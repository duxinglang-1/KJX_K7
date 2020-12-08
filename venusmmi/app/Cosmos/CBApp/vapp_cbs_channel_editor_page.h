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
 * Vapp_cbs_channel_editor_page.h
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

#ifndef __VAPP_CBS_CHANNEL_EDITOR_PAGE_H__
#define __VAPP_CBS_CHANNEL_EDITOR_PAGE_H__
#include "mmi_features.h"

#ifndef __cplusplus
#error "this header file can be used in C++ only."
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vapp_cbs_iprot.h"
typedef srv_sms_callback_struct cbsCallbackStruct;


/*channel editor page*/
class VappCbsChannelEditorForm : public VcpForm
{
    //VFX_DECLARE_CLASS(VappCbsChannelEditorForm);
// Declaration

// Constructor / Destructor
public:
    VappCbsChannelEditorForm();
 //   virtual ~VappCBSChannelEditorForm(){};
// Method
public:
    const VfxWString getName(void);
    const VfxWString getNumber(void);
    VfxBool getSubscribeStatus(void);
    void setNameValue(VfxWString string);
    void setNumberValue(VfxWString number);
    void setSubscribeStatus(VfxBool is_subscribed);
    void disabledNumber();
    void createItems();
    //void activeNameEditor(void);
    //void activeNumberEditor(void);
    //void deactiveNameEditor(void);
    //void deactiveNumberEditor(void);
	void activeTextEditor(VfxBool isNameEditor, VfxBool isActive);


    //void setNameFuncBar(VcpFunctionBar *funcBar);
    //void setNumberFuncBar(VcpFunctionBar *m_funcBar);
	void setFuncBar(VcpFunctionBar *funcBar, VfxBool isNameFuncBar);

    
    VcpTextEditor *getNameEditor(void);
    VcpTextEditor *getNumberEditor(void);
	
	VcpFormItemTextInput *getNumberItem(void);
// Variable
private:
    VcpFormItemSwitchCell *m_subscribe;
    VcpFormItemTextInput *m_channelNameInput, *m_channelNumberInput;
};

class VappCbsChannelEditorPage : public VfxPage
{
private:
    enum vappCbsChannelEditorNumberInputErrorEnum
    {
        NUBMER_EXCEED,
        NUBMER_EMPTY,
        NO_ERROR
    };
    enum vappCbsChannelEditorFuncBarEnum
    {
        FUNCBAR_PREV = 0,
        FUNCBAR_NEXT,
        FUNCBAR_SAVE,
        FUNCBAR_ALL
    };

// Declaration
    //VFX_DECLARE_CLASS(VappCbsChannelEditorPage);
// Constructor / Destructor
public:
    VappCbsChannelEditorPage(VfxS32 sim, srv_cbs_chnl_entry_struct *channel, VfxBool isNewChannel);
    //~VappCbsChannelEditorPage();
    //void setSim(VappCbsSimEnum sim);
    VfxS32 getSim();
    //void setChannel(srv_cbs_chnl_entry_struct *channel);
    //srv_cbs_chnl_entry_struct *getChannel();
    //void setIsNewChannel(VfxBool isNewChannel);
    
    //void updateForm();
    void activationSwitched(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus);
    void onToolBarClick(VfxObject* sender, VfxId id);
    
    void confirmEventHandler(VfxObject* obj, VfxId id);
    void onFuncBarClick(VfxObject*, VfxId id);
#ifdef _VAPP_CBS_AUTO_CHECK_
    void onTextChanged(VcpTextEditor *editor);
#endif

    void onNameEditorActivated(VcpTextEditor *editor, VfxBool activated);
    void onNumberEditorActivated(VcpTextEditor *editor, VfxBool activated);

    
public:
    static void channelActionCallback(cbsCallbackStruct *callbackData);

protected:
    virtual void onInit();
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
    
private:
    //void showErrorConfirm(VfxWString string);
    vappCbsChannelEditorNumberInputErrorEnum channelInputCheck(VfxU32 &channelIdOutput);
    VfxWString getErrorString(vappCbsChannelEditorNumberInputErrorEnum error);
    void save();

// Variable
private:
    enum item_id
    {
        SAVE,
        CANCEL
    };
    VappCbsChannelEditorForm * m_channelEditor;
    
	VcpTitleBar *m_titleBar;
    VcpToolBar *m_toolBar;
    VfxBool m_isNewChannel;
    VfxS32 m_currSim;
    srv_cbs_chnl_entry_struct *m_currChannel;
    VcpIndicatorPopup *m_processingPopup;
    VcpConfirmPopup *m_confirmPopup;
    VcpFunctionBar *m_funcBar;
    VfxBool m_isInProcessing;
};
/* channel editor page end */

#endif /* __VAPP_CBS_CHANNEL_EDITOR_PAGE_H__ */
