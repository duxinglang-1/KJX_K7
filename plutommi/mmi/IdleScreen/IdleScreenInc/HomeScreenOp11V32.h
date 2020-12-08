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
 *  HomeScreenOp11V32.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  OP11 HomeScreen version 3.1 & 3.2 header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef MMI_OP11_HS32_H
#define MMI_OP11_HS32_H
    
#include "MMI_features.h"

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)

#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "HomeScreenOp11V32Def.h"
#include "HomeScreenOp11V32Gprot.h"

// auto add by kw_check begin
#include "kal_general_types.h"
#include "kal_public_defs.h"
// auto add by kw_check end 

/************************************************************/
/*															*/
/*			Constants and values Define                 				*/
/*															*/
/************************************************************/
#define MMI_OP11_HS32_AP_SIDEBAR_ICON_MAX  12
#define MMI_OP11_HS32_AP_WP_MAX  3

#define MMI_OP11_HS32_AP_INDCTR_MAX  2
#define MMI_OP11_HS32_AP_SHCT_MAX  8

#define MMI_OP11_HS32_DEVICE_STATUS_TOV 2000

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

#define MMI_HS32_GET_SIZE(x)                  (sizeof(x) / sizeof(x[0]))

/* Homescreen control flag: */
#define MMI_OP11_HS32_HISTORY_DISCARDED        0x0001
#define MMI_OP11_HS32_HISTORY_FOR_REDRAW       0x0002
#define MMI_OP11_HS32_REVERT_TIMEOUT      0x0004
#define MMI_OP11_HS32_ACTIVATE_BY_SSC      0x0008
#define MMI_OP11_HS32_HISTORY_NO_SSE       0x0010

typedef enum
{
    SPECIAL_AP_SYNC_NOTREADY,                     /* shortcut count not decided yet */
    SPECIAL_AP_SYNC_DONE,                              /* shortcut count sync finished */
//    SPECIAL_AP_SYNC_UPDATE,                         /* APP actively update the sidebar info and will change the shortcut count */
    SPECIAL_AP_SYNC_TYPE_MAX
} mmi_op11_hs32_special_ap_data_sync_enum;

/************************************************************/
/*															*/
/*			HS & Category concerned Data Structure				*/
/*															*/
/************************************************************/

/* Shortcut context structure */
typedef struct
{
/* HS info */
//    S32 sidebar_id;
    U8 shct_id;
    S8 with_content_flag;  /*0: no content; 1: have content  */
//    S32 panel_flag;     /* for category use */
//    U16 shct_label[MMI_OP11_HS32_SHCT_LABEL_STRLEN_MAX+1]; 
/* following for ap fill data  */
    mmi_op11_hs32_shct_data_struct *data_p;
}mmi_op11_hs32_shct_struct;


/* sidebar context structure (HS use) */
typedef struct
{
/* for idle using  */
    U8 sidebar_id;
    S8 sidebar_status;
/* for view item data  */
//    S32 sidebar_icon;
//    U8 indicator_num;
//    U8 indicator_id[MMI_OP11_HS32_AP_INDCTR_MAX];
//    U16 indicator_icon[MMI_OP11_HS32_AP_INDCTR_MAX];
    S32 indicator_data[MMI_OP11_HS32_AP_INDCTR_MAX];
//    S32 indicator_position[MMI_OP11_HS32_AP_INDCTR_MAX];
/* shortcut data  */
    S32 shortcut_count;
    mmi_op11_hs32_shct_struct *shortcut_p;
}mmi_op11_hs32_sidebar_struct;


/* sidebar context structure (HS use) */
typedef struct
{
    WCHAR *name_p;  /* e.g. email sender names buffer pointer  */
    MYTIME item_time;        /* e.g. email received times  */
}mmi_op11_hs32_eml_widget_struct;


/************************************************************/
/*			HS main context structures                  				*/
/************************************************************/

typedef struct
{
    void *app_mem_pool;
    KAL_ADM_ID adm_pool_id;
} mmi_op11_hs_context_mem_struct;


typedef struct
{
     // SIDEBAR_VIEW, EXPANDED_VIEW
    S32 view_mode; 

    // STATE_INIT, STATE_IDLE, STATE_ACTIVE
    S32 view_state;

    // The vertical position of the sidebar
    S32 sidebar_index;

    // The horizontal highlight position of shortcut bar.
    S32 shortcut_index;
} mmi_op11_hs_screen_history_struct;


/* home screen main context structure: */
typedef struct
{
    mmi_op11_hs_context_mem_struct mem;
    U8 *history;
    U32 flag;

    mmi_op11_hs32_sidebar_struct *sidebar_p;
    U8 sidebar_count;

    U8 shct_hist_count[MMI_OP11_HS32_AP_TYPE_MAX];
    U8 shct_ui_count[MMI_OP11_HS32_AP_TYPE_MAX];

    U8 history_revised;
    U8 shct_phb_reordered;
    U8 shct_eml_reordered;
    U8 view_mode;

    S32 eml_account[MMI_OP11_HS32_AP_EML_ACCOUNT_MAX];
    U8 alm_account[MMI_OP11_HS32_AP_ALM_MAX];
    U16 us_vip[MMI_OP11_HS32_AP_CON_VIP_MAX];
    S32 us_vip_count;

    U16 vip_index;
    U16 eml_account_index;
    U8 is_sel_screen_changed;
    U8 last_set_index;
    U8 us_vip_switch;

    U8 is_wp_edit;
    S32 wp_mgr_index;
    S32 wp_sel_index;
   
    MMI_ID phb_list_sg_id;
    MMI_ID lsk_sg_id;
    MMI_ID csk_sg_id;
    MMI_ID flightmode_sg_id;
    MMI_ID fmgr_sg_id;
    mmi_op11_hs32_shct_data_struct* mes_data_p[MMI_OP11_HS32_SHCT_MES_NEW_TYPE_MAX];
} mmi_op11_hs_context_struct;




/************************************************************/
/*															*/
/*			external functions 									*/
/*															*/
/************************************************************/
extern S32 mmi_op11_hs_get_sidebar_index(S32 sidebar_id);
extern mmi_op11_hs32_sidebar_struct* mmi_op11_hs32_get_sidebar_info_pointer(S32 sidebar_id);
extern mmi_op11_hs32_shct_data_struct* mmi_op11_hs32_get_shct_data_pointer_internal(S32 sidebar_id, S32 shct_id);

extern void mmi_op11_hs32_realloc_and_update_shct(mmi_op11_hs32_sidebar_struct *sidebar_info);

extern void mmi_op11_hs32_shct_select_cb_cll(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_con(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_mes(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_eml(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_omr(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_owd(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_pro(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_alm(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_cal(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_mus(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_pho(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_cnx(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_dst(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_stk(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_tph(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_vip(S32 shct_id);
extern void mmi_op11_hs32_shct_select_cb_uscon(S32 shct_id);

extern void mmi_op11_hs32_get_device_status(S32 update_memory, void *dev_p);


extern U8* mmi_op11_hs32_option_context_exec(S32 sidebar_id, S32 op_flag);
extern void mmi_op11_hs32_vip_launch_call(U16 vip_index);
extern void mmi_op11_hs32_vip_send_mes(U16 vip_index);
extern void mmi_op11_hs32_vip_view_contact(U16 vip_index);

extern void mmi_op11_hs32_entry_us_vip_option_screen(void);
extern void mmi_op11_hs32_us_vip_view_contact(void);
extern void mmi_op11_hs32_us_vip_add_new(void);
extern void mmi_op11_hs32_us_vip_make_call(void);

extern void mmi_op11_hs32_goback_to_main(void);

#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
extern void mmi_op11_hs32_enter_wp_mgr_screen(void);
extern void mmi_op11_hs32_enter_wp_select_screen(void);
#endif /* (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__)) */

extern void mmi_op11_hs32_exec_rsk(void);


#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif /* MMI_OP11_HS32_H  */

