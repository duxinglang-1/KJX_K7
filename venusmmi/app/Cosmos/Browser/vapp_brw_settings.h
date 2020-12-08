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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * VappBrowserMain.h
 *
 * Project:
 * --------
 *   MAUI
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

#ifndef _VAPP_BRW_SETTINGS_H_
#define _VAPP_BRW_SETTINGS_H_

#include "MMI_include.h"
#include "MMIDataType.h"

#ifdef __MMI_BROWSER_2__

#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */
#include "BrowserSrvInterface.h"
#include "BrowserSrvBookmarks.h"
#include "BrowserSrvGprot.h"
#include "BrowserSrvMain.h"
#include "BrowserSrvSettings.h"
#include "RestoreGprot.h"
#include "Wps_struct.h"
#ifdef __cplusplus
}
#endif /* __cplusplus */

#include "vcp_tabctrl_page.h"

/****************************************************************************
* Class VappTimeOutListcontentprovider
****************************************************************************/
typedef enum
{
	VAPP_BRW_TIMEOUT_VALUE_30_SEC = 0,
	VAPP_BRW_TIMEOUT_VALUE_60_SEC,
	VAPP_BRW_TIMEOUT_VALUE_120_SEC,
	VAPP_BRW_TIMEOUT_VALUE_180_SEC,
	VAPP_BRW_TIMEOUT_VALUE_240_SEC,
	VAPP_BRW_TIMEOUT_VALUE_300_SEC,
	VAPP_BRW_TIMEOUT_VALUE_TOTAL
}browser_time_out;

class VappTimeOutListcontentprovider : public VfxObject, public IVcpListMenuContentProvider
{
public:
	virtual void setMenu(VcpListMenu *)
	{
	}
	virtual VfxBool getItemText(
	VfxU32 index,                    // [IN] the index of item
	VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
	VfxWString &text,                // [OUT] the text resource
	VcpListMenuTextColorEnum &color  // [OUT] the text color
	);

	virtual VfxBool getItemImage(
	VfxU32 index,                    // [IN] the index of item
	VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
	VfxImageSrc &image              // [OUT] the image resource
	);

	virtual void closeItemImage(
	VfxU32 index,                    // [IN] the index of item
	VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
	VfxImageSrc Image               // [IN] the image resource
	)
	{
	// move to .cpp if required
	}

	virtual VfxU32 getCount()const
	{
		return VAPP_BRW_TIMEOUT_VALUE_TOTAL;
	} 

	// Get the state of a list item
	virtual VcpListMenuItemStateEnum getItemState(VfxU32 index)const;
};

//VFX_IMPLEMENT_CLASS("VappTimeOutListcontentprovider", VappTimeOutListcontentprovider, VfxObject);

class VappSearchEnginecontentprovider : public VfxObject, public IVcpListMenuContentProvider
{
	//VFX_DECLARE_CLASS(VappSearchEnginecontentprovider);
public:
	//VfxU32 m_id;
	virtual void setMenu(VcpListMenu *)
	{
	}
	virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

	virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

	virtual void closeItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc Image               // [IN] the image resource
		)
	{
	    // move to .cpp if required
	}

	virtual VfxU32 getCount()const
	{
		return 2;
	} 

	    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
		) const
	{
		srv_brw_search_engines_enum search_engine = srv_brw_read_search_engine();
		if(index == (VfxU32)search_engine)
			return VCP_LIST_MENU_ITEM_STATE_SELECTED;
		else
			return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}

	void m_signalListSearchItemTapped(VcpListMenu *listmenu, VfxU32 id);
};

//VFX_IMPLEMENT_CLASS("VappSearchEnginecontentprovider", VappSearchEnginecontentprovider, VfxObject);

class VappPrivateModecontentprovider : public VfxObject, public IVcpListMenuContentProvider
{
	//VFX_DECLARE_CLASS(VappPrivateModecontentprovider);
public:
	virtual void setMenu(VcpListMenu *)
	{
	}
	virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

	virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

	virtual void closeItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc Image               // [IN] the image resource
		)
	{
	    // move to .cpp if required
	}

	virtual VfxU32 getCount()const
	{
		VfxU32 UCount = 4;
		
		#ifdef __MMI_BRW_SLIM__ // no history
			UCount--;			
		#endif
		
		#ifdef SLIM_WAP_MMS // no cache
			UCount--;
		#endif
		
		return UCount;		
	} 
	
	virtual VfxBool getItemIsDisabled(
	VfxU32 index       // [IN] the index of item
	) const;

	    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
		) const;

	virtual void closeItemCustomContentFrame(
        VfxU32 index,  // [IN] index of the item
        VcpListMenuCellClientBaseFrame *cell // [IN] the content frame to be released
		);
	
	virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        );

	virtual VfxBool getItemIsHighlightable(VfxU32 index)const;


};

#if (defined (WAP_SEC_SUPPORT) && !defined (__LOW_COST_SUPPORT_COMMON__))
class VappTrustedCertificatescontentprovider: public VfxObject, public IVcpListMenuContentProvider
{
	//VFX_DECLARE_CLASS(VappTrustedCertificatescontentprovider);
public:
	

	virtual void setMenu(VcpListMenu *)
	{
	}
	virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
	{
		if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total != 0)
		{
		VfxWChar *bufPtr = text.lockBuf(300);
		mmi_asc_to_ucs2((CHAR*) bufPtr, (CHAR*) srv_brw_trusted_certificate_list_get_item(index));
		//text.format("%s", srv_brw_trusted_certificate_list_get_item((S32)index));
		//text = VFX_WSTR_STATIC((VfxWChar *)srv_brw_trusted_certificate_list_get_item(index));
		//text = VFX_WSTR_STATIC(bufPtr);
		text.unlockBuf();
		}
        return VFX_TRUE;
	}

	virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        )
	{
		return VFX_FALSE;
	}
	
	void ViewCertcallback(S32 user_data , U32 result, void* rsp_data);

	virtual void closeItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc Image               // [IN] the image resource
		)
	{
	    // move to .cpp if required
	}

	virtual VfxU32 getCount()const
	{
		return ((VfxU32) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total);
	} 

	    // Get the state of a list item

	virtual void closeItemCustomContentFrame(
        VfxU32 index,  // [IN] index of the item
        VcpListMenuCellClientBaseFrame *cell // [IN] the content frame to be released
		)
	{
	    // move to .cpp if required
	}
	
	virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        )
	{
		return NULL;
	}
	virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color)
	{
		text = VFX_WSTR_RES(STR_ID_VAPP_BRW_EMPTY_TRUSTED_CERT_LIST);
		return VFX_TRUE;
	}

};
#endif

//VFX_IMPLEMENT_CLASS("VappTrustedCertificatescontentprovider", VappTrustedCertificatescontentprovider, VfxObject);
/******* ends here ***********/
class VappBrwPrivateModeCustomFrame:public VcpListMenuCellClientBaseFrame
{
	//VFX_DECLARE_CLASS(VappBrwPrivateModeCustomFrame);
public:

	virtual void onCreateElements(void){}
	virtual void onCloseElements(void){}
	virtual void onLayoutElements(void){}
    virtual void onUpdateElements(void){}
};

class VfxAppBrowserSettingsInterface : public VfxObject
{
    //VFX_DECLARE_CLASS(VfxAppLauncher);

public:

	 static VfxSignal3<S32, U32, void *> m_dispatchCallback;
	 static void OnServiceRspCallback(S32 user_data , U32 result, void* rsp_data)
	 {
		VfxAppBrowserSettingsInterface::m_dispatchCallback.emit(user_data, result, rsp_data);
	 }
};
//VFX_IMPLEMENT_CLASS("VappBrwPrivateModeCustomFrame", VappBrwPrivateModeCustomFrame, VcpListMenuCellClientBaseFrame);

typedef enum
{
	BRW_SETTINGS_HEADER_ITEM_PREFERENCES = 0,
	BRW_SETTINGS_DATA_ITEM_SEARCH_ENGINE,
	BRW_SETTINGS_DATA_ITEM_TIME_OUT,
	BRW_SETTINGS_SELECT_ITEM_LOAD_IMAGES,
	BRW_SETTINGS_SELECT_ITEM_SELECT_MODE,
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    BRW_SETTINGS_SELECT_ITEM_USE_BAIDU_PROXY,
#endif /* #ifdef __BAIDU_TRANSCODING_SUPPORT__ */
	BRW_SETTINGS_HEADER_ITEM_PRIVACY_OPTIONS,
	BRW_SETTINGS_DATA_ITEM_PRIVATE_MODE,
	BRW_SETTINGS_DATA_ITEM_CLEAR_HISTORY,
#ifndef SLIM_WAP_MMS
	BRW_SETTINGS_DATA_ITEM_CLEAR_CACHE,
#endif // ? SLIM_WAP_MMS
	BRW_SETTINGS_DATA_ITEM_CLEAR_COOKIES,
	BRW_SETTINGS_HEADER_ITEM_ACCOUNT_OPTIONS,
#if 0
/* under construction !*/
#endif //0
	//BRW_SETTINGS_DATA_ITEM_SELECT_PROFILE,
	BRW_SETTINGS_DATA_ITEM_DATA_ACCOUNT,
	BRW_SETTINGS_HEADER_ITEM_SECURITY,
#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))
	BRW_SETTINGS_DATA_ITEM_VIEW_TRUSTED_CERTIFICATES,
#endif
	BRW_SETTINGS_DATA_ITEM_CLEAR_AUTHENTICATION_INFO,
	BRW_SETTINGS_HEADER_ITEM_RESTORE_SETTINGS,
	BRW_SETTINGS_DATA_ITEM_RESTORE_DEFAULT_SETTINGS
}setting_data_items_enum;

typedef enum
{
#ifndef __GOOGLE_SEARCH_SUPPORT__
    BRW_SETTINGS_SEARCH_ENGINE = 0,
	BRW_SETTINGS_TIME_OUT,
#else
	BRW_SETTINGS_TIME_OUT = 0,
#endif
	BRW_SETTINGS_PRIVATE_MODE,
#ifndef __MMI_BRW_SLIM__
	BRW_SETTINGS_CLEAR_HISTORY,
#endif
#ifndef SLIM_WAP_MMS
	BRW_SETTINGS_CLEAR_CACHE,
#endif // ? SLIM_WAP_MMS
	BRW_SETTINGS_CLEAR_COOKIES,
	BRW_SETTINGS_DATA_ACCOUNT,
#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))
	BRW_SETTINGS_VIEW_TRUSTED_CERTIFICATES,
#endif
	BRW_SETTINGS_CLEAR_AUTHENTICATION_INFO,
	BRW_SETTINGS_RESTORE_DEFAULT_SETTINGS
}setting_items_enum;
class VappSettingsPage : public VfxPage
{
    //VFX_DECLARE_CLASS(VappSettingsPage);
public:
    VcpForm *m_form;

    VcpFormItemLauncherCell *m_setting[9];
	VcpFormItemCaption *m_setting_header[5];

    VfxS32 m_ShowImagesTemp;
#if 0
/* under construction !*/
#endif //0
    VcpFormItemSwitchCell *m_switchTypeSetting;
#if 0
/* under construction !*/
#endif //0
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    VfxS8 m_UseBaiduProxyTemp;
    VcpFormItemSwitchCell *m_switchTypeBaiduProxySetting;
    VfxS8 m_resetBaiduProxysetting;
#endif /* __BAIDU_TRANSCODING_SUPPORT__ */
// Override

	VcpIndicatorPopup *m_popup;
	VcpConfirmPopup *m_confirm;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
	virtual void onInit();
	virtual void onDeinit();
	void onButtonClicked(VcpFormItemCell* sender, VfxId Id);
	void SwitchChangeReq(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus);
	#ifndef __MMI_BRW_SLIM__
	void onClearHistory(VfxObject* obj, VfxId id);
	#endif
	#ifndef SLIM_WAP_MMS
	void onClearCache(VfxObject* obj, VfxId id);
	#endif // ? SLIM_WAP_MMS
	void onClearCookies(VfxObject* obj, VfxId id);
	void onClearAuthenticationInfo(VfxObject* obj, VfxId id);
	static void OnDataClearCallback(S32 user_data, U32 result, void *obj);
	void UpdateHintText(VcpFormItemLauncherCell* item, VfxId id);
	void onRestoreBrowserSettings(VfxObject* obj, VfxId id);
	void RestoreProfileRspcallback(S32 user_data , U32 result, void* rsp_data);
	//virtual VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
	virtual void onRotate(const VfxScreenRotateParam &param);
    virtual void onEnter(VfxBool isBackward);
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    void onBaiduProxyConfirm(VfxObject* obj, VfxId id);    
#endif //#ifdef __BAIDU_TRANSCODING_SUPPORT__
};
typedef enum
	{
		BRW_STATIC_LIST_TYPE_SEARCH_ENGINE,
		BRW_STATIC_LIST_TYPE_TIMEOUT,
		BRW_STATIC_LIST_TYPE_PRIVATE_MODE,
		BRW_STATIC_LIST_TYPE_SELECT_PROFILE,
		BRW_STATIC_LIST_TYPE_DATA_ACCOUNT
#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))
		,BRW_STATIC_LIST_TYPE_TRUSTED_CERTFICATES
#endif
	}setting_static_list_enum;

enum
    {
        BRW_LIST_TOOLBAR_BUTTON_SAVE = 0,
        BRW_LIST_TOOLBAR_BUTTON_CANCEL
    };
class VappStaticListPage : public VfxPage
{
	//VFX_DECLARE_CLASS(VappStaticListPage);
public:
	
	enum
    {
        BRW_MENU_ID_SIM1 = 0,
        BRW_MENU_ID_SIM2,
        BRW_MENU_ID_ALWAYS_ASK,
#if 0
#ifdef __MMI_WLAN_FEATURES__
/* under construction !*/
#endif /* __MMI_WLAN_FEATURES__ */
#endif //0
    };

    VappStaticListPage()
    {};
    VappStaticListPage(VfxU32 index) : 
        m_list_type(index) 
    {};
	virtual void onInit();
	virtual void onDeinit();
	 VfxBool swapItem(
        VfxU32 index1, // [IN] index of the first item
        VfxU32 index2  // [IN] index of the second item
		)
	{
	    return VFX_FALSE;
	}
	
	
	VfxFrame *getContentFrame(
        VcpMenuPos pos        // [IN] index of the item
		)
	{
	    return NULL;
	}

	void onStaticListToolBarClick(VfxObject* sender, VfxId id);

	void m_signalListItemSelected(VcpListMenu *listmenu, VfxU32 id, VcpListMenuItemStateEnum state);
	// todo: relook private: done
	void updatelistmenu(void){}  /* Redraw UI on basis of data on APP */

	void refresh_list(void){}   /* Get fresh data from APP */

	VcpToolBar *m_tool_bar;
	VcpPagePanel *m_page_panel;
	VfxFrame *m_frame1;
	VcpTitleBar * titleBar;
	VcpIndicatorPopup *m_popup;

	void m_signalListItemTapped(VcpListMenu *, VfxU32);

	void m_signalListFocusChanged(VcpListMenu *, VfxU32,VfxU32){}

	VfxU32 m_list_type ;
	VfxU32 m_id;
	VfxBool m_sel_ids[3];
	VcpListMenu *m_list;
	U8 m_private_mode_setting;
	VcpSwitch *m_switch;
	void m_updateStaticListTitle(VcpTitleBar *titleBar);
	
	void set_private_mode_setting(U8 setting_id);

	U8 get_private_mode_setting(void);
	
	void m_updateStaticListSize();

	void m_updateStaticListStyle(void);

	void m_updateContentProvider(void);

	void m_updateStaticListToolBar(void);

	void UpdateStaticListSelectedItems(void);
	void switchCallback(VcpSwitch *abc, VfxBool status);
	virtual void onEnter(VfxBool isBackward);
	//virtual VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
	void PrivateModeRspcallback(S32 user_data , U32 result, void* rsp_data);
	virtual void onRotate(const VfxScreenRotateParam &param);
};

/********Viewer cell*********************/
class VcpFormItemViewerCell : public VcpFormItemBase 
{
    //VFX_DECLARE_CLASS(VcpFormItemViewerCell);

public:
    // Constructor/destructor
    //VcpFormItemViewerCell();
    //~VcpFormItemViewerCell();

    // Override
    virtual void onInit();
	virtual void onDeinit();
    //VfxBool onPenInput(const VfxPenEvent &event);

    // Variable
    VcpTextView *m_mainText;
    VfxFrame *m_separator;

	virtual void setMainText(const VfxWString &text);
	virtual void setText(const VfxWChar *text); 
  
};

#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))
class VappBrwTrustedCertViewerPage : public VfxPage
{
private:
    //VcpForm *m_form;

    //VcpFormItemViewerCell *m_cert_data[9];
	//VcpFormItemCaption *m_cert_header[4];
    //VfxS32 m_radioSelectIndex1;
    //VfxS32 m_radioSelectIndex2;
    //VcpFormItemSwitchCell *m_switchTypeSetting;
	VcpToolBar *m_tool_bar;
// Override
public:
	typedef struct
	{
		kal_uint8  issuer[256];
		kal_uint32 not_after;
		kal_uint32 not_before;
		kal_uint8  serial_num[128];
		kal_uint16 serial_num_len;
		kal_uint8  sig_alg_name[128];
		kal_uint8  subject[256];
		kal_uint8  type;
		kal_uint8  version;
	} mmi_brw_certificate_content_struct;
	VcpTextView *m_text;
	VfxWChar *m_bufPtr;
	VfxU32 m_index;
	mmi_brw_certificate_content_struct* m_trusted_cert_p;
	VappBrwTrustedCertViewerPage()
    {};
    VappBrwTrustedCertViewerPage(VfxU32 index) : 
        m_index(index) 
    {};
	VcpIndicatorPopup *m_popup;
	VcpConfirmPopup *m_confirm;
	
	void CopyTrustedCertViewerData(
        mmi_brw_certificate_content_struct *dest_p,
        wps_sec_cert_content_struct *src_p);

	virtual void onInit();
	virtual void onDeinit();
	void ViewCertcallback(S32 user_data, U32 result, void *obj);
	void onCertViewerToolBarClick(VfxObject* sender, VfxId id);
	void DeleteCertcallback(S32 user_data, U32 result, void *obj);
	void UpdatedCertListcallback(S32 user_data, U32 result, void *obj);
	//virtual VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    void certificateDeleteHandler(VfxObject* obj, VfxId id);
};
#endif
//VFX_IMPLEMENT_CLASS("VappStaticListPage", VappStaticListPage, VfxPage);

#endif /* __MMI_BROWSER_2__ */
#endif /* _VAPP_BRW_SETTINGS_H_ */
