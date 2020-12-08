/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * vmadpui.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * 
 *
*==============================================================================
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/


#include "vmswitch.h"
#ifdef __MRE_CORE_BASE__

#ifdef __COSMOS_MMI_PACKAGE__

#include "vmsalui.h"

#include "vfx_datatype.h"
#include "vapp_nmgr_gprot.h"

extern "C" void vm_nmgr_confirm_popup_user_callback (vm_common_ui_confirm_evt_enum evt_id, VMINT common_ui_id);

static const VcpPopupTypeEnum confirm_popup_type_mapping_evt_table[] =
{
	VCP_POPUP_TYPE_FAILURE,
	VCP_POPUP_TYPE_INFO,
	VCP_POPUP_TYPE_WARNING,
	VCP_POPUP_TYPE_SUCCESS,
	VCP_POPUP_TYPE_PROGRESS,
	VCP_POPUP_TYPE_QUESTION
};

static void vm_nmgr_confirm_popup_callback (VfxId id, void *userData)
{
	VMINT common_ui_id = (VMINT)userData;	
	vm_common_ui_confirm_evt_enum evt_id = VM_COMMON_UI_CONFIRM_EVENT_MAX;

	switch (id)
	{
		case VCP_CONFIRM_POPUP_BUTTON_USER_1:
		{
			evt_id = VM_COMMON_UI_CONFIRM_EVENT_USER_1;
			break;
		}
		case VCP_CONFIRM_POPUP_BUTTON_USER_2:
		{
			evt_id = VM_COMMON_UI_CONFIRM_EVENT_USER_2;
			break;
		}
		case VCP_POPUP_BUTTON_NO_PRESSED:
		{
			evt_id = VM_COMMON_UI_CONFIRM_EVENT_BUTTON_NONE;
			break;
		}
		default:
			break;
	}

	if (evt_id != VM_COMMON_UI_CONFIRM_EVENT_MAX)
	{
		vm_nmgr_confirm_popup_user_callback(evt_id, common_ui_id);
	}
}

extern "C" VMINT vm_nmgr_confirm_popup_show(vm_common_ui_info_struct *ui_info, vm_common_ui_res_struct *ui_res_p)
{
	VcpPopupTypeEnum confirm_popup_type = confirm_popup_type_mapping_evt_table[ui_info->confirm_popup_para.confirm_popup_type];
    VfxWString popup_string, popup_button_string1, popup_button_string2;
	VfxS32 popup_grp_id = 0;

	popup_string = VFX_WSTR_MEM((VfxWChar *)(ui_info->confirm_popup_para.popup_string));
	popup_button_string1 = VFX_WSTR_MEM((VfxWChar *)(ui_info->confirm_popup_para.popup_button_string1));	

	if (ui_info->confirm_popup_para.confirm_type == VM_COMMON_UI_CONFIRM_TYPE_ONE_BUTTON)
	{
		ui_res_p->gpType = VM_CONFIRM_ONE_BUTTON_STR;	
		popup_grp_id = vapp_nmgr_global_popup_show_confirm_one_button_str(
				MMI_SCENARIO_ID_DEFAULT,
				confirm_popup_type, 
				popup_string, 
				popup_button_string1, 
				VCP_POPUP_BUTTON_TYPE_NORMAL,
				vm_nmgr_confirm_popup_callback,
				(void *)(ui_res_p->m_nResid));
	}
	else if (ui_info->confirm_popup_para.confirm_type == VM_COMMON_UI_CONFIRM_TYPE_TWO_BUTTON)
	{
		ui_res_p->gpType = VM_CONFIRM_TWO_BUTTON_STR;	
		popup_button_string2 = VFX_WSTR_MEM((VfxWChar *)(ui_info->confirm_popup_para.popup_button_string2));
		popup_grp_id = vapp_nmgr_global_popup_show_confirm_two_button_str(
				MMI_SCENARIO_ID_DEFAULT,
				confirm_popup_type, 
				popup_string, 
				popup_button_string1, 
				popup_button_string2, 
				VCP_POPUP_BUTTON_TYPE_NORMAL,
				VCP_POPUP_BUTTON_TYPE_NORMAL,
				vm_nmgr_confirm_popup_callback,
				(void *)(ui_res_p->m_nResid));
	}

	return (VMINT)popup_grp_id;	
}

extern "C" void vm_nmgr_confirm_popup_cancel(VMINT grp_id)
{
	vapp_nmgr_global_popup_cancel((VfxS32)grp_id);
}

#endif /* __COSMOS_MMI_PACKAGE__ */

#endif /* __MRE_CORE_BASE__ */


