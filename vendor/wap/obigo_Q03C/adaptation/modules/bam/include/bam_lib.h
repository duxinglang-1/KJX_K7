#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_lib.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains library functions provided by BAM module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _bam_lib_h

#define _bam_lib_h

typedef struct
{
    int id;     /*
                 * IANA registered number of the charset. BrowserAPP
                 * * should this number in MSG_ID_WAP_BAM_LOAD_URL_REQ.
                 */
    int name_id;    /* STR ID for the name of thecharset */
} bam_charset_name_id_t;

typedef struct
{
    int con_type;
    unsigned char prx_ip[4];
    unsigned short prx_port;
    char *username;
    char *password;
    int net_id;
    int net_id2;
} bam_conn_profile_t;

/**********************************************************************
 * External interfaces
 **********************************************************************/
/* For BrowserAPP */

#if 0
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
#endif

#if 0
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
#endif

#if 0   /* This function should be replaced with the URL validation function in MMI */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

/* For OWL */

/*****************************************************************************
 * FUNCTION
 *  bam_wait_user_action_ind
 * DESCRIPTION
 *  This function is used to send indication MSG_ID_WAP_BAM_WAIT_USER_ACTION_IND 
 *  to Browser Application to notify Browser Application of waiting for user action, 
 *  e.g. a cofirm dialog. After user action is completed, BrowserAPP should send 
 *  MSG_ID_WAP_BAM_WAIT_USER_ACTION_RSP to notify BAM of the user action.
 * PARAMETERS
 *  enable_positive_sk:     [IN]    Enable positive softkey or not.
 *  positive_label:         [IN]    The label of positive softkey. If ¡§enable_positive_sk¡¨ is FALSE, this label must be ignored.
 *  positive_label_len:     [IN]    The label length of positive softkey. If ¡§enable_positive_sk¡¨ is FALSE, this label must be ignored.
 *  enable_negative_sk:     [IN]    Enable negative softkey or not.
 *  negative_label:         [IN]    The label of negative softkey. If ¡§enable_positive_sk¡¨ is FALSE, this label must be ignored.
 *  negative_label_len:     [IN]    The label length of negative softkey. If ¡§enable_positive_sk¡¨ is FALSE, this label must be ignored.
 * RETURNS
 *  void
 *****************************************************************************/
extern void
bam_wait_user_action_ind(
    int enable_positive_sk,
    const char *positive_label,
    int positive_label_len,
    int enable_negative_sk,
    const char *negative_label,
    int negative_label_len);

/*****************************************************************************
 * FUNCTION
 *  bam_brs_is_idle
 * DESCRIPTION
 *  This function is used to indicate whether BRS is ready and idle.
 * PARAMETERS
 *  void
 * RETURNS
 *  1 for idle, otherwise 0.
 *****************************************************************************/
extern int bam_brs_is_idle(void);

/*****************************************************************************
 * FUNCTION
 *  bam_get_brs_paintbox
 * DESCRIPTION
 *  This function is used to get the paintbox previously returned in a request 
 *  to instantiate the BRS.
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  The handle of paintbox.
 *****************************************************************************/
extern unsigned long bam_get_brs_paintbox(void);
	
/* For STK */

/*****************************************************************************
 * FUNCTION
 *  bam_get_brs_security_id
 * DESCRIPTION
 *  Return security information of current document.
 * PARAMETERS
 *  void
 * RETURNS
 *  Security ID information of current document.
 *****************************************************************************/
extern int bam_get_brs_security_id(void);

/*****************************************************************************
 * FUNCTION
 *  bam_get_brs_id
 * DESCRIPTION
 *  This function is used to get the object Id previously returned in a request to instantiate the BRS.
 * PARAMETERS
 *  void
 * RETURNS
 *  The object Id previously returned in a request to instantiate the BRS.
 *****************************************************************************/
extern int bam_get_brs_id(void);

/* For WPS */

/*****************************************************************************
 * FUNCTION
 *  bam_get_default_conn_profile
 * DESCRIPTION
 *  Get the default connection profile setting.
 * PARAMETERS
 *  prof:   [OUT]   Connection profile
 * RETURNS
 *  void
 *****************************************************************************/
extern void bam_get_default_conn_profile(bam_conn_profile_t *prof);

/*****************************************************************************
 * FUNCTION
 *  bam_get_net_acc_id
 * DESCRIPTION
 *  This function is used to get the current network account id.
 * PARAMETERS
 *  void
 * RETURNS
 *  The current network account id.
 *****************************************************************************/
extern int bam_get_net_acc_id(void);

/* For Framework */

/*****************************************************************************
 * FUNCTION
 *  bam_send_out_of_memory_ind
 * DESCRIPTION
 *  This function is used to send an indication to Browser Application of error WAP_BAM_ERROR_OUT_OF_MEMORY.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void bam_send_out_of_memory_ind(void);

/*For BRS plugin */

/*****************************************************************************
 * FUNCTION
 *  bam_get_num_of_registered_schemes
 * DESCRIPTION
 *  This function is used to get the total number of all registered schemes.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of all registered schemes.
 *****************************************************************************/
extern unsigned char bam_get_num_of_registered_schemes(void);

/*****************************************************************************
 * FUNCTION
 *  bam_get_registered_scheme_by_index
 * DESCRIPTION
 *  This function is used to get registered scheme by index.
 * PARAMETERS
 *  index   [IN]    Index of the specified registered scheme
 * RETURNS
 *  The specified scheme.
 *****************************************************************************/
extern const char *bam_get_registered_scheme_by_index(unsigned char index);

#ifdef MTK_TMP_PATCH /* TR34746, TR34686: Loading large web page and MT call comes */
/* For BRS */
extern int bam_get_no_continue_iterations(void);
extern int bam_is_brw_task_busy(void);
extern void bam_get_system_time_tick(unsigned int *ticks_ptr);
extern int bam_get_system_time_ticks_1_sec(void);
#endif /* MTK_TMP_PATCH */

/* For VDS */

/*****************************************************************************
 * FUNCTION
 *  bam_is_nav_mode_scrolling
 * DESCRIPTION
 *  This function is used to check whether the browser navigation mode is scrolling.
 * PARAMETERS
 *  void
 * RETURNS
 *  Returns 0 if it is not scrolling mode; otherwise, returns 1.
 *****************************************************************************/
int
bam_is_nav_mode_scrolling(void);

/* For BRS */

/*****************************************************************************
 * FUNCTION
 *  bam_get_max_wap_conn_msg_size
 * DESCRIPTION
 *  This function is used to get the maximum total message size for WAP connection.
 * PARAMETERS
 *  void
 * RETURNS
 *  The maximum total message size for WAP connection.
 *****************************************************************************/
extern long bam_get_max_wap_conn_msg_size(void);

#endif /* _bam_lib_h */ 


#endif /*OBIGO_Q03C_BROWSER*/