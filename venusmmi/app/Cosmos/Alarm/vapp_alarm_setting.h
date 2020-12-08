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
 *  vapp_alarm_setting.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Alarm setting page
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_ALARM_SETTING_H__
#define __VAPP_ALARM_SETTING_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_page.h"

#include "vcp_list_menu.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappAlarmSnoozePage
 *****************************************************************************/
class VappAlarmSnoozePage : public VfxPage, public IVcpListMenuContentProvider
{
// Override
public:
	VappAlarmSnoozePage() : m_list(NULL), m_snooze(0){}
	VappAlarmSnoozePage(const VfxU8 &snooze) : m_list(NULL), m_snooze(snooze){}
	virtual ~VappAlarmSnoozePage(){};
	//void setValue(const VfxU8 &snooze);

	VfxSignal2<const VfxObject *, const VfxU8 &> m_signalSelected;
// Override
protected:
	void onInit(void);

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );


    virtual VfxU32 getCount() const {return ALARM_TOTAL_SNOOZE;};

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;
	
private:
	void onListItemTap(VcpListMenu *obj, VfxU32 index);

private:
	VcpListMenu *m_list;
	VfxU8		m_snooze;
};


/***************************************************************************** 
 * Class VappAlarmSettingPage
 *****************************************************************************/
class VappSetVolumePopup;
class VcpFormItemCell;
class VappAlarmSettingPage : public VfxPage
{
// Override
public:
	VappAlarmSettingPage();
	virtual ~VappAlarmSettingPage(){}
	void onInit(void);
	
	enum 
	{
		ID_FORM_CELL_LAUNCH_SNOOZE,
		ID_FORM_CELL_LAUNCH_VOLUME,
		ID_FORM_CELL_TOTAL
	};
	
protected:
	void onExit(VfxBool isBackward);
	
private:
	void onItemCellLaunch(VcpFormItemCell *obj, VfxId id);
	void onSnoozeSelect(const VfxObject *obj, const VfxU8 &days);
    void onVolClick(VfxU8 vol);

private:
	VcpForm *m_form;
	VfxU8 m_snooze;
	VfxU8 m_volume;
	VfxWeakPtr<VappSetVolumePopup> m_volWeakPtr;
};


#endif /* __VAPP_ALARM_SETTING_H__ */

