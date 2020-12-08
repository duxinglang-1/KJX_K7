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
 *  vapp_secset_ssc.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Security setting
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_secset.h"
#include "vapp_secset_str.h"
#include "mmi_rp_vapp_secset_def.h"
extern "C"
{
#include "GlobalResDef.h"
#include "SecSetGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NotificationGprot.h"

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_B__) 
#include "dcmgr.h" // DCM
#endif
}

using namespace VappSecSetStr;


#if (MMI_MAX_SIM_NUM >= 2)

class VappSecSetSimSel : public VfxPage
{
private:
    VcpFormItemLauncherCell *m_simCell[MMI_SIM_TOTAL];
    mmi_sim_enum m_simSelected;

    void onSimTapped(VcpFormItemCell *cell, VfxId id);

protected:
    virtual void onInit();
    virtual void onBack();

public:
    enum ResultEnum
    {
        RESULT_SIM_SELECTED,
        RESULT_BACK_SELECTED,

        RESULT_END_OF_ENUM
    };

    VfxSignal2<VappSecSetSimSel*, ResultEnum> m_signalDone;

    VappSecSetSimSel() : m_simSelected(MMI_SIM_NONE)
    {
        m_simCell[0] = NULL;
    }

    mmi_sim_enum getSimSelected()
    {
        return m_simSelected;
    }
};

#pragma arm section code = "DYNAMIC_CODE_SECSET_ROCODE", rodata = "DYNAMIC_CODE_SECSET_RODATA"

void VappSecSetSimSel::onInit()
{
    VfxPage::onInit();

    // Title bar
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(STR_ID_VAPP_SECSET_SELECT_SIM);
    setTopBar(titleBar);

    VcpForm *form;
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setSize(getSize());
    form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);

        if (srv_sim_ctrl_is_inserted(sim))
        {
            VFX_OBJ_CREATE(m_simCell[i], VcpFormItemLauncherCell, form);
            VfxResId simStrId = getSimIDNameByIndex(i);
            m_simCell[i]->setMainText(simStrId);
            m_simCell[i]->m_signalTap.connect(this, &VappSecSetSimSel::onSimTapped);
            form->addItem(m_simCell[i], i);
        }
    }
}


void VappSecSetSimSel::onBack()
{
    m_signalDone.postEmit(this, RESULT_BACK_SELECTED);
}


void VappSecSetSimSel::onSimTapped(VcpFormItemCell *cell, VfxId id)
{
    m_simSelected = srv_sim_ctrl_get_sim_by_index(static_cast<VfxS32>(id));
    m_signalDone.emit(this, RESULT_SIM_SELECTED);
}
#pragma arm section code, rodata

#endif


class VappSecSetSSCChv : public VfxObject
{
    VFX_DECLARE_CLASS(VappSecSetSSCChv);

private:

    VfxMainScr *m_mainScr;
    mmi_proc_func m_callbackProc;
    void *m_callbackUserData;
    VfxWeakPtr<VcpIndicatorPopup> m_waitingInd;
    VfxBool m_chvWasBlocked;
    
#if (MMI_MAX_SIM_NUM >= 2)
    srv_sim_ctrl_pwd_type_enum m_pwdType;
    VfxWString m_guardPwd;
    VfxWString m_newPwd;
    VfxWeakPtr<VappSecSetSimSel> m_simSel;
#endif

    VfxBool popupForNotMatch(
        srv_sim_ctrl_pwd_type_enum pwd_type,
        const VfxWChar *pwd1,
        const VfxWChar *pwd2);

    VfxBool popupForInvalidLength(
        srv_sim_ctrl_pwd_type_enum pwd_type,
        const VfxWChar *guard_pwd,
        const VfxWChar *new_pwd);

#if (MMI_MAX_SIM_NUM >= 2)
    mmi_sim_enum getOneInsertedSim();
    void onSimSelected(VappSecSetSimSel *simSel, VappSecSetSimSel::ResultEnum result);
#endif

    VfxBool operateSim(
        mmi_sim_enum sim,
        srv_sim_ctrl_pwd_type_enum pwdType,
        const VfxWChar *guardPwd,
        const VfxWChar *newPwd);

    static mmi_ret onChangePasswordResult(mmi_event_struct *evt);
    static mmi_ret onUbchvResult(mmi_event_struct *evt);

    void showWaiting(const VfxWString &msg = VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
    void closeWaiting();
    void onPopupConfirmedForDone(VfxObject *obj, VfxId id);

protected:

    virtual void onInit();
    virtual void onDeinit();

public:
    enum ResultEnum
    {
        RESULT_INVALID,
        RESULT_SUCCESS,
        RESULT_FAILED,
        RESULT_CANCEL,

        RESULT_END_OF_ENUM
    };

    typedef enum
    {
       EVT_ID_RESULT,

       EVT_ID_END_OF_ENUM
    } event_enum;

    typedef struct
    {
        MMI_EVT_PARAM_HEADER
        
        VappSecSetSSCChv *sender;
    } result_evt_struct;


private:

    ResultEnum m_result;
    
    void sendResultEvent(ResultEnum result, VfxBool post = VFX_FALSE);
    void displayPopupAndDone(VcpPopupTypeEnum type, const VfxWString &msg, ResultEnum result);

public:

    VappSecSetSSCChv();
    virtual ~VappSecSetSSCChv();

    VfxBool run(
        VfxMainScr *mainScr,
        srv_sim_ctrl_pwd_type_enum pwd_type,
        VfxWChar *parseResult[4],
        mmi_proc_func proc,
        void *userData);
};


VFX_IMPLEMENT_CLASS("VappSecSetSSCChv", VappSecSetSSCChv, VfxObject);

VappSecSetSSCChv::VappSecSetSSCChv() :
        m_mainScr(NULL),
        m_callbackProc(NULL),
        m_callbackUserData(NULL),
        m_waitingInd(NULL),
        m_chvWasBlocked(VFX_FALSE),
        m_result(RESULT_INVALID)
    {
#if (MMI_SIM_TOTAL > 1)
        m_simSel = NULL;
#endif
        #if defined(__DCM_WITH_COMPRESSION_MMI_POOL_B__)
        DCM_Load(DYNAMIC_CODE_COMPRESS_SECSET, 0, 0);
        #endif
    }

VappSecSetSSCChv::~VappSecSetSSCChv()
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_B__)
DCM_Unload(DYNAMIC_CODE_COMPRESS_SECSET);
#endif
}

#pragma arm section code = "DYNAMIC_CODE_SECSET_ROCODE", rodata = "DYNAMIC_CODE_SECSET_RODATA"

void VappSecSetSSCChv::onInit()
{
    VfxObject::onInit();
}


void VappSecSetSSCChv::onDeinit()
{
#if (MMI_SIM_TOTAL > 1)
    if (m_simSel.isValid())
    {
        m_mainScr->closePage(m_simSel->getId());
        m_simSel = NULL;
    }
#endif

    if (m_waitingInd.isValid())
    {
        VFX_OBJ_CLOSE(m_waitingInd);
    }

    VfxObject::onDeinit();
}


VfxBool VappSecSetSSCChv::run(
    VfxMainScr *mainScr,
    srv_sim_ctrl_pwd_type_enum pwdType,
    VfxWChar *parseResult[4],
    mmi_proc_func proc,
    void *userData)
{
    m_mainScr = mainScr;
    m_callbackProc = proc;
    m_callbackUserData = userData;

    if (popupForNotMatch(pwdType, parseResult[2], parseResult[3]))
    {
        return VFX_FALSE;
    }

    if (popupForInvalidLength(pwdType, parseResult[1], parseResult[2]))
    {
        return VFX_FALSE;
    }

    VfxS32 nInsertedSim = srv_sim_ctrl_get_num_of_inserted();
#if (MMI_MAX_SIM_NUM >= 2)
    m_pwdType = pwdType;

    if (nInsertedSim >= 2)
    {
        m_guardPwd.loadFromMem(parseResult[1]);
        m_newPwd.loadFromMem(parseResult[2]);
        VFX_OBJ_CREATE(m_simSel, VappSecSetSimSel, m_mainScr);
        m_simSel->m_signalDone.connect(this, &VappSecSetSSCChv::onSimSelected);
        m_mainScr->pushPage(0, m_simSel.get());
        
        return VFX_TRUE;
    }
#endif
    if (nInsertedSim == 1)
    {
#if (MMI_MAX_SIM_NUM >= 2)
        mmi_sim_enum sim = getOneInsertedSim();
        VFX_ASSERT(sim != MMI_SIM_NONE);
#else
        mmi_sim_enum sim = MMI_SIM1;
#endif
        operateSim(sim, pwdType, parseResult[1], parseResult[2]);
        return VFX_TRUE;
    }

    displayPopupAndDone(
        VCP_POPUP_TYPE_FAILURE,
        VFX_WSTR_RES(STR_GLOBAL_NOT_AVAILABLE),
        RESULT_INVALID);

    return VFX_FALSE;
}


VfxBool VappSecSetSSCChv::operateSim(
    mmi_sim_enum sim,
    srv_sim_ctrl_pwd_type_enum pwdType,
    const VfxWChar *guardPwd,
    const VfxWChar *newPwd)
{
    switch (pwdType)
    {
        case SRV_SIM_CTRL_PWD_TYPE_CHV1:
        case SRV_SIM_CTRL_PWD_TYPE_CHV2:
            if (srv_sim_ctrl_pwd_is_blocked(sim, pwdType))
            {
                displayPopupAndDone(
                    VCP_POPUP_TYPE_FAILURE,
                    getChvStr(sim, pwdType, STR_CHV_BLOCKED),
                    RESULT_FAILED);
                    
                return VFX_FALSE;
            }
            else if (!srv_sim_ctrl_pwd_is_enabled(sim, pwdType))
            {
                displayPopupAndDone(
                    VCP_POPUP_TYPE_FAILURE,
                    getChvStr(sim, pwdType, STR_CHV_DISABLED),
                    RESULT_FAILED);
                    
                return VFX_FALSE;
            }
            else
            {
                if (!srv_sim_ctrl_is_available(sim))
                {
                    displayPopupAndDone(
                        VCP_POPUP_TYPE_FAILURE,
                        VFX_WSTR_RES(STR_GLOBAL_NOT_AVAILABLE),
                        RESULT_FAILED);
                        
                    return VFX_FALSE;
                }

                showWaiting();
                srv_sim_ctrl_change_password(
                    sim,
                    pwdType,
                    guardPwd,
                    newPwd,
                    &VappSecSetSSCChv::onChangePasswordResult,
                    getObjHandle());
            }
            break;

        case SRV_SIM_CTRL_PWD_TYPE_UBCHV1:
        case SRV_SIM_CTRL_PWD_TYPE_UBCHV2:
            if (srv_sim_ctrl_pwd_is_blocked(sim, pwdType))
            {
                displayPopupAndDone(
                    VCP_POPUP_TYPE_FAILURE,
                    getChvStr(sim, pwdType, STR_UBCHV_BLOCKED),
                    RESULT_FAILED);
            
                return VFX_FALSE;
            }
            else
            {
                if (!srv_sim_ctrl_is_available(sim))
                {
                    displayPopupAndDone(
                        VCP_POPUP_TYPE_FAILURE,
                        VFX_WSTR_RES(STR_GLOBAL_NOT_AVAILABLE),
                        RESULT_FAILED);
                        
                    return VFX_FALSE;
                }
                
                // To decide popup "PIN changed" or "PIN unblocked"
                if (pwdType == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
                {
                    m_chvWasBlocked =
                        srv_sim_ctrl_pwd_is_blocked(sim, SRV_SIM_CTRL_PWD_TYPE_CHV1) ? VFX_TRUE : VFX_FALSE;
                }
                else
                {
                    m_chvWasBlocked =
                        srv_sim_ctrl_pwd_is_blocked(sim, SRV_SIM_CTRL_PWD_TYPE_CHV2) ? VFX_TRUE : VFX_FALSE;
                }
            
                showWaiting();
                srv_sim_ctrl_verify_ubchv(
                    sim,
                    pwdType,
                    guardPwd,
                    newPwd,
                    &VappSecSetSSCChv::onUbchvResult,
                    getObjHandle());
            }
            break;

        default:
            VFX_ASSERT(0);
            break;
    }

    return VFX_TRUE;
}


mmi_ret VappSecSetSSCChv::onChangePasswordResult(mmi_event_struct *evt)
{
    srv_sim_ctrl_change_password_result_evt_struct *result_evt =
        reinterpret_cast<srv_sim_ctrl_change_password_result_evt_struct*>(evt);
        
    VappSecSetSSCChv *chvObj;
    VAPP_SECSET_HANDLE_TO_OBJECT(chvObj, VappSecSetSSCChv, result_evt->user_data);

    if (chvObj == NULL)
    {
        return MMI_RET_OK;
    }

    chvObj->closeWaiting();

    if (result_evt->success)
    {
        VfxWString msgStr = getChvStr(result_evt->sim, result_evt->type, STR_CHV_CHANGED);
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_SUCCESS,
            msgStr.getBuf());
    
        chvObj->sendResultEvent(RESULT_SUCCESS);
    }
    else
    {
        if (result_evt->type == SRV_SIM_CTRL_PWD_TYPE_CHV1 &&
            srv_sim_ctrl_get_unavailable_cause(result_evt->sim) == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED)
        {
            // UBCHV1 screen will show
            chvObj->sendResultEvent(RESULT_FAILED);
        }
        else if (result_evt->fail_cause == SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD)
        {
            if (!srv_sim_ctrl_pwd_is_blocked(result_evt->sim, result_evt->type))
            {
                VfxWString prompt =
                    getChvStr(result_evt->sim, result_evt->type, STR_WRONG_CHV);
                VfxS32 nRemainingAttempts = srv_sim_ctrl_get_n_remaining_attempts(result_evt->sim, result_evt->type);
                VfxWString failureMsg = getFailureMsgWithRemaining(prompt, nRemainingAttempts, chvObj);
                chvObj->displayPopupAndDone(VCP_POPUP_TYPE_FAILURE, failureMsg, RESULT_FAILED);
            }
            else
            {
                chvObj->displayPopupAndDone(
                    VCP_POPUP_TYPE_FAILURE,
                    getChvStr(result_evt->sim, result_evt->type, STR_CHV_BLOCKED),
                    RESULT_FAILED);
            }
        }
        else
        {
            VfxWString failureMsg = getSimFailureMessage(result_evt->sim, result_evt->type, result_evt->fail_cause);
            chvObj->displayPopupAndDone(
                VCP_POPUP_TYPE_FAILURE,
                failureMsg,
                RESULT_FAILED);
        }
    }

    return MMI_RET_OK;
}


mmi_ret VappSecSetSSCChv::onUbchvResult(mmi_event_struct *evt)
{
    srv_sim_ctrl_verify_result_evt_struct *result_evt =
        reinterpret_cast<srv_sim_ctrl_verify_result_evt_struct*>(evt);
        
    VappSecSetSSCChv *chvObj;
    VAPP_SECSET_HANDLE_TO_OBJECT(chvObj, VappSecSetSSCChv, result_evt->user_data);

    if (chvObj == NULL)
    {
        return MMI_RET_OK;
    }
    
    chvObj->closeWaiting();

    if (result_evt->success)
    {
        if (chvObj->m_chvWasBlocked)
        {
            VfxWString msgStr = getChvStr(result_evt->sim, result_evt->type, STR_CHV_UNBLOCKED);
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_SUCCESS,
                msgStr.getBuf());
        }
        else
        {
            VfxWString msgStr = getChvStr(result_evt->sim, result_evt->type, STR_CHV_CHANGED);
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_SUCCESS,
                msgStr.getBuf());
        }
    
        chvObj->sendResultEvent(RESULT_SUCCESS);
    }
    else if (result_evt->fail_cause == SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD)
    {
        if (!srv_sim_ctrl_pwd_is_blocked(result_evt->sim, result_evt->type))
        {
            VfxWString prompt =
                getChvStr(result_evt->sim, result_evt->type, STR_WRONG_UBCHV);
            VfxS32 nRemainingAttempts = srv_sim_ctrl_get_n_remaining_attempts(result_evt->sim, result_evt->type);
            VfxWString failureMsg = getFailureMsgWithRemaining(prompt, nRemainingAttempts, chvObj);
            chvObj->displayPopupAndDone(VCP_POPUP_TYPE_FAILURE, failureMsg, RESULT_FAILED);
        }
        else
        {
            chvObj->displayPopupAndDone(
                VCP_POPUP_TYPE_FAILURE,
                getChvStr(result_evt->sim, result_evt->type, STR_UBCHV_BLOCKED),
                RESULT_FAILED);
        }
    }
    else
    {
        VfxWString failureMsg = getSimFailureMessage(result_evt->sim, result_evt->type, result_evt->fail_cause);
        chvObj->displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            failureMsg,
            RESULT_FAILED);
    }
    
    return MMI_RET_OK;
}


VfxBool VappSecSetSSCChv::popupForNotMatch(
    srv_sim_ctrl_pwd_type_enum pwd_type,
    const VfxWChar *pwd1,
    const VfxWChar *pwd2)
{
    if (vfx_sys_wcscmp(pwd1, pwd2) != 0)
    {
        MMI_STR_ID err_msg;

        err_msg = STR_ID_VAPP_SECSET_INVALID_FORMAT;
        if (pwd_type == SRV_SIM_CTRL_PWD_TYPE_CHV1 || pwd_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
        {
            err_msg = STR_ID_VAPP_SECSET_CHV1_NOT_MATCH;
        }
        else if (pwd_type == SRV_SIM_CTRL_PWD_TYPE_CHV2 || pwd_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV2)
        {
            err_msg = STR_ID_VAPP_SECSET_CHV2_NOT_MATCH;
        }

        displayPopupAndDone(VCP_POPUP_TYPE_FAILURE, VFX_WSTR_RES(err_msg), RESULT_INVALID);

        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VappSecSetSSCChv::popupForInvalidLength(
    srv_sim_ctrl_pwd_type_enum pwd_type,
    const VfxWChar *guard_pwd,
    const VfxWChar *new_pwd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 guard_pwd_len;
    S32 new_pwd_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guard_pwd_len = vfx_sys_wcslen(guard_pwd);
    new_pwd_len = vfx_sys_wcslen(new_pwd);

    if (guard_pwd_len == 0 || new_pwd_len == 0)
    {
        displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            VFX_WSTR_RES(STR_ID_VAPP_SECSET_INVALID_LENGTH),
            RESULT_INVALID);
        
        return VFX_TRUE;
    }

    switch (pwd_type)
    {
        case SRV_SIM_CTRL_PWD_TYPE_CHV1:
        case SRV_SIM_CTRL_PWD_TYPE_CHV2:
            if (guard_pwd_len < SRV_SIM_CTRL_MIN_CHV_LEN || SRV_SIM_CTRL_MAX_CHV_LEN < guard_pwd_len ||
                new_pwd_len < SRV_SIM_CTRL_MIN_CHV_LEN || SRV_SIM_CTRL_MAX_CHV_LEN < new_pwd_len)
            {
                displayPopupAndDone(
                    VCP_POPUP_TYPE_FAILURE,
                    VFX_WSTR_RES(STR_ID_VAPP_SECSET_INVALID_LENGTH),
                    RESULT_INVALID);
                    
                return VFX_TRUE;
            }
            break;

        case SRV_SIM_CTRL_PWD_TYPE_UBCHV1:
        case SRV_SIM_CTRL_PWD_TYPE_UBCHV2:
            if (guard_pwd_len < SRV_SIM_CTRL_MIN_UBCHV_LEN || SRV_SIM_CTRL_MAX_UBCHV_LEN < guard_pwd_len ||
                new_pwd_len < SRV_SIM_CTRL_MIN_CHV_LEN || SRV_SIM_CTRL_MAX_CHV_LEN < new_pwd_len)
            {
                displayPopupAndDone(
                    VCP_POPUP_TYPE_FAILURE,
                    VFX_WSTR_RES(STR_ID_VAPP_SECSET_INVALID_LENGTH),
                    RESULT_INVALID);
            
                return VFX_TRUE;
            }
            break;
    }

    return VFX_FALSE;
}


#if (MMI_MAX_SIM_NUM >= 2)
mmi_sim_enum VappSecSetSSCChv::getOneInsertedSim()
{
    for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim = srv_sim_ctrl_get_sim_by_index(i);
        if (srv_sim_ctrl_is_inserted(sim))
        {
            return sim;
        }
    }

    return MMI_SIM_NONE;
}


void VappSecSetSSCChv::onSimSelected(
    VappSecSetSimSel *simSel,
    VappSecSetSimSel::ResultEnum result)
{
    switch (result)
    {
        case VappSecSetSimSel::RESULT_SIM_SELECTED:
            operateSim(
                simSel->getSimSelected(),
                m_pwdType,
                m_guardPwd.getBuf(),
                m_newPwd.getBuf());
            break;

        case VappSecSetSimSel::RESULT_BACK_SELECTED:
            sendResultEvent(RESULT_CANCEL);
            break;

        default:
            VFX_ASSERT(0);
            break;
    }
}

#endif /* (MMI_MAX_SIM_NUM >= 2) */


void VappSecSetSSCChv::sendResultEvent(ResultEnum result, VfxBool post)
{
    if (m_callbackProc != NULL)
    {
        result_evt_struct result_evt;
        
        MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_RESULT);
        result_evt.sender = this;

        if (post)
        {
            MMI_FRM_POST_EVENT(&result_evt, m_callbackProc, m_callbackUserData);
        }
        else
        {
            MMI_FRM_SEND_EVENT(&result_evt, m_callbackProc, m_callbackUserData);
        }
    }
}


void VappSecSetSSCChv::showWaiting(const VfxWString &msg)
{
    if (!m_waitingInd.isValid())
    {
        VFX_OBJ_CREATE(m_waitingInd, VcpIndicatorPopup, m_mainScr);
        m_waitingInd->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_waitingInd->setText(msg);
        m_waitingInd->show(VFX_TRUE);
    }
    else
    {
        m_waitingInd->bringToFront();
    }
}


void VappSecSetSSCChv::closeWaiting()
{
    if (m_waitingInd.isValid())
    {
        m_waitingInd->exit(VFX_TRUE);
        m_waitingInd = NULL;
    }
}


void VappSecSetSSCChv::displayPopupAndDone(VcpPopupTypeEnum type, const VfxWString &msg, ResultEnum result)
{
    m_result = result;

    VcpConfirmPopup *confirmPopup;
    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, m_mainScr);
    confirmPopup->setInfoType(type);
    confirmPopup->setText(msg);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    confirmPopup->setAutoDestory(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VappSecSetSSCChv::onPopupConfirmedForDone);
    confirmPopup->show(VFX_TRUE);
}


void VappSecSetSSCChv::onPopupConfirmedForDone(VfxObject *obj, VfxId id)
{
    sendResultEvent(m_result, VFX_FALSE);
}
#pragma arm section code, rodata


typedef struct
{
    VfxWeakPtr<VappSecSetSSCChv> oper_obj;
} vapp_secset_ssc_cntx_struct;


static vapp_secset_ssc_cntx_struct g_vapp_secset_ssc_cntx;


static inline VfxBool vapp_secset_is_digit(const VfxWChar ch)
{
    return (L'0' <= ch && ch <= L'9');
}


/*****************************************************************************
 * FUNCTION
 *  vapp_secset_ssc_parse_chv
 * DESCRIPTION
 *  L"**04*1234*5678*9012#" =>
 *  result_strs[0] = L"04"
 *  result_strs[1] = L"1234"
 *  result_strs[2] = L"5678"
 *  result_strs[3] = L"9012"
 * PARAMETERS
 *  input_buffer    [IN/OUT] String to be parsed, will be modified
 *  result_strs     [OUT] Result of parsing
 * RETURNS
 *  Valid format
 *****************************************************************************/
static VfxBool vapp_secset_ssc_parse_chv(
                    VfxWChar *input_buffer,
                    VfxWChar *result_strs[4])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    VfxWChar *ch_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!(input_buffer[0] == L'*' && (input_buffer[1] == L'*')))
    {
        return VFX_FALSE;
    }

    ch_p = &(input_buffer[2]);
    for (i = 0; i < 3; i++)
    {
        result_strs[i] = ch_p;
        while (vapp_secset_is_digit(*ch_p))
        {
            ch_p++;
        }
        if (*ch_p != L'*')
        {
            return VFX_FALSE;
        }
        if (ch_p == result_strs[i])
        {
            /* Empty segment */
            return VFX_FALSE;
        }
        *ch_p = L'\0';
        
        ch_p++;
    }

    result_strs[3] = ch_p;
    while (vapp_secset_is_digit(*ch_p))
    {
        ch_p++;
    }
    if (*ch_p != L'#')
    {
        return VFX_FALSE;
    }
    if (ch_p == result_strs[3])
    {
        /* Empty segment */
        return VFX_FALSE;
    }
    *ch_p = L'\0';

    return VFX_TRUE;
}


mmi_ret vapp_secset_ssc_chv_on_result(mmi_event_struct *evt)
{
    vapp_secset_ssc_cntx_struct *cntx =
        reinterpret_cast<vapp_secset_ssc_cntx_struct*>(evt->user_data);

    if (cntx->oper_obj.isValid())
    {
        VFX_OBJ_CLOSE(cntx->oper_obj);
        cntx->oper_obj = NULL;
    }

    return MMI_RET_OK;
}


VfxBool vapp_secset_ssc_process(const VfxWChar *ssc, VfxMainScr *mainScr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxBool accept;
    VfxS32 sscLen;
    VfxWChar *sscCopy;
    VfxWChar *parseResult[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    accept = VFX_FALSE;

    sscLen = vfx_sys_wcslen(ssc);
    VFX_ALLOC_MEM(sscCopy, (sscLen + 3) * sizeof(VfxWChar), mainScr);
    vfx_sys_wcscpy(sscCopy, ssc);

    if (vapp_secset_ssc_parse_chv(sscCopy, parseResult))
    {
        srv_sim_ctrl_pwd_type_enum pwdType = SRV_SIM_CTRL_PWD_TYPE_NONE;
    
        if (vfx_sys_wcscmp(parseResult[0], (const VfxWChar*)L"04") == 0)
        {
            pwdType = SRV_SIM_CTRL_PWD_TYPE_CHV1;
            accept = VFX_TRUE;
        }
        else if (vfx_sys_wcscmp(parseResult[0], (const VfxWChar*)L"042") == 0)
        {
            pwdType = SRV_SIM_CTRL_PWD_TYPE_CHV2;
            accept = VFX_TRUE;
        }
        else if (vfx_sys_wcscmp(parseResult[0], (const VfxWChar*)L"05") == 0)
        {
            pwdType = SRV_SIM_CTRL_PWD_TYPE_UBCHV1;
            accept = VFX_TRUE;
        }
        else if (vfx_sys_wcscmp(parseResult[0], (const VfxWChar*)L"052") == 0)
        {
            pwdType = SRV_SIM_CTRL_PWD_TYPE_UBCHV2;
            accept = VFX_TRUE;
        }

        if (accept)
        {
            VappSecSetSSCChv *chvObj;
            
            VFX_OBJ_CREATE(chvObj, VappSecSetSSCChv, mainScr);
            g_vapp_secset_ssc_cntx.oper_obj = chvObj;
            
            chvObj->run(
                mainScr,
                pwdType,
                parseResult,
                vapp_secset_ssc_chv_on_result,
                &g_vapp_secset_ssc_cntx);
        }
    }

    VFX_FREE_MEM(sscCopy);
    
    return accept;
}


extern "C"
MMI_BOOL mmi_secset_ssc_process(const CHAR *input_in_ucs2)
{
    return MMI_FALSE;
}

