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
 *  vcp_title_bar.h
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

#ifndef __VCP_TITLE_BAR_H__
#define __VCP_TITLE_BAR_H__
 
 /***************************************************************************** 
  * Include
  *****************************************************************************/
#include "vcp_pluto_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"

 
 /***************************************************************************** 
  * Define
  *****************************************************************************/
 
 /***************************************************************************** 
  * Class VcpPlutoTitleBar
  *****************************************************************************/
 
/*
* The description of this class
*
* EXAMPLE
* <code>
*   VcpPlutoTitleBar *title_bar;
*   VFX_OBJ_CREATE(title_bar, VcpPlutoTitleBar, this);
* </code>
*/
class VcpPlutoTitleBar : public VcpPlutoControl
{
    VFX_DECLARE_CLASS(VcpPlutoTitleBar);

// Constructor / Destructor
public:	
    // <group DOM_Title_VcpTitleBar_Constructor/Destructor>
    // Default constructor.
    VcpPlutoTitleBar();
 
     
// Method
public:      
    // <group DOM_Title_VcpTitleBar_Method>
    //Change the text of title.
    void changeText(const VfxWString &text);
    
    // <group DOM_Title_VcpTitleBar_Method>
    // Change the text of title with not update for performance
    void changeTextWithNotUpdate(const VfxWString &text);
 
    // <group DOM_Title_VcpTitleBar_Method>
    //Change the left icon of title.
    void changeLeftIcon(VfxU16 imageId);
 
    // <group DOM_Title_VcpTitleBar_Method>
    //Change the right icon of title.
    void changeRightIcon(VfxU16 imageId);
 
    // <group DOM_Title_VcpTitleBar_Method>
    //Enable integrate title or not.
    void enableIntegrateTitle(VfxBool enable);

    // <group DOM_Title_VcpTitleBar_Method>
    //Enable shortcut show or not.
    void enableShortcutDisplay(VfxBool enable);
 
    // <group DOM_Title_VcpTitleBar_Method>
    //Start title scrolling, If title's text exceed the display range, the text will scrolling.
    void startScrolling(void);

    // <group DOM_Title_VcpTitleBar_Method>
    //Stop title scrolling
    void stopScrolling(void);
 
// Override 
protected:
 
    // <group DOM_Title_VcpTitleBar_Override>
    // Create the pluto control
    virtual void onPlutoCreate();
 
    // <group DOM_Title_VcpTitleBar_Override>
    // Close the pluto control
    virtual void onPlutoClose();
 
    // <group DOM_Title_VcpTitleBar_Override>
    // Draw the pluto control
    virtual void onPlutoDraw();
 
    // <group DOM_Title_VcpTitleBar_Override>
    // Use double buffer for title
    virtual VfxBool onPlutoNeedDoubleBuffer() {return VFX_TRUE;}
    
 		
    // <group DOM_Title_VcpTitleBar_Override>
    // Get the preferred size of pluto control
    virtual VfxSize onPlutoGetPreferredSize();

// Implementation
private:

    // <group DOM_Title_VcpTitleBar_Implementation>
    // When change the bounds of title object, this function will be call to move and resize title
    void onBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds);
};
 
 
#endif /* __VCP_TITLE_BAR_H__ */

