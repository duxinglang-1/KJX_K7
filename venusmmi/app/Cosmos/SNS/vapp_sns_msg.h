/*  Copyright Statement:
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
 *  vapp_sns_msg.h
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_SNS_MSG_H__
#define __VAPP_SNS_MSG_H__

#include "MMI_features.h"

#ifdef __MMI_SNS_MESSAGES__
#include "Vapp_sns_base.h"
#include "Vapp_sns_base_cp.h"

class VappSnsMsgLauncherCell : public VappSnsItemLauncherCell
{
    VFX_DECLARE_CLASS(VappSnsMsgLauncherCell);

// Constructor
public:
    VappSnsMsgLauncherCell(VcpMenuPos menuPos = VcpMenuPos(0, 0));

// Method
public:
    void setNumOfRecipients(VfxU32 numOfRecipients);
    VfxU32 getNumOfRecipients();
    static mmi_ret setMarkReadCb(mmi_event_struct *evt);

private:
    VfxU32 m_numRecipients;
};


class VappSnsMsgCaption : public VappSnsItemCaption
{
    VFX_DECLARE_CLASS(VappSnsMsgCaption);

// Constructor
public:
    VappSnsMsgCaption();

// Method
public:
    void setNumOfRecipients(VfxU32 numOfRecipients);
    VfxU32 getNumOfRecipients();

private:
    VfxU32 m_numRecipients;
};


class VappSnsMsgAgent : public VappSnsBaseAgent
{
    VFX_DECLARE_CLASS(VappSnsMsgAgent);

    enum VappSnsMsgQueryStatusEnum
    {
        VAPP_SNS_MSG_AGENT_QUERY_NONE = 0, 
        VAPP_SNS_MSG_AGENT_QUERY_LIST, 
        VAPP_SNS_MSG_AGENT_QUERY_MSG_INFO, 
        VAPP_SNS_MSG_AGENT_QUERY_END
    };

// Constructor
public:
    VappSnsMsgAgent();

// Method
public:
    void updateThreadListId(VfxBool isRefresh = VFX_FALSE, VfxU32 providers = SRV_SNS_PROVIDER_ALL);
    void updateMessageListId(VfxChar *threadId, VfxU32 provider, VfxBool getThreadInfo = VFX_FALSE);
    VfxS32 getThreadListId();
    VfxU32 getThreadListProviderId();
    VfxS32 getMessageListId();
    VfxU32 getMessageListProviderId();
    VfxChar *getSingleThreadId();
    VfxS32 getSingleThreadListId();
    VfxS32 getThreadList(VfxS16 &startIdx, VfxS16 &endIdx, VfxU16 &totalCount);
    VfxS32 getMessageList(VfxS16 &startIdx, VfxS16 &endIdx, VfxU16 &totalCount);
    VfxS32 getSingleThreadList(VfxS16 &startIdx, VfxS16 &endIdx, VfxU16 &totalCount);
    VfxS32 getList(VfxS32 listId, VfxS16 &startIdx, VfxS16 &endIdx, VfxU16 &totalCount);
    VfxS32 getThreadInfo(VfxU32 index, srv_sns_thread_struct *&itemInfo);
    VfxS32 getMessageInfo(VfxU32 index, srv_sns_message_struct *&itemInfo);
    VfxS32 getSingleThreadInfo(VfxU32 index, srv_sns_thread_struct *&itemInfo);
    VfxS32 getInfo(VfxS32 listId, VfxU32 index, void *&itemInfo);
    VfxBool isGettingList();
    VfxBool isGettingMsgInfo();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
public:
    virtual mmi_ret loadResultCb(mmi_event_struct *param);
    virtual mmi_ret loadItemResultCb(mmi_event_struct *param);

private:
    VfxS32 m_threadListId;
    VfxU32 m_threadListProviderId;
    VfxS32 m_messageListId;
    VfxU32 m_messageListProviderId;
    VfxS32 m_singleThreadListId;
    VfxChar *m_singleThreadId;
    VappSnsMsgQueryStatusEnum m_queryStatus;
};


class VappSnsMsgViewerPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappSnsMsgViewerPage);

// Constructor
public:
    VappSnsMsgViewerPage();

// Method
    void setInfo(VappSnsMsgLauncherCell *cellInfo);
    void updateInfo(VappSnsMsgLauncherCell *cellInfo);
    VappSnsItemTextView *getItem() { return m_item; };

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

// internal apis
private:
    void onEditorBoundsChanged(VfxFrame *obj, const VfxRect &rect);
    static mmi_ret onSrvEvtHandler(mmi_event_struct *param);

// member variables
private:
    VappSnsMsgCaption *m_caption;
    VappSnsItemTextView *m_item;
    VappSnsMsgSender *m_editor;
    VfxTextFrame *m_errorString;
};


class VappSnsMsgRecipientsPage : public VappSnsBasePage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappSnsMsgRecipientsPage);

// Constructor
public:
    VappSnsMsgRecipientsPage();

// Method
public:
    void setInfo(VfxChar *threadId, VfxU32 provider);

// provider
public:
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
        );
    virtual VfxBool getItemImage(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,           // [IN] position of the item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        );
    virtual VfxBool getMenuEmptyText(
        VfxWString & text,
        VcpListMenuTextColorEnum & color);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual void onItemUpdated(
        VfxS32 listId,
        VfxU16 index, 
        VappSnsItemUpdatedTypeEnum type, 
        VfxWChar *path
    );
    virtual void onGetLoadResults(VfxS32 listId, VfxU16 total, VfxS16 startIndex, VfxS16 endIndex);
    virtual void onSrvStatusChanged(VfxBool isReady, srv_sns_result result, VfxU32 listId);

private:
    VfxU32 m_provider;
    VfxChar *m_threadId;
    VcpListMenu *m_listMenu;
};
#endif /* __MMI_SNS_MESSAGES__ */
#endif /* __VAPP_SNS_MSG_H__ */
