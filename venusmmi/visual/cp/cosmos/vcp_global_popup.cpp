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
 *  vcp_popup.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internal UI componets of home screen application category
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vcp_global_popup.h"
#include "vfx_uc_include.h"
#include "vadp_mmi_frm.h"
#include "vcp_popup.h"
#include "mmi_rp_srv_venus_component_popup_def.h"
#include "vfx_datatype.h"
#include "vfx_app_cat_scr.h"
#include "vfx_object.h"
#include "vfx_base_popup.h"
#include "vcp_status_icon_bar.h"
#include "vfx_adp_sse.h"
#include "vadp_sys_trc.h"

extern "C" 
{
    #include "GlobalResDef.h"
}

// TODO: use cosmos compiler option
#ifdef __MMI_VUI_COSMOS_CP__
extern "C" void vapp_ncenter_disable_leave(void);
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
typedef struct
{
	VfxId buttonId;
    MMI_ID groupId;	
	PopupCallBackPtr callback;
    void *userData;
	void *popupData;
}vcp_global_popup_struct;

typedef struct
{
    VcpPopupTypeEnum type; 
    VfxResId textResId;
    VfxWChar *textPtr;
    VfxResId btnText1ResId;
    VfxWChar *btnText1Ptr;
    VfxResId btnText2ResId;
    VfxWChar *btnText2Ptr;
    VcpPopupButtonTypeEnum type1;
    VcpPopupButtonTypeEnum type2;
} vcp_global_popup_confirm_struct;


typedef struct
{
    VfxResId textResId;
    VfxWChar *textPtr;
    VfxS32   btnCount;
    VfxId    btnTextId[7];
    VfxResId btnTextResId[7];
    VfxWChar *btnTextPtr[7];
    VcpPopupButtonTypeEnum btnType[7];
} vcp_global_popup_command_struct;

typedef struct
{   
    VfxScrRotateTypeEnum dir;
    PopupCallBackPtr callback;
	getPopUpHandleCB getpopupCB;
    void *userData;
    VfxId buttonId;
} vcp_global_popup_generic_struct;

/***************************************************************************** 
 * Class VcpGlobalPopupScr
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcpGlobalPopupScr", VcpGlobalPopupScr, VfxAppCatScr);
 
VcpGlobalPopupScr::VcpGlobalPopupScr() :
    m_statusBar(NULL),
    m_callBack(NULL),
    m_userData(NULL),
    m_isBackWard(VFX_TRUE),
    m_id(VCP_POPUP_BUTTON_NO_PRESSED),
    m_popup(NULL),
    m_dir(VFX_SCR_ROTATE_TYPE_NORMAL)
{
    setIsSmallScreen();
}


VcpGlobalPopupScr::VcpGlobalPopupScr(VfxScrRotateTypeEnum dir) :
	m_statusBar(NULL),
    m_callBack(NULL),
    m_userData(NULL),
    m_isBackWard(VFX_TRUE),
    m_popup(NULL),
    m_dir(dir)
{
    setIsSmallScreen();
}


void VcpGlobalPopupScr::onInit()
{

	VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
	m_dir = renderer->getPreScreenRotateType();

    VfxAppCatScr::onInit();
   
    m_buttonPressed = VFX_FALSE;

  //  VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
   // m_statusBar->setPos(0, 0);
}

void VcpGlobalPopupScr::onRotate(const VfxScreenRotateParam &param)
{
    VfxAppCatScr::onRotate(param);
	if (m_statusBar != NULL)
	{
		m_statusBar->setSize(getSize().width, m_statusBar->getSize().height);
	}
}

void VcpGlobalPopupScr::onExit(VfxBool isBackward)
{
    m_isBackWard = isBackward;
    #ifdef __MMI_VUI_COSMOS_CP__
    if (m_isBackWard)
    {
        vapp_ncenter_disable_leave();
    }
    #endif
    
    VfxAppCatScr::onExit(isBackward);
}
void VcpGlobalPopupScr::onEntered(VfxBool isBackward)
{
	if (!m_statusBar)
	{
		VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
		m_statusBar->setPos(0, 0);
		m_statusBar->setSize(getSize().width, m_statusBar->getSize().height);
	}
}

void VcpGlobalPopupScr::onButtonClicked(VfxObject* sender, VfxId id)
{
    m_id = id;

    vcp_global_popup_struct *popup_data = (vcp_global_popup_struct *)mmi_frm_scrn_get_user_data(m_groupId, SCR_ID_GLOBAL_POPUP_BASE);
	popup_data->buttonId = m_id;

    mmi_frm_scrn_clear_attribute(m_groupId, SCR_ID_GLOBAL_POPUP_BASE, MMI_SCRN_ATTRIB_ADD_HISTORY);
}


void VcpGlobalPopupScr::onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state)
{
    if (state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {
        if (m_isBackWard)
        {
            mmi_frm_scrn_close(m_groupId, SCR_ID_GLOBAL_POPUP_BASE);
        }
    }
}


void VcpGlobalPopupScr::onQueryRotateEx(VfxScreenRotateParam &param)
{  
    param.rotateTo = m_dir;
}

/***************************************************************************** 
 * Static Variable
 *****************************************************************************/
static VcpGlobalPopupScr *g_vcp_global_popup_screen_ptr;
//static vcp_global_popup_confirm_struct g_confirm_popup_data;
//static vcp_global_popup_confirm_struct g_confirm_popup_data_2;
//static vcp_global_popup_command_struct g_command_popup_data;
//static vcp_global_popup_command_struct g_command_popup_data_2;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
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
#endif
/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_confirm_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret vcp_global_popup_show_confirm_leave_proc(mmi_event_struct *evt)
{
     if (evt->evt_id == EVT_ID_SCRN_DEINIT)
     {
        VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_CONFIRM_DEINIT_MSG);
        mmi_scenario_evt_struct *evt2 = (mmi_scenario_evt_struct *)evt;
        if (evt2->user_data)
        {
			vcp_global_popup_struct *popup_data = (vcp_global_popup_struct *)evt2->user_data;
			vcp_global_popup_confirm_struct * confirm_popup_data = (vcp_global_popup_confirm_struct*)popup_data->popupData;

            // callback APP
            if (popup_data->callback)
            {
                popup_data->callback(popup_data->buttonId, popup_data->userData);
            }

            VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_FREE_MSG, confirm_popup_data->textPtr);
            VFX_SYS_FREE_MEM(confirm_popup_data->textPtr);
            VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_FREE_MSG, confirm_popup_data->btnText1Ptr);
            VFX_SYS_FREE_MEM(confirm_popup_data->btnText1Ptr);
            if (confirm_popup_data->btnText2ResId != -1)
            {
                VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_FREE_MSG, confirm_popup_data->btnText2Ptr);
                VFX_SYS_FREE_MEM(confirm_popup_data->btnText2Ptr);
            }
            VFX_SYS_FREE_MEM(confirm_popup_data);
			VFX_SYS_FREE_MEM(popup_data);
            VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_FREE_MSG, confirm_popup_data);
        }
     }
     return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_confirm_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret vcp_global_popup_show_command_leave_proc(mmi_event_struct *evt)
{
    VfxS32 i;
    
    if (evt->evt_id == EVT_ID_SCRN_DEINIT)
    {
        VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_COMMAND_DEINIT_MSG);
        mmi_scenario_evt_struct *evt2 = (mmi_scenario_evt_struct *)evt;
        if (evt2->user_data)
        {
			vcp_global_popup_struct *popup_data = (vcp_global_popup_struct *)evt2->user_data;
			vcp_global_popup_command_struct * command_popup_data = (vcp_global_popup_command_struct *)popup_data->popupData;
            
            // callback APP
            if (popup_data->callback)
            {
                popup_data->callback(popup_data->buttonId, popup_data->userData);
            }

            if (command_popup_data->textResId == 0)
            {
                VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_FREE_MSG, command_popup_data->textPtr);
                VFX_SYS_FREE_MEM(command_popup_data->textPtr);
            }
            for (i = 0; i < command_popup_data->btnCount; i++)
            {
                if (command_popup_data->btnTextResId[i] == 0)
                {
                    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_FREE_MSG, command_popup_data->btnTextPtr[i]);
                    VFX_SYS_FREE_MEM(command_popup_data->btnTextPtr[i]);
                }
            }
            VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_FREE_MSG, command_popup_data);
            VFX_SYS_FREE_MEM(command_popup_data);
			VFX_SYS_FREE_MEM(popup_data);
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_leave
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcp_global_popup_leave(void)
{
    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_CONFIRM_LEAVE_MSG);
    /* Leave the APP category screen */
    VFX_OBJ_CLOSE(g_vcp_global_popup_screen_ptr);
    
    VfxAppCatScr::deinitalize();

    // Disable NCenter leave
    ExitCategoryFunction = reset_small_screen;
    vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_NONE, VFX_FALSE, VFX_SCR_TRANSIT_PRIORITY_SMALL_SCR);
}


/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_confirm_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vcp_global_popup_show_confirm_entry(mmi_scrn_essential_struct *arg)
{
    //U8 *history_buffer;
	vcp_global_popup_struct *popup_data = (vcp_global_popup_struct *)arg->user_data;
	vcp_global_popup_confirm_struct *data = (vcp_global_popup_confirm_struct *)popup_data->popupData;

    // Disable NCenter leave
    #ifdef __MMI_VUI_COSMOS_CP__
    vapp_ncenter_disable_leave();
    #endif
    
    if (!mmi_frm_scrn_enter(arg->group_id, SCR_ID_GLOBAL_POPUP_BASE, vcp_global_popup_leave, (FuncPtr)vcp_global_popup_show_confirm_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }
    mmi_frm_scrn_set_leave_proc(arg->group_id, SCR_ID_GLOBAL_POPUP_BASE, vcp_global_popup_show_confirm_leave_proc);
    set_small_screen();
    
    /* Enter the APP category screen */
    VfxAppCatScr::initalize();  


    VFX_OBJ_CREATE(
        g_vcp_global_popup_screen_ptr, 
        VcpGlobalPopupScr, 
        VfxAppCatScr::getContext());

    if (g_vcp_global_popup_screen_ptr == NULL)
    {
        // If current screen is leaveing. g_vcp_global_popup_screen_ptr will set null when create.
        return;
    }

    g_vcp_global_popup_screen_ptr->setGroupId(arg->group_id);

    VcpConfirmPopup *popup;
    VFX_OBJ_CREATE(popup, VcpConfirmPopup, g_vcp_global_popup_screen_ptr);
#if defined(__MMI_VUI_COSMOS_CP__)
    popup->setIsPlayTone(VFX_FALSE);
#endif
    popup->setInfoType(data->type);
    
    if (data->textResId == 0)
    {
        popup->setText(VFX_WSTR_MEM(data->textPtr));
    }
    else
    {
        popup->setText(VFX_WSTR_RES(data->textResId));
    }
    
    popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);

    if (data->btnText2ResId == -1)
    {
        if (data->textResId == 0)
        {
            popup->setCustomButton(
                        VFX_WSTR_MEM(data->btnText1Ptr), 
                        VFX_WSTR_NULL, 
                        data->type1,
                        data->type2
                        );
        }
        else
        {
            popup->setCustomButton(
                        VFX_WSTR_RES(data->btnText1ResId), 
                        VFX_WSTR_NULL, 
                        data->type1,
                        data->type2
                        );
        }
    }
    else
    {
        if (data->textResId == 0)
        {
            popup->setCustomButton(
                        VFX_WSTR_MEM(data->btnText1Ptr), 
                        VFX_WSTR_MEM(data->btnText2Ptr), 
                        data->type1,
                        data->type2
                        );
        }
        else
        {
            popup->setCustomButton(
                        VFX_WSTR_RES(data->btnText1ResId), 
                        VFX_WSTR_RES(data->btnText2ResId), 
                        data->type1,
                        data->type2
                        );
        }
    }
    
    g_vcp_global_popup_screen_ptr->setCallBack(popup_data->callback, popup_data->userData);
    //g_vcp_global_popup_screen_ptr->setDir(g_confirm_popup_data.dir);
    popup->m_signalButtonClicked.connect(g_vcp_global_popup_screen_ptr, &VcpGlobalPopupScr::onButtonClicked);
    popup->m_signalPopupState.connect(g_vcp_global_popup_screen_ptr, &VcpGlobalPopupScr::onPopupStateChanged);
    popup->show(VFX_TRUE);
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
#endif
/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_confirm_first_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static mmi_ret vcp_global_popup_show_confirm_first_entry(mmi_event_struct *evt)
{
    vcp_global_popup_struct *popup_data = (vcp_global_popup_struct *)evt->user_data;
    mmi_frm_group_enter(popup_data->groupId, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_first_enter(popup_data->groupId, SCR_ID_GLOBAL_POPUP_BASE, (FuncPtr)vcp_global_popup_show_confirm_entry, evt->user_data);
    return MMI_RET_OK;
}
    

/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_confirm_two_button_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

VfxS32 vcp_global_popup_show_confirm_two_button_str(
        MMI_ID parentID,
        VcpPopupTypeEnum type, 
        const VfxWString &text, 
        const VfxWString &btnText1, 
        const VfxWString &btnText2,
        VcpPopupButtonTypeEnum type1,
        VcpPopupButtonTypeEnum type2,
        PopupCallBackPtr callback,
        void *userData
        )
{
    //U8 *history_buffer;
    MMI_ID group_id;
	vcp_global_popup_struct *popup_data;
    vcp_global_popup_confirm_struct *confirm_popup_data;

	VFX_SYS_ALLOC_MEM(popup_data, sizeof(vcp_global_popup_struct));
    VFX_SYS_ALLOC_MEM(confirm_popup_data, sizeof(vcp_global_popup_confirm_struct));
    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_ALLOCATE_MSG, confirm_popup_data);
    confirm_popup_data->type = type;
    
    confirm_popup_data->textResId = 0;
    VFX_SYS_ALLOC_MEM(confirm_popup_data->textPtr, (text.getLength() + 1) * sizeof(VfxWChar));
    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_ALLOCATE_MSG, confirm_popup_data->textPtr);
    memcpy(confirm_popup_data->textPtr, text.getBuf(), (text.getLength() + 1) * sizeof(VfxWChar));

    confirm_popup_data->btnText1ResId = 0;
    VFX_SYS_ALLOC_MEM(confirm_popup_data->btnText1Ptr, (btnText1.getLength() + 1) * sizeof(VfxWChar));
    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_ALLOCATE_MSG, confirm_popup_data->btnText1Ptr);
    memcpy(confirm_popup_data->btnText1Ptr, btnText1.getBuf(), (btnText1.getLength() + 1) * sizeof(VfxWChar));
    
	confirm_popup_data->type1 = type1;

	if (VCP_POPUP_BUTTON_TYPE_END_OF_ENUM == type2)
	{
		confirm_popup_data->btnText2ResId = -1;
		confirm_popup_data->btnText2Ptr = NULL;
		confirm_popup_data->type2 = type1;
	}
	else
	{
		confirm_popup_data->btnText2ResId = 0;
		VFX_SYS_ALLOC_MEM(confirm_popup_data->btnText2Ptr, (btnText2.getLength() + 1) * sizeof(VfxWChar));
		VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_ALLOCATE_MSG, confirm_popup_data->btnText2Ptr);
		memcpy(confirm_popup_data->btnText2Ptr, btnText2.getBuf(), (btnText2.getLength() + 1) * sizeof(VfxWChar));
		confirm_popup_data->type2 = type2;
	}
    popup_data->callback = callback;
    popup_data->userData = userData;
    popup_data->buttonId = VCP_POPUP_BUTTON_NO_PRESSED;

#ifdef __MMI_VUI_COSMOS_CP__
    vapp_ncenter_disable_leave();
#endif


    // create a group ID.
    group_id = mmi_frm_group_create(parentID, GRP_ID_AUTO_GEN, NULL, popup_data);
    popup_data->groupId = group_id;

    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_SHOW_CONFIRM_STR_MSG, group_id);

    //mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    //mmi_frm_scrn_first_enter(group_id, SCR_ID_GLOBAL_POPUP_BASE, (FuncPtr)vcp_global_popup_show_confirm_entry, confirm_popup_data);

    // post enter group
	popup_data->popupData = confirm_popup_data;
    mmi_event_struct postInvoke;
    MMI_FRM_INIT_EVENT(&postInvoke, 0);
    MMI_FRM_POST_EVENT(&postInvoke, vcp_global_popup_show_confirm_first_entry, popup_data);

    return group_id;
}

/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_confirm_two_button_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

VfxS32 vcp_global_popup_show_confirm_one_button_str(
        MMI_ID parentID,
        VcpPopupTypeEnum type, 
        const VfxWString &text, 
        const VfxWString &btnText1, 
        VcpPopupButtonTypeEnum type1,
        PopupCallBackPtr callback,
        void *userData
        )
{
   
    return vcp_global_popup_show_confirm_two_button_str(
														parentID,
														type, 
														text, 
														btnText1, 
														VFX_WSTR_NULL,
														type1,
														VCP_POPUP_BUTTON_TYPE_END_OF_ENUM,
														callback,
														userData
														);
}

/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_confirm_two_button_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vcp_global_popup_show_confirm_two_button_id(
        MMI_ID parentID,
        VcpPopupTypeEnum type, 
        VfxResId textResId, 
        VfxResId btnText1ResId, 
        VfxResId btnText2ResId,
        VcpPopupButtonTypeEnum type1,
        VcpPopupButtonTypeEnum type2,
        PopupCallBackPtr callback,
        void *userData
        )
{
    //U8 *history_buffer;
    MMI_ID group_id;
	vcp_global_popup_struct *popup_data;
    vcp_global_popup_confirm_struct *confirm_popup_data;

    VFX_SYS_ALLOC_MEM(popup_data, sizeof(vcp_global_popup_struct));
    VFX_SYS_ALLOC_MEM(confirm_popup_data, sizeof(vcp_global_popup_confirm_struct));
    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_ALLOCATE_MSG, confirm_popup_data);
    confirm_popup_data->type = type;
    confirm_popup_data->textResId = textResId;
    confirm_popup_data->textPtr = NULL;
    confirm_popup_data->btnText1ResId = btnText1ResId;
    confirm_popup_data->btnText1Ptr = NULL;
    confirm_popup_data->btnText2ResId = btnText2ResId;
    confirm_popup_data->btnText2Ptr = NULL;
    confirm_popup_data->type1 = type1;
    confirm_popup_data->type2 = type2;
    popup_data->callback = callback;
    popup_data->userData = userData;
    popup_data->buttonId = VCP_POPUP_BUTTON_NO_PRESSED;

    // create a group ID.
#ifdef __MMI_VUI_COSMOS_CP__
    vapp_ncenter_disable_leave();
#endif
    group_id = mmi_frm_group_create(parentID, GRP_ID_AUTO_GEN, NULL, popup_data);
    popup_data->groupId = group_id;

    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_SHOW_CONFIRM_ID_MSG, group_id);

    //mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    //mmi_frm_scrn_first_enter(group_id, SCR_ID_GLOBAL_POPUP_BASE, (FuncPtr)vcp_global_popup_show_confirm_entry, confirm_popup_data);
	popup_data->popupData = confirm_popup_data;
    mmi_event_struct postInvoke;
    MMI_FRM_INIT_EVENT(&postInvoke, 0);
    MMI_FRM_POST_EVENT(&postInvoke, vcp_global_popup_show_confirm_first_entry, popup_data);

    return group_id;
}

/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_confirm_one_button_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vcp_global_popup_show_confirm_one_button_id(
        MMI_ID parentID,
        VcpPopupTypeEnum type, 
        VfxResId textResId, 
        VfxResId btnText1ResId, 
        VcpPopupButtonTypeEnum type1,
        PopupCallBackPtr callback,
        void *userData
        )
{
    return vcp_global_popup_show_confirm_two_button_id(
                                                parentID, 
                                                type, 
                                                textResId, 
                                                btnText1ResId, 
                                                -1, 
                                                type1, 
                                                type1, 
                                                callback, 
                                                userData);
}


/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_command_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vcp_global_popup_show_command_entry(mmi_scrn_essential_struct *arg)
{
    //U8 *history_buffer;
    VfxS32 i;
    vcp_global_popup_struct *popup_data = (vcp_global_popup_struct *)arg->user_data;
	vcp_global_popup_command_struct *data = (vcp_global_popup_command_struct *)popup_data->popupData;

    // Disable NCenter leave
    #ifdef __MMI_VUI_COSMOS_CP__
    vapp_ncenter_disable_leave();
    #endif
    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_COMMAND_ENTRY_MSG, arg->group_id);
    
    if (!mmi_frm_scrn_enter(arg->group_id, SCR_ID_GLOBAL_POPUP_BASE, vcp_global_popup_leave, (FuncPtr)vcp_global_popup_show_command_entry, MMI_FRM_SMALL_SCRN))
    {
        return;
    }
    mmi_frm_scrn_set_leave_proc(arg->group_id, SCR_ID_GLOBAL_POPUP_BASE, vcp_global_popup_show_command_leave_proc);
    set_small_screen();

    /* Enter the APP category screen */
    VfxAppCatScr::initalize();
   
	VFX_OBJ_CREATE(
        g_vcp_global_popup_screen_ptr, 
        VcpGlobalPopupScr, 
        VfxAppCatScr::getContext());

    if (g_vcp_global_popup_screen_ptr == NULL)
    {
        // If current screen is leaveing. g_vcp_global_popup_screen_ptr will set null when create.
        return;
    }

    g_vcp_global_popup_screen_ptr->setGroupId(arg->group_id);

    VcpCommandPopup *popup;
    VFX_OBJ_CREATE(popup, VcpCommandPopup, g_vcp_global_popup_screen_ptr);
#if defined(__MMI_VUI_COSMOS_CP__)
    popup->setIsPlayTone(VFX_FALSE);
#endif
    if (data->textResId == 0)
    {
        popup->setText(VFX_WSTR_MEM(data->textPtr));
    }
    else
    {
        popup->setText(VFX_WSTR_RES(data->textResId));
    }
    g_vcp_global_popup_screen_ptr->setCallBack(popup_data->callback, popup_data->userData);
    //g_vcp_global_popup_screen_ptr->setDir(g_command_popup_data.dir);
    g_vcp_global_popup_screen_ptr->setPopup(popup);
    popup->m_signalButtonClicked.connect(g_vcp_global_popup_screen_ptr, &VcpGlobalPopupScr::onButtonClicked);
    popup->m_signalPopupState.connect(g_vcp_global_popup_screen_ptr, &VcpGlobalPopupScr::onPopupStateChanged);

    if (mmi_frm_is_in_backward_scenario())
    {      
        for (i = 0; i < data->btnCount; i++)
        {
            if (data->btnTextResId[i] == 0)
            {
                popup->addItem(
                    data->btnTextId[i], 
                    VFX_WSTR_MEM(data->btnTextPtr[i]),
                    data->btnType[i]
                    );
            }
            else
            {
                popup->addItem(
                    data->btnTextId[i], 
                    VFX_WSTR_RES(data->btnTextResId[i]),
                    data->btnType[i]
                    );
            }
        }

        popup->show(VFX_TRUE);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_command_create_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vcp_global_popup_show_command_create_str(
        MMI_ID parentID,
        const VfxWString &text, 
        PopupCallBackPtr callback,
        void *userData
        )
{
    MMI_ID group_id;

	vcp_global_popup_struct *popup_data;
    vcp_global_popup_command_struct *command_popup_data;

	VFX_SYS_ALLOC_MEM(popup_data, sizeof(vcp_global_popup_struct));

    VFX_SYS_ALLOC_MEM(command_popup_data, sizeof(vcp_global_popup_command_struct));
    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_ALLOCATE_MSG, command_popup_data);

    command_popup_data->btnCount = 0;
    command_popup_data->textResId = 0;
    VFX_SYS_ALLOC_MEM(command_popup_data->textPtr, (text.getLength() + 1) * sizeof(VfxWChar));
    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_ALLOCATE_MSG, command_popup_data->textPtr);
    memcpy(command_popup_data->textPtr, text.getBuf(), (text.getLength() + 1) * sizeof(VfxWChar));
    popup_data->callback = callback;
    popup_data->userData = userData;
    popup_data->buttonId = VCP_POPUP_BUTTON_NO_PRESSED;

#ifdef __MMI_VUI_COSMOS_CP__
    vapp_ncenter_disable_leave();
#endif

    // create a group ID.
    group_id = mmi_frm_group_create(parentID, GRP_ID_AUTO_GEN, NULL, NULL);
	popup_data->groupId = group_id;

    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_CREATE_COMMAND_STR_MSG, group_id);

    mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	popup_data->popupData = command_popup_data;
    mmi_frm_scrn_first_enter(group_id, SCR_ID_GLOBAL_POPUP_BASE, (FuncPtr)vcp_global_popup_show_command_entry, popup_data);

    return group_id;
}


/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_command_add_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcp_global_popup_show_command_add_str(
        VfxS32 handle,
        VfxId id,                     
        const VfxWString &btnText,         
        VcpPopupButtonTypeEnum type
        )
{
    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_ADD_COMMAND_STR_MSG, handle);

	vcp_global_popup_command_struct *command_popup_data = (vcp_global_popup_command_struct *)((vcp_global_popup_struct*)mmi_frm_scrn_get_user_data(handle, SCR_ID_GLOBAL_POPUP_BASE))->popupData;
    VfxS32 i = command_popup_data->btnCount;

	if (i >= 7)
	{
		return;
	}
    
    command_popup_data->btnTextId[i] = id;
    command_popup_data->btnTextResId[i] = 0;
    VFX_SYS_ALLOC_MEM(command_popup_data->btnTextPtr[i], (btnText.getLength() + 1) * sizeof(VfxWChar));
    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_ALLOCATE_MSG, command_popup_data->btnTextPtr[i]);
    memcpy(command_popup_data->btnTextPtr[i], btnText.getBuf(), (btnText.getLength() + 1) * sizeof(VfxWChar));
    command_popup_data->btnType[i] = type;
    command_popup_data->btnCount++;

    if (g_vcp_global_popup_screen_ptr == NULL)
    {
        // If current screen is leaveing. g_vcp_global_popup_screen_ptr will set null when create.
        return;
    }
    
    VcpCommandPopup *popup = (VcpCommandPopup *) g_vcp_global_popup_screen_ptr->getPopup();
    popup->addItem(id, btnText, type);
}


/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_command_show_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcp_global_popup_show_command_show_str(VfxS32 handle)
{
    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_SHOW_COMMAND_STR_MSG, handle);

    if (g_vcp_global_popup_screen_ptr == NULL)
    {
        // If current screen is leaveing. g_vcp_global_popup_screen_ptr will set null when create.
        return;
    }
    VcpCommandPopup *popup = (VcpCommandPopup *)g_vcp_global_popup_screen_ptr->getPopup();
    popup->show(VFX_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_command_create_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vcp_global_popup_show_command_create_id(
        MMI_ID parentID,
        VfxResId textResId, 
        PopupCallBackPtr callback,
        void *userData
        )
{
    MMI_ID group_id;
	vcp_global_popup_struct *popup_data;
    vcp_global_popup_command_struct *command_popup_data;

	VFX_SYS_ALLOC_MEM(popup_data, sizeof(vcp_global_popup_struct));
    VFX_SYS_ALLOC_MEM(command_popup_data, sizeof(vcp_global_popup_command_struct));
    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_ALLOCATE_MSG, command_popup_data);
    command_popup_data->btnCount = 0;
    command_popup_data->textResId = textResId;
    command_popup_data->textPtr = NULL;
    popup_data->callback = callback;
    popup_data->userData = userData;
    popup_data->buttonId = VCP_POPUP_BUTTON_NO_PRESSED;

#ifdef __MMI_VUI_COSMOS_CP__
    vapp_ncenter_disable_leave();
#endif
    // create a group ID.
    group_id = mmi_frm_group_create(parentID, GRP_ID_AUTO_GEN, NULL, NULL);

    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_CREATE_COMMAND_ID_MSG, group_id);

    mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	popup_data->popupData = command_popup_data;

    mmi_frm_scrn_first_enter(group_id, SCR_ID_GLOBAL_POPUP_BASE, (FuncPtr)vcp_global_popup_show_command_entry, popup_data);

    return group_id;
}


/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_command_add_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcp_global_popup_show_command_add_id(
        VfxS32 handle,
        VfxId id,                     
        VfxResId btnTextId,        
        VcpPopupButtonTypeEnum type
        )
{
    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_ADD_COMMAND_ID_MSG, handle);
    
	vcp_global_popup_command_struct *command_popup_data = (vcp_global_popup_command_struct *)((vcp_global_popup_struct*)mmi_frm_scrn_get_user_data(handle, SCR_ID_GLOBAL_POPUP_BASE))->popupData;
    VfxS32 i = command_popup_data->btnCount;

	if (i >= 7)
	{
		return;
	}
    
    command_popup_data->btnTextId[i] = id;
    command_popup_data->btnTextResId[i] = btnTextId;
    command_popup_data->btnTextPtr[i] = NULL;
    command_popup_data->btnType[i] = type;
    command_popup_data->btnCount++;

    if (g_vcp_global_popup_screen_ptr == NULL)
    {
        // If current screen is leaveing. g_vcp_global_popup_screen_ptr will set null when create.
        return;
    }
    
    VcpCommandPopup *popup = (VcpCommandPopup *) g_vcp_global_popup_screen_ptr->getPopup();
    popup->addItem(id, VFX_WSTR_RES(btnTextId), type);
}


/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_show_command_show_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcp_global_popup_show_command_show_id(VfxS32 handle)
{
    VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_SHOW_COMMAND_ID_MSG, handle);

    if (g_vcp_global_popup_screen_ptr == NULL)
    {
        // If current screen is leaveing. g_vcp_global_popup_screen_ptr will set null when create.
        return;
    }
    VcpCommandPopup *popup = (VcpCommandPopup *)g_vcp_global_popup_screen_ptr->getPopup();
    popup->show(VFX_TRUE);
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
#endif

/*****************************************************************************
 * FUNCTION
 *  vcp_global_popup_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcp_global_popup_cancel(VfxS32 handle)
{
    if (handle != VCP_GLOBAL_POPUP_INVALID_HANDLE)
    {
        if(mmi_frm_group_is_in_dangle(handle) == MMI_TRUE)
		{
			 vcp_global_popup_struct *popup_data = (vcp_global_popup_struct *)mmi_frm_group_get_user_data(handle);
			 if (popup_data != NULL && popup_data->groupId == handle)
			 {
				 popup_data->callback(popup_data->buttonId, popup_data->userData);
			 }
		}
        mmi_frm_group_close(handle);
    }
}

//Generic Global popup code
static mmi_ret vcp_global_popup_generic_leave_proc(mmi_event_struct *evt)
{
     if (evt->evt_id == EVT_ID_SCRN_DEINIT)
     {
       
        mmi_scenario_evt_struct *evt2 = (mmi_scenario_evt_struct *)evt;
        if (evt2->user_data)
        {
            vcp_global_popup_generic_struct * generic_popup_data = (vcp_global_popup_generic_struct *)evt2->user_data; 
			if (generic_popup_data->callback)
			{
				generic_popup_data->callback(generic_popup_data->buttonId, generic_popup_data->userData);
			}
            VFX_SYS_FREE_MEM(generic_popup_data);
        }
     }
     return MMI_RET_OK;
}


static void vcp_global_popup_show_generic_entry(mmi_scrn_essential_struct *arg)
{
    //U8 *history_buffer;
    vcp_global_popup_generic_struct *data = (vcp_global_popup_generic_struct *)arg->user_data;

    // Disable NCenter leave
#ifdef __MMI_VUI_COSMOS_CP__
    vapp_ncenter_disable_leave();
#endif
    
    if (!mmi_frm_scrn_enter(arg->group_id, SCR_ID_GLOBAL_POPUP_BASE, vcp_global_popup_leave, (FuncPtr)vcp_global_popup_show_generic_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }
    mmi_frm_scrn_set_leave_proc(arg->group_id, SCR_ID_GLOBAL_POPUP_BASE, vcp_global_popup_generic_leave_proc);
    set_small_screen();
    
    /* Enter the APP category screen */
    VfxAppCatScr::initalize(); 

    VFX_OBJ_CREATE_EX(
        g_vcp_global_popup_screen_ptr, 
        VcpGlobalPopupScr, 
        VfxAppCatScr::getContext(),
        (data->dir));

    if (g_vcp_global_popup_screen_ptr == NULL)
    {
        // If current screen is leaveing. g_vcp_global_popup_screen_ptr will set null when create.
        return;
    }

    g_vcp_global_popup_screen_ptr->setGroupId(arg->group_id);
	VfxBasePopup *popup = data->getpopupCB(g_vcp_global_popup_screen_ptr, data->userData);    
	g_vcp_global_popup_screen_ptr->setCallBack(data->callback, data->userData);	
	g_vcp_global_popup_screen_ptr->setPopup(popup);
    popup->m_signalPopupState.connect(g_vcp_global_popup_screen_ptr, &VcpGlobalPopupScr::onPopupStateChanged);
    popup->show(VFX_TRUE);
}


VfxS32 vcp_global_popup_generic_create(MMI_ID parentID,
									   PopupCallBackPtr callback,
									   getPopUpHandleCB getPopupCB,
									   void* userData
									   )
{
	MMI_ID group_id;
    vcp_global_popup_generic_struct *generic_popup_data;

    VFX_SYS_ALLOC_MEM(generic_popup_data, sizeof(vcp_global_popup_generic_struct));
    //Add log
    generic_popup_data->callback = callback;
    generic_popup_data->userData = userData;
    generic_popup_data->buttonId = VCP_POPUP_BUTTON_NO_PRESSED;
	generic_popup_data->getpopupCB = getPopupCB;


    VfxTopLevel *toplevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    generic_popup_data->dir = toplevel->getScreenRotateType();

#ifdef __MMI_VUI_COSMOS_CP__
    vapp_ncenter_disable_leave();
#endif

    // create a group ID.
    group_id = mmi_frm_group_create(parentID, GRP_ID_AUTO_GEN, NULL, NULL);

   // VFX_LOG(VFX_INFO, VCP_GLOBAL_POPUP_CREATE_COMMAND_ID_MSG, group_id);
	//Add log

    mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_first_enter(group_id, SCR_ID_GLOBAL_POPUP_BASE, (FuncPtr)vcp_global_popup_show_generic_entry, generic_popup_data);

    return group_id;
}
