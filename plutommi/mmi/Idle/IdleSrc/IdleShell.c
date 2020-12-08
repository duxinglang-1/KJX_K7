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
 *  IdleVhs.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the Shell home screen.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_SHELL_APP__)

#include "IdleAppProt.h"

/* Venus MMI headers: */
#include "ui_core\base\vfx_base.h"
#include "HomeScreen\vadp_p2v_hs.h"
#include "OP01HomeScreen\vadp_p2v_op01_hs.h"

/* Pluto MMI headers: */
#include "IdleShell.h"
#include "ShellAppGprot.h"
#include "MMIDataType.h"
#include "wgui_categories_idlescreen.h"
#include "IdleObject.h"
#include "IdleCommon.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "SATGProts.h"
#include "IdleGprot.h"


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_shell_update_idle_text
 * DESCRIPTION
 *  This function updates the idle text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_shell_update_idle_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Idle mode text and icon. */
    vadp_p2v_hs_set_idle_mode_text((U8 *)wgui_cat033_get_extra_text());
    vadp_p2v_hs_set_idle_mode_icon((U8 *)GetSATIdleIcon());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_shell_on_enter
 * DESCRIPTION
 *  This function is the enter function.
 * PARAMETERS
 *  obj             : [IN]          Idle object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_shell_on_enter(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_shell_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (mmi_idle_shell_struct *)obj;

    mmi_shell_vapp_show_homescreen();

    mmi_idle_set_handler((mmi_idle_obj_struct *)p);

    ClearKeyEvents();

    mmi_idle_sublcd_display();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_shell_on_update_service_indication
 * DESCRIPTION
 *  This function updates the service indication.
 * PARAMETERS
 *  obj             : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_shell_on_update_service_indication(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_service_indication_struct *service_indication;
    WCHAR *str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_update_service_indication_context(obj);

    service_indication = mmi_idle_get_service_indication_context(obj, MMI_SIM1);

    str = (mmi_wcslen(service_indication->line1) ? service_indication->line1 : NULL);
    vadp_p2v_hs_set_network_name((U8 *)str);

    str = (mmi_wcslen(service_indication->line2) ? service_indication->line2 : NULL);
    vadp_p2v_hs_set_network_status((U8 *)str);

#if defined(__MMI_DUAL_SIM__)
    service_indication = mmi_idle_get_service_indication_context(obj, MMI_SIM2);

    str = (mmi_wcslen(service_indication->line1) ? service_indication->line1 : NULL);
    vadp_p2v_hs_set_network_name_2((U8 *)str);

    str = (mmi_wcslen(service_indication->line2) ? service_indication->line2 : NULL);
    vadp_p2v_hs_set_network_status_2((U8 *)str);
#endif /* defined(__MMI_DUAL_SIM__) */

    /*
     * TODO: category should export the API to update it specifically. Should
     *       not duplicate the dispatching condition in the function.
     */
    idle_screen_show_network_details();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_shell_on_init
 * DESCRIPTION
 *  This function initializes the idle object.
 * PARAMETERS
 *  obj           : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_shell_on_init(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_shell_struct *p;
    U32 *capability;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_on_init(obj);

    p = (mmi_idle_shell_struct *)obj;

    /* Member variable. */
    p->type = MMI_IDLE_TYPE_SHELL;

    /* Member function. */
    p->on_enter = mmi_idle_shell_on_enter;
    p->on_update_service_area = mmi_idle_shell_on_update_service_indication;

    /* Change the capabilities. */
    capability = &obj->capability;

    *capability &= ~ENABLE_SOFT_KEY_AREA;
    *capability &= ~ENABLE_CENTER_SOFT_KEY;

#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    /*
     * Shell already has a touch button to lock the handset. No need to use END
     * key to lock the handset.
     */
    *capability &= ~ENABLE_END_KEY;
#endif /* defined(__MMI_VUI_SHELL_MULTI_PAGE__) */
}


#endif /* defined(__MMI_VUI_SHELL_APP__) */

