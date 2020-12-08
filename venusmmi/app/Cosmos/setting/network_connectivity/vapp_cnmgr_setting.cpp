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
 *  
 *
 * Project:
 * --------
 *  Cosmos
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __TCPIP__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_cnmgr_setting.h"

// Resource
#include "mmi_rp_vapp_setting_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h" 
// Data account
#include "vapp_dtcnt_gprot.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "MMI_features.h"
#include "cbm_api.h"
#include "cbm_consts.h"
#include "CnmgrSrvGprot.h"
#include "CnmgrSrvIprot.h"
#include "DtcntSrvGprot.h"
#include "GlobalResDef.h"
#include "l4c_common_enum.h"
#include "kal_trace.h"

#ifdef __cplusplus
}
#endif

#ifdef __MMI_CBM_CONNECTION_MANAGER__

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/***************************************************************************** 
 * Class VappCnmgrApp
 *****************************************************************************/

extern "C" void vapp_cnmgr_launch(void)
{
    VfxAppLauncher::launch( 
        VAPP_CNMGR,
        VFX_OBJ_CLASS_INFO(VappCnmgrApp),
        GRP_ID_ROOT);
}

VFX_IMPLEMENT_CLASS("VappCnmgrApp", VappCnmgrApp, VfxApp);

void VappCnmgrApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappCnmgrScreen *scr;
    VFX_OBJ_CREATE(scr, VappCnmgrScreen, this);
    scr->show();
}

VFX_IMPLEMENT_CLASS("VappCnmgrScreen", VappCnmgrScreen, VfxMainScr);

void VappCnmgrScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VappCnmgrBearerListPage *bearerListPage;
    VFX_OBJ_CREATE(bearerListPage, VappCnmgrBearerListPage, this);
    pushPage(0, bearerListPage);
}

/***************************************************************************** 
 * Class VappCnmgrSettingCell
 *****************************************************************************/
/*
VFX_IMPLEMENT_CLASS("VappCnmgrSettingCell", VappCnmgrSettingCell, VcpFormItemLauncherCell);
void VappCnmgrSettingCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    m_signalTap.connect(this, &VappCnmgrSettingCell::onTap);
    setMainText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_CONNECTION_MANAGEMENT));
    setHintText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_SETTING_HINT));
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
}

void VappCnmgrSettingCell::onTap(VcpFormItemCell *sender, VfxId senderId)
{
    // Entry connection list page
    VappCnmgrBearerListPage *bearerListPage;
    
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);
    if (mainScr)
	{
		VFX_OBJ_CREATE(bearerListPage, VappCnmgrBearerListPage, mainScr);
		mainScr->pushPage(0, bearerListPage);	
	}    
}
*/

/***************************************************************************** 
 * Class VappCnmgrBearerListPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappCnmgrBearerListPage", VappCnmgrBearerListPage, VfxPage);
VappCnmgrBearerListPage::VappCnmgrBearerListPage() :
                            m_listMenu(NULL),
                            m_textNoConnection(NULL),
                            m_titleBar(NULL),
                            m_toolBar(NULL),
                            m_confirmPopup(NULL),
                            m_confirmPopupPtr(NULL),
                            m_indicatorPopup(NULL),
                            m_errorPopup(NULL),
                            m_discAll(VFX_FALSE),
                            m_activeNum(0)
{
    memset(&m_bearerList, 0, sizeof(vapp_cnmgr_bearer_list_struct));
}

void VappCnmgrBearerListPage::onInit()
{
    VfxPage::onInit();

    // Create title bar
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_CONNECTION_MANAGEMENT));
    setTopBar(m_titleBar);

    // Create tool bar
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(this, &VappCnmgrBearerListPage::onToolBarTap);
    m_toolBar->addItem(0, VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_DISCONNECT_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_REMOVE);
    setBottomBar(m_toolBar);

    // Get active bearer list and update bearer list page
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_listMenu->setContentProvider(this);
    m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);
    m_listMenu->setSize(getSize());
    m_listMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->m_signalItemTapped.connect(this, &VappCnmgrBearerListPage::onSelectItem);
	//reset
    reset();
}

void VappCnmgrBearerListPage::onDeinit()
{
    VfxPage::onDeinit();
}

void VappCnmgrBearerListPage::onEnter(VfxBool isBackward)
{
    // Get active bearer list and update bearer list page
    if (isBackward)
    {
        reset();
    }
}

void VappCnmgrBearerListPage::onEntered()
{
    // Register bearer list update callback
    srv_cnmgr_register_bearer_data_update_notify(
        SRV_CNMGR_DATA_UPDATE_INTERVAL_1_SEC,
        &VappCnmgrBearerListPage::refreshPage,
        getObjHandle());
}

void VappCnmgrBearerListPage::onExit(VfxBool isBackward)
{
    // Deregister bearer list update callback
    srv_cnmgr_deregister_bearer_data_update_notify(&VappCnmgrBearerListPage::refreshPage, getObjHandle());
}

void VappCnmgrBearerListPage::reset(void)
{
    MMI_TRACE(VAPP_CNMGR_TRC_GROUP, VAPP_CNMGR_LIST_RESET);
	m_activeNum = m_bearerList.bearer_num;
    updateBearerList();
    if (m_bearerList.bearer_num > 0)
    {	
         toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_TRUE);
    }
    else
    {
         toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_FALSE);
        if(m_confirmPopupPtr.isValid())
        {
            VFX_OBJ_CLOSE(m_confirmPopup);
        }
     }
    //m_listMenu->resetAllItems();
    if(m_activeNum == m_bearerList.bearer_num)
    {
    	m_listMenu->updateAllItems();
    }
	else
	{
    m_listMenu->resetAllItems();
}
}

void VappCnmgrBearerListPage::updateBearerList(void)
{
    // Get active bearer list
    srv_cnmgr_bearer_list_struct activeBearerList;
    VfxWChar dest[MAX_DATA_ACCOUNT_NAME_LEN + 1];
    cbm_bearer_enum bearer;
    VfxS32 i;

    srv_cnmgr_get_active_bearer_list(&activeBearerList);

    MMI_TRACE(VAPP_CNMGR_TRC_GROUP,
              VAPP_CNMGR_LIST_UPDATE_BEARER_LIST,
              activeBearerList.active_node_num);

    m_bearerList.bearer_num = activeBearerList.active_node_num;
    for (i = 0; i < activeBearerList.active_node_num; i++)
    {
        m_bearerList.bearer[i].account_id = activeBearerList.node[i].account_id;
        m_bearerList.bearer[i].connect_type = activeBearerList.node[i].connect_type;
        m_bearerList.bearer[i].all_data_size = activeBearerList.node[i].all_data_size;
        m_bearerList.bearer[i].connect_time = activeBearerList.node[i].connect_time;
        m_bearerList.bearer[i].dialup_type = activeBearerList.node[i].dialup_type;

        // Get profile name of each bearer
        cbm_get_bearer_type(m_bearerList.bearer[i].account_id, &bearer);

        if (bearer & CBM_WIFI)
        {
            m_bearerList.bearer[i].profile_name = VFX_WSTR_RES(STR_GLOBAL_WIFI);
        }
        else if (m_bearerList.bearer[i].connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP)
        {
            m_bearerList.bearer[i].profile_name = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_TYPE_DIALUP);
        }
        else
        {
            memset(dest, 0, sizeof(dest));
            vapp_dtcnt_get_full_account_name(
                m_bearerList.bearer[i].account_id,
                dest,
                (MAX_DATA_ACCOUNT_NAME_LEN + 1)*ENCODING_LENGTH,
                VAPP_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
            m_bearerList.bearer[i].profile_name = VFX_WSTR_MEM(dest);
        }
    }
}

void VappCnmgrBearerListPage::refreshPage(void *userData)
{
    VappCnmgrBearerListPage *listPage = (VappCnmgrBearerListPage*)VfxObject::handleToObject((VfxObjHandle)userData);

    if (listPage)
    {
        MMI_TRACE(VAPP_CNMGR_TRC_GROUP, VAPP_CNMGR_LIST_REFRESH_PAGE);
        VFX_DEV_ASSERT(listPage->isKindOf(VFX_OBJ_CLASS_INFO(VappCnmgrBearerListPage)));

        if (listPage->getDiscAll() == VFX_FALSE)
        {
            listPage->reset();
        }
    }
}

VfxU32 VappCnmgrBearerListPage::getCount() const
{
    // Return the number of bearers
    return m_bearerList.bearer_num;
}

VfxBool VappCnmgrBearerListPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
	if (index < getCount())
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)	
		{
            text = m_bearerList.bearer[index].profile_name;
            return VFX_TRUE;
		}
        else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        {
            if (m_bearerList.bearer[index].connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP &&
                m_bearerList.bearer[index].dialup_type == CSD_BEARER_DIALUP)
            {
                VfxS32 hour, min, sec;

                hour = (VfxS32)(m_bearerList.bearer[index].connect_time / VAPP_CNMGR_HOUR_TO_SEC);
                min = (m_bearerList.bearer[index].connect_time % VAPP_CNMGR_HOUR_TO_SEC) / VAPP_CNMGR_MIN_TO_SEC;
                sec = m_bearerList.bearer[index].connect_time % VAPP_CNMGR_MIN_TO_SEC;

                text.format("%02d:%02d:%02d", hour, min, sec);
            }
            else
            {
                VfxFloat dataSize = (VfxFloat)m_bearerList.bearer[index].all_data_size / VAPP_CNMGR_DATA_UNIT_SIZE;
                text.format("%0.2fKB", dataSize);
            }
            return VFX_TRUE;
        }
	}
	return VFX_FALSE;
}

VfxBool VappCnmgrBearerListPage::getItemImage(VfxU32 index,VcpListMenuFieldEnum fieldType,VfxImageSrc &image)
{
	if (index < getCount())
	{
		if (fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
		{
		    image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
            return VFX_TRUE;
		} 
	}
	return VFX_FALSE;
}

VfxBool VappCnmgrBearerListPage::getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
{
    text.loadFromRes(STR_ID_VAPP_SETTING_CNMGR_NO_CONNECTION);
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}

void VappCnmgrBearerListPage::onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx)
{
    // Check if bearer is still valid first
    srv_cnmgr_bearer_id_struct bearer;
    srv_cnmgr_bearer_data_struct bearerData;

    bearer.account_id = m_bearerList.bearer[selectIdx].account_id;
    bearer.connect_type = m_bearerList.bearer[selectIdx].connect_type;

    if (srv_cnmgr_get_bearer_connection_data(&bearer, &bearerData) == SRV_CNMGR_RESULT_SUCCESS)
    {
        // Check bearer status
        if (bearerData.bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
        {
            // Entry detail info page
            VappCnmgrBearerDetailInfoPage *bearerDetailInfoPage;
            
            VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);
            if (mainScr)
        	{
        		VFX_OBJ_CREATE_EX(
                    bearerDetailInfoPage,
                    VappCnmgrBearerDetailInfoPage,
                    mainScr,
                    (m_bearerList.bearer[selectIdx].account_id,
                     m_bearerList.bearer[selectIdx].connect_type,
                     m_bearerList.bearer[selectIdx].dialup_type,
                     m_bearerList.bearer[selectIdx].profile_name));
        		mainScr->pushPage(0, bearerDetailInfoPage);	
        	}
        }
        else if (bearerData.bearer_status == SRV_CNMGR_BEARER_STATUS_DEACTIVATING)
        {
            // Bearer is in deactivating state. User can see bearer detail info only if bearer is activated.
            displayErrorPopup(VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_DISCONNECTING));
        }
        else
        {
            displayErrorPopup(VFX_WSTR_RES(STR_GLOBAL_UNFINISHED));
        }
    }
    else
    {
        // Bearer is not valid anymore
        displayErrorPopup(VFX_WSTR_RES(STR_GLOBAL_UNFINISHED));
    }
}

void VappCnmgrBearerListPage::onToolBarTap(VfxObject *sender, VfxId id)
{
    if (id == 0)
    {
        // Display confirmation popup
        VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, getMainScr());
        m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        m_confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_DISCONEECT_ALL_CONFIRM));
        m_confirmPopup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        m_confirmPopup->setCustomButton(VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_DISCONNECT_ALL), VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_NORMAL, VCP_POPUP_BUTTON_TYPE_CANCEL);
        m_confirmPopup->setAutoDestory(VFX_TRUE);
        m_confirmPopup->m_signalButtonClicked.connect(this, &VappCnmgrBearerListPage::onDiscAllPopupBtnTap);
        m_confirmPopup->show(VFX_TRUE);
        m_confirmPopupPtr = m_confirmPopup;
    }
}

void VappCnmgrBearerListPage::onDiscAllPopupBtnTap(VfxObject *sender, VfxId id)
{
    if (id == 'USR1')
	{
	    // Disconnect all bearer
	    srv_cnmgr_result_enum result = srv_cnmgr_disconnect_all_bearer(&VappCnmgrBearerListPage::discAllDone, getObjHandle());

        if (result == SRV_CNMGR_RESULT_WAIT_FOR_RSP)
        {
            setDiscAll(VFX_TRUE);

            // Display indicator popup
            VFX_OBJ_CREATE(m_indicatorPopup, VcpIndicatorPopup, getMainScr());
            m_indicatorPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            m_indicatorPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_DISCONNECTING));
            m_indicatorPopup->setAutoDestory(VFX_FALSE);
            m_indicatorPopup->show(VFX_TRUE);
        }
        else if (result == SRV_CNMGR_RESULT_NO_CONNECTION)
        {
            reset();
        }
	}
    else if (id == 'USR2')
    {
        reset();
    }
}

void VappCnmgrBearerListPage::discAllDone(VfxU8 result, void *userData)
{
    VappCnmgrBearerListPage *listPage = (VappCnmgrBearerListPage*)VfxObject::handleToObject((VfxObjHandle)userData);

    if (listPage)
    {
        VFX_DEV_ASSERT(listPage->isKindOf(VFX_OBJ_CLASS_INFO(VappCnmgrBearerListPage)));
        listPage->setDiscAll(VFX_FALSE);
        listPage->closeIndicatorPopup();

        if (result == SRV_CNMGR_RESULT_SUCCESS)
        {
            listPage->reset();            
        }
        else
        {
            listPage->displayErrorPopup(VFX_WSTR_RES(STR_GLOBAL_UNFINISHED));
        }
    }
}

void VappCnmgrBearerListPage::closeIndicatorPopup()
{
    if (m_indicatorPopup != NULL)
    {
        m_indicatorPopup->hide(VFX_TRUE);
        VFX_OBJ_CLOSE(m_indicatorPopup);
    }
}

void VappCnmgrBearerListPage::displayErrorPopup(const VfxWString &text)
{
    VFX_OBJ_CLOSE(m_errorPopup);

    VFX_OBJ_CREATE(m_errorPopup, VcpConfirmPopup, getMainScr());
    m_errorPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    m_errorPopup->setText(text);
    m_errorPopup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_errorPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    m_errorPopup->setAutoDestory(VFX_TRUE);
    m_errorPopup->m_signalButtonClicked.connect(this, &VappCnmgrBearerListPage::onErrorPopupBtnTap);
    m_errorPopup->show(VFX_TRUE);
}

void VappCnmgrBearerListPage::onErrorPopupBtnTap(VfxObject *sender, VfxId id)
{
    reset();
}


/***************************************************************************** 
 * Class VappCnmgrBearerDetailInfoPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappCnmgrBearerDetailInfoPage", VappCnmgrBearerDetailInfoPage, VfxPage);
VappCnmgrBearerDetailInfoPage::VappCnmgrBearerDetailInfoPage() : 
                                	m_accountId(0),
                                	m_connectType(0),
                                	m_dialupType(0),
                                	m_profileName(VFX_WSTR_NULL),
                                	m_listMenu(NULL),
                                	m_titleBar(NULL),
                                	m_toolBar(NULL),
                                	m_confirmPopup(NULL),
                                	m_indicatorPopup(NULL),
                                	m_detailFilter(0)
{
    memset(&m_bearerData, 0, sizeof(vapp_cnmgr_bearer_detail_info_struct));
    m_bearerData.setting = VFX_WSTR_NULL;
}

VappCnmgrBearerDetailInfoPage::VappCnmgrBearerDetailInfoPage(const VfxU32 &accountId, const VfxU8 &connectType, const VfxU8 &dialupType, const VfxWString &profileName) : 
                                	m_accountId(accountId),
                                	m_connectType(connectType),
                                	m_dialupType(dialupType),
                                	m_profileName(profileName),
                                	m_listMenu(NULL),
                                	m_titleBar(NULL),
                                	m_toolBar(NULL),
                                	m_confirmPopup(NULL),
                                        m_confirmPopupPtr(NULL),
                                	m_indicatorPopup(NULL),
                                	m_detailFilter(0)
{
    memset(&m_bearerData, 0, sizeof(vapp_cnmgr_bearer_detail_info_struct));
    m_bearerData.setting = VFX_WSTR_NULL;
}

void VappCnmgrBearerDetailInfoPage::onInit()
{
    VfxPage::onInit();

    // Get bearer connection data
    getBearerData();

    // Create title bar
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(m_profileName);
    setTopBar(m_titleBar);

    // Create tool bar
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(this, &VappCnmgrBearerDetailInfoPage::onToolBarTap);
    m_toolBar->addItem(0, VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_DISCONNECT), VCP_IMG_TOOL_BAR_COMMON_ITEM_REMOVE);
    setBottomBar(m_toolBar);

    // Create list menu
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_listMenu->setContentProvider(this);
    m_listMenu->setSize(getSize());
    m_listMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->setItemHighlightHidden(VFX_TRUE);
}

void VappCnmgrBearerDetailInfoPage::onDeinit()
{
    // Deregister bearer data update callback
    srv_cnmgr_deregister_bearer_data_update_notify(&VappCnmgrBearerDetailInfoPage::refreshPage, getObjHandle());
    srv_cnmgr_deregister_bearer_data_update_notify(&VappCnmgrBearerDetailInfoPage::updateData, getObjHandle());

    VfxPage::onDeinit();
}

void VappCnmgrBearerDetailInfoPage::getBearerData()
{
    // Get bearer connection data
    srv_cnmgr_bearer_data_struct bearerData;
    srv_cnmgr_bearer_id_struct bearer;

    bearer.account_id = m_accountId;
    bearer.connect_type = m_connectType;
    
    if (srv_cnmgr_get_bearer_connection_data(&bearer, &bearerData) == SRV_CNMGR_RESULT_SUCCESS)
    {
        MMI_TRACE(VAPP_CNMGR_TRC_GROUP,
                  VAPP_CNMGR_DETAIL_GET_BEARER_DATA,
                  1,
                  m_accountId,
                  bearerData.bearer_status);
        m_bearerData.connect_time = bearerData.connect_time;
        m_bearerData.all_data_size = bearerData.all_data_size;
        m_bearerData.recv_data_size = bearerData.recv_data_size;
        m_bearerData.sent_data_size = bearerData.sent_data_size;
        m_bearerData.upload_rate = bearerData.upload_rate;
        m_bearerData.download_rate = bearerData.download_rate;
        m_bearerData.bearer_status = bearerData.bearer_status;

        cbm_get_bearer_type(m_accountId, &m_bearerData.bearer_type);

        if (m_connectType == SRV_CNMGR_CONNECT_TYPE_LOCAL)
        {
            if (m_bearerData.bearer_type & CBM_CSD)
            {
                srv_dtcnt_prof_str_info_qry_struct acctData;
                VfxWChar dest[SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN + 1];

                acctData.dest_len = (SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN + 1) * sizeof(VfxWChar);
                acctData.dest = (S8*)dest;
                srv_dtcnt_get_csd_number(m_accountId, &acctData, SRV_DTCNT_ACCOUNT_PRIMARY);

                m_bearerData.setting = VFX_WSTR_MEM(dest);
            }
            else if (m_bearerData.bearer_type & CBM_PS)
            {
                srv_dtcnt_prof_str_info_qry_struct acctData;
                VfxWChar dest[SRV_DTCNT_PROF_MAX_APN_LEN + 1];

                acctData.dest_len = (SRV_DTCNT_PROF_MAX_APN_LEN + 1) * sizeof(VfxWChar);
                acctData.dest = (S8*)dest;
                srv_dtcnt_get_apn(m_accountId, &acctData, SRV_DTCNT_ACCOUNT_PRIMARY);

                m_bearerData.setting = VFX_WSTR_MEM(dest);
            }
            else
            {
                // Not show the first field (APN or Number) for Wi-Fi bearer
                m_detailFilter |= VAPP_CNMGR_DETAIL_FILTER_NO_SETTING;
            }
        }
        else
        {
            if (m_dialupType == CSD_BEARER_DIALUP)
            {
                // Not show the first field (APN or Number) and transmission data fields for CSD dial-up bearer
                m_detailFilter |= VAPP_CNMGR_DETAIL_FILTER_NO_SETTING;
                m_detailFilter |= VAPP_CNMGR_DETAIL_FILTER_NO_TRANSMISSION_DATA;
            }
            else
            {
                // Not show the first field (APN or Number) for dial-up bearer
                m_detailFilter |= VAPP_CNMGR_DETAIL_FILTER_NO_SETTING;
            }
        }
    }
    else
    {
        MMI_TRACE(VAPP_CNMGR_TRC_GROUP,
                  VAPP_CNMGR_DETAIL_GET_BEARER_DATA,
                  0,
                  m_accountId,
                  m_bearerData.bearer_status);
        m_bearerData.bearer_status = SRV_CNMGR_BEARER_STATUS_DEACTIVE;
    }
}

void VappCnmgrBearerDetailInfoPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(VAPP_CNMGR_TRC_GROUP,
              VAPP_CNMGR_DETAIL_ONENTER,
              isBackward,
              m_bearerData.bearer_status);

    // Get bearer data
    getBearerData();

    // Update screen
    redrawPage();
}

void VappCnmgrBearerDetailInfoPage::onEntered()
{
    // Deregister bearer data update callback
    srv_cnmgr_deregister_bearer_data_update_notify(&VappCnmgrBearerDetailInfoPage::updateData, getObjHandle());

    // Register bearer data update callback
    srv_cnmgr_register_bearer_data_update_notify(
        SRV_CNMGR_DATA_UPDATE_INTERVAL_1_SEC,
        &VappCnmgrBearerDetailInfoPage::refreshPage,
        getObjHandle());
}

void VappCnmgrBearerDetailInfoPage::onExit(VfxBool isBackward)
{
    // Deregister bearer data update callback
    srv_cnmgr_deregister_bearer_data_update_notify(&VappCnmgrBearerDetailInfoPage::refreshPage, getObjHandle());

    // Register bearer data update callback
    srv_cnmgr_register_bearer_data_update_notify(
        SRV_CNMGR_DATA_UPDATE_INTERVAL_DEFAULT_VALUE,
        &VappCnmgrBearerDetailInfoPage::updateData,
        getObjHandle());
}

VfxU32 VappCnmgrBearerDetailInfoPage::getCount() const
{
    VfxU32 menuItemNum = VAPP_CNMGR_DETAIL_INFO_TOTAL;

    if (m_detailFilter & VAPP_CNMGR_DETAIL_FILTER_NO_SETTING)
    {
        // Not show the first field (APN or Number)
        menuItemNum -= 1;
    }

    if (m_detailFilter & VAPP_CNMGR_DETAIL_FILTER_NO_TRANSMISSION_DATA)
    {
        // Not show transmission data fields
        menuItemNum -= (VAPP_CNMGR_DETAIL_INFO_DOWNLOAD_RATE - VAPP_CNMGR_DETAIL_INFO_ALL_DATA_SIZE + 1);
    }

    return menuItemNum;
}

VfxBool VappCnmgrBearerDetailInfoPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    if (index >= getCount())
    {
        return VFX_FALSE;
    }

    VfxU32 mapIdx = index;

    if (m_detailFilter & VAPP_CNMGR_DETAIL_FILTER_NO_SETTING)
    {
        mapIdx += 1;
    }

    switch (mapIdx)
    {
        case VAPP_CNMGR_DETAIL_INFO_SETTING:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    		{
    		    if (m_bearerData.bearer_type & CBM_PS)
                {
                    text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_APN);
                }
                else if (m_bearerData.bearer_type & CBM_CSD)
                {
                    text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_NUMBER);
                }
                else
                {
                    return VFX_FALSE;
                }
     		}
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                if (m_bearerData.bearer_type & CBM_PS ||
                    m_bearerData.bearer_type & CBM_CSD)
                {
                    text = m_bearerData.setting;
                }
                else
                {
                    return VFX_FALSE;
                }
            }
            break;
        }

        case VAPP_CNMGR_DETAIL_INFO_TYPE:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    		{
    		    text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_TYPE);
     		}
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                if (m_connectType == SRV_CNMGR_CONNECT_TYPE_LOCAL)
                {
                    if (m_bearerData.bearer_type & CBM_PS)
                    {
                        text = VFX_WSTR_RES(STR_GLOBAL_GPRS);
                    }
                    else if (m_bearerData.bearer_type & CBM_CSD)
                    {
                        text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_TYPE_CSD);
                    }
                    else if (m_bearerData.bearer_type & CBM_WIFI)
                    {
                        text = VFX_WSTR_RES(STR_GLOBAL_WIFI);
                    }
                    else
                    {
                        text = VFX_WSTR_RES(STR_GLOBAL_INVALID);
                    }
                }
                else
                {
                    text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_TYPE_DIALUP);
                }
            }
            break;
        } 

        case VAPP_CNMGR_DETAIL_INFO_CONNECT_STATUS:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    		{
    		    text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_CONNECTION_STATUS);
     		}
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                if (m_bearerData.bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
                {
                    if (m_bearerData.upload_rate == 0 &&
                        m_bearerData.download_rate == 0)
                    {
                        text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_NO_TRANSFER);
                    }
                    else
                    {
                        text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_TRANSFERRING);
                    }
                }
                else
                {
                    text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_DISCONNECTED);
                }
            }
            break;
        }

        case VAPP_CNMGR_DETAIL_INFO_CONNECT_TIME:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    		{
    		    text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_CONNECTION_TIME);
     		}
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                VfxS32 hour, min, sec;

                hour = (VfxS32)(m_bearerData.connect_time / VAPP_CNMGR_HOUR_TO_SEC);
                min = (m_bearerData.connect_time % VAPP_CNMGR_HOUR_TO_SEC) / VAPP_CNMGR_MIN_TO_SEC;
                sec = m_bearerData.connect_time % VAPP_CNMGR_MIN_TO_SEC;

                text.format("%02d:%02d:%02d", hour, min, sec);
            }
            break;
        }

        case VAPP_CNMGR_DETAIL_INFO_ALL_DATA_SIZE:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    		{
    		    text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_ALL_DATA_SIZE);
     		}
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                VfxDoube dataSize = (VfxFloat)m_bearerData.all_data_size / VAPP_CNMGR_DATA_UNIT_SIZE;

                text.format("%0.2fKB", dataSize);
            }
            break;
        }

        case VAPP_CNMGR_DETAIL_INFO_RECV_DATA_SIZE:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    		{
    		    text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_RECV_DATA_SIZE);
     		}
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                VfxDoube dataSize = (VfxFloat)m_bearerData.recv_data_size / VAPP_CNMGR_DATA_UNIT_SIZE;

                text.format("%0.2fKB", dataSize);
            }
            break;
        }

        case VAPP_CNMGR_DETAIL_INFO_SENT_DATA_SIZE:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    		{
    		    text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_SENT_DATA_SIZE);
     		}
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                VfxFloat dataSize = (VfxFloat)m_bearerData.sent_data_size / VAPP_CNMGR_DATA_UNIT_SIZE;

                text.format("%0.2fKB", dataSize);
            }
            break;
        }

        case VAPP_CNMGR_DETAIL_INFO_UPLOAD_RATE:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    		{
    		    text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_UPLOAD_RATE);
     		}
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                VfxFloat dataSize = (VfxFloat)m_bearerData.upload_rate / VAPP_CNMGR_DATA_UNIT_SIZE;

                text.format("%0.2fKB/s", dataSize);
            }
            break;
        }

        case VAPP_CNMGR_DETAIL_INFO_DOWNLOAD_RATE:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    		{
    		    text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_DOWNLOAD_RATE);
     		}
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                VfxFloat dataSize = (VfxFloat)m_bearerData.download_rate / VAPP_CNMGR_DATA_UNIT_SIZE;

                text.format("%0.2fKB/s", dataSize);
            }
            break;
        }

        default:
            return VFX_FALSE;
    }
 
	return VFX_TRUE;
}

void VappCnmgrBearerDetailInfoPage::updateData(void *userData)
{
    VappCnmgrBearerDetailInfoPage *page = (VappCnmgrBearerDetailInfoPage*)VfxObject::handleToObject((VfxObjHandle)userData);

    if (page)
    {
        MMI_TRACE(VAPP_CNMGR_TRC_GROUP, VAPP_CNMGR_DETAIL_UPDATE_DATA);
        VFX_DEV_ASSERT(page->isKindOf(VFX_OBJ_CLASS_INFO(VappCnmgrBearerDetailInfoPage)));

        page->getBearerData();
    }
}

void VappCnmgrBearerDetailInfoPage::refreshPage(void *userData)
{
    VappCnmgrBearerDetailInfoPage *page = (VappCnmgrBearerDetailInfoPage*)VfxObject::handleToObject((VfxObjHandle)userData);

    if (page)
    {
        MMI_TRACE(VAPP_CNMGR_TRC_GROUP, VAPP_CNMGR_DETAIL_REFRESH_PAGE);
        VFX_DEV_ASSERT(page->isKindOf(VFX_OBJ_CLASS_INFO(VappCnmgrBearerDetailInfoPage)));

        page->getBearerData();
        page->redrawPage();
    }
}

void VappCnmgrBearerDetailInfoPage::redrawPage()
{
    MMI_TRACE(VAPP_CNMGR_TRC_GROUP, VAPP_CNMGR_DETAIL_REDRAW_PAGE, m_bearerData.bearer_status);

    // Disable "Disconnect" button if bearer status is disconnected
    if (m_bearerData.bearer_status != SRV_CNMGR_BEARER_STATUS_ACTIVE)
    {
        m_toolBar->setDisableItem(0, VFX_TRUE);
        if(m_confirmPopupPtr.isValid())
        {
            VFX_OBJ_CLOSE(m_confirmPopup);
        }
    }
    else
    {
        m_toolBar->setDisableItem(0, VFX_FALSE);
    }

    m_listMenu->updateAllItems();
}

void VappCnmgrBearerDetailInfoPage::onToolBarTap(VfxObject *sender, VfxId id)
{
    if (id == 0)
    {
        // Display confirmation popup
        VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, getMainScr());
        m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        m_confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_DISCONEECT_CONFIRM));
        m_confirmPopup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        m_confirmPopup->setCustomButton(VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_DISCONNECT), VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_NORMAL, VCP_POPUP_BUTTON_TYPE_CANCEL);
        m_confirmPopup->setAutoDestory(VFX_TRUE);
        m_confirmPopup->m_signalButtonClicked.connect(this, &VappCnmgrBearerDetailInfoPage::onDiscPopupBtnTap);
        m_confirmPopup->show(VFX_TRUE);
        m_confirmPopupPtr = m_confirmPopup;
    }
}

void VappCnmgrBearerDetailInfoPage::onDiscPopupBtnTap(VfxObject *sender, VfxId id)
{
    if (id == 'USR1')
	{
	    // Disconnect bearer
	    srv_cnmgr_bearer_id_struct bearer;

        bearer.account_id = m_accountId;
        bearer.connect_type = m_connectType;
	    srv_cnmgr_result_enum result = srv_cnmgr_disconnect_bearer(&bearer, &VappCnmgrBearerDetailInfoPage::discDone, getObjHandle());

        if (result == SRV_CNMGR_RESULT_WAIT_FOR_RSP)
        {
            // Display indicator popup
            VFX_OBJ_CREATE(m_indicatorPopup, VcpIndicatorPopup, getMainScr());
            m_indicatorPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            m_indicatorPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_CNMGR_DISCONNECTING));
            m_indicatorPopup->setAutoDestory(VFX_FALSE);
            m_indicatorPopup->show(VFX_TRUE);
        }
        else
        {
            // Exit bearer detail info page
            getMainScr()->popPage();
        }
	}
}

void VappCnmgrBearerDetailInfoPage::exitPage()
{
    if (m_indicatorPopup != NULL)
    {
        m_indicatorPopup->hide(VFX_TRUE);
        VFX_OBJ_CLOSE(m_indicatorPopup);
    }

    exit();
}

void VappCnmgrBearerDetailInfoPage::discDone(VfxU8 result, void *userData)
{
    VappCnmgrBearerDetailInfoPage *infoPage = (VappCnmgrBearerDetailInfoPage*)VfxObject::handleToObject((VfxObjHandle)userData);

    if (infoPage)
    {
        VFX_DEV_ASSERT(infoPage->isKindOf(VFX_OBJ_CLASS_INFO(VappCnmgrBearerDetailInfoPage)));
        infoPage->exitPage();
    }
}

#endif /* __MMI_CBM_CONNECTION_MANAGER__ */
#endif /* __TCPIP__ */
