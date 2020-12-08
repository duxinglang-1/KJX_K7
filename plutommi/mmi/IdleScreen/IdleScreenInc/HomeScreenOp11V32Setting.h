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
 * HomeScreenOp11V32Setting.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ORANGE Homescreen setting.
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _HOMESCREENOP11V32SETTING_H_
#define _HOMESCREENOP11V32SETTING_H_


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
    
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)

#ifdef __cplusplus
extern "C" {
#endif

#include "MMIDataType.h"

// auto add by kw_check begin
#include "kal_general_types.h"
// auto add by kw_check end 

/***************************************************************************** 
 * Define 
 *****************************************************************************/
#if defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_320X240__)
#define     MMI_HS_MAX_SIDERBAR_ITEMS       8
#else
#define     MMI_HS_MAX_SIDERBAR_ITEMS       12
#endif

#define     MMI_OP11_HS32_SB_HIST_MAX       16

#ifdef __MMI_MAINLCD_320X240__
#define     HS_MAX_ITEM_DISPLAYED_ON_IDLE   4
#define     HS_SEPERATE_LINE_INDEX          0
#elif defined(__MMI_MAINLCD_240X320__)
#define     HS_MAX_ITEM_DISPLAYED_ON_IDLE   6
#define     HS_SEPERATE_LINE_INDEX          1
#elif defined(__MMI_MAINLCD_176X220__)
#define     HS_MAX_ITEM_DISPLAYED_ON_IDLE   6
#define     HS_SEPERATE_LINE_INDEX          1
#elif defined(__MMI_MAINLCD_128X160__)
#define     HS_MAX_ITEM_DISPLAYED_ON_IDLE   4
#define     HS_SEPERATE_LINE_INDEX          0
#endif

/***************************************************************************** 
 * Global variable 
 *****************************************************************************/

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

extern void mmi_op11_hs32_setting_init(void);

extern void mmi_op11_hs_entry_personalise(void);

extern void mmi_op11_hs_entry_options_menu(S32 sidebar);
extern const U8 * mmi_op11_hs32_get_owner_number(void);

extern U8 mmi_op11_hs32_get_clock_size(void);
extern U8 mmi_op11_hs32_is_keypad_search(void);

extern void mmi_op11_hs32_set_done_flag(void);

extern S32 mmi_op11_hs32_get_shct_index(U8 sidebar, U8 shct);
extern S32 mmi_op11_hs_get_item_index(U8 item, const U8 * item_hist);

extern void mmi_op11_hs_save_id_history(void);

extern void mmi_op11_hs32_del_input_my_number_screen(void);

#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
extern void mmi_op11_hs32_view_mode_toggle(void);
extern void mmi_op11_hs32_force_sidebar_view(void);
extern MMI_BOOL mmi_op11_hs_is_wp_exist(U8 wp_id);
extern S32 mmi_op11_hs_get_wp_count(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif /*_HOMESCREENOP11V32SETTING_H_*/

