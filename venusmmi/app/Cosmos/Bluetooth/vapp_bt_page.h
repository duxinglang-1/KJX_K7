/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *   vapp_bt_page.h
 *
 * Project:
 * --------
 *   SLIM
 *
 * Description:
 * ------------
 *   Define base class of page for vapp_bt. 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_BT_PAGE_H__
#define __VAPP_BT_PAGE_H__

/*****************************************************************************
 * Include header files
 *****************************************************************************/
#include "vfx_page.h" // for VfxPage
#include "vcp_list_menu.h" // for IVcpListMenuContentProvider
#include "BtcmSrvGprot.h" // for srv_bt_cm_get_dev_info_by_index
#include "vcp_status_icon_bar.h" // for VcpStatusIconBar


/*****************************************************************************
 * Define consts
 *****************************************************************************/
#if 0
/* under construction !*/
#else
#define VFX_LOG_FUNC
#define VFX_LOG_FUNC1(fmt, p1)
#define VFX_LOG_FUNC2(fmt, p1, p2)
#define VFX_LOG_STATIC_FUNC
#define VFX_LOG_STATIC_FUNC1(fmt, p1)
#define VFX_LOG_STATIC_FUNC2(fmt, p1, p2)
#endif

/*****************************************************************************
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Define Class VappBTPageBase
 * Description:  Define base class of page for vapp_bt_xxxPage.
 *****************************************************************************/
class VappBTPageBase:public VfxPage, public IVcpListMenuContentProvider
{
 //   VFX_DECLARE_CLASS(VappBTPageBase);
    
// Methods override Base:
public:

/*---------------------------------------------------------------------------*
 * Function: getItemText()
 * Date:Nov/25/2011
 * Description: virtual function from IVcpListMenuContentProvider.
 *    
 * Parameters
 *    @index:  [IN] the index of item
 *    @fieldType: [IN] the type of the field in the cell
 *    @&text: [OUT] the text resource
 *    @&color: [OUT] the text color
 *    @return: VFX_TURE is success
 *---------------------------------------------------------------------------*/
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType,VfxWString &text,VcpListMenuTextColorEnum &color);


/*---------------------------------------------------------------------------*
 * Function: getItemImage()
 * Date:Dec 5/2011
 * Description: give image of list items.
 *    
 * Parameters
 *    @index: [IN] the index of item
 *    @fieldType: [IN] the type of the field in the cell
 *    @&image: [OUT] the image resource
 *    @return: VFX_TURE is success
 *---------------------------------------------------------------------------*/
    virtual VfxBool getItemImage(VfxU32 index,VcpListMenuFieldEnum fieldType,VfxImageSrc &image);

/*---------------------------------------------------------------------------*
 * Function: getCount()
 * Date:Nov/25/2011
 * Description: the count of dev list.
 *    
 *    @return: return the dev list count.
 *---------------------------------------------------------------------------*/
    virtual VfxU32 getCount() const;

/*---------------------------------------------------------------------------*
 * Function: initDevLis()
 * Date:Nov/25/2011
 * Description: init Dev list of page.
 *    
 *---------------------------------------------------------------------------*/
    void initDevLis();

/*---------------------------------------------------------------------------*
 * Function: onDeinit()
 * Date:Dec 5/2011
 * Description: virtual function from VfxPage. Be called when deinitialization.
 *    
 *---------------------------------------------------------------------------*/
	virtual void onDeinit();
// New Methods:
public:

/*---------------------------------------------------------------------------*
 * Function: serviceEventsNotify()
 * Date:Dec 5/2011
 * Description: service event call back.
 *    
 * Parameters
 *    @event:  current event
 *    @para: date from service.
 *---------------------------------------------------------------------------*/
	static void serviceEventsNotify(VfxU32 event, void* para);

/*---------------------------------------------------------------------------*
 * Function: onHitDevItem()
 * Date:Nov/25/2011
 * Description: call back function, Be called when user hits a dev in the dev_list.
 *    
 * Parameters
 *    @VcpListMenu: handle of dev_list.
 *    @index: the index of the hitten item.
 *---------------------------------------------------------------------------*/
	void onHitDevItem(VcpListMenu* VcpListMenu, VfxU32 index);

protected:
/*---------------------------------------------------------------------------*
 * Function: getDevInfoByIndex()
 * Date:Dec 19/2011
 * Description: get the dev info by the index.
 *    
 * Parameters
 *    @index: the index of the dev.
 *    @return: return the dev information.
 *---------------------------------------------------------------------------*/
	virtual const srv_bt_cm_dev_struct* getDevInfoByIndex(VfxU32 index);

/*---------------------------------------------------------------------------*
 * Function: updateDevList()
 * Date:Nov/25/2011
 * Description: update the dev list.
 *    
 * Parameters
 *    @aDevType: the type of dev_list.
 *---------------------------------------------------------------------------*/
	void updateDevList(srv_bt_cm_dev_type_enum aDevType);

/*---------------------------------------------------------------------------*
 * Function: popupBalloonMsg()
 * Date:Dec 7/2011
 * Description: popup a balloom message with aMsgSrtId.
 *    
 * Parameters
 *    @aMsgSrtId: The ID of the srting to be show.
 *---------------------------------------------------------------------------*/
	void popupBalloonMsg(VfxId aMsgSrtId);
	virtual void onClickedDev(VfxU32 index, const srv_bt_cm_dev_struct* dev_Info) = 0; 
/*---------------------------------------------------------------------------*
 * Function: setNotifyEvents()
 * Date:Nov/25/2011
 * Description: set notify events, and regist call back function to service.
 *    
 * Parameters
 *    @aEventMask: event group.
 *    @return: VFX_TURE is success
 *---------------------------------------------------------------------------*/
	VfxBool setNotifyEvents(VfxU32 aEventMask);
	virtual void handleBtEvents(VfxU32 event, void* para) = 0;
	
// Implementations:
private:
    
// Numbers:
protected:
	S32 m_serviceHandle; //service handle, if it is less than 0, it means invalid handle
    VcpListMenu*  m_btDevListMenu;
    srv_bt_cm_dev_type_enum 	m_devType;
private:
	VfxS32 			m_eventMask; //current notify event group mask.
};

/***************************************************************************** 
 * Declare VappBTSmallScr class
 * For showing bt popup(sending, confirm and indicating).
 *****************************************************************************/
class VappBTSmallScr : public VfxAppScr
{
public:
    VappBTSmallScr()
    {
        setIsSmallScreen();
		m_haveStatusBar = VFX_FALSE;
		m_statusBar = NULL;
    }
public:
	virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );
    virtual void onRotate(const VfxScreenRotateParam & param);
	void addStatusBar();
protected:
    virtual void onEntered(VfxBool isBackward);
	virtual void onExit(VfxBool isBackward);
// Variable
private:
    VcpStatusIconBar *m_statusBar;
	
	VfxBool m_haveStatusBar;
};


#endif /* __VAPP_BT_PAGE_H__ */
