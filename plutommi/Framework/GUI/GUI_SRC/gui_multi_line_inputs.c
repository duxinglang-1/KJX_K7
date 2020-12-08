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
 *   gui_multi_line_inputs.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Editor layout
 *
 * Author:
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
//#include "mmi_frm_gprot.h"
//#include "WguiCategoryGprot.h"
//#include "lcd_sw_rnd.h"
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
#endif 

#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
#define MAX_EDITOR_DISP_LEN      60
#endif /* __MMI_INDIC_ALG__ */ 

#include "LangModuleGProt.h"


/* MTK Elvis for R2L characters */
#include "BIDIDEF.h"
#include "BIDIProt.h"

#include "gui_inputs_internal.h"
#include "IMERes.h"

#if defined (__MMI_ARSHAPING_ENGINE__)
#include "ArabicGProt.h"
#endif 

    #include "gui_data_types.h"
    #include "MMIDataType.h"
    #include "gui_inputs.h"
    #include "MMI_features.h"
    #include "string.h"
    #include "wgui_inputs.h"
    #include "gui_scrollbars.h"
    #include "CustThemesRes.h"
    #include "gdi_datatype.h"
    #include "gdi_include.h"
    #include "gui.h"
    #include "wgui.h"
    #include "gui_config.h"
    #include "kal_general_types.h"
    #include "wgui_categories_util.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "mmi_rp_app_uiframework_def.h"
    #include "wgui_inline_edit.h"
    #include "PixcomFontEngine.h"
    #include "FontRes.h"
    #include "lcd_sw_inc.h"
    #include "Unicodexdcl.h"
    #include "gui_themes.h"
    #include "mmi_frm_timer_gprot.h"
    
    #include "gdi_const.h"
    #include "CustDataRes.h"
    #include "ImeGprot.h"

#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__
/* Static variable */
static const color g_mmi_gui_input_format_w3c_text_background_color_table[] = 
{
    {169, 169, 169, 100},
    {139, 0, 0, 100},
    {255, 255, 0, 100},
    {0, 100, 0, 100},
    {0, 139, 139, 100},
    {0, 0, 139, 100},
    {139, 0, 139, 100},
    {128, 128, 128, 100},
    {255, 255, 255, 100},
    {255, 0, 0, 100},
    {255, 255, 224, 100},
    {144, 238, 144, 100},
    {224, 255, 255, 100},
    {173, 216, 230, 100},
    {255, 0, 255, 100},
    {0, 0, 0, 100}
};

/* 147 colors */
static const color g_mmi_gui_input_format_w3c_color_table[] = 
{
    {240, 248, 255, 100},
    {250, 235, 215, 100},
    {0, 255, 255, 100},
    {127, 255, 212, 100},
    {240, 255, 255, 100},
    {245, 245, 220, 100},
    {255, 228, 196, 100},
    {0, 0, 0, 100},
    {255, 235, 205, 100},
    {0, 0, 235, 100},   /* Avoid transparent color */
    {138, 43, 226, 100},
    {165, 42, 42, 100},
    {222, 184, 135, 100},
    {95, 158, 160, 100},
    {127, 255, 0, 100},
    {210, 105, 30, 100},
    {255, 127, 80, 100},
    {100, 149, 237, 100},
    {255, 248, 220, 100},
    {220, 20, 60, 100},
    {0, 255, 255, 100},
    {0, 0, 139, 100},
    {0, 139, 139, 100},
    {184, 134, 11, 100},
    {169, 169, 169, 100},
    {0, 100, 0, 100},
    {169, 169, 169, 100},
    {189, 183, 107, 100},
    {139, 0, 139, 100},
    {85, 107, 47, 100},
    {255, 140, 0, 100},
    {153, 50, 204, 100},
    {139, 0, 0, 100},
    {233, 150, 122, 100},
    {143, 188, 143, 100},
    {72, 61, 139, 100},
    {47, 79, 79, 100},
    {47, 79, 79, 100},
    {0, 206, 209, 100},
    {148, 0, 211, 100},
    {255, 20, 147, 100},
    {0, 191, 255, 100},
    {105, 105, 105, 100},
    {105, 105, 105, 100},
    {30, 144, 255, 100},
    {178, 34, 34, 100},
    {255, 250, 240, 100},
    {34, 139, 34, 100},
    {255, 0, 255, 100},
    {220, 220, 220, 100},
    {248, 248, 255, 100},
    {255, 215, 0, 100},
    {218, 165, 32, 100},
    {128, 128, 128, 100},
    {128, 128, 128, 100},
    {0, 128, 0, 100},
    {173, 255, 47, 100},
    {240, 255, 240, 100},
    {255, 105, 180, 100},
    {205, 92, 92, 100},
    {75, 0, 130, 100},
    {255, 255, 240, 100},
    {240, 230, 140, 100},
    {230, 230, 250, 100},
    {255, 240, 245, 100},
    {124, 252, 0, 100},
    {255, 250, 205, 100},
    {173, 216, 230, 100},
    {240, 128, 128, 100},
    {224, 255, 255, 100},
    {250, 250, 210, 100},
    {211, 211, 211, 100},
    {144, 238, 144, 100},
    {211, 211, 211, 100},
    {255, 182, 193, 100},
    {255, 160, 122, 100},
    {32, 178, 170, 100},
    {135, 206, 250, 100},
    {119, 136, 153, 100},
    {119, 136, 153, 100},
    {176, 196, 222, 100},
    {255, 255, 224, 100},
    {0, 255, 0, 100},
    {50, 205, 50, 100},
    {250, 240, 230, 100},
    {255, 0, 255, 100},
    {128, 0, 0, 100},
    {102, 205, 170, 100},
    {0, 0, 205, 100},
    {186, 85, 211, 100},
    {147, 112, 219, 100},
    {60, 179, 113, 100},
    {123, 104, 238, 100},
    {0, 250, 154, 100},
    {72, 209, 204, 100},
    {199, 21, 133, 100},
    {25, 25, 112, 100},
    {245, 255, 250, 100},
    {255, 228, 225, 100},
    {255, 228, 181, 100},
    {255, 222, 173, 100},
    {0, 0, 128, 100},
    {253, 245, 230, 100},
    {128, 128, 0, 100},
    {107, 142, 35, 100},
    {255, 165, 0, 100},
    {255, 69, 0, 100},
    {218, 112, 214, 100},
    {238, 232, 170, 100},
    {152, 251, 152, 100},
    {175, 238, 238, 100},
    {219, 112, 147, 100},
    {255, 239, 213, 100},
    {255, 218, 185, 100},
    {205, 133, 63, 100},
    {255, 192, 203, 100},
    {221, 160, 221, 100},
    {176, 224, 230, 100},
    {128, 0, 128, 100},
    {255, 0, 0, 100},
    {188, 143, 143, 100},
    {65, 105, 225, 100},
    {139, 69, 19, 100},
    {250, 128, 114, 100},
    {244, 164, 96, 100},
    {46, 139, 87, 100},
    {255, 245, 238, 100},
    {160, 82, 45, 100},
    {192, 192, 192, 100},
    {135, 206, 235, 100},
    {106, 90, 205, 100},
    {112, 128, 144, 100},
    {112, 128, 144, 100},
    {255, 250, 250, 100},
    {0, 255, 127, 100},
    {70, 130, 180, 100},
    {210, 180, 140, 100},
    {0, 128, 128, 100},
    {216, 191, 216, 100},
    {255, 99, 71, 100},
    {64, 224, 208, 100},
    {238, 130, 238, 100},
    {245, 222, 179, 100},
    {255, 255, 255, 100},
    {245, 245, 245, 100},
    {255, 255, 0, 100},
    {154, 205, 50, 100}
};

static const color g_mmi_gui_input_format_color_table[] = 
{
    {255, 0, 0, 100},
    {255, 255, 0, 100},
    {0, 255, 0, 100},
    {0, 255, 255, 100},
    {0, 0, 235, 100},   /* Avoid transparent color */
    {255, 0, 255, 100},
    {255, 255, 255, 100},
    {230, 230, 230, 100},
    {218, 218, 218, 100},
    {205, 205, 205, 100},
    {192, 192, 192, 100},
    {180, 180, 180, 100},
    {168, 168, 168, 100},
    {154, 154, 154, 100},
    {141, 141, 141, 100},
    {129, 129, 129, 100},
    {230, 0, 6, 100},
    {255, 237, 0, 100},
    {0, 152, 55, 100},
    {0, 166, 234, 100},
    {45, 29, 134, 100},
    {228, 0, 132, 100},
    {116, 116, 116, 100},
    {102, 102, 102, 100},
    {89, 89, 89, 100},
    {75, 75, 75, 100},
    {62, 62, 62, 100},
    {48, 48, 48, 100},
    {33, 33, 33, 100},
    {19, 19, 19, 100},
    {10, 10, 10, 100},
    {0, 0, 0, 100},
    {240, 148, 115, 100},
    {244, 173, 124, 100},
    {249, 200, 134, 100},
    {255, 245, 148, 100},
    {209, 224, 149, 100},
    {173, 210, 149, 100},
    {141, 199, 149, 100},
    {136, 203, 199, 100},
    {129, 207, 244, 100},
    {136, 169, 217, 100},
    {141, 147, 199, 100},
    {144, 127, 186, 100},
    {169, 134, 188, 100},
    {195, 141, 187, 100},
    {238, 155, 193, 100},
    {238, 151, 156, 100},
    {233, 98, 63, 100},
    {240, 136, 70, 100},
    {245, 175, 77, 100},
    {255, 240, 87, 100},
    {138, 208, 96, 100},
    {136, 192, 102, 100},
    {79, 176, 104, 100},
    {66, 138, 177, 100},
    {12, 188, 239, 100},
    {85, 138, 199, 100},
    {98, 109, 179, 100},
    {104, 81, 159, 100},
    {139, 85, 160, 100},
    {172, 91, 161, 100},
    {233, 102, 163, 100},
    {233, 101, 117, 100},
    {230, 0, 6, 100},
    {234, 89, 0, 100},
    {242, 143, 0, 100},
    {255, 237, 0, 100},
    {153, 192, 0, 100},
    {79, 172, 37, 100},
    {0, 152, 55, 100},
    {0, 158, 150, 100},
    {0, 166, 234, 100},
    {0, 104, 180, 100},
    {1, 70, 154, 100},
    {45, 29, 134, 100},
    {107, 18, 133, 100},
    {149, 0, 133, 100},
    {228, 0, 132, 100},
    {229, 0, 79, 100},
    {159, 0, 3, 100},
    {161, 60, 0, 100},
    {167, 98, 0, 100},
    {179, 162, 0, 100},
    {102, 132, 0, 100},
    {45, 118, 21, 100},
    {0, 105, 35, 100},
    {0, 109, 103, 100},
    {0, 113, 164, 100},
    {0, 69, 128, 100},
    {0, 43, 109, 100},
    {32, 4, 95, 100},
    {74, 0, 94, 100},
    {103, 0, 92, 100},
    {159, 0, 90, 100},
    {160, 0, 52, 100},
    {117, 0, 0, 100},
    {120, 43, 0, 100},
    {124, 70, 0, 100},
    {131, 118, 0, 100},
    {69, 96, 0, 100},
    {22, 86, 10, 100},
    {0, 76, 23, 100},
    {0, 79, 74, 100},
    {0, 82, 121, 100},
    {0, 47, 93, 100},
    {0, 23, 77, 100},
    {22, 0, 68, 100},
    {56, 0, 67, 100},
    {78, 0, 65, 100},
    {119, 0, 64, 100},
    {118, 0, 33, 100},
    {203, 187, 164, 100},
    {165, 141, 121, 100},
    {125, 99, 85, 100},
    {90, 65, 58, 100},
    {63, 41, 35, 100},
    {199, 163, 111, 100},
    {176, 130, 78, 100},
    {150, 98, 46, 100},
    {124, 74, 25, 100},
    {101, 51, 7, 100},
    {41, 73, 121, 100}
};

#endif/*__MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__*/
#define MAX_GUI_INPUT_COLOR         (sizeof(g_mmi_gui_input_format_color_table)/sizeof(color))
#define MAX_GUI_INPUT_W3C_COLOR     (sizeof(g_mmi_gui_input_format_w3c_color_table)/sizeof(color))
#define MAX_GUI_INPUT_W3C_TEXT_BG_COLOR      (sizeof(g_mmi_gui_input_format_w3c_text_background_color_table)/sizeof(color))

/* Static function declaration */
static U8 gui_get_multi_line_current_cluster(
            multi_line_input_box *b,
            multi_line_input_box_show_struct *bs,
            UI_character_type *current_character_p,
            U16 count);


#ifdef __MMI_BIDI_ALG__
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__
static void gui_apply_multi_line_marker_for_bidi_text(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__*/
#endif /* __MMI_BIDI_ALG__ */ 

#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__ 
static void gui_apply_multi_line_marker(
                multi_line_input_box *b,
                multi_line_input_box_show_struct *bs,
                UI_character_type current_character,
                U32 which_pass);

#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__*/

static UI_buffer_type gui_get_multi_line_current_char_offset(
                        multi_line_input_box_show_struct *bs,
                        S32 disp_count);
static void gui_draw_multi_line_current_line_highlight(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
static U8 gui_truncate_multi_line_content(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
static void gui_handle_multi_line_cursor(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
static void gui_draw_multi_line_text(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
static void gui_draw_multi_line_single_character(
                multi_line_input_box *b,
                multi_line_input_box_show_struct *bs,
                UI_character_type current_character);
static U32 gui_check_multi_line_character_highlight(multi_line_input_box *b, multi_line_input_box_show_struct *bs, U16 count);
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
static S32 gui_check_multi_line_cursor_validation_for_wcss(multi_line_input_box *b, multi_line_input_box_show_struct *bs, UI_buffer_type cursor_p);
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/
#ifdef __UI_ENHANCED_HILITE_IN_MULTILINE_EDITOR__
static void gui_set_multi_line_hilite_format(multi_line_input_box *b, multi_line_input_box_show_struct *bs, U16 hilite_idx);
#endif
/*****************************************************************************
 * FUNCTION
 *  gui_init_multi_line_show_struct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_init_multi_line_show_struct(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* maybe this init-zero can be  */
    memset(bs, 0, sizeof(multi_line_input_box_show_struct));

    bs->current_cursor_p = b->cursor_p;
    bs->previous_cursor_p = b->cursor_p;
    bs->selector_color = b->selector_color;
    bs->selected_text_color = b->selected_text_color;
    bs->flags = b->flags;
    bs->default_direction = BIDI_L;
    bs->cursor_line_found_flag = 0;
    bs->previous_line_height = 0;

#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
    {
        if (b->page_offset > 0 || b->jump_offset_from_app > 0)
            bs->adjust_view = 1;
    }
#endif

    if (b->hilite_list)
        bs->reserve_line_height_for_hilite = 1;
    else
        bs->reserve_line_height_for_hilite = 0;

    /* init richtext structure */
    bs->rich_text.default_color = bs->rich_text.curr_color = b->normal_text_color;
    /* USAT */
    bs->rich_text.default_text_bg_color = bs->rich_text.curr_text_bg_color = gui_richtext_default_text_bg_color;
    bs->rich_text.draw_text_bg_color = 0;
    if (bs->flags & UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY)
    {
        bs->rich_text.default_alignment = GUI_INPUT_ALIGN_CENTER;
    }
    else if (bs->flags & UI_MULTI_LINE_INPUT_BOX_RIGHT_JUSTIFY)
    {
        bs->rich_text.default_alignment = GUI_INPUT_ALIGN_RIGHT;
    }
    else
    {
        bs->rich_text.default_alignment = GUI_INPUT_ALIGN_LEFT;
    }
    bs->rich_text.curr_alignment = bs->rich_text.default_alignment;
    bs->rich_text.line_end_font = bs->rich_text.line_begin_font = bs->rich_text.curr_font = *b->text_font;
    bs->rich_text.line_end_border = bs->rich_text.line_begin_border = bs->rich_text.curr_border = 0;
    bs->rich_text.line_end_color = bs->rich_text.line_begin_color = bs->rich_text.curr_color;
    bs->rich_text.line_end_strikethrough = bs->rich_text.line_begin_strikethrough 
         = bs->rich_text.curr_strikethrough = 0;
    bs->rich_text.more_line_spacing = 0;
    bs->rich_text.line_separator = 0;

    bs->end_line = 0;

    /* to make the color is same as theme, remove this color correction */
/*
    if(bs->selected_text_color.r == bs->selector_color.r 
    && bs->selected_text_color.g == bs->selector_color.g 
    && bs->selected_text_color.b == bs->selector_color.b )
    {
        bs->selected_text_color.r ^= 0xff;
        bs->selected_text_color.g ^= 0xff;
        bs->selected_text_color.b ^= 0xff;
    }
*/
}


/*****************************************************************************
 * FUNCTION
 *  gui_init_multi_line_input_box_for_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_init_multi_line_input_box_for_show(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
    b->edit_height_displayed_lines = 0; /* ritesh */
    b->current_page_count = 0;
#endif 

    if (b->header_height > 0)
        b->header_gap = 1;
    else
        b->header_gap = 0;

    b->line_info->line_count = 0;
    b->line_info->b_to_end = MMI_FALSE;
    b->visible_start = -1;
    b->visible_start_ex = -1;

    b->highlight_end_y = 0;

    b->hilite_s_x = 0;
    b->hilite_s_y = 0;
    b->hilite_e_x = 0;
    b->hilite_e_y = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_prepare_multi_line_show_area
 * DESCRIPTION
 *  Set area info for background show.
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_prepare_multi_line_show_area(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#if !defined(__MMI_FTE_EDITOR_SCROLLBAR_STYLE__) && !defined(__MMI_EDITOR_FORCE_AUTO_SCROLLBAR__)
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW)
        && b->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__ /**/
        && !(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
#endif /*__UI_PAGING_IN_MULTILINE_EDITOR__*/ /**/           
        && bs->find_new_cursor_flag != FINDING_CURSOR)
    {
        gui_set_vertical_scrollbar_range(&b->vbar, 0);
        gui_set_vertical_scrollbar_scale(&b->vbar, 0);
    }
#endif

    bs->x1 = b->x;
    bs->y1 = b->y;
    bs->x2 = b->x + b->width - 1;   /* b->width contains the width of vbar */
    bs->y2 = bs->y1 + b->height - 1;
    bs->edit_width = b->edit_width;
    bs->edit_height = b->edit_height;
}

#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__/**/

/*****************************************************************************
 * FUNCTION
 *  gui_draw_multi_line_transparent_background_area
 * DESCRIPTION
 *  Draw transparent multi line background, currently used by inline readonly multiline
 * PARAMETERS
 *  b       [IN]          Editor instance     
 *  x1      [IN]          Background area top left x position
 *  y1      [IN]          Background area top left y position
 *  x2      [IN]          Background area bottom right x position
 *  y2      [IN]          Background area bottom right y position
 *  f       [IN]          filler
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_multi_line_transparent_background_area(multi_line_input_box *b, S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = b->trans_color;
    U32 alpha = ((U32)b->trans_alpha) * 255 / 100;
    gdi_handle act_layer, src_layer;
    U32 flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_active(&act_layer);
    gdi_get_alpha_blending_source_layer(&src_layer);

    if (f != NULL)
    {
        flags = f->flags;
        if ((flags & UI_FILLED_AREA_DOUBLE_BORDER) == UI_FILLED_AREA_DOUBLE_BORDER)
        {
            x1 += 2;
            x2 -= 2;
            y1 += 2;
            y2 -= 2;
        }
        else if (flags & UI_FILLED_AREA_SINGLE_BORDER)
        {
            x1 += 1;
            x2 -= 1;
            y1 += 1;
            y2 -= 1;
        }
    }
    if ((act_layer != src_layer) && src_layer)
    {
        gdi_effect_alpha_blending_rect(src_layer, x1, y1, x2, y2, alpha, c.r, c.g, c.b);
    }
    else if (act_layer)
    {
        gdi_effect_alpha_blending_rect(act_layer, x1, y1, x2, y2, 255, c.r, c.g, c.b);
    }
}
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__*/


/*****************************************************************************
 * FUNCTION
 *  gui_draw_multi_line_background_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_multi_line_background_area(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_filled_area f;
    S32 l_height = 0, l_clip;
    gui_inputs_bg_mem_image_struct *bg_image = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bs->l_clip = l_clip = 0;

    /* Pixtel - Gurinder 2/4/6 - Use Auto Scrollbar if current multi line box is Inscreen */
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    if (MMI_multi_line_inputbox_present)
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR;
        b->flags |= UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU;
        bs->l_clip = l_clip = bs->y2 - (MMI_content_height + MMI_content_y - 1);

        if (l_clip < 0)
        {
            l_clip = 0;
        }
    }
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 

    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))    /* If not disable draw then do it.. */
    {
        if (bs->flags & UI_MULTI_LINE_INPUT_BOX_STATE_FOCUSSED)
        {
            f = *b->focussed_filler;
            bs->rich_text.default_color = bs->rich_text.curr_color = b->focussed_text_color;
            bg_image = b->focussed_mem_bg_image;
        }
        else if (bs->flags & UI_MULTI_LINE_INPUT_BOX_STATE_DISABLED)
        {
            f = *b->disabled_filler;
            bs->rich_text.default_color = bs->rich_text.curr_color = b->disabled_text_color;
        }
        else
        {
            f = *b->normal_filler;
            bs->rich_text.default_color = bs->rich_text.curr_color = b->normal_text_color;
            bg_image = b->normal_mem_bg_image;
        }

        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SET_BG_COLOR)
        {
            f.c = b->default_bg_color;
        }

	// baiwenlin 20131122  
	f.c = gui_color(0,0,0);
	
    #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
        if (MMI_multi_line_inputbox_present == 1)
        {
            if(INFORMATION_BAR_HEIGHT > 0)
            {
                /* Inline Multiline Edit Infobar Height Change. - Gurinder - 12/5/2004 */
                l_height = INFORMATION_BAR_HEIGHT + 2;
            }
            /* Gurinder 7/14/2004 - Inscreen Multiline Title Enable/Disable */
        #if(!INSCREEN_MUTLILINE_TITLE_ENABLE)
            if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
            {
                l_height = 0;
            }
        #endif /* (!INSCREEN_MUTLILINE_TITLE_ENABLE) */ 
        }
    #endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 

        gui_push_clip();

        if (bs->flags & UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING)
        {
            gui_set_clip_preset(b->x, bs->y1 - l_height, bs->x2 + 2, bs->y2 + 2 - l_clip);
        }
        else
        {
            /* MTK Terry instead y2+1-l_clip with y2-l_clip for overlap soft key area */
            gui_set_clip(b->x, bs->y1 - l_height, bs->x2 + 2, bs->y2 - l_clip);
        }

		if (b->hide_callback != NULL)
		{
			b->hide_callback(b->x, b->y, b->x + b->width - 1, b->y +b->height - 1);
			return;
		}

        if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND))  /* if not disable background then do .. */
        {
            if (b->ext_flags &
                (GUI_MULTI_LINE_INPUT_BOX_NONE_BORDER
                 | GUI_MULTI_LINE_INPUT_BOX_SINGLE_BORDER | GUI_MULTI_LINE_INPUT_BOX_DOUBLE_BORDER))
            {
                /* If user set these flag, use the user setting instead of the theme setting */
                f.flags &= ~(UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_DOUBLE_BORDER);
                if (!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_NONE_BORDER))
                {
                    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SINGLE_BORDER)
                    {
                        f.flags |= UI_FILLED_AREA_SINGLE_BORDER;
                    }
                    else if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_DOUBLE_BORDER)
                    {
                        f.flags |= UI_FILLED_AREA_DOUBLE_BORDER;
                    }
                }

            }

            if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))       /* if not include info_area then do .. */
            {
                /* Draw standard background filler */
                /* 070405 Calvin Start */
                if (mmi_fe_get_r2l_state())
                {
                    if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) &&
                        (bs->flags & UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND))
                    {
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__/**/                       
                        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SEMITRANSPARENT_BACKGROUND)
                        {
                            gui_draw_multi_line_transparent_background_area(
                                b,
                                b->x,
                                bs->y1 - l_height,
                                bs->x2,
                                bs->y2,
                                &f);
                        }
                        else
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__*/  
                        {
                            gdi_draw_solid_rect(
                                b->x,
                                bs->y1 - l_height,
                                bs->x2 /* +b->vbar.width */ ,
                                bs->y2,
                                GDI_COLOR_TRANSPARENT);
                        }                        
                    }
                    else
                    {
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__/**/                     
                        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SEMITRANSPARENT_BACKGROUND)
                        {
                        #ifdef __MMI_FTE_SUPPORT__
                            if (MMI_multi_line_inputbox_present)
                            {
                                gdi_image_draw_resized_id(
                                    bs->x1,
                                    bs->y1 - l_height,
                                    bs->x2 - bs->x1 + 1,
                                    bs->y2 - bs->y1 + l_height + 1,
                                    IMG_INLINE_DISPLAY_ONLY_NORMAL_BG);
                            }
                            else
                        #endif
                            {
                                gui_draw_multi_line_transparent_background_area(
                                    b,
                                    b->x,
                                    bs->y1 - l_height,
                                    bs->x2,
                                    bs->y2,
                                    &f);
                            }
                        }
                        else
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__*/  
                        {
                        #ifdef __MMI_FTE_SUPPORT__
                            if (MMI_multi_line_inputbox_present)
                            {
                                gdi_image_draw_resized_id(
                                    bs->x1,
                                    bs->y1 - l_height,
                                    bs->x2 - bs->x1 + 1,
                                    bs->y2 - bs->y1 + l_height + 1,
                                    IMG_INLINE_DISPLAY_ONLY_HIGHLIGHT_BG);
                            }
                            else
                        #endif
                            if (bg_image)
                            {
                                /* image background */
                                /* from memmory */
                                gdi_image_draw_mem_blend2layers(
                                    bs->x1,
                                    bs->y1 - l_height,
                                    bg_image->data,
                                    bg_image->type,
                                    bg_image->len);
                            }
                            else if (f.b != NULL)
                            {
                                /* from resource */
                                gdi_image_draw_resized_blend2layers(
                                    bs->x1,
                                    bs->y1 - l_height,
                                    bs->x2 - bs->x1 + 1,
                                    bs->y2 - bs->y1 + l_height + 1,
                                    f.b);
                            }
                            else
                            {
                                gui_draw_filled_area(b->x, bs->y1 - l_height, bs->x2, bs->y2, &f);
                            }
                        }
                    }
                }
                else
                {
                    if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) &&
                        (bs->flags & UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND))
                    {
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__/**/                        
                        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SEMITRANSPARENT_BACKGROUND)
                        {
                            gui_draw_multi_line_transparent_background_area(
                                b,
                                bs->x1,
                                bs->y1 - l_height,
                                bs->x2,
                                bs->y2,
                                &f);
                        }
                        else
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__*/                            
                        {
                            gdi_draw_solid_rect(bs->x1, bs->y1 - l_height, bs->x2, bs->y2, GDI_COLOR_TRANSPARENT);
                        }
                    }
                    else
                    {
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__/**/                        
                        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SEMITRANSPARENT_BACKGROUND)
                        {
                        #ifdef __MMI_FTE_SUPPORT__
                            if (MMI_multi_line_inputbox_present)
                            {
                                gdi_image_draw_resized_id(
                                    bs->x1,
                                    bs->y1 - l_height,
                                    bs->x2 - bs->x1 + 1,
                                    bs->y2 - bs->y1 + l_height + 1,
                                    IMG_INLINE_DISPLAY_ONLY_NORMAL_BG);
                            }
                            else
                        #endif
                            {
                                gui_draw_multi_line_transparent_background_area(
                                    b,
                                    bs->x1,
                                    bs->y1 - l_height,
                                    bs->x2,
                                    bs->y2,
                                    &f);
                            }
                        }
                        else
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__*/                        
                        {
                        #ifdef __MMI_FTE_SUPPORT__
                            if (MMI_multi_line_inputbox_present)
                            {
                                gdi_image_draw_resized_id(
                                    bs->x1,
                                    bs->y1 - l_height,
                                    bs->x2 - bs->x1 + 1,
                                    bs->y2 - bs->y1 + l_height + 1,
                                    IMG_INLINE_DISPLAY_ONLY_HIGHLIGHT_BG);
                            }
                            else
                        #endif  
                            if (bg_image)
                            {
                                /* image background */
                                /* from memmory */
                                gdi_image_draw_mem_blend2layers(
                                    bs->x1,
                                    bs->y1 - l_height,
                                    bg_image->data,
                                    bg_image->type,
                                    bg_image->len);
                            }
                            else if (f.b != NULL)
                            {
                                gdi_image_draw_resized_blend2layers(
                                    bs->x1,
                                    bs->y1 - l_height,
                                    bs->x2 - bs->x1 + 1,
                                    bs->y2 - bs->y1 + l_height + 1,
                                    f.b);
                            }
                            else
                            {                             
                                gui_draw_filled_area(bs->x1, bs->y1 - l_height, bs->x2, bs->y2, &f);
                            }
                        }
                    }
                }
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_BOX_DISPLAY_BORDER__
                if(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_DISPLAY_BORDER)
                {
                    f.c= gui_color(255, 255, 255);
                    gui_draw_filled_area(bs->x1, bs->y1 - l_height, bs->x2, bs->y2, &f);
                    f.c= gui_color(0, 0, 0);
                    gui_draw_filled_area(bs->x1+MULTILINE_BOX_BORDER_WIDTH, 
                                         bs->y1+MULTILINE_BOX_BORDER_WIDTH - l_height,
                                         bs->x2-MULTILINE_BOX_BORDER_WIDTH, 
                                         bs->y2-MULTILINE_BOX_BORDER_WIDTH, &f); 
                }
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_BOX_DISPLAY_BORDER__*/
                /* 070405 Calvin End */

                /*
                 * Draw b->text_filler for text area only.
                 * (typically when b->header_height or b->footer_callback is non-zero)
                 */
#ifdef __MMI_IMPS__      //slim_slim_2           
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__/**/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_IMPS__ */                  
            }
            else    /* if including info_area then do .. */
            {
                gui_set_clip(b->x, bs->y1 - wgui_inputbox_information_bar_height - l_height, bs->x2, bs->y2 - l_clip);
                f.flags = UI_FILLED_AREA_TYPE_BITMAP;
              //  f.b = get_image(WGUI_VOLUME_LEVEL1);    /* test */

                /* 070405 Calvin Start */
                if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) &&
                    (bs->flags & UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND))
                {
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__/**/
                    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SEMITRANSPARENT_BACKGROUND)
                    {
                        gui_draw_multi_line_transparent_background_area(
                            b,
                            b->x,
                            bs->y1 - wgui_inputbox_information_bar_height - l_height,
                            bs->x2,
                            bs->y2,
                            &f);
                    }
                    else
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__*/
                    {
                        gdi_draw_solid_rect(
                            b->x,
                            bs->y1 - wgui_inputbox_information_bar_height - l_height,
                            bs->x2,
                            bs->y2,
                            GDI_COLOR_TRANSPARENT);
                    }
                }
                else
                {
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__/**/
                    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SEMITRANSPARENT_BACKGROUND)
                    {
                        gui_draw_multi_line_transparent_background_area(
                            b,
                            b->x,
                            bs->y1 - wgui_inputbox_information_bar_height - l_height,
                            bs->x2,
                            bs->y2,
                            &f);
                    }
                    else
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_SEMITRANSPARENT_BACKGROUND__*/
                    {
                        gui_draw_filled_area(
                            b->x,
                            bs->y1 - wgui_inputbox_information_bar_height - l_height,
                            bs->x2,
                            bs->y2,
                            &f);
                    }
                }
                /* 070405 Calvin End */

                if (mmi_fe_get_r2l_state())
                {
                    gui_draw_rectangle(
                        b->x,
                        bs->y1 - l_height,
                        bs->x2 /* +b->vbar.width */ ,
                        bs->y2,
                        b->boundary_color);
                }
                else
                {
                    gui_draw_rectangle(bs->x1, bs->y1 - l_height, bs->x2, bs->y2, b->boundary_color);
                }

                if (bs->flags & UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING)
                {
                    gui_set_clip_preset(bs->x1, bs->y1 - l_height, bs->x2 + 2, bs->y2 + 2 - l_clip);
                }
                else
                {
                    gui_set_clip(bs->x1, bs->y1 - l_height, bs->x2 + 2, bs->y2 + 2 - l_clip);
                }
            }
        }

    #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
        if (MMI_multi_line_inputbox_present)
        {
            /* Gurinder 6/5/2004 - Show Information Bar / Caption String */
            if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
            {
                //Show Information Bar
                //START TARUN PMT 20040927  ADDED : Check the flag before redrawing the info bar
                if (wgui_inputbox_information_flag)
                {
					gdi_layer_lock_frame_buffer();
                    wgui_redraw_input_information_bar();
					gdi_layer_unlock_frame_buffer();
                }
                /* END TARUN PMT 20040927 */
            }
        #if(INSCREEN_MUTLILINE_TITLE_ENABLE)
            /* Gurinder 7/14/2004 - Inscreen Multiline Title Enable/Disable */
            else
            {
                /* Show Signature Text.... */
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
                gui_draw_inscreen_multi_line_input_box_title(bs->x1, bs->y1 - l_height + 1, bs->x2 - 2, bs->y1 - 1);
#endif
            }
        #endif /* (INSCREEN_MUTLILINE_TITLE_ENABLE) */ 
        }
    #endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
    }
}

#ifdef __MMI_BIDI_ALG__


/*****************************************************************************
 * FUNCTION
 *  gui_get_multi_line_text_language_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_get_multi_line_text_language_type(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 iCount;
    U8 lastest_char_type;
    UI_character_type dummy_c;
    U16 strongCharType = 0xFFFF;
    UI_buffer_type text_p;
    const sIMEModeDetails *mode_details_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Add pretection for Ebook, there're some scenario the text is NULL and still call show funtion */
    if (b->text == NULL)
    {
        return;
    }

    if ((b->text_length / ENCODING_LENGTH) - 1 != 0)
    {
        for (iCount = 0; iCount < (U32) ((b->text_length >> 1) - 1); iCount++)
        {
            text_p = (UI_buffer_type)(b->text + iCount * ENCODING_LENGTH);
            UI_STRING_GET_NEXT_CHARACTER(text_p, dummy_c);
                

            if ((bs->flags & UI_MULTI_LINE_INPUT_BOX_RICHTEXT) && GUI_INPUT_IS_MARKER(dummy_c))
                continue;

            bidi_get_char_type((U8*) (b->text + iCount * ENCODING_LENGTH), (U8*) & lastest_char_type);
            if ((lastest_char_type == AL 
                || lastest_char_type == BIDI_L 
                || lastest_char_type == BIDI_R 
                || lastest_char_type == AN)
                && strongCharType == 0xFFFF)
            {
                strongCharType = lastest_char_type;
            }
            
            if ((lastest_char_type == AL) || (lastest_char_type == AN) || (lastest_char_type == BIDI_R))
            {
                bs->arabic_char_flag = MMI_TRUE;
                break;
            }
        }

        bidi_get_char_type(b->text, (U8*) & bs->default_direction);
    #ifdef GUI_INPUTBOX_ALIGNMENT_WHEN_EXIST_R2L_CHAR
        if (bs->arabic_char_flag)
    #else 
        if (strongCharType == AL || strongCharType == BIDI_R || strongCharType == AN)
    #endif 
        {
            bs->default_direction = BIDI_R;
        }
        else
        {
            bs->default_direction = BIDI_L;

            if (strongCharType == 0xFFFF)
            {
                if (mmi_imc_is_connected())
                {
                    mode_details_ptr = mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode());
                    
                    if (mode_details_ptr)
                    {
                        if (mode_details_ptr->lang_id == IME_WRITING_LANG_AR
                            || mode_details_ptr->lang_id == IME_WRITING_LANG_UR
                            || mode_details_ptr->lang_id == IME_WRITING_LANG_PS
                            || mode_details_ptr->lang_id == IME_WRITING_LANG_HE)
                        {
                            bs->default_direction = BIDI_R;
                        }
                    }
                }
            }
        }
    }
    else
    {
        if (mmi_imc_is_connected())
        {
            mode_details_ptr = mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode());
            
            if (mode_details_ptr)
            {
                if (mode_details_ptr->lang_id == IME_WRITING_LANG_AR
                     || mode_details_ptr->lang_id == IME_WRITING_LANG_UR
                     || mode_details_ptr->lang_id == IME_WRITING_LANG_PS
                     || mode_details_ptr->lang_id == IME_WRITING_LANG_HE)
                {
                    bs->default_direction = BIDI_R;
                }
            }
        }
    }
}
#endif /* __MMI_BIDI_ALG__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_text_area_range
 * DESCRIPTION
 *  Set area info for text. Deduct scrollbar's width if there is a scrollbar. 
 *  Deduct the border.
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multi_line_text_area_range(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* hjf recalculate the x boundary */
    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR))
    {
        if (!mmi_fe_get_r2l_state())
        {
#ifndef __MMI_FTE_EDITOR_SCROLLBAR_STYLE__
            if (bs->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR)
            {
                if (b->vbar.scale != 0
                    && (b->vbar.scale < b->vbar.range))
                {
                    bs->x2 -= b->vbar.width;
                }
                else if (b->pre_scrollbar_state && b->pre_height == b->height)
                {
                    bs->x2 -= b->vbar.width;
                    b->pre_scrollbar_state = 0;
                }
            }
            else		
#endif
            bs->x2 -= b->vbar.width + 1;
        }
        else 
        {
            if (b->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR)
            {
#if defined(__MMI_FTE_EDITOR_SCROLLBAR_STYLE__)
                bs->x1 = b->x + b->vbar.width + 1;
#elif defined(__MMI_EDITOR_FORCE_AUTO_SCROLLBAR__)
                if (((b->vbar.scale < b->vbar.range) && !(b->icon_callback)) ||
		    ((b->vbar.scale < b->vbar.range + 2) && (b->icon_callback)))
                {
                    bs->x1 = b->x + b->vbar.width + 1;
                }            
#else
                if ((b->vbar.scale != 0) && 
		    (((b->vbar.scale < b->vbar.range) && !(b->icon_callback)) ||
		    ((b->vbar.scale < b->vbar.range + 2) && (b->icon_callback))))
                {
                    bs->x1 = b->x + b->vbar.width + 1;
                }            
#endif /* __MMI_FTE_EDITOR_SCROLLBAR_STYLE__*/
            }
            else
            {
                bs->x1 = b->x + b->vbar.width + 1;
            }
        }
    }

    bs->x1 += b->left_width;
    bs->x2 -= (b->text_x2_gap_width + b->right_width);

    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_FIXED_TEXT_AREA)
    {
        bs->backup_x1 = bs->x1;
        bs->backup_x2 = bs->x2;
        bs->x1 += b->fixed_text_start_x;
        bs->x2 = bs->x1 + b->fixed_text_width;
    }

    bs->edit_width = (bs->x2 - bs->x1 - b->text_x);

    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SINGLE_BORDER)
    {
        bs->edit_width -= 2;
    }
    else if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_DOUBLE_BORDER)
    {
        bs->edit_width -= 4;
    }

    b->edit_width = bs->edit_width;
}


/*****************************************************************************
 * FUNCTION
 *  gui_setup_multi_line_text_clip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_setup_multi_line_text_clip(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_filled_area f;
    S32 clip_x1, clip_y1, clip_x2, clip_y2, l_clip = bs->l_clip;
    U32 chk_flags;
    S32 top_down_margin = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    top_down_margin = b->margin.down_margin;
   
    if (bs->flags & UI_MULTI_LINE_INPUT_BOX_STATE_FOCUSSED)
    {
        f = *b->focussed_filler;
    }
    else if (bs->flags & UI_MULTI_LINE_INPUT_BOX_STATE_DISABLED)
    {
        f = *b->disabled_filler;
    }
    else
    {
        f = *b->normal_filler;
    }
    
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SET_BG_COLOR)
    {
        f.c = b->default_bg_color;
    }
    
    if (b->ext_flags &
        (GUI_MULTI_LINE_INPUT_BOX_NONE_BORDER
        | GUI_MULTI_LINE_INPUT_BOX_SINGLE_BORDER | GUI_MULTI_LINE_INPUT_BOX_DOUBLE_BORDER))
    {
        /* If user set these flag, use the user setting instead of the theme setting */
        f.flags &= ~(UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_DOUBLE_BORDER);
        if (!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_NONE_BORDER))
        {
            if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SINGLE_BORDER)
            {
                f.flags |= UI_FILLED_AREA_SINGLE_BORDER;
            }
            else if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_DOUBLE_BORDER)
            {
                f.flags |= UI_FILLED_AREA_DOUBLE_BORDER;
            }
        }
    }
    chk_flags = f.flags;
    
    /* Clipping is poped after the editor has finished drawing */
    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))    /* if not disable draw then do ... */
    {
        gui_push_text_clip();
        gui_push_clip();
    }
    
    if ((chk_flags & UI_FILLED_AREA_DOUBLE_BORDER) == UI_FILLED_AREA_DOUBLE_BORDER)
    {
        bs->border_y = 2;
        clip_x1 = bs->x1 + 2;
        clip_y1 = bs->y1 + 2;
        clip_x2 = bs->x2 - 2;
        clip_y2 = bs->y2 - ((l_clip > 2) ? l_clip : 2) - top_down_margin;
    }
    else if (chk_flags & UI_FILLED_AREA_BORDER)
    {
        bs->border_y = 1;
        clip_x1 = bs->x1 + 1;
        clip_y1 = bs->y1 + 1;
        clip_x2 = bs->x2 - 1;
        clip_y2 = bs->y2 - ((l_clip > 1) ? l_clip : 1) - top_down_margin;
    }
    else
    {
        bs->border_y = 0;
        clip_x1 = bs->x1;
        clip_y1 = bs->y1;
        clip_x2 = bs->x2;
        clip_y2 = bs->y2 - l_clip - top_down_margin;
    }
    
    clip_y1 += b->text_y;
    
    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))    /* if not disable draw then do ... */
    {
        if (bs->flags & UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING)
        {
            gui_set_text_clip_preset(clip_x1, clip_y1, clip_x2, clip_y2);
            gui_set_clip_preset(clip_x1, clip_y1, clip_x2, clip_y2);
        }
        else
        {
            gui_set_text_clip(clip_x1, clip_y1, clip_x2, clip_y2);
            gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
        }
    }
    
    bs->edit_height = b->edit_height = clip_y2 - clip_y1 + 1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_default_font
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multi_line_default_font(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
    {
        switch (b->font_style)
        {
            case FONT_DEFAULT:
                bs->rich_text.curr_font.italic = bs->rich_text.curr_font.bold = 0;
                break;
            case FONT_BOLD:
                bs->rich_text.curr_font.bold = 1;
                bs->rich_text.curr_font.italic = 0;
                break;
            case FONT_ITALIC:
                bs->rich_text.curr_font.italic = 1;
                bs->rich_text.curr_font.bold = 0;
                break;
        }
        bs->rich_text.line_end_font = bs->rich_text.line_begin_font = bs->rich_text.curr_font;
    }
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 

    gui_set_font(&(bs->rich_text.curr_font));   /* set text font */

}


/*****************************************************************************
 * FUNCTION
 *  gui_adjust_multi_line_cursor_for_language
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_adjust_multi_line_cursor_for_language(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type temp_cursor_p = b->cursor_p;
    mmi_lm_cluster_info cur_cluster;
    UI_buffer_type pre_cluster_p;
    UI_character_type temp_char;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bs->find_new_cursor_flag != NORMAL_CURSOR
        || !bs->cursor_line_found_flag || (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
       /* || g_editor_line.cursor_line_flag == 0 */)
    {
        /* the current cursor_p is invalid */
        return;
    }
 
    UI_STRING_GET_NEXT_CHARACTER(temp_cursor_p, temp_char);
    
    if (temp_char == 0 
        || b->cursor_p == b->text
        || b->cursor_p == b->line_before_cursor_line_p)
        return;
    
    mmi_lm_get_prev_cluster(b->line_before_cursor_line_p, b->text + b->text_length - 2, b->cursor_p, MMI_TRUE, &cur_cluster);
    pre_cluster_p = cur_cluster.data_ptr;
    mmi_lm_get_next_cluster(b->line_before_cursor_line_p, b->text + b->text_length - 2, pre_cluster_p, MMI_TRUE, &cur_cluster);
    b->cursor_p = cur_cluster.data_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  gui_prepare_multi_line_new_line_loop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_prepare_multi_line_new_line_loop(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&(bs->rich_text.curr_font));

    /* Restore the text_gap and line spacing */
    bs->rich_text.more_line_spacing = 0;
    bs->rich_text.line_separator = 0;

    bs->previous_line_height = g_editor_line.line_height;
    bs->draw_separator = FALSE;

    /*
     * Backup the font at the beginning of line
     * Alignment is setup in the first pass only, and color is set in the second pass only.
     */
    bs->rich_text.curr_font = bs->rich_text.line_begin_font = bs->rich_text.line_end_font;
    bs->rich_text.curr_border = bs->rich_text.line_begin_border = bs->rich_text.line_end_border;
    bs->rich_text.curr_strikethrough = bs->rich_text.line_begin_strikethrough = bs->rich_text.line_end_strikethrough;
    bs->rich_text.curr_color = bs->rich_text.line_begin_color = bs->rich_text.line_end_color;

    g_editor_line.bidi_done_flag = 0;
    g_editor_line.cursor_line_flag = 0;
    g_editor_line.override_flag = 0;
    g_editor_line.marker_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_end_multi_line_new_line_loop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_end_multi_line_new_line_loop(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y;
    static const U8 dotted_line_bitvalues[] = {1, 1, 0, 0};
    static const U8 line_separator_value[] = {1, 1};
    S32 gap = 0;
    S32 yoffset = 12; /* separator-line space */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw the seperator line */
    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) &&
        (bs->flags & UI_MULTI_LINE_INPUT_BOX_DRAW_SEPARATOR) && bs->draw_separator)
    {
        if (!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
        {
        #ifdef __MMI_BIDI_ALG__
            if (bs->arabic_char_flag)
            {
                y = bs->yty + g_editor_line.line_height - 1;
            }
            else
                y = bs->yty + g_editor_line.line_height;
        #else /* __MMI_BIDI_ALG__ */ 
            y = bs->yty + g_editor_line.line_height;
        #endif /* __MMI_BIDI_ALG__ */ 

            gdi_draw_line_style(
                bs->xx + 5,
                y,
                bs->xx + b->edit_width - 1 - 5,
                y,
                gdi_act_color_from_rgb(255, 112, 125, 240),
                sizeof(dotted_line_bitvalues),
                dotted_line_bitvalues);
        }
    }

#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__
    /* for marker separator */
    if (bs->rich_text.line_separator)
    {
        if (!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
        {   
            if (bs->yty + g_editor_line.line_height - yoffset < b->y + b->height && bs->yty + g_editor_line.line_height - yoffset > b->y)
            {   
                /* separator line is visible */
                /* g_editor_line.height already include 2 * yoffset, so line y = bs->yty + g_editor_line.line_height - yoffset */
                gdi_draw_line_style(
                    (S32) b->x + gap,
                    (S32) bs->yty + g_editor_line.line_height - yoffset,
                    (S32) b->x + b->width - 1 - gap,
                    (S32) bs->yty + g_editor_line.line_height - yoffset,
                    (gdi_color) gdi_act_color_from_rgb(255, 0xb5, 0xb5, 0xb5),
                    sizeof(line_separator_value),
                    line_separator_value);
            }
        }
    }
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__*/

    bs->ty += g_editor_line.line_height;

    if (bs->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE
        && g_editor_line.line_unit_count == 0
        && bs->end_line
        && bs->line_counter == 0)
        bs->ty -= g_editor_line.line_height;

    if (g_editor_line.line_height > b->max_line_height)
    {
        b->max_line_height = g_editor_line.line_height;
    }

    bs->line_counter++;
    bs->current_text_p = g_editor_line.line_start_p + g_editor_line.line_char_count * ENCODING_LENGTH;

    /* draw underline */
    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) 
        && (bs->flags & UI_MULTI_LINE_INPUT_BOX_DRAW_UNDERLINE)
        &&!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
    {
        S32 line_x, line_x2, line_y;
        gdi_color line_color = gdi_act_color_from_rgb(255, 
                    current_MMI_theme->inputbox_base_line_color->r, current_MMI_theme->inputbox_base_line_color->g, current_MMI_theme->inputbox_base_line_color->b);
       
#ifdef __MMI_FTE_EDITOR_SCROLLBAR_STYLE__
        gui_push_clip();
        if (b->normal_filler->flags & UI_FILLED_AREA_SINGLE_BORDER)
            gui_set_clip(b->x+1, b->y, b->x + b->width - 2, b->y + b->height - 1);
        else
            gui_set_clip(b->x, b->y, b->x + b->width - 1, b->y + b->height - 1);
#endif
        line_x = b->x;
        line_x2 = b->x + b->width - 1;
        line_y = bs->yty + g_editor_line.line_height - 1;
        gdi_draw_line(line_x, line_y, line_x2, line_y, line_color);
#ifdef __MMI_FTE_EDITOR_SCROLLBAR_STYLE__
        gui_pop_clip();
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_find_multi_line_one_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_find_multi_line_one_line(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 break_highlight = 0;
    U16 count = 0, icon_count;
    U16 break_line_count = 0, break_unit_count = 0, break_line_width = 0, break_ascent = 0, break_dscent = 0, break_line_height = 0;
    S32 width, height, temp_width, temp_height, former_width = 0, disp_width = 0;
    S32 upper_addition, bottom_addition;
    UI_character_type current_character = 0, next_character = 0;
    UI_buffer_type temp_text_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    width = 0;
    height = 0;
    g_editor_line.line_width = 0;
    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_ONLY_SHOW_FIRST_LINE))
    {
#ifdef  __MMI_EDITOR_MULTILINE_SUPPORT_96_64_STYLE__
        g_editor_line.line_height = gui_inputs_get_char_info_for_all_lang(b->text_font->size, &g_editor_line.line_ascent, &g_editor_line.line_dscent);
        upper_addition = 0; 
        bottom_addition = 0;   
#else /*__MMI_EDITOR_MULTILINE_SUPPORT_96_64_STYLE__*/
        g_editor_line.line_height = gui_inputs_get_char_info_for_all_lang(b->text_font->size, &g_editor_line.line_ascent, &g_editor_line.line_dscent);
        g_editor_line.line_height += EDITOR_LINE_ADDITION_PIXTEL;
        g_editor_line.line_ascent += EDITOR_LINE_UPPER_PIXTEL;
        g_editor_line.line_dscent += EDITOR_LINE_LOWER_PIXTEL;
        upper_addition = EDITOR_LINE_UPPER_PIXTEL;
        bottom_addition = EDITOR_LINE_LOWER_PIXTEL;

#endif/*__MMI_EDITOR_MULTILINE_SUPPORT_96_64_STYLE__*/
        if(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_DIALER_STYLE)
        {
            g_editor_line.line_height = gui_get_string_height((UI_string_type) L"1234567890*+pw");
            upper_addition = 0; 
            bottom_addition = 0;
            g_editor_line.line_ascent = 0;
            g_editor_line.line_dscent = 0;
        
        }
    }
    else
    {
        g_editor_line.line_height = gui_get_character_height();
        g_editor_line.line_ascent = 0;
        g_editor_line.line_dscent = 0;
        upper_addition = 0;
        bottom_addition = 0;
    }

    g_editor_line.line_char_count = 0;
    g_editor_line.line_unit_count = 0;
    g_editor_line.highlight_flag = 0;
    g_editor_line.line_start_p = bs->current_text_p;

    while (g_editor_line.line_char_count < (GUI_INPUTS_MAX_NUM_OF_CHAR_FOR_EACH_LINE/2))
    {
        gui_set_font(&(bs->rich_text.curr_font));

        /* get the current character type */
        g_editor_line.line_char[count].char_type = gui_get_multi_line_current_cluster(b, bs, &current_character, count);
        
#if defined(__MMI_LANG_THAI__)
        if (g_editor_line.line_char[count].char_type == THAI_CLUSTER)
        {
            if (b->cursor_p > bs->current_text_p
                && b->cursor_p < bs->current_text_p + g_editor_line.line_char[count].c_info.data_len * ENCODING_LENGTH)
            {
                /* adjust the cursor position for THAI cluster */
                b->cursor_p = bs->current_text_p + g_editor_line.line_char[count].c_info.data_len * ENCODING_LENGTH;
            }
        }
#endif
        if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
        {
            /* the end of the whole text is reached */
            b->last_position_p = bs->current_text_p + ENCODING_LENGTH;
            return 0;
        }

#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__
        if ((bs->flags & UI_MULTI_LINE_INPUT_BOX_RICHTEXT) && GUI_INPUT_IS_MARKER(current_character))
        {
            g_editor_line.line_char[count].char_type = MARKER_CHAR;
            gui_apply_multi_line_marker(b, bs, current_character, 1);
        }
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__*/

    #if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
        if (UI_TEST_CR_CHARACTER(current_character))
        {
            temp_text_p = bs->current_text_p + ENCODING_LENGTH;
            UI_STRING_GET_NEXT_CHARACTER(temp_text_p, next_character);
            if (UI_TEST_LF_CHARACTER(next_character))
            {
                g_editor_line.line_char[count].char_type = CRLF_CLUSTER;
                g_editor_line.line_char[count].c_info.h = 0;
                g_editor_line.line_char[count].c_info.by = 0;
                g_editor_line.line_char[count].c_info.data_len = 2;  
                g_editor_line.line_char[count].c_info.is_gap = 1;
                g_editor_line.line_char[count].c_info.adv_x = 0;
                g_editor_line.line_char[count].c_info.w = 0;
            }
        }
    #endif /* (MULTILINE_INPUTBOX_USE_CRLF_COMBINATION) */ 

#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__ 
        if (b->icon_callback)
        {
            icon_count = b->icon_callback(bs->current_text_p, MMI_FALSE, &width, &height, 0, 0);
            if (icon_count)
            {
                g_editor_line.line_char[count].char_type = ICON_CALLBACK_CLUSTER;
                g_editor_line.line_char[count].c_info.is_gap = 0;
                g_editor_line.line_char[count].c_info.data_len = icon_count;
                g_editor_line.override_flag = 1;
            }
        }
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/

        switch (g_editor_line.line_char[count].char_type)
        {
            case SINGLE_CHAR:
            {
                if ((bs->flags & UI_MULTI_LINE_INPUT_BOX_DRAW_SEPARATOR) && UI_TEST_ESC_CHARACTER(current_character))
                {
                    bs->draw_separator = TRUE;
                }

            #if(MULTILINE_INPUTBOX_DISPLAY_SPECIAL_CHARACTERS)
                if (UI_TEST_CR_CHARACTER(current_character) ||
                    UI_TEST_LF_CHARACTER(current_character) || UI_TEST_ESC_CHARACTER(current_character))
                {
                    g_editor_line.line_char[count].c_info.adv_x = 10;
                    g_editor_line.line_char[count].c_info.w = 10;
                    g_editor_line.line_char[count].c_info.h = 10;
                    g_editor_line.line_char[count].c_info.by = 10;
                    g_editor_line.line_char[count].c_info.is_gap = 1;
                }
            #else /* (MULTILINE_INPUTBOX_DISPLAY_SPECIAL_CHARACTERS) */ 
                if (UI_TEST_LF_CHARACTER(current_character) || UI_TEST_CR_CHARACTER(current_character) &&
                    !(bs->flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS))
                {
                    g_editor_line.line_char[count].c_info.adv_x = 0;
                    g_editor_line.line_char[count].c_info.w = 0;
                    g_editor_line.line_char[count].c_info.h = 0;
                    g_editor_line.line_char[count].c_info.by = 0;
                    g_editor_line.line_char[count].c_info.is_gap = 1;
                }
            #endif /* (MULTILINE_INPUTBOX_DISPLAY_SPECIAL_CHARACTERS) */ 

            }
                break;

            case MARKER_CHAR:
                /* size = 0 */
                g_editor_line.line_char[count].c_info.w = 0;
                g_editor_line.line_char[count].c_info.adv_x = 0;
                g_editor_line.line_char[count].c_info.h = 0;
                g_editor_line.line_char[count].c_info.by = 0;
                g_editor_line.line_char[count].c_info.is_gap = 0;
                break;

            case ICON_CALLBACK_CLUSTER:
                g_editor_line.line_char[count].c_info.w = width;
                g_editor_line.line_char[count].c_info.adv_x = width;
                g_editor_line.line_char[count].c_info.h = height;
                g_editor_line.line_char[count].c_info.by = height;
                break;
                
            case MASK_CHAR:
            case INDIC_CLUSTER:
            case VIET_CLUSTER:
            case THAI_CLUSTER:
                break;

            default:
                break;
        }

        /* check the highlight information */
        g_editor_line.line_char[count].highlight_flag = (U8)gui_check_multi_line_character_highlight(b, bs, count);
        if (g_editor_line.highlight_flag == 0 && g_editor_line.line_char[count].highlight_flag)
            g_editor_line.highlight_flag = 1;

        disp_width = temp_width = former_width 
            + g_editor_line.line_char[count].c_info.adv_x 
            + g_editor_line.line_char[count].c_info.rx
            + g_editor_line.line_char[count].c_info.is_gap;
        
        if (g_editor_line.line_char[count].c_info.w > g_editor_line.line_char[count].c_info.adv_x)
            disp_width += (g_editor_line.line_char[count].c_info.w - g_editor_line.line_char[count].c_info.adv_x);

        if (bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_WRAPPING_BY_WORD)
            g_editor_line.line_char[count].c_info.is_connect = MMI_LM_CLUSTER_ATTR_CONNECT;
            
        if (count > 0 && g_editor_line.line_char[count-1].char_type == MARKER_CHAR)
            g_editor_line.line_char[count].c_info.is_connect = MMI_LM_CLUSTER_ATTR_CONNECT;

        if ((disp_width < (bs->edit_width - 1) 
            || g_editor_line.line_char[count].c_info.adv_x == 0)
            && (g_editor_line.line_char_count + g_editor_line.line_char[count].c_info.data_len < (GUI_INPUTS_MAX_NUM_OF_CHAR_FOR_EACH_LINE/2)))
        {
            /* backup the break line info if necessary */
            if (count > 0 && g_editor_line.line_char[count].c_info.is_connect == MMI_LM_CLUSTER_ATTR_DISCONNECT)
            {
                break_line_count = g_editor_line.line_char_count;
                break_unit_count = g_editor_line.line_unit_count;
                break_line_width = g_editor_line.line_width;
                break_line_height = g_editor_line.line_height;
                break_ascent = g_editor_line.line_ascent;
                break_dscent = g_editor_line.line_dscent;
                break_highlight = bs->word_highlight;
            }
            
            /* the current character is belong to the current line */
            former_width = temp_width;

            /* the current line real width */
            g_editor_line.line_width = disp_width;

            /* update the line ascent */
            if (g_editor_line.line_ascent < g_editor_line.line_char[count].c_info.by + upper_addition)
                g_editor_line.line_ascent = g_editor_line.line_char[count].c_info.by + upper_addition;
            
            /* update the line dscent */
            if (g_editor_line.line_dscent < g_editor_line.line_char[count].c_info.h 
                                                - g_editor_line.line_char[count].c_info.by + bottom_addition)
                g_editor_line.line_dscent = g_editor_line.line_char[count].c_info.h 
                                                - g_editor_line.line_char[count].c_info.by + bottom_addition;

            temp_height = g_editor_line.line_ascent + g_editor_line.line_dscent + bs->rich_text.more_line_spacing;
            if (g_editor_line.line_height < temp_height)
                g_editor_line.line_height = temp_height; 

            g_editor_line.line_char_count += g_editor_line.line_char[count].c_info.data_len;
            bs->current_text_p += g_editor_line.line_char[count].c_info.data_len * ENCODING_LENGTH;
            count++;
            g_editor_line.line_unit_count = count;
        }
        else
        {
            /* the current line is end */
            if (count > 0 && g_editor_line.line_char[count].c_info.is_connect == MMI_LM_CLUSTER_ATTR_DISCONNECT)
                break_line_count = 0;
            break;
        }

        if ((UI_TEST_LF_CHARACTER(current_character) || UI_TEST_CR_CHARACTER(current_character)) &&
            !(bs->flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS))
        {
            /* the current line is end */
            return 1;
        }
    }

    if (break_line_count)
    {
        /* This line should be cut by 0x20 */
        g_editor_line.line_char_count = break_line_count;
        g_editor_line.line_unit_count = break_unit_count;
        g_editor_line.line_width = break_line_width;
        g_editor_line.line_height = break_line_height;
        g_editor_line.line_ascent = break_ascent;
        g_editor_line.line_dscent = break_dscent;
        bs->word_highlight = break_highlight;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_cursor_information
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  bs              [?]         
 *  end_line        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multi_line_cursor_information(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_line_end;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bs->find_new_cursor_flag)
    {
        /* In this case, We can't use the b->cursor_p to find the cursor line */
        return;
    }

    current_line_end = bs->end_line ? (g_editor_line.line_start_p + (g_editor_line.line_char_count + 1) * ENCODING_LENGTH)
        : (g_editor_line.line_start_p + g_editor_line.line_char_count * ENCODING_LENGTH);

    if (b->cursor_p >= g_editor_line.line_start_p && b->cursor_p < current_line_end)
    {
        /* the cursor is at the current line */
        bs->cursor_line_found_flag = 1;
        g_editor_line.cursor_line_flag = 1;
        g_editor_line.cursor_unit_index = g_editor_line.line_unit_count;
        for (i=0; i<g_editor_line.line_unit_count; i++)
        {
            if (b->cursor_p >= g_editor_line.line_char[i].c_info.data_ptr
                && b->cursor_p < g_editor_line.line_char[i].c_info.data_ptr + g_editor_line.line_char[i].c_info.data_len * ENCODING_LENGTH)
            {
                g_editor_line.cursor_unit_index = i;
            }
        }

        b->cursor_y = bs->ty;
        b->cursor_line_p = g_editor_line.line_start_p;
        b->cursor_line_position_counter = g_editor_line.line_char_count;
        bs->cursor_line_height = g_editor_line.line_height;
        if (bs->end_line)
        {
            b->line_after_cursor_line_p = b->cursor_line_p;
            b->line_after_cursor_line_last_p = g_editor_line.line_start_p + g_editor_line.line_char_count * ENCODING_LENGTH;
        }
    }
    else if (bs->cursor_line_found_flag)
    {
        if (g_editor_line.line_start_p == b->cursor_line_p + b->cursor_line_position_counter * ENCODING_LENGTH)
        {
            /* this is the next line of the cursor line */
            b->line_after_cursor_line_p = g_editor_line.line_start_p;
            b->line_after_cursor_line_last_p = b->line_after_cursor_line_p
                + g_editor_line.line_char_count * ENCODING_LENGTH;
        }
    }
    else if (!bs->cursor_line_found_flag)
    {
        b->line_before_cursor_line_p = g_editor_line.line_start_p;
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_get_multi_line_current_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                       [?]     
 *  bs                      [?]     
 *  current_character_p     [?]     
 *  count         [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_get_multi_line_current_cluster(
    multi_line_input_box *b,
    multi_line_input_box_show_struct *bs,
    UI_character_type *current_character_p,
    U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 rtn;
    UI_character_type current_character;
    UI_buffer_type text_p = bs->current_text_p, text_end_p;
    mmi_lm_cluster_info pre2_cluster, pre_cluster;
    mmi_lm_cluster_info_p pre_cl, pre2_cl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(text_p, current_character);

    if (bs->flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS
        && !(UI_STRING_END_OF_STRING_CHARACTER(current_character)))
    {
        /* if this is a mask style, we will not find any cluster */
        if (!((bs->flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP) 
            && (bs->current_text_p == bs->previous_cursor_p)))
        {
            text_p = &b->mask_character;
            current_character = b->mask_character;
            rtn = MASK_CHAR;
        }
        else
        {
            text_p = bs->current_text_p; 
            rtn = SINGLE_CHAR;
        }

        /* mask style, so always draw single character */
        text_end_p = text_p + ENCODING_LENGTH;

        mmi_lm_cluster_init(&g_editor_line.line_char[index].c_info);
        pre_cl = &pre_cluster;
        pre2_cl = &pre2_cluster;
        mmi_lm_cluster_init(&pre_cluster);
        mmi_lm_cluster_init(&pre2_cluster);
        mmi_lm_get_current_cluster(text_p, text_end_p, pre2_cl, pre_cl, &g_editor_line.line_char[index].c_info);    

        if (rtn == MASK_CHAR)
        {
            g_editor_line.line_char[index].c_info.data_ptr = bs->current_text_p;
        }
        
        *current_character_p = current_character;
        return rtn;
    }
    else
    {
        text_p = bs->current_text_p;
        text_end_p = (UI_buffer_type)(b->text + b->text_length);
        
        mmi_lm_cluster_init(&g_editor_line.line_char[index].c_info);
        
        if (index >= 2)
		{
			pre_cl = &g_editor_line.line_char[index - 1].c_info;
            pre2_cl = &g_editor_line.line_char[index - 2].c_info;
		}
		else if (index == 1)
		{
			pre_cl = &g_editor_line.line_char[index - 1].c_info;
			pre2_cl = &pre2_cluster;
			mmi_lm_cluster_init(&pre2_cluster);
		}
		else
        {
            pre_cl = &pre_cluster;
            pre2_cl = &pre2_cluster;
            mmi_lm_cluster_init(&pre_cluster);
            mmi_lm_cluster_init(&pre2_cluster);
        }
        
        mmi_lm_get_current_cluster(text_p, text_end_p, pre2_cl, pre_cl, &g_editor_line.line_char[index].c_info);
        *current_character_p = current_character;
        return gui_get_char_type_by_lm_lang((mmi_lm_lang_enum)(g_editor_line.line_char[index].c_info.lang_id));
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_prepare_multi_line_one_line_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_prepare_multi_line_one_line_show(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Restore the font at the beginning of line  */
    bs->rich_text.line_end_font = bs->rich_text.curr_font;
    bs->rich_text.line_end_border = bs->rich_text.curr_border;
    bs->rich_text.line_end_strikethrough = bs->rich_text.curr_strikethrough;
    bs->rich_text.line_end_color = bs->rich_text.curr_color;

    bs->rich_text.curr_font = bs->rich_text.line_begin_font;
    bs->rich_text.curr_border = bs->rich_text.line_begin_border;
    bs->rich_text.curr_strikethrough = bs->rich_text.line_begin_strikethrough;
    bs->rich_text.curr_color = bs->rich_text.line_begin_color;

    gui_set_font(&(bs->rich_text.curr_font));
    UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR(bs->rich_text.curr_color);

    bs->tx = 0;

    if (bs->rich_text.curr_alignment == GUI_INPUT_ALIGN_CENTER)
    {
        bs->tx = ((bs->edit_width >> 1) - (g_editor_line.line_width >> 1));
        if (bs->tx < 0)
        {
            bs->tx = 0;
        }
    }
    else if (bs->rich_text.curr_alignment == GUI_INPUT_ALIGN_RIGHT)
    {
        bs->tx = bs->edit_width - g_editor_line.line_width;
        if (bs->tx < 0)
        {
            bs->tx = 0;
        }
    }
    else
    {
        if (bs->default_direction == BIDI_L)
            bs->tx = 0;
#ifdef __MMI_BIDI_ALG__/**/     
        else
        {
            temp_x = (bs->x2 - b->text_x - b->text_offset_x) - g_editor_line.line_width;
            bs->tx = temp_x - bs->x1;
            if (bs->tx < 0)
            {
                bs->tx = 0;
            }
        }
#endif /*__MMI_BIDI_ALG__*/   
    }

    bs->current_text_p = g_editor_line.line_start_p;

    /* set the current line y offset */
    bs->yty = bs->yy + bs->ty;
}

#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__


/*****************************************************************************
 * FUNCTION
 *  gui_calculate_multi_line_paging_information
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calculate_multi_line_paging_information(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 current_line_height;
    U8 shared_data_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_line_height = g_editor_line.line_height;
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
    {
        /** to determine the height of the currently displayed window.if condition is taken here to get the current **/
        if (bs->total_page_height + b->header_gap + b->header_height >= -(b->text_offset_y)
            && (bs->total_page_height + b->header_gap + b->header_height < (-(b->text_offset_y) + bs->edit_height))
            && b->edit_height_displayed_lines + current_line_height <= bs->edit_height)
        {

            if (bs->total_page_height + b->header_gap + b->header_height == -b->text_offset_y)
            {
                if (b->text_offset_y == -(b->header_gap + b->header_height))
                {
                    b->text_offset = 0;
                }
                else
                {
                    b->text_offset = bs->char_count;
                }
            }
            if (bs->total_page_height + b->header_gap + b->header_height > -b->text_offset_y
                && bs->total_page_height + b->header_gap + b->header_height - (-b->text_offset_y) < bs->previous_line_height)
            {
                b->text_offset = bs->char_count;
            }
            
            if (bs->char_count == 0 && -b->text_offset_y <= b->header_gap + b->header_height)
                b->text_offset = bs->char_count;

            bs->total_page_height += current_line_height;
            b->edit_height_displayed_lines += current_line_height;
            b->current_page_count += g_editor_line.line_char_count;
        }
        else
        {
            bs->total_page_height += current_line_height;
        }

        bs->char_count += g_editor_line.line_char_count;  /* for every line ,char_count is incermented by the no of containing in that line */

        /* if concerned application wants to show the text from the particular offset then this offset value is copied into 
           page_offset element of the multiline structure.According to this text_offset_y is calculated.This page_offset is compared against char_count to get text_offset_y */
        if ((b->page_offset > 0 || b->jump_offset_from_app > 0)
            && (b->page_offset >= bs->char_count || b->jump_offset_from_app >= bs->char_count))
        {
            if (b->text_offset_y == b->header_height)
                b->text_offset_y -= b->header_gap;  /* for 1 gap between header and text content */

            b->text_offset_y -= current_line_height;
            b->text_offset = bs->char_count;
            b->edit_height_displayed_lines = 0;
            b->current_page_count = 0;
        }
        else if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR
                 && (bs->ty + b->text_offset_y + current_line_height > 0) && bs->locate_cursor == 0)
        {
            b->cursor_p = g_editor_line.line_start_p;
            bs->locate_cursor = 1;
        }

        /*
         * this condition is tested for the 1st page.
         * "b->previous_shared_bytes" is considered to be the part of the page at 0th index in the buffer.it is needed to maintain the height of page 
         * available in the buffer.height of page is also dependent on the shared_bytes with next or previous page.
         * In case of next page entry,the page at 0th index will be out from the buffer and the page next to the removed one will come to 0th index and so on
         * 
         * check_flag: check_flag is needed to prevent the body of every if should be executed once.
         * 
         * page_size=512 bytes.if char_count>=512 then it should go through the if condition and set the check_flag to 1. 
         */
        if (bs->char_count >= (GUI_PAGE_SIZE + (b->previous_shared_bytes / ENCODING_LENGTH)) && bs->check_flag == 0)
        {
            /* if shared bytes is zero. previous_shared_bytes is the bytes which is shared between page at 0th and 1st index in the buffer** */
            if ((shared_data_count =
                 bs->char_count % (GUI_PAGE_SIZE + (b->previous_shared_bytes / ENCODING_LENGTH))) == 0)
            {
                b->page_details[PAGE_ZERO].page_id = b->start_id;
                b->page_details[PAGE_ZERO].page_height = bs->total_page_height;
                b->page_details[PAGE_ZERO].shared_no_of_bytes = 0;

            }
            else
            {
                memcpy(
                    b->page_details[PAGE_ZERO].shared_data,
                    b->text + (GUI_PAGE_SIZE + (b->previous_shared_bytes / ENCODING_LENGTH) - g_editor_line.line_char_count + shared_data_count) * ENCODING_LENGTH,
                    (g_editor_line.line_char_count - shared_data_count) * ENCODING_LENGTH);
                b->page_details[PAGE_ZERO].page_id = b->start_id;
                b->page_details[PAGE_ZERO].page_height = bs->total_page_height - current_line_height;
                b->page_details[PAGE_ZERO].shared_no_of_bytes =
                    (g_editor_line.line_char_count - shared_data_count) * ENCODING_LENGTH;
            }
            bs->check_flag = 1;
        }
        /*
         * 2nd page details calculation:
         * GUI_PAGE_SIZE=512 bytes.if char_count>=GUI_PAGE_SIZE*2 then it should go through the if condition and set the check_flag to 2. 
         */
        else if (bs->char_count >= GUI_PAGE_SIZE * 2 && bs->check_flag == 1)
        {
            if ((shared_data_count = bs->char_count % (GUI_PAGE_SIZE * 2)) == 0)
            {
                b->page_details[PAGE_ONE].page_id = b->start_id + 1;
                b->page_details[PAGE_ONE].page_height = bs->total_page_height - b->page_details[PAGE_ZERO].page_height;
                b->page_details[PAGE_ONE].shared_no_of_bytes = 0;
            }
            else
            {
                memcpy(
                    b->page_details[PAGE_ONE].shared_data,
                    b->text + ((GUI_PAGE_SIZE * 2) - g_editor_line.line_char_count + shared_data_count) * ENCODING_LENGTH,
                    (g_editor_line.line_char_count - shared_data_count) * ENCODING_LENGTH);
                b->page_details[PAGE_ONE].page_id = b->start_id + 1;
                b->page_details[PAGE_ONE].page_height =
                    bs->total_page_height - b->page_details[PAGE_ZERO].page_height - current_line_height;
                b->page_details[PAGE_ONE].shared_no_of_bytes =
                    (g_editor_line.line_char_count - shared_data_count) * ENCODING_LENGTH;
            }
            bs->check_flag = 2;
        }
        /*
         * 3rd page details calculation: 
         * GUI_PAGE_SIZE=512 bytes.if char_count>=GUI_PAGE_SIZE*3 then it should go through the if condition and set the check_flag to 3. 
         */
        else if (bs->char_count >= GUI_PAGE_SIZE * 3 && bs->check_flag == 2)
        {
            if ((shared_data_count = bs->char_count % (GUI_PAGE_SIZE * 3)) == 0)
            {
                b->page_details[PAGE_TWO].page_id = b->start_id + 2;
                b->page_details[PAGE_TWO].page_height =
                    bs->total_page_height - b->page_details[PAGE_ONE].page_height -
                    b->page_details[PAGE_ZERO].page_height;
                b->page_details[PAGE_TWO].shared_no_of_bytes = 0;
            }
            else
            {
                memcpy(
                    b->page_details[PAGE_TWO].shared_data,
                    b->text + ((GUI_PAGE_SIZE * 3) - g_editor_line.line_char_count + shared_data_count) * ENCODING_LENGTH,
                    (g_editor_line.line_char_count - shared_data_count) * ENCODING_LENGTH);
                b->page_details[PAGE_TWO].page_id = b->start_id + 2;
                b->page_details[PAGE_TWO].page_height =
                    bs->total_page_height - b->page_details[1].page_height -
                    b->page_details[0].page_height + current_line_height;
                b->page_details[PAGE_TWO].shared_no_of_bytes =
                    (g_editor_line.line_char_count - shared_data_count) * ENCODING_LENGTH;
            }
            bs->check_flag = 3;
        }
        /*
         * 4th page details calculation: 
         * GUI_PAGE_SIZE=512 bytes.if char_count>=GUI_PAGE_SIZE*4 then it should go through the if coditon. 
         */
        else if ((bs->char_count >= GUI_PAGE_SIZE * 4) && bs->check_flag == 3)
        {
            b->page_details[PAGE_THREE].shared_no_of_bytes = 0;
            b->page_details[PAGE_THREE].page_id = b->start_id + 3;
            b->page_details[PAGE_THREE].page_height =
                bs->total_page_height - b->page_details[PAGE_TWO].page_height -
                b->page_details[PAGE_ONE].page_height - b->page_details[PAGE_ZERO].page_height;
            bs->check_flag = 4;
        }
    }
}
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 

#ifdef __MMI_BIDI_ALG__
/*****************************************************************************
 * FUNCTION
 *  gui_translate_multi_line_bidi_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_translate_multi_line_bidi_text(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_char, iCount, i;
    pBOOL line_arabic_char_flag = MMI_FALSE;
    U8 char_type;
    S32 temp_x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bs->arabic_char_flag || ((bs->default_direction != BIDI_L) && (b->override_direction != 2)))
    {
        num_char = g_editor_line.line_char_count;

        MMI_ASSERT(num_char < GUI_INPUTS_MAX_NUM_OF_CHAR_FOR_EACH_LINE/2);

        if (num_char == 0)
        {
            return;
        }

        /* adjust the cursor position */
        if (g_editor_line.cursor_line_flag)
            bs->logical_cur_pos = (b->cursor_p - g_editor_line.line_start_p) / ENCODING_LENGTH;
        else
            bs->logical_cur_pos = 0xFFFF;

        for (iCount = 0; iCount < num_char; iCount++)
        {
            bidi_get_char_type((U8*) (g_editor_line.line_start_p + iCount * ENCODING_LENGTH), (U8*) & char_type);
            if ((char_type == AL) 
                || (char_type == AN) 
                || (char_type == BIDI_R)
                || (char_type == WS)
                || (char_type == NSM))
            {
                line_arabic_char_flag = MMI_TRUE;
                break;
            }

        }

        bidi_main_ext(
            g_editor_line.line_start_p,
            (U16) num_char,
            bs->logical_cur_pos,
            g_editor_line.visual_str,
            &bs->visual_str_len,
            &bs->visual_cur_pos,
            g_editor_line.logic_to_visual_map,
            g_editor_line.visual_to_logic_map,
            0,
            MMI_bidi_input_type,
            g_editor_line.override_flag,
            (bs->default_direction == BIDI_L) ? P_LTR : (line_arabic_char_flag ? P_RTL : P_LTR));

        bs->current_text_p = g_editor_line.visual_str;
        g_editor_line.bidi_done_flag = 1;

        /* translate the character map to unit map */
        gui_convert_bidi_map_to_unit_map(bs->visual_str_len);

        if (bs->visual_cur_pos != 0xFFFF)
        {
            g_editor_line.cursor_unit_index = g_editor_line.line_unit_count;

            for (i = 0, num_char = 0; i<g_editor_line.visual_unit_count; i++)
            {
                iCount = g_editor_line.visual_to_logic_map[i];
                num_char += g_editor_line.line_char[iCount].c_info.data_len;
                if (bs->visual_cur_pos < num_char)
                {
                    g_editor_line.cursor_unit_index = iCount;
					break;
                }
            }
        }
        
        // recalculate the line width after BIDI
        g_editor_line.cur_read = 0;
        g_editor_line.line_width = 0;
        for(i = 0; i < g_editor_line.line_unit_count; i++)
        {
            gui_get_multi_line_current_char_offset(bs, i);
            if (i < (g_editor_line.line_unit_count - 1))
            {
                g_editor_line.line_width += g_editor_line.line_char[g_editor_line.cur_read].c_info.adv_x
                                + g_editor_line.line_char[g_editor_line.cur_read].c_info.rx
                                + g_editor_line.line_char[g_editor_line.cur_read].c_info.is_gap;
            }
            else
            {
                g_editor_line.line_width += g_editor_line.line_char[g_editor_line.cur_read].c_info.w;
            }
        }
        if (bs->rich_text.curr_alignment == GUI_INPUT_ALIGN_CENTER)
        {
            bs->tx = ((bs->edit_width >> 1) - (g_editor_line.line_width >> 1));
            if (bs->tx < 0)
            {
                bs->tx = 0;
            }
        }
        else if (bs->rich_text.curr_alignment == GUI_INPUT_ALIGN_RIGHT)
        {
            bs->tx = bs->edit_width - g_editor_line.line_width;
            if (bs->tx < 0)
            {
                bs->tx = 0;
            }
        }
        else
        {
            if (bs->default_direction == BIDI_L)
                bs->tx = 0;
            else
            {
                temp_x = (bs->x2 - b->text_x - b->text_offset_x) - g_editor_line.line_width;
                bs->tx = temp_x - bs->x1;
                if (bs->tx < 0)
                {
                    bs->tx = 0;
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_convert_multi_line_unit_map
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void    
 *      
 * RETURNS
 *  void
 *****************************************************************************/
void gui_convert_bidi_map_to_unit_map(S32 max_n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0, j, char_index, unit_index, v_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < max_n)
    {
        char_index = g_editor_line.visual_to_logic_map[i];

        /* find the unit for logic_index */
        j = 0;
        unit_index = 0;
        while (1)
        {
            if (j + g_editor_line.line_char[unit_index].c_info.data_len > char_index)
                break;
            else
            {
                j += g_editor_line.line_char[unit_index++].c_info.data_len;
            }

            ASSERT(unit_index < g_editor_line.line_unit_count);
        }

        ASSERT(v_index <= i);
        
		
		/* update the visual_to_logic_map for unit */
        g_editor_line.visual_to_logic_map[v_index++] = unit_index;
        i += g_editor_line.line_char[unit_index].c_info.data_len;
    } 

    for (i = 0; i<v_index; i++)
        g_editor_line.logic_to_visual_map[g_editor_line.visual_to_logic_map[i]] = i;
    
    g_editor_line.visual_unit_count = v_index;

}
#endif /* __MMI_BIDI_ALG__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_draw_multi_line_one_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_multi_line_one_line(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 character_width;
    S32 baseline = 0, i, gap = 0;
    U8 highlight = 0;
    color line_color;
    UI_buffer_type current_text_p = NULL;
    UI_character_type current_character;
#ifdef __UI_ENHANCED_HILITE_IN_MULTILINE_EDITOR__
    U16 hilite_idx = 0;
#endif
    U8 ret_truncate = 0;

    S32 def_text_width, def_text_height;
    UI_string_type default_text = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_editor_line.cur_read = 0;
    baseline = g_editor_line.line_ascent;
    
    if (!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
    {
        /* draw all the highlight for current line */
        if (g_editor_line.highlight_flag)
            gui_draw_multi_line_current_line_highlight(b, bs);
    
        
        if (g_editor_line.line_char_count == 0)
        {
            /* this is a blank line, try to draw the cursor and back */
            bs->xtx = bs->xx + bs->tx;

            if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) 
                    && (gui_multi_line_input_box_get_text_length(b) == 0)
                    && (bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW))
            {
                if (b->default_text)
                {
                    default_text = b->default_text;
                }
                if (default_text != NULL)
                {
    			#ifdef __MMI_FTE_SUPPORT__
                    gui_set_text_color(*(current_MMI_theme->inputbox_default_text_color));
    			#else
    				gui_set_text_color(gui_color(160, 160, 160));
    			#endif /* __MMI_FTE_SUPPORT__ */
                    if (!mmi_fe_get_r2l_state())
                    {
                        mmi_fe_show_string_n_baseline(bs->xtx,
                            bs->yty,
                            (PU8)default_text,
                            mmi_ucs2strlen((const CHAR*)default_text),
                            g_editor_line.line_ascent);
                    }
                    else
                    {
                        Get_StringWidthHeight((PU8)default_text, &def_text_width, &def_text_height);
                        mmi_fe_show_string_n_baseline(bs->xtx + def_text_width,
                            bs->yty,
                            (PU8)default_text,
                            mmi_ucs2strlen((const CHAR*)default_text),
                            g_editor_line.line_ascent);
                    }
                }
            }
            
            gui_handle_multi_line_cursor(b, bs);
            return;
        }

        for(i=0; i<g_editor_line.line_unit_count; i++)
        {
            bs->xtx = bs->xx + bs->tx;
            /* 
             * get the character to draw. we need to do two things: 
             * 1. get the right *current_text_p 
             * 2. set the right g_editor_line.cur_read
             */
            bs->current_text_p = current_text_p = gui_get_multi_line_current_char_offset(bs, i);
            if (current_text_p == NULL)
            {
                /* to the line end */
                break;
            }
            
            /* adjust the xtx for rx */
            bs->tx += g_editor_line.line_char[g_editor_line.cur_read].c_info.rx;
            bs->xtx += g_editor_line.line_char[g_editor_line.cur_read].c_info.rx;

            character_width = g_editor_line.line_char[g_editor_line.cur_read].c_info.adv_x;

            if (g_editor_line.line_char[g_editor_line.cur_read].c_info.is_gap == MMI_LM_CLUSTER_ATTR_GAP)
            {
                gap = 1;
                bs->tx ++;
                bs->xtx ++;
            
#ifdef __MMI_BIDI_ALG__
                {
                    U8 char_type;
            
                    bidi_get_char_type((U8*) current_text_p, (U8*) & char_type);
                    if ((char_type == AL) || (char_type == BIDI_R))
                    {
                        bs->tx--;
                        bs->xtx--;
                        character_width++;
                    }
                }
#endif
            }            
  
            UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
            highlight = g_editor_line.line_char[g_editor_line.cur_read].highlight_flag;

            if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
            {
                /* draw the text content */
                UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR(bs->rich_text.curr_color);

                if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_USE_BORDER_FONT)
                    gui_set_text_border_color(b->border_color);

#ifdef __UI_ENHANCED_HILITE_IN_MULTILINE_EDITOR__
                /* support to highlight the words in the hilite list */
                if (b->hilite_list != NULL
                    && b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_USE_HILITE_FORMAT
                    && highlight == EDITOR_HILITE_LIST_HIGHLIGHT)
                {
                    if (gui_multi_line_input_box_is_pos_inside_hilite_ext(b, current_text_p, &hilite_idx))
                    {
                        gui_set_multi_line_hilite_format(b, bs, hilite_idx);
                    }
                }
#endif

            #ifdef __MMI_BIDI_ALG__
                #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__ 
                if (g_editor_line.bidi_done_flag && g_editor_line.marker_flag)
                {
                    /*
                     * if this line is handle by bidi_alg and have some markers to 
                     * set, we should set the marker for every character.
                     */
                    gui_apply_multi_line_marker_for_bidi_text(b, bs);
                }
                #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__*/
            #endif /* __MMI_BIDI_ALG__ */ 

                if (highlight && highlight != EDITOR_HILITE_LIST_HIGHLIGHT)
                {
                    UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR(bs->selected_text_color);
                }

                /* check whether to truncate the content */
                ret_truncate = gui_truncate_multi_line_content(b, bs);
                if (!ret_truncate)
                {
                    /* handle the current character */
                    switch (g_editor_line.line_char[g_editor_line.cur_read].char_type)
                    {
                        case SINGLE_CHAR:
                            MMI_ASSERT(current_text_p != NULL);
                            gui_draw_multi_line_single_character(b, bs, current_character);
                            break;
                        
                        case MASK_CHAR:
                            g_editor_line.line_char[g_editor_line.cur_read].c_info.display_buffer[0] = b->mask_character;
                       //     if (!FONT_TEST_NEW_LINE_CHAR(*(g_editor_line.line_char[g_editor_line.cur_read].c_info.data_ptr)))
                            {
                                gui_draw_multi_line_text(b, bs);
                            }
                            break;
                        
                       #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__
                        case MARKER_CHAR:
                            if (!g_editor_line.bidi_done_flag)
                                gui_apply_multi_line_marker(b, bs, current_character, 2);
                            break;
                       #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__*/

                        case ICON_CALLBACK_CLUSTER:
                            {
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__                                 
                                UI_buffer_type icon_p;
                            
                                icon_p = g_editor_line.line_char[g_editor_line.cur_read].c_info.data_ptr;
                                b->icon_callback(icon_p, MMI_TRUE, NULL, NULL, bs->xtx, bs->yty);
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/                                
                            }
                            break;
                        
                        case CRLF_CLUSTER:
                            break;
                        
                        default:    /* draw the text */
                            gui_draw_multi_line_text(b, bs);
                            break;

                    }
                }
                #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__
                /* Draw the strikethrough */
                if (bs->rich_text.curr_strikethrough)
                {
                    if (!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                    {
                        UI_draw_horizontal_line(
                            bs->xtx,
                            bs->xtx + character_width - 1,
                            bs->yty + (baseline >> 1),
                            gui_richtext_strikethrough_color);
                    }
                }

                /* Draw the strikethrough */
                if (bs->rich_text.curr_font.underline)
                {
                    if (!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                    {
                        UI_draw_horizontal_line(
                            bs->xtx,
                            bs->xtx + character_width - 1,
                            bs->yty + g_editor_line.line_height - 2,
                            UI_get_text_color());
                    }
                }
                #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__*/           

                /* Draw the  highlight list underline */

#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__

                if (b->hilite_list != NULL && highlight == EDITOR_HILITE_LIST_HIGHLIGHT)
                {
#ifdef __UI_ENHANCED_HILITE_IN_MULTILINE_EDITOR__
                    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_USE_HILITE_FORMAT
                        && b->hilite_format_list[hilite_idx].format_flag & GUI_MULTI_LINE_INPUT_HILITE_UNDERLINE_COLOR)
                        line_color = b->hilite_format_list[hilite_idx].underline_color;
                    else
#endif    
                        line_color = gui_hilite_underline_color;

                    UI_draw_horizontal_line(
                        bs->xtx - gap,
                        bs->xtx + character_width - 1,
                        bs->yty + g_editor_line.line_height - 1,
                        line_color);
                }
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
            }

            /* handle the cursor */
            gui_handle_multi_line_cursor(b, bs);

            bs->tx += character_width;

            if (ret_truncate)
            {
                break;
            }
        }
    }
}
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__

#ifdef __MMI_BIDI_ALG__


/*****************************************************************************
 * FUNCTION
 *  gui_apply_multi_line_marker_for_bidi_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_apply_multi_line_marker_for_bidi_text(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    UI_buffer_type p;
    UI_character_type current_character;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* restore the current font and color to the beginning of the line start */
    bs->rich_text.curr_font = bs->rich_text.line_begin_font;
    bs->rich_text.curr_border = bs->rich_text.line_begin_border;
    bs->rich_text.curr_strikethrough = bs->rich_text.line_begin_strikethrough;
    bs->rich_text.curr_color = bs->rich_text.line_begin_color;

    gui_set_font(&(bs->rich_text.curr_font));
    UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR(bs->rich_text.curr_color);

    for (i = 0; i <= g_editor_line.cur_read; i++)
    {
        if (g_editor_line.line_char[i].char_type == MARKER_CHAR)
        {
            p = g_editor_line.line_start_p;

            for (j = 0; j < i; j++)
                p += g_editor_line.line_char[j].c_info.data_len * ENCODING_LENGTH;

            UI_STRING_GET_NEXT_CHARACTER(p, current_character);

            gui_apply_multi_line_marker(b, bs, current_character, 2);
        }
    }

    return;

}
#endif /* __MMI_BIDI_ALG__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_apply_multi_line_marker
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                       [?]         
 *  bs                      [?]         
 *  current_character       [IN]        
 *  which_pass              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_apply_multi_line_marker(
        multi_line_input_box *b,
        multi_line_input_box_show_struct *bs,
        UI_character_type current_character,
        U32 which_pass)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL change_font = MMI_FALSE;
    BOOL change_color = MMI_FALSE, change_others = MMI_FALSE;
    gui_input_richtext_struct rich_text = bs->rich_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (current_character)
    {
        case GUI_INPUT_MARKER_RESET_ALL:
            /* Reset font format and color (no paragraph) */
            rich_text.curr_font = *b->text_font;
            rich_text.curr_border = 0;
            /* USAT */
            rich_text.curr_strikethrough = 0;
            rich_text.curr_text_bg_color = bs->rich_text.default_text_bg_color;
            rich_text.draw_text_bg_color = 0;
            rich_text.curr_color = bs->rich_text.default_color;
            change_font = MMI_TRUE;
            change_color = MMI_TRUE;
            break;

        case GUI_INPUT_MARKER_RESET_PARAGRAPH:
            if (which_pass == 1)
            {
                /* this format only affect at the first pass */
                rich_text.curr_alignment = bs->rich_text.default_alignment;
                rich_text.more_line_spacing = 0;
                rich_text.line_separator = 0;
            }
            break;

        case GUI_INPUT_MARKER_RESET_FORMAT:
            rich_text.curr_font = *b->text_font;
            rich_text.curr_border = 0;
            /* USAT */
            rich_text.curr_strikethrough = 0;
            change_font = MMI_TRUE;
            break;

        case GUI_INPUT_MARKER_RESET_COLOR:
            rich_text.curr_color = bs->rich_text.default_color;
            /* USAT */
            rich_text.curr_text_bg_color = bs->rich_text.default_text_bg_color;
            rich_text.draw_text_bg_color = 0;
            change_color = MMI_TRUE;
            break;

        default:
            if (current_character >= GUI_INPUT_MARKER_COLOR_BEGIN && current_character <= GUI_INPUT_MARKER_COLOR_END)
            {
                if (current_character - GUI_INPUT_MARKER_COLOR_BEGIN < MAX_GUI_INPUT_COLOR)
                {
                    rich_text.curr_color =
                        g_mmi_gui_input_format_color_table[current_character - GUI_INPUT_MARKER_COLOR_BEGIN];
                    change_color = MMI_TRUE;
                }
            }
            else if (current_character >= GUI_INPUT_MARKER_W3C_COLOR_BEGIN &&
                     current_character <= GUI_INPUT_MARKER_W3C_COLOR_END)
            {
                if (current_character - GUI_INPUT_MARKER_W3C_COLOR_BEGIN < MAX_GUI_INPUT_W3C_COLOR)
                {
                    rich_text.curr_color =
                        g_mmi_gui_input_format_w3c_color_table[current_character - GUI_INPUT_MARKER_W3C_COLOR_BEGIN];
                    change_color = MMI_TRUE;
                }
            }
            /* USAT */
            else if (current_character >= GUI_INPUT_MARKER_TEXT_BACKGROUND_COLOR_BEGIN &&
                     current_character <= GUI_INPUT_MARKER_TEXT_BACKGROUND_COLOR_END)
            {
                if (current_character - GUI_INPUT_MARKER_TEXT_BACKGROUND_COLOR_BEGIN < MAX_GUI_INPUT_W3C_TEXT_BG_COLOR)
                {
                    rich_text.curr_text_bg_color =
                        g_mmi_gui_input_format_w3c_text_background_color_table[current_character
                                                                               -
                                                                               GUI_INPUT_MARKER_TEXT_BACKGROUND_COLOR_BEGIN];
                    rich_text.draw_text_bg_color = 1;
                }
            }

            if (current_character >= GUI_INPUT_MARKER_BORDER_COLOR_BEGIN &&
                current_character <= GUI_INPUT_MARKER_BORDER_COLOR_END)
            {
                if (current_character - GUI_INPUT_MARKER_BORDER_COLOR_BEGIN < MAX_GUI_INPUT_COLOR)
                {
                    gui_set_text_border_color(g_mmi_gui_input_format_color_table
                                              [current_character - GUI_INPUT_MARKER_BORDER_COLOR_BEGIN]);
                }
            }
            else if (current_character >= GUI_INPUT_MARKER_W3C_BORDER_COLOR_BEGIN &&
                     current_character <= GUI_INPUT_MARKER_W3C_BORDER_COLOR_END)
            {
                if (current_character - GUI_INPUT_MARKER_W3C_BORDER_COLOR_BEGIN < MAX_GUI_INPUT_W3C_COLOR)
                {
                    gui_set_text_border_color(g_mmi_gui_input_format_w3c_color_table
                                              [current_character - GUI_INPUT_MARKER_W3C_BORDER_COLOR_BEGIN]);
                }
            }
            else if (GUI_INPUT_IS_FORMAT_MARKER(current_character))
            {
                if (GUI_INPUT_CHECK_FORMAT_MARKER(current_character, GUI_INPUT_MARKER_BOLD))
                {
                    rich_text.curr_font.bold = 1;
                    change_font = MMI_TRUE;
                }
                if (GUI_INPUT_CHECK_FORMAT_MARKER(current_character, GUI_INPUT_MARKER_ITALIC))
                {
                    rich_text.curr_font.italic = 1;
                    change_font = MMI_TRUE;
                }
                if (GUI_INPUT_CHECK_FORMAT_MARKER(current_character, GUI_INPUT_MARKER_UNDERLINE))
                {
                    rich_text.curr_font.underline = 1;
                    change_font = MMI_TRUE;
                }
                /* USAT */
                if (GUI_INPUT_CHECK_FORMAT_MARKER(current_character, GUI_INPUT_MARKER_STRIKETHROUGH))
                {
                    rich_text.curr_strikethrough = 1;
                    change_others = MMI_TRUE;
                }

                if (GUI_INPUT_CHECK_FORMAT_MARKER(current_character, GUI_INPUT_MARKER_BORDER))
                {
                    /* We do not increase font size for bordered font because text gap is already enlarged */
                    rich_text.curr_border = 1;
                    change_others = MMI_TRUE;
                }

                if (GUI_INPUT_CHECK_SIZE_MARKER(current_character, GUI_INPUT_MARKER_SMALL))
                {
                    rich_text.curr_font.size = SMALL_FONT;
                    change_font = MMI_TRUE;
                }
                else if (GUI_INPUT_CHECK_SIZE_MARKER(current_character, GUI_INPUT_MARKER_MEDIUM))
                {
                    rich_text.curr_font.size = MEDIUM_FONT;
                    change_font = MMI_TRUE;
                }
                else if (GUI_INPUT_CHECK_SIZE_MARKER(current_character, GUI_INPUT_MARKER_LARGE))
                {
                    rich_text.curr_font.size = LARGE_FONT;
                    change_font = MMI_TRUE;
                }
            }
            else if (GUI_INPUT_IS_PARAGRAPH_MARKER(current_character) && which_pass == 1)
            {
                /* Paragraph handled only in the first pass */
                if (GUI_INPUT_CHECK_ALIGN_MARKER(current_character, GUI_INPUT_MARKER_ALIGN_LEFT))
                {
                    rich_text.curr_alignment = GUI_INPUT_ALIGN_LEFT;
                }
                else if (GUI_INPUT_CHECK_ALIGN_MARKER(current_character, GUI_INPUT_MARKER_ALIGN_CENTER))
                {
                    rich_text.curr_alignment = GUI_INPUT_ALIGN_CENTER;
                }
                else if (GUI_INPUT_CHECK_ALIGN_MARKER(current_character, GUI_INPUT_MARKER_ALIGN_RIGHT))
                {
                    rich_text.curr_alignment = GUI_INPUT_ALIGN_RIGHT;
                }

                if (GUI_INPUT_CHECK_LINE_SPACING_MARKER(current_character, GUI_INPUT_MARKER_LINE_SPACING_1))
                {
                    rich_text.more_line_spacing = 1;
                }
                else if (GUI_INPUT_CHECK_LINE_SPACING_MARKER(current_character, GUI_INPUT_MARKER_LINE_SPACING_2))
                {
                    rich_text.more_line_spacing = 2;
                }
                else if (GUI_INPUT_CHECK_LINE_SPACING_MARKER(current_character, GUI_INPUT_MARKER_LINE_SPACING_3))
                {
                    rich_text.more_line_spacing = 3;
                }
                else if (GUI_INPUT_CHECK_LINE_SPACING_MARKER(current_character, GUI_INPUT_MARKER_LINE_SPACING_4))
                {
                    rich_text.more_line_spacing = 4;
                }
                else if (GUI_INPUT_CHECK_LINE_SPACING_MARKER(current_character, GUI_INPUT_MARKER_LINE_SPACING_5))
                {
                    rich_text.more_line_spacing = 5;
                }
                else if (GUI_INPUT_CHECK_LINE_SPACING_MARKER(current_character, GUI_INPUT_MARKER_LINE_SPACING_6))
                {
                    rich_text.more_line_spacing = 6;
                }
                else if (GUI_INPUT_CHECK_LINE_SPACING_MARKER(current_character, GUI_INPUT_MARKER_LINE_SPACING_7))
                {
                    rich_text.more_line_spacing = 7;
                }

                if (GUI_INPUT_CHECK_PARAGRAPH_MARKER(current_character, GUI_INPUT_MARKER_LINE_SEPARATOR))
                {
                    rich_text.line_separator = 1;
                }

                /* Reserve minimum line spacing for line separator */
                if (bs->rich_text.line_separator && bs->rich_text.more_line_spacing < 3)
                {
                    rich_text.more_line_spacing = 3;
                }
            }
            break;
    }

    if (change_font)
    {
        gui_set_font(&rich_text.curr_font);
    }

    if (change_color && which_pass == 2)
    {
        UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR(rich_text.curr_color);
    }

    if ( which_pass == 1
        && (change_font || change_color || change_others))
    {
        /* this line contain marker to set at the line show function */
        g_editor_line.marker_flag = 1;
    }

    bs->rich_text = rich_text;
}
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_RICH_TEXT__*/

/*****************************************************************************
 * FUNCTION
 *  gui_get_multi_line_current_char_offset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bs                  [?]         
 *  current_text_p      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_buffer_type gui_get_multi_line_current_char_offset(multi_line_input_box_show_struct *bs, S32 disp_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_editor_line.bidi_done_flag)
    {
        g_editor_line.cur_read = disp_count;
        if (g_editor_line.cur_read >= g_editor_line.line_unit_count)
        {
            /* to the current line end */
            return NULL;
        }

        p = g_editor_line.line_char[g_editor_line.cur_read].c_info.data_ptr;
    }
#ifdef __MMI_BIDI_ALG__
    else
    {
        if (disp_count >= g_editor_line.line_unit_count)
        {
            /* to the current line end */
            return NULL;
        }
        
        g_editor_line.cur_read = g_editor_line.visual_to_logic_map[disp_count];
        g_editor_line.cur_v_read = disp_count;
        p = g_editor_line.line_char[g_editor_line.cur_read].c_info.data_ptr;
    }
#endif /* __MMI_BIDI_ALG__ */ 

    return p;
}


/*****************************************************************************
 * FUNCTION
 *  gui_draw_multi_line_highlight_background
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_multi_line_current_line_highlight(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 xtx, xx, tx, gap, i;
    S32 char_width, char_height, highlight_width;
    U8 highlight;
    UI_buffer_type current_text_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW)
        return;
    
    xx = bs->xx;
    tx = bs->tx;
    
    if(bs->flags & UI_MULTI_LINE_INPUT_BOX_DRAW_UNDERLINE)
        gap = 2;
    else
        gap = 1;

    if (g_editor_line.highlight_flag)
    {
        for(i=0; i<g_editor_line.line_unit_count; i++)
        {
            xtx = xx + tx;

            current_text_p = gui_get_multi_line_current_char_offset(bs, i);
            if (current_text_p == NULL)
            {
                /* to the line end */
                break;
            }
            
            /* adjust the xtx for rx */
            tx += g_editor_line.line_char[g_editor_line.cur_read].c_info.rx;
            xtx += g_editor_line.line_char[g_editor_line.cur_read].c_info.rx;

            char_width = g_editor_line.line_char[g_editor_line.cur_read].c_info.adv_x;
            highlight_width = g_editor_line.line_char[g_editor_line.cur_read].c_info.w;
            highlight_width = char_width > highlight_width ? char_width : highlight_width;

            if ((g_editor_line.line_char[g_editor_line.cur_read].c_info.is_gap == MMI_LM_CLUSTER_ATTR_GAP) ||
                (g_editor_line.cur_read == g_editor_line.line_unit_count - 1))
            {
                char_width++;
                highlight_width++;
            }
            
            char_height = g_editor_line.line_height;
            highlight = g_editor_line.line_char[g_editor_line.cur_read].highlight_flag;

            if (highlight)
            {
                if (highlight != EDITOR_HILITE_LIST_HIGHLIGHT)
                {
                    gui_fill_rectangle(xtx, bs->yty, xtx + highlight_width - 1, bs->yty + char_height - gap, bs->selector_color);

                    if (b->hilite_s_x == 0 && b->hilite_s_y == 0)
                    {
                        b->hilite_s_x = xtx;
                        b->hilite_s_y = bs->yty;
                    }
                    b->hilite_e_x = xtx + highlight_width - 1;
                    b->hilite_e_y = bs->yty;
                }
#ifdef  __UI_ENHANCED_HILITE_IN_MULTILINE_EDITOR__
                else
                {
                    U16 hilite_idx;

                    hilite_idx = g_editor_line.line_char[g_editor_line.cur_read].hilite_idx;

                    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_USE_HILITE_FORMAT
                        &&b->hilite_format_list[hilite_idx].format_flag & GUI_MULTI_LINE_INPUT_HILITE_BACKGROUND_COLOR)
                    gui_fill_rectangle(xtx, bs->yty, xtx + highlight_width, bs->yty + char_height - gap, b->hilite_format_list[hilite_idx].filler_color);
                }
#endif
            }

            tx += char_width;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_check_multi_line_character_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  
 *****************************************************************************/
U32 gui_check_multi_line_character_highlight(multi_line_input_box *b, multi_line_input_box_show_struct *bs, U16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 highlight = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__

    /* Check for hilite list, which maybe overrided by common highlight */
    if (b->hilite_list != NULL)
    {
        if (gui_multi_line_input_box_is_pos_inside_hilite_ext(b, bs->current_text_p, &g_editor_line.line_char[count].hilite_idx))
        {
            highlight = EDITOR_HILITE_LIST_HIGHLIGHT;
        }
    }

#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/

    /* Check for common highlight */
    if ((bs->flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT) && b->highlight_start_position != NULL)
    {
        if (bs->current_text_p == b->highlight_start_position
            || (!bs->word_highlight 
            && bs->current_text_p < b->highlight_start_position
            && (bs->current_text_p + g_editor_line.line_char[count].c_info.data_len * ENCODING_LENGTH) > b->highlight_start_position))
        {
            /* barcode */
            int temp_y = bs->ty;
            
            bs->word_highlight = 1;
            b->curr_hilite_text_offset_y = -temp_y;

            #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__

            if (b->hilite_list != NULL)
            {
                if (b->hilite_str_number == 0)
                {
                    bs->word_highlight = 0;
                }
            }

            #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/            
        }
        
        if (!bs->word_highlight
            && bs->current_text_p >= b->highlight_start_position
            && bs->current_text_p < b->highlight_end_position)
        {
            bs->word_highlight = 1;
            b->curr_hilite_text_offset_y = -(bs->ty);
        }

        if (bs->current_text_p == b->highlight_end_position
            || (bs->word_highlight && bs->current_text_p > b->highlight_end_position))
        {
            bs->word_highlight = 0;
            b->highlight_end_y = bs->yy + bs->ty + g_editor_line.line_height;
        }

        if (bs->word_highlight)
        {
            highlight = EDITOR_COMMON_HIGHLIGHT;
            b->highlight_end_y = bs->yy + bs->ty + g_editor_line.line_height;
        }

    }

    /* Check for multitap highlight */
    if (bs->multitap_flag)
    {
        if ((bs->current_text_p <= bs->previous_cursor_p)
            && (bs->previous_cursor_p < bs->current_text_p + g_editor_line.line_char[count].c_info.data_len * ENCODING_LENGTH))
            highlight = EDITOR_MULTITAP_HIGHLIGHT;
         /* This logic ensures that the characters entered by multitap mode are highlighted 
         * The logic works by looking that the character is in between the input mode start
         * and cursor position and highlight the characters.
         */
        /* We can remove the above condition and use the more 
             generalized condition using variable input_start_cursor_p. Kindly comment 
             and make appropriate changes if possible */
        if(bs->current_text_p + g_editor_line.line_char[count].c_info.data_len * ENCODING_LENGTH  > b->input_start_cursor_p &&
            bs->current_text_p + g_editor_line.line_char[count].c_info.data_len * ENCODING_LENGTH <= b->cursor_p)
            highlight = EDITOR_MULTITAP_HIGHLIGHT;
    }

    /* Check for overwrite highlight */
    if (bs->overwrite_flag && !bs->multitap_flag)
    {
        if (bs->current_text_p == bs->current_cursor_p ||
            ((bs->current_cursor_p >= bs->current_text_p) && (bs->current_cursor_p < bs->current_text_p + g_editor_line.line_char[count].c_info.data_len * ENCODING_LENGTH)))
        {
            highlight = EDITOR_OVERWRITE_HIGHLIGHT;
        }
    }

    return highlight;
}


/*****************************************************************************
 * FUNCTION
 *  gui_truncate_multi_line_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_truncate_multi_line_content(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 current_line_height = g_editor_line.line_height;
    U16 character_width = g_editor_line.line_char[g_editor_line.cur_read].c_info.adv_x;
    U8 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT) &&
        (bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR))
    {
        if (b->text_height > b->edit_height)
        {
            if (bs->yty + current_line_height * 2 > bs->y2
                || bs->line_counter == b->n_lines - 2)
            {
                S32 width, height;
                Get_StringWidthHeight((U8*)INPUTBOX_TRUNCATE_STRING, &width, &height);

                if ((g_editor_line.line_char_count == 1 
                    || bs->xtx + character_width + width >= b->x + b->edit_width
                    || g_editor_line.cur_read == g_editor_line.line_unit_count - 1)
                    && (bs->end_line != 1))
                {
                    FONT_CANCEL_WIDTH(1);
#ifdef __MMI_BIDI_ALG__/**/             
                    if (bs->default_direction == BIDI_R)
                    {
                        if (FONT_TEST_NEW_LINE_CHAR(*(g_editor_line.line_char[g_editor_line.cur_read].c_info.data_ptr)))
                        {
                            ShowString_n_baseline((bs->xtx - g_editor_line.line_width - width - 1), bs->yty, *UI_font, 0, (U8*)INPUTBOX_TRUNCATE_STRING, INPUTBOX_TRUNCATE_DOT_NUM, g_editor_line.line_ascent);
                        }
                        else
                        {
                            ShowString_n_baseline((bs->xtx + character_width - width - 1), bs->yty, *UI_font, 0, (U8*)INPUTBOX_TRUNCATE_STRING, INPUTBOX_TRUNCATE_DOT_NUM, g_editor_line.line_ascent);
                        }
                        ret = 0;
                    }
                    else
#endif /*__MMI_BIDI_ALG__*/              
                    {
                        ShowString_n_baseline(bs->xtx, bs->yty, *UI_font, 0, (U8*)INPUTBOX_TRUNCATE_STRING, INPUTBOX_TRUNCATE_DOT_NUM, g_editor_line.line_ascent);
                        ret = 1;
                    }
                    FONT_CANCEL_WIDTH(0);
                    bs->end_line = 1;
                    bs->is_truncate = 1;
                    return ret;
                }
            }
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_find_multi_line_cursor_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_find_multi_line_cursor_position(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x = b->cursor_fixed_x;
    UI_buffer_type cursor_p;

    S32 d = 0;
    S32 found = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x == -1)
        x = b->cursor_x;

    if ((b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_PREVIOUSE_LINE)
        && g_editor_line.line_start_p == b->line_before_cursor_line_p)
    {
        if (b->cursor_fixed_x == -1)
            b->cursor_fixed_x = b->cursor_x;
        d = 1;
    }
    else if ((b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_NEXT_LINE)
             && g_editor_line.line_start_p == b->line_after_cursor_line_p)
    {
        if (b->cursor_fixed_x == -1)
            b->cursor_fixed_x = b->cursor_x;
        d = 2;
    }
    else if(bs->move_to_x != -1 || bs->move_to_y != -1)
    {
        /* find cursor by move_to_x and move_to_y */
        x = bs->move_to_x;

        if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE &&
            ((bs->move_to_y < b->header_height + b->header_gap + bs->yy && b->header_callback)
            || (bs->move_to_y > bs->yy - b->footer_height + b->text_height && b->footer_callback)))
        {
            b->cursor_p = NULL;
            bs->find_new_cursor_flag = FOUND_CURSOR;            
        }

        if (bs->move_to_y >= bs->ty + bs->yy
            && bs->move_to_y < bs->ty + bs->yy + g_editor_line.line_height)
            d = 3;

        if (bs->end_line 
            && (bs->move_to_y >= bs->ty + bs->yy + g_editor_line.line_height))
        {
            d = 3;
            x = b->x + b->width;
        }
    }

    if (d)
    {
        if (g_editor_line.line_unit_count == 0)
        {
            b->cursor_p = g_editor_line.line_start_p;
            bs->find_new_cursor_flag = FOUND_CURSOR;
            found = 1;
        }
        else if (bs->xtx + g_editor_line.line_char[g_editor_line.cur_read].c_info.adv_x > x)
        {
            /* ok, have found it */
#ifdef __MMI_BIDI_ALG__/**/            
            if (bs->default_direction == BIDI_R 
                && bs->xtx >= x
                && bs->end_line)
            {
                
#ifdef __MMI_BIDI_ALG__
                if ((g_editor_line.bidi_done_flag && g_editor_line.logic_to_visual_map[g_editor_line.cur_read] == 0)
                    || (!g_editor_line.bidi_done_flag && g_editor_line.cur_read == 0))
                    
#else
                if (g_editor_line.cur_read == 0)
#endif
                {
                    /* 
                     * the x offset is less than the first display character,
                     * we need to set the cursor to the end of this line.
                     */

                    cursor_p = g_editor_line.line_start_p + g_editor_line.line_char_count * ENCODING_LENGTH;
                }
                else
                    cursor_p = g_editor_line.line_char[g_editor_line.cur_read].c_info.data_ptr;
            }
            else
#endif /*__MMI_BIDI_ALG__*/                   
                    cursor_p = g_editor_line.line_char[g_editor_line.cur_read].c_info.data_ptr;

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/    
            if (d == 3)
            {
                if (gui_check_multi_line_cursor_validation_for_wcss(b, bs, cursor_p))
                    b->cursor_p = cursor_p;   
            }
            else    
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/ 
                b->cursor_p = cursor_p;
            
            bs->find_new_cursor_flag = FOUND_CURSOR;
            found = 1;
        }
        else
        {
#ifdef __MMI_BIDI_ALG__
            if (g_editor_line.bidi_done_flag)
            {
                if (g_editor_line.logic_to_visual_map[g_editor_line.cur_read] == g_editor_line.visual_unit_count - 1)
                {
                    /*
                     * the current character is the last one of this line, 
                     * * but we still can't find the cursor_p.
                     */
                    if (bs->end_line)
                    {
                        /* 
                         * This is the last line of the whole text, we should set the cursor
                         * at the front of the NULL, not the last unit.
                         */
                        cursor_p = g_editor_line.line_start_p + g_editor_line.line_char_count * ENCODING_LENGTH;
                    }
                    else
                    {
                        cursor_p = g_editor_line.line_char[g_editor_line.cur_read].c_info.data_ptr;
                    }

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/ 
                    if (d == 3)
                    {                       
                        if (gui_check_multi_line_cursor_validation_for_wcss(b, bs, cursor_p))
                            b->cursor_p = cursor_p;                       
                    }
                    else   
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/                         
                        b->cursor_p = cursor_p;

                    bs->find_new_cursor_flag = FOUND_CURSOR;
                    found = 1;
                }
            }
            else
#endif
            {
                if (g_editor_line.cur_read + 1 >= g_editor_line.line_unit_count)
                {
                    /*
                     * the current character is the last one of this line, 
                     * * but we still can't find the cursor_p. 
                     */
                    if (bs->end_line)
                    {
                        /* 
                         * This is the last line of the whole text, we should set the cursor
                         * at the front of the NULL, not the last unit.
                         */
                        cursor_p = g_editor_line.line_start_p + g_editor_line.line_char_count * ENCODING_LENGTH;
                    }
                    else
                    {
                        cursor_p = g_editor_line.line_char[g_editor_line.cur_read].c_info.data_ptr;
                    }

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
                    if (d == 3)
                    { 
                        if (gui_check_multi_line_cursor_validation_for_wcss(b, bs, cursor_p))
                            b->cursor_p = cursor_p;
                    }
                    else    
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/  
                        b->cursor_p = cursor_p;

                    bs->find_new_cursor_flag = FOUND_CURSOR;
                    found = 1;
                }
            }
        }

        if (found == 1)
        {
        #if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
            if (d == 3 && b->locate_cursor_callback != NULL)
            {
                b->locate_cursor_callback(
                    b->text,
                    b->cursor_p,
                    (S32) (b->cursor_p - b->text - b->previous_shared_bytes + (b->start_id) * GUI_PAGE_SIZE * ENCODING_LENGTH),
                    b->text_length);
            }
        #endif /* defined(__UI_PAGING_IN_MULTILINE_EDITOR__) */ 
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_handle_multi_line_cursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_handle_multi_line_cursor(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, height;
    U8 show_cursor = 0;
    S32 cx2 = bs->x2, cy2 = bs->y2 - bs->border_y;
    S32 line_x, line_x2, line_y;
    U16 character_width = g_editor_line.line_char[g_editor_line.cur_read].c_info.adv_x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bs->find_new_cursor_flag == FINDING_CURSOR)
    {
        gui_find_multi_line_cursor_position(b, bs);
        return;
    }

    if (g_editor_line.cursor_line_flag)
    {
        if (g_editor_line.cur_read == g_editor_line.cursor_unit_index)
            show_cursor = 1;

        if (g_editor_line.cursor_unit_index == g_editor_line.line_unit_count)
        {
            if (!g_editor_line.bidi_done_flag)
            {
                if (g_editor_line.line_unit_count == g_editor_line.cur_read + 1)
                    show_cursor =  2;
            }
#ifdef __MMI_BIDI_ALG__
            else
            {
                if (g_editor_line.cur_v_read == g_editor_line.visual_unit_count - 1)
                    show_cursor = 2;
            }
#endif
        }

        if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW)
            && !(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
        {
            if (show_cursor)
            {
                x = (g_editor_line.line_unit_count == 0)? bs->xtx + b->text_gap : bs->xtx;//no char, +gap, gap pixel form the border
                y = bs->yty;
                height = g_editor_line.line_height;

                if(bs->flags & UI_MULTI_LINE_INPUT_BOX_DRAW_UNDERLINE)
                    height -= 1;

                if (g_mmi_wgui_halfline_marquee_scroll_enable)
                    y = bs->y1;

                if (show_cursor == 2)
                    x = bs->xtx + character_width + 1;

                /* show cursor */
                gui_multi_line_input_box_show_cursor(b, x, y, height, bs->x1, bs->y1, cx2, cy2);
            }
        }

        if (show_cursor)
        {
            /* update cursor information */

            b->cursor_x = (show_cursor == 1) ? bs->xtx : bs->xtx + character_width + 1;

            if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
            {
                line_x = b->x + b->text_x;
                line_x2 = line_x + b->width - 1;
                line_y = bs->yty + g_editor_line.line_height - 1;
                if (line_y < b->y + b->height)
                {
                    gdi_draw_line(
                        line_x,
                        line_y,
                        line_x2,
                        line_y,
                        gdi_act_color_from_rgb(255, b->underline_color.r, b->underline_color.g, b->underline_color.b));
                }

            #if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
                if (b->underline_callback != NULL)
                    b->underline_callback(
                        b->text,
                        (S32) (b->cursor_line_p - b->text - b->previous_shared_bytes + (b->start_id) * GUI_PAGE_SIZE * ENCODING_LENGTH),
                        g_editor_line.line_char_count);
            #endif /* defined(__UI_PAGING_IN_MULTILINE_EDITOR__) */ 
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_draw_multi_line_single_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                       [?]         
 *  bs                      [?]         
 *  current_character       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_multi_line_single_character(
        multi_line_input_box *b,
        multi_line_input_box_show_struct *bs,
        UI_character_type current_character)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 current_line_height = g_editor_line.line_height;
    U16 character_width = g_editor_line.line_char[g_editor_line.cur_read].c_info.adv_x;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(UI_STRING_END_OF_STRING_CHARACTER(current_character) ||
          UI_TEST_LF_CHARACTER(current_character) ||
          UI_TEST_CR_CHARACTER(current_character) || UI_TEST_ESC_CHARACTER(current_character)))
    {
        /* USAT */
        if ((bs->rich_text).draw_text_bg_color)
        {
            gui_fill_rectangle(
                bs->xtx,
                bs->yty - 1,
                bs->xtx + character_width,
                bs->yty + current_line_height - 1,
                bs->rich_text.curr_text_bg_color);
        }

        gui_draw_multi_line_text(b, bs);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  gui_draw_multi_line_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_multi_line_text(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_lm_show_cluster_param lm_show_param;
    S32 upper_addition;
    mmi_lm_cluster_info_p prev_cluster = NULL;

#ifdef __MMI_BIDI_ALG__
    U8 *mirror_buffer, *original_buffer;
    UI_character_type current_character, mirror_character, backup_character;
    S32 i, len;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_ONLY_SHOW_FIRST_LINE))
    {
#ifdef  __MMI_EDITOR_MULTILINE_SUPPORT_96_64_STYLE__

        upper_addition = 0;

#else /*__MMI_EDITOR_MULTILINE_SUPPORT_96_64_STYLE__*/

        upper_addition = EDITOR_LINE_UPPER_PIXTEL; 

#endif/*__MMI_EDITOR_MULTILINE_SUPPORT_96_64_STYLE__*/
    }
    else
    {
        upper_addition = 0;
    }

    lm_show_param.cluster= &g_editor_line.line_char[g_editor_line.cur_read].c_info;
    if (g_editor_line.cur_read)
        prev_cluster = &g_editor_line.line_char[g_editor_line.cur_read - 1].c_info;
    lm_show_param.prev_cluster = prev_cluster;
    lm_show_param.x = bs->xtx;
    lm_show_param.y = bs->yty + upper_addition;
    lm_show_param.baseline = g_editor_line.line_ascent - upper_addition;
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_USE_BORDER_FONT
        || bs->rich_text.curr_border)
        lm_show_param.bordered = 1;
    else
        lm_show_param.bordered = 0;

#ifdef __MMI_BIDI_ALG__
    if (g_editor_line.bidi_done_flag 
        && g_editor_line.line_unit_count > 0
        && g_editor_line.line_char_count > 0
        && lm_show_param.cluster->data_len == 1
        && (g_editor_line.line_char[g_editor_line.cur_read].char_type != MASK_CHAR))
    {
        mirror_buffer = &g_editor_line.visual_str[0];
        original_buffer = lm_show_param.cluster->data_ptr;

        for (i=0; i<g_editor_line.cur_v_read; i++)
        {
            len = g_editor_line.line_char[g_editor_line.visual_to_logic_map[i]].c_info.data_len;
            mirror_buffer += len * ENCODING_LENGTH;
        }


        UI_STRING_GET_NEXT_CHARACTER(mirror_buffer, mirror_character);
        UI_STRING_GET_NEXT_CHARACTER(original_buffer, current_character);

        if (mirror_character != current_character)
        {
            backup_character = lm_show_param.cluster->display_buffer[0];
            lm_show_param.cluster->display_buffer[0] = mirror_character;
            mmi_lm_draw_cluster(&lm_show_param);
            lm_show_param.cluster->display_buffer[0] = backup_character;
        }
        else
            mmi_lm_draw_cluster(&lm_show_param);

    }
    else
    {
        mmi_lm_draw_cluster(&lm_show_param);
    }
#else
    mmi_lm_draw_cluster(&lm_show_param);
#endif /*__MMI_BIDI_ALG__*/

    return;
}


/*****************************************************************************
 * FUNCTION
 *  gui_end_multi_line_text_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_end_multi_line_text_display(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
    U32 height_previous_page = 0;
    U32 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    if (!gui_inputs_cache_is_valid() 
        || b->cache_update_type == GUI_INPUT_BOX_CACHE_UPDATE_ALL)
#endif /* GUI_INPUT_BOX_CACHE_SUPPORT */
    {
        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
        {
            if (bs->check_flag <= PAGE_THREE)
            {
                /* the all text is less than four buffer, should set the last page information */
                for (i = 0; i < bs->check_flag; i++)
                    height_previous_page += b->page_details[i].page_height;

                b->page_details[bs->check_flag].shared_no_of_bytes = 0;
                b->page_details[bs->check_flag].page_id = b->start_id + bs->check_flag;
                b->page_details[bs->check_flag].page_height = bs->total_page_height - height_previous_page;
            }
        }
    }
#endif /* defined(__UI_PAGING_IN_MULTILINE_EDITOR__) */ 

    /* update the line count */
    b->n_lines = bs->line_counter;

    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_FIXED_TEXT_AREA)
    {
        bs->x1 = bs->backup_x1;
        bs->x2 = bs->backup_x2;
    }

    /* Set global font to default because rich_text.curr_font is local variable released dynamically. */
    gui_set_font(b->text_font);
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_scroll_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multi_line_scroll_bar(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        gui_set_vertical_scrollbar_scale(&b->vbar, b->edit_height);
        gui_set_vertical_scrollbar_range(&b->vbar, 0);
        gui_set_vertical_scrollbar_value(&b->vbar, 0);
        return;
    }

#ifdef __UI_LINEBASE_IN_MULTILINE_EDITOR__
	if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE)
    {
        if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
        {
            gui_update_multi_line_linebase_scrollbar(b);
        }
        return;
    }
#endif

#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
    {
        if (b->jump_offset_from_app != 0 && b->search_flag_is_on)
        {
            b->text_offset_y += 40;
            if (b->text_offset_y > 0)
                b->text_offset_y = 0;

            if ((bs->flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT) 
                && b->highlight_start_position != NULL
                && b->hilite_str_number == 0)
            {
                if (b->highlight_end_y >= b->y + b->height)
                    b->text_offset_y = b->curr_hilite_text_offset_y;
            }
        }

        /* begin steven ebook */
        if (-b->text_offset_y == b->text_height && b->text_height > b->edit_height_displayed_lines)
        {
            b->text_offset_y += b->edit_height_displayed_lines;
        }
        /* end steve ebook */
        b->page_offset = 0;
        b->jump_offset_from_app = 0;

        if (b->size_of_total_data < GUI_PAGE_SIZE * 4)
        {
            gui_set_vertical_scrollbar_scale(&b->vbar, b->edit_height);
        }
        else
        {
            gui_set_vertical_scrollbar_scale(&b->vbar, 1);
        }

        bs->rich_text.curr_font.bold = bs->rich_text.curr_font.italic = 0;
    }
    else
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 
    {
        gui_set_vertical_scrollbar_scale(&b->vbar, b->edit_height);

        /* if content is empty, don't show the scrollbar */
        if (b->text_length <= 1 * ENCODING_LENGTH && b->header_height <= 0 && b->footer_height <= 0)
            gui_set_vertical_scrollbar_range(&b->vbar, 0);
        else
            gui_set_vertical_scrollbar_range(&b->vbar, b->text_height);

        gui_set_vertical_scrollbar_value(&b->vbar, -b->text_offset_y);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_multi_line_scroll_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_multi_line_scroll_bar(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_EDITOR_SCROLLBAR_STYLE__
    gdi_handle layer;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))    /* if not disable draw then do .. */
    {
        gui_pop_clip();

#ifdef __MMI_FTE_EDITOR_SCROLLBAR_STYLE__
        gdi_layer_get_active(&layer);
        gui_vertical_scrollbar_set_alpha_blend_layer(&b->vbar, layer);
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
        gdi_push_and_set_alpha_blending_source_layer(bs->scr_layer);
#endif
        if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR) && (bs->edit_width > 0))
        {
            if (bs->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR)
            {
                if (b->vbar.scale != 0 && (b->vbar.scale < b->vbar.range))
                {
                    if (mmi_fe_get_r2l_state())
                    {
                        /* move vertical scrollbar to the left side, +1 for left side boarder */
                        gui_move_vertical_scrollbar(&b->vbar, b->x + 1, b->vbar.y);
                    }

                    gui_show_vertical_scrollbar(&b->vbar);
                    b->scrollbar_state = 1;
                }
                else
                {
                    b->scrollbar_state = 0;
                }
            }
            else
            {
                if (mmi_fe_get_r2l_state())
                {
                    /* move vertical scrollbar to the left side */
                    gui_move_vertical_scrollbar(&b->vbar, b->x, b->vbar.y);
                }

                gui_show_vertical_scrollbar(&b->vbar);
                b->scrollbar_state = 1;
            }
        }
        else
        {
            b->scrollbar_state = 0;
        }

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
        gdi_pop_and_restore_alpha_blending_source_layer();
#endif
    }
#if defined(__MMI_EDITOR_FORCE_AUTO_SCROLLBAR__)
	else
    {
        if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR) && (bs->edit_width > 0))
        {
            if (bs->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR)
            {
                if (b->vbar.scale != 0 && (b->vbar.scale < b->vbar.range))
                {
                    b->scrollbar_state = 1;
                }
                else
                {
                    b->scrollbar_state = 0;
                }
            }
            else
            {
                b->scrollbar_state = 1;
            }
        }
        else
        {
            b->scrollbar_state = 0;
        }
    }
#endif /* __MMI_EDITOR_FORCE_AUTO_SCROLLBAR__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_update_multi_line_extern_module_infomation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_update_multi_line_extern_module_infomation(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
#ifdef __MMI_UI_DALMATIAN_EDITOR__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width, image_height, x, y;
    PU8 img_p;
#endif /* __MMI_UI_DALMATIAN_EDITOR__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    if (GetMessagesCurrScrnID() == SCR_ID_MSG_WRITE)
    {
        g_nsm_msg_context.UCS2_count = b->UCS2_count;   /* To fix outbox edit bug */
        g_nsm_msg_context.textlength = b->text_length;
    }

    if ((GetExitScrnID() == SCR_ID_MSG_OUTBOX_MSG) && (mmi_nsm_get_msg_type() == PICTURE_MESSAGE))
    {
        g_nsm_msg_context.UCS2_count = b->UCS2_count;   /* To fix outbox SEND bug */
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#ifdef __MMI_UI_DALMATIAN_EDITOR__
    if (!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_DISABLE_DALMATIAN_EDITOR))
    {
        if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW)
            && !(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
        {
            S32 draw_dal_image = 1;

            if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) &&
                b->header_callback && (b->header_height > 0) && (b->text_offset_y + b->header_height >= 0))
            {
                draw_dal_image = 0; /* Not to draw image when image insert in editor. */
            }

            /* Draw Dalmatian editor image */
            if (b->height >= 100)   /* To draw image according to screen size. */
            {
                gui_measure_image(get_image(IMG_EDITOR_DALMATIAN), &image_width, &image_height);
            }
            else
            {
                gui_measure_image(get_image(IMG_EDITOR_DALMATIAN_SMALL), &image_width, &image_height);
            }

            /* The image will be drawn if the editor height is 25% more than image height */
            if (image_height > (b->height - (image_height >> 2)))
            {
                draw_dal_image = 0;
            }

            if (draw_dal_image && b->text_length <= 2 && (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)) &&
                (0 == b->footer_height))
            {
                if (b->height >= 100)
                {
                    img_p = get_image(IMG_EDITOR_DALMATIAN);
                }
                else
                {
                    img_p = get_image(IMG_EDITOR_DALMATIAN_SMALL);
                }

                if (!mmi_fe_get_r2l_state())
                {
                    x = b->x + b->width - (b->vbar.width + image_width + 2);
                }
                else
                {
                    x = b->x + (b->vbar.width + 2);
                }

                y = b->y + b->height - (image_height + 4);

                gui_show_image((U16) x, (U16) y, img_p);
            }
        }
    }
#endif /* __MMI_UI_DALMATIAN_EDITOR__ */ 

#if defined(__MMI_SMART_MESSAGE_MT__)
    /* Update ucs2 flag when entering outbox msg */
    if ((GetMessagesCurrScrnID() == SCR_ID_NSM_EDITOR) ||
        ((GetExitScrnID() == SCR_ID_MSG_OUTBOX_MSG) && (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)))
    {
        picmsg_text_struct.ucs2_count = b->UCS2_count;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_draw_multi_line_under_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_multi_line_under_line(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 line_x, line_x2, line_y, line_y_end;
    S32 line_jump = gui_inputs_get_char_info_for_all_lang(b->text_font->size, NULL, NULL) + EDITOR_LINE_ADDITION_PIXTEL;
    /* use this theme only after 07B*/
    gdi_color line_color = gdi_act_color_from_rgb(255, 
                current_MMI_theme->inputbox_base_line_color->r, current_MMI_theme->inputbox_base_line_color->g, current_MMI_theme->inputbox_base_line_color->b);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->min_line_height > 0)
    {
#ifdef __MMI_FTE_EDITOR_SCROLLBAR_STYLE__
        gui_push_clip();
        if (b->normal_filler->flags & UI_FILLED_AREA_SINGLE_BORDER)
            gui_set_clip(b->x+1, b->y, b->x + b->width - 2, b->y + b->height - 1);
        else
            gui_set_clip(b->x, b->y, b->x + b->width - 1, b->y + b->height - 1);
#endif
        line_y = bs->yy + bs->ty + line_jump - 1;
        line_y_end = bs->y1 + b->text_y + bs->border_y + b->edit_height - 1;

        if (b->footer_height > 0 && (line_y_end > bs->yy + bs->ty))
            line_y_end = bs->yy + bs->ty;

        /* we always draw line in whole area, only depeonds on the clipping area is correct */
        line_x = b->x;
        line_x2 = b->x + b->width - 1;

        while (line_y <= line_y_end && line_y < b->y)
            line_y += line_jump;    /* loop until line_y is visible */

        while (line_y <= line_y_end)
        {
            gdi_draw_line(line_x, line_y, line_x2, line_y, line_color);
            line_y += line_jump;
        }
#ifdef __MMI_FTE_EDITOR_SCROLLBAR_STYLE__
        gui_pop_clip();
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_draw_multi_line_callback_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_multi_line_callback_area(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ty + b->footer_height will become b->text_height */
    if (b->min_text_height > 0 && bs->ty + b->footer_height < b->min_text_height)
    {
        bs->ty = b->min_text_height - b->footer_height;
    }

    if (b->max_empty_text_height > 0 && !b->text[0] && !b->text[1])
    {
        bs->ty = b->header_height + b->max_empty_text_height;
    }

    /* Draw header region */
    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && b->header_callback)
    {
        /* Not overlapped with single-pixel border */
        b->header_callback(
            (MMI_BOOL) ((b->header_height > 0) && (b->text_offset_y + b->header_height > 0)),
            bs->yy,
            b->header_height,
            bs->x1 + b->margin.left_margin,
            bs->y1 + b->margin.top_margin,
            bs->x2 - b->margin.right_margin,
            bs->y2 - b->margin.down_margin);
    }

    /* Draw footer region */
    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && b->footer_callback)
    {
        /* Not overlapped with single-pixel border */
        b->footer_callback(
            (MMI_BOOL) ((b->footer_height > 0) && (b->text_offset_y + bs->ty < b->edit_height)),
            bs->yy + bs->ty,
            b->footer_height,
            bs->x1 + b->margin.left_margin,
            bs->y1 + b->margin.top_margin,
            bs->x2 - b->margin.right_margin,
            bs->y2 - b->margin.down_margin);
    }

    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW)
        && b->text != NULL)
    {
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        if ((!gui_inputs_cache_is_valid()) 
            || (gui_mlc_total_line_count() > 0))
#endif
        {
            gui_pop_text_clip();
            gui_pop_clip();
        }
    }
    
    /* Draw left region */
    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && b->left_callback)
    {
        /* Not overlapped with single-pixel border */
        b->left_callback(
            (MMI_BOOL) ((b->left_height > 0) && (b->text_offset_y + b->left_height > 0)),
            bs->yy,
            b->left_height,
            bs->x1 - b->left_width, bs->y1 + 1, bs->x1, bs->y2 - 1);
    }
    
    /* Draw right region */
    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && b->right_callback)
    {
        /* Not overlapped with single-pixel border */
        b->right_callback(
            (MMI_BOOL) ((b->right_height > 0) && (b->text_offset_y + b->right_height > 0)),
            bs->yy,
            b->right_height,
            bs->x2 + 1, bs->y1 + 1, bs->x2 + b->right_width, bs->y2 - 1);
    }
    
    if (b->max_line_height > 0)
    {
        if (b->text_length == 0)
        {
            b->max_line_height = 0;
        }
        else if ((b->text != NULL) && (b->text[0] == 0 && b->text[1] == 0))
        {
            b->max_line_height = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_adjust_multi_line_text_offset_y
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_adjust_multi_line_text_offset_y(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_d;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_ONLY_SHOW_FIRST_LINE)
    {
        b->text_offset_y = 0;
        return;
    }

    temp_d = b->text_offset_y + bs->ty;

    if (bs->find_new_cursor_flag == FOUND_CURSOR)
    {
        b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    }

    /* View mode condition added. Nov-19, TESTFIX   */
    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
        && !(bs->flags & UI_MULTI_LINE_INPUT_BOX_STATE_DISABLED)
        && !(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
    {
        if (temp_d < bs->edit_height)
        {
        #if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
            if (GetMessagesCurrScrnID() == SCR_ID_MSG_WRITE)
            {
                b->text_offset_y += 15;
            }
            else
        #endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 
                b->text_offset_y += (bs->edit_height - temp_d);
            if (b->text_offset_y > 0)
            {
                b->text_offset_y = 0;
            }
        }
    }

    /* if not view mode then adjust the view point by cursor position */

#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
    if (! (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE && bs->adjust_view)
        && !(b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
        && !(b->ext_flags &GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR))
#else
    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
        && !(b->ext_flags &GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR))
#endif
    {
#ifdef __MMI_EDITOR_SSP_SUPPORT__        
        if (gui_input_box_ssp_get_state() == GUI_INPUT_BOX_SSP_STATE_UNFOCUS)
#endif
        {
            if (bs->cursor_line_height == 0)
                bs->cursor_line_height = g_editor_line.line_height;
            
            if (bs->edit_height <= bs->cursor_line_height)
            {
                if (b->text_offset_y != -b->cursor_y)
                    StopTimer(BLINKING_CURSOR);
                
                b->text_offset_y = -b->cursor_y;
                
            }
            else if ((b->cursor_y + bs->cursor_line_height + b->text_offset_y) > bs->edit_height &&
                bs->edit_height > bs->cursor_line_height)
            {
                b->text_offset_y = -(b->cursor_y + bs->cursor_line_height - bs->edit_height);
                StopTimer(BLINKING_CURSOR);
            }
            else if ((b->cursor_y + b->text_offset_y) < 0)
            {
                b->text_offset_y = -(b->cursor_y);
                StopTimer(BLINKING_CURSOR);
            }
        }
    }

#ifndef __MMI_FTE_EDITOR_SCROLLBAR_STYLE__
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE
        && !(b->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR
		     && b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW)
        && !(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_FIXED_Y_OFFSET)
        && !(b->flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU))
#else
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE
        && !(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_FIXED_Y_OFFSET)
        && !(b->flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU))
#endif

    {
        if (b->text_offset_y < b->edit_height - b->text_height)
        {
            b->text_offset_y = b->edit_height - b->text_height;
        }
        
        if( b->text_offset_y >0) 
            b->text_offset_y = 0;
    }
}
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
/*****************************************************************************
 * FUNCTION
 *  gui_check_multi_line_cursor_validation_for_wcss
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_check_multi_line_cursor_validation_for_wcss(multi_line_input_box *b, multi_line_input_box_show_struct *bs, UI_buffer_type cursor_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cursor_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (b->predefine_char_pos != NULL)
    {

        cursor_offset = (cursor_p - b->text)/ENCODING_LENGTH;
        if (!gui_multi_line_input_box_test_cursor_pos(b, cursor_offset))
           return 0;
    }

    return 1;
}
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/


#ifdef  __UI_ENHANCED_HILITE_IN_MULTILINE_EDITOR__
/*****************************************************************************
* FUNCTION
*  gui_set_multi_line_hilite_format
* DESCRIPTION
*  
* PARAMETERS
*  b       [?]     
*  bs      [?]     
* RETURNS
*  void
*****************************************************************************/
void gui_set_multi_line_hilite_format(multi_line_input_box *b, multi_line_input_box_show_struct *bs, U16 hilite_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 format_flag;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(b->hilite_list != NULL);
    if (b->hilite_format_list[hilite_idx].format_flag != 0)
    {
        format_flag = b->hilite_format_list[hilite_idx].format_flag;
            
        if (format_flag & GUI_MULTI_LINE_INPUT_HILITE_TEXT_COLOR)
        {
            UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR(b->hilite_format_list[hilite_idx].text_color);
        }
    }
}
#endif

U8 gui_get_char_type_by_lm_lang(mmi_lm_lang_enum id)
{
    U8 rtn = SINGLE_CHAR;
    
    switch (id)
    {
    case MMI_LM_LANG_NONE:
        rtn = SINGLE_CHAR;
        break;
        
    case MMI_LM_LANG_THAI:
        rtn = THAI_CLUSTER;
        break;

    case MMI_LM_LANG_ARABIC:
        rtn = SINGLE_CHAR;
        break;

    case MMI_LM_LANG_INDIC:
        rtn = INDIC_CLUSTER;
        break;

    case MMI_LM_LANG_ARMENIAN:
        rtn = OTHER_CLUSTER;
        break;

    case MMI_LM_LANG_OTHERS:
        rtn = SINGLE_CHAR;
        break;

    default:
        ASSERT (0);
        break;
    }

    return rtn;
}

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
/*****************************************************************************
* FUNCTION
*  gui_jump_multi_line_paging_visible_area
* DESCRIPTION
*  
* PARAMETERS
*  b       [?]      
* RETURNS
*  void
*****************************************************************************/
S32 gui_jump_multi_line_paging_visible_area(multi_line_input_box *b)
{
    S32 n, max, y;
    input_box_all_line_struct *line_info;

    if (b->page_offset > 0 || b->jump_offset_from_app > 0)
    {
        max = b->page_offset > b->jump_offset_from_app ? b->page_offset : b->jump_offset_from_app;
        n = gui_mlc_character_line_index_find(max);
        if (n<0)
            n = 0;

        y = gui_mlc_line_cache_one_line_offset_y(n);
        b->text_offset_y = -(b->header_height+b->header_gap + y);
        b->page_offset = 0;
        b->jump_offset_from_app = 0;

        line_info = gui_mlc_line_info_get(n);
        b->text_offset = line_info->start_offset / ENCODING_LENGTH;
        return 1;
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  gui_calculate_multi_line_paging_information
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multi_line_paging_visible_information(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 current_line_height;
    S32 header_visual_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_line_height = g_editor_line.line_height;
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
    {
        header_visual_height = b->text_offset_y + b->header_gap + b->header_height;
        if (header_visual_height < 0)
        {
            header_visual_height = 0;
        }

        /** to determine the height of the currently displayed window.if condition is taken here to get the current **/
        if (bs->total_page_height + b->header_gap + b->header_height >= -(b->text_offset_y)
            && (bs->total_page_height + b->header_gap + b->header_height < (-(b->text_offset_y) + bs->edit_height))
            && header_visual_height + b->edit_height_displayed_lines + current_line_height <= bs->edit_height)
        {

            if (bs->total_page_height + b->header_gap + b->header_height == -b->text_offset_y)
            {
                if (b->text_offset_y == -(b->header_gap + b->header_height))
                {
                    b->text_offset = 0;
                }
                else
                {
                    b->text_offset = bs->char_count;
                }
            }
            if (bs->total_page_height + b->header_gap + b->header_height > -b->text_offset_y
                && bs->total_page_height + b->header_gap + b->header_height - (-b->text_offset_y) < bs->previous_line_height)
            {
                b->text_offset = bs->char_count;
            }
            
            if (bs->char_count == 0 && -b->text_offset_y <= b->header_gap + b->header_height)
                b->text_offset = bs->char_count;

            bs->total_page_height += current_line_height;
            b->edit_height_displayed_lines += current_line_height;
            b->current_page_count += g_editor_line.line_char_count;
        }
        else
        {
            bs->total_page_height += current_line_height;
        }

        bs->char_count += g_editor_line.line_char_count;  /* for every line ,char_count is incermented by the no of containing in that line */


        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR
             && (bs->ty + b->text_offset_y + current_line_height > 0) && bs->locate_cursor == 0)
        {
            b->cursor_p = g_editor_line.line_start_p;
            bs->locate_cursor = 1;
        }
    }
}

#endif

/*****************************************************************************
* FUNCTION
*  gui_preset_multi_line_visible_line
* DESCRIPTION
*  
* PARAMETERS
*  b       [?]     
*  bs      [?]     
* RETURNS
*  void
*****************************************************************************/
S32 gui_preset_multi_line_visible_line(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    input_box_all_line_struct *line_info;
   
    /* set the start line to the visible start line */
    gui_mlc_visible_start_line_get(&bs->sl);
    gui_mlc_visible_end_line_get(&bs->el);
    
    bs->current_text_p = b->text + bs->sl.offset;
    bs->ty += bs->sl.offset_y;
    bs->line_counter = bs->sl.index;
    
    if(bs->sl.index > 0)
    {
        line_info = gui_mlc_line_info_get(bs->sl.index - 1);
        g_editor_line.line_height = line_info->line_height;
        g_editor_line.line_width = line_info->line_width;
        g_editor_line.line_start_p = b->text + line_info->start_offset;
        g_editor_line.line_char_count = line_info->char_count;

#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
        bs->total_page_height = gui_mlc_line_cache_one_line_offset_y(bs->sl.index);
        bs->char_count = bs->sl.offset / ENCODING_LENGTH;
#endif
    }
    
    return 1;
}


/*****************************************************************************
* FUNCTION
*  gui_set_multi_line_highlight_information
* DESCRIPTION
*  
* PARAMETERS
*  b       [?]     
*  bs      [?]     
* RETURNS
*  void
*****************************************************************************/
void gui_set_multi_line_highlight_information(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type backup_text_p = bs->current_text_p;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<g_editor_line.line_unit_count; i++)
    {
        g_editor_line.line_char[i].highlight_flag = (U8)gui_check_multi_line_character_highlight(b, bs, (U16)i);
        if (g_editor_line.highlight_flag == 0 && g_editor_line.line_char[i].highlight_flag)
            g_editor_line.highlight_flag = 1;

        if (bs->flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS)
        {
            if(g_editor_line.line_char[i].char_type == SINGLE_CHAR && g_editor_line.line_char[i].highlight_flag == 0)
                g_editor_line.line_char[i].char_type = MASK_CHAR;
        }

        bs->current_text_p += g_editor_line.line_char[i].c_info.data_len * ENCODING_LENGTH;
    }

    bs->current_text_p = backup_text_p;
}


/*****************************************************************************
 * FUNCTION
 *  gui_prepare_multi_line_one_line_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_prepare_multi_line_one_line_context(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_x;
    input_box_all_line_struct *lf;
    input_box_visible_line_struct *vlf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bs->previous_line_height = g_editor_line.line_height;
    bs->draw_separator = FALSE;
    
    /* read line information from the line cache and visible line cache */
    lf = gui_mlc_line_info_get(bs->line_counter);
    vlf = gui_mlc_visible_info_get(bs->line_counter);
    gui_mlc_text_format_info_get(&bs->rich_text, bs->line_counter);

    bs->rich_text.line_begin_font = bs->rich_text.curr_font;
    bs->rich_text.line_begin_border = bs->rich_text.curr_border;
    bs->rich_text.line_begin_strikethrough= bs->rich_text.curr_strikethrough;
    bs->rich_text.line_begin_color = bs->rich_text.curr_color;

    /* set the line information to g_editor_line */
    g_editor_line.bidi_done_flag = 0;
    g_editor_line.cursor_line_flag = 0;
    
    g_editor_line.line_height = lf->line_height;
    g_editor_line.line_width = lf->line_width;
    g_editor_line.line_ascent = lf->line_ascent;
    g_editor_line.line_dscent = lf->line_dscent;
    g_editor_line.line_start_p = b->text + lf->start_offset;

    g_editor_line.highlight_flag = vlf->highlight_flag;
    g_editor_line.line_unit_count = vlf->line_unit_count;
	g_editor_line.line_char_count = vlf->line_char_count;
    g_editor_line.marker_flag = vlf->marker_flag;
    g_editor_line.override_flag = vlf->override_flag;
    /* g_editor_line.line_char = vlf->line_char; */
    g_editor_line.line_char = temp_line_char;
    memcpy(g_editor_line.line_char, vlf->line_char, sizeof (gui_editor_character_unit_struct) * vlf->line_unit_count);

    gui_set_font(&(bs->rich_text.curr_font));
    UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR(bs->rich_text.curr_color);

    bs->tx = 0;
    if (bs->line_counter == b->n_lines - 1)
        bs->end_line = 1;
    
    if (bs->rich_text.curr_alignment == GUI_INPUT_ALIGN_CENTER)
    {
        bs->tx = ((bs->edit_width >> 1) - (g_editor_line.line_width >> 1));
        if (bs->tx < 0)
        {
            bs->tx = 0;
        }
    }
    else if (bs->rich_text.curr_alignment == GUI_INPUT_ALIGN_RIGHT)
    {
        bs->tx = bs->edit_width - g_editor_line.line_width;
        if (bs->tx < 0)
        {
            bs->tx = 0;
        }
    }
    else
    {
        if (bs->default_direction == BIDI_L)
            bs->tx = 0;
#ifdef __MMI_BIDI_ALG__/**/       
        else
        {
            temp_x = (bs->x2 - b->text_x - b->text_offset_x) - g_editor_line.line_width;
            bs->tx = temp_x - bs->x1;
            if (bs->tx < 0)
            {
                bs->tx = 0;
            }
        }
#endif /*__MMI_BIDI_ALG__*/            
    }

    bs->current_text_p = g_editor_line.line_start_p;
    
    /* set the current line y offset */
    bs->yty = bs->yy + bs->ty;

    gui_set_multi_line_highlight_information(b, bs);
}


/*****************************************************************************
 * FUNCTION
 *  gui_find_multi_line_cursor_from_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]     
 *  bs      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_find_multi_line_cursor_from_cache(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index, line_index, cursor_y;
    input_box_all_line_struct *lf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (bs->find_new_cursor_flag)
        return;

    index = (b->cursor_p - b->text) / ENCODING_LENGTH;

    do
    {
        line_index = gui_mlc_character_line_index_find(index);
        if (line_index < 0)
        {
            if (gui_inputs_cache_is_not_in_update())
            {
                line_index = 0;
                break;
            }
            else
            {
                gui_mlc_partial_line_update();
            }
        }

    }while(line_index < 0);

    cursor_y = gui_mlc_line_cache_one_line_offset_y(line_index);
    b->cursor_y = cursor_y + b->header_height + b->header_gap;
    lf = gui_mlc_line_info_get(line_index);
    bs->cursor_line_height = lf->line_height;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  gui_save_multi_line_visible_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]     
 *  bs      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_save_multi_line_visible_info(multi_line_input_box *b, multi_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL backup_end = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    
#ifdef __UI_LINEBASE_IN_MULTILINE_EDITOR__ /**/   
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE)
    {
        backup_end = b->line_info->b_to_end;
        if (g_editor_line.line_start_p - b->text + g_editor_line.line_char_count*ENCODING_LENGTH < b->text_length)
            b->line_info->b_to_end = (MMI_BOOL)bs->end_line;
    }
#endif /*__UI_LINEBASE_IN_MULTILINE_EDITOR__*/ /**/   
        
    /* Half line visible also counter */
    if (bs->yty + g_editor_line.line_height/2 >= (bs->yy - b->text_offset_y)
        && bs->yty + g_editor_line.line_height/2 <= (bs->yy - b->text_offset_y + bs->edit_height))
    {
        b->visible_end_ex = (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH
            + g_editor_line.line_char_count;
        if (b->visible_start_ex < 0)
            b->visible_start_ex = (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH;
    }

    if (bs->yty >= (bs->yy - b->text_offset_y)
                && bs->yty + g_editor_line.line_height <= (bs->yy - b->text_offset_y + bs->edit_height))
    {
        b->visible_end = (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH
            + g_editor_line.line_char_count;
        if (b->visible_start < 0)
            b->visible_start = (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH;

#ifdef __UI_LINEBASE_IN_MULTILINE_EDITOR__ /**/
        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE)
        {
            if (b->force_stop_line_index >= 0)
            {
                /* force stop if destination line reached */
                if (b->force_stop_line_index < b->line_info->start_line_index + b->line_info->line_count)
                {
                    bs->end_line = 1;
                    return 0;
                }
            }

            b->line_info->array[b->line_info->line_count].offset = 
                (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH;
            b->line_info->line_height[b->line_info->line_count] = g_editor_line.line_height;
            b->line_info->line_count++;

            if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
            {
                *(b->visible_line_info) = *(b->line_info);
            }
            
            /* Save last line offset info as the text length */
            if (b->line_info->start_line_index + b->line_info->line_count == b->total_line_count)
            {
                b->line_info->array[b->line_info->line_count].offset = (b->text_length / ENCODING_LENGTH - 1);
            }
        }
#endif /*__UI_LINEBASE_IN_MULTILINE_EDITOR__*/ /**/
    }
    else
    {
#ifdef __UI_LINEBASE_IN_MULTILINE_EDITOR__ /**/
        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE)
        {
            if (b->line_info->line_count > 0)
            {
                /* the view area is beyond the current visible area */
                if (b->force_stop_line_index < 0)
                {
                    /* Save one more line to caculate visible area character count */
                    b->line_info->b_to_end = backup_end;
                    b->line_info->array[b->line_info->line_count].offset = 
                        (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH;
                    b->line_info->line_height[b->line_info->line_count] = g_editor_line.line_height;
                    
                    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
                    {
                        *(b->visible_line_info) = *(b->line_info);
                    }

                    bs->end_line = 1;
                    return 0;
                }
                else
                {
                    if (b->force_stop_line_index < b->line_info->start_line_index + b->line_info->line_count)
                    {
                        bs->end_line = 1;
                        return 0;
                    }
                    
                    b->line_info->array[b->line_info->line_count].offset = 
                        (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH;
                    b->line_info->line_height[b->line_info->line_count] = g_editor_line.line_height;
                    b->line_info->line_count++;
                }
            }
        }
        else 
#endif /*__UI_LINEBASE_IN_MULTILINE_EDITOR__*/ /**/            
        {
            if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_ONLY_VISIBLE_LINE)
        {
            if (bs->yty >= (bs->yy - b->text_offset_y))
            {
                bs->end_line = 1;
                return 0;
            }
        }
    }
    }

#ifdef __UI_LINEBASE_IN_MULTILINE_EDITOR__ /**/
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE)
    {
        if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW)
            && (b->line_info->start_line_index + b->line_info->line_count > b->total_line_count))
        {
            bs->end_line = 1;
           return 0;
        }
    }
#endif /*__UI_LINEBASE_IN_MULTILINE_EDITOR__*/ /**/   
    
    return 1;
}


#ifdef __UI_LINEBASE_IN_MULTILINE_EDITOR__
/*****************************************************************************
 * FUNCTION
 *  gui_update_multi_line_linebase_scrollbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_update_multi_line_linebase_scrollbar(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_vertical_scrollbar_range(&b->vbar, b->total_line_count);

    if (b->visible_line_info->b_to_end
        || (b->visible_line_info->start_line_index + b->visible_line_info->line_count >= b->total_line_count))
    {
        if (b->visible_line_info->line_count >= b->total_line_count)
        {
            gui_set_vertical_scrollbar_scale(&b->vbar, b->total_line_count);
        }
        else
            gui_set_vertical_scrollbar_scale(&b->vbar, b->visible_line_info->line_count);

            gui_set_vertical_scrollbar_value(&b->vbar, b->total_line_count - 1);
    }
    else
    {
        gui_set_vertical_scrollbar_scale(&b->vbar, b->visible_line_info->line_count);
        gui_set_vertical_scrollbar_value(&b->vbar, b->visible_line_info->start_line_index);
    }
}
#endif /* __UI_LINEBASE_IN_MULTILINE_EDITOR__ */

