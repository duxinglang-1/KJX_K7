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
 *  vfx_ncenter.h
 *
 * Project:
 * --------
 *  COSMOS Notification Center
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VSRV_NDECLARATION_H__
#define __VSRV_NDECLARATION_H__

#include "MMIDataType.h"
#include "vrt_base_list.h"
    


#define NOTI_MEM_POOL_KB (15)
#define NOTI_MEM_POOL_MARGIN_B (20)

#define VSRV_NOTIFICATION_FLAG_AUTO_CLOSE (VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TAP | VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_CLEAR | \
                                       VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_LAUNCH | VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TERMINATE | \
                                       VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_REQUEST_LEAVE)
                                       
#define VSRV_NOTIFICATION_FLAG_DEFAULT (VSRV_NOTIFICATION_FLAG_AUTO_CLOSE | VSRV_NOTIFICATION_FLAG_AUTO_LAUNCH)

#define VSRV_NOTIFICATION_FLAG_MASK (VSRV_NOTIFICATION_FLAG_AUTO_CLOSE | VSRV_NOTIFICATION_FLAG_AUTO_LAUNCH | \
                                     VSRV_NOTIFICATION_FLAG_NO_NSS | VSRV_NOTIFICATION_FLAG_NO_CLEAR_BUTTON | \
                                     VSRV_NOTIFICATION_FLAG_NO_FOCUS)

                                       
#define VSRV_NOTIFICATION_INVALID_ID (0xFFFFFFFF)
#define VSRV_NGROUP_INVALID_ID (0xFFFFFFFF)

#if defined(__MMI_MAINLCD_320X480__)   
    #define VSRV_NCELL_DEFAULT_HEIGHT (51)
#elif defined(__MMI_MAINLCD_480X800__)
    #define VSRV_NCELL_DEFAULT_HEIGHT (86)    
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__)
    #define VSRV_NCELL_DEFAULT_HEIGHT (45)    
#else
    #define VSRV_NCELL_DEFAULT_HEIGHT (51)    
#endif


// <group DOM_NCenter_VsrvNotificationFlag_Enum>
// This enum is for notification flag
typedef enum
{
    VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TAP           = 1 << 0, // Close after tap the cell on NCenter (autoLaunch false) 
    VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_CLEAR         = 1 << 1, // Close after click the "clear all" button on NCenter 
    VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_LAUNCH        = 1 << 2, // Close after launch on NCenter (autoLaunch true)   
    VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TERMINATE     = 1 << 3, // Close after tap "OK" button in the confirm popup on NCenter 
    VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_REQUEST_LEAVE = 1 << 4, // Close after requestLeave(VsrvNotification* noti) called   
    VSRV_NOTIFICATION_FLAG_AUTO_LAUNCH                    = 1 << 5, // After tapping a cell in NCenter, send LAUNCH intent to the notification.Otherwise, the service send TAP intent to the notification.
    VSRV_NOTIFICATION_FLAG_NO_NSS                         = 1 << 6, // ignore NSS(notification setting service) on viewers 
    VSRV_NOTIFICATION_FLAG_NO_CLEAR_BUTTON                = 1 << 7, // Hide clear button if only your notification on viewer   
    VSRV_NOTIFICATION_FLAG_NO_FOCUS                       = 1 << 8, // Disable key focus on your notification 

/* DOM-NOT_FOR_SDK-BEGIN */
    //under this line, the flags are internal used only
    VSRV_NOTIFICATION_FLAG_STABLE                         = 1 << 9,
    VSRV_NOTIFICATION_FLAG_OLD                            = 1 << 10,
    VSRV_NOTIFICATION_FLAG_END                            = 1 << 11
/* DOM-NOT_FOR_SDK-END */    
}VsrvNotificationFlag;


// <group DOM_NCenter_VsrvNotificationType_Enum>
// This enum is for notification type
typedef enum 
{
    VSRV_NOTIFICATION_TYPE_BASE,    // VsrvNotification
    VSRV_NOTIFICATION_TYPE_EVENT,   // VsrvNotificationEvent
    VSRV_NOTIFICATION_TYPE_ONGOING, // VsrvNotificationOngoing
    VSRV_NOTIFICATION_TYPE_CUSTOM,  // VsrvNotificationCustom
    VSRV_NOTIFICATION_TYPE_END
}VsrvNotificationType;

// <group DOM_NCenter_VsrvNGroupType_Enum>
// This enum is for notification group type
typedef enum
{
    VSRV_NGROUP_TYPE_BASE,          // VsrvNGroup
    VSRV_NGROUP_TYPE_SINGLE_TITLE,  // VsrvNGroupSingleTitle
    VSRV_NGROUP_TYPE_END
}VsrvNGroupType;

// <group DOM_NCenter_VsrvNStatusType_Enum>
// This enum is for notification activity status
typedef enum 
{
    VSRV_NSTATUS_CREATE,  // create
    VSRV_NSTATUS_UPDATE,  // update
    VSRV_NSTATUS_CLOSE,   // close
    VSRV_NSTATUS_END
}VsrvNStatusType;

// <group DOM_NCenter_VsrvNIntentType_Enum>
// This enum is for intent type 
typedef enum 
{
    VSRV_NINTENT_TYPE_ENTER,                // notification viewers enter
    VSRV_NINTENT_TYPE_ENTERED,              // notification viewers entered
    VSRV_NINTENT_TYPE_EXIT,                 // notification viewers exit
    VSRV_NINTENT_TYPE_EXITED,               // notification viewers exited
    VSRV_NINTENT_TYPE_LAUNCH,               // User tap the notification on Viewer if AutoLaunch is true
    VSRV_NINTENT_TYPE_TERMINATE,            // User tap the notification on Viewer if AutoLaunch is false
    VSRV_NINTENT_TYPE_TAP,                  // User confirm to terminate APP
    VSRV_NINTENT_TYPE_CLEAR,                // User click the "clear all" button in notification tab
    VSRV_NINTENT_TYPE_CLOSE,                // The notification will be closed 
    VSRV_NINTENT_TYPE_AFTER_REQUEST_LEAVE,  // Sent when APP called VappNCenter->requestLeave(notification) 
    VSRV_NINTENT_TYPE_LANGUAGE_CHANGED,     // User changed phone language from setting
    VSRV_NINTENT_TYPE_END
}VsrvNIntentType;

// <group DOM_NCenter_VsrvNViewerType_Enum>
// This enum is for notification viewr
typedef enum 
{    
    VSRV_NVIEWER_TYPE_GENERAL            = 1 << 0,  // for all viewers
    VSRV_NVIEWER_TYPE_VSRV_NCENTER       = 1 << 1,  // VsrvNCenter
    VSRV_NVIEWER_TYPE_VAPP_NCENTER       = 1 << 2,  // VappNCenter
    VSRV_NVIEWER_TYPE_VAPP_SCREEN_LOCK   = 1 << 3,  // VappScreenLock  
    VSRV_NVIEWER_TYPE_END                = 1 << 4   
}VsrvNViewerType;


// <group DOM_NCenter_VsrvNotificationCustomCategory_Enum>
// This enum is for custom notification category
typedef enum 
{
    VSRV_NOTIFICAITON_CUSTOM_CATEGORY_EVENT,       // event
    VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING,     // ongoing    
    VSRV_NOTIFICAITON_CUSTOM_CATEGORY_END,        
}VsrvNotificationCustomCategory;


typedef U32 VsrvNotificationId;
typedef U32 VsrvNGroupId;
    
typedef void* vsrv_ngroup_handle;
typedef void* vsrv_notification_handle;

typedef VsrvNGroupId vsrv_ngroup_id;
typedef VsrvNotificationId vsrv_notification_id;

typedef vrt_list_entry_handle vsrv_ngroup_entry;
typedef vrt_list_entry_handle vsrv_notification_entry;

typedef VsrvNGroupType vsrv_ngroup_type;
typedef VsrvNotificationType vsrv_notification_type;

typedef VsrvNViewerType vsrv_nviewer_type;
typedef VsrvNIntentType vsrv_nintent_type;

typedef VsrvNotificationFlag vsrv_notification_flag;

typedef struct
{
    VsrvNIntentType type;
    VsrvNViewerType viewer;
    void* intentData;
}VsrvNIntent;

typedef struct 
{
    vsrv_nintent_type type;
    vsrv_nviewer_type viewer;
    void* intentData;
}vsrv_nintent;


typedef void (*vsrv_nitent_funcptr)(vsrv_notification_handle, vsrv_nintent intent, void* userData, U32 userDataSize);



#endif /* __VSRV_NDECLARATION_H__ */

