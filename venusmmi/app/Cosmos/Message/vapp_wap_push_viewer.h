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
 *  vapp_XXX.h
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
 *
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_PUSH_MSG_BODY_H__
#define __VAPP_PUSH_MSG_BODY_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_msg_contact_bar.h"
#include "vapp_msg_viewer.h"
#include "vapp_wap_push_interface.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "WAPPushSrvProts.h"
#include "WAPPushSrvTypes.h"
#include "Browser_api.h"

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappWapPushLiteViewerCp : public VappMsgViewerCp
{
// Constructor
public:
    VappWapPushLiteViewerCp(VfxU32 msgId):
        m_msgId(msgId),
        m_originalSize(VfxSize(0,0))
    {
        m_textframe = NULL;
        m_bodyText = NULL;
        m_timeStamp = 0;
    };

    // Property
    virtual void setMsgId(VfxU32 msgId){};
    virtual VfxU32 getTimestamp(){ return m_timeStamp;}
    void setTimestamp(VfxU32 timeStamp){ m_timeStamp = timeStamp;}
    // Method
    virtual void forceUpdate();
    // Event

    // Overridable
protected:
    virtual void onInit();
    virtual void onDeinit();
    void updateCell();
    void setBodyText(pmg_detailed_msg_struct *msg, VfxS8 *url);
    void wapPushLiteViewerDataRecive(pmg_detailed_msg_struct *msg, VfxS8 *url);

    VfxU32 m_msgId;
    VfxU32 m_timeStamp;
    VfxTextFrame *m_textframe;
    VfxWChar *m_bodyText;
    VfxSize m_originalSize;
};

class VappWapPushFullViewer : public VappMsgViewerCp
{

// Override
private:
#if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRM_BKM_INTERFACE_SUPPORT__)
    mmi_ret m_bookmarkId;
#endif /*__MMI_VUI_SAVE_BOOKMARK_SUPPORT__*/
public:
    VfxWChar *m_bodyText;
    VfxWChar *m_urlText;
    VfxWChar *m_timeText;

    VfxFrame *m_bodyTextFrame;
    VfxTextFrame *m_createdTime;
    VcpTextView *m_bodyTextView;    
    VappWapPushFullViewer()
    {
        m_bodyText = NULL;
        m_urlText = NULL;
        m_bodyTextView = NULL;
        m_createdTime = NULL;
        m_timeText = NULL;
        m_createdTime = NULL;
    };
#if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRM_BKM_INTERFACE_SUPPORT__)
    enum
    {
        PUSH_GO_TO_URL,
        PUSH_ADD_TO_BK,
        PUSH_BK_CANCEL,
    };
#endif /*__MMI_VUI_SAVE_BOOKMARK_SUPPORT__*/
    void setBodyText(pmg_detailed_msg_struct *msg, VfxS8 *url);
    VfxWChar *getURLText(){ return m_urlText;}
    VfxWChar *getBodyText(){ return m_bodyText;}  
    virtual void onInit();
    virtual void onDeinit();
    void onKeywordClicked(
    VcpTextKeyWordEnum keyworkType,
    VfxWChar* text,
    VfxS32 textLen);
    void updateSize(void);
#if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRM_BKM_INTERFACE_SUPPORT__)
    void onUrlAddToBookmarks(VfxObject * obj, VfxId id);
    static mmi_ret saveBookmarkIntProc(mmi_event_struct *evt);
#endif /*__MMI_VUI_SAVE_BOOKMARK_SUPPORT__*/
	
};

class VappWapPushViewerPage : public VfxPage
{
// Override
public:
    enum
    {
        PUSH_VIEWER_LAUNCH_BROWSER,
        PUSH_VIEWER_MSG_DELETE,
    };
    VfxS32 m_msgID;
    VcpToolBar *m_tool_bar;
    VappMsgContactBar *m_contactBar;
    VcpIndicatorPopup *m_popup;

    VappWapPushFullViewer    *m_pushFullViewer;

    VappWapPushViewerPage()
    {	
        m_tool_bar = NULL;
        m_contactBar = NULL;
        m_popup = NULL;
    };  
    VappWapPushViewerPage(VfxS32 msgID);
    virtual void onInit();
    void onWapPushViewerTBClick(VfxObject* sender, VfxId id); 
    void wapPushViewerMsgDelete(VfxBool showInfo, VfxU32 msgID);
    void wapPushViewerDataRecive(pmg_detailed_msg_struct *msg, VfxS8 *url);
    void onBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds);
    virtual void onDeinit();
    void onWapPushViewerDelete(VfxObject * obj, VfxId id);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
        //support all rotation
    }
};

#endif /* __VAPP_PUSH_MSG_BODY_H__ */

