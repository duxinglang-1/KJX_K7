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
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH¡ä?
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
 *  vapp_prov_viewer.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_global_popup.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vapp_cca_def.h"
#include "vapp_cca_gprot.h"
#ifdef __MMI_PROV_IN_UM__ 

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" 
#endif
{
    #include "ccasrvgprot.h"
    #include "ProvBoxSrvGProt.h"
    #include "ProvBoxSrvIProt.h"
    
    #ifdef __DM_LAWMO_SUPPORT__
    #include "DmSrvGprot.h"
    #endif
}

#include "vapp_cca_gprot.h"

#include "vapp_nmgr_gprot.h"

#include "mmi_frm_scenario_gprot.h"

#include "mmi_rp_vapp_prov_msg_def.h"

#include "vapp_msg_contact_bar.h"

#include "vapp_prov_viewer.h"

#include "vapp_prov_base.h"

#include "vapp_prov_util.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"


/*****************************************************************************
 * define macro
 *****************************************************************************/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static vapp_prov_box_cntx_struct g_vapp_prov_box_cntx = {0};
static VfxBool m_isInstall = VFX_FALSE;

#ifdef __DM_LAWMO_SUPPORT__
static void vapp_prov_dm_lock_callback(mmi_dmui_app_id_enum app_id, mmi_dmui_cmd_enum cmd);
static srv_provbox_result_enum vapp_prov_delete_all(srv_provbox_box_type_enum box_type);
#endif /* __DM_LAWMO_SUPPORT__ */

static void vapp_prov_set_group_id(MMI_ID parent_id);

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/
extern "C" void vapp_prov_app_init(void)
{
    /* Register event handler function */
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_CCA_PROCESS_PROV_MSG_CNF,
        (PsIntFuncPtr) VappProvMsgDataOp::onInstallMsgHdlr,
        MMI_TRUE);

#ifdef __DM_LAWMO_SUPPORT__
    /* Register DM event handler function */
    mmi_dmui_lawmo_register_notify(MMI_DMUI_APP_ID_PROVBOX, 
        MMI_DMUI_MO_TYPE_LAWMO_WIPE, vapp_prov_dm_lock_callback);
#endif /* __DM_LAWMO_SUPPORT__ */
}


#ifdef __DM_LAWMO_SUPPORT__
static void vapp_prov_dm_lock_callback(mmi_dmui_app_id_enum app_id, mmi_dmui_cmd_enum cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_id == MMI_DMUI_APP_ID_PROVBOX)
    {
        switch (cmd)
        {
            case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
            {
                vapp_prov_delete_all(SRV_PROVBOX_BOX_TYPE_WHOLE_ALL);
            }
            break;

            default:
            break;
        }
    }
    
    mmi_dmui_lawmo_report(
        MMI_DMUI_APP_ID_PROVBOX,
        cmd,
        MMI_DMUI_RESULT_SUCCESS);
}
#endif /* __DM_LAWMO_SUPPORT__ */

extern "C" MMI_ID vapp_prov_get_group_id(void)
{
    return g_vapp_prov_box_cntx.parent_id;
}


static void vapp_prov_set_group_id(MMI_ID parent_id)
{
    g_vapp_prov_box_cntx.parent_id = parent_id;
}


void vapp_prov_install_ext(VfxU32 msg_id, VAPP_PROV_CB_FUNC_P cb_func, void* user_data, VfxS32 gid)
{
    VappOperateCell::onSetCell(msg_id, user_data, cb_func);
    vapp_prov_set_group_id(gid);

    /* Register event handler function */
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_CCA_PROCESS_PROV_MSG_CNF,
        (PsIntFuncPtr) vapp_prov_msg_handle_install_cnf,
        MMI_TRUE);

    vapp_prov_msg_sent_install_req(msg_id, VAPP_PROV_TRANS_ID_CCA_PROCESS_MSG_EXT);
}

#ifdef __DM_LAWMO_SUPPORT__
static srv_provbox_result_enum vapp_prov_delete_all(srv_provbox_box_type_enum box_type)
{
    U32 idx = 0;
    srv_provbox_result_enum delete_result = SRV_PROVBOX_RESULT_OK;
    srv_provbox_msg_delete_all_struct data = {0};
    
    
    while (box_type)
    {
        data.box_type = (srv_provbox_box_type_enum)(VAPP_PROV_GET_AVALIABLE_VALUE(box_type, idx));
        data.del_all_type = SRV_PROVBOX_DEL_ALL_MSG_MODE_UNDEFINED;
        data.sim_id = MMI_SIM_ALL;

        do 
        {
            delete_result = srv_provbox_msg_delete_all(&data);
        } while(SRV_PROVBOX_RESULT_CONTINUE == delete_result);
        
        VAPP_PROV_RESET_VALUE(box_type, idx, srv_provbox_box_type_enum);
        idx++;
    }
    
    return delete_result;
}
#endif 
/*****************************************************************************
 * Class VappOperateCell
 *****************************************************************************/
VfxU32 VappOperateCell::m_msgId    = 0;

void*  VappOperateCell::m_userData = NULL;

VAPP_PROV_CB_FUNC_P VappOperateCell::m_pCbFunc = NULL;


VfxBool VappOperateCell::onGetCell(VappOperateCell **cell)
{
    if (NULL == cell || NULL == m_userData)
    {
        return VFX_FALSE;
    }        
	
    (*cell)->m_userData = m_userData;
    (*cell)->m_pCbFunc  = m_pCbFunc;

    return VFX_TRUE;
}


VfxBool VappOperateCell::onResetCell()
{
    if (NULL == m_userData)
    {
        return VFX_FALSE;
    }

    m_userData = NULL;
    m_msgId    = 0;
    m_pCbFunc  = NULL;

    return VFX_TRUE;
}

VfxBool VappOperateCell::onSetCell(VfxU32 msg_id, void * op_obj, VAPP_PROV_CB_FUNC_P cb_func)
{
    // 0 is unvailable message id. and if try set operation object, op_obj is not NULL
    if (NULL == op_obj || 0 == msg_id || m_msgId)
    {        
        return VFX_FALSE;
    }    
    
    m_msgId    = msg_id;
    m_userData = op_obj;
    m_pCbFunc  = cb_func;

    return VFX_TRUE;
}

/*****************************************************************************
 * Class VappOperateCell end
 *****************************************************************************/


/*****************************************************************************
 * Class VappProvViewerCp
 *****************************************************************************/

VappProvViewerCp::VappProvViewerCp(VfxU32 type, VfxU32 msgId, VfxU32 msgType) :
                      VappMsgViewerCp(type, msgId, msgType),
					  m_timeStamp(0),
                      m_textMsgTime(NULL),
                      m_textMsgSize(NULL),
                      m_textMsgTitle(NULL),
                      m_provMsgOp(NULL)
{
}

void VappProvViewerCp::onInit()
{
    VappMsgViewerCp::onInit();

    if (VAPP_MSG_VIEWER_LITE == m_viewerType)
    {        
        getMsgProperties();
        setInstallBtn();
    }
    else
    {
        VFX_OBJ_CREATE(m_textMsgTime, VfxTextFrame, this);
    }
}

void VappProvViewerCp::onDeinit()
{
	VfxBool result;
	vapp_cca_close_popup(result, NULL);
    onInstallMsgDone(VFX_TRUE);
    VappMsgViewerCp::onDeinit();
}

VfxU32 VappProvViewerCp::getTimestamp()
{
	return m_timeStamp;
}

void VappProvViewerCp::setTextShow(
                           VfxTextFrame **text, 
                           const VfxWString &value, 
                           const VfxColor &color,
                           const VfxFontDesc &fontDesc)
{
    /* create time text viewer */
    (*text)->setString(value);
    (*text)->setColor(color);
    (*text)->setFont(fontDesc);  
}


void VappProvViewerCp::forceUpdate()
{
    switch (m_viewerType)
    {
        case VappMsgViewerCp::VAPP_MSG_VIEWER_LITE:
        {
            VfxU32 viewerWidth;
            VfxU32 viewerHeigth;
            VfxU32 space = VAPP_PROV_VIEW_FULL_SIZE_AND_TITLE_OFFSET;
            VfxU32 titleAndSizeHeigth = m_textMsgTitle->getSize().height + m_textMsgSize->getSize().height;

            viewerWidth = m_textMsgTitle->getSize().width + 
                          VAPP_PROV_VIEW_LITE_INSTALL_BTN_SPACE + 
                          VAPP_PROV_VIEW_LITE_INSTALL_BTN_WIDTH;

            viewerHeigth = VAPP_PROV_VIEW_LITE_INSTALL_BTN_HEIGHT > 
                           (titleAndSizeHeigth + space) ?
                           VAPP_PROV_VIEW_LITE_INSTALL_BTN_HEIGHT : 
                           (titleAndSizeHeigth + space);

            if (VAPP_PROV_VIEW_LITE_INSTALL_BTN_HEIGHT == viewerHeigth)
            {
                VfxU32 offsetY = (viewerHeigth - titleAndSizeHeigth)/2;
                m_textMsgTitle->setPos(0, offsetY);
                m_textMsgSize->setPos(0, offsetY + space + m_textMsgTitle->getSize().height);
            }

            setSize(viewerWidth, viewerHeigth);            
        }
        break;
        
        case VappMsgViewerCp::VAPP_MSG_VIEWER_FULL:
        {
            setSize(getParentFrame()->getSize().width , getParentFrame()->getSize().height);            
        }
        break;

        default:
            VFX_ASSERT(0); //"Invalidable message viewer type!"
            break;
    }
}

void VappProvViewerCp::setMsgTitleSizeTime(srv_provbox_msg_properties_struct *detail)
{
    VfxFontDesc ttfont,sfont,tfont;    
    VfxU16 sizeBuf[DETAIL_DATA_BUF_SIZE] = {0};
    VfxColor ttcolor,scolor;
    S16 msgSize;

    ttfont.size = VFX_FONT_DESC_VF_SIZE(VAPP_PROV_TITLE_FONT_SIZE);
    VFX_OBJ_CREATE(m_textMsgTitle, VfxTextFrame, this);

    sfont.size = VFX_FONT_DESC_VF_SIZE(VAPP_PROV_SIZE_FONT_SIZE);
    if (1024 <= detail->msg_size)
    {
        msgSize = detail->msg_size / 1024;
        kal_wsprintf((WCHAR *)sizeBuf, "%w: %dKB", get_string(STR_ID_VAPP_PROV_MSG_SIZE), msgSize);
    }
    else
    {
        msgSize = detail->msg_size;
        kal_wsprintf((WCHAR *)sizeBuf, "%w: %dB", get_string(STR_ID_VAPP_PROV_MSG_SIZE), msgSize);
    }
    /* create message size text viewer */
    if (NULL == m_textMsgSize)
    {
        VFX_OBJ_CREATE(m_textMsgSize, VfxTextFrame, this);
    }
    /* set message size posation */
	
    if (VAPP_MSG_VIEWER_FULL == m_viewerType)
    {
        WCHAR data_time[DETAIL_DATA_BUF_SIZE] = {0};
        vapp_prov_compose_data_time(data_time, detail->cmn_info.timestamp);

        tfont.size = VFX_FONT_DESC_VF_SIZE(VAPP_PROV_TIME_FONT_SIZE);

        ttcolor = VFX_COLOR_RES(CLR_ID_VAPP_PROV_MSG_VIEW_FONT_COLOR);
        scolor = VRT_COLOR_MAKE(255, 154, 154, 154);

        setTextShow(&m_textMsgTime, VFX_WSTR_MEM((VfxU16 *)data_time), 
        VRT_COLOR_MAKE(255, 154, 154, 154), tfont);
    }
    else
    {
        m_timeStamp = detail->cmn_info.timestamp;
        ttcolor = VFX_COLOR_RES(CLR_ID_VAPP_PROV_MSG_PROV_TEXT_FONT_COLOR);//review
        scolor = VFX_COLOR_RES(CLR_ID_VAPP_PROV_MSG_PROV_SIZE_FONT_COLOR);//review
    }
    setTextShow(&m_textMsgTitle, VFX_WSTR_RES(STR_ID_VAPP_PROV_MSG_CNFIG),
        ttcolor, ttfont);
    setTextShow(&m_textMsgSize, VFX_WSTR_MEM(sizeBuf), 
        scolor, sfont);

}

void VappProvViewerCp::setInstallBtn()
{
    //VfxBool   btn_valid;
    VcpButton *m_installBtn;
    VfxU32 titleWidth = m_textMsgTitle->getSize().width;

    VFX_OBJ_CREATE(m_installBtn, VcpButton, this);
    
    /* set button text font */
    VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(VAPP_PROV_BUTTON_FONT_SIZE);
    m_installBtn->setTextFont(font);

    /* set button text color */
    m_installBtn->setTextColor(VFX_COLOR_RES(CLR_ID_VAPP_PROV_MSG_CP_INSTALL_BTN_FONT_COLOR));

    /* set button text */
    m_installBtn->setText((VfxResId)STR_ID_VAPP_PROV_MSG_INSTALL);

    /* set button posation */
    m_installBtn->setRect(titleWidth + VAPP_PROV_VIEW_LITE_INSTALL_BTN_SPACE, 
                       VAPP_PROV_VIEW_LITE_INSTALL_BTN_Y_OFFSET, 
                       VAPP_PROV_VIEW_LITE_INSTALL_BTN_WIDTH, 
                       VAPP_PROV_VIEW_LITE_INSTALL_BTN_HEIGHT);
    
	m_installBtn->m_signalClicked.connect(this, &VappProvViewerCp::onInstallMsg);
    m_installBtn->setIsDisabled(VFX_FALSE);
}

void VappProvViewerCp::getMsgProperties()
{
    if (NULL == m_provMsgOp)
    {
        srv_provbox_msg_properties_struct details = {0};

        VFX_OBJ_CREATE(m_provMsgOp, VappProvMsgDataOp, this);

        details.msg_id = m_msgId;

        m_provMsgOp->onRead(&details);

        if (VAPP_MSG_VIEWER_LITE == m_viewerType)
        {
            m_syncNotify.connect(this, &VappProvViewerCp::onNotifyReady);
        }

        RecvMsgPorperties(&details);
    }
}


void VappProvViewerCp::RecvMsgPorperties(srv_provbox_msg_properties_struct* details)
{
    if (SRV_PROVBOX_RESULT_OK != details->result)
    {
        VcpProvCnfmPopup * m_deleteCnfmPopup;
        VfxWString tempStr;
		tempStr.loadFromRes(STR_GLOBAL_NOT_AVAILABLE);

        VFX_OBJ_CREATE_EX(m_deleteCnfmPopup, VcpProvCnfmPopup, findScreen(), 
            (tempStr, VCP_POPUP_TYPE_FAILURE, VCP_CONFIRM_BUTTON_SET_OK));

        m_deleteCnfmPopup->show(VFX_TRUE);
    } 
    else
    {
        setMsgTitleSizeTime(details);        
        onRefresh(getParentFrame()->getSize().width);
        if (VAPP_MSG_VIEWER_LITE == m_viewerType)
        {
            m_syncNotify.postEmit((MMI_BOOL)(SRV_PROVBOX_RESULT_OK == details->result));
        }
    }

    VFX_OBJ_CLOSE(m_provMsgOp);

    VappMsgViewerCp::onUpdate();
}


void VappProvViewerCp::onRefresh(VfxS32 frameWidth)
{
    VfxS32 xPos;
    VfxS32 yPos;
 
    /* set text msg title position */
    if (VAPP_MSG_VIEWER_LITE == m_viewerType)
    {
        xPos = 0;
        yPos = 0;
    }
    else
    {
        xPos = VAPP_PROV_VIEW_FULL_TEXT_X_OFFSET;
        yPos = VAPP_PROV_VIEW_FULL_TEXT_Y_OFFSET;
    }
    m_textMsgTitle->setPos(xPos, yPos);

    /* set text msg size position */
    if (VAPP_MSG_VIEWER_FULL == m_viewerType)
    {
        yPos = VAPP_PROV_VIEW_FULL_TEXT_X_OFFSET + 
               m_textMsgTitle->getSize().height + 
               VAPP_PROV_VIEW_FULL_SIZE_Y_OFFSET;
    }
    else
    {
        yPos = VAPP_PROV_VIEW_FULL_TEXT_X_OFFSET + 
               m_textMsgTitle->getSize().height;
    }
    m_textMsgSize->setPos(xPos, yPos);
    
    /* set text msg time position */
    if (VAPP_MSG_VIEWER_FULL == m_viewerType)
    {
        xPos = frameWidth - 
               m_textMsgTime->getSize().width - 
               VAPP_PROV_VIEW_FULL_TEXT_X_OFFSET;

        yPos = m_textMsgSize->getPos().y + 
               m_textMsgSize->getSize().height + 
               VAPP_PROV_VIEW_FULL_SIZE_AND_TIME_OFFSET;

        m_textMsgTime->setPos(xPos, yPos);
    }
}


void VappProvViewerCp::onNotifyReady(MMI_BOOL isRead)
{
    setContentReady(isRead? VFX_TRUE: VFX_FALSE);
}


void VappProvViewerCp::onInstallMsg(VfxObject *obj, VfxId id)
{
    /* if the process is in ansync install process, return from this function,
       and not do any operation */
    if (NULL == m_provMsgOp)
    {
    // If there is other installing message, not to install this message		
        if (m_isInstall)
        {
            MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "onInstallMsg m_isInstall true.");            
        }
        m_isInstall = VFX_TRUE;

        // Provide screen group id for cca to create cui
        vapp_prov_set_group_id(VfxMainScr::findMainScr((VfxFrame*)getParent())->getApp()->getGroupId());

        // Create provisioning message operate object
        VFX_OBJ_CREATE(m_provMsgOp, VappProvMsgDataOp, this);
        m_provMsgOp->m_signalOp.connect(this, &VappProvViewerCp::onInstallMsgDone);
        m_provMsgOp->install(m_msgId);
    }
}


void VappProvViewerCp::onInstallMsgDone(VfxU32 result)
{
    // If current message is installing message, reset cur_flag to clear install flag
    if (m_isInstall)
    {
        m_isInstall = VFX_FALSE;
        VappOperateCell::onResetCell();
    }

    if (m_provMsgOp)
    {
        VFX_OBJ_CLOSE(m_provMsgOp);
    }
}

/*****************************************************************************
 * Class VappProvViewerCp end
 *****************************************************************************/


/*****************************************************************************
 * Class VappProvDetailPage
 *****************************************************************************/

VappProvDetailPage::VappProvDetailPage(VfxU8 msgId, VfxU32 msgType) : 
						m_msgType(msgType),
						m_msgId(msgId),                        
                        m_origin(0, 0),
                        m_msgViewer(NULL),
                        m_provMsgOp(NULL),
                        m_msgContactBar(NULL)            
{
}

void VappProvDetailPage::onInit()
{
    VfxPage::onInit();
 
    VfxS32 scrnWidth = getParentFrame()->getSize().width;

    /* set page background color */
    setBgColor(CLR_ID_VAPP_PROV_MSG_BG_FONT_COLOR);

    /* create contact bar */
    VFX_OBJ_CREATE(m_msgContactBar, VappMsgContactBar, this);
    VfxS32 contactBarH = m_msgContactBar->getSize().height;
    m_msgContactBar->setSize(scrnWidth, contactBarH);

    /* set origin point */
    m_origin = VfxPoint(0, (m_msgContactBar->getPos().y + contactBarH - 1));
 
    /* create message full viewer */
    VFX_OBJ_CREATE_EX(m_msgViewer, VappProvViewerCp, this, (VappProvViewerCp::VAPP_MSG_VIEWER_FULL, m_msgId, m_msgType));
    m_msgViewer->setPos(m_origin.x, m_origin.y);
    m_msgViewer->setSize(scrnWidth, getParentFrame()->getSize().height - contactBarH);
    m_msgViewer->setBgColor(CLR_ID_VAPP_PROV_MSG_BG_FONT_COLOR);
    m_msgViewer->setAlignParent(
                     VFX_FRAME_ALIGNER_MODE_SIDE, 
                     VFX_FRAME_ALIGNER_MODE_SIDE, 
                     VFX_FRAME_ALIGNER_MODE_SIDE, 
                     VFX_FRAME_ALIGNER_MODE_SIDE);

    /* create tool bar */
	VcpToolBar *m_toolBar;
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);

    m_toolBar->addItem(VAPP_PROV_MSG_BTN_INSTALL, 
                   (VfxResId)STR_ID_VAPP_PROV_MSG_INSTALL, 
                   VCP_IMG_TOOL_BAR_COMMON_ITEM_INSTALL);

    m_toolBar->addItem(VAPP_PROV_MSG_BTN_DELETE,
                   (VfxResId)STR_GLOBAL_DELETE, 
                   VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);

    m_toolBar->m_signalButtonTap.connect(this, &VappProvDetailPage::onTapToolBar);

    setBottomBar(m_toolBar);
    getMsgProperties();
}

void VappProvDetailPage::onEntered()
{
    if(m_msgContactBar)
    {
        m_msgContactBar->onRotate();
    }
}

void VappProvDetailPage::onDeinit()
{
    intallDone(VFX_TRUE);
    VfxPage::onDeinit();
}

void VappProvDetailPage::onUpdate()
{
    VfxPage::onUpdate();

    VfxS32 scrnWidth  = getParentFrame()->getSize().width;
    VfxS32 scrnHeight = getParentFrame()->getSize().height;

    /* create contact bar */
    VfxS32 contactBarHeight = m_msgContactBar->getSize().height;
    VfxS32 viewerHeight     = getParentFrame()->getSize().height - contactBarHeight;

    /* set origin point */
    m_origin = VfxPoint(0, m_msgContactBar->getPos().y + contactBarHeight);

    /* set contact bar position */
    m_msgContactBar->setSize(scrnWidth, contactBarHeight);

    /* set full viewer position */
    m_msgViewer->setPos(m_origin.x, m_origin.y - 1);
    m_msgViewer->setSize(scrnWidth, viewerHeight);
    m_msgViewer->onRefresh(scrnWidth);
}
 

void VappProvDetailPage::onTapToolBar(VfxObject * obj, VfxId barId)
{
    switch(barId)
    {
        case VAPP_PROV_MSG_BTN_INSTALL:
        {
            // If there is other installing message, not to install this message             
            m_isInstall = VFX_TRUE;

            // Provide screen group id for cca to create cui
            vapp_prov_set_group_id(VfxMainScr::findMainScr((VfxFrame*)getParent())->getApp()->getGroupId());

            // Create provisioning message operate object
            VFX_OBJ_CREATE(m_provMsgOp, VappProvMsgDataOp, this);
            m_provMsgOp->m_signalOp.connect(this, &VappProvDetailPage::intallDone);
            m_provMsgOp->install(m_msgId);
        }
        break;
 
        case VAPP_PROV_MSG_BTN_DELETE:
        {
            VcpConfirmPopup * m_deleteCnfmPopup;
            VFX_OBJ_CREATE(m_deleteCnfmPopup, VcpConfirmPopup, getMainScr());
            m_deleteCnfmPopup->setText(VfxWString().loadFromRes(STR_ID_VAPP_PROV_MSG_DELETE_QUERY));
            m_deleteCnfmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_deleteCnfmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
            m_deleteCnfmPopup->setCustomButton(
                                   (VfxResId)STR_GLOBAL_DELETE, 
                                   (VfxResId)STR_GLOBAL_CANCEL, 
                                   VCP_POPUP_BUTTON_TYPE_WARNING, 
                                   VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_deleteCnfmPopup->m_signalButtonClicked.connect(this, &VappProvDetailPage::deleteMsg);
            m_deleteCnfmPopup->show(VFX_TRUE);
        }
        break;

        default:
            VFX_ASSERT(0);//"Novailable Tool Bar Button!"
            break;
    }
}
 
 
void VappProvDetailPage::deleteMsg(VfxObject * obj, VfxId barId)
{
    if (NULL != m_provMsgOp)
    {
        return;
    }

    if (VCP_CONFIRM_POPUP_BUTTON_YES == barId)
    {
        VFX_OBJ_CREATE(m_provMsgOp, VappProvMsgDataOp, this);

		if(VFX_TRUE != m_provMsgOp->onDelete(m_msgId))
		{
			VcpProvCnfmPopup * delCnfmPopup;
	        VfxWString tempStr;
			tempStr.loadFromRes(STR_GLOBAL_NOT_AVAILABLE);

	        VFX_OBJ_CREATE_EX(delCnfmPopup, VcpProvCnfmPopup, getMainScr(), 
	            (tempStr, VCP_POPUP_TYPE_FAILURE, VCP_CONFIRM_BUTTON_SET_OK));

	        delCnfmPopup->show(VFX_TRUE);
		}
		else
		{
			 this->exit();
		}

		 VFX_OBJ_CLOSE(m_provMsgOp);
    }
}
 
 
void VappProvDetailPage::getMsgProperties()
{
    if (NULL == m_provMsgOp)
    {
        srv_provbox_msg_properties_struct details = {0};

        details.msg_id = m_msgId;

        VFX_OBJ_CREATE(m_provMsgOp, VappProvMsgDataOp, this);
        m_provMsgOp->onRead(&details);
        recvMsgProperties(&details);
    }
}


void VappProvDetailPage::recvMsgProperties(srv_provbox_msg_properties_struct *detail)
{
    mmi_rp_app_cosmos_global_img_enum simFlag = IMG_COSMOS_SIM1;
    if (SRV_PROVBOX_RESULT_OK != detail->result)
    {
        VcpProvCnfmPopup * failCnfmPopup;
        VfxWString tempStr;
		tempStr.loadFromRes(STR_GLOBAL_NOT_AVAILABLE);

        VFX_OBJ_CREATE_EX(failCnfmPopup, VcpProvCnfmPopup, getMainScr(), 
            (tempStr, VCP_POPUP_TYPE_FAILURE, VCP_CONFIRM_BUTTON_SET_OK));

        failCnfmPopup->show(VFX_TRUE);

        this->exit();
    } 
    else
    {
        WCHAR msg_addr[VAPP_PROV_MSG_SEND_ADDR_MAX_LEN] = {0};
        vapp_prov_msg_addr_type_enum addr_type;
        VfxWString contact;

        m_msgViewer->setMsgTitleSizeTime(detail);
        m_msgViewer->onRefresh(getParentFrame()->getSize().width);

        vapp_prov_get_available_msg_address(msg_addr, &addr_type, &(detail->cmn_info.sender_addr));

        if (VAPP_PROV_MSG_ADDR_TYPE_NUM == addr_type)
        {
            m_msgContactBar->setContact(contact.loadFromMem((VfxWChar *)msg_addr), VAPP_MSG_CONTACT_TYPE_PHONENUMBER);
        }
        else if (VAPP_PROV_MSG_ADDR_TYPE_STR == addr_type)
        {
             m_msgContactBar->setContact(contact.loadFromRes(STR_ID_VAPP_PROV_MSG_NO_NUMBER), VAPP_MSG_CONTACT_TYPE_ALPHANUMBIC);
        }
         
    #if (MMI_MAX_SIM_NUM >= 2)
        if (MMI_SIM1 == detail->cmn_info.sim_id)
        {
            simFlag = IMG_COSMOS_SIM1;
        }		
        else if (MMI_SIM2 == detail->cmn_info.sim_id)
        {
            simFlag = IMG_COSMOS_SIM2;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        else if (MMI_SIM3 == detail->cmn_info.sim_id)
        {
            simFlag = IMG_COSMOS_SIM3;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        else if (MMI_SIM4 == detail->cmn_info.sim_id)
        {
            simFlag = IMG_COSMOS_SIM4;
        }
    #endif
        m_msgContactBar->setRightIcon(VfxImageSrc(simFlag), VfxImageSrc(IMG_ID_VAPP_PROV_MSG_INDICTOR_ICON));
    #else
        m_msgContactBar->setRightIcon(VfxImageSrc(IMG_ID_VAPP_PROV_MSG_INDICTOR_ICON));
    #endif
    }
    VFX_OBJ_CLOSE(m_provMsgOp);
}


void VappProvDetailPage::intallDone(VfxU32 result)
{
    // If current message is installing message, reset cur_flag to clear install flag
    if (m_isInstall)
    {
        m_isInstall = VFX_FALSE;
        VappOperateCell::onResetCell();
    }
    if (NULL != m_provMsgOp)
    {
        VFX_OBJ_CLOSE(m_provMsgOp);
    }
        
}

void VappProvDetailPage::onRotate(const VfxScreenRotateParam & param)
{
    if(NULL != m_msgContactBar)
    {
        m_msgContactBar->onRotate();
    }
}
/*****************************************************************************
 * Class VappProvDetailPage end
 *****************************************************************************/

/*****************************************************************************
 * Class VappProvMsgDataOp
 *****************************************************************************/

VappProvMsgDataOp::VappProvMsgDataOp() : m_isOperating(VFX_FALSE), m_msgId(0)
{
}

void VappProvMsgDataOp::onDeinit()
{
    VfxObject::onDeinit();

    m_isOperating = VFX_FALSE;
    m_msgId       = 0;
}


void VappProvMsgDataOp::onRead(srv_provbox_msg_properties_struct *detail)
{
    if (VFX_FALSE == m_isOperating)
    {
        m_msgId = detail->msg_id;
        srv_provbox_msg_get_properties(detail);
    }
}

VfxBool VappProvMsgDataOp::onDelete(VfxU32 msgId)
{
   VfxBool deleteResult = VFX_FALSE;


   if (VFX_FALSE == m_isOperating)
   {
       m_msgId       = msgId;

       if (SRV_PROVBOX_RESULT_OK == srv_provbox_msg_delete(msgId))
       {
           deleteResult = VFX_TRUE;
       }
   }

   return deleteResult;
}


void VappProvMsgDataOp::install(VfxU32 msgId)
{
   if (VFX_FALSE == m_isOperating)
   {
       m_isOperating = VFX_TRUE;
       m_msgId       = msgId;

       if (VFX_FALSE == VappOperateCell::onSetCell(m_msgId, (void*)this, NULL))
       {
           m_signalOp.emit(VFX_FALSE);
       }
       vapp_prov_msg_sent_install_req(msgId, VAPP_PROV_TRANS_ID_CCA_PROCESS_MSG);
   }
}

U8 VappProvMsgDataOp::onInstallMsgHdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappProvMsgDataOp *curObj = NULL;
    srv_cca_process_prov_msg_cnf_struct *data;
    VappOperateCell *cell = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_process_prov_msg_cnf_struct*) msg;


    if (data->trans_id != VAPP_PROV_TRANS_ID_CCA_PROCESS_MSG || VFX_FALSE == VappOperateCell::onGetCell(&cell))
    {
        return MMI_RET_OK;
    }

    curObj = (VappProvMsgDataOp *)cell->m_userData;

    /* The reason of this judge is that re-entry messaging from n-center
       when installing a provisioning message. During re-entry process, all
       message page should be close, so current object is available. If this
       case is invoked, curObj should be reset to NULL, and do the follow 
       judge when receive install cnf primitive message. */ 
    if (NULL == curObj)
    {
        return MMI_RET_OK;
    }
    /* This place should pay attantion on handling */
    /* There are two cases on this fucntion. Firstly, in the normal process
       the follow judge is true. and program would notify cp or page to update.
       On the other handle, the case is re-entry messaging from n-center when 
       there are miss calls or unread sms. In this process, UM will delete the 
       related page or object, so curObj is dirty object. So do not handle curObj.
       So in this case, program just would unlock. */ 
    if (curObj->m_isOperating)
    {
        if (curObj->m_msgId != data->msg_id)
        {
            VFX_ASSERT(0);
        }
        curObj->m_signalOp.emit(data->status);
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * Class VappProvMsgDataOp end
 *****************************************************************************/
#endif /* __MMI_PROV_IN_UM__  */

