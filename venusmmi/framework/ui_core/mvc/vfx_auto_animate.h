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
 *  vfx_auto_animate.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_AUTO_ANIMATE_H__
#define __VFX_AUTO_ANIMATE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_cpp_base.h"
#include "vfx_datatype.h"

#include "vfx_frame.h"
// For vrt_object_property_id_enum, etc.
#include "vrt_datatype.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

// Defines context stack size of auto animation.
#define VFX_AUTO_ANIMATE_STACK_SIZE      32


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

class VfxFrame;


/***************************************************************************** 
 * Class VfxAutoAnimate
 *****************************************************************************/



// VfxAutoAnimate is a helper class which helps you to write animation more easily.
//
// NOTE: Default interpolation of auto animation is linear.
class VfxAutoAnimate
{
// Method
public:
    // Whether the current auto-animation is disabled.
    static VfxBool getDisable();

    // Disables or enables current auto-animation. 
    static void setDisable(
        VfxBool value   // [IN] Sets VFX_TRUE to disable auto-animation. Otherwise, VFX_FALSE.
    );

    // Returns the current duration setting of auto-animation.
    static VfxMsec getDuration();

    // Sets the current duration setting of auto-animation.
    static void setDuration(
        VfxMsec value   // [IN] Duration time in millisecond.
    );

    // Sets the timing function of auto-animation.
    static void setTimingFunc(
        VfxTimingFuncIdEnum value   // [IN] Timing function ID.
    );

    // Sets the custom timing function of auto-animation.
    static void setCustomTimingFunc(
        VfxTimelineTimingFuncPtr callback,  // [IN] Callback function for custom timing.
        const void *userData,               // [IN] User data for timing functions.
        VfxU32 userDataSize                 // [IN] Size of user data.
    );

    // Saves current auto-animation context into stack and starts a new auto-animation context.
    static void begin();
    // Frees the current auto-animation context and restores to previous one.
    static void commit();

    // Start initial-time auto-animation mode
    static void initAnimateBegin();
    // End initial-time auto-animation mode
    static void initAnimateEnd();

// Framework method
public: 
    // Internal used.
    static void setAnimatableProperty(
        VfxAnimatable *animatable,
        vrt_object_property_id_enum property_id,
        const void *fromValue, 
        const void *toValue, 
        VfxU32 valueSize);

// Implementation
private:
    // Auto-animation stack
    struct StackContext
    {
        VfxBool isDisabled;
        VfxMsec durTime;
        
        vrt_timeline_timing_callback_struct *customTimingCallback;
    };

    static StackContext s_contextStack[];
    static VfxU32 s_contextStackTop;
    
    static StackContext s_currentContext;
    static VfxBool s_initAnimate;
};

#endif /* __VFX_AUTO_ANIMATE_H__ */

