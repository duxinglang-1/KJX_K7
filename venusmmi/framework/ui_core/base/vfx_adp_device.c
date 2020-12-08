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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vfx_system.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Hardware Device Adapatation Layer
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_adp_device.h"

#include "vfx_datatype.h"


/* For LCD backlight */
#include "GpioSrvGProt.h"

/* For Screen Rotation Sensor */
#include "mdi_datatype.h"    
#include "ScreenRotationGProt.h"

/* For Touch Feedback */
#include "gui_touch_feedback.h"

/* For Sleep In/Out */
#include "vfx_mmi.h"


/***************************************************************************** 
 * Pre-Declaration
 *****************************************************************************/
extern void gui_touch_feedback_enable_tone_internal(void);
extern void gui_touch_feedback_disable_tone_internal(void);
extern void gui_touch_feedback_enable_vibrate_internal(void);
extern void gui_touch_feedback_disable_vibrate_internal(void);


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/

static vfx_adp_sleep_mode_state_enum g_vfx_adp_sleep_mode_state = VFX_ADP_SLEEP_MODE_STATE_ENABLE;
static VfxS8 g_vfx_adp_srs_enable = 0;
static VfxS32 g_vfx_adp_pause_count = 0;
static VfxScrRotateTypeEnum g_vfx_adp_rotate_type_enum = VFX_SCR_ROTATE_TYPE_NORMAL;
static VfxScrRotateTypeEnum g_vfx_adp_rotate_callback_type_enum = VFX_SCR_ROTATE_TYPE_NORMAL;


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

static VfxScrRotateTypeEnum vfx_adp_srs_change_enum_type(mmi_frm_screen_rotate_enum type)
{
    switch (type)
    {
    default:
    case MMI_FRM_SCREEN_ROTATE_0:
        return VFX_SCR_ROTATE_TYPE_0;
    case MMI_FRM_SCREEN_ROTATE_90:
        return VFX_SCR_ROTATE_TYPE_90;
    case MMI_FRM_SCREEN_ROTATE_180:
        return VFX_SCR_ROTATE_TYPE_180;
    case MMI_FRM_SCREEN_ROTATE_270:
        return VFX_SCR_ROTATE_TYPE_270;
    }
}


static mmi_ret vfx_adp_srs_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_auto_rotate_evt_struct *evt = (mmi_frm_auto_rotate_evt_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vfx_adp_pause_count > 0)
    {
        g_vfx_adp_rotate_callback_type_enum = vfx_adp_srs_change_enum_type(mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_DEFAULT));
        return MMI_RET_OK;
    }

    if (!g_vfx_adp_srs_enable || evt->evt_id != EVT_ID_ORIENTATION_CHANGED)
    {
        return MMI_RET_DONT_CARE;
    }

    vfx_adp_srs_on_rotate(vfx_adp_srs_change_enum_type(evt->new_degree));
        
    return MMI_RET_OK;
}


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

vfx_adp_sleep_mode_state_enum vfx_adp_sleep_mode_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vfx_adp_sleep_mode_state;
}


extern mmi_ret vfx_adp_lcd_sleepout_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret vRet = MMI_RET_ERR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vfx_adp_sleep_mode_state == VFX_ADP_SLEEP_MODE_STATE_ENABLE)
    {
        return MMI_RET_OK;
    }
    vRet = vfx_mmi_lcd_sleepout_handler(evt);
    g_vfx_adp_sleep_mode_state = VFX_ADP_SLEEP_MODE_STATE_ENABLE;
    return vRet;
}


extern mmi_ret vfx_adp_lcd_sleepin_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret vRet = MMI_RET_ERR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vfx_adp_sleep_mode_state == VFX_ADP_SLEEP_MODE_STATE_DISABLE)
    {
        return MMI_RET_OK;
    }
    vRet = vfx_mmi_lcd_sleepin_handler(evt);
    g_vfx_adp_sleep_mode_state = VFX_ADP_SLEEP_MODE_STATE_DISABLE;
    return vRet;
}




void vfx_adp_srs_enable(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vfx_adp_srs_enable)
    {
        return;
    }

    mmi_frm_cb_reg_event(EVT_ID_ORIENTATION_CHANGED, vfx_adp_srs_callback, NULL);
    g_vfx_adp_srs_enable = 1;
}


void vfx_adp_srs_disable(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vfx_adp_srs_enable)
    {
        return;
    }

    mmi_frm_cb_dereg_event(EVT_ID_ORIENTATION_CHANGED, vfx_adp_srs_callback, NULL);
    g_vfx_adp_srs_enable = 0;
}


VfxScrRotateTypeEnum vfx_adp_srs_get_value()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vfx_adp_pause_count > 0)
    {
        return g_vfx_adp_rotate_type_enum;
    }

    return vfx_adp_srs_change_enum_type(mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_DEFAULT));
}


VfxS32 vfx_adp_srs_is_paused(void)
{
    return g_vfx_adp_pause_count;
}


void vfx_adp_srs_pause(void)
{
    if (g_vfx_adp_pause_count == 0)
    {
        g_vfx_adp_rotate_type_enum = vfx_adp_srs_get_value();
        g_vfx_adp_rotate_callback_type_enum = g_vfx_adp_rotate_type_enum;
    }
    g_vfx_adp_pause_count++;
}


void vfx_adp_srs_resume(void)
{
    VFX_ASSERT(g_vfx_adp_pause_count > 0);
    VFX_ASSERT(g_vfx_adp_pause_count < 10);

    g_vfx_adp_pause_count--;

    if (g_vfx_adp_pause_count == 0)
    {
        if(g_vfx_adp_rotate_type_enum != g_vfx_adp_rotate_callback_type_enum)
        {
            g_vfx_adp_rotate_type_enum = g_vfx_adp_rotate_callback_type_enum;
            vfx_adp_srs_on_rotate(g_vfx_adp_rotate_callback_type_enum);
        }
    }
}


void vfx_adp_touch_fb_enable_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_touch_feedback_enable_tone();
}


void vfx_adp_touch_fb_disable_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_touch_feedback_disable_tone();
}


void vfx_adp_touch_fb_enable_vibrate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_touch_feedback_enable_vibrate();
}


void vfx_adp_touch_fb_disable_vibrate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_touch_feedback_disable_vibrate();
}


void vfx_adp_touch_fb_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_touch_feedback_enable_tone();
    gui_touch_feedback_enable_vibrate();
}


void vfx_adp_touch_fb_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_touch_feedback_disable_vibrate();
    gui_touch_feedback_disable_tone();
}


void vfx_adp_touch_fb_play(vfx_adp_touch_fb_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const gui_touch_feedback_enum table[VFX_ADP_TOUCH_FB_TYPE_END_OF_ENUM] =
    {
        GUI_TOUCH_FEEDBACK_DOWN,
        GUI_TOUCH_FEEDBACK_DOWN_VIBRATE,
        GUI_TOUCH_FEEDBACK_DOWN_TONE,
        GUI_TOUCH_FEEDBACK_HOLD,
        GUI_TOUCH_FEEDBACK_SPECIAL
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(type < VFX_ADP_TOUCH_FB_TYPE_END_OF_ENUM);
        
    gui_touch_feedback_play(table[type]);
}

