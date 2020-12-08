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
 *   gui_ems.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   EMS editor - UI component
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#undef GUI_INPUTBOX_ALIGNMENT_WHEN_EXIST_R2L_CHAR

//#include "SettingProfile.h"
//#include "mmi_frm_gprot.h"
#include "gui_inputs.h"
#include "gui_ems.h"
//#include "WguiCategoryGprot.h"
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/

#include "LangModuleGProt.h"

#include "gui_touch_feedback.h"

/* for R2L characters */
#include "BIDIDEF.h"
//#include "BIDIProt.h"

#include "gui_inputs_internal.h"

#include "SmsSrvGprot.h"

//#include "Mdi_datatype.h"
#include "Mdi_audio.h"

    #include "MMIDataType.h"
    #include "gui_data_types.h"
    #include "gui_theme_struct.h"
    #include "FontRes.h"
    #include "PixcomFontEngine.h"
    #include "kal_general_types.h"
    #include "ems.h"
    #include "gui_config.h"
    #include "MMI_features.h"
    #include "string.h"
    #include "gui.h"
    #include "gui_scrollbars.h"
    #include "gui_themes.h"
    #include "CustThemesRes.h"
    #include "ps_public_enum.h"
    #include "kal_public_api.h"
    #include "Unicodexdcl.h"    
    #include "mmi_frm_timer_gprot.h"
    #include "gdi_datatype.h"
    #include "mmi_frm_input_gprot.h"
    #include "wgui_categories_util.h"
    #include "device.h"
    #include "gdi_include.h"
    #include "gui_typedef.h"
    #include "wgui_inputs.h"
    #include "gdi_const.h"
    #include "mmi_frm_history_gprot.h"
    #include "MMI_fw_trc.h"
    #include "mmi_fw_trc.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "wgui_categories_res.h"
    #include "mmi_frm_events_gprot.h"
    #include "mmi_cb_mgr_gprot.h"
    #include "Gsm7BitNationalLang.h"
    #include "lcd_sw_inc.h"
    #if defined(__MMI_MULTITAP_BANGLA_SPEC__)
#include "IndicEngineGprot.h"
#endif
    #include "ImeGprot.h"

#include "wgui_categories_inputs.h"

#include "mmi_rp_app_uiframework_def.h"

#ifdef UI_EMS_SUPPORT

/* for R2L characters */
extern BOOL r2lMMIFlag;
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))
extern U8 mtkmultitap_ire_bengali_ndicator;
static U8 to_decide_to_reshuffle = 0;
#endif
#ifdef __MMI_BIDI_ALG__
extern U8 visual_str[];
extern U8 MMI_bidi_input_type;
#endif /* __MMI_BIDI_ALG__ */ 

/* MTK Steven 20050505 */
#ifdef __MMI_LANG_THAI__
#define isThaiChar(ch)  (((ch >= 0x0E01) && (ch <= 0x0E7F))? (1):(0))
#endif 
/* MTK End */

extern void StopTimer(U16 nTimerId);
extern U8 mmi_msg_get_seg_num(void);
extern S32 UI_cursor_x1;    /* cursor x1 postioon */
extern S32 UI_cursor_y1;    /* cursor y1 position */
extern S32 UI_cursor_x2;    /* cursor x1 postioon */
extern S32 UI_cursor_y2;    /* cursor y1 position */
extern void UI_draw_horizontal_line(S32 x1, S32 x2, S32 y, color c);


/* PMT START URDU */
#ifdef __MMI_ARSHAPING_ENGINE__
#include "ArabicGProt.h"
#endif 

#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
extern U16 shaping_str[MAX_TEXT_LENGTH * BIDI_ENCODING_LENGTH];
extern U16 OrgToSha[MAX_TEXT_LENGTH * BIDI_ENCODING_LENGTH];
extern S32 unshaped_text_len;
extern S32 shaped_text_len;
#endif /* #if defined(__MMI_BIDI_ALG__) */

/* PMT END LANGUAGE 20060104 */
#define EMS_SHOW_HORIZONTAL_RULE_FOR_NEWLINE       0
/* START PMT NEERAJ 20050916 */
#define EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES        1
/* END PMT NEERAJ 20050916 */
#define EMS_ENABLE_EDITOR_OBJECT_PLAYBACK          0
#define EMS_PREVENT_CRLF_DISPLAY                1
#define EMS_USE_CRLF_COMBINATION                1
#define EMS_USE_ESC_COMBINATION                    1
#define EMS_USE_GSM_EXTENDED                    0
#define EMS_ENABLE_GRAPHICAL_CURSOR_MOVEMENT       1
#define EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER        0x0A
#define EMS_ENABLE_SPECIAL_FONT_DISPLAY               1
#define EMS_HEADER_SCROLL_SIZE                     20
#define EMS_ENABLE_TESTFIX_OBJECT_ORDERING            1
#define EMS_DEFAULT_DCS_ALLOCATED_LENGTH           mmi_msg_get_seg_num() * 153
#define EMS_UCS2_DCS_ALLOCATED_LENGTH              mmi_msg_get_seg_num() * 67

#if defined(__MMI_MESSAGES_CONCAT_SMS__)
#define EMS_DEFAULT_DCS_AVAILABLE_LENGTH           mmi_msg_get_seg_num() * 153
#define EMS_UCS2_DCS_AVAILABLE_LENGTH              mmi_msg_get_seg_num() * 67
#else /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 
#define EMS_DEFAULT_DCS_AVAILABLE_LENGTH           160
#define EMS_UCS2_DCS_AVAILABLE_LENGTH              70
#endif /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 

UI_EMS_input_box_theme *current_EMS_input_box_theme = NULL;
stFontAttribute UI_EMS_inputbox_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
stFontAttribute UI_EMS_inputbox_medium_font = {0, 0, 0, MEDIUM_FONT, 0, 0};

MMI_BOOL g_ems_is_disable_show = MMI_FALSE;
MMI_BOOL g_ems_is_disable_sound = MMI_FALSE;

#ifdef __MMI_DIALLING_FONT__
stFontAttribute UI_EMS_inputbox_large_font = {0, 0, 0, MEDIUM_FONT, 0, 0};
#else 
stFontAttribute UI_EMS_inputbox_large_font = {0, 0, 0, LARGE_FONT, 0, 0};
#endif 
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
U8 saved_last_skip_pos = 0;
U8 ems_cursor_pos_flag = 0;
U8 no_objects_adjusted = 0;
/* PMT START MAUI_00027731 */
//code removed
/* PMT END MAUI_00027731 */
/* PMT START MAUI_00024993 */
U8 donot_call_cancel =0;
/* PMT END MAUI_00024993 */
extern U8 add_template_ems_flag;
#endif /*__MMI_INDIC_ALG__*/
/*PMT IRE END*/
stFontAttribute UI_EMS_inputbox_current_font = {0, 0, 0, MEDIUM_FONT, 0, 0};
color UI_EMS_inputbox_text_color = {0, 0, 0, 100};
EMSALIGNMENT UI_EMS_current_alignment = EMS_ALIGN_LEFT;
EMSALIGNMENT lastest_EMS_alignment = EMS_ALIGN_LEFT;
U8 UI_EMS_strikethrough = 0;

#if defined(__MMI_EDITOR_SSP_SUPPORT__) && defined(__MMI_MESSAGES_EMS__)
static U8 in_scrolling_flag = 0;
#endif

static __inline MMI_BOOL gui_ems_test_extention_character(UI_character_type c);
static __inline MMI_BOOL gui_ems_test_gsm_character(UI_character_type c);


#if(EMS_DISPLAY_SPECIAL_CHARACTERS)

/* Temporary data for debugging  */
const U8 EMS_CR_display_character[] = 
{
    0x04, 0x00, 0xAF, 0x00, 0x00, 0x00,
    0x09, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0C, 0x12, 0x00, 0x00, 0x00,
    0x34, 0x12, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
    0x34, 0x12, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
    0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x20,
    0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0xFF, 0xFF, 0xFF, 0xFF,
    0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0xFF, 0xFF,
    0xFF, 0xFF, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
    0x04, 0x20, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
    0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
    0x34, 0x12, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
    0x34, 0x12,
};

const U8 EMS_LF_display_character[] = 
{
    0x04, 0x00, 0xAF, 0x00, 0x00, 0x00,
    0x09, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0C, 0x12, 0x00, 0x00, 0x00,
    0x34, 0x12, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00,
    0x34, 0x12, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00,
    0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0xC0, 0x00,
    0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00,
    0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xFF, 0xFF,
    0xFF, 0xFF, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00,
    0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00,
    0x34, 0x12, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00,
    0x34, 0x12,
};

const U8 EMS_ESC_display_character[] = 
{
    0x04, 0x00, 0xAF, 0x00, 0x00, 0x00,
    0x09, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0C, 0x12, 0x00, 0x00, 0x00,
    0x34, 0x12, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F,
    0x34, 0x12, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F,
    0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0xFF, 0xFF, 0x42, 0x1F, 0x42, 0x1F,
    0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0xFF, 0xFF,
    0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F,
    0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F,
    0x34, 0x12, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F,
    0x34, 0x12,
};

#endif /* (EMS_DISPLAY_SPECIAL_CHARACTERS) */ 

#if(!UI_DISABLE_EMS_INPUT_BOX)
EMSObjData UI_EMS_normal_text_format_object_data;
EMSObject UI_EMS_normal_text_format_object;

#ifdef __MMI_MESSAGES_EMS__
extern void EMS_cancel_object_focus(void);
extern U16 EMS_predefined_animations[];
#endif /* __MMI_MESSAGES_EMS__ */ 
#define EMS_DATA_END_OFFSET(x)   ((x))

/* Basic Latin,Latin 1,Latin Extended A, Latin Extended B */
/* Cyrillic */
/* Latin Extended Additional  */
/* Combining Marks  */
/* Basic Arabic  */
/* Arabic Presentation Forms-A */
/* Arabic Presentation Forms-B */
#define UI_MULTI_LINE_INPUT_BOX_ALPHABETIC_CHARACTER(c)                                                              \
   (( ((UI_character_type)(c)>=(UI_character_type)0x2180) && ((UI_character_type)(c)<=(UI_character_type)0x9FAF) )?0:1) // only CJK will not word wrapping

#ifdef __MMI_EDITOR_SSP_SUPPORT__
static void gui_ems_ssp_update_client(void *user_data, S32 offset);
static void gui_ems_ssp_get_client_info(
                void *user_data, 
                S32 *total_offset, 
                S32 *cur_offset,
                S32 *move_type);
#endif

#define GUI_EMS_INPUTBOX_HEIGHT_EXTRA_GAP       4

static void gui_EMS_input_box_scroll_down(UI_EMS_input_box *b);
static void gui_EMS_input_box_scroll_up(UI_EMS_input_box *b);

#ifdef __UI_EMS_HIGHLIGHT_LIST_SUPPORT__
static EMSObject* gui_EMS_input_box_get_text_hilite_object(UI_EMS_input_box *b, U16 idx);
static MMI_BOOL gui_EMS_input_box_is_hilite_in_visible_range(UI_EMS_input_box *b, U16 hilite_idx);
static S32 gui_EMS_input_box_find_first_hilite_in_visible_range(UI_EMS_input_box *b);
static S32 gui_EMS_input_box_find_last_hilite_in_visible_range(UI_EMS_input_box *b);
#endif

#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_change_input_mode_for_smart_Abc
 * DESCRIPTION
 *  change input mode from smart abc to smart Abc
 * PARAMETERS
 *  b       [IN]        UI_EMS_input_box object
 * RETURNS
 *  MMI_BOOL true -> changed to Abc , false--> else
 *****************************************************************************/
MMI_BOOL gui_EMS_input_box_change_input_mode_for_smart_Abc(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type pre_ch = 0, pre2_ch = 0;
    UI_character_type separator[] = {'.','!','?',0x00};
    U8 idx = 0;
    EMSPosition mapped_cursor_position;
    EMSData *data = b->data;
    EMSObject *current_object;
    U8 object_type;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_current_input_mode != INPUT_MODE_SMART_LOWERCASE_ABC)
    {
        return MMI_FALSE;
    }


    EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
    object_type = gui_EMS_input_box_get_previous_object(data, &mapped_cursor_position, &pre_ch, &current_object);
    if (1 == object_type)
    {
        if(pre_ch != (UI_character_type)0x20)
        {
            return MMI_FALSE;
        }

    }
    else
    {
        return MMI_FALSE;
    }
    
    object_type = gui_EMS_input_box_get_previous_object(data, &mapped_cursor_position, &pre2_ch, &current_object);
    if (1 == object_type)
    {
        while(pre2_ch != separator[idx])
        {
            if(((UI_character_type)0x00) == separator[idx])
            {
                return MMI_FALSE;
            }
            idx++;
        }
    }
    else
    {
        return MMI_FALSE;
    }    

    
    MMI_current_input_mode = INPUT_MODE_SMART_FIRST_UPPERCASE_ABC;
    change_EMS_inputbox_mode(INPUT_MODE_SMART_FIRST_UPPERCASE_ABC);
    wgui_EMS_redraw_input_information_bar();
    return MMI_TRUE;

}
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_intialize_EMS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_intialize_EMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_EMS_normal_text_format_object.Type = EMS_TYPE_TEXT_FORMAT;
    UI_EMS_normal_text_format_object.next = NULL;
    UI_EMS_normal_text_format_object.prev = NULL;
    UI_EMS_normal_text_format_object.OffsetToText = 0;
    UI_EMS_normal_text_format_object.data = &UI_EMS_normal_text_format_object_data;
    ResetTextFormat(&UI_EMS_normal_text_format_object.data->text_format);
#ifdef __MMI_MESSAGES_TEXT_FORMAT_ALIGN_LEFT__
    UI_EMS_normal_text_format_object.data->text_format.Alignment = EMS_ALIGN_LEFT;
#else 
    UI_EMS_normal_text_format_object.data->text_format.Alignment = EMS_ALIGN_LANG_DEP;
#endif 
}
/* PMT START MAUI_00027731 */
/*****************************************************************************
 * FUNCTION
 *  gui_show_EMS_input_box_find_segment_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/

U8* gui_show_EMS_input_box_find_segment_start(EMSData *data,U8* end)
{
    EMSObject *obj;
    S32 end_index = end - data->textBuffer;
    S32 start_index = 0;
    if(end_index <0 || end_index > data->textLength ) return end; // just for safe. it should be assert !

    for(obj = data->listTail; obj && obj->OffsetToText >= end_index;obj = obj->prev)
        ;

    if(obj && obj->OffsetToText < end_index)
        start_index = obj->OffsetToText;


    return data->textBuffer + start_index;
}
/*****************************************************************************
 * FUNCTION
 *  gui_show_EMS_input_box_find_segment_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/

U8* gui_show_EMS_input_box_find_segment_end(EMSData *data,U8* start)
{
    EMSObject *obj;
    S32 start_index = start - data->textBuffer;
    S32 end_index = data->textLength ; 
   if(start_index <0 || start_index > end_index) return start; // just for safe. it should be assert !
    
    for(obj = data->listHead; obj && obj->OffsetToText <= start_index;obj = obj->next)
        ;

    if(obj && obj->OffsetToText > start_index)
        end_index = obj->OffsetToText;


    return data->textBuffer + end_index;
}
/* PMT END MAUI_00027731 */
/*****************************************************************************
 * FUNCTION
 *  gui_set_EMS_input_box_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_EMS_input_box_theme(UI_EMS_input_box *b, UI_EMS_input_box_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_filler = t->normal_filler;
    b->disabled_filler = t->disabled_filler;
    b->selected_filler = t->selected_filler;
    b->normal_text_color = t->normal_text_color;
    b->selected_text_color = t->selected_text_color;
    b->selection_color = t->selection_color;
    b->cursor_color = t->cursor_color;
    b->boundary_color = t->boundary_color;  /* Pixtel - Gurinder - 3/14/2004 - Editor With BG Image */
    b->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_EMS_input_box_current_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_EMS_input_box_current_theme(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_filler = current_EMS_input_box_theme->normal_filler;
    b->disabled_filler = current_EMS_input_box_theme->disabled_filler;
    b->selected_filler = current_EMS_input_box_theme->selected_filler;
    b->normal_text_color = current_EMS_input_box_theme->normal_text_color;
    b->selected_text_color = current_EMS_input_box_theme->selected_text_color;
    b->selection_color = current_EMS_input_box_theme->selection_color;
    b->cursor_color = current_EMS_input_box_theme->cursor_color;
    b->boundary_color = current_EMS_input_box_theme->boundary_color;    /* Pixtel - Gurinder - 3/14/2004 - Editor With BG Image */
    b->flags |= current_EMS_input_box_theme->flags;
}

extern S16 MMI_current_input_ext_type;


/*****************************************************************************
 * FUNCTION
 *  gui_create_EMS_input_box
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [?]         
 *  x           [IN]        
 *  y           [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_EMS_input_box(UI_EMS_input_box *b, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(b, 0, sizeof(UI_EMS_input_box));

    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->flags = 0;
    b->last_cursor_offset = -1;
    MMI_current_input_ext_type = 0;
    gui_set_EMS_input_box_current_theme(b);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    gui_create_vertical_scrollbar(
        &b->vbar,
        b->x + b->width - current_EMS_input_box_theme->vbar_width - 1,
        b->y + 1,
        current_EMS_input_box_theme->vbar_width,
        b->height - 2);

#ifdef __MMI_FTE_EDITOR_SCROLLBAR_STYLE__
    gui_vertical_scrollbar_enable_clear_background(&b->vbar, MMI_FALSE);
#endif
    
#if defined(__MMI_EDITOR_FORCE_AUTO_SCROLLBAR__)
    b->flags |= UI_EMS_INPUT_BOX_AUTO_DISABLE_SCROLLBAR;
#endif

    b->data = NULL;
    b->start_position.Object = NULL;
    b->start_position.OffsetToText = 0;
    b->end_position.Object = NULL;
    b->end_position.OffsetToText = 0;
    b->display_y = 0;
    ResetTextFormat(&b->text_format);
/*PMT IRE START*/
#if defined(__MMI_INDIC_ALG__)
    /*Resetting required in Indic Engine when EMS input box is created */
    ire_reset_use_multitap();
#endif 
/*PMT IRE END*/
    b->text_format.Alignment = UI_EMS_normal_text_format_object.data->text_format.Alignment;
    b->saved_cursor_ax = -1;
    b->underline_color = gui_color(0, 0, 128);
    b->strikethrough_color = gui_color(192, 0, 0);

    /* use this theme only after 07B*/
    b->paragraph_color = *(current_MMI_theme->inputbox_ems_cr_base_line_color); 
    
    b->locate_cursor_flag = 1;
    b->show_action_flag = 1;

#ifdef __MMI_TOUCH_SCREEN__
    b->pen_scroll_after_delay = -1;
    b->pen_scroll_delay_time = 100;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __SMS_R8_NATION_LANGUAGE__
    memset(&b->ems_auto_dection, 0, sizeof(mmi_7bit_auto_detection_struct));
#endif

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_inputs_cache_create(b);
#endif /* GUI_INPUT_BOX_CACHE_SUPPORT */

#ifdef __MMI_EDITOR_SSP_SUPPORT__
    gui_input_box_ssp_set_client_callback(
        gui_ems_ssp_update_client, 
        gui_ems_ssp_get_client_info, 
        b);
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */

    gui_inputs_register_cursor_callback();
}

#if(EMS_USE_DCS)


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_change_DCS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_change_DCS(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->UCS2_count > 0)
    {
        gui_EMS_input_box_set_dcs(b, SMSAL_UCS2_DCS);

    #if defined(__MMI_MESSAGES_CONCAT_SMS__)
        b->available_length = b->data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num() >> 1;
    #else 
        b->available_length = EMS_UCS2_DCS_AVAILABLE_LENGTH;
    #endif 
    }
    else
    {
        gui_EMS_input_box_set_dcs(b, SMSAL_DEFAULT_DCS);

    #if defined(__MMI_MESSAGES_CONCAT_SMS__)
        b->available_length = b->data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num();
    #else 
        b->available_length = EMS_DEFAULT_DCS_AVAILABLE_LENGTH;
    #endif 
    }
}

#endif /* (EMS_USE_DCS) */ 


/*****************************************************************************
 * FUNCTION
 *  gui_set_EMS_input_box_compare_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  p1      [?] 
 *  p2      [?]
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_set_EMS_input_box_compare_position(UI_EMS_input_box *b, EMSPosition *p1, EMSPosition *p2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT (p1 != NULL && p2 != NULL);

    if (p1->OffsetToText != p2->OffsetToText)
    {
        return p1->OffsetToText - p2->OffsetToText;
    }
    else
    {
        if (p1->Object == p2->Object)
            return 0;

        if (p1->Object == NULL)
        {
            return -1;
        }
        else if (p2->Object == NULL)
        {
            return 1;
        }
        else
        {
            p = b->data->listHead;
            
            while (p)
            {
                if (p == p1->Object)
                    return -1;
                
                if (p == p2->Object)
                    return 1;
                
                p = p->next;
            }
            
            return 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_EMS_input_box_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  d       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_EMS_input_box_data(UI_EMS_input_box *b, EMSData *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *text_format_object;
    U8 done = 0, dcs = 0;
    EMSPosition current_position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->data = d;
    if (d == NULL)
    {
        return;
    }

    dcs = d->dcs;
    /* ResetCurrentPosition(b->data); */
    b->UCS2_count = 0;
    b->object_count = 0;
    b->GSM_ext_count = 0;

    /* [NOTE]: In case the DCS is wrong, like the message dcs is UCS2, 
       but it contains extension characters, we'll remove extension char first when set data */
    if (dcs == SMSAL_UCS2_DCS)
    {
        gui_EMS_input_box_remove_extension_character(b, b->data);
    }

#if(EMS_USE_DCS)
    if ((b->data->textLength > 0) || (b->data->listHead != NULL))
    {
        U8 r;
        EMSPosition p = b->data->CurrentPosition;
        EMSObject *current_object;
        UI_character_type c;

        p.OffsetToText = 0;
        p.Object = NULL;
        while (!done)
        {
            r = gui_EMS_input_box_get_next_object(d, &p, &c, &current_object);
            switch (r)
            {
                case 0:
                    done = 1;
                    break;
                case 1:             
                    if (gui_ems_test_UCS2_character(c))
                    {
                        b->UCS2_count++;
                    }
                    if (gui_ems_test_extention_character(c))
                    {
                        b->GSM_ext_count++;
                    }

#ifdef __SMS_R8_NATION_LANGUAGE__
                    mmi_7bit_update_character_type(&b->ems_auto_dection, c, MMI_TRUE);
#endif
                    break;
                case 2:
                    b->object_count++;
                    break;
            }
        }
    }


#ifdef __SMS_R8_NATION_LANGUAGE__    
    if (!(b->flags & UI_EMS_INPUT_BOX_VIEW_MODE))
    {
        EMSNationalLanguage l1;
        EMSPosition old_cursor_position = b->data->CurrentPosition;
        

        mmi_7bit_get_national_lang_table(&l1);
        EMSSetNationalLanguageandCancelRedundancy(b->data, &l1);
        if (gui_set_EMS_input_box_compare_position(b, &old_cursor_position, &b->data->CurrentPosition) < 0)
        {
            MoveCursorToPosition(b->data, &old_cursor_position);
        }
    }

    if (!(b->flags & UI_EMS_INPUT_BOX_VIEW_MODE))
    {
        gui_ems_table_mechanism_enum cur_m;
        EMSNationalLanguage l1, l2;

        cur_m = mmi_7bit_get_table_mechanism();
        if (cur_m == EMS_AUTO_DETECTION && b->UCS2_count == 0)
        {
            mmi_7bit_choose_national_table(&b->ems_auto_dection, &l1);
            mmi_7bit_get_national_lang_table(&l2);
            
            if (l1.locking_shift != l2.locking_shift
                || l1.single_shift != l2.single_shift)
            {
                gui_EMS_input_box_remove_extension_character(b, b->data);
                mmi_7bit_set_national_lang_table(&l1);
                gui_EMS_input_box_insert_extension_character(b, b->data);

                if (EMSSetNationalLanguage(b->data, &l1) != EMS_OK)
                {
                    /* the table can't be set into EMS lib, restore tables */
                    gui_EMS_input_box_remove_extension_character(b, b->data);
                    mmi_7bit_set_national_lang_table(&l2);
                    gui_EMS_input_box_insert_extension_character(b, b->data);
                    EMSSetNationalLanguage(b->data, &l2);
                }
                
            }
        }
    }
#endif
    if (!(b->flags & UI_EMS_INPUT_BOX_VIEW_MODE))
    {
        gui_EMS_change_DCS(b);

        if (dcs == SMSAL_UCS2_DCS && b->data->dcs == SMSAL_DEFAULT_DCS)
        {
            /* the dcs has been change from UCS2 to default */
            gui_EMS_input_box_insert_extension_character(b, b->data);
        }
    }
#endif /* (EMS_USE_DCS) */ 

    current_position.OffsetToText = 0;
    current_position.Object = NULL;
    text_format_object = GetTextFormatObjectAtPosition(b->data, &current_position);
    if (text_format_object != NULL)
    {
        b->text_format = text_format_object->data->text_format;
    }
    
    b->saved_cursor_ax = -1;
}


/*****************************************************************************
 * FUNCTION
 *  EMS_get_remaining_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 EMS_get_remaining_length(EMSData *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->dcs == SMSAL_DEFAULT_DCS)
#if defined(__MMI_MESSAGES_CONCAT_SMS__)
        return (data->Reminder.totalRemainingOctet -
                (data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num() -
                 data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num()));
#else /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 
        return (data->Reminder.totalRemainingOctet -
                (EMS_DEFAULT_DCS_ALLOCATED_LENGTH - EMS_DEFAULT_DCS_AVAILABLE_LENGTH));
#endif /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 
    else
#if defined(__MMI_MESSAGES_CONCAT_SMS__)
        return (data->Reminder.totalRemainingOctet -
                (data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num() -
                 data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num()));
#else /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 
        return (data->Reminder.totalRemainingOctet -
                ((EMS_UCS2_DCS_ALLOCATED_LENGTH << 1) - (EMS_UCS2_DCS_AVAILABLE_LENGTH << 1)));
#endif /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 
}

/* Mude Lin(MBJ06016) Add For SMS Remaining Count Display In EMS Editor*/
#ifdef __MMI_MESSAGES_EMS_REMAINING_COUNTER__
/*****************************************************************************
 * FUNCTION
 *  EMS_get_required_segment
 * DESCRIPTION
 *  Get the number of required segments to carry this EMS
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 EMS_get_required_segment(UI_EMS_input_box *input_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32)input_data->data->Reminder.requiredSegment;
}

/*****************************************************************************
 * FUNCTION
 *  EMS_get_last_segment_remaining_char
 * DESCRIPTION
 *  Get The number of remaining characters in last segment. 
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 EMS_get_last_segment_remaining_char(UI_EMS_input_box *input_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 RemainingChar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input_data->UCS2_count > 0)
    {
        RemainingChar = (S32)input_data->data->Reminder.segRemainingOctet / 2;
    }
    else
    {
        RemainingChar = (S32)input_data->data->Reminder.segRemainingOctet;
    }

    return RemainingChar;   
}
#endif /*__MMI_MESSAGES_EMS_REMAINING_COUNTER__*/

/*End Mude Lin(MBJ06016) Add*/


#ifdef __MMI_MESSAGES_EMS__


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_set_text_format_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  f       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_set_text_format_object(UI_EMS_input_box *b, EMSTextFormat *f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f != NULL)
    {
        b->text_format = *f;
    }
}
#endif /* __MMI_MESSAGES_EMS__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_locate_cursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_locate_cursor(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 box_height = b->height - GUI_EMS_INPUTBOX_HEIGHT_EXTRA_GAP;
    S32 cursory;
    S32 content_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!b->show_action_flag || (b->flags & UI_EMS_INPUT_BOX_STATE_DISABLED))
    {
        return;
    }

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    if (-b->display_y + box_height - b->header_height < b->cursor_ay
        && !gui_inputs_cache_is_not_in_update())
    {
        gui_emsc_partial_line_update();
    }
#endif
    
    b->flags |= UI_EMS_INPUT_BOX_DISABLE_DRAW;
    gui_show_EMS_input_box(b);
    b->flags &= ~UI_EMS_INPUT_BOX_DISABLE_DRAW;

    if (b->flags & UI_EMS_INPUT_BOX_DISPLAY_HEADER)
    {
        cursory = b->cursor_ay + b->header_height + 1;
        content_h = b->display_height + b->header_height + 1;
    }
    else
    {
        cursory = b->cursor_ay;
        content_h = b->display_height;
    }
/*    if (b->flags & UI_EMS_INPUT_BOX_DISPLAY_HEADER)
    {
        if ((b->cursor_ay + b->header_height) < (-b->display_y))
        {
            b->display_y = -b->cursor_ay - b->header_height;
        }
        else if ((b->cursor_ay + b->header_height + b->cursor_line_height) > ((-b->display_y) + (box_height)))
        {
            b->display_y -=
                (b->cursor_ay + b->cursor_line_height) - ((-b->display_y) + (box_height - b->header_height));
        }
        if (b->display_y > 0)
        {
            b->display_y = 0;
        }
    }
    else*/

    /* If content_h is 0, then DONOT adjust the display_y, EMS locate cursor function may be called by 
       resize or other function which the b->display_height is not correctly initialized (to be 0) */
    if (content_h > 0)
    {
        if (cursory < (-b->display_y) && b->cursor_line_height <= box_height)
        {
            b->display_y = -cursory;
        }
        else if ((cursory + b->cursor_line_height) > ((-b->display_y) + box_height))
        {
            b->display_y -= (cursory + b->cursor_line_height) - ((-b->display_y) + box_height);
        }
        if ((b->display_y + content_h) < box_height)
        {
            b->display_y = (box_height) - content_h;
        }
        if (b->display_y > 0)
        {
            b->display_y = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_reset_cursor_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_reset_cursor_position(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->data != NULL)
    {
        ResetCurrentPosition(b->data);
        gui_EMS_input_box_locate_cursor(b);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_get_previous_text_alignment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_get_previous_text_alignment(UI_EMS_input_box *b, EMSPosition *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 done = 0;
    UI_character_type c;
    EMSObject *o;
    U8 r;
    EMSPosition current_position = *p;
    U8 alignment = UI_EMS_normal_text_format_object.data->text_format.Alignment;
    EMSObject *pre_format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!done)
    {
        r = gui_EMS_input_box_get_previous_object(b->data, &current_position, &c, &o);
        switch (r)
        {
            case 0:
                done = 1;
                break;
            case 1:
                if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                {
                    pre_format = gui_ems_get_current_text_format_for_position(b->data, &current_position);
                    if (pre_format)
                    {
                        alignment = pre_format->data->text_format.Alignment;
                    }
                    done = 1;
                }
                break;
            case 2:
                if (o->Type == EMS_TYPE_TEXT_FORMAT)
                {
                    alignment = o->data->text_format.Alignment;
                }
                break;
        }
    }
    return (alignment);
}

/* Sets the alignment of the whole paragraph to the value specified.
   Starts from the given cursor position.
   The cursor position given must be at the first position on the paragraph   */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_set_paragraph_text_alignment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  p               [?]         
 *  alignment       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_set_paragraph_text_alignment(UI_EMS_input_box *b, EMSPosition *p, U8 alignment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 done = 0;
    UI_character_type c;
    EMSObject *o;
    U8 r, flag = 0;
    EMSPosition current_position = *p;
    EMSTextFormat tf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->data->CurrentTextFormatObj != NULL)
    {
        if (b->data->CurrentTextFormatObj->OffsetToText + 
            b->data->CurrentTextFormatObj->data->text_format.textLength > current_position.OffsetToText)
            flag = 1;
    }

    while (!done)
    {
        r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
        switch (r)
        {
            case 0:
                done = 1;
                if (flag == 0)
                {
                    if (b->data->CurrentTextFormatObj != NULL)
                    {
                        tf = UI_EMS_normal_text_format_object.data->text_format;
                        tf.Alignment = (EMSALIGNMENT) alignment;
                        tf.textLength = 60000;   /* to make EMS lib fail to add and merge the same format*/
                        AddTextAlignment(b->data, p->OffsetToText, &tf);
                        flag = 1;
                    }
                }
                break;
            case 1:
                if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                {
                    done = 1;
                }
                break;
            case 2:
                if (o->Type == EMS_TYPE_TEXT_FORMAT)
                {
                    o->data->text_format.Alignment = (EMSALIGNMENT) alignment;
                    tf = o->data->text_format;
                    tf.textLength = 60000;   /* to make EMS lib fail to add and merge the same format*/
                    AddTextAlignment(b->data, current_position.OffsetToText, &tf);
                    flag = 1;
#ifdef __MMI_INDIC_ALG__
                    /* PMT START MAUI_00027731 */
                    if (b->data->CurrentPosition.OffsetToText >= 4)
                    {
                        EMSObject *current_object;
                        EMSPosition position;
                        U16 next_object=0, previous_object=0;
                        UI_character_type ch = (b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 2]) 
                            | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 1] << 8);
                        position = b->data->CurrentPosition;
                        next_object=gui_EMS_input_box_get_next_object(b->data, &position, &c, &current_object);
                        position = b->data->CurrentPosition;
                        previous_object=gui_EMS_input_box_get_previous_object(b->data, &position, &c, &current_object);
                        
                        if(((next_object==1)&& (previous_object==1)) && ((IRE_IS_CHAR_TYPE_HALANT(ch)) || (ch == ZWJ)))
                        {
                            PU8 src_p = NULL, dest_p = NULL,prev_src_p = NULL, starting_p = NULL;
                            src_p = (b->data->textBuffer + b->data->CurrentPosition.OffsetToText);
                            if(gui_show_EMS_input_box_find_segment_start(b->data,src_p) > (b->data->textBuffer + b->previous_line_position.OffsetToText))
                            {
                                starting_p = gui_show_EMS_input_box_find_segment_start(b->data,src_p);
                            }
                            else
                            {
                                starting_p = (b->data->textBuffer + b->previous_line_position.OffsetToText);
                            }
                            prev_src_p = ire_get_prev_cluster_p(starting_p/*gui_show_EMS_input_box_find_segment_start(b->data,src_p)*/, src_p);
                            dest_p = ire_get_next_cluster_p(prev_src_p, gui_show_EMS_input_box_find_segment_end(b->data,prev_src_p));
                            b->data->CurrentPosition.OffsetToText += (dest_p - src_p);  
                        }
                    }
    #endif /* __MMI_INDIC_ALG__ */ 
                }
                break;
        }
    }
}

/* Checks if the cursor is at the beginning of a paragraph  */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_test_paragraph_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_test_paragraph_start(UI_EMS_input_box *b, EMSPosition *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 paragraph_flag = 0;
    UI_character_type c;
    EMSObject *o;
    U8 r;
    EMSPosition current_position = *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (TestFirstPosition(b->data, &current_position))
    {
        paragraph_flag = 1;
    }
    else
    {
        if (BackwardCurrentPosition(b->data, 1) == 1)
        {
            current_position = b->data->CurrentPosition;
            r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
            ForwardCurrentPosition(b->data, 1);
            if ((r == 1) && (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER))
            {
                paragraph_flag = 1;
            }
        }
    }
    return (paragraph_flag);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_set_text_format_cursor_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_set_text_format_cursor_position(UI_EMS_input_box *b)
{
#ifdef __MMI_MESSAGES_EMS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 done = 0;
    EMSPosition current_position;
    EMSObject *current_text_format_object;
    UI_character_type c;
    EMSObject *o, *t;
    U8 r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*if delete by smart IME input mode, don't replace the current format*/
    if (!(b->flags & UI_EMS_INPUT_BOX_INPUT_METHOD_MODE) &&
        !(b->flags & UI_EMS_INPUT_BOX_STATE_MULTITAP) &&
        !mmi_imc_is_clipboard_state())
    {
        b->text_format = UI_EMS_normal_text_format_object.data->text_format;
    }

    if (b->data == NULL)
    {
        return;
    }
    current_position = b->data->CurrentPosition;
    current_text_format_object = b->data->CurrentTextFormatObj;

    if ((current_text_format_object != NULL)
        && (current_position.OffsetToText >= current_text_format_object->OffsetToText)
        && (current_position.OffsetToText <=
            (current_text_format_object->OffsetToText + current_text_format_object->data->text_format.textLength))
        && !(b->flags & UI_EMS_INPUT_BOX_INPUT_METHOD_MODE))
    {
        b->text_format = current_text_format_object->data->text_format;
    }

    /* At the beginning of a paragraph ? Then locate the text alignment to be used   */
    if (gui_EMS_input_box_test_paragraph_start(b, &current_position) || current_position.OffsetToText == 0)
    {
        t = gui_ems_get_current_text_format_for_position(b->data, &current_position);
        
        while (!done)
        {
            r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
            switch (r)
            {
                case 0:
                    if (!(b->flags & UI_EMS_INPUT_BOX_INPUT_METHOD_MODE))
                    {
                        b->text_format.Alignment = UI_EMS_normal_text_format_object.data->text_format.Alignment;
                        if (t != NULL)
                            b->text_format.Alignment = t->data->text_format.Alignment;
                    }
                    done = 1;
                    break;
                case 1:
                    if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                    {
                        b->text_format.Alignment = UI_EMS_normal_text_format_object.data->text_format.Alignment;
                        if (t != NULL)
                            b->text_format.Alignment = t->data->text_format.Alignment;
                        done = 1;
                    }
                    break;
                case 2:
                    if (o->Type == EMS_TYPE_TEXT_FORMAT)
                    {
                        b->text_format.Alignment = o->data->text_format.Alignment;
                        done = 1;
                    }
                    break;
            }
        }
    }
    else
    {
        while (!done)
        {
            t = gui_ems_get_current_text_format_for_position(b->data, &current_position);
            r = gui_EMS_input_box_get_previous_object(b->data, &current_position, &c, &o);
            switch (r)
            {
                case 0:
                    done = 1;
                    break;
                case 1:
                    if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                    {
                        if (!(b->flags & UI_EMS_INPUT_BOX_INPUT_METHOD_MODE))
                        {
                            b->text_format.Alignment = UI_EMS_normal_text_format_object.data->text_format.Alignment;
                            if (t != NULL)
                                b->text_format.Alignment = t->data->text_format.Alignment;
                        }
                        
                        done = 1;
                    }
                    break;
                case 2:
                    if (o->Type == EMS_TYPE_TEXT_FORMAT)
                    {
                        b->text_format.Alignment = o->data->text_format.Alignment;
                        done = 1;
                    }
                    break;
            }
        }

    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_set_cursor_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_set_cursor_position(UI_EMS_input_box *b, EMSPosition *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->data != NULL)
    {
        ResetCurrentPosition(b->data);
        while (!
               ((b->data->CurrentPosition.OffsetToText == p->OffsetToText) &&
                (b->data->CurrentPosition.Object == p->Object)))
        {
            if (ForwardCurrentPosition(b->data, 1) != 1)
            {
                break;
            }
        }
        gui_EMS_input_box_locate_cursor(b);
    }
}

/* Macros for graphics functions */

extern stFontAttribute *UI_font;
extern U8 SetFont(stFontAttribute Font, U8 arrCount);

extern S32 UI_clip_x1, UI_clip_x2, UI_clip_y1, UI_clip_y2;
extern S32 UI_text_x, UI_text_y;


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_equal_text_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t1      [?]     
 *  t2      [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_equal_text_format(EMSTextFormat *t1, EMSTextFormat *t2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (t1->Alignment != t2->Alignment)
    {
        return (0);
    }
    if (t1->bgColor != t2->bgColor)
    {
        return (0);
    }
    if (t1->fgColor != t2->fgColor)
    {
        return (0);
    }
    if (t1->FontSize != t2->FontSize)
    {
        return (0);
    }
    if (t1->isBold != t2->isBold)
    {
        return (0);
    }
    if (t1->isItalic != t2->isItalic)
    {
        return (0);
    }
    if (t1->isStrikethrough != t2->isStrikethrough)
    {
        return (0);
    }
    if (t1->isUnderline != t2->isUnderline)
    {
        return (0);
    }
    if (t1->textLength != t2->textLength)
    {
        return (0);
    }
    return (1);
}

#define EMS_EQUAL_TEXT_FORMAT(t1,t2) (~(memcmp((t1),(t2),sizeof(EMSTextFormat)))
#define EMS_ESCAPE_CHARACTER  (27)


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_remove_extension_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_remove_extension_character(UI_EMS_input_box *b, EMSData *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 c, OffsetToText;
    U8 *textBuffer = data->textBuffer;
    U16 textBufferLength = data->textLength;
    EMSPosition currposition = data->CurrentPosition;
    kal_uint16 ret_char;
    EMSPosition dummyposition;
    EMSObject *ret_object, *backup_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (textBuffer == NULL)
    {
        return;
    }
    backup_object = data->CurrentPosition.Object;
    ResetCurrentPosition(data);
    /* if (data->dcs == SMSAL_DEFAULT_DCS ) 
       [NOTE]: Comment this like because in case the DCS is wrong, like the message dcs is UCS2, 
       but it contains extension characters, we'll remove extension char first when set data,
       so here we need allowed to remove extension character even the DCS is UCS2 */
    {
        while ((OffsetToText = data->CurrentPosition.OffsetToText) < textBufferLength)
        {
        #if(EMS_BYTE_ORDER_BIG_ENDIAN)
            c = (U16) (textBuffer[OffsetToText + 1] | (textBuffer[OffsetToText] << 8));
        #else 
            c = (U16) (textBuffer[OffsetToText] | (textBuffer[OffsetToText + 1] << 8));
        #endif 
            if (c == EMS_ESCAPE_CHARACTER)
            {
                dummyposition = data->CurrentPosition;
                while (EMSGetNextObject(data, &dummyposition, &ret_char, &ret_object) == 2)
                {
                    ForwardCurrentPosition(data, 1);
                    dummyposition = data->CurrentPosition;

                    if (ret_object->Type == EMS_TYPE_TEXT_FORMAT)
                    {
                        if (EMSGetPreviousObject(data, &dummyposition, &ret_char, &ret_object) == 1)
                        {
                            BackwardCurrentPosition(data, 1);
                            break;
                        }
                        dummyposition = data->CurrentPosition;
                    }
                }
                //changes by pawanjeet 080707
            #if(EMS_BYTE_ORDER_BIG_ENDIAN)
                if (ForwardCurrentPosition(data, 1) != 1)
                {
                    break;
                }
                CancelCurrentPosition(data, 1);
                if (OffsetToText < currposition.OffsetToText)
                {
                    currposition.OffsetToText--;

                    if (b->flags &UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)
                    {
                        b->input_mode_position.OffsetToText--;     
                        if (b->input_start_position.OffsetToText != data->CurrentPosition.OffsetToText)
                        {
                            b->input_start_position.OffsetToText -= ENCODING_LENGTH;
                        }
                    }
                }
                OffsetToText = data->CurrentPosition.OffsetToText;
                textBufferLength -= ENCODING_LENGTH;
            #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
                if (ForwardCurrentPosition(data, 1) != 1)
                {
                    break;
                }
                CancelCurrentPosition(data, 1);

                c = (U16) (textBuffer[data->CurrentPosition.OffsetToText] | (textBuffer[data->CurrentPosition.OffsetToText + 1] << 8));
                

                if (OffsetToText < currposition.OffsetToText)
                {
                    currposition.OffsetToText -= ENCODING_LENGTH;
                    
if (b->flags &UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)
                    {
                        b->input_mode_position.OffsetToText -= ENCODING_LENGTH;     
                        if (b->input_start_position.OffsetToText != data->CurrentPosition.OffsetToText)
                        {
                            b->input_start_position.OffsetToText -= ENCODING_LENGTH;
                        }
                    }
                }
                OffsetToText = data->CurrentPosition.OffsetToText;
                textBufferLength -= ENCODING_LENGTH;
            #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
                //changes by pawanjeet 080707
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
    currposition.Object = backup_object;
    MoveCursorToPosition(data, &currposition);
}

/* Call before EMSPack  */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_extension_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 gui_EMS_input_box_insert_extension_character(UI_EMS_input_box *b, EMSData *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 c, OffsetToText;
    U8 *textBuffer = data->textBuffer;
    U16 textBufferLength = data->textLength;
    EMSPosition currposition = data->CurrentPosition;
    kal_uint16 ret_char;
    EMSPosition dummyposition;
    EMSObject *ret_object, *backup_object;
    EMSTextFormat txt_fmt;
    S32 add_fmt = 0;
    U8 ret = EMS_OK;

#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    U8 ESC_string[] = {0x00, 0x1B};
#else 
    U8 ESC_string[] = {0x1B, 0x00};
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (textBuffer == NULL)
    {
        return ret;
    }

    backup_object = data->CurrentPosition.Object;
    ResetCurrentPosition(data);

    if (data->dcs == SMSAL_DEFAULT_DCS)
    {
        while ((OffsetToText = data->CurrentPosition.OffsetToText) < textBufferLength)
        {
        #if(EMS_BYTE_ORDER_BIG_ENDIAN)
            c = (U16) (textBuffer[OffsetToText + 1] | (textBuffer[OffsetToText] << 8));
        #else 
            c = (U16) (textBuffer[OffsetToText] | (textBuffer[OffsetToText + 1] << 8));
        #endif 
            if (gui_ems_test_extention_character(c))
            {
                dummyposition = data->CurrentPosition;
                while (EMSGetNextObject(data, &dummyposition, &ret_char, &ret_object) == 2)
                {
                    ForwardCurrentPosition(data, 1);
                    dummyposition = data->CurrentPosition;
                    
                    if (ret_object->Type == EMS_TYPE_TEXT_FORMAT)
                    {
                        if (EMSGetPreviousObject(data, &dummyposition, &ret_char, &ret_object) == 1)
                        {
                            if (data->CurrentTextFormatObj)
                            {
                                add_fmt = 1;
                                txt_fmt = data->CurrentTextFormatObj->data->text_format;
                                txt_fmt.textLength = 2;
                            }

                            BackwardCurrentPosition(data, 1);
                            break;
                        }
                        dummyposition = data->CurrentPosition;
                    }
                }

                if (add_fmt)
                {
                    ret = AddString(data, ESC_string, 1, &txt_fmt);
                    add_fmt = 0;
                    if (ret != EMS_OK)
                        break;
                }
                else
                {
                    EMSObject *t;

                    t = gui_ems_get_current_text_format_for_position(b->data, &data->CurrentPosition);
                    
                    if (t != NULL)
                    {
                        txt_fmt = t->data->text_format;
                    }
                    else
                    {
                        txt_fmt = UI_EMS_normal_text_format_object.data->text_format;
                        txt_fmt.textLength = 2;
                    }
                    ret = AddString(data, ESC_string, 1, &txt_fmt);
                    if (ret != EMS_OK)
                        break;
                }

                //changes by pawanjeet 080707
                if(OffsetToText < currposition.OffsetToText)
                {
                    currposition.OffsetToText += ENCODING_LENGTH;
                    
                    if (b->flags &UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)
                    {
                        b->input_mode_position.OffsetToText += ENCODING_LENGTH;     
                        b->input_start_position.OffsetToText += ENCODING_LENGTH;
                    }
                }
                //changes by pawanjeet 080707
                OffsetToText = data->CurrentPosition.OffsetToText;
                /* MTK Elvis 20031126 */
                textBufferLength += ENCODING_LENGTH;
                /* MTK end */
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
    currposition.Object = backup_object;
    MoveCursorToPosition(data, &currposition);

    return ret;
}

#if(EMS_USE_DCS)

#if(EMS_USE_CRLF_COMBINATION || EMS_USE_ESC_COMBINATION)

/* Deletes one object/character before cursor position and updates UCS2 and Object counters  */
/* Also handles CRLF combination                                              */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_cancel_current_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_cancel_current_position(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    EMSPosition pos;
#endif

/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/    
    S32 lst_pos = 0;
    S32 cancel_two_pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (TestLastPosition(b->data, &(b->data->CurrentPosition)))
    {
        lst_pos = 1;
    }
/*PMT IRE START*/
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 

    if (BackwardCurrentPosition(b->data, 1) == 1)
    {
        EMSPosition p = b->data->CurrentPosition;
        EMSObject *current_object;
        UI_character_type c;
        U8 r;
        S32 count;
        U8 dcs_change = 0;

        r = gui_EMS_input_box_get_next_object(b->data, &p, &c, &current_object);
/*PMT IRE START*/    
    #ifdef __MMI_INDIC_ALG__
        if (lst_pos)
        {
            /*If the character is CR & LF combination then put the value 0 at the place for these*/
            /*2 unicode values                                                                   */
            if (b->data->CurrentPosition.OffsetToText >= 4 &&
                UI_TEST_LF_CHARACTER(b->data->textBuffer[b->data->CurrentPosition.OffsetToText]) &&
                UI_TEST_CR_CHARACTER(b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 2]))
            {
                b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 2] = 0;
                b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 1] = 0;
                b->data->textBuffer[b->data->CurrentPosition.OffsetToText] = 0;
                b->data->textBuffer[b->data->CurrentPosition.OffsetToText + 1] = 0;
                cancel_two_pos = 1;

            }
        }
    #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
        ForwardCurrentPosition(b->data, 1);
        switch (r)
        {
            case 0:
                break;
            case 1:
        #if(EMS_USE_CRLF_COMBINATION)
                if (UI_TEST_LF_CHARACTER(c))
                {
                    count = BackwardCurrentPosition(b->data, 2);
                    if (count == 2)
                    {
                        p = b->data->CurrentPosition;
                        r = gui_EMS_input_box_get_next_object(b->data, &p, &c, &current_object);

                        if(r==2 && current_object->Type==EMS_TYPE_TEXT_FORMAT) // solved by pawanjeet , it should ignore the text format between LF CR
                            r = gui_EMS_input_box_get_next_object(b->data, &p, &c, &current_object);

                        if ((r == 1) && UI_TEST_CR_CHARACTER(c))
                        {
                            ForwardCurrentPosition(b->data, 2);
                            CancelCurrentPosition(b->data, 1);
                            count = 0;
                        }
                        else if (r == 1)
                        {
                            /* If New line symbol is 0x0A, we should reset the c to lf, or the
                               following update EMS_AUTO_DECTION structure will be wrong.*/
                            c = 0x0A;
                        }
                    }
                    ForwardCurrentPosition(b->data, (U16) count);
                }
                else
        #endif /* (EMS_USE_CRLF_COMBINATION) */ 
                if (gui_ems_test_UCS2_character(c))
                {
                    if (b->UCS2_count > 0)
                    {
                        b->UCS2_count--;
                        if (b->UCS2_count == 0)
                        {
                            dcs_change = 1;
                            gui_EMS_change_DCS(b);
                        }
                    }
                }
                else if (gui_ems_test_extention_character(c))
                {
                    if (b->GSM_ext_count > 0)
                    {
                        b->GSM_ext_count--;
                    }
                }
                break;
            case 2:
                /* MTK Joy added for text format case, get the character and set the parameters accordingly, 1230 */
                if (current_object->Type == 0)
                {
                    r = gui_EMS_input_box_get_next_object(b->data, &p, &c, &current_object);
                    if ((r == 1) && gui_ems_test_UCS2_character(c))
                    {
                        if (b->UCS2_count > 0)
                        {
                            b->UCS2_count--;
                            if (b->UCS2_count == 0)
                            {
                                dcs_change = 1;
                                gui_EMS_change_DCS(b);
                            }
                        }
                    }
                    else if (gui_ems_test_extention_character(c))
                    {
                        if (b->GSM_ext_count > 0)
                        {
                            b->GSM_ext_count--;
                        }
                    }
                    break;
                }
                /* MTK end */
                if (b->object_count > 0)
                {
                    b->object_count--;
                    if (b->object_count == 0)
                    {
                        gui_EMS_change_DCS(b);
                    }
                }
                break;
        }
        CancelCurrentPosition(b->data, 1);

        if (b->flags &UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)
        {
            b->input_mode_position.OffsetToText -= ENCODING_LENGTH;   
        }

#ifdef __SMS_R8_NATION_LANGUAGE__
        {
            gui_ems_table_mechanism_enum cur_m = mmi_7bit_get_table_mechanism();

            if (cur_m == EMS_AUTO_DETECTION && (!gui_ems_test_UCS2_character(c)))
            {
                mmi_7bit_update_character_type(&b->ems_auto_dection, c, MMI_FALSE);
            }
        }
#endif
/*PMT IRE START*/
/* PMT START MAUI_00024993 */
    #ifdef __MMI_INDIC_ALG__
        b->data->textBuffer[b->data->textLength] = 0;
        b->data->textBuffer[b->data->textLength + 1] = 0;
        if (cancel_two_pos)
        {
            CancelCurrentPosition(b->data, 1);
        }
/* PMT START MAUI_00027731 */
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
#endif
    #endif /* __MMI_INDIC_ALG__ */ 
/* PMT END MAUI_00024993 */
/*PMT IRE END*/
        if (dcs_change)
        {
            gui_EMS_input_box_insert_extension_character(b, b->data);

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
            pos.OffsetToText = 0;
            pos.Object = NULL;
            gui_emsc_change_request(pos);
#endif
        }

    #if(EMS_USE_ESC_COMBINATION)
        if (b->UCS2_count == 0)
        {
            p = b->data->CurrentPosition;
            r = gui_EMS_input_box_get_previous_object(b->data, &p, &c, &current_object);
            if ((r == 1) && UI_TEST_ESC_CHARACTER(c))
            {
                CancelCurrentPosition(b->data, 1);
                if (b->flags &UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)
                {
                    b->input_mode_position.OffsetToText -= ENCODING_LENGTH;    
                }
            }
        }
    #endif /* (EMS_USE_ESC_COMBINATION) */ 
        return (1);
    }
    return (0);
}

#else /* (EMS_USE_CRLF_COMBINATION || EMS_USE_ESC_COMBINATION) */ 

/* Deletes one object/character before cursor position and updates UCS2 and Object counters  */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_cancel_current_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_cancel_current_position(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (BackwardCurrentPosition(b->data, 1) == 1)
    {
        EMSPosition p = b->data->CurrentPosition;
        EMSObject *current_object;
        UI_character_type c;
        U8 r;

        r = gui_EMS_input_box_get_next_object(b->data, &p, &c, &current_object);
        ForwardCurrentPosition(b->data, 1);
        switch (r)
        {
            case 0:
                break;
            case 1:
                if (gui_ems_test_UCS2_character(c))
                {
                    if (b->UCS2_count > 0)
                    {
                        b->UCS2_count--;
                        if (b->UCS2_count == 0)
                        {
                            gui_EMS_change_DCS(b);
                        }
                    }
                }
                break;
            case 2:
                if (b->object_count > 0)
                {
                    b->object_count--;
                    if (b->object_count == 0)
                    {
                        gui_EMS_change_DCS(b);
                    }
                }
                break;
        }
        CancelCurrentPosition(b->data, 1);
        return (1);
    }
    return (0);
}

#endif /* (EMS_USE_CRLF_COMBINATION || EMS_USE_ESC_COMBINATION) */ 

#define  EMSSWAP(t,a,b) \
{  t temp=a;            \
   a=b;                 \
   b=temp;              \
}

/* Temporary function: Will be removed later                            */
/* For testing purpose only: Using this will cause an assertion in the EMS library  */


/*****************************************************************************
 * FUNCTION
 *  ArrangeEMSObjects
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ArrangeEMSObjects(EMSData *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *current = data->listHead;
    EMSObject *start;
    U8 done;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (current != NULL)
    {
        done = 0;
        start = current;
        while (!done)
        {
            current = current->next;
            if (current == NULL)
            {
                done = 1;
                break;
            }
            if (current->OffsetToText != start->OffsetToText)
            {
                done = 1;
                break;
            }
            if (current->Type == EMS_TYPE_TEXT_FORMAT)
            {
                EMSSWAP(EMSObject, *current, *start);
                EMSSWAP(kal_uint16, current->OffsetToText, start->OffsetToText);
                EMSSWAP(struct _EMSObject *, current->prev, start->prev);
                EMSSWAP(struct _EMSObject *, current->next, start->next);

                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_add_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]     
 *  s               [?]     
 *  text_format     [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSTATUS gui_EMS_input_box_add_string(UI_EMS_input_box *b, U8 *s, EMSTextFormat *text_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_char = 1;
    UI_character_type local_string[2];
    UI_buffer_type ptr = (UI_buffer_type)&local_string[0];

#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    UI_character_type c = ((UI_character_type) s[1]) | (((UI_character_type) s[0]) << 8);
#else 
    UI_character_type c = ((UI_character_type) s[0]) | (((UI_character_type) s[1]) << 8);
#endif 
    EMSTATUS r;

#ifdef __MMI_INDIC_ALG__
    EMSTextFormat temp_text_format;
    U8 prev_text_format_flag=0;
    U8 dv_hal_sign_check = 0;
    U8 halant_cons_combination = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_ems_test_extention_character(c) && b->UCS2_count == 0)
    {
        UI_STRING_INSERT_CHARACTER(ptr, 0x1B);
        UI_STRING_INSERT_CHARACTER(ptr, c);
        num_char = 2;
    }
    else
    {
        UI_STRING_INSERT_CHARACTER(ptr, c);
    }

/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
    /*This statement checks whether a template is being added or not.If a template*/
    /* is added then if following sequence: Cons.+Halant+Object(cursor) and the   */
    /*first character from the template to be insert is a consonant then move the */
    /*cursor in front of the object and then insert the character.                */
    /*Note:There could be more than one object in the sequence                    */
    if(add_template_ems_flag) 
    {
        /*This statement does not allow addition of format object in the following cases: */
        /*1.When the input character is Dep. Vowel, Halant, Sign                          */
        /*2.When the previous character is Halant and input character is Consonant        */
        /* PMT START IRE CODE REVIEW */ 
        U32 character_type=0;
        character_type = ire_identify_character_type((U16)(s[0] | (s[1]<<8) ));
        switch(character_type)
        {
            case IRE_CHAR_TYPE_DEPVOWEL:
            case IRE_CHAR_TYPE_HALANT:
            case IRE_CHAR_TYPE_HALANT1: 
            case IRE_CHAR_TYPE_SIGN:
                dv_hal_sign_check = MMI_TRUE;
                break;
            default:
                dv_hal_sign_check = MMI_FALSE;
        }
        
        halant_cons_combination = ( (character_type==IRE_CHAR_TYPE_CON )
              && ( IRE_IS_CHAR_TYPE_HALANT((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2] 
                | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -1]<<8) )))  );
        /* PMT END IRE CODE REVIEW */
        
        
        if( (c == ZWJ) || dv_hal_sign_check ||  halant_cons_combination)
        {
            U32 langid_Halant=0;
/* PMT START MAUI_00027731 */
            langid_Halant =  IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2] 
                             | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -1]<<8) ));
            if((c == ZWJ) ||(dv_hal_sign_check) || ((halant_cons_combination) && (langid_Halant==IRE_GET_CHARACTER_LANG_ID((U16)(s[0] | (s[1]<<8) )))))
            {
                prev_text_format_flag=1;
                temp_text_format=b->text_format;
                if(b->data->CurrentTextFormatObj)
                {
                    b->text_format=b->data->CurrentTextFormatObj->data->text_format;
                }
                else
                {
                    b->text_format=UI_EMS_normal_text_format_object.data->text_format;
                }
            }
        }
        add_template_ems_flag=0;
    }
#endif /* __MMI_INDIC_ALG__ */
/*PMT IRE END*/    
    if (text_format == NULL)
    {
        r = AddString(b->data, (U8*)&local_string[0], num_char, NULL);
    }
    else if (b->data->CurrentTextFormatObj == NULL)
    {
        if (gui_EMS_input_box_equal_text_format(&b->text_format, &UI_EMS_normal_text_format_object.data->text_format))
        {
            r = AddString(b->data,(U8*)&local_string[0], num_char, NULL);
        }
        else
        {
            r = AddString(b->data, (U8*)&local_string[0], num_char, text_format);
        }
    }
    else
    {
        r = AddString(b->data, (U8*)&local_string[0], num_char, text_format);
    }
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
    /*This statement is to check whether prev_text_format_flag is set or not. */
    /*If it is set then reset the text formatng to the one previously added   */
    if(prev_text_format_flag)
    {
        b->text_format=temp_text_format;
    }
#endif /* __MMI_INDIC_ALG__ */
/*PMT IRE END*/
    if (r == EMS_OK)
    {
        if (b->flags &UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)
        {
            b->input_mode_position.OffsetToText += num_char * ENCODING_LENGTH;   
        }

        if (gui_ems_test_UCS2_character(c))
        {
            if (b->UCS2_count == 0)
            {
                b->UCS2_count++;
                gui_EMS_change_DCS(b);
            }
            else
            {
                b->UCS2_count++;
            }
        }
        else if (gui_ems_test_extention_character(c))
        {
            b->GSM_ext_count++;
        }

#ifdef __SMS_R8_NATION_LANGUAGE__
        {
            gui_ems_table_mechanism_enum cur_m = mmi_7bit_get_table_mechanism();

            if (cur_m == EMS_AUTO_DETECTION && (!gui_ems_test_UCS2_character(c)))
            {
                mmi_7bit_update_character_type(&b->ems_auto_dection, c, MMI_TRUE);
            }
        }
#endif
 
    }
    else
    {
        /* MTK Terry for EMS_NO_MEMORY or other error cause */
        if (b->flags & UI_EMS_INPUT_BOX_STATE_MULTITAP)
        {
            b->flags &= ~UI_EMS_INPUT_BOX_STATE_MULTITAP;
        }
        
        gui_EMS_change_DCS(b);
    }

    /* Temporary   */
    /* ArrangeEMSObjects(b->data); */

    return (r);
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_add_whole_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]     
 *  s               [?]     
 *  text_format     [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSTATUS gui_EMS_input_box_add_whole_string(UI_EMS_input_box *b, U8 *s, EMSTextFormat *text_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))
	UI_buffer_type temp_texp_p;
	S32 str_len;
#endif
#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    UI_character_type c = ((UI_character_type) s[1]) | (((UI_character_type) s[0]) << 8);
#else 
    UI_character_type c = ((UI_character_type) s[0]) | (((UI_character_type) s[1]) << 8);
#endif 
    EMSTATUS r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
    EMSTextFormat temp_text_format;
    U8 prev_text_format_flag=0;
    U8 dv_hal_sign_check = 0;
    U8 halant_cons_combination = 0;
    /*This statement checks whether a template is being added or not.If a template*/
    /* is added then if following sequence: Cons.+Halant+Object(cursor) and the   */
    /*first character from the template to be insert is a consonant then move the */
    /*cursor in front of the object and then insert the character.                */
    /*Note:There could be more than one object in the sequence                    */
    if(add_template_ems_flag) 
    {
        /*This statement does not allow addition of format object in the following cases: */
        /*1.When the input character is Dep. Vowel, Halant, Sign                          */
        /*2.When the previous character is Halant and input character is Consonant        */
        /* PMT START IRE CODE REVIEW */
        U32 character_type = 0;
        character_type ^= character_type;
        character_type = ire_identify_character_type((U16)(s[0] | (s[1]<<8) ));
        switch(character_type)
        {
            case IRE_CHAR_TYPE_DEPVOWEL:
            case IRE_CHAR_TYPE_HALANT:
            case IRE_CHAR_TYPE_HALANT1:
            case IRE_CHAR_TYPE_SIGN:
                dv_hal_sign_check = MMI_TRUE;
                break;
            default:
                dv_hal_sign_check =MMI_FALSE;
        }
        halant_cons_combination = ( (character_type==IRE_CHAR_TYPE_CON )
              && ( IRE_IS_CHAR_TYPE_HALANT((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2] 
                | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -1]<<8) )))  );
        /* PMT END IRE CODE REVIEW */
        
        
        if( (c == ZWJ) || dv_hal_sign_check ||  halant_cons_combination)
        {
            U32 langid_Halant=0;
/* PMT START MAUI_00027731 */
            langid_Halant =  IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2] 
                             | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -1]<<8) ));
            if((c == ZWJ) ||(dv_hal_sign_check) || ((halant_cons_combination) && (langid_Halant==IRE_GET_CHARACTER_LANG_ID((U16)(s[0] | (s[1]<<8) )))))
            {
                prev_text_format_flag=1;
                temp_text_format=b->text_format;
                if(b->data->CurrentTextFormatObj)
                {
                    b->text_format=b->data->CurrentTextFormatObj->data->text_format;
                }
                else
                {
                    b->text_format=UI_EMS_normal_text_format_object.data->text_format;
                }
            }
        }
/* PMT END MAUI_00027731 */ 
/* PMT START MAUI_00027731 */
//code removed
/* PMT END MAUI_00027731 */     
        add_template_ems_flag=0;
    }
#endif /* __MMI_INDIC_ALG__ */
/*PMT IRE END*/    
/* START PMT PATCH04052007 */   
    if (b->UCS2_count == 0)
    {
        while (c)
        {  
            if (gui_ems_test_UCS2_character(c))
            {
                gui_EMS_input_box_remove_extension_character(b, b->data);
                if ((r = gui_EMS_input_box_set_dcs(b, SMSAL_UCS2_DCS)) != EMS_OK)
                {
                    gui_EMS_input_box_set_dcs(b, SMSAL_DEFAULT_DCS);
                    gui_EMS_input_box_insert_extension_character(b, b->data);
                    return r;
                }
                else
                {
                    if (EMS_get_remaining_length(b->data) < mmi_ucs2strlen((S8*)s) *2 )
                    {
                        gui_EMS_input_box_set_dcs(b, SMSAL_DEFAULT_DCS);
                        gui_EMS_input_box_insert_extension_character(b, b->data);
                        return EMS_NO_SPACE;
                    }
                    else
                        break; // Success convert to UCS2
                }
            }
            i +=2;
            c = (UI_character_type)(s[i] | (s[i+1]<<8));
        }
        
    }

    if (text_format == NULL)
    {
        r = AddString(b->data, s, (U16)mmi_ucs2strlen((S8*)s), NULL);
    }
    else if (b->data->CurrentTextFormatObj == NULL)
    {
        if (gui_EMS_input_box_equal_text_format(&b->text_format, &UI_EMS_normal_text_format_object.data->text_format))
        {
            r = AddString(b->data,s, (U16)mmi_ucs2strlen((S8*)s), NULL);
        }
        else
        {
            r = AddString(b->data, s, (U16)mmi_ucs2strlen((S8*)s), text_format);
        }
    }
    else
    {
        r = AddString(b->data, s, (U16)mmi_ucs2strlen((S8*)s), text_format);
    }
	/*
	Check for string in ems editor
	*/
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

	if(mtkmultitap_ire_bengali_ndicator == 1)
	{
		temp_texp_p = s;
		if(( temp_texp_p[0] | (temp_texp_p[1] << 8)) == 0x09b0)
			{
				temp_texp_p += 2;
				if(( temp_texp_p[0] | (temp_texp_p[1] << 8)) == 0x09cd)
				{                                                                    
					str_len =((*(b->data)).CurrentPosition).OffsetToText ;
					ire_shuffling_editor_buffer_for_bengali_spec(b->data->textBuffer, str_len);
					to_decide_to_reshuffle = 1;
				}
			}
	}
#endif
/* END PMT PATCH04052007 */
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
    /*This statement is to check whether prev_text_format_flag is set or not. */
    /*If it is set then reset the text formatng to the one previously added   */
    if(prev_text_format_flag)
    {
        b->text_format=temp_text_format;
    }
#endif /* __MMI_INDIC_ALG__ */
/*PMT IRE END*/
    if (r == EMS_OK)
    {
        while (c)
        {
            if (gui_ems_test_UCS2_character(c))
            {
                if (b->UCS2_count == 0)
                {
                    b->UCS2_count++;
                    gui_EMS_change_DCS(b);
                }
                else
                {
                    b->UCS2_count++;
                }
            }
            else
            {
#ifdef __SMS_R8_NATION_LANGUAGE__
                {
                    gui_ems_table_mechanism_enum cur_m = mmi_7bit_get_table_mechanism();
                    
                    if (cur_m == EMS_AUTO_DETECTION)
                    {
                        mmi_7bit_update_character_type(&b->ems_auto_dection, c, MMI_TRUE);
                    }
                }           
#endif
                if (gui_ems_test_extention_character(c))
                {
                    b->GSM_ext_count++;
                }
            }
            
        i +=2;
        c = (UI_character_type)(s[i] | (s[i+1]<<8));
        }
    }
    else
    {
        /* MTK Terry for EMS_NO_MEMORY or other error cause */
        gui_EMS_change_DCS(b);
    }

    /* Whenever we are adding some text or deleting the text we need to update the 
       input_mode_position so this change is done. */
    if ((r == EMS_OK) && (b->flags &UI_EMS_INPUT_BOX_INPUT_METHOD_MODE))
    {
        /* Get the length of the string that is inserted and update the position */
        b->input_mode_position.OffsetToText += (S32)mmi_ucs2strlen((const S8 *)s) * ENCODING_LENGTH;   
    }
    return (r);
}

#else /* (EMS_USE_DCS) */ 


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_add_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]     
 *  s               [?]     
 *  text_format     [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSTATUS gui_EMS_input_box_add_string(UI_EMS_input_box *b, U8 *s, EMSTextFormat *text_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_char = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_format == NULL)
    {
        return (AddString(b->data, s, num_char, NULL));
    }
    else if (b->data->CurrentTextFormatObj == NULL)
    {
        if (gui_EMS_input_box_equal_text_format(&b->text_format, &UI_EMS_normal_text_format_object.data->text_format))
        {
            return (AddString(b->data, s, num_char, NULL));
        }
        else
        {
            return (AddString(b->data, s, num_char, text_format));
        }
    }
    else
    {
        return (AddString(b->data, s, num_char, text_format));
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_add_whole_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]     
 *  s               [?]     
 *  text_format     [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSTATUS gui_EMS_input_box_add_whole_string(UI_EMS_input_box *b, U8 *s, EMSTextFormat *text_format)
{
    U16 i = 0;

    UI_character_type c = ((UI_character_type) s[0]) | (((UI_character_type) s[1]) << 8);

    while (c)
    {
        gui_EMS_input_box_add_string(b, (U8*)&c, text_format);
        i += 2;
        c = (UI_character_type)(s[i] | (s[i+1]<<8));
    }
    
}
#endif /* (EMS_USE_DCS) */ 


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_inputbox_add_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                               [?]         
 *  type                            [IN]        
 *  objData                         [?]         
 *  predefined_object_number        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
EMSTATUS gui_EMS_inputbox_add_object(UI_EMS_input_box *b, U8 type, EMSObjData *objData, U8 predefined_object_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/* PMT START MAUI_00027731 */
//code removed
/* PMT END MAUI_00027731 */
    r = AddObject(b->data, type, objData, (U8) predefined_object_number);
#if(EMS_USE_DCS)
    if (r == EMS_OK)
    {
        S32 remaining_length;

        if (b->object_count == 0)
        {
            b->object_count++;
            gui_EMS_change_DCS(b);
        }
        else
        {
            b->object_count++;
        }
        if (b->UCS2_count > 0)
        {
            remaining_length = (EMS_get_remaining_length(b->data) >> 1);
        }
        else
        {
            remaining_length = EMS_get_remaining_length(b->data);
        }
        if (remaining_length < 0)
        {
            CancelCurrentPosition(b->data, 1);
            b->object_count--;
            if (b->object_count == 0)
            {
                gui_EMS_change_DCS(b);
            }
            /* UI_editor_play_tone_cannot_insert(); */
            return (EMS_NO_SPACE);
        }
    }
#endif /* (EMS_USE_DCS) */ 
    b->saved_cursor_ax = -1;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_emsc_change_request(b->data->CurrentPosition);
#endif
    
    return (r);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]         
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_insert_character_no_draw(UI_EMS_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //W06.03 EMS_get_remaining_length > 0 does not make sure that we could insert one more character
    //Return EMS_OK if we insert the character successfully
    U16 ch = (U16) c;
    U8 s[2] = {0, 0};
    U8 ret = EMS_OK;
    
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    EMSPosition pos;
#endif

/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
    //EMSObject *object_pointer1;
/*PMT START MAUI_00025408*/
    UI_character_type current_character1 = 0/*,current_character2 = 0*/;
    U8 /*object_type_check2 = 0,*/object_type_check1 =0;
    EMSObject /**o2,*/*o1;
    EMSPosition p1/*, p2 = b->data->CurrentPosition*/;
    EMSData *data_chk_type1 = b->data/*, *data_chk_type2 = b->data*/;
    UI_buffer_type  second_cons_ems_position;
 /*PMT END MAUI_00025408*/
    EMSTextFormat temp_text_format;
    U8 prev_text_format_flag=0;
    U8 dv_hal_sign_check = 0;
    U8 halant_cons_combination = 0;
    
/* PMT START MAUI_00024993 */
    //U16 array[12];
    //EMSTextFormat text_format;
    /* PMT START IRE CODE REVIEW */
    U32 character_type=0;
    /* PMT END IRE CODE REVIEW */
/* PMT END MAUI_00024993 */
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 
    S32 steps;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 

    if (b->flags &UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)
    {
        steps = (S32)b->data->CurrentPosition.OffsetToText - (S32)b->input_mode_position.OffsetToText;
        if (steps > 0)
        {
            BackwardCurrentPosition(b->data, (U16)(steps/ENCODING_LENGTH));    
        }
        else if (steps < 0)
        {
            ForwardCurrentPosition(b->data, (U16)((-steps)/ENCODING_LENGTH));
        }

        /* b->data->CurrentPosition.OffsetToText = b->input_mode_position.OffsetToText; */
#ifdef __MMI_INDIC_ALG__
        if (b->data->CurrentTextFormatObj)
        {
            /* Restore text format length for Indic cluster */
            b->data->CurrentTextFormatObj->data->text_format.textLength -= saved_last_skip_pos * ENCODING_LENGTH;
            saved_last_skip_pos = 0;
        }
#endif /* __MMI_INDIC_ALG__ */
    }

    if (b->UCS2_count == 0)
    {
        if (gui_ems_test_UCS2_character(c))
        {
            gui_EMS_input_box_remove_extension_character(b, b->data);
            if (gui_EMS_input_box_set_dcs(b, SMSAL_UCS2_DCS) != EMS_OK)
            {
                gui_EMS_input_box_set_dcs(b, SMSAL_DEFAULT_DCS);
                gui_EMS_input_box_insert_extension_character(b, b->data);
                UI_editor_play_tone_cannot_insert();
                return EMS_NO_SPACE;
            }
            else
            {
                if (EMS_get_remaining_length(b->data) < 2)
                {
                    gui_EMS_input_box_set_dcs(b, SMSAL_DEFAULT_DCS);
                    gui_EMS_input_box_insert_extension_character(b, b->data);
                    UI_editor_play_tone_cannot_insert();
                    return EMS_NO_SPACE;
                }

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
                pos.OffsetToText = 0;
                pos.Object = NULL;
                gui_emsc_change_request(pos);
#endif
            }
        }
    }
    /* MTK end */

    /* If in Overwrite mode, delete the current character/object and insert the new one */
    if (b->flags & UI_EMS_INPUT_BOX_OVERWRITE_MODE)
    {
        if (gui_EMS_input_box_forward_cursor(b) == 1)
        {
            gui_EMS_cancel_current_position(b);
        }
    }
#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    s[0] = (ch & 0xff00) >> 8;
    s[1] = (ch & 0x00ff);
#else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    s[1] = (U8) (ch >> 8);
    s[0] = (U8) ch;
#endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
/* PMT START MAUI_00027731 */
    second_cons_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 2]);
/* PMT START IRE CODE REVIEW */
        character_type = ire_identify_character_type((U16)(s[0] | (s[1]<<8) ));
        switch(character_type)
        {
            case IRE_CHAR_TYPE_DEPVOWEL:
            case IRE_CHAR_TYPE_HALANT:
            case IRE_CHAR_TYPE_HALANT1:
            case IRE_CHAR_TYPE_SIGN:
                dv_hal_sign_check = MMI_TRUE;
                break;
            default:
                dv_hal_sign_check =MMI_FALSE;
        }
    halant_cons_combination = ( (character_type==IRE_CHAR_TYPE_CON )
          && ( IRE_IS_CHAR_TYPE_HALANT( (U16)( (*second_cons_ems_position) | ((*(second_cons_ems_position+1))<<8) ) ))  );
/* PMT END IRE CODE REVIEW */
    /*This statement does not allow addition of format object in the following cases: */
    /*1.When the input character is Dep. Vowel, Halant, Sign                          */
    /*2.When the previous character is Halant and input character is Consonant        */
    if( (c == ZWJ) || dv_hal_sign_check ||  halant_cons_combination ) 
    {
        U32 langid_Halant=0;
        langid_Halant =  IRE_GET_CHARACTER_LANG_ID((U16)( (*second_cons_ems_position) | ((*(second_cons_ems_position+1))<<8) ));
        if((c == ZWJ) || (dv_hal_sign_check) || ((halant_cons_combination) && (langid_Halant==IRE_GET_CHARACTER_LANG_ID((U16)(s[0] | (s[1]<<8) )))))
        {
            prev_text_format_flag=1;
            temp_text_format=b->text_format;
            if(b->data->CurrentTextFormatObj)
            {
                b->text_format=b->data->CurrentTextFormatObj->data->text_format;
            }
            else
            {
                b->text_format=UI_EMS_normal_text_format_object.data->text_format;
            }
        }
    }
/* PMT END MAUI_00027731 */
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 
    if (gui_EMS_input_box_add_string(b, s, &b->text_format) != EMS_OK)
    {
        UI_editor_play_tone_cannot_insert();
        b->overflow_callback();
        ret = EMS_NO_SPACE;
    }
    else
    {

#ifdef __MMI_INDIC_ALG__
         p1=b->data->CurrentPosition;
         if (!TestLastPosition(b->data, &(b->data->CurrentPosition)))
         {
             object_type_check1 = gui_EMS_input_box_get_next_object(data_chk_type1, &p1, &current_character1, &o1);
         }
        if((object_type_check1==1) && ((IRE_IS_CHAR_TYPE_HALANT(c)) || (c == ZWJ)))
        {
            PU8 src_p = NULL, dest_p = NULL,prev_src_p = NULL, starting_p = NULL;
            src_p = (b->data->textBuffer + b->data->CurrentPosition.OffsetToText);
            if(gui_show_EMS_input_box_find_segment_start(b->data,src_p) > (b->data->textBuffer + b->line_positions_text_offset[b->current_line]))
            {
                starting_p = gui_show_EMS_input_box_find_segment_start(b->data,src_p);
            }
            else
            {
                /* In case the smart input method will disable show flag to insert string, the 
                   line_positions_text_offset is not updated for every insert process, we start
                   from buffer begninning instead */
                starting_p = b->data->textBuffer; //(b->data->textBuffer + b->line_positions_text_offset[b->current_line]);
            }
            prev_src_p = ire_get_prev_cluster_p(starting_p/*gui_show_EMS_input_box_find_segment_start(b->data,src_p)*/, src_p);
            dest_p = ire_get_next_cluster_p(prev_src_p, gui_show_EMS_input_box_find_segment_end(b->data,prev_src_p));
            if ((b->data->CurrentTextFormatObj) &&
                ((b->data->textBuffer + b->data->CurrentTextFormatObj->OffsetToText +
                  b->data->CurrentTextFormatObj->data->text_format.textLength) < dest_p))
            {
                /* Adjust text format length to cover the whole cluster if next char not in text format range */
                b->data->CurrentTextFormatObj->data->text_format.textLength += (dest_p - src_p);
                saved_last_skip_pos = (dest_p - src_p) / 2;
            }

            {
                steps = (S32)(dest_p - src_p);
                if (steps < 0)
                {
                    BackwardCurrentPosition(b->data, (U16)((-steps)/ENCODING_LENGTH));    
                }
                else if (steps > 0)
                {
                    ForwardCurrentPosition(b->data, (U16)(steps/ENCODING_LENGTH));
                }
            }
        }
#endif 

        b->change_callback();

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_emsc_change_request(b->data->CurrentPosition);
#endif

    }
#ifdef __MMI_INDIC_ALG__
    /*This statement is to check whether prev_text_format_flag is set or not. */
    /*If it is set then reset the text formatng to the one previously added   */
    if(prev_text_format_flag)
    {
        b->text_format=temp_text_format;
    }
#endif /*__MMI_INDIC_ALG__*/
/* PMT END MAUI_00024993 */
    if (ret == EMS_OK)
    {
#ifdef __MMI_INDIC_ALG__    
        if(!prev_text_format_flag)
#endif /* __MMI_INDIC_ALG__ */ 
            gui_EMS_input_box_set_text_format_cursor_position(b);
    }

#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_EMS_input_box_change_input_mode_for_smart_Abc(b);
#endif  

    return ret;
}

U8 gui_EMS_input_box_insert_character(UI_EMS_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    gui_ems_table_mechanism_enum cur_m = mmi_7bit_get_table_mechanism();
#endif
    U8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* check extention character */
#ifdef __SMS_R8_NATION_LANGUAGE__
    if (cur_m == EMS_AUTO_DETECTION && (!gui_ems_test_UCS2_character(c)))
    {
        ret = gui_ems_auto_detection_insert_character(b, c);
    }
    else
#endif
    {
        ret = gui_EMS_input_box_insert_character_no_draw(b,c);
    }

    if (b->locate_cursor_flag)
    {
        gui_EMS_input_box_locate_cursor(b);
    }
    
    b->saved_cursor_ax = -1;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_multitap_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]         
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 gui_EMS_input_box_insert_multitap_character_no_draw(UI_EMS_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ch = (U16) c;
    U8 s[2] = {0, 0};
    EMSTextFormat text_format;
    U8 ret = EMS_OK;
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

	S32 str_len;
#endif
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    EMSPosition pos;
#endif

#ifdef __MMI_INDIC_ALG__
    //EMSObject *object_pointer1;
    UI_character_type current_character1 = 0;
    U8 object_type_check1 = 0;
    EMSObject *o1;
    EMSPosition p1 = b->data->CurrentPosition;
    EMSData *data_chk_type1 = b->data;
    UI_buffer_type first_cons_ems_position, second_cons_ems_position;
    EMSTextFormat temp_text_format;
    U8 prev_text_format_flag=0;
    U8 dv_hal_sign_check = 0;/*checking whether the character is Dep. vowel, sign or halant*/
    U8 halant_cons_combination = 0;/*check for halant and consonant combination */
    U32 character_type=0;
#endif /* __MMI_INDIC_ALG__ */ 
    S32 steps;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 

    if (b->flags &UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)
    {
        steps = (S32)b->data->CurrentPosition.OffsetToText - (S32)b->input_mode_position.OffsetToText;
        if (steps > 0)
        {
            BackwardCurrentPosition(b->data, (U16)(steps/ENCODING_LENGTH));    
        }
        else if (steps < 0)
        {
            ForwardCurrentPosition(b->data, (U16)((-steps)/ENCODING_LENGTH));
        }  
#ifdef __MMI_INDIC_ALG__
        if (b->data->CurrentTextFormatObj)
        {
            /* Restore text format length for Indic cluster */
            b->data->CurrentTextFormatObj->data->text_format.textLength -= saved_last_skip_pos * ENCODING_LENGTH;
            saved_last_skip_pos = 0;
        }
#endif /* __MMI_INDIC_ALG__ */
    }

    if (b->UCS2_count == 0)
    {
        if (gui_ems_test_UCS2_character(c))
        {
            gui_EMS_input_box_remove_extension_character(b, b->data); // hjf, It should remove gsm extended character when switch to UCS2
            if (gui_EMS_input_box_set_dcs(b, SMSAL_UCS2_DCS) != EMS_OK)
            {
                gui_EMS_input_box_set_dcs(b, SMSAL_DEFAULT_DCS);
                gui_EMS_input_box_insert_extension_character(b, b->data);// hjf, can't switch to UCS2, append gsm extended character again
                UI_editor_play_tone_cannot_insert();
                ret = EMS_NO_SPACE;
                return ret;
            }
            else
            {
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
                pos.OffsetToText = 0;
                pos.Object = NULL;
                gui_emsc_change_request(pos);
#endif
            }
        }
        /*
        else if (gui_ems_test_extention_character(c))
        {
            if (EMS_get_remaining_length(b->data) < 2)
            {
                UI_editor_play_tone_cannot_insert();
                ret = EMS_NO_SPACE;
                return ret;
            }
        }
        */
    }
#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    s[0] = (ch & 0xff00) >> 8;
    s[1] = (ch & 0x00ff);
#else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    s[1] = (U8) (ch >> 8);
    s[0] = (U8) ch;
#endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
#ifdef __MMI_INDIC_ALG__
        character_type = ire_identify_character_type((U16)(s[0] | (s[1]<<8) ));
        switch(character_type)
        {
            case IRE_CHAR_TYPE_DEPVOWEL:
            case IRE_CHAR_TYPE_HALANT:
            case IRE_CHAR_TYPE_HALANT1:
            case IRE_CHAR_TYPE_SIGN:
                dv_hal_sign_check = MMI_TRUE;
                break;
            default:
                dv_hal_sign_check =MMI_FALSE;
        }
#endif
    if (b->flags & UI_EMS_INPUT_BOX_STATE_MULTITAP)
    {
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
        first_cons_ems_position=  &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 4]);
        halant_cons_combination= ( (character_type==IRE_CHAR_TYPE_CON )
              && ( IRE_IS_CHAR_TYPE_HALANT( (U16)( (*first_cons_ems_position) | ((*(first_cons_ems_position+1))<<8) ) ))  );
     
#endif /* __MMI_INDIC_ALG__ */
       /* The code is updated to give a more generic form. Previously hardcoded one
           characeter was deleted while in multitap state but with introduction of
           multigraphs we need to delete more characters and that information can be got
           from input_start_position 
       */
        if (b->flags & UI_EMS_INPUT_BOX_INPUT_METHOD_MODE) 
        {
            S32 i, j = 0;

            steps = (S32)b->data->CurrentPosition.OffsetToText - (S32)b->input_start_position.OffsetToText;
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

	if(to_decide_to_reshuffle == 1)
	{
		str_len =((*(b->data)).CurrentPosition).OffsetToText ;
		ire_reshuffling_editor_buffer_for_bengali_spec(b->data->textBuffer, str_len);
					to_decide_to_reshuffle = 0;
	}
#endif
            for (i=0; i<steps / ENCODING_LENGTH; i++)
            {
                gui_EMS_cancel_current_position(b);
                j = (S32)b->data->CurrentPosition.OffsetToText - (S32)b->input_start_position.OffsetToText;
                if (j == 0)
                    break;
            }
        } 
#ifdef __MMI_INDIC_ALG__
        if((c == ZWJ) || (dv_hal_sign_check ||  halant_cons_combination))
        {
            U32 langid_Halant=0;
            langid_Halant =  IRE_GET_CHARACTER_LANG_ID((U16)( (*first_cons_ems_position) | ((*(first_cons_ems_position+1))<<8) ));
            if((c == ZWJ) ||(dv_hal_sign_check) || ((halant_cons_combination) && (langid_Halant==IRE_GET_CHARACTER_LANG_ID((U16)(s[0] | (s[1]<<8) )))))
            {
                prev_text_format_flag=1;
                temp_text_format=b->text_format;
                if(b->data->CurrentTextFormatObj)
                {
                    b->text_format=b->data->CurrentTextFormatObj->data->text_format;
                }
                else
                {
                    b->text_format=UI_EMS_normal_text_format_object.data->text_format;
                }
            }
        }
        ems_cursor_pos_flag = 0;
        second_cons_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText+2]);
        first_cons_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 2]);
#endif /* __MMI_INDIC_ALG__ */ 
        text_format = b->text_format;
        if (b->UCS2_count == 0 && gui_ems_test_UCS2_character(c))
        {
            gui_EMS_input_box_remove_extension_character(b, b->data);
        }
        if ((ret = gui_EMS_input_box_add_string(b, s, &text_format)) != EMS_OK /*==EMS_NO_SPACE */ )
        {
            UI_editor_play_tone_cannot_insert();
            b->overflow_callback();
        }
        else
        {
#ifdef __MMI_INDIC_ALG__
            PU8 src_p = NULL, dest_p = NULL,prev_src_p = NULL, starting_p = NULL;
            p1=b->data->CurrentPosition;
            if (!TestLastPosition(b->data, &(b->data->CurrentPosition)))
            {
                object_type_check1 = gui_EMS_input_box_get_next_object(data_chk_type1, &p1, &current_character1, &o1);
            }
            if((object_type_check1==1) && ((IRE_IS_CHAR_TYPE_HALANT(c)) || (c == ZWJ)))
            {
                src_p = (b->data->textBuffer + b->data->CurrentPosition.OffsetToText);
                if(gui_show_EMS_input_box_find_segment_start(b->data,src_p) > (b->data->textBuffer + b->line_positions_text_offset[b->current_line]))
                {
                    starting_p = gui_show_EMS_input_box_find_segment_start(b->data,src_p);
                }
                else if(b->current_line > 0)
                {
                    starting_p = (b->data->textBuffer + b->line_positions_text_offset[b->current_line - 1]);
                }
                else
                {
                    starting_p = (b->data->textBuffer + b->line_positions_text_offset[b->current_line]);
                }
                prev_src_p = ire_get_prev_cluster_p(starting_p/*gui_show_EMS_input_box_find_segment_start(b->data,src_p)*/, src_p);
                dest_p = ire_get_next_cluster_p(prev_src_p, gui_show_EMS_input_box_find_segment_end(b->data,prev_src_p));
                b->data->CurrentPosition.OffsetToText += (dest_p - src_p);
                if ((b->data->CurrentTextFormatObj) &&
                    ((b->data->textBuffer + b->data->CurrentTextFormatObj->OffsetToText +
                      b->data->CurrentTextFormatObj->data->text_format.textLength) < dest_p))
                {
                    /* Adjust text format length to cover the whole cluster if next char not in text format range */
                    b->data->CurrentTextFormatObj->data->text_format.textLength += (dest_p - src_p);
                    saved_last_skip_pos = (dest_p - src_p) / 2;
                }
                ems_cursor_pos_flag = 1;
            }
           
           #endif /* __MMI_INDIC_ALG__ */ 
           b->change_callback();
        }
    }
    else
    {
#ifdef __MMI_INDIC_ALG__
        ems_cursor_pos_flag = 0;
        no_objects_adjusted=0;
        second_cons_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 2]);
/* PMT START IRE CODE REVIEW */
        halant_cons_combination = ( (character_type==IRE_CHAR_TYPE_CON )
              && ( IRE_IS_CHAR_TYPE_HALANT( (U16)( (*second_cons_ems_position) | ((*(second_cons_ems_position+1))<<8) ) ))  );
/* PMT END IRE CODE REVIEW */
        /*This statement does not allow addition of format object in the following cases: */
        /*1.When the input character is Dep. Vowel, Halant, Sign                          */
        /*2.When the previous character is Halant and input character is Consonant        */
        if( (c == ZWJ) || dv_hal_sign_check ||  halant_cons_combination)
        {
            U32 langid_Halant=0;
            langid_Halant =  IRE_GET_CHARACTER_LANG_ID((U16)( (*second_cons_ems_position) | ((*(second_cons_ems_position+1))<<8) ));
            if((c == ZWJ) ||(dv_hal_sign_check) || ((halant_cons_combination) && (langid_Halant==IRE_GET_CHARACTER_LANG_ID((U16)(s[0] | (s[1]<<8) )))))
            {
                prev_text_format_flag=1;
                temp_text_format=b->text_format;
                if(b->data->CurrentTextFormatObj)
                {
                    b->text_format=b->data->CurrentTextFormatObj->data->text_format;
                }
                else
                    {
                    b->text_format=UI_EMS_normal_text_format_object.data->text_format;
                    }
            }
        }
#endif /* __MMI_INDIC_ALG__ */ 
        if (b->flags & UI_EMS_INPUT_BOX_OVERWRITE_MODE)
        {
            if (gui_EMS_input_box_forward_cursor(b) == 1)
            {
                gui_EMS_cancel_current_position(b);
                text_format = b->text_format;
                if (gui_EMS_input_box_add_string(b, s, &text_format) != EMS_OK /*==EMS_NO_SPACE */ )
                {
                    UI_editor_play_tone_cannot_insert();
                    b->overflow_callback();
                }
                else
                {
                    b->change_callback();
                }
            }
            /* to prevent to enable the multitap flag while reaching the max length(cannot add any char) */
            b->flags |= UI_EMS_INPUT_BOX_STATE_MULTITAP;

        }
        else
        {
            if ((ret = gui_EMS_input_box_add_string(b, s, &b->text_format)) != EMS_OK /*==EMS_NO_SPACE */ )
            {
                UI_editor_play_tone_cannot_insert();
                b->overflow_callback();
            }
            else
            {
                b->change_callback();
                b->flags |= UI_EMS_INPUT_BOX_STATE_MULTITAP;
            }
        }
        
    }
    
#ifdef __MMI_INDIC_ALG__
    /*This statement is to check whether prev_text_format_flag is set or not. */
    /*If it is set then reset the text formatng to the one previously added   */
    if(prev_text_format_flag)
    {
        b->text_format=temp_text_format;
    }
    if (TestLastPosition(b->data, &(b->data->CurrentPosition)))
    {
        b->data->textBuffer[b->data->CurrentPosition.OffsetToText] = 0;
        b->data->textBuffer[b->data->CurrentPosition.OffsetToText + 1] = 0;
    }
#endif /* __MMI_INDIC_ALG__ */ 

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_emsc_change_request(b->data->CurrentPosition);
#endif
    
    if (ret == EMS_OK)
    {
#ifdef __MMI_INDIC_ALG__    
        if(!prev_text_format_flag)
#endif /* __MMI_INDIC_ALG__ */ 
        gui_EMS_input_box_set_text_format_cursor_position(b);
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_multitap_string_no_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b            [IN]        UI_EMS_input_box instance         
 *  string       [IN]        String to be inserted
 * RETURNS
 *  U8 Characters inserted
 *****************************************************************************/
U8 gui_EMS_input_box_insert_multitap_string_no_draw(UI_EMS_input_box *b, UI_character_type* string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 steps = 0;
    S32 to_delete = 0;
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    EMSPosition pos;
    pos.OffsetToText = 0;
    pos.Object = NULL;
    gui_emsc_change_request(pos);
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 

    if (b->flags & UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)
    {
        steps = (S32)b->data->CurrentPosition.OffsetToText - (S32)b->input_mode_position.OffsetToText;
        if (steps > 0)
        {
            BackwardCurrentPosition(b->data, (U16)(steps/ENCODING_LENGTH));    
        }
        else if (steps < 0)
        {
            ForwardCurrentPosition(b->data, (U16)((-steps)/ENCODING_LENGTH));
        }
        /* These statements ensures that we delete the characters last entered by multitap method */
        steps = (S32)b->data->CurrentPosition.OffsetToText - (S32)b->input_start_position.OffsetToText;
        to_delete = (S32) steps / ENCODING_LENGTH;
        while(to_delete--)
        {
            gui_EMS_cancel_current_position(b);
        }
    }
    /* Add whole string to the editor */
    if (gui_EMS_input_box_add_whole_string(b, (U8*)string, &b->text_format) != EMS_OK)
    {
        UI_editor_play_tone_cannot_insert();
        b->overflow_callback();
    }
    else
    {
       b->change_callback();
        /* Set the multitap state */
        b->flags |= UI_EMS_INPUT_BOX_STATE_MULTITAP;
    }
    
    #ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        gui_emsc_change_request(b->data->CurrentPosition);
    #endif
    return EMS_OK;
}

U8 gui_EMS_input_box_insert_multitap_character(UI_EMS_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    gui_ems_table_mechanism_enum cur_m = mmi_7bit_get_table_mechanism();
#endif
    U8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* check extention character */
#ifdef __SMS_R8_NATION_LANGUAGE__
    if (cur_m == EMS_AUTO_DETECTION && (!gui_ems_test_UCS2_character(c)))
    {
        ret = gui_ems_auto_detection_insert_multitap_character(b, c);
    }
    else
#endif
    {
        ret = gui_EMS_input_box_insert_multitap_character_no_draw(b, c);
    }

    gui_EMS_input_box_locate_cursor(b);
    b->saved_cursor_ax = -1;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_confirm_multitap_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_confirm_multitap_character(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags &= ~UI_EMS_INPUT_BOX_STATE_MULTITAP;
#ifdef __MMI_INDIC_ALG__
    saved_last_skip_pos = 0;
#endif /* __MMI_INDIC_ALG__ */
}

extern EMSTextFormat wgui_EMS_text_format;


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_delete_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_delete_all(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    EMSNationalLanguage l;
    gui_ems_table_mechanism_enum cur_m = mmi_7bit_get_table_mechanism();
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    ResetCurrentPosition(b->data);
    /* MTK Elvis 20040611 donot plan tone while the EMS data is empty. */

    /* MTK end */
    /* Probably a better way of doing this is to have a EMS library API  */
    GoToEndPosition(b->data);
    /* START TARUN 20041230 */
    memset(b->data->textBuffer, 0, b->data->CurrentPosition.OffsetToText);
    /* END TARUN 20041230 */
#if defined(__MMI_MESSAGES_CONCAT_SMS__)
    CancelCurrentPosition(b->data, (U16) (b->data->Reminder.maxUsableLenPerSeg * (b->data->Reminder.requiredSegment+1)));
#else 
    CancelCurrentPosition(b->data, (U16) (EMS_DEFAULT_DCS_ALLOCATED_LENGTH));
#endif 
    gui_EMS_input_box_set_text_format_cursor_position(b);
    
    b->UCS2_count = 0;
    b->object_count = 0;
    /* MTK Joy added for clear all, 1228 */
    b->GSM_ext_count = 0;
    /* MTK end */
    gui_EMS_change_DCS(b);
    b->saved_cursor_ax = -1;
    ResetTextFormat(&wgui_EMS_text_format);

#ifdef __SMS_R8_NATION_LANGUAGE__
    memset(&b->ems_auto_dection, 0, sizeof(mmi_7bit_auto_detection_struct));

    if (cur_m == EMS_AUTO_DETECTION)
    {
        l.locking_shift = EMS_NL_DEFAULT;
        l.single_shift = EMS_NL_DEFAULT;
        
        mmi_7bit_set_national_lang_table(&l);
        EMSSetNationalLanguage(b->data, &l);
    }

#endif

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        gui_emsc_change_request(b->data->CurrentPosition);
#endif
    
    gui_EMS_input_box_locate_cursor(b);
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_delete_no_draw(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 steps;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 

    if (b->flags &UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)
    {
        steps = (S32)b->data->CurrentPosition.OffsetToText - (S32)b->input_mode_position.OffsetToText;
        if (steps > 0)
        {
            BackwardCurrentPosition(b->data, (U16)(steps/ENCODING_LENGTH));    
        }
        else if (steps < 0)
        {
            ForwardCurrentPosition(b->data, (U16)((-steps)/ENCODING_LENGTH));
        }
        
        /* b->data->CurrentPosition.OffsetToText = b->input_mode_position.OffsetToText; */     
    }

    if (UI_TEST_CR_CHARACTER(b->data->textBuffer[b->data->CurrentPosition.OffsetToText]))
    {
        if (ForwardCurrentPosition(b->data, 1) == 1)
        {
            if (!UI_TEST_LF_CHARACTER(b->data->textBuffer[b->data->CurrentPosition.OffsetToText]))
            {
                BackwardCurrentPosition(b->data, 1);
            }
        }
    }
    if (gui_EMS_input_box_forward_cursor(b) == 1)
    {
        gui_EMS_cancel_current_position(b);
        gui_EMS_input_box_set_text_format_cursor_position(b);

        //gui_EMS_input_box_locate_cursor(b);
        if (b->flags &UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)
        {
            b->input_mode_position.OffsetToText -= ENCODING_LENGTH;     
        }
    }
    else
    {
        UI_editor_play_tone_cannot_change();
    }
}
void gui_EMS_input_box_delete(UI_EMS_input_box *b)
{
    gui_EMS_input_box_delete_no_draw(b);
    b->saved_cursor_ax = -1;
    gui_EMS_input_box_locate_cursor(b);
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_previous
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_previous(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition mapped_cursor_position;
    mmi_lm_cluster_info cur_cluster;
    UI_character_type current_character;
    EMSObject *current_object;
    UI_buffer_type start, end, cursor_p;
    EMSData *data = b->data;
    U8 object_type;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK End */

#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 

    mapped_cursor_position = data->CurrentPosition;
    object_type = gui_EMS_input_box_get_previous_object(data, &mapped_cursor_position, &current_character, &current_object);

    if (2 == object_type && current_object->Type == EMS_TYPE_TEXT_FORMAT)
        object_type = gui_EMS_input_box_get_previous_object(data, &mapped_cursor_position, &current_character, &current_object);

    if (object_type == 1)
    {
        EMSPosition tmp_cursor_p = data->CurrentPosition;
        start = data->textBuffer;
        object_type = gui_EMS_input_box_get_next_object(data, &tmp_cursor_p, &current_character, &current_object);
        /* If next is text format or object set the end position to cursor position */
        if (object_type != 1)
        {
            end = data->textBuffer + data->CurrentPosition.OffsetToText;
        }
        else
        {
            end = data->textBuffer + data->textLength;
        }
        
        cursor_p = data->textBuffer + data->CurrentPosition.OffsetToText;
        mmi_lm_get_prev_cluster(start, end, cursor_p, MMI_TRUE, &cur_cluster);
        if (cur_cluster.data_len > 1)
        {
            for(i=1; i<(S32)cur_cluster.data_len; i++)
            {
                object_type = gui_EMS_input_box_get_previous_object(data, &mapped_cursor_position, &current_character, &current_object);
                if (object_type != 1)
                    break;
            }

            if (i == (S32)cur_cluster.data_len)
            {
                BackwardCurrentPosition(data, (U16)cur_cluster.data_len);
                gui_EMS_input_box_set_text_format_cursor_position(b);
                gui_EMS_input_box_locate_cursor(b);
                b->saved_cursor_ax = -1;
                return;
            }
        }
    }


    if (BackwardCurrentPositionSkipCR(b->data) != 1)
    {
        UI_editor_play_tone_cannot_navigate();
    }
    else
    {
        gui_EMS_input_box_set_text_format_cursor_position(b);
        gui_EMS_input_box_locate_cursor(b);
        b->saved_cursor_ax = -1;
    }

#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_EMS_input_box_change_input_mode_for_smart_Abc(b);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_forward_cursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_forward_cursor(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->data->CurrentPosition.OffsetToText <= (b->data->textLength))
    {   /* START TARUN 20041212 */
        if (ForwardCurrentPositionSkipCR(b->data) == 1)
            //if(ForwardCurrentPositionSkipCR(b->data)>=1)
            //END TARUN 20041212
        {
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_next(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition mapped_cursor_position;
    mmi_lm_cluster_info cur_cluster;
    UI_character_type current_character;
    EMSObject *current_object;
    EMSData *data = b->data;
    UI_buffer_type start, end, cursor_p;
    U8 object_type;
    S32 i, len;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK End */

#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    mapped_cursor_position = data->CurrentPosition;
    object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &current_character, &current_object);

    if (2 == object_type && current_object->Type == EMS_TYPE_TEXT_FORMAT)
        object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &current_character, &current_object);

    if (object_type == 1)
    {
        start = cursor_p = data->textBuffer + data->CurrentPosition.OffsetToText;
        end = data->textBuffer + data->textLength;
        mmi_lm_get_next_cluster(start, end, cursor_p, MMI_TRUE, &cur_cluster);
        len = (S32)((UI_buffer_type)cur_cluster.data_ptr - cursor_p)/ENCODING_LENGTH;
        if (len > 1)
        {
            for(i=1; i<len; i++)
            {
                object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &current_character, &current_object);
                if (object_type != 1)
                    break;
            }
            
            if (i == len)
            {
                ForwardCurrentPosition(data, (U16)len);
                gui_EMS_input_box_set_text_format_cursor_position(b);
                gui_EMS_input_box_locate_cursor(b);
                b->saved_cursor_ax = -1;
                return;
            }
            else if (i < len)
            {
                start = cursor_p = data->textBuffer + data->CurrentPosition.OffsetToText;
                end = cursor_p + i*ENCODING_LENGTH;
                mmi_lm_get_next_cluster(start, end, cursor_p, MMI_TRUE, &cur_cluster);
                len = (S32)((UI_buffer_type)cur_cluster.data_ptr - cursor_p)/ENCODING_LENGTH;
                if (len > 1)
                {
                    ForwardCurrentPosition(data, (U16)len);
                    gui_EMS_input_box_set_text_format_cursor_position(b);
                    gui_EMS_input_box_locate_cursor(b);
                    b->saved_cursor_ax = -1;
                    return;
                }
                    
            }
        }
    }
    

    if (gui_EMS_input_box_forward_cursor(b) != 1)
    {
        UI_editor_play_tone_cannot_navigate();
    }
    else
    {
        gui_EMS_input_box_set_text_format_cursor_position(b);
        gui_EMS_input_box_locate_cursor(b);
        b->saved_cursor_ax = -1;
    }

#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_EMS_input_box_change_input_mode_for_smart_Abc(b);
#endif
}



/*****************************************************************************
 * FUNCTION
 *  gui_move_EMS_input_box
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]         
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_EMS_input_box(UI_EMS_input_box *b, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    gui_move_vertical_scrollbar(&b->vbar, b->x + b->width - b->vbar.width - 1, b->y + 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_EMS_input_box
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [?]         
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_EMS_input_box(UI_EMS_input_box *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width_change = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (width != b->width || height != b->height)
        b->saved_cursor_ax = -1;

    if (width != b->width)
        width_change = 1;

    b->width = width;
    b->height = height;
    gui_move_vertical_scrollbar(&b->vbar, b->x + b->width - b->vbar.width - 1, b->y + 1);
    gui_resize_vertical_scrollbar(&b->vbar, b->vbar.width, b->height - 2);
    
#if(UI_BLINKING_CURSOR_SUPPORT)
    StopTimer(BLINKING_CURSOR);
#endif

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    if (width_change)
    {
        gui_emsc_all_line_update();
    }
#endif

    if ((!(b->flags & UI_EMS_INPUT_BOX_VIEW_MODE)) &&
        (!(b->flags & UI_EMS_INPUT_BOX_DISABLE_CURSOR_DRAW)))
        gui_EMS_input_box_locate_cursor(b);
}

/* Returns 0: none, 1: character, 2:object   */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_get_next_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data                    [?]         
 *  current_position        [?]         
 *  c                       [?]         
 *  o                       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_get_next_object(
    EMSData *data,
    EMSPosition *current_position,
    UI_character_type *c,
    EMSObject **o)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (EMSGetNextObject(data, current_position, c, o));
}

/* MTK Add By Elvis for Input method */
/* Returns 0: none, 1: character, 2:object   */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_get_next_object_for_input_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data                    [?]         
 *  current_position        [?]         
 *  c                       [?]         
 *  o                       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_get_next_object_for_input_method(
    EMSData *data,
    EMSPosition *current_position,
    UI_character_type *c,
    EMSObject **o)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 return_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_position->Object != NULL)
    {
        if (current_position->Object->next != NULL &&
            current_position->Object->next->OffsetToText == current_position->OffsetToText)
        {
            return_type = 2;
            *o = current_position->Object->next;
            current_position->Object = current_position->Object->next;
        }
        else if (current_position->OffsetToText < EMS_DATA_END_OFFSET(data->textLength))
        {
            return_type = 1;
        #if(EMS_BYTE_ORDER_BIG_ENDIAN)
            *c = (data->
                  textBuffer[current_position->OffsetToText +
                             1] | (data->textBuffer[current_position->OffsetToText] << 8));
        #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
            *c = (data->
                  textBuffer[current_position->OffsetToText] | (data->
                                                                textBuffer[current_position->OffsetToText + 1] << 8));
        #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
            current_position->OffsetToText += 2;
        }
    }
    else if (data->listHead != NULL)
    {
        if (data->listHead->OffsetToText == current_position->OffsetToText)
        {
            return_type = 2;
            *o = data->listHead;
            current_position->Object = data->listHead;
        }
        else if (current_position->OffsetToText < EMS_DATA_END_OFFSET(data->textLength))
        {
            return_type = 1;
        #if(EMS_BYTE_ORDER_BIG_ENDIAN)
            *c = (data->
                  textBuffer[current_position->OffsetToText +
                             1] | (data->textBuffer[current_position->OffsetToText] << 8));
        #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
            *c = (data->
                  textBuffer[current_position->OffsetToText] | (data->
                                                                textBuffer[current_position->OffsetToText + 1] << 8));
        #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
            current_position->OffsetToText += 2;
        }

    }
    else if (current_position->OffsetToText < EMS_DATA_END_OFFSET(data->textLength))
    {
        return_type = 1;
    #if(EMS_BYTE_ORDER_BIG_ENDIAN)
        *c = (data->
              textBuffer[current_position->OffsetToText + 1] | (data->textBuffer[current_position->OffsetToText] << 8));
    #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        *c = (data->
              textBuffer[current_position->OffsetToText] | (data->textBuffer[current_position->OffsetToText + 1] << 8));
    #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        current_position->OffsetToText += 2;
    }
    return (return_type);
}

/* MTK end */

/* Returns 0: none, 1: character, 2:object   */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_get_previous_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data                    [?]         
 *  current_position        [?]         
 *  c                       [?]         
 *  o                       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_get_previous_object(
    EMSData *data,
    EMSPosition *current_position,
    UI_character_type *c,
    EMSObject **o)
{
    return (EMSGetPreviousObject(data, current_position, c, o));
    }
/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_get_previous_character
 * DESCRIPTION
 *  to get previous character according to current cursor position
 * PARAMETERS
 *  b        [IN]          UI_EMS_input_box context object
 *  c        [OUT]         return character's unicode    
 * RETURNS
 *  1 -> success
 *  0 -> no character return
 *****************************************************************************/
U8 gui_EMS_input_box_get_previous_character(UI_EMS_input_box *b, UI_character_type *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *current_object = NULL;
    EMSPosition mapped_cursor_position;
    U8 ret = 0;
    EMSData *data = b->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);*/
    mapped_cursor_position = data->CurrentPosition;
    ret = gui_EMS_input_box_get_previous_object(
            data,
            &mapped_cursor_position,
            c,
            &current_object);

    if (ret == 2 && current_object->Type == EMS_TYPE_TEXT_FORMAT)
	{
		ret = gui_EMS_input_box_get_previous_object(
                data,
                &mapped_cursor_position,
                c,
                &current_object);
	}

    if(ret == 1) /* character */
    {
        return 1;
    }
    else
    {
        return 0;
    }
            
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_get_next_character
 * DESCRIPTION
 *  to get next character according to current cursor position
 * PARAMETERS
 *  b        [IN]          UI_EMS_input_box context object
 *  c        [OUT]         return character's unicode    
 * RETURNS
 *  1 -> success
 *  0 -> no character return
 *****************************************************************************/
U8 gui_EMS_input_box_get_next_character(UI_EMS_input_box *b, UI_character_type *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *current_object = NULL;
    EMSPosition mapped_cursor_position;
    U8 ret = 0;
    EMSData *data = b->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);*/
    mapped_cursor_position = data->CurrentPosition;
    ret = gui_EMS_input_box_get_next_object(
            data,
            &mapped_cursor_position,
            c,
            &current_object);

	if (ret == 2 && current_object->Type == EMS_TYPE_TEXT_FORMAT)
	{
		ret = gui_EMS_input_box_get_next_object(
            data,
            &mapped_cursor_position,
            c,
            &current_object);
	}

    if(ret == 1) /* character */
    {
        return 1;
    }
    else
    {
        return 0;
    }
            
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_EMS_input_box_cursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [?]         
 *  x           [IN]        
 *  y           [IN]        
 *  width       [IN]        
 *  height      [IN]        
 *  flags       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_EMS_input_box_cursor(UI_EMS_input_box *b, S32 x, S32 y, S32 width, S32 height, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cursor_type = (U8) (flags & 0x0f);
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cursor_type == 1)
    {
        x1 = x - 1;
        y1 = y;
        x2 = x;
        y2 = y + height - 1;
        if (x1 < (b->x + 1))
        {
            x1 = b->x + 1;
        }
        if (y1 < (b->y + 1))
        {
            y1 = b->y + 1;
        }
        if (x2 > (b->x + b->width - 2))
        {
            x2 = b->x + b->width - 2;
        }
        if (y2 > (b->y + b->height - 2))
        {
            y2 = b->y + b->height - 2;
        }
        
    #if(UI_BLINKING_CURSOR_SUPPORT)
        if (y > (b->y + b->height) || (y + height) < b->y)
            StopTimer(BLINKING_CURSOR);
        else
            UI_inputbox_show_cursor(x1, y1, x2, y2, b->cursor_color);
    #else 
        UI_cursor_x1 = x1;
        UI_cursor_y1 = y1;
        UI_cursor_x2 = x2;
        UI_cursor_y2 = y2;

        gui_fill_rectangle(x1, y1, x2, y2, b->cursor_color);
    #endif 
    }
    else if (cursor_type == 2)
    {
        x1 = x - 2;
        y1 = y;
        x2 = x - 1;
        y2 = y + height - 1;
        if (x1 < (b->x + 1))
        {
            x1 = b->x + 1;
        }
        if (y1 < (b->y + 1))
        {
            y1 = b->y + 1;
        }
        if (x2 > (b->x + b->width - 2))
        {
            x2 = b->x + b->width - 2;
        }
        if (y2 > (b->y + b->height - 2))
        {
            y2 = b->y + b->height - 2;
        }
    #if(UI_BLINKING_CURSOR_SUPPORT)
        if (y > (b->y + b->height) || (y + height) < b->y)
            StopTimer(BLINKING_CURSOR);
        else
            UI_inputbox_show_cursor(x1, y1, x2, y2, b->cursor_color);
    #else /* (UI_BLINKING_CURSOR_SUPPORT) */ 
        UI_cursor_x1 = x1;
        UI_cursor_y1 = y1;
        UI_cursor_x2 = x2;
        UI_cursor_y2 = y2;

        gui_fill_rectangle(x1, y1, x2, y2, b->cursor_color);
    #endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 
    }
    else if (cursor_type == 3)
    {
        x1 = x - 1;
        y1 = y - 1;
        x2 = x + width - 1 + 1;
        y2 = y + height - 1 + 1;
        if (x1 < (b->x + 1))
        {
            x1 = b->x + 1;
        }
        if (y1 < (b->y + 1))
        {
            y1 = b->y + 1;
        }
        if (x2 > (b->x + b->width - 2))
        {
            x2 = b->x + b->width - 2;
        }
        if (y2 > (b->y + b->height - 2))
        {
            y2 = b->y + b->height - 2;
        }
    #if(UI_BLINKING_CURSOR_SUPPORT)
        StopTimer(BLINKING_CURSOR);
    #endif
        gui_draw_rectangle(x1, y1, x2, y2, b->cursor_color);
    }
}

/* MTK end */

/* CRLF/Esc sequence handling functions:              */
/* These must be made available in the EMS library       */
/* Navigates CRLF/Esc sequence as a single object        */
/* Currently assumes Little endian byte ordering only    */
/* Supports only steps=1                           */


/*****************************************************************************
 * FUNCTION
 *  BackwardCurrentPositionSkipCR
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 BackwardCurrentPositionSkipCR(EMSData *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 object_type_check;
    EMSObject *o;
    EMSPosition p = data->CurrentPosition;
    EMSData *data_chk_type = data;
    UI_character_type current_character = 0;
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
    UI_character_type dummy_c = 0;
    S32 prev_ems_moves = 0;
    UI_buffer_type check_ems_hindi_p;
    PU8 src_p;
    PU8 dest_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    check_ems_hindi_p = src_p = (data->textBuffer + data->CurrentPosition.OffsetToText);

    UI_STRING_GET_PREVIOUS_CHARACTER(check_ems_hindi_p, dummy_c);       /* get previous character */
/*PMT IRE START*/
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(dummy_c))
    {
        /* Move by a syllable rather than by a character as in English */
/* PMT START MAUI_00027731 */
        dest_p = ire_get_prev_cluster_p(gui_show_EMS_input_box_find_segment_start(data,src_p), src_p);
/* PMT END MAUI_00027731 */
/*PMT IRE END*/
        prev_ems_moves = src_p - dest_p;
        prev_ems_moves = prev_ems_moves >> 1;
        object_type_check = gui_EMS_input_box_get_previous_object(data_chk_type, &p, &current_character, &o);
        if (object_type_check == 2)
        {
            prev_ems_moves = 1;
        }
    }
    else
    {
        prev_ems_moves = 1;
    }
    /* To be checked why its returning 0 for prev_ems_moves>1 */
    MMI_ASSERT(!(prev_ems_moves < 0));
    if (BackwardCurrentPosition(data, (U16)prev_ems_moves) >= 1)
/*PMT IRE START*/
#else /* __MMI_INDIC_ALG__ */ 
    if (BackwardCurrentPosition(data, 1) == 1)
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 
    {
        if (data->textBuffer == NULL)
        {
            return (1);
        }
        p = data->CurrentPosition;
        object_type_check = gui_EMS_input_box_get_previous_object(data_chk_type, &p, &current_character, &o);
        
        if (object_type_check == 1
            || (object_type_check == 2 && (o->Type == EMS_TYPE_TEXT_FORMAT)))
        {
#if(EMS_USE_CRLF_COMBINATION)
            if (UI_TEST_LF_CHARACTER(data->textBuffer[data->CurrentPosition.OffsetToText]))
            {
                if (BackwardCurrentPosition(data, 1) == 1)
                {
                    if (!UI_TEST_CR_CHARACTER(data->textBuffer[data->CurrentPosition.OffsetToText]))
                    {
                        ForwardCurrentPosition(data, 1);
                    }
                }
            }
#endif /* (EMS_USE_CRLF_COMBINATION) */ 
            
#if(EMS_USE_ESC_COMBINATION)
            if (BackwardCurrentPosition(data, 1) == 1)
            {
                
                if (!UI_TEST_ESC_CHARACTER(data->textBuffer[data->CurrentPosition.OffsetToText]))
                {
                    ForwardCurrentPosition(data, 1);
                }
                /*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
                //changes by pawanjeet 080707
                /*else if ((UI_TEST_ESC_CHARACTER(data->textBuffer[data->CurrentPosition.OffsetToText])) &&
                (data->textBuffer[data->CurrentPosition.OffsetToText + 1 == 0x09]))
                {
                ForwardCurrentPosition(data, 1);
            }*/
                //changes by pawanjeet 080707
#endif /* __MMI_INDIC_ALG__ */ 
                /*PMT IRE END*/
            }
#endif /* (EMS_USE_ESC_COMBINATION) */ 
        }

        return (1);
    }
    return (0);
}

/* Navigates CRLF/Esc sequence as a single object        */
/* Currently assumes Little endian byte ordering only    */
/* Supports only steps=1                           */


/*****************************************************************************
 * FUNCTION
 *  ForwardCurrentPositionSkipCR
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 ForwardCurrentPositionSkipCR(EMSData *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 count = 0;
    UI_character_type current_character = 0;
    U8 object_type_check;
    EMSObject *o;
    EMSPosition p = data->CurrentPosition;
    EMSData *data_chk_type = data;
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
    UI_character_type dummy_c = 0;
    S32 next_ems_moves = 0;
    UI_buffer_type check_ems_hindi_p;
    PU8 src_p;
    PU8 dest_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    check_ems_hindi_p = src_p = (data->textBuffer + data->CurrentPosition.OffsetToText);

    UI_STRING_GET_NEXT_CHARACTER(check_ems_hindi_p, dummy_c);   /* get previous character */
/*PMT IRE START*/  
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(dummy_c))
    {
        /* Move by a syllable rather than by a character as in English */
/* PMT START MAUI_00027731 */
        dest_p = ire_get_next_cluster_p(src_p, gui_show_EMS_input_box_find_segment_end(data,src_p));
/* PMT END MAUI_00027731 */
/*PMT IRE END*/
        next_ems_moves = dest_p - src_p;
        next_ems_moves = next_ems_moves >> 1;
        object_type_check = gui_EMS_input_box_get_next_object(data_chk_type, &p, &current_character, &o);
        if (object_type_check == 2 && (next_ems_moves >= 2) && o->Type == EMS_TYPE_TEXT_FORMAT)
        {
            /* Do nothing */
        }

        else if (object_type_check == 2)
        {
            next_ems_moves = 1;
        }
    }
    else
    {
        next_ems_moves = 1;
    }
/*PMT IRE START*/
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 
    if (data->textBuffer == NULL)
    {
        count = ForwardCurrentPosition(data, 1);
        return (count);
    }
    
    p = data->CurrentPosition;
    object_type_check = gui_EMS_input_box_get_next_object(data_chk_type, &p, &current_character, &o);
    if (object_type_check == 1
        || (object_type_check == 2 && (o->Type == EMS_TYPE_TEXT_FORMAT)))
    {
#if(EMS_USE_ESC_COMBINATION)
        if ((data->dcs == SMSAL_DEFAULT_DCS) &&
            (UI_TEST_ESC_CHARACTER(data->textBuffer[data->CurrentPosition.OffsetToText])))
        {
            count = ForwardCurrentPosition(data, 1);
            if (count == 1)
            {
                ForwardCurrentPosition(data, 1);
            }
        }
        else
#endif /* (EMS_USE_ESC_COMBINATION) */ 
#if(EMS_USE_CRLF_COMBINATION)
            if (UI_TEST_CR_CHARACTER(data->textBuffer[data->CurrentPosition.OffsetToText]))
            {
                count = ForwardCurrentPosition(data, 1);
                if (UI_TEST_LF_CHARACTER(data->textBuffer[data->CurrentPosition.OffsetToText]))
                {
                    ForwardCurrentPosition(data, 1);
                }
            }
            else
#endif /* (EMS_USE_CRLF_COMBINATION) */ 
            {
                /*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
                /*PMT IRE END*/
                MMI_ASSERT(!(next_ems_moves < 0));
                count = ForwardCurrentPosition(data, (U16)next_ems_moves);
                if (count >= 1)
                {
                    count = 1;
                }
                /*PMT IRE START*/
#else /* __MMI_INDIC_ALG__ */ 
                count = ForwardCurrentPosition(data, 1);
#endif /* __MMI_INDIC_ALG__ */ 
                /*PMT IRE END*/
            }
    }
    else
        count = ForwardCurrentPosition(data, 1);

    return (count);
}

/* Moves the cursor forwards by the number of steps specified.
   Cursor starts at start position. (If data->CursorPosition is not at
   the given start position, then the cursor will be moved to start position first)
   The cursor will not move beyond one step before the given end position  */


/*****************************************************************************
 * FUNCTION
 *  MoveCurrentPosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  start       [?]         
 *  end         [?]         
 *  steps       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MoveCurrentPosition(EMSData *data, EMSPosition *start, EMSPosition *end, kal_uint16 steps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 diff;
    U8 object_flag;
    U8 done_flag = 0;
    S32 count = 0;
    U8 back_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object_flag = 0;
    diff = data->CurrentPosition.OffsetToText - start->OffsetToText;
    if ((start->Object != NULL) && (start->Object->OffsetToText == start->OffsetToText))
    {
        object_flag = 1;
    }
    if (diff < 0)
    {
        while (!done_flag)
        {
            if (data->CurrentPosition.OffsetToText == start->OffsetToText)
            {
                if (object_flag)
                {
                    if ((data->CurrentPosition.Object == start->Object) &&
                        (data->CurrentPosition.Object->OffsetToText == start->OffsetToText))
                    {
                        BackwardCurrentPosition(data, 1);
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
    else if (diff > 0)
    {
        while (!done_flag)
        {
            if (data->CurrentPosition.OffsetToText == start->OffsetToText)
            {
                if (object_flag)
                {
                    if ((data->CurrentPosition.Object == start->Object) &&
                        (data->CurrentPosition.Object->OffsetToText == start->OffsetToText))
                    {
                        BackwardCurrentPosition(data, 1);
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (BackwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
    else
    {
        S32 old_OffsetToText = data->CurrentPosition.OffsetToText;

        while (data->CurrentPosition.OffsetToText == old_OffsetToText)
        {
            if (BackwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
        while (!done_flag)
        {
            if (data->CurrentPosition.OffsetToText == start->OffsetToText)
            {
                if (object_flag)
                {
                    if ((data->CurrentPosition.Object == start->Object) &&
                        (data->CurrentPosition.Object->OffsetToText == start->OffsetToText))
                    {
                        BackwardCurrentPosition(data, 1);
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
    if (steps == 0)
    {
        return;
    }
    object_flag = 0;
    if ((end->Object != NULL) && (end->Object->OffsetToText == end->OffsetToText))
    {
        object_flag = 1;
    }
    if (data->CurrentPosition.OffsetToText == end->OffsetToText)
    {
        S32 old_OffsetToText = data->CurrentPosition.OffsetToText;

        while (data->CurrentPosition.OffsetToText == old_OffsetToText)
        {
            if (BackwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
            count--;
        }
        while (!done_flag)
        {
            if (count >= steps)
            {
                break;
            }
            count++;
            if (data->CurrentPosition.OffsetToText == end->OffsetToText)
            {
                if (object_flag)
                {
                    if ((data->CurrentPosition.Object == end->Object) &&
                        (data->CurrentPosition.Object->OffsetToText == end->OffsetToText))
                    {
                        back_flag = 1;
                        break;
                    }
                }
                else
                {
                    back_flag = 1;
                    break;
                }
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
        if (back_flag)
        {
            BackwardCurrentPosition(data, 1);
        }
        if (data->CurrentPosition.OffsetToText > end->OffsetToText)
        {
            BackwardCurrentPosition(data, 1);
        }
    }
    else
    {
        while (!done_flag)
        {
            if (count >= steps)
            {
                break;
            }
            count++;
            if (data->CurrentPosition.OffsetToText == end->OffsetToText)
            {
                if (object_flag)
                {
                    if ((data->CurrentPosition.Object == end->Object) &&
                        (data->CurrentPosition.Object->OffsetToText == end->OffsetToText))
                    {
                        back_flag = 1;
                        break;
                    }
                }
                else
                {
                    back_flag = 1;
                    break;
                }
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
        if (back_flag)
        {
            BackwardCurrentPosition(data, 1);
        }
        if (data->CurrentPosition.OffsetToText >= end->OffsetToText)
        {
            if ((end->OffsetToText != data->textLength) && !((end->Object != NULL) && (end->Object != data->listHead)))
            {
                BackwardCurrentPosition(data, 1);
            }
            if ((data->CurrentPosition.Object != NULL) && (end->Object != NULL))
            {
                while (data->CurrentPosition.Object->OffsetToText > end->Object->OffsetToText)
                {
                    if (BackwardCurrentPosition(data, 1) != 1)
                    {
                        break;
                    }
                }
            }
        }
    }
}

/* Moves the cursor to a given position   */


/*****************************************************************************
 * FUNCTION
 *  MoveCursorToPosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  dst         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void MoveCursorToPosition(EMSData *data, EMSPosition *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 diff;
    U8 done_flag = 0;
    EMSPosition dst_copy = *dst;
    EMSPosition mapped_cursor_position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_map_position(data, &dst_copy, dst);
    EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
    diff = data->CurrentPosition.OffsetToText - dst->OffsetToText;

    if (diff < 0)
    {
        while (!done_flag)
        {
            EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
            if ((mapped_cursor_position.OffsetToText == dst->OffsetToText) &&
                (mapped_cursor_position.Object == dst->Object))
            {
                break;
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
    else if (diff > 0)
    {
        while (!done_flag)
        {
            EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
            if ((mapped_cursor_position.OffsetToText == dst->OffsetToText) &&
                (mapped_cursor_position.Object == dst->Object))
            {
                break;
            }
            if (BackwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
    else
    {
        S32 old_OffsetToText = data->CurrentPosition.OffsetToText;

        while (data->CurrentPosition.OffsetToText == old_OffsetToText)
        {
            if (BackwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
        if (data->CurrentPosition.OffsetToText < old_OffsetToText)
        {
            ForwardCurrentPosition(data, 1);
        }
        while (!done_flag)
        {
            EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
            if (mapped_cursor_position.Object == dst->Object)
            {
                break;
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
}

/* Moves the cursor backwards to the given position. If an object is encountered, it breaks  */
/* Returns 1 if dst is reached, otherwise, returns 0                                */


/*****************************************************************************
 * FUNCTION
 *  BackwardCurrentPositionObject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  dst         [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 BackwardCurrentPositionObject(EMSData *data, EMSPosition *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition mapped_cursor_position;
    U8 done = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
    {
        return (1);
    }
    while (!done)
    {
        if (BackwardCurrentPosition(data, 1) != 1)
        {
            done = 1;
            break;
        }
        EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
        if ((mapped_cursor_position.Object != NULL) && (mapped_cursor_position.Object->Type != EMS_TYPE_TEXT_FORMAT))
        {
            break;
        }
        if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
        {
            done = 1;
            break;
        }
    }
    return (done);
}


/*****************************************************************************
 * FUNCTION
 *  ForwardCurrentPositionObject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  dst         [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 ForwardCurrentPositionObject(EMSData *data, EMSPosition *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition mapped_cursor_position;
    U8 done = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
    {
        return (1);
    }
    while (!done)
    {
        if (ForwardCurrentPosition(data, 1) != 1)
        {
            done = 1;
            break;
        }
        EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
        if ((mapped_cursor_position.Object != NULL) && (mapped_cursor_position.Object->Type != EMS_TYPE_TEXT_FORMAT))
        {
            break;
        }
        if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
        {
            done = 1;
            break;
        }
    }
    return (done);
}

/* Moves the cursor backwards to the given position. If an object is encountered, it breaks  */
/* Returns 1 if dst is reached, otherwise, returns 0                                */


/*****************************************************************************
 * FUNCTION
 *  BackwardCurrentPositionSeekObject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  dst         [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 BackwardCurrentPositionSeekObject(EMSData *data, EMSPosition *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition mapped_cursor_position;
    U8 done = 0;
    U8 object_flag = 0;
    EMSPosition last_object_position = data->CurrentPosition;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
    {
        return (1);
    }
    while (!done)
    {
        EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
        if ((mapped_cursor_position.Object != NULL) && (mapped_cursor_position.Object->Type != EMS_TYPE_TEXT_FORMAT))
        {
            last_object_position = data->CurrentPosition;
            object_flag = 1;
            if (count > 0)
            {
                break;
            }
        }
        if (BackwardCurrentPosition(data, 1) != 1)
        {
            done = 1;
            break;
        }
        if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
        {
            done = 1;
            break;
        }
        count++;
    }
    EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
    if (object_flag && (count > 0) &&
        ((data->CurrentPosition.OffsetToText != dst->OffsetToText) || (data->CurrentPosition.Object != dst->Object)))
    {
        MoveCursorToPosition(data, &last_object_position);
    }
    else if (mapped_cursor_position.Object == NULL)
    {
        MoveCursorToPosition(data, &last_object_position);
    }
    return (done);
}


/*****************************************************************************
 * FUNCTION
 *  ForwardCurrentPositionSeekObject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  dst         [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 ForwardCurrentPositionSeekObject(EMSData *data, EMSPosition *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition mapped_cursor_position;
    U8 done = 0;
    EMSPosition last_object_position = data->CurrentPosition;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
    {
        return (1);
    }
    while (!done)
    {
        EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
        if ((mapped_cursor_position.Object != NULL) && (mapped_cursor_position.Object->Type != EMS_TYPE_TEXT_FORMAT))
        {
            last_object_position = data->CurrentPosition;
            if (count > 0)
            {
                break;
            }
        }
        if (ForwardCurrentPosition(data, 1) != 1)
        {
            done = 1;
            break;
        }
        if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
        {
            done = 1;
            break;
        }
        count++;
    }
    MoveCursorToPosition(data, &last_object_position);
    return (done);
}

/* Returns true if the given position is the last position  */
/* p=un-mapped EMS position                        */


/*****************************************************************************
 * FUNCTION
 *  TestLastPosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  p           [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 TestLastPosition(EMSData *data, EMSPosition *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_map_position(data, p, &dst);
    if ((dst.OffsetToText >= data->textLength) && (dst.Object == NULL))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

/* Returns true if the given position is the first position */
/* p=un-mapped EMS position                        */


/*****************************************************************************
 * FUNCTION
 *  TestFirstPosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  p           [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 TestFirstPosition(EMSData *data, EMSPosition *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((p->OffsetToText == 0) && (p->Object == NULL))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EMS_map_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  src         [?]     
 *  dst         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_map_position(EMSData *data, EMSPosition *src, EMSPosition *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->listHead == NULL)
    {
        *dst = *src;
    }
    else
    {
        EMSObject *object;

        if (src->Object == NULL)
        {
            object = data->listHead;
            if (object->OffsetToText == src->OffsetToText)
            {

            #if(EMS_ENABLE_TESTFIX_OBJECT_ORDERING)
                /* Nov-21-2003: TESTFIX: text format object followed by EMS object fix                 */
                /* Object ordering must be as text format object followed by other objects to use this fix   */
                if (object != NULL)
                {
                    if (object->Type == EMS_TYPE_TEXT_FORMAT)
                    {
                        if (object->next != NULL)
                        {
                            if (object->next->OffsetToText == object->OffsetToText)
                            {
                                dst->OffsetToText = src->OffsetToText;
                                dst->Object = object->next;
                            }
                            else
                            {
                                dst->OffsetToText = src->OffsetToText;
                                dst->Object = object;
                            }
                        }
                        else
                        {
                            dst->OffsetToText = src->OffsetToText;
                            dst->Object = NULL; //JF: fixed for cursor in text format, it should not mapping to a text format.
                        }
                    }
                    else
                    {
                        dst->OffsetToText = src->OffsetToText;
                        dst->Object = object;
                    }
                }
                else
                {
                    /* Nov-21-2003: TESTFIX: ends */
            #endif /* (EMS_ENABLE_TESTFIX_OBJECT_ORDERING) */ 

                    dst->OffsetToText = src->OffsetToText;
                    dst->Object = object;

                #if(EMS_ENABLE_TESTFIX_OBJECT_ORDERING)
                    /* Nov-21-2003: TESTFIX    */
                }
                /* Nov-21-2003: TESTFIX: ends */
                #endif /* (EMS_ENABLE_TESTFIX_OBJECT_ORDERING) */ 
            }
            else
            {
                dst->OffsetToText = src->OffsetToText;
                dst->Object = NULL;
            }
        }
        else
        {
            object = src->Object->next;
            if ((object != NULL) && (object->OffsetToText == src->OffsetToText))
            {
            #if(EMS_ENABLE_TESTFIX_OBJECT_ORDERING)
                /* Nov-21-2003: TESTFIX: text format object followed by EMS object fix                 */
                /* Object ordering must be as text format object followed by other objects to use this fix   */
                if (object->Type == EMS_TYPE_TEXT_FORMAT)
                {
                    if (object->next != NULL)
                    {
                        if (object->next->OffsetToText == object->OffsetToText)
                        {
                            dst->OffsetToText = src->OffsetToText;
                            dst->Object = object->next;
                        }
                        else
                        {
                            dst->OffsetToText = src->OffsetToText;
                            dst->Object = NULL;
                        }
                    }
                    else
                    {
                        dst->OffsetToText = src->OffsetToText;
                        dst->Object = NULL;
                    }
                }
                else
                {
                    /* Nov-21-2003: TESTFIX: ends */
            #endif /* (EMS_ENABLE_TESTFIX_OBJECT_ORDERING) */ 

                    dst->OffsetToText = src->OffsetToText;
                    dst->Object = object;

                #if(EMS_ENABLE_TESTFIX_OBJECT_ORDERING)
                    /* Nov-21-2003: TESTFIX    */
                }
                /* Nov-21-2003: TESTFIX: ends */
                #endif /* (EMS_ENABLE_TESTFIX_OBJECT_ORDERING) */ 
            }
            else
            {
                dst->OffsetToText = src->OffsetToText;
                dst->Object = NULL;
            }
        }
    }
}

U8 EMS_view_mode = 0;

#ifdef __MMI_MESSAGES_EMS__

#define EMS_ANIMATION_TIME    500

S32 EMS_current_predefined_sound_ID = -1;
U8 EMS_object_pre_defined_sound_flag = 0;
U8 EMS_object_user_defined_melody_flag = 0;
PU8 EMS_editor_sound_icon = NULL;
PU8 EMS_editor_melody_icon = NULL;
S32 EMS_object_x = 0;
S32 EMS_object_y = 0;
S32 EMS_object_width = 0;
S32 EMS_object_height = 0;
S32 EMS_object_frame_counter = 0;
S32 EMS_object_n_frames = 0;
S32 EMS_object_current_frame_size = 0;
S32 EMS_object_repeat_counter = 0;
U8 EMS_object_animation_timer_flag = 0;
U8 EMS_object_predefined_animation_timer_flag = 0;
gdi_handle ems_object_predefined_animation_handle;
EMSObject *EMS_current_object = NULL;
PU8 EMS_current_predefined_image;

extern U16 EMS_predefined_sounds[];

/*****************************************************************************
 * FUNCTION
 *  EMS_normal_play_pre_defined_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ID      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_normal_play_pre_defined_sound(S32 ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 aud_len;
    U8 *aud_data = NULL;
    U8  aud_type;
    U16 aud_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ID < 0)
    {
        ID = 0;
    }
    if (ID > 9)
    {
        ID = 9;
    }
    StopCurrentKeyPadTone();
    aud_id = EMS_predefined_sounds[ID];
    aud_data = get_audio(aud_id, &aud_type, &aud_len);
    mdi_audio_play_string(aud_data, (U16) aud_len, aud_type, DEVICE_AUDIO_PLAY_ONCE, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EMS_normal_stop_pre_defined_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_normal_stop_pre_defined_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_stop_string();
}


/*****************************************************************************
 * FUNCTION
 *  EMS_normal_play_user_defined_melody
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_normal_play_user_defined_melody(U8 *data, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_play_string(data, (U16) length, MDI_FORMAT_IMELODY, DEVICE_AUDIO_PLAY_ONCE, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EMS_normal_stop_user_defined_melody
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_normal_stop_user_defined_melody(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_stop_string();
}


/*****************************************************************************
 * FUNCTION
 *  EMS_silent_play_pre_defined_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ID      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_silent_play_pre_defined_sound(S32 ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(ID);
}


/*****************************************************************************
 * FUNCTION
 *  EMS_silent_stop_pre_defined_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_silent_stop_pre_defined_sound(void)
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
 *  EMS_silent_play_user_defined_melody
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_silent_play_user_defined_melody(U8 *data, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(data);
    UI_UNUSED_PARAMETER(length);
}


/*****************************************************************************
 * FUNCTION
 *  EMS_silent_stop_user_defined_melody
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_silent_stop_user_defined_melody(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

void (*EMS_play_pre_defined_sound) (S32 ID) = EMS_normal_play_pre_defined_sound;
void (*EMS_stop_pre_defined_sound) (void) = EMS_normal_stop_pre_defined_sound;
void (*EMS_play_user_defined_melody) (U8 *data, S32 length) = EMS_normal_play_user_defined_melody;
void (*EMS_stop_user_defined_melody) (void) = EMS_normal_stop_user_defined_melody;


/*****************************************************************************
 * FUNCTION
 *  EMS_enable_audio_playback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_enable_audio_playback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ems_is_disable_sound)
    {
        return;
    }

    EMS_play_pre_defined_sound = EMS_normal_play_pre_defined_sound;
    EMS_stop_pre_defined_sound = EMS_normal_stop_pre_defined_sound;
    EMS_play_user_defined_melody = EMS_normal_play_user_defined_melody;
    EMS_stop_user_defined_melody = EMS_normal_stop_user_defined_melody;
}


/*****************************************************************************
 * FUNCTION
 *  EMS_disable_audio_playback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_disable_audio_playback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_play_pre_defined_sound = EMS_silent_play_pre_defined_sound;
    EMS_stop_pre_defined_sound = EMS_silent_stop_pre_defined_sound;
    EMS_play_user_defined_melody = EMS_silent_play_user_defined_melody;
    EMS_stop_user_defined_melody = EMS_silent_stop_user_defined_melody;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_measure_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  o           [?]     
 *  width       [?]     
 *  height      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_measure_object(EMSObject *o, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = 0;
    *height = 0;
    switch (o->Type)
    {
        case EMS_TYPE_PIC:
        {
            *width = o->data->picture.hDim;
            *height = o->data->picture.vDim;
        }
            break;
        case EMS_TYPE_USERDEF_ANM:
        {
            *width = o->data->animation.hDim;
            *height = o->data->animation.vDim;
        }
            break;
        case EMS_TYPE_PREDEF_ANM:
        {
            PU8 image = get_image(EMS_predefined_animations[o->PredefNo]);

            gui_measure_image(image, width, height);
        }
            break;
        case EMS_TYPE_PREDEF_SND:
        {
            gui_measure_image(EMS_editor_sound_icon, width, height);
        }
            break;
        case EMS_TYPE_USERDEF_SND:
        {
            gui_measure_image(EMS_editor_melody_icon, width, height);
        }
            break;
    }
}


void gui_EMS_input_box_display_object_pic(S32 x,S32 y,U8* src,S32 src_size,S32 w,S32 h,S32 bits_per_pixel)
{
    gdi_color palette[64]; // maximum is 64 colors
    switch(bits_per_pixel)
    {
    case 1:
        {
            palette[0] = gdi_act_color_from_rgb(255,255,255,255); // white
            palette[1] = gdi_act_color_from_rgb(255,0,0,0); // black
        }
        break;
    case 2:
        {
            palette[0] = gdi_act_color_from_rgb(255,0,0,0); // black
            palette[1] = gdi_act_color_from_rgb(255,85,85,85); // dark grey
            palette[2] = gdi_act_color_from_rgb(255,170,170,170); // light grey
            palette[3] = gdi_act_color_from_rgb(255,255,255,255); // white
        }
        break;
    case 6:
        {
            S32 R,G,B,index;
            const static S32 value[]={0,85,170,255};

            index = 0;
            for(R=0;R<4;R++)
                for(G=0;G<4;G++)
                    for(B=0;B<4;B++,index++)
                        palette[index] = gdi_act_color_from_rgb(255,value[R],value[G],value[B]);
        }
        break;
    default:
        /* unsupported bits_per_pixel, display nothing */
        return;
    }

    // check the palette is the same as source key
    {
        BOOL source_key_enable;
        gdi_color source_key_value;
        int i;
        
        gdi_layer_get_source_key(&source_key_enable,&source_key_value);
        if(source_key_enable)
        {
            for(i = (1<<bits_per_pixel) - 1;i>=0;i--)
                if(palette[i] == source_key_value)
                    palette[i] = source_key_value ^ 1;
        }
    }
    
    gdi_bits_draw(
        x,y,
        src,
        src_size,
        w,h,
        bits_per_pixel,
        palette);

}


/*****************************************************************************
 * FUNCTION
 *  EMS_input_box_show_animation_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void EMS_input_box_show_animation_frame(void)
{
    S32 width,height;
    EMS_object_frame_counter++;
    if (EMS_object_frame_counter >= EMS_current_object->data->animation.cFrame)
        EMS_object_frame_counter = 0;

    width = EMS_current_object->data->animation.hDim;
    height = EMS_current_object->data->animation.vDim;
    
    gui_EMS_input_box_display_object_pic(
                        EMS_object_x,EMS_object_y,
                        (U8*) (EMS_current_object->data->animation.pdu 
                             + EMS_object_frame_counter * EMS_object_current_frame_size),
                        EMS_object_current_frame_size,
                        width,
                        height,
                        EMS_current_object->data->animation.bitsPerPixel);
    gui_BLT_double_buffer(EMS_object_x, EMS_object_y, EMS_object_x + width - 1, EMS_object_y + height - 1);
    if (EMS_current_object->data->animation.cFrame != 0)
    {
        if (EMS_object_frame_counter % EMS_current_object->data->animation.cFrame == 0)
            EMS_object_repeat_counter++;
    }
    if (EMS_current_object->data->animation.cRepeat != 0 
    && EMS_object_repeat_counter >= EMS_current_object->data->animation.cRepeat)
    {
        gui_cancel_timer(NULL);
    }
    else
    {
        gui_start_timer((EMS_current_object->data->animation.Duration + 1) * 100, EMS_input_box_show_animation_frame);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EMS_input_box_show_predefined_animation_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_input_box_show_predefined_animation_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_object_frame_counter++;
    if (EMS_object_frame_counter >= EMS_object_n_frames)
    {
        EMS_object_frame_counter = 0;
    }
    gui_push_clip();
    gui_set_clip(0, MMI_title_y + MMI_title_height, UI_device_width - 1, UI_device_height - MMI_button_bar_height - 2);
    gui_show_animated_image_frame(
        EMS_object_x,
        EMS_object_y,
        EMS_current_predefined_image,
        (S16) EMS_object_frame_counter);
    gui_pop_clip();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        EMS_object_x,
        EMS_object_y,
        EMS_object_x + EMS_object_width - 1,
        EMS_object_y + EMS_object_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
    gui_start_timer(EMS_ANIMATION_TIME, EMS_input_box_show_predefined_animation_frame);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_display_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                   [IN]        
 *  y                   [IN]        
 *  o                   [?]         
 *  display_cursor      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_display_object(S32 x, S32 y, EMSObject *o, U8 display_cursor)
{
#if(EMS_ENABLE_EDITOR_OBJECT_PLAYBACK)
    U8 playback_flag = 1;
#else
    U8 playback_flag = 0;
    if (EMS_view_mode)
        playback_flag = 1;
#endif

    switch (o->Type)
    {
        case EMS_TYPE_PIC:
            gui_EMS_input_box_display_object_pic(
                        x,y,
                        (U8*)o->data->picture.pdu,
                        o->data->picture.pdu_length,
                        o->data->picture.hDim,o->data->picture.vDim,
                        o->data->picture.bitsPerPixel);
            break;

        case EMS_TYPE_USERDEF_ANM:
            if (display_cursor)
            {
                EMS_object_x = x;
                EMS_object_y = y;
                EMS_object_frame_counter = 0;
                EMS_object_repeat_counter = 0;
                EMS_current_object = o;
            }
            
            EMS_object_current_frame_size = o->data->animation.pdu_length;
            if (o->data->animation.cFrame != 0)
                EMS_object_current_frame_size /= o->data->animation.cFrame;

            gui_EMS_input_box_display_object_pic(
                    x,y,
                    (U8*) o->data->animation.pdu,
                    EMS_object_current_frame_size,
                    o->data->animation.hDim,o->data->animation.vDim,
                    o->data->animation.bitsPerPixel);
            
            if (display_cursor && playback_flag)
            {
                EMS_object_animation_timer_flag = 1;
                gui_start_timer((o->data->animation.Duration + 1) * 100, EMS_input_box_show_animation_frame);
            }
            break;
        case EMS_TYPE_PREDEF_ANM:
        {
            PU8 image = get_image(EMS_predefined_animations[o->PredefNo]);

            gui_show_animated_image_frame(x, y, image, 0);
            if (display_cursor && playback_flag)
            {
                EMS_object_x = x;
                EMS_object_y = y;
                gui_measure_image(image, &EMS_object_width, &EMS_object_height);
                EMS_object_n_frames = gui_image_n_frames(image);
                EMS_object_frame_counter = 0;
                EMS_current_object = o;
                EMS_current_predefined_image = image;
                EMS_object_predefined_animation_timer_flag = 1;
                /* gui_start_timer(EMS_ANIMATION_TIME, EMS_input_box_show_predefined_animation_frame); */
                gdi_image_draw_animation(
                    x,
                    y,
                    image,
                    &ems_object_predefined_animation_handle); 
            }
        }
            break;
        case EMS_TYPE_PREDEF_SND:
        {
            /* If redraw background screen, don't play sound */
            if (mmi_is_redrawing_bk_screens())
            {
                return;
            }

            gui_show_transparent_image(x, y, EMS_editor_sound_icon, 0);
        #if defined(__MMI_EDITOR_SSP_SUPPORT__)
            if (display_cursor && playback_flag && !in_scrolling_flag)
        #else
            if (display_cursor && playback_flag)
        #endif
            {
                EMS_object_pre_defined_sound_flag = 1;
                EMS_play_pre_defined_sound(o->PredefNo);
            }
        }
            break;
        case EMS_TYPE_USERDEF_SND:
        {
            /* If redraw background screen, don't play sound */
            if (mmi_is_redrawing_bk_screens())
            {
                return;
            }

            gui_show_transparent_image(x, y, EMS_editor_melody_icon, 0);
        #if defined(__MMI_EDITOR_SSP_SUPPORT__)
            if (display_cursor && playback_flag && !in_scrolling_flag)
        #else
            if (display_cursor && playback_flag)
        #endif
            {
                EMS_object_user_defined_melody_flag = 1;
                /* MTK Joy added for customization, 1014 */
            #if defined(__MMI_IMELODY_SUPPORT__)
                EMS_play_user_defined_melody(o->data->sound.pdu, o->data->sound.pdu_length);
            #endif 
                /* MTK end */
            }
        }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_playback_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  o       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_playback_object(EMSObject *o)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (o->Type)
    {
        case EMS_TYPE_PREDEF_SND:
        {
            EMS_object_pre_defined_sound_flag = 1;
            EMS_play_pre_defined_sound(o->PredefNo);
        }
            break;
            /* MTK Joy added for customization, 1014 */
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_TYPE_USERDEF_SND:
        {
            EMS_object_user_defined_melody_flag = 1;
            EMS_play_user_defined_melody(o->data->sound.pdu, o->data->sound.pdu_length);
        }
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            /* MTK end */
    }
}


/*****************************************************************************
 * FUNCTION
 *  EMS_cancel_object_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_cancel_object_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EMS_object_animation_timer_flag)
    {
        gui_cancel_timer(EMS_input_box_show_animation_frame);
        EMS_object_animation_timer_flag = 0;
    }
    else if (EMS_object_predefined_animation_timer_flag)
    {
        /* gui_cancel_timer(EMS_input_box_show_predefined_animation_frame); */
        gdi_image_stop_animation(ems_object_predefined_animation_handle);
        EMS_object_predefined_animation_timer_flag = 0;
    }
    else if (EMS_object_pre_defined_sound_flag)
    {
        EMS_stop_pre_defined_sound();
        EMS_object_pre_defined_sound_flag = 0;
    }
    else if (EMS_object_user_defined_melody_flag)
    {
        EMS_stop_user_defined_melody();
        EMS_object_user_defined_melody_flag = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_set_text_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  o       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_set_text_format(UI_EMS_input_box *b, EMSObject *o)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 font_size = (U8) MEDIUM_FONT;
    U8 font_bold = 0;
    U8 font_italic = 0;
    U8 font_underline = 0;
    U8 strikethrough = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* color        c={0,0,0,100}; */

    /* UI_EMS_inputbox_text_color=c; */
    if (o == NULL)
    {
        EMS_SET_FONT(&UI_EMS_inputbox_medium_font);
        /* EMS_SET_TEXT_COLOR(UI_EMS_inputbox_text_color); */
        b->flags &=
            ~(UI_EMS_INPUT_BOX_CURRENT_ALIGN_LEFT | UI_EMS_INPUT_BOX_CURRENT_ALIGN_RIGHT |
              UI_EMS_INPUT_BOX_CURRENT_ALIGN_CENTER);
    }
    else
    {
        if (o->Type == EMS_TYPE_TEXT_FORMAT)
        {
            EMSTextFormat *t = &(o->data->text_format);

            b->flags &=
                ~(UI_EMS_INPUT_BOX_CURRENT_ALIGN_LEFT | UI_EMS_INPUT_BOX_CURRENT_ALIGN_RIGHT |
                  UI_EMS_INPUT_BOX_CURRENT_ALIGN_CENTER);
            switch (t->Alignment)
            {
                case EMS_ALIGN_LEFT:
                    b->flags |= UI_EMS_INPUT_BOX_CURRENT_ALIGN_LEFT;
                    break;
                case EMS_ALIGN_RIGHT:
                    b->flags |= UI_EMS_INPUT_BOX_CURRENT_ALIGN_RIGHT;
                    break;
                case EMS_ALIGN_CENTER:
                    b->flags |= UI_EMS_INPUT_BOX_CURRENT_ALIGN_CENTER;
                    break;
                case EMS_ALIGN_LANG_DEP:
                    b->flags |= UI_EMS_INPUT_BOX_CURRENT_ALIGN_LEFT;
                    break;
            }
            switch (t->FontSize)
            {
                case EMS_FONTSIZE_NORMAL:
                    font_size = (U8) UI_EMS_inputbox_medium_font.size;
                    /* c.r=0;c.g=0;c.b=0; */
                    break;
                case EMS_FONTSIZE_LARGE:
                    font_size = (U8) UI_EMS_inputbox_large_font.size;
                    /* c.r=255;c.g=0;c.b=0; */
                    break;
                case EMS_FONTSIZE_SMALL:
                    font_size = (U8) UI_EMS_inputbox_small_font.size;
                    /* c.r=0;c.g=0;c.b=255; */
                    break;
            }
        #ifndef __MMI_TEXT_FORMAT_WITHOUT_BOLD__
            if (t->isBold)
            {
                font_bold = 1;
            }
        #endif /* __MMI_TEXT_FORMAT_WITHOUT_BOLD__ */ 
            if (t->isItalic)
            {
                font_italic = 1;
            }
            if (t->isUnderline)
            {
                font_underline = 1;
            }
            if (t->isStrikethrough)
            {
                strikethrough = 1;
            }
            
            UI_EMS_inputbox_current_font.bold = font_bold;
            UI_EMS_inputbox_current_font.italic = font_italic;
            UI_EMS_inputbox_current_font.underline = font_underline;
            UI_EMS_inputbox_current_font.size = font_size;
            EMS_SET_FONT(&UI_EMS_inputbox_current_font);
        UI_EMS_current_alignment = t->Alignment;
            UI_EMS_strikethrough = strikethrough;
            
            /* UI_EMS_inputbox_text_color=c; */
            /* EMS_SET_TEXT_COLOR(UI_EMS_inputbox_text_color); */
        }
    }
}
#endif /* __MMI_MESSAGES_EMS__ */ 
#define UI_EMS_INPUTBOX_N_BREAK_CHARACTERS   1

UI_character_type EMS_input_box_break_characters[] = { 
    /* ' ',
     * '.',
     * ',',
     * '\\',
     * '/',
     * '-',
     * ':',
     * ';',
     * '?',
     * '!',
     * '|',
     * '+',
     * '=',
     * '_',
     */
    '\n'
};

UI_character_type EMS_input_box_new_line_character = (UI_character_type) '\n';


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_breakable_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_breakable_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < UI_EMS_INPUTBOX_N_BREAK_CHARACTERS; i++)
    {
        if ((UI_character_type) c == EMS_input_box_break_characters[i])
        {
            return (1);
        }
    }
    return (0);
}

#define UI_EMS_INPUT_BOX_BREAK_CHARACTER(c,flag)                                                      \
      {  S32 _ii_;                                                                                    \
         flag=0;                                                                                      \
         for(_ii_=0;_ii_<UI_EMS_INPUTBOX_N_BREAK_CHARACTERS;_ii_++)                                   \
         {  if((UI_character_type)c==(UI_character_type)EMS_input_box_break_characters[_ii_])         \
            {  flag=1;                                                                                \
               break;                                                                                 \
            }                                                                                         \
         }                                                                                            \
      }


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_new_line_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_new_line_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((UI_character_type) c == EMS_input_box_new_line_character)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

#if(EMS_USE_CRLF_COMBINATION)

static U8 gui_EMS_input_box_insert_new_line_no_sound(UI_EMS_input_box *b);
/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_new_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_insert_new_line(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret = EMS_OK;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gui_EMS_input_box_insert_new_line_no_sound(b);
    if (ret == EMS_NO_SPACE)
        UI_editor_play_tone_cannot_insert();

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_new_line_no_sound
 * DESCRIPTION
 *  Insert new line (0x0A) symbol into EMS editor
 * PARAMETERS
 *  b          [IN]            EMS object
 * RETURNS
 *  U8   EMS_OK if success, else fail
 *****************************************************************************/
U8 gui_EMS_input_box_insert_new_line_no_sound(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 ret = EMS_OK;
    U8 r;
    UI_character_type c;
    EMSTextFormat saved_fmt;

#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    U8 s[2] = {0x00, 0x0A};
#else 
    U8 s[2] = {0x0A, 0x00};
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif

    /* If current position before new line symbol, we need move after new line symbol because 
       it'll reset alignment when input 'enter' symbol */
    r = gui_EMS_input_box_get_next_character(b, &c);
    if ((r == 1) && ((c == 0x0D) || (c == 0x0A)))
    {
        /* Save text format before move cursor, in gui_EMS_input_box_next text format will be changed */
        saved_fmt = b->text_format;
        gui_EMS_input_box_next(b);
        /* Restore text format after move cursor */
        b->text_format = saved_fmt;
    }

    /* Overwrite mode is un-implemented */
    if (AddString(b->data, s, 1, &b->text_format) == EMS_NO_SPACE)
    {
        b->overflow_callback();
        ret = EMS_NO_SPACE;
    }
    else
    {
        b->change_callback();
    }

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        gui_emsc_change_request(b->data->CurrentPosition);
#endif

    if ((r == 1) && ((c == 0x0D) || (c == 0x0A)))
    {
        gui_EMS_input_box_previous(b);
        /* Restore text format after move cursor */
        b->text_format = saved_fmt;

        if (b->data->CurrentTextFormatObj)
        {
            /* DO NOT reset alignment when insert alignment in the middle of a parah covered by text format object */
            if (!((b->data->CurrentPosition.OffsetToText >= b->data->CurrentTextFormatObj->OffsetToText)
                && (b->data->CurrentPosition.OffsetToText < b->data->CurrentTextFormatObj->OffsetToText + b->data->CurrentTextFormatObj->data->text_format.textLength)))
            {
                b->text_format.Alignment = EMS_ALIGN_LANG_DEP; // reset alignment only when in the end of the paragraph
            }
        }
        else
        {
            b->text_format.Alignment = EMS_ALIGN_LANG_DEP; // reset alignment only when in the end of the paragraph
        }
    }

    gui_EMS_input_box_locate_cursor(b);
    return ret;
}

#else /* (EMS_USE_CRLF_COMBINATION) */ 


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_new_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_insert_new_line(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_EMS_input_box_insert_character(b, EMS_input_box_new_line_character);
    return EMS_OK;
}

#endif /* (EMS_USE_CRLF_COMBINATION) */ 

#define EMS_SET_BREAK_POSITION()                                     \
{  break_line_width=line_width;                                      \
   break_line_height=line_height;                                    \
   break_line_object_count=line_object_count;                        \
   break_line_alignment=line_alignment;                              \
   break_line_text_object_count=line_text_object_count;              \
}

#define EMS_SET_NEXT_BREAK_POSITION()                                \
{  break_line_width=line_width;                                      \
   break_line_height=line_height;                                    \
   break_line_object_count=line_object_count+1;                      \
   break_line_alignment=line_alignment;                              \
   break_line_text_object_count=line_text_object_count;              \
}


/*****************************************************************************
 * FUNCTION
 *  EMS_handle_CRLF_navigation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_handle_CRLF_navigation(EMSData *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 r;
    EMSPosition p;
    UI_character_type c;
    EMSObject *o;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(EMS_USE_CRLF_COMBINATION)
    p = data->CurrentPosition;
    r = gui_EMS_input_box_get_next_object(data, &p, &c, &o);
    if ((r == 1) && UI_TEST_LF_CHARACTER(c))
    {
        p = data->CurrentPosition;
        r = gui_EMS_input_box_get_previous_object(data, &p, &c, &o);
        if ((r == 1) && UI_TEST_CR_CHARACTER(c))
        {
            BackwardCurrentPosition(data, 1);
            return;
        }
    }
#endif /* (EMS_USE_CRLF_COMBINATION) */ 
#if(EMS_USE_ESC_COMBINATION)
    if (data->dcs == SMSAL_DEFAULT_DCS)
    {
        p = data->CurrentPosition;
        r = gui_EMS_input_box_get_previous_object(data, &p, &c, &o);
        if ((r == 1) && UI_TEST_ESC_CHARACTER(c))
        {
            BackwardCurrentPosition(data, 1);
        }
    }
#endif /* (EMS_USE_ESC_COMBINATION) */ 
}


U8 EMS_object_width_cache[128];
U8 EMS_object_height_cache[128];

/* Gurinder - 03/15/2004 - EMS Input Box InfoBar BG Image */
extern S32 wgui_EMS_inputbox_information_bar_height;

#define MAX_EMS_DISP_CLUSTER_LEN 50
/* START TARUN PMT 20050128 */
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
extern BOOL cancelWidth;
#endif 
//END TARUN PMT 20050128
//W05.52 Fix Cursor Moviong issue for ESC character

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_back_cursor_for_ESC_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]     
 *  position        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_back_cursor_for_ESC_character(EMSData *data, EMSPosition *position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *current_object;
    UI_character_type current_character;
    U8 object_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object_type = gui_EMS_input_box_get_previous_object(data, position, &current_character, &current_object);   /* get next character */
    if (1 == object_type)
    {
        if (UI_TEST_ESC_CHARACTER(current_character))
        {
            if (BackwardCurrentPositionSkipCR(data) != 1)
            {
                UI_editor_play_tone_cannot_navigate();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_EMS_input_box
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_EMS_input_box(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 begin_tick,end_tick;
    static S32 count = 0;
#if defined(__MMI_EDITOR_FORCE_AUTO_SCROLLBAR__) && defined(GUI_INPUT_BOX_CACHE_SUPPORT)
    U8 scrollbar_state;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_ems_is_disable_show == MMI_TRUE)
    {
        return;
    }
    
    if(b == NULL || b->data == NULL) return; // avoid invalid data source
#if defined(__MMI_EDITOR_FORCE_AUTO_SCROLLBAR__) && defined(GUI_INPUT_BOX_CACHE_SUPPORT)
    scrollbar_state = b->scrollbar_state;
#endif
    kal_get_time(&begin_tick);
    gui_show_EMS_input_box_ext(b, (-1), (-1));

#if defined(__MMI_EDITOR_FORCE_AUTO_SCROLLBAR__) && defined(GUI_INPUT_BOX_CACHE_SUPPORT)
    if ((b->flags & UI_EMS_INPUT_BOX_AUTO_DISABLE_SCROLLBAR)
        && scrollbar_state != b->scrollbar_state)
    {
        if (gui_inputs_cache_is_valid())
        {
            gui_emsc_all_line_update();
            if (!(b->flags & UI_EMS_INPUT_BOX_DISABLE_CURSOR_DRAW))
            {
                gui_EMS_input_box_locate_cursor(b);
            }
            gui_show_EMS_input_box_ext(b, -1, -1);
        }
    }
#endif
    
    kal_get_time(&end_tick);
    end_tick -= begin_tick;
    end_tick = kal_ticks_to_milli_secs(end_tick);
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_EMS_LEAVE_SHOWN, count++, end_tick);
}


void gui_show_EMS_input_box_ext(UI_EMS_input_box *b, S32 move_to_x, S32 move_to_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    U32 flags;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    b->flags &= ~UI_EMS_INPUT_BOX_TRANSPARENT_BACKGROUND;
#endif

    gui_push_clip();
#ifdef __MMI_MESSAGES_EMS__
        EMS_cancel_object_focus();
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    flags = b->flags;
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (!(flags & UI_EMS_INPUT_BOX_DISABLE_DRAW))
    {
        gdi_push_and_set_alpha_blending_source_layer(gui_inputs_get_source_layer());
    }
#endif

#ifndef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_show_EMS_input_box_basic(b, move_to_x, move_to_y);
#else
    
    if (gui_inputs_cache_is_valid())
    {
        MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_EMS_ENTER_SHOWN_WITH_CACHE);

        gui_show_EMS_input_box_with_cache(b, move_to_x, move_to_y);

        if (gui_inputs_cache_get_error_code() <= 0)
        {
            MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_EMS_ENTER_SHOWN);
            g_editor_line.line_char = temp_line_char;
            gui_show_EMS_input_box_basic(b, move_to_x, move_to_y);
        }
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_EMS_ENTER_SHOWN);
        g_editor_line.line_char = temp_line_char;
        gui_show_EMS_input_box_basic(b, move_to_x, move_to_y);
    }
    
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (!(flags & UI_EMS_INPUT_BOX_DISABLE_DRAW))
        gdi_pop_and_restore_alpha_blending_source_layer();
#endif

    gui_pop_clip();
}


void gui_show_EMS_input_box_basic(UI_EMS_input_box *b, S32 move_to_x, S32 move_to_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    ems_input_box_show_struct bs_struct;
    ems_input_box_show_struct* bs = &bs_struct;
    S32 h_medium;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* init the structure bs*/
    gui_init_ems_show_struct(b, bs);
    
    if (!(bs->flags & UI_EMS_INPUT_BOX_DISABLE_DRAW) 
        && !(bs->flags & UI_EMS_INPUT_BOX_DISABLE_CURSOR_DRAW))
    {
        UI_cursor_x1 = 0;
        UI_cursor_y1 = 0;
        UI_cursor_x2 = 0;
        UI_cursor_y2 = 0;
    }

#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
    if (!(bs->flags & UI_EMS_INPUT_BOX_VIEW_MODE))
        overwrite_current_language_for_hindi_rules_based_on_input_method();
#endif 
    
    if (((-1) != move_to_x) || ((-1) != move_to_y))
    {
        bs->flags |= UI_EMS_INPUT_BOX_DISABLE_DRAW;
        bs->find_new_cursor_flag = FINDING_CURSOR;
        bs->move_to_x = move_to_x;
        bs->move_to_y = move_to_y;

        /* The previouse cursor x offset is invalid*/
        b->saved_cursor_ax = -1;
    }
    else
    {
        bs->find_new_cursor_flag = NORMAL_CURSOR;
        bs->move_to_x = move_to_x;
        bs->move_to_y = move_to_y;
    }

    if (bs->flags & UI_EMS_INPUT_BOX_PREVIOUS_LINE
        || bs->flags & UI_EMS_INPUT_BOX_NEXT_LINE
        || bs->flags & UI_EMS_INPUT_BOX_PREVIOUS_OBJECT 
        || bs->flags & UI_EMS_INPUT_BOX_NEXT_OBJECT)
    {
        /* In these case, we need to find the cursor_p. 
         */
        bs->find_new_cursor_flag = FINDING_CURSOR;
    }
    else
    {
        /* the content maybe changed, the line count is invalid */
        b->n_lines = 0;
    }
        
#ifdef __MMI_BIDI_ALG__
    /* get the text BIDI type*/
    gui_get_ems_text_language_type(b, bs);
#endif /* __MMI_BIDI_ALG__ */
    
    
    /* prepare the layout area*/
    gui_prepare_ems_show_area(b, bs);
    
    /* set the view mode */
    if (bs->flags & UI_EMS_INPUT_BOX_VIEW_MODE)
    {
        EMS_view_mode = 1;
    }
    else
    {
        EMS_view_mode = 0;
    }
    

    /* draw the editor background*/
    gui_draw_ems_background_area(b, bs);

    /* update the text area range */
    gui_set_ems_text_area_range(b, bs);

    if (bs->flags & UI_EMS_INPUT_BOX_STATE_MULTITAP)
    {
        bs->multitap_flag = 1;
    }
    
    if ((bs->flags & UI_EMS_INPUT_BOX_OVERWRITE_MODE) && (!bs->multitap_flag))
    {
        bs->overwrite_flag = 1;
    }

    bs->xx = bs->x1 + 3;
    bs->yy = bs->y1 + 1 + b->display_y;
    b->first_displayed_line = -1;
    b->last_displayed_line = -1;
    EMS_map_position(b->data, &b->data->CurrentPosition, &bs->mapped_cursor_position);
    bs->line_alignment = EMS_ALIGN_LANG_DEP;
    bs->line_end_text_format = &UI_EMS_normal_text_format_object;
    lastest_EMS_alignment = UI_EMS_normal_text_format_object.data->text_format.Alignment;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    if (gui_inputs_cache_is_valid() && b->cache_begin_callback)
        b->cache_begin_callback(b, bs);
#endif

    h_medium = Get_CharHeightOfAllLang(MEDIUM_FONT) + EDITOR_LINE_ADDITION_PIXTEL;
    while (!bs->end_line && (bs->edit_width >= 0))
    {
        /* start to check the text content line by line*/
        gui_prepare_ems_new_line_loop(b, bs);
        
        /* find one line to break */
        bs->end_line = !gui_find_ems_one_line(b, bs);
        
        if (g_editor_line.line_height < h_medium)
        {
            g_editor_line.line_ascent += h_medium - g_editor_line.line_height;
            g_editor_line.line_height = h_medium;
        }
        
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        if (gui_inputs_cache_is_valid() && b->cache_line_ready_callback)
        {
            if (!b->cache_line_ready_callback(b, bs))
            {
                /* the line information query is end, break it */
                return;
            }
        }
#endif
        /* 
         * Now we can check the cursor line and the cursor_y, but we can't 
         * get the cursor_x, which need to be got at this line drawn(maybe bidi).
         */
        gui_set_ems_cursor_information(b, bs, MMI_TRUE);

        /* prepare to show the current line */
        gui_prepare_ems_one_line_show(b, bs);

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        if (!gui_inputs_cache_is_valid() || b->cache_update_type == GUI_INPUT_BOX_CACHE_UPDATE_ALL)
#endif
        {
            gui_set_ems_line_information(b, bs);
        }
        
        /* adjust the cursor_p for language special requirement*/
        gui_adjust_ems_cursor_for_language(b, bs);

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT        
        if (!gui_inputs_cache_is_valid())
#endif
        {
            if (bs->yty + g_editor_line.line_height > bs->y1
                && bs->yty < bs->y2
                || (!EMS_view_mode && bs->find_new_cursor_flag == FINDING_CURSOR) )
            {
                /* update the visible line information */
                if (b->first_displayed_line == -1)
                {
                    b->first_displayed_line = bs->n_lines;
                    b->line_before_visible_start_height = g_editor_line.line_height;
                }
                b->last_displayed_line = bs->n_lines;
                b->line_after_visible_start_height = g_editor_line.line_height;

                /* only draw the visible area */
                /* In the second pass, we translate all the objects to the string */
                gui_prepare_ems_total_str(b, bs);
                
#ifdef __MMI_BIDI_ALG__
                /* try to apply the BIDI alg to the current text content */
                gui_translate_ems_bidi_text(b, bs);
#endif
                /* draw the current line */
                gui_draw_ems_one_line(b, bs);
            }
        }
        
        gui_end_ems_new_line_loop(b, bs);
    }

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    if (gui_inputs_cache_is_valid())
    {
        return;
    }
#endif

    b->n_lines = bs->n_lines;
    
    if (EMS_view_mode
        && bs->find_new_cursor_flag == FINDING_CURSOR)
    {
        gui_find_ems_cursor_position_for_view_mode(b, bs);
    }

    gui_draw_ems_under_line(b, bs);
    
    if ((!EMS_view_mode) && (((-1) != move_to_x) || ((-1) != move_to_y)))
    {
        gui_EMS_input_box_set_text_format_cursor_position(b);
    }
    
    /* draw special remaining counter */
    gui_ems_show_special_remaining_counter(b);
    
    /* draw the scroll bar */
    gui_show_ems_scroll_bar(b, bs);
    
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
    restore_current_language_for_hindi_rules();
#endif 
}


#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
void gui_show_EMS_input_box_with_cache(UI_EMS_input_box *b, S32 move_to_x, S32 move_to_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    ems_input_box_show_struct bs_struct;
    ems_input_box_show_struct* bs = &bs_struct;
    S32 i;
    
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
    static S32 old_indic_rules = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* init the structure bs*/
    gui_init_ems_show_struct(b, bs);

    if (!(bs->flags & UI_EMS_INPUT_BOX_DISABLE_DRAW) 
        && !(bs->flags & UI_EMS_INPUT_BOX_DISABLE_CURSOR_DRAW))
    {
        UI_cursor_x1 = 0;
        UI_cursor_y1 = 0;
        UI_cursor_x2 = 0;
        UI_cursor_y2 = 0;
    }

    if (gui_emsc_is_dirty(b))
    {
        gui_inputs_cache_create(b);
        gui_emsc_all_line_update();
        
        if (gui_inputs_cache_get_error_code() <= 0)
        {
            return;
        }
    }

    EDITOR_LOCK;
    /* request the visible line cache ready */
    while (gui_emsc_visible_line_shown_request() < 0)
    {
        if (gui_inputs_cache_get_error_code() <= 0)
        {
            EDITOR_UNLOCK;
            return;
        }
        
        gui_emsc_partial_line_update();

        if (gui_inputs_cache_get_error_code() <= 0)
        {
            EDITOR_UNLOCK;
            return;
        }
    }
    
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
    if (!(bs->flags & UI_EMS_INPUT_BOX_VIEW_MODE))
    {
        overwrite_current_language_for_hindi_rules_based_on_input_method();
        if (old_indic_rules != (S32)indic_rules_current_set_language)
        {
            gui_emsc_all_line_update();
            old_indic_rules = (S32)indic_rules_current_set_language;
        }
    }
#endif 
    
    if (((-1) != move_to_x) || ((-1) != move_to_y))
    {
        bs->flags |= UI_EMS_INPUT_BOX_DISABLE_DRAW;
        bs->find_new_cursor_flag = FINDING_CURSOR;
        bs->move_to_x = move_to_x;
        bs->move_to_y = move_to_y;

        /* The previouse cursor x offset is invalid*/
        b->saved_cursor_ax = -1;
    }
    else
    {
        bs->find_new_cursor_flag = NORMAL_CURSOR;
        bs->move_to_x = move_to_x;
        bs->move_to_y = move_to_y;
    }

    if (bs->flags & UI_EMS_INPUT_BOX_PREVIOUS_LINE
        || bs->flags & UI_EMS_INPUT_BOX_NEXT_LINE
        || bs->flags & UI_EMS_INPUT_BOX_PREVIOUS_OBJECT 
        || bs->flags & UI_EMS_INPUT_BOX_NEXT_OBJECT)
    {
        /* In these case, we need to find the cursor_p. 
         */
        bs->find_new_cursor_flag = FINDING_CURSOR;
    }
    else
    {
        /* the content maybe changed, the line count is invalid */
        b->n_lines = 0;
    }
        
#ifdef __MMI_BIDI_ALG__
    /* get the text BIDI type*/
    gui_get_ems_text_language_type(b, bs);
#endif /* __MMI_BIDI_ALG__ */
    
    /* prepare the layout area*/
    gui_prepare_ems_show_area(b, bs);
    
    /* set the view mode */
    if (bs->flags & UI_EMS_INPUT_BOX_VIEW_MODE)
    {
        EMS_view_mode = 1;
    }
    else
    {
        EMS_view_mode = 0;
    }
    
    EDITOR_UNLOCK;
    /* draw the editor background*/
    gui_draw_ems_background_area(b, bs);
    if (gui_inputs_cache_get_error_code() <= 0)
    {
        return;
    }
    EDITOR_LOCK;

    /* update the text area range */
    gui_set_ems_text_area_range(b, bs);

    if (bs->flags & UI_EMS_INPUT_BOX_STATE_MULTITAP)
    {
        bs->multitap_flag = 1;
    }
    
    if ((bs->flags & UI_EMS_INPUT_BOX_OVERWRITE_MODE) && (!bs->multitap_flag))
    {
        bs->overwrite_flag = 1;
    }

    bs->xx = bs->x1 + 3;
    bs->yy = bs->y1 + 1 + b->display_y;
    b->first_displayed_line = -1;
    b->last_displayed_line = -1;
    EMS_map_position(b->data, &b->data->CurrentPosition, &bs->mapped_cursor_position);
    bs->line_alignment = EMS_ALIGN_LANG_DEP;
    bs->line_end_text_format = &UI_EMS_normal_text_format_object;
    lastest_EMS_alignment = UI_EMS_normal_text_format_object.data->text_format.Alignment;
    b->n_lines = gui_emsc_total_line_count();
    
    /* set bs by visible line cache */
    gui_preset_ems_visible_line(b, bs);
    
    /***************MULTILINE BIG LOOP BEGIN *****************************/
    for(i=bs->sl.index; i<=bs->el.index; i++)
    {
        /* no visible line */
        if (i < 0)
            break;

        /* prepare to show the current line */
        gui_prepare_ems_one_line_context(b, bs);
        
        gui_set_ems_cursor_information(b, bs, MMI_FALSE);

        if (bs->yty + g_editor_line.line_height > bs->y1 && bs->yty < bs->y2)
        {
            /* update the visible line information */
            if (b->first_displayed_line == -1)
            {
                b->first_displayed_line = bs->n_lines;
                b->line_before_visible_start_height = g_editor_line.line_height;
            }
            b->last_displayed_line = bs->n_lines;
            b->line_after_visible_start_height = g_editor_line.line_height;
        }

        /* adjust the cursor_p for language special requirement*/
        gui_adjust_ems_cursor_for_language(b, bs);

        /* only draw the visible area */
        /* In the second pass, we translate all the objects to the string */
        gui_prepare_ems_total_str(b, bs);
                
#ifdef __MMI_BIDI_ALG__
        /* try to apply the BIDI alg to the current text content */
        gui_translate_ems_bidi_text(b, bs);
#endif

        EDITOR_UNLOCK;
        /* draw the current line */
        gui_draw_ems_one_line(b, bs);
        
        if (gui_inputs_cache_get_error_code() <= 0)
        {
            return;
        }
        
        EDITOR_LOCK;

        gui_end_ems_new_line_loop(b, bs);
    }

    /* visible line is completed */
    gui_find_ems_cursor_from_cache(b, bs);

    /* now we set the ty to the last line of the whole text */
    if (gui_inputs_cache_is_not_in_update() || b->last_display_height == 0)
	    b->display_height = gui_emsc_total_line_height();
    else 
        b->display_height = b->last_display_height;
    
    if (bs->el.index >= 0)
        bs->ty += b->display_height - (bs->el.offset_y + g_editor_line.line_height);
    else
        bs->ty += b->display_height;
    
    if (EMS_view_mode
        && bs->find_new_cursor_flag == FINDING_CURSOR)
    {
        gui_find_ems_cursor_position_for_view_mode(b, bs);
    }

    gui_draw_ems_under_line(b, bs);
    
    EDITOR_UNLOCK;

    if ((!EMS_view_mode) && (((-1) != move_to_x) || ((-1) != move_to_y)))
    {
        gui_EMS_input_box_set_text_format_cursor_position(b);
    }
    
    /* draw special remaining counter */
    gui_ems_show_special_remaining_counter(b);
        
    /* draw the scroll bar */
    gui_show_ems_scroll_bar(b, bs);
    
    /* notify the cursor pos change */
    gui_ems_cursor_info_update(b);
    
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
    restore_current_language_for_hindi_rules();
#endif 
}
#endif


/*****************************************************************************
 * FUNCTION
 *  gui_ems_cursor_info_update
 * DESCRIPTION
 *  
 *  
 * PARAMETERS
 *  b       [IN]        EMS inputs object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_ems_cursor_info_update(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cursor_offset;
    gui_evt_inputs_cursor_changed_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cursor_offset = (S32)b->data->CurrentPosition.OffsetToText;
    if (!(b->flags & UI_EMS_INPUT_BOX_DISABLE_DRAW) 
        && cursor_offset != b->last_cursor_offset)
    {
        b->last_cursor_offset = cursor_offset;
        
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_GUI_INPUTS_CURSOR_CHANGED);
        evt.cursor_pos = cursor_offset;

        if (!mmi_frm_is_event_posted((mmi_event_struct*)&evt))
        {
            MMI_FRM_CB_EMIT_POST_EVENT(&evt);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_toggle_insert_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_toggle_insert_mode(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    if (b->flags & UI_EMS_INPUT_BOX_OVERWRITE_MODE)
    {
        b->flags &= ~UI_EMS_INPUT_BOX_OVERWRITE_MODE;
    }
    else
    {
        b->flags |= UI_EMS_INPUT_BOX_OVERWRITE_MODE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_backspace
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_backspace_no_draw(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 paragraph_text_align_flag = 0;
    U8 previous_paragraph_text_alignment = EMS_ALIGN_LANG_DEP;
    EMSPosition current_position;
    UI_character_type c;
    EMSObject *o;
    S32 steps;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    
    if (b->flags &UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)
    {
        steps = (S32)b->data->CurrentPosition.OffsetToText - (S32)b->input_mode_position.OffsetToText;
        if (steps > 0)
        {
            BackwardCurrentPosition(b->data, (U16)(steps/ENCODING_LENGTH));    
        }
        else if (steps < 0)
        {
            ForwardCurrentPosition(b->data, (U16)((-steps)/ENCODING_LENGTH));
        }
        
#ifdef __MMI_INDIC_ALG__
        if (b->data->CurrentTextFormatObj)
        {
            /* Restore text format length for Indic cluster */
            b->data->CurrentTextFormatObj->data->text_format.textLength -= saved_last_skip_pos * ENCODING_LENGTH;
            saved_last_skip_pos = 0;
        }
#endif /* __MMI_INDIC_ALG__ */
        /* b->data->CurrentPosition.OffsetToText = b->input_mode_position.OffsetToText; */     
    }

    if ((b->data != NULL) && (b->data->listHead != NULL))
    {
        current_position = b->data->CurrentPosition;
        if (gui_EMS_input_box_test_paragraph_start(b, &current_position))
        {
            gui_EMS_input_box_get_previous_object(b->data, &current_position, &c, &o);
            previous_paragraph_text_alignment = gui_EMS_input_box_get_previous_text_alignment(b, &current_position);
            paragraph_text_align_flag = 1;
        }
    }
    if (gui_EMS_cancel_current_position(b) == 0)
    {
        UI_editor_play_tone_cannot_change();
    }
    else
    {

        gui_EMS_input_box_set_text_format_cursor_position(b);
        if (paragraph_text_align_flag)
        {
            current_position = b->data->CurrentPosition;
            gui_EMS_input_box_set_paragraph_text_alignment(b, &current_position, previous_paragraph_text_alignment);
            gui_EMS_input_box_set_text_format_cursor_position(b);
        }

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        gui_emsc_change_request(b->data->CurrentPosition);
#endif

    }
#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_EMS_input_box_change_input_mode_for_smart_Abc(b);
#endif

}

void gui_EMS_input_box_backspace(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    EMSNationalLanguage old_l, new_l;
    gui_ems_table_mechanism_enum cur_m = mmi_7bit_get_table_mechanism();
    S32 count;
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    EMSPosition pos;
#endif /* GUI_INPUT_BOX_CACHE_SUPPORT */

#endif /* __SMS_R8_NATION_LANGUAGE__ */



    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef __SMS_R8_NATION_LANGUAGE__
    gui_EMS_input_box_backspace_no_draw(b);
#else

    count = b->UCS2_count;

    gui_EMS_input_box_backspace_no_draw(b);

    if (cur_m == EMS_AUTO_DETECTION && b->UCS2_count == 0)
    {
        mmi_7bit_get_national_lang_table(&old_l);
        mmi_7bit_choose_national_table(&b->ems_auto_dection, &new_l);
        
        if (new_l.locking_shift != old_l.locking_shift
            || new_l.single_shift != old_l.single_shift
            || count == 1)
        {
            gui_EMS_input_box_remove_extension_character(b, b->data);
            mmi_7bit_set_national_lang_table(&new_l);
            EMSSetNationalLanguage(b->data, &new_l);

            if (gui_EMS_input_box_insert_extension_character(b, b->data) != EMS_OK)
            {
                /* table can't be changed, retore the old table */
                gui_EMS_input_box_remove_extension_character(b, b->data);
                mmi_7bit_set_national_lang_table(&old_l);
                gui_EMS_input_box_insert_extension_character(b, b->data);
                EMSSetNationalLanguage(b->data, &old_l);
            }

            if (b->flags & UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)   
                b->input_mode_position = b->data->CurrentPosition;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
            pos.OffsetToText = 0;
            pos.Object = NULL;
            gui_emsc_change_request(pos);
#endif

        }
    }
#endif
    if (b->locate_cursor_flag)
        gui_EMS_input_box_locate_cursor(b);
    b->saved_cursor_ax = -1;
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_previous_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_previous_line(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 hflag = 0;
    EMSPosition current_position = b->data->CurrentPosition;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_EMS_INPUT_BOX_VIEW_MODE)
    {
    #ifdef __UI_EMS_HIGHLIGHT_LIST_SUPPORT__
        if(b->hilite_str_number != 0)
        {
            gui_EMS_input_box_previous_line_with_hilite_list(b);
            return;
        }
    #endif /* __UI_EMS_HIGHLIGHT_LIST_SUPPORT__ */

    #if UI_EMS_VIEW_PAGE
        if ((b->data->listHead == NULL) && (b->flags & UI_EMS_INPUT_BOX_VIEW_MODE))
        {
            gui_EMS_input_box_scroll_up(b);
            return;
        }
    #endif /* UI_EMS_VIEW_PAGE */
    }

#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    if(b->cursor_ay == 0 && b->display_y <0)
    {
        b->display_y +=20;
        if(b->display_y >0) b->display_y = 0;
        return;
    }
    b->flags |= (UI_EMS_INPUT_BOX_PREVIOUS_LINE | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    gui_show_EMS_input_box(b);
    b->flags &= ~(UI_EMS_INPUT_BOX_PREVIOUS_LINE | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    if (b->cursor_ay == 0)
    {
        hflag = 1;
    }
    /* if(!TestFirstPosition(b->data,&current_position)) */
    gui_EMS_input_box_locate_cursor(b);
    if ((b->flags & UI_EMS_INPUT_BOX_DISPLAY_HEADER) && hflag
        && (b->cursor_ay == 0) && (b->display_y != 0) &&
        (current_position.Object == NULL) /* && TestFirstPosition(b->data,&current_position) */ )
    {
        b->flags |= UI_EMS_INPUT_BOX_DISABLE_TONE;
        b->display_y += EMS_HEADER_SCROLL_SIZE; /* Scroll through header   */
        if (b->display_y > 0)
        {
            b->display_y = 0;
        }
    }

    gui_EMS_input_box_set_text_format_cursor_position(b);
#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_EMS_input_box_change_input_mode_for_smart_Abc(b);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_next_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_next_line(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_EMS_INPUT_BOX_VIEW_MODE)
    {
    #ifdef __UI_EMS_HIGHLIGHT_LIST_SUPPORT__
        if(b->hilite_str_number != 0)
        {
            gui_EMS_input_box_next_line_with_hilite_list(b);
            return;
        }
    #endif /* __UI_EMS_HIGHLIGHT_LIST_SUPPORT__ */

    #if UI_EMS_VIEW_PAGE
        if (b->data->listHead == NULL)
        {
            gui_EMS_input_box_scroll_down(b);
            return;
        }
    #endif /* UI_EMS_VIEW_PAGE */
    }

#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    b->flags |= (UI_EMS_INPUT_BOX_NEXT_LINE | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    gui_show_EMS_input_box(b);
    b->flags &= ~(UI_EMS_INPUT_BOX_NEXT_LINE | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    /* if(!TestLastPosition(b->data,&b->data->CurrentPosition)) */
    gui_EMS_input_box_set_text_format_cursor_position(b);
    gui_EMS_input_box_locate_cursor(b);

#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_EMS_input_box_change_input_mode_for_smart_Abc(b);
#endif
}

#ifdef __MMI_MESSAGES_EMS__


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_view_previous_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_view_previous_object(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_cancel_object_focus();
    b->flags |= (UI_EMS_INPUT_BOX_PREVIOUS_OBJECT | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    gui_show_EMS_input_box(b);
    b->flags &= ~(UI_EMS_INPUT_BOX_PREVIOUS_OBJECT | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    gui_EMS_input_box_locate_cursor(b);
    b->saved_cursor_ax = -1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_view_next_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_view_next_object(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_cancel_object_focus();
    b->flags |= (UI_EMS_INPUT_BOX_NEXT_OBJECT | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    gui_show_EMS_input_box(b);
    b->flags &= ~(UI_EMS_INPUT_BOX_NEXT_OBJECT | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    gui_EMS_input_box_locate_cursor(b);
    b->saved_cursor_ax = -1;
}
#endif /* __MMI_MESSAGES_EMS__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_inputbox_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_inputbox_empty(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((b->data->textLength == 0) && (b->data->listHead == NULL))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_highlight_cursor_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_EMS_input_box_highlight_cursor_end(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition *current_position = &b->data->CurrentPosition;
    EMSPosition previous_position;
    EMSPosition saved_current_position = b->data->CurrentPosition;
    U8 done = 0, bflag;
    UI_character_type current_character;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Move cursor backwards until a break character is encountered   */
    while (!done)
    {
        previous_position = *current_position;
        if ((current_position->Object != NULL) &&
            (current_position->Object->OffsetToText == current_position->OffsetToText))
        {
            break;
        }
        if (current_position->OffsetToText == 0)
        {
            break;
        }
        if (BackwardCurrentPosition(b->data, 1) != 1)
        {
            break;
        }
    #if(EMS_BYTE_ORDER_BIG_ENDIAN)
        current_character =
            b->data->textBuffer[current_position->OffsetToText +
                                1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
    #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        current_character =
            b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                                   textBuffer[current_position->OffsetToText + 1] << 8);
    #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        count++;
        UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            break;
        }
    }
    b->highlight_start_position = previous_position;
    /* *current_position=saved_current_position; */
    MoveCursorToPosition(b->data, &saved_current_position);

    /* Move cursor forwards until a break character is encountered */
#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    current_character =
        b->data->textBuffer[current_position->OffsetToText +
                            1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
#else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    current_character =
        b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                               textBuffer[current_position->OffsetToText + 1] << 8);
#endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
    if (b->data->CurrentPosition.OffsetToText >= b->data->textLength)
    {
        bflag = 1;
    }
    if (bflag)
    {
        done = 1;
        b->flags &= ~UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else
    {
        done = 0;
        b->flags |= UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
    }
    while (!done)
    {
        if ((current_position->Object != NULL) &&
            (current_position->Object->OffsetToText == current_position->OffsetToText))
        {
            break;
        }
        if (current_position->OffsetToText >= b->data->textLength)
        {
            break;
        }
        if (ForwardCurrentPosition(b->data, 1) != 1)
        {
            break;
        }
    #if(EMS_BYTE_ORDER_BIG_ENDIAN)
        current_character =
            b->data->textBuffer[current_position->OffsetToText +
                                1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
    #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        current_character =
            b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                                   textBuffer[current_position->OffsetToText + 1] << 8);
    #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        count++;
        UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            break;
        }
    }
    b->highlight_end_position = *current_position;
    gui_EMS_input_box_locate_cursor(b);
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_highlight_cursor_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  numOfChar       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_EMS_input_box_highlight_cursor_number(UI_EMS_input_box *b, S32 numOfChar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition *current_position = &b->data->CurrentPosition;
    EMSPosition saved_current_position = b->data->CurrentPosition;
    UI_character_type current_character;
    S32 count = 0, i, steps;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)
    {
        steps = (S32)current_position->OffsetToText - (S32)b->input_mode_position.OffsetToText;
        if (steps > 0)
        {
            BackwardCurrentPosition(b->data, (U16)(steps/ENCODING_LENGTH));    
        }
        else if (steps < 0)
        {
            ForwardCurrentPosition(b->data, (U16)((-steps)/ENCODING_LENGTH));
        }

        /* current_position->OffsetToText = b->input_mode_position.OffsetToText; */
    }

    for (i = 0; i < numOfChar; i++)
    {
        if ((current_position->Object != NULL) &&
            (current_position->Object->OffsetToText == current_position->OffsetToText))
        {
            break;
        }
        if (current_position->OffsetToText == 0)
        {
            break;
        }
        if (BackwardCurrentPosition(b->data, 1) != 1)
        {
            break;
        }
    #if(EMS_BYTE_ORDER_BIG_ENDIAN)
        current_character =
            b->data->textBuffer[current_position->OffsetToText +
                                1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
    #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        current_character =
            b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                                   textBuffer[current_position->OffsetToText + 1] << 8);
    #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        if (gui_ems_test_extention_character(current_character) && b->UCS2_count == 0)
        {
            i--;
        }
        else
            count++;
    }

    b->highlight_start_position = *current_position;
    /* *current_position=saved_current_position; */
    MoveCursorToPosition(b->data, &saved_current_position);

#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    current_character =
        b->data->textBuffer[current_position->OffsetToText +
                            1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
#else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    current_character =
        b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                               textBuffer[current_position->OffsetToText + 1] << 8);
#endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 

    b->flags |= UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;

    b->highlight_end_position = *current_position;
    
    if (b->locate_cursor_flag)
    {
        gui_EMS_input_box_locate_cursor(b);
    }
    
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_highlight_cursor_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_EMS_input_box_highlight_cursor_start(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition *current_position = &b->data->CurrentPosition;
    EMSPosition previous_position;
    EMSPosition saved_current_position = b->data->CurrentPosition;
    U8 done = 0, bflag;
    UI_character_type current_character;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (BackwardCurrentPosition(b->data, 1) != 1)
    {
        b->flags &= ~UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    /* Move cursor forwards until a break character is encountered */
    while (!done)
    {
        if ((current_position->Object != NULL) &&
            (current_position->Object->OffsetToText == current_position->OffsetToText))
        {
            break;
        }
        if (current_position->OffsetToText >= b->data->textLength)
        {
            break;
        }
        if (ForwardCurrentPosition(b->data, 1) != 1)
        {
            break;
        }
    #if(EMS_BYTE_ORDER_BIG_ENDIAN)
        current_character =
            b->data->textBuffer[current_position->OffsetToText +
                                1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
    #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        current_character =
            b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                                   textBuffer[current_position->OffsetToText + 1] << 8);
    #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        count++;
        UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            break;
        }
    }
    b->highlight_end_position = *current_position;
    /* *current_position=saved_current_position; */
    MoveCursorToPosition(b->data, &saved_current_position);

    /* Move cursor backwards until a break character is encountered   */
    if (BackwardCurrentPosition(b->data, 1) != 1)
    {
        b->flags &= ~UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    current_character =
        b->data->textBuffer[current_position->OffsetToText +
                            1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
#else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    current_character =
        b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                               textBuffer[current_position->OffsetToText + 1] << 8);
#endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
    if (bflag)
    {
        ForwardCurrentPosition(b->data, 1);
        done = 1;
        b->flags &= ~UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    else
    {
        done = 0;
        b->flags |= UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
    }
    while (!done)
    {
        previous_position = *current_position;
        if ((current_position->Object != NULL) &&
            (current_position->Object->OffsetToText == current_position->OffsetToText))
        {
            break;
        }
        if (current_position->OffsetToText == 0)
        {
            break;
        }
        if (BackwardCurrentPosition(b->data, 1) != 1)
        {
            break;
        }
    #if(EMS_BYTE_ORDER_BIG_ENDIAN)
        current_character =
            b->data->textBuffer[current_position->OffsetToText +
                                1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
    #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        current_character =
            b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                                   textBuffer[current_position->OffsetToText + 1] << 8);
    #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        count++;
        UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            break;
        }
    }
    b->highlight_start_position = previous_position;
    /* *current_position=previous_position; */
    MoveCursorToPosition(b->data, &previous_position);
    gui_EMS_input_box_locate_cursor(b);
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_text_format_forward_seek
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                               [?]         
 *  t                               [?]         
 *  length                          [?]         
 *  isModifyExistedTextformat       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_text_format_forward_seek(
        UI_EMS_input_box *b,
        EMSTextFormat *t,
        S32 *length,
        BOOL isModifyExistedTextformat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition current_position = b->data->CurrentPosition;
    UI_character_type c;
    EMSObject *o;
    U8 r;
    U8 done = 0;
    S32 text_format_object_count = 0;
    S32 text_length = 0;
    BOOL isModify = isModifyExistedTextformat;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!done)
    {
        if (current_position.OffsetToText >= b->data->textLength)
        {
            break;
        }
        r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
        switch (r)
        {
            case 0:
                done = 1;
                break;
            case 1:
                if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                {
                    done = 1;
                }
                if (text_format_object_count == 0)
                {
                    text_length++;
                }
                break;
            case 2:
                if (o->Type == EMS_TYPE_TEXT_FORMAT)
                {
                    text_format_object_count++;
                    if (isModify)
                    {
                        o->data->text_format.Alignment = t->Alignment;
                    }
                }
                break;
        }
    }
    *length = text_length;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_text_format_backward_seek
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                               [?]         
 *  t                               [?]         
 *  length                          [?]         
 *  isModifyExistedTextformat       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_text_format_backward_seek(
        UI_EMS_input_box *b,
        EMSTextFormat *t,
        S32 *length,
        BOOL isModifyExistedTextformat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_length = *length;
    EMSPosition current_position = b->data->CurrentPosition;
    UI_character_type c;
    EMSObject *o;
    U8 r;
    U8 done = 0;
    U8 counter_reset_flag = 0;
    S32 saved_text_length = 0;
    S32 old_OffsetToText;
    BOOL isModify = isModifyExistedTextformat;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!done)
    {
        if (BackwardCurrentPosition(b->data, 1) != 1)
        {
            if (counter_reset_flag)
            {
                text_length = saved_text_length;
            }
            break;
        }
        gui_EMS_input_box_set_text_format_cursor_position(b);
        current_position = b->data->CurrentPosition;
        r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
        switch (r)
        {
            case 0:
                if (counter_reset_flag)
                {
                    text_length = saved_text_length;
                }
                counter_reset_flag = 0;
                done = 1;
                break;
            case 1:
                if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                {
                    if (counter_reset_flag)
                    {
                        text_length = saved_text_length;
                    }
                    ForwardCurrentPosition(b->data, 1);
                    done = 1;
                }
                else
                {
                    text_length++;
                }
                counter_reset_flag = 0;
                break;
            case 2:
                if (o->Type == EMS_TYPE_TEXT_FORMAT)
                {
                    if (text_length > 0)
                    {
                        saved_text_length = text_length + 1;
                    }
                    else
                    {
                        saved_text_length = text_length;
                    }
                    text_length = 0;
                    if (isModify)
                    {
                        o->data->text_format.Alignment = t->Alignment;
                    }
                    counter_reset_flag = 1;
                }
                break;
        }
    }
    *length = text_length;

#if(EMS_ENABLE_TESTFIX_OBJECT_ORDERING)
    old_OffsetToText = b->data->CurrentPosition.OffsetToText;
    while (b->data->CurrentPosition.OffsetToText == old_OffsetToText)
    {
        if (BackwardCurrentPosition(b->data, 1) != 1)
        {
            break;
        }
    }
    if (b->data->CurrentPosition.OffsetToText != old_OffsetToText)
    {
        ForwardCurrentPosition(b->data, 1);
    }
#endif /* (EMS_ENABLE_TESTFIX_OBJECT_ORDERING) */ 
}


/*****************************************************************************
 * FUNCTION
 *  GetTextFormatObjectAtPosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  p           [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSObject *GetTextFormatObjectAtPosition(EMSData *data, EMSPosition *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *current = data->listHead;
    U16 OffsetToText = (U16) p->OffsetToText;
    EMSObject *return_object = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (current != NULL)
    {
        if ((current->Type == EMS_TYPE_TEXT_FORMAT) && (current->OffsetToText == OffsetToText))
        {
            return_object = current;
            break;
        }
        if (current->OffsetToText > OffsetToText)
        {
            break;
        }
        current = current->next;
    }
    return (return_object);
}


/*****************************************************************************
 * FUNCTION
 *  gui_ems_get_current_text_format_for_position_ex
 * DESCRIPTION
 *  Get the text format of position. The format object cover the position p, while
 *  gui_ems_get_current_text_format_for_position not cover the position p.
 * PARAMETERS
 *  data        [?]     
 *  p           [?]     
 * RETURNS
 *  Text format object
 *****************************************************************************/
EMSObject *gui_ems_get_current_text_format_for_position_ex(EMSData *data, EMSPosition *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *current = data->listHead;
    U16 OffsetToText = (U16) p->OffsetToText;
    EMSObject *return_object = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (current != NULL)
    {
        if ((current->Type == EMS_TYPE_TEXT_FORMAT) 
            && (current->OffsetToText < OffsetToText)
            && ((current->OffsetToText + current->data->text_format.textLength >= OffsetToText)))
        {
            return_object = current;
            break;
        }
        if (current->OffsetToText > OffsetToText)
        {
            break;
        }
        current = current->next;
    }
    return (return_object);
}


/*****************************************************************************
 * FUNCTION
 *  gui_ems_get_current_text_format_for_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  p           [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSObject *gui_ems_get_current_text_format_for_position(EMSData *data, EMSPosition *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *current = data->listHead;
    U16 OffsetToText = (U16) p->OffsetToText;
    EMSObject *return_object = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (current != NULL)
    {
        if ((current->Type == EMS_TYPE_TEXT_FORMAT) 
            && (current->OffsetToText <= OffsetToText)
            && ((current->OffsetToText + current->data->text_format.textLength > OffsetToText)))
        {
            return_object = current;
            break;
        }
        if (current->OffsetToText > OffsetToText)
        {
            break;
        }
        current = current->next;
    }
    return (return_object);
}
#ifdef __MMI_MESSAGES_EMS__


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_find_paragraph_range
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                   [?]     
 *  offsetToText        [?]     
 *  textLength          [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_find_paragraph_range(UI_EMS_input_box *b, kal_uint16 *offsetToText, kal_uint16 *textLength)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 *offset = offsetToText;
    kal_uint16 *textLen = textLength;
    EMSPosition saved_position = b->data->CurrentPosition;
    EMSPosition current_position = b->data->CurrentPosition;
    UI_character_type c;
    EMSObject *o;
    U8 r;
    U8 done = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Move to the beginning of paragraph */
    while (!done)
    {
        /* Reach the first position */
        if (BackwardCurrentPosition(b->data, 1) != 1)
        {
            break;
        }

        current_position = b->data->CurrentPosition;
        r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
        switch (r)
        {
                /* check if reach the start of paragraph */
            case 1:
                if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                {
                    ForwardCurrentPosition(b->data, 1);
                    done = 1;
                }
                break;

                /* ignore object */
            case 2:
                r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
                if (r == 1)
                {
                    if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                    {
                        ForwardCurrentPosition(b->data, 1);
                        done = 1;
                    }
                }
                break;

                /* impossible case */
            case 0:
            default:
                MMI_ASSERT(0);
                break;
        }
    }

    *offset = b->data->CurrentPosition.OffsetToText;

    done = 0;
    current_position = b->data->CurrentPosition;

    /* count to the end of the paragraph */
    while (!done)
    {

        if (current_position.OffsetToText >= b->data->textLength)
        {
            break;
        }
        r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
        switch (r)
        {
                /* count the number of characters in the paragraph */
            case 1:
                if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                {
                    done = 1;
                    (*textLen)++;
                    /* Exclude 0x0d and 0x0a */
                    /* (*textLen)--; */
                }
                else
                {
                    (*textLen)++;
                }
                break;

                /* To the end of the message */
            case 0:
                done = 1;
                break;

                /* ignore object */
            case 2:
                break;

                /* impossible case */
            default:
                MMI_ASSERT(0);
                break;
        }
    }

    MoveCursorToPosition(b->data, &saved_position);

}

/* Warning: Function requires the parameter t to be modified in some cases.
   So it is necessary to pass a copy instead of the actual data            */
/* MTK Joy added for text format insert, 0112 */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_text_alignment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  t       [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSTATUS gui_EMS_input_box_insert_text_alignment(UI_EMS_input_box *b, EMSTextFormat *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    kal_uint16 offsetToText = 0;
    kal_uint16 textLength = 0;
    EMSTATUS emsObjectStatus = EMS_OK;
    EMSTextFormat textFormat = *t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->data->textLength == 0)
    {
        return EMS_OK;
    }

    gui_EMS_input_box_find_paragraph_range(b, &offsetToText, &textLength);

    if (textLength == 0)
    {
        return EMS_OK;
    }

    if (b->data->CurrentTextFormatObj == NULL
        && b->text_format.Alignment == t->Alignment)
    {
        return EMS_OK;    
    }

    textFormat.textLength = textLength * 2;
    textFormat.FontSize = EMS_FONTSIZE_NORMAL;
    textFormat.isBold = KAL_FALSE;
    textFormat.isItalic = KAL_FALSE;
    textFormat.isStrikethrough = KAL_FALSE;
    textFormat.isUnderline = KAL_FALSE;
    
    emsObjectStatus = AddTextAlignment(b->data, offsetToText, &textFormat);

    gui_EMS_input_box_set_text_format_cursor_position(b);
    return emsObjectStatus;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_new_paragraph
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  t       [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSTATUS gui_EMS_input_box_insert_new_paragraph(UI_EMS_input_box *b, EMSTextFormat *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 emsObjectStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(EMS_USE_CRLF_COMBINATION)
    emsObjectStatus = gui_EMS_input_box_insert_new_line_no_sound(b);
#else
    emsObjectStatus = gui_EMS_input_box_insert_new_line(b);
#endif

    if ((EMSTATUS)emsObjectStatus == EMS_OK)
    {
        emsObjectStatus = gui_EMS_input_box_insert_text_alignment(b, t);

        /* Should roll back (Delete new line symbol added) if can't insert.*/
        if (emsObjectStatus != EMS_OK)
        {
        #ifdef LF_NEW_LINE_SYMBOL
            /* when we insert new line symbol, if current position before new line symbol, 
               we will move after new line symbol because it'll reset alignment when input 'enter' symbol.
               So in case the new line symbol is 0x0D 0A, after we insert newline, 
               "abc|0x0D0x0A"  --> "abc0x0D0A|0A "
               if we call gui_EMS_input_box_backspace, it will delete two characters(0D 0A), but in fact, 
               we insert only 0A, the count will be abnormal */
            CancelCurrentPosition(b->data, 1);
        #else /* LF_NEW_LINE_SYMBOL */
            gui_EMS_input_box_backspace(b);
        #endif /* LF_NEW_LINE_SYMBOL */
        }
    }

    return (EMSTATUS)emsObjectStatus;
}

/* MTK end */
#endif /* __MMI_MESSAGES_EMS__ */ 


/*****************************************************************************
 * FUNCTION
 *  EMS_move_graphical_cursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  start_x         [IN]        
 *  cursor_x        [IN]        
 *  max_count       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_move_graphical_cursor(EMSData *data, S32 start_x, S32 cursor_x, S32 max_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition current_position = data->CurrentPosition;
    U8 done = 0;
    S32 x = start_x;
    S32 count = 0;
    U8 r;
    EMSObject *current_object;
    UI_character_type current_character;
    S32 width = 0, height;
/*PMT IRE START*/
U8 text_format_flag=0;
#ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
    //EMSData *data_chk_type = data;
    //UI_character_type dummy_c = 0;
    S32 next_ems_moves = 0;
/*PMT IRE START*/
    PU8 src_p=(data->textBuffer + data->CurrentPosition.OffsetToText);
/*PMT IRE END*/
    PU8 dest_p;
/*PMT IRE START*/ 
    U8 cursor_truncation_flag=0;
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 
#if defined(__MMI_LANG_VIETNAMESE__)
    /* W05.38 Fix Viet Tone Cursor Moving Issue */
    U8 viet_tone_move = 0;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!done)
    {
        if (count >= max_count)
        {
            break;
        }
        /*PMT IRE START*/ 
        #ifdef __MMI_INDIC_ALG__
        if(text_format_flag==0)
        {
            current_position=data->CurrentPosition;
        }
        #endif /* __MMI_HINDI_ALG__ */ 
        /*PMT IRE END*/ 
        
        r = gui_EMS_input_box_get_next_object(data, &current_position, &current_character, &current_object);
        switch (r)
        {
            case 0:
                done = 1;
                break;
            case 1:
        #if(EMS_USE_CRLF_COMBINATION)
                if (UI_TEST_CR_CHARACTER(current_character) && (current_position.OffsetToText < data->textLength) &&
                    UI_TEST_LF_CHARACTER(data->textBuffer[current_position.OffsetToText]))
                {
                    width = 0;
                }
                else if (UI_TEST_LF_CHARACTER(current_character))
                {
                    width = 0;
                }
                else
        #endif /* (EMS_USE_CRLF_COMBINATION) */ 
            #if(EMS_USE_ESC_COMBINATION)
                if (UI_TEST_ESC_CHARACTER(current_character))
                {
                    width = 0;
                }
                else
            #endif /* (EMS_USE_ESC_COMBINATION) */ 
                {
                #if defined(__MMI_LANG_VIETNAMESE__)
                    /* MTK Terry for Cursor Move Up and Down Issue */
                    UI_character_type dummy_c = 0;
                    viet_tone_mark tone_mark = VIET_TONE_NONE;
                    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;

                    if ((current_character > 0x0040) && (current_character < 0x01B1))
                    {
                        r = gui_EMS_input_box_get_next_object(data, &current_position, &dummy_c, &current_object);      /* get next character */
                        if (1 == r)
                        {
                            tone_mark = mmi_viet_tone_mark(dummy_c);
                            if (VIET_TONE_NONE != tone_mark)
                            {
                                viet_vowel = mmi_viet_vowel_letter(current_character);
                                if (VIET_VOWEL_NONE != viet_vowel)
                                {
                                    current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                                    /* W05.38 Fix Viet Tone Cursor Moving Issue */
                                    viet_tone_move = 1;
                                }
                                else
                                {
                                    r = gui_EMS_input_box_get_previous_object(
                                            data,
                                            &current_position,
                                            &dummy_c,
                                            &current_object);
                                }
                            }
                            else
                            {
                                r = gui_EMS_input_box_get_previous_object(
                                        data,
                                        &current_position,
                                        &dummy_c,
                                        &current_object);
                            }
                        }
                        else if (0 != r)
                        {
                            r = gui_EMS_input_box_get_previous_object(
                                    data,
                                    &current_position,
                                    &dummy_c,
                                    &current_object);
                        }
                    }
                #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
/*PMT IRE START*/
                #ifdef __MMI_INDIC_ALG__
                #ifdef __MMI_INDIC_ALG__
                    if(text_format_flag)
                    {
                    src_p = (data->textBuffer + data->CurrentPosition.OffsetToText) - 2;
                    }
                    else
                    {
                        src_p = (data->textBuffer + data->CurrentPosition.OffsetToText);
                    }
        #endif /* __MMI_INDIC_ALG__ */
                    if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                    {
/* PMT START MAUI_00027731 */
                        dest_p = ire_get_next_cluster_p_with_size(src_p, gui_show_EMS_input_box_find_segment_end(data,src_p), &width);
/* PMT END MAUI_00027731 */
/*PMT IRE END*/
                        next_ems_moves = dest_p - src_p;
                        next_ems_moves = next_ems_moves >> 1;
/*PMT IRE START*/
                        if(text_format_flag)
                        {
                            if(count-1+next_ems_moves>max_count)
                            {
                                cursor_truncation_flag=1;
                                BackwardCurrentPosition(data,1);
                                break;
                            }
                        }
                        else
                        {
                            if(count+next_ems_moves>max_count)
                            {
                                cursor_truncation_flag=1;
                                break;
                            }

                        }
/*PMT IRE END*/
/*PMT IRE START*/
                        
                        if (next_ems_moves >= 2)    /* && r==2) //&& current_object->Type==EMS_TYPE_TEXT_FORMAT) */
                        {
                            ForwardCurrentPosition(data, (U16)(next_ems_moves - 1));
                            count += next_ems_moves - 1;
                            if((x+width+1) > (cursor_x + (width >> 1)))
                            {
                                BackwardCurrentPosition(data, (U16)(next_ems_moves - 1));
                                if(text_format_flag)
                                {
                                    BackwardCurrentPosition(data,1);
                                }

                            }
                            next_ems_moves = 0;
/*PMT IRE END*/
                        }
                        else
                        {
                            gui_measure_character(current_character, &width, &height);
                        }
                        src_p = dest_p;
                    }
                    else
/*PMT IRE START*/
                #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                        gui_measure_character(current_character, &width, &height);
                    width += 1;
                }
                x += width;
                break;
            #ifdef __MMI_MESSAGES_EMS__
            case 2:
                if (current_object->Type == EMS_TYPE_TEXT_FORMAT)
                {
/*PMT IRE START*/   
            text_format_flag=1;
/*PMT IRE END*/
                    width = 0;
                }
                else
                {
                    gui_EMS_input_box_measure_object(current_object, &width, &height);
                    width += 2;
                }
                x += width;
                break;
            #endif /* __MMI_MESSAGES_EMS__ */ 
        }
        if (x <= (cursor_x + (width >> 1)))
        {
 /*PMT IRE START*/
        #ifdef __MMI_INDIC_ALG__
            if(cursor_truncation_flag)
            {
                cursor_truncation_flag=0;
                break;

            }
        #endif /* __MMI_INDIC_ALG__ */ 
            if(text_format_flag==1 && r==1)
            {
                text_format_flag=0;
                continue;
            }
/*PMT IRE END*/
            count++;
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        #if defined(__MMI_LANG_VIETNAMESE__)
            /* W05.38 Fix Viet Tone Cursor Moving Issue */
            if (1 == viet_tone_move)
            {
                if (ForwardCurrentPosition(data, 1) != 1)
                {
                }
                viet_tone_move = 0;
            }
        #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
        }
        else
        {
            break;
        }
    }
}
/*PMT IRE START*/


#ifdef __MMI_INDIC_ALG__

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_post_template_addition_adjustment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]       
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_post_template_addition_adjustment(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    PU8 src_p = NULL, dest_p = NULL,prev_src_p = NULL, starting_p = NULL;
    UI_character_type ch, current_character1;
    EMSData *data_chk_type1 = b->data;
    EMSPosition p1 = b->data->CurrentPosition;
    EMSObject *o1;
    U8 object_type_check1 = 0;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p1=b->data->CurrentPosition;
    if (!TestLastPosition(b->data, &(b->data->CurrentPosition)))
    {
        object_type_check1 = gui_EMS_input_box_get_next_object(data_chk_type1, &p1, &current_character1, &o1);
    }        
    src_p = (b->data->textBuffer + b->data->CurrentPosition.OffsetToText);
    if(gui_show_EMS_input_box_find_segment_start(b->data,src_p) > (b->data->textBuffer + b->line_positions_text_offset[b->current_line]))
    {
        starting_p = gui_show_EMS_input_box_find_segment_start(b->data,src_p);
    }
    else
    {
        starting_p = (b->data->textBuffer + b->line_positions_text_offset[b->current_line]);
    }
    if (b->data->CurrentPosition.OffsetToText >= 4)
    {
        ch = (b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 2]) | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 1] << 8);
        if((object_type_check1==1) && ((IRE_IS_CHAR_TYPE_HALANT(ch)) || (ch == ZWJ)) && (starting_p != src_p))
        {
            prev_src_p = ire_get_prev_cluster_p(starting_p, src_p);
            dest_p = ire_get_next_cluster_p(prev_src_p, gui_show_EMS_input_box_find_segment_end(b->data,prev_src_p));
            b->data->CurrentPosition.OffsetToText += (dest_p - src_p);      
        }
    }
}
#endif /* __MMI_INDIC_ALG__ */ 



/*PMT IRE END*/
#endif /* (!UI_DISABLE_EMS_INPUT_BOX) */ 

/* msz00065_20051010 peng hua add for multitap thai begin */
#ifdef __MMI_MULTITAP_THAI__


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_check_input_test_overflow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]         
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_check_input_test_overflow(UI_EMS_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 remaining_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    if (b->UCS2_count > 0)
    {
        remaining_length = (EMS_get_remaining_length(b->data) >> 1);
    }
    else
    {
        remaining_length = EMS_get_remaining_length(b->data);

    }
    if (remaining_length <= 0)
    {
        return FALSE;
    }
    if (b->UCS2_count == 0)
    {
        if (gui_ems_test_UCS2_character(c))
        {
            if (gui_EMS_input_box_set_dcs(b, SMSAL_UCS2_DCS) != EMS_OK)
            {
                gui_EMS_input_box_set_dcs(b, SMSAL_DEFAULT_DCS);
                return FALSE;
            }
            else
            {
                if (EMS_get_remaining_length(b->data) < 2)
                {
                    gui_EMS_input_box_set_dcs(b, SMSAL_DEFAULT_DCS);
                    return FALSE;
                }
                else
                {
                    gui_EMS_input_box_set_dcs(b, SMSAL_DEFAULT_DCS);
                    return TRUE;
                }
            }
        }
        else if (gui_ems_test_extention_character(c))
        {
            if (EMS_get_remaining_length(b->data) < 1)  /* JP : 408 info bar issue */
            {
                return FALSE;
            }
        }
    }
    /* MTK end */

    /* If in Overwrite mode, delete the current character/object and insert the new one */
    if (b->flags & UI_EMS_INPUT_BOX_OVERWRITE_MODE)
    {
        return TRUE;
    }
    return TRUE;
}
#endif /* __MMI_MULTITAP_THAI__ */ 
/* msz00065_20051010 peng hua add for multitap thai end */

#ifdef __MMI_TOUCH_SCREEN__
static UI_EMS_input_box *gui_pen_scroll_EMS_input_box = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_scroll_by_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                       [?]         
 *  offset_y                [IN]        
 *  EMS_input_box_event     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_EMS_input_box_scroll_by_pen(
                UI_EMS_input_box *b,
                S32 offset_y,
                gui_EMS_input_box_pen_enum *EMS_input_box_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* int move_gap = b->display_y + offset_y; */
    S32 x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 

#if defined(__MMI_EDITOR_SSP_SUPPORT__) && defined(__MMI_MESSAGES_EMS__)
    in_scrolling_flag = 1;
#endif

    b->display_y = -offset_y;

    if (b->saved_cursor_ax == -1)
        b->saved_cursor_ax = b->cursor_ax;
    x = b->saved_cursor_ax;

    /* W06.06 Fix Cursor issue in EMS Input Box */
    if (!(b->flags & UI_EMS_INPUT_BOX_VIEW_MODE) && !(b->flags & UI_EMS_INPUT_BOX_DISABLE_CURSOR_DRAW))
    {
        if (b->cursor_ay < -(b->display_y))
        {
            gui_show_EMS_input_box_ext(b, x, b->y + b->height - b->cursor_line_height);
        }
        else if (b->cursor_ay + b->cursor_line_height > b->height - b->display_y)
        {
            gui_show_EMS_input_box_ext(b, x, b->y + b->cursor_line_height);
        }
        /*
        if (b->cursor_ay < -(b->display_y) || b->cursor_ay + b->cursor_line_height > b->height - b->display_y)
        {
            if (move_gap > 0)
            {
                gui_show_EMS_input_box_ext(b, x, UI_cursor_y1 + b->cursor_line_height);
            }
            else
            {
                if (0 == offset_y)
                {
                    gui_show_EMS_input_box_ext(b, x, b->y + b->cursor_line_height);
                }
                else
                {
                    gui_show_EMS_input_box_ext(b, x, UI_cursor_y1);
                }
            }
        }
        */
    }
    
    if (g_inputs_pen_scroll_cb != NULL)
    {
        g_inputs_pen_scroll_cb(b->display_y);
    }

    /* Reset saved_cursor_ax to x because it will be changed in gui_show_EMS_input_box_ext */
    b->saved_cursor_ax = x;
    b->display_y = -offset_y;
    /*if (!(b->flags & UI_EMS_INPUT_BOX_VIEW_MODE) && (0 != offset_y))
    {
        gui_EMS_input_box_locate_cursor(b);
    }*/
    gui_show_EMS_input_box(b);
#if defined(__MMI_EDITOR_SSP_SUPPORT__) && defined(__MMI_MESSAGES_EMS__)
    in_scrolling_flag = 0;
#endif
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width, b->y + b->height);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_scroll_timer_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_EMS_input_box_scroll_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_EMS_input_box *b = gui_pen_scroll_EMS_input_box;
    gui_EMS_input_box_pen_enum EMS_input_box_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_EMS_input_box = NULL;

    if (!b)
    {
        return;
    }

    gui_EMS_input_box_scroll_by_pen(b, b->pen_scroll_after_delay, &EMS_input_box_event);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_abort_scroll_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_EMS_input_box_abort_scroll_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_EMS_input_box = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_start_scroll_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [?]         
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_EMS_input_box_start_scroll_timer(UI_EMS_input_box *b, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* assert that no two input box at the same time */
    MMI_DBG_ASSERT(!gui_pen_scroll_EMS_input_box || gui_pen_scroll_EMS_input_box == b);

    b->pen_scroll_after_delay = value;
    gui_pen_scroll_EMS_input_box = b;

    gui_cancel_timer(gui_EMS_input_box_scroll_timer_hdlr);
    gui_start_timer(b->pen_scroll_delay_time, gui_EMS_input_box_scroll_timer_hdlr);

    gui_add_cleanup_hook(gui_EMS_input_box_abort_scroll_timer);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_set_pen_scroll_delay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  delay_time      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_set_pen_scroll_delay(UI_EMS_input_box *b, S32 delay_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(delay_time < (S32) 0x0000FFFF);
    b->pen_scroll_delay_time = (S16) delay_time;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                       [?]         
 *  pen_event               [IN]        
 *  x                       [IN]        
 *  y                       [IN]        
 *  EMS_input_box_event     [?]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_EMS_input_box_translate_pen_event(
        UI_EMS_input_box *b,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_EMS_input_box_pen_enum *EMS_input_box_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_TRUE;
    gui_EMS_input_box_pen_state_struct *pen_state;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
#ifdef __MMI_EDITOR_SSP_SUPPORT__
    mmi_pen_point_struct point;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EDITOR_SSP_SUPPORT__
    point.x = x;
    point.y = y;
#endif

    pen_state = &b->pen_state;
    ret = MMI_TRUE;

    if (pen_event != MMI_PEN_EVENT_DOWN && pen_state->pen_on_scroll_bar)
    {
        gui_vertical_scrollbar_translate_pen_event(&b->vbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            if (b->pen_scroll_delay_time > 0)   /* Delay time for scrollbar scrolling */
            {
                gui_EMS_input_box_start_scroll_timer(b, scrollbar_param._u.i);
            }
            else
            {
                gui_EMS_input_box_scroll_by_pen(b, scrollbar_param._u.i, EMS_input_box_event);
            }
        }
        *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_SCROLL_BAR;
    }
    else
    {
        switch (pen_event)
        {
            case MMI_PEN_EVENT_DOWN:
                if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
                {
                    pen_state->pen_on_scroll_bar = 0;
                    gui_vertical_scrollbar_set_minimum_pen_offset(&b->vbar, b->cursor_line_height);
                    if (!(b->flags & UI_EMS_INPUT_BOX_DISABLE_SCROLLBAR 
                          || (b->flags & UI_EMS_INPUT_BOX_AUTO_DISABLE_SCROLLBAR && (b->vbar.scale > b->vbar.range))) 
                        && gui_vertical_scrollbar_translate_pen_event(
                            &b->vbar,
                            MMI_PEN_EVENT_DOWN,
                            x,
                            y,
                            &scrollbar_event,
                            &scrollbar_param))
                    {
                        pen_state->pen_on_scroll_bar = 1;
                        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                        {
                            if (b->pen_scroll_delay_time > 0)   /* Delay time for scrollbar scrolling */
                            {
                                gui_EMS_input_box_start_scroll_timer(b, scrollbar_param._u.i);
                            }
                            else
                            {
                                gui_EMS_input_box_scroll_by_pen(b, scrollbar_param._u.i, EMS_input_box_event);
                            }
                        }
                        *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_SCROLL_BAR;
                    }
                    else
                    {
                        if (b->pen_control_area_callback != NULL)
                        {
                            if (b->header_height > 0 && b->y + b->display_y + b->header_height >= y)
                            {
                                *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_CONTROL_AREA;
                                ret = b->pen_control_area_callback(GUI_INPUT_BOX_AREA_HEADER, MMI_PEN_EVENT_DOWN, x, y - (b->y + b->display_y));
                            }
                            else
                            {
                                /* Only play feedback when in editor mode or view mode with scroll bar */
                                if (!(b->flags & UI_EMS_INPUT_BOX_VIEW_MODE) || (b->vbar.scale < b->vbar.range))
                                {
                                    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                                }
                                *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_TEXT_DOWN;
                                ret = b->pen_control_area_callback(GUI_INPUT_BOX_AREA_TEXT, MMI_PEN_EVENT_DOWN, x, y - (b->y + b->display_y));
                    }
                }
                else
                {
                            *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_TEXT_DOWN;
                        }
                    }
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;
            case MMI_PEN_EVENT_UP:
                if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
                {
                    if (!(b->flags & UI_EMS_INPUT_BOX_DISABLE_SCROLLBAR) &&
                        PEN_CHECK_BOUND(x, y, b->vbar.x, b->vbar.y, b->vbar.width, b->vbar.height))
                    {
                        *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_SCROLL_BAR;
                    }
                    else
                    {
                        if (b->pen_control_area_callback != NULL)
                        {
                            if (b->header_height > 0 && b->y + b->display_y + b->header_height >= y)
                            {
                                *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_CONTROL_AREA;
                                ret = b->pen_control_area_callback(GUI_INPUT_BOX_AREA_HEADER, MMI_PEN_EVENT_UP, x, y - (b->y + b->display_y));
                            }
                            else
                            {
                        *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_TEXT_UP;
                                ret = b->pen_control_area_callback(GUI_INPUT_BOX_AREA_TEXT, MMI_PEN_EVENT_UP, x, y - (b->y + b->display_y));
                    }
                }
                else
                {
                            *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_TEXT_UP;
                        }
                    }
                }
                else
                {
                    if (b->pen_control_area_callback)
                    {
                        b->pen_control_area_callback(GUI_INPUT_BOX_AREA_END, MMI_PEN_EVENT_UP, 0, 0);
                    }
                    ret = MMI_FALSE;
                }
                break;
            case MMI_PEN_EVENT_MOVE:
            case MMI_PEN_EVENT_LONG_TAP:
            case MMI_PEN_EVENT_REPEAT:
            case MMI_PEN_EVENT_ABORT:
                if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
                {
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;
        }
    }

#ifdef __MMI_EDITOR_SSP_SUPPORT__
    if (b->state == GUI_INPUT_BOX_STATE_SELECTING_TEXT)
    {
        gui_input_box_ssp_pen_translate(point, MMI_PEN_EVENT_ABORT);
        *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_NONE;
    }
    else
    {
        if (pen_event == MMI_PEN_EVENT_DOWN 
            && !PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
            return ret;

        if (gui_input_box_ssp_get_userdata() != (void*)b)
        {
            gui_input_box_ssp_set_client_callback(
                gui_ems_ssp_update_client, 
                gui_ems_ssp_get_client_info, 
                b);
        }

        if (gui_input_box_ssp_pen_translate(point, pen_event))
        {
            *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_NONE;
        }
    }
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */

    return ret;
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_ems_input_box_start_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_ems_input_box_start_input(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags |= UI_EMS_INPUT_BOX_INPUT_METHOD_MODE;
    
    b->input_mode_position = b->data->CurrentPosition;
    /* Stores the input start position so that we can handle the multitap mode easily */
    b->input_start_position = b->data->CurrentPosition;
#ifdef __MMI_INDIC_ALG__
    saved_last_skip_pos = 0;
#endif /* __MMI_INDIC_ALG__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_ems_input_box_stop_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_ems_input_box_stop_input(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags &= ~UI_EMS_INPUT_BOX_INPUT_METHOD_MODE;
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

	to_decide_to_reshuffle = 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_ems_test_extention_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static __inline MMI_BOOL gui_ems_test_extention_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (MMI_BOOL)((!mmi_7bit_check_gsm(c)) && (mmi_7bit_check_gsm_ext_character(c)));
}


#ifdef __SMS_R8_NATION_LANGUAGE__

/*****************************************************************************
 * FUNCTION
 *  gui_ems_auto_detection_insert_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b      [IN]
 *  c       [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 gui_ems_auto_detection_insert_character(UI_EMS_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSNationalLanguage old_l, new_l;
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    EMSPosition pos;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_7bit_get_national_lang_table(&old_l);

    /* attemp to add c */
    mmi_7bit_update_character_type(&b->ems_auto_dection, c, MMI_TRUE);
    mmi_7bit_choose_national_table(&b->ems_auto_dection, &new_l);
    mmi_7bit_update_character_type(&b->ems_auto_dection, c, MMI_FALSE);

    if (b->UCS2_count > 0 
        || (new_l.locking_shift == old_l.locking_shift
            && new_l.single_shift == old_l.single_shift))
    {
        /* the table needn't to be changed */
        return gui_EMS_input_box_insert_character_no_draw(b, c);
    }

    /* table need to be changed. Test it */
    gui_EMS_input_box_remove_extension_character(b, b->data);
    mmi_7bit_set_national_lang_table(&new_l);
    
    if (EMSSetNationalLanguage(b->data, &new_l) != EMS_OK)
    {
        /* table can't be changed, retore the old table */
        gui_EMS_input_box_remove_extension_character(b, b->data);
        mmi_7bit_set_national_lang_table(&old_l);
        gui_EMS_input_box_insert_extension_character(b, b->data);
        UI_editor_play_tone_cannot_insert();
        return EMS_NO_SPACE;
    }

    if (gui_EMS_input_box_insert_extension_character(b, b->data) != EMS_OK)
    {
        /* table can't be changed, retore the old table */
        gui_EMS_input_box_remove_extension_character(b, b->data);
        mmi_7bit_set_national_lang_table(&old_l);
        gui_EMS_input_box_insert_extension_character(b, b->data);
        EMSSetNationalLanguage(b->data, &old_l);
        UI_editor_play_tone_cannot_insert();
        return EMS_NO_SPACE;
    }
    else
    {
        if (gui_EMS_input_box_insert_character_no_draw(b, c) != EMS_OK)
        {
            /* table can't be changed, retore the old table */
            gui_EMS_input_box_remove_extension_character(b, b->data);
            mmi_7bit_set_national_lang_table(&old_l);
            gui_EMS_input_box_insert_extension_character(b, b->data);
            EMSSetNationalLanguage(b->data, &old_l);
            UI_editor_play_tone_cannot_insert();
            return EMS_NO_SPACE;
        }
        else
        {
            if (b->flags & UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)   
                b->input_mode_position = b->data->CurrentPosition;
        }
    }

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    pos.OffsetToText = 0;
    pos.Object = NULL;
    gui_emsc_change_request(pos);
#endif

    return EMS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  gui_ems_auto_detection_insert_multitap_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b      [IN]
 *  c       [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 gui_ems_auto_detection_insert_multitap_character(UI_EMS_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSNationalLanguage old_l, new_l;
    UI_character_type pre_char;
    EMSPosition mapped_cursor_position;
    EMSObject *current_object;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    EMSPosition pos;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_7bit_get_national_lang_table(&old_l);

    if (b->flags & UI_EMS_INPUT_BOX_STATE_MULTITAP)
    {
        mapped_cursor_position = b->data->CurrentPosition;
        gui_EMS_input_box_get_previous_object(b->data, &mapped_cursor_position, &pre_char, &current_object);
        
        /* remove the previous one */
        mmi_7bit_update_character_type(&b->ems_auto_dection, pre_char, MMI_FALSE);
        /* add the new one*/
        mmi_7bit_update_character_type(&b->ems_auto_dection, c, MMI_TRUE);
        mmi_7bit_choose_national_table(&b->ems_auto_dection, &new_l);
        mmi_7bit_update_character_type(&b->ems_auto_dection, pre_char, MMI_TRUE);
        mmi_7bit_update_character_type(&b->ems_auto_dection, c, MMI_FALSE);
    }
    else
    {
        /* attemp to add c */
        mmi_7bit_update_character_type(&b->ems_auto_dection, c, MMI_TRUE);
        mmi_7bit_choose_national_table(&b->ems_auto_dection, &new_l);
        mmi_7bit_update_character_type(&b->ems_auto_dection, c, MMI_FALSE);
    }

    if (b->UCS2_count > 0 
        || (new_l.locking_shift == old_l.locking_shift
            && new_l.single_shift == old_l.single_shift))
    {
        /* the table needn't to be changed */
        return gui_EMS_input_box_insert_multitap_character_no_draw(b, c);
    }
    
    /* table need to be changed. Test it */
    gui_EMS_input_box_remove_extension_character(b, b->data);
    mmi_7bit_set_national_lang_table(&new_l);
    
    if (EMSSetNationalLanguage(b->data, &new_l) != EMS_OK)
    {
        /* table can't be changed, retore the old table */
        gui_EMS_input_box_remove_extension_character(b, b->data);
        mmi_7bit_set_national_lang_table(&old_l);
        gui_EMS_input_box_insert_extension_character(b, b->data);
        UI_editor_play_tone_cannot_insert();
        return EMS_NO_SPACE;
    }
    
    if (gui_EMS_input_box_insert_extension_character(b, b->data) != EMS_OK)
    {
        /* table can't be changed, retore the old table */
        gui_EMS_input_box_remove_extension_character(b, b->data);
        mmi_7bit_set_national_lang_table(&old_l);
        gui_EMS_input_box_insert_extension_character(b, b->data);
        EMSSetNationalLanguage(b->data, &old_l);
        UI_editor_play_tone_cannot_insert();
        return EMS_NO_SPACE;
    }
    else
    {
        if (gui_EMS_input_box_insert_multitap_character_no_draw(b, c) != EMS_OK)
        {
            /* table can't be changed, retore the old table */
            gui_EMS_input_box_remove_extension_character(b, b->data);
            mmi_7bit_set_national_lang_table(&old_l);
            gui_EMS_input_box_insert_extension_character(b, b->data);
            EMSSetNationalLanguage(b->data, &old_l);
            UI_editor_play_tone_cannot_insert();
            return EMS_NO_SPACE;
        }
        else
        {
            if (b->flags & UI_EMS_INPUT_BOX_INPUT_METHOD_MODE)   
                b->input_mode_position = b->data->CurrentPosition;
        }
    }

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    pos.OffsetToText = 0;
    pos.Object = NULL;
    gui_emsc_change_request(pos);
#endif
    
    return EMS_OK;
}

#endif

#ifdef __EMS_NON_STD_7BIT_CHAR__
U8 convert_non_standard_gsm(U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type gsm;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_no_standard_character(c))
    {
        gsm = srv_sms_encode_no_sandard_char(0, (U8)c);
    }
    else
        gsm = 0x20;
    
    return (U8)gsm;
}
#endif


#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
/*****************************************************************************
* FUNCTION
*  gui_get_ems_visible_area
* DESCRIPTION
*  
* PARAMETERS
*  b       [?]     
*  y1      [?] 
*  y2      [?]   
* RETURNS
*  void
*****************************************************************************/
void gui_get_ems_visible_area(UI_EMS_input_box *b, S32 *y1, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 header_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_EMS_INPUT_BOX_DISPLAY_HEADER)
        header_height = b->measure_header();

    *y1 = -(b->display_y) - (header_height + 1);
    *y2 = *y1 + b->height;

    if(*y1 < 0)
        *y1 = 0;

    if(*y2 < 0)
        *y2 = 0;
    
    if (*y2 - *y1 > UI_DEVICE_HEIGHT)
        *y2 = *y1 + UI_DEVICE_HEIGHT;
}
#endif

/*****************************************************************************
* FUNCTION
*  gui_EMS_input_box_disalbe_show
* DESCRIPTION
*  Disable show or not
* PARAMETERS
*  b_disable       [IN]        disable or not
* RETURNS
*  void
*****************************************************************************/
void gui_EMS_input_box_disalbe_show(MMI_BOOL b_disable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ems_is_disable_show = b_disable;
}

/*****************************************************************************
* FUNCTION
*  gui_EMS_input_box_disable_sound
* DESCRIPTION
*  Disable sound or not
* PARAMETERS
*  b_disable       [IN]        disable or not
* RETURNS
*  void
*****************************************************************************/
void gui_EMS_input_box_disable_sound(MMI_BOOL b_disable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ems_is_disable_sound = b_disable;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_scroll_down
 * DESCRIPTION
 *  Move to next line/page (Scroll down)
 * PARAMETERS
 *  b       [IN]        EMS object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_scroll_down(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if UI_EMS_VIEW_PAGE
    b->display_y -= (b->height - b->line_after_visible_start_height);
#else
    b->display_y -= b->line_after_visible_start_height;
#endif /* UI_EMS_VIEW_PAGE */

    if ((b->display_y + b->display_height) < b->height)
    {
        b->display_y = b->height - b->display_height - GUI_EMS_INPUTBOX_HEIGHT_EXTRA_GAP;
    }
    if (b->display_y > 0)
    {
        b->display_y = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_scroll_up
 * DESCRIPTION
 *  Move to preivous line/page (Scroll up)
 * PARAMETERS
 *  b       [IN]        EMS object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_scroll_up(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if UI_EMS_VIEW_PAGE
    b->display_y += (b->height - b->line_before_visible_start_height);
#else
    b->display_y += b->line_before_visible_start_height;
#endif /* UI_EMS_VIEW_PAGE */

    if ((b->display_y + b->display_height) < b->height)
    {
        b->display_y = b->height - b->display_height - GUI_EMS_INPUTBOX_HEIGHT_EXTRA_GAP;
    }
    if (b->display_y > 0)
    {
        b->display_y = 0;
    }
}


#ifdef __UI_EMS_HIGHLIGHT_LIST_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_is_pos_inside_hilite_ext
 * DESCRIPTION
 *  Check if the position inside hilite list range
 * PARAMETERS
 *  b               [IN]        EMS object
 *  current_pos     [IN]        position    
 *  hilite_idx      [OUT]       hilite idx if the position inside hilite
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_EMS_input_box_is_pos_inside_hilite_ext(
            UI_EMS_input_box *b,
            UI_buffer_type current_pos,
            U16 *hilite_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hilite_no = b->hilite_str_number;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i < (hilite_no + 1); i++)
    {
        if ((current_pos >= (b->data->textBuffer + b->hilite_list[i].offset_to_text)) &&
            (current_pos < (b->data->textBuffer + b->hilite_list[i].offset_to_text + b->hilite_list[i].hilite_length)))
        {
            *hilite_idx = i;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_get_text_hilite_object
 * DESCRIPTION
 *  Get text hilite object, 
 * PARAMETERS
 *  b                [IN]        EMS object
 *  obj        	     [IN]        hilite object   
 * RETURNS
 *  EMSObject
 *****************************************************************************/
EMSObject* gui_EMS_input_box_get_text_hilite_object(UI_EMS_input_box *b, U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *temp_obj, *obj = b->hilite_list[idx].object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (obj == NULL)
    {
        temp_obj = b->data->listHead;
    }
    else
    {
        temp_obj = obj->next;
    }
    
    while (temp_obj)
    {
        if (temp_obj->Type == EMS_TYPE_TEXT_FORMAT)
        {
            if ((temp_obj->OffsetToText < b->hilite_list[idx].offset_to_text) && 
                ((temp_obj->OffsetToText + temp_obj->data->text_format.textLength) > b->hilite_list[idx].offset_to_text))
            {
                return temp_obj;
            }
            else if (temp_obj->OffsetToText >= b->hilite_list[idx].offset_to_text)
            {
                return temp_obj->prev;
            }
        }
        else
        {
            return obj;
        }

        if (temp_obj->next == NULL)
        {
            return temp_obj;
        }
        temp_obj = temp_obj->next;
    }

    return obj;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_go_to_hilite
 * DESCRIPTION
 *  Go to specific hilite index
 * PARAMETERS
 *  b                [IN]        EMS object
 *  idx        	     [IN]        hilite index   
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_go_to_hilite(UI_EMS_input_box *b, U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition cursor_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Cancel highlight */
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus(); 
#endif
	b->highlight_start_position.OffsetToText = 0;
    b->highlight_start_position.Object = NULL;
    b->highlight_end_position.OffsetToText = 0;
    b->highlight_end_position.Object = NULL;

    if ((idx <= b->hilite_str_number) && (idx > 0))
    {
        if (b->hilite_list[idx].hilite_type == EMS_HILITE_OBJECT)
        {
            cursor_pos.OffsetToText = b->hilite_list[idx].offset_to_text;
            MMI_ASSERT(b->hilite_list[idx].object != NULL);
            cursor_pos.Object = b->hilite_list[idx].object->prev;
            gui_EMS_input_box_set_cursor_position(b, &cursor_pos);
        }
        else
        {
            cursor_pos.OffsetToText = b->hilite_list[idx].offset_to_text;// + (ENCODING_LENGTH * b->hilite_list[hilite_idx].hilite_length);
            cursor_pos.Object = gui_EMS_input_box_get_text_hilite_object(b, idx);
            gui_EMS_input_box_set_cursor_position(b, &cursor_pos);

            b->highlight_start_position.OffsetToText = b->hilite_list[idx].offset_to_text;
            b->highlight_start_position.Object = b->hilite_list[idx].object;
            b->highlight_end_position.OffsetToText = b->hilite_list[idx].offset_to_text + b->hilite_list[idx].hilite_length;
            b->highlight_end_position.Object = b->hilite_list[idx].object;
            b->flags |= UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
        }
    }

    b->current_hilite_idx = idx;
    b->hilite_cb(idx);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_is_hilite_in_visible_range
 * DESCRIPTION
 *  Check if specific hilite index in the visible range
 * PARAMETERS
 *  b                [IN]        EMS object
 *  hilite_idx       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_EMS_input_box_is_hilite_in_visible_range(UI_EMS_input_box *b, U16 hilite_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition hilite_start_pos, hilite_end_pos, visible_start, visible_end;
    S32 ret_s_start, ret_s_end, ret_e_start, ret_e_end;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((hilite_idx < 0) || (hilite_idx > b->hilite_str_number + 1))
    {
        return MMI_FALSE;
    }

    if (b->first_displayed_line == 0)
    {
        visible_start.OffsetToText = b->line_positions_text_offset[b->first_displayed_line];
        #ifdef __MMI_MESSAGES_EMS__
        visible_start.Object = gui_ems_get_object_by_index(b, b->line_positions_object_index[b->first_displayed_line]);
        #else
        visible_start.Object = NULL;
        #endif
    }
    else
    {
        visible_start.OffsetToText = b->line_positions_text_offset[b->first_displayed_line + 1];
        #ifdef __MMI_MESSAGES_EMS__
        visible_start.Object = gui_ems_get_object_by_index(b, b->line_positions_object_index[b->first_displayed_line + 1]);
        #else
        visible_start.Object = NULL;
        #endif
    }

    if (b->last_displayed_line < (b->n_lines - 1))
    {
        visible_end.OffsetToText = b->line_positions_text_offset[b->last_displayed_line + 1];
        #ifdef __MMI_MESSAGES_EMS__
        visible_end.Object = gui_ems_get_object_by_index(b, b->line_positions_object_index[b->last_displayed_line + 1]);
        #else
        visible_end.Object = NULL;
        #endif
    }
    else
    {
        visible_end.OffsetToText = b->line_positions_text_offset[b->last_displayed_line];
        #ifdef __MMI_MESSAGES_EMS__
        visible_end.Object = gui_ems_get_object_by_index(b, b->line_positions_object_index[b->last_displayed_line]);
        #else
        visible_end.Object = NULL;
        #endif
    }

    hilite_start_pos.OffsetToText = b->hilite_list[hilite_idx].offset_to_text;
    hilite_start_pos.Object = b->hilite_list[hilite_idx].object;
    hilite_end_pos.OffsetToText = b->hilite_list[hilite_idx].offset_to_text + b->hilite_list[hilite_idx].hilite_length;
    hilite_end_pos.Object = b->hilite_list[hilite_idx].object;
    
    ret_e_start = gui_set_EMS_input_box_compare_position(b, &hilite_end_pos, &visible_start);
    ret_e_end = gui_set_EMS_input_box_compare_position(b, &hilite_end_pos, &visible_end);
    ret_s_start = gui_set_EMS_input_box_compare_position(b, &hilite_start_pos, &visible_start);
    ret_s_end = gui_set_EMS_input_box_compare_position(b, &hilite_start_pos, &visible_end);

    /* hilite rule:
          1. if hilite start position is in visible area, we should hilite it
          2. if hilite end position is in visible area, we should hilite it */
    if (((ret_s_start >= 0) && (ret_s_end < 0)) || ((ret_e_start >= 0) && (ret_e_end < 0 || (b->last_displayed_line == (b->n_lines - 1)))))
    {
        ret = MMI_TRUE;
    }
    else
    {
        ret = MMI_FALSE;
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_find_first_hilite_in_visible_range
 * DESCRIPTION
 *  Find the first hilite in visible range
 * PARAMETERS
 *  b       [IN]        EMS object
 * RETURNS
 *  S32: the index of first hilite in visible range, if not exist, return -1 
 *****************************************************************************/
S32 gui_EMS_input_box_find_first_hilite_in_visible_range(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i <= b->hilite_str_number; i++)
    {
        if (gui_EMS_input_box_is_hilite_in_visible_range(b, i))
        {
            return i;
        }        
    }

    return -1;
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_find_last_hilite_in_visible_range
 * DESCRIPTION
 *  Find the last hilite in visible range
 * PARAMETERS
 *  b       [IN]        EMS object
 * RETURNS
 *  S32: the index of last hilite in visible range, if not exist, return -1 
 *****************************************************************************/
S32 gui_EMS_input_box_find_last_hilite_in_visible_range(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = b->hilite_str_number; i > 0; i--)
    {
        if (gui_EMS_input_box_is_hilite_in_visible_range(b, i))
        {
            return i;
        }        
    }

    return -1;
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_next_line_with_hilite_list
 * DESCRIPTION
 *  Go to next line with hilite list. If next hilite is in visible area,
 *  Go to next hilite, else move to next line as normal
 * PARAMETERS
 *  b       [IN]        EMS object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_next_line_with_hilite_list(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 next_index = b->current_hilite_idx + 1; /* Next hilite index */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_EMS_input_box_is_hilite_in_visible_range(b, b->current_hilite_idx))
    {  
        /* if current hilite is in visible area */
        if (b->current_hilite_idx == b->hilite_str_number)
        {
            /* if reach last hilite */
            if (b->last_displayed_line == (b->n_lines - 1) && b->display_y + b->display_height <= b->height)
            {
                /* if reach the last line , cancel hilite */
                gui_EMS_input_box_go_to_hilite(b, b->hilite_str_number + 1);
            }
            else
            {
                /* if not reach the last line, scroll down */
                gui_EMS_input_box_scroll_down(b);
            }
        }
        else if (gui_EMS_input_box_is_hilite_in_visible_range(b, next_index))
        {
            /* if the next hilite is in visible area, go to that hilite */
            gui_EMS_input_box_go_to_hilite(b, next_index);
        }
        else
        {
            /* if the next hilite is not in visible area, scroll down text */
            gui_EMS_input_box_scroll_down(b);
        }
    }
    else
    {
        /* if current hilite is not in visible area, find the first hilite in visible area */        
        next_index = gui_EMS_input_box_find_first_hilite_in_visible_range(b);
        if (next_index != -1)
        {
            /* if exist, go to that hilite */
            gui_EMS_input_box_go_to_hilite(b, next_index);
        }
        else if (b->current_hilite_idx == b->hilite_str_number)
        {
            /* if not exist, and we reach last hilite */
            if (b->last_displayed_line == (b->n_lines - 1))
            {
                /* if reach the last line , cancel hilite */
                gui_EMS_input_box_go_to_hilite(b, b->hilite_str_number + 1);
            }
            else
            {
                /* if not reach the last line, scroll down */
                gui_EMS_input_box_scroll_down(b);
            }
        }
        else
        {
            /* if there is no next hilite in visible area and we do not reach last hilite, scroll down text */
            gui_EMS_input_box_scroll_down(b);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_previous_line_with_hilite_list
 * DESCRIPTION
 *  Go to previous line with hilite list. If previous hilite is in visible area,
 *  Go to previous hilite, else move to previous line as normal
 * PARAMETERS
 *  b       [IN]        EMS object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_previous_line_with_hilite_list(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pre_index = b->current_hilite_idx - 1; /* Previous hilite index */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_EMS_input_box_is_hilite_in_visible_range(b, b->current_hilite_idx))
    {
        /* if current hilite is in visible area */
        if (b->current_hilite_idx == 1)
        {
            /* if we reach first hilite */
            if (b->first_displayed_line == 0)
            {
                /* if reach the first line, cancel hilite */
                gui_EMS_input_box_go_to_hilite(b, 0);
            }
            else
            {
                /* if not reach the first line, scroll up */
                gui_EMS_input_box_scroll_up(b);
            }
        }
        else if (gui_EMS_input_box_is_hilite_in_visible_range(b, pre_index))
        {
            /* if the previous hilite is in visible area, go to that hilite */
            gui_EMS_input_box_go_to_hilite(b, pre_index);
        }
        else
        {
            /* if the previous hilite is not in visible area, scroll up text */
            gui_EMS_input_box_scroll_up(b);
        }
    }
    else
    {
        /* if current hilite is not in visible area, find the last hilite in visible area */        
        pre_index = gui_EMS_input_box_find_last_hilite_in_visible_range(b);
        if (pre_index != -1)
        {
            /* if exist, go to that hilite */
            gui_EMS_input_box_go_to_hilite(b, pre_index);
        }
        else if (b->current_hilite_idx == 1)
        {
            /* if not exist, and we reach first hilite */
            if (b->first_displayed_line == 0)
            {
                /* if reach the first line , cancel hilite */
                gui_EMS_input_box_go_to_hilite(b, 0);
            }
            else
            {
                /* if not reach the first line, scroll up */
                gui_EMS_input_box_scroll_up(b);
            }
        }
        else
        {
            /* if there is no previous hilite in visible area and we do not reach first hilite, scroll up text */
            gui_EMS_input_box_scroll_up(b);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_is_pen_down_in_hilite
 * DESCRIPTION
 *  Check if pen down on hilite. Pen down on hilite condition 
 *    1). Pen down on highlight text 
 *    2). Pen donw on object
 * PARAMETERS
 *  b       [IN]        EMS object
 * RETURNS
 *  MMI_BOOL
 *      MMI_TRUE:  pen down on hilite
 *      MMI_FALSE: pen down on non hilite area
 *****************************************************************************/
MMI_BOOL gui_EMS_input_box_is_pen_down_in_hilite(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition current_pos = b->data->CurrentPosition;
    U16 hilite_no = b->hilite_str_number;
    U16 i = 0;
    U16 hilite_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i <= hilite_no; i++)
    {
        hilite_length = b->hilite_list[i].hilite_length;
    
        /* Pen down on hilite condition 1). Pen down on highlight text 2). Pen donw on object*/
        if (b->hilite_list[i].hilite_type == EMS_HILITE_OBJECT)
        {
            MMI_ASSERT(b->hilite_list[i].object != NULL);
            if ((current_pos.OffsetToText == b->hilite_list[i].offset_to_text) &&
                (current_pos.Object == b->hilite_list[i].object->prev))
            {
                b->current_hilite_idx = i;;
                return MMI_TRUE;
            }
        }
        else
        {
            if ((current_pos.OffsetToText >= b->hilite_list[i].offset_to_text) &&
                (current_pos.OffsetToText < b->hilite_list[i].offset_to_text + hilite_length))
            {
                b->current_hilite_idx = i;;
                return MMI_TRUE;
            }
        }    

    }

    return MMI_FALSE;
}
#endif /* __UI_EMS_HIGHLIGHT_LIST_SUPPORT__ */


/*****************************************************************************
* FUNCTION
*  gui_EMS_input_box_set_dcs
* DESCRIPTION
*  Wrapper for set dcs of emslib
* PARAMETERS
*  
* RETURNS
*  EMSTATUS
*****************************************************************************/
EMSTATUS gui_EMS_input_box_set_dcs(UI_EMS_input_box *b, kal_uint8 dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __SMS_R8_NATION_LANGUAGE__
    return EMSSetDCS(b->data, dcs);
#else
    if (dcs == SMSAL_UCS2_DCS)
    {
        EMSNationalLanguage l1;
        
        l1.locking_shift = EMS_NL_DEFAULT;
        l1.single_shift = EMS_NL_DEFAULT;
        EMSSetNationalLanguage(b->data, &l1);

        return EMSSetDCS(b->data, dcs);
    }
    else
    {
        EMSNationalLanguage l1;
        EMSTATUS ret;

        gui_ems_table_mechanism_enum cur_m = mmi_7bit_get_table_mechanism();

        ret = EMSSetDCS(b->data, dcs);
        
        if (cur_m != EMS_AUTO_DETECTION)
        {
            mmi_7bit_get_national_lang_table(&l1);
            EMSSetNationalLanguage(b->data, &l1);
        }

        return ret;
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  gui_EMS_input_box_get_object_count
* DESCRIPTION
*  Get unit(character and object) count of a text
* PARAMETERS
*  b                [IN]             object
*  start            [IN]             start position
*  end              [IN]             end position
* RETURNS
*  S32
*****************************************************************************/
S32 gui_EMS_input_box_get_unit_count(UI_EMS_input_box *b, EMSPosition start, EMSPosition end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;
    EMSObject *pObj = b->data->listHead;
    EMSPosition obj_position;
    S32 start_cmp, end_cmp;
    U16 c;
    U8 *textBuffer = b->data->textBuffer;
    U16 OffsetToText = start.OffsetToText;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = (end.OffsetToText - start.OffsetToText) / ENCODING_LENGTH;

    /* Don't count 0x1b character in the count */
    while (OffsetToText < end.OffsetToText)
    {
    #if(EMS_BYTE_ORDER_BIG_ENDIAN)
        c = (U16) (textBuffer[OffsetToText + 1] | (textBuffer[OffsetToText] << 8));
    #else 
        c = (U16) (textBuffer[OffsetToText] | (textBuffer[OffsetToText + 1] << 8));
    #endif 
        if (c == EMS_ESCAPE_CHARACTER)
        {
            count--;
        }
        OffsetToText += ENCODING_LENGTH;
    }

    if (pObj == NULL)
    {
        return count;
    }
    else
    {
        while (pObj)
        {
            if (pObj->Type == EMS_TYPE_TEXT_FORMAT)
            {
                pObj = pObj->next;
                continue;
            }
    
            obj_position.OffsetToText = pObj->OffsetToText;
            obj_position.Object = pObj;
            
            start_cmp = gui_set_EMS_input_box_compare_position(b, &obj_position, &start);
            end_cmp = gui_set_EMS_input_box_compare_position(b, &obj_position, &end);

            if ((start_cmp > 0) && (end_cmp <= 0))
            {
                count++;
                pObj = pObj->next;
            }
            else if (start_cmp <= 0)
            {
                pObj = pObj->next;
            }
            else
            {
                break;
            }
        }
    }

    return count;
}


#ifdef __MMI_EDITOR_SSP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  gui_multiline_ssp_update_client
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset              [IN]    the new offset position
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
static void gui_ems_ssp_update_client(void *user_data, S32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_EMS_input_box *b = (UI_EMS_input_box *)user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->display_y == -offset)
        return;
    
    b->display_y = -offset;

#if defined(__MMI_EDITOR_SSP_SUPPORT__) && defined(__MMI_MESSAGES_EMS__)
    in_scrolling_flag = 1;
#endif
    
#ifdef __MMI_VUI_ENGINE__
        //if (vadp_p2v_uc_is_in_venus())
        //{
        //    vadp_p2v_update_view_for_SSP(b->venus_text_view);
        //    return;
        //}
#endif

    gui_show_EMS_input_box(b);

#if defined(__MMI_EDITOR_SSP_SUPPORT__) && defined(__MMI_MESSAGES_EMS__)
    in_scrolling_flag = 0;
#endif

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        b->x,
        b->y,
        b->x + b->width,
        b->y + b->height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_multiline_ssp_get_client_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset              [IN]    the new offset position
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
static void gui_ems_ssp_get_client_info(void *user_data, S32 *total_offset, S32 *cur_offset, S32 *move_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_EMS_input_box *b = (UI_EMS_input_box *)user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (total_offset)
    {
        *total_offset = b->display_height + b->header_height - (b->height - 5);
        if (*total_offset < 0)
            *total_offset = 0;
    }

    if (cur_offset)
    {
        *cur_offset = -b->display_y;
    }

    if (move_type)
    {
        *move_type = GUI_INPUT_BOX_SSP_BY_Y;
    }
}
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  gui_ems_show_special_remaining_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b            [IN]             ems object
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
void gui_ems_show_special_remaining_counter(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef GUI_INPUT_BOX_FLOATING_COUNTER
    S32 x1, y1, x2, y2;
    S32 max_n, n, w, h;
    UI_character_type str[32];
    gdi_handle act_layer;
    stFontAttribute    small_font = {0, 0, 0, SMALL_FONT, 0, 1};
    color c = *current_MMI_theme->remaining_length_text_color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_inputbox_register_floating_counter_position(0, 0, 0, 0);

    if (b->flags & UI_EMS_INPUT_BOX_DISABLE_DRAW
        || b->flags & UI_EMS_INPUT_BOX_VIEW_MODE
        || !(mmi_imc_is_connected()))
        return;

#ifdef __MMI_CLIPBOARD__
    if (mmi_imc_is_connected() &&
        (g_mmi_editor_hanler.input_box_type == MMI_EDITOR_EMS_INPUT_BOX) &&
        mmi_imc_clipboard_is_editor_read_only())
    {
        return;
    }
#endif

#ifdef __MMI_MESSAGES_EMS_REMAINING_COUNTER__
    n = EMS_get_last_segment_remaining_char(b);
    max_n = EMS_get_required_segment(b);
   
    if (b->flags & UI_EMS_INPUT_BOX_AUTO_DISPLAY_REMAINING_COUNTER)
    {
        if (!(max_n > 1 || n <= GUI_INPUT_BOX_FLOATING_COUNTER_DISPLAY_THRESHOLD))
            return;
    }
    
#else /*__MMI_MESSAGES_EMS_REMAINING_COUNTER__*/
    n = b->available_length - EMS_get_remaining_length(b->data);
    if (b->UCS2_count > 0)
    {
        n = b->available_length - (EMS_get_remaining_length(b->data) >> 1);
    }
    else if (b->GSM_ext_count > 0)
    {
        n = b->available_length - EMS_get_remaining_length(b->data);
    }
    max_n = b->available_length;

    if (b->flags & UI_EMS_INPUT_BOX_AUTO_DISPLAY_REMAINING_COUNTER)
    {
        if (n < max_n - GUI_INPUT_BOX_FLOATING_COUNTER_DISPLAY_THRESHOLD)
            return;
    }
#endif /*__MMI_MESSAGES_EMS_REMAINING_COUNTER__*/
    
    /* Compute the position */
    gui_sprintf(str, "%d/%d", n, max_n);
    gui_set_font(&small_font);
    gui_measure_string(str, &w, &h);
    
    if (!r2lMMIFlag)
    {
        x2 = b->x + b->width - 1 - GUI_INPUT_BOX_FLOATING_COUNTER_GAP_X;
        x1 = x2 - w - 1;
    }
    else
    {
        x1 = b->x + GUI_INPUT_BOX_FLOATING_COUNTER_GAP_X;
        x2 = x1 + w + 1;
    }

    if (b->header_height + b->display_y < 0)
    {
        y1 = b->y + GUI_INPUT_BOX_FLOATING_COUNTER_GAP_Y;
    }
    else
    {
        y1 = b->y + b->header_height + b->display_y + GUI_INPUT_BOX_FLOATING_COUNTER_GAP_Y;
    }
    y2 = y1 + h + 1;
    
    gui_push_clip();
   // gui_reset_clip();
    gui_set_clip(b->x, b->y, b->x + b->width - 1, b->y + b->height - 1);
    
    gdi_layer_get_active(&act_layer);
    gdi_push_and_set_alpha_blending_source_layer(act_layer);
    gdi_image_draw_resized(x1 - GUI_INPUT_BOX_FLOATING_COUNTER_INDENT, 
        y1 - 1, 
        x2 - (x1 - GUI_INPUT_BOX_FLOATING_COUNTER_INDENT) + GUI_INPUT_BOX_FLOATING_COUNTER_INDENT,
        y2 - (y1 - 1) + 1, 
        current_MMI_theme->inputbox_remaining_counter_bg);
    gdi_pop_and_restore_alpha_blending_source_layer();
    
    UI_inputbox_register_floating_counter_position(x1 - GUI_INPUT_BOX_FLOATING_COUNTER_INDENT,
        y1 - 1,
        x2 + GUI_INPUT_BOX_FLOATING_COUNTER_INDENT,
        y2 + 1);

    UI_inputbox_stop_cursor_ext(x1 - GUI_INPUT_BOX_FLOATING_COUNTER_INDENT, 
        y1 - 1, 
        x2 + GUI_INPUT_BOX_FLOATING_COUNTER_INDENT, 
        y2 + 1,
        MMI_FALSE);

    gui_set_font(&small_font);

    if (!r2lMMIFlag)
    {
        gui_move_text_cursor(x2 - 1 - w, y1 + 1);
    }
    else
    {
        gui_move_text_cursor(x1 + 1 + w, y1 + 1);
    }

    gui_set_text_color(c);
    gui_print_text(str);
    gui_pop_clip();
#endif /* GUI_INPUT_BOX_FLOATING_COUNTER */
}


/*****************************************************************************
 * FUNCTION
 *  gui_ems_test_first_line
 * DESCRIPTION
 *  check if cursor is at first line
 * PARAMETERS
 *  b            [IN]             ems object
 * RETURNS
 *  MMI_TRUE if cursor at first line; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_ems_test_first_line(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 first_line_end_offset = 0;
    S32 first_line_end_object = 0;
    EMSPosition firstEndPos;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if start position, return true */
    if (TestFirstPosition(b->data, &b->data->CurrentPosition))
    {
        return MMI_TRUE;
    }

    first_line_end_offset = b->n_lines > 1 ? b->line_positions_text_offset[1] : (b->data->textLength);
    #ifdef __MMI_MESSAGES_EMS__
    first_line_end_object = b->n_lines > 1 ? b->line_positions_object_index[1] : (b->object_count);
    #endif
    
    firstEndPos.OffsetToText = first_line_end_offset;
    firstEndPos.Object = gui_ems_get_object_by_index(b, first_line_end_object);

    if ((b->data->CurrentPosition.OffsetToText < first_line_end_offset) ||
        (b->n_lines == 1) ||
        (gui_set_EMS_input_box_compare_position(b, &b->data->CurrentPosition, &firstEndPos)) < 0)
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
 *  gui_ems_test_last_line
 * DESCRIPTION
 *  check if cursor is at first line
 * PARAMETERS
 *  b            [IN]             ems object
 * RETURNS
 *  MMI_TRUE if cursor at first line; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_ems_test_last_line(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->data->CurrentPosition.OffsetToText > b->line_positions_text_offset[b->n_lines - 1])
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
 *  gui_EMS_input_box_set_default_text
 * DESCRIPTION
 *  Set EMS editor default text when content is empty
 * PARAMETERS
 *  b              [IN]             EMS inputbox object
 *  default_text   [IN]             default text
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_set_default_text(UI_EMS_input_box *b, UI_string_type default_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->default_text = default_text;
}
#endif /* UI_EMS_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  gui_ems_test_gsm_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static __inline MMI_BOOL gui_ems_test_gsm_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 b = 0;
#ifdef __SMS_R8_NATION_LANGUAGE__
    gui_ems_table_mechanism_enum cur_m = mmi_7bit_get_table_mechanism();
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__    
    if (cur_m == EMS_AUTO_DETECTION)
    {
        return mmi_7bit_test_gsm_character_in_all_table(c);
    }
#endif

    b = mmi_7bit_check_gsm(c);
    if (b)
        return MMI_TRUE;
    
    b = mmi_7bit_check_gsm_ext_character(c);
    if (b)
        return MMI_TRUE;

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_ems_test_UCS2_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_ems_test_UCS2_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __EMS_NON_STD_7BIT_CHAR__
    /* if force 7bit, return NONE UCS2*/
    if (srv_sms_is_7bit_setting(SRV_SMS_SIM_1) == MMI_TRUE)
    {
        if (srv_sms_is_no_standard_character(c))
            return MMI_FALSE;
        
        if (gui_ems_test_gsm_character(c))
            return MMI_FALSE;
        else
            return MMI_TRUE;
    }
    else
#endif /* __EMS_NON_STD_7BIT_CHAR__ */
    {
        if (gui_ems_test_gsm_character(c))
            return MMI_FALSE;
        else
            return MMI_TRUE;
    }
}

