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
 *  DialerCuiSos.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the emergency call dialer.
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

#include "MMIDataType.h"
#include "DialerCuiObject.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "DialerCuiMain.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
#include "DialerCuiCommon.h"
#include "DialerCuiSos.h"
#include "custom_ecc.h"
#include "Unicodexdcl.h"
#include "gdi_include.h"
#include "DialerCuiClassic.h"
#include "wgui_categories_util.h"
#include "wgui_inputs.h"
#include "wgui_categories_CM.h"
#include "DialerCuiGprot.h"
#include "Gpiosrvgprot.h"
#include "mmi_rp_cui_dialer_def.h"

/****************************************************************************
 * Define
 ****************************************************************************/

/* Auto. close timeout value in msec. */
#define CUI_DIALER_SOS_AUTO_CLOSE_TIME          (5000)


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_sos_auto_close_timeout_hdlr
 * DESCRIPTION
 *  This function handles the auto close timeout event.
 * PARAMETERS
 *  user_data               : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_sos_auto_close_timeout_hdlr(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj = (cui_dialer_obj_struct *)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    cui_dialer_emit_close_req(obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_sos_start_auto_close_timer
 * DESCRIPTION
 *  This function starts the auto close timer.
 * PARAMETERS
 *  obj                 : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_sos_start_auto_close_timer(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimerEx(
        EMERGENCY_NO_DIALED_TRANSIANT_SCR_TIMER,
        CUI_DIALER_SOS_AUTO_CLOSE_TIME,
        cui_dialer_sos_auto_close_timeout_hdlr,
        obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_sos_stop_auto_close_timer
 * DESCRIPTION
 *  This function stops the auto close timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_sos_stop_auto_close_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EMERGENCY_NO_DIALED_TRANSIANT_SCR_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_validation_hdlr
 * DESCRIPTION
 *  This function is the callback to check the dial string.
 * PARAMETERS
 *  dial_string             : [IN]          Dial string
 *  cursor_position         : [IN]          Cursor position in the dial string
 *  length                  : [IN]          Dial string length
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_sos_validation_hdlr(
    PU8 dial_string,
    PU8 cursor_position,
    S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj = cui_dialer_get_obj_from_group();
    #if defined(CUI_DIALER_CFG_SOS_DIALER_CLOSE_WITHOUT_LAST_DIGIT)  
    cui_dialer_sos_struct *p;
    #endif
    ecc_verify_detail_enum verify_detail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
    #if defined(CUI_DIALER_CFG_SOS_DIALER_CLOSE_WITHOUT_LAST_DIGIT)  
    p = (cui_dialer_sos_struct *)obj;
    #endif

    /* Restart the auto close timer. */
    cui_dialer_sos_start_auto_close_timer(obj);

    /* Check if the string is an emergency number. */
    if (mmi_wcslen(obj->dial_string) > 0)
    {
        verify_detail = cui_dialer_is_ecc(obj->dial_string);

        if (verify_detail != ECC_PARTIALLY_MATCH &&
            verify_detail != ECC_FULLY_MATCH)
        {
            cui_dialer_emit_close_req(obj);

        #if defined(CUI_DIALER_CFG_SOS_DIALER_CLOSE_WITHOUT_LAST_DIGIT)
            gdi_layer_lock_frame_buffer();
            p->is_frame_locked = MMI_TRUE;
        #endif /* defined(CUI_DIALER_CFG_SOS_DIALER_CLOSE_WITHOUT_LAST_DIGIT) */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_sos_on_enter
 * DESCRIPTION
 *  This function handles the enter action.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_sos_on_enter(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Callback to parent. */
    cui_dialer_classic_on_enter(obj);

    /* Reset string / image on the LSK and CSK. */
    ChangeLeftSoftkey(0, 0);
    ChangeCenterSoftkey(0, 0);

	/* Open screen backlight. */
	srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    /* Setup the dial string validation callback. */
    wgui_inputs_register_validation_func(cui_dialer_sos_validation_hdlr);

    /* Start the auto close timer. */
    cui_dialer_sos_start_auto_close_timer(obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_sos_on_exit
 * DESCRIPTION
 *  This function handless the exit action.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_sos_on_exit(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Stop the auto close timer. */
    cui_dialer_sos_stop_auto_close_timer();

    /* Close the SOS dialer. */
    cui_dialer_emit_close_req(obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_sos_on_set_cat_hdlr
 * DESCRIPTION
 *  This function sets the category handler.
 * PARAMETERS
 *  obj             : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_sos_on_set_cat_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Callback to parent. */
    cui_dialer_classic_on_set_cat_hdlr();

#if defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    /* SOS dialer does not allow to save contact. Disable it. */
    SetDialingKeypadPhonebookHandler(NULL);
#endif

#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) && defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__))
    SetDialingKeypadVideoHandler(NULL);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_sos_on_close
 * DESCRIPTION
 *  This function closes the dialer CUI.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_sos_on_close(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    #if defined(CUI_DIALER_CFG_SOS_DIALER_CLOSE_WITHOUT_LAST_DIGIT)  
    cui_dialer_sos_struct *p = (cui_dialer_sos_struct *)obj;
    #endif /* defined(CUI_DIALER_CFG_SOS_DIALER_CLOSE_WITHOUT_LAST_DIGIT) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	cui_dialer_sos_stop_auto_close_timer();
	
#if defined(CUI_DIALER_CFG_SOS_DIALER_CLOSE_WITHOUT_LAST_DIGIT)
    if (p->is_frame_locked)
    {
        gdi_layer_unlock_frame_buffer();
    }
#endif /* defined(CUI_DIALER_CFG_SOS_DIALER_CLOSE_WITHOUT_LAST_DIGIT) */

    cui_dialer_obj_on_close(obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_sos_on_init
 * DESCRIPTION
 *  This function initializes the SOS dialer object.
 * PARAMETERS
 *  obj             : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_sos_on_init(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_sos_struct *p;
    cui_dialer_capability_struct *capability;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_dialer_classic_on_init(obj);

    p = (cui_dialer_sos_struct *)obj;

    p->type = CUI_DIALER_TYPE_SOS;
    p->on_enter = cui_dialer_sos_on_enter;
    p->on_exit = cui_dialer_sos_on_exit;
    p->on_set_cat_hdlr = cui_dialer_sos_on_set_cat_hdlr;
    p->on_close = cui_dialer_sos_on_close;

    /*
     * Change the capabilities.
     */
    capability = &obj->capability;
	
    memset(capability, 0, sizeof(cui_dialer_capability_struct));
	capability->enable_send = MMI_TRUE;
}

