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
 *  vapp_wap_push_viewer.cpp
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "../xml/vfx_xml_loader.h"
#include "vapp_wap_push_viewer.h"
#include "mmi_rp_vapp_wap_push_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include"app_datetime.h"
#include "vcui_bookmark_gprot.h"
#include "wap_adp.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "GlobalResDef.h"

#ifdef __cplusplus
}
#endif

#include "vcp_global_popup.h"

extern VfxS32 g_highConfirmPopupHandle;
/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_MAINLCD_320X480__
	#define PUSH_TEXT_VIEW_MARGIN 10
	#define VIEWER_BODY_FONT_SIZE 18
	#define LITE_VIEWER_BODY_FONT_SIZE 18
	#define CREATED_TIME_FONT_SIZE 14
#elif __MMI_MAINLCD_480X800__
	#define PUSH_TEXT_VIEW_MARGIN 14
	#define VIEWER_BODY_FONT_SIZE 20
	#define LITE_VIEWER_BODY_FONT_SIZE 30
	#define CREATED_TIME_FONT_SIZE 21
#elif __MMI_MAINLCD_240X320__
	#define PUSH_TEXT_VIEW_MARGIN 5
	#define VIEWER_BODY_FONT_SIZE 14
	#define LITE_VIEWER_BODY_FONT_SIZE 14
	#define CREATED_TIME_FONT_SIZE 11
#elif __MMI_MAINLCD_432X240__
	#define PUSH_TEXT_VIEW_MARGIN 5
	#define VIEWER_BODY_FONT_SIZE 14
	#define LITE_VIEWER_BODY_FONT_SIZE 14
	#define CREATED_TIME_FONT_SIZE 11
#else
	#define PUSH_TEXT_VIEW_MARGIN 10
	#define VIEWER_BODY_FONT_SIZE 18
	#define LITE_VIEWER_BODY_FONT_SIZE 18
	#define CREATED_TIME_FONT_SIZE 14
#endif
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

void VappWapPushFullViewer::onInit()
{
    VfxFontDesc font;
    VappMsgViewerCp::onInit(); // call base class	

    showLoading();
    VFX_OBJ_CREATE(m_bodyTextView, VcpTextView, this);
    VfxRect rect = getBounds();
    m_bodyTextView->setSize(getSize().width, getSize().height);
    m_bodyTextView->setPos(rect.origin.x,rect.origin.y);    
    m_bodyTextView->setMargins(PUSH_TEXT_VIEW_MARGIN, PUSH_TEXT_VIEW_MARGIN,
                                PUSH_TEXT_VIEW_MARGIN, PUSH_TEXT_VIEW_MARGIN);
    m_bodyTextView->setAlignParent(
                                    VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE);
    font.size = VFX_FONT_DESC_VF_SIZE(VIEWER_BODY_FONT_SIZE);
    m_bodyTextView->setFont(font);
    m_bodyTextView->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_BLACK);
    VFX_OBJ_CREATE(m_createdTime, VfxTextFrame, this);
    m_createdTime->setMargins(0, PUSH_TEXT_VIEW_MARGIN, 0, 0);
    m_createdTime->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));	
    font.size = VFX_FONT_DESC_VF_SIZE(CREATED_TIME_FONT_SIZE);
    m_createdTime->setFont(font);
}

void VappWapPushFullViewer::setBodyText(pmg_detailed_msg_struct *msg, VfxS8 *url)
{
    VfxU16 urr_size = 0;
    VfxU16 text_len = 0;
    VfxU16 totalTextLen = 0;
    VfxWChar *ucs2_msg = NULL;
    VfxWChar *ucs2_url = NULL;
    VfxFontDesc font;

    /* Displaying Message URL */
    /* Displaying Message Text */
    if (msg->text_type == WAP_PMG_STRTYPE_ASCII)
    {
        text_len = vfx_sys_strlen((VfxChar*)msg->text);
    }
    else if (msg->text_type == WAP_PMG_STRTYPE_UCS2)
    {
        text_len = mmi_ucs2strlen((const VfxChar*)msg->text);
    }

    if ((msg->msg_type == WAP_PMG_MSGTYPE_SI) && 
        (msg->text != NULL) && (text_len != 0))
    {
        VFX_ALLOC_MEM(ucs2_msg, ((text_len + 1) * ENCODING_LENGTH), this);

        memset (ucs2_msg, 0, ((text_len + 1) *ENCODING_LENGTH));

        if (msg->text_type == WAP_PMG_STRTYPE_ASCII)
        {
            mmi_asc_to_ucs2((VfxChar*) ucs2_msg, (VfxChar*) msg->text);
        }
        else if (msg->text_type == WAP_PMG_STRTYPE_UCS2)
        {
            vfx_sys_wcscpy((VfxWChar*) ucs2_msg, (VfxWChar*) msg->text);
        }
        totalTextLen = text_len;
    }    
    if (url != NULL)
    {
        urr_size = vfx_sys_strlen ((VfxChar *)url);
        VFX_ALLOC_MEM(ucs2_url, ((urr_size + 1) * ENCODING_LENGTH), this);
        memset (ucs2_url, 0, ((urr_size + 1) *ENCODING_LENGTH));
        mmi_asc_to_ucs2((VfxChar*) ucs2_url, (VfxChar*) url);
        VFX_ALLOC_MEM(m_urlText, ((urr_size + 1) *ENCODING_LENGTH), this);
        vfx_sys_wcscpy((VfxWChar*) m_urlText, (VfxWChar*) ucs2_url);
        totalTextLen += urr_size + 2;
    }
    if (totalTextLen)
    {
        VFX_ALLOC_MEM(m_bodyText, ((totalTextLen + 1) * ENCODING_LENGTH), this);
        memset(m_bodyText, 0, ((totalTextLen + 1) * ENCODING_LENGTH));
        if(ucs2_msg)
        {
            vfx_sys_wcscpy((VfxWChar*) m_bodyText, (VfxWChar*) ucs2_msg);
            VFX_FREE_MEM(ucs2_msg);
            if(ucs2_url)
            {
                mmi_ucs2cat((VfxChar*)m_bodyText, "\n");
                mmi_ucs2cat((VfxChar*)m_bodyText, (const VfxChar*)ucs2_url);
                VFX_FREE_MEM(ucs2_url);
            }
        }
        else if(ucs2_url)
        {
            vfx_sys_wcscpy((VfxWChar*) m_bodyText, (VfxWChar*) ucs2_url);
            VFX_FREE_MEM(ucs2_url);
        }	
    }
    stopLoading();
    m_bodyTextView->setText(m_bodyText, NULL);
    m_bodyTextView->setKeyword(VCP_TEXT_KEYWORD_URL);
    m_bodyTextView->m_signalKeywordClick.connect(this, &VappWapPushFullViewer::onKeywordClicked); 

    VfxWChar *content = m_bodyTextView->getText();
    VfxU32 contentLen = vfx_sys_wcslen(content);
    VFX_ALLOC_MEM(m_timeText, 100, this);
    srv_wap_push_create_ucs2_time_format_string(msg->created, (S8*)m_timeText);
    m_createdTime->setString(m_timeText);
    font.size = VFX_FONT_DESC_VF_SIZE(CREATED_TIME_FONT_SIZE);
    m_createdTime->setFont(font);	
    VcpRichTextCustomFrame customFrame;
    customFrame.setFrame(m_createdTime);
    customFrame.setRange(contentLen, contentLen);
    customFrame.setObjectAttribute(VCP_RICH_TEXT_OBJ_ARRT_RIGHT_ALIGN);
    m_bodyTextView->addTextFormat(customFrame);
    m_bodyTextView->setColor(VCP_TEXT_NORMAL_TEXT_COLOR,VFX_COLOR_RES(CLR_ID_PUSH_MSG_TEXT_VIEW_COLOR));
}

void VappWapPushFullViewer::updateSize(void)
{
    VfxSize size = getSize();
    VfxSize contentSize = size;
    m_bodyTextView->setSize(contentSize);
    m_bodyTextView->forceUpdate();

    if (m_bodyTextView->getLineCount() < 2)
    {
        m_bodyTextView->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    }
    else
    {
        m_bodyTextView->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    }
    size = m_bodyTextView->getSize();   
    m_bodyTextView->setSize(size);
    m_bodyTextView->forceUpdate();
}

void VappWapPushFullViewer::onDeinit()
{
    if(m_bodyText)
    {
        VFX_FREE_MEM(m_bodyText);
    }		
    if(m_timeText)
    {
        VFX_FREE_MEM(m_timeText);
    }		
    if(m_urlText)
    {
        VFX_FREE_MEM(m_urlText);
    }		
    VappMsgViewerCp::onDeinit();
}

void VappWapPushFullViewer::onKeywordClicked(
    VcpTextKeyWordEnum keyworkType,
    VfxWChar* text,
    VfxS32 textLen)
{
    VfxWString address;
    switch (keyworkType)
    {
        case VCP_TEXT_KEYWORD_PHONENUMBER:        
        case VCP_TEXT_KEYWORD_EMAIL:
        break;
        
        case VCP_TEXT_KEYWORD_URL:
        {
        #if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRM_BKM_INTERFACE_SUPPORT__)
            VcpCommandPopup *m_commandPopup;
            VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, this);
            m_commandPopup->setInfoType(VCP_POPUP_TYPE_INFO);           
            m_commandPopup->setText(VFX_WSTR_STATIC(VappWapPushFullViewer::getURLText())); 	
            m_commandPopup->addItem(PUSH_GO_TO_URL, (VfxResId)STR_ID_VAPP_PUSH_GO_TO_URL);
            m_commandPopup->addItem(PUSH_ADD_TO_BK, (VfxResId)STR_ID_VAPP_PUSH_SAVE_TO_BK);	
            m_commandPopup->addItem(PUSH_BK_CANCEL, (VfxResId)STR_GLOBAL_CANCEL,VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_commandPopup->setAutoDestory(VFX_FALSE);
            m_commandPopup->m_signalButtonClicked.connect(this, &VappWapPushFullViewer::onUrlAddToBookmarks);
            m_commandPopup->show(VFX_TRUE);
        #else
        #ifdef BROWSER_SUPPORT
            wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8 *)VappWapPushFullViewer::getURLText());
        #endif /*BROWSER_SUPPORT*/
        #endif /*__MMI_VUI_SAVE_BOOKMARK_SUPPORT__*/
        }
        break;
        default:
        break;
    }
}

#if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRM_BKM_INTERFACE_SUPPORT__)
void VappWapPushFullViewer::onUrlAddToBookmarks(VfxObject* sender, VfxId id)
{   
    switch(id)
    {
        case PUSH_GO_TO_URL:
        {
        #ifdef BROWSER_SUPPORT
            if (VappWapPushFullViewer::getURLText())
            {
                wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8 *)VappWapPushFullViewer::getURLText());
            }
        #endif /*BROWSER_SUPPORT*/
        }
        break;

        case PUSH_ADD_TO_BK:
        {
            U8 *temp_string = NULL;
            mmi_id grpId=VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
        #if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRM_BKM_INTERFACE_SUPPORT__)
            m_bookmarkId = vcui_bkm_add_bkm_create(grpId);
            if(m_bookmarkId==GRP_ID_INVALID)
            {
                return;
            }            
            mmi_frm_group_set_caller_proc(m_bookmarkId, &VappWapPushFullViewer::saveBookmarkIntProc,(void*)this);
            VFX_ALLOC_MEM(temp_string, (WAP_MAX_URL_LENGTH +1) * ENCODING_LENGTH, this);; 
            memset(temp_string, 0, (WAP_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
            mmi_chset_ucs2_to_utf8_string( (U8*) temp_string, (WAP_MAX_URL_LENGTH + 1) * ENCODING_LENGTH, (U8*)VappWapPushFullViewer::getURLText());
            vcui_bkm_add_bkm_run (  m_bookmarkId, (U8*)temp_string);
            VFX_FREE_MEM(temp_string);
        #endif
        }   
        break;
        
        case PUSH_BK_CANCEL:
        break;
        
        default:
        break;
    }

}

mmi_ret VappWapPushFullViewer::saveBookmarkIntProc(mmi_event_struct *evt)
{   
    switch(evt->evt_id)
    {
        case EVT_ID_VCUI_BKM_ADD_BKM_CLOSE:
        {
            vcui_bkm_add_bkm_close(m_bookmarkId);
            m_bookmarkId = GRP_ID_INVALID;	
        }       		
        break;
        
        default:
        break;
    }
    return MMI_RET_OK;
}

#endif /*__MMI_VUI_SAVE_BOOKMARK_SUPPORT__*/

void VappWapPushViewerPage::onWapPushViewerTBClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
        case PUSH_VIEWER_LAUNCH_BROWSER:
        {
        #ifdef BROWSER_SUPPORT
            if (m_pushFullViewer && m_pushFullViewer->getURLText())
            {
                wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8 *)m_pushFullViewer->getURLText());
            }
        #endif /*BROWSER_SUPPORT*/
        }
        break;
        
        case PUSH_VIEWER_MSG_DELETE:
        {
            VcpConfirmPopup *confirm;
            VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);
            confirm->setText((VfxResId)STR_ID_VAPP_PUSH_DELETE_CONRM);
            confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
            confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
            confirm->setCustomButton(
            (VfxResId)STR_GLOBAL_DELETE, 
            (VfxResId)STR_GLOBAL_CANCEL, 
            VCP_POPUP_BUTTON_TYPE_WARNING, 
            VCP_POPUP_BUTTON_TYPE_CANCEL);
            confirm->m_signalButtonClicked.connect(this, &VappWapPushViewerPage::onWapPushViewerDelete);
            confirm->show(VFX_TRUE);
        }
        break;
        
        default:
        break;
    }
}

void VappWapPushViewerPage::onWapPushViewerDelete(VfxObject * obj, VfxId id)
{
    // only delete action now
    /* show processing */
    if (VCP_CONFIRM_POPUP_BUTTON_YES == id)
    {
    #ifdef __MMI_PUSH_IN_UM__
        srv_wap_push_send_um_refresh_ind(m_msgID,SRV_UM_REFRESH_MSG_DELETED,NULL);
    #endif
        srv_wap_push_delete_message_generic (m_msgID);
    }
}

void VappWapPushViewerPage::onInit()
{
    VfxFontDesc font;
    VfxPage::onInit(); // call base class

    srv_wap_push_idle_messge_queue_struct *message = NULL;
    message = srv_wap_push_get_first_msg ();

    if(message != NULL)
    {
        if((message->message_id == m_msgID) && (g_highConfirmPopupHandle != 0))
        {
            vcp_global_popup_cancel(g_highConfirmPopupHandle);
        }
        else
        {
            if(! srv_wap_push_msg_read_status(m_msgID))
            {
                srv_wap_push_delete_from_msg_queue(m_msgID);
            }            
        }
    }

    setBgColor(CLR_ID_PUSH_MSG_TEXT_BG_COLOR);
    VFX_OBJ_CREATE(m_contactBar, VappMsgContactBar, this);
    m_contactBar->setSize(getSize().width, m_contactBar->getSize().height);
    m_contactBar->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_NONE);
    m_contactBar->setIsUnhittable(VFX_TRUE);
    VFX_OBJ_CREATE(m_pushFullViewer, VappWapPushFullViewer, this);
    m_pushFullViewer->setSize(getSize().width, getSize().height - m_contactBar->getSize().height);
    m_pushFullViewer->setPos(0,m_contactBar->getSize().height);
    m_pushFullViewer->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);

    g_srv_wap_push_cntxt->selected_message.msg_type = WAP_PMG_MSGTYPE_NULL;
    g_srv_wap_push_cntxt->selected_message_id = m_msgID;
    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_msgBodyDispatchCallback.connect(this , &VappWapPushViewerPage::wapPushViewerDataRecive);
    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_msgDeleteCallback.connect(this , &VappWapPushViewerPage::wapPushViewerMsgDelete);
    srv_wap_push_update_service_msg_req(m_msgID);
    srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
    srv_wap_push_get_full_message (g_srv_wap_push_cntxt->selected_message_id, PUSH_GET_MSG_TO_DISPLAY_FROM_UM_TRANS_ID);
    VFX_OBJ_CREATE(m_tool_bar,VcpToolBar,this);
    m_tool_bar->m_signalButtonTap.connect(this, &VappWapPushViewerPage::onWapPushViewerTBClick);
    m_tool_bar->addItem(PUSH_VIEWER_LAUNCH_BROWSER, (VfxResId)STR_ID_VAPP_PUSH_VIEW_WEBSITE,VCP_IMG_TOOL_BAR_COMMON_ITEM_SEND);
    m_tool_bar->addItem(PUSH_VIEWER_MSG_DELETE, (VfxResId)STR_GLOBAL_DELETE,VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_tool_bar->setDisableItem(PUSH_VIEWER_LAUNCH_BROWSER, VFX_TRUE);
    m_tool_bar->setDisableItem(PUSH_VIEWER_MSG_DELETE, VFX_TRUE);
    setBottomBar(m_tool_bar);
}

void VappWapPushViewerPage::onBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds)
{
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);   
}

void VappWapPushViewerPage::wapPushViewerMsgDelete(VfxBool showInfo, VfxU32 msgID)
{
    if (m_msgID != msgID)
    {
        return;
    }    
    if (showInfo)
    {
        VfxAppWapPushInterface::displayPopup(STR_GLOBAL_DELETED, SRV_WAP_PUSH_EVENT_EXPLICITLY_DELETED);
    }    
    (getMainScr())->popPage();	
}

void VappWapPushViewerPage::wapPushViewerDataRecive(pmg_detailed_msg_struct *msg, VfxS8 *url)
{
    VfxWString formAddress;
    VfxWString createdTimeAddress;
    VfxWString msgBody;
    VfxFontDesc font;    
    VFX_ASSERT(msg);

    VfxS32 size = vfx_sys_strlen ((VfxChar *)msg->from.addr);
    if (size)
    {
        VfxWChar *bufPtr = formAddress.lockBuf(((size + 1) *ENCODING_LENGTH));
        mmi_asc_to_ucs2((VfxChar *) bufPtr, (VfxChar *) msg->from.addr);
        formAddress.unlockBuf();
        m_contactBar->setContact(formAddress,VAPP_MSG_CONTACT_TYPE_ALPHANUMBIC);
        VfxU32 priority=0;
        VfxU32 simId=0;      

    #if (MMI_MAX_SIM_NUM >= 2)
        simId = IMG_COSMOS_SIM1 + (msg->sim_id - WAP_PMG_SIM1);			
    #endif
        priority = IMG_ID_WAP_PUSH_VENUS_MESSAGE_LOW_ICON + (msg->priority - WAP_PMG_MSGPRIO_LOW);          
        m_contactBar->setRightIcon(VfxImageSrc(simId),VfxImageSrc(priority));
    }
    m_pushFullViewer->setBodyText(msg, url);	
    m_tool_bar->setDisableItem(PUSH_VIEWER_LAUNCH_BROWSER, VFX_FALSE);
    m_tool_bar->setDisableItem(PUSH_VIEWER_MSG_DELETE, VFX_FALSE);
    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_msgBodyDispatchCallback.disconnect(this , &VappWapPushViewerPage::wapPushViewerDataRecive);
}

VappWapPushViewerPage::VappWapPushViewerPage(VfxS32 msgID) : 
        m_msgID(msgID)
{
    m_tool_bar = NULL;
    m_contactBar = NULL;
    m_popup = NULL;
};

void VappWapPushViewerPage::onDeinit()
{
    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_msgBodyDispatchCallback.disconnect(this , &VappWapPushViewerPage::wapPushViewerDataRecive);
    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_msgDeleteCallback.disconnect(this , &VappWapPushViewerPage::wapPushViewerMsgDelete);
    VfxPage::onDeinit();
}

void VappWapPushLiteViewerCp::onInit()
{
    VfxFontDesc font;
    VappMsgViewerCp::onInit(); // call base class

    if (g_highConfirmPopupHandle != 0)
    {
        vcp_global_popup_cancel(g_highConfirmPopupHandle);
    }

    srv_wap_push_delete_all_queue_entry();	
    g_srv_wap_push_cntxt->read_from_um = MMI_TRUE;
    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_msgBodyDispatchCallback.connect(this , &VappWapPushLiteViewerCp::wapPushLiteViewerDataRecive);
    VFX_OBJ_CREATE(m_textframe, VfxTextFrame, this);
    m_textframe->setAlignParent(VFX_FRAME_ALIGNER_SIDE_TOP, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_textframe->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_textframe->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_textframe->setColor(VFX_COLOR_BLACK);   
    font.size = VFX_FONT_DESC_VF_SIZE(LITE_VIEWER_BODY_FONT_SIZE);
    m_textframe->setFont(font);
    srv_wap_push_get_full_message (m_msgId, PUSH_GET_MSG_DETAIL_TRANS_ID);
}

void VappWapPushLiteViewerCp::wapPushLiteViewerDataRecive(pmg_detailed_msg_struct *msg, VfxS8 *url)
{
    VfxWString msgBody;
    if (m_msgId != msg->msg_id)
    {
        return;
    }   
		
    setBodyText(msg, url);
    VfxU32 timestamp;
    timestamp=applib_dt_sec_local_to_utc(msg->created);
    setTimestamp(timestamp);
    updateCell();
    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_msgBodyDispatchCallback.disconnect(this , &VappWapPushLiteViewerCp::wapPushLiteViewerDataRecive);
    setContentReady(VFX_TRUE);
}


void VappWapPushLiteViewerCp::setBodyText(pmg_detailed_msg_struct *msg, VfxS8 *url)
{
    VfxU16 text_len = 0;

    if ((msg->text != NULL) && (msg->text_type == WAP_PMG_STRTYPE_ASCII))
    {
        text_len = vfx_sys_strlen((VfxChar*)msg->text);
    }
    else if ((msg->text != NULL) && (msg->text_type == WAP_PMG_STRTYPE_UCS2))
    {
        text_len = mmi_ucs2strlen((VfxChar*)msg->text);
    }   

    if ((msg->msg_type == WAP_PMG_MSGTYPE_SI) && 
        (msg->text != NULL) && (text_len != 0))
    {
        VFX_ALLOC_MEM(m_bodyText, ((text_len + 1) * ENCODING_LENGTH), this);
        memset (m_bodyText, 0, ((text_len + 1) *ENCODING_LENGTH));
        if (msg->text_type == WAP_PMG_STRTYPE_ASCII)
        {
            mmi_asc_to_ucs2((VfxChar*) m_bodyText, (VfxChar*) msg->text);
        }
        else if (msg->text_type == WAP_PMG_STRTYPE_UCS2)
        {
            vfx_sys_wcscpy((VfxWChar*) m_bodyText, (VfxWChar*) msg->text);
        }
    }
    else if(url)
    {
        text_len = vfx_sys_strlen ((VfxChar *)url);
        VFX_ALLOC_MEM(m_bodyText, ((text_len + 1) * ENCODING_LENGTH), this);
        memset (m_bodyText, 0, ((text_len + 1) *ENCODING_LENGTH));
        mmi_asc_to_ucs2((VfxChar*) m_bodyText, (VfxChar*) url);
    }
}

void VappWapPushLiteViewerCp::forceUpdate()
{
    if (!m_textframe->getString().isEmpty())
    {
        m_originalSize = getSize();
        updateCell();
    }
    else
    {    
        m_originalSize = getSize();
        setSize(VfxSize(0,0));
    }
}

void VappWapPushLiteViewerCp::onDeinit()
{
    if(m_bodyText)
    {
        VFX_FREE_MEM(m_bodyText);
    }   

    VappMsgViewerCp::onDeinit();
}

void VappWapPushLiteViewerCp::updateCell(void)
{
    VfxSize size;
    VfxSize contentSize = m_originalSize;

    m_textframe->setSize(contentSize);    
    if(m_bodyText)
    {
        m_textframe->setString((VfxWChar *)m_bodyText);
    }
    else
    {
        m_textframe->setString((VfxResId)STR_ID_VAPP_PUSH_NO_SUBJECT);
    }    
    if (m_textframe->getLineCount() < 2)
    {
        m_textframe->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    }
    else
    {
        m_textframe->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    }
    m_textframe->setColor(VFX_COLOR_RES(CLR_ID_PUSH_MSG_TEXT_FONT_COLOR));
    m_textframe->forceUpdate();
    size = m_textframe->getSize();
    setSize(size);
}
