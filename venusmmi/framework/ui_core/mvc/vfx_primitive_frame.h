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
 *  vfx_primitive_frame.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Primitive frame types
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
#ifndef __VFX_PRIMITIVE_FRAME_H__
#define __VFX_PRIMITIVE_FRAME_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxFrame
#include "vfx_frame.h"

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_image_src.h"
#include "vfx_cpp_base.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
 
// The VfxImageFrame registered name
#define VFX_IMAGE_FRAME_CLASS_NAME       "Image"


/***************************************************************************** 
 * Class VfxImageFrame
 *****************************************************************************/

/*
 * VfxImageFrame is a primitive frame which contains a VfxImage for frame content.
 *
 * SEE ALSO: VfxImage
 */
class VfxImageFrame : public VfxFrame
{
    VFX_DECLARE_CLASS(VfxImageFrame);
    
// Constructor / Destructor
public:
    // Default constructor
    VfxImageFrame();

// Property
public:
    // The file name of the image.
    // 
    // NOTE: Default value is null string.
    const VfxWString &getPath() const;
    
    // Backward compatiable method, see getPath.
    //
    // SEE ALSO: getPath
    const VfxWString &getSrc() const
    {
        return getPath();

    }
    
    // The Resource ID of the image.
    // 
    // NOTE: Default value is 0.
    VfxS32 getResId() const;

    // Set the image frame content with a path
    void setPath(const VfxWString &value)
    {
        setImgContent(VfxImageSrc(value));
    }
    
    // Set the image frame content with a resource ID
    //
    // NOTE: The frame size will be updated to image size.    
    void setResId(VfxS32 value)
    {
        setImgContent(VfxImageSrc(value));
    }

    // Set the image frame with a memory pointer with image resource 8-bytes header
    //
    // NOTE: The frame size will be updated to image size.    
    void setMem(const VfxU8 *value)
    {
        setImgContent(VfxImageSrc(value));
    }

    virtual void setImgContent(const VfxImageSrc &value);

    // Return if the image frame contains null image source.
    //
    // RETURNS: Return VFX_TURE if the image frame contains null image source.
    //  Otherwise, return VFX_FALSE.
    VfxBool isNull() const
    {
        return getImgContent().isNull();
    }

    // Set the image frame to contains null image source.
    void setNull()
    {
        setImgContent(VFX_IMAGE_SRC_NULL);
    }

	void setAutoResize(VfxBool isEnabled)
	{
	    m_isAutoResize = isEnabled;
	}

// Methods
public:
    // Backward compatiable method, see setPath.
    //
    // SEE ALSO: setPath
    void setSrc(const VfxWString &value)
    {
        setPath(value);
    }
    
    // Backward compatiable method, see setMem.
    //
    // SEE ALSO: setMem
    void loadFromMem(const VfxU8 *value)
    {
        setMem(value);
    }
    
// Override
protected:
    virtual void onInit();

// Implementation
private:
    void updateSize();

private:

	VfxBool m_isAutoResize;
};


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_ANIM_IMAGE_FRAME_CLASS_NAME       "VfxAnimImage"

#define VFX_ANIM_IMAGE_FRAME_PLAY_COUNT_INFINIT 0xFFFFFFFF

#define VFX_ANIM_IMAGE_FRAME_MAX_INDEX 0xFFFFFFFF

/***************************************************************************** 
 * Class VfxAnimImageFrame
 *****************************************************************************/

/*
 * VfxAnimImageFrame is a primitive frame which contains a animation frame content.
 *
 * SEE ALSO: VfxImageSrc
 */
class VfxAnimImageFrame : public VfxImageFrame
{
    VFX_DECLARE_CLASS(VfxAnimImageFrame);
    
// Constructor / Destructor
public:

    // Default constructor
    VfxAnimImageFrame();

// Method
public:
    
	// Set animation repeat count, default value is VFX_ANIM_IMAGE_FRAME_PLAY_COUNT_INFINIT
	VfxBool setRepeatCount(
	    VfxU32 repeatCount    // [IN] The repeat count of the animation
	);
	
	// Get the animation repeat count
	VfxU32 getRepeatCount() const;
	
	// Set the animation end frame index, default is the last index
	void setEndIndex(VfxU32 endIndex);
	
	// Get the animation end frame index
	VfxU32 getEndIndex() const;
	
	// Start to play the animation
	void play();
	
	// Stop the animation
	void stop();

    // Suspend the animation at the specified index
	void suspend(
	    VfxU32 suspendAtIndex = VFX_ANIM_IMAGE_FRAME_MAX_INDEX    // [IN] The inedx to suspend at
	);

    // Resume the suspended animation
	void resume();

    // Helper interface, play and suspend the animation at the specific index
	void playAndSuspend(
	    VfxU32 suspendAtIndex = VFX_ANIM_IMAGE_FRAME_MAX_INDEX    // [IN] The inedx to suspend at
	);

// Event
public:

    // The signal is emitted when the animation is finished
    VfxSignal1<VfxObject *> m_signalEnd;

// Override	
public:

	virtual void processCreateHandle();

    virtual void setImgContent(const VfxImageSrc &value);

private:

	enum anim_state_enum
	{
        INIT,
        PLAYING,
        SUSPENDED
	};

	struct anim_control_data_struct
    {
		VfxU32       repeatCount;
		VfxU32       endIndex;
		VfxU32       suspendIndex;
		anim_state_enum state;
    };

	static void vrtPlayEndCallbackHelper(void *userdata);

	static vrt_frame_property_monitor_type_enum vrtFramePropertyMonitorCallback(
            vrt_frame_property_handle target_frame, void *user_data, vrt_u32 user_data_size);

	void playEndCallback();

	void updateControlData();

	static vrt_frame_property_monitor_type_enum vrtProcessInitState(anim_control_data_struct *controlData, vrt_animation_image_status_struct *anim);

	static vrt_frame_property_monitor_type_enum vrtProcessPlayingState(anim_control_data_struct *controlData, vrt_animation_image_status_struct *anim);

	static vrt_frame_property_monitor_type_enum vrtProcessSuspendedState(anim_control_data_struct *controlData, vrt_animation_image_status_struct *anim);

    static VfxBool vrtExecuteAnimationImage(anim_control_data_struct *controlData, vrt_animation_image_status_struct *anim);
private:

	VfxU32 m_repeatCount;

	VfxU32 m_endIndex;

	anim_state_enum m_state;

	VfxU32 m_suspendIndex;

};

#endif /* __VFX_PRIMITIVE_FRAME_H__ */

