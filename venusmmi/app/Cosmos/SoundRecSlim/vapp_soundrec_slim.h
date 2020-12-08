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
 *  vapp_soundrecorder_slim.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  Sound recorder header file
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
 *
 * removed!
 * removed!
 *
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

#ifndef __VAPP_SOUNDRECORDER_SLIM_H__
#define __VAPP_SOUNDRECORDER_SLIM_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
    
#ifdef __MMI_SOUNDREC_SLIM__

//#undef __COSMOS_NO_USER_DRIVE__

// for supporting phone drive
#ifndef __COSMOS_NO_USER_DRIVE__
#ifndef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__
#define __MMI_SOUNDREC_SLIM_PHONE_DRIVE__
#endif
#endif

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_menu_popup.h"


/* Pluto MMI headers */
#ifdef __cplusplus
extern "C"
{
#endif
#include "mdi_datatype.h"
#include "FileMgrSrvGProt.h"
#include "custom_mmi_folders_config.h"
#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SNDREC_FOLDER_LEN ((sizeof(RECORD_DOWNLOAD_FOLDER_NAME)/2) + 3)   /* "C:\Record\" not include null terminator */
//#define VAPP_SNDREC_FOLDER L"\\Record\\"

/* "Recording_1000.amr" not include null terminator */
#define VAPP_SNDREC_FILENAME_LEN (SRV_FMGR_PATH_MAX_LEN - VAPP_SNDREC_FOLDER_LEN)
//#define VAPP_SNDREC_FILENAME_LEN 18 /* "Recording_1000.amr" not include null terminator */
//#define VAPP_SNDREC_FILENAME_PREFIX L"Recording_"

#define VAPP_SNDREC_FILEPATH_LEN (VAPP_SNDREC_FOLDER_LEN + VAPP_SNDREC_FILENAME_LEN)

#define VAPP_SNDREC_MAX_SEQUENCE 999 /* Max file sequence */
#define VAPP_SNDREC_FIND_SEQ_RANGE 20 /* Number of file names check at one function call */

#define MAIN_PAGE_BG_COLOR                  (VfxColor(255,30,30,30))

/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/
class VappSoundRecorderApp;
class VappSoundRecorderScreen;
class VappSoundRecorderRecordPage;


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
    int ret;
    VfxU64 disk_size;
}vapp_soundrec_check_size_result;
 

/***************************************************************************** 
 * Class VappSoundRecorderApp
 *****************************************************************************/
class VappSoundRecorderApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappSoundRecorderApp);

public:
    /* Override */
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onInit();
    virtual void onDeinit();

    static mmi_ret eventHandler(mmi_event_struct *param); 

private:
    VappSoundRecorderScreen *scr;
};


/***************************************************************************** 
 * Class VappSoundRecorderScreen
 *****************************************************************************/
class VappSoundRecorderScreen : public VfxMainScr
{
// Override
public:
    virtual void on1stReady();
    void notifyTopPage(mmi_event_struct *evt);
};


/***************************************************************************** 
 * Class VappSoundRecorderRecordPage
 *****************************************************************************/
class VappSoundRecorderRecordPage : public VfxPage
{
public:
    enum UIConstantsEnum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        TEXT_RECORD_FILE_NAME_X = LCD_WIDTH/2,
        TEXT_RECORD_FILE_NAME_Y = 67,
        TEXT_RECORD_FILE_NAME_WIDTH = LCD_WIDTH,
        TEXT_RECORD_FILE_NAME_HEIGHT = 20,
        TEXT_RECORD_FILE_NAME_FONT_SIZE = 18,
        TEXT_REMAIN_TIME_X = LCD_WIDTH/2,
        TEXT_REMAIN_TIME_Y = 199,
        TEXT_REMAIN_TIME_WIDTH = LCD_WIDTH,
        TEXT_REMAIN_TIME_HEIGHT = 20,
        TEXT_REMAIN_TIME_FONT_SIZE = 18,
        TEXT_RECORD_TIME_X = 35,
        TEXT_RECORD_TIME_Y = 130,
        TEXT_RECORD_TIME_WIDTH = 250,
        TEXT_RECORD_TIME_HEIGHT = 69,
        TEXT_RECORD_TIME_FONT_SIZE = 65,
        BTN_RECORD_X = 64,
        BTN_RECORD_Y = 337,
        BTN_RECORD_WIDTH = 53,
        BTN_RECORD_HEIGHT = 54,
        POPUP_Y = 230
    #elif defined(__MMI_MAINLCD_240X320__)
        TEXT_RECORD_FILE_NAME_X = LCD_WIDTH/2,
        TEXT_RECORD_FILE_NAME_Y = 29,
        TEXT_RECORD_FILE_NAME_WIDTH = LCD_WIDTH,
        TEXT_RECORD_FILE_NAME_HEIGHT = 17,
        TEXT_RECORD_FILE_NAME_FONT_SIZE = 14,
        TEXT_REMAIN_TIME_X = LCD_WIDTH/2,
        TEXT_REMAIN_TIME_Y = 123,
        TEXT_REMAIN_TIME_WIDTH = LCD_WIDTH,
        TEXT_REMAIN_TIME_HEIGHT = 17,
        TEXT_REMAIN_TIME_FONT_SIZE = 14,
        TEXT_RECORD_TIME_X = 26,
        TEXT_RECORD_TIME_Y = 74,
        TEXT_RECORD_TIME_WIDTH = 200,
        TEXT_RECORD_TIME_HEIGHT = 56,
        TEXT_RECORD_TIME_FONT_SIZE = 48,
        BTN_RECORD_X = 55,
        BTN_RECORD_Y = 211,
        BTN_RECORD_WIDTH = 41,
        BTN_RECORD_HEIGHT = 41,
        POPUP_Y = 152
    #else // defined(__MMI_MAINLCD_240X400__)
        TEXT_RECORD_FILE_NAME_X = LCD_WIDTH/2,
        TEXT_RECORD_FILE_NAME_Y = 60,
        TEXT_RECORD_FILE_NAME_WIDTH = LCD_WIDTH,
        TEXT_RECORD_FILE_NAME_HEIGHT = 17,
        TEXT_RECORD_FILE_NAME_FONT_SIZE = 14,
        TEXT_REMAIN_TIME_X = LCD_WIDTH/2,
        TEXT_REMAIN_TIME_Y = 154,
        TEXT_REMAIN_TIME_WIDTH = LCD_WIDTH,
        TEXT_REMAIN_TIME_HEIGHT = 17,
        TEXT_REMAIN_TIME_FONT_SIZE = 14,
        TEXT_RECORD_TIME_X = 26,
        TEXT_RECORD_TIME_Y = 105,
        TEXT_RECORD_TIME_WIDTH = 200,
        TEXT_RECORD_TIME_HEIGHT = 56,
        TEXT_RECORD_TIME_FONT_SIZE = 48,
        BTN_RECORD_X = 55,
        BTN_RECORD_Y = 270,
        BTN_RECORD_WIDTH = 41,
        BTN_RECORD_HEIGHT = 41,
        POPUP_Y = 174        
    #endif
    };

public:
    VappSoundRecorderRecordPage();
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);    
    virtual void onExit(VfxBool isBackward);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    void recordCallbackHdlr(mdi_result result);
    void recordErrorHdlr(mdi_result result);
    void onCpopupButtonClicked(VfxObject* sender, VfxId btn);

    static mmi_ret eventHandler(mmi_event_struct *param);

private:
    enum SoundrRecStateEnum
    {
        SNDREC_STATE_IDLE,
        SNDREC_STATE_RECORD,
        SNDREC_STATE_PAUSE,
        SNDREC_STATE_INTERRUPTED,
        SNDREC_STATE_TOTAL
    };

    enum SoundrRecBtnEnum
    {
        SNDREC_BTN_REC,
        SNDREC_BTN_STOP,

        // tool bar buttons
        SNDREC_BTN_TOOL_BAR_REC_LIST,
    #ifdef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__
        SNDREC_BTN_TOOL_BAR_STORAGE,
    #endif

        SNDREC_BTN_TOTAL
    };

#ifdef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__
    enum SoundrRecStorageEnum
    {
        SNDREC_STORAGE_PHONE,
        SNDREC_STORAGE_MEMORY_CARD,

        SNDREC_STORAGE_TOTAL
    };
#endif

    enum
    {
    #ifdef __MTK_TARGET__
        TIMER_UPDATE_CURRENT_TIME = 250,
    #else
        TIMER_UPDATE_CURRENT_TIME = 1000,
    #endif
        TIMER_CHECK_REMAIN_TIME = 1000,
        TIMER_FIND_NAME = 200
    };

    /* Private functions */
    void onButtonClicked(VfxObject* obj, VfxId id);
    void onUpdateTimerExpir(VfxTimer *timer);
    void onCheckRemainTimerExpir(VfxTimer *timer);
    void onErrorCheckTimerExpir(VfxTimer *timer);
    void onFindPathTimerExpir(VfxTimer *timer);
    void createScreenComponent(void);
    VfxU64 updateRemainTimeText(VfxBool forceUpdate);
    VfxU64 updateFreeSpaceTimeText(VfxBool forceUpdate);
    VfxU64 updateLimitTimeText(VfxBool forceUpdate);
    void updateRecButtonState(VfxBool is_pause);
    void updateTimeText(VfxTextFrame *text, VfxU64 display_time);
    VfxBool checkRecordPath(void);
    VfxBool findRecordPath(void);
    VfxBool findRecordPathLoop(void);
    void recordStart(void);
    void recordPause(void);
    void recordResume(void);
    void recordStop(VfxBool is_finish);

    void stopRecordAndExit(VfxBool user_stop);

    void showConfirmPopup(const VfxWString &text);

    void showLoading(void);
    void stopLoading(void);

#ifdef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__
    void setStorageType(SoundrRecStorageEnum storageType);   
    void selectStoragePopup(void);  
    void onStorageSelected(VfxObject* sender, VfxId id);
    void showDefaultStoragePopup(void);
    void onDefaultStorageConfirm(VfxObject* vfx_obj, VfxId id);
#endif
   
private:
    /* Private screen components */
    VcpToolBar *m_toolbar;

    SoundrRecBtnEnum m_btnPressed;
    VcpButton *m_image_btn_rec;
    VcpButton *m_image_btn_stop;

    VfxTextFrame *m_text_record_file_name;
    VfxTextFrame *m_text_record_time;
    VfxTextFrame *m_text_remain_time;

    VcpConfirmPopup *m_confirmPopup;

    VfxColor m_text_remain_time_color;

    VfxTimer *m_timer_update;
    VfxTimer *m_timer_check_remain;
    VfxTimer *m_timer_error_check;
    VfxTimer *m_timer_find_name;

    VcpActivityIndicator *m_indicator; 
    /* Private variables */
    VfxU8 m_mode;
    VfxU8 m_state;
    VfxU16 m_stop_seq;
    VfxU16 m_last_seq;
    VfxU64 m_current_time;
    VfxU64 m_accumulate_time; /* To keep total time for interrupt case */
    VfxU64 m_check_remain_timer_dur;
    VfxU64 m_last_update_remain_time;
    
    VfxWChar m_record_path[VAPP_SNDREC_FILEPATH_LEN + 1];

#ifdef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__    
    SoundrRecStorageEnum m_storageType;
    VcpSelectPopup  *m_selectStoragePopup;
#endif    
};

#endif // __MMI_SOUNDREC_SLIM__
#endif // __VAPP_SOUNDRECORDER_SLIM_H__

