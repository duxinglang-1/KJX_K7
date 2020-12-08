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
 *  vapp_clog_ui.h
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CALL_LOG_UI_H__
#define __VAPP_CALL_LOG_UI_H__
 
 
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_tabctrl_page.h"
#include "vcp_button_util.h"
#include "vcp_list_menu.h"
#include "vcp_menu_popup.h"
#include "vfx_input_event.h"
#include "vcp_photo_border_frame.h"

#include "vapp_clog_data_provider.h"
#include "vapp_clog_action.h"
#ifdef __MMI_CLOG_MARK_SEVERAL__
#include "vapp_clog_multi_delete.h"
#endif

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#include "mmi_features.h"
#include "MMI_include.h"
#include "MMIDataType.h"
#include "CallLogSrvGprot.h" 
}
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    VAPP_CLOG_BTN_VIEW_CONTACT,
    VAPP_CLOG_BTN_SAVE_TO_CONTACT,
    VAPP_CLOG_BTN_CALL_VOICE_SIM1,
    VAPP_CLOG_BTN_CALL_VOICE_SIM2,
    VAPP_CLOG_BTN_CALL_VOICE_SIM3,
    VAPP_CLOG_BTN_CALL_VOICE_SIM4,
    VAPP_CLOG_BTN_CALL_SELECT,
    VAPP_CLOG_BTN_CALL_VIDEO,
    VAPP_CLOG_BTN_EDIT_BEFORE_CALL,
    VAPP_CLOG_BTN_SEND_MSG, // SIM1
    VAPP_CLOG_BTN_SEND_MSG_SIM2,
    VAPP_CLOG_BTN_SEND_MSG_SIM3,
    VAPP_CLOG_BTN_SEND_MSG_SIM4,
    VAPP_CLOG_BTN_SEND_MSG_SELECT,
    VAPP_CLOG_BTN_SEND_MSG_NO_SIM,
    VAPP_CLOG_BTN_DELETE,                 // delete one log
    VAPP_CLOG_BTN_DELETE_FOR_ONE_CONTACT, // delete logs of one contact
    VAPP_CLOG_BTN_DELETE_ALL,             // delete All or Missed, Todo
#if defined(__MMI_CM_BLACK_LIST__) && defined(__OP01__)
    VAPP_CLOG_BTN_VIEW_BLACK_LIST,
#endif
    VAPP_CLOG_BTN_END_OF_ENUM
} VappCLogButtonIDEnum;

typedef enum
{
    VAPP_CLOG_PAGE_BASIC,         // Basic call log list page
    VAPP_CLOG_PAGE_FOR_DIALER,    // for Dialer APP
    VAPP_CLOG_PAGE_FOR_CONTACT,   // List all log info of the same one contact, which is one page of contact profile
    VAPP_CLOG_PAGE_END_OF_ENUM
} VappCLogPageTypeEnum;


typedef enum
{
    VAPP_CLOG_LIST_ID_ALL_CALL,
    VAPP_CLOG_LIST_ID_MISSED_CALL,       
    VAPP_CLOG_LIST_ID_TOTAL
} VappCLogListIDEnum;

typedef enum
{
#if defined(__MMI_MAINLCD_480X800__) 
    VAPP_CLOG_LEFT_GAP = 14,
    VAPP_CLOG_RIGHT_GAP = 14,
    VAPP_CLOG_TOP_GAP = 14,
#elif defined(__MMI_MAINLCD_320X480__)  
    VAPP_CLOG_LEFT_GAP = 8,
    VAPP_CLOG_RIGHT_GAP = 8,
    VAPP_CLOG_TOP_GAP = 10,
#else
    VAPP_CLOG_LEFT_GAP = 5,
    VAPP_CLOG_RIGHT_GAP = 5,
    VAPP_CLOG_TOP_GAP = 8,
#endif
} VappCLogDiesmonEnum;

#ifdef __MMI_CLOG_MARK_SEVERAL__
typedef enum 
{
    VAPP_CLOG_LIST_NORMAL,
    VAPP_CLOG_LIST_MARK,
    VAPP_CLOG_LIST_TYPE_TOTAL
}VappCLogListModeEnum;
#endif

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern void vapp_clog_check_nmgr_alert(void);


/***************************************************************************** 
 * Define
 *****************************************************************************/
extern VfxS32 vapp_clog_check_phb_id(mmi_phb_contact_id id);

/***************************************************************************** 
 * Class for Basic
 *****************************************************************************/

class VappCLogList : public VfxPage, public IVcpListMenuContentProvider
{
public:
    
	/*
    typedef VappCLogListIDEnum  CLogListIDEnum;
    #define    CLOG_LIST_ID_ALL_CALL        VAPP_CLOG_LIST_ID_ALL_CALL
    #define    CLOG_LIST_ID_MISSED_CALL        VAPP_CLOG_LIST_ID_MISSED_CALL

    typedef VappCLogPageTypeEnum  CLogPageTypeEnum;
    #define    CLOG_PAGE_BASIC        VAPP_CLOG_PAGE_BASIC
    #define    CLOG_PAGE_FOR_DIALER        VAPP_CLOG_PAGE_FOR_DIALER
    #define    CLOG_PAGE_FOR_CONTACT        VAPP_CLOG_PAGE_FOR_CONTACT*/

public:
   //  VappCLogList();
    VappCLogList(VappCLogPageTypeEnum pageType = VAPP_CLOG_PAGE_BASIC ,
                 VfxBool b2ndReady = VFX_FALSE, // for performance enhancement and only for VAPP_CLOG_PAGE_BASIC
                 VappCLogListIDEnum listID = VAPP_CLOG_LIST_ID_ALL_CALL,  // only for VAPP_CLOG_PAGE_BASIC             
                 VfxU16 store_idx = 0,          // only for VAPP_CLOG_PAGE_FOR_CONTACT
                 mmi_sim_enum sim_id = MMI_SIM1 // only for VAPP_CLOG_PAGE_FOR_DIALER
                 );

public:
    void setListID(VappCLogListIDEnum listID);
    
#ifdef __MMI_CLOG_MARK_SEVERAL__
    void setListMode(VappCLogListModeEnum mode);

    VcpListMenu *getListMenu() const;

    CLogMark *getMarked() const;

    void markAll();

    void unMarkAll();

    void onStateChanged(
            VcpListMenu *list,
            VfxU32 index,
            VcpListMenuItemStateEnum state);

    void onMultiDeleteStart();

    void onMultiDeleteEnd();
#endif
    
// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
#ifdef __MMI_CLOG_MARK_SEVERAL__
    virtual void onBack();
#endif
    void showlistscreen(VfxTimer *timer);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

    // Set the list menu pointer to content provider
    virtual void setMenu(VcpListMenu *menu) {m_CLogList = menu;};

    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
                        VfxU32 index,                    // [IN] the index of item
                        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                        VfxWString &text,                // [OUT] the text resource
                        VcpListMenuTextColorEnum &color  // [OUT] the text color
                        );    

    // Get the image resource for the image fields of list cell
    virtual VfxBool getItemImage(
                        VfxU32 index,                    // [IN] the index of item
                        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                        VfxImageSrc &image              // [OUT] the image resource
                        );
    
    virtual VcpListMenuCmdStateEnum getItemCmdState(
                        VfxU32 index    // [IN] index of the item
                        ) const;

 #ifdef __MMI_CLOG_MARK_SEVERAL__   
    virtual VcpListMenuItemStateEnum getItemState(
                        VfxU32 index    // [IN] index of the item
                        ) const;
 #endif
    
    // Get the item count of the list menu
    virtual VfxU32 getCount() const;

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        );

    // Get the empty text resource for the text when list menu is empty
    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    // For performance enhancement
    void updatePage();

public:
#ifdef __MMI_CLOG_MARK_SEVERAL__ 
    VfxSignal0 m_listUpdated;
#endif

private:
    void initToolBar();
    void updataToolBarStatus();
    void onBoundsChanged(VfxFrame *frame, const VfxRect &old);
    void onToolBarClick(VfxObject* sender, VfxId id);
    void onListCmdBtnClick(
            VcpListMenu *, // Sender
            VfxU32         
            );
    
    void onCntxMenuClick(
            VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item);

    // handler when log item is short tapped
    void onItemShortTapped(
            VcpListMenu *list,          // [IN] ListMenu pointer
            VfxU32 index                // [IN] The selected menu item
            );
    // handler when log item is long tapped
    void onItemLongTapped(
            VcpListMenu *list,          // [IN] ListMenu pointer
            VfxU32 index                // [IN] The selected menu item
            );

    static mmi_ret onPhbContactChanged(mmi_event_struct *param);
    void onUpdatePageForContact();
    void onUpdateClogList(void *evt);

    VfxBool isToday(const VfxU32 &timestamp, VfxDateTime &logTime) const;

    void regListener();
    void deregListener();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    void onTimeChanged(VfxU32 flag);
    
private:

    // Button ID in List Page
    enum ListButtonEnum
    {
        SEGMENT_BTN_ALL_CALL,
        SEGMENT_BTN_MISSED_CALL,
    #ifdef __MMI_CLOG_MARK_SEVERAL__ 
        BOTTOM_BTN_DELETE,
    #else
        BOTTOM_BTN_CLEAR,        
    #endif
        LIST_BUTTON_END_OF_ENUM
    };

    enum TopControlEnum
    {
        LEFT_GAP = VAPP_CLOG_LEFT_GAP,
        RIGHT_GAP = VAPP_CLOG_RIGHT_GAP,
    #if defined(__MMI_MAINLCD_480X800__)
        TOP_CONTROL_HEIGHT = 86,
        MAIN_STR_FONT = 38,
        STR_BTN_GAP = 10,
        BTN_HEIGHT = 70,
        BTN_WIDTH = 105,
        BTN_UP = 8,
        MAIN_STR_WIDTH = LCD_WIDTH - LEFT_GAP - RIGHT_GAP - STR_BTN_GAP - BTN_WIDTH,
    #elif defined(__MMI_MAINLCD_320X480__)  
        TOP_CONTROL_HEIGHT = 52,
        MAIN_STR_FONT = 24, 	   
        STR_BTN_GAP = 5,
        BTN_HEIGHT = 40,
        BTN_WIDTH = 66,
        BTN_UP = 6,
        MAIN_STR_WIDTH = LCD_WIDTH - LEFT_GAP - RIGHT_GAP - STR_BTN_GAP - BTN_WIDTH,
    #else
        TOP_CONTROL_HEIGHT = 45,
        MAIN_STR_FONT = 18, 	   
        STR_BTN_GAP = 5,
        BTN_HEIGHT = 38,
        BTN_WIDTH = 54,
        BTN_UP = 4,
        MAIN_STR_WIDTH = LCD_WIDTH - LEFT_GAP - RIGHT_GAP - STR_BTN_GAP - BTN_WIDTH,
    #endif
	
    };
    #define CONTACT_INFO_SEPERATOR_LINE_HEIGHT   2

private:
    VcpListMenu  *m_CLogList;
    VfxId m_currListID; //CLogListIDEnum
    VappCLogPageTypeEnum m_currPageType; // CLogPageTypeEnum
    VfxBool m_b2ndReady; // For performance enhancement
    SRV_CLOG_ID m_currClogItemID;
    VppCLogAction *m_action;
    VcpToolBar *m_toolBar;
    VfxFrame *m_seg_frame;
    VcpSegmentButton *m_segBtn;
    VfxU16 m_storeIndex;
    VappCLogDataProvider *m_clogDataSrv;
    mmi_sim_enum m_currSIMID; // only for Dialer -Calllog List, directly make call with this SIM card
    
    VfxTimer *m_showTimer; // ensure aleady show list screen

    VfxTextFrame *m_str;
    VcpButton *m_button;
	VfxS32 get_ret;
	VcpListMenuHistoryStruct   m_listHistory;
#ifdef __MMI_CLOG_MARK_SEVERAL__
    CLogMark *m_mark;
    VfxObject *m_deleteObj;
    VappCLogMarkCmdTypeEnum m_cmd;
#endif
};


/*****************************************************************************
 * Class VappCLogListMenuItemCell
 *****************************************************************************/

class VappCLogListMenuItemCell : public VcpListMenuCellIconQuintTextFrame
{
// Override
public:

    // <group DOM_ListMenu_VcpListMenuCellIconQuintTextFrame_Override>
    virtual void onLayoutElements();

public:
    enum // CT means Call Log Type, dialled, received, missed
    {
    #if defined(__MMI_MAINLCD_480X800__)    
        CT_IMG_TOP_GAPS      = TEXT1_TOP_GAPS + 3,/* algin with main text */
        CT_IMG_LEFT_GAPS     = 14,
        CT_IMG_RIGHT_GAPS    = 14,
        CT_IMG_MAX_WIDTH     = 23,
    #elif defined(__MMI_MAINLCD_320X480__)        
        CT_IMG_TOP_GAPS      = TEXT1_TOP_GAPS + 2,
        CT_IMG_LEFT_GAPS     = 8,
        CT_IMG_RIGHT_GAPS    = 8,
        CT_IMG_MAX_WIDTH     = 15,
    #else        
        CT_IMG_TOP_GAPS      = TEXT1_TOP_GAPS,
        CT_IMG_LEFT_GAPS     = 5,
        CT_IMG_RIGHT_GAPS    = 5,
        CT_IMG_MAX_WIDTH     = 15,
    #endif    
    };

};


/***************************************************************************** 
 * Class for Dailer/Contact calllog page
 *****************************************************************************/

/*class VappCLogListEx : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappCLogListEx);

public:
    VappCLogListEx();
    VappCLogListEx(VappCLogPageTypeEnum pageType,           
                 VfxU16 store_idx = 0,          // only for CLOG_PAGE_FOR_CONTACT
                 mmi_sim_enum sim_id = MMI_SIM1 // only for CLOG_PAGE_FOR_DIALER
                 );
    
// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    void showlistscreen(VfxTimer *timer);
    virtual VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
    static mmi_ret onPhbContactChanged(mmi_event_struct *param);

    // Set the list menu pointer to content provider
    virtual void setMenu(VcpListMenu *menu) {m_CLogList = menu;};

    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
                        VfxU32 index,                    // [IN] the index of item
                        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                        VfxWString &text,                // [OUT] the text resource
                        VcpListMenuTextColorEnum &color  // [OUT] the text color
                        );    

    // Get the image resource for the image fields of list cell
    virtual VfxBool getItemImage(
                        VfxU32 index,                    // [IN] the index of item
                        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                        VfxImageSrc &image              // [OUT] the image resource
                        );
    
    // Get the item count of the list menu
    virtual VfxU32 getCount() const;

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        );

    // Get the empty text resource for the text when list menu is empty
    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
   
private:

    // handler when log item is short tapped
    void onItemShortTapped(
            VcpListMenu *list,          // [IN] ListMenu pointer
            VfxU32 index                // [IN] The selected menu item
            ); 

    void onUpdatePageForContact();
    void onUpdateClogList(void *evt);

    VfxBool isToday(const VfxU32 &timestamp, VfxDateTime &logTime) const;

    void regListener();
    void deregListener();
    mmi_ret onProc(mmi_event_struct *evt);
    void onTimeChanged(VfxU32 flag);

private:
    VcpListMenu  *m_CLogList;
    VappCLogPageTypeEnum m_currPageType; // CLogPageTypeEnum
    SRV_CLOG_ID m_currClogItemID;
    VppCLogAction *m_action;
    VfxU16 m_storeIndex;
    VappCLogDataProvider *m_clogDataSrv;
    mmi_sim_enum m_currSIMID; // only for Dialer -Calllog List, directly make call with this SIM card
    
    VappCLogListTopControl *m_topContrl;
    VfxTimer *m_showTimer; // ensure aleady show list screen
public:
    enum TopControlEnum
    {
        LEFT_GAP = VAPP_CLOG_LEFT_GAP,
        RIGHT_GAP = VAPP_CLOG_RIGHT_GAP,
    #if defined(__MMI_MAINLCD_480X800__)
        TOP_CONTROL_HEIGHT = 86,
        MAIN_STR_FONT = 38,
        STR_BTN_GAP = 10,
        BTN_HEIGHT = 70,
        BTN_WIDTH = 105,
        BTN_UP = 8,
        MAIN_STR_WIDTH = LCD_WIDTH - LEFT_GAP - RIGHT_GAP - STR_BTN_GAP - BTN_WIDTH,
    #elif defined(__MMI_MAINLCD_320X480__)  
        TOP_CONTROL_HEIGHT = 52,
        MAIN_STR_FONT = 24,        
        STR_BTN_GAP = 5,
        BTN_HEIGHT = 40,
        BTN_WIDTH = 66,
        BTN_UP = 6,
        MAIN_STR_WIDTH = LCD_WIDTH - LEFT_GAP - RIGHT_GAP - STR_BTN_GAP - BTN_WIDTH,
    #else
        TOP_CONTROL_HEIGHT = 45,
        MAIN_STR_FONT = 18,        
        STR_BTN_GAP = 5,
        BTN_HEIGHT = 38,
        BTN_WIDTH = 54,
        BTN_UP = 4,
        MAIN_STR_WIDTH = LCD_WIDTH - LEFT_GAP - RIGHT_GAP - STR_BTN_GAP - BTN_WIDTH,
    #endif
        
    };
    #define CONTACT_INFO_SEPERATOR_LINE_HEIGHT   2
private:
    VfxTextFrame *m_str;
    VcpButton *m_button;    
};*/


/*****************************************************************************
 * Class VappCLogListMenuItemExCell
 *****************************************************************************/

class VappCLogListMenuItemExCell : public VcpListMenuCellIconTripleTextFrameEx
{
// Override
public:

    virtual void onLayoutElements();

protected:
    enum // CT means Call Log Type, dialled, received, missed
    {
        CT_IMG_LEFT_GAPS   = VappCLogListMenuItemCell::CT_IMG_LEFT_GAPS,
        CT_IMG_TOP_GAPS    = VappCLogListMenuItemCell::CT_IMG_TOP_GAPS,/* algin with main text */
        CT_IMG_RIGHT_GAPS  = VappCLogListMenuItemCell::CT_IMG_RIGHT_GAPS,
        CT_IMG_MAX_WIDTH   = VappCLogListMenuItemCell::CT_IMG_MAX_WIDTH,
    };

};


/*****************************************************************************
 * Class VappCLogDetail
 *****************************************************************************/
class VappCLogDetail : public VfxPage
{
public:
    VappCLogDetail(){};
    VappCLogDetail(const srv_clog_log_struct & log);
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    void showlistscreen(VfxTimer *timer);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    void clearUnreadMissedCount();
    
    void regListener();
    void deregListener();
   // mmi_ret listener(mmi_event_struct* evt);
    void onUpdateForm(void *evt);
    virtual VfxBool onKeyInput(VfxKeyEvent & event);

private:
	enum CreateComboTypeEnum
    {
        COMBO_BUTTON_CALL,
        COMBO_BUTTON_MSG,
        COMBO_BUTTON_TOTAL_ITEMS
    };

    void creatForm();
    void creatLogIDCard();
    void onPhotoClicked();
    void creatLogType();
   // void creatMultiCallBtn();
	void createMultiBtn(CreateComboTypeEnum type, VfxId id); 
#if defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__)
    void createVideoCallBtn();
#endif
    void createEditBeforeCallBtn();
   // void createMsgBtn();
    void creatToolBar();
    void updatePhbToolBar();
    void updateBtnStatus();
	virtual mmi_ret onProc(mmi_event_struct *evt);
    void creatComboButton(VcpComboButton *btn, CreateComboTypeEnum type);
    void updateComboButtonStatus(VcpComboButton *btn, CreateComboTypeEnum type, VfxS32 sim_count);
    VfxId getButtonId(mmi_sim_enum sim_id, CreateComboTypeEnum type);
    //VfxResId getButtonIconId(mmi_sim_enum sim_id, CreateComboTypeEnum type);
    void onButtonClicked(VfxObject* sender, VfxId btnID);
    void onChildButtonClicked(VcpButton* sender, VfxId btnID);
    void onCntxMenuClick(VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item);

public:
    enum FormItemIdEnum
    {
        PAGE_CAPTION,
        LOG_NAME_NUMBER,
        LOG_TYPE,
        LOG_TIMESTAMP,
        DETAIL_INFO,
        THREE_CALL_BTN,
    #if defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__)
        VIDEO_CALL_BTN,
    #endif
        EDIT_BEFORE_CALL_BTN,
        SEND_MSG_BTN,        
        TOTAL_ITEMS
    };

    
private:
    VcpForm *m_form;
    srv_clog_log_struct m_logItem;
    VppCLogAction *m_action;
    VappCLogDataProvider *m_clogDataSrv;
    mmi_sim_enum m_perferSIM[COMBO_BUTTON_TOTAL_ITEMS]; // one for call, another for message
    VfxU8 m_insertSIM; // bit-wise of SIM inserted
    VcpComboButton * m_callBtn;
#if defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__)
    VcpButton *m_callVideoBtn;
#endif
    VcpButton *m_editBeforeCallBtn;
    VcpComboButton *m_msgBtn;
    //VcpComboButton *m_multiBtn;
    VfxTimer *m_showTimer; // ensure aleady show list screen 
};

// Include call log name, number, contact image, or default image
class VappCLogDetailIDCard: public VcpFormItemBase
{
public:

    // Constructor/Destructor
    VappCLogDetailIDCard();

    // Override
	virtual void onInit();

    void setText(const srv_clog_call_log_struct & log);

    enum
    {
        LEFT_GAP = VAPP_CLOG_LEFT_GAP,
        RIGHT_GAP = VAPP_CLOG_RIGHT_GAP,
    #if defined(__MMI_MAINLCD_480X800__)
        IMG_TOP_GAP = 14,
        IMG_WIDTH = 90,
        IMG_HEIGHT = 90,
        CELL_HEIGHT = IMG_HEIGHT + IMG_TOP_GAP * 2,
        IMG_STR_GAP = 18,
        MAIN_STR_POS_X = LEFT_GAP + IMG_WIDTH + IMG_STR_GAP,
        MAIN_STR_POS_Y = 18 + 8, /* algin with the top of Image */
        MAIN_STT_FONT = 35,
        SUB_STR_POS_X = MAIN_STR_POS_X,
        SUB_STR_POS_Y = 67,
        SUB_STT_FONT = 26,
    #elif defined(__MMI_MAINLCD_320X480__)
        IMG_TOP_GAP = 6,
        IMG_WIDTH = 48,
        IMG_HEIGHT = 48,
        CELL_HEIGHT = IMG_HEIGHT +  IMG_TOP_GAP * 2,
        IMG_STR_GAP = 10,
        MAIN_STR_POS_X = LEFT_GAP + IMG_WIDTH + IMG_STR_GAP,
        MAIN_STR_POS_Y = 8 + 6,
        MAIN_STT_FONT = 22,
        SUB_STR_POS_X = MAIN_STR_POS_X,
        SUB_STR_POS_Y = 38 + 2,
        SUB_STT_FONT = 14,
    #else
        IMG_TOP_GAP = 5,
        IMG_WIDTH = 42,
        IMG_HEIGHT = 42,
        CELL_HEIGHT = IMG_HEIGHT +  IMG_TOP_GAP * 2,
        IMG_STR_GAP = 7,
        MAIN_STR_POS_X = LEFT_GAP + IMG_WIDTH + IMG_STR_GAP,
        MAIN_STR_POS_Y = 7,
        MAIN_STT_FONT = 18,
        SUB_STR_POS_X = MAIN_STR_POS_X,
        SUB_STR_POS_Y = 32,
        SUB_STT_FONT = 13,    
    #endif
    };

public:
    VcpPhotoBorderFrame *m_photoBorder;
private:
    VfxTextFrame *m_str;
    VfxTextFrame *m_subStr;
    VfxBool      m_isContact;
};


// include Call type, starttime, duration, sim used
class VappCLogDetailInfo: public VcpFormItemBase, public IVcpListMenuContentProvider
{
public:

    // Constructor/Destructor
    VappCLogDetailInfo(){};
    VappCLogDetailInfo(const srv_clog_call_log_struct & calllog);

    // Override
	virtual void onInit();
    void setClog(const srv_clog_call_log_struct & calllog, VfxBool needKeepViewState = VFX_FALSE);

    
    // Set the list menu pointer to content provider
    virtual void setMenu(VcpListMenu *menu) {m_timeList = menu;};

    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
                        VfxU32 index,                    // [IN] the index of item
                        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                        VfxWString &text,                // [OUT] the text resource
                        VcpListMenuTextColorEnum &color  // [OUT] the text color
                        );    
    
    // Get the item count of the list menu
    virtual VfxU32 getCount() const;

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        );

    // Get the empty text resource for the text when list menu is empty
    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    enum
    {
        LEFT_GAP = VAPP_CLOG_LEFT_GAP,
        RIGHT_GAP = VAPP_CLOG_RIGHT_GAP,
    #if (MMI_MAX_SIM_NUM == 1)
        LINE_COUNT = 3,
    #else
        LINE_COUNT = 4,
    #endif    
    #if defined(__MMI_MAINLCD_480X800__)
        TOP_GAP = 25,
        BOTTOM_GAP = 25,
        STR_FONT = 26,
        SINGEL_LINE_STR_HEIGHT = 26,
        LINE_GAP = 26,        
        CELL_HEIGHT = TOP_GAP + LINE_COUNT * SINGEL_LINE_STR_HEIGHT + (LINE_COUNT - 1) * LINE_GAP + BOTTOM_GAP,
    #elif defined(__MMI_MAINLCD_320X480__)
        TOP_GAP = 12,
        BOTTOM_GAP = 12,
        STR_FONT = 18,
        SINGEL_LINE_STR_HEIGHT = 20,
        LINE_GAP = 12,
        CELL_HEIGHT = TOP_GAP + LINE_COUNT * SINGEL_LINE_STR_HEIGHT + (LINE_COUNT - 1) * LINE_GAP + BOTTOM_GAP,
    #else
        TOP_GAP = 10,
        BOTTOM_GAP = 10,
        STR_FONT = 13,
        SINGEL_LINE_STR_HEIGHT = 13,
        LINE_GAP = 5,
        CELL_HEIGHT = TOP_GAP + LINE_COUNT * SINGEL_LINE_STR_HEIGHT + (LINE_COUNT - 1) * LINE_GAP + BOTTOM_GAP,
    #endif
    };

private:
    srv_clog_call_log_struct m_clog;
    VfxTextFrame *m_textFrame;
    
    VcpListMenu *m_timeList;
};


class VappCLogDetailType: public VcpFormItemBase
{
public:

    // Constructor/Destructor
    VappCLogDetailType(){};
    VappCLogDetailType(VfxU8 which_type, VfxU8 which_sim);

    // Override
	virtual	void onInit();
    
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        CELL_HEIGHT = 42,
        STR_FONT_SIZE = 20,
    #elif defined(__MMI_MAINLCD_480X800__)
        CELL_HEIGHT = 62,
        STR_FONT_SIZE = 30,
    #else
        CELL_HEIGHT = 36,
        STR_FONT_SIZE = 16,
    #endif
    };

private:
    VfxU8 m_logType;
    VfxU8 m_logSim;
};


/*****************************************************************************
 * Class VappCLogDetailTimeListItemCell
 *****************************************************************************/

class VappCLogDetailTimeListItemCell : public VcpListMenuCellMultiTextFrameEx
{
// Override
public:
    //virtual void onLayoutElements();
    virtual void onUpdateTextFrameStyle(VcpListMenuFieldEnum fieldType, VfxTextFrame *frame);
    virtual void onUpdateTextViewStyle(VcpListMenuFieldEnum fieldType, VcpTextView *frame);

    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        ITEM_HEIGHT = 30,
        SRT_FONT_SIZE  = 14,
    #elif defined(__MMI_MAINLCD_480X800__)
        ITEM_HEIGHT = 42,
        SRT_FONT_SIZE  = 21,
    #else
        ITEM_HEIGHT = 26,
        SRT_FONT_SIZE  = 12,
    #endif
    };
};



#endif /* __VAPP_CALL_LOG_UI_H__ */



