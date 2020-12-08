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
 *  vapp_dialer_core.cpp
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "vcp_global_popup.h"
#include "vapp_dialer_core.h"
#include "vapp_dialer_cui.h"
#include "vapp_dialer_main.h"
#include "vcui_language_setting_gprot.h"
#include "vcui_phb_gprot.h"
#include "vapp_dialer_gprot.h"
#include "vapp_secset_gprot.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "UCMGprot.h"
#include "SSCStringHandle.h"
#include "IdleAppDef.h"
#include "AlertScreen.h"
#include "mmi_rp_cui_dialer_def.h"
#include "GeneralSettingSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "mmi_frm_utility_gprot.h"

#ifdef __cplusplus
}
#endif

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
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class IDialerOperation
 *****************************************************************************/
srv_ucm_call_type_enum IDialerOperation::getDialType(DialerCallTypeEnum type)
{
    switch (type)
    {
        case SIM1_CALL:
            return SRV_UCM_VOICE_CALL_TYPE;
    #if (MMI_MAX_SIM_NUM >= 2)
        case SIM2_CALL:
            return SRV_UCM_VOICE_CALL_TYPE_SIM2;
    #if (MMI_MAX_SIM_NUM >= 3)
        case SIM3_CALL:
            return SRV_UCM_VOICE_CALL_TYPE_SIM3;
    #if (MMI_MAX_SIM_NUM >= 4)
        case SIM4_CALL:
            return SRV_UCM_VOICE_CALL_TYPE_SIM4;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
    #ifdef __MMI_VIDEO_TELEPHONY__
        case VIDEO_CALL:
            return SRV_UCM_VIDEO_CALL_TYPE;
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        default:
            return SRV_UCM_VOICE_CALL_TYPE;
    }
}


void IDialerOperation::setDialerPreferSIM(DialerCallTypeEnum type)
{
    mmi_sim_enum sim;

    switch (type)
    {
        case SIM1_CALL:
    #if (MMI_MAX_SIM_NUM >= 2)
        case SIM2_CALL:
    #if (MMI_MAX_SIM_NUM >= 3)
        case SIM3_CALL:
    #if (MMI_MAX_SIM_NUM >= 4)
        case SIM4_CALL:
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
            sim = (mmi_sim_enum) type;
            break;
    #ifdef __MMI_VIDEO_TELEPHONY__
        case VIDEO_CALL:
            sim = MMI_SIM1;
            break;
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        default:
            sim = MMI_SIM_NONE;
            break;
    }

    if (sim != MMI_SIM_NONE)
    {
        VfxU8 value;
        VfxS16 error;
        value = sim;
        WriteValue(NVRAM_DIALER_PREFER_SIM, &value, DS_BYTE, &error);
    }
}


/***************************************************************************** 
 * Class DialerOperationClassic
 *****************************************************************************/
void DialerOperationClassic::makeCall(VfxWChar *str, DialerCallTypeEnum type)
{
    mmi_ucm_make_call_para_struct param;
    mmi_ucm_init_call_para(&param);
    param.dial_type                         = getDialType(type);
    param.ucs2_num_uri                      = (PU16)str;
    param.adv_para.phb_data                 = NULL;
    param.adv_para.after_make_call_callback = DialerOperationClassic::dialCallback;
    param.adv_para.after_callback_user_data = (void*)(U32)type;
    mmi_ucm_call_launch(mmi_frm_group_get_active_id(), &param);
}


void DialerOperationClassic::dialCallback(mmi_ucm_after_make_call_cb_struct* para)
{
    if (para->result == SRV_UCM_RESULT_OK)
    {
        setDialerPreferSIM((DialerCallTypeEnum)(U32)para->user_data);
    }
}


VfxBool DialerOperationClassic::languageSwitch(VfxWChar *str)
{
    VfxBool ret;

    VfxApp *old_app = VfxAppLauncher::findApp(
                    VAPP_DIALER,
                    VFX_OBJ_CLASS_INFO(VappDialerCalllogContactApp),
                    VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
    if (old_app)
    {
        ret = VFX_FALSE;
    }
    else
    {
        ret = mmi_ssc_lauguage_string_pass_ex(str, m_scr) ? VFX_TRUE : VFX_FALSE;
    }

    return ret;
}


void DialerOperationClassic::onSendKey(VfxWChar *str, mmi_sim_enum sim)
{
    if (languageSwitch(str))
    {
        return;
    }
    else
    {
        if (sim == MMI_SIM1 || sim == MMI_SIM2 || sim == MMI_SIM3 || sim == MMI_SIM4)
        {
            makeCall(str, (DialerCallTypeEnum) sim);
        }
        else
        {
            sim = (mmi_sim_enum) srv_sim_ctrl_get_one_available_sim();
            if (sim == MMI_SIM1 || sim == MMI_SIM2 || sim == MMI_SIM3 || sim == MMI_SIM4)
            {
                makeCall(str, (DialerCallTypeEnum) sim);
            }
            else
            {
                makeCall(str, SIM1_CALL);
            }
        }
    }

    VfxApp *old_app = VfxAppLauncher::findApp(
                    VAPP_DIALER,
                    VFX_OBJ_CLASS_INFO(VappDialerCalllogContactApp),
                    VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
    if (old_app)
    {
        VfxAppLauncher::terminate(old_app->getGroupId());
    }
}


void DialerOperationClassic::onCallBtn(DialerCallTypeEnum type, VfxWChar *str)
{
    if (languageSwitch(str))
    {
        return;
    }
    else
    {
        makeCall(str, type);
    }
}


void DialerOperationClassic::onPoundBtn(VfxWChar *str)
{
    if (mmi_ssc_phone_string_pass_ex((WCHAR *)str, m_scr))
    {
        return;
    }
    else if (mmi_ssc_sim_string_pass_ex((WCHAR *)str, m_scr))
    {
        return;
    }
    else
    {
        VfxS32 index, length;
        if (mmi_ucs2toi((CHAR *)str, &index, &length) > 0 && length <= 3 && (length = mmi_ucs2strlen((CHAR *)str) - 1) <= 3)
        {
            for (VfxS32 i = 0; i < length; i++)
            {
                if (str[i] < L'0' || str[i] > L'9')
                {
                    return;
                }
            }

            mmi_id cui_id = vcui_phb_sim_locator_create(m_scr->getApp()->getGroupId(), (U16) index);
            if (cui_id == GRP_ID_INVALID)
            {
                return;
            }

            vfxSetCuiCallerScr(cui_id, m_scr);
            vcui_phb_sim_locator_run(cui_id);
        }
    }
}


void DialerOperationClassic::onSaveToContactBtn(VfxWChar *str)
{
    mmi_id cui_id = vcui_phb_contact_saver_create(m_scr->getApp()->getGroupId());
    if (cui_id == GRP_ID_INVALID)
    {
        return;
    }

    vfxSetCuiCallerScr(cui_id, m_scr);
    vcui_phb_contact_saver_set_number(cui_id, str, mmi_wcslen(str));
    vcui_phb_contact_saver_run(cui_id);
}


/***************************************************************************** 
 * Class DialerOperationCUI
 *****************************************************************************/
void DialerOperationCUI::onCallBtn(DialerCallTypeEnum type, VfxWChar * str)
{
    VappDialerCUI *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(m_scr->getApp()->getGroupId()) ,VappDialerCUI);
    VFX_ASSERT(obj != NULL);

    srv_ucm_call_type_enum dialType = getDialType(type);
    setDialerPreferSIM(type);
    mmi_ucm_make_call_para_struct param;
    mmi_ucm_init_call_para(&param);
    param.dial_type                         = dialType;
    param.ucs2_num_uri                      = (PU16)str;
    param.adv_para.phb_data                 = obj->getPhbData();
    param.adv_para.after_make_call_callback = VappDialerCUI::dialCallback;
    param.adv_para.after_callback_user_data = obj->getObjHandle();
    mmi_ucm_call_launch(mmi_frm_group_get_active_id(), &param);
}


void DialerOperationCUI::onSendKey(VfxWChar *str, mmi_sim_enum sim)
{
    if (sim == MMI_SIM1 || sim == MMI_SIM2 || sim == MMI_SIM3 || sim == MMI_SIM4)
    {
        onCallBtn((DialerCallTypeEnum) sim, str);
    }
    else if (sim == MMI_SIM_END_OF_ENUM)
    {
        for (VfxU32 i = 0; i < MMI_SIM_TOTAL; i++)
        {
            mmi_sim_enum sim = mmi_frm_index_to_sim(i);
            if (srv_sim_ctrl_is_in_verifying(sim))
            {
                onCallBtn((DialerCallTypeEnum) sim, str);
                return;
            }
        }

        onCallBtn(SIM1_CALL, str);
    }
    else
    {
        sim = (mmi_sim_enum) srv_sim_ctrl_get_one_available_sim();
        if (sim == MMI_SIM1 || sim == MMI_SIM2 || sim == MMI_SIM3 || sim == MMI_SIM4)
        {
            onCallBtn((DialerCallTypeEnum) sim, str);
        }
        else
        {
            onCallBtn(SIM1_CALL, str);
        }
    }
}


extern "C"
{
void vcp_dialer_popup(WCHAR *str)
{
    vcp_global_popup_show_confirm_one_button_str(
        GRP_ID_ROOT,
        VCP_POPUP_TYPE_INFO,
        VfxWString().loadFromMem(str),
        VfxWString().loadFromRes(STR_GLOBAL_CANCEL),
        VCP_POPUP_BUTTON_TYPE_CANCEL,
        NULL,
        NULL);
}


void vcp_dialer_imei_pupup(WCHAR *str, void *scr)
{
    vcp_global_popup_show_confirm_one_button_str(
        GRP_ID_ROOT,
        VCP_POPUP_TYPE_INFO,
        VfxWString().loadFromMem(str),
        VfxWString().loadFromRes(STR_GLOBAL_OK),
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        NULL,
        NULL);
}


#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
void vapp_dialer_language_switch(void* scr, U8* language_SSC)
{
    VfxMainScr *screen = (VfxMainScr *)scr;
    mmi_id cui_id = cui_language_setting_create(screen->getApp()->getGroupId(), language_SSC);
    if (cui_id == 0)
    {
        return;
    }

    vfxSetCuiCallerScr(cui_id, screen);
    cui_language_setting_run(cui_id);
}
#else
void vapp_dialer_language_switch(void* scr, U8 language_id)
{
    VfxMainScr *screen = (VfxMainScr *)scr;
    mmi_id cui_id = cui_language_setting_create(screen->getApp()->getGroupId(), language_id);
    if (cui_id == 0)
    {
        return;
    }

    vfxSetCuiCallerScr(cui_id, screen);
    cui_language_setting_run(cui_id);
}
#endif


MMI_BOOL mmi_dialer_ssc_process_chv(WCHAR *str, void *screen)
{
    return (MMI_BOOL)vapp_secset_ssc_process((VfxWChar *)str, (VfxMainScr *)screen);
}

}

