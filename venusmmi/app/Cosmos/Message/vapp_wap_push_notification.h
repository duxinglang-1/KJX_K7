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
 *  vapp_wap_push_notification.h
 *
 * Project:
 * --------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_WAP_PUSH_NOTIFICATION_H__
#define __VAPP_WAP_PUSH_NOTIFICATION_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "common\ncenter\vapp_ncenter_base_cell.h"

#include "common\ncenter\vsrv_notification.h"
#include "common\ncenter\vsrv_ncenter.h"
#include "common\ncenter\Vsrv_ndeclaration.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "WAPPushSrvProts.h"
#include "WAPPushSrvTypes.h"
     


#ifdef __cplusplus
}
#endif
#include "NotificationGprot.h"
#include "mmi_rp_srv_status_icons_def.h"


/*****************************************************************************
 * Class VappFirstCell
 *****************************************************************************/
 
enum
{
	VAPP_PUSH_NOTIFICATION_CONFIRM_ACCEPT_SIR,
	VAPP_PUSH_NOTIFICATION_CONFIRM_REJECT_SIR,
	VAPP_PUSH_NOTIFICATION_CONFIRM_ACCEPT_UNKNOWN_ADDR,
	VAPP_PUSH_NOTIFICATION_CONFIRM_ACCEPT_AND_ADD_UNKNOWN_ADDR,
	VAPP_PUSH_NOTIFICATION_CONFIRM_REJECT_UNKNOWN_ADDR,
	VAPP_PUSH_NOTIFICATION_CONFIRM_REJECT_AND_ADD_UNKNOWN_ADDR,
	VAPP_PUSH_NOTIFICATION_CONFIRM_POPUP_TOTAL
};

class VappPushNotificationScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappPushNotificationScr);

// constuctor / destructor
public:    
    VappPushNotificationScr(){}

    VappPushNotificationScr(VfxU32 msgId, VfxU32 msgType);	

    virtual ~VappPushNotificationScr() {}

// override
public:
    virtual void onDeinit();
    virtual void on1stReady();
    void setGroupID(mmi_id groupID){ m_groupID = groupID;}
    
    VcpIndicatorPopup *m_popup;
    mmi_id m_groupID;
    VfxU32 m_msgId;
    VfxU32 m_msgType;

// method
public:    
    void onSIHighConfirm(VfxObject* obj, VfxId id);
    void onSLHighConfirm(VfxObject* obj, VfxId id);
    void onLauchMsgURLNotify(void);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);

};

class VappPushNotificationApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappPushNotificationApp);

public: 
    VappPushNotificationApp(){}
    virtual ~VappPushNotificationApp() {}
    
public:
    // initial parameter and entry main src
    virtual void onRun(
        void *arg,          // parameter
        VfxU32 argSize      // parameter size  
    );

// Method
private:
    VappPushNotificationScr *m_scr;
};

#ifdef WAP_SUPPORT

class VappWapPushNCenterHdlr : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappWapPushNCenterHdlr);
	
    VappWapPushNCenterHdlr()
    {
        m_isShow = VFX_FALSE;
        m_popupHandle = 0;
        m_isCellActive = VFX_FALSE;
    };

public:

    virtual void onInit();
    void showNSSContent(VfxWString* previewText);
    void createView();
    void updateCellStatus (void);
    void connectUnKnownListDataReceive (VfxU32 type);
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    void onTrustlistSettingScrActive (VfxBool isActive);
#endif
    VfxBool m_isShow;
    VfxU32 m_notificationOption;
    VfxS32 m_popupHandle;
    VfxBool m_isCellActive;
};

void onConfirmDialog (VfxId id, void *userData) ;
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
void onConfirmUnmatchedAddressDialog (VfxId id, void *userData) ;
#endif

void onTap(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize);
void onShowNsCeContent();
extern "C" mmi_ret onTapNSSCallback (mmi_event_struct *param);
static mmi_ret postCall(mmi_event_struct *param);

#endif
#endif /* __VAPP_WAP_PUSH_NOTIFICATION_H__ */

