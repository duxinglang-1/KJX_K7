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
 *  vapp_alarm_list_menu.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Alarm list menu header file.
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
#ifndef __VAPP_ALARM_LIST_MENU_H__
#define __VAPP_ALARM_LIST_MENU_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"
#include "vfx_signal.h"

#include "vcp_list_menu.h"
#include "vcp_menu_popup.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappAlarmListItem
 *****************************************************************************/
class VappAlarmTimeFrame;
class VcpSwitch;
class VfxWString;
class VfxTextFrame;
class VappAlarmListItem : public VcpListMenuCellClientBaseFrame
{
public:
	VappAlarmListItem();
	VappAlarmListItem(const VfxU16 &index, const VfxBool &bSwitch = VFX_TRUE);
	virtual ~VappAlarmListItem(){};
	
    enum{
	#ifdef __MMI_MAINLCD_480X800__
		TIME_FONT_SIZE = 30,
		AMPM_FONT_SIZE = 21,
		REPEAT_FONT_SIZE = 21,
		LABEL_FONT_SIZE = 21,
		TIME_POS_X = 14,
		TIME_POS_Y = 13,
		REPEAT_POX_X = TIME_POS_X,
		REPEAT_POX_Y = 50,
		LABEL_POS_SHIFT = 14,
		SWITCH_RIFHT_MARGIN = 14,
	#elif defined  __MMI_MAINLCD_320X480__
		TIME_FONT_SIZE = 20,
		AMPM_FONT_SIZE = 14,
		REPEAT_FONT_SIZE = 14,
		LABEL_FONT_SIZE = 14,
		TIME_POS_X = 8,
		TIME_POS_Y = 6,
		REPEAT_POX_X = TIME_POS_X,
		REPEAT_POX_Y = 30,
		LABEL_POS_SHIFT = 10,
		SWITCH_RIFHT_MARGIN = 8,
    #elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )
		TIME_FONT_SIZE = 16,
		AMPM_FONT_SIZE = 12,
		REPEAT_FONT_SIZE = 12,
		LABEL_FONT_SIZE = 12,
		TIME_POS_X = 5,
		TIME_POS_Y = 7,
		REPEAT_POX_X = TIME_POS_X,
		REPEAT_POX_Y = 26,
		LABEL_POS_SHIFT = 8,
		SWITCH_RIFHT_MARGIN = 8,
	#else // temp value
		TIME_FONT_SIZE = 17,
		AMPM_FONT_SIZE = 10,
		REPEAT_FONT_SIZE = 13,
		LABEL_FONT_SIZE = 14,
		TIME_POS_X = 8,
		TIME_POS_Y = 10,
		REPEAT_POX_X = TIME_POS_X,
		REPEAT_POX_Y = 30,
		LABEL_POS_SHIFT = 22,
		SWITCH_RIFHT_MARGIN = 10,
	#endif
        };

	//void setIndex(const VfxU16 &index); 

	VfxSignal2<VfxU16, VfxBool> m_signalSwitch;
// Overridable
public:
    virtual void onCreateElements(void);
    virtual void onCloseElements(void);
    virtual void onLayoutElements(void);
    virtual void onUpdateElements(void){};
	
private:
	/*const VfxWString getRepeatString(
						const VfxU16 &repeat,
						const VfxU8 &days
						) const;
	
	const VfxWString getTimeString(
						const VfxU32 &hour,
						const VfxU32 &min
						) const;*/
	
    void onAniDone(
            VcpSwitch *obj, 	//[IN] sender
			VfxBool newState	//[IN] new state
            );

private:
	VappAlarmTimeFrame  *m_txtTime;
	VfxTextFrame  *m_txtRepeat;
	VfxTextFrame  *m_txtLabel;
	VcpSwitch	  *m_switch;

    VfxU16 m_index;
	VfxBool m_bSwitch;
};

/***************************************************************************** 
 * Class VappAlmCustomListMenu
 *****************************************************************************/
class VappAlmCustomListMenu : public VcpListMenu, public IVcpListMenuContentProvider
{
public:

	VappAlmCustomListMenu(const VfxBool &bSwitch = VFX_TRUE);
	virtual ~VappAlmCustomListMenu(){};

	typedef enum
	{
		LIST_MODE_DELETE,
		LIST_MODE_LIST,
		LIST_MODE_TOTAL
	};

	const VfxU8 *getIndexList(void) const;
	void setListState(const VfxU32 &index, const VcpListMenuItemStateEnum &newState);

	VfxU32 getCount(void) const { return m_totalAlm; };
	void updateOneItem(const VfxU32 &index);
	void updateAllItems(VfxBool needReset = VFX_FALSE);
	void deleteSelectedItems(void);
    VfxU32 getSelectedCount(void);
	
	void setEditMode(const VfxU16 &newMode);

	VfxSignal2<VfxU16 , VfxBool > m_signalSwitch;
	VfxSignal2<VfxObject *, VfxU32> m_signalTap;
	VfxSignal0	m_signalDeleteDone;
	VfxSignal2<VfxObject *, VfxU32> m_signalHasSelect;
	
// Override
protected:	
	void onInit();

	// VcpList implement function

	VcpListMenuItemStateEnum getItemState(
		VfxU32 index   // [IN] index of the item
		) const;

	VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
		VfxU32 index,		 // [IN] index of the item
		VfxFrame *parentFrame // [IN] parent frame of the custom content frame
		);
	
	void closeItemCustomContentFrame(
		VfxU32 index,  // [IN] index of the item
		VcpListMenuCellClientBaseFrame *cell // [IN] the content frame to be released
		);
	
    VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

private:
	void onListItemSelect(VcpListMenu *obj, VfxU32 index, VcpListMenuItemStateEnum newState);
	void onSwitch(VfxU16 index, VfxBool newState);
	void onItemTap(VcpListMenu *obj, VfxU32 index);
	void onLongTap(VcpListMenu *obj, U32 index);
	void onCmdCallback(VfxObject *obj, VfxId id);
	void onMenuCallack(
			VcpMenuPopup* menu, 
			VcpMenuPopupEventEnum evt, 
			VcpMenuPopupItem *item);
	void checkHasSelect(void);
	void resetState(void);
	
private:
	
	VfxBool m_bSwitch;
	VfxU8 m_totalAlm;
	VfxU8 m_indexLst[NUM_OF_ALM];
	VcpListMenuItemStateEnum m_stateLst[NUM_OF_ALM];
	VfxU16 m_mode;
	VfxU8 m_indexLongTap;
};

#endif /* __VAPP_ALARM_LIST_MENU_H__ */

