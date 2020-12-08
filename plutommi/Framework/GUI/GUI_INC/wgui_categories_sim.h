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
 *  wgui_categories_common.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Category header file
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WGUI_CATEGORIES_SIM_H__
#define __WGUI_CATEGORIES_SIM_H__
#include "MMI_features.h"
#include "MMIDataType.h"
#include "gui_typedef.h"
#include "gui_data_types.h"

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
#define WGUI_CAT9010_TEXT_SIZE 28  // because the text space is very small, so it is better to use simple text.
typedef struct{
	WCHAR text_0[WGUI_CAT9010_TEXT_SIZE + 1];  // if the sim area is grey, there will be only one line text.
	WCHAR text_1[WGUI_CAT9010_TEXT_SIZE + 1];
}wgui_cat9010_text_struct;

typedef void(*wgui_cat9010_get_text_func_type)(S32 sim_index, U8 sim_state, wgui_cat9010_text_struct *sim_info);
typedef enum{
	SIM_SPACE = 0,
	SIM_SELECTOR
}wgui_cat9010_type_enum;

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_show
 * DESCRIPTION
 *  show sim space / selector screen for Gemini plus
 * PARAMETERS
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title for the screen
 *   title_icon                    : [IN ] (N/A) Icon shown with the title
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Icon for the left softkey
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
 *   get_text_func                 : [IN ] (N/A) Get text by sim index
 *   sim_count                     : [IN ] (N/A) 3 card or 4 card
 *   sim_state                     : [IN ] (N/A) sim state (grey or normal)
 *   screen_type                   : [IN ] (N/A) space screen or selector screen
 *   highlight_index               : [IN ] (N/A) Highlight sim index
 *   gui_buffer                    : [IN ] (N/A) history buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat9010_show(
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
 			U8* gui_buffer);
/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_update
 * DESCRIPTION
 *  Update category screen if any change with sim x.
 * PARAMETERS
 *  sim_index        [IN]      sim index
 *  sim_state        [IN]      new sim state
 * RETURNS
 *  void
 *****************************************************************************/		
extern void wgui_cat9010_update(S32 sim_index, S32 sim_state);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9010_update_status_icon
 * DESCRIPTION
 *  Update category called by status icon bar
 * PARAMETERS
 *  icon_id        [IN]      changed icon id
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat9010_update_status_icon(S32 icon_id);

extern void wgui_cat9010_register_highlight_handler(void (*f)(S32 sim_index));

extern void wgui_cat9010_register_select_handler(void(*f)(S32 sim_index));
#endif
#endif /* __WGUI_CATEGORIES_COMMON_H__ */ 


