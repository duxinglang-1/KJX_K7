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
 *  vcp_photo_border_frame.h
 *
 * Project:
 * --------
 *  FTO Components
 *
 * Description:
 * ------------
 *  Vinus Photo Border Frame Component
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
 *****************************************************************************/

#ifndef __VCP_PHOTO_BORDER_FRAME_H__
#define __VCP_PHOTO_BORDER_FRAME_H__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"
#include "vfx_control.h"
#include "vfx_class_info.h"
#include "vfx_basic_type.h"
#include "vfx_timer.h"

#if defined(__MMI_VUI_COSMOS_CP__) 

/*****************************************************************************
 * Define
 *****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */

class VfxImageSrc;

/* DOM-NOT_FOR_SDK-END */

// <group DOM_PhotoBorderFrame_Macro&Enum_Enum>
// photo border frame placement enum
enum VcpPhotoBorderFramePlacementEnum
{
    VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_IMAGE_SIZE,    // fit image size, border would resize to fit image real size
    VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_MAX_SIZE,      // fit max size, border would resize to fit image aspect ratio within max size
    VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE,    // fit exact size, border would be the exact size set by max size

    VCP_PHOTO_BORDER_FRAME_PLACEMENT_END_OF_ENUM        // end of the enum
};

// <group DOM_PhotoBorderFrame_Macro&Enum_Enum>
// photo border frame state enum
enum VcpPhotoBorderFrameStateEnum
{
    VCP_BORDER_STATE_NORMAL,            // normal state
    VCP_BORDER_STATE_PRESSED,           // pressed state

    VCP_BORDER_STATE_END_OF_ENUM        // end of the enum
};

/*****************************************************************************
  * Class VcpPhotoBorderFrame
  *****************************************************************************/
class VcpPhotoBorderFrame : public VfxControl
{
    VFX_DECLARE_CLASS(VcpPhotoBorderFrame);

    // Constructor / Destructor
public:	
    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Constructor/Destructor>
    VcpPhotoBorderFrame();


    // Property
public:
    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Property>
    // set the image with image source
    virtual void setImgContent(
        const VfxImageSrc &value    // [IN] image source for content image frame
        );

    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Property>
    // set the image with res id
    void setImgResId(
        VfxResId resId              // [IN] image res id for content image frame
        );

    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Property>
    // set the image with image path
    void setImgPath(
        const VfxWString & path     // [IN] image path for content image frame
        );
	 void setImgPath(
        const VfxWChar *path     // [IN] image path for content image frame
        );

    // Method
public:
    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Method>
    // set the photo border frame layout rule
    void setPlacement(
        VcpPhotoBorderFramePlacementEnum placement  // [IN] the layout rule enum
        );

    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Method>
    // set the content placement for the content image frame
    void setImageContentPlacement(
        VfxFrameContentPlacementTypeEnum contentPlacement   // [IN] the content placement for content image frame
        );

    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Method>
    // set the max size for border frame layout
    // the meaning of max size is depend on setPlacement() value
    void setMaxSize(
        const VfxSize & maxSize     // [IN] the size for layout referenc
        );

    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Method>
    // run onUpdate immediately to update the border frame size
    void forceUpdate();

    void invalidateImageFrame();

//  alternative API - TBD
//  void setFitImageMode(const VfxSize & defaultSize);
//  void setFitMaxSizeMode(const VfxSize & maxSize);
//  void setExactSizeMode(const VfxSize & exactSize, VfxFrameContentPlacementTypeEnum contentPlacement);


    // Signal
public:
    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Event>
    // the click signal
    VfxSignal0 m_signalClicked;

    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Event>
    // the long press signal
    VfxSignal0 m_signalLongPress;

    // Override
protected:
    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Override>
    virtual void onInit();

    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Override>
    virtual void onUpdate();

    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Override>
    virtual VfxBool onPenInput(VfxPenEvent &event);


    // Overridable
protected:
    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Overridable>
    // get the image frame content
    VfxFrame * getImageFrame() const;

    // <group DOM_PhotoBorderFrame_VcpPhotoBorderFrame_Overridable>
    // set the image frame content
    // default is an VfxImageFrame instance
    void setImageFrame(
        VfxFrame * content      // [IN] the new content frame
        );

    void onPenRelease(VfxTimer *timer);


    // Implementation
private:
    VfxFrame * m_content;
    VfxFrame * m_bg;
    VfxFrame * m_fg;
    VcpPhotoBorderFramePlacementEnum m_placement;
    VfxFrameContentPlacementTypeEnum m_imgContentPlacement;
    VfxS32 m_maxWidth;
    VfxS32 m_maxHeight;
    VcpPhotoBorderFrameStateEnum m_state;
    VfxTimer *m_penUpTimer;
};

#endif /* #if defined (__MMI_VUI_COSMOS_CP__)  */
#endif // __VCP_PHOTO_BORDER_FRAME_H__

