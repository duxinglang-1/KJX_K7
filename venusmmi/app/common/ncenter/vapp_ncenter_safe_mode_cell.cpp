/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vapp_ncenter_safe_mode_cell.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the safe mode cell.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_SAFE_MODE__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_ncenter_base_cell.h"
#include "vapp_ncenter_safe_mode_cell.h"

#ifdef __COSMOS_MMI_PACKAGE__
#include "vcp_global_popup.h"
#include "mmi_rp_vapp_safe_mode_def.h"  // cosmos resource
#else
#include "mmi_rp_app_safemode_def.h"  // pluto/FTE reource
extern "C"
{
	#include "wgui_categories_text_viewer.h"
	#include "globalResDef.h"
	#include "wgui_categories_util.h"
}
#endif

extern "C"
{
#include "AlarmSrvGprot.h"
#include "SafeModeSrvGprot.h"
}


#ifdef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * Prototype
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vapp_safe_mode_launch
 * DESCRIPTION
 *  This function launches the safe mode UI.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_safe_mode_launch();


/*****************************************************************************
 * FUNCTION
 *  vapp_safe_mode_button_clicked
 * DESCRIPTION
 *  This function handles the button clicked event.
 * PARAMETERS
 *  userData        : [IN]      User data
 *  id              : [IN]      Id
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_safe_mode_button_clicked(
    VfxId id,
    void *userData);


/*****************************************************************************
 * Function
 *****************************************************************************/

void vapp_safe_mode_launch()
{
    vcp_global_popup_show_confirm_two_button_id(
        GRP_ID_ROOT,
        VCP_POPUP_TYPE_WARNING,
        STR_ID_VAPP_SAFE_MODE_HELP_TEXT,
        STR_ID_VAPP_SAFE_MODE_RESTART,
        STR_ID_VAPP_SAFE_MODE_DO_IT_LATER,
        VCP_POPUP_BUTTON_TYPE_WARNING,
        VCP_POPUP_BUTTON_TYPE_CANCEL,
        vapp_safe_mode_button_clicked,
        NULL);
}


void vapp_safe_mode_button_clicked(VfxId id, void *userData)
{
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            srv_alm_normal_reset(MMI_TRUE, 3);
            break;
        }
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        case VCP_POPUP_BUTTON_NO_PRESSED:
        {
            // Do nothing.
            break;
        }

        default:
            break;
    }
}

#else /*__COSMOS_MMI_PACKAGE__ */
/*****************************************************************************
 * Prototype
 *****************************************************************************/
static void vapp_safe_mode_launch();
static void vapp_safe_mode_exit_screen();
static mmi_ret mmi_safe_mode_confirm_proc(mmi_event_struct* evt);
static void vapp_safe_mode_entry_screen();

static void vapp_safe_mode_exit_screen()
{
	// do nothing
}

static mmi_ret mmi_safe_mode_confirm_proc(mmi_event_struct* evt)
{
	return MMI_RET_OK;
}
static void mmi_safe_mode_lsk_handler()
{
	srv_alm_normal_reset(MMI_TRUE, 3);
}

static void vapp_safe_mode_entry_screen()
{
    if(mmi_frm_scrn_enter(GRP_ID_SAFE_MODE_CONFIRM, SCR_ID_SAFE_MODE_CONFIRM, vapp_safe_mode_exit_screen, vapp_safe_mode_entry_screen, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

	ShowCategory7Screen(
		STR_ID_SAFE_MODE_EXIT,
		0,
		STR_GLOBAL_OK,
		0,
		STR_GLOBAL_CANCEL,
		0,
		(U8*)GetString(STR_ID_SAFE_MODE_HELP_TEXT),
		0);
	SetLeftSoftkeyFunction(mmi_safe_mode_lsk_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_safe_mode_lsk_handler, KEY_EVENT_UP);
}

void vapp_safe_mode_launch()
{
	mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SAFE_MODE_CONFIRM, mmi_safe_mode_confirm_proc, (void*)NULL);
    mmi_frm_group_enter(GRP_ID_SAFE_MODE_CONFIRM, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	vapp_safe_mode_entry_screen();
}
#endif /*__COSMOS_MMI_PACKAGE__ */
/*****************************************************************************
 * Notification Cell on Notification Center
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappSafeModeNotificationCell",
    VappSafeModeNotificationCell,
    VfxFrame);


VappSafeModeNotificationCell::VappSafeModeNotificationCell() :
    m_button(NULL)
{
    // Do nothing.
}


void VappSafeModeNotificationCell::onInit()
{
    VfxFrame::onInit();

    //
    // This
    //
    VfxS32 cellHeight = VAPP_NCENTER_EVENT_CELL_HEIGHT + GAP_HEIGHT;

    VfxSize parentSize = getParentFrame()->getSize();
    setSize(parentSize.width, cellHeight);

    //
    // Button
    //
    VFX_OBJ_CREATE(m_button, VcpButton, this);
    m_button->setAnchor(0.5f, 0.5f);
    m_button->setPos(parentSize.width / 2, cellHeight / 2);
    m_button->setIsAutoResized(VFX_TRUE);
#ifdef __COSMOS_MMI_PACKAGE__
    m_button->setText(VFX_WSTR_RES(STR_ID_VAPP_SAFE_MODE_EXIT));
#else
	m_button->setText(VFX_WSTR_RES(STR_ID_SAFE_MODE_EXIT));
#endif
    m_button->m_signalClicked.connect(this, &VappSafeModeNotificationCell::onButtonClicked);
}


void VappSafeModeNotificationCell::onDeinit()
{
    VfxFrame::onDeinit();

    // Do nothing.
}


void VappSafeModeNotificationCell::onButtonClicked(VfxObject *obj, VfxId id)
{
    vapp_safe_mode_launch();
}

#endif /* defined(__MMI_SAFE_MODE__) */

