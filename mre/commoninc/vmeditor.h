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
 *  vmeditor.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  Inline editor APIs
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================
 ******************************************************************************/

#ifndef VMEDITOR_H_
#define VMEDITOR_H_

#ifdef __MRE_LIB_EDITOR__

#include "vmeditor_sdk.h"

#else /* define all APIs to NULL if __MRE_LIB_EDITOR is not defined. */

#define vm_editor_create                                    (void*)NULL
#define vm_editor_close                                     (void*)NULL
#define vm_editor_set_IME                                   (void*)NULL
#define vm_editor_set_softkey                               (void*)NULL
#define vm_editor_get_softkey_height                        (void*)NULL
#define vm_editor_show                                      (void*)NULL
#define vm_editor_set_multiline_text_font                   (void*)NULL
#define vm_editor_get_font_attribute                        (void*)NULL
#define vm_editor_set_bg_image                              (void*)NULL
#define vm_editor_set_bg_border_style                       (void*)NULL
#define vm_editor_set_margin                                (void*)NULL
#define vm_editor_set_layer_handle                          (void*)NULL
#define vm_editor_set_update_text_callback                  (void*)NULL
#define vm_editor_set_update_text_with_cursor_rect_callback (void*)NULL
#define vm_editor_set_pos                                   (void*)NULL
#define vm_editor_get_pos                                   (void*)NULL
#define vm_editor_set_size                                  (void*)NULL
#define vm_editor_get_size                                  (void*)NULL
#define vm_editor_set_text                                  (void*)NULL
#define vm_editor_get_text                                  (void*)NULL
#define vm_editor_set_text_color                            (void*)NULL
#define vm_editor_set_cursor_color                          (void*)NULL
#define vm_editor_activate                                  (void*)NULL
#define vm_editor_deactivate                                (void*)NULL
#define vm_editor_get_active_editor                         (void*)NULL
#define vm_editor_get_fit_height                            (void*)NULL
#define vm_editor_get_indicator_height                      (void*)NULL
#define vm_editor_save                                      (void*)NULL
#define vm_editor_restore                                   (void*)NULL
#define vm_editor_is_draw_floating_indicator                (void*)NULL
#define vm_editor_redraw_floating_ui_within_rect            (void*)NULL
#define vm_editor_redraw_ime_screen                         (void*)NULL
#define vm_editor_get_extra_imui_layer_handler              (void*)NULL
#define vm_editor_set_imui_background_filler                (void*)NULL
#define vm_editor_insert_string                             (void*)NULL
#define vm_editor_set_cursor_index                          (void*)NULL
#define vm_editor_get_cursor_index                          (void*)NULL
#define vm_editor_set_default_text                          (void*)NULL
#define vm_editor_show_from_first_line                      (void*)NULL
#define vm_editor_show_from_start                           (void*)NULL

#endif /* end of __MRE_LIB_EDITOR__ */

#endif /* __VMEDITOR_H__ */ 

