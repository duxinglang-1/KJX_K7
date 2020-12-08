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
 *  vapp_shell_page_order.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Data service for page order
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

#ifndef __VAPP_SHELL_PAGE_ORDER_H__
#define __VAPP_SHELL_PAGE_ORDER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_APP__

#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vapp_shell_panel_cfg.h"


/***************************************************************************** 
 * Class VdatShellPageOrder
 *****************************************************************************/
/* Example
 *  <Code>
 *
 *  VdatShellPageOrder::PageState state[VdatShellPageOrder::SHELL_AP_TOTAL];
 *  VdatShellPageOrder* order = VFX_OBJ_GET_INSTANCE(VdatShellPageOrder);
 *
 *  VfxBool bRet = order->getOrders(state, VdatShellPageOrder::SHELL_AP_TOTAL);
 *  VdatShellPageOrder::PageState smsState;
 *  bRet = order->getState(&smsState, VdatShellPageOrder::SHELL_AP_SMS);
 *  </Code>
 */
class VdatShellPageOrder: public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VdatShellPageOrder);

public:
     VdatShellPageOrder();
    ~VdatShellPageOrder();
    
	struct PageState
	{
		 VfxU8  value;	// enum value
		 VfxU8 state;	// VFX_TRUE -> ON, VFX_FALSE->OFF
    };
   
    // get one app's state
    VfxBool getState(
            PageState *state,      //[OUT]
            const VfxU16 &index    //[IN]
        );

    VfxBool getOrderById(
            VfxU8 panel_id,
            VfxU8 &order,
            VfxBool &state
        );

    void swapOrder(const VfxU16 &index1, const VfxU16 &index2);
    
    // get one app's state
    VfxBool setState(
            const PageState &state, //[IN]
            const VfxU16    &index  //[IN]
        );

    VfxBool setPanelState(
        const VfxBool &state, 
        const VfxU16 &panelId
        );

    VfxSignal2 <const PageState*, const VfxU16 &> m_signalChange;


private:  	
  void loadOrder(void);
  void saveOrder(void);
  
private:
	PageState m_pOrder[10];
    VfxBool   m_dirty;
};
		
#endif /* __MMI_VUI_SHELL_APP__ */

#endif /* __VAPP_SHELL_SETTINGS_H__ */
