/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  IdleOp11v32.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the OP11 v32 idle screen.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)

#include "HomeScreenOp11V32Gprot.h"

// TODO: phase out this.
//#include "IdleAppDef.h"
#include "IdleAppProt.h"

// auto add by kw_check begin
#include "IdleObject.h"
#include "IdleOp11v32.h"
#include "IdleCommon.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "IdleGprot.h"
 // auto add by kw_check end 

/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_op11v32_on_enter
 * DESCRIPTION
 *  This function is the enter function.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_op11v32_on_enter(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_op11v32_struct *p;

    p = (mmi_idle_op11v32_struct *)obj;

    mmi_op11_hs32_entry_homescreen();

    mmi_idle_set_handler((mmi_idle_obj_struct *)p);

    ClearKeyEvents();
    
    mmi_idle_sublcd_display();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_op11v32_on_update_service_indication
 * DESCRIPTION
 *  This function updates the service indication.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_op11v32_on_update_service_indication(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_service_indication_struct *service_indication;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_update_service_indication_context(obj);

    service_indication = mmi_idle_get_service_indication_context(obj, MMI_SIM1);

    mmi_op11_hs32_update_idle_text(service_indication->line1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_op11v32_on_before_enter
 * DESCRIPTION
 *  This function updates the service area.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_op11v32_on_before_enter(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_op11_hs32_discard_history();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_op11v32_on_want_to_run
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_idle_op11v32_on_want_to_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Ask parent.
     */
    if (!mmi_idle_obj_on_want_to_run())
    {
        return MMI_FALSE;
    }

    return mmi_op11_hs32_is_enable();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_op11v32_on_init
 * DESCRIPTION
 *  This function initializes the idle object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_op11v32_on_init(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_op11v32_struct *p;
    U32 *capability;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_on_init(obj);

    p = (mmi_idle_op11v32_struct *)obj;

    /* Member variable. */
    p->type = MMI_IDLE_TYPE_OP11V32;

    /* Member function. */
    p->on_enter = mmi_idle_op11v32_on_enter;
    p->on_update_service_area = mmi_idle_op11v32_on_update_service_indication;
    p->on_before_idle_display = mmi_idle_op11v32_on_before_enter;

    /* Change the capabilities. */
    capability = &obj->capability;

    *capability &= ~ENABLE_LEFT_SOFT_KEY;
    *capability &= ~ENABLE_RIGHT_SOFT_KEY;
    *capability &= ~ENABLE_SEND_KEY;
    *capability &= ~ENABLE_NAVIGATION_KEY ;
    *capability &= ~ENABLE_END_KEY;
    *capability &= ~ENABLE_CENTER_SOFT_KEY;

}

#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

