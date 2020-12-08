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
 *  vapp_dtcnt_prov_adp.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This adp file is used to implement for data account provisioning
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __TCPIP__
//#ifdef __CCA_SUPPORT__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vapp_dtcnt.h"
#include "vapp_dtcnt_prov_adp.h"
#include "vapp_dtcnt_prov.h"
#include "mmi_rp_vapp_dtcnt_prov_def.h"
#include "GlobalResDef.h"

// cca header file
#include "vapp_cca_gprot.h"


extern "C"
{
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
}


/***************************************************************************** 
 * Variable
 *****************************************************************************/
#ifdef __COSMOS_DTCNT_CCA_SUPPORT__

mmi_id cuiId;


/***************************************************************************** 
 * Function
 *****************************************************************************/

// internal use
mmi_id vappDtcntProvCuiCreate(mmi_id parentId, srv_dtcnt_prov_ind_evt_struct *arg)
{
    mmi_id cuiId = VfxAppLauncher::createCui(
                                        VAPP_DTCNT_PROV,
                                        VFX_OBJ_CLASS_INFO(VappDtcntProvCui),
                                        parentId,
                                        arg,
                                        sizeof(srv_dtcnt_prov_ind_evt_struct));
    return cuiId;
}

void vappDtcntProvCuiRun(mmi_id cuiId)
{
    VfxAppLauncher::runCui(cuiId);
}


void vappDtcntProvCuiClose(mmi_id cuiId)
{
    VfxAppLauncher::terminate(cuiId);
}


void vappDtcntProvIndHdlr(mmi_event_struct *param)
{
    srv_dtcnt_prov_ind_evt_struct *provIndEvt;
    provIndEvt = (srv_dtcnt_prov_ind_evt_struct *)param;
    mmi_id ccaId = GRP_ID_ROOT;
    ccaId = vapp_cca_get_parent_id();

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_PROV_IND_HDLR, ccaId, provIndEvt->prov_ind);

    if (provIndEvt->prov_ind == SRV_DTCNT_PROV_IND_CSD || provIndEvt->prov_ind == SRV_DTCNT_PROV_IND_GPRS)
    {
        // create CUI
        cuiId = vappDtcntProvCuiCreate(ccaId, provIndEvt);
        vappDtcntProvCuiRun(cuiId);
    }
}


void vappDtcntProvInstallOneDone(mmi_event_struct *param)
{
    srv_dtcnt_prov_install_res_ind_evt_struct *provInd;    
    provInd = (srv_dtcnt_prov_install_res_ind_evt_struct *)param;
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_PROV_INSTALL_ONE_DONE, provInd->install_result, provInd->prov_ind);

    if (!provInd->install_result)
    {
        return;
    }

    VfxU32 i = 0;
    VfxBool replace = VFX_FALSE;
    VappDtcntDispItem* dispItem;
    if (provInd->prov_ind == SRV_DTCNT_PROV_IND_CSD || provInd->prov_ind == SRV_DTCNT_PROV_IND_GPRS)
    {
        for (i = 0; i < VappDtcntDispItemList::getAcctNum(); i++)
        {
            dispItem = VappDtcntDispItemList::getAccountItem(i);
            if (dispItem->getProfileId()== provInd->acct_id)
            {
                replace = VFX_TRUE;
                break;
            }
        }

        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_PROV_INSTALL_ONE_DONE_REPLACE, replace);

        VfxU8 bearer = DATA_ACCOUNT_BEARER_GPRS;
        if (provInd->prov_ind == SRV_DTCNT_PROV_IND_CSD)
        {
            bearer = DATA_ACCOUNT_BEARER_CSD;
        }
        
        srv_dtcnt_sim_type_enum simInfo;
        srv_dtcnt_get_sim_info(provInd->acct_id, &simInfo);
        
        srv_dtcnt_connection_type_enum connType = SRV_DTCNT_CONN_TYPE_HTTP;
        srv_dtcnt_get_connection_type(provInd->acct_id, &connType);
        
        VfxU8 readOnly = 0;
        if (srv_dtcnt_acct_is_read_only(provInd->acct_id))
        {
            readOnly = 1;
        }

	VappDtcntDispItem acctItem(provInd->acct_id, (VfxU8)connType, (VfxU8)simInfo, 
					bearer, readOnly, provInd->prof_type);
	MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_UPDATE_PROFILE, provInd->acct_id, replace);
        if (replace)
        {
              VappDtcntDispItemList::updateAcctItem(acctItem);
        }
        else
        {
            VappDtcntDispItemList::addAcctItem(acctItem);
        }
    }
}


static mmi_ret vappDtcntProvCallbackHandler(mmi_event_struct* param)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_EVENT_ID, param->evt_id);

    switch (param->evt_id)
    {
    case EVT_ID_SRV_DTCNT_PROV_IND:
        vappDtcntProvIndHdlr(param);
        break;
    case EVT_ID_SRV_DTCNT_PROV_INSTALL_RES_IND:
        vappDtcntProvInstallOneDone(param);
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}


// register event of provisioning from data account srv
mmi_ret vappDtcntProvRegEvent(void *userData)
{
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_PROV_IND, vappDtcntProvCallbackHandler, userData);
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_PROV_INSTALL_RES_IND, vappDtcntProvCallbackHandler, userData);
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_PROV_DONE_IND, vappDtcntProvCallbackHandler, userData);
    return MMI_RET_OK;
}

#endif /*__CCA_SUPPORT__ */

#endif /* __TCPIP__ */

