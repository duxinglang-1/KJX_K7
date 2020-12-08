
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
 *  vapp_cal_group.h
 *
 * Project:
 * --------
 *  COSMOS
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CAL_GROUP_LIST_H__
#define __VAPP_CAL_GROUP_LIST_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

extern "C"
{
	#include "TodolistSrvGprot.h"
}

#include "vfx_weak_ptr.h"
#include "vfx_page.h"
#include "vfx_screen.h"

#include "vcp_list_menu.h"
#include "vcp_menu_popup.h"

#include "vapp_cal_prot.h"



/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

enum VAPP_CAL_G_LIST_ENTRY_TYPE
{
    VAPP_CAL_G_LIST_ENTRY_CALENDAR,
    VAPP_CAL_G_LIST_ENTRY_UC,
    VAPP_CAL_G_LIST_ENTRY_TOTAL
};


/***************************************************************************** 
 * Class VappCalGroupListPage
 *****************************************************************************/
class VcpToolBar;
class VcpMenuPopup;
class VcpConfirmPopup;
class VcpTitleBar;
class VappCalMainViewPage;

class VappCalGroupListPage : public VfxPage, public IVcpGroupListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappCalGroupListPage);

public:
    VappCalGroupListPage(){};
    
    VappCalGroupListPage(VAPP_CAL_G_LIST_ENTRY_TYPE type) : m_entryType(type),m_opListWeakPtr(NULL),m_confirmPopupWeakPtr(NULL){};

public: 
    
    enum
    {
        VAPP_CAL_G_LIST_ADD,
        #ifdef __MMI_CAL_EXPIRY__
        VAPP_CAL_G_LIST_EXPIRED,
        #endif
        VAPP_CAL_G_LIST_SEARCH,
        VAPP_CAL_G_LIST_DELETE,
        #ifdef __MMI_SNS_CALENDAR__  
        VAPP_CAL_G_LIST_FILTER,
        VAPP_CAL_G_LIST_MORE,
        #endif
        VAPP_CAL_SEL_LIST_MARK_ALL,
        VAPP_CAL_SEL_LIST_DELETE,
        VAPP_CAL_SEL_LIST_CANCEL
    }VAPP_CAL_G_LIST_ACTION;

    enum
    {
        VAPP_CAL_G_LIST_INCOMING,
        VAPP_CAL_G_LIST_OLD,
        VAPP_CAL_G_LIST_TOTAL
    }VAPP_CAL_G_LIST_INDEX;
    
    
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onBack();
    virtual void onEnter(VfxBool isBackward);

    virtual void onEntered();
    
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    
    virtual VfxBool getItemText(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    
    virtual VfxBool getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );
        
    virtual VfxU32 getCount(VfxU32 group) const;
    virtual VfxU32 getGroupCount() const;
    
    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    
    virtual VcpListMenuItemStateEnum getItemState(
        VcpMenuPos pos   // [IN] position of the item
        ) const;
    
    virtual VfxBool hasGroupHeader(VfxS32 group) const;
    
public:
    void closeJob();
    void GetSnsData();
    //void GetSnsData(srv_tdl_event_source_enum type);
    static mmi_ret updateSNSListData(mmi_event_struct *param);
    VcpGroupListMenu * GetlistMenu() const;
#ifdef __MMI_SNS_CALENDAR__
    void onFilterListPageBack(VfxU32 index,VfxU32 selIndex);
#endif
    void onToolBarClicked(VfxObject *sender, VfxId id);
    void onListMenuClicked(VcpGroupListMenu *sender, VcpMenuPos pos);
    void onSelListMenuClicked(
                        VcpGroupListMenu * sender, 
                        VcpMenuPos pos,        
                        VcpListMenuItemStateEnum state);
    void onListMenuLongTap(VcpGroupListMenu *sender, VcpMenuPos pos);
    void onOpListClicked(VcpMenuPopup* sender, VcpMenuPopupEventEnum evtEnum, VcpMenuPopupItem* item);
    void onSelListDelConfirm(VfxObject* sender, VfxId id);
    void onLongPressDelConfirm(VfxObject* sender, VfxId id);
    
    VfxU16 getTotalCount() const;
    //VfxU16 getExpiredCount();
    void setSelListState(VcpListMenuItemStateEnum state);
    void updateCalGroupListPageInt();
    void setDataChangeState(VfxBool state);
    VfxBool getDataChageState();


public:
    
#if defined(__MMI_VCALENDAR__)
    static mmi_ret updateCalGroupListPage(mmi_event_struct *param);
#endif
    static mmi_ret updateCalEventGroupListPage(mmi_event_struct *param);
    void closeDeletePopup();
    
public:
    VfxBool m_markAllBtn;            // this flag used to distinguish button is mark-all or unmark-all


private:
    VcpTitleBar *m_titleBar;
    VcpToolBar *m_toolBar;
    VcpGroupListMenu *m_listMenu;

    VfxU16 m_listCount[VAPP_CAL_G_LIST_TOTAL];
    VfxU16 m_markedCount;
    VfxBool m_isMutiDelProcessing;   // whether muili deletion
    //VfxBool m_isDataChanged;         // the flag that group list is changed
    VfxBool m_isNoDeleteDataChanged; // the flag that the data is updated or added, but not deleted
    VcpMenuPos m_selPos;
    VAPP_CAL_G_LIST_ENTRY_TYPE m_entryType;
    
    VfxWeakPtr<VcpMenuPopup> m_opListWeakPtr;
    VfxWeakPtr<VcpConfirmPopup> m_confirmPopupWeakPtr;
    srv_tdl_event_source_enum m_fliterid;
    VfxS32 m_jobId[VAPP_CAL_G_LIST_TOTAL]; 
    VcpListMenuItemStateEnum* m_listEventSel[VAPP_CAL_G_LIST_TOTAL];
    VfxU32 m_totalcount;
    VfxU16 m_stringId;
    srv_tdl_event_id_struct *m_eventbuffer[VAPP_CAL_G_LIST_TOTAL] ;
    VfxBool m_multiDel;

    VfxWChar *path;

#ifdef __MMI_SNS_CALENDAR__
    srv_tdl_event_source_enum m_selIndex;
#endif



};
#ifdef __MMI_CAL_EXPIRY__
/***************************************************************************** 
 * Class VappCalExpiredListPage
 *****************************************************************************/
class VcpToolBar;
class VappCalListMgr;
class VappCalExpiredListPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappCalExpiredListPage);

public:
    enum
    {
        VAPP_CAL_LIST_DELETE,
        VAPP_CAL_SEL_LIST_MARK_ALL,
        VAPP_CAL_SEL_LIST_DELETE,
        VAPP_CAL_SEL_LIST_CANCEL
    }VAPP_CAL_LIST_ACTION;

public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onBack();

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxU32 getCount() const;

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );
    
    VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

    virtual VfxBool getMenuEmptyText(
                        VfxWString &text,               
                        VcpListMenuTextColorEnum &color);

public:
    static mmi_ret updateSNSListData(mmi_event_struct *param);
    void closeDeletePopup();

    void setDataChangeState(VfxBool isChanged);
    void GetSnsData(srv_tdl_event_source_enum type);
    VcpListMenu*  GetlistMenu() const;

    void onToolBarClicked(VfxObject *sender, VfxId id);
    void onListMenuClicked(VcpListMenu *sender, VfxU32 index);
    void onSelListMenuClicked(
                        VcpListMenu * sender, 
                        VfxU32 index,        
                        VcpListMenuItemStateEnum state);
    void onSelListDelConfirm(VfxObject* sender, VfxId id);
    void onListMenuLongTap(VcpListMenu *sender, VfxId id);
    void onOpListClicked(VcpMenuPopup* sender, VcpMenuPopupEventEnum evtEnum, VcpMenuPopupItem* item);
    void onLongPressDelConfirm(VfxObject* sender, VfxId id);
    void updateCalExpiredListPageInt();
public:
    static mmi_ret updateCalExpiredListPage(mmi_event_struct *param);

public:
    VfxBool m_markAllBtn;            // this flag used to distinguish button is mark-all or unmark-all

    VfxBool m_isMarkAll;


private:
    VcpTitleBar *m_titleBar;
    VcpToolBar *m_toolBar;
    VcpListMenu *m_listMenu;
    VappCalListMgr *m_listMgr;
    VfxBool m_isMutiDelProcessing;     
    VfxU16 m_selIdx;
    VfxU16 m_dataChangedType;

    VfxS32 m_jobId; 
    VfxU32 m_count;
    srv_tdl_event_id_struct *m_eventbuffer ;
    VfxU16 m_stringId;
    VcpListMenuItemStateEnum *m_listEventSel;
    VfxU16 m_markedCount;
    VfxBool m_isDataChange;
    
    VfxWeakPtr<VcpMenuPopup> m_opListWeakPtr;
    VfxWeakPtr<VcpConfirmPopup> m_confirmPopupWeakPtr;
};
#endif


#ifdef __MMI_SNS_CALENDAR__
class VappCalFliterListPage : public VfxPage, public IVcpListMenuContentProvider
{
public:
        VappCalFliterListPage(VappCalGroupListPage *page, srv_tdl_event_source_enum selIndex):m_page(page),m_selIndex(selIndex){};
        VappCalFliterListPage():m_page(NULL){};
        virtual void onInit();
        virtual void onDeinit();
        virtual VfxBool getItemText(
            VfxU32 index,           // [IN] the index of item
            VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
            VfxWString &text,           // [OUT] the text resource
            VcpListMenuTextColorEnum &color  // [OUT] the text color
            );

        virtual VfxU32 getCount() const;

        virtual VfxBool getItemImage(
                VfxU32 index,            // [IN] the index of item
                VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                VfxImageSrc &image         // [OUT] the image resource
                );

        virtual VfxBool getMenuEmptyText(
                        VfxWString &text,
                        VcpListMenuTextColorEnum &color);

        VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

    public:
        void onListMenuClicked(VcpListMenu *sender, VfxU32 index);

    private:
        void updateListData();
        VcpListMenu *m_listMenu;
        VappCalGroupListPage *m_page;
        srv_tdl_event_source_enum m_selIndex;

    public:
        VfxSignal2<VfxU32,VfxU32> m_signalFilterListItemTap;

};



#endif






#endif  /*__VAPP_CAL_GROUP_LIST_H__*/

