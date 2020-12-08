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
 *  Vapp_Setting_SchedulePowerOnOff.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SCHEDULE_POWER_SETTING_H__
#define __VAPP_SCHEDULE_POWER_SETTING_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_setting_schedule_power_on_off.h"
#include "vcp_time_picker.h"
extern "C"
{
#include "ScheduledPowerOnOffGprot.h"
#include "custom_mmi_default_value.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SCHEDULE_ON_RECORD_NUM (2)
#define VAPP_SCHEDULE_OFF_RECORD_NUM (2)
#define VAPP_SCHEDULE_TOTAL_RECORD_NUM (VAPP_SCHEDULE_ON_RECORD_NUM + VAPP_SCHEDULE_OFF_RECORD_NUM)

#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_SPOF_TIME_PICKER_TOP_MARGIN (8)
#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_SPOF_TIME_PICKER_TOP_MARGIN (14)
#else
#define VAPP_SPOF_TIME_PICKER_TOP_MARGIN (5)
#endif 
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    VAPP_SPOF_DISABLE,
    VAPP_SPOF_ENABLE    
} VappSchedulePowerStatusEnum;

typedef enum
{
    VAPP_SPOF_POWERON,
    VAPP_SPOF_POWEROFF    
} VappSchedulePowerTypeEnum;

typedef enum
{
    VAPP_SPOF_SCHEDULE_NO_ERROR,
    VAPP_SPOF_SCHEDULE_ERROR_CONFLICT,
        
    VAPP_SPOF_SCHEDULE_ERROR_END
}VappSchedulePowerErrorEnum;
/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappSchedulePowerController : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappSchedulePowerController);
    // Methods
    public:
    VappSchedulePowerController() : m_isInit(VFX_FALSE) {initSchedulePower();};
    void initSchedulePower();
    VappSchedulePowerErrorEnum setSchedule(VfxId index, const spof_nvram_struct &data);
    spof_nvram_struct getSchedule(VfxId index);
    void scheduleExpired(VfxU8 index, VfxBool powerOff);
    void updateNextTime(VfxU8 index, VfxBool pwrOn);
    void scheduleReinit();
    void scheduleDeinit();
    void showSchedulePowerOffPopup();
    static void schedulePowerOffAutoShutDown();
    static MMI_BOOL onNmgrNotified(mmi_scenario_id scenarioId, void *userData);
    static void onSchedulePowerOffPopupTapped(VfxId id, void* userData);
    static mmi_ret onCallEnd(mmi_event_struct *evt);
    // Variables
    private:
    spof_nvram_struct m_data[NUM_OF_SPOF];
    VfxBool m_isInit;
};


class VappSchedulePowerStatusSettingCell : public VcpFormItemSwitchCell
{
    VFX_DECLARE_CLASS(VappSchedulePowerStatusSettingCell);

    // Methods
    public:    
    void setSchedulePowerRecordId(VfxU8 recordId) ;
    void onSwitch(VcpFormItemSwitchCell* sender, VfxId senderId, VfxBool status);
    void updateStatus();
    
    // Variables
    private:
    VfxU8 m_recordId;
    VfxBool m_status;
};

class VappSchedulePowerTimeSettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappSchedulePowerTimeSettingPage);    

    // Overrides
    public:
    virtual void onInit();
    
    // Methods:
    public:
    VappSchedulePowerTimeSettingPage()
    {
            m_time.hour = 0; 
            m_time.minute = 0;
            m_type = VAPP_SPOF_POWERON;
    };
    VappSchedulePowerTimeSettingPage(VappSchedulePowerTypeEnum type, VfxU8 hour, VfxU8 minute) 
    {
        m_time.hour = hour; 
        m_time.minute = minute;
        m_type = type;
    };
    void onToolBarTap(VfxObject* sender, VfxId senderId);
    void updateTime(VfxObject *sender, VcpTimePickerStruct *time);
    // Variables
    public:
    VfxSignal2 <VfxU8, VfxU8> m_signalUpdateTime; // hour, minute
    
    private:
    VcpToolBar *m_toolBar;
    VcpTimePicker *m_timePicker;
    VcpTimePickerStruct m_time;
    VappSchedulePowerTypeEnum m_type;
};

class VappSchedulePowerTimeSettingCell : public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappSchedulePowerTimeSettingCell);

    // Methods
    public:
    void setSchedulePowerRecordId(VfxU8 recordId);
    void onEntryTimeSetting(VcpFormItemCell *sender, VfxId senderId);
    void updateTime();
    void setTime(VfxU8 hour, VfxU8 minute);
    // Variables
    private:
    VfxU8 m_recordId;
    VappSchedulePowerTimeSettingPage *m_settingPage;
};

class VappSchedulePowerSettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappSchedulePowerSettingPage);
    // Overrides
    public:
    virtual void onInit();

    // Methods

    // Variables
    public:
    VfxSignal0   m_signalUpdateCell;

    private:
    VcpForm *m_form;
    VcpTitleBar *m_titleBar;
    VcpToolBar  *m_toolBar;
    VappSchedulePowerStatusSettingCell *m_schedulePowerOnStatusCell[VAPP_SCHEDULE_ON_RECORD_NUM];
    VappSchedulePowerStatusSettingCell *m_schedulePowerOffStatusCell[VAPP_SCHEDULE_OFF_RECORD_NUM];
    VappSchedulePowerTimeSettingCell   *m_schedulePowerOnTimeCell[VAPP_SCHEDULE_ON_RECORD_NUM];
    VappSchedulePowerTimeSettingCell   *m_schedulePowerOffTimeCell[VAPP_SCHEDULE_OFF_RECORD_NUM];    
};
#endif /* __VAPP_SCHEDULE_POWER_SETTING_H__ */
 
