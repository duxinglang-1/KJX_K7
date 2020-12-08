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
 *  vapp_dtcnt_wlan_base.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DTCNT_WLAN_BASE_H__
#define __VAPP_DTCNT_WLAN_BASE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
extern "C"
{
    #include "supc_abm_msgs.h"
    #include "DtcntSrvIprot.h"
    #include "NetSetAppGprot.h"
    // #include "SimDetectionGprot.h"
    // #include "CertManMMIGprots.h"
    #include "mmi_rp_vapp_data_account_wlan_def.h"
    #include "custom_wlan_ui_config.h"// chinese ssid
}
#include "vfx_datatype.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"

/***************************************************************************** 
 * Compile option test define
 *****************************************************************************/
/* for test, default undef it */
// #define __COSMOS_WLAN_COMPILE_OPTION_TEST__

#ifdef __COSMOS_WLAN_COMPILE_OPTION_TEST__                               
    //#undef __MMI_OP01_WIFI__                        
    //#undef __WPS_SUPPORT__                          
    //#undef __CBM_BEARER_SWITCH__
    //#undef WIFI_AUTH_PSK_ONLY
    //#undef __CERTMAN_SUPPORT__ 
    //#undef __WAPI_SUPPORT__
#endif /* __COSMOS_WLAN_COMPILE_OPTION_TEST__ */

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* OP01 allow that user open WLAN in flight mode */
#ifndef __MMI_OP01_WIFI__ 
#define __COSMOS_WLAN_IN_FLGHT_MODE__ 
#endif

#define WLAN_PROF_NAME_LEN_MAX           33
#define WLAN_PROF_CA_CERT_NAME_LEN_MAX   34
#define WLAN_PROF_USER_CERT_NAME_LEN_MAX 34
/* TCP/IP SETTINGS */
#define TCP_IP_ADDR_LEN_MAX              SRV_DTCNT_PROF_MAX_IP_ADDR_LEN * 4
/* HOMEPAGE */
#define HOME_PAGE_LEN_MAX                256
#define HOME_PAGE_DEFAULT_URL            "http://"
#define HOME_PAGE_DEFAULT_URL_SIZE       strlen(MMI_WAP_PROF_DEFAULT_URL)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum 
{
    SUBSCRIBE_INIT_MSG = 0x0001,                  /* init event */
    SUBSCRIBE_SCAN_MSG = 0x0002,                  /* scan event */
    SUBSCRIBE_CONNECT_SUCCESS_MSG = 0x0004,       /* connect event */
    SUBSCRIBE_CONNECT_FAIL_MSG = 0x0008,          /* connect event */
    SUBSCRIBE_DISCONNECT_MSG = 0x0010,            /* disconnect event */
    SUBSCRIBE_DEINIT_MSG = 0x0020,                /* deinit event */
    SUBSCRIBE_SELECT_CA_MSG = 0x0040,             /* CA cert. event */
    SUBSCRIBE_SELECT_USER_MSG = 0x0080,           /* User cert. event */
    SUBSCRIBE_SELECT_ASE_MSG = 0x0100,            /* ASE cert. event */
    SUBSCRIBE_SELECT_CLIENT_MSG = 0x0200,         /* Simple user cert. event */
    SUBSCRIBE_CURR_AP_INFO_MSG = 0x0400,          /* Current AP RSSI event */
    SUBSCRIBE_WPS_INFO_MSG = 0x0800,              /* WPS info event */
    SUBSCRIBE_BEARER_STATUS_MSG= 0x1000,          /* Bearer status event */
    SUBSCRIBE_CONNECT_REQUEST_MSG= 0x2000,        /* Connect request event */  
    SUBSCRIBE_MSG_TOTAL = 0xFF
}SUBSCRIBE_SRV_WLAN_EVENT_ENUM;

typedef enum
{
    WLAN_AP_SAVED,
    WLAN_AP_SEARCH,
    WLAN_AP_SEARCH_SAVED,
    WLAN_AP_SEARCH_SAVED_CONNECTED,
    WLAN_AP_SAVED_CONNECTED,
    WLAN_AP_CHANGE_TOTAL
} VAPP_WLAN_AP_CHANGE_ENUM;

typedef enum
{
    AP_WEP_KEY_LEN_ZERO = 0,
    AP_WEP_KEY_LEN_FIVE = 5,
    AP_WEP_KEY_LEN_TEN = 10,
    AP_WEP_KEY_LEN_THIRTEEN = 13,
    AP_WEP_KEY_LEN_TWENTY_SIX = 26,
    AP_WEP_KEY_LEN_TOTAL
} AP_WEP_KEY_LEN_ENUM;

typedef enum
{
    WLAN_STATUS_NULL,
    WLAN_STATUS_INIT,
    WLAN_STATUS_SCAN_WAITING,
    WLAN_STATUS_SCAN_ABORT,
    WLAN_STATUS_CONN_WAITING,
    WLAN_STATUS_TOTAL
} VAPP_WLAN_STATUS;

typedef enum
{
    WLAN_WPS_STATUS_NULL,
    WLAN_WPS_STATUS_INIT,
    WLAN_WPS_STATUS_OVERLAP_ON,
    WLAN_WPS_STATUS_OVERLAP_OFF,
    WLAN_WPS_STATUS_TOTAL
} VAPP_WLAN_WPS_STATUS;

typedef enum
{
    WLAN_CONN_MANUAL,
    WLAN_CONN_AUTO,
    WLAN_CONN_WPS,
    WLAN_CONN_TOTAL
} VAPP_WLAN_CONN_PROC_TYPE;

typedef enum
{
    VAPP_WLAN_WPS_NONE,
    VAPP_WLAN_WPS_PIN,
    VAPP_WLAN_WPS_PBC,
    VAPP_WLAN_WPS_TOTAL
} VAPP_WLAN_WPS_CONN_TYPE;


/* DOM-NOT_FOR_SDK-BEGIN */
#if defined(__MMI_MAINLCD_320X480__) /* HVGA */
    enum
    {
        SEGMENT_BTN_LEFT_GAPS    = 8,
        SEGMENT_BTN_RIGHT_GAPS   = 8,
        SEGMENT_BTN_TOP_GAPS     = 4,
        SEGMENT_BTN_BOTTOM_GAPS  = 4,
        SEGMENT_BTN_MAX_HEIGTH   = 39
    };
#elif defined(__MMI_MAINLCD_480X800__) /* WVGA */
    enum
    {
        SEGMENT_BTN_LEFT_GAPS    = 14,
        SEGMENT_BTN_RIGHT_GAPS   = 14,
        SEGMENT_BTN_TOP_GAPS     = 6,
        SEGMENT_BTN_BOTTOM_GAPS  = 6,
        SEGMENT_BTN_MAX_HEIGTH   = 66
    };
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) /* QVGA / WQVGA */
    enum
    {
        SEGMENT_BTN_LEFT_GAPS    = 8,
        SEGMENT_BTN_RIGHT_GAPS   = 8,
        SEGMENT_BTN_TOP_GAPS     = 4,
        SEGMENT_BTN_BOTTOM_GAPS  = 4,
        SEGMENT_BTN_MAX_HEIGTH   = 35
    };
#else /* Shell: QVGA / WQVGA */
    enum
    {
        SEGMENT_BTN_LEFT_GAPS    = 8,
        SEGMENT_BTN_RIGHT_GAPS   = 8,
        SEGMENT_BTN_TOP_GAPS     = 4,
        SEGMENT_BTN_BOTTOM_GAPS  = 4,
        SEGMENT_BTN_MAX_HEIGTH   = 39
    };
#endif

#if defined(__MMI_MAINLCD_320X480__) /* HVGA */
    enum
    {
        MAC_ADDR_INFO_FONT_SIZE        = 15,
        MAC_ADDR_INFO_TEXT_X           = 8,
        MAC_ADDR_INFO_TEXT_Y           = 10,
        
        CONNECTED_AP_INFO_POPUP_FONT_SIZE       = 17,
        CONNECTED_AP_INFO_POPUP_WIDTH           = 290,
        CONNECTED_AP_INFO_POPUP_LANDSCAPE_WIDTH = 340,
        CONNECTED_AP_INFO_POPUP_TITLE_FONT_SIZE = 15,
        CONNECTED_AP_INFO_POPUP_TD_GAP          = 5,
        CONNECTED_AP_INFO_POPUP_LR_GAP          = 15,
        CONNECTED_AP_INFO_POPUP_TITLE_HEIGHT    = 25,
        CONNECTED_AP_INFO_POPUP_TITLE_X         = CONNECTED_AP_INFO_POPUP_LR_GAP,
        CONNECTED_AP_INFO_POPUP_TITLE_Y         = 0,
        CONNECTED_AP_INFO_POPUP_X               = 11,
        CONNECTED_AP_INFO_POPUP_Y               = 10,
        CONNECTED_AP_INFO_POPUP_BUTTON_TOP      = 13,
        CONNECTED_AP_INFO_POPUP_BUTTON_GAP      = 4,
        CONNECTED_AP_INFO_POPUP_BUTTON_HEIGHT   = 45,
        CONNECTED_AP_INFO_POPUP_BUTTON_WIDTH    = ((CONNECTED_AP_INFO_POPUP_WIDTH - 2 * CONNECTED_AP_INFO_POPUP_LR_GAP - CONNECTED_AP_INFO_POPUP_BUTTON_GAP) / 2),
        CONNECTED_AP_INFO_POPUP_BOTTOM_GAP      = 16
    };
#elif defined(__MMI_MAINLCD_480X800__) /* WVGA */
    enum
    {
        MAC_ADDR_INFO_FONT_SIZE        = 24,
        MAC_ADDR_INFO_TEXT_X           = 14,
        MAC_ADDR_INFO_TEXT_Y           = 14,

        CONNECTED_AP_INFO_POPUP_FONT_SIZE       = 26,
        CONNECTED_AP_INFO_POPUP_WIDTH           = 446,
        CONNECTED_AP_INFO_POPUP_LANDSCAPE_WIDTH = 546,
        CONNECTED_AP_INFO_POPUP_TITLE_FONT_SIZE = 24,
        CONNECTED_AP_INFO_POPUP_TD_GAP          = 14,
        CONNECTED_AP_INFO_POPUP_LR_GAP          = 21,
        CONNECTED_AP_INFO_POPUP_TITLE_HEIGHT    = 45,
        CONNECTED_AP_INFO_POPUP_TITLE_X         = CONNECTED_AP_INFO_POPUP_LR_GAP,
        CONNECTED_AP_INFO_POPUP_TITLE_Y         = 0,
        CONNECTED_AP_INFO_POPUP_X               = 21,
        CONNECTED_AP_INFO_POPUP_Y               = 14,
        CONNECTED_AP_INFO_POPUP_BUTTON_TOP      = 20,
        CONNECTED_AP_INFO_POPUP_BUTTON_GAP      = 10,
        CONNECTED_AP_INFO_POPUP_BUTTON_HEIGHT   = 70,
        CONNECTED_AP_INFO_POPUP_BUTTON_WIDTH    = ((CONNECTED_AP_INFO_POPUP_WIDTH - 2 * CONNECTED_AP_INFO_POPUP_LR_GAP - CONNECTED_AP_INFO_POPUP_BUTTON_GAP) / 2),
        CONNECTED_AP_INFO_POPUP_BOTTOM_GAP      = 30
    };
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) /* QVGA / WQVGA */
    enum
    {
        MAC_ADDR_INFO_FONT_SIZE        = 13,
        MAC_ADDR_INFO_TEXT_X           = 5,
        MAC_ADDR_INFO_TEXT_Y           = 5,
        
        CONNECTED_AP_INFO_POPUP_FONT_SIZE       = 12,
        CONNECTED_AP_INFO_POPUP_WIDTH           = 223,
        CONNECTED_AP_INFO_POPUP_LANDSCAPE_WIDTH = 242,
        CONNECTED_AP_INFO_POPUP_TITLE_FONT_SIZE = 13,
        CONNECTED_AP_INFO_POPUP_TD_GAP          = 8,
        CONNECTED_AP_INFO_POPUP_LR_GAP          = 8,
        CONNECTED_AP_INFO_POPUP_TITLE_HEIGHT    = 20,
        CONNECTED_AP_INFO_POPUP_TITLE_X         = CONNECTED_AP_INFO_POPUP_LR_GAP,
        CONNECTED_AP_INFO_POPUP_TITLE_Y         = 0,
        CONNECTED_AP_INFO_POPUP_X               = 8,
        CONNECTED_AP_INFO_POPUP_Y               = 8,
        CONNECTED_AP_INFO_POPUP_BUTTON_TOP      = 8,
        CONNECTED_AP_INFO_POPUP_BUTTON_GAP      = 5,
        CONNECTED_AP_INFO_POPUP_BUTTON_HEIGHT   = 42,
        CONNECTED_AP_INFO_POPUP_BUTTON_WIDTH    = ((CONNECTED_AP_INFO_POPUP_WIDTH - 2 * CONNECTED_AP_INFO_POPUP_LR_GAP - CONNECTED_AP_INFO_POPUP_BUTTON_GAP) / 2),
        CONNECTED_AP_INFO_POPUP_BOTTOM_GAP      = 12
    };
#else 
    enum
    {
        MAC_ADDR_INFO_FONT_SIZE        = 15,
        MAC_ADDR_INFO_TEXT_X           = 8,
        MAC_ADDR_INFO_TEXT_Y           = 10,
#ifdef __MMI_OP01_WIFI__        
        CONNECTED_AP_INFO_POPUP_FONT_SIZE       = 17,
#else
        CONNECTED_AP_INFO_POPUP_FONT_SIZE       = 18,
#endif
        CONNECTED_AP_INFO_POPUP_WIDTH           = 290,
        CONNECTED_AP_INFO_POPUP_LANDSCAPE_WIDTH = 340,
        CONNECTED_AP_INFO_POPUP_TITLE_FONT_SIZE = 15,
        CONNECTED_AP_INFO_POPUP_TD_GAP          = 5,
        CONNECTED_AP_INFO_POPUP_LR_GAP          = 15,
        CONNECTED_AP_INFO_POPUP_TITLE_HEIGHT    = 25,
        CONNECTED_AP_INFO_POPUP_TITLE_X         = CONNECTED_AP_INFO_POPUP_LR_GAP,
        CONNECTED_AP_INFO_POPUP_TITLE_Y         = 0,
        CONNECTED_AP_INFO_POPUP_X               = 11,
        CONNECTED_AP_INFO_POPUP_Y               = 10,
        CONNECTED_AP_INFO_POPUP_BUTTON_TOP      = 13,
        CONNECTED_AP_INFO_POPUP_BUTTON_GAP      = 4,
        CONNECTED_AP_INFO_POPUP_BUTTON_HEIGHT   = 45,
        CONNECTED_AP_INFO_POPUP_BUTTON_WIDTH    = ((CONNECTED_AP_INFO_POPUP_WIDTH - 2 * CONNECTED_AP_INFO_POPUP_LR_GAP - CONNECTED_AP_INFO_POPUP_BUTTON_GAP) / 2),
        CONNECTED_AP_INFO_POPUP_BOTTOM_GAP      = 16
    };
#endif    

enum ConnectedApInfoButtonEnum
{
     CONNECTED_AP_INFO_POPUP_BTN_OK,
     CONNECTED_AP_INFO_POPUP_BTN_CANCEL,
     CONNECTED_AP_INFO_POPUP_BTN_TOTAL
};

/* action after CMCC logout */
typedef enum
{
    WLAN_AP_CMCC_LOGOUT_MANUAL_CONN,       
    WLAN_AP_CMCC_LOGOUT_WPS_CONN,
    WLAN_AP_CMCC_LOGOUT_DISCONN,
    WLAN_AP_CMCC_LOGOUT_DEINIT,
    WLAN_AP_CMCC_LOGOUT_END
} VAPP_WLAN_CMCC_LOGOUT_ACTION;

typedef enum
{
    VAPP_WLAN_ADD_SAVED_AP,
    VAPP_WLAN_ADD_REMEMBER_AP,
    VAPP_WLAN_ADD_BLOCKED_AP,
    VAPP_WLAN_ADD_AP_TOTAL
} VAPP_WLAN_ADD_AP_TYPE;

/* UI Status Machine */
typedef enum
{
    WLAN_UI_NONE,
    WLAN_UI_ABORT_CONNECT,              /* Abort connecting */
    WLAN_UI_WAIT_FOR_IP_UPDATE,         /* Waiting for IP update event */
    WLAN_UI_DISC_AFTER_LOGIN_FAILED,    /* CMCC: disconnect if login failed */
    WLAN_UI_PORTAL_LOGIN,               /* CMCC: login to portal server */
    WLAN_UI_PORTAL_LOGOUT,              /* CMCC: logout */
    //WLAN_UI_CHANGE_TO_WLAN_CONFIRM,
    WLAN_UI_TOTAL    
} VAPP_WLAN_UI_FLOW_ENUM;

/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
 * Class
 *****************************************************************************/
class VappWlanBaseInfo : public VfxObject
{
// Declaration   

// Constructor / Destructor
public:
    VappWlanBaseInfo():
        m_privacy(0),
        m_ssidLen(0),
        m_rssi(0),
        m_channelNumber(0),
        m_maxRate(0),
        m_numOfAp(0),
        m_networkType(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA),
        m_authMode(SRV_DTCNT_WLAN_AUTH_MODE_OPEN),
        m_encryptMode(SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
    { 
        memset(m_apName, 0, sizeof(VfxU8) * WLAN_PROF_NAME_LEN_MAX * 2);
    }

// Method
public:   
    VfxU8 getPrivacy() const;
    void setPrivacy(const VfxU8 privacy);

    VfxU16 getSsidLen() const;
    void setSsidLen(const VfxU16 ssidLen);

    const VfxU8* getBssid() const;
    void setBssid(const VfxU8* bssid);
    
    const VfxU8* getSsid() const;
    void setSsid(const VfxU8* ssid, const VfxU16 ssidLen);
    
    VfxS32 getRssi() const;
    void setRssi(const VfxS32 rssi);
    VfxWString getRssiStr() const;

    VfxU32 getChannelNumber() const;
    void setChannelNumber(const VfxU32);
    VfxWString getChannelStr() const;

    VfxU16 getMaxRate() const;
    void setMaxRate(const VfxU16 maxRate);
    VfxWString getSpeedStr() const;

    VfxU8 getNumOfAp() const;
    void setNumOfAp(const VfxU8);

    void clearSsid()
    {
        memset(m_ssid, 0, WNDRV_SSID_MAX_LEN + 1);
    }

    void clearBssid()
    {
        memset(m_bssid, 0, WNDRV_MAC_ADDRESS_LEN);
    }

    VfxWString getNetworkTypeName() const;
    VfxWString getAuthModeName() const;
    VfxWString getEncryptionModeName() const;
    const VfxU8* getApName() const ; 
    void setApName(const VfxU8* name);
    VfxResId getNetworkTypeIcon() const;

   srv_dtcnt_wlan_network_type_enum getNetworkType() const
    {
        return m_networkType;
    }
    
    void setNetworkType(srv_dtcnt_wlan_network_type_enum networkType)
    {
        m_networkType = networkType;
    } 
    
    srv_dtcnt_wlan_auth_mode_enum getAuthMode() const
    {
        return m_authMode;
    }
    
    void setAuthMode(srv_dtcnt_wlan_auth_mode_enum authMode)
    {
        m_authMode = authMode;
    }
       
    srv_dtcnt_wlan_encrypt_mode_enum getEncryptMode() const
    {
        return m_encryptMode;
    } 
    
    void setEncryptMode(srv_dtcnt_wlan_encrypt_mode_enum encryptMode)
    {
        m_encryptMode = encryptMode;
    }
    
    void setPriority(VfxU8 priority)
    {
        m_priority = priority;
    }
    
    VfxU8 getPriority() const
    {
        return m_priority;
    }

    VfxU32 getProfileId() const
    {
        return m_profileId;
    }

    void setProfileId(VfxU32 profileId)
    {
        m_profileId = profileId;
    }

    VAPP_WLAN_AP_CHANGE_ENUM getApMatchType() const
    {
        return m_apMatchType;
    }
    
    void setApMatchType(VAPP_WLAN_AP_CHANGE_ENUM apChangeEnum)
    {
        m_apMatchType = apChangeEnum;
    }
    
    void setApCharset(mmi_chset_enum charset)
    {
	    m_charset = charset;
    }

    mmi_chset_enum getApCharset()
    {
	    return m_charset;
    }
    
    srv_dtcnt_wlan_ap_type_enum getApMgrType() const
    {
        return m_apMgrType;
    }

    void setApMgrType(srv_dtcnt_wlan_ap_type_enum apChangeEnum)
    {
        m_apMgrType = apChangeEnum;
    }

// Overridable

// Override
protected:
    virtual void onInit ();
    virtual void onDeinit ();

// Variable
private:
    VfxU8       m_privacy;                        /* WEP encryption requirement */
    VfxU16      m_ssidLen;    
    VfxS32      m_rssi;                           /* receive signal, in dBm */
    VfxU32      m_channelNumber;    
    VfxU16      m_maxRate;      
    VfxU8       m_numOfAp;   // Kinki: numbers of APs in a SSID [MAUI_00398552]
    srv_dtcnt_wlan_network_type_enum        m_networkType;  /* profile network type */
    srv_dtcnt_wlan_auth_mode_enum           m_authMode;     /* profile auth.mode */    
    srv_dtcnt_wlan_encrypt_mode_enum        m_encryptMode;  /* profile encrypt mode */ 
    VfxU32      m_profileId;   
    VfxU8       m_bssid[ WNDRV_MAC_ADDRESS_LEN ]; /* MAC address */
    VfxU8       m_apName[WLAN_PROF_NAME_LEN_MAX * ENCODING_LENGTH];   
    VfxU8       m_ssid [ WNDRV_SSID_MAX_LEN + 1 ];  
    VfxU8       m_priority; 
    VAPP_WLAN_AP_CHANGE_ENUM                m_apMatchType;
    mmi_chset_enum                          m_charset;
    srv_dtcnt_wlan_ap_type_enum             m_apMgrType;
};

class VappWlanProfile : public VappWlanBaseInfo
{
// Declaration

// Constructor / Destructor
public:
    VappWlanProfile() :
    m_eapAuthType(WLAN_EAP_TLS),
#ifdef WLAN_EAP_PEAP_SUPPORT
    m_eapPeapAuthType(WLAN_EAP_TLS),
#endif
#ifdef WLAN_EAP_TTLS_SUPPORT
#ifdef WLAN_EAP_SIM_SUPPORT
    m_eapTtlsAuthType(WLAN_EAP_SIM),
#else
    m_eapTtlsAuthType(WLAN_EAP_TLS),
#endif
#endif
    m_useDhcp(VFX_TRUE),
    m_peapVersion(SUPC_PHASE1_PEAP_0 | SUPC_PHASE1_PEAP_1),
    m_wepKeyLen(SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64),
    m_wepKeyFormat(SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX)
{
}

// Method
public:
    VfxWString getWepKeyIndexStr() const;
    VfxWString getWepKeyEncryptStr() const;
    VfxWString getWepKeyFormatStr() const;
#ifdef  __WAPI_SUPPORT__
    VfxWString getWaiKeyFormatStr() const;
#endif
    const VfxU8* getCaCertName() const;
    const VfxU8* getUserCertName() const;
    void setCaCertName(const VfxU8* ca);
    void setUserCertName(const VfxU8* user);

    VfxResId   getNetworkTypeIcon() const;

    VfxWString getIpAddrStr() const;
    
    VfxU32 getEapAuthType() const
    {
        return m_eapAuthType;
    }
    
    VfxU32 getEapPeapAuthType() const
    {
        return m_eapPeapAuthType;
    }
    
    VfxU32 getEapTtlsAuthType() const
    {
        return m_eapTtlsAuthType;
    }

    VfxU8 getWepKeyIndex() const
    {
        return m_wepKeyIndex;
    }

    srv_dtcnt_wlan_wep_key_encrypt_enum getWepKeyLen() const
    {
        return m_wepKeyLen;
    }
    
    srv_dtcnt_wlan_wep_key_format_enum getWepKeyFormat() const
    {
        return m_wepKeyFormat;
    }
    
    VfxBool getUseDhcp() const
    {
        return m_useDhcp;
    }

    const VfxU8* getIpAddr() const
    {
        return m_ipAddr;
    }

    const VfxU8* getNetmask() const
    {
        return m_netmask;
    }

    const VfxU8* getGateway() const
    {
        return m_gateway;
    }

    const VfxU8* getDns1() const
    {
        return m_dns1;
    }

    const VfxU8* getDns2() const
    {
        return m_dns2;
    }

    VfxBool getUseProxy() const
    {
        return m_useProxy;
    }

    const VfxU8* getPxAddr() const
    {
        return m_pxAddr;
    }

    const VfxU8* getAuthId() const
    {
        return m_pxAuthId;
    }

    const VfxU8* getAuthPw() const
    {
        return m_pxAuthPw;
    }

    const VfxU8* getHomePage() const
    {
        return m_homePage;
    }

    VfxU16 getPxPort() const
    {
        return m_pxPort;
    }

    VfxU32 getRootCaId() const
    {
        return m_rootCaId;
    }

    VfxU32 getClientCaId() const
    {
        return m_clientCaId;
    }

#ifdef __WAPI_SUPPORT__
    const VfxU8* getWapiPskStr() const
    {
        return m_wapiPskStr;
    }

    const VfxS8* getWapiPrivateKeyPasswdStr() const
    {
        return m_wapiPrivateKeyPasswdStr;
    }

    VfxU32 getWapiAseId() const
    {
        return m_wapiAseId;
    }

    VfxU32 getWapiClientId() const
    {
        return m_wapiClientId;
    }

    VfxS32 getWapiPskFormat() const
    {
        return m_wapiPskFormat;
    }
#endif /* __WAPI_SUPPORT__ */

    VfxU8 getPeapVersion() const
    {
        return m_peapVersion;
    }

    const VfxU8* getUserName() const
    {
        return m_userName;
    }
    
    const VfxU8* getPassphrase() const
    {
        return m_passphrase;
    }
    
    const VfxU8* getPsk() const
    {
        return m_psk;
    }
    
    const VfxU8* getWepKey() const
    {
        return m_wepKey;
    }    

    const VfxU8* getPassword() const
    {
        return m_password;
    }    

    const VfxU8* getPrivateKeyPasswd() const
    {
        return m_privateKeyPasswd;
    }    

    supc_connection_type_enum getConnType() const
    {
        return m_connectType;   
    }

    void setConnType(supc_connection_type_enum connType)
    {
        m_connectType = connType;
    }
    
    void setEapAuthType(VfxU32 eapAuthType)
    {
        m_eapAuthType |= eapAuthType;
    }
    
    void setEapPeapAuthType(VfxU32 eapPeapAuthType)
    {
        m_eapPeapAuthType |= eapPeapAuthType;
    }
    
    void setEapTtlsAuthType(VfxU32 eapTtlsAuthType)
    {
        m_eapTtlsAuthType |= eapTtlsAuthType;
    }

    void resetEapAuthType(VfxU32 eapAuthType)
    {
        m_eapAuthType = eapAuthType;
    }
    
    void resetEapPeapAuthType(VfxU32 eapPeapAuthType)
    {
        m_eapPeapAuthType = eapPeapAuthType;
    }
    
    void resetEapTtlsAuthType(VfxU32 eapTtlsAuthType)
    {
        m_eapTtlsAuthType = eapTtlsAuthType;
    }
    
    void setWepKeyFormat(srv_dtcnt_wlan_wep_key_format_enum wepKeyFormat) 
    {
        m_wepKeyFormat = wepKeyFormat;
    }
    
    void setUseDhcp(VfxBool useDhcp)
    {
        m_useDhcp = useDhcp;
    }

    void setIpAddr(const VfxU8* ipAddr)
    {
        memcpy(m_ipAddr, ipAddr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }

    void setNetmask(const VfxU8* netmask)
    {
        memcpy(m_netmask, netmask, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }

    void setGateway(const VfxU8* gateway)
    {
        memcpy(m_gateway, gateway, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }

    void setDns1(const VfxU8* dns1)
    {
        memcpy(m_dns1, dns1, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }

    void setDns2(const VfxU8* dns2)
    {
        memcpy(m_dns2, dns2, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }

    void setUseProxy(const VfxBool useProxy)
    {
        m_useProxy = useProxy;
    }

    void setPxAddr(const VfxU8* pxAddr)
    {
        memcpy(m_pxAddr, pxAddr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN+1);
    }

    void setPxAuthId(const VfxU8* pxAuthId)
    {
        memcpy(m_pxAuthId, pxAuthId, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1);
    }

    void setPxAuthPw(const VfxU8* pxAuthPw)
    {
        memcpy(m_pxAuthPw, pxAuthPw, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1);
    }

    void setHomePage(const VfxU8* homePage)
    {
        memcpy(m_homePage, homePage, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1);
    }

    void setPxPort(VfxU16 pxPort)
    {
        m_pxPort = pxPort;
    }

    void setRootCaId(VfxU32 rootCaId)
    {
        m_rootCaId = rootCaId;
    }

    void setClientCaId(VfxU32 clientCaId)
    {
        m_clientCaId = clientCaId;
    }
    
#ifdef __WAPI_SUPPORT__
    void setWapiPskStr(const VfxU8* wapiPskStr)
    {
        memcpy(m_wapiPskStr, wapiPskStr, SRV_DTCNT_WAPI_PSK_STR_LEN);
    }

    void setWapiPrivateKeyPasswdStr(const VfxS8* wapiPrivateKeyPasswdStr)
    {
        memcpy(m_wapiPrivateKeyPasswdStr, wapiPrivateKeyPasswdStr, SRV_DTCNT_PROF_MAX_PW_LEN + 2);
    }

    void setWapiAseId(VfxU32 wapiAseId)
    {
        m_wapiAseId = wapiAseId;
    }

    void setWapiClientId(VfxU32 wapiClientId)
    {
        m_wapiClientId = wapiClientId;
    }

    void setWapiPskFormat(VfxS32 wapiPskFormat)
    {
        m_wapiPskFormat = wapiPskFormat;
    }
#endif /* __WAPI_SUPPORT__ */

    void setPeapVersion(VfxU8 peapVersion)
    {
        m_peapVersion = peapVersion;
    }

    void setWepKeyIndex(VfxU8 wepKeyIndex)
    {
        m_wepKeyIndex = wepKeyIndex;
    }

    void setWepKeyLen(srv_dtcnt_wlan_wep_key_encrypt_enum wepKeyLen)
    {
        m_wepKeyLen = wepKeyLen;
    }

    void setUserName(const VfxU8* userName)
    {
        memcpy(m_userName, userName, SRV_DTCNT_PROF_MAX_USER_LEN+1);
    }

    void setPassphrase(const VfxU8* passphrase)
    {
        memcpy(m_passphrase, passphrase, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);
    }

    void setPassphrase(const VfxU8* passphrase, VfxU8 length)
    {
        memset(m_passphrase, 0, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);
        if(length <= SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN)
        {
            memcpy(m_passphrase, passphrase, length);
        }
        else
        {
            memcpy(m_passphrase, passphrase, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);
        }
    }

    void setPsk(const VfxU8* psk)
    {
        memcpy(m_psk, psk, SRV_DTCNT_PROF_MAX_PSK_LEN);
    }

    void setPsk(const VfxU8* psk, VfxU8 length)
    {
        memset(m_psk, 0, SRV_DTCNT_PROF_MAX_PSK_LEN);
        if(length < SRV_DTCNT_PROF_MAX_PSK_LEN)
        {
            memcpy(m_psk, psk, length);
        }
        else
        {
            memcpy(m_psk, psk, SRV_DTCNT_PROF_MAX_PSK_LEN);   
        }
    }

    void setWepKey(const VfxU8* wepKey)
    {
        memcpy(m_wepKey, wepKey, SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1);
    }

    void setWepKey(const VfxU8* wepKey, VfxU32 length)
    {
        memcpy(m_wepKey, wepKey, length);
    }

    void setPassword(const VfxU8* password)
    {
        memcpy(m_password, password, SRV_DTCNT_PROF_MAX_PW_LEN + 1);
    }

    void setPrivateKeyPasswd(const VfxU8* privateKeyPasswd)
    {
        memcpy(m_privateKeyPasswd, privateKeyPasswd, SRV_DTCNT_PROF_MAX_PW_LEN + 1);
    }

    void clearEapAuthType ()
    {
        m_eapAuthType = 0;
    }

    void clearEapPeapAuthType ()
    {
        m_eapPeapAuthType = 0;
    }

    void clearEapTtlsAuthType ()
    {
        m_eapTtlsAuthType = 0;
    }

    void clearWepKey()
    {
        memset(m_wepKey, 0, SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1);
    }

    void clearIpAddr()
    {
        memset(m_ipAddr, 0, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }

    void clearNetmask()
    {
        memset(m_netmask, 0, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }

    void clearGateway()
    {
        memset(m_gateway, 0, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }

    void clearDns1()
    {
        memset(m_dns1, 0, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }

    void clearDns2()
    {
        memset(m_dns2, 0, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }

    void clearpxAddr()
    {
        memset(m_pxAddr, 0, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN+1);
    }

    void clearPxAuthId()
    {
        memset(m_pxAuthId, 0, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1);
    }

    void clearPxAuthPw()
    {
        memset(m_pxAuthPw, 0, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1);
    }

    void clearHomePage()
    {
        memset(m_homePage, 0, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1);
    }

    void clearUserName()
    {
        memset(m_userName, 0, SRV_DTCNT_PROF_MAX_USER_LEN+1);
    }

    void clearPassphrase()
    {
        memset(m_passphrase, 0, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);
    }

    void clearPsk()
    {
        memset(m_psk, 0, SRV_DTCNT_PROF_MAX_PSK_LEN);
    }

    void clearPassword()
    {
        memset(m_password, 0, SRV_DTCNT_PROF_MAX_PW_LEN+1);
    }

    void clearPrivateKeyPasswd()
    {
        memset(m_privateKeyPasswd, 0, SRV_DTCNT_PROF_MAX_PW_LEN+1);
    }

#ifdef __WAPI_SUPPORT__
    void clearWapiPskStr()
    {
        memset(m_wapiPskStr, 0, SRV_DTCNT_WAPI_PSK_STR_LEN);
    }

    void clearWapiPrivateKeyPasswdStr()
    {
        memset(m_wapiPrivateKeyPasswdStr, 0, SRV_DTCNT_PROF_MAX_PW_LEN+2);
    }
#endif /* __WAPI_SUPPORT__ */
  
    VfxWString  getNetmaskStr() const;
   
    VfxWString  getGatewayStr() const;

// Overridable

// Override
protected:
    virtual void onInit ();
    virtual void onDeinit ();

// Variable
private:
    VfxU32      m_eapAuthType;          /* eap fisrt level auth.type */
    VfxU32      m_eapPeapAuthType;      /* peap auth.type */
    VfxU32      m_eapTtlsAuthType;      /* ttls auth.type */
    VfxBool     m_useDhcp;              /* enable/disable DHCP */

    VfxU8 m_ipAddr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];     /* IP address (ASCII, MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    VfxU8 m_netmask[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];    /* Netmask (ASCII, MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    VfxU8 m_gateway[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];    /* Gateway (ASCII, MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    VfxU8 m_dns1[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];       /* Primary DNS (ASCII, MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    VfxU8 m_dns2[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];       /* Secondary DNS (ASCII, MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */

    VfxBool     m_useProxy;
    /* proxy addr string IP format */
    VfxU8 m_pxAddr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN+1];       
    /* proxy auth. ID string (ASCII) (MAX: SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN) */
    VfxU8 m_pxAuthId[SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1];  
    /* proxy auth. PW (ASCII) (MAX: SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN) */
    VfxU8 m_pxAuthPw[SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1]; 
    /* Homepage string (ASCII) (MAX: SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN) */   
    VfxU8 m_homePage[SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1];       
    VfxU16 m_pxPort;            /* proxy port */
    VfxU32 m_rootCaId;          /* root ca id */
    VfxU32 m_clientCaId;        /* user cert id */
    VfxU8  m_caCertName[SRV_DTCNT_PROF_MAX_USER_LEN + 1];
    VfxU8  m_userCertName[SRV_DTCNT_PROF_MAX_USER_LEN + 1];

#ifdef __WAPI_SUPPORT__
    /* wapi pre-shared key string */
    VfxU8 m_wapiPskStr[SRV_DTCNT_WAPI_PSK_STR_LEN];       
    /* wapi priv ate key passwd string (ASCII, MAX: SRV_DTCNT_PROF_MAX_PW_LEN) */
    VfxS8 m_wapiPrivateKeyPasswdStr[SRV_DTCNT_PROF_MAX_PW_LEN+2]; 
    VfxU32 m_wapiAseId;        /* wapi ase ca id */
    VfxU32 m_wapiClientId;     /* wapi client cert id */
    VfxS32 m_wapiPskFormat;    /* wapi pre-shared key format */   
#endif /* __WAPI_SUPPORT__ */

    VfxU8 m_peapVersion;        /* peap version */
    VfxU8 m_wepKeyIndex;        /* wep key index info */
    srv_dtcnt_wlan_wep_key_encrypt_enum m_wepKeyLen;    /* wep key length (srv_dtcnt_wlan_wep_key_encrypt_enum) */
    srv_dtcnt_wlan_wep_key_format_enum  m_wepKeyFormat; /* wep key format */    
    VfxU8 m_userName[SRV_DTCNT_PROF_MAX_USER_LEN+1];    /* user name string (ASCII, MAX: SRV_DTCNT_PROF_MAX_USER_LEN) */
    VfxU8 m_passphrase[SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN+1]; /* passphrase string (MAX: SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN) */
    VfxU8 m_psk[SRV_DTCNT_PROF_MAX_PSK_LEN];        /* pre-shared key for passphrase (MAX: SRV_DTCNT_PROF_MAX_PSK_LEN) */
    VfxU8 m_wepKey[SRV_DTCNT_PROF_MAX_WEP_KEY_LEN+1];    /* wep key string (MAX: SRV_DTCNT_PROF_MAX_WEP_KEY_LEN) */
    VfxU8 m_password[SRV_DTCNT_PROF_MAX_PW_LEN+1];   /* password string (ASCII, MAX: SRV_DTCNT_PROF_MAX_PW_LEN) */
    VfxU8 m_privateKeyPasswd[SRV_DTCNT_PROF_MAX_PW_LEN+1]; /* private key passwd string (ASCII, MAX: SRV_DTCNT_PROF_MAX_PW_LEN) */ 
    supc_connection_type_enum m_connectType;        /* connect type: PIN/PBC/ALL_PROFILE_ENABLE/ONE_PROFILE_SELECT */
// Implementation
    
};

class Observer : public VfxPage
{
// Declaration
    VFX_DECLARE_CLASS(Observer);

// Constructor / Destructor
    Observer() :
        m_subscribe (0x0000)              /* register msg you are interested */
    {
        VFX_TRACE(("Observer default constructor\n"));
    }
    virtual ~Observer()
    {
        VFX_TRACE(("Observer deconstructor\n"));
    }

// Method
public:
    VfxU32 getSubscribe();
    void setSubscribe(VfxU32 msg);

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();

// Variable
public:
    //VfxBool - TRUE: Join FALSE: Cancel
    VfxSignal2 <VfxBool, VappWlanProfile*> m_signalJoinNetwork;
    
private:
    VfxU32  m_subscribe;
    
// Implementation
public:
    virtual void UpdatePage(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg) {}
    virtual void showConnectingPopup(VappWlanProfile* hiltAp) {}
};

class Subject : public VfxObject
{
// Declaration
    VFX_DECLARE_CLASS(Subject);

// Constructor / Destructor
    Subject()
    {
        VFX_TRACE(("Subject default constructor\n"));
    }
    virtual ~Subject()
    {
        VFX_TRACE(("Subject deconstructor\n"));
    }

// Method

// Overridable

// Override

// Variable

// Implementation
public:
    virtual void registerObserver(Observer* o) {}
    virtual void removeObserver(Observer* o) {}
    virtual void notifyObservers(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg) {}
};


#endif /*__VAPP_DTCNT_WLAN_BASE_H__*/

