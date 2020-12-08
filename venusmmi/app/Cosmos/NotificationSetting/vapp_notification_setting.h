/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   vapp_notification_setting.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   notification setting app
 *
 * Author:
 * -------
 * -------
 *
 *****************************************************************************
 *============================================================================
 *			 HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_NOTIFICATION_SETTING_H__
#define __VAPP_NOTIFICATION_SETTING_H__

/*****************************************************************************
 * Include header files
 *****************************************************************************/
#include "MMI_features.h" 
#ifdef __MMI_NSS_SUPPORT__
#include "vfx_app.h" // for VfxApp
#include "vfx_main_scr.h" // for IVfxMainScrHandler
#include "vfx_page.h" // for VfxPage
#include "vcp_form.h" // for VcpFormItemSwitchCell
#include "vcp_list_menu.h" // for VcpListMenu
#include "mmi_rp_vapp_notification_setting_def.h"


/*****************************************************************************
 * Define consts
 *****************************************************************************/
//#define

/*****************************************************************************
 * Typedef
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif
extern void vapp_notification_setting_launch(VfxMainScr* scr);
#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Define Class VappNSettingIconFormCell
 * Description: add_description_here
 *****************************************************************************/
class VappNSettingIconFormCell : public VcpFormItemLauncherCell 
{
    VFX_DECLARE_CLASS(VappNSettingIconFormCell);
protected:
	// The size parameter should be the same as the VcpListMenuCellIconSingleTextFrame
#if defined(__MMI_MAINLCD_320X480__)
	enum
	{
		TEXT_LEFT_GAPS	 = 0,
		TEXT_RIGHT_GAPS  = 10,
		IMG_LEFT_GAPS	 = 8,
		IMG_RIGHT_GAPS	 = 8,
		IMG_MAX_WIDTH	 = 30,
		IMG_MAX_HEIGHT	  = 30, 	   
		ACCESSORY_WIDTH  = 30,
		ACCESSORY_RIGHT_GAPS = 8
	};
#elif defined(__MMI_MAINLCD_480X800__)
	enum
	{
		TEXT_LEFT_GAPS	 = 0,
		TEXT_RIGHT_GAPS  = 18,
		IMG_LEFT_GAPS	 = 14,
		IMG_RIGHT_GAPS	 = 18,
		IMG_MAX_WIDTH	 = 35,
		IMG_MAX_HEIGHT	  = 35, 	   
		ACCESSORY_WIDTH  = 30,
		ACCESSORY_RIGHT_GAPS = 8		
	};
#else
	enum
	{
		TEXT_LEFT_GAPS	 = 0,
		TEXT_RIGHT_GAPS  = 8,
		IMG_LEFT_GAPS	 = 5,
		IMG_RIGHT_GAPS	 = 5,
		IMG_MAX_WIDTH	 = 23,	 
		IMG_MAX_HEIGHT	  = 23,
		ACCESSORY_WIDTH  = 30,
		ACCESSORY_RIGHT_GAPS = 8		
	};
#endif       

	// Overrides
public:
	virtual void onInit();
	void setIconResId(VfxU32 id);
	void setIconImage(const mmi_image_src_struct& aImage);
	virtual void onUpdate();
	
	// Variables
private:
	VfxImageFrame *m_imageFrame;
};


/*****************************************************************************
 * Define Class VappNSettingApp
 * Description: add_description_here
 *****************************************************************************/
class VappNSettingApp : public VfxApp, public IVfxMainScrHandler, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappNSettingApp);
    
public: 
    
// Methods override Base:
/*---------------------------------------------------------------------------*
 * Function: onRun()
 * Date:Feb/15/2012
 * Description: virtual function from VfxApp, Be called when VappNSettingApp is launching. 
 *    
 * Parameters
 *    @args: 
 *    @argSize: 
 *---------------------------------------------------------------------------*/
    virtual void onRun(void* args, VfxU32 argSize);

/*---------------------------------------------------------------------------*
 * Function: onProc()
 * Date:Feb/15/2012
 * Description: App call back function.
 *    
 * Parameters
 *    @*param: 
 *    @return:
 *---------------------------------------------------------------------------*/
    virtual mmi_ret onProc(mmi_event_struct *param);

/*---------------------------------------------------------------------------*
 * Function: onScr1stReady()
 * Date:Feb/15/2012
 * Description: virtual function from IVfxMainScrHandler, Be called when screen is prepare to show.
 *    
 * Parameters
 *    @scr: the screen handle.
 *---------------------------------------------------------------------------*/
    virtual void onScr1stReady(VfxMainScrEx* scr);

/*---------------------------------------------------------------------------*
 * Function: onScr2ndReady()
 * Date:Feb/15/2012
 * Description: virtual function from IVfxMainScrHandler, Be called after 1st fram is drawed.
 *    
 * Parameters
 *    @scr: the screen handle.
 *---------------------------------------------------------------------------*/
	virtual void onScr2ndReady(VfxMainScrEx* scr);

/*---------------------------------------------------------------------------*
 * Function: getItemImage()
 * Date:Apr/7/2012
 * Description: virtual function from IVcpListMenuContentProvider, give image of list items.
 *    
 * Parameters
 *    @index: [IN] the index of item
 *    @fieldType: [IN] the type of the field in the cell
 *    @&image: [OUT] the image resource
 *    @return: VFX_TURE is success
 *---------------------------------------------------------------------------*/
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);
	

/*---------------------------------------------------------------------------*
 * Function: getItemState()
 * Date:Apr/7/2012
 * Description: virtual from IVcpListMenuContentProvider, give the item status.
 *    
 * Parameters
 *    @index: the index of the item to be given status.
 *    @return: item status.
 *---------------------------------------------------------------------------*/
	virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
	

/*---------------------------------------------------------------------------*
 * Function: onPopupButtonClicked()
 * Date:Apr/11/2012
 * Description: background data confirm popup call back function.
 *    
 * Parameters
 *    @sender: 
 *    @id: 
 *---------------------------------------------------------------------------*/
    void onPopupButtonClicked(VfxObject* sender, VfxId id);

/*---------------------------------------------------------------------------*
 * Function: getCount()
 * Date:Apr/7/2012
 * Description: the count of list items .
 *    
 *    @return: return the dev list count.
 *---------------------------------------------------------------------------*/
    virtual VfxU32 getCount() const;

/*---------------------------------------------------------------------------*
 * Function: onItemSelect()
 * Date:Apr/7/2012
 * Description: callback function, be called when user select a notification style.
 *    
 * Parameters
 *    @*menuList: 
 *    @item_id: 
 *---------------------------------------------------------------------------*/
void onItemSelect(VcpListMenu *menuList, VfxU32 item_id);


// New Methods:
    
// Implementations:
private:

/*---------------------------------------------------------------------------*
 * Function: initAppsListPage()
 * Date:Mar/17/2012
 * Description: initialize the Apps List Page
 *    
 * Parameters
 *    @aAppListPage: the handle of the page.
 *---------------------------------------------------------------------------*/
	void initAppsListPage(VfxPage* aAppListPage);


/*---------------------------------------------------------------------------*
 * Function: goToDetailSetting()
 * Date:Mar/17/2012
 * Description: go to detail setting page.
 *    
 * Parameters
 *    @VcpFormItemCell*: 
 *    @Id: 
 *---------------------------------------------------------------------------*/
	void goToDetailSetting(VcpFormItemCell* cell, VfxId Id);


/*---------------------------------------------------------------------------*
 * Function: initAppsSettingPage()
 * Date:Mar/17/2012
 * Description: initialize the Apps detail setting Page
 *    
 *---------------------------------------------------------------------------*/
	void initAppsSettingPage();


/*---------------------------------------------------------------------------*
 * Function: initStylePage()
 * Date:Apr/7/2012
 * Description: initialize the App Style Page
 *    
 * Parameters
 *    @aStylePage: the handle of the page.
 *---------------------------------------------------------------------------*/
	void initStylePage(VfxPage* aStylePage);

/*---------------------------------------------------------------------------*
 * Function: onBackgroundSwitch()
 * Date:Mar/20/2012
 * Description: user clicked the background switch cell.
 *    
 * Parameters
 *    @*cell: 
 *    @id: 
 *    @newVal: 
 *---------------------------------------------------------------------------*/
    void onBackgroundSwitch(VcpFormItemSwitchCell *cell, VfxId id, VfxBool newVal);


/*---------------------------------------------------------------------------*
 * Function: onAppDetailSettingSwitch()
 * Date:Apr/11/2012
 * Description: user clicked the Form cells on detail page.
 *    
 * Parameters
 *    @*cell: 
 *    @id: 
 *    @newVal: 
 *---------------------------------------------------------------------------*/
    void onAppDetailSettingSwitch(VcpFormItemSwitchCell *cell, VfxId id, VfxBool newVal);


/*---------------------------------------------------------------------------*
 * Function: onStyleCellClicked()
 * Date:Mar/28/2012
 * Description: user clicked style cell.
 *    
 * Parameters
 *    @cell: 
 *    @Id: 
 *---------------------------------------------------------------------------*/
	void onStyleCellClicked(VcpFormItemCell* cell, VfxId Id);

// Numbers:
private:

    VfxMainScrEx* m_screen;
	VfxPage* m_detailPage;
	VcpFormItemLauncherCell* m_styleCell;
	VcpListMenu* m_listMenu;
	VcpFormItemSwitchCell *m_backgroundSetting;
	VfxU32 m_appIndex;
	VfxU32 m_styleIndex;
	VfxU16 m_appId;
    
};
#endif // __MMI_NSS_SUPPORT__

#endif /* __VAPP_NOTIFICATION_SETTING_H__ */
