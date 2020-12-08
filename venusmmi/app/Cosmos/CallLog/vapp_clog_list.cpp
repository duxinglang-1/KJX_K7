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
 *  vapp_clog_list.cpp
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
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_menu_popup.h"
#include "vcp_list_menu.h"
#include "vtst_rt_main.h"

#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vdat_systime.h"
#include "vfx_app_scr.h"
#include "vfx_adp_device.h"
#include "vsrv_ncenter.h"

#include "vapp_phb_gprot.h"
#include "vapp_phb_launch.h"

#include "vapp_clog_config.h"
#include "vapp_clog_ui.h"
#include "vapp_clog_action.h"
#include "vapp_clog_data_provider.h"
#include "vapp_phb_gprot.h"

#include "../xml/vfx_xml_loader.h"


/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#include "MMI_include.h"
#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "GlobalResdef.h"
#include "mmi_frm_utility_gprot.h"

#include "DateTimeType.h"     // for mmi_dt_utc_sec_2_mytime
#include "App_datetime.h"     // for applib_time_struct
#include "NwUsabSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "Phbsrvgprot.h"
#include "CallLogSrvGprot.h"
#include "mmi_rp_vapp_calllog_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"
#include "vapp_clog_gprot.h"
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
typedef struct
{
    mmi_sim_enum sim_id;
    srv_clog_call_type_enum call_type; // just suport voice and video type
    VfxResId normal_iconId;
    VfxResId pressed_iconId;
    VfxResId hightlight_iconId;
    VfxResId disable_iconId;
} vapp_clog_list_call_button_struct;

enum VappClogListCallButtonStatusEnum
{
    VAPP_CLOG_LIST_BUT_IMG_NORMAL,         // Image of the normal command button
    VAPP_CLOG_LIST_BUT_IMG_PRESSED,        // Image of the pressed command button 
    VAPP_CLOG_LIST_BUT_IMG_HIGHLIGHT,      // Image of the highlight command button
    VAPP_CLOG_LIST_BUT_IMG_DISABLED,       // Image of the disabled command button
    VAPP_CLOG_LIST_BUT_IMG_MAX
};


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static const vapp_clog_list_call_button_struct vapp_clog_list_call_button_id[] =
{
#if (MMI_MAX_SIM_NUM <= 0)    
    {MMI_SIM1, SRV_CLOG_CALL_TYPE_VOICE, IMG_ID_VAPP_CLOG_CALL_SIM1_N, IMG_ID_VAPP_CLOG_CALL_SIM1_P, IMG_ID_VAPP_CLOG_CALL_SIM1_P, IMG_ID_VAPP_CLOG_CALL_SIM1_D},
#if (MMI_MAX_SIM_NUM >= 2)
    {MMI_SIM2, SRV_CLOG_CALL_TYPE_VOICE, IMG_ID_VAPP_CLOG_CALL_SIM2_N, IMG_ID_VAPP_CLOG_CALL_SIM2_P, IMG_ID_VAPP_CLOG_CALL_SIM2_P, IMG_ID_VAPP_CLOG_CALL_SIM2_D},
#endif
#else /* (MMI_MAX_SIM_NUM <= 2) will be geimini+ project*/
    {MMI_SIM1, SRV_CLOG_CALL_TYPE_VOICE, IMG_COSMOS_GEMINI_SIM1_LIST_CALL_N, IMG_COSMOS_GEMINI_SIM1_LIST_CALL_P, IMG_COSMOS_GEMINI_SIM1_LIST_CALL_P, IMG_COSMOS_GEMINI_SIM1_LIST_CALL_D},
    {MMI_SIM2, SRV_CLOG_CALL_TYPE_VOICE, IMG_COSMOS_GEMINI_SIM2_LIST_CALL_N, IMG_COSMOS_GEMINI_SIM2_LIST_CALL_P, IMG_COSMOS_GEMINI_SIM2_LIST_CALL_P, IMG_COSMOS_GEMINI_SIM2_LIST_CALL_D},
    {MMI_SIM3, SRV_CLOG_CALL_TYPE_VOICE, IMG_COSMOS_GEMINI_SIM3_LIST_CALL_N, IMG_COSMOS_GEMINI_SIM3_LIST_CALL_P, IMG_COSMOS_GEMINI_SIM3_LIST_CALL_P, IMG_COSMOS_GEMINI_SIM3_LIST_CALL_D},
#if (MMI_MAX_SIM_NUM >= 4)
    {MMI_SIM4, SRV_CLOG_CALL_TYPE_VOICE, IMG_COSMOS_GEMINI_SIM4_LIST_CALL_N, IMG_COSMOS_GEMINI_SIM4_LIST_CALL_P, IMG_COSMOS_GEMINI_SIM4_LIST_CALL_P, IMG_COSMOS_GEMINI_SIM4_LIST_CALL_D},
#endif
#endif
#ifdef __MMI_VIDEO_TELEPHONY__
    {MMI_SIM1, SRV_CLOG_CALL_TYPE_VIDEO, IMG_ID_VAPP_CLOG_CALL_VIDEO_N, IMG_ID_VAPP_CLOG_CALL_VIDEO_P, IMG_ID_VAPP_CLOG_CALL_VIDEO_P, IMG_ID_VAPP_CLOG_CALL_VIDEO_D},
#endif

};

/***************************************************************************** 
 * Function
 *****************************************************************************/
static MMI_ID vapp_clog_launch_from_phb(VappCLogListIDEnum listId)
{
    vapp_phb_sub_app_launch_struct phb_struct;
    phb_struct.sub_app = VAPP_PHB_SUB_APP_CLOG;
    // temp solution for VFX slim 
    // remove using VFX_SYS_ALLOC_MEM
    // and use address to record listId
    phb_struct.user_data = (void *)listId;

    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_LAUNCH_FROM_PHB, listId, phb_struct.user_data);
    
    return vapp_phb_launch(&phb_struct, sizeof(vapp_phb_sub_app_launch_struct));
}


extern "C" MMI_ID vapp_clog_launch(void* param, U32 param_size)
{
    return vapp_clog_launch_from_phb(VAPP_CLOG_LIST_ID_ALL_CALL);
}


extern "C" void vapp_clog_mclt_launch(void)
{
    vapp_clog_launch_from_phb(VAPP_CLOG_LIST_ID_MISSED_CALL);
}


extern "C" void vapp_clog_aclt_launch(void)
{
    vapp_clog_launch_from_phb(VAPP_CLOG_LIST_ID_ALL_CALL);
}


extern "C" void vapp_clog_scrlock_launch(void)
{
    VfxU32 unread_num = srv_clog_get_unread_missed_call_num();
    if(unread_num)
        vapp_clog_mclt_launch();
    else
        vapp_clog_aclt_launch();
}


VtstTestResultEnum vtst_callog_launch(VfxU32 param)
{
    vapp_clog_launch_from_phb(VAPP_CLOG_LIST_ID_MISSED_CALL);
    return VTST_TR_OK;
}


VfxResId vapp_clog_get_list_call_button_id(mmi_sim_enum sim_id, srv_clog_call_type_enum call_type, VappClogListCallButtonStatusEnum btn_status)
{
    VfxS32 i;
    for (i = 0; i < (sizeof(vapp_clog_list_call_button_id) / sizeof(vapp_clog_list_call_button_struct)); i++)
    {
        if (sim_id == vapp_clog_list_call_button_id[i].sim_id && call_type == vapp_clog_list_call_button_id[i].call_type)
        {
            switch (btn_status)
            {
                case VAPP_CLOG_LIST_BUT_IMG_NORMAL:
                    return vapp_clog_list_call_button_id[i].normal_iconId;

                case VAPP_CLOG_LIST_BUT_IMG_PRESSED:
                    return vapp_clog_list_call_button_id[i].pressed_iconId;

                case VAPP_CLOG_LIST_BUT_IMG_HIGHLIGHT:    
                    return vapp_clog_list_call_button_id[i].hightlight_iconId;

                case VAPP_CLOG_LIST_BUT_IMG_DISABLED:
                    return vapp_clog_list_call_button_id[i].disable_iconId;

                default:
                    return 0;
            }
        }
    }
    return 0;
}


/*****************************************************************************
 * Class VappCLogList
 *****************************************************************************/

/*VappCLogList::VappCLogList() :
    m_CLogList(NULL),
    m_currListID(VAPP_CLOG_LIST_ID_ALL_CALL),
    m_currPageType(VAPP_CLOG_PAGE_BASIC),
    m_b2ndReady(VFX_FALSE),
    m_currClogItemID(0),
    m_action(NULL),
    m_toolBar(NULL),
    m_segBtn(NULL),
    m_storeIndex(0),
    m_clogDataSrv(NULL),
    m_currSIMID(MMI_SIM_NONE) // don't care this varible
#ifdef __MMI_CLOG_MARK_SEVERAL__
    ,m_mark(NULL),
    m_deleteObj(NULL)
#endif
{
    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_LIST_DEFAULT_CONSTRUCTOR);
	
#ifdef __MMI_CLOG_MARK_SEVERAL__
	m_cmd = VAPP_CLOG_MARK_CMD_NONE;
#endif
}*/


VappCLogList::VappCLogList(VappCLogPageTypeEnum pageType,
                 VfxBool b2ndReady,
                 VappCLogListIDEnum listID, 
                 VfxU16 store_idx,
                 mmi_sim_enum sim_id
                 ) :
    m_CLogList(NULL),
    m_currListID(listID),
    m_currPageType(pageType),
    m_b2ndReady(b2ndReady),
    m_currClogItemID(0),
    m_action(NULL),
    m_toolBar(NULL),
    m_segBtn(NULL),
    m_storeIndex(store_idx),
    m_clogDataSrv(NULL),
    m_currSIMID(sim_id)
#ifdef __MMI_CLOG_MARK_SEVERAL__
    ,m_mark(NULL),
    m_deleteObj(NULL)
#endif
{
    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_LIST_CONSTRUCTOR, pageType, listID, store_idx, sim_id);

#ifdef __MMI_CLOG_MARK_SEVERAL__
    m_cmd = VAPP_CLOG_MARK_CMD_NONE;
#endif
}


void VappCLogList::onInit()
{
    VfxPage::onInit(); // call base class
    
    VFX_OBJ_CREATE(m_action, VppCLogAction, this);    
    VFX_OBJ_CREATE(m_showTimer, VfxTimer, this);
    VFX_OBJ_CREATE(m_CLogList, VcpListMenu, this);
    m_CLogList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_CLogList->setItemHeight(VCP_LIST_MENU_CELL_HEIGHT_MULTI_LINE);
    // For performance enhancement
    if (!m_b2ndReady)
    {
        m_CLogList->setContentProvider(this);
    }
    else
    {
        m_CLogList->setContentProvider(NULL);
    }
    
    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_LIST_ONINIT, m_currPageType);
    
    if (m_currPageType == VAPP_CLOG_PAGE_BASIC)
    {
        VFX_OBJ_CREATE_EX(m_clogDataSrv, VappCLogDataProvider, this, (VAPP_CLOG_PAGE_BASIC));
        
    #ifdef __MMI_CLOG_MARK_SEVERAL__
	    setListMode(VAPP_CLOG_LIST_NORMAL);
    #else
        m_CLogList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
    #endif
        m_CLogList->setSize(getSize());
        m_CLogList->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);
            
        m_CLogList->m_signalItemTapped.connect(this, &VappCLogList::onItemShortTapped);
        m_CLogList->m_signalItemLongTapped.connect(this, &VappCLogList::onItemLongTapped);
        m_CLogList->m_signalCmdButtonClicked.connect(this, &VappCLogList::onListCmdBtnClick);

        VfxId listId;
        void * user_data = ((VappPhbApp *)getApp())->getUserData(VAPP_PHB_SUB_APP_CLOG);
        if (user_data)
        {
            // temp solution for VFX slim
            // use address to record listId
            listId = (VfxId)user_data;
            MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_LIST_ONINIT_BASIC, m_currPageType, listId, user_data);
            m_currListID = listId;
        }
        else
        {
            listId = m_currListID;
            MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_LIST_ONINIT_BASIC, m_currPageType, listId, user_data);
        }
        m_currListID = (VappCLogListIDEnum) listId;
        
        initToolBar();

        m_clogDataSrv->m_signalClogUpdated.connect(this, &VappCLogList::onUpdateClogList);
    }
    else if (m_currPageType == VAPP_CLOG_PAGE_FOR_DIALER)
    {        
        VFX_OBJ_CREATE_EX(m_clogDataSrv, VappCLogDataProvider, this, (VAPP_CLOG_PAGE_BASIC));
        m_clogDataSrv->getClogIDs(VAPP_CLOG_LIST_ID_ALL_CALL);
        
//        m_CLogList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);       
        m_CLogList->setSize(getSize());
        m_CLogList->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);
        
        m_CLogList->m_signalItemTapped.connect(this, &VappCLogList::onItemShortTapped);
        
        m_clogDataSrv->m_signalClogUpdated.connect(this, &VappCLogList::onUpdateClogList);
    }
#ifdef __MMI_PHB_VIEW_CALLOG__
    else
    {
        VFX_OBJ_CREATE_EX(m_clogDataSrv, VappCLogDataProvider, this, (VAPP_CLOG_PAGE_FOR_CONTACT));

        VfxFrame *bg;
        VFX_OBJ_CREATE(bg, VfxFrame, this);
        bg->setSize(getSize().width, TOP_CONTROL_HEIGHT);
        bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        bg->setImgContent(VfxImageSrc(VCP_IMG_LIST_MENU_TOP_SHADOW_U));
        bg->setPos(0, 0);
        bg->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_NONE);

        VFX_OBJ_CREATE(m_str, VfxTextFrame, this);
        m_str->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(MAIN_STR_FONT)));
        m_str->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_str->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
        m_str->setPos(LEFT_GAP, bg->getSize().height / 2);
        m_str->setAnchor(0, 0.5);
        m_str->setSize(getSize().width - LEFT_GAP - RIGHT_GAP - STR_BTN_GAP - BTN_WIDTH, 
                            MAIN_STR_FONT + 4);
        m_str->setString(VFX_WSTR_EMPTY);
        m_str->setAutoResized(VFX_FALSE);
        m_str->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE);

        VFX_OBJ_CREATE(m_button, VcpButton, this);
        m_button->setAnchor(1, 0);
        m_button->setPos(getSize().width - RIGHT_GAP, BTN_UP);
        m_button->setSize(BTN_WIDTH, BTN_HEIGHT);
        m_button->setIsDisabled(VFX_TRUE);
        m_button->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_NONE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_NONE);
        
        VfxWChar name[MMI_PHB_NAME_LENGTH + 1] = {0};
        srv_phb_get_name(m_storeIndex,(U16 *)name, MMI_PHB_NAME_LENGTH);
        if (name[0] != 0)
            //m_str->setString(VFX_WSTR_MEM(name));
            m_str->setString(name);
        else
           // m_str->setString(VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNNAMED));
            m_str->setString(STR_ID_VAPP_CLOG_UNNAMED);
        m_button->setText(STR_GLOBAL_CLEAR);
        m_button->setId(VAPP_CLOG_BTN_DELETE_FOR_ONE_CONTACT);
        m_action->setDataSrv(m_clogDataSrv);
        m_button->m_signalClicked.connect(m_action, &VppCLogAction::onButtonClicked);
        
        // draw line
        VfxImageFrame *seperator;
        VFX_OBJ_CREATE(seperator, VfxImageFrame, this);
        seperator->setResId(IMG_COSMOS_SEPARATOR_LINE);
        seperator->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        seperator->setPos(0, bg->getSize().height - CONTACT_INFO_SEPERATOR_LINE_HEIGHT);
        seperator->setSize(getSize().width, CONTACT_INFO_SEPERATOR_LINE_HEIGHT);
        seperator->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE);
        
        m_clogDataSrv->getClogIDsWithSamePHB(m_storeIndex);

        m_CLogList->setRect(0, bg->getSize().height,
            getSize().width, getSize().height - bg->getSize().height);
        m_CLogList->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);
        
        m_CLogList->m_signalItemTapped.connect(this, &VappCLogList::onItemShortTapped);

        m_clogDataSrv->m_signalGetClogCbDone.connect(this, &VappCLogList::onUpdatePageForContact);
        m_clogDataSrv->m_signalClogUpdated.connect(this, &VappCLogList::onUpdateClogList);
        mmi_frm_cb_reg_event(EVT_ID_PHB_UPD_CONTACT, &VappCLogList::onPhbContactChanged, this);
    }
    #endif
    regListener();
}


void VappCLogList::onDeinit()
{
    deregListener();

    m_clogDataSrv->m_signalClogUpdated.disconnect(this, &VappCLogList::onUpdateClogList);    
#ifdef __MMI_PHB_VIEW_CALLOG__
    if (m_currPageType == VAPP_CLOG_PAGE_FOR_CONTACT)
    {
        m_clogDataSrv->m_signalGetClogCbDone.disconnect(this, &VappCLogList::onUpdatePageForContact);
        mmi_frm_cb_dereg_event(EVT_ID_PHB_UPD_CONTACT, &VappCLogList::onPhbContactChanged, this);
    }
#endif   
    VfxPage::onDeinit(); // call base class
}


void VappCLogList::onEnter(VfxBool isBackward)
{
    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_LIST_ONENTER, m_currPageType, isBackward);
    
    vapp_clog_check_nmgr_alert();
    VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_CALLLOG, 0);

    m_showTimer->setStartDelay(1);
    m_showTimer->m_signalTick.connect(this, &VappCLogList::showlistscreen);
    m_showTimer->start();
    vapp_clog_evt_struct evt; 
    evt.userdata = getObjHandle();
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_CLOG_APP_ENTER);
    MMI_FRM_CB_EMIT_EVENT(&evt);
    m_action->setGroupId(getApp()->getGroupId());
    m_action->setAppScr(getMainScr());
}

void VappCLogList::showlistscreen(VfxTimer *timer)
{
    m_clogDataSrv->clearUnreadMissedCount();
}

void VappCLogList::onExit(VfxBool isBackward)
{
    m_showTimer->stop();
}


#ifdef __MMI_CLOG_MARK_SEVERAL__
void VappCLogList::onBack()
{
    if (m_cmd == VAPP_CLOG_MARK_CMD_DELETE)
    {
        onMultiDeleteEnd();

		VFX_OBJ_CLOSE(m_deleteObj);
    }
    else
    {
        VfxPage::onBack();
    }
}
#endif


void VappCLogList::onQueryRotateEx(VfxScreenRotateParam &param)
{
#ifdef __MMI_PHB_VIEW_CALLOG__
  if (VAPP_CLOG_PAGE_FOR_CONTACT != m_currPageType)
#endif
    {
        param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
    }
}


void VappCLogList::initToolBar()
{
    VFX_OBJ_CREATE(m_toolBar,VcpToolBar,this);

	m_toolBar->m_signalButtonTap.connect(this, &VappCLogList::onToolBarClick);
	setBottomBar(m_toolBar);
    
    m_seg_frame = m_toolBar->addControlFrame(VCP_TOOL_BAR_SEGMENT_BUTTON_COUNT_TWO);    
    m_seg_frame->m_signalBoundsChanged.connect(this, &VappCLogList::onBoundsChanged);
    VFX_OBJ_CREATE(m_segBtn, VcpSegmentButton, m_seg_frame);
    //m_segBtn->setPos(8, 6);
    m_segBtn->setSize(m_seg_frame->getSize());
    //m_segBtn->setSize(170, 39);
    m_segBtn->setType(VCP_SEGMENT_BUTTON_TYPE_RADIO);
    m_segBtn->setStyle(VCP_SEGMENT_BUTTON_STYLE_TEXT_ONLY);
    // Create 2 buttoned segment button
    VcpStateImage allCallsImg, missedCallsImg;
	//allCallsImg.setImage(0, 0, 0, 0);
	//missedCallsImg.setImage(0, 0, 0, 0);
    m_segBtn->addButton(SEGMENT_BTN_ALL_CALL, allCallsImg, VFX_WSTR_RES(STR_ID_VAPP_CLOG_ALL));
    m_segBtn->addButton(SEGMENT_BTN_MISSED_CALL, missedCallsImg, VFX_WSTR_RES(STR_ID_VAPP_CLOG_MISSED));
    // Connect segment button with your own callback
    m_segBtn->m_signalButtonClicked.connect(this, &VappCLogList::onToolBarClick); // common button click func
    
#ifdef __MMI_CLOG_MARK_SEVERAL__
    m_toolBar->addItem(BOTTOM_BTN_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
#else
	m_toolBar->addItem(BOTTOM_BTN_CLEAR, VFX_WSTR_RES(STR_GLOBAL_CLEAR), VCP_IMG_TOOL_BAR_COMMON_ITEM_CLEAR);
#endif

    updataToolBarStatus();
}


void VappCLogList::updataToolBarStatus()
{
//    if (m_currPageType != VAPP_CLOG_PAGE_BASIC)
//        return;
    
    if (m_currListID == VAPP_CLOG_LIST_ID_ALL_CALL)
        m_segBtn->setButtonIsHighlighted(SEGMENT_BTN_ALL_CALL, VFX_TRUE);
    else
        m_segBtn->setButtonIsHighlighted(SEGMENT_BTN_MISSED_CALL, VFX_TRUE);
    
    if (m_clogDataSrv->getClogCount(m_currListID) == 0)
    #ifdef __MMI_CLOG_MARK_SEVERAL__
        m_toolBar->setDisableItem(BOTTOM_BTN_DELETE, VFX_TRUE);
    #else
        m_toolBar->setDisableItem(BOTTOM_BTN_CLEAR, VFX_TRUE);
    #endif
    else
    #ifdef __MMI_CLOG_MARK_SEVERAL__
	    m_toolBar->setDisableItem(BOTTOM_BTN_DELETE, VFX_FALSE);
    #else
        m_toolBar->setDisableItem(BOTTOM_BTN_CLEAR, VFX_FALSE);
    #endif
}

void VappCLogList::onBoundsChanged(VfxFrame *frame, const VfxRect &old)
{
    m_segBtn->setSize(m_seg_frame->getSize());
}


void VappCLogList::onToolBarClick(VfxObject* sender, VfxId btnID)
{
    switch (btnID)
    {
        case SEGMENT_BTN_ALL_CALL:
            setListID(VAPP_CLOG_LIST_ID_ALL_CALL);
            break;

        case SEGMENT_BTN_MISSED_CALL:
            setListID(VAPP_CLOG_LIST_ID_MISSED_CALL);
            break;

    #ifdef __MMI_CLOG_MARK_SEVERAL__
        case BOTTOM_BTN_DELETE:
	        VappClogMultiDeleteObj *obj;
            VFX_OBJ_CREATE_EX(obj, VappClogMultiDeleteObj, this, (this, this));

            m_deleteObj = obj;
            break;
    #else
        case BOTTOM_BTN_CLEAR:
            if (VAPP_CLOG_LIST_ID_ALL_CALL == m_currListID)
                m_action->deleteConfrim(VppCLogAction::DELETE_ALL);
            else // VAPP_CLOG_LIST_ID_MISSED_CALL
                m_action->deleteConfrim(VppCLogAction::DELETE_MISSED);
            break;
    #endif

        default :
            break;
    }
    updataToolBarStatus();
}


void VappCLogList::regListener()
{
    // Connect signal to refresh the time string.
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappCLogList::onTimeChanged);
}


void VappCLogList::deregListener()
{
    // DisConnect signal to refresh the time string.
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this, &VappCLogList::onTimeChanged);
}


mmi_ret VappCLogList::onProc(mmi_event_struct *evt)
{
    if (m_action != NULL)
        return m_action->onProc(evt);

	return MMI_RET_DONT_CARE;
}

void VappCLogList::onTimeChanged(VfxU32 flag)
{
    if (flag & VDAT_SYSTIME_CHANGED_DAY)
    {
        onUpdateClogList(NULL);
    }
}

void VappCLogList::setListID(VappCLogListIDEnum listID)
{
    m_currListID = listID;
    m_clogDataSrv->getClogIDs(m_currListID);
    
    m_CLogList->reset();
}


#ifdef __MMI_CLOG_MARK_SEVERAL__
void VappCLogList::setListMode(VappCLogListModeEnum mode)
{
    if (mode == VAPP_CLOG_LIST_NORMAL)
    {
        m_CLogList->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
        m_CLogList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
        m_CLogList->resetAllItems(VFX_TRUE);

		VFX_OBJ_CLOSE(m_mark);
        m_CLogList->m_signalItemSelectionStateChanged.disconnect(this, &VappCLogList::onStateChanged);
    }
	else if (mode == VAPP_CLOG_LIST_MARK)
	{
	    // mark several
        VFX_OBJ_CREATE_EX(m_mark, CLogMark, this, (m_currListID));
        m_mark->setDataProvider(m_clogDataSrv);
		
	    m_CLogList->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
		m_CLogList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);
        m_CLogList->resetAllItems(VFX_TRUE);

		m_CLogList->m_signalItemSelectionStateChanged.connect(this, &VappCLogList::onStateChanged);
	}
}


VcpListMenu *VappCLogList::getListMenu() const
{
    return m_CLogList;
}


CLogMark *VappCLogList::getMarked() const
{
    return m_mark;
}


void VappCLogList::markAll()
{
    m_mark->markAll();
    m_CLogList->resetAllItems(VFX_TRUE);
}


void VappCLogList::unMarkAll()
{
    m_mark->unMarkAll();
    m_CLogList->resetAllItems(VFX_TRUE);
}


void VappCLogList::onStateChanged(
        VcpListMenu *list,
        VfxU32 index,
        VcpListMenuItemStateEnum state)
{
    m_mark->changeMark(index);
}


void VappCLogList::onMultiDeleteStart()
{
	m_cmd = VAPP_CLOG_MARK_CMD_DELETE;

	m_CLogList->m_signalItemTapped.disconnect(this, &VappCLogList::onItemShortTapped);
	m_CLogList->m_signalItemLongTapped.disconnect(this, &VappCLogList::onItemLongTapped);
}


void VappCLogList::onMultiDeleteEnd()
{
	m_cmd = VAPP_CLOG_MARK_CMD_NONE;

	setListMode(VAPP_CLOG_LIST_NORMAL);
	
	m_CLogList->m_signalItemTapped.connect(this, &VappCLogList::onItemShortTapped);
	m_CLogList->m_signalItemLongTapped.connect(this, &VappCLogList::onItemLongTapped);
	
	setBottomBar(m_toolBar);
}
#endif /* __MMI_CLOG_MARK_SEVERAL__ */


void VappCLogList::onUpdateClogList(void *evt)
{
    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_LIST_ONUPDATECLOGLIST, 
        m_currPageType,
        m_currListID,
        (evt != NULL) ? ((mmi_event_struct *)evt)->evt_id : 0,
        EVT_ID_SRV_CLOG_ADD_LOG);
   
#ifdef __MMI_PHB_VIEW_CALLOG__ 
    if (m_currPageType == VAPP_CLOG_PAGE_FOR_CONTACT)
    {
        if (m_clogDataSrv->m_isUpdating)
            return;
        
        if (evt == NULL) // means time changed for day
            m_CLogList->updateAllItems();
        else
        {
            switch (((mmi_event_struct *)evt)->evt_id)
            {
                case EVT_ID_SRV_CLOG_ADD_LOG:
                case EVT_ID_SRV_CLOG_DEL_LOG:
                case EVT_ID_SRV_CLOG_DEL_ALL:
                    m_clogDataSrv->getClogIDsWithSamePHB(m_storeIndex);
                    break;

                case EVT_ID_SRV_CLOG_UPDATE_LOG:
                case EVT_ID_SRV_CLOG_UPDATE_ALL:
                {
                    VfxWChar name[MMI_PHB_NAME_LENGTH + 1] = {0};
                    srv_phb_get_name(m_storeIndex,(U16 *)name, MMI_PHB_NAME_LENGTH);
                    if (name[0] != 0)
                        //m_str->setString(VFX_WSTR_MEM(name));
                        m_str->setString(name);
                    else
                        //m_str->setString(VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNNAMED)); 
                        m_str->setString(STR_ID_VAPP_CLOG_UNNAMED); 
                    m_CLogList->updateAllItems();
                    break;
                }

                default:
                    break;
            }            
        }
        return;
    }
 #endif   
    if (m_currPageType == VAPP_CLOG_PAGE_FOR_DIALER)
    {
        m_clogDataSrv->getClogIDs(VAPP_CLOG_LIST_ID_ALL_CALL);
        if ((evt != NULL) && ((mmi_event_struct *)evt)->evt_id == EVT_ID_SRV_CLOG_ADD_LOG)
            m_CLogList->resetAllItems(VFX_FALSE);
        else
            m_CLogList->updateAllItems();
        
        return;
    }

    m_clogDataSrv->getClogIDs(m_currListID);
    
    if ((evt != NULL) && ((mmi_event_struct *)evt)->evt_id == EVT_ID_SRV_CLOG_ADD_LOG)
    {
        srv_clog_evt_add_log_struct *add_evt = (srv_clog_evt_add_log_struct *) evt;
        if (add_evt->old_idf.log_id == m_currClogItemID)
        {
            m_currClogItemID = add_evt->new_idf.log_id;
            srv_clog_log_struct log = {0};
            VfxS32 ret;
            ret = m_clogDataSrv->getClogByID(m_currClogItemID, log);
            if (SRV_CLOG_RET_OK != ret)//don't get success
                return;
            m_action->setLog(log);
        }
        m_CLogList->resetAllItems(VFX_FALSE);
    }
#ifdef __MMI_CLOG_MARK_SEVERAL__
    else if ((evt != NULL) && ((mmi_event_struct *)evt)->evt_id == EVT_ID_SRV_CLOG_DEL_LOG)
    {
        m_CLogList->resetAllItems(VFX_FALSE);
    }
#endif
    else
    {
        //m_CLogList->resetAllItems(VFX_TRUE);
        m_CLogList->updateAllItems();
    }

#ifndef __MMI_CLOG_MARK_SEVERAL__
    updataToolBarStatus();
#else
    if (m_cmd == VAPP_CLOG_MARK_CMD_DELETE)
    {
        m_listUpdated.postEmit();
    }
    else if (m_cmd == VAPP_CLOG_MARK_CMD_NONE)
    {
        updataToolBarStatus();
    }
#endif
}


#ifdef __MMI_PHB_VIEW_CALLOG__
mmi_ret VappCLogList::onPhbContactChanged(mmi_event_struct *param)
{
    VappCLogList *currObj = (VappCLogList*)param->user_data;

    VfxWChar name[MMI_PHB_NAME_LENGTH + 1] ;
    srv_phb_get_name(currObj->m_storeIndex,(U16 *)name, MMI_PHB_NAME_LENGTH);
    if (name[0] != 0)
        currObj->m_str->setString(VFX_WSTR_MEM(name));
    else
        currObj->m_str->setString(VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNNAMED));  

    return MMI_RET_OK;
}


void VappCLogList::onUpdatePageForContact()
{
    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_LIST_ONUPDATEPAGEFORCONTACT, 
        m_currPageType,
        m_clogDataSrv->getClogNum());
    
    m_CLogList->reset();

    if (m_currPageType != VAPP_CLOG_PAGE_FOR_CONTACT)
        return;

    if (getMainScr()->isActive() && ((VcpTabCtrlPage *)getParent())->isActive() && isActive())
        m_clogDataSrv->clearUnreadMissedCount();
    
    if (m_clogDataSrv->getClogNum() == 0)
        m_button->setIsDisabled(VFX_TRUE);
    else
        m_button->setIsDisabled(VFX_FALSE);
}
#endif
VfxBool VappCLogList::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
{
    //VfxS32 get_ret;
    srv_clog_log_struct log;
    m_clogDataSrv->getClogByIdx(index, log, get_ret);
    if (SRV_CLOG_RET_OK != get_ret || log.cate != SRV_CLOG_CATE_CALL)
        return VFX_FALSE;
    
    srv_clog_call_log_struct *calllog = &(log.data.call_log);        
    
    if (m_currPageType == VAPP_CLOG_PAGE_BASIC)
    {
	if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
	{
            if (calllog->name[0] != 0) // have name string
		//text = VFX_WSTR_MEM((VfxWChar *)calllog->name);
				text.loadFromMem((VfxWChar *)calllog->name);
            else if (srv_phb_check_number_id(calllog->phb_id)) // stored in PHB, but no name string 
                //text = VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNNAMED);
                text.loadFromRes(STR_ID_VAPP_CLOG_UNNAMED);
            else if (calllog->cid[0] != 0)
               // text = VFX_WSTR_MEM((VfxWChar *)calllog->cid);
                text.loadFromMem((VfxWChar *)calllog->cid);
            else
                //text = VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNKONWN_NUMBER);
                text.loadFromRes(STR_ID_VAPP_CLOG_UNKONWN_NUMBER);
        
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
	}
	else if (fieldType == VCP_LIST_MENU_FIELD_TAIL_TEXT)
	{
            if (calllog->total_num > 1)
            {
                text.format("(%d)", calllog->total_num);
            }
            else
            {
                text.setNull();
            }
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
	}
	else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
	{
            if (calllog->name[0] != 0) // have name string
                //text = VFX_WSTR_MEM((VfxWChar *)calllog->cid);
                text.loadFromMem((VfxWChar *)calllog->cid);
            else if (srv_phb_check_number_id(calllog->phb_id)) // stored in PHB, but no name string 
                //text = VFX_WSTR_MEM((VfxWChar *)calllog->cid);
                text.loadFromMem((VfxWChar *)calllog->cid);
            else
                //text = VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNSAVED);
                text.loadFromRes(STR_ID_VAPP_CLOG_UNSAVED);
        
		color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
	}
	else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT2)
	{
            if ((calllog->log_type == SRV_CLOG_CLT_MISSED) && (calllog->duration[SRV_CLOG_LASTEST_TIME_IDX] <= 1))
               // text = VFX_WSTR_RES(STR_ID_VAPP_CLOG_RING_ONCE);
               text.loadFromRes(STR_ID_VAPP_CLOG_RING_ONCE);
            else
                text.setNull();
        
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
	}
	else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT3)
	{
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
            // ingore that timestamp larger than phone time  //VFX_DATE_TIME_DATE_MASK;
            VfxDateTime logTime;
            VfxWChar buf[20];
            VfxU32 flags;
            if (isToday(calllog->timestamp[SRV_CLOG_LASTEST_TIME_IDX], logTime))
            {
                flags = VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;
            }
            else 
            {
                flags = VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY;  
            }
            logTime.getDateTimeString(flags, (VfxWChar *)buf, sizeof(buf));		    
            text.loadFromMem(buf);
            if (calllog->timestamp[SRV_CLOG_LASTEST_TIME_IDX] == 0) // indicate this log is sync form SIM, no call timestamp
                text.loadFromRes(STR_ID_VAPP_CLOG_UNKNOWN);
	}
	else
	{
            return VFX_FALSE;
	}
	return VFX_TRUE;	
    }
#ifdef __MMI_PHB_VIEW_CALLOG__
    else if (m_currPageType == VAPP_CLOG_PAGE_FOR_CONTACT)
    {
        if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            text = VFX_WSTR_MEM((VfxWChar *)calllog->cid);            
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        {
        #ifdef __MMI_CLOG_CALL_TIME__
            if (calllog->log_type == SRV_CLOG_CLT_MISSED)
            {
                text.format("%d ", 0);
                text += VFX_WSTR_RES(STR_ID_VAPP_CLOG_SEC);
            }
            else if ((calllog->timestamp[SRV_CLOG_LASTEST_TIME_IDX] == 0) && (calllog->log_type == SRV_CLOG_CLT_DIALED)) // sync from SIM
            {
                text.loadFromRes(STR_ID_VAPP_CLOG_UNKNOWN);
            }
            else
            {
                VappCLogUtils clogUtils;
                clogUtils.convertUTC2Duration(calllog->duration[SRV_CLOG_LASTEST_TIME_IDX], text, calllog->log_type);
            }
        #else
            // ingore that timestamp larger than phone time  //VFX_DATE_TIME_DATE_MASK;
            VfxDateTime logTime;
            VfxWChar buf[20];
            VfxU32 flags;
            if (isToday(calllog->timestamp[SRV_CLOG_LASTEST_TIME_IDX], logTime))
            {
                flags = VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;
            }
            else 
            {
                flags = VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY;  
            }
            logTime.getDateTimeString(flags, (VfxWChar *)buf, sizeof(buf));
            text = VFX_WSTR_MEM(buf);

            if (calllog->timestamp[SRV_CLOG_LASTEST_TIME_IDX] == 0) // indicate this log is sync form SIM, no call timestamp
                text.loadFromRes(STR_ID_VAPP_CLOG_UNKNOWN);
        #endif /* __MMI_CLOG_CALL_TIME__ */

            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        }
    #ifdef __MMI_CLOG_CALL_TIME__
        else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT2)
        {
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
            // ingore that timestamp larger than phone time  //VFX_DATE_TIME_DATE_MASK;
            VfxDateTime logTime;
            VfxWChar buf[20];
            VfxU32 flags;
            if (isToday(calllog->timestamp[SRV_CLOG_LASTEST_TIME_IDX], logTime))
            {
                flags = VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;
            }
            else 
            {
                flags = VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY;  
            }
            logTime.getDateTimeString(flags, (VfxWChar *)buf, sizeof(buf));
            text = VFX_WSTR_MEM(buf);
                
            if (calllog->timestamp[SRV_CLOG_LASTEST_TIME_IDX] == 0) // indicate this log is sync form SIM, no call timestamp
                //text = VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNKNOWN);
                text.loadFromRes(STR_ID_VAPP_CLOG_UNKNOWN);
        }
#endif /* __MMI_CLOG_CALL_TIME__ */
        else
        {
            return VFX_FALSE;
        }
        return VFX_TRUE;
    }
#endif
    else
    {
        if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            if (calllog->name[0] != 0) // have name string
               // text = VFX_WSTR_MEM((VfxWChar *)calllog->name);
               text.loadFromMem((VfxWChar *)calllog->name);
            else if (srv_phb_check_number_id(calllog->phb_id)) // stored in PHB, but no name string 
                //text = VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNNAMED);
                text.loadFromRes(STR_ID_VAPP_CLOG_UNNAMED);
            else if (calllog->cid[0] != 0)
                //text = VFX_WSTR_MEM((VfxWChar *)calllog->cid);
                text.loadFromMem((VfxWChar *)calllog->cid);
            else
                //text = VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNKONWN_NUMBER);
                text.loadFromRes(STR_ID_VAPP_CLOG_UNKONWN_NUMBER);
            
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        {
            if (calllog->name[0] != 0) // have name string
                //text = VFX_WSTR_MEM((VfxWChar *)calllog->cid);
                text.loadFromMem((VfxWChar *)calllog->cid);
            else if (srv_phb_check_number_id(calllog->phb_id)) // stored in PHB, but no name string 
                //text = VFX_WSTR_MEM((VfxWChar *)calllog->cid);
                text.loadFromMem((VfxWChar *)calllog->cid);
            else
                //text = VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNSAVED);
                text.loadFromRes(STR_ID_VAPP_CLOG_UNSAVED);
            
        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT2)
        {
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
            // ingore that timestamp larger than phone time  //VFX_DATE_TIME_DATE_MASK;
            VfxDateTime logTime;
            VfxWChar buf[20];
            VfxU32 flags;
            if (isToday(calllog->timestamp[SRV_CLOG_LASTEST_TIME_IDX], logTime))
            {
                flags = VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;
            }
            else 
            {
                flags = VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY;  
            }
            logTime.getDateTimeString(flags, (VfxWChar *)buf, sizeof(buf));         
            //text = VFX_WSTR_MEM(buf);
            text.loadFromMem(buf);
                
            if (calllog->timestamp[SRV_CLOG_LASTEST_TIME_IDX] == 0) // indicate this log is sync form SIM, no call timestamp
                //text = VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNKNOWN);
                text.loadFromRes(STR_ID_VAPP_CLOG_UNKNOWN);
        }
        else
        {
            return VFX_FALSE;
        }
        return VFX_TRUE;
    }
}


VfxBool VappCLogList::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        )
{
    //VfxS32 get_ret;
    srv_clog_log_struct log;
    m_clogDataSrv->getClogByIdx(index, log, get_ret);
    if (SRV_CLOG_RET_OK != get_ret || log.cate != SRV_CLOG_CATE_CALL)
        return VFX_FALSE;
    VfxBool tmp_value =  VFX_TRUE;
    srv_clog_call_log_struct *calllog = &(log.data.call_log);
    // Now only support call log, in futrue support sms log, nwpd log
    VfxResId res_id;
    switch (fieldType)
    {
        case VCP_LIST_MENU_FIELD_ICON:
            switch (calllog->log_type)
            {
                case SRV_CLOG_CLT_MISSED:
                    image.setResId(IMG_COSMOS_MISSED_CALL);
                    break;

                case SRV_CLOG_CLT_DIALED:
                    image.setResId(IMG_COSMOS_DIALED_CALL);
                    break;
							
                case SRV_CLOG_CLT_RECVED:
                    image.setResId(IMG_COSMOS_RECEIVED_CALL);
                    break;
							
                default:
                    break;
            }
            tmp_value = VFX_TRUE;
            break;

        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL:
        #ifdef __MMI_VIDEO_TELEPHONY__
            if (calllog->sub_type == SRV_CLOG_CALL_TYPE_VIDEO)
            {
                image.setResId(IMG_ID_VAPP_CLOG_CALL_VIDEO_N);
                tmp_value = VFX_TRUE;
                break;
            }
        #endif
            if (1 >= srv_sim_ctrl_get_num_of_inserted()) // only 1 SIM or no SIM is inserted
            {
                image.setResId(IMG_COSMOS_GEMINI_LIST_CALL_N);
                tmp_value = VFX_TRUE;
                break;
            }
            res_id = vapp_clog_get_list_call_button_id((mmi_sim_enum)calllog->sim_id, SRV_CLOG_CALL_TYPE_VOICE, VAPP_CLOG_LIST_BUT_IMG_NORMAL);
            image.setResId(res_id);
            tmp_value = VFX_TRUE;
            break;

        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT:
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED:
        #ifdef __MMI_VIDEO_TELEPHONY__    
            if (calllog->sub_type == SRV_CLOG_CALL_TYPE_VIDEO)
            {
                image.setResId(IMG_ID_VAPP_CLOG_CALL_VIDEO_P);
                tmp_value = VFX_TRUE;
                //return VFX_TRUE;
                break;
            }
        #endif
            if (1 >= srv_sim_ctrl_get_num_of_inserted()) // only 1 SIM or no SIM is inserted
            {
                image.setResId(IMG_COSMOS_GEMINI_LIST_CALL_P);
                tmp_value = VFX_TRUE;
                //return VFX_TRUE;
                break;
            }
            res_id = vapp_clog_get_list_call_button_id((mmi_sim_enum)calllog->sim_id, SRV_CLOG_CALL_TYPE_VOICE, VAPP_CLOG_LIST_BUT_IMG_PRESSED);
            image.setResId(res_id);
            tmp_value = VFX_TRUE;
            //return VFX_TRUE;
            break;

        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED:
        #ifdef __MMI_VIDEO_TELEPHONY__    
            if (calllog->sub_type == SRV_CLOG_CALL_TYPE_VIDEO)
            {
                image.setResId(IMG_ID_VAPP_CLOG_CALL_VIDEO_D);
                //return VFX_TRUE;
                tmp_value = VFX_TRUE;
                break;
            }
        #endif
            if (1 >= srv_sim_ctrl_get_num_of_inserted()) // only 1 SIM or no SIM is inserted
            {
                image.setResId(IMG_COSMOS_GEMINI_LIST_CALL_D);
                tmp_value = VFX_TRUE;
                //return VFX_TRUE;
                break;
            }
            res_id = vapp_clog_get_list_call_button_id((mmi_sim_enum)calllog->sim_id, SRV_CLOG_CALL_TYPE_VOICE, VAPP_CLOG_LIST_BUT_IMG_DISABLED);
            image.setResId(res_id);
            tmp_value = VFX_TRUE;
            //return VFX_TRUE;
			break;

        case VCP_LIST_MENU_FIELD_ICON_EXTRA1:
            image.setResId(0);
            tmp_value = VFX_TRUE;
            //return VFX_TRUE;
            break;
        
        case VCP_LIST_MENU_FIELD_ICON_EXTRA2:
            if (1 >= srv_sim_ctrl_get_num_of_inserted()) // only 1 SIM or no SIM is inserted
            {
                image.setResId(0);
                tmp_value = VFX_TRUE;
                //return VFX_TRUE;
                break;
            }
        #if (MMI_MAX_SIM_NUM >= 2)    
            switch (calllog->sim_id)
            {
                case MMI_SIM1:
                    image.setResId(IMG_COSMOS_SIM1);
                    break;
                case MMI_SIM2:
                    image.setResId(IMG_COSMOS_SIM2);
                    break;
            #if (MMI_MAX_SIM_NUM >= 3)
                case MMI_SIM3:
                    image.setResId(IMG_COSMOS_SIM3);//todo 3
                    break;
            #if (MMI_MAX_SIM_NUM >= 4)
                case MMI_SIM4:
                    image.setResId(IMG_COSMOS_SIM4);//todo 4
                    break;
            #endif
            #endif
                default:
                    //return VFX_FALSE;
                    tmp_value = VFX_FALSE;
                    break;
            }
        #endif /* (MMI_MAX_SIM_NUM >= 2) */    
            //return VFX_TRUE;
            tmp_value = VFX_TRUE;
            break;

        default :
            tmp_value = VFX_FALSE;
            break;
            //return VFX_FALSE;
    }
    return tmp_value;
}


VcpListMenuCmdStateEnum VappCLogList::getItemCmdState(VfxU32 index) const
{
    VfxS32 get_ret;
    srv_clog_log_struct log;
    m_clogDataSrv->getClogByIdx(index, log, get_ret);
    if (SRV_CLOG_RET_OK != get_ret)
        return VCP_LIST_MENU_CMD_STATE_DEFAULT;
    
    srv_clog_call_log_struct *calllog = &(log.data.call_log);
    
    if (1 >= srv_sim_ctrl_get_num_of_inserted()) // only 1 SIM or no SIM is inserted
    {
        if (srv_sim_ctrl_get_num_of_inserted() == 0 || srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
            return VCP_LIST_MENU_CMD_STATE_DISABLED;
    }
    else
    {
        if (srv_mode_switch_get_network_mode((mmi_sim_enum)calllog->sim_id) == SRV_MODE_SWITCH_OFF)
            return VCP_LIST_MENU_CMD_STATE_DISABLED;
    }

    //return VCP_LIST_MENU_CMD_STATE_DEFAULT;
    return VCP_LIST_MENU_CMD_STATE_NORMAL;
}


#ifdef __MMI_CLOG_MARK_SEVERAL__
VcpListMenuItemStateEnum VappCLogList::getItemState(
        VfxU32 index          // [IN] index of the item
        ) const
{
    return (m_mark->checkMark(index)) ?
               VCP_LIST_MENU_ITEM_STATE_SELECTED :
               VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}
#endif


VfxU32 VappCLogList::getCount() const
{
    VfxU32 count;
	
    /*if (m_currPageType == VAPP_CLOG_PAGE_BASIC)
    {
        count = m_clogDataSrv->getClogCount(m_currListID);
    }
    else
    {
        count = m_clogDataSrv->getClogCount(VAPP_CLOG_LIST_ID_ALL_CALL);
    }*/
    count = m_clogDataSrv->getClogCount(m_currListID);
    
    return count;
}


VcpListMenuCellClientBaseFrame * VappCLogList::getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        ) 
{
    if (m_currPageType == VAPP_CLOG_PAGE_BASIC)
    {
        VappCLogListMenuItemCell *item;
        VFX_OBJ_CREATE(item, VappCLogListMenuItemCell, parentFrame);

        return item;
    }
    else
    {
        VappCLogListMenuItemExCell *item;
        VFX_OBJ_CREATE(item, VappCLogListMenuItemExCell, parentFrame);

        return item;
    }
}


VfxBool VappCLogList::getMenuEmptyText(
                            VfxWString &text,                // [OUT] the text resource
                            VcpListMenuTextColorEnum &color  // [OUT] the text color
                            )
{
    
#ifdef __MMI_PHB_VIEW_CALLOG__
    if (m_currPageType == VAPP_CLOG_PAGE_FOR_CONTACT && m_clogDataSrv->m_isUpdating)
        return VFX_FALSE;
#endif        
    if (m_currPageType != VAPP_CLOG_PAGE_BASIC || m_currListID == VAPP_CLOG_LIST_ID_ALL_CALL)
        text.loadFromRes(STR_ID_VAPP_CLOG_NO_CALL_LOG);
    else
        text.loadFromRes(STR_ID_VAPP_CLOG_NO_MISSED_CALL);

    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
	return VFX_TRUE;
}


void VappCLogList::updatePage()
{
    m_b2ndReady = VFX_FALSE;
    
    m_CLogList->setContentProvider(this);
    
    m_clogDataSrv->getClogIDs(m_currListID);
}


VfxBool VappCLogList::isToday(const VfxU32 &timestamp, VfxDateTime &logTime) const
{
    applib_time_struct startTime; 
    VfxU32 local_sec = applib_dt_sec_utc_to_local(timestamp);
	mmi_dt_utc_sec_2_mytime(local_sec, &startTime, MMI_FALSE);

    logTime.setDateTime(&startTime);
    
	VfxDateTime currTime;
	currTime.setCurrentTime();

    if (logTime.getYear() == currTime.getYear()&&
        logTime.getMonth() == currTime.getMonth() &&
        logTime.getDay() == currTime.getDay())
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


void VappCLogList::onListCmdBtnClick(
        VcpListMenu * sender,
        VfxU32   index)
{
    //VfxS32 get_ret;
    srv_clog_log_struct log;
    m_currClogItemID = m_clogDataSrv->getClogByIdx(index, log, get_ret);
    if (SRV_CLOG_RET_OK != get_ret)
        return;
    
    m_action->setLog(log);
    
    if (1 == srv_sim_ctrl_get_num_of_inserted()) // only 1 SIM is inserted
    {
        VfxS32 i;
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            if (srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
            {
                log.data.call_log.sim_id = mmi_frm_index_to_sim(i); // traking method
                break;
            }
        }
    }
    
    if (log.data.call_log.sub_type == SRV_CLOG_CALL_TYPE_VIDEO)
        m_action->makeCall(SRV_UCM_VIDEO_CALL_TYPE);
    else if (log.data.call_log.sim_id == MMI_SIM1)
        m_action->makeCall(SRV_UCM_VOICE_CALL_TYPE);
    else if (log.data.call_log.sim_id == MMI_SIM2)
        m_action->makeCall(SRV_UCM_VOICE_CALL_TYPE_SIM2);
    else if (log.data.call_log.sim_id == MMI_SIM3)
        m_action->makeCall(SRV_UCM_VOICE_CALL_TYPE_SIM3);
    else if (log.data.call_log.sim_id == MMI_SIM4)
        m_action->makeCall(SRV_UCM_VOICE_CALL_TYPE_SIM4);
}

void VappCLogList::onItemShortTapped(
        VcpListMenu *list,          // [IN] ListMenu pointer
        VfxU32 index                // [IN] The selected menu item
    )
{
   //VfxS32 get_ret;
   srv_clog_log_struct log;
    m_currClogItemID = m_clogDataSrv->getClogByIdx(index, log, get_ret);
    if (SRV_CLOG_RET_OK != get_ret)
        return;

    if (m_currPageType == VAPP_CLOG_PAGE_BASIC)
    {
        VappCLogDetail *detail;
        VFX_OBJ_CREATE_EX(detail, VappCLogDetail, getMainScr(), (log));
        getMainScr()->pushPage(0, detail);
    }
    else if(m_currPageType == VAPP_CLOG_PAGE_FOR_DIALER)
    {
        m_action->setLog(log); 
        srv_ucm_call_type_enum   calltype= srv_ucm_query_voice_type_by_sim(m_currSIMID);
        m_action->makeCall(calltype);
        
        //onListCmdBtnClick(list, index);
    }
#ifdef __MMI_PHB_VIEW_CALLOG__
    else
    {
                m_action->setLog(log);
                if (1 == srv_sim_ctrl_get_num_of_inserted()) // only 1 SIM is inserted
                {
                    VfxS32 i;
                    for (i = 0; i < MMI_SIM_TOTAL; i++)
                    {
                        if (srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
                        {
                            log.data.call_log.sim_id = mmi_frm_index_to_sim(i); // traking method
                            break;
                        }
                    }
                }
                 srv_ucm_call_type_enum   calltype= srv_ucm_query_voice_type_by_sim(m_currSIMID);
                 m_action->makeCall(calltype);
    }
#endif 
}


void VappCLogList::onItemLongTapped(
        VcpListMenu *list,          // [IN] ListMenu pointer
        VfxU32 index                // [IN] The selected menu item
    )
{
   // VfxS32 get_ret;
    srv_clog_log_struct log;
    m_currClogItemID = m_clogDataSrv->getClogByIdx(index, log, get_ret);
    if (SRV_CLOG_RET_OK != get_ret)
        return;
    
    VcpMenuPopup *cntxMenu;
    VFX_OBJ_CREATE(cntxMenu, VcpMenuPopup, this);
    // Need check null number
    if (log.data.call_log.name[0] != 0)
        //cntxMenu->setTitle(VFX_WSTR_MEM((VfxWChar *)log.data.call_log.name));
        cntxMenu->setTitle((VfxWChar *)log.data.call_log.name);
    else
        //cntxMenu->setTitle(VFX_WSTR_MEM((VfxWChar *)log.data.call_log.cid));
        cntxMenu->setTitle((VfxWChar *)log.data.call_log.cid);

    if (srv_phb_check_number_id(log.data.call_log.phb_id)) // stored in PHB
       cntxMenu->addItem(VAPP_CLOG_BTN_VIEW_CONTACT, VFX_WSTR_RES(STR_ID_VAPP_CLOG_VIEW_CONTACT));
       //cntxMenu->addItem((VfxResId)STR_ID_VAPP_CLOG_VIEW_CONTACT, (VfxId)VAPP_CLOG_BTN_VIEW_CONTACT);
    else
       //cntxMenu->addItem(VAPP_CLOG_BTN_SAVE_TO_CONTACT, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    cntxMenu->addItem(VAPP_CLOG_BTN_SAVE_TO_CONTACT,(VfxResId)STR_GLOBAL_SAVE);

    //cntxMenu->addItem(VAPP_CLOG_BTN_EDIT_BEFORE_CALL, VFX_WSTR_RES(STR_GLOBAL_DIAL)); // enter edit before call
    cntxMenu->addItem(VAPP_CLOG_BTN_EDIT_BEFORE_CALL,(VfxResId)STR_GLOBAL_EDIT_BEFORE_CALL);
    // default no sim pass to uc, then uc will follow UC's rule to select suitable SIM
    //cntxMenu->addItem(VAPP_CLOG_BTN_SEND_MSG_NO_SIM, VFX_WSTR_RES(STR_GLOBAL_SEND_MESSAGE));
    cntxMenu->addItem((VfxId)VAPP_CLOG_BTN_SEND_MSG_NO_SIM,(VfxResId)STR_GLOBAL_SEND_MESSAGE);

    //cntxMenu->addItem(VAPP_CLOG_BTN_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE));
    cntxMenu->addItem((VfxId)VAPP_CLOG_BTN_DELETE,(VfxResId)STR_GLOBAL_DELETE);

#if defined(__MMI_CM_BLACK_LIST__) && defined(__OP01__)
    cntxMenu->addItem(VAPP_CLOG_BTN_VIEW_BLACK_LIST, VFX_WSTR_RES(STR_ID_VAPP_CLOG_VIEW_BLACK_LIST));
#endif

    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
    cntxMenu->m_signalMenuCallback.connect(this, &VappCLogList::onCntxMenuClick);
    cntxMenu->show(VFX_TRUE);
}

void VappCLogList::onCntxMenuClick(
        VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item)
{
    if (event == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        srv_clog_log_struct log;
        VfxS32 ret;
        ret = m_clogDataSrv->getClogByID(m_currClogItemID, log);
        if (SRV_CLOG_RET_OK != ret) // don't get success
            return;
        m_action->setLog(log);
        m_action->onButtonClicked((VfxObject *)menu, item->getId());
    }
}


/*****************************************************************************
 * Class VappCLogListMenuItemCell
 *****************************************************************************/

void VappCLogListMenuItemCell::onLayoutElements()
{
    if (m_imageFrame)
    {
        m_imageFrame->setRect(VfxRect(CT_IMG_LEFT_GAPS, CT_IMG_TOP_GAPS,
                                      CT_IMG_MAX_WIDTH, m_imageFrame->getRect().getHeight()));
        m_imageFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    VfxS32 maxText1Width;
    VfxS32 textFrame4AreaWidth = 0;

    if (m_textFrame4)
    {
        textFrame4AreaWidth = TEXT4_LEFT_GAPS + m_textFrame4->getRect().getWidth() + TEXT4_RIGHT_GAPS;
    }

    VfxS32 textFrame2AreaWidth = 0;

    if (m_textFrame2)
    {
        textFrame2AreaWidth = TEXT2_LEFT_GAPS + m_textFrame2->getRect().getWidth() + TEXT2_RIGHT_GAPS;
    }

    maxText1Width = getRect().getWidth() - (CT_IMG_LEFT_GAPS + CT_IMG_RIGHT_GAPS + CT_IMG_MAX_WIDTH) - TEXT1_LEFT_GAPS
                    - TEXT1_RIGHT_GAPS - textFrame4AreaWidth - textFrame2AreaWidth;

    VfxWString string;

    VfxSize stringSize;

    if (getText(VCP_LIST_MENU_FIELD_TEXT, string))
    {
        stringSize = VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_MEDIUM).measureStr(string);
    }

    if (m_textFrame1)
    {
        m_textFrame1->setRect(VfxRect(TEXT1_LEFT_GAPS + CT_IMG_LEFT_GAPS + CT_IMG_RIGHT_GAPS + CT_IMG_MAX_WIDTH, 
                                      TEXT1_TOP_GAPS,
                                      (stringSize.width > maxText1Width) ? maxText1Width : stringSize.width,
                                      m_textFrame1->getRect().getHeight()));
        m_textFrame1->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    VfxS32 textFrame1MaxX = TEXT1_LEFT_GAPS + CT_IMG_LEFT_GAPS + CT_IMG_RIGHT_GAPS + CT_IMG_MAX_WIDTH;

    if (m_textFrame1)
    {
        textFrame1MaxX = m_textFrame1->getRect().getMaxX();
    }
    
    if (m_textFrame2)
    {
        m_textFrame2->setRect(VfxRect(textFrame1MaxX + TEXT1_RIGHT_GAPS + TEXT2_LEFT_GAPS, 
                                      TEXT2_TOP_GAPS,
                                      m_textFrame2->getRect().getWidth(),
                                      m_textFrame2->getRect().getHeight()));

        m_textFrame2->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    VfxS32 textFrame5AreaWidth = 0;

    if (m_textFrame5)
    {
        textFrame5AreaWidth = TEXT5_LEFT_GAPS + m_textFrame5->getRect().getWidth() + TEXT5_RIGHT_GAPS;
    }

    if (m_textFrame3)
    {
        m_textFrame3->setRect(VfxRect(TEXT3_LEFT_GAPS + CT_IMG_LEFT_GAPS + CT_IMG_RIGHT_GAPS + CT_IMG_MAX_WIDTH, 
                                      getRect().getHeight() - 1 - TEXT3_BOTTOM_GAPS - m_textFrame3->getRect().getHeight(),
                                      getRect().getWidth() - TEXT3_LEFT_GAPS - TEXT3_RIGHT_GAPS
                                      - (CT_IMG_LEFT_GAPS + CT_IMG_RIGHT_GAPS + CT_IMG_MAX_WIDTH) - textFrame5AreaWidth,
                                      m_textFrame3->getRect().getHeight()));

        m_textFrame3->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    if (m_textFrame4)
    {
        m_textFrame4->setRect(VfxRect(getRect().getWidth() - 1 - TEXT4_RIGHT_GAPS - m_textFrame4->getRect().getWidth(), 
                                      TEXT4_TOP_GAPS,
                                      m_textFrame4->getRect().getWidth(),
                                      m_textFrame4->getRect().getHeight()));

        m_textFrame4->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    if (m_textFrame5)
    {
        m_textFrame5->setRect(VfxRect(getRect().getWidth() - 1 - TEXT5_RIGHT_GAPS - m_textFrame5->getRect().getWidth(), 
                                      getRect().getHeight() - 1 - TEXT5_BOTTOM_GAPS - m_textFrame5->getRect().getHeight(),
                                      m_textFrame5->getRect().getWidth(),
                                      m_textFrame5->getRect().getHeight()));

        m_textFrame5->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }
}
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
        #ifdef __MMI_CLOG_CALL_TIME__
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
        #endif /* __MMI_CLOG_CALL_TIME__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_CLOG_CALL_TIME__
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
    #endif /* __MMI_CLOG_CALL_TIME__ */
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
        #if (MMI_MAX_SIM_NUM >= 2)    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#endif
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
       #endif /* (MMI_MAX_SIM_NUM >= 2) */    
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
#endif

/*****************************************************************************
 * Class VappCLogListMenuItemExCell
 *****************************************************************************/

void VappCLogListMenuItemExCell::onLayoutElements()
{
    VcpListMenuCellIconTripleTextFrameEx::onLayoutElements();

    if (m_imageFrame)
    {
        m_imageFrame->setRect(VfxRect(CT_IMG_LEFT_GAPS, CT_IMG_TOP_GAPS,
                                      CT_IMG_MAX_WIDTH, m_imageFrame->getRect().getHeight()));        
        m_imageFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);

    }

    if (m_textFrame1)
    {
        m_textFrame1->setRect(VfxRect(TEXT1_LEFT_GAPS + CT_IMG_LEFT_GAPS + CT_IMG_RIGHT_GAPS + CT_IMG_MAX_WIDTH, 
                                      TEXT1_TOP_GAPS,
                                      m_textFrame1->getRect().getWidth() + 
                                      (IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH) - 
                                      (CT_IMG_LEFT_GAPS + CT_IMG_RIGHT_GAPS + CT_IMG_MAX_WIDTH),
                                      m_textFrame1->getRect().getHeight()));
        m_textFrame1->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }
    
    VfxS32 textFrame3AreaWidth = 0;

    if (m_textFrame3)
    {
        textFrame3AreaWidth = TEXT3_LEFT_GAPS + m_textFrame3->getRect().getWidth() + TEXT3_RIGHT_GAPS;
    }

    if (m_textFrame2)
    {
        m_textFrame2->setRect(VfxRect(TEXT2_LEFT_GAPS + CT_IMG_LEFT_GAPS + CT_IMG_RIGHT_GAPS + CT_IMG_MAX_WIDTH, 
                                      getRect().getHeight() - 1 - TEXT2_BOTTOM_GAPS - m_textFrame2->getRect().getHeight(),
                                      getRect().getWidth() - TEXT2_LEFT_GAPS - TEXT2_RIGHT_GAPS
                                      - (CT_IMG_LEFT_GAPS + CT_IMG_RIGHT_GAPS + CT_IMG_MAX_WIDTH) - textFrame3AreaWidth,
                                      m_textFrame2->getRect().getHeight()));
        m_textFrame2->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }
}


/*****************************************************************************
 * Class VappCLogUtils
 *****************************************************************************/
void VappCLogUtils::convertUTC2DT(const VfxU32 &timestamp, VfxDateTime &logTime) const
{
    applib_time_struct startTime; 
    VfxU32 local_sec = applib_dt_sec_utc_to_local(timestamp);
	mmi_dt_utc_sec_2_mytime(local_sec, &startTime, MMI_FALSE);

    logTime.setDateTime(&startTime);
}


/*void VappCLogUtils::timestamp2string(const VfxU32 &timestamp, VfxWString &str) const
{
    // ingore that timestamp larger than phone time  //VFX_DATE_TIME_DATE_MASK;
	VfxDateTime logTime;
    convertUTC2DT(timestamp, logTime);
    
    VfxWChar buf[20];
	VfxU32 flags;
	if (isToday(timestamp))
	{
		flags = VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;
	}
	else
	{
		flags = VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY;  
	}
    logTime.getDateTimeString(flags, (VfxWChar *)buf, sizeof(buf));		    
	str = VFX_WSTR_MEM(buf);
}*/

/*VfxBool VappCLogUtils::isToday(const VfxU32 &timestamp) const
{
    VfxDateTime logTime;
    convertUTC2DT(timestamp, logTime);
    
	VfxDateTime currTime;
	currTime.setCurrentTime();

    if (logTime.getYear() == currTime.getYear()&&
        logTime.getMonth() == currTime.getMonth() &&
        logTime.getDay() == currTime.getDay())
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}
*/

#ifdef __MMI_CLOG_CALL_TIME__
void VappCLogUtils::convertUTC2Duration(const VfxU32 &dur_sec, VfxWString &dur_str, VfxU8 log_type) const
{
    /*
    if (SRV_CLOG_CLT_MISSED == log_type)
    {
        if (dur_sec <= 1)
            dur_str += VFX_WSTR_RES(STR_ID_VAPP_CLOG_RING_ONCE);
        else
            dur_str += VFX_WSTR_RES(STR_ID_VAPP_CLOG_MISSED);
        return;
    }
    */
    if (dur_sec < 60)
    {
        dur_str.format("%d ", dur_sec);
        if (dur_sec <= 1)
            dur_str += VFX_WSTR_RES(STR_ID_VAPP_CLOG_SEC);
        else
            dur_str += VFX_WSTR_RES(STR_ID_VAPP_CLOG_SECS);
    }
    else if (dur_sec < 60 * 60)
    {
        VfxWString min_str;
        min_str.format("%d ", dur_sec/60);
        if (dur_sec/60 <= 1)
            min_str += VFX_WSTR_RES(STR_ID_VAPP_CLOG_MIN);
        else
            min_str += VFX_WSTR_RES(STR_ID_VAPP_CLOG_MINS);
        VfxWString sec_str;
        sec_str.format(" %d ", dur_sec%60);
        if (dur_sec%60 <= 1)
            sec_str += VFX_WSTR_RES(STR_ID_VAPP_CLOG_SEC);
        else
            sec_str += VFX_WSTR_RES(STR_ID_VAPP_CLOG_SECS);

        dur_str += min_str;
        dur_str += sec_str;
    }
    else
    {
        VfxWString hr_str;
        hr_str.format("%d ", dur_sec/3600);
        if (dur_sec/3600 <= 1)
            hr_str += VFX_WSTR_RES(STR_ID_VAPP_CLOG_HOUR);
        else
            hr_str += VFX_WSTR_RES(STR_ID_VAPP_CLOG_HOURS);
        VfxWString min_str;
        min_str.format(" %d ", dur_sec%3600/60);
        if (dur_sec%3600/60 <= 1)
            min_str += VFX_WSTR_RES(STR_ID_VAPP_CLOG_MIN);
        else
            min_str += VFX_WSTR_RES(STR_ID_VAPP_CLOG_MINS);
        VfxWString sec_str;
        sec_str.format(" %d ", dur_sec%60);
        if (dur_sec%60 <= 1)
            sec_str += VFX_WSTR_RES(STR_ID_VAPP_CLOG_SEC);
        else
            sec_str += VFX_WSTR_RES(STR_ID_VAPP_CLOG_SECS);

        dur_str += hr_str;
        dur_str += min_str;
        dur_str += sec_str;
    }
}
#endif /* __MMI_CLOG_CALL_TIME__ */

#ifdef __MMI_CLOG_CALL_TIME__
void VappCLogUtils::sec2mytime(const VfxU32 &dur_sec, VfxWString &myTime, VfxU8 log_type) const
{
    if (SRV_CLOG_CLT_MISSED == log_type)
    {
        if (dur_sec <= 1)
            myTime = VFX_WSTR_RES(STR_ID_VAPP_CLOG_RING_ONCE);
        else
            myTime = VFX_WSTR_RES(STR_ID_VAPP_CLOG_MISSED);
        return;
    }

    myTimeStruct t = {0};

    t.Hour = dur_sec / 3600;
    t.Min = dur_sec % 3600 / 60;
    t.Sec = dur_sec % 60;

    if (dur_sec < 60 * 60)
        myTime.format("%02d:%02d", t.Min, t.Sec);
    else
        myTime.format("%02d:%02d:%02d", t.Hour, t.Min, t.Sec);
}
#endif



