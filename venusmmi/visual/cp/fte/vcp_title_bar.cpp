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
 *  vcp_title_bar.cpp
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  Title bar component (Adaptor to Pluto UI component )
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_pluto_control.h"
#include "vcp_title_bar.h"

extern "C"
{
    /* Pluto MMI headers */
    #include "MMI_features.h"
    #include "gdi_include.h"

    /* Venus to pluto adaption layer header */
    #include "GUI\vadp_v2p_title_bar.h"    
    #include "MMIDataType.h"
    #include "string.h"
    #include "kal_general_types.h"

}

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_signal.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("PlutoTitleBar", VcpPlutoTitleBar, VcpPlutoControl);


/***************************************************************************** 
 * Global function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  VcpPlutoTitleBar::VcpPlutoTitleBar
 * DESCRIPTION
 *  Constructor of VcpPlutoTitleBar class
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VcpPlutoTitleBar::VcpPlutoTitleBar()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VcpPlutoTitleBar::changeText
 * DESCRIPTION
 *  Change the text of title
 * PARAMETERS
 *  text        [IN]    New text of title
 * RETURNS
 *  void
 *****************************************************************************/
void VcpPlutoTitleBar::changeText(const VfxWString &text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* temp;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = (U8*)text.getBuf();
    if (memcmp(vadp_v2p_get_title_string(), temp, text.getLength()) != 0)
    {
     	vadp_v2p_change_title_bar_text((U8*)text.getBuf());
    	vadp_v2p_show_title_bar();
        //setNeedRedrawPluto();
    }
}


/*****************************************************************************
 * FUNCTION
 *  VcpPlutoTitleBar::changeText
 * DESCRIPTION
 *  Change the text of title
 * PARAMETERS
 *  text        [IN]    New text of title
 * RETURNS
 *  void
 *****************************************************************************/
void VcpPlutoTitleBar::changeTextWithNotUpdate(const VfxWString &text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_change_title_bar_text((U8*)text.getBuf());
}


/*****************************************************************************
 * FUNCTION
 *  VcpPlutoTitleBar::changeLeftIcon
 * DESCRIPTION
 *  Change the left icon of title
 * PARAMETERS
 *  imageId      [IN]    New left icon of title
 * RETURNS
 *  void
 *****************************************************************************/
void VcpPlutoTitleBar::changeLeftIcon(VfxU16 imageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_change_title_bar_left_icon(imageId);
    vadp_v2p_show_title_bar();
    //setNeedRedrawPluto();
}


/*****************************************************************************
 * FUNCTION
 *  VcpPlutoTitleBar::changeRightIcon
 * DESCRIPTION
 *  Change the right icon of title
 * PARAMETERS
 *  imageId   [IN]    New right icon of title
 * RETURNS
 *  void
 *****************************************************************************/
void VcpPlutoTitleBar::changeRightIcon(VfxU16 imageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_change_title_bar_right_icon(imageId);
    vadp_v2p_show_title_bar();
    //setNeedRedrawPluto();
}


/*****************************************************************************
 * FUNCTION
 *  VcpPlutoTitleBar::enableIntegrateTitle
 * DESCRIPTION
 *  Enabe integrate title or not
 * PARAMETERS
 *  enable      [IN]    Enable integrate title or not
 * RETURNS
 *  void
 *****************************************************************************/
void VcpPlutoTitleBar::enableIntegrateTitle(VfxBool enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_enable_integrate_title((MMI_BOOL)enable);
}


/*****************************************************************************
 * FUNCTION
 *  VcpPlutoTitleBar::enableShortcutDisplay
 * DESCRIPTION
 *  Enabe shortcut display or not
 * PARAMETERS
 *  enable      [IN]    Enable shortcut display or not
 * RETURNS
 *  void
 *****************************************************************************/
void VcpPlutoTitleBar::enableShortcutDisplay(VfxBool enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_enable_shortcut_display((MMI_BOOL)enable);
}


/*****************************************************************************
 * FUNCTION
 *  VcpPlutoTitleBar::startScrolling
 * DESCRIPTION
 *  Start title scrolling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpPlutoTitleBar::startScrolling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_start_title_bar_scroll();
}


/*****************************************************************************
 * FUNCTION
 *  VcpPlutoTitleBar::stopScrolling
 * DESCRIPTION
 *  Stop title scrolling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpPlutoTitleBar::stopScrolling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_stop_title_bar_scroll();
}


/*****************************************************************************
 * FUNCTION
 *  VcpPlutoTitleBar::onPlutoCreate
 * DESCRIPTION
 *  Create the pluto component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpPlutoTitleBar::onPlutoCreate()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_create_title_bar(updateScreenForPluto, this, getLayerHandle());
    vadp_v2p_move_title_bar(0, 0);
    m_signalBoundsChanged.connect(this, &VcpPlutoTitleBar::onBoundsValueChange);
}


/*****************************************************************************
 * FUNCTION
 *  VcpPlutoTitleBar::onPlutoClose
 * DESCRIPTION
 *  Close the pluto component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpPlutoTitleBar::onPlutoClose()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_close_title_bar();
}


/*****************************************************************************
 * FUNCTION
 *  VcpPlutoTitleBar::onPlutoDraw
 * DESCRIPTION
 *  Draw the pluto component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpPlutoTitleBar::onPlutoDraw()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_show_title_bar();
}


/*****************************************************************************
 * FUNCTION
 *  VcpPlutoTitleBar::onPlutoGetPreferredSize
 * DESCRIPTION
 *  Get the size of title
 * PARAMETERS
 *  void
 * RETURNS
 *  The size of title
 *****************************************************************************/
VfxSize VcpPlutoTitleBar::onPlutoGetPreferredSize()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 width, height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_get_title_bar_prefered_size(&width, &height);
    return VfxSize(width, height);
}


/*****************************************************************************
 * FUNCTION
 *  VcpPlutoTitleBar::onBoundsValueChange
 * DESCRIPTION
 *  When change the bounday of title, resize the title
 * PARAMETERS
 *  args
 * RETURNS
 *  The size of title
 *****************************************************************************/
 void VcpPlutoTitleBar::onBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxRect rect;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);
    
    rect = getBounds();
    vadp_v2p_move_title_bar(rect.origin.x, rect.origin.y);
    vadp_v2p_resize_title_bar(rect.size.width, rect.size.height);
}


