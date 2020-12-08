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
 *  vadp_p2v_vip_contact.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Pluto MMI to the Venus
 *  MMI.
 *
 *      Pluto APP ---> p2v adaptor ---> Venus APP
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_3D_CUBE_APP__


#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "trc\vadp_app_trc.h"
#include "vapp_cube_res.h"

#include "CubeApp/vapp_cube_vip_contact.h"
#include "vadp_p2v_cube_vip_contact.h"
#include "vadp_v2p_cube_vip_contact.h"


extern "C"
{
#include "CubeAppProt.h"
#include "CubeAppGprot.h"
#include "PhbSrvGprot.h"
}

static VappCubeVipContactScr *g_cube_vip_contact_scr_handle;

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vip_contact_phb_evt_handler
 * DESCRIPTION
 *  init phonebook notify handler.
 * PARAMETERS
 *  event              [IN]            event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
 mmi_ret vadp_p2v_cube_vip_contact_phb_evt_handler(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_phb_op_evt_struct* evt = (srv_phb_op_evt_struct*)param;
	VfxU8 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_PHB_EVENT, evt->evt_id, evt->store_index);
	
	switch (evt->evt_id)
	{
	case EVT_ID_PHB_UPD_CONTACT:

		// if vip contact page is not active. don't care about this event.
		if (g_cube_vip_contact_scr_handle == NULL)
		{
			break;
		}
		
		for (i = 0; i < VappCubeVipContactScr::TOTAL_CONTACTS; i++)
		{
			if (vadp_v2p_vip_contact_get_index(i) == evt->store_index)
			{
				g_cube_vip_contact_scr_handle->onUpdateCont(i);
								
				break;
			}
		}
		break;
		
	case EVT_ID_PHB_DEL_CONTACT:
		{
			// care this event all the time.
			for (i = 0; i < VappCubeVipContactScr::TOTAL_CONTACTS; i++)
			{
				if (vadp_v2p_vip_contact_get_index(i) == evt->store_index)
				{
					vadp_v2p_vip_contact_clear_index(i);
					
					if (g_cube_vip_contact_scr_handle != NULL)
					{
						g_cube_vip_contact_scr_handle->onUpdateCont(i);
					}
					VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_PHB_EVENT_UPDATE, i);
				}
			}
			
			vadp_v2p_vip_contact_save_setting();
		}
		break;
		
	default:
		break;
	}
	
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTIONf
 *  vadp_p2v_cube_vip_contact_init
 * DESCRIPTION
 *  This function is used to init shell app
 *  buffer.
 * PARAMETERS
 *  idx         : [IN]      screen index
 * RETURNS
 *  S8
 *****************************************************************************/
void *vadp_p2v_cube_vip_contact_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	vadp_v2p_vip_contact_load_setting();
	
    VappCubeScr::initalize();

	VFX_OBJ_CREATE(g_cube_vip_contact_scr_handle, VappCubeVipContactScr, VappCubeScr::getContext());

	// must care this event, phb maybe updated by tools
	mmi_frm_cb_reg_event(EVT_ID_PHB_UPD_CONTACT, vadp_p2v_cube_vip_contact_phb_evt_handler, NULL);

	VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_INIT);
	
    return (void *)g_cube_vip_contact_scr_handle;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vip_contact_deinit
 * DESCRIPTION
 *  This function is used to deinit shell app
 *  buffer.
 * PARAMETERS
 *  idx         : [IN]      screen index
 * RETURNS
 *  S8
 *****************************************************************************/
void vadp_p2v_cube_vip_contact_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_OBJ_CLOSE(g_cube_vip_contact_scr_handle);
	
    VappCubeScr::deinitalize();

	VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_DEINIT);
    return;
}

#endif /* __MMI_VUI_3D_CUBE_APP__ */

