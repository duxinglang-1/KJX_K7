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
 *  ImgViewCuiScrn.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is the main screen of image view CUI.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"

#if defined(__MMI_IMAGE_VIEWER__)
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "DebugInitDef_Int.h"
#include "Math.h"       /* sqrt */

#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_lcd_config.h"
#include "gdi_image_gif.h"
#include "gdi_include.h"

#if defined(__MMI_BT_SUPPORT__)
#include "BTMMIScrGprots.h"
#endif

#include "Med_smalloc.h"
#include "Med_api.h"
#include "ScreenRotationGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "Wgui_categories_util.h"
#include "gui_font_size.h"
#include "AlertScreen.h"
#include "gpiosrvgprot.h"       /* srv_backlight_turn_on */
#include "FileMgrType.h"
#include "FileMgrServiceResDef.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "Menucuigprot.h"
#include "FileMgrGProt.h"
#include "SensorSrvGport.h"     /* motion sensor */
#include "gui_themes.h" /* current_MMI_theme */
#include "AMGprot.h"    /* mmi_am_is_using_media_memory */

#include "ImgviewerConfig.h"
#include "ImgViewerCacheGProt.h"
#include "mmi_rp_app_imageviewer_def.h"
#include "Mmi_rp_cui_imageviewer_def.h"
#include "ImageViewCuiGprot.h"
#include "ImgviewCui.h"
#include "ImgViewerGprot.h"
#include "MediaAppPanel.h"
#include "PixcomFontEngine.h"
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
#include "ScrLockerGprot.h"
#endif

#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata = "DYNAMIC_CODE_CAMIMGV_RODATA",code = "DYNAMIC_CODE_CAMIMGV_ROCODE"
#endif

#ifdef __MMI_RMGR__
extern void mmi_rmgr_option_enabler_more_rits(
                mmi_menu_id menu_id,
                const WCHAR *filepath,
                const srv_fmgr_fileinfo_struct *fileinfo);
#endif /* __MMI_RMGR__ */

#if defined (GDI_COLORENGINE_SUPPORT)
	extern void gdi_color_engine_open();
	extern void gdi_color_engine_enable();
	extern void gdi_color_engine_disable();
	extern void gdi_color_engine_close();
#endif


enum CUI_IV_ERR
{
    CUI_IV_ERR_NO_RIGHT = 100
};

/* update trigger source, can OR each other */
enum CUI_IV_UPDATE_TRIGGER
{
    CUI_IV_UPDATE_NEW_IMAGE = 0x1,      /* current display image changed, for DRM process */
    CUI_IV_UPDATE_IMAGE_STATE = 0x2,    /* current image state changed, fg, rotate, zoom, etc. */
    CUI_IV_UPDATE_OSD = 0x4,            /* OSD change */
    CUI_IV_UPDATE_PANEL = 0x8           /* panel change */
};

static void cui_iv_start_rotate(cui_iv_cntx *pcui, S32 is_cw);
static void cui_iv_update_screen(cui_iv_cntx *pcui, S32 update_content);
static void cui_iv_load_complete(void *usrdata, S32 result);
static void cui_iv_still_exit(cui_iv_cntx *pcui);
static void cui_iv_still_key_down(cui_iv_cntx *pcui, U16 key_code);
static void cui_iv_still_key_up(cui_iv_cntx *pcui, U16 key_code);
static MMI_BOOL cui_iv_init_img_scrn_info(
                    cui_iv_img_extinfo *pinfo,
                    const WCHAR *pfilename,
                    U8 img_orient);
static MMI_BOOL cui_iv_still_navigation_down(cui_iv_cntx *pcui, U16 key_code);
static mmi_ret cui_iv_scrn_key_proc(mmi_event_struct *evt);

#ifdef __MMI_IVF_IMGADP__
static void cui_iv_imgadp_draw(
                cui_iv_cntx *pcui,
                const WCHAR *pfile,
                cui_iv_img_extinfo *pinfo,
                gdi_handle h_layer,
                gdi_handle h_temp_layer,
                cui_iv_imgadp_callback callback,
                void *userData);
static void cui_iv_imgadp_stop(cui_iv_cntx *pcui, cui_iv_imgadp_img_struct *pImg);
static void cui_iv_imgadp_pause(cui_iv_cntx *pcui, cui_iv_imgadp_img_struct *pImg);
static void cui_iv_imgadp_resume(cui_iv_cntx *pcui, cui_iv_imgadp_img_struct *pImg);

#ifdef __MMI_IVF_ANIM_SUPPORT__
static U16 cui_iv_imgadp_anim_check(const WCHAR *pfile);

#define CUI_IV_IMGADP_ANIM_CHECK(pfile)                 cui_iv_imgadp_anim_check(pfile)
#else /* __MMI_IVF_ANIM_SUPPORT__ */
#define CUI_IV_IMGADP_ANIM_CHECK(pfile)                 0
#endif /* __MMI_IVF_ANIM_SUPPORT__ */
#endif /* __MMI_IVF_IMGADP__ */

#ifdef __MMI_IVF_CACHE__
static void cui_iv_imgadp_cache_init(cui_iv_cntx *pcui);

#define CUI_IV_CACHE_INIT(pcui)                 cui_iv_imgadp_cache_init(pcui)
#define CUI_IV_CACHE_DEINIT(pcui)               mmi_ivc_destory((pcui)->scrn_data.decHdl)
#define CUI_IV_CACHE_SET_CURR_IDX(pcui, idx)    mmi_ivc_set_curr_idx((pcui)->scrn_data.decHdl, idx)

#else /* __MMI_IVF_CACHE__ */
#define CUI_IV_CACHE_INIT(pcui)
#define CUI_IV_CACHE_DEINIT(pcui)
#define CUI_IV_CACHE_SET_CURR_IDX(pcui, idx)
#endif /* __MMI_IVF_CACHE__ */

#ifdef __MMI_IVF_SLIDE__
static void cui_iv_slide_stop(cui_iv_cntx *pcui);
static MMI_BOOL cui_iv_slide_play(cui_iv_cntx *pcui);
static void cui_iv_slide_key_down(cui_iv_cntx *pcui, U16 key_code);
MMI_BOOL cui_iv_slide_is_playing(cui_iv_cntx *pcui);
#define CUI_IV_PLAY(pcui) cui_iv_slide_play(pcui)

#define CUI_IV_PLAY_EXIT        cui_iv_slide_stop
#define CUI_IV_PLAY_KEY_DOWN    cui_iv_slide_key_down

#ifdef __MMI_IVF_TOUCH_SCREEN__
static void cui_iv_slide_pen_down(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData);

#define CUI_IV_PLAY_PEN_DOWN    cui_iv_slide_pen_down
#else /* __MMI_IVF_TOUCH_SCREEN__ */
#define CUI_IV_PLAY_PEN_DOWN    NULL
#endif /* __MMI_IVF_TOUCH_SCREEN__ */

#ifdef __MMI_IVF_MOTION__
static void cui_iv_slide_motion_hdlr(cui_iv_cntx *pcui, U32 rot);

#define CUI_IV_SLIDE_MOTION_HDLR            cui_iv_slide_motion_hdlr
#else /* __MMI_IVF_MOTION__ */
#define CUI_IV_SLIDE_MOTION_HDLR            NULL
#endif /* __MMI_IVF_MOTION__ */

#else /* __MMI_IVF_SLIDE__ */

#define CUI_IV_PLAY(pcui)
#define CUI_IV_PLAY_EXIT        NULL
#define CUI_IV_PLAY_KEY_DOWN    NULL
#define CUI_IV_PLAY_PEN_DOWN    NULL
#define CUI_IV_SLIDE_MOTION_HDLR            NULL

#endif /* __MMI_IVF_SLIDE__ */

#ifdef __MMI_IVF_OPTION__       /* options */

static void cui_iv_options_entry(cui_iv_cntx *pcui);

#define CUI_IV_OPTIONS_ENTRY(pcui)  cui_iv_options_entry(pcui)
#else /* __MMI_IVF_OPTION__ */

#define CUI_IV_OPTIONS_ENTRY(pcui)  cui_iv_rotate_view(pcui)

#endif /* __MMI_IVF_OPTION__ */

#ifdef __MMI_IVF_TOUCH_SCREEN__
static void cui_iv_init_pen_handler(cui_iv_cntx *pcui);
static void cui_iv_still_pen_down(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData);
static void cui_iv_still_pen_up(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData);
static void cui_iv_still_pen_move(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData);
static void cui_iv_still_pen_abort(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData);
static void cui_iv_pen_wait_double(void *pdata);

#define CUI_IV_INIT_PEN_HANDLER  cui_iv_init_pen_handler
#define CUI_IV_STILL_PEN_DOWN    cui_iv_still_pen_down
#define CUI_IV_STILL_PEN_UP      cui_iv_still_pen_up
#define CUI_IV_STILL_PEN_MOVE    cui_iv_still_pen_move
#define CUI_IV_STILL_PEN_ABORT   cui_iv_still_pen_abort
#define CUI_IV_STILL_PEN_STOP_WAITE_DOUBLE()    gui_cancel_timer((FuncPtr)cui_iv_pen_wait_double)
#else /* __MMI_IVF_TOUCH_SCREEN__ */
#define CUI_IV_INIT_PEN_HANDLER(pcui)
#define CUI_IV_STILL_PEN_DOWN    NULL
#define CUI_IV_STILL_PEN_UP      NULL
#define CUI_IV_STILL_PEN_MOVE    NULL
#define CUI_IV_STILL_PEN_ABORT   NULL
#define CUI_IV_STILL_PEN_STOP_WAITE_DOUBLE()
#endif /* __MMI_IVF_TOUCH_SCREEN__ */

#ifdef __MMI_IVF_OSD__
static void cui_iv_init_osd(cui_iv_scrndata *pscrn_data);
static void cui_iv_deinit_osd(cui_iv_scrndata *pscrn_data);
static void cui_iv_get_osd_layers(const cui_iv_scrndata *pscrn_data, gdi_handle *ph_panel, gdi_handle *ph_title);
static void cui_iv_osd_show(cui_iv_scrndata *pscrn_data, S32 is_show);
static void cui_iv_update_title(cui_iv_cntx *pcui);
static void cui_iv_osd_key_down(cui_iv_scrndata *pscrn_data, U16 key_code);
static void cui_iv_osd_key_up(cui_iv_scrndata *pscrn_data, U16 key_code);
static void cui_iv_osd_reset_frame(cui_iv_scrndata *pscrn_data);
static void cui_iv_osd_set_hide(cui_iv_scrndata *pscrn_data);

#define CUI_IV_INIT_OSD(pscrn_data)                 cui_iv_init_osd(pscrn_data)
#define CUI_IV_DEINIT_OSD(pscrn_data)               cui_iv_deinit_osd(pscrn_data)
#define CUI_IV_GET_OSD_LAYERS(pscrn_data, ph_panel, ph_title) cui_iv_get_osd_layers(pscrn_data, ph_panel, ph_title)
#define CUI_IV_SHOW_OSD(pscrn_data, is_show)        cui_iv_osd_show(pscrn_data, is_show)
#define CUI_IV_OSD_START_WATCHDOG(pscrn_data)       mmi_mapp_frame_start_watchdog((pscrn_data)->pframe)
#define CUI_IV_OSD_STOP_WATCHDOG(pscrn_data)        mmi_mapp_frame_stop_watchdog((pscrn_data)->pframe)
#define CUI_IV_UPDATE_TITLE(pcui)                   cui_iv_update_title(pcui)
#define CUI_IV_OSD_KEY_DOWN(pscrn_data, key_code)   cui_iv_osd_key_down(pscrn_data, key_code)
#define CUI_IV_OSD_KEY_UP(pscrn_data, key_code)     cui_iv_osd_key_up(pscrn_data, key_code)
#define CUI_IV_OSD_RESET_FRAME(pscrn_data)          cui_iv_osd_reset_frame(pscrn_data)
#define IV_IS_OSD_HIDE(pscrn_data)                  (mmi_mapp_frame_state((pscrn_data)->pframe) == MAPP_FRAME_STAT_HIDE)
#define IV_IS_OSD_HIDING(pscrn_data)                (mmi_mapp_frame_state((pscrn_data)->pframe) == MAPP_FRAME_STAT_HIDING)
#define IV_IS_OSD_SHOW(pscrn_data)                  (mmi_mapp_frame_state((pscrn_data)->pframe) == MAPP_FRAME_STAT_SHOW)
#define IV_IS_OSD_SHOWING(pscrn_data)               (mmi_mapp_frame_state((pscrn_data)->pframe) == MAPP_FRAME_STAT_SHOWING)
#define CUI_IV_OSD_SET_HIDE(pscrn_data)             cui_iv_osd_set_hide(pscrn_data)

#else /* __MMI_IVF_OSD__ */
#define CUI_IV_INIT_OSD(pscrn_data)
#define CUI_IV_DEINIT_OSD(pscrn_data)
#define CUI_IV_GET_OSD_LAYERS(pscrn_data, ph_panel, ph_title)
#define CUI_IV_SHOW_OSD(pscrn_data, is_show)
#define CUI_IV_OSD_START_WATCHDOG(pscrn_data)
#define CUI_IV_OSD_STOP_WATCHDOG(pscrn_data)
#define CUI_IV_OSD_SET_HIDE(pscrn_data)
#define CUI_IV_UPDATE_TITLE(pcui)
#define CUI_IV_OSD_KEY_DOWN(pscrn_data, key_code)
#define CUI_IV_OSD_KEY_UP(pscrn_data, key_code)
#define CUI_IV_OSD_RESET_FRAME(pscrn_data)
#define IV_IS_OSD_HIDE(pscrn_data)        0
#define IV_IS_OSD_HIDING(pscrn_data)      0
#define IV_IS_OSD_SHOW(pscrn_data)        1
#define IV_IS_OSD_SHOWING(pscrn_data)     0

#endif /* __MMI_IVF_OSD__ */

#ifdef __MMI_IVF_SWITCH_EFFECT__
static void cui_iv_se_get_blt_layers(const cui_iv_scrndata *pscrnData, GDI_HANDLE *disLyr, GDI_HANDLE *switchLyr);
static void cui_iv_se_init_data(
                cui_iv_cntx *pcui,
                U32 imgIdx,
                S32 isNext,
                S32 effectIdx,
                GDI_HANDLE displayLyr,
                GDI_HANDLE switchLyr);
static void cui_iv_se_start(cui_iv_cntx *pcui, cui_iv_se_complete_cb complete, void *userData);
static MMI_BOOL cui_iv_se_stop(cui_iv_cntx *pcui);
static void cui_iv_switch_exit(cui_iv_cntx *pcui);
static void cui_iv_switch_key_down(cui_iv_cntx *pcui, U16 key_code);

#define CUI_IV_SE_INIT_DATA(pcui, imgIdx, isNext, effectIdx, displayLyr, switchLyr) \
    cui_iv_se_init_data(pcui, imgIdx, isNext, effectIdx, displayLyr, switchLyr)
#define CUI_IV_SE_INIT_DATA_EASE(pcui, imgIdx, isNext, displayLyr, switchLyr)   \
    cui_iv_se_init_data(pcui, imgIdx, isNext, 0, displayLyr, switchLyr)
#define CUI_IV_SE_START(pcui, index, complete, userData)    cui_iv_se_start(pcui, complete, userData)
#define CUI_IV_SE_STOP(pcui)                                cui_iv_se_stop(pcui)
#define CUI_IV_SWITCH_EXIT                                  cui_iv_switch_exit
#define CUI_IV_SWITCH_KEY_DOWN                              cui_iv_switch_key_down
#define CUI_IV_SWITCH_KEY_UP                                NULL
#define CUI_IV_GET_ERR_DST_LYR(disLyr, cacheLyr)            (disLyr)
#define CUI_IV_GET_BLT_LAYERS(pscrnData, disLyr, switchLyr) cui_iv_se_get_blt_layers(pscrnData, disLyr, switchLyr)

#ifdef __MMI_IVF_DRAG_SWITCH__
static S32 cui_iv_switch_get_switch_direction(cui_iv_cntx *pcui, S32 offset);
static void cui_iv_switch_pen_move(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData);
static void cui_iv_switch_pen_down(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData);
static void cui_iv_switch_pen_up(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData);

#define CUI_IV_SWITCH_GET_SWITCH_DIRECTION(pcui, offset)    cui_iv_switch_get_switch_direction(pcui, offset)
#define CUI_IV_SWITCH_PEN_DOWN                              cui_iv_switch_pen_down
#define CUI_IV_SWITCH_PEN_UP                                cui_iv_switch_pen_up
#define CUI_IV_SWITCH_PEN_MOVE                              cui_iv_switch_pen_move
#define CUI_IV_SWITCH_PEN_ABORT                             cui_iv_switch_pen_up
#else /* __MMI_IVF_DRAG_SWITCH__ */
#define CUI_IV_SWITCH_GET_SWITCH_DIRECTION(pcui, offset)    0
#define CUI_IV_SWITCH_PEN_DOWN                              NULL
#define CUI_IV_SWITCH_PEN_UP                                NULL
#define CUI_IV_SWITCH_PEN_MOVE                              NULL
#define CUI_IV_SWITCH_PEN_ABORT                             NULL
#endif /* __MMI_IVF_DRAG_SWITCH__ */

#ifdef __MMI_IVF_MOTION__
static void cui_iv_switch_motion_hdlr(cui_iv_cntx *pcui, U32 rot);

#define CUI_IV_SWITCH_MOTION_HDLR           cui_iv_switch_motion_hdlr
#else /* __MMI_IVF_MOTION__ */
#define CUI_IV_SWITCH_MOTION_HDLR           NULL
#endif /* __MMI_IVF_MOTION__ */

static void cui_iv_pause_img_ops(cui_iv_cntx *pcui);
static void cui_iv_resume_img_ops(cui_iv_cntx *pcui);

#define CUI_IV_PAUSE_IMG_OPS(pcui)          cui_iv_pause_img_ops(pcui)
#define CUI_IV_RESUME_IMG_OPS(pcui)         cui_iv_resume_img_ops(pcui)

#else /* __MMI_IVF_SWITCH_EFFECT__ */

#define CUI_IV_SE_INIT_DATA(pcui, imgIdx, isNext, effectIdx, displayLyr, switchLyr)
#define CUI_IV_SE_INIT_DATA_EASE(pcui, imgIdx, isNext, displayLyr, switchLy)
#define CUI_IV_SE_START(pcui, index, complete, userData)    complete(userData, index, (pcui->disp_cap))
#define CUI_IV_SE_STOP(pcui)                                MMI_FALSE
#define CUI_IV_SWITCH_GET_SWITCH_DIRECTION(pcui, offset)    0
#define CUI_IV_SWITCH_EXIT                                  NULL
#define CUI_IV_SWITCH_KEY_DOWN                              NULL
#define CUI_IV_SWITCH_KEY_UP                                NULL
#define CUI_IV_SWITCH_PEN_DOWN                              NULL
#define CUI_IV_SWITCH_PEN_UP                                NULL
#define CUI_IV_SWITCH_PEN_MOVE                              NULL
#define CUI_IV_SWITCH_PEN_ABORT                             NULL
#define CUI_IV_GET_ERR_DST_LYR(disLyr, cacheLyr)            (cacheLyr)
#define CUI_IV_GET_BLT_LAYERS(pcui, disLyr, switchLyr)
#define CUI_IV_SWITCH_MOTION_HDLR                           NULL
#define CUI_IV_PAUSE_IMG_OPS(pcui)
#define CUI_IV_RESUME_IMG_OPS(pcui)
#endif /* __MMI_IVF_SWITCH_EFFECT__ */

#ifdef __MMI_IVF_ZOOM__
static void cui_iv_zoom_dec_img(
                cui_iv_cntx *pcui,
                const WCHAR *pfile,
                cui_iv_img_extinfo *pinfo,
                gdi_handle h_layer,
                gdi_handle h_temp_layer,
                cui_iv_imgadp_callback callback,
                void *userData);
static void cui_iv_zoom_init(cui_iv_cntx *pcui);
static void cui_iv_zoom_deinit(cui_iv_cntx *pcui);
static void cui_iv_start_zoom(cui_iv_cntx *pcui, S32 is_zoomin);
static void cui_iv_stop_zoom(cui_iv_cntx *pcui);
static void cui_iv_cancel_zoom(cui_iv_cntx *pcui);
static void cui_iv_zoom_init_img_extinfo(cui_iv_cntx *pcui);
static void cui_iv_pan(cui_iv_cntx *pcui, S32 off_x, S32 off_y);
static void cui_iv_start_pan(cui_iv_cntx *pcui, U16 key_code);
static MMI_BOOL cui_iv_zoom_navigation_down(cui_iv_cntx *pcui, U16 key_code);
static void cui_iv_zoom_fast(cui_iv_cntx *pcui);
static void cui_iv_zoom_init_base_info(cui_iv_img_baseinfo *pinfo);

#define CUI_IV_DEC_IMG(pcui, pfile, pinfo, h_layer, h_temp_layer, callback, userdata) \
                cui_iv_zoom_dec_img(pcui, pfile, pinfo, h_layer, h_temp_layer, callback, userdata)
#define CUI_IV_ZOOM_INIT(pcui)                  cui_iv_zoom_init(pcui)
#define CUI_IV_ZOOM_DEINIT(pcui)                cui_iv_zoom_deinit(pcui)
#define CUI_IV_ZOOM_INIT_BASE_INFO(pinfo)       cui_iv_zoom_init_base_info(pinfo)
#define CUI_IV_ZOOM_INIT_IMG_EXTINFO(pcui)      cui_iv_zoom_init_img_extinfo(pcui)
#define CUI_IV_START_ZOOM(pcui, is_zoomin)      cui_iv_start_zoom(pcui, is_zoomin)
#define CUI_IV_STOP_ZOOM(pcui)                  cui_iv_stop_zoom(pcui)
#define CUI_IV_CANCEL_ZOOM(pcui)                cui_iv_cancel_zoom(pcui)
#define CUI_IV_PAN(pcui, off_x, off_y)          cui_iv_pan(pcui, off_x, off_y)
#define CUI_IV_NAVIGATION_DOWN(pcui, key_code)  cui_iv_zoom_navigation_down(pcui, key_code)
#define CUI_IV_ZOOM_FAST(pcui)                  cui_iv_zoom_fast(pcui)

#ifdef __MMI_IVF_TOUCH_SCREEN__
static void cui_iv_zoom_get_switch_flag(cui_iv_cntx *pcui);

#define CUI_IV_ZOOM_GET_SWITCH_FLAG(pcui)  cui_iv_zoom_get_switch_flag(pcui)
#else /* __MMI_IVF_TOUCH_SCREEN__ */
#define CUI_IV_ZOOM_GET_SWITCH_FLAG(pcui)
#endif /* __MMI_IVF_TOUCH_SCREEN__ */

#else /* __MMI_IVF_ZOOM__ */

#define CUI_IV_DEC_IMG(pcui, pfile, pinfo, h_layer, h_temp_layer, callback, userdata) \
                cui_iv_imgadp_draw(pcui, pfile, pinfo, h_layer, h_temp_layer, callback, userdata)
#define CUI_IV_ZOOM_INIT(pcui)
#define CUI_IV_ZOOM_DEINIT(pcui)
#define CUI_IV_ZOOM_INIT_BASE_INFO(pinfo)
#define CUI_IV_ZOOM_INIT_IMG_EXTINFO(pcui)
#define CUI_IV_START_ZOOM(pcui, is_zoomin)
#define CUI_IV_STOP_ZOOM(pcui)
#define CUI_IV_CANCEL_ZOOM(pcui)
#define CUI_IV_PAN(pcui, off_x, off_y)
#define CUI_IV_NAVIGATION_DOWN(pcui, key_code) cui_iv_still_navigation_down(pcui, key_code)
#define CUI_IV_ZOOM_FAST(pcui)
#define CUI_IV_ZOOM_GET_SWITCH_FLAG(pcui)

#endif /* __MMI_IVF_ZOOM__ */

#ifdef __MMI_IVF_MOTION__
static void cui_iv_motion_start_listen(cui_iv_cntx *pcui);
static void cui_iv_motion_stop_listen(cui_iv_cntx *pcui);
static void cui_iv_still_motion_hdlr(cui_iv_cntx *pcui, U32 rot);

#define CUI_IV_MOTION_START_LISTEN(pcui)    cui_iv_motion_start_listen(pcui)
#define CUI_IV_MOTION_STOP_LISTEN(pcui)     cui_iv_motion_stop_listen(pcui)
#define CUI_IV_STILL_MOTION_HDLR            cui_iv_still_motion_hdlr
#else /* __MMI_IVF_MOTION__ */
#define CUI_IV_MOTION_START_LISTEN(pcui)
#define CUI_IV_MOTION_STOP_LISTEN(pcui)
#define CUI_IV_STILL_MOTION_HDLR            NULL
#endif /* __MMI_IVF_MOTION__ */

#ifdef __DRM_SUPPORT__

#include "Drm_gprot.h"

typedef struct
{
    const WCHAR *filepath;
    kal_int32 drm_id;
    S32 stat;
    S32 index;
} cui_iv_drm_cntx_t;

static void cui_iv_drm_show_image(cui_iv_cntx *pcui, S32 result);
static void cui_iv_drm_pause_show(cui_iv_cntx *pcui, U32 index);
static void cui_iv_drm_exit_show(cui_iv_cntx *pcui);
static void cui_iv_drm_init(cui_iv_cntx *pcui);
static S32 cui_iv_drm_check_right(const WCHAR *filepath, U8 check_rights);

/* for slide show will not save the error state, so we need result to distinguish */
#define CUI_IV_DRM_INIT(pcui)                   cui_iv_drm_init(pcui)
#define CUI_IV_SHOW_IMAGE(pcui, result)         cui_iv_drm_show_image(pcui, result)
#define CUI_IV_PAUSE_SHOW(pcui, index)          cui_iv_drm_pause_show(pcui, index)
#define CUI_IV_EXIT_SHOW(pcui)                  cui_iv_drm_exit_show(pcui)
#define CUI_IV_DRM_CHECK_RIGHT(filepath)        cui_iv_drm_check_right((WCHAR*)filepath, DRM_PERMISSION_DISPLAY)
#define CUI_IV_DRM_SET_ERR(pinfo)               pinfo->err_code = CUI_IV_ERR_NO_RIGHT

#else /* __DRM_SUPPORT__ */

#define CUI_IV_DRM_INIT(pcui)
#define CUI_IV_SHOW_IMAGE(pcui, result)
#define CUI_IV_PAUSE_SHOW(pcui, index)
#define CUI_IV_EXIT_SHOW(pcui)
#define CUI_IV_DRM_CHECK_RIGHT(filepath)        MMI_TRUE
#define CUI_IV_DRM_SET_ERR(pinfo)

#endif /* __DRM_SUPPORT__ */

static const struct
{
    void (*exit_hdlr) (cui_iv_cntx *pcui);
    void (*key_down_hdlr) (cui_iv_cntx *pcui, U16 key_code);
    void (*key_up_hdlr) (cui_iv_cntx *pcui, U16 key_code);
    void (*pen_down_hdlr) (cui_iv_cntx *pcui, mmi_touch_data_struct *touchData);
    void (*pen_up_hdlr) (cui_iv_cntx *pcui, mmi_touch_data_struct *touchData);
    void (*pen_move_hdlr) (cui_iv_cntx *pcui, mmi_touch_data_struct *touchData);
    void (*pen_abort_hdlr) (cui_iv_cntx *pcui, mmi_touch_data_struct *touchData);
    void (*motion_hdlr) (cui_iv_cntx *pcui, U32 rot);
} cui_iv_scrn_input[] =
{
    {
        cui_iv_still_exit,  /* IV_SCRN_STAT_ACTIVE */
        cui_iv_still_key_down,
        cui_iv_still_key_up,
        CUI_IV_STILL_PEN_DOWN,
        CUI_IV_STILL_PEN_UP,
        CUI_IV_STILL_PEN_MOVE,
        CUI_IV_STILL_PEN_ABORT,
        CUI_IV_STILL_MOTION_HDLR,},
    {
        CUI_IV_PLAY_EXIT,   /* IV_SCRN_STAT_PLAY,      */
        CUI_IV_PLAY_KEY_DOWN,
        NULL,
        CUI_IV_PLAY_PEN_DOWN,
        NULL,
        NULL,
        NULL,
        CUI_IV_SLIDE_MOTION_HDLR,},
    {
        CUI_IV_SWITCH_EXIT, /* IV_SCRN_STAT_SWITCHING, */
        CUI_IV_SWITCH_KEY_DOWN,
        CUI_IV_SWITCH_KEY_UP,
        CUI_IV_SWITCH_PEN_DOWN,
        CUI_IV_SWITCH_PEN_UP,
        CUI_IV_SWITCH_PEN_MOVE,
        CUI_IV_SWITCH_PEN_ABORT,
        CUI_IV_SWITCH_MOTION_HDLR,}
};

#ifdef __MMI_IV_PLUTO_SLIM__
#define CUI_IV_LOADING_TIME  100
static U16 loading_value = 0;
GDI_HANDLE loading_dstLyr = NULL;
#endif

#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
/*****************************************************************************
 * FUNCTION
 *  cui_iv_screen_locker_event_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *
 *****************************************************************************/
static mmi_ret cui_iv_screen_locker_event_handler (mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING) {
        cui_iv_cntx *pcui = (cui_iv_cntx*) evt->user_data;
        mmi_scr_locker_pre_lock_evt_struct *lock_event = (mmi_scr_locker_pre_lock_evt_struct *) evt;

        MMI_ASSERT(pcui != NULL);
        
        if (lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_POWER_KEY)
        {
            return MMI_RET_OK;
        }
        else if (lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_AUTO_LOCK)
        {
#ifdef __MMI_IVF_SLIDE__
            if (MMI_TRUE == cui_iv_slide_is_playing(pcui))
                return MMI_RET_ERR;
            else
#endif
                return MMI_RET_OK;
        }
        else
        {
            return MMI_RET_OK;
        }
    }
    else {
        return MMI_RET_ERR;
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cui_iv_input_available
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *
 *****************************************************************************/
static MMI_BOOL cui_iv_input_available(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pcui->scrn_stat == IV_SCRN_STAT_INACTIVE)
        return MMI_FALSE;

    return MMI_TRUE;
}

#if (!(defined (__MMI_IV_PLUTO_SLIM__)) || defined (__DRM_SUPPORT__))

/*****************************************************************************
 * FUNCTION
 *  cui_iv_draw_err_icon
 * DESCRIPTION
 *
 * PARAMETERS
 *  dstLyr      [IN]
 *  ImageId     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_draw_err_icon(GDI_HANDLE dstLyr, U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h, x, y, layer_w, layer_h;
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gdi_image_get_dimension_id(ImageId, &w, &h);
    MMI_ASSERT(ret == GDI_SUCCEED);
    if (ret != GDI_SUCCEED)
        return;

    gdi_layer_get_dimension_nb_concurrent(dstLyr, &layer_w, &layer_h);

    x = (layer_w - w) >> 1;
    y = (layer_h - h) >> 1;

    gdi_layer_clear_nb_concurrent(dstLyr, GDI_COLOR_BLACK);

    gdi_layer_push_and_set_active(dstLyr);
    gdi_image_draw_id(x, y, ImageId);
    gdi_layer_pop_and_restore_active();
}
#endif

#ifdef __MMI_IV_PLUTO_SLIM__

/*****************************************************************************
 * FUNCTION
 *  cui_iv_draw_err_string
 * DESCRIPTION
 *
 * PARAMETERS
 * 	void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_draw_err_string(GDI_HANDLE dstLyr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h, x1, y1,x2,y2,layer_w, layer_h;
	color text_color;
    color text_border_color;
	UI_string_type str = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	StopTimer(IV_LOADING_TIMER);
	text_color = gui_color(255,255,255);
	text_border_color = gui_color(0,0,0);
	str = (UI_string_type) GetString(STR_GLOBAL_INVALID_FORMAT);
	#ifdef __MMI_VECTOR_FONT_SUPPORT__
		mmi_fe_set_antialias(MMI_FALSE);
	#endif
    gui_set_font((UI_font_type) gui_font_get_type(GUI_FONT_SIZE_TITLE));
    gdi_layer_get_dimension_nb_concurrent(dstLyr, &layer_w, &layer_h);
    gui_measure_string(str, &w, &h);
    x1 = (layer_w - w) >> 1;
    y1 = (layer_h - h) >> 1;
    x2 = x1 + w;
	y2 = y1 + h;
	
    gdi_layer_clear_nb_concurrent(dstLyr, GDI_COLOR_BLACK);
    gdi_layer_push_and_set_active(dstLyr);
	gdi_layer_lock_frame_buffer();
	gdi_layer_push_and_set_clip(x1, y1, x2, y2);
	gui_set_text_color(text_color);
	gui_set_text_border_color(text_border_color);
    /*gui_move_text_cursor(
                x1 + (120 - w) / 2,
                y1 + (20 - h) / 2);*/
	if (mmi_fe_get_r2l_state())
	{
		gui_move_text_cursor(x1 + w, y1);
	}
    else
    {
    	gui_move_text_cursor(
                x1, 
                y1);
    }
    gui_print_bordered_text(str);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
	gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);
    
}

/*****************************************************************************
 * FUNCTION
 *  cui_iv_draw_load_string
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_draw_load_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h, x1, y1,x2,y2,layer_w, layer_h;
	color text_color;
    color text_border_color;
	U16 str[20];
	UI_string_type str_add = L".";
	S32 iterator = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	text_color = gui_color(255,255,255);
	text_border_color = gui_color(0,0,0);
	mmi_ucs2cpy((CHAR *)str,(CHAR *)GetString(STR_GLOBAL_LOADING));
	#ifdef __MMI_VECTOR_FONT_SUPPORT__
		mmi_fe_set_antialias(MMI_FALSE);
	#endif
    gui_set_font((UI_font_type) gui_font_get_type(GUI_FONT_SIZE_TITLE));
    gdi_layer_get_dimension_nb_concurrent(loading_dstLyr, &layer_w, &layer_h);
    gui_measure_string(str, &w, &h);
    x1 = (layer_w - w) >> 1;
    y1 = (layer_h - h) >> 1;
    
	while(iterator < loading_value)
	{
		mmi_ucs2cat((CHAR *)str,(CHAR *) str_add);
		iterator++;
	}
	if(loading_value < 3)
	{
		loading_value++;
	}
	else
	{
		loading_value = 0;
	}

	gui_measure_string(str, &w, &h);
	x2 = x1 + w ;
	y2 = y1 + h ;
    gdi_layer_clear_nb_concurrent(loading_dstLyr, GDI_COLOR_BLACK);
    gdi_layer_push_and_set_active(loading_dstLyr);
	gdi_layer_lock_frame_buffer();
	gdi_layer_push_and_set_clip(x1, y1, x2, y2);
	gui_set_text_color(text_color);
	gui_set_text_border_color(text_border_color);
	if (mmi_fe_get_r2l_state())
	{
		gui_move_text_cursor(x1 + w, y1);
	}
    else
    {
    	gui_move_text_cursor(
                x1 ,
                y1 );
    }
    gui_print_bordered_text(str);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
	gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);
    StartTimer(IV_LOADING_TIMER, CUI_IV_LOADING_TIME, cui_iv_draw_load_string);
}
#endif /* __MMI_IV_PLUTO_SLIM__ */

/*****************************************************************************
 * FUNCTION
 *  cui_iv_set_img_rot
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  rot_value       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_set_img_rot(cui_iv_cntx *pcui, U8 rot_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pcui->img_base_info.img_orient = rot_value;

    if (rot_value == GDI_LAYER_ROTATE_90 || rot_value == GDI_LAYER_ROTATE_270)
    {
        w = LCD_HEIGHT;
        h = LCD_WIDTH;
    }
    else
    {
        w = LCD_WIDTH;
        h = LCD_HEIGHT;
    }

    gdi_layer_resize_nb_concurrent(pscrn_data->h_cache_layer, w, h);
    gdi_layer_set_rotate_nb_concurrent(pscrn_data->h_cache_layer, rot_value);
    gdi_layer_resize_nb_concurrent(pscrn_data->h_disp_layer, w, h);
    gdi_layer_set_rotate_nb_concurrent(pscrn_data->h_disp_layer, rot_value);

    CUI_IV_ZOOM_INIT_BASE_INFO(&pcui->img_base_info);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_cancel_img_ops
 * DESCRIPTION
 *  Cancel all the uncompleted operations of current image.
 * PARAMETERS
 *  pcui        [?]     Context of CUI.
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_cancel_img_ops(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_CANCEL_IMG_OPS, pinfo->stat);

    if (pinfo->stat == IV_IMG_STAT_LOADING)
    {
        /* Stop current loading */
        cui_iv_cancel_load_file();
    }

    /* Stop large cache decoding */
    CUI_IV_CANCEL_ZOOM(pcui);

    cui_iv_imgadp_stop(pcui, pinfo->pImg);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_init_img_info
 * DESCRIPTION
 *  Init image info which only related to the image
 *  Which will be reserved after screen exit.
 * PARAMETERS
 *  pcui        [?]
 *  index       [IN]
 *  rot_val     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_init_img_info(cui_iv_cntx *pcui, U32 index, U8 rot_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_INIT_IMG_INFO, index, rot_val);
    /* init info */
    memset(pinfo, 0, sizeof(cui_iv_img_extinfo));
    memset(&pcui->img_base_info, 0, sizeof(cui_iv_img_baseinfo));
    pcui->index = index;

    cui_iv_set_img_rot(pcui, rot_val);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_update_img
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  index       [IN]
 *  rot_val     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_update_img(cui_iv_cntx *pcui, U32 index, U8 rot_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Cancel uncompleted operations of current image */
    cui_iv_cancel_img_ops(pcui);

    cui_iv_init_img_info(pcui, index, rot_val);

    /* init current base info */
    cui_iv_load_filename(pcui, index, (void*)pcui, cui_iv_load_complete);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_rotate_view
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_rotate_view(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pcui->disp_cap = pcui->disp_cap ^ CUI_IMGVIEW_DISP_ROT;

    /* Reset osd */
    CUI_IV_OSD_RESET_FRAME(&pcui->scrn_data);
    cui_iv_update_img(
        pcui,
        pcui->index,
        (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT) == CUI_IMGVIEW_DISP_ROT ? GDI_LAYER_ROTATE_90 : GDI_LAYER_ROTATE_0);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_switch_complete
 * DESCRIPTION
 *
 * PARAMETERS
 *  userData        [?]
 *  index           [IN]        Only used when switch effect supported.
 *  newDispCap      [IN]        Used to pass new view rotation to update screen, only used when switch effect supported.
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_switch_complete(void *userData, U32 index, U32 newDispCap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui = (cui_iv_cntx*) userData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SWITCH_COMPLETE, index, newDispCap);

#ifdef __MMI_IVF_SWITCH_EFFECT__
    if (pcui->index == index)
    {
        /* Rebound back */
        if (pcui->disp_cap == newDispCap)
        {
            /* View rotation has not been changed */
            CUI_IV_RESUME_IMG_OPS(pcui);
        }
        else
        {
            /* Rebound back but view rotation has been changed */
            cui_iv_rotate_view(pcui);
        }
    }
    else
#endif /* __MMI_IVF_SWITCH_EFFECT__ */
    {
        /* Update IVC index */
        CUI_IV_CACHE_SET_CURR_IDX(pcui, index);

        if (pcui->disp_cap == newDispCap)
        {
            /* Just change the image to the other one */
            cui_iv_update_img(
                pcui,
                index,
                (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT) == CUI_IMGVIEW_DISP_ROT ? GDI_LAYER_ROTATE_90 : GDI_LAYER_ROTATE_0);
        }
        else
        {
            /* Also rotate the view direction */
            pcui->index = index;
            cui_iv_rotate_view(pcui);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_start_switch
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  is_next     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_start_switch(cui_iv_cntx *pcui, S32 is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = pcui->index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_START_SWITCH, index, is_next);
    if (pcui->count <= 1)
    {
        return;
    }

    /* reset current image info */
    if (is_next)
    {
        index = (index == pcui->count - 1) ? 0 : (index + 1);
    }
    else
    {
        index = (index == 0) ? (pcui->count - 1) : (index - 1);
    }

    CUI_IV_PAUSE_IMG_OPS(pcui);
    CUI_IV_SE_INIT_DATA_EASE(pcui, index, is_next, pcui->scrn_data.h_disp_layer, pcui->scrn_data.h_cache_layer);
    CUI_IV_SE_START(pcui, index, cui_iv_switch_complete, (void*)pcui);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_start_rotate
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  is_cw       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_start_rotate(cui_iv_cntx *pcui, S32 is_cw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 img_rot = pcui->img_base_info.img_orient;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_ROTATE, is_cw);
    if (pcui->scrn_data.cur_img_info.stat != IV_IMG_STAT_OK)
        return;

    /* resize and rotate layers */
    if (is_cw)
    {
        img_rot++;
    }
    else
    {
        img_rot--;
    }

    cui_iv_update_img(pcui, pcui->index, img_rot & 0x3);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_still_navigation_down
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  key_code        [IN]
 * RETURNS
 *
 *****************************************************************************/
static MMI_BOOL cui_iv_still_navigation_down(cui_iv_cntx *pcui, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pcui->count > 1)
    {
        CUI_IV_SHOW_OSD(&pcui->scrn_data, 0);
        if (((pcui->disp_cap & CUI_IMGVIEW_DISP_ROT) && key_code > KEY_DOWN_ARROW)      /* left or right */
            || (!(pcui->disp_cap & CUI_IMGVIEW_DISP_ROT) && key_code < KEY_LEFT_ARROW))
        {   /* down or up */
            return MMI_FALSE;
        }

        cui_iv_start_switch(pcui, (KEY_RIGHT_ARROW == key_code || KEY_DOWN_ARROW == key_code));
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_rkey_cyclic
 * DESCRIPTION
 *
 * PARAMETERS
 *  pdata       [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_rkey_cyclic(void *pdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct key_evt;
    cui_iv_cntx *pcui = (cui_iv_cntx*) pdata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&key_evt, EVT_ID_ON_KEY);
    key_evt.key_code = (U8) pcui->scrn_data.repeat_key;
    key_evt.key_type = KEY_EVENT_DOWN;
    mmi_frm_post_event((mmi_event_struct*) (&key_evt), cui_iv_scrn_key_proc, pcui);

    gui_start_timer_ex(MMI_IV_RKEY_INTERVAL, cui_iv_rkey_cyclic, pcui);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_rkey_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  key_code        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_rkey_start(cui_iv_cntx *pcui, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pcui->scrn_data.repeat_key = key_code;
    gui_start_timer_ex(MMI_IV_RKEY_START_INTERVAL, cui_iv_rkey_cyclic, pcui);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_rkey_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_rkey_stop(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer((FuncPtr) cui_iv_rkey_cyclic);
    pcui->scrn_data.repeat_key = 0;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_still_key_down
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  key_code        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_still_key_down(cui_iv_cntx *pcui, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_STILL_KEY_DOWN, key_code, pcui->scrn_data.flag);

    if (pcui->scrn_data.flag & (IV_FLAG_ZOOMIN | IV_FLAG_ZOOMOUT))
    {
        CUI_IV_STOP_ZOOM(pcui);
        pcui->scrn_data.flag &= ~IV_FLAG_KEY_DOWN;
        return;
    }

    /* switch always work */
    if (key_code == KEY_LEFT_ARROW || key_code == KEY_RIGHT_ARROW ||
        key_code == KEY_UP_ARROW || key_code == KEY_DOWN_ARROW)
    {
        if (CUI_IV_NAVIGATION_DOWN(pcui, key_code) == MMI_TRUE)
        {
            if (pcui->scrn_data.repeat_key == 0)
            {
                cui_iv_rkey_start(pcui, key_code);
            }
        }
        else
        {
            cui_iv_rkey_stop(pcui);
        }
        return;
    }

    if (IV_IS_OSD_HIDE(&pcui->scrn_data) || IV_IS_OSD_HIDING(&pcui->scrn_data))
    {
        CUI_IV_SHOW_OSD(&pcui->scrn_data, 1);
        pcui->scrn_data.flag &= ~IV_FLAG_KEY_DOWN;  /* ignore the key up */
        return;
    }

    CUI_IV_OSD_STOP_WATCHDOG(&pcui->scrn_data);
    CUI_IV_OSD_KEY_DOWN(&pcui->scrn_data, key_code);

    switch (key_code)
    {
        case CUI_IV_KEY_ZOOMOUT:
        case CUI_IV_KEY_ZOOMIN:
            CUI_IV_START_ZOOM(pcui, key_code == CUI_IV_KEY_ZOOMIN);
            break;

        case CUI_IV_KEY_FZOOM:
            CUI_IV_ZOOM_FAST(pcui);
            break;

        default:
            break;
    };
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_still_key_up
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  key_code        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_still_key_up(cui_iv_cntx *pcui, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_STILL_KEY_UP, key_code, pcui->scrn_data.flag);

    CUI_IV_OSD_START_WATCHDOG(&pcui->scrn_data);
    CUI_IV_OSD_KEY_UP(&pcui->scrn_data, key_code);

    switch (key_code)
    {
        case KEY_LSK:
            if (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT)
            {
                break;
            }
            else if (pcui->disp_cap & CUI_IMGVIEW_DISP_LSK_DEF)
            {
                CUI_IV_OPTIONS_ENTRY(pcui);
            }
            else
            {
                /* Send OK event */

                mmi_group_event_struct evt;

                /* single instance will use global context */
                evt.evt_id = EVT_ID_IMGVIEW_ON_OK;
                evt.sender_id = pcui->cui_gid;
                evt.size = sizeof(mmi_group_event_struct);
                mmi_frm_group_send_to_parent(pcui->cui_gid, &evt);
            }
            break;

        case KEY_RSK:
            if (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT)
            {
                cui_iv_rotate_view(pcui);
            }
            else
            {
                cui_iv_close(pcui);
            }
            return;

        case CUI_IV_KEY_ZOOMOUT:
        case CUI_IV_KEY_ZOOMIN:
            CUI_IV_STOP_ZOOM(pcui);
            break;

        case KEY_CSK:
            CUI_IV_PLAY(pcui);
            break;

        case CUI_IV_KEY_CCWR:
        case CUI_IV_KEY_CWR:
            cui_iv_start_rotate(pcui, key_code == CUI_IV_KEY_CWR);
            break;

        default:
            break;
    };

}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_scrn_key_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt     [?]
 * RETURNS
 *
 *****************************************************************************/
static mmi_ret cui_iv_scrn_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct*) evt;
    cui_iv_cntx *pcui = (cui_iv_cntx*) key_evt->user_data;
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ON_KEY)
    {
        /* ignore sys keys */
        if (key_evt->key_code == KEY_END || key_evt->key_code == KEY_POWER)
            return MMI_RET_OK;

        if (cui_iv_input_available(pcui) == MMI_FALSE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_INPUT_NOT_AVAIL);
            return MMI_RET_OK;
        }

        /* key process */
        if (key_evt->key_type == KEY_EVENT_DOWN)
        {
            pscrn_data->flag |= IV_FLAG_KEY_DOWN;

            if (cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].key_down_hdlr)
            {
                cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].key_down_hdlr(pcui, (U16) (key_evt->key_code));
            }
        }
        else if (key_evt->key_type == KEY_EVENT_UP)
        {
            cui_iv_rkey_stop(pcui);
            if (IV_IS_KEY_DOWN(pscrn_data->flag))
            {
                pscrn_data->flag &= ~IV_FLAG_KEY_DOWN;
                if (cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].key_up_hdlr)
                {
                    cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].key_up_hdlr(
                                                                                pcui,
                                                                                (U16) (key_evt->key_code));
                }
            }
        }

        return MMI_RET_KEY_HANDLED;

    }
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_scn_on_active
 * DESCRIPTION
 *  Init screen enviroment.
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_scn_on_active(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* force all playing keypad tone off */
    /* entry full screen app */
    entry_full_screen();
    /* clear key events for key release event from last screen */
    ClearKeyEvents();
    gdi_layer_reset_clip();
    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    CUI_IV_MOTION_START_LISTEN(pcui);

    /* init pen handler */
    CUI_IV_INIT_PEN_HANDLER(pcui);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_is_src_valid
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *
 *****************************************************************************/
static MMI_BOOL cui_iv_is_src_valid(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pcui->src_mode)
    {
        case IMGVIEW_SRC_FILE:
        case IMGVIEW_SRC_GET_FILE:
        {
            FS_HANDLE hd;

            hd = FS_Open((WCHAR*) pcui->file_name, FS_READ_ONLY);
            if (hd >= 0)
            {
                FS_Close(hd);
                return MMI_TRUE;
            }
        }
            break;

        case IMGVIEW_SRC_FILELIST:
        {
            if (srv_fmgr_filelist_is_dirty(pcui->h_list) &&
                srv_fmgr_filelist_get_state(pcui->h_list) != SRV_FMGR_FILELIST_STATE_LOADING)
                break;
            if (srv_fmgr_filelist_count(pcui->h_list) <= 0)
                break;
        }
            return MMI_TRUE;

        default:
            break;

    };

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_init_layer
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_init_layer(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;
    S32 w = LCD_WIDTH;
    S32 h = LCD_HEIGHT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pcui->img_base_info.img_orient == GDI_LAYER_ROTATE_90 || pcui->img_base_info.img_orient == GDI_LAYER_ROTATE_270)
    {
        w = LCD_HEIGHT;
        h = LCD_WIDTH;
    }

    gdi_layer_get_base_handle(&pscrn_data->h_disp_layer);
    gdi_layer_resize_nb_concurrent(pscrn_data->h_disp_layer, w, h);
    gdi_layer_set_rotate_nb_concurrent(pscrn_data->h_disp_layer, pcui->img_base_info.img_orient);
    gdi_layer_clear_nb_concurrent(pscrn_data->h_disp_layer, GDI_COLOR_BLACK);
    gdi_layer_set_background_nb_concurrent(pscrn_data->h_disp_layer, GDI_COLOR_BLACK);
    gdi_layer_set_source_key_nb_concurrent(pscrn_data->h_disp_layer, (BOOL) MMI_FALSE, GDI_COLOR_TRANSPARENT);

    gdi_layer_create(0, 0, w, h, &pscrn_data->h_cache_layer);
    gdi_layer_set_rotate_nb_concurrent(pscrn_data->h_cache_layer, pcui->img_base_info.img_orient);
    gdi_layer_clear_nb_concurrent(pscrn_data->h_cache_layer, GDI_COLOR_BLACK);
    gdi_layer_set_background_nb_concurrent(pscrn_data->h_cache_layer, GDI_COLOR_BLACK);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_deinit_layer
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_deinit_layer(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_free(pscrn_data->h_cache_layer);
    gdi_layer_set_source_key_nb_concurrent(pscrn_data->h_disp_layer, (BOOL) MMI_TRUE, GDI_COLOR_TRANSPARENT);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_init_memory
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL cui_iv_init_memory(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IV_TOTAL_MED_MEMORY_SIZE != 0)
    {
        pscrn_data->medMemPtr = mmi_frm_asm_alloc_nc_r(pcui->cui_gid, IV_TOTAL_MED_MEMORY_SIZE);
        if (pscrn_data->medMemPtr == NULL)
            return MMI_FALSE;
    }

    if (IV_TOTAL_SCREEN_MEMORY_SIZE != 0)
    {
        pscrn_data->scrMemPtr = mmi_frm_asm_alloc_nc_r(pcui->cui_gid, IV_TOTAL_SCREEN_MEMORY_SIZE);
        if (pscrn_data->scrMemPtr == NULL) {
            if (pscrn_data->medMemPtr != NULL) {
                mmi_frm_asm_free_r(pcui->cui_gid, pscrn_data->medMemPtr);
            }
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_deinit_memory
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_deinit_memory(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IV_TOTAL_MED_MEMORY_SIZE != 0)
    {
        mmi_frm_asm_free_r(pcui->cui_gid, pscrn_data->medMemPtr);
    }

    if (IV_TOTAL_SCREEN_MEMORY_SIZE != 0)
    {
        mmi_frm_asm_free_r(pcui->cui_gid, pscrn_data->scrMemPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_init_scn_res
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL cui_iv_init_scn_res(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_INIT_SCRN_RES);

    pscrn_data->flag = 0;

    if (MMI_FALSE == cui_iv_init_memory(pcui)) {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_ALLOC_MEMORY, MMI_FALSE);
        return MMI_FALSE;
    }
    else {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_ALLOC_MEMORY, MMI_TRUE);
    }

    cui_iv_init_layer(pcui);

    pscrn_data->flag = 0;

    CUI_IV_CACHE_INIT(pcui);

    /* init large cache */
    CUI_IV_ZOOM_INIT(pcui);

    /* Create and init OSD */
    CUI_IV_INIT_OSD(pscrn_data);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_popup_error_sg
 * DESCRIPTION
 *  This function shows display popup.
 * PARAMETERS
 *  parent_gid      [IN]
 *  str_ptr         [IN]
 *  event           [IN]
 *  is_rot          [IN]
 *  usrdata         [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_popup_error_sg(
                mmi_id parent_gid,
                UI_string_type str_ptr,
                mmi_event_notify_enum event,
                S32 is_rot,
                void *usrdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_screen_rotate_enum lcd_rotate = MMI_FRM_SCREEN_ROTATE_0;
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* IVEX ui use layer rotate */
    mmi_popup_property_init(&arg);

#if defined(__MMI_SCREEN_ROTATE__)
    if (is_rot)
    {
        lcd_rotate = MMI_FRM_SCREEN_ROTATE_270;
    }
#endif /* defined(__MMI_SCREEN_ROTATE__) */

    if (parent_gid == GRP_ID_INVALID)
    {
        arg.parent_id = GRP_ID_ROOT;
    }
    else
    {
        arg.parent_id = parent_gid;
        arg.user_tag = (void*)usrdata;
    }

    arg.rotation = lcd_rotate;

    mmi_popup_display((WCHAR*) str_ptr, event, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_make_bg_exit
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_iv_make_bg_exit(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;
    gdi_handle h_base;
    gdi_handle h_notBase;
    gdi_handle h1, h2, h3, h4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_base_handle(&h_base);

    if (h_base == pscrn_data->h_disp_layer)
        h_notBase = pscrn_data->h_cache_layer;
    else
        h_notBase = pscrn_data->h_disp_layer;

    gdi_layer_get_blt_layer(&h1, &h2, &h3, &h4);

    gdi_layer_push_and_set_active(h_notBase);
    gdi_layer_flatten(h1, h2, h3, h4);
    gdi_layer_pop_and_restore_active();

    gdi_layer_resize_nb_concurrent(h_base, LCD_WIDTH, LCD_HEIGHT);
    gdi_layer_set_rotate_nb_concurrent(h_base, GDI_LAYER_ROTATE_0);
    gdi_layer_set_position_nb_concurrent(h_base, 0, 0);

    gdi_layer_flatten_to_base(h_notBase, 0, 0, 0);

    gdi_layer_set_blt_layer(h_base, 0, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_still_exit
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_still_exit(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_STILL_EXIT);

    /* Stop async operations */
    cui_iv_cancel_img_ops(pcui);

    /* Cancel repeat key emulator */
    gui_cancel_timer((FuncPtr) cui_iv_rkey_cyclic);

    /* Stop waiting for double click. */
    CUI_IV_STILL_PEN_STOP_WAITE_DOUBLE();
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_scn_exit
 * DESCRIPTION
 *  exit screen handler
 * PARAMETERS
 *  evt     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_scn_exit(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    cui_iv_cntx *pcui = (cui_iv_cntx*) evt->user_data;
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SCRN_EXIT, pcui->scrn_stat);

    if (pcui->scrn_stat < IV_SCRN_STAT_ACTIVE)
        return;

    CUI_IV_MOTION_STOP_LISTEN(pcui);

#ifdef __MMI_IV_PLUTO_SLIM__
	StopTimer(IV_LOADING_TIMER);
#endif

#ifdef __MMI_IVF_TOUCH_SCREEN__
    /* restore to normal state */
    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
#endif /* __MMI_IVF_TOUCH_SCREEN__ */
    if (pcui->scrn_stat < IV_SCRN_STAT_INACTIVE)
    {
        if (cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].exit_hdlr)
        {
            cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].exit_hdlr(pcui);
        }
    }

    /* pause consume drm rights */
    CUI_IV_PAUSE_SHOW(pcui, pcui->index);

    /* make background and restore base layer */
    cui_iv_make_bg_exit(pcui);

    CUI_IV_DEINIT_OSD(pscrn_data);

    CUI_IV_ZOOM_DEINIT(pcui);

    CUI_IV_CACHE_DEINIT(pcui);

    cui_iv_deinit_layer(pcui);

    cui_iv_deinit_memory(pcui);

    pcui->scrn_stat = IV_SCRN_STAT_INACTIVE;

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
    /* this will force title status to redraw */
    entry_full_screen();
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_set_blt_layer
 * DESCRIPTION
 *  This function may be not necessary.
 * PARAMETERS
 *  pscrn_data      [IN]
 *  img_stat        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_set_blt_layer(const cui_iv_scrndata *pscrn_data, cui_iv_img_stat img_stat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle h_layer;
    gdi_handle h_switch = GDI_LAYER_EMPTY_HANDLE;
    gdi_handle h_panel = GDI_LAYER_EMPTY_HANDLE;
    gdi_handle h_title = GDI_LAYER_EMPTY_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (img_stat == IV_IMG_STAT_OK)
    {
        h_layer = pscrn_data->h_disp_layer;
    }
    else
    {
        h_layer = CUI_IV_GET_ERR_DST_LYR(pscrn_data->h_disp_layer, pscrn_data->h_cache_layer);
    }

    /* get title and panel layer */
    CUI_IV_GET_OSD_LAYERS(pscrn_data, &h_panel, &h_title);

    CUI_IV_GET_BLT_LAYERS(pscrn_data, &h_layer, &h_switch);

    /* set blt layers */
    gdi_layer_set_blt_layer_nb_concurrent(h_layer, h_switch, h_panel, h_title);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SET_BLT_LAYER, h_layer, h_switch, h_panel, h_title);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_get_context
 * DESCRIPTION
 *  get cui context for no user data callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static cui_iv_cntx *cui_iv_get_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id = GRP_ID_INVALID;
    MMI_ID scrn_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_get_active_scrn_id(&group_id, &scrn_id);

    if (scrn_id != SCR_ID_IMGVIEW_VIEW) /* the logic is not sufficient, but we have no other methods. */
    {
        return NULL;
    }

    return (cui_iv_cntx*) mmi_frm_group_get_user_data(group_id);

}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_view_imgadp_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  pImg            [?]
 *  evt             [IN]
 *  userdata        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_view_imgadp_callback(cui_iv_imgadp_img_struct *pImg, U32 evt, void *userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui = (cui_iv_cntx*) userdata;
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_CALLBACK, pImg, pImg->index, evt);

    if (pImg != pinfo->pImg)
        return;

    /* Maybe there is a trap as bellow case:
       From first switch to last, load filename have not ready.
       But when switch done, will re-start cache, then curr image decode done will callback.
       For this case should not show image, should waite for load complete, then get image again. */
    switch (evt)
    {
        case CUI_IV_IMGADP_EVENT_DECODING:
            pinfo->stat = IV_IMG_STAT_DECODING;
            break;

        case CUI_IV_IMGADP_EVENT_OK:
            pinfo->stat = IV_IMG_STAT_OK;
            if (!pinfo->is_anim)
                CUI_IV_ZOOM_INIT_IMG_EXTINFO(pcui); /* Init zoom factors to determine if the image could be zoomed */
		#ifdef __MMI_IV_PLUTO_SLIM__
			StopTimer(IV_LOADING_TIMER);
		#endif
            break;

        case CUI_IV_IMGADP_EVENT_ERR:
            pinfo->stat = IV_IMG_STAT_ERR;
            break;

        default:
            break;
    }

    /* update screen */
    cui_iv_update_screen(pcui, CUI_IV_UPDATE_NEW_IMAGE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_update_screen
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui                [?]
 *  update_trigger      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_update_screen(cui_iv_cntx *pcui, S32 update_trigger)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;
    GDI_HANDLE err_dst_lyr = CUI_IV_GET_ERR_DST_LYR(pcui->scrn_data.h_disp_layer, pcui->scrn_data.h_cache_layer);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_UPDATE_SCRN, pinfo->stat);

    /*
     * Condition: if(update_trigger != CUI_IV_UPDATE_OSD) is a temperary solution.
     * It is to resolve the scenario: Any call sync draw function, eg gdi_image_draw_id(), 
     * will abort the none-blocking decode. And the OSD hide or show has no need to redraw 
     * the image area.
     * We need to revise this function to avoid draw any unnecessary thing in future.
     */
    if(update_trigger != CUI_IV_UPDATE_OSD){
        switch (pinfo->stat)
        {
            case IV_IMG_STAT_ERR:
                /* draw error icon */
        #ifdef __DRM_SUPPORT__
                if (pinfo->err_code == CUI_IV_ERR_NO_RIGHT)
                {
                    cui_iv_draw_err_icon(err_dst_lyr, IMG_ID_IV_ERROR_NO_RIGHT);
                }
                else
        #endif /* __DRM_SUPPORT__ */
                {
	            #ifdef __MMI_IV_PLUTO_SLIM__
                    cui_iv_draw_err_string(err_dst_lyr);
				#else
                    cui_iv_draw_err_icon(err_dst_lyr, IMG_ID_IV_ERROR);
				#endif
                }
                break;

            case IV_IMG_STAT_LOADING:
            case IV_IMG_STAT_DECODING:
                /* draw loading icon */
				#ifdef __MMI_IV_PLUTO_SLIM__
					loading_dstLyr = err_dst_lyr;
					cui_iv_draw_load_string();
				#else
                cui_iv_draw_err_icon(err_dst_lyr, IMG_ID_IV_LOAD);
				#endif
                break;

            default:
                break;
        };
    }

    if (update_trigger & CUI_IV_UPDATE_NEW_IMAGE)
    {
        CUI_IV_SHOW_IMAGE(pcui, pinfo->stat == IV_IMG_STAT_OK);
    }

    /* blt to LCD */
    cui_iv_set_blt_layer(&pcui->scrn_data, pinfo->stat);
    gdi_layer_blt_previous_nb_concurrent(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_scn_entry
 * DESCRIPTION
 *  Entry of main screen.
 * PARAMETERS
 *  evt     [?]
 * RETURNS
 *  Success or not
 *****************************************************************************/
static MMI_BOOL cui_iv_scn_entry(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui = (cui_iv_cntx*) evt->user_data;
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;
    cui_iv_scrn_stat org_scrn_stat = pcui->scrn_stat;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SCRN_ENTRY);

    /* init screen data */
    memset(pscrn_data, 0, sizeof(cui_iv_scrndata));

    pcui->scrn_stat = IV_SCRN_PRE_ACTIVE;
    /* check before enter screen */
    if (org_scrn_stat == IV_SCRN_STAT_INACTIVE)
    {
        if (!cui_iv_is_src_valid(pcui))
        {
            /* popup message */
            cui_iv_popup_error_sg(
                GRP_ID_ROOT,
                (UI_string_type) GetString(FMGR_FS_MEDIA_CHANGED_TEXT),
                MMI_EVENT_FAILURE,
                pcui->disp_cap & CUI_IMGVIEW_DISP_ROT,
                NULL);

            return MMI_FALSE;
        }
    }

    if (mmi_am_is_using_media_memory())
    {
        S32 type;
        MMI_STR_ID strid = mmi_am_get_error_info(MMI_MRE_ERR_IS_UNAVAILABLE, &type);

        cui_iv_popup_error_sg(
            GRP_ID_ROOT,
            (UI_string_type) GetString(strid),
            MMI_EVENT_FAILURE,
            pcui->disp_cap & CUI_IMGVIEW_DISP_ROT,
            NULL);

        return MMI_FALSE;
    }

    /* malloc and init screen based resources */
    if (MMI_FALSE == cui_iv_init_scn_res(pcui))
        return MMI_FALSE;

    /* init data only valid when screen is active */
    cui_iv_scn_on_active(pcui);
    pcui->scrn_stat = IV_SCRN_STAT_ACTIVE;

    /* init current base info */
    cui_iv_load_filename(pcui, pcui->index, (void*)pcui, cui_iv_load_complete);

    /* blt to lcd */
    gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_scn_proc
 * DESCRIPTION
 *  Proc of main screen.
 * PARAMETERS
 *  evt     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_iv_scn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui = (cui_iv_cntx*) evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            if (MMI_FALSE == cui_iv_scn_entry(evt))
            {
                cui_iv_close(pcui);
            }
		#if defined (GDI_COLORENGINE_SUPPORT)
    		gdi_color_engine_open();
			gdi_color_engine_enable();
		#endif
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
            mmi_frm_cb_reg_event(EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING, cui_iv_screen_locker_event_handler, pcui);
#endif
        }
            break;

        case EVT_ID_SCRN_INACTIVE:
        {
		#if defined (GDI_COLORENGINE_SUPPORT)
			gdi_color_engine_disable();
			gdi_color_engine_close();
		#endif
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
            mmi_frm_cb_dereg_event(EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING, cui_iv_screen_locker_event_handler, pcui);
#endif
            cui_iv_scn_exit(evt);
        }
            break;

        case EVT_ID_ON_KEY:
        {
		#ifdef __MMI_IV_PLUTO_SLIM__
			StopTimer(IV_LOADING_TIMER);
		#endif
            cui_iv_scrn_key_proc(evt);
        }
            break;

        case EVT_ID_SCRN_DEINIT:
        {
            CUI_IV_EXIT_SHOW(pcui);
        }
            break;

    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_init_img_scrn_info
 * DESCRIPTION
 *  Init the image info which will not be reserved after the screen exit
 * PARAMETERS
 *  pinfo           [?]
 *  pfilename       [?]
 *  img_orient      [IN]
 * RETURNS
 *
 *****************************************************************************/
static MMI_BOOL cui_iv_init_img_scrn_info(
                    cui_iv_img_extinfo *pinfo,
                    const WCHAR *pfilename,
                    U8 img_orient)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    CHAR *error_str_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_INIT_IMG_VAR_INFO);

    pinfo->type = GDI_IMAGE_TYPE_INVALID;
    pinfo->is_anim = 0;

    if (MMI_FALSE == CUI_IV_DRM_CHECK_RIGHT(pfilename))
    {
        CUI_IV_DRM_SET_ERR(pinfo);
        return MMI_FALSE;
    }

    if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, (CHAR*) pfilename, &error_str_ptr))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_INIT_IMG_VAR_INFO_RET1);
        return MMI_FALSE;
    }

    pinfo->type = gdi_image_get_type_from_file((CHAR*) pfilename);
    ret = gdi_image_get_dimension_file((CHAR*) pfilename, &(pinfo->org_w), &(pinfo->org_h));
    if (((pinfo->org_w <= 0) || (pinfo->org_h <= 0)) ||
        (ret < 0 || GDI_IMAGE_TYPE_INVALID == pinfo->type) ||
        ((pinfo->org_w > IV_MAX_IMG_SIZE) || (pinfo->org_h > IV_MAX_IMG_SIZE)))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_INIT_IMG_VAR_INFO_RET2, ret, pinfo->org_w, pinfo->org_h);
        return MMI_FALSE;
    }
    else
    {
        S32 layer_w, layer_h;

        if (img_orient == GDI_LAYER_ROTATE_0 || img_orient == GDI_LAYER_ROTATE_180)
        {
            layer_w = LCD_WIDTH;
            layer_h = LCD_HEIGHT;
        }
        else
        {
            layer_h = LCD_WIDTH;
            layer_w = LCD_HEIGHT;
        }
        gdi_util_fit_box(
            GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
            layer_w,
            layer_h,
            pinfo->org_w,
            pinfo->org_h,
            &pinfo->draw_x,
            &pinfo->draw_y,
            &pinfo->cur_w,
            &pinfo->cur_h);
    }

    switch (pinfo->type)
    {
        case GDI_IMAGE_TYPE_GIF:
        case GDI_IMAGE_TYPE_GIF_FILE:
        case GDI_IMAGE_TYPE_M3D:
        case GDI_IMAGE_TYPE_M3D_FILE:
            pinfo->is_anim = CUI_IV_IMGADP_ANIM_CHECK(pfilename);
            break;

        default:
            break;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_load_complete
 * DESCRIPTION
 *
 * PARAMETERS
 *  usrdata     [?]
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_load_complete(void *usrdata, S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui = (cui_iv_cntx*) usrdata;
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_LOAD_COMPLETE, result);

    if (result < 0)
    {
        pinfo->stat = IV_IMG_STAT_ERR;
    }
    else if (result > 0)
    {
        pinfo->stat = IV_IMG_STAT_LOADING;
    }
    else
    {
        /* Decode image to layer */
        CUI_IV_DEC_IMG(
            pcui,
            pcui->file_name,
            pinfo,
            pcui->scrn_data.h_disp_layer,
            pcui->scrn_data.h_cache_layer,
            cui_iv_view_imgadp_callback,
            (void*)pcui);
    }

    /* Update screen */
	#ifdef __MMI_IV_PLUTO_SLIM__
		StopTimer(IV_LOADING_TIMER);
	#endif
    CUI_IV_UPDATE_TITLE(pcui);
    cui_iv_update_screen(pcui, CUI_IV_UPDATE_NEW_IMAGE | CUI_IV_UPDATE_OSD);
}

/*************** Slide Show ****************/
#ifdef __MMI_IVF_SLIDE__
#define IV_CUI_SLIDE_FLAG_TIMEOUT       0x1     /* current play complete */
#define IV_CUI_SLIDE_FLAG_NEXT_OK       (0x1<<1)
#define IV_CUI_SLIDE_FLAG_IMG_FINISH    (0x1<<2)
#define IV_CUI_SLIDE_FLAG_START         (0x1<<3)
#define IV_CUI_SLIDE_FLAG_FIRST         (0x1<<4)
#define IV_CUI_SLIDE_FLAG_POST_ROT      (0x1<<5)

#define IV_CUI_SLIDE_FLAG_ASYNC_MASK    (0xFF00)
#define IV_CUI_SLIDE_FLAG_LOADING       (0x1<<8)
#define IV_CUI_SLIDE_FLAG_DECODING      (0x1<<9)
#define IV_CUI_SLIDE_FLAG_RELOADING     (0x1<<10)

#define IV_CUI_SLIDE_IS_TIMEOUT(flag)   ((flag) & IV_CUI_SLIDE_FLAG_TIMEOUT)
#define IV_CUI_SLIDE_NEXT_OK(flag)      ((flag) & IV_CUI_SLIDE_FLAG_NEXT_OK)
#define IV_CUI_SLIDE_IMG_END(flag)      ((flag) & IV_CUI_SLIDE_FLAG_IMG_FINISH)
#define IV_CUI_SLIDE_PLAY_END(flag)     ((IV_CUI_SLIDE_IMG_END(flag)) && (IV_CUI_SLIDE_IS_TIMEOUT(flag)))

static S32 cui_iv_slide_start_switch(cui_iv_slide_data_t *pslide);
static void cui_iv_slide_start_load_file(void *pdata);
static void cui_iv_slide_load_file_complete(void *pdata, S32 result);


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_play_complete
 * DESCRIPTION
 *
 * PARAMETERS
 *  pslide      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_slide_play_complete(cui_iv_slide_data_t *pslide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SLIDE_PLAY_COMPLETE, pslide->flag);

    if (IV_CUI_SLIDE_PLAY_END(pslide->flag) && IV_CUI_SLIDE_NEXT_OK(pslide->flag))
    {
        cui_iv_slide_start_switch(pslide);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_play_timeout
 * DESCRIPTION
 *
 * PARAMETERS
 *  pdata       [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_slide_play_timeout(void *pdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_slide_data_t *pslide = (cui_iv_slide_data_t*) pdata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SLIDE_PLAY_TIMEOUT);
    pslide->flag |= IV_CUI_SLIDE_FLAG_TIMEOUT;
    cui_iv_slide_play_complete(pslide);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_start_play
 * DESCRIPTION
 *
 * PARAMETERS
 *  pslide      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_slide_start_play(cui_iv_slide_data_t *pslide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn = GET_SCRNDATA_FROM_SLIDE(pslide);
    cui_iv_cntx *pcui = GET_CUI_FROM_SCRNDATA(pscrn);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SLIDE_START_PLAY);

    if (pslide->flag & IV_CUI_SLIDE_FLAG_FIRST)
    {
        pslide->flag =
            IV_CUI_SLIDE_FLAG_START | IV_CUI_SLIDE_FLAG_FIRST | IV_CUI_SLIDE_FLAG_TIMEOUT |
            IV_CUI_SLIDE_FLAG_IMG_FINISH;
        pslide->pCurrImg = NULL;
    }
    else
    {
        /* clear flag */
        pslide->flag = IV_CUI_SLIDE_FLAG_START;

        /* save index of current show image */
        pslide->cur_index = pcui->index;

        cui_iv_imgadp_resume(pcui, pslide->pCurrImg);

        /* Start timer */
        gui_start_timer_ex(MMI_IV_SLIDE_PLAY_INTERVAL, cui_iv_slide_play_timeout, pslide);
    }

    if (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT)
        pslide->flag |= IV_CUI_SLIDE_FLAG_POST_ROT;

    /* Prepare next */
    cui_iv_slide_start_load_file(pslide);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_switch_complete
 * DESCRIPTION
 *
 * PARAMETERS
 *  userData        [?]
 *  index           [IN]        Not used for slide, but used for view
 *  newDispCap      [IN]        Not used for slide, but used for view
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_slide_switch_complete(void *userData, U32 index, U32 newDispCap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle h_layer;
    cui_iv_slide_data_t *pslide = (cui_iv_slide_data_t*) userData;
    cui_iv_scrndata *pscrn = GET_SCRNDATA_FROM_SLIDE(pslide);
    cui_iv_cntx *pcui = GET_CUI_FROM_SCRNDATA(pscrn);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SLIDE_SWITCH_COMPLETE, index, newDispCap);
#ifdef __MMI_IV_PLUTO_SLIM__
	StopTimer(IV_LOADING_TIMER);
#endif
    gdi_layer_set_blt_layer_nb_concurrent(pslide->h_layer[1], 0, 0, 0);

    gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

    CUI_IV_SHOW_IMAGE(pcui, 1);

    /* Swap layer */
    h_layer = pslide->h_layer[0];
    pslide->h_layer[0] = pslide->h_layer[1];
    pslide->h_layer[1] = h_layer;

    /* Swap img */
    pslide->pCurrImg = pcui->scrn_data.cur_img_info.pImg;
    pcui->scrn_data.cur_img_info.pImg = NULL;

    if (pslide->flag & IV_CUI_SLIDE_FLAG_POST_ROT)
        pcui->disp_cap |= CUI_IMGVIEW_DISP_ROT;
    else
        pcui->disp_cap &= ~CUI_IMGVIEW_DISP_ROT;

    cui_iv_slide_start_play(pslide);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_start_switch
 * DESCRIPTION
 *
 * PARAMETERS
 *  pslide      [?]
 * RETURNS
 *
 *****************************************************************************/
static S32 cui_iv_slide_start_switch(cui_iv_slide_data_t *pslide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn = GET_SCRNDATA_FROM_SLIDE(pslide);
    cui_iv_cntx *pcui = GET_CUI_FROM_SCRNDATA(pscrn);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SLIDE_SWITCH_START);

    if (pslide->flag & IV_CUI_SLIDE_FLAG_FIRST)
    {
        pslide->flag &= ~IV_CUI_SLIDE_FLAG_FIRST;
        cui_iv_slide_switch_complete((void*)&pcui->scrn_data.slide_data, pcui->index, pcui->disp_cap);
    }
    else
    {
        /* Stop the current image */
        cui_iv_imgadp_stop(pcui, pslide->pCurrImg);
        CUI_IV_SE_INIT_DATA_EASE(pcui, pcui->index, 1, pslide->h_layer[0], pslide->h_layer[1]);
        CUI_IV_SE_START(pcui, pcui->index, cui_iv_slide_switch_complete, (void*)&pcui->scrn_data.slide_data);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_imgadp_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  pImg            [?]
 *  evt             [IN]
 *  userdata        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_slide_imgadp_callback(cui_iv_imgadp_img_struct *pImg, U32 evt, void *userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_slide_data_t *pslide = (cui_iv_slide_data_t*) userdata;
    cui_iv_scrndata *pscrn = GET_SCRNDATA_FROM_SLIDE(pslide);
    cui_iv_cntx *pcui = GET_CUI_FROM_SCRNDATA(pscrn);
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SLIDE_IMGADP_CALLBACK, pImg, pImg->index, evt);

    if (pImg == pinfo->pImg)
    {
        /*
         * Maybe there is a trap as bellow case:
         * If for one image callback twice, will cause some error.
         * Like if the image is error, then callback twice will cause start two timer to start load file.
         */
        switch (evt)
        {
            case CUI_IV_IMGADP_EVENT_DECODING:
            {
                pinfo->stat = IV_IMG_STAT_DECODING;
                pslide->flag &= ~IV_CUI_SLIDE_FLAG_ASYNC_MASK;
                pslide->flag |= IV_CUI_SLIDE_FLAG_DECODING;
            }
                break;

            case CUI_IV_IMGADP_EVENT_OK:
            {
                pinfo->stat = IV_IMG_STAT_OK;

                /* for slide is background decode, the decoded image need play until switch done */
                cui_iv_imgadp_pause(pcui, pinfo->pImg);

                if (IV_CUI_SLIDE_PLAY_END(pslide->flag))
                {
                    /* Start Switch */
                    cui_iv_slide_start_switch(pslide);
                }
                else
                {
                    /* set next ready */
                    pslide->flag |= IV_CUI_SLIDE_FLAG_NEXT_OK;
                }
            }
                break;

            case CUI_IV_IMGADP_EVENT_ERR:
            {
                pinfo->stat = IV_IMG_STAT_ERR;
                cui_iv_imgadp_stop(pcui, pinfo->pImg);
                gui_start_timer_ex(MMI_IV_SLIDE_RELOAD_INTERVAL, cui_iv_slide_start_load_file, pslide);
            }
                break;

            default:
                break;
        }
    }
    else if (pImg == pslide->pCurrImg)
    {
        switch (evt)
        {
            case CUI_IV_IMGADP_EVENT_FINISH:
            {
                if (pslide->flag & IV_CUI_SLIDE_FLAG_IMG_FINISH)
                    /* This is avoid bellow case:
                       First, next decode is done; then anim finish; then time out.
                       If anim whole time is shorter than switch effect whole time,
                       then will caused to endless loop */
                    break;

                pslide->flag |= IV_CUI_SLIDE_FLAG_IMG_FINISH;
                cui_iv_slide_play_complete(pslide);
            }
                break;

            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_start_decode_img
 * DESCRIPTION
 *
 * PARAMETERS
 *  pslide      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_slide_start_decode_img(cui_iv_slide_data_t *pslide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn = GET_SCRNDATA_FROM_SLIDE(pslide);
    cui_iv_cntx *pcui = GET_CUI_FROM_SCRNDATA(pscrn);
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_iv_imgadp_draw(
        pcui,
        pcui->file_name,
        pinfo,
        pslide->h_layer[1],
        GDI_LAYER_EMPTY_HANDLE,
        cui_iv_slide_imgadp_callback,
        (void*)pslide);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_load_file_complete
 * DESCRIPTION
 *
 * PARAMETERS
 *  pdata       [?]
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_slide_load_file_complete(void *pdata, S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_slide_data_t *pslide = (cui_iv_slide_data_t*) pdata;
    cui_iv_scrndata *pscrn = GET_SCRNDATA_FROM_SLIDE(pslide);
    cui_iv_cntx *pcui = GET_CUI_FROM_SCRNDATA(pscrn);
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SLIDE_LOAD_FIN, result);

    if (result > 0)
    {
        pinfo->stat = IV_IMG_STAT_LOADING;
        pslide->flag |= IV_CUI_SLIDE_FLAG_LOADING;
    }
    else if (result < 0)
    {
        pinfo->stat = IV_IMG_STAT_ERR;
        gui_start_timer_ex(MMI_IV_SLIDE_RELOAD_INTERVAL, cui_iv_slide_start_load_file, pdata);
    }
    else
    {
        cui_iv_slide_start_decode_img(pslide);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_init_img_info
 * DESCRIPTION
 *  Caution: this is a temp solution
 * PARAMETERS
 *  pcui        [?]
 *  index       [IN]
 *  rot_val     [IN]
 *  dstHdl      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_slide_init_img_info(cui_iv_cntx *pcui, U32 index, U8 rot_val, GDI_HANDLE dstHdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_INIT_IMG_INFO, index, rot_val);

    /* init info */
    memset(pinfo, 0, sizeof(cui_iv_img_extinfo));
    memset(&pcui->img_base_info, 0, sizeof(cui_iv_img_baseinfo));
    pcui->index = index;

    pcui->img_base_info.img_orient = rot_val;

    if (rot_val == GDI_LAYER_ROTATE_90 || rot_val == GDI_LAYER_ROTATE_270)
    {
        w = LCD_HEIGHT;
        h = LCD_WIDTH;
    }
    else
    {
        w = LCD_WIDTH;
        h = LCD_HEIGHT;
    }

    gdi_layer_resize_nb_concurrent(dstHdl, w, h);
    gdi_layer_set_rotate_nb_concurrent(dstHdl, rot_val);

    CUI_IV_ZOOM_INIT_BASE_INFO(&pcui->img_base_info);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_start_load_file
 * DESCRIPTION
 *
 * PARAMETERS
 *  pdata       [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_slide_start_load_file(void *pdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* load file */
    cui_iv_slide_data_t *pslide = (cui_iv_slide_data_t*) pdata;
    cui_iv_scrndata *pscrn = GET_SCRNDATA_FROM_SLIDE(pslide);
    cui_iv_cntx *pcui = GET_CUI_FROM_SCRNDATA(pscrn);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pcui->index++;
    if (pcui->index >= pcui->count)
        pcui->index = 0;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SLIDE_LOAD_START, pcui->index);

    /* Update IVC index */
    CUI_IV_CACHE_SET_CURR_IDX(pcui, pcui->index);

    cui_iv_slide_init_img_info(
        pcui,
        pcui->index,
        (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT) == CUI_IMGVIEW_DISP_ROT ? GDI_LAYER_ROTATE_90 : GDI_LAYER_ROTATE_0,
        pslide->h_layer[1]);

    cui_iv_load_filename(pcui, pcui->index, (void*)pslide, cui_iv_slide_load_file_complete);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_slide_stop(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_slide_data_t *pslide = &pcui->scrn_data.slide_data;
    MMI_BOOL is_done;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SLIDE_STOP);

    is_done = CUI_IV_SE_STOP(pcui);

    /* stop all the timer and async operations */
    gui_cancel_timer((FuncPtr) cui_iv_slide_start_load_file);
    gui_cancel_timer((FuncPtr) cui_iv_slide_play_timeout);

    if (pslide->flag & IV_CUI_SLIDE_FLAG_LOADING)
    {
        /* Stop current loading */
        cui_iv_cancel_load_file();
    }

    cui_iv_imgadp_stop(pcui, pslide->pCurrImg);
    cui_iv_imgadp_stop(pcui, pcui->scrn_data.cur_img_info.pImg);
    /* Point:bellow two lines is work around for GDI callbacks has no userdata */
    pslide->pCurrImg = NULL;
    pcui->scrn_data.cur_img_info.pImg = NULL;

    if (pslide->flag & IV_CUI_SLIDE_FLAG_POST_ROT)
        pcui->disp_cap |= CUI_IMGVIEW_DISP_ROT;
    else
        pcui->disp_cap &= ~CUI_IMGVIEW_DISP_ROT;

    /* reset flag */
    pslide->flag = 0;

    if (MMI_FALSE == is_done)
    {
        /* reload current image to sync the layer and image info */
        pcui->index = pslide->cur_index;
    }

    /* Reset osd */
    CUI_IV_OSD_RESET_FRAME(&pcui->scrn_data);
    cui_iv_init_img_info(
        pcui,
        pcui->index,
        (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT) == CUI_IMGVIEW_DISP_ROT ? GDI_LAYER_ROTATE_90 : GDI_LAYER_ROTATE_0);

    /* Update IVC index */
    CUI_IV_CACHE_SET_CURR_IDX(pcui, pcui->index);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_is_playing
 * DESCRIPTION
 *  Get whether slide show is going.
 * PARAMETERS
 *  pcui        [?]     Context of CUI.
 * RETURNS
 *  MMI_BOOL : current state of slide.
 *  MMI_TRUE: started
 *  MMI_FALSE: stoped
 *****************************************************************************/
MMI_BOOL cui_iv_slide_is_playing(cui_iv_cntx *pcui)
{
    cui_iv_slide_data_t *pslide = &pcui->scrn_data.slide_data;
    if (pcui->count <= 1)
    {
        return MMI_FALSE;
    }

    if (pslide->flag)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_play
 * DESCRIPTION
 *  If current state is stop, start slide. else, stop slide.
 * PARAMETERS
 *  pcui        [?]     Context of CUI.
 * RETURNS
 *  MMI_BOOL : current state of slide after the call.
 *  MMI_TRUE: started
 *  MMI_FALSE: stoped
 *****************************************************************************/
static MMI_BOOL cui_iv_slide_play(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_slide_data_t *pslide = &pcui->scrn_data.slide_data;
    cui_iv_scrndata *pscrn = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pcui->count <= 1)
    {
        return MMI_FALSE;
    }

    if (pslide->flag)
    {
        /* Restore backlight */
        srv_backlight_turn_off();

        cui_iv_slide_stop(pcui);
        pcui->scrn_stat = IV_SCRN_STAT_ACTIVE;
        cui_iv_load_filename(pcui, pcui->index, (void*)pcui, cui_iv_load_complete);
        CUI_IV_SHOW_OSD(pscrn, 1);
        return MMI_FALSE;
    }
    else
    {
        /* Use current state to decide if draw loading icon again */
        cui_iv_img_stat oldStat = pcui->scrn_data.cur_img_info.stat;

        /* Turn backlight */
        srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
        /* hide osd */
        CUI_IV_OSD_SET_HIDE(pscrn);
        /* Cancel uncompleted operations of current image */
        cui_iv_cancel_img_ops(pcui);

        /* start play */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SLIDE_START);
        /* init data */
        memset(pslide, 0, sizeof(cui_iv_slide_data_t));
        pslide->cur_index = pcui->index;
        /* load from current and show loading or error */
        pcui->index--;
        if (pcui->index >= pcui->count)
        {
            pcui->index = pcui->count - 1;
        }
        /* Init image info which only related to the image */
        cui_iv_init_img_info(
            pcui,
            pcui->index,
            (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT) == CUI_IMGVIEW_DISP_ROT ? GDI_LAYER_ROTATE_90 : GDI_LAYER_ROTATE_0);

        /*
         * The order of this two layer cannot be changed,
         * because the h_disp_layer may contains the decoded done image or err icon which is showing now.
         */
        pslide->h_layer[0] = pcui->scrn_data.h_disp_layer;
        pslide->h_layer[1] = pcui->scrn_data.h_cache_layer;

        if (IV_IMG_STAT_OK != oldStat && IV_IMG_STAT_ERR != oldStat)
        {
            /*
             * Redraw loading icon on layer[0] and blt.
             * layer[1] is used to re-decode current image.
             */
            #ifdef __MMI_IV_PLUTO_SLIM__
				loading_dstLyr = pslide->h_layer[0];
				cui_iv_draw_load_string();
			#else
            cui_iv_draw_err_icon(pslide->h_layer[0], IMG_ID_IV_LOAD);
			#endif
            gdi_layer_set_blt_layer_nb_concurrent(pslide->h_layer[0], 0, 0, 0);
            gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
        }
        else
        {
            /*
             * Do nothing, not update current display of image.
             * It maybe ok or error.
             */
        }

        pslide->flag = IV_CUI_SLIDE_FLAG_FIRST;
        cui_iv_slide_start_play(pslide);
        pcui->scrn_stat = IV_SCRN_STAT_PLAY;
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_key_down
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  key_code        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_slide_key_down(cui_iv_cntx *pcui, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SLIDE_KEY_DOWN);

    cui_iv_slide_play(pcui);
    pcui->scrn_data.flag &= ~IV_FLAG_KEY_DOWN;  /* ignore the key up */
}

#ifdef __MMI_IVF_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_pen_down
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  touchData       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_slide_pen_down(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SLIDE_PEN_DOWN);
    cui_iv_slide_play(pcui);
}
#endif /* __MMI_IVF_TOUCH_SCREEN__ */

#ifdef __MMI_IVF_MOTION__


/*****************************************************************************
 * FUNCTION
 *  cui_iv_slide_motion_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  rot         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_slide_motion_hdlr(cui_iv_cntx *pcui, U32 rot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SLIDE_MOTION_HDLR, rot);

    if (rot & CUI_IMGVIEW_DISP_ROT)
        pcui->scrn_data.slide_data.flag |= IV_CUI_SLIDE_FLAG_POST_ROT;
    else
        pcui->scrn_data.slide_data.flag &= ~IV_CUI_SLIDE_FLAG_POST_ROT;
}

#endif /* __MMI_IVF_MOTION__ */

#endif /* __MMI_IVF_SLIDE__ */

#ifdef __MMI_IVF_OPTION__


/*****************************************************************************
 * FUNCTION
 *  cui_iv_options_entry
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_options_entry(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_create_and_run(
        pcui->cui_gid,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        MENU_ID_IMGVIEW_VIEW_OPTION,
        MMI_TRUE,
        pcui);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_options_init
 * DESCRIPTION
 *  init use option list
 * PARAMETERS
 *  parent_id       [IN]
 *  path            [?]
 *  is_send         [IN]        MMI_TRUE--send, MMI_FALSE--use as
 * RETURNS
 *  void
 *****************************************************************************/
IV_MOD_API void cui_iv_options_init(S32 parent_id, WCHAR *path, int is_send)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 parent_menu_id;
    S32 sub_menu_id;
    U16 sub_id_num;
    MMI_MENU_ID sub_ids[MAX_SUB_MENUS];
    MMI_STR_ID sub_id_strs[MAX_SUB_MENUS];
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* condition: have saved the image
       use filepath to ask fmgr for send option and init the sub menu list of send */
    if (is_send)
    {
        parent_menu_id = srv_fmgr_types_get_send_option_menu(FMGR_TYPE_ALL, path);
    }
    else
    {
        parent_menu_id = srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, path);
    }

    sub_id_num = GetNumOfChild_Ext(parent_menu_id);
    GetSequenceStringIds_Ext(parent_menu_id, sub_id_strs);

    for (i = 0; i < sub_id_num; i++)
    {
        sub_ids[i] = GetSeqItemId_Ext(parent_menu_id, i);
    }

    if (parent_menu_id > 0)
    {
        cui_menu_set_currlist(parent_id, sub_id_num, (MMI_MENU_ID*) sub_ids);

        for (i = 0; i < sub_id_num; i++)
        {
            sub_menu_id = cui_menu_get_currlist_menu_id_from_index(parent_id, i);

            cui_menu_set_item_string_by_id(parent_id, sub_menu_id, sub_id_strs[i]);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_options_init_items
 * DESCRIPTION
 *  ivex current image option screen handler
 * PARAMETERS
 *  pcui            [?]
 *  sender_id       [IN]
 *  filepath        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_options_init_items(cui_iv_cntx *pcui, MMI_ID sender_id, WCHAR *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_unhide_child_menu_items(MENU_ID_IMGVIEW_VIEW_OPTION);
    cui_menu_set_non_leaf_item(sender_id, MENU_ID_IMGVIEW_VIEW_OPTION_SEND, MMI_TRUE);
    cui_menu_set_non_leaf_item(sender_id, MENU_ID_IMGVIEW_VIEW_OPTION_USE, MMI_TRUE);

    if (pcui->count <= 1)
    {
        mmi_frm_hide_menu_item(MENU_ID_IMGVIEW_VIEW_OPTION_PLAY);
    }

    /* Send menu */
#if defined(__MMI_BT_SUPPORT__)
    if ((!mmi_bt_is_to_display_bt_menu()) || srv_fmgr_types_get_send_option_menu(FMGR_TYPE_ALL, filepath) <= 0)
#else
    if (srv_fmgr_types_get_send_option_menu(FMGR_TYPE_ALL, filepath) <= 0)
#endif
    {
        mmi_frm_hide_menu_item(MENU_ID_IMGVIEW_VIEW_OPTION_SEND);
    }
    /* Use as menu */
    if (srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, filepath) <= 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_IMGVIEW_VIEW_OPTION_USE);
    }

    /* for filelist loading current file */
    if (pcui->scrn_data.cur_img_info.stat == IV_IMG_STAT_LOADING ||
        FMGR_GROUP_IMAGE != srv_fmgr_types_find_group_by_filename_str(filepath))
    {
        mmi_frm_hide_menu_item(MENU_ID_IMGVIEW_VIEW_OPTION_INFO);
    }

    /* Get right item */
#ifdef __MMI_RMGR__
    mmi_rmgr_option_enabler_more_rits(MENU_ID_FMGR_GEN_OPTION_MORE_RITS, filepath, NULL);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_menu_proc
 * DESCRIPTION
 *  Image view cui process function.
 * PARAMETERS
 *  evt     [?]     Events pointer.
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
IV_MOD_API mmi_ret cui_iv_menu_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_event = (cui_menu_event_struct*) evt;
    cui_iv_cntx *pcui = (cui_iv_cntx*) menu_event->app_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            switch (menu_event->parent_menu_id)
            {
                case MENU_ID_IMGVIEW_VIEW_OPTION:
                {
                    cui_iv_options_init_items(pcui, menu_event->sender_id, (WCHAR*) pcui->file_name);
                }
                    break;
                case MENU_ID_IMGVIEW_VIEW_OPTION_SEND:
                case MENU_ID_IMGVIEW_VIEW_OPTION_USE:
                {
                    cui_iv_options_init(
                        menu_event->sender_id,
                        (WCHAR*) pcui->file_name,
                        menu_event->parent_menu_id == MENU_ID_IMGVIEW_VIEW_OPTION_SEND);
                }
                    break;
            }
        }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            switch (menu_event->highlighted_menu_id)
            {
                case MENU_ID_IMGVIEW_VIEW_OPTION_INFO:
                    mmi_imgview_show_img_info(pcui->cui_gid, (WCHAR*) pcui->file_name);
                    break;

            #ifdef __MMI_IVF_SLIDE__
                case MENU_ID_IMGVIEW_VIEW_OPTION_PLAY:
                {
                    mmi_frm_scrn_close_active_id();
                    /* Start play from menu, if entry scrn fail, should not start play */
                    if (NULL == cui_iv_get_context())
                    {
                        break;
                    }
                    cui_iv_slide_play(pcui);
                }
                    break;
            #endif /* __MMI_IVF_SLIDE__ */

            #ifndef __MMI_IVF_MOTION__
                case MENU_ID_IMGVIEW_VIEW_OPTION_ROTATE_VIEW:
                {
                    mmi_frm_scrn_close_active_id();
                    /* Rotate view from menu, if entry scrn fail, should not rotate view */
                    if (NULL == cui_iv_get_context())
                    {
                        break;
                    }
                    cui_iv_rotate_view(pcui);
                }
                    break;
            #endif /* __MMI_IVF_MOTION__ */

            #ifdef __MMI_RMGR__
                case MENU_ID_FMGR_GEN_OPTION_MORE_RITS:
                {
                    S32 ret;

                    ret = srv_fmgr_types_launch_option((WCHAR*) pcui->file_name, menu_event->highlighted_menu_id);
                    if (ret <= 0)
                    {
                        cui_iv_popup_error_sg(
                            pcui->cui_gid,
                            (UI_string_type) GetString(srv_fmgr_fs_error_get_string(ret)),
                            (mmi_event_notify_enum) srv_fmgr_fs_error_get_popup_type(ret),
                            pcui->disp_cap & CUI_IMGVIEW_DISP_ROT,
                            NULL);
                    }
                }
                    break;
            #endif /* __MMI_RMGR__ */
                default:
                {
                    switch (menu_event->parent_menu_id)
                    {
                        case MENU_ID_IMGVIEW_VIEW_OPTION_USE:
                        case MENU_ID_IMGVIEW_VIEW_OPTION_SEND:
                            srv_fmgr_types_launch_option((WCHAR*) pcui->file_name, menu_event->highlighted_menu_id);
                            break;

                    }
                }
                    break;
            }
        }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_event->sender_id);
        }
            break;
    }

    return MMI_RET_OK;
}

#endif /* __MMI_IVF_OPTION__ */

#ifdef __MMI_IVF_TOUCH_SCREEN__

#define MMI_IV_CLICK_INTERVAL   50
#define MMI_IV_DCLICK_INTERVAL  200
#define MMI_IV_MOVE_STEP        4


/*****************************************************************************
 * FUNCTION
 *  cui_iv_on_click
 * DESCRIPTION
 *
 * PARAMETERS
 *  pscrn_data      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_on_click(cui_iv_scrndata *pscrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_CLICK);

    if (IV_IS_OSD_HIDE(pscrn_data) || IV_IS_OSD_SHOW(pscrn_data))       /* not in fading */
        CUI_IV_SHOW_OSD(pscrn_data, IV_IS_OSD_HIDE(pscrn_data));
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_on_dclick
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_on_dclick(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_DCLICK);

    CUI_IV_ZOOM_FAST(pcui);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_on_move
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  offx        [IN]
 *  offy        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_on_move(cui_iv_cntx *pcui, S32 offx, S32 offy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 switchRet;
    S32 offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_MOVE);

    CUI_IV_SHOW_OSD(&pcui->scrn_data, 0);

    if ((pcui->disp_cap & CUI_IMGVIEW_DISP_ROT) == CUI_IMGVIEW_DISP_ROT)
        offset = offy;
    else
        offset = offx;

    if (abs(offset) >= MMI_IV_MOVE_STEP && ((2 * abs(offset)) - abs(offx) - abs(offy)) >= 0)
    {
        switchRet = CUI_IV_SWITCH_GET_SWITCH_DIRECTION(pcui, offset);

        /* check if need switch */
        if (0 != switchRet)
        {
            CUI_IV_PAUSE_IMG_OPS(pcui);
            CUI_IV_SE_INIT_DATA_EASE(
                pcui,
                (pcui->index + pcui->count + switchRet) % pcui->count,
                switchRet == 1 ? 1 : 0,
                pcui->scrn_data.h_disp_layer,
                pcui->scrn_data.h_cache_layer);
        }
    }

    CUI_IV_PAN(pcui, offx, offy);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_on_move_end
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  off_x       [IN]        Offset from key down
 *  off_y       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_on_move_end(cui_iv_cntx *pcui, S32 off_x, S32 off_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_IVF_DRAG_SWITCH__)
    S32 offset;
    S32 is_next = 0;
#endif /* !defined(__MMI_IVF_DRAG_SWITCH__) */
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_MOVE_END, pscrn_data->flag);

    /* convert according to UI rotate */

#if !defined(__MMI_IVF_DRAG_SWITCH__)
    if ((pcui->disp_cap & CUI_IMGVIEW_DISP_ROT) == CUI_IMGVIEW_DISP_ROT)
    {
        offset = off_y;
    }
    else
    {
        offset = off_x;
    }

    /* check if need switch */
    if (abs(offset) >= MMI_IV_MOVE_STEP && ((2 * abs(offset)) - abs(off_x) - abs(off_y)) >= 0)
    {
        if (offset > 0 && !(pscrn_data->flag & IV_FLAG_NOT_SWITCH_PREV))
        {
            is_next = 0;
        }
        else if (offset < 0 && !(pscrn_data->flag & IV_FLAG_NOT_SWITCH_NEXT))
        {
            is_next = 1;
        }
        else
        {
            return;
        }

        cui_iv_start_switch(pcui, is_next);
    }
#endif /* !defined(__MMI_IVF_DRAG_SWITCH__) */
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_pen_wait_double
 * DESCRIPTION
 *
 * PARAMETERS
 *  pdata       [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_pen_wait_double(void *pdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = (cui_iv_scrndata*) pdata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pscrn_data->pen_stat = IV_PEN_STAT_INIT;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_WAIT_DOUBLE_TIMEOUT);

    /* emit click */
    cui_iv_on_click(pscrn_data);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_still_pen_down
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  touchData       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_still_pen_down(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_MEDIA_TRC_G2_APP,
        MMI_TRC_IVAPP_STILL_PEN_DOWN,
        touchData->currpos.pos.x,
        touchData->currpos.pos.y,
        pscrn_data->flag);

    CUI_IV_STOP_ZOOM(pcui);

    if (!IV_IS_OSD_HIDE(pscrn_data))
    {
        if (mmi_mapp_frame_pendown(pscrn_data->pframe, touchData->currpos.pos) == MMI_TRUE)
        {
            if (cui_iv_input_available(pcui) == MMI_TRUE)
            {
                CUI_IV_OSD_STOP_WATCHDOG(&pcui->scrn_data);
            }
            return;
        }
    }

    /* On Image */
    if (pscrn_data->pen_stat == IV_PEN_STAT_INIT)
    {
        pscrn_data->pen_stat = IV_PEN_STAT_DOWN1;
    }
    else if (pscrn_data->pen_stat == IV_PEN_STAT_WAIT_DOUBLE)
    {
        gui_cancel_timer((FuncPtr) cui_iv_pen_wait_double);
        pscrn_data->pen_stat = IV_PEN_STAT_DOWN2;
    }
    else
    {
        MMI_ASSERT(0);
    }

    /* record image can switch direction */
    CUI_IV_ZOOM_GET_SWITCH_FLAG(pcui);

}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_still_pen_up
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  touchData       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_still_pen_up(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_MEDIA_TRC_G2_APP,
        MMI_TRC_IVAPP_STILL_PEN_UP,
        touchData->currpos.pos.x,
        touchData->currpos.pos.y,
        pscrn_data->flag);

    if (!IV_IS_OSD_HIDE(pscrn_data))
    {
        if (mmi_mapp_frame_penup(pscrn_data->pframe) == MMI_TRUE)
        {
            if (cui_iv_input_available(pcui) == MMI_TRUE)
            {
                CUI_IV_OSD_START_WATCHDOG(&pcui->scrn_data);
            }
            return;
        }
    }

    switch (pscrn_data->pen_stat)
    {
        case IV_PEN_STAT_DOWN1:
            if (touchData->currpos.timestamp - touchData->down_pos.timestamp < MMI_IV_CLICK_INTERVAL)
            {
                pscrn_data->pen_stat = IV_PEN_STAT_WAIT_DOUBLE;
                gui_start_timer_ex(MMI_IV_DCLICK_INTERVAL, cui_iv_pen_wait_double, pscrn_data);
            }
            else
            {
                pscrn_data->pen_stat = IV_PEN_STAT_INIT;
            }
            break;

        case IV_PEN_STAT_DOWN2:
            if (touchData->currpos.timestamp - touchData->down_pos.timestamp < MMI_IV_CLICK_INTERVAL)
            {
                /* emit double click */
                cui_iv_on_dclick(pcui);
            }
            pscrn_data->pen_stat = IV_PEN_STAT_INIT;
            break;

        case IV_PEN_STAT_MOVE:
            pscrn_data->pen_stat = IV_PEN_STAT_INIT;

            /* emit move end */
            cui_iv_on_move_end(
                pcui,
                touchData->currpos.pos.x - touchData->down_pos.pos.x,
                touchData->currpos.pos.y - touchData->down_pos.pos.y);
            break;

        default:
            break;
    };
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_still_pen_move
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  touchData       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_still_pen_move(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;
    S32 offx, offy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_MEDIA_TRC_G2_APP,
        MMI_TRC_IVAPP_STILL_PEN_MOVE,
        touchData->currpos.pos.x,
        touchData->currpos.pos.y,
        pscrn_data->flag);

    if (!IV_IS_OSD_HIDE(pscrn_data))
    {
        if (mmi_mapp_frame_penmove(pscrn_data->pframe, touchData->currpos.pos) == MMI_TRUE)
            return;
    }

    offx = touchData->currpos.pos.x - touchData->pre_pos.pos.x;
    offy = touchData->currpos.pos.y - touchData->pre_pos.pos.y;
    if (abs(offx) < MMI_IV_MOVE_STEP && abs(offy) < MMI_IV_MOVE_STEP)
    {
        return;
    }

    pscrn_data->pen_stat = IV_PEN_STAT_MOVE;

    /* emit move */
    cui_iv_on_move(pcui, offx, offy);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_still_pen_abort
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  touchData       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_still_pen_abort(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_abort_type_enum abort_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_STILL_PEN_ABORT);

    abort_type = mmi_pen_get_pen_abort_type();
    if (!IV_IS_OSD_HIDE(&pcui->scrn_data))
    {
        if (mmi_mapp_frame_penabort(pcui->scrn_data.pframe, abort_type) == MMI_TRUE)
            return;
    }

    /* get pen abort type, will do pen up action if pen up lost because queue full, or do nothing */
    if (abort_type == MMI_PEN_ABORT_TYPE_DRVQ_FULL)
    {
        cui_iv_still_pen_up(pcui, touchData);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_pen_proc
 * DESCRIPTION
 *  pen proc
 * PARAMETERS
 *  evt     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_iv_pen_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EVT_ID_ON_TOUCH == evt->evt_id)
    {
        mmi_multi_touch_event_struct *penEvt = (mmi_multi_touch_event_struct*) evt;
        mmi_touch_data_struct *touchData = penEvt->touch_data;
        cui_iv_cntx *pcui = (cui_iv_cntx*) evt->user_data;

        switch (touchData->event)
        {
            case MMI_PEN_EVENT_DOWN:
                if (cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].pen_down_hdlr)
                {
                    cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].pen_down_hdlr(pcui, touchData);
                }
                break;

            case MMI_PEN_EVENT_MOVE:
                if (cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].pen_move_hdlr)
                {
                    cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].pen_move_hdlr(pcui, touchData);
                }
                break;

            case MMI_PEN_EVENT_UP:
                if (cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].pen_up_hdlr)
                {
                    cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].pen_up_hdlr(pcui, touchData);
                }
                break;

            case MMI_PEN_EVENT_ABORT:
                if (cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].pen_abort_hdlr)
                {
                    cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].pen_abort_hdlr(pcui, touchData);
                }
                break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_init_pen_handler
 * DESCRIPTION
 *  init key handler
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_init_pen_handler(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_PEN);

    /* config high precise */
    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_2, MMI_PEN_SAMPLING_PERIOD_2);

    mmi_frm_touch_register_proc(cui_iv_pen_proc, (void*)pcui);
}

#endif /* __MMI_IVF_TOUCH_SCREEN__ */

#ifdef __MMI_IVF_OSD__


/*****************************************************************************
 * FUNCTION
 *  cui_iv_osd_show
 * DESCRIPTION
 *
 * PARAMETERS
 *  pscrn_data      [?]
 *  is_show         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_osd_show(cui_iv_scrndata *pscrn_data, S32 is_show)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_OSD_SHOW, is_show);
#ifdef __MMI_IVF_OSD_FADE__
    if (is_show)
    {
        mmi_mapp_frame_start_fade_in(pscrn_data->pframe);
    }
    else
    {
        mmi_mapp_frame_start_fade_out(pscrn_data->pframe);
    }
#else /* __MMI_IVF_OSD_FADE__ */
    mmi_mapp_frame_show(pscrn_data->pframe, is_show ? MMI_TRUE : MMI_FALSE);
    cui_iv_update_screen(GET_CUI_FROM_SCRNDATA(pscrn_data), CUI_IV_UPDATE_OSD);
#endif /* __MMI_IVF_OSD_FADE__ */

}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_get_osd_layers
 * DESCRIPTION
 *
 * PARAMETERS
 *  pscrn_data      [IN]
 *  ph_panel        [?]
 *  ph_title        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_get_osd_layers(const cui_iv_scrndata *pscrn_data, gdi_handle *ph_panel, gdi_handle *ph_title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle layers[2];
    mapp_frame_t *pframe = pscrn_data->pframe;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mapp_frame_get_display_layers(pframe, layers, 2);
    *ph_panel = layers[0];
    *ph_title = layers[1];

    if (IV_IS_OSD_HIDE(pscrn_data))
        return;

#ifdef __MMI_IVF_OSD_PANEL__
    {
        S32 i;
        struct
        {
            U32 id;
            U32 enable;
        } en_map[4] =
        {
            {
            CUI_IV_KEY_ZOOMIN, 0},
            {
            CUI_IV_KEY_ZOOMOUT, 0},
            {
            CUI_IV_KEY_CWR, 0},
            {
        CUI_IV_KEY_CCWR, 0},};
        /* update panel items state */
        if (pscrn_data->cur_img_info.stat == IV_IMG_STAT_OK)
        {
            cui_iv_cntx *pcui = GET_CUI_FROM_SCRNDATA(pscrn_data);
            cui_iv_img_extinfo  *pinfo = &pcui->scrn_data.cur_img_info;

            en_map[2].enable = 1;
            en_map[3].enable = 1;

            if (!pinfo->is_anim)    /* Current image is not animation */
            {
                cui_iv_img_baseinfo *pbaseinfo = &pcui->img_base_info;

                if (pscrn_data->cur_img_info.max_zoom_factor > 10)
                {
                    if (pbaseinfo->zoom_factor < pscrn_data->cur_img_info.max_zoom_factor)
                    {
                        en_map[0].enable = 1;
                    }
                    if (pbaseinfo->zoom_factor > 10)
                    {
                        en_map[1].enable = 1;
                    }
                }
            }
        }

        for (i = 0; i < 4; i++)
        {
            if (en_map[i].enable)
            {
                mmi_mapp_frame_enable_item(pframe, en_map[i].id);
            }
            else
            {
                mmi_mapp_frame_disable_item(pframe, en_map[i].id);
            }

        }
    }
    mmi_med_panel_redraw((med_panel_handle) pframe->panel_array[1].p_panel, MMI_TRUE);
#endif /* __MMI_IVF_OSD_PANEL__ */

}

#ifdef __MMI_IVF_TOUCH_SCREEN__
typedef struct {
    MMI_EVT_PARAM_HEADER
    void (*process_func) (cui_iv_cntx * pcui, U16 key_code);
} cui_iv_evt_panel_struct; 


static mmi_ret cui_iv_panel_signal_hdlr(mmi_event_struct *evt)
{
    cui_iv_evt_panel_struct *pevt = (cui_iv_evt_panel_struct*)evt;

    pevt->process_func((cui_iv_cntx *)pevt->user_data, pevt->evt_id);

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_iv_panel_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  id              [IN]
 *  event           [IN]
 *  pcui            [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_panel_cb(U32 id, med_panel_evt_t event, cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    void (*process_func) (cui_iv_cntx * pcui, U16 key_code) = NULL;

    if (event == MED_EVT_BTN_DOWN)
    {
        process_func = cui_iv_still_key_down;
    }
    else if (event == MED_EVT_BTN_UP)
    {
        process_func = cui_iv_still_key_up;
    }
    else if (event == MED_EVT_BTN_CANCEL)
    {   /* for do things on down icon need to response cancel */
    #ifdef __MMI_IVF_OSD_PANEL__
        if (id == CUI_IV_KEY_ZOOMIN || id == CUI_IV_KEY_ZOOMIN)
        {
            process_func = cui_iv_still_key_up;
        }
    #endif /* __MMI_IVF_OSD_PANEL__ */
    }
    else
    {
        return;
    }

    cui_iv_update_screen(pcui, CUI_IV_UPDATE_PANEL);
    if (process_func)
    {
        /* use post in place of call directly for panel use screen based memory, 
         * and these memory maybe modified by med panel after callback. If screen exit in process_func 
         * we may crash the screen memory.
         */
        cui_iv_evt_panel_struct evt;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_OSD_EVENT, event, id);
        MMI_FRM_INIT_EVENT(&evt, (U16)id);
        evt.size = sizeof(evt);
        evt.process_func = process_func;
        mmi_frm_post_event((mmi_event_struct*)(&evt), cui_iv_panel_signal_hdlr, pcui);
    }
}
#endif /* __MMI_IVF_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  cui_iv_osd_key_down
 * DESCRIPTION
 *
 * PARAMETERS
 *  pscrn_data      [?]
 *  key_code        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_osd_key_down(cui_iv_scrndata *pscrn_data, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui = GET_CUI_FROM_SCRNDATA(pscrn_data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mapp_frame_press_item(pscrn_data->pframe, key_code);
    cui_iv_update_screen(pcui, CUI_IV_UPDATE_PANEL);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_osd_key_up
 * DESCRIPTION
 *
 * PARAMETERS
 *  pscrn_data      [?]
 *  key_code        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_osd_key_up(cui_iv_scrndata *pscrn_data, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui = GET_CUI_FROM_SCRNDATA(pscrn_data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mapp_frame_up_item(pscrn_data->pframe, key_code);
    cui_iv_update_screen(pcui, CUI_IV_UPDATE_PANEL);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_update_title
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_update_title(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR buf[30];
    const WCHAR *ptitle[IV_MAX_TITLE_LINE + 1];
    S32 w, h, off_x, off_y = 0, i = 0;
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;
    S32 title_w = pscrn_data->title_w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define IV_TITLE_COLOR          (*(current_MMI_theme->title_text_color))
#define IV_TITLE_BORDER_COLOR   (*(current_MMI_theme->title_text_border_color))

    memset((void*)(&ptitle), 0, sizeof(ptitle));
    if (pcui->ptitle)
    {
        ptitle[0] = pcui->ptitle;
    }
    else
    {
        ptitle[0] = buf;
        kal_wsprintf(buf, "< %d/%d >", pcui->index + 1, pcui->count);
    }

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_FALSE);
#endif

    gui_set_font((UI_font_type) gui_font_get_type(GUI_FONT_SIZE_TITLE));

    gdi_layer_push_and_set_active(pcui->scrn_data.h_title_layer);

    gdi_layer_reset_clip();
    gdi_draw_solid_rect(IV_TITLE_X, IV_TITLE_Y, IV_TITLE_X + title_w - 1, IV_TITLE_Y + IV_TITLE_H - 1, GDI_COLOR_TRANSPARENT);
    gui_set_text_color(IV_TITLE_COLOR);
    gui_set_text_border_color(IV_TITLE_BORDER_COLOR);

    while (ptitle[i])
    {
        gui_measure_string((UI_string_type) ptitle[i], &w, &h);
        off_y +=
            (IV_TITLE_H - h) <
            (IV_MAX_TITLE_LINE + 1) * IV_TITLE_MIN_MARGIN ? (IV_TITLE_H - h) / (IV_MAX_TITLE_LINE +
                                                                                1) : IV_TITLE_MIN_MARGIN;
        off_x = IV_TITLE_MIN_MARGIN + (w > title_w ? 0 : (title_w - w) / 2);

        gui_move_text_cursor(off_x, off_y);
        gui_print_truncated_borderd_text(off_x, off_y, title_w, (UI_string_type) ptitle[i]);
        off_y += h;
        i++;
    }

    gdi_layer_pop_and_restore_active();

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_TRUE);
#endif
}

#ifdef __MMI_IVF_OSD_SK_TEXT__


/*****************************************************************************
 * FUNCTION
 *  cui_iv_sk_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  pitems              [?]
 *  id                  [IN]
 *  scrn_rotate         [IN]
 *  str_id              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_sk_init(
                med_panel_item_t *pitems,
                WGUI_SOFTKEY_ENUM id,
                mmi_frm_screen_rotate_enum scrn_rotate,
                U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_med_panel_init_txtbtn(pitems);
    pitems->data.txtbtn.ptxt = (CHAR*) GetString(str_id);

    gui_set_font((UI_font_type) gui_font_get_type(GUI_FONT_SIZE_BUTTON));
    gui_measure_string((UI_string_type) pitems->data.txtbtn.ptxt, &pitems->w, &pitems->h);
    wgui_softkey_get_offset((UI_string_type) pitems->data.txtbtn.ptxt, &pitems->x, &pitems->y, &w, id, scrn_rotate);

    if (scrn_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        pitems->w += 4;
    }

    /* check r2lMMIFlag flag to correct offset_x of string, due to we will do the change in
       mmi_camera_draw_style_text() */
    if (mmi_fe_get_r2l_state())
    {
        pitems->x -= pitems->w;
    }

}
#endif /* __MMI_IVF_OSD_SK_TEXT__ */


/*****************************************************************************
 * FUNCTION
 *  cui_iv_alloc_scrn_mem
 * DESCRIPTION
 *
 * PARAMETERS
 *  pscrn_data      [?]
 *  size            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void *cui_iv_alloc_scrn_mem(cui_iv_scrndata *pscrn_data, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *pmem = pscrn_data->p_scrn_mem + pscrn_data->alloc_scrn_mem_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = (size + 3) & (~0x3);
    pscrn_data->alloc_scrn_mem_size += size;

    return pmem;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_osd_create_layers
 * DESCRIPTION
 *
 * PARAMETERS
 *  pscrn_data      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_osd_create_layers(cui_iv_scrndata *pscrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 pbuf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create panel layer */
    pbuf = (PU8) cui_iv_alloc_scrn_mem(pscrn_data, IV_OSD_PANEL_SIZE);
    /* init panel layers */
    gdi_layer_create_cf_using_outside_memory(
        IV_OSD_LAYER_CF,
        0,
        0,
        IV_PANEL_W,
        IV_PANEL_H,
        &pscrn_data->h_panel_layer,
        (PU8) pbuf,
        IV_OSD_PANEL_SIZE);

    gdi_layer_set_source_key_nb_concurrent(pscrn_data->h_panel_layer, TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_nb_concurrent(pscrn_data->h_panel_layer, GDI_COLOR_TRANSPARENT);

    /* Create title layer */
    pbuf = (PU8) cui_iv_alloc_scrn_mem(pscrn_data, IV_OSD_TITLE_SIZE);
    gdi_layer_create_cf_using_outside_memory(
        IV_OSD_LAYER_CF,
        0,
        0,
        IV_TITLE_W,
        IV_TITLE_H,
        &pscrn_data->h_title_layer,
        (PU8) pbuf,
        IV_OSD_TITLE_SIZE);
    gdi_layer_clear_nb_concurrent(pscrn_data->h_title_layer, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key_nb_concurrent(pscrn_data->h_title_layer, TRUE, GDI_COLOR_TRANSPARENT);

}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_screen_to_layer
 * DESCRIPTION
 *
 * PARAMETERS
 *  pitems      [?]
 *  count       [IN]
 *  h_layer     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_screen_to_layer(med_panel_item_t *pitems, S32 count, gdi_handle h_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, offx, offy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(h_layer);
    gdi_layer_get_position(&offx, &offy);
    gdi_layer_pop_and_restore_active();

    for (i = 0; i < count; i++)
    {
        pitems[i].y -= offy;
        pitems[i].x -= offx;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_create_panel
 * DESCRIPTION
 *
 * PARAMETERS
 *  p_frame_panel       [?]
 *  h_layer             [IN]
 *  pitems              [?]
 *  count               [IN]
 *  fade_dir            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_create_panel(
                mapp_frame_panel_t *p_frame_panel,
                gdi_handle h_layer,
                med_panel_item_t *pitems,
                S32 count,
                mapp_fade_direct fade_dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    med_panel_handle h_panel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(h_layer);
    gdi_layer_get_position(&x, &y);
    gdi_layer_get_dimension(&w, &h);
    gdi_layer_pop_and_restore_active();

    p_frame_panel->fade_length = h;
    p_frame_panel->fade_dir = fade_dir;
    h_panel = mmi_med_create_panel(p_frame_panel->p_panel, h_layer, x, y, w, h, pitems, count);

    mmi_med_panel_init_color_bg(h_panel, GDI_COLOR_TRANSPARENT);
    mmi_med_panel_redraw(h_panel, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_osd_create_frame
 * DESCRIPTION
 *
 * PARAMETERS
 *  pscrn_data      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_osd_create_frame(cui_iv_scrndata *pscrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 panel_item = 2, i;
    mapp_frame_panel_t *panel_array;
    med_panel_t *med_panels;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pscrn_data->pframe = (mapp_frame_t*) cui_iv_alloc_scrn_mem(pscrn_data, sizeof(mapp_frame_t));
    panel_array = (mapp_frame_panel_t*) cui_iv_alloc_scrn_mem(pscrn_data, panel_item * sizeof(mapp_frame_panel_t));
    med_panels = (med_panel_t*) cui_iv_alloc_scrn_mem(pscrn_data, panel_item * sizeof(med_panel_t));

    for (i = 0; i < panel_item; i++)
    {
        panel_array[i].p_panel = &med_panels[i];
    }

    pscrn_data->pframe->panel_array = panel_array;
    pscrn_data->pframe->panel_count = panel_item;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_osd_frame_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt_type        [IN]
 *  evt_data        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_osd_frame_cb(mapp_frame_evt_type_t evt_type, void *evt_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt_type == FRAME_EVT_TYPE_FRM)
    {
        mapp_frame_evt_data_t *p_frm_data = (mapp_frame_evt_data_t*) evt_data;

        cui_iv_update_screen((cui_iv_cntx*) (p_frm_data->usrdata), CUI_IV_UPDATE_OSD);
    }
#ifdef __MMI_IVF_TOUCH_SCREEN__
    else
    {
        mapp_panel_evt_data_t *p_panel_data = (mapp_panel_evt_data_t*) evt_data;

        cui_iv_panel_cb(p_panel_data->id, p_panel_data->evt, (cui_iv_cntx*) (p_panel_data->usrdata));
    }
#endif /* __MMI_IVF_TOUCH_SCREEN__ */
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_osd_reset_frame
 * DESCRIPTION
 *
 * PARAMETERS
 *  pscrn_data      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_osd_reset_frame(cui_iv_scrndata *pscrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui = GET_CUI_FROM_SCRNDATA(pscrn_data);
    S32 scrn_h, scrn_w, panel_h;
    U8 rot;
    const iv_panel_t *p_act_panel;
    med_panel_item_t *pitems, *p_title_items = NULL, *p_panel_items = NULL;
    S32 p_title_items_count, p_panel_items_count;
    S32 show_panel = 1, panel_count = 2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT)
    {
        scrn_h = LCD_WIDTH;
        scrn_w = LCD_HEIGHT;
        rot = GDI_LAYER_ROTATE_90;
        panel_h = IV_PANEL_ICON_BAR_H;
        p_act_panel = &iv_panel_270;
    #if !defined(__MMI_IVF_OSD_PANEL__)
        show_panel = 0;
        panel_count = 1;
    #endif /* !defined(__MMI_IVF_OSD_PANEL__) */
    }
    else
    {
        scrn_h = LCD_HEIGHT;
        scrn_w = LCD_WIDTH;
        rot = GDI_LAYER_ROTATE_0;
        panel_h = IV_PANEL_H;
        p_act_panel = &iv_panel_0;
    }

    /* reset layer */
    gdi_layer_set_rotate_nb_concurrent(pscrn_data->h_title_layer, rot);
    gdi_layer_set_position_nb_concurrent(pscrn_data->h_title_layer, 0, 0);
    gdi_layer_resize_nb_concurrent(pscrn_data->h_title_layer, scrn_w, IV_TITLE_H);
    gdi_layer_clear_nb_concurrent(pscrn_data->h_title_layer, GDI_COLOR_TRANSPARENT);

    if (show_panel)
    {
        U16 margin = (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT) ? IV_PANEL_ICON_BAR_BOTTOM_MARGIN : 0;
        gdi_layer_set_rotate_nb_concurrent(pscrn_data->h_panel_layer, rot);
        gdi_layer_set_position_nb_concurrent(pscrn_data->h_panel_layer, 0, scrn_h - panel_h - margin);
        gdi_layer_resize_nb_concurrent(pscrn_data->h_panel_layer, scrn_w, panel_h);
        gdi_layer_clear_nb_concurrent(pscrn_data->h_panel_layer, GDI_COLOR_TRANSPARENT);
    }

    if (!pscrn_data->p_items)
    {
        pscrn_data->p_items =
            (med_panel_item_t*) cui_iv_alloc_scrn_mem(pscrn_data, IV_ICON_COUNT * sizeof(med_panel_item_t));
    }

    /* init icon items */
    pitems = pscrn_data->p_items;

#ifdef __MMI_IVF_OSD_PANEL__
    {
        S32 i;

        for (i = 0; i < IV_ICON_COUNT; i++)
        {
            mmi_med_panel_init_btn4(pitems);
            pitems->x = p_act_panel->picons[i].x;
            pitems->y = p_act_panel->picons[i].y;
            pitems->id = p_act_panel->picons[i].id;
            pitems->data.btn4.icon = (MMI_IMG_ID) (IMG_ID_IV_BTN_ZOOMIN + i);
            pitems->data.btn4.icon_bg = IMG_ID_IV_BTN_BG;
            pitems->data.btn4.icon_hl_mask = IMG_ID_IV_BTN_HL_MASK;
            pitems->data.btn4.icon_dis_mask = IMG_ID_IV_BTN_DIS_MASK;
#ifndef __MMI_FTE_SUPPORT__
            gdi_image_get_dimension_id(IMG_ID_IV_BTN_BG, &(pitems->w), &(pitems->h));
#else
            pitems->w = p_act_panel->picons[i].w;
            pitems->h = p_act_panel->picons[i].h;
#endif
            pitems++;
        }
        pitems -= 2;    /* point to softkey */
    }
#elif (!defined (__MMI_IVF_OSD_SK_TEXT__))
    {
        S32 i;

        for (i = 0; i < IV_ICON_COUNT; i++)
        {
            mmi_med_panel_init_btn4(pitems);
            pitems->x = p_act_panel->picons[i].x;
            pitems->y = p_act_panel->picons[i].y;
            pitems->id = p_act_panel->picons[i].id;
            pitems->data.btn4.icon = (MMI_IMG_ID) (IMG_ID_IV_BTN_LSK + i);
            pitems->data.btn4.icon_bg = IMG_ID_IV_BTN_BG;
            pitems->data.btn4.icon_hl_mask = IMG_ID_IV_BTN_HL_MASK;
            pitems->data.btn4.icon_dis_mask = IMG_ID_IV_BTN_DIS_MASK;
#ifndef __MMI_FTE_SUPPORT__
            gdi_image_get_dimension_id(IMG_ID_IV_BTN_BG, &(pitems->w), &(pitems->h));
#else
            pitems->w = p_act_panel->picons[i].w;
            pitems->h = p_act_panel->picons[i].h;
#endif
            pitems++;
        }
    }
#endif

    /* init softkey */
#ifdef __MMI_IVF_OSD_SK_TEXT__
    {
        cui_iv_cntx *pcui = GET_CUI_FROM_SCRNDATA(pscrn_data);
        U16 str_id;
        mmi_frm_screen_rotate_enum rot =
            p_act_panel == &iv_panel_0 ? MMI_FRM_SCREEN_ROTATE_0 : MMI_FRM_SCREEN_ROTATE_270;

        /* init LSK */
        if (pcui->disp_cap & CUI_IMGVIEW_DISP_LSK_DEF)
        {

        #ifdef __MMI_IVF_OPTION__
            str_id = STR_GLOBAL_OPTIONS;
        #else
            str_id = STR_ID_IMGVIEW_ROTATE;
        #endif
        }
        else
        {
            str_id = STR_GLOBAL_OK;
        }

        cui_iv_sk_init(pitems, MMI_LEFT_SOFTKEY, rot, str_id);
        pitems->id = KEY_LSK;

        /* init RSK */
        /* init softkey item */
        pitems++;
        cui_iv_sk_init(pitems, MMI_RIGHT_SOFTKEY, rot, STR_GLOBAL_BACK);
        pitems->id = KEY_RSK;
    }
#endif /* __MMI_IVF_OSD_SK_TEXT__ */

    p_panel_items = pscrn_data->p_items;

    if (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT)
    {
        p_title_items = pitems;
        p_title_items_count = 1;
        p_panel_items_count = IV_ICON_COUNT - 2;
        pscrn_data->title_w = pitems->x - (IV_TITLE_MIN_MARGIN * 2);
    }
    else
    {
        p_title_items_count = 0;
        p_panel_items_count = IV_ICON_COUNT;
        pscrn_data->title_w = scrn_w - (IV_TITLE_MIN_MARGIN * 2);
    }

    /* convert position from screen to layer. */
    cui_iv_screen_to_layer(p_panel_items, p_panel_items_count, pscrn_data->h_panel_layer);
    cui_iv_screen_to_layer(p_title_items, p_title_items_count, pscrn_data->h_title_layer);

    /* init and create frame */
    cui_iv_create_panel(
        &pscrn_data->pframe->panel_array[0],
        pscrn_data->h_title_layer,
        p_title_items,
        p_title_items_count,
        FADE_DIR_UP);
    cui_iv_create_panel(
        &pscrn_data->pframe->panel_array[1],
        pscrn_data->h_panel_layer,
        p_panel_items,
        p_panel_items_count,
        FADE_DIR_DOWN);

#ifdef __MMI_IVF_OSD_FADE__
    mmi_mapp_frame_create(
        pscrn_data->pframe,
        pscrn_data->pframe->panel_array,
        panel_count,
        MAPP_FRAME_FLAG_FADE_ENABLE);
#else /* __MMI_IVF_OSD_FADE__ */
    mmi_mapp_frame_create(pscrn_data->pframe, pscrn_data->pframe->panel_array, panel_count, 0);
#endif /* __MMI_IVF_OSD_FADE__ */

    mmi_mapp_frame_set_cb(pscrn_data->pframe, cui_iv_osd_frame_cb, pcui);

    cui_iv_update_title(pcui);                                                                                                                        
    mmi_mapp_frame_show(pscrn_data->pframe, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_init_osd
 * DESCRIPTION
 *
 * PARAMETERS
 *  pscrn_data      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_init_osd(cui_iv_scrndata *pscrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_OSD_INIT);
    pscrn_data->p_scrn_mem = pscrn_data->scrMemPtr;

    MMI_ASSERT(pscrn_data->p_scrn_mem != NULL);

    /* Create layer, panel and frame */
    cui_iv_osd_create_layers(pscrn_data);
    cui_iv_osd_create_frame(pscrn_data);

    /* Reset frame */
    cui_iv_osd_reset_frame(pscrn_data);

    mmi_mapp_frame_start_watchdog(pscrn_data->pframe);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_deinit_osd
 * DESCRIPTION
 *
 * PARAMETERS
 *  pscrn_data      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_deinit_osd(cui_iv_scrndata *pscrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_OSD_DEINIT);

    mmi_mapp_frame_destory(pscrn_data->pframe);

    /* free layer */
    gdi_layer_free(pscrn_data->h_panel_layer);
    gdi_layer_free(pscrn_data->h_title_layer);

}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_osd_set_hide
 * DESCRIPTION
 *
 * PARAMETERS
 *  pscrn_data      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_osd_set_hide(cui_iv_scrndata *pscrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_OSD_SET_HIDE);
    mmi_mapp_frame_show(pscrn_data->pframe, MMI_FALSE);

}
#endif /* __MMI_IVF_OSD__ */

#ifdef __MMI_IVF_ZOOM__
static void cui_iv_get_img(cui_iv_cntx *pcui, cui_iv_resizer_mode resize_mode);
static void cui_iv_zoom_cyclic(void *pdata);
static S32 cui_iv_start_dec_cache(
            cui_iv_cntx *pcui,
            gdi_handle h_layer,
            cui_iv_img_extinfo *pinfo,
            const WCHAR *pfile, 
            MMI_BOOL from_zoom);
static void cui_iv_compute_zoom_data(cui_iv_cntx *pcui, S32 is_update_wnd_pos);

typedef void  (*large_cache_ok_callback)(cui_iv_cntx *); 
static large_cache_ok_callback    g_large_cache_ok_callback;


/* Alloc cache memory */


/*****************************************************************************
 * FUNCTION
 *  cui_iv_zoom_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_zoom_init(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_ZOOM_INIT);

    pscrn_data->p_large_cache_mem = pscrn_data->medMemPtr;

    gdi_layer_create_cf_using_outside_memory(
        IV_LAYER_CF,
        0,
        0,
        MMI_IVF_ZOOM_CACHE_W,
        MMI_IVF_ZOOM_CACHE_H,
        &pscrn_data->h_large_cache_layer,
        pscrn_data->p_large_cache_mem,
        IV_LARGE_CACHE_SIZE);

    gdi_layer_clear_nb_concurrent(pscrn_data->h_large_cache_layer, GDI_COLOR_BLACK);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_zoom_deinit
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_zoom_deinit(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_ZOOM_DEINIT);

    /* free layer */
    gdi_layer_free(pscrn_data->h_large_cache_layer);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_zoom_init_base_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  pinfo       [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_zoom_init_base_info(cui_iv_img_baseinfo *pinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pinfo->zoom_factor = 10;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_zoom_init_cache_layer
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_zoom_init_cache_layer(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 expectSize, actualSize;
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    expectSize = pinfo->org_w * pinfo->org_h;
    actualSize = MMI_IVF_ZOOM_CACHE_W * MMI_IVF_ZOOM_CACHE_H;

    if (actualSize < expectSize)
    {
        U32 ratio = (U32) sqrt((actualSize * 100.0 * 100.0) / expectSize);

        pscrn_data->cache_w = (S32) (ratio * pinfo->org_w / 100.0);
        pscrn_data->cache_h = (S32) (ratio * pinfo->org_h / 100.0);
    }
    else
    {
        pscrn_data->cache_w = pinfo->org_w;
        pscrn_data->cache_h = pinfo->org_h;
    }

    mmi_imgview_adjust_resize_size(pinfo->type, &(pscrn_data->cache_w), &(pscrn_data->cache_h));

    gdi_layer_resize_nb_concurrent(pscrn_data->h_large_cache_layer, pscrn_data->cache_w, pscrn_data->cache_h);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_zoom_init_img_extinfo
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_zoom_init_img_extinfo(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;
    S32 factor_h, factor_w;
    FS_HANDLE h_file;
    kal_uint32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* compute image size of of zoom */
    cui_iv_zoom_init_cache_layer(pcui);

    /* compute max size */
    pinfo->max_img_h = pcui->scrn_data.cache_h;
    pinfo->max_img_w = pcui->scrn_data.cache_w;

    pinfo->fit_h = pinfo->cur_h;
    pinfo->fit_w = pinfo->cur_w;
    pinfo->cur_img_h = pinfo->cur_h;
    pinfo->cur_img_w = pinfo->cur_w;

    /*
     * temp solution: init max zoom factor according to
     * the limitation, may be delete when the decode add limitation according to chip
     */
    h_file = FS_Open(pcui->file_name, FS_READ_ONLY);
    FS_GetFileSize(h_file, &size);
    FS_Close(h_file);
    if (size > 1024 * 1024)
    {
        pinfo->max_zoom_factor = 10;
    }
    else
    {
        factor_h = pinfo->max_img_h * 10 / pinfo->fit_h;
        factor_w = pinfo->max_img_w * 10 / pinfo->fit_w;
        pinfo->max_zoom_factor = factor_h < factor_w ? factor_h : factor_w;     /* max or min ??? */
    }

    cui_iv_compute_zoom_data(pcui, 0);

}

/*****************************************************************************
 * FUNCTION
 *  cui_iv_large_cache_ok_interrupt_cb
 * DESCRIPTION
 *  The complete operation of large cache decode done callback 
 *  when the large cache decoding is triggered by back to enlarged state 
 *  from interrupt in place of zoom operation.
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_large_cache_ok_interrupt_cb(cui_iv_cntx *pcui)
{
    cui_iv_get_img(pcui, IV_RESIZER_HIGH);
}

/*****************************************************************************
 * FUNCTION
 *  cui_iv_large_cache_ok_stoppedzoom_cb
 * DESCRIPTION
 *  The complete operation of large cache decode done callback 
 *  when the large cache decoding is triggered by zoom operation, 
 *  but the zoom operation has terminated at this point for zoom 
 *  key or button has been released.
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_large_cache_ok_stoppedzoom_cb(cui_iv_cntx *pcui)
{
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pscrn_data->flag |= IV_FLAG_ZOOMIN;
    pinfo->resizer_mode = IV_RESIZER_HIGH;
    cui_iv_zoom_cyclic(pcui);
    gui_cancel_timer((FuncPtr) cui_iv_zoom_cyclic);
    pscrn_data->flag &= (~IV_FLAG_ZOOMIN);

}

/*****************************************************************************
 * FUNCTION
 *  cui_iv_dec_cache_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 *  handle      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_dec_cache_cb(GDI_RESULT result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui;
    cui_iv_scrndata *pscrn_data;
    cui_iv_img_extinfo *pinfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_ZOOM_DEC_DONE, result);

    pcui = cui_iv_get_context();
    if (!pcui)
        return;

    pscrn_data = &pcui->scrn_data;
    pinfo = &pcui->scrn_data.cur_img_info;

    if (handle != pscrn_data->h_large_dec)
        return;

    if (result == GDI_SUCCEED)
    {
        /* start DRM comsume */

        /* chage image state */
        pinfo->stat = IV_IMG_STAT_OK;
        pscrn_data->cache_stat = IV_CACHE_OK;
        if(g_large_cache_ok_callback){
           g_large_cache_ok_callback(pcui); 
        }
    }
    else
    {
        /* chage image state */
        pinfo->stat = IV_IMG_STAT_ERR;
    }

    /* resume DRM consume */
    cui_iv_update_screen(pcui, CUI_IV_UPDATE_IMAGE_STATE | CUI_IV_UPDATE_NEW_IMAGE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_zoom_dec_img
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui                        [?]
 *  pfile                       [IN]
 *  pinfo                       [?]
 *  h_layer                     [IN]
 *  h_temp_layer                [IN]
 *  callback                    [IN]
 *  userData                    [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_zoom_dec_img(
                cui_iv_cntx *pcui,
                const WCHAR *pfile,
                cui_iv_img_extinfo *pinfo,
                gdi_handle h_layer,
                gdi_handle h_temp_layer,
                cui_iv_imgadp_callback callback,
                void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_ZOOM_DEC);

    if (pcui->img_base_info.zoom_factor > 10)
    {
        S32 cacheRet = cui_iv_start_dec_cache(pcui, pscrn_data->h_large_cache_layer, pinfo, pfile, MMI_FALSE);

        if (cacheRet == 1)
        {
            pinfo->stat = IV_IMG_STAT_DECODING;
        }
        else
        {
            /* Will not change current display */
        }
    }
    else
    {
        cui_iv_imgadp_draw(pcui, pfile, pinfo, h_layer, h_temp_layer, callback, userData);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_compute_zoom_data
 * DESCRIPTION
 *  compute other data from zoom factor
 * PARAMETERS
 *  pcui                    [?]
 *  is_update_wnd_pos       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_compute_zoom_data(cui_iv_cntx *pcui, S32 is_update_wnd_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;
    cui_iv_img_baseinfo *pbaseinfo = &pcui->img_base_info;
    S32 layer_w, layer_h, temp_img_h, temp_img_w, view_point_x, view_point_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_dimension_nb_concurrent(pscrn_data->h_disp_layer, &layer_w, &layer_h);

    /* compute current image size */
    temp_img_h = pinfo->cur_img_h;
    temp_img_w = pinfo->cur_img_w;
    pinfo->cur_img_h = pinfo->fit_h * pbaseinfo->zoom_factor / 10;
    pinfo->cur_img_w = pinfo->fit_w * pbaseinfo->zoom_factor / 10;

    view_point_x = (2 * pbaseinfo->wnd_x + pinfo->cur_w) >> 1;
    view_point_y = (2 * pbaseinfo->wnd_y + pinfo->cur_h) >> 1;

    view_point_x = view_point_x * pinfo->cur_img_w / temp_img_w;
    view_point_y = view_point_y * pinfo->cur_img_h / temp_img_h;

    temp_img_h = layer_h;
    temp_img_w = layer_w;
    /* compute wnd position */
    if (pinfo->cur_img_h < layer_h)
    {
        temp_img_h = pinfo->cur_img_h;
    }

    if (pinfo->cur_img_w < layer_w)
    {
        temp_img_w = pinfo->cur_img_w;
    }

    pinfo->cur_h = temp_img_h;
    pinfo->cur_w = temp_img_w;
    pinfo->draw_x = (layer_w - temp_img_w) >> 1;
    pinfo->draw_y = (layer_h - temp_img_h) >> 1;

    if (is_update_wnd_pos)
    {
        pbaseinfo->wnd_x = (view_point_x - (layer_w >> 1)) < 0 ? 0 : view_point_x - (layer_w >> 1);
        pbaseinfo->wnd_y = (view_point_y - (layer_h >> 1)) < 0 ? 0 : view_point_y - (layer_h >> 1);

        if (pbaseinfo->wnd_x > (pinfo->cur_img_w - pinfo->cur_w))
        {
            pbaseinfo->wnd_x = pinfo->cur_img_w - pinfo->cur_w;
        }

        if (pbaseinfo->wnd_y > (pinfo->cur_img_h - pinfo->cur_h))
        {
            pbaseinfo->wnd_y = pinfo->cur_img_h - pinfo->cur_h;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_get_img
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_get_img(cui_iv_cntx *pcui, cui_iv_resizer_mode resize_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;
    S32 cache_x1, cache_y1, cache_x2, cache_y2;
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_ZOOM_GET_IMG);

    /* compute cache position */
    cache_x1 = pcui->img_base_info.wnd_x * pscrn_data->cache_w / pinfo->cur_img_w;
    cache_x2 = (pcui->img_base_info.wnd_x + pinfo->cur_w) * pscrn_data->cache_w / pinfo->cur_img_w;
    cache_y1 = pcui->img_base_info.wnd_y * pscrn_data->cache_h / pinfo->cur_img_h;
    cache_y2 = (pcui->img_base_info.wnd_y + pinfo->cur_h) * pscrn_data->cache_h / pinfo->cur_img_h;

    if (cache_x1 < 0)
        cache_x1 = 0;
    if (cache_x2 > pscrn_data->cache_w)
        cache_x2 = pscrn_data->cache_w;

    if (cache_y1 < 0)
        cache_y1 = 0;
    if (cache_y2 > pscrn_data->cache_h)
        cache_y2 = pscrn_data->cache_h;

    gdi_layer_clear_nb_concurrent(pscrn_data->h_disp_layer, GDI_COLOR_BLACK);
    gdi_layer_push_and_set_active(pscrn_data->h_disp_layer);
    gdi_bitblt_resized_with_resizer(
        pscrn_data->h_large_cache_layer,
        cache_x1,
        cache_y1,
        cache_x2 - 1,
        cache_y2 - 1,
        pinfo->draw_x,
        pinfo->draw_y,
        pinfo->draw_x + pinfo->cur_w - 1,
        pinfo->draw_y + pinfo->cur_h - 1,
        resize_mode == IV_RESIZER_LOW ? GDI_RESIZER_SW_QUALITY_LOW: GDI_RESIZER_SW_QUALITY_HIGH);
    gdi_layer_pop_and_restore_active();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_ZOOM_GET_IMG);

}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_start_dec_cache
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  h_layer     [IN]
 *  pinfo       [?]
 *  pfile       [?]
 * RETURNS
 *
 *****************************************************************************/
static S32 cui_iv_start_dec_cache(
            cui_iv_cntx *pcui,
            gdi_handle h_layer,
            cui_iv_img_extinfo *pinfo,
            const WCHAR *pfile, 
            MMI_BOOL from_zoom)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pcui->scrn_data.cache_index != pcui->index ||
        (pcui->scrn_data.cache_index == pcui->index && pcui->scrn_data.cache_stat != IV_CACHE_OK))
    {
        /* back from interrupt when enlarged */
        if (cui_iv_init_img_scrn_info(pinfo, pcui->file_name, pcui->img_base_info.img_orient) == MMI_FALSE)
            return -1;  /* error */

        pcui->scrn_data.cache_index = pcui->index;
        cui_iv_zoom_init_img_extinfo(pcui);

        /* Update decode completed callback */
        if(from_zoom == MMI_TRUE){
            g_large_cache_ok_callback = (large_cache_ok_callback)(cui_iv_zoom_cyclic);
        }else{
            g_large_cache_ok_callback = cui_iv_large_cache_ok_interrupt_cb;
        }
        
        gdi_layer_clear_nb_concurrent(h_layer, GDI_COLOR_BLACK);
        gdi_layer_push_and_set_active(h_layer);
        /* clear gdi working buffer */
        gdi_image_clear_work_buffer();
        gdi_nb_set_done_callback(cui_iv_dec_cache_cb);
        gdi_nb_set_blt(MMI_FALSE, MMI_FALSE);

        pcui->scrn_data.h_large_dec = gdi_image_nb_draw_resized_file(0, 0, pcui->scrn_data.cache_w, pcui->scrn_data.cache_h, pfile);
        gdi_layer_pop_and_restore_active();
        pcui->scrn_data.cache_stat = IV_CACHE_DECODING;
        return 1;       /* decoding */
    }
    return 0;           /* cache is ok */
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_zoom_cyclic
 * DESCRIPTION
 *
 * PARAMETERS
 *  pdata       [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_zoom_cyclic(void *pdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui = (cui_iv_cntx*) pdata;
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;
    cui_iv_img_baseinfo *pbaseinfo = &pcui->img_base_info;
    cui_iv_img_extinfo *pextinfo = &pscrn_data->cur_img_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* compute zoom params */
    if (pscrn_data->flag & IV_FLAG_ZOOMIN)
    {
        pbaseinfo->zoom_factor += MMI_IV_ZOOM_STEP;
    }
    else
    {
        pbaseinfo->zoom_factor -= MMI_IV_ZOOM_STEP;
    }

    if (pbaseinfo->zoom_factor > 10 &&
        pbaseinfo->zoom_factor < pextinfo->max_zoom_factor)
    {   /* check if reach to max */
        /* start timer */
        gui_start_timer_ex(MMI_IV_ZOOM_INTERVAL, cui_iv_zoom_cyclic, pcui);
    }
    else
    {
        /* clear zoom flag */
        pscrn_data->flag &= ~(IV_FLAG_ZOOMIN | IV_FLAG_ZOOMOUT);

        if (pbaseinfo->zoom_factor <= 10)
        {
            pbaseinfo->zoom_factor = 10;
        }
        else
        {
            pbaseinfo->zoom_factor = pextinfo->max_zoom_factor;
        }
    }

    /* update zoom factor and other data */
    cui_iv_compute_zoom_data(pcui, 1);

    /* get current image */
    cui_iv_get_img(pcui, pextinfo->resizer_mode);
    /* zoom out terminated and not called from terminated timer and large cache dec callback */
    if(pbaseinfo->zoom_factor == 10 && pextinfo->resizer_mode != IV_RESIZER_HIGH)
    {
        pextinfo->resizer_mode = IV_RESIZER_HIGH;
        gui_start_timer_ex(0, cui_iv_zoom_cyclic, pcui);
    }else{
        pextinfo->resizer_mode = IV_RESIZER_LOW;
    }

    /* update screen */
    cui_iv_update_screen(pcui, CUI_IV_UPDATE_IMAGE_STATE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_start_zoom
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  is_zoomin       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_start_zoom(cui_iv_cntx *pcui, S32 is_zoomin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;
    cui_iv_img_extinfo *pinfo = &pscrn_data->cur_img_info;
    cui_iv_img_baseinfo *pbaseinfo = &pcui->img_base_info;
    S32 cacheRet;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_ZOOM_START, is_zoomin, pinfo->is_anim, pbaseinfo->zoom_factor, pinfo->stat);

    /* check if can zoom */
    if (pinfo->is_anim || pinfo->stat != IV_IMG_STAT_OK)
        return;

    if (is_zoomin)
    {
        if (pbaseinfo->zoom_factor >= pinfo->max_zoom_factor)
            return;
        pscrn_data->flag |= IV_FLAG_ZOOMIN;
    }
    else
    {
        if (pbaseinfo->zoom_factor <= 10)
            return;

        pscrn_data->flag |= IV_FLAG_ZOOMOUT;
    }

    /* decode cache */
    cacheRet = cui_iv_start_dec_cache(pcui, pscrn_data->h_large_cache_layer, pinfo, pcui->file_name, MMI_TRUE);
    if (cacheRet == -1)
    {
        /* Will not change current display */
        return;
    }
    else if (cacheRet == 1)
    {
        /* waiting cache */
        pinfo->stat = IV_IMG_STAT_DECODING;
        cui_iv_update_screen(pcui, CUI_IV_UPDATE_IMAGE_STATE | CUI_IV_UPDATE_PANEL);
        CUI_IV_PAUSE_SHOW(pcui, pcui->index);
        return;
    }
    else
    {
        /* Will start zoom */
        cui_iv_zoom_cyclic(pcui);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_stop_zoom
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_stop_zoom(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!(pcui->scrn_data.flag & (IV_FLAG_ZOOMIN | IV_FLAG_ZOOMOUT))){
        return ;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_ZOOM_STOP);

    if (pcui->scrn_data.cache_stat != IV_CACHE_OK){
        g_large_cache_ok_callback = cui_iv_large_cache_ok_stoppedzoom_cb;
    }else{
        /* Cancel zoom timer */
        gui_cancel_timer((FuncPtr) cui_iv_zoom_cyclic);
        if(pcui->img_base_info.zoom_factor != pcui->scrn_data.cur_img_info.max_zoom_factor)
        {
            cui_iv_get_img(pcui, IV_RESIZER_HIGH);
            cui_iv_update_screen(pcui, CUI_IV_UPDATE_IMAGE_STATE);
        }
    }
    pcui->scrn_data.flag &= ~(IV_FLAG_ZOOMIN | IV_FLAG_ZOOMOUT);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_cancel_zoom
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_cancel_zoom(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_ZOOM_STOP);

    /* init cache */
    if (pscrn_data->cache_stat == IV_CACHE_DECODING)
    {
        gdi_image_nb_stop(pscrn_data->h_large_dec);
    }
    else
    {
        /* Cancel zoom timer */
        gui_cancel_timer((FuncPtr) cui_iv_zoom_cyclic);
    }
    pcui->scrn_data.flag &= ~(IV_FLAG_ZOOMIN | IV_FLAG_ZOOMOUT);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_zoom_fast
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_zoom_fast(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_img_baseinfo *pbaseinfo = &pcui->img_base_info;
    cui_iv_img_extinfo  *pextinfo = &pcui->scrn_data.cur_img_info;
    S32 is_zoomin = pbaseinfo->zoom_factor <= 10;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(is_zoomin){
        if(pextinfo->max_zoom_factor > 20){
            pbaseinfo->zoom_factor = pextinfo->max_zoom_factor - 10;
            cui_iv_compute_zoom_data(pcui, 1);
        }
    }else{
        if(pbaseinfo->zoom_factor > 20){
            pbaseinfo->zoom_factor = 20;
            cui_iv_compute_zoom_data(pcui, 1);
        }
    }
    cui_iv_start_zoom(pcui, is_zoomin);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_convert_off_direction
 * DESCRIPTION
 *
 * PARAMETERS
 *  img_orient      [IN]
 *  off_x           [?]
 *  off_y           [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_convert_off_direction(U32 img_orient, S32 *off_x, S32 *off_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp = *off_x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (img_orient == GDI_LAYER_ROTATE_0)
    {
        *off_x = -(*off_x);
        *off_y = -(*off_y);
    }
    else if (img_orient == GDI_LAYER_ROTATE_90)
    {
        *off_x = -(*off_y);
        *off_y = temp;
    }
    else if (img_orient == GDI_LAYER_ROTATE_270)
    {
        *off_x = *off_y;
        *off_y = -temp;
    }
}

/********************* PAN *************************/


/*****************************************************************************
 * FUNCTION
 *  cui_iv_pan
 * DESCRIPTION
 *  Pan the image.
 *  offset is the image offset.
 * PARAMETERS
 *  pcui        [?]
 *  off_x       [IN]
 *  off_y       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_pan(cui_iv_cntx *pcui, S32 off_x, S32 off_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pcui->img_base_info.zoom_factor <= 10)
        return;

    /* compute offset direction */
    cui_iv_convert_off_direction(pcui->img_base_info.img_orient, &off_x, &off_y);

    /* compute new pos */
    pcui->img_base_info.wnd_x += off_x;
    pcui->img_base_info.wnd_y += off_y;
    if (pcui->img_base_info.wnd_x < 0)
    {
        pcui->img_base_info.wnd_x = 0;
    }
    else if (pcui->img_base_info.wnd_x > pinfo->cur_img_w - pinfo->cur_w)
    {
        pcui->img_base_info.wnd_x = pinfo->cur_img_w - pinfo->cur_w;
    }

    if (pcui->img_base_info.wnd_y < 0)
    {
        pcui->img_base_info.wnd_y = 0;
    }
    else if (pcui->img_base_info.wnd_y > pinfo->cur_img_h - pinfo->cur_h)
    {
        pcui->img_base_info.wnd_y = pinfo->cur_img_h - pinfo->cur_h;
    }

    /* get image */
    cui_iv_get_img(pcui, IV_RESIZER_HIGH);

    /* Update screen */
    cui_iv_update_screen(pcui, CUI_IV_UPDATE_IMAGE_STATE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_start_pan
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  key_code        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_start_pan(cui_iv_cntx *pcui, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pan_x = 0, pan_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_IV_SHOW_OSD(&pcui->scrn_data, 0);
    switch (key_code)
    {
        case KEY_LEFT_ARROW:
            pan_x = MMI_IV_PAN_STEP;
            break;

        case KEY_RIGHT_ARROW:
            pan_x = -MMI_IV_PAN_STEP;
            break;

        case KEY_UP_ARROW:
            pan_y = MMI_IV_PAN_STEP;
            break;

        case KEY_DOWN_ARROW:
            pan_y = -MMI_IV_PAN_STEP;
            break;

        default:
            return;
    };
    cui_iv_pan(pcui, pan_x, pan_y);

}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_reach_edge
 * DESCRIPTION
 *
 * PARAMETERS
 *  pbaseinfo       [?]
 *  pextinfo        [?]
 *  key_code        [IN]
 * RETURNS
 *
 *****************************************************************************/
static S32 cui_iv_reach_edge(cui_iv_img_baseinfo *pbaseinfo, cui_iv_img_extinfo *pextinfo, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 direct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Rotate */
    switch (key_code)
    {
        case KEY_RIGHT_ARROW:
            direct = 0;
            break;

        case KEY_UP_ARROW:
            direct = 1;
            break;

        case KEY_LEFT_ARROW:
            direct = 2;
            break;

        case KEY_DOWN_ARROW:
            direct = 3;
            break;

        default:
            return 0;
    };

    direct = (direct + pbaseinfo->img_orient) & 0x3;

    switch (direct)
    {
        case 0: /* right */
            return pbaseinfo->wnd_x >= pextinfo->cur_img_w - pextinfo->cur_w;

        case 1: /* up */
            return pbaseinfo->wnd_y <= 0;

        case 2: /* left */
            return pbaseinfo->wnd_x <= 0;

        case 3: /* down */
            return pbaseinfo->wnd_y >= pextinfo->cur_img_h - pextinfo->cur_h;

        default:
            return 0;
    };
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_zoom_navigation_down
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  key_code        [IN]
 * RETURNS
 *
 *****************************************************************************/
static MMI_BOOL cui_iv_zoom_navigation_down(cui_iv_cntx *pcui, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reach_edge;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reach_edge = cui_iv_reach_edge(&pcui->img_base_info, &pcui->scrn_data.cur_img_info, key_code);
    if (reach_edge)
    {
        return cui_iv_still_navigation_down(pcui, key_code);
    }

    cui_iv_start_pan(pcui, key_code);

    reach_edge = cui_iv_reach_edge(&pcui->img_base_info, &pcui->scrn_data.cur_img_info, key_code);
    return reach_edge == 0 ? MMI_TRUE : MMI_FALSE;
}

#ifdef __MMI_IVF_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  cui_iv_zoom_get_switch_flag
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_zoom_get_switch_flag(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;
    mmi_keypads_enum nextKey = KEY_RIGHT_ARROW;
    mmi_keypads_enum prevKey = KEY_LEFT_ARROW;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pscrn_data->flag &= ~(IV_FLAG_NOT_SWITCH_PREV | IV_FLAG_NOT_SWITCH_NEXT);

    if (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT)
    {
        nextKey = KEY_DOWN_ARROW;
        prevKey = KEY_UP_ARROW;
    }

    if (!cui_iv_reach_edge(&pcui->img_base_info, &pscrn_data->cur_img_info, nextKey))
    {
        /* block switch next by pen  */
        pscrn_data->flag |= IV_FLAG_NOT_SWITCH_NEXT;
    }

    if (!cui_iv_reach_edge(&pcui->img_base_info, &pscrn_data->cur_img_info, prevKey))
    {
        /* block switch next by pen  */
        pscrn_data->flag |= IV_FLAG_NOT_SWITCH_PREV;
    }
}
#endif /* __MMI_IVF_TOUCH_SCREEN__ */
#endif /* __MMI_IVF_ZOOM__ */

#ifdef __MMI_IVF_SWITCH_EFFECT__
/* Switch animation parameters */
#define MMI_IV_SE_INTERVAL          30
#define MMI_IV_SE_FRAME_COUNT       6
#define MMI_IV_SE_LAYER_GAP         20

#define CUI_IV_SE_EFFECT_COUNT      1

#define CUI_IV_SE_STATE             (0x0F)
#define CUI_IV_SE_STATE_BACKWARD    (0x01 << 0)
#define CUI_IV_SE_STATE_FORWARD     (0x01 << 1)
#define CUI_IV_SE_STATE_AUTO        (0x01 << 2)

#define CUI_IV_SE_DIRECTION         (0xF0)
#define CUI_IV_SE_DIRECTION_PREV    (0x10 << 0)
#define CUI_IV_SE_DIRECTION_NEXT    (0x10 << 1)

#define CUI_IV_SE_POST_ROT          (0x01<<8)

#define CUI_IV_SE_GET_STATE(f)          ((f) & CUI_IV_SE_STATE)
#define CUI_IV_SE_SET_STATE(f, v)       ((f) = ((f) & ~CUI_IV_SE_STATE) | (v))
#define CUI_IV_SE_GET_DIRECTION(f)      (f & CUI_IV_SE_DIRECTION)
#define CUI_IV_SE_SET_DIRECTION(f, v)   ((f) = ((f) & ~CUI_IV_SE_DIRECTION) | (v))

static void cui_iv_se_cyclic(void *userData);
static void cui_iv_se_effect_ease_init(cui_iv_cntx *pcui);
static MMI_BOOL cui_iv_se_effect_ease_deinit(cui_iv_cntx *pcui);
static void cui_iv_se_effect_ease_run(cui_iv_cntx *pcui);

static const struct
{
    void (*seInitFunc) (cui_iv_cntx *pcui);
      MMI_BOOL(*seDeinitFunc) (cui_iv_cntx *pcui);
    void (*seRunFunc) (cui_iv_cntx *pcui);
} cui_iv_se_func[] =
{
    {
    cui_iv_se_effect_ease_init, cui_iv_se_effect_ease_deinit, cui_iv_se_effect_ease_run}
};


/*****************************************************************************
 * FUNCTION
 *  cui_iv_rkey_pause
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_rkey_pause(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer((FuncPtr) cui_iv_rkey_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_rkey_resume
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_rkey_resume(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((U8) pcui->scrn_data.repeat_key)
    {
        gui_start_timer_ex(MMI_IV_RKEY_INTERVAL, cui_iv_rkey_cyclic, pcui);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_se_convert_to_layer
 * DESCRIPTION
 *
 * PARAMETERS
 *  px          [?]
 *  py          [?]
 *  lyrRotV     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_se_convert_to_layer(S32 *px, S32 *py, U8 lyrRotV)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lyrRotV)
    {
        case GDI_LCD_LAYER_ROTATE_90:
            temp = *px;
            *px = *py;
            *py = -temp;
            break;

        case GDI_LCD_LAYER_ROTATE_180:
            *px = -(*px);
            *py = -(*py);
            break;

        case GDI_LCD_LAYER_ROTATE_270:
            temp = *px;
            *px = -(*py);
            *py = temp;
            break;

        default:
            break;
    };
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_se_convert_to_screen
 * DESCRIPTION
 *
 * PARAMETERS
 *  px          [?]
 *  py          [?]
 *  lyrRotV     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_se_convert_to_screen(S32 *px, S32 *py, U8 lyrRotV)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lyrRotV)
    {
        case GDI_LCD_LAYER_ROTATE_90:
            temp = *px;
            *px = -(*py);
            *py = temp;
            break;

        case GDI_LCD_LAYER_ROTATE_180:
            *px = -(*px);
            *py = -(*py);
            break;

        case GDI_LCD_LAYER_ROTATE_270:
            temp = *px;
            *px = *py;
            *py = -temp;
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_se_get_layer_pos
 * DESCRIPTION
 *
 * PARAMETERS
 *  layer_handle        [IN]
 *  px                  [?]
 *  py                  [?]
 *  careRot             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_se_get_layer_pos(GDI_HANDLE layer_handle, S32 *px, S32 *py, S32 careRot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 lyrRotV;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_position_nb_concurrent(layer_handle, px, py);
    if (careRot)
    {
        lyrRotV = gdi_layer_get_rotate_nb_concurrent(layer_handle);
        cui_iv_se_convert_to_screen(px, py, lyrRotV);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_se_set_layer_pos
 * DESCRIPTION
 *
 * PARAMETERS
 *  layer_handle        [IN]
 *  x                   [IN]
 *  y                   [IN]
 *  careRot             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_se_set_layer_pos(GDI_HANDLE layer_handle, S32 x, S32 y, S32 careRot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 lyrRotV;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (careRot)
    {
        lyrRotV = gdi_layer_get_rotate_nb_concurrent(layer_handle);
        cui_iv_se_convert_to_layer(&x, &y, lyrRotV);
    }

    gdi_layer_set_position_nb_concurrent(layer_handle, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_se_get_blt_layers
 * DESCRIPTION
 *
 * PARAMETERS
 *  pscrnData       [IN]
 *  disLyr          [?]
 *  switchLyr       [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_se_get_blt_layers(const cui_iv_scrndata *pscrnData, GDI_HANDLE *disLyr, GDI_HANDLE *switchLyr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const cui_iv_se_data *pse = &pscrnData->seData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != pse->currFrameIdx)
    {
        *disLyr = pse->displayLyr;
        *switchLyr = pse->switchLyr;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_se_init_data
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  imgIdx          [IN]
 *  isNext          [IN]
 *  effectIdx       [IN]
 *  displayLyr      [IN]
 *  switchLyr       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_se_init_data(
                cui_iv_cntx *pcui,
                U32 imgIdx,
                S32 isNext,
                S32 effectIdx,
                GDI_HANDLE displayLyr,
                GDI_HANDLE switchLyr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrnData = &pcui->scrn_data;
    cui_iv_se_data *pse = &pscrnData->seData;
    WCHAR switchFilepath[SRV_FMGR_PATH_BUFFER_SIZE >> 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SE_INIT_DATA, imgIdx, isNext, effectIdx);

    if (IV_SCRN_STAT_PLAY != pcui->scrn_stat)
        pcui->scrn_stat = IV_SCRN_STAT_SWITCHING;

    pse->currFrameIdx = 1;
    pse->imgIdx = imgIdx;
    pse->effectIdx = effectIdx;
    pse->displayLyr = displayLyr;
    pse->switchLyr = switchLyr;

    if (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT)
        pse->flag = CUI_IV_SE_POST_ROT;
    else
        pse->flag = 0;

    if (isNext)
        CUI_IV_SE_SET_DIRECTION(pse->flag, CUI_IV_SE_DIRECTION_NEXT);
    else
        CUI_IV_SE_SET_DIRECTION(pse->flag, CUI_IV_SE_DIRECTION_PREV);

    cui_iv_se_func[pse->effectIdx].seInitFunc(pcui);

    /* init content of switch layer */
    {
        S32 result;

        result = cui_iv_get_filename(pcui, imgIdx, switchFilepath, NULL, NULL);

        if (0 == result)
        {
            if (MMI_FALSE == CUI_IV_DRM_CHECK_RIGHT(switchFilepath))
            {
                result = -2;
            }
            else
            {
                S32 ivdecRet;

                ivdecRet = mmi_ivc_query_img(pcui->scrn_data.decHdl, imgIdx, pse->switchLyr);
                if (MMI_IVC_FAILE == ivdecRet)
                    result = 1;
            }
        }

        if (1 == result)
			#ifdef __MMI_IV_PLUTO_SLIM__
				loading_dstLyr = pse->switchLyr;
				cui_iv_draw_load_string();
			#else
            cui_iv_draw_err_icon(pse->switchLyr, IMG_ID_IV_LOAD);
			#endif
        else if (-1 == result)
			#ifdef __MMI_IV_PLUTO_SLIM__
            	cui_iv_draw_err_string(pse->switchLyr);
			#else
            cui_iv_draw_err_icon(pse->switchLyr, IMG_ID_IV_ERROR);
			#endif
    #ifdef __DRM_SUPPORT__
        else if (-2 == result)
            cui_iv_draw_err_icon(pse->switchLyr, IMG_ID_IV_ERROR_NO_RIGHT);
    #endif /* __DRM_SUPPORT__ */
    }

    /* Stop bg decode */
    mmi_ivc_stop(pcui->scrn_data.decHdl);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_se_deinit_data
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *
 *****************************************************************************/
static MMI_BOOL cui_iv_se_deinit_data(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrnData = &pcui->scrn_data;
    cui_iv_se_data *pse = &pscrnData->seData;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SE_DEINIT_DATA);

    if (IV_SCRN_STAT_PLAY != pcui->scrn_stat)
        pcui->scrn_stat = IV_SCRN_STAT_ACTIVE;

    /* Start bg decode */
    mmi_ivc_start(pcui->scrn_data.decHdl);

    result = cui_iv_se_func[pse->effectIdx].seDeinitFunc(pcui);

    /* If last frame, call switch complete callback */
    if (MMI_IV_SE_FRAME_COUNT == pse->currFrameIdx && NULL != pse->completeFunc)
    {
        U32 newDispCap = pcui->disp_cap;

        if (pse->flag & CUI_IV_SE_POST_ROT)
            newDispCap |= CUI_IMGVIEW_DISP_ROT;
        else
            newDispCap &= ~CUI_IMGVIEW_DISP_ROT;

        /* in completeFunc may query blt layer, so need reset this var first */
        pse->currFrameIdx = 0;
        pse->completeFunc(pse->completeUserData, pse->imgIdx, newDispCap);
        pse->completeFunc = NULL;
    }

    pse->currFrameIdx = 0;
    pse->imgIdx = 0xFFFFFFFF;
    pse->flag = 0;
    pse->effectIdx = -1;

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_se_finish
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *
 *****************************************************************************/
static MMI_BOOL cui_iv_se_finish(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_MEDIA_TRC_G2_APP,
        MMI_TRC_IVAPP_SE_FINISH,
        pcui->scrn_data.seData.currFrameIdx,
        pcui->scrn_data.seData.flag);

    gui_cancel_timer((FuncPtr) cui_iv_se_cyclic);

    cui_iv_rkey_resume(pcui);

    return cui_iv_se_deinit_data(pcui);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_se_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  complete        [IN]
 *  userData        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_se_start(cui_iv_cntx *pcui, cui_iv_se_complete_cb complete, void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrnData = &pcui->scrn_data;
    cui_iv_se_data *pse = &pscrnData->seData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SE_START);

    cui_iv_rkey_pause(pcui);

    pse->currFrameIdx = 1;
    pse->completeFunc = complete;
    pse->completeUserData = userData;
    cui_iv_se_cyclic((void*)pcui);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_se_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *
 *****************************************************************************/
static MMI_BOOL cui_iv_se_stop(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrnData = &pcui->scrn_data;
    cui_iv_se_data *pse = &pscrnData->seData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == pse->currFrameIdx)
        return MMI_FALSE;

    pse->completeFunc = NULL;
    pse->completeUserData = NULL;

    return cui_iv_se_finish(pcui);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_se_cyclic
 * DESCRIPTION
 *
 * PARAMETERS
 *  userData        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_se_cyclic(void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui = (cui_iv_cntx*) userData;
    cui_iv_scrndata *pscrnData = &pcui->scrn_data;
    cui_iv_se_data *pse = &pscrnData->seData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SE_CYCLIC, pse->currFrameIdx, pse->flag);

    gui_start_timer_ex(MMI_IV_SE_INTERVAL, cui_iv_se_cyclic, userData);

    cui_iv_se_func[pse->effectIdx].seRunFunc(pcui);

    if (MMI_IV_SE_FRAME_COUNT == pse->currFrameIdx)
    {
        /* Animation is done */
        cui_iv_se_finish(pcui);
    }
    else
    {
        MMI_ASSERT(MMI_IV_SE_FRAME_COUNT > pse->currFrameIdx);
        pse->currFrameIdx++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_se_effect_ease_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_se_effect_ease_init(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrnData = &pcui->scrn_data;
    cui_iv_se_data *pse = &pscrnData->seData;
    S32 sign = -1;  /* Switch to prev should move from left to right */
    U8 rot;
    S32 layerW;
    S32 layerH;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CUI_IV_SE_DIRECTION_NEXT == CUI_IV_SE_GET_DIRECTION(pse->flag)) /* Switch to next should also move from right to left */
    {
        sign = 1;
    }

    CUI_IV_SE_SET_STATE(pse->flag, CUI_IV_SE_STATE_FORWARD);

    /* Init switch layer. */
    if ((pcui->disp_cap & CUI_IMGVIEW_DISP_ROT) == CUI_IMGVIEW_DISP_ROT)
    {
        rot = GDI_LAYER_ROTATE_90;
        layerW = LCD_HEIGHT;
        layerH = LCD_WIDTH;
    }
    else
    {
        rot = GDI_LAYER_ROTATE_0;
        layerW = LCD_WIDTH;
        layerH = LCD_HEIGHT;
    }
    gdi_layer_resize_nb_concurrent(pcui->scrn_data.seData.switchLyr, layerW, layerH);
    gdi_layer_set_rotate_nb_concurrent(pcui->scrn_data.seData.switchLyr, rot);
    gdi_layer_clear_nb_concurrent(pcui->scrn_data.seData.switchLyr, GDI_COLOR_BLACK);
    cui_iv_se_set_layer_pos(pse->switchLyr, sign * (layerW + MMI_IV_SE_LAYER_GAP), 0, 0);
    cui_iv_se_set_layer_pos(pse->displayLyr, 0, 0, 1);

    /* set blt layers */
    gdi_layer_set_blt_layer_nb_concurrent(
        pse->displayLyr,
        pse->switchLyr,
        GDI_LAYER_EMPTY_HANDLE,
        GDI_LAYER_EMPTY_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_se_effect_ease_deinit
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *
 *****************************************************************************/
static MMI_BOOL cui_iv_se_effect_ease_deinit(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrnData = &pcui->scrn_data;
    cui_iv_se_data *pse = &pscrnData->seData;

    S32 layerW, layerH;
    S32 swiPosX, swiPosY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_dimension_nb_concurrent(pse->switchLyr, &layerW, &layerH);

    cui_iv_se_get_layer_pos(pse->switchLyr, &swiPosX, &swiPosY, 0);

    /* Reset layers. */
    cui_iv_se_set_layer_pos(pse->displayLyr, 0, 0, 1);
    cui_iv_se_set_layer_pos(pse->switchLyr, 0, 0, 0);

    if (CUI_IV_SE_STATE_BACKWARD == CUI_IV_SE_GET_STATE(pse->flag))
        pse->imgIdx = pcui->index;

    if (abs(swiPosX) < (layerW / 2) && CUI_IV_SE_STATE_FORWARD == CUI_IV_SE_GET_STATE(pse->flag))
    {
        /* Switch action almost done */
        gdi_layer_set_blt_layer_nb_concurrent(
            pse->switchLyr,
            GDI_LAYER_EMPTY_HANDLE,
            GDI_LAYER_EMPTY_HANDLE,
            GDI_LAYER_EMPTY_HANDLE);
        return MMI_TRUE;
    }
    else
    {
        /* Switch action is cancelled */
        gdi_layer_set_blt_layer_nb_concurrent(
            pse->displayLyr,
            GDI_LAYER_EMPTY_HANDLE,
            GDI_LAYER_EMPTY_HANDLE,
            GDI_LAYER_EMPTY_HANDLE);
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_se_effect_ease_run
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_se_effect_ease_run(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrnData = &pcui->scrn_data;
    cui_iv_se_data *pse = &pscrnData->seData;

    S32 layerW, layerH;
    S32 disPosX, disPosY;
    S32 swiPosX, swiPosY;
    S32 refDiff;
    S32 movement;   /* unit: pixel */

    /* Uniformly accelerated motion parameters */
    S32 initialV = 0;   /* unit: pixel/s */
    S32 finalV;         /* unit: pixel/s */
    S32 acc;            /* unit: pixel/(s*s) */
    S32 totalS;         /* unit: pixel */
    S32 totalT;         /* unit: ms */
    S32 currT;          /* unit: ms */
    S32 currS;          /* unit: pixel */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define CUI_IV_SE_REBOUND_THRESHOLD (layerW * 3 / 4)

    gdi_layer_get_dimension_nb_concurrent(pse->switchLyr, &layerW, &layerH);

    /* Cause curr image may have different image rotate value, so the change for display layer is not on a fix coordination. */
    cui_iv_se_get_layer_pos(pse->displayLyr, &disPosX, &disPosY, 1);
    /* The change for switch layer is always on the x-coordination. */
    cui_iv_se_get_layer_pos(pse->switchLyr, &swiPosX, &swiPosY, 0);

#ifdef __MMI_IVF_DRAG_SWITCH__
    if (1 == pse->currFrameIdx && CUI_IV_SE_STATE_AUTO == CUI_IV_SE_GET_STATE(pse->flag))
    {
        if (abs(swiPosX) <= (layerW + MMI_IV_SE_LAYER_GAP) && abs(swiPosX) >= CUI_IV_SE_REBOUND_THRESHOLD)
        {
            /* Cancel switch action and rebound back */
            CUI_IV_SE_SET_STATE(pse->flag, CUI_IV_SE_STATE_BACKWARD);
        }
        else
        {
            /* Continue switch action
               This is for case: pen down when rebound, and drag to switch again, need to set to continue switch */
            CUI_IV_SE_SET_STATE(pse->flag, CUI_IV_SE_STATE_FORWARD);
        }
    }

    if (CUI_IV_SE_STATE_BACKWARD == CUI_IV_SE_GET_STATE(pse->flag))
    {
        refDiff = (layerW + MMI_IV_SE_LAYER_GAP) * (swiPosX / abs(swiPosX)) - swiPosX;
    }
    else
#endif /* __MMI_IVF_DRAG_SWITCH__ */
    {
        refDiff = swiPosX;
    }

    if (1 == pse->currFrameIdx)
        pse->seParam = abs(refDiff);

    if (0 == refDiff)
        pse->currFrameIdx = MMI_IV_SE_FRAME_COUNT;
    else
    {
        /* Uniformly accelerated motion:
           1. (totalS = (initialV + finalV) * totalT / 2) --> (finialV = 2 * totalS / totalT - initialV)
           2. (finalV = initialV + acc * t) --> (acc = (finalV - initialV) / totalT)
           3. (currS = initialV * currT + acc * currT * currT / 2) */
        totalT = MMI_IV_SE_INTERVAL * MMI_IV_SE_FRAME_COUNT;
        totalS = pse->seParam;
        finalV = 2 * totalS * 1000 / totalT - initialV;
        acc = (finalV - initialV) * 1000 / totalT;
        currT = totalT - (MMI_IV_SE_INTERVAL * pse->currFrameIdx);
        currS = initialV * currT / 1000 + acc * currT * currT / (2 * 1000 * 1000);
        movement = abs(refDiff) - currS;

    #ifdef __MMI_IVF_DRAG_SWITCH__
        /* If ref layer pos is greater then 0, then its pos should become smaller.
           Otherwise it should be greater. */
        if (CUI_IV_SE_STATE_BACKWARD == CUI_IV_SE_GET_STATE(pse->flag))
        {
            movement = movement * (refDiff / abs(refDiff));
        }
        else
    #endif /* __MMI_IVF_DRAG_SWITCH__ */
        {
            movement = (-1) * movement * (refDiff / abs(refDiff));
        }

        /* Set layer pos and update screen, the pos changes of display layer and switch layer are the same. */
        swiPosX += movement;
        if ((pcui->disp_cap & CUI_IMGVIEW_DISP_ROT) == CUI_IMGVIEW_DISP_ROT)
        {
            /* View is rotated, according to screen, disLayer change will on y-coordination */
            disPosY += movement;
        }
        else
        {
            /* View is not rotated, according to screen, disLayer change will on x-coordination */
            disPosX += movement;
        }

        /* Cause curr image may have different image rotate value, so the change for display layer is not on a fix coordination. */
        cui_iv_se_set_layer_pos(pse->displayLyr, disPosX, disPosY, 1);
        /* The change for switch layer is always on the x-coordination. */
        cui_iv_se_set_layer_pos(pse->switchLyr, swiPosX, swiPosY, 0);

        cui_iv_update_screen(pcui, CUI_IV_UPDATE_IMAGE_STATE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_switch_exit
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_switch_exit(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_done;
    U32 seIdx = pcui->scrn_data.seData.imgIdx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SWITCH_EXIT);

    /* Stop async operations */
    cui_iv_cancel_img_ops(pcui);

    is_done = cui_iv_se_stop(pcui);

    if (MMI_TRUE == is_done)
        pcui->index = seIdx;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_switch_key_down
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  key_code        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_switch_key_down(cui_iv_cntx *pcui, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SWITCH_KEY_DOWN);

    pcui->scrn_data.flag &= ~IV_FLAG_KEY_DOWN;  /* ignore the key up */
}

#ifdef __MMI_IVF_DRAG_SWITCH__
static mmi_touch_pos_struct g_ivcui_switch_pen_speed_pre_move_pos;


/*****************************************************************************
 * FUNCTION
 *  cui_iv_switch_pen_speed_move
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  touchData       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_switch_pen_speed_move(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ivcui_switch_pen_speed_pre_move_pos = touchData->pre_pos;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_switch_pen_speed_up
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  touchData       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_switch_pen_speed_up(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offx = touchData->pre_pos.pos.x - g_ivcui_switch_pen_speed_pre_move_pos.pos.x;
    S32 offy = touchData->pre_pos.pos.y - g_ivcui_switch_pen_speed_pre_move_pos.pos.y;
    S32 V = offx * offx + offy * offy;
    U32 T = touchData->currpos.timestamp - touchData->down_pos.timestamp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define CUI_IV_SWITCH_AUTO_RUN_THRESHOLD    ((6*6*2)/(KAL_TICKS_10_MSEC*2))

    if (MMI_PEN_EVENT_MOVE != touchData->pre_event)
    {
        /* Pen not moving */
        CUI_IV_SE_SET_STATE(pcui->scrn_data.seData.flag, CUI_IV_SE_STATE_AUTO);
    }
    else if (CUI_IV_SE_STATE_FORWARD == CUI_IV_SE_GET_STATE(pcui->scrn_data.seData.flag))
    {
        /* Only at forward condition need to let SE decide to run forward or backward */
        if (V <= CUI_IV_SWITCH_AUTO_RUN_THRESHOLD || T >= (3 * KAL_TICKS_100_MSEC))
            CUI_IV_SE_SET_STATE(pcui->scrn_data.seData.flag, CUI_IV_SE_STATE_AUTO);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_switch_get_switch_direction
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  offset      [IN]
 * RETURNS
 *  1: next
 *  -1: prev
 *  0: none
 *****************************************************************************/
static S32 cui_iv_switch_get_switch_direction(cui_iv_cntx *pcui, S32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;
    U32 oldFlag = pscrn_data->flag;
    U32 newFlag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pcui->count <= 1)
        return 0;

    CUI_IV_ZOOM_GET_SWITCH_FLAG(pcui);

    newFlag = pscrn_data->flag;
    pscrn_data->flag = oldFlag;

    /* check if need switch */
    if (offset > 0 && !(newFlag & IV_FLAG_NOT_SWITCH_PREV) && !(oldFlag & IV_FLAG_NOT_SWITCH_PREV))
    {
        return -1;
    }
    else if (offset < 0 && !(newFlag & IV_FLAG_NOT_SWITCH_NEXT) && !(oldFlag & IV_FLAG_NOT_SWITCH_NEXT))
    {
        return 1;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_switch_pan
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  offset      [IN]
 * RETURNS
 *
 *****************************************************************************/
static S32 cui_iv_switch_pan(cui_iv_cntx *pcui, S32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrnData = &pcui->scrn_data;
    cui_iv_se_data *pse = &pscrnData->seData;

    S32 layerW, layerH;
    S32 disPosX, disPosY, disOffset;
    S32 swiPosX, swiPosY;

    MMI_BOOL isFinish = MMI_FALSE;
    S32 extOffset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SWITCH_PAN);

    if (0 == offset)
        return 0;

    gdi_layer_get_dimension_nb_concurrent(pse->switchLyr, &layerW, &layerH);

    /* Cause curr image may have different image rotate value, so the change for display layer is not on a fix coordination. */
    cui_iv_se_get_layer_pos(pse->displayLyr, &disPosX, &disPosY, 1);
    /* The change for switch layer is always on the x-coordination. */
    cui_iv_se_get_layer_pos(pse->switchLyr, &swiPosX, &swiPosY, 0);

    if (abs(swiPosX + offset) >= (layerW + MMI_IV_SE_LAYER_GAP))
    {
        /* Drag out another image, and then drag it back */
        S32 switchRet;

        extOffset = (abs(swiPosX + offset) - (layerW + MMI_IV_SE_LAYER_GAP)) * (offset / abs(offset));

        switchRet = cui_iv_switch_get_switch_direction(pcui, offset);
        if (0 != switchRet)
        {
            cui_iv_se_init_data(
                pcui,
                (pcui->index + pcui->count + switchRet) % pcui->count,
                switchRet == 1 ? 1 : 0,
                pse->effectIdx,
                pse->displayLyr,
                pse->switchLyr);
            return 0;
        }
        else
        {
            isFinish = MMI_TRUE;
            offset = offset - extOffset;
        }
    }

    if (swiPosX * (swiPosX + offset) < 0 || abs(swiPosX) >= abs(swiPosX + offset))
    {
        /* Move closer to 0 */
        CUI_IV_SE_SET_STATE(pse->flag, CUI_IV_SE_STATE_FORWARD);
    }
    else
    {
        /* Move far away from 0 */
        CUI_IV_SE_SET_STATE(pse->flag, CUI_IV_SE_STATE_BACKWARD);
    }

    /* Set layer pos and update screen, the pos changes of display layer and switch layer are the same. */
    swiPosX += offset;
    if ((pcui->disp_cap & CUI_IMGVIEW_DISP_ROT) == CUI_IMGVIEW_DISP_ROT)
    {
        /* View is rotated, according to screen, disLayer change will on y-coordination */
        disPosY += offset;
        disOffset = disPosY;
    }
    else
    {
        /* View is not rotated, according to screen, disLayer change will on x-coordination */
        disPosX += offset;
        disOffset = disPosX;
    }

    /* Cause curr image may have different image rotate value, so the change for display layer is not on a fix coordination. */
    cui_iv_se_set_layer_pos(pse->displayLyr, disPosX, disPosY, 1);
    /* The change for switch layer is always on the x-coordination. */
    cui_iv_se_set_layer_pos(pse->switchLyr, swiPosX, swiPosY, 0);

    if (swiPosX * disOffset > 0 || swiPosX == 0)
    {
        /* Continue drag */
        isFinish = MMI_TRUE;
        pse->currFrameIdx = MMI_IV_SE_FRAME_COUNT;  /* Current switch is done, call back app. */
        CUI_IV_ZOOM_GET_SWITCH_FLAG(pcui);
    }

    if (MMI_TRUE == isFinish)
    {
        cui_iv_se_finish(pcui);
    }

    cui_iv_update_screen(pcui, CUI_IV_UPDATE_IMAGE_STATE);

    return extOffset;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_switch_pen_move
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  touchData       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_switch_pen_move(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 extOffset;
    S32 offx = touchData->currpos.pos.x - touchData->pre_pos.pos.x;
    S32 offy = touchData->currpos.pos.y - touchData->pre_pos.pos.y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SWITCH_PEN_MOVE);

    if (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT)
    {
        /* View is rotated, according to screen, disLayer change will on y-coordination */
        extOffset = cui_iv_switch_pan(pcui, offy);

        /* offy is intercepted by switch effect */
        cui_iv_on_move(pcui, offx, extOffset);
    }
    else
    {
        /* View is not rotated, according to screen, disLayer change will on x-coordination */
        extOffset = cui_iv_switch_pan(pcui, offx);

        /* offx is intercepted by switch effect */
        cui_iv_on_move(pcui, extOffset, offy);
    }

    cui_iv_switch_pen_speed_move(pcui, touchData);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_switch_pen_down
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  touchData       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_switch_pen_down(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SWITCH_PEN_DOWN);
    pcui->scrn_data.pen_stat = IV_PEN_STAT_DOWN1;

    gui_cancel_timer((FuncPtr) cui_iv_se_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_switch_pen_up
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  touchData       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_switch_pen_up(cui_iv_cntx *pcui, mmi_touch_data_struct *touchData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SWITCH_PEN_UP);

    pcui->scrn_data.pen_stat = IV_PEN_STAT_INIT;

    cui_iv_switch_pen_speed_up(pcui, touchData);

    cui_iv_se_start(pcui, cui_iv_switch_complete, (void*)pcui);
}
#endif /* __MMI_IVF_DRAG_SWITCH__ */

#ifdef __MMI_IVF_MOTION__


/*****************************************************************************
 * FUNCTION
 *  cui_iv_switch_motion_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  rot         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_switch_motion_hdlr(cui_iv_cntx *pcui, U32 rot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SWITCH_MOTION_HDLR, rot);

    if (rot & CUI_IMGVIEW_DISP_ROT)
        pcui->scrn_data.seData.flag |= CUI_IV_SE_POST_ROT;
    else
        pcui->scrn_data.seData.flag &= ~CUI_IV_SE_POST_ROT;
}
#endif /* __MMI_IVF_MOTION__ */


/*****************************************************************************
 * FUNCTION
 *  cui_iv_pause_img_ops
 * DESCRIPTION
 *  Pause all the uncompleted operations of current image.
 * PARAMETERS
 *  pcui        [?]     Context of CUI.
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_pause_img_ops(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_PAUSE_IMG_OPS, pinfo->stat);

    if (pinfo->stat == IV_IMG_STAT_LOADING)
    {
        /* Stop current loading */
        cui_iv_cancel_load_file();
    }

    /* Stop large cache decoding */
    CUI_IV_CANCEL_ZOOM(pcui);

    cui_iv_imgadp_pause(pcui, pinfo->pImg);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_resume_img_ops
 * DESCRIPTION
 *  Resume paused operations of current image.
 * PARAMETERS
 *  pcui        [?]     Context of CUI.
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_resume_img_ops(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_img_extinfo *pinfo = &pcui->scrn_data.cur_img_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_RESUME_IMG_OPS, pinfo->stat);

    if (pinfo->stat == IV_IMG_STAT_LOADING || pinfo->stat == IV_IMG_STAT_DECODING)
    {
        /* Resume current loading */
        cui_iv_update_img(
            pcui,
            pcui->index,
            (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT) == CUI_IMGVIEW_DISP_ROT ? GDI_LAYER_ROTATE_90 : GDI_LAYER_ROTATE_0);
    }
    else
    {
        /* No need to resume */
    }

    /* Resume current animation */
    cui_iv_imgadp_resume(pcui, pinfo->pImg);
}
#endif /* __MMI_IVF_SWITCH_EFFECT__ */

#ifdef __MMI_IVF_MOTION__


/*****************************************************************************
 * FUNCTION
 *  cui_iv_motion_event_hdlr
 * DESCRIPTION
 *  the callback of motion event
 * PARAMETERS
 *  sensor_type     [IN]
 *  sensor_data     [?]
 *  user_data       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_iv_motion_event_hdlr(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sensor_motion_direct_struct *pDirect = (srv_sensor_motion_direct_struct*) sensor_data;
    srv_sensor_motion_direct_enum direct = pDirect->direct;
    cui_iv_cntx *pcui = (cui_iv_cntx*) user_data;
    U32 rot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (direct == SRV_SENSOR_MOTION_ANGLE_GX180)
    {
        rot = CUI_IMGVIEW_DISP_ROT;
    }
    else if (direct == SRV_SENSOR_MOTION_ANGLE_GY180)
    {
        rot = 0;
    }
    else
    {
        return;
    }

    if (rot != (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT))
    {
        if (cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].motion_hdlr)
            cui_iv_scrn_input[pcui->scrn_stat - IV_SCRN_STAT_ACTIVE].motion_hdlr(pcui, rot);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_motion_start_listen
 * DESCRIPTION
 *  Start listen motion.
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_motion_start_listen(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sensor_motion_direct_cfg_struct sensitive;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sensitive.angle_threshold = 30;

    pcui->scrn_data.motionHld = srv_sensor_start_listen(
                                    SRV_SENSOR_MOTION_DIRECT,
                                    &sensitive,
                                    cui_iv_motion_event_hdlr,
                                    (void*)pcui);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_motion_stop_listen
 * DESCRIPTION
 *  Stop listen motion.
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_motion_stop_listen(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sensor_stop_listen(pcui->scrn_data.motionHld);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_still_motion_hdlr
 * DESCRIPTION
 *  Still motion handler.
 * PARAMETERS
 *  pcui        [?]
 *  rot         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_iv_still_motion_hdlr(cui_iv_cntx *pcui, U32 rot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 newDispCap = pcui->disp_cap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_STILL_MOTION_HDLR, rot);

    if (rot & CUI_IMGVIEW_DISP_ROT)
        newDispCap |= CUI_IMGVIEW_DISP_ROT;
    else
        newDispCap &= ~CUI_IMGVIEW_DISP_ROT;

    if (newDispCap != pcui->disp_cap)
    {
        cui_iv_rotate_view(pcui);
    }
}
#endif /* __MMI_IVF_MOTION__ */

#ifdef __DRM_SUPPORT__
enum
{
    CUI_IV_DRM_STAT_INIT = 0,
    CUI_IV_DRM_STAT_CONSUME,
    CUI_IV_DRM_STAT_PAUSE,
    CUI_IV_DRM_STAT_EXPIRE
};

cui_iv_drm_cntx_t g_cui_iv_drm_cntx;


/*****************************************************************************
 * FUNCTION
 *  cui_iv_drm_start_consume
 * DESCRIPTION
 *  start consume DRM right when the whole image is shown on screen.
 * PARAMETERS
 *  pDrm_cntx       [?]
 *  rights          [IN]
 *  callback        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_drm_start_consume(
                cui_iv_drm_cntx_t *pDrm_cntx,
                kal_uint8 rights,
                void (*callback) (kal_int32 result, kal_int32 id))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h_file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(pDrm_cntx->stat == CUI_IV_DRM_STAT_INIT);

    if ((h_file = DRM_open_file((kal_wchar*) (pDrm_cntx->filepath), FS_READ_ONLY, rights)) >= FS_NO_ERROR)
    {
        pDrm_cntx->drm_id = DRM_consume_rights(h_file, rights, callback);
        DRM_close_file(h_file);
        pDrm_cntx->stat = CUI_IV_DRM_STAT_CONSUME;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_drm_pause_consume
 * DESCRIPTION
 *  pause consume DRM right when interrupting
 * PARAMETERS
 *  pDrm_cntx       [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_drm_pause_consume(cui_iv_drm_cntx_t *pDrm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(pDrm_cntx->stat == CUI_IV_DRM_STAT_CONSUME);
    DRM_pause_consume(pDrm_cntx->drm_id);
    pDrm_cntx->stat = CUI_IV_DRM_STAT_PAUSE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_drm_resume_consume
 * DESCRIPTION
 *  resume consume DRM right when come form history
 * PARAMETERS
 *  pDrm_cntx       [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_drm_resume_consume(cui_iv_drm_cntx_t *pDrm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(pDrm_cntx->stat == CUI_IV_DRM_STAT_PAUSE);

    DRM_resume_consume(pDrm_cntx->drm_id);  /* How to deal with the return value ?????????? */
    pDrm_cntx->stat = CUI_IV_DRM_STAT_CONSUME;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_drm_stop_consume
 * DESCRIPTION
 *  stop consume DRM right when destroy view screen or switch image
 * PARAMETERS
 *  pDrm_cntx       [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_drm_stop_consume(cui_iv_drm_cntx_t *pDrm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pDrm_cntx->stat == CUI_IV_DRM_STAT_PAUSE) || (pDrm_cntx->stat == CUI_IV_DRM_STAT_CONSUME))
    {
        DRM_stop_consume(pDrm_cntx->drm_id);
    }

    pDrm_cntx->stat = CUI_IV_DRM_STAT_INIT;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_drm_check_right
 * DESCRIPTION
 *  check file's DRM right
 * PARAMETERS
 *  filepath            [IN]
 *  check_rights        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static S32 cui_iv_drm_check_right(const WCHAR *filepath, U8 check_rights)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DRM_get_object_method(-1, (kal_wchar*) filepath) != DRM_METHOD_NONE)
    {
        if (!DRM_validate_permission(-1, (kal_wchar*) filepath, check_rights))
        {
            return 0;
        }
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_drm_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 *  id          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_drm_cb(kal_int32 result, kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_drm_show_image
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  img_ok      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_drm_show_image(cui_iv_cntx *pcui, S32 img_ok)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_drm_cntx_t *pdrm = &g_cui_iv_drm_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pcui->index == pdrm->index)
    {
        if (pdrm->stat == CUI_IV_DRM_STAT_PAUSE)
        {
            cui_iv_drm_resume_consume(pdrm);
        }
    }
    else
    {
        cui_iv_drm_stop_consume(pdrm);
        pdrm->filepath = pcui->file_name;

        if (img_ok && cui_iv_drm_check_right(pcui->file_name, DRM_PERMISSION_DISPLAY))
        {
            cui_iv_drm_start_consume(pdrm, DRM_PERMISSION_DISPLAY, cui_iv_drm_cb);
            if (pdrm->stat == CUI_IV_DRM_STAT_CONSUME)
            {
                pdrm->index = pcui->index;
            }
        }
        else
        {
            pdrm->index = 0xFFFFFFFF;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_drm_pause_show
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  index       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_drm_pause_show(cui_iv_cntx *pcui, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_drm_cntx_t *pdrm = &g_cui_iv_drm_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == pdrm->index && pdrm->stat == CUI_IV_DRM_STAT_CONSUME)
    {
        cui_iv_drm_pause_consume(pdrm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_drm_exit_show
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_drm_exit_show(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_iv_drm_stop_consume(&g_cui_iv_drm_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_drm_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_drm_init(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_drm_cntx_t *pdrm = &g_cui_iv_drm_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pdrm->index = 0xFFFFFFFF;
}
#endif /* __DRM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  cui_iv_popup_waiting
 * DESCRIPTION
 *
 * PARAMETERS
 *  parent_id       [IN]
 *  usrdata         [IN]
 * RETURNS
 *  Alert screen id.
 *****************************************************************************/
static MMI_ID cui_iv_popup_waiting(mmi_id parent_id, void *usrdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&property, CNFM_TYPE_CANCEL);
    property.parent_id = parent_id;
    property.user_tag = usrdata;
    property.f_enter_history = 1;
    property.f_auto_dismiss = 0;
    property.f_auto_map_empty_softkey = 0;
    return mmi_confirm_display((WCHAR*) GetString(STR_GLOBAL_PLEASE_WAIT), MMI_EVENT_PROGRESS, &property);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_create_mscrn
 * DESCRIPTION
 *  Create main screen. First Entry.
 * PARAMETERS
 *  pcui        [?]     Context of CUI.
 * RETURNS
 *  void
 *****************************************************************************/
IV_MOD_API void cui_iv_create_mscrn(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_SCRN_CREATE, __LINE__);

    mmi_frm_group_enter(pcui->cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (cui_iv_init_file_list(pcui))
    {
        pcui->wait_scrn_id = cui_iv_popup_waiting(pcui->cui_gid, pcui);
        return;
    }
    /* Init image base info */
    if (pcui->disp_cap & CUI_IMGVIEW_DISP_ROT)
    {
        pcui->img_base_info.img_orient = GDI_LAYER_ROTATE_90;
    }
    CUI_IV_ZOOM_INIT_BASE_INFO(&pcui->img_base_info);
    CUI_IV_DRM_INIT(pcui);

    /* set scrn user data and Activate screen */
    mmi_frm_scrn_create(pcui->cui_gid, SCR_ID_IMGVIEW_VIEW, cui_iv_scn_proc, pcui);
}

#ifdef __MMI_IVF_IMGADP__
#ifdef __MMI_IVF_CACHE__
static void cui_iv_imgadp_cache_get_img(cui_iv_cntx *pcui, cui_iv_imgadp_img_struct *pImg);

#define CUI_IV_IMGADP_START_DEC                         cui_iv_imgadp_cache_dec_img
#define CUI_IV_IMGADP_GET_IMG(pcui, dstLyr)             cui_iv_imgadp_cache_get_img(pcui, dstLyr)
#else /* __MMI_IVF_CACHE__ */
#define CUI_IV_IMGADP_START_DEC                         cui_iv_imgadp_app_dec_img
#define CUI_IV_IMGADP_GET_IMG(pcui, dstLyr)
#endif /* __MMI_IVF_CACHE__ */

#ifdef __MMI_IVF_ANIM_SUPPORT__
#define CUI_IV_IMGADP_ANIM_DRAW(pinfo, pfile)           cui_iv_imgadp_anim_draw(pinfo, pfile)
#define CUI_IV_IMGADP_ANIM_PAUSE(animHdl)               gdi_anim_pause(animHdl)
#define CUI_IV_IMGADP_ANIM_RESUME(animHdl)              gdi_anim_resume(animHdl)
#define CUI_IV_IMGADP_ANIM_STOP_BY_HANDLE(gdiHdl)       gdi_anim_nb_stop(gdiHdl)
#define CUI_IV_IMGADP_ANIM_STOP_BY_LAYER(lyr)           gdi_anim_stop_all_by_layer(lyr)
#else
#define CUI_IV_IMGADP_ANIM_DRAW(pinfo, pfile)
#define CUI_IV_IMGADP_ANIM_PAUSE(animHdl)
#define CUI_IV_IMGADP_ANIM_RESUME(animHdl)
#define CUI_IV_IMGADP_ANIM_STOP_BY_HANDLE(gdiHdl)
#define CUI_IV_IMGADP_ANIM_STOP_BY_LAYER(lyr)
#endif

#if defined(__MMI_IVF_CACHE__) && defined(__MMI_IVF_ANIM_SUPPORT__)
#define __MMI_IVF_IMGADP_ANIM_USE_TEMP_LAYER__
#define CUI_IV_IMGADP_GET_ANIM_LAYER(pImg)              ((GDI_LAYER_EMPTY_HANDLE != (pImg)->tempLyr) ? (pImg)->tempLyr : (pImg)->lyr)
#define CUI_IV_IMGADP_RESET_TEMP_LAYER(pImg)            cui_iv_imgadp_reset_temp_layer((pImg))
#else
#define CUI_IV_IMGADP_GET_ANIM_LAYER(pImg)              ((pImg)->lyr)
#define CUI_IV_IMGADP_RESET_TEMP_LAYER(pImg)
#endif

/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_get_img_from_gdiHdl
 * DESCRIPTION
 *
 * PARAMETERS
 *  handle      [IN]
 * RETURNS
 *
 *****************************************************************************/
static cui_iv_imgadp_img_struct *cui_iv_imgadp_get_img_from_gdiHdl(GDI_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    cui_iv_cntx *pcui;
    cui_iv_scrndata *pscrn;
    cui_iv_imgadp_struct *pImgAdp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pcui = cui_iv_get_context();
    if (!pcui)
        return NULL;

    pscrn = &pcui->scrn_data;
    pImgAdp = &pscrn->imgAdp;

    for (i = 0; i < CUI_IV_IMGADP_IMG_COUNT; i++)
    {
        if (handle == pImgAdp->imgList[i].gdiHdl)
            return &pImgAdp->imgList[i];
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_update_img_state
 * DESCRIPTION
 *
 * PARAMETERS
 *  pImg        [?]
 *  state       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_update_img_state(cui_iv_imgadp_img_struct *pImg, cui_iv_imgadp_img_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pImg->state = state;
    if (CUI_IV_IMGADP_EVENT_NONE != CUI_IV_IMGADP_EVENT_GET(pImg->state))
    {
        pImg->callback(pImg, CUI_IV_IMGADP_EVENT_GET(pImg->state), pImg->userData);
    }

    if (!CUI_IV_IMGADP_FLAG_IS_ANIM(pImg) && CUI_IV_IMGADP_IMG_STATE_PLAY == pImg->state)
    {
        cui_iv_imgadp_update_img_state(pImg, CUI_IV_IMGADP_IMG_STATE_FINISH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_draw_result
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  pImg        [?]
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_draw_result(cui_iv_cntx *pcui, cui_iv_imgadp_img_struct *pImg, S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_imgadp_img_state_enum state = CUI_IV_IMGADP_IMG_STATE_DECODING;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == result && CUI_IV_IMGADP_IMG_STATE_DECODING == pImg->state)
    {
        if (CUI_IV_IMGADP_FLAG_IS_ANIM(pImg) && GDI_NULL_HANDLE == pImg->gdiHdl)
            state = CUI_IV_IMGADP_IMG_STATE_PREVIEW;
        else
            state = CUI_IV_IMGADP_IMG_STATE_PLAY;

        CUI_IV_IMGADP_GET_IMG(pcui, pImg);
    }
    else if (0 == result)
        state = CUI_IV_IMGADP_IMG_STATE_PLAY;
    else if (-1 == result)
        state = CUI_IV_IMGADP_IMG_STATE_ERR;

    cui_iv_imgadp_update_img_state(pImg, state);
}

#ifdef __MMI_IVF_IMGADP_ANIM_USE_TEMP_LAYER__


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_reset_temp_layer
 * DESCRIPTION
 *  To guarantee the temp layer is the same with destination layer
 * PARAMETERS
 *  pImg        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_reset_temp_layer(cui_iv_imgadp_img_struct *pImg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_LAYER_EMPTY_HANDLE != pImg->tempLyr)
    {
        gdi_layer_get_dimension_nb_concurrent(pImg->lyr, &width, &height);
        gdi_layer_resize_nb_concurrent(pImg->tempLyr, width, height);
        gdi_layer_push_and_set_active(pImg->tempLyr);
        gdi_bitblt(pImg->lyr, 0, 0, width - 1, height - 1, 0, 0);
        gdi_layer_pop_and_restore_active();
    }
}
#endif

#if !defined(__MMI_IVF_CACHE__) || defined(__MMI_IVF_ANIM_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_before_draw_cb
 * DESCRIPTION
 *  This is before draw callback function of any type of image, not just for animation.
 * PARAMETERS
 *  result      [IN]
 *  handle      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_before_draw_cb(GDI_RESULT result, GDI_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_imgadp_img_struct *pImg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_GDI_BEFORE_DRAW, result, handle);

    pImg = cui_iv_imgadp_get_img_from_gdiHdl(handle);
    if (!CUI_IV_IMGADP_IMG_VALID(pImg))
        return;

    gdi_layer_clear(GDI_COLOR_BLACK);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_dec_done_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 *  handle      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_dec_done_cb(GDI_RESULT result, GDI_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui;
    cui_iv_imgadp_img_struct *pImg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_GDI_DEC_DONE, result, handle);

    pcui = cui_iv_get_context();
    if (!pcui)
        return;

    pImg = cui_iv_imgadp_get_img_from_gdiHdl(handle);
    if (!CUI_IV_IMGADP_IMG_VALID(pImg))
        return;

    if (GDI_SUCCEED == result)
        cui_iv_imgadp_draw_result(pcui, pImg, 0);
    else
        cui_iv_imgadp_draw_result(pcui, pImg, -1);
}
#endif /* !defined(__MMI_IVF_CACHE__) || defined(__MMI_IVF_ANIM_SUPPORT__) */

#ifdef __MMI_IVF_ANIM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_anim_handle_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  anim_handle     [IN]
 *  handle          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_anim_handle_cb(GDI_HANDLE anim_handle, GDI_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_imgadp_img_struct *pImg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_GDI_ANIM_HANDLE, anim_handle, handle);

    pImg = cui_iv_imgadp_get_img_from_gdiHdl(handle);
    if (!CUI_IV_IMGADP_IMG_VALID(pImg))
        return;
    pImg->animHdl = anim_handle;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_anim_each_frame_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_anim_each_frame_cb(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    cui_iv_cntx *pcui;
    cui_iv_scrndata *pscrn;
    cui_iv_imgadp_struct *pImgAdp;
    cui_iv_imgadp_img_struct *pImg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_GDI_ANIM_EACH_FRAME, result);

    pcui = cui_iv_get_context();
    if (!pcui)
        return;

    pscrn = &pcui->scrn_data;
    pImgAdp = &pscrn->imgAdp;
    for (i = 0; i < CUI_IV_IMGADP_IMG_COUNT; i++)
    {
        pImg = &pImgAdp->imgList[i];

        /* Trap:maybe not only one image at paly state */
        if (CUI_IV_IMGADP_FLAG_IS_ANIM(pImg) &&
            (CUI_IV_IMGADP_IMG_STATE_PLAY == pImg->state ||
            CUI_IV_IMGADP_IMG_STATE_FINISH == pImg->state))
            break;
    }
    if (i >= CUI_IV_IMGADP_IMG_COUNT)
        return;

    if (result == GDI_SUCCEED)
    {
        if (CUI_IV_IMGADP_GET_ANIM_LAYER(pImg) != pImg->lyr)
        {
            gdi_layer_push_and_set_active(pImg->lyr);
            gdi_bitblt(
                CUI_IV_IMGADP_GET_ANIM_LAYER(pImg),
                pImg->x,
                pImg->y,
                pImg->x + pImg->w - 1,
                pImg->y + pImg->h - 1,
                pImg->x,
                pImg->y);
            gdi_layer_pop_and_restore_active();
        }
        gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_anim_finish_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_anim_finish_cb(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui;
    cui_iv_scrndata *pscrn;
    cui_iv_imgadp_img_struct *pImg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_GDI_ANIM_FINISH, result);

    pcui = cui_iv_get_context();
    if (!pcui)
        return;

    pscrn = &pcui->scrn_data;
    /* Trap:pImg, it can works due to only slide care the finish event */
    pImg = pscrn->slide_data.pCurrImg;
    if (!CUI_IV_IMGADP_IMG_VALID(pImg))
        return;

    cui_iv_imgadp_update_img_state(pImg, CUI_IV_IMGADP_IMG_STATE_FINISH);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_anim_draw
 * DESCRIPTION
 *
 * PARAMETERS
 *  pImg        [?]
 *  pfile       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_anim_draw(cui_iv_imgadp_img_struct *pImg, WCHAR *pfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_nb_set_done_callback(cui_iv_imgadp_dec_done_cb);
    /* This setting is for any type of image, not just for animation. */
    gdi_nb_set_anim_before_frame_callback(cui_iv_imgadp_before_draw_cb);
    gdi_nb_set_anim_handle_query_callback(cui_iv_imgadp_anim_handle_cb);
    gdi_nb_set_anim_after_each_frame_callback(cui_iv_imgadp_anim_each_frame_cb);
    gdi_nb_set_anim_last_frame_callback(cui_iv_imgadp_anim_finish_cb);
    gdi_nb_set_blt((BOOL) MMI_FALSE, (BOOL) MMI_FALSE);

    gdi_layer_push_and_set_active(CUI_IV_IMGADP_GET_ANIM_LAYER(pImg));
    pImg->gdiHdl = gdi_anim_nb_draw_resized_file(pImg->x, pImg->y, pImg->w, pImg->h, pfile);
    gdi_layer_pop_and_restore_active();

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_GDI_ANIM_DRAW, pImg->index, pImg->gdiHdl);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_anim_check
 * DESCRIPTION
 *
 * PARAMETERS
 *  pfile       [IN]
 * RETURNS
 *
 *****************************************************************************/
static U16 cui_iv_imgadp_anim_check(const WCHAR *pfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_anim = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_gif_check_animation_file((CHAR*) pfile, &is_anim);

    return (U16) (is_anim);
}
#endif /* __MMI_IVF_ANIM_SUPPORT__ */

#ifdef __MMI_IVF_CACHE__


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_get_img_from_index
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  index       [IN]
 * RETURNS
 *
 *****************************************************************************/
static cui_iv_imgadp_img_struct *cui_iv_imgadp_get_img_from_index(cui_iv_cntx *pcui, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    cui_iv_scrndata *pscrn = &pcui->scrn_data;
    cui_iv_imgadp_struct *pImgAdp = &pscrn->imgAdp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CUI_IV_IMGADP_IMG_COUNT; i++)
    {
        if (index == pImgAdp->imgList[i].index)
            return &pImgAdp->imgList[i];
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_cache_decode_done_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  idx         [IN]
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_cache_decode_done_cb(cui_iv_cntx *pcui, S32 idx, S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    cui_iv_imgadp_img_struct *pImg = cui_iv_imgadp_get_img_from_index(pcui, idx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_CACHE_DEC_DONE, result, idx);

    if (!CUI_IV_IMGADP_IMG_VALID(pImg))
        return;

    if (CUI_IV_IMGADP_IMG_STATE_DECODING == pImg->state)
    {
        if (MMI_IVC_OK == result)
            ret = 0;
        else
            ret = -1;
        cui_iv_imgadp_draw_result(pcui, pImg, ret);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_cache_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt     [?]
 * RETURNS
 *
 *****************************************************************************/
static S32 cui_iv_imgadp_cache_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_event_struct *ivcEvt = (mmi_ivc_event_struct*) evt;
    cui_iv_cntx *pcui = (cui_iv_cntx*) ivcEvt->user_data;
    S32 ret = MMI_IVC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    #if defined(__MMI_IVF_CACHE_DB__)
        case MMI_IVC_EVENT_GET_FOLDER:
        {
            /* Get app folder path. */
            S32 getFolderRet = cui_iv_get_folder_path(pcui, ivcEvt->data.folder.folderPath);

            if (1 == getFolderRet)
                ret = MMI_IVC_LOADING;
            if (-1 == getFolderRet)
                ret = MMI_IVC_ERR;
        }
            break;
    #endif /* defined(__MMI_IVF_CACHE_DB__) */

        case MMI_IVC_EVENT_GET_FILE:
        {
            /* Get specific filename. */
            S32 getFileRet = cui_iv_get_filename(pcui, ivcEvt->data.file.idx, ivcEvt->data.file.filepath, NULL, NULL);

            if (1 == getFileRet)
                ret = MMI_IVC_LOADING;
            if (-1 == getFileRet)
                ret = MMI_IVC_ERR;
        }
            break;

        case MMI_IVC_EVENT_DECODE:
        {
            /* Return decode result. */
            cui_iv_imgadp_cache_decode_done_cb(pcui, ivcEvt->data.decode.idx, ivcEvt->data.decode.result);
        }
            break;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_cache_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_cache_init(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;
    PU8 runBufPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (IV_CACHE_COUNT_IN_MED != 0)
    {
        S32 leftSize = IV_TOTAL_MED_MEMORY_SIZE;

        pscrn_data->cacheBufSize[IV_CACHE_SRC_TYPE_MED] = IV_CACHE_COUNT_IN_MED * IV_CACHE_SIZE_UNIT;
        leftSize = leftSize - pscrn_data->cacheBufSize[IV_CACHE_SRC_TYPE_MED];
        pscrn_data->cacheBufPtr[IV_CACHE_SRC_TYPE_MED] = pscrn_data->medMemPtr + leftSize;
    }
#endif /* (IV_CACHE_COUNT_IN_MED != 0) */

    {
        S32 leftSize = IV_TOTAL_SCREEN_MEMORY_SIZE;

    #if (IV_CACHE_COUNT_IN_SCR != 0)
        pscrn_data->cacheBufSize[IV_CACHE_SRC_TYPE_SCR] = IV_CACHE_COUNT_IN_SCR * IV_CACHE_SIZE_UNIT;
        leftSize = leftSize - pscrn_data->cacheBufSize[IV_CACHE_SRC_TYPE_SCR];
        pscrn_data->cacheBufPtr[IV_CACHE_SRC_TYPE_SCR] = pscrn_data->scrMemPtr + leftSize;
    #endif /* (IV_CACHE_COUNT_IN_SCR != 0) */
        leftSize = leftSize - MMI_IVC_RUN_BUF_SIZE;
        runBufPtr = pscrn_data->scrMemPtr + leftSize;
    }

    pscrn_data->decHdl = mmi_ivc_create(
                            pcui->index,
                            pcui->count,
                            runBufPtr,
                            MMI_IVC_RUN_BUF_SIZE,
                            cui_iv_imgadp_cache_proc,
                            (void*)pcui);

    if (IV_CACHE_SRC_TYPE_COUNT == 0)
        MMI_ASSERT(0);
    else
    {
        S32 idx;

        for (idx = 0; idx < IV_CACHE_SRC_TYPE_COUNT; idx++)
            mmi_ivc_add_memory(pscrn_data->decHdl, pscrn_data->cacheBufPtr[idx], pscrn_data->cacheBufSize[idx]);
    }

    mmi_ivc_start(pscrn_data->decHdl);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_cache_dec_img
 * DESCRIPTION
 *  Decode image to layer.
 * PARAMETERS
 *  pcui        [?]
 *  pfile       [IN]
 *  pImg        [?]
 * RETURNS
 *  1 -- decoding
 *  0 -- complete
 *  -1 -- error
 *****************************************************************************/
static S32 cui_iv_imgadp_cache_dec_img(cui_iv_cntx *pcui, const WCHAR *pfile, cui_iv_imgadp_img_struct *pImg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;
    S32 ivcRet;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_DEC_IMG);

    gdi_layer_clear_nb_concurrent(pImg->lyr, GDI_COLOR_BLACK);

    ivcRet = mmi_ivc_get_curr_img(pscrn_data->decHdl, pImg->lyr);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_DEC_IMG_RET, ivcRet);

    if (MMI_IVC_OK == ivcRet)
        result = 0;
    else if (MMI_IVC_DECODING == ivcRet)
        result = 1;
    else
        result = -1;

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_cache_get_img
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  dstLyr      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_cache_get_img(cui_iv_cntx *pcui, cui_iv_imgadp_img_struct *pImg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_scrndata *pscrn_data = &pcui->scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_clear_nb_concurrent(pImg->lyr, GDI_COLOR_BLACK);
    mmi_ivc_get_curr_img(pscrn_data->decHdl, pImg->lyr);
    if (CUI_IV_IMGADP_FLAG_IS_ANIM(pImg))
        CUI_IV_IMGADP_ANIM_DRAW(pImg, pcui->file_name);
}
#else /* __MMI_IVF_CACHE__ */


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_app_dec_img
 * DESCRIPTION
 *  Decode image to layer.
 * PARAMETERS
 *  pcui        [?]
 *  pfile       [IN]
 *  pImg        [?]
 * RETURNS
 *  1 -- decoding
 *  0 -- complete
 *  -1 -- error
 *****************************************************************************/
static S32 cui_iv_imgadp_app_dec_img(cui_iv_cntx *pcui, const WCHAR *pfile, cui_iv_imgadp_img_struct *pImg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_DEC_IMG);

    if (CUI_IV_IMGADP_FLAG_IS_ANIM(pImg))
    {
        CUI_IV_IMGADP_ANIM_DRAW(pImg, (WCHAR*) pfile);
    }
    else
    {
        gdi_nb_set_done_callback(cui_iv_imgadp_dec_done_cb);
        /* This setting is for any type of image, not just for animation. */
        gdi_nb_set_anim_before_frame_callback(cui_iv_imgadp_before_draw_cb);
        gdi_layer_push_and_set_active(pImg->lyr);
        gdi_push_and_set_alpha_blending_source_layer(pImg->lyr);
        pImg->gdiHdl = gdi_image_nb_draw_resized_file(pImg->x, pImg->y, pImg->w, pImg->h, pfile);
        gdi_pop_and_restore_alpha_blending_source_layer();
        gdi_layer_pop_and_restore_active();
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_DEC_IMG_RET, pImg->gdiHdl);

    return pImg->gdiHdl == GDI_NULL_HANDLE ? -1 : 1;
}
#endif /* __MMI_IVF_CACHE__ */


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_draw
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui            [?]
 *  pfile           [IN]
 *  pinfo           [?]
 *  h_layer         [IN]
 *  h_temp_layer    [IN]
 *  callback        [IN]
 *  userData        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_draw(
                cui_iv_cntx *pcui,
                const WCHAR *pfile,
                cui_iv_img_extinfo *pinfo,
                gdi_handle h_layer,
                gdi_handle h_temp_layer,
                cui_iv_imgadp_callback callback,
                void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 decRet = -1;
    cui_iv_scrndata *pscrn = &pcui->scrn_data;
    cui_iv_imgadp_struct *pImgAdp = &pscrn->imgAdp;
    cui_iv_imgadp_img_struct *pImg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CUI_IV_IMGADP_IMG_COUNT; i++)
    {
        pImg = &pImgAdp->imgList[i];

        if (CUI_IV_IMGADP_IMG_STATE_EXIT == pImg->state)
            break;
    }
    MMI_ASSERT(i < CUI_IV_IMGADP_IMG_COUNT);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_DRAW, pImg);

    pinfo->pImg = pImg;
    pImg->flag = 0;
    pImg->state = CUI_IV_IMGADP_IMG_STATE_DECODING;
    pImg->lyr = h_layer;
#ifdef __MMI_IVF_IMGADP_ANIM_USE_TEMP_LAYER__
    pImg->tempLyr = h_temp_layer;
#else
    pImg->tempLyr = GDI_LAYER_EMPTY_HANDLE;
#endif
    pImg->index = pcui->index;
    pImg->callback = callback;
    pImg->userData = userData;

    CUI_IV_IMGADP_RESET_TEMP_LAYER(pImg);

    if (MMI_TRUE == cui_iv_init_img_scrn_info(pinfo, pfile, pcui->img_base_info.img_orient))
    {
        pImg->x = pinfo->draw_x;
        pImg->y = pinfo->draw_y;
        pImg->w = pinfo->cur_w;
        pImg->h = pinfo->cur_h;

        if (pinfo->is_anim)
        {
            pImg->flag |= CUI_IV_IMGADP_FLAG_ANIM;
        }

        decRet = CUI_IV_IMGADP_START_DEC(pcui, pfile, pImg);
    }

    cui_iv_imgadp_draw_result(pcui, pImg, decRet);
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  pImg        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_stop(cui_iv_cntx *pcui, cui_iv_imgadp_img_struct *pImg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_STOP, pImg, pImg ? pImg->state : 0, pImg ? pImg->flag : 0);

    if (!CUI_IV_IMGADP_IMG_VALID(pImg))
        return;

    switch (pImg->state)
    {
        case CUI_IV_IMGADP_IMG_STATE_DECODING:
        case CUI_IV_IMGADP_IMG_STATE_PREVIEW:
        {
            if (CUI_IV_IMGADP_FLAG_IS_ANIM(pImg))
            {
                CUI_IV_IMGADP_ANIM_STOP_BY_HANDLE(pImg->gdiHdl);
                pImg->gdiHdl = GDI_NULL_HANDLE;
            }
            else
            {
                gdi_image_nb_stop(pImg->gdiHdl);
                pImg->gdiHdl = GDI_NULL_HANDLE;
            }
        }
            break;

        case CUI_IV_IMGADP_IMG_STATE_PLAY:
        case CUI_IV_IMGADP_IMG_STATE_FINISH:
        {
            if (CUI_IV_IMGADP_FLAG_IS_ANIM(pImg))
            {
                CUI_IV_IMGADP_ANIM_STOP_BY_LAYER(CUI_IV_IMGADP_GET_ANIM_LAYER(pImg));
            }
        }
            break;

        case CUI_IV_IMGADP_IMG_STATE_PAUSE:
        {
            if (CUI_IV_IMGADP_FLAG_IS_ANIM(pImg) && GDI_NULL_HANDLE != pImg->gdiHdl)
            {
                CUI_IV_IMGADP_ANIM_STOP_BY_LAYER(CUI_IV_IMGADP_GET_ANIM_LAYER(pImg));
            }
        }
            break;

        default:
            break;
    }

    memset(pImg, 0, sizeof(cui_iv_imgadp_img_struct));
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_pause
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  pImg        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_pause(cui_iv_cntx *pcui, cui_iv_imgadp_img_struct *pImg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_PAUSE, pImg, pImg ? pImg->state : 0, pImg ? pImg->flag : 0);

    if (!CUI_IV_IMGADP_IMG_VALID(pImg))
        return;

    switch (pImg->state)
    {
        case CUI_IV_IMGADP_IMG_STATE_PREVIEW:
        {
            if (CUI_IV_IMGADP_FLAG_IS_ANIM(pImg))
            {
                CUI_IV_IMGADP_ANIM_STOP_BY_HANDLE(pImg->gdiHdl);
                pImg->gdiHdl = GDI_NULL_HANDLE;
            }
            cui_iv_imgadp_update_img_state(pImg, CUI_IV_IMGADP_IMG_STATE_PAUSE);
        }
            break;

        case CUI_IV_IMGADP_IMG_STATE_PLAY:
        case CUI_IV_IMGADP_IMG_STATE_FINISH:
        {
            if (CUI_IV_IMGADP_FLAG_IS_ANIM(pImg))
            {
                CUI_IV_IMGADP_ANIM_PAUSE(pImg->animHdl);
            }
            cui_iv_imgadp_update_img_state(pImg, CUI_IV_IMGADP_IMG_STATE_PAUSE);
        }
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_imgadp_resume
 * DESCRIPTION
 *
 * PARAMETERS
 *  pcui        [?]
 *  pImg        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_imgadp_resume(cui_iv_cntx *pcui, cui_iv_imgadp_img_struct *pImg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_IMGADP_RESUME, pImg, pImg ? pImg->state : 0, pImg ? pImg->flag : 0);

    if (!CUI_IV_IMGADP_IMG_VALID(pImg))
        return;

    switch (pImg->state)
    {
        case CUI_IV_IMGADP_IMG_STATE_PAUSE:
        {
            if (CUI_IV_IMGADP_FLAG_IS_ANIM(pImg))
            {
                /* Cause after pause, APP may use temp layer to do something, so need to reset it */
                CUI_IV_IMGADP_RESET_TEMP_LAYER(pImg);

                if (GDI_NULL_HANDLE != pImg->gdiHdl)
                {
                    /* Before pause, the image is playing */
                    CUI_IV_IMGADP_ANIM_RESUME(pImg->animHdl);
                    cui_iv_imgadp_update_img_state(pImg, CUI_IV_IMGADP_IMG_STATE_PLAY);
                }
                else
                {
                    /*
                     * Before pause, the image is not playing:
                     * cui_iv_imgadp_pause will set gdiHdl to GDI_NULL_HANDLE
                     */
                    S32 decRet = -1;

                    /*
                     * Must set before dec, cause dec may directly reture ok
                     * cui_iv_imgadp_draw_result also check this state
                     */
                    pImg->state = CUI_IV_IMGADP_IMG_STATE_DECODING;

                    /* Trap:pcui->file_name, maybe it is not match to the pImg */
                    decRet = CUI_IV_IMGADP_START_DEC(pcui, pcui->file_name, pImg);
                    cui_iv_imgadp_draw_result(pcui, pImg, decRet);
                }
            }
            else
                cui_iv_imgadp_update_img_state(pImg, CUI_IV_IMGADP_IMG_STATE_FINISH);
        }
            break;

        default:
            break;
    }
}

#endif /* __MMI_IVF_IMGADP__ */


#ifdef __MMI_SNS_PHOTO_UPLOAD__
/*****************************************************************************
 * FUNCTION
 *  mmi_iv_sns_photo_upload_check
 * DESCRIPTION
 *  check limit for image
 * PARAMETERS
 *  const WCHAR* filepath
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_iv_sns_photo_upload_check(const WCHAR* filepath)
{
    FS_HANDLE hd;
    CHAR *error_str_ptr;

    MMI_ASSERT(filepath != NULL);
    
    hd = FS_Open(filepath, FS_READ_ONLY);
    if (hd >= 0) {
        FS_Close(hd);
    }
    else {
        return MMI_FALSE;
    }
    
    if (MMI_FALSE == CUI_IV_DRM_CHECK_RIGHT(filepath))
    {
        return MMI_FALSE;
    }

    if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, (CHAR*) filepath, &error_str_ptr))
    {
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}
#endif /* __MMI_SNS_PHOTO_UPLOAD__ */


#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata,code
#endif

#endif /* defined(__MMI_IMAGE_VIEWER__) */

