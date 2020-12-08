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
 *  vapp_widget_mini_stage.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the base class of the 3D mini stage widget.
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

#include "MMI_features.h"


#if defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_3D_V10__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_widget.h"
#include "vapp_widget_3d.h"
#include "vapp_widget_mini_stage.h"


/*****************************************************************************
 * 3D Mini Stage Widget Base Class
 *****************************************************************************/

//
// The magic number is calculated by the following formula:
//
//  360 / (the height of the region to swipe the stage)
//
// For example, on the WVGA resolution, let the region be 480x550. Then, the
// magic number is calculated by
//
//  0.49f = 270 / 550
//
// It means we want the stage to rotate 270 degrees when the user swipes 550
// pixels.
//
#if defined(__MMI_MAINLCD_480X800__)
const VfxFloat VappWidgetMiniStage::s_degreePerPixel = 0.33f;
#elif defined(__MMI_MAINLCD_320X480__)
const VfxFloat VappWidgetMiniStage::s_degreePerPixel = 0.56f;
#elif defined(__MMI_MAINLCD_240X400__)
const VfxFloat VappWidgetMiniStage::s_degreePerPixel = 0.67f;
#else /* defined(__MMI_MAINLCD_240X320__) */
const VfxFloat VappWidgetMiniStage::s_degreePerPixel = 0.84f;
#endif /* defined(__MMI_MAINLCD_240X320__) */


VFX_IMPLEMENT_VIRTUAL_CLASS("VappWidgetMiniStage", VappWidgetMiniStage, VappWidget3D);


VappWidgetMiniStage::VappWidgetMiniStage()
{
    // Do nothing.
}


VappWidgetMiniStage::~VappWidgetMiniStage()
{
    // Do nothing.
}


void VappWidgetMiniStage::onRotateStart(VfxPenEvent &event)
{
    rotateView(event);
}


void VappWidgetMiniStage::onRotate(VfxPenEvent &event)
{
    rotateView(event);
}


void VappWidgetMiniStage::onRotateEnd(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        onSwipeToNearestView();
    }
    else
    {
        // Our HW pen sampling rate could be low. When we capture the pen event,
        // it is possible that 'pos' and 'prevPos' are the same. UI engine
        // supports 'predictPos' to solve this issue. So, we use 'predictPos',
        // rather than 'pos' when we handle the 'pen-up' event.
        VfxMsec tDiff = vfxMsecDiff(event.timeStamp, event.downTimeStamp);
        VfxS32 yDiff = event.predictPos.y - event.downPos.y;

        // Determine if the user actually wants to swipe the stage. That is
        // the user has a large pen movement in a short time.
        if (tDiff >= TIME_CRITERIA || vfxAbs(yDiff) <= DIST_CRITERIA)
        {
            onSwipeToNearestView();
        }
        else
        {
            if (yDiff > 0)
            {
                onSwipeDown();
            }
            else
            {
                onSwipeUp();
            }
        }
    }
}


void VappWidgetMiniStage::onRotateX(VfxFloat angle)
{
    VFX_UNUSED(angle);

    // Do nothing.
}


void VappWidgetMiniStage::onSwipeUp()
{
    // Do nothing.
}


void VappWidgetMiniStage::onSwipeDown()
{
    // Do nothing.
}


void VappWidgetMiniStage::onSwipeToNearestView()
{
    // Do nothing.
}


VfxFloat VappWidgetMiniStage::getRotationAngle(VfxS32 distance) const
{
    return s_degreePerPixel * distance;
}


void VappWidgetMiniStage::rotateView(VfxPenEvent &event)
{
    VfxS32 offset = event.pos.y - event.downPos.y;

    if (offset != 0)
    {
        onRotateX(getRotationAngle(offset));
    }
}

#endif /* defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_3D_V10__) */

