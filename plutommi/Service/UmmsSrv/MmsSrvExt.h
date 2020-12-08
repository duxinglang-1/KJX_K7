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
 *  MMSAppExt.h
 * 
 * Project:
 * --------
 *  MAUI
 * 
 * Description:
 * ------------
 *  This file contains declaration of APIs defined in MMSAppExt.c and definitions of 
 *  structures and unions used in MMSAppExt.c
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

#ifndef MMSSRVEXT_H
#define MMSSRVEXT_H

#include "MMI_features.h"
#ifdef __MMI_MMS_2__

#include "kal_general_types.h"
#ifdef __MMI_MMS_URI_AGENT__
#include "UriAgentSrvGprot.h"
#endif 
// #include "MmsSrvGprot.h"

#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif 

#if defined(__MMI_VUI_HOMESCREEN__)
#include "IdleRecentEventGprot.h"
#endif 

#ifdef __MMI_OP12_TOOLBAR__
#include "IdleToolbarGprot.h"
#endif 
#include "UcSrvGprot.h"
// #include "MMSAppInterfaceGprot.h"

#include "MMIDataType.h"

#ifdef __MMI_MMS_URI_AGENT__
#define     MMS_URI_TO                      "to="
#define     MMS_URI_EXT_TO                  "?to="
#define     MMS_URI_CC                      "cc="
#define     MMS_URI_SUBJECT                 "subject="
#define     MMS_URI_SUBJECT_AND_SYMB      "&subject="
#define     MMS_URI_SUBJECT_AMPERSAND_SYMB   "?subject="
#define     MMS_URI_BODY                    "body="
#define     MMS_URI_IS_SEPARATOR(c)         ((c == '?') || (c == '&') || (c == ','))
#define     MMS_URI_IS_SUBJECT_SEPERATOR(c) ((c == '?') || (c == ';') || (c == '&'))
#define     SRV_MMS_MAX_URI_LENGTH         513
#endif /* __MMI_MMS_URI_AGENT__ */ 

#ifdef __MMI_MMS_URI_AGENT__
typedef enum
{
    MMS_URI_HEADER_TO,
    MMS_URI_HEADER_CC,
    MMS_URI_HEADER_SUBJECT,
    MMS_URI_HEADER_BODY,
    MMS_URI_HEADER_MAX
} srv_mms_header_enum;
#endif /* __MMI_MMS_URI_AGENT__ */ 

#ifdef __MMI_MMS_URI_AGENT__
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
typedef struct
{
    kal_uint32 ura_appid;
    char *param;
    srv_uriagent_uri_request_hdlr_cb cb;
    kal_uint8 *text_buffer;
    kal_uint8 *uc_subject;
    srv_uc_addr_struct *addr_buffer;
} srv_mms_current_uri_info_struct;
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 

typedef void (*mms_func_ptr) (void *);

typedef struct
{
    kal_uint8 addr_num;         /* Max addresses */
    srv_uc_addr_struct *addr;   /* Addresses linklist */
    kal_uint8 *text_buffer;     /* File path */
    kal_uint16 text_num;        /* File path */
    kal_uint8 *subject;         /* File path */
    mms_func_ptr callback;      /* Callback function specified by caller of object forward, for calling after use of object */
} srv_mms_entry_write_struct;
#endif /* __MMI_MMS_URI_AGENT__ */ 

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
typedef struct
{
    U8 app_id;
    U32 msg_id;
} srv_mms_vendor_struct;
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 

#ifdef __MMI_MMS_URI_AGENT__
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
extern void srv_mms_uri_insert_hdlr_ext(kal_uint32 ura_appid, char *param, srv_uriagent_uri_request_hdlr_cb cb);
extern void srv_mms_uri_addr_enqueue(srv_uc_addr_struct *addr_data, srv_uc_addr_struct **addr_queue);
extern void srv_mms_uri_scheme_cb(void *param);
extern char *srv_mms_strdup(const char *s);
extern char *srv_mms_strndup(const char *s, int len);
extern void srv_mms_set_uri_parameters(kal_uint32 ura_appid, char *param, srv_uriagent_uri_request_hdlr_cb cb);
extern void srv_mms_uri_exit_hndlr_for_confirm_popup(void);
extern void srv_mms_launch_write_msg(void);
extern void srv_mms_send_call_back_to_uri_agnt(void);
extern kal_char *srv_mms_stristr(const kal_char *src_str, const kal_char *tbf_str);
extern MMI_BOOL srv_mms_uri_is_new_header(char *str, srv_mms_header_enum cur_header);
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ /* #ifdef __UNIFIED_COMPOSER_SUPPORT__ */
#endif /* __MMI_MMS_URI_AGENT__ */ 
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
extern BOOL srv_mms_check_is_num_or_email_valid(srv_uc_address_type_enum type, char *addr);
extern void srv_mms_display_invalid_popup(void);
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 

#ifdef __MMI_MMS_URI_AGENT__
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
extern kal_int32 mmi_chset_utf8_to_ucs2_string(U8 *dest, kal_int32 dest_size, U8 *src);

extern void srv_mms_uri_insert_hdlr(
                srv_uriagent_appid_enum ura_appid,
                char *url,
                char *param,
                srv_uriagent_options_enum options,
                srv_uriagent_uri_request_hdlr_cb cb);
extern void srv_mms_de_init_uri(void);
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 
#endif /* __MMI_MMS_URI_AGENT__ */ 

#endif /* __MMI_MMS_2__ */ 
#endif /* MMSSRVEXT_H */ 

