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
 * Vapp_mre_app_operator.cpp
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
/***************************************************************************** 
* Include
*****************************************************************************/
#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_features.h"
#include "vapp_mre_app_operator.h"
#include "vapp_mre_app_ncenter.h"
#include "vapp_setting_date_time_setting.h"
#include "vapp_nmgr_gprot.h"


extern "C"
{
#include "mmi_features.h"
#include "vmsys.h"
#include "vmsock.h"
#include "MRESrvGProt.h"
#include "MREAppmgrsrvgprot.h"
#include "app_datetime.h" // time relative
#include "mmi_rp_vapp_app_manager_def.h"
#include "mmi_rp_vapp_mre_app_operator_def.h"
#include "mmi_rp_vapp_m_space_def.h"
#include "mmi_rp_app_mre_def.h"
#include "vmmem.h"

#if !defined(__MMI_MRE_NO_POPUP_AUTHENTICATION_SUPPORT__)
#define _MRE_NO_AUTH_SUPPORT_
#endif
//#define __MMI_MRE_SWLA_DEBUG__

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MMI_MRE_SWLA_DEBUG__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define MRE_SWLA_START(_symbol_)
#define MRE_SWLA_STOP(_symbol_)
#endif


//for test
extern void vapp_app_manager_entry(void);
VMINT vm_mre_pre_malloc_app_mem(WCHAR* path, void (*callback)(void));
void vm_mre_free_pre_app_mem(void);

}


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define ABSSUB(a,b) (a)>(b)?(a)-(b):(b)-(a)


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern VscrPara        g_scrPara;

#ifdef _AM_TEST_
extern VappAMUTArrow g_UT;
#endif //_AM_TEST_
WCHAR* g_vapp_app_path = NULL;

void vapp_asm_callback(void)
{
    if (g_vapp_app_path)
    {
//        vm_mre_pre_malloc_app_mem(g_vapp_app_path,vapp_asm_callback); 
        
        mmi_id app_id = VfxAppLauncher::launch( 
            VAPP_MRE_APP_OPERATOR, 
            VFX_OBJ_CLASS_INFO(VappMRELauncherEx),
            GRP_ID_ROOT,
            g_vapp_app_path, 2*mmi_wcslen(g_vapp_app_path)+2);
            
        _vm_kernel_free(g_vapp_app_path);
        g_vapp_app_path = NULL;
    }
    else
  	{
  		StartTimer(MRE_SRV_OOM_TIMER, 10, vapp_asm_callback);
  	}
}
/***************************************************************************** 
 * Main Entry
 *****************************************************************************/
extern "C" void vapp_mre_app_launch(CHAR* appName)
{
    if (VappUSBOperator::isMassStorageMode())
    {
        VappUSBOperator::showPopup();
        return;
    }

    VfxWChar appPath[SRV_FMGR_PATH_MAX_LEN + 1]={0};

    if (srv_mre_appmgr_get_file_path(appName,appPath))
    {
        if (!srv_mre_is_app_bg_running(appPath))
        {
            if (1 == vm_mre_pre_malloc_app_mem(appPath,vapp_asm_callback))
            {
                g_vapp_app_path = (WCHAR*)_vm_kernel_malloc(2*(SRV_FMGR_PATH_MAX_LEN + 1));
                ASSERT(g_vapp_app_path);
                kal_wstrcpy(g_vapp_app_path,appPath);
                return;
            }
        }
    }
    else
    {
        ASSERT(0);
    }
    
    
    if (appName)
    {
        mmi_id app_id = VfxAppLauncher::launch( 
            VAPP_MRE_APP_OPERATOR, 
            VFX_OBJ_CLASS_INFO(VappMRELauncher),
            GRP_ID_ROOT,
            appName, strlen(appName)+1); 
        VAPP_AM_TRACE1(VAPP_MRE_ENTER_LAUNCH,app_id);
    }
#ifdef _AM_TEST_    
    g_UT.updateUTFlag();
#endif //_AM_TEST_ 
}

extern "C" void vapp_mre_app_launch_by_path(WCHAR* appPtah)
{
    if (VappUSBOperator::isMassStorageMode())
    {
        VappUSBOperator::showPopup();
        return;
    }

    if (!srv_mre_is_app_bg_running(appPtah))
    {
        if (1 == vm_mre_pre_malloc_app_mem(appPtah,vapp_asm_callback))
        {
            g_vapp_app_path = (WCHAR*)_vm_kernel_malloc(2*(SRV_FMGR_PATH_MAX_LEN + 1));
            ASSERT(g_vapp_app_path);
            kal_wstrcpy(g_vapp_app_path,appPtah);
            return;
        }
    }
    if (appPtah)
    {
        mmi_id app_id = VfxAppLauncher::launch( 
            VAPP_MRE_APP_OPERATOR, 
            VFX_OBJ_CLASS_INFO(VappMRELauncherEx),
            GRP_ID_ROOT,
            appPtah, 2*mmi_wcslen(appPtah)+2); 
        VAPP_AM_TRACE1(VAPP_MRE_ENTER_LAUNCH,app_id);
    }
#ifdef _AM_TEST_    
    g_UT.updateUTFlag();
#endif //_AM_TEST_ 
}

extern "C" void vapp_mre_app_install(WCHAR* appPtah)
{
    if (VappUSBOperator::isMassStorageMode())
    {
        VappUSBOperator::showPopup();
        return;
    }

    if (appPtah)
    {
        mmi_id app_id = VfxAppLauncher::launch( 
            VAPP_MRE_APP_OPERATOR, 
            VFX_OBJ_CLASS_INFO(VappMREInstaller),
            GRP_ID_ROOT,
            appPtah, 2*mmi_wcslen(appPtah)+2);
        VAPP_AM_TRACE1(VAPP_MRE_ENTER_INSTALL,app_id);
    }
#ifdef _AM_TEST_    
    g_UT.updateUTFlag();   
#endif //_AM_TEST_   
}

#ifndef _MRE_LOADING_POPUP_
extern "C" void gdi_draw_solid_rect(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color rect_color);
static void vapp_entry_loading_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    S32 width,height;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_VAPP_AM, SCR_ID_VAPP_AM_LOADING, NULL, vapp_entry_loading_scrn, MMI_FRM_FG_ONLY_SCRN);

    if (ret == MMI_FALSE)
    {
        return;
    }

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, GDI_COLOR_BLACK);

    gdi_image_get_dimension_id(VAPP_AM_IMG_APPMANAGER, &width, &height);
    gdi_image_draw_id((UI_device_width - width) >> 1, (UI_device_height - height) >> 1, VAPP_AM_IMG_APPMANAGER);
    return;

}

static void vapp_show_loading_scr()
{
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_VAPP_AM, NULL, NULL);
    mmi_frm_group_enter(GRP_ID_VAPP_AM, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    vapp_entry_loading_scrn();
}

static void vapp_close_loading_scr()
{
    mmi_frm_group_close(GRP_ID_VAPP_AM);
}

#endif //no _MRE_LOADING_POPUP_

/***************************************************************************** 
 * class VappMREOperator
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappMREOperator); 
VappMREOperator::VappMREOperator()
:m_pImg(NULL),m_bLaunching(VFX_FALSE),m_bRegister(VFX_FALSE)
{

}

void VappMREOperator::setApp(VfxChar* pAppName)
{
    VAPP_AM_TRACE1(VAPP_MRE_SET_APP_BEGIN,Vapp_AM_UTF8_to_ASCII(pAppName));

    m_appInfo.m_strApp = pAppName;
    m_appInfo.m_type = VappInfo::VAPP_AM_APP_TYPE_MRE;
    m_appInfo.m_pAdapter = VappMREInfoAdapter::getInstance();
    
    srv_mre_appmgr_app_storage_position_enum storage_position;
    storage_position = srv_mre_appmgr_get_app_storage_position(pAppName);
    if (SRV_MRE_APPMGR_APP_POSITION_CARD == storage_position)
    {
        m_appInfo.m_storage = VappInfo::VAPP_AM_APP_POS_CARD;
    }
    else
    {
        m_appInfo.m_storage = VappInfo::VAPP_AM_APP_POS_PHONE;
    }
    
    VfxWChar appPath[SRV_FMGR_PATH_MAX_LEN + 1]={0};
    if (m_appInfo.isExist())
    {
        if (srv_mre_appmgr_get_file_path(m_appInfo.m_strApp,appPath))
        {
            m_wstrAppPath = VFX_WSTR_MEM(appPath);        
        }
    }
    else
    {   
        m_wstrAppPath.setEmpty();
    }
    VAPP_AM_TRACE1(VAPP_MRE_SET_APP_END,Vapp_AM_UCS2_to_ASCII(appPath));
}

void VappMREOperator::setAppPath(VfxWChar* pAppPath)
{    
    VAPP_AM_TRACE1(VAPP_MRE_SET_PATH_BEGIN,Vapp_AM_UCS2_to_ASCII(pAppPath));
    
#ifdef _AM_TEST_
    m_appInfo.m_strApp = "test";
    m_appInfo.m_type = VappInfo::VAPP_AM_APP_TYPE_MRE;
    m_appInfo.m_pAdapter = VappMREInfoAdapter::getInstance();
#else
    m_wstrAppPath = VFX_WSTR_MEM(pAppPath);

    m_appInfo.m_strApp = NULL;     
    m_appInfo.m_type = VappInfo::VAPP_AM_APP_TYPE_MRE;
    m_appInfo.m_pAdapter = (IVappInfoAdapter*)VappMREInfoAdapter::getInstance();
#endif

    VAPP_AM_TRACE1(VAPP_MRE_SET_PATH_END,Vapp_AM_UTF8_to_ASCII(m_appInfo.m_strApp));
}

VfxBool VappMREOperator::isInstalled()
{
#ifdef _AM_TEST_
    if (g_UT.getUTFlag() & VAPP_AM_TEST_INSTALLED)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
#else //_AM_TEST_
    if (m_appInfo.m_strApp)
    {
        return srv_mre_appmgr_is_app_installed(m_appInfo.m_strApp)?VFX_TRUE:VFX_FALSE;
    }
    else
    {
        return srv_mre_appmgr_is_app_installed_by_path((U16*)m_wstrAppPath.getBuf())?
                VFX_TRUE:VFX_FALSE;
    } 
#endif //_AM_TEST_   
}

VfxBool VappMREOperator::isExist()
{
#ifdef _AM_TEST_
    if (g_UT.getUTFlag()& (VAPP_AM_TEST_NOT_EXIST_CARD|VAPP_AM_TEST_NOT_EXIST_PHONE))
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
#else //_AM_TEST_
    if (!m_wstrAppPath.isEmpty())
    {
        return VFX_TRUE;
    }
    return m_appInfo.isExist();
#endif //_AM_TEST_   
}
VfxBool VappMREOperator::isUpdating()
{
#ifdef _AM_TEST_
    if (g_UT.getUTFlag() & VAPP_AM_TEST_UPDATING)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
#else //_AM_TEST_
    if (!m_wstrAppPath.isEmpty())
    {
        return srv_mre_appmgr_is_bg_downloading_by_path((U16*)m_wstrAppPath.getBuf())?
                VFX_TRUE:VFX_FALSE;
    }
    return m_appInfo.isUpdating();
#endif //_AM_TEST_   
}

VfxBool VappMREOperator::isRunning()
{
#ifdef _AM_TEST_
    if (g_UT.getUTFlag() & VAPP_AM_TEST_RUNNING)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
#else //_AM_TEST_
    if (!m_wstrAppPath.isEmpty())
    {
        return srv_mre_is_app_bg_running((U16*)m_wstrAppPath.getBuf())?
                VFX_TRUE:VFX_FALSE;
    }
    return m_appInfo.isRunning();
#endif //_AM_TEST_   
}

VfxBool VappMREOperator::checkUpdateMRE()
{
    applib_time_struct currTime;    
    applib_dt_get_date_time(&currTime);

    VAPP_AM_TRACE3(VAPP_MRE_CHECK_UPDATE,currTime.nYear,currTime.nMonth,currTime.nDay);
    
    VfxS16 err;
    ReadValue(NVRAM_VAPP_MRE_UPDATE_TIME,&m_lastUpdateTime,DS_SHORT,&err);
    ReadValue(NVRAM_VAPP_MRE_CANCEL_TIME,&m_lastCancelTime,DS_SHORT,&err);    
    
    VAPP_AM_TRACE3(VAPP_MRE_LAST_UPDATE_TIME,0,m_lastUpdateTime.m_month,m_lastUpdateTime.m_day);
    VAPP_AM_TRACE3(VAPP_MRE_LAST_CANCEL_TIME,0,m_lastCancelTime.m_month,m_lastCancelTime.m_day);
    
    if (ABSSUB(m_lastUpdateTime.m_month*30+m_lastUpdateTime.m_day ,currTime.nMonth*30+currTime.nDay) > 7 )//at least one week not update
    {       
        if (m_lastCancelTime.m_month != currTime.nMonth ||
            m_lastCancelTime.m_day != currTime.nDay)//user not cancel update today!
        {           
            // TODO: invoke srv api to judge if MRE environment need to update
            if (MRE_SRV_CDR_NO_SYSC_CDR != srv_mre_update_is_sync_cdr())
            {
                return VFX_TRUE;
            }            
        }
    }
    return VFX_FALSE;
}

VfxS32 VappMREOperator::updateMRE()
{    
    // TODO: invoke srv api to update MRE environment
    VfxS32 result;
    result = srv_mre_update_sync_cdr(&VappMREOperator::updateMRECB);
    if(SRV_MRE_DL_SUCCESS != result)
    {
        updateMRECB(result);
    }
    
#ifdef _AM_TEST_
    VfxTimer* pTimer;

    VFX_OBJ_CREATE(pTimer, VfxTimer, this);
    pTimer->setStartDelay(3000);
    pTimer->m_signalTick.connect(this,&VappMREOperator::onTime1);
    pTimer->start();
    return 0;
#endif //_AM_TEST_
    return 0;
}

void VappMREOperator::cancelUpdateMRE()
{
    srv_mre_update_cancel_sync_cdr();
}

void VappMREOperator::cancelNotify()
{
    applib_time_struct currTime;    
    applib_dt_get_date_time(&currTime);

    m_lastCancelTime.m_month = currTime.nMonth;
    m_lastCancelTime.m_day = currTime.nDay;

    VfxS16 err;
    WriteValue(NVRAM_VAPP_MRE_CANCEL_TIME,&m_lastCancelTime,DS_SHORT,&err);
}

VfxBool VappMREOperator::checkAppValid()
{
    return SRV_MRE_VERIFY_OK == srv_mre_is_app_valid((U16*)m_wstrAppPath.getBuf())? VFX_TRUE:VFX_FALSE;
}

VfxBool VappMREOperator::isOnCard()
{
    if (!m_wstrAppPath.isEmpty())
    {        
        if ((U32)m_wstrAppPath[0] == (U32)FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE))
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

VfxS32 VappMREOperator::launchApp()
{
    
    
#ifdef _AM_TEST_
    VfxTimer* pTimer;

    VFX_OBJ_CREATE(pTimer, VfxTimer, this);
    pTimer->setStartDelay(3000);
    pTimer->m_signalTick.connect(this,&VappMREOperator::onTime);
    pTimer->start();
    return 0;
#else //_AM_TEST_   
    if (m_wstrAppPath.isEmpty())
    {
        VfxWChar appPath[SRV_FMGR_PATH_MAX_LEN + 1];
        if (srv_mre_appmgr_get_file_path(m_appInfo.m_strApp,appPath))
        {
            m_wstrAppPath = VFX_WSTR_MEM(appPath);            
        }
    }

    VAPP_AM_TRACE1(VAPP_MRE_LAUNCH_APP,Vapp_AM_UCS2_to_ASCII(m_wstrAppPath.getBuf()));
    
#ifndef _MRE_LOADING_POPUP_
    vapp_show_loading_scr();
#endif
    VfxS32 err = transErrorCode((VfxS32)srv_mre_launch_app((U16*)m_wstrAppPath.getBuf(),
                        (srv_mre_launch_app_cb_t)&VappMREOperator::launchAppCB));
                        
    if (VAPP_AM_OK !=  err)
    {
#ifndef _MRE_LOADING_POPUP_    
        vapp_close_loading_scr();
#endif        
        getInstance()->m_launchedSignal.postEmit(err);
        return err;
    } 
    m_bLaunching = VFX_TRUE;
    return VAPP_AM_OK;
#endif //_AM_TEST_                       
}

VfxS32 VappMREOperator::activeApp()
{
    if (m_wstrAppPath.isEmpty())
    {
        VfxWChar appPath[SRV_FMGR_PATH_MAX_LEN + 1];
        if (srv_mre_appmgr_get_file_path(m_appInfo.m_strApp,appPath))
        {
            m_wstrAppPath = VFX_WSTR_MEM(appPath);
            
        }
    }

    VAPP_AM_TRACE1(VAPP_MRE_ACTIVE_APP,Vapp_AM_UCS2_to_ASCII(m_wstrAppPath.getBuf()));
    
    return transErrorCode((VfxS32)srv_mre_launch_app((U16*)m_wstrAppPath.getBuf(),NULL));
}

VfxS32 VappMREOperator::installApp()
{
    VAPP_AM_TRACE1(VAPP_MRE_INSTALL_APP,Vapp_AM_UCS2_to_ASCII(m_wstrAppPath.getBuf()));
    
    if (!m_wstrAppPath.isEmpty())
    {
        if (!srv_mre_appmgr_is_able_to_install((U16*)m_wstrAppPath.getBuf()))
        {
            return VAPP_AM_MAX_APP_NUM;
        }
        if (srv_mre_appmgr_install_app((U16*)m_wstrAppPath.getBuf(),SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL,m_appName))
        {
            VAPP_AM_TRACE1(VAPP_MRE_INSTALL_SUCCESS,Vapp_AM_UTF8_to_ASCII(m_appName));
            
            m_appInfo.m_strApp = m_appName;
            m_appInfo.m_type = VappInfo::VAPP_AM_APP_TYPE_MRE;
            m_appInfo.m_pAdapter = (IVappInfoAdapter*)VappMREInfoAdapter::getInstance();
            return VAPP_AM_OK;
        }
    }
    return VAPP_AM_ERR;
}

VfxS32 VappMREOperator::installVso()
{
    VAPP_AM_TRACE1(VAPP_MRE_INSTALL_APP,Vapp_AM_UCS2_to_ASCII(m_wstrAppPath.getBuf()));
    
    if (!m_wstrAppPath.isEmpty())
    {
        if (!srv_mre_appmgr_is_able_to_install((U16*)m_wstrAppPath.getBuf()))
        {
            return VAPP_AM_MAX_APP_NUM;
        }
        if (srv_mre_appmgr_install_app((U16*)m_wstrAppPath.getBuf(),SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL,m_appName))
        {
            VAPP_AM_TRACE1(VAPP_MRE_INSTALL_SUCCESS,Vapp_AM_UTF8_to_ASCII(m_appName));
            return VAPP_AM_OK;
        }
    }
    return VAPP_AM_ERR;
}

#ifdef _MRE_LOADING_POPUP_ 

void VappMREOperator::getAppIcon(VfxImageSrc &img, VfxObject* alloc)
{
    //has app name
    img.setResId(VAPP_AM_IMG_MRE_LOGO);
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
#endif	
}

#endif //_MRE_LOADING_POPUP_
void VappMREOperator::release()
{
    if (m_pImg)//do this is to avoid the macro change in case
    {
        VFX_FREE_MEM(m_pImg);
    }
    if (m_bLaunching)
    {
        srv_mre_close_app((U16*)m_wstrAppPath.getBuf());
        m_bLaunching = VFX_FALSE;
    }
}

void VappMREOperator::updateMRECB(VfxS32 result)
{
    VAPP_AM_TRACE(VAPP_MRE_UPDATE_MRE_CB);

    VfxS16 err;
    if (!result)
    {
        applib_time_struct currTime;    
        applib_dt_get_date_time(&currTime);
        
        getInstance()->m_lastUpdateTime.m_month = currTime.nMonth;
        getInstance()->m_lastUpdateTime.m_day = currTime.nDay;
        WriteValue(NVRAM_VAPP_MRE_UPDATE_TIME,&getInstance()->m_lastUpdateTime,DS_SHORT,&err);
    }
    getInstance()->m_updateMRESignal.emit(result);
}


void VappMREOperator::launchAppCB(VfxWChar* app_path, VfxS32 evt)
{
    VAPP_AM_TRACE1(VAPP_MRE_LAUNCH_APP_CB,evt);
    getInstance()->m_bLaunching = VFX_FALSE;
    getInstance()->m_launchedSignal.emit(transErrorCode(evt,VAPP_MRE_LAUNCH_CB_ERR));
}

VfxS32 VappMREOperator::transErrorCode(VfxS32 err, VfxS32 errType)
{
    if (VAPP_MRE_LAUNCH_ERR == errType)
    {
        switch (err)
        {
        case SRV_MRE_LAUNCH_APP_SUCCESS:
            return VAPP_AM_OK;

        case SRV_MRE_LAUNCH_APP_NOT_ENOUGH_MEMORY:
            return VAPP_AM_NO_MEMORY;

        case SRV_MRE_LAUNCH_APP_TIMESTAMP_ERROR:
            return VAPP_AM_TIME_ERR;

        case SRV_MRE_LAUNCH_APP_ONLY_ONE_FOREGROUND:
            return VAPP_AM_ONLY_ONE_FG;

        case SRV_MRE_LAUNCH_APP_MAX_NUM:
            return VAPP_AM_MAX_APP_NUM;

        case SRV_MRE_LAUNCH_VERSION_NOT_MATCH:
            return VAPP_AM_VERSION_NOT_MATCH;
        default:
            return VAPP_AM_ERR;
        }
    }
    else if (VAPP_MRE_LAUNCH_CB_ERR == errType)
    {
        switch(err)
        {
        case SRV_MRE_LAUNCH_APP_EVT_SUCCESS:
            return VAPP_AM_OK;
            
        case SRV_MRE_LAUNCH_APP_ASM_READY:
            return VAPP_AM_MRE_LAUNCH_AGAIN;
            
        default:
            return VAPP_AM_ERR;            
        }
    }
    return VAPP_AM_ERR;
}

extern "C" VMINT vm_update_update_int(void (*callback)(VfxS32 result, VfxWChar* path, void* user_data));
extern "C" typedef void (*update_file_cb)(VfxU32 result, VfxWChar* path, void* user_data);
static VMWSTR g_vm_update_path = NULL;

void VappMREOperator::updateAppFileCB(VfxS32 result, VfxWChar* path, void* user_data)
{
    VappMREOperator* pOperator = (VappMREOperator*)getInstance();
    g_vm_update_path = (VMWSTR)_vm_kernel_malloc(260*2);
    if (g_vm_update_path)
    {
        memcpy(g_vm_update_path,path,260*2);
    }
    pOperator->m_updateFileSignal.postEmit(result);
}

void VappMREOperator::updateAppFile(void* data)
{
    vm_update_update_int(&VappMREOperator::updateAppFileCB);
}
#ifdef _AM_TEST_
void VappMREOperator::onTime1(VfxTimer* pTimer)
{
    VFX_OBJ_CLOSE(pTimer);
    
    updateMRECB(NULL, 0);
}

void VappMREOperator::onTime(VfxTimer* pTimer)
{
    VFX_OBJ_CLOSE(pTimer);
    
    vapp_app_manager_entry();
    launchAppCB(NULL, 0);
}
#endif //_AM_TEST_


//************************************************************************************
// special popup, process back key
//************************************************************************************
VappConfirmPopup::VappConfirmPopup()
:m_clickType(-1)
{
    
};

void VappConfirmPopup::onInit()
{
    VcpConfirmPopup::onInit();
    m_signalButtonClicked.connect(this,&VappConfirmPopup::onClicked);
}

VfxBool VappConfirmPopup::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (event.keyCode == VFX_KEY_CODE_BACK)
        {
            VfxAppScr* pScr = (VfxAppScr*)getParent();
            pScr->exit();
            return VFX_TRUE;
        }
    }
    return VcpConfirmPopup::onKeyInput(event);
};

void VappConfirmPopup::onClicked(VfxObject* obj,  VfxId id)
{
    m_clickType = id;
}


VappQuestionPopup::VappQuestionPopup()
:m_clickType(-1)
{
    
};

void VappQuestionPopup::onInit()
{
    VcpQuestionPopup::onInit();
    m_signalButtonClicked.connect(this,&VappQuestionPopup::onClicked);
}

VfxBool VappQuestionPopup::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (event.keyCode == VFX_KEY_CODE_BACK)
        {
            VfxAppScr* pScr = (VfxAppScr*)getParent();
            pScr->exit();
            return VFX_TRUE;
        }
    }
    return VcpQuestionPopup::onKeyInput(event);
};

void VappQuestionPopup::onClicked(VfxObject* obj,  VfxId id)
{
    m_clickType = id;
}

/***************************************************************************** 
 * class VappMREOperatorMainScr
 *****************************************************************************/
VappMREOperatorMainScr::VappMREOperatorMainScr(VfxS32 type)
:m_bFirstIn(VFX_TRUE),m_bLaunched(VFX_FALSE),m_bValid(VFX_FALSE),m_operateType(type),m_updateMREPopup(NULL)
#ifdef _MRE_LOADING_POPUP_
,m_launchAppPopup(NULL)
#endif
{
    setIsSmallScreen();  
}

static void vapp_entry_scrn_callback(void* param)
{
    VappMREOperatorMainScr* pthis = (VappMREOperatorMainScr*)param;
    pthis->on1stReady();
}
void VappMREOperatorMainScr::onEnter(VfxBool isBackward)
{
    if (m_bFirstIn)
    {
        m_bFirstIn = VFX_FALSE;
        StartTimerEx(0xefac,0,(oslTimerFuncPtr)vapp_entry_scrn_callback,this);
//        vfxPostInvoke0(this,&VappMREOperatorMainScr::on1stReady);    
    }
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,cardPlugOutCB,this->getObjHandle());
}

mmi_ret VappMREOperatorMainScr::cardPlugOutCB(mmi_event_struct *param)
{
    VappMREOperatorMainScr* pThis = (VappMREOperatorMainScr*)VfxObject::handleToObject(param->user_data);
      
    if (pThis && pThis->isValid())
    {    
        VappMREOperator* pMREOptor = VappMREOperator::getInstance();
        if (pMREOptor->isOnCard())
        {
            pThis->exit();
        }
    }
    return 0;
}

void VappMREOperatorMainScr::on1stReady()
{
    VAPP_AM_TRACE1(VAPP_MRE_MAINSCR_READY,m_operateType);

    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
    pMREOptor->m_launchedSignal.connect(this,&VappMREOperatorMainScr::onLaunched);
    pMREOptor->m_updateMRESignal.connect(this,&VappMREOperatorMainScr::onUpdated);
    
    //is app updating?
    if (pMREOptor->isUpdating())
    {
        VcpConfirmPopup* pPopup;
        VFX_OBJ_CREATE(pPopup,VappConfirmPopup,this);
        
        VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_CANT_FOR_UPDATING));    
        pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
        pPopup->setText(strText);
        pPopup->m_signalButtonClicked.connect(this,&VappMREOperatorMainScr::onExit);
        pPopup->show(VFX_TRUE);
        return;
    }
    //is app running background?
    if (pMREOptor->isRunning())
    {
        //make the app run foreground
        VfxS32 err = pMREOptor->activeApp();
        onLaunched(err);
        return;
    }
    //is in installe mode
    if (OPERATE_TYPE_INSTALL == m_operateType)
    {
        //is app installed?
        if (!pMREOptor->isInstalled())
        {
            install();
            return;
        }
        else
        {
            VcpConfirmPopup* pPopup;
            VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,this);

            VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_ALREADY_INSTALLED)); 
            pPopup->setInfoType(VCP_POPUP_TYPE_INFO);
            pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
            pPopup->setText(strText);
            pPopup->m_signalButtonClicked.connect(this,&VappMREOperatorMainScr::onExit);
            pPopup->show(VFX_TRUE);
            return;
        }
    }
    MRE_SWLA_START("MA1");
    launch();
    MRE_SWLA_STOP("MA1");
}

void VappMREOperatorMainScr::install()
{
    VappMREOperator* pMREOptor = VappMREOperator::getInstance();

    VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_VXP_OPERATE));
    
    VFX_OBJ_CREATE(m_installPopup, VappQuestionPopup, this);
//    m_installPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);  
    m_installPopup->setText(strText);
    m_installPopup->addItem(VCP_CONFIRM_POPUP_BUTTON_USER_1,VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_INSTALL));                            
//    m_installPopup->addItem(VCP_CONFIRM_POPUP_BUTTON_USER_2,VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_JUST_LAUNCH));
    m_installPopup->addItem(VCP_CONFIRM_POPUP_BUTTON_CANCEL,VFX_WSTR_RES(STR_GLOBAL_EXIT));
    
    m_installPopup->m_signalPopupState.connect(this,&VappMREOperatorMainScr::onInstallPopupStateChanged);
    m_installPopup->show(VFX_TRUE); 
}

void VappMREOperatorMainScr::launch()
{
    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
    //is app file exist?    
    if (pMREOptor->isExist())
    {  
        if (pMREOptor->checkUpdateMRE())
        {
            //update mre env
            VcpConfirmPopup* pPopup;
            VFX_OBJ_CREATE(pPopup,VappConfirmPopup,this);
            
            VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_MRE_ENV_UPDATE)); 
            pPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);   
            pPopup->setText(strText);
            pPopup->setCustomButton(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_UPDATE), 
                                    VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_CANCEL),
                                    VCP_POPUP_BUTTON_TYPE_NORMAL,
                                    VCP_POPUP_BUTTON_TYPE_CANCEL);        
            pPopup->m_signalButtonClicked.connect(this,&VappMREOperatorMainScr::onUpdateMRE);
            pPopup->show(VFX_TRUE);
        }
        else
        {
            onLaunchApp();
        }
        return;
    }
    //app file not exist!!!and not storage mode!!
    VcpConfirmPopup* pPopup;
    VFX_OBJ_CREATE(pPopup,VappConfirmPopup,this);
    
    VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_NOT_FOUND_APP)); 
    pPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
    pPopup->setText(strText);      
    pPopup->m_signalButtonClicked.connect(this,&VappMREOperatorMainScr::onExit);
    pPopup->show(VFX_TRUE);
}

extern "C" void vm_start_parent();
void VappMREOperatorMainScr::onLaunchApp()
{
    VAPP_AM_TRACE1(VAPP_MRE_MAINSCR_ONLAUNCHAPP,isValid());
    
    if (!isValid())
    {
        return;
    }

    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
#ifdef _MRE_LOADING_POPUP_    
    VfxImageSrc img;

    pMREOptor->getAppIcon(img,this);

    VFX_OBJ_CREATE(m_launchAppPopup, VcpLoadingPopup, this);
    m_launchAppPopup->setIcon(img);

 //   m_launchAppPopup->m_signalPopupState.connect(this,&VappMREOperatorMainScr::onLaunchPopupStateChanged); 
    m_launchAppPopup->show(VFX_TRUE);
#endif
    if (m_bValid || pMREOptor->checkAppValid())
    {
        //app valid
        launchApp();
    }
    else
    {
#ifdef _MRE_LOADING_POPUP_

        m_launchAppPopup->exit(VFX_TRUE);
#endif

#ifdef _MRE_NO_AUTH_SUPPORT_
        //app invalid
        VcpConfirmPopup* pPopup;
        VFX_OBJ_CREATE(pPopup,VappConfirmPopup,this);
           
        pPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);   
        pPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_NO_AUTH));

        pPopup->m_signalButtonClicked.connect(this,&VappMREOperatorMainScr::onClickLaunchApp);
        pPopup->show(VFX_TRUE);
#else
        VcpConfirmPopup* pPopup;
        VFX_OBJ_CREATE(pPopup,VappConfirmPopup,this);
       
        pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
        pPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_LAUNCH_FAIL));

        pPopup->m_signalButtonClicked.connect(this,&VappMREOperatorMainScr::onExit);
        pPopup->show(VFX_TRUE);
#endif
    } 
}

void VappMREOperatorMainScr::onClickLaunchApp(VfxObject* pObj, VfxId id)
{
    if (VCP_CONFIRM_POPUP_BUTTON_YES == id)
    {
        m_bValid = VFX_TRUE;
#ifdef _MRE_LOADING_POPUP_
        VfxImageSrc img;

        VappMREOperator* pMREOptor = VappMREOperator::getInstance();
        pMREOptor->getAppIcon(img,this);

        VFX_OBJ_CREATE(m_launchAppPopup, VcpLoadingPopup, this);
        m_launchAppPopup->setIcon(img);

//        m_launchAppPopup->m_signalPopupState.connect(this,&VappMREOperatorMainScr::onLaunchPopupStateChanged); 
//        m_launchAppPopup->show(VFX_TRUE);
#endif
        launchApp();
    }
    else if (VCP_CONFIRM_POPUP_BUTTON_NO == id)
    {
        vm_start_parent();
        exit();
    }    
}

void VappMREOperatorMainScr::onClickInstallApp(VfxObject* pObj, VfxId id)
{
    if (VCP_CONFIRM_POPUP_BUTTON_YES == id)
    {
        VappMREOperator* pMREOptor = VappMREOperator::getInstance();
        VfxS32 result = pMREOptor->installApp();
        if (result)
        {
            //failed!!
            VcpConfirmPopup* pPopup;
            VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,this);
            
            VfxWString strText;
            if (result == VAPP_AM_MAX_APP_NUM)
            {
                strText = VFX_WSTR_RES(STR_MRE_REACH_MAX_NUM);
            }
            else
            {
                strText = VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_INSTALL_FAIL);
            }  
            pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
            pPopup->setText(strText);
            pPopup->m_signalButtonClicked.connect(this,&VappMREOperatorMainScr::onExit);
            pPopup->show(VFX_TRUE);
            return;
        }
        else
        {
            VcpConfirmPopup* pPopup;
            VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,this);
            
            VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_INSTALL_SUCCESS)); 
            pPopup->setInfoType(VCP_POPUP_TYPE_SUCCESS);
            pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
            pPopup->setText(strText);
            pPopup->m_signalButtonClicked.connect(this,&VappMREOperatorMainScr::onExit);
            pPopup->show(VFX_TRUE);
            return;
        }
    }
    else if (VCP_CONFIRM_POPUP_BUTTON_NO == id)
    {
        exit();
    }    
}

void VappMREOperatorMainScr::launchApp()
{
    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
    pMREOptor->launchApp();
}

void VappMREOperatorMainScr::onLaunched(VfxS32 result)
{
    VAPP_AM_TRACE1(VAPP_MRE_MAINSCR_ONLAUNCHED,isValid());
    
    if (!isValid())
    {
        return;
    }
    

    VfxWString strText;
    VfxU32  popType = VCP_CONFIRM_BUTTON_SET_OK;
    switch (result)
    {
        case VAPP_AM_OK:
            //launch success ,exit Launcher
            exit();
            return;

        case VAPP_AM_MRE_LAUNCH_AGAIN:
            //need launch again!!
            m_bLaunched = VFX_FALSE;
            onLaunchApp();
            return;
            
        case VAPP_AM_TIME_ERR:
            popType = VCP_CONFIRM_BUTTON_SET_USER_DEFINE;
            strText = VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_LAUNCH_FAIL_TIME);
            break;

        case VAPP_AM_ONLY_ONE_FG:
            strText = VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_LAUNCH_FAIL_ONLY_ONE_FG);
            break;

        case VAPP_AM_MAX_APP_NUM:
            strText = VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_LIMITATION_APP);
            break;
        case VAPP_AM_VERSION_NOT_MATCH:
            strText = VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_VERSION_DISMATCH);
            break;
        default:
            strText = VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_LAUNCH_FAIL);
            break;
    }
#ifdef _MRE_LOADING_POPUP_    
    if (m_launchAppPopup)
    {
        m_launchAppPopup->hide(VFX_TRUE);
    } 
#endif    
    //else we show failure popup   
    VcpConfirmPopup* pPopup;
    VFX_OBJ_CREATE(pPopup,VappConfirmPopup,this);
       
    pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    pPopup->setButtonSet((VcpConfirmPopupButtonSetEnum)popType);   
    pPopup->setText(strText);
    
    if ((VfxU32)VCP_CONFIRM_BUTTON_SET_USER_DEFINE == popType)
    {
        pPopup->setCustomButton(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_REPAIR), 
                            VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_CANCEL), 
                            VCP_POPUP_BUTTON_TYPE_NORMAL,
                            VCP_POPUP_BUTTON_TYPE_CANCEL);                            
                                   
    }

    pPopup->m_signalButtonClicked.connect(this,&VappMREOperatorMainScr::onRepair);
    pPopup->show(VFX_TRUE);
}

void VappMREOperatorMainScr::onRepair(VfxObject* pObj, VfxId id)
{
    VAPP_AM_TRACE1(VAPP_MRE_MAINSCR_ONREPAIR,isValid());
    
    if (!isValid())
    {
        return;
    }
    if (VCP_CONFIRM_POPUP_BUTTON_USER_1 == id)
    {        
        //show date setting page
        VfxMainScr* scr;
        VFX_OBJ_CREATE(scr,VfxMainScr,getApp());

        VappDateSettingPage* pPage;
        VFX_OBJ_CREATE(pPage,VappDateSettingPage,scr);
        
        scr->pushPage(0,pPage);
        scr->show();
        exit();
    }
    else if (VCP_CONFIRM_POPUP_BUTTON_USER_2 == id)
    {        
        exit();
    }
    else if (VCP_CONFIRM_POPUP_BUTTON_OK == id)
    {
        exit();
    }
}

void VappMREOperatorMainScr::onDeletedApp(VfxS32 bResult)
{
    VAPP_AM_TRACE1(VAPP_MRE_MAINSCR_ONDELETED,isValid());
    
    if (!isValid())
    {
        return;
    }
    // TODO: what should i do ,if delete failed???
    exit();
}

void VappMREOperatorMainScr::onUpdateMRE(VfxObject* pObj, VfxId id)
{
    VAPP_AM_TRACE1(VAPP_MRE_MAINSCR_ONUPDATEMRE,isValid());
    
    if (!isValid())
    {
        return;
    }
    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
    if (VCP_CONFIRM_POPUP_BUTTON_USER_1 == id)
    {        
        VFX_OBJ_CREATE(m_updateMREPopup, VcpIndicatorPopup, this);
        m_updateMREPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
        m_updateMREPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_UPDATING));
        m_updateMREPopup->m_signalCanceled.connect(this,&VappMREOperatorMainScr::onCancelUpdateMRE);
        m_updateMREPopup->show(VFX_TRUE);
        pMREOptor->updateMRE();
        return;
    }
    else if (VCP_CONFIRM_POPUP_BUTTON_USER_2 == id)
    {
        //user cancel update mre environment, need to notify
        pMREOptor->cancelNotify();
        //launch app
        onLaunchApp();
        return;
    }
}

void VappMREOperatorMainScr::onCancelUpdateMRE(VfxObject* obj, VfxFloat f)
{
    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
    pMREOptor->cancelUpdateMRE();
    //launch app
    onLaunchApp();
}

void VappMREOperatorMainScr::onUpdated(VfxS32 result)
{
    VAPP_AM_TRACE1(VAPP_MRE_MAINSCR_ONUPDATED,result);

    if (!isValid())
    {
        return;
    }
    
    if (m_updateMREPopup)
    {
        m_updateMREPopup->hide(VFX_TRUE);
    }

    //failed!!
    if (result)
    {
        VcpConfirmPopup* pPopup;
        VFX_OBJ_CREATE(pPopup,VappConfirmPopup,this);
        
        VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_UPDATE_FAIL)); 
        pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
        pPopup->setText(strText);
        pPopup->m_signalPopupState.connect(this,&VappMREOperatorMainScr::onUpdateFailPopupStateChanged);
        pPopup->show(VFX_TRUE);
    }
    else
    {
        onLaunchApp();
    }
}

void VappMREOperatorMainScr::onInstallLaunch()
{
    VAPP_AM_TRACE1(VAPP_MRE_MAINSCR_ONINSTALL,isValid());
    
    if (!isValid())
    {
        return;
    }
    VappMREOperator* pMREOptor = VappMREOperator::getInstance();

    m_bValid = VFX_TRUE;
    if (pMREOptor->checkAppValid())
    {        
        //app valid
        //install and launch
        VfxS32 result = pMREOptor->installApp();
        if (result)
        {
            //failed!!
            VcpConfirmPopup* pPopup;
            VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,this);
            
            VfxWString strText;
            if (result == VAPP_AM_MAX_APP_NUM)
            {
                strText = VFX_WSTR_RES(STR_MRE_REACH_MAX_NUM);
            }
            else
            {
                strText = VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_INSTALL_FAIL);
            } 
            pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
            pPopup->setText(strText);
            pPopup->m_signalButtonClicked.connect(this,&VappMREOperatorMainScr::onExit);
            pPopup->show(VFX_TRUE);
            return;
        }
        else
        {
            VcpConfirmPopup* pPopup;
            VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,this);
            
            VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_INSTALL_SUCCESS)); 
            pPopup->setInfoType(VCP_POPUP_TYPE_SUCCESS);
            pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
            pPopup->setText(strText);
            pPopup->m_signalButtonClicked.connect(this,&VappMREOperatorMainScr::onExit);
            pPopup->show(VFX_TRUE);
            return;
        }
    }
    else
    {
#ifdef _MRE_NO_AUTH_SUPPORT_    
        //app invalid
        VcpConfirmPopup* pPopup;
        VFX_OBJ_CREATE(pPopup,VappConfirmPopup,this);
           
        pPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);   
        pPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_NO_AUTH_INSTALL));

        pPopup->m_signalButtonClicked.connect(this,&VappMREOperatorMainScr::onClickInstallApp);
        pPopup->show(VFX_TRUE);
#else
        //failed!!
        VcpConfirmPopup* pPopup;
        VFX_OBJ_CREATE(pPopup,VappConfirmPopup,this);
        
        VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_INSTALL_FAIL)); 
        pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
        pPopup->setText(strText);
        pPopup->m_signalButtonClicked.connect(this,&VappMREOperatorMainScr::onExit);
        pPopup->show(VFX_TRUE);
#endif
        return;
    }
}

void VappMREOperatorMainScr::onExit(VfxObject* pObj, VfxId id)
{
    VAPP_AM_TRACE1(VAPP_MRE_MAINSCR_ONEXIT,isValid());
    exit();
}

void VappMREOperatorMainScr::onCanceled(VfxObject* pObj, VfxFloat flt)
{
    onExit(NULL,0);
}

void VappMREOperatorMainScr::onInstallPopupStateChanged(VfxBasePopup* pPopup, VfxBasePopupStateEnum state)
{

    if (VFX_BASE_POPUP_AFTER_END_ANIMATION == state)
    {
        VappQuestionPopup* pPop = (VappQuestionPopup*)pPopup;
        if (VCP_CONFIRM_POPUP_BUTTON_USER_1 == pPop->m_clickType)
        {
            onInstallLaunch();
        }
        else if (VCP_CONFIRM_POPUP_BUTTON_USER_2 == pPop->m_clickType)
        {
            launch();
        }
        else
        {
            exit();
        }
    }
}
void VappMREOperatorMainScr::onInstallFailPopupStateChanged(VfxBasePopup* pPopup, VfxBasePopupStateEnum state)
{
    if (VFX_BASE_POPUP_AFTER_END_ANIMATION == state)
    {
        VappConfirmPopup* pPop = (VappConfirmPopup*)pPopup;
        if (VCP_CONFIRM_POPUP_BUTTON_OK == pPop->m_clickType)
        {
            onLaunchApp();
        }
    }
}

void VappMREOperatorMainScr::onUpdateFailPopupStateChanged(VfxBasePopup* pPopup, VfxBasePopupStateEnum state)
{
    if (VFX_BASE_POPUP_AFTER_END_ANIMATION == state)
    {
        VappConfirmPopup* pPop = (VappConfirmPopup*)pPopup;
        if (VCP_CONFIRM_POPUP_BUTTON_OK == pPop->m_clickType)
        {
            onLaunchApp();
        }
    }
}
void VappMREOperatorMainScr::setOperateType(VfxS32 type)
{
    m_operateType = type;
}

/***************************************************************************** 
 * class VappMRELauncher
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMRELauncher", VappMRELauncher, VfxApp);

void VappMRELauncher::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    if (args)
    {
        m_appName = NULL;
        VFX_ALLOC_MEM(m_appName,argSize,this);
        VFX_ASSERT(m_appName != NULL);

        memcpy(m_appName,args,argSize);
        VappMREOperator* pMREOptor = VappMREOperator::getInstance();
        pMREOptor->setApp((VfxChar*)m_appName);
    }

    VappUSBOperator* pUSB;
    VFX_OBJ_CREATE(pUSB, VappUSBOperator, this);
    pUSB->m_enterMSSignal.connect(this, &VfxApp::exit);
    
    VappMREOperatorMainScr *pScr;
    VFX_OBJ_CREATE_EX(pScr, VappMREOperatorMainScr, this,
                    (VappMREOperatorMainScr::OPERATE_TYPE_LAUNCH));
    pScr->show();
}

void VappMRELauncher::onDeinit()
{
    VFX_FREE_MEM(m_appName);
    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
    pMREOptor->release();
    vm_mre_free_pre_app_mem();
    VfxApp::onDeinit();
}

VFX_IMPLEMENT_CLASS("VappMRELauncherEx", VappMRELauncherEx, VfxApp);

void VappMRELauncherEx::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    if (args)
    {
        VappMREOperator* pMREOptor = VappMREOperator::getInstance();
        pMREOptor->setAppPath((VfxWChar*)args);
    }

    VappUSBOperator* pUSB;
    VFX_OBJ_CREATE(pUSB, VappUSBOperator, this);
    pUSB->m_enterMSSignal.connect(this, &VfxApp::exit);
    
    VappMREOperatorMainScr *pScr;
    VFX_OBJ_CREATE_EX(pScr, VappMREOperatorMainScr, this,
                    (VappMREOperatorMainScr::OPERATE_TYPE_LAUNCH));
    pScr->show();
}

void VappMRELauncherEx::onDeinit()
{
    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
    pMREOptor->release();
    vm_mre_free_pre_app_mem();
    VfxApp::onDeinit();
}

/***************************************************************************** 
 * class VappMREInstaller
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMREInstaller", VappMREInstaller, VfxApp);

VappMREInstaller::VappMREInstaller()
{
    
}

void VappMREInstaller::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
    pMREOptor->setAppPath((VfxWChar*)args);

    VappUSBOperator* pUSB;
    VFX_OBJ_CREATE(pUSB, VappUSBOperator, this);
    pUSB->m_enterMSSignal.connect(this, &VfxApp::exit);
    
    VappMREOperatorMainScr *pScr;
    VFX_OBJ_CREATE_EX(pScr, VappMREOperatorMainScr, this,
                    (VappMREOperatorMainScr::OPERATE_TYPE_INSTALL));
    pScr->show();
}

void VappMREInstaller::onDeinit()
{
    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
    pMREOptor->release();
    VfxApp::onDeinit();           
}

extern "C" void vapp_mre_app_update(void* param, int size)
{
    if (VappUSBOperator::isMassStorageMode())
    {
        VappUSBOperator::showPopup();
        return;
    }

    if (param)
    {
        mmi_id app_id = VfxAppLauncher::launch( 
            VAPP_MRE_APP_OPERATOR, 
            VFX_OBJ_CLASS_INFO(VappMREUpdater),
            GRP_ID_ROOT,
            param, size);
    }  
}

VFX_IMPLEMENT_CLASS("VappMREUpdater", VappMREUpdater, VfxApp);

void VappMREUpdater::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    
    VappUSBOperator* pUSB;
    VFX_OBJ_CREATE(pUSB, VappUSBOperator, this);
    pUSB->m_enterMSSignal.connect(this, &VfxApp::exit);
    
    VappMREUpdateMainScr *pScr;
    VFX_OBJ_CREATE(pScr, VappMREUpdateMainScr, this);
    pScr->show();
}

void VappMREUpdater::onDeinit()
{
    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
    pMREOptor->release();
    
    VfxApp::onDeinit();
}

VFX_IMPLEMENT_CLASS("VappMREUpdateMainScr", VappMREUpdateMainScr, VfxMainScr);

VappMREUpdateMainScr::VappMREUpdateMainScr():m_bFirstIn(VFX_TRUE)
{
    setIsSmallScreen(); 
}

void VappMREUpdateMainScr::onEnter(VfxBool isBackward)
{
    if (m_bFirstIn)
    {
        m_bFirstIn = VFX_FALSE;
        vfxPostInvoke0(this,&VappMREUpdateMainScr::on1stReady);    
    }
}

void VappMREUpdateMainScr::on1stReady()
{    
    VcpConfirmPopup* pPopup;
    VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,this);
    
    VfxWString strText(VFX_WSTR_RES(STR_MRE_UPDATE_QUERY)); 
    pPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);   
    pPopup->setText(strText);
    pPopup->m_signalButtonClicked.connect(this,&VappMREUpdateMainScr::onQueried);
    pPopup->show(VFX_TRUE);
}

void VappMREUpdateMainScr::onQueried(VfxObject* obj, VfxId id)
{
    if (VCP_CONFIRM_POPUP_BUTTON_YES == id)
    {
        VFX_OBJ_CREATE(m_pWaitingPopup,VcpIndicatorPopup,this);
        m_pWaitingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_pWaitingPopup->setText(VFX_WSTR_RES(STR_MRE_UPDATE_UPDATING));
        m_pWaitingPopup->show(VFX_TRUE);
        VappMREOperator* pMREOptor = VappMREOperator::getInstance();
        VappMREUpdater* pApp = (VappMREUpdater*)getParent();
        pMREOptor->m_updateFileSignal.connect(this,&VappMREUpdateMainScr::onResult);
        pMREOptor->updateAppFile(NULL);        
    }
    else if (VCP_CONFIRM_POPUP_BUTTON_NO == id)
    {
        exit();
    }
}

void VappMREUpdateMainScr::onResult(VfxS32 result)
{
    VfxWString strText;
    VcpConfirmPopup* pPopup;

    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
    pMREOptor->m_updateFileSignal.disconnect(this,&VappMREUpdateMainScr::onResult);
    m_pWaitingPopup->exit(VFX_TRUE);
    
    VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,this);
    if (0 == result)
    {
        strText = VFX_WSTR_RES(STR_MRE_UPDATE_SUCCESS);
        pPopup->setInfoType(VCP_POPUP_TYPE_SUCCESS);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    }
    else
    {
        strText = VFX_WSTR_RES(STR_MRE_UPDATE_FAIL);
        pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    }
       
    pPopup->setText(strText);
    pPopup->m_signalButtonClicked.connect(this,&VappMREUpdateMainScr::onExit);
    pPopup->show(VFX_TRUE);
}

void VappMREUpdateMainScr::onExit(VfxObject* obj, VfxId id)
{
    if (VCP_CONFIRM_POPUP_BUTTON_NO == id || VCP_CONFIRM_POPUP_BUTTON_OK == id)
    {
        exit();
    }
    else if (VCP_CONFIRM_POPUP_BUTTON_YES == id)
    {
        VappMREUpdater* pApp = (VappMREUpdater*)getParent();        
        vapp_mre_app_launch_by_path((WCHAR*)g_vm_update_path);
        exit();
    }
    _vm_kernel_free(g_vm_update_path);
    g_vm_update_path = NULL;
}


extern "C" void vapp_mre_vso_install(WCHAR* Path)
{
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__

    if (VappUSBOperator::isMassStorageMode())
    {
        VappUSBOperator::showPopup();
        return;
    }

    if (Path)
    {
        VfxAppLauncher::launch( 
            VAPP_MRE_APP_OPERATOR, 
            VFX_OBJ_CLASS_INFO(VappMREVSOInstaller),
            GRP_ID_ROOT,
            Path, 2*kal_wstrlen(Path)+2);
    }  
#endif // __LOW_COST_SUPPORT_COMMON__    
}

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__

VFX_IMPLEMENT_CLASS("VappMREVSOInstaller", VappMREVSOInstaller, VfxApp);

void VappMREVSOInstaller::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    
    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
    pMREOptor->setAppPath((VfxWChar*)args);
    
    VappUSBOperator* pUSB;
    VFX_OBJ_CREATE(pUSB, VappUSBOperator, this);
    pUSB->m_enterMSSignal.connect(this, &VfxApp::exit);
    
    VappMREVSOInstallMainScr *pScr;
    VFX_OBJ_CREATE(pScr, VappMREVSOInstallMainScr, this);
    pScr->show();
}

void VappMREVSOInstaller::onDeinit()
{
    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
    pMREOptor->release();
    
    VfxApp::onDeinit();
}

VFX_IMPLEMENT_CLASS("VappMREVSOInstallMainScr", VappMREVSOInstallMainScr, VfxMainScr);

VappMREVSOInstallMainScr::VappMREVSOInstallMainScr():m_bFirstIn(VFX_TRUE)
{
    setIsSmallScreen();
}

void VappMREVSOInstallMainScr::onEnter(VfxBool isBackward)
{
    if (m_bFirstIn)
    {
        m_bFirstIn = VFX_FALSE;
        vfxPostInvoke0(this,&VappMREVSOInstallMainScr::on1stReady);    
    }
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,cardPlugOutCB,this->getObjHandle());
}

mmi_ret VappMREVSOInstallMainScr::cardPlugOutCB(mmi_event_struct *param)
{
    VappMREVSOInstallMainScr* pThis = (VappMREVSOInstallMainScr*)VfxObject::handleToObject(param->user_data);
      
    if (pThis && pThis->isValid())
    {    
        VappMREOperator* pMREOptor = VappMREOperator::getInstance();
        if (pMREOptor->isOnCard())
        {
            pThis->exit();
        }
    }
    return 0;
}

void VappMREVSOInstallMainScr::on1stReady()
{  
    VappMREOperator* pMREOptor = VappMREOperator::getInstance();
    if (pMREOptor->isInstalled())
    {
        VcpConfirmPopup* pPopup;
        VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,this);
        
        VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_ALREADY_INSTALLED)); 
        pPopup->setInfoType(VCP_POPUP_TYPE_INFO);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
        pPopup->setText(strText);
        pPopup->m_signalButtonClicked.connect(this,&VappMREVSOInstallMainScr::onExit);
        pPopup->show(VFX_TRUE);
        return;
    }
    
    VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_VSO_OPERATE));
    VappQuestionPopup* installPopup;
    VFX_OBJ_CREATE(installPopup, VappQuestionPopup, this);

    installPopup->setText(strText);
    installPopup->addItem(VCP_CONFIRM_POPUP_BUTTON_USER_1,VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_INSTALL));                            
    installPopup->addItem(VCP_CONFIRM_POPUP_BUTTON_CANCEL,VFX_WSTR_RES(STR_GLOBAL_EXIT));
    
    installPopup->m_signalPopupState.connect(this,&VappMREVSOInstallMainScr::onInstallPopupStateChanged);
    installPopup->show(VFX_TRUE); 
}

void VappMREVSOInstallMainScr::onInstallPopupStateChanged(VfxBasePopup* pPopup, VfxBasePopupStateEnum state)
{

    if (VFX_BASE_POPUP_AFTER_END_ANIMATION == state)
    {
        VappQuestionPopup* pPop = (VappQuestionPopup*)pPopup;
        if (VCP_CONFIRM_POPUP_BUTTON_USER_1 == pPop->m_clickType)
        {
            VappMREOperator* pMREOptor = VappMREOperator::getInstance();
            VfxS32 result = pMREOptor->installVso();
            if (result)
            {
                OnInstallFailed(result);
            }
            else
            {
                OnInstallSuccess();
            }
        }
        else
        {
            exit();
        }
    }
}

extern "C" S32 srv_mre_appmgr_get_file_type(WCHAR *path);
void VappMREVSOInstallMainScr::OnInstallFailed(VfxS32 result)
{
    VcpConfirmPopup* pPopup;
    VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,this);
    
    VfxWString strText;
    if (result == VAPP_AM_MAX_APP_NUM)
    {
        VappMREOperator* pMREOptor = VappMREOperator::getInstance();

        S32 type = srv_mre_appmgr_get_file_type((WCHAR *)pMREOptor->m_wstrAppPath.getBuf());
        VfxResId id;
        switch (type)
        {
        case SRV_MRE_APPMGR_APP_TYPE_WIDGET:
            id = STR_ID_VAPP_AM_POPUP_CAN_NOT_INSTALL_WIDGET;
            break;
        case SRV_MRE_APPMGR_APP_TYPE_WALLPAPER:
            id = STR_ID_VAPP_AM_POPUP_CAN_NOT_INSTALL_WALLPAPER;
            break;
        case SRV_MRE_APPMGR_APP_TYPE_LAUNCHER:
            id = STR_ID_VAPP_AM_POPUP_CAN_NOT_INSTALL_LAUNCHER;
            break;
        case SRV_MRE_APPMGR_APP_TYPE_SCRLOCK:
            id = STR_ID_VAPP_AM_POPUP_CAN_NOT_INSTALL_SCRLOCK;
            break;
        default:
            break;
        }
        strText = VFX_WSTR_RES(id);
    }
    else
    {
        strText = VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_INSTALL_FAIL);
    }
    pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
    pPopup->setText(strText);
    pPopup->m_signalButtonClicked.connect(this,&VappMREVSOInstallMainScr::onExit);
    pPopup->show(VFX_TRUE);
    return;
}

void VappMREVSOInstallMainScr::OnInstallSuccess()
{
    VcpConfirmPopup* pPopup;
    VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,this);
    
    VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_INSTALL_SUCCESS)); 
    pPopup->setInfoType(VCP_POPUP_TYPE_SUCCESS);
    pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
    pPopup->setText(strText);
    pPopup->m_signalButtonClicked.connect(this,&VappMREVSOInstallMainScr::onExit);
    pPopup->show(VFX_TRUE);
    return;
}

void VappMREVSOInstallMainScr::onExit(VfxObject* pObj, VfxId id)
{
    if (VCP_CONFIRM_POPUP_BUTTON_OK == id)
    {    
        exit();
    }
}

#endif //__COSMOS_MMI_PACKAGE__

//shortcut download UI

VfxWeakPtr<VappMREShortcutInstallMainScr> g_pShortctSrc;


typedef struct
{
    U16*    filepath;
    srv_mre_appmgr_shortcut_info_struct* info;
}vapp_shortcut_data;

static int g_installing[5]={0,0,0,0,0};

static void vapp_mre_shortcut_set_installing(int app_id)
{
    for (int i = 0; i < 5; i++)
    {
        if (0 == g_installing[i])
        {
            g_installing[i] = app_id;
            return;
        }
    }
}

static void vapp_mre_shortcut_clear_installing(int app_id)
{
    for (int i = 0; i < 5; i++)
    {
        if (app_id == g_installing[i])
        {
            g_installing[i] = 0;
            return;
        }
    }
}

static VfxBool vapp_mre_shortcut_is_installing(int app_id)
{
    for (int i = 0; i < 5; i++)
    {
        if (app_id == g_installing[i])
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

extern S32 vapp_mre_shortcut_install_ex(vapp_shortcut_data* data);
static void vapp_mre_shortcut_vsm_install_cb(VMINT result,VMWSTR path,void* user_data)
{
    vapp_shortcut_data* p_shortcut_data = (vapp_shortcut_data*)user_data;
    WCHAR buff[256];
    kal_wstrcpy((WCHAR *)buff,(WCHAR *)GetString(p_shortcut_data->info->name_id));
    kal_wstrcat((WCHAR *)buff,(WCHAR *)L" ");
    
    _vm_kernel_free(p_shortcut_data->filepath);
    p_shortcut_data->filepath = NULL;

    vapp_mre_shortcut_clear_installing(p_shortcut_data->info->app_id);
    
    if (result)
    {        
        _vm_kernel_free(p_shortcut_data->info);
        _vm_kernel_free(p_shortcut_data);
        
        kal_wstrcat((WCHAR *)buff,(WCHAR *)GetString(STR_ID_VAPP_AM_POPUP_SHORTCUT_INSTALL_FAIL));
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_FAILURE,
            	                     (WCHAR*)buff);                  
    }
    else
    {
        vapp_mre_shortcut_install_ex(p_shortcut_data);
    }
}

static void vapp_mre_shortcut_install_cb(VMINT result,VMWSTR path,void* user_data)
{
    vapp_shortcut_data* p_shortcut_data = (vapp_shortcut_data*)user_data;
    WCHAR buff[256];
    
	vapp_mre_shortcut_clear_installing(p_shortcut_data->info->app_id);	
    if (result)
    {
        kal_wstrcpy((WCHAR *)buff,(WCHAR *)GetString(STR_ID_VAPP_AM_POPUP_SHORTCUT_INSTALL_FAIL));
        kal_wstrcat((WCHAR *)buff,(WCHAR *)L" ");
        kal_wstrcat((WCHAR *)buff,(WCHAR *)GetString(p_shortcut_data->info->name_id));
        
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_FAILURE,
            	                     (WCHAR*)buff);                
    }
    else
    {
        kal_wstrcpy((WCHAR *)buff,(WCHAR *)GetString(p_shortcut_data->info->name_id));
        kal_wstrcat((WCHAR *)buff,(WCHAR *)L" ");
        kal_wstrcat((WCHAR *)buff,(WCHAR *)GetString(STR_ID_VAPP_AM_POPUP_SHORTCUT_INSTALL_SUCESS));
        
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_INFO,
            	                     (WCHAR*)buff);
    }
    _vm_kernel_free(p_shortcut_data->filepath);
    _vm_kernel_free(p_shortcut_data->info);
    _vm_kernel_free(p_shortcut_data);
}

static void vapp_mre_shortcut_vsm_update_cb(S32 hdl, void * para)
{
	vm_update_download_param param;
	vm_preload_recv_data_t* data = (vm_preload_recv_data_t*)para;
	vapp_shortcut_data* p_shortcut_data = (vapp_shortcut_data*)data->head.user_data;
    srv_mre_appmgr_shortcut_info_struct* p_shortcut_info = p_shortcut_data->info;

	if (E_PRELOAD_AVAILABLE_UPDATE == data->head.state)
	{        
		if (g_pShortctSrc.isValid())
	    {
	        g_pShortctSrc.get()->ExitWaitingPopup();
	    }
        param.callback = vapp_mre_shortcut_vsm_update_cb;
        param.user_data = data->head.user_data;
        param.handle = hdl;
        param.app_path = (VMWSTR)p_shortcut_data->filepath;
        param.bUseDLA = 1;
		if (VM_UPDATE_OK != vm_update_download_ex(&param))
		{
		    goto error;
		}
	}
	else if (E_PRELOAD_DOWNLOADED == data->head.state)
	{
	    vapp_mre_shortcut_set_installing(p_shortcut_data->info->app_id);
	    if (VM_UPDATE_OK != vm_update_update_file_ex((VMWSTR)p_shortcut_data->filepath,vapp_mre_shortcut_vsm_install_cb,p_shortcut_data))
		{
		    _vm_kernel_free(p_shortcut_data->filepath);
		    vapp_mre_shortcut_install_ex(p_shortcut_data);
		}
        data->head.user_data = NULL;
		
	}
	else if (data->head.state != E_PRELOAD_DOWNLOADING && data->head.state != E_PRELOAD_QUERYING &&
		data->head.state != E_PRELOAD_CONNECTING && data->head.state != E_PRELOAD_CONNECTED)
	{
error:	
        WCHAR buff[256];
              
        kal_wstrcpy((WCHAR *)buff,(WCHAR *)GetString(STR_ID_VAPP_AM_POPUP_SHORTCUT_INSTALL_FAIL));
        kal_wstrcat((WCHAR *)buff,(WCHAR *)L" ");
        kal_wstrcat((WCHAR *)buff,(WCHAR *)GetString(p_shortcut_data->info->name_id));
        
        if (g_pShortctSrc.isValid())
	    {
	        g_pShortctSrc.get()->ExitWaitingPopup();
	    }
	    
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_INFO,
            	                     (WCHAR*)buff);
            	                     
        _vm_kernel_free(p_shortcut_data->filepath);
		_vm_kernel_free(p_shortcut_data->info);
        _vm_kernel_free(p_shortcut_data);
        data->head.user_data = NULL;
	}
}

static void vapp_mre_shortcut_update_cb(S32 hdl, void * para)
{
	vm_update_download_param param;
	vm_preload_recv_data_t* data = (vm_preload_recv_data_t*)para;
    vapp_shortcut_data* p_shortcut_data = (vapp_shortcut_data*)data->head.user_data;

	if (E_PRELOAD_AVAILABLE_UPDATE == data->head.state)
	{
	    if (g_pShortctSrc.isValid())
	    {
	        g_pShortctSrc.get()->ExitWaitingPopup();
	    }
	    
	    if (FS_GetDevStatus((unsigned int)FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, 	FS_NO_ALT_DRIVE), FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
	    {
            param.bSaveOnCard = 1;
        }
        else
        {
            param.bSaveOnCard = 0;
        }
        param.callback = vapp_mre_shortcut_update_cb;
        param.user_data = p_shortcut_data;
        param.handle = hdl;
        param.app_path = (VMWSTR)p_shortcut_data->filepath;
        param.bUseDLA = 1;
		if (VM_UPDATE_OK != vm_update_download_ex(&param))
		{
		    goto error;
		}
	}
	else if (E_PRELOAD_DOWNLOADED == data->head.state)
	{
	    vapp_mre_shortcut_set_installing(p_shortcut_data->info->app_id);
		if (VM_UPDATE_OK != vm_update_update_file_ex((VMWSTR)p_shortcut_data->filepath,vapp_mre_shortcut_install_cb,p_shortcut_data))
		{
		    vapp_mre_shortcut_install_cb(1,NULL,p_shortcut_data);
		}
		data->head.user_data = NULL;
	}
	else if (data->head.state != E_PRELOAD_DOWNLOADING && data->head.state != E_PRELOAD_QUERYING &&
		data->head.state != E_PRELOAD_CONNECTING && data->head.state != E_PRELOAD_CONNECTED)
	{
error:	
        WCHAR buff[256];

        kal_wstrcpy((WCHAR *)buff,(WCHAR *)GetString(STR_ID_VAPP_AM_POPUP_SHORTCUT_INSTALL_FAIL));
        kal_wstrcat((WCHAR *)buff,(WCHAR *)L" ");
        kal_wstrcat((WCHAR *)buff,(WCHAR *)GetString(p_shortcut_data->info->name_id));
        
        if (g_pShortctSrc.isValid())
	    {
	        g_pShortctSrc.get()->ExitWaitingPopup();
	    }
	    
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_INFO,
            	                     (WCHAR*)buff); 
        _vm_kernel_free(p_shortcut_data->filepath);
		_vm_kernel_free(p_shortcut_data->info);
        _vm_kernel_free(p_shortcut_data);
        data->head.user_data = NULL;
	}
}

S32 vapp_mre_shortcut_install_ex(vapp_shortcut_data* data)
{
    VMINT result;
    CHAR app_name[MMI_APP_NAME_MAX_LEN];
    vm_update_check_version_param param;
    
    if (NULL == data->info->vsm)
    {
        data->filepath = (U16*)_vm_kernel_malloc(SRV_MRE_APPMGR_FILEPATH_LEN);
        if (!data->filepath)
        {
            _vm_kernel_free(data->info);
            return -1;
        }
        param.app_id = data->info->app_id;
        srv_mre_appmgr_get_shortcut_app_name_package(data->info->app_id,app_name);
        srv_mre_appmgr_get_file_path((mmi_app_package_char*)app_name, data->filepath);        

        param.URL = data->info->url;
        param.port = 80;
        param.apn = 1;
        param.app_path = (VMWSTR)data->filepath;
        param.app_ver = "0.0.0";
        param.app_info = NULL;
        param.callback = vapp_mre_shortcut_update_cb;
        param.user_data = data;
        
        result = vm_update_check_version_ex(&param);
        if (VM_UPDATE_OK_ALREADY_DOWNLOADED == result)
        {
            vapp_mre_shortcut_set_installing(param.app_id);
            vm_update_update_file_ex((VMWSTR)data->filepath,vapp_mre_shortcut_install_cb,data);
            return 0;
        }
        else if (VM_UPDATE_OK  != result)
        {
            _vm_kernel_free(data->filepath);
            _vm_kernel_free(data->info);
            _vm_kernel_free(data);
            
        	vapp_nmgr_global_popup_show_confirm_one_button_id
        		(MMI_SCENARIO_ID_DEFAULT,
        		VCP_POPUP_TYPE_FAILURE,
        		STR_ID_VAPP_AM_POPUP_SHORTCUT_DOWNLOAD_FAIL,
        		STR_GLOBAL_OK,
        		VCP_POPUP_BUTTON_TYPE_CANCEL,
        		NULL,
        		NULL
        		);  
       		
        	return -1;
        }  
        else
        {
            if (g_pShortctSrc.isValid())
    	    {
    	        g_pShortctSrc.get()->ShowPopup();
    	    }
        }
    }
    else
    {
        int drv;
        data->filepath = (U16*)_vm_kernel_malloc(SRV_MRE_APPMGR_FILEPATH_LEN);
        if (!data->filepath)
        {
            _vm_kernel_free(data->info);
            _vm_kernel_free(data);
            return -1;
        }
        
        kal_wstrcpy((WCHAR *)data->filepath,(WCHAR *)L"C:\\MRE\\");
        mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)data->info->vsm->vsm_name, 
                (char *)(data->filepath+kal_wstrlen(data->filepath)), SRV_MRE_APPMGR_FILEPATH_LEN*2);
        drv = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, 	FS_NO_ALT_DRIVE);
        if (drv <= 0)
        {
            drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
        }
        *(CHAR*)data->filepath = (CHAR)drv;
        //remove already exist file
        FS_Delete(data->filepath);
        
        param.app_id = data->info->vsm->vsm_id;
        param.URL = data->info->url;
        param.port = 80;
        param.apn = 1;
        param.app_path = (VMWSTR)data->filepath;
        param.app_ver = "0.0.0";
        param.app_info = NULL;
        param.callback = vapp_mre_shortcut_vsm_update_cb;
        param.user_data = data;

        data->info->vsm = data->info->vsm->next;
        
        result = vm_update_check_version_ex(&param);
        if (VM_UPDATE_OK_ALREADY_DOWNLOADED == result)
        {
            vapp_mre_shortcut_set_installing(param.app_id);
            vm_update_update_file_ex((VMWSTR)data->filepath,vapp_mre_shortcut_vsm_install_cb,data);
            return 0;
        }
        else if (VM_UPDATE_OK  != result)
        {
            _vm_kernel_free(data->info);            
        	vapp_nmgr_global_popup_show_confirm_one_button_id
        		(MMI_SCENARIO_ID_DEFAULT,
        		VCP_POPUP_TYPE_FAILURE,
        		STR_ID_VAPP_AM_POPUP_SHORTCUT_DOWNLOAD_FAIL,
        		STR_GLOBAL_OK,
        		VCP_POPUP_BUTTON_TYPE_CANCEL,
        		NULL,
        		NULL
        		);  
            _vm_kernel_free(data->filepath);
            _vm_kernel_free(data->info);
            _vm_kernel_free(data);
        	return -1;
        }  
        else
        {
            if (g_pShortctSrc.isValid())
    	    {
    	        g_pShortctSrc.get()->ShowPopup();
    	    }
        }
    }
    return 1;
}

extern "C" VMINT vm_preload_status(VMINT app_id);

extern "C" void vm_preload_show_download_list(void);

extern "C" void vapp_mre_shortcut_install(void* param, int size)
{
    VMINT status = 0;
    srv_mre_appmgr_shortcut_info_struct info;
    
    if (VappUSBOperator::isMassStorageMode())
    {
        VappUSBOperator::showPopup();
        return;
    }

    srv_mre_appmgr_get_shortcut_app_info((char *)param,&info);

    while (info.vsm)
    {
        status = vm_preload_status(info.vsm->vsm_id);
        if (E_PRELOAD_DOWNLOADING == status)
        {
            vm_preload_show_download_list();
            return;
        }
        else if (status >= 0)
        {
            return;
        }
        info.vsm = info.vsm->next;
    }
    
    status = vm_preload_status(info.app_id);
    if (E_PRELOAD_DOWNLOADING == status)
    {
        vm_preload_show_download_list();
        return;
    }
    else if (status >= 0)
    {
        return;
    }

    if (vapp_mre_shortcut_is_installing(info.app_id))
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_INFO,
            	                     (WCHAR *)GetString(STR_GLOBAL_PLEASE_WAIT));
        return;            	                     
    }
    
    if (param)
    {
        mmi_id app_id = VfxAppLauncher::launch( 
            VAPP_MRE_APP_OPERATOR, 
            VFX_OBJ_CLASS_INFO(VappMREShortcutInstall),
            GRP_ID_ROOT,
            param, size);
    }  
}

VFX_IMPLEMENT_CLASS("VappMREShortcutInstall", VappMREShortcutInstall, VfxApp);

void VappMREShortcutInstall::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VFX_ALLOC_MEM(m_name,argSize,this);
    if (!m_name)
    {
        ASSERT(0);
    }
    
    memcpy(m_name,args,argSize);
    
    VappUSBOperator* pUSB;
    VFX_OBJ_CREATE(pUSB, VappUSBOperator, this);
    pUSB->m_enterMSSignal.connect(this, &VfxApp::exit);
    
    VappMREShortcutInstallMainScr *pScr;
    VFX_OBJ_CREATE(pScr, VappMREShortcutInstallMainScr, this);
    g_pShortctSrc = pScr;
    pScr->show();
}

void VappMREShortcutInstall::onDeinit()
{    
    VFX_FREE_MEM(m_name);
    VfxApp::onDeinit();
}

VFX_IMPLEMENT_CLASS("VappMREShortcutInstallMainScr", VappMREShortcutInstallMainScr, VfxMainScr);

VappMREShortcutInstallMainScr::VappMREShortcutInstallMainScr():m_bFirstIn(VFX_TRUE),m_pWaitingPopup(NULL)
{
    setIsSmallScreen(); 
    VFX_OBJ_CREATE(m_pWaitingPopup,VcpIndicatorPopup,this);
    m_pWaitingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_pWaitingPopup->setText(VFX_WSTR_RES(STR_MRE_UPDATE_UPDATING));
}

void VappMREShortcutInstallMainScr::onEnter(VfxBool isBackward)
{
    if (m_bFirstIn)
    {
        m_bFirstIn = VFX_FALSE;
        vfxPostInvoke0(this,&VappMREShortcutInstallMainScr::on1stReady);    
    }
}

void VappMREShortcutInstallMainScr::on1stReady()
{    
    VcpConfirmPopup* pPopup;
    VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,this);
    
    VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_SHORTCUT_DOWNLOAD_ASK)); 
    pPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);   
    pPopup->setText(strText);
    pPopup->setCustomButton(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_SHORTCUT_BTN_DOWNLOAD), 
                            VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_CANCEL), 
                            VCP_POPUP_BUTTON_TYPE_NORMAL,
                            VCP_POPUP_BUTTON_TYPE_CANCEL);
    pPopup->m_signalButtonClicked.connect(this,&VappMREShortcutInstallMainScr::onQueried);
    pPopup->show(VFX_TRUE);
}

void VappMREShortcutInstallMainScr::onQueried(VfxObject* obj, VfxId id)
{
    if (VCP_CONFIRM_POPUP_BUTTON_USER_1 == id)
    {
        VMINT result;
        U16* filepath = NULL;
        srv_mre_appmgr_shortcut_info_struct* p_shortcut_info;
        vapp_shortcut_data* p_shortcut_data;
        char* app_name = ((VappMREShortcutInstall*)getApp())->m_name;        

        p_shortcut_info = (srv_mre_appmgr_shortcut_info_struct*)_vm_kernel_malloc(sizeof(srv_mre_appmgr_shortcut_info_struct));
        if (!p_shortcut_info)
        {
            return;
        }
        p_shortcut_data = (vapp_shortcut_data*)_vm_kernel_malloc(sizeof(vapp_shortcut_data));
        if (!p_shortcut_data)
        {
            return;
        }
        
        srv_mre_appmgr_get_shortcut_app_info(app_name,p_shortcut_info);
        p_shortcut_data->info = p_shortcut_info;
        result = vapp_mre_shortcut_install_ex(p_shortcut_data);
        if (result <=0)
        {
            exit();
        }
    }
    else
    {
        exit();
    }
}

void VappMREShortcutInstallMainScr::ShowPopup()
{
    if (m_pWaitingPopup)
    {
        m_pWaitingPopup->show(VFX_TRUE);
        m_pWaitingPopup = NULL;
    }
}

void VappMREShortcutInstallMainScr::ExitWaitingPopup()
{
    if (m_pWaitingPopup)
    {
        m_pWaitingPopup->exit(VFX_TRUE);
        m_pWaitingPopup = NULL;
    }
    exit();
}

#endif //__COSMOS_MMI_PACKAGE__
