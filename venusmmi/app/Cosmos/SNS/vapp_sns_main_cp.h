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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   vapp_sns_main.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements SNS class declaration.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#ifndef __VAPP_SNS_MAIN_CP_H__
#define __VAPP_SNS_MAIN_CP_H__
 
#include "MMI_features.h"

#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "MMIDataType.h"

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_var_height_menu.h"
#include "vcp_photo_border_frame.h"

#include "vapp_sns_base_cp.h"
#include "vapp_sns_main.h"

//#include "SnsTypes.h"
#include "SnsSrvTypes.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SNS_REQUEST_STATUS_BG		VFX_COLOR_RES(CLR_ID_VAPP_SNS_REQUEST_STATUS_BG)

/*****************************************************************************
 * Class Declaration
 *****************************************************************************/
#ifdef __MMI_SNS_CENTER__
// VappSnsSwitchBar class declaration
class VappSnsSwitchBar : public VcpPanelBar
{
    VFX_DECLARE_CLASS(VappSnsSwitchBar);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsSwitchBar();

// Enum
public:
    enum VappSnsSwitchTypeEnum
    {
        TYPE_NOTIFICATIONS,
        TYPE_REQUESTS,

        TYPE_TOTAL
    };

    enum Layout {
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
        DEFAULT_MARGIN = ((LCD_WIDTH - 220) / 2),           
    #elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_400X240__)
        DEFAULT_MARGIN = ((LCD_WIDTH - 220) / 2),            
    #elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X320__)
        DEFAULT_MARGIN = ((LCD_WIDTH - 290) / 2),
    #elif defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_800X480__)
        DEFAULT_MARGIN = ((LCD_WIDTH - 418) / 2),
    #endif
    };

// Override
protected:
    // Init function
    virtual void onInit();

// Implementation
public:
    // Set hight segment button
    void setSegmentPressed(
        VfxId id
    );

private:
    void onClick(VfxObject *sender, VfxId id);

// Signal    
public:
    VfxSignal2 <VfxObject*, VfxId> m_signalClicked;

private:
    // Segment button
    VcpSegmentButton *m_segButton;
};
#endif /* __MMI_SNS_CENTER__ */

// VappSnsItemActivityCell class declaration
class VappSnsItemActivityCell : public VappSnsItemLauncherCell
{
    VFX_DECLARE_CLASS(VappSnsItemActivityCell);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsItemActivityCell(VfxBool supportRotate = VFX_FALSE);
    
    VappSnsItemActivityCell(VcpMenuPos menuPos, void *userData, VfxBool supportRotate = VFX_FALSE, VfxS32 listId = 0);    

// Override
protected:
    // Init function
    virtual void onInit();

    // Deinit function
    virtual void onDeinit();
    
    // Cell tapped event
    virtual void onCellTapped(VfxObject *sender, VfxId id);

    // Title or title image tapped
    virtual void onTitleTapped(VfxObject *sender, VfxChar *userId, VfxU32 provider);


// Implementation
public:
    // Set componet content
    void setInfo(void *info, VfxBool isTitleTappable, VfxBool isActive = VFX_TRUE);

    // Append customized frame
    void appendExtendString(srv_sns_activity_struct *realAct = NULL);

private:
    // Free data pointer
    void freeActPartialData();
    
    // Set data pointer
    void setActivityData(void *dataPtr);

    // Get data pointer
    void *getActivityData();

// Variable
private:
    // Is user name/image tappable
    VfxBool m_isTitleTappable;

    // Rotate flag
    VfxBool m_supportRotate;

    // List id
    VfxS32 m_listId;

    // Data pointer
    srv_sns_activity_struct *m_activity;
};


// VappSnsItemCommentsCell class declaration
class VappSnsItemCommentsCell : public VappSnsItemLauncherCell
{
    VFX_DECLARE_CLASS(VappSnsItemCommentsCell);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsItemCommentsCell(VcpMenuPos menuPos = VcpMenuPos(0, 0));

// Overridable
protected:
    // Init function
    virtual void onInit();

// Override
protected:
    // Title or title image tapped
    virtual void onTitleTapped(VfxObject *sender, VfxChar *userId, VfxU32 provider);

};


#ifdef __MMI_SNS_CENTER__
// VappSnsItemRequestCell class declaration
class VappSnsItemRequestCell : public VappSnsItemLauncherCell
{
    VFX_DECLARE_CLASS(VappSnsItemRequestCell);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsItemRequestCell(VcpMenuPos menuPos = VcpMenuPos(0, 0), void *data = NULL);

// Overridable
protected:
    // Init function
    virtual void onInit();

    // Update function 
    virtual void onUpdate();

    // Cell tapped event
    virtual void onCellTapped(VfxObject *sender, VfxId id);

    // Title or title image tapped
    virtual void onTitleTapped(VfxObject *sender, VfxChar *userId, VfxU32 provider);

// Implementation
public:
    // Set notification type
    void setNotificationType(srv_sns_object_enum type);

    // Set object id
    void setObjectId(VfxChar *objectId, VfxU16 len);

    // Set href id
    void setHref(VfxChar *href, VfxU16 len);

    // Enable request button
    void enableButton(VfxBool enable);

    // Set reqeust status
    void setStatus(VappSnsRequestCellStatus status, VfxBool notify = VFX_TRUE);

    // On button clicked handler
    void onButtonClicked(VfxObject *sender, VfxId id);

    // On popup button clicked
    void onPopupButtonClicked(VfxObject *sender, VfxId id);

    // event callback handler
    mmi_ret onEvtHdlr(mmi_event_struct *param);

// Signal
public:
    // Staus changed signal
    VfxSignal2 <VcpMenuPos, VappSnsRequestCellStatus> m_signalStatusChanged;
    
// Variable
private:
    enum {
        NOTOFICATION_OBJ_ID  = 0,
        NOTOFICATION_HREF_ID = 1,

        BUTTON_ID_ACCEPT = 2,
        BUTTON_ID_REJECT = 3
    };
    
    // Notification type
    srv_sns_object_enum m_type;

    // Reqeust status
    VappSnsRequestCellStatus m_status;

    // Accept button
    VcpButton *m_acceptBtn;

    // Reject button
    VcpButton *m_rejectBtn;

    // Status frame
    VfxTextFrame *m_statusFrame;

    // Status text
    VfxFrame *m_statusBg;

    // Com popup
    VcpConfirmPopup *m_confirmPopup; 

    // content url
    VfxWChar m_contentUrl[SRV_SNS_MAX_LEN_PIC_URL + 1];
};
#endif /* __MMI_SNS_CENTER__*/

#endif /* __SOCIAL_NETWORK_SUPPORT__ */
#endif /* __VAPP_SNS_MAIN_CP_H__ */

