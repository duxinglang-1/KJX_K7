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
 *  vfx_page_bar.h
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_PAGE_BAR_H__
#define __VFX_PAGE_BAR_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
// by RHR //#include "vfx_uc_include.h"

#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_weak_ptr.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

// Indicate the location of page bar
enum VfxPageBarLocationEnum
{
    VFX_PAGE_BAR_LOCATION_TOP,      // Top position, like title bar
    VFX_PAGE_BAR_LOCATION_BOTTOM,   // Bottom position, like tool bar

    VFX_PAGE_BAR_LOCATION_END_OF_ENUM
};

/***************************************************************************** 
 * Class VfxPageBar
 *****************************************************************************/

class VfxPageTransition;
class VfxPage;
class VfxMainScr;
class VfxApp;

/*
 * VfxPageBar. This is the base class of page bar. Classes inherit this class 
 * can be attached to a VfxPage, via its VfxPage::setBar API
 */
class VfxPageBar : public VfxControl
{
    VFX_DECLARE_CLASS(VfxPageBar);

// Declaration
public:

// Constructor / Destructor
public:
    // Constructor
    VfxPageBar();
    
    // Destructor
    virtual ~VfxPageBar();

/* DOM-NOT_FOR_SDK-BEGIN */
// Override
public:
    virtual void setPos(const VfxPoint &value);
    virtual void setPosZ(VfxFloat value);
    virtual void setBounds(const VfxRect &value);
    virtual void setOpacity(VfxFloat value);
    virtual void setTransform(const VfxTransform &value);
    virtual void setHidden(VfxBool value);
    virtual VfxBool processFocusKey(VfxKeyEvent &event);
protected:    
    void onParentFrameChanged(VfxFrame *origParentFrame);
    virtual VfxBool onPreviewPenInput(VfxPenEvent &event);
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual void onObjectNotify(VfxId eventId, void *userData);

public:
    void setPos(VfxS32 x, VfxS32 y)    
    {
        setPos(VfxPoint(x, y));
    }
/* DOM-NOT_FOR_SDK-END */

// Method
public:
    // Setup a new page transition, it is used while pushing/popuping
    void        setTransition(
        VfxPageTransition *transition   // [IN] Page transition object
    );

    // Turn on/off shadow support
    void        setEnableShadow(
        VfxBool value                   // [IN] enable shadow or not.
    );

// Method
public:
    // Query VfxApp pointer
    VfxApp      *getApp() const;

    // Query VfxMainScr pointer
    VfxMainScr  *getMainScr() const;

    // Query VfxPage pointer
    VfxPage     *getPage() const;

    // Query location
    VfxPageBarLocationEnum getLoc() const;

    // Call this interface when user press Back button
    void        doBackFunc();

    // Set a shadow frame
    VfxFrame    *setShadowFrame(VfxFrame*);

/* DOM-NOT_FOR_SDK-BEGIN */
// Method
public:
    // Start a transition.
    // This API is internal used, only called by VfxPage. 
    VfxBool     startTransition(
        VfxBool in = VFX_TRUE,          // [IN] transit in or out
        VfxS32 direction = 0,           // [IN] direction, can be 1, 0, -1
        VfxBool noAnimation = VFX_FALSE,// [IN] turn off animation effect
        VfxBool autoClose = VFX_FALSE   // [IN] close page after finishing transit out
    );

    // Stop a transition.
    // This API is internal used, only called by VfxPage. 
    VfxBool     stopTransition();

    // Re-start the transition according to previous setting.
    // It only work during transition and will return VFX_FALSE if not in transition.
    // This API is internal used, only called by VfxPage. 
    VfxBool     restartTransition();

    // turn on/off translucent support.
    // This API is internal used, only called by VfxPage. 
    void setTranslucent(
        VfxBool translucent // [IN] on or off
    ) { onSetTranslucent(translucent); }

    // set rotate direction.
    // This API is internal used, only called by VfxPage. 
    void setRotate(
        VfxScrRotateTypeEnum rotate // [IN] new direction
    ) { onSetRotate(rotate); }
/* DOM-NOT_FOR_SDK-END */

// Overridable    
protected:
    // Notify when translucent flag is changed
    virtual void onSetTranslucent(
        VfxBool translucent // [IN] on or off
    ) { VFX_UNUSED(translucent); }

    // Notify when rotate direction is changed
    virtual void onSetRotate(
        VfxScrRotateTypeEnum rotate // [IN] new direction
    ) { VFX_UNUSED(rotate); }

    // Notify when transition end
    virtual void onTransitionStop(
        VfxBool in,             // [IN] transit in or out
        VfxS32 direction       // [IN] direction, can be 1, 0, -1
    ) { 
        VFX_UNUSED(in); 
        VFX_UNUSED(direction); 
    }

/* DOM-NOT_FOR_SDK-BEGIN */
// Variable
private:
    VfxWeakPtr<VfxPageTransition> m_transition;
    VfxPageBarLocationEnum m_loc;
    VfxWeakPtr<VfxFrame> m_shadow;
    VfxBool m_enableShadow;

// Implementation
private:
    void setLoc(VfxPageBarLocationEnum newLoc);
    void processTransitionStop(VfxBool in, VfxS32 direction);

    friend class VfxPage;
/* DOM-NOT_FOR_SDK-END */
};

#endif /* __VFX_PAGE_BAR_H__ */
