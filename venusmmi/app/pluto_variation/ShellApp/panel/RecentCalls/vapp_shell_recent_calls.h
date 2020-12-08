/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *  Vapp_Shell_Recent_Calls.h
 * 
 * Project:
 * --------
 *  Venus Shell
 * 
 * Description:
 * ------------
 *  Shell Recent Calls provides users with the convenience of quick accessing 
 *  the recent call logs, including incoming calls, out going calls and missed
 *  calls, without having to open the Kernel Call log app
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SHELL_RECENT_CALLS__
#define __VAPP_SHELL_RECENT_CALLS__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_Features.h"
#ifdef __MMI_VUI_SHELL_RECENT_CALLS__


#include "ShellApp\base\vapp_shell_panel.h"

/* auto add by kw_check begin */
#include "vapp_shell_panel.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_string.h"
#include "vfx_date_time.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vcp_list_menu.h"
#include "vcp_tab_bar.h"
#include "vcp_popup.h"
#include "vfx_weak_ptr.h"
#include "vfx_text_frame.h"
#include "vfx_primitive_frame.h"
#include "vfx_class_info.h"
#include "vfx_image_src.h"
#include "vfx_signal.h"
#include "vfx_frame.h"
/* auto add by kw_check end */

#ifdef __cplusplus
extern "C"
{
#include "mmi_rp_app_venus_shell_recent_calls_def.h"    
#include "UCMGprot.h"
#include "CalllogSrvGprot.h"
#include "custom_phb_config.h"
#include "MMIDataType.h"

}
#endif

typedef enum
{
    VAPP_SHELL_RC_LIST_ALL = 0,    // The first tabbar, All calls
    VAPP_SHELL_RC_LIST_MISSED = 1,     // The second tabbar, Missed calls
    VAPP_SHELL_RC_LIST_TOTAL = 2       // End of enum
}VappShellRCListMenuEnum;

typedef enum
{
    VAPP_SHELL_RC_TYPE_DIALED,
    VAPP_SHELL_RC_TYPE_MISSED,
    VAPP_SHELL_RC_TYPE_RECVED
}VappShellRCLogTypeEnum;

// Recent calls structure information
typedef struct
{
    VfxU8            cate;               // Call log, SMS log, NWPD log
    VfxU8            sim_id;             // MMI_SIM1, MMI_SIM2
    VfxU8            log_type;           // Dialed, Missed, Recved, (Reject)
    VfxU8            sub_type;           // Voice, Video, VOIP

    VfxBool          is_phb_contact;     // VFX_FALSE : not exist in PHB, or else
    SRV_PHB_ID       phb_id;
    VfxU16           unread_count;       // Only for missed unread call count
    VfxWString       name;               // Log name
    VfxWString       number;             // Log cid
    VfxDateTime      time;               // Start time, timestamp
    VfxU32           timestamp;          // timestamp
    void            *user_data;
}VappShellRCInfo;


class VappShellRCDataProvider;
/*****************************************************************************
 * Class VfxShape
 *****************************************************************************/

/*
 * VappShellRC is a class that can describe screen with recent calls.
 *
 * EXAMPLE
 * <code>
 * </code>
 */
class VappShellRC : public VappShellPanel
{
    VAPP_SHELL_PANEL_CREATE(VappShellRC, VFX_FALSE);

    
// Constructor / Destructor
public:
    // Default constructor
    VappShellRC();

// Override
public:
    // This function is used to get icon id which will be used in changing shell order
    virtual VfxS32 getPanelStrId() { return VAPP_SHELL_STR_RECENT_CALLS;};

    // called after bootup
    virtual void onInit();
    
    // called before shutdown
    virtual void onDeinit();

    // init view. application can create components here
    virtual void onInitView();
    
    // deinit view. applicaiton can close components which are created in onInitView stage
    virtual void onDeinitView();
    
    // enter view. Application can create components which waste lots of resources here
    virtual void onEnterView();
    
    // exit view. Application can release those resources which is obtained in onEnterView
    virtual void onExitView(ShellExitCauseEnum cause);

// Method
public:

private:
    void regListener();
    void deregListener();
    static mmi_ret listener(mmi_event_struct* evt);

    void enterRCPanel();
    
// Implementation
private:

	void getMyBounds(VfxRect &appBound);

    void onUpdateList(
        VappShellRCDataProvider *rcDP,   //[IN]
        VfxId updateListIdx              //[IN]
    );

    void onChangeList(
        VfxObject *tabBar,
        VfxId     tabIdx
    );

    void setIsHideList(
        VfxU32   unhideIdx      //[IN] Set this index List to unhide, other lists to hide
    );
    
    // This function is the event hander when the recent call is changed.
    void onRCItemChanged(
        const VfxU32 &index     //[IN] The list index
    );

    // This function is the event handler when a recent calls item is selected.
    void onTabRCItem(
        VcpListMenu *list,          // [IN] ListMenu pointer
        VfxU32 index                // [IN] The selected menu item
    );

    // This function is the event handler when the mobile's time is changed. In
    // this situation, we might need to change the hint string of the list item.
    void onTimeChanged(
        VfxU32 flag     // [IN] Bit-OR flag indicating the change
    );

    // After tap one recent call item, show commandpopup options menu
    void showCmdPopup(const VfxU32 &logItemIdx);

    // After press button on VcpCommandPopup, entry this handler function
    void onClickCmdBtn(VfxObject *obj, VfxId id);

    // Press "Call" in VcpCommandPopup, will make MO call
    void makeCall(const VfxWChar *number);
    static void makeCallCb(mmi_ucm_after_make_call_cb_struct* cb_para);

    // Press "Send message" in VcpCommandPopup, will send UC msg
    void sendSms(const VfxWChar *number);

    // Press "Add new contact" or "Replace existing" in VcpCommandPopup, both will call this function
    void saveContact(const VfxWChar *number, VfxBool is_voip, VfxU32 save_type);

    // This function updates the help text of this shell.
    // RETURN VALUES:
    // VFX_TRUE     : Indicate show help text
    // VFX_FALSE    : Indicate show nothing and display VvpListMenu
    VfxBool updateHelpText(VfxU32 listIdx);


// Define
private:

    typedef enum
    {
        CMD_MENU_CALL,
        CMD_MENU_SEND_MSG,
        CMD_MENU_ADD_NEW_CONTACT,
        CMD_MENU_REPLACE_CONTACT,
        CMD_MENU_CANCEL,
        CMD_MENU_TOTAL
    }CmdPopupMenuEnum;

	typedef enum
    {
	#ifdef __MMI_MAINLCD_320X480__
        GAP_MIN_X = 15,  // gap between screen left edge and my panel
		GAP_MIN_Y = 15,  // gap between status icon bar and my panel
		GAP_MAX_X = 15,  // gap between screen right edge and my panel
		GAP_MAX_Y = 15,  // gap between below shortcut and my panel
	#else
		GAP_MIN_X = 11,  // gap between screen left edge and my panel
		GAP_MIN_Y = 11,  // gap between status icon bar and my panel
		GAP_MAX_X = 11,  // gap between screen right edge and my panel
		GAP_MAX_Y = 11,  // gap between below shortcut and my panel
	#endif
		GAP_SHADOW = 10, // gap between shadow bg and my panel 
		GAP_TOTAL
    }GapEnum;

// Variable
private:
    
    VcpTabBar           *m_tabBar;
    VcpListMenu         *m_RCList[VAPP_SHELL_RC_LIST_TOTAL];    

    VfxWeakPtr<VcpCommandPopup> m_cmdPopupWeakPtr;
	VfxTextFrame *m_helpText;
    
    VappShellRCDataProvider *m_RCDataProvider;
    // Currently, highlight ListMenu index (All or Missed calls)
    VfxU32               m_currListIdx;
    VfxU32               m_currListLogIdx;
    VfxBool              m_firstInitFlag;
    VfxBool              m_realEnterRCPanel;
	  
	VfxImageFrame        *m_bgImage;
	VfxImageFrame        *m_bgShadow;
	VfxImageFrame        *m_bgTopBorder;
	VfxImageFrame        *m_bgTailBorder;
	  
	SRV_PHB_ID           m_tabRCItemPhbID;
};


/*****************************************************************************
 * Class VappShellRCDataProvider
 ****************************************************************************/

/*
 * VappShellRCDataProvider implement to provide the list menu cell content.
 *
 * EXAMPLE
 * <code>
 * </code>
 */
class VappShellRCDataProvider : public VfxObject, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappShellRCDataProvider);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappShellRCDataProvider);

// Constructor / Destructor
public:
    // Default constructor
    VappShellRCDataProvider();

// Implement
public:
    void setCurrListIdx(VfxU32 currListIdx);
    VfxU32 getCurrListIdx(void) const;

    VfxBool isToday(const VfxDateTime &time) const;
    VfxBool isCurrYear(const VfxDateTime &time) const;

    VfxBool getLogItem(VfxU32 logItemIdx);
    const VfxWString& getLogName() const;
    const VfxWString& getLogNumber() const;

    VfxU32 getSrvState();
    static VfxBool getLogIcon(VappShellRCInfo &log,  // [IN] the log data
					   VfxImageSrc &image     // [OUT] the image resource
			);
	void clearUnreadFlag() const;             // Clear unread missed calls flag and update status icon

    void processRCChanged(VfxU32 srvState, VfxU8 log_type);
    VfxSignal2 <VappShellRCDataProvider *, VfxId> m_signalRCChanged;

private:
	void createCLogInstance(SRV_CLOG_HANDLE &hdlr) const;

	
// Override
public:
    // Set the list menu pointer to content provider
    virtual void setMenu(VcpListMenu *);

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
        VfxImageSrc &image               // [OUT] the image resource
        );

    // Free the image resource for the image fields of list cell
    virtual void closeItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc Image               // [IN] the image resource
        ) {VFX_UNUSED(index);VFX_UNUSED(fieldType);VFX_UNUSED(Image);};

    // Get the item count of the lis menu
    virtual VfxU32 getCount() const;

    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const {VFX_UNUSED(index);return VCP_LIST_MENU_ITEM_STATE_NONE;};

    // Swap two items, user should update its internal data of the two items
    virtual VfxBool swapItem(
        VfxU32 index1, // [IN] index of the first item
        VfxU32 index2  // [IN] index of the second item
        ) {VFX_UNUSED(index1);VFX_UNUSED(index2);return 0;};

    // Get the content frame of the item, it's used when the cell style is 
    // VCP_LIST_MENU_CELL_STYLE_CUSTOM, uer should creat and layout its owned
    // cell content frame and return it here
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,   // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        ) {VFX_UNUSED(index); VFX_UNUSED(parentFrame); return NULL;};

    // Uer should release the resource of the content frame which is created by 
    // itself, such as image resource
    virtual void closeItemCustomContentFrame(
        VfxU32 index,                        // [IN] index of the item
        VcpListMenuCellClientBaseFrame *cell // [IN] the content frame to be released
        ) {VFX_UNUSED(index);VFX_UNUSED(cell);};


// Declaration
public:
    
    VappShellRCInfo           m_RCItemCache;

    typedef enum
    {
        SRV_NOT_READY,
        SRV_READY,
        SRV_UPDATED,
        SRV_STATE_TOTAL
    } SrvState;

 // Varible
private:

    VcpListMenu         *m_currList;
    VfxU32               m_currListIdx;
    VfxU32               m_srvState;
    
};


/***************************************************************************** 
 * Global Function
 *****************************************************************************/


#endif // __MMI_VUI_SHELL_RECENT_CALLS__
#endif // __VAPP_SHELL_RECENT_CALLS__

