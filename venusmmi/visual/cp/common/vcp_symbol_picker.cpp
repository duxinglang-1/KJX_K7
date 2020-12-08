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
 *  vcp_symbol_picker.cpp
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  Symbol picker class
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "vcp_symbol_picker.h"
#include "vcp_navi_title_bar.h"
#if defined(__MMI_VUI_COSMOS_CP__)
#include "vcp_tool_bar.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#endif
#include "vfx_main_scr.h"
#include "vfx_control.h"
#include "vfx_top_level.h" 
#include "Vfx_string.h"
#include "mmi_rp_srv_venus_component_popup_def.h"
#include "vadp_v2p_input_server.h"
#if defined(__COSMOS_MMI_PACKAGE__)
#include "mmi_rp_app_cosmos_global_def.h"
#endif 

extern "C"
{	 
	#include "MMIDataType.h"
	#include "ImeGprotEnums.h"
	#include "CommonScreensProt.h"
	#include "mmi_rp_srv_virtual_keyboard_misc_def.h"
	#include "GlobalResDef.h"
	#include "wgui_categories_inputs.h"
}
extern "C"
{
    void VIME_SymbolPicker_Entry();
}

#define VCP_SYMBOL_PICKER_MAX_SYMBOLS            49
#define VCP_SYMBOL_PICKER_DEFAULT_SYMBOLS		 39
#define VCP_SYMBOL_PICKER_MAX_GUJARATI_SYMBOLS		 46
#define VCP_SYMBOL_PICKER_MAX_CHINESE_SYMBOLS	 28
#define VCP_SYMBOL_PICKER_THAI_SYMBOLS			 42
#if defined(__MMI_LANG_MYANMAR__) && defined(__MMI_CSTAR__)
#define VCP_SYMBOL_PICKER_MYANMAR_SYMBOLS                43
#endif 

extern "C"
{
 const VfxU8 *vcp_SymbolPickerSymbols[VCP_SYMBOL_PICKER_DEFAULT_SYMBOLS] = 
{
	(VfxU8 *) "\n\0\0",
    (VfxU8 *) "\x2e\0\0",
    (VfxU8 *) "\x2c\0\0",
    (VfxU8 *) "?\0\0",
    (VfxU8 *) "!\0\0",
    (VfxU8 *) "\'\0\0",
    (VfxU8 *) "\"\0\0",
    (VfxU8 *) "(\0\0",
    (VfxU8 *) ")\0\0",
    (VfxU8 *) "@\0\0",
    (VfxU8 *) "\\\0\0",
    (VfxU8 *) "/\0\0",
    (VfxU8 *) ":\0\0",
    (VfxU8 *) "_\0\0",
    (VfxU8 *) ";\0\0",
    (VfxU8 *) "+\0\0",
    (VfxU8 *) "-\0\0",
    (VfxU8 *) "*\0\0",
    (VfxU8 *) "=\0\0",
    (VfxU8 *) "%\0\0",
    (VfxU8 *) "&\0\0",
    (VfxU8 *) "<\0\0",
    (VfxU8 *) ">\0\0",
    (VfxU8 *) "\xa3\0\0",
    (VfxU8 *) "\x24\0\0",
    (VfxU8 *) "\xa5\0\0",
    (VfxU8 *) "\xa7\0\0",
    /* (VfxU8*)"\xa2\0\0", */
    (VfxU8 *) "\xac\x20\0\0",
    (VfxU8 *) "\xa4\0\0",
    (VfxU8 *) "[\0\0",
    (VfxU8 *) "]\0\0",
    (VfxU8 *) "{\0\0",
    (VfxU8 *) "}\0\0",
    (VfxU8 *) "~\0\0",
    (VfxU8 *) "#\0\0",
	(VfxU8 *) "\xab\0\0",
	(VfxU8 *) "\xbb\0\0",
	(VfxU8 *) "\x5e\0\0",
    (VfxU8 *) " \0\0",
    /* (VfxU8*)" \0\0", */
};

#if defined(__MMI_LANG_GUJARATI__) || defined(__MMI_LANG_MALAYALAM__) || defined(__MMI_LANG_PUNJABI__)
 const VfxU8 *vcp_SymbolPickerGujaratiSymbols[VCP_SYMBOL_PICKER_MAX_GUJARATI_SYMBOLS] = 
{
	(VfxU8 *) "\n\0\0",
    (VfxU8 *) "\x2e\0\0",
    (VfxU8 *) "\x2c\0\0",
    (VfxU8 *) "?\0\0",
    (VfxU8 *) "!\0\0",
    (VfxU8 *) "\'\0\0",
    (VfxU8 *) "\"\0\0",
    (VfxU8 *) "(\0\0",
    (VfxU8 *) ")\0\0",
    (VfxU8 *) "@\0\0",
    (VfxU8 *) "\\\0\0",
    (VfxU8 *) "/\0\0",
    (VfxU8 *) ":\0\0",
    (VfxU8 *) "_\0\0",
    (VfxU8 *) ";\0\0",
    (VfxU8 *) "+\0\0",
    (VfxU8 *) "-\0\0",
    (VfxU8 *) "*\0\0",
    (VfxU8 *) "=\0\0",
    (VfxU8 *) "%\0\0",
    (VfxU8 *) "&\0\0",
    (VfxU8 *) "<\0\0",
    (VfxU8 *) ">\0\0",
    (VfxU8 *) "\xa3\0\0",
    (VfxU8 *) "\x24\0\0",
    (VfxU8 *) "\xa5\0\0",
    (VfxU8 *) "\xa7\0\0",
    /* (VfxU8*)"\xa2\0\0", */
    (VfxU8 *) "\xac\x20\0\0",
    (VfxU8 *) "\xa4\0\0",
    (VfxU8 *) "[\0\0",
    (VfxU8 *) "]\0\0",
    (VfxU8 *) "{\0\0",
    (VfxU8 *) "}\0\0",
    (VfxU8 *) "~\0\0",
    (VfxU8 *) "#\0\0",
    (VfxU8 *) " \0\0",
	(VfxU8 *) "\x64\x09\0\0",
	(VfxU8 *) "\x65\x09\0\0",
	(VfxU8 *) "\xa8\x20\0\0",
	(VfxU8 *) "\xab\0\0",
	(VfxU8 *) "\xbb\0\0",
	(VfxU8 *) "\x5e\0\0",
	(VfxU8 *) "\xB0\0\0",
	(VfxU8 *) "\x7C\0\0",
	(VfxU8 *) "\x60\0\0",
	(VfxU8 *) "\xB7\0\0",
    /* (VfxU8*)" \0\0", */
};

#endif
//static VfxU8 g_mmi_ime_ap_desired_symbol[SYMBOL_PICKER_MAX_SYMBOLS* 2 * sizeof(UI_character_type)]; /* symbol and null end */

#if defined(__MMI_LANG_ARABIC__)
 const VfxU8 *vcp_SymbolPickerArabicSymbols[VCP_SYMBOL_PICKER_DEFAULT_SYMBOLS] = 
{
	(VfxU8 *) "\n\0\0",
    (VfxU8 *) "\x2e\0\0",
    (VfxU8 *) "\x0c\06\0\0", /* Arabic Comma */
    (VfxU8 *) "\x1f\x06\0\0", /* Arabic Question Mark */
    (VfxU8 *) "!\0\0",
    (VfxU8 *) "\'\0\0",
    (VfxU8 *) "\"\0\0",
    (VfxU8 *) ")\0\0",
    (VfxU8 *) "(\0\0",
    (VfxU8 *) "@\0\0",
    (VfxU8 *) "\\\0\0",
    (VfxU8 *) "/\0\0",
    (VfxU8 *) ":\0\0",
    (VfxU8 *) "_\0\0",
    (VfxU8 *) "\x1b\x06\0\0",
    (VfxU8 *) "+\0\0",
    (VfxU8 *) "-\0\0",
    (VfxU8 *) "*\0\0",
    (VfxU8 *) "=\0\0",
    (VfxU8 *) "%\0\0",
    (VfxU8 *) "&\0\0",
    (VfxU8 *) ">\0\0",
    (VfxU8 *) "<\0\0",
    (VfxU8 *) "\xa3\0\0",
    (VfxU8 *) "\x24\0\0",
    (VfxU8 *) "\xa5\0\0",
    (VfxU8 *) "\xa7\0\0",
    (VfxU8 *) "\xac\x20\0\0",
    (VfxU8 *) "\xa4\0\0",
    (VfxU8 *) "]\0\0",
    (VfxU8 *) "[\0\0",
    (VfxU8 *) "}\0\0",
    (VfxU8 *) "{\0\0",
    (VfxU8 *) "~\0\0",
    (VfxU8 *) "#\0\0",
    (VfxU8 *) " \0\0",
};

#endif 

#if defined(__MMI_LANG_THAI__)
 const VfxU8 *vcp_SymbolPickerThaiSymbols[VCP_SYMBOL_PICKER_THAI_SYMBOLS] = 
{
	(VfxU8 *) "\n\0\0",
    (VfxU8 *) "\x2e\0\0",
    (VfxU8 *) "\x2c\0\0",
    (VfxU8 *) "?\0\0",
    (VfxU8 *) "!\0\0",
    (VfxU8 *) "\'\0\0",
    (VfxU8 *) "\"\0\0",
    (VfxU8 *) "(\0\0",
    (VfxU8 *) ")\0\0",
    (VfxU8 *) "@\0\0",
    (VfxU8 *) "\\\0\0",
    (VfxU8 *) "/\0\0",
    (VfxU8 *) ":\0\0",
    (VfxU8 *) "_\0\0",
    (VfxU8 *) ";\0\0",
    (VfxU8 *) "+\0\0",
    (VfxU8 *) "-\0\0",
    (VfxU8 *) "*\0\0",
    (VfxU8 *) "=\0\0",
    (VfxU8 *) "%\0\0",
    (VfxU8 *) "&\0\0",
    (VfxU8 *) "<\0\0",
    (VfxU8 *) ">\0\0",
    (VfxU8 *) "\xa3\0\0",
    (VfxU8 *) "\x24\0\0",
    (VfxU8 *) "\xa5\0\0",
    (VfxU8 *) "\xa7\0\0",
    (VfxU8 *) "\xac\x20\0\0",
    (VfxU8 *) "\xa4\0\0",
    (VfxU8 *) "[\0\0",
    (VfxU8 *) "]\0\0",
    (VfxU8 *) "{\0\0",
    (VfxU8 *) "}\0\0",
    (VfxU8 *) "~\0\0",
    (VfxU8 *) "#\0\0",
    (VfxU8 *) " \0\0",
    (VfxU8 *) "\x3f\x0e\0",
	(VfxU8 *) "\x46\x0e\0\0",
	(VfxU8 *) "\x2f\x0e\0\0",
	(VfxU8 *) "\x4f\x0e\0\0",
    (VfxU8 *) "\x5a\x0e\0",
    (VfxU8 *) "\x5b\x0e\0",
};

#endif
#if defined(__MMI_LANG_MYANMAR__) && defined(__MMI_CSTAR__)
 const U8 *vcp_SymbolPickerMyanmarSymbols[VCP_SYMBOL_PICKER_MYANMAR_SYMBOLS] = 
 {
	 (VfxU8 *) "#\x10\0",
	 (VfxU8 *) "$\x10\0",
	 (VfxU8 *) "%\x10\0",
	 (VfxU8 *) "&\x10\0",
	 (VfxU8 *) "'\x10\0",
	 (VfxU8 *) ")\x10\0",
	 (VfxU8 *) "*\x10\0",
	 (VfxU8 *) "?\x10\0",
	 (VfxU8 *) "L\x10\0",
	 (VfxU8 *) "M\x10\0",
	 (VfxU8 *) "N\x10\0",
	 (VfxU8 *) "O\x10\0",
	 (VfxU8 *) "\x2e\0\0",
	 (VfxU8 *) "\x2c\0\0",
	 (VfxU8 *) "?\0\0",
	 (VfxU8 *) "!\0\0",
	 (VfxU8 *) "\'\0\0",
	 (VfxU8 *) "\"\0\0",
	 (VfxU8 *) "(\0\0",
	 (VfxU8 *) ")\0\0",
	 (VfxU8 *) "@\0\0",
	 (VfxU8 *) "\\\0\0",
	 (VfxU8 *) "/\0\0",
	 (VfxU8 *) ":\0\0",
	 (VfxU8 *) "_\0\0",
	 (VfxU8 *) ";\0\0",
	 (VfxU8 *) "+\0\0",
	 (VfxU8 *) "-\0\0",
	 (VfxU8 *) "*\0\0",
	 (VfxU8 *) "=\0\0",
	 (VfxU8 *) "%\0\0",
	 (VfxU8 *) "&\0\0",
	 (VfxU8 *) "<\0\0",
	 (VfxU8 *) ">\0\0",	
	 (VfxU8 *) "\x24\0\0",    
	 (VfxU8 *) "[\0\0",
	 (VfxU8 *) "]\0\0",
	 (VfxU8 *) "{\0\0",
	 (VfxU8 *) "}\0\0",
	 (VfxU8 *) "~\0\0",
	 (VfxU8 *) "#\0\0",
	 (VfxU8 *) " \0\0",
	 (VfxU8 *) "\n\0\0",
 };
#endif

 const VfxU8 *vcp_SymbolPickerChineseSymbols[VCP_SYMBOL_PICKER_MAX_CHINESE_SYMBOLS] = 
{
	(VfxU8 *) "\n\0\0",
    (VfxU8 *) "\x0c\xff\0\0",
    (VfxU8 *) "\x02\x30\0\0",  /* using CJK defned value instead of full-width defined value(VfxU8*)"\x61\xff\0\0", */
    (VfxU8 *) "\x01\x30\0\0",  /* using CJK defned value instead of full-width defined value(VfxU8*)"\x64\xff\0\0", */
    (VfxU8 *) "\x1a\xff\0\0",
    (VfxU8 *) "\x1b\xff\0\0",
    (VfxU8 *) "\x1f\xff\0\0",
    (VfxU8 *) "\x26\x20\0\0",
    (VfxU8 *) "\x01\xff\0\0",
    (VfxU8 *) "\x0a\x30\0\0",
    (VfxU8 *) "\x0b\x30\0\0",
    (VfxU8 *) "\x0e\x30\0\0",
    (VfxU8 *) "\x0f\x30\0\0",
    (VfxU8 *) "\x1c\x20\0\0",
    (VfxU8 *) "\x1d\x20\0\0",
    (VfxU8 *) "\x08\xff\0\0",
    (VfxU8 *) "\x09\xff\0\0",
    (VfxU8 *) "\x0c\x30\0\0",  /* using CJK defned value instead of full-width defined value(VfxU8*)"\x62\xff\0\0", */
    (VfxU8 *) "\x0d\x30\0\0",  /* using CJK defned value instead of full-width defined value(VfxU8*)"\x63\xff\0\0", */
    (VfxU8 *) "\x18\x20\0\0",
    (VfxU8 *) "\x19\x20\0\0",
    (VfxU8 *) "\x0e\xff\0\0",
    (VfxU8 *) "\x1c\xff\0\0",
    (VfxU8 *) "\x1e\xff\0\0",
    (VfxU8 *) "\x5e\xff\0\0",
    (VfxU8 *) "\x3b\xff\0\0",
    (VfxU8 *) "\x3d\xff\0\0",
    (VfxU8 *) "\x20\x00\0\0",
};

}

 const VfxU8 VCP_SymbolPickerLFString[] = {0x85, 0, '\0', 0};
 const VfxU8 VCP_SymbolPickerSpaceString[] = {0x86, 0, '\0', 0};

#if defined(__MMI_MAINLCD_480X800__)
   #define SYMBOL_PICKER_ITEM_WIDTH 68
   #define SYMBOL_PICKER_ITEM_HEIGHT 68
   #define SYMBOL_PICKER_LEFT_GAP 23//5
   #define SYMBOL_PICKER_TOP_GAP 12//0
   #define SYMBOL_PICKER_START_Y 50
   #define SYMBOL_PICKER_PAGE_WIDTH 380//350
   #define SYMBOL_PICKER_PAGE_HEIGHT 520//490
   #define SYMBOL_PICKER_FONT_SIZE 25
   #define SYMBOL_PICKER_SCROLLABLE_HEIGHT_DIFFERENCE 28//15
#elif defined(__MMI_MAINLCD_320X480__)
   #define SYMBOL_PICKER_ITEM_WIDTH 54
   #define SYMBOL_PICKER_ITEM_HEIGHT 54
   #define SYMBOL_PICKER_MAX_PAGE_WIDTH 260
   #define SYMBOL_PICKER_SHADOW_WIDTH 5
   #define SYMBOL_PICKER_MAX_PAGE_HEIGHT 
   #define SYMBOL_PICKER_FONT_SIZE 22
#define SYMBOL_PICKER_PAGE_WIDTH   280
 #define SYMBOL_PICKER_PAGE_HEIGHT 400
   #define SYMBOL_PICKER_LEFT_GAP 10
   #define SYMBOL_PICKER_TOP_GAP 10
   #define SYMBOL_PICKER_POPUP_GAP 16
   #define SYMBOL_PICKER_SCROLLABLE_HEIGHT_DIFFERENCE 15

#elif defined(__MMI_MAINLCD_240X400__)
   #define SYMBOL_PICKER_ITEM_WIDTH 43
   #define SYMBOL_PICKER_ITEM_HEIGHT 43
   #define SYMBOL_PICKER_LEFT_GAP 5
   #define SYMBOL_PICKER_START_Y 42
   #define SYMBOL_PICKER_PAGE_WIDTH 220
   #define SYMBOL_PICKER_PAGE_HEIGHT 320
    #define SYMBOL_PICKER_FONT_SIZE 20
   #define SYMBOL_PICKER_TOP_GAP 0
   #define SYMBOL_PICKER_SCROLLABLE_HEIGHT_DIFFERENCE 15

#elif defined(__MMI_MAINLCD_240X320__)
   #define SYMBOL_PICKER_ITEM_WIDTH 43
   #define SYMBOL_PICKER_ITEM_HEIGHT 43
   #define SYMBOL_PICKER_LEFT_GAP 5
   #define SYMBOL_PICKER_START_Y 41
   #define SYMBOL_PICKER_PAGE_WIDTH 220
   #define SYMBOL_PICKER_PAGE_HEIGHT 280
    #define SYMBOL_PICKER_FONT_SIZE 20
   #define SYMBOL_PICKER_TOP_GAP 0
   #define SYMBOL_PICKER_SCROLLABLE_HEIGHT_DIFFERENCE 15
#else /* */
   #define SYMBOL_PICKER_ITEM_WIDTH 40
   #define SYMBOL_PICKER_ITEM_HEIGHT 40
   #define SYMBOL_PICKER_LEFT_GAP 3
   #define SYMBOL_PICKER_START_Y 42
   #define SYMBOL_PICKER_PAGE_WIDTH 240
   #define SYMBOL_PICKER_PAGE_HEIGHT 215
    #define SYMBOL_PICKER_FONT_SIZE 20
   #define SYMBOL_PICKER_TOP_GAP 0
   #define SYMBOL_PICKER_SCROLLABLE_HEIGHT_DIFFERENCE 15
#endif 

#define SYMBOL_PICKER_EXTRA_SCROLL 10

#define VCP_SPACE_SYMBOL (0x20)
#define VCP_NEWLINE_SYMBOL (0x0a)
#define VCP_EURO_SYMBOL (0x20ac)


// Sets the symbol list bases on current input method 
void VIME_SymbolPicker_Page::Set_Symbols_List_Based_On_Inputmethod()
{
    VfxS32 i;
    VfxS32 j = 0;
    VfxWChar symb;
    VfxU8** symbol_table;
    VfxS32 max_num = 0;
	mmi_fe_enable_proprietary_symbol_display();
        switch (mmi_imm_get_curr_input_mode())
        {
            case IMM_INPUT_MODE_SM_MULTITAP_PINYIN:
            case IMM_INPUT_MODE_SM_PINYIN:
            case IMM_INPUT_MODE_TR_BOPOMO:
            case IMM_INPUT_MODE_TR_MULTITAP_BOPOMO:
            case IMM_INPUT_MODE_TR_STROKE:
            case IMM_INPUT_MODE_HK_STROKE:                
            case IMM_INPUT_MODE_SM_STROKE:
            case IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO:
            case IMM_INPUT_MODE_QUICK_SEARCH_PINYIN:
            case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
            case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:	
            case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:	
				
                symbol_table = (VfxU8** )vcp_SymbolPickerChineseSymbols;
                max_num = VCP_SYMBOL_PICKER_MAX_CHINESE_SYMBOLS;
                break;
        #if defined(__MMI_LANG_ARABIC__) 
            case IMM_INPUT_MODE_SMART_ARABIC:
            case IMM_INPUT_MODE_MULTITAP_ARABIC:
            case IMM_INPUT_MODE_ARABIC_NUMERIC:
                symbol_table = (VfxU8** )vcp_SymbolPickerArabicSymbols;
                max_num = VCP_SYMBOL_PICKER_DEFAULT_SYMBOLS;
                break;
        #endif        

		#if defined(__MMI_LANG_GUJARATI__) || defined(__MMI_LANG_MALAYALAM__) || defined(__MMI_LANG_PUNJABI__)
			case IMM_INPUT_MODE_MULTITAP_GUJARATI:
			case IMM_INPUT_MODE_SMART_GUJARATI:
			case IMM_INPUT_MODE_MULTITAP_MALAYALAM :
			case IMM_INPUT_MODE_SMART_MALAYALAM :
			case IMM_INPUT_MODE_MULTITAP_PUNJABI:
			case IMM_INPUT_MODE_SMART_PUNJABI :
				symbol_table = (VfxU8** )vcp_SymbolPickerGujaratiSymbols;
				max_num = VCP_SYMBOL_PICKER_MAX_GUJARATI_SYMBOLS;
				break;
		#endif

        #if defined(__MMI_LANG_THAI__)
            case IMM_INPUT_MODE_MULTITAP_THAI:
            case IMM_INPUT_MODE_SMART_THAI:
                 symbol_table = (VfxU8** )vcp_SymbolPickerThaiSymbols;
                max_num = VCP_SYMBOL_PICKER_THAI_SYMBOLS;
                break;
        #endif
		#if defined(__MMI_LANG_MYANMAR__) && defined(__MMI_CSTAR__)
   			 case IMM_INPUT_MODE_MULTITAP_MYANMAR:
    		    symbol_table = (VfxU8**)vcp_SymbolPickerMyanmarSymbols;
				max_num = VCP_SYMBOL_PICKER_MYANMAR_SYMBOLS;
        		break;
		#endif
            default:
                symbol_table = (VfxU8**)vcp_SymbolPickerSymbols;
                max_num = VCP_SYMBOL_PICKER_DEFAULT_SYMBOLS;
                break;
        }

        j = 0;
		//DO the handling for JAVA
        if (g_mmi_ime_symbol_table_stack_top >= 0)
        {
			max_num = g_mmi_ime_prepare_symbol_table[g_mmi_ime_symbol_table_stack_top](g_mmi_ime_ap_desired_symbol, VCP_SYMBOL_PICKER_MAX_SYMBOLS, symbol_table, max_num);
            if (max_num > SYMBOL_PICKER_MAX_SYMBOLS)
                ASSERT(0);
        }
			
        for (i = 0; i < max_num && j < VCP_SYMBOL_PICKER_MAX_SYMBOLS - 1; i++)
        {
            if (g_mmi_ime_symbol_table_stack_top >= 0)
            {
                symb = g_mmi_ime_ap_desired_symbol[(i<<2)] | (g_mmi_ime_ap_desired_symbol[(i<<2)+1] << 8);
            }
            else
            {			
                symb =(*(symbol_table[i]) | ((*(symbol_table[i]+1))<<8));
			}
            if (((MMI_current_input_ext_type & INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL) &&  (symb == (VfxWChar)VCP_NEWLINE_SYMBOL)))
			{
				continue;
			}
			else if(((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD) &&
                        (symb == (VfxWChar)VCP_EURO_SYMBOL)))
			{
				  continue;
			}
			else if(!mmi_imm_test_input(&symb, 1))
            {
                continue;
            }
            else
            {
				if (g_mmi_ime_symbol_table_stack_top >= 0)
				{
					m_symbol_string[j] = &g_mmi_ime_ap_desired_symbol[(i<<2)];
				}
				else
				{
                   m_symbol_string[j] = symbol_table[i]; 
				}
                   j++;
            }
        }
		m_symbol_string[j] = 0;
		m_no_of_symbols=j;
}

void VIME_SymbolPicker_Page::Set_Button_Content_and_Rect()
{
	   VfxS32 i;
	   //VfxS32 x=0;
	   VfxS32 curr_x=SYMBOL_PICKER_LEFT_GAP,curr_y=SYMBOL_PICKER_TOP_GAP;	
	   for(i=0;i<m_no_of_symbols;i++)
	   {	 
		   if(curr_x+SYMBOL_PICKER_ITEM_WIDTH >SYMBOL_PICKER_PAGE_WIDTH+6)
		   {
			   curr_x= SYMBOL_PICKER_LEFT_GAP;
			   curr_y+=  SYMBOL_PICKER_ITEM_HEIGHT;
		   }
#ifdef __COSMOS_MMI_PACKAGE__
		   VFX_OBJ_CREATE(m_textBtn[i], VcpScrollingTextButton, m_scrollable);
		   m_textBtn[i]->setIsHighlighted(VFX_TRUE);
		   m_textBtn[i]->setScrollOnHighlight(VFX_TRUE);
#else
		   VFX_OBJ_CREATE(m_textBtn[i], VcpButton, m_scrollable);
#endif
		   m_textBtn[i]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
		   m_textBtn[i]->setId(i);
		   m_textBtn[i]->setFuzzy(VFX_FALSE);
		   m_textBtn[i]->setRect(curr_x,curr_y,SYMBOL_PICKER_ITEM_WIDTH,SYMBOL_PICKER_ITEM_HEIGHT);
		   m_textBtn[i]->setImage(VcpStateImage(NULL));
		   // m_textBtn[i]->setIsHighlighted(VFX_TRUE);
		   // m_textBtn[i]->setBorder(VRT_COLOR_GREY, 1);
		   m_textBtn[i]->m_signalClicked.connect(this, &VIME_SymbolPicker_Page::OnButtonClick);
		   m_textBtn[i]->m_signalStateChanged.connect(this, &VIME_SymbolPicker_Page::OnButtonStateChanged);
		   m_textBtn[i]->setBgImageList(NULL);
		   VfxFontDesc m_numBtnFont;
		   // VfxColor m_numBtnFontColor(0, 0, 0, 0);
		   m_numBtnFont.size = VFX_FONT_DESC_VF_SIZE(SYMBOL_PICKER_FONT_SIZE);
		   m_textBtn[i]->setTextFont(m_numBtnFont);
#if !defined(__COSMOS_MMI_PACKAGE__)
		   m_textBtn[i]->setTextColor(VRT_COLOR_BLACK);
#endif 
		   SetButtonContent(i);
		   curr_x+=SYMBOL_PICKER_ITEM_WIDTH;
	   }
} 

void   VIME_SymbolPicker_Page::SetButtonContent(VfxS32 index)
{
	/* The textbutton does not allow to use string constants directly so we need to use this complex 
	   statement to set the button content */ 
	VfxWChar symb=0;
	 symb =(VfxWChar)(*(m_symbol_string[index]) | ((*(m_symbol_string[index]+1))<<8));
	if(symb == (VfxWChar)VCP_SPACE_SYMBOL)
		m_textBtn[index]->setText(VFX_WSTR_MEM((VfxWChar *)VCP_SymbolPickerSpaceString));
	else if(symb == (VfxWChar)VCP_NEWLINE_SYMBOL)
		m_textBtn[index]->setText(VFX_WSTR_MEM((VfxWChar *)VCP_SymbolPickerLFString));
	else 
		m_textBtn[index]->setText(VFX_WSTR_MEM((VfxWChar *)m_symbol_string[index]));
}


void VIME_SymbolPicker_Page::onInit()
{
    VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getActiveScr()->addChildFrame(this);
	VfxBasePopup::onInit();
	//hack [Imc key dont know that symbol picker need to launch or not So symbol picker need to first check 
	// no. of symbol first if no symbol then return]
	Set_Symbols_List_Based_On_Inputmethod();
	if(m_no_of_symbols == 0)
	{
		return ;
	}
	VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
	
    vrt_size_struct mainScreenSize;
	vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
	m_current_highlighted_index=0;
#if defined(__COSMOS_MMI_PACKAGE__)
	setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND));
	setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#else 
	setBgColor(VRT_COLOR_WHITE);
#endif 
	//hack 
	//Set_Symbols_List_Based_On_Inputmethod();
	VFX_OBJ_CREATE(m_scrollable, VcpScrollable, this);
#if !defined(__COSMOS_MMI_PACKAGE__)
	m_scrollable->setScrollIndicatorColor(VfxColor(VRT_COLOR_GREEN));
#endif 
    m_scrollable->enableBoundaryLight(VFX_FALSE);
    VfxS32 width=0, height=0 ;
	//VfxU32 start_x,start_y;
	
	//VIME_SymbolPicker_get_size(width,height);
    m_button_pressed = VFX_FALSE;
	
	
    width = SYMBOL_PICKER_PAGE_WIDTH + 10;
	/*Done Temp solution for QVGA code need to Revise*/
#ifdef __MMI_MAINLCD_240X320__
	if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_90 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_270)
    {   
		height = 220;	
    }
    else
#endif
    {     
		height = SYMBOL_PICKER_PAGE_HEIGHT;
    }
    /* if rotation make it impossible to fir like in case of QVGA ; as old code is taking 8 as start poin using the same 8*2 =16*/
    /* cleanup of the file is needed ; messy code written */
	
    if(height > mainScreenSize.height)
    {
        height = mainScreenSize.height -16;
    }
	this->setBounds(VfxRect(0,0,width  ,height ));
	prepare_scrollable();
	Set_Button_Content_and_Rect();
	
	//setCatchFocus(VFX_FALSE);
	
	setAutoDestory(VFX_FALSE);
	
    setCatchFocus(VFX_FALSE);
	
	VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
	
    inputServerUI->registerIMEPopupMenu(this);
}

void VIME_SymbolPicker_Page::calculate_scrollbar_size(VfxS32 &width, VfxS32 &height)
{
   VfxS32 no_of_rows = 0;
	VfxS32 total_width= m_no_of_symbols*SYMBOL_PICKER_ITEM_WIDTH;

	width=SYMBOL_PICKER_PAGE_WIDTH - (2*SYMBOL_PICKER_LEFT_GAP);
	if(total_width%SYMBOL_PICKER_PAGE_WIDTH ==0)
		no_of_rows= total_width/width;
   else
        no_of_rows= total_width/width +1;
	height= no_of_rows * SYMBOL_PICKER_ITEM_HEIGHT ;
}

void  VIME_SymbolPicker_Page::prepare_scrollable()
{
	VfxS32 width, height;
	calculate_scrollbar_size(width,height); 
	VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
	 //m_scrollable->setViewRect(VfxRect(0, 8, SYMBOL_PICKER_PAGE_WIDTH + 10, SYMBOL_PICKER_PAGE_HEIGHT -SYMBOL_PICKER_SCROLLABLE_HEIGHT_DIFFERENCE));
/*Done Temp solution for QVGA code need to Revise*/
#ifdef __MMI_MAINLCD_240X320__
	 if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_90 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_270)
    { 
		m_scrollable->setBounds(VfxRect(0, 8, SYMBOL_PICKER_PAGE_WIDTH + 10, 220 -SYMBOL_PICKER_SCROLLABLE_HEIGHT_DIFFERENCE));	
	}
	else
#elif __MMI_MAINLCD_320X480__
	 if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_90 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_270)
    { 
		m_scrollable->setBounds(VfxRect(0, 8, SYMBOL_PICKER_PAGE_WIDTH + 10, 300 -SYMBOL_PICKER_SCROLLABLE_HEIGHT_DIFFERENCE));	
	}
	else
#elif __MMI_MAINLCD_480X800__
	 if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_90 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_270)
    { 
		m_scrollable->setBounds(VfxRect(0, 8, SYMBOL_PICKER_PAGE_WIDTH + 10, 450 -SYMBOL_PICKER_SCROLLABLE_HEIGHT_DIFFERENCE));	
	}
	else
#endif
	{
	 m_scrollable->setBounds(VfxRect(0, 8, SYMBOL_PICKER_PAGE_WIDTH + 10, SYMBOL_PICKER_PAGE_HEIGHT-SYMBOL_PICKER_SCROLLABLE_HEIGHT_DIFFERENCE));
	}
	m_scrollable->setContentSize(VfxSize(width, height+ 2*SYMBOL_PICKER_EXTRA_SCROLL));

#ifdef __MMI_MAINLCD_480X800__
	m_scrollable->setPos(0, 16);
#else
	 m_scrollable->setPos(0, 8);
#endif
	//m_scrollable->setValidContentRect(VfxRect(0, 0, width, height));
   
}
    

void VIME_SymbolPicker_Page::OnButtonClick(VfxObject* sender, VfxId id)
{
           if(m_button_pressed == VFX_TRUE)
           {
               return;
           }
           m_button_pressed = VFX_TRUE;
	   VfxWChar symbol=0;
	   symbol =(VfxWChar)(*(m_symbol_string[id]) | ((*(m_symbol_string[id]+1))<<8));
	   m_signalcallback.postEmit(this, symbol);	 
	   leave(VFX_TRUE);
	   VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
	    inputServerUI->m_popupMenu->exit(VFX_TRUE); 
}

void VIME_SymbolPicker_Page::OnButtonStateChanged(VfxObject* sender, VfxId id, VcpButtonStateEnum state)
{

	if(state == VCP_BUTTON_STATE_PRESSED)
	{
           #if defined(__COSMOS_MMI_PACKAGE__)
		m_textBtn[id]->setBorder(VFX_COLOR_RES(CLR_COSMOS_TEXT_LINK),2);
           #else 
                 m_textBtn[id]->setBorder(VRT_COLOR_GREEN, 2);
           #endif 
	}
	if(state == VCP_BUTTON_STATE_NORMAL)
	{
		if(m_scrollable !=NULL) // we don't have other option because scrollable has closed this object
	 	m_textBtn[id]->setBorder(VRT_COLOR_TRANSPARENT, 0);
	}
}


void VIME_SymbolPicker_Page::close_objects()
{
			VFX_OBJ_CLOSE(m_scrollable);			 
}

void VIME_SymbolPicker_Page::onDeinit()
{
    VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 

	inputServerUI->leaveIMEPopupMenu(this);
    inputServerUI->unRegisterIMEPopupMenu(this);
    
    VfxBasePopup::onDeinit();
}
void VIME_SymbolPicker_Page::enterIMEPopupMenu()
{
    VsrvInputBinding *inputBinding = VFX_OBJ_GET_INSTANCE(VadpInputServer)->m_currInputBinding;

    if (inputBinding)
    {
        InputConnection *connPtr = inputBinding->getConnection();

        if (connPtr)
        {
            connPtr->sendIMENotification(IME_NOTIFICATION_SHOW_IME_POPUP, NULL);
        }
    }
}
