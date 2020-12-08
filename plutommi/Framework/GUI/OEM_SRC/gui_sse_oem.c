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
 *  gui_sse_oem.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  GUI Screen switch effect
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "gdi_const.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "kal_public_api.h"
#include "gui.h"
#include "wgui_inputs.h"
#include "wgui.h"
#include "CustThemesRes.h"
#include "gui_switch.h"
#include "wgui_include.h"
#include "gui_data_types.h"
#include "wgui_title.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "string.h"
#include "MMI_fw_trc.h"
#include "mmi_fw_trc.h"
#include "kal_trace.h"
#include "gui_fixed_menuitems.h"
#include "wgui_fixed_menus.h"
#include "gui_fixed_menus.h"
#include "CustDataRes.h"
#include "gui_typedef.h"
#include "lcd_if.h"
#include "wgui_categories_enum.h"
#include "mmi_frm_input_gprot.h"
#include "MMI_features_switch.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalConstants.h"
#include "ProfilingEngine.h"

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_frm_prot.h"
#include "gui_effect_oem.h"

#include "gd_include.h"             /* for gd_color_from_rgb_16 */
#include "gdi_include.h"            /* for GDI_LAYER_ROTATE_0 */
#include "gdi_layer.h"
#include "wgui_draw_manager.h"      /* for dm_check_control_exist, DM_POPUP_BACKGROUND */
#include "gui_calendar.h"           /* for GUI_CALENDAR_FRAME_START_Y */


#if defined(__MMI_SCREEN_ROTATE__)
#include "ScreenRotationGprot.h"
#endif /* defined(__MMI_SCREEN_ROTATE__) */

#include "PhoneSetupGProts.h"
#include "UcmSrvGprot.h"            /* for SRV_UCM_CALL_XXX */

#if defined(__MMI_VUI_ENGINE__)
#include "framework\vadp_p2v_uc.h"
#endif /* defined(__MMI_VUI_ENGINE__) */

#if defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_VIDEO_RECORDER__)
#include "mdi_video.h"
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_VIDEO_RECORDER__) */

#include "mdi_camera.h"             /* for mdi_camera_is_ready_to_capture */

#if defined(__MMI_VIDEO_PLAYER__)
#include "VdoPlyResDef.h"           /* for SCR_ID_VDOPLY_APP */
#include "mmi_rp_app_vdoply_def.h"  /* for SCR_ID_VDOPLY_APP */
#endif /* defined(__MMI_VIDEO_PLAYER__) */


#include "BootupSrvGprot.h"         /* for srv_bootup_is_completed */

#if defined(__J2ME__)
#include "JavaAgencyGprot.h"        /* for mmi_java_is_installing */
#endif /* defined(__J2ME__) */

#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#include "vapp_ncenter_gprot.h"
#endif
#include "DialerGprot.h"
/* for test bed */
#include "wgui_categories_util.h"   /* for GetHighlightedItem */
#include "gui_themes.h"             /* for MMI_medium_font & UI_COLOR_WHITE */
#include "wgui_categories_list.h"   /* for ShowCategory353Screen */
#include "CommonScreens.h"          /* for gIndexIconsImageList */

#include "ui_buffer.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

#if defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__)
#include "vfx_system.h"
extern void vcpSseRunSsePluto(void);
extern void vcpSseRunSse(void);
extern void vcpSseBuildOldScreen(void);
extern void vcpSseBuildNewScreen(void);
extern void vcpSseSetupScenario(gui_sse_scenario_enum scenario);
extern void vcpSseReset(void);
extern void vcpSseSetOpen();
#ifdef __MMI_REDUCED_UI_BUFFER__
extern MMI_BOOL vcpSseIsForcedCancel(void);
#endif
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/

#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
typedef struct
{
    gui_sse_scenario_enum scenario;
    gui_screen_switch_effect_type_enum effect;
} gui_sse_scenario_effect_table_struct;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) */

/***************************************************************************** 
 * Extern
 *****************************************************************************/

#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
/* matrix main menu expanding effect */
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__)
extern U16 gMainMenuAnimation[];
extern S32 matrix_mm_active_image_num;
extern gui_image_text_rect matrix_mm_rect[];
#endif /* defined(__MMI_MAINMENU_MATRIX_SUPPORT__) */

extern void gui_effect_clear_blt_rect(void);
extern void gui_effect_projective_transform_set_subsample_mode(gui_effect_projective_transform_subsample_mode_enum mode);
extern void gui_effect_affine_transform_set_subsample_mode(gui_effect_affine_transform_subsample_mode_enum mode);
extern void gui_effect_mem_manager_create(gui_effect_memory_manager_struct *mem_manager, void *buf, S32 size);
extern void gui_screen_switch_effect_draw_world(void);
extern void gui_smooth_scrolling_effect_post_exit_category(void);
extern void wgui_category_sse_register_popup_sliding(void);
extern U8 *dm_get_base_control_set(void);

extern U32 mmi_frm_get_screen_level(U16 scrn_id);
extern S32 mmi_frm_screen_get_direction(void);
#endif

extern void gui_smooth_scrolling_effect_run(void);
extern void gui_smooth_scrolling_effect_setup(S32 category_id, S32 category_flag, S32 category_redraw);

#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
extern MMI_BOOL mmi_frm_screen_is_sse_backup_on(void);
#endif

/***************************************************************************** 
 * Function Declaration
 *****************************************************************************/

#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY)
void gui_screen_switch_effect_create_object(gui_screen_switch_effect_object_struct *object, S32 id, S32 width, S32 height, S32 bpp, S32 z, PU8 buf, gui_screen_switch_effect_object_get_param_funcptr get_param_callback);
void gui_screen_switch_effect_create_object_layer(gui_screen_switch_effect_object_struct *object, gdi_handle *layer);
void gui_screen_switch_effect_create_world(void);
void gui_screen_switch_effect_close_world(void);
void gui_screen_switch_effect_object_get_param_callback(gui_screen_switch_effect_object_struct *object, gui_screen_switch_effect_param_struct *param, S32 time);
void gui_screen_switch_effect_register_finish_callback(gui_screen_switch_effect_finish_callback_funcptr_type finish_callback);
#endif 
void gui_sse_setup_scenario(gui_sse_scenario_enum scenario);

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* also used in gui_effect_oem.c for SSK */


MMI_BOOL g_gui_screen_switch_effect_is_to_clear_key = MMI_FALSE;
MMI_BOOL g_gui_screen_switch_effect_enable_early_key_break = MMI_FALSE;
S32 g_gui_screen_switch_effect_frames = 0;
S32 g_gui_screen_switch_effect_frame_duration = 0;
gui_rect g_gui_screen_switch_effect_world_view_rect = {0};
gui_screen_switch_effect_param_struct g_gui_screen_switch_effect_object_param[GUI_SCREEN_SWITCH_EFFECT_MAX_OBJECT_NUM][GUI_SCREEN_SWITCH_EFFECT_MAX_FRAME_NUM] = {0};
gui_screen_switch_effect_object_struct g_gui_screen_switch_effect_object[GUI_SCREEN_SWITCH_EFFECT_MAX_OBJECT_NUM] = {0};


/* also used in gui_effect_arm_oem.c */
MMI_BOOL g_gui_screen_switch_effect_is_key_pressed = MMI_FALSE;
S32 g_gui_screen_switch_effect_type = 0;
S32 g_gui_screen_switch_effect_object_num = 0;
S32 g_gui_screen_switch_effect_current_frame_index = 0;
gui_effect_memory_manager_struct g_gui_screen_switch_effect_tmp_mem = {0};
gui_screen_switch_effect_world_struct g_gui_sse_world = {MMI_FALSE,0};
gui_screen_switch_effect_finish_callback_funcptr_type g_gui_screen_switch_effect_finish_callback = NULL;

/* used even no SSE */
static BOOL g_gui_screen_switch_effect_is_lcd_freeze = FALSE;
static S32 g_gui_screen_switch_effect_frame_lock_count = 0;

/* dummy temp buffer c for linking. DO NOT REMOVE ME. */
#ifndef __MMI_SCREEN_SWITCH_EFFECT__
static U32 g_gui_screen_switch_effect_buf_c[1];
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */

#if defined(__MMI_SCREEN_SWITCH_EFFECT__)

/* SSE variables */
static MMI_BOOL g_gui_screen_switch_effect_enable = MMI_TRUE;
static gui_sse_scenario_enum g_gui_sse_scenario = GUI_SSE_SCENARIO_NONE;


static S32 g_gui_sse_prev_category_id = 0;
static S32 g_gui_sse_category_id = 0;
#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
static gui_sse_owner_draw_frame_callback_funcptr_type g_gui_sse_owner_draw_frame_callback = NULL;
static gui_screen_switch_effect_error_enum g_gui_screen_switch_effect_error_code = GUI_SSE_ERROR_NONE;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) */

static MMI_BOOL g_gui_sse_is_block_enable = MMI_FALSE;
#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
static MMI_BOOL g_gui_sse_is_force_block = MMI_FALSE;
static MMI_BOOL g_gui_sse_is_force_enable_effect = MMI_FALSE;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) */
static MMI_BOOL g_gui_sse_is_dummy_screen = MMI_FALSE;
static MMI_BOOL g_gui_sse_is_small_screen = MMI_FALSE;


#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
static U16 g_gui_screen_switch_effect_previous_screen_id = 0;
static S32 g_gui_sse_previous_category_id = 0;

static gui_sse_custom_callback_funcptr_type g_gui_sse_custom_callback = NULL;
static MMI_BOOL g_gui_screen_switch_effect_from_MM = MMI_FALSE;

static void (*g_gui_sse_pre_launch_func)(void) = NULL;
static void (*g_gui_sse_post_launch_func)(void) = NULL;
static void (*g_gui_sse_no_run_func)(void) = NULL;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) */

#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
/* matrix main menu expanding effect */
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__)
static gui_effect_point_struct g_gui_sse_matrix_menu_menu_icon_start_points[12] = {0};
static gui_effect_point_struct g_gui_sse_matrix_menu_menu_icon_end_points[12] = {0};
#endif /* defined(__MMI_MAINMENU_MATRIX_SUPPORT__) */

#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) */

#if defined(__MMI_SCREEN_ROTATE__)
static mmi_frm_screen_rotate_enum g_gui_screen_switch_effect_previous_rotation = MMI_FRM_SCREEN_ROTATE_0;
#endif /* defined(__MMI_SCREEN_ROTATE__) */

/* 3 main lcd size buffer */
#ifdef __MTK_TARGET__
#pragma arm section zidata = "DYNAMICCACHEABLEZI_NC"
#endif

#ifndef __MTK_TARGET__
#define __align(X)
#endif
//__align(__MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__) static U32 g_gui_screen_switch_effect_buf[GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE / 2];
//static U32 *g_gui_screen_switch_effect_buf_b = g_gui_screen_switch_effect_buf;
//static U32 *g_gui_screen_switch_effect_buf_a = g_gui_screen_switch_effect_buf + GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE / 4;

static U32 *g_gui_screen_switch_effect_buf_b = NULL;
static U32 *g_gui_screen_switch_effect_buf_a = NULL;

//__align(__MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__) static U32 g_gui_screen_switch_effect_buf_b[GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE / 4];    /* NEW SCREEN */
//__align(__MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__) static U32 g_gui_screen_switch_effect_buf_a[GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE / 4];    /* OLD SCREEN */

/*
 * Additional memory size (GUI_SCREEN_SWITCH_EFFECT_TEMP_BUFFER_SIZE - GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE) 
 * is reserved for output rectangle errors of affine and projective transform.
 */
#if defined(__COSMOS_MMI_PACKAGE__)

static U8 *g_gui_screen_switch_effect_buf_c = NULL;
static U8 *g_gui_sse_tmp_buffer = NULL;

#else /* defined(__COSMOS_MMI_PACKAGE__) */

__align(__MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__) static U32 g_gui_screen_switch_effect_buf_c[GUI_SCREEN_SWITCH_EFFECT_TEMP_BUFFER_SIZE / 4];

/* temporary buffer for non-blocking blt and misc usage */
//#if (__MMI_UI_MEMORY_PROFILE__ > 3)
//__align(__MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__) static U32 g_gui_sse_tmp_buffer[GUI_SCREEN_SWITCH_EFFECT_TEMP_BUFFER_SIZE / 4];
//#endif

#endif /* defined(__COSMOS_MMI_PACKAGE__) */

#ifdef __MTK_TARGET__
#pragma arm section zidata
#endif

#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)

static const gui_sse_effect_selection_struct g_gui_sse_effect_selection_table_full[] = 
{
    /* END OF EFFECT SELECTION TABLE. DO NOT MODIFY! */
    GUI_SSE_EFFECT_SELECTION_END    
};


static const gui_sse_effect_selection_struct g_gui_sse_effect_selection_table_simple[] = 
{
    /* END OF EFFECT SELECTION TABLE. DO NOT MODIFY! */
    GUI_SSE_EFFECT_SELECTION_END    
};

const static gui_sse_scenario_effect_table_struct g_gui_sse_scenario_effect_tbl [] =
{
    /* idle screen */
    {GUI_SSE_SCENARIO_ENTER_IDLE, GUI_SCREEN_SWITCH_EFFECT_NONE},
    {GUI_SSE_SCENARIO_FROM_IDLE, GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_UP},

#if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
    {GUI_SSE_SCENARIO_FROM_IDLE_SHORTCUT, GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_UP},
#endif /* defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */

#if defined(__MMI_VUI_ENGINE__)
    {GUI_SSE_SCENARIO_FROM_VENUS_HS_WIDGET, GUI_SCREEN_SWITCH_EFFECT_FLIP_CLOCK_WISE},
    {GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT, GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_UP},
#endif /* defined(__MMI_VUI_ENGINE__) */

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    {GUI_SSE_SCENARIO_FROM_OP11_HS, GUI_SCREEN_SWITCH_EFFECT_OP11_HS_SLIDING},
    {GUI_SSE_SCENARIO_FROM_OP11_HS_POPUP, GUI_SCREEN_SWITCH_EFFECT_OP11_HS_FADEIN},
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

    /* main menu */
#if (defined(__CPU_ARM7EJ_S__) || defined(__MMI_VUI_3D_MAINMENU__) || defined(__MMI_VUI_LAUNCHER_KEY__))
    {GUI_SSE_SCENARIO_FROM_MAINMENU, GUI_SCREEN_SWITCH_EFFECT_ZOOM_AND_BLEND_IN},
#else
    {GUI_SSE_SCENARIO_FROM_MAINMENU, GUI_SCREEN_SWITCH_EFFECT_CUBE_CLOCK_WISE},
#endif
#if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
    {GUI_SSE_SCENARIO_IDLE_SHORTCUT_TO_MAINMENU, GUI_SCREEN_SWITCH_EEFECT_ICON_FLIP},
#endif /* defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */
    {GUI_SSE_SCENARIO_ENTER_MAINMENU, GUI_SCREEN_SWITCH_EFFECT_BLEND_IN},

    /* photowall */
#if defined(__MMI_VUI_MEDIAWALL__)
    {GUI_SSE_SCENARIO_FROM_PHOTOWALL_TO_IMGVIEWER, GUI_SCREEN_SWITCH_EFFECT_SLIDE_LEFT},
#endif /* defined(__MMI_VUI_MEDIAWALL__) */

#if !defined(__COSMOS_MMI_PACKAGE__)
    /* popup */
    {GUI_SSE_SCENARIO_SMALL_SCREEN_IN, GUI_SCREEN_SWITCH_EFFECT_BLEND_IN},
    {GUI_SSE_SCENARIO_SMALL_SCREEN_OUT, GUI_SCREEN_SWITCH_EFFECT_BLEND_OUT},
#endif /* !defined(__COSMOS_MMI_PACKAGE__) */

#if defined(__MMI_CALENDAR__)
    {GUI_SSE_SCENARIO_CALENDAR_PAGE_UP, GUI_SCREEN_SWITCH_EEFECT_CALENDAR_PAGE_UP},
    {GUI_SSE_SCENARIO_CALENDAR_PAGE_DOWN, GUI_SCREEN_SWITCH_EEFECT_CALENDAR_PAGE_DOWN},
#endif /* defined(__MMI_CALENDAR__) */

#if defined(__COSMOS_MMI_PACKAGE__)
#if defined(__MTK_TARGET__)
    {GUI_SSE_SCENARIO_COSMOS_APP_ENTRY, GUI_SCREEN_SWITCH_EFFECT_COSMOS_APP_ENTRY},
    {GUI_SSE_SCENARIO_COSMOS_APP_EXIT, GUI_SCREEN_SWITCH_EFFECT_COSMOS_APP_EXIT},
#endif /* defined(__MTK_TARGET__) */
    {GUI_SSE_SCENARIO_COSMOS_PAGE_ENTRY, GUI_SCREEN_SWITCH_EFFECT_SLIDE_LEFT/*GUI_SCREEN_SWITCH_EFFECT_COSMOS_PAGE_ENTRY*/},
    {GUI_SSE_SCENARIO_COSMOS_PAGE_EXIT, GUI_SCREEN_SWITCH_EFFECT_SLIDE_RIGHT/*GUI_SCREEN_SWITCH_EFFECT_COSMOS_PAGE_EXIT*/},
    {GUI_SSE_SCENARIO_COSMOS_MOVE_ENTRY, GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_DOWN},
    {GUI_SSE_SCENARIO_COSMOS_MOVE_EXIT, GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_UP},
#endif /* defined(__COSMOS_MMI_PACKAGE__) */

    {GUI_SSE_SCENARIO_NO_EFFECT, GUI_SCREEN_SWITCH_EFFECT_NONE}
};
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) */

#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */


/***************************************************************************** 
 * Local Function
 *****************************************************************************/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)

/*****************************************************************************
 * FUNCTION
 *  gui_sse_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_sse_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_REDUCED_UI_BUFFER__)
    g_gui_screen_switch_effect_buf_b = (U32*)ui_buffer_get_start_addr(UI_BUFFER_ID_GUI_SSE_BUF_B);
    g_gui_screen_switch_effect_buf_a = (U32*)ui_buffer_get_start_addr(UI_BUFFER_ID_GUI_SSE_BUF_A);
#else
	g_gui_screen_switch_effect_buf_b = (U32*)ui_buffer_get_start_addr(UI_BUFFER_ID_GDI_SBL);
	g_gui_screen_switch_effect_buf_a = NULL;
#endif 
}


#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_is_lcd_output_available
 * DESCRIPTION
 *  Checks whether the LCD is locked or freezed.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if LCD output is ok; otherwise, MMI_FALSE;
 *****************************************************************************/
static MMI_BOOL gui_screen_switch_effect_is_lcd_output_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 frame_buffer_lock_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do not run effects when the frame buffer is locked */
    gdi_layer_get_frame_buffer_lock_count(&frame_buffer_lock_count);

    /* not available if the frame buffer is locked or the LCD is freezed */
    if (frame_buffer_lock_count || gdi_lcd_get_freeze())
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_skip_beginning_frames
 * DESCRIPTION
 *  Skips the specified number of beginning frames
 * PARAMETERS
 *  skip_frame_num       [IN]   number of frames to be skipped
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_skip_beginning_frames(S32 skip_frame_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* make sure the skipping is feasible */
    MMI_ASSERT((skip_frame_num >= 0) && (skip_frame_num < g_gui_screen_switch_effect_frames));
    
    for (i = 0; i < g_gui_screen_switch_effect_frames - skip_frame_num; i++)
    {
        for (j = 0; j < g_gui_screen_switch_effect_object_num; j++)
        {        
            g_gui_screen_switch_effect_object_param[j][i] = g_gui_screen_switch_effect_object_param[j][i + skip_frame_num];
        }
    }

    g_gui_screen_switch_effect_frames -= skip_frame_num;
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_save_current_screen
 * DESCRIPTION
 *  Saves the current screen by flattening all DM layers.
 * PARAMETERS
 *  output_buf       [OUT]     output buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_save_current_screen(U8 *output_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;    
    gdi_handle snap_layer, layers[4];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_create_cf_using_outside_memory(
        GUI_SCREEN_SWITCH_EFFECT_LAYER_COLOR_FORMAT,
        0,
        0,
        UI_device_width,
        UI_device_height,
        &snap_layer,
        output_buf,
        UI_device_width * UI_device_height * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE);

    gdi_layer_push_and_set_active(snap_layer);
    gdi_layer_reset_clip();

    /* if DM layers are available, use DM layers; otherwise, use blt layers as flatten source layers */
    if (dm_is_activated())
    {
        gdi_layer_flatten(dm_get_layer_handle(0), dm_get_layer_handle(1), dm_get_layer_handle(2), dm_get_layer_handle(3));
    }
    else
    {
        gdi_layer_get_blt_layer(&layers[0], &layers[1], &layers[2], &layers[3]);
        for (i = 0; i < 4; i++)
        {
            /* do not touch the layer if it is already freed */
            // TODO: use GDI API
            if (layers[i] && !(((gdi_layer_struct*)layers[i])->flag & 1))
            {
                layers[i] = GDI_NULL_HANDLE;
            }
        }    

        gdi_layer_flatten(layers[0], layers[1], layers[2], layers[3]);
    }        
    
    gdi_layer_pop_and_restore_active();

    gdi_layer_free(snap_layer);
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_save_and_get_current_screen_buffer
 * DESCRIPTION
 *  save and get new screen buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
static U8* gui_sse_save_and_get_current_screen_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SEN", SA_start);
#endif
#if defined(__COSMOS_MMI_PACKAGE__)
    {
        gdi_handle layers[4], blt_layer = NULL;
        S32 count = 0, i;
        U8* buf_ptr = NULL;

        gdi_layer_get_blt_layer(&layers[0], &layers[1], &layers[2], &layers[3]);
        for (i = 0; i < 4; i++)
        {
            if (layers[i] && GDI_LAYER_GET_FLAG(layers[i], GDI_LAYER_FLAG_USED))
            {
                count++;
                blt_layer = layers[i];
            }
        }

        if (count == 1)
        {
            gdi_layer_push_and_set_active(blt_layer);
            if (gdi_layer_get_bit_per_pixel() == 16)
            {
                gdi_layer_get_buffer_ptr(&buf_ptr);
            }
            gdi_layer_pop_and_restore_active();
        }

        if (!buf_ptr)
        {
            gui_screen_switch_effect_save_current_screen((PU8)g_gui_screen_switch_effect_buf_b);
            return (U8*)g_gui_screen_switch_effect_buf_b;
        }
        else
        {
            return buf_ptr;
        }
    }
#else /* defined(__COSMOS_MMI_PACKAGE__) */
    gui_screen_switch_effect_save_current_screen((PU8)g_gui_screen_switch_effect_buf_b);
    return (U8*)g_gui_screen_switch_effect_buf_b;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SEN", SA_stop);
#endif
}

#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_save_wallpaper_layer
 * DESCRIPTION
 *  Saves the wallpaper layer to 
 * PARAMETERS
 *  buf                     [OUT]   output buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_save_wallpaper_layer(U8 *output_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle snap_layer;
    gdi_handle wallpaper_layer;
    BOOL        src_key_enable;
    gdi_color   src_key_color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wallpaper_layer = dm_get_wallpaper_layer();
    if (wallpaper_layer == GDI_ERROR_HANDLE)
    {
        GUI_SSE_SET_ERROR_CODE(GUI_SSE_ERROR_SUBMENU_SLIDE);
        
        return;
    }
    
   gdi_layer_create_cf_using_outside_memory(
        GUI_SCREEN_SWITCH_EFFECT_LAYER_COLOR_FORMAT,
        0,
        0,
        UI_device_width,
        UI_device_height,
        &snap_layer,
        output_buffer,
        UI_device_width * UI_device_height * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE);

    gdi_layer_push_and_set_active(wallpaper_layer);
    gdi_layer_get_source_key(&src_key_enable, &src_key_color);
    gdi_layer_set_source_key(FALSE, src_key_color);

    gdi_layer_push_and_set_active(snap_layer);
    
    gdi_layer_reset_clip();   
    gdi_layer_flatten_with_clipping(wallpaper_layer, 0, 0, 0);

    gdi_layer_pop_and_restore_active();
    
    gdi_layer_set_source_key(src_key_enable, src_key_color);
    gdi_layer_pop_and_restore_active();

    gdi_layer_free(snap_layer); 
}

#endif 
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) */

#if defined(__GUI_SSE_BACKUP_EFFECT_ON__) || defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_save_main_base_layer
 * DESCRIPTION
 *  Saves the main base layer to 
 * PARAMETERS
 *  buf                     [OUT]   output buffer
 *  save_content_area_only  [IN]    flag to save the content area
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_save_main_base_layer(U8 *output_buffer, MMI_BOOL save_content_area_only)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle snap_layer;
    gdi_handle base_layer;
    BOOL        src_key_enable;
    gdi_color   src_key_color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_create_cf_using_outside_memory(
        GUI_SCREEN_SWITCH_EFFECT_LAYER_COLOR_FORMAT,
        0,
        0,
        UI_device_width,
        UI_device_height,
        &snap_layer,
        output_buffer,
        UI_device_width * UI_device_height * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE);

    gdi_layer_get_base_handle(&base_layer);
    gdi_layer_push_and_set_active(base_layer);
    gdi_layer_get_source_key(&src_key_enable, &src_key_color);
    gdi_layer_set_source_key(FALSE, src_key_color);

    gdi_layer_push_and_set_active(snap_layer);
    gdi_layer_reset_clip();   

    /* clear things out of the content area and clear the scroll bar for submenu sliding. */
    // TODO: must check if the scrollbar is displayed or not.
    if (save_content_area_only)
    {
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        /* only clears the scrollbar (for better feeling) if there is a list menu */
        if (dm_check_control_exist(g_dm_data.s32CatId, DM_LIST1) ||
            dm_check_control_exist(g_dm_data.s32CatId, DM_DYNAMIC_LIST1) ||
            dm_check_control_exist(g_dm_data.s32CatId, DM_ASYNCDYNAMIC_LIST1)
#ifdef __MMI_FTE_SUPPORT__ 
            || 
            dm_check_control_exist(g_dm_data.s32CatId, DM_INLINE_FIXED_LIST1)
#endif
            )
        {   
            // TODO: should use the list menu coordinate instead of macros
            if (r2lMMIFlag)
            {
                gdi_layer_set_clip(
                    MMI_SUBMENU_CONTENT_X + current_MMI_theme->scrollbar_size, 
                    MMI_SUBMENU_CONTENT_Y, 
                    MMI_SUBMENU_CONTENT_X + MMI_SUBMENU_CONTENT_WIDTH - 1 + current_MMI_theme->scrollbar_size,
                    MMI_SUBMENU_CONTENT_Y + MMI_SUBMENU_CONTENT_HEIGHT - 1);        
            }
            else
            {
                gdi_layer_set_clip(
                    MMI_SUBMENU_CONTENT_X,
                    MMI_SUBMENU_CONTENT_Y, 
                    MMI_SUBMENU_CONTENT_X + MMI_SUBMENU_CONTENT_WIDTH - 1 - current_MMI_theme->scrollbar_size,
                    MMI_SUBMENU_CONTENT_Y + MMI_SUBMENU_CONTENT_HEIGHT - 1);
            }                
        } 
    }
    
    gdi_layer_flatten_with_clipping(base_layer, 0, 0, 0);

    gdi_layer_pop_and_restore_active();
    
    gdi_layer_set_source_key(src_key_enable, src_key_color);
    gdi_layer_pop_and_restore_active();

    gdi_layer_free(snap_layer); 
}

#endif
#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)

/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_match_selection_table
 * DESCRIPTION
 *  Find the match in the selection table by given screen IDs
 * PARAMETERS
 *  from_screen_id       [IN]   from screen id
 *  to_screen_id         [IN]   to screen id
 * RETURNS
 *  MMI_TRUE if the condition is matched; otherwise, MMI_FALSE.
 *****************************************************************************/
static const gui_sse_effect_selection_struct *gui_screen_switch_effect_match_selection_table(U16 from_screen_id, U16 to_screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_sse_effect_selection_struct *effect_selection_p;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (PhnsetGetScreenSwitchEffectStatus() == MMI_PHNSET_SSE_FULL)
    {
        effect_selection_p = &g_gui_sse_effect_selection_table_full[0];
    }
    else
    {
        effect_selection_p = &g_gui_sse_effect_selection_table_simple[0];
    }       

    /* lookup the effect selection table */
    for (;
         effect_selection_p->from_scr_id != GUI_SSE_EFFECT_SELECTION_INVALID_SCREEN_ID;
         effect_selection_p++)
    {
        if (((effect_selection_p->from_scr_id == GUI_SSE_EFFECT_SELECTION_DONT_CARE_SCREEN_ID) ||
             (from_screen_id == GUI_SSE_EFFECT_SELECTION_DONT_CARE_SCREEN_ID) ||
             (effect_selection_p->from_scr_id == from_screen_id)) &&
            ((effect_selection_p->to_scr_id == GUI_SSE_EFFECT_SELECTION_DONT_CARE_SCREEN_ID) ||
             (to_screen_id == GUI_SSE_EFFECT_SELECTION_DONT_CARE_SCREEN_ID) ||
             (effect_selection_p->to_scr_id == to_screen_id)))
        {
            return effect_selection_p;
        }
    }

    return NULL;
}

#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) */

#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_slide
 * DESCRIPTION
 *  Slide screen switch effect.
 * PARAMETERS
 *  effect_type       [IN]      effect type
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_slide(gui_screen_switch_effect_type_enum effect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 direction;
    S32 offset;
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gui_screen_switch_effect_create_world();    
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);

    /* no source key */
    g_gui_screen_switch_effect_object[0].enable_source_key = MMI_FALSE;
    g_gui_screen_switch_effect_object[1].enable_source_key = MMI_FALSE;

    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_FRAMES;

    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        if ((effect_type == GUI_SCREEN_SWITCH_EFFECT_SLIDE_LEFT) || (effect_type == GUI_SCREEN_SWITCH_EFFECT_SLIDE_UP))
        {
            direction = -1;
        }
        else
        {
            direction = 1;
        }

        if ((effect_type == GUI_SCREEN_SWITCH_EFFECT_SLIDE_LEFT) || (effect_type == GUI_SCREEN_SWITCH_EFFECT_SLIDE_RIGHT))
        {        
            offset = direction * UI_device_width * (i + 1) / (g_gui_screen_switch_effect_frames + 1);
            g_gui_screen_switch_effect_object_param[0][i].offset_x = offset;
            g_gui_screen_switch_effect_object_param[1][i].offset_x = -direction * UI_device_width + offset;     
        }
        else
        {
            offset = direction * UI_device_height * (i + 1) / (g_gui_screen_switch_effect_frames + 1);
            g_gui_screen_switch_effect_object_param[0][i].offset_y = offset;
            g_gui_screen_switch_effect_object_param[1][i].offset_y = -direction * UI_device_height + offset;          
        }
    }

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();
}

/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_zoom_and_blend_in
 * DESCRIPTION
 *  Zoom and blend in screen switch effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_zoom_and_blend_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S32     scale;
    S32     dst_w, dst_h;
    gui_screen_switch_effect_param_struct *param;
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     

    gui_screen_switch_effect_create_world();
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);

    /* no source key */
    g_gui_screen_switch_effect_object[0].enable_source_key = MMI_FALSE;
    g_gui_screen_switch_effect_object[1].enable_source_key = MMI_FALSE;

    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;

#if defined(__CPU_ARM7EJ_S__)
    g_gui_screen_switch_effect_frames = 5;   
#else /* defined(__CPU_ARM7EJ_S__) */
    g_gui_screen_switch_effect_frames = 7;   
#endif /* defined(__CPU_ARM7EJ_S__) */


    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        float x = 1.0f - (float)i / g_gui_screen_switch_effect_frames;
        float s = 1.0f - x*x*x;

        /* new frame */
        param = &g_gui_screen_switch_effect_object_param[1][i];

        /* zoom in */
        scale = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(s*0.2f + 0.8f);
        param->scale_x = param->scale_y = scale;

        /* center */
        dst_w = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT_MUL(scale, g_gui_screen_switch_effect_object[1].width);
        dst_h = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT_MUL(scale, g_gui_screen_switch_effect_object[1].height);
        
        param->offset_x = (UI_device_width - dst_w) / 2;
        param->offset_y = (UI_device_height - dst_h) / 2;

        param->opacity = (S32)(150 + 105*s);

        /* old frame */
        param = &g_gui_screen_switch_effect_object_param[0][i];
        x = (float)i / g_gui_screen_switch_effect_frames;
        s = x*x*x;
        param->opacity = (S32)(200 - 200*s);
    }

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_zoom_and_blend_out
 * DESCRIPTION
 *  Zoom and blend out screen switch effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_zoom_and_blend_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S32     scale;
    S32     dst_w, dst_h;
    gui_screen_switch_effect_param_struct *param;
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    gui_screen_switch_effect_create_world();
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);

    /* no source key */
    g_gui_screen_switch_effect_object[0].enable_source_key = MMI_FALSE;
    g_gui_screen_switch_effect_object[1].enable_source_key = MMI_FALSE;

    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_FRAMES;   

    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        float x = 1.0f - (float)i / g_gui_screen_switch_effect_frames;
        float s = x*x*x;

        /* old frame */
        param = &g_gui_screen_switch_effect_object_param[1][i];

        /* zoom out */
        scale = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(1.0f - s*0.2f);

        param->scale_x = param->scale_y = scale;        
        dst_w = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT_MUL(scale, g_gui_screen_switch_effect_object[1].width);
        dst_h = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT_MUL(scale, g_gui_screen_switch_effect_object[1].height);                

        /* center align */
        param->offset_x = (UI_device_width - dst_w) / 2;
        param->offset_y = (UI_device_height - dst_h) / 2;

        /* linear opacity degrading from 200 */
        param->opacity = (S32)(200 - 200*s);
        
        /* new frame */
        param = &g_gui_screen_switch_effect_object_param[0][i];
        s = 1.0f - x*x*x;
        param->opacity = (S32)(150 + 105*s);
    }
        
    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();        
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_flip
 * DESCRIPTION
 *  Flip screen switch effect.
 * PARAMETERS
 *  flip_direction  [IN]    flip direction
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_flip(gui_screen_switch_effect_type_enum flip_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    color theme_bg_color;
    gdi_color bg_color;
    S32 direction;
    S32 key_frame_index;

    #define GUI_SCREEN_SWITCH_EFFECT_FLIP_INITIAL_SKIP_FRAME_NUM 1   /* skip frames at first to speed up a little */
    #define GUI_SCREEN_SWITCH_EFFECT_FLIP_FRAME_NUM 8                /* total fames for flip */

    const U8 opacity_story[GUI_SCREEN_SWITCH_EFFECT_FLIP_FRAME_NUM] = {230, 200, 150, 110, 110, 150, 200, 230};

    /*
     * projection transform matrix
     *
     * Element layout:
     *      0 1 2
     *      3 4 5
     *      6 7 x
     */
    const float projective_transform_matrix[GUI_SCREEN_SWITCH_EFFECT_FLIP_FRAME_NUM * 8] = 
    {
    #if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
        0.848536F, 0.043933F, 0.000209F, -0.000000F, 1.000000F, -0.000000F, 24.000000F, 0.000000F,
        0.689540F, 0.092748F, 0.000453F, -0.000000F, 1.000000F, -0.000000F, 48.000000F, 0.000000F,
        0.523652F, 0.147305F, 0.000726F, -0.000000F, 1.000000F, -0.000000F, 72.000000F, 0.000000F,
        0.349582F, 0.208682F, 0.001033F, -0.000000F, 1.000000F, -0.000000F, 96.000000F, 0.000000F,
        0.081543F, -0.167364F, -0.000828F, -0.000000F, 0.802005F, -0.000000F, 96.000000F, 40.000000F,
        0.297732F, -0.125523F, -0.000619F, -0.000000F, 0.852130F, -0.000000F, 72.000000F, 30.000000F,
        0.523988F, -0.083682F, -0.000409F, -0.000000F, 0.902256F, -0.000000F, 48.000000F, 20.000000F,
        0.760311F, -0.041841F, -0.000199F, -0.000000F, 0.952381F, -0.000000F, 24.000000F, 10.000000F,
    #elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
        0.847941F, 0.035124F, 0.000206F, -0.000000F, 1.000000F, -0.000000F, 24.000000F, 0.000000F,
        0.688982F, 0.074152F, 0.000450F, -0.000000F, 1.000000F, -0.000000F, 48.000000F, 0.000000F,
        0.523136F, 0.117770F, 0.000723F, -0.000000F, 1.000000F, -0.000000F, 72.000000F, 0.000000F,
        0.349111F, 0.166841F, 0.001030F, -0.000000F, 1.000000F, -0.000000F, 96.000000F, 0.000000F,
        0.081846F, -0.133891F, -0.000826F, -0.000000F, 0.802508F, -0.000000F, 96.000000F, 32.000000F,
        0.298107F, -0.100418F, -0.000616F, -0.000000F, 0.852665F, -0.000000F, 72.000000F, 24.000000F,
        0.524442F, -0.066946F, -0.000407F, 0.000000F, 0.902821F, -0.000000F, 48.000000F, 16.000000F,
        0.760850F, -0.033473F, -0.000197F, -0.000000F, 0.952978F, -0.000000F, 24.000000F, 8.000000F,
    #elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
        0.846065F, 0.019716F, 0.000151F, 0.000000F, 1.000000F, 0.000000F, 32.000000F, 0.000000F,
        0.687333F, 0.041623F, 0.000334F, 0.000000F, 1.000000F, 0.000000F, 64.000000F, 0.000000F,
        0.521728F, 0.066107F, 0.000538F, 0.000000F, 1.000000F, 0.000000F, 96.000000F, 0.000000F,
        0.347962F, 0.093652F, 0.000767F, 0.000000F, 1.000000F, 0.000000F, 128.000000F, 0.000000F,
        0.082265F, -0.075235F, -0.000616F, 0.000000F, 0.803347F, 0.000000F, 128.000000F, 24.000000F,
        0.298422F, -0.056426F, -0.000459F, 0.000000F, 0.853556F, 0.000000F, 96.000000F, 18.000000F,
        0.524652F, -0.037618F, -0.000302F, 0.000000F, 0.903766F, 0.000000F, 64.000000F, 12.000000F,
        0.760955F, -0.018809F, -0.000144F, 0.000000F, 0.953975F, 0.000000F, 32.000000F, 6.000000F,      
    #elif defined(__MMI_MAINLCD_320X480__)
        // TODO: HVGA matrix, currently duplicated from 320x240
        /* 320 x 480 */
        0.846065F, 0.019716F, 0.000151F, 0.000000F, 1.000000F, 0.000000F, 32.000000F, 0.000000F,
        0.687333F, 0.041623F, 0.000334F, 0.000000F, 1.000000F, 0.000000F, 64.000000F, 0.000000F,
        0.521728F, 0.066107F, 0.000538F, 0.000000F, 1.000000F, 0.000000F, 96.000000F, 0.000000F,
        0.347962F, 0.093652F, 0.000767F, 0.000000F, 1.000000F, 0.000000F, 128.000000F, 0.000000F,
        0.082265F, -0.075235F, -0.000616F, 0.000000F, 0.803347F, 0.000000F, 128.000000F, 24.000000F,
        0.298422F, -0.056426F, -0.000459F, 0.000000F, 0.853556F, 0.000000F, 96.000000F, 18.000000F,
        0.524652F, -0.037618F, -0.000302F, 0.000000F, 0.903766F, 0.000000F, 64.000000F, 12.000000F,
        0.760955F, -0.018809F, -0.000144F, 0.000000F, 0.953975F, 0.000000F, 32.000000F, 6.000000F,
    #else
        /* 176 x 220 */
        0.847747F, 0.036099F, 0.000302F, 0.000000F, 1.000000F, 0.000000F, 18.000000F, 0.000000F,
        0.691169F, 0.069524F, 0.000606F, 0.000000F, 1.000000F, 0.000000F, 35.000000F, 0.000000F,
        0.524700F, 0.114378F, 0.001014F, 0.000000F, 1.000000F, 0.000000F, 53.000000F, 0.000000F,
        0.353701F, 0.156429F, 0.001396F, 0.000000F, 1.000000F, 0.000000F, 70.000000F, 0.000000F,
        0.086784F, -0.125714F, -0.001122F, 0.000000F, 0.803653F, 0.000000F, 70.000000F, 22.000000F,
        0.294090F, -0.097143F, -0.000861F, 0.000000F, 0.849315F, 0.000000F, 53.000000F, 17.000000F,
        0.528454F, -0.062857F, -0.000548F, 0.000000F, 0.904110F, 0.000000F, 35.000000F, 11.000000F,
        0.754651F, -0.034286F, -0.000287F, 0.000000F, 0.949772F, 0.000000F, 18.000000F, 6.000000F,
    #endif
    };
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      

    gui_screen_switch_effect_create_world();
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);
    
    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_FLIP_FRAME_NUM;

    /* use theme scr bg background color */
    if (current_MMI_theme->lite_disp_scr_bg_color)
    {
        theme_bg_color = *current_MMI_theme->lite_disp_scr_bg_color;
    }
    else
    {
        /* default BLACK if the theme component is NULL (should be impossible, though...) */
        theme_bg_color = UI_COLOR_BLACK;
    }

    /* SSE only supports 16-bit. */
    // TODO: This is dangerous?
    bg_color = gd_color_from_rgb_16(255, theme_bg_color.r, theme_bg_color.g, theme_bg_color.b);

    if (flip_direction == GUI_SCREEN_SWITCH_EFFECT_FLIP_COUNTERCLOCK_WISE)
    {
        direction = 1;
        key_frame_index = 0;
    }
    else
    {
        direction = -1;
        key_frame_index = GUI_SCREEN_SWITCH_EFFECT_FLIP_FRAME_NUM - 1;
    }

    /* old screen */
    for (i = 0; i < GUI_SCREEN_SWITCH_EFFECT_FLIP_FRAME_NUM / 2; i++)
    {
        g_gui_screen_switch_effect_object_param[0][i].transform_matrix = (float*)projective_transform_matrix + key_frame_index * 8;
        key_frame_index += direction;
        g_gui_screen_switch_effect_object_param[0][i].bg_color = bg_color;        
        g_gui_screen_switch_effect_object_param[0][i].opacity = (S32)opacity_story[i];  

        /* hide new screen */
        g_gui_screen_switch_effect_object_param[1][i].scale_x = 0;
    }

    /* new screen */
    for (i = GUI_SCREEN_SWITCH_EFFECT_FLIP_FRAME_NUM / 2; i < GUI_SCREEN_SWITCH_EFFECT_FLIP_FRAME_NUM; i++)
    {
        g_gui_screen_switch_effect_object_param[1][i].transform_matrix = (float*)projective_transform_matrix + key_frame_index * 8;
        key_frame_index += direction;        
        g_gui_screen_switch_effect_object_param[1][i].bg_color = bg_color;        
        g_gui_screen_switch_effect_object_param[1][i].opacity = (S32)opacity_story[i];  
        
        /* hide old screen */
        g_gui_screen_switch_effect_object_param[0][i].scale_x = 0;
    }

    /* skip beginning frames to speed up a little since the old screen is not so important */
    gui_screen_switch_effect_skip_beginning_frames(GUI_SCREEN_SWITCH_EFFECT_FLIP_INITIAL_SKIP_FRAME_NUM);

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();    
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_cube
 * DESCRIPTION
 *  Cube screen switch effect.
 * PARAMETERS
 *  cube_rotation_direction  [IN]    cube rotation direction
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_cube(gui_screen_switch_effect_type_enum cube_rotation_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    color theme_bg_color;
    gdi_color bg_color;
    S32 direction;
    S32 key_frame_index;

    #define GUI_SCREEN_SWITCH_EFFECT_CUBE_INITIAL_SKIP_FRAME_NUM 1   /* skip frames at first to speed up a little */
    #define GUI_SCREEN_SWITCH_EFFECT_CUBE_FRAME_NUM 5                /* total fames for cube */

    const U8 opacity_story[GUI_SCREEN_SWITCH_EFFECT_CUBE_FRAME_NUM] = {220, 200, 180, 160, 140};
    
    /*
     * projection transform matrix
     *
     * Element layout:
     *      0 1 2
     *      3 4 5
     *      6 7 x
     *
     * [Array layout]
     * frame 0 old screen matrix,
     * frame 0 new screen matrix,
     * ...
     * frame n old screen matrix,
     * frame n new screen matrix     
     */

    // TODO: support other resolution besides 240x400 and 240x320
    const float projective_transform_matrix[(GUI_SCREEN_SWITCH_EFFECT_CUBE_FRAME_NUM * 2) * 8] = 
    {
    #if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
        0.707493F, -0.171168F, -0.000856F, 0.000000F, 0.877193F, -0.000000F, -10.000000F, 25.000000F,
        0.756357F, 0.579337F, 0.002897F, -0.000000F, 1.102757F, -0.000000F, 200.000000F, -20.000000F,
        0.549910F, -0.242080F, -0.001195F, 0.000000F, 0.814536F, -0.000000F, -10.000000F, 40.000000F,
        0.945684F, 0.562916F, 0.002867F, -0.000000F, 1.140351F, -0.000000F, 170.000000F, -25.000000F,
        0.358348F, -0.303685F, -0.001485F, 0.000000F, 0.751880F, -0.000000F, -5.000000F, 50.000000F,
        1.098326F, 0.470711F, 0.002301F, -0.000000F, 1.165414F, -0.000000F, 125.000000F, -35.000000F,
        0.130071F, -0.345643F, -0.001728F, -0.000000F, 0.676692F, -0.000000F, 10.000000F, 65.000000F,
        1.223532F, 0.329656F, 0.001648F, -0.000000F, 1.152882F, -0.000000F, 70.000000F, -30.000000F,
        -0.007903F, -0.365411F, -0.001767F, -0.000000F, 0.651629F, -0.000000F, 25.000000F, 70.000000F,
        1.231321F, 0.260012F, 0.001195F, -0.000000F, 1.127820F, -0.000000F, 40.000000F, -30.000000F        
    #elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
        0.711297F, -0.133891F, -0.000837F, 0.000000F, 0.877743F, -0.000000F, -10.000000F, 20.000000F,
        0.732218F, 0.446304F, 0.002789F, -0.000000F, 1.097179F, -0.000000F, 200.000000F, -15.000000F,
        0.476252F, -0.218534F, -0.001300F, 0.000000F, 0.799373F, -0.000000F, -7.000000F, 35.000000F,
        1.040320F, 0.456447F, 0.002853F, -0.000000F, 1.159875F, -0.000000F, 155.000000F, -25.000000F,
        0.330879F, -0.253835F, -0.001562F, 0.000000F, 0.736677F, -0.000000F, -2.000000F, 45.000000F,
        1.190831F, 0.411588F, 0.002638F, -0.000000F, 1.175549F, -0.000000F, 123.000000F, -25.000000F,
        0.202250F, -0.272815F, -0.001640F, -0.000000F, 0.705329F, -0.000000F, 7.000000F, 50.000000F,
        1.211061F, 0.335572F, 0.002058F, -0.000000F, 1.159875F, -0.000000F, 91.000000F, -25.000000F,
        0.007408F, -0.267462F, -0.001695F, -0.000000F, 0.658307F, -0.000000F, 25.000000F, 55.000000F,
        1.203080F, 0.191195F, 0.001167F, -0.000000F, 1.106583F, -0.000000F, 45.000000F, -15.000000F
    #elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
        0.676954F, -0.095895F, -0.000763F, 0.000000F, 0.857741F, 0.000000F, -17.000000F, 20.000000F,
        0.800982F, 0.304410F, 0.002529F, 0.000000F, 1.133891F, 0.000000F, 263.000000F, -14.000000F,
        0.472058F, -0.135029F, -0.001086F, 0.000000F, 0.774059F, 0.000000F, -12.000000F, 30.000000F,
        1.048343F, 0.291457F, 0.002445F, 0.000000F, 1.184100F, 0.000000F, 212.000000F, -20.000000F,
        0.313171F, -0.150823F, -0.001236F, 0.000000F, 0.719665F, 0.000000F, -3.000000F, 36.000000F,
        1.154771F, 0.243858F, 0.002041F, 0.000000F, 1.188285F, 0.000000F, 160.000000F, -20.000000F,
        0.156254F, -0.166983F, -0.001369F, 0.000000F, 0.669456F, 0.000000F, 11.000000F, 42.000000F,
        1.267821F, 0.207851F, 0.001704F, 0.000000F, 1.188285F, 0.000000F, 108.000000F, -20.000000F,
        -0.000012F, -0.168492F, -0.001400F, 0.000000F, 0.627615F, 0.000000F, 31.000000F, 46.000000F,
        1.223677F, 0.127174F, 0.001030F, 0.000000F, 1.133891F, 0.000000F, 56.000000F, -14.000000F     
    #elif defined(__MMI_MAINLCD_320X480__)
        // TODO: HVGA matrix, currently duplicated from 320x240
        /* 320 x 480 */
        0.676954F, -0.095895F, -0.000763F, 0.000000F, 0.857741F, 0.000000F, -17.000000F, 20.000000F,
        0.800982F, 0.304410F, 0.002529F, 0.000000F, 1.133891F, 0.000000F, 263.000000F, -14.000000F,
        0.472058F, -0.135029F, -0.001086F, 0.000000F, 0.774059F, 0.000000F, -12.000000F, 30.000000F,
        1.048343F, 0.291457F, 0.002445F, 0.000000F, 1.184100F, 0.000000F, 212.000000F, -20.000000F,
        0.313171F, -0.150823F, -0.001236F, 0.000000F, 0.719665F, 0.000000F, -3.000000F, 36.000000F,
        1.154771F, 0.243858F, 0.002041F, 0.000000F, 1.188285F, 0.000000F, 160.000000F, -20.000000F,
        0.156254F, -0.166983F, -0.001369F, 0.000000F, 0.669456F, 0.000000F, 11.000000F, 42.000000F,
        1.267821F, 0.207851F, 0.001704F, 0.000000F, 1.188285F, 0.000000F, 108.000000F, -20.000000F,
        -0.000012F, -0.168492F, -0.001400F, 0.000000F, 0.627615F, 0.000000F, 31.000000F, 46.000000F,
        1.223677F, 0.127174F, 0.001030F, 0.000000F, 1.133891F, 0.000000F, 56.000000F, -14.000000F
    #else
        /* 176 x 220 */
        0.688160F, -0.134462F, -0.001176F, 0.000000F, 0.881279F, 0.000000F, -14.000000F, 14.000000F,
        0.773994F, 0.389738F, 0.003732F, 0.000000F, 1.109589F, 0.000000F, 134.000000F, -12.000000F,
        0.520771F, -0.184943F, -0.001655F, 0.000000F, 0.817352F, 0.000000F, -13.000000F, 21.000000F,
        0.991429F, 0.413534F, 0.003759F, 0.000000F, 1.150685F, 0.000000F, 110.000000F, -16.000000F,
        0.385962F, -0.218538F, -0.001935F, 0.000000F, 0.767123F, 0.000000F, -10.000000F, 27.000000F,
        1.148426F, 0.383731F, 0.003530F, 0.000000F, 1.159817F, 0.000000F, 87.000000F, -17.000000F,
        0.227092F, -0.235060F, -0.002094F, 0.000000F, 0.726027F, 0.000000F, -3.000000F, 31.000000F,
        1.220975F, 0.310790F, 0.002723F, 0.000000F, 1.146119F, 0.000000F, 58.000000F, -16.000000F,
        0.076698F, -0.242436F, -0.002178F, 0.000000F, 0.689498F, 0.000000F, 7.000000F, 35.000000F,
        1.244230F, 0.214933F, 0.001989F, 0.000000F, 1.114155F, 0.000000F, 33.000000F, -12.000000F
    #endif
    };
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      

    gui_screen_switch_effect_create_world();
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);

    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_CUBE_FRAME_NUM;

#if !defined(__CPU_ARM7EJ_S__)
    g_gui_screen_switch_effect_frame_duration += (g_gui_screen_switch_effect_frame_duration >> 2);
#endif

    /* use theme scr bg background color */
    if (current_MMI_theme->lite_disp_scr_bg_color)
    {
        theme_bg_color = *current_MMI_theme->lite_disp_scr_bg_color;
    }
    else
    {
        /* default BLACK if the theme component is NULL (should be impossible, though...) */
        theme_bg_color = UI_COLOR_BLACK;
    }

    /* SSE only supports 16-bit. */
    // TODO: This is dangerous?
    bg_color = gd_color_from_rgb_16(255, theme_bg_color.r, theme_bg_color.g, theme_bg_color.b);

    /* decide direction parameter */
    if (cube_rotation_direction == GUI_SCREEN_SWITCH_EFFECT_CUBE_CLOCK_WISE)
    {
        direction = 1;
        key_frame_index = 0;
    }
    else
    {
        direction = -1;
        key_frame_index = 2 * GUI_SCREEN_SWITCH_EFFECT_CUBE_FRAME_NUM - 1;
    }

    for (i = 0; i < GUI_SCREEN_SWITCH_EFFECT_CUBE_FRAME_NUM; i++)
    {    
        /* old screen */
        g_gui_screen_switch_effect_object_param[0][i].transform_matrix = (float*)projective_transform_matrix + key_frame_index * 8;
        key_frame_index += direction;
        g_gui_screen_switch_effect_object_param[0][i].bg_color = bg_color;        
        g_gui_screen_switch_effect_object_param[0][i].opacity = (S32)opacity_story[i];  

        /* new screen */
        g_gui_screen_switch_effect_object_param[1][i].transform_matrix = (float*)projective_transform_matrix + key_frame_index * 8;
        key_frame_index += direction;        
        g_gui_screen_switch_effect_object_param[1][i].bg_color = bg_color;
        g_gui_screen_switch_effect_object_param[1][i].opacity = (S32)opacity_story[GUI_SCREEN_SWITCH_EFFECT_CUBE_FRAME_NUM - 1 - i];
    }

#if defined(__CPU_ARM7EJ_S__)
    /* skip beginning frames to speed up a little since the old screen is not so important */
    gui_screen_switch_effect_skip_beginning_frames(GUI_SCREEN_SWITCH_EFFECT_CUBE_INITIAL_SKIP_FRAME_NUM);   
#endif

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();    
}

/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_move_in
 * DESCRIPTION
 *  Move in screen switch effect.
 * PARAMETERS
 *  effect_type       [IN]  move in effect type
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_move_in(gui_screen_switch_effect_type_enum effect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 offset_x, offset_y;
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // TODO: WORKAROUND FOR DIALER. PLEASE FIX ME
    g_gui_screen_switch_effect_is_to_clear_key = MMI_FALSE;

    gui_screen_switch_effect_create_world();    

    /* move in, new screen on top */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);
    
    /* no source key */
    g_gui_screen_switch_effect_object[0].enable_source_key = MMI_FALSE;
    g_gui_screen_switch_effect_object[1].enable_source_key = MMI_FALSE;

    /* best effort in order to reduce dialer SSE speed */
#if defined(__CPU_ARM7EJ_S__)
    g_gui_screen_switch_effect_frame_duration = 0;
#else /* defined(__CPU_ARM7EJ_S__) */
    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;
#endif /* defined(__CPU_ARM7EJ_S__) */
    
#if defined(__CPU_ARM7EJ_S__)
    g_gui_screen_switch_effect_frames = 4;
#else /* defined(__CPU_ARM7EJ_S__) */
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_FRAMES;
#endif /* defined(__CPU_ARM7EJ_S__) */

    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        offset_x = UI_device_width * (i + 1) / (g_gui_screen_switch_effect_frames + 1);
        offset_y = UI_device_height * (i + 1) / (g_gui_screen_switch_effect_frames + 1);

        switch (effect_type)
        {
            case GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_LEFT:
                g_gui_screen_switch_effect_object_param[1][i].offset_x = UI_device_width - offset_x;
                break;

            case GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_RIGHT:
                g_gui_screen_switch_effect_object_param[1][i].offset_x = -UI_device_width + offset_x;
                break;

            case GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_DOWN:
                g_gui_screen_switch_effect_object_param[1][i].offset_y = -UI_device_height + offset_y;
                break;

            case GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_UP:
                g_gui_screen_switch_effect_object_param[1][i].offset_y = UI_device_height - offset_y;
                break;

            default:
                MMI_ASSERT(0);
                break;
                
        }
    
    }

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();

    // TODO: WORKAROUND FOR DIALER. PLEASE FIX ME
    g_gui_screen_switch_effect_is_to_clear_key = MMI_TRUE;
}


#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/*****************************************************************************
 * FUNCTION
 *  gui_sse_op11_hs_sliding
 * DESCRIPTION
 *  sliding effect for op11 homescreen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sse_op11_hs_sliding(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define NUMBER_OF_OP11_HS_SLIDING_FRAMES    8

    S32 i;
    extern S32 MMI_softkey_height;
    S32 x[NUMBER_OF_OP11_HS_SLIDING_FRAMES] = {72, 60, 45, 36, 24, 12, 6, 0};    // percentage of total width
    S32 y[NUMBER_OF_OP11_HS_SLIDING_FRAMES] = {8, 6, 4, 2, 1, 1, 0, 0};       // shift from top
    S32 s[NUMBER_OF_OP11_HS_SLIDING_FRAMES] = {60, 70, 70, 80, 80, 90, 95, 100};
    S32 o[NUMBER_OF_OP11_HS_SLIDING_FRAMES] = {30, 50, 75, 110, 150, 200, 225, 255};
    S32 scale;
    gui_screen_switch_effect_param_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_screen_switch_effect_save_current_screen((PU8)g_gui_screen_switch_effect_buf_b);

    gui_screen_switch_effect_create_world();

    /* blt the area out of the main area of the new screen */
    gdi_lcd_freeze(TRUE);
    gdi_layer_blt_previous(0, 0, 0, 0);
    gdi_lcd_freeze(FALSE);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, MMI_status_bar_height - 1);
    gdi_layer_blt_previous(0, UI_device_height - MMI_softkey_height, UI_device_width - 1, UI_device_height);

    /* set view port to content area only (inluding the title) */
    GUI_RECT(g_gui_screen_switch_effect_world_view_rect, 0, MMI_status_bar_height, UI_device_width, (UI_device_height - MMI_status_bar_height - MMI_softkey_height));

    // previous screen
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0,
        UI_device_width, UI_device_height, 16, 0,
        (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);

    // main area of new screen
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1,
        UI_device_width, (UI_device_height - MMI_status_bar_height - MMI_softkey_height), 16, 0,
        (PU8)g_gui_screen_switch_effect_buf_b + (UI_device_width * MMI_status_bar_height * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE), gui_screen_switch_effect_object_get_param_callback);

    /* no source key */
    g_gui_screen_switch_effect_object[0].enable_source_key = MMI_FALSE;
    g_gui_screen_switch_effect_object[1].enable_source_key = MMI_FALSE;

    /* setup frame number and duration */
    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = NUMBER_OF_OP11_HS_SLIDING_FRAMES;

    /* setup each frame */
    for (i = 0; i < NUMBER_OF_OP11_HS_SLIDING_FRAMES; i++)
    {
        param = &g_gui_screen_switch_effect_object_param[1][i];

        scale = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(((float)s[i]/100));
        param->offset_x = UI_device_width * x[i] / 100;
        param->offset_y = MMI_status_bar_height + y[i];
        param->scale_x = scale;
        param->scale_y = scale;
        param->opacity = o[i];
    }

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();
}


/*****************************************************************************
 * gui_sse_op11_hs_fadein
 *  gui_sse_op11_hs_sliding
 * DESCRIPTION
 *  fade-in effect for op11 homescreen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sse_op11_hs_fadein(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define NUMBER_OF_OP11_HS_FADEIN_FRAMES     6

    S32 i, opacity;
    extern S32 MMI_softkey_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_screen_switch_effect_save_current_screen((PU8)g_gui_screen_switch_effect_buf_b);

    gui_screen_switch_effect_create_world();

    /* blt the area out of the main area of the new screen */
    gdi_lcd_freeze(TRUE);
    gdi_layer_blt_previous(0, 0, 0, 0);
    gdi_lcd_freeze(FALSE);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, MMI_status_bar_height - 1);
    gdi_layer_blt_previous(0, UI_device_height - MMI_softkey_height, UI_device_width - 1, UI_device_height);

    /* set view port to content area only (inluding the title) */
    GUI_RECT(g_gui_screen_switch_effect_world_view_rect, 0, MMI_status_bar_height, UI_device_width, (UI_device_height - MMI_status_bar_height - MMI_softkey_height));

    // previous screen
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0,
        UI_device_width, UI_device_height, 16, 0,
        (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);

    // main area of new screen
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1,
        UI_device_width, (UI_device_height - MMI_status_bar_height - MMI_softkey_height), 16, 0,
        (PU8)g_gui_screen_switch_effect_buf_b + (UI_device_width * MMI_status_bar_height * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE), gui_screen_switch_effect_object_get_param_callback);

    /* no source key */
    g_gui_screen_switch_effect_object[0].enable_source_key = MMI_FALSE;
    g_gui_screen_switch_effect_object[1].enable_source_key = MMI_FALSE;

    /* setup frame number and duration */
    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = NUMBER_OF_OP11_HS_FADEIN_FRAMES;

    /* setup each frame */
    opacity = 30;
    for (i = 0; i < NUMBER_OF_OP11_HS_FADEIN_FRAMES; i++)
    {
        g_gui_screen_switch_effect_object_param[1][i].offset_y = MMI_status_bar_height;
        g_gui_screen_switch_effect_object_param[1][i].opacity = opacity;
        opacity += 40;
        opacity = (opacity > 255) ? (255) : (opacity);
    }

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();
}
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */


#if defined(__COSMOS_MMI_PACKAGE__)
/*****************************************************************************
 * FUNCTION
 *  gui_sse_cosmos_app_entry
 * DESCRIPTION
 *  APP entry effect for Cosmos project
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sse_cosmos_app_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define NUMBER_OF_COSMOS_APP_ENTRY_FRAMES   10

    S32 i;
    float transform_matrix1[NUMBER_OF_COSMOS_APP_ENTRY_FRAMES][8];
    float transform_matrix2[NUMBER_OF_COSMOS_APP_ENTRY_FRAMES][8];
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init transform matrix */
    memset(transform_matrix1, 0, NUMBER_OF_COSMOS_APP_ENTRY_FRAMES * 8 * sizeof(float));
    memset(transform_matrix2, 0, NUMBER_OF_COSMOS_APP_ENTRY_FRAMES * 8 * sizeof(float));

    gui_screen_switch_effect_create_world();

    /* old screen & new screen */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);

    /* no source key */
    g_gui_screen_switch_effect_object[0].enable_source_key = MMI_FALSE;
    g_gui_screen_switch_effect_object[1].enable_source_key = MMI_FALSE;

    /* setup frame number and duration */
    g_gui_screen_switch_effect_frame_duration = 25;
    g_gui_screen_switch_effect_frames = NUMBER_OF_COSMOS_APP_ENTRY_FRAMES;

    /* setup each frame */
    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        gui_screen_switch_effect_param_struct *param;
        float x, s;

        x = 1.0f - (float)i / g_gui_screen_switch_effect_frames;

        /* old screen */
        param = &g_gui_screen_switch_effect_object_param[0][i];
        param->bg_color = GDI_COLOR_GRAY;

        s = 1.0f + 0.5f * (1.0f - x * x * x * x);

        // set opacity
        param->opacity = (S32)(255 * x * x * x * x);

        // set scale
        transform_matrix1[i][0] = transform_matrix1[i][4] = s;

        // set position
        transform_matrix1[i][6] = (UI_device_width - s * g_gui_screen_switch_effect_object[0].width) / 2;
        transform_matrix1[i][7] = UI_device_height * (s - 1);

        param->transform_matrix= transform_matrix1[i];

        /* new screen */
        param = &g_gui_screen_switch_effect_object_param[1][i];
        param->bg_color = GDI_COLOR_GRAY;

        s = 1.0f - x * x * x * x;

        // set opacity
        param->opacity = (S32)(255 * s);

        // set scale
        transform_matrix2[i][0] = transform_matrix2[i][4] = s;

        // set position
        transform_matrix2[i][6] = (UI_device_width - s * g_gui_screen_switch_effect_object[1].width) / 2;
        transform_matrix2[i][7] = (UI_device_height - s * g_gui_screen_switch_effect_object[1].height) / 2;

        param->transform_matrix= transform_matrix2[i];
    }

    /* skip beginning frames to speed up a little since the old screen is not so important */
    gui_screen_switch_effect_skip_beginning_frames(1);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SSE", SA_start);
#endif
    gui_screen_switch_effect_draw_world();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SSE", SA_stop);
#endif
    gui_screen_switch_effect_close_world();
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_cosmos_app_exit
 * DESCRIPTION
 *  APP exit effect for Cosmos project
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sse_cosmos_app_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define NUMBER_OF_COSMOS_APP_EXIT_FRAMES    10

    S32 i;
    float transform_matrix1[NUMBER_OF_COSMOS_APP_EXIT_FRAMES][8];
    float transform_matrix2[NUMBER_OF_COSMOS_APP_EXIT_FRAMES][8];
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init transform matrix */
    memset(transform_matrix1, 0, NUMBER_OF_COSMOS_APP_EXIT_FRAMES * 8 * sizeof(float));
    memset(transform_matrix2, 0, NUMBER_OF_COSMOS_APP_EXIT_FRAMES * 8 * sizeof(float));

    gui_screen_switch_effect_create_world();

    /* old screen & new screen */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);

    /* no source key */
    g_gui_screen_switch_effect_object[0].enable_source_key = MMI_FALSE;
    g_gui_screen_switch_effect_object[1].enable_source_key = MMI_FALSE;

    /* setup frame number and duration */
    g_gui_screen_switch_effect_frame_duration = 25;
    g_gui_screen_switch_effect_frames = NUMBER_OF_COSMOS_APP_EXIT_FRAMES;

    /* setup each frame */
    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        gui_screen_switch_effect_param_struct *param;
        float x, s;

        x = 1.0f - (float)i / g_gui_screen_switch_effect_frames;

        /* old screen */
        param = &g_gui_screen_switch_effect_object_param[0][i];
        param->bg_color = GDI_COLOR_GRAY;
        
        s = x * x * x * x;

        // set opacity
        param->opacity = (S32)(255 * s);

        // set scale
        transform_matrix1[i][0] = transform_matrix1[i][4] = s;

        // set position
        transform_matrix1[i][6] = (UI_device_width - s * g_gui_screen_switch_effect_object[0].width) / 2;
        transform_matrix1[i][7] = (UI_device_height - s * g_gui_screen_switch_effect_object[0].height) / 2;

        param->transform_matrix= transform_matrix1[i];

        /* new screen */
        param = &g_gui_screen_switch_effect_object_param[1][i];
        param->bg_color = GDI_COLOR_GRAY;

        s = 1.0f + 0.5f * x * x * x * x;

        // set opacity
        param->opacity = (S32)255 * (1.0f - x * x * x * x);

        // set scale
        transform_matrix2[i][0] = transform_matrix2[i][4] = s;

        // set position
        transform_matrix2[i][6] = (UI_device_width - s * g_gui_screen_switch_effect_object[1].width) / 2;
        transform_matrix2[i][7] = UI_device_height * (s - 1.0f) * 2;

        param->transform_matrix= transform_matrix2[i];
    }

    /* skip beginning frames to speed up a little since the old screen is not so important */
    gui_screen_switch_effect_skip_beginning_frames(1);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SSE", SA_start);
#endif
    gui_screen_switch_effect_draw_world();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SSE", SA_stop);
#endif
    gui_screen_switch_effect_close_world();
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_cosmos_page
 * DESCRIPTION
 *  Page entry effect for Cosmos project
 * PARAMETERS
 *  type    [IN] effect type
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sse_cosmos_page(gui_screen_switch_effect_type_enum effect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define NUMBER_OF_COSMOS_APP_PAGE_FRAMES   15

    S32 i;
    S32 direction = (effect_type == GUI_SCREEN_SWITCH_EFFECT_COSMOS_PAGE_ENTRY) ? (-1) : (1);
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_screen_switch_effect_create_world();

    /* old screen & new screen */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);

    /* setup frame number and duration */
    g_gui_screen_switch_effect_frame_duration = 25;
    g_gui_screen_switch_effect_frames = NUMBER_OF_COSMOS_APP_PAGE_FRAMES;

    GUI_RECT(g_gui_screen_switch_effect_world_view_rect, 0, MMI_STATUS_BAR_HEIGHT, UI_device_width, UI_device_height - MMI_STATUS_BAR_HEIGHT);

    /* setup each frame */
    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {    
        float x = 1.0f - (float)i / g_gui_screen_switch_effect_frames;
        float s = 1 - x * x * x ;
        S32 offset_x = (S32)(s * UI_device_width * direction);

        /* old screen */
        g_gui_screen_switch_effect_object_param[0][i].bg_color = GDI_COLOR_GRAY;
        g_gui_screen_switch_effect_object_param[0][i].offset_x = offset_x;

        /* new screen */
        g_gui_screen_switch_effect_object_param[1][i].bg_color = GDI_COLOR_GRAY;
        g_gui_screen_switch_effect_object_param[1][i].offset_x = UI_device_width * (-direction) + offset_x;
    }

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();
}

#endif /* defined(__COSMOS_MMI_PACKAGE__) */


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_owner_draw
 * DESCRIPTION
 *  Custom owner draw screen switch effect.
 * PARAMETERS
 *  effect_type       [IN]  owner draw effect type
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_owner_draw(gui_screen_switch_effect_type_enum effect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;    
    kal_uint32 start_time, end_time, elapsed_ms;    
    S32 frame_buffer_lock_count;
    S32 next_timer_duration;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for SSE owner draw method, we allow FORCE enable */
    gdi_layer_get_frame_buffer_lock_count(&frame_buffer_lock_count);    

    if ((g_gui_sse_owner_draw_frame_callback == NULL) ||
        PhnsetGetScreenSwitchEffectStatus() == MMI_PHNSET_SSE_NONE ||     
        
    #ifdef __J2ME__
        mmi_java_is_installing() ||
    #endif
    
    #ifdef __MMI_UCM__
        (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0) ||
    #endif
        frame_buffer_lock_count ||
        !dm_is_activated() ||
        /* force enable can override the following cases */
        (!g_gui_sse_is_force_enable_effect &&
         ((g_gui_sse_is_force_block && dm_check_control_exist(g_dm_data.s32CatId, DM_POPUP_BACKGROUND)) ||     /* force block, ONLY apply to popup sliding currently */
          gdi_lcd_get_freeze() || 
          mmi_is_redrawing_bk_screens())))
    {
        return;
    }

    GDI_LOCK;
    
    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        kal_get_time(&start_time);        
        if (g_gui_sse_owner_draw_frame_callback(effect_type, i, g_gui_screen_switch_effect_frames) == MMI_FALSE)
        {
            GDI_UNLOCK;

            /* blt again to let draw frame termination easier */
            // TODO: maybe let draw frame callback handle this?
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            
            return;
        }
        kal_get_time(&end_time);

        /* 
         * control time duration 
         */
        elapsed_ms = kal_ticks_to_milli_secs(end_time - start_time);
        MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_GUI_SCREEN_SWITCH_EFFECT_PERFORMANCE, g_gui_screen_switch_effect_type, i, elapsed_ms);

        if (elapsed_ms > (kal_uint32)g_gui_screen_switch_effect_frame_duration)
        {
            next_timer_duration = 0;
        }
        else
        {
            next_timer_duration = g_gui_screen_switch_effect_frame_duration - elapsed_ms; 
        }        

        kal_sleep_task(kal_milli_secs_to_ticks(next_timer_duration));
    }

    GDI_UNLOCK;
}

#ifdef __MMI_MAINMENU_MATRIX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  gui_sse_get_current_category_control_coordinate
 * DESCRIPTION
 *  Gets the control coordinate of the current category
 * PARAMETERS
 *  control_id       [IN]   control id
 *  x                [IN]   control coordinate x
 *  y                [IN]   control coordinate y
 *  width            [IN]   control coordinate width
 *  height           [IN]   control coordinate height
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sse_get_current_category_control_coordinate(mmi_dm_control_ids_enum control_id, S32 *x, S32 *y, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates coord;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_get_control_coordinates_from_category(
        -1,
        g_dm_data.s32CatId,
        control_id,
        -1,
        &coord);

    *x = (S32)coord.s16X;
    *y = (S32)coord.s16Y;
    *width = (S32)coord.s16Width;
    *height = (S32)coord.s16Height;
}




/*****************************************************************************
 * FUNCTION
 *  gui_sse_main_menu_matrix_icon_expand_draw
 * DESCRIPTION
 *  Draws all matrix menu icons accroding to start and end points.
 * PARAMETERS
 *  object       [IN]   SSE object
 *  param        [IN]   frame parameter
 *  time         [IN]   current frame index
 *  layers       [IN]   SSE layers
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sse_main_menu_matrix_icon_expand_draw(gui_screen_switch_effect_object_struct *object, gui_screen_switch_effect_param_struct *param, S32 time, gdi_handle *layers)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, x1, y1;
    S32 matrix_x, matrix_y, matrix_w, matrix_h;
    gdi_handle matrix_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_get_current_category_control_coordinate(
        DM_MATRIX_MENU1, 
        &matrix_x,
        &matrix_y,
        &matrix_w,
        &matrix_h);

    /* copy the background to the active matrix layer */
    gui_screen_switch_effect_create_object_layer(object, &matrix_layer);
    gdi_layer_push_and_set_active(matrix_layer);
    gdi_layer_set_clip(0, matrix_y, UI_device_width - 1, matrix_y + matrix_h - 1);
    // TODO: This flatten will make nonblocking blt impossible. Should use memcpy or something.
    gdi_layer_flatten_with_clipping(layers[0], 0, 0, 0);
    gdi_layer_pop_and_restore_active();

    /* set source layer to the active matrix layer */
    gdi_push_and_set_alpha_blending_source_layer(matrix_layer);
    
    /* show all matrix icons according to its position */
    for (i = 0; i < matrix_mm_active_image_num; i++)
    {
        x1 = g_gui_sse_matrix_menu_menu_icon_start_points[i].x + (g_gui_sse_matrix_menu_menu_icon_end_points[i].x - g_gui_sse_matrix_menu_menu_icon_start_points[i].x) * time / g_gui_screen_switch_effect_frames;
        y1 = g_gui_sse_matrix_menu_menu_icon_start_points[i].y + (g_gui_sse_matrix_menu_menu_icon_end_points[i].y - g_gui_sse_matrix_menu_menu_icon_start_points[i].y) * time / g_gui_screen_switch_effect_frames;

    #if !defined(__MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__)
        if (i == MMI_fixed_matrix_menu.highlighted_item)
        {
            gdi_image_draw_id(x1, y1, gMainMenuAnimation[i]);
        }
        else
    #endif /* !defined(__MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__) */
        {
            gdi_image_draw(x1, y1, matrix_mm_rect[i].image);
        }
    }
    
    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_free(matrix_layer);
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_matrix_main_menu_icon_expand
 * DESCRIPTION
 *  Matrix main menu icon expanding screen switch effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_matrix_main_menu_icon_expand(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    PU8 scr_bg_buf_p;
    S32 x1, y1, iw, ih;
    S32 icon_x, icon_y;
    S32 matrix_x, matrix_y, matrix_w, matrix_h;    
    S32 center_x, center_y, sx, sy;        
    gdi_handle other_layer;
    gui_common_menuitem_base_struct *cm;

    S32 scr_bg_bpp;
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
    gdi_handle scr_bg_backup_layer = GDI_NULL_HANDLE;
#endif
    /* 
     * matrix main menu icons start position ratio 
     *
     * 1. [CAUTION] Do not use parentheses here
     * 2. For HVGA, the ratio is raised to 0.8 because the effect frame number is decreased.
     */
    
#ifdef __MMI_MAINLCD_320X480__
    #define GUI_SSE_MATRIX_MAIN_MENU_ICON_EXPAND_START_POSITION_RATIO   4 / 5
    #define GUI_SSE_MATRIX_MAIN_MENU_ICON_EXPAND_FRAME_NUM              3
#else /* __MMI_MAINLCD_320X480__ */
    #define GUI_SSE_MATRIX_MAIN_MENU_ICON_EXPAND_START_POSITION_RATIO   2 / 3
    #define GUI_SSE_MATRIX_MAIN_MENU_ICON_EXPAND_FRAME_NUM              4
#endif /* __MMI_MAINLCD_320X480__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    cm = (gui_common_menuitem_base_struct*)MMI_fixed_matrix_menu.common_item_data;
    
    gui_sse_get_current_category_control_coordinate(
        DM_MATRIX_MENU1, 
        &matrix_x,
        &matrix_y,
        &matrix_w,
        &matrix_h);

    center_x = matrix_x + matrix_w / 2;
    center_y = matrix_y + matrix_h / 2;

    /* setup matrix icons start and end point position */
    for (i = 0; i < matrix_mm_active_image_num; i++)
    {
        gdi_image_get_dimension(matrix_mm_rect[i].image, &iw, &ih);
       
        icon_x = cm->icon_x;
        icon_y = cm->icon_y;

        if (cm->flags & UI_MENUITEM_CENTER_ICON_X)
        {
            icon_x = (cm->width >> 1) - (iw >> 1);
        }

        if (cm->flags & UI_MENUITEM_CENTER_ICON_Y)
        {
            icon_y = (cm->height >> 1) - (ih >> 1);
        }

        x1 = matrix_mm_rect[i].rect.x + icon_x;
        y1 = matrix_mm_rect[i].rect.y + icon_y;

        /* set icon movement end points */
        GUI_EFFECT_SET_POINT(g_gui_sse_matrix_menu_menu_icon_end_points[i], x1, y1);

        /* calculate icon movement start points */
        sx = (g_gui_sse_matrix_menu_menu_icon_end_points[i].x + iw / 2 - center_x) * GUI_SSE_MATRIX_MAIN_MENU_ICON_EXPAND_START_POSITION_RATIO + center_x - iw / 2;
        sy = (g_gui_sse_matrix_menu_menu_icon_end_points[i].y + ih / 2 - center_y) * GUI_SSE_MATRIX_MAIN_MENU_ICON_EXPAND_START_POSITION_RATIO + center_y - ih / 2;

        GUI_EFFECT_SET_POINT(g_gui_sse_matrix_menu_menu_icon_start_points[i], sx, sy);
    }
    
    gui_screen_switch_effect_save_current_screen((PU8)g_gui_screen_switch_effect_buf_b);
 
    /* get SCR BG layer buffer pointer */
    gdi_layer_push_and_set_active(dm_get_scr_bg_layer());
    scr_bg_bpp = (S32)gdi_layer_get_bit_per_pixel();    
    gdi_layer_get_buffer_ptr(&scr_bg_buf_p);
    /* must redraw SCR BG because main menu highlight scaling will touch SCR BG layer... */
    // TODO: this is slow...
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
    /* save the SCR BG layer content first */
    if (scr_bg_bpp == 16)
    {
        memcpy(g_gui_screen_switch_effect_buf_c, scr_bg_buf_p, UI_device_width * UI_device_height * 2);    
    }
    else
    {
        BOOL source_key_enable;
        gdi_color source_key_value;
        
        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        gdi_layer_set_source_key(FALSE, source_key_value);
    
        /* flatten SCR BG layer to the 16-bit backup layer */
        // TODO: 24-bit is downgraded to 16-bit...
        gdi_layer_create_cf_using_outside_memory(
            GDI_COLOR_FORMAT_16,
            0,
            0,
            UI_device_width, 
            UI_device_height,
            &scr_bg_backup_layer,
            (PU8)g_gui_screen_switch_effect_buf_c,
            UI_device_width * UI_device_height * 2);

        gdi_layer_push_and_set_active(scr_bg_backup_layer);
        gdi_layer_flatten(dm_get_scr_bg_layer(), 0, 0, 0);
        gdi_layer_pop_and_restore_active();

        gdi_layer_set_source_key(source_key_enable, source_key_value);
    }
    
    dm_draw_scr_bg_image();
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__ */
    gdi_layer_pop_and_restore_active();

    /* force a full-screen blt for the first frame */
    // TODO: This is tricky.
    gdi_layer_lock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    gdi_layer_unlock_frame_buffer();

    g_gui_screen_switch_effect_is_to_clear_key = MMI_FALSE;

    gui_screen_switch_effect_create_world();

    /* do not use the default finish callback since we want to manually blt the final frame */
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
    gui_screen_switch_effect_register_finish_callback(NULL);    
#endif

    /* SCR BG */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, scr_bg_bpp, 0, scr_bg_buf_p, gui_screen_switch_effect_object_get_param_callback);
    /* matrix */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
    /* others */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 2, 2, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_b, gui_screen_switch_effect_object_get_param_callback);

    GUI_RECT(g_gui_screen_switch_effect_world_view_rect, 0, matrix_y, UI_device_width, matrix_h);
  
    /* The "other layer" is only for the first frame to blt the left parts. */
    gui_screen_switch_effect_create_object_layer(g_gui_screen_switch_effect_object + 2, &other_layer);
    gdi_layer_push_and_set_active(other_layer);
    gdi_draw_solid_rect(0, matrix_y, UI_device_width - 1, matrix_y + matrix_h - 1, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(other_layer);

    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;    
    
    /* reduce frame number for HVGA */
    // TODO: should roll back after use ABM for PNG icons
    g_gui_screen_switch_effect_frames = GUI_SSE_MATRIX_MAIN_MENU_ICON_EXPAND_FRAME_NUM;

    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        g_gui_screen_switch_effect_object_param[1][i].opacity = 255 * (i + 1) / (g_gui_screen_switch_effect_frames + 2);
    }

    /* set the draw function to draw all icons for each frame */
    g_gui_screen_switch_effect_object[1].draw_callback = gui_sse_main_menu_matrix_icon_expand_draw;

    /* assign the double buffer to make non-blocking blt possible */
#if !defined(__MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__)
    g_gui_screen_switch_effect_object[1].buf2 = (PU8)g_gui_screen_switch_effect_buf_c;
#endif

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();

    /* restore the SCR BG layer content and blt whole screen again */
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
    if (scr_bg_bpp == 16)
    {
        memcpy(scr_bg_buf_p, g_gui_screen_switch_effect_buf_c, UI_device_width * UI_device_height * 2);
    }
    else
    {
        /* flatten the 16-bit backup layer back to the SCR BG layer */
        gdi_layer_push_and_set_active(dm_get_scr_bg_layer());
        gdi_layer_flatten(scr_bg_backup_layer, 0, 0, 0);
        gdi_layer_pop_and_restore_active();
    
        gdi_layer_free(scr_bg_backup_layer);
    }
    
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__ */

    g_gui_screen_switch_effect_is_to_clear_key = MMI_TRUE;
}


#endif /* __MMI_MAINMENU_MATRIX_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_blend
 * DESCRIPTION
 *  Alpha blending screen switch effect. For screen switch effects, blend in/out
 *  is the same. The old screen to blend out shows the new screen to blend in.
 * PARAMETERS
 *  effect_type       [IN]  effect type
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_blend(gui_screen_switch_effect_type_enum effect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    UI_UNUSED_PARAMETER(effect_type);

    // TODO: WORKAROUND FOR DIALER. PLEASE FIX ME
    g_gui_screen_switch_effect_is_to_clear_key = MMI_FALSE;

    gui_screen_switch_effect_create_world();

    if (effect_type == GUI_SCREEN_SWITCH_EFFECT_BLEND_IN)
    {
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);
    }
    else
    {
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
    }

    /* no source key */
    g_gui_screen_switch_effect_object[0].enable_source_key = MMI_FALSE;
    g_gui_screen_switch_effect_object[1].enable_source_key = MMI_FALSE;
    
    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_FRAMES;

    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        float x, s;

        if (effect_type == GUI_SCREEN_SWITCH_EFFECT_BLEND_IN)
        {
            /* new frame */
            x = 1.0f - (float)i / g_gui_screen_switch_effect_frames;
            s = 1.0f - x*x*x;
            g_gui_screen_switch_effect_object_param[1][i].opacity = (S32)(255*s);
        }
        else
        {
            /* new frame */
            x = 1.0f - (float)i / g_gui_screen_switch_effect_frames;
            s = x*x*x;
            g_gui_screen_switch_effect_object_param[1][i].opacity = (S32)(255*s);
        }
    }
    
    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();

	// TODO: WORKAROUND FOR DIALER. PLEASE FIX ME
    g_gui_screen_switch_effect_is_to_clear_key = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_slide_and_blend
 * DESCRIPTION
 *  slide and blend
 *  buffer 0(a): old frame
 *  buffer 1(b): new frame
 * PARAMETERS
 *  effect_type       [IN]  effect type
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_slide_and_blend(gui_screen_switch_effect_type_enum effect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color theme_bg_color = (current_MMI_theme->lite_disp_scr_bg_color) ? (*current_MMI_theme->lite_disp_scr_bg_color) : (UI_COLOR_BLACK);
    gdi_color bg_color = gd_color_from_rgb_16(255, theme_bg_color.r, theme_bg_color.g, theme_bg_color.b);
    S32 direction = (effect_type == GUI_SCREEN_SWITCH_EFFECT_SLIDE_AND_BLEND_IN) ? (1) : (-1);
    S32 i;
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    gui_screen_switch_effect_create_world();
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);

    /* no source key */
    g_gui_screen_switch_effect_object[0].enable_source_key = MMI_FALSE;
    g_gui_screen_switch_effect_object[1].enable_source_key = MMI_FALSE;
    
    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = 8;


    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        float x = 1.0f - (float)i / g_gui_screen_switch_effect_frames;
        float s = x*x*x;

        /* new frame */
        g_gui_screen_switch_effect_object_param[1][i].opacity = (S32)(150 + 105*(1.0f - s));
        g_gui_screen_switch_effect_object_param[1][i].offset_x = (S32)(direction * UI_device_width * 3 * s / 4);
#if defined(__COSMOS_MMI_PACKAGE__)
        g_gui_screen_switch_effect_object_param[1][i].bg_color = GDI_COLOR_GRAY;
#else /* defined(__COSMOS_MMI_PACKAGE__) */
        g_gui_screen_switch_effect_object_param[1][i].bg_color = bg_color;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */

        /* old frame */
        g_gui_screen_switch_effect_object_param[0][i].opacity = (S32)(150 - 50*(1.0f - s));
        g_gui_screen_switch_effect_object_param[0][i].offset_x = (S32)((-direction) * UI_device_width * 3 * (1.0f - s) / 4);  
#if defined(__COSMOS_MMI_PACKAGE__)
        g_gui_screen_switch_effect_object_param[0][i].bg_color = GDI_COLOR_GRAY;
#else /* defined(__COSMOS_MMI_PACKAGE__) */
        g_gui_screen_switch_effect_object_param[0][i].bg_color = bg_color;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
    }
    
    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_custom
 * DESCRIPTION
 *  Customized screen switch effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_custom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    // ADD CUSTOMER CODE HERE
}


#ifdef __MMI_CALENDAR__
/*****************************************************************************
 * FUNCTION
 *  gui_screen_effect_calendar_page
 * DESCRIPTION
 *  Setups SSE effect parameters
 * PARAMETERS
 *  page_direction           [IN]  page direction
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_effect_calendar_page(gui_screen_switch_effect_type_enum page_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    float *transform_matrix_p;
    gdi_handle old_page_frame_layer, shadow_layer, old_screen_layer;

#define GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_INITIAL_SKIP_FRAME_NUM 0   /* skip frames at first to speed up a little */
#define GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_FRAME_NUM 5                /* total frames for page turn */
#define GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_TIMER_UNIT   50

#if defined(__MMI_MAINLCD_240X400__)
    #define GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_SHADOW_HEIGHT 80
#elif defined(__MMI_MAINLCD_320X480__)
    #define GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_SHADOW_HEIGHT 87
#elif defined(__MMI_MAINLCD_240X320__)
    #define GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_SHADOW_HEIGHT 65
#elif defined(__MMI_MAINLCD_320X240__)
    #define GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_SHADOW_HEIGHT 68
#elif defined(__MMI_MAINLCD_176X220__)
    #define GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_SHADOW_HEIGHT 55
#else 
    #define GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_SHADOW_HEIGHT 40
#endif

    const U8 gui_sse_calendar_page_opacity_story[GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_FRAME_NUM] = {100, 90, 75, 55, 30};

    const S32 gui_sse_calendar_page_shadow_offset_y[GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_FRAME_NUM] = 
    {
#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
        211, 185, 170, 100, 72
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
        174, 150, 130, 95, 75
#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
        145, 140, 120, 94, 73
#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
        205, 180, 138, 110, 95
#elif defined(__MMI_MAINLCD_176X220__)
        /* 176 x 220 */
        144, 120, 100, 82, 63
#else
        /* 128 x 160 */
        100, 80, 60, 40, 20
#endif /* defined(__MMI_MAINLCD_240X400__) */
        
    };

    const gui_sse_projective_transform_matrix_struct projective_transform_matrix[GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_FRAME_NUM] = 
    {
#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
        {1.00000F, 0.00000F, 0.00000F, -0.08042F, 0.74476F, -0.00067F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.12381F, 0.54603F, -0.00099F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.17465F, 0.33521F, -0.00135F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.18011F, 0.13441F, -0.00148F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.18848F, 0.08115F, -0.00155F, 0.00000F, 0.00000F},
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
        {1.00000F, 0.00000F, 0.00000F, -0.14689F, 0.61848F, -0.00116F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.18877F, 0.44745F, -0.00153F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.21419F, 0.28668F, -0.00173F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.21419F, 0.16476F, -0.00173F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.23415F, 0.09943F, -0.00182F, 0.00000F, 0.00000F},
#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
        {1.00000F, 0.00000F, 0.00000F, -0.17143F, 0.74286F, -0.00106F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.18367F, 0.63265F, -0.00115F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.26573F, 0.42890F, -0.00159F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.28966F, 0.27126F, -0.00165F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.28767F, 0.11872F, -0.00168F, 0.00000F, 0.00000F},
#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
        {1.00000F, 0.00000F, 0.00000F, -0.09622F, 0.73540F, -0.00061F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.15094F, 0.54715F, -0.00090F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.21502F, 0.31028F, -0.00133F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.24934F, 0.16194F, -0.00148F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.26658F, 0.07723F, -0.00156F, 0.00000F, 0.00000F},
#else
        /* 176 x 220 */
        {1.00000F, 0.00000F, 0.00000F, -0.08665F, 0.75276F, -0.00095F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.12784F, 0.53593F, -0.00145F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.17177F, 0.33450F, -0.00185F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.20078F, 0.19241F, -0.00219F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, -0.21950F, 0.10191F, -0.00245F, 0.00000F, 0.00000F},
#endif /* defined(__MMI_MAINLCD_240X400__) */
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (page_direction == GUI_SCREEN_SWITCH_EEFECT_CALENDAR_PAGE_UP)
    {
        gui_screen_switch_effect_save_current_screen((PU8)g_gui_screen_switch_effect_buf_b);
    }
    else
    {
        gui_screen_switch_effect_save_current_screen((PU8)g_gui_screen_switch_effect_buf_a);
    }

    /* old screen layer */
    gdi_layer_create_cf_using_outside_memory(
        GUI_EFFECT_LAYER_COLOR_FORMAT,
        0,
        0,
        UI_device_width,
        UI_device_height,
        &old_screen_layer,
        (U8*)g_gui_screen_switch_effect_buf_a,
        UI_device_width * UI_device_height * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE);  

    /* old page matrix frame */
    gdi_layer_create_cf_using_outside_memory(
        GUI_EFFECT_LAYER_COLOR_FORMAT,
        0,
        0,
        UI_device_width,
        GUI_CALENDAR_FRAME_HEIGHT,
        &old_page_frame_layer,
        (U8*)g_gui_screen_switch_effect_buf_c,
        UI_device_width * GUI_CALENDAR_FRAME_HEIGHT * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE);     


    gdi_layer_push_and_set_active(old_screen_layer);
    gdi_layer_set_position(0, -GUI_CALENDAR_FRAME_START_Y - 1);
    gdi_layer_set_active(old_page_frame_layer);
    gdi_layer_flatten(old_screen_layer, 0, 0, 0);
    gdi_layer_pop_and_restore_active();

    if (page_direction == GUI_SCREEN_SWITCH_EEFECT_CALENDAR_PAGE_UP)
    {
        memcpy((PU8)g_gui_screen_switch_effect_buf_b, 
            (PU8)g_gui_screen_switch_effect_buf_a, 
            UI_device_width * GUI_CALENDAR_FRAME_START_Y * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE);

        memcpy((PU8)g_gui_screen_switch_effect_buf_b + UI_device_width * (GUI_CALENDAR_FRAME_START_Y + GUI_CALENDAR_FRAME_HEIGHT) * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE, 
            (PU8)g_gui_screen_switch_effect_buf_a + UI_device_width * (GUI_CALENDAR_FRAME_START_Y + GUI_CALENDAR_FRAME_HEIGHT) * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE, 
            UI_device_width * (UI_device_height - GUI_CALENDAR_FRAME_HEIGHT - GUI_CALENDAR_FRAME_START_Y) * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE);
    }
    
    memcpy((PU8)g_gui_screen_switch_effect_buf_a, 
        (PU8)g_gui_screen_switch_effect_buf_c, 
        UI_device_width * GUI_CALENDAR_FRAME_HEIGHT * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE);

    gdi_layer_free(old_page_frame_layer);
    gdi_layer_free(old_screen_layer);

    /* black shadow */
    gdi_layer_create_cf_using_outside_memory(
        GUI_EFFECT_LAYER_COLOR_FORMAT,
        0,
        0,
        UI_device_width,
        GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_SHADOW_HEIGHT,
        &shadow_layer,
        (U8*)g_gui_screen_switch_effect_buf_a + UI_device_width * GUI_CALENDAR_FRAME_HEIGHT * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE,
        UI_device_width * GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_SHADOW_HEIGHT * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE);     

    gdi_layer_push_and_set_active(shadow_layer);
    gdi_push_and_set_alpha_blending_source_layer(shadow_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();

    gdi_layer_free(shadow_layer);

    g_gui_screen_switch_effect_is_to_clear_key = MMI_FALSE;
    gui_screen_switch_effect_create_world();
    
    /* set view port to matrix frame area only */
  //  GUI_RECT(g_gui_screen_switch_effect_world_view_rect, GUI_CALENDAR_FRAME_START_X, GUI_CALENDAR_FRAME_START_Y, GUI_CALENDAR_FRAME_WIDTH, GUI_CALENDAR_FRAME_HEIGHT);

    /* new calendar bg */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_b, gui_screen_switch_effect_object_get_param_callback);
    /* shadow */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_SHADOW_HEIGHT, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a + UI_device_width * GUI_CALENDAR_FRAME_HEIGHT * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE, gui_screen_switch_effect_object_get_param_callback);
    /* old calendar frame */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 2, 2, UI_device_width, GUI_CALENDAR_FRAME_HEIGHT, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);

    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_FRAME_NUM;
    
    for (i = 0; i < GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_FRAME_NUM; i++)
    {            
        g_gui_screen_switch_effect_object_param[2][i].offset_y = GUI_CALENDAR_FRAME_START_Y;

        if (page_direction == GUI_SCREEN_SWITCH_EEFECT_CALENDAR_PAGE_UP)
        {
            g_gui_screen_switch_effect_object_param[1][i].offset_y = gui_sse_calendar_page_shadow_offset_y[i];
            transform_matrix_p = (float*)projective_transform_matrix[i].m;
            g_gui_screen_switch_effect_object_param[1][i].opacity = gui_sse_calendar_page_opacity_story[i];
        }
        else
        {
            g_gui_screen_switch_effect_object_param[1][i].offset_y = gui_sse_calendar_page_shadow_offset_y[GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_FRAME_NUM - 1 - i];
            transform_matrix_p = (float*)projective_transform_matrix[GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_FRAME_NUM - 1 - i].m;
            g_gui_screen_switch_effect_object_param[1][i].opacity = gui_sse_calendar_page_opacity_story[GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_FRAME_NUM - 1 - i];
        }
        
        g_gui_screen_switch_effect_object_param[2][i].transform_matrix = transform_matrix_p;
        g_gui_screen_switch_effect_object_param[2][i].opacity = 255;

     //   g_gui_screen_switch_effect_object_param[1][i].scale_x = 0;
    }

    /* skip beginning frames to speed up a little since the old screen is not so important */
    gui_screen_switch_effect_skip_beginning_frames(GUI_SCREEN_SWITCH_EFFECT_CALENDAR_PAGE_INITIAL_SKIP_FRAME_NUM);   

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();    
    g_gui_screen_switch_effect_is_to_clear_key = MMI_TRUE;
}
#endif /* __MMI_CALENDAR__ */


#ifdef __GUI_SSE_BACKUP_EFFECT_ON__
/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_zoom
 * DESCRIPTION
 *  Zoom screen switch effect.
 * PARAMETERS
 *  effect_type       [IN]  effect type
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_zoom(gui_screen_switch_effect_type_enum effect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S32     scale;
    S32     dst_w, dst_h;
    gui_screen_switch_effect_param_struct *param;
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     

    gui_screen_switch_effect_create_world();

    if (effect_type == GUI_SCREEN_SWITCH_EFFECT_ZOOM_OUT)
    {
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);        
    }
    else
    {
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);
    }
    
    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_FRAMES;   

    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        param = &g_gui_screen_switch_effect_object_param[1][i];

        scale = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(1.0) * i / (g_gui_screen_switch_effect_frames + 1);
        
        /* zoom out */
        if (effect_type == GUI_SCREEN_SWITCH_EFFECT_ZOOM_OUT)
        {
            scale = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(1.0) - scale;
        }
        
        param->scale_x = param->scale_y = scale;

        /* center */
        dst_w = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT_MUL(scale, g_gui_screen_switch_effect_object[1].width);
        dst_h = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT_MUL(scale, g_gui_screen_switch_effect_object[1].height);
        
        param->offset_x = (UI_device_width - dst_w) / 2;
        param->offset_y = (UI_device_height - dst_h) / 2;
    }
       
    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();
}

static gdi_handle g_gui_sse_title_sliding_bg_layer_handle = GDI_NULL_HANDLE;
/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_submenu_slide_draw_title
 * DESCRIPTION
 *  Draws the title for title sliding.
 * PARAMETERS
 *  object       [IN]   object 
 *  param        [IN]   object current parameter
 *  time         [IN]   object frame index
 *  layers       [IN]   layer handle of each object
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_submenu_slide_draw_title(gui_screen_switch_effect_object_struct *object, gui_screen_switch_effect_param_struct *param, S32 time, gdi_handle *layers)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_width, text_height;
    PU8 text;
    S32 move_range, offset_x;
    gdi_handle active_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_get_text_info(&text_width, &text_height, &text);
    move_range = text_width / 8;    
    offset_x = move_range - move_range * time / g_gui_screen_switch_effect_frames;

    /* redraw the title with offset */
    if (g_gui_screen_switch_effect_type == GUI_SCREEN_SWITCH_EFFECT_SUBMENU_SLIDE_RIGHT)
    {
        offset_x = -offset_x;
    }

    wgui_title_set_offset(offset_x, 0);
    gdi_layer_lock_frame_buffer();
    draw_title();
    gdi_layer_unlock_frame_buffer();

    gdi_layer_get_active(&active_layer);
    gdi_layer_set_clip(0, MMI_SUBMENU_CONTENT_Y - MMI_TITLE_HEIGHT, UI_device_width - 1, MMI_SUBMENU_CONTENT_Y - 1);
    /* use some opacity to make it look better */
    gdi_layer_set_opacity(TRUE, (U8)(250 * (time + 1) / g_gui_screen_switch_effect_frames));
    gdi_layer_flatten_with_clipping(g_gui_sse_title_sliding_bg_layer_handle, active_layer, 0, 0);
    gdi_layer_set_opacity(FALSE, 255);
    
    /* reset title position to normal */
    wgui_title_set_offset(0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_submenu_slide
 * DESCRIPTION
 *  Submenu screen switch sliding effect.
 * PARAMETERS
 *  effect_type       [IN]  effect type
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_submenu_slide(gui_screen_switch_effect_type_enum effect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         i;
    S32         direction;
    S32         offset;

    gdi_handle  scr_bg_layer;
    PU8         scr_bg_buf;
    UI_string_type old_MMI_title_string;
    S32         scr_bpp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_bg_layer = dm_get_scr_bg_layer();
    if (scr_bg_layer == GDI_ERROR_HANDLE)
    {
        GUI_SSE_SET_ERROR_CODE(GUI_SSE_ERROR_SUBMENU_SLIDE);
        
        return;
    }

    gui_screen_switch_effect_save_main_base_layer((PU8)g_gui_screen_switch_effect_buf_b, MMI_TRUE);

    /* get SCR BG layer buffer pointer */
    gdi_layer_push_and_set_active(scr_bg_layer);
    scr_bpp = gdi_layer_get_bit_per_pixel();
    gdi_layer_get_buffer_ptr(&scr_bg_buf);
    gdi_layer_pop_and_restore_active();

    /* blit the area out of the content area by the new screen */
    gdi_lcd_freeze(TRUE);
    gdi_layer_blt_previous(0, 0, 0, 0);
    gdi_lcd_freeze(FALSE);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, MMI_SUBMENU_CONTENT_Y -  MMI_TITLE_HEIGHT);
    gdi_layer_blt_previous(0, MMI_SUBMENU_CONTENT_Y + MMI_SUBMENU_CONTENT_HEIGHT, UI_device_width - 1, UI_device_height - 1);

    gui_screen_switch_effect_create_world();
    /* set view port to content area only (inluding the title) */
    GUI_RECT(g_gui_screen_switch_effect_world_view_rect, MMI_SUBMENU_CONTENT_X, MMI_SUBMENU_CONTENT_Y - MMI_TITLE_HEIGHT, MMI_SUBMENU_CONTENT_WIDTH, MMI_SUBMENU_CONTENT_HEIGHT + MMI_TITLE_HEIGHT);
    /* scr bg */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, scr_bpp, 0, (PU8)scr_bg_buf, gui_screen_switch_effect_object_get_param_callback);
    /* old main base layer */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height - MMI_SUBMENU_CONTENT_Y, 16, 0, (PU8)g_gui_screen_switch_effect_buf_c + 2 * UI_device_width * MMI_SUBMENU_CONTENT_Y, gui_screen_switch_effect_object_get_param_callback);
    /* new main base layer */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 2, 2, UI_device_width, UI_device_height - MMI_SUBMENU_CONTENT_Y, 16, 0, (PU8)g_gui_screen_switch_effect_buf_b + 2 * UI_device_width * MMI_SUBMENU_CONTENT_Y, gui_screen_switch_effect_object_get_param_callback);
    /* title */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 3, 3, UI_device_width, MMI_SUBMENU_CONTENT_Y, 16, 0, (PU8)g_gui_screen_switch_effect_buf_c, gui_screen_switch_effect_object_get_param_callback);

    // TODO: should consider the case, no title.
    /* save the title bg (without text) */
    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_16,
        0,
        0,
        UI_device_width,
        MMI_SUBMENU_CONTENT_Y,
        &g_gui_sse_title_sliding_bg_layer_handle,
        (PU8)g_gui_screen_switch_effect_buf_b,
        UI_device_width * MMI_SUBMENU_CONTENT_Y * 2);    

    gdi_layer_push_and_set_active(g_gui_sse_title_sliding_bg_layer_handle);
    gdi_layer_reset_clip();
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_draw_solid_rect(0, MMI_SUBMENU_CONTENT_Y - MMI_TITLE_HEIGHT, UI_device_width - 1, MMI_SUBMENU_CONTENT_Y - 1, GDI_COLOR_TRANSPARENT);
    /* without title text */
    old_MMI_title_string = MMI_title_string;
    MMI_title_string = NULL;
    draw_title();
    MMI_title_string = old_MMI_title_string;    
    gdi_layer_flatten(scr_bg_layer, g_gui_sse_title_sliding_bg_layer_handle, 0, 0);
    gdi_layer_pop_and_restore_active();

    /* title draw frame callback */
    g_gui_screen_switch_effect_object[3].draw_callback = gui_screen_switch_effect_submenu_slide_draw_title;
    /* assign the double buffer to make non-blocking blt possible */
    g_gui_screen_switch_effect_object[3].buf2 = (PU8)g_gui_screen_switch_effect_buf_a;

    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_FRAMES;

    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        if (effect_type == GUI_SCREEN_SWITCH_EFFECT_SUBMENU_SLIDE_LEFT)
        {
            direction = -1;
        }
        else
        {
            direction = 1;
        }

        offset = direction * UI_device_width * (i + 1) / (g_gui_screen_switch_effect_frames + 1);
        g_gui_screen_switch_effect_object_param[1][i].offset_x = offset;
        g_gui_screen_switch_effect_object_param[1][i].offset_y = MMI_SUBMENU_CONTENT_Y;
        g_gui_screen_switch_effect_object_param[1][i].opacity = 200 - 200 * (i + 1) / (g_gui_screen_switch_effect_frames + 1);

        g_gui_screen_switch_effect_object_param[2][i].offset_x = -direction * UI_device_width + offset;     
        g_gui_screen_switch_effect_object_param[2][i].offset_y = MMI_SUBMENU_CONTENT_Y;
    }
    
    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();

    /* free the title bg layer */
    gdi_layer_free(g_gui_sse_title_sliding_bg_layer_handle);    
}

/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_rotate
 * DESCRIPTION
 *  Rotation screen switch effect.
 * PARAMETERS
 *  effect_type       [IN]  effect type
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_rotate(gui_screen_switch_effect_type_enum effect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 scale, rotation, opacity, dst_w, dst_h;
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_gui_screen_switch_effect_is_to_clear_key = MMI_FALSE;
    gui_screen_switch_effect_create_world();
    g_gui_screen_switch_effect_enable_early_key_break = MMI_TRUE;    

    if (effect_type == GUI_SCREEN_SWITCH_EFFECT_ROTATE_IN)
    {
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);
        g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_FRAMES;
    }
    else
    {
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
        g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_FRAMES + 6;
    }

    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;

    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        if (effect_type == GUI_SCREEN_SWITCH_EFFECT_ROTATE_IN)
        {
            rotation = 360 - i * 360 / g_gui_screen_switch_effect_frames;
            scale = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.4) + i * GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.6) / g_gui_screen_switch_effect_frames;
            opacity = 68 + i * 10;
        }
        else
        {
            rotation = i * 360 / g_gui_screen_switch_effect_frames;
            scale = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.6) - i * GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.6) / g_gui_screen_switch_effect_frames;
            opacity = 128 - i * 5;
        }

        g_gui_screen_switch_effect_object_param[1][i].rotation = rotation;
        g_gui_screen_switch_effect_object_param[1][i].scale_x = scale;
        g_gui_screen_switch_effect_object_param[1][i].scale_y = scale;
        g_gui_screen_switch_effect_object_param[1][i].opacity = opacity;   

        dst_w = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT_MUL(scale, g_gui_screen_switch_effect_object[1].width);
        dst_h = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT_MUL(scale, g_gui_screen_switch_effect_object[1].height);                

        /* center align */
        g_gui_screen_switch_effect_object_param[1][i].offset_x = (UI_device_width - dst_w) / 2;
        g_gui_screen_switch_effect_object_param[1][i].offset_y = (UI_device_height - dst_h) / 2;
    }
    
    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();

    g_gui_screen_switch_effect_is_to_clear_key = MMI_TRUE;    
}

/*****************************************************************************
 * FUNCTION
 *  gui_sse_page_divide_horizontal_half
 * DESCRIPTION
 *  Divides the input screen buffer into 2 halves with the same width.
 * PARAMETERS
 *  screen_buf_p       [IN/OUT] screen buffer
 *  width              [IN]     screen width
 *  height             [IN]     screen height
 *  bpp                [IN]     screen bpp
 *  tmp_buf_p          [IN]     temporary buffer    
 *  tmp_buf_size       [IN]     temporary buffer size
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sse_page_divide_horizontal_half(PU8 screen_buf_p, S32 width, S32 height, S32 bpp, PU8 tmp_buf_p, S32 tmp_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle whole_screen, right_half, left_half;
    S32 screen_buf_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    screen_buf_size = width * height * bpp / 8;

    MMI_ASSERT(tmp_buf_size >= screen_buf_size);

    /* whole screen layer */
    gdi_layer_create_cf_using_outside_memory(
        (gdi_color_format)(bpp / 8),
        0,
        0,
        width,
        height,
        &whole_screen,
        screen_buf_p,
        screen_buf_size);     

    /* left half layer */
    gdi_layer_create_cf_using_outside_memory(
        (gdi_color_format)(bpp / 8),
        0,
        0,
        width / 2,
        height,
        &left_half,
        tmp_buf_p,
        screen_buf_size / 2);     

    /* right half layer */
    gdi_layer_create_cf_using_outside_memory(
        (gdi_color_format)(bpp / 8),
        0,
        0,
        width / 2,
        height,
        &right_half,
        tmp_buf_p + screen_buf_size / 2,
        screen_buf_size / 2);     
    
    /* get left half */
    gdi_layer_push_and_set_active(left_half);
    gdi_layer_flatten(whole_screen, 0, 0, 0);
    gdi_layer_pop_and_restore_active();

    /* get right half */
    gdi_layer_push_and_set_active(whole_screen);
    gdi_layer_set_position(-width / 2, 0);   
    gdi_layer_set_active(right_half);
    gdi_layer_flatten(whole_screen, 0, 0, 0);
    gdi_layer_pop_and_restore_active();

    gdi_layer_free(whole_screen);
    gdi_layer_free(left_half);
    gdi_layer_free(right_half);

    /* copy two halves from tmp to output */
    memcpy(screen_buf_p, tmp_buf_p, screen_buf_size);
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_page_turn
 * DESCRIPTION
 *  Page turn screen switch effect.
 * PARAMETERS
 *  page_turn_direction  [IN]    page turn rotation direction
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_page_turn(gui_screen_switch_effect_type_enum page_turn_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    float *transform_matrix_p;

    #define GUI_SCREEN_SWITCH_EFFECT_PAGE_TURN_INITIAL_SKIP_FRAME_NUM 0   /* skip frames at first to speed up a little */
    #define GUI_SCREEN_SWITCH_EFFECT_PAGE_TURN_FRAME_NUM 6                /* total frames for page turn */

    const gui_sse_projective_transform_matrix_struct projective_transform_matrix[GUI_SCREEN_SWITCH_EFFECT_PAGE_TURN_FRAME_NUM] = 
    {
    #if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
        {1.00282F, -0.27542F, -0.00127F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.55909F, -0.26893F, -0.00126F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.28139F, -0.24531F, -0.00112F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.44147F,  0.27500F,  0.00125F, -0.03077F, 1.04724F, -0.00026F, 85.00000F, -28.00000F},
        {0.80454F,  0.25833F,  0.00129F, -0.01111F, 1.11750F, -0.00009F, 42.00000F, -28.00000F},
        {1.20906F,  0.17500F,  0.00084F, 0.00458F, 1.11599F, 0.00000F, -13.00000F, -24.00000F},
    #elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
        {1.00282F, -0.27542F, -0.00127F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.55909F, -0.26893F, -0.00126F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.28139F, -0.24531F, -0.00112F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.44147F,  0.27500F,  0.00125F, -0.03077F, 1.04724F, -0.00026F, 85.00000F, -28.00000F},
        {0.80454F,  0.25833F,  0.00129F, -0.01111F, 1.11750F, -0.00009F, 42.00000F, -28.00000F},
        {1.20906F,  0.17500F,  0.00084F, 0.00458F, 1.11599F, 0.00000F, -13.00000F, -24.00000F},
    #elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
        {0.99834F, -0.13691F, -0.00055F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.71910F, -0.16292F, -0.00063F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.27027F, -0.21622F, -0.00084F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.50833F,  0.26875F,  0.00099F, 0.00000F, 1.15833F, 0.00000F, 104.00000F, -43.00000F},
        {0.98570F,  0.15625F,  0.00057F, 0.00235F, 1.09899F, 0.00000F, 17.00000F, -25.00000F},
        {1.17917F,  0.13125F,  0.00046F, 0.00000F, 1.07292F, 0.00000F, -17.00000F, -21.00000F},
    #elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
        {0.99834F, -0.13691F, -0.00055F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.71910F, -0.16292F, -0.00063F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.27027F, -0.21622F, -0.00084F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.50833F,  0.26875F,  0.00099F, 0.00000F, 1.15833F, 0.00000F, 104.00000F, -43.00000F},
        {0.98570F,  0.15625F,  0.00057F, 0.00235F, 1.09899F, 0.00000F, 17.00000F, -25.00000F},
        {1.17917F,  0.13125F,  0.00046F, 0.00000F, 1.07292F, 0.00000F, -17.00000F, -21.00000F},        
    #else
        /* 176 x 220 */
        {0.99585F, -0.12448F, -0.00099F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.68798F, -0.16473F, -0.00167F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.32819F, -0.18340F, -0.00171F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.63182F,  0.23864F,  0.00201F, 0.00000F, 1.17727F, 0.00000F, 48.00000F, -21.00000F},
        {1.01818F,  0.20455F,  0.00150F, 0.00000F, 1.13182F, 0.00000F, 10.00000F, -18.00000F},
        {1.30909F,  0.15909F,  0.00119F, 0.00000F, 1.10455F, 0.00000F, -18.00000F, -14.00000F},
    #endif /* defined(__MMI_MAINLCD_240X400__) */
    };
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      

    /* divide old screen into two halves with equal width */
    gui_sse_page_divide_horizontal_half(
        (PU8)g_gui_screen_switch_effect_buf_a,
        UI_device_width, 
        UI_device_height, 
        16, 
        (PU8)g_gui_screen_switch_effect_buf_c, 
        GUI_SCREEN_SWITCH_EFFECT_TEMP_BUFFER_SIZE);

    /* divide new screen into two halves with equal width */
    gui_sse_page_divide_horizontal_half(
        (PU8)curr_screen_buf_ptr, 
        UI_device_width, 
        UI_device_height, 
        16, 
        (PU8)g_gui_screen_switch_effect_buf_c, 
        GUI_SCREEN_SWITCH_EFFECT_TEMP_BUFFER_SIZE);

    gui_screen_switch_effect_create_world();
    /* new screen left half */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width / 2, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);
    /* new screen right half */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width / 2, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr + GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE / 2, gui_screen_switch_effect_object_get_param_callback);
    /* old screen left half */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 2, 2, UI_device_width / 2, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
    /* old screen right half */
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 3, 3, UI_device_width / 2, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a + GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE / 2, gui_screen_switch_effect_object_get_param_callback);
    
    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_PAGE_TURN_FRAME_NUM;

    for (i = 0; i < GUI_SCREEN_SWITCH_EFFECT_PAGE_TURN_FRAME_NUM; i++)
    {            
        g_gui_screen_switch_effect_object_param[1][i].offset_x = UI_device_width / 2;
        g_gui_screen_switch_effect_object_param[3][i].offset_x = UI_device_width / 2;

        if (page_turn_direction == GUI_SCREEN_SWITCH_EFFECT_PAGE_TURN_LEFT)
        {
            transform_matrix_p = (float*)projective_transform_matrix[i].m;
            /* old screen */
            if (i < GUI_SCREEN_SWITCH_EFFECT_PAGE_TURN_FRAME_NUM / 2)
            {   /* first half frames in right */
                g_gui_screen_switch_effect_object_param[3][i].transform_matrix = transform_matrix_p;
            }
            else
            {   /* last half frames in left */
                /* hide old screen right part */
                g_gui_screen_switch_effect_object_param[3][i].scale_x = 0;
         
                /* raise the new screen left part up */
                g_gui_screen_switch_effect_object_param[0][i].z = 1;
                
                g_gui_screen_switch_effect_object_param[0][i].transform_matrix = transform_matrix_p;
            }
        }
        else
        {
            transform_matrix_p = (float*)projective_transform_matrix[GUI_SCREEN_SWITCH_EFFECT_PAGE_TURN_FRAME_NUM - 1 - i].m;

            if (i < GUI_SCREEN_SWITCH_EFFECT_PAGE_TURN_FRAME_NUM / 2)
            {   /* first half frames in left */
                g_gui_screen_switch_effect_object_param[2][i].transform_matrix = transform_matrix_p;
            }
            else
            {   /* last half frames in right */
                /* hide old screen left part */
                g_gui_screen_switch_effect_object_param[2][i].scale_x = 0;
         
                /* raise the new screen right part up */
                g_gui_screen_switch_effect_object_param[1][i].z = 1;
                
                g_gui_screen_switch_effect_object_param[1][i].transform_matrix = transform_matrix_p;
            }
        }
    }

    /* skip beginning frames to speed up a little since the old screen is not so important */
    gui_screen_switch_effect_skip_beginning_frames(GUI_SCREEN_SWITCH_EFFECT_PAGE_TURN_INITIAL_SKIP_FRAME_NUM);   

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();    
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_move_out
 * DESCRIPTION
 *  Move out screen switch effect.
 * PARAMETERS
 *  effect_type       [IN]  move in effect type
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_move_out(gui_screen_switch_effect_type_enum effect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 offset_x, offset_y;
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // TODO: WORKAROUND FOR DIALER. PLEASE FIX ME
    g_gui_screen_switch_effect_is_to_clear_key = MMI_FALSE;
    
    gui_screen_switch_effect_create_world();    

    /* move out, old screen on top */        
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);        
    
    /* no source key */
    g_gui_screen_switch_effect_object[0].enable_source_key = MMI_FALSE;
    g_gui_screen_switch_effect_object[1].enable_source_key = MMI_FALSE;

    /* best effort in order to reduce dialer SSE speed */
#if defined(__CPU_ARM7EJ_S__)
    g_gui_screen_switch_effect_frame_duration = 0;
#else /* defined(__CPU_ARM7EJ_S__) */
    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_TIMER_UNIT;
#endif /* defined(__CPU_ARM7EJ_S__) */

    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_FRAMES;

    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        offset_x = UI_device_width * (i + 1) / (g_gui_screen_switch_effect_frames + 1);
        offset_y = UI_device_height * (i + 1) / (g_gui_screen_switch_effect_frames + 1);

        switch (effect_type)
        {
            case GUI_SCREEN_SWITCH_EFFECT_MOVE_OUT_LEFT:
                g_gui_screen_switch_effect_object_param[1][i].offset_x = -offset_x;
                break;

            case GUI_SCREEN_SWITCH_EFFECT_MOVE_OUT_RIGHT:
                g_gui_screen_switch_effect_object_param[1][i].offset_x = offset_x;
                break;

            case GUI_SCREEN_SWITCH_EFFECT_MOVE_OUT_DOWN:
                g_gui_screen_switch_effect_object_param[1][i].offset_y = offset_y;
                break;

            case GUI_SCREEN_SWITCH_EFFECT_MOVE_OUT_UP:
                g_gui_screen_switch_effect_object_param[1][i].offset_y = -offset_y;
                break;

            default:
                MMI_ASSERT(0);
                break;
                
        }
    
    }

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();

    // TODO: WORKAROUND FOR DIALER. PLEASE FIX ME
    g_gui_screen_switch_effect_is_to_clear_key = MMI_TRUE;    
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_effect_revolving_gate_page
 * DESCRIPTION
 *  Setups SSE effect parameters
 * PARAMETERS
 *  page_direction           [IN]  page direction
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_effect_revolving_gate_page(gui_screen_switch_effect_type_enum page_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    float *transform_matrix_p;

#define GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_INITIAL_SKIP_FRAME_NUM 0   /* skip frames at first to speed up a little */

#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
#define GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM 4                /* total frames for page turn */
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
#define GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM 3                /* total frames for page turn */
#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
#define GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM 3                /* total frames for page turn */
#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
#define GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM 3                /* total frames for page turn */
#else
        /* 176 x 220 */
#define GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM 4                /* total frames for page turn */
#endif /* defined(__MMI_MAINLCD_240X400__) */

#if defined(__CPU_ARM7EJ_S__)
#define GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_TIMER_UNIT   33
#else /* defined(__CPU_ARM7EJ_S__) */
#define GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_TIMER_UNIT   60
#endif /* defined(__CPU_ARM7EJ_S__) */

#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__)
    const U8 gui_sse_double_page_top_opacity_story[GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM] = {200, 150, 100, 50};
    const U8 gui_sse_double_page_bottom_opacity_story[GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM] = {200, 200, 200, 200};
#else /* defined(__MMI_MAINLCD_176X220__) */
    const U8 gui_sse_double_page_top_opacity_story[GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM] = {200, 125, 50};
    const U8 gui_sse_double_page_bottom_opacity_story[GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM] = {200, 200, 200};
#endif /* defined(__MMI_MAINLCD_176X220__) */


    const gui_sse_projective_transform_matrix_struct projective_transform_matrix[GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM * 2 - 1] = 
    {
#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
        {0.72985F, -0.10893F, -0.00054F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.48942F, -0.16865F, -0.00086F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.31664F, -0.19948F, -0.00100F, 0.00000F, 0.99248F, -0.00002F, 0.00000F, 0.00000F},
        {0.15026F, -0.23570F, -0.00122F, 0.00000F, 1.01414F, 0.00004F, 0.00000F, 0.00000F},
        {1.04610F, 0.36052F, 0.00174F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {1.03590F, 0.18974F, 0.00096F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {1.06238F, 0.14133F, 0.00071F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
        {0.74419F, -0.05039F, -0.00029F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},
        {0.39614F, -0.15781F, -0.00095F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},
        {0.14981F, -0.20375F, -0.00117F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},
        {0.94261F, 0.10745F, 0.00072F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},
        {0.99884F, 0.06969F, 0.00048F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},

#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
        {0.53353F, -0.11370F, -0.00094F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},
        {0.29856F, -0.17266F, -0.00133F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},
        {0.15232F, -0.19040F, -0.00147F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},
        {1.02348F, 0.11602F, 0.00102F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},
        {1.05947F, 0.06189F, 0.00052F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},

#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
        {0.67553F, -0.11702F, -0.00047F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},
        {0.41304F, -0.17391F, -0.00071F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},
        {0.14747F, -0.19816F, -0.00082F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},
        {0.97744F, 0.15414F, 0.00063F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},
        {1.04490F, 0.11650F, 0.00052F, 0.00000F, 1.00000F, 0.00000F, 0.00000F},

#else
        /* 176 x 220 */
        {0.85062F, -0.06224F, -0.00050F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.56734F, -0.11993F, -0.00107F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {0.37811F, -0.14404F, -0.00118F, 0.00000F, 0.99068F, -0.00004F, 0.00000F, 0.00000F},
        {0.17979F, -0.16695F, -0.00140F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {1.02011F, 0.15086F, 0.00150F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {1.07639F, 0.13194F, 0.00126F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
        {1.04061F, 0.06980F, 0.00066F, 0.00000F, 1.00000F, 0.00000F, 0.00000F, 0.00000F},
#endif /* defined(__MMI_MAINLCD_240X400__) */
    };
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

    gui_screen_switch_effect_create_world();
    
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);

    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);

    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM;
    
    if (page_direction == GUI_SCREEN_SWITCH_EEFECT_REVOLVING_GATE_TURN_LEFT)
    {
        for (i = 0; i < GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM; i++)
        {
            transform_matrix_p = (float*)projective_transform_matrix[i].m;
            g_gui_screen_switch_effect_object_param[0][i].transform_matrix = transform_matrix_p;

            g_gui_screen_switch_effect_object_param[0][i].opacity = gui_sse_double_page_top_opacity_story[i];
            g_gui_screen_switch_effect_object_param[1][i].opacity = gui_sse_double_page_bottom_opacity_story[i];
            g_gui_screen_switch_effect_object_param[0][i].bg_color = GDI_COLOR_GRAY;
            g_gui_screen_switch_effect_object_param[1][i].bg_color = GDI_COLOR_GRAY;
            
            if (i > 0)
            {
                transform_matrix_p = (float*)projective_transform_matrix[i + GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM - 1].m;
                g_gui_screen_switch_effect_object_param[1][i].transform_matrix = transform_matrix_p;
            }
            else
            {
                g_gui_screen_switch_effect_object_param[1][i].offset_x = -UI_device_width;
            }
        }
    }
    else
    {
        for (j = 0, i = GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM - 1; j < GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM; i--, j++)
        {
            transform_matrix_p = (float*)projective_transform_matrix[i].m;
            g_gui_screen_switch_effect_object_param[1][j].transform_matrix = transform_matrix_p;

            g_gui_screen_switch_effect_object_param[1][j].opacity = gui_sse_double_page_top_opacity_story[i];
            g_gui_screen_switch_effect_object_param[0][j].opacity = gui_sse_double_page_bottom_opacity_story[i];
            g_gui_screen_switch_effect_object_param[0][j].bg_color = GDI_COLOR_GRAY;
            g_gui_screen_switch_effect_object_param[1][j].bg_color = GDI_COLOR_GRAY;

            if (i > 0)
            {
                transform_matrix_p = (float*)projective_transform_matrix[i + GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_FRAME_NUM - 1].m;
                g_gui_screen_switch_effect_object_param[0][j].transform_matrix = transform_matrix_p;
            }
            else
            {
                g_gui_screen_switch_effect_object_param[0][j].offset_x = -UI_device_width;
            }
        }
    }

    /* skip beginning frames to speed up a little since the old screen is not so important */
    gui_screen_switch_effect_skip_beginning_frames(GUI_SCREEN_SWITCH_EFFECT_DOUBLE_PAGE_INITIAL_SKIP_FRAME_NUM);   

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();    
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_effect_diagonal_flip
 * DESCRIPTION
 *  Setups SSE effect parameters
 * PARAMETERS
 *  page_direction           [IN]  page direction
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_effect_diagonal_flip(gui_screen_switch_effect_type_enum page_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    float *transform_matrix_p;

#define GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_INITIAL_SKIP_FRAME_NUM 0   /* skip frames at first to speed up a little */

#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
#define GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_FRAME_NUM 6                /* total frames for page turn */
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
#define GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_FRAME_NUM 4                /* total frames for page turn */
#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
#define GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_FRAME_NUM 4                /* total frames for page turn */
#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
#define GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_FRAME_NUM 4                /* total frames for page turn */
#else
        /* 176 x 220 */
#define GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_FRAME_NUM 6                /* total frames for page turn */
#endif /* defined(__MMI_MAINLCD_240X400__) */

#if defined(__CPU_ARM7EJ_S__)
#define GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_TIMER_UNIT   33
#else /* defined(__CPU_ARM7EJ_S__) */
#define GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_TIMER_UNIT   50
#endif /* defined(__CPU_ARM7EJ_S__) */

    const gui_sse_projective_transform_matrix_struct projective_transform_matrix[GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_FRAME_NUM * 2 - 1] = 
    {
#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
        {0.85515F, 0.13547F, 0.00007F, 0.05594F, 0.86710F, -0.00017F, 0.00000F, 0.00000F},
        {0.74954F, 0.22612F, 0.00002F, 0.12357F, 0.81982F, -0.00012F, 0.00000F, 0.00000F},
        {0.58360F, 0.37811F, -0.00006F, 0.21885F, 0.72149F, -0.00010F, 0.00000F, 0.00000F},
        {0.59241F, -0.37917F, 0.00019F, -0.27250F, 0.58242F, -0.00048F, 109.00000F, 91.00000F},
        {0.69493F, -0.25417F, -0.00002F, -0.18000F, 0.77403F, -0.00018F, 72.00000F, 61.00000F},
        {0.81545F, -0.13750F, -0.00007F, -0.10000F, 0.85853F, -0.00015F, 40.00000F, 33.00000F},
        
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
        {0.78954F, 0.22936F, 0.00024F, 0.09992F, 0.75074F, -0.00042F, 0.00000F, 0.00000F},
        {0.59763F, 0.38957F, 0.00026F, 0.20448F, 0.57809F, -0.00060F, 0.00000F, 0.00000F},
        {0.51980F, -0.36667F, -0.00007F, -0.34688F, 0.57438F, -0.00047F, 111.00000F, 88.00000F},
        {0.70730F, -0.22500F, -0.00018F, -0.18750F, 0.71431F, -0.00037F, 60.00000F, 54.00000F},

#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
        {0.82927F, 0.15259F, 0.00019F, 0.17187F, 0.75473F, -0.00043F, 0.00000F, 0.00000F},
        {0.67432F, 0.27726F, 0.00030F, 0.24882F, 0.49125F, -0.00098F, 0.00000F, 0.00000F},
        {0.51060F, -0.27500F, -0.00037F, -0.49583F, 0.44614F, -0.00078F, 119.00000F, 88.00000F},
        {0.74956F, -0.14063F, -0.00005F, -0.31250F, 0.70396F, -0.00045F, 75.00000F, 45.00000F},

#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
        {0.72684F, 0.20860F, 0.00013F, 0.06513F, 0.68547F, -0.00046F, 0.00000F, 0.00000F},
        {0.58814F, 0.39536F, 0.00014F, 0.15502F, 0.55709F, -0.00047F, 0.00000F, 0.00000F},
        {0.48391F, -0.38438F, -0.00015F, -0.31250F, 0.47326F, -0.00056F, 150.00000F, 123.00000F},
        {0.64842F, -0.23125F, -0.00024F, -0.18333F, 0.68247F, -0.00034F, 88.00000F, 74.00000F},

#else
        /* 176 x 220 */
        {0.81851F, -0.13068F, 0.00003F, -0.15000F, 0.82488F, -0.00032F, 33.00000F, 23.00000F},
        {0.76048F, -0.21591F, 0.00035F, -0.24091F, 0.75710F, -0.00032F, 53.00000F, 38.00000F},
        {0.53311F, -0.34091F, -0.00001F, -0.37273F, 0.55858F, -0.00077F, 82.00000F, 60.00000F},
        {0.59140F, 0.37579F, 0.00048F, 0.18934F, 0.52745F, -0.00116F, 0.00000F, 0.00000F},
        {0.68015F, 0.23046F, -0.00006F, 0.16255F, 0.69897F, -0.00048F, 0.00000F, 0.00000F},
        {0.81499F, 0.11803F, -0.00006F, 0.07995F, 0.82050F, -0.00034F, 0.00000F, 0.00000F},
#endif /* defined(__MMI_MAINLCD_240X400__) */
    };
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

    gui_screen_switch_effect_create_world();
    
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);

    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);

    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_FRAME_NUM;
    
    for (i = 0; i < GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_FRAME_NUM; i++)
    {
        if (page_direction == GUI_SCREEN_SWITCH_EEFECT_DIAGONAL_FLIP_TURN_LEFT)
        {
            transform_matrix_p = (float*)projective_transform_matrix[i].m;
        }
        else
        {
            transform_matrix_p = (float*)projective_transform_matrix[GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_FRAME_NUM - 1 - i].m;
        }

        g_gui_screen_switch_effect_object_param[0][i].bg_color = GDI_COLOR_GRAY;
        g_gui_screen_switch_effect_object_param[1][i].bg_color = GDI_COLOR_GRAY;
        
        if (i < GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_FRAME_NUM / 2)
        {
            g_gui_screen_switch_effect_object_param[0][i].transform_matrix = transform_matrix_p;
            g_gui_screen_switch_effect_object_param[1][i].scale_x = 0;
        }
        else
        {
            g_gui_screen_switch_effect_object_param[1][i].transform_matrix = transform_matrix_p;
            g_gui_screen_switch_effect_object_param[0][i].scale_x = 0;
        }
        
    }

    /* skip beginning frames to speed up a little since the old screen is not so important */
    gui_screen_switch_effect_skip_beginning_frames(GUI_SCREEN_SWITCH_EFFECT_DIAGONAL_FLIP_INITIAL_SKIP_FRAME_NUM);   

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();    
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_effect_individual_flip
 * DESCRIPTION
 *  Setups SSE effect parameters
 * PARAMETERS
 *  page_direction           [IN]  page direction
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_effect_individual_flip(gui_screen_switch_effect_type_enum page_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    float *transform_matrix_p;

#define GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_INITIAL_SKIP_FRAME_NUM 0   /* skip frames at first to speed up a little */

#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
#define GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM 6                /* total frames for page turn */
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
#define GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM 4                /* total frames for page turn */
#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
#define GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM 4                /* total frames for page turn */
#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
#define GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM 4                /* total frames for page turn */
#else
        /* 176 x 220 */
#define GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM 6                /* total frames for page turn */
#endif /* defined(__MMI_MAINLCD_240X400__) */

#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
#define GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_TIMER_UNIT   33
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
#define GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_TIMER_UNIT   33
#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
#define GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_TIMER_UNIT   33
#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
#define GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_TIMER_UNIT   33
#else
        /* 176 x 220 */
#define GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_TIMER_UNIT   33
#endif /* defined(__MMI_MAINLCD_240X400__) */


#if defined(__MMI_MAINLCD_240X400__)
            /* 240 x 400 */
const U8 gui_sse_individual_flip_opacity_story[GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 1] = {200, 160, 120, 80, 40};
#elif defined(__MMI_MAINLCD_240X320__)
            /* 240 x 320 */
const U8 gui_sse_individual_flip_opacity_story[GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 1] = {200, 120, 40};
#elif defined(__MMI_MAINLCD_320X240__)
            /* 320 x 240 */
const U8 gui_sse_individual_flip_opacity_story[GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 1] = {200, 120, 40};
#elif defined(__MMI_MAINLCD_320X480__)
            /* 320 x 480 */
const U8 gui_sse_individual_flip_opacity_story[GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 1] = {200, 120, 40};
#else
            /* 176 x 220 */
const U8 gui_sse_individual_flip_opacity_story[GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 1] = {200, 160, 120, 80, 40};
#endif /* defined(__MMI_MAINLCD_240X400__) */


    const gui_sse_projective_transform_matrix_struct projective_transform_matrix[(GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 1) * 2] = 
    {
#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
        {1.00000F, 0.00000F, 0.00000F, 0.03981F, 1.00095F, 0.00034F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, 0.12651F, 0.95783F, 0.00111F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, 0.19034F, 0.85241F, 0.00164F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, 0.27805F, 0.76098F, 0.00238F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, 0.44211F, 0.72632F, 0.00382F, 0.00000F, 0.00000F},
        {0.43333F, 0.00000F, 0.00000F, -0.16750F, -0.27917F, -0.00142F, 67.00000F, 285.00000F},
        {0.50833F, 0.00000F, 0.00000F, -0.14000F, -0.17667F, -0.00123F, 56.00000F, 274.00000F},
        {0.58333F, 0.00000F, 0.00000F, -0.12250F, 0.01083F, -0.00104F, 49.00000F, 229.00000F},
        {0.66667F, 0.00000F, 0.00000F, -0.09750F, 0.23417F, -0.00083F, 39.00000F, 173.00000F},
        {0.78750F, 0.00000F, 0.00000F, -0.06250F, 0.52750F, -0.00053F, 25.00000F, 104.00000F},
        
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
        {1.00000F, 0.00000F, 0.00000F, 0.05383F, 0.99402F, 0.00046F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, 0.20364F, 0.78974F, 0.00184F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, 0.39474F, 0.57237F, 0.00345F, 0.00000F, 0.00000F},
        {0.47500F, 0.00000F, 0.00000F, -0.19063F, -0.20000F, -0.00164F, 61.00000F, 216.00000F},
        {0.59583F, 0.00000F, 0.00000F, -0.14688F, 0.16771F, -0.00126F, 47.00000F, 137.00000F},
        {0.75000F, 0.00000F, 0.00000F, -0.09375F, 0.48750F, -0.00078F, 30.00000F, 84.00000F},

#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
        {1.00000F, 0.00000F, 0.00000F, 0.06393F, 0.94064F, 0.00040F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, 0.30622F, 0.75917F, 0.00221F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, 0.81752, 0.67153F, 0.00557F, 0.00000F, 0.00000F},
        {0.47813F, 0.00000F, 0.00000F, -0.34583F, -0.18854F, -0.00217F, 83.00000F, 160.00000F},
        {0.63125F, 0.00000F, 0.00000F, -0.23750F, 0.16875F, -0.00154F, 57.00000F, 111.00000F},
        {0.76875F, 0.00000F, 0.00000F, -0.15000F, 0.51875F, -0.00096F, 36.00000F, 60.00000F},

#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
        {1.00000F, 0.00000F, 0.00000F, 0.05314F, 1.00000F, 0.00033F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, 0.19237F, 0.78607F, 0.00123F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, 0.31224F, 0.56962F, 0.00214F, 0.00000F, 0.00000F},
        {0.48438F, 0.00000F, 0.00000F, -0.15833F, -0.18854F, -0.00107F, 76.00000F, 323.00000F},
        {0.61875F, 0.00000F, 0.00000F, -0.11875F, 0.16250F, -0.00079F, 57.00000F, 219.00000F},
        {0.77188F, 0.00000F, 0.00000F, -0.07500F, 0.52604F, -0.00048F, 36.00000F, 118.00000F},

#else
        /* 176 x 220 */
        {1.00000F, 0.00000F, 0.00000F, 0.05161F, 1.01161F, 0.00062F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, 0.14375F, 0.91875F, 0.00170F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, 0.28235F, 0.86275F, 0.00330F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, 0.34409F, 0.79140F, 0.00406F, 0.00000F, 0.00000F},
        {1.00000F, 0.00000F, 0.00000F, 0.58889F, 0.71111F, 0.00657F, 0.00000F, 0.00000F},
        {0.47159F, 0.00000F, 0.00000F, -0.20909F, -0.24659F, -0.00240F, 46.00000F, 158.00000F},
        {0.50568F, 0.00000F, 0.00000F, -0.19091F, -0.18523F, -0.00225F, 42.00000F, 152.00000F},
        {0.58523F, 0.00000F, 0.00000F, -0.16364F, -0.01932F, -0.00189F, 36.00000F, 133.00000F},
        {0.62500F, 0.00000F, 0.00000F, -0.15000F, 0.19773F, -0.00170F, 33.00000F, 94.00000F},
        {0.78977F, 0.00000F, 0.00000F, -0.08636F, 0.53523F, -0.00096F, 19.00000F, 56.00000F},
#endif /* defined(__MMI_MAINLCD_240X400__) */
    };
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

    gui_screen_switch_effect_create_world();
    
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);

    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);

#if defined(__CPU_ARM7EJ_S__)
    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_TIMER_UNIT;
#else /* defined(__CPU_ARM7EJ_S__) */
    g_gui_screen_switch_effect_frame_duration = 50;
#endif /* defined(__CPU_ARM7EJ_S__) */
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM;

    if (page_direction == GUI_SCREEN_SWITCH_EEFECT_INDIVIDUAL_FLIP_UP)
    {
        for (i = 0; i < GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 1; i++)
        {
            transform_matrix_p = (float*)projective_transform_matrix[i].m;
            g_gui_screen_switch_effect_object_param[0][i].transform_matrix = transform_matrix_p;
            g_gui_screen_switch_effect_object_param[0][i].opacity = gui_sse_individual_flip_opacity_story[i];
            
            transform_matrix_p = (float*)projective_transform_matrix[i + GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 1].m;
            g_gui_screen_switch_effect_object_param[1][i + 1].transform_matrix = transform_matrix_p;
            g_gui_screen_switch_effect_object_param[1][i + 1].opacity = gui_sse_individual_flip_opacity_story[GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 2 - i];

            g_gui_screen_switch_effect_object_param[0][i].bg_color = GDI_COLOR_GRAY;
            g_gui_screen_switch_effect_object_param[1][i].bg_color = GDI_COLOR_GRAY;
        }
    }
    else
    {
        for (i = 0; i < GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 1; i++)
        {
            transform_matrix_p = (float*)projective_transform_matrix[(GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 1) * 2 - i - 1].m;
            g_gui_screen_switch_effect_object_param[0][i].transform_matrix = transform_matrix_p;
            g_gui_screen_switch_effect_object_param[0][i].opacity = gui_sse_individual_flip_opacity_story[i];
            
            transform_matrix_p = (float*)projective_transform_matrix[GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 1 - i - 1].m;
            g_gui_screen_switch_effect_object_param[1][i + 1].transform_matrix = transform_matrix_p;
            g_gui_screen_switch_effect_object_param[1][i + 1].opacity = gui_sse_individual_flip_opacity_story[GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 2 - i];

            g_gui_screen_switch_effect_object_param[0][i].bg_color = GDI_COLOR_GRAY;
            g_gui_screen_switch_effect_object_param[1][i].bg_color = GDI_COLOR_GRAY;
        }
    }
    
    g_gui_screen_switch_effect_object_param[0][GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 1].scale_x = 0;
    g_gui_screen_switch_effect_object_param[1][0].scale_x = 0;

    g_gui_screen_switch_effect_object_param[0][GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 1].bg_color = GDI_COLOR_GRAY;
    g_gui_screen_switch_effect_object_param[1][GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_FRAME_NUM - 1].bg_color = GDI_COLOR_GRAY;

    /* skip beginning frames to speed up a little since the old screen is not so important */
    gui_screen_switch_effect_skip_beginning_frames(GUI_SCREEN_SWITCH_EFFECT_INDIVIDUAL_FLIP_INITIAL_SKIP_FRAME_NUM);   

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();    
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_effect_oblique_fly
 * DESCRIPTION
 *  Setups SSE effect parameters
 * PARAMETERS
 *  page_direction           [IN]  page direction
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_effect_oblique_fly(gui_screen_switch_effect_type_enum page_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    float *transform_matrix_p;

#define GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_INITIAL_SKIP_FRAME_NUM 0   /* skip frames at first to speed up a little */

#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
#define GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM 6                /* total frames for page turn */
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
#define GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM 4                /* total frames for page turn */
#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
#define GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM 4                /* total frames for page turn */
#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
#define GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM 4                /* total frames for page turn */
#else
        /* 176 x 220 */
#define GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM 6                /* total frames for page turn */
#endif /* defined(__MMI_MAINLCD_240X400__) */

#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
#define GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_TIMER_UNIT   50
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
#define GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_TIMER_UNIT   33
#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
#define GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_TIMER_UNIT   33
#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
#define GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_TIMER_UNIT   33
#else
        /* 176 x 220 */
#define GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_TIMER_UNIT   33
#endif /* defined(__MMI_MAINLCD_240X400__) */


#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
const U8 gui_sse_oblique_fly_opacity_story[GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM] = {200, 180, 160, 140, 120, 100};
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
const U8 gui_sse_oblique_fly_opacity_story[GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM] = {200, 170, 140, 100};
#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
const U8 gui_sse_oblique_fly_opacity_story[GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM] = {200, 170, 140, 100};
#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
const U8 gui_sse_oblique_fly_opacity_story[GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM] = {200, 170, 140, 100};
#else
        /* 176 x 220 */
const U8 gui_sse_oblique_fly_opacity_story[GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM] = {200, 180, 160, 140, 120, 100};
#endif /* defined(__MMI_MAINLCD_240X400__) */


    const gui_sse_projective_transform_matrix_struct projective_transform_matrix[GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM] = 
    {
#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
        {0.76250F, -0.10833F, -0.00057F, 0.00000F, 0.86250F, 0.00000F, 24.00000F, 26.00000F},
        {0.38667F, -0.28750F, -0.00138F, 0.00000F, 0.67000F, 0.00000F, 68.00000F, 69.00000F},
        {0.24345F, -0.27393F, -0.00139F, 0.00000F, 0.44250F, 0.00000F, 68.00000F, 107.00000F},
        {0.10656F, -0.35604F, -0.00165F, 0.00000F, 0.25250F, 0.00000F, 47.00000F, 155.00000F},
        {0.07987F, -0.35023F, -0.00164F, 0.00000F, 0.16250F, 0.00000F, 27.00000F, 177.00000F},
        {0.04644F, -0.40783F, -0.00189F, 0.00000F, 0.10250F, 0.00000F, 14.00000F, 193.00000F},
        
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
        {0.78958F, -0.07917F, -0.00055F, 0.00000F, 0.86875F, 0.00000F, 19.00000F, 19.00000F},
        {0.34687F, -0.22500F, -0.00142F, 0.00000F, 0.65938F, 0.00000F, 75.00000F, 54.00000F},
        {0.12603F, -0.28301F, -0.00167F, 0.00000F, 0.26563F, 0.00000F, 35.00000F, 120.00000F},
        {0.08070F, -0.25860F, -0.00158F, 0.00000F, 0.18438F, 0.00000F, 21.00000F, 131.00000F},

#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
        {0.78021F, -0.05000F, -0.00044F, 0.00000F, 0.85833F, 0.00000F, 25.00000F, 16.00000F},
        {0.37396F, -0.12813F, -0.00103F, 0.00000F, 0.67083F, 0.00000F, 95.00000F, 41.00000F},
        {0.10223F, -0.17232F, -0.00134F, 0.00000F, 0.28333F, 0.00000F, 57.00000F, 90.00000F},
        {0.09793F, -0.14008F, -0.00114F, 0.00000F, 0.19583F, 0.00000F, 29.00000F, 95.00000F},

#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
        {0.77500F, -0.11250F, -0.00047F, 0.00000F, 0.85000F, 0.00000F, 24.00000F, 36.00000F},
        {0.39063F, -0.24375F, -0.00102F, 0.00000F, 0.67500F, 0.00000F, 91.00000F, 78.00000F},
        {0.11405F, -0.28657F, -0.00114F, 0.00000F, 0.25625F, 0.00000F, 51.00000F, 183.00000F},
        {0.09063F, -0.30376F, -0.00121F, 0.00000F, 0.18750F, 0.00000F, 31.00000F, 197.00000F},

#else
        /* 176 x 220 */
        {0.80568F, -0.06818F, -0.00062F, 0.00000F, 0.89091F, 0.00000F, 15.00000F, 12.00000F},
        {0.38864F, -0.18182F, -0.00173F, 0.00000F, 0.69545F, 0.00000F, 54.00000F, 32.00000F},
        {0.24765F, -0.21120F, -0.00174F, 0.00000F, 0.49545F, 0.00000F, 55.00000F, 58.00000F},
        {0.16381F, -0.21470F, -0.00181F, 0.00000F, 0.29091F, 0.00000F, 27.00000F, 80.00000F},
        {0.08658F, -0.21735F, -0.00187F, 0.00000F, 0.20455F, 0.00000F, 17.00000F, 94.00000F},
        {0.06934F, -0.21974F, -0.00186F, 0.00000F, 0.15000F, 0.00000F, 8.00000F, 104.00000F},
#endif /* defined(__MMI_MAINLCD_240X400__) */
    };
    U8* curr_screen_buf_ptr = gui_sse_save_and_get_current_screen_buffer();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

    gui_screen_switch_effect_create_world();

    if (page_direction == GUI_SCREEN_SWITCH_EEFECT_OBLIQUE_FLY_OUT)
    {
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
    }
    else
    {
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
        gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, UI_device_width, UI_device_height, 16, 0, (PU8)curr_screen_buf_ptr, gui_screen_switch_effect_object_get_param_callback);
    }

#if defined(__CPU_ARM7EJ_S__)
    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_TIMER_UNIT;
#else /* defined(__CPU_ARM7EJ_S__) */
    g_gui_screen_switch_effect_frame_duration = 50;
#endif /* defined(__CPU_ARM7EJ_S__) */
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM;

    for (i = 0; i < GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM; i++)
    {
        if (page_direction == GUI_SCREEN_SWITCH_EEFECT_OBLIQUE_FLY_OUT)
        {
            transform_matrix_p = (float*)projective_transform_matrix[i].m;
            g_gui_screen_switch_effect_object_param[0][i].opacity = gui_sse_oblique_fly_opacity_story[GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM - 1 - i];
        }
        else
        {
            transform_matrix_p = (float*)projective_transform_matrix[GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_FRAME_NUM - 1 - i].m;
            g_gui_screen_switch_effect_object_param[0][i].opacity = gui_sse_oblique_fly_opacity_story[i];
        }
        
        g_gui_screen_switch_effect_object_param[1][i].transform_matrix = transform_matrix_p;
        g_gui_screen_switch_effect_object_param[1][i].opacity = 150;

    }
    
    /* skip beginning frames to speed up a little since the old screen is not so important */
    gui_screen_switch_effect_skip_beginning_frames(GUI_SCREEN_SWITCH_EFFECT_OBLIQUE_FLY_INITIAL_SKIP_FRAME_NUM);   

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();    
}

/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_run_backup_effect
 * DESCRIPTION
 *  Runs the screen switch backup effect. not used by internal project.
 * PARAMETERS
 *  effect_type       [IN]      screen switch effect type
 * RETURNS
 *  void
 *****************************************************************************/

void gui_screen_switch_effect_run_backup_effect(gui_screen_switch_effect_type_enum effect_type)
{
    switch(effect_type)
    {
        case GUI_SCREEN_SWITCH_EFFECT_ZOOM_IN:
        case GUI_SCREEN_SWITCH_EFFECT_ZOOM_OUT:
            gui_screen_switch_effect_zoom(effect_type);
            break;
        case GUI_SCREEN_SWITCH_EFFECT_SUBMENU_SLIDE_LEFT:
        case GUI_SCREEN_SWITCH_EFFECT_SUBMENU_SLIDE_RIGHT:
            gui_screen_switch_effect_submenu_slide(effect_type);
            break;
        case GUI_SCREEN_SWITCH_EFFECT_ROTATE_IN:
        case GUI_SCREEN_SWITCH_EFFECT_ROTATE_OUT:
            gui_screen_switch_effect_rotate(effect_type);
            break;
        case GUI_SCREEN_SWITCH_EFFECT_PAGE_TURN_LEFT:
        case GUI_SCREEN_SWITCH_EFFECT_PAGE_TURN_RIGHT:
            gui_screen_switch_effect_page_turn(effect_type);
            break;
        case GUI_SCREEN_SWITCH_EFFECT_MOVE_OUT_LEFT:
        case GUI_SCREEN_SWITCH_EFFECT_MOVE_OUT_RIGHT:
        case GUI_SCREEN_SWITCH_EFFECT_MOVE_OUT_DOWN:
        case GUI_SCREEN_SWITCH_EFFECT_MOVE_OUT_UP:
            gui_screen_switch_effect_move_out(effect_type);
            break;
        case GUI_SCREEN_SWITCH_EEFECT_REVOLVING_GATE_TURN_LEFT:
        case GUI_SCREEN_SWITCH_EEFECT_REVOLVING_GATE_TURN_RIGHT:
            gui_screen_effect_revolving_gate_page(effect_type);
            break;
            
        case GUI_SCREEN_SWITCH_EEFECT_DIAGONAL_FLIP_TURN_LEFT:
        case GUI_SCREEN_SWITCH_EEFECT_DIAGONAL_FLIP_TURN_RIGHT:
            gui_screen_effect_diagonal_flip(effect_type);
            break;
        
        case GUI_SCREEN_SWITCH_EEFECT_INDIVIDUAL_FLIP_UP:
        case GUI_SCREEN_SWITCH_EEFECT_INDIVIDUAL_FLIP_DOWN:
            gui_screen_effect_individual_flip(effect_type);
            break;
        
        case GUI_SCREEN_SWITCH_EEFECT_OBLIQUE_FLY_OUT:
        case GUI_SCREEN_SWITCH_EEFECT_OBLIQUE_FLY_IN:
            gui_screen_effect_oblique_fly(effect_type);
            break;


    }
 
}

#endif /* __GUI_SSE_BACKUP_EFFECT_ON__ */


#ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
/*****************************************************************************
 * FUNCTION
 *  gui_screen_effect_icon_flip
 * DESCRIPTION
 *  Setups SSE effect parameters
 * PARAMETERS
 *  page_direction           [IN]  page direction
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_effect_icon_flip(gui_screen_switch_effect_type_enum page_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    float *transform_matrix_p;
    S32 x, y, width, height;
    gdi_handle layer_a, layer_icon, wallpaper_layer;

#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_INITIAL_SKIP_FRAME_NUM 0   /* skip frames at first to speed up a little */

#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM          10                    /* total frames  */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_FLIP   6
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_SCALE (GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM - GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_FLIP)
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM          10                    /* total frames  */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_FLIP   6
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_SCALE (GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM - GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_FLIP)
#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM          10                    /* total frames  */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_FLIP   6
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_SCALE (GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM - GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_FLIP)
#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM 0                /* total frames */
#else
        /* 176 x 220 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM 0                /* total frames  */
#endif /* defined(__MMI_MAINLCD_240X400__) */

#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_TIMER_UNIT   33
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_TIMER_UNIT   33
#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_TIMER_UNIT   33
#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_TIMER_UNIT   33
#else
        /* 176 x 220 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_TIMER_UNIT   33
#endif /* defined(__MMI_MAINLCD_240X400__) */


#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
const U8 gui_sse_icon_flip_opacity_story[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM] = {210, 180, 150, 130, 110, 90, 70};

const S32 gui_sse_icon_flip_scale_frame_scale_story[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_SCALE] = {GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.5), GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.8), GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.9), GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.95)};
const S32 gui_sse_icon_flip_scale_frame_offset_x_story[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_SCALE] = {0, 0, 0, 0};
const S32 gui_sse_icon_flip_scale_frame_offset_y_story[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_SCALE] = {200, 80, 39, 20};
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
const U8 gui_sse_icon_flip_opacity_story[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM] = {210, 180, 150, 130, 110, 90, 70};

const S32 gui_sse_icon_flip_scale_frame_scale_story[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_SCALE] = {GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.5), GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.8), GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.9), GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.95)};
const S32 gui_sse_icon_flip_scale_frame_offset_x_story[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_SCALE] = {0, 0, 0, 0};
const S32 gui_sse_icon_flip_scale_frame_offset_y_story[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_SCALE] = {160, 65, 33, 17};
#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
const U8 gui_sse_icon_flip_opacity_story[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM] = {210, 180, 150, 130, 110, 90, 70};

const S32 gui_sse_icon_flip_scale_frame_scale_story[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_SCALE] = {GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.5), GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.8), GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.9), GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(0.95)};
const S32 gui_sse_icon_flip_scale_frame_offset_x_story[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_SCALE] = {0, 0, 0, 0};
const S32 gui_sse_icon_flip_scale_frame_offset_y_story[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_SCALE] = {120, 48, 24, 12};
#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
const U8 gui_sse_icon_flip_opacity_story[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM] = {0, 0, 0, 0, 0};
#else
        /* 176 x 220 */
const U8 gui_sse_icon_flip_opacity_story[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM] = {0, 0, 0, 0, 0};
#endif /* defined(__MMI_MAINLCD_240X400__) */



#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_X               0                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_Y               350                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_WIDTH        60                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_HEIGHT       50                    

#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_X               0                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_Y               270                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_WIDTH        60                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_HEIGHT       50                    
#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_X               0                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_Y               190                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_WIDTH        80                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_HEIGHT       50                    
#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_X               0                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_Y               350                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_WIDTH        60                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_HEIGHT       50                    
#else
        /* 176 x 220 */
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_X               0                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_Y               350                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_WIDTH        60                    
#define GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_HEIGHT       50                    
#endif /* defined(__MMI_MAINLCD_240X400__) */

    const gui_sse_projective_transform_matrix_struct projective_transform_matrix[GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM] = 
    {
#if defined(__MMI_MAINLCD_240X400__)
        /* 240 x 400 */
        {1.04756F, 0.08130F, 0.00366F, 0.00000F, 1.00000F, 0.00000F, 3.00000F, 0.00000F},
        {1.00686F, 0.23725F, 0.00882F, 0.00000F, 1.04000F, 0.00000F, 13.00000F, -2.00000F},
        {0.70152F, 0.22727F, 0.00859F, 0.00000F, 1.00000F, 0.00000F, 17.00000F, 0.00000F},
        {0.03068F, -0.46250F, -0.00123F, 0.00000F, 0.07750F, 0.00000F, 18.00000F, 359.00000F},
        {0.08011F, -0.35833F, -0.00095F, 0.00000F, 0.08500F, 0.00000F, 14.00000F, 358.00000F},
        {0.14330F, -0.23922F, -0.00063F, 0.00000F, 0.09750F, 0.00000F, 8.00000F, 355.00000F},
#elif defined(__MMI_MAINLCD_240X320__)
        /* 240 x 320 */
        {1.04756F, 0.08130F, 0.00366F, 0.00000F, 1.00000F, 0.00000F, 3.00000F, 0.00000F},
        {1.00686F, 0.23725F, 0.00882F, 0.00000F, 1.04000F, 0.00000F, 13.00000F, -2.00000F},
        {0.70152F, 0.22727F, 0.00859F, 0.00000F, 1.00000F, 0.00000F, 17.00000F, 0.00000F},
        {0.05736F, -0.31909F, -0.00107F, 0.00000F, 0.10000F, 0.00000F, 16.00000F, 279.00000F},
        {0.11017F, -0.23169F, -0.00078F, 0.00000F, 0.10938F, 0.00000F, 11.00000F, 277.00000F},
        {0.16429F, -0.17738F, -0.00060F, 0.00000F, 0.13125F, 0.00000F, 6.00000F, 274.00000F},
#elif defined(__MMI_MAINLCD_320X240__)
        /* 320 x 240 */
        {1.00987F, 0.06579F, 0.00395F, 0.00000F, 1.00000F, 0.00000F, 10.00000F, 0.00000F},
        {0.99167F, 0.22083F, 0.00833F, 0.00000F, 1.00000F, 0.00000F, 19.00000F, -1.00000F},
        {0.89348F, 0.27337F, 0.01141F, 0.00000F, 0.88000F, 0.00000F, 28.00000F, 3.00000F},
        {0.01166F, -0.29566F, -0.00137F, 0.00000F, 0.09583F, 0.00000F, 26.00000F, 204.00000F},
        {0.06269F, -0.21467F, -0.00102F, 0.00000F, 0.13750F, 0.00000F, 19.00000F, 198.00000F},
        {0.14044F, -0.11938F, -0.00056F, 0.00000F, 0.17083F, 0.00000F, 10.00000F, 194.00000F},
#elif defined(__MMI_MAINLCD_320X480__)
        /* 320 x 480 */

#else
        /* 176 x 220 */

#endif /* defined(__MMI_MAINLCD_240X400__) */
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

    if (!wgui_cat033_shortcut_get_mainmenu_area(&x, &y, &width, &height))
    {
        return;
    }

    if (x != GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_X ||
        y != GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_Y ||
        width != GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_WIDTH ||
        height != GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_HEIGHT)
    {
        return;
    }

    gui_screen_switch_effect_create_world();

    /*old screen layer */
    gdi_layer_create_cf_using_outside_memory(
        GUI_EFFECT_LAYER_COLOR_FORMAT,
        0,
        0,
        UI_device_width,
        UI_device_height,
        &layer_a,
        (U8*)g_gui_screen_switch_effect_buf_a,
        UI_device_width * UI_device_height * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE);  

    /* icon layer */
    gdi_layer_create_cf_using_outside_memory(
        GUI_EFFECT_LAYER_COLOR_FORMAT,
        0,
        0,
        width,
        height,
        &layer_icon,
        (U8*)g_gui_screen_switch_effect_buf_c + GUI_SCREEN_SWITCH_EFFECT_TEMP_BUFFER_SIZE - width * height * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE,
        width * height * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE);     
    
    /* wallpaper layer */
    gdi_layer_create_cf_using_outside_memory(
        GUI_EFFECT_LAYER_COLOR_FORMAT,
        0,
        0,
        UI_device_width,
        UI_device_height,
        &wallpaper_layer,
        (U8*)g_gui_screen_switch_effect_buf_b,
        UI_device_width * UI_device_height * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE);  

    gdi_layer_push_and_set_active(layer_a);

    gdi_layer_set_position(-x, -y);
    gdi_layer_set_active(layer_icon);
    gdi_layer_flatten(layer_a, 0, 0, 0);
    
    gdi_layer_set_active(layer_a);
    gdi_layer_set_position(0, 0);
    gdi_layer_push_clip();
    gdi_layer_set_clip(x, y, x + width - 1, y + height - 1);       
    gdi_layer_flatten_with_clipping(wallpaper_layer, 0, 0, 0);
    gdi_layer_pop_clip();
    
    gdi_layer_pop_and_restore_active();
    
    gdi_layer_free(layer_a);
    gdi_layer_free(layer_icon);
    gdi_layer_free(wallpaper_layer);
    
    gui_screen_switch_effect_save_current_screen((PU8)g_gui_screen_switch_effect_buf_b);


    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 0, 0, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_a, gui_screen_switch_effect_object_get_param_callback);
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 1, 1, width, height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_c + GUI_SCREEN_SWITCH_EFFECT_TEMP_BUFFER_SIZE - width * height * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE, gui_screen_switch_effect_object_get_param_callback);
    gui_screen_switch_effect_create_object(g_gui_screen_switch_effect_object + 2, 2, UI_device_width, UI_device_height, 16, 0, (PU8)g_gui_screen_switch_effect_buf_b, gui_screen_switch_effect_object_get_param_callback);

    g_gui_screen_switch_effect_object[0].enable_source_key = MMI_FALSE;

    g_gui_screen_switch_effect_frame_duration = GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_TIMER_UNIT;
    g_gui_screen_switch_effect_frames = GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM;

    for (i = 0; i < GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM; i++)
    {
        transform_matrix_p = (float*)projective_transform_matrix[i].m;
        g_gui_screen_switch_effect_object_param[0][i].opacity = gui_sse_icon_flip_opacity_story[i];

        if (i < GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_FLIP / 2)
        {
            g_gui_screen_switch_effect_object_param[1][i].transform_matrix = transform_matrix_p;
            g_gui_screen_switch_effect_object_param[1][i].offset_x = x;
            g_gui_screen_switch_effect_object_param[1][i].offset_y = y;
            g_gui_screen_switch_effect_object_param[2][i].offset_x = -UI_device_width;
        }
        else if (i < GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_FLIP)
        {
            g_gui_screen_switch_effect_object_param[2][i].transform_matrix = transform_matrix_p;
            g_gui_screen_switch_effect_object_param[1][i].offset_x = -UI_device_width;
        }
        else
        {
            g_gui_screen_switch_effect_object_param[2][i].scale_x = gui_sse_icon_flip_scale_frame_scale_story[i - GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_FLIP];
            g_gui_screen_switch_effect_object_param[2][i].scale_y = gui_sse_icon_flip_scale_frame_scale_story[i - GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_FLIP];
            g_gui_screen_switch_effect_object_param[2][i].offset_x = gui_sse_icon_flip_scale_frame_offset_x_story[i - GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_FLIP];
            g_gui_screen_switch_effect_object_param[2][i].offset_y = gui_sse_icon_flip_scale_frame_offset_y_story[i - GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_FRAME_NUM_FLIP];
            g_gui_screen_switch_effect_object_param[1][i].offset_x = -UI_device_width;
        }
    }
    
    /* skip beginning frames to speed up a little since the old screen is not so important */
    gui_screen_switch_effect_skip_beginning_frames(GUI_SCREEN_SWITCH_EFFECT_ICON_FLIP_INITIAL_SKIP_FRAME_NUM);   
    gui_effect_projective_transform_set_subsample_mode(GUI_EFFECT_PROJECTIVE_TRANSFORM_SUBSAMPLE_MODE_BILINEAR);    

    gui_screen_switch_effect_draw_world();
    gui_screen_switch_effect_close_world();    
}
#endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) */

/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_reset_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/

void gui_screen_switch_effect_reset_flag(void)
{
    g_gui_sse_scenario = GUI_SSE_SCENARIO_NONE;
#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    g_gui_screen_switch_effect_from_MM = MMI_FALSE;
#endif
    g_gui_screen_switch_effect_type = 0;
	g_gui_sse_prev_category_id = 0;
    /* reset block effect flag automatically */
    g_gui_sse_is_block_enable = MMI_FALSE;
}



#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
/*****************************************************************************
 * FUNCTION
 *  gui_sse_custom_set_param
 * DESCRIPTION
 *  Sets the custom effect parameter.
 * PARAMETERS
 *  param       [IN]    custom effect parameter structure
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sse_custom_set_param(gui_screen_switch_effect_custom_param_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param->effect_type = (gui_screen_switch_effect_type_enum)g_gui_screen_switch_effect_type;
    param->previous_screen_id = g_gui_screen_switch_effect_previous_screen_id;
    param->previous_category_id = g_gui_sse_previous_category_id;
}

#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) */

/*****************************************************************************
 * FUNCTION
 *  gui_sse_post_check_is_enable
 * DESCRIPTION
 *  chech whether to enable SSE right before gui_sse_launch
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_sse_post_check_is_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define SSE_DISABLE_IF(args)   if (args) return MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SSE_DISABLE_IF(!g_gui_screen_switch_effect_enable);
    SSE_DISABLE_IF(PhnsetGetScreenSwitchEffectStatus() == MMI_PHNSET_SSE_NONE);
    SSE_DISABLE_IF(!srv_bootup_is_completed());
    SSE_DISABLE_IF(gdi_lcd_get_freeze());
    SSE_DISABLE_IF(g_gui_sse_is_block_enable);
    SSE_DISABLE_IF(g_gui_sse_is_dummy_screen);
    /* disable if video/preview is running */
    SSE_DISABLE_IF(!gdi_layer_flatten_is_ready());

    {
        S32 frame_buffer_lock_count = 0;

        gdi_layer_get_frame_buffer_lock_count(&frame_buffer_lock_count);
        SSE_DISABLE_IF(frame_buffer_lock_count > 0);
    }

    {
        kal_bool is_hw_update = KAL_FALSE;
        gdi_lcd_get_hw_update(&is_hw_update);
        SSE_DISABLE_IF(is_hw_update);
    }

#if defined(__MMI_SCREEN_ROTATE__)
    SSE_DISABLE_IF(mmi_frm_get_screen_rotate() != g_gui_screen_switch_effect_previous_rotation);
    SSE_DISABLE_IF(mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0);
#endif /* defined(__MMI_SCREEN_ROTATE__) */
    SSE_DISABLE_IF(gdi_lcd_get_rotate() != GDI_LAYER_ROTATE_0);

#if defined(__MMI_UCM__)
    SSE_DISABLE_IF(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0);
#endif /* defined(__MMI_UCM__) */

#if defined(__J2ME__)
    SSE_DISABLE_IF(mmi_java_is_installing());
#endif /* defined(__J2ME__) */

#if defined(__MMI_VUI_ENGINE__)
    //SSE_DISABLE_IF(vadp_p2v_uc_is_in_venus());
#endif /* defined(__MMI_VUI_ENGINE__) */

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    SSE_DISABLE_IF(mdi_video_is_playing());
#endif /* __MMI_VIDEO_PLAY_SUPPORT__*/

#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
    SSE_DISABLE_IF(mdi_camera_is_ready_to_capture());
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */

#if defined(__MMI_FTE_SUPPORT__)
    SSE_DISABLE_IF(dm_check_control_exist(g_gui_sse_category_id, DM_POPUP_BACKGROUND));
#endif /* defined(__MMI_FTE_SUPPORT__) */

#if defined(__ATV_SMS_SUPPORT__)
    SSE_DISABLE_IF(dm_is_fixed_layer_mode_enabled());
#endif

#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    SSE_DISABLE_IF(vapp_ncenter_is_entered());
#endif
#if defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__) && defined(__MMI_REDUCED_UI_BUFFER__)
    SSE_DISABLE_IF(vcpSseIsForcedCancel());
#endif

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_pre_setting
 * DESCRIPTION
 *  pre setting SSE, those check should be in APP / category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sse_pre_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dm_check_control_exist(g_gui_sse_category_id, DM_POPUP_BACKGROUND))
    {
        if (dm_check_control_exist(g_gui_sse_prev_category_id, DM_POPUP_BACKGROUND))
        {
            gui_sse_setup_scenario(GUI_SSE_SCENARIO_NO_EFFECT);
        }
        else
        {
            gui_sse_setup_scenario(GUI_SSE_SCENARIO_SMALL_SCREEN_IN);
        }
        //wgui_category_sse_register_popup_sliding();
        return ;
    }

#if defined(__MMI_FTE_SUPPORT__)
	/* work around: disable SSE if previsou screen is popup in FTE project because it can not have effect after popup with background only */
    if (dm_check_control_exist(g_gui_sse_prev_category_id, DM_POPUP_BACKGROUND))
    {
        gui_sse_setup_scenario(GUI_SSE_SCENARIO_NO_EFFECT);
    }
#endif /* defined(__MMI_FTE_SUPPORT__) */

    if (g_gui_sse_is_small_screen)
    {
        gui_sse_setup_scenario(GUI_SSE_SCENARIO_SMALL_SCREEN_IN);
    }
    if (g_gui_sse_category_id == MMI_CATEGORY_CASCADING_MENU_ID)
    {
        gui_sse_setup_scenario(GUI_SSE_SCENARIO_NO_EFFECT);
    }
}

#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */


/***************************************************************************** 
 * Extern Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gui_effect_get_buf_b
 * DESCRIPTION
 *  get SSE buffer B
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
U8* gui_effect_get_buf_b(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    return (U8*)g_gui_screen_switch_effect_buf_b;
#else /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
    return NULL;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_cpy_buf_a2b
 * DESCRIPTION
 *  copy buffer from A to B
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_cpy_buf_a2b(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)

#if defined(__MMI_REDUCED_UI_BUFFER__)
    MMI_ASSERT(g_gui_screen_switch_effect_buf_b && g_gui_screen_switch_effect_buf_a);    
    memcpy(g_gui_screen_switch_effect_buf_b, g_gui_screen_switch_effect_buf_a, GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE);    
#else
    memcpy(g_gui_screen_switch_effect_buf_b, g_gui_screen_switch_effect_buf_a, ui_buffer_get_size(UI_BUFFER_ID_GUI_SSE_BUF_A));
#endif

#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_setup_scenario
 * DESCRIPTION
 *  setup SSE scenario
 * PARAMETERS
 *  scenario    [IN]    scenario
 * RETURNS
 *  void
 *****************************************************************************/
void gui_sse_setup_scenario(gui_sse_scenario_enum scenario)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    g_gui_sse_scenario = scenario;
#if defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__)
    vcpSseSetupScenario(scenario);
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__) */
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}

/*****************************************************************************
 * FUNCTION
 *  gui_sse_get_scenario
 * DESCRIPTION
 *  get SSE scenario
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
gui_sse_scenario_enum gui_sse_get_scenario()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    return g_gui_sse_scenario;
#else
    return GUI_SSE_SCENARIO_NONE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  gui_sse_set_is_dummy_screen
 * DESCRIPTION
 *  set whether it is dummy screen
 * PARAMETERS
 *  is_dummy    [IN]    is dummy screen
 * RETURNS
 *  void
 *****************************************************************************/
void gui_sse_set_is_dummy_screen(MMI_BOOL is_dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    g_gui_sse_is_dummy_screen = is_dummy;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_get_is_dummy_screen
 * DESCRIPTION
 *  get whether it is dummy screen
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_sse_get_is_dummy_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    return g_gui_sse_is_dummy_screen;
#else /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
    return MMI_FALSE;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_set_is_small_screen
 * DESCRIPTION
 *  set whether it is small screen
 * PARAMETERS
 *  is_small    [IN]    is small screen
 * RETURNS
 *  void
 *****************************************************************************/
void gui_sse_set_is_small_screen(MMI_BOOL is_small)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    g_gui_sse_is_small_screen = is_small;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_scenario_begin
 * DESCRIPTION
 *  Begin special SSE scenario for those effect which do not entry new screen
 *  This API will lock frmae buffer and should be used with gui_sse_scenario_commit
 * PARAMETERS
 *  scenario    [IN]    scenario
 * RETURNS
 *  void
 *****************************************************************************/
void gui_sse_scenario_begin(gui_sse_scenario_enum scenario)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    gui_sse_setup_scenario(scenario);

#if defined(__MMI_CALENDAR__) && defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    if (scenario == GUI_SSE_SCENARIO_CALENDAR_PAGE_UP)
    {
        gui_screen_switch_effect_save_current_screen((PU8)g_gui_screen_switch_effect_buf_a);
    }
    else if (scenario == GUI_SSE_SCENARIO_CALENDAR_PAGE_DOWN)
    {
        gui_screen_switch_effect_save_current_screen((PU8)g_gui_screen_switch_effect_buf_b);
    }
#endif /* defined(__MMI_CALENDAR__) */

    gdi_layer_lock_frame_buffer();
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_scenario_commit
 * DESCRIPTION
 *  Launch special SSE scenario for those effect which do not entry new screen
 * PARAMETERS
 *  scenario    [IN]    scenario
 * RETURNS
 *  void
 *****************************************************************************/
void gui_sse_scenario_commit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void gui_sse_launch(void);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    gdi_layer_unlock_frame_buffer();
    gui_sse_launch();
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_setup_scenario
 * DESCRIPTION
 *  setup SSE scenario for MainMenu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_setup_MM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    g_gui_screen_switch_effect_from_MM = MMI_TRUE;
#endif
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_MAINMENU);
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_setup_effect
 * DESCRIPTION
 *  Setups SSE effect parameters
 * PARAMETERS
 *  effect_type           [IN]  effect type
 *  total_frame_num       [IN]  total frame number
 *  frame_duration        [IN]  frame duration
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_setup_effect(gui_screen_switch_effect_type_enum effect_type, S32 total_frame_num, S32 frame_duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    g_gui_screen_switch_effect_type = effect_type;
    g_gui_screen_switch_effect_frames = total_frame_num;
    g_gui_screen_switch_effect_frame_duration = frame_duration;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_is_key_pressed
 * DESCRIPTION
 *  Checks if a key is pressed.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if yes; otherwise MMI_FALSE
 *****************************************************************************/
MMI_BOOL gui_screen_switch_effect_is_key_pressed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mmi_frm_get_key_event_count() > 0) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_is_enabled
 * DESCRIPTION
 *  Checks if SSE is enabled.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if SSE is enabled; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_screen_switch_effect_is_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    if ((PhnsetGetScreenSwitchEffectStatus() != MMI_PHNSET_SSE_NONE)  
        #ifdef __MMI_UCM__
            && (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) <= 0) 
        #endif
        
        #ifdef __J2ME__
            && (!mmi_java_is_installing())
        #endif
            )

    {
        return MMI_TRUE;
    }
    else
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
    {
        return MMI_FALSE;
    }
}

#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY)
/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_default_finish_callback
 * DESCRIPTION
 *  Default screen switch effect finish callback.
 * PARAMETERS
 *  frame_index       [IN]  frame index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_default_finish_callback(S32 frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_screen_switch_effect_close_world();

    /* simply blt the current screen again */
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}
#endif /* #if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) */

/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_register_owner_draw_frame_callback
 * DESCRIPTION
 *  Registers the owner draw frame callback function
 * PARAMETERS
 *  draw_frame_callback       [IN]  owner draw frame callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_register_owner_draw_frame_callback(gui_sse_owner_draw_frame_callback_funcptr_type draw_frame_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    g_gui_sse_owner_draw_frame_callback = draw_frame_callback;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_register_custom_callback
 * DESCRIPTION
 *  Registers the custom callback function
 * PARAMETERS
 *  custom_callback       [IN]  custom callback function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_register_custom_callback(gui_sse_custom_callback_funcptr_type custom_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    g_gui_sse_custom_callback = custom_callback;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}

#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY)

/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_register_finish_callback
 * DESCRIPTION
 *  Registers the screen switch effect finish callback.
 * PARAMETERS
 *  finish_callback       [IN]  finish callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_register_finish_callback(gui_screen_switch_effect_finish_callback_funcptr_type finish_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    g_gui_screen_switch_effect_finish_callback = finish_callback;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}

#endif /* #if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) */


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_block
 * DESCRIPTION
 *  Blocks the SSE effect for the current screen.
 * PARAMETERS
 *  enable       [IN]   enable flag
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_block(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    if (enable == MMI_TRUE)
    {
        g_gui_sse_is_block_enable = MMI_TRUE;
    }
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_force_enable
 * DESCRIPTION
 *  Skips SSE appliable checks to force SSE effects run.
 * PARAMETERS
 *  enable       [IN]   enable flag
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_force_enable(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    g_gui_sse_is_force_enable_effect = enable;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_force_block
 * DESCRIPTION
 *  Forces to block SSE effects.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_force_block(MMI_BOOL is_force_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    g_gui_sse_is_force_block = is_force_block;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}

#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY)

/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_object_get_param_callback
 * DESCRIPTION
 *  Effect object get parameter callback function.
 * PARAMETERS
 *  object       [IN]   effect object
 *  param        [OUT]  object parameter
 *  time         [IN]   frame count
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_object_get_param_callback(gui_screen_switch_effect_object_struct *object, gui_screen_switch_effect_param_struct *param, S32 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *param = g_gui_screen_switch_effect_object_param[object->id][time];
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_create_object
 * DESCRIPTION
 *  Creates an effect object.
 * PARAMETERS
 *  object                   [OUT]  object
 *  id                       [IN]   id
 *  width                    [IN]   width
 *  height                   [IN]   height
 *  bpp                      [IN]   bpp (NOT USED)
 *  z                        [IN]   z order (NOT USED)
 *  buf                      [IN]   buffer pointer
 *  get_param_callback       [IN]   get parameter callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_create_object(gui_screen_switch_effect_object_struct *object, S32 id, S32 width, S32 height, S32 bpp, S32 z, PU8 buf, gui_screen_switch_effect_object_get_param_funcptr get_param_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object->id = id;
    object->width = width;
    object->height = height;
    object->bpp = bpp;
    object->z = z;
    object->buf = buf;
    object->get_param_callback = get_param_callback;

    /* assign double buffer manually */
    object->buf2 = NULL;
    
    /* default enable source key */
    object->enable_source_key = MMI_TRUE;

    object->draw_callback = NULL;

    g_gui_screen_switch_effect_object_num++;

    /* make sure the number of effect objects does not exceed the number of HW layers */
    MMI_ASSERT(g_gui_screen_switch_effect_object_num <= GUI_SCREEN_SWITCH_EFFECT_MAX_OBJECT_NUM);
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_create_object_layer
 * DESCRIPTION
 *  Creates a GDI layer for the effect object.
 * PARAMETERS
 *  object       [IN]   effect object
 *  layer        [OUT]  layer handle of the object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_create_object_layer(gui_screen_switch_effect_object_struct *object, gdi_handle *layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_create_cf_using_outside_memory(
        (gdi_color_format)(object->bpp / 8),
        0,
        0,
        object->width,
        object->height,
        layer,
        object->buf,
        object->width * object->height * object->bpp / 8);    
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_create_world
 * DESCRIPTION
 *  Initializes the screen effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_create_world(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    gui_screen_switch_effect_param_struct default_param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset SSE world object */
    memset(&g_gui_sse_world, 0, sizeof(gui_screen_switch_effect_world_struct));

#if !defined(__COSMOS_MMI_PACKAGE__)
    if (g_gui_screen_switch_effect_is_to_clear_key)
    {
        /* block pen inputs */
    #ifdef __MMI_TOUCH_SCREEN__  
        mmi_pen_block();
    #endif
        ClearKeyEvents();
    }
#endif /* !defined(__COSMOS_MMI_PACKAGE__) */

    /* save lcd freeze state */
    g_gui_screen_switch_effect_is_lcd_freeze = gdi_lcd_get_freeze();
    gdi_lcd_freeze(TRUE);

    /* unlock all framebuffer to prevent */
    gdi_layer_get_frame_buffer_lock_count(&g_gui_screen_switch_effect_frame_lock_count);
    for (i = 0; i < g_gui_screen_switch_effect_frame_lock_count; i++)
    {
        gdi_layer_unlock_frame_buffer();
    }
    
    g_gui_screen_switch_effect_object_num = 0;
    g_gui_screen_switch_effect_current_frame_index = 0;
    g_gui_screen_switch_effect_frames = 0;

    gui_screen_switch_effect_register_finish_callback(gui_screen_switch_effect_default_finish_callback);
    g_gui_screen_switch_effect_enable_early_key_break = MMI_FALSE;
    
    /* reset to world view port to full screen */
    GUI_RECT(g_gui_screen_switch_effect_world_view_rect, 0, 0, UI_device_width, UI_device_height);

    /* reset all object parameters to default */
    GUI_SCREEN_SWITCH_EFFECT_SET_DEFAULT_PARAM(default_param);    
    for (i = 0; i < GUI_SCREEN_SWITCH_EFFECT_MAX_OBJECT_NUM; i++)
    {
        for (j = 0; j < GUI_SCREEN_SWITCH_EFFECT_MAX_FRAME_NUM; j++)
        {
            memcpy(&g_gui_screen_switch_effect_object_param[i][j], &default_param, sizeof(gui_screen_switch_effect_param_struct));
        }
    }

    /* create temp memory pool */
    gui_effect_mem_manager_create(&g_gui_screen_switch_effect_tmp_mem, (PU8)g_gui_screen_switch_effect_buf_c, GUI_SCREEN_SWITCH_EFFECT_TEMP_BUFFER_SIZE);

    /* enable non-blocking blt by default to speed up */
    g_gui_sse_world.enable_non_blocking_blt = MMI_FALSE;
    g_gui_sse_world.tmp_buffer_p = NULL;
    g_gui_sse_world.tmp_buffer_size = 0;
    
    /* temporary buffer for non-blocking blt and misc usage */    
#if defined (__MMI_SCREEN_SWITCH_EFFECT__)
#if defined(__COSMOS_MMI_PACKAGE__)
    if (g_gui_sse_tmp_buffer)
    {
        /* more than 3 frame buffer, use the additional static allocated memory */
        g_gui_sse_world.tmp_buffer_p = (PU8)g_gui_sse_tmp_buffer;
        g_gui_sse_world.tmp_buffer_size = GUI_SCREEN_SWITCH_EFFECT_TEMP_BUFFER_SIZE;    
        g_gui_sse_world.enable_non_blocking_blt = MMI_TRUE;
    }
#endif /* defined(__COSMOS_MMI_PACKAGE__) */   
#endif /* (__MMI_UI_MEMORY_PROFILE__ > 3) && defined (__MMI_SCREEN_SWITCH_EFFECT__) */

    /* use nearest subsampling for projective transform due to performance */
    gui_effect_projective_transform_set_subsample_mode(GUI_EFFECT_PROJECTIVE_TRANSFORM_SUBSAMPLE_MODE_NEAREST);    
    /* use bilinear subsampling for affine transform */    
    gui_effect_affine_transform_set_subsample_mode(GUI_EFFECT_AFFINE_TRANSFORM_SUBSAMPLE_MODE_BILINEAR);    
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_close_world
 * DESCRIPTION
 *  Closes the screen switch effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_close_world(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__COSMOS_MMI_PACKAGE__)
    /* clear key events */
    if (g_gui_screen_switch_effect_is_to_clear_key)
    {
        /* unblock pen inputs */
    #ifdef __MMI_TOUCH_SCREEN__  
        mmi_pen_unblock();
    #endif
        ClearKeyEvents();
    }
#endif /* !defined(__COSMOS_MMI_PACKAGE__) */

    /* lock frame buffer back to avoid gdi assertion */
    for (i = 0; i < g_gui_screen_switch_effect_frame_lock_count; i++)
    {
        gdi_layer_lock_frame_buffer();
    }
    g_gui_screen_switch_effect_frame_lock_count = 0;

    /* restore lcd freeze state */
    gdi_lcd_freeze(g_gui_screen_switch_effect_is_lcd_freeze);
}

#endif /* #if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) */


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_get_frame_buffer_info
 * DESCRIPTION
 *  Gets SSE frame buffer address and size information.
 * PARAMETERS
 *  frame_buf_index   [IN]  SSE frame buffer index
 *  buf_p             [OUT] frame buffer address
 *  buf_size          [OUT] frame buffer size
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_get_frame_buffer_info(U32 frame_buf_index, PU8 *buf_p, S32 *buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
   // MMI_ASSERT(frame_buf_index < __MMI_UI_MEMORY_PROFILE__);

    /* allow 3 SSE frame buffer to be exported */
    switch (frame_buf_index)
    {
        case 0:
            *buf_p = (PU8)g_gui_screen_switch_effect_buf_a;
        #ifdef __MMI_REDUCED_UI_BUFFER__
            *buf_size = 0;
        #else
            *buf_size = GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE;
        #endif /* __MMI_REDUCED_UI_BUFFER__ */
            return;

        case 1:
            *buf_p = (PU8)g_gui_screen_switch_effect_buf_b;
            *buf_size = GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE;
            return;

#if !defined(__COSMOS_MMI_PACKAGE__)
        case 2:
            *buf_p = (PU8)g_gui_screen_switch_effect_buf_c;
            *buf_size = GUI_SCREEN_SWITCH_EFFECT_TEMP_BUFFER_SIZE;
            return;
#endif /* !defined(__COSMOS_MMI_PACKAGE__) */

        default:
            *buf_p = NULL;
            *buf_size = 0;            
            break;
    }
    
#else /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */

    /* nothing if SSE is not enabled */
    *buf_p = NULL;
    *buf_size = 0;
    
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_get_frame_buffer_count
 * DESCRIPTION
 *  Gets the number of frame buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  The number of frame buffer available.
 *****************************************************************************/
S32 gui_screen_switch_effect_get_frame_buffer_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
#if defined(__COSMOS_MMI_PACKAGE__)
    return 2; /* buf A + B */
#else /* defined(__COSMOS_MMI_PACKAGE__) */
    return 3;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
#else /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
    return 0;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_save_wallpaper
 * DESCRIPTION
 *  Save wallpaper layer buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_sse_save_wallpaper(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) && defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    gui_screen_switch_effect_save_wallpaper_layer((PU8)g_gui_screen_switch_effect_buf_b);
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_pre_exit_screen
 * DESCRIPTION
 *  This function is called before the screen exit function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_pre_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)

#ifdef __MMI_VUI_ENGINE__
    /* cannot touch SSE buffers here, since VRT is not yet deinited (in the ExitCategoryFunction()), and using SSE buffers */
    /*if (vadp_p2v_uc_is_in_venus())
    {
        return;
    }*/
#endif /* __MMI_VUI_ENGINE__ */

    /*
     * Some APP creates its own layers and frees them in the exit screen function, e.g., Calculator
     * To solve this problem, we must save the old screen here with caution.
     */
    if (!dm_is_activated() &&
#ifdef __MMI_VIDEO_PLAY_SUPPORT__    
        !mdi_video_is_playing() &&
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
#ifdef __MMI_VIDEO_RECORDER__        
        !mdi_video_is_recording() &&
#endif /* __MMI_VIDEO_RECORDER__ */
        gui_screen_switch_effect_is_lcd_output_available())
    {
        const gui_sse_effect_selection_struct *effect_selection_p;
        mmi_id group_id, scrn_id;
        mmi_frm_get_exit_scrn_id(&group_id, &scrn_id);

        /* only save the content when the current screen id matches the from screen ID (this screen is old) */
        effect_selection_p = gui_screen_switch_effect_match_selection_table(
                                scrn_id,
                                GUI_SSE_EFFECT_SELECTION_DONT_CARE_SCREEN_ID);
        /* make sure the effect is valid */
        if (effect_selection_p && 
            (effect_selection_p->effect_type != GUI_SCREEN_SWITCH_EFFECT_NONE))
        {            
            /* save the old screen */
            gui_screen_switch_effect_save_current_screen((PU8)g_gui_screen_switch_effect_buf_a);

            /* 
             * Disable SSE to prevent saving the old screen again in post exit category.
             * SSE will be enabled again in the setup function if necessary.
             */
            g_gui_screen_switch_effect_enable = MMI_FALSE;

            return;
        }            
    }

    /* call the custom callback for EXIT stage */
    if (g_gui_sse_custom_callback 
        && PhnsetGetScreenSwitchEffectStatus() != MMI_PHNSET_SSE_NONE
        
        #ifdef __J2ME__
        && !mmi_java_is_installing()
        #endif
        
        )
    {
        gui_screen_switch_effect_custom_param_struct param;

        gui_sse_custom_set_param(&param);
        g_gui_sse_custom_callback(GUI_SSE_STAGE_EXIT, &param);    
    }

    /* clear all custom callbacks */
    gui_screen_switch_effect_register_custom_callback(NULL);
    gui_screen_switch_effect_register_owner_draw_frame_callback(NULL);
	g_gui_screen_switch_effect_type = GUI_SCREEN_SWITCH_EFFECT_NONE;

    /* save previous category ID */
    g_gui_sse_previous_category_id = g_dm_data.s32CatId;

#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_pre_exit_category
 * DESCRIPTION
 *  Saves necessary layer and gets previous screen information before ExitCategory().
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_pre_exit_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    mmi_id group_id, scrn_id;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__)
    if (PhnsetGetScreenSwitchEffectStatus() == MMI_PHNSET_SSE_NONE
        
    #ifdef __J2ME__
        || mmi_java_is_installing()
    #endif
    
    #ifdef __MMI_UCM__
        || (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    #endif
        )
    {
        g_gui_screen_switch_effect_enable = MMI_FALSE;
        
        return;
    }
    
    if (!mmi_frm_screen_is_sse_backup_on())
    {
        /* for screen group dummy node, do not do this twice */
        return;
    }
#ifdef __MMI_SCREEN_ROTATE__
    g_gui_screen_switch_effect_previous_rotation = mmi_frm_get_screen_rotate(); 
#endif

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
    if (mdi_video_is_playing())
    {
        g_gui_screen_switch_effect_enable = MMI_FALSE;
    }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */    
#ifdef __MMI_VIDEO_RECORDER__
    if (mdi_video_is_recording())
    {
        g_gui_screen_switch_effect_enable = MMI_FALSE;
    }
#endif /* __MMI_VIDEO_RECORDER__ */

	if (g_gui_sse_is_small_screen)
    {
#if defined(__COSMOS_MMI_PACKAGE__)
        g_gui_screen_switch_effect_enable = MMI_FALSE;
#elif defined(__MMI_FTE_SUPPORT__)
        gui_sse_setup_scenario(GUI_SSE_SCENARIO_NO_EFFECT);
#else /* defined(__MMI_FTE_SUPPORT__) */
        gui_sse_setup_scenario(GUI_SSE_SCENARIO_SMALL_SCREEN_OUT);
#endif
    }



#else
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    if (!mmi_frm_screen_is_sse_backup_on())
    {
        /* for screen group dummy node, do not do this twice */
        return;
    }

    if (PhnsetGetScreenSwitchEffectStatus() == MMI_PHNSET_SSE_NONE
        
    #ifdef __J2ME__
        || mmi_java_is_installing()
    #endif
    
    #ifdef __MMI_UCM__
        || (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    #endif
        )
    {
        g_gui_screen_switch_effect_enable = MMI_FALSE;
        
        return;
    }


#if defined(__MMI_VIDEO_PLAYER__) 
	mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
    if (scrn_id == SCR_ID_VDOPLY_APP)
    {
        gui_screen_switch_effect_reset_flag();
    }
#endif /* defined(__MMI_VIDEO_PLAYER__) */

    /* enable the screen switch effect */
    g_gui_screen_switch_effect_enable = MMI_TRUE;

    /* ignore GLOBAL_SCR_DUMMY */
    // TODO: assume that the dummy screen will not draw anything */
    mmi_frm_get_exit_scrn_id(&group_id, &scrn_id);
 
    g_gui_screen_switch_effect_previous_screen_id = scrn_id;

#ifdef __MMI_SCREEN_ROTATE__
    g_gui_screen_switch_effect_previous_rotation = mmi_frm_get_screen_rotate(); 
#endif /* __MMI_SCREEN_ROTATE__ */

    /* a simple check to disable screen switch ASAP */
    if (gdi_lcd_get_freeze() ||
        //!dm_is_activated() || 
        mmi_is_redrawing_bk_screens())
    {
        g_gui_screen_switch_effect_enable = MMI_FALSE;
    }
    else
    {
        g_gui_screen_switch_effect_enable = MMI_TRUE;
    }

    /* no effects for popups */
    if (dm_check_control_exist(g_dm_data.s32CatId, DM_POPUP_BACKGROUND))
    {
        /* for popup sliding */
        //g_gui_screen_switch_effect_enable = MMI_FALSE;
    }

#ifdef __MMI_VUI_ENGINE__
    /* 
     * Cannot touch SSE buffers here, since VRT is not yet deinited and using SSE buffers.
     * However, we still can enable SSE from venus to pluto with the main base layer content left.
     */
    /*if (vadp_p2v_uc_is_in_venus())
    {
        return;
    }*/
#endif /* __MMI_VUI_ENGINE__ */

    /*
     *  cannot save the main base layer if the video is playing
     */    
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
    if (mdi_video_is_playing())
    {
        g_gui_screen_switch_effect_enable = MMI_FALSE;
    }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */    
#ifdef __MMI_VIDEO_RECORDER__
    if (mdi_video_is_recording())
    {
        g_gui_screen_switch_effect_enable = MMI_FALSE;
    }
#endif /* __MMI_VIDEO_RECORDER__ */

    if (g_gui_screen_switch_effect_enable)
    {    

        /* must enable small screen flatten */
        dm_enable_small_screen_flatten();
    }

    if (g_gui_sse_is_small_screen)
    {
#if defined(__COSMOS_MMI_PACKAGE__)
        g_gui_screen_switch_effect_enable = MMI_FALSE;
#else
        gui_sse_setup_scenario(GUI_SSE_SCENARIO_SMALL_SCREEN_OUT);
#endif
    }

    if (dm_check_control_exist(g_gui_sse_category_id, DM_POPUP_BACKGROUND))
    {
#if defined(__MMI_FTE_SUPPORT__)
        gui_sse_setup_scenario(GUI_SSE_SCENARIO_NO_EFFECT);
#else /* defined(__MMI_FTE_SUPPORT__) */
        gui_sse_setup_scenario(GUI_SSE_SCENARIO_SMALL_SCREEN_OUT);
#endif /* defined(__MMI_FTE_SUPPORT__) */
    }

    if (g_gui_sse_category_id == MMI_CATEGORY_CASCADING_MENU_ID)
    {
        gui_sse_setup_scenario(GUI_SSE_SCENARIO_SMALL_SCREEN_OUT);
    }

    g_gui_sse_prev_category_id = g_gui_sse_category_id;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_post_exit_category
 * DESCRIPTION
 *  Saves the flattened screen (by DM) of the previous screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_post_exit_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    if (!mmi_frm_screen_is_sse_backup_on())
    {
        /* for screen group dummy node, do not do this twice */
        return;
    }
#if defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__)
    vcpSseBuildOldScreen();
    g_gui_sse_category_id = 0;
#else

    if (g_gui_screen_switch_effect_enable
        || (g_gui_sse_scenario != GUI_SSE_SCENARIO_NONE)  
        || g_gui_screen_switch_effect_from_MM
        )
    {   
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SEO", SA_start);
#endif
        /* save flattened previous screen (on the main base layer) to buffer A */
        gui_screen_switch_effect_save_main_base_layer((PU8)g_gui_screen_switch_effect_buf_a, MMI_FALSE); 
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SEO", SA_stop);
#endif
    }

    g_gui_sse_category_id = 0;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__) */
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */

    /* reset the pre key handler */
    mmi_frm_kbd_reg_pre_key_hdlr(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_setup
 * DESCRIPTION
 *  Setups and chooses the screen switch effect. Must be paried with gui_screen_switch_effect_run().
 * PARAMETERS
 *  category_id           [IN]      current category ID
 *  category_flag         [IN]      current category flag
 *  category_redraw       [IN]      current category redraw state
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_setup(S32 category_id, S32 category_flag, S32 category_redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_smooth_scrolling_effect_setup(category_id, category_flag, category_redraw);

#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    {
        g_gui_sse_category_id = category_id;
    }
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_run
 * DESCRIPTION
 *  Runs the screen switch effect. Must be paried with gui_screen_switch_effect_setup().
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_run(void)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_smooth_scrolling_effect_run();
}

#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)

/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_run_default_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void gui_screen_switch_effect_run_default_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dir = mmi_frm_screen_get_direction();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dir > 0)
    {
        gui_screen_switch_effect_slide_and_blend(GUI_SCREEN_SWITCH_EFFECT_SLIDE_AND_BLEND_IN);
    }
    else if (dir < 0)
    {
        gui_screen_switch_effect_slide_and_blend(GUI_SCREEN_SWITCH_EFFECT_SLIDE_AND_BLEND_OUT);
    } 
}

#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) */


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_run_effect
 * DESCRIPTION
 *  Runs the screen switch effect.
 * PARAMETERS
 *  effect_type       [IN]      screen switch effect type
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_run_effect(gui_screen_switch_effect_type_enum effect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_interactive_start4();
#endif
    switch (effect_type)
    {
        case GUI_SCREEN_SWITCH_EFFECT_SLIDE_LEFT:
        case GUI_SCREEN_SWITCH_EFFECT_SLIDE_RIGHT:
        case GUI_SCREEN_SWITCH_EFFECT_SLIDE_UP:
        case GUI_SCREEN_SWITCH_EFFECT_SLIDE_DOWN:
            gui_screen_switch_effect_slide(effect_type);
            break;
        case GUI_SCREEN_SWITCH_EFFECT_BLEND_IN:
        case GUI_SCREEN_SWITCH_EFFECT_BLEND_OUT:        
            gui_screen_switch_effect_blend(effect_type);
            break;
        case GUI_SCREEN_SWITCH_EFFECT_SLIDE_AND_BLEND_IN:
        case GUI_SCREEN_SWITCH_EFFECT_SLIDE_AND_BLEND_OUT:
            gui_screen_switch_effect_slide_and_blend(effect_type);
            break;

        case GUI_SCREEN_SWITCH_EFFECT_ZOOM_AND_BLEND_IN:
            gui_screen_switch_effect_zoom_and_blend_in();
            break;
            
        case GUI_SCREEN_SWITCH_EFFECT_ZOOM_AND_BLEND_OUT:
            gui_screen_switch_effect_zoom_and_blend_out();
            break;

        case GUI_SCREEN_SWITCH_EFFECT_FLIP_CLOCK_WISE:
        case GUI_SCREEN_SWITCH_EFFECT_FLIP_COUNTERCLOCK_WISE:
            gui_screen_switch_effect_flip(effect_type);
            break;
            
        case GUI_SCREEN_SWITCH_EFFECT_CUSTOM:
            gui_screen_switch_effect_custom();
            break;

        case GUI_SCREEN_SWITCH_EFFECT_CUBE_CLOCK_WISE:
        case GUI_SCREEN_SWITCH_EFFECT_CUBE_COUNTERCLOCK_WISE:
            gui_screen_switch_effect_cube(effect_type);
            break;

        case GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_LEFT:
        case GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_RIGHT:
        case GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_DOWN:
        case GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_UP:
            gui_screen_switch_effect_move_in(effect_type);
            break;
            
        case GUI_SCREEN_SWITCH_EEFECT_OWNER_DRAW1:
        case GUI_SCREEN_SWITCH_EEFECT_OWNER_DRAW2:
        case GUI_SCREEN_SWITCH_EEFECT_OWNER_DRAW3:
            gui_screen_switch_effect_owner_draw(effect_type);
            break;
#ifdef __MMI_CALENDAR__
        case GUI_SCREEN_SWITCH_EEFECT_CALENDAR_PAGE_UP:
        case GUI_SCREEN_SWITCH_EEFECT_CALENDAR_PAGE_DOWN:
            gui_screen_effect_calendar_page(effect_type);
            break;
#endif /* __MMI_CALENDAR__ */
            
#ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
        case GUI_SCREEN_SWITCH_EEFECT_ICON_FLIP:
            gui_screen_effect_icon_flip(effect_type);
            break;
#endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */

    #ifdef __MMI_MAINMENU_MATRIX_SUPPORT__
        case GUI_SCREEN_SWITCH_EFFECT_MATRIX_MAIN_MENU_ICON_EXPAND:
            gui_screen_switch_effect_matrix_main_menu_icon_expand();
            break;
    #endif /* __MMI_MAINMENU_MATRIX_SUPPORT__ */

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        case GUI_SCREEN_SWITCH_EFFECT_OP11_HS_SLIDING:
            gui_sse_op11_hs_sliding();
            break;

        case GUI_SCREEN_SWITCH_EFFECT_OP11_HS_FADEIN:
            gui_sse_op11_hs_fadein();
            break;
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#if defined(__COSMOS_MMI_PACKAGE__)
        case GUI_SCREEN_SWITCH_EFFECT_COSMOS_APP_ENTRY:
            gui_sse_cosmos_app_entry();
            break;

        case GUI_SCREEN_SWITCH_EFFECT_COSMOS_APP_EXIT:
            gui_sse_cosmos_app_exit();
            break;

        case GUI_SCREEN_SWITCH_EFFECT_COSMOS_PAGE_ENTRY:
            gui_sse_cosmos_page(effect_type);
            break;

        case GUI_SCREEN_SWITCH_EFFECT_COSMOS_PAGE_EXIT:
            gui_sse_cosmos_page(effect_type);
            break;                    
#endif /* defined(__COSMOS_MMI_PACKAGE__) */

        default:
        {
            #ifdef __GUI_SSE_BACKUP_EFFECT_ON__
                gui_screen_switch_effect_run_backup_effect(effect_type);
            #else
                gui_screen_switch_effect_run_default_effect();
            #endif
            break;
        }
    }
#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_interactive_end4();
    mmi_frm_profiling_interactive_show((U8*) L"E", MMI_FRM_PROFILING_MASK_2 | MMI_FRM_PROFILING_MASK_3| MMI_FRM_PROFILING_MASK_4);
#endif
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}

/*****************************************************************************
 * FUNCTION
 *  gui_sse_set_pre_launch_func
 * DESCRIPTION
 *  register custom handler executed before SSE by APP
 *  APP has to de-register by himself
 * PARAMETERS
 *  handler [IN] pre launch function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_sse_set_pre_launch_func(void (*handler)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    g_gui_sse_pre_launch_func = handler;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_set_post_launch_func
 * DESCRIPTION
 *  register custom handler executed after SSE by APP
 *  APP has to de-register by himself
 * PARAMETERS
 *  handler [IN] post launch function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_sse_set_post_launch_func(void (*handler)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    g_gui_sse_post_launch_func = handler;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_set_no_run_func
 * DESCRIPTION
 *  register the custom handler invoked when SSE is not run
 *  APP has to de-register by himself
 * PARAMETERS
 *  handler [IN] no run function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_sse_set_no_run_func(void (*handler)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    g_gui_sse_no_run_func = handler;
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
}

/*****************************************************************************
 * FUNCTION
 *  gui_sse_launch
 * DESCRIPTION
 *  Runs the screen switch effect.
 *  This function is only used for mmi_frm_refrsh_lcm().
 *  If no effect to run, just BLT current screen to LCM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_sse_launch(void)
{
#if defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__)
    MMI_BOOL gui_screen_switch_effect_is_to_clear_key = MMI_TRUE;

    g_gui_screen_switch_effect_enable = gui_sse_post_check_is_enable();
    gui_sse_pre_setting();

#if !defined(__COSMOS_MMI_PACKAGE__)
    if (g_gui_screen_switch_effect_enable && g_gui_sse_scenario == GUI_SSE_SCENARIO_NONE)
    {
        if (PhnsetGetScreenSwitchEffectStatus() == MMI_PHNSET_SSE_FULL)
        {
            S32 dir = mmi_frm_screen_get_direction();

            if (dir > 0)
            {
                gui_sse_setup_scenario(GUI_SSE_SCENARIO_FTE_DEFAULT_ENTER);
            }
            else if (dir < 0)
            {
                gui_sse_setup_scenario(GUI_SSE_SCENARIO_FTE_DEFAULT_EXIT);
            }
            else
            {
                gui_sse_setup_scenario(GUI_SSE_SCENARIO_NO_EFFECT);
            }
        }
    }   
#endif



#if !defined(__COSMOS_MMI_PACKAGE__)
    // Currently only Dialer not to clear key
    if (g_gui_sse_scenario == GUI_SSE_SCENARIO_FROM_IDLE || g_gui_sse_scenario == GUI_SSE_SCENARIO_NONE || \
		mmi_dialer_is_active())
    {
        gui_screen_switch_effect_is_to_clear_key = MMI_FALSE;
    }
    else
    {
        gui_screen_switch_effect_is_to_clear_key = MMI_TRUE;
    }
    

    if (gui_screen_switch_effect_is_to_clear_key)
    {
        /* block pen inputs */
    #ifdef __MMI_TOUCH_SCREEN__  
        //mmi_pen_block();
    #endif
        ClearKeyEvents();
    }
#endif /* !defined(__COSMOS_MMI_PACKAGE__) */

    if (!g_gui_screen_switch_effect_enable || 
             g_gui_sse_scenario == GUI_SSE_SCENARIO_NONE || 
             g_gui_sse_scenario == GUI_SSE_SCENARIO_NO_EFFECT ||
             g_gui_sse_scenario == GUI_SSE_SCENARIO_ENTER_IDLE  // Do not run sse currently
#if defined(__COSMOS_MMI_PACKAGE__)
             ||
             g_gui_sse_scenario == GUI_SSE_SCENARIO_SMALL_SCREEN_IN ||
             g_gui_sse_scenario == GUI_SSE_SCENARIO_SMALL_SCREEN_OUT
#endif 
             )
    {
        vcpSseReset();
        gdi_lcd_repaint_all();
    }
    else
    {
        // pluto case
        if (vfx_sys_get_canvas_state() == VFX_SYS_STATE_LEAVE)
        {
            gdi_handle layers[4];
            gdi_handle alpha;
            gdi_handle act_layer;
            gdi_layer_get_active(&act_layer);
            gdi_layer_get_blt_layer(&layers[0], &layers[1], &layers[2], &layers[3]);
            gdi_get_alpha_blending_source_layer(&alpha);
            vcpSseRunSsePluto();
            gdi_set_alpha_blending_source_layer(alpha);
            gdi_layer_set_blt_layer(layers[0], layers[1], layers[2], layers[3]);
            gdi_layer_set_active(act_layer);
            gdi_lcd_repaint_all();
        }
        else
        {
            vcpSseRunSse();
        }
    }  

#if !defined(__COSMOS_MMI_PACKAGE__)
    if (gui_screen_switch_effect_is_to_clear_key)
    {
        /* unblock pen inputs */
    #ifdef __MMI_TOUCH_SCREEN__  
        //mmi_pen_unblock();
    #endif
        ClearKeyEvents();
    }

    //g_gui_screen_switch_effect_is_to_clear_key = MMI_TRUE;
#endif /* !defined(__COSMOS_MMI_PACKAGE__) */

    g_gui_screen_switch_effect_enable = MMI_TRUE;
#else
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_custom_effect = MMI_FALSE;
    gui_screen_switch_effect_custom_param_struct param;
    gui_screen_switch_effect_custom_return_code_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_screen_switch_effect_enable = gui_sse_post_check_is_enable();

    /* pre-setting */
    gui_sse_pre_setting();

    /* allocate memory */
#if defined(__COSMOS_MMI_PACKAGE__)
    g_gui_screen_switch_effect_buf_c = mmi_frm_asm_alloc_anonymous_nc(GUI_SCREEN_SWITCH_EFFECT_TEMP_BUFFER_SIZE);
    if (!g_gui_screen_switch_effect_buf_c)
    {
        g_gui_screen_switch_effect_enable = MMI_FALSE;
    }
    g_gui_sse_tmp_buffer = mmi_frm_asm_alloc_anonymous_nc(GUI_SCREEN_SWITCH_EFFECT_TEMP_BUFFER_SIZE);
#endif /* defined(__COSMOS_MMI_PACKAGE__) */

    if (g_gui_screen_switch_effect_enable)
    {
        /* custom PRE SETUP */
        if (g_gui_sse_custom_callback)
        {
            gui_sse_custom_set_param(&param);
            ret = g_gui_sse_custom_callback(GUI_SSE_STAGE_PRE_SETUP, &param);
            switch (ret)
            {
                case GUI_SSE_CUSTOM_RETURN_CODE_CUSTOM_EFFECT:
                    g_gui_screen_switch_effect_enable = MMI_TRUE;
                    is_custom_effect = MMI_TRUE;
                    break;

                case GUI_SSE_CUSTOM_RETURN_CODE_NO_EFFECT:
                    g_gui_screen_switch_effect_enable = MMI_FALSE;
                    break;

                default:
                    break;
            }
        }
    }

    if (g_gui_screen_switch_effect_enable)
    {
        if (!is_custom_effect)
        {
            if (g_gui_sse_scenario)
            {
                S32 i = 0;

                g_gui_screen_switch_effect_type = GUI_SCREEN_SWITCH_EFFECT_NONE;
                for (i = 0 ; i < (sizeof(g_gui_sse_scenario_effect_tbl) / sizeof(gui_sse_scenario_effect_table_struct)) ; i++)
                {
                    if (g_gui_sse_scenario_effect_tbl[i].scenario == g_gui_sse_scenario)
                    {
                        g_gui_screen_switch_effect_type = g_gui_sse_scenario_effect_tbl[i].effect;
                        break;
                    }
                }
            }
            else
            {
                if (PhnsetGetScreenSwitchEffectStatus() == MMI_PHNSET_SSE_FULL)
                {
                    S32 dir = mmi_frm_screen_get_direction();

                    if (dir > 0)
                    {
                        g_gui_screen_switch_effect_type = GUI_SCREEN_SWITCH_EFFECT_SLIDE_AND_BLEND_IN;
                    }
                    else if (dir < 0)
                    {
                        g_gui_screen_switch_effect_type = GUI_SCREEN_SWITCH_EFFECT_SLIDE_AND_BLEND_OUT;
                    }
                    else
                    {
                        g_gui_screen_switch_effect_type = GUI_SCREEN_SWITCH_EFFECT_NONE;
                    }
                }
            }
        }

        /* custom POST SETUP stage */
        if (g_gui_sse_custom_callback)
        {
            gui_sse_custom_set_param(&param);
            ret = g_gui_sse_custom_callback(GUI_SSE_STAGE_POST_SETUP, &param);

            switch (ret)
            {
                case GUI_SSE_CUSTOM_RETURN_CODE_CUSTOM_EFFECT:
                    g_gui_screen_switch_effect_enable = MMI_TRUE;
                    break;

                case GUI_SSE_CUSTOM_RETURN_CODE_NO_EFFECT:
                    g_gui_screen_switch_effect_enable = MMI_FALSE;
                    break;

                default:
                    break;
            }
        }
    }
    else
    {
        gui_screen_switch_effect_reset_flag();
    }

    mmi_frm_scrn_set_ui_data(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id(), (U32)g_gui_sse_scenario);
    
    if (g_gui_screen_switch_effect_enable)
    {
        /* custom PRE RUN */
        if (g_gui_sse_custom_callback)
        {
            gui_sse_custom_set_param(&param);
            g_gui_sse_custom_callback(GUI_SSE_STAGE_PRE_RUN, &param);
        }

        /* run the selected effect decided in gui_screen_switch_effect_setup() */
        if (g_gui_screen_switch_effect_type != GUI_SCREEN_SWITCH_EFFECT_NONE)
        {
            if (g_gui_sse_pre_launch_func)
            {
                g_gui_sse_pre_launch_func();
            }

            gui_screen_switch_effect_run_effect((gui_screen_switch_effect_type_enum)g_gui_screen_switch_effect_type);

            if (g_gui_sse_post_launch_func)
            {
                g_gui_sse_post_launch_func();
            }
        }
        else
        {
            gdi_lcd_repaint_all();
        }

        /* Errors happen when the effect is running. Must blt out the fb since the fb is locked. */
        if (GUI_SSE_GET_ERROR_CODE() != GUI_SSE_ERROR_NONE)
        {
            if (dm_is_activated())
            {
                gdi_layer_blt_previous(0, 0, 0, 0);
            }
        }

        /* custom POST RUN */
        if (g_gui_sse_custom_callback)
        {
            gui_sse_custom_set_param(&param);
            g_gui_sse_custom_callback(GUI_SSE_STAGE_POST_RUN, &param);
        }

        gui_screen_switch_effect_reset_flag();
        g_gui_screen_switch_effect_enable = MMI_TRUE;
    }
    else
    {
        if (g_gui_sse_no_run_func)
        {
            g_gui_sse_no_run_func();
        }
        
        gdi_lcd_repaint_all();
    }

    /* free memory */
#if defined(__COSMOS_MMI_PACKAGE__)
    if (g_gui_screen_switch_effect_buf_c)
    {
        mmi_frm_asm_free_anonymous(g_gui_screen_switch_effect_buf_c);
        g_gui_screen_switch_effect_buf_c = NULL;
    }

    if (g_gui_sse_tmp_buffer)
    {
        mmi_frm_asm_free_anonymous(g_gui_sse_tmp_buffer);
        g_gui_sse_tmp_buffer = NULL;
    }
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__) */
}


/***************************************************************************** 
 * Test bed
 *****************************************************************************/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)

/* test item index */
static S32 g_gui_sse_test_id = 0;
static mmi_id g_gui_sse_test_group_id;
static void gui_sse_test_entry_screen(void);
static mmi_ret mmi_sse_test_proc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
/*****************************************************************************
 * FUNCTION
 *  gui_sse_test_custom_callback
 * DESCRIPTION
 *  custom callback for SSE test
 * PARAMETERS
 *  stage_type  [IN]    stage
 *  param       [OUT]   parameters
 * RETURNS
 *  gui_screen_switch_effect_custom_return_code_enum
 *****************************************************************************/
static gui_screen_switch_effect_custom_return_code_enum gui_sse_test_custom_callback(gui_screen_switch_effect_stage_enum stage_type, gui_screen_switch_effect_custom_param_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 id[] = {
        GUI_SCREEN_SWITCH_EFFECT_SLIDE_LEFT,
        GUI_SCREEN_SWITCH_EFFECT_SLIDE_RIGHT,
        GUI_SCREEN_SWITCH_EFFECT_ZOOM_IN,
        GUI_SCREEN_SWITCH_EFFECT_ZOOM_OUT,
        GUI_SCREEN_SWITCH_EFFECT_BLEND_IN,
        GUI_SCREEN_SWITCH_EFFECT_BLEND_OUT,
        GUI_SCREEN_SWITCH_EFFECT_SUBMENU_SLIDE_LEFT,
        GUI_SCREEN_SWITCH_EFFECT_SUBMENU_SLIDE_RIGHT,
        GUI_SCREEN_SWITCH_EFFECT_ZOOM_AND_BLEND_IN,
        GUI_SCREEN_SWITCH_EFFECT_ZOOM_AND_BLEND_OUT,
        GUI_SCREEN_SWITCH_EFFECT_FLIP_CLOCK_WISE,
        GUI_SCREEN_SWITCH_EFFECT_FLIP_COUNTERCLOCK_WISE,
        GUI_SCREEN_SWITCH_EFFECT_ROTATE_IN,
        GUI_SCREEN_SWITCH_EFFECT_ROTATE_OUT,
        GUI_SCREEN_SWITCH_EFFECT_CUBE_CLOCK_WISE,
        GUI_SCREEN_SWITCH_EFFECT_CUBE_COUNTERCLOCK_WISE,
        GUI_SCREEN_SWITCH_EFFECT_PAGE_TURN_LEFT,
        GUI_SCREEN_SWITCH_EFFECT_PAGE_TURN_RIGHT,
        GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_LEFT,
        GUI_SCREEN_SWITCH_EFFECT_MOVE_IN_RIGHT,
        GUI_SCREEN_SWITCH_EFFECT_MOVE_OUT_LEFT,
        GUI_SCREEN_SWITCH_EFFECT_MOVE_OUT_RIGHT,
        GUI_SCREEN_SWITCH_EEFECT_REVOLVING_GATE_TURN_LEFT,
        GUI_SCREEN_SWITCH_EEFECT_REVOLVING_GATE_TURN_RIGHT,
        GUI_SCREEN_SWITCH_EEFECT_DIAGONAL_FLIP_TURN_LEFT,
        GUI_SCREEN_SWITCH_EEFECT_DIAGONAL_FLIP_TURN_RIGHT,
        GUI_SCREEN_SWITCH_EEFECT_INDIVIDUAL_FLIP_DOWN,
        GUI_SCREEN_SWITCH_EEFECT_INDIVIDUAL_FLIP_UP,
        GUI_SCREEN_SWITCH_EEFECT_OBLIQUE_FLY_OUT,
        GUI_SCREEN_SWITCH_EEFECT_OBLIQUE_FLY_IN
#if defined(__COSMOS_MMI_PACKAGE__)
        , GUI_SCREEN_SWITCH_EFFECT_COSMOS_APP_ENTRY,
        GUI_SCREEN_SWITCH_EFFECT_COSMOS_APP_EXIT,
        GUI_SCREEN_SWITCH_EFFECT_COSMOS_PAGE_ENTRY,
        GUI_SCREEN_SWITCH_EFFECT_COSMOS_PAGE_EXIT
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (stage_type == GUI_SSE_STAGE_POST_SETUP)
    {
        S32 shift = (GetActiveScreenId() == GLOBAL_SCR_DUMMY) ? (1) : (0);

        g_gui_screen_switch_effect_enable = MMI_TRUE;
        g_gui_screen_switch_effect_type = id[g_gui_sse_test_id * 2 + shift];
    }
    return GUI_SSE_CUSTOM_RETURN_CODE_DEFAULT;
}

#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) */

/*****************************************************************************
 * FUNCTION
 *  gui_sse_test_item
 * DESCRIPTION
 *  test each SSE effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sse_test_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__)
    kal_uint32 start_time, end_time, duration;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__)
    vcpSseSetOpen();
#else
    g_gui_sse_test_id = GetHighlightedItem();

    if(mmi_frm_scrn_enter(g_gui_sse_test_group_id, GLOBAL_SCR_DUMMY + 1, NULL, gui_sse_test_item, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_screen_switch_effect_register_custom_callback(gui_sse_test_custom_callback);

    kal_get_time(&start_time);

    ShowCategory353Screen(
        (U8*)L"Title", 0,
        0, 0,
        STR_GLOBAL_BACK, 0,
        0, NULL, NULL, NULL,
        0, 0, NULL);

    kal_get_time(&end_time);
    duration = kal_ticks_to_milli_secs(end_time - start_time);

    gdi_layer_lock_frame_buffer();
    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    {
        U16 str[16];

        gui_sprintf(str, "%04d ms", duration);
        gui_set_font(&MMI_medium_font);
        gui_set_text_color(UI_COLOR_WHITE);
        gui_set_text_border_color(gui_color(0, 0, 0));
        gui_move_text_cursor(5, MMI_content_y + 5);
        gui_print_bordered_text(str);
    }
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();

    gui_start_timer(1500, mmi_frm_scrn_close_active_id);
    //SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_test
 * DESCRIPTION
 *  entry function of test bed of SSE
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_sse_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     g_gui_sse_test_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_sse_test_proc, NULL);
     mmi_frm_group_enter(g_gui_sse_test_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
     gui_sse_test_entry_screen();
}

static void gui_sse_test_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_enter(g_gui_sse_test_group_id, GLOBAL_SCR_DUMMY, NULL, gui_sse_test_entry_screen, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

#if defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__)
    subMenuDataPtrs[count++] = (U8*)L"Enable/Disable 3D SSE";
#else
    subMenuDataPtrs[count++] = (U8*)L"Slide";
    subMenuDataPtrs[count++] = (U8*)L"Zoom";
    subMenuDataPtrs[count++] = (U8*)L"Blend";
    subMenuDataPtrs[count++] = (U8*)L"Submenu Slide";
    subMenuDataPtrs[count++] = (U8*)L"Zoom & Blend";
    subMenuDataPtrs[count++] = (U8*)L"Flip";
    subMenuDataPtrs[count++] = (U8*)L"Rotate";
    subMenuDataPtrs[count++] = (U8*)L"Cube";
    subMenuDataPtrs[count++] = (U8*)L"Page Turn";
    subMenuDataPtrs[count++] = (U8*)L"Move In";
    subMenuDataPtrs[count++] = (U8*)L"Move Out";
    subMenuDataPtrs[count++] = (U8*)L"Revolving Gate";
    subMenuDataPtrs[count++] = (U8*)L"Diagonal Flip";
    subMenuDataPtrs[count++] = (U8*)L"Individual Flip";
    subMenuDataPtrs[count++] = (U8*)L"Oblique Fly";
#if defined(__COSMOS_MMI_PACKAGE__)
    subMenuDataPtrs[count++] = (U8*)L"Cosmos APP Entry";
    subMenuDataPtrs[count++] = (U8*)L"Cosmos Page Entry";
#endif /* defined(__COSMOS_MMI_PACKAGE__) */

    if (guiBuffer)
    {
        gui_screen_switch_effect_register_custom_callback(gui_sse_test_custom_callback);
    }
#endif
    ShowCategory353Screen(
        (U8*)L"SSE effects", 0,
        STR_GLOBAL_OK, 0,
        STR_GLOBAL_BACK, 0,
        count, subMenuDataPtrs, (U16*) gIndexIconsImageList, NULL,
        0, 0, guiBuffer);

    SetLeftSoftkeyFunction(gui_sse_test_item, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */

