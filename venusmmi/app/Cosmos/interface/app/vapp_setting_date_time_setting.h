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
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SETTING_DATE_TIME_SETTING_H__
#define __VAPP_SETTING_DATE_TIME_SETTING_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_date_picker.h"
#include "vcp_time_picker.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappHomeCitySettingCell : public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappHomeCitySettingCell);

    // Overrides
    public:
    virtual void onInit();

    // Methods
    public:
    VfxWString getHint();
    void onTap(VcpFormItemCell* sender, VfxId senderId);
    void updateCell();
    static mmi_ret cuiProc(mmi_event_struct *evt);
};

class VappDateSettingCell : public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappDateSettingCell);

    // Overrides
    public:
    virtual void onInit();

    // Methods
    public:
    VfxWString getHint();
    void onTap(VcpFormItemCell* sender, VfxId senderId);
    void updateCell();
    void onDateUpdate(VfxU32 flag);
};

class VappTimeSettingCell : public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappTimeSettingCell);

    // Overrides
    public:
    virtual void onInit();

    // Methods
    public:
    void onTap(VcpFormItemCell* sender, VfxId senderId);
    VfxWString getHint();
    void updateCell();
    void onTimeUpdate(VfxU32 flag);
};

class VappDateSettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappDateSettingPage);
    // Overrides
    public:
    virtual void onInit();

    // Method
    public:
    void UpdateDateFormat(VfxU8 dateFormat);
    void UpdateDateSeperator(VfxU8 dateSeperator);
    void updateDate(VfxObject* sender, VcpDatePickerStruct *date);
    void onToolBarTap(VfxObject* sender, VfxId senderId);
    void onDateUpdate(VfxBool result);
    static void onDateUpdateRsp(MMI_BOOL result, void *userData);
    private:
    void onEntryDateFormat(VcpFormItemCell* sender, VfxId senderId);
    void onEntryDateSeperator(VcpFormItemCell* sender, VfxId senderId);    
    // variables
    private:
    VcpFormItemLauncherCell *m_dateFormatCell;
    VcpFormItemLauncherCell *m_dateSeperatorCell;
    VcpForm *m_form;
    VcpTitleBar *m_titleBar;
    VcpToolBar *m_toolBar;
    VcpDatePicker *m_datePicker;
    VfxU8 m_selectFormat;
    VfxU8 m_selectSeperator;    
    VcpDatePickerStruct m_date;
    public:
    VfxSignal0 m_signalUpdateCell;
};
#endif /* __VAPP_SETTING_DATE_TIME_SETTING_H__ */
 
