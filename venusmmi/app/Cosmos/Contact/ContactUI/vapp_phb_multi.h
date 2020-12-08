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
 *  vapp_phb_multi.h
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#ifndef __PB_MULTI_H__
#define __PB_MULTI_H__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vcp_include.h"

#include "vapp_contact_group.h"
#include "vapp_phb_list.h"
#include "vapp_uc_gprot.h"
#include "vapp_phb_gprot.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "UcSrvGprot.h"

#ifdef __cplusplus
}
#endif


typedef enum
{
    PB_MULTI_CMD_SELECT,
    PB_MULTI_CMD_OP,
    PB_MULTI_CMD_CANCEL,
    PB_MULTI_CMD_TYPE_TOTAL
} vapp_phb_multi_cmd_type_enum;


typedef enum
{
    VAPP_PHB_MARK_CMD_NONE,
    VAPP_PHB_MARK_CMD_DELETE,
    VAPP_PHB_MARK_CMD_MESSAGE,
    VAPP_PHB_MARK_CMD_SHARE,
    VAPP_PHB_MARK_CMD_DELETE_GROUP,
    VAPP_PHB_MARK_CMD_DELETE_GROUP_MEMBER,
    VAPP_PHB_MARK_CMD_MOVE_GROUP_MEMBER,
    VAPP_PHB_MARK_CMD_TYPE_TOTAL
} vapp_phb_mark_cmd_type_enum;


/***************************************************************************** 
 * Class VappPhbMarkCmdInterface
 *****************************************************************************/ 
class VappPhbMarkCmdInterface
{
public:
    virtual void onCmdStart(vapp_phb_mark_cmd_type_enum cmd) = 0;
    virtual void onCmdEnd(vapp_phb_mark_cmd_type_enum cmd) = 0;

    vapp_phb_mark_cmd_type_enum m_cmd;
};


/***************************************************************************** 
 * Class VappPhbMarkDeleteObj
 *****************************************************************************/ 
class VappPhbMarkDeleteObj: public VfxObject
{
public:
    VappPhbMarkDeleteObj(VappPhbListCp* list, VfxPage *page, VappPhbMarkCmdInterface *cmd);

    void onToolBarClick(VfxObject* obj, VfxId id);

    void deleteDone();

    void onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state);

    void onTextChanged(VcpTextEditor *editor);

    void onListCountChanged(VappPhbListCp* list, VfxU32 count);

protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    VfxPage         *m_page;
    VappPhbListCp   *m_list;
    VcpToolBar      *m_tool;
    ContactMark     *m_mark;
    VappPhbMarkCmdInterface *m_cmd;

private:
    VappPhbMarkDeleteObj(){}

    void configToolBar();

    void closeSelf();
};

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
#endif 
/***************************************************************************** 
 * Class VappPhbMultiCopyObj
 *****************************************************************************/ 

class VappPhbMultiCopyObj: public VfxObject
{
	public:
		VappPhbMultiCopyObj(phb_storage_enum desStorage, phb_storage_enum srcStorage,VfxBool isImport, VfxMainScr *screen);
	
		void onToolBarClick(VfxObject* obj, VfxId id);
	
		void copyDone();
	
		void onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state);
	
		void onTextChanged(VcpTextEditor *editor);
	
		void onListCountChanged(VappPhbListCp* list, VfxU32 count);
	
	protected:
		virtual void onInit();
	
	private:
		phb_storage_enum m_desStorage;
		phb_storage_enum m_srcStorage;
		VfxBool m_isImport;
		VfxMainScr		*m_parent;
		VfxPage 		*m_page;
		VappPhbListCp	*m_list;
		VcpToolBar		*m_tool;
		ContactMark 	*m_mark;		
	
	private:

		void configToolBar();
	
		void closeSelf();


};


/***************************************************************************** 
 * Class VappPhbMarkMsgObj
 *****************************************************************************/
#ifdef __MMI_PHB_MARK_MESSAGE__

class VappPhbMarkMsgObj: public VfxObject
{
public:
    VappPhbMarkMsgObj(VappPhbListCp* list, VfxPage *page, VappPhbMarkCmdInterface *cmd);

    ContactMark* getMarkSet();

    void onToolBarClick(VfxObject* obj, VfxId id);

    void sendMsg();

    void onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state);

    void onListCountChanged(VappPhbListCp* list, VfxU32 count);

protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    VappPhbMarkMsgObj(){}

    void configToolBar();

    void closeSelf();

private:
    VfxPage *m_page;
    VappPhbListCp   *m_list;
    VcpToolBar      *m_tool;
    ContactMark     *m_mark;
    VappPhbMarkCmdInterface *m_cmd;
};
#endif /* __MMI_PHB_MARK_MESSAGE__ */

/***************************************************************************** 
 * Class VappPhbMarkShareObj
 *****************************************************************************/
	
#if defined (__MMI_OPP_SUPPORT__) && defined (__MMI_VCARD__)
class VappPhbMarkShareObj: public VfxObject
{
public:
    VappPhbMarkShareObj(VappPhbListCp* list, VfxPage *page, VappPhbMarkCmdInterface *cmd);

    void onToolBarClick(VfxObject* obj, VfxId id);

    void shareContact();

    void onListCountChanged(VappPhbListCp* list, VfxU32 count);

    void onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state);

protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    VfxPage *m_page;
    VappPhbListCp   *m_list;
    VcpToolBar      *m_tool;
    ContactMark     *m_mark;
    VappPhbMarkCmdInterface *m_cmd;

private:
    VappPhbMarkShareObj(){}

    void configToolBar();

    void closeSelf();

    enum
    {
        VAPP_PHB_SHARE_BY_BT,
        VAPP_PHB_SHARE_BY_TOTAL
    };
};
#endif /* __MMI_PHB_MARK_MESSAGE__*/

/***************************************************************************** 
 * Class VappPhbMarkDeleteGroupMemberObj
 *****************************************************************************/ 
#ifdef __MMI_PHB_CALLER_GROUP__ 
class VappPhbMarkDeleteGroupMemberObj: public VfxObject
{
public:
    VappPhbMarkDeleteGroupMemberObj(
        VappPhbListCp* list,
        VfxPage *page,
        VappPhbMarkCmdInterface *cmd,
        ContactGroupManager *groupManager,
        VfxU8 groupId);

    void onToolBarClick(VfxObject* obj, VfxId id);

    void onListCountChanged(VappPhbListCp* list, VfxU32 count);

    void onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state);

    void onGroupMemberDeleted(ContactGroupManager* manager);

protected:
    virtual void onInit();

private:
    VappPhbMarkDeleteGroupMemberObj(){}

    void configToolBar();

    void closeSelf();

private:
    VfxPage *m_page;
    VappPhbListCp   *m_list;
    VcpToolBar      *m_tool;
    ContactMark     *m_mark;
    VappPhbMarkCmdInterface *m_cmd;
    ContactGroupManager *m_groupManager;
    VfxU8 m_groupId;
    VcpIndicatorPopup *m_progress;
};
#endif /* MMI_PHB_CALLER_GROUP */


#if defined(__OP02__)
/***************************************************************************** 
 * Class VappPhbMarkMoveGroupMemberObj
 *****************************************************************************/ 
class VappPhbMarkMoveGroupMemberObj: public VfxObject
{
public:
    VappPhbMarkMoveGroupMemberObj(
        VappPhbListCp* list,
        VfxPage *page,
        VappPhbMarkCmdInterface *cmd,
        ContactGroupManager *groupManager,
        VfxU8 groupId);

    void onToolBarClick(VfxObject* obj, VfxId id);

    void onListCountChanged(VappPhbListCp* list, VfxU32 count);

    void onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state);

    void onGroupSelected(VfxObject* obj, VfxU8 groupId);

    void onGroupMemberMoved(ContactGroupManager* manager);

protected:
    virtual void onInit();

private:
    VappPhbMarkMoveGroupMemberObj(){}

    void configToolBar();

    void closeSelf();

private:
    VfxPage         *m_page;
    VappPhbListCp   *m_list;
    VcpToolBar      *m_tool;
    ContactMark     *m_mark;
    VappPhbMarkCmdInterface *m_cmd;
    ContactGroupManager *m_groupManager;
    VfxU8 m_groupId;
    VfxU16 m_groupCount;
    mmi_phb_contact_id m_groupIdArray[MMI_PHB_PHONE_ENTRIES];
};
#endif /* defined(__OP02__) */

#endif /* __PB_MULTI_H__ */

