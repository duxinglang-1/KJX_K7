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
 * Vapp_cbs_pages.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================

**********************************************************************************/

#ifndef __VAPP_CBS_CHANNEL_PAGE_H__
#define __VAPP_CBS_CHANNEL_PAGE_H__
#include "mmi_features.h"

#ifndef __cplusplus
#error "this header file can be used in C++ only."
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_cbs_iprot.h"

typedef srv_sms_callback_struct cbsCallbackStruct;
/***************************************************************************** 
 * VappCbsChannelListPage
 *****************************************************************************/
 class VappCbsChannelListPage : public VfxPage, public IVcpListMenuContentProvider
 {
 // Declaration
    //VFX_DECLARE_CLASS(VappCbsChannelListPage);
    
public:
    // Constructor / Destructor
    VappCbsChannelListPage(VfxS32 sim);
    VfxS32 getSim();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
// Method //delete channel 
    static mmi_ret channelChangeProc(mmi_event_struct *param);
    static void channelDeleteCallback(cbsCallbackStruct *callbackData);
    
protected:
//override
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
    virtual void onBack();
//content provider
    virtual VfxBool getItemText(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxWString &text,
            VcpListMenuTextColorEnum &color
            );

     virtual VfxBool getItemImage(
         VfxU32 index,
         VcpListMenuFieldEnum fieldType,
         VfxImageSrc &image
         );

     virtual VfxU32 getCount() const;
     
     virtual VcpListMenuItemStateEnum getItemState(
         VfxU32 index   // [IN] index of the item
         ) const;
         
     virtual VfxBool getMenuEmptyText(
        VfxWString & text,
        VcpListMenuTextColorEnum & color);

private:
    void deleteChannels();
    void updateProcess();
    void switchToOptPage();
    void switchToListPage();
    void selectAll(VfxBool isSelect);
    void fillDeleteData();
    void resetDeleteData();
    //void showErrorConfirm(VfxWString string);
//data cache // ui date cache
    void initChannelInfo();
    void resetMasks();
    VfxBool getSelectionByID(VfxId channelId) const;
    void fillMasks();
    VfxS32 getChannelIndexById(VfxU32 channelId);
    void handleIfListPageEmpty();

// signal processing
    void onToolBarClick(VfxObject* sender, VfxId id);
    void onItemButtonTouched(VcpListMenu * sender,VfxU32 index);
    void errorConfirmEventHandler(VfxObject* obj, VfxId id);
    void onItemTouched(VcpListMenu *sender, VfxU32 index);
    void onListItemStateChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState);
    void eventHandler(VfxObject* obj, VfxId id);
    void onCanceled(VfxObject* obj, VfxFloat curr_progress);
    void processingPopupKeyHandler(VfxObject* obj, VfxId evt);

    void createAndShowEditor(VfxBool isNew, srv_cbs_chnl_entry_struct *channel = NULL);

private:
    enum toolBarEnum
    {
        ADD = 0,
        TO_DELETE,
        
        ALL,
        DELETE,
        CANCEL
    };

// Variable
private:
    VcpToolBar *m_toolBar;
	VcpListMenu *m_channelList;
	VfxS32 m_SIM;
	//data cache and UI cache
    srv_cbs_channel_struct m_channelInfo;
    VfxId m_channelId[SRV_CBS_MAX_CHNL_NUM];
    VfxBool m_selectionMask[SRV_CBS_MAX_CHNL_NUM];
    VfxU32 m_totalSelection;
    VfxBool m_isReentry;
	VcpTitleBar *m_titleBar;
	VfxBool m_isAdding;
	VfxBool m_isOpt;
    // DeleteChannelCntx
    VfxId m_channelToDelete[SRV_CBS_MAX_CHNL_NUM];
    VfxU32 m_totalToDelete;
    VfxU32 m_currDeleteIndex;
    VfxBool m_isCancelled;
    
    //confirm and processing
    VcpConfirmPopup *m_confirmPopup;
    VcpIndicatorPopup *m_processingPopup;
 };


/* Channel page end */



#endif /* __VAPP_CBS_CHANNEL_PAGE_H__ */
