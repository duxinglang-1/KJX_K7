/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_dtcnt_ui.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file implements data account app display and config
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __TCPIP__
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vtst_rt_main.h"
#include "vapp_dtcnt_def.h"
#include "vapp_dtcnt_gprot.h"
#include "mmi_rp_vapp_dtcnt_def.h"
#include "vapp_dtcnt_ui.h"
#include "vapp_dtcnt.h"
extern "C"
{
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
#include "SimCtrlSrvGprot.h"
#include "app_url.h"
#include "Conversions.h"
#include "cbm_api.h"
#include "cbm_consts.h"
#include "ModeSwitchSrvGprot.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "TetheringSrvGprot.h"
#include "NotificationGprot.h"

}
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"
#include "GlobalResDef.h"
#include "mmi_frm_utility_gprot.h"

extern "C"
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_B__) 
#include "dcmgr.h" // DCM
#endif
}

/***************************************************************************** 
 * Define
 *****************************************************************************/



/***************************************************************************** 
 * static function
 *****************************************************************************/
mmi_id vcui_dtcnt_setting_create(mmi_id parent_gid, void *user_data)
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_B__)
    DCM_Load(DYNAMIC_CODE_COMPRESS_COSMOS_DTCNT, 0, 0);
#endif
    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VAPP_DTCNT,
                                        VFX_OBJ_CLASS_INFO(VappDtcntApp),
                                        parent_gid,
                                        user_data,
                                        sizeof(user_data));
    return cui_id;
}

void vcui_dtcnt_setting_run(mmi_id cui_gid)
{
    VfxAppLauncher::runCui(cui_gid);
}

/***************************************************************************** 
 * Class VappDtcntDisplayItemInfo
 *****************************************************************************/

void VappDtcntDisplayItemInfo::onInit()
{
     VfxObject::onInit();
}

void VappDtcntDisplayItemInfo::onDeinit()
{
     VfxObject::onDeinit();
}


void VappDtcntListDisplayContext::swapListInfo(VappDtcntDisplayItemInfo *ListInfo1, VappDtcntDisplayItemInfo *ListInfo2)
{
    VfxU32 tempProfileId;
    VfxU8 tempConnectionType;
    VfxU8 tempSimInfo;
    VfxU8 tempBearerType;
    VfxU8 tempReadOnly;
    srv_dtcnt_prof_acc_type_enum tempAccountType;
    VfxWChar tempName[MAX_DATA_ACCOUNT_NAME_LEN + 1];
    VfxWChar tempAddress[MAX_DTCNT_LIST_ADDR_LEN];

    // get temp data
    tempProfileId = ListInfo1->getProfileId();
    tempConnectionType = ListInfo1->getConnectionType();
    tempSimInfo = ListInfo1->getSimInfo();
    tempBearerType = ListInfo1->getBearerType();
    tempReadOnly = ListInfo1->getReadOnly();
    tempAccountType = ListInfo1->getAccountType();
    mmi_wcscpy((WCHAR*)tempName, (WCHAR*)ListInfo1->getName());
    mmi_wcscpy((WCHAR*)tempAddress, (WCHAR*)ListInfo1->getAddress());

    // set listInfo1
    ListInfo1->setProfileId(ListInfo2->getProfileId());
    ListInfo1->setConnectionType(ListInfo2->getConnectionType());
    ListInfo1->setSimInfo(ListInfo2->getSimInfo());
    ListInfo1->setBearerType(ListInfo2->getBearerType());
    ListInfo1->setReadOnly(ListInfo2->getReadOnly());
    ListInfo1->setAccountType(ListInfo2->getAccountType());
    ListInfo1->setName(ListInfo2->getName());
    ListInfo1->setAddress(ListInfo2->getAddress());

    // set listinfo2
    ListInfo2->setProfileId(tempProfileId);
    ListInfo2->setConnectionType(tempConnectionType);
    ListInfo2->setSimInfo(tempSimInfo);
    ListInfo2->setBearerType(tempBearerType);
    ListInfo2->setReadOnly(tempReadOnly);
    ListInfo2->setAccountType(tempAccountType);
    ListInfo2->setName(tempName);
    ListInfo2->setAddress(tempAddress);
}

void VappDtcntListDisplayContext::arrangeAcctListInfo(VappDtcntDisplayItemInfo **ListInfo, VfxU32 start, VfxU32 end)
{
    if (end <= (start + 1))
    {
        return;
    }
    // because not include end index
    VfxU32 i, j;
    VfxBool flag;
    for (i = start; i < end - 1; i++)
    {
        flag = VFX_FALSE;
        for (j = start; j < (end + start - 1 - i); j++)
        {
            if (mmi_wcscmp((WCHAR*)ListInfo[j]->getName(), (WCHAR*)ListInfo[j + 1]->getName()) > 0)
            {
                swapListInfo(ListInfo[j], ListInfo[j + 1]);
                flag = VFX_TRUE;
            }                
        }
        if (!flag)
        {
            break;
        }
    }
}

void VappDtcntListDisplayContext::prepareListInfo(srv_dtcnt_sim_type_enum simType, VappDtcntPrepareListType type)
{
    VfxU32 listNum = 0;
    VfxS32 start = 0;
    
    VfxU32 i;
    VappDtcntDispItem* dispItem;
    VfxU32 totalAcctNum;
    totalAcctNum = VappDtcntDispItemList::getAcctNum();
    // user define factory config account
    start = listNum;
    for (i = 0; i < totalAcctNum; i++)
    {
        dispItem = VappDtcntDispItemList::getAccountItem(i);

        // skip different sim type
        if (dispItem->getSimInfo() != simType)
        {
            continue;
        }

        if (dispItem->getAccountType() == SRV_DTCNT_PROF_TYPE_USER_CONF ||
         dispItem->getAccountType() == SRV_DTCNT_PROF_TYPE_OTA_CONF) // configure type
        {   
            m_listInfo[listNum]->setProfileId(dispItem->getProfileId());
            m_listInfo[listNum]->setConnectionType(dispItem->getConnectionType());
            m_listInfo[listNum]->setSimInfo(dispItem->getSimInfo());
            m_listInfo[listNum]->setBearerType(dispItem->getBearerType());
            m_listInfo[listNum]->setReadOnly(dispItem->getReadOnly());
            m_listInfo[listNum]->setAccountType(dispItem->getAccountType());

            srv_dtcnt_prof_str_info_qry_struct acctData;
            acctData.dest_len = (MAX_DATA_ACCOUNT_NAME_LEN + 1) * ENCODING_LENGTH;
            VFX_ALLOC_MEM(acctData.dest, acctData.dest_len, this);
            srv_dtcnt_get_account_name(dispItem->getProfileId(),
                          &acctData,
                          SRV_DTCNT_ACCOUNT_PRIMARY);
            m_listInfo[listNum]->setName((VfxWChar*)acctData.dest);
            VFX_FREE_MEM(acctData.dest);

            acctData.dest_len = (MAX_DTCNT_LIST_ADDR_LEN) * ENCODING_LENGTH;
            VFX_ALLOC_MEM(acctData.dest, acctData.dest_len, this);
            if (dispItem->getBearerType() == DATA_ACCOUNT_BEARER_GPRS)
            {
                srv_dtcnt_get_apn(
                    dispItem->getProfileId(),
                    &acctData,
                    SRV_DTCNT_ACCOUNT_PRIMARY);
            }
            else
            {
                srv_dtcnt_get_csd_number(
                    dispItem->getProfileId(),
                    &acctData,
                    SRV_DTCNT_ACCOUNT_PRIMARY);
            }
            m_listInfo[listNum]->setAddress((VfxWChar*)acctData.dest);
            VFX_FREE_MEM(acctData.dest);

            listNum++;               
        }
    }
    arrangeAcctListInfo(m_listInfo, start, listNum);

    start = listNum;
    for (i = 0; i < totalAcctNum; i++)
    {
        dispItem = VappDtcntDispItemList::getAccountItem(i);

        if (dispItem->getSimInfo() != simType)
        {
            continue;
        }
        if (dispItem->getAccountType() == SRV_DTCNT_PROF_TYPE_FACTORY_CONF ||
         dispItem->getAccountType() == SRV_DTCNT_PROF_TYPE_SIM_PROF) // configure type
        {                              
            if ((type == VAPP_DTCNT_LIST_PREPARE_TYPE_PROVISIONING) && dispItem->getReadOnly())
            {
                continue;
            }
            m_listInfo[listNum]->setProfileId(dispItem->getProfileId());
            m_listInfo[listNum]->setConnectionType(dispItem->getConnectionType());
            m_listInfo[listNum]->setSimInfo(dispItem->getSimInfo());
            m_listInfo[listNum]->setBearerType(dispItem->getBearerType());
            m_listInfo[listNum]->setReadOnly(dispItem->getReadOnly());
            m_listInfo[listNum]->setAccountType(dispItem->getAccountType());

            srv_dtcnt_prof_str_info_qry_struct acctData;
            acctData.dest_len = (MAX_DATA_ACCOUNT_NAME_LEN + 1) * ENCODING_LENGTH;
            VFX_ALLOC_MEM(acctData.dest, acctData.dest_len, this);
            srv_dtcnt_get_account_name(dispItem->getProfileId(),
                          &acctData,
                          SRV_DTCNT_ACCOUNT_PRIMARY);
            m_listInfo[listNum]->setName((VfxWChar*)acctData.dest);
            VFX_FREE_MEM(acctData.dest);

            acctData.dest_len = (MAX_DTCNT_LIST_ADDR_LEN) * ENCODING_LENGTH;
            VFX_ALLOC_MEM(acctData.dest, acctData.dest_len, this);
            if (dispItem->getBearerType() == DATA_ACCOUNT_BEARER_GPRS)
            {
                srv_dtcnt_get_apn(
                    dispItem->getProfileId(),
                    &acctData,
                    SRV_DTCNT_ACCOUNT_PRIMARY);
            }
            else
            {
                srv_dtcnt_get_csd_number(
                    dispItem->getProfileId(),
                    &acctData,
                    SRV_DTCNT_ACCOUNT_PRIMARY);
            }
            m_listInfo[listNum]->setAddress((VfxWChar*)acctData.dest);
            VFX_FREE_MEM(acctData.dest);

            listNum++;
        }
    }
    arrangeAcctListInfo(m_listInfo, start, listNum);
    m_listItemNumber = listNum;
}

void VappDtcntListDisplayContext::onInit()
{
     VfxObject::onInit();
     for (VfxU32 i = 0; i < VAPP_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM; i++)
     {
         VFX_OBJ_CREATE(m_listInfo[i], VappDtcntDisplayItemInfo, this);
     }
}


void VappDtcntListDisplayContext::onDeinit()
{
     VfxObject::onDeinit();
}


#pragma arm section code = "DYNAMIC_CODE_COSMOS_DTCNT_ROCODE", rodata = "DYNAMIC_CODE_COSMOS_DTCNT_RODATA"


/***************************************************************************** 
 * Class VappDtcntCommonAccountData
 *****************************************************************************/

VappDtcntCommonAccountData::VappDtcntCommonAccountData() :
    m_connectionType(1),
    m_useProxy(0),
    m_wapPortIndex(0),
    m_reserved(0),
    m_proxyPort(0)
{
    m_dataAccountName[0] = L'\0';
    m_userName[0] = L'\0';
    m_password[0] = L'\0';
    m_proxyAddress[0] = L'\0';
    m_homePage[0] = L'\0';
    m_proxyPortStr[0] = L'\0';
    m_proxyUserName[0] = L'\0';
    m_proxyPassword[0] = L'\0';
    m_dnsPrimaryIpDisplay[0] = L'\0';
    m_dnsSecondaryIpDisplay[0] = L'\0';
    m_ipDisplay[0] = L'\0';
    m_submaskIpDisplay[0] = L'\0';
    //m_proxyIpDisplay[0] = L'\0';

    memset(m_dnsPrimaryIp, 0, sizeof(m_dnsPrimaryIp));
    memset(m_dnsSecondaryIp, 0, sizeof(m_dnsSecondaryIp));
    memset(m_ip, 0, sizeof(m_ip));
    memset(m_submaskIp, 0, sizeof(m_submaskIp));
    //memset(m_proxyIp, 0, sizeof(m_proxyIp));
}

void VappDtcntCommonAccountData::setDnsPrimaryIp(VfxU8* ip)
{ 
    VfxU32 i;
    for (i = 0; i < MAX_PART_IP_ADDRESS; i++) 
    {
        m_dnsPrimaryIp[i] = ip[i];
    }
}

void VappDtcntCommonAccountData::setDnsSecondaryIp(VfxU8* ip)
{ 
    VfxU32 i;
    for (i = 0; i < MAX_PART_IP_ADDRESS; i++) 
    {
        m_dnsSecondaryIp[i] = ip[i];
    }
}

void VappDtcntCommonAccountData::setIp(VfxU8* ip) 
{ 
    VfxU32 i;
    for (i = 0; i < MAX_PART_IP_ADDRESS; i++) 
    {
        m_ip[i] = ip[i];
    }
}

void VappDtcntCommonAccountData::setSubmaskIp(VfxU8* ip)
{
    VfxU32 i;
    for (i= 0; i < MAX_PART_IP_ADDRESS; i++) 
    {
        m_submaskIp[i] = ip[i];
    }
}

/*
void VappDtcntCommonAccountData::setProxyIp(VfxU8* ip)
{
    VfxU32 i;
    for (i= 0; i < MAX_PART_IP_ADDRESS; i++) 
    {
        m_proxyIp[i] = ip[i];
    }
}
*/
void VappDtcntCommonAccountData::onInit()
{
    VfxObject::onInit();
}

void VappDtcntCommonAccountData::onDeinit()
{
    VfxObject::onDeinit();
}

/***************************************************************************** 
 * Class VappDtcntGPRSAccountData
 *****************************************************************************/

void VappDtcntGPRSAccountData::onInit() 
{
    VappDtcntCommonAccountData::onInit();
}

void VappDtcntGPRSAccountData::onDeinit()
{
    VappDtcntCommonAccountData::onDeinit();
}

/***************************************************************************** 
 * Class VappDtcntCSDAccountData
 *****************************************************************************/

#ifdef __TCPIP_OVER_CSD__

VFX_IMPLEMENT_CLASS("VappDtcntCSDAccountData", VappDtcntCSDAccountData, VappDtcntCommonAccountData);

void VappDtcntCSDAccountData::onInit() 
{
    VappDtcntCommonAccountData::onInit();
}

void VappDtcntCSDAccountData::onDeinit() 
{
    VappDtcntCommonAccountData::onDeinit();
}
#endif

/***************************************************************************** 
 * Class VappDtcntRightIconMultiTextFrame
 *****************************************************************************/

void VappDtcntRightIconMultiTextFrame::onCreateElements()
{
    VcpListMenuCellMultiTextFrame::onCreateElements();

    VFX_OBJ_CREATE(m_imageFrame, VfxImageFrame, this);
}


void VappDtcntRightIconMultiTextFrame::onLayoutElements()
{
    m_textFrame1->setRect(VfxRect(TEXT1_LEFT_GAPS, 
                                  TEXT1_TOP_GAPS,
                                  getRect().getWidth() - TEXT1_LEFT_GAPS - TEXT1_RIGHT_GAPS - IMG_LEFT_GAPS - IMG_RIGHT_GAPS - IMG_MAX_WIDTH,
                                  m_textFrame1->getRect().getHeight()));
    
    m_textFrame1->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE);

    
    m_textFrame2->setRect(VfxRect(TEXT2_LEFT_GAPS, 
                                  getRect().getHeight() - 1 - TEXT2_BOTTOM_GAPS - m_textFrame2->getRect().getHeight(),
                                  getRect().getWidth() - TEXT2_LEFT_GAPS - TEXT2_RIGHT_GAPS - IMG_LEFT_GAPS - IMG_RIGHT_GAPS - IMG_MAX_WIDTH,
                                  m_textFrame2->getRect().getHeight()));

    m_textFrame2->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE);

    m_imageFrame->setRect(getRect().getWidth() - 1 - IMG_RIGHT_GAPS - m_imageFrame->getRect().getWidth(), 
                          (getBounds().getHeight() - m_imageFrame->getBounds().getHeight()) / 2,
                          IMG_MAX_WIDTH, m_imageFrame->getRect().getHeight());

    m_imageFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE);
}


void VappDtcntRightIconMultiTextFrame::onUpdateElements()
{
    VcpListMenuCellMultiTextFrame::onUpdateElements();
    
    VfxImageSrc img;
    IVcpListMenuContentProviderInt *contentProvider = getContentProvider();

    if (contentProvider)
    {
        if (contentProvider->getItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON, img))
        {
            m_imageFrame->setImgContent(img);
        }
    }
}

/***************************************************************************** 
 * Class VappDtcntGPRSPage
 *****************************************************************************/

void VappDtcntGPRSPage::onInit()
{
    VfxPage::onInit();
    VappDtcntDispItemList::setCurrEditProfileId(m_acctId);
    // initial data
    VFX_OBJ_CREATE(m_gprsContext, VappDtcntGPRSAccountData, this);
    VFX_ALLOC_MEM(m_gprsProfileSrvCntx, sizeof(srv_dtcnt_prof_gprs_struct), this);
    memset(m_gprsProfileSrvCntx, 0x00, sizeof(srv_dtcnt_prof_gprs_struct));
    if(VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD == m_settingType)
    {
        m_gprsContext->setConnectionType(1);
        m_gprsContext->setProxyPort(0);
        m_gprsContext->setProxyPortStr((VfxWChar*)L"");
        m_gprsContext->setDnsPrimaryIpDisplay((VfxWChar*)L"0.0.0.0");
        m_gprsContext->setDnsSecondaryIpDisplay((VfxWChar*)L"0.0.0.0");
        m_gprsContext->setIpDisplay((VfxWChar*)L"0.0.0.0");
        m_gprsContext->setSubmaskIpDisplay((VfxWChar*)L"0.0.0.0");
        //m_gprsContext->setProxyIpDisplay((VfxWChar*)L"0.0.0.0");
    }
    else
    {
        loadGPRSInitContext(m_acctId, m_gprsProfileSrvCntx, m_gprsContext);
    }
    m_authType = m_gprsContext->getAuthType();
    // display titleBar
    VfxU32 gprsResId[3] = {STR_ID_VAPP_DTCNT_ADD_GPRS, STR_ID_VAPP_DTCNT_EDIT_PS_ACCOUNT, STR_ID_VAPP_DTCNT_VIEW_PS_ACCOUNT};
    vapp_dtcnt_set_titlebar(gprsResId[m_settingType], this);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    if (VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD == m_settingType || VAPP_DTCNT_ACCOUNT_SETTING_TYPE_EDIT == m_settingType)
    {
        //toolBar
        VcpToolBar *toolBar;
        VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
        toolBar->addItem(GPRS_TOOLBAR_ID_SAVE, STR_GLOBAL_SAVE, VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
        toolBar->addItem(GPRS_TOOLBAR_ID_CANCEL, STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
        toolBar->m_signalButtonTap.connect(this, &VappDtcntGPRSPage::onGPRSToolBarTapped);
        setBottomBar(toolBar);            
        editGprsPage();
    }
    else
    {
        viewGprsPage();
    } 
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__
    VFX_OBJ_GET_INSTANCE(VappDtcntSimAvailableListener)->m_signalSimChangedEvent.connect(this, &VappDtcntGPRSPage::onSimChangeEvt);  
#endif
} 

void VappDtcntGPRSPage::createTextInput(VfxFrame* functionBar, VfxU32 resId, VfxWChar *text, 
                                            VfxS32 maxLen, VfxU32 inputType, VfxId itemId)
{
    VcpFormItemTextInput *textInput;
    VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
    textInput->setLabelPosition(VCPFORM_TOP_LEFT);
    textInput->setLabelText(resId);
    textInput->getTextBox()->setIME(inputType);
    if(IMM_INPUT_TYPE_SENTENCE != inputType)
    {

        textInput->getTextBox()->setText(text, maxLen);
    }
    else
    {
        textInput->getTextBox()->setText(text, maxLen, VFX_FALSE, VCP_TEXT_ENCODING_ASCII);
    }
    textInput->getTextBox()->m_signalActivated.connect(this, &VappDtcntGPRSPage::onTextActivated);
    textInput->getTextBox()->setFunctionBar((VfxFrame*)functionBar);
    textInput->getTextBox()->setId(itemId);
    m_form->addItem(textInput, itemId);
}

void VappDtcntGPRSPage::editGprsPage()
{
    VcpFormItemBigButton *btn;
    VcpFormItemBigArrowButton *btnArrow;
    //form
    VcpFunctionBar *functionBar;
    VFX_OBJ_CREATE(functionBar, VcpFunctionBar, this);
    functionBar->addItem((VfxResId)STR_GLOBAL_PREV, (VfxId)ID_GPRS_FUNCTIONBAR_PREV);
    functionBar->addItem((VfxResId)STR_GLOBAL_NEXT, (VfxId)ID_GPRS_FUNCTIONBAR_NEXT);
    functionBar->addItem((VfxResId)STR_GLOBAL_SAVE, (VfxId)ID_GPRS_FUNCTIONBAR_SAVE);
    functionBar->setItemSpecial(ID_GPRS_FUNCTIONBAR_SAVE);
    functionBar->m_signalButtonTap.connect(this, &VappDtcntGPRSPage::onFunctionBarTap);
    createTextInput(functionBar, STR_ID_VAPP_DTCNT_RENAME, m_gprsContext->getDataAccountName(),
                    SRV_DTCNT_PROF_MAX_ACC_NAME_LEN, IMM_INPUT_TYPE_SENTENCE, GPRS_ITEM_ID_ACCOUNT_NAME);
    createTextInput(functionBar, STR_ID_VAPP_DTCNT_GPRS_APN, m_gprsContext->getAPN(),
                    SRV_DTCNT_PROF_MAX_APN_LEN, IMM_INPUT_TYPE_ASCII_CHAR, GPRS_ITEM_ID_APN);
    createTextInput(functionBar, STR_ID_VAPP_DTCNT_USERNAME, m_gprsContext->getUserName(),
                    SRV_DTCNT_PROF_MAX_USER_LEN, IMM_INPUT_TYPE_ASCII_CHAR, GPRS_ITEM_ID_USERNAME);
    createTextInput(functionBar, STR_GLOBAL_PASSWORD, m_gprsContext->getPassword(),
                    SRV_DTCNT_PROF_MAX_PW_LEN, IMM_INPUT_TYPE_ASCII_PASSWORD, GPRS_ITEM_ID_PASSWORD);
    VFX_OBJ_CREATE(btn, VcpFormItemBigButton, m_form);
    btn->setButtonText(VFX_WSTR_RES(STR_ID_VAPP_DTCNT_GPRS_AUTH_TYP));
    if (m_gprsContext->getAuthType() == 0)
    {
        btn->setHintText(STR_ID_VAPP_DTCNT_GPRS_PAP_AUTH);
    }
    else
    {
        btn->setHintText(STR_ID_VAPP_DTCNT_GPRS_CHAP_AUTH);
    }
    btn->getButton()->m_signalClicked.connect(this, &VappDtcntGPRSPage::onBtnAuthTypeTapped);
    m_form->addItem(btn, GPRS_ITEM_ID_AUTHTYPE);

    VFX_OBJ_CREATE(btnArrow, VcpFormItemBigArrowButton, m_form);
    btnArrow->setButtonText(STR_ID_VAPP_DTCNT_ADVANCED_SETTING);
    btnArrow->getButton()->m_signalClicked.connect(this, &VappDtcntGPRSPage::onBtnLaunchGPRSAdvancedSetting);
    m_form->addItem(btnArrow, GPRS_ITEM_ID_ADVANCED_SETTING);
}
            
void VappDtcntGPRSPage::viewGprsPage()
{
    VcpFormItemCustomFrame *customFrame;            
    VfxWString str;
    VcpFormItemBigArrowButton *btnArrow;
    // multiline text view
    VFX_ALLOC_MEM(m_detail, VAPP_DTCNT_GPRS_DETAIL_SIZE, this);
    m_detail[0] = 0;
    m_detail[1] = 0;

    VcpTextView *detailView;
    VFX_OBJ_CREATE(detailView, VcpTextView, m_form); // use form as parent
    detailView->setPos(VfxPoint(VAPP_DTCNT_DETAIL_GAP_LEFT, VAPP_DTCNT_DETAIL_GAP_TOP));
    detailView->setBounds(VfxRect(0, 0, getSize().width - VAPP_DTCNT_DETAIL_GAP_LEFT - VAPP_DTCNT_DETAIL_GAP_RIGHT, 0));
    detailView->setAutoResized(VFX_TRUE);
    detailView->enableVerticalScrollIndicator(VFX_FALSE);
    detailView->setText(m_detail, VFX_TRUE);

    VfxS32 maxLen;
    maxLen = (VAPP_DTCNT_GPRS_DETAIL_SIZE / 2) - 1;
    // account name
    detailView->addDetail(str.loadFromRes(STR_ID_VAPP_DTCNT_RENAME), VCP_TEXT_DETAIL_TITLE, maxLen);
    detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
    str.loadFromMem(m_gprsContext->getDataAccountName());
    str += VFX_WSTR_MEM((VfxWChar*)L"\n");
    detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);
    // APN
    detailView->addDetail(str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_APN), VCP_TEXT_DETAIL_TITLE, maxLen);
    detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
    str.loadFromMem(m_gprsContext->getAPN());
    str += VFX_WSTR_MEM((VfxWChar*)L"\n");
    detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);
    // username
    detailView->addDetail(str.loadFromRes(STR_ID_VAPP_DTCNT_USERNAME), VCP_TEXT_DETAIL_TITLE, maxLen);
    detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
    str.loadFromMem(m_gprsContext->getUserName());
    str += VFX_WSTR_MEM((VfxWChar*)L"\n");
    detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);
    // password
    detailView->addDetail(str.loadFromRes(STR_GLOBAL_PASSWORD), VCP_TEXT_DETAIL_TITLE, maxLen);
    detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
    str.loadFromMem(m_gprsContext->getPassword());
    str += VFX_WSTR_MEM((VfxWChar*)L"\n");
    detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);
   // Auth.type
    detailView->addDetail(str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_AUTH_TYP), VCP_TEXT_DETAIL_TITLE, maxLen);
    detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
    if (m_gprsContext->getAuthType() == 0)
    {
        str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_PAP_AUTH);
    }
    else
    {
        str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_CHAP_AUTH);
    }
    str += VFX_WSTR_MEM((VfxWChar*)L"\n");
    detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);

    detailView->forceUpdate();

    VFX_OBJ_CREATE(customFrame, VcpFormItemCustomFrame, this); // use this as parent
    customFrame->attachCustomFrame((VfxFrame*)detailView);
    m_form->addItem(customFrame, GPRS_DETAIL_ID_BASE); // need to define id here

    VFX_OBJ_CREATE(btnArrow, VcpFormItemBigArrowButton, m_form);
    btnArrow->setButtonText(STR_GLOBAL_ADVANCED);
    btnArrow->getButton()->m_signalClicked.connect(this, &VappDtcntGPRSPage::onBtnLaunchGPRSAdvancedSetting);
    m_form->addItem(btnArrow, GPRS_DETAIL_ID_ADVANCED);
}

void VappDtcntGPRSPage::onBarSaveCommond()
{
    // check account in use or not first
    if (VAPP_DTCNT_ACCOUNT_SETTING_TYPE_EDIT == m_settingType)
    {
        if (VappDtcntDispItemList::isAccountInUse(m_acctId))
        {
            getMainScr()->popPage();
            return;
        }
    }
    // check validity, and save to display context if valid
    VcpFormItemTextInput *textInput;
    textInput = (VcpFormItemTextInput *)m_form->getItem(GPRS_ITEM_ID_APN);
    VfxWChar *str;
    str = textInput->getTextBox()->getText();
    if (mmi_wcslen((WCHAR*)str) == 0)
    {
        VfxWString string;
        string.loadFromRes(STR_ID_VAPP_DTCNT_APN_NEEDED);
        textInput->setWarningText(string);
        m_form->scrollItemToView(GPRS_ITEM_ID_APN, VCPFORM_SCROLL_TOP);
        return;
    }

    srv_dtcnt_store_prof_data_struct profInfo;
    srv_dtcnt_result_enum result;    
    profInfo.prof_type = SRV_DTCNT_BEARER_GPRS;
    profInfo.prof_data = m_gprsProfileSrvCntx;
    profInfo.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;

    // apn
    VfxChar *apn;
    VfxWChar *name;
    VFX_ALLOC_MEM(apn, (SRV_DTCNT_PROF_MAX_APN_LEN + 1), this);
    VFX_ALLOC_MEM(name, (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1) * ENCODING_LENGTH, this);
    mmi_wcs_to_asc((CHAR*)apn, (WCHAR*)str);
    m_gprsProfileSrvCntx->APN = (U8*)apn;

    //account name
    textInput = (VcpFormItemTextInput *)m_form->getItem(GPRS_ITEM_ID_ACCOUNT_NAME);
    str = textInput->getTextBox()->getText();
    m_gprsProfileSrvCntx->prof_common_header.AccountName = (U8*)str;

    // user name
    textInput = (VcpFormItemTextInput *)m_form->getItem(GPRS_ITEM_ID_USERNAME);
    str = textInput->getTextBox()->getText();
    mmi_wcs_to_asc((CHAR*)m_gprsProfileSrvCntx->prof_common_header.Auth_info.UserName, (WCHAR*)str);

    // password            
    textInput = (VcpFormItemTextInput *)m_form->getItem(GPRS_ITEM_ID_PASSWORD);
    str = textInput->getTextBox()->getText();
    mmi_wcs_to_asc((CHAR*)m_gprsProfileSrvCntx->prof_common_header.Auth_info.Passwd, (WCHAR*)str);

    // auth_type
    m_gprsProfileSrvCntx->prof_common_header.Auth_info.AuthType = (srv_dtcnt_prof_gprs_auth_type_enum)m_authType;

    // sim
    srv_dtcnt_sim_type_enum simType;
    simType = m_simType;
    m_gprsProfileSrvCntx->prof_common_header.sim_info = simType;

    // configure type
    if (m_settingType == VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD)
    {
        m_gprsProfileSrvCntx->prof_common_header.acct_type = SRV_DTCNT_PROF_TYPE_USER_CONF;
    }

    // homepage
    str = m_gprsContext->getHomePage();
    mmi_wcs_to_asc((CHAR*)m_gprsProfileSrvCntx->prof_common_header.HomePage, (WCHAR*)str);

    // connection type
    if (m_gprsContext->getConnectionType())
    {
        m_gprsProfileSrvCntx->prof_common_header.px_service = SRV_DTCNT_PROF_PX_SRV_HTTP;
    }
    else
    {
        m_gprsProfileSrvCntx->prof_common_header.px_service = SRV_DTCNT_PROF_PX_SRV_CO_WSP;
    }

    // use proxy
    m_gprsProfileSrvCntx->prof_common_header.use_proxy = m_gprsContext->getUseProxy();

    // proxy address and other ip
    str = m_gprsContext->getProxyAddress();
    mmi_wcs_to_asc((CHAR*)m_gprsProfileSrvCntx->prof_common_header.px_addr, (WCHAR*)str);
    VfxU8 *tempIP2, *tempIP3, *tempIP4, *tempIP5;
    //tempIP1 = m_gprsContext->getProxyIp();
    tempIP2 = m_gprsContext->getDnsPrimaryIp();
    tempIP3 = m_gprsContext->getDnsSecondaryIp();
    tempIP4 = m_gprsContext->getIp();
    tempIP5 = m_gprsContext->getSubmaskIp();
    VfxS32 i;
    for (i = 0; i < MAX_PART_IP_ADDRESS; i++)
    {
        //m_gprsProfileSrvCntx->prof_common_header.px_addr[i] = tempIP1[i];
        m_gprsProfileSrvCntx->prof_common_header.PrimaryAddr[i] = tempIP2[i];
        m_gprsProfileSrvCntx->prof_common_header.SecondaryAddr[i] = tempIP3[i];
        m_gprsProfileSrvCntx->prof_common_header.StaicIPAddr[i] = tempIP4[i];
        m_gprsProfileSrvCntx->prof_common_header.NetMask[i] = tempIP5[i];
    }

    // proxy port
    if (m_gprsContext->getConnectionType())
    {
        if (m_gprsContext->getUseProxy())
        {
            str = m_gprsContext->getProxyPortStr();
            VfxChar temp[VAPP_DTCNT_MAX_PORT_LENGTH + 1];
            mmi_wcs_to_asc((CHAR*)temp, (WCHAR*)str);
            m_gprsProfileSrvCntx->prof_common_header.px_port = (U16)atoi((char*)temp);
        }
        else
        {
            m_gprsProfileSrvCntx->prof_common_header.px_port = 0;
        }
    }
    else
    {
        if (m_gprsContext->getWapPortIndex())
        {
            m_gprsProfileSrvCntx->prof_common_header.px_port = 9203;
        }
        else
        {
            m_gprsProfileSrvCntx->prof_common_header.px_port = 9201;
        }
    }

    // proxy user name
    str = m_gprsContext->getProxyUserName();
    mmi_wcs_to_asc((CHAR*)m_gprsProfileSrvCntx->prof_common_header.px_authid, (WCHAR*)str);

    // proxy password            
    str = m_gprsContext->getProxyPassword();
    mmi_wcs_to_asc((CHAR*)m_gprsProfileSrvCntx->prof_common_header.px_authpw, (WCHAR*)str);

    // account name
    if (m_settingType == VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD)
    {
        // add first
        result = srv_dtcnt_store_add_prof(&profInfo, &m_acctId);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_ADD_PROFILE, m_acctId, result);

        if (result == SRV_DTCNT_RESULT_SUCCESS)
        {
            VappDtcntDispItem acctItem(m_acctId, m_gprsContext->getConnectionType(), (VfxU8)simType,
                                        DATA_ACCOUNT_BEARER_GPRS, 0, m_gprsProfileSrvCntx->prof_common_header.acct_type);
            VappDtcntDispItemList::addAcctItem(acctItem);
            MMI_BOOL ret;
            VfxU32 defaultId;
            ret = srv_dtcnt_get_default_account(m_simType, &defaultId);
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_DEFAULT_ACCOUNT, m_simType, defaultId, ret);
        }
        else if(result == SRV_DTCNT_RESULT_STORE_FULL)
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_INFO,
                (WCHAR*)GetString(STR_ID_VAPP_DTCNT_ACCT_MAX_NUM));
        }
    }
    else if (m_settingType == VAPP_DTCNT_ACCOUNT_SETTING_TYPE_EDIT)
    {                
        result = srv_dtcnt_store_update_prof(m_acctId, &profInfo);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_UPDATE_PROFILE, m_acctId, result);
        if (result == SRV_DTCNT_RESULT_SUCCESS)
        {
            VappDtcntDispItem acctItem(m_acctId, m_gprsContext->getConnectionType(), (VfxU8)simType,
                                        DATA_ACCOUNT_BEARER_GPRS, 0, m_gprsProfileSrvCntx->prof_common_header.acct_type);
            VappDtcntDispItemList::updateAcctItem(acctItem);
        }
    }
    VFX_FREE_MEM(apn); // free memory
    VFX_FREE_MEM(name); // free memory
    getMainScr()->popPage();
}


void VappDtcntGPRSPage::onGPRSToolBarTapped(
        VfxObject* sender,  // sender
        VfxId id            // id
    )
{
    if(GPRS_TOOLBAR_ID_SAVE == id)
    {
        onBarSaveCommond();
    }
    else
    {
        getMainScr()->popPage();
    }
}


void VappDtcntGPRSPage::onFunctionBarTap(
        VfxObject *sender,  // [IN] sender object
        VfxId id            // [IN] Toolbar id
    )
{
    switch (id)
    {
        case ID_GPRS_FUNCTIONBAR_PREV:
        {
            VfxId prevId = GPRS_ITEM_ID_ACCOUNT_NAME;
            if(GPRS_ITEM_ID_ACCOUNT_NAME != m_currActiveId)
            {
                prevId = --m_currActiveId;
            }
            textEditorState(m_form, prevId, VFX_TRUE);
            break;
        }
        
        case ID_GPRS_FUNCTIONBAR_NEXT:
        {
            VfxId nextId = GPRS_ITEM_ID_PASSWORD;
            if(GPRS_ITEM_ID_PASSWORD != m_currActiveId)
            {
                nextId = ++m_currActiveId;
            }
            textEditorState(m_form, nextId, VFX_TRUE);
            break;
        }
        
        case ID_GPRS_FUNCTIONBAR_SAVE:
        {
            VcpFormItemTextInput* textInput;
            textInput = (VcpFormItemTextInput*)(m_form->getItem(m_currActiveId));
            textInput->getTextBox()->deactivate();
            onBarSaveCommond();
            break;
        }
        default:
            break;
    }
}

void VappDtcntGPRSPage::onTextActivated(
    VcpTextEditor *sender,  // [IN] send object
    VfxBool  activated      // [IN] activate flag
)
{
    if (activated)
    {
        m_currActiveId = sender->getId();
        VcpFunctionBar *functionBar;
        functionBar = (VcpFunctionBar *)sender->getFunctionBar();
        if (m_currActiveId == GPRS_ITEM_ID_ACCOUNT_NAME)
        {
            functionBar->setDisableItem(ID_GPRS_FUNCTIONBAR_PREV, VFX_TRUE);
            functionBar->setDisableItem(ID_GPRS_FUNCTIONBAR_NEXT, VFX_FALSE);
        } 
        else if (m_currActiveId == GPRS_ITEM_ID_PASSWORD)
        {
            functionBar->setDisableItem(ID_GPRS_FUNCTIONBAR_PREV, VFX_FALSE);
            functionBar->setDisableItem(ID_GPRS_FUNCTIONBAR_NEXT, VFX_TRUE);
        }
        else
        {
            functionBar->setDisableItem(ID_GPRS_FUNCTIONBAR_PREV, VFX_FALSE);
            functionBar->setDisableItem(ID_GPRS_FUNCTIONBAR_NEXT, VFX_FALSE);
        }        
    }
}


void VappDtcntGPRSPage::onLaunchGPRSAdvancedSetting(
    VcpFormItemCell* sender, // Sender
    VfxId id) // Sender id
{
    VappDtcntAdvancedPage *advancedSettingPage;
    VFX_OBJ_CREATE_EX(advancedSettingPage, VappDtcntAdvancedPage, this, (m_settingType, m_gprsContext, m_simType, VFX_TRUE));
    getMainScr()->pushPage(0, advancedSettingPage);
}

void VappDtcntGPRSPage::onBtnAuthTypeTapped(
        VfxObject* sender, //sender 
        VfxId id //
    )
{
    // de-active editor
    textEditorState(m_form, m_currActiveId, VFX_FALSE);
    
    VcpSelectPopup *selectPopup;
    VFX_OBJ_CREATE(selectPopup, VcpSelectPopup, this);
    selectPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
    VfxWString str;
    str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_AUTH_TYP);
    selectPopup->setText(str);
    selectPopup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    
    if (m_authType == 0)
    {
        str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_PAP_AUTH);
        selectPopup->addItem(0, str, VFX_TRUE);
        str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_CHAP_AUTH);
        selectPopup->addItem(1, str, VFX_FALSE);
    }
    else
    {
        str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_PAP_AUTH);
        selectPopup->addItem(0, str, VFX_FALSE);
        str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_CHAP_AUTH);
        selectPopup->addItem(1, str, VFX_TRUE);
    }

    selectPopup->m_signalPopupState.connect(this, &VappDtcntGPRSPage::onSelectAuthType);
    selectPopup->show(VFX_FALSE);
}


void VappDtcntGPRSPage::onSelectAuthType(
    VfxBasePopup *sender,        // popup
    VfxBasePopupStateEnum state  // state
)
{
    if(state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {        
        VcpSelectPopup *senderPopup;
        senderPopup = (VcpSelectPopup*)sender;
        VfxId i;
        i = senderPopup->getFirstSeletedId();

        if (i == m_authType)
        {
            return; // not changed
        }

        VcpFormItemBigButton *btn;
        VfxWString str;
        btn =(VcpFormItemBigButton *)(m_form->getItem(GPRS_ITEM_ID_AUTHTYPE));
        if (i == 0)
        {
            m_authType = 0;
            str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_PAP_AUTH);
            btn->setHintText(str);
        }
        else
        {
            m_authType = 1;
            str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_CHAP_AUTH);
            btn->setHintText(str);
        }
        return;
    }
}


void VappDtcntGPRSPage::onBtnLaunchGPRSAdvancedSetting(
        VfxObject* sender, //sender 
        VfxId id //
    )
{
    VappDtcntAdvancedPage *advancedSettingPage;
    VFX_OBJ_CREATE_EX(advancedSettingPage, VappDtcntAdvancedPage, getMainScr(), (m_settingType, m_gprsContext, m_simType, VFX_TRUE));
    getMainScr()->pushPage(0, advancedSettingPage);
}

void VappDtcntGPRSPage::loadGPRSInitContext(
        VfxU32 acctId, // [IN] acctId
        srv_dtcnt_prof_gprs_struct *srvCntx, // [OUT] 
        VappDtcntGPRSAccountData *displayContext // [OUT]
    )
{
    // srvCntx is initialized out of this api
    VFX_ASSERT(srvCntx);

    srv_dtcnt_result_enum result;
    srv_dtcnt_store_prof_data_struct profInfo;
    profInfo.prof_type = SRV_DTCNT_BEARER_GPRS;
    profInfo.prof_data = srvCntx;
    profInfo.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
    result =  srv_dtcnt_store_qry_prof(acctId, &profInfo);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_PROFILE, acctId, result);

    VfxWChar *str; // use the max length to allow memory, homepage is the max type
    VFX_ALLOC_MEM(str, (MAX_ADDRESS_NAME_LEN) * sizeof(VfxWChar), this);

    // account name
    displayContext->setDataAccountName((VfxWChar*)srvCntx->prof_common_header.AccountName);

    // apn
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)srvCntx->APN);
    displayContext->setAPN((VfxWChar*)str);

    // user name
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)srvCntx->prof_common_header.Auth_info.UserName);
    displayContext->setUserName((VfxWChar*)str);

    // password
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)srvCntx->prof_common_header.Auth_info.Passwd);
    displayContext->setPassword((VfxWChar*)str);

    // authType
    displayContext->setAuthType((VfxU8)srvCntx->prof_common_header.Auth_info.AuthType);

    // homepage
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)srvCntx->prof_common_header.HomePage);
    displayContext->setHomePage((VfxWChar*)str);

    // connection type
    if (srvCntx->prof_common_header.px_service == SRV_DTCNT_PROF_PX_SRV_CL_WSP ||
        srvCntx->prof_common_header.px_service == SRV_DTCNT_PROF_PX_SRV_CO_WSP ||
        srvCntx->prof_common_header.px_service == SRV_DTCNT_PROF_PX_SRV_CL_SEC_WSP ||
        srvCntx->prof_common_header.px_service == SRV_DTCNT_PROF_PX_SRV_CO_SEC_WSP ||
        srvCntx->prof_common_header.px_service == SRV_DTCNT_PROF_PX_SRV_CL_SEC_WTA ||
        srvCntx->prof_common_header.px_service == SRV_DTCNT_PROF_PX_SRV_CO_SEC_WTA)
    {
        displayContext->setConnectionType(0);
    }
    else    
    {
        displayContext->setConnectionType(1);
    }

    // proxy
    if (srvCntx->prof_common_header.use_proxy)
    {
        displayContext->setUseProxy(1); 
	mmi_asc_to_wcs((WCHAR*)str, (CHAR*)srvCntx->prof_common_header.px_addr);
	displayContext->setProxyAddress((VfxWChar*)str);
        displayContext->setProxyPort(srvCntx->prof_common_header.px_port);
        //displayContext->setProxyIp(srvCntx->prof_common_header.px_addr);
        mmi_asc_to_wcs((WCHAR*)str, (CHAR*)srvCntx->prof_common_header.px_authid);
        displayContext->setProxyUserName((VfxWChar*)str);
        mmi_asc_to_wcs((WCHAR*)str, (CHAR*)srvCntx->prof_common_header.px_authpw);
        displayContext->setProxyPassword((VfxWChar*)str);

        displayContext->setWapPortIndex(0);

        if (!displayContext->getConnectionType())
        {
            if (srvCntx->prof_common_header.px_port == 9203)
            {
                displayContext->setWapPortIndex(1);
            }
        }

        // port string
        VfxChar strDigist[VAPP_DTCNT_MAX_PORT_LENGTH + 1];
        sprintf(strDigist, "%d", srvCntx->prof_common_header.px_port);
        mmi_asc_to_wcs((WCHAR*)str, (CHAR*)strDigist);
        displayContext->setProxyPortStr((VfxWChar*)str);
    }
    else
    {
        displayContext->setUseProxy(0);
        // port string
        //VfxChar strDigist[VAPP_DTCNT_MAX_PORT_LENGTH + 1];
        //sprintf(strDigist, "%d", 0);
        //mmi_asc_to_wcs((WCHAR*)str, (CHAR*)strDigist);
        displayContext->setProxyPortStr((VfxWChar*)L"");
    }
    
    // others
    displayContext->setDnsPrimaryIp(srvCntx->prof_common_header.PrimaryAddr);
    displayContext->setDnsSecondaryIp(srvCntx->prof_common_header.SecondaryAddr);
    displayContext->setIp(srvCntx->prof_common_header.StaicIPAddr);
    displayContext->setSubmaskIp(srvCntx->prof_common_header.NetMask);

    // need convert ip to display string
    VfxChar ipStr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN * 4];
    VfxU8 *ip;
    ip = displayContext->getDnsPrimaryIp();  
    sprintf(ipStr, "%d.%d.%d.%d", ip[0],ip[1],ip[2],ip[3]);
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)ipStr);
    displayContext->setDnsPrimaryIpDisplay((VfxWChar*)str);

    ip = displayContext->getDnsSecondaryIp();  
    sprintf(ipStr, "%d.%d.%d.%d", ip[0],ip[1],ip[2],ip[3]);
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)ipStr);
    displayContext->setDnsSecondaryIpDisplay((VfxWChar*)str);

    ip = displayContext->getIp();  
    sprintf(ipStr, "%d.%d.%d.%d", ip[0],ip[1],ip[2],ip[3]);
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)ipStr);
    displayContext->setIpDisplay((VfxWChar*)str);

    ip = displayContext->getSubmaskIp();  
    sprintf(ipStr, "%d.%d.%d.%d", ip[0],ip[1],ip[2],ip[3]);
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)ipStr);
    displayContext->setSubmaskIpDisplay((VfxWChar*)str);
/*
    ip = displayContext->getProxyIp();  
    sprintf(ipStr, "%d.%d.%d.%d", ip[0],ip[1],ip[2],ip[3]);
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)ipStr);
    displayContext->setProxyIpDisplay((VfxWChar*)str);
   */ 
    VFX_FREE_MEM(str);
}

#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
void VappDtcntGPRSPage::onSimChangeEvt(VfxBool flag, mmi_sim_enum sim)
{
	VfxU32 simIndex = 0;
	simIndex = mmi_frm_sim_to_index(sim);
	if(VFX_FALSE == flag)
	{
		if(simIndex == (VfxU32)(m_simType - 1))
		{
			getMainScr()->closePage(getId());
		}
    }
}
#endif

void VappDtcntGPRSPage::onDeinit()
{
    if (m_gprsProfileSrvCntx)
    {
        VFX_FREE_MEM(m_gprsProfileSrvCntx);
    }
    if (m_detail)
    {
        VFX_FREE_MEM(m_detail);
    }
    VappDtcntDispItemList::setCurrEditProfileId(CBM_INVALID_NWK_ACCT_ID);
    VfxPage::onDeinit();
}

/***************************************************************************** 
 * Class VappDtcntCSDPage
 *****************************************************************************/
 #ifdef __TCPIP_OVER_CSD__
 
VFX_IMPLEMENT_CLASS("VappDtcntCSDPage", VappDtcntCSDPage, VfxPage);

void VappDtcntCSDPage::onInit()
{
    VfxPage::onInit();
    VappDtcntDispItemList::setCurrEditProfileId(m_acctId);
    // initial data
    VFX_OBJ_CREATE(m_csdContext, VappDtcntCSDAccountData, this);
    VFX_ALLOC_MEM(m_csdProfileSrvCntx, sizeof(srv_dtcnt_prof_csd_struct), this);
    memset(m_csdProfileSrvCntx, 0x00, sizeof(srv_dtcnt_prof_csd_struct));
    switch (m_settingType)
    {
        case VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD:
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #else
            m_csdContext->setConnectionType(1);
            m_csdContext->setProxyPort(0);
            m_csdContext->setProxyPortStr((VfxWChar*)L"");
            #endif
            // need convert ip to display string
            m_csdContext->setDnsPrimaryIpDisplay((VfxWChar*)L"0.0.0.0");
            m_csdContext->setDnsSecondaryIpDisplay((VfxWChar*)L"0.0.0.0");
            m_csdContext->setIpDisplay((VfxWChar*)L"0.0.0.0");
            m_csdContext->setSubmaskIpDisplay((VfxWChar*)L"0.0.0.0");
            //m_csdContext->setProxyIpDisplay((VfxWChar*)L"0.0.0.0");
            break;
        case VAPP_DTCNT_ACCOUNT_SETTING_TYPE_EDIT:
        case VAPP_DTCNT_ACCOUNT_SETTING_TYPE_VIEW:
            loadCSDInitContext(m_acctId, m_csdProfileSrvCntx, m_csdContext);
            break;
    }
    // keep value if cancel
    m_lineType = m_csdContext->getLineType();
    m_speed = m_csdContext->getSpeed();
    
    // display titleBar
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);    
    VfxWString str;
    //str.loadFromRes(STR_GLOBAL_DATA_ACCOUNT);
    //titleBar->setTitle(str);
    switch (m_settingType)
    {
        case VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD:
            str.loadFromRes(STR_ID_VAPP_DTCNT_ADD_CSD);
            titleBar->setTitle(str);
            break;
        case VAPP_DTCNT_ACCOUNT_SETTING_TYPE_EDIT:
            str.loadFromRes(STR_ID_VAPP_DTCNT_EDIT_CSD_ACCOUNT);
            titleBar->setTitle(str);
            break;
        case VAPP_DTCNT_ACCOUNT_SETTING_TYPE_VIEW:
            str.loadFromRes(STR_ID_VAPP_DTCNT_VIEW_CSD_ACCOUNT);
            titleBar->setTitle(str);
            break;
        default:
            break;
    }    
    setTopBar(titleBar);    

    // display toolBar
    switch (m_settingType)
    {
        case VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD:
        case VAPP_DTCNT_ACCOUNT_SETTING_TYPE_EDIT:
            VcpToolBar *toolBar;
            VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
            str.loadFromRes(STR_GLOBAL_SAVE);
            toolBar->addItem(CSD_TOOLBAR_ID_SAVE, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
            str.loadFromRes(STR_GLOBAL_CANCEL);
            toolBar->addItem(CSD_TOOLBAR_ID_CANCEL, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
            toolBar->m_signalButtonTap.connect(this, &VappDtcntCSDPage::onCSDToolBarTapped);
            setBottomBar(toolBar);            
            break;
        case VAPP_DTCNT_ACCOUNT_SETTING_TYPE_VIEW:
            break;
        default:
            break;
    } 

    // form
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    VcpFormItemBigButton *btn;
    VcpFormItemBigArrowButton *btnArrow;
    switch (m_settingType)
    {
        case VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD:
        case VAPP_DTCNT_ACCOUNT_SETTING_TYPE_EDIT:
            VcpFunctionBar *functionBar;
            VFX_OBJ_CREATE(functionBar, VcpFunctionBar, this);
            str.loadFromRes(STR_GLOBAL_PREV);
            functionBar->addItem(ID_CSD_FUNCTIONBAR_PREV, str);
            str.loadFromRes(STR_GLOBAL_NEXT);
            functionBar->addItem(ID_CSD_FUNCTIONBAR_NEXT, str);
            str.loadFromRes(STR_GLOBAL_SAVE);
            functionBar->addItem(ID_CSD_FUNCTIONBAR_SAVE, str);
            functionBar->setItemSpecial(ID_CSD_FUNCTIONBAR_SAVE);
            functionBar->m_signalButtonTap.connect(this, &VappDtcntCSDPage::onFunctionBarTap);
            VcpFormItemTextInput *textInput;
            VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
            textInput->setLabelPosition(VCPFORM_TOP_LEFT);
            str.loadFromRes(STR_ID_VAPP_DTCNT_RENAME);
            textInput->setLabelText(str);
            //TODO: need to add ime extention 
            textInput->getTextBox()->setIME(IMM_INPUT_TYPE_SENTENCE);
            textInput->getTextBox()->setText(
                m_csdContext->getDataAccountName(), 
                SRV_DTCNT_PROF_MAX_ACC_NAME_LEN,
                VFX_FALSE,
                VCP_TEXT_ENCODING_ASCII); 
            textInput->getTextBox()->setId(CSD_ITEM_ID_ACCOUNT_NAME);
            textInput->getTextBox()->m_signalActivated.connect(this, &VappDtcntCSDPage::onTextActivated);
            textInput->getTextBox()->setFunctionBar((VfxFrame*)functionBar);
            //textInput->getTextBox()->setAutoDeactivated(VFX_TRUE);
            m_form->addItem(textInput, CSD_ITEM_ID_ACCOUNT_NAME);

            VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
            textInput->setLabelPosition(VCPFORM_TOP_LEFT);
            str.loadFromRes(STR_ID_VAPP_DTCNT_DIAL_NUMBER);
            textInput->setLabelText(str);
            textInput->getTextBox()->setIME(IMM_INPUT_TYPE_PHONE_NUMBER, IME_PLUS_CHAR_HANDLING);
            textInput->getTextBox()->setText(m_csdContext->getDialNumber(), SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN - 1);
            textInput->getTextBox()->setId(CSD_ITEM_ID_NUMBER);
            textInput->getTextBox()->m_signalActivated.connect(this, &VappDtcntCSDPage::onTextActivated);
            textInput->getTextBox()->setFunctionBar((VfxFrame*)functionBar);
            //textInput->getTextBox()->setAutoDeactivated(VFX_TRUE);
            m_form->addItem(textInput, CSD_ITEM_ID_NUMBER);

            VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
            textInput->setLabelPosition(VCPFORM_TOP_LEFT);
            str.loadFromRes(STR_ID_VAPP_DTCNT_USERNAME);
            textInput->setLabelText(str);
            textInput->getTextBox()->setIME(IMM_INPUT_TYPE_ASCII_CHAR);
            textInput->getTextBox()->setText(m_csdContext->getUserName(), SRV_DTCNT_PROF_MAX_USER_LEN);
            textInput->getTextBox()->setId(CSD_ITEM_ID_USERNAME);
            textInput->getTextBox()->m_signalActivated.connect(this, &VappDtcntCSDPage::onTextActivated);
            textInput->getTextBox()->setFunctionBar((VfxFrame*)functionBar);
            //textInput->getTextBox()->setAutoDeactivated(VFX_TRUE);
            m_form->addItem(textInput, CSD_ITEM_ID_USERNAME);

            VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
            textInput->setLabelPosition(VCPFORM_TOP_LEFT);
            str.loadFromRes(STR_GLOBAL_PASSWORD);
            textInput->setLabelText(str);
            textInput->getTextBox()->setText(m_csdContext->getPassword(), SRV_DTCNT_PROF_MAX_PW_LEN);
            textInput->getTextBox()->setIME(IMM_INPUT_TYPE_ASCII_PASSWORD);
            textInput->getTextBox()->setId(CSD_ITEM_ID_PASSWORD);
            textInput->getTextBox()->m_signalActivated.connect(this, &VappDtcntCSDPage::onTextActivated);
            textInput->getTextBox()->setFunctionBar((VfxFrame*)functionBar);
            //textInput->getTextBox()->setAutoDeactivated(VFX_TRUE);
            m_form->addItem(textInput, CSD_ITEM_ID_PASSWORD);

            VFX_OBJ_CREATE(btn, VcpFormItemBigButton, m_form);
            str.loadFromRes(STR_ID_VAPP_DTCNT_DIAL_TYPE);
            btn->setButtonText(str);
            if (m_csdContext->getLineType() == 0)
            {
                str.loadFromRes(STR_ID_VAPP_DTCNT_ANALOGUE_STR);
                btn->setHintText(str);
            }
            else
            {
                str.loadFromRes(STR_ID_VAPP_DTCNT_ISDN_STR);
                btn->setHintText(str);
            }
            btn->getButton()->m_signalClicked.connect(this, &VappDtcntCSDPage::onBtnLineTypeTapped);
            m_form->addItem(btn, CSD_ITEM_ID_LINETYPE);

            VFX_OBJ_CREATE(btn, VcpFormItemBigButton, m_form);
            str.loadFromRes(STR_ID_VAPP_DTCNT_DATA_RATE);
            btn->setButtonText(str);
            
            btn->setHintText(str.loadFromRes(STR_ID_VAPP_DTCNT_RATE_STR_ZERO + m_csdContext->getSpeed()));
            
            btn->getButton()->m_signalClicked.connect(this, &VappDtcntCSDPage::onBtnSpeedTypeTapped);
            m_form->addItem(btn, CSD_ITEM_ID_SPEED);

            VFX_OBJ_CREATE(btnArrow, VcpFormItemBigArrowButton, m_form);
            str.loadFromRes(STR_ID_VAPP_DTCNT_ADVANCED_SETTING);
            btnArrow->setButtonText(str);
            btnArrow->getButton()->m_signalClicked.connect(this, &VappDtcntCSDPage::onBtnLaunchCSDAdvancedSetting);
            m_form->addItem(btnArrow, CSD_ITEM_ID_ADVANCED_SETTING);
            /*VcpFormItemLauncherCell *launch;
            VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
            launch->setMainText(VFX_WSTR("Advanced setting"));
            launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
            launch->m_signalTap.connect(this, &VappDtcntCSDPage::onLaunchCSDAdvancedSetting);
            m_form->addItem(launch, CSD_ITEM_ID_ADVANCED_SETTING);*/
            break;

        case VAPP_DTCNT_ACCOUNT_SETTING_TYPE_VIEW:
            VcpFormItemCustomFrame *customFrame;            
            VfxS32 xPos, yPos;
            xPos = VAPP_DTCNT_DETAIL_GAP_LEFT;
            yPos = VAPP_DTCNT_DETAIL_GAP_TOP;    
            // multiline text view
            VFX_ALLOC_MEM(m_detail, VAPP_DTCNT_CSD_DETAIL_SIZE, this);
            m_detail[0] = 0;
            m_detail[1] = 0;

            VcpTextView *detailView;
            VFX_OBJ_CREATE(detailView, VcpTextView, m_form); // use form as parent
            detailView->setPos(VfxPoint(xPos, yPos));
            detailView->setBounds(VfxRect(0, 0, getSize().width - VAPP_DTCNT_DETAIL_GAP_LEFT - VAPP_DTCNT_DETAIL_GAP_RIGHT, 0));
            detailView->setAutoResized(VFX_TRUE);
            detailView->enableVerticalScrollIndicator(VFX_FALSE);
    
            detailView->setText(m_detail, VFX_TRUE);

            VfxS32 maxLen;
            maxLen = (VAPP_DTCNT_CSD_DETAIL_SIZE / 2) - 1;
            // account name
            str.loadFromRes(STR_ID_VAPP_DTCNT_RENAME);
            detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
            detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
            str.loadFromMem(m_csdContext->getDataAccountName());
            str += VFX_WSTR_MEM((VfxWChar*)L"\n");
            detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);
            //detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_CONTENT, maxLen);

            // dial number
            str.loadFromRes(STR_ID_VAPP_DTCNT_DIAL_NUMBER);
            detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
            detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
            str.loadFromMem(m_csdContext->getDialNumber());
            str += VFX_WSTR_MEM((VfxWChar*)L"\n");
            detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);
            //detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_CONTENT, maxLen);

            // username
            str.loadFromRes(STR_ID_VAPP_DTCNT_USERNAME);
            detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
            detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
            str.loadFromMem(m_csdContext->getUserName());
            str += VFX_WSTR_MEM((VfxWChar*)L"\n");
            detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);
            //detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_CONTENT, maxLen);

            // password
            str.loadFromRes(STR_GLOBAL_PASSWORD);
            detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
            detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
            str.loadFromMem(m_csdContext->getPassword());
            str += VFX_WSTR_MEM((VfxWChar*)L"\n");
            detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);
            //detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_CONTENT, maxLen);

            // dial type
            str.loadFromRes(STR_ID_VAPP_DTCNT_DIAL_TYPE);
            detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
            detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
            if (m_csdContext->getLineType() == 0)
            {
                str.loadFromRes(STR_ID_VAPP_DTCNT_ANALOGUE_STR);
            }
            else
            {
                str.loadFromRes(STR_ID_VAPP_DTCNT_ISDN_STR);
            }
            str += VFX_WSTR_MEM((VfxWChar*)L"\n");
            detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);
            //detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_CONTENT, maxLen);

            // speed
            str.loadFromRes(STR_ID_VAPP_DTCNT_DATA_RATE);
            detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
            detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
            str.loadFromRes(STR_ID_VAPP_DTCNT_RATE_STR_ZERO + m_csdContext->getSpeed());
            str += VFX_WSTR_MEM((VfxWChar*)L"\n");
            detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);
            //detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_CONTENT, maxLen);
            
            detailView->forceUpdate();

            VFX_OBJ_CREATE(customFrame, VcpFormItemCustomFrame, this); // use this as parent
            customFrame->attachCustomFrame((VfxFrame*)detailView);
            m_form->addItem(customFrame, CSD_DETAIL_ID_BASE); // need to define id here
            //m_form->insertSeparator(CSD_DETAIL_ID_BASE); // need to define id here

            VFX_OBJ_CREATE(btnArrow, VcpFormItemBigArrowButton, m_form);
            str.loadFromRes(STR_GLOBAL_ADVANCED);
            btnArrow->setButtonText(str);
            btnArrow->getButton()->m_signalClicked.connect(this, &VappDtcntCSDPage::onBtnLaunchCSDAdvancedSetting);
            m_form->addItem(btnArrow, CSD_DETAIL_ID_ADVANCED);
            break;
        default:
            break;
    } 
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__
	VFX_OBJ_GET_INSTANCE(VappDtcntSimAvailableListener)->m_signalSimChangedEvent.connect(this, &VappDtcntCSDPage::onSimChangeEvt);
#endif
}


void VappDtcntCSDPage::onBarSaveCommond()
{
    // check account in use or not first
    if (VAPP_DTCNT_ACCOUNT_SETTING_TYPE_EDIT == m_settingType)
    {
        if (VappDtcntDispItemList::isAccountInUse(m_acctId))
        {
            getMainScr()->popPage();
            return;
        }
    }
    // check validity, and save to display context if valid
    VcpFormItemTextInput *textInput;
    textInput = (VcpFormItemTextInput *)m_form->getItem(CSD_ITEM_ID_NUMBER);
    VfxWChar *str;
    str = textInput->getTextBox()->getText();
    if (mmi_wcslen((WCHAR*)str) == 0)
    {
        VfxWString string;
        string.loadFromRes(STR_ID_VAPP_DTCNT_NUMBER_NEEDED);
        textInput->setWarningText(string);
        m_form->scrollItemToView(CSD_ITEM_ID_NUMBER, VCPFORM_SCROLL_TOP);
        return;
    }

    srv_dtcnt_store_prof_data_struct profInfo;
    srv_dtcnt_result_enum result;    
    profInfo.prof_type = SRV_DTCNT_BEARER_CSD;
    profInfo.prof_data = m_csdProfileSrvCntx;
    profInfo.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;

    // number
    VfxChar *number;
    VfxWChar *name;
    VFX_ALLOC_MEM(number, (SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN + 1), this);
    VFX_ALLOC_MEM(name, (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1) * ENCODING_LENGTH, this);
    mmi_wcs_to_asc((CHAR*)number, (WCHAR*)str);
    m_csdProfileSrvCntx->DialNumber = (U8*)number;

    // account name
    textInput = (VcpFormItemTextInput *)m_form->getItem(CSD_ITEM_ID_ACCOUNT_NAME);
    str = textInput->getTextBox()->getText();
    m_csdProfileSrvCntx->prof_common_header.AccountName = (U8*)str;

    // user name
    textInput = (VcpFormItemTextInput *)m_form->getItem(CSD_ITEM_ID_USERNAME);
    str = textInput->getTextBox()->getText();
    mmi_wcs_to_asc((CHAR*)m_csdProfileSrvCntx->prof_common_header.Auth_info.UserName, (WCHAR*)str);

    // password            
    textInput = (VcpFormItemTextInput *)m_form->getItem(CSD_ITEM_ID_PASSWORD);
    str = textInput->getTextBox()->getText();
    mmi_wcs_to_asc((CHAR*)m_csdProfileSrvCntx->prof_common_header.Auth_info.Passwd, (WCHAR*)str);

    // line_type
    m_csdProfileSrvCntx->DialType = (srv_dtcnt_prof_csd_dial_type_enum)m_lineType;

    // speed
    m_csdProfileSrvCntx->DataRate = (srv_dtcnt_prof_csd_rate_enum)m_speed;

    // sim, because after edit, the account will change to user define
    srv_dtcnt_sim_type_enum simType;
    simType = m_simType;
    //MMI_BOOL ret;
    //ret = srv_dtcnt_get_sim_preference(&simType);
    //MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_SIM_PREFERENCE, simType, ret);
    m_csdProfileSrvCntx->prof_common_header.sim_info = simType;

    // configure type
    if (m_settingType == VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD)
    {
        m_csdProfileSrvCntx->prof_common_header.acct_type = SRV_DTCNT_PROF_TYPE_USER_CONF;
    }

    // homepage
    str = m_csdContext->getHomePage();
    mmi_wcs_to_asc((CHAR*)m_csdProfileSrvCntx->prof_common_header.HomePage, (WCHAR*)str);

    // connection type
    if (m_csdContext->getConnectionType())
    {
        m_csdProfileSrvCntx->prof_common_header.px_service = SRV_DTCNT_PROF_PX_SRV_HTTP;
    }
    else
    {
        m_csdProfileSrvCntx->prof_common_header.px_service = SRV_DTCNT_PROF_PX_SRV_CO_WSP;
    }

    // use proxy
    m_csdProfileSrvCntx->prof_common_header.use_proxy = m_csdContext->getUseProxy();

    // proxy address and other ip
    str = m_csdContext->getProxyAddress();
    mmi_wcs_to_asc((CHAR*)m_csdProfileSrvCntx->prof_common_header.px_addr, (WCHAR*)str);
    VfxU8 *tempIP2, *tempIP3, *tempIP4, *tempIP5;
    //tempIP1 = m_csdContext->getProxyIp();
    tempIP2 = m_csdContext->getDnsPrimaryIp();
    tempIP3 = m_csdContext->getDnsSecondaryIp();
    tempIP4 = m_csdContext->getIp();
    tempIP5 = m_csdContext->getSubmaskIp();
    VfxS32 i;
    for (i = 0; i < MAX_PART_IP_ADDRESS; i++)
    {
        //m_csdProfileSrvCntx->prof_common_header.px_addr[i] = tempIP1[i];
        m_csdProfileSrvCntx->prof_common_header.PrimaryAddr[i] = tempIP2[i];
        m_csdProfileSrvCntx->prof_common_header.SecondaryAddr[i] = tempIP3[i];
        m_csdProfileSrvCntx->prof_common_header.StaicIPAddr[i] = tempIP4[i];
        m_csdProfileSrvCntx->prof_common_header.NetMask[i] = tempIP5[i];
    }

    // proxy port
    if (m_csdContext->getConnectionType())
    {
        if (m_csdContext->getUseProxy())
        {
            str = m_csdContext->getProxyPortStr();
            VfxChar temp[VAPP_DTCNT_MAX_PORT_LENGTH + 1];
            mmi_wcs_to_asc((CHAR*)temp, (WCHAR*)str);
            m_csdProfileSrvCntx->prof_common_header.px_port = (U16)atoi((char*)temp);
        }
        else
        {
            m_csdProfileSrvCntx->prof_common_header.px_port = 0;
        }
    }
    else
    {
        if (m_csdContext->getWapPortIndex())
        {
            m_csdProfileSrvCntx->prof_common_header.px_port = 9203;
        }
        else
        {
            m_csdProfileSrvCntx->prof_common_header.px_port = 9201;
        }
    }

    // proxy user name
    str = m_csdContext->getProxyUserName();
    mmi_wcs_to_asc((CHAR*)m_csdProfileSrvCntx->prof_common_header.px_authid, (WCHAR*)str);

    // proxy password            
    str = m_csdContext->getProxyPassword();
    mmi_wcs_to_asc((CHAR*)m_csdProfileSrvCntx->prof_common_header.px_authpw, (WCHAR*)str);

    // account name
    if (m_settingType == VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD)
    {
        // add first
        result = srv_dtcnt_store_add_prof(&profInfo, &m_acctId);                
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_ADD_PROFILE, m_acctId, result);                
        if (result == SRV_DTCNT_RESULT_SUCCESS)
        {
            VappDtcntDispItem acctItem;
            acctItem.setProfileId(m_acctId);
            acctItem.setConnectionType(m_csdContext->getConnectionType());
            acctItem.setSimInfo((VfxU8)simType);
            acctItem.setBearerType(DATA_ACCOUNT_BEARER_CSD);
            acctItem.setReadOnly(0);
            acctItem.setAccountType(m_csdProfileSrvCntx->prof_common_header.acct_type);
            VappDtcntDispItemList::addAcctItem(acctItem);
            MMI_BOOL ret;
            VfxU32 defaultId;
            ret = srv_dtcnt_get_default_account(m_simType, &defaultId);
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_DEFAULT_ACCOUNT, m_simType, defaultId, ret);
        }
        else if(result == SRV_DTCNT_RESULT_STORE_FULL)
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_INFO,
                (WCHAR*)GetString(STR_ID_VAPP_DTCNT_ACCT_MAX_NUM));
        }
    }
    else if (m_settingType == VAPP_DTCNT_ACCOUNT_SETTING_TYPE_EDIT)
    {                
        result = srv_dtcnt_store_update_prof(m_acctId, &profInfo);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_UPDATE_PROFILE, m_acctId, result);
        if (result == SRV_DTCNT_RESULT_SUCCESS)
        {
            VappDtcntDispItem acctItem;
            acctItem.setProfileId(m_acctId);
            acctItem.setConnectionType(m_csdContext->getConnectionType());
            acctItem.setSimInfo((VfxU8)simType);
            acctItem.setBearerType(DATA_ACCOUNT_BEARER_CSD);
            acctItem.setReadOnly(0);
            acctItem.setAccountType(m_csdProfileSrvCntx->prof_common_header.acct_type);
            VappDtcntDispItemList::updateAcctItem(acctItem);
        }
    }
    VFX_FREE_MEM(number); // free memory
    VFX_FREE_MEM(name); // free memory
    getMainScr()->popPage();
}


void VappDtcntCSDPage::onCSDToolBarTapped(
    VfxObject* sender,  // sender
    VfxId id            // id
    )
{
    switch (id)
    {
        case CSD_TOOLBAR_ID_SAVE :
            onBarSaveCommond();
            break;
        case CSD_TOOLBAR_ID_CANCEL:
            getMainScr()->popPage();
            break;
        default:
            break;
    }
}

void VappDtcntCSDPage::onFunctionBarTap(
    VfxObject *sender,  // [IN] sender object
    VfxId id            // [IN] Toolbar id
) 
{
    switch (id)
    {
        case ID_CSD_FUNCTIONBAR_PREV:
        {
            VfxId prevId = CSD_ITEM_ID_ACCOUNT_NAME;
            switch (m_currActiveId)
            {
                case CSD_ITEM_ID_ACCOUNT_NAME:
                    break;
                case CSD_ITEM_ID_NUMBER:
                    prevId = CSD_ITEM_ID_ACCOUNT_NAME;
                    break;
                case CSD_ITEM_ID_USERNAME:
                    prevId = CSD_ITEM_ID_NUMBER;
                    break;
                case CSD_ITEM_ID_PASSWORD:
                    prevId = CSD_ITEM_ID_USERNAME;
                    break;
            }
            VcpTextEditor *textEdit;
            VcpFormItemTextInput *textInput;
            textInput = (VcpFormItemTextInput *)m_form->getItem(prevId);
            textEdit = textInput->getTextBox();
            textEdit->activate();
            m_form->scrollItemToView(prevId, VCPFORM_SCROLL_BOTTOM, VFX_TRUE);
            break;
        }
        
        case ID_CSD_FUNCTIONBAR_NEXT:
        {
            VfxId nextId = CSD_ITEM_ID_PASSWORD;
            switch (m_currActiveId)
            {
                case CSD_ITEM_ID_ACCOUNT_NAME:
                    nextId = CSD_ITEM_ID_NUMBER;
                    break;
                case CSD_ITEM_ID_NUMBER:
                    nextId = CSD_ITEM_ID_USERNAME;
                    break;
                case CSD_ITEM_ID_USERNAME:
                    nextId = CSD_ITEM_ID_PASSWORD;
                    break;
                case CSD_ITEM_ID_PASSWORD:
                    break;
            }
            VcpTextEditor *textEdit;
            VcpFormItemTextInput *textInput;
            textInput = (VcpFormItemTextInput *)m_form->getItem(nextId);
            textEdit = textInput->getTextBox();
            textEdit->activate();
            m_form->scrollItemToView(nextId, VCPFORM_SCROLL_BOTTOM, VFX_TRUE);
            break;
        }
        
        case ID_CSD_FUNCTIONBAR_SAVE:
        {
            VcpFormItemTextInput* textInput;
            textInput = (VcpFormItemTextInput*)(m_form->getItem(m_currActiveId));
            textInput->getTextBox()->deactivate();
            onBarSaveCommond();
            break;
        }
        default:
            break;
    }
}

void VappDtcntCSDPage::onTextActivated(
    VcpTextEditor *sender,  // [IN] send object
    VfxBool  activated      // [IN] activate flag
)
{
    if (activated)
    {
        m_currActiveId = sender->getId();
        VcpFunctionBar *functionBar;
        functionBar = (VcpFunctionBar *)sender->getFunctionBar();
        if (m_currActiveId == CSD_ITEM_ID_ACCOUNT_NAME)
        {
            functionBar->setDisableItem(ID_CSD_FUNCTIONBAR_PREV, VFX_TRUE);
            functionBar->setDisableItem(ID_CSD_FUNCTIONBAR_NEXT, VFX_FALSE);
        } 
        else if (m_currActiveId == CSD_ITEM_ID_PASSWORD)
        {
            functionBar->setDisableItem(ID_CSD_FUNCTIONBAR_PREV, VFX_FALSE);
            functionBar->setDisableItem(ID_CSD_FUNCTIONBAR_NEXT, VFX_TRUE);
        }
        else
        {
            functionBar->setDisableItem(ID_CSD_FUNCTIONBAR_PREV, VFX_FALSE);
            functionBar->setDisableItem(ID_CSD_FUNCTIONBAR_NEXT, VFX_FALSE);
        }        
    }
}

void VappDtcntCSDPage::onLaunchCSDAdvancedSetting(
    VcpFormItemCell* sender, // Sender
    VfxId id // Sender id
    )
{
    VappDtcntAdvancedPage *advancedSettingPage;
    VFX_OBJ_CREATE_EX(advancedSettingPage, VappDtcntAdvancedPage, getMainScr(), (m_settingType, m_csdContext, m_simType, VFX_FALSE));
    getMainScr()->pushPage(0, advancedSettingPage);
}


void VappDtcntCSDPage::onBtnLineTypeTapped(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    // de-active editor
    textEditorState(m_form, m_currActiveId, VFX_FALSE);

    VcpSelectPopup *selectPopup;
    VFX_OBJ_CREATE(selectPopup, VcpSelectPopup, this);
    selectPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
    VfxWString str;
    str.loadFromRes(STR_ID_VAPP_DTCNT_DIAL_TYPE);
    selectPopup->setText(str);
    selectPopup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    
    if (m_lineType == 0)
    {
        str.loadFromRes(STR_ID_VAPP_DTCNT_ANALOGUE_STR);
        selectPopup->addItem(0, str, VFX_TRUE);
        str.loadFromRes(STR_ID_VAPP_DTCNT_ISDN_STR);
        selectPopup->addItem(1, str, VFX_FALSE);
    }
    else
    {
        str.loadFromRes(STR_ID_VAPP_DTCNT_ANALOGUE_STR);
        selectPopup->addItem(0, str, VFX_FALSE);
        str.loadFromRes(STR_ID_VAPP_DTCNT_ISDN_STR);
        selectPopup->addItem(1, str, VFX_TRUE);
    }

    selectPopup->m_signalPopupState.connect(this, &VappDtcntCSDPage::onSelectLineType);
    selectPopup->show(VFX_FALSE);
}

void VappDtcntCSDPage::onSelectLineType(
    VfxBasePopup *sender,        // popup
    VfxBasePopupStateEnum state  // state
)
{
    if(state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {        
        VcpSelectPopup *senderPopup;
        senderPopup = (VcpSelectPopup*)sender;
        VfxId i;
        i = senderPopup->getFirstSeletedId();
        if (i == m_lineType)
        {
            return; // not changed
        }

        VcpFormItemBigButton *btn;
        VfxWString str;
        btn =(VcpFormItemBigButton *)(m_form->getItem(CSD_ITEM_ID_LINETYPE));
        if (i == 0)
        {
            m_lineType = 0;
            str.loadFromRes(STR_ID_VAPP_DTCNT_ANALOGUE_STR);
            btn->setHintText(str);
        }
        else
        {
            m_lineType = 1;
            str.loadFromRes(STR_ID_VAPP_DTCNT_ISDN_STR);
            btn->setHintText(str);
        }
    }
}


void VappDtcntCSDPage::onBtnSpeedTypeTapped(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    // de-active editor
    VcpFormItemTextInput* textInput;
    VcpTextEditor *editor;
    textInput = (VcpFormItemTextInput*)(m_form->getItem(m_currActiveId));
    editor = textInput->getTextBox();
    editor->deactivate();
    
    VcpSelectPopup *selectPopup;
    VFX_OBJ_CREATE(selectPopup, VcpSelectPopup, this);
    selectPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
    VfxWString str;
    str.loadFromRes(STR_ID_VAPP_DTCNT_DATA_RATE);
    selectPopup->setText(str);
    selectPopup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

    str.loadFromRes(STR_ID_VAPP_DTCNT_RATE_STR_FOUR);
    VfxId i;
    i = STR_ID_VAPP_DTCNT_RATE_STR_FOUR - STR_ID_VAPP_DTCNT_RATE_STR_ZERO;
    if (m_speed == i)
    {
        selectPopup->addItem(i, str, VFX_TRUE);
    }
    else
    {
        selectPopup->addItem(i, str, VFX_FALSE);
    }
    
    for (i = 0; i < DATA_ACCOUNT_SPEED_RATE_TYPE_NUM - 1; i++)
    {
        // here need string id as enum
        str.loadFromRes(STR_ID_VAPP_DTCNT_RATE_STR_ZERO + i);
        if (m_speed == i)
        {
            selectPopup->addItem(i, str, VFX_TRUE);
        }
        else
        {
            selectPopup->addItem(i, str, VFX_FALSE);
        }
    }

    selectPopup->m_signalPopupState.connect(this, &VappDtcntCSDPage::onSelectSpeedType);
    selectPopup->show(VFX_FALSE);
}


void VappDtcntCSDPage::onSelectSpeedType(
    VfxBasePopup *sender,        // popup
    VfxBasePopupStateEnum state  // state
)
{
    if(state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {        
        VcpSelectPopup *senderPopup;
        senderPopup = (VcpSelectPopup*)sender;
        VfxId i;
        i = senderPopup->getFirstSeletedId();
        
        if (i == m_speed)
        {
            return; // not changed
        }

        VcpFormItemBigButton *btn;
        btn =(VcpFormItemBigButton *)(m_form->getItem(CSD_ITEM_ID_SPEED));
        VfxWString str;
        // here need string id as enum
        str.loadFromRes(STR_ID_VAPP_DTCNT_RATE_STR_ZERO + i);
        m_speed = i;            
        btn->setHintText(str);        
    }
}



void VappDtcntCSDPage::onBtnLaunchCSDAdvancedSetting(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    VappDtcntAdvancedPage *advancedSettingPage;
    VFX_OBJ_CREATE_EX(advancedSettingPage, VappDtcntAdvancedPage, getMainScr(), (m_settingType, m_csdContext, m_simType, VFX_FALSE));
    getMainScr()->pushPage(0, advancedSettingPage);
}


void VappDtcntCSDPage::loadCSDInitContext(
    VfxU32 acctId, // [IN] acctId
    srv_dtcnt_prof_csd_struct *srvCntx, // [OUT] 
    VappDtcntCSDAccountData *displayContext // [OUT]
    )
{
    // srvCntx is initialized out of this api
    VFX_ASSERT(srvCntx);

    srv_dtcnt_result_enum result;
    srv_dtcnt_store_prof_data_struct profInfo;
    profInfo.prof_type = SRV_DTCNT_BEARER_CSD;
    profInfo.prof_data = srvCntx;
    profInfo.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
    result =  srv_dtcnt_store_qry_prof(acctId, &profInfo);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_PROFILE, acctId, result);

    VfxWChar *str; // use the max length to allow memory, homepage is the max type
    VFX_ALLOC_MEM(str, (MAX_ADDRESS_NAME_LEN) * sizeof(VfxWChar), this);

    // account name
    displayContext->setDataAccountName((VfxWChar*)srvCntx->prof_common_header.AccountName);

    // dial number
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)srvCntx->DialNumber);
    displayContext->setDialNumber((VfxWChar*)str);

    // user name
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)srvCntx->prof_common_header.Auth_info.UserName);
    displayContext->setUserName((VfxWChar*)str);

    // password
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)srvCntx->prof_common_header.Auth_info.Passwd);
    displayContext->setPassword((VfxWChar*)str);

    // LineType
    displayContext->setLineType((VfxU8)srvCntx->DialType);

    // Speed
    displayContext->setSpeed((VfxU8)srvCntx->DataRate);

    // homepage
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)srvCntx->prof_common_header.HomePage);
    displayContext->setHomePage((VfxWChar*)str);

    // connection type
    if (srvCntx->prof_common_header.px_service == SRV_DTCNT_PROF_PX_SRV_CL_WSP ||
        srvCntx->prof_common_header.px_service == SRV_DTCNT_PROF_PX_SRV_CO_WSP ||
        srvCntx->prof_common_header.px_service == SRV_DTCNT_PROF_PX_SRV_CL_SEC_WSP ||
        srvCntx->prof_common_header.px_service == SRV_DTCNT_PROF_PX_SRV_CO_SEC_WSP ||
        srvCntx->prof_common_header.px_service == SRV_DTCNT_PROF_PX_SRV_CL_SEC_WTA ||
        srvCntx->prof_common_header.px_service == SRV_DTCNT_PROF_PX_SRV_CO_SEC_WTA)
    {
        displayContext->setConnectionType(0);
    }
    else    
    {
        displayContext->setConnectionType(1);
    }

    // proxy
    if (srvCntx->prof_common_header.use_proxy)
    {
        displayContext->setUseProxy(1); 
	mmi_asc_to_wcs((WCHAR*)str, (CHAR*)srvCntx->prof_common_header.px_addr);
	displayContext->setProxyAddress((VfxWChar*)str);
        displayContext->setProxyPort(srvCntx->prof_common_header.px_port);
        //displayContext->setProxyIp(srvCntx->prof_common_header.px_addr);
        mmi_asc_to_wcs((WCHAR*)str, (CHAR*)srvCntx->prof_common_header.px_authid);
        displayContext->setProxyUserName((VfxWChar*)str);
        mmi_asc_to_wcs((WCHAR*)str, (CHAR*)srvCntx->prof_common_header.px_authpw);
        displayContext->setProxyPassword((VfxWChar*)str);

        displayContext->setWapPortIndex(0);

        if (!displayContext->getConnectionType())
        {
            if (srvCntx->prof_common_header.px_port == 9203)
            {
                displayContext->setWapPortIndex(1);
            }
        }

        // port string
        char strDigist[VAPP_DTCNT_MAX_PORT_LENGTH + 1];
        sprintf(strDigist, "%d", srvCntx->prof_common_header.px_port);
        mmi_asc_to_wcs((WCHAR*)str, (CHAR*)strDigist);
        displayContext->setProxyPortStr((VfxWChar*)str);
    }
    else
    {
        displayContext->setUseProxy(0);
        // port string
        //char strDigist[VAPP_DTCNT_MAX_PORT_LENGTH + 1];
        //sprintf(strDigist, "%d", 0);
        //mmi_asc_to_wcs((WCHAR*)str, (CHAR*)strDigist);
        displayContext->setProxyPortStr((VfxWChar*)L"");
    }
    
    // others
    displayContext->setDnsPrimaryIp(srvCntx->prof_common_header.PrimaryAddr);
    displayContext->setDnsSecondaryIp(srvCntx->prof_common_header.SecondaryAddr);
    displayContext->setIp(srvCntx->prof_common_header.StaicIPAddr);
    displayContext->setSubmaskIp(srvCntx->prof_common_header.NetMask);

    // need convert ip to display string
    // need convert ip to display string
    VfxChar ipStr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN * 4];
    VfxU8 *ip;
    ip = displayContext->getDnsPrimaryIp();  
    sprintf(ipStr, "%d.%d.%d.%d", ip[0],ip[1],ip[2],ip[3]);
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)ipStr);
    displayContext->setDnsPrimaryIpDisplay((VfxWChar*)str);

    ip = displayContext->getDnsSecondaryIp();  
    sprintf(ipStr, "%d.%d.%d.%d", ip[0],ip[1],ip[2],ip[3]);
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)ipStr);
    displayContext->setDnsSecondaryIpDisplay((VfxWChar*)str);

    ip = displayContext->getIp();  
    sprintf(ipStr, "%d.%d.%d.%d", ip[0],ip[1],ip[2],ip[3]);
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)ipStr);
    displayContext->setIpDisplay((VfxWChar*)str);

    ip = displayContext->getSubmaskIp();  
    sprintf(ipStr, "%d.%d.%d.%d", ip[0],ip[1],ip[2],ip[3]);
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)ipStr);
    displayContext->setSubmaskIpDisplay((VfxWChar*)str);
/*
    ip = displayContext->getProxyIp();  
    sprintf(ipStr, "%d.%d.%d.%d", ip[0],ip[1],ip[2],ip[3]);
    mmi_asc_to_wcs((WCHAR*)str, (CHAR*)ipStr);
    displayContext->setProxyIpDisplay((VfxWChar*)str);
*/
    VFX_FREE_MEM(str);
}

void VappDtcntCSDPage::onSimChangeEvt(VfxBool flag, mmi_sim_enum sim)
{
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__

	VfxU32 simIndex = 0;
	simIndex = mmi_frm_sim_to_index(sim);
	
	if(VFX_FALSE == flag)
	{
		if(simIndex == (VfxU32)(m_simType - 1))
		{
			getMainScr()->closePage(getId());
		}
	}
#endif
}


void VappDtcntCSDPage::onDeinit()
{
    if (m_csdProfileSrvCntx)
    {
        VFX_FREE_MEM(m_csdProfileSrvCntx);
    }
    if (m_detail)
    {
        VFX_FREE_MEM(m_detail);
    }
    VappDtcntDispItemList::setCurrEditProfileId(CBM_INVALID_NWK_ACCT_ID);
    VfxPage::onDeinit();
}
#endif
/***************************************************************************** 
 * Class VappDtcntAdvancedPage
 *****************************************************************************/

void VappDtcntAdvancedPage::onInit()
{
    VfxPage::onInit();
    m_connectionType = m_commonContext->getConnectionType();
    m_useProxy = m_commonContext->getUseProxy();
    m_wapPortIndex = m_commonContext->getWapPortIndex();

    // display titleBar
    if (m_isGPRS)
    {
        VfxU32 gprsResId[3] = {STR_ID_VAPP_DTCNT_ADD_GPRS, STR_ID_VAPP_DTCNT_EDIT_PS_ACCOUNT, STR_ID_VAPP_DTCNT_VIEW_PS_ACCOUNT};
        vapp_dtcnt_set_titlebar(gprsResId[m_settingType], this);
    }
#ifdef __TCPIP_OVER_CSD__
    else
    {
        VfxU32 csdResId[3] = {STR_ID_VAPP_DTCNT_ADD_CSD, STR_ID_VAPP_DTCNT_EDIT_CSD_ACCOUNT, STR_ID_VAPP_DTCNT_VIEW_CSD_ACCOUNT};
        vapp_dtcnt_set_titlebar(csdResId[m_settingType], this);
    } 
 #endif           
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    if(VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD == m_settingType || VAPP_DTCNT_ACCOUNT_SETTING_TYPE_EDIT == m_settingType)
    {
        VcpToolBar *toolBar;
        VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
        toolBar->addItem(ADVANCED_SETTING_TOOLBAR_ID_OK, STR_GLOBAL_OK, VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
        toolBar->addItem(ADVANCED_SETTING_TOOLBAR_ID_CANCEL, STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
        toolBar->m_signalButtonTap.connect(this, &VappDtcntAdvancedPage::onAdvancedToolBarTapped);
        setBottomBar(toolBar);
        editAdvancePage();
    }
    else
    {
        viewAdvancePage();
    }
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__
    VFX_OBJ_GET_INSTANCE(VappDtcntSimAvailableListener)->m_signalSimChangedEvent.connect(this, &VappDtcntAdvancedPage::onSimChangeEvt);
#endif
}

void VappDtcntAdvancedPage::createTextInput(VfxU32 resId, VfxWChar *text, VfxS32 maxLen, 
                                                VfxU32 inputType, VfxId itemId, VfxBool isInsert)
{
    VcpFormItemTextInput *textInput = NULL;
    VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
    textInput->setLabelPosition(VCPFORM_TOP_LEFT);
    textInput->setLabelText(resId);
    if(IMM_INPUT_TYPE_DECIMAL_NUMERIC == inputType)
    {
        VsrvInputBinding inputBindingIP(inputType, IME_SKIP_DECIMAL_CHECK, 0, textInput->getTextBox()->m_editing);
        textInput->getTextBox()->setIME(inputBindingIP);
    }
    else
    {
        textInput->getTextBox()->setIME(inputType);
    }
    textInput->getTextBox()->setText(text, maxLen);
    textInput->getTextBox()->m_signalActivated.connect(this, &VappDtcntAdvancedPage::onTextActivated);
    if(IMM_INPUT_TYPE_NUMERIC == inputType)
    {
        textInput->getTextBox()->m_signalBeforeChange.connect(this, &VappDtcntAdvancedPage::onTextInsert);
    }
    textInput->getTextBox()->setFunctionBar((VfxFrame*)m_functionBar, VFX_FALSE);
    textInput->getTextBox()->setId(itemId);
    if(isInsert)
    {
        m_form->insertItem(textInput, ADVANCED_SETTING_ITEM_ID_PROXY_USERNAME, itemId);
    }
    else
    {
        m_form->addItem(textInput, itemId);
    }
} 


void VappDtcntAdvancedPage::editAdvancePage()
{
    // form
    VFX_OBJ_CREATE(m_functionBar, VcpFunctionBar, this);
    m_functionBar->addItem((VfxResId)STR_GLOBAL_PREV, (VfxId)ID_ADVANCED_FUNCTIONBAR_PREV);
    m_functionBar->addItem((VfxResId)STR_GLOBAL_NEXT, (VfxId)ID_ADVANCED_FUNCTIONBAR_NEXT);
    m_functionBar->addItem((VfxResId)STR_GLOBAL_OK, (VfxId)ID_ADVANCED_FUNCTIONBAR_OK);
    m_functionBar->setItemSpecial(ID_ADVANCED_FUNCTIONBAR_OK);
    m_functionBar->m_signalButtonTap.connect(this, &VappDtcntAdvancedPage::onFunctionBarTap);
    createTextInput(STR_ID_VAPP_DTCNT_HOME_PAGE, m_commonContext->getHomePage(), MAX_ADDRESS_NAME_LEN - 1,
    IMM_INPUT_TYPE_URL, ADVANCED_SETTING_ITEM_ID_HOMEPAGE, VFX_FALSE);
    VcpFormItemBigButton *btn;
    VFX_OBJ_CREATE(btn, VcpFormItemBigButton, m_form);
    btn->setButtonText(STR_ID_VAPP_DTCNT_CONNECTION_TYPE);
    if (m_connectionType == 1)
    {
        btn->setHintText(STR_ID_VAPP_DTCNT_CONNECTION_TYPE_HTTP);
    }
    else
    {
        btn->setHintText(STR_ID_VAPP_DTCNT_CONNECTION_TYPE_WAP);   
    }
    btn->getButton()->m_signalClicked.connect(this, &VappDtcntAdvancedPage::onBtnConnectionTypeTapped);
    m_form->addItem(btn, ADVANCED_SETTING_ITEM_ID_CONNTYPE);

    VcpFormItemCaption *caption;
    VFX_OBJ_CREATE(caption, VcpFormItemCaption, m_form);
    caption->setText(STR_ID_VAPP_DTCNT_GROUP_PROXY);
    caption->setStyle(VCPFORM_STYLE2);
    m_form->addItem(caption, ADVANCED_SETTING_ITEM_ID_PROXY_CAPTION);

    VcpFormItemSwitchCell *switchCell;
    VFX_OBJ_CREATE(switchCell, VcpFormItemSwitchCell, m_form);
    if (m_useProxy)
    {
        switchCell->setSwitchStatus(VFX_TRUE);
    }
    else
    {
        switchCell->setSwitchStatus(VFX_FALSE);
    }
    switchCell->setMainText(STR_ID_VAPP_DTCNT_USE_PROXY);
    switchCell->setIsTappable(VFX_FALSE);
    switchCell->m_signalSwitchChangeReq.connect(this, &VappDtcntAdvancedPage::onProxySwitchChange);
    m_form->addItem(switchCell, ADVANCED_SETTING_ITEM_ID_PROXY_SWITCH);
    createTextInput(STR_ID_VAPP_DTCNT_PROXY_ADDRESS, m_commonContext->getProxyAddress(), SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN,
                    IMM_INPUT_TYPE_URL, ADVANCED_SETTING_ITEM_ID_PROXY_PROXY_ADDRESS, VFX_FALSE);
    // wap or http
    if (m_connectionType == 1)
    {
        createTextInput(STR_ID_VAPP_DTCNT_PROXY_PORT, m_commonContext->getProxyPortStr(), VAPP_DTCNT_MAX_PORT_LENGTH,
        IMM_INPUT_TYPE_NUMERIC, ADVANCED_SETTING_ITEM_ID_PROXY_PORT, VFX_FALSE);
    }
    else
    {
        VFX_OBJ_CREATE(btn, VcpFormItemBigButton, m_form);
        btn->setButtonText(STR_ID_VAPP_DTCNT_PROXY_PORT);
        if (m_wapPortIndex == 1)
        {
            btn->setHintText(STR_ID_VAPP_DTCNT_GPRS_CHAP_AUTH);
        }
        else
        {
            btn->setHintText(STR_ID_VAPP_DTCNT_GPRS_PAP_AUTH);
        }
        btn->getButton()->m_signalClicked.connect(this, &VappDtcntAdvancedPage::onBtnWapProxyPortTypeTapped);
        m_form->addItem(btn, ADVANCED_SETTING_ITEM_ID_PROXY_PORT);
    }
    createTextInput(STR_ID_VAPP_DTCNT_PROXY_USERNAME, m_commonContext->getProxyUserName(), SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN,
                     IMM_INPUT_TYPE_ASCII_CHAR, ADVANCED_SETTING_ITEM_ID_PROXY_USERNAME, VFX_FALSE);
    createTextInput(STR_ID_VAPP_DTCNT_PROXY_PASS_WORD, m_commonContext->getProxyPassword(), SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN,
                    IMM_INPUT_TYPE_ASCII_PASSWORD, ADVANCED_SETTING_ITEM_ID_PROXY_PASSWORD, VFX_FALSE);
    setItemState();

    VFX_OBJ_CREATE(caption, VcpFormItemCaption, m_form);
    caption->setText(STR_ID_VAPP_DTCNT_GROUP_OTHERS);
    caption->setStyle(VCPFORM_STYLE2);
    m_form->addItem(caption, ADVANCED_SETTING_ITEM_ID_OTHERS_CAPTION);
    createTextInput(STR_ID_VAPP_DTCNT_DNS_ADDRESS1, m_commonContext->getDnsPrimaryIpDisplay(), SRV_DTCNT_PROF_MAX_IP_ADDR_LEN * 4 - 1,
                    IMM_INPUT_TYPE_DECIMAL_NUMERIC, ADVANCED_SETTING_ITEM_ID_OTHERS_DNS1, VFX_FALSE);
    createTextInput(STR_ID_VAPP_DTCNT_DNS_ADDRESS2, m_commonContext->getDnsSecondaryIpDisplay(), SRV_DTCNT_PROF_MAX_IP_ADDR_LEN * 4 - 1, 
                    IMM_INPUT_TYPE_DECIMAL_NUMERIC, ADVANCED_SETTING_ITEM_ID_OTHERS_DNS2, VFX_FALSE);
    createTextInput(STR_ID_VAPP_DTCNT_IP_ADDRESS, m_commonContext->getIpDisplay(), SRV_DTCNT_PROF_MAX_IP_ADDR_LEN * 4 - 1, 
                    IMM_INPUT_TYPE_DECIMAL_NUMERIC, ADVANCED_SETTING_ITEM_ID_OTHERS_IP, VFX_FALSE);
    createTextInput(STR_ID_VAPP_DTCNT_SUBNET_MASK, m_commonContext->getSubmaskIpDisplay(), SRV_DTCNT_PROF_MAX_IP_ADDR_LEN * 4 - 1, 
                    IMM_INPUT_TYPE_DECIMAL_NUMERIC, ADVANCED_SETTING_ITEM_ID_OTHERS_SUBNET, VFX_FALSE);
}

void VappDtcntAdvancedPage::viewAdvancePage()
{
    VfxWString str;
    VcpFormItemCustomFrame *customFrame;            
    VcpFormItemCaption *caption;
    VfxS32 xPos, yPos;
    xPos = VAPP_DTCNT_DETAIL_GAP_LEFT;
    yPos = VAPP_DTCNT_DETAIL_GAP_TOP;    

    // part 1
    VFX_ALLOC_MEM(m_detailBase, VAPP_DTCNT_ADVANCED_DETAIL_BASE_SIZE, this);
    m_detailBase[0] = 0;
    m_detailBase[1] = 0;

    VcpTextView *detailView;
    VFX_OBJ_CREATE(detailView, VcpTextView, m_form); // use form as parent
    detailView->setPos(VfxPoint(xPos, yPos));
    detailView->setBounds(VfxRect(0, 0, getSize().width - VAPP_DTCNT_DETAIL_GAP_LEFT - VAPP_DTCNT_DETAIL_GAP_RIGHT, 0));
    detailView->setAutoResized(VFX_TRUE);
    detailView->enableVerticalScrollIndicator(VFX_FALSE);

    detailView->setText(m_detailBase, VFX_TRUE);

    VfxS32 maxLen;
    maxLen = (VAPP_DTCNT_ADVANCED_DETAIL_BASE_SIZE / 2) - 1;

    // homepage
    str.loadFromRes(STR_ID_VAPP_DTCNT_HOME_PAGE);
    detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
    detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
    str.loadFromMem(m_commonContext->getHomePage());
    str += VFX_WSTR_MEM((VfxWChar*)L"\n");
    detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);

    // conn_type
    str.loadFromRes(STR_ID_VAPP_DTCNT_CONNECTION_TYPE);
    detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
    detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
    if (m_connectionType == 1)
    {
        str.loadFromRes(STR_ID_VAPP_DTCNT_CONNECTION_TYPE_HTTP);
    }
    else
    {
        str.loadFromRes(STR_ID_VAPP_DTCNT_CONNECTION_TYPE_WAP);
    }
    str += VFX_WSTR_MEM((VfxWChar*)L"\n");
    detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);

    detailView->forceUpdate();

    VFX_OBJ_CREATE(customFrame, VcpFormItemCustomFrame, this); // use this as parent
    customFrame->attachCustomFrame((VfxFrame*)detailView);
    m_form->addItem(customFrame, ADVANCED_DETAIL_ID_BASE); // need to define id here

    // part2
    if (m_useProxy)
    {
        // caption
        VFX_OBJ_CREATE(caption, VcpFormItemCaption, m_form);
        str.loadFromRes(STR_ID_VAPP_DTCNT_GROUP_PROXY);
        caption->setText(str);
        caption->setStyle(VCPFORM_STYLE2);
        m_form->addItem(caption, ADVANCED_DETAIL_ID_PROXY_CAPTION);

        VFX_ALLOC_MEM(m_detailProxy, VAPP_DTCNT_ADVANCED_DETAIL_PROXY_SIZE, this);
        m_detailProxy[0] = 0;
        m_detailProxy[1] = 0;

        VFX_OBJ_CREATE(detailView, VcpTextView, m_form); // use form as parent
        detailView->setPos(VfxPoint(xPos, yPos));
        detailView->setBounds(VfxRect(0, 0, getSize().width - VAPP_DTCNT_DETAIL_GAP_LEFT - VAPP_DTCNT_DETAIL_GAP_RIGHT, 0));
        detailView->setAutoResized(VFX_TRUE);
        detailView->enableVerticalScrollIndicator(VFX_FALSE);

        detailView->setText(m_detailProxy, VFX_TRUE);

        maxLen = (VAPP_DTCNT_ADVANCED_DETAIL_PROXY_SIZE / 2) - 1;

        // proxy address
        str.loadFromRes(STR_ID_VAPP_DTCNT_PROXY_ADDRESS);
        detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
        detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
        str.loadFromMem(m_commonContext->getProxyAddress());
        str += VFX_WSTR_MEM((VfxWChar*)L"\n");
        detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);

        // proxy port
        str.loadFromRes(STR_ID_VAPP_DTCNT_PROXY_PORT);
        detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
        detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
        if (m_connectionType)
        {    
            str.loadFromMem(m_commonContext->getProxyPortStr());
            str += VFX_WSTR_MEM((VfxWChar*)L"\n");
            detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);
        }
        else
        {
            if (m_wapPortIndex)
            {
                str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_CHAP_AUTH);
            }
            else
            {
                str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_PAP_AUTH);
            }
            str += VFX_WSTR_MEM((VfxWChar*)L"\n");
            detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);
        }

        // proxy user name                
        str.loadFromRes(STR_ID_VAPP_DTCNT_PROXY_USERNAME);
        detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
        detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
        str.loadFromMem(m_commonContext->getProxyUserName());
        str += VFX_WSTR_MEM((VfxWChar*)L"\n");
        detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);

        // proxy password
        str.loadFromRes(STR_ID_VAPP_DTCNT_PROXY_PASS_WORD);
        detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
        detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
        str.loadFromMem(m_commonContext->getProxyPassword());
        str += VFX_WSTR_MEM((VfxWChar*)L"\n");
        detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);

        detailView->forceUpdate();

        VFX_OBJ_CREATE(customFrame, VcpFormItemCustomFrame, this); // use this as parent
        customFrame->attachCustomFrame((VfxFrame*)detailView);
        m_form->addItem(customFrame, ADVANCED_DETAIL_ID_PROXY); // need to define id here
    }

    // part3

    // caption
    VFX_OBJ_CREATE(caption, VcpFormItemCaption, m_form);
    str.loadFromRes(STR_ID_VAPP_DTCNT_GROUP_OTHERS);
    caption->setText(str);
    caption->setStyle(VCPFORM_STYLE2);
    m_form->addItem(caption, ADVANCED_DETAIL_ID_OTHERS_CAPTION);

    VFX_ALLOC_MEM(m_detailOthers, VAPP_DTCNT_ADVANCED_DETAIL_OTHERS_SIZE, this);
    m_detailOthers[0] = 0;
    m_detailOthers[1] = 0;

    VFX_OBJ_CREATE(detailView, VcpTextView, m_form); // use form as parent
    detailView->setPos(VfxPoint(xPos, yPos));
    detailView->setBounds(VfxRect(0, 0, getSize().width - VAPP_DTCNT_DETAIL_GAP_LEFT - VAPP_DTCNT_DETAIL_GAP_RIGHT, 0));
    detailView->setAutoResized(VFX_TRUE);
    detailView->enableVerticalScrollIndicator(VFX_FALSE);

    detailView->setText(m_detailOthers, VFX_TRUE);

    maxLen = (VAPP_DTCNT_ADVANCED_DETAIL_OTHERS_SIZE / 2) - 1;

    // primary dns
    str.loadFromRes(STR_ID_VAPP_DTCNT_DNS_ADDRESS1);
    detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
    detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
    str = VFX_WSTR_MEM(m_commonContext->getDnsPrimaryIpDisplay());
    str += VFX_WSTR_MEM((VfxWChar*)L"\n");
    detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);

    str.loadFromRes(STR_ID_VAPP_DTCNT_DNS_ADDRESS2);
    detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
    detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
    str = VFX_WSTR_MEM(m_commonContext->getDnsSecondaryIpDisplay());
    str += VFX_WSTR_MEM((VfxWChar*)L"\n");
    detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);

    str.loadFromRes(STR_ID_VAPP_DTCNT_IP_ADDRESS);
    detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
    detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
    str = VFX_WSTR_MEM(m_commonContext->getIpDisplay());
    str += VFX_WSTR_MEM((VfxWChar*)L"\n");
    detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);

    str.loadFromRes(STR_ID_VAPP_DTCNT_SUBNET_MASK);
    detailView->addDetail(str, VCP_TEXT_DETAIL_TITLE, maxLen);
    detailView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, maxLen);
    str = VFX_WSTR_MEM(m_commonContext->getSubmaskIpDisplay());
    str += VFX_WSTR_MEM((VfxWChar*)L"\n");
    detailView->addDetail(str, VCP_TEXT_DETAIL_CONTENT, maxLen);

    detailView->forceUpdate();

    VFX_OBJ_CREATE(customFrame, VcpFormItemCustomFrame, this); // use this as parent
    customFrame->attachCustomFrame((VfxFrame*)detailView);
    m_form->addItem(customFrame, ADVANCED_DETAIL_ID_OTHERS); // need to define id here
}


void VappDtcntAdvancedPage::onBarOKCommond()
{
    // check validity, and save to display context if valid
    VfxBool errorFlag = VFX_FALSE;
    // check homepage
    VcpFormItemTextInput *textInput;
    textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_HOMEPAGE);
    VfxWChar *strHomepage, *tempStrHomepage, *strProxyAddress, *strProxyPort = NULL;
    VfxWChar *strDns1Address, *strDns2Address, *strIpAddress, *strSubnetAddress;
    char *strproxyAscii;
    VfxU8 primaryDNS[MAX_PART_IP_ADDRESS];
    VfxU8 secondaryDNS[MAX_PART_IP_ADDRESS], ip[MAX_PART_IP_ADDRESS], subnetMask[MAX_PART_IP_ADDRESS];
    tempStrHomepage = textInput->getTextBox()->getText();
    VFX_ALLOC_MEM(strHomepage, MAX_ADDRESS_NAME_LEN * sizeof(VfxWChar), this);
    mmi_wcscpy(strHomepage, tempStrHomepage);
    VfxWString string;
    VfxBool emptyErrorStrHomepage = VFX_FALSE;
    VfxBool emptyErrorStrProxyAddr = VFX_FALSE;
    VfxBool emptyErrorStrProxyPort = VFX_FALSE;
    VfxBool emptyErrorStrDNS1 = VFX_FALSE;
    VfxBool emptyErrorStrDNS2 = VFX_FALSE;
    VfxBool emptyErrorStrIP = VFX_FALSE;
    VfxBool emptyErrorStrSubnet = VFX_FALSE;
    VfxBool focus = VFX_FALSE; // use to get the first error item
    VfxId focusItemId = ADVANCED_SETTING_ITEM_ID_HOMEPAGE;

    if (checkUrlValidity(strHomepage, VFX_TRUE) != 0)
    {
        errorFlag = VFX_TRUE;
        string.loadFromRes(STR_ID_VAPP_DTCNT_INVALID_HOMEPAGE);
        textInput->setWarningText(string);
        if (!focus)
        {
            focus = VFX_TRUE;
            focusItemId = ADVANCED_SETTING_ITEM_ID_HOMEPAGE;
        }
    }
    else
    {
        emptyErrorStrHomepage = VFX_TRUE;
    }
    // check proxy address
    // check proxy port
    textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PROXY_ADDRESS);
    strProxyAddress = textInput->getTextBox()->getText();

    if (m_connectionType)
    {
        textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PORT);
        strProxyPort = textInput->getTextBox()->getText();
    }

    // get proxy address
    //VfxBool flag;
    //flag = checkIpAddressValidity(strProxyAddress, proxyIp, VFX_FALSE, VFX_FALSE);
    
    if (m_useProxy)
    {
    	VFX_ALLOC_MEM(strproxyAscii, (SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN+1)* sizeof(VfxWChar), this);
	mmi_wcs_to_asc(strproxyAscii, strProxyAddress);
        textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PROXY_ADDRESS);
        if (applib_url_is_valid_ext(strproxyAscii, KAL_TRUE, KAL_FALSE))
        {
            errorFlag = VFX_TRUE;
            string.loadFromRes(STR_ID_VAPP_DTCNT_INVALID_PROXY_ADDRESS);
            textInput->setWarningText(string);
            if (!focus)
            {
                focus = VFX_TRUE;
                focusItemId = ADVANCED_SETTING_ITEM_ID_PROXY_PROXY_ADDRESS;
            }
        }
        else
        {
            emptyErrorStrProxyAddr = VFX_TRUE;
        }
	VFX_FREE_MEM(strproxyAscii);

        if (m_connectionType)
        {
            textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PORT);
            if (!checkProxyPortValidity(strProxyPort))
            {
                errorFlag = VFX_TRUE;
                string.loadFromRes(STR_ID_VAPP_DTCNT_INVALID_PROXY_PORT);
                textInput->setWarningText(string);
                if (!focus)
                {
                    focus = VFX_TRUE;
                    focusItemId = ADVANCED_SETTING_ITEM_ID_PROXY_PORT;
                }
            }
            else
            {
                emptyErrorStrProxyPort = VFX_TRUE;
            }
        }
    }
    // check other ip
    textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_OTHERS_DNS1);
    strDns1Address = textInput->getTextBox()->getText();
    if (!checkIpAddressValidity(strDns1Address, primaryDNS, VFX_TRUE, VFX_TRUE))
    {
        errorFlag = VFX_TRUE;
        string.loadFromRes(STR_ID_VAPP_DTCNT_INVALID_PRIMARY_DNS);
        textInput->setWarningText(string);
        if (!focus)
        {
            focus = VFX_TRUE;
            focusItemId = ADVANCED_SETTING_ITEM_ID_OTHERS_DNS1;
        }
    }
    else
    {
        emptyErrorStrDNS1 = VFX_TRUE;
    }

    textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_OTHERS_DNS2);
    strDns2Address = textInput->getTextBox()->getText();
    if (!checkIpAddressValidity(strDns2Address, secondaryDNS, VFX_TRUE, VFX_TRUE))
    {
        errorFlag = VFX_TRUE;
        string.loadFromRes(STR_ID_VAPP_DTCNT_INVALID_SECONDARY_DNS);
        textInput->setWarningText(string);
        if (!focus)
        {
            focus = VFX_TRUE;
            focusItemId = ADVANCED_SETTING_ITEM_ID_OTHERS_DNS2;
        }
    }
    else
    {
        emptyErrorStrDNS2 = VFX_TRUE;
    }

    textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_OTHERS_IP);
    strIpAddress = textInput->getTextBox()->getText();
    if (!checkIpAddressValidity(strIpAddress, ip, VFX_TRUE, VFX_TRUE))
    {
        errorFlag = VFX_TRUE;
        string.loadFromRes(STR_ID_VAPP_DTCNT_INVALID_IP_ADDRESS);
        textInput->setWarningText(string);
        if (!focus)
        {
            focus = VFX_TRUE;
            focusItemId = ADVANCED_SETTING_ITEM_ID_OTHERS_IP;
        }
    }
    else
    {
        emptyErrorStrIP = VFX_TRUE;
    }

    textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_OTHERS_SUBNET);
    strSubnetAddress = textInput->getTextBox()->getText();
    if (!checkIpAddressValidity(strSubnetAddress, subnetMask, VFX_TRUE, VFX_TRUE))
    {
        errorFlag = VFX_TRUE;
        string.loadFromRes(STR_ID_VAPP_DTCNT_INVALID_SUBNET_MASK);
        textInput->setWarningText(string);
        if (!focus)
        {
            focus = VFX_TRUE;
            focusItemId = ADVANCED_SETTING_ITEM_ID_OTHERS_SUBNET;
        }
    }
    else
    {
        emptyErrorStrSubnet = VFX_TRUE;
    }

    if (errorFlag)
    {
        if (emptyErrorStrHomepage)
        {
            textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_HOMEPAGE);
            textInput->setWarningText(VFX_WSTR_EMPTY);
        }
        if (emptyErrorStrProxyAddr)
        {
            textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PROXY_ADDRESS);
            textInput->setWarningText(VFX_WSTR_EMPTY);
        }
        if (emptyErrorStrProxyPort)
        {
            textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PORT);
            textInput->setWarningText(VFX_WSTR_EMPTY);
        }
        if (emptyErrorStrDNS1)
        {
            textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_OTHERS_DNS1);
            textInput->setWarningText(VFX_WSTR_EMPTY);
        }
        if (emptyErrorStrDNS2)
        {
            textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_OTHERS_DNS2);
            textInput->setWarningText(VFX_WSTR_EMPTY);
        }
        if (emptyErrorStrIP)
        {
            textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_OTHERS_IP);
            textInput->setWarningText(VFX_WSTR_EMPTY);
        }
        if (emptyErrorStrSubnet)
        {
            textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_OTHERS_SUBNET);
            textInput->setWarningText(VFX_WSTR_EMPTY);
        }
        m_form->scrollItemToView(focusItemId, VCPFORM_SCROLL_TOP);
        VFX_FREE_MEM(strHomepage);
        return;
    }

    // save value to context
    m_commonContext->setHomePage(strHomepage);
    m_commonContext->setConnectionType(m_connectionType);
    m_commonContext->setUseProxy(m_useProxy);
    //m_commonContext->setProxyIpDisplay(strProxyAddress);
    m_commonContext->setProxyAddress(strProxyAddress);
/*
    if (!m_useProxy)
    {
        memset(proxyIp, 0x00, (sizeof(VfxU8) * MAX_PART_IP_ADDRESS));
    }
    m_commonContext->setProxyIp(proxyIp);
    */
    if (m_connectionType)
    {
        m_commonContext->setProxyPortStr(strProxyPort);
    }
    else
    {
        m_commonContext->setWapPortIndex(m_wapPortIndex);
    }
    VfxWChar *str;
    textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_USERNAME);
    str = textInput->getTextBox()->getText();
    m_commonContext->setProxyUserName(str);

    textInput = (VcpFormItemTextInput *)m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PASSWORD);
    str = textInput->getTextBox()->getText();
    m_commonContext->setProxyPassword(str);

    m_commonContext->setDnsPrimaryIpDisplay(strDns1Address);             
    m_commonContext->setDnsSecondaryIpDisplay(strDns2Address);
    m_commonContext->setIpDisplay(strIpAddress);
    m_commonContext->setSubmaskIpDisplay(strSubnetAddress);

    m_commonContext->setDnsPrimaryIp(primaryDNS);
    m_commonContext->setDnsSecondaryIp(secondaryDNS);
    m_commonContext->setIp(ip);
    m_commonContext->setSubmaskIp(subnetMask);
    VFX_FREE_MEM(strHomepage);
    getMainScr()->popPage();
}


void VappDtcntAdvancedPage::onAdvancedToolBarTapped(
        VfxObject* sender,  // sender
        VfxId id            // id
    )
{
    if(ADVANCED_SETTING_TOOLBAR_ID_OK == id)
    {
        onBarOKCommond();
    }
    else
    {
        getMainScr()->popPage();
    }
}


void VappDtcntAdvancedPage::onFunctionBarTap(
        VfxObject *sender,  // [IN] sender object
        VfxId id            // [IN] Toolbar id
    ) 
{
    switch (id)
    {
        case ID_ADVANCED_FUNCTIONBAR_PREV:
        {
            VfxId prevId = ADVANCED_SETTING_ITEM_ID_HOMEPAGE;
            if(ADVANCED_SETTING_ITEM_ID_HOMEPAGE != m_currActiveId)
            {
                if(ADVANCED_SETTING_ITEM_ID_PROXY_USERNAME == m_currActiveId)
                {
                    if (m_connectionType)
                    {
                        prevId = --m_currActiveId;
                    }
                    else
                    {
                        prevId = ADVANCED_SETTING_ITEM_ID_PROXY_PROXY_ADDRESS;
                    }
                }
                else if(ADVANCED_SETTING_ITEM_ID_OTHERS_DNS1 == m_currActiveId)
                {
                    if (m_useProxy)
                    {
                        prevId = --m_currActiveId;
                    }
                    else
                    {
                        prevId = ADVANCED_SETTING_ITEM_ID_HOMEPAGE;
                    }
                }
                else
                {
                    prevId = --m_currActiveId;
                }
            }
            textEditorState(m_form, prevId, VFX_TRUE);
            break;
        }
        
        case ID_ADVANCED_FUNCTIONBAR_NEXT:
        {
            VfxId nextId = ADVANCED_SETTING_ITEM_ID_OTHERS_SUBNET;
            if(ADVANCED_SETTING_ITEM_ID_OTHERS_SUBNET != m_currActiveId)
            {
                if(ADVANCED_SETTING_ITEM_ID_HOMEPAGE == m_currActiveId)
                {
                    if (m_useProxy)
                    {
                        nextId = ++m_currActiveId;
                    }
                    else
                    {
                        nextId = ADVANCED_SETTING_ITEM_ID_OTHERS_DNS1;
                    }

                }
                else if(ADVANCED_SETTING_ITEM_ID_PROXY_PROXY_ADDRESS == m_currActiveId)
                {
                    if (m_connectionType)
                    {
                        nextId = ++m_currActiveId;
                    }
                    else
                    {
                        nextId = ADVANCED_SETTING_ITEM_ID_PROXY_USERNAME;
                    }                    
                }
                else
                {
                    nextId = ++m_currActiveId;
                }
            }
            textEditorState(m_form, nextId, VFX_TRUE);
            break;
        }
        
        case ID_ADVANCED_FUNCTIONBAR_OK:
        {
            VcpFormItemTextInput* textInput;
            textInput = (VcpFormItemTextInput*)(m_form->getItem(m_currActiveId));
            textInput->getTextBox()->deactivate();
            onBarOKCommond();
            break;
        }
        default:
            break;
    }
}


void VappDtcntAdvancedPage::onTextActivated(
    VcpTextEditor *sender,  // [IN] send object
    VfxBool  activated      // [IN] activate flag
)
{
    if (activated)
    {
        m_currActiveId = sender->getId();
        
        if (m_currActiveId == ADVANCED_SETTING_ITEM_ID_HOMEPAGE)
        {
            m_functionBar->setDisableItem(ID_ADVANCED_FUNCTIONBAR_PREV, VFX_TRUE);
            m_functionBar->setDisableItem(ID_ADVANCED_FUNCTIONBAR_NEXT, VFX_FALSE);
        } 
        else if (m_currActiveId == ADVANCED_SETTING_ITEM_ID_OTHERS_SUBNET)
        {
            m_functionBar->setDisableItem(ID_ADVANCED_FUNCTIONBAR_PREV, VFX_FALSE);
            m_functionBar->setDisableItem(ID_ADVANCED_FUNCTIONBAR_NEXT, VFX_TRUE);
        }
        else
        {
            m_functionBar->setDisableItem(ID_ADVANCED_FUNCTIONBAR_PREV, VFX_FALSE);
            m_functionBar->setDisableItem(ID_ADVANCED_FUNCTIONBAR_NEXT, VFX_FALSE);
        }        
    }
}


void VappDtcntAdvancedPage::onProxySwitchChange(
        VcpFormItemSwitchCell* sender,  // Sender
        VfxId id,                       // Sender id
        VfxBool switchVal               // new switch value
    )
{
    if (m_currActiveId != ADVANCED_SETTING_ITEM_ID_PROXY_PORT || m_connectionType)
    {
        // de-active editor
        textEditorState(m_form, m_currActiveId, VFX_FALSE);
    }
        
    if (switchVal)
    {
        sender->setSwitchStatus(VFX_TRUE);
        m_useProxy = 1;
        setItemState();
    }
    else
    {
        sender->setSwitchStatus(VFX_FALSE);
        m_useProxy = 0;
        setItemState();
    }
}

void VappDtcntAdvancedPage::setItemState()
{
    if(m_useProxy)
    {
        m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PROXY_ADDRESS)->setIsDisabled(VFX_FALSE);
        m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PORT)->setIsDisabled(VFX_FALSE);
        m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_USERNAME)->setIsDisabled(VFX_FALSE);
        m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PASSWORD)->setIsDisabled(VFX_FALSE);
    }
    else
    {
        m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PROXY_ADDRESS)->setIsDisabled(VFX_TRUE);
        m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PORT)->setIsDisabled(VFX_TRUE);
        m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_USERNAME)->setIsDisabled(VFX_TRUE);
        m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PASSWORD)->setIsDisabled(VFX_TRUE);
    }
}

void VappDtcntAdvancedPage::onBtnConnectionTypeTapped(VfxObject * sender,VfxId id)
{
    if (m_currActiveId != ADVANCED_SETTING_ITEM_ID_PROXY_PORT || m_connectionType)
    {
        // de-active editor
        textEditorState(m_form, m_currActiveId, VFX_FALSE);
    }
    
    VcpSelectPopup *selectPopup;
    VFX_OBJ_CREATE(selectPopup, VcpSelectPopup, this);
    selectPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
    VfxWString str;
    str.loadFromRes(STR_ID_VAPP_DTCNT_CONNECTION_TYPE);
    selectPopup->setText(str);
    selectPopup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

    if (m_connectionType)
    {
        str.loadFromRes(STR_ID_VAPP_DTCNT_CONNECTION_TYPE_HTTP);
        selectPopup->addItem(1, str, VFX_TRUE);
        str.loadFromRes(STR_ID_VAPP_DTCNT_CONNECTION_TYPE_WAP);
        selectPopup->addItem(0, str, VFX_FALSE);
    }
    else
    {
        str.loadFromRes(STR_ID_VAPP_DTCNT_CONNECTION_TYPE_HTTP);
        selectPopup->addItem(1, str, VFX_FALSE);
        str.loadFromRes(STR_ID_VAPP_DTCNT_CONNECTION_TYPE_WAP);
        selectPopup->addItem(0, str, VFX_TRUE);
    }

    selectPopup->m_signalPopupState.connect(this, &VappDtcntAdvancedPage::onSelectConnectionType);
    selectPopup->show(VFX_FALSE);
}


void VappDtcntAdvancedPage::onSelectConnectionType(
    VfxBasePopup *sender,        // popup
    VfxBasePopupStateEnum state  // state
)
{
    if(state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {        
        VcpSelectPopup *senderPopup;
        senderPopup = (VcpSelectPopup*)sender;
        VfxId i;
        i = senderPopup->getFirstSeletedId();
        
        if (i == m_connectionType)
        {
            return; // not changed
        }

        VcpFormItemBigButton *btn;
        VfxWString str;
        btn =(VcpFormItemBigButton *)(m_form->getItem(ADVANCED_SETTING_ITEM_ID_CONNTYPE));
        if (i)
        {
            m_connectionType = 1;
            // remove and add
            btn->setHintText(STR_ID_VAPP_DTCNT_CONNECTION_TYPE_HTTP);
            m_form->removeItem(ADVANCED_SETTING_ITEM_ID_PROXY_PORT);
            createTextInput(STR_ID_VAPP_DTCNT_PROXY_PORT, m_commonContext->getProxyPortStr(), VAPP_DTCNT_MAX_PORT_LENGTH,
                            IMM_INPUT_TYPE_NUMERIC, ADVANCED_SETTING_ITEM_ID_PROXY_PORT, VFX_TRUE);
        }
        else
        {
            m_connectionType = 0;
            // remove and add
            btn->setHintText(STR_ID_VAPP_DTCNT_CONNECTION_TYPE_WAP);
            m_form->removeItem(ADVANCED_SETTING_ITEM_ID_PROXY_PORT);
            VcpFormItemBigButton *btn;
            VFX_OBJ_CREATE(btn, VcpFormItemBigButton, m_form);
            btn->setButtonText(STR_ID_VAPP_DTCNT_PROXY_PORT);
            if (m_wapPortIndex == 1)
            {
                btn->setHintText(STR_ID_VAPP_DTCNT_GPRS_CHAP_AUTH);
            }
            else
            {
                btn->setHintText(STR_ID_VAPP_DTCNT_GPRS_PAP_AUTH);
            }
            btn->getButton()->m_signalClicked.connect(this, &VappDtcntAdvancedPage::onBtnWapProxyPortTypeTapped);
            m_form->insertItem(btn, ADVANCED_SETTING_ITEM_ID_PROXY_USERNAME, ADVANCED_SETTING_ITEM_ID_PROXY_PORT);
        }
        if (m_useProxy)
        {
            m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PORT)->setIsDisabled(VFX_FALSE);
        }
        else
        {
            m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PORT)->setIsDisabled(VFX_TRUE);
        }
    }
}

void VappDtcntAdvancedPage::onBtnWapProxyPortTypeTapped(
        VfxObject* sender, //sender 
        VfxId id //
    )
{
    if (m_currActiveId != ADVANCED_SETTING_ITEM_ID_PROXY_PORT || m_connectionType)
    {
        // de-active editor
        textEditorState(m_form, m_currActiveId, VFX_FALSE);
    }
    
    VcpSelectPopup *selectPopup;
    VFX_OBJ_CREATE(selectPopup, VcpSelectPopup, this);
    selectPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
    VfxWString str;
    str.loadFromRes(STR_ID_VAPP_DTCNT_PROXY_PORT);
    selectPopup->setText(str);
    selectPopup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

    if (m_wapPortIndex == 0)
    {
        str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_PAP_AUTH);
        selectPopup->addItem(0, str, VFX_TRUE);
        str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_CHAP_AUTH);
        selectPopup->addItem(1, str, VFX_FALSE);
    }
    else
    {
        str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_PAP_AUTH);
        selectPopup->addItem(0, str, VFX_FALSE);
        str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_CHAP_AUTH);
        selectPopup->addItem(1, str, VFX_TRUE);
    }

    selectPopup->m_signalPopupState.connect(this, &VappDtcntAdvancedPage::onSelectWapProxyPort);
    selectPopup->show(VFX_FALSE);
}


void VappDtcntAdvancedPage::onSelectWapProxyPort(
    VfxBasePopup *sender,        // popup
    VfxBasePopupStateEnum state  // state
)
{
   if(state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {        
        VcpSelectPopup *senderPopup;
        senderPopup = (VcpSelectPopup*)sender;
        VfxId i;
        i = senderPopup->getFirstSeletedId();
        
        if (i == m_wapPortIndex)
        {
            return; // not changed
        }

        VcpFormItemBigButton *btn;
        btn =(VcpFormItemBigButton *)(m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PORT));
        VfxWString str;
        if (i == 0)
        {
            m_wapPortIndex = 0;
            str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_PAP_AUTH);
            btn->setHintText(str);
        }
        else
        {
            m_wapPortIndex = 1;
            str.loadFromRes(STR_ID_VAPP_DTCNT_GPRS_CHAP_AUTH);
            btn->setHintText(str);
        }
    }
}

void VappDtcntAdvancedPage::onTextInsert(
        VfxWChar *str,  // [IN] current text string buf
        VfxS32 pos,     // [IN] will be inserted char
        VcpTextChangeEnum type,
        VfxBool *changed // [OUT] flad indicate to insert or not
    )
{
    *changed = VFX_TRUE;
    if(VCP_TEXT_CHANGE_INSERT_CHAR == type)
    {
        VFX_ASSERT(str != NULL);
        VcpTextEditor *sender;
        VcpFormItemTextInput* textInput;
        textInput = (VcpFormItemTextInput*)(m_form->getItem(ADVANCED_SETTING_ITEM_ID_PROXY_PORT));
        sender = textInput->getTextBox();
        VfxWChar *textBuf;
        textBuf = sender->getText();

        if (mmi_wcslen((WCHAR*)textBuf) == 0)
        {
            *changed = VFX_TRUE;
            return;
        }
        // dot won't make number bigger
        if (mmi_wcscmp((WCHAR*)str, (WCHAR*)L"0") == 0) // 0
        {
            // the followting cases won't impact value, editor will skip it.
            if ((pos == 0) || (pos == 1 && mmi_wcsncmp((WCHAR*)textBuf, (WCHAR*)L"0", 1) == 0))
            {
                *changed = VFX_FALSE;
                return;
            }
        }
        else // 1~9
        {
            if (pos == 1 && mmi_wcsncmp((WCHAR*)textBuf, (WCHAR*)L"0", 1) == 0)
            {
                // first calculate, then delete
                sender->deleteChars();
                *changed = VFX_TRUE;
                return;
            }
        }
    }
}


VfxS16 VappDtcntAdvancedPage::checkUrlValidity(VfxWChar *url, VfxBool isBlankValid)
{
    /* check the zero length */
    if (VFX_FALSE == isBlankValid)
    {
        if (!mmi_wcslen((WCHAR*)url))
        {
            return APPLIB_URL_ERR_INVALID_PARAM;
        }
    }
    else
    {
        if (!mmi_wcslen((WCHAR*)url))
        {
            return 0;
        }
    }

    /* convert the UCS2 URL string into UTF-8 */
    VfxU8 urlAscii[MAX_ADDRESS_NAME_LEN];
    mmi_chset_ucs2_to_utf8_string((U8*)urlAscii, MAX_ADDRESS_NAME_LEN, (U8*)url);

    /* parse the URL string by using Applib API */
    applib_url_struct urlInfo;
    if (!(VfxS32) applib_parse_url((char*)urlAscii, &urlInfo))
    {
        /* if there is an empty URI scheme in the URL then append the default ("http://") */
        /* URI scheme */
        if (urlInfo.scheme_type == applib_scheme_empty)
        {
            VfxU8 uriSchmLen;
            uriSchmLen = strlen((char*)VAPP_DTCNT_DEFAULT_URL);
            VfxChar temp[MAX_ADDRESS_NAME_LEN];
            if (strlen((char*)urlAscii) + uriSchmLen + 1 > MAX_ADDRESS_NAME_LEN)
            {
                strncpy((char*)temp, (char*)urlAscii, MAX_ADDRESS_NAME_LEN - uriSchmLen - 1);
                temp[MAX_ADDRESS_NAME_LEN - uriSchmLen - 1] = '\0';
            }
            else
            {
                strcpy((char*) temp, (char*) urlAscii);
            }
            strcpy((char*) urlAscii, (char*) VAPP_DTCNT_DEFAULT_URL);
            strcat((char*) urlAscii, (char*) temp);
            
            /* check whether it contain HTTP or HTTPS URI scheme with empty host */
            if (VFX_FALSE == isBlankValid)
            {
                if (!(S32) applib_parse_url((char*) urlAscii, &urlInfo))
                {
                    if ((urlInfo.scheme_type == applib_scheme_http) || (urlInfo.scheme_type == applib_scheme_https))
                    {

                        if (!urlInfo.len[APPLIB_URL_HOST_PART])
                        {
                            return APPLIB_URL_ERR_INVALID_HOST;
                        }
                    }
                }
            }
        }
        /* check whether it contain HTTP or HTTPS URI scheme with empty host */
        else if ((urlInfo.scheme_type == applib_scheme_http) || (urlInfo.scheme_type == applib_scheme_https))
        {
            if (MMI_FALSE == isBlankValid)
            {
                if (!urlInfo.len[APPLIB_URL_HOST_PART])
                {
                    return APPLIB_URL_ERR_INVALID_HOST;
                }
            }
        }
    }

    /* validate the UTF-8 URL string by using Applib API */
    VfxS16 ret;
    ret = (S16)applib_url_is_valid((char*) urlAscii);
    if (ret == 0)
    {        
        mmi_chset_utf8_to_ucs2_string((U8*) url, (MAX_ADDRESS_NAME_LEN) * ENCODING_LENGTH, (U8*) urlAscii);
    }
    return ret;
}


VfxBool VappDtcntAdvancedPage::checkIpAddressValidity(VfxWChar *ipDisplayStr, VfxU8 *ip, VfxBool isBlankValid, VfxBool isAllZeroValid)
{
    // emtpy
    if (VFX_FALSE == isBlankValid)
    {
        if (!mmi_wcslen((WCHAR*)ipDisplayStr))
        {
            return VFX_FALSE;
        }
    }
    else
    {
        if (!mmi_wcslen((WCHAR*)ipDisplayStr))
        {
            return VFX_TRUE;
        }
    }

    // get ip value
    VfxU16 ipAddress[MAX_PART_IP_ADDRESS]; /* use U16 to justify ip value > 255 */
    VfxChar tmpBuf[MAX_PART_IP_ADDRESS * 4];
    VfxChar *point, *p, *q;
    VfxS32 i = 0;
    mmi_wcs_to_asc((CHAR*)tmpBuf, (WCHAR*)ipDisplayStr);
    /* not allow blank space */
    if (strchr(tmpBuf, ' '))
    {
        return VFX_FALSE;
    }
    if (strstr(tmpBuf, "...") || strstr(tmpBuf, ".."))
    {
        return VFX_FALSE;
    }
    p = tmpBuf;
    while ((i < MAX_PART_IP_ADDRESS) && p)
    {
        point = strchr(p, '.');
        if (point)
        {
            q = point + 1;
            point = NULL;
        }
        else
        {
            q = NULL;
        }
        if (!p || !strlen(p))
        {
            return VFX_FALSE;
        }
        ipAddress[i] = atoi(p);
        p = q;
        if (ipAddress[i++] > 255)
        {
            return VFX_FALSE;
        }
    }
    if (i != MAX_PART_IP_ADDRESS || p)
    {
        return VFX_FALSE;
    }

    // check all zero of IP
    if (!isAllZeroValid)
    {
        if ((ipAddress[0] + ipAddress[1] + ipAddress[2] + ipAddress[3]) == 0)
        {
            return VFX_FALSE;
        }
    }

    // assign value
    for (i = 0; i < MAX_PART_IP_ADDRESS; i++)
    {
        ip[i] = (VfxU8)ipAddress[i];
    }    
    return VFX_TRUE;
}


VfxBool VappDtcntAdvancedPage::checkProxyPortValidity(VfxWChar *portStr)
{
    if (!mmi_wcslen((WCHAR*)portStr))
    {
        return VFX_FALSE;
    }
    VfxChar portAscii[VAPP_DTCNT_MAX_PORT_LENGTH + 1];
    mmi_wcs_to_asc((CHAR*)portAscii, (WCHAR*)portStr);
    VfxU32 tempVal = (U32)atoi(portAscii);
    if (tempVal == 0 || tempVal > VAPP_DTCNT_MAX_PORT_NUM)
    {
        return VFX_FALSE;
    }
    return VFX_TRUE;
}


void VappDtcntAdvancedPage::displayComfirmPopup(VfxU16 resId)
{
    VcpConfirmPopup *confirmPopup;                
    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
    confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    VfxWString string;
    string.loadFromRes(resId);
    confirmPopup->setText(string);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    confirmPopup->setAutoDestory(VFX_FALSE);
    confirmPopup->show(VFX_FALSE);
}

#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
void VappDtcntAdvancedPage::onSimChangeEvt(VfxBool flag, mmi_sim_enum sim)
{
	VfxU32 simIndex = 0;
	simIndex = mmi_frm_sim_to_index(sim);
	if(VFX_FALSE == flag)
	{
		if(simIndex == (VfxU32)(m_simType - 1))
		{
			getMainScr()->closePage(getId());
		}
	}
}
#endif

void VappDtcntAdvancedPage::onDeinit()
{
    if (m_functionBar)
    {
        VFX_OBJ_CLOSE(m_functionBar);
    }
    if (m_detailBase)
    {
        VFX_FREE_MEM(m_detailBase);
    }
    if (m_detailProxy)
    {
        VFX_FREE_MEM(m_detailProxy);
    }
    if (m_detailOthers)
    {
        VFX_FREE_MEM(m_detailOthers);
    }
    VfxPage::onDeinit();
}

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
#endif
/***************************************************************************** 
 * Class VappDtcntListPage
 *****************************************************************************/

void VappDtcntListPage::onPageInit(VfxPageEx *page)
{
    VfxPageHandler::onPageInit(page);

    // prepare data for list
    VFX_OBJ_CREATE(m_listCntx, VappDtcntListDisplayContext, this);
    m_listCntx->prepareListInfo(m_simType, VAPP_DTCNT_LIST_PREPARE_TYPE_SETTING);

    //VappDtcntScreen *scr = (VappDtcntScreen*)getMainScr();
    //scr->setSimType(m_simType);
    // title bar
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, page);    
    if (VappDtcntSimAvailableInfo::getAvailableSimNum() < 2)
    {
        m_titleBar->setTitle(STR_ID_VAPP_DTCNT);
    }
    else
    {
        m_titleBar->setTitle(VappDtcntDispItemList::getSimName((VfxU32)(m_simType - 1)));
    }
    page->setTopBar(m_titleBar);
    // toolbar
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, page);
    m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_ADD, STR_GLOBAL_ADD, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
    m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_CHANGE_DEFAULT, STR_ID_VAPP_DTCNT_SET_DEFAULT, IMG_ID_VAPP_DTCNT_SET_DEFAULT);
    m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_DELETE, STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    if (getAcctNumExcludeSimProv(m_simType) == 0)
    {
        m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_CHANGE_DEFAULT, VFX_TRUE);
        m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_DELETE, VFX_TRUE);
    }
    if (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM == getAcctNumExcludeSimProv(m_simType))
    {
        m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_ADD, VFX_TRUE);
    }
    m_toolBar->m_signalButtonTap.connect(this, &VappDtcntListPage::onToolBarTapped);          // connect tool bar signal
    page->setBottomBar(m_toolBar); 

    // list
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, page);
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemTapped.connect(this, &VappDtcntListPage::onListItemTapped);
    m_listMenu->m_signalItemSelectionStateChanged.connect(this, &VappDtcntListPage::onItemStateChanged);
    m_listMenu->setSize(page->getSize());
    setListMenuFormat(m_listMenu, VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT, VCP_LIST_MENU_MODE_NORMAL, VCP_LIST_MENU_CONTROL_MODE_NORMAL);
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__
    VFX_OBJ_GET_INSTANCE(VappDtcntSimAvailableListener)->m_signalSimChangedEvent.connect(this, &VappDtcntListPage::onSimChangeEvt);
#endif
}


void VappDtcntListPage::onPageDeinit(VfxPageEx *page)
{
    if (m_selectionState)
    {
        VFX_FREE_MEM(m_selectionState);
    }
    if (m_disableState)
    {
        VFX_FREE_MEM(m_disableState);
    }
    VfxPageHandler::onPageDeinit(page);
}

void VappDtcntListPage::onPageEnter(VfxPageEx *page, VfxBool isBackward)
{
    if (isBackward)
    {
        if (m_listType == VAPP_DTCNT_LIST_TYPE_DISPLAY_ACCOUNT)
        {
            if (getAcctNumExcludeSimProv(m_simType) == 0)
            {
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_CHANGE_DEFAULT, VFX_TRUE);
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_DELETE, VFX_TRUE);
            }
            else
            {
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_CHANGE_DEFAULT, VFX_FALSE);
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_DELETE, VFX_FALSE);
            }
            if (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM == getAcctNumExcludeSimProv(m_simType))
            {
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_ADD, VFX_TRUE);
            }            
            m_listCntx->prepareListInfo(m_simType, VAPP_DTCNT_LIST_PREPARE_TYPE_SETTING);
            m_listMenu->resetAllItems(VFX_TRUE);
        }
        else if (m_listType == VAPP_DTCNT_LIST_TYPE_DELETE_ACCOUNT)
        {
            // refresh delete page
            VfxBool *tempSelectionState; //
            VfxU32 *tempAccountId; //
            VfxU32 i, j, tempNum;
            VappDtcntDisplayItemInfo *itemInfo;
            tempNum = m_listCntx->getListItemNumber(); // the number before refresh
            VFX_ALLOC_MEM(tempSelectionState, tempNum * sizeof(VfxBool), this);
            VFX_ALLOC_MEM(tempAccountId, tempNum * sizeof(VfxU32), this);
            memcpy(tempSelectionState, m_selectionState, tempNum * sizeof(VfxBool));
            for (i = 0; i < tempNum; i++)
            {
                itemInfo = m_listCntx->getListInfo(i);
                tempAccountId[i] = itemInfo->getProfileId();
            }
            // free momery and realloc again
            VFX_FREE_MEM(m_selectionState);
            VFX_FREE_MEM(m_disableState);

            // prepare info again
            m_listCntx->prepareListInfo(m_simType, VAPP_DTCNT_LIST_PREPARE_TYPE_SETTING);
            VfxU32 acctNum;
            acctNum = m_listCntx->getListItemNumber();
            VFX_ALLOC_MEM(m_selectionState, acctNum * sizeof(VfxBool), this);
            VFX_ALLOC_MEM(m_disableState, acctNum * sizeof(VfxBool), this);
            memset(m_selectionState, 0, acctNum * sizeof(VfxBool));
            memset(m_disableState, 0, acctNum * sizeof(VfxBool));

            for (i = 0; i < acctNum; i++)
            {
                itemInfo = m_listCntx->getListInfo(i);

                for (j = 0; j < tempNum; j++)
                {
                    if (tempAccountId[j] == itemInfo->getProfileId())
                    {
                        m_selectionState[i] = tempSelectionState[j];
                        break;
                    }
                }

                if (VappDtcntDispItemList::isAccountInUse(itemInfo->getProfileId()) || itemInfo->getReadOnly())
                {
                    m_disableState[i] = VFX_TRUE;
                    m_selectionState[i] = VFX_FALSE;
                }
                else
                {
                    m_disableState[i] = VFX_FALSE;
                }
            }

            // toolbar
            m_markAll = VFX_TRUE;
            VfxBool diableAllFlag = VFX_TRUE;
            VfxBool selectAnyFlag = VFX_FALSE;
            VfxWString str;
            for (i = 0; i < acctNum; i++)
            {
                if (!m_disableState[i])
                {
                    diableAllFlag = VFX_FALSE;
                }
                if (m_selectionState[i])
                {
                    selectAnyFlag = VFX_TRUE;
                }
                if (!m_disableState[i] && !m_selectionState[i])
                {
                    m_markAll = VFX_FALSE;
                }
            }
            
            if (diableAllFlag) // all item is disable
            {
                m_markAll = VFX_FALSE;
                str.loadFromRes(STR_GLOBAL_MARK_ALL);
                m_toolBar->changeItem(VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL, VFX_TRUE);                    
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_DELETE, VFX_TRUE);
            }
            else if (m_markAll)
            {
                str.loadFromRes(STR_GLOBAL_UNMARK_ALL);
                m_toolBar->changeItem(VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL, VFX_FALSE);                    
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_DELETE, VFX_FALSE);
            }
            else if (selectAnyFlag)
            {
                str.loadFromRes(STR_GLOBAL_MARK_ALL);
                m_toolBar->changeItem(VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL, VFX_FALSE);                    
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_DELETE, VFX_FALSE);
            }
            else
            {
                str.loadFromRes(STR_GLOBAL_MARK_ALL);
                m_toolBar->changeItem(VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL, VFX_FALSE);                    
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_DELETE, VFX_TRUE);
            }
            VFX_FREE_MEM(tempSelectionState);
            VFX_FREE_MEM(tempAccountId);
            m_listMenu->resetAllItems(VFX_TRUE);
        }
    }
}


void VappDtcntListPage::onPageBack(VfxPageEx *page)
{
    VfxWString str;

    if(VAPP_DTCNT_LIST_TYPE_DISPLAY_ACCOUNT == m_listType)
    {
        //page->onBack();
        VfxPageHandler::onPageBack(page);
    }
    else 
    {
        if(VAPP_DTCNT_LIST_TYPE_DELETE_ACCOUNT == m_listType)
        {
            VFX_FREE_MEM(m_selectionState);
            VFX_FREE_MEM(m_disableState);
        }
        if (VappDtcntSimAvailableInfo::getAvailableSimNum() < 2)
        {
            str.loadFromRes(STR_ID_VAPP_DTCNT);
        }
        else
        {
            str = VappDtcntDispItemList::getSimName((VfxU32)(m_simType - 1));
        }
        m_titleBar->setTitle(str);
        page->toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_TRUE);
        VFX_OBJ_CLOSE(m_toolBar);
        VFX_OBJ_CREATE(m_toolBar, VcpToolBar, page);
        m_listType = VAPP_DTCNT_LIST_TYPE_DISPLAY_ACCOUNT;
        str.loadFromRes(STR_GLOBAL_ADD);
        m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_ADD, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
        str.loadFromRes(STR_ID_VAPP_DTCNT_SET_DEFAULT);
        m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_CHANGE_DEFAULT, str, IMG_ID_VAPP_DTCNT_SET_DEFAULT);
        str.loadFromRes(STR_GLOBAL_DELETE);
        m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_DELETE, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
        if (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM == getAcctNumExcludeSimProv(m_simType))
        {
            m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_ADD, VFX_TRUE);
        }
        page->setBottomBar(m_toolBar); 
        m_toolBar->m_signalButtonTap.connect(this, &VappDtcntListPage::onToolBarTapped); 

        m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
        m_listMenu->updateAllItems();
    }
}


VfxU32 VappDtcntListPage::getCount() const
{
    return m_listCntx->getListItemNumber();
}

VfxBool VappDtcntListPage::getItemIsDisabled(VfxU32 index) const 
{
    if(VAPP_DTCNT_LIST_TYPE_DELETE_ACCOUNT == m_listType && m_disableState[index])
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VcpListMenuItemStateEnum VappDtcntListPage::getItemState(
        VfxU32 index   // [IN] index of the item
        ) const
{
    if(VAPP_DTCNT_LIST_TYPE_DELETE_ACCOUNT == m_listType)
    {
        if (m_selectionState[index])
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }            
    }
    else if(VAPP_DTCNT_LIST_TYPE_CHANGE_DFFAULT == m_listType)
    {
        VappDtcntDisplayItemInfo *itemInfo;
        itemInfo = m_listCntx->getListInfo(index);
        MMI_BOOL ret;
        VfxU32 defaultId;
        ret = srv_dtcnt_get_default_account(m_simType, &defaultId);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_DEFAULT_ACCOUNT, m_simType, defaultId, ret);
        if (defaultId == itemInfo->getProfileId())
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
    }
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}


VcpListMenuCellClientBaseFrame *VappDtcntListPage::getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        )
{
    VappDtcntDisplayItemInfo *itemInfo;
    itemInfo = m_listCntx->getListInfo(index);
    if (itemInfo->getReadOnly())
    {
        VappDtcntRightIconMultiTextFrame *frame;
        VFX_OBJ_CREATE(frame, VappDtcntRightIconMultiTextFrame, parentFrame);
        return frame;
    }    
    return NULL;
}


VfxBool VappDtcntListPage::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
{
    VappDtcntDisplayItemInfo *itemInfo;
    itemInfo = m_listCntx->getListInfo(index);
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text.loadFromMem(itemInfo->getName());
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        text.loadFromMem(itemInfo->getAddress());
    }
    return VFX_TRUE;
}

VfxBool VappDtcntListPage::getItemTextFrameFormat(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxTextFrame *frame             // [OUT] the text frame
    ) 
{
    VappDtcntDisplayItemInfo *itemInfo;
    itemInfo = m_listCntx->getListInfo(index);

    MMI_BOOL ret;
    VfxU32 defaultId;
    ret = srv_dtcnt_get_default_account(m_simType, &defaultId);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_DEFAULT_ACCOUNT, m_simType, defaultId, ret);
    if ((itemInfo->getProfileId() != defaultId) ||
         (m_listMenu->getFocusItemIndex() == index))
    {
        return VFX_FALSE;
    }
    else
    {
        frame->setColor(VAPP_DTCNT_DEFAULT_TEXT_FONT_COLOR);
        return VFX_TRUE;
    }
}


VfxBool VappDtcntListPage::getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
{
    text.loadFromRes(STR_ID_VAPP_DTCNT_EMPTY_LIST);
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}


VfxBool VappDtcntListPage::getItemImage(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxImageSrc &image              // [OUT] the image resource
    )
{
    VappDtcntDisplayItemInfo *itemInfo;
    itemInfo = m_listCntx->getListInfo(index);
    if (itemInfo->getReadOnly())
    {
        if (fieldType == VCP_LIST_MENU_FIELD_ICON)
        {
            image.setResId(IMG_ID_VAPP_DTCNT_READ_ONLY);
        }
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

void VappDtcntListPage::deleteSelectedAccount()
{
    m_listType = VAPP_DTCNT_LIST_TYPE_DISPLAY_ACCOUNT;
    VfxU32 i;
    for (i = 0; i < m_listCntx->getListItemNumber(); i++)
    {
        if (m_selectionState[i] == VFX_TRUE)
        {
            VappDtcntDisplayItemInfo *itemInfo;
            itemInfo = m_listCntx->getListInfo(i);
            // check account is used or not
            if(VappDtcntDispItemList::isAccountInUse(itemInfo->getProfileId()))
            {
                continue;
            }

            // call service api to delete id, use callback to set invalid info
            srv_dtcnt_result_enum result;
            result = srv_dtcnt_store_delete_prof(
                itemInfo->getProfileId(), 
                MMI_FALSE, 
                NULL, 
                NULL);

            // if success, delete
            if (result == SRV_DTCNT_RESULT_SUCCESS)
            {
                VappDtcntDispItemList::deleteAcctItem(itemInfo->getProfileId());
                m_selectionState[i] = VFX_FALSE;
            }
            
        }
    }
    MMI_BOOL ret;
    VfxU32 defaultId;
    ret = srv_dtcnt_get_default_account(m_simType, &defaultId);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_DEFAULT_ACCOUNT, m_simType, defaultId, ret);

    VfxBool flag; // check whether all deleted
    flag = VFX_TRUE;
    VfxWString str;
    for (i = 0; i < m_listCntx->getListItemNumber(); i++)
    {
        if (m_selectionState[i] == VFX_TRUE)
        {
            flag = VFX_FALSE;
            break;
        }
    }
    if (!flag)
    {
        VcpConfirmPopup *confirmPopup;                
        VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, getPage());
        confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        str.loadFromRes(STR_ID_VAPP_DTCNT_DELETE_NOT_ALLOWED);
        confirmPopup->setText(str);
        confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        confirmPopup->setAutoDestory(VFX_FALSE);
        confirmPopup->show(VFX_FALSE);
        confirmPopup->m_signalButtonClicked.connect(this, &VappDtcntListPage::onBtnNotAllowDelete);
        return;
    }
    VFX_FREE_MEM(m_selectionState);
    VFX_FREE_MEM(m_disableState);
    if (VappDtcntSimAvailableInfo::getAvailableSimNum() < 2)
    {
        str.loadFromRes(STR_ID_VAPP_DTCNT);
    }
    else
    {
        str = VappDtcntDispItemList::getSimName((VfxU32)(m_simType - 1));
    }
    m_titleBar->setTitle(str);
    VFX_OBJ_CLOSE(m_toolBar);
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, getPage());
    str.loadFromRes(STR_GLOBAL_ADD);
    m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_ADD, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
    str.loadFromRes(STR_ID_VAPP_DTCNT_SET_DEFAULT);
    m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_CHANGE_DEFAULT, str, IMG_ID_VAPP_DTCNT_SET_DEFAULT);
    str.loadFromRes(STR_GLOBAL_DELETE);
    m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_DELETE, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    if (VappDtcntDispItemList::getAcctNum() == 0)
    {
        m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_CHANGE_DEFAULT, VFX_TRUE);
        m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_DELETE, VFX_TRUE);
    }
    getPage()->setBottomBar(m_toolBar); 
    m_toolBar->m_signalButtonTap.connect(this, &VappDtcntListPage::onToolBarTapped); 

    m_listCntx->prepareListInfo(m_simType, VAPP_DTCNT_LIST_PREPARE_TYPE_SETTING);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
    m_listMenu->resetAllItems(VFX_TRUE);
}


void VappDtcntListPage::onListItemTapped(VcpListMenu * sender,VfxU32 index)
{
    VfxWString str;
    VappDtcntDisplayItemInfo *itemInfo;
    if(VAPP_DTCNT_LIST_TYPE_DISPLAY_ACCOUNT == m_listType)
    {
        // entry edit or view page
        itemInfo = m_listCntx->getListInfo(index);
        if (itemInfo->getBearerType() == DATA_ACCOUNT_BEARER_GPRS)
        {
            if (itemInfo->getReadOnly())
            {
                // view                    
                VappDtcntGPRSPage *gprsPage;
                VFX_OBJ_CREATE_EX(gprsPage, VappDtcntGPRSPage, m_scr, (itemInfo->getProfileId(), VAPP_DTCNT_ACCOUNT_SETTING_TYPE_VIEW, m_simType));
                m_scr->pushPage(0, gprsPage);
            }
            else
            {
                if(VappDtcntDispItemList::isAccountInUse(itemInfo->getProfileId()))
                {
                    VcpConfirmPopup *confirmPopup;                
                    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, getPage());
                    confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
                    str.loadFromRes(STR_ID_VAPP_DTCNT_EDIT_NOT_ALLOWED);
                    confirmPopup->setText(str);
                    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                    confirmPopup->setAutoDestory(VFX_FALSE);
                    confirmPopup->show(VFX_FALSE);
                    return;
                }
                VappDtcntGPRSPage *gprsPage;
                VFX_OBJ_CREATE_EX(gprsPage, VappDtcntGPRSPage, m_scr, (itemInfo->getProfileId(), VAPP_DTCNT_ACCOUNT_SETTING_TYPE_EDIT, m_simType));
                m_scr->pushPage(0, gprsPage);
            }
        }
    #ifdef __TCPIP_OVER_CSD__
        else if (itemInfo->getBearerType() == DATA_ACCOUNT_BEARER_CSD)
        {
            if (itemInfo->getReadOnly())
            {
                // view
                VappDtcntCSDPage *csdPage;
                VFX_OBJ_CREATE_EX(csdPage, VappDtcntCSDPage, m_scr, (itemInfo->getProfileId(), VAPP_DTCNT_ACCOUNT_SETTING_TYPE_VIEW, m_simType));
                m_scr->pushPage(0, csdPage);
            }
            else //edit
            {
                if(VappDtcntDispItemList::isAccountInUse(itemInfo->getProfileId()))
                {
                    VcpConfirmPopup *confirmPopup;                
                    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, getPage());
                    confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
                    str.loadFromRes(STR_ID_VAPP_DTCNT_EDIT_NOT_ALLOWED);
                    confirmPopup->setText(str);
                    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                    confirmPopup->setAutoDestory(VFX_FALSE);
                    confirmPopup->show(VFX_FALSE);
                    return;
                }
                VappDtcntCSDPage *csdPage;
                VFX_OBJ_CREATE_EX(csdPage, VappDtcntCSDPage, m_scr, (itemInfo->getProfileId(), VAPP_DTCNT_ACCOUNT_SETTING_TYPE_EDIT, m_simType));
                m_scr->pushPage(0, csdPage);
            }
        }
    #endif
    }
    else if(m_listType == VAPP_DTCNT_LIST_TYPE_CHANGE_DFFAULT)
    {
        VappDtcntDisplayItemInfo *itemInfo;
        itemInfo = m_listCntx->getListInfo(index);
        VappDtcntDispItemList::setDefaultProfileIdToSrv(itemInfo->getProfileId());
        getPage()->toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_TRUE);
        if (VappDtcntSimAvailableInfo::getAvailableSimNum() < 2)
        {
            str.loadFromRes(STR_ID_VAPP_DTCNT);
        }
        else
        {
            str = VappDtcntDispItemList::getSimName((VfxU32)(m_simType - 1));
        }
        m_titleBar->setTitle(str);
        m_listType = VAPP_DTCNT_LIST_TYPE_DISPLAY_ACCOUNT;
        m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
        m_listMenu->updateAllItems();
    }
}


void VappDtcntListPage::onItemStateChanged(
    VcpListMenu *sender, 
    VfxU32 index, 
    VcpListMenuItemStateEnum newState)
{
    if(VAPP_DTCNT_LIST_TYPE_DELETE_ACCOUNT == m_listType)
    {
        if (newState == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
        {
            m_selectionState[index] = VFX_FALSE;
        }
        else if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        {
            m_selectionState[index] = VFX_TRUE;
        }
        
        VfxU32 i, acctNum;
        acctNum = m_listCntx->getListItemNumber();
        for (i = 0; i < acctNum; i++)
        {
            if (m_selectionState[i])
            {
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_DELETE, VFX_FALSE);
                break;
            }
        }
        if (i == acctNum)
        {
            m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_DELETE, VFX_TRUE);
        }

        VfxBool tmpFlag;
        tmpFlag = VFX_FALSE;
        for (i = 0; i < acctNum; i++)
        {
            if (!m_selectionState[i] && !m_disableState[i])
            {
                tmpFlag = VFX_TRUE;
                break;
            }
        }
        VfxWString str;
        if (!tmpFlag)
        {
            if (!m_markAll)
            {
                str.loadFromRes(STR_GLOBAL_UNMARK_ALL);
                m_toolBar->changeItem(VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
                m_markAll = VFX_TRUE;
            }
        }
        else
        {
            if (m_markAll)
            {
                str.loadFromRes(STR_GLOBAL_MARK_ALL);
                m_toolBar->changeItem(VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
                m_markAll = VFX_FALSE;
            }
        }
    }    
}

void VappDtcntListPage::onToolBarTapped(VfxObject *sender, VfxU32 index)
{
    VfxWString str;
    VfxU32 i;
    VfxPageEx *page = getPage();
    switch (index)
    {
        case VAPP_DTCNT_LIST_TOOLBAR_ID_ADD:
        {
        #if defined(__TCPIP_OVER_CSD__) && defined(__MMI_GPRS_FEATURES__)
            VcpCommandPopup *commandPopup;
            VFX_OBJ_CREATE(commandPopup, VcpCommandPopup, page);
                
            commandPopup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
            str.loadFromRes(STR_ID_VAPP_DTCNT_ADD_DATA_ACCOUNT);
            commandPopup->setText(str);
            #ifdef __MMI_GPRS_FEATURES__
            str.loadFromRes(STR_ID_VAPP_DTCNT_ADD_GPRS);
            commandPopup->addItem(VAPP_DTCNT_ADD_ACCOUNT_TYPE_GPRS, str);
            #endif
            #ifdef __TCPIP_OVER_CSD__
            str.loadFromRes(STR_ID_VAPP_DTCNT_ADD_CSD);
            commandPopup->addItem(VAPP_DTCNT_ADD_ACCOUNT_TYPE_CSD, str);
            #endif
            str.loadFromRes(STR_GLOBAL_CANCEL);
            commandPopup->addItem(VAPP_DTCNT_ADD_ACCOUNT_TYPE_CANCEL, str, VCP_POPUP_BUTTON_TYPE_CANCEL);
            commandPopup->setAutoDestory(VFX_TRUE);
            commandPopup->m_signalButtonClicked.connect(this, &VappDtcntListPage::onCommandPopupAddAccount);
            commandPopup->show(VFX_FALSE);
            // display popup
        #elif defined(__MMI_GPRS_FEATURES__)
            VappDtcntGPRSPage *gprsPage;
            VFX_OBJ_CREATE_EX(gprsPage, VappDtcntGPRSPage, m_scr, (0, VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD, m_simType));
            m_scr->pushPage(0, gprsPage);
        #elif defined(__TCPIP_OVER_CSD__)
            VappDtcntCSDPage *csdPage;
            VFX_OBJ_CREATE_EX(csdPage, VappDtcntCSDPage, m_scr, (0, VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD, m_simType));
            m_scr->pushPage(0, csdPage);
        #endif
            break;
        }
        case VAPP_DTCNT_LIST_TOOLBAR_ID_TO_CHANGE_DEFAULT:
        {
            // change default page
            /*
            VappDtcntSetDefaultListPage *setDefaultPage;
            VFX_OBJ_CREATE_EX(setDefaultPage, VappDtcntSetDefaultListPage, this, (m_simType, m_listCntx));
            getMainScr()->pushPage(0, setDefaultPage);
            */
            str.loadFromRes(STR_ID_VAPP_DTCNT_SET_DEFAULT);
            m_titleBar->setTitle(str);
            page->toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_FALSE);
            m_listType = VAPP_DTCNT_LIST_TYPE_CHANGE_DFFAULT;
            m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);
            
            VfxId currIndex = 0;
            VappDtcntDisplayItemInfo *itemInfo;
            VfxU32 index;
            MMI_BOOL ret;
            VfxU32 defaultId;
            ret = srv_dtcnt_get_default_account(m_simType, &defaultId);
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_DEFAULT_ACCOUNT, m_simType, defaultId, ret);
            for (index = 0; index < m_listCntx->getListItemNumber(); index++)
            {
                itemInfo = m_listCntx->getListInfo(index);
                if (defaultId == itemInfo->getProfileId())
                {
                    currIndex = index;
                    break;
                }
            }
            m_listMenu->setVisibleMenuItem(currIndex);
            m_listMenu->updateAllItems();
            break;
        }
        case VAPP_DTCNT_LIST_TOOLBAR_ID_TO_DELETE:
        {
            // delete page
            VFX_ALLOC_MEM(m_selectionState, m_listCntx->getListItemNumber() * sizeof(VfxBool), this);
            VFX_ALLOC_MEM(m_disableState, m_listCntx->getListItemNumber() * sizeof(VfxBool), this);
            memset(m_selectionState, 0, m_listCntx->getListItemNumber() * sizeof(VfxBool));
            memset(m_disableState, 0, m_listCntx->getListItemNumber() * sizeof(VfxBool));
            VfxU32 acctNum;
            acctNum = m_listCntx->getListItemNumber();
            VappDtcntDisplayItemInfo *itemInfo;
            for (i = 0; i < acctNum; i++)
            {
                itemInfo = m_listCntx->getListInfo(i);

                if (VappDtcntDispItemList::isAccountInUse(itemInfo->getProfileId()) || itemInfo->getReadOnly())
                {
                    m_disableState[i] = VFX_TRUE;
                }
                else
                {
                    m_disableState[i] = VFX_FALSE;
                }
            }
            m_markAll = VFX_FALSE;
            m_listType = VAPP_DTCNT_LIST_TYPE_DELETE_ACCOUNT;
            str.loadFromRes(STR_ID_VAPP_DTCNT_DELETE_DATA_ACCOUNT);
            m_titleBar->setTitle(str);
            VFX_OBJ_CLOSE(m_toolBar);
            VFX_OBJ_CREATE(m_toolBar, VcpToolBar, page);
            str.loadFromRes(STR_GLOBAL_MARK_ALL);
            m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
            str.loadFromRes(STR_GLOBAL_DELETE);
            m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_DELETE, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
            str.loadFromRes(STR_GLOBAL_CANCEL);
            m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_CANCEL, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
            m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_DELETE, VFX_TRUE);

            VfxBool tmpFlag;
            tmpFlag = VFX_FALSE;
            for (i = 0; i < acctNum; i++)
            {
                if (!m_selectionState[i] && !m_disableState[i])
                {
                    tmpFlag = VFX_TRUE;
                    break;
                }
            }
            if (!tmpFlag)
            {
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL, VFX_TRUE);
            }
            
            page->setBottomBar(m_toolBar); 
            m_toolBar->m_signalButtonTap.connect(this, &VappDtcntListPage::onToolBarTapped); 
            m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
            //onUpdateListPage();
            m_listMenu->updateAllItems();
            break;
        }
        case VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL:
        {
            // change default page
            VfxU32 acctNum;
            acctNum = m_listCntx->getListItemNumber();
            for (i = 0; i < acctNum; i++)
            {
                if (!m_markAll)
                {
                    if (m_disableState[i])
                    {
                        continue;
                    }
                    m_selectionState[i] = VFX_TRUE;
                    m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_DELETE, VFX_FALSE);
                }
                else
                {
                    m_selectionState[i] = VFX_FALSE;
                    m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_DELETE, VFX_TRUE);
                }
            }
            if (!m_markAll)
            {
                str.loadFromRes(STR_GLOBAL_UNMARK_ALL);
                m_toolBar->changeItem(VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
                m_markAll = VFX_TRUE;
            }
            else
            {                
                str.loadFromRes(STR_GLOBAL_MARK_ALL);
                m_toolBar->changeItem(VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
                m_markAll = VFX_FALSE;
            }
            //onUpdateListPage();
            m_listMenu->updateAllItems();
            break;
        }
        case VAPP_DTCNT_LIST_TOOLBAR_ID_DELETE:
        {
            // delete account
            VcpConfirmPopup *confirmPopup;
            VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, page);
            confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            VfxU32 i, acctNum, deleteNum;
            acctNum = m_listCntx->getListItemNumber();
            deleteNum = 0;
            for (i = 0; i < acctNum; i++)
            {
                if (m_selectionState[i])
                {
                    deleteNum++;
                }
            }
            VfxWString str1, str2;
            WCHAR popupString[40];
            WCHAR *prefix;
            WCHAR *suffix;
            WCHAR numStr[4];
            prefix = (WCHAR*)GetString(STR_ID_VAPP_DTCNT_DELETE_ACCOUNT_PREFIX);
            suffix = (WCHAR*)GetString(STR_ID_VAPP_DTCNT_DELETE_ACCOUNT_SUFFIX);            
            kal_wsprintf(numStr, "%d", deleteNum);
            mmi_wcscpy(popupString, prefix);
            mmi_wcscat(popupString, numStr);
            mmi_wcscat(popupString, suffix);
            confirmPopup->setText(popupString);
            confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            str1.loadFromRes(STR_GLOBAL_DELETE);
            str2.loadFromRes(STR_GLOBAL_CANCEL);
            confirmPopup->setCustomButton(str1, str2, VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
            confirmPopup->show(VFX_FALSE);            
            confirmPopup->setAutoDestory(VFX_FALSE);
            confirmPopup->m_signalButtonClicked.connect(this, &VappDtcntListPage::onDeleteConfirm);
            break;
        }
        case VAPP_DTCNT_LIST_TOOLBAR_ID_CANCEL:
        {
            // cancel delete
            VFX_FREE_MEM(m_selectionState);
            VFX_FREE_MEM(m_disableState);
            if (VappDtcntSimAvailableInfo::getAvailableSimNum() < 2)
            {
                str.loadFromRes(STR_ID_VAPP_DTCNT);
            }
            else
            {
                str = VappDtcntDispItemList::getSimName((VfxU32)(m_simType - 1));
            }
            m_titleBar->setTitle(str);
            VFX_OBJ_CLOSE(m_toolBar);
            VFX_OBJ_CREATE(m_toolBar, VcpToolBar, page);
            m_listType = VAPP_DTCNT_LIST_TYPE_DISPLAY_ACCOUNT;
            str.loadFromRes(STR_GLOBAL_ADD);
            m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_ADD, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
            str.loadFromRes(STR_ID_VAPP_DTCNT_SET_DEFAULT);
            m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_CHANGE_DEFAULT, str, IMG_ID_VAPP_DTCNT_SET_DEFAULT);
            str.loadFromRes(STR_GLOBAL_DELETE);
            m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_DELETE, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
            page->setBottomBar(m_toolBar);
            if (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM == getAcctNumExcludeSimProv(m_simType))
            {
                m_toolBar->setDisableItem(VAPP_DTCNT_LIST_TOOLBAR_ID_ADD, VFX_TRUE);
            }
            m_toolBar->m_signalButtonTap.connect(this, &VappDtcntListPage::onToolBarTapped); 

            m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
            m_listMenu->updateAllItems();
            break;
        }
        default:
            break;
    }
}

VfxU8 VappDtcntListPage::getAcctNumExcludeSimProv(srv_dtcnt_sim_type_enum simType)
{
    srv_dtcnt_store_prof_qry_struct acctIdQuery;
    VfxU8 num = 0;

    acctIdQuery.qry_info.filters = SRV_DTCNT_STORE_QRY_TYPE_ACC_TYPE | SRV_DTCNT_STORE_QRY_TYPE_SIM;
    acctIdQuery.qry_info.sim_qry_info = simType;

    acctIdQuery.qry_info.acc_type_info = SRV_DTCNT_PROF_TYPE_USER_CONF;
    srv_dtcnt_store_qry_ids(&acctIdQuery);
    num += acctIdQuery.num_ids;
    
    acctIdQuery.qry_info.acc_type_info = SRV_DTCNT_PROF_TYPE_FACTORY_CONF;
    srv_dtcnt_store_qry_ids(&acctIdQuery);
    num += acctIdQuery.num_ids;
    
    acctIdQuery.qry_info.acc_type_info = SRV_DTCNT_PROF_TYPE_OTA_CONF;
    srv_dtcnt_store_qry_ids(&acctIdQuery);
    num += acctIdQuery.num_ids;
    
    return num;
}


void VappDtcntListPage::onBtnNotAllowDelete(
        VfxObject* sender,     // sender 
        VfxId id          // id
    )
{
    VfxWString str;
    VFX_FREE_MEM(m_selectionState);
    VFX_FREE_MEM(m_disableState);
    if (VappDtcntSimAvailableInfo::getAvailableSimNum() < 2)
    {
        str.loadFromRes(STR_ID_VAPP_DTCNT);
    }
    else
    {
        str = VappDtcntDispItemList::getSimName((VfxU32)(m_simType - 1));
    }
    m_titleBar->setTitle(str);
    VFX_OBJ_CLOSE(m_toolBar);
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, getPage());
    str.loadFromRes(STR_GLOBAL_ADD);
    m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_ADD, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
    str.loadFromRes(STR_ID_VAPP_DTCNT_SET_DEFAULT);
    m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_CHANGE_DEFAULT, str, IMG_ID_VAPP_DTCNT_SET_DEFAULT);
    str.loadFromRes(STR_GLOBAL_DELETE);
    m_toolBar->addItem(VAPP_DTCNT_LIST_TOOLBAR_ID_TO_DELETE, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    getPage()->setBottomBar(m_toolBar);
    m_toolBar->m_signalButtonTap.connect(this, &VappDtcntListPage::onToolBarTapped); 

    m_listCntx->prepareListInfo(m_simType, VAPP_DTCNT_LIST_PREPARE_TYPE_SETTING);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
    m_listMenu->resetAllItems(VFX_TRUE);
}


void VappDtcntListPage::onDeleteConfirm(
    VfxObject* obj, 
    VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        deleteSelectedAccount();
    }
}


void VappDtcntListPage::onCommandPopupAddAccount(
        VfxObject* sender,     // sender 
        VfxId id          // id
    )
{
    if (id == VAPP_DTCNT_ADD_ACCOUNT_TYPE_GPRS)
    {        
        VappDtcntGPRSPage *gprsPage;
        VFX_OBJ_CREATE_EX(gprsPage, VappDtcntGPRSPage, m_scr, (0, VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD, m_simType));
        m_scr->pushPage(0, gprsPage);
    }
#ifdef __TCPIP_OVER_CSD__
    else if (id == VAPP_DTCNT_ADD_ACCOUNT_TYPE_CSD)
    {
        VappDtcntCSDPage *csdPage;
        VFX_OBJ_CREATE_EX(csdPage, VappDtcntCSDPage, m_scr, (0, VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD, m_simType));
        m_scr->pushPage(0, csdPage);
    }
#endif
}

#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
void VappDtcntListPage::onSimChangeEvt(VfxBool flag, mmi_sim_enum sim)
{
    if(VFX_FALSE == flag)
    {
	VfxU32 simIndex = 0;
	simIndex = mmi_frm_sim_to_index(sim);
	if(simIndex == (VfxU32)(m_simType - 1))
	{
	    if(m_listType == VAPP_DTCNT_LIST_TYPE_DELETE_ACCOUNT)
	    {
		VFX_FREE_MEM(m_selectionState);
	        VFX_FREE_MEM(m_disableState);
	    }
            m_scr->closePage(getPage()->getId());
        }
    }
}
#endif


/***************************************************************************** 
 * Class VappDtcntSimListPage
 *****************************************************************************/

void VappDtcntSimListPage::onPageInit(VfxPageEx *page)
{
    VfxPageHandler::onPageInit(page);
 
    vapp_dtcnt_set_titlebar(STR_ID_VAPP_DTCNT, page);
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, page);
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemTapped.connect(this, &VappDtcntSimListPage::onListItemTapped);
    m_listMenu->setSize(page->getSize());
    setListMenuFormat(m_listMenu, VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT, VCP_LIST_MENU_MODE_NORMAL, VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__
    VFX_OBJ_GET_INSTANCE(VappDtcntSimAvailableListener)->m_signalSimChangedEvent.connect(this, &VappDtcntSimListPage::onSimChangeEvt);
#endif
}


VfxBool VappDtcntSimListPage::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
    )
{
    VfxU32 simIndex;
    simIndex = VappDtcntSimAvailableInfo::getAvailableSimIndex(index);

    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text = VappDtcntDispItemList::getSimName(simIndex);
    }
    return VFX_TRUE;
}


VfxU32 VappDtcntSimListPage::getCount() const
{
    return VappDtcntSimAvailableInfo::getAvailableSimNum();
}


VfxBool VappDtcntSimListPage::getItemImage(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxImageSrc &image              // [OUT] the image resource
    ) 
{
    if (VCP_LIST_MENU_FIELD_DISCLOSURE_IMG == fieldType)
    {
        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
    }
    else if (VCP_LIST_MENU_FIELD_HIGHLIGHT_DISCLOSURE_IMG == fieldType)
    {
        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_HIGHLIGHT_DISCLOSURE);
    }
    return VFX_TRUE;
}

void VappDtcntSimListPage::onListItemTapped(
       VcpListMenu *sender, // Sender
       VfxU32 index        // List item index
   )
{
    VfxU32 simIndex;
    simIndex = VappDtcntSimAvailableInfo::getAvailableSimIndex(index);
    VappDtcntListPage *m_listPage;
    srv_dtcnt_sim_type_enum simType;
    simType = (srv_dtcnt_sim_type_enum)(simIndex + 1);
    VFX_OBJ_CREATE_EX(m_listPage, VappDtcntListPage, m_scr, (simType, m_scr));
    m_scr->pushPageHandler(0, m_listPage);
}

#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
void VappDtcntSimListPage::onSimChangeEvt(VfxBool flag, mmi_sim_enum sim)
{

    if(VappDtcntSimAvailableInfo::getAvailableSimNum() > 1)
    {
	m_listMenu->resetAllItems();
    }
    else
    {
        m_scr->closePage(getPage()->getId());
    }
}
#endif

/***************************************************************************** 
 * Class VappDtcntScreen
 *****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif
/***************************************************************************** 
 * Class VappDtcntApp
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDtcntApp", VappDtcntApp, VfxCui);

void VappDtcntApp::onDeinit()
{
    VFX_TRACE(("VappDtcntApp::onDeinit"));

    VfxCui::onDeinit();
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_B__)
    DCM_Unload(DYNAMIC_CODE_COMPRESS_COSMOS_DTCNT);
#endif
}



void VappDtcntApp::onRun(void* args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);

    VfxMainScrEx *scr;
    VFX_OBJ_CREATE_EX(scr, VfxMainScrEx, this, (this));
    scr->show();
}

void VappDtcntApp::onScr1stReady(VfxMainScrEx *scr)
{
    VfxU32 availSim;
    availSim = VappDtcntSimAvailableInfo::getAvailableSimNum();

    if (availSim > 1)
    {
        // push page
        VappDtcntSimListPage *simListPage;
        VFX_OBJ_CREATE_EX(simListPage, VappDtcntSimListPage, scr, (scr));
        scr->pushPageHandler(0, simListPage);
    }
    else
    {
        // push page
        MMI_BOOL ret;
        srv_dtcnt_sim_type_enum simType = SRV_DTCNT_SIM_TYPE_1;
        ret = srv_dtcnt_get_sim_preference(&simType); // data connection sim
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_SIM_PREFERENCE, simType, ret);
        VappDtcntListPage *m_listPage;
        VFX_OBJ_CREATE_EX(m_listPage, VappDtcntListPage, scr, (simType, scr));
        scr->pushPageHandler(0, m_listPage);        
    }
}

#pragma arm section code, rodata

// setting framework
/***************************************************************************** 
 * Class VappDtcntSettingCell
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDtcntSettingCell", VappDtcntSettingCell, VcpFormItemLauncherCell);

void VappDtcntSettingCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    setMainText(STR_ID_VAPP_DTCNT);
    setHintText(STR_ID_VAPP_DTCNT_DATA_ACCOUNT_ENTRY_HINT);
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_signalTap.connect(this, &VappDtcntSettingCell::onTap);
    if (!srv_sim_ctrl_any_sim_is_available())
    {
        setIsDisabled(VFX_TRUE);
    }
    else
    {
        setIsDisabled(VFX_FALSE);
    }
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__	
    VFX_OBJ_GET_INSTANCE(VappDtcntSimAvailableListener)->m_signalSimChangedEvent.connect(this, &VappDtcntSettingCell::onSimChangeEvt);
#endif
}


void VappDtcntSettingCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{
    VfxMainScr *mainScr;
    mmi_id settingCuiId;
    mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);
    if (mainScr)
    {
        VfxApp *app = mainScr->getApp();
        settingCuiId = vcui_dtcnt_setting_create(app->getGroupId(), NULL);
        vcui_dtcnt_setting_run(settingCuiId);
    }
}

#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
void VappDtcntSettingCell::onSimChangeEvt(VfxBool flag, mmi_sim_enum sim)
{
    if(VappDtcntSimAvailableInfo::getAvailableSimNum() == 0)
    {
        setIsDisabled(VFX_TRUE);
    }
    else
    {
        setIsDisabled(VFX_FALSE);
    }
}
#endif

void textEditorState(VcpForm *form, VfxId ActiveId, VfxBool isActived)
{
    VcpFormItemTextInput* textInput;
    VcpTextEditor *editor;
    textInput = (VcpFormItemTextInput*)(form->getItem(ActiveId));
    editor = textInput->getTextBox();
    if(isActived)
    {
        editor->activate();
    }
    else
    {
        editor->deactivate();
    }
}

#endif
