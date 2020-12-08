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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_dtcnt_cmcc_wlan_auth_http.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __VAPP_DTCNT_WLAN_CMCC_AUTH_HTTP_H__
#define __VAPP_DTCNT_WLAN_CMCC_AUTH_HTTP_H__

#include "MMI_features.h"
#ifdef __MMI_OP01_WIFI__
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
extern "C"
{
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "fs_type.h"
#include "fs_func.h"
#include "cbm_consts.h"
#include "wps_struct.h"
#include "cbm_api.h"

#ifdef __SSL_SUPPORT__
#include "tls_api.h"
#endif
}
#include "Vapp_dtcnt_wlan_cmcc_auth_gprot.h"

// For debug
//#define __CMCC_WLAN_AUTH_UT__ 
#ifdef __CMCC_WLAN_AUTH_DEBUG__
static void copy_http_rsp_file_ut(void);
static void copy_http_req_file_ut(U8 *url, U8 *post);
#endif /* __CMCC_WLAN_AUTH_UT__ */

/* Defines */
#define VAPP_CMCC_WLAN_WPS_TIMEOUT  120
#define VAPP_CMCC_WLAN_HTTP_FILENAME_LEN 32
#define VAPP_CMCC_WLAN_MAX_FILE_BUF_SIZE ((VAPP_CMCC_WLAN_HTTP_FILENAME_LEN + 3) * 4)
#define VAPP_CMCC_WLAN_MAX_STRING_LEN 128

extern const char* VAPP_CMCC_WLAN_HTTP_FILENAME;
#define VAPP_CMCC_WLAN_MAKE_FILENAME_HTTP(str) \
    do{\
    kal_wsprintf(str,\
        "%c:\\%s",\
        (CHAR) FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_DRIVE_I_SYSTEM),\
        VAPP_CMCC_WLAN_HTTP_FILENAME);\
    }while(0)


#define VAPP_CMCC_SET_WPS_MSG_HANDLER(cb, msg) \
    do{\
        mmi_frm_set_protocol_event_handler(msg, (PsIntFuncPtr)cb, MMI_TRUE);\
    }while(0)

#define VAPP_HTML_PORTAL_S_INIT 0
#define VAPP_HTML_PORTAL_S_TAG_INIT 1
#define VAPP_HTML_PORTAL_S_TAG 2

#define VAPP_HTML_PORTAL_FORM_S_INIT   1
#define VAPP_HTML_PORTAL_FORM_S_INPUT  2

#define VAPP_CMCC_WLAN_ACTIVITY_NONE 0
#define VAPP_CMCC_WLAN_ACTIVITY_LOGIN 1
#define VAPP_CMCC_WLAN_ACTIVITY_LOGOUT 2


typedef enum
{
    VAPP_CMCC_WLAN_S_NULL,
    VAPP_CMCC_WLAN_S_WPS_INIT,  /* Set up channel */
    VAPP_CMCC_WLAN_S_AUTH_TRY,
    VAPP_CMCC_WLAN_S_AUTH_PORTAL,
    VAPP_CMCC_WLAN_S_AUTH_LOGIN,
    VAPP_CMCC_WLAN_S_AUTH_LOGOUT,
}vapp_cmcc_wlan_stat_enum;

typedef struct
{
    char *form_name;
    char *action_url;
    char *portal_url;

    char *wlanacname;
    char *wlanacip;
    char *wlanuserip;
    char *wlanacssid;
    //char *actiontype;
    char *languagetype;
    char *logonsessid;
}vapp_cmcc_wlan_portal_cntx_struct;

typedef struct 
{
    char *logout_url;
    char *logout_post;
}vapp_cmcc_wlan_logout_data_struct;

typedef struct
{
    /* Response */
    FS_HANDLE fh;
    char buf[VAPP_CMCC_WLAN_MAX_FILE_BUF_SIZE];
    U32 buf_len;
    U32 buf_off;
    S32 buf_state;
    char temp_string[VAPP_CMCC_WLAN_MAX_STRING_LEN + 1];

    U32 ret;
    vapp_dtcnt_wlan_auth_callback callback;
    void *user_data;
    
    U8 activity; 
    U16 wps_request_id;

    vapp_cmcc_wlan_stat_enum s;
}vapp_cmcc_wlan_cntx_struct;

/***************************************************************************** 
 * Class VappCmccWlanAuthHttp
 *****************************************************************************/
/*
 * DESCRIPTION
 * 
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappCmccWlanAuthHttp : public VfxBase
{
public:
    //Export API 
    static U32 getDtcntId(void);
    static U8 getAbmId(void);
    //Parse utility
    static char* characterToupper(char *str);
    static char* characterTolower(char *str);
    static char* getNextWords(char **pp);
    static VfxBool isTermiCharacter(char c, const char *termi);

    const static char* getPassword();
    const static char* getUsername();
    static U32 makeHttpUserData(char *buf, U32 len, BOOL login);
    static void remakeLogoutPara(void);
    static void reassemblePortalUrl(void);
    static U16 getNextReqId(void);
        
    static vapp_cmcc_wlan_auth_ret_enum httpLogin(vapp_dtcnt_wlan_auth_callback cb, void *user_data);
    static vapp_cmcc_wlan_auth_ret_enum httpLogout(vapp_dtcnt_wlan_auth_callback cb, void *user_data);
    static void httpAbort(void);
    
    static void authFsm(void);
    static void httpSendMsg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
    static void sendCallback(vapp_cmcc_wlan_auth_ret_enum ret);
        
    static void wpsInitReq(void);
    static VfxBool wpsInitRsp(void *msg, S32 src, void *ilm);
		
    static void wpsTryReq(void);
        
    static void wpsPortalReq(void);
    static void wpsPortalRsp(wps_http_rsp_struct *para);
    
    static void wpsLoginReq(void);
    static void wpsLoginRsp(wps_http_rsp_struct *para);
    
    static void wpsLogoutReq(void);
    static void wpsLogoutRsp(wps_http_rsp_struct *para);

    static void wpsCleanReq(void);
    static VfxBool wpsCleanRsp(void *msg, S32 src, void *ilm);
    
    static void wpsHttpReq(const char *url, U8 *data, BOOL auto_redirect);
    static VfxBool wpsHttpInd(void *msg, S32 src, void *ptr);
    static VfxBool wpsHttpRsp(void *msg, S32 src, void *ptr);

    static void parseFormSafeFree(char **pp);
    static void parseFormFree(void);
    static VfxBool htmlOpen(void);
    static VfxBool htmlRead(void);
    static char htmlNextChar(void);
    static VfxBool htmlClose(void);	
    static VfxBool htmlParsePortal(void);
    static VfxBool parseForm(char *tag_line);    
    static VfxBool parseInput(char *tag_line);
    static void parseSaveField(char *name, char *value);
    static char* getNextStringFromFile(const char *termi);
    static void parseSaveFieldSafe(char **pp, char *value);   
    static VfxBool htmlParseLogonsessid(void);   
    static VfxBool htmlParseLogin(void);      
		
#ifdef __CMCC_WLAN_AUTH_DEBUG__
    static WCHAR *copy_http_file_get_filename(BOOL req);
    static void ut_copy_html(FS_HANDLE fhSrc, FS_HANDLE fhDst);
    static void copy_http_rsp_file_ut(void);
    static void copy_http_req_file_ut(U8 *url, U8 *post);
#endif		
private:
    static vapp_cmcc_wlan_cntx_struct gCmccWlanCntx;
    static vapp_cmcc_wlan_portal_cntx_struct gCmccWlanPortalCntx;
    static vapp_cmcc_wlan_logout_data_struct gCmccWlanLogoutData;
};
#endif /* __MMI_OP01_WIFI__ */

#endif /* __VAPP_DTCNT_WLAN_CMCC_AUTH_HTTP_H__ */

