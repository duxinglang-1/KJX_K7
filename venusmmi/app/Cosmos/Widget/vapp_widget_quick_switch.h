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
 *  vapp_widget_quick_switch.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the quick switch widget.
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
 * removed!
 *
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

#ifndef VAPP_WIDGET_QUICK_SWITCH_H
#define VAPP_WIDGET_QUICK_SWITCH_H

#include "MMI_features.h"

#if defined (__MMI_VUI_WIDGET_QUICK_SWITCH__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"

/* Pluto MMI headers */
extern "C"
{
#include "tetheringSrvgprot.h"  //check tethering
}


/*****************************************************************************
 * Quick Switch Widget
 *****************************************************************************/

class VappWidgetQuickSwitch : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetQuickSwitch);

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetQuickSwitch();

    static mmi_ret wlanEvtHandle(
        mmi_event_struct* param
    );
    static void responseInitEvent(
        mmi_event_struct* param
    );
    static void responseDeinitEvent(
        mmi_event_struct* param
    );

    static mmi_ret onProc(
        mmi_event_struct *evt
    );

    static void btEvtHdlr(
        U32 event,
        void* para
    );

    static mmi_ret flightEvtHdlr(
        mmi_event_struct *event
    );

    static void afterStopTethering(
        srv_tethering_type_enum tethering_type, 
        MMI_BOOL result, 
        void *user_data
    );    

// Override
public:
    virtual VappWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(
        VfxWChar *string,
        VfxS32 size
    ) const;

    virtual VfxFrame *createIcon(
        VfxObject *parentObj
    );

    virtual void onCreateView();

    virtual void onReleaseView();

    virtual void onSerializeView(
        VfxArchive *ar
    );

    virtual void onRestoreView(
        VfxArchive *ar
    );

    virtual VfxPoint onGetEditButtonOffset();

private:

    // Register events of callback manager.
    void registerEvent();

    // Deregister events of callback manager.
    void deregisterEvent();
    
    void onWifiBtnClicked(
        VfxObject *sender,
        VfxId id
    );

    void onBtBtnClicked(
        VfxObject *sender,
        VfxId id
    );

    void onSilentBtnClicked(
        VfxObject *sender,
        VfxId id
    );

    void onFlightBtnClicked(
        VfxObject *sender,
        VfxId id
    );

    void onBrightnessBtnClicked(
        VfxObject *sender,
        VfxId id
    );

    void onConfirmClicked(VfxObject* sender, VfxU32 id);    

    // Backlight indicator initialization as well as acquire current status
    void getCurrentLightLevel();

    VfxPoint getSeparatorPos(
        const VfxSize &size,
        VfxS32 idx
    ) const;

    void updateStatus();

    void showConfirmScreen(void);

    void initialUI(void);
    
    void releaseUI(void);

    // show loading indicator when decode photo
    void showLoading(VcpActivityIndicator *ind);
    
    // replace loading indicator with decoded photo
    void hideLoading(VcpActivityIndicator *ind);

// Variable
public:

    VcpActivityIndicator *m_btIndicator;
    VcpActivityIndicator *m_fightModeIndicator;

    //Set as public since quick switch is default widget in home scren in CMCC project.
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        MAX_SIZE_WIDTH = 480,
        MAX_SIZE_HEIGHT = 120,
    #elif defined(__MMI_MAINLCD_320X480__)
        MAX_SIZE_WIDTH = 320,
        MAX_SIZE_HEIGHT = 84,
    #elif defined(__MMI_MAINLCD_240X400__)
        MAX_SIZE_WIDTH = 240,
        MAX_SIZE_HEIGHT = 71,
    #else /* defined(__MMI_MAINLCD_240X320__) */
        MAX_SIZE_WIDTH = 240,
        MAX_SIZE_HEIGHT = 70,
    #endif

        SHORTCUT_NUM = 5,
        SEPARATOR_NUM = SHORTCUT_NUM - 1
    };

private:
    VfxU8 m_lastLevel;
    VfxU8 m_level0;
    VfxU8 m_minLevel;
    VfxU8 m_midLevel;
    VfxU8 m_currentLevel;
    VfxU8 m_maxLevel;
    VfxImageFrame *m_bgImg;
    VcpConfirmPopup* m_confirmPopup;

    VfxImageFrame *m_indicatorWifi;
    VfxImageFrame *m_indicatorBt;
    VfxImageFrame *m_indicatorSilent;
    VfxImageFrame *m_indicatorFlight;
    VfxImageFrame *m_indicatorMin;
    VfxImageFrame *m_indicatorMid;
    VfxImageFrame *m_indicatorMax;

    VcpImageButton *m_buttonWifi;
    VcpImageButton *m_buttonBt;
    VcpImageButton *m_buttonSilent;
    VcpImageButton *m_buttonFlight;
    VcpImageButton *m_buttonBrightness;

    VfxS32 m_btSrvHandle;
    VfxBool m_wifiBtnStatus;
    VfxBool m_flightBtnStatus;    
    VfxU32 m_confirmFlag;

    typedef enum
    {
        VAPP_BT_POWER_ON_CONFIRM = 1,
        VAPP_BT_POWER_OFF_CONFIRM,
        VAPP_BT_POWER_ENUM_TOTAL,
        VAPP_TETHERING_ON_CONFIRM,
        VAPP_TETHERING_OFF_CONFIRM,
        VAPP_WIFI_ON_CONFIRM
    } vapp_confirm_pop_up_type_enum;

    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)//WVGA
        BTN_BOUNDS_X =45,
        BTN_BOUNDS_Y=45,
        SEPARATOR_BOUNDS_X=2,
        SEPARATOR_BOUNDS_Y=93,
        SEPARATOR_OFFSET_Y = 5,
        BG_WIDTH =460,
        BG_HEIGHT =107,
        BG_X =10,
        BG_Y =0,
        SHADOW = 6,

        BTN_WIFI_X =29,
        BTN_BT_X = 118,
        BTN_SILENT_X= 208,
        BTN_FLIGHT_X= 299,
        BTN_BRIGHTNESS_X=388,

        INDICATOR_WIFI_X=35,
        INDICATOR_BT_X=125,
        INDICATOR_SILENT_X=215,
        INDICATOR_FLIGHT_X=305,
        INDICATOR_MIN_X=373,
        INDICATOR_MID_X=394,
        INDICATOR_MAX_X=416,

        INDICATOR_Y = 18,
        BTN_Y=35,
        EFFECT_W =85,
        EFFECT_H =85,
        EDIT_BTN_OFFSET_X = 30,
        EDIT_BTN_OFFSET_Y = 16
        
    #elif defined(__MMI_MAINLCD_320X480__)//HVGA
        BTN_BOUNDS_X = 32,
        BTN_BOUNDS_Y = 32,
        SEPARATOR_BOUNDS_X = 2,
        SEPARATOR_BOUNDS_Y = 61,
        SEPARATOR_OFFSET_Y = 6,
        BG_WIDTH = 295,
        BG_HEIGHT = 70,
        BG_X = 13,
        BG_Y = 0,
        SHADOW = 4,

        BTN_WIFI_X = 18,
        BTN_BT_X = 74,
        BTN_SILENT_X = 133,
        BTN_FLIGHT_X = 189,
        BTN_BRIGHTNESS_X = 246,

        INDICATOR_WIFI_X = 22,
        INDICATOR_BT_X = 79,
        INDICATOR_SILENT_X = 137,
        INDICATOR_FLIGHT_X = 194,
        INDICATOR_MIN_X = 239,
        INDICATOR_MID_X = 251,
        INDICATOR_MAX_X = 263,

        INDICATOR_Y = 9,
        BTN_Y=21,
        EFFECT_W =65,
        EFFECT_H =65,
        EDIT_BTN_OFFSET_X = 15,
        EDIT_BTN_OFFSET_Y = 3
        
    #elif defined(__MMI_MAINLCD_240X400__)//WQVGA
        BTN_BOUNDS_X =25,
        BTN_BOUNDS_Y=25,
        SEPARATOR_BOUNDS_X=2,
        SEPARATOR_BOUNDS_Y=47,
        SEPARATOR_OFFSET_Y = 5,
        BG_WIDTH =228,
        BG_HEIGHT =53,
        BG_X =6,
        BG_Y =0,
        SHADOW =3,

        BTN_WIFI_X = 13,
        BTN_BT_X = 57,
        BTN_SILENT_X = 102,
        BTN_FLIGHT_X = 147,
        BTN_BRIGHTNESS_X = 190,

        INDICATOR_WIFI_X = 16,
        INDICATOR_BT_X = 60,
        INDICATOR_SILENT_X = 105,
        INDICATOR_FLIGHT_X = 149,
        INDICATOR_MIN_X = 183,
        INDICATOR_MID_X = 193,
        INDICATOR_MAX_X = 203,

        INDICATOR_Y = 9,
        BTN_Y=16,
        EFFECT_W =55,
        EFFECT_H =55,
        EDIT_BTN_OFFSET_X = 28,
        EDIT_BTN_OFFSET_Y = 5
        
    #else //QVGA
        BTN_BOUNDS_X =25,
        BTN_BOUNDS_Y=25,
        SEPARATOR_BOUNDS_X=2,
        SEPARATOR_BOUNDS_Y=47,
        SEPARATOR_OFFSET_Y = 5,
        BG_WIDTH =228,
        BG_HEIGHT =53,
        BG_X =6,
        BG_Y =0,
        SHADOW =3,

        BTN_WIFI_X = 13,
        BTN_BT_X = 57,
        BTN_SILENT_X = 102,
        BTN_FLIGHT_X = 147,
        BTN_BRIGHTNESS_X = 190,

        INDICATOR_WIFI_X = 16,
        INDICATOR_BT_X = 60,
        INDICATOR_SILENT_X = 105,
        INDICATOR_FLIGHT_X = 149,
        INDICATOR_MIN_X = 183,
        INDICATOR_MID_X = 193,
        INDICATOR_MAX_X = 203,

        INDICATOR_Y = 9,
        BTN_Y=16,
        EFFECT_W =55,
        EFFECT_H =55,
        EDIT_BTN_OFFSET_X = 15,
        EDIT_BTN_OFFSET_Y = 8
    #endif
    };
};

#endif  /* defined(__MMI_VUI_WIDGET_QUICK_SWITCH__) */
#endif /* VAPP_WIDGET_QUICK_SWITCH_H */
