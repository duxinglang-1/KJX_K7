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
 *  HomeScreenOp11V32Gport.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  OP11 HomeScreen version 3.1 & 3.2 global port header file
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef MMI_OP11_HS32_GPORT_H
#define MMI_OP11_HS32_GPORT_H
    
#include "MMI_features.h"
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)

#include "HomeScreenOp11V32Def.h"
#include "custom_mmi_default_value.h"
//#include "FileMgrGProt.h"

// auto add by kw_check begin
#include "MMIDataType.h"
#include "kal_general_types.h"
// auto add by kw_check end 

/************************************************************/
/*															*/
/*			Constants and values Define                 				*/
/*															*/
/************************************************************/
#define MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX  4

#define MMI_OP11_HS32_SHCT_LABEL_STRLEN_MAX  20

#define MMI_OP11_HS32_SHCT_NAME_COUNT_MAX  4
#define MMI_OP11_HS32_SHCT_NAME_STRLEN_MAX  41

#define MMI_OP11_HS32_SHCT_CONTENT_COUNT_MAX  4
#define MMI_OP11_HS32_SHCT_CONTENT_STRLEN_MAX  65

#define MMI_OP11_HS32_SHCT_MAX_FILE_PATH_LEN 260

#define MMI_OP11_HS32_AP_CON_VIP_MAX  5
#define MMI_OP11_HS32_AP_EML_ACCOUNT_MAX  5
#define MMI_OP11_HS32_AP_ALM_MAX  7

#define MMI_OP11_HS32_APP_TOV   (15*1000)


/************************************************************/
/*															*/
/*			App memory related Define                 				*/
/*															*/
/************************************************************/

/*******************************************************************/
/* Default we alloc HS memory from APP ASM                                                  */
/* but you can use one of following two compile option to change the mechanism */
/*******************************************************************/
//#define __MMI_OP11_HS32_MEM_MONOPOLY__
#define __MMI_OP11_HS32_MEM_SHARE_MED__


#define MMI_OP11_HS32_APP_MEM_TOTAL_SIZE (36*1024)
/* worst case: 12*(mmi_op11_hs32_sidebar_struct)+48*(mmi_op11_hs32_shct_struct)+32*(mmi_op11_hs32_shct_data_struct)  */
/* worst size: 12*(18)+48*(6)+32*(970) = 31544 */

// #define MMI_OP11_HS32_APP_MEM_VIP_SCREEN_SIZE (10*1024)

/************************************************************/
/*															*/
/*			UI related values Define                 				       */
/*															*/
/************************************************************/
#if defined(__MMI_MAINLCD_320X240__)
    #define MMI_OP11_HS32_SHCT_LABEL_PIXEL 220
#elif defined(__MMI_MAINLCD_240X320__)
    #define MMI_OP11_HS32_SHCT_LABEL_PIXEL 165
#elif defined(__MMI_MAINLCD_176X220__)
    #define MMI_OP11_HS32_SHCT_LABEL_PIXEL 112
#elif defined(__MMI_MAINLCD_128X160__)
    #define MMI_OP11_HS32_SHCT_LABEL_PIXEL 80
#else
    #define MMI_OP11_HS32_SHCT_LABEL_PIXEL 80
#endif

#define MMI_OP11_HS32_SHCT_LABEL_COUNT_MAX_STRLEN	3
#define MMI_OP11_HS32_SHCT_LABEL_COUNT_MAX	999
#define MMI_OP11_HS32_SHCT_LABEL_COUNT_MAX_STR	    L"999"


#if defined(__MMI_MAINLCD_320X240__)
    #define MMI_OP11_HS32_SHCT_CONTENT_PIXEL 250
#elif defined(__MMI_MAINLCD_240X320__)
    #define MMI_OP11_HS32_SHCT_CONTENT_PIXEL 172
#elif defined(__MMI_MAINLCD_176X220__)
    #define MMI_OP11_HS32_SHCT_CONTENT_PIXEL 128
#elif defined(__MMI_MAINLCD_128X160__)
    #define MMI_OP11_HS32_SHCT_CONTENT_PIXEL 94
#else
    #define MMI_OP11_HS32_SHCT_CONTENT_PIXEL 94
#endif

/************************************************************/
/*															*/
/*			Enum Definne 									*/
/*															*/
/************************************************************/

typedef enum
{
    MMI_OP11_HS32_RESULT_NOT_READY,        /* APP is not ready and will update later */
    MMI_OP11_HS32_RESULT_OK,                     /* APP filled data done */
    MMI_OP11_HS32_RESULT_UPDATE,            /* APP actively update the content */
    MMI_OP11_HS32_RESULT_TYPE_MAX
} mmi_op11_hs32_data_result_enum;

typedef enum
{
    MMI_OP11_HS32_AP_DATA_ADD,              /* e.g. phb add a new VIP contact */
    MMI_OP11_HS32_AP_DATA_REMOVE,        /* e.g. phb delete a VIP contact */
    MMI_OP11_HS32_AP_DATA_CHANGE_TYPE_MAX
} mmi_op11_hs32_ap_data_change_enum;


/************************************************************/
/*															*/
/*			AP concerned Data Structure							*/
/*															*/
/************************************************************/

/* Need AP return's sidebar info structure */
typedef struct
{
    mmi_op11_hs32_data_result_enum result_flag;  /* data flag: ok, not ready, or update*/
    S32 indicator_value;                             /* e.g. sms numbers */
    S32 ap_status;                                          /* for Orange Messager, profile, music player */
//    S32   sync_data_count;           /* for PHB, Email check histoy if available */
    void   *sync_data;           /* for PHB, Email, Alarm check history */
}mmi_op11_hs32_sidebar_query_info_struct;


/* Shortcut data structure, For AP fill data */
typedef struct
{
    mmi_op11_hs32_data_result_enum result_flag;                       /* data flag: ok, not ready, or update*/
    S32 query_index;                                                                        /* only for phb, email, alarm to query data */
    WCHAR shct_label[MMI_OP11_HS32_SHCT_LABEL_STRLEN_MAX+1];    /* only for PHB fill VIP contact name; email fill account name */
    S32 item_count;                                                                             /*  e.g. sms numbers */
    S32 item_uid[MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX];             /* e.g. sms unique id, now just for view latest sms, but future extensibility */
    S8 item_flag[MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX];            /* e.g. whether need this sms contents flag */
//    U16 item_icon[MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX];                 /*  e.g. sms icon  */
    WCHAR item_name[MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX][MMI_OP11_HS32_SHCT_NAME_STRLEN_MAX+1];  /* e.g. sms sender names  */
    MYTIME item_time[MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX];        /* e.g. sms received times  */
    WCHAR item_content[MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX][MMI_OP11_HS32_SHCT_CONTENT_STRLEN_MAX+1]; /* e.g. sms contents */
//    S8 power_status;                                                                    /* only for BT, Flight Mode assign status */
//    S8 visible_status;                                                                    /* only for BT assign visible status */
//    S8 file_path_flag;                                        /* only for PHB fill contact pic path */
//    WCHAR* file_path;                                        /* only for PHB fill contact pic path */
}mmi_op11_hs32_shct_data_struct;



/************************************************************/
/*															*/
/*			Need AP help implement function prototype define      	*/
/*															*/
/************************************************************/

/* Function prototype: HS query AP sidebar info function type. */
typedef void (*mmi_op11_hs32_query_sidebar_func_t)(S32 sidebar_id, S32 indctr_id);


/* Function prototype: HS get AP shortcut data function type. */
typedef void (*mmi_op11_hs32_get_shct_func_t)(S32 sidebar_id,S32 shct_id, void *shct_data_p);
//typedef void (*mmi_op11_hs32_get_shct_func_t)(S32 sidebar_id,S32 shct_id, mmi_op11_hs32_shct_data_struct *shct_data_p);


/* Function prototype: APs indicator select callback function type. */
typedef void (*mmi_op11_hs32_indctr_cb_func_t)(void);


/* Function prototype: APs shortcut select function type. */
typedef void (*mmi_op11_hs32_shct_cb_func_t)(void);


/* Function prototype: APs shortcut select function(with input parameter) type. */
typedef void (*mmi_op11_hs32_shct_cb_parm_func_t)(S32 index);


/************************************************************/
/*															*/
/*			external functions 									*/
/*															*/
/************************************************************/
/* Venus home screen context structure: */

extern void mmi_op11_hs32_update_idle_text(WCHAR *network_name);

/* for APs return sidebar info  */
extern void mmi_op11_hs32_answer_sidebar(
                S32 sidebar_id, 
                S32 indctr_id, 
                mmi_op11_hs32_sidebar_query_info_struct *sidebar_answer_p);


/* for APs return shct data,  if AP fill data not immediately, please verify the pointer first   */
extern void mmi_op11_hs32_answer_shct_data(
                S32 sidebar_id, 
                S32 shct_id, 
                mmi_op11_hs32_shct_data_struct *shct_data_p);


/* for APs get data pointer (if retun NULL: means may leave HomeScreen, or  user already delete this sidebar, so no need to fill data.) */
extern mmi_op11_hs32_shct_data_struct* mmi_op11_hs32_get_shct_data_pointer(S32 sidebar_id, S32 shct_id);


/* for APs verify data buffer valid (if retun MMI_FALSE: means may leave HomeScreen, or  user already delete this sidebar, so no need to fill data.) */
MMI_BOOL mmi_op11_hs32_is_shct_data_buffer_valid(
                         S32 sidebar_id, 
                         S32 shct_id, 
                         mmi_op11_hs32_shct_data_struct *shct_data_p);


/* only for email get shortcut id by HS email account index, if return -1: means user cleard this HS account */
extern S32 mmi_op11_hs32_email_get_shct_id_by_account(S32 index);

extern void mmi_op11_hs32_get_eml_account_after_select(S32 account_id);

    

extern void mmi_op11_hs32_init(void);

extern void mmi_op11_hs32_exit_homescreen(void);

extern void mmi_op11_hs32_entry_homescreen(void);

extern void mmi_op11_hs32_con_vip_update(void);
extern void mmi_op11_hs32_cnx_bt_update(void);
extern void mmi_mus_update_op11_hs32_sidebar_info(void);
extern void mmi_op11_hs32_pro_update(void);

extern MMI_BOOL mmi_op11_hs32_is_proprietary_sim(void);
extern MMI_BOOL mmi_op11_hs32_is_enable(void);
extern void mmi_op11_hs32_discard_history(void);
extern void mmi_op11_hs32_redraw_homescreen(void);
extern void mmi_op11_hs32_pre_fetch_history(void);
extern void mmi_op11_hs32_activate_by_ssc(void);
extern void mmi_op11_hs32_reset_screen(void);

extern void mmi_op11_hs32_at_delete_vip_screen(void);

extern mmi_ret mmi_op11_hs32_proc_gpio_dimming(mmi_event_struct* para);

extern void mmi_op11_hs32_delete_eml_account_scr(void);

#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#endif /* MMI_OP11_HS32_GPORT_H  */

