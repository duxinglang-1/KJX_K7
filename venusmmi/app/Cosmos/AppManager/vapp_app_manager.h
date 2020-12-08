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
 * Vapp_app_manager.h
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
#ifndef __VAPP_APP_MANAGER_H__
#define __VAPP_APP_MANAGER_H__
#ifdef __COSMOS_MMI_PACKAGE__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_form.h"
#include "vcp_tabctrl_page.h"
#include "vcui_dtcnt_select_gprot.h"
#include "vcp_menu_popup.h"
#include "vcp_global_popup.h"
#include "mmi_rp_app_cosmos_global_def.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "PhbSrvGprot.h"
#include "vrt_datatype.h"
#include "AppMgrSrvGprot.h"
#include "usbsrvgprot.h"
#include "MREAppMgrSrvGprot.h"
#ifdef __GADGET_SUPPORT__
#include "WgtMgrSrvIprot.h"
#include "WgtMgrSrvGprot.h"
#endif
#ifdef __J2ME__
#include "JavaAppFactorySrvGprot.h"
#endif  
#include "MRESrvDownloadGprot.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
//some micro for test!!!! begin --

//#define _AM_TEST_                         //should close normal
//#define _AM_APP_TEST_                 //should close normal
//#define _AM_PRINT_TRACE_           //should close normal
//#define _AM_BACK_DOOR_            //should close normal
#define _AM_DATA_ACCOUNT_       //should OPEN normal
//#ifndef WIN32
#define _MRE_LOADING_POPUP_
//#endif
//some micro for test!!!!end --

//error code
#define VAPP_AM_OK                  0
#define VAPP_AM_ERR                 -1
#define VAPP_AM_TIME_ERR            -2
#define VAPP_AM_NO_MEMORY           -3
#define VAPP_AM_ONLY_ONE_FG         -4
#define VAPP_AM_MAX_APP_NUM         -5
#define VAPP_AM_VERSION_NOT_MATCH   -6

#define VAPP_AM_PROCESSING          1
#define VAPP_AM_ALREAD_DONE         2
#define VAPP_AM_NO_UPDATE           3
#define VAPP_AM_MRE_LAUNCH_AGAIN    4

#define VAPP_AM_ADPTER_MRE      0
#define VAPP_AM_ADPTER_JAVA     1
#define VAPP_AM_ADPTER_WGT      2
#define VAPP_AM_ADPTER_MRE_VSO  3

#ifdef __MMI_MAINLCD_320X480__  //HVGA
#define VAPP_AM_LIST_HEIGHT                 65
#define VAPP_AM_LIST_MARGIN                 8
#define VAPP_AM_LIST_MARGIN_ICONS           4
#define VAPP_AM_LIST_APPICON_SIZE           48
#define VAPP_AM_LIST_APP_NAME_HEIGHT        30 
#define VAPP_AM_LIST_APP_NAME_SIZE          20
#define VAPP_AM_LIST_APP_INSTALL_TIME_SIZE  14

#define VAPP_AM_DETAIL_MARGIN               8
#define VAPP_AM_DETAIL_GAP                  10
#elif defined(__MMI_MAINLCD_480X800__)   //WVGA
#define VAPP_AM_LIST_HEIGHT                 109
#define VAPP_AM_LIST_MARGIN                 14
#define VAPP_AM_LIST_MARGIN_ICONS           8
#define VAPP_AM_LIST_APPICON_SIZE           72
#define VAPP_AM_LIST_APP_NAME_HEIGHT        45 
#define VAPP_AM_LIST_APP_NAME_SIZE          30
#define VAPP_AM_LIST_APP_INSTALL_TIME_SIZE  21

#define VAPP_AM_DETAIL_MARGIN               14
#define VAPP_AM_DETAIL_GAP                  18
#elif defined(__MMI_MAINLCD_240X320__)   //QVGA
#define VAPP_AM_LIST_HEIGHT                 51
#define VAPP_AM_LIST_MARGIN                 5
#define VAPP_AM_LIST_MARGIN_ICONS           4
#define VAPP_AM_LIST_APPICON_SIZE           38
#define VAPP_AM_LIST_APP_NAME_HEIGHT        20 
#define VAPP_AM_LIST_APP_NAME_SIZE          16
#define VAPP_AM_LIST_APP_INSTALL_TIME_SIZE  12

#define VAPP_AM_DETAIL_MARGIN               5
#define VAPP_AM_DETAIL_GAP                  6
#elif defined(__MMI_MAINLCD_240X400__)   //WQVGA
#define VAPP_AM_LIST_HEIGHT                 51
#define VAPP_AM_LIST_MARGIN                 5
#define VAPP_AM_LIST_MARGIN_ICONS           4
#define VAPP_AM_LIST_APPICON_SIZE           38 
#define VAPP_AM_LIST_APP_NAME_HEIGHT        20 
#define VAPP_AM_LIST_APP_NAME_SIZE          16
#define VAPP_AM_LIST_APP_INSTALL_TIME_SIZE  12

#define VAPP_AM_DETAIL_MARGIN               5
#define VAPP_AM_DETAIL_GAP                  6
#else //default
#define VAPP_AM_LIST_HEIGHT                 65
#define VAPP_AM_LIST_MARGIN                 8
#define VAPP_AM_LIST_MARGIN_ICONS           4
#define VAPP_AM_LIST_APPICON_SIZE           48 
#define VAPP_AM_LIST_APP_NAME_HEIGHT        30 
#define VAPP_AM_LIST_APP_NAME_SIZE          20
#define VAPP_AM_LIST_APP_INSTALL_TIME_SIZE  14

#define VAPP_AM_DETAIL_MARGIN               8
#define VAPP_AM_DETAIL_GAP                  10
#endif

#define VAPP_AM_DETAIL_INFO_BIG_SIZE        VCP_TEXTVIEW_DETAIL_TITLE_FONT_SIZE
#define VAPP_AM_DETAIL_INFO_SMALL_SIZE      VCP_TEXTVIEW_DETAIL_CONTENT_FONT_SIZE 


//color
#define VAPP_AM_BLACK   CLR_COSMOS_TEXT_MAIN//VRT_COLOR_MAKE(255,21,21,21)
#define VAPP_AM_GREY   CLR_COSMOS_TEXT_SUB//VRT_COLOR_MAKE(255,80,80,80)
#define VAPP_AM_LOADING_GREY VRT_COLOR_MAKE(255,144,144,144)

#if defined(__GADGET_SUPPORT__)
#define _AM_FULL_SUPPORT_
#endif

#if 0 //!(defined(__J2ME__)) && defined(__GADGET_SUPPORT__)
#ifndef _AM_ONLY_GADGET_SUPPORT_
/* under construction !*/
#endif
#endif

#ifdef _AM_TEST_

#define VAPP_AM_TEST_UPDATING           0x00000001
#define VAPP_AM_TEST_RUNNING            0x00000002
#define VAPP_AM_TEST_INSTALLED          0x00000004
#define VAPP_AM_TEST_NOT_EXIST_CARD     0x00000008
#define VAPP_AM_TEST_NOT_EXIST_PHONE    0x00000010
#define VAPP_AM_TEST_MASSSTORAGE        0x00000020
#define VAPP_AM_TEST_NO_MRE_UPDATE      0x00000040

#endif

#ifdef _AM_PRINT_TRACE_
#define VAPP_AM_TRACE(msg) \
            MMI_PRINT(MOD_MRE, TRACE_GROUP_1,msg)
#define VAPP_AM_TRACE1(msg,a) \
            MMI_PRINT(MOD_MRE, TRACE_GROUP_1,msg,a)
#define VAPP_AM_TRACE2(msg,a,b) \
            MMI_PRINT(MOD_MRE, TRACE_GROUP_1,msg,a,b)
#define VAPP_AM_TRACE3(msg,a,b,c) \
            MMI_PRINT(MOD_MRE, TRACE_GROUP_1,msg,a,b,c)            
#else
#define VAPP_AM_TRACE(msg) \
            MMI_TRACE(TRACE_GROUP_1,msg)
#define VAPP_AM_TRACE1(msg,a) \
            MMI_TRACE(TRACE_GROUP_1,msg,a)
#define VAPP_AM_TRACE2(msg,a,b) \
            MMI_TRACE(TRACE_GROUP_1,msg,a,b)
#define VAPP_AM_TRACE3(msg,a,b,c) \
            MMI_TRACE(TRACE_GROUP_1,msg,a,b,c)            
#endif

#ifdef DEBUG_INFORMATION
    #define VAPP_AM_TRACE_GLOBAL_BUFF_SIZE 260
    char* Vapp_AM_UCS2_to_ASCII(const VfxWChar* strUCS2);
    char* Vapp_AM_UTF8_to_ASCII(const VfxChar* strUTF8);
#endif
//temp trace macro
//
#ifdef _AM_PRINT_TRACE_
#define VAPP_AM_AM_MALLOC "[MRE][FTO AM]<malloc ptr = 0x%08x.size = %d>"
#define VAPP_AM_AM_FREE "[MRE][FTO AM]<free ptr = 0x%08x>"

#define VAPP_AM_ENTER_MASSSTORAGE "[MRE][FTO AM]enterMassStorageModeCB()<>"

#define VAPP_AM_ENTER_AM "[MRE][FTO AM]enter App Manager<app id = %d>"

#define VAPP_AM_WGT_START_CB "[MRE][FTO AM]VappWidgetInfoAdapter::startCallback()<user_data = 0x%08x>"
#define VAPP_AM_WGT_GET_INFO_CB "[MRE][FTO AM]VappWidgetInfoAdapter::getAppInfoCallback()<user_data = 0x%08x>"
//#define VAPP_AM_WGT_GET_INFO_CB_COPYRIGH "[MRE][FTO AM]VappWidgetInfoAdapter::getAppInfoCallback()<copyright = %s>"
//#define VAPP_AM_WGT_GET_INFO_CB_AUTHOR "[MRE][FTO AM]VappWidgetInfoAdapter::getAppInfoCallback()<author = %s>"
#define VAPP_AM_WGT_UNINSTALL_CB "[MRE][FTO AM]VappWidgetInfoAdapter::uninstallCallback()<>"
#define VAPP_AM_WGT_START "[MRE][FTO AM]VappWidgetInfoAdapter::startSrv()<>"
#define VAPP_AM_WGT_GET_APP_LIST_BEGIN "[MRE][FTO AM]VappWidgetInfoAdapter::getAppList()<begin><m_bStarted = %d>" 
#define VAPP_AM_WGT_GET_NUM "[MRE][FTO AM]VappWidgetInfoAdapter::getAppList()<widget srv get number = %d>"
#define VAPP_AM_WGT_GET_APP_LIST_END "[MRE][FTO AM]VappWidgetInfoAdapter::getAppList()<end>" 
#define VAPP_AM_WGT_GET_APP_INFO_BEGIN "[MRE][FTO AM]VappWidgetInfoAdapter::getAppInfo()<begin><m_bStarted = %d, app id = %d>" 
#define VAPP_AM_WGT_GET_APP_INFO_END "[MRE][FTO AM]VappWidgetInfoAdapter::getAppInfo()<end>" 
#define VAPP_AM_WGT_GET_APP_DETAIL_INFO "[MRE][FTO AM]VappWidgetInfoAdapter::getDetailAppInfo()<>"
#define VAPP_AM_WGT_UNINSTALL "[MRE][FTO AM]VappWidgetInfoAdapter::uninstallApp()<>"

#define VAPP_AM_JAVA_GET_APP_LIST_BEGIN "[MRE][FTO AM]VappJavaInfoAdapter::getAppList()<begin>" 
#define VAPP_AM_JAVA_GET_NUM "[MRE][FTO AM]VappJavaInfoAdapter::getAppList()<Java srv get number = %d>"
#define VAPP_AM_JAVA_GET_APP_LIST_END "[MRE][FTO AM]VappJavaInfoAdapter::getAppList()<end>"
#define VAPP_AM_JAVA_GET_APP_INFO_BEGIN "[MRE][FTO AM]VappJavaInfoAdapter::getAppInfo()<begin><app name = %s>" 
#define VAPP_AM_JAVA_GET_APP_INFO_END "[MRE][FTO AM]VappJavaInfoAdapter::getAppInfo()<end>"
#define VAPP_AM_JAVA_UPATE_BEGIN "[MRE][FTO AM]VappJavaInfoAdapter::updateApp()<begin>"
#define VAPP_AM_JAVA_UPATE_END "[MRE][FTO AM]VappJavaInfoAdapter::updateApp()<end>"
#define VAPP_AM_JAVA_UNINSTALL_BEGIN "[MRE][FTO AM]VappJavaInfoAdapter::uninstallApp()<begin>"
#define VAPP_AM_JAVA_UNINSTALL_END "[MRE][FTO AM]VappJavaInfoAdapter::uninstallApp()<end>"
#define VAPP_AM_JAVA_UNINSTALL_CB "[MRE][FTO AM]VappJavaInfoAdapter::uninstallCallback()<result = %d>"

#define VAPP_AM_MRE_GET_APP_LIST_BEGIN "[MRE][FTO AM]VappMREInfoAdapter::getAppList()<begin>" 
#define VAPP_AM_MRE_GET_NUM "[MRE][FTO AM]VappMREInfoAdapter::getAppList()<MRE srv get number = %d>"
#define VAPP_AM_MRE_GET_APP_LIST_END "[MRE][FTO AM]VappMREInfoAdapter::getAppList()<end>" 
#define VAPP_AM_MRE_GET_APP_INFO_BEGIN "[MRE][FTO AM]VappMREInfoAdapter::getAppInfo()<begin><app name = %s>"
#define VAPP_AM_MRE_GET_APP_INFO_END "[MRE][FTO AM]VappMREInfoAdapter::getAppInfo()<end>"
#define VAPP_AM_MRE_GET_APP_DETAIL_INFO_BEGIN "[MRE][FTO AM]VappMREInfoAdapter::getDetailAppInfo()<begin><app name = %s>"
#define VAPP_AM_MRE_GET_APP_DETAIL_INFO_END "[MRE][FTO AM]VappMREInfoAdapter::getDetailAppInfo()<end>"
#define VAPP_AM_MRE_IS_EXIST "[MRE][FTO AM]VappMREInfoAdapter::isExist()<app name = %s, result = %d>"
#define VAPP_AM_MRE_IS_UPDATING "[MRE][FTO AM]VappMREInfoAdapter::isUpdating()<app name = %s, result = %d>"
#define VAPP_AM_MRE_IS_RUNNING "[MRE][FTO AM]VappMREInfoAdapter::isRunning()<app name = %s, result = %d>"
#define VAPP_AM_MRE_CHECK_UPDATE_CB "[MRE][FTO AM]VappMREInfoAdapter::checkUpdateCallback()<>"

#define VAPP_AM_CEATE_ELEMENT_BEGIN "[MRE][FTO AM]VappAMItem::onCreateElements()<begin><app id =%d, app name = %s>"
#define VAPP_AM_CEATE_ELEMENT_END "[MRE][FTO AM]VappAMItem::onCreateElements()<end>"

#define VAPP_AM_LIST_MENU_PAGE_INIT "[MRE][FTO AM]VappAMListPage::onInit()<>"
#define VAPP_AM_MAIN_PAGE_INIT "[MRE][FTO AM]VappAMMainPage::onInit()<>"
#define VAPP_AM_INFO_PAGE_INIT "[MRE][FTO AM]VappAMAppInfoPage::onInit()<>"
#define VAPP_AM_SETTING_PAGE_INIT "[MRE][FTO AM]VappAMSettingPage::onInit()"
#define VAPP_AM_MRE_SETTING_PAGE_INIT "[MRE][FTO AM]VappAMMRESettingPage::onInit()<>"
#define VAPP_AM_WGT_SETTING_PAGE_INIT "[MRE][FTO AM]VappAMMRESettingPage::onInit()<>"
#define VAPP_AM_MENU_POPUP_INIT "[MRE][FTO AM]VappAMMenuPopup::onInit()<>"
#define VAPP_AM_DELETE_POPUP_INIT "[MRE][FTO AM]VappAmDeleteBasePopup::onInit()<>"
#define VAPP_AM_ENTER_JAVA_SETTINGS "[MRE][FTO AM]VappAMAppInfoPage::eventHandler()<enter java settings page>"

#define VAPP_AM_UNINSTALL "[MRE][FTO AM]VappAmUninstall::uninstall()<>"
#define VAPP_AM_DELETE "[MRE][FTO AM]VappAmUninstall::deleteApp()<>"
#define VAPP_AM_UNINSTALL_CB "[MRE][FTO AM]VappAmUninstall::uninstallCallback()<bValid = %d>"
#define VAPP_AM_REMOVE_LIST "[MRE][FTO AM]VappAmUninstall::uninstallCallback()<remove from list, pAppInfo = 0x%08x>"

#define VAPP_AM_UPDATE "[MRE][FTO AM]VappAmUpdate::update()<>"
#define VAPP_AM_CHECKED_UPDATE "[MRE][FTO AM]VappAmUpdate::onCheckedUpdate()<bValid = %d>"
#endif //_AM_PRINT_TRACE_

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef void (VfxObject::*oFun)(VfxObject*);

/***************************************************************************** 
 * Enum
 *****************************************************************************/
enum VAPP_AM_MRE_DA_TYPE_ENUM
{
    VAPP_AM_MRE_DA_NO_PROXY,
    VAPP_AM_MRE_DA_PROXY
};

/***************************************************************************** 
 * Classes 
 *****************************************************************************/
class VappUSBOperator : public VfxObject
{
public:
    virtual void onInit();
    virtual void onDeinit();
    static mmi_ret enterMassStorageModeCB(mmi_event_struct *param);
    static VfxBool isMassStorageMode();
    static void showPopup();
public:
    VfxSignal0  m_enterMSSignal;
};


#ifdef _AM_TEST_
class VappAMUTArrow
{
private:
    static const  VfxU32    m_amUTFlagArrow[9];
    VfxS32                  m_index;
    
public:
    VappAMUTArrow():m_index(-1){};
    VfxU32 getUTFlag()
    {
        return m_amUTFlagArrow[m_index%9];
    };

    void updateUTFlag()
    {
        m_index++;
    };
};

#endif //_AM_TEST_


class VappDialerCUIInstance
{
public:    
    static void runInstance(const VfxWString &str);
    static void closeInstance();

    static mmi_ret proc(mmi_event_struct *evt); 

    static mmi_id  m_id;
};

class VscrPara:public VfxBase
{
public:
    VscrPara();
    VfxS32 width();
    VfxS32 height();
private:
    VfxSize m_size;
};

class VappDetailInfo : public VfxObject
{
public:
    enum VappDetailInfoEnum
    {
        VAPP_AM_DETAIL_INFO_NONE = -1,   //no define
        VAPP_AM_DETAIL_INFO_INTRODUCE , //introduce of the app
        VAPP_AM_DETAIL_INFO_SIZE,   //app size
        VAPP_AM_DETAIL_INFO_AUTHOR,   //author
        VAPP_AM_DETAIL_INFO_COPYRIGHT,//copyright
        VAPP_AM_DETAIL_INFO_VERSION, //version
        VAPP_AM_DETAIL_INFO_AUTHORIZED,//authorized
        VAPP_AM_DETAIL_INFO_WEBSITE,
        VAPP_AM_DETAIL_INFO_NUMBER //telephone number
    };
    
    VappDetailInfo():m_type(VAPP_AM_DETAIL_INFO_NONE),m_next(NULL){};

    VappDetailInfoEnum      m_type;
    VfxWString              m_wstrContent;

    VappDetailInfo* m_next;
};

class IVappInfoAdapter;
class VappAMItem;
class VappAMAppInfoPage;

class VappInfo : public VfxObject
{
public:   
    
    enum VAPP_AM_APP_TYPE_ENUM
    {
        VAPP_AM_APP_TYPE_NONE = -1,
        VAPP_AM_APP_TYPE_MRE,
        VAPP_AM_APP_TYPE_JAVA,
        VAPP_AM_APP_TYPE_WIGHET,
        VAPP_AM_APP_TYPE_MRE_VSO,
    };
    enum VAPP_AM_APP_POS_ENUM
    {
        VAPP_AM_APP_POS_NONE = -1,
        VAPP_AM_APP_POS_PHONE,
        VAPP_AM_APP_POS_CARD
    };
    enum VAPP_AM_APP_INSTALL_TYPE_ENUM
    {
        VAPP_AM_APP_INSTALL_TYPE_NONE = -1,
        VAPP_AM_APP_INSTALL_TYPE_INSTALL,//local install app
        VAPP_AM_APP_INSTALL_TYPE_DOWNLOAD,
        VAPP_AM_APP_INSTALL_TYPE_NATIVE //build-in app
    };
    
    VappInfo():m_strApp(NULL),m_type(VAPP_AM_APP_TYPE_NONE),m_iconId(0),m_memPtr(NULL),m_storage(VAPP_AM_APP_POS_NONE),
                m_pDetailInfoList(NULL),m_bUpdatable(VFX_TRUE),m_bUninstallable(VFX_TRUE),m_pAdapter(NULL),
                m_bGetInfo(VFX_FALSE),m_bGetDetail(VFX_FALSE)
    {
    };

    //get app information that will not cost too much time
    VfxS32  getAppInfo();
    VfxS32  getAppDetailInfo();
    VfxBool isExist();
    VfxBool isUpdating();
    VfxBool isRunning();
    void    releaseAppDetailInfo();// release heavy resouce

    VfxS32  checkUpdate();
    VfxS32  updateApp();
    VfxS32  uninstallApp();
    
    void    appendDetailInfo(VappDetailInfo* pDetailInfo);

    void    fresh();
public: 
    VfxS32      m_appID;
    VfxChar*    m_strApp; //
    VfxS32      m_type;// VAPP_AM_APP_TYPE_ENUM
    //AM main UI relative
    VfxWString  m_wstrAppName;
    VfxWString  m_wstrInstallTime;
    VfxId       m_iconId;
    VfxWString  m_wstrIconPath;
    VfxU8*      m_memPtr;
    VfxU32     m_memLength;
    VfxS32      m_installtype; // VAPP_AM_APP_INSTALL_TYPE_ENUM
    VfxS32      m_storage;// VAPP_AM_APP_POS_ENUM
    //Infor
    VappDetailInfo* m_pDetailInfoList;// detial information of the app   
    //other infor
    VfxBool         m_bUpdatable; 
    VfxBool         m_bUninstallable; 
    //Adapter to apps
    IVappInfoAdapter* m_pAdapter;
    
private:
    //already get infor flag
    VfxBool         m_bGetInfo;
    //already get details infor flag
    VfxBool         m_bGetDetail;
    
};
       
class VappBaseSettings : public VfxObject
{
public:
    VfxBool     m_bWiFiOnly;
    VfxBool     m_bNetWork;
};

class IVappDataAccountAdapter;
class VappAMDataAccount : public VfxObject
{
public:
    enum VAPP_AM_DA_TYPE
    {
        VAPP_AM_DA_TYPE_WGT,
        VAPP_AM_DA_TYPE_MRE,
        VAPP_AM_DA_TYPE_MRE_PROXY
    };
    VappAMDataAccount(VfxU32 type = VAPP_AM_DA_TYPE_WGT);

    mmi_id          m_mmiId; 
#ifdef _AM_DATA_ACCOUNT_
    cui_dtcnt_select_run_struct m_runData;
#endif
    
    void show();  
    mmi_ret onProc(mmi_event_struct *evt);
    
private:
    void set();
    void close();    
    static mmi_ret onUpdate(mmi_event_struct *param);
    IVappDataAccountAdapter*    m_pDAAdapter;
    VfxU32                      m_type; //detail type
};


class VappInfoList;

class IVappInfoAdapter 
{
public:
    virtual VfxS32  startSrv() = 0;
    virtual void  stopSrv() = 0;
    virtual VfxS32  getAppList(VappInfoList* pInfoList) = 0;
    
    virtual VfxS32  getAppInfo(VappInfo* pAppInfo) = 0;
    virtual VfxS32  getDetailAppInfo(VappInfo* pAppInfo) = 0;
    virtual VfxBool isExist(VappInfo* pAppInfo) = 0;
    virtual VfxBool isUpdating(VappInfo* pAppInfo) = 0;
    virtual VfxBool isRunning(VappInfo* pAppInfo) = 0;
    
    virtual void getSettings(VappBaseSettings* pSettings) = 0;
    virtual VfxS32 setSettings(const VappBaseSettings* pSettings) = 0;

    virtual VfxS32 checkUpdate(VappInfo* pAppInfo) = 0;
    virtual VfxS32 updateApp(VappInfo* pAppInfo) = 0;
    virtual VfxS32  uninstallApp(VappInfo* pAppInfo) = 0;

public:
    //signal   
    VfxSignal0              m_startedSignal;
    VfxSignal0              m_updatedSignal;
    VfxSignal1<VfxS32>      m_checkedUpdateSignal;
    VfxSignal1<VfxS32>      m_uninstallSignal;
    VfxSignal0              m_getInfoSignal;
    IVappInfoAdapter*       m_pNext;
};

class IVappDataAccountAdapter
{
public:
    virtual void getDataAccount(VappAMDataAccount* pDA, VfxU32 type = 0) = 0;
    virtual void setDataAccount(const VappAMDataAccount* pDA, VfxU32 type = 0) = 0;
};

//use this class to avoid too much compile option
class VappAdapterFactory
{
public:
    static IVappInfoAdapter* getInfoAdapter(VfxS32 type);
    static IVappDataAccountAdapter* getDAAdapter(VfxS32 type);
};

#ifdef _AM_APP_TEST_
class VappTestInfoAdapter 
:public VfxObject, public IVappInfoAdapter
{

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappTestInfoAdapter);
public:    
    VappTestInfoAdapter();
    
    virtual VfxS32  startSrv();
    virtual void  stopSrv();
    virtual VfxS32  getAppList(VappInfoList* pInfoList);
    
    virtual VfxS32  getAppInfo(VappInfo* pAppInfo);
    virtual VfxS32  getDetailAppInfo(VappInfo* pAppInfo);
    virtual VfxBool isExist(VappInfo* pAppInfo);
    virtual VfxBool isUpdating(VappInfo* pAppInfo);
    virtual VfxBool isRunning(VappInfo* pAppInfo);
    
    virtual void getSettings(VappBaseSettings* pSettings);

    virtual VfxS32 setSettings(const VappBaseSettings* pSettings);

    virtual VfxS32 checkUpdate(VappInfo* pAppInfo);
    virtual VfxS32 updateApp(VappInfo* pAppInfo);
    virtual VfxS32  uninstallApp(VappInfo* pAppInfo);
    static VfxU32   m_count;
};
#endif //_AM_APP_TEST_

#ifdef __GADGET_SUPPORT__
class VappWidgetInfoAdapter 
:public VfxObject, public IVappInfoAdapter, public IVappDataAccountAdapter
{

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappWidgetInfoAdapter);
public:    
    VappWidgetInfoAdapter();

    virtual VfxS32  startSrv();
    virtual void  stopSrv();
    virtual VfxS32  getAppList(VappInfoList* pInfoList);
    
    virtual VfxS32  getAppInfo(VappInfo* pAppInfo);
    virtual VfxS32  getDetailAppInfo(VappInfo* pAppInfo);
    virtual VfxBool isExist(VappInfo* pAppInfo);
    virtual VfxBool isUpdating(VappInfo* pAppInfo);
    virtual VfxBool isRunning(VappInfo* pAppInfo);
    
    virtual void getSettings(VappBaseSettings* pSettings);

    virtual VfxS32 setSettings(const VappBaseSettings* pSettings);

    virtual VfxS32 checkUpdate(VappInfo* pAppInfo);
    virtual VfxS32 updateApp(VappInfo* pAppInfo);
    virtual VfxS32  uninstallApp(VappInfo* pAppInfo);
    
    virtual void getDataAccount(VappAMDataAccount* pDA, VfxU32 type = 0);
    virtual void setDataAccount(const VappAMDataAccount* pDA, VfxU32 type = 0);
    
private:
    static void startCallback(void* user_data); 
    static void getAppInfoCallback(srv_wgtmgr_wgt_detail_struct *info, void* user_data);
    static void uninstallCallback(void* user_data);
    
    static void translateTime(VfxU32 time, VfxWString& wstrTime);

private:    
    VfxBool m_bStarted;
    void*   m_pMem;
};
#endif //__GADGET_SUPPORT__

#ifdef __J2ME__

class VappJavaInfoAdapter :public VfxObject, public IVappInfoAdapter
{

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappJavaInfoAdapter);
public:    
    VappJavaInfoAdapter();

    virtual VfxS32  startSrv();
    virtual void  stopSrv();
    virtual VfxS32  getAppList(VappInfoList* pInfoList);
    
    virtual VfxS32  getAppInfo(VappInfo* pAppInfo);
    virtual VfxS32  getDetailAppInfo(VappInfo* pAppInfo);
    virtual VfxBool isExist(VappInfo* pAppInfo);
    virtual VfxBool isUpdating(VappInfo* pAppInfo);
    virtual VfxBool isRunning(VappInfo* pAppInfo);
    
    virtual void getSettings(VappBaseSettings* pSettings);

    virtual VfxS32 setSettings(const VappBaseSettings* pSettings);

    virtual VfxS32 checkUpdate(VappInfo* pAppInfo);
    virtual VfxS32 updateApp(VappInfo* pAppInfo);
    virtual VfxS32 uninstallApp(VappInfo* pAppInfo);

private: 
    mmi_app_package_name_struct* m_pList;
    static void uninstallCallback(void * user_data, kal_int32 result);
    static VfxBool isURLString(VfxWChar* str);
};

#endif //__J2ME__

//class VappAmUpdatePopup;
class VappMREInfoAdapter 
:public VfxObject, public IVappInfoAdapter, public IVappDataAccountAdapter
{

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappMREInfoAdapter);
public:    
    VappMREInfoAdapter();

    virtual VfxS32  startSrv();
    virtual void  stopSrv();
    virtual VfxS32  getAppList(VappInfoList* pInfoList);
    
    virtual VfxS32  getAppInfo(VappInfo* pAppInfo);
    virtual VfxS32  getDetailAppInfo(VappInfo* pAppInfo);
    virtual VfxBool isExist(VappInfo* pAppInfo);
    virtual VfxBool isUpdating(VappInfo* pAppInfo);
    virtual VfxBool isRunning(VappInfo* pAppInfo);
    
    virtual void getSettings(VappBaseSettings* pSettings);

    virtual VfxS32 setSettings(const VappBaseSettings* pSettings);

    virtual VfxS32 checkUpdate(VappInfo* pAppInfo);
    virtual VfxS32 updateApp(VappInfo* pAppInfo);
    virtual VfxS32 uninstallApp(VappInfo* pAppInfo);

    virtual void getDataAccount(VappAMDataAccount* pDA, VfxU32 type = VAPP_AM_MRE_DA_NO_PROXY);
    virtual void setDataAccount(const VappAMDataAccount* pDA, VfxU32 type = VAPP_AM_MRE_DA_NO_PROXY);

    static void enterDownLoadUI(VappInfo* pAppInfo);
    
protected:
//    static void checkUpdateCallback(U32 appid, srv_mre_appmgr_check_update_state_enum state,
      //                                                U32 filesize, U16 *filename); 
   // static void updateCallback(U32 appid, srv_mre_appmgr_update_state_enum state, void *user_data);   
   // static VfxS32 transErrorCode(srv_mre_appmgr_check_update_state_enum state);

    VfxU32      m_appId;
    VfxU32      m_fileSize;
    VfxWString  m_fileName;
    mmi_app_package_name_struct* m_pList;
};

class VappMREVSOInfoAdapter 
:public VappMREInfoAdapter
{

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappMREVSOInfoAdapter);
public:    
    virtual VfxS32  getAppList(VappInfoList* pInfoList);
};

class VappInfoList : public VfxObjList
{
public:
    typedef void (VfxObject::*NotifyFun)(void); 

    //this class is used to compare app name
    class VappInfoComparetor
    {
    public:
        static VfxS32 compare(VappInfo* pAppInfo1, VappInfo* pAppInfo2)
        {
            // TODO: need to revise!!
            return srv_phb_compare_pinyin_string((U16*)pAppInfo1->m_wstrAppName.getBuf(),
                            (U16*)pAppInfo2->m_wstrAppName.getBuf());
        };
    };
   
public:    
    VappInfoList();
    
    void setAddNotifyFunction(VfxObject* pObj, NotifyFun fun);    
    void setRemoveNotifyFunction(VfxObject* pObj, NotifyFun fun);
    void setAdapter(IVappInfoAdapter* pAdapter);    
    VfxS32 getAppListFromSrv();
    void fresh(){m_bAlreadyGetList = VFX_FALSE;};
    VfxObjListEntry *append(VfxObject *obj);    
    VfxBool removeOne(VfxObject *obj);
    VfxObject* operator [](VfxU32 index);

    IVappInfoAdapter*   m_pAdapter;
 //   IVappInfoAdapter*   m_pAdapter1;
    
protected:    
    VfxSignal0          m_signalAdd;
    VfxSignal0          m_signalRemove;
    VfxU32              m_index;
    VfxObjListEntry*    m_pIndexEntry;
    
    VfxBool             m_bAlreadyGetList;
    
private:
    //prevent to use this
    VfxObjListEntry *prepend(VfxObject *obj){return NULL;};
    VfxObjListEntry *insertBefore(VfxObjListEntry *entry, VfxObject *obj){return NULL;};
    VfxObjListEntry *insertAfter( VfxObjListEntry *entry, VfxObject *obj){return NULL;};
};

class VappAMApp;
class VappAMMainSrc : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappAMMainSrc);

// Override
protected:
    virtual void on1stReady();

    friend class VappAMApp;
};

class VappAMApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappAMApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize); 
    
    static VappAMMainSrc* getMainScr()
    {
        if (m_pMainSrc)
        {
            return m_pMainSrc->get();
        }
        return NULL;
    };

    static void initApp();
    static VfxWeakPtr<VappAMMainSrc>*   m_pMainSrc;
    VfxWeakPtr<VappAMMainSrc>   m_MainSrc;
    static mmi_id           m_mmiId;
protected:
    VappInfoList            m_AppInfoList;
    VappInfoList            m_WidgetInfoList;
    VfxBool                 m_bInited;        
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *evt);
};

#ifdef __MMI_COSMOS_APP_MANAGER__

class VappAMItem : public VcpListMenuCellClientBaseFrame
{
    VFX_DECLARE_CLASS(VappAMItem);
public:    
    VappAMItem(VappInfo *pAppInfo);
    virtual ~VappAMItem();

    virtual void onCreateElements();
    virtual void onCloseElements();
    virtual void onLayoutElements();
    virtual void onUpdateElements();
    VappInfo* getAppInfo();

    static VfxSize  m_itemSize;
// Override
protected:
    VappAMItem();
    
protected:
    VappInfo*       m_pAppInfo;
    VfxFrame*       m_pAppIcon;
    VfxTextFrame*   m_pAppName;
    VfxTextFrame*   m_pInstallTime;
    VfxImageFrame*  m_pStorageIcon;
    VfxImageFrame*  m_pInstallTypeIcon;    
    friend class VappAMListMenuContentProvider;
};

class VappAMListMenuContentProvider : public VfxObject, public IVcpListMenuContentProvider
{
// Override
public:
    VappAMListMenuContentProvider(VappInfoList* appInfoList):m_pAppInfoList(appInfoList)
    {};

    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
    {        
        return VFX_FALSE;
    }

    virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
    {
        return VFX_FALSE;
    }
  
    virtual void closeItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType, 
        VfxImageSrc Image               
        ) {}

    virtual VfxU32 getCount() const
    {
        return m_pAppInfoList->getValidCount();  
    }

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const { return VCP_LIST_MENU_ITEM_STATE_NONE;}

    
    virtual VfxBool swapItem(
        VfxU32 index1, 
        VfxU32 index2 
        ) 
    {
        
        return VFX_TRUE;
    }

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,
        VfxFrame *parentFrame
        )
    {
        VappAMItem* pAmItem = NULL;
        VappInfo*   pAppInfo = (VappInfo*)(*m_pAppInfoList)[index];
        //get app information
        pAppInfo->getAppInfo();
 
        VFX_OBJ_CREATE_EX(pAmItem, VappAMItem, parentFrame,(pAppInfo));

        return (VcpListMenuCellClientBaseFrame *)pAmItem;
    }

    virtual void closeItemCustomContentFrame(
        VfxU32 index,  
        VcpListMenuCellClientBaseFrame *cell 
        )
    {
        if (cell)
        {
            VappAMItem* pAmItem = (VappAMItem*)cell;
            //if this is MRE App , we release the detail information
            if (VappInfo::VAPP_AM_APP_TYPE_MRE == pAmItem->m_pAppInfo->m_type)
            {
                pAmItem->m_pAppInfo->releaseAppDetailInfo();
            }
            VFX_OBJ_CLOSE(cell);
        }
    }
private:
    VappInfoList* m_pAppInfoList;
};


class VappAMListMenuCell :public VcpListMenuCell
{
public:
    VappAMListMenuCell(VcpListMenuCellStyleEnum style, VcpMenuPos pos);
    VappInfo* getAppInfo();
protected:
    virtual VfxBool onPenInput(VfxPenEvent &event);
protected:

     VfxBool    m_bTap;
     VfxBool    m_bMoving; 
};


class VappAMListMenu : public VcpListMenu
{
    VFX_DECLARE_CLASS(VappAMListMenu);
public:
    
    VappAMListMenu(VappInfoList* pInfoList);

    VfxSignal1 <VfxObject*> m_signalLongTap;
    VfxSignal1 <VfxObject*> m_signalTap;
    
protected:
    virtual void onInit();

    void onLongTap(VcpListMenu* pMenu, VfxU32 index);
    void onTap(VcpListMenu* pMenu, VfxU32 index);
    void onRemoveItem();
    
private:
    VappAMListMenu();
       
    VappInfoList*           m_pAppInfoList;
    VcpForm*                m_pForm;
    friend class VappAMItem;
    friend class VappAMListMenuCell;
};

class VappAMListPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappAMListPage);
public:
    
    VappAMListPage(VappInfoList* pInfoList);

    void updatePage();
    void setLongTapFunction(VfxObject* pObj, oFun fun);
    void setTapFunction(VfxObject* pObj, oFun fun);
    void setListBounds(const VfxRect& rect);

    void onUpdatePage();
    
protected:
    virtual void onInit();
    void onTime(VfxTimer *timer);
private:
    VappAMListPage();
    VfxTextFrame*       m_pText;
    VappAMListMenu*     m_pListMenu;
    VappInfoList*       m_pAppInfoList;
};


#ifdef _AM_FULL_SUPPORT_

class VappAMMainPage : public VcpTabCtrlPage
{
    VFX_DECLARE_CLASS(VappAMMainPage);
public:
    static VfxId m_pageId;

    VappAMMainPage();
    void update();
protected:
    virtual void onInit();
    virtual void onEntered();
    virtual void onTabSwitched(VfxId tabId);
    virtual VfxPage* onCreateTabPage(VfxId tabId); 
    void    eventHandler(VfxObject* pObj, VfxId id);
    void    onTap(VfxObject* pObj);
    void    onLongTap(VfxObject* pObj);
    void    onTime(VfxTimer* pTime);

private:
    VfxBool m_bFirstIn;
};

#else //_AM_FULL_SUPPORT_

class VappAMMainPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappAMMainPage);
public:
    static VfxId m_pageId;

    VappAMMainPage();
    void update();
protected:
    virtual void onInit();
//    virtual void onAfterInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    void    eventHandler(VfxObject* pObj, VfxId id);
    void    onTap(VfxObject* pObj);
    void    onLongTap(VfxObject* pObj);
    void    onTime(VfxTimer* pTime);

private:
    VappAMListPage *m_pAmListpage;
    VfxBool         m_bFirstIn;
}; 

#endif // _AM_FULL_SUPPORT_

class VappAMAppInfoItem : public VcpFormItemBase
{
    VFX_DECLARE_CLASS(VappAMAppInfoItem);
public:
    void setTitle(const VfxWString& wstrTitle);
    void setText(const VfxWString& wstrContent);
    void forceUpdate();
    void setFirst();
//    static VfxS32   m_margin;
protected:
    virtual void onInit();

protected:
    VfxTextFrame*   m_pTitle;
    VfxTextFrame*   m_pContent;
    VfxS32          m_firstMargin;
};

class VappAMAppInfoKeyWord : public VcpFormItemBase
{
    VFX_DECLARE_CLASS(VappAMAppInfoKeyWord);
public:
    void setNumber(const VfxWString& wstrNumber);
    void setWebsize(const VfxWString& wstrWeb);
    
//    static VfxS32   m_margin;
protected:
    virtual void onInit();
    void onKeywordClicked(VcpTextKeyWordEnum mode, VfxWChar* text, VfxS32 len);
    static void getPureNumber(VfxWChar* text, VfxWChar* outNumber);

protected:
    VfxTextFrame*   m_pTitle;
    VcpTextView*   m_pContent;
};

class VappAMAppInfoPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappAMAppInfoPage);
public:
    VappAMAppInfoPage(VappInfo* pAppInfo);   
    
    void    showPage();
    void    updatePage();

    VappInfo*   m_pAppInfo;
    static VfxId m_pageId;
    
protected:
    virtual void onInit();
    void    eventHandler(VfxObject* pObj, VfxId id);
    
    void    updateInfo();
    void    onUpdateInfo();
    void    onUninstall(VfxS32 bRet);
    virtual mmi_ret onProc(mmi_event_struct *evt);

protected:
    VcpToolBar* m_pToolBar;
    VcpForm*    m_pForm;

private:
    VappAMAppInfoPage();
    
};

class VappAMSettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappAMSettingPage);
public:
    VappAMSettingPage();

    static VfxId m_pageId;
    
protected:
    virtual void onInit();
    void    eventHandler(VcpFormItemCell* sender, VfxId id);       
};

class VappAMDataAccount;

class VappAMMRESettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappAMMRESettingPage);
public:
    VappAMMRESettingPage();

    static VfxId m_pageId;
    
protected:
    virtual void onInit();
#ifdef __MMI_MRE_DTCNT_SETTING__     
    void eventHandler(VcpFormItemCell* sender, VfxId id);
    virtual mmi_ret onProc(mmi_event_struct *evt);
#endif //__MMI_MRE_DTCNT_SETTING__     

#if _AM_WIFI_ONLY_ //remove wifi only   
    void switchHandler(VcpFormItemSwitchCell* sender, VfxId id, VfxBool bState);
#endif    
    
    
protected:   
    VappBaseSettings            m_settings;
    VcpFormItemSwitchCell*      m_wifiSetting;
#ifdef __MMI_MRE_DTCNT_SETTING__    
    VcpFormItemLauncherCell*    m_pDACell;
    VcpFormItemLauncherCell*    m_pDACellPx;
    VappAMDataAccount*          m_pDataAccount; 
    VappAMDataAccount*          m_pDataAccountPx;
    VappAMDataAccount*          m_pCurDataAccount;
#endif //__MMI_MRE_DTCNT_SETTING__    
};


#ifdef __GADGET_SUPPORT__ 
class VappAMWGTSettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappAMWGTSettingPage);
public:
    VappAMWGTSettingPage();

    static VfxId m_pageId;
    
protected:
    virtual void onInit();
    void eventHandler(VcpFormItemCell* sender, VfxId id);
    void switchHandler(VcpFormItemSwitchCell* sender, VfxId id, VfxBool bState);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    
protected:
    VcpFormItemSwitchCell*      m_netAccess;
    VcpFormItemSwitchCell*      m_wifiSetting;
    VcpFormItemLauncherCell*    m_pDACell;
    VappBaseSettings            m_settings;
    VappAMDataAccount*          m_pDataAccount;
};
#endif //__GADGET_SUPPORT__

//************************************************************************
//some internal use popup classes
//************************************************************************
//parent MUST be MainScreen
class VappAMMenuPopup : public VcpMenuPopup
{
    VFX_DECLARE_CLASS(VappAMMenuPopup);
public:    
    VappAMMenuPopup(VappInfo* pAppInfo);
protected:
    virtual void onInit();
    void onSelect(VcpMenuPopup* pMenu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item);
private:
    VappAMMenuPopup(){};
    
    VappInfo*   m_pAppInfo;
    
};


class VappAmDeleteBasePopup : public VcpConfirmPopup
{
    VFX_DECLARE_CLASS(VappAmDeleteBasePopup);
public:
    VappAmDeleteBasePopup(VappInfo* pAppInfo);

    
protected:
    virtual void onInit();
    void onClick(VfxObject* pObj, VfxId id);


    VappAmDeleteBasePopup();
    
    VappInfo*   m_pAppInfo;    
};

class VappAmDeletePopup : public VappAmDeleteBasePopup
{
    VFX_DECLARE_CLASS(VappAmDeletePopup);
public:
    VappAmDeletePopup(VappInfo* pAppInfo);

protected:
    virtual void onInit();
    
private:   
    VappAmDeletePopup();

    
};

class VappAmDeleteCardPopup : public VappAmDeleteBasePopup
{
    VFX_DECLARE_CLASS(VappAmDeleteCardPopup);
public:
    VappAmDeleteCardPopup(VappInfo* pAppInfo);

protected:
    virtual void onInit();
    
private:   
    VappAmDeleteCardPopup();    
};

class VappAmDeletePhonePopup : public VappAmDeleteBasePopup
{
    VFX_DECLARE_CLASS(VappAmDeletePhonePopup);
public:
    VappAmDeletePhonePopup(VappInfo* pAppInfo);

protected:
    virtual void onInit();
    
private:   
    VappAmDeletePhonePopup();    
};

class VappAmUpdatePopup : public VcpIndicatorPopup
{
        VFX_DECLARE_CLASS(VappAmUpdatePopup);
    public:
        VappAmUpdatePopup();

    protected:
        virtual void onInit();

        VfxTextFrame*   m_textFrame;
};

//************************************************************************
//uninstall operator class
//************************************************************************
//parent MUST be MainScreen
class VappAmUninstall : public VfxObject
{
public:
    enum VAPP_AM_UNINSALL_ENUM
    {
        VAPP_AM_UNINSALL_OK,
        VAPP_AM_UNINSALL_CANCEL,
        VAPP_AM_UNINSALL_FAIL
    };
    
    typedef void (VfxObject::*notifyFunc)(VfxS32);    
    VappAmUninstall(VappInfo* pAppInfo);

//    void setAppInfo(VappInfo* pAppInfo);
    void setInfoPopup(VfxBool bShow);
    void uninstall(); //app file is exist
    void deleteApp(); //app file is not exit
    
    void setNotifyFunction(VfxObject* pObj,notifyFunc fun);
    void onClick(VfxObject* pObj, VfxId id);
    void uninstallCallback(VfxS32 result);
    
protected:
	virtual void onInit();

    VfxBool                 m_bShow; //show info popup or not
    VappAmDeleteBasePopup*  m_pPopup;
    VcpIndicatorPopup*      m_pWaiting;
    VappInfo*               m_pAppInfo;
    VfxSignal1<VfxS32>      m_notifySignal;
};

//************************************************************************
//Update operator class
//************************************************************************
//parent MUST be MainScreen
class VappAmUpdate : public VfxObject
{
public:
    typedef struct 
    {
        VfxObject*  pObj;
        VfxU32      pid;    
    }update_cb_data;
    
    VappAmUpdate(VappInfo* pAppInfo);
    void update();
    static void updateCallback(update_cb_data* pData);
    
protected:
    virtual void onInit();
    void onCheckedUpdate(VfxS32 result);
    void onUpdateApp(VfxObject* pObj, VfxId id);
    void onCancelCheckUpdate(VfxObject* pObj, VfxFloat f);
    
    VappAmUpdatePopup*  m_pUpdatePopup;  
    VappInfo*           m_pAppInfo;
#ifdef _AM_TEST_
    void onTime(VfxTimer* pTime);
    VfxTimer*           m_pTimer;            
#endif //_AM_TEST_
};

#endif //__MMI_COSMOS_APP_MANAGER__
#endif //__COSMOS_MMI_PACKAGE__#endif //__VAPP_APP_MANAGER_H__
#endif //__VAPP_APP_MANAGER_H__
