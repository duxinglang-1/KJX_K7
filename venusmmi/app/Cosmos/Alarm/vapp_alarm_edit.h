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
 *  vapp_alarm_edit.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Alarm edit page header file
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
#ifndef __VAPP_ALARM_EDIT_H__
#define __VAPP_ALARM_EDIT_H__
/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
	#include "AlarmSrvGprot.h"
}

#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_page.h"

#include "vcp_list_menu.h"
#include "vcp_form.h"

#include "vapp_alarm.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappAlarmRepeatPage
 *****************************************************************************/
class VfxWString;
class VappAlarmRepeatPage : public VfxPage, public IVcpListMenuContentProvider
{

// Override
public:
	VappAlarmRepeatPage();
	VappAlarmRepeatPage(const VfxU8 &days);
	virtual ~VappAlarmRepeatPage(){};

	//void setDays(const VfxU8 &days);

	VfxSignal2<VfxObject*, VfxU8> m_signalSelectDay;

// Override
protected:
	void onInit(void);
	
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxU32 getCount(void) const { return ALARM_TOTAL_WDAY;};

    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
	
private:
	void onListItemSelect(VcpListMenu *obj, VfxU32 index, VcpListMenuItemStateEnum newState);
	void onToolbarClick(VfxObject* obj, VfxId id);

private:
	VcpListMenuItemStateEnum m_stateLst[ALARM_TOTAL_WDAY];
	VcpListMenu *m_list;
	VfxU8		m_days;
	VfxBool m_bAll;
};


/***************************************************************************** 
 * Class VappAlarmFormItemSwitchCell
 *****************************************************************************/
class VfxPenEvent;
class VappAlarmFormItemSwitchCell : public VcpFormItemSwitchCell
{
	
public:
	VappAlarmFormItemSwitchCell(){};
	virtual ~VappAlarmFormItemSwitchCell(){};
	
protected:
	virtual void onCellTap(VfxPenEvent &event);
};

/***************************************************************************** 
 * Class VappAlarmEditPage
 *****************************************************************************/
class VcpFunctionBar;
class VappAlarmEditPage : public VfxPage
{

// Override
public:
	VappAlarmEditPage();
	VappAlarmEditPage(const VfxU8 &index);
	virtual ~VappAlarmEditPage(){};

	enum 
	{
		ID_FORM_CELL_CUSTOM_PICKER,
		ID_FORM_CELL_LAUNCH_REPEAT,
		ID_FORM_CELL_SWITCH_RING,
		ID_FORM_CELL_SWITCH_VIB,
		ID_FORM_CELL_SWITCH_SNOOZE,
		ID_FORM_CELL_TXT_LABEL,
		ID_FORM_CELL_TOTAL
	};

	VfxSignal2<VfxObject *, VfxU8> m_signalChanged;
// Override
protected:
	void onInit(void);
	void onEntered(void);
	void onDeinit(void);
	mmi_ret onProc(mmi_event_struct *evt);
	 
private:
	
	void onItemSwitchReq(VcpFormItemSwitchCell *obj, VfxId id, VfxBool newState);
	void onItemCellLaunch(VcpFormItemCell *obj, VfxId id);
	void onToolbarClick(VfxObject* obj, VfxId id);
	void onFuncBarClick(VfxObject *sender, VfxId id);
	void onRepeatSelection(VfxObject *obj, VfxU8 days);
	void save(void);
	VfxWString getToneString(void) const;
	void initNode(srv_alm_node_type *node);
	
private:	
	VcpFormItemTextInput *txtLabel;
	VcpFunctionBar *m_funcBar;
	srv_alm_node_type *m_pNode;
	VcpForm *m_form;
	VfxU8 m_index;
	VfxU8 m_repeat;
	mmi_id m_cuiGrpId;
	VfxBool m_firstEnter;

};


#endif /* __VAPP_ALARM_EDIT_H__ */

