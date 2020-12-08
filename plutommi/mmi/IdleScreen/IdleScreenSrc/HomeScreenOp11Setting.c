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
 *    HomeScreenOp11Setting.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "mmi_features.h"

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)

#include "app_datetime.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list_op.h"
#include "common_nvram_editor_data_item.h"
#include "PhoneSetupGprots.h"
//#include "SimDetectionGprot.h"
//#include "IdleAppResDef.h"
#include "WPSSProtos.h"
#include "ShortcutsDefs.h"
#include "ShortcutsGProts.h"
//#include "PhoneBookExtraNumber.h"
#include "ProfilesSrvGprot.h"
#ifdef __MMI_DIALER_SEARCH__
#endif
#include "CallSetSrvGprot.h"  /* SS 10A split */

#include "HomeScreenOp11V32.h"
#include "HomeScreenOp11V32Setting.h"
#include "mmi_rp_app_op11_hs32_def.h"

#include "MenuCUIGprot.h"
#include "DialerGprot.h"
#include "Inlinecuigprot.h"

#include "mmi_phnset_dispchar.h" /* for MAUI_02582994 */

// auto add by kw_check begin
#include "MMIDataType.h"
#include "HomeScreenOp11V32Def.h"
#include "mmi_frm_history_gprot.h"
#include "custom_phb_config.h"
#include "wgui_categories_list.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_public_api.h"
#include "gui.h"
#include "GlobalConstants.h"
#include "mmi_frm_events_gprot.h"
#include "CustMenuRes.h"
#include "GlobalResDef.h"
#include "gui_data_types.h"
#include "wgui_categories_popup.h"
#include "CustDataRes.h"
#include "custom_events_notify.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "gui_typedef.h"
#include "HomeScreenOp11V32Gprot.h"
#include "string.h"
#include "AlertScreen.h"
#include "PhbSrvGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "ps_public_enum.h"
#include "sim_common_enums.h"
#include "wgui_categories_text_viewer.h"
#include "PhbSrvIprot.h"
#include "PhoneSetup.h"
#include "mmi_rp_app_uiframework_def.h"
#include "DebugInitDef_Int.h"
// auto add by kw_check end 

#include "PhoneSetupGprots.h"


/* for inline editor */
#define HS_APP_INLINE_CAPTION		(CUI_INLINE_ITEM_ID_BASE+0)
#define HS_APP_INLINE_EDITOR		(CUI_INLINE_ITEM_ID_BASE+1)

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define  MMI_HS_CPY_ITEM(dst, src) do{int i=0; do{ dst[i]=src[i];}while(src[i++]!=0xFF); }while(0)

const U16 g_hs_sidebar_icon[] = 
{
    IMG_ID_OP11_HS_ML_CLL,     /* Call */
    IMG_ID_OP11_HS_ML_CON,     /* Contacts (PHB)*/
    IMG_ID_OP11_HS_ML_MES,     /* Message */
    IMG_ID_OP11_HS_ML_EML,     /* Email */
    IMG_ID_OP11_HS_ML_OMR,     /* Orange Messenger */
    IMG_ID_OP11_HS_ML_OWD,     /* Orange World (WAP) */
    IMG_ID_OP11_HS_ML_PRO,     /* Profile */
    IMG_ID_OP11_HS_ML_ALM,     /* Alarms */
    IMG_ID_OP11_HS_ML_CAL,     /* Calendar */
    IMG_ID_OP11_HS_ML_MUS,     /* Music */
    IMG_ID_OP11_HS_ML_PHO,     /* Photography */
    IMG_ID_OP11_HS_ML_CNX,     /* Connections (BT, Flight Mode) */
    IMG_ID_OP11_HS_ML_DST,     /* Device Status */
    IMG_ID_OP11_HS_ML_STK,      /* SIM Toolkit */
    IMG_ID_OP11_HS_ML_TPH,      /* US Takephoto */
    IMG_ID_OP11_HS_ML_VIP,     /* US VIP */
    IMG_ID_OP11_HS_ML_CON     /* US contacts */
};

const U16 g_hs_sidebar_str[] = 
{
    STR_ID_OP11_HS_CLL,	/* calls */
    STR_ID_OP11_HS_CON,	/* contacts */
    STR_ID_OP11_HS_MES,	/* Messages */
    STR_ID_OP11_HS_EML,	/* Email */
    STR_ID_OP11_HS_OMR,	/* Orange Message */
    STR_ID_OP11_HS_OWD,	/* Orange World */
    STR_ID_OP11_HS_PRO,	/* Profile */
    STR_ID_OP11_HS_ALM,	/* Alarms */
    STR_ID_OP11_HS_CAL,	/* Calendar */
    STR_ID_OP11_HS_MUS,	/* Music */
    STR_ID_OP11_HS_PHO,	/* Photography */
    STR_ID_OP11_HS_CNX,	/* Connections */
    STR_ID_OP11_HS_DST,	/* Device status */
    STR_ID_OP11_HS_STK,	/* SIM Toolkit */
    STR_ID_OP11_HS32_PHO_TP,	/* US Takephoto */
    STR_ID_OP11_HS_USVIP, 	/* US VIP */
    STR_ID_OP11_HS_CON	/* US contacts */
};


const static U16  mmi_op11_hs_shct_cll_str_list[] = {OP11_HS32_SHCT_STR_LIST_CLL}; 
const static U16  mmi_op11_hs_shct_con_str_list[] = {OP11_HS32_SHCT_STR_LIST_CON}; 
const static U16  mmi_op11_hs_shct_mes_str_list[] = {OP11_HS32_SHCT_STR_LIST_MES}; 
const static U16  mmi_op11_hs_shct_eml_str_list[] = {OP11_HS32_SHCT_STR_LIST_EML}; 
const static U16  mmi_op11_hs_shct_omr_str_list[] = {OP11_HS32_SHCT_STR_LIST_OMR}; 
const static U16  mmi_op11_hs_shct_owd_str_list[] = {OP11_HS32_SHCT_STR_LIST_OWD};
const static U16  mmi_op11_hs_shct_pro_str_list[] = {OP11_HS32_SHCT_STR_LIST_PRO};
const static U16  mmi_op11_hs_shct_alm_str_list[] = {OP11_HS32_SHCT_STR_LIST_ALM};
const static U16  mmi_op11_hs_shct_cal_str_list[] = {OP11_HS32_SHCT_STR_LIST_CAL};
const static U16  mmi_op11_hs_shct_mus_str_list[] = {OP11_HS32_SHCT_STR_LIST_MUS};
const static U16  mmi_op11_hs_shct_pho_str_list[] = {OP11_HS32_SHCT_STR_LIST_PHO};
const static U16  mmi_op11_hs_shct_cnx_str_list[] = {OP11_HS32_SHCT_STR_LIST_CNX};
const static U16  mmi_op11_hs_shct_dst_str_list[] = {OP11_HS32_SHCT_STR_LIST_DST};
const static U16  mmi_op11_hs_shct_stk_str_list[] = {OP11_HS32_SHCT_STR_LIST_STK};
const static U16  mmi_op11_hs_shct_tph_str_list[] = {OP11_HS32_SHCT_STR_LIST_TPH};
const static U16  mmi_op11_hs_shct_vip_str_list[] = {OP11_HS32_SHCT_STR_LIST_VIP};
const static U16  mmi_op11_hs_shct_uscon_str_list[] = {OP11_HS32_SHCT_STR_LIST_USCON};

const U16 * g_mmi_op11_hs_shct_str_list[] = 
{
    mmi_op11_hs_shct_cll_str_list,  /* calls */
    mmi_op11_hs_shct_con_str_list,  /* contacts */
    mmi_op11_hs_shct_mes_str_list,  /* Messages */
    mmi_op11_hs_shct_eml_str_list,  /* Email */
    mmi_op11_hs_shct_omr_str_list,  /* Orange Message */
    mmi_op11_hs_shct_owd_str_list,  /* Orange World */
    mmi_op11_hs_shct_pro_str_list,  /* Profile */
    mmi_op11_hs_shct_alm_str_list,  /* Alarms */
    mmi_op11_hs_shct_cal_str_list,  /* Calendar */
    mmi_op11_hs_shct_mus_str_list,  /* Music */
    mmi_op11_hs_shct_pho_str_list,  /* Photography */
    mmi_op11_hs_shct_cnx_str_list,  /* Connections */
    mmi_op11_hs_shct_dst_str_list,  /* Device status */
    mmi_op11_hs_shct_stk_str_list,   /* SIM Toolkit */
    mmi_op11_hs_shct_tph_str_list,   /* US Takephoto */
    mmi_op11_hs_shct_vip_str_list,  /* US VIP */
    mmi_op11_hs_shct_uscon_str_list   /* US contacts */
};

/* defind locked items which should not be removed */
const static U8  g_hs_locked_sidebar[] = 
{
    MMI_OP11_HS32_AP_CLL,    /* Call */
    MMI_OP11_HS32_AP_CON,    /* Contacts (PHB)*/
    MMI_OP11_HS32_AP_MES,    /* Message */
    0xFF
};       

/* define sidebar items which should be removed. these items must not appear while add sidebar. */
#if defined(__MMI_OP11_HOMESCREEN_US__)
const static U8  g_hs_sidebar_prohibited[] = 
{
    MMI_OP11_HS32_AP_EML,        /* Email  3*/
    MMI_OP11_HS32_AP_OMR,        /* Orange Messenger  4*/
#if !defined(__MMI_OP11_HS32_OWD__)
    MMI_OP11_HS32_AP_OWD,       /* Orange World (WAP)  5*/
#endif
    MMI_OP11_HS32_AP_CAL,         /* Calendar  8*/
#if !defined(__MMI_OP11_HS32_MUS__)
    MMI_OP11_HS32_AP_MUS,        /* Music  9*/
#endif
    MMI_OP11_HS32_AP_PHO,        /* Photography  10*/
    MMI_OP11_HS32_AP_CNX,        /* Connections (BT, Flight Mode)  11*/
    MMI_OP11_HS32_AP_DST,        /* Device Status  12*/
#if !defined(__MMI_OP11_HS32_TPH__)
    MMI_OP11_HS32_AP_TPH,       /* Take Photo 14 */
#endif
    MMI_OP11_HS32_AP_USCON,       /* AP reserved (PHB for example) 16 */
    0xFF
};   
#else /* __MMI_OP11_HOMESCREEN_US__ */
const static U8  g_hs_sidebar_prohibited[] = 
{
#if !defined(__MMI_OP11_HS32_EML__)
    MMI_OP11_HS32_AP_EML,        /* Email  3*/
#endif
#if !defined(__MMI_OP11_HS32_OMR__)
    MMI_OP11_HS32_AP_OMR,        /* Orange Messenger  4*/
#endif
#if !defined(__MMI_OP11_HS32_OWD__)
    MMI_OP11_HS32_AP_OWD,       /* Orange World (WAP)  5*/
#endif
#if !defined(__MMI_OP11_HS32_MUS__)
    MMI_OP11_HS32_AP_MUS,        /* Music  9*/
#endif
#if !defined(__MMI_OP11_HS32_PHO__)
    MMI_OP11_HS32_AP_PHO,        /* Photography  10*/
#endif
    MMI_OP11_HS32_AP_TPH,       /* Take Photo 14 */
    MMI_OP11_HS32_AP_VIP,       /* VIP Contacts 15 */
    MMI_OP11_HS32_AP_USCON,       /* AP reserved (PHB for example) 16 */
    0xFF
};   
#endif /* __MMI_OP11_HOMESCREEN_US__ */

/* the items are supported. if the content is modified, must format flash while download. */
#if defined(__MMI_OP11_HOMESCREEN_US__)
const static U8  g_hs_sidebar_needed[] = 
{
    MMI_OP11_HS32_AP_CLL,         /* Call  0*/
    MMI_OP11_HS32_AP_CON,        /* Contacts (PHB) 1*/
    MMI_OP11_HS32_AP_MES,        /* Message  2*/
    MMI_OP11_HS32_AP_VIP,       /* VIP Contacts 15 */
#if defined(__MMI_OP11_HS32_TPH__)
    MMI_OP11_HS32_AP_TPH,       /* Take Photo 14 */
#endif
#if defined(__MMI_OP11_HS32_MUS__)
    MMI_OP11_HS32_AP_MUS,        /* Music  9*/
#endif
    MMI_OP11_HS32_AP_STK,        /* SIM Toolkit  13*/
    MMI_OP11_HS32_AP_ALM,        /* Alarms  7*/
#if defined(__MMI_OP11_HS32_OWD__)
    MMI_OP11_HS32_AP_OWD,       /* Orange World (WAP)  5*/
#endif
    MMI_OP11_HS32_AP_PRO,        /* Profile  6*/
    0xFF
};

#elif defined(__MMI_MAINLCD_320X240__)
const static U8  g_hs_sidebar_needed[] = 
{
    MMI_OP11_HS32_AP_CLL,         /* Call  0*/
    MMI_OP11_HS32_AP_CON,        /* Contacts (PHB) 1*/
    MMI_OP11_HS32_AP_MES,        /* Message  2*/
#if defined(__MMI_OP11_HS32_OWD__)
    MMI_OP11_HS32_AP_OWD,       /* Orange World (WAP)  5*/
#endif

    MMI_OP11_HS32_AP_CAL,         /* Calendar  8*/
#if defined(__MMI_OP11_HS32_PHO__)
    MMI_OP11_HS32_AP_PHO,        /* Photography  10*/
#endif
    MMI_OP11_HS32_AP_ALM,        /* Alarms  7*/
    MMI_OP11_HS32_AP_DST,        /* Device Status  12*/

    MMI_OP11_HS32_AP_STK,        /* SIM Toolkit  13*/
#if defined(__MMI_OP11_HS32_EML__)
    MMI_OP11_HS32_AP_EML,        /* Email  3*/
#endif
#if defined(__MMI_OP11_HS32_OMR__)
    MMI_OP11_HS32_AP_OMR,        /* Orange Messenger  4*/
#endif
    MMI_OP11_HS32_AP_PRO,        /* Profile  6*/
    MMI_OP11_HS32_AP_CNX,        /* Connections (BT, Flight Mode)  11*/
#if defined(__MMI_OP11_HS32_MUS__)
    MMI_OP11_HS32_AP_MUS,        /* Music  9*/
#endif
    0xFF
};

#else /* ! __MMI_OP11_HOMESCREEN_US__ */
const static U8  g_hs_sidebar_needed[] = 
{
#if defined(__MMI_OP11_HS32_OWD__)
    MMI_OP11_HS32_AP_OWD,       /* Orange World (WAP)  5*/
#endif
    MMI_OP11_HS32_AP_CLL,         /* Call  0*/
    MMI_OP11_HS32_AP_CON,        /* Contacts (PHB) 1*/
    MMI_OP11_HS32_AP_MES,        /* Message  2*/
#if defined(__MMI_OP11_HS32_PHO__)
    MMI_OP11_HS32_AP_PHO,        /* Photography  10*/
#endif
    MMI_OP11_HS32_AP_CAL,         /* Calendar  8*/
    MMI_OP11_HS32_AP_ALM,        /* Alarms  7*/
#if defined(__MMI_OP11_HS32_EML__)
    MMI_OP11_HS32_AP_EML,        /* Email  3*/
#endif
    MMI_OP11_HS32_AP_PRO,        /* Profile  6*/
#if defined(__MMI_OP11_HS32_OMR__)
    MMI_OP11_HS32_AP_OMR,        /* Orange Messenger  4*/
#endif
    MMI_OP11_HS32_AP_DST,        /* Device Status  12*/
    MMI_OP11_HS32_AP_STK,        /* SIM Toolkit  13*/
    MMI_OP11_HS32_AP_CNX,        /* Connections (BT, Flight Mode)  11*/
#if defined(__MMI_OP11_HS32_MUS__)
    MMI_OP11_HS32_AP_MUS,        /* Music  9*/
#endif
    0xFF
};
#endif /* __MMI_OP11_HOMESCREEN_US__ */

#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
const U8  g_mmi_op11_hs32_wp_total_list[] = 
{
    MMI_OP11_HS32_AP_ALM,        /* Alarms  7*/
    MMI_OP11_HS32_AP_CNX,        /* Connections (BT, Flight Mode)  11*/
    MMI_OP11_HS32_AP_DST,        /* Device Status  12*/
    0xFF
};
#endif

enum  hs_action_state_enum {
    ACTION_STATE_INIT,
    ACTION_STATE_SELECT,
    ACTION_STATE_CNF_BACK,
    ACTION_STATE_CAN_BACK
};

enum remove_entry_enum {
    ENTRY_REMOVE_FROM_MENU,
    ENTRY_REMOVE_FROM_OTHER
};

typedef struct mmi_hs_setting_struct
{
    U8      sb_item_hist[MMI_OP11_HS32_SB_HIST_MAX];
    U8      list_gui_buf[MAX_GUI_BUFFER];
    
    U8 *    str_list[MMI_OP11_HS32_AP_TYPE_MAX+1];    /* 1 is for --off screen-- item */
    U16     icon_list1[MMI_OP11_HS32_AP_TYPE_MAX+1];
    U16     icon_list2[MMI_OP11_HS32_AP_TYPE_MAX+1];
    S32     item_count;
    S32     selected_item;

    CHAR *    mst_str_p;      /* used by more setting */
    U8      curr_sidebar;   /* 0xFF means entry from personalise menu, otherwise from options menu */
    U8      curr_shct;  
    U8      act_state;      /* Refer to hs_action_state_enum, used by reorder and remove */
    U8      done_flag;      /* used by reorder and remove */
    U8      remove_entry;   /* refer to remove_entry_enum, used by remove */

    U8      line_id;
    U16     my_num_name[MMI_PHB_NAME_LENGTH+1]; 
    U16     my_num_number[MMI_PHB_NUMBER_LENGTH+1]; 

} mmi_hs_setting_cntx;


/* reorder place common struct */
typedef struct 
{
    S32     seld_idx;
    U8 *    gui_buffer;
    U8      sb_order[MMI_OP11_HS32_SB_HIST_MAX];
    U8      curr_sidebar; /* 0xFF means that it is reordering the shortcut */

    U16         scr_id;
    U16         str_title;
    U16         str_sub_title;
    U16         str_lsk;
    U16         str_rsk;

    FuncPtr     func_lsk;
    FuncPtr     func_rsk;
    wgui_cat1002_op11_draw_menuitem_func  draw_item_func;  

    S32     separate_line;
    S32     curr_idx;
    S32     last_idx;
    S32     item_num;

    U8 *        item_list[MMI_OP11_HS32_AP_TYPE_MAX+1];    /* 1 is for --off screen-- item */
    U16         icon_list[MMI_OP11_HS32_AP_TYPE_MAX+1];
    U16         icon_sta_list[MMI_OP11_HS32_AP_TYPE_MAX+1];
} op11_hs32_reorder_struct;


enum  mmi_more_setting_item_enum{
    MMI_HS_MST_WALLPAPER,
    MMI_HS_MST_TIME_FMT,
#if !defined(__MMI_MAINLCD_128X160__)
    MMI_HS_MST_CLK_SIZE,
#endif
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
    MMI_HS_MST_DUAL_CLK,
#endif
    MMI_HS_MST_DAT_FMT,
    MMI_HS_MST_MY_NUMBER,
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_US__)
    MMI_HS_MST_LEFT_KEY,
    MMI_HS_MST_RIGHT_KEY,
#endif
    /* MMI_HS_MST_RIGHT_SOFTKEY, */
#if defined(__MMI_DIALER_SEARCH__)
    MMI_HS_MST_KEYPAD_SEARCH,
#endif
    MMI_HS_MST_TOTAL
};

const static U16  g_more_setting_str_list[] = 
{
    STR_ID_OP11_HS_WALLPAPER,
    STR_ID_OP11_HS_TIME_FMT,
#if !defined(__MMI_MAINLCD_128X160__)
    STR_ID_OP11_HS_CLK_SIZE,
#endif
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
    STR_ID_OP11_HS_DUAL_CLK,
#endif
    STR_ID_OP11_HS_DAT_FMT,
    STR_ID_OP11_HS_MY_NUMBER,
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_US__)
    STR_ID_OP11_HS_LEFT_KEY,
    STR_ID_OP11_HS_RIGHT_KEY,
#endif /* __MMI_OP11_HOMESCREEN_0301__ */
    /* STR_ID_OP11_HS_RIGHT_SOFTKEY, */
    STR_ID_OP11_HS_KEYPAD_SEARCH
};


const static cui_inline_item_caption_struct  hs_input_caption =
{
    STR_ID_OP11_HS_INPUT_MY_NUMBER
};

static mmi_imm_input_mode_enum  hs_input_mode = IMM_INPUT_MODE_123_SYMBOLS;
static cui_inline_item_text_edit_struct  hs_input_editor = 
{
    0,
	0,
    MMI_PHB_NUMBER_LENGTH+1,
    IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
    0,
    &hs_input_mode
};


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static cui_inline_set_item_struct  hs_inline_editor_items[] = 
{
    {HS_APP_INLINE_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION ,     0, &hs_input_caption},
    {HS_APP_INLINE_EDITOR,    CUI_INLINE_ITEM_TYPE_TEXT_EDIT,    0, &hs_input_editor}
};

static cui_inline_struct  hs_inline_screen = 
{
    2,
    STR_ID_OP11_HS_MY_NUM_DISPLAY, 
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
//    &hs_inline_sofkey,
    NULL,
    hs_inline_editor_items
};


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

static mmi_hs_setting_cntx   g_hs_setting_cntx;
static mmi_hs_setting_cntx * g_setting_cntx_p = &g_hs_setting_cntx;

static op11_hs32_reorder_struct   g_reorder_cntx;
static op11_hs32_reorder_struct * g_rdr_cntx_p = &g_reorder_cntx;

static void mmi_op11_hs_entry_personalise_int(void);

static void mmi_reorder_sidebar_select(void);
static void mmi_reorder_sidebar_select_int(void);
static void mmi_reorder_sidebar_place_pre(void);
static void mmi_reorder_sidebar_place_confirm(void);
static void mmi_reorder_sidebar_place_cancel(void);
static void mmi_reorder_sidebar_done(void);

static void mmi_add_sidebar_items_check(void);
static void mmi_add_sidebar_select_rest_items(void);
static void mmi_add_sidebar_max_item_reached(void);
static void mmi_add_sidebar_place_first(void);
static void mmi_add_sidebar_reorder_select_pre(void);
static void mmi_add_sidebar_reorder_select(void);
static void mmi_add_sidebar_place_later(void);
static void mmi_add_sidebar_done(void);
static void mmi_add_sidebar_place_later_conf(void);
static void mmi_add_sidebar_place_later_cancel(void);

static MMI_BOOL mmi_op11_hs_item_locked(U8 item, const U8 * locked_item);

static void mmi_remove_sidebar_main(void);
static void mmi_remove_sidebar_item_int(void);
static MMI_BOOL mmi_remove_sidebar_item_check(void);
static void mmi_remove_sidebar_confirm(void);
static void mmi_remove_sidebar_conf_yes(void);
static void mmi_remove_sidebar_conf_no(void);
static void mmi_remove_sidebar_done(void);
static MMI_BOOL mmi_remove_sidebar_get_flag_hdlr(S32 index, U32* flag, U32* flag_ex);
static void mmi_remove_sidebar_from_add_item(void);
static S32 mmi_remove_sidebar_get_highlight_index(U8 sidebar);

static void mmi_reorder_shct_main(void);
static void mmi_reorder_shct_int(void);
static void mmi_reorder_shct_place_pre(void);
static void mmi_reorder_shct_place_cnf(void);
static void mmi_reorder_shct_place_cancel(void);
static void mmi_reorder_shct_done(void);

static void mmi_more_setting_main_pre(void);
static void mmi_more_setting_main(void);
static void mmi_more_setting_main_done(void);
static void mmi_more_setting_exit(void);
static void mmi_more_setting_highlight_hdlr(S32 index);
static void mmi_more_setting_clock_size(void);
static void mmi_more_setting_clock_size_done(void);
static void mmi_op11_hs32_set_clock_size(U8 clock_size);

static void mmi_more_setting_is_dual_clock(void);
static void mmi_more_setting_is_dual_clock_done(void);
static void mmi_more_setting_show_my_num(void);
static void mmi_more_setting_show_my_num_done(void);
static void mmi_more_setting_keypad_search(void);
//static void mmi_more_setting_keypad_search_done(void);
static void mmi_more_setting_enter_app(void);
static void mmi_more_setting_help(void);

static void mmi_more_setting_input_my_number_pre(void);
static void mmi_more_setting_get_phb_entry_callback(U16 result, l4c_phb_entry_struct *sim_entry);
static void mmi_more_setting_input_my_number(void);
static void mmi_op11_hs_entry_options_menu_int(void);

static MMI_BOOL mmi_hs_is_owner_number_empty(void);
static MMI_BOOL mmi_hs_is_owner_number_valid(U16 * number);
static void mmi_more_setting_save_my_number(void);
static void mmi_more_setting_set_number_rsp(U16 result);
static void mmi_more_setting_exit_input_my_number(void);
static void mmi_more_setting_input_my_number_custom_func(void);

#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
static void mmi_more_setting_sel_shct_cb(mmi_shct_nav_key_enum nav_key);
#endif

static S32 mmi_sidebar_include_needed_items(void);
static MMI_BOOL mmi_sidebar_is_prohibited_items(const U8 * item_list, U8 item);
#ifdef __MMI_OP11_HOMESCREEN_US__
static void mmi_op11_hs_entry_personalise_us_int(void);
static S32  mmi_edit_sidebar_get_hist_us(void);
static S32  mmi_edit_sidebar_organise_items_us(void);
static void mmi_edit_sidebar_icons(void);
static void mmi_edit_sidebar_icons_int(void);
static void mmi_edit_sidebar_done(void);
static void mmi_edit_sidebar_highlight_hdlr(S32 index);
static void mmi_edit_sidebar_show_icon(void);
static void mmi_edit_sidebar_hide_icon(void);
#endif

void mmi_hs_comm_get_fmt_date_string(const applib_time_struct *time, U8* string);

void mmi_op11_hs_reorder_sidebar_place(void);
void mmi_op11_hs_reorder_shortcut_place(void);

S32 mmi_op11_hs_get_item_list(const U8 * order, 
                              U8 * str_list[],
                              U16  icon_list[],
                              U16  icon_sta_list[],
                              const U8 * disabled);

S32 mmi_op11_hs_get_shct_item_list(U8 sidebar, 
                              const U8 shct_order[],
                              U8 * str_list[],
                              U16  icon_list[],
                              U16  icon_sta_list[]);

/* defined in PhnSetDisplay.c */
U8 PhnsetGetDualClockState(void);
MMI_BOOL mmi_op11_hs_is_show_owner_num(void);
MMI_BOOL mmi_op11_hs_set_show_owner_num(U8 status);
extern MMI_BOOL PhnsetSetDualClockState(U8 status);
//extern void mmi_phnset_entry_wallpaper_main(void);

/* DateAndTime.c */
extern void mmi_entry_phnset_time_format(void); /* add for HS3.1 */


void mmi_op11_hs_us_switch_mynumber(void);

#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
static void mmi_entry_switch_view_mode(void);
static void mmi_op11_hs_attach_wp(void);
static void mmi_op11_hs_detach_wp(void);
#endif

static void mmi_op11_hs_create_lsk_root_gid(void);

static U8 g_hs_setting_clock_size;      /* 0->small; 1->large */
static U8 g_hs_setting_keypad_search;   /* 0 -> keypad search on; 1 -> keypad search off */

extern mmi_op11_hs_context_struct g_mmi_op11_hs32_cntx;
nvram_ef_op11_hs32_hist_struct  g_hs_hist_cntx;

#ifdef __MMI_OP11_HOMESCREEN_US__
static U8  g_hs_sdbr_hist[MMI_OP11_HS32_SB_HIST_MAX];
U8 *       g_hs_sdbr_hist_p = g_hs_sdbr_hist;
#else
U8 *       g_hs_sdbr_hist_p = g_hs_hist_cntx.sdbr_hist;
#endif

static mmi_ret mmi_op11_hs_setting_grp_proc(mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs32_setting_init
 * DESCRIPTION
 *  setting init
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs32_setting_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_OP11_HS32_HIST_LID, 1, &g_hs_hist_cntx, NVRAM_EF_OP11_HS32_HIST_SIZE, &error);
#if !defined(__MMI_MAINLCD_128X160__)
    ReadValue(NVRAM_OP11_HS32_CLOCK_SIZE, &g_hs_setting_clock_size, DS_BYTE, &error);
#endif
    ReadValue(NVRAM_OP11_HS32_HISTORY_CHANGED, &g_mmi_op11_hs32_cntx.history_revised, DS_BYTE, &error);
    ReadValue(NVRAM_OP11_HS32_SHCT_PHB_CHANGED, &g_mmi_op11_hs32_cntx.shct_phb_reordered, DS_BYTE, &error);
    ReadValue(NVRAM_OP11_HS32_SHCT_EML_CHANGED, &g_mmi_op11_hs32_cntx.shct_eml_reordered, DS_BYTE, &error);
#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
    ReadValue(NVRAM_OP11_HS32_VIEW_MODE, &g_mmi_op11_hs32_cntx.view_mode, DS_BYTE, &error);
#endif

    if (g_mmi_op11_hs32_cntx.history_revised == 0) /* power on the phone the first time */
    {
        mmi_sidebar_include_needed_items();
        g_mmi_op11_hs32_cntx.history_revised = 1;
        WriteValue(NVRAM_OP11_HS32_HISTORY_CHANGED, &g_mmi_op11_hs32_cntx.history_revised, DS_BYTE, &error);
        WriteRecord(NVRAM_EF_OP11_HS32_HIST_LID, 1, &g_hs_hist_cntx, NVRAM_EF_OP11_HS32_HIST_SIZE, &error);
    }
#ifdef __MMI_OP11_HOMESCREEN_US__
    else
    {
        mmi_edit_sidebar_get_hist_us();
    }
#endif /* __MMI_OP11_HOMESCREEN_US__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hs_setting_get_clock_size
 * DESCRIPTION
 *  setting init
 * PARAMETERS
 *  U8 : 0 -> small font; 1 -> large font
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_op11_hs32_get_clock_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_hs_setting_clock_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hs_setting_get_clock_size
 * DESCRIPTION
 *  setting init
 * PARAMETERS
 *  U8 : 0 -> small font; 1 -> large font
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_op11_hs32_set_clock_size(U8 clock_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_hs_setting_clock_size = clock_size;
	WriteValue(NVRAM_OP11_HS32_CLOCK_SIZE, &g_hs_setting_clock_size, DS_BYTE, &error);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs32_is_keypad_search
 * DESCRIPTION
 *  setting init
 * PARAMETERS
 *  U8 : 0 -> not support keypad search; 1 -> support keypad search
 * RETURNS
 *  void
 *****************************************************************************/
U8  mmi_op11_hs32_is_keypad_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    ReadValue(NVRAM_IDLE_DIALER_SEARCH_SETTING, &g_hs_setting_keypad_search, DS_BYTE, &error);
#ifdef __MMI_DIALER_SEARCH__
     if (mmi_dialer_search_is_enable())
     {
         return 1;
     }
     else
     {
         return 0;
     }
#endif
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs32_set_done_flag
 * DESCRIPTION
 *  set done flag for more setting, used by other app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs32_set_done_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    if (IsScreenPresent(SCR_ID_OP11_HS_SELECT_HS_ITEM))
    if (mmi_frm_group_is_present(g_mmi_op11_hs32_cntx.lsk_sg_id))
    {
        g_setting_cntx_p->done_flag = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs32_get_shct_index
 * DESCRIPTION
 * get shortcut index according to sidebar and shortcut
 * PARAMETERS
 * sidebar : sidebar id
 * shct    : shortcut id
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_op11_hs32_get_shct_index(U8 sidebar, U8 shct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 *	shct_item_list;
	S32		i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(sidebar<MMI_OP11_HS32_AP_TYPE_MAX);
    shct_item_list = g_hs_hist_cntx.shct_hist[sidebar];

	i = 0;
	while (shct_item_list[i] != 0xff)
	{
		if (shct_item_list[i] == shct)
		{
			return i;
		}
		i++;
	}

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sidebar_include_needed_items
 * DESCRIPTION
 *  remove device status sidebar item, it is not supported on 128X160.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_OP11_HOMESCREEN_US__
static S32 mmi_sidebar_include_needed_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (i < MMI_OP11_HS32_SB_HIST_MAX)
    {
        g_hs_hist_cntx.sdbr_hist[i] = 0x00; /* check-box: off */
        g_hs_sdbr_hist[i]           = 0xff;
        i++;
    }

    i = 0;
    while (g_hs_sidebar_needed[i] != 0xff && i < MMI_HS_MAX_SIDERBAR_ITEMS)
    {
        if (mmi_op11_hs_item_locked(g_hs_sidebar_needed[i], g_hs_locked_sidebar))
        {
            g_hs_hist_cntx.sdbr_hist[i] = 0x02; /* locked */
        }
        else
        {
            g_hs_hist_cntx.sdbr_hist[i] = 0x01; /* check-box: on */
        }

        g_hs_sdbr_hist[i]           = g_hs_sidebar_needed[i];
        i++;
    }

    return i;
}
#else /* __MMI_OP11_HOMESCREEN_US__ */
static S32 mmi_sidebar_include_needed_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    U8 *    sb_hist_p = g_hs_hist_cntx.sdbr_hist;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (i < MMI_OP11_HS32_SB_HIST_MAX)
    {
        sb_hist_p[i] = 0xff;
        i++;
    }

    i = 0;
    while (g_hs_sidebar_needed[i] != 0xff && i < MMI_HS_MAX_SIDERBAR_ITEMS)
    {
        sb_hist_p[i] = g_hs_sidebar_needed[i];
        i++;
    }
    sb_hist_p[i] = 0xff;
    return i;
}
#endif /* __MMI_OP11_HOMESCREEN_US__ */

#ifdef __MMI_OP11_HOMESCREEN_US__
static S32 mmi_edit_sidebar_get_hist_us(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S32     count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (i < MMI_OP11_HS32_SB_HIST_MAX)
    {
        g_hs_sdbr_hist[i] = 0xff;
        i++;
    }

    i = 0;
    count = 0;
    while (g_hs_sidebar_needed[i] != 0xff)
    {
        if (g_hs_hist_cntx.sdbr_hist[i])
        {
            g_hs_sdbr_hist[count] = g_hs_sidebar_needed[i];
            count++;
        }
        i++;
    }
    return count;
}
#endif /* __MMI_OP11_HOMESCREEN_US__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_sidebar_is_prohibited_items
 * DESCRIPTION
 *  to check whether the item is prohibited.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sidebar_is_prohibited_items(const U8 * item_list, U8 item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (item_list[i] != 0xff)
    {
        if (item_list[i] == item)
        {
            return MMI_TRUE;
        }
        i++;
    }
    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_draw_off_screen_item
 * DESCRIPTION
 *  Category 1001_op11 menu item show function by application
 * PARAMETERS
 *  item                   [IN]     private menu item object
 *  common_item_data       [IN]     common menu item object
 *  x                      [IN]     x
 *  y                      [IN]     y
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_reorder_draw_off_screen_item (S32 idx, MMI_BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *   img_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx != HS_MAX_ITEM_DISPLAYED_ON_IDLE)
    {
        return MMI_FALSE;
    }

    img_data = get_image(IMG_ID_OP11_HS_ML_BOTTOMLINE);
    gui_show_image(x1, y1 + 2, img_data);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_entry_personalise
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_entry_personalise(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_setting_cntx_p->curr_sidebar = 0xFF; 

	mmi_op11_hs_create_lsk_root_gid();

#ifdef __MMI_OP11_HOMESCREEN_US__
	mmi_op11_hs_entry_personalise_us_int();
#else
	mmi_op11_hs_entry_personalise_int();
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_entry_personalise_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_op11_hs_entry_personalise_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16     ItemStrList[MAX_SUB_MENUS];
    U16     nItems;
    U8 *    guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_HS_PERSONALISATION, NULL, mmi_op11_hs_entry_personalise_int, NULL);

//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_HS_PERSONALISATION);

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_PERSONALISATION, NULL, mmi_op11_hs_entry_personalise_int, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();


#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
    mmi_frm_unhide_menu_item(MENU_ID_OP11_HS_SWITCH_VIEWS);

    if (mmi_op11_hs_get_wp_count() == 0)
    {
        mmi_frm_unhide_menu_item(MENU_ID_OP11_HS_SET_WP_PANELS);
        mmi_frm_hide_menu_item(MENU_ID_OP11_HS_EDIT_WP_PANELS);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_OP11_HS_SET_WP_PANELS);
        mmi_frm_unhide_menu_item(MENU_ID_OP11_HS_EDIT_WP_PANELS);
    }

#else
    mmi_frm_hide_menu_item(MENU_ID_OP11_HS_SWITCH_VIEWS);  /* For HS3.2 only */
    mmi_frm_hide_menu_item(MENU_ID_OP11_HS_SET_WP_PANELS); /* For HS3.2 only */
    mmi_frm_hide_menu_item(MENU_ID_OP11_HS_EDIT_WP_PANELS); /* For HS3.2 only */
#endif /* (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__)) */

    nItems = GetNumOfChild_Ext(MENU_ID_OP11_HS_PERSONALISATION);
    GetSequenceStringIds_Ext(MENU_ID_OP11_HS_PERSONALISATION, ItemStrList);
    SetParentHandler(MENU_ID_OP11_HS_PERSONALISATION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory1Screen(
        STR_ID_OP11_HS_PERSONALISE_HS,
        0,
        STR_GLOBAL_SELECT,
        0,
        STR_GLOBAL_CLOSE,
        0,
        nItems,
        ItemStrList,
        0,
        guiBuffer);     

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hs_comm_display_confirm
 * DESCRIPTION
 *  Display confirm popup, orange requirement different from our common screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_hs_comm_display_confirm(U16  left_softkey,
                                        U16  left_softkey_icon,
                                        U16  right_softkey,
                                        U16  right_softkey_icon,
                                        UI_string_type message,
                                        U16  message_icon,
                                        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_tone_enum  tone_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*
	mmi_display_popup_confirm(
		(UI_string_type) get_string(STR_GLOBAL_YES),
		(U8*) GetImage(IMG_GLOBAL_YES), 
		(UI_string_type) get_string(STR_GLOBAL_NO),
		(U8*) GetImage(IMG_GLOBAL_NO), 
		(UI_string_type) str,
		MMI_EVENT_QUERY);
*/
    ShowCategory163Screen((UI_string_type)get_string(left_softkey), 
        (U8*)GetImage(left_softkey_icon), 
        (UI_string_type)get_string(right_softkey),
        (U8*)GetImage(right_softkey_icon), 
        message, 
        message_icon, 
        NULL);

    tone_id = mmi_get_event_based_sound(MMI_EVENT_QUERY);
   
    if (tone_id)
    {
//       playRequestedTone(tone_id);
       srv_prof_play_tone((srv_prof_tone_enum)tone_id, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hs_comm_get_fmt_date_string
 * DESCRIPTION
 *  Gef formatted date string according to date format setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hs_comm_get_fmt_date_string(const applib_time_struct *time, U8* string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 day, month, year, day_index;
    CHAR ts[32];
    U8 seperator;

    U8 month_str[12][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    U8 day_str[7][4] = {"Sun", "Mon", "Tus", "Wed", "Thu", "Fri", "Sat"};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    day_index = time->DayIndex;
    day   = time->nDay;
    month = time->nMonth;
    year  = time->nYear;

    if (month > 12 || month < 1)
    {
        month = 1;
    }

    if (day_index > 6)
    {
        day_index = 0;
    }

    switch (PhnsetGetDateSeperatorFormat())
    {
        case 0:
            seperator = '.';
            break;

        case 1:
            seperator = ':';
            break;

        case 2:
            seperator = '/';
            break;

        case 3:
            seperator = '-';
            break;

        default:
            seperator = '.';
            break;
    }

    switch (PhnsetGetDateFormat())  /* Get the current format of date */
    {
        case 0: /* day,month,year */
            sprintf((CHAR*)ts, "%02d%c%02d%c%04d", day, seperator, month, seperator, year);
            mmi_asc_to_ucs2((CHAR*) string, ts);
            break;

        case 1: /* month, day, year */
            sprintf((CHAR*) ts, "%02d%c%02d%c%04d", month, seperator, day, seperator, year);
            mmi_asc_to_ucs2((CHAR*) string, ts);
            break;
                
        case 2: /* year, month, day */
            sprintf((CHAR*) ts, "%04d%c%02d%c%02d", year, seperator, month, seperator, day);
            mmi_asc_to_ucs2((CHAR*) string, ts);
            break;

        case 3:
            sprintf((CHAR*) ts, "%3s %02d %3s", day_str[day_index], day, month_str[month - 1]);
            mmi_asc_to_ucs2((CHAR*) string, ts);
            break;

        default:
            string[0] = 0;
            string[1] = 0;
            break;
    }
}

/****** below code is common part for placing item when reorder ****************/

/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_comm_place_switch_items
 * DESCRIPTION
 *  Category 1002_op11 switch menuitem data between two indexs.
 * PARAMETERS
 *  idx                   [IN]     current index
 *  prev_idx              [IN]     previous highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_comm_place_switch_items(S32 curr_index, S32 last_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *    string;
    U16     icon;
    U8      item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    string = g_rdr_cntx_p->item_list[curr_index];
    g_rdr_cntx_p->item_list[curr_index] = g_rdr_cntx_p->item_list[last_index];
    g_rdr_cntx_p->item_list[last_index] = string;

    icon = g_rdr_cntx_p->icon_list[curr_index];
    g_rdr_cntx_p->icon_list[curr_index] = g_rdr_cntx_p->icon_list[last_index];
    g_rdr_cntx_p->icon_list[last_index] = icon;

    icon = g_rdr_cntx_p->icon_sta_list[curr_index];
    g_rdr_cntx_p->icon_sta_list[curr_index] = g_rdr_cntx_p->icon_sta_list[last_index];
    g_rdr_cntx_p->icon_sta_list[last_index] = icon;

    if (g_rdr_cntx_p->curr_sidebar == 0xFF) /* reorder sidebar */
    {
        curr_index = (curr_index >= HS_MAX_ITEM_DISPLAYED_ON_IDLE) ? (curr_index-1) : curr_index;
        last_index = (last_index >= HS_MAX_ITEM_DISPLAYED_ON_IDLE) ? (last_index-1) : last_index;
    }

    item = g_rdr_cntx_p->sb_order[curr_index];
    g_rdr_cntx_p->sb_order[curr_index] = g_rdr_cntx_p->sb_order[last_index];
    g_rdr_cntx_p->sb_order[last_index] = item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_comm_get_flag_hdlr
 * DESCRIPTION
 *  Set the separator line and disabled item
 * PARAMETERS
 *  index       [IN]    The list item index
 *  flag        [OUT]   UI Menu Item Flag
 *  flag_ex     [OUT]   UI Menu Item Extension Flag
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_reorder_comm_get_flag_hdlr(S32 index, U32* flag, U32* flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == HS_SEPERATE_LINE_INDEX)
    {
        *flag_ex |= UI_MENUITEM_EXT_SHOW_DOWN_SHORT_SEPARATORLINE;
        result = MMI_TRUE;
    }

    if (index == HS_MAX_ITEM_DISPLAYED_ON_IDLE)
    {
        *flag |= UI_MENUITEM_STATE_DISABLED;
        result = MMI_TRUE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_sdbr_place_goto_prev
 * DESCRIPTION
 *  Category 1002_op11 goto previous index by application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_sdbr_place_goto_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_rdr_cntx_p->curr_idx != HS_MAX_ITEM_DISPLAYED_ON_IDLE)
    {
        last_index = (g_rdr_cntx_p->curr_idx + (g_rdr_cntx_p->item_num- 1)) % g_rdr_cntx_p->item_num;
        if(last_index == HS_MAX_ITEM_DISPLAYED_ON_IDLE)
        {
            last_index = (last_index + (g_rdr_cntx_p->item_num- 1)) % g_rdr_cntx_p->item_num;
        }
        mmi_reorder_comm_place_switch_items(g_rdr_cntx_p->curr_idx, last_index);
        wgui_cat1002_op11_goto_list(last_index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_sdbr_place_goto_next
 * DESCRIPTION
 *  Category 1002_op11 goto next index by application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_sdbr_place_goto_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_rdr_cntx_p->curr_idx != HS_MAX_ITEM_DISPLAYED_ON_IDLE)
    {
        last_index = (g_rdr_cntx_p->curr_idx + (g_rdr_cntx_p->item_num + 1)) % g_rdr_cntx_p->item_num;
        if(last_index == HS_MAX_ITEM_DISPLAYED_ON_IDLE)
        {
            last_index = (last_index + (g_rdr_cntx_p->item_num + 1)) % g_rdr_cntx_p->item_num;
        }
        mmi_reorder_comm_place_switch_items(g_rdr_cntx_p->curr_idx, last_index);
        wgui_cat1002_op11_goto_list(last_index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_shct_place_goto_prev
 * DESCRIPTION
 *  Category 1002_op11 goto previous index by application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_shct_place_goto_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    last_index = (g_rdr_cntx_p->curr_idx + (g_rdr_cntx_p->item_num- 1)) % g_rdr_cntx_p->item_num;

    mmi_reorder_comm_place_switch_items(g_rdr_cntx_p->curr_idx, last_index);
    wgui_cat1002_op11_goto_list(last_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_shct_place_goto_next
 * DESCRIPTION
 *  Category 1002_op11 goto next index by application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_shct_place_goto_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    last_index = (g_rdr_cntx_p->curr_idx + (g_rdr_cntx_p->item_num + 1)) % g_rdr_cntx_p->item_num;

    mmi_reorder_comm_place_switch_items(g_rdr_cntx_p->curr_idx, last_index);
    wgui_cat1002_op11_goto_list(last_index);
}


#ifdef __MMI_TOUCH_SCREEN__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_comm_place_touch_hdlr
 * DESCRIPTION
 *  Category 1002_op11 touch list by pen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_comm_place_touch_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rdr_cntx_p->last_idx != g_rdr_cntx_p->curr_idx)
    {
        mmi_reorder_comm_place_switch_items(g_rdr_cntx_p->curr_idx, g_rdr_cntx_p->last_idx);
        wgui_cat1002_op11_touch_refresh_list();
        g_rdr_cntx_p->last_idx = g_rdr_cntx_p->curr_idx;
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_comm_place_highlight_hdlr
 * DESCRIPTION
 *  reorder to place item highlight handler.
 * PARAMETERS
 *  index       [IN]    highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_comm_place_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rdr_cntx_p->last_idx = g_rdr_cntx_p->curr_idx;
    g_rdr_cntx_p->curr_idx = index;

    if (g_rdr_cntx_p->last_idx != g_rdr_cntx_p->curr_idx)
    {
        mmi_reorder_comm_place_switch_items(g_rdr_cntx_p->curr_idx, g_rdr_cntx_p->last_idx);
        wgui_cat1002_op11_refresh_item_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_reorder_sidebar_place
 * DESCRIPTION
 *  to place the selected item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_reorder_sidebar_place(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *    guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_HS_PLACE_HS_ITEM, NULL, mmi_op11_hs_reorder_sidebar_place, NULL);
//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_HS_PLACE_HS_ITEM);

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_PLACE_HS_ITEM, NULL, mmi_op11_hs_reorder_sidebar_place, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    
    if ((g_rdr_cntx_p->gui_buffer != NULL) && (guiBuffer == NULL))
    {
        guiBuffer = g_rdr_cntx_p->gui_buffer;
    }

    g_rdr_cntx_p->item_num = mmi_op11_hs_get_item_list(g_rdr_cntx_p->sb_order, 
                                                        g_rdr_cntx_p->item_list,
                                                        g_rdr_cntx_p->icon_list, 
                                                        g_rdr_cntx_p->icon_sta_list,
                                                        NULL);
//    g_rdr_cntx_p->separate_line = 1;
    RegisterHighlightHandler(mmi_reorder_comm_place_highlight_hdlr);
    wgui_fixed_list_register_get_flags_handler(mmi_reorder_comm_get_flag_hdlr);

    wgui_cat1002_op11_set_order_screen(MMI_TRUE);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    wgui_cat1002_op11_show(
        get_string(g_rdr_cntx_p->str_title),
        get_string(g_rdr_cntx_p->str_sub_title),
        get_string(g_rdr_cntx_p->str_lsk),
        0,
        get_string(g_rdr_cntx_p->str_rsk),
        0,
        g_rdr_cntx_p->item_num,
        g_rdr_cntx_p->item_list,
        g_rdr_cntx_p->icon_list,
        g_rdr_cntx_p->icon_sta_list,
        g_rdr_cntx_p->seld_idx,
        g_rdr_cntx_p->draw_item_func,
        guiBuffer);
/*
    SetKeyHandler(mmi_reorder_sdbr_place_goto_prev, KEY_UP_ARROW,   KEY_EVENT_DOWN);
    SetKeyHandler(mmi_reorder_sdbr_place_goto_prev, KEY_UP_ARROW,   KEY_LONG_PRESS);
    SetKeyHandler(mmi_reorder_sdbr_place_goto_prev, KEY_UP_ARROW,   KEY_REPEAT);

    SetKeyHandler(mmi_reorder_sdbr_place_goto_next, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_reorder_sdbr_place_goto_next, KEY_DOWN_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(mmi_reorder_sdbr_place_goto_next, KEY_DOWN_ARROW, KEY_REPEAT);
*/
    SetLeftSoftkeyFunction(g_rdr_cntx_p->func_lsk, KEY_EVENT_UP);
//    SetKeyHandler(g_rdr_cntx_p->func_lsk, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(g_rdr_cntx_p->func_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(g_rdr_cntx_p->func_rsk, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_reorder_shortcut_place
 * DESCRIPTION
 *  to place the selected item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_reorder_shortcut_place(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *    guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_RRD_SHCT_PLACE, NULL, mmi_op11_hs_reorder_shortcut_place, NULL);
//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_RRD_SHCT_PLACE);

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_RRD_SHCT_PLACE, NULL, mmi_op11_hs_reorder_shortcut_place, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();


    if ((g_rdr_cntx_p->gui_buffer != NULL) && (guiBuffer == NULL))
    {
        guiBuffer = g_rdr_cntx_p->gui_buffer;
    }

    g_rdr_cntx_p->item_num = mmi_op11_hs_get_shct_item_list(g_rdr_cntx_p->curr_sidebar,
                                                        g_rdr_cntx_p->sb_order, 
                                                        g_rdr_cntx_p->item_list,
                                                        g_rdr_cntx_p->icon_list, 
                                                        g_rdr_cntx_p->icon_sta_list);

    RegisterHighlightHandler(mmi_reorder_comm_place_highlight_hdlr);

    wgui_cat1002_op11_set_order_screen(MMI_TRUE);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    wgui_cat1002_op11_show(
        get_string(g_rdr_cntx_p->str_title),
        get_string(g_rdr_cntx_p->str_sub_title),
        get_string(g_rdr_cntx_p->str_lsk),
        0,
        get_string(g_rdr_cntx_p->str_rsk),
        0,
        g_rdr_cntx_p->item_num,
        g_rdr_cntx_p->item_list,
        g_rdr_cntx_p->icon_list,
        g_rdr_cntx_p->icon_sta_list,
        g_rdr_cntx_p->seld_idx,
        g_rdr_cntx_p->draw_item_func,
        guiBuffer);
/*
    SetKeyHandler(mmi_reorder_shct_place_goto_prev, KEY_UP_ARROW,   KEY_EVENT_DOWN);
    SetKeyHandler(mmi_reorder_shct_place_goto_prev, KEY_UP_ARROW,   KEY_LONG_PRESS);
    SetKeyHandler(mmi_reorder_shct_place_goto_prev, KEY_UP_ARROW,   KEY_REPEAT);

    SetKeyHandler(mmi_reorder_shct_place_goto_next, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_reorder_shct_place_goto_next, KEY_DOWN_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(mmi_reorder_shct_place_goto_next, KEY_DOWN_ARROW, KEY_REPEAT);
*/
    SetLeftSoftkeyFunction(g_rdr_cntx_p->func_lsk, KEY_EVENT_UP);
//    SetKeyHandler(g_rdr_cntx_p->func_lsk, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(g_rdr_cntx_p->func_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(g_rdr_cntx_p->func_rsk, KEY_EVENT_UP);
}

/****** below code is common part for placing item when reorder ***************/


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_entry_edit_hs_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_entry_edit_hs_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16     ItemStrList[8];
    U16     ItemIconList[8] = {0, 0, 0, 0}; 
    U16     nItems;
    U8 *    guiBuffer;
    UI_string_type  str_list[8];
    U8              index;
    U16     sub_title;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_HS_EDIT_HS_ITEM, NULL, mmi_op11_hs_entry_edit_hs_item, NULL);

//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_HS_EDIT_HS_ITEM);

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_EDIT_HS_ITEM, NULL, mmi_op11_hs_entry_edit_hs_item, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    nItems = GetNumOfChild_Ext(MENU_ID_OP11_HS_EDIT_HS_ITEM);
    GetSequenceStringIds_Ext(MENU_ID_OP11_HS_EDIT_HS_ITEM, ItemStrList);
    SetParentHandler(MENU_ID_OP11_HS_EDIT_HS_ITEM);

    for (index = 0; index < nItems; index++)
    {
        str_list[index] = get_string(ItemStrList[index]);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

#if defined(__MMI_OP11_HOMESCREEN_US__)
    sub_title = STR_ID_OP11_HS_PERSONALISE_INFO_S;
#else
    sub_title = STR_ID_OP11_HS_PERSONALISE_INFO;
#endif

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    wgui_cat1001_op11_show(
        (UI_string_type)get_string(STR_ID_OP11_HS_EDIT_ITEMS),
        (UI_string_type)get_string(sub_title), 
        get_string(STR_GLOBAL_SELECT),
        0,
        get_string(STR_GLOBAL_BACK),
        0,
        nItems,
        (U8**)str_list,
        ItemIconList,
        NULL,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_hs_item_get_flag_hdlr
 * DESCRIPTION
 *  Set the separator line and disabled item
 * PARAMETERS
 *  index       [IN]    The list item index
 *  flag        [OUT]   UI Menu Item Flag
 *  flag_ex     [OUT]   UI Menu Item Extension Flag
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_reorder_hs_item_get_flag_hdlr(S32 index, U32* flag, U32* flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == HS_SEPERATE_LINE_INDEX)
    {
        *flag_ex |= UI_MENUITEM_EXT_SHOW_DOWN_SHORT_SEPARATORLINE;
        result = MMI_TRUE;
    }

    if (index == HS_MAX_ITEM_DISPLAYED_ON_IDLE)
    {
        *flag |= UI_MENUITEM_STATE_DISABLED;
        result = MMI_TRUE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_hs_item_sel_highlight_hdlr
 * DESCRIPTION
 *  Category 1002_op11 highlight handler.
 * PARAMETERS
 *  index       [IN]    highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_hs_item_sel_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_setting_cntx_p->selected_item = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_get_item_list
 * DESCRIPTION
 *  select an item to reorder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_op11_hs_get_item_list(const U8 * order, 
                              U8 * str_list[],
                              U16  icon_list[],
                              U16  icon_sta_list[],
                              const U8 * disabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     count = 0;
    U8      index = 0;
    U8      item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (order[index] != 0xFF)
    {
        if (count == HS_MAX_ITEM_DISPLAYED_ON_IDLE)
        {
            /* for owner draw */
            str_list[count]      = 0;
            icon_list[count]     = 0;
            icon_sta_list[count] = 0;
        }
        else
        {
            item = order[index];
            ASSERT(item<MMI_OP11_HS32_AP_TYPE_MAX);

            str_list[count] = (U8*) get_string((U16)g_hs_sidebar_str[item]);
            icon_list[count] = g_hs_sidebar_icon[item];

            /* to compute which item need lock mark */
            icon_sta_list[count] = 0;
            if (disabled != NULL)
            {
                S32  i = 0;
                while (disabled[i] != 0xFF)
                {
                    if (item == disabled[i])
                    {
                        icon_sta_list[count] = IMG_ID_OP11_HS_ML_LOCK;
                        break;
                    }
                    i++;
                }
            }

            index++;
        }
        
        count++;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_get_shct_item_list
 * DESCRIPTION
 *  select an item to reorder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_op11_hs_get_shct_item_list(U8 sidebar, 
                              const U8 shct_order[],
                              U8 * str_list[],
                              U16  icon_list[],
                              U16  icon_sta_list[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     index = 0;
    U8      item;
    const U16 * shct_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(sidebar<MMI_OP11_HS32_AP_TYPE_MAX);
    shct_str = g_mmi_op11_hs_shct_str_list[sidebar];

    while (shct_order[index] != 0xFF)
    {
        item = shct_order[index];
        str_list[index]      = (U8*) get_string((U16)shct_str[item]);
        icon_list[index]     = 0;
        icon_sta_list[index] = 0;

        index++;
    }
    return index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_item_locked
 * DESCRIPTION
 *  select an item to reorder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_op11_hs_item_locked(U8 item, const U8 * locked_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (locked_item[i] != 0xFF)
    {
        if (locked_item[i] == item)
        {
            return MMI_TRUE;
        }
        i++;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_get_item_index
 * DESCRIPTION
 *  select an item to reorder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_op11_hs_get_item_index(U8 item, const U8 * item_hist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = 0;
    while (item_hist[index] != 0xff)
    {
        if (item_hist[index] == item)
        {
            return index;
        }
        index ++;
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_get_sidebar_index
 * DESCRIPTION
 *  select an item to reorder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_op11_hs_get_sidebar_index(S32 sidebar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_op11_hs_get_item_index((U8)sidebar_id, g_hs_hist_cntx.sdbr_hist);

}



/********** below part for reorder sidebar **********************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_sidebar_select
 * DESCRIPTION
 *  select an item to reorder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_sidebar_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_setting_cntx_p->act_state = ACTION_STATE_SELECT;
    g_setting_cntx_p->done_flag = 0;

	if (g_setting_cntx_p->curr_sidebar == 0xFF) /* enter from personalise menu */
	{
		g_setting_cntx_p->selected_item = 0;
	}
	else /* entry from options menu, focus defaults to item from which LSK menu wap opened */
	{
		S32  index;
        index = mmi_op11_hs_get_item_index(g_setting_cntx_p->curr_sidebar, g_hs_hist_cntx.sdbr_hist);
        /* 1. from Options enter Edit homescreen items 
           2. add an item, but max items reached.
           3. remove items which is forcused in idle.
           4. reorder it, so can not find the item. */
        /* ASSERT(index!=-1); */
        if (index == -1)
		{
            g_setting_cntx_p->selected_item = 0;
        }
		else if (index >= HS_MAX_ITEM_DISPLAYED_ON_IDLE)
		{
			g_setting_cntx_p->selected_item = index + 1;
		}
		else
		{
			g_setting_cntx_p->selected_item = index;
		}
	}

    mmi_reorder_sidebar_select_int();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_sidebar_select_int
 * DESCRIPTION
 *  select an item to reorder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_sidebar_select_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *    guiBuffer;
    U16     sub_title;
    U16     str_rsk;
    FuncPtr func_rsk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_HS_SELECT_HS_ITEM, NULL, mmi_reorder_sidebar_select_int, NULL);
//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_HS_SELECT_HS_ITEM);

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_SELECT_HS_ITEM, NULL, mmi_reorder_sidebar_select_int, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* sub title */
    if (g_setting_cntx_p->done_flag) 
    {
        sub_title = STR_ID_OP11_HS_CHS_ANOTHER_MOV;
        func_rsk  = mmi_reorder_sidebar_done;
        str_rsk   = STR_GLOBAL_DONE;
    } 
    else 
    {
        sub_title = STR_ID_OP11_HS_CHS_TO_MOV;
        func_rsk  = mmi_frm_scrn_close_active_id;
        str_rsk   = STR_GLOBAL_CANCEL;
    }

    /* check from where to entry */
    if (guiBuffer != NULL)
    {
        if (g_setting_cntx_p->act_state == ACTION_STATE_CNF_BACK) 
        {
            guiBuffer = g_setting_cntx_p->list_gui_buf;
        }
    }
    g_setting_cntx_p->act_state = ACTION_STATE_SELECT;

    g_setting_cntx_p->item_count = mmi_op11_hs_get_item_list(g_hs_hist_cntx.sdbr_hist, 
                                                g_setting_cntx_p->str_list, 
                                                g_setting_cntx_p->icon_list1, 
                                                g_setting_cntx_p->icon_list2,
                                                NULL);

    RegisterHighlightHandler(mmi_reorder_hs_item_sel_highlight_hdlr);
    wgui_fixed_list_register_get_flags_handler(mmi_reorder_hs_item_get_flag_hdlr);
    wgui_cat1002_op11_set_order_screen(MMI_FALSE);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    wgui_cat1002_op11_show(
        get_string(STR_ID_OP11_HS_REORDER_HS_ITEM),
        get_string(sub_title),
        get_string(STR_GLOBAL_SELECT),
        0,
        get_string(str_rsk),
        0,
        g_setting_cntx_p->item_count,
        g_setting_cntx_p->str_list,
        g_setting_cntx_p->icon_list1,
        g_setting_cntx_p->icon_list2,
        g_setting_cntx_p->selected_item,
        mmi_reorder_draw_off_screen_item,
        guiBuffer);

    g_setting_cntx_p->act_state = ACTION_STATE_SELECT;

    SetLeftSoftkeyFunction(mmi_reorder_sidebar_place_pre, KEY_EVENT_UP);
//    SetKeyHandler(mmi_reorder_sidebar_place_pre, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_reorder_sidebar_place_pre, KEY_EVENT_UP);
    SetRightSoftkeyFunction(func_rsk, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_sidebar_done
 * DESCRIPTION
 *  finished reordering and back to homescreen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_sidebar_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*
    DeleteScreenIfPresent(SCR_ID_OP11_HS_PERSONALISATION);
    DeleteScreenIfPresent(SCR_ID_OP11_HS_EDIT_HS_ITEM);
    DeleteScreenIfPresent(SCR_ID_OP11_HS_PLACE_HS_ITEM);

	DeleteScreenIfPresent(SCR_ID_OP11_HS_OPTIONS);

    mmi_frm_scrn_close_active_id();
*/
    mmi_op11_hs32_discard_history();
    mmi_op11_hs32_goback_to_main();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_sidebar_place_confirm
 * DESCRIPTION
 *  place here confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_sidebar_place_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16     error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(g_hs_hist_cntx.sdbr_hist, g_rdr_cntx_p->sb_order, MMI_OP11_HS32_SB_HIST_MAX);

    WriteRecord(NVRAM_EF_OP11_HS32_HIST_LID, 1, &g_hs_hist_cntx, NVRAM_EF_OP11_HS32_HIST_SIZE, &error);

    GetCategoryHistory(g_setting_cntx_p->list_gui_buf);
    g_setting_cntx_p->act_state = ACTION_STATE_CNF_BACK;
    g_setting_cntx_p->done_flag = 1;
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_sidebar_place_cancel
 * DESCRIPTION
 *  place here cancel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_sidebar_place_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_setting_cntx_p->act_state = ACTION_STATE_CAN_BACK;
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_sidebar_place_pre
 * DESCRIPTION
 *  to place the selected item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_sidebar_place_pre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rdr_cntx_p->curr_sidebar = 0xFF; /* to reorder sidebar items */
    g_rdr_cntx_p->seld_idx     = g_setting_cntx_p->selected_item;

    g_rdr_cntx_p->last_idx = g_rdr_cntx_p->seld_idx;
    g_rdr_cntx_p->curr_idx = g_rdr_cntx_p->seld_idx;

    GetCategoryHistory(g_setting_cntx_p->list_gui_buf);
    g_rdr_cntx_p->gui_buffer = g_setting_cntx_p->list_gui_buf;

    memcpy(g_rdr_cntx_p->sb_order, g_hs_hist_cntx.sdbr_hist, MMI_OP11_HS32_SB_HIST_MAX);

    g_rdr_cntx_p->scr_id        = SCR_ID_OP11_HS_PLACE_HS_ITEM;
    g_rdr_cntx_p->str_title     = STR_ID_OP11_HS_REORDER_HS_ITEM;
    g_rdr_cntx_p->str_sub_title = STR_ID_OP11_HS_MOVE_TO_NEW_LOC;
    g_rdr_cntx_p->str_lsk       = STR_ID_OP11_HS_PLACE_HERE;
    g_rdr_cntx_p->str_rsk       = STR_GLOBAL_CANCEL;

    g_rdr_cntx_p->func_lsk      = mmi_reorder_sidebar_place_confirm;
    g_rdr_cntx_p->func_rsk      = mmi_reorder_sidebar_place_cancel;
    g_rdr_cntx_p->draw_item_func= mmi_reorder_draw_off_screen_item;

    mmi_op11_hs_reorder_sidebar_place();
}

/********** above part for reorder sidebar **********************************/
/********** below part for add sidebar **************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_add_sidebar_items_check
 * DESCRIPTION
 *  check if max number of items reached before add sidebar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_add_sidebar_items_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32  num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num = 0;
    while (g_hs_hist_cntx.sdbr_hist[num] != 0xFF)
    {
        num++;
    }

    if (num >= MMI_HS_MAX_SIDERBAR_ITEMS)
    {
        mmi_add_sidebar_max_item_reached();
    }
    else
    {
        mmi_add_sidebar_select_rest_items();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_add_sidebar_select_rest_items
 * DESCRIPTION
 *  to select an item to add
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_add_sidebar_select_rest_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *    guiBuffer;
    U8      index;
    U8      item;
    U8      count;
    U8      is_need;
    mmi_popup_property_struct popup_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_HS_ADD_HS_ITEM_SELECT, NULL, mmi_add_sidebar_select_rest_items, NULL);
//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_HS_ADD_HS_ITEM_SELECT);

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_ADD_HS_ITEM_SELECT, NULL, mmi_add_sidebar_select_rest_items, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* compute remained items */
    count = 0;
    memset(g_setting_cntx_p->sb_item_hist, 0xFF, sizeof(g_setting_cntx_p->sb_item_hist));
    for (item = 0; item < MMI_OP11_HS32_AP_TYPE_MAX; item++)
    {
        /* check whether the item appears in g_hs_hist_cntx.sdbr_hist */
        if (mmi_sidebar_is_prohibited_items(g_hs_sidebar_prohibited, item))
            continue;

        is_need = 1;
        index   = 0;
        while (g_hs_hist_cntx.sdbr_hist[index] != 0xFF)
        {
            if (g_hs_hist_cntx.sdbr_hist[index] == item)
            {
                is_need = 0;
                break;
            }
            index++;
        }
        if (is_need)
        {
            g_setting_cntx_p->sb_item_hist[count++] = item;
        }
    }

    if (count == 0)
    {
        /* need a string id, there is no item to add */
        mmi_popup_property_init(&popup_arg);
        popup_arg.parent_id = g_mmi_op11_hs32_cntx.lsk_sg_id;
        mmi_popup_display((WCHAR*)get_string(STR_ID_OP11_HS_NO_ITEM_TO_ADD), MMI_EVENT_FAILURE, &popup_arg);
        
//        mmi_display_popup((UI_string_type)get_string(STR_ID_OP11_HS_NO_ITEM_TO_ADD), MMI_EVENT_WARNING);
//        DeleteScreenIfPresent(SCR_ID_OP11_HS_ADD_HS_ITEM_SELECT);
        mmi_frm_scrn_close(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_ADD_HS_ITEM_SELECT);  
        return;
    }

    /* prepare string, icon, state icon */
    index = 0;  
    while (g_setting_cntx_p->sb_item_hist[index] != 0xFF)
    {
        item = g_setting_cntx_p->sb_item_hist[index];
        ASSERT(item<MMI_OP11_HS32_AP_TYPE_MAX);

        g_setting_cntx_p->str_list[index]    = (U8*) get_string((U16)g_hs_sidebar_str[item]);
        g_setting_cntx_p->icon_list1[index]  = g_hs_sidebar_icon[item];
        g_setting_cntx_p->icon_list2[index] = 0;
        index++;
    }
    g_setting_cntx_p->item_count = index;

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    RegisterHighlightHandler(mmi_reorder_hs_item_sel_highlight_hdlr);
    wgui_cat1002_op11_set_order_screen(MMI_FALSE);
    wgui_cat1002_op11_show(
        get_string(STR_ID_OP11_HS_ADD_ITEM_TO_HS),
        get_string(STR_ID_OP11_HS_CHS_TO_ADD),
        get_string(STR_GLOBAL_ADD),
        0,
        get_string(STR_GLOBAL_CANCEL),
        0,
        g_setting_cntx_p->item_count,
        g_setting_cntx_p->str_list,
        g_setting_cntx_p->icon_list1,
        g_setting_cntx_p->icon_list2,
        0,
        NULL,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_add_sidebar_place_first, KEY_EVENT_UP);
//    SetKeyHandler(mmi_add_sidebar_place_first, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_add_sidebar_place_first, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_add_sidebar_max_item_reached
 * DESCRIPTION
 *  select another item to reorder again
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_add_sidebar_max_item_reached(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_320X240__)
    U16    str_info = STR_ID_OP11_HS_ADD_LIMIT_INFO8;
#else
    U16    str_info = STR_ID_OP11_HS_ADD_LIMIT_INFO12;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_HS_MAX_ITEMS_REACHED, NULL, NULL, NULL);

//    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_MAX_ITEMS_REACHED, NULL, NULL, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_MAX_ITEMS_REACHED, NULL, mmi_add_sidebar_max_item_reached, MMI_FRM_FG_ONLY_SCRN) == MMI_FALSE)
        return;

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    mmi_hs_comm_display_confirm(STR_ID_OP11_HS_REMOV_ITEM, 
                                0,
                                STR_GLOBAL_CANCEL,
                                0,
                                get_string(str_info),
                                0,
                                NULL);

    SetLeftSoftkeyFunction(mmi_remove_sidebar_from_add_item, KEY_EVENT_UP);
//    SetKeyHandler(mmi_remove_sidebar_from_add_item, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_remove_sidebar_from_add_item, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_add_sidebar_place_first
 * DESCRIPTION
 *  to select an item to add confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_add_sidebar_place_first(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item = g_setting_cntx_p->sb_item_hist[g_setting_cntx_p->selected_item];

    /* enter from personalise menu, add the item at the first place */
	if (g_setting_cntx_p->curr_sidebar == 0xff) 
	{
		memcpy(&g_setting_cntx_p->sb_item_hist[1], g_hs_hist_cntx.sdbr_hist, MMI_OP11_HS32_SB_HIST_MAX-1);
		g_setting_cntx_p->sb_item_hist[0] = item;
		g_rdr_cntx_p->seld_idx     = 0;
	}
	else /* enter from options menu, new item added above item from which LSK menu was opened. */
	{
		S32  index;
		S32  j = 0;
        index = mmi_op11_hs_get_item_index(g_setting_cntx_p->curr_sidebar, g_hs_hist_cntx.sdbr_hist);
        /* 1. from Options enter Edit homescreen items 
           2. add an item, but max items reached.
           3. remove items which is forcused in idle.
           4. add again, so can not find the item. */
		/* ASSERT(index!=-1); */
        if (index == -1)
        {
		    memcpy(&g_setting_cntx_p->sb_item_hist[1], g_hs_hist_cntx.sdbr_hist, MMI_OP11_HS32_SB_HIST_MAX-1);
		    g_setting_cntx_p->sb_item_hist[0] = item;
		    g_rdr_cntx_p->seld_idx     = 0;
        }
        else
        {
		    memset(g_setting_cntx_p->sb_item_hist, 0xff, sizeof(g_setting_cntx_p->sb_item_hist));
		    for (j = 0; j < index; j++)
		    {
			    g_setting_cntx_p->sb_item_hist[j] = g_hs_hist_cntx.sdbr_hist[j];
		    }
		    g_setting_cntx_p->sb_item_hist[index] = item;

		    j = index;
		    while (g_hs_hist_cntx.sdbr_hist[j] != 0xff)
		    {
			    g_setting_cntx_p->sb_item_hist[j+1] = g_hs_hist_cntx.sdbr_hist[j];
			    j++;
		    }
            g_rdr_cntx_p->seld_idx = (index >= HS_MAX_ITEM_DISPLAYED_ON_IDLE) ? (index + 1) : index;
        }		
	}

    g_rdr_cntx_p->last_idx     = g_rdr_cntx_p->seld_idx;
    g_rdr_cntx_p->curr_idx     = g_rdr_cntx_p->seld_idx;

    g_rdr_cntx_p->scr_id       = SCR_ID_OP11_HS_PLACE_HS_ITEM;
    g_rdr_cntx_p->curr_sidebar = 0xFF; /* reorder sidebar */

    g_rdr_cntx_p->gui_buffer   = NULL;

    memcpy(g_rdr_cntx_p->sb_order, g_setting_cntx_p->sb_item_hist, MMI_OP11_HS32_SB_HIST_MAX);

    g_rdr_cntx_p->str_title     = STR_ID_OP11_HS_REORDER_HS_ITEM;
    g_rdr_cntx_p->str_sub_title = STR_ID_OP11_HS_MOVE_TO_NEW_LOC;
    g_rdr_cntx_p->str_lsk       = STR_ID_OP11_HS_PLACE_HERE;
    g_rdr_cntx_p->str_rsk       = STR_GLOBAL_CANCEL;

    g_rdr_cntx_p->func_lsk      = mmi_add_sidebar_reorder_select_pre;
    g_rdr_cntx_p->func_rsk      = mmi_frm_scrn_close_active_id;
    g_rdr_cntx_p->draw_item_func= mmi_reorder_draw_off_screen_item;

    mmi_op11_hs_reorder_sidebar_place();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_add_sidebar_reorder_select_pre
 * DESCRIPTION
 *  to select an item to add confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_add_sidebar_reorder_select_pre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(g_setting_cntx_p->sb_item_hist, g_rdr_cntx_p->sb_order, MMI_OP11_HS32_SB_HIST_MAX);
    GetCategoryHistory(g_setting_cntx_p->list_gui_buf);
    g_setting_cntx_p->act_state = ACTION_STATE_SELECT;
    mmi_add_sidebar_reorder_select();
    /* delete first place screen */
//    DeleteScreenIfPresent(SCR_ID_OP11_HS_PLACE_HS_ITEM); 
    mmi_frm_scrn_close(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_PLACE_HS_ITEM);  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_add_sidebar_reorder_select
 * DESCRIPTION
 *  to select an item to reorder while add items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_add_sidebar_reorder_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *    guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_HS_ADD_HS_ITEM_REORDER, NULL, mmi_add_sidebar_reorder_select, NULL);
//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_HS_ADD_HS_ITEM_REORDER);

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_ADD_HS_ITEM_REORDER, NULL, mmi_add_sidebar_reorder_select, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    if ((guiBuffer == NULL) || (g_setting_cntx_p->act_state == ACTION_STATE_CNF_BACK))
    {
        guiBuffer = g_setting_cntx_p->list_gui_buf;
    }
    g_setting_cntx_p->act_state = ACTION_STATE_SELECT;

    g_setting_cntx_p->item_count = mmi_op11_hs_get_item_list(g_setting_cntx_p->sb_item_hist, 
                                                g_setting_cntx_p->str_list, 
                                                g_setting_cntx_p->icon_list1, 
                                                g_setting_cntx_p->icon_list2,
                                                NULL);

    RegisterHighlightHandler(mmi_reorder_hs_item_sel_highlight_hdlr);
    wgui_fixed_list_register_get_flags_handler(mmi_reorder_hs_item_get_flag_hdlr);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    wgui_cat1002_op11_set_order_screen(MMI_FALSE);
    wgui_cat1002_op11_show(
        get_string(STR_ID_OP11_HS_REORDER_HS_ITEM),
        get_string(STR_ID_OP11_HS_CHS_ANOTHER_MOV),
        get_string(STR_GLOBAL_SELECT),
        0,
        get_string(STR_GLOBAL_DONE),
        0,
        g_setting_cntx_p->item_count,
        g_setting_cntx_p->str_list,
        g_setting_cntx_p->icon_list1,
        g_setting_cntx_p->icon_list2,
        0,
        mmi_reorder_draw_off_screen_item,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_add_sidebar_place_later, KEY_EVENT_UP);
//    SetKeyHandler(mmi_add_sidebar_place_later, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_add_sidebar_place_later, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_add_sidebar_done, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_add_sidebar_place_later
 * DESCRIPTION
 *  select another item to reorder again
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_add_sidebar_place_later(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rdr_cntx_p->seld_idx   = g_setting_cntx_p->selected_item;
    g_rdr_cntx_p->last_idx   = g_rdr_cntx_p->seld_idx;
    g_rdr_cntx_p->curr_idx   = g_rdr_cntx_p->seld_idx;

    GetCategoryHistory(g_setting_cntx_p->list_gui_buf);
    g_rdr_cntx_p->gui_buffer = g_setting_cntx_p->list_gui_buf;

    memcpy(g_rdr_cntx_p->sb_order, g_setting_cntx_p->sb_item_hist, MMI_OP11_HS32_SB_HIST_MAX);

    g_rdr_cntx_p->scr_id        = SCR_ID_OP11_HS_PLACE_HS_AGAIN;
    g_rdr_cntx_p->str_title     = STR_ID_OP11_HS_REORDER_HS_ITEM;
    g_rdr_cntx_p->str_sub_title = STR_ID_OP11_HS_MOVE_TO_NEW_LOC;
    g_rdr_cntx_p->str_lsk       = STR_ID_OP11_HS_PLACE_HERE;
    g_rdr_cntx_p->str_rsk       = STR_GLOBAL_CANCEL;

    g_rdr_cntx_p->func_lsk      = mmi_add_sidebar_place_later_conf;
    g_rdr_cntx_p->func_rsk      = mmi_add_sidebar_place_later_cancel;
    g_rdr_cntx_p->draw_item_func= mmi_reorder_draw_off_screen_item;

    mmi_op11_hs_reorder_sidebar_place();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_add_sidebar_place_later_conf
 * DESCRIPTION
 *  reorder items after add an item, to place the item to proper position.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_add_sidebar_place_later_conf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(g_setting_cntx_p->sb_item_hist, g_rdr_cntx_p->sb_order, MMI_OP11_HS32_SB_HIST_MAX);
    GetCategoryHistory(g_setting_cntx_p->list_gui_buf);
    g_setting_cntx_p->act_state = ACTION_STATE_CNF_BACK;

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_add_sidebar_place_later_cancel
 * DESCRIPTION
 *  reorder items after add an item, to place the item to proper position.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_add_sidebar_place_later_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    DeleteScreenIfPresent(SCR_ID_OP11_HS_ADD_HS_ITEM_REORDER);

    g_setting_cntx_p->act_state = ACTION_STATE_CAN_BACK;
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_add_sidebar_done
 * DESCRIPTION
 *  select item to reorder while add item to homescreen, go to idle 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_add_sidebar_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16     error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(g_hs_hist_cntx.sdbr_hist, g_setting_cntx_p->sb_item_hist, MMI_OP11_HS32_SB_HIST_MAX);

    WriteRecord(NVRAM_EF_OP11_HS32_HIST_LID, 1, &g_hs_hist_cntx, NVRAM_EF_OP11_HS32_HIST_SIZE, &error);
/*
    DeleteScreenIfPresent(SCR_ID_OP11_HS_PERSONALISATION);
	DeleteScreenIfPresent(SCR_ID_OP11_HS_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_OP11_HS_EDIT_HS_ITEM);
    DeleteScreenIfPresent(SCR_ID_OP11_HS_ADD_HS_ITEM_SELECT);
    DeleteScreenIfPresent(SCR_ID_OP11_HS_PLACE_HS_ITEM);

    mmi_frm_scrn_close_active_id();
*/
    mmi_op11_hs32_discard_history();
    mmi_op11_hs32_goback_to_main();
}



/****** above part for add sidebar **************************************************/
/****** below part for remove sidebar ***********************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_remove_sidebar_main
 * DESCRIPTION
 *  pre-entry remove sidebar items 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_remove_sidebar_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32  index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_setting_cntx_p->selected_item = 0;
    g_setting_cntx_p->done_flag     = 0;
    g_setting_cntx_p->remove_entry  = ENTRY_REMOVE_FROM_MENU;

    /* enter from options menu */
    if (g_setting_cntx_p->curr_sidebar != 0xff)
    {
        index = mmi_remove_sidebar_get_highlight_index(g_setting_cntx_p->curr_sidebar);
        if (index != -1)
        {
            g_setting_cntx_p->selected_item = index >= HS_MAX_ITEM_DISPLAYED_ON_IDLE ? index + 1 : index;
        }
        else
        {
            g_setting_cntx_p->selected_item = 0;
        }
    }
    else /* enter from personalise menu */
    {
        g_setting_cntx_p->selected_item = 0;
    }

    mmi_remove_sidebar_item_int();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_remove_sidebar_get_highlight_index
 * DESCRIPTION
 * get sidebar item index which can be highlighted
 * focus defaults to item from which LSK menu was opened - or to item above 
 * if from calls, contacts of messages items.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_remove_sidebar_get_highlight_index(U8 sidebar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32       index, i;
    MMI_BOOL  locked;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* compute highlight item */
    index = mmi_op11_hs_get_item_index(sidebar, g_hs_hist_cntx.sdbr_hist);
    if (index == -1)
    {
        /* occured in the scenario: 
            1. entry from option menu 
            2. entry edit homescreen items
            3. entry remove items, and remove all items which can be removed
            4. back to edit homescreen items.
            5. entry remove items
        */
        return -1; 
    }

    locked = mmi_op11_hs_item_locked(sidebar, g_hs_locked_sidebar);
    if (!locked)
    {
        return index;
    }
    else
    {
        if (index == 0)
        {
            i = 0;
            while (g_hs_hist_cntx.sdbr_hist[i] != 0xFF)
            {
                if (!mmi_op11_hs_item_locked(g_hs_hist_cntx.sdbr_hist[i], g_hs_locked_sidebar))
                {
                    return i;
                }
                i++;
            }
        }
        else
        {
            i = index - 1;
            while ((i >= 0) && (g_hs_hist_cntx.sdbr_hist[i] != 0xFF))
            {
                if (!mmi_op11_hs_item_locked(g_hs_hist_cntx.sdbr_hist[i], g_hs_locked_sidebar))
                {
                    return i;
                }
                i--;                
            }
            if (i == -1)
            {
                i = 0;
                while (g_hs_hist_cntx.sdbr_hist[i] != 0xFF)
                {
                    if (!mmi_op11_hs_item_locked(g_hs_hist_cntx.sdbr_hist[i], g_hs_locked_sidebar))
                    {
                        return i;
                    }
                    i++;
                }
            }
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_remove_sidebar_item_check
 * DESCRIPTION
 *  pre-entry remove sidebar items 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : MMI_TRUE -> there is item to remove; MMI_FALSE -> no item to remove 
 *****************************************************************************/
static MMI_BOOL mmi_remove_sidebar_item_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32			i, j;
	MMI_BOOL	result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	i = 0;
	while (g_hs_hist_cntx.sdbr_hist[i] != 0xFF)
	{
		j = 0;
		result = MMI_TRUE;
		while (g_hs_locked_sidebar[j] != 0xFF)
		{
			if (g_hs_hist_cntx.sdbr_hist[i] == g_hs_locked_sidebar[j])
			{
				result = MMI_FALSE;
				break;
			}
			j++;
		}
		if (result)
		{
			return MMI_TRUE;
		}
		i++;
	}
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_remove_sidebar_from_add_item
 * DESCRIPTION
 *  pre-entry remove sidebar items 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_remove_sidebar_from_add_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_setting_cntx_p->selected_item = 0;
    g_setting_cntx_p->done_flag     = 0;
    g_setting_cntx_p->remove_entry  = ENTRY_REMOVE_FROM_OTHER;

    mmi_remove_sidebar_item_int();

	//DeleteScreenIfPresent(SCR_ID_OP11_HS_MAX_ITEMS_REACHED);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_remove_sidebar_item_int
 * DESCRIPTION
 *  entry remove sidebar items 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_remove_sidebar_item_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *        guiBuffer;
    FuncPtr     func_rsk;
    U16         str_rsk;
    mmi_popup_property_struct popup_arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_HS_REMOVE_HS_ITEM, NULL, mmi_remove_sidebar_item_int, NULL);
//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_HS_REMOVE_HS_ITEM);

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_REMOVE_HS_ITEM, NULL, mmi_remove_sidebar_item_int, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

	/* to check whether there are items can be removed. */
	if (!mmi_remove_sidebar_item_check())
	{
            mmi_popup_property_init(&popup_arg);
            popup_arg.parent_id = g_mmi_op11_hs32_cntx.lsk_sg_id;
            mmi_popup_display((WCHAR*)get_string(STR_ID_OP11_HS_NO_ITEM_TO_REMOVE), MMI_EVENT_FAILURE, &popup_arg);

//		mmi_display_popup((UI_string_type)get_string(STR_ID_OP11_HS_NO_ITEM_TO_REMOVE), MMI_EVENT_WARNING);
//		DeleteScreenIfPresent(SCR_ID_OP11_HS_REMOVE_HS_ITEM);
              mmi_frm_scrn_close(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_REMOVE_HS_ITEM);  
		return;
	}

    if (g_setting_cntx_p->done_flag == 1) 
    {
        guiBuffer = NULL;
        str_rsk   = STR_GLOBAL_DONE;
        func_rsk  = mmi_remove_sidebar_done;
    }
    else
    {
        str_rsk   = STR_GLOBAL_CANCEL;
        func_rsk  = mmi_frm_scrn_close_active_id;
    }

    g_setting_cntx_p->item_count = mmi_op11_hs_get_item_list(g_hs_hist_cntx.sdbr_hist, 
                                                g_setting_cntx_p->str_list, 
                                                g_setting_cntx_p->icon_list1, 
                                                g_setting_cntx_p->icon_list2,
                                                g_hs_locked_sidebar);

    RegisterHighlightHandler(mmi_reorder_hs_item_sel_highlight_hdlr);
    wgui_fixed_list_register_get_flags_handler(mmi_remove_sidebar_get_flag_hdlr);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    wgui_cat1002_op11_set_order_screen(MMI_FALSE);
    wgui_cat1002_op11_show(
        get_string(STR_ID_OP11_HS_REMOVE_HS_ITEMS),
        get_string(STR_ID_OP11_HS_CHS_TO_REMOVE),
        get_string(STR_ID_OP11_HS_REMOVE),
        0,
        get_string(str_rsk),
        0,
        g_setting_cntx_p->item_count,
        g_setting_cntx_p->str_list,
        g_setting_cntx_p->icon_list1,
        g_setting_cntx_p->icon_list2,
        g_setting_cntx_p->selected_item,
        mmi_reorder_draw_off_screen_item,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_remove_sidebar_confirm, KEY_EVENT_UP);
//    SetKeyHandler(mmi_remove_sidebar_confirm, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_remove_sidebar_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(func_rsk, KEY_EVENT_UP);  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_remove_sidebar_get_flag_hdlr
 * DESCRIPTION
 *  list flag handler for remove sidebar item 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_remove_sidebar_get_flag_hdlr(S32 index, U32* flag, U32* flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  result = MMI_FALSE;
    S32       i, item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == HS_SEPERATE_LINE_INDEX)
    {
        *flag_ex |= UI_MENUITEM_EXT_SHOW_DOWN_SHORT_SEPARATORLINE;
        result = MMI_TRUE;
    }

    if (index == HS_MAX_ITEM_DISPLAYED_ON_IDLE)
    {
        *flag |= UI_MENUITEM_STATE_DISABLED;
        result = MMI_TRUE;
    }

    index = (index >= HS_MAX_ITEM_DISPLAYED_ON_IDLE) ? (index-1) : index;
    item  = g_hs_hist_cntx.sdbr_hist[index];

    i = 0;
    while (g_hs_locked_sidebar[i] != 0xFF)
    {
        if (item == g_hs_locked_sidebar[i])
        {
            *flag |= UI_MENUITEM_STATE_DISABLED;
            result = MMI_TRUE;
            break; 
        }
        i++;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_remove_sidebar_done
 * DESCRIPTION
 *  finish removing sidebar items, and back to home screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_remove_sidebar_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_setting_cntx_p->remove_entry == ENTRY_REMOVE_FROM_MENU)
    {
/*
        DeleteScreenIfPresent(SCR_ID_OP11_HS_PERSONALISATION);
		DeleteScreenIfPresent(SCR_ID_OP11_HS_OPTIONS);
        DeleteScreenIfPresent(SCR_ID_OP11_HS_EDIT_HS_ITEM);
*/
        mmi_op11_hs32_discard_history();
        mmi_op11_hs32_goback_to_main();
    }
    else if (g_setting_cntx_p->remove_entry == ENTRY_REMOVE_FROM_OTHER)
    {
//        DeleteScreenIfPresent(SCR_ID_OP11_HS_MAX_ITEMS_REACHED);
        mmi_frm_scrn_close(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_MAX_ITEMS_REACHED); 
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_remove_sidebar_confirm
 * DESCRIPTION
 *  confirm with user whether to remove it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_remove_sidebar_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16     str[64];
    S32     index;
    U8      item;
    U16     item_str;
    U16     item_img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_HS_REMOVE_HS_ITEM_CONF, NULL, NULL, NULL);

//    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_REMOVE_HS_ITEM_CONF, NULL, NULL, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_REMOVE_HS_ITEM_CONF, NULL, mmi_remove_sidebar_confirm, MMI_FRM_FG_ONLY_SCRN) == MMI_FALSE)
        return;

    index = (g_setting_cntx_p->selected_item >= HS_MAX_ITEM_DISPLAYED_ON_IDLE) ? (g_setting_cntx_p->selected_item-1) : g_setting_cntx_p->selected_item;
    item  = g_hs_hist_cntx.sdbr_hist[index];
    item_str = g_hs_sidebar_str[item];
    item_img = g_hs_sidebar_icon[item];

    mmi_ucs2cpy((CHAR*)str, (CHAR*)get_string(STR_ID_OP11_HS_REMOVE));
    mmi_ucs2cat((CHAR*)str, (CHAR*)L" ");
    mmi_ucs2cat((CHAR*)str, (CHAR*)get_string(item_str));
    mmi_ucs2cat((CHAR*)str, (CHAR*)L" ");
    mmi_ucs2cat((CHAR*)str, (CHAR*)get_string(STR_ID_OP11_HS_FROM_YOUR_HS));

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    mmi_hs_comm_display_confirm(STR_GLOBAL_YES,
                                IMG_GLOBAL_YES,
                                STR_GLOBAL_NO,
                                IMG_GLOBAL_NO,
                                str,
                                item_img,
                                NULL);

    SetLeftSoftkeyFunction(mmi_remove_sidebar_conf_yes, KEY_EVENT_UP);
//    SetKeyHandler(mmi_remove_sidebar_conf_yes, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_remove_sidebar_conf_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_remove_sidebar_conf_no, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_remove_sidebar_conf_yes
 * DESCRIPTION
 *  yes handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_remove_sidebar_conf_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     index;
    S32     i;
    S16     error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = g_setting_cntx_p->selected_item;
    index = (index >= HS_MAX_ITEM_DISPLAYED_ON_IDLE) ? (index-1) : index;

    for ( i = index; i < MMI_OP11_HS32_SB_HIST_MAX - 1; i++)
    {
        g_hs_hist_cntx.sdbr_hist[i] = g_hs_hist_cntx.sdbr_hist[i+1];
    }
    g_setting_cntx_p->done_flag = 1;

    WriteRecord(NVRAM_EF_OP11_HS32_HIST_LID, 1, &g_hs_hist_cntx, NVRAM_EF_OP11_HS32_HIST_SIZE, &error);

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_remove_sidebar_conf_no
 * DESCRIPTION
 *  no handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_remove_sidebar_conf_no(void)
{

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    if (g_setting_cntx_p->act_state == ACTION_STATE_INIT)
//    {
//        g_setting_cntx_p->act_state = ACTION_STATE_CAN_BACK;
//    }
    mmi_frm_scrn_close_active_id();
}

/**^^^ above part for remove sidebar ^^^********************************************/
/**VVV below part for more setting  VVV*********************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_main_pre
 * DESCRIPTION
 *  no handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_main_pre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct popup_arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_setting_cntx_p->done_flag = 0;

    if (!srv_phb_startup_is_phb_ready())
    {
        mmi_popup_property_init(&popup_arg);
        popup_arg.parent_id = g_mmi_op11_hs32_cntx.lsk_sg_id;
        mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_BUSY_TRY_LATER), MMI_EVENT_FAILURE, &popup_arg);
//        mmi_display_popup((UI_string_type)get_string(STR_GLOBAL_BUSY_TRY_LATER), MMI_EVENT_INFO);
        return;
    }

	mmi_more_setting_main();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_main
 * DESCRIPTION
 *  no handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32			nItems = MMI_HS_MST_TOTAL;
    U8 *		guiBuffer;
    CHAR *	wallpapername;
    U8 **		string_list;
    U8 *		str_p;
    S32			i;
    applib_time_struct curr_date;
    S16			date_str[32];
    S16			colon_str[] = {':', ' ', 0};
	MMI_BOOL	show_flag;	
	U16			str_rsk;
	FuncPtr		func_rsk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_HS_MORE_SETTING, mmi_more_setting_exit, mmi_more_setting_main, NULL);
//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_HS_MORE_SETTING);

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_MORE_SETTING, mmi_more_setting_exit, mmi_more_setting_main, MMI_FRM_FULL_SCRN) == FALSE)
        return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();


    RegisterHighlightHandler(mmi_more_setting_highlight_hdlr);
    
    /* assume that max characters of each item less than 63. */
    g_setting_cntx_p->mst_str_p = (CHAR *)OslMalloc(sizeof(U8*) * nItems + nItems * 64 * 2);
    ASSERT(g_setting_cntx_p->mst_str_p!=NULL);

    string_list = (U8**)g_setting_cntx_p->mst_str_p;
    for (i = 0; i < nItems; i++)
    {
        /* wallpaper will display short name while the filename is too long. */
		string_list[i] = ((U8*)string_list) + sizeof(U8*) * nItems + i * 64 * 2;
        mmi_ucs2cpy((CHAR*)string_list[i], (CHAR*)get_string(g_more_setting_str_list[i]));
        mmi_ucs2cat((CHAR*)string_list[i], (CHAR*)colon_str);
    }

    /* wallpaper */
    wallpapername = (CHAR*)PhnsetGetCurWallpaperName();
    mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_WALLPAPER], wallpapername);

    /* Time format */
    if (PhnsetGetTimeFormat() == 1)		/* 24 hour */
    {		
		mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_TIME_FMT], (CHAR*)get_string(STR_ID_OP11_HS_TIME_FMT_24H));
    }
    else		/* 12 hour */
    {		
		mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_TIME_FMT], (CHAR*)get_string(STR_ID_OP11_HS_TIME_FMT_12H));
    }

    /* clock size */
#if !defined(__MMI_MAINLCD_128X160__)
    if (g_hs_setting_clock_size == 1)
    {
        mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_CLK_SIZE], (CHAR *)get_string(STR_ID_OP11_HS_LARGE));
    }
    else
    {
        mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_CLK_SIZE], (CHAR *)get_string(STR_ID_OP11_HS_SMALL));
    }
#endif

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
    /* dual clock PhnsetGetDualClockState() HighlightPhnsetDualClockIdleScreen */
    if (PhnsetGetDualClockState() == 1)
    {
        mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_DUAL_CLK], (CHAR *)get_string(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_DUAL_CLK], (CHAR *)get_string(STR_GLOBAL_OFF));
    }
#endif /* defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) */
    /* date format */
    applib_dt_get_date_time(&curr_date);
    mmi_hs_comm_get_fmt_date_string(&curr_date, (U8*)date_str);
    mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_DAT_FMT], (CHAR *)date_str);

    /* my number mmi_op11_hs_is_show_owner_num */
    if (!srv_phb_startup_is_phb_support(SIM1, PHB_MSISDN))
    {
        mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_MY_NUMBER], (CHAR *)get_string(STR_GLOBAL_NOT_SUPPORTED));
    }
    else
    {
	    show_flag = mmi_op11_hs_is_show_owner_num() && !mmi_hs_is_owner_number_empty();
        if (show_flag)
        {
            mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_MY_NUMBER], (CHAR *)get_string(STR_ID_OP11_HS_SHOW));
        }
        else
        {
            mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_MY_NUMBER], (CHAR *)get_string(STR_ID_OP11_HS_HIDE));
        }
    }
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_US__)
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
    /* left key */
    str_p = (U8*)mmi_shct_get_nav_key_str(DEDICATED_KEY_LEFT);
    mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_LEFT_KEY], (CHAR *)str_p);

    /* right key */
    str_p = (U8*)mmi_shct_get_nav_key_str(DEDICATED_KEY_RIGHT);
    mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_RIGHT_KEY], (CHAR *)str_p);
#endif
#endif
    /* right soft key */
//    mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_RIGHT_SOFTKEY], (CHAR *)get_string(STR_ID_OP11_HS_MENU));

    /* keypad search */
#if defined(__MMI_DIALER_SEARCH__)
//    if (mmi_bootup_get_active_flight_mode())
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        nItems--; /* because keypad search is the last item*/
    }
    else
    {
        g_hs_setting_keypad_search = mmi_op11_hs32_is_keypad_search();
        if (g_hs_setting_keypad_search)
        {
            mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_KEYPAD_SEARCH], (CHAR *)get_string(STR_GLOBAL_ON));
        }
        else
        {
            mmi_ucs2cat((CHAR*)string_list[MMI_HS_MST_KEYPAD_SEARCH], (CHAR *)get_string(STR_GLOBAL_OFF));
        }
    }
#endif

	if (guiBuffer != NULL && g_setting_cntx_p->done_flag == 1)
	{
		str_rsk  = STR_GLOBAL_DONE;
		func_rsk = mmi_more_setting_main_done;
	} 
	else
	{
		str_rsk  = STR_GLOBAL_CANCEL;
		func_rsk = mmi_frm_scrn_close_active_id;
	}

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    ShowCategory6Screen(
        STR_ID_OP11_HS_MORE_HS_SETTING,
        0,
        STR_GLOBAL_EDIT,
        0,
        str_rsk,
        0,
        nItems,
        string_list,
        NULL,
        0,
        guiBuffer);     

    SetLeftSoftkeyFunction(mmi_more_setting_enter_app, KEY_EVENT_UP);
//    SetKeyHandler(mmi_more_setting_enter_app, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_more_setting_enter_app, KEY_EVENT_UP);
    SetRightSoftkeyFunction(func_rsk, KEY_EVENT_UP);
}


static void mmi_more_setting_main_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*
	DeleteScreenIfPresent(SCR_ID_OP11_HS_PERSONALISATION);
	DeleteScreenIfPresent(SCR_ID_OP11_HS_OPTIONS);
	mmi_frm_scrn_close_active_id();
*/
    mmi_op11_hs32_discard_history();
    mmi_op11_hs32_goback_to_main();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_exit
 * DESCRIPTION
 *  no handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_setting_cntx_p->mst_str_p != NULL)
    {
        OslMfree(g_setting_cntx_p->mst_str_p);
        g_setting_cntx_p->mst_str_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_highlight_hdlr
 * DESCRIPTION
 *  no handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_setting_cntx_p->selected_item = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_enter_app
 * DESCRIPTION
 *  no handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_enter_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct popup_arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_setting_cntx_p->selected_item)
    {
    case MMI_HS_MST_WALLPAPER:
        mmi_phnset_wallpaper_entry_system(g_mmi_op11_hs32_cntx.lsk_sg_id);
//        mmi_phnset_entry_wallpaper_main();
//        EntryPhnsetWallpaperSys(g_mmi_op11_hs32_cntx.lsk_sg_id);
        break;

    case MMI_HS_MST_TIME_FMT:
        mmi_entry_phnset_time_format();
        break;

#if !defined(__MMI_MAINLCD_128X160__)
    case MMI_HS_MST_CLK_SIZE:
        mmi_more_setting_clock_size();
        break;
#endif

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
    case MMI_HS_MST_DUAL_CLK:
        mmi_more_setting_is_dual_clock();
        break;
#endif /* defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) */

    case MMI_HS_MST_DAT_FMT:
        mmi_entry_phnset_time_format();
        break;

    case MMI_HS_MST_MY_NUMBER:
        {
            if (!srv_phb_startup_is_phb_support(SIM1, PHB_MSISDN))
            {
                mmi_popup_property_init(&popup_arg);
                popup_arg.parent_id = g_mmi_op11_hs32_cntx.lsk_sg_id;
                mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_NOT_SUPPORTED), MMI_EVENT_FAILURE, &popup_arg);
//                 mmi_display_popup((UI_string_type)get_string(STR_GLOBAL_NOT_SUPPORTED), MMI_EVENT_INFO);
                 return;
            }
			/* void mmi_phb_owner_number_pre_req(void) PhoneBookExtraNumber.c */			
			if (mmi_hs_is_owner_number_empty())
			{
				mmi_op11_hs_set_show_owner_num(1);
				mmi_more_setting_input_my_number_pre();
			}
			else 
			{
                MMI_BOOL  show;
                show = mmi_op11_hs_is_show_owner_num();
                show = !show;
                mmi_op11_hs_set_show_owner_num((U8)show);
            #if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
                mmi_op11_hs32_force_sidebar_view();
            #endif
                mmi_op11_hs32_discard_history();
                mmi_op11_hs32_goback_to_main();
			}			
			/* mmi_more_setting_show_my_num();*/
        }
        break;

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_US__)
    case MMI_HS_MST_LEFT_KEY:
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
        mmi_shct_interface_sel_nav_key_shct(DEDICATED_KEY_LEFT, mmi_more_setting_sel_shct_cb);
#endif
        break;
#endif /* __MMI_OP11_HOMESCREEN_0301__ */

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_US__)
    case MMI_HS_MST_RIGHT_KEY:
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
        mmi_shct_interface_sel_nav_key_shct(DEDICATED_KEY_RIGHT, mmi_more_setting_sel_shct_cb);
#endif
        break;
#endif /* __MMI_OP11_HOMESCREEN_0301__ */
/*
    case MMI_HS_MST_RIGHT_SOFTKEY:
        break;
*/
#if defined(__MMI_DIALER_SEARCH__)
    case MMI_HS_MST_KEYPAD_SEARCH:
        mmi_more_setting_keypad_search();
        break;
#endif

    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_clock_size
 * DESCRIPTION
 *  no handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_clock_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID  menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_id = cui_menu_create(g_mmi_op11_hs32_cntx.lsk_sg_id,
                                  CUI_MENU_SRC_TYPE_RESOURCE,
                                  CUI_MENU_TYPE_APPMAIN, /* CUI_MENU_TYPE_OPTION, */
                                  MENU_ID_OP11_HS_CLOCK_SIZE,
                                  MMI_TRUE,
                                  NULL);

    if (menu_cui_id != GRP_ID_INVALID)
    {
		if (g_hs_setting_clock_size == 0)
		{
			cui_menu_set_radio_list_item(menu_cui_id, MENU_ID_OP11_HS_CLOCK_SIZE_SMALL);
		}
		else
		{
			cui_menu_set_radio_list_item(menu_cui_id, MENU_ID_OP11_HS_CLOCK_SIZE_LARGE);
		}
        cui_menu_enable_center_softkey(menu_cui_id, 0, 0);
        cui_menu_run(menu_cui_id);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_clock_size_done
 * DESCRIPTION
 *  no handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_clock_size_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_setting_cntx_p->done_flag = 1;
    g_hs_setting_clock_size = (U8)g_setting_cntx_p->selected_item;

    WriteValue(NVRAM_OP11_HS32_CLOCK_SIZE, &g_hs_setting_clock_size, DS_BYTE, &error);

//    mmi_display_popup((UI_string_type)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
    mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);

//    DeleteScreenIfPresent(SCR_ID_OP11_HS_SETTING_CLK_SIZE);
    mmi_frm_scrn_close(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_SETTING_CLK_SIZE); 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_is_dual_clock
 * DESCRIPTION
 *  no handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_is_dual_clock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID  menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_id = cui_menu_create(g_mmi_op11_hs32_cntx.lsk_sg_id,
                                  CUI_MENU_SRC_TYPE_RESOURCE,
                                  CUI_MENU_TYPE_APPMAIN, /* CUI_MENU_TYPE_OPTION, */
                                  MENU_ID_OP11_HS_DUAL_CLOCK,
                                  MMI_TRUE,
                                  NULL);

    if (menu_cui_id != GRP_ID_INVALID)
    {
		if (PhnsetGetDualClockState() == 1)
		{
			cui_menu_set_radio_list_item(menu_cui_id, MENU_ID_OP11_HS_DUAL_CLOCK_ON);
		}
		else
		{
			cui_menu_set_radio_list_item(menu_cui_id, MENU_ID_OP11_HS_DUAL_CLOCK_OFF);
		}
        cui_menu_enable_center_softkey(menu_cui_id, 0, 0);
        cui_menu_run(menu_cui_id);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_is_dual_clock_done
 * DESCRIPTION
 *  no handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_is_dual_clock_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    state = (U8)g_setting_cntx_p->selected_item;
    PhnsetSetDualClockState(state);
	g_setting_cntx_p->done_flag = 1;
    mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
//    DeleteScreenIfPresent(SCR_ID_OP11_HS_SETTING_DUAL_CLK);
    mmi_frm_scrn_close(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_SETTING_DUAL_CLK); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_show_my_num_done
 * DESCRIPTION
 *  show my number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_show_my_num_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    state = (U8)g_setting_cntx_p->selected_item;
    mmi_op11_hs_set_show_owner_num(state);
	g_setting_cntx_p->done_flag = 1;
    mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
//    DeleteScreenIfPresent(SCR_ID_OP11_HS_SETTING_SHOW_MY_NUM);
    mmi_frm_scrn_close(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_SETTING_SHOW_MY_NUM); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_show_my_num
 * DESCRIPTION
 *  show my number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_show_my_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16  StrItemList[] = {STR_ID_OP11_HS_HIDE, STR_ID_OP11_HS_SHOW};   
    U16  nNumofItem;
    U8 * guiBuffer;
    U8   highlight_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_HS_SETTING_SHOW_MY_NUM, NULL, mmi_more_setting_show_my_num, NULL);
//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_HS_SETTING_SHOW_MY_NUM);

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_SETTING_SHOW_MY_NUM, NULL, mmi_more_setting_show_my_num, MMI_FRM_FULL_SCRN) == MMI_FALSE)
		return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    nNumofItem = sizeof(StrItemList)/sizeof(U16);

    RegisterHighlightHandler(mmi_more_setting_highlight_hdlr);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    highlight_item = mmi_op11_hs_is_show_owner_num();
    ShowCategory11Screen(STR_ID_OP11_HS_MY_NUMBER,
                         0,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK, 
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 
                         nNumofItem, 
                         StrItemList,
                         highlight_item,
                         guiBuffer);

    SetLeftSoftkeyFunction(mmi_more_setting_show_my_num_done, KEY_EVENT_UP);
//    SetKeyHandler(mmi_more_setting_show_my_num_done, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_more_setting_show_my_num_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_sel_shct_cb
 * DESCRIPTION
 *  no handler 
 * PARAMETERS
 *  SHCT_DEDICATED_KEY_ENUM : 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_sel_shct_cb(mmi_shct_nav_key_enum nav_key)
{
    g_setting_cntx_p->done_flag = 1;
}
#endif

#if defined(__MMI_DIALER_SEARCH__)
/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_keypad_search
 * DESCRIPTION
 *  no handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_keypad_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID  menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_id = cui_menu_create(g_mmi_op11_hs32_cntx.lsk_sg_id,
                                  CUI_MENU_SRC_TYPE_RESOURCE,
                                  CUI_MENU_TYPE_APPMAIN, /* CUI_MENU_TYPE_OPTION, */
                                  MENU_ID_OP11_HS_KEYPAD_SEARCH,
                                  MMI_TRUE,
                                  NULL);

    if (menu_cui_id != GRP_ID_INVALID)
    {
		if (g_hs_setting_keypad_search == 1)
		{
			cui_menu_set_radio_list_item(menu_cui_id, MENU_ID_OP11_HS_KEYPAD_SEARCH_ON);
		}
		else
		{
			cui_menu_set_radio_list_item(menu_cui_id, MENU_ID_OP11_HS_KEYPAD_SEARCH_OFF);
		}
        cui_menu_enable_center_softkey(menu_cui_id, 0, 0);
        cui_menu_run(menu_cui_id);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_help
 * DESCRIPTION
 *  enter help screen. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_help(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *guiBuffer;

    /*-----------------------------------------------------------  -----*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_HS_MORE_SETTING_HELP, NULL, mmi_more_setting_help, NULL);
//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_HS_MORE_SETTING_HELP); 

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_MORE_SETTING_HELP, NULL, mmi_more_setting_help, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf(); 

    ShowCategory74Screen(
        STR_GLOBAL_HELP,
        IMG_GLOBAL_OPTIONS,
        0,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK, 
        (U8 *)get_string(STR_ID_OP11_HS_HELP_CONTENT),
        mmi_ucs2strlen((CHAR *)get_string(STR_ID_OP11_HS_HELP_CONTENT)),
        guiBuffer);

    /* SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP); */
    /* SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_ENTER, KEY_EVENT_UP); */
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hs_is_owner_number_empty
 * DESCRIPTION
 *  to check whether the number of "Owner number" is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_hs_is_owner_number_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16     line = 0; 
	S32  len;
    U16 *   number;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    if (srv_callset_line_switch_get_id(MMI_SIM1) == SRV_CALLSET_LINE1)
    {
        line = 0;
    } 
    else if (srv_callset_line_switch_get_id(MMI_SIM1) == SRV_CALLSET_LINE2)
    {
        line = 1;
    }
#endif
    number = srv_phb_owner_number_get_number(SIM1, line);
	len = mmi_ucs2strlen((const CHAR *)number);
    if (len == 0)
    {
        return MMI_TRUE;
    }    

	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs32_get_owner_number
 * DESCRIPTION
 *  to check whether the number of "Owner number" is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
const U8 * mmi_op11_hs32_get_owner_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16  line = 0; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    if (srv_callset_line_switch_get_id(MMI_SIM1) == SRV_CALLSET_LINE1)
    {
        line = 0;
    } 
    else if (srv_callset_line_switch_get_id(MMI_SIM1) == SRV_CALLSET_LINE2)
    {
        line = 1;
    }
#endif

	return (U8*)srv_phb_owner_number_get_number(SIM1, line);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hs_is_owner_number_valid
 * DESCRIPTION
 *  to check whether the number of "Owner number" is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_hs_is_owner_number_valid(U16 * number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_check_valid_number((U16*) number) ||
        mmi_ucs2str((CHAR*)number, "w") || mmi_ucs2str((CHAR*)number, "W"))
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_get_phb_entry_callback
 * DESCRIPTION
 *  callback function of get phonebook entry 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_get_phb_entry_callback(U16 result, l4c_phb_entry_struct *sim_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
        srv_phb_parse_l4phb_entry(sim_entry, g_setting_cntx_p->my_num_name, NULL, g_setting_cntx_p->my_num_number);
        mmi_more_setting_input_my_number();
    }
    else
    {
        mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE, NULL);
//        mmi_display_popup((UI_string_type)get_string(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_input_my_number_pre
 * DESCRIPTION
 *  pre-entry input my number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_input_my_number_pre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16         record_index = 1;
    U16      *  number;   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#else
    g_setting_cntx_p->line_id = srv_callset_line_switch_get_id(MMI_SIM1);
#endif

    number = srv_phb_owner_number_get_number(SIM1, g_setting_cntx_p->line_id);
    mmi_ucs2cpy((CHAR*)g_setting_cntx_p->my_num_number, (CHAR*)number);
    mmi_more_setting_input_my_number();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_input_my_number
 * DESCRIPTION
 *  entry input my number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_input_my_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID  inline_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	inline_cui_id = cui_inline_create(g_mmi_op11_hs32_cntx.lsk_sg_id, &hs_inline_screen);
	if (inline_cui_id != GRP_ID_INVALID)
	{
		cui_inline_run(inline_cui_id);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs32_del_input_my_number_screen
 * DESCRIPTION
 *  delete input my number screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs32_del_input_my_number_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    DeleteScreenIfPresent(SCR_ID_OP11_HS_INPUT_MY_NUMBER);
    mmi_frm_scrn_close(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_INPUT_MY_NUMBER); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_input_my_number_custom_func
 * DESCRIPTION
 *  entry input my number custom function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_input_my_number_custom_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((const CHAR *)g_setting_cntx_p->my_num_number) == 0)
    {
        ChangeLeftSoftkey(0, 0);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_more_setting_save_my_number, KEY_EVENT_UP);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_more_setting_save_my_number
 * DESCRIPTION
 *  save my number into SIM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_save_my_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16         entry_index = 1;
    U16 *       name;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_hs_is_owner_number_valid(g_setting_cntx_p->my_num_number))
    {
        mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_INVALID_NUMBER), MMI_EVENT_FAILURE, NULL);
//        mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_INVALID_NUMBER), MMI_EVENT_FAILURE);
        return;
    }

//    mmi_ucs2cpy((CHAR*)g_setting_cntx_p->my_num_name, (CHAR*)(gDispOwnerNumber[g_setting_cntx_p->line_id].name));
    name = srv_phb_owner_number_get_name(SIM1, g_setting_cntx_p->line_id);
    mmi_ucs2cpy((CHAR*)g_setting_cntx_p->my_num_name, (CHAR*)name);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    if (g_setting_cntx_p->line_id == SRV_CALLSET_LINE1)
    {
        entry_index = 1;
    } 
    else if (g_setting_cntx_p->line_id == SRV_CALLSET_LINE2)
    {
        entry_index = 2;
    }
#endif
    srv_phb_xmgnt_set_entry(
        SIM1,
        PHB_MSISDN,
        entry_index,
        0xFFFF,
		(U16 *)g_setting_cntx_p->my_num_name,
		(U16 *)g_setting_cntx_p->my_num_number,
        mmi_more_setting_set_number_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_owner_number_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_more_setting_set_number_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
		g_setting_cntx_p->done_flag  = 1;
//		mmi_phb_get_owner_number_list_req();
              mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
//		mmi_display_popup((UI_string_type)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
          #if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
              mmi_op11_hs32_force_sidebar_view();
          #endif
//		DeleteScreenIfPresent(SCR_ID_OP11_HS_INPUT_MY_NUMBER);
              mmi_frm_scrn_close(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_INPUT_MY_NUMBER); 
    }
    else
    {
              mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_FAILED_TO_SAVE), MMI_EVENT_FAILURE, NULL);
//		mmi_display_popup((UI_string_type)get_string(STR_GLOBAL_FAILED_TO_SAVE), MMI_EVENT_FAILURE);
          #if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
              mmi_op11_hs32_force_sidebar_view();
          #endif
//		DeleteScreenIfPresent(SCR_ID_OP11_HS_INPUT_MY_NUMBER);
              mmi_frm_scrn_close(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_INPUT_MY_NUMBER); 
    }
}



/*********** below part for options menu **********************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_entry_options_menu
 * DESCRIPTION
 *  enter options menu for others
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_entry_options_menu(S32 sidebar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_op11_hs_screen_history_struct * screen_history_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_setting_cntx_p->curr_sidebar = sidebar;
    ASSERT(sidebar<MMI_OP11_HS32_AP_TYPE_MAX);

    mmi_op11_hs_create_lsk_root_gid();

    /* Because history is saved while exit idle screen. */
//    EntryNewScreen(SCR_ID_OP11_HS_DUMMY, NULL, NULL, NULL);
//    mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_DUMMY, NULL, NULL, MMI_FRM_FULL_SCRN);
    mmi_frm_display_dummy_screen_ex(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_DUMMY);

    screen_history_p = (const mmi_op11_hs_screen_history_struct*)g_mmi_op11_hs32_cntx.history;
    g_setting_cntx_p->curr_shct = screen_history_p->shortcut_index;

#ifdef __MMI_OP11_HOMESCREEN_US__
    mmi_op11_hs_entry_personalise_us_int();
#else
    mmi_op11_hs_entry_options_menu_int();
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_entry_options_menu_int
 * DESCRIPTION
 *  enter options menu for internal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_op11_hs_entry_options_menu_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16     str_id_list[10]; /* attention: max shcts may less than 10 */
    U8 *    string_list[10];
    U16     nItems;
    U8 *    guiBuffer;
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_HS_OPTIONS, NULL, mmi_op11_hs_entry_options_menu_int, NULL);
//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_HS_OPTIONS);    

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_OPTIONS, NULL, mmi_op11_hs_entry_options_menu_int, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();    


#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
    mmi_frm_unhide_menu_item(MENU_ID_OP11_HS_SWITCH_VIEWS);/* For HS3.2 only */
    switch(g_setting_cntx_p->curr_sidebar)
    {
        case MMI_OP11_HS32_AP_ALM:
        case MMI_OP11_HS32_AP_CNX:
        case MMI_OP11_HS32_AP_DST:
            if (mmi_op11_hs_is_wp_exist(g_setting_cntx_p->curr_sidebar))
            {
                mmi_frm_hide_menu_item(MENU_ID_OP11_HS_ATTACH_WP);
                mmi_frm_unhide_menu_item(MENU_ID_OP11_HS_DETACH_WP);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_ID_OP11_HS_ATTACH_WP);
                mmi_frm_hide_menu_item(MENU_ID_OP11_HS_DETACH_WP);
            }
            break;

        default:
            mmi_frm_hide_menu_item(MENU_ID_OP11_HS_ATTACH_WP);
            mmi_frm_hide_menu_item(MENU_ID_OP11_HS_DETACH_WP);
            break;
    }
#else
    mmi_frm_hide_menu_item(MENU_ID_OP11_HS_SWITCH_VIEWS);/* For HS3.2 only */
    mmi_frm_hide_menu_item(MENU_ID_OP11_HS_ATTACH_WP);   /* For HS3.2 only */
    mmi_frm_hide_menu_item(MENU_ID_OP11_HS_DETACH_WP);   /* For HS3.2 only */
#endif /* (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__)) */

    switch(g_setting_cntx_p->curr_sidebar)
    {
        case MMI_OP11_HS32_AP_CON:
        case MMI_OP11_HS32_AP_EML:
            if (g_mmi_op11_hs32_cntx.shct_ui_count[g_setting_cntx_p->curr_sidebar] == 0)
            {
                mmi_frm_hide_menu_item(MENU_ID_OP11_HS_CONTEXT_ITEM); 
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_ID_OP11_HS_CONTEXT_ITEM); 
            }
            mmi_frm_unhide_menu_item(MENU_ID_OP11_HS_REORDER_SHCTS); 
            break;

        case MMI_OP11_HS32_AP_CNX:
            mmi_frm_unhide_menu_item(MENU_ID_OP11_HS_CONTEXT_ITEM); 
            mmi_frm_unhide_menu_item(MENU_ID_OP11_HS_REORDER_SHCTS); 
            break;
            
        case MMI_OP11_HS32_AP_ALM:
            if (NULL == mmi_op11_hs32_option_context_exec(g_setting_cntx_p->curr_sidebar, -1))
            {
                mmi_frm_hide_menu_item(MENU_ID_OP11_HS_CONTEXT_ITEM); 
                mmi_frm_hide_menu_item(MENU_ID_OP11_HS_REORDER_SHCTS); 
            }
            else
            {
            mmi_frm_unhide_menu_item(MENU_ID_OP11_HS_CONTEXT_ITEM); 
            mmi_frm_hide_menu_item(MENU_ID_OP11_HS_REORDER_SHCTS); 
            }
            break;

        case MMI_OP11_HS32_AP_PRO:
        case MMI_OP11_HS32_AP_DST:
        case MMI_OP11_HS32_AP_STK:
            mmi_frm_hide_menu_item(MENU_ID_OP11_HS_CONTEXT_ITEM); 
            mmi_frm_hide_menu_item(MENU_ID_OP11_HS_REORDER_SHCTS); 
            break;

        default:
            mmi_frm_hide_menu_item(MENU_ID_OP11_HS_CONTEXT_ITEM); 
            mmi_frm_unhide_menu_item(MENU_ID_OP11_HS_REORDER_SHCTS); 
            break;
    }

    if (g_mmi_op11_hs32_cntx.shct_ui_count[g_setting_cntx_p->curr_sidebar] <= 1)
    {
        mmi_frm_hide_menu_item(MENU_ID_OP11_HS_REORDER_SHCTS); 
    }

    nItems = GetNumOfChild_Ext(MENU_ID_OP11_HS_OPTIONS);
    GetSequenceStringIds_Ext(MENU_ID_OP11_HS_OPTIONS, str_id_list);
    SetParentHandler(MENU_ID_OP11_HS_OPTIONS);

    for (i = 0; i < nItems; i++)
    {
        string_list[i] = (U8*)get_string(str_id_list[i]);
    }

    switch(g_setting_cntx_p->curr_sidebar)
    {
        case MMI_OP11_HS32_AP_CON:
        case MMI_OP11_HS32_AP_EML:
            if (!(g_mmi_op11_hs32_cntx.shct_ui_count[g_setting_cntx_p->curr_sidebar] == 0))
            {
                string_list[0] = mmi_op11_hs32_option_context_exec(g_setting_cntx_p->curr_sidebar, 0);
            }            
            break;

        case MMI_OP11_HS32_AP_CNX:
            string_list[0] = mmi_op11_hs32_option_context_exec(g_setting_cntx_p->curr_sidebar, 0);
            break;

        case MMI_OP11_HS32_AP_ALM:
            if (NULL != mmi_op11_hs32_option_context_exec(g_setting_cntx_p->curr_sidebar, -1))
            {
                string_list[0] = mmi_op11_hs32_option_context_exec(g_setting_cntx_p->curr_sidebar, 0);
            }
            break;
   
        default:
            break;
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    ShowCategory6Screen(
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_SELECT,
        0,
        STR_GLOBAL_CLOSE,
        0,
        nItems,
        string_list,
        NULL,
        0,
        guiBuffer);     

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}



/*********** above part for options menu **********************************************/
/*********** below part for reorder shortcut ******************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_shct_main
 * DESCRIPTION
 *  main entry for reorder shortcut
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_shct_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_setting_cntx_p->act_state = ACTION_STATE_SELECT;
    g_setting_cntx_p->done_flag = 0;
    mmi_reorder_shct_int();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_shct_int
 * DESCRIPTION
 *  reorder shortcut for internal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_shct_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *    guiBuffer;
    U8      index;
    U8      item;
    U8  *   shct_item_list;
    const U16 *   shct_str_list;
    U16     sub_title, str_rsk;
    FuncPtr func_rsk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_RRD_SHCT_SELECT, NULL, mmi_reorder_shct_int, NULL);
//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_RRD_SHCT_SELECT);

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_RRD_SHCT_SELECT, NULL, mmi_reorder_shct_int, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* sub title */
    if (g_setting_cntx_p->done_flag) 
    {
        sub_title = STR_ID_OP11_HS_SHCT_CHS_OTH_MOV;
        func_rsk  = mmi_reorder_shct_done;
        str_rsk   = STR_GLOBAL_DONE;
    } 
    else 
    {
        sub_title = STR_ID_OP11_HS_SHCT_CHS_TO_MOV;
        func_rsk  = mmi_frm_scrn_close_active_id;
        str_rsk   = STR_GLOBAL_CANCEL;
    }

    /* check from where to entry */
    if (guiBuffer != NULL)
    {
        if (g_setting_cntx_p->act_state == ACTION_STATE_CNF_BACK) 
        {
            guiBuffer = g_setting_cntx_p->list_gui_buf;
        }
    }
    g_setting_cntx_p->act_state = ACTION_STATE_SELECT;

    /* prepare string, icon, state icon */
    ASSERT(g_setting_cntx_p->curr_sidebar<MMI_OP11_HS32_AP_TYPE_MAX);
    shct_item_list = g_hs_hist_cntx.shct_hist[g_setting_cntx_p->curr_sidebar];
    shct_str_list  = g_mmi_op11_hs_shct_str_list[g_setting_cntx_p->curr_sidebar];

    if (shct_item_list != NULL)
    {
        index = 0;
        while (shct_item_list[index] != 0xFF)
        {
            item = shct_item_list[index];

            g_setting_cntx_p->str_list[index]   = (U8*) get_string((U16)shct_str_list[item]);
            g_setting_cntx_p->icon_list1[index] = 0;
            g_setting_cntx_p->icon_list2[index] = 0;

            index++;
        }
        g_setting_cntx_p->item_count = index;
    } 
    else
    {
        g_setting_cntx_p->item_count = 0;
    }

    RegisterHighlightHandler(mmi_reorder_hs_item_sel_highlight_hdlr);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    wgui_cat1002_op11_set_order_screen(MMI_FALSE);
    wgui_cat1002_op11_show(
        get_string(STR_ID_OP11_HS_REORDER_SHCTS),
        get_string(sub_title),
        get_string(STR_GLOBAL_SELECT),
        0,
        get_string(str_rsk),
        0,
        g_setting_cntx_p->item_count,
        g_setting_cntx_p->str_list,
        g_setting_cntx_p->icon_list1,
        g_setting_cntx_p->icon_list2,
        g_setting_cntx_p->curr_shct,
        NULL,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_reorder_shct_place_pre, KEY_EVENT_UP);
//    SetKeyHandler(mmi_reorder_shct_place_pre, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_reorder_shct_place_pre, KEY_EVENT_UP);
    SetRightSoftkeyFunction(func_rsk, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_shct_place_pre
 * DESCRIPTION
 *  pre-entry for place the item when reorder shortcut for
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_shct_place_pre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *   shct_item_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rdr_cntx_p->curr_sidebar = g_setting_cntx_p->curr_sidebar;
    g_rdr_cntx_p->seld_idx     = g_setting_cntx_p->selected_item;

    g_rdr_cntx_p->last_idx     = g_rdr_cntx_p->seld_idx;
    g_rdr_cntx_p->curr_idx     = g_rdr_cntx_p->seld_idx;

    GetCategoryHistory(g_setting_cntx_p->list_gui_buf);
    g_rdr_cntx_p->gui_buffer = g_setting_cntx_p->list_gui_buf;


    ASSERT(g_setting_cntx_p->curr_sidebar<MMI_OP11_HS32_AP_TYPE_MAX);
    shct_item_list = g_hs_hist_cntx.shct_hist[g_setting_cntx_p->curr_sidebar];
    MMI_HS_CPY_ITEM(g_rdr_cntx_p->sb_order, shct_item_list);

    g_rdr_cntx_p->str_title     = STR_ID_OP11_HS_REORDER_SHCTS;
    g_rdr_cntx_p->str_sub_title = STR_ID_OP11_HS_SHCT_MOV_TO;
    g_rdr_cntx_p->str_lsk       = STR_ID_OP11_HS_PLACE_HERE;
    g_rdr_cntx_p->str_rsk       = STR_GLOBAL_CANCEL;

    g_rdr_cntx_p->func_lsk      = mmi_reorder_shct_place_cnf;
    g_rdr_cntx_p->func_rsk      = mmi_reorder_shct_place_cancel;
    g_rdr_cntx_p->draw_item_func= NULL;

    mmi_op11_hs_reorder_shortcut_place();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_shct_place_cnf
 * DESCRIPTION
 *  confirm placing here and back to select other item to reorder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_shct_place_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *   shct_item_list;
    S16     error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_setting_cntx_p->curr_sidebar<MMI_OP11_HS32_AP_TYPE_MAX);
    shct_item_list = g_hs_hist_cntx.shct_hist[g_setting_cntx_p->curr_sidebar];
    MMI_HS_CPY_ITEM(shct_item_list, g_rdr_cntx_p->sb_order);
    WriteRecord(NVRAM_EF_OP11_HS32_HIST_LID, 1, &g_hs_hist_cntx, NVRAM_EF_OP11_HS32_HIST_SIZE, &error);

    g_setting_cntx_p->curr_shct = g_rdr_cntx_p->curr_idx;

    GetCategoryHistory(g_setting_cntx_p->list_gui_buf);

    g_setting_cntx_p->act_state = ACTION_STATE_CNF_BACK;
    g_setting_cntx_p->done_flag = 1;

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_shct_place_cancel
 * DESCRIPTION
 *  cancel placing here and back to select other item to reorder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_shct_place_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_setting_cntx_p->act_state = ACTION_STATE_CAN_BACK;
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_shct_done
 * DESCRIPTION
 *  finish reordering shortcut and back to homescreen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_reorder_shct_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    mmi_op11_hs_screen_history_struct * screen_history_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    screen_history_p = (mmi_op11_hs_screen_history_struct*)g_mmi_op11_hs32_cntx.history;
    screen_history_p->shortcut_index = g_setting_cntx_p->curr_shct;
    g_mmi_op11_hs32_cntx.flag &= ~MMI_OP11_HS32_HISTORY_DISCARDED;

//    DeleteScreenIfPresent(SCR_ID_OP11_HS_OPTIONS);
    mmi_frm_scrn_close(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_OPTIONS); 
	if (g_setting_cntx_p->curr_sidebar == MMI_OP11_HS32_AP_EML)
	{
		if (!g_mmi_op11_hs32_cntx.shct_eml_reordered)
		{
			g_mmi_op11_hs32_cntx.shct_eml_reordered = 1;
			WriteValue(NVRAM_OP11_HS32_SHCT_EML_CHANGED, &g_mmi_op11_hs32_cntx.shct_eml_reordered, DS_BYTE, &error);
		}
	}
	else if (g_setting_cntx_p->curr_sidebar == MMI_OP11_HS32_AP_CON)
	{
		if (!g_mmi_op11_hs32_cntx.shct_phb_reordered)
		{
			g_mmi_op11_hs32_cntx.shct_phb_reordered = 1;
			WriteValue(NVRAM_OP11_HS32_SHCT_PHB_CHANGED, &g_mmi_op11_hs32_cntx.shct_phb_reordered, DS_BYTE, &error);
		}
	}	

    mmi_frm_scrn_close_active_id();
}




/*********** above part for reorder shortcut ******************************************/
/*********** below part for highlight handler *****************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_switch_views
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_switch_views(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
    SetLeftSoftkeyFunction(mmi_entry_switch_view_mode, KEY_EVENT_UP);
//    SetKeyHandler(mmi_entry_switch_view_mode, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_entry_switch_view_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_edit_hs_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_edit_hs_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_OP11_HOMESCREEN_US__
    SetLeftSoftkeyFunction(mmi_edit_sidebar_icons, KEY_EVENT_UP);
//    SetKeyHandler(mmi_edit_sidebar_icons, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_edit_sidebar_icons, KEY_EVENT_UP);
#else
    SetLeftSoftkeyFunction(mmi_op11_hs_entry_edit_hs_item, KEY_EVENT_UP);
//    SetKeyHandler(mmi_op11_hs_entry_edit_hs_item, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_op11_hs_entry_edit_hs_item, KEY_EVENT_UP);
#endif    

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_set_wp_panels
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_set_wp_panels(void)
{
#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
    g_mmi_op11_hs32_cntx.is_wp_edit = 0;
    g_mmi_op11_hs32_cntx.wp_mgr_index = MMI_OP11_HS32_AP_WP_MAX - 1;
    SetLeftSoftkeyFunction(mmi_op11_hs32_enter_wp_mgr_screen, KEY_EVENT_UP);
//    SetKeyHandler(mmi_op11_hs32_enter_wp_mgr_screen, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_op11_hs32_enter_wp_mgr_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_set_wp_panels
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_edit_wp_panels(void)
{
#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_op11_hs32_cntx.is_wp_edit = 1;

    for (i =MMI_OP11_HS32_AP_WP_MAX-1; i >= 0; i--)
    {
        if (g_hs_hist_cntx.wp_hist[i] == 0xff)
        {
            break;
        }
    }

    if (i < 0)
    {
        i = 0;
    }
    g_mmi_op11_hs32_cntx.wp_mgr_index = i;

    SetLeftSoftkeyFunction(mmi_op11_hs32_enter_wp_mgr_screen, KEY_EVENT_UP);
//    SetKeyHandler(mmi_op11_hs32_enter_wp_mgr_screen, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_op11_hs32_enter_wp_mgr_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_more_settings
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_more_settings(void)
{    
    SetLeftSoftkeyFunction(mmi_more_setting_main_pre, KEY_EVENT_UP);
//    SetKeyHandler(mmi_more_setting_main_pre, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_more_setting_main_pre, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_help
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_help(void)
{
    SetLeftSoftkeyFunction(mmi_more_setting_help, KEY_EVENT_UP);
//    SetKeyHandler(mmi_more_setting_help, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_more_setting_help, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_reorder_shcts
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_reorder_shcts(void)
{
    SetLeftSoftkeyFunction(mmi_reorder_shct_main, KEY_EVENT_UP);
//    SetKeyHandler(mmi_reorder_shct_main, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_reorder_shct_main, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_attach_wp
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_attach_wp(void)
{
#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
    SetLeftSoftkeyFunction(mmi_op11_hs_attach_wp, KEY_EVENT_UP);
//    SetKeyHandler(mmi_op11_hs_attach_wp, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_op11_hs_attach_wp, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_attach_wp
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_detach_wp(void)
{
#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
    SetLeftSoftkeyFunction(mmi_op11_hs_detach_wp, KEY_EVENT_UP);
//    SetKeyHandler(mmi_op11_hs_detach_wp, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_op11_hs_detach_wp, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_reorder_items
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_reorder_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_reorder_sidebar_select, KEY_EVENT_UP);
//    SetKeyHandler(mmi_reorder_sidebar_select, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_reorder_sidebar_select, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_add_item
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_add_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_add_sidebar_items_check, KEY_EVENT_UP);
//    SetKeyHandler(mmi_add_sidebar_items_check, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_add_sidebar_items_check, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_remove_items
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_remove_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_remove_sidebar_main, KEY_EVENT_UP);
//    SetKeyHandler(mmi_remove_sidebar_main, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_remove_sidebar_main, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_context_item
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_context_hilight_hdlr(void)
{
    mmi_op11_hs32_option_context_exec(g_setting_cntx_p->curr_sidebar, 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_context_item
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_context_item(void)
{
    SetLeftSoftkeyFunction(mmi_op11_hs_context_hilight_hdlr, KEY_EVENT_UP);
//    SetKeyHandler(mmi_op11_hs_context_hilight_hdlr, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_op11_hs_context_hilight_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_us_change_wallpaper_cb
 * DESCRIPTION
 *  highlight handler call back
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_us_change_wallpaper_cb(void)
{
    /* for MAUI_02582994 start */
    extern PHNSET_CNTX *g_phnset_cntx_p;
    g_phnset_cntx_p->wpss_type = MMI_PHNSET_TYPE_WP;
    /* for MAUI_02582994 end */

    EntryPhnsetWallpaperSys(g_mmi_op11_hs32_cntx.lsk_sg_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_switch_views
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_us_change_wallpaper(void)
{
    SetLeftSoftkeyFunction(mmi_op11_hs_hilight_us_change_wallpaper_cb, KEY_EVENT_UP);
//    SetKeyHandler(mmi_phnset_entry_wallpaper_main, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_op11_hs_hilight_us_change_wallpaper_cb, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_hilight_switch_views
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_hilight_us_switch_mynumber(void)
{
    SetLeftSoftkeyFunction(mmi_op11_hs_us_switch_mynumber, KEY_EVENT_UP);
//    SetKeyHandler(mmi_op11_hs_us_switch_mynumber, KEY_ENTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_op11_hs_us_switch_mynumber, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*********** above part for highlight handler *****************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_save_id_history
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_save_id_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16     error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_OP11_HS32_HIST_LID, 1, &g_hs_hist_cntx, NVRAM_EF_OP11_HS32_HIST_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_entry_personalise_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_entry_personalise_us_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16     ItemStrList[MAX_SUB_MENUS];
    U16     nItems;
    U8 *    guiBuffer;
    MMI_BOOL	show_flag;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_startup_is_phb_support(SIM1, PHB_MSISDN))
    {
         mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_BUSY_TRY_LATER), MMI_EVENT_FAILURE, NULL);
         return;
    }

//    EntryNewScreen(SCR_ID_OP11_HS_PERSONALISATION, NULL, mmi_op11_hs_entry_personalise_us_int, NULL);

//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_HS_PERSONALISATION);

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_PERSONALISATION, NULL, mmi_op11_hs_entry_personalise_us_int, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        return;

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    nItems = GetNumOfChild_Ext(MENU_ID_OP11_HS_US_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_OP11_HS_US_OPTION, ItemStrList);
    SetParentHandler(MENU_ID_OP11_HS_US_OPTION);

    /* my number mmi_op11_hs_is_show_owner_num */
    if (!srv_phb_startup_is_phb_support(SIM1, PHB_MSISDN))
    {
        ItemStrList[2] = STR_GLOBAL_NOT_SUPPORTED;
    }
    else
    {
	 show_flag = mmi_op11_hs_is_show_owner_num() && !mmi_hs_is_owner_number_empty();
        if (show_flag)
        {
            ItemStrList[2] = STR_ID_OP11_HS_HIDE_MYNUMBER;
        }
        else
        {
            ItemStrList[2] = STR_ID_OP11_HS_SHOW_MYNUMBER;
        }
    }
    
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory1Screen(
        STR_ID_OP11_HS_US_PERSONALISE_HS,
        0,
        STR_GLOBAL_SELECT,
        0,
        STR_GLOBAL_CLOSE,
        0,
        nItems,
        ItemStrList,
        0,
        guiBuffer);     

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_entry_personalise_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs_us_switch_mynumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  show;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_phb_startup_is_phb_support(SIM1, PHB_MSISDN))
    {
         mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_NOT_SUPPORTED), MMI_EVENT_FAILURE, NULL);
//         mmi_display_popup((UI_string_type)get_string(STR_GLOBAL_NOT_SUPPORTED), MMI_EVENT_INFO);
         return;
    }
	/* void mmi_phb_owner_number_pre_req(void) PhoneBookExtraNumber.c */			
	if (mmi_hs_is_owner_number_empty())
	{
		mmi_op11_hs_set_show_owner_num(1);
		mmi_more_setting_input_my_number_pre();
	}
	else 
	{
        show = mmi_op11_hs_is_show_owner_num();
        show = !show;
        mmi_op11_hs_set_show_owner_num((U8)show);

        mmi_op11_hs32_discard_history();
        mmi_op11_hs32_goback_to_main();
	}			
	/* mmi_more_setting_show_my_num();*/
}

#ifdef __MMI_OP11_HOMESCREEN_US__

static S32 mmi_edit_sidebar_organise_items_us(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32      index;
    U8       item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = 0;
    while (g_hs_sidebar_needed[index] != 0xFF)
    {
        item = g_hs_sidebar_needed[index];

        g_setting_cntx_p->str_list[index]   = (U8*) get_string((U16)g_hs_sidebar_str[item]);
        g_setting_cntx_p->icon_list1[index] = g_hs_sidebar_icon[item];

        if (g_setting_cntx_p->sb_item_hist[index] == 0)
        {
            g_setting_cntx_p->icon_list2[index] = SMALL_CHECKBOX_OFF_IMAGE_ID;
        }
        else if (g_setting_cntx_p->sb_item_hist[index] == 1)
        {
            g_setting_cntx_p->icon_list2[index] = SMALL_CHECKBOX_ON_IMAGE_ID;
        }
        else if (g_setting_cntx_p->sb_item_hist[index] == 2)
        {
            g_setting_cntx_p->icon_list2[index] = IMG_ID_OP11_HS_ML_LOCK;
        }

        index++;
    }
    return index; 
}


static void mmi_edit_sidebar_icons(void)
{
    g_setting_cntx_p->done_flag     = 0;
    g_setting_cntx_p->selected_item = 0;

    memcpy(g_setting_cntx_p->sb_item_hist, g_hs_hist_cntx.sdbr_hist, MMI_OP11_HS32_SB_HIST_MAX);

    mmi_edit_sidebar_icons_int();
}

static MMI_BOOL mmi_edit_sidebar_get_flag_hdlr(S32 index, U32* flag, U32* flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == HS_SEPERATE_LINE_INDEX)
    {
        *flag_ex |= UI_MENUITEM_EXT_SHOW_DOWN_SHORT_SEPARATORLINE;
        result = MMI_TRUE;
    }

    if (g_setting_cntx_p->sb_item_hist[index] == 0x02) /* locked */
    {
        *flag |= UI_MENUITEM_STATE_DISABLED;
        result = MMI_TRUE;
    }
    return result;
}

static void mmi_edit_sidebar_icons_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *        guiBuffer;
    FuncPtr     func_rsk;
    U16         str_rsk;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_OP11_HS_EDIT_SIDEBAR_ICONS, NULL, mmi_edit_sidebar_icons_int, NULL);
//    guiBuffer = GetCurrGuiBuffer(SCR_ID_OP11_HS_EDIT_SIDEBAR_ICONS);

    if (mmi_frm_scrn_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, SCR_ID_OP11_HS_EDIT_SIDEBAR_ICONS, NULL, mmi_edit_sidebar_icons_int, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

	/* to check whether there are items can be removed. */

    if (g_setting_cntx_p->done_flag == 1) 
    {
        guiBuffer = NULL;
        str_rsk   = STR_GLOBAL_DONE;
        func_rsk  = mmi_edit_sidebar_done;
    }
    else
    {
        str_rsk   = STR_GLOBAL_CANCEL;
        func_rsk  = mmi_frm_scrn_close_active_id;
    }

    g_setting_cntx_p->item_count = mmi_edit_sidebar_organise_items_us();

    RegisterHighlightHandler(mmi_edit_sidebar_highlight_hdlr);
    wgui_fixed_list_register_get_flags_handler(mmi_edit_sidebar_get_flag_hdlr);
    wgui_cat1002_op11_set_order_screen(MMI_FALSE);

    EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);

    wgui_cat1002_op11_show(
        get_string(STR_ID_OP11_HS_EDIT_SIDEBAR_ICON),
        get_string(STR_ID_OP11_HS_TO_SHOW_HIDE),
        get_string(STR_ID_OP11_HS_HIDE_ICON),
        0,
        get_string(str_rsk),
        0,
        g_setting_cntx_p->item_count,
        g_setting_cntx_p->str_list,
        g_setting_cntx_p->icon_list1,
        g_setting_cntx_p->icon_list2,
        g_setting_cntx_p->selected_item,
        NULL,
        guiBuffer);

//    SetLeftSoftkeyFunction(mmi_remove_sidebar_confirm, KEY_EVENT_UP);
//    SetKeyHandler(mmi_remove_sidebar_confirm, KEY_ENTER, KEY_EVENT_UP);
    SetRightSoftkeyFunction(func_rsk, KEY_EVENT_UP);  
}


static void mmi_edit_sidebar_show_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32  index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = g_setting_cntx_p->selected_item;
    if (g_setting_cntx_p->sb_item_hist[index] == 0)
    {
        g_setting_cntx_p->sb_item_hist[index]     = 1;
        g_setting_cntx_p->icon_list2[index] = SMALL_CHECKBOX_ON_IMAGE_ID;

        ChangeLeftSoftkey(STR_ID_OP11_HS_HIDE_ICON, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(mmi_edit_sidebar_hide_icon, KEY_EVENT_UP);
//        SetKeyHandler(mmi_edit_sidebar_hide_icon, KEY_ENTER, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_edit_sidebar_hide_icon, KEY_EVENT_UP);

        wgui_cat1002_op11_touch_refresh_list();
    }
    else
    {
        ASSERT(0);
    }
    if (g_setting_cntx_p->done_flag == 0)
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(mmi_edit_sidebar_done, KEY_EVENT_UP);
        g_setting_cntx_p->done_flag = 1;
    }
}

static void mmi_edit_sidebar_hide_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32  index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = g_setting_cntx_p->selected_item;
    if (g_setting_cntx_p->sb_item_hist[index] == 1)
    {
        g_setting_cntx_p->sb_item_hist[index] = 0;
        g_setting_cntx_p->icon_list2[index] = SMALL_CHECKBOX_OFF_IMAGE_ID;

        ChangeLeftSoftkey(STR_ID_OP11_HS_SHOW_ICON, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(mmi_edit_sidebar_show_icon, KEY_EVENT_UP);
//        SetKeyHandler(mmi_edit_sidebar_show_icon, KEY_ENTER, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_edit_sidebar_show_icon, KEY_EVENT_UP);

        wgui_cat1002_op11_touch_refresh_list();
    }
    else
    {
        ASSERT(0);
    }
    if (g_setting_cntx_p->done_flag == 0)
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(mmi_edit_sidebar_done, KEY_EVENT_UP);
        g_setting_cntx_p->done_flag = 1;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_edit_sidebar_highlight_hdlr
 * DESCRIPTION
 *  Category 1002_op11 highlight handler.
 * PARAMETERS
 *  index       [IN]    highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_edit_sidebar_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_setting_cntx_p->selected_item = index;
    if (g_setting_cntx_p->sb_item_hist[index] == 0)
    {
        ChangeLeftSoftkey(STR_ID_OP11_HS_SHOW_ICON, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_edit_sidebar_show_icon, KEY_EVENT_UP);
//        SetKeyHandler(mmi_edit_sidebar_show_icon, KEY_ENTER, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_edit_sidebar_show_icon, KEY_EVENT_UP);
    }
    else if (g_setting_cntx_p->sb_item_hist[index] == 1)
    {
        ChangeLeftSoftkey(STR_ID_OP11_HS_HIDE_ICON, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_edit_sidebar_hide_icon, KEY_EVENT_UP);
//        SetKeyHandler(mmi_edit_sidebar_hide_icon, KEY_ENTER, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_edit_sidebar_hide_icon, KEY_EVENT_UP);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_edit_sidebar_done
 * DESCRIPTION
 *  finish removing sidebar items, and back to home screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_edit_sidebar_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     count;
    S32     i;
    S16     error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = 0;
    for (i = 0; i < g_setting_cntx_p->item_count; i++)
    {
        if (g_setting_cntx_p->sb_item_hist[i] != 0)
            count++;
    }

    if (count > 8)
    {
        mmi_popup_display((WCHAR*)get_string(STR_ID_OP11_HS_ADD_LIMIT_INFO8), MMI_EVENT_FAILURE, NULL);
//        mmi_display_popup((UI_string_type)get_string(STR_ID_OP11_HS_ADD_LIMIT_INFO8), MMI_EVENT_WARNING);
        return;
    }

    memcpy(g_hs_hist_cntx.sdbr_hist, g_setting_cntx_p->sb_item_hist, MMI_OP11_HS32_SB_HIST_MAX);
    WriteRecord(NVRAM_EF_OP11_HS32_HIST_LID, 1, &g_hs_hist_cntx, NVRAM_EF_OP11_HS32_HIST_SIZE, &error);    
    
    mmi_edit_sidebar_get_hist_us();
    /* save */
    mmi_op11_hs32_discard_history();
    mmi_op11_hs32_goback_to_main();
}

#endif /* __MMI_OP11_HOMESCREEN_US__ */

#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))

/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_shct_done
 * DESCRIPTION
 *  finish reordering shortcut and back to homescreen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs32_view_mode_toggle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_op11_hs32_cntx.view_mode = 1 - g_mmi_op11_hs32_cntx.view_mode;

    WriteValue(NVRAM_OP11_HS32_VIEW_MODE, &g_mmi_op11_hs32_cntx.view_mode, DS_BYTE, &error);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_shct_done
 * DESCRIPTION
 *  finish reordering shortcut and back to homescreen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs32_force_sidebar_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_op11_hs32_cntx.view_mode = 0;
    WriteValue(NVRAM_OP11_HS32_VIEW_MODE, &g_mmi_op11_hs32_cntx.view_mode, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_shct_done
 * DESCRIPTION
 *  finish reordering shortcut and back to homescreen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_op11_hs_is_wp_exist(U8 wp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i =0; i <MMI_OP11_HS32_AP_WP_MAX; i++)
    {
        if (g_hs_hist_cntx.wp_hist[i] == wp_id)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_get_wp_count
 * DESCRIPTION
 *  finish reordering shortcut and back to homescreen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_op11_hs_get_wp_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, count = 0; i <MMI_OP11_HS32_AP_WP_MAX; i++)
    {
        if (g_hs_hist_cntx.wp_hist[i] != 0xff)
        {
            count ++;
        }
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reorder_shct_done
 * DESCRIPTION
 *  finish reordering shortcut and back to homescreen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_entry_switch_view_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_op11_hs32_view_mode_toggle();
    mmi_op11_hs32_discard_history();
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_entry_options_menu_int
 * DESCRIPTION
 *  enter options menu for internal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_op11_hs_attach_wp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i,j;
    U8 wp_temp[MMI_OP11_HS32_AP_WP_MAX];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(wp_temp, 0xff, sizeof(wp_temp));
    i = MMI_OP11_HS32_AP_WP_MAX - 1;
    j = MMI_OP11_HS32_AP_WP_MAX - 1;
    for (; i >= 0; i--)
    {
        if (g_hs_hist_cntx.wp_hist[i] != 0xff)
        {
            wp_temp[j] = g_hs_hist_cntx.wp_hist[i];
            j --;
        }
    }
    memcpy(g_hs_hist_cntx.wp_hist, wp_temp, MMI_OP11_HS32_AP_WP_MAX);

    for (i =MMI_OP11_HS32_AP_WP_MAX-1; i >= 0; i--)
    {
        if (g_hs_hist_cntx.wp_hist[i] == 0xff)
        {
            g_hs_hist_cntx.wp_hist[i] = g_setting_cntx_p->curr_sidebar;
            break;
        }
    }
    MMI_ASSERT(i >= 0);

    mmi_op11_hs_save_id_history();
    mmi_op11_hs32_force_sidebar_view();
    mmi_op11_hs32_discard_history();
    mmi_op11_hs32_goback_to_main();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_entry_options_menu_int
 * DESCRIPTION
 *  enter options menu for internal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_op11_hs_detach_wp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i,j;
    U8 wp_temp[MMI_OP11_HS32_AP_WP_MAX];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i =MMI_OP11_HS32_AP_WP_MAX-1; i >= 0; i--)
    {
        if (g_hs_hist_cntx.wp_hist[i] == g_setting_cntx_p->curr_sidebar)
        {
            g_hs_hist_cntx.wp_hist[i] = 0xff;
            break;
        }
    }
    MMI_ASSERT(i >= 0);

    memset(wp_temp, 0xff, sizeof(wp_temp));
    i = MMI_OP11_HS32_AP_WP_MAX - 1;
    j = MMI_OP11_HS32_AP_WP_MAX - 1;
    for (; i >= 0; i--)
    {
        if (g_hs_hist_cntx.wp_hist[i] != 0xff)
        {
            wp_temp[j] = g_hs_hist_cntx.wp_hist[i];
            j --;
        }
    }
    memcpy(g_hs_hist_cntx.wp_hist, wp_temp, MMI_OP11_HS32_AP_WP_MAX);

    mmi_op11_hs_save_id_history();
    mmi_op11_hs32_force_sidebar_view();
    mmi_op11_hs32_discard_history();
    mmi_op11_hs32_goback_to_main();

}


#endif /* (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__)) */


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_is_show_owner_num
 * DESCRIPTION
 *  This function is to get show owner number on/off status
 *  Functionality:
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_op11_hs_is_show_owner_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SETTING_OWNER_NO, &data, DS_BYTE, &error);

    if (data == 1)
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
 *  mmi_op11_hs_set_show_owner_num
 * DESCRIPTION
 *  This function is to set show owner number on/off status
 *  Functionality:
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_op11_hs_set_show_owner_num(U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16     error;
    U8      state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    state = status;
    WriteValue(NVRAM_SETTING_OWNER_NO, &state, DS_BYTE, &error);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_create_lsk_root_gid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_op11_hs_create_lsk_root_gid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_mmi_op11_hs32_cntx.lsk_sg_id != 0) && mmi_frm_group_is_present(g_mmi_op11_hs32_cntx.lsk_sg_id))
    {
        mmi_frm_group_close(g_mmi_op11_hs32_cntx.lsk_sg_id);
    }

    g_mmi_op11_hs32_cntx.lsk_sg_id =  mmi_frm_group_create (GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_op11_hs_setting_grp_proc, NULL);
    mmi_frm_group_enter(g_mmi_op11_hs32_cntx.lsk_sg_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_setting_grp_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_op11_hs_setting_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct * menu_evt;
    mmi_popup_property_struct popup_arg;
    MMI_ID sg_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {  
#if 1
        /**********************/
        /*       Menu CUI Start      */
        /**********************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
                    #if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
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
                    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
                    #endif /* (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__)) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                menu_evt = (cui_menu_event_struct *)evt;

                switch(menu_evt->highlighted_menu_id)
                {
#if 0
/* under construction !*/
                        #ifdef __MMI_OP11_HOMESCREEN_US__
/* under construction !*/
                        #else
/* under construction !*/
                        #endif
/* under construction !*/
/* under construction !*/
                #if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
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
                #endif /* __MMI_OP11_HOMESCREEN_0302__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

                    case MENU_ID_OP11_HS_CLOCK_SIZE_SMALL:
                        mmi_op11_hs32_set_clock_size(0); /* small font */
                        g_setting_cntx_p->done_flag = 1;
                        mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
                        cui_menu_close(menu_evt->sender_id);
                        break;

                    case MENU_ID_OP11_HS_CLOCK_SIZE_LARGE:
                        mmi_op11_hs32_set_clock_size(1); /* large font */
                        g_setting_cntx_p->done_flag = 1;
                        mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
                        cui_menu_close(menu_evt->sender_id);
                        break;

                    case MENU_ID_OP11_HS_DUAL_CLOCK_ON:
                        PhnsetSetDualClockState(1);
                        g_setting_cntx_p->done_flag = 1;
                        mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
                        cui_menu_close(menu_evt->sender_id);
                        break;

                    case MENU_ID_OP11_HS_DUAL_CLOCK_OFF:
                        PhnsetSetDualClockState(0);
                        g_setting_cntx_p->done_flag = 1;
                        mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
                        cui_menu_close(menu_evt->sender_id);
                        break;

#if defined(__MMI_DIALER_SEARCH__)
                    case MENU_ID_OP11_HS_KEYPAD_SEARCH_ON:
                        mmi_dialer_search_set_enable(1);
                        g_setting_cntx_p->done_flag = 1;
                        mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
                        cui_menu_close(menu_evt->sender_id);
                        break;

                    case MENU_ID_OP11_HS_KEYPAD_SEARCH_OFF:
                        mmi_dialer_search_set_enable(0);
                        g_setting_cntx_p->done_flag = 1;
                        mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
                        cui_menu_close(menu_evt->sender_id);
                        break;
#endif

                    default:
                        break;
                }
                break;
            }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                menu_evt = (cui_menu_event_struct *)evt;
                cui_menu_close(menu_evt->sender_id);
            }
            break;


        /**********************/
        /*       Inline CUI Start      */
        /**********************/
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            cui_event_inline_submit_struct * inline_submit_p = (cui_event_inline_submit_struct *)evt;

            cui_inline_get_value(inline_submit_p->sender_id, HS_APP_INLINE_EDITOR, g_setting_cntx_p->my_num_number);
//			if (mmi_wcslen(g_setting_cntx_p->my_num_number) == 0) {
//				break;
//			}
            if (!mmi_hs_is_owner_number_valid(g_setting_cntx_p->my_num_number))
            {
                mmi_popup_property_init(&popup_arg);
                sg_id = mmi_frm_group_get_active_id();
                popup_arg.parent_id = g_mmi_op11_hs32_cntx.lsk_sg_id;
                mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_INVALID_NUMBER), MMI_EVENT_FAILURE, &popup_arg);
//            	mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_INVALID_NUMBER), MMI_EVENT_FAILURE);
            }
            else
            {
            	mmi_more_setting_save_my_number();
            	cui_inline_close(inline_submit_p->sender_id);
            }
        }
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct * inline_abort_p = (cui_event_inline_abort_struct *)evt;
            cui_inline_close(inline_abort_p->sender_id);
        }
        break;

    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *notify_p = (cui_event_inline_notify_struct *)evt;
            if (notify_p->item_id == HS_APP_INLINE_EDITOR)
            {
                if (notify_p->event_type == CUI_INLINE_NOTIFY_TEXT_EMPTY)
                {
                    cui_inline_set_softkey_text(notify_p->sender_id, (U16)notify_p->item_id, MMI_LEFT_SOFTKEY, 0);
                    cui_inline_set_softkey_icon(notify_p->sender_id, (U16)notify_p->item_id, MMI_CENTER_SOFTKEY, 0);
                    cui_inline_set_softkey_text(notify_p->sender_id, (U16)notify_p->item_id, MMI_RIGHT_SOFTKEY, STR_GLOBAL_CANCEL);
                }
                else if (notify_p->event_type == CUI_INLINE_NOTIFY_TEXT_NOT_EMPTY)
                {
                    cui_inline_set_softkey_text(notify_p->sender_id, (U16)notify_p->item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_OK);
                    cui_inline_register_lsk_handler();
                    cui_inline_set_softkey_icon(notify_p->sender_id, (U16)notify_p->item_id, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
                    cui_inline_register_csk_handler();
                    cui_inline_set_softkey_text(notify_p->sender_id, (U16)notify_p->item_id, MMI_RIGHT_SOFTKEY, STR_GLOBAL_CLEAR);
                }
            }
        }
    break;
#endif

        default:
            break;
    }
    return MMI_RET_OK;
}
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__)||defined(__MMI_OP11_HOMESCREEN_0302__) */
