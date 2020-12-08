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
 *  vapp_wallpaper_interactive_video.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen interactive video wallpaper class header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__

#ifndef __VAPP_WALLPAPER_INTERACTIVE_VIDEO_H__
#define __VAPP_WALLPAPER_INTERACTIVE_VIDEO_H__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_wallpaper.h"

/* RHR start */
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vapp_wallpaper_cfg.h"
#include "vfx_sys_memory.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_primitive_frame.h"
#include "vfx_animation.h"
#include "vfx_owner_draw.h"
#include "vrt_datatype.h"
#include "vfx_image_src.h"
/* RHR end */

// decoder related interface
extern "C"
{
#include "vapp_wallpaper_video_decoder.h"
#include "FileMgrSrvGProt.h"
}

#define STATE_SCALE (100)

class VappInteractiveVideoDraw;
/*****************************************************************************
 * Home screen UI componet: interactive video wallpaper class
 *****************************************************************************/
class VappWallpaperInteractiveVideo : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperInteractiveVideo);

    VAPP_WALLPAPER_CREATE(VappWallpaperInteractiveVideo);

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperInteractiveVideo();

// Configuration before createView
public:
    void setSourceFile(WCHAR *srcFile);

// Override
public:
    // decode file to retrieve thumbnail
    virtual VfxBool getThumbnailImage(VfxImageBuffer &output);

    // use file name as wallpaper name
    virtual void getName(VfxWString &wallpaperName);

    // check if the already exists
    virtual VfxBool checkResource();

    virtual mmi_ret handleEvent(mmi_event_struct *param);

protected:
    // create wallpaper
    virtual void onCreateView();

    // release wallpaper
    virtual void onReleaseView();

    virtual void onSerializeView();
    virtual void onRestoreView();

    // Is allow suspend wallpaper when desktop swipe
    virtual VfxBool onAllowSuspendOnSwipe();

    // Is allow suspend wallpaper when receive pen down
    virtual VfxBool onAllowSuspendOnPenDown();

    // callback for suspend and resume wallpaper
    virtual void onSuspend();
    virtual void onResume();
    virtual void onDesktopCursorChanged(
        VfxFloat curPos,     
        VfxFloat oldPos);

    void checkPlay(void);

//Override
protected:
    virtual VfxBool onPenInput(VfxPenEvent & event);
    VfxBool initASMScreenGroup();
    void deinitASMScreenGroup();

    static mmi_ret onScreenGroupEvent(mmi_event_struct *evt);

public:
    static void* unzip_mem_malloc(void *opaque, unsigned int items, unsigned int size);
    static void unzip_mem_free(void *opaque, void *address);

private:
    VappInteractiveVideoDraw *m_draw;
    VfxFloatTimeline     *m_timeline;

    WCHAR                 m_sourceFileName[FS_MAX_PATH + 1];  // the wallpaper file path
    VfxBool               m_isFileValid;

    MMI_ID                m_asmGroupId;
    static VfxObjHandle   s_instance;
};


/*****************************************************************************
 * Class VappInteractiveVideoDraw
 *****************************************************************************/

class VappInteractiveVideoDraw : public VfxOwnerDraw
{
// Constructor
public:
    // Default constructor
    VappInteractiveVideoDraw();

// Override
public:
    static vrt_render_dirty_type_enum onUpdate(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);

    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect);

    void setFileSrc(WCHAR* src);
    VfxBool destoryFileInfo(void);
    VfxBool createFileInfo(void);

    VfxBool isSuspend(void){return (m_isSuspend);};
    void errHandler(VfxU32 errCode, void* userData);

protected:
    virtual void onInit();
    virtual void onDeinit();

// Method
private:
    static void onVRTError(void *arg);
    void restoreWallpaperSetting(VfxU32 errCode);
    VfxU32 decodeFirstFrame(const vrt_frame_visual_property_struct* watch_frame, const VfxU32 lcdFrameSize);
    VfxU32 readNextFrameContent(VfxU8 *dstBuf, VfxU32* dstBufSize, VAPP_WP_READ_FILE_MODE_ENUM readMode);


// Variable
public:

    #define VIDEO_FPS (15)
    #define VIDEO_HEADER_LEN (50)
    #define DELAY_MOVING_CONDITION (10)
    #define MAX_SUPPORT_PARTITION_NUM (51)

    VfxBool                 m_isSuspend;

    // ======================================================
    // timing update related
    // for interactive mode use
    VfxFloat                m_lastUpdateTiming;

    VfxFloat                m_timeOffset;         // the time offset from the previous updating

    VfxFloat                m_currentTimeOffset;  // the time offset from the start frame in current partiion

    VfxU32                  m_currentDuration;    // current partition frame duration (set FPS as 15)

    VfxS32                  m_previousState;      // the previous state for wallpaper location

    VfxS32                  m_state;              // the current state for wallpaper location

    VfxS32                  m_currentState;       // the current state for frame update
                                                  //
                                                  //
    // ======================================================


    VfxU8                  *m_contentBuffer;                // the decoded data buffer for show the wallpaper
                                                            // for cosmos project, it will be allocated from anomynous ASM
                                                            // for pluto project, it will be allocated from  MED memory

    VfxU32                  m_firstContentSize;             // the size of first decoded frame

    VfxU8                  *m_sourceBuffer;                 // the encode data got from wallpaper file
    VfxU32                  m_sourceBufferRealSize;         // the size of encode data got from wallpaper file
    VfxU8                  *m_sourceBuffer2;                // the encode data got from wallpaper file (double buffer)
    VfxU32                  m_sourceBufferRealSize2;        // the size of encode data got from wallpaper file     (double buffer)
	VfxU8                  *m_fistNotUesedBuffer;           // the buffer point to the next encoded data buffer

    WCHAR                   m_sourceFileName[FS_MAX_PATH + 1];          // the wallpaper file path

    VfxBool                 m_isMovingBetweenPage;          // the status that if drawer is under page moving of HS

    VfxBool                 m_isFirstFrameGen;              // the flag for generate the first frame ot not

    // ======================================================
    // frame decoded related
    //
    VAPP_WP_DECODER_HANDLE *m_fileHandle;                   // the decoder handle

    STFSAL                  m_fsal;                         // the fsal handle for decoder

    VfxU32                  m_frameHeaderLen;               // the frame header size

    VfxU32                  m_framePtr;                     // decoder current decoding frame pointer

    VfxU32                  m_frameCnt;                     // the total frame counts in the file

    VfxU32                  m_decodedFramePtr;              // current frame pointer content on m_contentBuffer. -1 means not decoded at all.

    vrt_color_type_enum     m_cf;                           // VRT color format for m_contentBuffer

    VfxS32                  m_bpp;                          // the number of byte per pixel (in m_contentBuffer)

    VfxU32                  m_FrameWidth;                   // the frame width

    VfxU32                  m_FrameHeight;                  // the frame height

    VfxU32                  m_partitionCount;               // the partition counts in the file

    VfxU32                  m_partitionFrameCount[MAX_SUPPORT_PARTITION_NUM];      // the frame count in each partition (the sum should be the same as m_frameCnt)

    VfxU32                  m_partitionFrameStartPtr[MAX_SUPPORT_PARTITION_NUM];   // the start frame number for each partition
                                                            //   - for non interactive video,
                                                            //     the partition count should be 1 and start at 0
    // ======================================================

    VfxBool                 m_isErrorHappended;
    VfxU32                  m_errorCode;

};
#endif /* __VAPP_WALLPAPER_INTERACTIVE_VIDEO_H__ */
#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__ */

