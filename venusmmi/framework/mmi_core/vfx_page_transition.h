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
 *  vfx_page_transition.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_PAGE_TRANSITION_H__
#define __VFX_PAGE_TRANSITION_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
// by RHR //#include "vfx_uc_include.h"

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_screen.h"
#include "vfx_control.h"
#include "vfx_signal.h"
#include "vfx_timer.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VfxPageTransition
 *****************************************************************************/

/*
 * VfxPageTransition
 */
class VfxPageTransition : public VfxObject
{
    VFX_DECLARE_CLASS(VfxPageTransition);

// Declaration
public:

// Constructor / Destructor
public:
    // Constructor
    VfxPageTransition();
    
// Override
protected:

// Method
public:
    // Prepare the transition
    void prepare(
        VfxBool in = VFX_TRUE,          // [IN] in or our
        VfxS32 direction = 0,           // [IN] direction, can be 1, 0, -1
        const VfxScreenRotateParam *param = NULL    // [IN] rotate information
    );

    // Start the transition
    VfxBool start(
        VfxControl *target,             // [IN] the control that applied the transition
        VfxBool noAnimation = VFX_FALSE,// [IN] turn off animation effect
        VfxBool closeTarget = VFX_FALSE // [IN] close control after finishing transit out
    );

    // Stop the transition
    VfxBool stop();

    // Restart the transition
    VfxBool restart();

    // Query if still in transition animation
    VfxBool inAnimation() { return (m_transFlags & FLAGS_IN_ANIMATION) ? VFX_TRUE : VFX_FALSE; }

    // Query in or not
    VfxBool getIn() { return (m_transFlags & FLAGS_IS_PHASE_IN) ? VFX_TRUE : VFX_FALSE; }

    // Query direction
    VfxS32 getDir() { return m_direction; }

// Variable
public:
    // Signal that emit when transition is finished.
    VfxSignal2<VfxBool, VfxS32> m_signalStopped;

// Method
protected:
    // Query that target control applying the transition
    VfxControl *getTarget() { return m_ctrl; }

// Overridable    
protected:
    // Prepare the transition
    virtual void customPrepare(
        VfxBool in,                         // [IN] in or our
        VfxS32 direction,                   // [IN] direction, can be 1, 0, -1
        const VfxScreenRotateParam *param   // [IN] rotate information
    );

    // Start the transition.
    // Derived class can override this interface to do customized transition effect.
    // Base class implement a default slide / swap effect.
    // Dont call it if you implement your own effect.
    virtual void customStart(
        VfxBool in,         // [IN] in or out
        VfxS32 direction,   // [IN] direction, can be 1, 0, -1
        VfxMsec duration    // [IN] duration
    );

    // Stop the transition.
    // Derived class can override this interface to do customized transition effect.
    // Base class implement a default slide / swap effect.
    // Dont call it if you implement your own effect.
    virtual void customStop(
        VfxBool in,         // [IN] in or out
        VfxS32 direction,   // [IN] direction, can be 1, 0, -1
        VfxMsec duration    // [IN] duration
    );
    
/* DOM-NOT_FOR_SDK-BEGIN */
    // The target is transitted out completely
    // Dont call it if you implement your own effect.
    virtual VfxBool customOuted(void);
/* DOM-NOT_FOR_SDK-END */

// Implemetation
private:
    enum
    {
        FLAGS_IS_PHASE_IN       = 1 << 0,    // If phase in
        FLAGS_IN_ANIMATION      = 1 << 1,    // If in animation
        FLAGS_CLOSE_TARGET      = 1 << 2,    // If need to close target
        FLAGS_OLD_HITTEST       = 1 << 3,    // If need to receive pen event

        FLAGS_MAX
    };

// Variable
private:
    VfxU16      m_transFlags;
    //VfxBool     m_phaseIn;
    //VfxBool     m_inAnimation;
    //VfxBool     m_closeTarget;
    VfxS8       m_direction;
    VfxControl  *m_ctrl;
    VfxTimer    *m_timer;

// Implementation
private:
    void onStop(VfxTimer *timer);
    friend class VpiPageTransitionProxy;
};

/* DOM-NOT_FOR_SDK-BEGIN */
/*
 * VfxPageSlideTransition
 */
class VfxPageSlideTransition : public VfxPageTransition
{
    VFX_DECLARE_CLASS(VfxPageSlideTransition);

// Constructor / Destructor
public:
    // Constructor
    VfxPageSlideTransition() : m_customWidth(0), m_tl(NULL) {};

// Override
protected:
    virtual void customPrepare(VfxBool in, VfxS32 direction, const VfxScreenRotateParam *param);
    virtual void customStart(VfxBool in, VfxS32 direction, VfxMsec duration);
    virtual void customStop(VfxBool in, VfxS32 direction, VfxMsec duration);

private:
    VfxS32 m_customWidth;
    VfxS32Timeline *m_tl;
};

/*
 * VfxPageCosmosTransition
 */
class VfxPageCosmosTransition : public VfxPageTransition
{
    VFX_DECLARE_CLASS(VfxPageCosmosTransition);

// Constructor / Destructor
public:
    // Constructor
    VfxPageCosmosTransition() : m_customWidth(0) {};

// Override
protected:
    virtual void customPrepare(VfxBool in, VfxS32 direction, const VfxScreenRotateParam *param);
    virtual void customStart(VfxBool in, VfxS32 direction, VfxMsec duration);
    virtual void customStop(VfxBool in, VfxS32 direction, VfxMsec duration);

private:
    VfxS32 m_customWidth;
};
/* DOM-NOT_FOR_SDK-END */

#endif /* __VFX_PAGE_TRANSITION_H__ */
