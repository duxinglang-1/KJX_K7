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
 *  CodingTemplate.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef COMMONSCREENSPROT_H
#define COMMONSCREENSPROT_H

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MMI_features.h"
extern void mmi_frm_highlight_inline_generic_done(void);
extern void mmi_frm_highlight_input_method_generic(void);
#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
extern void mmi_ime_commonscreens_highlight_imeoptions(void);
extern void mmi_ime_commonscreens_highlight_dictionary(void);
extern void mmi_ime_commonscreens_highlight_newword(void);
extern void mmi_ime_commonscreens_highlight_keyboard(void);
extern void mmi_ime_commonscreens_ime_highlight_writinglanguage(void);
extern void mmi_ime_commonscreens_ime_highlight_inputmodes(void);
extern void mmi_ime_commonscreens_highlight_advancedoptions(void);
extern void mmi_ime_commonscreens_entry_imeoptions(void);
extern void mmi_ime_commonscreens_entry_imeoptions_with_sg(mmi_id g_id);
extern void mmi_ime_commonscreens_advancedoptions_highlight_hdlr(S32 item_index);
extern void mmi_ime_commonscreens_keyboard_highlight_hdlr(S32 item_index);


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_is_in_java_screens
 * DESCRIPTION
 * is commonscreens in java Temp solution to be removed in 10.17
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_ime_commonscreens_is_in_java_screens();

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_config_is_java_screens
 * DESCRIPTION
 * config is commonscreens in java Temp solution to be removed in 10.17
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_commonscreens_config_is_java_screens(MMI_BOOL is_in);



#endif
#ifdef __MMI_CLIPBOARD__ 
/* clipboard */
extern void mmi_frm_highlight_clipboard_edit_option(void);
extern void mmi_frm_highlight_clipboard_edit_option_mark(void);
extern void mmi_frm_highlight_clipboard_edit_option_copy(void);
extern void mmi_frm_highlight_clipboard_edit_option_copy_all(void);
extern void mmi_frm_highlight_clipboard_edit_option_cut_all(void);
extern void mmi_frm_highlight_clipboard_edit_option_cut(void);
extern void mmi_frm_highlight_clipboard_edit_option_paste(void);
#endif /* __MMI_CLIPBOARD__ */


#endif /* COMMONSCREENSPROT_H */ 



