/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_mini_stage.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the base class of the 3D mini stage widget.
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_MINI_STAGE_H
#define VAPP_WIDGET_MINI_STAGE_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_3D_V10__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"
#include "vapp_widget_3d.h"


/*****************************************************************************
 * 3D Mini Stage Widget Base Class
 *****************************************************************************/

/*
 * 3D Mini Stage Widget Base Class
 */
class VappWidgetMiniStage : public VappWidget3D
{
    VFX_DECLARE_CLASS(VappWidgetMiniStage);

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetMiniStage();

    // Default destructor
    virtual ~VappWidgetMiniStage();

// Override
protected:
    // Please refer to VappWidget3D.
    virtual void onRotateStart(
        VfxPenEvent &event
    );

    // Please refer to VappWidget3D.
    virtual void onRotate(
        VfxPenEvent &event
    );

    // Please refer to VappWidget3D.
    virtual void onRotateEnd(
        VfxPenEvent &event
    );

// Override
protected:
    //
    // The following 4 functions will be called by the rule:
    //
    //  (OnRotateX)+ [onSwipeUp | onSwipeDown | onSwipeToNearestView]
    //

    // This function is called when the user rotates the mini stage. A
    // specialization of the mini stage widget could implement this function to
    // rotate the 3D model along the x-axis.
    virtual void onRotateX(
        VfxFloat angle          // [IN] Rotation degree
    );

    // This function is called when the user swipes the mini stage up. A
    // specialization of the mini stage widget could implement this function to
    // rotate the 3D model upwards along the x-axis.
    virtual void onSwipeUp();

    // This function is called when the user swipes the mini stage down. A
    // specialization of the mini stage widget could implement this function to
    // rotate teh 3D model downwards along the x-axis.
    virtual void onSwipeDown();

    // This function is called when we need the mini stage to rotate to its
    // nearest view, which is either the perspective view or the secrete view. A
    // specialization of the mini stage widget could implement this function.
    virtual void onSwipeToNearestView();

// Enum
private:
    // This enum defines the constants to control the behavior of the widget.
    enum
    {
        // The distance, in y-axis, we consider the user swipes the widget.
    #if defined(__MMI_MAINLCD_480X800__)
        DIST_CRITERIA = 24,
    #elif defined(__MMI_MAINLCD_320X480__)
        DIST_CRITERIA = 16,
    #elif defined(__MMI_MAINLCD_240X400__)
        DIST_CRITERIA = 12,
    #else /* defined(__MMI_MAINLCD_240X320__) */
        DIST_CRITERIA = 12,
    #endif /* defined(__MMI_MAINLCD_240X320__) */

        // The time, in msec., we consider the user swipes the widget.
        TIME_CRITERIA = 800
    };

// Variable
private:
    // This constant is used to control the rotation degrees of the pen
    // movement in the y-axis of the screen coordination.
    static const VfxFloat s_degreePerPixel;

// Implementation
private:
    // This function gets the rotation angle of the mini stage.
    // RETURNS: rotation degree
    VfxFloat getRotationAngle(
        VfxS32 distance             // [IN] Pen movement in the y-axis
    ) const;

    // This function rotates the view according to the pen even.
    void rotateView(
        VfxPenEvent &event          // [IN] Pen event
    );
};

#endif /* defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_3D_V10__) */
#endif /* VAPP_WIDGET_MINI_STAGE_H */

