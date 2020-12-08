/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *  Vapp_CBS_main.cpp
 *
 * Project:
 * --------
 *  App CBS
 *
 * Description:
 * ------------
 *  Venus App CBS multi option screen implements for C++
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#include "vapp_cbs_iprot.h"
#include "vapp_cbs_setting_page.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/*****************************************************************************
 * Class Xyz
 ****************************************************************************/


/*****************************************************************************
 * Template Abc
 ****************************************************************************/


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
    #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
#endif
    #if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
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
#endif
    #if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

VcpConfirmPopup *vapp_cbs_show_error_confirm(VfxObject *parent, VfxWString string, VappCbsConfEnum type)
{
	VcpConfirmPopup *errorPrompt = NULL;
	VFX_OBJ_CREATE(errorPrompt, VcpConfirmPopup, parent);

	switch (type)
	{
		case CBS_FAILURE_CONF:
			errorPrompt->setInfoType(VCP_POPUP_TYPE_FAILURE);
			errorPrompt->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
			break;
			
		case CBS_WARNING_CONF:
			errorPrompt->setInfoType(VCP_POPUP_TYPE_WARNING);
			errorPrompt->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
			errorPrompt->setCustomButton((VfxResId)STR_GLOBAL_DELETE, (VfxResId)STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
			break;
			
		case CBS_INFO_CONF:
			errorPrompt->setInfoType(VCP_POPUP_TYPE_INFO);
			errorPrompt->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
			break;
			
		default:
			break;
	}
	errorPrompt->setText(string);
	errorPrompt->setAutoDestory(VFX_TRUE);
	errorPrompt->show(VFX_TRUE);
	return errorPrompt;
}
void vapp_cbs_delete_confirm_str(VfxWString& ask, VfxU32 del_cnt, VappCbsDelStrEnum type)
{
	VfxResId stringID = 0;
	switch (type)
	{
		case CBS_CHANNEL_STR:
			stringID = STR_ID_VAPP_CBS_CHANNEL_DELETE_CONFIRM_1;
			break;
		case CBS_MSG_STR:
			stringID = STR_ID_VAPP_CBS_MSG_LIST_DELETE_CONFIRM_1;
			break;
		default:
			break;
	}
	ask.loadFromRes(stringID);
	VfxWString number;
	number.format("%d", del_cnt);
	ask += VFX_WSTR("(");
	ask += number;
	ask += VFX_WSTR(")");
	ask += VFX_WSTR("?");
}



