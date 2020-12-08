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
 *  vapp_alarm_list.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Alarm list page header file.
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_ALARM_LIST_H__
#define __VAPP_ALARM_LIST_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
	#include "MMIDataType.h"
}
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vfx_page.h"
#include "vfx_signal.h"

#include "vcp_list_menu.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappAlarmRecentFrame
 *****************************************************************************/
class VappAlarmClock;
class VappAlarmTimeFrame;
class VappAlarmRecentFrame : public VfxFrame
{
// Override
public:
	VappAlarmRecentFrame();
	VappAlarmRecentFrame(const VfxU16 &index);
	virtual ~VappAlarmRecentFrame(){};
    virtual void onInit();

	void setIndex(const VfxU16 &index);
	VfxU16 getIndex(void) const;

	enum{ 
#ifdef __MMI_MAINLCD_480X800__
		HEIGHT = 198,
    	LABEL_POS_X = 30,
		LABEL_POS_Y = 50,
    	LABEL_FONT_SIZE = 26,
		TIME_POS_X = LABEL_POS_X,
		TIME_POS_Y = 47,
    	TIME_FONT_SIZE = 80,
    	AMPM_FONT_SIZE = 26,
		NON_ALM_FONT_SIZE = 32,
    	CLOCK_RIGHT_MARGIN = 14,	
    	TXT_MARGIN = 14,
#elif defined  __MMI_MAINLCD_320X480__
		HEIGHT = 120,
	  	LABEL_POS_X = 20,
	  	LABEL_POS_Y = 25,
	  	LABEL_FONT_SIZE = 13,
	  	TIME_POS_X = LABEL_POS_X,
	  	TIME_POS_Y = 47,
	  	TIME_FONT_SIZE = 45,
	  	AMPM_FONT_SIZE = 26,
	  	NON_ALM_FONT_SIZE = 16,
	  	CLOCK_RIGHT_MARGIN = 10,
		TXT_MARGIN = 8,
#elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )
		HEIGHT = 99,
	  	LABEL_POS_X = 14,
	  	LABEL_POS_Y = 20,
	  	LABEL_FONT_SIZE = 13,
	  	TIME_POS_X = LABEL_POS_X,
	  	TIME_POS_Y = 37,
	  	TIME_FONT_SIZE = 40,
	  	AMPM_FONT_SIZE = 14,
	  	NON_ALM_FONT_SIZE = 18,
	  	CLOCK_RIGHT_MARGIN = 10,
		TXT_MARGIN = 8,
#else //temp value
		HEIGHT = 198,
		LABEL_POS_X = 23,
		LABEL_POS_Y = 50,
		LABEL_FONT_SIZE = 23,
		TIME_POS_X = LABEL_POS_X,
		TIME_POS_Y = 47,
		TIME_FONT_SIZE = 98,
  		AMPM_FONT_SIZE = 26,
		NON_ALM_FONT_SIZE = 32,
		CLOCK_RIGHT_MARGIN = 10,	
		TXT_MARGIN = 8,
#endif
	  	INVALID_INDEX = 0xFF
		};
	
private:
	void update(void);
	
private:
	VappAlarmTimeFrame *m_time;
	VappAlarmClock *m_clock;
	
	VfxTextFrame *m_txtLabel;
	VfxU16		  m_almIdx;
	
};

/***************************************************************************** 
 * Class VappAlarmlistPage
 *****************************************************************************/
class VcpToolBar;
class VfxTextFrame;
class VappAlmCustomListMenu;
class VappAlarmlistPage : public VfxPage
{

public:
	VappAlarmlistPage();
	virtual ~VappAlarmlistPage(){};

	mmi_ret onOpEvt(mmi_event_struct *evt);
	static mmi_ret onEvtHandler(mmi_event_struct *evt);

	VfxSignal0	m_signalDeleted;
	enum
    {
            ID_TOOLBAR_BTN1,
	    ID_TOOLBAR_BTN2,
	    ID_TOOLBAR_BTN3,
	    ID_TOOLBAR_BTN4,
	    ID_TOOLBAR_BTN5,
	    ID_TOOLBAR_BTN6,
	    ID_TOOLBAR_END
    };
	
	
// Override
protected:	
  void onInit(void);
  void onDeinit(void);
  void onBack(void);
  void onEnter(VfxBool isBackward);
	
private:
	void onListItemTap(VfxObject *obj, VfxU32 index);
	void onListItemSwitch(VfxU16 index, VfxBool newState);
	void onToolbarClick(VfxObject* obj, VfxId id);
	void onTimeChanged(VfxU32 flag);
	void refresh(void);
	void onEditDone(VfxObject *obj, VfxU8 index);
	void onDeleteDone(void);
	void reset(void);

	void changeMode(const VfxU16 &newMode);
	
	void createDelToolbar(void);
	//void onDelToolbarClick(VfxObject* obj, VfxId id);
	void onDelCmdCallback(VfxObject *obj, VfxId id);
	void onSelChange(VfxObject *obj, VfxU32 count);

private:
	VappAlarmRecentFrame *m_recentAlm;
	VappAlmCustomListMenu *m_list;
	VcpToolBar *m_toolbar;
	//VcpToolBar *m_toolbarDel;
	VfxBool m_bAll;
};

#endif /* __VAPP_ALARM_H__ */

