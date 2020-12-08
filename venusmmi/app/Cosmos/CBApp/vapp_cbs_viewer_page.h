/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  Vapp_cbs_viewer_page.h
 *
 * Project:
 * --------
 *  App CBS
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
 ****************************************************************************/
#ifndef __VAPP_CBS_VIEWER_PAGE_H__
#define __VAPP_CBS_VIEWER_PAGE_H__
#include "mmi_features.h"

/***************************************************************************** 
 * Include
 *****************************************************************************/
//#define __CBS_XML_LAYOUT_


#include "vfx_xml_loader.h"

#include "vapp_cbs_iprot.h"
#include ".\cosmos\message\vapp_msg_use_detail.h"
#include "vcp_photo_border_frame.h"

#include "mmi_rp_app_vapp_sms_def.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#if 1

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Class Xyz
 ****************************************************************************/
/***************************************************************************** 
 * VappCbsViewerPage 
 *****************************************************************************/

class VappCbsViewerPage : public VfxPage
{

    //VFX_DECLARE_CLASS(VappCbsViewerPage);
// Declaration

// Constructor / Destructor
public:
    VappCbsViewerPage(VfxS32 sim);
    //void setSim(VappCbsSimEnum simId);
    //void setMsgId(VfxId msgId);
    //void setChannelId(VfxId channel);

	void setMsgIdAndChannelId(VfxId msgId, VfxId channel);
    VfxBool readContent();
    void confirmHandler(VfxObject* obj, VfxId id);
    static mmi_ret cbsMsgChangeProc(mmi_event_struct *evt);
    void onToolBarClicked(VfxObject *sender, VfxId id); 
    void onKeywordClicked(VcpTextKeyWordEnum mode, VfxWChar *text, VfxS32 len);
    void setElements();// layout title, layout text viewer
    void updateContent();
    
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );
    
private:
    void deleteCurrMsg();
#ifdef __MMI_SMS_DETAILS_INFO__
    void addAddrItemToUseDetail(VappMsgUseDetailProvider* provider);
#endif
    //void showErrorConfirm(VfxWString string);
    void emitMsgViewedEvt();
    void initElements();

    void deleteMemberFromLayout();
	VappMsgAddrType keywordToAddrtype(VcpTextKeyWordEnum mode);
    
// Variable
private:
    enum // toolbar items
    {
        DELETE,
	#ifdef __MMI_SMS_DETAILS_INFO__
        USE_DETAIL
    #endif
    };
    VfxId m_channelId;
    VfxId m_msgId;
    VfxS32 m_sim;
    VfxBool m_isDeleting;
    VfxWChar m_msgContent[SRV_CBS_MAX_CONTENT_LEN + 1];
    VcpConfirmPopup *m_confirmPopup;

    VfxFrame *m_bgFrame;
    VcpTextView *m_contentText;
    VcpToolBar *m_toolBar;
    VfxTextFrame *m_timestampFrame;
    
    VfxTextFrame *m_titleText; // height is same as m_cion and width = parent_width - height
    VfxTextFrame *m_titleId;
    VfxFrame *m_icon;
    VfxFrame *m_iconBorder;
    VfxFrame *m_iconBg;
    VfxFrame *m_titleBgFrame;

	VappMsgAddrOption *m_addrOption;
	VfxWeakPtr<VfxObject> m_detailsPage;
};
 

 /* viewer pages end*/
 
#endif // __viewer
#endif /* __VAPP_CBS_SETTING_PAGE_H__ */


