/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vfx_video_frame.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_VIDEO_FRAME_H__
#define __VFX_VIDEO_FRAME_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "ui_core\pme\vfx_pme.h"
#include "vfx_frame.h"
#include "vrt_datatype.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "MMIDataType.h"
#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/

// The VfxVideoFrame registered name
#define VFX_VIDEOFRAME_CLASS_NAME           "VideoFrame"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Class VfxVideoFrame
 *****************************************************************************/

class VfxVideoFrame : public VfxFrame
{
    VFX_DECLARE_CLASS(VfxVideoFrame);

// Typedef
public:
    enum MultimediaTypeEnum
    {
        MULTIMEDIA_NULL,        
        MULTIMEDIA_CAMERA,      // Camera preview 
        MULTIMEDIA_VIDEO,       // Video player (CMMB MTV)
        MULTIMEDIA_RRECORD,     // Recorder
        MULTIMEDIA_MATV,        // mATV
        MULTIMEDIA_VIDEOPHONE,  // Video phone call
        MULTIMEDIA_SUBTITLE     // MKV title
    };

    // video frame hint
    enum HintEnum
    {
        HINT_NONE = VRT_VIDEO_FRAME_HINT_NONE,          // no hint
        // once the video frame exists, do not switch VRT color format back in order to reduce response time
        HINT_PREVENT_VRT_COLOR_FORMAT_CHANGE_IN_SCREEN = VRT_VIDEO_FRAME_HINT_PREVENT_COLOR_FORMAT_CHANGE_IN_SCREEN,
        HINT_APP_CONTROL = VRT_VIDEO_FRAME_HINT_APP_CTRL, // application control video layer position
        HINT_LIVE_ROTATION = VRT_VIDEO_FRAME_HINT_LIVE_ROTATION // live rotation, must allocate triple buffer at first
    };
    
// Constructor / Destructor
public:
    // Default constructor
    VfxVideoFrame();
    // Destructor
    virtual ~VfxVideoFrame();

// Method
public:
    // Set the type of video frame
    virtual void setMultimediaType(
        MultimediaTypeEnum value
    );

    // Set if the video frame is in animation or not 
    virtual void setIsAnimation(
        VfxBool value
    );

    // Set if the video frame is in animation or not 
    virtual void setBuffer(
        const mmi_id appID
    )
    {
        m_appID = appID;
    }
 
    void setColorFormat(
        vrt_color_type_enum colorFormat
    );

    void setHint(HintEnum hint)
    {
        m_hint = hint;
    }

    HintEnum getHint() const
    {
        return m_hint;
    }
    
    // Make venus UI engine to create HW layer by using the buffer 
    virtual VfxBool prepare();

    virtual void unPrepare();

    virtual MultimediaTypeEnum getType()
    {
        return m_multimediaType;
    }

    virtual VfxU32 getColorFormat();
    
    virtual VfxU32 getRotateAngle()
    {
        return 0;
    }
    
    virtual void getBufferContent(
        VfxU8 *mem
    )
    {
    }

    virtual VfxBool getIsReady()
    {
        return m_isReady;
    }

    virtual VfxU32 getLayerHandle();

    virtual VfxU32 getDisplayLayerFlag();

    virtual VfxU32 getHwLayerFlag();

public:
    void bringToFront();

    VfxSignal0 m_signalPlayReady;

private:
    static void vrtPlayCallback(void *userdata);
    void playCallback();
    void onPlayReadyTimerTick(VfxTimer *source);
    
public:
    virtual void setHidden(VfxBool value);

protected:

    virtual void onDeinit();

// Implementation
private:
    MultimediaTypeEnum m_multimediaType;
    const VfxU8  *m_buffer;
    VfxS32  m_bufferSize;
    VfxS32  m_rotateAngle;
    vrt_color_type_enum  m_colorFormat;
    VfxU32  m_layerHandle;
    mmi_id  m_appID;
    VfxS32  m_index;
    VfxBool m_isAnimation;
    VfxBool m_isReady;
    static VfxS32 m_videoLayerCount;
    VfxTimer *m_playReadyTimer;

    HintEnum m_hint;
};

#endif /* __VFX_VIDEO_FRAME_H__ */
