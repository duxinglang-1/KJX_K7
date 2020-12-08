/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   wgui_categories_sim.c
 *
 * Project:
 * --------
 *   Maui
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "mmi_frm_gprot.h"
#include "WguiCategoryGprot.h"
#include "CommonScreens.h"
#include "wgui_categories_sim.h"
#include "callsetsrvGprot.h"
#include "wgui_fixed_menuitems.h"
#include "wgui_fixed_menus.h"
#include "TimerEvents.h"
#include "mmi_rp_app_uiframework_def.h"
#include "wgui_categories_enum.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "gdi_include.h"
#include "wgui_include.h"
/***************************************************************
 *
 *  Gemini+ sim space/selector
 *
 *********************************************************************/
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))

#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__)
    #define __MMI_CAT9010_STYLE_2__
#else
    #define __MMI_CAT9010_STYLE_3__
#endif

typedef struct
{
    U16 history_ID;
    S32 highlight_index;
} wgui_cat9010_history_struct;

typedef struct
{
	U8 count;
	U8 current_index;
	U16 loop_id[5];
}wgui_cat9010_loop_id_struct;


static wgui_cat9010_get_text_func_type  wgui_cat9010_get_text_func = NULL;
static void (*wgui_cat9010_selected_handler)(S32 sim_index);
static void (*wgui_cat9010_highlight_handler)(S32 sim_index);
static U8 g_cat9010_sim_count = 0;
static U8 g_cat9010_sim_state[4];
static U8 g_cat9010_sim_highlight_index = 0;
static wgui_cat9010_type_enum g_cat9010_screen_type = SIM_SPACE;
static scrolling_text g_cat9010_scroll_text1;
static wgui_cat9010_text_struct g_cat9010_scroll_text;
static wgui_cat9010_loop_id_struct g_cat9010_loop_context[4];
#ifdef __MMI_FTE_SUPPORT__
static gdi_image_cache_bmp_struct  g_cat9010_popup_bg_cache_buf;
#endif

#define WGUI_CAT9010_CACHE_BG_BUF_SIZE (320*480*2)
#ifdef __MMI_MAINLCD_240X320__
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))   // 4card
	#define WGUI_CAT9010_IMAGE1_X  91
	#define WGUI_CAT9010_IMAGE1_Y  119
	#define WGUI_CAT9010_IMAGE2_X  121
	#define WGUI_CAT9010_IMAGE2_Y  159
	#define WGUI_CAT9010_IMAGE3_X  91
	#define WGUI_CAT9010_IMAGE3_Y  189
	#define WGUI_CAT9010_IMAGE4_X  51
	#define WGUI_CAT9010_IMAGE4_Y  159
// singal 
	#define WGUI_CAT9010_SIM1_SINGAL_X 111
	#define WGUI_CAT9010_SIM1_SINGAL_Y 165
	#define WGUI_CAT9010_SIM1_LINE_X 97
	#define WGUI_CAT9010_SIM1_LINE_Y 94

	#define WGUI_CAT9010_SIM2_SINGAL_X 126
	#define WGUI_CAT9010_SIM2_SINGAL_Y 174
	#define WGUI_CAT9010_SIM2_LINE_X 108
	#define WGUI_CAT9010_SIM2_LINE_Y 104

	#define WGUI_CAT9010_SIM3_SINGAL_X 106
	#define WGUI_CAT9010_SIM3_SINGAL_Y 195
	#define WGUI_CAT9010_SIM3_LINE_X 97
	#define WGUI_CAT9010_SIM3_LINE_Y 140

	#define WGUI_CAT9010_SIM4_SINGAL_X 96
	#define WGUI_CAT9010_SIM4_SINGAL_Y 179
	#define WGUI_CAT9010_SIM4_LINE_X 60
	#define WGUI_CAT9010_SIM4_LINE_Y 104

// center
	#define WGUI_CAT9010_PETAL_CENTER_X  119
	#define WGUI_CAT9010_PETAL_CENTER_Y	 186
	#define WGUI_CAT9010_PETAL_RADIUS    68

// popup 
	#define WGUI_CAT9010_POPUP_X1  13
	#define WGUI_CAT9010_POPUP_Y1  45
	#define WGUI_CAT9010_POPUP_X2  224
	#define WGUI_CAT9010_POPUP_Y2  265
	#define WGUI_CAT9010_POPUP_TITLE_H 30

// INFO BG
    #define WGUI_CAT9010_INFO_BG_X 24
    #define WGUI_CAT9010_INFO_BG_Y 45
    #define WGUI_CAT9010_INFO_BG_W 190
    #define WGUI_CAT9010_INFO_BG_H 63
    #define WGUI_CAT9010_INFO_GAP 14
    #define WGUI_CAT9010_STATUS_ICON_W 75
// popup text
    #define WGUI_CAT9010_POPUP_TITLE_X (WGUI_CAT9010_POPUP_X1 + WGUI_CAT9010_INFO_GAP)
    #define WGUI_CAT9010_POPUP_TITLE_Y (WGUI_CAT9010_POPUP_Y1 + UI_POPUP_BORDER_SIZE)

// LINE
    #define WGUI_CAT9010_LINE_Y 76
    #define WGUI_CAT9010_POPUP_LINE_Y (WGUI_CAT9010_POPUP_Y1 + 35)
    #define WGUI_CAT9010_POPUP_LINE_X  20
#else  // 3 card
	#define WGUI_CAT9010_IMAGE1_X  91
	#define WGUI_CAT9010_IMAGE1_Y  144
	#define WGUI_CAT9010_IMAGE2_X  121
	#define WGUI_CAT9010_IMAGE2_Y  184
	#define WGUI_CAT9010_IMAGE3_X  51
	#define WGUI_CAT9010_IMAGE3_Y  184

// singal 
	#define WGUI_CAT9010_SIM1_SINGAL_X 111
	#define WGUI_CAT9010_SIM1_SINGAL_Y 190
	#define WGUI_CAT9010_SIM1_LINE_X 97
	#define WGUI_CAT9010_SIM1_LINE_Y 113
	#define WGUI_CAT9010_SIM2_SINGAL_X 126
	#define WGUI_CAT9010_SIM2_SINGAL_Y 199
	#define WGUI_CAT9010_SIM2_LINE_X 108
	#define WGUI_CAT9010_SIM2_LINE_Y 123
	#define WGUI_CAT9010_SIM3_SINGAL_X 96
	#define WGUI_CAT9010_SIM3_SINGAL_Y 204
	#define WGUI_CAT9010_SIM3_LINE_X 60
	#define WGUI_CAT9010_SIM3_LINE_Y 123
// center
	#define WGUI_CAT9010_PETAL_CENTER_X  118
	#define WGUI_CAT9010_PETAL_CENTER_Y	 209
	#define WGUI_CAT9010_PETAL_RADIUS    70

// popup 
	#define WGUI_CAT9010_POPUP_X1  13
	#define WGUI_CAT9010_POPUP_Y1  45
	#define WGUI_CAT9010_POPUP_X2  224
	#define WGUI_CAT9010_POPUP_Y2  265
	#define WGUI_CAT9010_POPUP_TITLE_H 30
    
    // INFO BG
    #define WGUI_CAT9010_INFO_BG_X 24
    #define WGUI_CAT9010_INFO_BG_Y 45
    #define WGUI_CAT9010_INFO_BG_W 190
    #define WGUI_CAT9010_INFO_BG_H 63
    #define WGUI_CAT9010_INFO_GAP 14
    #define WGUI_CAT9010_STATUS_ICON_W 75
    // popup text
    #define WGUI_CAT9010_POPUP_TITLE_X (WGUI_CAT9010_POPUP_X1 + WGUI_CAT9010_INFO_GAP)
    #define WGUI_CAT9010_POPUP_TITLE_Y (WGUI_CAT9010_POPUP_Y1 + UI_POPUP_BORDER_SIZE)
    
    // LINE
    #define WGUI_CAT9010_LINE_Y 77
    #define WGUI_CAT9010_POPUP_LINE_Y (WGUI_CAT9010_POPUP_Y1 + 35)
    #define WGUI_CAT9010_POPUP_LINE_X  20

#endif /* (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))*/
#elif defined(__MMI_MAINLCD_176X220__)
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))   // 4card
	#define WGUI_CAT9010_IMAGE1_X  67
	#define WGUI_CAT9010_IMAGE1_Y  85
	#define WGUI_CAT9010_IMAGE2_X  89
	#define WGUI_CAT9010_IMAGE2_Y  115
	#define WGUI_CAT9010_IMAGE3_X  67
	#define WGUI_CAT9010_IMAGE3_Y  138
	#define WGUI_CAT9010_IMAGE4_X  36
	#define WGUI_CAT9010_IMAGE4_Y  115
// singal 
	#define WGUI_CAT9010_SIM1_SINGAL_X 82
	#define WGUI_CAT9010_SIM1_SINGAL_Y 119
	#define WGUI_CAT9010_SIM1_LINE_X 97
	#define WGUI_CAT9010_SIM1_LINE_Y 94
	
	#define WGUI_CAT9010_SIM2_SINGAL_X 94
	#define WGUI_CAT9010_SIM2_SINGAL_Y 127
	#define WGUI_CAT9010_SIM2_LINE_X 108
	#define WGUI_CAT9010_SIM2_LINE_Y 104
	
	#define WGUI_CAT9010_SIM3_SINGAL_X 79
	#define WGUI_CAT9010_SIM3_SINGAL_Y 142
	#define WGUI_CAT9010_SIM3_LINE_X 97
	#define WGUI_CAT9010_SIM3_LINE_Y 140
	
	#define WGUI_CAT9010_SIM4_SINGAL_X 71
	#define WGUI_CAT9010_SIM4_SINGAL_Y 130
	#define WGUI_CAT9010_SIM4_LINE_X 60
	#define WGUI_CAT9010_SIM4_LINE_Y 104
	
// center
	#define WGUI_CAT9010_PETAL_CENTER_X  88
	#define WGUI_CAT9010_PETAL_CENTER_Y	 136
	#define WGUI_CAT9010_PETAL_RADIUS    50

// popup 
	#define WGUI_CAT9010_POPUP_X1  10
	#define WGUI_CAT9010_POPUP_Y1  16
	#define WGUI_CAT9010_POPUP_X2  166
	#define WGUI_CAT9010_POPUP_Y2  198
	#define WGUI_CAT9010_POPUP_TITLE_H 20

// INFO BG
    #define WGUI_CAT9010_INFO_BG_X 19
    #define WGUI_CAT9010_INFO_BG_Y 28
    #define WGUI_CAT9010_INFO_BG_W 134
    #define WGUI_CAT9010_INFO_BG_H 50
    #define WGUI_CAT9010_INFO_GAP 14
    #define WGUI_CAT9010_STATUS_ICON_W 70
// popup text
    #define WGUI_CAT9010_POPUP_TITLE_X (WGUI_CAT9010_POPUP_X1 + WGUI_CAT9010_INFO_GAP)
    #define WGUI_CAT9010_POPUP_TITLE_Y (WGUI_CAT9010_POPUP_Y1 + UI_POPUP_BORDER_SIZE)

// LINE
    #define WGUI_CAT9010_LINE_Y 54
    #define WGUI_CAT9010_POPUP_LINE_Y (WGUI_CAT9010_POPUP_Y1 + 30)
    #define WGUI_CAT9010_POPUP_LINE_X  20
#else  // 3 card
	#define WGUI_CAT9010_IMAGE1_X  67
	#define WGUI_CAT9010_IMAGE1_Y  101
	#define WGUI_CAT9010_IMAGE2_X  89
	#define WGUI_CAT9010_IMAGE2_Y  131
	#define WGUI_CAT9010_IMAGE3_X  36
	#define WGUI_CAT9010_IMAGE3_Y  131

// singal 
	#define WGUI_CAT9010_SIM1_SINGAL_X 82
	#define WGUI_CAT9010_SIM1_SINGAL_Y 135
	#define WGUI_CAT9010_SIM1_LINE_X 97
	#define WGUI_CAT9010_SIM1_LINE_Y 113
	#define WGUI_CAT9010_SIM2_SINGAL_X 94
	#define WGUI_CAT9010_SIM2_SINGAL_Y 143
	#define WGUI_CAT9010_SIM2_LINE_X 108
	#define WGUI_CAT9010_SIM2_LINE_Y 123
	#define WGUI_CAT9010_SIM3_SINGAL_X 71
	#define WGUI_CAT9010_SIM3_SINGAL_Y 146
	#define WGUI_CAT9010_SIM3_LINE_X 60
	#define WGUI_CAT9010_SIM3_LINE_Y 123
// center
	#define WGUI_CAT9010_PETAL_CENTER_X  88
	#define WGUI_CAT9010_PETAL_CENTER_Y	 139
	#define WGUI_CAT9010_PETAL_RADIUS    78

// popup 
	#define WGUI_CAT9010_POPUP_X1  8
	#define WGUI_CAT9010_POPUP_Y1  30
	#define WGUI_CAT9010_POPUP_X2  168
	#define WGUI_CAT9010_POPUP_Y2  186
	#define WGUI_CAT9010_POPUP_TITLE_H 20
    
    // INFO BG
    #define WGUI_CAT9010_INFO_BG_X 19
    #define WGUI_CAT9010_INFO_BG_Y 28
    #define WGUI_CAT9010_INFO_BG_W 134
    #define WGUI_CAT9010_INFO_BG_H 50
    #define WGUI_CAT9010_INFO_GAP 14
    #define WGUI_CAT9010_STATUS_ICON_W 70
    // popup text
    #define WGUI_CAT9010_POPUP_TITLE_X (WGUI_CAT9010_POPUP_X1 + WGUI_CAT9010_INFO_GAP)
    #define WGUI_CAT9010_POPUP_TITLE_Y (WGUI_CAT9010_POPUP_Y1 + UI_POPUP_BORDER_SIZE)
    
    // LINE
    #define WGUI_CAT9010_LINE_Y 54
    #define WGUI_CAT9010_POPUP_LINE_Y (WGUI_CAT9010_POPUP_Y1 + 30)
    #define WGUI_CAT9010_POPUP_LINE_X  20

#endif /* (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))*/
#elif defined(__MMI_MAINLCD_240X400__)
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))   // 4card
	#define WGUI_CAT9010_IMAGE1_X  86
	#define WGUI_CAT9010_IMAGE1_Y  158
	#define WGUI_CAT9010_IMAGE2_X  121
	#define WGUI_CAT9010_IMAGE2_Y  204
	#define WGUI_CAT9010_IMAGE3_X  86
	#define WGUI_CAT9010_IMAGE3_Y  238
	#define WGUI_CAT9010_IMAGE4_X  40
	#define WGUI_CAT9010_IMAGE4_Y  204
// singal 
	#define WGUI_CAT9010_SIM1_SINGAL_X 112
	#define WGUI_CAT9010_SIM1_SINGAL_Y 215
	#define WGUI_CAT9010_SIM1_LINE_X 97
	#define WGUI_CAT9010_SIM1_LINE_Y 94
	
	#define WGUI_CAT9010_SIM2_SINGAL_X 127
	#define WGUI_CAT9010_SIM2_SINGAL_Y 224
	#define WGUI_CAT9010_SIM2_LINE_X 108
	#define WGUI_CAT9010_SIM2_LINE_Y 104
	
	#define WGUI_CAT9010_SIM3_SINGAL_X 107
	#define WGUI_CAT9010_SIM3_SINGAL_Y 245
	#define WGUI_CAT9010_SIM3_LINE_X 97
	#define WGUI_CAT9010_SIM3_LINE_Y 140
	
	#define WGUI_CAT9010_SIM4_SINGAL_X 97
	#define WGUI_CAT9010_SIM4_SINGAL_Y 229
	#define WGUI_CAT9010_SIM4_LINE_X 60
	#define WGUI_CAT9010_SIM4_LINE_Y 104
	
// center
	#define WGUI_CAT9010_PETAL_CENTER_X  120
	#define WGUI_CAT9010_PETAL_CENTER_Y	 238
	#define WGUI_CAT9010_PETAL_RADIUS    80

// popup 
	#define WGUI_CAT9010_POPUP_X1  9
	#define WGUI_CAT9010_POPUP_Y1  46
	#define WGUI_CAT9010_POPUP_X2  224
	#define WGUI_CAT9010_POPUP_Y2  337
	#define WGUI_CAT9010_POPUP_TITLE_H 30

// INFO BG
    #define WGUI_CAT9010_INFO_BG_X 24
    #define WGUI_CAT9010_INFO_BG_Y 57
    #define WGUI_CAT9010_INFO_BG_W 190
    #define WGUI_CAT9010_INFO_BG_H 80
    #define WGUI_CAT9010_INFO_GAP 14
    #define WGUI_CAT9010_STATUS_ICON_W 70
// popup text
    #define WGUI_CAT9010_POPUP_TITLE_X (WGUI_CAT9010_POPUP_X1 + WGUI_CAT9010_INFO_GAP)
    #define WGUI_CAT9010_POPUP_TITLE_Y (WGUI_CAT9010_POPUP_Y1 + UI_POPUP_BORDER_SIZE)

// LINE
    #define WGUI_CAT9010_LINE_Y 97
    #define WGUI_CAT9010_POPUP_LINE_Y (WGUI_CAT9010_POPUP_Y1 + 35)
    #define WGUI_CAT9010_POPUP_LINE_X  20
#else  // 3 card
	#define WGUI_CAT9010_IMAGE1_X  86
	#define WGUI_CAT9010_IMAGE1_Y  180
	#define WGUI_CAT9010_IMAGE2_X  121
	#define WGUI_CAT9010_IMAGE2_Y  226
	#define WGUI_CAT9010_IMAGE3_X  40
	#define WGUI_CAT9010_IMAGE3_Y  226

// singal 
	#define WGUI_CAT9010_SIM1_SINGAL_X 112
	#define WGUI_CAT9010_SIM1_SINGAL_Y 236
	#define WGUI_CAT9010_SIM1_LINE_X 97
	#define WGUI_CAT9010_SIM1_LINE_Y 113
	#define WGUI_CAT9010_SIM2_SINGAL_X 127
	#define WGUI_CAT9010_SIM2_SINGAL_Y 245
	#define WGUI_CAT9010_SIM2_LINE_X 108
	#define WGUI_CAT9010_SIM2_LINE_Y 123
	#define WGUI_CAT9010_SIM3_SINGAL_X 97
	#define WGUI_CAT9010_SIM3_SINGAL_Y 250
	#define WGUI_CAT9010_SIM3_LINE_X 60
	#define WGUI_CAT9010_SIM3_LINE_Y 123
// center
	#define WGUI_CAT9010_PETAL_CENTER_X  122
	#define WGUI_CAT9010_PETAL_CENTER_Y	 260
	#define WGUI_CAT9010_PETAL_RADIUS    80
	
// popup 
	#define WGUI_CAT9010_POPUP_X1  13
	#define WGUI_CAT9010_POPUP_Y1  48
	#define WGUI_CAT9010_POPUP_X2  220
	#define WGUI_CAT9010_POPUP_Y2  334
	#define WGUI_CAT9010_POPUP_TITLE_H 30
	
    // INFO BG
    #define WGUI_CAT9010_INFO_BG_X 24
    #define WGUI_CAT9010_INFO_BG_Y 57
    #define WGUI_CAT9010_INFO_BG_W 190
    #define WGUI_CAT9010_INFO_BG_H 63
    #define WGUI_CAT9010_INFO_GAP 14
    #define WGUI_CAT9010_STATUS_ICON_W 70
    // popup text
    #define WGUI_CAT9010_POPUP_TITLE_X (WGUI_CAT9010_POPUP_X1 + WGUI_CAT9010_INFO_GAP)
    #define WGUI_CAT9010_POPUP_TITLE_Y (WGUI_CAT9010_POPUP_Y1 + UI_POPUP_BORDER_SIZE)
	
    // LINE
    #define WGUI_CAT9010_LINE_Y 97
    #define WGUI_CAT9010_POPUP_LINE_Y (WGUI_CAT9010_POPUP_Y1 + 35)
    #define WGUI_CAT9010_POPUP_LINE_X  20

#endif /* (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))*/
#else // 320X480
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))   // 4card
	#define WGUI_CAT9010_IMAGE1_X  112
	#define WGUI_CAT9010_IMAGE1_Y  163
	#define WGUI_CAT9010_IMAGE2_X  160
	#define WGUI_CAT9010_IMAGE2_Y  229
	#define WGUI_CAT9010_IMAGE3_X  112
	#define WGUI_CAT9010_IMAGE3_Y  277
	#define WGUI_CAT9010_IMAGE4_X  46
	#define WGUI_CAT9010_IMAGE4_Y  229
// singal 
	#define WGUI_CAT9010_SIM1_SINGAL_X 150
	#define WGUI_CAT9010_SIM1_SINGAL_Y 252
	#define WGUI_CAT9010_SIM1_LINE_X 97
	#define WGUI_CAT9010_SIM1_LINE_Y 94

	#define WGUI_CAT9010_SIM2_SINGAL_X 166
	#define WGUI_CAT9010_SIM2_SINGAL_Y 263
	#define WGUI_CAT9010_SIM2_LINE_X 108
	#define WGUI_CAT9010_SIM2_LINE_Y 104

	#define WGUI_CAT9010_SIM3_SINGAL_X 146
	#define WGUI_CAT9010_SIM3_SINGAL_Y 283
	#define WGUI_CAT9010_SIM3_LINE_X 97
	#define WGUI_CAT9010_SIM3_LINE_Y 140

	#define WGUI_CAT9010_SIM4_SINGAL_X 136
	#define WGUI_CAT9010_SIM4_SINGAL_Y 267
	#define WGUI_CAT9010_SIM4_LINE_X 60
	#define WGUI_CAT9010_SIM4_LINE_Y 104

// center
	#define WGUI_CAT9010_PETAL_CENTER_X  158
	#define WGUI_CAT9010_PETAL_CENTER_Y	 276
	#define WGUI_CAT9010_PETAL_RADIUS    110

// popup 
	#define WGUI_CAT9010_POPUP_X1  10
	#define WGUI_CAT9010_POPUP_Y1  70
	#define WGUI_CAT9010_POPUP_X2  310
	#define WGUI_CAT9010_POPUP_Y2  400
    #define WGUI_CAT9010_POPUP_TITLE_H  30

// INFO BG
    #define WGUI_CAT9010_INFO_BG_X 40
    #define WGUI_CAT9010_INFO_BG_Y 59
    #define WGUI_CAT9010_INFO_BG_W 238
    #define WGUI_CAT9010_INFO_BG_H 82
    #define WGUI_CAT9010_INFO_GAP 14
    #define WGUI_CAT9010_STATUS_ICON_W 70
// popup text
    #define WGUI_CAT9010_POPUP_TITLE_X (WGUI_CAT9010_POPUP_X1 + WGUI_CAT9010_INFO_GAP)
    #define WGUI_CAT9010_POPUP_TITLE_Y (WGUI_CAT9010_POPUP_Y1 + 5)

// LINE
    #define WGUI_CAT9010_LINE_Y 99
    #define WGUI_CAT9010_POPUP_LINE_Y (WGUI_CAT9010_POPUP_Y1 + 45)
    #define WGUI_CAT9010_POPUP_LINE_X  20
#else  // 3 card
	#define WGUI_CAT9010_IMAGE1_X  112
	#define WGUI_CAT9010_IMAGE1_Y  197
	#define WGUI_CAT9010_IMAGE2_X  160
	#define WGUI_CAT9010_IMAGE2_Y  263
	#define WGUI_CAT9010_IMAGE3_X  46
	#define WGUI_CAT9010_IMAGE3_Y  263

// singal 
	#define WGUI_CAT9010_SIM1_SINGAL_X 150
	#define WGUI_CAT9010_SIM1_SINGAL_Y 286
	#define WGUI_CAT9010_SIM1_LINE_X 97
	#define WGUI_CAT9010_SIM1_LINE_Y 113
	#define WGUI_CAT9010_SIM2_SINGAL_X 166
	#define WGUI_CAT9010_SIM2_SINGAL_Y 297
	#define WGUI_CAT9010_SIM2_LINE_X 108
	#define WGUI_CAT9010_SIM2_LINE_Y 123
	#define WGUI_CAT9010_SIM3_SINGAL_X 136
	#define WGUI_CAT9010_SIM3_SINGAL_Y 301
	#define WGUI_CAT9010_SIM3_LINE_X 60
	#define WGUI_CAT9010_SIM3_LINE_Y 123
// center
	#define WGUI_CAT9010_PETAL_CENTER_X  158
	#define WGUI_CAT9010_PETAL_CENTER_Y	 307
	#define WGUI_CAT9010_PETAL_RADIUS    112

// popup 
	#define WGUI_CAT9010_POPUP_X1  10
	#define WGUI_CAT9010_POPUP_Y1  66
	#define WGUI_CAT9010_POPUP_X2  310
	#define WGUI_CAT9010_POPUP_Y2  400
    #define WGUI_CAT9010_POPUP_TITLE_H  30

    // INFO BG
    #define WGUI_CAT9010_INFO_BG_X 40
    #define WGUI_CAT9010_INFO_BG_Y 59
    #define WGUI_CAT9010_INFO_BG_W 238
    #define WGUI_CAT9010_INFO_BG_H 82
    #define WGUI_CAT9010_INFO_GAP 14
    #define WGUI_CAT9010_STATUS_ICON_W 70
    // popup text
    #define WGUI_CAT9010_POPUP_TITLE_X (WGUI_CAT9010_POPUP_X1 + WGUI_CAT9010_INFO_GAP)
    #define WGUI_CAT9010_POPUP_TITLE_Y (WGUI_CAT9010_POPUP_Y1 + 5)

    // LINE
    #define WGUI_CAT9010_LINE_Y 99
    #define WGUI_CAT9010_POPUP_LINE_Y (WGUI_CAT9010_POPUP_Y1 + 45)
    #define WGUI_CAT9010_POPUP_LINE_X  20

#endif /* (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))*/
#endif

/*******
 * static function
 *************/
#if defined(__MMI_CAT9010_STYLE_2__)
static void wgui_cat9010_draw_petal(S32 index);
static void wgui_cat9010_draw_petal_signal_icon(S32 index);
static void wgui_cat9010_draw_petal_background(void);
static void wgui_cat9010_scrolling_text0_timer(void);
static void wgui_cat9010_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2);

#if defined(__MMI_TOUCH_SCREEN__)
static S32 wgui_cat9010_translate_pen_event(mmi_pen_point_struct point);
static MMI_BOOL wgui_cat9010_pen_down_handler(mmi_pen_point_struct point);
#endif

static void wgui_cat9010_down_arrow_key_handler(void);
static void wgui_cat9010_up_arrow_key_handler(void);
static void wgui_cat9010_right_arrow_key_handler(void);
static void wgui_cat9010_left_arrow_key_handler(void);
static void wgui_cat9010_arrow_key_handler(S32 new_index);
static void wgui_cat9010_redraw_by_arrow_key(S32 new_index, S32 old_index);
static void wgui_cat9010_draw_ctrl_area1(dm_coordinates *coordinate);
static void wgui_cat9010_draw_ctrl_area2(dm_coordinates *coordinate);
static void wgui_cat9010_update_petal(void);

static void wgui_cat9010_draw_info_bg(void);
static void wgui_cat9010_draw_space_info(S32 index);
static void wgui_cat9010_draw_selector_info(S32 index);
static void wgui_cat9010_draw_space_status_icon(S32 index);
static void wgui_cat9010_update_selector_text(S32 sim_index);
static void wgui_cat9010_draw_space_status_icon_loop_timer(void);
#endif

// common
static void wgui_cat9010_enter_key_handler(void);
static void wgui_cat9010_exit(void);
static S32 wgui_cat9010_get_highlight_index(void);
static void wgui_cat9010_set_highlight_index(S32 index);
static U8 wgui_cat9010_get_status_icon_image_id(S32 sim_index, U16 image[]);
static MMI_BOOL wgui_cat9010_check_status_icon_in_sim2(S32 icon_id);
static MMI_BOOL wgui_cat9010_check_status_icon_in_sim1(S32 icon_id);
static MMI_BOOL wgui_cat9010_check_status_icon_in_sim3(S32 icon_id);
static MMI_BOOL wgui_cat9010_check_status_icon_in_sim4(S32 icon_id);
static MMI_BOOL wgui_cat9010_set_right_highlight_index_by_state(void);

extern void dm_draw_scr_bg_image(void);
/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_register_highlight_handler
 * DESCRIPTION
 *  Register sim highlight handler
 * PARAMETERS
 *  f                   [IN]     highlight handler callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9010_register_highlight_handler(void (*f)(S32 sim_index))
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wgui_cat9010_highlight_handler = f;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_register_select_handler
 * DESCRIPTION
 *  Register sim selected handler
 * PARAMETERS
 *  f                   [IN]     selected handler callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9010_register_select_handler(void(*f)(S32 sim_index))
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wgui_cat9010_selected_handler = f;
}

/*  Common static function */

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_set_highlight_index
 * DESCRIPTION
 *  set highlight index
 * PARAMETERS
 *  index                   [IN]     sim index
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9010_set_highlight_index(S32 index)
{
	g_cat9010_sim_highlight_index = index;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_get_highlight_index
 * DESCRIPTION
 *  get highlight sim index
 * PARAMETERS
 *  void
 * RETURNS
 *  S32    [OUT]  highlight index
 *****************************************************************************/
static S32 wgui_cat9010_get_highlight_index(void)
{
	return g_cat9010_sim_highlight_index;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_enter_key_handler
 * DESCRIPTION
 *  KEY ENTER handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void wgui_cat9010_enter_key_handler(void)
{
	S32 highlight_index;

	highlight_index = wgui_cat9010_get_highlight_index();
	if(highlight_index != -1)
	{
		if(wgui_cat9010_selected_handler)
			wgui_cat9010_selected_handler(highlight_index);
	}
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_get_status_icon_image_id
 * DESCRIPTION
 *  get status icon image id shown in the sim x area
 * PARAMETERS
 *  sim_index                   [IN]     sim index
 *  image[]                     [IN]     image array
 * RETURNS
 *  U8      [OUT]  image count
 *****************************************************************************/
static U8 wgui_cat9010_get_status_icon_image_id(S32 sim_index, U16 image[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 sim1_icon[] = {
		// call divert
		STATUS_ICON_CALL_DIVERT_L1L2,
		STATUS_ICON_CALL_DIVERT_L1,
		STATUS_ICON_CALL_DIVERT_L2,
		// romaing
		STATUS_ICON_ROAMING,
		// homezone
#ifdef __HOMEZONE_SUPPORT__
		STATUS_ICON_HOMEZONE,
#endif

#ifndef __MMI_NCENTER_SUPPORT__
#ifdef __MMI_SLIM_IMG_RES__
        STATUS_ICON_UNREAD_VOICE_MASTER,
        STATUS_ICON_UNREAD_FAX_MASTER,
        STATUS_ICON_UNREAD_EMAIL_MASTER,
        STATUS_ICON_UNREAD_VIDEO_MASTER,
        STATUS_ICON_UNREAD_NET_MASTER
#else
		// unread voice
		STATUS_ICON_UNREAD_VOICE_L1_MASTER,
		STATUS_ICON_UNREAD_VOICE_L2_MASTER,
		STATUS_ICON_UNREAD_VOICE_L1L2_MASTER,
		// unread fax
		STATUS_ICON_UNREAD_FAX_L1_MASTER,
		STATUS_ICON_UNREAD_FAX_L2_MASTER,
		STATUS_ICON_UNREAD_FAX_L1L2_MASTER,
		// unread email
		STATUS_ICON_UNREAD_EMAIL_L1_MASTER,
		STATUS_ICON_UNREAD_EMAIL_L2_MASTER,
		STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER,
		// unread video
		STATUS_ICON_UNREAD_VIDEO_L1_MASTER,
		STATUS_ICON_UNREAD_VIDEO_L2_MASTER,
		STATUS_ICON_UNREAD_VIDEO_L1L2_MASTER,
		// unread net
		STATUS_ICON_UNREAD_NET_L1_MASTER,
		STATUS_ICON_UNREAD_NET_L2_MASTER,
		STATUS_ICON_UNREAD_NET_L1L2_MASTER
#endif /* __MMI_SLIM_IMG_RES__ */
#endif
		};
	U16 sim2_icon[] = {
		// call divert
		STATUS_ICON_SLAVE_CALLFORWARD,
		STATUS_ICON_SLAVE_CALLFORWARD_L1,
		STATUS_ICON_SLAVE_CALLFORWARD_L2,
		// romaing
		STATUS_ICON_SLAVE_ROAMING,
		// homezone
#ifdef __HOMEZONE_SUPPORT__
		STATUS_ICON_SLAVE_HOMEZONE,
#endif
#ifndef __MMI_NCENTER_SUPPORT__
#ifdef __MMI_SLIM_IMG_RES__
        STATUS_ICON_UNREAD_VOICE_SLAVE,
        STATUS_ICON_UNREAD_FAX_SLAVE,
        STATUS_ICON_UNREAD_EMAIL_SLAVE,
        STATUS_ICON_UNREAD_VIDEO_SLAVE,
        STATUS_ICON_UNREAD_NET_SLAVE
#else
		// unread voice
		STATUS_ICON_UNREAD_VOICE_L1_SLAVE, 
		STATUS_ICON_UNREAD_VOICE_L2_SLAVE, 
		STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE,
		// unread fax
		STATUS_ICON_UNREAD_FAX_L1_SLAVE, 
		STATUS_ICON_UNREAD_FAX_L2_SLAVE, 
		STATUS_ICON_UNREAD_FAX_L1L2_SLAVE,
		// unread email
		STATUS_ICON_UNREAD_EMAIL_L1_SLAVE, 
		STATUS_ICON_UNREAD_EMAIL_L2_SLAVE, 
		STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE,
		// unread video
		STATUS_ICON_UNREAD_VIDEO_L1_SLAVE, 
		STATUS_ICON_UNREAD_VIDEO_L2_SLAVE, 
		STATUS_ICON_UNREAD_VIDEO_L1L2_SLAVE,
		// unread net
		STATUS_ICON_UNREAD_NET_L1_SLAVE, 
		STATUS_ICON_UNREAD_NET_L2_SLAVE, 
		STATUS_ICON_UNREAD_NET_L1L2_SLAVE
#endif /* __MMI_SLIM_IMG_RES__ */
#endif
        };
	U16 sim3_icon[] = {
		// call divert
		STATUS_ICON_SIM3_CALL_DIVERT,
		STATUS_ICON_SIM3_CALL_DIVERT_L1,
		STATUS_ICON_SIM3_CALL_DIVERT_L2,
		// romaing
		STATUS_ICON_SIM3_ROAMING,
		// homezone
#ifdef __HOMEZONE_SUPPORT__
		STATUS_ICON_SIM3_HOMEZONE,
#endif
#ifndef __MMI_NCENTER_SUPPORT__
#ifdef __MMI_SLIM_IMG_RES__
        STATUS_ICON_UNREAD_VOICE_SIM3,
        STATUS_ICON_UNREAD_FAX_SIM3,
        STATUS_ICON_UNREAD_EMAIL_SIM3,
        STATUS_ICON_UNREAD_VIDEO_SIM3,
        STATUS_ICON_UNREAD_NET_SIM3
#else
		// unread voice
		STATUS_ICON_UNREAD_VOICE_L1_SIM3,
		STATUS_ICON_UNREAD_VOICE_L2_SIM3,
		STATUS_ICON_UNREAD_VOICE_L1L2_SIM3,
		// unread fax
		STATUS_ICON_UNREAD_FAX_L1_SIM3,
		STATUS_ICON_UNREAD_FAX_L2_SIM3,
		STATUS_ICON_UNREAD_FAX_L1L2_SIM3,
		// unread email
		STATUS_ICON_UNREAD_EMAIL_L1_SIM3,
		STATUS_ICON_UNREAD_EMAIL_L2_SIM3,
		STATUS_ICON_UNREAD_EMAIL_L1L2_SIM3,
		// unread video
		STATUS_ICON_UNREAD_VIDEO_L1_SIM3,
		STATUS_ICON_UNREAD_VIDEO_L2_SIM3,
		STATUS_ICON_UNREAD_VIDEO_L1L2_SIM3,
		// unread net
		STATUS_ICON_UNREAD_NET_L1_SIM3,
		STATUS_ICON_UNREAD_NET_L2_SIM3,
		STATUS_ICON_UNREAD_NET_L1L2_SIM3
#endif /* __MMI_SLIM_IMG_RES__ */		
#endif
		};
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))
	U16 sim4_icon[] = {
		// call divert
		STATUS_ICON_SIM4_CALL_DIVERT,
		STATUS_ICON_SIM4_CALL_DIVERT_L1,
		STATUS_ICON_SIM4_CALL_DIVERT_L2,
		// romaing
		STATUS_ICON_SIM4_ROAMING,
		// homezone
#ifdef __HOMEZONE_SUPPORT__
		STATUS_ICON_SIM4_HOMEZONE,
#endif
#ifndef __MMI_NCENTER_SUPPORT__
#ifdef __MMI_SLIM_IMG_RES__
        STATUS_ICON_UNREAD_VOICE_SIM4,
        STATUS_ICON_UNREAD_FAX_SIM4,
        STATUS_ICON_UNREAD_EMAIL_SIM4,
        STATUS_ICON_UNREAD_VIDEO_SIM4,
        STATUS_ICON_UNREAD_NET_SIM4
#else
		// unread voice
		STATUS_ICON_UNREAD_VOICE_L1_SIM4,
		STATUS_ICON_UNREAD_VOICE_L2_SIM4,
		STATUS_ICON_UNREAD_VOICE_L1L2_SIM4,
		// unread fax
		STATUS_ICON_UNREAD_FAX_L1_SIM4,
		STATUS_ICON_UNREAD_FAX_L2_SIM4,
		STATUS_ICON_UNREAD_FAX_L1L2_SIM4,
		// unread email
		STATUS_ICON_UNREAD_EMAIL_L1_SIM4,
		STATUS_ICON_UNREAD_EMAIL_L2_SIM4,
		STATUS_ICON_UNREAD_EMAIL_L1L2_SIM4,
		// unread video
		STATUS_ICON_UNREAD_VIDEO_L1_SIM4,
		STATUS_ICON_UNREAD_VIDEO_L2_SIM4,
		STATUS_ICON_UNREAD_VIDEO_L1L2_SIM4,
		// unread net
		STATUS_ICON_UNREAD_NET_L1_SIM4,
		STATUS_ICON_UNREAD_NET_L2_SIM4,
		STATUS_ICON_UNREAD_NET_L1L2_SIM4
#endif /* 	__MMI_SLIM_IMG_RES__ */	
#endif
		};
#endif
	U8 icon_count = 0;
	U8 i;
	U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon_count = sizeof(sim1_icon) / sizeof(U16);
	switch (sim_index)
	{
	    case 0:
    		for(i = 0; i < icon_count; i++)
    		{
    			if(wgui_status_icon_bar_whether_icon_display(sim1_icon[i]))
    			{
    				MMI_ASSERT(count < 9);
    				image[count] = wgui_status_icon_bar_get_icon_image_id(sim1_icon[i]);
    				count ++;
    			}
    		}
    		break;
	    case 1:
    		for(i = 0; i < icon_count; i++)
    		{
    			if(wgui_status_icon_bar_whether_icon_display(sim2_icon[i]))
    			{
    				MMI_ASSERT(count < 9);
    				image[count] = wgui_status_icon_bar_get_icon_image_id(sim2_icon[i]);
    				count ++;
    			}
    		}
    		break;
	    case 2:
    		for(i = 0; i < icon_count; i++)
    		{
    			if(wgui_status_icon_bar_whether_icon_display(sim3_icon[i]))
    			{
    				MMI_ASSERT(count < 9);
    				image[count] = wgui_status_icon_bar_get_icon_image_id(sim3_icon[i]);
    				count ++;
    			}
    		}
    		break;
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))
    	case 3:
    		for(i = 0; i < icon_count; i++)
    		{
    			if(wgui_status_icon_bar_whether_icon_display(sim4_icon[i]))
    			{
    				MMI_ASSERT(count < 9);
    				image[count] = wgui_status_icon_bar_get_icon_image_id(sim4_icon[i]);
    				count ++;
    			}
    		}
    		break;
#endif
	    default:
		    break;
	}

	return count;
}


static MMI_BOOL wgui_cat9010_check_status_icon_in_sim1(S32 icon_id)
{
	U16 sim1_icon[] = {
		// call divert
		STATUS_ICON_CALL_DIVERT_L1L2,
		STATUS_ICON_CALL_DIVERT_L1,
		STATUS_ICON_CALL_DIVERT_L2,
		// romaing
		STATUS_ICON_ROAMING,
		// homezone
#ifdef __HOMEZONE_SUPPORT__
		STATUS_ICON_HOMEZONE,
#endif
#ifndef __MMI_NCENTER_SUPPORT__
#ifdef __MMI_SLIM_IMG_RES__
        STATUS_ICON_UNREAD_VOICE_MASTER,
        STATUS_ICON_UNREAD_FAX_MASTER,
        STATUS_ICON_UNREAD_EMAIL_MASTER,
        STATUS_ICON_UNREAD_VIDEO_MASTER,
        STATUS_ICON_UNREAD_NET_MASTER
#else
		// unread voice
		STATUS_ICON_UNREAD_VOICE_L1_MASTER,
		STATUS_ICON_UNREAD_VOICE_L2_MASTER,
		STATUS_ICON_UNREAD_VOICE_L1L2_MASTER,
		// unread fax
		STATUS_ICON_UNREAD_FAX_L1_MASTER,
		STATUS_ICON_UNREAD_FAX_L2_MASTER,
		STATUS_ICON_UNREAD_FAX_L1L2_MASTER,
		// unread email
		STATUS_ICON_UNREAD_EMAIL_L1_MASTER,
		STATUS_ICON_UNREAD_EMAIL_L2_MASTER,
		STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER,
		// unread video
		STATUS_ICON_UNREAD_VIDEO_L1_MASTER,
		STATUS_ICON_UNREAD_VIDEO_L2_MASTER,
		STATUS_ICON_UNREAD_VIDEO_L1L2_MASTER,
		// unread net
		STATUS_ICON_UNREAD_NET_L1_MASTER,
		STATUS_ICON_UNREAD_NET_L2_MASTER,
		STATUS_ICON_UNREAD_NET_L1L2_MASTER
#endif /* __MMI_SLIM_IMG_RES__ */
#endif
		};
	U8 j = 0;
    U8 i = 0;


    i = sizeof(sim1_icon) / sizeof(U16);
	for(j = 0; j < i; j++)
		if(sim1_icon[j] == icon_id)
			return MMI_TRUE;
	return MMI_FALSE;

}

static MMI_BOOL wgui_cat9010_check_status_icon_in_sim2(S32 icon_id)
{
	U16 sim2_icon[] = {
		// call divert
		STATUS_ICON_SLAVE_CALLFORWARD,
		STATUS_ICON_SLAVE_CALLFORWARD_L1,
		STATUS_ICON_SLAVE_CALLFORWARD_L2,
		// romaing
		STATUS_ICON_SLAVE_ROAMING,
		// homezone
#ifdef __HOMEZONE_SUPPORT__
		STATUS_ICON_SLAVE_HOMEZONE,
#endif
#ifndef __MMI_NCENTER_SUPPORT__
#ifdef __MMI_SLIM_IMG_RES__
        STATUS_ICON_UNREAD_VOICE_SLAVE,
        STATUS_ICON_UNREAD_FAX_SLAVE,
        STATUS_ICON_UNREAD_EMAIL_SLAVE,
        STATUS_ICON_UNREAD_VIDEO_SLAVE,
        STATUS_ICON_UNREAD_NET_SLAVE
#else
		// unread voice
		STATUS_ICON_UNREAD_VOICE_L1_SLAVE, 
		STATUS_ICON_UNREAD_VOICE_L2_SLAVE, 
		STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE,
		// unread fax
		STATUS_ICON_UNREAD_FAX_L1_SLAVE, 
		STATUS_ICON_UNREAD_FAX_L2_SLAVE, 
		STATUS_ICON_UNREAD_FAX_L1L2_SLAVE,
		// unread email
		STATUS_ICON_UNREAD_EMAIL_L1_SLAVE, 
		STATUS_ICON_UNREAD_EMAIL_L2_SLAVE, 
		STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE,
		// unread video
		STATUS_ICON_UNREAD_VIDEO_L1_SLAVE, 
		STATUS_ICON_UNREAD_VIDEO_L2_SLAVE, 
		STATUS_ICON_UNREAD_VIDEO_L1L2_SLAVE,
		// unread net
		STATUS_ICON_UNREAD_NET_L1_SLAVE, 
		STATUS_ICON_UNREAD_NET_L2_SLAVE, 
		STATUS_ICON_UNREAD_NET_L1L2_SLAVE
#endif /* __MMI_SLIM_IMG_RES__ */
#endif
        };
	U8 j = 0;
    U8 i = 0;


    i = sizeof(sim2_icon) / sizeof(U16);
	for(j = 0; j < i; j++)
		if(sim2_icon[j] == icon_id)
			return MMI_TRUE;
	return MMI_FALSE;

}

static MMI_BOOL wgui_cat9010_check_status_icon_in_sim3(S32 icon_id)
{
	U16 sim3_icon[] = {
		// call divert
		STATUS_ICON_SIM3_CALL_DIVERT,
		STATUS_ICON_SIM3_CALL_DIVERT_L1,
		STATUS_ICON_SIM3_CALL_DIVERT_L2,
		// romaing
		STATUS_ICON_SIM3_ROAMING,
		// homezone
#ifdef __HOMEZONE_SUPPORT__
		STATUS_ICON_SIM3_HOMEZONE,
#endif
#ifndef __MMI_NCENTER_SUPPORT__
#ifdef __MMI_SLIM_IMG_RES__
        STATUS_ICON_UNREAD_VOICE_SIM3,
        STATUS_ICON_UNREAD_FAX_SIM3,
        STATUS_ICON_UNREAD_EMAIL_SIM3,
        STATUS_ICON_UNREAD_VIDEO_SIM3,
        STATUS_ICON_UNREAD_NET_SIM3
#else
		// unread voice
		STATUS_ICON_UNREAD_VOICE_L1_SIM3,
		STATUS_ICON_UNREAD_VOICE_L2_SIM3,
		STATUS_ICON_UNREAD_VOICE_L1L2_SIM3,
		// unread fax
		STATUS_ICON_UNREAD_FAX_L1_SIM3,
		STATUS_ICON_UNREAD_FAX_L2_SIM3,
		STATUS_ICON_UNREAD_FAX_L1L2_SIM3,
		// unread email
		STATUS_ICON_UNREAD_EMAIL_L1_SIM3,
		STATUS_ICON_UNREAD_EMAIL_L2_SIM3,
		STATUS_ICON_UNREAD_EMAIL_L1L2_SIM3,
		// unread video
		STATUS_ICON_UNREAD_VIDEO_L1_SIM3,
		STATUS_ICON_UNREAD_VIDEO_L2_SIM3,
		STATUS_ICON_UNREAD_VIDEO_L1L2_SIM3,
		// unread net
		STATUS_ICON_UNREAD_NET_L1_SIM3,
		STATUS_ICON_UNREAD_NET_L2_SIM3,
		STATUS_ICON_UNREAD_NET_L1L2_SIM3
#endif /* __MMI_SLIM_IMG_RES__ */		
#endif
		};
	U8 j = 0;
    U8 i = 0;

    i = sizeof(sim3_icon) / sizeof(U16);
	for(j = 0; j < i; j++)
		if(sim3_icon[j] == icon_id)
			return MMI_TRUE;
	return MMI_FALSE;

}


static MMI_BOOL wgui_cat9010_check_status_icon_in_sim4(S32 icon_id)
{
	U16 sim4_icon[] = {
		// call divert
		STATUS_ICON_SIM4_CALL_DIVERT,
		STATUS_ICON_SIM4_CALL_DIVERT_L1,
		STATUS_ICON_SIM4_CALL_DIVERT_L2,
		// romaing
		STATUS_ICON_SIM4_ROAMING,
		// homezone
#ifdef __HOMEZONE_SUPPORT__
		STATUS_ICON_SIM4_HOMEZONE,
#endif
#ifndef __MMI_NCENTER_SUPPORT__
#ifdef __MMI_SLIM_IMG_RES__
        STATUS_ICON_UNREAD_VOICE_SIM4,
        STATUS_ICON_UNREAD_FAX_SIM4,
        STATUS_ICON_UNREAD_EMAIL_SIM4,
        STATUS_ICON_UNREAD_VIDEO_SIM4,
        STATUS_ICON_UNREAD_NET_SIM4
#else
		// unread voice
		STATUS_ICON_UNREAD_VOICE_L1_SIM4,
		STATUS_ICON_UNREAD_VOICE_L2_SIM4,
		STATUS_ICON_UNREAD_VOICE_L1L2_SIM4,
		// unread fax
		STATUS_ICON_UNREAD_FAX_L1_SIM4,
		STATUS_ICON_UNREAD_FAX_L2_SIM4,
		STATUS_ICON_UNREAD_FAX_L1L2_SIM4,
		// unread email
		STATUS_ICON_UNREAD_EMAIL_L1_SIM4,
		STATUS_ICON_UNREAD_EMAIL_L2_SIM4,
		STATUS_ICON_UNREAD_EMAIL_L1L2_SIM4,
		// unread video
		STATUS_ICON_UNREAD_VIDEO_L1_SIM4,
		STATUS_ICON_UNREAD_VIDEO_L2_SIM4,
		STATUS_ICON_UNREAD_VIDEO_L1L2_SIM4,
		// unread net
		STATUS_ICON_UNREAD_NET_L1_SIM4,
		STATUS_ICON_UNREAD_NET_L2_SIM4,
		STATUS_ICON_UNREAD_NET_L1L2_SIM4
#endif /* 	__MMI_SLIM_IMG_RES__ */	
#endif
        };
	 U8 j = 0;
     U8 i = 0;

    i = sizeof(sim4_icon) / sizeof(U16);
	for(j = 0; j < i; j++)
		if(sim4_icon[j] == icon_id)
			return MMI_TRUE;
	return MMI_FALSE;
}
#ifdef __MMI_CAT9010_STYLE_2__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_draw_info_bg
 * DESCRIPTION
 *  Draw info image background
 *  Drawn in the scr bg layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9010_draw_info_bg(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 x, y;
	U16 image_id;
    GDI_HANDLE handle0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = WGUI_CAT9010_INFO_BG_X;
    y = WGUI_CAT9010_INFO_BG_Y;
    handle0 = dm_get_layer_handle(0);
    image_id = IMG_SIM_SPACE_INFO_BG;
	gdi_layer_push_and_set_active(handle0);
	
	gdi_image_draw_id(x, y, image_id); 

	gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_draw_space_info
 * DESCRIPTION
 *  Draw operator name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9010_draw_space_info(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_cat9010_text_struct sim_text;
    S32 sw, sh;
    S32 w, h;
    S32 x, y;
    srv_callset_line_id_enum line_id;
    S32 line_x, line_y;
	mmi_sim_enum sim_id = MMI_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
// draw text
    x = WGUI_CAT9010_INFO_BG_X;
    y = WGUI_CAT9010_INFO_BG_Y;
    w = WGUI_CAT9010_INFO_BG_W - 2*WGUI_CAT9010_INFO_GAP;
    h = WGUI_CAT9010_LINE_Y - WGUI_CAT9010_INFO_BG_Y;
    //clear background
	gdi_draw_solid_rect(x, y, x+WGUI_CAT9010_INFO_BG_W-1, y+h-1, GDI_COLOR_TRANSPARENT); 
  
    memset(&sim_text, 0, sizeof(sim_text));
    gui_set_font(&MMI_medium_font);
    wgui_cat9010_get_text_func(index, g_cat9010_sim_state[index], &sim_text);

    Get_StringWidthHeight((U8*) sim_text.text_0, &sw, &sh);

    if(sw > w)
    {
        gui_set_font(&MMI_small_font);
        Get_StringWidthHeight((U8*) sim_text.text_0, &sw, &sh);
    }

    if(sw > w)
    {
        x = (WGUI_CAT9010_INFO_BG_X + WGUI_CAT9010_INFO_GAP);
    }
    else
    {
        x = WGUI_CAT9010_INFO_BG_X + WGUI_CAT9010_INFO_GAP + (w - sw)/2;
		w = sw;
    }
    y = y + (h-sh)/2 + 2;

    g_cat9010_scroll_text = sim_text;
	gui_scrolling_text_stop(&g_cat9010_scroll_text1);
	gui_create_scrolling_text(
				&g_cat9010_scroll_text1,
				x,
				y,
				w,
				sh,
				g_cat9010_scroll_text.text_0,
				wgui_cat9010_scrolling_text0_timer,
				wgui_cat9010_scrolling_text_draw_background,
#ifdef __MMI_FTE_SUPPORT__
				gui_color(255, 255, 255),
#else
				gui_color(0, 0, 0),
#endif
				gui_color(0, 0, 0));
    gui_show_scrolling_text(&g_cat9010_scroll_text1);

// draw L1, L2.
	gui_set_font(&MMI_medium_font);
	switch(index)
	{
		case 0:
			sim_id = MMI_SIM1;
			break;
		case 1:
			sim_id = MMI_SIM2;
			break;
		case 2:
			sim_id = MMI_SIM3;
			break;
		case 3:
			sim_id = MMI_SIM4;
			break;
		default:
			break;
	}
    line_x = WGUI_CAT9010_INFO_BG_X + WGUI_CAT9010_INFO_GAP;
    Get_StringWidthHeight((U8*)L"L2", &sw, &sh);
    line_y = WGUI_CAT9010_LINE_Y + 1 + (h-sh)/2;
	line_id = srv_callset_line_switch_get_id(sim_id);
    gdi_draw_solid_rect(
        line_x, 
        line_y, 
        line_x+sw-1, 
        line_y+sh-1, 
        GDI_COLOR_TRANSPARENT); 
	if(r2lMMIFlag)
	{
		gui_move_text_cursor(line_x + sw - 1, line_y);
	}
	else
	{
	    gui_move_text_cursor(line_x, line_y);
	}
	if(line_id == SRV_CALLSET_LINE1)
			gui_print_text((UI_string_type)L"L1");
	else if(line_id == SRV_CALLSET_LINE2)
			gui_print_text((UI_string_type)L"L2");

}


static void wgui_cat9010_draw_space_status_icon_loop_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;
    S32 iw, ih;
    S32 index;
    S32 icon_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    x = WGUI_CAT9010_INFO_BG_X + WGUI_CAT9010_INFO_BG_W - WGUI_CAT9010_INFO_GAP;
    index = g_cat9010_loop_context[0].current_index;

    if(index >= g_cat9010_loop_context[0].count)
        return;
    
    icon_id = g_cat9010_loop_context[0].loop_id[index];
    gdi_image_get_dimension_id(icon_id, &iw, &ih);
    y = WGUI_CAT9010_LINE_Y + 1;
	y = y + (WGUI_CAT9010_LINE_Y - WGUI_CAT9010_INFO_BG_Y - ih)/2;
    gdi_draw_solid_rect(
        x - iw - 1, 
        y, 
        x, 
        y+ih, 
        GDI_COLOR_TRANSPARENT);

    index++;
    if(index == g_cat9010_loop_context[0].count)
        index = 0;
    g_cat9010_loop_context[0].current_index = index;
    icon_id = g_cat9010_loop_context[0].loop_id[index];
	gdi_image_get_dimension_id(icon_id, &iw, &ih);
    y = WGUI_CAT9010_LINE_Y + 1 + (WGUI_CAT9010_LINE_Y - WGUI_CAT9010_INFO_BG_Y - ih)/2;
    gdi_image_draw_id(x - iw - 1, y, icon_id);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    StartTimer(CAT9010_TIMER, 500, wgui_cat9010_draw_space_status_icon_loop_timer);
}

static void wgui_cat9010_draw_space_status_icon(S32 index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 icon_id[8];
    U8 count;
    S32 iw = 0, ih = 0;
    S32 i;
    S32 x, y;
    S32 total_w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = wgui_cat9010_get_status_icon_image_id(index, icon_id);
    StopTimer(CAT9010_TIMER);
	if(count > 4)
	{
		g_cat9010_loop_context[0].count = count - 3;  
		for(i = 0; i < count - 3; i++)
			g_cat9010_loop_context[0].loop_id[i] = icon_id[i+3];
		g_cat9010_loop_context[0].current_index = 0;
        StartTimer(CAT9010_TIMER, 500, wgui_cat9010_draw_space_status_icon_loop_timer);
	}
    
    i = 0;

    total_w = 0;
	while((i < count) && (i < 4))
	{
		gdi_image_get_dimension_id(icon_id[i], &iw, &ih);
        total_w += (iw + 1);
		i++;
	}

    i = 0;
    x = WGUI_CAT9010_INFO_BG_X + WGUI_CAT9010_INFO_BG_W - WGUI_CAT9010_INFO_GAP;
    y = WGUI_CAT9010_LINE_Y + 1;
    h = WGUI_CAT9010_LINE_Y - WGUI_CAT9010_INFO_BG_Y;
    gdi_draw_solid_rect(
        x - WGUI_CAT9010_STATUS_ICON_W - 1, 
        y, 
        x, 
        y+h-1,
        GDI_COLOR_TRANSPARENT); 
	x -= total_w;
    while((i < count) && (i < 4))
    {
        y = WGUI_CAT9010_LINE_Y + 1;
        gdi_image_get_dimension_id(icon_id[i], &iw, &ih);
        y += (h - ih)/2;
        gdi_image_draw_id(x +(iw+1)*i, y, icon_id[i]);
        i++;
    }
	 gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}
/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_draw_selector_info
 * DESCRIPTION
 *  Draw operator name
 *  Draw line , draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9010_draw_selector_info(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 title_x, title_y;
    S32 text_x, text_y;
    S32 line_x, line_y;
    s32 w, h;
    wgui_cat9010_text_struct sim_text;
    S32 sw, sh;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    title_x = WGUI_CAT9010_POPUP_TITLE_X;
    title_y = WGUI_CAT9010_POPUP_TITLE_Y;

    w = WGUI_CAT9010_POPUP_X2 - WGUI_CAT9010_POPUP_X1 - 2*WGUI_CAT9010_INFO_GAP;
    h = (WGUI_CAT9010_POPUP_LINE_Y - WGUI_CAT9010_POPUP_Y1 - UI_POPUP_BORDER_SIZE);
//draw title
    gui_set_text_color(*current_MMI_theme->popup_text_color);
    gui_set_font(&MMI_medium_font);
    Get_StringWidthHeight((U8*)MMI_message_string, &sw, &sh);
    if(r2lMMIFlag)
    {
        gui_move_text_cursor(title_x + w - (w-sw)/2, title_y + (h-sh)/2);
    }
    else
    {
        gui_move_text_cursor(title_x + (w-sw)/2, title_y + (h-sh)/2);
    }
    gui_print_text((UI_string_type)MMI_message_string);
// draw line
    line_x = WGUI_CAT9010_POPUP_LINE_X;
    line_y = WGUI_CAT9010_POPUP_LINE_Y;
    gdi_image_draw_id(line_x, line_y, IMG_SIM_SELECTOR_LINE);
// draw text
    memset(&sim_text, 0, sizeof(sim_text));

    wgui_cat9010_get_text_func(index, g_cat9010_sim_state[index], &sim_text);

    Get_StringWidthHeight((U8*)sim_text.text_0, &sw, &sh);
    if(sw > w)
    {
        gui_set_font(&MMI_small_font);
        Get_StringWidthHeight((U8*) sim_text.text_0, &sw, &sh);
    }
    text_x = title_x;
    if(sw < w)
    {
        text_x = title_x + (w - sw)/2;
        w = sw;
    }
    text_y = line_y + 1;
    text_y = text_y + (h - sh)/2;

    g_cat9010_scroll_text = sim_text;
	gui_scrolling_text_stop(&g_cat9010_scroll_text1);
 
    gui_create_scrolling_text(
				&g_cat9010_scroll_text1,
				text_x,
				text_y,
				w,
				sh,
				g_cat9010_scroll_text.text_0,
				wgui_cat9010_scrolling_text0_timer,
				wgui_cat9010_scrolling_text_draw_background,
#ifdef __MMI_FTE_SUPPORT__
				*current_MMI_theme->popup_text_color,
#else
				gui_color(0, 0, 0),
#endif
				gui_color(0, 0, 0));
    gui_show_scrolling_text(&g_cat9010_scroll_text1); 
}

static void wgui_cat9010_update_selector_text(S32 sim_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wgui_cat9010_text_struct sim_text;
	S32 text_x, text_y, text_w, text_h;
	S32 sw,sh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&g_cat9010_scroll_text1);
	text_x = WGUI_CAT9010_POPUP_TITLE_X;
	text_y = WGUI_CAT9010_POPUP_LINE_Y + 1;
	text_w = WGUI_CAT9010_POPUP_X2 - WGUI_CAT9010_POPUP_X1 - 2*WGUI_CAT9010_INFO_GAP;
	text_h = (WGUI_CAT9010_POPUP_LINE_Y - WGUI_CAT9010_POPUP_Y1 - UI_POPUP_BORDER_SIZE);

	gdi_draw_solid_rect(text_x, text_y, text_x + text_w, text_y + text_h +1, GDI_COLOR_TRANSPARENT);
	memset(&sim_text, 0, sizeof(sim_text));
    wgui_cat9010_get_text_func(sim_index, g_cat9010_sim_state[sim_index], &sim_text);

	gui_set_font(&MMI_medium_font);
    Get_StringWidthHeight((U8*)sim_text.text_0, &sw, &sh);
    if(sw > text_w)
    {
        gui_set_font(&MMI_small_font);
        Get_StringWidthHeight((U8*) sim_text.text_0, &sw, &sh);
    }
    if(sw < text_w)
    {
        text_x = text_x + (text_w - sw)/2;
        text_w = sw;
    }
    text_y = text_y + (text_h - sh)/2;

    g_cat9010_scroll_text = sim_text;
	gui_scrolling_text_stop(&g_cat9010_scroll_text1);
 
    gui_create_scrolling_text(
				&g_cat9010_scroll_text1,
				text_x,
				text_y,
				text_w,
				sh,
				g_cat9010_scroll_text.text_0,
				wgui_cat9010_scrolling_text0_timer,
				wgui_cat9010_scrolling_text_draw_background,
#ifdef __MMI_FTE_SUPPORT__
				*current_MMI_theme->popup_text_color,
#else
				gui_color(0, 0, 0),
#endif
				gui_color(0, 0, 0));

    gui_show_scrolling_text(&g_cat9010_scroll_text1); 
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_draw_petal
 * DESCRIPTION
 *  Draw petal background for every sim card
 *  Drawn in the scr bg layer
 * PARAMETERS
 *  index                   [IN]     SIM card index
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9010_draw_petal(S32 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 x = 0, y = 0;
	U16 image_id = 0;
    GDI_HANDLE handle0;
	S32 highlight_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle0 = dm_get_layer_handle(0);
	highlight_index = wgui_cat9010_get_highlight_index();

	switch (index)
	{
	case 0:
			x = WGUI_CAT9010_IMAGE1_X;
			y = WGUI_CAT9010_IMAGE1_Y;
			if(g_cat9010_sim_state[index] == 0)
			{
				image_id = IMG_SIM_GREY_PETAL_1;
                #ifdef __MMI_CAT9010_STYLE_2__
                if(index == highlight_index)
                    image_id = IMG_SIM_GREY_HIGHLIGHT_PETAL_1;
                #endif
			}
			else if(index == highlight_index)
			{
				image_id = IMG_SIM_HIGHLIGHT_PETAL_1;
			}
			else
			{
				image_id = IMG_SIM_NORMAL_PETAL_1;
			}
			break;
	case 1:
			x = WGUI_CAT9010_IMAGE2_X;
			y = WGUI_CAT9010_IMAGE2_Y;
			if(g_cat9010_sim_state[index] == 0)
			{
				image_id = IMG_SIM_GREY_PETAL_2;
                #ifdef __MMI_CAT9010_STYLE_2__
                if(index == highlight_index)
                    image_id = IMG_SIM_GREY_HIGHLIGHT_PETAL_2;
                #endif
			}
			else if(index == highlight_index)
			{
				image_id = IMG_SIM_HIGHLIGHT_PETAL_2;
			}
			else
			{
				image_id = IMG_SIM_NORMAL_PETAL_2;
			}
			break;
	case 2:
			x = WGUI_CAT9010_IMAGE3_X;
			y = WGUI_CAT9010_IMAGE3_Y;
			if(g_cat9010_sim_state[index] == 0)
			{
				image_id = IMG_SIM_GREY_PETAL_3;
                #ifdef __MMI_CAT9010_STYLE_2__
                if(index == highlight_index)
                    image_id = IMG_SIM_GREY_HIGHLIGHT_PETAL_3;
                #endif
			}
			else if(index == highlight_index)
			{
				image_id = IMG_SIM_HIGHLIGHT_PETAL_3;
			}
			else
			{
				image_id = IMG_SIM_NORMAL_PETAL_3;
			}
			break;
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))
	case 3:
			x = WGUI_CAT9010_IMAGE4_X;
			y = WGUI_CAT9010_IMAGE4_Y;
			if(g_cat9010_sim_state[index] == 0)
			{
				image_id = IMG_SIM_GREY_PETAL_4;
                #ifdef __MMI_CAT9010_STYLE_2__
                if(index == highlight_index)
                    image_id = IMG_SIM_GREY_HIGHLIGHT_PETAL_4;
                #endif
			}
			else if(index == highlight_index)
			{
				image_id = IMG_SIM_HIGHLIGHT_PETAL_4;
			}
			else
			{
				image_id = IMG_SIM_NORMAL_PETAL_4;
			}
			break;
#endif
	default:
			MMI_ASSERT(0);
	}
	gdi_layer_push_and_set_active(handle0);
	
	gdi_image_draw_id(x, y, image_id); 

	gdi_layer_pop_and_restore_active();
}


extern UI_filled_area wgui_pop_up_dialog_background;

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_draw_petal_background
 * DESCRIPTION
 *  Draw petal popup background for sim selector screen
 *  Drawn in the base layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9010_draw_petal_background(void)
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	PU8 current_popup_bg;
	GDI_HANDLE handle0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	handle0 = dm_get_layer_handle(0);
	gdi_layer_push_and_set_active(handle0);
	current_popup_bg = wgui_pop_up_dialog_background.b;
#ifndef __MMI_FTE_SUPPORT__
	wgui_pop_up_dialog_background.b = NULL;
#endif
    // grey background
	gui_greyscale_rectangle(0, 0, UI_device_width - 1, UI_device_height - 1, MMI_BG_GREYSCALE_VALUE, MMI_BG_GREYSCALE_BLACK_VALUE); 
    // draw popup background
	wgui_draw_pop_up_screen_background(
        WGUI_CAT9010_POPUP_X1,
        WGUI_CAT9010_POPUP_Y1,
        WGUI_CAT9010_POPUP_X2,
        WGUI_CAT9010_POPUP_Y2,
        &wgui_pop_up_dialog_background,
        MMI_TRUE);
	 wgui_pop_up_dialog_background.b = current_popup_bg;
	 gdi_layer_pop_and_restore_active();

}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_draw_ctrl_area1
 * DESCRIPTION
 *  Draw background for sim space/selector screen
 * PARAMETERS
 *  coordinate      [IN] control area coodinate
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9010_draw_ctrl_area1(dm_coordinates *coordinate)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 index;
#ifdef __MMI_FTE_SUPPORT__
    GDI_HANDLE handle0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);

	if(g_cat9010_screen_type == SIM_SELECTOR)
	{
		wgui_cat9010_draw_petal_background();
#ifdef __MMI_FTE_SUPPORT__
		handle0 = dm_get_layer_handle(0);
		gdi_layer_push_and_set_active(handle0);

        g_cat9010_popup_bg_cache_buf.buf_ptr = (U8*) mmi_frm_scrmem_alloc(WGUI_CAT9010_CACHE_BG_BUF_SIZE);
        g_cat9010_popup_bg_cache_buf.height = WGUI_CAT9010_POPUP_Y2 - WGUI_CAT9010_POPUP_Y1 + 1;
        g_cat9010_popup_bg_cache_buf.width = WGUI_CAT9010_POPUP_X2 - WGUI_CAT9010_POPUP_X1 + 1;
		if(g_cat9010_popup_bg_cache_buf.buf_ptr)
        gdi_image_cache_bmp_get(
            WGUI_CAT9010_POPUP_X1, 
            WGUI_CAT9010_POPUP_Y1,
            WGUI_CAT9010_POPUP_X2,
            WGUI_CAT9010_POPUP_Y2, 
            &g_cat9010_popup_bg_cache_buf); 
		gdi_layer_pop_and_restore_active();
#endif

	}

	for(index = 0; index < g_cat9010_sim_count; index++)
	{
		wgui_cat9010_draw_petal(index);
	}
    if(g_cat9010_screen_type == SIM_SPACE)
        wgui_cat9010_draw_info_bg();
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_scrolling_text0_timer
 * DESCRIPTION
 *  scrolling text timer callback for text line 1
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9010_scrolling_text0_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&g_cat9010_scroll_text1);
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_scrolling_text_draw_background
 * DESCRIPTION
 *  draw scrolling text background
 * PARAMETERS
 *  x1   [IN]  
 *  y1   [IN]
 *  x2   [IN]
 *  y2   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9010_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_draw_petal_signal_icon
 * DESCRIPTION
 *  draw signal image for every sim petal
 * PARAMETERS
 *  index   [IN]   SIM index  
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9010_draw_petal_signal_icon(S32 index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 x = 0, y = 0;
	U16 image_id = 0;
    S32 iw, ih;

	U16 signal[] = {STATUS_ICON_SIGNAL_STRENGTH,
					STATUS_ICON_SLAVE_SIGNAL_STRENGTH
			#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
					,STATUS_ICON_SIM3_SIGNAL_STRENGTH
			#endif
			#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4))
					,STATUS_ICON_SIM4_SIGNAL_STRENGTH
			#endif
			};
    S32 frame_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	frame_number = wgui_status_icon_bar_get_icon_frame_number(signal[index]);

	switch (index)
	{
	case 0:
		x = WGUI_CAT9010_SIM1_SINGAL_X;
		y = WGUI_CAT9010_SIM1_SINGAL_Y;
		image_id = IMG_SIM1_SIGNAL_0;
		break;
	case 1:
		x = WGUI_CAT9010_SIM2_SINGAL_X;
		y = WGUI_CAT9010_SIM2_SINGAL_Y;
		image_id = IMG_SIM2_SIGNAL_0;
		break;
	case 2:
		x = WGUI_CAT9010_SIM3_SINGAL_X;
		y = WGUI_CAT9010_SIM3_SINGAL_Y;
		image_id = IMG_SIM3_SIGNAL_0;
		break;
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))
	case 3:
		x = WGUI_CAT9010_SIM4_SINGAL_X;
		y = WGUI_CAT9010_SIM4_SINGAL_Y;
		image_id = IMG_SIM4_SIGNAL_0;
		break;
#endif
	default:
		break;
	}
    gdi_image_get_dimension_id(image_id, &iw, &ih);
    gdi_draw_solid_rect(x, y, x+iw-1, y+ih-1, GDI_COLOR_TRANSPARENT); 
	if(frame_number > 0)
	{
		image_id += (frame_number -1);
		gdi_image_draw_id(x, y, image_id); 
	}
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_draw_ctrl_area2
 * DESCRIPTION
 *  draw text , status icon , signal icon,
 * PARAMETERS
 *  coordinate  [IN] controlled area's coordinate  
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9010_draw_ctrl_area2(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    index = wgui_cat9010_get_highlight_index();

    if(g_cat9010_screen_type == SIM_SPACE)
    {
        // draw text and L1, L2
        wgui_cat9010_draw_space_info(index);

        // draw status icon
        wgui_cat9010_draw_space_status_icon(index);
    }
    if(g_cat9010_screen_type == SIM_SELECTOR)
        wgui_cat9010_draw_selector_info(index);
    for(index = 0; index < g_cat9010_sim_count; index++)
    {
       // draw  signal icon
       wgui_cat9010_draw_petal_signal_icon(index); 
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_update_petal
 * DESCRIPTION
 *  update petal background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9010_update_petal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
#if defined(__MMI_FTE_SUPPORT__)
	GDI_HANDLE handle0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_cat9010_screen_type == SIM_SELECTOR)
    {
#if !defined(__MMI_FTE_SUPPORT__)
        wgui_cat9010_draw_petal_background();
#else
		handle0 = dm_get_layer_handle(0);
		gdi_layer_push_and_set_active(handle0);
		if(g_cat9010_popup_bg_cache_buf.buf_ptr)
		 gdi_image_cache_bmp_draw(WGUI_CAT9010_POPUP_X1, WGUI_CAT9010_POPUP_Y1, &g_cat9010_popup_bg_cache_buf);  
		gdi_layer_pop_and_restore_active();
#endif
    }
    if(g_cat9010_screen_type == SIM_SPACE)
    {
        dm_draw_scr_bg_image();
    }

	for(index = 0; index < g_cat9010_sim_count; index++)
    {
		wgui_cat9010_draw_petal(index);
    }
    if(g_cat9010_screen_type == SIM_SPACE)
    {
        wgui_cat9010_draw_info_bg();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_redraw_by_arrow_key
 * DESCRIPTION
 *  redraw sim area
 * PARAMETERS
 *  new_index    [IN]   new highlight index
 *  old_index    [IN]   old highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9010_redraw_by_arrow_key(S32 new_index, S32 old_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


	gdi_layer_lock_frame_buffer();
	//petal
	wgui_cat9010_update_petal();

    if(g_cat9010_screen_type == SIM_SPACE)
    {
        wgui_cat9010_draw_space_info(new_index);
        StopTimer(CAT9010_TIMER);
        wgui_cat9010_draw_space_status_icon(new_index);
    }
	if(g_cat9010_screen_type == SIM_SELECTOR)
	{
		wgui_cat9010_update_selector_text(new_index);
	}

	//signal
	wgui_cat9010_draw_petal_signal_icon(old_index);
	wgui_cat9010_draw_petal_signal_icon(new_index);
	gdi_layer_unlock_frame_buffer();


	gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_arrow_key_handler
 * DESCRIPTION
 *  redraw sim area
 * PARAMETERS
 *  new_index    [IN]   new highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9010_arrow_key_handler(S32 new_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 old_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	old_index = wgui_cat9010_get_highlight_index();

	if(old_index == -1)
		return;
	if(old_index != new_index)
	{
		wgui_cat9010_set_highlight_index(new_index);
		wgui_cat9010_redraw_by_arrow_key(new_index, old_index);
		if(wgui_cat9010_highlight_handler)
			wgui_cat9010_highlight_handler(new_index);

	}
#if 0  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

static void wgui_cat9010_left_arrow_key_handler(void)
{
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))
	wgui_cat9010_arrow_key_handler(3);
#else
	wgui_cat9010_arrow_key_handler(2);
#endif
}

static void wgui_cat9010_right_arrow_key_handler(void)
{
	wgui_cat9010_arrow_key_handler(1);
}

static void wgui_cat9010_up_arrow_key_handler(void)
{
	wgui_cat9010_arrow_key_handler(0);
}

static void wgui_cat9010_down_arrow_key_handler(void)
{
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))
	wgui_cat9010_arrow_key_handler(2);
#endif
}

#if defined(__MMI_TOUCH_SCREEN__)
static S32 wgui_cat9010_translate_pen_event(mmi_pen_point_struct point)
{
	S32 r1, r2;
	S32 x = WGUI_CAT9010_PETAL_CENTER_X;
	S32 y = WGUI_CAT9010_PETAL_CENTER_Y;
	S32 r = WGUI_CAT9010_PETAL_RADIUS;
	S32 index;

	r1 = (point.x > x) ? (point.x - x) : (x - point.x);
	r2 = (point.y > y) ? (point.y - y) : (y - point.y);

    if((r1*r1 + r2*r2) < r*r)
	{
		if(point.x > x)
		{
			if(r1 > r2)
				index = 1;
			else if (point.y > y)
				index = 2;
			else
				index = 0;
		}
		else
		{
			if(r1 > r2)
				index = 3;
			else if(point.y >y)
				index = 2;
			else 
				index = 0;
		}
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM == 4))
		return index;
#endif
		if(index == 3)
			index = 2;
		return index;
	}
	else
	{
		return -1;
	}
}
static MMI_BOOL wgui_cat9010_pen_down_handler(mmi_pen_point_struct point)
{
	S32 ret;

	ret = wgui_cat9010_translate_pen_event(point);

	if(ret == -1)
		return MMI_FALSE;
	else
	{
		wgui_cat9010_arrow_key_handler(ret);
		return MMI_TRUE;
	}
}
#endif
#endif /* defined(__MMI_CAT9010_STYLE_2__) */

U8 set_category9010_history(U16 history_ID, U8 *history_buffer)
{
	if (history_buffer != NULL)
	{
		wgui_cat9010_history_struct *h = (wgui_cat9010_history_struct*)history_buffer;

		if (history_valid(h->history_ID, history_ID))
		{
			wgui_cat9010_set_highlight_index(h->highlight_index);
		}
		return 1;
	}
	return 0;
}


U8* get_category9010_history(U8 *history_buffer)
{
	 if (history_buffer != NULL)
	 {
		 U16 hID = (U16) (g_dm_data.s32CatId | 0x8000);
		 wgui_cat9010_history_struct *h = (wgui_cat9010_history_struct*)history_buffer;
		 h->history_ID = hID;
		 h->highlight_index = wgui_cat9010_get_highlight_index();

	 }
	  return (history_buffer);
}

S32 get_category9010_history_size(void)
{
	 return (sizeof(wgui_cat9010_history_struct));
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_set_right_highlight_index_by_state
 * DESCRIPTION
 *  change highlight index by sim state
 * PARAMETERS
 *  void      
 * RETURNS
 *  MMI_BOOL :  MMI_TRUE, highlight index changed, MMI_FALSE, not changed
 *****************************************************************************/
static MMI_BOOL wgui_cat9010_set_right_highlight_index_by_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 old_index;
	S32 i;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	old_index = wgui_cat9010_get_highlight_index();
	if(g_cat9010_sim_state[old_index] == 1)
			return MMI_FALSE;

	for(i = 0; i < g_cat9010_sim_count; i++)
	{
		if(g_cat9010_sim_state[i] == 1)
		{
			wgui_cat9010_set_highlight_index(i);
			return MMI_TRUE;
		}
	}

	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_update
 * DESCRIPTION
 *  Update sim content
 * PARAMETERS
 *  sim_index      [IN]     which sim card need update
 *  sim_state      [IN]     sim state
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9010_update(S32 sim_index, S32 sim_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 highlight_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if((g_dm_data.s32CatId != MMI_CAT9010_ID) && (g_dm_data.s32CatId != MMI_CAT9010_SMALL_ID) && (g_dm_data.s32CatId != MMI_CAT9010_LIST_ID))
		return;

#if defined(__MMI_CAT9010_STYLE_2__)

	highlight_index = wgui_cat9010_get_highlight_index();
	g_cat9010_sim_state[sim_index] = sim_state;

	gdi_layer_lock_frame_buffer();
    wgui_cat9010_update_petal();

    if(sim_index == highlight_index)
	{
		if(g_cat9010_screen_type == SIM_SPACE)
		{
            wgui_cat9010_draw_space_info(sim_index);
            wgui_cat9010_draw_space_status_icon(sim_index);
        }
        if(g_cat9010_screen_type == SIM_SELECTOR)
        {
            wgui_cat9010_update_selector_text(sim_index);
		}
	}

	wgui_cat9010_draw_petal_signal_icon(sim_index);

	gdi_layer_unlock_frame_buffer();
	gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif
#if defined(__MMI_CAT9010_STYLE_3__)
	g_cat9010_sim_state[sim_index] = sim_state;
	show_fixed_list();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif
}

/* For status icon bar */
void wgui_cat9010_update_status_icon(S32 icon_id)
{
    S32 highlight_index;

    highlight_index = wgui_cat9010_get_highlight_index();
#if defined(__MMI_CAT9010_STYLE_3__)
	if(g_dm_data.s32CatId == MMI_CAT9010_LIST_ID)
	{
		MMI_BOOL is_status = MMI_FALSE;
		if(icon_id == STATUS_ICON_SIGNAL_STRENGTH)
		{
			is_status = MMI_TRUE;
		}
		else if(icon_id == STATUS_ICON_SLAVE_SIGNAL_STRENGTH)
		{
			is_status = MMI_TRUE;
		}
	#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
		else if(icon_id == STATUS_ICON_SIM3_SIGNAL_STRENGTH)
		{
			is_status = MMI_TRUE;
		}
	#endif
	#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4))
		else if(icon_id == STATUS_ICON_SIM4_SIGNAL_STRENGTH)
		{
			is_status = MMI_TRUE;
		}
	#endif
		if (is_status)
		{
			show_fixed_list();
			gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
			return;

		}
		if(g_cat9010_screen_type == SIM_SPACE)
		{
			MMI_BOOL is_sim1 = wgui_cat9010_check_status_icon_in_sim1(icon_id);
			MMI_BOOL is_sim2 = wgui_cat9010_check_status_icon_in_sim2(icon_id);
			MMI_BOOL is_sim3 = wgui_cat9010_check_status_icon_in_sim3(icon_id);
			MMI_BOOL is_sim4 = wgui_cat9010_check_status_icon_in_sim4(icon_id);
			if (is_sim1 || is_sim2 || is_sim3 || is_sim4)
		    {
				show_fixed_list();
				gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

			}
		}
		return;
	}
#endif
	if(g_dm_data.s32CatId != MMI_CAT9010_ID)
		return;

#if defined(__MMI_CAT9010_STYLE_2__)

	 if(g_cat9010_screen_type != SIM_SELECTOR)
	 {
    	if(wgui_cat9010_check_status_icon_in_sim1(icon_id))
    	{
            if(highlight_index == 0)
                wgui_cat9010_draw_space_status_icon(0);
  
    	}
    		//
    	else if(wgui_cat9010_check_status_icon_in_sim2(icon_id))
    	{
            if(highlight_index == 1)
                wgui_cat9010_draw_space_status_icon(1);

    	}
    	//
    	else if(wgui_cat9010_check_status_icon_in_sim3(icon_id))
    	{
            if(highlight_index == 2)
                wgui_cat9010_draw_space_status_icon(2);

    	}
    	//
    	else if(wgui_cat9010_check_status_icon_in_sim4(icon_id))
    	{
            if(highlight_index == 3)
                wgui_cat9010_draw_space_status_icon(3);
    	}
	 }
	//
	if(icon_id == STATUS_ICON_SIGNAL_STRENGTH)
	{
		wgui_cat9010_draw_petal_signal_icon(0);
	}
	else if(icon_id == STATUS_ICON_SLAVE_SIGNAL_STRENGTH)
	{
		wgui_cat9010_draw_petal_signal_icon(1);
	}
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
	else if(icon_id == STATUS_ICON_SIM3_SIGNAL_STRENGTH)
	{
		wgui_cat9010_draw_petal_signal_icon(2);
	}
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4))
	else if(icon_id == STATUS_ICON_SIM4_SIGNAL_STRENGTH)
	{
		wgui_cat9010_draw_petal_signal_icon(3);
	}
#endif
	else
	{
		return;
	}
#endif /* defined(__MMI_CAT9010_STYLE_2__) */

}

static void wgui_cat9010_exit(void)
{
	gui_scrolling_text_stop(&g_cat9010_scroll_text1);
	StopTimer(CAT9010_TIMER);
	wgui_softkey_set_is_in_popup(MMI_FALSE);
    reset_fixed_list();
    reset_pop_up_descriptions();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 
#ifdef __MMI_FTE_SUPPORT__
	if(g_cat9010_popup_bg_cache_buf.buf_ptr)
	 mmi_frm_scrmem_free(g_cat9010_popup_bg_cache_buf.buf_ptr);
#endif
	wgui_cat9010_highlight_handler = NULL;
}
#ifdef __MMI_CAT9010_STYLE_3__
static void wgui_cat9010_list_draw_signal_icon(S32 index, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 image_id = 0;

	U16 signal[] = {STATUS_ICON_SIGNAL_STRENGTH,
					STATUS_ICON_SLAVE_SIGNAL_STRENGTH
			#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
					,STATUS_ICON_SIM3_SIGNAL_STRENGTH
			#endif
			#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4))
					,STATUS_ICON_SIM4_SIGNAL_STRENGTH
			#endif
			};
	S32 frame_number;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	frame_number = wgui_status_icon_bar_get_icon_frame_number(signal[index]);
	image_id =  wgui_status_icon_bar_get_icon_image_id(signal[index]);
	gdi_image_draw_frames(x, y, (U8*)GetImage(image_id), frame_number); 
}
static void wgui_cat_9010_post_display_menuitem(void *item, void *common_item_data, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wgui_cat9010_text_struct sim_text;
	S32 sw, sh;
	S32 v_gap;
	S32 start_y;
	S32 icon_w, icon_h;
	S32 sim_w, sim_h;
	const S32 item_height = MMI_MULTIROW_MENUITEM_HEIGHT;
	S32 index;
	S32 icon_y;
	S32 icon_x;
	S32 text_w;
	S32 status_w, status_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	start_y = y;
    index = MMI_fixed_list_menu.current_displayed_item;
    if (index == -1)
    {
        index = wgui_title_get_menu_shortcut_number() - 1;
    }
	memset(&sim_text, 0, sizeof(sim_text));

	wgui_cat9010_get_text_func(index, 0, &sim_text);

	Get_StringWidthHeight((U8*) sim_text.text_0, &sw, &sh);
	
	v_gap = (item_height - 2*sh)/3;

	// draw simx  -- line 1
	gdi_image_get_dimension_id(IMG_GLOBAL_SIM1, &sim_w, &sim_h);
	gdi_image_draw_id(2, start_y + v_gap, IMG_GLOBAL_SIM1+index); 

	//draw text 1  -- line 1
	text_w = MMI_CONTENT_HEIGHT - 3 - sim_w - MMI_fixed_list_menu.vbar.width;
	gui_print_truncated_text(2+sim_w+1, start_y + v_gap, text_w, sim_text.text_0);

	// draw status icon  -- line 2
	gdi_image_get_dimension_id(IMG_SI_SIGNAL_STRENGTH, &icon_w, &icon_h);
	icon_y = start_y + v_gap + sh + ((item_height - sh - v_gap - icon_h)>>1);
	icon_x = 2+sim_w+1;

	// draw signal strength  -- line 2
	wgui_cat9010_list_draw_signal_icon(index, icon_x, icon_y);

	// draw status icon 2 -- line 2
	if(g_cat9010_screen_type == SIM_SPACE)
	{
		U8 count;
		U16 icon_id[8];
		U8 i = 0;
		S32 total_w = icon_w;
		count = wgui_cat9010_get_status_icon_image_id(index, icon_id);
		while(i < count)
		{
			gdi_image_get_dimension_id(icon_id[i], &status_w, &status_h);
			gdi_image_draw_id(icon_x + total_w + 1, icon_y, icon_id[i]);
			total_w += status_w + 1;
			i++;
		}
	}
}

static void wgui_cat9010_highlight_list_handler(S32 item_index)
{
	wgui_cat9010_set_highlight_index(item_index);
	if(wgui_cat9010_highlight_handler)
			wgui_cat9010_highlight_handler(item_index);
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_item_text(item_index);
    if (!wgui_title_get_menu_shortcut_handler_display())
    {
        gui_redraw_menu_shortcut();
    }

    MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
#if (UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}
#endif
/**********************************
 * title:   		[IN]  title string.
 * title_icon: 		[IN]  title icon.
 * left_sofktey: 	[IN]  left softkey string
 * left_softkey_icon:   [IN]  left sofktey icon
 * right_softkey:       [IN]  right softkey string
 * right_softkey_icon:  [IN]  right softkey icon
 * get_text_func:       [IN]  get two line text
 * sim_count:		[IN]  sim card count:  3 card , or 4 card
 * sim_state:		[IN]  0: grey the petal (like no-sim, no service, blocked, show one line text),  1: normal.
 * screen_type:		[IN]  SIM space (full screen) or SIM selector (small screen)
 * highlight_index:	[IN]  default highlgiht sim index
 * gui_buffer:		[IN]  history buffer
 ***************************************/
void wgui_cat9010_show(
	    	WCHAR* title,
        	PU8 title_icon,
        	WCHAR* left_softkey,
        	PU8 left_softkey_icon,
        	WCHAR* right_softkey,
        	PU8 right_softkey_icon,
			wgui_cat9010_get_text_func_type get_text_func,
			S32 sim_count,  
			U8 *sim_state, 
			wgui_cat9010_type_enum screen_type,
			U8  highlight_index,
 			U8* gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
	S32 i = 0;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT((sim_count == 3) || (sim_count == 4));
	g_cat9010_screen_type = screen_type;
	g_cat9010_sim_count = sim_count;
    MMI_message_string = title;
	wgui_cat9010_set_highlight_index(highlight_index);
	for(i = 0; i < sim_count; i++)
	{
		g_cat9010_sim_state[i] = sim_state[i];
        memset(&g_cat9010_loop_context[i], 0,  sizeof(wgui_cat9010_loop_id_struct));
	}
    dm_add_title(title, title_icon);
    dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);

	wgui_cat9010_get_text_func = get_text_func;
#ifdef __MMI_CAT9010_STYLE_3__
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();   /* in order to let APP to refresh quickly, we block this effect */
#endif
	wgui_fixed_list_create_multi_icontext_menu(
        0, 
        1, 
        sim_count, 
        0, 
        MMI_MULTIROW_MENUITEM_HEIGHT, 
        0,
        MMI_CAT9010_LIST_ID,
        gui_buffer);

    set_fixed_icontext_list_menuitems_post_display(wgui_cat_9010_post_display_menuitem);
	set_fixed_icontext_list_text_coordinates(0, 30, 0, 100, 36);
	wgui_fixed_list_override_multi_icontext_highlight_handler(wgui_cat9010_highlight_list_handler);
    wgui_fixed_list_begin_add_multi_icontext_one_item();
    for (i = 0; i < sim_count; i++)
    {
        U8* items[1];
        items[0] = (U8*)L"";
        wgui_fixed_list_add_multi_icontext_one_item(i, items, NULL, NULL);
    }
    wgui_fixed_list_end_add_multi_icontext_one_item();

	dm_data.s32CatId = MMI_CAT9010_LIST_ID;
	dm_data.s32flags = 0;

#else /* __MMI_CAT9010_STYLE_3__*/
    dm_register_category_controlled_callback(wgui_cat9010_draw_ctrl_area1);
    dm_register_category_controlled2_callback(wgui_cat9010_draw_ctrl_area2);
	SetKeyHandler(wgui_cat9010_left_arrow_key_handler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(wgui_cat9010_right_arrow_key_handler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(wgui_cat9010_up_arrow_key_handler, KEY_UP_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(wgui_cat9010_down_arrow_key_handler, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

#if defined(__MMI_TOUCH_SCREEN__)
	wgui_register_category_screen_control_area_pen_handlers(wgui_cat9010_pen_down_handler, MMI_PEN_EVENT_DOWN);
#endif
	if(g_cat9010_screen_type == SIM_SPACE)
	{
		dm_data.s32CatId = MMI_CAT9010_ID;
		dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND |DM_SCR_BG_NO_CACHE;
	}
	else
	{
		dm_data.s32CatId = MMI_CAT9010_SMALL_ID;
		dm_data.s32flags = DM_SET_NEW_LAYER_ACTIVE;
		wgui_softkey_set_is_in_popup(MMI_TRUE);
	}
    set_category9010_history(dm_data.s32CatId, gui_buffer);
	wgui_cat9010_set_right_highlight_index_by_state();
#endif /* __MMI_CAT9010_STYLE_3__*/
	if(g_cat9010_screen_type == SIM_SELECTOR)
	{
		SetKeyHandler(wgui_cat9010_enter_key_handler, KEY_ENTER, KEY_EVENT_UP);
		SetKeyHandler(wgui_cat9010_enter_key_handler, KEY_SEND, KEY_EVENT_UP);

		SetLeftSoftkeyFunction(wgui_cat9010_enter_key_handler, KEY_EVENT_UP);
	}
#ifdef __MMI_CAT9010_STYLE_2__
    dm_data.s32flags |= DM_NO_TITLE;
#endif

    ExitCategoryFunction = wgui_cat9010_exit;
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_setup_category_functions(dm_redraw_category_screen, get_category9010_history, get_category9010_history_size);
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}
#endif /*(defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))*/

