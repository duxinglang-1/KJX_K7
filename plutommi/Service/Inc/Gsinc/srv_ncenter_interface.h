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
 *   srv_ncenter_interface.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   INcenter interface
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
 
#include "gs_id.h"
#include "gs_base.h"

#define GS_C_INTERFACE
#include "gs_srv_ncenter_interface_def.h"

#include "gs_srv_ncenter_type.h"

/*****************************************************************************
 * INcenter methods
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  INcenter_addRef
 * DESCRIPTION
 *  add class reference
 * PARAMETERS
 *  obj   [IN] object pointer returned by vm_create_service
 * RETURNS
 *  reference count
 *****************************************************************************/
S32 __inline INcenter_addRef(INcenter *obj)
{
    return obj->vt->addRef(obj);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_release
 * DESCRIPTION
 *  release class reference
 * PARAMETERS
 *  obj   [IN] object pointer returned by vm_create_service
 * RETURNS
 *  reference count
 *****************************************************************************/
S32 __inline INcenter_release(INcenter *obj)
{
    return obj->vt->release(obj);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_queryInterface
 * DESCRIPTION
 *  get relative object
 * PARAMETERS
 *  obj   [IN] object pointer returned by vm_create_service
 *  iid   [IN] inferface id
 *  pptr   [OUT] inferface pointer
 * RETURNS
 *  0 if sucess
 *****************************************************************************/
S32 __inline INcenter_queryInterface(INcenter *obj, S32 iid, GS_IBase **pptr)
{
    return obj->vt->queryInterface(obj, iid, pptr);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_create_ngroup
 * DESCRIPTION
 *  create notification group 
 * PARAMETERS
 *  obj   [IN] object pointer
 *  group type   [IN] group type,
 *  group id     [IN] group ID
 * RETURNS
 *  notification group handle
 *****************************************************************************/ 
gs_ngroup_handle __inline INcenter_create_ngroup(INcenter *obj,gs_ngroup_type type, gs_ngroup_id gid)
{
    return obj->vt->create_ngroup(obj,type,gid);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_create_notification
 * DESCRIPTION
 *  create notification
 * PARAMETERS
 *  obj   [IN] object pointer 
 *  notification type   [IN] notification type
 *  group id            [IN] group ID
 * RETURNS
 *  notification handle
 *****************************************************************************/
gs_notification_handle __inline INcenter_create_notification(INcenter *obj,gs_notification_type type, gs_ngroup_handle ghandle, gs_notification_id nid)
{
    return obj->vt->create_notification(obj,type,ghandle,nid);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_query_ngroup
 * DESCRIPTION
 *  query ngroup by group id
 * PARAMETERS
 *  obj   [IN] object pointer  
 *  group id     [IN] group ID assigned by user
 * RETURNS
 *  notification group handle
 *****************************************************************************/
gs_ngroup_handle __inline INcenter_query_ngroup(INcenter *obj,gs_ngroup_id gid)
{
    return obj->vt->query_ngroup(obj,gid);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_ngroup_entry
 * DESCRIPTION
 *  query notification by notification id
 * PARAMETERS
 *  obj   [IN] object pointer  
 *  notification id     [IN] notification ID assigned by user
 * RETURNS
 *  notification handle
 *****************************************************************************/ 
gs_ngroup_entry __inline INcenter_get_ngroup_entry(INcenter *obj)
{
    return obj->vt->get_ngroup_entry(obj);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_next_ngroup_entry
 * DESCRIPTION
 *  get the next ngroup entry, entry is used to iterate all ngroups
 * PARAMETERS
 *  obj   [IN] object pointer 
 *  ngroup entry    [IN] current ngroup entry
 * RETURNS
 *  the next ngroup entry
 *****************************************************************************/
gs_ngroup_entry __inline INcenter_get_next_ngroup_entry(INcenter *obj,gs_ngroup_entry gentry)
{
    return obj->vt->get_next_ngroup_entry(obj,gentry);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_notification_entry
 * DESCRIPTION
 *  get the first notification entry, entry is used to iterate all notifications
 * PARAMETERS
 *  obj   [IN] object pointer 
 *  notification entry    [IN] current notification entry
 * RETURNS
 *  the first notification entry
 *****************************************************************************/
gs_notification_entry __inline INcenter_get_notification_entry(INcenter *obj,gs_ngroup_handle ghandle)
{
    return obj->vt->get_notification_entry(obj,ghandle);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_next_notification_entry
 * DESCRIPTION
 *  get the next notification entry, entry is used to iterate all notification
 * PARAMETERS
 *  obj   [IN] object pointer  
 *  notification entry    [IN] current notification entry
 * RETURNS
 *  the next notification entry
 *****************************************************************************/
gs_notification_entry __inline INcenter_get_next_notification_entry(INcenter *obj,gs_notification_entry nentry)
{
    return obj->vt->get_next_notification_entry(obj,nentry);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_ngroup
 * DESCRIPTION
 *  get ngroup by ngroup entry
 * PARAMETERS
 *  obj   [IN] object pointer  
 *  ngroup entry    [IN] current ngroup entry
 * RETURNS
 *  ngroup handle
 *****************************************************************************/
gs_ngroup_handle __inline INcenter_get_ngroup(INcenter *obj,gs_ngroup_entry nentry)
{
    return obj->vt->get_ngroup(obj,nentry);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_notification
 * DESCRIPTION
 *  get notification by notification entry
 * PARAMETERS
 *  notification entry    [IN] current notification entry
 * RETURNS
 *  notification handle
 *****************************************************************************/
gs_notification_handle __inline INcenter_get_notification(INcenter *obj,gs_notification_entry nentry)
{
    return obj->vt->get_notification(obj,nentry);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_query_notification
 * DESCRIPTION
 *  query notification by notification id
 * PARAMETERS
 *  obj   [IN] object pointer  
 *  notification id     [IN] notification ID assigned by user
 * RETURNS
 *  notification handle
 *****************************************************************************/
gs_notification_handle __inline INcenter_query_notification(INcenter *obj,gs_ngroup_handle ghandle, gs_notification_id nid)
{
    return obj->vt->query_notification(obj,ghandle,nid);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_close_ngroup
 * DESCRIPTION
 *  close notification group 
 * PARAMETERS
 *  obj   [IN] object pointer   
 *  group handle   [IN] 
 * RETURNS
 *  TRUE if close successfully
 *****************************************************************************/
BOOL __inline INcenter_close_ngroup(INcenter *obj,gs_ngroup_handle ghandle)
{
    return obj->vt->close_ngroup(obj,ghandle);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_close_notification
 * DESCRIPTION
 *  close notification 
 * PARAMETERS
 *  obj   [IN] object pointer   
 *  notification handle   [IN] 
 * RETURNS
 *  TRUE if close successfully
 *****************************************************************************/
BOOL __inline INcenter_close_notification(INcenter *obj,gs_notification_handle nhandle)
{
    return obj->vt->close_notification(obj,nhandle);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_ngroup_id
 * DESCRIPTION
 *  get ngroup ID by ngroup handle
 * PARAMETERS
 *  obj   [IN] object pointer  
 *  ngroup handle    [IN]
 * RETURNS
 *  ngroup id
 *****************************************************************************/
gs_ngroup_id __inline INcenter_get_ngroup_id(INcenter *obj,gs_ngroup_handle ghandle)
{
    return obj->vt->get_ngroup_id(obj,ghandle);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_notification_id
 * DESCRIPTION
 *  get notification ID by notification handle
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle    [IN]
 * RETURNS
 *  notification id
 *****************************************************************************/
gs_notification_id __inline INcenter_get_notification_id(INcenter *obj,gs_notification_handle nhandle)
{
    return obj->vt->get_notification_id(obj,nhandle);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_set_ngroup_title
 * DESCRIPTION
 *  set ngroup title, works if group type is NGROUP_TYPE_SINGLE_TITLE
 * PARAMETERS
 *  obj   [IN] object pointer
 *  ngroup handle  [IN]
 *  group title    [IN]
 * RETURNS
 *  TRUE if title set
 *****************************************************************************/
BOOL __inline INcenter_set_ngroup_title(INcenter *obj,gs_ngroup_handle ghandle, WCHAR* title)
{
    return obj->vt->set_ngroup_title(obj,ghandle,title);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_set_notification_icon
 * DESCRIPTION
 *  set notification icon, works if notification type is NOTIFICATION_TYPE_EVENT, NOTIFICATION_TYPE_ONGOING
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle  [IN]
 *  image icon           [IN]
 * RETURNS
 *  TRUE if icon set
 *****************************************************************************/
BOOL __inline INcenter_set_notification_icon(INcenter *obj,gs_notification_handle nhandle, gs_image_src_struct icon)
{
    return obj->vt->set_notification_icon(obj,nhandle,icon);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_notification_icon
 * DESCRIPTION
 *  get notification icon, works if notification type is NOTIFICATION_TYPE_EVENT, NOTIFICATION_TYPE_ONGOING
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle  [IN]
 *  image icon           [OUT]
 * RETURNS
 *  TRUE if icon got
 *****************************************************************************/
BOOL __inline INcenter_get_notification_icon(INcenter *obj,gs_notification_handle nhandle, gs_image_src_struct *icon)
{
    return obj->vt->get_notification_icon(obj,nhandle,icon);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_set_notification_maintext
 * DESCRIPTION
 *  set notification maintext, works if notification type is NOTIFICATION_TYPE_EVENT, NOTIFICATION_TYPE_ONGOING
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle  [IN]
 *  main text            [IN]
 * RETURNS
 *  TRUE if maintext set
 *****************************************************************************/
BOOL __inline INcenter_set_notification_maintext(INcenter *obj,gs_notification_handle nhandle, WCHAR* text)
{
    return obj->vt->set_notification_maintext(obj,nhandle,text);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_notification_maintext
 * DESCRIPTION
 *  get notification maintext, works if notification type is NOTIFICATION_TYPE_EVENT, NOTIFICATION_TYPE_ONGOING
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle  [IN]
 *  text buffer          [OUT]
 *  text buffer size     [IN] 
 * RETURNS
 *  TRUE if maintext got
 *****************************************************************************/
BOOL __inline INcenter_get_notification_maintext(INcenter *obj,gs_notification_handle nhandle, WCHAR* text, U32 bufsize)
{
    return obj->vt->get_notification_maintext(obj,nhandle,text,bufsize);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_set_notification_subtext
 * DESCRIPTION
 *  set notification subtext, works if notification type is NOTIFICATION_TYPE_EVENT, NOTIFICATION_TYPE_ONGOING
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle  [IN]
 *  subtext            [IN]
 * RETURNS
 *  TRUE if subtext set
 *****************************************************************************/
BOOL __inline INcenter_set_notification_subtext(INcenter *obj,gs_notification_handle nhandle, WCHAR* text)
{
    return obj->vt->set_notification_subtext(obj,nhandle,text);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_notification_subtext
 * DESCRIPTION
 *  get notification subtext
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle  [IN]
 *  text buffer          [OUT]
 *  text buffer size     [IN] 
 * RETURNS
 *  TRUE if subtext got
 *****************************************************************************/
BOOL __inline INcenter_get_notification_subtext(INcenter *obj,gs_notification_handle nhandle, WCHAR* text, U32 bufsize)
{
    return obj->vt->get_notification_subtext(obj,nhandle,text,bufsize);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_set_notification_questiontext
 * DESCRIPTION
 *  set notification questiontext, works if notification type is NOTIFICATION_TYPE_ONGOING
 *  this question text is used to confirm with user that the ongoing APP will be terminated
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle  [IN]
 *  questiontext         [IN]
 * RETURNS
 *  TRUE if questiontext set
 *****************************************************************************/
BOOL __inline INcenter_set_notification_questiontext(INcenter *obj,gs_notification_handle nhandle, WCHAR* text)
{
    return obj->vt->set_notification_questiontext(obj,nhandle,text);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_notification_questiontext
 * DESCRIPTION
 *  get notification questiontext
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle  [IN]
 *  text buffer          [OUT]
 *  text buffer size     [IN]
 * RETURNS
 *  TRUE if questiontext got
 *****************************************************************************/
BOOL __inline INcenter_get_notification_questiontext(INcenter *obj,gs_notification_handle nhandle, WCHAR* text, U32 bufsize)
{
    return obj->vt->get_notification_questiontext(obj,nhandle,text,bufsize);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_set_notification_timestamp
 * DESCRIPTION
 *  set notification timestamp, works for all notification type
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle  [IN]
 *  timestamp         [IN]
 * RETURNS
 *  TRUE if timestamp set
 *****************************************************************************/
BOOL __inline INcenter_set_notification_timestamp(INcenter *obj,gs_notification_handle nhandle, gs_time_struct *timestamp)
{
    return obj->vt->set_notification_timestamp(obj,nhandle,timestamp);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_notification_timestamp
 * DESCRIPTION
 *  get notification timestamp, works for all notification type
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle  [IN]
 *  timestamp            [OUT]
 * RETURNS
 *  TRUE if timestamp got
 *****************************************************************************/
BOOL __inline INcenter_get_notification_timestamp(INcenter *obj,gs_notification_handle nhandle, gs_time_struct *timestamp)
{
    return obj->vt->get_notification_timestamp(obj,nhandle,timestamp);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_set_notification_intent_callback
 * DESCRIPTION
 *  set notification intent callback, the notification sender can process according to the different intent type in this callback,
 *  works for all notification type
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle  [IN]
 *  callback             [IN]
 *  userdata             [IN] ncenter service will copy this userdata
 *  userdataSize         [IN] 
 * RETURNS
 *  TRUE if callback set
 *****************************************************************************/
BOOL __inline INcenter_set_notification_intent_callback(INcenter *obj,gs_notification_handle nhandle, gs_nitent_funcptr callback, void *userdata, U32 userdata_size)
{
    return obj->vt->set_notification_intent_callback(obj,nhandle,callback,userdata,userdata_size);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_notification_userdata
 * DESCRIPTION
 *  get userdata used in notification intent callback, works for all notification type
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle  [IN]
 * RETURNS
 *  userdata or NULL
 *****************************************************************************/
void __inline *INcenter_get_notification_userdata(INcenter *obj,gs_notification_handle nhandle)
{
    return obj->vt->get_notification_userdata(obj,nhandle);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_get_notification_userdata_size
 * DESCRIPTION
 *  get userdata size used in notification intent callback, works for all notification type
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle  [IN]
 * RETURNS
 *  userdata size or 0
 *****************************************************************************/
U32 __inline INcenter_get_notification_userdata_size(INcenter *obj,gs_notification_handle nhandle)
{
    return obj->vt->get_notification_userdata_size(obj,nhandle);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_notify_notification
 * DESCRIPTION
 *  notify the notification
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification handle  [IN]
 * RETURNS
 *  TRUE if notification notified
 *****************************************************************************/
BOOL __inline INcenter_notify_notification(INcenter *obj,gs_notification_handle nhandle)
{
    return obj->vt->notify_notification(obj,nhandle);
}

/*****************************************************************************
 * FUNCTION
 *  INcenter_send_intent
 * DESCRIPTION
 *  viewer send intent to the notification sender
 * PARAMETERS
 *  obj   [IN] object pointer
 *  notification viewer type   [IN] 
 *  notification intent type   [IN]
 *  notification handle        [IN] NULL if viewer wants to send intent to all notification sender
 * RETURNS
 *  TRUE if intent sent
 *****************************************************************************/
BOOL __inline INcenter_send_intent(INcenter *obj,gs_nviewer_type viewer, gs_nintent_type type, gs_notification_handle nhandle)
{
    return obj->vt->send_intent(obj,viewer,type,nhandle);
}

