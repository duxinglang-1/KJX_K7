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
 *  Vapp_Setting_DateTimeSetting.h
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

#ifndef __VAPP_DATE_TIME_SETTING_H__
#define __VAPP_DATE_TIME_SETTING_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_setting_date_time_setting.h"
#include "mmi_rp_vapp_setting_def.h"
#include "vcp_date_picker.h"
#include "vcp_time_picker.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_DATE_TIME_PICKER_TOP_MARGIN (8)
#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_DATE_TIME_PICKER_TOP_MARGIN (14)
#else
#define VAPP_DATE_TIME_PICKER_TOP_MARGIN (5)
#endif 

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
static VfxId VappDateFormatString[] =
{
    STR_ID_VAPP_SETTING_FORMAT_DD_MM_YYYY,
    STR_ID_VAPP_SETTING_FORMAT_MM_DD_YYYY,
    STR_ID_VAPP_SETTING_FORMAT_YYYY_MM_DD
};

static VfxId VappDateSeperatorString[] = 
{
    STR_ID_VAPP_SETTING_SEPERATOR_DOT, 
    STR_ID_VAPP_SETTING_SEPERATOR_COLON, 
    STR_ID_VAPP_SETTING_SEPERATOR_SLOPE, 
    STR_ID_VAPP_SETTING_SEPERATOR_LINE        
};
/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappDateFormatSettingPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappDateFormatSettingPage);
    
    // Overrides
    public:
    virtual void onInit();
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxU32 getCount() const {return (sizeof(VappDateFormatString) / sizeof(VfxId));};
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const {return ((m_selectIdx == index) ? VCP_LIST_MENU_ITEM_STATE_SELECTED: VCP_LIST_MENU_ITEM_STATE_NONE);}

    // Methods
    public:
    void setSelectIndex(VfxU8 selectIdx) {m_selectIdx = selectIdx;};
    void onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx);

    // Variables
    public:
    VfxU8 m_selectIdx;
    VcpListMenu *m_listMenu;
    VfxSignal1 <VfxU8> m_updateFormat;
};

class VappDateSeperatorSettingPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappDateSeperatorSettingPage);
    // Overrides
    public:
    virtual void onInit();
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxU32 getCount() const {return (sizeof(VappDateSeperatorString) / sizeof(VfxId));};
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const {return ((m_selectIdx == index) ? VCP_LIST_MENU_ITEM_STATE_SELECTED: VCP_LIST_MENU_ITEM_STATE_NONE);}

    // Methods
    public:
    void setSelectIndex(VfxU8 selectIdx) {m_selectIdx = selectIdx;};
    void setDateFormat(VfxU8 dateFormat) {m_dateFormat = dateFormat;};
    void onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx);
    void setDate(const VcpDatePickerStruct &date) {m_date = date;};
    // Variables
    VfxU8 m_selectIdx;
    VfxU8 m_dateFormat;
    VcpDatePickerStruct m_date;
    VcpListMenu *m_listMenu;
    VfxSignal1 <VfxU8> m_updateSeperator;
};


/***************************************************************************** 
 * VappTimeSettingCell
 *****************************************************************************/
class VappTimeSettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappTimeSettingPage);
    // Overrides
    public:
    virtual void onInit();

    // Method
    public:
    void onToolBarTap(VfxObject* sender, VfxId senderId);
    void onTimeFormatTap(VcpFormItemSwitchCell* sender, VfxId senderId, VfxBool value);
    void onDayLightSavingTap(VcpFormItemSwitchCell* sender, VfxId senderId, VfxBool value);
    void updateTime(VfxObject *sender, VcpTimePickerStruct *time);
    void onTimeUpdate(VfxBool result);
    static void onTimeUpdateRsp(MMI_BOOL result, void *userData);
    // variables
    public:
    VfxSignal0 m_signalUpdate;
    
    private:
    VcpFormItemSwitchCell *m_timeFormatCell;
    VcpFormItemSwitchCell *m_dayLightSavingCell;
    VcpTimePicker *m_timePicker;    
    VcpForm *m_form;
    VcpTitleBar *m_titleBar;
    VcpToolBar *m_toolBar;
    VfxBool m_is24HourFormat;
    VfxBool m_dayLightSaving;    
    VcpTimePickerStruct m_time;
};    
#endif /* __VAPP_DATE_TIME_SETTING_H__ */
 
