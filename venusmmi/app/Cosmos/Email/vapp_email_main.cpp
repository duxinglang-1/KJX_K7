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
 * Vapp_email_main.cpp
 *
 * Project:
 * --------
 * 
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
 *----------------------------------------------------------------------------
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h" 

#include "Vapp_Email_Main.h"
#include "Vapp_Email_Msg_List.h"
#include "Vapp_Email_Msg_View.h"
#include "Vapp_Email_Acct_Wizard.h"
#include "vapp_email_uri.h"
#include "Vapp_email_sso.h"

#ifdef __MMI_SSO__
#include "vcui_sso_gprot.h"
#endif

#include "vapp_email_setting.h"
#include "Vadp_asm.h"
#include "vcp_global_popup.h"
#include "vapp_nmgr_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "vapp_usb_gprot.h"
#include "Vapp_Email_mgr.h"

extern "C"
{
#include "emailsrvgprot.h"
#include "NativeAppFactorySrvGprot.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "UsbSrvGprot.h"

#include "Unicodexdcl.h"    //for mmi_wsprintf_ex

#ifdef __MMI_SSO__
#include "SsoSrvGprot.h"
#endif
} /* exter "C" */

#ifdef __MMI_EMAIL_SUPPORT_1000_MAILS__
#define VAPP_EMAIL_MEM_POOL_SIZE    (510 * 1024)
#else
#define VAPP_EMAIL_MEM_POOL_SIZE    (70 * 1024)
#endif

EMAIL_SRV_HANDLE gEmailSrvHandle;
static email_app_set_first_struct gFirstPageInfo;
VfxU32 gScrnWidth = LCD_WIDTH;
VfxU32 gScrnHeight = LCD_HEIGHT;

// this buffer used to store the content from other apps
// and used in background sending for MRE
extern WCHAR g_content[VAPP_EMAIL_MAX_CONT_LEN + 1] = {0};

#ifdef __MMI_SSO__
static VfxBool g_emailAppCreateSsoAcctQueryed = VFX_FALSE;
#endif

// please be carefull when remove an item from this array,
// SHOULD also modify the definition size in vapp_email_main.h
extern const email_app_err_struct email_err_tbl[] =
{
    {SRV_EMAIL_RESULT_NO_MEMORY, STR_GLOBAL_NOT_ENOUGH_MEMORY},
    {SRV_EMAIL_RESULT_ACTIVATE_BEARER_FAIL, STR_EMAIL_ERROR_CODE_BEARER_FAIL},
    {SRV_EMAIL_RESULT_AUTH_FAIL, STR_EMAIL_FTO_ERROR_CODE_AUTH_FAIL_ID},
    {SRV_EMAIL_RESULT_INVALID_USERNAME, STR_EMAIL_FTO_ERROR_CODE_AUTH_FAIL_ID},
    {SRV_EMAIL_RESULT_INVALID_PASSWORD, STR_EMAIL_FTO_ERROR_CODE_AUTH_FAIL_ID},
    {SRV_EMAIL_RESULT_MSG_NOT_EXIST, STR_EMAIL_ERROR_CODE_MSG_NOT_EXISTING_ID},
    {SRV_EMAIL_RESULT_INVALID_MSG, STR_EMAIL_ERROR_CODE_MSG_NOT_EXISTING_ID},
    {SRV_EMAIL_RESULT_SERVER_NOT_SUPPORT_STARTTLS, STR_EMAIL_MSG_SERVER_TLS_FAIL},
    {SRV_EMAIL_RESULT_SERVER_NOT_SUPPORT_APOP, STR_EMAIL_ERROR_CODE_NOT_SUPPORT_APOP_ID},
    {SRV_EMAIL_RESULT_SERVER_ERROR, STR_EMAIL_ERROR_CODE_CONN_FAIL_ID},
    {SRV_EMAIL_RESULT_NETWORK_ERROR, STR_EMAIL_ERROR_CODE_CONN_FAIL_ID},
    {SRV_EMAIL_RESULT_INCOMPLETE_ACCT, STR_EMAIL_ERROR_CODE_CONN_FAIL_ID},
    {SRV_EMAIL_RESULT_NETWORK_TIMEOUT, STR_EMAIL_ERROR_CODE_NETWORK_ID},
    {SRV_EMAIL_RESULT_RECIPIENTS_ERROR, STR_EMAIL_SMTP_RCPT_TO_FAIL},
    {SRV_EMAIL_RESULT_INVALID_FORMAT, STR_EMAIL_INVALID_MAIL_MESSAGE},
    {SRV_EMAIL_RESULT_SMTP_CMD_ERROR, STR_EMAIL_ERROR_CODE_SMTP_CMD},
    {SRV_EMAIL_RESULT_POP3_CMD_ERROR, STR_EMAIL_ERROR_CODE_POP_CMD},
    {SRV_EMAIL_RESULT_IMAP4_CMD_ERROR, STR_EMAIL_ERROR_CODE_IMAP_CMD},
    {SRV_EMAIL_RESULT_SELECT_FOLDER_ERROR, STR_EMAIL_ERROR_CODE_SELECT_FOLDER},
    {SRV_EMAIL_RESULT_MSG_REACH_MAX_NUM, STR_EMAIL_ERROR_CODE_REACH_MAX_NUM},    
    {SRV_EMAIL_RESULT_MSG_EXCEED_DOWNLOAD_SIZE, STR_EMAIL_FTO_TOO_LARGE_TO_DOWN_ID},
    {0, STR_EMAIL_ERROR_CODE_OPT_FAIL_ID}
};


VFX_IMPLEMENT_CLASS("VappEmailApp", VappEmailApp, VfxApp);


extern "C"
{
static void vapp_email_global_pop_nmgr_pop(VfxResId strId)
{
    // after checking with BD, show a balloon instead of popup
    mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)GetString(strId));
}

void vapp_email_set_first_page_type(email_app_set_first_struct *pageInfo)
{
    memset(&gFirstPageInfo, 0, sizeof(email_app_set_first_struct));
    memcpy(&gFirstPageInfo, pageInfo, sizeof(email_app_set_first_struct));
}

MMI_ID vapp_email_package_launch(void* param, U32 param_size)
{
    // launch from ICON, reset it to ignore OOM issue
    // launch Email from browser, in OOM screen, choose cancel
    memset(&gFirstPageInfo, 0, sizeof(email_app_set_first_struct));

    VappEmailStateEnum emailState = VappEmailMgr::getInstance()->getEmailAppState();
    if (emailState == VAPP_EMAIL_STATE_DEINITED ||
        emailState == VAPP_EMAIL_STATE_INITIALIZING)
    {
        vapp_email_global_pop_nmgr_pop(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
        return 0;
    }
    if(custom_email_using_card_memory() && emailState == VAPP_EMAIL_STATE_TCARD_OUT)
    {
        vapp_email_global_pop_nmgr_pop(STR_GLOBAL_INSERT_MEMORY_CARD);
        return 0;
    }
#ifdef __MMI_USB_SUPPORT__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)L"root"))
        {
            VcpPopupTypeEnum type;
            vapp_email_global_pop_nmgr_pop(vapp_usb_get_error_info(0, &type));
            return 0;
        }
    }
#endif /* __MMI_USB_SUPPORT__ */

    return VfxAppLauncher::launch(
                VAPP_EMAIL, 
                VFX_OBJ_CLASS_INFO(VappEmailApp), 
                GRP_ID_ROOT, 
                param, 
                param_size);
}


mmi_ret vapp_email_package_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id) 
    {
        case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_BADGE:
        {
            srv_nativeappfactory_query_app_badge_evt_struct *badge_evt = 
                (srv_nativeappfactory_query_app_badge_evt_struct*)evt;
            VfxU32 unreadNum;

            VappEmailStateEnum emailAppState;
            emailAppState = VFX_OBJ_GET_INSTANCE(VappEmailMgr)->getEmailAppState();
            if (emailAppState == VAPP_EMAIL_STATE_DEINITED || emailAppState == VAPP_EMAIL_STATE_USB_MODE)
            {
                mmi_wsprintf_ex(
                    (*badge_evt).badge,
                    (SRV_APPMGR_BADGE_MAX_LEN + 1) * sizeof(WCHAR),
                    (WCHAR*)L"");
                return MMI_RET_OK;
            }
            
            srv_email_acct_total_unread_num_get(&unreadNum);

            if (unreadNum)
            {
                mmi_wsprintf_ex(
                    (*badge_evt).badge,
                    (SRV_APPMGR_BADGE_MAX_LEN + 1) * sizeof(WCHAR),
                    (WCHAR*)L"%d",
                    unreadNum);
            }
            else
            {
                mmi_wsprintf_ex(
                    (*badge_evt).badge,
                    (SRV_APPMGR_BADGE_MAX_LEN + 1) * sizeof(WCHAR),
                    (WCHAR*)L"");
            }

            return MMI_RET_OK;
        }
         default:
            return MMI_RET_DONT_CARE;
    }
}


// this function is used to resolve CR MAUI_02741484 by work around
static mmi_ret vapp_email_launch_email_async(mmi_event_struct *param)
{
    VfxAppLauncher::launch( 
        VAPP_EMAIL,
        VFX_OBJ_CLASS_INFO(VappEmailApp),
        GRP_ID_ROOT);
    srv_email_create(&gEmailSrvHandle);
    return MMI_TRUE;
}

void mmi_email_app_lauch_composer(void)
{
    VfxBool needPop = VFX_FALSE;
    VfxResId erroStr = STR_GLOBAL_ERROR;

    VappEmailStateEnum emailState = VappEmailMgr::getInstance()->getEmailAppState();
    if (emailState == VAPP_EMAIL_STATE_USB_MODE)
    {
        needPop = VFX_TRUE;
        erroStr = STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE;
    }
    else if (emailState == VAPP_EMAIL_STATE_DEINITED ||
        emailState == VAPP_EMAIL_STATE_INITIALIZING
        )
    {
        needPop = VFX_TRUE;
        erroStr = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
    }
    else if(emailState == VAPP_EMAIL_STATE_TCARD_OUT)
    {
        needPop = VFX_TRUE;
        erroStr = STR_GLOBAL_INSERT_MEMORY_CARD;
    }
    if (!needPop)
    {
    U32 acct_num = 0;
    srv_email_acct_get_num(&acct_num);
    if (acct_num == 0)
        {
        needPop = VFX_TRUE;
        erroStr = STR_EMAIL_FTO_NO_EMAIL_ACCT;
        }
    }

    if (needPop)
    {
        if (gFirstPageInfo.lauch_comp.usePopToShowErr)
        {
            vapp_email_alert_cfm(erroStr);
        }
        else
        {
            vapp_email_global_pop_nmgr_pop(erroStr);
        }
        return;
    }

    VfxApp *app = VfxAppLauncher::findApp(
        VAPP_EMAIL, 
        VFX_OBJ_CLASS_INFO(VappEmailApp), 
        VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 
        0);
    
    if (app != NULL)
    {
        VfxAppLauncher::terminate(app->getGroupId());
    }

    gFirstPageInfo.first_page_type = EMAIL_MAIN_FIRST_PAGE_ACCT_LIST;
    gFirstPageInfo.entry_point = EMAIL_ENTRY_FROM_OTHER_APP;
    gFirstPageInfo.lauch_comp.needLaunch = VFX_TRUE;

    // at backward scenario, post the launch
    mmi_event_struct evt;
    MMI_FRM_INIT_EVENT(&evt, 0);
    mmi_frm_post_event(&evt, vapp_email_launch_email_async, NULL);
}

void mmi_email_app_send_attch_internal(
        const WCHAR *file_path,
        VfxBool del_file,
        VfxBool usePopToShowErr)
{
    VfxS32 errCode = 0;
    VappEmailComp::ResultEnum res;
    res = VappEmailComp::chkAttch((WCHAR*)file_path, NULL, 0, NULL, &errCode);

    VEMAIL_TRC_MAIN_SEND_CHK_ATTCH(res);
    
    if (res != VappEmailComp::SUCC)
    {
        VfxResId resId = STR_GLOBAL_ERROR;
        switch (res)
        {
            case VappEmailComp::FILE_IS_EMPTY:
                resId = STR_EMAIL_FTO_EMPTY_FILE;
                break;
            case VappEmailComp::FILE_NOT_FOUND:
                resId = STR_GLOBAL_FILE_NOT_FOUND;
                break;
            case VappEmailComp::FILE_TOO_LARGE:
            case VappEmailComp::MAIL_TOO_LARGE:
                resId = STR_EMAIL_FTO_ATTCH_TOO_LARGE;
                break;
            case VappEmailComp::DRM_PROHIBITED:
                resId = STR_GLOBAL_DRM_PROHIBITED;
                break;
            case VappEmailComp::FS_ERROR:
                resId = srv_fmgr_fs_error_get_string(errCode);
                break;
        }

        if (usePopToShowErr)
        {
            vapp_email_alert_cfm(resId);
        }
        else
        {
            vapp_email_global_pop_nmgr_pop(resId);
        }
        return;
    }
    
    memset(&(gFirstPageInfo.lauch_comp), 0, sizeof(vapp_email_composer_launch));
    mmi_wcsncpy(gFirstPageInfo.lauch_comp.attchPath, file_path, SRV_EMAIL_MAX_FILE_NAME_LEN);
    gFirstPageInfo.lauch_comp.deleleAttch = del_file;
    gFirstPageInfo.lauch_comp.usePopToShowErr = usePopToShowErr;
    mmi_email_app_lauch_composer();
}

void mmi_email_app_send_attch_ext(const char *file_path, MMI_BOOL del_file)
{
    VfxBool delFile = del_file ? VFX_TRUE : VFX_FALSE;
    mmi_email_app_send_attch_internal((WCHAR*)file_path, delFile, VFX_FALSE);
}

/* work around for Opera's limitation: cannot show balloon on Opera */
void mmi_email_app_send_attch_for_opera(const char *file_path)
{
    mmi_email_app_send_attch_internal((WCHAR*)file_path, VFX_FALSE, VFX_FALSE);
}

void mmi_email_app_send_attch(const char *file_path)
{
    mmi_email_app_send_attch_ext(file_path, MMI_FALSE);
}

void mmi_email_app_send_to_ext(const char *to_addr, const char *to_name)
{
    VFX_ASSERT(to_addr != NULL);

    VfxBool isValidAddr = vapp_email_util_chk_addr((VfxWChar*)to_addr);

    VEMAIL_TRC_MAIN_SEND_CHK_ADDR((isValidAddr?1:0));
    
    if (!isValidAddr)
    {
        vapp_email_global_pop_nmgr_pop(STR_EMAIL_FTO_INVALID_EMAIL_ADDR);
        return;
    }

    memset(&(gFirstPageInfo.lauch_comp), 0, sizeof(vapp_email_composer_launch));
    mmi_wcsncpy(gFirstPageInfo.lauch_comp.toAddr, (WCHAR*)to_addr, SRV_EMAIL_MAX_ADDR_LEN);
    if (to_name == NULL)
    {
        gFirstPageInfo.lauch_comp.toName[0] = 0;
    }
    else
    {
        mmi_wcsncpy(gFirstPageInfo.lauch_comp.toName, (WCHAR*)to_name, SRV_EMAIL_MAX_DISP_NAME_LEN);
    }
    mmi_email_app_lauch_composer();
}

void mmi_email_app_send_cont (const char *cont)
{
    VFX_ASSERT(cont != NULL);
    
    VEMAIL_TRC_MAIN_SEND_CONT(cont[0]);

    memset(&(gFirstPageInfo.lauch_comp), 0, sizeof(vapp_email_composer_launch));
    mmi_wcsncpy(g_content, (WCHAR*)cont, VAPP_EMAIL_MAX_CONT_LEN);
    gFirstPageInfo.lauch_comp.cont = g_content;
    mmi_email_app_lauch_composer();
}

} /* end of extern "C" */

extern void vapp_email_app_send_for_uri(mmi_email_app_send_param_struct *param, U32 paramFlag)
{
    memset(&(gFirstPageInfo.lauch_comp), 0, sizeof(vapp_email_composer_launch));
    if (paramFlag & (U32)EMAIL_TO_FILL_FLAG)
    { 
        if ((param->to_num >= 1) && (param->addr[0].addr_mail != NULL))
        {
            mmi_wcsncpy(gFirstPageInfo.lauch_comp.toAddr, (WCHAR*)param->addr[0].addr_mail, SRV_EMAIL_MAX_ADDR_LEN);
            if (param->addr[0].addr_name != NULL)
            {
                mmi_wcsncpy(gFirstPageInfo.lauch_comp.toName, (WCHAR*)param->addr[0].addr_name, SRV_EMAIL_MAX_DISP_NAME_LEN);
            }
        }
    }
    if (paramFlag & (U32)EMAIL_CC_FILL_FLAG)
    {
    }
    if (paramFlag & (U32)EMAIL_BCC_FILL_FLAG)
    {
    }
    if (paramFlag & (U32)EMAIL_SUBJ_FILL_FLAG)
    {
        gFirstPageInfo.lauch_comp.subj = (WCHAR*)param->subj;
    }
    if ((paramFlag & (U32)EMAIL_ATTCH_FILL_FLAG) && param->attch_file_path != NULL)
    {
        mmi_wcsncpy(gFirstPageInfo.lauch_comp.attchPath, (WCHAR*)param->attch_file_path, SRV_EMAIL_MAX_FILE_NAME_LEN);
    }
    if (paramFlag & (U32)EMAIL_PRIOR_FILL_FLAG)
    {
        // ignore the priority, because email account setting has this item
    }
    if (paramFlag & (U32)EMAIL_CONT_FILL_FLAG)
    {
        mmi_wcsncpy(g_content, (WCHAR*)param->cont, VAPP_EMAIL_MAX_CONT_LEN);
        gFirstPageInfo.lauch_comp.cont = g_content;
    }
    if (paramFlag & (U32)EMAIL_NEW_FILL_FLAG)
    {
        // it's NEW email, so not have to check the email address
    }
    mmi_email_app_lauch_composer();
}


KAL_ADM_ID VappEmailApp::m_admMemPtr = NULL;


void VappEmailApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    if (gFirstPageInfo.entry_point != EMAIL_ENTRY_FROM_MAIN_MENU)
    {
        VappEmailStateEnum emailState = VappEmailMgr::getInstance()->getEmailAppState();
        if (emailState == VAPP_EMAIL_STATE_DEINITED ||
            emailState == VAPP_EMAIL_STATE_INITIALIZING ||
            emailState == VAPP_EMAIL_STATE_USB_MODE ||
            emailState == VAPP_EMAIL_STATE_TCARD_OUT)
        {
            VfxApp::exit();
            return;
        }
    }

    VFX_ALLOC_MEM(m_memPoolPtr, VAPP_EMAIL_MEM_POOL_SIZE, this);
    m_admMemPtr = kal_adm_create(m_memPoolPtr, VAPP_EMAIL_MEM_POOL_SIZE, NULL, MMI_TRUE);
    if (NULL == m_admMemPtr)
    {
        VFX_FREE_MEM(m_memPoolPtr);
        m_memPoolPtr = NULL;
        m_admMemPtr = NULL;
    }

    srv_email_set_mem_func(
        gEmailSrvHandle,
        VappEmailApp::memAlloc,
        VappEmailApp::memFree);
    
    VappEmailMainScrn *mainScrn;
    VFX_OBJ_CREATE_EX(mainScrn, VappEmailMainScrn, this, (gFirstPageInfo));
    mainScrn->show();
}


void VappEmailApp::onDeinit()
{
    gScrnWidth = LCD_WIDTH;
    gScrnHeight = LCD_HEIGHT;

    vapp_email_reset_curr_fldr_info();
    deinitMem();
    
    VfxApp::onDeinit();    
}


mmi_ret VappEmailApp::onProc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
#ifdef __MMI_SSO__    
        case EVT_ID_VCUI_SSO_LOGIN_RESULT:
        {
            vapp_email_sso_login_done_hdlr(evt);
            return MMI_RET_OK;
        }
#endif /* #ifdef __MMI_SSO__ */
        default:
            break;
        
    }
    
    return VfxApp::onProc(evt);
}


VfxAppCloseAnswerEnum VappEmailApp::onProcessClose(VfxAppCloseOption options)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_APP_CLOSE, options);

    return VFX_APP_CLOSE_ANSWER_YES;
}


void *VappEmailApp::memAlloc(U32 size)
{
    return kal_adm_alloc(m_admMemPtr, size);
}


void VappEmailApp::memFree(void *ptr)
{
    kal_adm_free(m_admMemPtr, ptr);
}


void VappEmailApp::deinitMem()
{
    if (NULL != m_memPoolPtr && m_admMemPtr != NULL)
    {
        kal_adm_delete(m_admMemPtr);
        m_admMemPtr = NULL;

        VFX_FREE_MEM(m_memPoolPtr);
        m_memPoolPtr = NULL;
    }
}


VappEmailMainScrn::~VappEmailMainScrn()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_SCRN_DEINIT);

    // Can not memset it, will overwirte launch_comp's data
    // memset(&gFirstPageInfo, 0, sizeof(email_app_set_first_struct));
}


void VappEmailMainScrn::on1stReady()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_SCRN_FIRST_READY, m_firstPageType);
    VfxMainScr::on1stReady();

    switch (m_firstPageType)
    {
        case EMAIL_MAIN_FIRST_PAGE_ACCT_LIST:
        {
            VFX_OBJ_CREATE(m_firstPage, VappEmailAcctListPage, this);
            pushPage(EMAIL_PAGE_TYPE_ACCT_LISG, m_firstPage);
            m_acctListPage = (VappEmailAcctListPage*)m_firstPage;
            break;
        }
        case EMAIL_MAIN_FIRST_PAGE_MSG_LIST:
        {
            VFX_OBJ_CREATE_EX(m_firstPage, VappEmailMsgListPage, this, (m_acctID, m_fldrID, m_fldrType, m_showTitleSwitchBtn));
            pushPage(EMAIL_PAGE_TYPE_MSG_LIST, m_firstPage);
            break;
        }
        case EMAIL_MAIN_FIRST_PAGE_MSG_VIEW:
        {
            VFX_OBJ_CREATE_EX(m_firstPage, VappEmailMsgViewPage, this, (m_acctID, m_fldrID, m_msgID));
            pushPage(EMAIL_PAGE_TYPE_MSG_VIEW, m_firstPage);
            break;
        }
        default:
            return;
    }

    if (gFirstPageInfo.lauch_comp.needLaunch)
    {
        vfxPostInvoke3(
            this, 
            &VappEmailMainScrn::launchComposer, 
            (EMAIL_ACCT_ID)EMAIL_ACCT_INVALID_ID, 
            (EMAIL_MSG_ID)EMAIL_MSG_INVALID_ID, 
            VappEmailComp::EMAIL_MODE_NEW);
        //launchComposer(EMAIL_ACCT_INVALID_ID, EMAIL_MSG_INVALID_ID, VappEmailComp::EMAIL_MODE_NEW);
    }
}


void VappEmailMainScrn::on2ndReady()
{
    if (m_acctListPage.isValid())
    {
        VappEmailAcctListPage *acctListPage = m_acctListPage.get();
        acctListPage->on2ndEnter();
    }
}


mmi_ret VappEmailMainScrn::onProc(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_CUI_UC_EMAILCOMPOSER_CLOSE)
    {
        //if (m_compInst != NULL)
        //{
        //    VFX_OBJ_CLOSE(m_compInst);
        //    m_compInst = NULL;
        //}
    }

    return MMI_RET_OK;
}


void VappEmailMainScrn::getNextAcctnFldr(EMAIL_ACCT_ID &acctID, EMAIL_FLDR_ID &fldrID)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_GET_NEXT_ACCT_FLDR, VFX_TRUE, acctID, fldrID);
    if (m_firstPageType != EMAIL_MAIN_FIRST_PAGE_ACCT_LIST)
    {
        return;
    }

    ((VappEmailAcctListPage*)m_firstPage)->getNextAcctnFldr(acctID, fldrID);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_GET_NEXT_ACCT_FLDR, VFX_FALSE, acctID, fldrID);
}


void VappEmailMainScrn::getPrevAcctnFldr(EMAIL_ACCT_ID &acctID, EMAIL_FLDR_ID &fldrID)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_GET_PREV_ACCT_FLDR, VFX_TRUE, acctID, fldrID);
    if (m_firstPageType != EMAIL_MAIN_FIRST_PAGE_ACCT_LIST)
    {
        return;
    }

    ((VappEmailAcctListPage*)m_firstPage)->getPrevAcctnFldr(acctID, fldrID);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_GET_PREV_ACCT_FLDR, VFX_FALSE, acctID, fldrID);
}


void VappEmailMainScrn::setCurrFldr(EMAIL_FLDR_ID fldrID)
{
    if (m_firstPageType != EMAIL_MAIN_FIRST_PAGE_ACCT_LIST)
    {
        return;
    }

    ((VappEmailAcctListPage*)m_firstPage)->setCurrFldr(fldrID);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_GET_CURR_FLDR, fldrID);
}


EMAIL_MSG_ID VappEmailMainScrn::getNextMsgID(EMAIL_MSG_ID currMsgID, VfxU32 &index, VfxU32 &total)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_GET_NEXT_MSG_ID, VFX_TRUE, currMsgID, index, total);
    EMAIL_MSG_ID msgID = EMAIL_MSG_INVALID_ID;
    switch (m_firstPageType)
    {
    case EMAIL_MAIN_FIRST_PAGE_ACCT_LIST:
    case EMAIL_MAIN_FIRST_PAGE_MSG_LIST:
        msgID = ((VappEmailMsgListPage*)getPage(EMAIL_PAGE_TYPE_MSG_LIST))->getNextMsgID(currMsgID, index, total);
        break;
    default:
        index = 0;
        total = 1;
        break;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_GET_NEXT_MSG_ID, VFX_FALSE, msgID, index, total);
    return msgID;
}


EMAIL_MSG_ID VappEmailMainScrn::getPrevMsgID(EMAIL_MSG_ID currMsgID, VfxU32 &index, VfxU32 &total)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_GET_PREV_MSG_ID, VFX_TRUE, currMsgID, index, total);
    EMAIL_MSG_ID msgID = EMAIL_MSG_INVALID_ID;
    switch (m_firstPageType)
    {
    case EMAIL_MAIN_FIRST_PAGE_ACCT_LIST:
    case EMAIL_MAIN_FIRST_PAGE_MSG_LIST:
        msgID = ((VappEmailMsgListPage*)getPage(EMAIL_PAGE_TYPE_MSG_LIST))->getPrevMsgID(currMsgID, index, total);
        break;
    default:
        index = 0;
        total = 1;
        break;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_GET_PREV_MSG_ID, VFX_FALSE, msgID, index, total);
    return msgID;
}


void VappEmailMainScrn::getMsgIndex(EMAIL_MSG_ID currMsgID, VfxU32 &index, VfxU32 &total)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_GET_MSG_INDEX, VFX_TRUE, currMsgID, index, total);
    switch (m_firstPageType)
    {
    case EMAIL_MAIN_FIRST_PAGE_ACCT_LIST:
    case EMAIL_MAIN_FIRST_PAGE_MSG_LIST:
        ((VappEmailMsgListPage*)getPage(EMAIL_PAGE_TYPE_MSG_LIST))->getMsgIndex(currMsgID, index, total);
        break;
    case EMAIL_MAIN_FIRST_PAGE_MSG_VIEW:
        ((VappEmailMsgViewPage*)getPage(EMAIL_PAGE_TYPE_MSG_VIEW))->getMsgIndex(currMsgID, index, total);
        break;
    default:
        index = 0;
        total = 1;
        break;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_GET_MSG_INDEX, VFX_FALSE, currMsgID, index, total);
}


void VappEmailMainScrn::launchComposer(EMAIL_ACCT_ID acctID, EMAIL_MSG_ID msgID, VappEmailComp::VappEmailEditModeEnum mode)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_LAUNCH_COMPOSER, acctID, msgID, mode);

    if (m_compInst != NULL)
    {
        VFX_OBJ_CLOSE(m_compInst);
    }

    VFX_OBJ_CREATE(m_compInst, VappEmailComp, this);
    if (gFirstPageInfo.lauch_comp.needLaunch == VFX_TRUE)
    {
        gFirstPageInfo.lauch_comp.needLaunch = VFX_FALSE;

        if (gFirstPageInfo.lauch_comp.subj != NULL)
        {
            m_compInst->newEmailSetSubj(gFirstPageInfo.lauch_comp.subj);
        }
        if (gFirstPageInfo.lauch_comp.cont != NULL)
        {
            m_compInst->newEmailSetCont(gFirstPageInfo.lauch_comp.cont);
        }
        if (gFirstPageInfo.lauch_comp.toAddr[0] != 0)
        {
            m_compInst->newEmailAddAddr(
                gFirstPageInfo.lauch_comp.toAddr, 
                gFirstPageInfo.lauch_comp.toName);
        }
        if (gFirstPageInfo.lauch_comp.attchPath[0] != 0)
        {
            m_compInst->newEmailAddAttch(
                gFirstPageInfo.lauch_comp.attchPath, 
                gFirstPageInfo.lauch_comp.deleleAttch);
        }

        memset(&(gFirstPageInfo.lauch_comp), 0, sizeof(vapp_email_composer_launch));

        m_compInst->newEmail(EMAIL_ACCT_INVALID_ID, this);
        return;
    }

    if (mode == VappEmailComp::EMAIL_MODE_NEW)
    {
        m_compInst->newEmailAddAddr(sendToAddr, sendToDisplayName);
        m_compInst->newEmail(acctID, this);
        sendToAddr = NULL;
        sendToDisplayName = NULL;
    }
    else
    {
        m_compInst->editEmail(msgID, this, mode);
    }
}


void VappEmailAcctListMenuProvider::setMenu(VcpListMenu* listMenu)
{
    m_listMenu = listMenu;
}


VfxBool VappEmailAcctListMenuProvider::getItemText(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxWString &textString,
            VcpListMenuTextColorEnum &textColor)
{
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_TEXT:
        {
            VfxBool result = getAcctDisplayInfo(index, textString);
            if (result != VFX_TRUE)
            {
                return VFX_FALSE;
            }
            break;
        }

        case VCP_LIST_MENU_FIELD_SUB_TEXT1:
        {
            EMAIL_ACCT_ID acctID = ((VappEmailAcctListPage*)getParent())->getAcctID(index);
            VfxU32 updateTime = VappEmailMgr::getInstance()->getAcctUpdatedTime(acctID);
            if (updateTime == 0)
            {
                textString.loadFromRes(STR_EMAIL_FTO_NEVER_UPDATE);
                return VFX_TRUE;
            }

            U32 localTime;
            applib_time_struct timeInfo = {0};
            VfxDateTime dateTime;

            localTime = applib_dt_sec_utc_to_local(updateTime);
            applib_dt_utc_sec_2_mytime(localTime, &timeInfo, MMI_FALSE);
            textString.loadFromRes(STR_EMAIL_UPDATED_AT);
            dateTime.setDateTime(&timeInfo);
            VfxWString text;
            textString += dateTime.getDateTimeString(
                            VFX_DATE_TIME_DATE_YEAR |
                            VFX_DATE_TIME_DATE_MONTH |
                            VFX_DATE_TIME_DATE_DAY |
                            VFX_DATE_TIME_TIME_HOUR |
                            VFX_DATE_TIME_TIME_MINUTE);
            break;
        }
        
        case VCP_LIST_MENU_FIELD_SUB_TEXT2:
        {
            return VFX_FALSE;
            //textString.setEmpty();
        }
        
        case VCP_LIST_MENU_FIELD_SUB_TEXT3:
        {
            return VFX_FALSE;
            //textString.setEmpty();
        }

        case VCP_LIST_MENU_FIELD_TAIL_TEXT:
        {
            srv_email_result_enum result;
            EMAIL_ACCT_ID acctID;
            EMAIL_ACCT_HANDLE acctHandle = EMAIL_ACCT_INVALID_HANDLE;
            EMAIL_FLDR_ID inboxID;
            srv_email_acct_folder_struct *fldrInfo =
                (srv_email_acct_folder_struct*)get_ctrl_buffer(sizeof(srv_email_acct_folder_struct));
            U32 unreadMsgNum = 0;
            U32 totalMsgNum = 0;

            acctID = ((VappEmailAcctListPage*)getParent())->getAcctID(index);
            inboxID = ((VappEmailAcctListPage*)getParent())->getFldrID(index);

            do
            {
                /* get inbox unread and total msg number */
                result = srv_email_acct_create(gEmailSrvHandle, &acctHandle);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                result = srv_email_acct_open(acctHandle, acctID);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                result = srv_email_acct_get_fldr_info(acctHandle, inboxID, fldrInfo);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                unreadMsgNum = fldrInfo->unread_count;
                totalMsgNum = fldrInfo->msg_count;

                textString += VFX_WSTR(" ");
                textString += VFX_WSTR_RES(STR_EMAIL_FTO_LEFT_PARENTHESES);

                VfxWString str;
                if (unreadMsgNum == 0)
                {
                    str.format("%d", totalMsgNum);
                }
                else
                {
                    str.format("%d/%d", unreadMsgNum, totalMsgNum);
                }

                textString += str;
                textString += VFX_WSTR_RES(STR_EMAIL_FTO_RIGHT_PARENTHESES);                
            } while(0);

            free_ctrl_buffer(fldrInfo);
            if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
            {
                srv_email_acct_destroy(acctHandle);
            }

            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                textString.setEmpty();
                return VFX_FALSE;
            }
            break;
        }

        default:
            return VFX_FALSE;
    }
    return VFX_TRUE;
}


VfxBool VappEmailAcctListMenuProvider::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color)
{
    text.loadFromRes(STR_EMAIL_FTO_NO_ACCOUNTS_ID);
    return VFX_TRUE;
}


VfxBool VappEmailAcctListMenuProvider::getItemImage(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxImageSrc &imageSrc)
{
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_ICON:
        {
            EMAIL_ACCT_ID defaultAcctID = EMAIL_ACCT_INVALID_ID;
            srv_email_result_enum result = srv_email_acct_get_default(&defaultAcctID);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                imageSrc.setResId(IMG_EMAIL_FTO_LIST_ACCT_NORMAIL_OHTERS);
                break;
            }
            VappEmailAcctListPage *acctListPage = (VappEmailAcctListPage*)getParent();
            EMAIL_ACCT_ID currAcctID = acctListPage->getAcctID(index);
            VappEmailAcctStateEnum acctState = VappEmailMgr::getInstance()->getAcctState(currAcctID);
            VfxResId resID = 0;

#ifdef __MMI_EMAIL_IMAP_PUSH__
            if (VappEmailPush::isEnable() && currAcctID == VappEmailPush::getPushAcctId())
            {
                switch (acctState)
                {
                    case VAPP_EMAIL_ACCT_STATE_NORMAL:
                        if (defaultAcctID == currAcctID)
                        {
                            resID = IMG_EMAIL_FTO_LIST_PUSH_ACCT_NORMAIL_DEFAULT;
                        }
                        else
                        {
                            resID = IMG_EMAIL_FTO_LIST_PUSH_ACCT_NORMAIL_OHTERS;
                        }
                        break;
                    case VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING:
                    case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING:
                        resID = IMG_EMAIL_FTO_LIST_PUSH_ACCT_WAITING;
                        break;
                    case VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING:
                        resID = IMG_EMAIL_FTO_LIST_PUSH_ACCT_SENDING;
                        break;
                    case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING:
                        resID = IMG_EMAIL_FTO_LIST_PUSH_ACCT_REFRESHING;
                        break;
                    case VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL:
                        if (defaultAcctID == currAcctID)
                        {
                            resID = IMG_EMAIL_FTO_LIST_PUSH_ACCT_SEND_ERROR_DEFAULT;
                        }
                        else
                        {
                            resID = IMG_EMAIL_FTO_LIST_PUSH_ACCT_SEND_ERROR_OHTERS;
                        }
                        break;
                    case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL:
                        if (defaultAcctID == currAcctID)
                        {
                            resID = IMG_EMAIL_FTO_LIST_PUSH_ACCT_REFRESH_ERROR_DEFAULT;
                        }
                        else
                        {
                            resID = IMG_EMAIL_FTO_LIST_PUSH_ACCT_REFRESH_ERROR_OTHERS;
                        }
                        break;
                    default:
                        resID = IMG_EMAIL_FTO_LIST_PUSH_ACCT_NORMAIL_OHTERS;
                        break;
                }

            }
            else
#endif
            {
                switch (acctState)
                {
                    case VAPP_EMAIL_ACCT_STATE_NORMAL:
                        if (defaultAcctID == currAcctID)
                        {
                            resID = IMG_EMAIL_FTO_LIST_ACCT_NORMAIL_DEFAULT;
                        }
                        else
                        {
                            resID = IMG_EMAIL_FTO_LIST_ACCT_NORMAIL_OHTERS;
                        }
                        break;
                    case VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING:
                    case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING:
                        resID = IMG_EMAIL_FTO_LIST_ACCT_WAITING;
                        break;
                    case VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING:
                        resID = IMG_EMAIL_FTO_LIST_MSG_SENDING;
                        break;
                    case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING:
                        resID = IMG_EMAIL_FTO_LIST_ACCT_REFRESHING;
                        break;
                    case VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL:
                        if (defaultAcctID == currAcctID)
                        {
                            resID = IMG_EMAIL_FTO_LIST_ACCT_SEND_ERROR_DEFAULT;
                        }
                        else
                        {
                            resID = IMG_EMAIL_FTO_LIST_ACCT_SEND_ERROR_OHTERS;
                        }
                        break;
                    case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL:
                        if (defaultAcctID == currAcctID)
                        {
                            resID = IMG_EMAIL_FTO_LIST_ACCT_REFRESH_ERROR_DEFAULT;
                        }
                        else
                        {
                            resID = IMG_EMAIL_FTO_LIST_ACCT_REFRESH_ERROR_OTHERS;
                        }
                        break;
                    default:
                        resID = IMG_EMAIL_FTO_LIST_ACCT_NORMAIL_OHTERS;
                        break;
                }

            }
            imageSrc.setResId(resID);
            break;
        }

        case VCP_LIST_MENU_FIELD_DISCLOSURE_IMG:
        {
            imageSrc.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
            break;
        }

        default:
            return VFX_FALSE;
    }
    return VFX_TRUE;
}


void VappEmailAcctListMenuProvider::closeItemImage(
        VfxU32 index,
        VcpListMenuFieldEnum fieldEnum,
        VfxImageSrc imageSrc)
{

}


VfxU32 VappEmailAcctListMenuProvider::getCount(void) const
{
    if (VappEmailMgr::getInstance()->getEmailAppState() == VAPP_EMAIL_STATE_TCARD_OUT)
    {
        return 0;
    }

    U32 acctNum = 0;
    srv_email_result_enum result = srv_email_acct_get_num(&acctNum);

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return 0;
    }

    ((VappEmailAcctListPage*)getParent())->initIDs(VFX_FALSE);
    return (VfxU32)acctNum;
}


VcpListMenuItemStateEnum VappEmailAcctListMenuProvider::getItemState(VfxU32 index) const
{
    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}


VfxBool VappEmailAcctListMenuProvider::swapItem(VfxU32 first, VfxU32 second)
{
    return VFX_FALSE;
}


VcpListMenuCellClientBaseFrame *VappEmailAcctListMenuProvider::getItemCustomContentFrame(
                                    VfxU32 index,
                                    VfxFrame *frame)
{
    return NULL;
}


void VappEmailAcctListMenuProvider::closeItemCustomContentFrame(
        VfxU32 index,
        VcpListMenuCellClientBaseFrame *baseFrame)
{
}


VfxBool VappEmailAcctListMenuProvider::getItemTextFrameFormat(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxTextFrame *frame)
{
    switch(fieldType)
    {
    case VCP_LIST_MENU_FIELD_TEXT:
        {
            srv_email_acct_info_cache_struct acctInfo;
            srv_email_acct_cache_get(((VappEmailAcctListPage*)getParent())->getAcctID(index), &acctInfo);
            if (acctInfo.unread_num != 0)
            {
                VfxFontDesc font = frame->getFont();
                font.setAttr(VFX_FONT_DESC_ATTR_BOLD);
                frame->setFont(font);
            }
        }
        break;
    case VCP_LIST_MENU_FIELD_SUB_TEXT1:
        break;
    case VCP_LIST_MENU_FIELD_SUB_TEXT2:
        break;
    case VCP_LIST_MENU_FIELD_TAIL_TEXT:
        {
            srv_email_acct_info_cache_struct acctInfo;
            srv_email_acct_cache_get(((VappEmailAcctListPage*)getParent())->getAcctID(index), &acctInfo);
            if (acctInfo.unread_num != 0)
            {
                VfxFontDesc font = frame->getFont();
                font.setAttr(VFX_FONT_DESC_ATTR_BOLD);
                frame->setFont(font);
            }
        }
    default:
        return VFX_FALSE;
    }
    return VFX_TRUE;
}


VfxBool VappEmailAcctListMenuProvider::getAcctDisplayInfo(VfxU32 index, VfxWString &textString)
{
    WCHAR *textCont = (WCHAR*)get_ctrl_buffer((SRV_EMAIL_MAX_ACCT_NAME_LEN + 1 + 6) * 2);
    textCont[0] = 0;
    srv_email_result_enum result;
    EMAIL_ACCT_ID acctID = ((VappEmailAcctListPage*)getParent())->getAcctID(index);
    S32 acctNameLength = SRV_EMAIL_MAX_ACCT_NAME_LEN + 1;

    result = srv_email_acct_get_name(acctID, textCont, acctNameLength);
    textString.loadFromMem((VfxWChar*)textCont);
    free_ctrl_buffer(textCont);

    if (result == SRV_EMAIL_RESULT_SUCC)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


void VappEmailAcctListPage::onInit()
{
    VfxPage::onInit();

    m_currItemIndex = 0;
    m_loadingPopup = NULL;
    m_confirmPopup = NULL;
    m_switchingStorage = VFX_FALSE;

    VfxWString titleText;
    titleText.loadFromMem((VfxWChar*)GetString(STR_EMAIL_FTO_ACCOUNTS_ID));
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(titleText);
    setTopBar(titleBar);

    VFX_OBJ_CREATE(m_toolbar, VcpToolBar, this);
    VfxWString tbText;
    tbText.loadFromRes(STR_EMAIL_FTO_NEW_EMAIL_ID);
    m_toolbar->addItem(EMAIL_ACCT_LIST_PAGE_TB_NEW_MSG, tbText, VfxResId(IMG_EMAIL_FTO_TB_NEW_MAIL));
    
    if (VappEmailMgr::getInstance()->isRefreshAllAcct() == VFX_TRUE)
    {
        tbText.loadFromRes(STR_GLOBAL_STOP);
		m_toolbar->addItem(EMAIL_ACCT_LIST_PAGE_TB_REFRESH, tbText, VfxResId(IMG_EMAIL_FTO_TB_STOP));
    }
    else
    {
        tbText.loadFromRes(STR_GLOBAL_REFRESH); 
		m_toolbar->addItem(EMAIL_ACCT_LIST_PAGE_TB_REFRESH, tbText, VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH));
    }
	
    tbText.loadFromRes(STR_GLOBAL_SETTINGS);
    m_toolbar->addItem(EMAIL_ACCT_LIST_PAGE_TB_SETTING, tbText, VfxResId(IMG_EMAIL_FTO_TB_EMAIL_SET));
    m_toolbar->m_signalButtonTap.connect(this, &VappEmailAcctListPage::onTBClick);
    setBottomBar(m_toolbar);

    VFX_OBJ_CREATE(m_listProvider, VappEmailAcctListMenuProvider, this);
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    VfxSize pageSize = getSize();
    m_listMenu->setRect(0, 0, pageSize.width, pageSize.height);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_QUINTUPLE_TEXT);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
    m_listMenu->m_signalItemTapped.connect(this, &VappEmailAcctListPage::onItemClick);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VappEmailMgr::getInstance()->m_signalAcctMsgNumChange.connect(this, &VappEmailAcctListPage::onMsgNumberChange);
    VappEmailMgr::getInstance()->m_signalAcctNwkDone.connect(this, &VappEmailAcctListPage::onAcctNwkDone);
    VappEmailMgr::getInstance()->m_signalAcctStateChange.connect(this, &VappEmailAcctListPage::onAcctStateChange);
#ifndef __MMI_EMAIL_STOR_CANNOT_SWITCH__
    VappEmailMgr::getInstance()->m_signalStoragePreSwitch.connect(this, &VappEmailAcctListPage::onPreSwitchStorage);
    VappEmailMgr::getInstance()->m_signalStorageFinishSwitch.connect(this, &VappEmailAcctListPage::onPostSwitchStorage);
#endif
}


void VappEmailAcctListPage::onDeinit()
{
    VfxPage::onDeinit();
}


void VappEmailAcctListPage::onRotate(const VfxScreenRotateParam &param)
{
    if (param.rotateTo == VFX_SCR_ROTATE_TYPE_90 ||
        param.rotateTo == VFX_SCR_ROTATE_TYPE_270 ||
        param.rotateTo == VFX_SCR_ROTATE_TYPE_LANDSCAPE)
    {
        gScrnWidth = LCD_HEIGHT;
        gScrnHeight = LCD_WIDTH;
    }
    else
    {
        gScrnWidth = LCD_WIDTH;
        gScrnHeight = LCD_HEIGHT;
    }
}


void VappEmailAcctListPage::onEnter(VfxBool isBackward)
{
    VappEmailStateEnum emailState = VappEmailMgr::getInstance()->getEmailAppState();
    VfxPage::onEnter(isBackward);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_PAGE_ON_ENTER, isBackward, emailState);
#ifndef __MMI_EMAIL_STOR_CANNOT_SWITCH__
    if (emailState == VAPP_EMAIL_STATE_TCARD_OUT && m_confirmPopup == NULL)
    {
        VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, getMainScr());
        m_confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
        m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        m_confirmPopup->setText(VFX_WSTR_RES(STR_EMAIL_FTO_SWITCH_STORAGE_ID));
        VfxWString btnText1;
        btnText1.loadFromRes(STR_GLOBAL_YES);
        VfxWString btnText2;
        btnText2.loadFromRes(STR_GLOBAL_NO);
        m_confirmPopup->setCustomButton(
            btnText1,
            btnText2,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            VCP_POPUP_BUTTON_TYPE_NORMAL);
        m_confirmPopup->m_signalButtonClicked.connect(this, &VappEmailAcctListPage::switchStorage);
        m_confirmPopup->setAutoDestory(VFX_TRUE);
        m_confirmPopup->show(VFX_FALSE);
        VappEmailMgr::getInstance()->m_signalStorageFinishSwitch.connect(this, &VappEmailAcctListPage::storageSwitchDone);
        return;
    }
#endif
    if (isBackward)
    {
        enterPage(VFX_TRUE);
    }
    else
    {
        //not backward, will call by on2ndEnter();
    }
}


void VappEmailAcctListPage::on2ndEnter()
{
    //Enter page after SSE, for performance
    initIDs(VFX_TRUE);
    
    m_listMenu->setContentProvider(m_listProvider);

    enterPage(VFX_FALSE);
}


void VappEmailAcctListPage::onTBClick(VfxObject *obj, VfxId index)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_PAGE_TOOLBAR_CLICK, index);
    switch (index)
    {
    case EMAIL_ACCT_LIST_PAGE_TB_NEW_MSG:
        {
            EMAIL_ACCT_ID acctID;
            srv_email_result_enum result;
            result = srv_email_acct_get_default(&acctID);

            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                VappEmailErrorPopup *errorPopup;
                VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getMainScr());
                errorPopup->showErrorPopup(result, getMainScr(), EMAIL_PAGE_TYPE_ACCT_LISG);
                return;
            }

            VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
            mainScr->launchComposer(acctID, EMAIL_MSG_INVALID_ID, VappEmailComp::EMAIL_MODE_NEW);
            break;
        }
    case EMAIL_ACCT_LIST_PAGE_TB_REFRESH:
        {
            if (VappEmailMgr::getInstance()->getEmailAppState() == VAPP_EMAIL_STATE_FLIGHT_MODE)
            {
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_INFO,
                    (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE));
                return;
            }

            if (VappEmailMgr::getInstance()->isRefreshAllAcct() == VFX_FALSE)
            {
                if (VappEmailMgr::getInstance()->refreshAllAcct() == VAPP_EMAIL_RES_WOULDBLOCK)
                {
                    VfxWString tbText;
                    tbText.loadFromRes(STR_GLOBAL_STOP);
                    m_toolbar->changeItem(
                        EMAIL_ACCT_LIST_PAGE_TB_REFRESH,
                        tbText,
                        VfxResId(IMG_EMAIL_FTO_TB_STOP));
                }
                else
                {
                    /* popup */
                }
            }
            else
            {
                VappEmailMgr::getInstance()->cancelAllAcctRefresh();
                VfxWString tbText;
                tbText.loadFromRes(STR_GLOBAL_REFRESH);
                m_toolbar->changeItem(
                    EMAIL_ACCT_LIST_PAGE_TB_REFRESH,
                    tbText,
                    VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH));
            }
        }
        break;
    case EMAIL_ACCT_LIST_PAGE_TB_SETTING:
        {
            VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
            mainScr->closeCompInstanse();
            VappEmailGlobalSettingScr *ass;
            VFX_OBJ_CREATE(ass, VappEmailGlobalSettingScr, getApp());
            ass->show();
            break;
        }
    default:
        return;
    }
}


void VappEmailAcctListPage::onItemClick(VcpListMenu *listMenu, VfxU32 index)
{
    VappEmailMsgListPage *msgListPage;
    VfxBool showTitleBarBtn = VFX_FALSE;
    if (m_listProvider->getCount() > 1)
    {
        showTitleBarBtn = VFX_TRUE;
    }
    VFX_OBJ_CREATE_EX(
        msgListPage,
        VappEmailMsgListPage,
        getParent(),
        (m_acctIDList[index], m_folderIDList[index], SRV_EMAIL_FLDR_TYPE_INBOX, showTitleBarBtn));
    ((VappEmailMainScrn*)getMainScr())->pushPage(EMAIL_PAGE_TYPE_MSG_LIST, msgListPage);
    m_currItemIndex = index;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_PAGE_ITEM_CLICK, index, m_acctIDList[index], m_folderIDList[index]);
}


void VappEmailAcctListPage::getNextAcctnFldr(EMAIL_ACCT_ID &acctID, EMAIL_FLDR_ID &fldrID)
{
    U32 acctNum = 0;
    srv_email_result_enum result = srv_email_acct_get_num(&acctNum);

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getParent());
        errorPopup->showErrorPopup(result);
        acctID = 0;
        fldrID = 0;
        return;
    }

    m_currItemIndex = (m_currItemIndex + 1) % acctNum;
    acctID = m_acctIDList[m_currItemIndex];
    fldrID = m_folderIDList[m_currItemIndex];
}


void VappEmailAcctListPage::getPrevAcctnFldr(EMAIL_ACCT_ID &acctID, EMAIL_FLDR_ID &fldrID)
{
    U32 acctNum = 0;
    srv_email_result_enum result = srv_email_acct_get_num(&acctNum);

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getParent());
        errorPopup->showErrorPopup(result);
        acctID = 0;
        fldrID = 0;
        return;
    }

    m_currItemIndex = (m_currItemIndex - 1 + acctNum) % acctNum;
    acctID = m_acctIDList[m_currItemIndex];
    fldrID = m_folderIDList[m_currItemIndex];
}

#ifndef __MMI_EMAIL_STOR_CANNOT_SWITCH__
void VappEmailAcctListPage::switchStorage(VfxObject *obj, VfxId id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_SWITCH_STORATE, id);
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        char drive = 0;
        SRV_FMGR_DRVLIST_HANDLE fmgrHd = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
        VfxU32 drvCount = srv_fmgr_drivelist_count(fmgrHd);
        if (drvCount != 0)
        {
            drive = srv_fmgr_drivelist_get_drv_letter(fmgrHd, 0);
        }
        VappEmailMgr::getInstance()->switchStorage(drive);
        showLoading();
    }
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2 || id == VCP_POPUP_BUTTON_NO_PRESSED)
    {
        getMainScr()->closePage(EMAIL_PAGE_TYPE_ACCT_LISG);
    }
    m_confirmPopup = NULL;
}

void VappEmailAcctListPage::onPreSwitchStorage()
{
    m_switchingStorage = VFX_TRUE;
}


void VappEmailAcctListPage::onPostSwitchStorage(VappEmailResEnum result)
{
    m_switchingStorage = VFX_FALSE;
}


void VappEmailAcctListPage::storageSwitchDone(VappEmailResEnum result)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_SWITCH_STORATE_DONE, result);

    /* 
     * disconnect the switch storage signal means only handle it once
     * when entry Email with storage in T card but T card removed.
     * invoke by mainScrn
     */
    VappEmailMgr::getInstance()->m_signalStorageFinishSwitch.disconnect(this, &VappEmailAcctListPage::storageSwitchDone);

    closeLoading();

    if (result != VAPP_EMAIL_RES_SUCC)
    {
        /* popup */
        getMainScr()->closePage(EMAIL_PAGE_TYPE_ACCT_LISG);
        return;
    }

#ifdef __MMI_SSO__
    if (vapp_email_sso_check_cloud_acct() && !g_emailAppCreateSsoAcctQueryed)  // need to add SSO account or not
    {
        if (m_confirmPopup == NULL)
        {
            showCreateSsoAcctConfirm();
            return;
        }
    }
#endif

    U32 acctNum = 0;
    srv_email_result_enum srvResult = srv_email_acct_get_num(&acctNum);
    if (srvResult != SRV_EMAIL_RESULT_SUCC)
    {
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getMainScr());
        errorPopup->showErrorPopup(result, getMainScr(), EMAIL_PAGE_TYPE_ACCT_LISG);
        return;
    }

    if (acctNum == 0 && m_confirmPopup == NULL)
    {
        m_toolbar->setDisableItem(EMAIL_ACCT_LIST_PAGE_TB_REFRESH, VFX_TRUE);
        m_toolbar->setDisableItem(EMAIL_ACCT_LIST_PAGE_TB_NEW_MSG, VFX_TRUE);
        showCreateAcctConfirm();
        return;
    }

    enterPage(VFX_TRUE);
}
#endif


void VappEmailAcctListPage::enterPage(VfxBool isBackward)
{
    srv_email_result_enum result;
    U32 acctNum;
    result = srv_email_acct_get_num(&acctNum);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getMainScr());
        errorPopup->showErrorPopup(result, getMainScr(), EMAIL_PAGE_TYPE_ACCT_LISG);
        return;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_ENTER_PAGE, isBackward, acctNum);
    
    VfxWString tbText;
    if (VappEmailMgr::getInstance()->isRefreshAllAcct() == VFX_TRUE)
    {
        tbText.loadFromRes(STR_GLOBAL_STOP);
        m_toolbar->changeItem(
            EMAIL_ACCT_LIST_PAGE_TB_REFRESH,
            tbText,
            VfxResId(IMG_EMAIL_FTO_TB_STOP));
    }
    else
    {
        tbText.loadFromRes(STR_GLOBAL_REFRESH);
        m_toolbar->changeItem(
            EMAIL_ACCT_LIST_PAGE_TB_REFRESH,
            tbText,
            VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH));
    }
    
    if (acctNum == 0)
    {
        m_toolbar->setDisableItem(EMAIL_ACCT_LIST_PAGE_TB_REFRESH, VFX_TRUE);
        m_toolbar->setDisableItem(EMAIL_ACCT_LIST_PAGE_TB_NEW_MSG, VFX_TRUE);
    }
    else
    {
        m_toolbar->setDisableItem(EMAIL_ACCT_LIST_PAGE_TB_REFRESH, VFX_FALSE);
        m_toolbar->setDisableItem(EMAIL_ACCT_LIST_PAGE_TB_NEW_MSG, VFX_FALSE);
        VappEmailStateEnum emailState;
        if (!VappEmailMgr::getInstance()->isNetworkReady(emailState))
        {
            m_toolbar->setDisableItem(EMAIL_ACCT_LIST_PAGE_TB_REFRESH, VFX_TRUE);
        }
    }

    if (isBackward)
    {
        initIDs(VFX_TRUE);
        m_listMenu->resetAllItems(VFX_TRUE);
    }
    else
    {
#ifdef __MMI_SSO__
        if (vapp_email_sso_check_cloud_acct() && !g_emailAppCreateSsoAcctQueryed)  // need to add SSO account or not
        {
            if (m_confirmPopup == NULL)
            {
                showCreateSsoAcctConfirm();
            }
        }
        else
        {
            if (acctNum == 0 && m_confirmPopup == NULL)
            {
                showCreateAcctConfirm();
            }
        }
#else /* __MMI_SSO__ */
        if (acctNum == 0 && m_confirmPopup == NULL)
        {
            showCreateAcctConfirm();
        }
#endif /* __MMI_SSO__ */
    }
}


void VappEmailAcctListPage::showCreateAcctConfirm()
{
    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, getMainScr());
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_confirmPopup->setText(VFX_WSTR_RES(STR_EMAIL_FTO_START_CREATE_ACCT_ID));
    VfxWString btnText1;
    btnText1.loadFromRes(STR_EMAIL_FTO_CREATE_ID);
    VfxWString btnText2;
    btnText2.loadFromRes(STR_GLOBAL_CANCEL);
    m_confirmPopup->setCustomButton(
        btnText1,
        btnText2,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_confirmPopup->m_signalButtonClicked.connect(this, &VappEmailAcctListPage::onCreateAcctConfirmBtnClick);
    m_confirmPopup->setAutoDestory(VFX_TRUE);
    m_confirmPopup->show(VFX_FALSE);  
}


void VappEmailAcctListPage::initIDs(VfxBool resetAll)
{
    if (resetAll == VFX_TRUE)
    {
        memset(m_folderIDList, 0, sizeof(m_folderIDList));
        memset(m_acctIDList, 0, sizeof(m_acctIDList));
    }

    srv_email_result_enum result;
    EMAIL_ACCT_ID acctIDList[MMI_EMAIL_MAX_ACCTS];
    U32 acctNum = 0;

    do
    {
        result = srv_email_acct_get_num(&acctNum);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        if (acctNum == 0)
        {
            return;
        }
        result = srv_email_acct_get_acct_id(0, (S32*)&acctNum, acctIDList);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        /* get inbox ID */
        for (U32 i = 0; i < acctNum; i++)
        {
            if (resetAll == VFX_TRUE)
            {
                m_acctIDList[i] = acctIDList[i];
                m_folderIDList[i] = srv_email_fldr_type_to_fldr_id(
                                        acctIDList[i],
                                        SRV_EMAIL_FLDR_TYPE_INBOX);
            }
            else
            {
                if (m_acctIDList[i] != acctIDList[i])
                {
                    m_acctIDList[i] = acctIDList[i];
                    m_folderIDList[i] = srv_email_fldr_type_to_fldr_id(
                                            acctIDList[i],
                                            SRV_EMAIL_FLDR_TYPE_INBOX);
                }
            }
        }
    } while(0);

    if (resetAll == VFX_FALSE)
    {
        for (U32 i = acctNum; i < MMI_EMAIL_MAX_ACCTS; i++)
        {
            m_acctIDList[i] = 0;
            m_folderIDList[i] = 0;
        }
    }

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getMainScr());
        errorPopup->showErrorPopup(result, getMainScr(), EMAIL_PAGE_TYPE_ACCT_LISG);
    }
}


void VappEmailAcctListPage::onCreateAcctConfirmBtnClick(VfxObject *btn, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        VappEmailAcctWizardScreen *ass;
        VFX_OBJ_CREATE(ass, VappEmailAcctWizardScreen, getApp());
        ass->show();
    }
    m_confirmPopup = NULL;
}


void VappEmailAcctListPage::onMsgNumberChange(EMAIL_ACCT_ID, VfxU32, VfxU32)
{
    m_listMenu->resetAllItems(VFX_TRUE);
}


void VappEmailAcctListPage::onAcctNwkDone(EMAIL_ACCT_ID, VappEmailNwkDoneEnum operation, VappEmailResStruct res)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_ACCT_NWK_DONE, operation, res.result);

    if (m_switchingStorage == VFX_TRUE)
    {
        return;
    }

    if (operation == VAPP_EMAIL_NWK_DONE_REFRESH_ALL)
    {
        VfxWString tbText;
        tbText.loadFromRes(STR_GLOBAL_REFRESH);
        m_toolbar->changeItem(
            EMAIL_ACCT_LIST_PAGE_TB_REFRESH,
            tbText,
            VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH));
    }

    if (res.result == VAPP_EMAIL_RES_SUCC)
    {
        m_listMenu->resetAllItems(VFX_TRUE);
    }
}


void VappEmailAcctListPage::onAcctStateChange(EMAIL_ACCT_ID acctID, VappEmailAcctStateEnum state)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_ACCT_STATE_CHANGE, acctID, state);

    if (m_switchingStorage == VFX_TRUE)
    {
        return;
    }

    VappEmailStateEnum emailState = VappEmailMgr::getInstance()->getEmailAppState();
    if (emailState == VAPP_EMAIL_STATE_TCARD_OUT || emailState == VAPP_EMAIL_STATE_USB_MODE)
    {
        return;
    }

    initIDs(VFX_FALSE);
    m_listMenu->resetAllItems(VFX_TRUE);
}


#ifdef __MMI_SSO__
void VappEmailAcctListPage::showCreateSsoAcctConfirm()
{
    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, getMainScr());
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_confirmPopup->setText(VFX_WSTR_RES(STR_EMAIL_FTO_SSO_IMPORT_ID));
    VfxWString btnText1;
    btnText1.loadFromRes(STR_EMAIL_FTO_CREATE_ID);
    VfxWString btnText2;
    btnText2.loadFromRes(STR_GLOBAL_CANCEL);
    m_confirmPopup->setCustomButton(
        btnText1,
        btnText2,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_confirmPopup->m_signalButtonClicked.connect(
        this, 
        &VappEmailAcctListPage::onCreateSsoAcctConfirmBtnClick);
    m_confirmPopup->setAutoDestory(VFX_TRUE);
    m_confirmPopup->show(VFX_FALSE);
}


void VappEmailAcctListPage::onCreateSsoAcctConfirmBtnClick(VfxObject *btn, VfxId id)
{
    m_confirmPopup = NULL;

    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        addSsoAcct();
    }
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
        g_emailAppCreateSsoAcctQueryed = VFX_TRUE;
        U32 acctNum = 0;
        srv_email_acct_get_num(&acctNum);
        
        if (acctNum == 0 && m_confirmPopup == NULL)
        {
            showCreateAcctConfirm();
        }
    }
}


void VappEmailAcctListPage::addSsoAcct()
{
    VfxU32 acctCnt = 0;
    srv_email_acct_get_num(&acctCnt);

    if (acctCnt >= MMI_EMAIL_MAX_ACCTS)
    {
        replaceAcctForSso();
    }
    else
    {
        vapp_email_sso_add_acct(vapp_email_sso_get_acct());
        g_emailAppCreateSsoAcctQueryed = VFX_TRUE;
        m_listMenu->resetAllItems(VFX_TRUE);
        enterPage(VFX_TRUE);
    }
}


void VappEmailAcctListPage::replaceAcctForSso()
{
    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, getMainScr());
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    m_confirmPopup->setText(VFX_WSTR_RES(STR_EMAIL_FTO_SSO_REPLACE_ID));
    m_confirmPopup->m_signalButtonClicked.connect(
        this, 
        &VappEmailAcctListPage::onReplaceForSsoAcctConfirmBtnClick);
    m_confirmPopup->show(VFX_FALSE);
}


void VappEmailAcctListPage::onReplaceForSsoAcctConfirmBtnClick(VfxObject *btn, VfxId id)
{
    m_confirmPopup = NULL;

    if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
        g_emailAppCreateSsoAcctQueryed = VFX_TRUE;
        VappEmailSsoReplaceAcctPage *page;
        VFX_OBJ_CREATE(page, VappEmailSsoReplaceAcctPage, this);
        getMainScr()->pushPage(0, page);
    }
    else if (id == VCP_CONFIRM_POPUP_BUTTON_NO)
    {
        g_emailAppCreateSsoAcctQueryed = VFX_TRUE;
        U32 acctNum = 0;
        srv_email_acct_get_num(&acctNum);
        if (acctNum == 0 && m_confirmPopup == NULL)
        {
            showCreateAcctConfirm();
        }
    }
}
#endif /* __MMI_SSO__ */


#ifdef __MMI_SSO__

void VappEmailSsoReplaceAcctPage::initData(void)
{
    m_selectedIndex = 0;
    m_acctCount = 0;

    srv_email_acct_get_num(&m_acctCount);

    for (VfxU32 i = 0; i < MMI_EMAIL_MAX_ACCTS; ++i)
    {
        m_acctId[i] = EMAIL_ACCT_INVALID_ID;
    }
    srv_email_acct_get_acct_id(
        0,
        (VfxS32*)&m_acctCount,
        (EMAIL_ACCT_ID*)&m_acctId[0]);
}

void VappEmailSsoReplaceAcctPage::onInit()
{
    VfxPage::onInit();

    vapp_email_set_titlebar(STR_GLOBAL_REPLACE, this);

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setContentProvider(this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_menu->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION, VFX_TRUE);
    m_menu->m_signalItemSelectionStateChanged.connect(
        this, &VappEmailSsoReplaceAcctPage::onItemStateChanged);
    m_menu->setRect(0, 0, getSize().width, getSize().height);
    m_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(
        this, &VappEmailSsoReplaceAcctPage::onToolBarClick);
    m_toolBar->addItem(
        'RPLC',
        VFX_WSTR_RES(STR_GLOBAL_REPLACE),
        VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH);
    m_toolBar->addItem(
        'CNCL',
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        IMG_EMAIL_FTO_CANCEL);
    setBottomBar(m_toolBar);
}


void VappEmailSsoReplaceAcctPage::onEnter(VfxBool isBackward)
{
    initData();
    m_menu->updateAllItems();
}


void VappEmailSsoReplaceAcctPage::onItemStateChanged(
    VcpListMenu *sender,
    VfxU32 index,
    VcpListMenuItemStateEnum newState)
{
    if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        m_selectedIndex = index;
    }
}


void VappEmailSsoReplaceAcctPage::onToolBarClick(VfxObject *obj, VfxId id)
{    
    switch(id)
    {
        case 'RPLC':
        {
            VappEmailAcctStateEnum acctState;

            if (VappEmailMgr::getInstance()->isAcctEntered(m_acctId[m_selectedIndex]))
            {
                vapp_email_alert_cfm(STR_EMAIL_FTO_EDIT_ACCT_USING);
                return;
            }

#ifdef __MMI_EMAIL_IMAP_PUSH__
            if (m_acctId[m_selectedIndex] == VappEmailPush::getPushAcctId())
            {
                VfxWString buttonStr(VFX_WSTR_RES(STR_GLOBAL_OK));
                VfxWString str1(VFX_WSTR_RES(STR_EMAIL_FTO_PUSH_EMAIL_ACCT));
                VfxWString str2(VFX_WSTR_RES(STR_EMAIL_FTO_CANNOT_REPLACE));
                VfxWString text;
				text += str1;
				text += VFX_WSTR("\n");
				text += str2;
                
                vapp_nmgr_global_popup_show_confirm_one_button_str(
                        MMI_SCENARIO_ID_DEFAULT,
                        VCP_POPUP_TYPE_FAILURE, 
                        text, 
                        buttonStr, 
                        VCP_POPUP_BUTTON_TYPE_NORMAL,
                        NULL,
                        NULL);
                return;
            }
#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */

            acctState = VappEmailMgr::getInstance()->getAcctState(m_acctId[m_selectedIndex]);
            if (acctState != VAPP_EMAIL_ACCT_STATE_NORMAL &&
                acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL &&
                acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL)
            {
                vapp_email_alert_cfm(STR_EMAIL_FTO_EDIT_ACCT_USING);
                return;
            }

            VappEmailStateEnum emailState;
            emailState = VappEmailMgr::getInstance()->getEmailAppState();    
            if (emailState == VAPP_EMAIL_STATE_DEINITED ||
                emailState == VAPP_EMAIL_STATE_INITIALIZING ||
                emailState == VAPP_EMAIL_STATE_USB_MODE ||
                emailState == VAPP_EMAIL_STATE_TCARD_OUT)
            {
                VfxResId errId = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
                if (emailState == VAPP_EMAIL_STATE_USB_MODE)
                {
                    errId = STR_EMAIL_FTO_OTAP_FAIL_MASS_STORAGE;
                }
                vapp_email_alert_cfm(errId);
                return;
            }
            
            srv_email_result_enum res = srv_email_acct_delete(m_acctId[m_selectedIndex]);            
            VappEmailMgr::getInstance()->notifyAcctDelete(m_acctId[m_selectedIndex]);
            mmi_email_auto_check_delete_acct(m_acctId[m_selectedIndex], MMI_TRUE);
            mmi_email_sig_delete_acct(m_acctId[m_selectedIndex], MMI_TRUE);

            vapp_email_sso_add_acct(vapp_email_sso_get_acct());
            
            getMainScr()->popPage();
            break;
        }
        case 'CNCL':
        {
            getMainScr()->popPage();
            break;
        }
    }
}

VfxBool VappEmailSsoReplaceAcctPage::getItemText(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxWString &text,
    VcpListMenuTextColorEnum &color)
{
    if (index < (VfxU32)m_acctCount)
    {
        srv_email_acct_info_cache_struct acctInfo;
        srv_email_acct_cache_get(m_acctId[index], &acctInfo);
        text.loadFromMem((const VfxWChar*)&acctInfo.acct_name);

        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxU32 VappEmailSsoReplaceAcctPage::getCount() const
{
    return m_acctCount;
}

VcpListMenuItemStateEnum VappEmailSsoReplaceAcctPage::getItemState(
    VfxU32 index) const
{
    if (index == m_selectedIndex)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}
#endif /* __MMI_SSO__ */



void VappEmailErrorPopup::showErrorPopup(
        srv_email_result_enum result,
        VfxMainScr *mainScr,
        EmailPageTypeEnum popPage1,
        EmailPageTypeEnum popPage2,
        EmailPageTypeEnum popPage3)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_SHOW_SRV_ERROR, result, mainScr, popPage1, popPage2);
    m_mainScr = mainScr;
    m_popPage1 = popPage1;
    m_popPage2 = popPage2;
    m_popPage3 = popPage3;

    U16 strID = STR_GLOBAL_ERROR;
    U16 entry = 0;
    if (result == SRV_EMAIL_RESULT_FS_ERROR)
    {
        strID = (U16)srv_fmgr_fs_error_get_string(srv_email_errno_get());
    }
    else
    {
        entry = sizeof(email_err_tbl) / sizeof(email_app_err_struct);
        for (U16 i = 0; i < entry; i++)
        {
            if (email_err_tbl[i].err_no == result)
            {
                strID = email_err_tbl[i].str_id;
            }
        }
    }

    setInfoType(m_popupType);
    setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    setAutoDestory(VFX_TRUE);
    if (m_postFix.isEmpty())
    {
        setText(VFX_WSTR_RES(strID));
    }
    else
    {
        VfxWString text;
        text.loadFromRes(strID);
        text += m_postFix;
        setText(text);
    }
    show(VFX_TRUE);
}


void VappEmailErrorPopup::showErrorPopup(
        VappEmailResStruct result,
        VfxMainScr *mainScr,
        EmailPageTypeEnum popPage1,
        EmailPageTypeEnum popPage2,
        EmailPageTypeEnum popPage3)
{
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MAIN_SHOW_SINGLETON_ERROR,
        result.result,
        result.major,
        result.minor,
        mainScr,
        popPage1,
        popPage2);
    m_mainScr = mainScr;
    m_popPage1 = popPage1;
    m_popPage2 = popPage2;
    m_popPage3 = popPage3;

    U16 strID = STR_GLOBAL_ERROR;
    if (result.result == VAPP_EMAIL_RES_SERVICE_ERROR)
    {
        U16 entry = 0;
        switch (result.major)
        {
            case SRV_EMAIL_MAIL_ERROR:
                if (result.minor == SRV_EMAIL_RESULT_FS_ERROR)
                {
                    strID = (U16)srv_fmgr_fs_error_get_string(srv_email_errno_get());
                }
                else
                {
                    entry = sizeof(email_err_tbl) / sizeof(email_app_err_struct);
                    for (U16 i = 0; i < entry; i++)
                    {
                        if (email_err_tbl[i].err_no == result.minor)
                        {
                            strID = email_err_tbl[i].str_id;
                        }
                    }
                }
                break;

            case SRV_EMAIL_FS_ERROR:
            case SRV_EMAIL_DRM_ERROR:
            case SRV_EMAIL_RESULT_FS_ERROR:
                strID = (U16)srv_fmgr_fs_error_get_string(result.minor);
                break;

            case SRV_EMAIL_SOCKET_ERROR:
            case SRV_EMAIL_TLS_ERROR:
                strID = STR_EMAIL_ERROR_CODE_NETWORK_ID;
                break;

            default:
                break;
        }
    }
    else
    {
        /*
         * result.result == VAPP_EMAIL_RES_FAIL
         * result.result == VAPP_EMAIL_RES_ACCT_EDIT_MODE
         * result.result == VAPP_EMAIL_RES_FLDR_MULTI_SELECT
         * result.result == VAPP_EMAIL_RES_NETWORK_RUNNING
         */

    }

    setInfoType(m_popupType);
    setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    setAutoDestory(VFX_TRUE);
    if (m_postFix.isEmpty())
    {
        setText(VFX_WSTR_RES(strID));
    }
    else
    {
        VfxWString text;
        text.loadFromRes(strID);
        text += m_postFix;
        setText(text);
    }
    show(VFX_TRUE);
}



void VappEmailErrorPopup::showErrorPopup(
        VfxResId strID,
        VfxMainScr *mainScr,
        EmailPageTypeEnum popPage1,
        EmailPageTypeEnum popPage2,
        EmailPageTypeEnum popPage3)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_SHOW_RES_ERROR, strID, mainScr, popPage1, popPage2);
    m_mainScr = mainScr;
    m_popPage1 = popPage1;
    m_popPage2 = popPage2;
    m_popPage3 = popPage3;

    setInfoType(m_popupType);
    setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    setAutoDestory(VFX_TRUE);
    if (m_postFix.isEmpty())
    {
        setText(VFX_WSTR_RES(strID));
    }
    else
    {
        VfxWString text;
        text.loadFromRes(strID);
        text += m_postFix;
        setText(text);
    }
    show(VFX_TRUE);
}


void VappEmailErrorPopup::showErrorPopup(
        VfxWString &stirng,
        VfxMainScr *mainScr,
        EmailPageTypeEnum popPage1,
        EmailPageTypeEnum popPage2,
        EmailPageTypeEnum popPage3)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_SHOW_STR_ERROR, mainScr, popPage1, popPage2);
    m_mainScr = mainScr;
    m_popPage1 = popPage1;
    m_popPage2 = popPage2;
    m_popPage3 = popPage3;

    setInfoType(m_popupType);
    setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    setAutoDestory(VFX_TRUE);
    if (m_postFix.isEmpty())
    {
        setText(stirng);
    }
    else
    {
        VfxWString text(stirng);
        text += m_postFix;
        setText(text);
    }
    show(VFX_TRUE);
}


void VappEmailErrorPopup::onDeinit()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_ERROR_POPUP_DEINIT);

    VcpConfirmPopup::onDeinit();

    if (m_mainScr != NULL)
    {
        if (m_popPage1 != EMAIL_PAGE_TYPE_BASE)
        {
            m_mainScr->closePage(m_popPage1);
        }
        if (m_popPage2 != EMAIL_PAGE_TYPE_BASE)
        {
            m_mainScr->closePage(m_popPage2);
        }
        if (m_popPage3 != EMAIL_PAGE_TYPE_BASE)
        {
            m_mainScr->closePage(m_popPage2);
        }
    }
}
