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
 *  vapp_dtcnt_wlan_base.cpp
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __TCPIP__
#include "mmi_features.h"
#ifdef __MMI_WLAN_FEATURES__
#include "vapp_dtcnt_wlan_base.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Class VappWlanBaseInfo
 *****************************************************************************/
const VfxU8* VappWlanBaseInfo::getSsid() const
{
    return m_ssid;
}

void VappWlanBaseInfo::setSsid(const VfxU8* ssid, const VfxU16 ssidLen)
{
    memset(m_ssid, 0, WNDRV_SSID_MAX_LEN + 1);
    if(ssidLen < WNDRV_SSID_MAX_LEN + 1)
    {
        memcpy(m_ssid, ssid, ssidLen);
        m_ssid[ssidLen] = '\0';
    }
    else
    {
        memcpy(m_ssid, ssid, WNDRV_SSID_MAX_LEN);
        m_ssid[WNDRV_SSID_MAX_LEN] = '\0';
    }
}

const VfxU8* VappWlanBaseInfo::getBssid() const
{
    return m_bssid;
}

void VappWlanBaseInfo::setBssid(const VfxU8* bssid)
{
    memcpy(m_bssid, bssid, WNDRV_MAC_ADDRESS_LEN);
}

VfxU8 VappWlanBaseInfo::getPrivacy() const
{
    return m_privacy;
}
void VappWlanBaseInfo::setPrivacy(const VfxU8 privacy)
{
    m_privacy = privacy;
}

VfxU16 VappWlanBaseInfo::getSsidLen() const
{
    return m_ssidLen;
}

void VappWlanBaseInfo::setSsidLen(const VfxU16 ssidLen)
{
    //m_ssidLen = ssidLen;
    if(ssidLen < WNDRV_SSID_MAX_LEN + 1)
    {
        m_ssidLen = ssidLen;
    }
    else
    {
        m_ssidLen = WNDRV_SSID_MAX_LEN;
    }
}

VfxS32 VappWlanBaseInfo::getRssi() const
{
    return m_rssi;
}

void VappWlanBaseInfo::setRssi(const VfxS32 rssi)
{
    m_rssi = rssi;
}

VfxWString VappWlanBaseInfo::getRssiStr() const
{
    VfxWString  rssiStr = VFX_WSTR_EMPTY;
    
    if (m_rssi > -40)
    {
        rssiStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_SIGNAL_STRENGTH_0);
    }
    else if (m_rssi > -60)
    {
        rssiStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_SIGNAL_STRENGTH_1);
    }
    else if (m_rssi > -70)
    {
        rssiStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_SIGNAL_STRENGTH_2);
    }
    else if (m_rssi > -80)
    {
        rssiStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_SIGNAL_STRENGTH_3);
    }
    else
    {
        rssiStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_SIGNAL_STRENGTH_4);
    }
    
    return rssiStr;
}

VfxU32 VappWlanBaseInfo::getChannelNumber() const
{
    return m_channelNumber;
}

void VappWlanBaseInfo::setChannelNumber(const VfxU32 channel)
{
    m_channelNumber = channel;
}

VfxWString VappWlanBaseInfo::getChannelStr() const
{
    VfxChar     tempBuf[16];
    VfxWChar    tempBufUnicode[32];
    VfxWString  channelStr;
    
    sprintf(tempBuf, "%d", m_channelNumber);
    mmi_asc_to_ucs2((CHAR*)tempBufUnicode, (CHAR*)tempBuf);
    channelStr.loadFromMem (tempBufUnicode);

    return channelStr;
}

VfxU16 VappWlanBaseInfo::getMaxRate() const
{
    return m_maxRate;
}

void VappWlanBaseInfo::setMaxRate(const VfxU16 maxRate)
{
    m_maxRate = maxRate;
}

VfxWString VappWlanBaseInfo::getSpeedStr() const
{
    VfxChar     tempBuf[16];
    VfxWChar    tempBufUnicode[32];
    VfxWString  speedStr;

    sprintf(tempBuf, "%d Mbps", m_maxRate / 2);
    mmi_asc_to_ucs2((CHAR*)tempBufUnicode, (CHAR*)tempBuf);
    speedStr.loadFromMem (tempBufUnicode);

    return speedStr;
}

VfxU8 VappWlanBaseInfo::getNumOfAp() const
{
    return m_numOfAp;
}
void VappWlanBaseInfo::setNumOfAp(const VfxU8 apNum)
{
    m_numOfAp = apNum;
}

void VappWlanBaseInfo::onInit ()
{
    VfxObject::onInit ();
}

void VappWlanBaseInfo::onDeinit ()
{
    VfxObject::onDeinit ();
}

const VfxU8* VappWlanBaseInfo::getApName() const
{
	return m_apName;
}

void VappWlanBaseInfo::setApName(const VfxU8* name)
{
	memset(m_apName, 0, WLAN_PROF_NAME_LEN_MAX * ENCODING_LENGTH);
	memcpy(m_apName, name, WLAN_PROF_NAME_LEN_MAX * ENCODING_LENGTH);
}

VfxWString VappWlanBaseInfo::getNetworkTypeName() const
{
    VfxWString networkType = VFX_WSTR_EMPTY;
    
    switch(m_networkType)
    {
    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
        networkType = VFX_WSTR_RES(STR_ID_VAPP_WLAN_NETWORK_TYPE_INFRA);
        break;
    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
        networkType = VFX_WSTR_RES(STR_ID_VAPP_WLAN_NETWORK_TYPE_ADHOC);
        break;
    default:
        break;
    }

    return networkType;
}

VfxWString VappWlanBaseInfo::getAuthModeName() const
{
    VfxWString authMode = VFX_WSTR_EMPTY;

    switch(m_authMode)
    {
    case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:
        authMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_OPEN);
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WEP:
        authMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_SHARED);
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X:
        authMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_IEEE8021X);
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:
        // authMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPA);        
        authMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPAWPA2); //MAUI_03327492
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:
        if(m_networkType == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
        {
            // authMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPAPSK);
            authMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPAWPA2PSK); //MAUI_03327492
        }
        else
        {
            authMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPA_NONE);
        }
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY:
        authMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPA2);
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:
        if(m_networkType == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
        {
            authMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPA2PSK);
        }
        else
        {
            authMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPA_NONE);
        }
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:
        authMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WAPI_CERT);
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:
        authMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WAPI_PSK);
        break;
	case SRV_DTCNT_WLAN_AUTH_MODE_TOTAL:		
        authMode = VFX_WSTR_RES(STR_GLOBAL_NOT_SUPPORTED);
        break;	
    default:
        break;
    }
    return authMode;
}

VfxWString VappWlanBaseInfo::getEncryptionModeName() const
{
    VfxWString encryptionMode = VFX_WSTR_EMPTY;

    switch(m_encryptMode)
    {
    case SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE:
        encryptionMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ENCRYPT_MODE_NONE);
        break;
    case SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP:
        encryptionMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ENCRYPT_MODE_WEP);
        break;
    case SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP:
        encryptionMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ENCRYPT_MODE_TKIP);
        break;
    case SRV_DTCNT_WLAN_ENCRYPT_MODE_AES:
        encryptionMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ENCRYPT_MODE_AESCCMP);
        break;
    case SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP_AES:
        encryptionMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ENCRYPT_MODE_TKIPAESCCMP);
        break;		
    case SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI:
        encryptionMode = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ENCRYPT_MODE_WPI);
        break;
    default:
        break;
    }
    return encryptionMode;

}

VfxResId VappWlanBaseInfo::getNetworkTypeIcon() const
{
    VfxResId resId = 0;
    VfxS32   rssi = getRssi ();

    switch (m_apMatchType)
    {
    case WLAN_AP_SAVED:
        break;
    case WLAN_AP_SEARCH:
    case WLAN_AP_SEARCH_SAVED:
    case WLAN_AP_SEARCH_SAVED_CONNECTED:
    case WLAN_AP_SAVED_CONNECTED:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_GET_CONNECTED_AP_RSSI, m_apMatchType, rssi);
        if(SRV_DTCNT_WLAN_AUTH_MODE_OPEN == m_authMode)
        {
            if(rssi > -40)
            {
                resId = IMG_ID_VAPP_WLAN_STATION_FUR;
            }
            else if(rssi > -60)
            {
                resId = IMG_ID_VAPP_WLAN_STATION_TRD;
            }
            else if(rssi > -80)
            {
                resId = IMG_ID_VAPP_WLAN_STATION_SND;
            }
#ifdef __MMI_OP01_WIFI__			
            else if(rssi >= -100)//CMCC > request
            {
                resId = IMG_ID_VAPP_WLAN_STATION_ONE;
            }
			else 
			{
				resId = 0; // forget AP
			}
#else
	        else
            {
                resId = IMG_ID_VAPP_WLAN_STATION_ONE;
            }
#endif			
        }
        else
        {
            if(rssi > -40)
            {
                resId = IMG_ID_VAPP_WLAN_SECURED_STATION_FUR;
            }
            else if(rssi > -60)
            {
                resId = IMG_ID_VAPP_WLAN_SECURED_STATION_TRD;
            }
            else if(rssi > -80)
            {
                resId = IMG_ID_VAPP_WLAN_SECURED_STATION_SND;
            }
#ifdef __MMI_OP01_WIFI__			
            else if(rssi >= -100) //CMCC request > 85
            {
                resId = IMG_ID_VAPP_WLAN_SECURED_STATION_ONE;
            }
			else
			{
				resId = 0; // forget AP
			}
#else
			else
			{
				resId = IMG_ID_VAPP_WLAN_SECURED_STATION_ONE;
			}
#endif
        }
        break;
    default:
        break;
    }

    return resId;
}

/***************************************************************************** 
 * Class VappWlanProfile
 *****************************************************************************/
void VappWlanProfile::onInit ()
{
    VappWlanBaseInfo::onInit ();
}

void VappWlanProfile::onDeinit ()
{
    VappWlanBaseInfo::onDeinit ();
}

VfxWString VappWlanProfile::getWepKeyIndexStr() const
{
    VfxWString wepKeyIndexStr = VFX_WSTR_EMPTY;
    switch(m_wepKeyIndex)
    {
    case 0:
        wepKeyIndexStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_INDEX_1);
        break;
    case 1:
        wepKeyIndexStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_INDEX_2);
        break;
    case 2:
        wepKeyIndexStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_INDEX_3);
        break;
    case 3:
        wepKeyIndexStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_INDEX_4);
        break;
    default:
        break;
    }
    return wepKeyIndexStr;
}

VfxWString VappWlanProfile::getWepKeyEncryptStr() const
{
    VfxWString wepKeyEncryptStr = VFX_WSTR_EMPTY;

    switch(m_wepKeyLen)
    {
    case SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64:  /* 64 */
        wepKeyEncryptStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_ENCRYPT_64);
        break;
    case SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128: /* 128 */
        wepKeyEncryptStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_ENCRYPT_128);
        break;
    default:
        break;
    }
    return wepKeyEncryptStr;
}

VfxWString VappWlanProfile::getWepKeyFormatStr() const
{
    VfxWString wepKeyFormatStr = VFX_WSTR_EMPTY;

    switch(m_wepKeyFormat)
    {
    case SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX:  /* HEX encoded */
        wepKeyFormatStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_FORMAT_HEX);
        break;
    case SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII:/* ASCII encoded */
        wepKeyFormatStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_FORMAT_ASCII);
        break;
    default:
        break;
    }
    return wepKeyFormatStr;
}

#ifdef  __WAPI_SUPPORT__
VfxWString VappWlanProfile::getWaiKeyFormatStr() const
{
    VfxWString waiKeyFormatStr = VFX_WSTR_EMPTY;

    switch(m_wapiPskFormat)
    {
    case 0:  /* HEX encoded */
        waiKeyFormatStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_FORMAT_HEX);
        break;
    case 1:/* ASCII encoded */
        waiKeyFormatStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_FORMAT_ASCII);
        break;
    default:
        break;
    }
    return waiKeyFormatStr;
}
#endif /* __WAPI_SUPPORT__ */

const VfxU8* VappWlanProfile::getCaCertName() const
{
    return m_caCertName;
}

const VfxU8* VappWlanProfile::getUserCertName() const
{
    return m_userCertName;
}

void VappWlanProfile::setCaCertName(const VfxU8* ca)
{
    memcpy (m_caCertName, ca, SRV_DTCNT_PROF_MAX_USER_LEN + 1);
}

void VappWlanProfile::setUserCertName(const VfxU8* user)
{
    memcpy (m_userCertName, user, SRV_DTCNT_PROF_MAX_USER_LEN + 1);
}

VfxWString VappWlanProfile::getIpAddrStr() const
{
    VfxChar    tempBuf[TCP_IP_ADDR_LEN_MAX];
    VfxChar    tempBufUnicode[TCP_IP_ADDR_LEN_MAX * ENCODING_LENGTH];
    VfxWString  ipAddrStr;
    
    memset(tempBuf, 0, TCP_IP_ADDR_LEN_MAX);
    memset(tempBufUnicode, 0, TCP_IP_ADDR_LEN_MAX * ENCODING_LENGTH);
    
    sprintf(tempBuf, 
        "%d.%d.%d.%d",
        m_ipAddr[0], m_ipAddr[1], m_ipAddr[2], m_ipAddr[3]);
    mmi_asc_to_ucs2((CHAR*)tempBufUnicode, (CHAR*)tempBuf);
    ipAddrStr.loadFromMem ((const VfxWChar *)tempBufUnicode);

    return ipAddrStr;
}

VfxWString	VappWlanProfile::getNetmaskStr() const
{
    VfxChar    tempBuf[TCP_IP_ADDR_LEN_MAX];
    VfxChar    tempBufUnicode[TCP_IP_ADDR_LEN_MAX * ENCODING_LENGTH];
    VfxWString  netmaskStr;
    
    memset(tempBuf, 0, TCP_IP_ADDR_LEN_MAX);
    memset(tempBufUnicode, 0, TCP_IP_ADDR_LEN_MAX * ENCODING_LENGTH);
    
    sprintf(tempBuf, 
        "%d.%d.%d.%d",
        m_netmask[0], m_netmask[1], m_netmask[2], m_netmask[3]);
    mmi_asc_to_ucs2((CHAR*)tempBufUnicode, (CHAR*)tempBuf);
    netmaskStr.loadFromMem ((const VfxWChar *)tempBufUnicode);

    return netmaskStr;
}

VfxWString	VappWlanProfile::getGatewayStr() const
{
    VfxChar    tempBuf[TCP_IP_ADDR_LEN_MAX];
    VfxChar    tempBufUnicode[TCP_IP_ADDR_LEN_MAX * ENCODING_LENGTH];
    VfxWString  gatewayStr;
    
    memset(tempBuf, 0, TCP_IP_ADDR_LEN_MAX);
    memset(tempBufUnicode, 0, TCP_IP_ADDR_LEN_MAX * ENCODING_LENGTH);
    
    sprintf(tempBuf, 
        "%d.%d.%d.%d",
        m_gateway[0], m_gateway[1], m_gateway[2], m_gateway[3]);
    mmi_asc_to_ucs2((CHAR*)tempBufUnicode, (CHAR*)tempBuf);
    gatewayStr.loadFromMem ((const VfxWChar *)tempBufUnicode);

    return gatewayStr;
}

/***************************************************************************** 
 * Class Observer
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("Observer", Observer, VfxPage);

void Observer::onInit ()
{
    VFX_TRACE(("Observer initialization\n"));
    VfxPage::onInit ();
}

void Observer::onDeinit ()
{
    VfxPage::onDeinit ();
    VFX_TRACE(("Observer deinitialization\n"));
}

VfxU32 Observer::getSubscribe()
{
    return m_subscribe;
}

void Observer::setSubscribe(VfxU32 msg)
{
    VFX_TRACE(("==== Subscribe message: %d===\n", msg));
    m_subscribe = msg;
}

/***************************************************************************** 
 * Class Subject
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("Subject", Subject, VfxObject);

#endif // __MMI_WLAN_FEATURES__
#endif // __TCPIP__

