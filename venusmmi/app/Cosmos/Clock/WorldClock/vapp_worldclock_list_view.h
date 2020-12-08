/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 * VappWorldclockListView.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements world clock application.
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
 *****************************************************************************/ 
#ifndef __VAPP_WORLD_CLOCK_LIST_VIEW_H__
#define __VAPP_WORLD_CLOCK_LIST_VIEW_H__

/****************************************************************************
 *Include
 ***************************************************************************/
#include "vapp_worldclock_panel.h"
#include "Vcp_include.h"
#include "vfx_mc_include.h"
#include "custom_world_clock.h"
/****************************************************************************
 *class
 ***************************************************************************/
/****************************************************************************
 *world clock list view page class
 ***************************************************************************/ 
#ifndef __MMI_WORLDCLOCK_SLIM__
#define cityMaxNumber 4
#else 
#define cityMaxNumber 3
#endif
class VappWCListViewPage:public VfxPage, IVcpListMenuContentProvider
{
public:
	//construct.
	VappWCListViewPage();
	virtual ~VappWCListViewPage();

public:

	enum WCToolbar
	{
		ID_VAPP_WC_ADD,
		ID_VAPP_WC_LIST
	};
	
    enum EditMenu
    {
       REPLACE_CITY,
       ACTIVE_DAY_LIGHT,
       CLOSE
    };

	enum EditFrnMenu
    {
       F_REPLACE_CITY,
       F_ACTIVE_DAY_LIGHT,
       F_SET_AS_HOMECITY,
       F_REMOVE,
       F_CLOSE
    };

	public:
    VfxSignal2 <
        VfxObject *, // Sender
        VfxU16       // cityIndex
        > m_signalCityChanged;
public:
	virtual void onInit();
	virtual VfxU32 getCount() const;
    //VfxBool getMenuEmptyText(VfxWString &text,VcpListMenuTextColorEnum &color);   
    virtual VfxBool getItemText(
                VfxU32 index,
                VcpListMenuFieldEnum fieldType,
                VfxWString& text,
                VcpListMenuTextColorEnum & color
                );
    virtual VfxBool getItemTextFormat(
                VfxU32 index,
                VcpListMenuFieldEnum fieldType,
                VcpRichText & format
                );

    virtual VcpListMenuCellClientBaseFrame* getItemCustomContentFrame(
                                        VfxU32 index,
                                        VfxFrame * parentFrame);
    virtual void closeItemCustomContentFrame(
								VfxU32 index,
								VcpListMenuCellClientBaseFrame *cell); 
	
	//virtual VfxBool getItemImage(
	//	  VfxU32 index, 				  // [IN] the index of item
	//	  VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
	//	  VfxImageSrc &image			  // [OUT] the image resource
	//	  );
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);
private:
	
	void onToolBarClick(VfxObject* sender, VfxId id);
	void onTapButton(VcpListMenu *, VfxId id);
	void setItemData();
	void showSelectCityPage(VfxBool HighLight, VfxBool HFlag);
	void onHomeCityChange(VfxObject *sender, VfxU16 cityIndex);
	void onFrnSelectCity(VfxObject *sender, VfxU16 cityIndex);
	void showHomeEditMenu();
	void showFrnEditMenu();
	void onHomeCmdPopCallback(VfxObject *obj, VfxId id);
	void HomeDLSHandler(VfxBool flag);
	//void onDayLightSavingChange();
	void updateTime(VfxObject *sender, VfxU16 cityIndex);
	void onFrnCmdPopCallback(VfxObject *obj, VfxId id);
	void FrnDLSHandler(VfxBool flag);
	void onDeleteCell(VfxObject *obj, VfxId id);

	
private:
	//VcpTitleBar *m_titlebar;
	VcpToolBar  *m_toolbar;
	VcpListMenu *m_listmenu;
	VfxU16 m_cityIndex[cityMaxNumber];
	VfxFloat m_cityZone[cityMaxNumber];
	//VfxU16 m_cityTime[cityMaxNumber];
	VfxU16 m_homeIcon;
	VappWCDataControl m_dataControl;
	VfxU16 m_citySelect;
	VfxId m_selectID;
	VfxBool m_frnflag;	


};
#endif
