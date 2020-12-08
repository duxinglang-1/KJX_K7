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
 * Vapp_cbs_msgs_page.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines class of CB app pages of venus.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
**********************************************************************************/

#ifndef __VAPP_CBS_MSGS_PAGE_H__
#define __VAPP_CBS_MSGS_PAGE_H__
#include "mmi_features.h"

#ifndef __cplusplus
#error "this header file can be used in C++ only."
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vapp_cbs_iprot.h"
typedef srv_sms_callback_struct cbsCallbackStruct;

#define VAPP_CBS_MSG_SUBJECT_LENGTH         40
/***************************************************************************** 
 * VappCbsMsgListPage
 *****************************************************************************/
class VappCbsMsgListPage : public VfxPage, public IVcpListMenuContentProvider
{
 // Declaration
    //VFX_DECLARE_CLASS(VappCbsMsgListPage);
    
public:
    // Constructor / Destructor
    VappCbsMsgListPage(VfxS32 sim, VfxId channel);

    //cntx
    VfxS32 getSim();
 //   void setSim(VappCbsSimEnum sim);
    //VfxId getChannel();
    //void setChannel(VfxId channel);
    void initMsgInfo();

// Method //delete channel 
    static mmi_ret msgChangeProc(mmi_event_struct *param);
    static mmi_ret channelChangeProc(mmi_event_struct *param);
    
    static void msgDeleteCallback(cbsCallbackStruct *callbackData);
    //void showList();
    void switchToViwePage();
    

// signal processing
    void onToolBarClick(VfxObject* sender, VfxId id);
    void onItemTouched(VcpListMenu *sender, VfxU32 index);
    void onListItemStateChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState);
    void eventHandler(VfxObject* obj, VfxId id);
    void errorConfirmEventHandler(VfxObject* obj, VfxId id);
    
    

protected:
//override
    virtual void onInit();
    virtual void onDeinit();
    virtual void onBack();
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);

//content provider
    virtual VfxBool getItemText(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxWString &text,
            VcpListMenuTextColorEnum &color
            );
    virtual VfxBool getMenuEmptyText(
        VfxWString & text,
        VcpListMenuTextColorEnum & color);
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
    
private:
    void deleteMsgs();
    void updateProcess();
    void selectAll(VfxBool isSelect);
    void deleteSelected();
    void switchToOptPage();
    void showErrorPrompt(VfxWString string);
    void fillDeleteData();
    void setTitle();   
//data cache // ui date cache
    void backupOriginIds();
	void backupOrignalSelection();
	void refreshDataAndKeepSelectionInfo();
    void resetMasks();
    void handleIfViewPageEmpty();
    VfxBool getSelectionByID(VfxId channelId) const;
    void fillMasks();
private:
    enum toolBarEnum
    {
        TO_DELETE = 0,
        
        ALL,
        DELETE,
        CANCEL
    };

// Variable
protected:
    VcpTitleBar *m_titleBar;
    VcpToolBar *m_toolBar;
	VcpListMenu *m_msgList;

	//cntx
	VfxS32 m_SIM;
	VfxId m_channel;
	
	//data cache and UI cache
    VfxId m_msgId[SRV_CBS_MAX_MSG_NUM];
    VfxU32 m_totalMsg;
    VfxId m_msgIdTemp[SRV_CBS_MAX_MSG_NUM];
    VfxU32 m_totalMsgTemp;
    
    VfxBool m_selectionMask[SRV_CBS_MAX_MSG_NUM];
    VfxU32 m_selectedNumber;
    VfxBool m_isReentry;
    VfxBool m_isAdding;
    VfxBool m_isDeleting;
    VfxBool m_isMulti;
    
    // DeleteChannelCntx
    VfxId m_msgToDelete[SRV_CBS_MAX_CHNL_NUM];
    VfxU32 m_totalToDelete;
    VfxU32 m_currDeleteIndex;
    
    //confirm and processing
    VcpConfirmPopup *m_confirmPopup;
    VcpIndicatorPopup *m_processingPopup;
 };
/* msg list page end */
#endif /* __VAPP_CBS_MSGS_PAGE_H__ */

