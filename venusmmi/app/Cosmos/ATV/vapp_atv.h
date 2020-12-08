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
 *  vapp_atv.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *
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

#ifndef __VAPP_ATV_H__
#define __VAPP_ATV_H__


/*****************************************************************************
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_ATV_SUPPORT__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_wheel_menu.h"
#include "vcp_loading_popup.h"
#include "vapp_atv_enum.h"

extern "C"
{
#include "mmi_features_mtv_player.h"
#include "common_nvram_editor_data_item.h"
#include "fileMgrSrvGprot.h"
#include "mdi_datatype.h"
#include "mdi_mtv.h"
}

/*****************************************************************************
 * Define
 *****************************************************************************/
#define VAPP_ATV_NAME_STR_LENGTH (32)
#define VAPP_ATV_SIGNAL_UPDATE_TIME (2000)
#define VAPP_ATV_CFM_STR_LENGTH  (128)

#if !defined(__COSMOS_NO_USER_DRIVE__)&& defined(__MMI_ATV_PHONE_DRIVE_SUPPORT__)
	#ifndef __MMI_ATV_STORAGE_SELECT__
	#define __MMI_ATV_STORAGE_SELECT__
	#endif
#endif

/*****************************************************************************
 * Pre-Declaration
 *****************************************************************************/
class VappAtvScanLocPage;
class VappAtvScreen;
class VappAtvMainPage;
class VappAtvToolBar;
class VappAtvSettingPage;
class VappAtvStoragePage;
class VappAtvRecSizePage;
class VappAtvScanProg;
class VappAtvImgButton;


/*****************************************************************************
 * Class
 *****************************************************************************/
typedef struct
{
    U32 service_id;
    U32 service_number;
    //mdi_mtv_service_type_enum service_type;
    //S32 service_flags;
    WCHAR service_name[VAPP_ATV_NAME_STR_LENGTH + 1];
    U32 audio_mode;
    U32 supported_audio_mode;
} vapp_srv_info_struct;


class VappAtvApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappAtvApp);

protected:
	using VfxApp::onProcessClose;

public:

    enum FILE_TYPE_ENUM
    {
        FILE_TYPE_IMG,  /* 0 */
        FILE_TYPE_REC   /* 1 */
    };

    /* Member variable */
    static VappAtvApp *m_self;
    VfxU32 m_mtvHandle;
    VappAtvScreen *m_scrn;
	VfxBool m_storageValid;
    VfxBool m_proc_close;
    VfxU16 m_numServices;
    VfxU16 m_numPrevServices;
	vapp_srv_info_struct *m_services; /* [VAPP_ATV_MAX_SERVICES] */
	VfxTimer *m_timerSignal;
    VfxU8 *m_recThumbBuffer;
    VfxBool m_massStorageMode;
    VAPP_ATV_KERNEL_STATE_ENUM m_kernelState;
    VAPP_ATV_PLAYER_STATE_ENUM m_playerState;
    VAPP_ATV_RECORDER_STATE_ENUM m_recordState;
    VfxBool m_1stEnter;
    VfxU32 m_pageHighPrioSetCount;
	VfxTimer *m_timerBTConnect;
	VfxU8 * m_tempBuffer;
	nvram_atv_setting_struct m_setting;
    VfxBool m_liveScan;
    VfxBool serviceUnavailable;
	VfxS32 recSizeNum;
    mdi_mtv_recorder_size_enum recSizeList[MDI_MTV_RECORDER_SIZE_COUNT];
    VfxWChar m_storagePath[SRV_FMGR_PATH_BUFFER_SIZE>>1];
    
	
	

    /* Constructor */
    VappAtvApp();

    /* Virtual function */
    virtual void onInit(void);
    virtual void onDeinit(void);
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onGroupActive();
    virtual void onGroupInactive();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);

    /* Self-Defined function */
    void loadSetting(void);
    void writeSetting(void);
    void restoreSetting(void);
    void updateFuncIcon(void);
    void updateStorageStatus(void);
    void setKernelState(VAPP_ATV_KERNEL_STATE_ENUM state);
    void setPlayerState(VAPP_ATV_PLAYER_STATE_ENUM state);
#ifdef __MMI_ATV_RECORD__
    void setRecorderState(VAPP_ATV_RECORDER_STATE_ENUM state);
#endif
    void allocStructure(void);
    void freeStructure(void);
    void getServiceList(void);
    void getVideoSetting(mdi_mtv_player_setting_struct *video_setting);
    void onUpdateSignal(VfxTimer *obj);
    void serviceReadyHdlr(VappAtvApp* app, mdi_mtv_service_info_struct *srvInfo);
    void deInitDisplay(VfxBool incReady);
    void setAudMode(VfxU32 mode);
#ifdef __MMI_ATV_RECORD_SIZE_SELECT__
    void setRecSize(mdi_mtv_recorder_size_enum size);
#endif
#ifdef __MMI_ATV_STORAGE_SELECT__
    void setStorage(srv_fmgr_drv_type_enum type);
#endif
#ifdef __MMI_ATV_RECORD__
    void initRecSizeList();
#endif
    void setAdjustValue(VfxU8 brightness, VfxU8 contrast, VfxU8 saturation);
    void getNextFileName(VfxWChar *storagePath, FILE_TYPE_ENUM type);

    U32 getBand(void);
    VAPP_ATV_KERNEL_STATE_ENUM getKernelState(void);
    VAPP_ATV_PLAYER_STATE_ENUM getPlayerState(void);
#ifdef __MMI_ATV_RECORD__
    VAPP_ATV_RECORDER_STATE_ENUM getRecorderState(void);
#endif
    VfxBool getStoragePath(VfxWChar *storagePath);
    VfxWString getDrvString(srv_fmgr_drv_type_enum type);
    VfxWString getRecSizeString(mdi_mtv_recorder_size_enum size);
    VappAtvScanProg *getScanProg();
    vapp_srv_info_struct *getActiveSrv();
    MDI_RESULT getSnapshot(gdi_handle layer_handle, VfxWChar *storagePath);
    MDI_RESULT getRecFrame(VfxWChar *storagePath);
    MDI_RESULT initDisplay();

    /* Control function */
    MDI_RESULT openEngine(void);
    MDI_RESULT scanService(void);
    MDI_RESULT startService();
    MDI_RESULT startPlayer();
#ifdef __MMI_ATV_RECORD__
    MDI_RESULT startRecord();
    MDI_RESULT resumeRecord();
    MDI_RESULT saveRecord(VfxWChar *storagePath);
#endif
    void abortScanService(void);
    void closeEngine(void);
    void stopService();
    void stopPlayer();
#ifdef __MMI_ATV_RECORD__
    MDI_RESULT pauseRecord();
    void stopRecord();
    void discardRecord();
#endif
    void setPageHighPriority();
    void clearPageHighPriority();

#if defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)
	void BTConnectTimeout(VfxTimer *timer);
    static void onBTOpenCallback(VfxS32 result);
    MDI_RESULT connectBT();
#endif // defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)
    static void completeRecoverHdlr(S32 value, void *user_data);
    static void serviceFoundHdlr(mdi_mtv_service_info_struct *service_info, void *user_data);
    static void searchProgressHdlr(S32 value, void *user_data);
    static void systemEvtHdlr(U32 event_id, S32 param, void *user_data);
    static void serviceEvtHdlr(U32 event_id, S32 param, void *user_data);
    static void playerEvtHdlr(U32 event_id, S32 param, void *user_data);
#ifdef __MMI_ATV_RECORD__
    static void recorderEvtHdlr(U32 event_id, S32 param, void *user_data);
#endif
	
    static void PowerOnFailHdlr(VfxId id, void *userData);

private:


};

/* Scan prog */
class VappAtvScanProg : public VfxControl
{
    //VFX_DECLARE_CLASS(VappAtvScanProg);

public:
    enum EVT_TYPE_ENUM
    {
        EVT_SCAN_FINISHED,
        EVT_CHANGE_SCAN_LOC,
        EVT_EXIT,
        EVT_SCAN_FAIL
    };
    VappAtvApp *m_app;
    VcpConfirmPopup *m_cfm;
    VcpIndicatorPopup *m_progPopup;

    /* Constructor */
    VappAtvScanProg();

    /* Virtual function */
    virtual void onInit();

    VfxSignal1 <EVT_TYPE_ENUM>m_signal;

    void startScan();
    void setScanProgress(VfxFloat value);
    void cancelScanHandler(VfxObject* obj, VfxFloat progress);
    void scanFinishHandler(void);
    void displayScanAgainConfirm(void);
    void onScanConfirmClicked(VfxObject* sender, VfxU32 id);
private:

};


/* Page: Scan location */
class VappAtvScanLocPage : public VfxPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappAtvScanLocPage);

public:
    VappAtvApp *m_app;
    S32 hilight_country;
    VfxBool m_locListCreated;
    VfxBool m_displayScanProg;
    VappAtvScanProg *m_scanProg;
    VcpToolBar *m_toolBar;
    VcpLoadingPopup *m_loadingPopup;
    VcpActivityIndicator *m_actInd;
	
    /* Constructor */
    VappAtvScanLocPage();

    /* Virtual function */
    virtual void onInit();
    virtual void onDeinit();
	virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );  //Replace onQueryRotate with onQueryRotateEx;
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    virtual void onBack();

    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color

    );

    virtual VfxU32 getCount(void) const;

    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

    /* Self-Defined function */
    void countrySelHandler(VfxObject* obj, VfxId id);
    void countryHilightHandler(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState);
    void displayScanLocList();
    void createCountryList();
    void displayPleaseWait();
    void displayScanProg();
    void scanEvthandler(VappAtvScanProg::EVT_TYPE_ENUM);
    void showMdiFailConfirm(MDI_RESULT ret);

    VfxSignal0 m_signalScanFinished;
private:
    enum
    {
        BUTTON_SCAN,
        BUTTON_CANCEL_EXIT
    };
};

// Thumbnail button
class VappAtvThumbButton : public VfxControl
{
    //VFX_DECLARE_CLASS(VappAtvThumbButton);

public:
    VfxImageSrc m_imgSrc;

    /* Constructor */
    VappAtvThumbButton(VfxImageSrc *imgSrc = NULL);
    virtual void onInit();

    virtual VfxBool onPenInput(VfxPenEvent &event);
    VfxSignal0 m_signalClicked;

private:

};


/* ToolBar */
class VappAtvToolBar : public VfxControl
{
    //VFX_DECLARE_CLASS(VappAtvToolBar);

public:

    enum
    {
        TBAR_BTN_NUM = 5,
        MOVE_THRESHOLD = 3
    };

    enum BUTTON_TYPE_ENUM
    {
        BUTTON_TYPE_SCAN,       /* 0 */
	#if !(defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__))
		BUTTON_TYPE_SCAN_LOCATION,
	#endif
        BUTTON_TYPE_AUD_MODE,   /* 1 */
        BUTTON_TYPE_SNAPSHOT,   /* 2 */
    #ifdef __MMI_ATV_RECORD__
        BUTTON_TYPE_RECORD,     /* 3 */
    #endif
	#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
        BUTTON_TYPE_SETTING,    /* 4 */
	#endif 
	#if !defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
		BUTTON_TYPE_STORAGE_SELECT,
	#endif
		BUTTON_TYPE_HANDLE,     /* 5 */
  
        BUTTON_ALL
    };

    enum DRAG_TYPE_ENUM
    {
        DRAG_TYPE_MOVE,/* 0 */
        DRAG_TYPE_UP   /* 1 */
    };

    VappAtvApp *m_app;
    VcpImageButton *m_tBarBtn[BUTTON_ALL-1];
    VappAtvImgButton *m_btn;
    VfxS32 m_penDownX;
    VfxS32 m_bgWidth;
    VfxBool m_handleDrag;

    VfxSignal1 <BUTTON_TYPE_ENUM> m_signalImgBtnClicked;
    VfxSignal2 <DRAG_TYPE_ENUM, VfxS32> m_signalDrag;
    /* Constructor */
    VappAtvToolBar();

    /* Virtual function */
    virtual void onInit();
    void onImgBtnClicked(VfxObject *obj, VfxId id);
    void onHandlePenEvent(VfxPenEvent &event, VfxId id);
    void setAllFuncEnabled(VfxBool isEnabled);
    void setIsFuncEnabled();
    virtual VfxBool onPenInput(VfxPenEvent &event);
    VfxS32 getBgWidth();
private:
};

class VappAtvImgButton : public VfxControl
{
    //VFX_DECLARE_CLASS(VappAtvImgButton);

public:

    /* Constructor */
    VappAtvImgButton(
        VfxResId imgId = 0,
        VfxS32 ctrlWidth = 0,
        VfxS32 ctrlHeight = 0,
        VfxS32 imgX = 0,
        VfxS32 imgY = 0);

    void setCallbackId(VfxId id);
    void setImgId(VfxId imgId);
    VfxId getImgId();

    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);
    VfxSignal2 <VfxPenEvent &, VfxId> m_signalPenEvent;

private:

    //get from constructor
    VfxResId m_imgId;
    VfxS32 m_ctrlWidth;
    VfxS32 m_ctrlHeight;
    VfxS32 m_imgX;
    VfxS32 m_imgY;

    VfxId m_callbackId;
    VfxImageFrame *m_imgFrame;
};

#ifdef __MMI_ATV_SLIM__

/* WheelPannel slim version */

class VappAtvWheelPanelSlim : public VcpWheelMenu
{
	public:
		VappAtvApp *m_app;
		enum BTN_ENUM
	    {
	        BTN_UP,
	        BTN_DOWN,
	        BTN_NUM
	    };
		VfxImageFrame *m_btnBGImg;
		VfxU8 m_targetChannel;
	    VfxBool m_btnPressed;
	    VfxTimer* m_timerChangeIdx;
	    VfxTimer* m_timerResetScrollIdx;

		VfxSignal1 <VfxU8> m_signalChangeChannel;

		/* Constructor */
    	VappAtvWheelPanelSlim();

    	/* Virtual function */
   	 	virtual void onInit();

		// wheelMenu
	    virtual VfxS32 getCount();
	    virtual VfxS32 getBehindCount();
	    virtual VfxS32 getAheadCount();
	    virtual VfxFrame* createCell(VfxS32 cell, VfxS32 subcell);
	    virtual void onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame);
	    virtual void onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame);
	    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB();
   		static vrt_render_dirty_type_enum frameEffectCB(
        VfxS32                              cell,           // [IN] the cell index
        VfxS32                              subCell,        // [IN] the sub cell index
        VfxFloat                            cellRelPos,     // [IN] the cell position
        vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
        VfxFloat                            fPos,           // [IN] animating index value
        VfxS32                              focus,          // the focus value of the menu
        VfxRect                             viewBounds,     // the menu bounds
        void                                *userData,      // user data
        VfxU32                              userDataSize,   // user data size
        VcpWheelMenuState                   state,          // [IN] the state of Menu
        VfxFloat                            level           // [IN] the level of state
    	);
	    virtual void onTap(VfxPoint pt);
	    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);
	    virtual void onDragEnd(VfxS32 xspeed, VfxS32 yspeed);

	    void initWheelFocus();
	    void incChannelIndex(VfxBool forceWrap);
	    void decChannelIndex(VfxBool forceWrap);
	    void stopChangeIndexTimer();
	    void incChannelTimeout(VfxTimer *timer);
	    void decChannelTimeout(VfxTimer *timer);
	    void resetScrollIdx(VfxTimer *timer);
	    void onWheelBtnPenEvent(VfxPenEvent &event, VfxId id);
	    void updateCellFont(VfxS32 cell, VfxTextFrame *textFrm);
	    void wheelBtnLongPressHdlr(VfxId id);
	    void wheelBtnDownHdlr(VfxId id);
	    void wheelBtnUpHdlr(VfxId id);
	private:
	    
#ifdef __MMI_ATV_SLIM__

		enum
	    {
	        DELAY_CHANGE_IDX = 700,
	        WHEEL_EFFECT_TIME = 200,
	        DELAY_RESET_SCROLL_IDX = 100,
	        TEXT_COLOR_NORMAL = 160,
	        TEXT_COLOR_FOCUS_R = 14,
	        TEXT_COLOR_FOCUS_G = 158,
	        TEXT_COLOR_FOCUS_B = 202
	    };

	    enum MENU_ENUM
	    {
	        MENU_SIDE_COUNT = 2,
	        MENU_FOCUSN_COUNT = 5,
	        MENU_TIMES = 20000 //must be even number
	    };
#else
		enum
	    {
	        DELAY_CHANGE_IDX = 700,
	        WHEEL_EFFECT_TIME = 200,
	        DELAY_RESET_SCROLL_IDX = 100,
	        TEXT_COLOR = 160
	    };
		
		enum MENU_ENUM
	    {
	        MENU_SIDE_COUNT = 3,
	        MENU_FOCUSN_COUNT = 7,
	        MENU_TIMES = 20000 //must be even number
	    };
#endif
};


#endif

#ifndef __MMI_ATV_SLIM__

/* WheelPanel */
class VappAtvWheelPanel : public VcpWheelMenu
{
    //VFX_DECLARE_CLASS(VappAtvWheelPanel);

public:
    VappAtvApp *m_app;

    enum BTN_ENUM
    {
        BTN_UP,
        BTN_DOWN,
        BTN_NUM
    };

    VfxImageFrame *m_btnBGImg[BTN_NUM];
    VappAtvImgButton *m_btn[BTN_NUM];
    VfxU8 m_targetChannel;
    VfxBool m_btnPressed;
    VfxTimer* m_timerChangeIdx;
    VfxTimer* m_timerResetScrollIdx;

    VfxSignal1 <VfxU8> m_signalChangeChannel;
    /* Constructor */
    VappAtvWheelPanel();

    /* Virtual function */
    virtual void onInit();

    // wheelMenu
    virtual VfxS32 getCount();
    virtual VfxS32 getBehindCount();
    virtual VfxS32 getAheadCount();
    virtual VfxFrame* createCell(VfxS32 cell, VfxS32 subcell);
    virtual void onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame);
    virtual void onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame);
    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB();
    static vrt_render_dirty_type_enum frameEffectCB(
        VfxS32                              cell,           // [IN] the cell index
        VfxS32                              subCell,        // [IN] the sub cell index
        VfxFloat                            cellRelPos,     // [IN] the cell position
        vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
        VfxFloat                            fPos,           // [IN] animating index value
        VfxS32                              focus,          // the focus value of the menu
        VfxRect                             viewBounds,     // the menu bounds
        void                                *userData,      // user data
        VfxU32                              userDataSize,   // user data size
        VcpWheelMenuState                   state,          // [IN] the state of Menu
        VfxFloat                            level           // [IN] the level of state
    );
    virtual void onTap(VfxPoint pt);
    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);
    virtual void onDragEnd(VfxS32 xspeed, VfxS32 yspeed);

    void initWheelFocus();
    void incChannelIndex(VfxBool forceWrap);
    void decChannelIndex(VfxBool forceWrap);
    void stopChangeIndexTimer();
    void incChannelTimeout(VfxTimer *timer);
    void decChannelTimeout(VfxTimer *timer);
    void resetScrollIdx(VfxTimer *timer);
    void onWheelBtnPenEvent(VfxPenEvent &event, VfxId id);
    void updateCellFont(VfxS32 cell, VfxTextFrame *textFrm);
    void wheelBtnLongPressHdlr(VfxId id);
    void wheelBtnDownHdlr(VfxId id);
    void wheelBtnUpHdlr(VfxId id);
private:
    enum
    {
        DELAY_CHANGE_IDX = 700,
        WHEEL_EFFECT_TIME = 200,
        DELAY_RESET_SCROLL_IDX = 100,
        TEXT_COLOR = 160
    };

    enum MENU_ENUM
    {
        MENU_SIDE_COUNT = 3,
        MENU_FOCUSN_COUNT = 7,
        MENU_TIMES = 20000 //must be even number
    };
};

#endif

#ifdef __MMI_ATV_PLAYER_SETTING__
/* AdjustBar */
class VappAtvAdjustBar : public VfxControl
{
    //VFX_DECLARE_CLASS(VappAtvAdjustBar);

public:
    VappAtvApp *m_app;

    VfxU8 m_brightness;
    VfxU8 m_contrast;
    VfxU8 m_saturation;

    enum SLIDER_TYPE_ENUM
    {
        SLIDER_BRIGHTNESS,
        SLIDER_CONTRAST,
        SLIDER_SATURATION,
        SLIDER_NUM
    };
    VcpSlider *m_slider[SLIDER_NUM];
    /* Constructor */
    VappAtvAdjustBar();

    virtual void onInit();
    void onAdjustBtnClicked(VfxObject *obj, VfxId id);
    void initAdjustValue();
    void onSliderDrag(VcpSlider *slider, VfxFloat value);

    VfxSignal0 m_signalBtnClicked;
private:
    enum BUTTON_TYPE_ENUM
    {
        BUTTON_OK,
        BUTTON_CANCEL
    };

    enum
    {
        BAR_NUM = 3,
        BTN_NUM = 2,
        TEXT_COLOR = 28
    };
};
#endif

/* Page: Main */
class VappAtvMainPage : public VfxPage
{
    //VFX_DECLARE_CLASS(VappAtvMainPage);

public:
#ifdef __MMI_ATV_RECORD__
    enum REC_BTN_ENUM
    {
        REC_BTN_PAUSE_RECORD,
        REC_BTN_STOP,
        REC_BTN_NUM
    };
#endif

    enum PAGE_TYPE_ENUM
    {
	#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
        PAGE_SETTING,
    #endif
        PAGE_SCAN_LOC,
	#if !defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
        PAGE_STORAGE_SELECT
    #endif
    };

    enum KEY_CODE_ENUM
    {
        ARROW_UP,
        ARROW_DOWN,
        ARROW_LEFT,
        ARROW_RIGHT
    };

    enum
    {
        DELAY_KEY_LONG_PRESS = 900,
        DELAY_KEY_REPEAT = 700
    };

    VappAtvApp *m_app;
    VfxImageFrame *m_signalImg;
    VappAtvToolBar *m_toolBar;
#ifndef __MMI_ATV_SLIM__
    VappAtvWheelPanel *m_wheelPanel;
#else
	VappAtvWheelPanelSlim *m_wheelPanel;
#endif
#ifdef __MMI_ATV_PLAYER_SETTING__
    VappAtvAdjustBar *m_adjustBar;
#endif
    VfxVideoFrame *m_videoFrame;
    VcpConfirmPopup *m_saveCfmPopup;
    VcpConfirmPopup *m_savePathCfmPopup;
    VappAtvScanProg *m_scanProg;
	VAPP_ATV_DISP_TYPE_ENUM m_dispType;
    VfxImageFrame *m_imgFrmRecStatus;
    VfxTextFrame *m_textFrmRecTime;
#ifdef __MMI_ATV_RECORD__
    VfxTimer *m_timerUpdateRecTime;
#endif
    VcpIndicatorPopup *m_recIndPopup;
    VfxTimer* m_timerHide;
    VfxTimer* m_timerKeyEvt;
#ifdef __MMI_ATV_THUMBNAIL__
    VappAtvThumbButton *m_thumbBtn;
#else
	VfxFrame *m_thumbImgFrame;
#endif
#ifdef __MMI_ATV_RECORD__
    VcpButton *m_recBtn[REC_BTN_NUM];
#endif	
    VfxMsec m_recStartSec;
    VfxMsec m_recTotalSec;
    VfxBool m_vdoFrmPrepared;

    VfxSignal1 <PAGE_TYPE_ENUM> m_signalChangePage;


    
    VfxWChar m_storagePath[SRV_FMGR_PATH_BUFFER_SIZE>>1];
    VfxWChar m_saveCfmStr[VAPP_ATV_CFM_STR_LENGTH];
	VcpSelectPopup *m_audModePopup;
	VfxFrame *m_qucikPreviewFrame;
	VcpLoadingPopup *m_loadingPopup;
	MMI_BOOL m_isImageThumb;

    /* Constructor */
    VappAtvMainPage();

    /* Virtual function */
    virtual void onInit();
    virtual void onDeinit();
	virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );  //Replace onQueryRotate with onQueryRotateEx;
    
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onBack();

    void onToolBarButtonCliked(
        VappAtvToolBar::BUTTON_TYPE_ENUM type
    );
    void onToolBarDrag(VappAtvToolBar::DRAG_TYPE_ENUM type, VfxS32 diffX);
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual VfxBool onPreviewPenInput(VfxPenEvent &event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);


    VfxBool recordValidate();
    VfxBool isClicked(VfxPoint &a, VfxPoint &b);
    VfxBool isWheelPanelShow();

    void handleKeyEvt(KEY_CODE_ENUM code, VfxKeyEventTypeEnum type);
    void keyRightRepeatTimeout(VfxTimer *timer);
    void keyLeftRepeatTimeout(VfxTimer *timer);
    void keyDownLongPressTimeout(VfxTimer *timer);
    void keyUpLongPressTimeout(VfxTimer *timer);
    void disconnectKeyTimeoutAll();
    void keyRightHdlr();
    void keyLeftHdlr();
    void onAudModeSelected(VfxObject* sender, VfxU32 index);
    void onVideoFramePrepared();
    void getTVPosSize(VfxS32 *x, VfxS32 *y, VfxS32 *width, VfxS32 *height);
    void setSignalLevel(VfxS32 level);
    void displayAudModeList();
    void onAdjustBtnClicked();
	
#ifdef __MMI_ATV_RECORD__
    void displayRecordBtn();
    void onRecBtnClicked(VfxObject *sender, VfxId Id);
    void onRecBtnStateChanged(VfxObject* sender, VfxId id, VcpButtonStateEnum state);
#endif
    void onMdiFailCfmClicked(VfxObject* sender, VfxU32 id);
#ifdef __MMI_ATV_RECORD__
    void switchRecordBtn();
    void displaySaveConfirm(MDI_RESULT ret);
    void onSaveRecCfmClicked(VfxObject* sender, VfxU32 id);
    void onRecordSavePathCfm(VfxObject* sender, VfxU32 id);
#endif
    void onSnapshotSavePathCfm(VfxObject* sender, VfxU32 id);
    void displaySavePathCfm(VfxBool isRecorded);
#ifdef __MMI_ATV_RECORD__
    void finalizeRec(VfxBool preview);
#endif
    void exitForeground();
#ifdef __MMI_ATV_RECORD__
    void closeRecComp();
#endif
    void displayPleaseWait();
    void startHideTimer();
    void hideIconTimeout(VfxTimer *timer);
    void stopHideTimer();
#ifdef __MMI_ATV_RECORD__
    void unhideRecordBtn();
#endif
    void displayScanProg();
    void toggleToolBar();
#ifdef __MMI_ATV_PLAYER_SETTING__
    void displayPlayerSetting();
#endif
    void setDispType(VAPP_ATV_DISP_TYPE_ENUM type);
    void scanEvthandler(VappAtvScanProg::EVT_TYPE_ENUM);
    void showMdiFailConfirm(MDI_RESULT ret);
    void hideCtrlPanel(VfxBool hide);
    void getImgThumb();
	void getQuickPreview();
#if defined (__MMI_ATV_RECORD__) && defined(__MMI_ATV_THUMBNAIL__)
    void getRecThumb();
#endif
#ifdef __MMI_ATV_THUMBNAIL__
    void closeThumb();
    void displayThumb(VfxImageSrc *imgSrc);
#endif
    void clearVideoFrame(void);
    void onChangeChannel(VfxU8 target_channel);
    void onWheelEndScroll(VfxObject *object);
    void resetAnchor();
    void setVideoFramePosSize();
#ifdef __MMI_ATV_RECORD__
    void UpdateRecTimeCyclic(VfxTimer *timer);
#endif
#ifdef __MMI_ATV_THUMBNAIL__
    void onThumbBtnClicked();
#endif
	void createLoadingPopup();
	void closeLoadingPopup();
	
private:
    enum
    {
        DELAY_HIDE = 3000,
        CLICK_TIME = 400,
        CLICK_DIST = 30,
        STROKE_DIST = 50,
        DELAY_UPDATE_REC = 500,
        TIME_COLOR = 255,
        QUICK_PREVIEW = 1000
    };
};

/* Page: Settings */
class VappAtvSettingPage : public VfxPage
{
    //VFX_DECLARE_CLASS(VappAtvSettingPage);

public:
    virtual void onInit();
    virtual void onDeinit();
	virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );  //Replace onQueryRotate with onQueryRotateEx;

    void settingSelHandler(VcpFormItemCell* sender, VfxId Id);
#ifdef __MMI_ATV_STORAGE_SELECT__
    void setIsCellEnabled();
#endif
    enum CELL_TYPE_ENUM
    {
        CELL_SCAN_LOCATION,     //0
	#ifdef __MMI_ATV_PLAYER_SETTING__        
        CELL_PLAYER_SETTING,    //1
	#endif
	#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_RECORD_SIZE_SELECT__)
        CELL_RECORD_SIZE,       //2
#endif
        CELL_STORAGE,           //3
        CELL_NUM                //4
    };

    VfxSignal1 <CELL_TYPE_ENUM> m_signalListCellClicked;

private:

    VappAtvApp *m_app;
    VcpForm *m_form;
    VcpFormItemLauncherCell *m_cell[CELL_NUM];
};

#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_RECORD_SIZE_SELECT__)
/* Page: Record size */
class VappAtvRecSizePage : public VfxPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappAtvRecSizePage);

public:
    VappAtvApp *m_app;

    virtual void onInit();
    virtual void onDeinit();
	virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );  //Replace onQueryRotate with onQueryRotateEx;

    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color);

    virtual VfxU32 getCount(void) const;

    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

    void SizeSelHandler(VcpListMenu *menu, VfxU32 index);


    VfxSignal0 m_signalRecSizeClicked;
private:


};
#endif
/* Page: Storage */
class VappAtvStoragePage : public VfxPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappAtvStoragePage);

public:
    VappAtvApp *m_app;

    VappAtvStoragePage();

    void initStorageStatus();
    void setItemDisable(VfxU32 index,VfxBool isDisabled);

    virtual void onInit();
    virtual void onDeinit();	
    virtual void onEntered();
	virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );  //Replace onQueryRotate with onQueryRotateEx;

    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color);

    virtual VfxU32 getCount(void) const;

    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
    virtual VfxBool getItemIsDisabled(VfxU32 index) const;

    void StorageSelHandler(VcpListMenu *menu, VfxU32 index);

    VfxSignal0 m_signalStorageClicked;
private:
    VcpListMenu * m_storageList;
    VfxS32 storageNum;
    srv_fmgr_drv_type_enum drvType[2]; //phone & memory card
};

/* Screen */
class VappAtvScreen : public VfxMainScr
{
    //VFX_DECLARE_CLASS(VappAtvScreen);


public:
    /* Constructor */
    VappAtvScreen();

    VappAtvApp *m_app;
    VappAtvScanLocPage *m_scanLocPage;
    VappAtvMainPage *m_mainPage;
#ifdef __MMI_ATV_STORAGE_SELECT__
    VappAtvStoragePage *m_storagePage;
#endif
#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
    VappAtvSettingPage *m_settingPage;
#endif
#ifdef __MMI_ATV_RECORD_SIZE_SELECT__
    VappAtvRecSizePage *m_recSizePage;
#endif
    virtual void on1stReady();
    virtual void on2ndReady();
	virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );  //Replace onQueryRotate with onQueryRotateEx;

    /* Self-Defined function */
    void onSettingCellClicked(VappAtvSettingPage::CELL_TYPE_ENUM);
    void onPageChange(VappAtvMainPage::PAGE_TYPE_ENUM type);
    void displayPowerOnFailCfm();
    void onPowerOnFailCfmClicked(VfxObject* sender, VfxU32 id);
#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_RECORD_SIZE_SELECT__)
    void onRecSizeClicked();
#endif
#ifdef __MMI_ATV_STORAGE_SELECT__
    void onStroageClicked();
#endif
    void entryMainPage();
    void entryScanLocPage();
    void entrySettingPage();
#ifdef __MMI_ATV_STORAGE_SELECT__
    void entryStoragePage();
#endif
#ifdef __MMI_ATV_RECORD_SIZE_SELECT__
    void entryRecSizePage();
#endif
#ifdef __MMI_ATV_PLAYER_SETTING__
    void displayPlayerSetting();
#endif
};
#endif //__MMI_ATV_SUPPORT__
#endif /* __VAPP_ATV_H__ */

