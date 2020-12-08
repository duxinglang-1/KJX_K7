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
 *  vcp_progress_indicator.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Progress component header
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
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_PROGRESS_INDICATOR_H__
#define __VCP_PROGRESS_INDICATOR_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"

#if defined(__MMI_VUI_COSMOS_CP__) 

/***************************************************************************** 
 * Define
 *****************************************************************************/

// <group DOM_ProgressIndicator_Macro&Enum_Macro>
// Timer duration for progress increas animation (in ms). 
#define VCP_PROGRESS_INDICATOR_PATTERN_MOTION_TIME   (250)

#ifdef __MMI_MAINLCD_480X800__
    #if defined(__MMI_VUI_COSMOS_CP__)
        #define VCP_PROGRESS_INDICATOR_HEIGHT                (10)
        #define VCP_PROGRESS_INDICATOR_WIDTH_MAX             (810)
        #define VCP_PROGRESS_INDICATOR_FG_OFFSET             (2)
        #define VCP_PROGRESS_INDICATOR_PATTERN_WIDTH         (32)

    #else
        #define VCP_PROGRESS_INDICATOR_HEIGHT                (14)
        #define VCP_PROGRESS_INDICATOR_WIDTH_MAX             (810)
        #define VCP_PROGRESS_INDICATOR_FG_OFFSET             (0)
        #define VCP_PROGRESS_INDICATOR_PATTERN_WIDTH         (32)

    #endif
#elif defined(__MMI_MAINLCD_320X480__)
    #if defined(__MMI_VUI_COSMOS_CP__)
        #define VCP_PROGRESS_INDICATOR_HEIGHT                (5)
        #define VCP_PROGRESS_INDICATOR_WIDTH_MAX             (485)
        #define VCP_PROGRESS_INDICATOR_FG_OFFSET             (2)
        #define VCP_PROGRESS_INDICATOR_PATTERN_WIDTH         (15)

    #else
        #define VCP_PROGRESS_INDICATOR_HEIGHT                (9)
        #define VCP_PROGRESS_INDICATOR_WIDTH_MAX             (485)
        #define VCP_PROGRESS_INDICATOR_FG_OFFSET             (0)
        #define VCP_PROGRESS_INDICATOR_PATTERN_WIDTH         (15)

    #endif
#elif defined(__MMI_MAINLCD_240X400__)
    #if defined(__MMI_VUI_COSMOS_CP__)
        #define VCP_PROGRESS_INDICATOR_HEIGHT                (5)
        #define VCP_PROGRESS_INDICATOR_WIDTH_MAX             (405)
        #define VCP_PROGRESS_INDICATOR_FG_OFFSET             (2)
        #define VCP_PROGRESS_INDICATOR_PATTERN_WIDTH         (15)

    #else
        #define VCP_PROGRESS_INDICATOR_HEIGHT                (9)
        #define VCP_PROGRESS_INDICATOR_WIDTH_MAX             (413)
        #define VCP_PROGRESS_INDICATOR_FG_OFFSET             (0)
        #define VCP_PROGRESS_INDICATOR_PATTERN_WIDTH         (13)

    #endif
#elif defined(__MMI_MAINLCD_240X320__)
    #if defined(__MMI_VUI_COSMOS_CP__)
        #define VCP_PROGRESS_INDICATOR_HEIGHT                (5)
        #define VCP_PROGRESS_INDICATOR_WIDTH_MAX             (325)
        #define VCP_PROGRESS_INDICATOR_FG_OFFSET             (2)
        #define VCP_PROGRESS_INDICATOR_PATTERN_WIDTH         (15)

    #else
        #define VCP_PROGRESS_INDICATOR_HEIGHT                (9)
        #define VCP_PROGRESS_INDICATOR_WIDTH_MAX             (325)
        #define VCP_PROGRESS_INDICATOR_FG_OFFSET             (0)
        #define VCP_PROGRESS_INDICATOR_PATTERN_WIDTH         (15)

    #endif
#else 
    #define VCP_PROGRESS_INDICATOR_HEIGHT                (5)
    #define VCP_PROGRESS_INDICATOR_WIDTH_MAX             (325)
    #define VCP_PROGRESS_INDICATOR_FG_OFFSET             (2)
    #define VCP_PROGRESS_INDICATOR_PATTERN_WIDTH         (15)
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Class VcpProgressIndicatorBase
 *  VcpProgressIndicatorBase - Base class for Progress indicator class 
 *  which takes care of the animation of the background pattern of the progress bar.
 *****************************************************************************/
class VcpProgressIndicatorBase : public VfxControl
{
    //VFX_DECLARE_CLASS(VcpProgressIndicatorBase);
    public:
        // <group DOM_ProgressIndicator_VcpProgressIndicatorBase_Constructor/Destructor>
        // Initialize block.
        VcpProgressIndicatorBase();

        // <group DOM_ProgressIndicator_VcpProgressIndicatorBase_Overridable>
        // Sets the width of the Indicator bar.
        virtual void setWidth(
            VfxU32 width              // [IN]  Indicator width 
        );

        // <group DOM_ProgressIndicator_VcpProgressIndicatorBase_Override>
        // Stops Progress bar internal frame animation.
        void pauseProgress();

        // <group DOM_ProgressIndicator_VcpProgressIndicatorBase_Override>
        // Starts Progress bar internal frame animation.
        void resumeProgress();

    protected:
        // <group DOM_ProgressIndicator_VcpProgressIndicatorBase_Override>
        // Initializing routine.
        virtual void onInit();

        // <group DOM_ProgressIndicator_VcpProgressIndicatorBase_Override>
        // Making sure, the height can not be altered.
        virtual void setBounds(const VfxRect &value) {}

    protected:
        // <group DOM_ProgressIndicator_VcpProgressIndicatorBase_Implementation>
        // The foreground image animation.
        VfxFrame *m_fgFrame;            

        // <group DOM_ProgressIndicator_VcpProgressIndicatorBase_Implementation>
        // The background image.
        VfxFrame *m_bgFrame;

        // <group DOM_ProgressIndicator_VcpProgressIndicatorBase_Implementation>
        // The animated image frame for progress bar.
        VfxImageFrame *m_barFrame;            

        // <group DOM_ProgressIndicator_VcpProgressIndicatorBase_Implementation>
        // The intenral frame animation timeline.
        VfxPointTimeline *m_frameAnimate;

        // <group DOM_ProgressIndicator_VcpProgressIndicatorBase_Implementation>
        // The animated image frame for progress bar.
        VfxBool m_isFrameAnimate;            
};


/*****************************************************************************
 * Class VcpProgressIndicator
 *  VcpProgressIndicator - will display a bar to show the progress of 
 *  an ongoing activity where progress can be measured.
 *****************************************************************************/
class VcpProgressIndicator : public VcpProgressIndicatorBase
{
    VFX_DECLARE_CLASS(VcpProgressIndicator);
    public:
        // <group DOM_ProgressIndicator_VcpProgressIndicator_Constructor/Destructor>
        // Initialize block
        VcpProgressIndicator();

        // <group DOM_ProgressIndicator_VcpProgressIndicator_Method>
        // Sets the max progress value.
        // RETURNS :
        // VFX_FALSE if the new progress value is greater than currently set progress value. 
        VfxBool setMaxProgressValue(
            VfxFloat max_progress_value              // [IN]  Max progress value
        );

        // <group DOM_ProgressIndicator_VcpProgressIndicator_Method>
        // Updates the current progress value.
        // RETURNS :
        // VFX_FALSE if the new progress value does not lie between the min and max progress value. 
        VfxBool setProgress(
            VfxFloat progress_value                 // [IN]  New progress value
        );

        // <group DOM_ProgressIndicator_VcpProgressIndicator_Method>
        // Get currently set maximum progress value.
        // RETURNS :
        // Max progress value.
        VfxFloat getMaxProgressValue() const {return m_maxProgressValue;}

        // <group DOM_ProgressIndicator_VcpProgressIndicator_Method>
        // Get current progress value.
        // RETURNS :
        // Current progress value.
        VfxFloat getProgress() const {return m_progressValue;}

        // <group DOM_ProgressIndicator_VcpProgressIndicator_Method>
        // Turns ON/OFF the progress update animation
        void setIsAnimate(
            VfxBool isAnim              // [IN]  Animation required while setting the progress
        );

        // <group DOM_ProgressIndicator_VcpProgressIndicator_Method>
        // Returns whether the progress indicator will animate when progress is increased. 
        // RETURNS :
        // Current progress animation state 
        VfxBool getIsAnimate() const {return m_isAnimate;}

        // <group DOM_ProgressIndicator_VcpProgressIndicator_Override>
        // Sets the width of Indicator bar
        virtual void setWidth(
            VfxU32 width                            // [IN]  Adjust indicator width 
        );

    // Override 
    protected:
        // <group DOM_ProgressIndicator_VcpProgressIndicator_Override>
        // Initializing routine.
        virtual void onInit();

    // Method
    private:
        // <group DOM_ProgressIndicator_VcpProgressIndicator_Implementation>
        void adjustProgress(VfxBool is_anim);

        // <group DOM_ProgressIndicator_VcpProgressIndicator_Implementation>
        void animationCompleted(VfxBaseTimeline *, VfxBool);

    private:
        // <group DOM_ProgressIndicator_VcpProgressIndicator_Implementation>
        // Current progress value.
        VfxFloat m_progressValue;       

        // <group DOM_ProgressIndicator_VcpProgressIndicator_Implementation>
        // Max progress value.
        VfxFloat m_maxProgressValue; 

        // <group DOM_ProgressIndicator_VcpProgressIndicator_Implementation>
        // Progress bar animation timer.
        VfxSizeTimeline *m_anime;        

        // <group DOM_ProgressIndicator_VcpProgressIndicator_Implementation>
        // Progress bar animation ON/OFF.
        VfxBool m_isAnimate;
};

#endif /* #if defined (__MMI_VUI_COSMOS_CP__)  */
#endif /* __VCP_PROGRESS_INDICATOR_H__ */

