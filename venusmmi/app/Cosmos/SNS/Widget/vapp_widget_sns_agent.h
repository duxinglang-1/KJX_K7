/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_agent.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the agent for sns widget.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_SNS_AGENT_H
#define VAPP_WIDGET_SNS_AGENT_H

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_VUI_HOMESCREEN_SNS__)
#include "vcp_include.h"
#include "vapp_sns_base.h" 


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#define VAPP_WIDGET_SNS_AUTO_REFRESH_MSEC (15 * 60 * 1000)

enum pageType {
    PAGE_TYPE_ACCOUNT_SETTINGS,
    PAGE_TYPE_FRIENDS_SELECTOR,
    PAGE_TYPE_HAPPENINGS_VIEWER,
    PAGE_TYPE_PICTURE_VIEWER,
};

struct pageInformation {
    pageType    type;
    void        *data;
    VfxU32      provider;
    VfxChar     *id;
    VfxS32      list_id;
    VfxS32      index;
};


// VappSnsAppAgent class declaration
class VappSnsWidgetAgent : public VappSnsBaseAgent
{
    VFX_DECLARE_CLASS(VappSnsWidgetAgent);

// Constrctor / Destructor
public:
    // Default constructor
    VappSnsWidgetAgent(VfxBool auto_init = VFX_TRUE);

// Method
public:
    // Get activities list
    VfxS32 getActivities(
        srv_sns_activity_enum type,
        VfxU32 provider,                      // either select by provider
        VfxU16 group,                         // or select by group
        VfxBool isDownloadPic,
        VfxBool forceRefresh
    );

    VfxS32 getSelectedFriends(
    );

    void editMemberConfirm(
        srv_sns_user_list_struct *userList, 
        VfxU8 userListSize, 
        VfxBool toAdd
    );

    mmi_ret groupOpCallbackHandler(
        mmi_event_struct *param
    );

    // Get activities list by users
    VfxS32 getActivityByUser(
        VfxU32 provider,
        VfxChar *id, 
        VfxBool refresh
    );

    VfxS32 downloadPic(
        VfxS32 list_id, 
        VfxS16 index, 
        srv_sns_pic_enum type
    );

    VfxS32 getNewsReminderSetting(
    );

    VfxU8 getDefaultStorage(
    );

    VfxBool isPBMSaved(
        VfxU8 *id
    );

    // Group updated signal
    VfxSignal1<srv_sns_result> m_signalGroupOpFinished;

private:

    VfxU8 m_storage;
};


#endif /* VAPP_WIDGET_SNS_AGENT_H */
#endif /* __MMI_VUI_HOMESCREEN_SNS__ */
