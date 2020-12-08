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
 *  vapp_sms_viewer.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SMS_VIEWER_H__
#define __VAPP_SMS_VIEWER_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_sms_base.h"
#include "vapp_sms_provider.h"
#include "vapp_sms_operator.h"
#include "vapp_msg_use_detail.h"
#include "vapp_msg_viewer.h"
#include "vapp_msg_contact_bar.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VappSmsContactProvider;
class VappSmsVObjectButton;

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappSmsViewerPage : public VfxPage
{
    //VFX_DECLARE_CLASS(VappSmsViewerPage);

public:

    VappSmsViewerPage();
    virtual ~VappSmsViewerPage() {};

    void setMsgID(VfxU16 msgID, VfxBool mode = VFX_FALSE);
    void setSmsProvider(VappSmsProvider& provider);

protected:
    virtual void onInit(void);
	virtual void onDeinit(void);
    virtual void onUpdate(void);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
	virtual VfxBool onKeyInput(VfxKeyEvent &event);
	virtual void onEntered();
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );

private:
    void checkUpdateEx(void);

    void setMsgToolbar(void);
    void setContactBar(void);
    void updateBody(void);

    void onLoadSmsDone(VfxBool result);
    void onMsgChanged(void);
    void onMsgDeleted(void);
	void onReadAgain(void);
    void onKeywordClicked(VcpTextKeyWordEnum keyworkType, VfxWChar* text, VfxS32 textLen);
    void onButtonClicked(VfxObject *sender, VfxId bottom_id);
#ifdef __MMI_SMS_PORT_MSG__ 

    void onVObjectButtonClicked(void);
#endif
    VfxBool isDisalbeUseDetail(void);
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
	static mmi_ret onTcardPlugInOutProc(mmi_event_struct *evt);
#endif
#ifdef __MMI_SMS_DETAILS_INFO__	
    void addAddrItemToUseDetail(VappMsgUseDetailProvider* provider);
#endif
    void showLoadingIcon(void);
    void stopLoadingIcon(void);

private:
    enum
    {
        BUTTON_REPLY = 0,
        BUTTON_CALL,
        BUTTON_RESEND,
        BUTTON_FORWARD,
        BUTTON_EDIT,
        BUTTON_DELETE,
    #ifdef __MMI_SMS_DETAILS_INFO__
        BUTTON_USE_DETAIL,
    #endif
        BUTTON_COPY_FROM_PHONE,
        BUTTON_COPY_TO_PHONE,
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        BUTTON_COPY_FROM_ARCHIVE,
    #endif
	#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
		BUTTON_COPY_FROM_TCARD,
		BUTTON_COPY_TO_INBOX,
	#endif
        BUTTON_REPORTS,

        BUTTON_TOTAL
    } button_id;

    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        TEXT_VIEW_MARGIN_TOP        = 14,
        TEXT_VIEW_MARGIN_LEFT       = 14,
        TEXT_VIEW_MARGIN_BUTTOM     = 14,

        VOBJECT_BUTTON_HEIGHT       = 70,
        VOBJECT_BUTTON_FONT_SIZE    = 28,

        VOBJECT_MARGIN_TOP          = 14,
        VOBJECT_MARGIN_LEFT         = 14,
        TIMESTAMP_MARGIN_TOP        = 14,
        TIMESTAMP_MARGIN_RIGHT      = 14,
        TIMESTAMP_FONT_SIZE         = 21,
    #elif defined(__MMI_MAINLCD_320X480__)
        TEXT_VIEW_MARGIN_TOP        = 8,
        TEXT_VIEW_MARGIN_LEFT       = 8,
        TEXT_VIEW_MARGIN_BUTTOM     = 8,

        VOBJECT_BUTTON_HEIGHT       = 47,
        VOBJECT_BUTTON_FONT_SIZE    = 16,

        VOBJECT_MARGIN_TOP          = 8,
        VOBJECT_MARGIN_LEFT         = 8,
        TIMESTAMP_MARGIN_TOP        = 8,
        TIMESTAMP_MARGIN_RIGHT      = 8,
        TIMESTAMP_FONT_SIZE         = 14,
    #else /* __MMI_MAINLCD_240X320__ __MMI_MAINLCD_240X400__  */
        TEXT_VIEW_MARGIN_TOP        = 5,
        TEXT_VIEW_MARGIN_LEFT       = 5,
        TEXT_VIEW_MARGIN_BUTTOM     = 5,

        VOBJECT_BUTTON_HEIGHT       = 38,
        VOBJECT_BUTTON_FONT_SIZE    = 14,

        VOBJECT_MARGIN_TOP          = 5,
        VOBJECT_MARGIN_LEFT         = 5,
        TIMESTAMP_MARGIN_TOP        = 5,
        TIMESTAMP_MARGIN_RIGHT      = 5,
        TIMESTAMP_FONT_SIZE         = 11,
    #endif

        DATATIME_BUFF_LEN           = 40,
    };

    VappSmsProvider *m_smsProvider;
    VappSmsOperator *m_smsOperator;
	VfxU16 m_msgID;
    VfxBool m_isLoadDone;

    VfxBool m_isUnsentMsg;

    VfxBool m_isUpdate;
	VfxBool m_isLiteMode;
	VfxBool m_isSupSendKey;
	  srv_sms_storage_enum m_msgStorage;

    VappMsgContactBar *m_contactBar;
    VappSmsContactProvider *m_contactProvider;
    VcpTextView *m_smsBody;
    VcpToolBar *m_toolBar;
    VfxTextFrame *m_timestampFrame;
    VcpActivityIndicator *m_loadingIcon;
#ifdef __MMI_SMS_PORT_MSG__ 

    VappSmsVObjectButton *m_vObjectButton;
#endif
	VappMsgAddrOption *m_addrOption;
};

class VappSmsLiteViewer : public VappMsgViewerCp
{
    //VFX_DECLARE_CLASS(VappSmsLiteViewer);

public:
    VappSmsLiteViewer();

    virtual void setMsgId(VfxU32 msgId);
    virtual VfxU32 getTimestamp(void);
    virtual void forceUpdate(void);
    virtual void setBounds(const VfxRect &value);

protected:
    virtual void onInit(void);
	virtual void onDeinit(void);
    virtual void onUpdate(void);

private:
    void updateView(void);
    void onLoadSmsDone(VfxBool result);
    void onMsgChanged(void);
    void onMsgDeleted(void);
	void onReadAgain(void);
    void setIntSize(const VfxSize &value);

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    void onButtonClicked(VfxObject * sender, VfxId bottom_id);
    static void onResendDone(srv_sms_callback_struct* callback_data);
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        LEFT_ICON_TEXT_OFFSET   = 14,
        LEFT_ICON_ICON_OFFSET   = 14,
        TEXT_RIGTH_ICON_OFFSET  = 14,
        RIGHT_ICON_SIZE         = 34,
        TEXT_FONT_SIZE          = 26
    #elif defined(__MMI_MAINLCD_320X480__)
        LEFT_ICON_TEXT_OFFSET   = 6,
        LEFT_ICON_ICON_OFFSET   = 6,
        TEXT_RIGTH_ICON_OFFSET  = 8,
        RIGHT_ICON_SIZE         = 26,
        TEXT_FONT_SIZE          = 16
    #else /* __MMI_MAINLCD_240X320__ __MMI_MAINLCD_240X400__  */
        LEFT_ICON_TEXT_OFFSET   = 5,
        LEFT_ICON_ICON_OFFSET   = 5,
        TEXT_RIGTH_ICON_OFFSET  = 8,
        RIGHT_ICON_SIZE         = 24,
        TEXT_FONT_SIZE          = 14
    #endif
    };

    VappSmsProvider *m_smsProvider;
    VcpTextView *m_smsContent;
	VfxU32 m_msgID;
    VfxImageFrame *m_vObjectIcon;
    VfxImageFrame *m_statusIcon;
    VfxSize m_outerSize;
	VfxSize m_preOuterSize;
	VfxSize m_viewerSize;
    VfxBool m_isOuterSize;
	VfxBool m_isNeedUpdate;

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    VcpImageButton *m_resendButton;
    VcpActivityIndicator *m_sendingIcon;
    VfxBool m_isResend;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
};

class VappSmsContactProvider : public VappMsgContactProvider
{
    //VFX_DECLARE_CLASS(VappSmsContactProvider);

public:
    VappSmsContactProvider();

    void setMsgID(VfxU16 msgID)
    {
        m_msgID = msgID;
    };

    VfxU16 getMsgID(void)
    {
        return m_msgID;
    };

    virtual VfxBool getContact(VappMsgContact& contact, VcpMenuPos index = VcpMenuPos(0, 0));
    virtual VfxU32 getCount(VfxU32 group = 0) const;

    virtual VfxBool isShowMemberInBar(VfxU32 group) const;

    virtual VfxBool isShowRecipientList(VfxWString& causeStr);
    virtual VfxBool isResendFailed(void);
    virtual void resendFailed(void);

private:
    VfxU16 m_msgID;   
};

#ifdef __MMI_SMS_PORT_MSG__ 

class VappSmsVObjectButton : public VfxControl
{
    //VFX_DECLARE_CLASS(VappSmsVObjectButton);

public:
	VappSmsVObjectButton();
	virtual ~VappSmsVObjectButton(){};

	void setImage(const VfxImageSrc& image);
	void setText(const VfxWString& text);

protected:
	virtual void onInit(void);
    virtual void onUpdate(void);
	virtual VfxBool onPenInput(VfxPenEvent& event);

public:
	VfxSignal0 m_signalClicked;

private:
    enum
    {
    #ifdef __MMI_MAINLCD_480X800__
        TEXT_FONT_SIZE  = 28,
        IMAGE_MARGIN    = 14,
        TEXT_MARGIN     = 14
   #else
        TEXT_FONT_SIZE  = 18,
        IMAGE_MARGIN    = 10,
        TEXT_MARGIN     = 10
    #endif
    };

	VfxImageFrame *m_image;
	VfxTextFrame *m_text;
	VfxBool m_isClicked;
};
#endif /*__MMI_SMS_PORT_MSG__*/
#endif /* __VAPP_SMS_VIEWER_H__ */

