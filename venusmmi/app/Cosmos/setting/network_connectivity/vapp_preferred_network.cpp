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
 *  Vapp_preferred_network.cpp
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
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_preferred_network.h"
#include "mmi_rp_vapp_setting_def.h"
#include "mmi_rp_vcui_mobile_nw_setting_def.h"

extern "C"
{
#include "PlmnEnum.h"
#include "app_plmn.h"
#include "GlobalResDef.h"
#include "Sim_common_enums.h"
#include "ImeGprotEnums.h"
#include "App_str.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_PREF_NETWORK_ADD_BTN    (0)
#define VAPP_PREF_NETWORK_CHANGE_BTN (1)
#define VAPP_PREF_NETWORK_DELETE_BTN (2)

#define VAPP_PREF_NETWORK_DEL_OK_BTN (0)
#define VAPP_PREF_NETWORK_DEL_CANCEL_BTN (1)

void clearPlmnNodes(VappSettingPlmnList* plmnList)
{
    if (plmnList)
    {
        plmnList->reset();
        VappSettingPlmnNodeBase *node = plmnList->getCurrentNode();
        while (node)
        {
            plmnList->deleteNode(node);
            VFX_OBJ_CLOSE(node);
            node = plmnList->getCurrentNode();
        }
    }
}
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
VfxBool VappPreferredNwSettingParser::m_abortUpdateList = VFX_FALSE;
VfxBool VappPreferredNwSettingController::m_abortBeforeClosed = VFX_FALSE;
/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappPreferredPlmnNode
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPreferredNwPlmnNode", VappPreferredNwPlmnNode, VappSettingPlmnNodeBase);
VappPreferredNwPlmnNode::VappPreferredNwPlmnNode(const CHAR* plmn, srv_netset_rat_mode_enum rat, VfxU16 priority)
{
    memset(m_plmn, 0, (MAX_PLMN_LEN + 1));
    memcpy(m_plmn, plmn, (MAX_PLMN_LEN + 1));
    m_rat = rat;
    m_priority = priority;
}

/***************************************************************************** 
 * VappPreferredNwSettingParser
 *****************************************************************************/
void VappPreferredNwSettingParser::updateList(mmi_sim_enum sim)
{
    ASSERT(sim != MMI_SIM_NONE && sim != MMI_SIM_END_OF_ENUM);
    m_abortUpdateList = VFX_FALSE;
    srv_netset_get_pref_list(sim, &VappPreferredNwSettingParser::updateListProc, getObjHandle());
}

mmi_ret VappPreferredNwSettingParser::updateListProc(mmi_event_struct *evt)
{
    srv_netset_rsp_event_struct *rspEvt = (srv_netset_rsp_event_struct*)evt;
    VappPreferredNwSettingParser *parser = (VappPreferredNwSettingParser*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
    if (VappPreferredNwSettingParser::m_abortUpdateList)
	{
	    // Do not update the list
	    return MMI_RET_OK;
	}
    if (parser && evt->evt_id == EVT_ID_SRV_NETSET_GET_PREF_LIST_RSP)
	{
        if (rspEvt->result == SRV_NETSET_RSP_RESULT_SUCCESS)
    	{    	
    	    parser->prepareList(rspEvt->rsp_data.get_pref_list_rsp_data);
    	}
        else
        {
            parser->m_signalListReady.emit(VAPP_PREF_NW_PROGRESS_FAILED, VAPP_PREFERRED_NW_GET_LIST);
        }
	}
    return MMI_RET_OK;
}

void VappPreferredNwSettingParser::prepareList(mmi_smu_get_preferred_oper_list_rsp_struct *data)
{
    if (!data->result || data->retnum == 0)
	{
	    m_signalListReady.emit(VAPP_PREF_NW_PROGRESS_FAILED, VAPP_PREFERRED_NW_GET_LIST);
        return;
	}
    m_simFileType = data->file_idx_rsp;
    
    VFX_OBJ_CREATE(m_list, VappSettingPlmnList, this);
    
    VfxU16 i = 0;
    for (i = 0; i < data->retnum; i++)
	{
        if ((data->oper_list[i * (MAX_PLMN_LEN + 1)] == 0X3F) 
            || (data->oper_list[i * (MAX_PLMN_LEN + 1)] == 0X00))
        {
            continue;
        }

        srv_netset_rat_mode_enum rat;
        if ((data->rat_list[i * 2] & 0x80) == 0x80 &&
            (data->rat_list[i * 2 + 1] & 0x80) == 0x00)
        {
            rat = SRV_NETSET_RAT_UMTS;
        }
        else if ((data->rat_list[i * 2] & 0x80) == 0x00 &&
            (data->rat_list[i * 2 + 1] & 0x80) == 0x80)
        {
            rat = SRV_NETSET_RAT_GSM;
        }
        else if ((data->rat_list[i * 2] & 0x80) == 0x80 &&
            (data->rat_list[i * 2 + 1] & 0x80) == 0x80)
        {
            rat = SRV_NETSET_RAT_UMTS;
        }
        else
        {
            rat = SRV_NETSET_RAT_NONE;
        }

        VappPreferredNwPlmnNode *node;
        VFX_OBJ_CREATE_EX(node, VappPreferredNwPlmnNode, this, ((const CHAR*)&data->oper_list[i * 7], rat, i));
        m_list->appendNode(node);
	}
    m_signalListReady.emit(VAPP_PREF_NW_PROGRESS_DONE, VAPP_PREFERRED_NW_GET_LIST);    
}

/***************************************************************************** 
 * VappPreferredNwSettingProvider
 *****************************************************************************/
VappPreferredNwSettingProvider::VappPreferredNwSettingProvider() : m_list(NULL)
{
    m_systemListCount = srv_netset_get_system_plmn_number();
}

VappPreferredNwSettingProvider::~VappPreferredNwSettingProvider()
{
    m_list = NULL;
}
VfxWString VappPreferredNwSettingProvider::getSimPlmn(VfxId plmnId)
{
    ASSERT(m_list);
    VappSettingPlmnNodeBase *node = (VappSettingPlmnNodeBase*)m_list->getNode(plmnId);
    if (!node)
    {
 	return VFX_WSTR_EMPTY;
    }
    VfxWString ret = VFX_WSTR_EMPTY;
    ret.format("%s", node->getPlmn());
    return ret;
}
VfxWString VappPreferredNwSettingProvider::getSimPlmnName(VfxId plmnId)
{
    ASSERT(m_list);
    VappSettingPlmnNodeBase *node = (VappSettingPlmnNodeBase*)m_list->getNode(plmnId);
    if (!node)
    {
	return VFX_WSTR_EMPTY;
    }
    return node->getOperatorName();
}

VfxWString VappPreferredNwSettingProvider::getSimPlmnRat(VfxId plmnId)
{
    ASSERT(m_list);
    VappSettingPlmnNodeBase *node = (VappSettingPlmnNodeBase*)m_list->getNode(plmnId);
    return node->getRatString();
}

VfxU16 VappPreferredNwSettingProvider::getSimPlmnCount()
{
    if (m_list)
	{
        return (VfxU16)m_list->getCount();
	}
	else
	{
		return 0;
	}
}

void VappPreferredNwSettingProvider::getSystemPlmn(VfxId plmnId, CHAR *buffer)
{
    ASSERT(plmnId <= getSystemPlmnCount() && buffer);
    memset(buffer, 0, (MAX_PLMN_LEN + 1));
    srv_netset_get_sys_plmn_mccmnc(plmnId, buffer, (MAX_PLMN_LEN + 1));
//    applib_plmn_convert_bcd_2_string((VfxU8*)&(m_systemList[plmnId].plmn_bcd), sizeof(m_systemList[plmnId].plmn_bcd) , buffer, (MAX_PLMN_LEN + 1));
}

VfxWString VappPreferredNwSettingProvider::getSystemPlmnString(VfxId plmnId)
{
    CHAR buffer[MAX_PLMN_LEN + 1];
    getSystemPlmn(plmnId, buffer);

    VfxWString ret = VFX_WSTR_EMPTY;
    ret.format("%s", buffer);
    return ret;
}
VfxWString VappPreferredNwSettingProvider::getSystemPlmnName(VfxId plmnId)
{
    ASSERT(plmnId <= getSystemPlmnCount());
    VfxWChar buffer[20];
    memset(buffer, 0, 20 * sizeof(VfxWChar));
    srv_netset_get_sys_plmn_opname(plmnId, buffer, 20);
    return VFX_WSTR_MEM(buffer);
}

/***************************************************************************** 
 * VappPreferredNwSettingController
 *****************************************************************************/
void VappPreferredNwSettingController::addToSimList(mmi_sim_enum sim, VappSettingPlmnList *list, VfxU16 startIndex)
{
    ASSERT(sim != MMI_SIM_NONE && list);
    m_opSim = sim;
    m_opList = list;
    m_startIndex = startIndex;
    m_opIndex = 0;
    m_operation = VAPP_PREFERRED_NW_ADD_TO_LIST;
    m_abortOp = VFX_FALSE;
    m_signalPostOp.connect(this, &VappPreferredNwSettingController::processInt);
    processInt();
}
void VappPreferredNwSettingController::deleteFromSimList(mmi_sim_enum sim,VappSettingPlmnList *list)
{
    ASSERT(sim != MMI_SIM_NONE && list);
    m_opSim = sim;
    m_opList = list;
    m_opIndex = 0;
    m_operation = VAPP_PREFERRED_NW_DELETE_FROM_LIST;
    m_abortOp = VFX_FALSE;
    m_signalPostOp.connect(this, &VappPreferredNwSettingController::processInt);
	processInt();
}

void VappPreferredNwSettingController::processInt()
{
    if (m_abortOp)
	{
            deinitList();
	    m_signalOpProgress.emit(VAPP_PREF_NW_PROGRESS_DONE, VAPP_PREFERRED_NW_ABORT_OPERATION);
	    return;
	}
    if (m_opIndex < m_opList->getCount())
	{
        mmi_smu_set_preferred_oper_list_req_struct reqData;
        mmi_smu_set_preferred_oper_list_req_struct *addData, *delData;
        addData = delData = NULL;
        
	    VappSettingPlmnNodeBase *node = (VappSettingPlmnNodeBase*)m_opList->getNode(m_opIndex);
        memcpy(reqData.oper, node->getPlmn(), (MAX_PLMN_LEN + 1));
        reqData.rat = (VfxU8)node->getRat();
        switch (m_operation)
    	{
    	case VAPP_PREFERRED_NW_ADD_TO_LIST:
            reqData.index = m_startIndex + m_opIndex;   
            addData = &reqData;
    		break;
        case VAPP_PREFERRED_NW_DELETE_FROM_LIST:
	{
    	    VappPreferredNwPlmnNode *prefNwNode = (VappPreferredNwPlmnNode*)node;
            // Adjust the index, for every delete operation, 
            // the priority of PLMN after the deleted one will decrease one in the L4
            reqData.index = prefNwNode->getPriority() - m_opIndex;             
            delData = &reqData;
	    break;
	}
    	default:
            break;    		
    	}
  		srv_netset_set_pref_list(m_opSim, delData, addData, &VappPreferredNwSettingController::opProc, getObjHandle());
        m_signalOpProgress.emit((m_opIndex++), m_operation);
	}    
    else
    {
        // operation finished
        m_signalOpProgress.emit(m_opList->getCount(), m_operation);
        m_signalPostOp.disconnect(this, &VappPreferredNwSettingController::processInt);
        // deinit the list
        deinitList();
    }
}

void VappPreferredNwSettingController::deinitList()
{
    if (m_opList)
	{
        clearPlmnNodes(m_opList);
        VFX_OBJ_CLOSE(m_opList);
        m_opList = NULL;
    }
}
void VappPreferredNwSettingController::changePriority(mmi_sim_enum sim,VappSettingPlmnNodeBase *node, VfxU16 oldPriority, VfxU16 newPriority)
{
    m_operation = VAPP_PREFERRED_NW_CHANGE_PRIORITY;
    mmi_smu_set_preferred_oper_list_req_struct delReq, addReq;
    memset(&delReq, 0, sizeof(mmi_smu_set_preferred_oper_list_req_struct));
    memset(&addReq, 0, sizeof(mmi_smu_set_preferred_oper_list_req_struct));
    
    memcpy(delReq.oper, node->getPlmn(), (MAX_PLMN_LEN + 1));
    memcpy(addReq.oper, node->getPlmn(), (MAX_PLMN_LEN + 1));
    delReq.rat = addReq.rat = node->getRat();
    delReq.index = oldPriority;
    addReq.index = newPriority;
    srv_netset_set_pref_list(sim, &delReq, &addReq, &VappPreferredNwSettingController::opProc, getObjHandle());
}

void VappPreferredNwSettingController::operationFailed()
{
    m_signalOpProgress.postEmit(VAPP_PREF_NW_PROGRESS_FAILED, m_operation);
    // deinit the list
    deinitList();
    switch (m_operation)
	{
	case VAPP_PREFERRED_NW_ADD_TO_LIST:
	case VAPP_PREFERRED_NW_DELETE_FROM_LIST:
	case VAPP_PREFERRED_NW_CHANGE_PRIORITY:
        m_signalPostOp.disconnect(this, &VappPreferredNwSettingController::processInt);
		break;
	default:
		break;
	}
}

mmi_ret VappPreferredNwSettingController::opProc(mmi_event_struct *evt)
{
    srv_netset_rsp_event_struct *rspEvt = (srv_netset_rsp_event_struct*)evt;
    mmi_smu_set_preferred_oper_list_rsp_struct *setPrefNwRsp = rspEvt->rsp_data.set_pref_list_rsp_data;

    if (VappPreferredNwSettingController::m_abortBeforeClosed)
	{
	    // the controller has already closed.
	    return MMI_RET_OK;
	}
    VappPreferredNwSettingController *controller = (VappPreferredNwSettingController*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
    if (evt->evt_id == EVT_ID_SRV_NETSET_SET_PREF_LIST_RSP)
	{
        switch (controller->m_operation)
    	{
    	case VAPP_PREFERRED_NW_ADD_TO_LIST:
        case VAPP_PREFERRED_NW_DELETE_FROM_LIST:
            if ((rspEvt->result != SRV_NETSET_RSP_RESULT_SUCCESS) || (!setPrefNwRsp->result))
        	{
                controller->operationFailed();
                break;
        	}
       	    controller->m_signalPostOp.postEmit();
            break;
        case VAPP_PREFERRED_NW_CHANGE_PRIORITY:
            if ((rspEvt->result != SRV_NETSET_RSP_RESULT_SUCCESS) || (!setPrefNwRsp->result))
        	{
                controller->operationFailed();
                break;
        	}
            controller->m_signalOpProgress.emit(VAPP_PREF_NW_PROGRESS_DONE, controller->m_operation);
            break;
    	default:
    		break;
    	}	
	}
    return MMI_RET_OK;
}
/***************************************************************************** 
 * VappPreferredNwSettingInterface
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappPreferredNwSettingInterface);
void VappPreferredNwSettingInterface::updateList()
{
    ASSERT(m_sim != MMI_SIM_NONE && m_parent);

    if (!m_parser)
	{
	    VFX_OBJ_CREATE(m_parser, VappPreferredNwSettingParser, m_parent);
        m_parser->m_signalListReady.connect(this, &VappPreferredNwSettingInterface::controllerSignalProc);
	}

    if (!m_provider)
	{
	    VFX_OBJ_CREATE(m_provider, VappPreferredNwSettingProvider, m_parent);
	}
    if (m_simList)    
	{
            clearPlmnNodes(m_simList);
	    VFX_OBJ_CLOSE(m_simList);
            m_provider->setList(NULL);
	}
    
    setProcess(VAPP_PREFERRED_NW_GET_LIST);
    m_parser->updateList(m_sim);
}

VfxWString VappPreferredNwSettingInterface::getSimPlmn(VfxId plmnId)
{
    ASSERT(m_provider);
    return m_provider->getSimPlmn(plmnId);
}

VfxWString VappPreferredNwSettingInterface::getSimPlmnName(VfxId plmnId)
{
    ASSERT(m_provider);
    return m_provider->getSimPlmnName(plmnId);
}

VfxWString VappPreferredNwSettingInterface::getSimPlmnRat(VfxId plmnId)
{
    ASSERT(m_provider);
    return m_provider->getSimPlmnRat(plmnId);
}

VappSettingPlmnNodeBase* VappPreferredNwSettingInterface::getSimPlmnNode(VfxId plmnId)
{
    ASSERT(m_simList);
    return m_simList->getNode(plmnId);
}

VfxU16 VappPreferredNwSettingInterface::getSimPlmnLimit()
{
    return srv_netset_get_noof_plmn_supported(m_sim);
}

VfxU16 VappPreferredNwSettingInterface::getSimPlmnCount()
{
    ASSERT(m_provider);
    return m_provider->getSimPlmnCount();
}    

void VappPreferredNwSettingInterface::getSystemPlmn(VfxId plmnId, CHAR *buffer)
{
    ASSERT(m_provider);
    return m_provider->getSystemPlmn(plmnId, buffer);    
}

VfxWString VappPreferredNwSettingInterface::getSystemPlmnString(VfxId plmnId)
{
    ASSERT(m_provider);
    return m_provider->getSystemPlmnString(plmnId);
}
VfxWString VappPreferredNwSettingInterface::getSystemPlmnName(VfxId plmnId)
{
    ASSERT(m_provider);
    return m_provider->getSystemPlmnName(plmnId);
}

VfxU16 VappPreferredNwSettingInterface::getSystemPlmnCount()
{
    ASSERT(m_provider);
    return m_provider->getSystemPlmnCount();
}

void VappPreferredNwSettingInterface::swapSimPlmnDisplay(VfxId originalPlmnId, VfxId newPlmnId)
{
    m_simList->moveNode(originalPlmnId, newPlmnId);
}

VfxU8 VappPreferredNwSettingInterface::addToSimList(VappSettingPlmnList *list)
{
    ASSERT(m_simList && list);
//    VfxU16 index = 0;
    m_OpTotalNum = list->getCount();
    m_actualOpNum = m_OpTotalNum;
    if (m_OpTotalNum == 0)
	{
	    m_signalAddProgress.emit(VFX_TRUE, 1);
	}
    list->reset();
    VappSettingPlmnNodeBase *newNode = list->getCurrentNode();
    while (newNode)
	{
        m_simList->reset();
        VappSettingPlmnNodeBase *simNode = m_simList->getCurrentNode();
        while (simNode)
    	{
    	    if (memcmp(newNode->getPlmn(), simNode->getPlmn(), (MAX_PLMN_LEN + 1)) == 0
                && newNode->getRat() == simNode->getRat()
                )
        	{
        	    m_actualOpNum--;
                list->deleteNode(newNode);
                VFX_OBJ_CLOSE(newNode);
                break;
        	}
    	    simNode = m_simList->getCurrentNode();
    	}
        newNode = list->getCurrentNode();
	}
    if (m_actualOpNum == 0)
    {
	m_signalAddProgress.emit(VFX_TRUE, 1.0);
        return m_actualOpNum;
    }
    setProcess(VAPP_PREFERRED_NW_ADD_TO_LIST);
    m_controller.addToSimList(m_sim, list, getSimPlmnCount());
    return m_actualOpNum;
}
    
void VappPreferredNwSettingInterface::deleteFromSimList(VappSettingPlmnList *list)
{
    ASSERT(list);
    setProcess(VAPP_PREFERRED_NW_DELETE_FROM_LIST);
    m_OpTotalNum = list->getCount();
    m_controller.deleteFromSimList(m_sim, list);
}

void VappPreferredNwSettingInterface::changePriority(VfxId oldPriority, VfxId newPriority)
{
    ASSERT(m_simList && oldPriority < m_simList->getCount() && newPriority < m_simList->getCount());
    setProcess(VAPP_PREFERRED_NW_CHANGE_PRIORITY);
    m_simList->reset();
    VappPreferredNwPlmnNode *node = (VappPreferredNwPlmnNode*)m_simList->getCurrentNode();
    while (node)
	{
	    if (node->getPriority() == oldPriority)
		{
		    break;
		}
	    node = (VappPreferredNwPlmnNode*)m_simList->getCurrentNode();
	}
    ASSERT(node);
    m_controller.changePriority(m_sim, node, oldPriority, newPriority);    
}

void VappPreferredNwSettingInterface::autoClosed() 
{
    if (isProcessing())
	{
        if (getProcessType() == VAPP_PREFERRED_NW_GET_LIST)
    	{
    	    m_parser->abortUpdateList();
    	}
        else
        {
            m_controller.abortOperation(VFX_TRUE);
        }
	}
    VFX_OBJ_CLOSE_INSTANCE(VappPreferredNwSettingInterface);
}

void VappPreferredNwSettingInterface::abortOperation()
{
    setProcess(VAPP_PREFERRED_NW_ABORT_OPERATION);
    m_controller.abortOperation();
}

void VappPreferredNwSettingInterface::updateListAfterChangePriority()
{
    VfxU16 count = 0;
    if (NULL == m_simList)
    {
        return ;
    }
    
    m_simList->reset();
    VappPreferredNwPlmnNode *node = (VappPreferredNwPlmnNode*)m_simList->getCurrentNode();
    while (node)
	{
        node->setPriority(count);
        count++;
	    node = (VappPreferredNwPlmnNode*)m_simList->getCurrentNode();
	}
}

void VappPreferredNwSettingInterface::controllerSignalProc(VfxS8 progress, VappPreferredNwOpTypeEnum type)
{
    VfxBool result = (progress == -1) ? VFX_FALSE : VFX_TRUE;
    VfxFloat actualProgress = progress;
    switch (type)
	{
	case VAPP_PREFERRED_NW_GET_LIST:
        m_simList = m_parser->getSimList();
        m_simFileType = m_parser->getSimFileType();
        m_provider->setList(m_simList);
        m_signalListReady.emit(result);        
        break;
        
	case VAPP_PREFERRED_NW_ADD_TO_LIST:
        actualProgress = ((VfxFloat)(progress + m_OpTotalNum - m_actualOpNum)) / (VfxFloat)m_OpTotalNum;
		m_signalAddProgress.emit(result, actualProgress);
		break;

	case VAPP_PREFERRED_NW_DELETE_FROM_LIST:
        actualProgress = (VfxFloat)progress / (VfxFloat)m_OpTotalNum;
		m_signalDelProgress.emit(result, actualProgress);
		break;

	case VAPP_PREFERRED_NW_CHANGE_PRIORITY:
        updateListAfterChangePriority();
		m_signalChangePriorityDone.emit((progress == VAPP_PREF_NW_PROGRESS_DONE) ? VFX_TRUE : VFX_FALSE);
		break;

    case VAPP_PREFERRED_NW_ABORT_OPERATION:
        m_signalOpAborted.emit();
        break;
        
	default:
        break;		
	}
    if (actualProgress == VAPP_PREF_NW_PROGRESS_DONE)
	{
	    endProcess();
	}
}

/***************************************************************************** 
 * VappSettingPreferredNetworkMainPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSettingPreferredNetworkMainPage", VappSettingPreferredNetworkMainPage, VfxPage);
VappSettingPreferredNetworkMainPage::~VappSettingPreferredNetworkMainPage()
{
    VappPreferredNwSettingInterface *prefNwSettingInterface = (VappPreferredNwSettingInterface*)VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);    
    prefNwSettingInterface->closeInterface();
    if (m_listFlag)
	{
	    //delete []m_listFlag;
	    VFX_FREE_MEM(m_listFlag);
        m_listFlag = NULL;
	}
}
    
void VappSettingPreferredNetworkMainPage::onInit()
{
    VfxPage::onInit();
    /*
    VappPreferredNwSettingInterface *prefNwSettingInterface = (VappPreferredNwSettingInterface*)VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
    prefNwSettingInterface->initInterface(m_sim, this);    
    */
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(STR_ID_VAPP_SETTING_PREFERRED_NETWORK);
    setTopBar(m_titleBar);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(this, &VappSettingPreferredNetworkMainPage::onToolBarTapped);
    setBottomBar(m_toolBar);
    
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
	m_listMenu->setSize(getSize());
	m_listMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    m_isCancel = VFX_FALSE;
    //updateList();
    onListReady(VFX_TRUE);
}

void VappSettingPreferredNetworkMainPage::switchPageType(VappPrefNwPageTypeEnum pageType)
{
    m_pageType = pageType;
    switch (pageType)
	{
	case VAPP_PREF_NW_MAIN_PAGE:
        if (m_listFlag)
    	{
    	    //delete []m_listFlag;
    	    VFX_FREE_MEM(m_listFlag);
            m_listFlag = NULL;
    	}        
        
        m_titleBar->setTitle(STR_ID_VAPP_SETTING_PREFERRED_NETWORK);
        if (m_isCancel)
        {        
            m_listMenu->setContentProvider(this);
            m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
            m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
            m_listMenu->m_signalItemSelectionStateChanged.disconnect(this, &VappSettingPreferredNetworkMainPage::onSelectStateChanged);
            m_listMenu->resetAllItems(VFX_TRUE);
            updateToolBar();
            m_isCancel = VFX_FALSE;
        }
        else
        {
            updateList();
        }//m_isCancel
		break;
        
	case VAPP_PREF_NW_DEL_PAGE:
        // Do not update list, only change the menu mode and tool bar
        if(m_listFlag)
        {
            //delete []m_listFlag;
            VFX_FREE_MEM(m_listFlag);
            m_listFlag = NULL;
        }
        m_isCancel = VFX_FALSE;
//        m_listFlag = new VfxU8[getCount()];
        VFX_ALLOC_MEM(m_listFlag, getCount(), this);
        memset(m_listFlag, VCP_LIST_MENU_ITEM_STATE_UNSELECTED, (getCount() * sizeof(m_listFlag[0])));
        m_listCount = 0;
        m_titleBar->setTitle(STR_ID_VAPP_SETTING_DELETE_NETWORKS);
        m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    	m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
        m_listMenu->m_signalItemSelectionStateChanged.connect(this, &VappSettingPreferredNetworkMainPage::onSelectStateChanged);
        updateToolBar();
		break;

	default:
        ASSERT(0);		
	}

}

void VappSettingPreferredNetworkMainPage::updateAfterOp(VfxBool gotoEndOfList)
{
    m_updateListAndPopPage = VFX_TRUE;
    m_gotoEndOfList = gotoEndOfList;
    updateList();
}

void VappSettingPreferredNetworkMainPage::updateList()
{
    VappPreferredNwSettingInterface *prefNwSettingInterface = (VappPreferredNwSettingInterface*)VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
    prefNwSettingInterface->m_signalListReady.connect(this, &VappSettingPreferredNetworkMainPage::onListReady);
    prefNwSettingInterface->updateList();
}

void VappSettingPreferredNetworkMainPage::onListReady(VfxBool result)
{
    if (!result)
	{
	    VcpConfirmPopup *popup;
        VFX_OBJ_CREATE(popup, VcpConfirmPopup, findScreen());        
        popup->setText(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        //popup->setTextAlignMode((VfxTextFrame::AlignModeEnum)3);
        popup->show(VFX_TRUE);
	}

	m_listMenu->setContentProvider(this);
    switch (m_pageType)
	{
	case VAPP_PREF_NW_MAIN_PAGE:
        m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    	m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
        m_listMenu->m_signalItemSelectionStateChanged.disconnect(this, &VappSettingPreferredNetworkMainPage::onSelectStateChanged);
        m_listMenu->resetAllItems(VFX_TRUE);
		break;
        
	case VAPP_PREF_NW_DEL_PAGE:
		m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    	m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
        m_listMenu->m_signalItemSelectionStateChanged.connect(this, &VappSettingPreferredNetworkMainPage::onSelectStateChanged);
		break;

	default:
        ASSERT(0);		
	}
    
    if (m_updateListAndPopPage)
    {
	if (m_gotoEndOfList)
	{
            m_listMenu->setVisibleMenuRegion(-1, getCount(), VFX_TRUE);
	}
        getMainScr()->popPage();
        m_updateListAndPopPage = VFX_FALSE;
    }
    
    updateToolBar();
}

void VappSettingPreferredNetworkMainPage::updateToolBar()
{
    m_toolBar->removeItem(VAPP_PREF_NETWORK_ADD_BTN);
    m_toolBar->removeItem(VAPP_PREF_NETWORK_CHANGE_BTN);
    m_toolBar->removeItem(VAPP_PREF_NETWORK_DELETE_BTN);
    
    if (m_pageType == VAPP_PREF_NW_MAIN_PAGE)
	{
        VappPreferredNwSettingInterface *prefNwSettingInterface = (VappPreferredNwSettingInterface*)VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
        // No PLMN
        if (prefNwSettingInterface->getSimPlmnCount() < prefNwSettingInterface->getSimPlmnLimit())
    	{
    	    m_toolBar->addItem(VAPP_PREF_NETWORK_ADD_BTN, STR_GLOBAL_ADD, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);	
    	}

        if (prefNwSettingInterface->getSimPlmnCount() > 0)
    	{
    	    m_toolBar->addItem(VAPP_PREF_NETWORK_CHANGE_BTN, STR_ID_VAPP_SETTING_CHANGE_PRIORITY, IMG_ID_VAPP_SETTING_CHANGE_PRIORITY);
    	    m_toolBar->addItem(VAPP_PREF_NETWORK_DELETE_BTN, STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);	
    	}
	}
    else if (m_pageType == VAPP_PREF_NW_DEL_PAGE)
	{
	    m_toolBar->addItem(VAPP_PREF_NETWORK_DEL_OK_BTN, STR_GLOBAL_OK, VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
        m_toolBar->addItem(VAPP_PREF_NETWORK_DEL_CANCEL_BTN, STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
        m_toolBar->setDisableItem(VAPP_PREF_NETWORK_DEL_OK_BTN, VFX_TRUE);
	}
}

void VappSettingPreferredNetworkMainPage::onToolBarTapped(VfxObject *obj, VfxId id)
{
    if (m_pageType == VAPP_PREF_NW_MAIN_PAGE)
	{
        switch (id)
    	{
    	case VAPP_PREF_NETWORK_ADD_BTN:
    		//Add
    		VcpCommandPopup *popup;
            VFX_OBJ_CREATE(popup, VcpCommandPopup, getMainScr());
            popup->setText(STR_GLOBAL_ADD);
            popup->addItem('USR1', STR_ID_VAPP_SETTING_ADD_FROM_PREDEFINED_LIST, VCP_POPUP_BUTTON_TYPE_RECOMMEND);
            popup->addItem('USR2', STR_ID_VAPP_SETTING_CREATE_NEW_NETWORK, VCP_POPUP_BUTTON_TYPE_NORMAL);
            popup->addItem('USR3', STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);
            popup->m_signalButtonClicked.connect(this, &VappSettingPreferredNetworkMainPage::onCommandPopupTapped);
            popup->show(VFX_TRUE);
    		break;
        case VAPP_PREF_NETWORK_CHANGE_BTN:
            VappSettingPreferredNetworkChangePriorityPage *page;
            VFX_OBJ_CREATE(page, VappSettingPreferredNetworkChangePriorityPage, getMainScr());
            page->m_signalUpdateList.connect(this, &VappSettingPreferredNetworkMainPage::updateAfterOp);
            getMainScr()->pushPage(0, page);
            break;
    	case VAPP_PREF_NETWORK_DELETE_BTN:        
            switchPageType(VAPP_PREF_NW_DEL_PAGE);
            break;
    	default:
    		break;
    	}	
    }
    else if (m_pageType == VAPP_PREF_NW_DEL_PAGE)
	{
        switch (id)
    	{
    	case VAPP_PREF_NETWORK_DEL_OK_BTN:
            VcpConfirmPopup *popup;
            VFX_OBJ_CREATE(popup, VcpConfirmPopup, findScreen());        
            popup->setText(STR_ID_VAPP_SETTING_DELETE_CONFIRM);
            popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            popup->setInfoType(VCP_POPUP_TYPE_WARNING);
            popup->setCustomButton(
                STR_GLOBAL_DELETE, 
                STR_GLOBAL_CANCEL, 
                VCP_POPUP_BUTTON_TYPE_WARNING,
                VCP_POPUP_BUTTON_TYPE_CANCEL);
            //popup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
            popup->m_signalButtonClicked.connect(this, &VappSettingPreferredNetworkMainPage::onDeleteConfirmPopupTapped);
            popup->show(VFX_TRUE);
    		break;
        case VAPP_PREF_NETWORK_DEL_CANCEL_BTN:
            m_isCancel = VFX_TRUE;
            switchPageType(VAPP_PREF_NW_MAIN_PAGE);
            break;
    	default:
    		break;
    	}
	}

}

void VappSettingPreferredNetworkMainPage::deleteSelectedPlmn(void)
{
    VfxU8 i;
    VappSettingPlmnList *list = NULL;
    VFX_OBJ_CREATE(list, VappSettingPlmnList, this);
    VappPreferredNwSettingInterface *prefNwSettingInterface = (VappPreferredNwSettingInterface*)VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
    for (i = 0; i < getCount(); i++)
	{
		if (m_listFlag[i] == VCP_LIST_MENU_ITEM_STATE_SELECTED)
		{
            VappSettingPlmnNodeBase *node = prefNwSettingInterface->getSimPlmnNode(i);
            VappPreferredNwPlmnNode *delNode;
            VFX_OBJ_CREATE_EX(delNode, VappPreferredNwPlmnNode, this, (node->getPlmn(), node->getRat(), i));
            list->appendNode(delNode);
		}
	}
    if (list->getCount() == 0)
	{
	    VFX_OBJ_CLOSE(list);        
	    return;
	}
    
    VFX_OBJ_CREATE(m_progressPopup, VcpIndicatorPopup, this);
    m_progressPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
    m_progressPopup->setText(STR_ID_VAPP_SETTING_DELETING);
    m_progressPopup->setMaxProgress(1.0);
    m_progressPopup->setProgress(0);
    m_progressPopup->setAutoDestory(VFX_FALSE);
    m_progressPopup->m_signalButtonClicked.connect(this, &VappSettingPreferredNetworkMainPage::onCancelDel);
    m_progressPopup->show(VFX_TRUE);

    
    prefNwSettingInterface->m_signalDelProgress.connect(this, &VappSettingPreferredNetworkMainPage::onDelProgress);
    prefNwSettingInterface->deleteFromSimList(list);
}

void VappSettingPreferredNetworkMainPage::onCancelDel(VfxObject *obj, VfxId id)
{
    if (id == VCP_POPUP_BUTTON_CANCEL_PRESSED)
    {
        VappPreferredNwSettingInterface *prefNwSettingInterface = (VappPreferredNwSettingInterface*)VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
        prefNwSettingInterface->m_signalOpAborted.connect(this, &VappSettingPreferredNetworkMainPage::cancelDelete);

        m_progressPopup->exit(VFX_TRUE);

        VFX_OBJ_CREATE(m_cancelWaitingPopup, VcpIndicatorPopup, this);
        m_cancelWaitingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_cancelWaitingPopup->setText(STR_GLOBAL_PLEASE_WAIT);
        m_cancelWaitingPopup->show(VFX_TRUE);
        
        prefNwSettingInterface->abortOperation();
    }
}

void VappSettingPreferredNetworkMainPage::cancelDelete()
{
    VappPreferredNwSettingInterface *prefNwSettingInterface = (VappPreferredNwSettingInterface*)VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
    prefNwSettingInterface->m_signalOpAborted.disconnect(this, &VappSettingPreferredNetworkMainPage::cancelDelete);
    m_cancelWaitingPopup->exit(VFX_TRUE);
    m_cancelWaitingPopup = NULL;
    switchPageType(VAPP_PREF_NW_MAIN_PAGE);
}

void VappSettingPreferredNetworkMainPage::onDeleteConfirmPopupTapped(VfxObject *obj, VfxId id)
{
    switch (id)
	{
	case 'USR1':
        m_isCancel = VFX_FALSE;
		deleteSelectedPlmn();
		break;
	default:
	    break;	
	}
}

void VappSettingPreferredNetworkMainPage::onCommandPopupTapped(VfxObject *obj, VfxId id)
{
    switch (id)
	{
	case 'USR1':
        VappSettingPreferredNetworkAddListPage *addFromListPage;
        VFX_OBJ_CREATE(addFromListPage, VappSettingPreferredNetworkAddListPage, getMainScr());
        addFromListPage->m_signalUpdateList.connect(this, &VappSettingPreferredNetworkMainPage::updateAfterOp);
		getMainScr()->pushPage(0, addFromListPage);
		break;
    case 'USR2':
        VappSettingPreferredNetworkCreateNewPage *page;
        VFX_OBJ_CREATE(page, VappSettingPreferredNetworkCreateNewPage, getMainScr());
        page->m_signalUpdateList.connect(this, &VappSettingPreferredNetworkMainPage::updateAfterOp);
        getMainScr()->pushPage(0, page);
        break;
	default:
		break;
	}
}

VfxBool VappSettingPreferredNetworkMainPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    VappPreferredNwSettingInterface *prefNwSettingInterface = (VappPreferredNwSettingInterface*)VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
	if (index < getCount())
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)	
		{
		    text = prefNwSettingInterface->getSimPlmnName(index);
		    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		    return VFX_TRUE;
		}
        if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    	{
    	    VfxWString hintString = prefNwSettingInterface->getSimPlmnRat(index);
            hintString += VFX_WSTR(" ");
            hintString += prefNwSettingInterface->getSimPlmn(index);
            text = hintString;
    		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    		return VFX_TRUE;
    	}
	}    
    return VFX_FALSE;
}

VfxU32 VappSettingPreferredNetworkMainPage::getCount() const
{
    VappPreferredNwSettingInterface *prefNwSettingInterface = (VappPreferredNwSettingInterface*)VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
    return prefNwSettingInterface->getSimPlmnCount();
}

VcpListMenuItemStateEnum VappSettingPreferredNetworkMainPage::getItemState(VfxU32 index) const
{
    return (VcpListMenuItemStateEnum)m_listFlag[index];
}

VfxBool VappSettingPreferredNetworkMainPage::getItemIsHighlightable(VfxU32 index) const 
{
    if (m_pageType == VAPP_PREF_NW_MAIN_PAGE)
    {
        // Should not high light the main list
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}

void VappSettingPreferredNetworkMainPage::onSelectStateChanged(VcpListMenu *sender, VfxU32 id, VcpListMenuItemStateEnum state)
{
    if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
	{
        if(m_listFlag[id] == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
        {
    	    m_listCount++;
        }
	}
    else
    {
        // Revise count only when the status is changed from selected to unselected
        if(m_listFlag[id] == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        {
    	    m_listCount--;
        }
    }    
    m_listFlag[id] = (VfxU8)state;
    if (m_listCount == 0)
	{
	   m_toolBar->setDisableItem(VAPP_PREF_NETWORK_DEL_OK_BTN, VFX_TRUE);
	}
    else
    {
	   m_toolBar->setDisableItem(VAPP_PREF_NETWORK_DEL_OK_BTN, VFX_FALSE);
    }
}

void VappSettingPreferredNetworkMainPage::onDelProgress(VfxBool result, VfxFloat progress)
{
    if (!result)
	{
        VcpConfirmPopup *popup;
        VFX_OBJ_CREATE(popup, VcpConfirmPopup, getMainScr());        
        popup->setText(STR_GLOBAL_FAILED_TO_SAVE);
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        //popup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        popup->show(VFX_TRUE);

        m_progressPopup->exit(VFX_TRUE);

        VappPreferredNwSettingInterface *prefNwSettingInterface = VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
        prefNwSettingInterface->m_signalDelProgress.disconnect(this, &VappSettingPreferredNetworkMainPage::onDelProgress);
        updateList();
	}
    else
    {
        m_progressPopup->setProgress(progress);
        if (progress == 1)
    	{
    	    // Delete finish
            m_progressPopup->m_signalButtonClicked.disconnect(this, &VappSettingPreferredNetworkMainPage::onCancelDel);
            m_progressPopup->exit(VFX_TRUE); 
            if (m_cancelWaitingPopup)
            {
                m_cancelWaitingPopup->exit(VFX_TRUE);
                m_cancelWaitingPopup = NULL;
            }
            switchPageType(VAPP_PREF_NW_MAIN_PAGE);
    	}
    }

}

void VappSettingPreferredNetworkMainPage::onBack()
{
    if (m_pageType == VAPP_PREF_NW_DEL_PAGE)
	{
	    switchPageType(VAPP_PREF_NW_MAIN_PAGE);
	}
    else
    {
        VfxPage::onBack();
    }
}

/***************************************************************************** 
 * VappSettingPreferredNetworkChangePriorityPage
 *****************************************************************************/
void VappSettingPreferredNetworkChangePriorityPage::onInit()
{
    VfxPage::onInit();

    m_startIndex = m_endIndex = (VfxU32)-1;

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(STR_ID_VAPP_SETTING_CHANGE_PRIORITY);
    setTopBar(m_titleBar);

    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
	m_listMenu->setSize(getSize());
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
	m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_REORDER, VFX_TRUE);
	m_listMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->m_signalEndDragCell.connect(this, &VappSettingPreferredNetworkChangePriorityPage::onChangePriority);
	m_listMenu->setContentProvider(this);
    
}

void VappSettingPreferredNetworkChangePriorityPage::onBack()
{
    m_signalUpdateList.emit(VFX_FALSE);
}

VfxBool VappSettingPreferredNetworkChangePriorityPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    VappPreferredNwSettingInterface *prefNwSettingInterface = (VappPreferredNwSettingInterface*)VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
	if (index < getCount())
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)	
		{
		    text = prefNwSettingInterface->getSimPlmnName(index);
		    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		    return VFX_TRUE;
		}
        if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    	{
    	    VfxWString hintString = prefNwSettingInterface->getSimPlmnRat(index);
            hintString += VFX_WSTR(" ");
            hintString += prefNwSettingInterface->getSimPlmn(index);
            text = hintString;
    		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    		return VFX_TRUE;
    	}
	}    
    return VFX_FALSE;
}

VfxU32 VappSettingPreferredNetworkChangePriorityPage::getCount() const
{
    VappPreferredNwSettingInterface *prefNwSettingInterface = (VappPreferredNwSettingInterface*)VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
    return prefNwSettingInterface->getSimPlmnCount();
}

VfxBool VappSettingPreferredNetworkChangePriorityPage::swapItem(VfxU32 index1, VfxU32 index2)
{
    VappPreferredNwSettingInterface *prefNwSettingInterface = VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);    
    // Tracking the swap to get the start index and end index
    if ((m_startIndex == (VfxU32)-1) || (m_endIndex == (VfxU32)-1))
	{
	    m_startIndex = index1;
        m_endIndex = index2;
	}
    else
    {
        if (index1 == m_startIndex || index1 == m_endIndex)
    	{
    	    // index1 is temp index
    	    m_startIndex = (m_startIndex != index1) ? m_startIndex : m_endIndex;
            m_endIndex = index2;
    	}
        else if (index2 == m_startIndex || index2 == m_endIndex)
    	{
    	    // index2 is temp index
    	    m_startIndex = (m_startIndex != index2) ? m_startIndex : m_endIndex;
            m_endIndex = index1;
    	}
    }
	if (m_startIndex == m_endIndex)
	{
	    // Reset the index because the cell is draw back to the original place
		m_startIndex = m_endIndex = -1;
	}
	VFX_TRACE(("\n######swapItem %d, %d (%d, %d)######\n", index1, index2, m_startIndex, m_endIndex));
    prefNwSettingInterface->swapSimPlmnDisplay(index1, index2);
    return VFX_TRUE;
}

void VappSettingPreferredNetworkChangePriorityPage::onChangePriority(VcpListMenu *sender)
{
	if(m_startIndex == -1 || m_endIndex == -1)
	{
		return;
	}
	VappPreferredNwSettingInterface *prefNwSettingInterface = VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
    prefNwSettingInterface->m_signalChangePriorityDone.connect(this, &VappSettingPreferredNetworkChangePriorityPage::onChangePriorityFinish);
    prefNwSettingInterface->changePriority(m_startIndex, m_endIndex);
	m_startIndex = m_endIndex = (VfxU32)-1;
}

void VappSettingPreferredNetworkChangePriorityPage::onChangePriorityFinish(VfxBool result)
{
    if (!result)
	{
        VcpConfirmPopup *popup;
        VFX_OBJ_CREATE(popup, VcpConfirmPopup, getMainScr());        
        popup->setText(VFX_WSTR("Change priority failed"));
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        //popup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        popup->show(VFX_TRUE);

        m_signalUpdateList.emit(VFX_FALSE);
	}
}
/***************************************************************************** 
 * VappSettingPreferredNetworkAddListPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSettingPreferredNetworkAddListPage", VappSettingPreferredNetworkAddListPage, VfxPage);
VappSettingPreferredNetworkAddListPage::~VappSettingPreferredNetworkAddListPage()
{
    if (m_listFlag)
	{
	    //delete []m_listFlag;
	    VFX_FREE_MEM(m_listFlag);
	}
}

void VappSettingPreferredNetworkAddListPage::onInit()
{
    VfxPage::onInit();
//    m_listFlag = new VfxU8[getCount()];
    VFX_ALLOC_MEM(m_listFlag, getCount(), this);
    memset(m_listFlag, VCP_LIST_MENU_ITEM_STATE_UNSELECTED, getCount() * sizeof(VfxU8));

    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(STR_ID_VAPP_SETTING_ADD_FROM_PREDEFINED_LIST);
    setTopBar(titleBar);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(0, STR_GLOBAL_OK, VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem(1, STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->setDisableItem(0, VFX_TRUE);
    m_toolBar->m_signalButtonTap.connect(this, &VappSettingPreferredNetworkAddListPage::onToolBarTapped);
    setBottomBar(m_toolBar);

    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
	m_listMenu->setContentProvider(this);
	m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
	m_listMenu->setSize(getSize());
	m_listMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->m_signalItemSelectionStateChanged.connect(this, &VappSettingPreferredNetworkAddListPage::onSelectStateChanged);
}

void VappSettingPreferredNetworkAddListPage::onToolBarTapped(VfxObject *obj, VfxId id)
{

    switch (id)
	{
	case 0:
    {
        #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
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
        #else
        addSelectedPlmn(SRV_NETSET_RAT_NONE);
        #endif

        break;
    }
        
	case 1:
        getMainScr()->popPage();
		break;
	default:
		break;
	}
}

void VappSettingPreferredNetworkAddListPage::onCommandPopupTapped(VfxObject *obj, VfxId id)
{
    switch (id)
	{
	case 'GSM_':
        addSelectedPlmn(SRV_NETSET_RAT_GSM);
        break;
        
    case 'UMTS':
        addSelectedPlmn(SRV_NETSET_RAT_UMTS);
        break;
        
    case 'NoOK':
		break;
	default:
		break;
	}
}
void VappSettingPreferredNetworkAddListPage::addSelectedPlmn(srv_netset_rat_mode_enum rat)
{
    if (m_listCount == 0)
	{
	    getMainScr()->popPage();
        return;
	}
    
    VappSettingPlmnList *list;
    VFX_OBJ_CREATE(list, VappSettingPlmnList, this);

    VappPreferredNwSettingInterface *prefNwSettingInterface = VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);

    VfxU16 i;
    for (i = 0; i < getCount(); i++)
	{
	    if (m_listFlag[i] == VCP_LIST_MENU_ITEM_STATE_SELECTED)	
		{
		    VappSettingPlmnNodeBase *node;
            CHAR buffer[(MAX_PLMN_LEN + 1)];
            prefNwSettingInterface->getSystemPlmn(i, buffer);
            VFX_OBJ_CREATE_EX(node, VappSettingPlmnNodeBase, this, (buffer, rat));
            list->appendNode(node);
		}
	}

    prefNwSettingInterface->m_signalAddProgress.connect(this, &VappSettingPreferredNetworkAddListPage::onAddProgress);
    if (prefNwSettingInterface->addToSimList(list) == 0)
    {
	// Do not display indication popup
	return;
    }
    // Begin to add
    VFX_OBJ_CREATE(m_progressPopup, VcpIndicatorPopup, this);
    m_progressPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
    m_progressPopup->setText(STR_ID_VAPP_SETTING_ADDING);
    m_progressPopup->setMaxProgress(1.0);
    m_progressPopup->setProgress(0);
    m_progressPopup->setAutoDestory(VFX_FALSE);
    m_progressPopup->m_signalButtonClicked.connect(this, &VappSettingPreferredNetworkAddListPage::onCancelAdd);
    m_progressPopup->show(VFX_TRUE);

}

void VappSettingPreferredNetworkAddListPage::onSelectStateChanged(VcpListMenu *sender, VfxU32 id, VcpListMenuItemStateEnum state)
{
    if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
	{
	    VappPreferredNwSettingInterface *prefNwSettingInterface = VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
        VfxU16 newCount = prefNwSettingInterface->getSimPlmnCount() + m_listCount + 1;
	    if (newCount > prefNwSettingInterface->getSimPlmnLimit())
		{
		    showLimitPopup();
            m_listMenu->setItemState(id, VCP_LIST_MENU_ITEM_STATE_UNSELECTED);
            return;
		}
        if(m_listFlag[id] == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
        {
    	    m_listCount++;
        }
	}
    else
    {
        // Revise count only when the status is changed from selected to unselected
        if(m_listFlag[id] == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        {
    	    m_listCount--;
        }
    }    
    if (m_listCount == 0)
	{
	   m_toolBar->setDisableItem(0, VFX_TRUE);
	}
    else
    {
	   m_toolBar->setDisableItem(0, VFX_FALSE);
    }
    m_listFlag[id] = (VfxU8)state;
}

void VappSettingPreferredNetworkAddListPage::showLimitPopup()
{
    VcpConfirmPopup *popup;
    VFX_OBJ_CREATE(popup, VcpConfirmPopup, getMainScr());        
    popup->setText(STR_ID_VAPP_SETTING_CANNOT_ADD_MORE_NETWORK);
    popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    //popup->setTextAlignMode((VfxTextFrame::AlignModeEnum)3);
    popup->show(VFX_TRUE);
}

void VappSettingPreferredNetworkAddListPage::onAddProgress(VfxBool result, VfxFloat progress)
{
    if (!result)
	{
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            VFX_WSTR_RES(STR_GLOBAL_FAILED_TO_SAVE).getBuf());
        
        if (m_progressPopup)
    	{
            m_progressPopup->exit(VFX_TRUE);
            m_progressPopup = NULL;
    	}

        VappPreferredNwSettingInterface *prefNwSettingInterface = VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
        prefNwSettingInterface->m_signalAddProgress.disconnect(this, &VappSettingPreferredNetworkAddListPage::onAddProgress);
        m_signalUpdateList.emit(VFX_TRUE);
	}
    else
    {
        if (m_progressPopup)
    	{
            m_progressPopup->setProgress(progress);    	
        }
        if (progress == 1)
    	{
    	    // Add finish
    	    m_signalUpdateList.emit(VFX_TRUE);
            if (m_progressPopup)
            {
                m_progressPopup->exit(VFX_TRUE);
                m_progressPopup = NULL;
            }
    	}
    }
}

void VappSettingPreferredNetworkAddListPage::onCancelAdd(VfxObject *obj, VfxId id)
{
    if (id == VCP_POPUP_BUTTON_CANCEL_PRESSED)
    {
        VappPreferredNwSettingInterface *prefNwSettingInterface = (VappPreferredNwSettingInterface*)VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
        prefNwSettingInterface->m_signalOpAborted.connect(this, &VappSettingPreferredNetworkAddListPage::cancelAdd);
        prefNwSettingInterface->abortOperation();	
    }
}

void VappSettingPreferredNetworkAddListPage::cancelAdd()
{
    VappPreferredNwSettingInterface *prefNwSettingInterface = (VappPreferredNwSettingInterface*)VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
    prefNwSettingInterface->m_signalOpAborted.disconnect(this, &VappSettingPreferredNetworkAddListPage::cancelAdd);
    m_signalUpdateList.emit(VFX_TRUE);
}
    
VfxBool VappSettingPreferredNetworkAddListPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    VappPreferredNwSettingInterface *prefNwSettingInterface = VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
	if (index < getCount())
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)	
		{
		    text = prefNwSettingInterface->getSystemPlmnName(index);
		    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		    return VFX_TRUE;
		}
        if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    	{
            text = prefNwSettingInterface->getSystemPlmnString(index);
    		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    		return VFX_TRUE;
    	}
	}    
    return VFX_FALSE;
}
VfxU32 VappSettingPreferredNetworkAddListPage::getCount() const
{
    VappPreferredNwSettingInterface *prefNwSettingInterface = VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
    return prefNwSettingInterface->getSystemPlmnCount();
}

VcpListMenuItemStateEnum VappSettingPreferredNetworkAddListPage::getItemState(VfxU32 index) const
{
    return (VcpListMenuItemStateEnum)m_listFlag[index];
}

/***************************************************************************** 
 * VappSettingPreferredNetworkCreateNewPage
 *****************************************************************************/
static VfxWString VappPrefNwRatTypeString[] = 
{
    VFX_WSTR("2G"),
    VFX_WSTR("3G")
};
VFX_IMPLEMENT_CLASS("VappSettingPreferredNetworkCreateNewPage", VappSettingPreferredNetworkCreateNewPage, VfxPage);
void VappSettingPreferredNetworkCreateNewPage::onInit()
{
    VfxPage::onInit();
        
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(STR_ID_VAPP_SETTING_CREATE_NEW_NETWORK);
    setTopBar(titleBar);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(0, STR_GLOBAL_OK, VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem(1, STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect(this, &VappSettingPreferredNetworkCreateNewPage::onToolBarTapped);
    setBottomBar(m_toolBar);    

    VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setPos(0, 0);
    m_form->setSize(getSize());
//	m_form->setBgColor(VFX_COLOR_WHITE);
	m_form->enableVerticalScrollIndicator(VFX_TRUE);
	m_form->setBorderColor(VFX_COLOR_BLACK);   
    m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_textInputCell, VcpFormItemTextInput, this);
    m_textInputCell->setLabelText(VFX_WSTR("MCC/MNC"));
    VcpTextEditor *textEditor = m_textInputCell->getTextBox();
    textEditor->setMaxLength(6);
    textEditor->setIME(IMM_INPUT_TYPE_NUMERIC);
    textEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    textEditor->setAutoActivated(VFX_TRUE);
    textEditor->m_signalTextChanged.connect(this, &VappSettingPreferredNetworkCreateNewPage::onTextChanged);

    VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, this);
    m_funcBar->addItem(0, VFX_WSTR_RES(STR_GLOBAL_OK));
    m_funcBar->addItem(1, VFX_WSTR_RES(STR_GLOBAL_CANCEL));
    m_funcBar->m_signalButtonTap.connect(this, &VappSettingPreferredNetworkCreateNewPage::onToolBarTapped);
    textEditor->setFunctionBar(m_funcBar);
    
    m_form->addItem(m_textInputCell, 0);
    m_form->insertSeparator((VfxId)0);

    // Disable the OK button because the input lenght is less than 5
    m_funcBar->setDisableItem(0, VFX_TRUE);
    m_toolBar->setDisableItem(0, VFX_TRUE);   

    #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
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
    #endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
}

void VappSettingPreferredNetworkCreateNewPage::addPlmn(const VfxWString &plmn, srv_netset_rat_mode_enum ratType)
{
    VappSettingPlmnList *list;
    VFX_OBJ_CREATE(list, VappSettingPlmnList, this);

    VappSettingPlmnNodeBase *node;
    CHAR buffer[(MAX_PLMN_LEN + 1)];
    memset(buffer, 0, (MAX_PLMN_LEN + 1));
    app_ucs2_wcs_to_asc_str((kal_int8*)buffer, (kal_wchar*)plmn.getBuf());
    VFX_OBJ_CREATE_EX(node, VappSettingPlmnNodeBase, this, (buffer, ratType));
    list->appendNode(node);

    // Begin to add
    VappPreferredNwSettingInterface *prefNwSettingInterface = VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
    prefNwSettingInterface->m_signalAddProgress.connect(this, &VappSettingPreferredNetworkCreateNewPage::onAddProgress);

    if (prefNwSettingInterface->addToSimList(list) == 0)
    {
	// Do not display indication popup
        return;	
    }
    VFX_OBJ_CREATE(m_progressPopup, VcpIndicatorPopup, this);
    m_progressPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_progressPopup->setText(STR_ID_VAPP_SETTING_ADDING);
    m_progressPopup->setAutoDestory(VFX_FALSE);
    m_progressPopup->show(VFX_TRUE);
}
void VappSettingPreferredNetworkCreateNewPage::onToolBarTapped(VfxObject *obj, VfxId id)
{
    switch (id)
	{
	case 0:
    {
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
#endif        
        #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
/* under construction !*/
        #else
        addPlmn(m_textInputCell->getText());
        #endif
        break;
    }
        
	case 1:
        getMainScr()->popPage();
		break;
	default:
		break;
	}
}

void VappSettingPreferredNetworkCreateNewPage::onTextChanged(VcpTextEditor *obj)
{
    if (m_textInputCell->getText().getLength() < 5)
    {
        m_funcBar->setDisableItem(0, VFX_TRUE);
        m_toolBar->setDisableItem(0, VFX_TRUE);
    }
    else
    {
        m_funcBar->setDisableItem(0, VFX_FALSE);
        m_toolBar->setDisableItem(0, VFX_FALSE);
    }
}

void VappSettingPreferredNetworkCreateNewPage::onAddProgress(VfxBool result, VfxFloat progress)
{
    if (!result)
	{
        VcpConfirmPopup *popup;
        VFX_OBJ_CREATE(popup, VcpConfirmPopup, getMainScr());        
        popup->setText(STR_GLOBAL_FAILED_TO_SAVE);
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        //popup->setTextAlignMode((VfxTextFrame::AlignModeEnum)3);
        popup->show(VFX_TRUE);

        VappPreferredNwSettingInterface *prefNwSettingInterface = VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
        prefNwSettingInterface->m_signalAddProgress.disconnect(this, &VappSettingPreferredNetworkCreateNewPage::onAddProgress);
        m_signalUpdateList.emit(VFX_TRUE);
	}
    else
    {
        if (progress == 1)
    	{
    	    // Add finish
    	    m_textInputCell->setFocused(VFX_FALSE);
    	    m_signalUpdateList.emit(VFX_TRUE);
    	}
    }
    if (m_progressPopup)
    {
        m_progressPopup->exit(VFX_TRUE);
        m_progressPopup = NULL;
    }
}

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
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
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
