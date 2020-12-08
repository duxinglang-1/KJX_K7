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
 *  vcp_pluto_control.h
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  Adaptor to Pluto UI component 
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
#ifndef __VCP_PLUTO_CONTROL_H__
#define __VCP_PLUTO_CONTROL_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "mmi_features.h"

// For VfxControl
#include "vfx_control.h"

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_draw_context.h"
#include "vfx_image_src.h"
#include "vfx_frame.h"
#include "vfx_string.h"
#include "vfx_font_desc.h"


/***************************************************************************** 
 * Class VcpPlutoControl
 *****************************************************************************/

/*
 * VcpPlutoControl is a virtual class that helps encapsulate/reuse Pluto UI component in Venus UI.
 *
 * EXAMPLE
 * <code>
 *  class VcpNewPlutoComponent : public VcpPlutoControl 
 *  {
 *  // override
 *  protected:
 *       virtual void onPlutoCreate() { ...}
 *       virtual void onPlutoClose() { ... }
 *       virtual void onPlutoDraw() { ... }
 *  }
 * </code>
 */
class VcpPlutoControl : public VfxControl
{
    VFX_DECLARE_CLASS(VcpPlutoControl);

// Typedef
public:
    enum 
    {
        // Maximum recursive call depth of beginUseGdiLayer()/endUseGdiLayer()
        MAX_USE_GDI_LAYER_DEPTH = 5
    };

// Constructor/Destructor
public:
    VcpPlutoControl();
  
// Overridable
protected:

    /* 
     * Overridable method to create (initialize) a Pluto UI component.
     * Note: this method should not be called directly in child class - use createPlutoComponent() instead.
     */
    virtual void onPlutoCreate() = 0;
    
    /* 
     * Overridable method to close (deinitialize) a Pluto UI component.
     * Note: this method should not be called directly in child class - use closePlutoComponent() instead.    
     */
    virtual void onPlutoClose() = 0;

    /* 
     * Overridable method to draw a Pluto UI component.
     * Note: this method should not be called directly in child class - use drawPlutoComponent() instead.
     */
    virtual void onPlutoDraw() = 0;

    /*
     * Overridable method to resize a Pluto UI component according to getCurrentSize().
     * Note: this method should not be called directly in child class - use resizePlutoComponent() instead.
     */
    virtual void onPlutoResize() {}

    // The method has been phase out.
    virtual VfxBool onPlutoNeedDoubleBuffer() {return VFX_FALSE;}

    /* 
     * Overridable method to query the preferred size of a Pluto UI component.
     *
     * RETURNS: VFX_SIZE_ZERO if no preferred size; otherwise, the returned size is used as the initial bounds size.
     */
    virtual VfxSize onPlutoGetPreferredSize() {return VFX_SIZE_ZERO;}

    /*
     * Overridable method to query if the Pluto UI component requires alpha channel in layer, which costs more RAM and becomes slower.
     * But it is mandatory when we want to keep per-pixel alpha information in PNG or vector fonts.
     * Note: If the Pluto UI component uses an opaque background image, even if it uses PNG or vector font, 
     * it can still return VFX_FALSE here.
     *
     * RETURNS: VFX_TRUE for alpha channel (4 bytes per pixel); otherwise, disable it (2 bytes per pixel).
     */
    virtual VfxBool onPlutoNeedAlphaChannel() {return VFX_TRUE;}

    /* 
     * Overridable method to decide whether this UI component processes pen events by itself. 
     * When it returns VFX_TRUE, GDI lock will be aquired during pen events to communicate with Pluto UI component, 
     * which may slow down the animation a bit.
     *
     * RETURNS: VFX_TRUE if onPlutoPenHandler() is also overloaded, and vice versa.
     */
    virtual VfxBool onPlutoAcceptPenEvents()  {return VFX_FALSE;}

    /*
     * Overridable method to handle pen events in pluto UI way. 
     * Note: 
     *   1. This method should not be called directly in child class.
     *   2. For technical reasons, we do not route key events to Pluto UI component. 
     *       So there is no such on_pluto_key_handler() function.
     *       To handle key, please override VfxControl::onKeyInput() in standard way.
     *
     * RETURNS: VFX_TRUE if pen event is accepted, and vice versa.
     */
    virtual VfxBool onPlutoPenHandler(
                        VfxS32 plutoPenEvent,       // value for mmi_pen_event_type_enum 
                        VfxS16 x,                   // x position
                        VfxS16 y                    // y position
    ) 
    {VFX_UNUSED(plutoPenEvent); VFX_UNUSED(x); VFX_UNUSED(y); return VFX_FALSE;}

    /*
     * Overridable method to handle stroke events in pluto UI way. 
     *
     * RETURNS: VFX_TRUE if stroke event is accepted.
     */
    virtual VfxBool onPlutoStrokeHandler(
                        VfxS32 plutoStrokeEvent,    // value for mmi_pen_stroke_type_enum
                        VfxS16 x,                   // x position
                        VfxS16 y                    // y position
    ) 
    {VFX_UNUSED(plutoStrokeEvent); VFX_UNUSED(x); VFX_UNUSED(y); return VFX_FALSE;}


//Method
public:
    // Force to redraw Pluto component (drawPlutoComponent()) 
    void setNeedRedrawPluto();

    // The method has been phase out, please use invalidate()
    void setNeedSwapDoubleBuffer();

// Method
protected:
    // Utility function used to invalidate (refresh) the display from Pluto component.
    // This method can be called from C files.
    static void updateScreenForPluto(
        void *object    // the VcpPlutoControl pointer to be refreshed
    );

    static void updateScreenForPlutoNeedRedraw(
        void *object    // the VcpPlutoControl pointer to be refreshed
    );

    // Create Pluto component
    void createPlutoComponent();
    // Close Pluto component    
    void closePlutoComponent();
    // Draw Pluto component    
    void drawPlutoComponent();
    // Resize Pluto component        
    void resizePlutoComponent();

    // Get the current bounds size
    VfxSize getCurrentSize() const 
    {
        return getBounds().size;
    }
    
    /*
     * Get the GDI layer handle (typecasted to 'gdi_handle') for Pluto UI Component.
     *
     * Sometimes Pluto UI component will redraw itself inside PlutoMMI directly. 
     * For example, it may start a Pluto timer to animate.
     * And it must use gdi_layer_push_and_set_active()/gdi_layer_pop_and_restore_active() 
     * with this layer handle before drawing the Pluto component.
     *
     * Note: Inside VcpPlutoControl API such as onPlutoCreate(), onPlutoDraw(), etc
     * the active layer is already automatically set as this layer.
     */
    VfxU32 getLayerHandle() const 
    {
        return m_layerForPluto;
    }

    // Fill the target GDI layer with transparent color (ARGB(0, 0, 0, 0))
    void clearLayerBackground();

// Override
protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent & event);    
    virtual void onDraw(VfxDrawContext &dc);
    virtual void processCreateHandle();
    virtual void processReleaseHandle();

// Variable
private:
    // Dirty flag to reduce redundant redrawing of Pluto component 
    VfxBool m_isNeedRedrawPluto;

    // GDI layer handle used in Pluto UI component.
    VfxU32 m_layerForPluto;    
    // GDI layer frame buffer for m_layerForPluto.
    VfxU8 *m_gdiLayerBuffer;
    // Buffer size of m_gdiLayerBuffer
    VfxU32 m_layerBufferSize;
    
    // Internal flag used in beginUseGdiLayer()/endUseGdiLayer()
    VfxS32 m_gdiCurrLockCnt[MAX_USE_GDI_LAYER_DEPTH];
    // Index of m_gdiCurrLockCnt[]
    VfxS32 m_gdiCurrLockIndex;

// Method
private:
    // Utility method before using (drawing) m_layerForPluto
    void beginUseGdiLayer();
    // Utility method before using (drawing) m_layerForPluto    
    void endUseGdiLayer();

    void initImageBufferByGdiLayer(VfxImageBuffer &imageBuf, VfxU32 handle);

    void freeGdiLayer();
    void createGdiLayer();

// Slot
private: 
    // Property value changed callback 
    void onPropertyBoundsChanged(VfxFrame *source, const VfxRect &oldBounds);
};

#if 0  //phase out
/* under construction !*/
#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* !defined(__MMI_VUI_COSMOS_CP_SLIM__) */
#endif
#endif /* __VCP_PLUTO_CONTROL_H__ */

