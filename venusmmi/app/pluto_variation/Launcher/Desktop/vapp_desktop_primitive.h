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
 *  vapp_desktop_primitive.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the primitives.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_DESKTOP_PRIMITIVE_H
#define VAPP_DESKTOP_PRIMITIVE_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_app_widget_primitive.h"


/*****************************************************************************
 * Color Filter
 *****************************************************************************/

class VappDesktopColorFilter : public VfxFrameFilter
{
    VFX_DECLARE_CLASS(VappDesktopColorFilter);

// Constructor / Destructor
public:
    // Default constructor
    VappDesktopColorFilter();

// Method
public:
    // Set the filter range. The whole frame's RGB color will be scaled to fix
    // within the min and max color. The alpha channel is not changed. That is
    // the alpha value in the 'colorMin' and 'colorMax' are dummy at present.
    void setColorFilter(
        const VfxColor &colorMin,       // [IN] Min color
        const VfxColor &colorMax        // [IN] Max color
    );

// Override
protected:
    // Please refer to VfxFrameFilter.
    virtual BufferModeEnum onGetBufferMode() const;

    // Please refer to VfxFrameFilter.
    virtual VfxBool onProcess(
        VfxU8 *outBuf,
        VfxImageBuffer &inBuf,
        VfxFloat timing
    );

// Variable
private:
    // Min red color after applying this color filter.
    VfxU8    m_minR;

    // Min green color after applying this color filter.
    VfxU8    m_minG;

    // Min blue color after applying this color filter.
    VfxU8    m_minB;

    // Range of the red color after applying this color filter.
    VfxU8    m_rangeR;

    // Range of the green color after applying this color filter.
    VfxU8    m_rangeG;

    // Range of the blue color after applying this color filter.
    VfxU8    m_rangeB;

// Implementation
private:
    // This function processes the ARGB color format.
    void onProcessArgb(
        VfxU8 *outBuf,          // [OUT] Output buffer
        VfxImageBuffer &inBuf,  // [IN]  Input buffer
        VfxFloat timing         // [IN]  Timing
    );

    // This function processes the PARGB color format.
    void onProcessPargb(
        VfxU8 *outBuf,          // [OUT] Output buffer
        VfxImageBuffer &inBuf,  // [IN]  Input buffer
        VfxFloat timing         // [IN]  Timing
    );
};


/*****************************************************************************
 * Sorting Utility
 *****************************************************************************/

class VappDesktopSort : public VfxObject
{
    VFX_DECLARE_CLASS(VappDesktopSort);

// Constructor / Destructor
public:
    // Default constructor
    VappDesktopSort();

// Method
public:
    // This function sorts the widget ID array according to the widget's names.
    // This function will cache all widget's names first such that it does not
    // need to query the widget's name each time we compares them. It improves
    // the perfomance.
    void sortByName(
        VappAppWidgetId **array,       // [IN] Widget ID array
        VfxS32 size                 // [IN] Size of the array
    );

// Enum
private:
    enum
    {
        // Max. length of the widget's name.
        MAX_NAME_LEN = 40,

        // Max. buffer size of the widget's name.
        MAX_NAME_SIZE = MAX_NAME_LEN + 1,
    };

// Implementation
private:
    // This function creates an array which contains the names of the specified
    // widgets.
    // RETURNS: array of all widget's names
    //
    // SEE ALSO: releaseNameArray
    VfxWChar **createNameArray(
        VappAppWidgetId **array,       // [IN] Widget ID array
        VfxS32 size                 // [IN] Size of the array
    );

    // This function releases the name array.
    //
    // SEE ALSO: createNameArray
    void releaseNameArray(
        VfxWChar **nameArray,       // [IN] Name array
        VfxS32 size                 // [IN] Size of the array
    );

    // This function sorts the widget ID array, together with their name array.
    void quickSort(
        VappAppWidgetId **array,       // [IN] Widget Id array
        VfxWChar **nameArray,       // [IN] Name Array
        VfxS32 left,                // [IN] Left-most index (inclusive)
        VfxS32 right                // [IN] Right-most index (inclusive)
    );

    // This function partitions the widget ID array, together with their name
    // array. After the partition, all elements before the 'pivotIndex'-th
    // element are less than or equal to the 'pivotIndex'-th element. And, all
    // elements after the 'pivotIndex'-th element are greater than or equal to
    // the 'pivotIndex'-the element.
    // RETURNS: the new index for the pivot.
    VfxS32 partition(
        VappAppWidgetId **array,       // [IN] Widget ID array
        VfxWChar **nameArray,       // [IN] Name array
        VfxS32 left,                // [IN] Left-most index (inclusive)
        VfxS32 right,               // [IN] Right-most index (inclusive)
        VfxS32 pivotIndex           // [IN] Pivot index
    );

    // This function swaps the 'index1'-th and the 'index2'-th elements in the
    // widget ID array and the name array.
    void swap(
        VappAppWidgetId **array,       // [IN] Widget Id array
        VfxWChar **nameArray,       // [IN] Name array
        VfxS32 index1,              // [IN] Index 1
        VfxS32 index2               // [IN] Index 2
    );
};


#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_DESKTOP_PRIMITIVE_H */

