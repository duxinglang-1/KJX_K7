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
 *  vcp_vk.cpp
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  Virtual keyboard class
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
//TODO MAKE COMMMON APIS stay in combined macro

extern "C"
{
#include "MMI_features.h"
}
#if  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)

#include "vcp_vk.h"
VcpVKAllowedDisabledCharBtn m_disabledAllowedCharBtns;

#if  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
extern "C"
{
#include "mmi_rp_srv_virtual_keyboard_misc_def.h"
#include "gui_virtual_keyboard_language_type.h"
#include "GlobalResDef.h"
#include "ImmProt.h"
#include "ImeGprot.h"
}

//#include "vcp_vk.h"
#include "vfx_auto_animate.h"
#include "vfx_adp_device.h"
#include "mmi_rp_srv_input_method_def.h"

#if defined(__MMI_INDIC_ALG__)
extern "C"
{
	#include  "IndicEngineGprot.h"
}
#endif


#if defined(__MMI_IME_V3__) && !defined(__NO_HANDWRITING__)
extern "C"
{

void mmi_imui_get_handwriting_area(mmi_pen_handwriting_area_struct *rect);
}
#endif

/***************************************************************************** 
* Defination
*****************************************************************************/
// the max value of content of character button
#define VCP_VK_CONTENT_CHARACTER_MAX            ((VfxU32)(0xFFFF))

// the delay of longtap signal
#define VCP_VK_LONGTAP_DELAY                    600
#define VCP_VK_REPEAT_DELAY                     150

// the delay of the popup to hide
#define VCP_VK_POPUP_HIDE_DELAY                 100


#define VCP_VK_POPUP_GAP                        11
#define VCP_VK_LONGTAP_POPUP_GAP                        11


#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define VCP_VK_LONGTAP_BUTTON_X_OFFSET          10
#define VCP_VK_LONGTAP_BUTTON_Y_OFFSET          10
#elif defined(__MMI_MAINLCD_320X480__)
#define VCP_VK_LONGTAP_BUTTON_X_OFFSET          24
#define VCP_VK_LONGTAP_BUTTON_Y_OFFSET          11
#else
#define VCP_VK_LONGTAP_BUTTON_X_OFFSET          15
#define VCP_VK_LONGTAP_BUTTON_Y_OFFSET          11
#endif

/***************************************************************************** 
* Class VcpVKLayoutAdp
*****************************************************************************/
extern "C"
{
	#include "BIDIGProt.h"
#include "PixcomFontEngine.h"

}
extern BOOL r2lMMIFlag ;
VfxResId VcpVKLayoutAdp::getBgImage()
{
    return (VfxResId)wgui_virtual_keyboard_get_vk_bg_img();
}


VfxU16 VcpVKLayoutAdp::getButtonCount()
{
    return wgui_virtual_keyboard_get_button_count( );
}


VfxU32 VcpVKLayoutAdp::getButtonContent(VfxU16 index, mmi_pen_event_type_enum pen_event)
{
    return wgui_virtual_keyboard_get_button_code(index,pen_event);
}

VfxU32 VcpVKLayoutAdp::getButtonContentpointer(VfxU16 index, mmi_pen_event_type_enum pen_event)
{
    //code here
    return wgui_virtual_keyboard_get_button_code_pointer(index,pen_event);
}


VfxU32 VcpVKLayoutAdp::getButtonContenttype(VfxU16 index , mmi_pen_event_type_enum pen_event)
{
    VfxU32 type = wgui_virtual_keyboard_get_button_code_type(index,pen_event);
    if(type ==GUI_VKBD_PEN_CHAR_I)
        return VCP_VK_BUTTON_TYPE_CHAR;
    else if (type ==GUI_VKBD_PEN_V3_CHAR_I_STRING)
        return VCP_VK_BUTTON_TYPE_STRING;
    else 
        return VCP_VK_BUTTON_TYPE_FUNC;

}

VfxU32 VcpVKLayoutAdp::getButtonContent(
VfxU16 index  // [IN] the index of button
)
{
    return getButtonContent(index , MMI_PEN_EVENT_UP);
}

VfxU32 VcpVKLayoutAdp::getMarginWidth(VfxU32 index)
{ 
    return wgui_virtual_keyboard_get_margin_x(  index);
}


VfxU32  VcpVKLayoutAdp::getMarginHeight(VfxU32 index)
{
    return wgui_virtual_keyboard_get_margin_y(index);
}

VfxBool VcpVKLayoutAdp::isRotated()
{
    return wgui_virtual_keyboard_is_rotate_vk() ? VFX_TRUE : VFX_FALSE;
}


VfxBool VcpVKLayoutAdp::isShiftEnable()
{
    return wgui_virtual_keyboard_is_shift_state() ? VFX_TRUE : VFX_FALSE;
}


VfxBool VcpVKLayoutAdp::isCached()
{
    return wgui_virtual_keyboard_is_cache() ? VFX_TRUE : VFX_FALSE;
}

void VcpVKLayoutAdp::getSize(VfxS32 *width,VfxS32 *height)
{
    (*width) = wgui_virtual_keyboard_get_vk_width();
    (*height) = wgui_virtual_keyboard_get_vk_height();
}


gui_virtual_keyboard_key_state_enum VcpVKLayoutAdp::getButtonType(VcpVKBtnStateEnum type)
{
    gui_virtual_keyboard_key_state_enum ret = GUI_VK_KEY_STATE_NONE;
    switch(type)
    {
    case VCP_VK_BUTTON_STATE_NORMAL:
        ret = GUI_VK_KEY_STATE_NORMAL;
        break;
    case VCP_VK_BUTTON_STATE_HILITE:
        ret = GUI_VK_KEY_STATE_HIGHLIGHT;
        break;
    case VCP_VK_BUTTON_STATE_POPUP:
        ret = GUI_VK_KEY_STATE_POPUP;
        break;
    case VCP_VK_BUTTON_STATE_DISABLED:
        ret = GUI_VK_KEY_STATE_NORMAL;
        break;
    default :
        ASSERT(0);
    }
    return ret;
}

/* i think the data layer must provide api which only give intended values ; otherwise lot of wasted CALLs*/
void VcpVKLayoutAdp::getButtonRect
(VfxU16 index, VfxS32 *x, VfxS32 *y, VfxS32 *width, VfxS32 *height , VcpVKBtnStateEnum flag)
{
    VfxS32 x_pos, y_pos , w , h;

    if (flag != VCP_VK_BUTTON_STATE_POPUP)
{
    wgui_virtual_keyboard_get_button_rect( 
        index,
        &x_pos, 
        &y_pos , 
        &w , 
        &h/* , getButtonType(flag) */ );
}
else
{
	wgui_virtual_keyboard_get_popup_hint_rect(
		index,
        &x_pos, 
        &y_pos , 
        &w , 
        &h
		);
}
    *(x) =x_pos ;
    *(y) =y_pos ;
    *(width) = w;
    *(height) = h;

}


VfxResId VcpVKLayoutAdp::getButtonBgImage(VfxU16 index,VcpVKBtnStateEnum flag  )
{
    return wgui_virtual_keyboard_get_button_bg_image( index, getButtonType(flag));
}

VfxRect VcpVKLayoutAdp::getButtonIconRect(VfxU16 index,VcpVKBtnStateEnum flag  )
{
    U16  icon;
    S32 x , y , height, width;   
    wgui_virtual_keyboard_get_button_icon_rect(
        index, 
        getButtonType(flag),
        &x,
        &y,
        &width , 
        &height);

    return  VfxRect(x,y,width,height);
}


VfxRect VcpVKLayoutAdp::getButtonIconRectAux(VfxU16 index,VcpVKBtnStateEnum flag  )
{
    U16  icon;
    S32 x , y , height, width;   
    wgui_virtual_keyboard_get_button_icon_aux_rect(
        index, 
        getButtonType(flag),
        &x,
        &y,
        &width , 
        &height);

    return  VfxRect(x,y,width,height);
}


VfxResId VcpVKLayoutAdp::getButtonIcon(VfxU16 index,VcpVKBtnStateEnum flag  )
{
    U16  icon;
    U32 x , y;

    wgui_virtual_keyboard_get_button_icon( 
        index,
        getButtonType(flag),
        &icon,
        &(x),
        &(y));
    return (VfxResId)icon;
}


VfxResId VcpVKLayoutAdp::getButtonIconAux(VfxU16 index,VcpVKBtnStateEnum flag  )
{
    U16  icon;
    U32 x , y;

    wgui_virtual_keyboard_get_button_icon_aux( 
        index,
        getButtonType(flag),
        &icon,
        &(x),
        &(y));


    return (VfxResId)icon;

}

VfxS32 VcpVKLayoutAdp::getLabelBaseline(void)
{
	return labelBaseLine ;
}

VfxS32 VcpVKLayoutAdp::getLabelAuxBaseline(void)
{
	return labelAuxBaseLine ;
}

VfxRect VcpVKLayoutAdp::getButtonLabelRect(VfxU16 index,VcpVKBtnStateEnum flag  )
{
    S32 x , y , height, width;

    wgui_virtual_keyboard_get_button_label_rect( 
        index, 
        getButtonType(flag),
        &x,
        &y,
        &width , 
        &height,
		&labelBaseLine);

    return  VfxRect(x,y,width,height);

}

VfxRect VcpVKLayoutAdp::getButtonLabelRectAux(VfxU16 index,VcpVKBtnStateEnum flag )
{
    S32 x , y , height, width;
    wgui_virtual_keyboard_get_button_label_aux_rect( 
        index, 
        getButtonType(flag),
        &x,
        &y,
        &width , 
        &height,
		&labelAuxBaseLine);

    return  VfxRect(x,y,width,height);

}


VfxWString VcpVKLayoutAdp::getButtonLabel(VfxU16 index,VcpVKBtnStateEnum flag  )
{

    U32 x , y , color , size;
    UI_string_type  label =NULL ;
    VfxWString ret;

    wgui_virtual_keyboard_get_button_label( 
        index, 
        &label,
        &x,
        &y,
        &color , 
        &size ,
        getButtonType(flag));
    if ( label != NULL)
    {  
        ret = VFX_WSTR_MEM(( VfxWChar*)(label));
    }
        return ret ;
}
    

VfxWString VcpVKLayoutAdp::getButtonLabelAux(VfxU16 index,VcpVKBtnStateEnum flag  )
{

    U32 x , y , color , size;
    UI_string_type  label =NULL ;
    VfxWString ret;

    wgui_virtual_keyboard_get_button_label_aux( 
        index, 
        &label,
        &x,
        &y,
        &color , 
        &size ,
        getButtonType(flag));
    if ( label != NULL)
    {  
        ret = VFX_WSTR_MEM(( VfxWChar*)(label));
    }
    return ret ;
}


VfxU32 VcpVKLayoutAdp::getButtonLabelColor(VfxU16 index,VcpVKBtnStateEnum flag  )
{

    U32 x , y , color , size;
    UI_string_type  label =NULL ;
    VfxWString ret;


    wgui_virtual_keyboard_get_button_label( 
        index, 
        &label,
        &x,
        &y,
        &color , 
        &size ,
        getButtonType(flag));
    return color ;

}

VfxU32 VcpVKLayoutAdp::getButtonLabelColorAux(VfxU16 index,VcpVKBtnStateEnum flag  )
{

    U32 x , y , color , size;
    UI_string_type  label =NULL ;
    VfxWString ret;


    wgui_virtual_keyboard_get_button_label_aux( 
        index, 
        &label,
        &x,
        &y,
        &color , 
        &size ,
        getButtonType(flag));
    return color ;
}


VfxU32 VcpVKLayoutAdp::getButtonLabelFontSize(VfxU16 index,VcpVKBtnStateEnum flag  )
{
    U32 x , y , color , size;
    UI_string_type  label =NULL ;
    VfxWString ret;

    wgui_virtual_keyboard_get_button_label( 
        index, 
        &label,
        &x,
        &y,
        &color , 
        &size ,
        getButtonType(flag));
    return size ;
}


VfxU32 VcpVKLayoutAdp::getButtonLabelFontSizeAux(VfxU16 index,VcpVKBtnStateEnum flag )
{
    U32 x , y , color , size;
    UI_string_type  label =NULL ;
    VfxWString ret;

    wgui_virtual_keyboard_get_button_label_aux( 
        index, 
        &label,
        &x,
        &y,
        &color , 
        &size ,
        getButtonType(flag));
    return size ;

}


VfxBool VcpVKLayoutAdp::checkButtonPopupExist(VfxU16 index)
{
   if(wgui_virtual_keyboard_is_popup_exist(index))
    return VFX_TRUE;
   else
    return VFX_FALSE;
}


VfxBool VcpVKLayoutAdp::checkAlphanumeric()
{
    if (((wgui_virtual_keyboard_get_vk_attr()) & MMI_VK_TYPE_ALPHANUMERIC) != 0)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

void VcpVKLayoutAdp:: setActiveRow(VfxU32 rowid)
{

    wgui_virtual_keyboard_set_active_row(rowid);

}



VfxBool VcpVKLayoutAdp::setup( VcpVKTypeEnum type, VcpVKAttr attr)
{
    wgui_virtual_keyboard_set_current_layout(type ,  attr); /* this should return error */
    return VFX_TRUE;
}

/* now because we dont have a mechanism im place to get mini vk using its enum ; have to use this way ; will do somethinking if we can make it by some otehr way */
VfxBool VcpVKLayoutAdp::setup( U32 index)
{
    if(wgui_virtual_keyboard_get_mini_keyboard_layout(index) == NULL)
        return VFX_FALSE;
    wgui_setup_virtual_keyboard_by_layout(wgui_virtual_keyboard_get_mini_keyboard_layout(index));  
    return VFX_TRUE;
}


VfxBool VcpVKLayoutAdp::checkLongtapPopupExist( U32 index)
{

    if(wgui_virtual_keyboard_get_mini_keyboard_layout(index) == NULL)
        return VFX_FALSE;
    return VFX_TRUE;
}

/***************************************************************************** 
* Class VcpVKHiliteFrame
*****************************************************************************/

void VcpVKHiliteFrame::bringToFront()
{
    VfxFrame::bringToFront();
}


void VcpVKHiliteFrame::setPos(const VfxPoint &value)
{
    VfxFrame::setPos(value);
}


void VcpVKHiliteFrame::setBounds(const VfxRect &value)
{
    VfxFrame::setBounds(value);
}


void VcpVKHiliteFrame::setHidden(VfxBool value)
{
    VfxFrame::setHidden(value);
}


void VcpVKHiliteFrame::setPosZ(VfxFloat value)
{
    VfxFrame::setPosZ(value);
}


void VcpVKHiliteFrame::setOpacity(VfxFloat value)
{
    VfxFrame::setOpacity(value);
}


void VcpVKHiliteFrame::onInit()
{
    VfxFrame::onInit();
    setIsUnhittable(VFX_TRUE);
    setHidden(VFX_TRUE);
}


void VcpVKHiliteFrame::onDeinit()
{
    VfxFrame::onDeinit();
}

void VcpVKPopup::onDraw(VfxDrawContext &dc)
{
    VFX_ASSERT(m_currButton != NULL);
    drawButton(dc, m_currButton,VCP_VK_BUTTON_STATE_POPUP);
}

void VcpVKPopup::drawButton(VfxDrawContext &dc, const VcpVKBtn *button , VcpVKBtnStateEnum flag  )
{
    VFX_ASSERT(m_currButton != NULL);
    VfxImageSrc bgImg;
    VfxWString label ;
    VfxU32 label_color , label_size;
    VfxRect labelRect,bgRect;

    bgImg = (VfxImageSrc)m_adaptor.getButtonBgImage(m_currButton->index,flag);
    bgRect = VfxRect(0,0,getRect().getWidth(),getRect().getHeight());

    label  = m_adaptor.getButtonLabel(m_currButton->index,flag );    

    labelRect = m_adaptor.getButtonLabelRect(m_currButton->index,flag);

    label_size =  m_adaptor.getButtonLabelFontSize(m_currButton->index,flag )  ;

    label_color =m_adaptor.getButtonLabelColor(m_currButton->index,flag );    


    if (label.getLength() != NULL)
    {
        m_renderer.renderButton( 
            dc,
            bgRect,
            bgImg,
            label,
            label_color,
            label_size,
            labelRect,
			m_adaptor.getLabelBaseline());
    }

}


void VcpVKHilite::onDraw(VfxDrawContext &dc)
{
    VFX_ASSERT(m_currButton != NULL);
    drawButton(dc, m_currButton,VCP_VK_BUTTON_STATE_HILITE);
}


void VcpVKHilite::drawButton(VfxDrawContext &dc, const VcpVKBtn *button , VcpVKBtnStateEnum flag  )
{

    VFX_ASSERT(m_currButton != NULL);
    VfxImageSrc bgImg;
    VfxWString label ;
    VfxWString label_aux ;  
    VfxU32 label_color , label_size;
    VfxU32 label_color_aux , label_size_aux;
    VfxRect labelRect,labelRectAux,bgRect;


    bgImg = (VfxImageSrc)m_adaptor.getButtonBgImage(m_currButton->index,flag);
    bgRect = VfxRect(0,0,getRect().getWidth(),getRect().getHeight());
    /* Adjusting the bg image gaps */

    bgRect = VfxRect(bgRect.getX() + m_adaptor.getMarginWidth(m_currButton->index)   ,bgRect.getY() + m_adaptor.getMarginHeight(m_currButton->index) ,bgRect.getWidth() - 2* m_adaptor.getMarginWidth(m_currButton->index)  ,bgRect.getHeight()-  2*m_adaptor.getMarginHeight(m_currButton->index) );

    label  = m_adaptor.getButtonLabel(m_currButton->index,flag );    
    label_aux = m_adaptor.getButtonLabelAux(m_currButton->index,flag );



    labelRect = m_adaptor.getButtonLabelRect(m_currButton->index,flag);
    labelRectAux = m_adaptor.getButtonLabelRectAux(m_currButton->index,flag);

    label_size =  m_adaptor.getButtonLabelFontSize(m_currButton->index,flag )  ;
    label_size_aux = m_adaptor.getButtonLabelFontSizeAux(m_currButton->index,flag );

    label_color =m_adaptor.getButtonLabelColor(m_currButton->index,flag );    
    label_color_aux =m_adaptor.getButtonLabelColorAux(m_currButton->index,flag ); 

	if(labelRect.origin.x < bgRect.origin.x)
	{
		labelRect.origin.x =  bgRect.origin.x + 1 ;
	}



    if (label .getLength() != NULL)
    {

       

        m_renderer.renderButton( 
            dc,
            bgRect,
            bgImg,
            label,
            label_color,
            label_size,
            labelRect,
            label_aux,
            label_color_aux,
            label_size_aux,
            labelRectAux,
			m_adaptor.getLabelBaseline(),
			m_adaptor.getLabelAuxBaseline());

    }

}

/***************************************************************************** 
* Class VcpVK
*****************************************************************************/
VFX_IMPLEMENT_CLASS(VCP_VK_CLASS_NAME, VcpVK, VfxControl);


VcpVK::VcpVK() :
m_type(GUI_VIRTUAL_KEYBOARD_MAX_LANG),
m_attr(0),
m_inLongtapHintState(VFX_FALSE),
m_buttonList(NULL),
m_currButton(NULL),
m_hiliteFrame(NULL),
m_popupHintFrame(NULL),
m_longtapTimer(NULL),
m_repeatTimer(NULL),
m_readyForLongtap(VFX_FALSE)
{
    m_disabledAllowedCharBtns.isDisabled = VFX_TRUE;
    m_disabledAllowedCharBtns.string.setEmpty();
    m_disabledFuncBtn[0] = GUI_VKBD_PEN_NONE;

}


VcpVK::VcpVK(VcpVKTypeEnum type, VcpVKAttr attr) :
m_type(type),
m_attr(attr),
m_inLongtapHintState(VFX_FALSE),
m_buttonList(NULL),
m_currButton(NULL),
m_hiliteFrame(NULL),
m_popupHintFrame(NULL),
m_longtapTimer(NULL),
m_repeatTimer(NULL),
m_readyForLongtap(VFX_FALSE)
{
    m_disabledAllowedCharBtns.isDisabled = VFX_TRUE;
    m_disabledAllowedCharBtns.string.setEmpty();
    m_disabledFuncBtn[0] = GUI_VKBD_PEN_NONE;
}


void VcpVK::rotate()
{
	//Need to reset All event
	if(m_inLongtapHintState)
	{
		m_popupHintFrame->setHidden(VFX_TRUE);
		m_hiliteFrame->setHidden(VFX_TRUE);
		m_inLongtapHintState = VFX_FALSE ;
	}
	else
	{
		if (m_currButton != NULL)
		{
			emitAbortSignal(m_currButton);
		}
	}
    m_adaptor.setup( m_type, m_attr);
    //checkUpdate();
    //Need to update all VK data while rotate because VK can have 
    //diff keys on landscape and portrait mode
	onUpdate();
}

void VcpVK::setType(VcpVKTypeEnum type)
{
    if (type == m_type)
    {
        return;
    }

    m_type = type;
    //checkUpdate();
	onUpdate();
}


void VcpVK::setAttr(VcpVKAttr attr)
{
    if (attr == m_attr)
    {
        return;
    }

    m_attr = attr;
    checkUpdate();
}


void VcpVK:: setActiveRow(VfxU32 rowid)
{

    m_adaptor.setActiveRow(rowid);

}

void VcpVK::setPos(const VfxPoint &value)
{
    if (getPos() != value)
    {
        // hide the popup and highlight frame to fit the animation of vk
        m_hiliteFrame->setHidden(VFX_TRUE);
        m_popupHintFrame->setHidden(VFX_TRUE);
    }

    VfxControl::setPos(value);
}


void VcpVK::setPosZ(VfxFloat value)
{
    // set the position Z of VK
    VfxControl::setPosZ(value);

    // set the position Z of the components in VK
    m_hiliteFrame->setPosZ(value - 1);
    m_popupHintFrame->setPosZ(value - 1);
}


void VcpVK::onInit()
{
    VfxControl::onInit();

    // for performance, let the vk background is locked, set the highlight frame to be child of toplevel
    VFX_OBJ_CREATE(m_hiliteFrame, VcpVKHilite, VFX_OBJ_GET_INSTANCE(VfxTopLevel));
    VFX_OBJ_CREATE(m_popupHintFrame, VcpVKPopup, VFX_OBJ_GET_INSTANCE(VfxTopLevel));

    VFX_OBJ_CREATE(m_longtapTimer, VfxTimer, this);
    VFX_OBJ_CREATE(m_repeatTimer, VfxTimer, this);

    
    m_longtapTimer->setStartDelay(VCP_VK_LONGTAP_DELAY);
    m_longtapTimer->m_signalTick.connect(this, &VcpVK::longtapTimeup);

    m_repeatTimer->setStartDelay(VCP_VK_REPEAT_DELAY);
    m_repeatTimer->m_signalTick.connect(this, &VcpVK::repeatTimeup);
    // set the position Z of the components in VK
    VfxFloat posZ = getPosZ();
    m_hiliteFrame->setPosZ(posZ - 1);
    m_popupHintFrame->setPosZ(posZ - 1);


    if (m_type != GUI_VIRTUAL_KEYBOARD_MAX_LANG)
    {
        checkUpdate();
    }

}


void VcpVK::onDeinit()
{

    // delete the linked list of buttons
    VcpVKBtn *currButton = m_buttonList;
    VcpVKBtn *nextButton;
    while (currButton != NULL)
    {
        nextButton = currButton->next;
        VFX_SYS_DELETE(currButton);
        currButton = nextButton;
    }

    // delete the highlight frame
    VFX_OBJ_CLOSE(m_hiliteFrame);

    // delete the popup hint frame
    VFX_OBJ_CLOSE(m_popupHintFrame);

    VfxControl::onDeinit();
}



VfxRect  VcpVKMain::getCurrButtonRectMain()
{

	VfxS32 x,y = 0 ;
    VfxRect rect = m_currButton->rect ;

	rect = VfxRect(rect.getX() + rect.getWidth() ,rect.getY(),rect.getWidth(),rect.getHeight());
	return    convertRectTo (rect, VFX_OBJ_GET_INSTANCE(VfxTopLevel));

}

VfxPoint  VcpVKMini::getCurrButtonRectMini(VfxU32 index)
{

	VfxS32 x,y = 0 ;
	wgui_virtual_keyboard_get_mini_keyboard_pos(index , &x, &y);
	//VfxPoint point = convertPointTo(VfxPoint(x, y), VFX_OBJ_GET_INSTANCE(VfxTopLevel)) ;
	VfxPoint point(x,y);

	return  point;

}


VfxU32  VcpVK::getCurrButtonIndex()
{
    return  m_currButton->index;

}


void VcpVK::onUpdate()
{


    // emit the abort signal when one button is active
    if (m_inLongtapHintState)
    {
        return;  // when mini keyboard is here ; main will just rest ; infact it may want to tell mini vk to carry out  abort
    }
    else
    {
        if (m_currButton != NULL)
        {
            emitAbortSignal(m_currButton);
        }
    }

    // delete the old linked list of buttons
    VcpVKBtn *currButton = m_buttonList;
    VcpVKBtn *nextButton;
    while (currButton != NULL)
    {
        nextButton = currButton->next;
        VFX_SYS_DELETE(currButton);
        currButton = nextButton;
    }
    m_buttonList = NULL;
    m_currButton = NULL;

    // build the new linked list of buttons
    VfxS32 x, y, width, height;
    VfxU16 index;
    VfxU16 count = m_adaptor.getButtonCount();
    VfxU32 content;
    VcpVKBtn *preButton = NULL;
    // build the first button in button list
    for (index = 0; index < count; index++)
    {
        // the button is not popup, and add into linked list
        VFX_SYS_NEW(currButton, VcpVKBtn);
        VFX_ASSERT(currButton != NULL);
        content = m_adaptor.getButtonContent(index);
        if (checkButtonIsAllowed(content))
        {
            currButton->isAllowed = VFX_TRUE;
        }
        else
        {
            currButton->isAllowed = VFX_FALSE;
        }
        m_adaptor.getButtonRect(index, &x, &y, &width, &height, VCP_VK_BUTTON_STATE_NORMAL);
        currButton->rect = VfxRect(x, y, width, height);
        currButton->index = index;
        currButton->next = NULL;
        m_buttonList = currButton;
        preButton = currButton;
        break;
    }

    index++;
    // build the other button in button list

    for (; index < count; index++)
    {
        // the button is not popup, and add into linked list
        VFX_SYS_NEW(currButton, VcpVKBtn);
        VFX_ASSERT(currButton != NULL);
        content = m_adaptor.getButtonContent(index);
        if (checkButtonIsAllowed(content))
        {
            currButton->isAllowed = VFX_TRUE;
        }
        else
        {
            currButton->isAllowed = VFX_FALSE;
        }
        m_adaptor.getButtonRect(index, &x, &y, &width, &height , VCP_VK_BUTTON_STATE_NORMAL);
        currButton->rect = VfxRect(x, y, width, height);
        currButton->index = index;
        currButton->next = NULL;
        preButton->next = currButton;
        preButton = currButton;
    }

    // get the size of virtual keyboard
    m_adaptor.getSize(&width, &height);
    // close the animation during  change of vk size
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setSize(width, height);
    VfxAutoAnimate::commit();


}


void VcpVK::onDraw(VfxDrawContext &dc)
{


    VfxRect bgRect(0, 0, getRect().getWidth(), getRect().getHeight());
    dc.drawResizedImageFromRes(bgRect, m_adaptor.getBgImage());
#if defined(__MMI_IME_V3__) && !defined(__NO_HANDWRITING__)

	if (m_type == GUI_VIRTUAL_KEYBOARD_TRAY)
	{

		//get handwritring rect from 
		mmi_pen_handwriting_area_struct rect ;
		mmi_imui_get_handwriting_area(&rect);
		VfxRect hwRect(rect.x1, 0, rect.x2 - rect.x1, rect.y2 - rect.y1 + 1); 

		#if defined(__COSMOS_MMI__)
		dc.drawResizedImageFromRes(hwRect , VADP_IMG_IME_CAND_HW_BG);
		#endif
	}
#endif

    for (VcpVKBtn *button = m_buttonList; button != NULL; button = button->next)
    {
        drawButton(dc, button);
    }
}



void VcpVK::drawButton(VfxDrawContext &dc, const VcpVKBtn *button)
{
    if (button->isAllowed)
    {
        drawButton(dc, button , VCP_VK_BUTTON_STATE_NORMAL  );
    }
    else
    {
        drawButton(dc, button , VCP_VK_BUTTON_STATE_DISABLED  );
    }
}


void VcpVK::drawButton(VfxDrawContext &dc, const VcpVKBtn *button , VcpVKBtnStateEnum flag   )
{
    VFX_ASSERT(button != NULL);
    VfxImageSrc bgImg;
    VfxWString label ;
    VfxWString label_aux ;
    VfxU32 label_color , label_size;
    VfxU32 label_color_aux , label_size_aux;
    VfxRect labelRect,labelRectAux,bgRect; 
    bgRect = button->rect;
    /* The data members */
    bgImg = (VfxImageSrc)m_adaptor.getButtonBgImage(button->index,flag);
    label  = m_adaptor.getButtonLabel(button->index,flag );    
    label_aux = m_adaptor.getButtonLabelAux(button->index,flag );


    labelRect =m_adaptor.getButtonLabelRect(button->index,flag);
    labelRectAux = m_adaptor.getButtonLabelRectAux(button->index,flag);
    bgRect = VfxRect(bgRect.getX() + m_adaptor.getMarginWidth(button->index)   ,bgRect.getY() + m_adaptor.getMarginHeight(button->index) ,bgRect.getWidth() - 2* m_adaptor.getMarginWidth(button->index)  ,bgRect.getHeight()-  2*m_adaptor.getMarginHeight(button->index) );


    /* adjusting as relative to current frame   */
    labelRect = VfxRect(labelRect.getX() +button->rect.getX(),labelRect.getY() +button->rect.getY(),labelRect.getWidth(),labelRect.getHeight());
	if(labelRect.origin.x < bgRect.origin.x)
	{
		labelRect.origin.x = bgRect.origin.x +1  ; 
	}
    labelRectAux = VfxRect(labelRectAux.getX() +button->rect.getX(),labelRectAux.getY() +button->rect.getY(),labelRectAux.getWidth(),labelRectAux.getHeight());

    label_size =  m_adaptor.getButtonLabelFontSize(button->index,flag )            ;
    label_size_aux = m_adaptor.getButtonLabelFontSizeAux(button->index,flag );

    label_color =m_adaptor.getButtonLabelColor(button->index,flag );    
    label_color_aux =m_adaptor.getButtonLabelColorAux(button->index,flag );  





    if (label.getLength() != NULL)
    {
		#if defined(__COSMOS_MMI__)
			if (flag == VCP_VK_BUTTON_STATE_DISABLED)
			{
				//If key is disable label color need to be disable color
				 label_color = VFX_COLOR_RES(VADP_COL_VK_DISABLE);
				 label_color_aux = VFX_COLOR_RES(VADP_COL_VK_DISABLE);  
			}
		#endif

        m_renderer.renderButton( 
            dc,
            bgRect,
            bgImg,
            label,
            label_color,
            label_size,
            labelRect,
            label_aux,
            label_color_aux,
            label_size_aux,
            labelRectAux,
			m_adaptor.getLabelBaseline(),
			m_adaptor.getLabelAuxBaseline());


    }

}


const VcpVKBtn *VcpVK::getButtonByPointStrict(const VfxPoint &point)
{
    for (VcpVKBtn *button = m_buttonList; button != NULL; button = button->next)
    {
        if (button->rect.contains(point))
        {
            if (button->isAllowed == VFX_FALSE)
            {
                return NULL;
            }
            else
            {
                return button;
            }
        }
    }

    return NULL;
}


const VcpVKBtn *VcpVK::getButtonByPoint(const VfxPoint &point)
{
    VfxU64 minDistance = 0xffffffffffffffff;
    VcpVKBtn *nearButton = NULL;

    for (VcpVKBtn *button = m_buttonList; button != NULL; button = button->next)
    {
        if (button->rect.contains(point))
        {
            if (button->isAllowed == VFX_FALSE)
            {
                return NULL;
            }
            else
            {
                return button;
            }
        }

        // find the nearist button
        if (button->isAllowed == VFX_TRUE)
        {
            VfxS32 dX = point.x - (button->rect.getX() + button->rect.getWidth() / 2);
            VfxS32 dY = point.y - (button->rect.getY() + button->rect.getHeight() / 2);
            VfxU64 distance = dX * dX + dY * dY;
            if (distance < minDistance)
            {
                minDistance = distance;
                nearButton = button;
            }
        }
    }

    return nearButton;
}


void VcpVK::repeatTimeup(VfxTimer *timerFunc)
{
    // maybe the vk is resetted [mini VK exist]
    if (m_currButton == NULL || m_readyForLongtap)
    {
        return;
    }

    if(! m_adaptor.checkLongtapPopupExist(m_currButton->index))
    {
            emitRepeatSignal(m_currButton);
            m_repeatTimer->start();
    }


}


void VcpVK::longtapTimeup(VfxTimer *timerFunc)
{
    // maybe the vk is resetted
    if (m_currButton == NULL)
    {
        return;

    }

	/*Hack for setting the popup over Smart key*/
	/*Check the key on longtap key if its smart key then Hide the Popup*/

	VfxU32 content = m_adaptor.getButtonContentpointer(m_currButton->index, MMI_PEN_EVENT_LONG_TAP);
	VfxU32 contenttype = m_adaptor.getButtonContenttype(m_currButton->index, MMI_PEN_EVENT_LONG_TAP);
	if((gui_virtual_keyboard_pen_enum)content == GUI_VKBD_PEN_V3_CHANGE_MODE_BETWEEN_SMART_AND_MULTITAP)
	{
			m_popupHintFrame->setHidden(VFX_TRUE);
			emitLongtapSignal(m_currButton);
			return ;
	}

    if(! m_adaptor.checkLongtapPopupExist(m_currButton->index))
    {
        emitLongtapSignal(m_currButton);
        return;
    }
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);

    /* hide the other stuff */
    m_hiliteFrame->setHidden(VFX_TRUE);
    m_popupHintFrame->setHidden(VFX_TRUE);
    // emit longtap signal
    // set the flag to notify that vk is ready for entering longtap state
    m_readyForLongtap = VFX_TRUE;
    m_inLongtapHintState = VFX_TRUE;
    emitLongtapTimeUpSignal(m_currButton);

 
}



void VcpVK::setHiliteButton(const VcpVKBtn *button)
{
    VFX_ASSERT(button != NULL);
    /* size is same as that on the button */
    m_hiliteFrame->setcurrbutton(button);
    m_hiliteFrame->setRect(convertRectTo(button->rect, VFX_OBJ_GET_INSTANCE(VfxTopLevel)));
    m_hiliteFrame->setOpacity(1);
}


void VcpVK::setPopupHintFrame(const VcpVKBtn *button)
{
    VFX_ASSERT(button != NULL);
    // get the size of popup hint
    VfxRect rect;
    VfxS32 x,y;
    m_adaptor.getButtonRect(button->index, &x, &y,  &(rect.size.width),  &(rect.size.height) , VCP_VK_BUTTON_STATE_POPUP);
    m_popupHintFrame->setcurrbutton(button);

    // get the size of popup hint
    rect = VfxRect(rect.getX() ,rect.getY() ,rect.getWidth()  /**( m_adaptor.getButtonPopupRatioHeight(button->index)) */,rect.getHeight() /** (m_adaptor.getButtonPopupRatioHeight(button->index) )*/);

    // get the position of popup hint
    rect.origin.x = button->rect.origin.x - ((rect.size.width - button->rect.size.width) / 2);
    if (rect.origin.x < 0)
    {
        rect.origin.x = 0;
    }
    if ((rect.origin.x + rect.size.width) > getSize().width)
    {
        rect.origin.x = getSize().width - rect.size.width;
    }
    rect.origin.y = button->rect.origin.y - VCP_VK_POPUP_GAP - rect.size.height;

    m_popupHintFrame->setRect(convertRectTo(rect, VFX_OBJ_GET_INSTANCE(VfxTopLevel)));


}

void VcpVK::emitRepeatSignal(const VcpVKBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxU32 content = m_adaptor.getButtonContent(button->index);
    VfxU32 contenttype = m_adaptor.getButtonContenttype(button->index , MMI_PEN_EVENT_REPEAT);

    m_signalButtonRepeat.postEmit(this, (VcpVKBtnTypeEnum) contenttype, content);

    }


void VcpVK::emitDownSignal(const VcpVKBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxU32 content = m_adaptor.getButtonContent(button->index, MMI_PEN_EVENT_DOWN);
    VfxU32 contenttype = m_adaptor.getButtonContenttype(button->index, MMI_PEN_EVENT_DOWN);

    m_signalButtonDown.postEmit(this, (VcpVKBtnTypeEnum) contenttype, content);

    }

void VcpVK::emitLongtapTimeUpSignal(const VcpVKBtn *button)
    {

    VFX_ASSERT(button != NULL);
    VfxU32 content = m_adaptor.getButtonContentpointer(button->index, MMI_PEN_EVENT_UP);
    VfxU32 contenttype = m_adaptor.getButtonContenttype(button->index, MMI_PEN_EVENT_UP);

    m_signalButtonLongtapTimeUp.postEmit(this, (VcpVKBtnTypeEnum) contenttype, content);//,button->index);
}


void VcpVK::emitLongtapSignal(const VcpVKBtn *button)
{

    VFX_ASSERT(button != NULL);
    VfxU32 content = m_adaptor.getButtonContentpointer(button->index, MMI_PEN_EVENT_LONG_TAP);
    VfxU32 contenttype = m_adaptor.getButtonContenttype(button->index, MMI_PEN_EVENT_LONG_TAP);

    m_signalButtonLongtap.postEmit(this, (VcpVKBtnTypeEnum) contenttype, content);//,button->index);
    }
void VcpVK::emitLongtapEventSignal(VcpVKLongtapHintEvt &event)
    {
    m_signalEventLongtap.emit(this,event);
}
//this will b different for derived
void VcpVK::emitMoveSignal(const VcpVKBtn *button)// ,VfxPenEvent& forMini)
{
    VFX_ASSERT(button != NULL);

    VfxU32 content = m_adaptor.getButtonContentpointer(button->index, MMI_PEN_EVENT_MOVE);
    VfxU32 contenttype = m_adaptor.getButtonContenttype(button->index, MMI_PEN_EVENT_MOVE);

    m_signalButtonMove.postEmit(this, (VcpVKBtnTypeEnum) contenttype, content);//,button->index);
}


void VcpVK::emitUpSignal(const VcpVKBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxU32 content = m_adaptor.getButtonContentpointer(button->index, MMI_PEN_EVENT_UP);
    VfxU32 contenttype = m_adaptor.getButtonContenttype(button->index, MMI_PEN_EVENT_UP);

    m_signalButtonUp.postEmit(this, (VcpVKBtnTypeEnum) contenttype, content);//,button->index);
}


void VcpVK::emitAbortSignal(const VcpVKBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxU32 content = m_adaptor.getButtonContentpointer(button->index, MMI_PEN_EVENT_ABORT);
    VfxU32 contenttype = m_adaptor.getButtonContenttype(button->index, MMI_PEN_EVENT_ABORT);

    m_signalButtonAbort.postEmit(this, (VcpVKBtnTypeEnum) contenttype, content);//,button->index);
}

void VcpVKMini::onInit()
{

    VcpVK::onInit();
    //   m_hiliteFrame->setHidden(VFX_FALSE);
}



void VcpVKMini::setCurrButtonIndex(VfxU32 index )
{
    m_currIndex = index ;
}

void VcpVKMini::onDraw(VfxDrawContext &dc)
{
    if(!setDataSource()) 
        return ;
    VcpVK::onDraw(dc);


}


void VcpVKMini::onUpdate()
{

    if(!setDataSource()) 
        return ;

    VcpVK::onUpdate();
    m_hiliteFrame->setcurrbutton(m_buttonList);  
    // draw highlight button as when its created ; one button will always be hilighted */
    setHiliteButton(m_buttonList);
    m_hiliteFrame->setHidden(VFX_FALSE);
    m_hiliteFrame->bringToFront();

    //get screen size
    vrt_size_struct mainScreenSize;
    vrt_color_type_enum mainScreenColorFormat;
    vrt_sys_get_main_screen_info(&mainScreenSize, &mainScreenColorFormat);

#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    //  redraw
    invalidate();


}

VfxBool VcpVKMini::checkPopupExist(const VcpVKBtn *button)
{
    return VFX_FALSE;  /* longtap has no popup */
}


VfxBool VcpVKMini::setDataSource()
{
    return m_adaptor.setup(m_currIndex) ;
}


VfxBool VcpVKMini::onPenInput(VcpVKLongtapHintEvt &event)
{
    const VcpVKBtn *button;
    switch (event.type)
    {
    case VFX_PEN_EVENT_TYPE_MOVE :
        button = getButtonByPoint(event.pos);
        if (button == NULL)
        {
            // the point is not in button
            //  m_hiliteFrame->setHidden(VFX_TRUE);
        }
        // the point is in button
        else   if (button == m_currButton)
        {
            // the button is current selected button
            if (m_hiliteFrame->getHidden())
            {
                    m_hiliteFrame->setHidden(VFX_FALSE);
                    m_hiliteFrame->bringToFront();
                }
            }
            else
            {
                // move to another button
                // highlight button
                m_currButton = button;
                setHiliteButton(button);
                m_hiliteFrame->setHidden(VFX_FALSE);
                m_hiliteFrame->invalidate();               
                // emit the signal of move
                emitMoveSignal(m_currButton);//,event);
            }

        break;

    case VFX_PEN_EVENT_TYPE_UP :
        m_hiliteFrame->setHidden(VFX_TRUE);
        button = getButtonByPoint(event.pos);
        if (button == NULL)
        {
            // the point is not in button
            // emit the signal of abort on selected button
            if (m_currButton != NULL)
            {
                emitAbortSignal(m_currButton);
                this->setHidden(VFX_TRUE);
            }
        }
        else
        {
            // the point is in button ** if any MiniVK key is highlighted then give the up event to that key 
            if (m_currButton)
            {
                // the button is current selected button
                // emit the signal of up on selected button
                emitUpSignal(m_currButton);
            }
            else
            {
                // move to another button
                // emit the signal of abort on selected button
                if (m_currButton != NULL)
                {
                    emitAbortSignal(m_currButton);
                }
            }
        }
        m_currButton = NULL;
        break;

    case VFX_PEN_EVENT_TYPE_ABORT :
        m_hiliteFrame->setHidden(VFX_TRUE);
        // emit the signal of abort on selected button
        if (m_currButton != NULL)
        {
            emitAbortSignal(m_currButton);
        }
        m_currButton = NULL;
        break;

    default:
        break;
    }
    return VFX_TRUE;
}


void VcpVKMain::onUpdate()
{
    m_hiliteFrame->setHidden(VFX_TRUE);
    m_popupHintFrame->setHidden(VFX_TRUE);

    if(!setDataSource()) 
        return ;
    VcpVK::onUpdate();
    m_hiliteFrame->setcurrbutton(m_buttonList);  

    //  redraw
    invalidate();


}


void VcpVKMain::onDraw(VfxDrawContext &dc)
{
    if(!setDataSource()) 
        ASSERT(0) ;
    VcpVK::onDraw(dc);

}

VfxBool VcpVKMain::setDataSource()
{

    m_adaptor.setup( m_type, m_attr );
    return VFX_TRUE;
}


VfxBool VcpVKMain::checkPopupExist(const VcpVKBtn *button)
{

    return m_adaptor.checkButtonPopupExist(button->index);
}


VfxBool VcpVKMain::onPenInput(VfxPenEvent &event)
{
    const VcpVKBtn *button;

    switch (event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        button = getButtonByPoint(event.getRelPos(this));

        if (button == NULL)
        {
            // do not press down in active button
            m_hiliteFrame->setHidden(VFX_TRUE);
            m_popupHintFrame->setHidden(VFX_TRUE);
            m_currButton = NULL;
        }
        else
        {
            /*if(mmi_imm_is_sound_feedback_enabled() || mmi_imm_is_vibration_enabled())
            {
            vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
            }*/
			//New handling

            if(mmi_imm_is_sound_feedback_enabled_for_ime())
            {
                vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN_TONE);
            }
            if(mmi_imm_is_vibration_enabled())
            {
                vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN_VIBRATE);
            }
            // down in active button
            // save the selected button
            m_currButton = button;
            m_hiliteFrame->setcurrbutton(button);
            // start timer for longtap
            m_longtapTimer->start();
            // draw highlight state
            setHiliteButton(button);
            m_hiliteFrame->setHidden(VFX_FALSE);
            m_hiliteFrame->bringToFront();
            /* to initiate drawing of button */
            m_hiliteFrame->invalidate();
            m_popupHintFrame->invalidate();
            // draw popup hint
            if (checkPopupExist(button))
            {
                setPopupHintFrame(button);
                m_popupHintFrame->setcurrbutton(button);
                m_popupHintFrame->setHidden(VFX_FALSE);
                m_popupHintFrame->bringToFront();
            }
            // emit down signal
            emitDownSignal(button);
        }
        break;

    case VFX_PEN_EVENT_TYPE_LONG_TAP:
            m_repeatTimer->start();
        break;

    case VFX_PEN_EVENT_TYPE_MOVE:
        if (m_inLongtapHintState)
        {
            //lets instead emit the signal
            m_eventformini.pos = event.pos;
            m_eventformini.type = event.type;
            emitLongtapEventSignal(m_eventformini);

        }
        else if (m_readyForLongtap)
        {
            button = getButtonByPointStrict(event.getRelPos(this));
            if ((button == NULL) || (button != m_currButton))
            {
                // enter longtap state
                m_inLongtapHintState = VFX_TRUE;
                m_readyForLongtap = VFX_FALSE;
            }
        }
        else
        {
            // in normal situation
            if (m_currButton == NULL)
            {
                // ignore
            }
            else
            {
                button = getButtonByPoint(event.getRelPos(this));
                if (button == NULL)
                {
                    // move into inactive area
                    if (m_adaptor.checkAlphanumeric() == VFX_TRUE)
                    {
                        // alphanumeric vk
                        m_longtapTimer->stop();
                        m_repeatTimer->stop();
                    }
                    else
                    {
                        m_hiliteFrame->setHidden(VFX_TRUE);
                        m_popupHintFrame->setHidden(VFX_TRUE);
                        m_longtapTimer->stop();
                        m_repeatTimer->stop();

                    }
                }
                else if (button == m_currButton)
                {

                }
                else
                {
                    // move into another button
                    if (m_adaptor.checkAlphanumeric() == VFX_TRUE)
                    {
                        // alphanumeric vk
                        m_longtapTimer->stop();
                        m_repeatTimer->stop();

                    }
                    else
                    {
                        // save the selected button
                        m_currButton = button;
                        // stop timer for longtap
                        m_longtapTimer->stop();
                        m_repeatTimer->stop();
                        // redraw highlight state of button
                        setHiliteButton(button);
                        m_hiliteFrame->setHidden(VFX_FALSE);
                        m_hiliteFrame->bringToFront();
                        m_hiliteFrame->invalidate();
                        // redraw the popup hint
                        if (checkPopupExist(button))
                        {
                            setPopupHintFrame(button);
                            m_popupHintFrame->setHidden(VFX_FALSE);
                            m_popupHintFrame->bringToFront();
                            m_popupHintFrame->invalidate();
                        }
                        else
                        {
                            m_popupHintFrame->setHidden(VFX_TRUE);
                        }
                        //need longtap ,
                         m_longtapTimer->start();
                        // emit move signal
                        emitMoveSignal(button);
                    }
                }
            }
        }
        break;

    case VFX_PEN_EVENT_TYPE_UP:
        if (m_inLongtapHintState)
        {
            // in longtap state, should transfer event to longtap hint
            //lets instead emit the signal
            m_eventformini.pos = event.pos;
            m_eventformini.type = event.type;
            emitLongtapEventSignal(m_eventformini);
            setDataSource();
            m_inLongtapHintState = VFX_FALSE;
            m_readyForLongtap = VFX_FALSE ;

            // back to initial state
            m_hiliteFrame->setHidden(VFX_TRUE);
            m_popupHintFrame->setHidden(VFX_TRUE);
            m_currButton = NULL;

        }
        else
        {
            if (m_currButton == NULL)
            {
                // ignore
            }
            else
            {
                if (m_readyForLongtap)
                {
                    m_inLongtapHintState = VFX_FALSE;
                    m_readyForLongtap = VFX_FALSE;
                }
                m_popupHintFrame->setHidden(VFX_TRUE);
                m_hiliteFrame->setHidden(VFX_TRUE);
                m_longtapTimer->stop();
                if (m_adaptor.checkAlphanumeric() == VFX_TRUE)
                {
                    emitUpSignal(m_currButton);
                }
                else
                {   
                    button = getButtonByPoint(event.getRelPos(this));
                    if (button == NULL)
                    {
                        // up in inactive area
                        emitAbortSignal(m_currButton);
                    }
                    else if (button == m_currButton)
                    {
                        // up in same button
                        emitUpSignal(m_currButton);
                    }
                    else
                    {
                        // up in another button
                        emitUpSignal(m_currButton);
                    }
                }

                m_currButton = NULL;
            }
        }
        break;

    case VFX_PEN_EVENT_TYPE_ABORT:
        if (m_inLongtapHintState)
        {
            // in longtap state, should transfer event to longtap hint
            //lets instead emit the signal
            m_eventformini.pos = event.pos;
            m_eventformini.type = event.type;
            emitLongtapEventSignal(m_eventformini);
            setDataSource();
            // back to initial state
            m_hiliteFrame->setHidden(VFX_TRUE);
            m_popupHintFrame->setHidden(VFX_TRUE);
            m_currButton = NULL;
        }
        else
        {
            if (m_currButton == NULL)
            {
                // ignore
            }
            else
            {
                if (m_readyForLongtap)
                {
                    m_inLongtapHintState = VFX_FALSE;
                    m_readyForLongtap = VFX_FALSE;
                }
                m_hiliteFrame->setHidden(VFX_TRUE);
                m_popupHintFrame->setHidden(VFX_TRUE);
                m_longtapTimer->stop();
                emitAbortSignal(m_currButton);
                m_currButton = NULL;
            }
        }
        break;

    default:
        break;
    }
    return VFX_TRUE;
}



void   VcpVkRenderer::renderButton( 
                                   VfxDrawContext &dc,
                                   VfxRect rect,
                                   VfxImageSrc bgImage,
                                   const VfxWString  label,
                                   VfxU32 fontcolor,
                                   VfxU32 fontsize,
                                   VfxRect fontloc,
                                   const VfxWString labelAux,
                                   VfxU32 fontcolorAux,
                                   VfxU32 fontsizeAux,
                                   VfxRect fontlocAux,
								   VfxS32 labelBaseLine,
								   VfxS32 labelAuxBaseLine)
{
    dc.drawResizedImage(rect, (VfxImageSrc)bgImage);
    //if(m_fontsize != fontsize)
    {
		dc.setFont   (VfxFontDesc(VFX_FONT_DESC_VF_SIZE(fontsize)));
        m_fontsize = fontsize;
    }
    //if(m_fontcolor != fontcolor)
    {
		dc.setFillColor(VfxColor(fontcolor));
        m_fontcolor = fontcolor;
    }
	
#if defined(__MMI_BIDI_ALG__)
	U8 dic = 0;
	U16 unicode = 0;
	U8* String = (U8*)label.getBuf();
	S32 char_width =0;
	unicode = String[0];
	unicode |= (String[1] << 8);
	bidi_get_char_type((U8*) (&unicode), &dic);
	if (r2lMMIFlag /*dic == BIDI_R || dic == AL || dic == AN */)
	{
		//Get_CharWidth(unicode,&char_width);
		char_width = gui_get_string_width((UI_character_type*)label.getBuf());
		fontloc.origin.x = fontloc.origin.x + char_width ;
		dc.drawTextBaseline(fontloc ,labelBaseLine, label, label.getLength());
		//dc.drawText(fontloc.getX(),fontloc.getY(),label);
	}	
	else
	{
		dc.drawTextBaseline(fontloc ,labelBaseLine, label, label.getLength());
		//dc.drawText(fontloc.getX(),fontloc.getY(),label);
	}
#else
	dc.drawTextBaseline(fontloc ,labelBaseLine, label, label.getLength());
	//dc.drawText(fontloc.getX(),fontloc.getY(),label);
#endif
	
    //if(m_fontsizeAux != fontcolorAux)
    {
		dc.setFont   (VfxFontDesc(VFX_FONT_DESC_VF_SIZE(fontsizeAux)));
        m_fontsizeAux = fontsizeAux;
    }
	// if(m_fontcolorAux != fontcolorAux)
    {
		dc.setFillColor(VfxColor(fontcolorAux));
        m_fontcolor = fontcolor;
    }
	
	if(labelAux.getLength() != NULL)
	{
#if defined(__MMI_BIDI_ALG__)
		
		U8 dic = 0;
		U16 unicode = 0;
		U8* String = (U8*)labelAux.getBuf();
		S32 char_width =0;
		unicode = String[0];
		unicode |= (String[1] << 8);
		bidi_get_char_type((U8*) (&unicode), &dic);
		if (r2lMMIFlag /*dic == BIDI_R || dic == AL || dic == AN */)
		{
			//Get_CharWidth(unicode,&char_width);
			char_width = gui_get_string_width((UI_character_type*)labelAux.getBuf());
			fontlocAux.origin.x = fontlocAux.origin.x + char_width ;
			dc.drawTextBaseline(fontlocAux ,labelAuxBaseLine, labelAux, labelAux.getLength());
			//dc.drawText(fontlocAux.getX(),fontlocAux.getY(),labelAux);
		}
		else
		{
			dc.drawTextBaseline(fontlocAux ,labelAuxBaseLine, labelAux, labelAux.getLength());
			//dc.drawText(fontlocAux.getX(),fontlocAux.getY(),labelAux);
			
		}
		
#else
		dc.drawTextBaseline(fontlocAux ,labelAuxBaseLine, labelAux, labelAux.getLength());
		//dc.drawText(fontlocAux.getX(),fontlocAux.getY(),labelAux);
#endif
	}
}




void   VcpVkRenderer::renderButton( 
                                   VfxDrawContext &dc,
                                   VfxRect rect,
                                   VfxImageSrc bgImage,
                                   const VfxWString  label,
                                   VfxU32 fontcolor,
                                   VfxU32 fontsize,
                                   VfxRect fontloc,
								   VfxS32 labelBaseLine)
{
    dc.drawResizedImage(rect, (VfxImageSrc) bgImage);
    //if(m_fontsize != fontsize)
    {
		dc.setFont   (VfxFontDesc(VFX_FONT_DESC_VF_SIZE(fontsize)));
        m_fontsize = fontsize;
    }
    //if(m_fontcolor != fontcolor)
    {
		dc.setFillColor(VfxColor(fontcolor));
        m_fontcolor = fontcolor;
    }
#if defined(__MMI_BIDI_ALG__)
	U8 dic = 0;
	U16 unicode = 0;
	U8* String = (U8*)label.getBuf();
	S32 char_width =0;
	
	unicode = String[0];
	unicode |= (String[1] << 8);
	
	bidi_get_char_type((U8*) (&unicode), &dic);
	
	if (r2lMMIFlag /*dic == BIDI_R || dic == AL || dic == AN */)
	{
		//Get_CharWidth(unicode,&char_width);
		char_width = gui_get_string_width((UI_character_type*)label.getBuf());
		fontloc.origin.x = fontloc.origin.x + char_width ;
		dc.drawTextBaseline(fontloc ,labelBaseLine, label, label.getLength());
		//dc.drawText(fontloc.getX(),fontloc.getY(),label);
	}
	else
	{
		dc.drawTextBaseline(fontloc ,labelBaseLine, label, label.getLength());
		//dc.drawText(fontloc.getX(),fontloc.getY(),label);
	}
#else
	dc.drawTextBaseline(fontloc ,labelBaseLine, label, label.getLength());
	//mmi_fe_show_string_ext_for_vk(fontlocAux.getX(),fontlocAux.getY(),(U8*)label.getBuf());
#endif
}

#elif defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__

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
*  vcp_vk.cpp
*
* Project:
* --------
*  Venus MMI
*
* Description:
* ------------
*  Virtual keyboard class
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/

extern "C"
{
#include "mmi_rp_srv_virtual_keyboard_misc_def.h"
#include "gui_virtual_keyboard_language_type.h"
#include "GlobalResDef.h"
#include "ImmProt.h"
#include "ImeGprot.h"
}

//#include "vcp_vk.h"
#include "vfx_auto_animate.h"
#include "vfx_adp_device.h"

extern "C"
{
    extern VcpVKLayoutStruct *wgui_virtual_keyboard_layout_list[];
}

#if defined(__MMI_INDIC_ALG__)
extern "C"
{
#include  "IndicEngineGprot.h"
}
#endif


/***************************************************************************** 
* Defination
*****************************************************************************/
// the max value of content of character button
#define VCP_VK_CONTENT_CHARACTER_MAX            ((VfxU32)(0xFFFF))

// the mix size of button of popup hint
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define VCP_VK_POPUP_BUTTON_MIN_WIDTH           57
#elif defined(__MMI_MAINLCD_320X480__)
#define VCP_VK_POPUP_BUTTON_MIN_WIDTH           66
#elif defined(__MMI_MAINLCD_480X800__)
#define VCP_VK_POPUP_BUTTON_MIN_WIDTH           88
#else
#error "non supported lcd resolution"
#endif

// the offset between button and longtap hint bound
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define VCP_VK_LONGTAP_BUTTON_X_OFFSET          10
#define VCP_VK_LONGTAP_BUTTON_Y_OFFSET          10
#elif defined(__MMI_MAINLCD_320X480__)
#define VCP_VK_LONGTAP_BUTTON_X_OFFSET          24
#define VCP_VK_LONGTAP_BUTTON_Y_OFFSET          11
#else
#define VCP_VK_LONGTAP_BUTTON_X_OFFSET          15
#define VCP_VK_LONGTAP_BUTTON_Y_OFFSET          11
#endif

// the gap between buttons of longtap hint
#define VCP_VK_LONGTAP_BUTTON_X_GAP             3
#define VCP_VK_LONGTAP_BUTTON_Y_GAP             3

// the delay of longtap signal
#define VCP_VK_LONGTAP_DELAY                    600

// the gap between popup hint and button
#define VCP_VK_POPUP_GAP                        11

// the gap between longtap hint and button
#define VCP_VK_LONGTAP_GAP                      11

// the enlarged height and width of button in longtap hint
#define VCP_VK_LONGTAP_BUTTON_MORE_WIDTH        2
#define VCP_VK_LONGTAP_BUTTON_MORE_HEIGHT       2

// the delay of the popup to hide
#define VCP_VK_POPUP_HIDE_DELAY                 100


/***************************************************************************** 
* Class VcpVKLayoutAdp
*****************************************************************************/
VfxResId VcpVKLayoutAdp::getLongtapBgImg()
{
    if (m_currVkLayout == NULL)
    {
        return (VfxResId)IMG_GLOBAL_DEFAULT;
    }
    else
    {
        return (VfxResId)IMG_ID_VKBD_CUSTOM_LONGTAP_POPUP_BG;
    }
}


VfxResId VcpVKLayoutAdp::getBgImage()
{
    if (m_currVkLayout == NULL)
    {
        return (VfxResId)IMG_GLOBAL_DEFAULT;
    }
    else
    {
        return (VfxResId)(m_currVkLayout->bg_id);
    }
}


VfxBool VcpVKLayoutAdp::checkAlphanumeric()
{
    if (m_currVkLayout == NULL)
    {
        return VFX_FALSE;
    }

    if ((m_currVkLayout->vk_attr & MMI_VK_TYPE_ALPHANUMERIC) != 0)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxBool VcpVKLayoutAdp::setup(VfxS32 width, VfxS32 height, VcpVKTypeEnum type, VcpVKAttr attr)
{
    VcpVKLayoutStruct *curr;

    m_currVkLayout = NULL;

    // get the resolution
    vrt_size_struct mainScreenSize;
    vrt_color_type_enum noUse;
    vrt_sys_get_main_screen_info(&mainScreenSize, &noUse);

    // find the layout
    for (VfxS32 i = 0; ::wgui_virtual_keyboard_layout_list[i]->lang != GUI_VIRTUAL_KEYBOARD_MAX_LANG; i++)
    {
        curr = ::wgui_virtual_keyboard_layout_list[i];

        if ((curr->resolution_width == mainScreenSize.width) &&
            (curr->resolution_height == mainScreenSize.height) &&
            (curr->lang == type) &&
            ((curr->vk_attr & attr) == attr))
        {
            g_wgui_virtual_keyboard_lang_type = type;
            m_currVkLayout = ::wgui_virtual_keyboard_layout_list[i];
            break;
        }
    }
    if (m_currVkLayout != NULL)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxU16 VcpVKLayoutAdp::getButtonCount()
{
    if (m_currVkLayout == NULL)
    {
        return (VfxU16)0;
    }
    else
    {
        return (VfxU16)(m_currVkLayout->count);
    }
}


VfxBool VcpVKLayoutAdp::checkButtonIsNormal(VfxU16 index)
{
    if (m_currVkLayout == NULL)
    {
        return VFX_TRUE;
    }

    if (m_currVkLayout->key_list[index].y < 0)
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}


VfxU32 VcpVKLayoutAdp::getButtonContent(VfxU16 index)
{
    if (m_currVkLayout == NULL)
    {
        return (VfxU32)0;
    }
    else
    {
        return (VfxU32)(m_currVkLayout->key_list[index].content);
    }
}


void VcpVKLayoutAdp::getButtonRect(VfxU16 index, VfxS32 *x, VfxS32 *y, VfxS32 *width, VfxS32 *height)
{
    if (m_currVkLayout == NULL)
    {
        (*x) = (*y) = (*width) = (*height) = 0;
    }
    else
    {
        *x = (VfxS32)(m_currVkLayout->key_list[index].x);
        *y = (VfxS32)(m_currVkLayout->key_list[index].y);
        *width = (VfxS32)(m_currVkLayout->key_list[index].width);
        *height = (VfxS32)(m_currVkLayout->key_list[index].height);
    }
}


void VcpVKLayoutAdp::getSize(VfxS32 *width,VfxS32 *height)
{
    if (m_currVkLayout == NULL)
    {
        (*width) = (*height) = 0;
    }
    else
    {
        *width = (VfxS32)(m_currVkLayout->width);
        *height = (VfxS32)(m_currVkLayout->height);
    }
}


VfxResId VcpVKLayoutAdp::getButtonNormalBgImg(VfxU16 index)
{
    if (m_currVkLayout == NULL)
    {
        return (VfxResId)IMG_GLOBAL_DEFAULT;
    }
    else
    {
        return (VfxResId)(m_currVkLayout->key_list[index].bg_id);
    }
}


VfxResId VcpVKLayoutAdp::getButtonNormalFgImg(VfxU16 index)
{
    if (m_currVkLayout == NULL)
    {
        return (VfxResId)IMG_GLOBAL_DEFAULT;
    }
    else
    {
        return (VfxResId)(m_currVkLayout->key_list[index].content_id);
    }
}


VfxResId VcpVKLayoutAdp::getButtonHiliteBgImg(VfxU16 index)
{
    if (m_currVkLayout == NULL)
    {
        return (VfxResId)IMG_GLOBAL_DEFAULT;
    }
    else
    {
        return (VfxResId)(m_currVkLayout->key_list[index].highlight_id);
    }
}


VfxResId VcpVKLayoutAdp::getButtonHiliteFgImg(VfxU16 index)
{
    if (m_currVkLayout == NULL)
    {
        return (VfxResId)IMG_GLOBAL_DEFAULT;
    }
    else
    {
        return (VfxResId)(m_currVkLayout->key_list[index].content_highlight_id);
    }
}


VfxResId VcpVKLayoutAdp::getButtonDisabledBgImg(VfxU16 index)
{
    if (m_currVkLayout == NULL)
    {
        return (VfxResId)IMG_GLOBAL_DEFAULT;
    }
    else
    {
        return (VfxResId)(m_currVkLayout->key_list[index].disable_id);
    }
}


VfxResId VcpVKLayoutAdp::getButtonDisabledFgImg(VfxU16 index)
{
    if (m_currVkLayout == NULL)
    {
        return (VfxResId)IMG_GLOBAL_DEFAULT;
    }
    else
    {
        return (VfxResId)(m_currVkLayout->key_list[index].content_disable_id);
    }
}


VfxResId VcpVKLayoutAdp::getButtonPopupBgImg(VfxU16 index)
{
    if (m_currVkLayout == NULL)
    {
        return (VfxResId)IMG_GLOBAL_DEFAULT;
    }

    if ((m_currVkLayout->vk_attr & MMI_VK_TYPE_ALPHANUMERIC) != 0)
    {
        /* the alphanumeric virtual keyboard do not has popup hint */
        VFX_ASSERT(0);
        return (VfxResId)IMG_ID_VKBD_CUSTOM_LARGE_ICON;
    }
    else
    {
        return (VfxResId)IMG_ID_VKBD_CUSTOM_LARGE_ICON;
    }
}


VfxResId VcpVKLayoutAdp::getButtonPopupFgImg(VfxU16 index)
{
    if (m_currVkLayout == NULL)
    {
        return (VfxResId)IMG_GLOBAL_DEFAULT;
    }

    if ((m_currVkLayout->vk_attr & MMI_VK_TYPE_ALPHANUMERIC) != 0)
    {
        /* the alphanumeric virtual keyboard do not has popup hint */
        VFX_ASSERT(0);
        return (VfxResId)IMG_ID_VKBD_CUSTOM_LARGE_ICON;
    }
    else
    {
        VfxS16 popup_index = m_currVkLayout->key_list[index].popup_index;
        VFX_ASSERT(popup_index >= 0);
        return (VfxResId)(m_currVkLayout->key_list[popup_index].content_highlight_id);
    }
}


VfxU16 VcpVKLayoutAdp::getButtonLongtapBtnNum(VfxU16 index)
{
    VfxS16 temp_index;
    if (m_currVkLayout == NULL)
    {
        return (VfxU16)0;
    }

    if ((m_currVkLayout->vk_attr & MMI_VK_TYPE_ALPHANUMERIC) != 0)
    {
        /* the longtap hint button of alphanumeric virtual keyboard begin with the first button indexed */
        temp_index = m_currVkLayout->key_list[index].popup_index;
        if (temp_index < 0)
        {
            return (VfxU16)0;
        }
    }
    else
    {
        /* the longtap hint button of qwerty virtual keyboard begin with the second button indexed */
        temp_index = m_currVkLayout->key_list[index].popup_index;
        if ((temp_index = m_currVkLayout->key_list[temp_index].popup_index) < 0)
        {
            return (VfxU16)0;
        }
    }

    VfxU16 count = 0;
    while (temp_index >= 0)
    {
        count++;
        temp_index = m_currVkLayout->key_list[temp_index].popup_index;
    }

    return count;
}


VfxU32 VcpVKLayoutAdp::getButtonLongtapContent(VfxU16 button_index, VfxU16 index)
{
    VfxS32 temp_index;
    if (m_currVkLayout == NULL)
    {
        return (VfxU32)0;
    }

    if ((m_currVkLayout->vk_attr & MMI_VK_TYPE_ALPHANUMERIC) != 0)
    {
        /* the longtap hint button of alphanumeric virtual keyboard begin with the first button indexed */
        temp_index = button_index;
    }
    else
    {
        /* the longtap hint button of qwerty virtual keyboard begin with the second button indexed */
        temp_index = m_currVkLayout->key_list[button_index].popup_index;
    }

    VfxU16 count = 0;
    do
    {
        temp_index = m_currVkLayout->key_list[temp_index].popup_index;
        VFX_ASSERT(temp_index >= 0);
        count++;
    } while (count <= index);

    return (VfxU32)(m_currVkLayout->key_list[temp_index].content); 
}


void VcpVKLayoutAdp::getButtonLongtapImg(
    VfxU16 button_index,
    VfxU16 index,
    VfxResId *fgId,
    VfxResId *bgId,
    VfxResId *fgHighlightId,
    VfxResId *bgHighlightId
    )
{
    VfxS32 temp_index;
    if (m_currVkLayout == NULL)
    {
        (*fgId) = (*bgId) = (*fgHighlightId) = (*bgHighlightId) = IMG_GLOBAL_DEFAULT;
    }
    else
    {
        if ((m_currVkLayout->vk_attr & MMI_VK_TYPE_ALPHANUMERIC) != 0)
        {
            /* the longtap hint button of alphanumeric virtual keyboard begin with the first button indexed */
            temp_index = button_index;
        }
        else
        {
            /* the longtap hint button of qwerty virtual keyboard begin with the second button indexed */
            temp_index = m_currVkLayout->key_list[button_index].popup_index;
        }

        VfxU16 count = 0;
        do
        {
            temp_index = m_currVkLayout->key_list[temp_index].popup_index;
            VFX_ASSERT(temp_index >= 0);
            count++;
        } while (count <= index);

        *fgId = (VfxResId)(m_currVkLayout->key_list[temp_index].content_id);
        *bgId = (VfxResId)(m_currVkLayout->key_list[temp_index].bg_id);
        *fgHighlightId = (VfxResId)(m_currVkLayout->key_list[temp_index].content_highlight_id);
        *bgHighlightId = (VfxResId)(m_currVkLayout->key_list[temp_index].highlight_id);
    }
}


void VcpVKLayoutAdp::getButtonLongtapSize(VfxU16 button_index, VfxU16 index, VfxU16 *width, VfxU16 *height)
{
    VfxS32 temp_index;
    if (m_currVkLayout == NULL)
    {
        (*width) = (*height) = 0;
    }
    else
    {
        if ((m_currVkLayout->vk_attr & MMI_VK_TYPE_ALPHANUMERIC) != 0)
        {
            /* the longtap hint button of alphanumeric virtual keyboard begin with the first button indexed */
            temp_index = button_index;
        }
        else
        {
            /* the longtap hint button of qwerty virtual keyboard begin with the second button indexed */
            temp_index = m_currVkLayout->key_list[button_index].popup_index;
        }

        VfxU16 count = 0;
        do
        {
            temp_index = m_currVkLayout->key_list[temp_index].popup_index;
            VFX_ASSERT(temp_index >= 0);
            count++;
        } while (count <= index);

        *width = (VfxU16)(m_currVkLayout->key_list[temp_index].width);
        *height = (VfxU16)(m_currVkLayout->key_list[temp_index].height);
    }
}


void VcpVKLayoutAdp::getButtonPopupSize(VfxU16 index, VfxS32 *width, VfxS32 *height)
{
    if (m_currVkLayout == NULL)
    {
        (*width) = (*height) = 0;
    }
    else
    {
        if ((m_currVkLayout->vk_attr & MMI_VK_TYPE_ALPHANUMERIC) != 0)
        {
            /* the alphanumeric virtual keyboard do not has popup hint */
            VFX_ASSERT(0);
        }
        else
        {
            VfxS16 popup_index = m_currVkLayout->key_list[index].popup_index;
            VFX_ASSERT(popup_index >= 0);
            *width = (VfxS32)(m_currVkLayout->key_list[popup_index].width);
            *height = (VfxS32)(m_currVkLayout->key_list[popup_index].height);
        }
    }
}


VfxBool VcpVKLayoutAdp::checkButtonPopupExist(VfxU16 index)
{
    if (m_currVkLayout == NULL)
    {
        return VFX_FALSE;
    }
    else
    {
        if ((m_currVkLayout->vk_attr & MMI_VK_TYPE_ALPHANUMERIC) != 0)
        {
            /* the alphanumeric virtual keyboard do not has popup hint */
            return VFX_FALSE;
        }
        else
        {
            if (m_currVkLayout->key_list[index].popup_index >= 0)
            {
                return VFX_TRUE;
            }
            else
            {
                return VFX_FALSE;
            }
        }
    }
}


VfxBool VcpVKLayoutAdp::checkButtonLongtapExist(VfxU16 index)
{
    if (m_currVkLayout == NULL)
    {
        return VFX_FALSE;
    }
    else
    {
        if ((m_currVkLayout->vk_attr & MMI_VK_TYPE_ALPHANUMERIC) != 0)
        {
            /* the longtap hint button of alphanumeric virtual keyboard begin with the first button indexed */
            if (m_currVkLayout->key_list[index].popup_index >= 0)
            {
                return VFX_TRUE;
            }
            else
            {
                return VFX_FALSE;
            }
        }
        else
        {
            /* the longtap hint button of qwerty virtual keyboard begin with the second button indexed */
            VfxS16 popup_index = m_currVkLayout->key_list[index].popup_index;
            if (popup_index < 0)
            {
                return VFX_FALSE;
            }

            if (m_currVkLayout->key_list[popup_index].popup_index >= 0)
            {
                return VFX_TRUE;
            }
            else
            {
                return VFX_FALSE;
            }
        }
    }
}


void VcpVKLayoutAdp::getButtonMultiPopupImg(
    VfxU16 button_index,
    VfxU16 index,
    VfxResId *fgId,
    VfxResId *bgId)
{
    if (m_currVkLayout == NULL)
    {
        (*fgId) = (*bgId) = IMG_GLOBAL_DEFAULT;
    }
    else
    {
        VfxS32 temp_index;
        temp_index = button_index;

        VfxU16 count = 0;
        do
        {
            temp_index = m_currVkLayout->key_list[temp_index].popup_index;
            VFX_ASSERT(temp_index >= 0);
            count++;
        } while (count <= index);

        *fgId = (VfxResId)(m_currVkLayout->key_list[temp_index].content_highlight_id);
        *bgId = (VfxResId)(m_currVkLayout->key_list[temp_index].highlight_id);
    }
}


/***************************************************************************** 
* Class VcpVKHiliteFrame
*****************************************************************************/
void VcpVKHiliteFrame::setBackgroundImg(const VfxImageSrc &image)
{
    if (image.isNull() || image.isEmpty())
    {
        setImgContent(VfxImageSrc((VfxResId)IMG_GLOBAL_DEFAULT));
    }
    else
    {
        setImgContent(image);
    }
}


void VcpVKHiliteFrame::setForegroundImg(const VfxImageSrc &image)
{
    if (image.isNull() || image.isEmpty())
    {
        setImgContent(VfxImageSrc((VfxResId)IMG_GLOBAL_DEFAULT));
    }
    else
    {
        m_fgFrame->setImgContent(image);
    }
}


void VcpVKHiliteFrame::bringToFront()
{
    // first, bring the background to front
    VfxFrame::bringToFront();

    // then, bring the foreground to front
    m_fgFrame->bringToFront();
}


void VcpVKHiliteFrame::setPos(const VfxPoint &value)
{
    // set the background position
    VfxFrame::setPos(value);

    // set the foreground position
    m_fgFrame->setPos(
        getPos().x + getSize().width / 2, 
        getPos().y + getSize().height / 2);
}


void VcpVKHiliteFrame::setBounds(const VfxRect &value)
{
    // set the background bounds
    VfxFrame::setBounds(value);

    // set the foreground bounds
    m_fgFrame->setBounds(value);

    // set the foreground position
    m_fgFrame->setPos(
        getPos().x + getSize().width / 2, 
        getPos().y + getSize().height / 2);
}


void VcpVKHiliteFrame::setHidden(VfxBool value)
{
    // set the background hidden
    VfxFrame::setHidden(value);

    // set the foreground hidden
    m_fgFrame->setHidden(value);
}


void VcpVKHiliteFrame::setPosZ(VfxFloat value)
{
    // set the position Z of highlight frame
    VfxFrame::setPosZ(value);

    // set the position Z of the components in highlight frame
    m_fgFrame->setPosZ(value - 1);
}


void VcpVKHiliteFrame::setOpacity(VfxFloat value)
{
    // set the opacity of highlight frame
    VfxFrame::setOpacity(value);

    // set the opacity of the components in highlight frame
    m_fgFrame->setOpacity(value);
}


void VcpVKHiliteFrame::onInit()
{
    VfxFrame::onInit();

    // for performance, let the background is locked, put the foreground is the child of the parent of this class
    VFX_OBJ_CREATE(m_fgFrame, VfxImageFrame, getParentFrame());
    m_fgFrame->setIsUnhittable(VFX_TRUE);
    m_fgFrame->setAnchor(0.5, 0.5);

    m_fgFrameWeakPtr = m_fgFrame;

    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    setIsUnhittable(VFX_TRUE);
    setHidden(VFX_TRUE);
}


void VcpVKHiliteFrame::onDeinit()
{
    if (m_fgFrameWeakPtr != NULL)
    {
        VFX_OBJ_CLOSE(m_fgFrame); // Maybe the parent of m_fgFrame is not toplevel, so it's this's the brother and closed just before
    }

    VfxFrame::onDeinit();
}


/***************************************************************************** 
* Class VcpVKLongtapHint
*****************************************************************************/
VcpVKLongtapHint::VcpVKLongtapHint(const VcpVKLongtapInfo *info , VfxObject *parent) :
m_info(info),
m_hiliteFrame(NULL),
m_buttonList(NULL),
m_currButton(NULL)
{
 m_parent  = parent ;
}


VfxBool VcpVKLongtapHint::processPenEvent(const VcpVKLongtapHintEvt &event)
{
    const VcpVKLongTapBtn *button;
    switch (event.type)
    {
    case VFX_PEN_EVENT_TYPE_MOVE :
        button = getButtonByPoint(event.pos);
        if (button == NULL)
        {
            // the point is not in button
            m_hiliteFrame->setHidden(VFX_TRUE);
        }
        else
        {
            // the point is in button
            if (button == m_currButton)
            {
                // the button is current selected button
                if (m_hiliteFrame->getHidden())
                {
                    m_hiliteFrame->setHidden(VFX_FALSE);
                    m_hiliteFrame->bringToFront();
                }
            }
            else
            {
                // move to another button
                // highlight button
                setHiliteButton(button);
                m_hiliteFrame->setHidden(VFX_FALSE);
                m_hiliteFrame->bringToFront();
                // save the selected button
                m_currButton = button;
                // emit the signal of move
                emitMoveSignal(m_currButton);
            }
        }
        break;

    case VFX_PEN_EVENT_TYPE_UP :
        m_hiliteFrame->setHidden(VFX_TRUE);
        button = getButtonByPoint(event.pos);
        if (button == NULL)
        {
            // the point is not in button
            // emit the signal of abort on selected button
            if (m_currButton != NULL)
            {
                emitAbortSignal(m_currButton);
            }
        }
        else
        {
            // the point is in button
            if (button == m_currButton)
            {
                // the button is current selected button
                // emit the signal of up on selected button
                emitUpSignal(m_currButton);
            }
            else
            {
                // move to another button
                // emit the signal of abort on selected button
                if (m_currButton != NULL)
                {
                    emitAbortSignal(m_currButton);
                }
            }
        }
        m_currButton = NULL;
        break;

    case VFX_PEN_EVENT_TYPE_ABORT :
        m_hiliteFrame->setHidden(VFX_TRUE);
        // emit the signal of abort on selected button
        if (m_currButton != NULL)
        {
            emitAbortSignal(m_currButton);
        }
        m_currButton = NULL;
        break;

    default:
        break;
    }
    return VFX_TRUE;
}


void VcpVKLongtapHint::setPosZ(VfxFloat value)
{
    // set the position Z of longtap hint
    VfxFrame::setPosZ(value);

    // set the position Z of the components in longtap hint
    m_hiliteFrame->setPosZ(value - 1);
}


void VcpVKLongtapHint::onInit()
{
    VFX_ASSERT(m_info != NULL);

    VfxFrame::onInit();

    calculateRects();

    setIsUnhittable(VFX_TRUE);

    VFX_OBJ_CREATE(m_hiliteFrame, VcpVKHiliteFrame, this);

    // draw the highlight button in initial state
    // setHiliteButton(m_buttonList);
    m_hiliteFrame->setHidden(VFX_TRUE);
    // m_hiliteFrame->bringToFront();
    m_currButton = NULL;
}


void VcpVKLongtapHint::onDeinit()
{
    // delete the linked list of buttons
    VcpVKLongTapBtn *button = m_buttonList;
    VcpVKLongTapBtn *nextButton;

    while (button != NULL)
    {
        nextButton = button->next;
        VFX_DELETE(button);
        button = nextButton;
    }

    VfxFrame::onDeinit();
}


void VcpVKLongtapHint::onDraw(VfxDrawContext &dc)
{
    // draw background
    VfxRect bgRect(0, 0, getRect().getWidth(), getRect().getHeight());
    dc.drawResizedImage(bgRect, m_info->bgImg);

    // draw buttons
    for (VcpVKLongTapBtn *button = m_buttonList; button != NULL; button = button->next)
    {
        drawButton(dc, button);
    }

    // draw highlight frame
    if (m_currButton != NULL)
    {
        VfxImageSrc bgImg = m_info->buttonArray[m_currButton->index].bgHighlightImg;
        VfxImageSrc fgImg = m_info->buttonArray[m_currButton->index].fgHighlightImg;
        m_hiliteFrame->setBackgroundImg(bgImg);
        m_hiliteFrame->setForegroundImg(fgImg);
    }
}


void VcpVKLongtapHint::calculateRects()
{
    // m_buttonList must be not exist
    VFX_ASSERT(m_buttonList == NULL);
    // at least one button in longtap hint
    VFX_ASSERT(m_info->buttonCount > 0);
    // the max width is greater than the width which one button needs
    VFX_ASSERT((2 * VCP_VK_LONGTAP_BUTTON_X_OFFSET + m_info->buttonArray[0].width) <= m_info->maxWidth);

    VfxS32 maxX, maxY;

    // build the linked list of m_buttonList
    VcpVKLongTapBtn *currButton = NULL, *preButton = NULL;
    VFX_ALLOC_NEW(currButton, VcpVKLongTapBtn, m_parent);
    VFX_ASSERT(currButton != NULL);

    VfxS32 x = VCP_VK_LONGTAP_BUTTON_X_OFFSET;
    VfxS32 y = VCP_VK_LONGTAP_BUTTON_Y_OFFSET;
    currButton->rect = VfxRect(x, y, m_info->buttonArray[0].width, m_info->buttonArray[0].height);
    currButton->index = 0;
    currButton->next = NULL;
    m_buttonList = currButton;
    preButton = currButton;

    maxX = x + m_info->buttonArray[0].width;
    maxY = y + m_info->buttonArray[0].height;

    x += (m_info->buttonArray[0].width + VCP_VK_LONGTAP_BUTTON_X_GAP);

    for (VfxU16 count = 1; count < m_info->buttonCount; count++)
    {
        if ((x + m_info->buttonArray[count].width) > (m_info->maxWidth - VCP_VK_LONGTAP_BUTTON_X_OFFSET))
        {
            // need another row
            x = VCP_VK_LONGTAP_BUTTON_X_OFFSET;
            y = maxY + VCP_VK_LONGTAP_BUTTON_Y_GAP;
        }

        currButton = NULL;
        VFX_ALLOC_NEW(currButton, VcpVKLongTapBtn, m_parent);
        VFX_ASSERT(currButton != NULL);
        currButton->rect = VfxRect(x, y, m_info->buttonArray[count].width, m_info->buttonArray[count].height);
        currButton->index = count;
        currButton->next = NULL;
        preButton->next = currButton;
        preButton = currButton;

        if ((x + m_info->buttonArray[count].width) > maxX)
        {
            maxX = x + m_info->buttonArray[count].width;
        }
        if ((y + m_info->buttonArray[count].height) > maxY)
        {
            maxY = y + m_info->buttonArray[count].height;
        }

        x += (m_info->buttonArray[count].width + VCP_VK_LONGTAP_BUTTON_X_GAP);
    }

    // set the size of longtap hint
    VfxS32 width = maxX + VCP_VK_LONGTAP_BUTTON_X_OFFSET;
    VfxS32 height = maxY + VCP_VK_LONGTAP_BUTTON_Y_OFFSET;
    setSize(width, height);

    // process that the button is placed from right to left
    if (m_info->isR2L)
    {
        VfxS32 changedX;
        for (currButton = m_buttonList; currButton != NULL; currButton = currButton->next)
        {
            changedX = width - currButton->rect.getX() - currButton->rect.getWidth();
            currButton->rect.origin.x = changedX;
        }
    }
}


void VcpVKLongtapHint::drawButton(VfxDrawContext &dc, const VcpVKLongTapBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxImageSrc bgImg = m_info->buttonArray[button->index].bgImg;
    VfxImageSrc fgImg = m_info->buttonArray[button->index].fgImg;

    dc.setClip(button->rect);

    // draw background
    dc.drawResizedImage(button->rect, bgImg);

    // draw foreground. calculate the position
    VfxS32 x = ((button->rect.getWidth() - fgImg.getSize().width) / 2) + button->rect.getX();
    VfxS32 y = ((button->rect.getHeight() - fgImg.getSize().height) / 2) + button->rect.getY();
    dc.drawImage(x, y, fgImg);

    dc.setClip(VfxRect(0, 0, getRect().getWidth(), getRect().getHeight()));
}


void VcpVKLongtapHint::setHiliteButton(const VcpVKLongTapBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxImageSrc bgImg = m_info->buttonArray[button->index].bgHighlightImg;
    VfxImageSrc fgImg = m_info->buttonArray[button->index].fgHighlightImg;

    m_hiliteFrame->setBackgroundImg(bgImg);
    m_hiliteFrame->setForegroundImg(fgImg);

    m_hiliteFrame->setRect(button->rect);
}


const VcpVKLongTapBtn *VcpVKLongtapHint::getButtonByPoint(const VfxPoint &point)
{
    VfxS32 x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    for (VcpVKLongTapBtn *button = m_buttonList; button != NULL; button = button->next)
    {
        // enlarge the scope of button
        x1 = button->rect.origin.x - VCP_VK_LONGTAP_BUTTON_MORE_WIDTH;
        if (x1 < 0)
        {
            x1 = 0;
        }
        y1 = button->rect.origin.y - VCP_VK_LONGTAP_BUTTON_MORE_HEIGHT;
        if (y1 < 0)
        {
            y1 = 0;
        }
        x2 = button->rect.origin.x + button->rect.size.width + VCP_VK_LONGTAP_BUTTON_MORE_WIDTH;
        if (x2 > getSize().width)
        {
            x2 = getSize().width;
        }
        y2 = button->rect.origin.y + button->rect.size.height + VCP_VK_LONGTAP_BUTTON_MORE_HEIGHT;
        if (y2 > getSize().height)
        {
            y2 = getSize().height;
        }
        VfxRect checkRect(x1, y1, x2 - x1, y2 - y1);
        if (checkRect.contains(point))
        {
            return button;
        }
    }

    return NULL;
}


void VcpVKLongtapHint::emitMoveSignal(const VcpVKLongTapBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxU32 content = m_info->buttonArray[button->index].content;
    if (content > VCP_VK_CONTENT_CHARACTER_MAX)
    {
        // function button
        m_signalButtonMove.emit(this, VCP_VK_BUTTON_TYPE_FUNC, content);
    }
    else
    {
        // character button 
        m_signalButtonMove.emit(this, VCP_VK_BUTTON_TYPE_CHAR, content);
    }
}


void VcpVKLongtapHint::emitAbortSignal(const VcpVKLongTapBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxU32 content = m_info->buttonArray[button->index].content;
    if (content > VCP_VK_CONTENT_CHARACTER_MAX)
    {
        // function button
        m_signalButtonAbort.emit(this, VCP_VK_BUTTON_TYPE_FUNC, content);
    }
    else
    {
        // character button 
        m_signalButtonAbort.emit(this, VCP_VK_BUTTON_TYPE_CHAR, content);
    }
}


void VcpVKLongtapHint::emitUpSignal(const VcpVKLongTapBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxU32 content = m_info->buttonArray[button->index].content;
    if (content > VCP_VK_CONTENT_CHARACTER_MAX)
    {
        // function button
        m_signalButtonUp.emit(this, VCP_VK_BUTTON_TYPE_FUNC, content);
    }
    else
    {
        // character button 
        m_signalButtonUp.emit(this, VCP_VK_BUTTON_TYPE_CHAR, content);
    }
}


/***************************************************************************** 
* Class VcpVK
*****************************************************************************/
VFX_IMPLEMENT_CLASS(VCP_VK_CLASS_NAME, VcpVK, VfxControl);


VcpVK::VcpVK(VfxObject *m_parent) :
m_type(GUI_VIRTUAL_KEYBOARD_MAX_LANG),
m_attr(0),
m_buttonList(NULL),
m_currButton(NULL),
m_hiliteFrame(NULL),
m_popupHintFrame(NULL),
m_btnImgInfo(NULL),
m_displayCbObj(NULL),
m_displayCbFunc(NULL),
m_multiPopupCbObj(NULL),
m_multiPopupCbFunc(NULL),
m_inLongtapHintState(VFX_FALSE),
m_longtapTimer(NULL),
m_popupHideTimer(NULL),
m_longtapHint(NULL),
m_readyForLongtap(VFX_FALSE)
{
    m_disabledAllowedCharBtns.isDisabled = VFX_TRUE;
    m_disabledAllowedCharBtns.string.setEmpty();
    m_disabledFuncBtn[0] = GUI_VKBD_PEN_NONE;

    m_longtapBtnInfo.buttonCount = 0;
    m_longtapBtnInfo.isR2L = VFX_FALSE;
    m_longtapBtnInfo.maxWidth = 0;
	m_VKparent = m_parent ;
}


VcpVK::VcpVK(VcpVKTypeEnum type, VcpVKAttr attr) :
m_type(type),
m_attr(attr),
m_buttonList(NULL),
m_currButton(NULL),
m_hiliteFrame(NULL),
m_popupHintFrame(NULL),
m_btnImgInfo(NULL),
m_displayCbObj(NULL),
m_displayCbFunc(NULL),
m_multiPopupCbObj(NULL),
m_multiPopupCbFunc(NULL),
m_inLongtapHintState(VFX_FALSE),
m_longtapTimer(NULL),
m_popupHideTimer(NULL),
m_longtapHint(NULL),
m_readyForLongtap(VFX_FALSE)
{
    m_disabledAllowedCharBtns.isDisabled = VFX_TRUE;
    m_disabledAllowedCharBtns.string.setEmpty();
    m_disabledFuncBtn[0] = GUI_VKBD_PEN_NONE;

    m_longtapBtnInfo.buttonCount = 0;
    m_longtapBtnInfo.isR2L = VFX_FALSE;
    m_longtapBtnInfo.maxWidth = 0;
}


void VcpVK::setType(VcpVKTypeEnum type)
{
    if (type == m_type)
    {
        return;
    }

    m_type = type;
    checkUpdate();
}


void VcpVK::setAttr(VcpVKAttr attr)
{
    if (attr == m_attr)
    {
        return;
    }

    m_attr = attr;
    checkUpdate();
}




void VcpVK::setButtonImage(const VcpVKBtnImg &imageInfo)
{
    VcpVKBtnImgNode *currBtnImg = NULL;
    VcpVKBtnImgNode *preBtnImg = NULL;

    // add information into m_btnImgInfo
    if (m_btnImgInfo == NULL)
    {
        // when the linked list is empty
        VFX_ALLOC_NEW(currBtnImg, VcpVKBtnImgNode , m_VKparent);
        VFX_ASSERT(currBtnImg != NULL);
        currBtnImg->imgInfo = imageInfo;
        currBtnImg->next = NULL;
        m_btnImgInfo = currBtnImg;
    }
    else
    {
        // when the linked list is not empty
        for (currBtnImg = m_btnImgInfo; currBtnImg != NULL; currBtnImg = currBtnImg->next)
        {
            if (currBtnImg->imgInfo.content == imageInfo.content)
            {
                break;
            }
            preBtnImg = currBtnImg;
        }

        if (currBtnImg != NULL)
        {
            // the image information already been exist
            currBtnImg->imgInfo = imageInfo;
        }
        else
        {
            // add new node
            VFX_ALLOC_NEW(currBtnImg, VcpVKBtnImgNode , m_VKparent);
            VFX_ASSERT(currBtnImg != NULL);
            currBtnImg->imgInfo = imageInfo;
            currBtnImg->next = NULL;
            preBtnImg->next = currBtnImg;
        }
    }

    invalidate();
}


void VcpVK::clearAllButtonImage()
{
    // delete the image info of buttons
    VcpVKBtnImgNode *currButtonImg = m_btnImgInfo;
    VcpVKBtnImgNode *nextButtonImg;
    while (currButtonImg != NULL)
    {
        nextButtonImg = currButtonImg->next;
        VFX_DELETE(currButtonImg);
        currButtonImg = nextButtonImg;
    }
    m_btnImgInfo = NULL;

    invalidate();
}


void VcpVK::registerDisplayCallback(VfxObject *obj, const VcpVKDisplayCB cbFunc)
{
    m_displayCbObj = obj;
    m_displayCbFunc = cbFunc;

    invalidate();
}


void VcpVK::registerMultiPopupCallback(VfxObject *obj, const VcpVKMultiPopupCB cbFunc)
{
    m_multiPopupCbObj = obj;
    m_multiPopupCbFunc = cbFunc;

    invalidate();
}


void VcpVK::unregisterDisplayCallback()
{
    m_displayCbObj = NULL;
    m_displayCbFunc = NULL;
    invalidate();
}


void VcpVK::unregisterMultiPopupCallback()
{
    m_multiPopupCbObj = NULL;
    m_multiPopupCbFunc = NULL;
    invalidate();
}


void VcpVK::setPos(const VfxPoint &value)
{
    if (getPos() != value)
    {
        // hide the popup and highlight frame to fit the animation of vk
        m_popupHideTimer->stop();
        m_hiliteFrame->setHidden(VFX_TRUE);
        m_popupHintFrame->setHidden(VFX_TRUE);
    }

    VfxControl::setPos(value);
}


void VcpVK::setPosZ(VfxFloat value)
{
    // set the position Z of VK
    VfxControl::setPosZ(value);

    // set the position Z of the components in VK
    m_hiliteFrame->setPosZ(value - 1);
    m_popupHintFrame->setPosZ(value - 1);
    if (m_longtapHint != NULL)
    {
        m_longtapHint->setPosZ(value - 1);
    }
}


void VcpVK::onInit()
{
    VfxControl::onInit();

    // for performance, let the vk background is locked, set the highlight frame to be child of toplevel
    VFX_OBJ_CREATE(m_hiliteFrame, VcpVKHiliteFrame, VFX_OBJ_GET_INSTANCE(VfxTopLevel));
    VFX_OBJ_CREATE(m_popupHintFrame, VcpVKHiliteFrame, VFX_OBJ_GET_INSTANCE(VfxTopLevel));

    VFX_OBJ_CREATE(m_longtapTimer, VfxTimer, this);
    m_longtapTimer->setStartDelay(VCP_VK_LONGTAP_DELAY);
    m_longtapTimer->m_signalTick.connect(this, &VcpVK::longtapTimeup);

    // set the position Z of the components in VK
    VfxFloat posZ = getPosZ();
    m_hiliteFrame->setPosZ(posZ - 1);
    m_popupHintFrame->setPosZ(posZ - 1);

    VFX_OBJ_CREATE(m_popupHideTimer, VfxTimer, this);
    m_popupHideTimer->setStartDelay(VCP_VK_POPUP_HIDE_DELAY);
    m_popupHideTimer->m_signalTick.connect(this, &VcpVK::popupHideTimeup);

    if (m_type != GUI_VIRTUAL_KEYBOARD_MAX_LANG)
    {
        checkUpdate();
    }
}


void VcpVK::onDeinit()
{
    // delete the image info of buttons
    VcpVKBtnImgNode *currButtonImg = m_btnImgInfo;
    VcpVKBtnImgNode *nextButtonImg;
    while (currButtonImg != NULL)
    {
        nextButtonImg = currButtonImg->next;
        VFX_DELETE(currButtonImg);
        currButtonImg = nextButtonImg;
    }

    // delete the linked list of buttons
    VcpVKBtn *currButton = m_buttonList;
    VcpVKBtn *nextButton;
    while (currButton != NULL)
    {
        nextButton = currButton->next;
        VFX_DELETE(currButton);
        currButton = nextButton;
    }

    // delete the highlight frame
    VFX_OBJ_CLOSE(m_hiliteFrame);

    // delete the popup hint frame
    VFX_OBJ_CLOSE(m_popupHintFrame);

    // delete the longtap popup hint
    if (m_longtapHint != NULL)
    {
        VFX_OBJ_CLOSE(m_longtapHint);
        m_longtapHint = NULL;
    }

    VfxControl::onDeinit();
}



void VcpVK::onDraw(VfxDrawContext &dc)
{
    // draw background
    VfxRect bgRect(0, 0, getRect().getWidth(), getRect().getHeight());
    dc.drawResizedImageFromRes(bgRect, m_adaptor.getBgImage());

    // draw buttons
    for (VcpVKBtn *button = m_buttonList; button != NULL; button = button->next)
    {
        drawButton(dc, button);
    }

    // draw highlight frame
    if (m_currButton != NULL)
    {
        VfxImageSrc bgImg;
        VfxImageSrc fgImg;
        getButtonImg(m_currButton, VCP_VK_BUTTON_STATE_HILITE, bgImg, fgImg);
        m_hiliteFrame->setBackgroundImg(bgImg);
        m_hiliteFrame->setForegroundImg(fgImg);
    }

    // draw popup
    /* 
    We don't need to reget the popup hint image as it is already set when m_currButton is not NULL. We need to do it because this interferes with
    functionality to provide the multipopup in case of zhuyin 
    if ((m_currButton != NULL) && (checkPopupExist(m_currButton)))
    {
    VfxImageSrc bgImg;
    VfxImageSrc fgImg;
    getButtonImg(m_currButton, VCP_VK_BUTTON_STATE_POPUP, bgImg, fgImg);
    m_popupHintFrame->setBackgroundImg(bgImg);
    m_popupHintFrame->setForegroundImg(fgImg);
    } */ 

    // draw longtap hint
    if (m_longtapHint != NULL)
    {
        m_longtapHint->invalidate();
    }
}


VfxBool VcpVK::onPenInput(VfxPenEvent &event)
{
    const VcpVKBtn *button;

    switch (event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        button = getButtonByPoint(event.getRelPos(this));

        if (button == NULL)
        {
            // do not press down in active button
            m_hiliteFrame->setHidden(VFX_TRUE);
            m_popupHintFrame->setHidden(VFX_TRUE);
            m_currButton = NULL;
        }
        else
        {
            vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
            // down in active button
            // save the selected button
            m_currButton = button;
            // start timer for longtap
            m_longtapTimer->start();
            // stop timer for hiding popup
            m_popupHideTimer->stop();
            // draw highlight state
            setHiliteButton(button);
            m_hiliteFrame->setHidden(VFX_FALSE);
            m_hiliteFrame->bringToFront();
            // draw popup hint
            if (checkPopupExist(button))
            {
                setPopupHintFrame(button);
                m_popupHintFrame->setHidden(VFX_FALSE);
                m_popupHintFrame->bringToFront();
            }
                //HIde the old popup As there may be case when this button has none but last pressed one had ..like space
                else
                {
                    m_popupHintFrame->setHidden(VFX_TRUE);

                }

            // emit down signal
            emitDownSignal(button);
        }
        break;

    case VFX_PEN_EVENT_TYPE_LONG_TAP:
        // ignore
        break;

    case VFX_PEN_EVENT_TYPE_MOVE:
        if (m_inLongtapHintState)
        {
            // in longtap state, should transfer event to longtap hint
            VcpVKLongtapHintEvt longtapEvent;
            longtapEvent.type = VFX_PEN_EVENT_TYPE_MOVE;
            longtapEvent.pos = convertPointTo(event.getRelPos(this), m_longtapHint);
            VFX_ASSERT(m_longtapHint != NULL);
            m_longtapHint->processPenEvent(longtapEvent);
        }
        else if (m_readyForLongtap)
        {
            button = getButtonByPointStrict(event.getRelPos(this));
            if ((button == NULL) || (button != m_currButton))
            {
                // enter longtap state
                m_inLongtapHintState = VFX_TRUE;
                m_readyForLongtap = VFX_FALSE;
            }
        }
        else
        {
            // in normal situation
            if (m_currButton == NULL)
            {
                // ignore
            }
            else
            {
                button = getButtonByPoint(event.getRelPos(this));
                if (button == NULL)
                {
                    // move into inactive area
                    if (m_adaptor.checkAlphanumeric() == VFX_TRUE)
                    {
                        // alphanumeric vk
                        m_longtapTimer->stop();
                    }
                    else
                    {
                        m_hiliteFrame->setHidden(VFX_TRUE);
                        m_popupHintFrame->setHidden(VFX_TRUE);
                        m_longtapTimer->stop();
                    }
                }
                else if (button == m_currButton)
                {
                    // move in same button
                    if (m_hiliteFrame->getHidden())
                    {
                        m_hiliteFrame->setHidden(VFX_FALSE);
                        m_hiliteFrame->bringToFront();
                    }
                    if ((checkPopupExist(button)) && (m_popupHintFrame->getHidden()))
                    {
                        m_popupHintFrame->setHidden(VFX_FALSE);
                        m_popupHintFrame->bringToFront();
                    }
                }
                else
                {
                    // move into another button
                    if (m_adaptor.checkAlphanumeric() == VFX_TRUE)
                    {
                        // alphanumeric vk
                        m_longtapTimer->stop();
                    }
                    else
                    {
                        // save the selected button
                        m_currButton = button;
                        // stop timer for longtap
                        m_longtapTimer->stop();
                        // redraw highlight state of button
                        setHiliteButton(button);
                        m_hiliteFrame->setHidden(VFX_FALSE);
                        m_hiliteFrame->bringToFront();
                        // redraw the popup hint
                        if (checkPopupExist(button))
                        {
                            setPopupHintFrame(button);
                            m_popupHintFrame->setHidden(VFX_FALSE);
                            m_popupHintFrame->bringToFront();
                        }
                        else
                        {
                            m_popupHintFrame->setHidden(VFX_TRUE);
                        }
                        // emit move signal
                        emitMoveSignal(button);
                    }
                }
            }
        }
        break;

    case VFX_PEN_EVENT_TYPE_UP:
        if (m_inLongtapHintState)
        {
            // in longtap state, should transfer event to longtap hint
            VcpVKLongtapHintEvt longtapEvent;
            longtapEvent.type = VFX_PEN_EVENT_TYPE_UP;
            longtapEvent.pos = convertPointTo(event.getRelPos(this), m_longtapHint);
            VFX_ASSERT(m_longtapHint != NULL);
            m_longtapHint->processPenEvent(longtapEvent);

            // in up event, longtap hint should be destroyed
            VFX_OBJ_CLOSE(m_longtapHint);
            m_longtapHint = NULL;
            m_inLongtapHintState = VFX_FALSE;

            // back to initial state
            m_hiliteFrame->setHidden(VFX_TRUE);
            m_popupHintFrame->setHidden(VFX_TRUE);
            m_currButton = NULL;
        }
        else
        {
            if (m_currButton == NULL)
            {
                // ignore
            }
            else
            {
                if (m_readyForLongtap)
                {
                    VFX_ASSERT(m_longtapHint != NULL);
                    VFX_OBJ_CLOSE(m_longtapHint);
                    m_longtapHint = NULL;
                    m_inLongtapHintState = VFX_FALSE;
                    m_readyForLongtap = VFX_FALSE;
                }
                m_popupHideTimer->start();
                m_longtapTimer->stop();
                if (m_adaptor.checkAlphanumeric() == VFX_TRUE)
                {
                    emitUpSignal(m_currButton);
                }
                else
                {   
                    button = getButtonByPoint(event.getRelPos(this));
                    if (button == NULL)
                    {
                        // up in inactive area
                        emitAbortSignal(m_currButton);
                    }
                    else if (button == m_currButton)
                    {
                        // up in same button
                        emitUpSignal(m_currButton);
                    }
                    else
                    {
                        // up in another button
                        emitUpSignal(m_currButton);
                    }
                }

                m_currButton = NULL;
            }
        }
        break;

    case VFX_PEN_EVENT_TYPE_ABORT:
        if (m_inLongtapHintState)
        {
            // in longtap state, should transfer event to longtap hint
            VcpVKLongtapHintEvt longtapEvent;
            longtapEvent.type = VFX_PEN_EVENT_TYPE_ABORT;
            longtapEvent.pos = convertPointTo(event.getRelPos(this), m_longtapHint);
            VFX_ASSERT(m_longtapHint != NULL);
            m_longtapHint->processPenEvent(longtapEvent);

            // in abort event, longtap hint should be destroyed
            VFX_OBJ_CLOSE(m_longtapHint);
            m_longtapHint = NULL;
            m_inLongtapHintState = VFX_FALSE;

            // back to initial state
            m_hiliteFrame->setHidden(VFX_TRUE);
            m_popupHintFrame->setHidden(VFX_TRUE);
            m_currButton = NULL;
        }
        else
        {
            if (m_currButton == NULL)
            {
                // ignore
            }
            else
            {
                if (m_readyForLongtap)
                {
                    VFX_ASSERT(m_longtapHint != NULL);
                    VFX_OBJ_CLOSE(m_longtapHint);
                    m_longtapHint = NULL;
                    m_inLongtapHintState = VFX_FALSE;
                    m_readyForLongtap = VFX_FALSE;
                }
                m_hiliteFrame->setHidden(VFX_TRUE);
                m_popupHintFrame->setHidden(VFX_TRUE);
                m_longtapTimer->stop();
                emitAbortSignal(m_currButton);
                m_currButton = NULL;
            }
        }
        break;

    default:
        break;
    }
    return VFX_TRUE;
}


void VcpVK::onUpdate()
{
    VFX_ASSERT(m_type != GUI_VIRTUAL_KEYBOARD_MAX_LANG);

    // clear the previous display
    m_hiliteFrame->setHidden(VFX_TRUE);
    m_popupHintFrame->setHidden(VFX_TRUE);

    // emit the abort signal when one button is active
    if (m_inLongtapHintState)
    {
        // in longtap state, should transfer event to longtap hint
        VcpVKLongtapHintEvt longtapEvent;
        longtapEvent.type = VFX_PEN_EVENT_TYPE_ABORT;
        VFX_ASSERT(m_longtapHint != NULL);
        m_longtapHint->processPenEvent(longtapEvent);
    }
    else
    {
        if (m_currButton != NULL)
        {
            emitAbortSignal(m_currButton);
        }
    }

    // get the layout of virtual keyboard
    vrt_size_struct mainScreenSize;
    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
    if (m_adaptor.setup(mainScreenSize.width, mainScreenSize.height, m_type, m_attr) == VFX_FALSE)
    {
        // can not find the layout
        // VFX_ASSERT(0);
    }

    // delete the old linked list of buttons
    VcpVKBtn *currButton = m_buttonList;
    VcpVKBtn *nextButton;
    while (currButton != NULL)
    {
        nextButton = currButton->next;
        VFX_DELETE(currButton);
        currButton = nextButton;
    }
    m_buttonList = NULL;
    m_currButton = NULL;

    // build the new linked list of buttons
    VfxS32 x, y, width, height;
    VfxU16 index;
    VfxU16 count = m_adaptor.getButtonCount();
    VfxU32 content;
    VcpVKBtn *preButton = NULL;
    // build the first button in button list
    for (index = 0; index < count; index++)
    {
        if (m_adaptor.checkButtonIsNormal(index) == VFX_TRUE)
        {
            // the button is not popup, and add into linked list
            VFX_ALLOC_NEW(currButton, VcpVKBtn , m_VKparent);
            VFX_ASSERT(currButton != NULL);
            content = m_adaptor.getButtonContent(index);
            if (checkButtonIsAllowed(content))
            {
                currButton->isAllowed = VFX_TRUE;
            }
            else
            {
                currButton->isAllowed = VFX_FALSE;
            }
            m_adaptor.getButtonRect(index, &x, &y, &width, &height);
            currButton->rect = VfxRect(x, y, width, height);
            currButton->index = index;
            currButton->next = NULL;
            m_buttonList = currButton;
            preButton = currButton;
            break;
        }
    }
    if (index == count)
    {
        // no button which is not popup
        // VFX_ASSERT(0);
    }
    index++;
    // build the other button in button list
    for (; index < count; index++)
    {
        if (m_adaptor.checkButtonIsNormal(index) == VFX_TRUE)
        {
            // the button is not popup, and add into linked list
            VFX_ALLOC_NEW(currButton, VcpVKBtn, m_VKparent);
            VFX_ASSERT(currButton != NULL);
            content = m_adaptor.getButtonContent(index);
            if (checkButtonIsAllowed(content))
            {
                currButton->isAllowed = VFX_TRUE;
            }
            else
            {
                currButton->isAllowed = VFX_FALSE;
            }
            m_adaptor.getButtonRect(index, &x, &y, &width, &height);
            currButton->rect = VfxRect(x, y, width, height);
            currButton->index = index;
            currButton->next = NULL;
            preButton->next = currButton;
            preButton = currButton;
        }
    }

    // get the size of virtual keyboard
    m_adaptor.getSize(&width, &height);

    // close the animation for the changing of vk size
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setSize(width, height);
    VfxAutoAnimate::commit();

    // let to redraw
    invalidate();
}





void VcpVK::drawButton(VfxDrawContext &dc, const VcpVKBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxImageSrc bgImg;
    VfxImageSrc fgImg;

    if (button->isAllowed)
    {
        getButtonImg(button, VCP_VK_BUTTON_STATE_NORMAL, bgImg, fgImg);
    }
    else
    {
        getButtonImg(button, VCP_VK_BUTTON_STATE_DISABLED, bgImg, fgImg);
    }

    dc.setClip(button->rect);

    // draw background
    dc.drawResizedImage(button->rect, bgImg);

    // draw foreground. calculate the position
    VfxS32 x = ((button->rect.getWidth() - fgImg.getSize().width) / 2) + button->rect.getX();
    VfxS32 y = ((button->rect.getHeight() - fgImg.getSize().height) / 2) + button->rect.getY();
    dc.drawImage(x, y, fgImg);

    dc.setClip(VfxRect(0, 0, getRect().getWidth(), getRect().getHeight()));
}


void VcpVK::getButtonImg(const VcpVKBtn *button, VcpVKBtnStateEnum state, VfxImageSrc &bgImg, VfxImageSrc &fgImg)
{
    bgImg.setNull();
    fgImg.setNull();

    VcpVKBtnImgNode *currBtnImg;
    VfxU32 content = m_adaptor.getButtonContent(button->index);
    for (currBtnImg = m_btnImgInfo; currBtnImg != NULL; currBtnImg = currBtnImg->next)
    {
        if (currBtnImg->imgInfo.content == content)
        {
            break;
        }
    }

    VcpVKDisplayCbPara displayCbPara;
    switch (state)
    {
    case VCP_VK_BUTTON_STATE_NORMAL:
        // get from the linked list
        if ((currBtnImg != NULL) && !(currBtnImg->imgInfo.bgImg.isEmpty() || currBtnImg->imgInfo.bgImg.isNull()))
        {
            bgImg = currBtnImg->imgInfo.bgImg;
        }

        if ((currBtnImg != NULL) && !(currBtnImg->imgInfo.fgImg.isEmpty() || currBtnImg->imgInfo.fgImg.isNull()))
        {
            fgImg = currBtnImg->imgInfo.fgImg;
        }

        if ((!bgImg.isNull()) && (!fgImg.isNull()))
        {
            break;
        }

        // get from display callback function
        if ((m_displayCbObj.isValid() == VFX_TRUE) && (m_displayCbFunc != NULL))
        {
            displayCbPara.buttonInfo.buttonContent = content;
            displayCbPara.buttonInfo.pos = VCP_VK_BUTTON_IMG_POS_BG;
            displayCbPara.buttonInfo.state = VCP_VK_BUTTON_STATE_NORMAL;
            if (bgImg.isNull())
            {
                displayCbPara.image.setNull();
                (m_displayCbObj.get()->*m_displayCbFunc)(displayCbPara);
                bgImg = displayCbPara.image;
            }
            displayCbPara.buttonInfo.pos = VCP_VK_BUTTON_IMG_POS_FG;
            if (fgImg.isNull())
            {
                displayCbPara.image.setNull();
                (m_displayCbObj.get()->*m_displayCbFunc)(displayCbPara);
                fgImg = displayCbPara.image;
            }
            if ((!bgImg.isNull()) && (!fgImg.isNull()))
            {
                break;
            }
        }

        // get from the file generated by MCT
        if (bgImg.isNull())
        {
            VfxResId bgId = m_adaptor.getButtonNormalBgImg(button->index);
            if (bgId != 0)
            {
                bgImg.setResId(bgId);
            }
        }

        if (fgImg.isNull())
        {
            VfxResId fgId = m_adaptor.getButtonNormalFgImg(button->index);
            if (fgId != 0)
            {
                fgImg.setResId(fgId);
            }
        }

        if (bgImg.isNull())
        {
            // can not find valid image id
            bgImg.setResId(IMG_GLOBAL_DEFAULT);
        }
        if (fgImg.isNull())
        {
            // can not find valid image id
            fgImg.setResId(IMG_GLOBAL_DEFAULT);
        }
        break;

    case VCP_VK_BUTTON_STATE_HILITE:
        // get from the linked list
        if ((currBtnImg != NULL) && !(currBtnImg->imgInfo.bgHighlightImg.isEmpty() || currBtnImg->imgInfo.bgHighlightImg.isNull()))
        {
            bgImg = currBtnImg->imgInfo.bgHighlightImg;
        }

        if ((currBtnImg != NULL) && !(currBtnImg->imgInfo.fgHighlightImg.isEmpty() || currBtnImg->imgInfo.fgHighlightImg.isNull()))
        {
            fgImg = currBtnImg->imgInfo.fgHighlightImg;
        }

        if ((!bgImg.isNull()) && (!fgImg.isNull()))
        {
            break;
        }

        // get from display callback function
        if ((m_displayCbObj.isValid() == VFX_TRUE) && (m_displayCbFunc != NULL))
        {
            displayCbPara.buttonInfo.buttonContent = content;
            displayCbPara.buttonInfo.pos = VCP_VK_BUTTON_IMG_POS_BG;
            displayCbPara.buttonInfo.state = VCP_VK_BUTTON_STATE_HILITE;
            if (bgImg.isNull())
            {
                displayCbPara.image.setNull();
                (m_displayCbObj.get()->*m_displayCbFunc)(displayCbPara);
                bgImg = displayCbPara.image;

            }
            displayCbPara.buttonInfo.pos = VCP_VK_BUTTON_IMG_POS_FG;
            if (fgImg.isNull())
            {
                displayCbPara.image.setNull();
                (m_displayCbObj.get()->*m_displayCbFunc)(displayCbPara);
                fgImg = displayCbPara.image;
            }
            if ((!bgImg.isNull()) && (!fgImg.isNull()))
            {
                break;
            }
        }

        // get from the file generated by MCT
        if (bgImg.isNull())
        {
            VfxResId bgId = m_adaptor.getButtonHiliteBgImg(button->index);
            if (bgId != 0)
            {
                bgImg.setResId(bgId);
            }
        }

        if (fgImg.isNull())
        {
            VfxResId fgId = m_adaptor.getButtonHiliteFgImg(button->index);
            if (fgId != 0)
            {
                fgImg.setResId(fgId);
            }
        }

        if (bgImg.isNull())
        {
            // can not find valid image id
            bgImg.setResId(IMG_GLOBAL_DEFAULT);
        }
        if (fgImg.isNull())
        {
            // can not find valid image id
            fgImg.setResId(IMG_GLOBAL_DEFAULT);
        }
        break;

    case VCP_VK_BUTTON_STATE_DISABLED:
        // get from the linked list
        if ((currBtnImg != NULL) && !(currBtnImg->imgInfo.bgDisabledImg.isEmpty() || currBtnImg->imgInfo.bgDisabledImg.isNull()))
        {
            bgImg = currBtnImg->imgInfo.bgDisabledImg;
        }

        if ((currBtnImg != NULL) && !(currBtnImg->imgInfo.fgDisabledImg.isEmpty() || currBtnImg->imgInfo.fgDisabledImg.isNull()))
        {
            fgImg = currBtnImg->imgInfo.fgDisabledImg;
        }

        if ((!bgImg.isNull()) && (!fgImg.isNull()))
        {
            break;
        }

        // get from display callback function
        if ((m_displayCbObj.isValid() == VFX_TRUE) && (m_displayCbFunc != NULL))
        {
            displayCbPara.buttonInfo.buttonContent = content;
            displayCbPara.buttonInfo.pos = VCP_VK_BUTTON_IMG_POS_BG;
            displayCbPara.buttonInfo.state = VCP_VK_BUTTON_STATE_DISABLED;
            if (bgImg.isNull())
            {
                displayCbPara.image.setNull();
                (m_displayCbObj.get()->*m_displayCbFunc)(displayCbPara);
                bgImg = displayCbPara.image;
            }
            displayCbPara.buttonInfo.pos = VCP_VK_BUTTON_IMG_POS_FG;
            if (fgImg.isNull())
            {
                displayCbPara.image.setNull();
                (m_displayCbObj.get()->*m_displayCbFunc)(displayCbPara);
                fgImg = displayCbPara.image;
            }
            if ((!bgImg.isNull()) && (!fgImg.isNull()))
            {
                break;
            }
        }

        // get from the file generated by MCT
        if (bgImg.isNull())
        {
            VfxResId bgId = m_adaptor.getButtonDisabledBgImg(button->index);
            if (bgId != 0)
            {
                bgImg.setResId(bgId);
            }
        }

        if (fgImg.isNull())
        {
            VfxResId fgId = m_adaptor.getButtonDisabledFgImg(button->index);
            if (fgId != 0)
            {
                fgImg.setResId(fgId);
            }
        }

        if (bgImg.isNull())
        {
            // can not find valid image id
            bgImg.setResId(IMG_GLOBAL_DEFAULT);
        }
        if (fgImg.isNull())
        {
            // can not find valid image id
            fgImg.setResId(IMG_GLOBAL_DEFAULT);
        }
        break;

    case VCP_VK_BUTTON_STATE_POPUP:
        // get from the linked list
        if ((currBtnImg != NULL) && !(currBtnImg->imgInfo.bgPopupImg.isEmpty() || currBtnImg->imgInfo.bgPopupImg.isNull()))
        {
            bgImg = currBtnImg->imgInfo.bgPopupImg;
        }

        if ((currBtnImg != NULL) && !(currBtnImg->imgInfo.fgPopupImg.isEmpty() || currBtnImg->imgInfo.fgPopupImg.isNull()))
        {
            fgImg = currBtnImg->imgInfo.fgPopupImg;
        }

        if ((!bgImg.isNull()) && (!fgImg.isNull()))
        {
            break;
        }

        // get from display callback function
        if ((m_displayCbObj.isValid() == VFX_TRUE) && (m_displayCbFunc != NULL))
        {
            displayCbPara.buttonInfo.buttonContent = content;
            displayCbPara.buttonInfo.pos = VCP_VK_BUTTON_IMG_POS_BG;
            displayCbPara.buttonInfo.state = VCP_VK_BUTTON_STATE_POPUP;
            if (bgImg.isNull())
            {
                displayCbPara.image.setNull();
                (m_displayCbObj.get()->*m_displayCbFunc)(displayCbPara);
                bgImg = displayCbPara.image;
            }
            displayCbPara.buttonInfo.pos = VCP_VK_BUTTON_IMG_POS_FG;
            if (fgImg.isNull())
            {
                displayCbPara.image.setNull();
                (m_displayCbObj.get()->*m_displayCbFunc)(displayCbPara);
                fgImg = displayCbPara.image;
            }
            if ((!bgImg.isNull()) && (!fgImg.isNull()))
            {
                break;
            }
        }

        // get from multi popup callback function
        if ((m_multiPopupCbObj.isValid() == VFX_TRUE) && (m_multiPopupCbFunc != NULL))
        {
            VfxU32 index = 0;
            if ((m_multiPopupCbObj.get()->*m_multiPopupCbFunc)(m_adaptor.getButtonContent(button->index), &index) == VFX_TRUE)
            {
                VfxResId tempFg = 0, tempBg = 0;
                m_adaptor.getButtonMultiPopupImg(button->index, index, &tempFg, &tempBg);

                if (bgImg.isNull() && (tempBg != 0))
                {
                    bgImg.setResId(tempBg);
                }

                if (fgImg.isNull() && (tempFg != 0))
                {
                    fgImg.setResId(tempFg);
                }

                if ((!bgImg.isNull()) && (!fgImg.isNull()))
                {
                    break;
                }
            }
        }

        // get from the file generated by MCT
        if (bgImg.isNull())
        {
            VfxResId bgId = m_adaptor.getButtonPopupBgImg(button->index);
            if (bgId != 0)
            {
                bgImg.setResId(bgId);
            }
        }

        if (fgImg.isNull())
        {
            VfxResId fgId = m_adaptor.getButtonPopupFgImg(button->index);
            if (fgId != 0)
            {
                fgImg.setResId(fgId);
            }
        }

        if (bgImg.isNull())
        {
            // can not find valid image id
            bgImg.setResId(IMG_GLOBAL_DEFAULT);
        }
        if (fgImg.isNull())
        {
            // can not find valid image id
            fgImg.setResId(IMG_GLOBAL_DEFAULT);
        }
        break;

    default:
        VFX_ASSERT(0);
        break;
    }
}


void VcpVK::getLongtapButtonImg(
                                const VcpVKBtn *button,
                                VfxU16 index,
                                VfxImageSrc &bgImg,
                                VfxImageSrc &fgImg,
                                VfxImageSrc &bgHiliteImg,
                                VfxImageSrc &fgHiliteImg
                                )
{
    bgImg.setNull();
    fgImg.setNull();
    bgHiliteImg.setNull();
    fgHiliteImg.setNull();

    VcpVKBtnImgNode *currBtnImg;
    VfxU32 content = m_adaptor.getButtonLongtapContent(button->index, index);

    for (currBtnImg = m_btnImgInfo; currBtnImg != NULL; currBtnImg = currBtnImg->next)
    {
        if (currBtnImg->imgInfo.content == content)
        {
            break;
        }
    }

    // get from the linked list
    if ((currBtnImg != NULL) && !(currBtnImg->imgInfo.bgImg.isEmpty() || currBtnImg->imgInfo.bgImg.isNull()))
    {
        bgImg = currBtnImg->imgInfo.bgImg;
    }

    if ((currBtnImg != NULL) && !(currBtnImg->imgInfo.fgImg.isEmpty() || currBtnImg->imgInfo.fgImg.isNull()))
    {
        fgImg = currBtnImg->imgInfo.fgImg;
    }

    if ((currBtnImg != NULL) && !(currBtnImg->imgInfo.bgHighlightImg.isEmpty() || currBtnImg->imgInfo.bgHighlightImg.isNull()))
    {
        bgHiliteImg = currBtnImg->imgInfo.bgHighlightImg;
    }

    if ((currBtnImg != NULL) && !(currBtnImg->imgInfo.fgHighlightImg.isEmpty() || currBtnImg->imgInfo.fgHighlightImg.isNull()))
    {
        fgHiliteImg = currBtnImg->imgInfo.fgHighlightImg;
    }

    if ((!bgImg.isNull()) &&
        (!fgImg.isNull()) &&
        (!bgHiliteImg.isNull()) &&
        (!fgHiliteImg.isNull()))
    {
        return;
    }

    // get from display callback function
    if ((m_displayCbObj.isValid() == VFX_TRUE) && (m_displayCbFunc != NULL))
    {
        VcpVKDisplayCbPara displayCbPara;
        displayCbPara.buttonInfo.buttonContent = content;
        displayCbPara.buttonInfo.pos = VCP_VK_BUTTON_IMG_POS_BG;
        displayCbPara.buttonInfo.state = VCP_VK_BUTTON_STATE_NORMAL;
        if (bgImg.isNull())
        {
            displayCbPara.image.setNull();
            (m_displayCbObj.get()->*m_displayCbFunc)(displayCbPara);
            bgImg = displayCbPara.image;
        }
        displayCbPara.buttonInfo.pos = VCP_VK_BUTTON_IMG_POS_FG;
        if (fgImg.isNull())
        {
            displayCbPara.image.setNull();
            (m_displayCbObj.get()->*m_displayCbFunc)(displayCbPara);
            fgImg = displayCbPara.image;
        }
        displayCbPara.buttonInfo.pos = VCP_VK_BUTTON_IMG_POS_BG;
        displayCbPara.buttonInfo.state = VCP_VK_BUTTON_STATE_HILITE;
        if (bgHiliteImg.isNull())
        {
            displayCbPara.image.setNull();
            (m_displayCbObj.get()->*m_displayCbFunc)(displayCbPara);
            bgHiliteImg = displayCbPara.image;
        }
        displayCbPara.buttonInfo.pos = VCP_VK_BUTTON_IMG_POS_FG;
        if (fgHiliteImg.isNull())
        {
            displayCbPara.image.setNull();
            (m_displayCbObj.get()->*m_displayCbFunc)(displayCbPara);
            fgHiliteImg = displayCbPara.image;
        }
        if ((!bgImg.isNull()) &&
            (!fgImg.isNull()) &&
            (!bgHiliteImg.isNull()) &&
            (!fgHiliteImg.isNull()))
        {
            return;
        }
    }

    // get from the file generated by MCT
    VfxResId tempFg = 0, tempBg = 0, tempFgHilite = 0, tempBgHilite = 0;
    m_adaptor.getButtonLongtapImg(
        button->index,
        index,
        &tempFg,
        &tempBg,
        &tempFgHilite,
        &tempBgHilite);

    if (bgImg.isNull() && (tempBg != 0))
    {
        bgImg.setResId(tempBg);
    }

    if (fgImg.isNull() && (tempFg != 0))
    {
        fgImg.setResId(tempFg);
    }

    if (bgHiliteImg.isNull() && (tempBgHilite != 0))
    {
        bgHiliteImg.setResId(tempBgHilite);
    }

    if (fgHiliteImg.isNull() && (tempFgHilite != 0))
    {
        fgHiliteImg.setResId(tempFgHilite);
    }

    if (bgImg.isNull())
    {
        // can not find valid image id
        bgImg.setResId(IMG_GLOBAL_DEFAULT);
    }
    if (fgImg.isNull())
    {
        // can not find valid image id
        fgImg.setResId(IMG_GLOBAL_DEFAULT);
    }
    if (bgHiliteImg.isNull())
    {
        // can not find valid image id
        bgHiliteImg.setResId(IMG_GLOBAL_DEFAULT);
    }
    if (fgHiliteImg.isNull())
    {
        // can not find valid image id
        fgHiliteImg.setResId(IMG_GLOBAL_DEFAULT);
    }
}


const VcpVKBtn *VcpVK::getButtonByPointStrict(const VfxPoint &point)
{
    for (VcpVKBtn *button = m_buttonList; button != NULL; button = button->next)
    {
        if (button->rect.contains(point))
        {
            if (button->isAllowed == VFX_FALSE)
            {
                return NULL;
            }
            else
            {
                return button;
            }
        }
    }

    return NULL;
}


const VcpVKBtn *VcpVK::getButtonByPoint(const VfxPoint &point)
{
    VfxU64 minDistance = 0xffffffffffffffff;
    VcpVKBtn *nearButton = NULL;

    for (VcpVKBtn *button = m_buttonList; button != NULL; button = button->next)
    {
        if (button->rect.contains(point))
        {
            if (button->isAllowed == VFX_FALSE)
            {
                return NULL;
            }
            else
            {
                return button;
            }
        }

        // find the nearist button
        if (button->isAllowed == VFX_TRUE)
        {
            VfxS32 dX = point.x - (button->rect.getX() + button->rect.getWidth() / 2);
            VfxS32 dY = point.y - (button->rect.getY() + button->rect.getHeight() / 2);
            VfxU64 distance = dX * dX + dY * dY;
            if (distance < minDistance)
            {
                minDistance = distance;
                nearButton = button;
            }
        }
    }

    return nearButton;
}


void VcpVK::emitDownSignal(const VcpVKBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxU32 content = m_adaptor.getButtonContent(button->index);
    if (content > VCP_VK_CONTENT_CHARACTER_MAX)
    {
        // function button
        m_signalButtonDown.postEmit(this, VCP_VK_BUTTON_TYPE_FUNC, content);
    }
    else
    {
        // character button 
        m_signalButtonDown.postEmit(this, VCP_VK_BUTTON_TYPE_CHAR, content);
    }
}


void VcpVK::emitLongtapSignal(const VcpVKBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxU32 content = m_adaptor.getButtonContent(button->index);
    if (content > VCP_VK_CONTENT_CHARACTER_MAX)
    {
        // function button
        m_signalButtonLongtap.postEmit(this, VCP_VK_BUTTON_TYPE_FUNC, content);
    }
    else
    {
        // character button 
        m_signalButtonLongtap.postEmit(this, VCP_VK_BUTTON_TYPE_CHAR, content);
    }
}


void VcpVK::emitMoveSignal(const VcpVKBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxU32 content = m_adaptor.getButtonContent(button->index);
    if (content > VCP_VK_CONTENT_CHARACTER_MAX)
    {
        // function button
        m_signalButtonMove.postEmit(this, VCP_VK_BUTTON_TYPE_FUNC, content);
    }
    else
    {
        // character button 
        m_signalButtonMove.postEmit(this, VCP_VK_BUTTON_TYPE_CHAR, content);
    }
}


void VcpVK::emitUpSignal(const VcpVKBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxU32 content = m_adaptor.getButtonContent(button->index);
    if (content > VCP_VK_CONTENT_CHARACTER_MAX)
    {
        // function button
        m_signalButtonUp.postEmit(this, VCP_VK_BUTTON_TYPE_FUNC, content);
    }
    else
    {
        // character button 
        m_signalButtonUp.postEmit(this, VCP_VK_BUTTON_TYPE_CHAR, content);
    }
}


void VcpVK::emitAbortSignal(const VcpVKBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxU32 content = m_adaptor.getButtonContent(button->index);
    if (content > VCP_VK_CONTENT_CHARACTER_MAX)
    {
        // function button
        m_signalButtonAbort.postEmit(this, VCP_VK_BUTTON_TYPE_FUNC, content);
    }
    else
    {
        // character button 
        m_signalButtonAbort.postEmit(this, VCP_VK_BUTTON_TYPE_CHAR, content);
    }
}


void VcpVK::longtapTimeup(VfxTimer *timerFunc)
{
    // maybe the vk is resetted
    if (m_currButton == NULL)
    {
        return;
    }

    // emit longtap signal
    emitLongtapSignal(m_currButton);

    // set longtap hint
    if (checklongtapExist(m_currButton))
    {
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
        // hide popup hint
        m_popupHintFrame->setHidden(VFX_TRUE);

        // clear previous
        if (m_longtapHint != NULL)
        {
            VFX_OBJ_CLOSE(m_longtapHint);
            m_longtapHint = NULL;
        }

        // get button information of longtap hint
        VfxU16 count = 0, total = 0;
        total= m_adaptor.getButtonLongtapBtnNum(m_currButton->index);

        if (total > VCP_VK_LONGTAP_BUTTON_MAX)
        {
            total = (VfxU16)VCP_VK_LONGTAP_BUTTON_MAX;
        }

        // initial the button array
        for (VfxS32 i = 0; i < total; i++)
        {
            m_longtapBtnInfo.buttonArray[i].fgImg.setNull();
            m_longtapBtnInfo.buttonArray[i].fgHighlightImg.setNull();
            m_longtapBtnInfo.buttonArray[i].bgImg.setNull();
            m_longtapBtnInfo.buttonArray[i].bgHighlightImg.setNull();
        }

        for (VfxU16 i = 0; i < total; i++)
        {
            VfxU32 content = m_adaptor.getButtonLongtapContent(
                m_currButton->index,
                i);

            if (checkButtonIsAllowed(content) == VFX_FALSE)
            {
                continue;
            }

            // for special case
            if ((content == GUI_VKBD_PEN_DOT_COM) &&
                (m_adaptor.checkAlphanumeric() == VFX_TRUE))
            {
                content = GUI_VKBD_PEN_ALPHANUMERIC_DOT_COM;
            }

            m_longtapBtnInfo.buttonArray[count].content = content;

            getLongtapButtonImg(
                m_currButton,
                i,
                m_longtapBtnInfo.buttonArray[count].bgImg,
                m_longtapBtnInfo.buttonArray[count].fgImg,
                m_longtapBtnInfo.buttonArray[count].bgHighlightImg,
                m_longtapBtnInfo.buttonArray[count].fgHighlightImg);

            m_adaptor.getButtonLongtapSize(
                m_currButton->index,
                i,
                &(m_longtapBtnInfo.buttonArray[count].width),
                &(m_longtapBtnInfo.buttonArray[count].height));

            count++;
        }

        if (count == 0)
        {
            // no button in longtap hint
            return;
        }
        m_longtapBtnInfo.buttonCount = count;
        m_longtapBtnInfo.bgImg.setResId(m_adaptor.getLongtapBgImg());

        // decide the max width
        VfxS32 bound;
        if (m_currButton->rect.origin.x < (getSize().width / 2))
        {
            // the button is in left side
            m_longtapBtnInfo.isR2L = VFX_FALSE;
            bound = m_currButton->rect.origin.x - VCP_VK_LONGTAP_BUTTON_X_OFFSET;
            if (bound < 0)
            {
                bound = 0;
            }
            m_longtapBtnInfo.maxWidth = getSize().width - bound;
        }
        else
        {
            // the button is in right side
            m_longtapBtnInfo.isR2L = VFX_TRUE;
            bound = m_currButton->rect.origin.x + m_currButton->rect.size.width + VCP_VK_LONGTAP_BUTTON_X_OFFSET;
            if (bound > getSize().width)
            {
                bound = getSize().width;
            }
            m_longtapBtnInfo.maxWidth = bound;
        }

        // create longtap hint object
        VFX_OBJ_CREATE_EX(m_longtapHint, VcpVKLongtapHint, VFX_OBJ_GET_INSTANCE(VfxTopLevel), (&m_longtapBtnInfo , m_VKparent));

        // set the position of Z
        m_longtapHint->setPosZ(getPosZ() - 1);

        // set position of longtap hint
        VfxS32 x, y;
        if (m_currButton->rect.origin.x < (getSize().width / 2))
        {
            // the button is in left side
            x = m_currButton->rect.origin.x - VCP_VK_LONGTAP_BUTTON_X_OFFSET;
            if (x < 0)
            {
                x = 0;
            }
        }
        else
        {
            // the button is in right side
            x = m_currButton->rect.origin.x + m_currButton->rect.size.width + VCP_VK_LONGTAP_BUTTON_X_OFFSET;
            if (x > getSize().width)
            {
                x = getSize().width;
            }
            x = x - m_longtapHint->getSize().width;
        }
        y = m_currButton->rect.origin.y - VCP_VK_LONGTAP_GAP - m_longtapHint->getSize().height;

        m_longtapHint->setPos(convertPointTo(VfxPoint(x, y), VFX_OBJ_GET_INSTANCE(VfxTopLevel)));
        m_longtapHint->setHidden(VFX_FALSE);

        // connect signal
        m_longtapHint->m_signalButtonMove.connect(this, &VcpVK::longtapHintMoveHandler);
        m_longtapHint->m_signalButtonAbort.connect(this, &VcpVK::longtapHintAbortHandler);
        m_longtapHint->m_signalButtonUp.connect(this, &VcpVK::longtapHintUpHandler);

        // set the flag to notify that vk is ready for entering longtap state
        m_readyForLongtap = VFX_TRUE;
    }
}


void VcpVK::popupHideTimeup(VfxTimer *timerFunc)
{
    m_hiliteFrame->setHidden(VFX_TRUE);
    m_popupHintFrame->setHidden(VFX_TRUE);
}


void VcpVK::setHiliteButton(const VcpVKBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxImageSrc bgImg;
    VfxImageSrc fgImg;

    getButtonImg(button, VCP_VK_BUTTON_STATE_HILITE, bgImg, fgImg);

    m_hiliteFrame->setBackgroundImg(bgImg);
    m_hiliteFrame->setForegroundImg(fgImg);
    // set the coordinate bases on toplevel, because the highlight frame is child of toplevel
    m_hiliteFrame->setRect(convertRectTo(button->rect, VFX_OBJ_GET_INSTANCE(VfxTopLevel)));

    // special to handle the up-arrow,down-arrow in sym page1,page4. 
    // the disabled, normal, highlight images all are same as disabled images.
    // but the background image is half-transparent, so, the effect is wrong. 
    // to set the highlight images to be transparent.
    VfxImageSrc normalBgImg;
    VfxImageSrc normalFgImg;

    getButtonImg(button, VCP_VK_BUTTON_STATE_NORMAL, normalBgImg, normalFgImg);
    if ((bgImg.getResId() == normalBgImg.getResId()) && (fgImg.getResId() == normalFgImg.getResId()))
    {
        m_hiliteFrame->setOpacity(0);
    }
    else
    {
        m_hiliteFrame->setOpacity(1);
    }
}


void VcpVK::setPopupHintFrame(const VcpVKBtn *button)
{
    VFX_ASSERT(button != NULL);

    VfxImageSrc bgImg;
    VfxImageSrc fgImg;

    getButtonImg(button, VCP_VK_BUTTON_STATE_POPUP, bgImg, fgImg);

    m_popupHintFrame->setBackgroundImg(bgImg);
    m_popupHintFrame->setForegroundImg(fgImg);

    // get the size of popup hint
    VfxRect rect;
    m_adaptor.getButtonPopupSize(button->index, &(rect.size.width), &(rect.size.height));
    if (rect.size.width < VCP_VK_POPUP_BUTTON_MIN_WIDTH)
    {
        rect.size.width = VCP_VK_POPUP_BUTTON_MIN_WIDTH;
    }
    // the height of popup hint is same as the height of image, because of the image that cannot be stretched
    rect.size.height = bgImg.getSize().height;

    // get the position of popup hint
    rect.origin.x = button->rect.origin.x - ((rect.size.width - button->rect.size.width) / 2);
    if (rect.origin.x < 0)
    {
        rect.origin.x = 0;
    }
    if ((rect.origin.x + rect.size.width) > getSize().width)
    {
        rect.origin.x = getSize().width - rect.size.width;
    }
    rect.origin.y = button->rect.origin.y - VCP_VK_POPUP_GAP - rect.size.height;

    m_popupHintFrame->setRect(convertRectTo(rect, VFX_OBJ_GET_INSTANCE(VfxTopLevel)));
}


VfxBool VcpVK::checkPopupExist(const VcpVKBtn *button)
{
    return m_adaptor.checkButtonPopupExist(button->index);
}


VfxBool VcpVK::checklongtapExist(const VcpVKBtn *button)
{
    // check whether the popup is in the special case of XT9
#if defined __MMI_XT9__
    if ((mmi_imm_is_current_mode_smart()) && (mmi_imm_get_curr_input_mode() != IMM_INPUT_MODE_SM_PINYIN))
    {
        return VFX_FALSE;
    }
#endif

    // check whether the popup is multi popup
    if ((m_multiPopupCbObj.isValid() == VFX_TRUE) && (m_multiPopupCbFunc != NULL))
    {
        VfxU32 noUse;
        if ((m_multiPopupCbObj.get()->*m_multiPopupCbFunc)(m_adaptor.getButtonContent(button->index), &noUse) == VFX_TRUE)
        {
            return VFX_FALSE;
        }
    }

    return m_adaptor.checkButtonLongtapExist(button->index);
}


void VcpVK::longtapHintMoveHandler(VfxObject *sender, VcpVKBtnTypeEnum type, VfxU32 content)
{
    m_signalButtonMove.postEmit(this, type, content);
}


void VcpVK::longtapHintUpHandler(VfxObject *sender, VcpVKBtnTypeEnum type, VfxU32 content)
{
    m_signalButtonUp.postEmit(this, type, content);
}


void VcpVK::longtapHintAbortHandler(VfxObject *sender, VcpVKBtnTypeEnum type, VfxU32 content)
{
    m_signalButtonAbort.postEmit(this, type, content);
}


#endif

/* common part */


void VcpVK::setAllowedCharButtons(const VfxWString &allowedButtons)
{
    m_disabledAllowedCharBtns.isDisabled = VFX_FALSE;
    m_disabledAllowedCharBtns.string = allowedButtons;

    // set the buttons
    VcpVKBtn *currButton = m_buttonList;
    VfxBool isDirty = VFX_FALSE;

    while (currButton != NULL)
    {
        VfxU32 content = m_adaptor.getButtonContent(currButton->index);
        if (checkButtonIsAllowed(content))
        {
            if (!currButton->isAllowed)
            {
                isDirty = VFX_TRUE;
            }

            currButton->isAllowed = VFX_TRUE;
        }
        else
        {
            if (currButton->isAllowed)
            {
                isDirty = VFX_TRUE;
            }

            currButton->isAllowed = VFX_FALSE;
        }

        currButton = currButton->next;
    }

    if (isDirty)
    {
        invalidate();
    }
}


void VcpVK::setDisabledCharButtons(const VfxWString &disabledButtons)
{
    m_disabledAllowedCharBtns.isDisabled = VFX_TRUE;
    m_disabledAllowedCharBtns.string = disabledButtons;

    // set the buttons
    VcpVKBtn *currButton = m_buttonList;
    VfxBool isDirty = VFX_FALSE;

    while (currButton != NULL)
    {
        VfxU32 content = m_adaptor.getButtonContent(currButton->index);
        if (checkButtonIsAllowed(content))
        {
            if (!currButton->isAllowed)
            {
                isDirty = VFX_TRUE;
            }

            currButton->isAllowed = VFX_TRUE;
        }
        else
        {
            if (currButton->isAllowed)
            {
                isDirty = VFX_TRUE;
            }

            currButton->isAllowed = VFX_FALSE;
        }

        currButton = currButton->next;
    }

    if (isDirty)
    {
        invalidate();
    }
}


void VcpVK::resetCharButtons()
{
    setDisabledCharButtons(VFX_WSTR(""));

    // set the buttons
    VcpVKBtn *currButton = m_buttonList;
    VfxBool isDirty = VFX_FALSE;

    while (currButton != NULL)
    {
        VfxU32 content = m_adaptor.getButtonContent(currButton->index);
        if (checkButtonIsAllowed(content))
        {
            if (!currButton->isAllowed)
            {
                isDirty = VFX_TRUE;
            }

            currButton->isAllowed = VFX_TRUE;
        }
        else
        {
            if (currButton->isAllowed)
            {
                isDirty = VFX_TRUE;
            }

            currButton->isAllowed = VFX_FALSE;
        }

        currButton = currButton->next;
    }

    if (isDirty)
    {
        invalidate();
    }
}


void VcpVK::setDisabledFuncButtons(const VcpVKFuncBtnEnum *disabledButtons)
{
    VfxS32 i = 0;
    while ((disabledButtons[i] != GUI_VKBD_PEN_NONE) && (i < VCP_VK_MAX_DISABLED_FUNC_BUTTON))
    {
        m_disabledFuncBtn[i] = disabledButtons[i];
        i++;
    }
    m_disabledFuncBtn[i] = GUI_VKBD_PEN_NONE;

    // set the buttons
    VcpVKBtn *currButton = m_buttonList;
    VfxBool isDirty = VFX_FALSE;

    while (currButton != NULL)
    {
        VfxU32 content = m_adaptor.getButtonContent(currButton->index);
        if (checkButtonIsAllowed(content))
        {
            if (!currButton->isAllowed)
            {
                isDirty = VFX_TRUE;
            }

            currButton->isAllowed = VFX_TRUE;
        }
        else
        {
            if (currButton->isAllowed)
            {
                isDirty = VFX_TRUE;
            }

            currButton->isAllowed = VFX_FALSE;
        }

        currButton = currButton->next;
    }

    if (isDirty)
    {
//for performance inmprovement
//Need to invalidate MAUI_03210753
//#if  !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)

        invalidate();
//#endif
    }
}


void VcpVK::resetFuncButtons()
{
    m_disabledFuncBtn[0] = GUI_VKBD_PEN_NONE;

    // set the buttons
    VcpVKBtn *currButton = m_buttonList;
    VfxBool isDirty = VFX_FALSE;

    while (currButton != NULL)
    {
        VfxU32 content = m_adaptor.getButtonContent(currButton->index);
        if (checkButtonIsAllowed(content))
        {
            if (!currButton->isAllowed)
            {
                isDirty = VFX_TRUE;
            }

            currButton->isAllowed = VFX_TRUE;
        }
        else
        {
            if (currButton->isAllowed)
            {
                isDirty = VFX_TRUE;
            }

            currButton->isAllowed = VFX_FALSE;
        }

        currButton = currButton->next;
    }

    if (isDirty)
    {
        invalidate();
    }
}
VfxBool VcpVK::checkButtonIsAllowed(VfxU32 content)
{
    if (content > VCP_VK_CONTENT_CHARACTER_MAX)
    {
        // the content represents function button
		/*Button dont have any significant input */
		if((gui_virtual_keyboard_pen_enum)content == GUI_VKBD_PEN_NONE)
		{
			return VFX_FALSE;
		}
        VfxS32 i = 0;
        while (m_disabledFuncBtn[i] != GUI_VKBD_PEN_NONE)
        {
            if ((VfxU32)(m_disabledFuncBtn[i]) == content)
            {
                return VFX_FALSE;
            }
            i++;
        }
        return VFX_TRUE;
    }
    else
    {
        // the content represents character button
#if defined(__MMI_INDIC_ALG__) 
        VfxU16 temp_charactor = (VfxU16)content;
        if (!ire_vk_get_grey() &&
            IRE_INDIC_LANGUAGE_RANGE(temp_charactor) &&
            ire_IsValidInput(&temp_charactor, 2) == MMI_FALSE)
        {
            return VFX_FALSE;
        }
#endif

        if (m_disabledAllowedCharBtns.isDisabled)
        {
            // the buttons is disabled button
            VfxU32 len = m_disabledAllowedCharBtns.string.getLength();
            for (VfxU32 i = 0; i < len; i++)
            {
                VfxWChar ch = m_disabledAllowedCharBtns.string[i];

                if ((VfxWChar)(content) == ch)
                {
                    return VFX_FALSE;
                }
            }
            return VFX_TRUE;
        }
        else
        {
            // the buttons is allowed button
            VfxU32 len = m_disabledAllowedCharBtns.string.getLength();
            for (VfxU32 i = 0; i < len; i++)
            {
                VfxWChar ch = m_disabledAllowedCharBtns.string[i];
                if ((ch == (VfxWChar)L'-') &&
                    (i > 0) &&
                    (m_disabledAllowedCharBtns.string[i + 1] != (VfxWChar)L'\0'))
                {
                    if (((VfxWChar)(content) > m_disabledAllowedCharBtns.string[i - 1]) &&
                        ((VfxWChar)(content) < m_disabledAllowedCharBtns.string[i + 1]))
                    {
                        return VFX_TRUE;
                    }
                }
                else if ((ch == (VfxWChar)L'\\') &&
                    (m_disabledAllowedCharBtns.string[i + 1] != (VfxWChar)L'\0'))
                {
                    if ((VfxWChar)(content) == m_disabledAllowedCharBtns.string[++i])
                    {
                        return VFX_TRUE;
                    }
                }
                else if ((VfxWChar)(content) == ch)
                {
                    return VFX_TRUE;
                }
            }
            return VFX_FALSE;
        }
    }
}
#endif
