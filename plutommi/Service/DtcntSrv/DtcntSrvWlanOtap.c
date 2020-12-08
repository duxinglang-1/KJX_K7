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
 * DtcntSrvWlanOtap.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intended to provide the WLAN profile OTA 
 *   provisioning handling services.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __TCPIP__
#include "MMI_features.h"
//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
#include "DtcntSrv.h"
#include "cbm_consts.h"
#ifdef __MMI_WLAN_FEATURES__
#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)

#include "Conversions.h" /* Conversion between different Unicode encodings. */
#include "MMI_features.h"
#include "DtcntSrvWlanOtap.h"
#include "DtcntSrvIprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "DtcntSrvIntStruct.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "DtcntSrvGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "DtcntSrvIntDef.h"
#include "DtcntSrvProv.h"
#include "DebugInitDef_Int.h"
#include "supc_abm_msgs.h"
#include "MMI_conn_app_trc.h"
#include "kal_trace.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "DtcntSrvIntEnum.h"
#include "DtcntSrvWlan.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "stdlib.h"
#include "CcaSrvGprot.h"

/***************************************************************************** 
* Define
*****************************************************************************/
/* Default profile's name. */
#define SRV_DTCNT_DEFAULT_PROF_NAME    (L"New Profile")
/* Constants for auto renaming. */
#define SRV_DTCNT_DUP_NAME_SUFFIX_PATTERN (L"(00)")   /* Appended pattern         */
#define SRV_DTCNT_DUP_NAME_SUFFIX_LEN     (4)         /* Length of pattern        */
#define SRV_DTCNT_DUP_NAME_SUFFIX_NUM     (100)       /* Num of values in pattern */


/***************************************************************************** 
* Local Variable
*****************************************************************************/

/* Since the application has the property that it is only triggered when a
   configuration document is arrived, we dynamically allocate the control 
   block to save memory. */
static srv_dtcnt_wlan_otap_struct *g_srv_dtcnt_wlan_otap = NULL;
static srv_dtcnt_prof_wlan_struct *g_srv_dtcnt_wlan_otap_active_prof_p = NULL;

/***************************************************************************** 
* Local Function
*****************************************************************************/
static S32 srv_dtcnt_wlan_hex_to_dec(U8 input);
static MMI_BOOL srv_dtcnt_wlan_hex_to_psk(U8 *dst, const U8 *src, S32 len);
static MMI_BOOL srv_dtcnt_wlan_is_ascii_string(const U8 *utf8_str);
static MMI_BOOL srv_dtcnt_wlan_is_appended_pattern(const U8 *name, U8 *value);
static void srv_dtcnt_wlan_update_appended_pattern(U8 *dup_name, const U8 **name, U8 num_names);
static void srv_dtcnt_wlan_resolve_duplicate_name(U8 *dup_name, const U8 **name, U8 num_names);
static srv_dtcnt_wlan_otap_struct *srv_dtcnt_wlan_new_otap_cntx(U16 conf_id, S32 doc_hdl);
static void srv_dtcnt_wlan_free_otap_cntx(void);
static U8 srv_dtcnt_wlan_abort_otap_app(void *dummy);
static void srv_dtcnt_wlan_init_slim_profile(srv_dtcnt_wlan_slim_profile_struct *prof);
static S16 srv_dtcnt_wlan_new_otap_profile(srv_dtcnt_wlan_otap_struct *cntx);
static void srv_dtcnt_wlan_free_otap_profile(srv_dtcnt_wlan_otap_struct *cntx, S16 index);
static MMI_BOOL srv_dtcnt_wlan_validate_eap(const srv_dtcnt_wlan_slim_profile_struct *prof);
static MMI_BOOL srv_dtcnt_wlan_validate_wep_key(const srv_dtcnt_wlan_slim_profile_struct * prof);
static MMI_BOOL srv_dtcnt_wlan_validate_profile(const srv_dtcnt_wlan_slim_profile_struct *prof);
static void srv_dtcnt_wlan_provision_profile(srv_dtcnt_prof_wlan_struct *dst, const srv_dtcnt_wlan_slim_profile_struct *src);
static U8 srv_dtcnt_wlan_find_empty_profile(void);
static MMI_BOOL srv_dtcnt_wlan_is_empty_profile(U8 i);
static void srv_dtcnt_wlan_otap_install_start(void);
static void srv_dtcnt_wlan_otap_install_notify(MMI_BOOL replace_flag);
static void srv_dtcnt_wlan_otap_prof_name_list(void);
static MMI_BOOL srv_dtcnt_wlan_is_duplicate_name(S16 src_idx);
static void srv_dtcnt_wlan_auto_rename_profile(S16 src_idx);
static void srv_dtcnt_wlan_otap_install(void);
static void srv_dtcnt_wlan_otap_replace(U8 replace_idx);
static void srv_dtcnt_wlan_otap_skip(void);
static void srv_stcnt_wlan_otap_install_next(void);
static U8 srv_dtcnt_wlan_install_profiles(void);
static void srv_dtcnt_wlan_otap_done_notify(U8 num_installed);


/* Use OMA extension OTAP spec. */
#if defined(__MMI_WLAN_OTAP_OMAEXT__)
static U32 srv_dtcnt_wlan_base64_decoder(S8 *dst, U32 dst_size, const S8 *src, U32 src_size);
static MMI_BOOL srv_dtcnt_wlan_has_otap_profile(cca_iterator_struct *param_list);

static cca_status_enum srv_dtcnt_wlan_proc_cca_param_wepkey(
                        const cca_core_data_struct *param, 
                        srv_dtcnt_wlan_slim_profile_struct *prof);
static cca_status_enum srv_dtcnt_wlan_proc_cca_param_eap(
                        const cca_core_data_struct *param, 
                        srv_dtcnt_wlan_slim_profile_struct *prof);
static cca_status_enum srv_dtcnt_wlan_proc_cca_param_wlan(
                        const cca_core_data_struct *param, 
                        srv_dtcnt_wlan_slim_profile_struct *prof);
static cca_status_enum srv_dtcnt_wlan_proc_cca_param_napdef(
                        const cca_core_data_struct *param, 
                        srv_dtcnt_wlan_otap_struct *cntx);
static cca_status_enum srv_dtcnt_wlan_proc_cca_nodes(
                        S32 doc_hdl, 
                        S32 node_hdl, 
                        U16 symbol, 
                        cca_iterator_struct *param_list, 
                        void *user_data);

/* Use the proprietary OTAP spec. */
#elif defined(__MMI_WLAN_OTAP_DMP__)

static cca_status_enum srv_dtcnt_wlan_proc_cca_node_profile(
                        cca_iterator_struct *param_list, 
                        srv_dtcnt_wlan_slim_profile_struct *prof);
static cca_status_enum srv_dtcnt_wlan_proc_cca_param_profile(
                        const cca_core_data_struct *param, 
                        srv_dtcnt_wlan_slim_profile_struct *prof);
static cca_status_enum srv_dtcnt_wlan_proc_cca_nodes(
                        S32 doc_hdl, 
                        S32 node_hdl, 
                        U16 symbol, 
                        cca_iterator_struct *param_list, 
                        void *user_data);

#endif /* ! (defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)) */


/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern srv_dtcnt_prof_wlan_struct g_srv_dtcnt_wlan_prof_list[SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM];
extern srv_dtcnt_prof_wlan_struct *g_srv_dtcnt_wlan_prof_list_p[SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM];
extern srv_dtcnt_wlan_setting_struct g_srv_dtcnt_wlan_setting_ctx;
extern void pbkdf2_sha1(
                const char *passphrase,
                const char *ssid,
                kal_uint16 ssid_len,
                int iterations,
                kal_uint8 *buf,
                kal_uint16 buflen);

#define WLAN_OTAP_STATIC_APIs

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_hex_to_dec
 * DESCRIPTION
 *  This function converts a hexadecimal character to its decimal value.
 * PARAMETERS
 *  input           [IN]            Input hexadecimal character
 * RETURNS
 *  If input is a hexadecimal character, return its decimal value. Otherwise,
 *  return -1.
 *****************************************************************************/
S32 srv_dtcnt_wlan_hex_to_dec(U8 input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input >= '0' && input <= '9') 
    {
        return input - '0';
    } 
    else if (input >= 'a' && input <= 'f')
    {
        return input - 'a' + 10;    
    }
    else if (input >= 'A' && input <= 'F')
    {
        return input - 'A' + 10;
    }
    else
    {
        return -1;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_hex_to_psk
 * DESCRIPTION
 *  This function converts a hexadecimal character string to the pre-shared
 *  key, where each hexadecimal character represents 4-bits in the destination.
 * PARAMETERS
 *  dst             [OUT]           Output raw data
 *  src             [IN]            Input hexadecimal character string
 *  len             [IN]            Length of the string
 * RETURNS
 *  On success, return TRUE. On error, return FALSE.
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_hex_to_psk(U8 *dst, const U8 *src, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msb, lsb;
    S32 ret;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (len % 2 != 0) 
    {
        return MMI_FALSE;
    }
    
    for (i = 0; i < len; i += 2)
    {
        if ((ret = srv_dtcnt_wlan_hex_to_dec(src[i])) < 0) 
        {
            return MMI_FALSE;
        }
        msb= (U8)ret;

        if ((ret = srv_dtcnt_wlan_hex_to_dec(src[i + 1])) < 0) 
        {
            return MMI_FALSE;
        }
        lsb = (U8)ret;
        
        dst[i / 2] = (msb << 4) + lsb;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_is_ascii_string
 * DESCRIPTION
 *  This function checks whether the input UTF-8 encoded string is an ASCII
 *  string.
 * PARAMETERS
 *  utf8_str        [IN]            Input UTF-8 encoded string
 * RETURNS
 *  If input string is ASCII string, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_is_ascii_string(const U8 *utf8_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If this is an ASCII string, each octet should be an ASCII character. */
    for ( ; *utf8_str != '\0'; ++utf8_str)
    {
        if (*utf8_str > 0x7F) 
        {
            return MMI_FALSE;
        }
    }
    
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_is_appended_pattern
 * DESCRIPTION
 *  This function examines whether the name has an appended pattern (\d\d).
 *  If the name has the pattern and value is not NULL, set value to \d\d.
 * PARAMETERS
 *  name            [IN]            Name to be examined
 *  value           [OUT]           Return the value of \d\d
 * RETURNS
 *  If name has an appended pattern, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_is_appended_pattern(const U8 *name, U8 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U8 *start, *end, *iter;
    S32 str_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    str_len = mmi_ucs2strlen((S8 *)name);

    /* Examine whether the name has the appended pattern. */
    if (str_len < SRV_DTCNT_DUP_NAME_SUFFIX_LEN) 
    {
        return MMI_FALSE;
    } 
    else 
    {
        start = name + (str_len - SRV_DTCNT_DUP_NAME_SUFFIX_LEN) * ENCODING_LENGTH;
        end   = name + (str_len - 1) * ENCODING_LENGTH;

        if (*start != '(' || *(start + 1) != '\0') 
        {
            return MMI_FALSE;
        }

        if (*end != ')' || *(end + 1) != '\0') 
        {
            return MMI_FALSE;
        }

        for (iter = start + ENCODING_LENGTH; iter != end; iter += ENCODING_LENGTH) 
        {
            if (*iter < '0' || *iter > '9' || *(iter + 1) != '\0') 
            {
                return MMI_FALSE;
            }
        }
    }

    /* Save the value in the pattern. */
    if (value != NULL) 
    {
        start = name + (str_len - 3) * ENCODING_LENGTH; /* decimal  */
        end   = name + (str_len - 2) * ENCODING_LENGTH; /* unit     */
        *value = (*start - '0') * 10 + (*end - '0');
    }
    
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_update_appended_pattern
 * DESCRIPTION
 *  The function updates the values of the pattern (\d\d) in the duplicate 
 *  name.
 * PARAMETERS
 *  dup_name        [IN/OUT]        The name to be updated
 *  name            [IN]            The other names
 *  num_names       [IN]            Number of the other names
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_update_appended_pattern(U8 *dup_name, const U8 **name, U8 num_names)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 map[SRV_DTCNT_DUP_NAME_SUFFIX_NUM];
    U8 value, min;
    S32 str_len;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Initialize the map. All numbers are not used. */
    memset(map, 0, SRV_DTCNT_DUP_NAME_SUFFIX_NUM);

    str_len = mmi_ucs2strlen((S8 *)dup_name);

    /* Mark used values as one. */ 
    for (i = 0; i < num_names; ++i)
    {
        /* String length must be identical. */
        if (str_len != mmi_ucs2strlen((S8 *)name[i])) 
        {
            continue;
        }
        
        /* Prefix of names must be the same as the prefix of duplicate name. */
        if (mmi_ucs2ncmp((S8 *)dup_name, (S8 *)name[i], str_len - SRV_DTCNT_DUP_NAME_SUFFIX_LEN) != 0) 
        {
            continue;
        }
        
        if (srv_dtcnt_wlan_is_appended_pattern(name[i], &value) == MMI_TRUE) 
        {
            map[value] = 1;
        }
    }

    /* Find the minimum unused position. If all values are used, still produce
       a pattern with a duplicate value 99. */
    min = SRV_DTCNT_DUP_NAME_SUFFIX_NUM - 1;
    
    for (i = 1; i < SRV_DTCNT_DUP_NAME_SUFFIX_NUM; ++i) 
    {
        if (map[i] == 0) 
        {
            min = i;
            break;
        }
    }

    /* Update the value in the pattern. */
    *(dup_name + (str_len - 2) * ENCODING_LENGTH) = (min % 10) + '0';
    *(dup_name + (str_len - 3) * ENCODING_LENGTH) = (min / 10) + '0';
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_resolve_duplicate_name
 * DESCRIPTION
 *  This function updates the duplicate name according to the circumstance of
 *  the name array.
 * PARAMETERS
 *  dup_name        [IN/OUT]        The duplicate name to be updated
 *  name            [IN]            The other names
 *  num_names       [IN]            Number of the other names
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_resolve_duplicate_name(U8 *dup_name, const U8 **name, U8 num_names)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    U8 *ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If tail does not have an appended pattern (\d\d), append a pattern. */
    if (srv_dtcnt_wlan_is_appended_pattern(dup_name, NULL) == MMI_FALSE) 
    {
        str_len = mmi_ucs2strlen((S8 *)dup_name);

        /* Whether spaces are enough for appending the pattern (\d\d). */
        if (str_len + SRV_DTCNT_DUP_NAME_SUFFIX_LEN > SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN) 
        {
            /* Spaces are not enough. Truncate the tail. */
            ptr = dup_name + (SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN - SRV_DTCNT_DUP_NAME_SUFFIX_LEN) * ENCODING_LENGTH;
            *(ptr)     = '\0';
            *(ptr + 1) = '\0';
        }
        
        mmi_ucs2cat((S8 *)dup_name, (S8 *)SRV_DTCNT_DUP_NAME_SUFFIX_PATTERN);
    }

    /* Update the values in the pattern. */
    srv_dtcnt_wlan_update_appended_pattern(dup_name, name, num_names);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_new_otap_cntx
 * DESCRIPTION
 *  This function allocates and initializes the control block of WLAN OTA
 *  provisioning application.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  On success, return the address of control block. On error, return NULL.
 *****************************************************************************/
srv_dtcnt_wlan_otap_struct *srv_dtcnt_wlan_new_otap_cntx(U16 conf_id, S32 doc_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_otap_struct *cntx;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Allocate the control block. Must be successful. */
    cntx = (srv_dtcnt_wlan_otap_struct *)OslMalloc(sizeof(srv_dtcnt_wlan_otap_struct));
    if (cntx == NULL) 
    {
        return NULL;
    }

    /* Clear the entire structure. */
    memset(cntx, 0, sizeof(srv_dtcnt_wlan_otap_struct));

    /* Save the identifier for this configuration process. */
    cntx->conf_id = conf_id;
    cntx->doc_hdl = doc_hdl;

    /* Allow to process nodes and parameters until a NAPDEF node comes. */
    cntx->is_active = MMI_FALSE;

    /* Initialize the index for replacement to an invalid index. */
    for (i = 0; i < SRV_DTCNT_MAX_WLAN_OTA_PROF_NUM; ++i) 
    {
        cntx->dst_idx[i] = -1;
    }

    /* Initialize the index for replacement to an invalid index. */
    for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; ++i)
    {
        cntx->src_idx[i]     = -1;
        cntx->sel_dst_idx[i] = -1;
    }
    
    return cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_free_otap_cntx
 * DESCRIPTION
 *  The function frees memory of the control block, and clears the global ptr.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_free_otap_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Nothing to do. Return. */
    if (g_srv_dtcnt_wlan_otap == NULL) 
    {
        return;
    }
    
    /* Free all profiles. */
    for (i = 0; i < g_srv_dtcnt_wlan_otap->num_profiles; ++i) 
    {
        OslMfree(g_srv_dtcnt_wlan_otap->profile[i]);
    }

    /* Free the control block. */
    OslMfree(g_srv_dtcnt_wlan_otap);
    g_srv_dtcnt_wlan_otap = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_abort_otap_app
 * DESCRIPTION
 *  This function should be called to exit the WLAN OTAP application. It is 
 *  registered as a delete screen callback such that it can be called when END
 *  key is pressed to return to idle screen.
 * PARAMETERS
 *  dummy           [IN]            Dummy parameter. Always be zero.
 * RETURNS
 *  When END key is pressed to return to idle screen, return TRUE to stop 
 *  delete other nodes in history stack. Here, always return FALSE.
 *****************************************************************************/
U8 srv_dtcnt_wlan_abort_otap_app(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Terminated. Send a response back to CCA and free memory. */
    switch (g_srv_dtcnt_wlan_otap->cur_status)
    {
        case 0:
        case 5:
            srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_wlan_otap->conf_id, g_srv_dtcnt_wlan_otap->doc_hdl, CCA_STATUS_ENDKEY_PRESSED);
            break;
        case 2:
            srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_wlan_otap->conf_id, g_srv_dtcnt_wlan_otap->doc_hdl, CCA_STATUS_ENDKEY_SETTING_INSTALLED);
            break;
        case 3:
            srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_wlan_otap->conf_id, g_srv_dtcnt_wlan_otap->doc_hdl, CCA_STATUS_ENDKEY_SETTING_SKIPPED);
            break;
        case 4:
            srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_wlan_otap->conf_id, g_srv_dtcnt_wlan_otap->doc_hdl, CCA_STATUS_ENDKEY_INVALID_SETTING);
            break;
    }

    srv_dtcnt_wlan_free_otap_cntx();
    
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_init_slim_profile
 * DESCRIPTION
 *  This function initializes a slim WLAN profile.
 * PARAMETERS
 *  prof            [OUT]           Profile to be initialized
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_init_slim_profile(srv_dtcnt_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(prof, 0, sizeof(srv_dtcnt_wlan_slim_profile_struct));

    mmi_ucs2cpy((S8 *)prof->name, (S8 *)SRV_DTCNT_DEFAULT_PROF_NAME);
    
    prof->network_type   = SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA;
    prof->encrypt_mode   = SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE;
    prof->auth_mode      = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
    
    prof->wep_key_index  = SRV_DTCNT_MAX_WEP_KEY_NUM;             /* Invalid index    */
    prof->wep_key_len    = SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_TOTAL;  /* Invalid key len  */
    prof->wep_key_format = SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_new_otap_profile
 * DESCRIPTION
 *  This function allocates a temporary storage for WLAN profile. And it will 
 *  turn on the flag such that we can process subsequent nodes/parameters
 *  again.
 * PARAMETERS
 *  cntx            [IN]            control block for WLAN OTA provisioning
 * RETURNS
 *  On success, return the index of the newly allocated profile. Otherwise, 
 *  return -1, i.e., an invalid index.
 *****************************************************************************/
S16 srv_dtcnt_wlan_new_otap_profile(srv_dtcnt_wlan_otap_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /* No more temporary profile storage. */
    if (cntx->num_profiles == SRV_DTCNT_MAX_WLAN_OTA_PROF_NUM) 
    {
        return -1;
    }
    
    /* Obtain the index. */
    index = cntx->num_profiles;
    
    /* Allocate memory for the profile. */
    cntx->profile[index] = (srv_dtcnt_wlan_slim_profile_struct *)OslMalloc(sizeof(srv_dtcnt_wlan_slim_profile_struct));
    if (cntx->profile[index] == NULL) 
    {
        return -1;
    }

    /* Initialize the allocated slim WLAN profile. */
    srv_dtcnt_wlan_init_slim_profile(cntx->profile[index]);

    /* Now, we can update the number of profiles. */
    ++cntx->num_profiles;

    return index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_free_otap_profile
 * DESCRIPTION
 *  This function frees the specified profile in the control block.
 * PARAMETERS
 *  cntx            [IN]            Control block of WLAN OTA provisioning
 *  index           [IN]            Index of the profile to be freed
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_free_otap_profile(srv_dtcnt_wlan_otap_struct *cntx, S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /* Whether the index is legal. */
    if (index >= cntx->num_profiles) 
    {
        MMI_ASSERT(0);
    }
    
    /* Release the specified profile. */
    OslMfree(cntx->profile[index]);

    /* Shift the other profiles. */
    for (i = index + 1; i < cntx->num_profiles; ++i) 
    {
        cntx->profile[i - 1] = cntx->profile[i];
    }
    cntx->profile[cntx->num_profiles - 1] = NULL;

    /* Now, we can update the number of profiles. */
    --cntx->num_profiles;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_validate_eap
 * DESCRIPTION
 *  The function validates whether a correct EAP setting is presented.
 * PARAMETERS
 *  prof            [IN]            A provisioned profile    
 * RETURNS
 *  On success, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_validate_eap(const srv_dtcnt_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Currently, only EAP-SIM is supported. */
    if (prof->eap_auth_type != WLAN_EAP_SIM) 
    {
        return MMI_FALSE;
    }
    
    /* Whether the username/password have been provided. */
    if (strlen((S8 *)prof->username) == 0 || strlen((S8 *)prof->password) == 0) 
    {
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_validate_wep_key
 * DESCRIPTION
 *  The function validates whether a correct WEP key is presented.
 * PARAMETERS
 *  prof            [IN]            A provisioned profile    
 * RETURNS
 *  On success, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_validate_wep_key(const srv_dtcnt_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Whether the wep key index is legal. */
    if (prof->wep_key_index >= SRV_DTCNT_MAX_WEP_KEY_NUM) 
    {
        return MMI_FALSE;
    }

    /* Return TRUE if WEP setting are meaningful. */
    str_len = strlen((S8 *)prof->wep_key);

    if (prof->wep_key_len == SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64 && 
        prof->wep_key_format == SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII)
    {
        return str_len == 5? MMI_TRUE: MMI_FALSE;   /* WEP64, ASCII  */
    }
    else if (prof->wep_key_len == SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64 && 
             prof->wep_key_format == SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX)
    {
        return str_len == 10? MMI_TRUE: MMI_FALSE;  /* WEP64, HEX    */
    }
    else if (prof->wep_key_len == SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128 && 
             prof->wep_key_format == SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII)
    {
        return str_len == 13? MMI_TRUE: MMI_FALSE;  /* WEP128, ASCII */
    }
    else if (prof->wep_key_len == SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128 && 
             prof->wep_key_format == SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX)
    {
        return str_len == 26? MMI_TRUE: MMI_FALSE;  /* WEP128, HEX   */
    }

    /* All other situations are illegal. Return FALSE. */
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_validate_profile
 * DESCRIPTION
 *  The function validates a provisioned profile.
 * PARAMETERS
 *  prof            [IN]            A provisioned profile    
 * RETURNS
 *  On success, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_validate_profile(const srv_dtcnt_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* NAPDEF node's node ID */
    if (mmi_chset_utf8_strlen((kal_uint8 *)prof->node_id) == 0) 
    {
        return MMI_FALSE;
    }

    /* Name */
    if (mmi_ucs2strlen((S8 *)prof->name) == 0) 
    {
        return MMI_FALSE;    
    }
    
    /* SSID */
    if (prof->ssid_len == 0) 
    {
        return MMI_FALSE;
    }

    /* Network type. Ad-hoc network does not has authentication server.
       IEEE802.1X and WPA need authentication server and can't be used. */
    if (prof->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC && 
        (prof->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X || 
         prof->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX))
    {
        return MMI_FALSE;
    }

    /* 
     * Authentication mode 
     */
    switch (prof->auth_mode)
    {
        case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:
            /* OPEN must turn on NONE or WEP encryption. */
            if (prof->encrypt_mode != SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE && 
                prof->encrypt_mode != SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP)
            {
                return MMI_FALSE;
            }
            break;
            
        case SRV_DTCNT_WLAN_AUTH_MODE_WEP:
            /* SHARED must turn on NONE or WEP encryption. */
            if (prof->encrypt_mode != SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE && 
                prof->encrypt_mode != SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP)
            {
                return MMI_FALSE;
            }

            /* SHARED alwalys needs a correct WEP key. */
            if (srv_dtcnt_wlan_validate_wep_key(prof) == MMI_FALSE) {
                return MMI_FALSE;
            }
            break;
                
        case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X:
            /* IEEE802.1X must turn on WEP encryption. */
            if (prof->encrypt_mode != SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP) 
            {
                return MMI_FALSE;
            }

            if (srv_dtcnt_wlan_validate_eap(prof) == MMI_FALSE)
            {
                return MMI_FALSE;
            }
            break;
            
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX:
            /* WPA must turn on TKIP or AES encryption. */
            if (prof->encrypt_mode != SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP && 
                prof->encrypt_mode != SRV_DTCNT_WLAN_ENCRYPT_MODE_AES) 
            {
                return MMI_FALSE;
            }
            
            if (srv_dtcnt_wlan_validate_eap(prof) == MMI_FALSE)
            {
                return MMI_FALSE;
            }
            break;

        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK:
            /* WPA-PSK must turn on TKIP or AES. */
            if (prof->encrypt_mode != SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP && 
                prof->encrypt_mode != SRV_DTCNT_WLAN_ENCRYPT_MODE_AES) 
            {
                return MMI_FALSE;
            }
            break;
            
        default:
            return MMI_FALSE; /* Discard profile */
    }
    
    /* 
     * Encryption mode
     */
    switch (prof->encrypt_mode)
    {
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE:
            break;
            
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP:
            /* Whether WEP key is correctly presented except under IEEE802.1X, 
               which provides the key automatically. */
            if (prof->auth_mode != SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X && 
                srv_dtcnt_wlan_validate_wep_key(prof) == MMI_FALSE) 
            {
                return MMI_FALSE;
            }
            break;

        case SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP:
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_AES:
            /* Whether psk or passphrase is presented. Note that WPA don't
               need to provide key here. It uses dynamic key. */
            if (prof->auth_mode != SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX && 
                prof->psk[32] == 0 && prof->passphrase[0] == '\0') 
            {
                return MMI_FALSE;
            }
            break;

        default:
            return MMI_FALSE; /* Discard profile */
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_provision_profile
 * DESCRIPTION
 *  This function setups a WLAN profile from a slim profile.
 * PARAMETERS
 *  dst             [OUT]           Destination profile
 *  src             [IN]            Source slim profile
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_provision_profile(srv_dtcnt_prof_wlan_struct *dst, const srv_dtcnt_wlan_slim_profile_struct *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Clear the profile. */
    srv_dtcnt_wlan_init_profile(dst);

    mmi_ucs2cpy((S8 *)dst->ProfName, (S8 *)src->name);  /* Name             */
    dst->ssid_len = src->ssid_len;                          /* SSID length      */
    memcpy(dst->ssid, src->ssid, dst->ssid_len);            /* SSID             */
    dst->network_type = (srv_dtcnt_wlan_network_type_enum)src->network_type;                  /* Network type     */
    dst->encrypt_mode = (srv_dtcnt_wlan_encrypt_mode_enum)src->encrypt_mode;                  /* Encryption       */
    dst->auth_mode    = (srv_dtcnt_wlan_auth_mode_enum)src->auth_mode;                     /* Authentication   */

    /* WEP settings */
    if (dst->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WEP || 
        dst->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP)
    {
        dst->wep_key_index  = src->wep_key_index;
        dst->wep_key_len    = src->wep_key_len;
        dst->wep_key_format = (srv_dtcnt_wlan_wep_key_format_enum)src->wep_key_format;
        strcpy((S8 *)dst->wep_key, (S8 *)src->wep_key);
    }

    /* Pre-shared key settings. */
    if (dst->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK)
    {
        /* Default uses psk; otherwise, compute psk from passphrase. */
        if (src->psk[32] != 0)
        {
            memcpy(dst->psk, src->psk, 32);
        }
        else
        {
            strcpy((S8 *)dst->passphrase, (S8 *)src->passphrase);
            
        #ifdef __MTK_TARGET__
            pbkdf2_sha1(
                (S8 *)dst->passphrase,
                (S8 *)dst->ssid,
                dst->ssid_len,
                4096,
                dst->psk,
                32);
        #else
            memcpy(dst->psk, src->passphrase, 32);
        #endif
        }

        /* PSK is always provided. Turn on the flag. */
        dst->psk[32] = 1;
    }

    /* EAP settings. */
    if (dst->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X || 
        dst->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX)
    {
        dst->eap_auth_type= src->eap_auth_type;
        strcpy((S8 *)dst->username, (S8 *)src->username);
        strcpy((S8 *)dst->password, (S8 *)src->password);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_find_empty_profile
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  profile slot index < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM : empty slot id
 *  profile slot index = SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM : no empty slot
 *****************************************************************************/
U8 srv_dtcnt_wlan_find_empty_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Find an empty profile. */
    for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; ++i)
    {
        /* Whether the profile is empty. */
        if (srv_dtcnt_wlan_is_empty_profile(i) == MMI_TRUE) 
        {
            return i;
        }
    }
    return SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_is_empty_profile
 * DESCRIPTION
 *  This function examines whether the i-th slot in the profile list is used.
 * PARAMETERS
 *  i               [IN]            Used to specify i-th profile
 * RETURNS
 *  Return TRUE when profile is empty. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_is_empty_profile(U8 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* The profile is used originally. */
    if (g_srv_dtcnt_wlan_prof_list[i].ssid_len != 0) 
    {
        return MMI_FALSE;
    }

    /* The profile is selected during the OTA provisioning. */
    if (g_srv_dtcnt_wlan_otap->src_idx[i] >= 0) 
    {
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_otap_install_start
 * DESCRIPTION
 *  This function sends the processing wlan ota profile information to APP.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_otap_install_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_INSTALL_START);
    /* notify DA APP for installation */
    if (srv_dtcnt_wlan_find_empty_profile() == SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM)
    {
        srv_dtcnt_wlan_otap_install_notify(MMI_TRUE);
    }
    else
    {
        srv_dtcnt_wlan_otap_install_notify(MMI_FALSE);
    }
}

void srv_dtcnt_wlan_otap_install_notify(MMI_BOOL replace_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_slim_profile_struct *prof;
    srv_dtcnt_prov_ind_evt_struct evt;
    srv_dtcnt_prov_wlan_ind_struct *tmp_ind;
    srv_dtcnt_prov_ind_cb_func_ptr callback;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_PROV_IND);
    
    /* Obtain the current interesting profile. */
    prof = (srv_dtcnt_wlan_slim_profile_struct *)g_srv_dtcnt_wlan_otap->profile[g_srv_dtcnt_wlan_otap->iter];

    /* construct prov wlan ind for DA APP */
    tmp_ind = OslMalloc(sizeof(srv_dtcnt_prov_wlan_ind_struct));
    tmp_ind->AccountName = prof->name;
    tmp_ind->SSID = prof->ssid;
    tmp_ind->network_type = (srv_dtcnt_wlan_network_type_enum)prof->network_type;
    tmp_ind->auth_mode = (srv_dtcnt_wlan_auth_mode_enum)prof->auth_mode;
    tmp_ind->encrypt_mode = (srv_dtcnt_wlan_encrypt_mode_enum)prof->encrypt_mode;
    evt.prof_data = tmp_ind;
    if (replace_flag)
    {
        srv_dtcnt_wlan_otap_prof_name_list();
        kal_mem_cpy(evt.prof_name_list, g_srv_dtcnt_wlan_otap->prof_name_list, SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM * sizeof(PU8));
    }
    
    /* construct event struct */
    evt.num_profs = g_srv_dtcnt_wlan_otap->num_profiles;
    evt.prov_ind = SRV_DTCNT_PROV_IND_WLAN;
    evt.prov_type = (replace_flag)? SRV_DTCNT_PROV_TYPE_REPLACE : SRV_DTCNT_PROV_TYPE_ADD;
    evt.cur_prof_idx = g_srv_dtcnt_wlan_otap->iter;
    callback = (srv_dtcnt_prov_ind_cb_func_ptr)srv_dtcnt_wlan_prov_ind_callback;
    evt.cnf_callback = callback;

    MMI_FRM_CB_EMIT_POST_EVENT_EX((mmi_event_struct *)&evt, srv_dtcnt_wlan_event_callback, (void *)evt.prof_data);
}

void srv_dtcnt_wlan_otap_prof_name_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 sel_idx, i_src_idx;
    U8 i, count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_mem_set(g_srv_dtcnt_wlan_otap->prof_name_list, 0, SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM * sizeof(PU8));
    
    for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; ++i)
    {
        if (g_srv_dtcnt_wlan_prof_list[i].ssid_len == 0)
        {
            /* The slot is originally empty, but has been chosen to install
               incoming profile during OTA provisioning. */
            i_src_idx = g_srv_dtcnt_wlan_otap->src_idx[i];
            sel_idx   = g_srv_dtcnt_wlan_setting_ctx.profile_id_count + (count++);
            g_srv_dtcnt_wlan_otap->prof_name_list[sel_idx - CBM_DEFAULT_ACCT_ID - 1] = g_srv_dtcnt_wlan_otap->profile[i_src_idx]->name;
            g_srv_dtcnt_wlan_otap->sel_dst_idx[sel_idx - CBM_DEFAULT_ACCT_ID - 1] = i;
        }
        else
        {
            /* The profile is originally used. */
            i_src_idx = g_srv_dtcnt_wlan_otap->src_idx[i];
            sel_idx   = g_srv_dtcnt_wlan_prof_list[i].priority - 1;

            /* Whether the slot has been chosen to install incoming profiles. */
            if (i_src_idx >= 0) 
            {
                g_srv_dtcnt_wlan_otap->prof_name_list[sel_idx] = g_srv_dtcnt_wlan_otap->profile[i_src_idx]->name;
            } 
            else 
            {
                g_srv_dtcnt_wlan_otap->prof_name_list[sel_idx] = (U8 *)g_srv_dtcnt_wlan_prof_list[i].ProfName;
            }

            g_srv_dtcnt_wlan_otap->sel_dst_idx[sel_idx] = i;

        }
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_is_duplicate_name
 * DESCRIPTION
 *  This function examines whether the specified provisioning profile has a 
 *  duplicate name.
 * PARAMETERS
 *  src_idx         [IN]            Used to specify the profile
 * RETURNS
 *  When there is a duplication, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_is_duplicate_name(S16 src_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *name;
    S16 dst_idx, i_src_idx;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Obtain info about this specified provisioned profile. */
    name    = g_srv_dtcnt_wlan_otap->profile[src_idx]->name;
    dst_idx = g_srv_dtcnt_wlan_otap->dst_idx[src_idx];

    /* Check duplication by scanning all profiles. */
    for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; ++i)
    {
        /* Skip itself. */
        if (dst_idx == i) 
        {
            continue;
        }

        /* Obtain the name of the profile in the i-th slot at present. */
        i_src_idx = g_srv_dtcnt_wlan_otap->src_idx[i];

        if (i_src_idx >= 0)
        {
            /* i-th slot has been selected to install a incoming profile. */
            if (mmi_ucs2cmp((S8 *)name, (S8 *)g_srv_dtcnt_wlan_otap->profile[i_src_idx]->name) == 0) 
            {
                return MMI_TRUE;
            }
        }
        else if (g_srv_dtcnt_wlan_prof_list[i].ssid_len != 0)
        {
            /* A profile exists in i-th slot before OTA provisioning. */
            if (mmi_ucs2cmp((S8 *)name, (S8 *)g_srv_dtcnt_wlan_prof_list[i].ProfName) == 0) 
            {
                return MMI_TRUE;
            }
        }
    }

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_auto_rename_profile
 * DESCRIPTION
 *  This function renames the specified provisioned profile that has duplicate
 *  name.
 * PARAMETERS
 *  src_idx         [IN]            Used to specified the profile
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_auto_rename_profile(S16 src_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U16 *name[SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM];
    U8 num_names;
    S16 dst_idx, i_src_idx;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Collect the other profiles' names. */
    num_names = 0;
    dst_idx = g_srv_dtcnt_wlan_otap->dst_idx[src_idx];

    for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; ++i)
    {
        /* Skip itself. */
        if (dst_idx == i) 
        {
            continue;
        }

        /* Obtain the name of the profile in the i-th slot at present. */
        i_src_idx = g_srv_dtcnt_wlan_otap->src_idx[i];

        if (i_src_idx >= 0)
        {
            /* i-th slot has been selected to install an incoming profile. */
            name[num_names++] = (U16 *)g_srv_dtcnt_wlan_otap->profile[i_src_idx]->name;
        }
        else if (g_srv_dtcnt_wlan_prof_list[i].ssid_len != 0)
        {
            /* A profile exists in i-th slot before OTA provisioning. */
            name[num_names++] = (U16 *)(g_srv_dtcnt_wlan_prof_list[i].ProfName);
        }
    }

    /* Auto renaming. */
    srv_dtcnt_wlan_resolve_duplicate_name(g_srv_dtcnt_wlan_otap->profile[src_idx]->name, (const U8 **)name, num_names);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_otap_install
 * DESCRIPTION
 *  This function handles the install command from APP.
 * PARAMETERS
 *  void
 * RETURNS
 *  ret < 0 : install failed
 *  ret > 0 : the installed profile id
 *****************************************************************************/
void srv_dtcnt_wlan_otap_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_INSTALL);    

    /* Find an empty profile. */
    i = srv_dtcnt_wlan_find_empty_profile();
    MMI_ASSERT(i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM);
    
    /* Remember the index of the empty profile. */
    g_srv_dtcnt_wlan_otap->dst_idx[g_srv_dtcnt_wlan_otap->iter] = i;
    g_srv_dtcnt_wlan_otap->src_idx[i] = g_srv_dtcnt_wlan_otap->iter;

    /* Whether the profile's name is duplicate. */
    if (srv_dtcnt_wlan_is_duplicate_name(g_srv_dtcnt_wlan_otap->iter) == MMI_TRUE) 
    {
        srv_dtcnt_wlan_auto_rename_profile(g_srv_dtcnt_wlan_otap->iter);
    }
    g_srv_dtcnt_wlan_otap->cur_status = 2;
    
    /* Go to the next profile if it is presented. */
    srv_stcnt_wlan_otap_install_next();
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_otap_replace
 * DESCRIPTION
 *  This function handles the install command from APP.
 * PARAMETERS
 *  replace_idx :   [IN]    replace idx of profie name list
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_otap_replace(U8 replace_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 src_idx, dst_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_REPLACE, replace_idx);    
        
    /* The index of profile in profile list that plans to be replaced. */
    dst_idx = g_srv_dtcnt_wlan_otap->sel_dst_idx[replace_idx];

    /* Whether the profile has been selected to be replaced during OTA
       provisioning. If yes, the previously provisioned profile is replaced
       here and will not be install consequently. */
    src_idx = g_srv_dtcnt_wlan_otap->src_idx[dst_idx];
    
    if (src_idx >= 0) 
    {
        g_srv_dtcnt_wlan_otap->dst_idx[src_idx] = -1;
    }
    
    /* Save the replacement result. */
    g_srv_dtcnt_wlan_otap->src_idx[dst_idx] = g_srv_dtcnt_wlan_otap->iter;
    g_srv_dtcnt_wlan_otap->dst_idx[g_srv_dtcnt_wlan_otap->iter] = dst_idx;

    /* Whether the profile's name is duplicate. */
    if (srv_dtcnt_wlan_is_duplicate_name(g_srv_dtcnt_wlan_otap->iter) == MMI_TRUE) 
    {
        srv_dtcnt_wlan_auto_rename_profile(g_srv_dtcnt_wlan_otap->iter);
    }
    g_srv_dtcnt_wlan_otap->cur_status = 2;
    
    /* Go to the next profile if it is presented. */
    srv_stcnt_wlan_otap_install_next();
}

static void srv_dtcnt_wlan_otap_skip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_SKIP);

    if (g_srv_dtcnt_wlan_otap->cur_status != 2)
    {
        g_srv_dtcnt_wlan_otap->cur_status = 3;
    }
    srv_stcnt_wlan_otap_install_next();
}

/*****************************************************************************
 * FUNCTION
 *  srv_stcnt_wlan_otap_install_next
 * DESCRIPTION
 *  This function leads us to process next incoming profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_stcnt_wlan_otap_install_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 num_installed;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_INSTALL_NEXT);
    /* Increase the index of the iterator to process next profile. */
    ++g_srv_dtcnt_wlan_otap->iter;

    /* Whether there is another profile needed to be installed. */
    if (g_srv_dtcnt_wlan_otap->iter < g_srv_dtcnt_wlan_otap->num_profiles) 
    {
        /* Try to install next profile. */
        srv_dtcnt_wlan_otap_install_start();
    } 
    else 
    {
        /* Now, save the profiles into the NVRAM. */
        num_installed = srv_dtcnt_wlan_install_profiles();

        /* Send a response back to CCA and free memory. */    
        if (num_installed == 0) 
        {
            srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_wlan_otap->conf_id, g_srv_dtcnt_wlan_otap->doc_hdl, CCA_STATUS_SETTING_SKIPPED);
        } 
        else 
        {
            srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_wlan_otap->conf_id, g_srv_dtcnt_wlan_otap->doc_hdl, CCA_STATUS_OK);

            /* notify DA APP */
            srv_dtcnt_wlan_otap_done_notify(num_installed);
        }

        /* Free all allocated memory. */
        srv_dtcnt_wlan_free_otap_cntx();
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_install_profiles
 * DESCRIPTION
 *  This function installs each incoming profile that has been chosen to 
 *  install.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of installed profiles.
 *****************************************************************************/
U8 srv_dtcnt_wlan_install_profiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, k, num_installed = 0, replace, total_num = 0;
    srv_dtcnt_wlan_network_type_enum old_network;
    srv_dtcnt_wlan_slim_profile_struct *src_prof;
    srv_dtcnt_prof_wlan_struct dst_prof;
    srv_dtcnt_prov_install_res_ind_evt_struct evt;
    S16 src_idx, error;
    U32 size = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; ++i)
    {           
        /* Continue when no incoming profile plans to install in this slot. */
        if ((src_idx = g_srv_dtcnt_wlan_otap->src_idx[i]) < 0) 
        {
            continue;
        }
        else
        {
            total_num++;
        }
    }

    /* Install each profile. To make sure the order of installed profiles are
       correct, scan the slots, rather than profiles in the control block. */
    for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; ++i)
    {
        /* Continue when no incoming profile plans to install in this slot. */
        if ((src_idx = g_srv_dtcnt_wlan_otap->src_idx[i]) < 0) 
        {
            continue;
        }

        src_prof = g_srv_dtcnt_wlan_otap->profile[src_idx];
        kal_mem_cpy(&dst_prof, &g_srv_dtcnt_wlan_prof_list[i], sizeof(srv_dtcnt_prof_wlan_struct));
        old_network = g_srv_dtcnt_wlan_prof_list[i].network_type;
        replace = (g_srv_dtcnt_wlan_prof_list[i].priority > 0)? 1 : 0;

        /* Setup profile. Note that all context of dst_prof will be reset. */
        srv_dtcnt_wlan_provision_profile(&dst_prof, src_prof);

        /* Setup new priority, profile_id and update pointer. */
        switch (g_srv_dtcnt_wlan_setting_ctx.pri_criteria)
        {
            case SRV_DTCNT_WLAN_PROF_PRI_INFRA_NEW:
                srv_dtcnt_wlan_save_profiles(i, replace, old_network, &dst_prof);
                break;
            /* not support now, should not happened */
            default:
                MMI_ASSERT(0);
        }

        /* Notify CCA the success of installing each WLAN profile. */
        mmi_cca_oma_add_dataacctid(g_srv_dtcnt_wlan_otap->doc_hdl, (S8 *)src_prof->node_id, CBM_WIFI_ACCT_ID);

        /* Install successfully. Update counter. */        
        ++num_installed;

        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_PROV_INSTALL_RES_IND);
        mmi_ucs2ncpy((char *)(evt.name), (char *) (dst_prof.ProfName), SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN+1);
        evt.prof_idx = (num_installed);
        evt.num_profs = total_num;
        evt.acct_id = CBM_WIFI_ACCT_ID;
        evt.prov_ind = SRV_DTCNT_PROV_IND_WLAN;
        evt.prof_type = SRV_DTCNT_PROF_TYPE_OTA_CONF;
        evt.install_result = 1;
        MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_INSTALL_PROFILES, num_installed);
    if (num_installed)
    {
        for (k = 0; k < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; k++)
        {
            if (g_srv_dtcnt_wlan_prof_list[k].priority > 0)
            {                
                size = WriteRecord(NVRAM_EF_WLAN_PROFILE_LID, k + 1, &g_srv_dtcnt_wlan_prof_list[k], NVRAM_MAX_WLAN_PROFILE_SIZE, &error);
                
                if (size < NVRAM_MAX_WLAN_PROFILE_SIZE)
                {
                    MMI_ASSERT(0);
                }
            }
            else /* memset the removed accounts */
            {
                memset(&(g_srv_dtcnt_wlan_prof_list[k]), 0, sizeof(srv_dtcnt_prof_wlan_struct));
            }
        }

        /* profile_id_count has been updated. Save the context in the NVRAM. */
        WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, &error);
        if (error != NVRAM_WRITE_SUCCESS) 
        {
            MMI_ASSERT(0);
        }
    }
    return num_installed;
}

void srv_dtcnt_wlan_otap_done_notify(U8 num_installed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_prov_done_ind_evt_struct evt;
    srv_dtcnt_prov_wlan_done_ind_struct *tmp_ind;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_DONE, num_installed);
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_PROV_DONE_IND);    

    /* construct prov wlan done ind for DA APP */
    tmp_ind = OslMalloc(sizeof(srv_dtcnt_prov_wlan_done_ind_struct));
    tmp_ind->num_adhoc_profs = g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num;
    tmp_ind->num_infra_profs = g_srv_dtcnt_wlan_setting_ctx.infra_prof_num;
    if (g_srv_dtcnt_wlan_otap_active_prof_p)
    {
        tmp_ind->active_prof_id_valid = MMI_TRUE;
        tmp_ind->active_prof_id = g_srv_dtcnt_wlan_otap_active_prof_p->profile_id;
        g_srv_dtcnt_wlan_otap_active_prof_p = NULL;
    }
    else
    {
        tmp_ind->active_prof_id_valid = MMI_FALSE;
    }
    
    /* construct event struct */
    evt.prov_ind = SRV_DTCNT_PROV_IND_WLAN;
    evt.prof_data = tmp_ind;
    MMI_FRM_CB_EMIT_POST_EVENT_EX((mmi_event_struct *)&evt, srv_dtcnt_wlan_event_callback, (void *)evt.prof_data);
}


/*****************************************************************************
 * Use OMA extension OTAP spec.
 *****************************************************************************/
#if defined(__MMI_WLAN_OTAP_OMAEXT__)
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_base64_decoder
 * DESCRIPTION
 *  This function decodes the Base64 encoded data according to the RFC 1341.
 * PARAMETERS
 *  dst             [OUT]           Buffer for storing the decoded data
 *  dst_size        [IN]            Size of the dst buffer
 *  src             [IN]            Buffer of the input Base64 encoded data
 *  src_size        [IN]            #characters of the Base64 encoded data
 * RETURNS
 *  On success, it returns the number of decoded octets that are stored in the
 *  dst buffer. On error, 0 is returned, e.g., when the size of dst buffer is
 *  too small. 
 *****************************************************************************/
U32 srv_dtcnt_wlan_base64_decoder(S8 *dst, U32 dst_size, const S8 *src, U32 src_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*
     * Codebook used to decode Base64 data. Please refer to RFC 1341 and ASCII
     * encoding for more details.
     */
    const U8 codebook[] = 
    {
        62, 0xFF, 0xFF, 0xFF, 63,                       /* +, /     */
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61,         /* 0-9      */
        0xFF, 0xFF, 0xFF, 0, 0xFF, 0xFF, 0xFF,          /* =        */
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,                   /* A-Z      */
        10, 11, 12, 13, 14, 15, 16, 17,
        18, 19, 20, 21, 22, 23, 24, 25,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,             /* garbage  */
        26, 27, 28, 29, 30, 31, 32, 33, 34, 35,         /* a-z      */
        36, 37, 38, 39, 40, 41, 42, 43,
        44, 45, 46, 47, 48, 49, 50, 51
    };

    U8 in[4], out[3];               /* buffers to decode a quantum  */
    S8 count;                       /* #octet decoded for a quantum */
    U32 num_octets;                 /* #octet decoded from source   */
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Initialize the number of octets decoded from the Base64 data. */
    num_octets = 0;

    /* Start the Base64 decoding process. */
    for (i = 0; i < src_size;) 
    {
        /* Initialize #octet decoded for a quantum without padding. */
        count = 3;

        /* Obtain a quantum to be decoded. */
        for (j = 0; j < 4; ++j) 
        {

            /* Ignore line breaks and other characters not found in the
               table of Base64 specification. */
            do 
            {
                /* Read one character from the Base64 data. If the data steam 
                   is empty, assign the padding character '='. */
                if (i < src_size) 
                {
                    in[j] = src[i++];
                } 
                else 
                {
                    in[j] = '=';
                }

                /* Padding happened. Decrease count for the decoded result.
                   Note that count might be negative when there is nothing to
                   commit to the destination buffer. */
                if (in[j] == '=') 
                {
                    --count;
                }

                /* decode the character by table look-up. */
                if (in[j] >= '+' && in[j] <= 'z') 
                {
                    in[j] = codebook[in[j] - '+'];
                } 
                else 
                {
                    in[j] = 0xFF;
                }
            } while (in[j] == 0xFF);
        }

        /* decode the quantum. */
        out[0] = (U8)(in[0] << 2 | in[1] >> 4);
        out[1] = (U8)(in[1] << 4 | in[2] >> 2);
        out[2] = (U8)(in[2] << 6 | in[3]);

        /* commit the result when we have decoded octets actually. */
        if (count > 0) 
        {
            /* check whether the size of the dst buffer is enough. */
            if (num_octets + count > dst_size || UINT_MAX - count < num_octets) 
            {
                return 0;
            }

            /* commit the result to the destination buffer. */
            memcpy(dst + num_octets, out, count);
            num_octets += count;
        }
    }

    return num_octets;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_has_otap_profile
 * DESCRIPTION
 *  This function checks whether there is a new WLAN profile in the document.
 *  The input data list contains the parameters and their values of a NAPDEF
 *  node. Care should be take that the input iterator is reset after calling
 *  the function.
 * PARAMETERS
 *  param_list       [IN]           Parameter list for a NAPDEF node
 * RETURNS
 *  If there is a new WLAN profile, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_has_otap_profile(cca_iterator_struct *param_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *bearer;
    S32 num_bearers;
    cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /* Extract the value of the parameter BEARER. */
    status = mmi_cca_doc_get_nodedata_ints(param_list, CCA_NS_OMA_BEARER, &bearer, &num_bearers);
    mmi_cca_iterator_restart(param_list);

    if (status != CCA_STATUS_OK) 
    {
        return MMI_FALSE;
    }

    /* Whether there is a WLAN bearer. */ 
    while (--num_bearers >= 0)
    {
        if (bearer[num_bearers] == CCA_NS_VAL_WLAN) 
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_proc_cca_param_wepkey
 * DESCRIPTION
 *  This function processes the parameter of WEPKEY node.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  prof            [IN/OUT]        The current provisioned profile
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum srv_dtcnt_wlan_proc_cca_param_wepkey(
                    const cca_core_data_struct *param, 
                    srv_dtcnt_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 num_octets;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * Dispatching according to the parameter symbol 
     */
    switch (param->id)
    {
        case CCA_NS_OMA_LENGTH:
            
            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }
            
            switch (atoi(param->values.s[0]))
            {
                case 40:
                    /* 40-bits WEP key  +  24-bits IV  =  64 bits */
                    prof->wep_key_len = SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64;
                    break;

                case 104:
                    /* 104-bits WEP key  +  24-bits IV  =  128 bits */
                    prof->wep_key_len = SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128;
                    break;

                default:
                    return CCA_STATUS_FAIL;            
            }
            
            break;

        case CCA_NS_OMA_DATA:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (srv_dtcnt_wlan_is_ascii_string((U8 *)param->values.s[0]) == MMI_FALSE) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Compute the WEP key. */
            num_octets = srv_dtcnt_wlan_base64_decoder(
                            (S8 *)prof->wep_key, 
                            SRV_DTCNT_PROF_MAX_WEP_KEY_LEN, 
                            param->values.s[0], 
                            strlen(param->values.s[0]));

            /* Fail when wep_key buffer is too small, or length is illegal. */
            if (num_octets != 5 && num_octets != 13) 
            {
                return CCA_STATUS_FAIL;
            }

            prof->wep_key[num_octets] = '\0';

            /* Set WEP key length when this entry is not set yet. */
            if (prof->wep_key_len == SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_TOTAL) 
            {
                if (num_octets == 5) 
                {
                    prof->wep_key_len = SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64;
                } 
                else
                {
                    prof->wep_key_len = SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128;
                }
            }
            
            break;

        case CCA_NS_OMA_INDEX:
        default:
            break;
    }
    
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_proc_cca_param_eap
 * DESCRIPTION
 *  The function processes the parameter of EAP node.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  prof            [IN/OUT]        The current provisioned profile    
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum srv_dtcnt_wlan_proc_cca_param_eap(
                    const cca_core_data_struct *param, 
                    srv_dtcnt_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * Dispatching according to the parameter symbol 
     */
    switch (param->id)
    {
        case CCA_NS_OMA_EAPTYPE:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_INT) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Only support EAP SIM currently. */
            switch (param->values.i[0])
            {
                case CCA_NS_VAL_EAP_SIM:
                    prof->eap_auth_type |= WLAN_EAP_SIM;
                    break;
                    
                default:
                    return CCA_STATUS_FAIL;
            }
            
            break;

        case CCA_NS_OMA_USERNAME:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Check whether the length of the username is legal. */
            str_len = mmi_chset_utf8_strlen((kal_uint8 *)param->values.s[0]);
            if (str_len > SRV_DTCNT_PROF_MAX_USER_LEN) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (srv_dtcnt_wlan_is_ascii_string((U8 *)param->values.s[0]) == MMI_FALSE) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Obtain the username. Zero-terminate username. */
            strcpy((S8 *)prof->username, param->values.s[0]);        
            
            break;

        case CCA_NS_OMA_PASSWORD:

            
            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Check whether the length of the password is legal. */
            str_len = mmi_chset_utf8_strlen((kal_uint8 *)param->values.s[0]);
            if (str_len > SRV_DTCNT_PROF_MAX_PW_LEN) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (srv_dtcnt_wlan_is_ascii_string((U8 *)param->values.s[0]) == MMI_FALSE) 
            {
                return CCA_STATUS_FAIL;
            }
            
            /* Obtain the password. Zero-terminate password. */
            strcpy((S8 *)prof->password, param->values.s[0]);            
            
            break;

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_proc_cca_param_wlan
 * DESCRIPTION
 *  This function processes the parameter of WLAN node.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  prof            [IN/OUT]        The current provisioned profile
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum srv_dtcnt_wlan_proc_cca_param_wlan(
                    const cca_core_data_struct *param, 
                    srv_dtcnt_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    U8 base64_buf[64];
    S32 value;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * Dispatching according to the parameter symbol 
     */
    switch (param->id)
    {
        case CCA_NS_OMA_PRI_SSID:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether the length of the SSID is legal. */
            str_len = mmi_chset_utf8_strlen((kal_uint8 *)param->values.s[0]);
            if (str_len > SRV_DTCNT_PROF_MAX_SSID_LEN) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (srv_dtcnt_wlan_is_ascii_string((U8 *)param->values.s[0]) == MMI_FALSE) 
            {
                return CCA_STATUS_FAIL;
            }
            
            /* Get SSID in ASCII format. Zero-terminate SSID. */
            prof->ssid_len = str_len;
            strcpy((S8 *)prof->ssid, param->values.s[0]);

            break;
        
        case CCA_NS_OMA_NETMODE:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_INT) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Extract setting. */
            switch (param->values.i[0])
            {
                case CCA_NS_VAL_INFRA:
                    prof->network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA;
                    break;

                case CCA_NS_VAL_ADHOC:
                    prof->network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC;
                    break;

                default:
                    return CCA_STATUS_FAIL;
            }
            
            break;

        case CCA_NS_OMA_WPA_PRES_KEY_ASC:
            
            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Check whether the length of the passphrase is legal. */
            str_len = mmi_chset_utf8_strlen((kal_uint8 *)param->values.s[0]);
            if (str_len < SRV_DTCNT_MIN_PASSPHRASE_LEN || str_len > SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (srv_dtcnt_wlan_is_ascii_string((U8 *)param->values.s[0]) == MMI_FALSE) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Get passphrase in ASCII format. Zero-terminate passphrase. */
            strcpy((S8 *)prof->passphrase, param->values.s[0]);

            break;

        case CCA_NS_OMA_WPA_PRES_KEY_HEX:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Length of the Base64 data should be 88 bytes for 64 HEX chars 
               (256 bits). Please refer to Base64 encoding method. */
            str_len = mmi_chset_utf8_strlen((kal_uint8 *)param->values.s[0]);
            if (str_len != 88) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (srv_dtcnt_wlan_is_ascii_string((U8 *)param->values.s[0]) == MMI_FALSE) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Obtain the HEX format pre-shared key. It should be 64 bytes. */
            if (srv_dtcnt_wlan_base64_decoder(
                    (S8 *)base64_buf, 
                    sizeof(base64_buf) / sizeof(U8), 
                    param->values.s[0], 
                    str_len) != 64) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Convert 64 bytes HEX data to 256 bits raw data. */
            if (srv_dtcnt_wlan_hex_to_psk(prof->psk, base64_buf, 64) == MMI_FALSE) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Turn on the 33-bytes when PSK is set. */
            prof->psk[32] = 1;
            
            break;

        case CCA_NS_OMA_WEPKEYIND:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Check whether the index is legal. */
            value = atoi(param->values.s[0]);
            
            if (value < 0 || value >= SRV_DTCNT_MAX_WEP_KEY_NUM) 
            {
                return CCA_STATUS_FAIL;
            }

            prof->wep_key_index = value;
            
            break;

        case CCA_NS_OMA_WEPAUTHMODE:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_INT) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Extract the setting. */
            switch (param->values.i[0])
            {
                case CCA_NS_VAL_OPEN:
                    prof->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
                    break;
            
                case CCA_NS_VAL_SHARED:
                    prof->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WEP;
                    break;
            
                default:
                    return CCA_STATUS_FAIL;
            }
            
            break;

        case CCA_NS_OMA_SECMODE:
        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_proc_cca_param_napdef
 * DESCRIPTION
 *  This function processes the parameter of WLAN node.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  cntx            [IN/OUT]        The WLAN OTAP control block
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum srv_dtcnt_wlan_proc_cca_param_napdef(
                    const cca_core_data_struct *param, 
                    srv_dtcnt_wlan_otap_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * Dispatching according to the parameter symbol 
     */
    switch (param->id)
    {
        case CCA_NS_NODEID:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }
            
            /* Whether the string's raw length is legal. */
            str_len = strlen(param->values.s[0]);
            if (str_len > SRV_DTCNT_MAX_NODE_ID_LEN) 
            {
                return CCA_STATUS_FAIL;
            }
            
            /* Extract the node id. Store it as UTF-8 string. */
            strcpy((S8 *)cntx->node_id, param->values.s[0]);

            break;

        case CCA_NS_OMA_NAME:

            /* Whether the value is presented and the type is legal. If it's
               illegal, default name will be used. Still return OK. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_OK;   /* Error-tolerant for profile's name */
            }

            /* Extract the profile's name. If the name is too long, it will be
               truncated by the function. */
            mmi_chset_utf8_to_ucs2_string(
                cntx->name, 
                (SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN+1)* ENCODING_LENGTH, 
                (U8 *)param->values.s[0]);

            break;
                        
        case CCA_NS_OMA_NAPID:
        case CCA_NS_OMA_BEARER:
        default:
            /* All other parameters are skipped. And the status is OK. */
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_proc_cca_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  doc_hdl         [IN]            Configuration document handle
 *  node_hdl        [IN]            The node handle
 *  symbol          [IN]            The converted node symbol
 *  param_list      [IN]            List of parameters in the node
 *  user_data       [IN]            User data         
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum srv_dtcnt_wlan_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_otap_struct *cntx;
    cca_core_data_struct *param;
    S8 *value_s;
    S32 value_i;
    S32 wep_key_index;
    cca_status_enum status;
    S16 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Obtain the control block. */
    cntx = (srv_dtcnt_wlan_otap_struct *)user_data;

    /* We always process NAPDEF nodes to obtain node_id. We always process
       WLAN nodes to obtain profiles. For other nodes, the behavior is
       controlled by is_active parameter. */
    if (symbol != WLAN_OTAP_NS_NAPDEF && symbol != WLAN_OTAP_NS_WLAN &&
        cntx->is_active != MMI_TRUE) 
    {
        return CCA_STATUS_OK;
    }

    /* 
     * Dispatch the node according to the node symbol.
     */
    status = CCA_STATUS_OK;             /* Initialize the status variable   */
    index  = cntx->num_profiles - 1;    /* Obtain the last profile          */
    
    switch (symbol)
    {
        case WLAN_OTAP_NS_NAPDEF:

            /* Clear node_id and name for previous NAPDEF node. */
            memset(cntx->node_id, 0, SRV_DTCNT_MAX_NODE_ID_LEN+1);
            memset(cntx->name, 0, (SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN+1) * ENCODING_LENGTH);

            /* Traverse each parameter in NAPDEF node. */ 
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
            {
                status = srv_dtcnt_wlan_proc_cca_param_napdef(param, cntx);
            }

            /* NAPDEF doesn't know the correctness of a WLAN profile. Always 
               return OK. */
            return CCA_STATUS_OK;
            
        case WLAN_OTAP_NS_WLAN:

            /* Whether we have node_id */
            if (strlen((S8 *)cntx->node_id) == 0) 
            {
                cntx->is_active = MMI_FALSE;
                return CCA_STATUS_FAIL;
            }
            
            /* Prepare a storage for the new profile. And get the new index. */
            if ((index = srv_dtcnt_wlan_new_otap_profile(cntx)) < 0)
            {
                cntx->is_active = MMI_FALSE;
                return CCA_STATUS_FAIL;
            }

            /* Enable to process parameters/nodes in the WLAN node. */
            cntx->is_active = MMI_TRUE;

            /* Remember the name, and node_id which this profile belongs to. */
            if (mmi_ucs2strlen((S8 *)cntx->name) != 0) 
            {
                mmi_ucs2cpy((S8 *)cntx->profile[index]->name, (S8 *)cntx->name);
            }
            strcpy((S8 *)cntx->profile[index]->node_id, (S8 *)cntx->node_id);
                        
            /* Before processing other parameters, obtain the security mode. */
            if (mmi_cca_doc_get_nodedata_int_first(param_list, CCA_NS_OMA_SECMODE, &value_i) == CCA_STATUS_OK)
            {
                switch (value_i)
                {
                    case CCA_NS_VAL_WEP:
                        cntx->profile[index]->auth_mode     = SRV_DTCNT_WLAN_AUTH_MODE_WEP;
                        cntx->profile[index]->encrypt_mode  = SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP;
                        break;
                
                    case CCA_NS_VAL_8021X:
                        cntx->profile[index]->auth_mode     = SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X;
                        cntx->profile[index]->encrypt_mode  = SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP;
                        break;
                
                    case CCA_NS_VAL_WPA:
                        cntx->profile[index]->auth_mode     = SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX;
                        cntx->profile[index]->encrypt_mode  = SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP;
                        break;
                
                    case CCA_NS_VAL_WPA_PRESHARED_KEY:
                        cntx->profile[index]->auth_mode     = SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK;
                        cntx->profile[index]->encrypt_mode  = SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP;
                        break;
                
                    case CCA_NS_VAL_WPA2:
                        cntx->profile[index]->auth_mode     = SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX;
                        cntx->profile[index]->encrypt_mode  = SRV_DTCNT_WLAN_ENCRYPT_MODE_AES;
                        break;
                
                    case CCA_NS_VAL_WPA2_PRESHARED_KEY:
                        cntx->profile[index]->auth_mode     = SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK;
                        cntx->profile[index]->encrypt_mode  = SRV_DTCNT_WLAN_ENCRYPT_MODE_AES;
                        break;
                
                    /* to-do: need add new auth-types which were added from W11.41*/
                
                    default:
                        return CCA_STATUS_FAIL;
                }
            }
            
            /* Traverse other parameter in WLAN node */
            mmi_cca_iterator_restart(param_list);

            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
            {
                status = srv_dtcnt_wlan_proc_cca_param_wlan(param, cntx->profile[index]);
            }
            break;

        case WLAN_OTAP_NS_EAP:

            /* Traverse each parameter in EAP node */
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
            {
                status = srv_dtcnt_wlan_proc_cca_param_eap(param, cntx->profile[index]);
            }
            break;
            
        case WLAN_OTAP_NS_WEPKEY:

            /* Return if WEP key has been set. */
            if (strlen((S8 *)cntx->profile[index]->wep_key) != 0) 
            {
                return CCA_STATUS_OK;
            }

            /* Pre-determine the key index if it's presented. */
            if (mmi_cca_doc_get_nodedata_str_first(param_list, CCA_NS_OMA_INDEX, &value_s) != CCA_STATUS_OK)
            {
                wep_key_index = SRV_DTCNT_MAX_WEP_KEY_NUM; /* Init an invalid index */
            }
            else
            {
                /* If it's presented, the range must be correct. */
                wep_key_index = atoi(value_s);
                
                if (wep_key_index < 0 || wep_key_index >= SRV_DTCNT_MAX_WEP_KEY_NUM) 
                {
                    return CCA_STATUS_OK;
                }
            }
            
            /* If WEP key index is specified in WLAN node, it must match the
               index in this WEPKEY node. */
            if (cntx->profile[index]->wep_key_index < SRV_DTCNT_MAX_WEP_KEY_NUM)
            {
                if (wep_key_index != cntx->profile[index]->wep_key_index) 
                {
                    return CCA_STATUS_OK;
                } 
            }
            
            /* Traverse each parameter in WEPKEY node */
            mmi_cca_iterator_restart(param_list);

            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
            {
                status = srv_dtcnt_wlan_proc_cca_param_wepkey(param, cntx->profile[index]);
            }

            /* If successfully get the WEP key, update the key index. */
            if (strlen((S8 *)cntx->profile[index]->wep_key) != 0) 
            {
                cntx->profile[index]->wep_key_index = (wep_key_index < SRV_DTCNT_MAX_WEP_KEY_NUM ? wep_key_index: 0);
            }
            
            break;

        case WLAN_OTAP_NS_SEC_SSID:
        case WLAN_OTAP_NS_CERT:
        
            /* Useless characteristic type. Still return OK since the profile 
               might work well even without these settings. And this will be 
               checked in the validation phase. */
            return CCA_STATUS_OK;

        default:
            /* A traversing not matched to the namespace definition. */
            MMI_ASSERT(0);
    }


    /* If the node or any parameters of the node can not be processed, update
       the context to stop processing the current profile. And release the 
       memory of the current profile. */
    if (status == CCA_STATUS_FAIL)
    {
        cntx->is_active = MMI_FALSE;
        srv_dtcnt_wlan_free_otap_profile(cntx, index);
    }
    
    return status;
}

/***************************************************************************** 
 * Use the proprietary OTAP spec. 
 *****************************************************************************/
#elif defined(__MMI_WLAN_OTAP_DMP__)
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_proc_cca_node_profile
 * DESCRIPTION
 *  This function pre-processes the parameters in the profile node.
 * PARAMETERS
 *  param_list      [IN]            The parameter list in the node
 *  prof            [IN/OUT]        The current provisioned profile
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum srv_dtcnt_wlan_proc_cca_node_profile(
                    cca_iterator_struct *param_list, 
                    srv_dtcnt_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *encrypt, *auth;
    cca_status_enum en_status, au_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Obtain the encryption and authentication method. */
    en_status = mmi_cca_doc_get_nodedata_str_first(
                    param_list, 
                    CCA_NS_OMADMP_ENCRYPTION, 
                    &encrypt);
    mmi_cca_iterator_restart(param_list);

    au_status = mmi_cca_doc_get_nodedata_str_first(
                    param_list, 
                    CCA_NS_OMADMP_AUTHENTICATION, 
                    &auth);
    mmi_cca_iterator_restart(param_list);

    /* Output traces if encryption or authentication method is specified. */
    if (en_status == CCA_STATUS_OK && encrypt != NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_ENCRYPTION, atoi(encrypt));
    }

    if (au_status == CCA_STATUS_OK && auth != NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_AUTHENTICATION, atoi(auth));
    }

    /* 
     * Determine the encryption method.
     */
    if (en_status != CCA_STATUS_OK) 
    {
        /* Use default encryption if parameter is not present. */
        prof->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP;
    }
    else 
    {
        /* Discard profile if parameter value is not present. */
        if (encrypt == NULL)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_FAIL_ENCRYPT);
            return CCA_STATUS_FAIL;
        }

        /* Determine encryption method according to the value. */
        switch (atoi(encrypt))
        {
            case 0:
                /* WEP */
                prof->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP;
                break;
                
            case 1:
                /* No encryption */
                prof->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE;
                break;
                
            case 4:
                /* TKIP */
                prof->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP;
                break;

            case 6:
                /* AES  */
                prof->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_AES;
                break;
                
            default:
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_FAIL_ENCRYPT_SWITCH);
                return CCA_STATUS_FAIL; /* Discard profile */
        }
    }

    /* 
     * Determine the authentication method.
     */
    if (au_status != CCA_STATUS_OK)
    {
        /* Use default authentication if parameter is not present. */
        prof->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
    }
    else
    {
        /* Discard profile if parameter value is not present. */
        if (auth == NULL)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_FAIL_AUTH);
            return CCA_STATUS_FAIL;
        }

        /* Determine authentication method according to the value. */
        switch (atoi(auth))
        {
            case 0:
                /* Open */
                prof->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
                break;
                
            case 1:
                /* SHARED */
                prof->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WEP;
                break;

            case 3:
                /* WPA: unsupported */
                return CCA_STATUS_FAIL;

            case 4:
                /* 4 is for WPA-PSK, while 7 is for WPA2-PSK. And both are 
                   valid for infrastructure network only. */
                if (prof->network_type != SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
                {
                    return CCA_STATUS_FAIL;
                }
                prof->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK;
                break;                
            case 7:
                /* 4 is for WPA-PSK, while 7 is for WPA2-PSK. And both are 
                   valid for infrastructure network only. */
                if (prof->network_type != SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
                {
                    return CCA_STATUS_FAIL;
                }
                prof->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK;
                break;

            case 5:
                /* WPA-NONE. This is valid for ad-hoc network only. */
                if (prof->network_type != SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
                {
                    return CCA_STATUS_FAIL;
                }
                prof->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK;
                break;

            default:
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_FAIL_AUTH_SWITCH);
                return CCA_STATUS_FAIL; /* Discard profile */
        }
    }
    
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_proc_cca_param_infra
 * DESCRIPTION
 *  This function processes the parameter of access-ponit/profile node.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  prof            [IN/OUT]        The current provisioned profile
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum srv_dtcnt_wlan_proc_cca_param_profile(
                    const cca_core_data_struct *param, 
                    srv_dtcnt_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    S32 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->id)
    {
        case CCA_NS_NODEID:
            
            /* Whether the type is legal and the value is present. */
            if (param->type != CCA_DT_STR || param->values.s[0] == NULL)
            {
                return CCA_STATUS_FAIL;
            }
            
            /* Whether the string's raw length is legal. */
            if (strlen(param->values.s[0]) > SRV_DTCNT_MAX_NODE_ID_LEN) 
            {
                return CCA_STATUS_FAIL;
            }
            
            /* Extract the node id. Store it as UTF-8 string. */
            strcpy((S8 *)prof->node_id, param->values.s[0]);

            break;
            
        case CCA_NS_OMADMP_SSID:

            /* Whether the type is legal and the value is present. */
            if (param->type != CCA_DT_STR || param->values.s[0] == NULL)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_FAIL_SSID);
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (srv_dtcnt_wlan_is_ascii_string((U8 *)param->values.s[0]) == MMI_FALSE) 
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_FAIL_SSID_FORMAT);
                return CCA_STATUS_FAIL;
            }

            /* Whether the length of the SSID is legal. */
            if ((str_len = strlen(param->values.s[0])) > SRV_DTCNT_PROF_MAX_SSID_LEN) 
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_FAIL_SSID_FORMAT);
                return CCA_STATUS_FAIL;
            }

            /* Get SSID in ASCII and zero-terminated format. */
            prof->ssid_len = str_len;
            strcpy((S8 *)prof->ssid, param->values.s[0]);

            /* SSID is also the profile name. */
            memset(prof->name, 0, (SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN+1) * ENCODING_LENGTH);
            mmi_asc_n_to_ucs2((S8 *)prof->name, param->values.s[0], SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN+1);
            
            break;

        case CCA_NS_OMADMP_NETWORKKEY:

            /* Network key is meaningless for OPEN network. */
            if (prof->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN && 
                prof->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
            {
                return CCA_STATUS_OK;
            }
            
            /* Whether the type is legal and the value is present. */
            if (param->type != CCA_DT_STR || param->values.s[0] == NULL)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_FAIL_NW_KEY);
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (srv_dtcnt_wlan_is_ascii_string((U8 *)param->values.s[0]) == MMI_FALSE)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_FAIL_NW_KEY_FORMAT);
                return CCA_STATUS_FAIL;
            }

            /* 
             * The usage of the key has four different cases. Using the auth,
             * encryption, and key string length can determine the cases. If 
             * security solution does not need any key, ignore this parameter.
             *
             *  1) WEP key in ASCII format
             *  2) WEP key in HEX format
             *  3) WPA-PSK key in ASCII format
             *  4) WPA-PSK key in HEX format
             */
            str_len = strlen(param->values.s[0]);

            if (prof->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP || 
                prof->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_AES)
            {
                /* 
                 * For TKIP or AES encryption methods. 
                 */
                if (str_len >= SRV_DTCNT_MIN_PASSPHRASE_LEN && str_len <= SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN)
                {
                    strcpy((S8 *)prof->passphrase, param->values.s[0]);
                }
                else if (str_len == 64)
                {
                    /* Obtain 256-bits PSK from 64-bytes HEX. */
                    if (srv_dtcnt_wlan_hex_to_psk(
                                        prof->psk, 
                                        (U8 *)param->values.s[0], 
                                        64) == MMI_FALSE)
                    {
                        return CCA_STATUS_FAIL;
                    }

                    /* Turn on the 33-bytes when PSK is set. */
                    prof->psk[32] = 1;
                }
                else
                {
                    return CCA_STATUS_FAIL;
                }
            }
            else if (prof->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WEP || 
                     prof->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP)
            {
                /* 
                 * For WEP security. 
                 */
                switch (str_len)
                {
                    case 5:
                        prof->wep_key_len    = SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64;
                        prof->wep_key_format = SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII;
                        break;
                        
                    case 10:
                        /* Examine whether input is a valid HEX string. */
                        if (!srv_dtcnt_is_valid_hexstring((U8 *)param->values.s[0], (U8)str_len))
                        {
                            return CCA_STATUS_FAIL;
                        }
                        prof->wep_key_len    = SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64;
                        prof->wep_key_format = SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX;
                        break;
                        
                    case 13:
                        prof->wep_key_len    = SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128;
                        prof->wep_key_format = SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII;
                        break;
                        
                    case 26:
                        /* Examine whether input is a valid HEX string. */
                        if (!srv_dtcnt_is_valid_hexstring((U8 *)param->values.s[0], (U8)str_len))
                        {
                            return CCA_STATUS_FAIL;
                        }
                        prof->wep_key_len    = SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128;
                        prof->wep_key_format = SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX;
                        break;
                        
                    default:
                        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_FAIL_WEP_KEY_LEN);
                        return CCA_STATUS_FAIL;
                }

                /* Obtain the key. */
                strcpy((S8 *)prof->wep_key, param->values.s[0]);

                /* Setup a default key index value if it is not set yet. */
                if (prof->wep_key_index == SRV_DTCNT_MAX_WEP_KEY_NUM) 
                {
                    prof->wep_key_index = 0;
                }
            }
            
            break;

        case CCA_NS_OMADMP_KEYINDEX:

            /* This parameter is only valid when WEP security is used. */
            if (prof->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WEP || 
                prof->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP)
            {
                /* Whether the type is legal and the value is present. */
                if (param->type != CCA_DT_STR || param->values.s[0] == NULL)
                {
                    return CCA_STATUS_FAIL;
                }
                
                /* Check whether the index is legal. */
                value = atoi(param->values.s[0]);
                
                if (value >= 1 && value <= SRV_DTCNT_MAX_WEP_KEY_NUM) 
                {
                    prof->wep_key_index = value - 1;
                }
                else
                {
                    return CCA_STATUS_FAIL; /* Discard profile */
                }
            }
            
            break;

        case CCA_NS_OMADMP_AUTHENTICATION:  /* Already processed */
        case CCA_NS_OMADMP_ENCRYPTION:      /* Already processed */
        case CCA_NS_OMADMP_ADHOC:           /* Useless           */
        case CCA_NS_OMADMP_KEYPROVIDED:     /* Useless           */
        case CCA_NS_OMADMP_USE8021X:        /* Unsupported       */
        case CCA_NS_OMADMP_EAPTYPE:         /* Unsupported       */
            break;
        default:
            MMI_ASSERT(0);  /* Impossible to reach here */
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_proc_cca_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  doc_hdl         [IN]            Configuration document handle
 *  node_hdl        [IN]            The node handle
 *  symbol          [IN]            The converted node symbol
 *  param_list      [IN]            List of parameters in the node
 *  user_data       [IN]            User data         
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum srv_dtcnt_wlan_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_otap_struct *cntx;
    cca_core_data_struct *param;
    cca_status_enum status;
    S16 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Obtain the OTAP control block. */
    cntx = (srv_dtcnt_wlan_otap_struct *)user_data;

    /* Prepare a storage for the new profile. And get the new index. */
    if ((index = srv_dtcnt_wlan_new_otap_profile(cntx)) < 0)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_FAIL_INDEX_INSTALL);
        return CCA_STATUS_FAIL;
    }

    /* Dispatch the node according to the node symbol. */
    status = CCA_STATUS_OK;
    
    switch (symbol)
    {
        case WLAN_OTAP_NS_INFRA:
            cntx->profile[index]->network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA;
            break;

        case WLAN_OTAP_NS_ADHOC:
            cntx->profile[index]->network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC;
            break;
            
        default:
            MMI_ASSERT(0);  /* Impossible to reach here */
    }

    /* Pre-process the profile node. */
    status = srv_dtcnt_wlan_proc_cca_node_profile(param_list, cntx->profile[index]);
    
    /* Traverse other parameters in the profile node. */
    while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
    {
        status = srv_dtcnt_wlan_proc_cca_param_profile(param, cntx->profile[index]);
    }

    /* If we fail to process the profile, release the memory. */
    if (status == CCA_STATUS_FAIL)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_PRE_DISCARD_PROF);
        srv_dtcnt_wlan_free_otap_profile(cntx, index);
    }
    
    return status;
}
#endif /* ! (defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)) */

#define WLAN_OTAP_EXTERN_APIs

#if defined(__MMI_WLAN_OTAP_OMAEXT__)
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_proc_cca_doc
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to WLAN
 *  data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_proc_cca_doc(U16 conf_id, S32 doc_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*
     * Mapping table used to extract the WLAN settings for each profile. All 
     * characteristics are included such that unsupported fields can also be
     * found out.
     */
    const U16 proc_tbl[] = 
    {
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, 
            WLAN_OTAP_NS_NAPDEF, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, CCA_NS_OMA_WLAN, 
            WLAN_OTAP_NS_WLAN, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, CCA_NS_OMA_WLAN, CCA_NS_OMA_SEC_SSID, 
            WLAN_OTAP_NS_SEC_SSID, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, CCA_NS_OMA_WLAN, CCA_NS_OMA_EAP, 
            WLAN_OTAP_NS_EAP, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, CCA_NS_OMA_WLAN, CCA_NS_OMA_EAP, CCA_NS_OMA_CERT, 
            WLAN_OTAP_NS_CERT, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, CCA_NS_OMA_WLAN, CCA_NS_OMA_WEPKEY, 
            WLAN_OTAP_NS_WEPKEY, 0xFFFF
    };

    cca_status_enum status;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_RECV_DOC);

    /* Whether any other OTA provisioning process is still running. */
    if (g_srv_dtcnt_wlan_otap != NULL) 
    {
        MMI_ASSERT(0);  /* Guaranteed by CCA that this should not happen */
    }
    
    /* Init control block and save the ID/handle for the response msg. */
    g_srv_dtcnt_wlan_otap = srv_dtcnt_wlan_new_otap_cntx(conf_id, doc_hdl);

    if (g_srv_dtcnt_wlan_otap == NULL) 
    {
        srv_dtcnt_send_cca_app_configure_rsp(conf_id, doc_hdl, CCA_STATUS_FAIL);
        return;
    }
    
    /* Extract WLAN settings from CCA configuration document, and store 
       settings in the temporary storage. */
    status = mmi_cca_doc_process(
                doc_hdl, 
                proc_tbl,
                sizeof(proc_tbl) / sizeof(U16),
                NULL, 
                srv_dtcnt_wlan_proc_cca_nodes, 
                g_srv_dtcnt_wlan_otap);


    /* Whether each profile contains all mandatory fields. */
    for (i = 0; i < g_srv_dtcnt_wlan_otap->num_profiles; ) 
    {
        /* If valid, examine next profile. If invalid, free the profile. */
        if (srv_dtcnt_wlan_validate_profile(g_srv_dtcnt_wlan_otap->profile[i]) == MMI_TRUE)
        {
            ++i;
        } 
        else 
        {
            /* Profiles are shifted. No need to increase the index. */
            srv_dtcnt_wlan_free_otap_profile(g_srv_dtcnt_wlan_otap, i);
            status = CCA_STATUS_FAIL;
        }
    }

    /* If there is no correct WLAN profile, send a FAIL response message back
       to CCA. Popup a notification screen to inform the user. */
    if (g_srv_dtcnt_wlan_otap->num_profiles == 0) 
    {
        /* Now, terminate the WLAN OTA provisioning application. */
        srv_dtcnt_send_cca_app_configure_rsp(conf_id, doc_hdl, CCA_STATUS_INVALID_SETTING);
        srv_dtcnt_wlan_free_otap_cntx();
        return;
    }

    /* Start the WLAN OTA provisioning application to interact with user. */
    srv_dtcnt_wlan_otap_install_start();
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_is_cca_target
 * DESCRIPTION
 *  This function examines whether the configuration document has any settings
 *  relevant to WLAN data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 *  data_list       [IN]            Level one node IDs and application IDs
 * RETURNS
 *  Return CCA_STATUS_OK if the document is relevant to WLAN data account; 
 *  otherwise, return CCA_STATUS_NOT_FOUND.
 *****************************************************************************/
cca_status_enum srv_dtcnt_wlan_is_cca_target(
                    U16 conf_id, 
                    S32 doc_hdl, 
                    cca_iterator_struct *data_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_iterator_struct *node_list, *param_list;
    S32 num_nodes, num_params;
    cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check whether NAPDEF nodes are presented in the document. */
    status = mmi_cca_doc_get_nodes(doc_hdl, CCA_NS_OMA_NAPDEF, &node_list, &num_nodes);
    if (status != CCA_STATUS_OK) 
    {
        return CCA_STATUS_NOT_FOUND;
    }

    /* Check whether there are NAPDEF nodes that have a BEARER parameter with
       the value of WLAN. */
    while (mmi_cca_iterator_next(node_list) != NULL)
    {
        /* Extract all parameters and their values in the current node. */
        status = mmi_cca_doc_get_nodedata(node_list, &param_list, &num_params);
        if (status != CCA_STATUS_OK) 
        {
            continue;   /* No need to release param iterator here */
        }
        
        /* Whether there is a WLAN bearer in the NAPDEF node */
        if (srv_dtcnt_wlan_has_otap_profile(param_list) == MMI_TRUE)
        {
            /* Release memory and return OK */    
            mmi_cca_iterator_release(node_list);
            mmi_cca_iterator_release(param_list);
            return CCA_STATUS_OK;
        }

        /* Release memory for the current node. */
        mmi_cca_iterator_release(param_list);
    }
    
    /* Release memory and return NOT_FOUND */
    mmi_cca_iterator_release(node_list);
    
    return CCA_STATUS_NOT_FOUND;
}

#elif defined(__MMI_WLAN_OTAP_DMP__)

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_proc_cca_doc
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to WLAN
 *  data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_proc_cca_doc(U16 conf_id, S32 doc_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*
     * Mapping table used to extract the WLAN settings for each profile. All 
     * characteristics are included such that unsupported fields can also be
     * found out.
     */
    const U16 proc_tbl[] = 
    {
        CCA_NS_TRIGNODE, CCA_NS_OMADMP_WIFI, CCA_NS_OMADMP_ACCESS_POINT, CCA_NS_OMADMP_PROFILE,
            WLAN_OTAP_NS_INFRA, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMADMP_WIFI, CCA_NS_OMADMP_AD_HOC, CCA_NS_OMADMP_PROFILE, 
            WLAN_OTAP_NS_ADHOC, 0xFFFF
    };

    //cca_status_enum status;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_RECV_DOC);
    
    /* Whether any other OTA provisioning process is still running. */
    if (g_srv_dtcnt_wlan_otap != NULL) 
    {
        MMI_ASSERT(0);  /* Guaranteed by CCA that this should not happen */
    }
    
    /* Init control block and save the ID/handle for the response msg. */
    g_srv_dtcnt_wlan_otap = srv_dtcnt_wlan_new_otap_cntx(conf_id, doc_hdl);

    if (g_srv_dtcnt_wlan_otap == NULL) 
    {
        srv_dtcnt_send_cca_app_configure_rsp(conf_id, doc_hdl, CCA_STATUS_FAIL);
        return;
    }
    
    /* Extract WLAN settings from CCA configuration document, and store 
       settings in the temporary storage. */
    mmi_cca_doc_process(
            doc_hdl, 
            proc_tbl,
            sizeof(proc_tbl) / sizeof(U16),
            NULL, 
            srv_dtcnt_wlan_proc_cca_nodes, 
            g_srv_dtcnt_wlan_otap);


    /* Whether each profile contains all mandatory fields. */
    for (i = 0; i < g_srv_dtcnt_wlan_otap->num_profiles; ) 
    {
        /* If valid, examine next profile. If invalid, free the profile. */
        if (srv_dtcnt_wlan_validate_profile(g_srv_dtcnt_wlan_otap->profile[i]) == MMI_TRUE)
        {
            ++i;
        } 
        else 
        {
            /* Profiles are shifted. No need to increase the index. */
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_POST_DISCARD_PROF);
            srv_dtcnt_wlan_free_otap_profile(g_srv_dtcnt_wlan_otap, i);
            //status = CCA_STATUS_FAIL;
        }
    }

    /* If there is no correct WLAN profile, send a error response message back
       to CCA. Popup a notification screen to inform the user. */
    if (g_srv_dtcnt_wlan_otap->num_profiles == 0) 
    {
        /* Now, terminate the WLAN OTA provisioning application. */
        g_srv_dtcnt_wlan_otap->cur_status = 4;
        srv_dtcnt_send_cca_app_configure_rsp(conf_id, doc_hdl, CCA_STATUS_INVALID_SETTING);
        srv_dtcnt_wlan_free_otap_cntx();
        return;
    }

    /* Ready to install profiles. */
    g_srv_dtcnt_wlan_otap->cur_status = 5;

    /* Start the WLAN OTA provisioning application to interact with user. */
    srv_dtcnt_wlan_otap_install_start();
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_is_cca_target
 * DESCRIPTION
 *  This function examines whether the configuration document has any settings
 *  relevant to WLAN data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 *  data_list       [IN]            Level one node IDs and application IDs
 * RETURNS
 *  Return CCA_STATUS_OK if the document is relevant to WLAN data account; 
 *  otherwise, return CCA_STATUS_NOT_FOUND.
 *****************************************************************************/
cca_status_enum srv_dtcnt_wlan_is_cca_target(
                    U16 conf_id, 
                    S32 doc_hdl, 
                    cca_iterator_struct *data_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *node_id, num_nodes;
    cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = mmi_cca_doc_get_nodedata_ints(data_list, CCA_NS_L1NODEID, &node_id, &num_nodes);

    /* Must be OK. It is guaranteed by CCA. */
    if (status != CCA_STATUS_OK) 
    {
        MMI_ASSERT(0); 
    }

    /* Return OK if there is a WIFI node in level one. */
    while (--num_nodes >= 0)
    {
        if (node_id[num_nodes] == CCA_NS_OMADMP_WIFI) 
        {
            return CCA_STATUS_OK;
        }
    }
    
    return CCA_STATUS_NOT_FOUND;
}


#endif /* ! (defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)) */

void srv_dtcnt_wlan_prov_ind_callback(srv_dtcnt_prov_cnf_enum cnf, U8 replace_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_RROV_IND_CALLBACK, cnf, replace_idx);
    switch (cnf)
    {
        case SRV_DTCNT_PROV_CNF_INSTALL:
            srv_dtcnt_wlan_otap_install();
            break;
        case SRV_DTCNT_PROV_CNF_REPLACE:
            srv_dtcnt_wlan_otap_replace(replace_idx);
            break;
        case SRV_DTCNT_PROV_CNF_SKIP:
            srv_dtcnt_wlan_otap_skip();
            break;
        case SRV_DTCNT_PROV_CNF_ABORT:
            srv_dtcnt_wlan_abort_otap_app(NULL);
            
            break;
        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_event_callback
 * DESCRIPTION
 *  The callback function after post event is done
 *  Including action response, action notify and confirm indication
 * PARAMETERS
 *  result_evt:        [IN]        result structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_dtcnt_wlan_event_callback(mmi_post_result_event_struct *result_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_EVENT_CALLBACK, result_evt, result_evt->user_data);
    if (result_evt->user_data != NULL)
    {
        OslMfree(result_evt->user_data);
    }

    return MMI_RET_OK;
}

#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __CCA_SUPPORT__ */
#endif /* __TCPIP__ */
