/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  DialerCuiCommon.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface for the dialer CUI common component.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef DIALER_CUI_COMMON_H
#define DIALER_CUI_COMMON_H

/* auto add by kw_check begin */
#include "DialerCuiObject.h"
#include "kal_general_types.h"
#include "custom_ecc.h"
#include "MMIDataType.h"
#include "wgui_categories_list.h"
/* auto add by kw_check end */

typedef enum
{
    CUI_DIALER_VOIP,
    CUI_DIALER_SIM1,
    CUI_DIALER_SIM2,
    CUI_DIALER_SIM3,
    CUI_DIALER_SIM4,
    CUI_DIALER_VIDEO,
    CUI_DIALER_VOICE,
	CUI_DIALER_ALL,
	CUI_DIALER_TOTAL,
} cui_dialer_ucm_type_enum;


extern cui_dialer_obj_struct *cui_dialer_get_obj_from_group(void);


extern ecc_verify_detail_enum cui_dialer_is_ecc(const WCHAR *dial_string);


extern void cui_dialer_do_toggle_silent_profile(void);


extern void cui_dialer_do_voice_mail_dial(void);


extern void cui_dialer_do_speed_dial(void);

#ifdef __MMI_FTE_SUPPORT__
extern void cui_dialer_pen_speed_dial(U16 pen_code);
#endif

extern void cui_dialer_do_abbrev_dial(void);


extern void cui_dialer_do_save_contact_ex(cui_dialer_obj_struct *obj);


extern void cui_dialer_do_save_contact(void);


extern void cui_dialer_do_ip_dial(void);


extern void cui_dialer_do_center_key_dial_ex(cui_dialer_obj_struct *obj);


extern void cui_dialer_do_center_key_dial(void);


extern void cui_dialer_do_send_key_dial(void);


extern void cui_dialer_do_send_key_dial_1(void);


extern void cui_dialer_do_send_key_dial_2(void);


extern void cui_dialer_input_first_char(cui_dialer_obj_struct *obj);


extern void cui_dialer_do_key_dial_by_type(cui_dialer_ucm_type_enum ucm_type);


extern void cui_dialer_do_close(void);


#if defined(__MMI_SEARCH_WEB__)
extern void cui_dialer_do_baidu_search(void);
#endif


extern void cui_dialer_set_touch_send_hdlr(
    FuncPtr sim1_func, 
    FuncPtr sim2_func);


extern void cui_dialer_set_speed_dial_hdlr(void);


extern void cui_dialer_set_handler(cui_dialer_obj_struct *obj);


extern void cui_dialer_init_capability(
    cui_dialer_capability_struct *capability);


extern void cui_dialer_entry_menu(void);

#if  defined(__MMI_DIALER_DYNAMIC_CALL_UI__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)

#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
extern void cui_dialer_set_dynamic_sim_hdlr(FuncPtr sim_func);
#endif

#endif

#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
//#ifdef __MMI_VIDEO_TELEPHONY__
extern void cui_dialer_do_video_dial(void);


extern void cui_dialer_do_voice_dial(void);
#endif


#endif /* DIALER_CUI_COMMON_H */

