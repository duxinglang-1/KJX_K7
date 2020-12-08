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
 *   vapp_ncenter_quick_setting_cell.h
 *
 * Project:
 * --------
 *   NCenter2.0
 *
 * Description:
 * ------------
 *   Define  class of quick setting.
 *
 * Author:
 * -------
 * -------
 *
 *****************************************************************************
 *============================================================================
 *			  HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/ 

#ifndef __VAPP_NCENTER_QUICK_SETTING_CELL_H__
#define __VAPP_NCENTER_QUICK_SETTING_CELL_H__
#include "MMI_features.h"

#define __MMI_NCENTER_NATIVE_WIDGET_SUPPORT__

#ifdef __MMI_NCENTER_NATIVE_WIDGET_SUPPORT__

/*****************************************************************************
* Include header files
*****************************************************************************/

#include "vapp_ncenter_base_cell.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "vcp_waiting_icon.h" // for VcpWaitingIcon
#endif

extern "C"
{
	
#ifdef __MMI_WLAN_FEATURES__
#include "TetheringSrvGprot.h" // for srv_tethering_type_enum
#endif

#if defined(__COSMOS_MMI_PACKAGE__)
#include "mmi_frm_scenario_gprot.h" // for mmi_scenario_id
#endif

}

/*****************************************************************************
* Define consts
*****************************************************************************/

/*****************************************************************************
* Typedef
*****************************************************************************/
class VappQuickSettingElement;

/*****************************************************************************
 * Define Class VappQuickSettingElement
 * Description: add_description_here
 *****************************************************************************/
class VappQuickSettingElement : public VfxFrame
{    
public:    
	VappQuickSettingElement(VfxS32 aId,VfxS32 aWidth, VfxResId aButton_N, VfxResId aButton_H, VfxU32 aIndicatorCount = 1)
	:m_elementId(aId),
	m_elementWidth(aWidth),
	m_indicatorCount(aIndicatorCount),
	m_currentIndex(0)
	{
		m_buttonImageId[0] = aButton_N;
		m_buttonImageId[1] = aButton_H;
	}
// Methods override Base:
protected:
/*---------------------------------------------------------------------------*
 * Function: onInit()
 * Date:Feb/28/2012
 * Description: virtual function from VfxObject, called when create.
 *    
 *---------------------------------------------------------------------------*/
    virtual void onInit();

// New Methods:
public:  
/*---------------------------------------------------------------------------*
 * Function: setIndicator()
 * Date:Feb/28/2012
 * Description: set the current indicator index.
 *    
 * Parameters
 *    @aIndicatorIndex: the index to set
 *---------------------------------------------------------------------------*/
	void setIndicator(VfxU32 aIndicatorIndex);

/*---------------------------------------------------------------------------*
 * Function: increaseIndicator()
 * Date:Feb/28/2012
 * Description: add (+1) to current indicator index.
 *    
 *---------------------------------------------------------------------------*/
	void increaseIndicator();

/*---------------------------------------------------------------------------*
 * Function: decreaseIndicator()
 * Date:Feb/28/2012
 * Description: add (-1) to currnet indicator index.
 *    
 *---------------------------------------------------------------------------*/
	void decreaseIndicator();

/*---------------------------------------------------------------------------*
 * Function: getCurrentIndicator()
 * Date:Feb/28/2012
 * Description: get the current indicator index.
 *    
 *    @return: index value.
 *---------------------------------------------------------------------------*/
	VfxU32 getCurrentIndicator() const;



/*---------------------------------------------------------------------------*
 * Function: getId()
 * Date:Feb/28/2012
 * Description: get the element ID
 *    
 *    @return: return the ID of the element.
 *---------------------------------------------------------------------------*/
	VfxS32 getId() const;

/*---------------------------------------------------------------------------*
 * Function: showProcessInd()
 * Date:Apr/10/2012
 * Description: show process indicator animation.
 *    
 *---------------------------------------------------------------------------*/
	void showProcessInd();


/*---------------------------------------------------------------------------*
 * Function: cancelProcessInd()
 * Date:Apr/10/2012
 * Description: stop process indicator animation.
 *    
 *---------------------------------------------------------------------------*/
	void cancelProcessInd();


/*---------------------------------------------------------------------------*
 * Function: isEnable()
 * Date:Apr/18/2012
 * Description: 
 *    
 *    @return: return VFX_TURE if can be clicked
 *---------------------------------------------------------------------------*/
	VfxBool isEnable();

public:
	VcpImageButton* m_imageButton;
// Implementations:
private:
    
// Numbers:
private:
	enum
	{
#if defined(__MMI_MAINLCD_480X800__)//WVGA
		BTN_BOUNDS_X =43,
		BTN_BOUNDS_Y=43,
		INDICATOR_PACE =18,
		INDICATOR_Y = 18,
		BTN_Y=35,
		EFFECT_W =85,
		EFFECT_H =85
		
#elif defined(__MMI_MAINLCD_320X480__)//HVGA
		BTN_BOUNDS_X = 32,
		BTN_BOUNDS_Y = 32,
		INDICATOR_PACE =12,
		INDICATOR_Y = 9,
		BTN_Y=21,
		EFFECT_W =65,
		EFFECT_H =65
		
#elif defined(__MMI_MAINLCD_240X400__)//WQVGA
		BTN_BOUNDS_X =25,
		BTN_BOUNDS_Y=25,
		INDICATOR_PACE =10,
		INDICATOR_Y = 6,
		BTN_Y=16,
		EFFECT_W =55,
		EFFECT_H =55
		
#else //QVGA
		BTN_BOUNDS_X =25,
		BTN_BOUNDS_Y=25,
		INDICATOR_PACE =10,
		INDICATOR_Y = 6,
		BTN_Y=16,
		EFFECT_W =55,
		EFFECT_H =55
#endif
	};

    VfxS32 m_elementId;
	VfxS32 m_elementWidth;
    VfxU32 m_indicatorCount;
	VfxU32 m_currentIndex;
	VfxResId m_buttonImageId[2];
	VfxImageFrame* m_indicatorImage[3];
	
#ifdef __COSMOS_MMI_PACKAGE__
    VcpActivityIndicator *m_activityInd;
#else
	VcpWaitingIcon* m_activityInd;
#endif /* !defined(__MRE_SDK__) && defined(__COSMOS_MMI_PACKAGE__) */
};

class VappQuickSettingInfo
{
public:
	VfxS32 elementID;
	VfxResId buttonImage_N;
	VfxResId buttonImage_H;
	VfxS32 indicatorCount;
	VappQuickSettingElement* elementHandle;
};

/*****************************************************************************
* Define Class VappQuickSettingCell
* Description:  Define base class of quick setting cell.
*****************************************************************************/
class VappQuickSettingCell : public VfxFrame
{
    VFX_DECLARE_CLASS(VappQuickSettingCell);
protected:

/*---------------------------------------------------------------------------*
 * Function: onInit()
 * Date:Feb/27/2012
 * Description: virtual function from VfxObject, called when create.
 *    
 *---------------------------------------------------------------------------*/
	virtual void onInit();

/*---------------------------------------------------------------------------*
 * Function: onDeinit()
 * Date:Feb/28/2012
 * Description: add_description_here
 *    
 *---------------------------------------------------------------------------*/
	virtual void onDeinit();
public:
/*---------------------------------------------------------------------------*
 * Function: findElementById()
 * Date:Feb/28/2012
 * Description: get the element handle by its ID.
 *    
 * Parameters
 *    @aElementId: the element ID.
 *    @return: return the element handle if found, or NULL.
 *---------------------------------------------------------------------------*/
	VappQuickSettingElement* findElementById(VfxS32 aElementId);

	void setWidth(VfxU32 width);
/*---------------------------------------------------------------------------*
 * Function: enentHdlr()
 * Date:Feb/28/2012
 * Description: enent handler, handle the enents, execpt bt envent.
 *    
 * Parameters
 *    @*evt: the entent to handle.
 *    @return: 
 *---------------------------------------------------------------------------*/
	static mmi_ret enentHdlr(mmi_event_struct *evt);
	
#if defined(__COSMOS_MMI_PACKAGE__)
	static MMI_BOOL warningToneCallback(mmi_scenario_id, void* user_data);

#ifndef __MMI_BT_IN_FLIGHT_MODE__
	static void onNullComfirmed(VfxId id, void *userData);
#endif //__MMI_BT_IN_FLIGHT_MODE__
#endif //__COSMOS_MMI_PACKAGE__

/*---------------------------------------------------------------------------*
 * Function: flightEvtHdlr()
 * Date:Mar/13/2012
 * Description: call back function for fligh mode switching. just return MMI_RET_OK.
 *    
 * Parameters
 *    @*event: 
 *    @return: return MMI_RET_OK
 *---------------------------------------------------------------------------*/
	static mmi_ret flightEvtHdlr(	mmi_event_struct *event);

#ifdef __MMI_WLAN_FEATURES__ 
/*---------------------------------------------------------------------------*
 * Function: afterStopTethering()
 * Date:Mar/14/2012
 * Description: auto turn wlan, if stoping successful.
 *    
 * Parameters
 *    @tethering_type: 
 *    @result: 
 *    @*user_data: 
 *---------------------------------------------------------------------------*/
	static void afterStopTethering(
		srv_tethering_type_enum tethering_type, 
		MMI_BOOL result, 
		void *user_data
	);	
#endif //__MMI_WLAN_FEATURES__ 

#ifdef __MMI_BT_SUPPORT__
/*---------------------------------------------------------------------------*
 * Function: btEvtHdlr()
 * Date:Feb/28/2012
 * Description: handle bt event
 *    
 * Parameters
 *    @event: 
 *    @para: 
 *---------------------------------------------------------------------------*/
    static void btEvtHdlr(U32 event, void* para);
#endif // __MMI_BT_SUPPORT__

/*---------------------------------------------------------------------------*
 * Function: onUserComfirmed()
 * Date:Mar/14/2012
 * Description: This function handles the popup clicked signal
 *    
 * Parameters
 *    @id: [IN] Button ID
 *    @*userData: [IN] User data, for comfirm PopupID
 *---------------------------------------------------------------------------*/
static void onUserComfirmed(VfxId id, void *userData);

/*---------------------------------------------------------------------------*
 * Function: onFTEComirmed()
 * Date:Mar/20/2012
 * Description: call back when user clicked popup button on FTE.
 *    
 * Parameters
 *    @*obj: 
 *    @id: 
 *---------------------------------------------------------------------------*/
	void onFTEComirmed(VfxObject *obj, VfxId id);

/*---------------------------------------------------------------------------*
 * Function: onUserClicked()
 * Date:Feb/28/2012
 * Description: called when user clicked the element button.
 *    
 * Parameters
 *    @*sender: 
 *    @id: the ID of being clicked button.
 *---------------------------------------------------------------------------*/
	void onUserClicked(VfxObject *sender, VfxId id);

private:

/*---------------------------------------------------------------------------*
 * Function: showComfirmPopup()
 * Date:Mar/11/2012
 * Description: popup a comfirm.
 *    
 *---------------------------------------------------------------------------*/
	void showComfirmPopup();

/*---------------------------------------------------------------------------*
 * Function: getCurrentLightIndex()
 * Date:Feb/28/2012
 * Description: get the current light index of LCD.
 *    
 *    @return: return the index of light, 0, 1, 2, or 3
 *---------------------------------------------------------------------------*/
	VfxS32 getCurrentLightIndex();


/*---------------------------------------------------------------------------*
 * Function: getSrvStatusById()
 * Date:Mar/11/2012
 * Description: get indicator count from service by elementID.
 *    
 * Parameters
 *    @aIndex: the id of element.
 *    @return: current indicator count.
 *---------------------------------------------------------------------------*/
	VfxS32 getSrvStatusById(VfxS32 aElementId);

/*---------------------------------------------------------------------------*
 * Function: setSrvStatusById()
 * Date:Mar/11/2012
 * Description: set indicator count to service by elementID.
 *    
 * Parameters
 *    @aNewStatus: new stuatus.
 *    @aElementId: the id of element.
 *---------------------------------------------------------------------------*/
	void setSrvStatusById(VfxU32 aNewStatus, VfxS32 aElementId);

/*---------------------------------------------------------------------------*
 * Function: registerEvent()
 * Date:Feb/28/2012
 * Description: Register events of callback manager.
 *    
 *---------------------------------------------------------------------------*/
    void registerEvent();

/*---------------------------------------------------------------------------*
 * Function: deregisterEvent()
 * Date:Feb/28/2012
 * Description: Deregister events of callback manager.
 *    
 *---------------------------------------------------------------------------*/
    void deregisterEvent();


/*---------------------------------------------------------------------------*
 * Function: createBgImg()
 * Date:Mar/13/2012
 * Description: create the background image.
 *    
 *---------------------------------------------------------------------------*/
	void createBgImg(const VfxSize& aBackgroundSize);


/*---------------------------------------------------------------------------*
 * Function: createElements()
 * Date:Mar/13/2012
 * Description: create the elements
 *    
 *---------------------------------------------------------------------------*/
	void createElements(const VfxSize& aElementSize);


// Numbers:
public:
	VfxU32 m_comfirmType;
	VfxBool m_turningOffTethering;
	VfxS32 m_popupHandle;
private:
	enum
	{
		VAPP_QSETTING_INVALID,
#ifdef __MMI_WLAN_FEATURES__
		VAPP_QSETTING_WIFI,
#endif
#ifdef __MMI_BT_SUPPORT__
		VAPP_QSETTING_BT,
#endif
		VAPP_QSETTING_SILENCE,
		VAPP_QSETTING_FLIGHT_MODE,
		VAPP_QSETTING_LIGHT,
		VAPP_QSETTING_TOTAL
	};
	enum
    {
#if defined(__MMI_MAINLCD_480X800__)//WVGA
        BG_IMG_POS_X = -1,
        BG_IMG_POS_Y = 4,
        BG_IMGE_WIDTH = -2,
        BG_IMGE_HEIGHT = 105,
        ELEMENT_HIGHT = 94,
        SEPATATOR_HEIGHT = 94,
        SEPATATOR_WIDTH = 2
#elif defined(__MMI_MAINLCD_320X480__)//HVGA
        BG_IMG_POS_X = 1,
        BG_IMG_POS_Y = 4,
        BG_IMGE_WIDTH = 1,
        BG_IMGE_HEIGHT = 72,
        ELEMENT_HIGHT = 62,
        SEPATATOR_HEIGHT = 62,
        SEPATATOR_WIDTH = 2
#elif defined(__MMI_MAINLCD_240X400__)//WQVGA
        BG_IMG_POS_X = 1,
        BG_IMG_POS_Y = 4,
        BG_IMGE_WIDTH = 2,
        BG_IMGE_HEIGHT = 56,
        ELEMENT_HIGHT = 46,
        SEPATATOR_HEIGHT = 46,
        SEPATATOR_WIDTH = 2
#else //QVGA
        BG_IMG_POS_X = 1,
        BG_IMG_POS_Y = 4,
        BG_IMGE_WIDTH = 2,
        BG_IMGE_HEIGHT = 56,
        ELEMENT_HIGHT = 46,
        SEPATATOR_HEIGHT = 46,
        SEPATATOR_WIDTH = 2
#endif
    };
	enum
	{
		VAPP_QSETTING_COMFIRM_WIFI_ON_WITH_FLIGHT_MODE = 1,
		VAPP_QSETTING_COMFIRM_WIFI_ON_WITH_TETHERING,
		VAPP_QSETTING_COMFIRM_BT_ON_WITH_FLIGHT_MODE,
		VAPP_QSETTING_COMFIRM_BT_OFF_WITH_CONNECTING
	};
	VappQuickSettingInfo m_elementInfo[VAPP_QSETTING_TOTAL - 1];
	VfxS32 m_rowNum;
	VfxBool m_lightUp;
	VfxS32 m_elementCount;
	VfxFrame* m_backgroundFrame;
	VfxS32 m_elementsInOneLine;
#ifdef __MMI_BT_SUPPORT__
    VfxS32 m_btSrvHandle;
#endif //__MMI_BT_SUPPORT__
};

#endif //__MMI_NCENTER_NATIVE_WIDGET_SUPPORT__
#endif //__VAPP_NCENTER_QUICK_SETTING_CELL_H__
