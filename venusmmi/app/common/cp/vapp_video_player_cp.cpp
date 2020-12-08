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
#include "MMI_features.h"

#if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) || defined(__COSMOS_MMI_PACKAGE__)

#include "vapp_video_player_cp.h"
#include "vfx_video_frame.h"
#include "vfx_top_level.h"
#include "MMI_media_app_trc.h"

extern "C"
{
#include "mdi_include.h"
#include "gpiosrvgprot.h"
#include "gdi_include.h"
#include "gdi_lcd.h"
#include "ProfilesSrvGprot.h"
#include "BtAudioSrvGprot.h"
#include "A2dpSrvGprot.h"
#include "cbm_api.h"
#include "DtcntSrvGprot.h"
#include "UcmSrvGprot.h"
#include "mmi_rp_vapp_video_player_cp_def.h"
#include "cache_sw.h"
#include "iul_csc_y2r.h"
#include "CbmSrvGprot.h"
#include "Cbm_api.h"
#include "hal_custom_video_codec_if.h"
#include "gdi_features.h"
#include "lang_interface.h"
}

#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_vapp_gallery_def.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "vapp_vol_dialog_gprot.h"
#include "vcp_activity_indicator.h"
#include "vapp_gallery_gprot.h"
#include "vcui_videoclipper_gprot.h"
#endif

#ifdef __MTK_TARGET__
#define __MAUI_SOFTWARE_LA__
#endif

#if defined(__MTK_TARGET__) && defined(__MAUI_SOFTWARE_LA__)
#ifdef __cplusplus
extern "C"
{
#endif
#include "SST_sla.h"
#ifdef __cplusplus
}
#endif
#define SWLA_BEGIN(_symbol_) SLA_CustomLogging(##_symbol_##, SA_start);
#define SWLA_END(_symbol_) SLA_CustomLogging(##_symbol_##, SA_stop);
#else
#define SWLA_BEGIN(_symbol_)
#define SWLA_END(_symbol_)
#endif

#undef __VAPP_VIDEO_PLAYER_SLEEP_VIDEO__

/*****************************************************************************
 * Dummy class for FTE
 *****************************************************************************/
#if !defined(__COSMOS_MMI_PACKAGE__)
class VcpActivityIndicator : public VfxFrame
{
public:
    void setHiddenWhenStopped(VfxBool) {};
    void stop(){};
    void start(){};
};
#endif

/*****************************************************************************
 * Global Variable
 *****************************************************************************/
static const VfxU32 VAPP_VIDEO_CP_URL_MAX_BUF_LENGTH = 521;      // This comes from MEDPLY_URL_MAX_LENGTH
static VappVideoPlayerComponent* g_inst = NULL;

/*****************************************************************************
 * Static functions
 *****************************************************************************/
static VfxBool isFileExist(const VfxWString &filePath)
{
    FS_HANDLE handle;
    handle = FS_Open(filePath, FS_READ_ONLY);
    if(handle > 0)
    {
        FS_Close(handle);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

static mmi_id findRootAppId(VfxObject *obj)
{
#ifdef __COSMOS_MMI_PACKAGE__
    mmi_id appId = NULL;
    VfxApp *pApp = NULL;
    for(VfxObject *pObj = obj; pObj != NULL; pObj = pObj->getParent())
    {
        pApp = VFX_OBJ_DYNAMIC_CAST(pObj, VfxApp);
        if(pApp != NULL)
        {
            appId = pApp->getGroupId();
            return appId;
        }
    }
    // root is not VfxApp, why?
    VFX_ASSERT(0);
#endif

    // Pluto package does not have root APP id
    return NULL;
}

static VfxResId getAudioOnlyIcon()
{
#ifndef __COSMOS_MMI_PACKAGE__
    // PLUTO package, no audio only icon
    return 0;
#else
    return IMG_ID_VAPP_GALLERY_VID_ICON_AUDIO_ONLY;
#endif
}

static VfxId getErrorIconFromMDIResult(MDI_RESULT res)
{
#ifndef __COSMOS_MMI_PACKAGE__
    // PLUTO package, no default error icon
    return 0;

#else
    // currently, we only handle "DRM" specifically.
    // otherwise treat as unsupported format.
    switch(res)
    {
    case MDI_RES_VDOPLY_ERR_DRM_PROHIBITED:
    case MDI_RES_VDOPLY_ERR_DRM_DURATION_USED:
        return IMG_ID_VAPP_GALLERY_SHT_DRM_ICON;
    /*
    case MDI_RES_VDOPLY_SEEK_PARTIAL_DONE:
    case MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH:
    case MDI_RES_VDOPLY_REACH_STOP_TIME:
    case MDI_RES_VDOPLY_STREAM_BUFFER_OVERFLOW:
    case MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW:
    case MDI_RES_VDOPLY_STREAM_DRM_NEED_RIGHT:
    case MDI_RES_VDOPLY_ALREADY_FINISHED:
    case MDI_RES_VDOPLY_ERR_FAILED:
    case MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED:
    case MDI_RES_VDOPLY_ERR_FILE_TOO_LARGE:
    case MDI_RES_VDOPLY_ERR_SNAPSHOT_FAILED:
    case MDI_RES_VDOPLY_ERR_PLAY_FAILED:
    case MDI_RES_VDOPLY_ERR_SEEK_FAILED:
    case MDI_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL:
    case MDI_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION:
    case MDI_RES_VDOPLY_ERR_SNAPSHOT_NO_DISK:
    case MDI_RES_VDOPLY_ERR_SNAPSHOT_ROOT_DIR_FULL:
    case MDI_RES_VDOPLY_ERR_STREAM_CONNECT_FAILED:
    case MDI_RES_VDOPLY_ERR_INVALID_RESOULTION:
    case MDI_RES_VDOPLY_ERR_NETWORK_DISCONNECT:
    case MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT:
    case MDI_RES_VDOPLY_ERR_NETWORK_FORBIDDEN:
    case MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT:
    case MDI_RES_VDOPLY_ERR_FRAMERATE_TOO_HIGH:
    case MDI_RES_VDOPLY_ERR_STREAM_BUFFER_FAILED:
    */
    default:
        return IMG_ID_VAPP_GALLERY_SHT_UNKNOWN_FORMAT_ICON;
    }
#endif // #ifndef __COSMOS_MMI_PACKAGE__
}

static mmi_ret _onVolumeChange(mmi_event_struct *param)
{
#ifdef __COSMOS_MMI_PACKAGE__
    if(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE != param->evt_id ||
       sizeof(vapp_vol_dialog_evt_struct) != param->size)
    {
        return MMI_RET_OK;
    }

    vapp_vol_dialog_evt_struct *volEvent = (vapp_vol_dialog_evt_struct*)param;
    if(VAPP_VOL_DIALOG_IS_MEDIA == volEvent->type)
    {
        return !MMI_RET_OK;
    }
#endif
    return MMI_RET_OK;
}

static VfxBool _isUserSetBTOutput()
{
#if defined(__MMI_A2DP_SUPPORT__)
    return (srv_a2dp_is_output_to_bt() == MMI_TRUE);
#else
    return VFX_FALSE;
#endif
}

static VfxBool isAnyParentHidden(VfxFrame *frame)
{
    for(VfxFrame *parent = frame->getParentFrame(); parent != NULL; parent = parent->getParentFrame())
    {
        if(parent->getHidden())
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

#if !defined(GDI_GOVL_SUPPORT) && !defined(__VENUS_3D_UI_ENGINE__)

// convert color format and MAY change layer pointer to cachable address
static MMI_BOOL _util_convert_color_format(gdi_handle layer_handle,
                                           U32 src_format,
                                           U32 dst_format,
                                           U8 *buf_ptr,
                                           S32 layer_width,
                                           S32 layer_height)
{
    S32 ret = 0;

    if (src_format == GDI_COLOR_FORMAT_UYVY422 &&  /* 6 */
        dst_format == GDI_COLOR_FORMAT_16)         /* 2 */
    {
        // if GOVL is supported,
        // we don't convert to cacheable, so that GOVL can be used.
        #if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__) && !defined(GDI_GOVL_SUPPORT))
        buf_ptr = (U8*)phys_to_virt((U32*)buf_ptr);
        #endif

        ret = iul_csc_yuv422itlv_to_rgb565(
                    (unsigned int*)buf_ptr,
                    (unsigned short*)buf_ptr,
                    layer_width,
                    layer_height);

        // make sure we change the layer buffer pointer,
        // since we don't do flush here.
        // VRT will use this pointer directly.
        #if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__) && !defined(GDI_GOVL_SUPPORT))
        gdi_layer_struct *layerImpl = (gdi_layer_struct*)layer_handle;
        layerImpl->buf_ptr = buf_ptr;
        #endif
    }
    else
    {
        // only support UYUV to RGB565
        ASSERT(src_format == dst_format);
    }

    if (ret == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#endif

/*****************************************************************************
 * Typedef
 *****************************************************************************/
#define VAPP_VIDEO_PLAYER_COMPONENT_DEFAULT_SUBTITLE_INFO_INDEX (-1)
enum VappVideoPlayerComponentSubtitleLayout
{
#if defined(__MMI_MAINLCD_480X800__)
    SUBTITLE_DISPLAY_X = 400,
    SUBTITLE_DISPLAY_Y = 475,
    FONT_SIZE = 30,

#elif defined(__MMI_MAINLCD_320X480__)
    SUBTITLE_DISPLAY_X = 240,
    SUBTITLE_DISPLAY_Y = 315,
    FONT_SIZE = 20,

#elif defined(__MMI_MAINLCD_240X400__)
    SUBTITLE_DISPLAY_X = 200,
    SUBTITLE_DISPLAY_Y = 235,
    FONT_SIZE = 16,

#elif defined(__MMI_MAINLCD_240X320__)
    SUBTITLE_DISPLAY_X = 160,
    SUBTITLE_DISPLAY_Y = 235,
    FONT_SIZE = 16,

#else
    SUBTITLE_DISPLAY_X = 160,
    SUBTITLE_DISPLAY_Y = 235,
    FONT_SIZE = 16,
#endif
};

/*****************************************************************************
 * Meneto for 3D anaglph switch
 *****************************************************************************/
VappVideoPlayerSwitchMemento::VappVideoPlayerSwitchMemento():
    m_isSwitchingMode(VFX_FALSE),
    m_isSeekable(VFX_FALSE),
    m_needResumeAfterSwitch(VFX_FALSE),
    m_totalDuration(0),
    m_currentTime(0)
{
}

void VappVideoPlayerSwitchMemento::configMemento(
                    const VfxBool isSwitchingMode,
                    const VfxBool isSeekable,
                    const VfxBool needResumeAfterSwitch,
                    const U64 totalDuration, 
                    const U64 currentTime,
                    const VappVideoMsec seekableRegion)
{
    m_isSwitchingMode = isSwitchingMode;
    m_isSeekable = isSeekable;
    m_needResumeAfterSwitch = needResumeAfterSwitch;
    m_totalDuration = totalDuration;
    m_currentTime = currentTime;
    m_seekableRegion = seekableRegion ? seekableRegion : totalDuration;
}

void VappVideoPlayerSwitchMemento::reset()
{
    m_isSwitchingMode = VFX_FALSE;
    m_isSeekable = VFX_FALSE;
    m_needResumeAfterSwitch = VFX_FALSE;
    m_totalDuration = 0;    
    m_currentTime = 0;
}

VfxBool VappVideoPlayerSwitchMemento::isSwitching() const
{
    return m_isSwitchingMode;
}

VfxBool VappVideoPlayerSwitchMemento::isSeekable() const
{
    return m_isSeekable;
}

VfxBool VappVideoPlayerSwitchMemento::isNeedResumeAfterSwitch() const
{
    return m_needResumeAfterSwitch;
}

MDI_RESULT VappVideoPlayerSwitchMemento::getTotalTime(U64 &time)
{
    time =  m_totalDuration;
    return MDI_RES_VDOPLY_SUCCEED;
}

MDI_RESULT VappVideoPlayerSwitchMemento::getSeekableRegion(VappVideoMsec &seekableRegion)
{
    seekableRegion = m_seekableRegion;
    return MDI_RES_VDOPLY_SUCCEED;
}

MDI_RESULT VappVideoPlayerSwitchMemento::getCurrentTime(U64 &time)
{
    time =  m_currentTime;
    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * Interfaces for MDI Video, PDL and Stream
 *****************************************************************************/
class VappVideoPlayerInputSource
{
public:
    VappVideoPlayerInputSource();
    VfxBool isLocalFile() const;
    VfxBool isProgressiveDownload() const;
    VfxBool isRTSPLink() const;
    VfxBool isStreaming() const;
    VfxBool isResource() const;

public:
    VfxBool m_isResId;      // VFX_TRUE if video resource id is used
    VfxBool m_isLocalFile;  // VFX_TRUE if the m_path is a local file path
    VfxBool m_isPDL;        // VRX_TRUE if the m_path is a PDL-enabled local file path
    VfxBool m_isStreaming;  // VFX_TRUE if file is played by streaming player
    VfxResId m_resId;       // actual resource id
    VfxWString m_path;      // may be a RTSP link or file path
    U64 m_startingTimeHint; // default to 0
};

VappVideoPlayerInputSource::VappVideoPlayerInputSource():
    m_isResId(VFX_FALSE),
	m_isLocalFile(VFX_TRUE),
    m_isPDL(VFX_FALSE),
    m_isStreaming(VFX_FALSE),
    m_resId(0),
    m_startingTimeHint(0)
{
}

VfxBool VappVideoPlayerInputSource::isLocalFile() const
{
    return m_isLocalFile;
}

VfxBool VappVideoPlayerInputSource::isProgressiveDownload() const
{
#ifdef __MMI_VIDEO_PDL__
    return m_isPDL && isLocalFile();
#else
    return VFX_FALSE;
#endif
}

VfxBool VappVideoPlayerInputSource::isRTSPLink() const
{
    return !m_isLocalFile;
}

VfxBool VappVideoPlayerInputSource::isStreaming() const
{
    return m_isStreaming;
}

VfxBool VappVideoPlayerInputSource::isResource() const
{
    return m_isResId;
}

class VappMDIAdaptor : public VfxObject
{
public:
    typedef VfxSignal2<MDI_RESULT, mdi_video_info_struct*> VideoOpenSignal;
    typedef VfxSignal1<MDI_RESULT> PlayFinishSignal;
    typedef VfxSignal2<MDI_RESULT, mdi_video_info_struct*> SeekDoneSignal;

public:
    VappMDIAdaptor();

    virtual void config(VappVideoPlayerComponent *parent, VfxId appId, VfxBool allowScrolling, const VappVideoPlayerPlayOption &option, VfxBool is3DAnaglyphMode = VFX_FALSE);
    VideoOpenSignal& getVideoOpenSignal();
    PlayFinishSignal& getPlayFinishSignal();
    SeekDoneSignal& getSeekDoneSignal();

    virtual MDI_RESULT openVideo(const VappVideoPlayerInputSource &input) = 0;
    virtual MDI_RESULT closeVideo() = 0;
    virtual VfxBool getOpenedVideo(VappVideoPlayerInputSource &input) = 0;    // retrieve the source being opened

    virtual VfxBool isPlaying();
    virtual MDI_RESULT play(VfxVideoFrame *videoFrame,              // video frame. CAN be NULL for audio-only case
                            VfxVideoFrame *subtitleFrame,           // subtitle. Can be NULL in no subtitle case
                            const mdi_video_info_struct &videoInfo  // video info to be played.
                            ) = 0;
    virtual MDI_RESULT stop() = 0;

    virtual MDI_RESULT getCurrentPlayTime(U64 &time) = 0;

    virtual VfxBool canSeek() = 0;
    virtual VfxBool canSeekWithoutBuffering() = 0;
    virtual MDI_RESULT getSeekableRegion(U64 &seekableRegion) = 0;
    virtual MDI_RESULT seek(U64 time) = 0;
    virtual MDI_RESULT blockingSeek(U64 time) = 0;
    virtual MDI_RESULT blockingSeekAndGetFrame(U64 time, GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer = NULL) = 0;
    virtual MDI_RESULT blockingGetFrame(GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer = NULL) = 0;
    virtual VfxBool canGetStillFrame() = 0;
    virtual VfxBool mustPlayAfterSeek() = 0;
    virtual MDI_RESULT seekAndGetFrame(U64 time, GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer = NULL) = 0;
    virtual VfxBool canGetKeyFrame() = 0;
    virtual MDI_RESULT getKeyFrameTime(const U64 refrenceTime, U64 &keyFrameTime) = 0;

    virtual VfxBool canDisconnect() = 0;
    virtual MDI_RESULT disconnect() = 0;
    virtual kal_int8 releaseBearer(){return 0;};

    // disables next DRM playcount consumption.
    // openVideo() and resume() both may consume play rights.
    // this works only once.
    virtual void disableNextDRMConsumption() = 0;

    virtual VfxBool changeVideoScreenMode(
                    const U8 mdiScreenMode,
                    VfxVideoFrame *videoFrame,
                    VfxVideoFrame *subtitleFrame,
                    const VfxBool needPausedResume,
                    const VfxBool isAudioOnly) = 0;

    /*
     * subtitle utility
     */
    VfxS32 querySubtitleTrackCount(const mdi_video_info_struct &videoInfo) const;
    VfxBool isValidSubtitleInfoIndex(const mdi_video_info_struct &videoInfo,
                                        const VfxS32 infoIndex) const;
    VfxBool queryMDISubtitleInfo(
                const mdi_video_info_struct &videoInfo,    // [IN] queried video info
                const VfxS32 infoIndex,                    // [IN] index of videoInfo.subtitle_info[]
                U32 &trackIndex,                           // [OUT] subtitle track index
                U32 &languageIso) const;                   // [OUT] language ISO of target subtitle track
    VfxBool querySubtitleLanguageName(
                const mdi_video_info_struct &videoInfo,   // [IN] queried video info
                const VfxS32 infoIndex,                   // [IN] index of videoInfo.subtitle_info[]
                VfxWString &name) const;                  // [OUT] language name of target subtitle track

    VfxBool querySubtitleInfoIndexByLCC(
                const mdi_video_info_struct &videoInfo,   // [IN] queried video info
                PU8 targetLCC,                            // [IN] target LCC (language country code)
                VfxS32 &infoIndex) const;                 // [OUT] sibtitle info index of the 1st subtitle which has the same LCC with target LCC

    // check if infoIndex is valid
    // for invalid subtitle info index, fix as the one with same LCC of phone as possible
    // otherwise, fix as 0 (1st info index) defaultly
    // return VFX_FALSE  if the output "validInfoIndex" is invalid
    virtual VfxBool checkAndFixToValidSubtitleInfoIndex(
        const mdi_video_info_struct &videoInfo, // [IN] source video info
        const VfxS32 infoIndex,                 // [IN] traget  index of videoInfo.subtitle_info[]
        VfxS32 &validInfoIndex                  // [OUT] valid traget  index of videoInfo.subtitle_info[]
        ) const;

    // sustitle support
    // note we not support subtitle defaultly
    virtual VfxBool canSwitchSubtitle() const{return VFX_FALSE;};
    virtual VfxBool switchSubtitleTrack(
        const mdi_video_info_struct &videoInfo, // [IN] source video info
        const VfxS32 infoIndex)                 // [IN] traget  index of videoInfo.subtitle_info[]
    {
        return VFX_FALSE;
    };

    void setSubtitleInfoIndex(VfxS32 infoIndex){m_subtitleInfoIndex = infoIndex;};
    VfxS32 getSubtitleInfoIndex() const{return m_subtitleInfoIndex;};

    // 3D anaglyph support
    void setIs3DAnaglyphMode(const VfxBool b){m_is3DAnaglyphMode = b;};
    VfxBool getIs3DAnaglyphMode(){return m_is3DAnaglyphMode;};
    virtual VfxBool canSwitchTo3DTrack(const mdi_video_info_struct &videoInfo, const VfxBool swtchTo3D) = 0;
    virtual VfxBool switchTo3DTrack(const mdi_video_info_struct &videoInfo, const VfxBool swtchTo3D) = 0;

protected:

    U8 getCurrentAudioPath()
    {
        return MDI_DEVICE_SPEAKER2; // use earphone if plugged
    }

    static void onPlayFinished(MDI_RESULT ret, void *user_data);
    virtual void handlePlayFinished(MDI_RESULT ret) = 0;         // handles playback finish event

protected:
    VappVideoPlayerComponent *m_parentComponent;
    VfxId m_appId;
    VfxBool m_allowScrolling;
    VideoOpenSignal m_signalVideoOpen;
    PlayFinishSignal m_signalPlayFinish;
    SeekDoneSignal m_signalSeekDone;
    VappVideoPlayerPlayOption m_option;
    VfxBool m_is3DAnaglyphMode;

    // subtitle
    VfxS32  m_subtitleInfoIndex;
};

class VappGalleryMDIVideoAdaptor : public VappMDIAdaptor
{
public:
    VappGalleryMDIVideoAdaptor();
    virtual void onDeinit();

    virtual MDI_RESULT openVideo(const VappVideoPlayerInputSource &input);
    virtual MDI_RESULT closeVideo();
    virtual VfxBool getOpenedVideo(VappVideoPlayerInputSource &input);

    virtual MDI_RESULT play(VfxVideoFrame *videoFrame,              // video frame. CAN be NULL for audio-only case
                            VfxVideoFrame *subtitleFrame,           // subtitle. Can be NULL in no subtitle case
                            const mdi_video_info_struct &videoInfo  // video info to be played.
                            );
    virtual MDI_RESULT stop();

    virtual MDI_RESULT getCurrentPlayTime(U64 &time);

    virtual VfxBool canGetStillFrame();
    virtual VfxBool mustPlayAfterSeek();

    virtual MDI_RESULT seekAndGetFrame(U64 time, GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer = NULL);
    virtual MDI_RESULT blockingSeekAndGetFrame(U64 time, GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer = NULL);
    virtual MDI_RESULT blockingGetFrame(GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer = NULL);
    virtual VfxBool canSeek();
    virtual VfxBool canSeekWithoutBuffering();
    virtual MDI_RESULT getSeekableRegion(U64 &seekableRegion);
    virtual MDI_RESULT seek(U64 time);
    virtual MDI_RESULT blockingSeek(U64 time);
    virtual VfxBool canGetKeyFrame() ;
    virtual MDI_RESULT getKeyFrameTime(const U64 refrenceTime, U64 &keyFrameTime) ;

    virtual VfxBool canDisconnect();
    virtual MDI_RESULT disconnect();

    virtual void disableNextDRMConsumption();

    virtual VfxBool changeVideoScreenMode(
                    const U8 mdiScreenMode,
                    VfxVideoFrame *videoFrame,
                    VfxVideoFrame *subtitleFrame,
                    const VfxBool needPausedResume,
                    const VfxBool isAudioOnly);

    // subtitle support
    // VappGalleryMDIVideoAdaptor supports subtitle if __MMI_VIDEO_SUBTITLE_SUPPORT__ config turns on
    virtual VfxBool canSwitchSubtitle() const;
    virtual VfxBool switchSubtitleTrack(const mdi_video_info_struct &videoInfo, // [IN] source video info
                                        const VfxS32 infoIndex)  ;              // [IN] traget  index of videoInfo.subtitle_info[]

    // 3D anaglyph support
    virtual VfxBool canSwitchTo3DTrack(const mdi_video_info_struct &videoInfo, const VfxBool swtchTo3D);
    virtual VfxBool switchTo3DTrack(const mdi_video_info_struct &videoInfo, const VfxBool swtchTo3D);

private:
    // 3D anaglyph support: query the mdi_video_track_index for the certain track type
    VfxBool queryMDIVideoTrackIndex(
                const mdi_video_info_struct &videoInfo,
                const mdi_video_track_type_enum targetType,
                VfxU32 &trackIndex);

    MDI_RESULT _playEx(VfxVideoFrame *videoFrame,
                       VfxVideoFrame *subtitleFrame,
                       const mdi_video_info_struct &videoInfo);
    MDI_RESULT _resumeEx(VfxVideoFrame *videoFrame,
                             VfxVideoFrame *subtitleFrame,
                             const VfxBool isAudioOnly);
    MDI_RESULT _getFrameEx(GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer);
    MDI_RESULT _seekEx(U64 time,
                       const VfxBool isBlocking,
                       const VfxBool shouldGetFrame,
                       GDI_HANDLE videoLayer,
                       GDI_HANDLE subtitleLayer,
                       mdi_seek_result_callback seekCallback,
                       void* userData);

protected:
    static void onVideoOpenResult(MDI_RESULT ret, mdi_video_info_struct *video_info, void *user_data);
    static void onSeekFinished(MDI_RESULT ret, void *user_data);
    static void onNonBlockSeekingFinishedDuringOpen(MDI_RESULT ret, void *user_data);

    void handleVideoOpenResult(MDI_RESULT ret, mdi_video_info_struct *video_info);
    void handleSeekFinishedResult(MDI_RESULT res);
    void handleNonBlockSeekingFinishedDuringOpen(MDI_RESULT ret, mdi_video_info_struct *video_info);

    virtual void handlePlayFinished(MDI_RESULT ret);

    void onBufferTimer(VfxTimer *bufTimer);
    VfxBool isPDL() const;

protected:
    enum PlayerState
    {
        UNINIT,
        SEEKING,
        PLAYING,        // Buffer Ready and play() is called
    };

    U64 m_startingTimeHint;
    PlayerState m_state;
    int m_originalCodecPlaybackMode;  // Stores codec option, for restore.

private:
    class VappGalleryPDLOpenData : public VfxBase
    {
    public:
        MDI_RESULT m_bufferOpenResult;  // for local PDL, delay video open result
    };
    class VappGalleryPDLPlayData : public VfxBase
    {
    public:
        // These are parameters of VappGalleryMDIVideoAdaptor::play
        VfxVideoFrame *videoFrame;
        VfxVideoFrame *subtitleFrame;
        mdi_video_info_struct videoInfo;
    };
	
    VfxBool m_isNonBlockingSeeking;
    typedef MDI_RESULT (*PFN_MDI_CLOSE_FUNC)(void);
    PFN_MDI_CLOSE_FUNC m_closeFunc;
	VfxTimer *m_bufferTimer;        // for local PDL file, we need to wait for 6-sec buffering before playback
    VappGalleryPDLOpenData *m_bufferOpenData;
    VappGalleryPDLPlayData *m_bufferPlayData;

    mdi_video_info_struct m_videoInfo;
    VappVideoPlayerInputSource m_source;
};


class VappGalleryMDIStreamingAdaptor : public VappMDIAdaptor
{
public:
    VappGalleryMDIStreamingAdaptor();
    virtual void onDeinit();

    virtual MDI_RESULT openVideo(const VappVideoPlayerInputSource &input);
    virtual MDI_RESULT closeVideo();
    virtual VfxBool getOpenedVideo(VappVideoPlayerInputSource &input);

    virtual MDI_RESULT play(VfxVideoFrame *videoFrame,              // video frame. CAN be NULL for audio-only case
                            VfxVideoFrame *subtitleFrame,           // subtitle. Can be NULL in no subtitle case
                           const mdi_video_info_struct &videoInfo  // video info to be played.
                            );
    virtual MDI_RESULT stop();

    virtual MDI_RESULT getCurrentPlayTime(U64 &time);

    virtual VfxBool canGetStillFrame();
    virtual VfxBool mustPlayAfterSeek();
    virtual MDI_RESULT seekAndGetFrame(U64 time, GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer = NULL);
    virtual MDI_RESULT blockingSeekAndGetFrame(U64 time, GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer = NULL);
    virtual MDI_RESULT blockingGetFrame(GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer = NULL);
    virtual VfxBool canSeek();
    virtual VfxBool canSeekWithoutBuffering();
    virtual MDI_RESULT getSeekableRegion(U64 &seekableRegion);
    virtual MDI_RESULT seek(U64 time);
    virtual MDI_RESULT blockingSeek(U64 time);
    virtual VfxBool canGetKeyFrame();
    virtual MDI_RESULT getKeyFrameTime(const U64 refrenceTime, U64 &keyFrameTime);

    virtual VfxBool canDisconnect();
    virtual MDI_RESULT disconnect();
    virtual kal_int8 releaseBearer();

    virtual void disableNextDRMConsumption();

    virtual VfxBool changeVideoScreenMode(
                    const U8 mdiScreenMode,
                    VfxVideoFrame *videoFrame,
                    VfxVideoFrame *subtitleFrame,
                    const VfxBool needPausedResume,
                    const VfxBool isAudioOnly);

    // 3D anaglyph support
    virtual VfxBool canSwitchTo3DTrack(const mdi_video_info_struct &videoInfo, const VfxBool swtchTo3D);
    virtual VfxBool switchTo3DTrack(const mdi_video_info_struct &videoInfo, const VfxBool swtchTo3D);

protected:
    // MDI Streaming have strict rule for States,
    // so we must maintain the state to prevent assertion.
    enum StreamingState
    {
        UNINIT,
        INITED,
        CONNECTING,     // after connect() is sucess, before connect callback
        CONNECTED,      // after connect callback, and after stop() is called
        BUFFERING,      // after Start buffering
        BUFFERED,       // Buffer Ready, but did not play()
        PLAYING,        // Buffer Ready and play() is called
    };

    MDI_RESULT connect();
    MDI_RESULT createStreamingConnection();
    static mmi_ret onDelayConnectAfterBearerReleased(mmi_event_struct *param);
    mmi_ret handleDelayConnectAfterBearerReleased(mmi_event_struct *param);
    kal_uint32 getStreamingAccountId();
    void setIsDelayConnectAfterBearerReleased(const VfxBool flag);
    VfxBool getIsDelayConnectAfterBearerReleased() const;
    void setHadReleasedBearer(const VfxBool flag);
    VfxBool getHadReleasedBearer() const;

    static void onStreamConnected(MDI_RESULT ret, mdi_video_info_struct *video_info, void *user_data);
    virtual void handleStreamConnectResult(MDI_RESULT ret, mdi_video_info_struct *video_info);

    static void onStreamBuffered(MDI_RESULT ret, mdi_video_info_struct *video_info, void *user_data);
    virtual void handleStreamBufferResult(MDI_RESULT ret, mdi_video_info_struct *video_info);

    virtual void handlePlayFinished(MDI_RESULT ret);

    static const VfxMsec BUFFER_POLLING_INTERVAL = 200;
    void onBufferingTick(VfxTimer *sender);

protected:
    VfxBool m_isRTSPLink;
    VfxBool m_isBuffered;
    VfxTimer *m_bufferTimer;    // used to poll buffer status
    StreamingState m_state;     // decides what resource has allocated
    U64 m_startingTimeHint;     // Hint for initial buffer time
    VfxWString m_path;
    VappVideoPlayerInputSource m_source;
    mdi_video_info_struct m_videoInfo; // records video info
    VfxBool m_isDelayConnectAfterBearerReleased;
    VfxBool hadReleasedBearer;
};

/*****************************************************************************
 * VappMDIAdaptor Implementation
 *****************************************************************************/
VappMDIAdaptor::VappMDIAdaptor():
    m_parentComponent(NULL),
    m_appId(NULL),
    m_allowScrolling(VFX_TRUE),
    m_subtitleInfoIndex(VAPP_VIDEO_PLAYER_COMPONENT_DEFAULT_SUBTITLE_INFO_INDEX)
{
}

void VappMDIAdaptor::config(VappVideoPlayerComponent *parent,
                            VfxId appId,
                            VfxBool allowScrolling,
                            const VappVideoPlayerPlayOption &option,
                            VfxBool is3DAnaglyphMode)
{
    m_parentComponent = parent;
    m_appId = appId;
    m_allowScrolling = allowScrolling;
    m_option = option;
    m_is3DAnaglyphMode = is3DAnaglyphMode;
}

VfxBool VappMDIAdaptor::isPlaying()
{
    // mdi_video_is_playing() works on both video and streaming
    return (MMI_TRUE == mdi_video_is_playing());
}

void VappMDIAdaptor::onPlayFinished(MDI_RESULT ret, void *user_data)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_BASE_ON_PLAY_FINISHED, ret);
    VappMDIAdaptor *pThis = (VappMDIAdaptor*)user_data;
    if(NULL == pThis)
    {
        VFX_DEV_ASSERT(VFX_FALSE);
        return;
    }

    pThis->handlePlayFinished(ret);
    return;
}

VappMDIAdaptor::VideoOpenSignal& VappMDIAdaptor::getVideoOpenSignal()
{
    return m_signalVideoOpen;
}

VappMDIAdaptor::PlayFinishSignal& VappMDIAdaptor::getPlayFinishSignal()
{
    return m_signalPlayFinish;
}

VappMDIAdaptor::SeekDoneSignal& VappMDIAdaptor::getSeekDoneSignal()
{
    return m_signalSeekDone;
}

VfxS32 VappMDIAdaptor::querySubtitleTrackCount(const mdi_video_info_struct &videoInfo) const
{
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_BASE_QUERY_SUBTITLE_TRACK_COUNT, videoInfo.subtitle_num);
    return videoInfo.subtitle_num;
#else
    return 0;
#endif
}

VfxBool VappMDIAdaptor::isValidSubtitleInfoIndex(const mdi_video_info_struct &videoInfo, const VfxS32 infoIndex) const
{
    const VfxS32 trackNum = querySubtitleTrackCount(videoInfo);
    return ((0 < trackNum) && (-1 < infoIndex) && (infoIndex < trackNum));
}

VfxBool VappMDIAdaptor::queryMDISubtitleInfo(const mdi_video_info_struct &videoInfo,
                                                  const VfxS32 infoIndex,
                                                  U32 &trackIndex,
                                                  U32 &languageIso) const
{
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    if(isValidSubtitleInfoIndex(videoInfo, infoIndex))
    {
        trackIndex = videoInfo.subtitle_info[infoIndex].track_index;
        languageIso= videoInfo.subtitle_info[infoIndex].language;
        return VFX_TRUE;
    }
#endif
    trackIndex = 0;
    languageIso = 0;
    return VFX_FALSE;
}

VfxBool VappMDIAdaptor::querySubtitleLanguageName(const mdi_video_info_struct &videoInfo,
                                                           const VfxS32 infoIndex,
                                                           VfxWString &name) const
{
    U32 trackIndex  = 0;
    U32 languageIso = 0;
    PU8 languageName = NULL;
    name = VFX_WSTR_EMPTY;
    if(queryMDISubtitleInfo(videoInfo, infoIndex, trackIndex, languageIso))
    {
        mmi_li_get_lang_name(languageIso, &languageName);
        name = VFX_WSTR_MEM((VfxWChar *)languageName);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxBool VappMDIAdaptor::querySubtitleInfoIndexByLCC(const mdi_video_info_struct &videoInfo,
                                                            PU8 targetLCC,
                                                            VfxS32 &infoIndex) const
{
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    infoIndex = 0;
    for(VfxS32 i = 0; i < querySubtitleTrackCount(videoInfo); i++)
    {
        U32 iso = videoInfo.subtitle_info[i].language;
        PU8 icc = NULL;
        mmi_li_get_lcc(iso, &icc);
        if(targetLCC == icc)
        {
            infoIndex = i;
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif
}

VfxBool VappMDIAdaptor::checkAndFixToValidSubtitleInfoIndex(const mdi_video_info_struct &videoInfo,
                                                                     const VfxS32 infoIndex,
                                                                     VfxS32 &validInfoIndex) const
{
    if(isValidSubtitleInfoIndex(videoInfo, infoIndex))
    {
        // if it is the valid subtitle info index, we do not need to fix it
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_BASE_FIX_AND_CHECK_SUBTITLE_INFO_INDEX, infoIndex);
        validInfoIndex = infoIndex;
        return VFX_TRUE;
    }

    const VfxS32 subtitleCount = querySubtitleTrackCount(videoInfo);
    if(0 >= subtitleCount)
    {
        // there is no subtitle track, return fix failed
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_BASE_FIX_AND_CHECK_SUBTITLE_INFO_INDEX_ERR, infoIndex);
        return VFX_FALSE;
    }


    // for invalid subtitle info index, fix to the one with same LCC of phone as possible
    // otherwise, fix as 0 (1st info index) defaultly
    PU8 phoneLCC = NULL;
    mmi_li_Get_Current_LCC(&phoneLCC);  //get phone current language country code
    if(querySubtitleInfoIndexByLCC(videoInfo, phoneLCC, validInfoIndex))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_BASE_FIX_AND_CHECK_SUBTITLE_INFO_INDEX, infoIndex, 1, validInfoIndex);
        return VFX_TRUE;
    }

    validInfoIndex = 0;
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_BASE_FIX_AND_CHECK_SUBTITLE_INFO_INDEX, infoIndex, 0, validInfoIndex);
    return VFX_TRUE;
}

/*****************************************************************************
 * VappGalleryMDIVideoAdaptor Implementation
 *****************************************************************************/
VappGalleryMDIVideoAdaptor::VappGalleryMDIVideoAdaptor():
    m_startingTimeHint(0),
    m_state(UNINIT),
	m_originalCodecPlaybackMode(0),
    m_isNonBlockingSeeking(VFX_FALSE),
    m_closeFunc(NULL),
    m_bufferTimer(NULL),
    m_bufferOpenData(NULL),
    m_bufferPlayData(NULL)
{
    kal_mem_set(&m_videoInfo, 0, sizeof(m_videoInfo));
}

void VappGalleryMDIVideoAdaptor::onDeinit()
{
    closeVideo();

    VappMDIAdaptor::onDeinit();
}

MDI_RESULT VappGalleryMDIVideoAdaptor::closeVideo()
{
#ifdef __VAPP_VIDEO_PLAYER_SLEEP_VIDEO__
    // restore CPU throttle
    mdi_video_ply_set_sleep_time(0, 0);
#endif

    if(m_isNonBlockingSeeking)
    {
        mdi_video_ply_stop_non_block_seek();
        m_isNonBlockingSeeking = VFX_FALSE;
    }

    if(PLAYING == m_state)
    {
         stop();
    }

    MDI_RESULT res = MDI_RES_VDOPLY_SUCCEED;
    if(m_closeFunc)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_VIDEO_CLOSE, m_closeFunc);
        res = m_closeFunc();
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_VIDEO_CLOSE_WITHOUT_MPL_CLOSE);
    }
    m_closeFunc = NULL;

    if(m_option.isWallpaperScenario && m_option.disableAudio)
    {
        // restore codec mode
        mply_codec_custom_query(MPLY_CODEC_CUSTOM_FORMAT_MP4,
                                MPLY_CODEC_CUSTOM_ITEM_SET_PLAYBACK_MODE,
                                m_originalCodecPlaybackMode);
    }

    if(m_bufferTimer)
    {
        VFX_OBJ_CLOSE(m_bufferTimer);
    }  
    VFX_FREE_MEM(m_bufferOpenData);
    VFX_FREE_MEM(m_bufferPlayData);

    kal_mem_set(&m_videoInfo, 0, sizeof(m_videoInfo));
    return res;
}

VfxBool VappGalleryMDIVideoAdaptor::getOpenedVideo(VappVideoPlayerInputSource &input)
{
    input = m_source;
    return VFX_TRUE;
}

MDI_RESULT VappGalleryMDIVideoAdaptor::openVideo(const VappVideoPlayerInputSource &input)
{
    m_startingTimeHint = input.m_startingTimeHint;
    m_source = input;

    if(m_option.isWallpaperScenario)
    {
        mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_MPEG4);
        // wallpaper + disableAudio ==> force lossless mode
        if(m_option.disableAudio)
        {
            // backup codec mode
            m_originalCodecPlaybackMode = mply_codec_custom_query(MPLY_CODEC_CUSTOM_FORMAT_MP4,
                                                                  MPLY_CODEC_CUSTOM_ITEM_GET_PLAYBACK_MODE,
                                                                  0);
            // set codec mode
            mply_codec_custom_query(MPLY_CODEC_CUSTOM_FORMAT_MP4,
                                    MPLY_CODEC_CUSTOM_ITEM_SET_PLAYBACK_MODE,
                                    MPLY_CODEC_CUSTOM_PLAYBACK_MODE_QUALITY);
        }
    }
    else
    {
#ifdef __COSMOS_MMI_PACKAGE__
        // if not in Gallery APP, always allow CIF resolution only.
        const VfxBool isGalleryAPP = (m_appId >= VAPP_GALLERY &&
                                      m_appId < mmi_res_get_app_max(VAPP_GALLERY));
        const VfxBool isGalleryImageViewerAPP = (m_appId >= VAPP_GALLERY_IMAGE_VIEWER &&
                                                 m_appId < mmi_res_get_app_max(VAPP_GALLERY_IMAGE_VIEWER));
        const VfxBool isGalleryVideoPlayerAPP = (m_appId >= VAPP_GALLERY_VIDEO_PLAYER &&
                                          m_appId < mmi_res_get_app_max(VAPP_GALLERY_VIDEO_PLAYER));
        const VfxBool isFullResolution = (m_option.supportFullResolution || isGalleryAPP || isGalleryVideoPlayerAPP || isGalleryImageViewerAPP);
        if(!isFullResolution)
        {
            mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_CIF);
        }
        else if(m_option.supportSubtitle)
        {
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
            mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_DEFAULT_N_SUBTITLE);
#endif /*__MMI_VIDEO_SUBTITLE_SUPPORT__*/
        }
        
        #ifdef __MMI_VIDEO_PDL_YOUTUBE__
        const VfxBool isYouTubePlayerApp = (m_appId >= VAPP_GALLERY_YOUTUBE_PGDL_PLAYER &&
                                            m_appId < mmi_res_get_app_max(VAPP_GALLERY_YOUTUBE_PGDL_PLAYER));
        if(isYouTubePlayerApp)
        {
            mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_QVGA_MPEG4SP);
        }
        #endif
#endif
    }

    MDI_RESULT res = MDI_RES_VDOPLY_SUCCEED;
    if(input.isResource())
    {
        // resource video can only blocking open
        // TODO: in 11B, close_clip_id causes compile error
        m_closeFunc = mdi_video_ply_close_file;
        res = mdi_video_ply_open_clip_id(
                                  m_appId,
                                  input.m_resId,
                                  &m_videoInfo);
        if(MDI_RES_VDOPLY_SUCCEED == res)
        {

            vfxPostInvoke2(this, &VappGalleryMDIVideoAdaptor::handleVideoOpenResult, res, (mdi_video_info_struct*)NULL);
        }
        else
        {
            m_closeFunc = NULL;
        }
    }
    else if(m_option.isWallpaperScenario)
    {
        // for wallpaper, we use blocking open & only support MP4 video
        filetypes_file_type_enum type = srv_fmgr_types_find_type_by_filename_str(input.m_path.getBuf());
        if(FMGR_TYPE_MP4 != type
           && FMGR_TYPE_3GP != type
           && FMGR_TYPE_AVI != type
           #ifdef __MKV_FILE_FORMAT_SUPPORT__
           && FMGR_TYPE_MKV != type
           && FMGR_TYPE_WEBM != type
           #endif
          )
        {
            res = MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT;
        }
        else
        {
            m_closeFunc = mdi_video_ply_close_clip_file;
            res = mdi_video_ply_open_clip_file(
                                        m_appId,
                                        (const CHAR*)input.m_path.getBuf(),
                                        &m_videoInfo);
            if(MDI_RES_VDOPLY_SUCCEED == res)
            {
                vfxPostInvoke2(this, &VappGalleryMDIVideoAdaptor::handleVideoOpenResult, res, (mdi_video_info_struct*)NULL);
            }
            else
            {
                m_closeFunc = NULL;
            }
        }
    }
    else if(input.isProgressiveDownload())
    {
        #ifdef __MMI_VIDEO_PDL__
        // progressive download
        m_closeFunc = mdi_video_progressive_close_file;
        res = mdi_video_progressive_open_file(
                                    m_appId,
                                    (const CHAR*)input.m_path.getBuf(),
                                    &onVideoOpenResult,
                                    this);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PDL_OPEN, res);
        VFX_OBJ_CLOSE(m_bufferTimer);
        VFX_OBJ_CREATE(m_bufferTimer, VfxTimer, this);
        const VfxMsec PGDL_BUFFER_INTERVAL = 500;
        m_bufferTimer->setDuration(PGDL_BUFFER_INTERVAL);    // use longer interval to prevent MED too busy
        m_bufferTimer->setStartDelay(PGDL_BUFFER_INTERVAL);
        m_bufferTimer->m_signalTick.connect(this, &VappGalleryMDIVideoAdaptor::onBufferTimer);
        #else
        VFX_ASSERT(0);  // why use PDL without PDL support?
        #endif
    }
    else
    {
        // general case, use async open.
        m_closeFunc = mdi_video_ply_close_file;
        res = mdi_video_ply_open_file(
                                    m_appId,
                                    (const CHAR*)input.m_path.getBuf(),
                                    &onVideoOpenResult,
                                    this);
    }

    // Throttle CPU usage, must be called after open
    if(m_option.isWallpaperScenario)
    {
#ifdef __VAPP_VIDEO_PLAYER_SLEEP_VIDEO__
        mdi_video_ply_set_sleep_time(10, 1);
#endif
    }

    return res;
}

void VappGalleryMDIVideoAdaptor::onVideoOpenResult(MDI_RESULT ret, mdi_video_info_struct *video_info, void *user_data)
{
    VappGalleryMDIVideoAdaptor *pThis = (VappGalleryMDIVideoAdaptor*)user_data;
    if(NULL == pThis)
    {
        VFX_DEV_ASSERT(VFX_FALSE);
        return;
    }

    return pThis->handleVideoOpenResult(ret, video_info);
}

void VappGalleryMDIVideoAdaptor::handleVideoOpenResult(MDI_RESULT ret, mdi_video_info_struct *video_info)
{
    // if "open" failed, emit directly
    if(MDI_RES_VDOPLY_SUCCEED != ret)
    {
        // open fail, no need to close.
        // otherwise we may close previous video session.
        m_closeFunc = NULL;
        m_signalVideoOpen.emit(ret, video_info);
        return;
    }

    if(m_option.isWallpaperScenario)
    {
#ifdef __COSMOS_MMI_PACKAGE__
        // check for proper video size for COSMOS projects;
        // for FTE projects, since wallpaper preview
        // is using Category 225, we do not check
        // dimension to prevent unsync behavior
        const VfxS32 MAX_WALLPAPER_DIM = 800;
        if(m_videoInfo.width > MAX_WALLPAPER_DIM ||
           m_videoInfo.height > MAX_WALLPAPER_DIM)
        {
            m_signalVideoOpen.emit(MDI_RES_VDOPLY_ERR_INVALID_RESOULTION, &m_videoInfo);
            return;
        }
#endif
        if(MDI_VIDEO_TRACK_A_ONLY == m_videoInfo.track ||
           m_videoInfo.width == 0 ||
           m_videoInfo.height == 0)
        {
            m_signalVideoOpen.emit(MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT, &m_videoInfo);
            return;
        }
    }

    // set video info for non-block seek during open
    if(video_info)
    {
        m_videoInfo = *video_info;
    }

   
    #ifdef __MMI_VIDEO_PDL__
    if(isPDL())
    {
        // for PDL, make sure we
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PDL_HANDLE_OPEN_RESULT, ret);
        VFX_ASSERT(m_bufferTimer);
        S32 percentage = 0;
        MDI_RESULT bufResult = mdi_video_progressive_get_buf_percentage(&percentage);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PDL_HANDLE_GET_BUF_PERCENTAGE, bufResult);
        if(MDI_RES_VDOPLY_SUCCEED != bufResult)
        {
            // treat as file I/O error
            ret = MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
        }
        else
        {
            if(percentage != 100)
            {
                // wait for buffer finish before callback
                m_bufferTimer->start();
                // store parameter to invoke handleVideoOpenResult again
                VFX_FREE_MEM(m_bufferOpenData);
                VFX_FREE_MEM(m_bufferPlayData);
                VFX_ALLOC_MEM(m_bufferOpenData, sizeof(VappGalleryPDLOpenData), this);
                m_bufferOpenData->m_bufferOpenResult = ret;
                return;
            }
            else
            {
                m_bufferTimer->stop();
            }
        }
    }
    #endif
    

    if(m_option.isWallpaperScenario)
    {
        if(!getIs3DAnaglyphMode() && canSwitchTo3DTrack(m_videoInfo, VFX_TRUE) && !canSwitchTo3DTrack(m_videoInfo, VFX_FALSE))
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_VIDEO_3D_VIDEO_IN_WP_SCENRAIO);
            setIs3DAnaglyphMode(VFX_TRUE);
        }
    }

    // set anaglyph video track
    VfxBool switchRes = switchTo3DTrack(m_videoInfo, getIs3DAnaglyphMode());
    if(!switchRes)
    {
        setIs3DAnaglyphMode(!getIs3DAnaglyphMode());
    }

    // set subtitle track and check if we should turns on subtitle display
    if(m_option.supportSubtitle)
    {
        const VfxBool subtitleRes = switchSubtitleTrack(m_videoInfo, getSubtitleInfoIndex());
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_HANDLE_VIDEO_OPEN_RESULT_SUBTITLE_RES, subtitleRes);
        mdi_video_ply_set_subtitle_font_size(FONT_SIZE);
        if(!subtitleRes)
        {
            // reset to default subtitle track to indicate err
            setSubtitleInfoIndex(VAPP_VIDEO_PLAYER_COMPONENT_DEFAULT_SUBTITLE_INFO_INDEX);
        }
    }

    // note some files are not seekable in FLV,
    // in such case, player should play from 0 after any interupt
    if(MMI_FALSE == m_videoInfo.is_seekable)
    {
        m_startingTimeHint = 0;
    }

    // seek to start time
    if(0 != m_startingTimeHint)
    {
        MDI_RESULT res = mdi_video_ply_non_block_seek(m_startingTimeHint,
                                                     &onNonBlockSeekingFinishedDuringOpen,
                                                     this);

        if(MDI_RES_VDOPLY_SUCCEED == res)
        {
            m_isNonBlockingSeeking = VFX_TRUE;
        }
        else
        {
            // considering there are some video which seek failed partly,
            // please note error icon is set only when "open" file failed (not include the seek result during open)
            // in other words, no matter what player do blockingSeek(0) or non-blockSeek during file open,
            // we do not process the err code for it
            // the error code will be handel while play file
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_VIDEO_NON_BLOCK_SEEK_DURING_OPEN_FAILED, res);
            m_signalVideoOpen.emit(MDI_RES_VDOPLY_SUCCEED, &m_videoInfo);
        }
    }
    else
    {
        // seek to starting pos
        blockingSeek(m_startingTimeHint);

        // notify component(ret must be MDI_RES_VDOPLY_SUCCEED)
        m_signalVideoOpen.emit(ret, &m_videoInfo);
    }
    return;
}

VfxBool VappGalleryMDIVideoAdaptor::isPDL() const
{
#ifdef __MMI_VIDEO_PDL__
    // if m_bufferTimer exists, this means we're PDL
    return (NULL != m_bufferTimer);
#else
    return VFX_FALSE;
#endif
}

void VappGalleryMDIVideoAdaptor::onBufferTimer(VfxTimer *bufTimer)
{
#ifdef __MMI_VIDEO_PDL__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PDL_HANDLE_ON_BUF_TIMER);
    S32 percentage = 0;
    MDI_RESULT res = mdi_video_progressive_get_buf_percentage(&percentage);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PDL_HANDLE_ON_BUF_TIMER_GET_BUF_PERCENTAGE_DETAIL, res, percentage);

    if(m_bufferOpenData)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PDL_HANDLE_ON_BUF_TIMER_WITH_BUF_DATA);
        // delay open case
        if(MDI_RES_VDOPLY_SUCCEED != res)
        {
            handleVideoOpenResult(MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED, NULL);
        }
        else
        {
            if(percentage == 100)
            {
                // pass the stored result back to handleVideoOpenResult
                m_bufferTimer->stop();
                handleVideoOpenResult(m_bufferOpenData->m_bufferOpenResult, NULL);
            }
            else
            {
                // keep waiting
                m_bufferTimer->start();
            }
        }
    }
    
    if(m_bufferPlayData)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PDL_HANDLE_ON_BUF_TIMER_WITH_BUF_DATA);
        // delay open case
        if(MDI_RES_VDOPLY_SUCCEED != res)
        {
            handlePlayFinished(MDI_RES_VDOPLY_ERR_PLAY_FAILED);
        }
        else
        {
            if(percentage == 100)
            {
                m_bufferTimer->stop();
                // play(m_bufferPlayData->videoFrame, m_bufferPlayData->subtitleFrame, m_bufferPlayData->videoInfo);
                m_signalSeekDone.emit(res, NULL);
            }
            else
            {
                // keep waiting
                m_bufferTimer->start();
            }
        }
    }
    
#endif
}

void VappGalleryMDIVideoAdaptor::onNonBlockSeekingFinishedDuringOpen(MDI_RESULT ret, void *user_data)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_VIDEO_ON_NON_BLOCK_SEEK_DURING_OPEN, ret);
    VappGalleryMDIVideoAdaptor *pThis = (VappGalleryMDIVideoAdaptor*)user_data;
    if(NULL == pThis)
    {
        VFX_DEV_ASSERT(VFX_FALSE);
        return;
    }

    return pThis->handleNonBlockSeekingFinishedDuringOpen(ret, &(pThis->m_videoInfo));
}

void VappGalleryMDIVideoAdaptor::handleNonBlockSeekingFinishedDuringOpen(MDI_RESULT ret, mdi_video_info_struct *video_info)
{
    m_isNonBlockingSeeking = VFX_FALSE;

    // considering there are some videos which seek failed in partly segment,
    // please note error icon is set only when "open" file failed (not include the seek result during open)
    // in other words, no matter what player do blockingSeek(0) or non-blockSeek during file open,
    // we do not process the err code for it
    // the error code will be handled while playing file
    m_signalVideoOpen.emit(MDI_RES_VDOPLY_SUCCEED, video_info);

    return;
}

void VappGalleryMDIVideoAdaptor::handlePlayFinished(MDI_RESULT ret)
{
    m_signalPlayFinish.emit(ret);
}

MDI_RESULT VappGalleryMDIVideoAdaptor::play(VfxVideoFrame *videoFrame,
                                            VfxVideoFrame *subtitleFrame,
                                            const mdi_video_info_struct &videoInfo)
{
    if(m_allowScrolling)
    {
        mdi_video_ply_enable_partial_display();
    }

    #ifdef __MMI_VIDEO_PDL__
    if(isPDL())
    {
        S32 percentage = 0;
        MDI_RESULT percentageRes = mdi_video_progressive_get_buf_percentage(&percentage);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PDL_HANDLE_PLAY_GET_BUF_PERCENTAGE_DETAIL, percentageRes, percentage);
        if(MDI_RES_VDOPLY_SUCCEED != percentageRes)
        {
            return MDI_RES_VDOPLY_ERR_PLAY_FAILED;
        }
        else
        {
            if(percentage < 100)
            {
                // we copy videoInfoData because videoInfo may be passed by m_bufferPlayData
                mdi_video_info_struct videoInfoData = videoInfo;
                VFX_FREE_MEM(m_bufferPlayData);
                VFX_FREE_MEM(m_bufferOpenData);
                VFX_ALLOC_MEM(m_bufferPlayData, sizeof(VappGalleryPDLPlayData), this);
                m_bufferPlayData->videoFrame = videoFrame;
                m_bufferPlayData->subtitleFrame = subtitleFrame;
                m_bufferPlayData->videoInfo = videoInfoData;
                m_bufferTimer->start();
                return MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH;
            }
            // otherwise it's 100 percent, we can start playback
        }
    }
    #endif

    MDI_RESULT res = _playEx(videoFrame, subtitleFrame, videoInfo);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_VIDEO_PLAY, res);

    if(0 <= res)
    {
        m_state = PLAYING;
    }

    return res;
}

MDI_RESULT VappGalleryMDIVideoAdaptor::stop()
{
    if(m_isNonBlockingSeeking)
    {
        mdi_video_ply_stop_non_block_seek();
        m_isNonBlockingSeeking = VFX_FALSE;
    }

    #ifdef __MMI_VIDEO_PDL__
    if(isPDL())
    {
        m_bufferTimer->stop();
    }
    #endif

    return mdi_video_ply_stop();
}

MDI_RESULT VappGalleryMDIVideoAdaptor::getCurrentPlayTime(U64 &time)
{
    SWLA_BEGIN("GCP");
    mdi_video_ply_get_cur_play_time(&time);
    SWLA_END("GCP");
    return MDI_RES_VDOPLY_SUCCEED;
}

VfxBool VappGalleryMDIVideoAdaptor::canSeek()
{
    return VFX_TRUE;
}

VfxBool VappGalleryMDIVideoAdaptor::canSeekWithoutBuffering()
{
    return VFX_TRUE;
}

VfxBool VappGalleryMDIVideoAdaptor::mustPlayAfterSeek()
{
    return VFX_FALSE;
}

void VappGalleryMDIVideoAdaptor::onSeekFinished(MDI_RESULT ret, void *user_data)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_VIDEO_ON_SEEK_FINISHED_RET_D, ret);
    VappGalleryMDIVideoAdaptor *pThis = (VappGalleryMDIVideoAdaptor*)user_data;

    if(NULL == pThis)
    {
        VFX_DEV_ASSERT(VFX_FALSE);
        return;
    }

    return pThis->handleSeekFinishedResult(ret);
}

void VappGalleryMDIVideoAdaptor::handleSeekFinishedResult(MDI_RESULT res)
{
    m_isNonBlockingSeeking = VFX_FALSE;
    m_signalSeekDone.emit(res, NULL);
    return;
}

MDI_RESULT VappGalleryMDIVideoAdaptor::blockingSeek(U64 time)
{
    #ifdef __MMI_VIDEO_PDL__
    if(isPDL())
    {
        m_bufferTimer->stop();
    }
    #endif
    return mdi_video_ply_seek(time);
}

MDI_RESULT VappGalleryMDIVideoAdaptor::seek(U64 time)
{
    #ifdef __MMI_VIDEO_PDL__
    if(isPDL())
    {
        m_bufferTimer->stop();
    }
    #endif
    
    U64 seekableRegion = 0;
    if(MDI_RES_VDOPLY_SUCCEED == getSeekableRegion(seekableRegion))
    {
        time = vfxMin(time, seekableRegion);
    }
    
    if (m_state == SEEKING)
    {
        mdi_video_ply_stop_non_block_seek();
    }

    MDI_RESULT res = mdi_video_ply_non_block_seek(time,
                                                  &onSeekFinished,
                                                  this);
    if(MDI_RES_VDOPLY_SUCCEED == res)
    {
        m_state = SEEKING;
        m_isNonBlockingSeeking = VFX_TRUE;
    }

    return res;
}

MDI_RESULT VappGalleryMDIVideoAdaptor::getSeekableRegion(U64 &seekableRegion)
{
    if(!canSeek())
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

    if(0 == m_videoInfo.total_time_duration)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

    #ifdef __MMI_VIDEO_PDL__
    if(isPDL())
    {
        // always clamp to max play time
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PDL_GET_SEEK_REGION);
        #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MPT", SA_start);
        #endif
        MDI_RESULT maxResult = mdi_video_progressive_get_max_play_time(&seekableRegion);
        #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MPT", SA_stop);
        #endif
        return maxResult;
    }
    #endif

    seekableRegion = m_videoInfo.total_time_duration;
    return MDI_RES_VDOPLY_SUCCEED; 
}

VfxBool VappGalleryMDIVideoAdaptor::canGetStillFrame()
{
    return VFX_TRUE;
}

MDI_RESULT VappGalleryMDIVideoAdaptor::blockingSeekAndGetFrame(U64 time, GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer)
{
    return _seekEx(time, VFX_TRUE, VFX_TRUE, videoLayer, subtitleLayer, NULL, NULL);
}

MDI_RESULT VappGalleryMDIVideoAdaptor::blockingGetFrame(GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_VIDEO_BLOCKING_GET_FRAME,  videoLayer, subtitleLayer);
    return _getFrameEx(videoLayer, subtitleLayer);
}

MDI_RESULT VappGalleryMDIVideoAdaptor::seekAndGetFrame(U64 time, GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer)
{
    if (m_state == SEEKING)
    {
        mdi_video_ply_stop_non_block_seek();
    }

    MDI_RESULT res = _seekEx(time,
                             VFX_FALSE,
                             VFX_TRUE,
                             videoLayer,
                             subtitleLayer,
                             &VappGalleryMDIVideoAdaptor::onSeekFinished,
                             this);

    if(MDI_RES_VDOPLY_SUCCEED == res)
    {
        m_state = SEEKING;
        m_isNonBlockingSeeking = VFX_TRUE;
    }

    return res;
}

VfxBool VappGalleryMDIVideoAdaptor::canGetKeyFrame()
{
    return VFX_TRUE;
}

MDI_RESULT VappGalleryMDIVideoAdaptor::getKeyFrameTime(const U64 refrenceTime, U64 &keyFrameTime)
{
    MDI_RESULT res = mdi_video_ply_get_key_frame_time(refrenceTime, MDI_VIDEO_SEARCH_DIR_BACKWARD, &keyFrameTime);
    if(MDI_RES_VDOPLY_SUCCEED != res)
    {
        keyFrameTime = 0;
    }
    return res;
}

VfxBool VappGalleryMDIVideoAdaptor::canDisconnect()
{
    return VFX_FALSE;
}

MDI_RESULT VappGalleryMDIVideoAdaptor::disconnect()
{
    return MDI_RES_VDOPLY_ERR_FAILED;
}

void VappGalleryMDIVideoAdaptor::disableNextDRMConsumption()
{
#ifdef __DRM_SUPPORT__
    mdi_video_ply_drm_disable_consume_count();
#endif
}

VfxBool VappGalleryMDIVideoAdaptor::changeVideoScreenMode(
                    const U8 mdiScreenMode,
                    VfxVideoFrame *videoFrame,
                    VfxVideoFrame *subtitleFrame,
                    const VfxBool needPausedResume,
                    const VfxBool isAudioOnly)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_VIDEO_CHANGE_SCREEN_MODE);

    if(needPausedResume)
    {
        mdi_video_ply_update_layer_pause();
    }

    mdi_video_ply_set_frame_mode(mdiScreenMode);

    if(needPausedResume && videoFrame)
    {
        _resumeEx(videoFrame, subtitleFrame, isAudioOnly);
    }

    return VFX_TRUE;
}

VfxBool VappGalleryMDIVideoAdaptor::canSwitchSubtitle() const
{
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    return VFX_TRUE;
#endif
    return VFX_FALSE;
}

VfxBool VappGalleryMDIVideoAdaptor::switchSubtitleTrack(const mdi_video_info_struct &videoInfo,
                                                        const VfxS32 infoIndex)
{
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    // make sure the track info is valid
    // note checkAndFixToValidSubtitleInfoIndex() implicitly check
    //      - if player supports subtitle
    //      - valid subtitle num and subtitle info index
    // and try to fix to valid info index for invalid case
    //  so we do not need to check again
    VfxS32 validInfoIndex = 0;
    if(checkAndFixToValidSubtitleInfoIndex(videoInfo, infoIndex, validInfoIndex))
    {
        // update to the valid subtitle info index
        setSubtitleInfoIndex(validInfoIndex);
        // set subtitle track to MDI video playback
        U32 trackIndex = videoInfo.subtitle_info[validInfoIndex].track_index;
        
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_VIDEO_SWITCH_SUBTITLE, validInfoIndex, infoIndex, trackIndex);
        mdi_video_ply_set_subtitle_track_index(trackIndex);
        return VFX_TRUE;
    }
#endif
    // fix failed, treat as switch failed,
    // change track info to default to indicated the switch err
    setSubtitleInfoIndex(VAPP_VIDEO_PLAYER_COMPONENT_DEFAULT_SUBTITLE_INFO_INDEX);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_VIDEO_SWITCH_SUBTITLE_FAILED);
    return VFX_FALSE;
}

VfxBool VappGalleryMDIVideoAdaptor::canSwitchTo3DTrack(const mdi_video_info_struct &videoInfo, const VfxBool swtchTo3D)
{
    mdi_video_track_type_enum targetType = swtchTo3D? MDI_VIDEO_TRACK_3D : MDI_VIDEO_TRACK_2D_NORMAL;
    VfxU32 trackIndex = 0;
    return queryMDIVideoTrackIndex(videoInfo, targetType, trackIndex);
}

VfxBool VappGalleryMDIVideoAdaptor::switchTo3DTrack(const mdi_video_info_struct &videoInfo,
                                                    const VfxBool swtchTo3D)
{
#ifdef __MMI_VIDEO_3D_ANAGLYPH__
    mdi_video_track_type_enum targetType = swtchTo3D? MDI_VIDEO_TRACK_3D : MDI_VIDEO_TRACK_2D_NORMAL;
    VfxU32 trackIndex = 0;
    if(queryMDIVideoTrackIndex(videoInfo, targetType, trackIndex))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_VIDEO_SWITCH_2D_3D_TRACK, swtchTo3D, trackIndex);
        MDI_RESULT res = mdi_video_ply_set_track_index(trackIndex);
        return VFX_TRUE;
    }
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif
}

VfxBool VappGalleryMDIVideoAdaptor::queryMDIVideoTrackIndex(const mdi_video_info_struct &videoInfo,
                                                                    const mdi_video_track_type_enum targetType,
                                                                    VfxU32 &trackIndex)
{
#ifdef __MMI_VIDEO_3D_ANAGLYPH__
    VfxBool isTargetTrackSupported = VFX_FALSE;
    for(VfxU8 i = 0; i < videoInfo.track_num; i++)
    {
        if(targetType == videoInfo.track_info[i].track_type)
        {
            trackIndex = videoInfo.track_info[i].track_index;
            isTargetTrackSupported = VFX_TRUE;
            break;
        }
    }

    return isTargetTrackSupported;
#else
    return VFX_FALSE;
#endif
}

MDI_RESULT VappGalleryMDIVideoAdaptor::_playEx(VfxVideoFrame *videoFrame,
                                                 VfxVideoFrame *subtitleFrame,
                                                 const mdi_video_info_struct &videoInfo)
{
    const VfxBool isAudioOnly = (NULL == videoFrame) || (MDI_VIDEO_TRACK_A_ONLY == videoInfo.track);
    const VfxBool hasSubtitle = (subtitleFrame ? VFX_TRUE : VFX_FALSE);

    // init play struct
    mdi_video_play_struct param;
    mdi_video_ply_get_default_play_setting(&param);
    // general part
    param.player_layer_handle  = (isAudioOnly ? NULL : videoFrame->getLayerHandle());
    param.blt_layer_flag       = (isAudioOnly ? NULL : videoFrame->getDisplayLayerFlag());
    param.play_layer_flag      = (isAudioOnly ? NULL : videoFrame->getHwLayerFlag());
    param.repeat_count         = (m_option.loopForever ? (U16)-1 : 1);
    param.is_visual_update     = (isAudioOnly ? MMI_FALSE : MMI_TRUE);
    param.is_play_audio        = (m_option.disableAudio ? MMI_FALSE : MMI_TRUE);
    param.audio_path           = getCurrentAudioPath();      // config audio output path. Use earphone if present
    param.rotate               = 0;                          // no rotation
    param.play_speed           = 100,                        // always use 1X playback
    param.play_finish_callback = &onPlayFinished;
    param.user_data            = this;
    // subtitle part
    param.subtitle_layer_handle = (hasSubtitle ? subtitleFrame->getLayerHandle() : NULL);
    param.subtitle_layer_flag   = (hasSubtitle ? subtitleFrame->getHwLayerFlag() : NULL);

    return mdi_video_ply_play_ex(&param);
}

MDI_RESULT VappGalleryMDIVideoAdaptor::_resumeEx(VfxVideoFrame *videoFrame,
                                                     VfxVideoFrame *subtitleFrame,
                                                     const VfxBool isAudioOnly)
{
    const VfxBool hasSubtitle = (subtitleFrame ? VFX_TRUE : VFX_FALSE);

    // init resume option
    mdi_video_update_layer_resume_struct param;
    mdi_video_ply_get_default_resume_setting(&param);
    // video part
    param.player_layer_handle  = (isAudioOnly ? NULL : videoFrame->getLayerHandle());
    param.blt_layer_flag       = (isAudioOnly ? NULL : videoFrame->getDisplayLayerFlag());
    param.play_layer_flag      = (isAudioOnly ? NULL : videoFrame->getHwLayerFlag());
    param.is_visual_update     = (isAudioOnly ? MMI_FALSE : MMI_TRUE);
    param.rotate               = 0;
    // subtitle part
    param.subtitle_layer_handle = (hasSubtitle ? subtitleFrame->getLayerHandle() : NULL);
    param.subtitle_layer_flag   = (hasSubtitle ? subtitleFrame->getHwLayerFlag() : NULL);
    return mdi_video_ply_update_layer_resume_ex(&param);
}

MDI_RESULT VappGalleryMDIVideoAdaptor::_seekEx(U64 time,
                                                  const VfxBool isBlocking,
                                                  const VfxBool shouldGetFrame,
                                                  GDI_HANDLE videoLayer,
                                                  GDI_HANDLE subtitleLayer,
                                                  mdi_seek_result_callback seekCallback,
                                                  void* userData)
{
    MMI_BOOL isHWLayer = MMI_FALSE;     
    gdi_layer_is_hw_update_layer(videoLayer, &isHWLayer);
    if(isHWLayer && shouldGetFrame)
    {
        MMI_TRACE(TRACE_GROUP_2,  TRC_VAPP_VIDEOCP_VIDEO_SEEK_EX_WAIT_RENDER);    
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->waitForRenderingComplete();
    }

    mdi_video_seek_struct param;
    mdi_video_ply_get_default_seek_setting(&param);

    // seek option
    param.time = time;
    param.blocking = (isBlocking ? MMI_TRUE : MMI_FALSE);
    param.seek_result_callback = seekCallback;
    param.user_data = userData;

    // get frame option
    param.get_frame = (shouldGetFrame ? MMI_TRUE : MMI_FALSE);
    param.frame.player_layer_handle = videoLayer;
    param.frame.subtitle_layer_handle = subtitleLayer;

    return mdi_video_ply_seek_ex(&param);
}

MDI_RESULT VappGalleryMDIVideoAdaptor::_getFrameEx(GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer)
{
    MMI_BOOL isHWLayer = MMI_FALSE;     
    gdi_layer_is_hw_update_layer(videoLayer, &isHWLayer);
    if(isHWLayer)
    {
        MMI_TRACE(TRACE_GROUP_2,  TRC_VAPP_VIDEOCP_VIDEO_GET_FRAME_EX_WAIT_RENDER);    
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->waitForRenderingComplete();
    }

    mdi_video_get_frame_struct param;
    mdi_video_ply_get_default_get_frame_setting(&param);

    param.player_layer_handle   = videoLayer;
    param.subtitle_layer_handle = subtitleLayer;

    return mdi_video_ply_get_frame_ex(&param);
}

/*****************************************************************************
 * VappGalleryMDIStreamingAdaptor Implementation
 *****************************************************************************/
#if defined(__MMI_VIDEO_STREAM__) && defined(__COSMOS_MMI_PACKAGE__)
VappGalleryMDIStreamingAdaptor::VappGalleryMDIStreamingAdaptor():
    m_state(UNINIT),
    m_bufferTimer(NULL),
    m_startingTimeHint(0),
    m_isBuffered(VFX_FALSE),
    m_isDelayConnectAfterBearerReleased(VFX_FALSE),
    hadReleasedBearer(VFX_FALSE)
{
    kal_mem_set(&m_videoInfo, 0, sizeof(m_videoInfo));
}

void VappGalleryMDIStreamingAdaptor::onDeinit()
{
    closeVideo();
    VappMDIAdaptor::onDeinit();
}

MDI_RESULT VappGalleryMDIStreamingAdaptor::closeVideo()
{
    // deregister CBM info
    VappGalleryStreamingSetting streamingSetting;
    const kal_uint32 accountId = streamingSetting.getActiveAccountId();
    const kal_uint8 cbmAppId = cbm_get_app_id(accountId);
    srv_cbm_deregister_bearer_info(cbmAppId);

    setIsDelayConnectAfterBearerReleased(VFX_FALSE);

    if(m_bufferTimer)
    {
        VFX_OBJ_CLOSE(m_bufferTimer);
        m_bufferTimer = NULL;
    }

    switch(m_state)
    {
    case BUFFERED:
    case BUFFERING:
    case PLAYING:
        stop();
        // do following actions
    case CONNECTED:
    case CONNECTING:
        mdi_video_stream_disconnect();
        // do following actions
    case INITED:
        mdi_video_stream_deinit();
        // do following actions
    case UNINIT:
    default:
        // do nothing
        break;
    }

    m_state = UNINIT;
    m_startingTimeHint = 0;
    kal_mem_set(&m_videoInfo, 0, sizeof(m_videoInfo));
    m_isBuffered = VFX_FALSE;
    return MDI_RES_VDOPLY_SUCCEED;
}

VfxBool VappGalleryMDIStreamingAdaptor::getOpenedVideo(VappVideoPlayerInputSource &input)
{
    input = m_source;
    return VFX_TRUE;
}

MDI_RESULT VappGalleryMDIStreamingAdaptor::openVideo(const VappVideoPlayerInputSource &input)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_OPEN);
    VFX_ASSERT(!input.isResource());

    closeVideo();

    m_startingTimeHint = input.m_startingTimeHint;
    m_source = input;

    MDI_RESULT res = mdi_video_stream_init(m_appId);

    // for ALL streaming videos, we limit to QVGA spec.
    mdi_video_stream_set_scenario(MDI_VIDEO_SCENARIO_QVGA);

    if(MDI_RES_VDOPLY_SUCCEED != res)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_INIT_FAIL_D, res);
        return res;
    }
    else
    {
        // update state if init ok
        m_state = INITED;
    }

    m_isRTSPLink = input.isRTSPLink();
    m_path = input.m_path;

    m_signalVideoOpen.emit(res, NULL);

    return res;
}

void VappGalleryMDIStreamingAdaptor::onStreamConnected(MDI_RESULT ret, mdi_video_info_struct *video_info, void *user_data)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_ON_STREAM_CONNECTED_RET_D, ret);
    VappGalleryMDIStreamingAdaptor *pThis = (VappGalleryMDIStreamingAdaptor*)user_data;
    if(NULL == pThis)
    {
        VFX_DEV_ASSERT(VFX_FALSE);
        return;
    }
    return pThis->handleStreamConnectResult(ret, video_info);
}

void VappGalleryMDIStreamingAdaptor::onStreamBuffered(MDI_RESULT ret, mdi_video_info_struct *video_info, void *user_data)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_ON_STREAM_BUFFERED_RET_D, ret);
    VappGalleryMDIStreamingAdaptor *pThis = (VappGalleryMDIStreamingAdaptor*)user_data;
    if(NULL == pThis)
    {
        VFX_DEV_ASSERT(VFX_FALSE);
        return;
    }

    return pThis->handleStreamBufferResult(ret, video_info);
}

void VappGalleryMDIStreamingAdaptor::handleStreamConnectResult(MDI_RESULT ret, mdi_video_info_struct *video_info)
{
    if(video_info)
    {
        m_videoInfo = *video_info;
    }

    if(MDI_RES_VDOPLY_SUCCEED != ret)
    {
        m_state = INITED;
        m_signalSeekDone.emit(ret, &m_videoInfo);
        return;
    }
    else
    {
        m_state = CONNECTED;
    }

    // seek and buffering are the same for streaming.
    MDI_RESULT seekResult = seek(m_startingTimeHint);
    if(MDI_RES_VDOPLY_SUCCEED != seekResult)
    {
        m_signalSeekDone.emit(seekResult, &m_videoInfo);
        return;
    }
}

void VappGalleryMDIStreamingAdaptor::onBufferingTick(VfxTimer *sender)
{
    S32 percentage = 0;
    MDI_RESULT res = mdi_video_stream_get_buf_percentage(&percentage);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAM_PLAYER_ON_BUFFERING_TICK_PERCENT_D, percentage);
}

void VappGalleryMDIStreamingAdaptor::handleStreamBufferResult(MDI_RESULT res, mdi_video_info_struct *video_info)
{
    if(m_bufferTimer)
    {
        VFX_OBJ_CLOSE(m_bufferTimer);
        m_bufferTimer = NULL;
    }

    if(MDI_RES_VDOPLY_SUCCEED != res)
    {
        m_signalSeekDone.emit(res, video_info);
        return;
    }

    m_state = BUFFERED;
    m_isBuffered = VFX_TRUE;
    m_signalSeekDone.emit(res, video_info);
    return;
}

void VappGalleryMDIStreamingAdaptor::handlePlayFinished(MDI_RESULT ret)
{
    // one of AV tracks failed (streaming will play continuously), notify CP to handle if show special message
    if(MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR == ret || MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR == ret)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_HANDLE_PLAY_FINISHED_SKIP_ERROR, ret, m_state);
        m_signalPlayFinish.emit(ret);
        return;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_HANDLE_PLAY_FINISHED, ret, m_state);
        
    // general case
    m_state = CONNECTED;
    if (ret == MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW)
    {
        mdi_video_stream_get_cur_play_time(&m_startingTimeHint);
    }
    else
    {
        m_startingTimeHint = 0;
    }

    m_signalPlayFinish.emit(ret);
}

MDI_RESULT VappGalleryMDIStreamingAdaptor::play(VfxVideoFrame *videoFrame, VfxVideoFrame *suntitleFrame, const mdi_video_info_struct &videoInfo)
{
    VFX_UNUSED(suntitleFrame);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_PLAY);
    MDI_RESULT res;

    if (INITED == m_state)
    {
        res = connect();
        if(MDI_RES_VDOPLY_SUCCEED == res)
        {
            return MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW;
        }
        return res;
    }
    else
    {
        if(BUFFERED != m_state)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_PLAY_FAILED_BECAUSE_NOT_BUFFERED_HINT_TIME_D_TOTAL_DURATION_D, m_startingTimeHint,m_startingTimeHint);
            U64 seekStartTime = m_startingTimeHint;
            // live stream case, where total_time_duration is 0 but currentTime is not.
            // in this case we can only buffer from beginning.
            if (m_isBuffered == VFX_TRUE)
            {
                seekStartTime = vfxMin(m_startingTimeHint, videoInfo.total_time_duration);
                if(MMI_FALSE == videoInfo.is_seekable)
                {
                    seekStartTime = 0;
                }
            }
            MDI_RESULT seekResult = seek(seekStartTime);
            if(MDI_RES_VDOPLY_SUCCEED == seekResult)
            {
                return MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW;
            }
            else
            {
                return seekResult;
            }
        }
        else if (BUFFERING == m_state)
        {
            return MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW;
        }


        const VfxBool isAudioOnly = (NULL == videoFrame) || (MDI_VIDEO_TRACK_A_ONLY == videoInfo.track);

        // MDI stream need to explicitly set which track to play
        if(isAudioOnly)
        {
            mdi_video_stream_set_track(MDI_VIDEO_TRACK_A_ONLY);
        }
        else
        {
            mdi_video_stream_set_track(videoInfo.track);
        }

        res = mdi_video_stream_play(
                            isAudioOnly ? NULL : videoFrame->getLayerHandle(),
                            isAudioOnly ? NULL : videoFrame->getDisplayLayerFlag(),
                            isAudioOnly ? NULL : videoFrame->getHwLayerFlag(),
                            isAudioOnly ? MMI_FALSE : MMI_TRUE,
                            getCurrentAudioPath(),      // config audio output path. Use earphone if present.
                            0,                          // no rotation
                            &onPlayFinished,
                            this);
        if(MDI_RES_VDOPLY_SUCCEED == res)
        {
            m_state = PLAYING;
        }
        else if (MDI_RES_VDOPLY_ERR_NETWORK_DISCONNECT == res)
        {
            m_state = INITED;
        }
        else
        {
            m_state = CONNECTED;
        }
    }
    return res;
}

MDI_RESULT VappGalleryMDIStreamingAdaptor::getCurrentPlayTime(U64 &time)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_GET_CURRENT_PLAY_TIME_STATE_D, m_state);
    switch(m_state)
    {
    case BUFFERED:
    case PLAYING:
        mdi_video_stream_get_cur_play_time(&time);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_GET_CURRENT_PLAY_TIME_D_D_LINE_D, time,__LINE__);
        return MDI_RES_VDOPLY_SUCCEED;
    case UNINIT:
    case INITED:
    case CONNECTING:
    case CONNECTED:
    case BUFFERING:
        (time) = m_startingTimeHint;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_GET_CURRENT_PLAY_TIME_D_D_LINE_D, time,__LINE__);
        return MDI_RES_VDOPLY_SUCCEED;
    default:
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
}

MDI_RESULT VappGalleryMDIStreamingAdaptor::stop()
{
    MDI_RESULT res = MDI_RES_VDOPLY_SUCCEED;

    if(PLAYING == m_state)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_STOP_WHEN_PLAYING);
        U64 time = 0;
        mdi_video_stream_get_cur_play_time(&time);
        m_startingTimeHint = time;

        res = mdi_video_stream_stop();
        m_state = CONNECTED;
    }
    else if(BUFFERING == m_state || BUFFERED == m_state)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_STOP_WHEN_BUFFER);
        res = mdi_video_stream_stop_buffering();
        m_state = CONNECTED;
        if(m_bufferTimer)
        {
            VFX_OBJ_CLOSE(m_bufferTimer);
            m_bufferTimer = NULL;
        }
    }
    else if (CONNECTING == m_state ) // can not discso|| CONNECTED == m_state)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_STOP_WHEN_CONNECTING);
        res = mdi_video_stream_disconnect();
        m_state = INITED;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_STOP_IN_INCORRECT_STATE_D, m_state);
        res = MDI_RES_VDOPLY_ERR_FAILED;
        // keep it original state.
    }

    return res;
}

VfxBool VappGalleryMDIStreamingAdaptor::canSeek()
{
    return VFX_TRUE;
}

VfxBool VappGalleryMDIStreamingAdaptor::canSeekWithoutBuffering()
{
    return VFX_FALSE;
}

MDI_RESULT VappGalleryMDIStreamingAdaptor::getSeekableRegion(U64 &seekableRegion)
{
    if(!canSeek())
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

    if(0 == m_videoInfo.total_time_duration)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
    
    seekableRegion = m_videoInfo.total_time_duration;
    return MDI_RES_VDOPLY_SUCCEED;
}

VfxBool VappGalleryMDIStreamingAdaptor::mustPlayAfterSeek()
{
    return VFX_TRUE;
}

MDI_RESULT VappGalleryMDIStreamingAdaptor::blockingSeek(U64 time)
{
    return MDI_RES_VDOPLY_ERR_FAILED;
}


MDI_RESULT VappGalleryMDIStreamingAdaptor::seek(U64 time)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_SEEK_TIME_X_D_STATE_D, time, m_state);

    // a quick check to prevent unnecessary re-buffering
    m_startingTimeHint = time;

    if(BUFFERED == m_state)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_SEEK_STATE_BUFFERED);

        U64 curTime = 0;
        mdi_video_stream_get_cur_play_time(&curTime);
        if(curTime == time)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_SEEK_PLAY_FINISHED);
            return MDI_RES_VDOPLY_ALREADY_FINISHED;
        }
    }
    else if (INITED == m_state)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_SEEK_STATE_INITED);
        VappGalleryStreamingSetting streamingSetting;
        kal_uint32 accountId = streamingSetting.getActiveAccountId();

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_USE_DATA_ACCOUNT_ID_X, accountId);

        MDI_RESULT res = connect();
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_SEEK, res, __LINE__);
        return res;
    }
    else if (CONNECTING == m_state)
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }

    // for streaming, we must drop all
    // buffer before seeking (re-buffering)
    stop();

    if(CONNECTED != m_state)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_SEEK_WRONG_STATE_D, m_state);
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

    // note live streaming always seeks from 0
    U64 seekTime = time;
    if(0 == m_videoInfo.total_time_duration)
    {
        seekTime = 0;
        m_startingTimeHint = 0;
    }

    MDI_RESULT res = mdi_video_stream_start_buffering(
                                                    seekTime,
                                                    &onStreamBuffered,
                                                    this);
    if(MDI_RES_VDOPLY_SUCCEED != res)
    {
        return res;
    }

    m_state = BUFFERING;
    if(NULL == m_bufferTimer)
    {
        VFX_OBJ_CREATE(m_bufferTimer, VfxTimer, this);
    }
    m_bufferTimer->setDuration(BUFFER_POLLING_INTERVAL);
    m_bufferTimer->setStartDelay(BUFFER_POLLING_INTERVAL);
    m_bufferTimer->m_signalTick.connect(this, &VappGalleryMDIStreamingAdaptor::onBufferingTick);
    m_bufferTimer->start();
    return res;
}

VfxBool VappGalleryMDIStreamingAdaptor::canGetStillFrame()
{
    return VFX_FALSE;
}

MDI_RESULT VappGalleryMDIStreamingAdaptor::seekAndGetFrame(U64 time, GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer)
{
    return MDI_RES_VDOPLY_ERR_FAILED;
}

MDI_RESULT VappGalleryMDIStreamingAdaptor::blockingSeekAndGetFrame(U64 time, GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer)
{
    return MDI_RES_VDOPLY_ERR_FAILED;
}

MDI_RESULT VappGalleryMDIStreamingAdaptor::blockingGetFrame(GDI_HANDLE videoLayer, GDI_HANDLE subtitleLayer)
{
    return MDI_RES_VDOPLY_ERR_FAILED;
}

VfxBool VappGalleryMDIStreamingAdaptor::canGetKeyFrame()
{
    return VFX_FALSE;
}

MDI_RESULT VappGalleryMDIStreamingAdaptor::getKeyFrameTime(const U64 refrenceTime, U64 &keyFrameTime)
{
    keyFrameTime = 0;
    return MDI_RES_VDOPLY_ERR_FAILED;
}

MDI_RESULT VappGalleryMDIStreamingAdaptor::connect()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_CONNECT_HAD_RELEASE, getHadReleasedBearer());

    if(!getHadReleasedBearer())
    {
        createStreamingConnection();
        return MDI_RES_VDOPLY_SUCCEED;
    }

    const kal_uint32 accountId = getStreamingAccountId();
    const kal_int32 bearerStatus = cbm_get_bearer_status(accountId);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_CONNECT, bearerStatus);

    switch(bearerStatus)
    {
    case CBM_DEACTIVATED:
        // it is ok to create a new connection
        setIsDelayConnectAfterBearerReleased(VFX_FALSE);
        return createStreamingConnection();
    default:
        setIsDelayConnectAfterBearerReleased(VFX_TRUE);
        m_state = CONNECTING;
        return MDI_RES_VDOPLY_SUCCEED;
    }
}

MDI_RESULT VappGalleryMDIStreamingAdaptor::createStreamingConnection()
{
    const kal_uint32 accountId = getStreamingAccountId();
    const kal_uint8 cbmAppId = cbm_get_app_id(accountId);

    // hold the new bearer
    cbm_hold_bearer(cbmAppId);

    // note streaming player should hold a new bearer and connect while the old bearer is CBM_DEACTIVATED state
    // remove proxy until proxy setting page is ready
    //srv_dtcnt_prof_proxy_info_struct temp_proxy_info;
    //srv_dtcnt_get_proxy_info(accountId, &temp_proxy_info, SRV_DTCNT_ACCOUNT_PRIMARY);
    MDI_RESULT res = mdi_video_stream_connect(
                            accountId,
                            (m_isRTSPLink == VFX_TRUE) ? MDI_VIDEO_STREAM_RTSP_URL : MDI_VIDEO_STREAM_SDP_FILE,
                            (CHAR*)m_path.getBuf(),
                            MMI_FALSE, //(temp_proxy_info.use_proxy)? MMI_TRUE : MMI_FALSE, // use proxy
                            NULL, //temp_proxy_info.px_addr,
                            0, //temp_proxy_info.px_port,
                            MMI_FALSE,  // use default port
                            0,          // use default port
                            0,          // use default port
                            &onStreamConnected,
                            this);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_CREATE_STREAMING_CONNECTION, res, m_state);
    if(MDI_RES_VDOPLY_SUCCEED == res)
    {
        m_state = CONNECTING;
    }

    return res;
}

mmi_ret VappGalleryMDIStreamingAdaptor::onDelayConnectAfterBearerReleased(mmi_event_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_ON_DELAY_CONNECT_AFTER_BEARER_RELEASED);

    VappGalleryMDIStreamingAdaptor *pThis = (VappGalleryMDIStreamingAdaptor*)handleToObject((VfxObjHandle)(param->user_data));
    if(NULL == pThis)
    {
        return MMI_RET_OK;
    }
    return pThis->handleDelayConnectAfterBearerReleased(param);
}

mmi_ret VappGalleryMDIStreamingAdaptor::handleDelayConnectAfterBearerReleased(mmi_event_struct *param)
{
    srv_cbm_bearer_info_struct *bearer_info = (srv_cbm_bearer_info_struct*)param;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_HANDLE_DELAY_CONNECT_AFTER_BEARER_RELEASED, bearer_info->state, m_isDelayConnectAfterBearerReleased);

    if(SRV_CBM_DEACTIVATED == bearer_info->state)
    {
        if(getIsDelayConnectAfterBearerReleased())
        {
            setHadReleasedBearer(VFX_FALSE);
            setIsDelayConnectAfterBearerReleased(VFX_FALSE);
            createStreamingConnection();
        }
    }
    return MMI_RET_OK;
}

kal_uint32 VappGalleryMDIStreamingAdaptor::getStreamingAccountId()
{
    VappGalleryStreamingSetting streamingSetting;
    kal_uint32 accountId = streamingSetting.getActiveAccountId();
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_USE_DATA_ACCOUNT_ID_X, accountId);
    return accountId;
}

kal_int8 VappGalleryMDIStreamingAdaptor::releaseBearer()
{
    const kal_uint32 accountId = getStreamingAccountId();
    const kal_uint8 cbmAppId = cbm_get_app_id(accountId);
    setHadReleasedBearer(VFX_TRUE);
    // register bearer info
    srv_cbm_register_bearer_info(cbmAppId,
                                 SRV_CBM_DEACTIVATED,
                                 SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
                                 &VappGalleryMDIStreamingAdaptor::onDelayConnectAfterBearerReleased,
                                 getObjHandle());
    const kal_int8 res = cbm_release_bearer(cbmAppId);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_RELEASE_BEARER, res);
    return res;
}

void VappGalleryMDIStreamingAdaptor::setIsDelayConnectAfterBearerReleased(const VfxBool flag)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_SET_IS_DELAY_CONNECT_AFTER_BEARER_RELEASED, flag);
    m_isDelayConnectAfterBearerReleased = flag;
}

VfxBool VappGalleryMDIStreamingAdaptor::getIsDelayConnectAfterBearerReleased() const
{
    return m_isDelayConnectAfterBearerReleased;
}

void VappGalleryMDIStreamingAdaptor::setHadReleasedBearer(const VfxBool flag)
{
    hadReleasedBearer = flag;
}

VfxBool VappGalleryMDIStreamingAdaptor::getHadReleasedBearer() const
{
    return hadReleasedBearer;
}

VfxBool VappGalleryMDIStreamingAdaptor::canDisconnect()
{
    return VFX_TRUE;
}

MDI_RESULT VappGalleryMDIStreamingAdaptor::disconnect()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_DISCONNECT, m_state);

    if(INITED == m_state)
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }

    MDI_RESULT res = MDI_RES_VDOPLY_SUCCEED;

    switch(m_state)
    {
        case PLAYING:
        {
            U64 time = 0;
            mdi_video_stream_get_cur_play_time(&time);
            m_startingTimeHint = time;
            res = mdi_video_stream_stop();
            break;
        }
        case BUFFERING:
        case BUFFERED:
        {
            res = mdi_video_stream_stop_buffering();
            if(m_bufferTimer)
            {
                VFX_OBJ_CLOSE(m_bufferTimer);
                m_bufferTimer = NULL;
            }
            break;
        }
        default:
            break;
    }

    res = mdi_video_stream_disconnect();
    m_state = INITED;

    return res;
}

void VappGalleryMDIStreamingAdaptor::disableNextDRMConsumption()
{
#ifdef __DRM_SUPPORT__
    mdi_video_stream_drm_disable_consume_count();
#endif
}

VfxBool VappGalleryMDIStreamingAdaptor::changeVideoScreenMode(
                    const U8 mdiScreenMode,
                    VfxVideoFrame *videoFrame,
                    VfxVideoFrame *subtitleFrame,
                    const VfxBool needPausedResume,
                    const VfxBool isAudioOnly)
{
    VFX_UNUSED(subtitleFrame);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_CHANGE_SCREEN_MODE);
    if(needPausedResume)
    {
        mdi_video_stream_pause();
    }

    mdi_video_stream_set_frame_mode(mdiScreenMode);

    if(needPausedResume && videoFrame)
    {
        mdi_video_stream_resume(
                isAudioOnly ? NULL : videoFrame->getLayerHandle(),
                isAudioOnly ? NULL : videoFrame->getDisplayLayerFlag(),
                isAudioOnly ? NULL : videoFrame->getHwLayerFlag(),
                isAudioOnly ? MMI_FALSE : MMI_TRUE,
                getCurrentAudioPath(),
                0);
    }

    return VFX_TRUE;
}

VfxBool VappGalleryMDIStreamingAdaptor::canSwitchTo3DTrack(const mdi_video_info_struct &videoInfo, const VfxBool swtchTo3D)
{
    VFX_UNUSED(videoInfo);
    return !swtchTo3D;
}

VfxBool VappGalleryMDIStreamingAdaptor::switchTo3DTrack(const mdi_video_info_struct &videoInfo,
                                                        const VfxBool swtchTo3D)
{
    VFX_UNUSED(videoInfo);
    VFX_UNUSED(swtchTo3D);
    return VFX_FALSE;
}

#endif // defined(__MMI_VIDEO_STREAM__) && defined(__COSMOS_MMI_PACKAGE__)

/*****************************************************************************
 * VappVideoPlayerComponentDisplay Interface
 *****************************************************************************/
class VappVideoPlayerComponentDisplay : public VfxObject
{
public:
    typedef VfxSignal0 PlayReadyEvent;

public:
    VappVideoPlayerComponentDisplay();

public:
    // config video display frame and subtitle frame
    void setupDisplay(VfxVideoFrame *videoFrame, VfxVideoFrame *subtitleFrame);
    void setBuffer(mmi_id appId);

    // set display funtional option
    // this method calls VfxVideoFrame::setHidden() implicitly,
    // so it should be called while playback is PAUSED to avoid tearing
    // note VideoCP Display turns on video display and turns off subtitle display defaultly
    void setOption(const VfxBool toggleVideo, const VfxBool toggleSubtitle);
    VfxBool getIsVideoDisplayTurnedOn() const;
    VfxBool getIsSubtitleDisplayTurnedOn() const;
    VfxBool hasVideoDisplay() const;
    VfxBool hasSubtitleDisplay() const;

    // get display play ready signal
    PlayReadyEvent* getPlayReadyEvent();
    // check if display is ready to play
    VfxBool getIsDisplayReady();
    // prepare display to update LCD and video layer config releated to VfxVideoFrame and VRT
    VfxBool prepareDisplay();
    void restoreAndUnprepareDisplay();
    void switchDisplayLayerToHW();
    void switchDisplayLayerToSW(const VfxBool convertToRGB565);

    // set display conenet
    void clean();
    // set display conenet is dirty to notify VRT update
    void invalidate();
    // clean and update
    void cleanAndInvalidate();

///////////////////////////////////////////////////////////////////////////
    VfxVideoFrame* getVideoDisplay() const;
    VfxVideoFrame* getSubtitleDisplay() const;

    // get gdi layer handle of video display
    GDI_HANDLE getVideoLayerHandle() const;
    // get gdi layer handle of subtitle display
    GDI_HANDLE getSubtitleLayerHandle() const;

    VfxBool hasValidVideoLayerHandle() const;
    VfxBool hasValidSubtitleLayerHandle() const;

//////////////////////////////////////////////////////////////////////////////
    void setDisplayPos(const VfxS32 x, const VfxS32 y);
    void setDisplaySize(const VfxSize size);
    void hideDisplay(const VfxBool hide);

private:
    // used to displaying video content
    // note size of VappVideoPlayerComponentDisplay equals to its member m_videoFrame size;
    VfxVideoFrame *m_videoDisplay;
    // used to displaying subtitle content (optional)
    VfxVideoFrame *m_subtitleDisplay;

    // optional flag to indicate the if the function is turned on
    // we turn on video but turn off subtitle defaultly
    VfxBool isVideoTurnedOn;        // VFX_TRUE while video display is turned on (need to prepare video display frame to update content)
    VfxBool isSubtitleTurnedOn;     // VFX_TRUE while subtitle display is turned on (need to prepare subtitle display frame to update content)

    // the signal to notify that Display is ready to update video content by playback
    // we emit this signal while both video and subtitle frame is prepared
    PlayReadyEvent m_signalPlayReady;

// implementation
private:
    VfxBool prepareVideoFrame();
    VfxBool preparedSubtileFrame();
    void onVideoFramePrepared();
    void onSubtileFramePrepared();

    VfxBool _isVideoFrameReady(VfxVideoFrame *vFrame);
    void _setVideoFrameHidden(VfxVideoFrame *vFrame, const VfxBool isHidden);
    void _cleanLayer(GDI_HANDLE layer, const VfxBool cleanToTransparent = VFX_FALSE);
    void _switchVideoLayerToHW(VfxVideoFrame *vFrame);
    void _switchVideoLayerToSW(VfxVideoFrame *vFrame, VfxBool convertToRGB565);
};

/*****************************************************************************
 * VappVideoPlayerComponentDisplay Implementation
 *****************************************************************************/
VappVideoPlayerComponentDisplay::VappVideoPlayerComponentDisplay():
    m_videoDisplay(NULL)
    ,m_subtitleDisplay(NULL)
    ,isVideoTurnedOn(VFX_TRUE)
    ,isSubtitleTurnedOn(VFX_FALSE)
{
}

void VappVideoPlayerComponentDisplay::setupDisplay(VfxVideoFrame *videoFrame, VfxVideoFrame *subtitleFrame)
{
    m_videoDisplay = videoFrame;
    m_subtitleDisplay = subtitleFrame;
}

void VappVideoPlayerComponentDisplay::setBuffer(mmi_id appId)
{
    if(m_videoDisplay)
        m_videoDisplay->setBuffer(appId);
    if(m_subtitleDisplay)
        m_subtitleDisplay->setBuffer(appId);
}

void VappVideoPlayerComponentDisplay::setOption(const VfxBool toggleVideo, const VfxBool toggleSubtitle)
{
    isVideoTurnedOn = toggleVideo;
    isSubtitleTurnedOn = toggleSubtitle;

    // update display visibale state
    _setVideoFrameHidden(m_videoDisplay, !toggleVideo);
    _setVideoFrameHidden(m_subtitleDisplay, !toggleSubtitle);
}

VfxBool VappVideoPlayerComponentDisplay::getIsVideoDisplayTurnedOn() const
{
    return isVideoTurnedOn;
}

VfxBool VappVideoPlayerComponentDisplay::getIsSubtitleDisplayTurnedOn() const
{
    return isSubtitleTurnedOn;
}

VfxBool VappVideoPlayerComponentDisplay::hasVideoDisplay() const
{
    return (getIsVideoDisplayTurnedOn() && m_videoDisplay);
}

VfxBool VappVideoPlayerComponentDisplay::hasSubtitleDisplay() const
{
    return (getIsSubtitleDisplayTurnedOn() && m_subtitleDisplay);
}

VappVideoPlayerComponentDisplay::PlayReadyEvent* VappVideoPlayerComponentDisplay::getPlayReadyEvent()
{
    return &m_signalPlayReady;
}

VfxBool VappVideoPlayerComponentDisplay::getIsDisplayReady()
{
    if(getIsVideoDisplayTurnedOn()&& getIsSubtitleDisplayTurnedOn())
        return (_isVideoFrameReady(m_videoDisplay) && _isVideoFrameReady(m_subtitleDisplay));

    // turn on video display only
    if(getIsVideoDisplayTurnedOn())
        return _isVideoFrameReady(m_videoDisplay);
    // turn on subtitle display only
    if(getIsSubtitleDisplayTurnedOn())
        return _isVideoFrameReady(m_subtitleDisplay);

    return VFX_FALSE;
}

VfxBool VappVideoPlayerComponentDisplay::prepareDisplay()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_DISPLAY_PREPARE_DISPLAY, getIsVideoDisplayTurnedOn(), getIsSubtitleDisplayTurnedOn());

    if(getIsVideoDisplayTurnedOn())
        return prepareVideoFrame();

    if(getIsSubtitleDisplayTurnedOn())
        return preparedSubtileFrame();

    return VFX_FALSE;
}

void VappVideoPlayerComponentDisplay::restoreAndUnprepareDisplay()
{
    if(m_videoDisplay)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_DISPLAY_UNPREPARE_VIDEO);
        m_videoDisplay->unPrepare();
    }
    if(m_subtitleDisplay)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_DISPLAY_UNPREPARE_SUBTITLE);
        m_subtitleDisplay->unPrepare();
    }
}

void VappVideoPlayerComponentDisplay::switchDisplayLayerToHW()
{
    if(hasVideoDisplay())
    {
        _switchVideoLayerToHW(m_videoDisplay);
    }
    if(hasSubtitleDisplay())
    {
        //////_switchVideoLayerToHW(m_subtitleDisplay);
    }
}

void VappVideoPlayerComponentDisplay::switchDisplayLayerToSW(const VfxBool convertToRGB565)
{
    if(hasVideoDisplay())
    {
        _switchVideoLayerToSW(m_videoDisplay, convertToRGB565);
    }
    if(hasSubtitleDisplay())
    {
        /////_switchVideoLayerToSW(m_subtitleDisplay, convertToRGB565);
    }
}

void VappVideoPlayerComponentDisplay::clean()
{
    _cleanLayer(getVideoLayerHandle(), VFX_FALSE);
    _cleanLayer(getSubtitleLayerHandle(), VFX_TRUE);
}

void VappVideoPlayerComponentDisplay::invalidate()
{
    if(m_videoDisplay && getIsVideoDisplayTurnedOn())
        m_videoDisplay->invalidate();
    if(m_subtitleDisplay && getIsSubtitleDisplayTurnedOn())
        m_subtitleDisplay->invalidate();
}

void VappVideoPlayerComponentDisplay::cleanAndInvalidate()
{
    clean();
    invalidate();
}

VfxVideoFrame* VappVideoPlayerComponentDisplay::getVideoDisplay() const
{
    return (getIsVideoDisplayTurnedOn() ? m_videoDisplay : NULL);
}

VfxVideoFrame* VappVideoPlayerComponentDisplay::getSubtitleDisplay() const
{
    return (getIsSubtitleDisplayTurnedOn() ? m_subtitleDisplay : NULL);
}

GDI_HANDLE VappVideoPlayerComponentDisplay::getVideoLayerHandle() const
{
    if(m_videoDisplay && getIsVideoDisplayTurnedOn())
        return m_videoDisplay->getLayerHandle();
    return GDI_LAYER_EMPTY_HANDLE;
}

GDI_HANDLE VappVideoPlayerComponentDisplay::getSubtitleLayerHandle() const
{
    if(m_subtitleDisplay && getIsSubtitleDisplayTurnedOn())
        return m_subtitleDisplay->getLayerHandle();
    return GDI_LAYER_EMPTY_HANDLE;
}

VfxBool VappVideoPlayerComponentDisplay::hasValidVideoLayerHandle() const
{
    return (GDI_LAYER_EMPTY_HANDLE == getVideoLayerHandle()? VFX_FALSE : VFX_TRUE);
}

VfxBool VappVideoPlayerComponentDisplay::hasValidSubtitleLayerHandle() const
{
    return (GDI_LAYER_EMPTY_HANDLE == getSubtitleLayerHandle()? VFX_FALSE : VFX_TRUE);
}

void VappVideoPlayerComponentDisplay::setDisplayPos(const VfxS32 x, const VfxS32 y)
{
    // TODO: while size or position change... the subtitle pos and size shoule be...?

    if(m_videoDisplay)
        m_videoDisplay->setPos(x, y);
}

void VappVideoPlayerComponentDisplay::setDisplaySize(const VfxSize size)
{
    if(m_videoDisplay)
        m_videoDisplay->setSize(size);

    // we support fixed size subtitle now
#ifdef __COSMOS_MMI_PACKAGE__
    const VfxS32 subtitleW = VAPP_GALLERY_VIDEO_SUBTITLE_DISPLAY_WIDTH;
    const VfxS32 subtitleH = VAPP_GALLERY_VIDEO_SUBTITLE_DISPLAY_HEIGHT;
#else
    const VfxS32 subtitleW = 2;
    const VfxS32 subtitleH = 2;
#endif
    if(m_subtitleDisplay)
        m_subtitleDisplay->setSize(subtitleW, subtitleH);
}

// TODO: check logic
void VappVideoPlayerComponentDisplay::hideDisplay(const VfxBool hide)
{
    if(m_videoDisplay && getIsVideoDisplayTurnedOn())
        m_videoDisplay->setHidden(hide);
    if(m_subtitleDisplay && getIsSubtitleDisplayTurnedOn())
        m_subtitleDisplay->setHidden(hide);
}

VfxBool VappVideoPlayerComponentDisplay::prepareVideoFrame()
{
    if(NULL == m_videoDisplay)
    {
        return VFX_FALSE;
    }

    m_videoDisplay->m_signalPlayReady.connect(this, &VappVideoPlayerComponentDisplay::onVideoFramePrepared);
    if(!m_videoDisplay->prepare())
    {
        m_videoDisplay->m_signalPlayReady.disconnect(this, &VappVideoPlayerComponentDisplay::onVideoFramePrepared);
        return VFX_FALSE;
    }
#ifdef __MMI_REDUCED_UI_BUFFER__
	gdi_handle handleT = m_videoDisplay->getLayerHandle();
    gdi_layer_push_and_set_active(handleT);
    gdi_layer_set_rotate(LCD_LAYER_ROTATE_90);
    gdi_layer_resize(LCD_HEIGHT, LCD_WIDTH);
    gdi_layer_set_position(0, 0);
    gdi_layer_pop_and_restore_active();
#endif
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_DISPLAY_PREPARE_VIDEO);
    return VFX_TRUE;
}

VfxBool VappVideoPlayerComponentDisplay::preparedSubtileFrame()
{
    if(NULL == m_subtitleDisplay)
    {
        return VFX_FALSE;
    }

    m_subtitleDisplay->m_signalPlayReady.connect(this, &VappVideoPlayerComponentDisplay::onSubtileFramePrepared);
    if(!m_subtitleDisplay->prepare())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_DISPLAY_PREPARE_SUBTITLE, -1);
        m_subtitleDisplay->m_signalPlayReady.disconnect(this, &VappVideoPlayerComponentDisplay::onSubtileFramePrepared);
        return VFX_FALSE;
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_DISPLAY_PREPARE_SUBTITLE, 0);
    return VFX_TRUE;
}

void VappVideoPlayerComponentDisplay::onVideoFramePrepared()
{
    m_videoDisplay->m_signalPlayReady.disconnect(this, &VappVideoPlayerComponentDisplay::onVideoFramePrepared);

    if(getIsSubtitleDisplayTurnedOn() && preparedSubtileFrame())
    {
        return;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_DISPLAY_VIDEO_PREPARED_EMIT);
    m_signalPlayReady.emit();
}

void VappVideoPlayerComponentDisplay::onSubtileFramePrepared()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_SUBTITLE_VIDEO_PREPARED_EMIT);

    m_subtitleDisplay->m_signalPlayReady.disconnect(this, &VappVideoPlayerComponentDisplay::onSubtileFramePrepared);
    m_signalPlayReady.emit();
}

VfxBool VappVideoPlayerComponentDisplay::_isVideoFrameReady(VfxVideoFrame *vFrame)
{
    return (vFrame && vFrame->getIsReady());
}

void VappVideoPlayerComponentDisplay::_setVideoFrameHidden(VfxVideoFrame *vFrame, const VfxBool isHidden)
{
    if(vFrame)
        vFrame->setHidden(isHidden);
}

void VappVideoPlayerComponentDisplay::_cleanLayer(GDI_HANDLE layer, const VfxBool cleanToTransparent)
{
    if(GDI_LAYER_EMPTY_HANDLE == layer){return;}
    if(cleanToTransparent)
    {
        gdi_layer_push_and_set_active(layer);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
    else
    {
        gdi_layer_push_and_set_active(layer);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
}

void VappVideoPlayerComponentDisplay::_switchVideoLayerToHW(VfxVideoFrame *vFrame)
{
    if(NULL == vFrame)
    {
        return;
    }
    SWLA_BEGIN("VHW");
#if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__))
    // make sure layer buffer is non-cacheable address    
    GDI_HANDLE videoLayer = vFrame->getLayerHandle();
    if(GDI_LAYER_EMPTY_HANDLE != videoLayer)
    {
        // 3D and GOVL cases, we won't convert buffer pointer,
        // no need to revert the pointer.
        #if !defined(GDI_GOVL_SUPPORT) && !defined(__VENUS_3D_UI_ENGINE__)
        // wait VRT to blt when switching layer properties
        U8* buf_ptr = NULL;
        gdi_layer_push_and_set_active(videoLayer);
        gdi_layer_get_buffer_ptr(&buf_ptr);
        gdi_layer_struct *layerImpl = (gdi_layer_struct*)videoLayer;
        buf_ptr = (U8*)virt_to_phys((U32*)buf_ptr);
        layerImpl->buf_ptr = buf_ptr;
        gdi_layer_pop_and_restore_active();
        #endif
    }
#endif
    SWLA_END("VHW");
}

void VappVideoPlayerComponentDisplay::_switchVideoLayerToSW(VfxVideoFrame *vFrame, VfxBool convertToRGB565)
{
    if(NULL == vFrame)
    {
        return;
    }
    
    GDI_HANDLE videoLayer = vFrame->getLayerHandle();
    if(GDI_LAYER_EMPTY_HANDLE != videoLayer)
    {
        SWLA_BEGIN("VSP");
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
        // 3D case, 
        // * VRT will pipeline GPU command
        // * GPU BLT in another task,
        // so make sure we wait for VRT flushes and then
        // acquire & wait LCD mutex, 
        // then wait for BLT finish
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->waitForRenderingComplete();
        gdi_layer_push_and_set_active(videoLayer);
        gdi_lcd_lock_mutex(); 
        gdi_waiting_blt_finish();
        SWLA_END("VSP");
        
        SWLA_BEGIN("VSW");
        mdi_util_hw_layer_switch_to_sw_layer(videoLayer);
        SWLA_END("VSW");
        
        #if !defined(GDI_GOVL_SUPPORT) && !defined(__VENUS_3D_UI_ENGINE__)
        SWLA_BEGIN("VCF");
        if(convertToRGB565)
        {
            U8 *buf_ptr = NULL;
            S32 layer_width = 0, layer_height = 0;
            gdi_color_format format = GDI_COLOR_FORMAT_16;
            
            gdi_layer_get_color_format(&format);
            gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
            gdi_layer_get_buffer_ptr(&buf_ptr);
            gdi_layer_get_dimension(&layer_width, &layer_height);
            _util_convert_color_format(videoLayer, 
                                      format,
                                      GDI_COLOR_FORMAT_16,
                                      buf_ptr,
                                      layer_width,
                                      layer_height
                                      );
        }
        SWLA_END("VCF");
        #endif
        
        SWLA_BEGIN("VSQ");
        // release LCD mutex
        gdi_lcd_unlock_mutex();              
        gdi_layer_pop_and_restore_active();
        SWLA_END("VSQ");
    }

    return;
}

/*****************************************************************************
 * VappVideoPlayerPlayOption Implementation
 *****************************************************************************/
VappVideoPlayerPlayOption::VappVideoPlayerPlayOption():
    delayStartWaitingIcon(VFX_FALSE)
    ,disableAudio(VFX_FALSE)
    ,loopForever(VFX_FALSE)
	,useRingVol(VFX_FALSE)
    ,isWallpaperScenario(VFX_FALSE)
    ,isKeepBacklight(VFX_FALSE)
	,useAnonymousASM(VFX_FALSE)
	,supportFullResolution(VFX_FALSE)
    ,supportSubtitle(VFX_FALSE)
	,isPreview(VFX_FALSE)
	,enablePlayDuringCall(VFX_FALSE)
    ,asmGroupId(NULL)
{
}

void VappVideoPlayerPlayOption::configAsWallpaperVideo()
{
    delayStartWaitingIcon = VFX_FALSE;
    disableAudio = VFX_TRUE;
    loopForever = VFX_TRUE;
    isWallpaperScenario = VFX_TRUE;
    useRingVol = VFX_FALSE;
    isKeepBacklight = VFX_FALSE;
    useAnonymousASM = VFX_TRUE;
    supportFullResolution = VFX_FALSE;
}

void VappVideoPlayerPlayOption::configAsBootVideo()
{
    delayStartWaitingIcon = VFX_FALSE;
    disableAudio = VFX_FALSE;
    loopForever = VFX_FALSE;
    isWallpaperScenario = VFX_TRUE;
    useRingVol = VFX_TRUE;
    isKeepBacklight = VFX_FALSE;
    useAnonymousASM = VFX_TRUE;
    supportFullResolution = VFX_FALSE;
}

void VappVideoPlayerPlayOption::configAsNormalVideo()
{
    delayStartWaitingIcon = VFX_FALSE;
    disableAudio = VFX_FALSE;
    loopForever = VFX_FALSE;
    isWallpaperScenario = VFX_FALSE;
    useRingVol = VFX_FALSE;
    isKeepBacklight = VFX_FALSE;
    useAnonymousASM = VFX_FALSE;
    supportFullResolution = VFX_FALSE;
}

void VappVideoPlayerPlayOption::configAsMmsVideo()
{
    configAsNormalVideo();
    delayStartWaitingIcon = VFX_TRUE;
}

void VappVideoPlayerPlayOption::configAsWallpaperVideoPreview()
{
    configAsWallpaperVideo();
    isPreview = VFX_TRUE;
    useAnonymousASM = VFX_FALSE;
    isKeepBacklight = VFX_TRUE;
}

void VappVideoPlayerPlayOption::configAsBootVideoPreview()
{
    configAsBootVideo();
    isPreview = VFX_TRUE;
    useAnonymousASM = VFX_FALSE;
    loopForever = VFX_TRUE;
    isKeepBacklight = VFX_TRUE;
}

/*****************************************************************************
 * VappVideoPlayerComponent Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappVideoPlayerComponent", VappVideoPlayerComponent, VfxFrame);
VappVideoPlayerComponent::VappVideoPlayerComponent():
	m_display(NULL),
    m_audioOnlyIconFrame(NULL),
    m_waitIcon(NULL),
    m_shouldPlayAfterBTConnected(VFX_FALSE),
	m_shouldConsumeDRM(VFX_TRUE),
	m_shouldWaitPGDLFile(VFX_TRUE),
	m_state(VGPS_CLOSED),
	m_appId(NULL),
    m_videoOpenResult(MDI_RES_VDOPLY_SUCCEED),
    m_videoSeekResult(MDI_RES_VDOPLY_SUCCEED),
    m_needResumePlayAfterReady(VFX_FALSE),
    m_needResumePlayAfterEndRotate(VFX_FALSE),
    m_needResumePlayAfterEndSeek(VFX_FALSE),
	m_needBlockingSeekAndGetFrame(VFX_FALSE),
	m_needResumePlayAfterSwitch3DAnaglyph(VFX_FALSE),
	m_allowScrolling(VFX_TRUE),
	m_hBackgroundPlay(NULL),
	m_connectingBT(VFX_FALSE),
	m_hBTAudio(NULL),
	m_mdiPlayer(NULL),
	m_videoFrameNotReady(VFX_FALSE),
	m_isBacklightForced(VFX_FALSE),
	m_screenMode(VS_STRETCH),
	m_subtitleInfoIndex(VAPP_VIDEO_PLAYER_COMPONENT_DEFAULT_SUBTITLE_INFO_INDEX),
	m_is3DAnaglyphMode(VFX_TRUE)
{
    kal_mem_set(&m_currentVideoInfo, 0, sizeof(m_currentVideoInfo));
}

VappVideoPlayerComponent::VappVideoPlayerComponent(const VappVideoPlayerPlayOption &option):
    m_display(NULL),
    m_audioOnlyIconFrame(NULL),
    m_waitIcon(NULL),
	m_shouldPlayAfterBTConnected(VFX_FALSE),
	m_shouldConsumeDRM(VFX_TRUE),
	m_shouldWaitPGDLFile(VFX_TRUE),
	m_state(VGPS_CLOSED),
    m_appId(NULL),
    m_videoOpenResult(MDI_RES_VDOPLY_SUCCEED),
    m_videoSeekResult(MDI_RES_VDOPLY_SUCCEED),
    m_needResumePlayAfterReady(VFX_FALSE),
    m_needResumePlayAfterEndRotate(VFX_FALSE),
    m_needResumePlayAfterEndSeek(VFX_FALSE),
	m_needBlockingSeekAndGetFrame(VFX_FALSE),
	m_needResumePlayAfterSwitch3DAnaglyph(VFX_FALSE),
	m_allowScrolling(VFX_TRUE),
	m_option(option),
	m_hBackgroundPlay(NULL),
	m_connectingBT(VFX_FALSE),
	m_hBTAudio(NULL),
	m_mdiPlayer(NULL),
    m_videoFrameNotReady(VFX_FALSE),
	m_isBacklightForced(VFX_FALSE),
	m_subtitleInfoIndex(VAPP_VIDEO_PLAYER_COMPONENT_DEFAULT_SUBTITLE_INFO_INDEX),
    m_is3DAnaglyphMode(VFX_TRUE)
{
    kal_mem_set(&m_currentVideoInfo, 0, sizeof(m_currentVideoInfo));
}

void VappVideoPlayerComponent::onInit()
{
    VfxFrame::onInit();

    setBgColor(VFX_COLOR_TRANSPARENT);
    m_signalBoundsChanged.connect((VfxFrame*)this, &VappVideoPlayerComponent::onBoundsChange);

    // initialize video display
    createDisplay(m_appId);

    // update subtitle para initial value
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    if(m_option.supportSubtitle)
    {
        m_subtitleInfoIndex = VAPP_VIDEO_PLAYER_COMPONENT_DEFAULT_SUBTITLE_INFO_INDEX;
    }
#endif

    // create waiting icon
    if(m_option.isWallpaperScenario)
    {
        VFX_OBJ_CLOSE(m_waitIcon);
    }
    else
    {
        VFX_OBJ_CREATE(m_waitIcon, VcpActivityIndicator, this);
        m_waitIcon->setAnchor(0.5f, 0.5f);
        m_waitIcon->setPos(getSize().width / 2, getSize().height / 2);
        m_waitIcon->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_MID,
                        VFX_FRAME_ALIGNER_MODE_MID,
                        VFX_FRAME_ALIGNER_MODE_MID,
                        VFX_FRAME_ALIGNER_MODE_MID);
        m_waitIcon->setHiddenWhenStopped(VFX_TRUE);
        m_waitIcon->bringToFront();
        if(!m_option.delayStartWaitingIcon)
        {
            m_waitIcon->start();
        }
    }

#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MED_IN_ASM__)
    
    // find APP to get app id.
    if(m_option.useAnonymousASM)
    {
        // For video wallpaper, we use anonymous POOL id
        m_appId = ASM_ANONYMOUS_ID;
        m_allowScrolling = VFX_TRUE;
    }
    else if(m_option.asmGroupId)
    {
        m_appId = m_option.asmGroupId;
    }
    else
    {
        m_appId = findRootAppId(this);
    }

    // must be placed under an VfxApp-based context
    // [Venusmmi] must be placed under an VfxApp-based context
    // [Plutommi] still set ASM_ANONYMOUS_ID to video frame to
    // ensure MDI will not skip allocation.
    VFX_ASSERT(NULL != m_appId);
    m_display->setBuffer(m_appId);

#else
    // Pluto MMI, the APP ID is a don't care.
    m_appId = 0;
    // still set ASM_ANONYMOUS_ID to video frame to
    // ensure MDI will not skip allocation.
    m_display->setBuffer(ASM_ANONYMOUS_ID);
#endif
    // for wallpaper/bootvideo,
    // video cp should register device event and turn off 3D effect
    if(m_option.isWallpaperScenario)
    {
        VfxObjHandle hObj = getObjHandle();
        mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappVideoPlayerComponent::onDeviceEvent, hObj);

        // always turn off 3D effect in wallpaper scenario
        setIs3DAnaglyphMode(VFX_FALSE);
    }

    m_currentVideoInfo.total_time_duration = 0;
    // direct set state variable,
    // since we should not trigger state change & redundant "CLOSE" action
    m_state = VGPS_CLOSED;
    m_hBackgroundPlay = NULL;

    // init as default screen mode
    m_screenMode = getDefaultScreenMode();

    // reset 3D switch memento
    m_switchMemento.reset();
}

void VappVideoPlayerComponent::onDeinit()
{
    if(m_option.isWallpaperScenario)
    {
        VfxObjHandle hObj = getObjHandle();
        mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappVideoPlayerComponent::onDeviceEvent, hObj);
    }

    closeFile();
    VfxFrame::onDeinit();
}

VappVideoPlayerState VappVideoPlayerComponent::setState(VappVideoPlayerState newState, const VfxBool forceToNotifyApp)
{
    // skip same-state
    if(m_state == newState)
    {
        if(forceToNotifyApp)
        {
            m_signalPlayerStateChange.postEmit(this, m_state, newState);
        }
        return m_state;
    }

    // check valid state trasition
    switch(m_state)
    {
    case VGPS_CLOSED:
        VFX_ASSERT(
                VGPS_OPENING == newState ||
                VGPS_CLOSED == newState);
        break;
    case VGPS_OPENING:
        VFX_ASSERT(
                VGPS_OPENING == newState ||
                VGPS_CLOSED == newState ||
                VGPS_PAUSED == newState);
        break;
    case VGPS_PLAYING:
        VFX_ASSERT(
                VGPS_PAUSED == newState ||
                VGPS_CLOSED == newState ||
                VGPS_PLAYING == newState ||
                VGPS_SEEKING == newState );
        break;
    case VGPS_PAUSED:
        VFX_ASSERT(
                VGPS_PAUSED == newState ||
                VGPS_CLOSED == newState ||
                VGPS_PLAYING == newState ||
                VGPS_SEEKING == newState );
        break;
    case VGPS_SEEKING:
        VFX_ASSERT(
                VGPS_PAUSED == newState ||
                VGPS_CLOSED == newState ||
                VGPS_PLAYING == newState ||
                VGPS_SEEKING == newState );
        break;
    }

    // handle state-dependent action
    if(VGPS_PLAYING == newState)
    {
#if defined(__MMI_A2DP_SUPPORT__)
        // even if user did not config BT, we still need to listen to BT connection.
        if(NULL == m_hBTAudio &&
           !m_option.disableAudio &&
           MDI_VIDEO_TRACK_V_ONLY != m_currentVideoInfo.track)
        {
            m_hBTAudio = srv_btaud_open(BTAUD_LEVEL_NORMAL, BTAUD_CHNL_ANY);
            srv_btaud_set_notify(m_hBTAudio, BTAUD_EV_STEREO_CONFIG_IND, (BtAudNotify)onBTDeviceArrival, this);
        }
#endif
    }
    else if(VGPS_PAUSED == newState ||
            VGPS_CLOSED == newState ||
            VGPS_SEEKING == newState)
    {
#if defined(__MMI_A2DP_SUPPORT__)
        // stop lisening to BT arrival
        if(m_hBTAudio)
        {
            srv_btaud_close(m_hBTAudio);
            m_hBTAudio = NULL;
        }

        // close A2DP if connected before
        if(g_inst)
        {
            srv_a2dp_close(MMI_FALSE);
            srv_a2dp_close_codec();
            m_connectingBT = VFX_FALSE;
            g_inst = NULL;
        }
#endif
        // resume suspended background audio
        if(m_hBackgroundPlay)
        {
            mdi_audio_resume_background_play_by_app((MDI_AUD_SUSPEND_BG_APP)m_hBackgroundPlay);
            m_hBackgroundPlay = NULL;
        }
    }

    // automatically handle volume dialog during playing.
    // for other cases, we don't register the callback.
    if(!m_option.disableAudio && !m_option.useRingVol)
    {
#ifdef __COSMOS_MMI_PACKAGE__
        if(VGPS_PLAYING == newState)
        {
            mmi_frm_cb_reg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, &_onVolumeChange, this);
        }
        else
        {
            mmi_frm_cb_dereg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, &_onVolumeChange, this);
        }
#endif
    }
    // handle backlight settings
    if(m_option.isKeepBacklight)
    {
        // check backlight state
        switch(newState)
        {
        case VGPS_PLAYING:
        case VGPS_SEEKING:
        case VGPS_OPENING:
            if(!m_isBacklightForced)
            {
                // work around for MAUI_02456556:
                // launch vedio player, lock and recieve call,
                // video player show first before call screen
                if(MMI_TRUE == srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD))
                {
                    // disable backlight timer when playing
                    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
                    m_isBacklightForced = VFX_TRUE;
                }
            }
            break;
        case VGPS_CLOSED:
        case VGPS_PAUSED:
            // make sure we restored backlight
            if(m_isBacklightForced)
            {
                srv_backlight_turn_off();
                m_isBacklightForced = VFX_FALSE;
            }
            break;
        }
    }

    // change state and emit signal
    VappVideoPlayerState oldState = m_state;
    m_state = newState;

    m_signalPlayerStateChange.postEmit(this, oldState, m_state);
    return oldState;
}

VappVideoPlayerState VappVideoPlayerComponent::getState() const
{
    return m_state;
}

void VappVideoPlayerComponent::setHidden(VfxBool isHidden)
{
    VfxFrame::setHidden(isHidden);
}

void VappVideoPlayerComponent::onBoundsChange(VfxFrame *frm, const VfxRect &rect)
{
    if(m_audioOnlyIconFrame && getSize() != m_audioOnlyIconFrame->getSize())
    {
        m_audioOnlyIconFrame->setSize(getSize());
    }

    // if ready, we have to destroy and re-prepare the video frame.
    m_needResumePlayAfterReady = VFX_FALSE;
    if(m_display->getIsDisplayReady())
    {
        if(m_mdiPlayer && m_mdiPlayer->isPlaying())
        {
            m_needResumePlayAfterReady = VFX_TRUE;
            pause();
        }
        restoreLayerAndUnprepareVideoFrame();

        // then we resize and re-prepare the video frame.
        m_display->getPlayReadyEvent()->connect(this, &VappVideoPlayerComponent::onVideoFramePrepared);
        MDI_RESULT ret = prepareAndShowVideo(&m_currentVideoInfo);

        // prepareAndShowVideo would do a seek (this is a must) before we can play,
        // to show first frame
        // and make sure this video can be decoded
        // The result writes to m_videoOpenResult
        if(MDI_RES_VDOPLY_SUCCEED != ret)
        {
            m_display->getPlayReadyEvent()->disconnect(this, &VappVideoPlayerComponent::onVideoFramePrepared);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PREPARE_AND_SHOW_VIDEO_ERROR, ret);
            closeFile();
            popupMDIErrorMessage(ret);
            setErrorIcon(getErrorIconFromMDIResult(ret));
            return;
        }
    }
}

void VappVideoPlayerComponent::onVideoFramePrepared()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_ON_VIDEO_FRAME_PREPARED_SET_M_VIDEO_FRAME_NOT_READY_FALSE);

    m_display->getPlayReadyEvent()->disconnect(this, &VappVideoPlayerComponent::onVideoFramePrepared);
    m_videoFrameNotReady = VFX_FALSE;

    if(m_mdiPlayer->canGetStillFrame())
    {
        // if resize video frame after seeked successfully,
        // it spends few time on call blocking seek and get frame
        MDI_RESULT firstFrameResult = m_mdiPlayer->blockingGetFrame(m_display->getVideoLayerHandle(), m_display->getSubtitleLayerHandle());
        m_display->invalidate();

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_BLOCKING_SEEK_AND_GET_FRAME, firstFrameResult);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_ON_VIDEO_FRAME_PREPARED_RESUME, m_needResumePlayAfterReady);
    if(m_needResumePlayAfterReady)
    {
        play();
    }
}

void VappVideoPlayerComponent::changeRotation()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_CHANGE_ROTATION);
    // if ready, we have to destroy and re-prepare the video frame.
    m_needResumePlayAfterReady = VFX_FALSE;
    if(m_display->getIsDisplayReady())
    {
        restoreLayerAndUnprepareVideoFrame();
        // update the resume flag
        m_needResumePlayAfterReady = m_needResumePlayAfterEndRotate;
        m_needResumePlayAfterEndRotate = VFX_FALSE;

        // then we resize and re-prepare the video frame.
        m_display->getPlayReadyEvent()->connect(this, &VappVideoPlayerComponent::onVideoFramePrepared);
        MDI_RESULT ret = prepareAndShowVideo(&m_currentVideoInfo);

        // prepareAndShowVideo would do a seek (this is a must) before we can play,
        // to show first frame
        // and make sure this video can be decoded
        // The result writes to m_videoOpenResult
        if(MDI_RES_VDOPLY_SUCCEED != ret)
        {
            m_display->getPlayReadyEvent()->disconnect(this, &VappVideoPlayerComponent::onVideoFramePrepared);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PREPARE_AND_SHOW_VIDEO_ERROR, ret);
            closeFile();
            setErrorIcon(getErrorIconFromMDIResult(ret));
            return;
        }
    }
}

VfxBool VappVideoPlayerComponent::getIsSwitching()
{
    if(m_switchMemento.isSwitching())
        return VFX_TRUE; 
    return VFX_FALSE;
}

VfxBool VappVideoPlayerComponent::canSwitchTo3DAnaglyph(const VfxBool swtchTo3D, VfxBool shouldPopupErrMsg)
{
    if(NULL == m_mdiPlayer)
    {
        return VFX_FALSE;
    }

    switch(getState())
    {
    case VGPS_CLOSED:
    case VGPS_OPENING:
        return VFX_FALSE;
    case VGPS_PAUSED:
    case VGPS_PLAYING:
    case VGPS_SEEKING:
        {
            const VfxBool canSwitch = m_mdiPlayer->canSwitchTo3DTrack(m_currentVideoInfo, swtchTo3D);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_ENABLE_SWITCH_3D_ANAGLYGH, swtchTo3D, shouldPopupErrMsg, canSwitch);
#if defined(__COSMOS_MMI_PACKAGE__)
            if(shouldPopupErrMsg && !canSwitch)
            {
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_FAILURE,
                    (WCHAR *)VFX_WSTR_RES(STR_ID_VAPP_VIDEOCP_ONLY_SUPPORT_3D_MODE).getBuf());
            }
#endif
            return m_mdiPlayer->canSwitchTo3DTrack(m_currentVideoInfo, swtchTo3D);
        }
    default:
        return VFX_FALSE;
    }
}

VfxBool VappVideoPlayerComponent::switchTo3DAnaglyph(const VfxBool swtchTo3D)
{
    if(NULL == m_mdiPlayer)
    {
        return VFX_FALSE;
    }

    if(!canSwitchTo3DAnaglyph(swtchTo3D))
    {
        return VFX_FALSE;
    }

    setNeedResumePlayAfterSwitch3DAnaglyph(VFX_FALSE);

    // switch 3D mode
    const VappVideoPlayerState curState = getState();
    switch(curState)
    {
        case VGPS_OPENING:
        {
            setIs3DAnaglyphMode(swtchTo3D);
            m_mdiPlayer->setIs3DAnaglyphMode(swtchTo3D);
            break;
        }
        case VGPS_SEEKING:
        case VGPS_PLAYING:
        case VGPS_PAUSED:
        {
            const VfxBool shouldAutoPlay = (VGPS_PLAYING == curState)? VFX_TRUE : VFX_FALSE;
            setNeedResumePlayAfterSwitch3DAnaglyph(shouldAutoPlay);
            pause();

            VfxWString filePath = m_videoFilePath;
            VappVideoMsec totalDuration = 0;
            VappVideoMsec startTime = 0;
            VappVideoMsec seekableRegion = 0;
            getTotalDuration(totalDuration);
            getCurrentTime(startTime);
            getSeekableRegion(seekableRegion);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_SWITCH_3D_ANAGLYGH, curState, startTime);

            // set 3D switch memento
            m_switchMemento.configMemento(
                VFX_TRUE,
                isSeekable(),
                shouldAutoPlay,
                totalDuration, 
                startTime,
                seekableRegion);

            // switch
            closeFile();
            setIs3DAnaglyphMode(swtchTo3D);
            openFileEx(filePath, VFX_FALSE, startTime);
            break;
        }
        case VGPS_CLOSED:
        default:
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_SWITCH_3D_ANAGLYGH_IN_WRONG_STATE);
            break;
        }
    }
    return VFX_TRUE;
}

VfxBool VappVideoPlayerComponent::getNeedResumePlayAfterSwitch3DAnaglyph()
{
    return m_needResumePlayAfterSwitch3DAnaglyph;
}

void VappVideoPlayerComponent::setNeedResumePlayAfterSwitch3DAnaglyph(const VfxBool needResumePlay)
{
    m_needResumePlayAfterSwitch3DAnaglyph = needResumePlay;
}

void VappVideoPlayerComponent::enableConsumeDRM(VfxBool shouldConsume)
{
    m_shouldConsumeDRM = shouldConsume;
}

void VappVideoPlayerComponent::enableAutoWaitPGDL(VfxBool enableAutoWait)
{
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][VideoCP][PDL] enableAutoWaitPGDL: %d", enableAutoWait);
    m_shouldWaitPGDLFile = enableAutoWait;
}

void VappVideoPlayerComponent::enableScrolling(VfxBool enableScrolling)
{
    m_allowScrolling = enableScrolling;
}

mmi_ret VappVideoPlayerComponent::onBearerSwitch(mmi_event_struct *param)
{
    VappVideoPlayerComponent *pThis = (VappVideoPlayerComponent*)handleToObject((VfxObjHandle)(param->user_data));
    if(NULL == pThis)
    {
        return MMI_RET_OK;
    }
    return pThis->handleBearerSwitch(param);
}

mmi_ret VappVideoPlayerComponent::handleBearerSwitch(mmi_event_struct *param)
{
    if(NULL == m_mdiPlayer){return MMI_RET_OK;}

    srv_cbm_bearer_event_struct *event = (srv_cbm_bearer_event_struct*)param;
    switch(event->type)
    {
        case SRV_CBM_BEARER_EVENT_DISCONNECT:
        {
            // SRV_CBM_BEARER_EVENT_DOSCONNECT notify APP that bearer dosconnect before bearer switch event
            // for example, when App (that has registered this event) is using the socket through WLAN,
            // if the WLAN is disconnected, App will receive DOSCONNECT before SWITCH event and NOT receive any socket error
            // note the SRV_CBM_BEARER_EVENT_DOSCONNECT happened in WLAN to WLAN or WLAN to PS only...

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_CBM_BEARER_EVENT_DISCONNECT, getState());
            if(m_mdiPlayer->canDisconnect())
            {
                // disconnect RTSP
                MDI_RESULT res = m_mdiPlayer->disconnect();
                setState(VGPS_PAUSED);
            }
            break;
        }
        case SRV_CBM_BEARER_EVENT_SWITCH:
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_CBM_BEARER_EVENT_SWITCH, getState());

            // note the SRV_CBM_BEARER_EVENT_DOSCONNECT happened while WLAN to WLAN or WLAN to PS only...
            // in PS to WLAN switch scenario, CBM will notify SRV_CBM_BEARER_EVENT_SWITCH only
            if(SRV_CBM_BEARER_SWITCH_PS_TO_WIFI == event->switch_type && m_mdiPlayer->canDisconnect())
            {
                // disconnect RTSP
                MDI_RESULT res = m_mdiPlayer->disconnect();
                setState(VGPS_PAUSED);
            }
            //[MAUI_03113958] release bearer while recieve to switch bearer
            if(m_mdiPlayer->canDisconnect())
            {
                m_mdiPlayer->releaseBearer();
            }
            // if streaming player are active, reconnect to RTSP
            // if result is fail, notify user as play finished
            MDI_RESULT playResult = playAfterAudioReady();
            if(MDI_RES_VDOPLY_SUCCEED != playResult)
            {
                handlePlayFinished(playResult);
            }
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

MDI_RESULT VappVideoPlayerComponent::openFile(const VfxWString &filePath)
{
    return openFileEx(filePath, VFX_FALSE, 0);
}

MDI_RESULT VappVideoPlayerComponent::openFileEx(const VfxWString &filePath, VfxBool isRTSPLink, U64 startTimeHint, VfxBool isPDL)
{
    m_videoFilePath = filePath;

    VfxBool isStreaming = VFX_FALSE;
#if defined(__MMI_VIDEO_STREAM__) && defined(__COSMOS_MMI_PACKAGE__)
    const filetypes_group_type_enum group = srv_fmgr_types_find_group_by_filename_str(filePath.getBuf());
    isStreaming = (FMGR_GROUP_STREAM == group || isRTSPLink);
#endif

    VappVideoPlayerInputSource inputSource;
    inputSource.m_path = filePath;
    inputSource.m_isLocalFile = isRTSPLink ? VFX_FALSE : VFX_TRUE;
    inputSource.m_isPDL = isPDL;
    inputSource.m_isStreaming = isStreaming? VFX_TRUE : VFX_FALSE;
    inputSource.m_startingTimeHint = startTimeHint;

     // RAM needs to read URL from file content
    const filetypes_file_type_enum fileType = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_filepath(filePath.getBuf());
    if(FMGR_TYPE_RAM == fileType)
    {
        inputSource.m_isLocalFile = VFX_FALSE;
        CHAR *asciiURL = NULL;
        VFX_ALLOC_MEM(asciiURL, VAPP_VIDEO_CP_URL_MAX_BUF_LENGTH, this);
        if(asciiURL)
        {
            FS_HANDLE fileHandle = NULL;
            U32 readed = 0;
            fileHandle = FS_Open((U16*)filePath.getBuf(), FS_READ_ONLY);
            memset(asciiURL, 0, VAPP_VIDEO_CP_URL_MAX_BUF_LENGTH);
            if(fileHandle >=0)
            {
                FS_Read(fileHandle, (void*)asciiURL, VAPP_VIDEO_CP_URL_MAX_BUF_LENGTH - 1, &readed);
                FS_Close(fileHandle);
                fileHandle = NULL;
            }

            VfxWChar* ucsURL = inputSource.m_path.lockBuf(VAPP_VIDEO_CP_URL_MAX_BUF_LENGTH);
            mmi_asc_to_ucs2((CHAR*)ucsURL, asciiURL);
            inputSource.m_path.unlockBuf();
            ucsURL = NULL;
        }

        VFX_FREE_MEM(asciiURL);
    }

#if defined(__MMI_VIDEO_STREAM__) && defined(__COSMOS_MMI_PACKAGE__)
    // WLAN prefer
    if(isStreaming)
    {
        VappGalleryStreamingSetting streamingSetting;
        const kal_uint32 accountId = streamingSetting.getActiveAccountId();
        const kal_uint8 cbmAppId = cbm_get_app_id(accountId);

        srv_cbm_register_bearer_event(
        SRV_CBM_BEARER_EVENT_DISCONNECT | SRV_CBM_BEARER_EVENT_SWITCH,
        cbmAppId,
        onBearerSwitch,
        getObjHandle());
     }
#endif

    return openImpl(inputSource);
}

MDI_RESULT VappVideoPlayerComponent::openResId(VfxResId resId)
{
    VappVideoPlayerInputSource inputSource;
    inputSource.m_isResId = VFX_TRUE;
    inputSource.m_resId = resId;
    return openImpl(inputSource);
}

MDI_RESULT VappVideoPlayerComponent::openImpl(const VappVideoPlayerInputSource &source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_OPEN_FILE);
    setState(VGPS_OPENING);

    // show wait icon
    if(m_waitIcon)
    {
    	m_waitIcon->bringToFront();
        m_waitIcon->start();
    }

    // open MDI (this is async call)
    m_videoOpenResult = MDI_RES_VDOPLY_SUCCEED;
    m_needResumePlayAfterReady = VFX_FALSE;

    // Re-initialize MDI logic
    VFX_OBJ_CLOSE(m_mdiPlayer);
    
    do
    {

        // Streaming
        #if defined(__MMI_VIDEO_STREAM__) && defined(__COSMOS_MMI_PACKAGE__)
        if(source.isStreaming())
        {
            VFX_OBJ_CREATE(m_mdiPlayer, VappGalleryMDIStreamingAdaptor, this);
            break;
        }
        #endif

        // PDL
        #if defined(__MMI_VIDEO_PDL__)
        if(source.isProgressiveDownload())
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PDL_CREATE_MDI_PLAYER);
            VFX_OBJ_CREATE(m_mdiPlayer, VappGalleryMDIVideoAdaptor, this);
            m_shouldWaitPGDLFile = VFX_TRUE;
            break;
        }
        #endif

        // Finally, local file.
        VFX_OBJ_CREATE(m_mdiPlayer, VappGalleryMDIVideoAdaptor, this);
    }while(0);
    
    VFX_ASSERT(m_mdiPlayer);
    m_mdiPlayer->config(this, m_appId, m_allowScrolling, m_option);

    // check if disable DRM consumption
    // to avoid re-openning and re-playing failed after any interrupt happened, ex: call
    if(!m_shouldConsumeDRM)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_DISABLE_NEXT_DRMCONSUMPTION);
        m_mdiPlayer->disableNextDRMConsumption();
    }

    // set anaglyph track mode
    m_mdiPlayer->setIs3DAnaglyphMode(getIs3DAnaglyphMode());

    // set subtitle parameter
    if(m_option.supportSubtitle && m_mdiPlayer->canSwitchSubtitle())
    {
        m_mdiPlayer->setSubtitleInfoIndex(getSubtitleIndex());
    }

    // open file
    m_mdiPlayer->getVideoOpenSignal().connect(this, &VappVideoPlayerComponent::handleVideoOpenResult);
    MDI_RESULT res = m_mdiPlayer->openVideo(source);

    if(MDI_RES_VDOPLY_SUCCEED != res)
    {
        if(m_waitIcon)
        {
            m_waitIcon->stop();
        }
        setErrorIcon(getErrorIconFromMDIResult(res));
        popupMDIErrorMessage(res);
        setState(VGPS_CLOSED);
        delayEmitFileReady(res);
    }
    return res;
}

MDI_RESULT VappVideoPlayerComponent::closeFile()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_CLOSE_FILE);

    // hide video frame
    m_display->hideDisplay(VFX_TRUE);
    // hide audio only icon
    if(m_audioOnlyIconFrame)
    {
        m_audioOnlyIconFrame->setHidden(VFX_TRUE);
    }

#if defined(__MMI_VIDEO_STREAM__) && defined(__COSMOS_MMI_PACKAGE__)
    // WLAN prefer
    if(m_mdiPlayer && m_mdiPlayer->canDisconnect())
    {
        VappGalleryStreamingSetting streamingSetting;
        const kal_uint32 accountId = streamingSetting.getActiveAccountId();
        const kal_uint8 cbmAppId = cbm_get_app_id(accountId);

        srv_cbm_deregister_bearer_event(cbmAppId);
     }
#endif

    MDI_RESULT res = MDI_RES_VDOPLY_SUCCEED;
    if(m_mdiPlayer)
    {
        VFX_OBJ_CLOSE(m_mdiPlayer);
        m_mdiPlayer = NULL;
    }

    restoreLayerAndUnprepareVideoFrame();

    // clear current video file path
    m_videoFilePath.setNull();
    m_videoOpenResult = MDI_RES_VDOPLY_SUCCEED;
    m_needResumePlayAfterReady = VFX_FALSE;

    setState(VGPS_CLOSED);
    return res;
}

MDI_RESULT VappVideoPlayerComponent::play()
{
    return playWithSpeed(VGPS_SPEED_1X);
}

MDI_RESULT VappVideoPlayerComponent::playWithSpeed(VappVideoPlayerSpeed speed)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PLAY_WITH_SPEED);

    if(isMakingCall() && !m_option.enablePlayDuringCall)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_CANNOT_PLAY_WITH_SPEED_DURING_CALL);
        return MDI_RES_VDOPLY_ERR_PLAY_FAILED;
    }

    // check if video frame is ready
    // if not, auto play after recieving video frame ready signal
    if(m_videoFrameNotReady)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PLAY_WITH_SPEED_WHILE_VIDEO_FRAME_NOT_READY);

        m_needResumePlayAfterReady = VFX_TRUE;
        return MDI_RES_VDOPLY_ERR_PLAY_FAILED;
    }

    const VappVideoPlayerState curState = getState();
    if(VGPS_SEEKING == curState)
    {
        // if we call play during seeking, player sould play after seek finished
        m_needResumePlayAfterEndSeek = VFX_TRUE;
        return MDI_RES_VDOPLY_ERR_PLAY_FAILED;
    }
    if(VGPS_CLOSED == curState ||
       VGPS_OPENING == curState ||
       VGPS_PLAYING == curState)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PLAY_WITH_SPEED_WRONG_STATE, curState);
        return MDI_RES_VDOPLY_ERR_PLAY_FAILED;
    }

    if(VGPS_SPEED_1X != speed)
    {
        // For now, COSMOS only support 1X playing
        VFX_ASSERT(0);
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

    // check if we need to delay play until
    // A2DP is connected. It may take sometime for A2DP to connect.
    if(m_connectingBT)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

    // suspend the background audio while ready to play
    // [MAUI_03085953] note we should supened background audio before try to connect BT device
    if(NULL == m_hBackgroundPlay)
    {
        if(!m_option.disableAudio)
        {
            m_hBackgroundPlay = mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_ANON_APP);
        }
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_MDI_AUDIO_SUSPEND_BACKGROUND_PLAY_BY_APP, m_hBackgroundPlay);
    }

    if(!_isUserSetBTOutput() ||
       !createA2DPConnection(VFX_TRUE))
    {
        return playAfterAudioReady();
    }

    return MDI_RES_VDOPLY_SUCCEED;
}

MDI_RESULT VappVideoPlayerComponent::playAfterAudioReady()
{
    if(!m_option.disableAudio &&
       m_currentVideoInfo.track != MDI_VIDEO_TRACK_V_ONLY)
    {
        const srv_prof_volume_level vol = m_option.useRingVol ? srv_prof_get_ring_vol() : srv_prof_get_media_vol();
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, vol);
    }

    if(m_mdiPlayer)
    {
        m_mdiPlayer->getSeekDoneSignal().connect(this, &VappVideoPlayerComponent::handleAsyncSeekResult);
        m_mdiPlayer->getPlayFinishSignal().connect(this, &VappVideoPlayerComponent::handlePlayFinished);
        return playAndChangeState();
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_PLAY_FAILED;
    }
}

MDI_RESULT VappVideoPlayerComponent::playAndChangeState()
{
    const VappVideoPlayerState curState = getState();
    if(VGPS_CLOSED == curState ||
       VGPS_OPENING == curState ||
       VGPS_PLAYING == curState)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PLAY_AND_CHANGE_STATE_WRONG_STATE, curState);
        return MDI_RES_VDOPLY_ERR_PLAY_FAILED;
    }

    SWLA_BEGIN("PCS");
    // disable consumption must be called right before MDI play().
    if(!m_shouldConsumeDRM)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_DISABLE_NEXT_DRMCONSUMPTION);
        m_mdiPlayer->disableNextDRMConsumption();
    }

    MDI_RESULT res = MDI_RES_VDOPLY_SUCCEED;
    if(m_display &&
       m_display->getIsDisplayReady() &&
       MDI_VIDEO_TRACK_A_ONLY != m_currentVideoInfo.track)
    {
        res = m_mdiPlayer->play(m_display->getVideoDisplay(), m_display->getSubtitleDisplay(), m_currentVideoInfo);
    }
    else
    {
        // audio only case
        // note MDI supposed subtitle track exists only if there is a video track currently
        res = m_mdiPlayer->play(NULL, NULL, m_currentVideoInfo);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PLAY, res);
    switch(res)
    {
    case MDI_RES_VDOPLY_SUCCEED:
        m_needResumePlayAfterReady = VFX_FALSE;
        setState(VGPS_PLAYING);
        if(m_waitIcon)
        {
            m_waitIcon->stop();
        }
        break;
    case MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW:
    case MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH:
        if(m_shouldWaitPGDLFile || MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW == res)
        {
            if(m_waitIcon)
            {
                m_waitIcon->bringToFront();
                m_waitIcon->start();
            }
            m_needResumePlayAfterEndSeek = VFX_TRUE;
            setState(VGPS_SEEKING);
        }
        else
        {
            setState(VGPS_PAUSED);
            popupMDIErrorMessage(res);
        }
        break;
    default:
        popupMDIErrorMessage(res);
        break;
    }
    SWLA_END("PCS");
    return res;
}

MDI_RESULT VappVideoPlayerComponent::pause()
{
    if(VGPS_CLOSED == getState() ||
       VGPS_OPENING == getState())
    {
        return MDI_RES_VDOPLY_ALREADY_FINISHED;
    }

    MDI_RESULT res = MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;;
    if(m_mdiPlayer)
    {
        res = m_mdiPlayer->stop();
    }

    if(m_waitIcon)
    {
        m_waitIcon->stop();
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PAUSE, res);
    if(0 <= res)
    {
        setState(VGPS_PAUSED);
    }

    return res;
}

void VappVideoPlayerComponent::swithVideoLayerToHW()
{
    SWLA_BEGIN("VHW");
    if(m_display && VGPS_PAUSED == getState())
    {
        m_display->switchDisplayLayerToHW();
    }
    SWLA_END("VHW");
}

void VappVideoPlayerComponent::swithVideoLayerToSW(VfxBool convertToRGB565)
{
    if(m_display && VGPS_PAUSED == getState())
    {
        m_display->switchDisplayLayerToSW(convertToRGB565);
    }
}

void VappVideoPlayerComponent::restoreLayerAndUnprepareVideoFrame()
{
    if(VGPS_PAUSED == getState() && m_display)
    {
        m_display->switchDisplayLayerToHW();
    }
    if(m_display)
    {
        m_display->restoreAndUnprepareDisplay();
    }  
}

MDI_RESULT VappVideoPlayerComponent::stop()
{
    if(VGPS_CLOSED == getState() ||
       VGPS_OPENING == getState())
    {
        return MDI_RES_VDOPLY_ALREADY_FINISHED;
    }

    VfxBool forceToNotifyAppUIChanged = VFX_FALSE;
    MDI_RESULT res = MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    if(m_mdiPlayer)
    {
        // stop playback
        res = m_mdiPlayer->stop();
        // seek to begin
        if(m_mdiPlayer->canSeekWithoutBuffering())
        {
            m_mdiPlayer->blockingSeek(0);
            forceToNotifyAppUIChanged = VFX_TRUE;
        }
    }

    if(m_waitIcon)
    {
        m_waitIcon->stop();
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STOP, res);
    if(MDI_RES_VDOPLY_SUCCEED == res)
    {
        setState(VGPS_PAUSED, forceToNotifyAppUIChanged);
    }

    return res;
}

VfxBool VappVideoPlayerComponent::isVideoTrackSupported()
{
    if(NULL == m_mdiPlayer)
    {
        return VFX_FALSE;
    }

    if(MDI_VIDEO_TRACK_A_ONLY == m_currentVideoInfo.track)
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}

VfxBool VappVideoPlayerComponent::isSeekable()
{
    if(m_switchMemento.isSwitching())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_IS_SEEKABLE, m_switchMemento.isSeekable());
        return m_switchMemento.isSeekable();
    }

    if(NULL == m_mdiPlayer)
    {
        return VFX_FALSE;
    }

    switch(getState())
    {
    case VGPS_CLOSED:
    case VGPS_OPENING:
        return VFX_FALSE;

    case VGPS_PAUSED:
    case VGPS_PLAYING:
    case VGPS_SEEKING:
        return m_mdiPlayer->canSeek() &&
               (0 < m_currentVideoInfo.total_time_duration) &&
               (MMI_TRUE == m_currentVideoInfo.is_seekable);
    }

    return VFX_FALSE;
}

MDI_RESULT VappVideoPlayerComponent::getSeekableRegion(VappVideoMsec &seekableRegion)
{
    MDI_RESULT ret = MDI_RES_VDOPLY_ERR_FAILED;
    if(m_switchMemento.isSwitching())
    {
        ret = m_switchMemento.getSeekableRegion(seekableRegion);        
    }
    else if(NULL == m_mdiPlayer)
    {
        ret = MDI_RES_VDOPLY_ERR_FAILED;
    }
    else
    {
        switch(getState())
        {
        case VGPS_CLOSED:
        case VGPS_OPENING:
            ret = MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
            break;
        case VGPS_PAUSED:
        case VGPS_PLAYING:
        case VGPS_SEEKING:
            ret = m_mdiPlayer->getSeekableRegion(seekableRegion);
            break;
        }
    }
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_GET_SEEKABLE_REGION, ret, seekableRegion);
    return ret;
}

MDI_RESULT VappVideoPlayerComponent::seek(VappVideoMsec time, VappVideoPlayerSeekHint)
{
    // after user seek, we should start play from seeked point.
    // currently there is no seek hint.
    MDI_RESULT seekResult = MDI_RES_VDOPLY_SUCCEED;

    // make sure we're HW layer before calling seek
    swithVideoLayerToHW();

    if(VGPS_PAUSED == getState() &&
       m_display &&
       (m_display->hasValidVideoLayerHandle() || m_display->hasValidSubtitleLayerHandle()) &&
       m_mdiPlayer &&
       m_mdiPlayer->canGetStillFrame())
    {
        seekResult = m_mdiPlayer->seekAndGetFrame(time, m_display->getVideoLayerHandle(), m_display->getSubtitleLayerHandle());
    }
    else if(m_mdiPlayer)
    {
        // must wait for buffering
        seekResult = m_mdiPlayer->seek(time);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_SEEK, seekResult);

    if(MDI_RES_VDOPLY_SUCCEED == seekResult)
    {
        m_mdiPlayer->getSeekDoneSignal().connect(this, &VappVideoPlayerComponent::handleAsyncSeekResult);
        setState(VGPS_SEEKING);

        if (!m_mdiPlayer->canSeekWithoutBuffering())
        {
            if(m_waitIcon)
            {
            	m_waitIcon->bringToFront();
                m_waitIcon->start();
            }
        }
    }
    else
    {
        // error handle for get frame failed which is caused content is audio track supported only
        if(MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED == seekResult)
        {
            return seekResult;
        }

        popupMDIErrorMessage(seekResult);
    }

    return seekResult;

}

MDI_RESULT VappVideoPlayerComponent::getTotalDuration(VappVideoMsec &totalDuration)
{
    SWLA_BEGIN("GTD");
    // return total duration in memento record while switching 3D mode
    if(m_switchMemento.isSwitching())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_GET_TOTAL_DURATION);
        SWLA_END("GTD");
        return m_switchMemento.getTotalTime(totalDuration);
    }

    switch(getState())
    {
        case VGPS_CLOSED:
        case VGPS_OPENING:
            return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }

    totalDuration = m_currentVideoInfo.total_time_duration;
    SWLA_END("GTD");
    return MDI_RES_VDOPLY_SUCCEED;
}

MDI_RESULT VappVideoPlayerComponent::getCurrentTime(VappVideoMsec &currentTime)
{
    // return current in memento record while switching 3D mode
    if(m_switchMemento.isSwitching())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_GET_CUR_TIME);
        return m_switchMemento.getCurrentTime(currentTime);
    }

    if(VGPS_CLOSED == getState() || NULL == m_mdiPlayer)
    {
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }

    return m_mdiPlayer->getCurrentPlayTime(currentTime);
}

MDI_RESULT VappVideoPlayerComponent::getKeyFrameTime(const VappVideoMsec refrenceTime, VappVideoMsec &keyFrameTime)
{
    if(NULL == m_mdiPlayer || !m_mdiPlayer->canGetKeyFrame())
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

    switch(getState())
    {
    case VGPS_CLOSED:
    case VGPS_OPENING:
        return MDI_RES_VDOPLY_ERR_FAILED;
    case VGPS_PAUSED:
    case VGPS_PLAYING:
    case VGPS_SEEKING:
        return m_mdiPlayer->getKeyFrameTime(refrenceTime, keyFrameTime);
    }
	return MDI_RES_VDOPLY_ERR_FAILED;
}

VfxBool VappVideoPlayerComponent::canClip() const
{
#ifdef __MMI_VIDEO_CLIPPER__
    if(NULL == m_mdiPlayer)
    {
        return VFX_FALSE;
    }

    switch(getState())
    {
    case VGPS_CLOSED:
    case VGPS_OPENING:
        return VFX_FALSE;

    case VGPS_PAUSED:
    case VGPS_PLAYING:
    case VGPS_SEEKING:
        return (MMI_TRUE == vcui_videoclipper_is_available(&m_currentVideoInfo) ? VFX_TRUE : VFX_FALSE);
    default:
        return VFX_FALSE;
    }
#endif
    return VFX_FALSE;
}

VfxBool VappVideoPlayerComponent::canChangePlayPausedState() const
{
    switch(getState())
    {
    case VGPS_CLOSED:
    case VGPS_OPENING:
        return VFX_FALSE;

    case VGPS_PAUSED:
    case VGPS_PLAYING:
    case VGPS_SEEKING:		
        if(MDI_VIDEO_TRACK_A_ONLY == m_currentVideoInfo.track)
            return VFX_TRUE;
        if(m_display && m_display->getIsDisplayReady())
            return VFX_TRUE;
        return VFX_FALSE;
    default:
        return VFX_FALSE;
    }
}

MDI_RESULT VappVideoPlayerComponent::getVideoAspectRatio(VfxS32 &width, VfxS32 &height)
{
    switch(getState())
    {
    case VGPS_CLOSED:
    case VGPS_OPENING:
        width = 0;
        height = 0;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_GET_VIDEO_ASPECT_RATIO_CALLED_WHEN_NOT_READY);
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    default:
        break;
    }

    // note: if audio only, no need to prepare VideoFrame
    // in such case, the aspect ratio is same as audio_only_image
    if(MDI_VIDEO_TRACK_A_ONLY == m_currentVideoInfo.track)
    {
        VfxImageSrc imgAudioOnly(getAudioOnlyIcon());
        width = imgAudioOnly.getSize().width;
        height = imgAudioOnly.getSize().height;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_GET_VIDEO_ASPECT_VIDEO_SIZE, m_currentVideoInfo.width, m_currentVideoInfo.height);

        if(0 == m_currentVideoInfo.width || 0 == m_currentVideoInfo.height)
        {

            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            width  = topLevel->getSize().width;
            height = topLevel->getSize().height;

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_GET_VIDEO_ASPECT_INVALID_SIZE,
                m_currentVideoInfo.width, m_currentVideoInfo.height,
                width, height);
        }
        else
        {
            // workaround for MAUI_02957167
            VfxPoint videoPos;
            VfxSize videoSize;

            gdi_util_fit_box(
                GDI_UTIL_MODE_LONG_SIDE_FIT,
                GDI_LCD_WIDTH,
                GDI_LCD_HEIGHT,
                m_currentVideoInfo.width,
                m_currentVideoInfo.height,
                &videoPos.x,
                &videoPos.y,
                &videoSize.width,
                &videoSize.height);

            width = videoSize.width;
            height = videoSize.height;

            if(0 == width){width = 2;}
            if(0 == height){height = 2;}
        }
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_GET_VIDEO_ASPECT_RETURN_SIZE, width, height);

    return MDI_RES_VDOPLY_SUCCEED;
}

MDI_RESULT VappVideoPlayerComponent::prepareAndShowVideo(mdi_video_info_struct* videoInfo)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PREPARE_AND_SHOW_VIDEO);

    VfxPoint videoPos;
    VfxSize videoSize;
#ifdef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
    // create video layer with max size (note we do not need to calculate aspect ratio)
    videoSize = getSize();
    videoPos.x = 0;
    videoPos.y = 0;
#else
    // keep the aspect ratio.
    gdi_util_fit_box(
            GDI_UTIL_MODE_LONG_SIDE_FIT,
            getSize().width,
            getSize().height,
            videoInfo->width,
            videoInfo->height,
            &videoPos.x,
            &videoPos.y,
            &videoSize.width,
            &videoSize.height);

    // note: video size MUST be 2x
    videoSize.width &= ~0x1;
    videoSize.height &= ~0x1;
#endif
    // video size MUST NOT be 0
    if(0 == videoSize.width)
        videoSize.width = 2;

    if(0 == videoSize.height)
        videoSize.height = 2;

    // guarantee valid video frame size
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    if(topLevel->getSize().width < videoSize.width)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PREPARE_AND_SHOW_VIDEO_INVALID_WIDTH, videoSize.width, topLevel->getSize().width  );
        videoSize.width = topLevel->getSize().width;
    }
    if(topLevel->getSize().height < videoSize.height)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PREPARE_AND_SHOW_VIDEO_INVALID_HEIGHT, videoSize.height, topLevel->getSize().height);
        videoSize.height = topLevel->getSize().height;
    }

    // update pos/size then prepare.
    m_display->setDisplayPos(videoPos.x, videoPos.y);
    m_display->setDisplaySize(videoSize);
    m_display->hideDisplay(VFX_FALSE);

    // prepare Video frame
    // Note: size CANNOT change after prepare().
#if 0
/* under construction !*/
#else
    if(!m_display->prepareDisplay())
    {
        // prepare failed, no memory for HW layer
        return MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT;
    }
#endif

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PREPARE_AND_SHOW_VIDEO_SET_M_VIDEO_FRAME_NOT_READY_TRUE);
    m_videoFrameNotReady = VFX_TRUE;

    // check if we can really decode this file.
    VFX_ASSERT(m_mdiPlayer);

    // clean gdi layer
    if(m_display)
    {
        m_display->clean();
    }

    // Note: the HW layer is already allocated
    // after calling m_videoFrame->prepare()
    // so we try to fill video content here

    // note MDI always returns successful result while gets a frame of subtitle track
    // insteading of checking getFrame result only, make sure both video frames(video and subtitle track) is prepared
    // i.e we can blt/ notify content is dirty
    // to avoid black flash caused by unprepared subtitle video frame
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PREPARE_AND_SHOW_VIDEO_IS_READY, m_display->getIsDisplayReady());
    if(m_mdiPlayer->canGetStillFrame() && m_display->getIsDisplayReady())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PREPARE_AND_SHOW_VIDEO_GET_FRAME);
        m_needBlockingSeekAndGetFrame = VFX_FALSE;
        MDI_RESULT firstFrameResult = m_mdiPlayer->blockingGetFrame(m_display->getVideoLayerHandle(), m_display->getSubtitleLayerHandle());
        if(MDI_RES_VDOPLY_SUCCEED == firstFrameResult)
        {
            m_display->invalidate();
            return firstFrameResult;
        }
    }
    // if fail to draw first frame to layer, we clear
    // the layer directly and hope it can play later.
    // e.g. Streaming player cannot get first frame
    if(m_display)
    {
        m_display->clean();
    }
    return MDI_RES_VDOPLY_SUCCEED;
}

VfxBool VappVideoPlayerComponent::canToggleSubtitle() const
{
    // check option
    if(!m_option.supportSubtitle)
    {
        return VFX_FALSE;
    }
    // check if mdiPlayer support subtitle
    if(NULL == m_mdiPlayer || !m_mdiPlayer->canSwitchSubtitle())
    {
        return VFX_FALSE;
    }

    // check state and subtitle track num
    const VappVideoPlayerState curState = getState();
    switch(curState)
    {
    case VGPS_PLAYING:
    case VGPS_SEEKING:
    case VGPS_PAUSED:
        return (0 < m_mdiPlayer->querySubtitleTrackCount(m_currentVideoInfo) ? VFX_TRUE : VFX_FALSE);
    case VGPS_OPENING:
    case VGPS_CLOSED:
    default:
        return VFX_FALSE;
    }
}

VfxBool VappVideoPlayerComponent::toggleSubtitle(const VfxBool on)
{
    if(!canToggleSubtitle()){return VFX_FALSE;}
    // TODO:
    return VFX_TRUE;
}

VfxBool VappVideoPlayerComponent::switchSubtitle(const VfxS32 infoIndex)
{
    if(!canToggleSubtitle()){return VFX_FALSE;}

    const VappVideoPlayerState curState = getState();
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_SWITCH_SUBTITLE, getSubtitleIndex(), curState);

    switch(curState)
    {
        case VGPS_SEEKING:
        case VGPS_PLAYING:
        case VGPS_PAUSED:
        {
            setNeedResumePlayAfterSwitch3DAnaglyph(VFX_FALSE);

            // pause playback
            const VfxBool shouldAutoPlay = (VGPS_PLAYING == curState)? VFX_TRUE : VFX_FALSE;
            setNeedResumePlayAfterSwitch3DAnaglyph(shouldAutoPlay);
            pause();

            VfxWString filePath = m_videoFilePath;
            VappVideoMsec totalDuration = 0;
            VappVideoMsec startTime = 0;
            VappVideoMsec seekableRegion = 0;
            getTotalDuration(totalDuration);
            getCurrentTime(startTime);
            getSeekableRegion(seekableRegion);
            
            m_switchMemento.configMemento(
                VFX_TRUE,
                isSeekable(),
                shouldAutoPlay,
                totalDuration, 
                startTime,
                seekableRegion);

            // switch subtitle
            closeFile();
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_SWITCH_SUBTITLE_2, getSubtitleIndex());
            setSubtitleIndex(infoIndex);
            openFileEx(filePath, VFX_FALSE, startTime);
            return VFX_TRUE;
        }
        case VGPS_OPENING:
        case VGPS_CLOSED:
        default:
        {
            return VFX_FALSE;
        }
    }
}

VfxBool VappVideoPlayerComponent::getSubtitleLanguageName(const VfxS32 infoIndex, VfxWString &name) const
{
    if(!canToggleSubtitle()){return VFX_FALSE;}
    return m_mdiPlayer->querySubtitleLanguageName(m_currentVideoInfo, infoIndex, name);
}

VfxS32 VappVideoPlayerComponent::getSubtitleTrackCount() const
{
    if(!canToggleSubtitle()){return 0;}
    return m_mdiPlayer->querySubtitleTrackCount(m_currentVideoInfo);
}

void VappVideoPlayerComponent::setVideoScreenMode(const VappVideoPlayerScreenMode newMode)
{
    if(VFX_FALSE == isScreenModeSupported(newMode))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_SWITCH_SET_SCREEN_MODE_ERR, newMode);
        return;
    }

    if(NULL == m_mdiPlayer)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_SWITCH_SET_SCREEN_MODE_ERR_2);
        return;
    }

    // update screen mode
    // note change mode error will return by playFinishedCallback or seekAndGetFrame callback
    m_screenMode = newMode;

    // if it is audio track only, do nothing
    const VfxBool isAudioOnly = (NULL == m_display) || (!m_display->hasVideoDisplay()) || (MDI_VIDEO_TRACK_A_ONLY == m_currentVideoInfo.track);
    if(isAudioOnly)
    {
        return;
    }

    // change mode
    const U8 mdiScreenMode = convertToMDIScreenModeID(newMode);
    const VappVideoPlayerState curState = getState();
    switch(curState)
    {
        case VGPS_PLAYING:
        {
            if(m_display->getIsDisplayReady())
            {
                m_mdiPlayer->changeVideoScreenMode(mdiScreenMode,
                                                   m_display->getVideoDisplay(),
                                                   m_display->getSubtitleDisplay(),
                                                   VFX_TRUE,
                                                   isAudioOnly);
                showAudioOnlyIcon(isAudioOnly);
            }
            break;
        }
        case VGPS_PAUSED:
        {
            m_mdiPlayer->changeVideoScreenMode(mdiScreenMode, NULL, NULL, VFX_FALSE, VFX_FALSE);
            // update frame content
            // note streaming dose not support get frame
            if(m_mdiPlayer->canGetStillFrame())
            {
                /*
                // make sure layer handle ptr is non-cacheable address before get frame or seek
                swithVideoLayerToHW();
                m_mdiPlayer->blockingGetFrame(m_videoFrame->getLayerHandle());
                // notify video frame that content is dirty
                m_videoFrame->invalidate();
                */
                swithVideoLayerToHW();
                MDI_RESULT firstFrameResult = m_mdiPlayer->blockingGetFrame(m_display->getVideoLayerHandle(), m_display->getSubtitleLayerHandle());
                m_display->invalidate();
            }
            else
            {
                VappVideoMsec currentPosition = 0;
                getCurrentTime(currentPosition);
                seek(currentPosition);
            }
            break;
        }
        default:
        {
            m_mdiPlayer->changeVideoScreenMode(mdiScreenMode, NULL, NULL, VFX_FALSE, VFX_FALSE);
            break;
        }
    }
}

VfxS32 VappVideoPlayerComponent::getSupportedScreenModeCount()
{
    VfxS32 num = 0;
    for(VfxS8 i =0; i < VS_END_OF_MODE; i ++)
    {
        VappVideoPlayerScreenMode mode = (VappVideoPlayerScreenMode)(VS_STRETCH + i);
        if(isScreenModeSupported(mode))
        {
            num = num + 1;
        }
    }
    return num;
}

VfxBool VappVideoPlayerComponent::isScreenModeSupported(const VappVideoPlayerScreenMode mode)
{
    switch(mode)
    {
    case VS_STRETCH:
        // stretch mode is always supported
        return VFX_TRUE;
    case VS_INSIDE:
        #ifdef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
            return VFX_TRUE;
        #else
            return VFX_FALSE;
        #endif
    case VS_OUTSIDE:
        #ifdef __MDI_DISPLAY_FIT_OUTSIDE_SUPPORT__
            return VFX_TRUE;
        #else
            return VFX_FALSE;
        #endif
    default:
        return VFX_FALSE;
    }
}

VappVideoPlayerScreenMode VappVideoPlayerComponent::getDefaultScreenMode()
{
    if(m_option.isWallpaperScenario)
    {
        return VS_OUTSIDE;
    }

    return convertToScreenModeID(getMDIDefaultScreenMode());
}

VappVideoPlayerScreenMode VappVideoPlayerComponent::convertToScreenModeID(const U8 mdiMode)
{
    VappVideoPlayerScreenMode mode = VS_END_OF_MODE;
    switch(mdiMode)
    {
        case MDI_VIDEO_FRAME_MODE_FIT_INSIDE:
            mode = VS_INSIDE;
            break;
        case MDI_VIDEO_FRAME_MODE_FIT_OUTSIDE:
            mode = VS_OUTSIDE;
            break;
        case MDI_VIDEO_FRAME_MODE_STRETCH:
            mode = VS_STRETCH;
            break;
        default:
            mode = VS_END_OF_MODE;
            break;
    }
    return mode;
}

U8 VappVideoPlayerComponent::convertToMDIScreenModeID(const VappVideoPlayerScreenMode mode)
{
    U8 mdiMode = MDI_VIDEO_FRAME_MODE_STRETCH;
    switch(mode)
    {
        case VS_INSIDE:
            mdiMode = MDI_VIDEO_FRAME_MODE_FIT_INSIDE;
            break;
        case VS_OUTSIDE:
            mdiMode = MDI_VIDEO_FRAME_MODE_FIT_OUTSIDE;
            break;
        case VS_STRETCH:
            mdiMode = MDI_VIDEO_FRAME_MODE_STRETCH;
            break;
        default:
            mdiMode = getMDIDefaultScreenMode();
            break;
    }
    return mdiMode;
}

U8 VappVideoPlayerComponent::getMDIDefaultScreenMode()
{
#ifdef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
    return MDI_VIDEO_FRAME_MODE_FIT_INSIDE;
#else
    return MDI_VIDEO_FRAME_MODE_STRETCH;
#endif
}
// TODO: check
void VappVideoPlayerComponent::createDisplay(const mmi_id appid)
{
    VfxVideoFrame *videoFrame = NULL;
    VFX_OBJ_CREATE(videoFrame, VfxVideoFrame, this);
    videoFrame->setMultimediaType(VfxVideoFrame::MULTIMEDIA_VIDEO);
    videoFrame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);

#ifdef __VENUS_3D_UI_ENGINE__
    // wallpaper + V3D case, we must prevent color format change,
    // since it cause OpenGL re-init and takes long time.
    if(m_option.isWallpaperScenario)
    {
        // setHint() is VfxVideoFrame-specific, this is NOT VfxFrame::setHints().
        videoFrame->setHint(VfxVideoFrame::HINT_PREVENT_VRT_COLOR_FORMAT_CHANGE_IN_SCREEN);
    }
#endif

    // substitle display frame
    VfxVideoFrame *subtitleFrame = NULL;
    if(m_option.supportSubtitle)
    {
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
        VFX_OBJ_CREATE(subtitleFrame, VfxVideoFrame, this);
        // set multimedia type and color format
        subtitleFrame->setMultimediaType(VfxVideoFrame::MULTIMEDIA_SUBTITLE);
        subtitleFrame->setColorFormat(VRT_COLOR_TYPE_ARGB8888);
        // set UI style
        subtitleFrame->setAnchor(0.5, 1);
        subtitleFrame->setPos(SUBTITLE_DISPLAY_X, SUBTITLE_DISPLAY_Y);
#endif
    }

    // create display handle
    VFX_ASSERT(NULL == m_display);
    VFX_OBJ_CREATE(m_display, VappVideoPlayerComponentDisplay, this);
    m_display->setupDisplay(videoFrame, subtitleFrame);
}

void VappVideoPlayerComponent::setErrorIcon(VfxId iconImgId)
{
    if(m_waitIcon)
    {
        m_waitIcon->stop();
    }
    if(m_display)
    {
        m_display->hideDisplay(VFX_TRUE);
    }

    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    if(m_option.isWallpaperScenario && !m_option.isPreview)
    {
        if(m_option.defaultBackground.isNull())
        {
        }
        else
        {
            setImgContent(m_option.defaultBackground);
        }
    }
    else
    {
        setImgContent(VfxImageSrc(iconImgId));
    }
    invalidate();
}

void VappVideoPlayerComponent::createAudioOnlyIcon()
{
    if(m_audioOnlyIconFrame){return;}

    // audio only icon
    VFX_OBJ_CREATE(m_audioOnlyIconFrame, VfxFrame, this);
    m_audioOnlyIconFrame->setSize(getSize());
    m_audioOnlyIconFrame->setPos(0, 0);

    VfxImageSrc imgAudioOnly(getAudioOnlyIcon());
    m_audioOnlyIconFrame->setImgContent(imgAudioOnly);
    m_audioOnlyIconFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    m_audioOnlyIconFrame->setHidden(VFX_TRUE);
}

void VappVideoPlayerComponent::showAudioOnlyIcon(const VfxBool showAudioIcon)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_SHOW_AUDIO_ONLY_ICON, showAudioIcon);

    // note that we don't stop m_waitIcon like setErrorIcon(),
    // since waitIcon may be displayed during seeking an audio file.
    createAudioOnlyIcon();
    if(showAudioIcon)
    {
        if(getSize() != m_audioOnlyIconFrame->getSize())
        {
            m_audioOnlyIconFrame->setSize(getSize());
        }

        VfxImageSrc imgAudioOnly(getAudioOnlyIcon());
        if(imgAudioOnly.getSize().width > m_audioOnlyIconFrame->getSize().width ||
           imgAudioOnly.getSize().height > m_audioOnlyIconFrame->getSize().height)
        {
            m_audioOnlyIconFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
        }
        else
        {
            m_audioOnlyIconFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
        }

        m_audioOnlyIconFrame->setHidden(VFX_FALSE);
    }
    else
    {
        m_audioOnlyIconFrame->setHidden(VFX_TRUE);
    }

    invalidate();
}

S16 VappVideoPlayerComponent::convertMDIPlaySpeed(VappVideoPlayerSpeed speed)
{
    switch(speed)
    {
    case VGPS_SPEED_1X:
        return 100;
    case VGPS_SPEED_HALF_X:
        return 50;
    case VGPS_SPEED_1_HALF_X:
        return 150;
    case VGPS_SPEED_2X:
        return 200;
    default:
        VFX_DEV_ASSERT(VFX_FALSE);  // unrecognized speed
        return 100;
    }
}

void VappVideoPlayerComponent::handleAsyncSeekResult(MDI_RESULT ret, mdi_video_info_struct *video_info)
{
    m_videoSeekResult = ret;

    // if connection is disconnected while we attempted to playback,
    // This must be put in front of error handling of MDI_RES_VDOPLY_SUCCEED != ret.
    // we need to re play once to invoke seek and reconnect actions.
    if (MDI_RES_VDOPLY_ERR_NETWORK_DISCONNECT == ret || MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW == ret)
    {
        setState(VGPS_PAUSED);
        playAndChangeState();
        return;
    }

    // restore generic state.
    m_mdiPlayer->getVideoOpenSignal().connect(this, &VappVideoPlayerComponent::handleVideoOpenResult);

    // after async seek, start playing immediately
    // we don't have to re-prepare video frame
    if(m_waitIcon)
    {
        m_waitIcon->stop();
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_HANDLE_ASYNC_SEEK_RESULT, ret);

    // if fail to re-seek video, emit directly
    if(MDI_RES_VDOPLY_SUCCEED != ret && MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED != ret)
    {

        // for streaming case which not support seek without buffering, when finish playing, clean preview layer
        // for video case, clean preview layer while seek failed (not to show error icon)
        setState(VGPS_PAUSED);
        if(m_display)
        {
            m_display->cleanAndInvalidate();
        }

        popupMDIErrorMessage(ret);

        // if connection is disconnected while we attempted to playback,
        if (MDI_RES_VDOPLY_ERR_STREAM_BUFFER_FAILED == ret)
        {
             MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_OPENING_ERROR, ret);
            return;
        }

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_HANDLE_ASYNC_SEEK_RESULT_ERROR, ret);
        //setState(VGPS_CLOSED);
        //setErrorIcon(getErrorIconFromMDIResult(ret));
        //delayEmitFileReady(ret);
        return;
    }

    // check if show audio only icon
    // for streaming player, AP should query video width and height infor after buffer is larger than 0
    VfxBool needPrepareVideoFrame = VFX_FALSE;
    do
    {
        if(NULL == video_info)
            break;
        // check self-assignment and set video info
        if(&m_currentVideoInfo != video_info)
        {
            m_currentVideoInfo = *video_info;
        }

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_VIDEO_INFO_TOTAL_DURATION_D, m_currentVideoInfo.total_time_duration);

        // If audio only, no need to prepare VideoFrame
       if(MDI_VIDEO_TRACK_A_ONLY == m_currentVideoInfo.track)
        {
            // since video frame is invisible, it
            // will not invoke m_signalPlayReady
            // so we call onVideoFramePreparedAfterOpen() directly
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_HANDLE_ASYNC_SEEK_RESULT_SHOULD_SHOW_AUDIO_ONLY_ICON);
            showAudioOnlyIcon(VFX_TRUE);
            break;
        }
        else if (m_display->getIsDisplayReady())
        {
            break;
        }
        else
        {
            needPrepareVideoFrame = VFX_TRUE;
        }

    }while(0);

    if(!needPrepareVideoFrame)
    {
        onVideoFramePreparedAfterSeek();
    }
    else
    {
        restoreLayerAndUnprepareVideoFrame();
        // prepate VideoFrame
        m_display->getPlayReadyEvent()->disconnect(this, &VappVideoPlayerComponent::onVideoFramePreparedAfterOpen);
        m_display->getPlayReadyEvent()->connect(this, &VappVideoPlayerComponent::onVideoFramePreparedAfterSeek);

        MDI_RESULT prepareRes = prepareAndShowVideo(video_info);

        if(MDI_RES_VDOPLY_SUCCEED != prepareRes)
        {
            m_display->getPlayReadyEvent()->disconnect(this, &VappVideoPlayerComponent::onVideoFramePreparedAfterOpen);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PREPARE_AND_SHOW_VIDEO_ERROR, prepareRes);
            closeFile();
            popupMDIErrorMessage(prepareRes);
            setErrorIcon(getErrorIconFromMDIResult(ret));
        }
    }
}

void VappVideoPlayerComponent::onVideoFramePreparedAfterSeek()
{
    setState(VGPS_PAUSED);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_ON_VIDEO_FRAME_PREPARED_AFTER_SEEK_SET_M_VIDEO_FRAME_NOT_READY_FALSE);
    m_videoFrameNotReady = VFX_FALSE;

    if(m_display)
    {
        m_display->invalidate();
    }

    if(m_mdiPlayer->mustPlayAfterSeek() || m_needResumePlayAfterEndSeek)
    {
        m_needResumePlayAfterEndSeek = VFX_FALSE;

        play();
    }
    delayEmitSeekDone(m_videoSeekResult);
}

void VappVideoPlayerComponent::handleVideoOpenResult(MDI_RESULT ret, mdi_video_info_struct *videoInfo)
{
    // if fail to open video, set UI error icon and
    // emit directly

    if(m_waitIcon)
    {
        m_waitIcon->stop();
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_HANDLE_VIDEO_OPEN_RESULT, ret);
    if(MDI_RES_VDOPLY_SUCCEED != ret)
    {
        if (MDI_RES_VDOPLY_ERR_NETWORK_DISCONNECT == ret || MDI_RES_VDOPLY_ERR_STREAM_BUFFER_FAILED == ret)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_STREAMING_OPENING_ERROR, ret);

            setState(VGPS_PAUSED);
            popupMDIErrorMessage(ret);
            return;
        }

        setState(VGPS_CLOSED);
        setErrorIcon(getErrorIconFromMDIResult(ret));

        if(m_option.isWallpaperScenario)
        {
            // for MAUI_03070053 (Video live wallpaper setting)
            // note that Video Player app UE does not pop balloon in this case.
            popupMDIErrorMessage(ret);
        }
        delayEmitFileReady(ret);
        return;
    }

    // subtitle part
    if(m_option.supportSubtitle &&
       m_mdiPlayer->canSwitchSubtitle() &&
       VAPP_VIDEO_PLAYER_COMPONENT_DEFAULT_SUBTITLE_INFO_INDEX < m_mdiPlayer->getSubtitleInfoIndex())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_HANDLE_VIDEO_OPEN_RESULT_SUBTITLE_COUNT, m_mdiPlayer->getSubtitleInfoIndex());
        setSubtitleIndex(m_mdiPlayer->getSubtitleInfoIndex());
        m_display->setOption(VFX_TRUE, VFX_TRUE);
    }

    // re-set video screen mode
    setVideoScreenMode(getVideoScreenMode());

    // reset 3D switch memento
    m_switchMemento.reset();

    // store the video open result
    m_videoOpenResult = ret;
    m_needResumePlayAfterReady = VFX_FALSE;

    if (videoInfo != NULL)
    {
        // check self-assignment and set video info
        if(&m_currentVideoInfo != videoInfo)
        {
            m_currentVideoInfo = *videoInfo;
        }

        // If audio only, no need to prepare VideoFrame
        if(MDI_VIDEO_TRACK_A_ONLY == m_currentVideoInfo.track)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_HANDLE_VIDEO_OPEN_RESULT_AUDIO_ONLY, __LINE__);
            // since video frame is invisible, it
            // will not invoke m_signalPlayReady
            // so we call onVideoFramePreparedAfterOpen() directly
            m_display->getPlayReadyEvent()->disconnect(this, &VappVideoPlayerComponent::onVideoFramePreparedAfterOpen);
            showAudioOnlyIcon(VFX_TRUE);
            onVideoFramePreparedAfterOpen();
        }
        else
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_HANDLE_VIDEO_OPEN_RESULT_PREPARE_DISPLAY, __LINE__);
            // prepare VideoFrame
            // If succeeded and has video track, seek to 1st frame and show it.
            m_display->getPlayReadyEvent()->connect(this, &VappVideoPlayerComponent::onVideoFramePreparedAfterOpen);
            MDI_RESULT prepareRes = prepareAndShowVideo(videoInfo);

            // check prepare result
            m_videoOpenResult = prepareRes;
            if(MDI_RES_VDOPLY_SUCCEED != prepareRes)
            {
                m_display->getPlayReadyEvent()->disconnect(this, &VappVideoPlayerComponent::onVideoFramePreparedAfterOpen);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PREPARE_AND_SHOW_VIDEO_ERROR, prepareRes);
                closeFile();
                popupMDIErrorMessage(prepareRes);
                setErrorIcon(getErrorIconFromMDIResult(prepareRes));
                delayEmitFileReady(prepareRes);
            }
            else if(getHidden() || isAnyParentHidden(this))
            {
                // if video frame is invisible, due to setHidden of this CP or parents,
                // it will not invoke m_signalPlayReady
                // so we call onVideoFramePreparedAfterOpen() directly
                m_display->getPlayReadyEvent()->disconnect(this, &VappVideoPlayerComponent::onVideoFramePreparedAfterOpen);
                onVideoFramePreparedAfterOpen();
            }
            // otherwise m_signalPlayReady is guranteed to invoke.
        }
    }
    else
    {
        setState(VGPS_PAUSED);
        delayEmitFileReady(MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW);
    }

    return;
}

VfxBool VappVideoPlayerComponent::createA2DPConnection(VfxBool playAfterBTReady)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_CREATE_A2_DPCONNECTION, playAfterBTReady);
#if defined(__MMI_A2DP_SUPPORT__)
    // return VFX_TRUE if connect is opened.
    // VFX_FALSE if there is no need to connect.
    if (!m_connectingBT &&
        !m_option.disableAudio &&
        (MDI_VIDEO_TRACK_AV == m_currentVideoInfo.track ||
         MDI_VIDEO_TRACK_A_ONLY == m_currentVideoInfo.track)
       )
    {
        m_shouldPlayAfterBTConnected = playAfterBTReady;
        g_inst = this;
        m_connectingBT = VFX_TRUE;
        srv_a2dp_open(srv_a2dp_get_bt_headset(),
                      m_currentVideoInfo.aud_sample_rate,
                      m_currentVideoInfo.is_stereo,
                      &onBTOpenCallback,
                      MMI_TRUE);
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
#else

    return VFX_FALSE;
#endif // defined(__MMI_A2DP_SUPPORT__)

}

void VappVideoPlayerComponent::onSeekDoneAfterOpen(MDI_RESULT ret, mdi_video_info_struct *video_info)
{
    if(m_mdiPlayer)
    {
        m_mdiPlayer->getSeekDoneSignal().disconnect(this, &VappVideoPlayerComponent::onSeekDoneAfterOpen);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_ON_SEEK_DONE_AFTER_OPEN, ret);

    setState(VGPS_PAUSED);

    if(m_display)
    {
        m_display->invalidate();
    }

    // no A2DP connection needed, emit ready directly
    // we will build the A2DP connection when Play()
    delayEmitFileReady(m_videoOpenResult);

}

void VappVideoPlayerComponent::onVideoFramePreparedAfterOpen()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_ON_VIDEO_FRAME_PREPARED_AFTER_OPEN_SET_M_VIDEO_FRAME_NOT_READY_FALSE);
    m_display->getPlayReadyEvent()->disconnect(this, &VappVideoPlayerComponent::onVideoFramePreparedAfterOpen);
    m_videoFrameNotReady = VFX_FALSE;

    // we already done seek during open;
    // because video prepare finished may be late than seek callback, ex: MAUI_03151070
    // get frame again to avoid black frame
#if 1
    U64 currentTime = 0;
    m_mdiPlayer->getCurrentPlayTime(currentTime);
    if(m_mdiPlayer->canGetStillFrame())
    {
        m_mdiPlayer->getSeekDoneSignal().connect(this,&VappVideoPlayerComponent::onSeekDoneAfterOpen);
        MDI_RESULT firstFrameResult = m_mdiPlayer->blockingGetFrame(m_display->getVideoLayerHandle(), m_display->getSubtitleLayerHandle());
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_ON_FRAME_PREPARE_AFTER_OPEN, firstFrameResult);
    }
    // skip get frame result, emit open result directly
    onSeekDoneAfterOpen(m_videoOpenResult, NULL);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void VappVideoPlayerComponent::delayEmitFileReady(mdi_result ret)
{
    m_signalFileOpened.postEmit(this, ret);
}

void VappVideoPlayerComponent::delayEmitSeekDone(mdi_result ret)
{
    m_signalSeekFinished.postEmit(this, ret);
}


void VappVideoPlayerComponent::handlePlayFinished(MDI_RESULT ret)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_HANDLE_PLAY_FINISHED, ret);

    // note the error code of screen mode change failed is return by play_finish_callback
    // and cp should not stop play while recieves MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR
    // because mpl only failed to play while auio and video track is played failed either since 11BW33

    if(MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR == ret || MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR == ret)
    {
        return;
    }

    // make sure we're HW layer before calling seek
    swithVideoLayerToHW();

    switch(ret)
    {
    case MDI_RES_VDOPLY_STREAM_BUFFER_OVERFLOW:
        // overflow we do nothing, MDI would frame-skipping automatically.
        break;
    case MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW:
        if(m_mdiPlayer && !m_mdiPlayer->canSeekWithoutBuffering())
        {
            if(m_waitIcon)
            {
            	m_waitIcon->bringToFront();
                m_waitIcon->start();
            }

            // seek to re-trigger buffering
            U64 time = 0;
            m_mdiPlayer->getCurrentPlayTime(time);
            m_mdiPlayer->seek(time);
        }
        break;
    #ifdef __MMI_VIDEO_PDL__
    case MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH:
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_PDL_FILE_NOT_ENOUGH);
        if(m_shouldWaitPGDLFile)
        {
            // simply play again, it'll wait for buffering
            m_needResumePlayAfterEndSeek = VFX_TRUE;
            setState(VGPS_SEEKING);
            playAndChangeState();
        }
        else
        {
            setState(VGPS_PAUSED);
            popupMDIErrorMessage(ret);
        }
        break;
    #endif
    //case MDI_RES_VDOPLY_SUCCEED:
    default:
        if(ret != MDI_RES_VDOPLY_SUCCEED)
        {
            popupMDIErrorMessage(ret);
        }
        if(m_mdiPlayer)
        {
            m_mdiPlayer->getPlayFinishSignal().disconnect(this, &VappVideoPlayerComponent::handlePlayFinished);

            // if the video can be seek to beginning, seek to begin
            if(m_display &&
               (m_display->hasValidVideoLayerHandle() || m_display->hasValidSubtitleLayerHandle())&&
               m_mdiPlayer->canSeekWithoutBuffering())
            {
                MDI_RESULT res = m_mdiPlayer->blockingSeekAndGetFrame(0, m_display->getVideoLayerHandle(), m_display->getSubtitleLayerHandle());

                if (res != MDI_RES_VDOPLY_SUCCEED)
                {
                    VFX_DEV_ASSERT(VFX_FALSE);
                    // for streaming case which not support seek without buffering, when finish playing, clean preview layer
                    m_display->clean();
                }

                m_display->invalidate();
            }
            else if(m_mdiPlayer->canSeekWithoutBuffering())
            {
                m_mdiPlayer->blockingSeek(0);
            }
            else if (m_display)
            {
                // for streaming case which not support seek without buffering, when finish playing, clean preview layer
                m_display->cleanAndInvalidate();
            }

        }
        setState(VGPS_PAUSED);
        break;
    }

    m_signalPlaybackFinished.postEmit(this, ret);
}

void VappVideoPlayerComponent::handleBTOpenCallback(srv_a2dp_callback_event_enum result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_HANDLE_BTOPEN_CALLBACK, result);

    // lower the BT connection waiting flag
    m_connectingBT = VFX_FALSE;

    // we only handle BT event when file has opened and ready.
    // at this point, we may already be closed.
    const VfxBool canAcceptBTEvent = (VGPS_PAUSED == getState() ||
                                      VGPS_PLAYING == getState() ||
                                      VGPS_SEEKING == getState());
    if(!canAcceptBTEvent)
    {
        return;
    }

#if defined(__MMI_A2DP_SUPPORT__)
    switch (result)
    {
        case SRV_A2DP_CALLBACK_EVENT_OPEN_OK:
            srv_a2dp_open_codec(VGPS_PLAYING == getState() ? MMI_TRUE : MMI_FALSE);
            break;
        case SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED:
        case SRV_A2DP_CALLBACK_EVENT_OPEN_STOPPED:
        case SRV_A2DP_CALLBACK_EVENT_OPEN_SCO:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_ABORT_IND:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_CLOSE_IND:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_SUSPEND_IND:
        case SRV_A2DP_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:
            if(VGPS_PLAYING == getState())
            {
                srv_a2dp_close_codec();
                srv_a2dp_close(MMI_FALSE);
            }
            g_inst = NULL; // open failed, expect no re callback
            break;
        case SRV_A2DP_CALLBACK_EVENT_OPEN_CANCELED:
            g_inst = NULL; // open failed, expect no re callback
            break;
        case SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND:
            break;
        case SRV_A2DP_CALLBACK_EVENT_INQUIRY_START_IND:
            break;
        case SRV_A2DP_CALLBACK_EVENT_INQUIRY_STOP_IND:
            break;
    };
#endif  // defined(__MMI_A2DP_SUPPORT__)

    if(m_shouldPlayAfterBTConnected)
    {
        m_shouldPlayAfterBTConnected = VFX_FALSE;
        // note video component should play after seek finished if current state is VGPS_SEEKING
        // otherwise, mdi will return -3005(play failed)
        if(!isMakingCall() && VGPS_PLAYING != getState() && VGPS_SEEKING != getState())
        {
            MDI_RESULT playResult = playAfterAudioReady();
            // if play failed, notify user as play finish
            if(MDI_RES_VDOPLY_SUCCEED != playResult)
            {
                handlePlayFinished(playResult);
            }
        }
    }
}

void VappVideoPlayerComponent::onBTOpenCallback(VfxS32 result)
{
#if defined(__MMI_A2DP_SUPPORT__)
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_ON_BTOPEN_CALLBACK, result);
    // TODO: can BT A2DP srv support user data in callback?
    // it is possible that g_inst is cleared (e.g. closeFile() is called)
    // at this point
    if(g_inst)
    {
        g_inst->handleBTOpenCallback((srv_a2dp_callback_event_enum)result);
    }
    return;
#endif  // defined(__MMI_A2DP_SUPPORT__)

}

S32 VappVideoPlayerComponent::onBTDeviceArrival(BtAudEvent event, U32 arg, void *user_data)
{
#if defined(__MMI_A2DP_SUPPORT__)
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_ON_BTDEVICE_ARRIVAL_EVT, event);
    if(event != BTAUD_EV_STEREO_CONFIG_IND)
    {
        return FALSE;
    }

    VappVideoPlayerComponent *pThis = reinterpret_cast<VappVideoPlayerComponent*>(user_data);
    if(NULL == pThis)
    {
        return FALSE;
    }

    if(pThis->m_option.disableAudio ||
       MDI_VIDEO_TRACK_V_ONLY == pThis->m_currentVideoInfo.track)
    {
        // ignore BT device arrival since video only
        return FALSE;
    }

    switch(pThis->getState())
    {
    case VGPS_PLAYING:
    case VGPS_SEEKING:
        // re-check if we need to start BT streaming
        // note we don't need to emit file ready again.
        pThis->createA2DPConnection(VFX_FALSE);
        return TRUE;
    }
#endif  // defined(__MMI_A2DP_SUPPORT__)
	return FALSE;
}

void VappVideoPlayerComponent::startRotate(void)
{
    // check state
    switch(getState())
    {
    case VGPS_PLAYING:
    case VGPS_SEEKING:
        m_needResumePlayAfterEndRotate = VFX_TRUE;
        break;
    default:
        m_needResumePlayAfterEndRotate = VFX_FALSE;
        break;
    }
    // check m_needResumePlayAfterReady flag
    m_needResumePlayAfterEndRotate = (m_needResumePlayAfterReady)? VFX_TRUE : m_needResumePlayAfterEndRotate;

    pause();

    // force calling blocking seek and get frame
    // to avoid showing black frame first after rotation
    if(m_mdiPlayer && m_mdiPlayer->canGetStillFrame() && m_currentVideoInfo.is_seekable)
    {
        m_needBlockingSeekAndGetFrame = VFX_TRUE;
    }
}

void VappVideoPlayerComponent::endRotate(void)
{
    // resume play if content is audio track only
    if(m_needResumePlayAfterEndRotate && MDI_VIDEO_TRACK_A_ONLY == m_currentVideoInfo.track)
    {
        play();
        return;
    }

    // otherwise, we should re-prepare the video frame in order to reconfig lcd layer rotation angle
    if(m_mdiPlayer && m_mdiPlayer->canGetStillFrame() && m_currentVideoInfo.is_seekable)
    {
        m_needBlockingSeekAndGetFrame = VFX_TRUE;
    }
    changeRotation();
}

VfxBool VappVideoPlayerComponent::isMakingCall()
{
    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
#ifdef __COSMOS_MMI_PACKAGE__
        if(!m_option.isWallpaperScenario || m_option.isPreview)
        {
            // don't show this error if we're wallpaper (because Call screen may use VLW)
            // However, during preview case, we should show such error.
            mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf());
        }

#endif
        return VFX_TRUE;
    }

    return VFX_FALSE;
}
void VappVideoPlayerComponent::popupMDIErrorMessage(mdi_result result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VIDEOCP_POPUP_ERR_MSG, result);
    VfxResId errStr;

    switch(result)
    {
    case MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH:
        errStr = (VfxResId)STR_ID_VAPP_VIDEOCP_VIDEO_DOWNLOAD_STOPPED;
        break;
    default:
        {
            mmi_event_notify_enum popupType;
            MMI_ID_TYPE errID = mdi_util_get_mdi_error_info(result, &popupType);
            errStr =  (VfxResId)errID;
        }
        break;
    }    
    mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_FAILURE,
        (WCHAR *)VFX_WSTR_RES(errStr).getBuf());
}

mmi_ret VappVideoPlayerComponent::onDeviceEvent(mmi_event_struct *param)
{
    VappVideoPlayerComponent *pThis = (VappVideoPlayerComponent*)VfxObject::handleToObject((VfxObjHandle)param->user_data);
    if(NULL == pThis)
    {
        return MMI_RET_OK;
    }

    return pThis->handleDeviceEvent(param);
}

mmi_ret VappVideoPlayerComponent::handleDeviceEvent(mmi_event_struct *param)
{
    if(NULL == m_mdiPlayer || NULL == param)
    {
        return MMI_RET_OK;
    }

    // only handling playing case.
    if(VGPS_PLAYING != getState())
    {
        return MMI_RET_OK;
    }

    switch(param->evt_id)
    {
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            VappVideoPlayerInputSource input;
            if(!m_mdiPlayer->getOpenedVideo(input))
                break;

            if(!input.isLocalFile())
                break;

            // check if current file is gone
            if(!isFileExist(input.m_path))
            {
                // treat as playback finished
                m_mdiPlayer->stop();
                handlePlayFinished(MDI_RES_VDOPLY_ERR_PLAY_FAILED);
            }
        }
    }
    return MMI_RET_OK;
}

static U8* _ensure_non_cachable_address(U8* mem_addr)
{
#if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__))
    U8* physicalAddr = (U8*)virt_to_phys((U32*)mem_addr);
    return physicalAddr;
#else
    return mem_addr;
#endif
}

VfxBool VappVideoPlayerComponent::getCurrentFrame(VfxImageBuffer &imgBuf)
{
    // make sure we're in paused state
    pause();
    if(VGPS_PAUSED != getState())
    {
        return VFX_FALSE;
    }

    // ensure video frame is valid
    if(!(m_display && m_display->getIsDisplayReady()))
    {
        return VFX_FALSE;
    }

    // get video content without subtitle
    GDI_HANDLE videoLayer = m_display->getVideoLayerHandle();
    if(NULL == videoLayer)
    {
        return VFX_FALSE;
    }

    GDI_RESULT res = GDI_FAILED;
    GDI_HANDLE thumbLayer = GDI_LAYER_EMPTY_HANDLE;
    // GDI layer only support zero-padded pitch
    // and thumbnail must be 16-bit RGB565 now
    VFX_ASSERT(imgBuf.pitchBytes == imgBuf.width * 2);
    VFX_ASSERT(imgBuf.colorFormat == VRT_COLOR_TYPE_RGB565);
    res = gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_16,
                                                   0, 0,
                                                   imgBuf.width,
                                                   imgBuf.height,
                                                   &thumbLayer,
                                                   _ensure_non_cachable_address(imgBuf.ptr),
                                                   imgBuf.pitchBytes * imgBuf.height);
    VFX_ASSERT(GDI_SUCCEED == res);

    do
    {
        gdi_layer_push_and_set_active(videoLayer);
        S32 videoWidth = 0, videoHeight = 0;
        gdi_layer_get_dimension(&videoWidth, &videoHeight);
        gdi_layer_pop_and_restore_active();


        S32 x = 0, y = 0, w = 0, h = 0;
        gdi_util_fit_box(
                GDI_UTIL_MODE_LONG_SIDE_FIT,
                videoWidth,
                videoHeight,
                imgBuf.width,
                imgBuf.height,
                &x,
                &y,
                &w,
                &h);

        gdi_layer_push_and_set_active(thumbLayer);
        res = gdi_bitblt_resized(videoLayer,
                           0,
                           0,
                           videoWidth - 1,
                           videoHeight - 1,
                           x,
                           y,
                           x + w - 1,
                           y + h - 1);
        gdi_layer_pop_and_restore_active();
    }while(0);

    gdi_layer_free(thumbLayer);
    thumbLayer = GDI_LAYER_EMPTY_HANDLE;

    return (GDI_SUCCEED == res);
}
#endif // defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) || defined(__COSMOS_MMI_PACKAGE__)
