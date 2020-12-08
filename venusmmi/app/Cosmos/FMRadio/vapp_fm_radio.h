/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   vapp_fm_radio.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  FM Radio header file
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
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __FMRADIO_FTO_H__
#define __FMRADIO_FTO_H__
#include "MMI_features.h"

#if defined(__MMI_FM_RADIO__)

#include "vapp_fm_radio_util.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_form.h"
#include "vcp_page_panel.h"
#include "vcp_activity_indicator.h"

#if defined(__MMI_NCENTER_SUPPORT__)
#include "vapp_ncenter.h"
#endif

#ifdef __MMI_FM_VIA_A2DP__
#include "vcp_loading_popup.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif
#include "Mdi_datatype.h"
#include "custom_mmi_folders_config.h"
#include "Common_nvram_editor_data_item.h"
#include "Mdi_audio.h"
#include "fmr_config_customize.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_FMRADIO_REC_FOLDER_LEN ((sizeof(RECORD_DOWNLOAD_FOLDER_NAME)/2) + 3)   /* "C:\Record\" not include null terminator */

#define VAPP_FMRADIO_REC_FILENAME_LEN 18 /* "FM record_1000.amr" not include null terminator */

#define VAPP_FMRADIO_REC_FILEPATH_LEN (VAPP_FMRADIO_REC_FOLDER_LEN + VAPP_FMRADIO_REC_FILENAME_LEN)

#define VAPP_FMRADIO_REC_MAX_SEQUENCE 999 /* Max file sequence */
#define VAPP_FMRADIO_REC_FIND_RANGE 20 /* Number of file names check at one function call */

#ifdef __FM_RADIO_RDS_SUPPORT__
#define VAPP_FMRADIO_RDS_OFF    0xFFFF
#define VAPP_FMRADIO_RDS_ON     0x0001
#define VAPP_FMRADIO_TAON       0x0002
#define VAPP_FMRADIO_TP         0x0004
#define VAPP_FMRADIO_PN         0x0008
#define VAPP_FMRADIO_RT         0x0010
#define VAPP_FMRADIO_AF         0x0020
#define VAPP_FMRADIO_RESET_ALL  0x00FE

#define VAPP_FMRADIO_RDS_PN_CHAR_NUM 9
#define VAPP_FMRADIO_RDS_RT_CHAR_NUM 64

#endif

#define VAPP_FM_RADIO_AUTO_LIST_NUM 20
#define VAPP_FM_RADIO_FAV_LIST_NUM 20
#define VAPP_FM_RADIO_FAV_NAME_CHAR_NUM 20
#define VAPP_FM_RADIO_PROGRAM_NAME_CHAR_NUM 20


typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER
    VfxBool is_open;
} vapp_fm_radio_close_open_evt_struct;

typedef struct
{
    int ret;
    VfxU64 disk_size;
    VfxU64 remain_time;
}vapp_fm_radio_check_size_result;


/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/
class VappFMRadioApp;
class VappFMRadioScreen;
class VappFMRadioControl;
#ifdef __FM_RADIO_RDS_SUPPORT__
class VappFMRadioRDSArea;
#endif
class VappFMRadioTuner;
class VappFMRadioLPButton;
class VappFMRadioWheel;
class VappFMRadioWheelArea;
class VappFMRadioList;
class VappFMRadioAutoMgr;
class VappFMRadioListAuto;
class VappFMRadioListFav;
class VappFMRadioListTab;
class VappFMRadioListTabItem;
class VappFMRadioMainPage;
class VappFMRadioInfo;
class VappFMRadioChannelBox;
class VappFMRadioSettingPage;
#ifndef __LOW_COST_SUPPORT_COMMON__
    class VappFMRadioStorageSettingPage;
#endif
class VappFMRadioQualitySettingPage;

/***************************************************************************** 
 * Class VappFMRadioApp
 *****************************************************************************/
class VappFMRadioApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappFMRadioApp);

public:

    enum VappFMRadioQualityEnum
    {
        QUALITY_STANDARD,
        QUALITY_HIGH,
        QUALITY_TOTAL
    };

    enum 
    {
        MIN_FREQ = FM_RADIO_MIN_FREQ,
        MAX_FREQ = FM_RADIO_MAX_FREQ
    };

    enum VappFMRadioRecErr
    {
        REC_ERR_SUCCESS,
        REC_ERR_MDI,
        REC_ERR_FS,
        //REC_ERR_CREATE_FAIL,
        REC_ERR_NO_CARD,
        REC_ERR_NO_SPACE,
        REC_ERR_RUN_OUT_FILE_NAME,
        REC_ERR_LOOP
    };

    enum VappFMRadioRDSTypes
    {
        TYPE_RDS,
        TYPE_AF,
        TYPE_TP,
        TYPE_ALL
    };

    static VappFMRadioApp *m_self;

    vadp_fm_radio_state_enum m_state;
    VfxU16 m_curFreq;
    VfxU16 m_preFreq;
    VfxTimer *m_delaySetFreqTimer;
    VfxTimer *m_delaySetPowerOnFreqTimer;

#ifdef __MMI_FM_RADIO_RECORD__
    vadp_fm_radio_record_state_enum m_recState;    
    VfxU32 m_recTime;
    VappFMRadioStorageEnum m_storage;
    VappFMRadioQualityEnum m_quality;
    VfxU16 m_stop_seq;
    VfxU16 m_last_seq;
    VfxWChar m_recPath[VAPP_FMRADIO_REC_FILEPATH_LEN + 1];
    VfxTimer *m_pathLoopTimer;
    VfxTimer *m_recTimer;
    VfxResId m_errRecStr;
#endif

#ifdef __FM_RADIO_RDS_SUPPORT__
    VfxBool m_RDS;
    VfxBool m_AF;
    VfxBool m_TP;
    VfxU16 m_RDSMask;
    VfxWChar m_programName[VAPP_FM_RADIO_PROGRAM_NAME_CHAR_NUM];
    VfxWChar m_radioText[VAPP_FMRADIO_RDS_RT_CHAR_NUM + 1];
#endif

#ifdef __MMI_FM_VIA_A2DP__ 
    // Used for showing loading animation to user if connect A2DP take a long time. 
    VfxTimer *m_a2dpConnectTimer;  
#endif

    VappFMRadioMainPage *m_mainPage;
    VappFMRadioScreen *m_scr;

#ifdef __MMI_FM_RADIO_RECORD__
    VfxSignal2 <vadp_fm_radio_record_state_enum, vadp_fm_radio_record_state_enum> m_recStateChanged;
    VfxSignal0 m_memoryCardPlugged;
#endif
    VfxSignal2 <vadp_fm_radio_state_enum, vadp_fm_radio_state_enum> m_stateChanged;

public:
    VappFMRadioApp();

    virtual void onInit(void);
    virtual void onDeinit(void);
    using VfxApp::onProcessClose;
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options, VfxAppCloseReason reason);
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);

    void powerOn(void);
    void powerOff(void);

#ifdef __MMI_FM_RADIO_RECORD__
    void recTimeUpdate(void);
    void onRecTimeTextUpdate(VfxTimer *source);
    static MMI_BOOL errRecNmgrCallback(mmi_scenario_id scen_id, void *arg);
    void onFindRecPathLoopTimeOut(VfxTimer *source);
    void recErrorPopup(VappFMRadioApp::VappFMRadioRecErr err, S32 fs_error);
    VappFMRadioRecErr findRecPathLoop(S32 *fs_error);
    VappFMRadioRecErr getRecFilePath(VfxWChar *filepath, S32 *fs_error);
    VappFMRadioRecErr checkRecFolderPath(VfxWChar *folder_path, S32 *fs_error);
    vapp_fm_radio_check_size_result getRecordDrvFreeSpace(void);
    vapp_fm_radio_check_size_result checkRecordRemainTime(void);
    void startRec(void);
    void pauseRec(void);
    void stopRec(VfxBool need_inform, VfxBool need_stop);
    void saveRec(void);
    void cancelSaveRec(void);
#endif

    void switchOutputPath(void);
    vadp_fm_radio_state_enum getState(void);
    void pureSetState(vadp_fm_radio_state_enum state);
    void setState(vadp_fm_radio_state_enum state);
    
#ifdef __MMI_FM_RADIO_RECORD__
    vadp_fm_radio_record_state_enum getRecState(void);
    void setRecState(vadp_fm_radio_record_state_enum state, VfxBool is_start);
#endif

    VfxU16 getPreFreq(void);
    VfxU16 getFreq(void);
    void setFreq(VfxU16 freq, VfxBool is_apply);
    void setSeekFreq(VfxU16 freq, VfxBool is_apply);
    void setFreqHdlr(VfxTimer *source);
    void delaySetFreq(void);

#ifdef __MMI_FM_RADIO_RECORD__
    VappFMRadioStorageEnum getStorage(void);
    void setStorage(VappFMRadioStorageEnum storage);

    VappFMRadioQualityEnum getQuality(void);
    void setQuality(VappFMRadioQualityEnum quality);
#endif

#ifdef __FM_RADIO_RDS_SUPPORT__
    static void RDSCallback(mdi_rds_event_struct *buffer, void *user_data);
    void turnOnRDS(void);
    void turnOffRDS(void);
    void resetRDS(VfxU16 mask);
    void enableAFTP(void);
    void disableAFTP(void);
    void clearMask(VfxU16 mask);
    void setMask(VfxU16 mask);
    VfxBool getRDS(VappFMRadioRDSTypes type);
    void setRDS(VappFMRadioRDSTypes type, VfxBool turn_on);
#endif
    void queryState(void);
    void onAppUpdate(void);

    // Check whether DelaySetPowerOnFreq timer is enabled.
    VfxBool isDelaySetPowerOnFreqEnable();
    // Check whether the FM Radio main interface shows in top most currently.
    VfxBool isFMRadioMainInterfaceActive();
    void updateSpeakerState(void);

    static void procCallback(mmi_event_struct *evt, void *user_data);
    static void generalCallback(mdi_result result, void *user_data);
    static MMI_BOOL backgroundCallback(mdi_result result, void *user_data);

#ifdef __MMI_FM_VIA_A2DP__
    // Connect A2DP has began.
    void connectA2dpBegin(void);
    // Connect A2DP has end.
    void connectA2dpEnd(void);
    // Connect A2DP has timeout and need to show loading animation.
    void onConnectA2dpTimeout(
        VfxTimer *timer         // [in] The timer which has timeout.
    );
#endif // __MMI_FM_VIA_A2DP__

#ifdef __MMI_AVRCP_SUPPORT__
    // AVRCP cmd process function.
    static VfxBool avrcpCmdCallback(
        VfxKeyEvent &event,     // [in] Key event transfered from AVRCP cmd
        VfxBool is_from_avrcp,  // [in] Indicate whether the key event is transfered from AVRCP cmd
        void *user_data         // [in] User data, usually is the object point of this class
    );
#endif // __MMI_AVRCP_SUPPORT__

#if defined(__MMI_NCENTER_SUPPORT__)
    // Handle NCenter events
    void onNCenterStatusChanged(VappNCenterEventEnum evt);
#endif

};

/***************************************************************************** 
 * Class VappFMRadioScreen
 *****************************************************************************/

enum VappFMRadioSwitchScreen
{
    FM_RADIO_TO_TUNER,
    FM_RADIO_TO_CHANNEL
};

class VappFMRadioScreen : public VfxMainScr
{
public:
//    VappFMRadioMainPage *m_mainPage;

// Override
public:
    VappFMRadioScreen(void);
    virtual void on1stReady(void);
    virtual void on2ndReady(void);
    virtual void onEnter(VfxBool isBackward);
    virtual void onExited(VfxBool isBackward);
};

/***************************************************************************** 
 * Class VappFMRadioControl
 *****************************************************************************/
class VappFMRadioControl : public VfxControl
{
    friend class VappFMRadioMainPage;

public:

    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        HEADSET_X = 9,
        HEADSET_Y = 0,
        HEADSET_WIDTH = 32,
        HEADSET_HEIGHT = 32,
        FAV_X = 279,
        FAV_Y = 0,
        FAV_WIDTH = 32,
        FAV_HEIGHT = 32,
        RDS_BOX_X = 118,
        RDS_BOX_Y = 11,
        RDS_BOX_WIDTH = 98,
        RDS_BOX_HEIGHT = 16,
        TUNER_X = 10,
        TUNER_Y = 44,
        TUNER_WIDTH = 300,
        TUNER_HEIGHT = 53,
        ARROW_L_X = 0,
        ARROW_L_Y = 100,
        ARROW_R_X = 286,
        ARROW_R_Y =100,
        ARROW_WIDTH = 34,
        ARROW_HEIGHT = 54,
        WHEEL_X = 37,
        WHEEL_Y = 111,
        WHEEL_WIDTH = 247,
        WHEEL_HEIGHT = 53,
        WHEEL_HEIGHT_EXPAND = 26,
        HOLE_X = 5,
        HOLE_Y = 164,
        HOLE_WIDTH = 311,
        HOLE_HEIGHT= 92,
        POWER_X = 124, 
        POWER_Y = 226,
        POWER_WIDTH = 72,
        POWER_HEIGHT = 72,
        REC_START_X = 8,
        REC_START_Y = 319,
        REC_START_WIDTH = 47,
        REC_START_HEIGHT = 46,
        REC_STOP_X = 66,
        REC_STOP_Y = REC_START_Y,
        REC_STOP_WIDTH = REC_START_WIDTH,
        REC_STOP_HEIGHT = REC_START_HEIGHT,
        REC_TIME_X = 122,
        REC_TIME_Y = 333,
        REC_TIME_WIDTH = 76,
        REC_TIME_HEIGHT = 18,
        REC_TIME_FONT_SIZE = 15,
        LIST_X = 207,
        LIST_Y = REC_START_Y,
        LIST_WIDTH = REC_START_WIDTH,
        LIST_HEIGHT = REC_START_HEIGHT,
        SETTING_X = 265,
        SETTING_Y = REC_START_Y,
        SETTING_WIDTH = REC_START_WIDTH,
        SETTING_HEIGHT = REC_START_HEIGHT
#elif defined(__MMI_MAINLCD_480X800__)
        HEADSET_X = 15,
        HEADSET_Y = 9,
        HEADSET_WIDTH = 46,
        HEADSET_HEIGHT = 46,
        FAV_X = 419,
        FAV_Y = 9,
        FAV_WIDTH = 46,
        FAV_HEIGHT = 46,
        RDS_BOX_X = 177,
        RDS_BOX_Y = 22,
        RDS_BOX_WIDTH = 152,
        RDS_BOX_HEIGHT = 42,
        TUNER_X = 15,
        TUNER_Y = 78,
        TUNER_WIDTH = 450,
        TUNER_HEIGHT = 80,
        ARROW_L_X = 0,
        ARROW_L_Y = 158,
        ARROW_R_X = 426,
        ARROW_R_Y = 158,
        ARROW_WIDTH = 54,
        ARROW_HEIGHT = 82,
        WHEEL_X = 55,
        WHEEL_Y = 171,
        WHEEL_WIDTH = 371,
        WHEEL_HEIGHT = 75,
        WHEEL_HEIGHT_EXPAND = 37,
        HOLE_X = 9,
        HOLE_Y = 253,
        HOLE_WIDTH = 465,
        HOLE_HEIGHT= 199,
        POWER_X = 187, 
        POWER_Y = 409,
        POWER_WIDTH = 107,
        POWER_HEIGHT = 107,
        REC_START_X = 13,
        REC_START_Y = 544,
        REC_START_WIDTH = 69,
        REC_START_HEIGHT = 69,
        REC_STOP_X = 92,
        REC_STOP_Y = REC_START_Y,
        REC_STOP_WIDTH = REC_START_WIDTH,
        REC_STOP_HEIGHT = REC_START_HEIGHT,
        REC_TIME_X = 166,
        REC_TIME_Y = 565,
        REC_TIME_WIDTH = 150,
        REC_TIME_HEIGHT = 28,
        REC_TIME_FONT_SIZE = 24,
        LIST_X = 319,    
        LIST_Y = REC_START_Y,
        LIST_WIDTH = REC_START_WIDTH,
        LIST_HEIGHT = REC_START_HEIGHT,
        SETTING_X = 398,
        SETTING_Y = REC_START_Y,
        SETTING_WIDTH = REC_START_WIDTH,
        SETTING_HEIGHT = REC_START_HEIGHT
#elif defined(__MMI_MAINLCD_240X400__)
        HEADSET_X = 7,
        HEADSET_Y = 4,
        HEADSET_WIDTH = 24,
        HEADSET_HEIGHT = 24,
        FAV_X = 209,
        FAV_Y = 4,
        FAV_WIDTH = 24,
        FAV_HEIGHT = 24,
        RDS_BOX_X = 87,
        RDS_BOX_Y = 8,
        RDS_BOX_WIDTH = 85,
        RDS_BOX_HEIGHT = 14,
        TUNER_X = 7,
        TUNER_Y = 38,
        TUNER_WIDTH = 226,
        TUNER_HEIGHT = 40,
        ARROW_L_X = 0,
        ARROW_L_Y = 78,
        ARROW_R_X = 213,
        ARROW_R_Y = 78,
        ARROW_WIDTH = 27,
        ARROW_HEIGHT = 40,
        WHEEL_X = 27,
        WHEEL_Y = 85,
        WHEEL_WIDTH = 186,
        WHEEL_HEIGHT = 38,
        WHEEL_HEIGHT_EXPAND = 19,
        HOLE_X = 4,
        HOLE_Y = 128,
        HOLE_WIDTH = 234,
        HOLE_HEIGHT= 99,
        POWER_X = 93, 
        POWER_Y = 205,
        POWER_WIDTH = 54,
        POWER_HEIGHT = 54,
        REC_START_X = 7,
        REC_START_Y = 273,
        REC_START_WIDTH = 39,
        REC_START_HEIGHT = 37,
        REC_STOP_X = 53,
        REC_STOP_Y = REC_START_Y,
        REC_STOP_WIDTH = REC_START_WIDTH,
        REC_STOP_HEIGHT = REC_START_HEIGHT,
        REC_TIME_X = 97,
        REC_TIME_Y = 287,
        REC_TIME_WIDTH = 51,
        REC_TIME_HEIGHT = 15,
        REC_TIME_FONT_SIZE = 10,
        LIST_X = 151,	 
        LIST_Y = REC_START_Y,
        LIST_WIDTH = REC_START_WIDTH,
        LIST_HEIGHT = REC_START_HEIGHT,
        SETTING_X = 197,
        SETTING_Y = REC_START_Y,
        SETTING_WIDTH = REC_START_WIDTH,
        SETTING_HEIGHT = REC_START_HEIGHT
#else//if defined(__MMI_MAINLCD_240X320__)
        HEADSET_X = 7,
        HEADSET_Y = 4,
        HEADSET_WIDTH = 24,
        HEADSET_HEIGHT = 24,
        FAV_X = 209,
        FAV_Y = 4,
        FAV_WIDTH = 24,
        FAV_HEIGHT = 24,
        RDS_BOX_X = 87,
        RDS_BOX_Y = 8,
        RDS_BOX_WIDTH = 85,
        RDS_BOX_HEIGHT = 14,
        TUNER_X = 7,
        TUNER_Y = 38,
        TUNER_WIDTH = 226,
        TUNER_HEIGHT = 40,
        ARROW_L_X = 0,
        ARROW_L_Y = 78,
        ARROW_R_X = 213,
        ARROW_R_Y = 78,
        ARROW_WIDTH = 27,
        ARROW_HEIGHT = 40,
        WHEEL_X = 27,
        WHEEL_Y = 85,
        WHEEL_WIDTH = 186,
        WHEEL_HEIGHT = 38,
        WHEEL_HEIGHT_EXPAND = 19,
        HOLE_X = 4,
        HOLE_Y = 124,
        HOLE_WIDTH = 234,
        HOLE_HEIGHT= 39,
        POWER_X = 93, 
        POWER_Y = 128,
        POWER_WIDTH = 54,
        POWER_HEIGHT = 54,
        REC_START_X = 7,
        REC_START_Y = 193,
        REC_START_WIDTH = 39,
        REC_START_HEIGHT = 37,
        REC_STOP_X = 53,
        REC_STOP_Y = REC_START_Y,
        REC_STOP_WIDTH = REC_START_WIDTH,
        REC_STOP_HEIGHT = REC_START_HEIGHT,
        REC_TIME_X = 97,
        REC_TIME_Y = 207,
        REC_TIME_WIDTH = 51,
        REC_TIME_HEIGHT = 15,
        REC_TIME_FONT_SIZE = 10,
        LIST_X = 151, 
        LIST_Y = REC_START_Y,
        LIST_WIDTH = REC_START_WIDTH,
        LIST_HEIGHT = REC_START_HEIGHT,
        SETTING_X = 197,
        SETTING_Y = REC_START_Y,
        SETTING_WIDTH = REC_START_WIDTH,
        SETTING_HEIGHT = REC_START_HEIGHT

#endif
    };

private:
    VcpImageButton *m_btnSpeaker;
#ifdef __FM_RADIO_RDS_SUPPORT__
    VappFMRadioRDSArea *m_RDSArea;
#endif
    VcpImageButton *m_btnFav;
    VappFMRadioTuner *m_tuner;
    VappFMRadioLPButton *m_btnArrowL;
    VappFMRadioWheel *m_wheel;
    VappFMRadioWheelArea *m_wheelArea;
    VappFMRadioLPButton *m_btnArrowR;
    VcpButton *m_btnPower;
#ifdef __MMI_FM_RADIO_RECORD__
    VcpButton *m_btnRrecStart;
    VcpButton *m_btnRecStop;
    VfxTextFrame *m_recTimeText;
#endif
#if defined(__MMI_FM_RADIO_RECORD__) || defined(__FM_RADIO_RDS_SUPPORT__)
    VcpButton *m_btnSetting;
#endif
    VcpButton *m_btnList;

public:
    VappFMRadioControl();
    virtual void onInit(void);
    void drawButtonState(VfxId button, VfxKeyEventTypeEnum key_event);
    void updateSpeakerBtn(VfxU8 audio_path);
#ifdef __MMI_FM_RADIO_RECORD__
    void updateRecTimeText(VfxU32 time);
#endif

private:
    //Add visual touch feedback for Image buttons
    void setBtnHaloEffect();

};

/***************************************************************************** 
 * Class VappFMRadioRDSArea
 *****************************************************************************/
#ifdef __FM_RADIO_RDS_SUPPORT__
class VappFMRadioRDSArea : public VfxFrame
{
private:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        DISTANCE = 8,
        RDS_FONT_SIZE = 14
#elif defined(__MMI_MAINLCD_480X800__)
        DISTANCE = 12,
        RDS_FONT_SIZE = 20
#elif defined(__MMI_MAINLCD_240X400__)
        DISTANCE = 3,
        RDS_FONT_SIZE = 13
#else//if defined(__MMI_MAINLCD_240X320__)
        DISTANCE = 3,
        RDS_FONT_SIZE = 13
#endif
    };

    VfxTextFrame *m_TP;
    VfxTextFrame *m_AF;
    VfxTextFrame *m_RDS;

public:
    VappFMRadioRDSArea();
    virtual void onInit(void);
    void setLight(VappFMRadioApp::VappFMRadioRDSTypes area, VfxBool turn_on);

};
#endif

/***************************************************************************** 
 * Class VappFMRadioLPButton
 *****************************************************************************/
class VappFMRadioLPButton : public VcpImageButton
{
public:
    VfxSignal3 <VfxObject*, VfxId, VfxPenEventTypeEnum> m_buttonStatus;

// Override
public:
    VappFMRadioLPButton();
    virtual VfxBool onPenInput(VfxPenEvent &event);

};

/***************************************************************************** 
 * Class VappFMRadioWheel
 *****************************************************************************/
class VappFMRadioWheel : public VfxControl
{
private:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        BAR_X = 4,
        BAR_Y = 10,
        BAR_WIDTH = 235,
        BAR_HEIGHT = 15,
        SHADOW_X = 0,
        SHADOW_Y = 2,
        SHADOW_WIDTH = 31,
        WHEEL_WIDTH = VappFMRadioControl::WHEEL_WIDTH,
        BAR_NUM = 4
#elif defined(__MMI_MAINLCD_480X800__)
        BAR_X = 7,
        BAR_Y = 15,
        BAR_WIDTH = 356,
        BAR_HEIGHT = 22,
        SHADOW_X = 2,
        SHADOW_Y = 2,
        SHADOW_WIDTH = 57,
        WHEEL_WIDTH = VappFMRadioControl::WHEEL_WIDTH,
        BAR_NUM = 3
#elif defined(__MMI_MAINLCD_240X400__)
        BAR_X = 4,
        BAR_Y = 6,
        BAR_WIDTH = 179,
        BAR_HEIGHT = 14,
        SHADOW_X = 0,
        SHADOW_Y = 0,
        SHADOW_WIDTH = 31,
        WHEEL_WIDTH = VappFMRadioControl::WHEEL_WIDTH,
        BAR_NUM = 4
#else//if defined(__MMI_MAINLCD_240X320__)
        BAR_X = 4,
        BAR_Y = 6,
        BAR_WIDTH = 179,
        BAR_HEIGHT = 14,
        SHADOW_X = 0,
        SHADOW_Y = 0,
        SHADOW_WIDTH = 31,
        WHEEL_WIDTH = VappFMRadioControl::WHEEL_WIDTH,
        BAR_NUM = 4
#endif
    };

    VappFMRadioApp *m_app;
    VfxImageFrame *m_wheelBar;
    static const VfxU16 m_centerFreq = 975;
    VfxFloatTimeline *m_timeline;

public:
    VappFMRadioWheel();
    virtual void onInit(void);
    void spinWheel(VfxS32 freq);
    static VfxU8 getWheelBarCount(VfxU16 freq);

    static vrt_render_dirty_type_enum redrawWheelBarCallback(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size);

};

/***************************************************************************** 
 * Class VappFMRadioWheelArea
 *****************************************************************************/
class VappFMRadioWheelArea : public VfxControl
{
    VappFMRadioApp *m_app;

public:
    VfxSignal2 <VfxObject*, VfxPenEvent> m_wheelStatus;


public:
    VappFMRadioWheelArea();
    virtual void onInit(void);
    virtual VfxBool onPenInput(VfxPenEvent &event);
};



/***************************************************************************** 
 * Class VappFMRadioTuner
 *****************************************************************************/
class VappFMRadioTuner : public VfxFrame
{
private:

    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        MARK_X = 11,
        MARK_Y = 13,
        MARK_LENGTH = 278,
        MARK_TO_FREQ = 20,
        FREQ_FONT_SIZE = 12
#elif defined(__MMI_MAINLCD_480X800__)
        MARK_X = 16,
        MARK_Y = 19,
        MARK_LENGTH = 418,
        MARK_TO_FREQ = 27,
        FREQ_FONT_SIZE = 18
#elif defined(__MMI_MAINLCD_240X400__)
        MARK_X = 8,
        MARK_Y = 10,
        MARK_LENGTH = 210,
        MARK_TO_FREQ = 14,
        FREQ_FONT_SIZE = 9
#else//if defined(__MMI_MAINLCD_240X320__)
        MARK_X = 8,
        MARK_Y = 10,
        MARK_LENGTH = 210,
        MARK_TO_FREQ = 14,
        FREQ_FONT_SIZE = 9
#endif
    };

    VfxImageFrame *m_pin;
    //VfxS32 m_pinX;
    //static const VfxS32 m_pinY = 0;
    VfxFloat m_interval;
    VfxImageFrame *m_light;
    VfxImageFrame* m_mark;
    VfxTextFrame *m_low_freq;
    VfxTextFrame *m_high_freq;


public:
    VappFMRadioTuner();
    virtual void onInit(void);

    void setLight(VfxBool turn_on);
    void setPin(VfxU16 freq);

};

/***************************************************************************** 
 * Class VappFMRadioList
 *****************************************************************************/
class VappFMRadioList : public VfxControl
{
    friend class VappFMRadioMainPage;

public:
    enum
    {
        //AUTO_X = 0,
        //AUTO_Y = 0,
        //AUTO_WIDTH = LCD_WIDTH / 2,
        //AUTO_HEIGHT = 50,
        //FAV_X = AUTO_WIDTH,
        //FAV_Y = 0,
        //FAV_WIDTH = AUTO_WIDTH,
        //FAV_HEIGHT = AUTO_HEIGHT,
#if defined(__MMI_MAINLCD_320X480__)
        TAB_X = 0,
        TAB_Y = 0,
        TAB_WIDTH = LCD_WIDTH,
        TAB_HEIGHT = 50,
        PANEL_X = 0,
        PANEL_Y = TAB_HEIGHT,
        PANEL_WIDTH = LCD_WIDTH,
        PANEL_HEIGHT = 350,
        // below size are relative to page panel, to share for both panel
        LIST_X = 0, 
        LIST_Y = 0,
        LIST_WIDTH = PANEL_WIDTH,
        LIST_HEIGHT = 259,
        BOTTOM_X = 0,
        BOTTOM_Y = LIST_HEIGHT,
        BOTTOM_WIDTH = LCD_WIDTH,
        BOTTOM_HEIGHT = PANEL_HEIGHT - LIST_HEIGHT
#elif defined(__MMI_MAINLCD_480X800__)
        TAB_X = 0,
        TAB_Y = 0,
        TAB_WIDTH = LCD_WIDTH,
        TAB_HEIGHT = 82,
        PANEL_X = 0,
        PANEL_Y = TAB_HEIGHT,
        PANEL_WIDTH = LCD_WIDTH,
        PANEL_HEIGHT = 549,
        // below size are relative to page panel, to share for both panel
        LIST_X = 0, 
        LIST_Y = 0,
        LIST_WIDTH = PANEL_WIDTH,
        LIST_HEIGHT = 446,
        BOTTOM_X = 0,
        BOTTOM_Y = LIST_HEIGHT,
        BOTTOM_WIDTH = LCD_WIDTH,
        BOTTOM_HEIGHT = PANEL_HEIGHT - LIST_HEIGHT
#elif defined(__MMI_MAINLCD_240X400__)
        TAB_X = 0,
        TAB_Y = 0,
        TAB_WIDTH = LCD_WIDTH,
        TAB_HEIGHT = 41,
        PANEL_X = 0,
        PANEL_Y = TAB_HEIGHT,
        PANEL_WIDTH = LCD_WIDTH,
        PANEL_HEIGHT = 272,
        // below size are relative to page panel, to share for both panel
        LIST_X = 0, 
        LIST_Y = 0,
        LIST_WIDTH = PANEL_WIDTH,
        LIST_HEIGHT = 224,
        BOTTOM_X = 0,
        BOTTOM_Y = LIST_HEIGHT,
        BOTTOM_WIDTH = LCD_WIDTH,
        BOTTOM_HEIGHT = PANEL_HEIGHT - LIST_HEIGHT
#else//if defined(__MMI_MAINLCD_240X320__)
        TAB_X = 0,
        TAB_Y = 0,
        TAB_WIDTH = LCD_WIDTH,
        TAB_HEIGHT = 41,
        PANEL_X = 0,
        PANEL_Y = TAB_HEIGHT,
        PANEL_WIDTH = LCD_WIDTH,
        PANEL_HEIGHT = 272,
        // below size are relative to page panel, to share for both panel
        LIST_X = 0, 
        LIST_Y = 0,
        LIST_WIDTH = PANEL_WIDTH,
        LIST_HEIGHT = 144,
        BOTTOM_X = 0,
        BOTTOM_Y = LIST_HEIGHT,
        BOTTOM_WIDTH = LCD_WIDTH,
        BOTTOM_HEIGHT = PANEL_HEIGHT - LIST_HEIGHT
#endif
    };

    enum VappFMRadioTabMode
    {
        AUTO_SEARCH,
        FAVORITE
    };

private:
    VcpPagePanel *m_pagePanel;

public:
    VappFMRadioListTab *m_tab;
    VappFMRadioTabMode m_tabChoose;
    VappFMRadioListAuto *m_autoList;
    VappFMRadioListFav *m_favList;

public:
    VappFMRadioList();
    virtual void onInit(void);
    void onTabChoose(VappFMRadioTabMode tab);
    void updateList(void);

};

/***************************************************************************** 
 * Class VappFMRadioListTabItem
 *****************************************************************************/
class VappFMRadioListTabItem : public VfxControl
{
public:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        ICON_X = 12,
        ICON_Y = 17,
        TEXT_X_GAP = 7
#elif defined(__MMI_MAINLCD_480X800__)
        ICON_X = 12,
        ICON_Y = 17,
        TEXT_X_GAP = 12
#elif defined(__MMI_MAINLCD_240X400__)
        ICON_X = 12,
        ICON_Y = 17,
        TEXT_X_GAP = 5
#else//if defined(__MMI_MAINLCD_240X320__)
        ICON_X = 12,
        ICON_Y = 17,
        TEXT_X_GAP = 5
#endif
    };

public:
    VfxImageFrame *m_icon;
    VfxTextFrame *m_text;
    VappFMRadioList::VappFMRadioTabMode m_id;
    //VfxBool m_choosen;
    VfxSignal1 <VappFMRadioList::VappFMRadioTabMode> m_signalChoose;

public:
    virtual void onInit(void);
    virtual VfxBool onPenInput(VfxPenEvent & event);
    //void setChoose(VfxBool choose);

};

/***************************************************************************** 
 * Class VappFMRadioListTab
 *****************************************************************************/
class VappFMRadioListTab : public VfxFrame
{
public:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        AUTO_WIDTH = 153,
        AUTO_HEIGHT = 50,
        AUTO_X = (LCD_WIDTH/2) - AUTO_WIDTH,
        AUTO_Y = 2,
        FAV_WIDTH = AUTO_WIDTH,
        FAV_HEIGHT = AUTO_HEIGHT,
        FAV_X = (LCD_WIDTH/2),
        FAV_Y = AUTO_Y,
        TEXT_LEN = 145,
        TEXT_FONT_SIZE = 18
#elif defined(__MMI_MAINLCD_480X800__)
        AUTO_WIDTH = 225,
        AUTO_HEIGHT = 82,
        AUTO_X = (LCD_WIDTH/2) - AUTO_WIDTH,
        AUTO_Y = 0,
        FAV_WIDTH = AUTO_WIDTH,
        FAV_HEIGHT = AUTO_HEIGHT,
        FAV_X = (LCD_WIDTH/2),
        FAV_Y = AUTO_Y,
        TEXT_LEN = 211,
        TEXT_FONT_SIZE = 27
#elif defined(__MMI_MAINLCD_240X400__)
        AUTO_WIDTH = 113,
        AUTO_HEIGHT = 41,
        AUTO_X = (LCD_WIDTH/2) - AUTO_WIDTH,
        AUTO_Y = 0,
        FAV_WIDTH = AUTO_WIDTH,
        FAV_HEIGHT = AUTO_HEIGHT,
        FAV_X = (LCD_WIDTH/2),
        FAV_Y = AUTO_Y,
        TEXT_LEN = 101,
        TEXT_FONT_SIZE = 14
#else//if defined(__MMI_MAINLCD_240X320__)
        AUTO_WIDTH = 113,
        AUTO_HEIGHT = 41,
        AUTO_X = (LCD_WIDTH/2) - AUTO_WIDTH,
        AUTO_Y = 0,
        FAV_WIDTH = AUTO_WIDTH,
        FAV_HEIGHT = AUTO_HEIGHT,
        FAV_X = (LCD_WIDTH/2),
        FAV_Y = AUTO_Y,
        TEXT_LEN = 101,
        TEXT_FONT_SIZE = 14
#endif
    };
    
public:
    VfxImageFrame *m_bg;
    VappFMRadioListTabItem *m_auto;
    VappFMRadioListTabItem *m_fav;

public:
    VappFMRadioListTab();
    virtual void onInit(void);
    void setChoose(VappFMRadioList::VappFMRadioTabMode tab);

};

/***************************************************************************** 
 * Class VappFMRadioAutoMgr
 *****************************************************************************/
class VappFMRadioAutoMgr : public VfxObject
{
public:
    nvram_ef_vapp_fmrdo_auto_list_struct m_freq;
    VfxU8 m_total;

public:
    virtual void onInit(void);
    void updateFreq(VfxU8 total, nvram_ef_vapp_fmrdo_auto_list_struct freq);
    VfxU8 getTotal(void);
    VfxU16 getFreq(VfxU8 index);
};

/***************************************************************************** 
 * Class VappFMRadioFavMgr
 *****************************************************************************/
class VappFMRadioFavMgr : public VfxObject
{
public:
    //VfxFloat m_freq[VAPP_FM_RADIO_FAV_LIST_NUM];
    //VfxWChar m_name[VAPP_FM_RADIO_FAV_LIST_NUM][VAPP_FM_RADIO_FAV_NAME_CHAR_NUM];
    nvram_ef_vapp_fmrdo_fav_list_struct m_data;
    VfxU8 m_total;
    VfxU8 m_editIndex;
    VfxSignal0 m_favListUpdated;

public:
    virtual void onInit(void);
    VfxU8 getTotal(void);
    VfxU16 getFreq(VfxU8 index);
    VfxWChar* getName(VfxU8 index);
    VfxU8 getEditIndex(void);
    void setEditIndex(VfxU8 index);
    void editList(VfxU16 freq, VfxWString name, VfxU8 index);
    VfxBool addToList(VfxU16 freq, VfxWString name);
    void DeleteItems(VfxBool* item_p);

};


/***************************************************************************** 
 * Class VappFMRadioListAuto
 *****************************************************************************/
class VappFMRadioListAuto : public VfxFrame, public IVcpListMenuContentProvider
{
    friend class VappFMRadioList;

private:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        AUTO_X = 83,
        AUTO_Y = 272,
        AUTO_WIDTH = 153,
        AUTO_HEIGHT = 42
#elif defined(__MMI_MAINLCD_480X800__)
        AUTO_X = 123,
        AUTO_Y = 461,
        AUTO_WIDTH = 228,
        AUTO_HEIGHT = 67
#elif defined(__MMI_MAINLCD_240X400__)
        AUTO_X = 63,
        AUTO_Y = 231,
        AUTO_WIDTH = 115,
        AUTO_HEIGHT = 35
#else//if defined(__MMI_MAINLCD_240X320__)
        AUTO_X = 63,
        AUTO_Y = 151,
        AUTO_WIDTH = 115,
        AUTO_HEIGHT = 35
#endif
    };

    VappFMRadioApp *m_app;
    VcpButton *m_btnSearch;
    VfxU16 m_signalCount;
    VcpConfirmPopup *m_startCnf;
    
    static VappFMRadioListAuto *m_self;

public:
    VcpListMenu *m_list;
    VcpIndicatorPopup *m_waiting;
    VappFMRadioAutoMgr *m_autoMgr;

public:
    
    VappFMRadioListAuto();
    virtual void onInit(void);
    virtual void onDeinit(void);

    void setApp(VappFMRadioApp* app);
    void updateAutoList(void);
    void onCancelAutoSearch(VfxObject* sender, VfxFloat curr_progress);
    void onAutoSearchButtonClicked(VfxObject* sender, VfxId btn);
    void onButtonClicked(VfxObject *sender, VfxId id);
    void onItemTapped(VcpListMenu *menu, VfxU32 index);
    void onStateChanged(vadp_fm_radio_state_enum pre_state, vadp_fm_radio_state_enum new_state);
    void startAutoScan(void);
    void abortAutoScan(void);
    VfxBool errBalloonHandler(void);
    void showWaitingPopup(void);

    // Get the text frame format for the text fields of list cell
    // User can update the text frame font, text color, etc.
    virtual VfxBool getItemTextFrameFormat(
                 VfxU32 index,                   // [IN] the index of item
                 VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
                 VfxTextFrame *frame             // [OUT] the text frame
                 );

    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
                 VfxU32 index,                    // [IN] the index of item
                 VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                 VfxWString &text,                // [OUT] the text resource
                 VcpListMenuTextColorEnum &color  // [OUT] the text color
                 );

    // Get the item count of the lis menu
    virtual VfxU32 getCount(void) const;

    // Get the empty text resource for the text when list menu is empty
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);

};


/***************************************************************************** 
 * Class VappFMRadioListFav
 *****************************************************************************/
class VappFMRadioListFav : public VfxFrame, public IVcpListMenuContentProvider
{
    friend class VappFMRadioList;

private:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        LEFT_BTN_X = 10,
        LEFT_BTN_Y = 272,
        RIGHT_BTN_X = 166,
        RIGHT_BTN_Y = LEFT_BTN_Y,
        BTN_WIDTH = 147,
        BTN_HEIGHT = 42
#elif defined(__MMI_MAINLCD_480X800__)
        LEFT_BTN_X = 39,
        LEFT_BTN_Y = 461,
        RIGHT_BTN_X = 262,
        RIGHT_BTN_Y = LEFT_BTN_Y,
        BTN_WIDTH = 180,
        BTN_HEIGHT = 67
#elif defined(__MMI_MAINLCD_240X400__)
        LEFT_BTN_X = 19,
        LEFT_BTN_Y = 231,
        RIGHT_BTN_X = 131,
        RIGHT_BTN_Y = LEFT_BTN_Y,
        BTN_WIDTH = 91,
        BTN_HEIGHT = 35
#else//if defined(__MMI_MAINLCD_240X320__)
        LEFT_BTN_X = 19,
        LEFT_BTN_Y = 151,
        RIGHT_BTN_X = 131,
        RIGHT_BTN_Y = LEFT_BTN_Y,
        BTN_WIDTH = 91,
        BTN_HEIGHT = 35
#endif
    };

    enum
    {
        BTN_ADD,
        BTN_DELETE,
        BTN_DELETE2,
        BTN_CANCEL
    };

    enum VappFMRadioFavListMode
    {
        ADD_MODE,
        DELETE_MODE
    };

    VappFMRadioApp *m_app;
    VcpInputPopup *m_edit;
    VcpInputPopup *m_addFav;
    VappFMRadioFavMgr *m_favMgr;
    VcpButton *m_btnL;
    VcpButton *m_btnR;
    VappFMRadioFavListMode m_mode;
    VfxBool m_select[VAPP_FM_RADIO_FAV_LIST_NUM];
    VfxU8 m_select_total;
    VfxS8 m_tappedIdx;
    VcpConfirmPopup *m_deleteCnf;

public:
    VcpListMenu *m_list;

public:

    VappFMRadioListFav();
    virtual void onInit(void);
    virtual void onItemTapped(VcpListMenu *menu, VfxU32 index);
    void setApp(VappFMRadioApp* app);

    // Get the content frame of the item, it's used when the cell style is 
    // VCP_LIST_MENU_CELL_STYLE_CUSTOM, uer should creat and layout its owned
    // cell content frame and return it here
    virtual VcpListMenuCellClientBaseFrame* getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame);

    // Get the text frame format for the text fields of list cell
    // User can update the text frame font, text color, etc.
    virtual VfxBool getItemTextFrameFormat(
                 VfxU32 index,                   // [IN] the index of item
                 VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
                 VfxTextFrame *frame             // [OUT] the text frame
                 );

    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
                 VfxU32 index,                    // [IN] the index of item
                 VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                 VfxWString &text,                // [OUT] the text resource
                 VcpListMenuTextColorEnum &color  // [OUT] the text color
                 );

    // Get the item count of the lis menu
    virtual VfxU32 getCount(void) const;

    // Get the image resource for the image fields of list cell
    virtual VfxBool getItemImage(
                 VfxU32 index,                    // [IN] the index of item
                 VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                 VfxImageSrc &image               // [OUT] the image resource
                 );

    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(
                VfxU32 index   // [IN] index of the item
                ) const;


    // Get the empty text resource for the text when list menu is empty
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);

    void onDeleteButtonClicked(VfxObject* sender, VfxId btn);
    void onButtonClicked(VfxObject *sender, VfxId id);
    void updateButton(void);
    void updateListMenu(void);
    void addToFavList(VfxU16 freq, VfxWString name);
    void cancelDelete(void);
    VfxBool onBackKey(void);

    VfxWChar* getFavName(VfxU16 freq);
    void onAddToFavPopUpButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum btn);
    void onEditPopUpButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum btn);
    void onEditButtonClicked(VcpListMenu *listmenu, VfxU32 index);
    void onEditTextActivated(VcpTextEditor *sender, VfxBool activated);
    void onSelectedChanged(VcpListMenu* menu, VfxU32 index, VcpListMenuItemStateEnum state);

};

/***************************************************************************** 
 * Class VappFMRadioMainPage
 *****************************************************************************/
class VappFMRadioMainPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappFMRadioMainPage);
    friend class VappFMRadioApp;

public:
    enum
    {
        BTN_PREV,
        BTN_NEXT,
        BTN_SPEAKER,
        BTN_FAV,
        BTN_ARROWL,
        BTN_ARROWR,
        BTN_POWER,
        BTN_REC_START,
        BTN_REC_STOP,
        BTN_LIST,
        BTN_SETTING
    };

    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        INFO_X = 0,
        INFO_Y = 0,
        INFO_WIDTH = LCD_WIDTH,
        INFO_HEIGHT = 82,
        PANEL_X = 0,
        PANEL_Y = 82,
        PANEL_WIDTH = LCD_WIDTH,
        PANEL_HEIGHT = 374
#elif defined(__MMI_MAINLCD_480X800__)
        INFO_X = 0,
        INFO_Y = 0,
        INFO_WIDTH = LCD_WIDTH,
        INFO_HEIGHT = 131,
        PANEL_X = 0,
        PANEL_Y = INFO_HEIGHT,
        PANEL_WIDTH = LCD_WIDTH,
        PANEL_HEIGHT = 631
#elif defined(__MMI_MAINLCD_240X400__)
        INFO_X = 0,
        INFO_Y = 0,
        INFO_WIDTH = LCD_WIDTH,
        INFO_HEIGHT = 63,
        PANEL_X = 0,
        PANEL_Y = INFO_HEIGHT,
        PANEL_WIDTH = LCD_WIDTH,
        PANEL_HEIGHT = 313
#else//if defined(__MMI_MAINLCD_240X320__)
        INFO_X = 0,
        INFO_Y = 0,
        INFO_WIDTH = LCD_WIDTH,
        INFO_HEIGHT = 63,
        PANEL_X = 0,
        PANEL_Y = INFO_HEIGHT,
        PANEL_WIDTH = LCD_WIDTH,
        PANEL_HEIGHT = 233
#endif
    };

    enum
    {
        LONGPRESS_DUR_MAX = 350,
        LONGPRESS_DUR_MIN = 100,
        LONGPRESS_DUR_GAP = 25,
        WHEEL_PIXELS_TO_FREQ = 3, //how many pixels in x axis stands for 0.1 MHZ frequency change
    };

private:
    VappFMRadioApp *m_app;
    VappFMRadioInfo *m_info;
    VcpActivityIndicator *m_waitingIcon;
    VfxTimer *m_arrowRTimer;
    VfxTimer *m_arrowLTimer;
    VfxU16 m_tempFreq;
    VfxId m_buttonPressed;

    // for seeking prompt
    VfxTimer *m_seekingPromptTimer;
    VfxTimer *m_seekingDelayTimer;
    VfxBool   m_isSeekingDone;

#ifdef __MMI_FM_VIA_A2DP__
    // Used for creating loading animation
    VcpLoadingPopup *m_loadingPopup;
#endif // __MMI_FM_VIA_A2DP__

#ifdef __MMI_FM_RADIO_RECORD__
public:
    VcpConfirmPopup *m_startCnf;
    VfxResId m_recSaveStr;
#endif

public:
    VappFMRadioControl *m_control;
    VcpPagePanel *m_pagePanel;
    VappFMRadioList *m_list;

public:
    VappFMRadioMainPage();
    virtual void onInit(void);
    virtual void onDeinit(void);
    void abortSeek(void);
    void updateState(void);
    // Update freq with checking seeking state.
    void updateFreq(VfxBool spin_wheel);
    // Update freq without checking seeking state.
    void pureUpdateFreq(VfxBool spin_wheel);
#ifdef __MMI_FM_RADIO_RECORD__
    void updateRecTime(VfxU32 time);
#endif
    static VfxU16 WStringToFreq(VfxWChar *s, VfxObject* parent);

    void showWaitingIcon(void);
    void hideWaitingIcon(void);
#ifdef __MMI_FM_RADIO_RECORD__
    void closeStopRecConfirms(void);
    VfxBool stopRecConfirm(void);
    VfxBool stopRecConfirm(VfxU16 freq);
#endif

#ifdef __MMI_FM_VIA_A2DP__
    // Show loading animation to user.
    void createLoadingPopup();
    // Stop loading animation.
    void closeLoadingPopup();
#endif // __MMI_FM_VIA_A2DP__

private:
    void drawMainPage(void);
    void arrowLLongPressed(VfxTimer *source);
    void arrowRLongPressed(VfxTimer *source);
#ifdef __MMI_FM_RADIO_RECORD__
    static void onRecSavePopUpButtonClicked(VfxId btn, void *user_data);
#endif
    void onWheelStatus(VfxObject *sender, VfxPenEvent event);
    void onButtonStatus(VfxObject *sender, VfxId id, VfxPenEventTypeEnum type);

    void getFavName(VfxWChar** str, VfxU16 freq);
#ifdef __FM_RADIO_RDS_SUPPORT__
    void getProgramName(VfxWChar** str);
    void getRadioText(VfxWChar** str);
    void updateRDSArea(void);
#endif

    void updateChannelBox(void);

    static void seekCallback(mdi_fmr_cb_reason_enum result, U16 stop_freq, MMI_BOOL is_valid, void* user_data);
    void startSeek(VfxBool forward);
    void onSeekingTimeout(VfxTimer *source);

#ifdef __MMI_FM_RADIO_RECORD__
    void onNoMemoryCardButtonClicked(VfxObject* sender, VfxId btn);
    void onStopRecButtonClickedInternal(VfxObject* sender, VfxId btn);
#endif
    void onSetFreqStopRecButtonClicked(VfxObject* sender, VfxId btn);
    void onButtonClicked(VfxObject *sender, VfxId id);

    VfxBool LPButtonAction(VfxId id, VfxPenEventTypeEnum type);
    void ButtonAction(VfxId id);
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    // Key event process function.
    // RETURNS: Return true if event has been processed, otherwise return false.
    VfxBool processKeyEvent(
        VfxKeyEvent &event,      // [in] Key event need to be processed.
        VfxBool is_from_avrcp    // [in] Indicate whether the key event is transfered from AVRCP cmd
    );

    void onEnterFreqSet(void);
    void onSetFreqPopUpButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum btn);
    void onAddToFavPopUpButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum btn);
    virtual void onExited(void);
    virtual void onEnter(VfxBool isBackward);
    virtual void onBack(void);

};


/***************************************************************************** 
 * Class VappFMRadioInfo
 *****************************************************************************/
class VappFMRadioInfo : public VfxControl
{
    friend class VappFMRadioMainPage;

public:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        LCD_BG_X = 10,
        LCD_BG_Y = 7,
        LCD_BG_WIDTH = 300,
        LCD_BG_HEIGHT = 70,
        BTN_PREV_X = 14,
        BTN_PREV_Y = 11,
        BTN_PREV_WIDTH = 30,
        BTN_PREV_HEIGHT = 62,
        BTN_NEXT_X = 280,
        BTN_NEXT_Y = 11,
        BTN_NEXT_WIDTH = BTN_PREV_WIDTH,
        BTN_NEXT_HEIGHT = BTN_PREV_HEIGHT,
        BTN_CHANNEL_X = 48,
        BTN_CHANNEL_Y = 7,
        BTN_CHANNEL_WIDTH = 224,
        BTN_CHANNEL_HEIGHT = 39,
        LINE_X = 49,
        LINE_Y = 46,
        LINE_WIDTH = 224, 
        LINE_HEIGHT = 1,
        RDS_FONT_SIZE = 14,
        RDS_X = 49,
        RDS_Y = 51,
        RDS_WIDTH = 220,
        RDS_HEIGHT = 22
#elif defined(__MMI_MAINLCD_480X800__)
        LCD_BG_X = 15,
        LCD_BG_Y = 16,
        LCD_BG_WIDTH = 451,
        LCD_BG_HEIGHT = 115,
        BTN_PREV_X = 15,
        BTN_PREV_Y = 16,
        BTN_PREV_WIDTH = 57,
        BTN_PREV_HEIGHT = 115,
        BTN_NEXT_X = 410,
        BTN_NEXT_Y = 16,
        BTN_NEXT_WIDTH = BTN_PREV_WIDTH,
        BTN_NEXT_HEIGHT = BTN_PREV_HEIGHT,
        BTN_CHANNEL_X = 72,
        BTN_CHANNEL_Y = 16,
        BTN_CHANNEL_WIDTH = 336,
        BTN_CHANNEL_HEIGHT = 64,
        LINE_X = 72,
        LINE_Y = 80,
        LINE_WIDTH = 337,
        LINE_HEIGHT = 2,
        RDS_FONT_SIZE = 21,
        RDS_X = 72,
        RDS_Y = 82,
        RDS_WIDTH = 337,
        RDS_HEIGHT = 49
#elif defined(__MMI_MAINLCD_240X400__)
        LCD_BG_X = 7,
        LCD_BG_Y = 5,
        LCD_BG_WIDTH = 227,
        LCD_BG_HEIGHT = 58,
        BTN_PREV_X = 7,
        BTN_PREV_Y = 5,
        BTN_PREV_WIDTH = 29,
        BTN_PREV_HEIGHT = 58,
        BTN_NEXT_X = 204,
        BTN_NEXT_Y = 5,
        BTN_NEXT_WIDTH = BTN_PREV_WIDTH,
        BTN_NEXT_HEIGHT = BTN_PREV_HEIGHT,
        BTN_CHANNEL_X = 36,
        BTN_CHANNEL_Y = 5,
        BTN_CHANNEL_WIDTH = 168,
        BTN_CHANNEL_HEIGHT = 32,
        LINE_X = 35,
        LINE_Y = 37,
        LINE_WIDTH = 168,
        LINE_HEIGHT = 1,
        RDS_FONT_SIZE = 13, //kno: color need to change ? 189 189 189
        RDS_X = 35,
        RDS_Y = 38,
        RDS_WIDTH = 168,
        RDS_HEIGHT = 25
#else//if defined(__MMI_MAINLCD_240X320__)
        LCD_BG_X = 7,
        LCD_BG_Y = 5,
        LCD_BG_WIDTH = 227,
        LCD_BG_HEIGHT = 58,
        BTN_PREV_X = 7,
        BTN_PREV_Y = 5,
        BTN_PREV_WIDTH = 29,
        BTN_PREV_HEIGHT = 58,
        BTN_NEXT_X = 204,
        BTN_NEXT_Y = 5,
        BTN_NEXT_WIDTH = BTN_PREV_WIDTH,
        BTN_NEXT_HEIGHT = BTN_PREV_HEIGHT,
        BTN_CHANNEL_X = 36,
        BTN_CHANNEL_Y = 5,
        BTN_CHANNEL_WIDTH = 168,
        BTN_CHANNEL_HEIGHT = 32,
        LINE_X = 35,
        LINE_Y = 37,
        LINE_WIDTH = 168,
        LINE_HEIGHT = 1,
        RDS_FONT_SIZE = 13, //kno: color need to change ? 189 189 189
        RDS_X = 35,
        RDS_Y = 38,
        RDS_WIDTH = 168,
        RDS_HEIGHT = 25
#endif
    };

    VappFMRadioChannelBox   *m_channelBox;

private:
#ifdef __FM_RADIO_RDS_SUPPORT__
    VcpMarquee   *m_infoString;
    VfxSignal1 <VfxWChar**> m_signalGetProgramName;
    VfxSignal1 <VfxWChar**> m_signalGetRadioText;
#endif

    VcpImageButton *m_btnPrev;
    VcpImageButton *m_btnNext;

public:
    VappFMRadioInfo();
    virtual void onInit(void);
    void setLight(VfxBool turn_on);
    void updateInfoString(void);

private:
    void drawInfo(void);

};


/***************************************************************************** 
 * Class VappFMRadioChannelBox
 *****************************************************************************/
class VappFMRadioChannelBox : public VfxControl
{
private:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        CHANNEL_X = 66,
        FAV_X = VappFMRadioInfo::BTN_CHANNEL_WIDTH/2,
        FAV_Y = 9,
        FAV_WIDTH = VappFMRadioInfo::BTN_CHANNEL_WIDTH,
        FAV_HEIGHT = VappFMRadioInfo::BTN_CHANNEL_WIDTH,
        CHANNEL_FONT_ZISE = 26
#elif defined(__MMI_MAINLCD_480X800__)
        CHANNEL_X = 100,
        FAV_X = VappFMRadioInfo::BTN_CHANNEL_WIDTH/2,
        FAV_Y = 15,
        FAV_WIDTH = VappFMRadioInfo::BTN_CHANNEL_WIDTH,
        FAV_HEIGHT = VappFMRadioInfo::BTN_CHANNEL_WIDTH,
        CHANNEL_FONT_ZISE = 39
#elif defined(__MMI_MAINLCD_240X400__)
        CHANNEL_X = 48,
        FAV_X = VappFMRadioInfo::BTN_CHANNEL_WIDTH/2,
        FAV_Y = 6,
        FAV_WIDTH = VappFMRadioInfo::BTN_CHANNEL_WIDTH,
        FAV_HEIGHT = VappFMRadioInfo::BTN_CHANNEL_WIDTH,
        CHANNEL_FONT_ZISE = 20
#else//if defined(__MMI_MAINLCD_240X320__)
        CHANNEL_X = 48,
        FAV_X = VappFMRadioInfo::BTN_CHANNEL_WIDTH/2,
        FAV_Y = 6,
        FAV_WIDTH = VappFMRadioInfo::BTN_CHANNEL_WIDTH,
        FAV_HEIGHT = VappFMRadioInfo::BTN_CHANNEL_WIDTH,
        CHANNEL_FONT_ZISE = 20
#endif
    };

public:
    VfxSignal0 m_signalBoxPressed;
    VfxSignal2 <VfxWChar**, VfxU16> m_signalGetFavName;
    VfxTextFrame   *m_favName;      // also used for seeking prompt

private:
    VfxTextFrame   *m_channel;
    VfxBool         m_enabled;

public:
    VappFMRadioChannelBox();
    virtual void onInit(void);
    void setLight(VfxBool turn_on);
    VfxBool setFreq(VfxU16 freq);
    virtual VfxBool onPenInput(VfxPenEvent & event);
    void showSeekingPrompt(VfxBool isShow);

};


/***************************************************************************** 
 * Class VappFMRadioSettingPage
 *****************************************************************************/
class VappFMRadioSettingPage : public VfxPage
{
    friend class VappFMRadioMainPage;

private:

    enum
    {
        STORAGE_L,
        QUALITY_L,
        RDS_S,
        AF_S,
        TP_S
    };
    
    VcpForm *m_form;
#ifdef __MMI_FM_RADIO_RECORD__    
    VcpFormItemLauncherCell *m_storage_launcher;
    VcpFormItemLauncherCell *m_quality_launcher;
#endif
#ifdef __FM_RADIO_RDS_SUPPORT__
    VcpFormItemSwitchCell *m_RDS_switch;
    VcpFormItemSwitchCell *m_AF_switch;
    VcpFormItemSwitchCell *m_TP_switch;
#endif
    VappFMRadioApp *m_app;

public:
    VappFMRadioSettingPage();
    virtual void onInit(void);

private:
    void drawSettingPage(void);
    virtual void onEnter(VfxBool isBackward);
    void onRecStateChanged(vadp_fm_radio_record_state_enum pre_state , vadp_fm_radio_record_state_enum cur_state);
    void onLauncher(VcpFormItemCell* sender, VfxId id);
    void onSwitchChanged(VcpFormItemSwitchCell* sender, VfxId id, VfxBool turn_on);

};


/***************************************************************************** 
 * Class VappFMRadioStorageSettingPage
 *****************************************************************************/
#ifndef __LOW_COST_SUPPORT_COMMON__

class VappFMRadioStorageSettingPage : public VfxPage, public IVcpListMenuContentProvider
{
private:
    VappFMRadioApp *m_app;
    VcpListMenu *m_storage_setting;


public:
    VappFMRadioStorageSettingPage();
    virtual void onInit(void);
    void onMemoryCardChanged(void);
	void onRecStateChanged(vadp_fm_radio_record_state_enum pre_state , vadp_fm_radio_record_state_enum cur_state);
    virtual void onItemTapped(VcpListMenu *menu, VfxU32 index);

    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
                 VfxU32 index,                    // [IN] the index of item
                 VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                 VfxWString &text,                // [OUT] the text resource
                 VcpListMenuTextColorEnum &color  // [OUT] the text color
                 );

    // Get the item count of the lis menu
    virtual VfxU32 getCount(void) const;

    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;   // [IN] index of the item

    // Get if the item is disabled
    virtual VfxBool getItemIsDisabled(VfxU32 index) const; // [IN] index of the item


};

#endif

/***************************************************************************** 
 * Class VappFMRadioQualitySettingPage
 *****************************************************************************/
class VappFMRadioQualitySettingPage : public VfxPage, public IVcpListMenuContentProvider
{
private:
    VappFMRadioApp *m_app;

public:
    VappFMRadioQualitySettingPage();
    virtual void onInit(void);
    virtual void onItemTapped(VcpListMenu *menu, VfxU32 index);

    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
                 VfxU32 index,                    // [IN] the index of item
                 VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                 VfxWString &text,                // [OUT] the text resource
                 VcpListMenuTextColorEnum &color  // [OUT] the text color
                 );

    // Get the item count of the lis menu
    virtual VfxU32 getCount(void) const;

    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;   // [IN] index of the item

    virtual VfxBool getItemIsDisabled(VfxU32 index) const;

};

#endif

#endif
