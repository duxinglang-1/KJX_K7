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
 * Vapp_app_manager.cpp
 *
 * Project:
 * --------
 * MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifdef __COSMOS_MMI_PACKAGE__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_MRE_MSPACE__
#include "vapp_app_manager.h"
#include "vapp_m_space.h"
#include "vapp_usb_gprot.h"

extern "C"
{
#include "ucmgprot.h" 
#include "browser_api.h"
#include "Conversions.h"
#include "vcui_dialer_gprot.h"//for telephone call
#include "mmi_rp_vapp_app_manager_def.h"
#include "mmi_rp_vapp_m_space_def.h"
#include "vfx_adp_device.h"
#include "SimCtrlSrvGprot.h"
#include "vmsock.h"
}

#define VAPP_MSPACE_TRACE(msg)


#define VAPP_MSPACE_TRACE1(msg,a) 


#define VAPP_MSPACE_TRACE2(msg,a,b)


#define VAPP_MSPACE_TRACE3(msg,a,b,c)   


/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

VfxId VappMSpaceMainPage::m_pageId          = 1;
VfxId VappMSpaceAppInfoPage::m_pageId       = 2;

extern VscrPara         g_scrPara;
static VappInfoList*    g_pAppInfoList = NULL;

VfxWeakPtr<VappMSpaceMainSrc> VappMSpaceApp::m_pMainSrc = NULL;
mmi_id VappMSpaceApp::m_mmiId = 0;

static S32 g_list_num = 0;
static srv_as_app_node_t* g_app_node = NULL;
static srv_as_app_info_t* g_app_info = NULL;

S32 vapp_m_space_init_list()
{
    srv_as_list_init();
    return 0;
}

void vapp_m_space_deinit_list()
{
    if (g_list_num > 0)
    {
        for (int i = 0; i < g_list_num; i++)
        {
            MSPACE_FREE(g_app_node[i].icon);
        }
    }
    MSPACE_FREE(g_app_node);
    MSPACE_FREE(g_app_info);
    g_list_num = 0;
    srv_as_list_deinit();
}

S32 vapp_m_space_update_list(U32 index)
{
    if (-1 == index)
    {
        //update all list
        S32 num = 0;
        num = srv_as_list_get_record_num();
        if (num <= 0)
        {
            g_list_num = 0;
            return num;
        }

        if (g_list_num > 0 && g_app_node)
        {
            for (int i = 0; i < g_list_num; i++)
            {
                MSPACE_FREE(g_app_node[i].icon);
            }
        }
        MSPACE_FREE(g_app_node);
        MSPACE_MALLOC(g_app_node,sizeof(srv_as_app_node_t)*num);
        ASSERT(g_app_node);
        memset(g_app_node,0,sizeof(srv_as_app_node_t)*num);

        MSPACE_FREE(g_app_info);
        MSPACE_MALLOC(g_app_info,sizeof(srv_as_app_info_t)*num);
        ASSERT(g_app_info);
        memset(g_app_info,0,sizeof(srv_as_app_info_t)*num);

        g_list_num = num;
        S32 result = srv_as_list_get_info(0,num,g_app_node,g_app_info);
        if (result)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        U8* tmp_icon = g_app_node[index].icon;
        S32 result = srv_as_list_get_info(index,1,&g_app_node[index],&g_app_info[index]);
        g_app_node[index].icon = tmp_icon;
        if (result)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
}

S32 vapp_m_space_list_num(void)
{
    return g_list_num;
}

S32 vapp_m_space_get_info(U32 index, U32 num, srv_as_app_node_t * node, srv_as_app_info_t * info)
{
    if (index >= g_list_num)
    {
        return -1;
    }
    if (node)
    {
        memcpy(node,&g_app_node[index],sizeof(srv_as_app_node_t));
    }
    if (info)
    {
        memcpy(info,&g_app_info[index],sizeof(srv_as_app_info_t));
    }
    return 0;
}

void* srv_as_list_get_icon(U32 index)
{
    if (!g_app_node || index >= g_list_num)
    {
        MMI_PRINT(MOD_MRE,TRACE_GROUP_1,"srv_as_list_get_icon error1");
        return NULL;
    }

    if (g_app_node[index].icon)
    {
        return g_app_node[index].icon;
    }
    MSPACE_MALLOC(g_app_node[index].icon,g_app_node[index].icon_size);
    if (!g_app_node[index].icon)
    {
        MMI_PRINT(MOD_MRE,TRACE_GROUP_1,"srv_as_list_get_icon error2");
        return NULL;
    }
    srv_as_list_get_icon(index, g_app_node[index].icon, g_app_node[index].icon_size);
    return g_app_node[index].icon;
}

static mmi_ret vapp_m_space_update(mmi_event_struct *param)
{
    VappMSpaceMainSrc::updatePage(-1);
    return MMI_RET_OK;
}

extern "C" mmi_ret vapp_m_space_handle_event(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_fmgr_notification_format_event_struct *format_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(param->evt_id)
	{
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        	{
        	    VappMSpaceMainSrc* pScr = VappMSpaceApp::getMainScr();
        	    if (pScr)
        	    {
                    pScr->getApp()->exit();
                }
        	}
        	break;
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN: 
        case EVT_ID_SRV_APPMGR_INSTALL_PACKAGE:
        case EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE:
            {
                mmi_event_struct evt;
    		    MMI_FRM_INIT_EVENT(&evt, 0);
    		    mmi_frm_post_event(&evt, vapp_m_space_update, 0);
		    }
        	break;
        default: 
            break;
	}
	return MMI_RET_OK;
}


/***************************************************************************** 
 * Main Entry
 *****************************************************************************/
extern "C" MMI_ID vapp_m_space_launch(void *param, U32 param_size)
{
    if (VappUSBOperator::isMassStorageMode())
    {
        VappUSBOperator::showPopup();
        return 0;
    }
    
    VappMSpaceApp::m_mmiId = VfxAppLauncher::launch( 
        VAPP_M_SPACE, 
        VFX_OBJ_CLASS_INFO(VappMSpaceApp),
        GRP_ID_ROOT);
    VAPP_MSPACE_TRACE1(VAPP_AM_ENTER_AM,VappMSpaceApp::m_mmiId);

    return VappMSpaceApp::m_mmiId;
}
/***************************************************************************** 
 * Class VappMSpaceApp
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMSpaceApp", VappMSpaceApp, VfxApp);

void VappMSpaceApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    m_bInited = VFX_FALSE;
    
    VappUSBOperator* pUSB;
    VFX_OBJ_CREATE(pUSB, VappUSBOperator, this);
    pUSB->m_enterMSSignal.connect(this, &VfxApp::exit);

    //create main screen
    VappMSpaceMainSrc *pScr;
    VFX_OBJ_CREATE(pScr, VappMSpaceMainSrc, this);
    VappMSpaceApp::m_pMainSrc = pScr;    
   
    //show main screen
    pScr->show();
}

void VappMSpaceApp::initApp()
{
    VappMSpaceMainSrc* pSrc = getMainScr();
    VappMSpaceApp* pApp = (VappMSpaceApp*)pSrc->getApp();
    pApp->m_bInited = VFX_TRUE;
}

void VappMSpaceApp::onDeinit()
{
    if (m_bInited)
    {
        m_bInited = VFX_FALSE;
    }

    vapp_m_space_deinit_list();
    
    VappMSpaceApp::m_pMainSrc = NULL;
    VfxApp::onDeinit();
}

mmi_ret VappMSpaceApp::onProc(mmi_event_struct *evt)
{
    VappMSpaceMainSrc* pSrc = getMainScr();
    if (pSrc && pSrc->isValid())
    {
        //we let page who own data account to process event
        return pSrc->processProc(evt);
    }
    return VfxApp::onProc(evt);
}

/***************************************************************************** 
 * Class VappMSpaceMainSrc
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMSpaceMainSrc", VappMSpaceMainSrc, VfxMainScr);


void VappMSpaceMainSrc::on1stReady()
{
    VfxMainScr::on1stReady();

    VappMSpaceMainPage* pPage;
    VFX_OBJ_CREATE(pPage, VappMSpaceMainPage, this);
    pushPage(VappMSpaceMainPage::m_pageId, pPage);       
}

void VappMSpaceMainSrc::updatePage(VfxS32 index)
{
    VfxRenderer* renderer = VfxRenderer::getInstance();
    renderer->suspendUntilCommit();
    VappMSpaceMainSrc* pScr = VappMSpaceApp::m_pMainSrc.get();
    if (pScr)
    {
        VappMSpacePage* pPage = (VappMSpacePage*)pScr->getPage(VappMSpaceMainPage::m_pageId);
        if (pPage)
        {
            pPage->updatePage(index);
        }
        pPage = (VappMSpacePage*)pScr->getPage(VappMSpaceAppInfoPage::m_pageId);
        if (pPage)
        {
            pPage->updatePage(index);
        }
    }
}

/***************************************************************************** 
 * Class VappMSpaceItem
 *****************************************************************************/
VappMSpaceItem::VappMSpaceItem(VfxU32 index):m_index(index),m_icon(NULL)
{
};

void VappMSpaceItem::onCreateElements()
{ 
    srv_as_app_node_t node;
    srv_as_app_info_t info;
    
    vapp_m_space_get_info(m_index, 1, &node, &info);
    m_icon = (VfxU8*)srv_as_list_get_icon(m_index);
    
    U32 xgap = VAPP_AM_LIST_MARGIN;
    U32 ygap = VAPP_AM_LIST_MARGIN;
    U32 x,y;
    
    setSize(VfxSize(LCD_WIDTH,VAPP_AM_LIST_HEIGHT));

    // create app icon background
    VfxImageFrame* bgFram;
    VFX_OBJ_CREATE(bgFram, VfxImageFrame, this);
    bgFram->setResId(VAPP_AM_IMG_APPICON_BG);
    bgFram->setAnchor(0.5,0.5);
    x = VAPP_AM_LIST_APPICON_SIZE/2 + xgap;
    y = getSize().height/2;
    bgFram->setPos(x, y);
    
    // create app icon
    VfxFrame* pAppIcon;
    VFX_OBJ_CREATE(pAppIcon, VfxFrame, this);
    pAppIcon->setImgContent(VfxImageSrc(m_icon));

    pAppIcon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    pAppIcon->setIsCached(VFX_TRUE);
    pAppIcon->setBounds(0, 0, VAPP_AM_LIST_APPICON_SIZE, VAPP_AM_LIST_APPICON_SIZE);
    x = xgap;
    y = ygap;
    pAppIcon->setPos(x, y);


    VfxFontDesc fontDesc;      
     
    // create install time text
    applib_time_struct time_struct;
    VfxDateTime dataTime;

    memset(&time_struct,0,sizeof(time_struct));
    time_struct.nYear = node.year;
    time_struct.nMonth= node.month;
    time_struct.nDay= node.day;

    dataTime.setDateTime(&time_struct);
    
    VFX_OBJ_CREATE(m_pInstallTime, VfxTextFrame, this);
    m_pInstallTime->setString(dataTime.getDateTimeString(VFX_DATE_TIME_DATE_MASK));
    m_pInstallTime->setColor(VFX_COLOR_RES(VAPP_AM_GREY));
    m_pInstallTime->setFont(VFX_FONT_DESC_SMALL);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_AM_LIST_APP_INSTALL_TIME_SIZE);
    m_pInstallTime->setFont(fontDesc);

    x = VAPP_AM_LIST_APPICON_SIZE + xgap*2;
    y = getSize().height*3/5;
    m_pInstallTime->setPos(x, y);

    VfxU32 iconLength = 0;

    // 3 types of icons to present app type: pre-in,  download,  install
    VFX_OBJ_CREATE(m_pStatusIcon, VfxImageFrame, this);

    if (SRV_AS_APP_STATUS_NO_AVAIL_UPDATE == info.status)
    {
        m_pStatusIcon->setResId(IMG_ID_VAPP_M_SPACE_APP_STATUS_INSTALLED_ICON);
    }
    else if (SRV_AS_APP_STATUS_AVAIL_UPDATE == info.status)
    {
        m_pStatusIcon->setResId(IMG_ID_VAPP_M_SPACE_APP_STATUS_UPDATE_ICON);
    }

    x = getSize().width - xgap;
    y = getSize().height/2;
    
    m_pStatusIcon->setAnchor(1,0.5); 
    m_pStatusIcon->setPos(x, y);

    iconLength += m_pStatusIcon->getSize().width + 2*xgap;
    
    // create app name text
    x = VAPP_AM_LIST_APPICON_SIZE + xgap*2;
    y = getSize().height*2/5;
    VfxU32 AppNameLength = getSize().width - x - iconLength;
                           
    VFX_OBJ_CREATE(m_pAppName, VfxTextFrame, this);    
    m_pAppName->setSize(AppNameLength,VAPP_AM_LIST_APP_NAME_HEIGHT);
    m_pAppName->setAutoResized(VFX_FALSE);
    m_pAppName->setColor(VAPP_AM_BLACK);
    m_pAppName->setAnchor(0,0.5);
    m_pAppName->setPos(x, y);
    m_pAppName->setString(VFX_WSTR_MEM(node.dis_name));
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_AM_LIST_APP_NAME_SIZE);
    m_pAppName->setFont(fontDesc);
    m_pAppName->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

    VAPP_MSPACE_TRACE(VAPP_AM_CEATE_ELEMENT_END);
}
 
void VappMSpaceItem::onCloseElements()
{
}
    
void VappMSpaceItem::onLayoutElements()
{

}

void VappMSpaceItem::onUpdateElements()
{
    // TODO: could update element here
    VcpListMenuCell* pCell = getCell();
    if (NULL == pCell)
    {
        return;
    }

    m_pAppName->setColor(pCell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_NORMAL));
    m_pInstallTime->setColor(pCell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT));

    srv_as_app_node_t node;
    srv_as_app_info_t info;
    vapp_m_space_get_info(m_index, 1, &node, &info);
    if (SRV_AS_APP_STATUS_NO_AVAIL_UPDATE == info.status)
    {
        m_pStatusIcon->setResId(IMG_ID_VAPP_M_SPACE_APP_STATUS_INSTALLED_ICON);
    }
    else if (SRV_AS_APP_STATUS_AVAIL_UPDATE == info.status)
    {
        m_pStatusIcon->setResId(IMG_ID_VAPP_M_SPACE_APP_STATUS_UPDATE_ICON);
    }
}



/***************************************************************************** 
 * Class VappMSpaceListPage
 *****************************************************************************/
 /*
void VappMSpaceListPage::onInit()
{
    VAPP_MSPACE_TRACE(VAPP_AM_LIST_MENU_PAGE_INIT);
    
    VfxPage::onInit();
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    VFX_OBJ_CREATE(m_pListMenu,VcpListMenu,this);
    m_pListMenu->setHidden(VFX_TRUE);

    VappMSpaceListMenuContentProvider* pProvider;
    VFX_OBJ_CREATE(pProvider,VappMSpaceListMenuContentProvider,this);
    m_pListMenu->setContentProvider(pProvider);
    m_pListMenu->setItemHeight(VAPP_AM_LIST_HEIGHT);
    
    VFX_OBJ_CREATE(m_pText,VfxTextFrame,this);
    m_pText->setColor(VAPP_AM_LOADING_GREY);
    m_pText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_AM_LIST_APP_NAME_SIZE)));
    m_pText->setString(VFX_WSTR_RES(STR_GLOBAL_LOADING)); 
    m_pText->setAutoResized(VFX_TRUE);
    m_pText->forceUpdate();

    //tool bar

    m_bUpdated = VFX_FALSE;
    m_pWaitingPopup = NULL;
//    m_pAppInfoList->setRemoveNotifyFunction(this,(VappInfoList::NotifyFun)&VappMSpaceListPage::updatePage);
}

void VappMSpaceListPage::updateCallback(S32 hdl, void * para)
{
    srv_as_cb_app_query_t* data = (srv_as_cb_app_query_t*)para;
    if (E_SRV_AS_AVAILABLE_UPDATE == data->state)
    {
        srv_as_data_download(hdl, NULL, &VappMSpaceListPage::updateCallback, data->user_data);
    }
    else if (E_SRV_AS_DOWNLOADED == data->state)
    {
        VappMSpaceListPage* pThis = (VappMSpaceListPage*)VfxObject::handleToObject(data->user_data);
        if (pThis)
        {
            ((VfxPage*)pThis->getParent())->getBar(VFX_PAGE_BAR_LOCATION_BOTTOM)->setHidden(VFX_TRUE);
            pThis->updatePage();
        }
    }
    else if (   E_SRV_AS_NO_UPDATE == data->state ||
                E_SRV_AS_HOST_NOT_FOUND == data->state ||
                E_SRV_AS_PIPE_CLOSED == data->state ||
                E_SRV_AS_PIPE_BROKEN == data->state ||
                E_SRV_AS_FAILURE == data->state)
    {
        VappMSpaceListPage* pThis = (VappMSpaceListPage*)VfxObject::handleToObject(data->user_data);
        if (pThis)
        {
            ((VfxPage*)pThis->getParent())->getBar(VFX_PAGE_BAR_LOCATION_BOTTOM)->setHidden(VFX_FALSE);
            pThis->updatePage();
        }
    }
}

void VappMSpaceListPage::updatePage()
{    
    if (m_pWaitingPopup)
    {
        m_pWaitingPopup->hide(VFX_TRUE);
    }
    //get app list from service
    VfxS32 num = srv_as_list_get_record_num();

    if (0 == num)
    {
        //no applications            
        m_pText->setString(VFX_WSTR_RES(STR_ID_VAPP_AM_NO_APPLICATIONS)); 

        m_pText->setHidden(VFX_FALSE);
        m_pListMenu->setHidden(VFX_TRUE);
    }
    else if (num > 0)
    {
        m_pText->setHidden(VFX_TRUE);
        m_pListMenu->setHidden(VFX_FALSE);
        m_pListMenu->resetAllItems(VFX_TRUE);
    }

    if (!m_bUpdated)
    {        
        srv_as_data_query_t query_data;
        query_data.qry = E_SRV_AS_APP_QUERY_LIS;
        m_handle = srv_as_data_query(&query_data, &VappMSpaceListPage::updateCallback, this->getObjHandle());

        VFX_OBJ_CREATE(m_pWaitingPopup,VcpIndicatorPopup,this);
        m_pWaitingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
//        m_pWaitingPopup->setText(VFX_WSTR_RES(STR_MRE_UPDATE_UPDATING));
        m_pWaitingPopup->m_signalButtonClicked.connect(this,&VappMSpaceListPage::onCancelUpdate);
        m_pWaitingPopup->show(VFX_TRUE);
        m_bUpdated = VFX_TRUE;
    }
}

void VappMSpaceListPage::onCancelUpdate(VfxObject* pObj, VfxId id)
{
    if (-1 != id)
    {
        srv_as_data_cancel(m_handle);
        m_pWaitingPopup->hide(VFX_TRUE);
    }
}

void VappMSpaceListPage::eventHandler(VfxObject* pObj, VfxId id)
{
    
    if (1 == id)
    {        
        //retry
        srv_as_data_query_t query_data;
        query_data.qry = E_SRV_AS_APP_QUERY_LIS;
        srv_as_data_query(&query_data, &VappMSpaceListPage::updateCallback, this->getObjHandle());
        m_pWaitingPopup->show(VFX_TRUE);
    }
    else if (2 == id)
    {
        //exit
        VfxPage* page = (VfxPage*)getParent();
        page->exit();
    }
}


void VappMSpaceListPage::setListBounds(const VfxRect& rect)
{
    m_pListMenu->setBounds(rect);
    m_pText->setAnchor(0.5,0.5);
    m_pText->setPos(rect.size.width/2,rect.size.height/2);
}

/***************************************************************************** 
 * Class VappMSpaceMainPage
 *****************************************************************************/
VappMSpaceMainPage::VappMSpaceMainPage()
:m_bFirstIn(VFX_TRUE),m_pListMenu(NULL)
{
    
}

void VappMSpaceMainPage::onInit()
{  
    VAPP_MSPACE_TRACE(VAPP_AM_MAIN_PAGE_INIT);
    
    VfxPage::onInit();
    //tile bar
    VcpTitleBar* pbar;
    VFX_OBJ_CREATE(pbar, VcpTitleBar, this);
    pbar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_M_SPACE_TITLE));
    setTopBar(pbar);  

    
    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    VFX_OBJ_CREATE(m_pText,VfxTextFrame,this);
    m_pText->setColor(VAPP_AM_LOADING_GREY);
    m_pText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_AM_LIST_APP_NAME_SIZE)));
    m_pText->setString(VFX_WSTR_RES(STR_GLOBAL_LOADING)); 
    m_pText->setAutoResized(VFX_TRUE);
    m_pText->setAnchor(0.5,1);
    m_pText->setPos(getPageRect().size.width/2,getPageRect().size.height/2);
    m_pText->forceUpdate();
    VFX_OBJ_CREATE(m_pListMenu,VcpListMenu,this);
    m_pListMenu->m_signalItemLongTapped.connect(this,&VappMSpaceMainPage::onLongTap);
    m_pListMenu->m_signalItemTapped.connect(this,&VappMSpaceMainPage::onTap);
    m_pListMenu->setCacheLen(1000);
    m_pListMenu->setHidden(VFX_TRUE);
    
    VappMSpaceListMenuContentProvider* pProvider;
    VFX_OBJ_CREATE(pProvider,VappMSpaceListMenuContentProvider,this);
    m_pListMenu->setContentProvider(pProvider);
    m_pListMenu->setItemHeight(VAPP_AM_LIST_HEIGHT);
    
    
    m_bUpdated = VFX_FALSE;
    m_pWaitingPopup = NULL;
}

void VappMSpaceMainPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    if (m_bFirstIn)
    {
        VfxTimer* pTimer;
        VFX_OBJ_CREATE(pTimer, VfxTimer, this);
        pTimer->setStartDelay(200);
        pTimer->m_signalTick.connect(this,&VappMSpaceMainPage::onTime);
        pTimer->start();
        m_bFirstIn = VFX_FALSE;
    }
}

void VappMSpaceMainPage::onTap(VcpListMenu* pMenu, VfxU32 index)
{
    VappMSpaceAppInfoPage* pPage;
    VFX_OBJ_CREATE_EX(pPage, VappMSpaceAppInfoPage, getMainScr(),(index));
    pPage->showPage();
 
}

void VappMSpaceMainPage::onLongTap(VcpListMenu* pMenu, VfxU32 index)
{
    // TODO: for enhance
}


void VappMSpaceMainPage::updateCallback(S32 hdl, void * para)
{
    srv_as_cb_app_query_t* data = (srv_as_cb_app_query_t*)para;
    if (E_SRV_AS_AVAILABLE_UPDATE == data->state)
    {
        if (srv_as_data_download(hdl, NULL, &VappMSpaceMainPage::updateCallback, data->user_data) < 0)
        {
    	    VappMSpaceMainPage* pThis = (VappMSpaceMainPage*)VfxObject::handleToObject(data->user_data);
            if (pThis)	
            {
                if (pThis->m_pWaitingPopup)
                {
                    pThis->m_pWaitingPopup->exit(VFX_TRUE);
                }
                
        	    VcpConfirmPopup* pPopup;
                VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,pThis);

                VfxWString strText(STR_ID_VAPP_AM_POPUP_UPDATE_FAIL_NO_MEM);
                pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
                pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
                pPopup->setText(strText);
                pPopup->m_signalButtonClicked.connect(pThis,&VappMSpaceMainPage::eventHandler);
                pPopup->show(VFX_TRUE);
            }
    	}
    }
    else if (E_SRV_AS_NO_UPDATE == data->state)
    {
        VappMSpaceMainPage* pThis = (VappMSpaceMainPage*)VfxObject::handleToObject(data->user_data);
        if (pThis)
        {
            pThis->m_pWaitingPopup->hide(VFX_TRUE);
        }
    }
    else if (E_SRV_AS_DOWNLOADED == data->state)
    {
        VappMSpaceMainPage* pThis = (VappMSpaceMainPage*)VfxObject::handleToObject(data->user_data);
        if (pThis)
        {
            pThis->updatePage(-1);
            if (pThis->m_pWaitingPopup)
            {
                pThis->m_pWaitingPopup->hide(VFX_TRUE);
            }
        }
    }
    else if (   E_SRV_AS_QUERYING != data->state &&
                E_SRV_AS_CONNECTING!= data->state &&
                E_SRV_AS_CONNECTED!= data->state &&
                E_SRV_AS_DOWNLOADING != data->state)
  
    {
        VappMSpaceMainPage* pThis = (VappMSpaceMainPage*)VfxObject::handleToObject(data->user_data);
        if (pThis)
        {
            VcpConfirmPopup* pPopup;
            VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,pThis);
            
            VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_M_SPACE_CONNECT_SERVER_FAILED));
            
            pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);   
            pPopup->setText(strText);
            pPopup->setCustomButton(VFX_WSTR_RES(STR_ID_VAPP_M_SPACE_RETRY),
                                    VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_CANCEL),
                                    VCP_POPUP_BUTTON_TYPE_NORMAL,
                                    VCP_POPUP_BUTTON_TYPE_CANCEL);
                                    
            pPopup->m_signalButtonClicked.connect(pThis,&VappMSpaceMainPage::eventHandler);
            pPopup->show(VFX_TRUE);
            if (pThis->m_pWaitingPopup)
            {
                pThis->m_pWaitingPopup->hide(VFX_TRUE);
            }
        }
    }
}

void VappMSpaceMainPage::updatePage(VfxS32 index)
{    
    vapp_m_space_update_list(index);
    VfxS32 num = vapp_m_space_list_num();

    if (0 >= num)
    {
        //no applications            
        m_pText->setString(VFX_WSTR_RES(STR_ID_VAPP_AM_NO_APPLICATIONS)); 

        m_pText->setHidden(VFX_FALSE);
        m_pListMenu->setHidden(VFX_TRUE);
    }
    else if (num > 0)
    {
        m_pText->setHidden(VFX_TRUE);
        m_pListMenu->setHidden(VFX_FALSE);
        m_pListMenu->resetAllItems(VFX_TRUE);
    }

    if (!m_bUpdated)
    {        
        srv_as_data_query_t query_data;
        query_data.qry = E_SRV_AS_APP_QUERY_LIS;
        m_handle = srv_as_data_query(&query_data, &VappMSpaceMainPage::updateCallback, this->getObjHandle());
       
        m_bUpdated = VFX_TRUE;
        if (m_handle < 0)
        {
/*            VcpToolBar* toolbar; 
            VFX_OBJ_CREATE(toolbar,VcpToolBar,this);
            toolbar->addItem(1, VFX_WSTR_RES(STR_ID_VAPP_M_SPACE_RETRY), VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH);  
            toolbar->addItem(2, VFX_WSTR_RES(STR_GLOBAL_EXIT), VCP_IMG_TOOL_BAR_COMMON_ITEM_EXIT);    
            setBottomBar(toolbar);
            toolbar->m_signalButtonTap.connect(this, &VappMSpaceMainPage::eventHandler);
            
            m_pText->setString(VFX_WSTR_RES(STR_ID_VAPP_M_SPACE_CONNECT_SERVER_FAILED));
            m_pText->setHidden(VFX_FALSE);
            m_pListMenu->setHidden(VFX_TRUE);  */
            VcpConfirmPopup* pPopup;
            VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,this);
            
            VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_M_SPACE_CONNECT_SERVER_FAILED));
            
            pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);   
            pPopup->setText(strText);
            pPopup->setCustomButton(VFX_WSTR_RES(STR_ID_VAPP_M_SPACE_RETRY),
                                    VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_CANCEL),
                                    VCP_POPUP_BUTTON_TYPE_NORMAL,
                                    VCP_POPUP_BUTTON_TYPE_CANCEL);
                                    
            pPopup->m_signalButtonClicked.connect(this,&VappMSpaceMainPage::eventHandler);
            pPopup->show(VFX_TRUE);
        }
        else
        {
            VFX_OBJ_CREATE(m_pWaitingPopup,VcpIndicatorPopup,this);
            m_pWaitingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
            m_pWaitingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
            m_pWaitingPopup->m_signalButtonClicked.connect(this,&VappMSpaceMainPage::onCancelUpdate);
            m_pWaitingPopup->show(VFX_TRUE);
        }
    }
}

void VappMSpaceMainPage::onCancelUpdate(VfxObject* pObj, VfxId id)
{
    if (-1 != id)
    {
        srv_as_data_cancel(m_handle);
        m_pWaitingPopup->hide(VFX_TRUE);
//        updatePage();
    }
}

void VappMSpaceMainPage::eventHandler(VfxObject* pObj, VfxId id)
{
    
    if (VCP_CONFIRM_POPUP_BUTTON_USER_1 == id)
    {        
        //retry
        srv_as_data_query_t query_data;
        query_data.qry = E_SRV_AS_APP_QUERY_LIS;
        m_handle = srv_as_data_query(&query_data, &VappMSpaceMainPage::updateCallback, this->getObjHandle());
        if (m_handle < 0)
        {         
            VcpConfirmPopup* pPopup;
            VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,this);
            
            VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_M_SPACE_CONNECT_SERVER_FAILED));
            
            pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);   
            pPopup->setText(strText);
            pPopup->setCustomButton(VFX_WSTR_RES(STR_ID_VAPP_M_SPACE_RETRY),
                                    VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_CANCEL),
                                    VCP_POPUP_BUTTON_TYPE_NORMAL,
                                    VCP_POPUP_BUTTON_TYPE_CANCEL);
                                    
            pPopup->m_signalButtonClicked.connect(this,&VappMSpaceMainPage::eventHandler);
            pPopup->show(VFX_TRUE);   
        }
        else
        {
            m_pWaitingPopup->show(VFX_TRUE);
        }
    }
    else if (VCP_CONFIRM_POPUP_BUTTON_OK == id)
    {
        exit();
    }
}

void VappMSpaceMainPage::setBounds(const VfxRect &value)
{    
	if (m_pListMenu)
	{
		m_pListMenu->setBounds(value);
	}
    VfxPage::setBounds(value);
}

void VappMSpaceMainPage::onTime(VfxTimer* pTime)
{
    vapp_m_space_init_list();
    
    VappMSpaceMainPage::updatePage(-1);
}


/***************************************************************************** 
 * Class VappMSpaceAppInfoPage
 *****************************************************************************/
VappMSpaceAppInfoPage::VappMSpaceAppInfoPage(VfxU32 index)
:m_index(index),m_icon(NULL),m_pToolBar(NULL),m_pForm(NULL)
{
}

VappMSpaceAppInfoPage::~VappMSpaceAppInfoPage()
{

}

void VappMSpaceAppInfoPage::onInit()
{
    VAPP_MSPACE_TRACE(VAPP_AM_INFO_PAGE_INIT);
    
    VfxPage::onInit();
    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    //tile bar
    VcpTitleBar* pbar;
    VFX_OBJ_CREATE(pbar, VcpTitleBar, this);
    setTopBar(pbar);  
    
    //tool bar
    VFX_OBJ_CREATE(m_pToolBar,VcpToolBar,this);
    setBottomBar(m_pToolBar);

    m_pToolBar->m_signalButtonTap.connect(this, &VappMSpaceAppInfoPage::eventHandler);      
}

extern "C" VMINT vm_preload_status(VMINT app_id);
extern "C" void vm_preload_show_download_list(void);

void VappMSpaceAppInfoPage::eventHandler(VfxObject* pObj, VfxId id)
{
    srv_as_app_node_t node;
    
    vapp_m_space_get_info(m_index, 1, &node, NULL);
    int status = vm_preload_status(node.appid);
    if (E_PRELOAD_DOWNLOADING == status)
    {
        vm_preload_show_download_list();
        return;
    }
    else if (status >= 0)
    {
        return;
    }

    VappMSpaceOperateHelper* helper;
    VFX_OBJ_CREATE(helper,VappMSpaceOperateHelper,getMainScr());
    switch (id)
    {
        case 1:
            //install
            helper->install(m_index);
            break;
            
        case 2:
            //update
            helper->update(m_index);                
            break;

        default:
            break;
    }
    VcpToolBar* pBar = (VcpToolBar*)pObj;
    pBar->setIsDisabled(VFX_TRUE);

}

void VappMSpaceAppInfoPage::onUninstall(VfxS32 bRet)
{
    if (VAPP_AM_OK == bRet)
    {
        //app has uninstalled, need to exit this page
        getMainScr()->popPage();
    }
    else
    {
        //uninstalled failed, what should i do?
        // TODO: deal with failure? 
    }
}

void VappMSpaceAppInfoPage::updatePage(VfxS32 index)
{
    //after app updated, may need to update page
    if (vapp_m_space_update_list(index) < 0)
    {
        return;
    }
    if (this->isValid())
    {       
        updateInfo();
    }
}

void VappMSpaceAppInfoPage::onUpdateInfo()
{
    if (this->isValid())
    {
        updateInfo();
        getMainScr()->pushPage(m_pageId,this);
    }
}

void VappMSpaceAppInfoPage::showPage()
{
    updateInfo();
    getMainScr()->pushPage(m_pageId,this);
}

void VappMSpaceAppInfoPage::updateInfo()
{
    srv_as_app_node_t node;
    srv_as_app_info_t info;
    
    vapp_m_space_get_info(m_index, 1, &node, &info);
    m_icon = (VfxU8*)srv_as_list_get_icon(m_index);

    VcpTitleBar* pBar = (VcpTitleBar*)getBar(VFX_PAGE_BAR_LOCATION_TOP);
    pBar->setTitle(VFX_WSTR_MEM(node.dis_name));

    if (SRV_AS_APP_STATUS_NO_AVAIL_UPDATE == info.status)
    {
        setBottomBar(NULL);
    }
    else if (SRV_AS_APP_STATUS_AVAIL_UPDATE == info.status)
    {
        m_pToolBar->addItem(2, VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_UPDATE), VAPP_AM_IMG_UPDATE);
    }
    else
    {
        m_pToolBar->addItem(1, VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_INSTALL), VAPP_AM_IMG_DOWNLOAD);
    }
    m_pToolBar->setIsDisabled(VFX_FALSE);
    VFX_OBJ_CLOSE(m_pForm);
    VFX_OBJ_CREATE(m_pForm, VcpForm, this);
    
    m_pForm->setPos(0,0);
    m_pForm->setSize(getSize());
    
    m_pForm->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE);
                
    U32 xgap = VAPP_AM_LIST_MARGIN;
    U32 ygap = VAPP_AM_LIST_MARGIN;
    U32 x,y;
    
 /*   VfxImageFrame* bgFram;
    VFX_OBJ_CREATE(bgFram, VfxImageFrame, m_pForm);
    bgFram->setResId(VAPP_AM_IMG_APPICON_BG);
    bgFram->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    bgFram->setBounds(0, 0, VAPP_AM_LIST_APPICON_SIZE*2, VAPP_AM_LIST_APPICON_SIZE*2);
    bgFram->setAnchor(0.5,0.5);
    x = VAPP_AM_LIST_APPICON_SIZE + xgap;
    y = x;
    bgFram->setPos(x, y);*/
    
    // create app icon
    VfxFrame* pAppIcon;
    VFX_OBJ_CREATE(pAppIcon, VfxFrame, m_pForm);

    pAppIcon->setImgContent(VfxImageSrc(m_icon));

    pAppIcon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    pAppIcon->setIsCached(VFX_TRUE);
    pAppIcon->setBounds(0, 0, VAPP_AM_LIST_APPICON_SIZE, VAPP_AM_LIST_APPICON_SIZE);
    pAppIcon->setAnchor(0.5,0.5);
    x = VAPP_AM_LIST_APPICON_SIZE/2 + xgap;
    y = x;
    pAppIcon->setPos(x, y);   
     
    // create install time text
    VfxTextFrame* pText;

    
    VFX_OBJ_CREATE(pText, VfxTextFrame, m_pForm);
    VfxWString str(VFX_WSTR_RES(STR_ID_VAPP_AM_DETAIL_SIZE));

    VfxWString tmpStr;
    tmpStr.format(":%d KB",(node.app_size>1)?node.app_size:1);
    str += tmpStr;
    
    pText->setString(str);
    pText->setColor(VFX_COLOR_RES(VAPP_AM_BLACK));
    pText->setFont(VFX_FONT_DESC_MEDIUM);

    x = VAPP_AM_LIST_APPICON_SIZE + xgap*2;
    y = xgap;
    pText->setPos(x, y);
    y += pText->getSize().height;
    
    VFX_OBJ_CREATE(pText, VfxTextFrame, m_pForm);

    str = VFX_WSTR("Time");

    applib_time_struct time_struct;
    VfxDateTime dataTime;

    memset(&time_struct,0,sizeof(time_struct));
    time_struct.nYear = node.year;
    time_struct.nMonth= node.month;
    time_struct.nDay= node.day;
    
    dataTime.setDateTime(&time_struct);
    


    str += VFX_WSTR(":");
    str += dataTime.getDateTimeString(VFX_DATE_TIME_DATE_MASK);
    
    pText->setString(str);
    pText->setColor(VFX_COLOR_RES(VAPP_AM_BLACK));
    pText->setFont(VFX_FONT_DESC_MEDIUM);
    pText->setPos(x, y);

    VcpTextView* pDetailView;
    VFX_OBJ_CREATE(pDetailView, VcpTextView, m_pForm);
    
    pDetailView->setPos(0,VAPP_AM_LIST_APPICON_SIZE + xgap*2);
    pDetailView->setBounds(VfxRect(0, 0, getSize().width, getSize().height-(VAPP_AM_LIST_APPICON_SIZE + xgap*2)));
    pDetailView->setMargins(VAPP_AM_DETAIL_MARGIN,VAPP_AM_DETAIL_MARGIN,VAPP_AM_DETAIL_MARGIN,VAPP_AM_DETAIL_MARGIN);
    pDetailView->setAutoResized(VFX_TRUE);             
    pDetailView->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    
    pDetailView->addDetail(VFX_WSTR_RES(STR_ID_VAPP_AM_DETAIL_AUTHOR),VCP_TEXT_DETAIL_TITLE,500);
    pDetailView->addDetail(VFX_WSTR("\n"),VCP_TEXT_DETAIL_TITLE,500);

    tmpStr = VFX_WSTR_MEM(node.provider);
    tmpStr += VFX_WSTR("\n");
    
    pDetailView->addDetail(tmpStr,VCP_TEXT_DETAIL_CONTENT,500);
    
    pDetailView->addDetail(VFX_WSTR_RES(STR_ID_VAPP_AM_DETAIL_INTRODUCE),VCP_TEXT_DETAIL_TITLE,500);
    pDetailView->addDetail(VFX_WSTR("\n"),VCP_TEXT_DETAIL_TITLE,500);
    pDetailView->addDetail(VFX_WSTR_MEM(node.des),VCP_TEXT_DETAIL_CONTENT,500);
//    pDetailView->addDetail(VFX_WSTR("\n"),VCP_TEXT_DETAIL_CONTENT,200);
    
//    pDetailView->setKeyword(VCP_TEXT_KEYWORD_URL|VCP_TEXT_KEYWORD_PHONENUMBER);
//    pDetailView->m_signalKeywordClick.connect()
    checkUpdate();
}


mmi_ret VappMSpaceAppInfoPage::onProc(mmi_event_struct *evt)
{
    return VappDialerCUIInstance::proc(evt);
}


void VappMSpaceOperateHelper::install(VfxU32 index)
{
    m_index = index;
    srv_as_app_node_t node;
    srv_as_app_info_t info;
    
    vapp_m_space_get_info(index, 1, &node, &info);
    
    VcpConfirmPopup* pPopup;
    VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,getParent());
    
    VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_INSTALL)); // TODO:
    strText += VFX_WSTR(" ");
    strText += VFX_WSTR_MEM(node.dis_name);
    strText += VFX_WSTR("?");
    
    pPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);   
    pPopup->setText(strText);
    pPopup->setCustomButton(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_INSTALL),
                            VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_CANCEL),
                            VCP_POPUP_BUTTON_TYPE_NORMAL,
                            VCP_POPUP_BUTTON_TYPE_CANCEL);
                            
    pPopup->m_signalButtonClicked.connect(this,&VappMSpaceOperateHelper::onInstall);
    pPopup->show(VFX_TRUE);
    return;
}

void VappMSpaceOperateHelper::onInstall(VfxObject* pObj, VfxId id)
{
    // TODO: install
    if (VCP_CONFIRM_POPUP_BUTTON_USER_1 == id)
    {
        S32 result = srv_as_app_download(m_index,&VappMSpaceOperateHelper::installedCallback,(void*)this->getObjHandle());
        if (0 == result)
        {
            VFX_OBJ_CREATE(m_pWaitingPopup,VcpIndicatorPopup,getParent());
            m_pWaitingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            m_pWaitingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
            m_pWaitingPopup->show(VFX_TRUE);
        }   
        else if (-17 == result)
        {
            // memory do not match
            VappMSpaceMainSrc::updatePage(m_index);
            VcpConfirmPopup* pPopup;
            VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,getParent());

            VfxWString strText(STR_ID_VAPP_M_SPACE_MEMORY_LIMITATION);
            pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
            pPopup->setText(strText);
            pPopup->show(VFX_TRUE);
        }
        else if (-18 == result)
        {
            // max install num
            VappMSpaceMainSrc::updatePage(m_index);
            VcpConfirmPopup* pPopup;
            VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,getParent());

            VfxWString strText(STR_ID_VAPP_AM_POPUP_LIMITATION_APP);
            pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
            pPopup->setText(strText);
            pPopup->show(VFX_TRUE);
        }
        else
        {
            VappMSpaceMainSrc::updatePage(m_index);
            VfxWString str(STR_ID_VAPP_M_SPACE_CONNECT_SERVER_FAILED);
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_INFO,
            	                     (WCHAR*)str.getBuf()); 
        }
        return;
    }
    VappMSpaceMainSrc::updatePage(m_index);
    VappMSpaceOperateHelper* pHelper = this;
    VFX_OBJ_CLOSE(pHelper);
}

void VappMSpaceOperateHelper::update(VfxU32 index)
{
    m_index = index;
    srv_as_app_node_t node;
    srv_as_app_info_t info;
    
    vapp_m_space_get_info(index, 1, &node, &info);
    
    VcpConfirmPopup* pPopup;
    VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,getParent());
    
    VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_UPDATE)); // TODO:
    strText += VFX_WSTR(" ");
    strText += VFX_WSTR_MEM(node.dis_name);
    strText += VFX_WSTR("?");
    
    pPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);   
    pPopup->setText(strText);
    pPopup->setCustomButton(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_UPDATE),
                            VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_CANCEL),
                            VCP_POPUP_BUTTON_TYPE_NORMAL,
                            VCP_POPUP_BUTTON_TYPE_CANCEL);
                            
    pPopup->m_signalButtonClicked.connect(this,&VappMSpaceOperateHelper::onUpdate);
    pPopup->show(VFX_TRUE);
    return;
}

void VappMSpaceOperateHelper::onUpdate(VfxObject* pObj, VfxId id)
{
    // TODO: update
    if (VCP_CONFIRM_POPUP_BUTTON_USER_1 == id)
    {
        S32 result = srv_as_app_download(m_index,&VappMSpaceOperateHelper::updateCallback,(void*)this->getObjHandle());
        if (0 == result)
        {
            VFX_OBJ_CREATE(m_pWaitingPopup,VcpIndicatorPopup,getParent());
            m_pWaitingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            m_pWaitingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
            m_pWaitingPopup->show(VFX_TRUE);
        }   
        else if (-17 == result)
        {
            // memory do not match
            VappMSpaceMainSrc::updatePage(m_index);
            VcpConfirmPopup* pPopup;
            VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,getParent());

            VfxWString strText(STR_ID_VAPP_M_SPACE_MEMORY_LIMITATION);
            pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
            pPopup->setText(strText);
            pPopup->show(VFX_TRUE);
        }   
        else
        {
            VappMSpaceMainSrc::updatePage(m_index);
            VfxWString str(STR_ID_VAPP_M_SPACE_CONNECT_SERVER_FAILED);
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_INFO,
            	                     (WCHAR*)str.getBuf()); 
        }
        return;
    }
    VappMSpaceMainSrc::updatePage(m_index);
    VappMSpaceOperateHelper* pHelper = this;
    VFX_OBJ_CLOSE(pHelper);
}

void VappMSpaceOperateHelper::installedCallback(S32 hdl, void * para)
{
    srv_as_cb_app_download_t* data = (srv_as_cb_app_download_t*)para;
    VappMSpaceOperateHelper* pHelper = (VappMSpaceOperateHelper*)VfxObject::handleToObject(data->user_data);;
    if (data->state == E_SRV_AS_AVAILABLE_UPDATE || data->state == E_SRV_AS_NO_UPDATE)
    {
        if (pHelper)
        {
            if (pHelper->m_pWaitingPopup)
            {
                pHelper->m_pWaitingPopup->exit(VFX_TRUE);
            }
            VFX_OBJ_CLOSE(pHelper);
        }
    }
    else if (E_SRV_AS_INSTALL_SUCC == data->state)
    {
        srv_as_app_node_t node;
        srv_as_app_info_t info;

        if (pHelper)
        {
            if (pHelper->m_pWaitingPopup)
            {
                pHelper->m_pWaitingPopup->exit(VFX_TRUE);
            }
            VFX_OBJ_CLOSE(pHelper);
        }
        
        VappMSpaceMainSrc::updatePage(data->index);
        if (!VappMSpaceApp::m_pMainSrc.get())
        {
            srv_as_list_init();
        }
        srv_as_list_get_info(data->index, 1, &node, &info);
        if (!VappMSpaceApp::m_pMainSrc.get())
        {
            srv_as_list_deinit();
        }
        WCHAR buff[256];
        kal_wstrcpy((WCHAR *)buff,(WCHAR *)node.dis_name);
        kal_wstrcat((WCHAR *)buff,(WCHAR *)L" ");
        kal_wstrcat((WCHAR *)buff,(WCHAR *)GetString(STR_ID_VAPP_M_SPACE_INSTALL_SUCCESS));
	    
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_INFO,
            	                     (WCHAR*)buff);           	                     
    }
    else if (   E_SRV_AS_QUERYING != data->state &&
                E_SRV_AS_CONNECTING != data->state &&
                E_SRV_AS_CONNECTED != data->state &&
                E_SRV_AS_DOWNLOADING != data->state &&
                E_SRV_AS_DOWNLOADED != data->state)
    {
        srv_as_app_node_t node;
        srv_as_app_info_t info;

        if (pHelper)
        {
            if (pHelper->m_pWaitingPopup)
            {
                pHelper->m_pWaitingPopup->exit(VFX_TRUE);
            }
            VFX_OBJ_CLOSE(pHelper);
        }
        
        VappMSpaceMainSrc::updatePage(data->index);
        if (!VappMSpaceApp::m_pMainSrc.get())
        {
            srv_as_list_init();
        }
        srv_as_list_get_info(data->index, 1, &node, &info);
        if (!VappMSpaceApp::m_pMainSrc.get())
        {
            srv_as_list_deinit();
        }
        WCHAR buff[256];

        kal_wstrcpy((WCHAR *)buff,(WCHAR *)GetString(STR_ID_VAPP_M_SPACE_INSTALL_FAIL));
        kal_wstrcat((WCHAR *)buff,(WCHAR *)L" ");
	    kal_wstrcat((WCHAR *)buff,(WCHAR *)node.dis_name);
        
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_INFO,
            	                     (WCHAR*)buff);            	                     
    }
}
void VappMSpaceOperateHelper::updateCallback(S32 hdl, void * para)
{
    srv_as_cb_app_download_t* data = (srv_as_cb_app_download_t*)para;
    VappMSpaceOperateHelper* pHelper = (VappMSpaceOperateHelper*)VfxObject::handleToObject(data->user_data);;
    if (data->state == E_SRV_AS_AVAILABLE_UPDATE || data->state == E_SRV_AS_NO_UPDATE)
    {
        if (pHelper)
        {
            if (pHelper->m_pWaitingPopup)
            {
                pHelper->m_pWaitingPopup->exit(VFX_TRUE);
            }
            VFX_OBJ_CLOSE(pHelper);
        }
    }
    else if (E_SRV_AS_INSTALL_SUCC == data->state)
    {
        srv_as_app_node_t node;
        srv_as_app_info_t info;

        if (pHelper)
        {
            if (pHelper->m_pWaitingPopup)
            {
                pHelper->m_pWaitingPopup->exit(VFX_TRUE);
            }
            VFX_OBJ_CLOSE(pHelper);
        }
        VappMSpaceMainSrc::updatePage(data->index);
        if (!VappMSpaceApp::m_pMainSrc.get())
        {
            srv_as_list_init();
        }
        srv_as_list_get_info(data->index, 1, &node, &info);
        if (!VappMSpaceApp::m_pMainSrc.get())
        {
            srv_as_list_deinit();
        }
        WCHAR buff[256];
        kal_wstrcpy((WCHAR *)buff,(WCHAR *)node.dis_name);
        kal_wstrcat((WCHAR *)buff,(WCHAR *)L" ");
        kal_wstrcat((WCHAR *)buff,(WCHAR *)GetString(STR_ID_VAPP_M_SPACE_INSTALL_SUCCESS));
	    
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_INFO,
            	                     (WCHAR*)buff);           	                     
    }
    else if (   E_SRV_AS_QUERYING != data->state &&
                E_SRV_AS_CONNECTING != data->state &&
                E_SRV_AS_CONNECTED != data->state &&
                E_SRV_AS_DOWNLOADING != data->state &&
                E_SRV_AS_DOWNLOADED != data->state)
    {
        srv_as_app_node_t node;
        srv_as_app_info_t info;

        if (pHelper)
        {
            if (pHelper->m_pWaitingPopup)
            {
                pHelper->m_pWaitingPopup->exit(VFX_TRUE);
            }
            VFX_OBJ_CLOSE(pHelper);
        }
        
        VappMSpaceMainSrc::updatePage(data->index);
        if (!VappMSpaceApp::m_pMainSrc.get())
        {
            srv_as_list_init();
        }
        srv_as_list_get_info(data->index, 1, &node, &info);
        if (!VappMSpaceApp::m_pMainSrc.get())
        {
            srv_as_list_deinit();
        }
        WCHAR buff[256];

        kal_wstrcpy((WCHAR *)buff,(WCHAR *)GetString(STR_ID_VAPP_M_SPACE_INSTALL_FAIL));
        kal_wstrcat((WCHAR *)buff,(WCHAR *)L" ");
	    kal_wstrcat((WCHAR *)buff,(WCHAR *)node.dis_name);
        
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_INFO,
            	                     (WCHAR*)buff);            	                     
    }
}
#endif //__MMI_MRE_MSPACE__
#endif //__COSMOS_MMI_PACKAGE__
