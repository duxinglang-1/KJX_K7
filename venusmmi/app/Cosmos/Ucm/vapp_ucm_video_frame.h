#ifndef VAPP_VT_VIDEOFRAME_H
#define VAPP_VT_VIDEOFRAME_H

#include "MMI_include.h"
#ifdef __MMI_VIDEO_TELEPHONY__

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "mdi_video.h"
#ifdef __cplusplus
}
#endif

#ifdef DUAL_CAMERA_SUPPORT
#define __VAPP_VT_VF_DUAL_CAMERA__
#endif 

#define VAPP_VT_VIDEOFRAME_FRAME_MARGIN     (4)

typedef enum
{
    VAPP_VT_VIDEOFRAME_SRC_VIDEO,
    VAPP_VT_VIDEOFRAME_SRC_IMAGE,
    VAPP_VT_VIDEOFRAME_SRC_END    
    
}VappVtVideoFrameSrcEnum;


typedef enum
{
    VAPP_VT_VIDEOFRAME_TYPE_PEER,
    VAPP_VT_VIDEOFRAME_TYPE_LOCAL,
    VAPP_VT_VIDEOFRAME_TYPE_END    
    
}VappVtVideoFrameTypeEnum;

typedef enum
{
    VAPP_VT_VIDEOFRAME_EV_N4 = 0,
    VAPP_VT_VIDEOFRAME_EV_N3,
    VAPP_VT_VIDEOFRAME_EV_N2,
    VAPP_VT_VIDEOFRAME_EV_N1,
    VAPP_VT_VIDEOFRAME_EV_0,
    VAPP_VT_VIDEOFRAME_EV_P1,
    VAPP_VT_VIDEOFRAME_EV_P2,
    VAPP_VT_VIDEOFRAME_EV_P3,    
    VAPP_VT_VIDEOFRAME_EV_P4,

    VAPP_VT_VIDEOFRAME_EV_TOTAL
    
} VappVtVideoFrameEvEnum;

typedef enum
{
    VAPP_VT_VIDEOFRAME_ENC_SIZE_QCIF,  /* default */  
    VAPP_VT_VIDEOFRAME_ENC_SIZE_SQCIF,

    VAPP_VT_VIDEOFRAME_ENC_SIZE_END
} VappVtVideoFrameEncSizeEnum;

typedef enum
{
    VAPP_VT_VIDEOFRAME_ENC_QUALITY_SMOOTH,
    VAPP_VT_VIDEOFRAME_ENC_QUALITY_NORMAL,
    VAPP_VT_VIDEOFRAME_ENC_QUALITY_SHARP,
    
    VAPP_VT_VIDEOFRAME_ENC_QUALITY_END
    
} VappVtVideoFrameEncQualityEnum;

typedef enum {
    
    VAPP_VT_VIDEOFRAME_EVENT_CHANGE_ENCODE_SIZE,    
    VAPP_VT_VIDEOFRAME_EVENT_CHANGE_ENCODE_QUALITY,
    VAPP_VT_VIDEOFRAME_EVENT_UPDATE_LCD,  
    VAPP_VT_VIDEOFRAME_EVENT_ENC_PATH_BUILT, 
    VAPP_VT_VIDEOFRAME_EVENT_START,     
    VAPP_VT_VIDEOFRAME_EVENT_RESUME,         
    VAPP_VT_VIDEOFRAME_EVENT_END
    
} VappVtVideoFrameEvtEnum;

typedef enum
{
    VAPP_VT_VIDEOFRAME_CAMERA_OFF,
    VAPP_VT_VIDEOFRAME_CAMERA_FRONT,
    VAPP_VT_VIDEOFRAME_CAMERA_BACK   
    
} VappVtVideoFrameSensorEnum;


typedef enum {
    VAPP_VT_VIDEOFRAME_STATE_STOP,    
    VAPP_VT_VIDEOFRAME_STATE_PAUSE,        
    VAPP_VT_VIDEOFRAME_STATE_START 
} VappVtVideoFrameStateEnum;

typedef enum {
    VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR,    
    VAPP_VT_VIDEOFRAME_ERROR_INVALIDE_INPUT,        
    VAPP_VT_VIDEOFRAME_ERROR_DRIVER_ERROR,              
    VAPP_VT_VIDEOFRAME_ERROR_CAPTURE_DISK_FULL,       
    VAPP_VT_VIDEOFRAME_ERROR_END    
} VappVtVideoFrameErrorEnum;


typedef enum {
    VAPP_VT_VIDEOFRAME_Z_ORDER_0 = 50,    
    VAPP_VT_VIDEOFRAME_Z_ORDER_1 = 70,
    VAPP_VT_VIDEOFRAME_Z_ORDER_2 = 90,
    VAPP_VT_VIDEOFRAME_Z_ORDER_3 = 110,
    VAPP_VT_VIDEOFRAME_Z_ORDER_END
} VappVtVideoFrameZOrderEnum;


typedef struct
{

    VfxU16 count;         
    VappVtVideoFrameEvEnum supportItem[VAPP_VT_VIDEOFRAME_EV_TOTAL];  

}VappVtVideoFrameEvCapStruct;


typedef struct
{

    VfxU16 stepNumber;         

}VappVtVideoFrameZoomCapStruct;


class VappVtVideoFrame : public VfxControl
{
public:
    virtual void onInit(void);
    virtual void onDeinit();

    VappVtVideoFrameErrorEnum setParamMaxWndSize(VfxSize PeerMaxWnd, VfxSize LocalMaxWnd,VfxSize PeerMinWnd, VfxSize LocalMinWnd);
    VappVtVideoFrameErrorEnum setParamAppId(VfxU32 id);
    VappVtVideoFrameErrorEnum setParamSensorId(VappVtVideoFrameSensorEnum sensor);
    VappVtVideoFrameErrorEnum setFrameRect(VappVtVideoFrameTypeEnum type, VfxRect rect);
    VappVtVideoFrameErrorEnum setParamMirror(VfxBool isMirror = VFX_FALSE);
    VappVtVideoFrameErrorEnum setParamHide(VappVtVideoFrameTypeEnum type, VfxBool isHidden);    
    VappVtVideoFrameErrorEnum setParamLocalQty(VappVtVideoFrameEncQualityEnum value);
    VappVtVideoFrameErrorEnum setParamPeerQty(VappVtVideoFrameEncQualityEnum value);
    VappVtVideoFrameErrorEnum setParamEncSize(VappVtVideoFrameEncSizeEnum value);
    VappVtVideoFrameErrorEnum setParamNightMode(VfxBool isNightMode = VFX_FALSE);
    VappVtVideoFrameErrorEnum setParamFrameMode(VappVtVideoFrameTypeEnum type, VappVtVideoFrameSrcEnum mode);    
    VappVtVideoFrameErrorEnum setParamFrameFront(VappVtVideoFrameTypeEnum type);     
    VappVtVideoFrameErrorEnum setParamFrameBorder(VappVtVideoFrameTypeEnum type, VfxImageFrame* f);     
    VappVtVideoFrameErrorEnum setParamFrameContent(VappVtVideoFrameTypeEnum type, const VfxImageSrc &value);    
    VappVtVideoFrameErrorEnum setParamPeerDefaultContent(const VfxImageSrc &value);

	void videoFramePrepareDone(void);
	
    VappVtVideoFrameErrorEnum start(void);
    VappVtVideoFrameErrorEnum resume(void);
    VappVtVideoFrameErrorEnum pause(void);
    VappVtVideoFrameErrorEnum stop(void);
    VappVtVideoFrameErrorEnum backgroundResume(void);
    VappVtVideoFrameErrorEnum backgroundPause(void);
    VappVtVideoFrameErrorEnum capture(VappVtVideoFrameTypeEnum type, CHAR* fileName);

    VappVtVideoFrameErrorEnum abortStart(void);    
    VappVtVideoFrameErrorEnum abortResume(void);    
    
    VappVtVideoFrameErrorEnum setZoomValue(VfxU16 value);
    VappVtVideoFrameErrorEnum setEVValue(VappVtVideoFrameEvEnum value);    

    VappVtVideoFrameErrorEnum getZoomCap(VappVtVideoFrameZoomCapStruct *cap);
    VappVtVideoFrameErrorEnum getEVCap(VappVtVideoFrameEvCapStruct *cap);
    VappVtVideoFrameErrorEnum getFrameData(VappVtVideoFrameTypeEnum type, VfxImageFrame* imageDst);    

    gdi_handle getFrameHandle(VappVtVideoFrameTypeEnum type);
    
    VfxU32 getFrameMargin(void);
    VfxU32 getFrameBorder(void);

    void showCover(void);
    void hideCover(void);

    VfxBool onPenInput(VfxPenEvent &event);    

    
    VfxSignal2 <
        VappVtVideoFrameEvtEnum,      // event type
        VfxS32                                   // event param 
    > m_signalVtEvent;

    VfxSignal2 <
        VfxPenEventTypeEnum,              // pen event type
        VappVtVideoFrameTypeEnum        // hit frame type 
    > m_signalVtVideoFramePenEvent;

    void eventCallbackHdlr(mdi_video_tel_codec_event_enum tel_event, S32 para, void* user_data);
    
private:    

    VfxBool hitTest(VfxPoint pos, VfxRect rect);

    
    VfxU32                          m_appId;
    VappVtVideoFrameSensorEnum      m_sensorId;        

    VappVtVideoFrameEvCapStruct     m_evCap;
    VappVtVideoFrameZoomCapStruct   m_zoomCap; 

    VfxVideoFrame*                  m_peerFrame;    
    VfxFrame*                       m_peerBgFrame;        
    VfxImageFrame*                  m_peerBorderFrame;           
    VfxImageFrame*                  m_peerCoverFrame;       
    VfxVideoFrame*                  m_localFrame;   
    VfxFrame*                       m_localBgFrame; 
    VfxImageFrame*                  m_localBorderFrame;       
    VfxImageFrame*                  m_localCoverFrame;           
    VappVtVideoFrameSrcEnum         m_peerFrameType;
    VappVtVideoFrameSrcEnum         m_localFrameType;    
    VappVtVideoFrameSrcEnum         m_peerPreFrameType;
    VappVtVideoFrameSrcEnum         m_localPreFrameType;
    VfxBool                         m_peerFrameHidden;
    VfxBool                         m_localFrameHidden;    

    mdi_video_setting_struct        m_videoSetting;
    VfxBool                         m_isMEDBuilt;
    VfxBool                         m_isMMIOpen;    
    VappVtVideoFrameStateEnum       m_state;

    gdi_handle                      m_cachedPeerLayer;    
    gdi_handle                      m_cachedLocolLayer;    
    void*                           m_cacheBuffer;    
    VfxU32                          m_cacheBufferSize;
    
    gdi_handle                      m_encodeLayer;
    void*                           m_encodeBuffer;

	VfxU32							m_prepareExpectCount;
	VfxU32							m_prepareCount;
	VfxU32							m_prepareMode;	
    
};

#endif
#endif
