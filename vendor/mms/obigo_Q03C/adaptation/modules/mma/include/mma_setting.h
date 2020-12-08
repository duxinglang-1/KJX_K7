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
 *   mma_main.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains functions definitions and functions used by MMA MAIN submodule.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMA_SETTING_H
#define _MMA_SETTING_H

/************************************************************
 * Constants
 ************************************************************/

/**********************************************************************
 * Type definitions
 **********************************************************************/
typedef struct
{
    kal_uint32  data_account;                                   /* Data account used by this profile */
    kal_uint16  proxy_port;                                     /* Port number of proxy */
                             /* MMA_MAX_PROF_HOMEPAGE_URL_LENGTHE, Specify the URL of homepage and encoded by UCS2*/
    kal_uint8 * mmsc_url_server;
    kal_uint8 * mmsc_url_scheme;
    kal_uint8 * mmsc_url_uri;
    kal_uint32  mmsc_url_port;
    kal_uint8 * username;           /* MMA_MAX_PROF_USERNAME_LENGTH, Specify the username and encoded by UCS2*/
    kal_uint8 * password;           /* MMA_MAX_PROF_PASSWORD_LENGTH, Specify the password and encoded by UCS2*/
    kal_uint8 * proxy_addr;                                    /* IP address of proxy*/                                      /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8 connection_type;                                  /* mma_connection_type_enum */
} mma_setting_profile_struct;

typedef struct
{
    kal_uint8 * rr_text_your_msg;   /* MMA_MAX_PROF_HOMEPAGE_URL_LENGTHE, Specify the URL of homepage and encoded by UCS2*/
    kal_uint8 * rr_text_read;           /* MMA_MAX_PROF_USERNAME_LENGTH, Specify the username and encoded by UCS2*/
    kal_uint8 * rr_text_from;           /* MMA_MAX_PROF_PASSWORD_LENGTH, Specify the password and encoded by UCS2*/
    kal_uint8 * rr_text_to;                                    /* IP address of proxy*/                                      /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8 * rr_text_msgId;
    kal_uint8 * rr_text_subject;
    kal_uint8 * rr_text_sent;
    kal_uint8 * rr_text_was_read;
} mma_setting_read_report_res_struct;


typedef struct
{
    wap_mma_set_setting_req_struct *setting;
    mma_setting_profile_struct *profile[MMA_MAX_SIM_COUNT];
    mma_setting_read_report_res_struct rr_res;
    kal_uint8 * user_agent;
    kal_uint8 * ua_profile;
    kal_uint8 is_roaming[MMA_MAX_SIM_COUNT];
    kal_uint8 is_suspended[MMA_MAX_SIM_COUNT];

} mma_setting_context_struct;


extern kal_bool mma_setting_terminate(void);
extern kal_bool mma_setting_init(void);
extern void mma_setting_process_int_sig(mma_signal_struct *sig);
extern kal_bool mma_setting_is_supended(MSF_INT32 sim_id);
extern wap_mma_set_setting_req_struct * mma_setting_get_settings(void);
extern mma_setting_profile_struct * mma_setting_get_profile(MSF_INT32 sim_id);
extern kal_bool mma_setting_split_mmsc(char *str, char **server, kal_uint32 *port, char **uri, char **scheme);
extern kal_bool mma_setting_is_roaming(MSF_INT32 sim_id);
extern kal_uint8 * mma_setting_get_user_agent(void);
extern kal_uint8 * mma_setting_get_user_prof(void);
extern mma_setting_read_report_res_struct mma_setting_get_rr_settings(void);
extern mma_result_enum mma_setting_set_registry_10_rr_all_string_res(void);
extern kal_uint32 mma_setting_get_max_retrival_size(void);
extern kal_uint32 mma_setting_get_account_id(kal_uint8 sim_id);

extern kal_uint8 mma_setting_get_preffered_storage(void);
#endif /* _MMA_SETTING_H */ 

