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
 *  vcp_symbol_picker.h
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  Symbol Picker Class
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_SYMBOL_PICKER_H__
#define	__VCP_SYMBOL_PICKER_H__
#include "vcp_symbol_picker.h"
#include "vcp_navi_title_bar.h"
#if defined(__MMI_VUI_COSMOS_CP__)
#include "vcp_tool_bar.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#endif
#include "vfx_main_scr.h"
#include "Vfx_page.h"
#include "vcp_scrollable.h"
#include "vcp_button.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "Vcp_button_util.h"
#endif
#include "vfx_base_popup.h"

extern "C"
{
    #include "MMI_features.h"
    #include "MMIDataType.h"
    #include "ImeGprot.h"
    #include "mmi_rp_srv_editor_def.h"
	#include "CommonScreensProt.h"
	#include "PixcomFontEngine.h"
}

#define VCP_SYMBOL_PICKER_MAX_SYMBOLS        49
#define VCP_NEWLINE_SYMBOL (0x0a)

class VIME_SymbolPicker_Page: public VfxBasePopup
{      
		public: 
		S32 m_no_of_symbols;
		VIME_SymbolPicker_Page() 
		{
		  	m_no_of_symbols=0;
			m_symbol_string[0]=0; 
		} 
		
#if 0	  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

	void Set_Symbols_List_Based_On_Inputmethod();
    void Insert_Selected_Symbol(U32 index);
    void SetButtonContent(VfxS32 index);
	virtual void onInit();
	virtual void onDeinit();
		void prepare_scrollable();
		void OnButtonClick(VfxObject* sender, VfxId id);
		void close_objects();
		void calculate_scrollbar_size(VfxS32 &width, VfxS32 &height);
		void Set_Button_Content_and_Rect();
        void OnButtonStateChanged(VfxObject* sender, VfxId id, VcpButtonStateEnum state);
	    VfxSignal2 <VfxObject *, VfxWChar> m_signalcallback;
		void enterIMEPopupMenu();
        private:
        //S32 m_no_of_symbols;
        VfxBool m_button_pressed;
        const VfxU8 *m_symbol_string[VCP_SYMBOL_PICKER_MAX_SYMBOLS];
		S32 m_current_highlighted_index;	
		VfxMainScr *m_mainScreen; 
		VcpScrollable *m_scrollable;
#ifdef __COSMOS_MMI_PACKAGE__
		VcpScrollingTextButton *m_textBtn[VCP_SYMBOL_PICKER_MAX_SYMBOLS];
#else
		VcpButton *m_textBtn[VCP_SYMBOL_PICKER_MAX_SYMBOLS];
#endif
		
		friend class VadpInputServerUI; 
};

#endif 