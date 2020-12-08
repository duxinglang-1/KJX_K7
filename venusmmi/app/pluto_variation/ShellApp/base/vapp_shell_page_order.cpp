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
 *  vapp_shell_page_order.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Shell ap page order class implementation. the order will permnently exist
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_APP__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "string.h"

#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_system.h"
#include "vfx_signal.h"
#include "vapp_shell_page_order.h"
#include "vapp_shell_panel_cfg.h"
#include "vadp_app_trc.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_trace.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Definition
 *****************************************************************************/
#define RETURN_IF_FAIL(p) if(!(p)){return;}
#define RETURN_VAL_IF_FAIL(p, ret) if(!(p)){ return (ret);}

/***************************************************************************** 
 * class VdatShellPageOrder
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VdatShellPageOrder);
VdatShellPageOrder::VdatShellPageOrder() : m_dirty(VFX_TRUE)
{
	// Panel ID don't wrap compile option
    //VFX_ALLOC_MEM(m_pOrder, sizeof(PageState) * VAPP_SHELL_PANEL_ID_TOTAL, this);
}

VdatShellPageOrder::~VdatShellPageOrder()
{
	//VFX_FREE_MEM(m_pOrder);
}

VfxBool VdatShellPageOrder::setPanelState(const VfxBool &state, const VfxU16 &panelId)
{
	RETURN_VAL_IF_FAIL((panelId < VAPP_SHELL_PANEL_ID_TOTAL), VFX_FALSE);

	for (VfxS32 i = 0; i < VAPP_SHELL_PANEL_ID_TOTAL; i++)
	{
		if (m_pOrder[i].value == panelId &&
			panelId < VAPP_SHELL_PANEL_TOTAL)
		{
			m_pOrder[i].state = state ? 1 : 0;
			
			break;
		}
	}

	VFX_LOG(VFX_INFO, VAPP_SHELL_ORDER_SET_PANEL_STATE, panelId, state);
	
	saveOrder();

	m_signalChange.emit(m_pOrder, VAPP_SHELL_PANEL_ID_TOTAL);

	return VFX_TRUE;
}


void VdatShellPageOrder::swapOrder(const VfxU16 & index1, const VfxU16 & index2)
{
	RETURN_IF_FAIL(index1 < VAPP_SHELL_PANEL_ID_TOTAL);
	RETURN_IF_FAIL(index2 < VAPP_SHELL_PANEL_ID_TOTAL);

	vfxSwap<PageState>(m_pOrder[index1], m_pOrder[index2]);

	saveOrder();

	VFX_LOG(VFX_INFO, VAPP_SHELL_ORDER_SWAP, index1, index2);

	m_signalChange.emit(m_pOrder, VAPP_SHELL_PANEL_ID_TOTAL);
}


VfxBool VdatShellPageOrder::setState(const PageState &state, const VfxU16 &index)
{
	RETURN_VAL_IF_FAIL((index < VAPP_SHELL_PANEL_ID_TOTAL), VFX_FALSE);
	memcpy(&m_pOrder[index], &state, sizeof(PageState));

	saveOrder();
	
	VFX_LOG(VFX_INFO, VAPP_SHELL_ORDER_SET_STATE, index, state.value, state.state);

	m_signalChange.emit(m_pOrder, VAPP_SHELL_PANEL_ID_TOTAL);

	return VFX_TRUE;
}

VfxBool VdatShellPageOrder::getState(PageState * state, const VfxU16 & index)
{
	RETURN_VAL_IF_FAIL((state != NULL && index < VAPP_SHELL_PANEL_ID_TOTAL), VFX_FALSE);

	loadOrder();

	state->state = m_pOrder[index].state;
	state->value = m_pOrder[index].value;
	
	VFX_LOG(VFX_INFO, VAPP_SHELL_ORDER_GET_STATE, index, state->value, state->state);
	
	return VFX_TRUE;
}

VfxBool VdatShellPageOrder::getOrderById(
                                VfxU8 panel_id, VfxU8 &order, VfxBool &state)
{
    /* it will only be loaded at first time */
    loadOrder();
	
	VfxBool ret = VFX_FALSE;
	
    /* get order by panel id */
    for (VfxU8 i = 0; i < VAPP_SHELL_PANEL_ID_TOTAL; i++)
    {
        if (m_pOrder[i].value == panel_id)
        {
            order = i;
            state = (m_pOrder[i].state != 0);
            
            ret = VFX_TRUE;
	    break;
        }
    }    

	VFX_LOG(VFX_INFO, VAPP_SHELL_ORDER_GET_BY_INDEX, ret, panel_id, order, state);

	return ret;
}

void VdatShellPageOrder::loadOrder(void)
{
	VFX_LOG(VFX_INFO, VAPP_SHELL_ORDER_LOAD, m_dirty);
	
	if (m_dirty)
	{
		VfxS16 error;

		ReadRecord(NVRAM_EF_VENUS_SHELL_PAGE_ORDER_LID, 
				   1, 
				   m_pOrder, 
				   NVRAM_EF_VENUS_SHELL_PAGE_ORDER_SIZE, 
				   &error);

		VFX_LOG(VFX_INFO, 
				VAPP_SHELL_ORDER_LOAD_DETAIL, 
				m_pOrder[0].value,
				m_pOrder[0].state,
				m_pOrder[1].value,
				m_pOrder[1].state,
				m_pOrder[2].value,
				m_pOrder[2].state,
				m_pOrder[3].value,
				m_pOrder[3].state,
				m_pOrder[4].value,
				m_pOrder[4].state,
				m_pOrder[5].value,
				m_pOrder[5].state,
				m_pOrder[6].value,
				m_pOrder[6].state,
				m_pOrder[7].value,
				m_pOrder[7].state
				);
		
		// Its the first time to load the order
		if (m_pOrder[0].value == 0xFF)
		{
			// the order in config panel will the right order.
			for (VfxS32 i = 0; i < VAPP_SHELL_PANEL_TOTAL; i++)
			{
				m_pOrder[i].value = g_vapp_shell_panel_create_tbl[i].panel_id;
				m_pOrder[i].state = 1;
			}
			
			saveOrder();
		}
		
		m_dirty = VFX_FALSE;
	}
}

void VdatShellPageOrder::saveOrder(void)
{
	VfxS16 error;
	
	WriteRecord(NVRAM_EF_VENUS_SHELL_PAGE_ORDER_LID, 
		    1, 
		    m_pOrder, 
		    NVRAM_EF_VENUS_SHELL_PAGE_ORDER_SIZE, 
		    &error);
}
		
#endif /* __MMI_VUI_SHELL_SETTINGS__ */

