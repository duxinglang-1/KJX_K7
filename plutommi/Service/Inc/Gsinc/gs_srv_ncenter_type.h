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
 *   gs_srv_ncenter_type.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   NcenterService type header file
 *
 * Author:
 * -------
 * 
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _GS_SRV_NCENTER_TYPE_
#define _GS_SRV_NCENTER_TYPE_


#define NOTI_MEM_POOL_KB 20
#define NOTI_MEM_POOL_MARGIN_B 20


#define GS_NOTIFICATION_FLAG_DEFAULT GS_NOTIFICATION_FLAG_AUTO_CLOSE | GS_NOTIFICATION_FLAG_AUTO_LAUNCH
#define GS_NOTIFICATION_INVALID_ID 0xFFFFFFFF
#define GS_NGROUP_INVALID_ID 0xFFFFFFFF

typedef enum
{
    GS_NOTIFICATION_FLAG_STABLE         = 1 << 0,
    GS_NOTIFICATION_FLAG_AUTO_CLOSE     = 1 << 1,
    GS_NOTIFICATION_FLAG_AUTO_LAUNCH    = 1 << 2,
    GS_NOTIFICATION_FLAG_OLD            = 1 << 3,
    GS_NOTIFICATION_FLAG_END            = 1 << 4
}GsNotificationFlag;

typedef enum 
{
    GS_NOTIFICATION_TYPE_BASE,
    GS_NOTIFICATION_TYPE_EVENT,
    GS_NOTIFICATION_TYPE_ONGOING,
    GS_NOTIFICATION_TYPE_CUSTOM,    
    GS_NOTIFICATION_TYPE_END
}GsNotificationType;

typedef enum
{
    GS_NGROUP_TYPE_BASE,
    GS_NGROUP_TYPE_SINGLE_TITLE,
    GS_NGROUP_TYPE_END
}GsNGroupType;

typedef enum 
{
    GS_NSTATUS_CREATE,
    GS_NSTATUS_UPDATE,
    GS_NSTATUS_CLOSE,
    GS_NSTATUS_END
}GsNStatusType;


typedef enum 
{
    GS_NINTENT_TYPE_ENTER,    
    GS_NINTENT_TYPE_ENTERED,    
    GS_NINTENT_TYPE_EXIT,     
    GS_NINTENT_TYPE_EXITED,   
    GS_NINTENT_TYPE_LAUNCH,
    GS_NINTENT_TYPE_TERMINATE,
    GS_NINTENT_TYPE_TAP,
    GS_NINTENT_TYPE_AFTER_REQUEST_LEAVE,
    GS_NINTENT_TYPE_CLEAR_ALL,    
    GS_NINTENT_TYPE_END
}GsNIntentType;

typedef enum 
{
    GS_NVIEWER_TYPE_INVALID            = 1 << 0, 
    GS_NVIEWER_TYPE_GENERAL            = 1 << 1,
    GS_NVIEWER_TYPE_VAPP_NCENTER       = 1 << 2,
    GS_NVIEWER_TYPE_VAPP_SCREEN_LOCK   = 1 << 3,    
    GS_NVIEWER_TYPE_END                = 1 << 4 
}GsNViewerType;

typedef struct gs_list_entry_struct
{
    struct gs_list_entry_struct *next_entry;
    struct gs_list_entry_struct *prev_entry;
} gs_list_entry_struct_int;

typedef enum
{
    GS_IMAGE_SRC_TYPE_NULL = 0,             /* Null image */
    GS_IMAGE_SRC_TYPE_RES_ID,               /* Image from resource ID (Only for VfxImageSrc) */
    GS_IMAGE_SRC_TYPE_PATH,                 /* Image from file path pointer */
    GS_IMAGE_SRC_TYPE_MEM,                   /* Image from mem buffer */
    
    GS_IMAGE_SRC_TYPE_MAX
}gs_image_src_type_enum;

typedef U32* IMG_HANDLE;

typedef struct
{
    gs_image_src_type_enum type;            /* Image source type */
    union
    {
        IMG_HANDLE      res_id;                  /* Resource ID if using MMI_IMAGE_SRC_TYPE_RES_ID type */
        WCHAR path[256];                    /* File path if using MMI_IMAGE_SRC_TYPE_PATH */
        U8* mem;                             /* Mem address if using MMI_IMAGE_SRC_TYPE_MEM */
    } data;
}gs_image_src_struct;

typedef struct
{
    U16 nYear;
    U8 nMonth;
    U8 nDay;
    U8 nHour;
    U8 nMin;
    U8 nSec;
    U8 DayIndex; /* 0=Sunday */
} gs_time_struct;

typedef U32 GsNotificationId;
typedef U32 GsNGroupId;
    
typedef void* gs_ngroup_handle;
typedef void* gs_notification_handle;

typedef GsNGroupId gs_ngroup_id;
typedef GsNotificationId gs_notification_id;

typedef gs_list_entry_struct_int* gs_ngroup_entry;
typedef gs_list_entry_struct_int* gs_notification_entry;

typedef GsNGroupType gs_ngroup_type;
typedef GsNotificationType gs_notification_type;

typedef GsNViewerType gs_nviewer_type;
typedef GsNIntentType gs_nintent_type;

typedef struct 
{
    gs_nintent_type type;
    gs_nviewer_type viewer;
    void* intentData;
}gs_nintent;


typedef void (*gs_nitent_funcptr)(gs_notification_handle, gs_nintent intent, void* userData, U32 userDataSize);


#endif //_GS_SRV_NCENTER_TYPE_


