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
 *  vapp_usb_usbmode.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_USB_USBMODE_H__
#define __VAPP_USB_USBMODE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
#include "GeneralSettingSrvGprot.h"
}
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "Vapp_usb_baticon.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __USB_MMI_DEBUG__

#ifndef __MTK_TARGET__
#ifndef __MMI_USB_SUPPORT__
#define __MMI_USB_SUPPORT__
#endif
#endif
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    CHARGING_STATE_NONE = 0,
    CHARGING_STATE_CHARGING,
    CHARGING_STATE_ERROR,
    CHARGING_STATE_COMPLETED,
    CHARGING_STATE_MAX
} charging_state_enum;

typedef enum
{
    TIME_TYPE_NONE = 0,
    TIME_TYPE_AM,
    TIME_TYPE_PM,
    TIME_TYPE_MAX
} time_type_enum;

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappUSBModePage : public VfxPage
{
    
// Override
public:
    virtual void onInit();

public:
    VappUSBModePage()
    {
       #ifndef __MMI_USB_SLIM__
        m_textFrame = NULL;
        m_timeFrame = NULL;
        m_timeTypeFrame = NULL;
       #endif
        m_imageFrame = NULL;
        m_chargingState = CHARGING_STATE_NONE;
        m_level = 0;
        m_hour = 0;
        m_min = 0;
        m_timeType = TIME_TYPE_AM;
    }
    
    void updateCharging(charging_state_enum state, VfxU8 level);
    #ifndef __MMI_USB_SLIM__
    void updateTime(VfxU8 hour, VfxU8 min, time_type_enum type);
    #endif

protected:
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    
private:
    void setTexts(void);
    void setImage(void);
    void setTime(void);
    void setTimeType(void);
    #ifndef __MMI_USB_SLIM__
    void setChargingText(void);
    #endif
    void setChargingIcon(void);
public:
    VfxSignal0 m_closeSignal;
    
private:
    #ifndef __MMI_USB_SLIM__
    VfxTextFrame    *m_textFrame;
    VfxTextFrame    *m_timeFrame;
    VfxTextFrame    *m_timeTypeFrame;
    #endif
    VappUSBBatIcon   *m_imageFrame;
    charging_state_enum m_chargingState;
    VfxU8           m_level;
    VfxU8           m_hour;
    VfxU8           m_min;
    time_type_enum  m_timeType;
};

class VappUSBModeScrn : public VfxMainScr
{

// Override
public:
    virtual void on1stReady();
    virtual void onDeinit();
    
public:
    VappUSBModeScrn()
    {
        m_page = NULL;
        m_alert = NULL;
        m_chargingState = CHARGING_STATE_NONE;
        m_chargingLevel = 0;
        m_hour = 0;
        m_min = 0;
        m_timeFormat = srv_setting_get_time_format();
    }
    
public:
    #ifndef __MMI_USB_SLIM__
    void updateTime(void);
    void updateTime(VfxU8 hour, VfxU8 min);
    #endif
    void updateChargingState(charging_state_enum state, VfxU8 level);
    void showErrorPopup(void);
    
private:
    void setCharging(void);
    void setTime(void);
    void onAlertClicked(VfxObject* sender, VfxId id);
    #ifndef __MMI_USB_SLIM__
    void onTimeChanged(VfxU32 flag);
    #endif
    void onPageClose(void);
    
public:
    VfxSignal0 m_closeSingal;
    
/* */
private:
    VappUSBModePage  *m_page;
    VcpConfirmPopup *m_alert;
    charging_state_enum m_chargingState;
    VfxU8 m_chargingLevel;
    VfxU8 m_hour;
    VfxU8 m_min;
    srv_setting_time_format_enum m_timeFormat;
};

class VappUSBModeContext : public VfxObject
{

public:
    VappUSBModeContext()
    {
        m_chargingMode = CHARGING_STATE_NONE;
        m_usbModeScrn = NULL;
    }
    
   virtual ~VappUSBModeContext()
    {
        VappUSBModeContext::m_inst = NULL;
        m_usbModeScrn = NULL;
    }

private:
    

/* Static functions*/
public:
    static void initContext(void);
    #ifndef __MMI_USB_SLIM__
    static void clockTimeHdlr(void *p);
    #endif
    static void MSModeConfirm(void);
    static void MSModeConfirmCallback(VfxId id, void *userData);
    static void ShowMSMode(void);
    static MMI_BOOL ShowMSModeCallback(mmi_scenario_id scen_id, void *arg);
    void showScreen(void);
    void closeScreen(void);
    void updateChargingState(VfxU16 status, VfxU8 level);
    void updateChargingState(void);
    
private:
    static VappUSBModeContext* getInst(void);
    static VfxU8 getChargingLevel(void);
    #ifndef __MMI_USB_SLIM__
    void updateClock(VfxU8 h, VfxU8 m);
    #endif
    void onScrnClose();
    
public:
    VfxSignal0 m_closeSingal;
        
/* */
private:
    static VappUSBModeContext *m_inst;
    charging_state_enum m_chargingMode;
    VappUSBModeScrn *m_usbModeScrn;
};

#endif /* __VAPP_USB_USBMODE_H__*/
