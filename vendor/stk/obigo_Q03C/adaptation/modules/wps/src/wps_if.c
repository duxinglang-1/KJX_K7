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
 *   wps_if.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements WPS module interface function
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
 *==============================================================================
 *******************************************************************************/
#include "msf_cfg.h"

#include "msf_def.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_dcvt.h"
#include "msf_log.h"
#include "msf_errc.h"
#include "msf_wid.h"
#include "msf_pipe.h"
#include "msf_file.h"
#include "msf_lib.h"
#include "stk_if.h"

#ifdef STK_CFG_USE_MTK_TLS	
#include "tls_api.h"
#include "soc_api.h"
#endif /*STK_CFG_USE_MTK_TLS*/

#include "wps_if.h"

#ifdef WPS_SUPPORT

/**********************************************************************
 * Signal-sending functions
 **********************************************************************/


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


/*****************************************************************************
 * FUNCTION
 *  WPSif_httpAuthIndication
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src             [IN]        
 *  requestId       [IN]        
 *  authType        [IN]        
 *  realm           [IN]        
 *  username        [IN]        
 *  warnings        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
WPSif_httpAuthIndication(
    MSF_UINT8 src,
    int requestId,
    int authType,
    const char *realm,
    const char *username,
    int warnings)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wps_http_auth_ind_t *sig;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	sig = MSF_MEM_ALLOC(MSF_MODID_WPS, sizeof(wps_http_auth_ind_t));
	memset(sig, 0, sizeof(wps_http_auth_ind_t));		

	sig->requestId = (MSF_INT32) requestId;
	sig->authType = (MSF_INT32) authType;
	sig->realm = msf_cmmn_strdup (MSF_MODID_WPS, (char*)realm);	 
	sig->username = msf_cmmn_strdup (MSF_MODID_WPS, (char*)username);	 
	sig->warnings = (MSF_INT32) warnings;

	MSF_SIGNAL_SEND (src, MSF_MODID_WPS, WPS_SIG_HTTP_AUTH_INDICATION, sig);     	
}

#endif /* WPS_SUPPORT */ 

/*****************************************************************************
 * FUNCTION
 *  WPSif_showSesConfirmDialog
 * DESCRIPTION
 *  Creates a dialog with one or two buttons.
 * PARAMETERS
 *  modId           [IN]        
 *  type            [IN]        One of SES_DLG_ALERT, SES_DLG_ERROR, SES_DLG_INFO.
 *  confirm         [IN]        Non-zero for two button dialogs.
 *  title_id        [IN]        
 *  text_id         [IN]        
 *  callback        [IN]        Callback when dialog closed.
 *  msg(?)          [IN]        Dialog text.
 *  data(?)         [IN]        Optional data passed on to callback.
 *  title(?)        [IN]        Dialog title.
 * RETURNS
 *  void
 *****************************************************************************/
void WPSif_showSecConfirmDialog(MSF_UINT8 modId, int type, int confirm, int title_id, int text_id, void *callback)
{
#ifdef WPS_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wps_show_sec_confirm_dialog_struct *sig;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    sig = MSF_MEM_ALLOC(MSF_MODID_WPS, sizeof(wps_show_sec_confirm_dialog_struct));
    memset(sig, 0, sizeof(wps_show_sec_confirm_dialog_struct));		

    sig->type = (MSF_UINT8) type;
    sig->confirm = (MSF_UINT8) confirm;
    sig->title_id = (MSF_UINT32) title_id;
    sig->text_id = (MSF_UINT32) text_id;
    sig->callback = (MSF_UINT32) callback;

   MSF_SIGNAL_SEND (modId, MSF_MODID_WPS, WPS_SIG_SHOW_SEC_CONFIRM_DIALOG, sig);     	
#endif /*WPS_SUPPORT*/
}





/*****************************************************************************
 * FUNCTION
 *  WPSif_get_security_warning_dialog
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
unsigned int WPSif_get_security_warning_dialog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q03C_BROWSER
  	{
        extern int bam_cfg_get_sec_conn_without_cert_dlg_setting(void);
				return bam_cfg_get_sec_conn_without_cert_dlg_setting();
    }
#else
		return 0;
#endif /*OBIGO_Q03C_BROWSER*/    
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_get_redirect_handling
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
unsigned int WPSif_get_redirect_handling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q03C_BROWSER
  	{
        extern unsigned int bam_cfg_brs_redirect_handling(void);
				return bam_cfg_brs_redirect_handling();
    }
#else
		return 1;
#endif /*OBIGO_Q03C_BROWSER*/    
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_get_show_cookie_disabled_popup_status
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
unsigned int WPSif_get_show_cookie_disabled_popup_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q03C_BROWSER
  	{
        extern unsigned int bam_cfg_get_show_cookie_disabled_popup_status(void);
				return bam_cfg_get_show_cookie_disabled_popup_status();
    }
#else
		return 0;
#endif /*OBIGO_Q03C_BROWSER*/    
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_get_display_cookie_popup_for_all_req
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
unsigned int WPSif_get_display_cookie_popup_for_all_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q03C_BROWSER
  	{
        extern unsigned int bam_cfg_get_display_cookie_popup_for_all_req(void);
				return bam_cfg_get_display_cookie_popup_for_all_req();
    }
#else
		return 0;
#endif /*OBIGO_Q03C_BROWSER*/
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_showAuthDialog
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void WPSif_showAuthDialog(int request_id, int auth_type, const char *realm,
                                      const char *username, const char *password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q03C_BROWSER
    {
     extern void BAMif_showAuthDialog( MSF_INT32 request_id, MSF_INT32 auth_type, const char *realm,
                                      const char *username, const char *password);

     BAMif_showAuthDialog( request_id, auth_type, realm, username, password);
    }
#endif /*OBIGO_Q03C_BROWSER*/
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_get_tls_module
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
unsigned int WPSif_get_tls_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
#ifndef STK_CFG_USE_MTK_TLS
    return STK_MODULE_INTERNAL_TLS;
#else
    return STK_MODULE_EXTERNAL_TLS;
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_tls_new_ctx
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 WPSif_tls_new_ctx(MSF_INT32 tls_version, MSF_INT32 tls_side,
	                                            module_type mod_id, kal_uint16 app_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/		
#ifdef STK_CFG_USE_MTK_TLS	
    return tls_new_ctx((tls_version_enum)tls_version, (tls_side_enum)tls_side,
                                       mod_id, app_str_id);
#else
	return 0;
#endif                                       
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_tls_delete_conn
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 WPSif_tls_delete_conn(kal_int8 sock_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/		
#ifdef STK_CFG_USE_MTK_TLS	
    return tls_delete_conn(sock_id);
#else
	return 0;
#endif                                           
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_tls_delete_ctx
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 WPSif_tls_delete_ctx(kal_uint8 ctx_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/		
#ifdef STK_CFG_USE_MTK_TLS		
    return tls_delete_ctx(ctx_id);
#else
	return 0;
#endif                                           
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_tls_read
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 WPSif_tls_read(kal_int8 sock_id, void* buf, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/		
#ifdef STK_CFG_USE_MTK_TLS		
    return tls_read(sock_id, buf, len);
#else
	return 0;
#endif                                           
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_tls_write
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 WPSif_tls_write(kal_int8 sock_id, const void* buf, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/		
#ifdef STK_CFG_USE_MTK_TLS		
    return tls_write(sock_id, buf, len);
#else
	return 0;
#endif                                           
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_tls_handshake
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 WPSif_tls_handshake(kal_int8 sock_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/		
#ifdef STK_CFG_USE_MTK_TLS		
    return tls_handshake(sock_id);
#else
	return 0;
#endif                                           
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_tls_rehandshake
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 WPSif_tls_rehandshake(kal_int8 sock_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/		
#ifdef STK_CFG_USE_MTK_TLS		
    return tls_rehandshake(sock_id);
#else
	return 0;
#endif                                           
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_tls_new_conn
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 WPSif_tls_new_conn(kal_uint8 ctx_id, kal_int8 sock_id, msf_sockaddr_t *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/		
#ifdef STK_CFG_USE_MTK_TLS		
    sockaddr_struct socaddr;

    socaddr.addr_len = addr->addrLen;
    memcpy(socaddr.addr, addr->addr, addr->addrLen);
    socaddr.port = addr->port;
    		
    return tls_new_conn(ctx_id, sock_id, &socaddr);
#else
	return 0;
#endif                                           
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_tls_check_invalid_cert
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 WPSif_tls_check_invalid_cert(kal_int8 sock_id, kal_bool onoff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/		
#ifdef STK_CFG_USE_MTK_TLS		
    return tls_check_invalid_cert(sock_id, onoff);
#else
	return 0;
#endif                                           
}

/*****************************************************************************
 * FUNCTION
 *  WPSif_tls_get_prot_version
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 WPSif_tls_get_prot_version(const kal_int8 socket)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/		
#ifdef STK_CFG_USE_MTK_TLS		
    tls_cipher_info_struct cipher_info;
    
    tls_get_cipher_info(socket, &cipher_info);
    if ((cipher_info.version == SSLv3)||(cipher_info.version == SSLv2))
    {
         return STK_PROTOCOL_HTTP_SSL;
    }
    else
    {
        return STK_PROTOCOL_HTTP_TLS;
    }
#else
	return 0;
#endif                                           
}

int WPSif_get_max_connections(void)
{
   #ifdef MSF_MAX_VM_CONN
      return (STK_CFG_MAX_SOCKETS + 2);
   #else
       return    10;
   #endif
   
}   


char* WPSif_getUAprofString(void)
{
#ifdef OBIGO_Q03C_BROWSER
	extern const char *bam_registry_get_ua_profile();
	return (char*)bam_registry_get_ua_profile();
#else
	return NULL;
#endif
}

