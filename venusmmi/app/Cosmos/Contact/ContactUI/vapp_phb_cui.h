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
 *  vapp_phb_cui.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __PB_CUI_H__
#define __PB_CUI_H__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vcp_include.h"
#include "vcp_tabctrl_page.h"

#include "vapp_phb_list.h"
#include "vapp_phb_editor.h"
#include "vapp_phb_info.h"
#include "vapp_phb_group.h"
#include "vcui_phb_gprot.h"


/***************************************************************************** 
 * Class VappPhbListCuiData
 *****************************************************************************/ 
class VappPhbListCuiData : public VfxBase
{
public:
    VappPhbListCuiData():
        m_groupId(MMI_PHB_INVALID_GROUP_ID),
        m_thisGroup(VFX_FALSE),
        m_fieldMask(MMI_PHB_CONTACT_FIELD_NAME | MMI_PHB_CONTACT_FIELD_NUMBER | MMI_PHB_CONTACT_FIELD_EMAIL),
        m_reqCount(1),
        m_storageMask(0),
        m_userData(0),
        m_titleStr(VFX_WSTR_RES(VAPP_PHB_STR_CONTACTS))
    {
    }

    VfxU8 m_groupId;
    VfxBool m_thisGroup;
    VfxU32 m_fieldMask;
    VfxU32 m_reqCount;
    VfxU32 m_storageMask;
    VfxU32 m_userData;
    VfxWString m_titleStr;
};


/***************************************************************************** 
 * Class VappPhbListCuiSelector
 *****************************************************************************/ 
class VappPhbListCuiSelector
{
public:
    virtual VfxU32 getSelectedCount() = 0;

    virtual mmi_phb_contact_id getId(VfxU32 index = 0) = 0;

    virtual void getName(VfxWChar* name, VfxU32 length, VfxU32 index = 0) = 0;

    virtual void getData(VfxWChar* data, VfxU32 length, VfxU32 index = 0) = 0;

    virtual void getDataType(VfxU32* type, VfxU32* subType, VfxU32* subId, VfxU32 index = 0) = 0;

public:
    VfxSignal2<VappPhbListCuiSelector*, VfxBool> m_signalSelected;
};


/***************************************************************************** 
 * Class VappPhbListCui
 *****************************************************************************/ 
class VappPhbListCui : public VfxCui
{
    VFX_DECLARE_CLASS(VappPhbListCui);

public:
    VappPhbListCui();

    void setReqField(VfxU32 fieldMask);

    VfxU32 getReqField() const;

    void setReqCount(VfxU32 count);

    VfxU32 gettReqCount() const;

    void setListType(vcui_phb_list_type_enum type);

    vcui_phb_list_type_enum getListType() const;
	
#ifdef __MMI_PHB_CALLER_GROUP__
    void setGroupField(VfxU8 groupId, VfxBool thisGroup);
#endif /* __MMI_PHB_CALLER_GROUP__ */

    void setUserData(VfxU32 userData);

    VfxU32 getUserData();

    VfxU32 getSelectedCount() const;

    mmi_phb_contact_id getId(VfxU32 index = 0);

    void getName(VfxWChar* name, VfxU32 length, VfxU32 index = 0);

    void getData(VfxWChar* data, VfxU32 length, VfxU32 index = 0);

    void getDataType(VfxU32 *type, VfxU32 *sub_type, VfxU32 *sub_id, VfxU32 index = 0);
    
    void setDragNCenterFlag(VfxBool dragNCenter);

public:
    virtual void onRun(void* args, VfxU32 argSize);

    void onSelectedDone(VappPhbListCuiSelector* selector, VfxBool success);

protected:
     using VfxApp:: onProcessClose;
     virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);
     

public:
    VappPhbListCuiData m_data;
    vcui_phb_list_type_enum m_listType;
    VappPhbListCuiSelector *m_selector;
    VfxBool m_dragNCenter;
};


/***************************************************************************** 
 * Class VappPhbListCuiScr
 *****************************************************************************/ 
class VappPhbListCuiScr : public VfxMainScr
{
public:
    VappPhbListCuiScr();

protected:
    virtual void on1stReady();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

    virtual void onEnter(VfxBool isBackward);

    virtual void onExit(VfxBool isBackward);

private:
    VcpTabCtrlPage *m_tabCtrlPage;

private:
    void onGroupTaped(VfxU8 groupId, VfxWString groupName);
};


/***************************************************************************** 
 * Class VappPhbListCuiSingleSelectorPage
 *****************************************************************************/ 
class VappPhbListCuiSingleSelectorPage : public VfxPage, public VappPhbListCuiSelector
{
public:
    VappPhbListCuiSingleSelectorPage(): m_list(NULL), m_titleBar(NULL){}

    virtual VfxU32 getSelectedCount();

    virtual mmi_phb_contact_id getId(VfxU32 index = 0);

    virtual void getName(VfxWChar* name, VfxU32 length, VfxU32 index = 0);

    virtual void getData(VfxWChar* data, VfxU32 length, VfxU32 index = 0);

    virtual void getDataType(VfxU32* type, VfxU32* subType, VfxU32* subId, VfxU32 index = 0);

    void onItemTaped(VcpGroupListMenu *list, VcpMenuPos pos);

    VappPhbListCp* getListCp();

    void setTitle(const VfxWString& title);

protected:
    virtual void onInit();

    virtual void onBack();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    VappPhbListCp *m_list;
    VcpTitleBar   *m_titleBar;
    mmi_phb_contact_id m_id;
    VfxU32 m_fieldType;
    VfxU32 m_subId;
};


/***************************************************************************** 
 * Class VappPhbListCuiWithGroupSingleSelectorPage
 *****************************************************************************/
#ifdef __MMI_PHB_CALLER_GROUP__
class VappPhbListCuiWithGroupSingleSelectorPage : public VcpTabCtrlPage
{
public:
    enum VappPhbListCuiTabType
    {
        PHB_LIST_CUI_TAB_CONTACT = 1,
        PHB_LIST_CUI_TAB_GROUP
    };

    void setTitle(VfxWString& str);

protected:
    virtual void onInit();

    virtual VfxPage *onCreateTabPage(VfxId tabId);

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

    virtual void onRotate(const VfxScreenRotateParam &param);

public:
    VfxSignal2<VfxU8, VfxWString> m_signalGroupTaped;
};
#endif

/***************************************************************************** 
 * Class VappPhbListCuiMultiSelectorPage
 *****************************************************************************/
class VappPhbListCuiMultiSelectorPage : public VfxPage, public VappPhbListCuiSelector
{
public:
    enum VappPhbListCuiCmdType
    {
        PHB_LIST_CUI_CONTACT_CMD_OK,
        PHB_LIST_CUI_CONTACT_CMD_CANCEL
    };

public:
    VappPhbListCuiMultiSelectorPage();

    void setTitle(const VfxWString& title);
    
#ifdef __MMI_PHB_CALLER_GROUP__
    // for group member list
    void setGroupId(VfxU8 groupId);
#endif /* __MMI_PHB_CALLER_GROUP__ */

    virtual VfxU32 getSelectedCount();

    virtual mmi_phb_contact_id getId(VfxU32 index = 0);

    virtual void getName(VfxWChar* name, VfxU32 length, VfxU32 index = 0);

    virtual void getData(VfxWChar* data, VfxU32 length, VfxU32 index = 0);

    virtual void getDataType(VfxU32* type, VfxU32* subType, VfxU32* subId, VfxU32 index = 0);

    void onToolBarClick(VfxObject *obj, VfxId id);

    void onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state);

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    void onListCountChanged(VappPhbListCp* list, VfxU32 count);
#endif

protected:
    virtual void onInit();

    virtual void onEntered();

    virtual void onBack();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void configToolBar();

private:
    VappPhbListCp *m_list;
    VcpTitleBar   *m_titleBar;
    VcpToolBar    *m_toolBar;
};


/***************************************************************************** 
 * Class VappPhbListCuiWithGroupMultiSelectorPage
 *****************************************************************************/
#ifdef __MMI_PHB_CALLER_GROUP__ 
class VappPhbListCuiWithGroupMultiSelectorPage : public VcpTabCtrlPage
{
public:
    enum VappPhbListCuiTabType
    {
        PHB_LIST_CUI_TAB_CONTACT = 1,
        PHB_LIST_CUI_TAB_GROUP
    };

    void setTitle(VfxWString& str);

protected:
    virtual void onInit();

    virtual VfxPage *onCreateTabPage(VfxId tabId);

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

    virtual void onRotate(const VfxScreenRotateParam &param);

public:
    VfxSignal2<VfxU8, VfxWString> m_signalGroupTaped;
};
#endif  /* __MMI_PHB_CALLER_GROUP__ */

/***************************************************************************** 
 * Class VappPhbListCuiTabGroupPage
 *****************************************************************************/ 
#ifdef __MMI_PHB_CALLER_GROUP__

class VappPhbListCuiTabGroupPage : public VfxPage
{
public:
    VappPhbListCuiTabGroupPage();

    void onItemTaped(VcpListMenu* list, VfxU32 id);

protected:
    virtual void onInit();

    virtual void onBack();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    VappPhbGroupListCp *m_groupList;
    ContactGroupManager *m_groupManager;
};
#endif /* __MMI_PHB_CALLER_GROUP__ */


/***************************************************************************** 
 * Class VappPhbViewContactCui
 *****************************************************************************/ 
class VappPhbViewContactCui : public VfxCui
{
    VFX_DECLARE_CLASS(VappPhbViewContactCui);

public:
#ifdef __MMI_PHB_NEED_SERIALZE__
    typedef struct
    {
        mmi_phb_contact_id m_id;
        mmi_id             m_groupId;
        //VfxBool            m_isRestore;
    }VcuiViewUCSerialize;
#endif
    VappPhbViewContactCui(): m_id(MMI_PHB_INVALID_CONTACT_ID){}

    void setId(mmi_phb_contact_id id);

    mmi_phb_contact_id getId() const;

    void setSubAppId(vcui_phb_viewer_type_enum type);

    vcui_phb_viewer_type_enum getSubAppId() const;

    void* getUserData(vcui_phb_viewer_type_enum type);

    void setUserData(void* userData, vcui_phb_viewer_type_enum type);

public:
    virtual void onRun(void* args, VfxU32 argSize);
#ifdef __MMI_PHB_NEED_SERIALZE__
    virtual void onSerialize(void * hint,VfxArchive & ar);
    virtual void onRestore(VfxArchive & ar);
#endif
    //static mmi_ret eventHandler(mmi_event_struct *event);
private:
    mmi_phb_contact_id m_id;
    vcui_phb_viewer_type_enum m_subAppId;
    void* m_profileUserData;
    void* m_clogUserData;
    void* m_messageUserData;
#ifdef __MMI_PHB_NEED_SERIALZE__
    VcuiViewUCSerialize m_archive;
#endif

};


/***************************************************************************** 
 * Class VappPhbLocateSimCui
 *****************************************************************************/ 
class VappPhbLocateSimCui : public VfxCui
{
    VFX_DECLARE_CLASS(VappPhbLocateSimCui);
#ifdef __MMI_PHB_NEED_SERIALZE__
    typedef struct
    {
        mmi_phb_contact_id m_id;
        mmi_id             m_groupId;
        //VfxBool            m_isRestore;
    }VappPhbSimCuiSerialize;
#endif
public:
    VappPhbLocateSimCui(): m_id(MMI_PHB_INVALID_CONTACT_ID){}

#ifdef __MMI_PHB_NEED_SERIALZE__
    virtual void onSerialize(void * hint,VfxArchive & ar);

    virtual void onRestore(VfxArchive & ar);
#endif

    void setId(mmi_phb_contact_id id);

    VfxU16 getId() const;

public:
    virtual void onRun(void* args, VfxU32 argSize);

private:
    mmi_phb_contact_id m_id;
#ifdef __MMI_PHB_NEED_SERIALZE__
    VappPhbSimCuiSerialize m_archive;
#endif
};

#endif /* __PB_CUI_H__ */

