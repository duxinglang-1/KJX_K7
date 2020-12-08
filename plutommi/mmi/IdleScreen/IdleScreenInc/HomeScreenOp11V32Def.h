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
 *  OP11 HomeScreen version 3.1 & 3.2 enum define header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef MMI_OP11_HS32_DEF_H
#define MMI_OP11_HS32_DEF_H
    
#include "MMI_features.h"
    
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)


#if defined(__MMI_IMPS__)
/* under construction !*/
#endif
#define __MMI_OP11_HS32_PRO__
#define __MMI_OP11_HS32_ALM__
#define __MMI_OP11_HS32_CAL__
#define __MMI_OP11_HS32_CNX__
#define __MMI_OP11_HS32_DST__
#define __MMI_OP11_HS32_STK__

#if defined(BROWSER_SUPPORT)
    #define __MMI_OP11_HS32_OWD__
#endif

#if defined(__MMI_EMAIL__)
#define __MMI_OP11_HS32_EML__
#endif

#if defined(__MMI_CAMCORDER__) ||defined(__MMI_CAMERA__)
#define __MMI_OP11_HS32_PHO__
#define __MMI_OP11_HS32_TPH__
#endif

#if defined(__MMI_MEDIA_PLAYER__)
#define __MMI_OP11_HS32_MUS__
#endif

#if defined(__MMI_BT_SUPPORT__)
#define __MMI_OP11_HS32_CNX_BT__
#endif

#if defined(__MMI_WLAN_FEATURES__)
#define __MMI_OP11_HS32_CNX_WIFI__
#endif

#define __MMI_OP11_HS32_ALM_NEW_UE__

/**********************************************************************
 * Total AP enum (sidebar id enum)
 **********************************************************************/
typedef enum
{
    MMI_OP11_HS32_AP_CLL,         /* Call  0*/
    MMI_OP11_HS32_AP_CON,        /* Contacts (PHB) 1*/
    MMI_OP11_HS32_AP_MES,        /* Message  2*/
    MMI_OP11_HS32_AP_EML,        /* Email  3*/
    MMI_OP11_HS32_AP_OMR,        /* Orange Messenger  4*/
    MMI_OP11_HS32_AP_OWD,       /* Orange World (WAP)  5*/
    MMI_OP11_HS32_AP_PRO,        /* Profile  6*/
    MMI_OP11_HS32_AP_ALM,        /* Alarms  7*/
    MMI_OP11_HS32_AP_CAL,         /* Calendar  8*/
    MMI_OP11_HS32_AP_MUS,        /* Music  9*/
    MMI_OP11_HS32_AP_PHO,        /* Photography  10*/
    MMI_OP11_HS32_AP_CNX,        /* Connections (BT, Flight Mode)  11*/
    MMI_OP11_HS32_AP_DST,        /* Device Status  12*/
    MMI_OP11_HS32_AP_STK,        /* SIM Toolkit  13*/
    MMI_OP11_HS32_AP_TPH,       /* Take Photo 14 */
    MMI_OP11_HS32_AP_VIP,       /* VIP Contacts 15 */
    MMI_OP11_HS32_AP_USCON,       /* AP reserved (PHB for example) 16 */
    
    MMI_OP11_HS32_AP_TYPE_MAX
} mmi_op11_hs32_sidebar_id_enum;


/**********************************************************************
 * AP Call [CLL]
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_CLL  mmi_clog_op11_hs32_sb_check_num

/* indicator enum */
typedef enum
{
//    MMI_OP11_HS32_INDCTR_CLL_NEW_VOICEMAIL,   /* due to we implement ROW Network Voicemail in spec  */
    MMI_OP11_HS32_INDCTR_CLL_MISSED_VOICECALL,
//    MMI_OP11_HS32_INDCTR_CLL_MISSED_VIDEOCALL,  /* due to we don't support video call yet.  */
    MMI_OP11_HS32_INDCTR_CLL_TYPE_MAX
} mmi_op11_hs32_indctr_cll_type_enum;

/* indicator selected callback function table */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_CLL \
{ mmi_clog_mclt_launch \
}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_CLL_VOICEMAIL,    /* No data, status get from indicator number */
    MMI_OP11_HS32_SHCT_CLL_CALL_LOG,      /* Need query data, "Missed calls (n)" */
    MMI_OP11_HS32_SHCT_CLL_CALL_PLAN,     /* no data  */
    MMI_OP11_HS32_SHCT_CLL_TYPE_MAX
} mmi_op11_hs32_shct_cll_type_enum;

#define OP11_HS32_SHCT_STR_LIST_CLL \
    STR_ID_OP11_HS32_CLL_VOICEMAIL,  \
    STR_ID_OP11_HS32_CLL_CALL_LOG,   \
    STR_ID_OP11_HS32_CLL_CALL_PLAN

/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_CLL \
{ mmi_op11_hs32_get_voicemail_shct_data,  \
   mmi_clog_op11_hs32_shct_query_data,  \
   NULL     \
}

/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_CLL \
{ DialVoiceMail, \
   NULL, \
   mmi_ss_ussd_request_from_menu  \
}


/**********************************************************************
 * AP Contacts [CON] (dynamic shortcuts)
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_CON  mmi_op11_hs32_query_sidebar_con

/*  Do not have indicator */
/* No indicator selected callback function table */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_CON {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_CON_LIST,     /* no data  */
    MMI_OP11_HS32_SHCT_CON_SET_VIP,      /* no data  */
    MMI_OP11_HS32_SHCT_CON_VIP1,
    MMI_OP11_HS32_SHCT_CON_VIP2,
    MMI_OP11_HS32_SHCT_CON_VIP3,
    MMI_OP11_HS32_SHCT_CON_VIP4,
    MMI_OP11_HS32_SHCT_CON_VIP5,
    MMI_OP11_HS32_SHCT_CON_EDIT_VIP,    /* has data  */
    MMI_OP11_HS32_SHCT_CON_TYPE_MAX
} mmi_op11_hs32_shct_con_type_enum;

#define OP11_HS32_SHCT_STR_LIST_CON \
    STR_ID_OP11_HS32_CON_CONTACT_LIST,  \
    STR_ID_OP11_HS32_CON_SET_VIP,   \
    STR_ID_OP11_HS32_CON_VIP_1,   \
    STR_ID_OP11_HS32_CON_VIP_2,   \
    STR_ID_OP11_HS32_CON_VIP_3,   \
    STR_ID_OP11_HS32_CON_VIP_4,   \
    STR_ID_OP11_HS32_CON_VIP_5,   \
    STR_ID_OP11_HS32_CON_EDIT_VIP

/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_CON \
{  NULL,   \
    NULL,  \
    mmi_op11_hs32_get_shct_data_con_vip,     \
    mmi_op11_hs32_get_shct_data_con_vip,     \
    mmi_op11_hs32_get_shct_data_con_vip,     \
    mmi_op11_hs32_get_shct_data_con_vip,     \
    mmi_op11_hs32_get_shct_data_con_vip,     \
    NULL    \
}

/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_CON \
{ mmi_phb_launch,  \
   mmi_op11_hs32_enter_set_con_vip_screen_group,  \
   NULL,  \
   NULL,  \
   NULL,  \
   NULL,  \
   NULL,  \
   mmi_op11_hs32_enter_edit_con_vip_screen_group   \
}


/**********************************************************************
 * AP Message [MES] 
 **********************************************************************/
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_MES  mmi_op11_hs32_query_sidebar_mes

/* indicator type enum */
typedef enum
{
    MMI_OP11_HS32_INDCTR_MES_NEW_SMS,   /* SMS please use this indicator id to answer HS siderbar info */
    MMI_OP11_HS32_INDCTR_MES_NEW_MMS,   /* MMS please use this indicator id to answer HS siderbar info */
    MMI_OP11_HS32_INDCTR_MES_TYPE_MAX
} mmi_op11_hs32_indctr_mes_type_enum;

/* indicator selected callback table */
/* e.g. mmi_um_pre_entry_sms_inbox, mmi_umms_pre_entry_inbox */

#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_MES \
{  mmi_um_launch_inbox_with_sms_only,  \
    mmi_um_launch_inbox_with_mms_only    \
}

/* shortcut type enum */
typedef enum
{
#ifdef __MMI_UNIFIED_COMPOSER__
    MMI_OP11_HS32_SHCT_MES_WRITE_MES,   /* if defined UC, will only one UC shortcut to write message */
#else    
    MMI_OP11_HS32_SHCT_MES_WRITE_SMS,   /* if not defined UC,  please provide HS write sms entry func hdlr */
    MMI_OP11_HS32_SHCT_MES_WRITE_MMS,   /* if not defined UC,  please provide HS write mms entry func hdlr */
#endif
    MMI_OP11_HS32_SHCT_MES_INBOX,    /* SMS and MMS update data please use mmi_op11_hs32_shct_mes_temp_buffer_enum type, do not use this id */

    MMI_OP11_HS32_SHCT_MES_TYPE_MAX
} mmi_op11_hs32_shct_mes_type_enum;

#ifdef __MMI_UNIFIED_COMPOSER__
#define  OP11_HS32_SHCT_STR_LIST_MES    \
    STR_ID_OP11_HS32_MES_WRITE_MSG,       \
    STR_ID_OP11_HS32_MES_INBOX
#else
#define  OP11_HS32_SHCT_STR_LIST_MES    \
    STR_ID_OP11_HS32_MES_WRITE_TXT_MSG,   \
    STR_ID_OP11_HS32_MES_WRITE_PIC_MSG,   \
    STR_ID_OP11_HS32_MES_INBOX
#endif

/* shortcut data get func table */
#ifdef __MMI_UNIFIED_COMPOSER__
#define MMI_OP11_HS32_SHCT_GET_FUNCT_MES \
{  NULL,    \
    mmi_op11_hs32_get_shct_data_mes     \
}
#else
#define MMI_OP11_HS32_SHCT_GET_FUNCT_MES \
{  NULL,    \
    NULL,     \
    mmi_op11_hs32_get_shct_data_mes     \
}
#endif

/* shortcut selected callback table */
#ifdef __MMI_UNIFIED_COMPOSER__
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_MES \
{ mmi_uc_pre_entry_write_msg,  \
   mmi_um_entry_inbox   \
}
#else
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_MES \
{ mmi_op11_hs32_enter_write_sms_screen,  \
  mmi_uc_pre_entry_write_msg,  \
  mmi_um_entry_inbox   \
}
#endif

/* shortcut temp buffer enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_MES_NEW_SMS,     /* SMS please use this shortcut id to answer HS shortcut data */
    MMI_OP11_HS32_SHCT_MES_NEW_MMS,     /* MMS please use this shortcut id to answer HS shortcut data */
    MMI_OP11_HS32_SHCT_MES_NEW_TYPE_MAX
} mmi_op11_hs32_shct_mes_temp_buffer_enum;


#if defined(__MMI_OP11_HS32_EML__)
/**********************************************************************
 * AP Email [EML] (dynamic shortcuts)
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_EML  mmi_email_hs_query_sidebar_info

/* sidebar info update notify enum */
typedef enum
{
    MMI_OP11_HS32_EML_NOTIFY_INDICATOR    = 0x01,   /* email indicator: new emails number */
    MMI_OP11_HS32_EML_NOTIFY_SYNC_ACCOUNT = 0x02,   /* sync_data: email return account array to HS */
    MMI_OP11_HS32_EML_NOTIFY_ALL       = 0x03              /* when need update both indicator value and email account */
} mmi_op11_hs32_sidebar_notify_eml_enum;

/* indicator type enum */
typedef enum
{
    MMI_OP11_HS32_INDCTR_EML_NEW_EMAIL,
    MMI_OP11_HS32_INDCTR_EML_TYPE_MAX
} mmi_op11_hs32_indctr_eml_type_enum;


/* indicator highlight callback table */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_EML   \
{  mmi_email_hs_entry_inbox_select    \
}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_EML_SET_ACCOUNT,      /* when no account exist */
    MMI_OP11_HS32_SHCT_EML_WRITE_EMAIL,      /* when only 1 account: will at first place, entry editor screen; when 2 or more accounts: entry account select screen */
    MMI_OP11_HS32_SHCT_EML_ACCOUNT1_NEWEMAIL,    /* list this account's new emails or No New Email */
    MMI_OP11_HS32_SHCT_EML_ACCOUNT2_NEWEMAIL,
    MMI_OP11_HS32_SHCT_EML_ACCOUNT3_NEWEMAIL,
    MMI_OP11_HS32_SHCT_EML_ACCOUNT4_NEWEMAIL,
    MMI_OP11_HS32_SHCT_EML_ACCOUNT5_NEWEMAIL,
    MMI_OP11_HS32_SHCT_EML_EDIT_ACCOUNT,      /* when 1 or more account exist */

    MMI_OP11_HS32_SHCT_EML_TYPE_MAX
} mmi_op11_hs32_shct_eml_type_enum;

#define  OP11_HS32_SHCT_STR_LIST_EML    \
    STR_ID_OP11_HS32_EML_SET_ACCOUNT,   \
    STR_ID_OP11_HS32_EML_WRITE_EMAIL,   \
    STR_ID_OP11_HS32_EML_ACCOUNT_1,   \
    STR_ID_OP11_HS32_EML_ACCOUNT_2,   \
    STR_ID_OP11_HS32_EML_ACCOUNT_3,   \
    STR_ID_OP11_HS32_EML_ACCOUNT_4,   \
    STR_ID_OP11_HS32_EML_ACCOUNT_5,   \
    STR_ID_OP11_HS32_EML_EDIT_ACCOUNT


/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_EML \
{ NULL,  \
   NULL,  \
   mmi_email_hs_query_email_shct_info,  \
   mmi_email_hs_query_email_shct_info,  \
   mmi_email_hs_query_email_shct_info,  \
   mmi_email_hs_query_email_shct_info,  \
   mmi_email_hs_query_email_shct_info,  \
   NULL  \
}

/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_EML \
{ mmi_op11_hs32_enter_set_eml_account_screen_group, \
   mmi_email_hs_entry_comp_select, \
   NULL, \
   NULL, \
   NULL, \
   NULL, \
   NULL, \
   mmi_op11_hs32_enter_edit_eml_account_screen_group  \
}
/**********************************************************************/
#else
/**********************************************************************/
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_EML  NULL

/* sidebar info update notify enum */
typedef enum
{
    MMI_OP11_HS32_EML_NOTIFY_INDICATOR    = 0x01,   /* email indicator: new emails number */
    MMI_OP11_HS32_EML_NOTIFY_SYNC_ACCOUNT = 0x02,   /* sync_data: email return account array to HS */
    MMI_OP11_HS32_EML_NOTIFY_ALL       = 0x03              /* when need update both indicator value and email account */
} mmi_op11_hs32_sidebar_notify_eml_enum;
/* indicator type enum */
typedef enum
{
    MMI_OP11_HS32_INDCTR_EML_NEW_EMAIL,
    MMI_OP11_HS32_INDCTR_EML_TYPE_MAX
} mmi_op11_hs32_indctr_eml_type_enum;
/* indicator highlight callback table */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_EML   {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_EML_SET_ACCOUNT,      /* when no account exist */
    MMI_OP11_HS32_SHCT_EML_WRITE_EMAIL,      /* when only 1 account: will at first place, entry editor screen; when 2 or more accounts: entry account select screen */
    MMI_OP11_HS32_SHCT_EML_ACCOUNT1_NEWEMAIL,    /* list this account's new emails or No New Email */
    MMI_OP11_HS32_SHCT_EML_ACCOUNT2_NEWEMAIL,
    MMI_OP11_HS32_SHCT_EML_ACCOUNT3_NEWEMAIL,
    MMI_OP11_HS32_SHCT_EML_ACCOUNT4_NEWEMAIL,
    MMI_OP11_HS32_SHCT_EML_ACCOUNT5_NEWEMAIL,
    MMI_OP11_HS32_SHCT_EML_EDIT_ACCOUNT,      /* when 1 or more account exist */

    MMI_OP11_HS32_SHCT_EML_TYPE_MAX
} mmi_op11_hs32_shct_eml_type_enum;
#define  OP11_HS32_SHCT_STR_LIST_EML    NULL

#define MMI_OP11_HS32_SHCT_GET_FUNCT_EML {NULL}

#define MMI_OP11_HS32_SHCT_SEL_FUNCT_EML {NULL}
/**********************************************************************/
#endif
/**********************************************************************/


#if defined(__MMI_OP11_HS32_OMR__)
/**********************************************************************
 * AP Orange Messenger [OMR] (dynamic ap status, static shortcuts)
 **********************************************************************/
/* sidebar info query func table */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_OMR  mmi_op11_hs32_query_imps_sidebar_info 

/* ap status enum */
typedef enum
{
    MMI_OP11_HS32_STATUS_OMR_OFF,
    MMI_OP11_HS32_STATUS_OMR_AVAIL,
    MMI_OP11_HS32_STATUS_OMR_INVISI,
    MMI_OP11_HS32_STATUS_OMR_BUSY,
    MMI_OP11_HS32_STATUS_OMR_AWAY,
    MMI_OP11_HS32_STATUS_OMR_TYPE_MAX
} mmi_op11_hs32_status_omr_type_enum;

/* sidebar info update notify enum */
typedef enum
{
    MMI_OP11_HS32_OMR_NOTIFY_INDICATOR    = 0x01,   /* when need update indicator value */
    MMI_OP11_HS32_OMR_NOTIFY_AP_STATUS    = 0x02,   /* when need update OM messenger status: available, unavailable  */
    MMI_OP11_HS32_OMR_NOTIFY_ALL       = 0x03             /* when need update both indicator value and OM messenger status */
} mmi_op11_hs32_sidebar_notify_omr_enum;

/* indicator type enum */
typedef enum
{
    MMI_OP11_HS32_INDCTR_OMR_NEW_CONVER,

    MMI_OP11_HS32_INDCTR_OMR_TYPE_MAX
} mmi_op11_hs32_indctr_omr_type_enum;

/* indicator selected callback function table */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_OMR   \
{  mmi_imps_entry_conversation    \
}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_OMR_OM,           /* Orange Messenger, no content display */
    MMI_OP11_HS32_SHCT_OMR_CV,           /*OM Conversation: 0: "Conversations"; 1: "View conversation"; 2 or more: "Conversations(n)" */
    MMI_OP11_HS32_SHCT_OMR_CT,           /* OM Contacts: "Contacts online (n)" */
    MMI_OP11_HS32_SHCT_OMR_SP,          /* Set OM Presence: "Set presence" */
    MMI_OP11_HS32_SHCT_OMR_TYPE_MAX
} mmi_op11_hs32_shct_omr_type_enum;

#define  OP11_HS32_SHCT_STR_LIST_OMR    \
    STR_ID_OP11_HS32_OMR_OM,   \
    STR_ID_OP11_HS32_OMR_CV,   \
    STR_ID_OP11_HS32_OMR_CT,   \
    STR_ID_OP11_HS32_OMR_SP

/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_OMR \
{ NULL,  \
   mmi_op11_hs32_get_imps_cv_shct_data,  \
   mmi_op11_hs_get_imps_ct_shct_data,  \
   mmi_op11_hs32_get_imps_sp_shct_data   \
}

/* shortcut highlight callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_OMR \
{ mmi_imps_launch, \
   mmi_imps_entry_conversation, \
   mmi_imps_launch, \
   mmi_imps_pre_entry_presence  \
}
/**********************************************************************/
#else
/**********************************************************************/
/* sidebar info query func table */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_OMR  NULL 

/* ap status enum */
typedef enum
{
    MMI_OP11_HS32_STATUS_OMR_OFF,
    MMI_OP11_HS32_STATUS_OMR_AVAIL,
    MMI_OP11_HS32_STATUS_OMR_INVISI,
    MMI_OP11_HS32_STATUS_OMR_BUSY,
    MMI_OP11_HS32_STATUS_OMR_AWAY,
    MMI_OP11_HS32_STATUS_OMR_TYPE_MAX
} mmi_op11_hs32_status_omr_type_enum;

/* sidebar info update notify enum */
typedef enum
{
    MMI_OP11_HS32_OMR_NOTIFY_INDICATOR    = 0x01,   /* when need update indicator value */
    MMI_OP11_HS32_OMR_NOTIFY_AP_STATUS    = 0x02,   /* when need update OM messenger status: available, unavailable  */
    MMI_OP11_HS32_OMR_NOTIFY_ALL       = 0x03             /* when need update both indicator value and OM messenger status */
} mmi_op11_hs32_sidebar_notify_omr_enum;

/* indicator type enum */
typedef enum
{
    MMI_OP11_HS32_INDCTR_OMR_NEW_CONVER,

    MMI_OP11_HS32_INDCTR_OMR_TYPE_MAX
} mmi_op11_hs32_indctr_omr_type_enum;

#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_OMR   {NULL}
/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_OMR_OM,           /* Orange Messenger, no content display */
    MMI_OP11_HS32_SHCT_OMR_CV,           /*OM Conversation: 0: "Conversations"; 1: "View conversation"; 2 or more: "Conversations(n)" */
    MMI_OP11_HS32_SHCT_OMR_CT,           /* OM Contacts: "Contacts online (n)" */
    MMI_OP11_HS32_SHCT_OMR_SP,          /* Set OM Presence: "Set presence" */
    MMI_OP11_HS32_SHCT_OMR_TYPE_MAX
} mmi_op11_hs32_shct_omr_type_enum;
#define  OP11_HS32_SHCT_STR_LIST_OMR    NULL
#define MMI_OP11_HS32_SHCT_GET_FUNCT_OMR {NULL}
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_OMR {NULL}
/**********************************************************************/
#endif
/**********************************************************************/


#if defined(__MMI_OP11_HS32_OWD__)
/**********************************************************************
 * AP Orange World [OWD] (static shortcuts)
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_OWD NULL 

/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_OWD {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_OWD_OW,          /* Orange World */
    MMI_OP11_HS32_SHCT_OWD_BK1,         /*Orange World default Bookmark 1 */
    MMI_OP11_HS32_SHCT_OWD_BK2,         /*Orange World default Bookmark 2 */
    MMI_OP11_HS32_SHCT_OWD_BK3,         /*Orange World default Bookmark 3 */
    MMI_OP11_HS32_SHCT_OWD_EU,          /* Enter web address */
    MMI_OP11_HS32_SHCT_OWD_MB,          /* "My bookmarks (n)" */
    MMI_OP11_HS32_SHCT_OWD_TYPE_MAX
} mmi_op11_hs32_shct_owd_type_enum;

#define  OP11_HS32_SHCT_STR_LIST_OWD    \
    STR_ID_OP11_HS32_OWD_OW,   \
    STR_ID_OP11_HS32_OWD_BK1,   \
    STR_ID_OP11_HS32_OWD_BK2,   \
    STR_ID_OP11_HS32_OWD_BK3,   \
    STR_ID_OP11_HS32_OWD_EU,   \
    STR_ID_OP11_HS32_OWD_MB


/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_OWD \
{ NULL,  \
   mmi_op11_hs32_get_shct_data_owd,  \
   mmi_op11_hs32_get_shct_data_owd,  \
   mmi_op11_hs32_get_shct_data_owd,  \
   NULL,  \
   mmi_op11_hs32_get_shct_data_owd_mb     \
}

/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_OWD \
{ wap_internet_key_hdlr, \
   NULL, \
   NULL, \
   NULL, \
   mmi_brw_enter_web_address, \
   mmi_brw_enter_user_defined_bookmark_list  \
}

/**********************************************************************/
#else
/**********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_OWD NULL 
/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_OWD {NULL}
/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_OWD_OW,          /* Orange World */
    MMI_OP11_HS32_SHCT_OWD_BK1,         /*Orange World default Bookmark 1 */
    MMI_OP11_HS32_SHCT_OWD_BK2,         /*Orange World default Bookmark 2 */
    MMI_OP11_HS32_SHCT_OWD_BK3,         /*Orange World default Bookmark 3 */
    MMI_OP11_HS32_SHCT_OWD_EU,          /* Enter web address */
    MMI_OP11_HS32_SHCT_OWD_MB,          /* "My bookmarks (n)" */
    MMI_OP11_HS32_SHCT_OWD_TYPE_MAX
} mmi_op11_hs32_shct_owd_type_enum;
#define  OP11_HS32_SHCT_STR_LIST_OWD    NULL
/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_OWD {NULL}
/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_OWD {NULL}
/**********************************************************************/
#endif
/**********************************************************************/


#if defined(__MMI_OP11_HS32_PRO__)
/**********************************************************************
 * AP Profile [PRO] (dynamic ap status, only 1 shortcut)
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_PRO  mmi_op11_hs32_query_sidebar_pro

/* ap status enum */
typedef enum
{
    MMI_OP11_HS32_STATUS_PRO_NON_SILENT,
    MMI_OP11_HS32_STATUS_PRO_SILENT,
    MMI_OP11_HS32_STATUS_PRO_TYPE_MAX
} mmi_op11_hs32_status_pro_type_enum;

/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_PRO {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_PRO,           /* only 1 shortcut*/
    MMI_OP11_HS32_SHCT_PRO_TYPE_MAX
} mmi_op11_hs32_shct_pro_type_enum;

#define  OP11_HS32_SHCT_STR_LIST_PRO    \
    STR_ID_OP11_HS32_PRO

/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_PRO {NULL}

/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_PRO \
{ mmi_op11_hs32_toggle_pro_shct \
}
/**********************************************************************/
#else
/**********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_PRO  NULL
/* ap status enum */
typedef enum
{
    MMI_OP11_HS32_STATUS_PRO_NON_SILENT,
    MMI_OP11_HS32_STATUS_PRO_SILENT,
    MMI_OP11_HS32_STATUS_PRO_TYPE_MAX
} mmi_op11_hs32_status_pro_type_enum;
/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_PRO,           /* only 1 shortcut*/
    MMI_OP11_HS32_SHCT_PRO_TYPE_MAX
} mmi_op11_hs32_shct_pro_type_enum;

/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_PRO {NULL}
#define  OP11_HS32_SHCT_STR_LIST_PRO    NULL
/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_PRO {NULL}
/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_PRO {NULL}
/**********************************************************************/
#endif
/**********************************************************************/


#if defined(__MMI_OP11_HS32_ALM__)
/**********************************************************************
 * AP Alarms [ALM] (dynamic shortcuts; no need  to reorder shortcuts)
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_ALM  mmi_alm_query_sidebar_info

/* ap status enum */
/* ALM_IE_001:O will not implement */

 /* Current Sidebar view Do not have indicator; But future expanded view need indicator */
typedef enum
{
    MMI_OP11_HS32_INDCTR_ALM,
    MMI_OP11_HS32_INDCTR_ALM_TYPE_MAX
} mmi_op11_hs32_indctr_alm_type_enum;

#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_ALM {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_ALM_NO,           /* "Alarms" -- No alarms set */
    MMI_OP11_HS32_SHCT_ALM_1,           /* "Alarm 1" */
    MMI_OP11_HS32_SHCT_ALM_2,           /* "Alarm 2" */
    MMI_OP11_HS32_SHCT_ALM_3,           /* "Alarm 3" */
    MMI_OP11_HS32_SHCT_ALM_4,           /* "Alarm 4" */
    MMI_OP11_HS32_SHCT_ALM_5,           /* "Alarm 5" */
    MMI_OP11_HS32_SHCT_ALM_6,           /* "Alarm 6" */
    MMI_OP11_HS32_SHCT_ALM_7,           /* "Alarm 7" */
    MMI_OP11_HS32_SHCT_ALM_TYPE_MAX
} mmi_op11_hs32_shct_alm_type_enum;

#define  OP11_HS32_SHCT_STR_LIST_ALM    \
    STR_ID_OP11_HS32_ALM_ALARMS

/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_ALM \
{ NULL,  \
   mmi_alm_hs32_get_alm_shct_data,  \
   mmi_alm_hs32_get_alm_shct_data,  \
   mmi_alm_hs32_get_alm_shct_data,  \
   mmi_alm_hs32_get_alm_shct_data,  \
   mmi_alm_hs32_get_alm_shct_data,  \
   mmi_alm_hs32_get_alm_shct_data,  \
   mmi_alm_hs32_get_alm_shct_data   \
}

/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_ALM \
{ mmi_alm_entry_alm_list, \
   NULL, \
   NULL, \
   NULL, \
   NULL, \
   NULL, \
   NULL, \
   NULL  \
}
/**********************************************************************/
#else
/**********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_ALM  NULL
typedef enum
{
    MMI_OP11_HS32_INDCTR_ALM,
    MMI_OP11_HS32_INDCTR_ALM_TYPE_MAX
} mmi_op11_hs32_indctr_alm_type_enum;
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_ALM {NULL}
/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_ALM_NO,           /* "Alarms" -- No alarms set */
    MMI_OP11_HS32_SHCT_ALM_1,           /* "Alarm 1" */
    MMI_OP11_HS32_SHCT_ALM_2,           /* "Alarm 2" */
    MMI_OP11_HS32_SHCT_ALM_3,           /* "Alarm 3" */
    MMI_OP11_HS32_SHCT_ALM_4,           /* "Alarm 4" */
    MMI_OP11_HS32_SHCT_ALM_5,           /* "Alarm 5" */
    MMI_OP11_HS32_SHCT_ALM_6,           /* "Alarm 6" */
    MMI_OP11_HS32_SHCT_ALM_7,           /* "Alarm 7" */
    MMI_OP11_HS32_SHCT_ALM_TYPE_MAX
} mmi_op11_hs32_shct_alm_type_enum;
#define  OP11_HS32_SHCT_STR_LIST_ALM    NULL
#define MMI_OP11_HS32_SHCT_GET_FUNCT_ALM {NULL}
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_ALM {NULL}
/**********************************************************************/
#endif
/**********************************************************************/


#if defined(__MMI_OP11_HS32_CAL__)
/**********************************************************************
 * AP Calendar [CAL] 
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_CAL  mmi_tdl_op11_hs32_query_sidebar_info

/* ap status enum */
/* CAL_IE_001:O will not implement */

/* indicator type enum */
typedef enum
{
    MMI_OP11_HS32_INDCTR_CAL,
    MMI_OP11_HS32_INDCTR_CAL_TYPE_MAX
} mmi_op11_hs32_indctr_cal_type_enum;

/* indicator highlight callback table */ /* mmi_clndr_entry_display_today_task  */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_CAL   \
{  mmi_clndr_op11_hs32_entry_today    \
}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_CAL_CL,           /* show today calendar: 0: "No calendar events; Today (n) */
    MMI_OP11_HS32_SHCT_CAL_TW,           /* show this week calendar "This week (n)" */
    MMI_OP11_HS32_SHCT_CAL_CA,           /* Create Appointment e.g."New appointment", no content */
    MMI_OP11_HS32_SHCT_CAL_TYPE_MAX
} mmi_op11_hs32_shct_cal_type_enum;

#define  OP11_HS32_SHCT_STR_LIST_CAL    \
    STR_ID_OP11_HS32_CAL_CL,   \
    STR_ID_OP11_HS32_CAL_TW,   \
    STR_ID_OP11_HS32_CAL_CA

/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_CAL \
{ mmi_tdl_op11_hs32_get_today_shct_data,  \
   mmi_tdl_op11_hs32_get_thweek_shct_data,  \
   NULL     \
}

/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_CAL \
{ NULL, \
   mmi_clndr_op11_hs32_entry_thweek, \
   mmi_clndr_op11_hs32_entry_add  \
}
/**********************************************************************/
#else
/**********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_CAL  NULL
typedef enum
{
    MMI_OP11_HS32_INDCTR_CAL,
    MMI_OP11_HS32_INDCTR_CAL_TYPE_MAX
} mmi_op11_hs32_indctr_cal_type_enum;
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_CAL   NULL
/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_CAL_CL,           /* show today calendar: 0: "No calendar events; Today (n) */
    MMI_OP11_HS32_SHCT_CAL_TW,           /* show this week calendar "This week (n)" */
    MMI_OP11_HS32_SHCT_CAL_CA,           /* Create Appointment e.g."New appointment", no content */
    MMI_OP11_HS32_SHCT_CAL_TYPE_MAX
} mmi_op11_hs32_shct_cal_type_enum;
#define  OP11_HS32_SHCT_STR_LIST_CAL    {NULL}
#define MMI_OP11_HS32_SHCT_GET_FUNCT_CAL {NULL}
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_CAL {NULL}
/**********************************************************************/
#endif
/**********************************************************************/


#if defined(__MMI_OP11_HS32_MUS__)
/**********************************************************************
 * AP Music [MUS] 
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_MUS  mmi_op11_hs32_query_mus_sidebar_info 

/* ap status enum */
typedef enum
{
    MMI_OP11_HS32_STATUS_MUS_STANDARD,                /* playback not in progress, no new tracks available*/
    MMI_OP11_HS32_STATUS_MUS_PROGRESS,                /* playback in progress*/
    MMI_OP11_HS32_STATUS_MUS_NOT_PROGRESS,       /* playback not in progress, new tracks available*/
    MMI_OP11_HS32_STATUS_MUS_TYPE_MAX
} mmi_op11_hs32_status_mus_type_enum;

/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_MUS {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_MUS_PL,           /* Music Player, if project do not have music hard key */
//    MMI_OP11_HS32_SHCT_MUS_MS,           /* Music Store, and we do not implement that */
    MMI_OP11_HS32_SHCT_MUS_MM,           /* My Music, after select will display play list screen */
    MMI_OP11_HS32_SHCT_MUS_TYPE_MAX
} mmi_op11_hs32_shct_mus_type_enum;

#define  OP11_HS32_SHCT_STR_LIST_MUS    \
    STR_ID_OP11_HS32_MUS_PL,   \
    STR_ID_OP11_HS32_MUS_MM


/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_MUS {NULL}

/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_MUS \
{ mmi_medply_app_entry_mscr, \
   mmi_medply_app_entry_listmgr  \
}
/**********************************************************************/
#else
/**********************************************************************/
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_MUS  NULL 
/* ap status enum */
typedef enum
{
    MMI_OP11_HS32_STATUS_MUS_STANDARD,                /* playback not in progress, no new tracks available*/
    MMI_OP11_HS32_STATUS_MUS_PROGRESS,                /* playback in progress*/
    MMI_OP11_HS32_STATUS_MUS_NOT_PROGRESS,       /* playback not in progress, new tracks available*/
    MMI_OP11_HS32_STATUS_MUS_TYPE_MAX
} mmi_op11_hs32_status_mus_type_enum;

/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_MUS {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_MUS_PL,           /* Music Player, if project do not have music hard key */
//    MMI_OP11_HS32_SHCT_MUS_MS,           /* Music Store, and we do not implement that */
    MMI_OP11_HS32_SHCT_MUS_MM,           /* My Music, after select will display play list screen */
    MMI_OP11_HS32_SHCT_MUS_TYPE_MAX
} mmi_op11_hs32_shct_mus_type_enum;

#define  OP11_HS32_SHCT_STR_LIST_MUS    NULL
/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_MUS {NULL}
/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_MUS  {NULL}
/**********************************************************************/
#endif
/**********************************************************************/


#if defined(__MMI_OP11_HS32_PHO__)
/**********************************************************************
 * AP Photography [PHO] 
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_PHO  NULL

/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_PHO {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_PHO_TP,           /* Take Photo, after select will entry Camera preview */
    MMI_OP11_HS32_SHCT_PHO_MP,           /* My Photos,  after select will entry imageviewer */
    MMI_OP11_HS32_SHCT_PHO_MV,           /* My Videos, after select will entry ? */
    MMI_OP11_HS32_SHCT_PHO_TYPE_MAX
} mmi_op11_hs32_shct_pho_type_enum;

#define OP11_HS32_SHCT_STR_LIST_PHO    \
    STR_ID_OP11_HS32_PHO_TP,   \
    STR_ID_OP11_HS32_PHO_MP,   \
    STR_ID_OP11_HS32_PHO_MV


/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_PHO {NULL}

/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_PHO \
{ mmi_op11_hs32_shct_cb_tp, \
   mmi_imgview_launch, \
   mmi_op11_hs32_enter_video_lib_screen  \
}
/**********************************************************************/
#else
/**********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_PHO  NULL
/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_PHO {NULL}
/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_PHO_TP,           /* Take Photo, after select will entry Camera preview */
    MMI_OP11_HS32_SHCT_PHO_MP,           /* My Photos,  after select will entry imageviewer */
    MMI_OP11_HS32_SHCT_PHO_MV,           /* My Videos, after select will entry ? */
    MMI_OP11_HS32_SHCT_PHO_TYPE_MAX
} mmi_op11_hs32_shct_pho_type_enum;
#define OP11_HS32_SHCT_STR_LIST_PHO    NULL
/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_PHO {NULL}
/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_PHO {NULL}
/**********************************************************************/
#endif
/**********************************************************************/


#if defined(__MMI_OP11_HS32_CNX__)
/**********************************************************************
 * AP Connections [CNX] 
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_CNX NULL 

/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_CNX {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_CNX_WIFI,           /* "Wifi" */
    MMI_OP11_HS32_SHCT_CNX_BT,           /* "Bluetooth" */
    MMI_OP11_HS32_SHCT_CNX_FM,           /* "Flight mode" */
    MMI_OP11_HS32_SHCT_CNX_TYPE_MAX
} mmi_op11_hs32_shct_cnx_type_enum;

#define OP11_HS32_SHCT_STR_LIST_CNX     \
    STR_ID_OP11_HS32_CNX_WIFI,   \
    STR_ID_OP11_HS32_CNX_BT,   \
    STR_ID_OP11_HS32_CNX_FM


#if defined(__MMI_OP11_HS32_CNX_WIFI__) && defined(__MMI_OP11_HS32_CNX_BT__)
    /* shortcut data get func table */
    #define MMI_OP11_HS32_SHCT_GET_FUNCT_CNX \
    { mmi_wifi_op11_hs32_get_shct_data,  \
       mmi_bt_op11_hs32_get_shct_data,  \
       NULL   \
    }
    /* shortcut selected callback table */
    #define MMI_OP11_HS32_SHCT_SEL_FUNCT_CNX \
    { mmi_wlan_entry_wlan_wizard_new, \
       mmi_bt_entry_main_menu, \
       EntryPhnsetFlightMode  \
    }
#elif defined(__MMI_OP11_HS32_CNX_WIFI__) /* no BT */
    /* shortcut data get func table */
    #define MMI_OP11_HS32_SHCT_GET_FUNCT_CNX \
    { mmi_wifi_op11_hs32_get_shct_data,  \
       NULL,  \
       NULL   \
    }
    /* shortcut selected callback table */
    #define MMI_OP11_HS32_SHCT_SEL_FUNCT_CNX \
    { mmi_wlan_entry_wlan_wizard_new, \
       NULL, \
       EntryPhnsetFlightMode  \
    }
#elif defined(__MMI_OP11_HS32_CNX_BT__) /* no WIFI */
/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_CNX \
    { NULL,  \
      mmi_bt_op11_hs32_get_shct_data,  \
      NULL   \
}
/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_CNX \
{  NULL, \
    mmi_bt_entry_main_menu, \
    EntryPhnsetFlightMode  \
}
#else
/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_CNX \
{ NULL,  \
   NULL,  \
   NULL   \
}
/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_CNX \
{ NULL, \
   NULL,  \
   EntryPhnsetFlightMode  \
}
#endif

/**********************************************************************/
#else
/**********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_CNX NULL 
/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_CNX {NULL}
/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_CNX_WIFI,           /* "Wifi" */
    MMI_OP11_HS32_SHCT_CNX_BT,           /* "Bluetooth" */
    MMI_OP11_HS32_SHCT_CNX_FM,           /* "Flight mode" */
    MMI_OP11_HS32_SHCT_CNX_TYPE_MAX
} mmi_op11_hs32_shct_cnx_type_enum;
#define OP11_HS32_SHCT_STR_LIST_CNX     NULL
/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_CNX {NULL}
/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_CNX {NULL}
/**********************************************************************/
#endif
/**********************************************************************/


#if defined(__MMI_OP11_HS32_DST__)
/**********************************************************************
 * AP Device Status [DST] (only 1 shortcut)
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_DST NULL

/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_DST {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_DST,           /* only 1 shortcut, "Device status" */
    MMI_OP11_HS32_SHCT_DST_TYPE_MAX
} mmi_op11_hs32_shct_dst_type_enum;

#define  OP11_HS32_SHCT_STR_LIST_DST    \
    STR_ID_OP11_HS32_DST

/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_DST {NULL}

/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_DST    \
{ mmi_op11_hs32_entry_dev_screen_group    \
}
/**********************************************************************/
#else
/**********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_DST NULL
/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_DST {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_DST,           /* only 1 shortcut, "Device status" */
    MMI_OP11_HS32_SHCT_DST_TYPE_MAX
} mmi_op11_hs32_shct_dst_type_enum;
#define  OP11_HS32_SHCT_STR_LIST_DST    NULL
/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_DST {NULL}
/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_DST    {NULL}
/**********************************************************************/
#endif
/**********************************************************************/


#if defined(__MMI_OP11_HS32_STK__)
/**********************************************************************
 * AP SIM Toolkit [STK] (only 1 shortcut)
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_STK NULL

/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_STK {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_STK,           /* only 1 shortcut, "Orange Plus"string need get data from AP */
    MMI_OP11_HS32_SHCT_STK_TYPE_MAX
} mmi_op11_hs32_shct_stk_type_enum;

#define  OP11_HS32_SHCT_STR_LIST_STK    \
    STR_ID_OP11_HS32_STK

/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_STK \
{ NULL  \
}

/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_STK \
{ mmi_sat_pre_entry_GoToSATMainMenu \
}
/**********************************************************************/
#else
/**********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_STK NULL
/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_STK {NULL}
/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_STK,           /* only 1 shortcut, "Orange Plus"string need get data from AP */
    MMI_OP11_HS32_SHCT_STK_TYPE_MAX
} mmi_op11_hs32_shct_stk_type_enum;

#define  OP11_HS32_SHCT_STR_LIST_STK    NULL
/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_STK {NULL}
/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_STK {NULL}
/**********************************************************************/
#endif
/**********************************************************************/


/**********************************************************************
 * AP TakePhoto [TPH] 
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_TPH  NULL

/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_TPH {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_TPH,           /* Take Photo, after select will entry Camera preview */
    MMI_OP11_HS32_SHCT_TPH_TYPE_MAX
} mmi_op11_hs32_shct_tph_type_enum;

#define OP11_HS32_SHCT_STR_LIST_TPH    \
    STR_ID_OP11_HS32_PHO_TP

/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_TPH {NULL}

/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_TPH \
{ mmi_op11_hs32_shct_cb_tp  \
}


/**********************************************************************
 * AP VIP Contacts [VIP] 
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_VIP  mmi_op11_hs32_query_sidebar_vip

/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_VIP {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_VIP,           /* Entry VIP edit screen */
    MMI_OP11_HS32_SHCT_VIP_TYPE_MAX
} mmi_op11_hs32_shct_vip_type_enum;

#define OP11_HS32_SHCT_STR_LIST_VIP    \
    STR_ID_OP11_HS32_SET_KEY_CONTACT

/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_VIP {NULL}

/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_VIP \
{ NULL  \
}


/**********************************************************************
 * AP reserved (PHB for example) [USCON] 
 **********************************************************************/
/* sidebar info query func */
#define MMI_OP11_HS32_SIDEBAR_QUERY_FUNCT_USCON  NULL

/*  Do not have indicator */
#define MMI_OP11_HS32_INDCTR_SEL_FUNCT_USCON {NULL}

/* shortcut type enum */
typedef enum
{
    MMI_OP11_HS32_SHCT_USCON,           /* Entry phb screen */
    MMI_OP11_HS32_SHCT_USCON_TYPE_MAX
} mmi_op11_hs32_shct_uscon_type_enum;

#define OP11_HS32_SHCT_STR_LIST_USCON    \
    STR_ID_OP11_HS32_CON_CONTACT_LIST

/* shortcut data get func table */
#define MMI_OP11_HS32_SHCT_GET_FUNCT_USCON {NULL}

/* shortcut selected callback table */
#define MMI_OP11_HS32_SHCT_SEL_FUNCT_USCON \
{ mmi_phb_launch  \
}




#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif /* MMI_OP11_HS32_DEF_H  */

