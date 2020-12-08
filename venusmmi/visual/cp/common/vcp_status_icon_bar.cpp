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
 *  vcp_status_icon_bar.cpp
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  Status icon bar component (Adaptor to Pluto UI component )
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
#include "vfx_uc_include.h"
#include "vcp_pluto_control.h"
#include "vcp_status_icon_bar.h"

extern "C"
{
    /* Pluto MMI headers */
    #include "MMI_features.h"
    #include "mmi_frm_input_gprot.h"
    #include "gdi_include.h"
    #include "gui_typedef.h"
    #include "wgui_include.h"

    /* Venus to pluto adaption layer header */
    #include "GUI\vadp_v2p_status_icon_bar.h"    
    #include "MMIDataType.h"
    #include "kal_general_types.h"
}
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"

#include "vfx_basic_type.h"


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("StatusIconBar", VcpStatusIconBar, VcpPlutoControl);

/***************************************************************************** 
 * Global function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::VcpStatusIconBar
 * DESCRIPTION
 *  Constructor
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
VcpStatusIconBar::VcpStatusIconBar():
m_translucent(VFX_FALSE),
m_curOpacity(1),
m_init(VFX_TRUE),
m_freeze(VFX_FALSE),
m_barid(0),
m_timer(NULL),
m_enableBackground(VFX_TRUE)
{
    m_curRect = VfxRect(0, 0, 0, 0);
}

/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::showIcon
 * DESCRIPTION
 *  Show an icon with icon ID.
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::showIcon(VfxS32 iconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_show_icon(iconId);
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::blinkIcon
 * DESCRIPTION
 *  Blink an icon with icon ID.
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::blinkIcon(VfxS32 iconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_blink_icon(iconId);
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::animateIcon
 * DESCRIPTION
 *  Animate an icon with icon ID.
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::animateIcon(VfxS32 iconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_animate_icon(iconId);
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::changeIconLevel
 * DESCRIPTION
 *  Change an icon level with icon ID and level percentage (0 ~ 100).
 * PARAMETERS
 *  iconId                  [IN]    icon ID
 *  level_percentage    [IN]    level percetage (0 ~ 100)
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::changeIconLevel(VfxS32 iconId, VfxU8 level_percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_change_icon_level(iconId, level_percentage);
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::changeIconImage
 *  Change an icon's image with icon ID and image ID.
 * PARAMETERS
 *  iconId       [IN]    icon ID
 *  image_id    [IN]    image ID
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::changeIconImage(VfxS32 iconId, VfxU16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_change_icon_image(iconId, image_id);
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::hideEvents
 *  Change an icon's image with icon ID and image ID.
 * PARAMETERS
 *  iconId       [IN]    icon ID
 *  image_id    [IN]    image ID
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::hideEvents(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_status_hide_events();
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::showEvents
 *  Change an icon's image with icon ID and image ID.
 * PARAMETERS
 *  iconId       [IN]    icon ID
 *  image_id    [IN]    image ID
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::showEvents(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_status_show_events();
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::showEvents
 *  Change an icon's image with icon ID and image ID.
 * PARAMETERS
 *  iconId       [IN]    icon ID
 *  image_id    [IN]    image ID
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::registerTapProc(FuncPtr handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_status_register_tap_proc(handler);
}



/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::enableBackground
 *  Enable background or disable
 * PARAMETERS
 *  enable       [IN]    Enable background or not.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::enableBackground(VfxBool enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m_enableBackground = enable;
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::closeClock
 *  Close clock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::closeClock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_status_icon_bar_close_clock();
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::onPlutoCreate
 * DESCRIPTION
 *  Create the pluto control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::onPlutoCreate()
{

	m_chain_node.instance = this;
	m_chain_node.update_screen_callback = updateScreenForPlutoNeedRedraw;
	vadp_v2p_status_icon_bar_add_instance(&m_chain_node);   
	vadp_v2p_status_icon_bar_set_layer(getLayerHandle());
    vadp_v2p_hide_statusbar(MMI_FALSE);
    setFreeze(m_freeze);

	VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setOpacity(m_curOpacity);
    VfxAutoAnimate::commit();
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::onPlutoClose
 * DESCRIPTION
 *  Close the pluto control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::onPlutoClose()
{
	vadp_v2p_status_icon_bar_set_layer(NULL);
    vadp_v2p_reset_status_translucent();
    vadp_v2p_set_statusbar_BG(0);   
    vadp_v2p_status_icon_bar_set_backgroud(MMI_FALSE);

    vadp_v2p_status_icon_bar_del_instance(&m_chain_node);
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::onPlutoDraw
 * DESCRIPTION
 *  Draw the pluto control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::onPlutoDraw()
{
	
	if (m_init)
    {
        m_curRect = this->getBounds();
        m_init = VFX_FALSE;
    }
    else
    {
        VfxSize(m_curRect.size.width, m_curRect.size.height);
    }

	vadp_v2p_status_icon_bar_set_layer(getLayerHandle());
    if(m_translucent)
    {
        vadp_v2p_set_status_translucent();
    }
    else
    {
        vadp_v2p_reset_status_translucent();
    }
    vadp_v2p_set_statusbar_BG(m_barid);
    vadp_v2p_status_icon_bar_set_backgroud(m_enableBackground ? MMI_TRUE : MMI_FALSE);

    vadp_v2p_show_status_icon_bar();
    
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::setTranslucent
 * DESCRIPTION
 *  Draw the pluto control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::setTranslucent(VfxBool translucent)
{
    m_translucent = translucent;
    if(getLayerHandle() != NULL)
    {
        updateScreenForPlutoNeedRedraw(this);
    }
}

/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::setEnable
 * DESCRIPTION
 *  Enable or disable status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::setEnable(VfxBool enable)
{
    if (enable)
    {
        m_curOpacity  = 1;
    }
    else
    {
        m_curOpacity = 0;
    }
  
        if ((!VfxAutoAnimate::getDisable()) && this->getAutoAnimate() && !m_curOpacity)
        {
            if (!m_timer)
            {
                VFX_OBJ_CREATE(m_timer, VfxTimer, this);
            }
            m_timer->setStartDelay(VfxAutoAnimate::getDuration());
            m_timer->m_signalTick.connect(this, &VcpStatusIconBar::onTimer);
            m_timer->start();

        }
        else 
        {
            this->setHidden(!m_curOpacity);
            vadp_v2p_hide_statusbar((MMI_BOOL)!m_curOpacity);
        }
        if (enable)
        {
            if (m_timer)
            {
                m_timer->stop();
            }
            setFreeze(VFX_FALSE);
        }
        setOpacity(m_curOpacity);
        updateScreenForPlutoNeedRedraw(this);
}


void VcpStatusIconBar::onTimer(VfxTimer* pTime)
{
    this->setHidden(VFX_TRUE);
    vadp_v2p_hide_statusbar(MMI_TRUE);
    setFreeze(VFX_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::setFreeze
 * DESCRIPTION
 *  Freeze or unfreeze status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::setFreeze(VfxBool freeze)
{
    VfxScreen * screen;

    screen = findScreen();
    m_freeze = freeze;
    if (screen != NULL && screen == (VFX_OBJ_GET_INSTANCE(VfxTopLevel))->getActiveScr())
    {
        vadp_v2p_set_statusbar_freeze(freeze ? MMI_TRUE : MMI_FALSE);
    }
}



/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::onPenInput
 * DESCRIPTION
 *  Draw the pluto control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxBool VcpStatusIconBar::onPenInput(VfxPenEvent &event)
{    
    VfxBool ret = VFX_TRUE;
#ifdef __MMI_TOUCH_SCREEN__
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        vadp_v2p_status_translate_pen_event(MMI_PEN_EVENT_DOWN, event.pos.x, event.pos.y);
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        vadp_v2p_status_translate_pen_event(MMI_PEN_EVENT_MOVE, event.pos.x, event.pos.y);
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        vadp_v2p_status_translate_pen_event(MMI_PEN_EVENT_UP, event.pos.x, event.pos.y);
    }
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    else if(event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        if(!vadp_v2p_status_is_in_ncenter())
        {
            vadp_v2p_statusbar_abort_enter_ncenter();
        }
    }
#endif
#endif /* __MMI_TOUCH_SCREEN__ */
    return ret;


}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::onPlutoGetPreferredSize
 * DESCRIPTION
 *  Get the preferred size of pluto control
 * PARAMETERS
 *  void
 * RETURNS
 *  Return size of control
 *****************************************************************************/
VfxSize VcpStatusIconBar::onPlutoGetPreferredSize()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_get_prefered_size(&width, &height);

    return VfxSize(width, height);
}

void VcpStatusIconBar::setStatusbarBG(VfxS32 id)
{
    m_barid = id;
    if(getLayerHandle() != NULL)
    {
        updateScreenForPlutoNeedRedraw(this);
    }
}

