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
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifndef __VSRV_NCENTER_H__
#define __VSRV_NCENTER_H__



#include "vsrv_ndeclaration.h"    
#include "app_datetime.h"    

    
#ifdef __cplusplus
extern "C"
{
#endif  

/**********************************************************************
 * External Interfaces:
**********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_create_ngroup
 * DESCRIPTION
 *  create notification group 
 * PARAMETERS
 *  group type   [IN] group type, e.g. VSRV_NGROUP_TYPE_BASE, VSRV_NGROUP_TYPE_SINGLE_TITLE
 *  group id     [IN] group ID, it will be APP_ID or VSRV_NGROUP_INVALID_ID
 * RETURNS
 *  notification group handle
 *****************************************************************************/ 
extern vsrv_ngroup_handle vsrv_ncenter_create_ngroup(vsrv_ngroup_type type, vsrv_ngroup_id gid);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_create_notification
 * DESCRIPTION
 *  create notification
 * PARAMETERS
 *  notification type   [IN] notification type, e.g. VSRV_NOTIFICATION_TYPE_EVENT, VSRV_NOTIFICATION_TYPE_ONGOING
 *  group id            [IN] group ID, it will be APP_ID or VSRV_NGROUP_INVALID_ID
 * RETURNS
 *  notification handle
 *****************************************************************************/ 
extern vsrv_notification_handle vsrv_ncenter_create_notification(vsrv_notification_type type, vsrv_ngroup_handle ghandle, vsrv_notification_id nid);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_close_ngroup
 * DESCRIPTION
 *  close notification group 
 * PARAMETERS
 *  group handle   [IN] 
 * RETURNS
 *  TRUE if close successfully
 *****************************************************************************/
extern BOOL vsrv_ncenter_close_ngroup(vsrv_ngroup_handle ghandle);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_close_notification
 * DESCRIPTION
 *  close notification 
 * PARAMETERS
 *  notification handle   [IN] 
 * RETURNS
 *  TRUE if close successfully
 *****************************************************************************/
extern BOOL vsrv_ncenter_close_notification(vsrv_notification_handle nhandle);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_query_ngroup
 * DESCRIPTION
 *  query ngroup by group id
 * PARAMETERS
 *  group id     [IN] group ID assigned by user
 * RETURNS
 *  notification group handle
 *****************************************************************************/ 
extern vsrv_ngroup_handle vsrv_ncenter_query_ngroup(vsrv_ngroup_id gid);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_query_notification
 * DESCRIPTION
 *  query notification by notification id
 * PARAMETERS
 *  notification id     [IN] notification ID assigned by user
 * RETURNS
 *  notification handle
 *****************************************************************************/ 
extern vsrv_notification_handle vsrv_ncenter_query_notification(vsrv_ngroup_handle ghandle, vsrv_notification_id nid);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_ngroup_entry
 * DESCRIPTION
 *  get the first ngroup entry, entry is used to iterate all ngroups
 * PARAMETERS
 *  NONE
 * RETURNS
 *  the first ngroup entry
 *****************************************************************************/ 
extern vsrv_ngroup_entry vsrv_ncenter_get_ngroup_entry();

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_next_ngroup_entry
 * DESCRIPTION
 *  get the next ngroup entry, entry is used to iterate all ngroups
 * PARAMETERS
 *  ngroup entry    [IN] current ngroup entry
 * RETURNS
 *  the next ngroup entry
 *****************************************************************************/ 
extern vsrv_ngroup_entry vsrv_ncenter_get_next_ngroup_entry(vsrv_ngroup_entry gentry);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_notification_entry
 * DESCRIPTION
 *  get the first notification entry, entry is used to iterate all notifications
 * PARAMETERS
 *  notification entry    [IN] current notification entry
 * RETURNS
 *  the first notification entry
 *****************************************************************************/ 
extern vsrv_notification_entry vsrv_ncenter_get_notification_entry(vsrv_ngroup_handle ghandle);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_next_notification_entry
 * DESCRIPTION
 *  get the next notification entry, entry is used to iterate all notification
 * PARAMETERS
 *  notification entry    [IN] current notification entry
 * RETURNS
 *  the next notification entry
 *****************************************************************************/ 
extern vsrv_notification_entry vsrv_ncenter_get_next_notification_entry(vsrv_notification_entry nentry);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_ngroup
 * DESCRIPTION
 *  get ngroup by ngroup entry
 * PARAMETERS
 *  ngroup entry    [IN] current ngroup entry
 * RETURNS
 *  ngroup handle
 *****************************************************************************/
extern vsrv_ngroup_handle vsrv_ncenter_get_ngroup(vsrv_ngroup_entry gentry);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_notification
 * DESCRIPTION
 *  get notification by notification entry
 * PARAMETERS
 *  notification entry    [IN] current notification entry
 * RETURNS
 *  notification handle
 *****************************************************************************/
extern vsrv_notification_handle vsrv_ncenter_get_notification(vsrv_notification_entry nentry);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_prev_notification
 * DESCRIPTION
 *  get previous notification in the same ngroup
 * PARAMETERS
 *  notification handle   [IN] current notification handle
 * RETURNS
 *  previous notification handle or NULL
 *****************************************************************************/
extern vsrv_notification_handle vsrv_ncenter_get_prev_notification(vsrv_notification_handle nhandle);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_next_notification
 * DESCRIPTION
 *  get next notification in the same ngroup
 * PARAMETERS
 *  notification handle   [IN] current notification handle
 * RETURNS
 *  next notification handle or NULL
 *****************************************************************************/
extern vsrv_notification_handle vsrv_ncenter_get_next_notification(vsrv_notification_handle nhandle);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_ngroup_id
 * DESCRIPTION
 *  get ngroup ID by ngroup handle
 * PARAMETERS
 *  ngroup handle    [IN]
 * RETURNS
 *  ngroup id
 *****************************************************************************/
extern vsrv_ngroup_id vsrv_ncenter_get_ngroup_id(vsrv_ngroup_handle ghandle);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_notification_id
 * DESCRIPTION
 *  get notification ID by notification handle
 * PARAMETERS
 *  notification handle    [IN]
 * RETURNS
 *  notification id
 *****************************************************************************/
extern vsrv_notification_id vsrv_ncenter_get_notification_id(vsrv_notification_handle nhandle);


/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_set_ngroup_title_str
 * DESCRIPTION
 *  set ngroup title, works if group type is VSRV_NGROUP_TYPE_SINGLE_TITLE
 * PARAMETERS
 *  ngroup handle  [IN]
 *  group title    [IN]
 * RETURNS
 *  TRUE if title set
 *****************************************************************************/
extern BOOL vsrv_ncenter_set_ngroup_title_str(vsrv_ngroup_handle ghandle, WCHAR* title);


/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_set_ngroup_title_id
 * DESCRIPTION
 *  set ngroup title, works if group type is VSRV_NGROUP_TYPE_SINGLE_TITLE
 * PARAMETERS
 *  ngroup handle       [IN]
 *  group title resid   [IN]
 * RETURNS
 *  TRUE if title set
 *****************************************************************************/
extern BOOL vsrv_ncenter_set_ngroup_title_id(vsrv_ngroup_handle ghandle, S32 resId);




/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_ngroup_title
 * DESCRIPTION
 *  get ngroup title, works if group type is VSRV_NGROUP_TYPE_SINGLE_TITLE
 * PARAMETERS
 *  ngroup handle      [IN]
 *  text buffer        [OUT]
 *  text buffer size   [IN] 
 * RETURNS
 *  TRUE if title got
 *****************************************************************************/
extern BOOL vsrv_ncenter_get_ngroup_title(vsrv_ngroup_handle ghandle, WCHAR* text, U32 bufsize);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_set_notification_icon
 * DESCRIPTION
 *  set notification icon, works if notification type is VSRV_NOTIFICATION_TYPE_EVENT, VSRV_NOTIFICATION_TYPE_ONGOING
 * PARAMETERS
 *  notification handle  [IN]
 *  image icon           [IN]
 * RETURNS
 *  TRUE if icon set
 *****************************************************************************/
extern BOOL vsrv_ncenter_set_notification_icon(vsrv_notification_handle nhandle, mmi_image_src_struct icon);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_notification_icon
 * DESCRIPTION
 *  get notification icon, works if notification type is VSRV_NOTIFICATION_TYPE_EVENT, VSRV_NOTIFICATION_TYPE_ONGOING
 * PARAMETERS
 *  notification handle  [IN]
 *  image icon           [OUT]
 * RETURNS
 *  TRUE if icon got
 *****************************************************************************/
extern BOOL vsrv_ncenter_get_notification_icon(vsrv_notification_handle nhandle, mmi_image_src_struct *icon);


/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_set_notification_maintext_str
 * DESCRIPTION
 *  set notification maintext, works if notification type is VSRV_NOTIFICATION_TYPE_EVENT, VSRV_NOTIFICATION_TYPE_ONGOING
 * PARAMETERS
 *  notification handle  [IN]
 *  main text            [IN]
 * RETURNS
 *  TRUE if maintext set
 *****************************************************************************/
extern BOOL vsrv_ncenter_set_notification_maintext_str(vsrv_notification_handle nhandle, WCHAR* text);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_set_notification_maintext_id
 * DESCRIPTION
 *  set notification maintext, works if notification type is VSRV_NOTIFICATION_TYPE_EVENT, VSRV_NOTIFICATION_TYPE_ONGOING
 * PARAMETERS
 *  notification handle  [IN]
 *  main text resid      [IN]
 * RETURNS
 *  TRUE if maintext set
 *****************************************************************************/
extern BOOL vsrv_ncenter_set_notification_maintext_id(vsrv_notification_handle nhandle, S32 resId);



/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_notification_maintext
 * DESCRIPTION
 *  get notification maintext, works if notification type is VSRV_NOTIFICATION_TYPE_EVENT, VSRV_NOTIFICATION_TYPE_ONGOING
 * PARAMETERS
 *  notification handle  [IN]
 *  text buffer          [OUT]
 *  text buffer size     [IN] 
 * RETURNS
 *  TRUE if maintext got
 *****************************************************************************/
extern BOOL vsrv_ncenter_get_notification_maintext(vsrv_notification_handle nhandle, WCHAR* text, U32 bufsize);


/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_set_notification_subtext_str
 * DESCRIPTION
 *  set notification subtext, works if notification type is VSRV_NOTIFICATION_TYPE_EVENT, VSRV_NOTIFICATION_TYPE_ONGOING
 * PARAMETERS
 *  notification handle  [IN]
 *  subtext            [IN]
 * RETURNS
 *  TRUE if subtext set
 *****************************************************************************/
extern BOOL vsrv_ncenter_set_notification_subtext_str(vsrv_notification_handle nhandle, WCHAR* text);


/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_set_notification_subtext_id
 * DESCRIPTION
 *  set notification subtext, works if notification type is VSRV_NOTIFICATION_TYPE_EVENT, VSRV_NOTIFICATION_TYPE_ONGOING
 * PARAMETERS
 *  notification handle  [IN]
 *  subtext            [IN]
 * RETURNS
 *  TRUE if subtext set
 *****************************************************************************/
extern BOOL vsrv_ncenter_set_notification_subtext_id(vsrv_notification_handle nhandle, S32 resId);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_notification_subtext
 * DESCRIPTION
 *  get notification subtext, works if notification type is VSRV_NOTIFICATION_TYPE_EVENT, VSRV_NOTIFICATION_TYPE_ONGOING
 * PARAMETERS
 *  notification handle  [IN]
 *  text buffer          [OUT]
 *  text buffer size     [IN] 
 * RETURNS
 *  TRUE if subtext got
 *****************************************************************************/
extern BOOL vsrv_ncenter_get_notification_subtext(vsrv_notification_handle nhandle, WCHAR* text, U32 bufsize);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_set_notification_questiontext_str
 * DESCRIPTION
 *  set notification questiontext, works if notification type is VSRV_NOTIFICATION_TYPE_ONGOING
 *  this question text is used to confirm with user that the ongoing APP will be terminated
 * PARAMETERS
 *  notification handle  [IN]
 *  questiontext         [IN]
 * RETURNS
 *  TRUE if questiontext set
 *****************************************************************************/
extern BOOL vsrv_ncenter_set_notification_questiontext_str(vsrv_notification_handle nhandle, WCHAR* text);


/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_set_notification_questiontext_id
 * DESCRIPTION
 *  set notification questiontext, works if notification type is VSRV_NOTIFICATION_TYPE_ONGOING
 *  this question text is used to confirm with user that the ongoing APP will be terminated
 * PARAMETERS
 *  notification handle  [IN]
 *  questiontext id      [IN]
 * RETURNS
 *  TRUE if questiontext set
 *****************************************************************************/
extern BOOL vsrv_ncenter_set_notification_questiontext_id(vsrv_notification_handle nhandle, S32 resId);





/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_notification_questiontext
 * DESCRIPTION
 *  get notification questiontext, works if notification type is VSRV_NOTIFICATION_TYPE_ONGOING
 * PARAMETERS
 *  notification handle  [IN]
 *  text buffer          [OUT]
 *  text buffer size     [IN]
 * RETURNS
 *  TRUE if questiontext got
 *****************************************************************************/
extern BOOL vsrv_ncenter_get_notification_questiontext(vsrv_notification_handle nhandle, WCHAR* text, U32 bufsize);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_set_notification_timestamp
 * DESCRIPTION
 *  set notification timestamp, works for all notification type
 * PARAMETERS
 *  notification handle  [IN]
 *  timestamp         [IN]
 * RETURNS
 *  TRUE if timestamp set
 *****************************************************************************/
extern BOOL vsrv_ncenter_set_notification_timestamp(vsrv_notification_handle nhandle, applib_time_struct *timestamp);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_notification_timestamp
 * DESCRIPTION
 *  get notification timestamp, works for all notification type
 * PARAMETERS
 *  notification handle  [IN]
 *  timestamp            [OUT]
 * RETURNS
 *  TRUE if timestamp got
 *****************************************************************************/
extern BOOL vsrv_ncenter_get_notification_timestamp(vsrv_notification_handle nhandle, applib_time_struct *timestamp);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_set_notification_intent_callback
 * DESCRIPTION
 *  set notification intent callback, the notification sender can process according to the different intent type in this callback,
 *  works for all notification type
 * PARAMETERS
 *  notification handle  [IN]
 *  callback             [IN]
 *  userdata             [IN] ncenter service will copy this userdata
 *  userdataSize         [IN] 
 * RETURNS
 *  TRUE if callback set
 *****************************************************************************/
extern BOOL vsrv_ncenter_set_notification_intent_callback(vsrv_notification_handle nhandle, vsrv_nitent_funcptr callback, void *userdata, U32 userdata_size);


/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_notification_userdata
 * DESCRIPTION
 *  get userdata used in notification intent callback, works for all notification type
 * PARAMETERS
 *  notification handle  [IN]
 * RETURNS
 *  userdata or NULL
 *****************************************************************************/
extern void* vsrv_ncenter_get_notification_userdata(vsrv_notification_handle nhandle);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_notification_userdata_size
 * DESCRIPTION
 *  get userdata size used in notification intent callback, works for all notification type
 * PARAMETERS
 *  notification handle  [IN]
 * RETURNS
 *  userdata size or 0
 *****************************************************************************/
extern U32 vsrv_ncenter_get_notification_userdata_size(vsrv_notification_handle nhandle);


/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_notify_notification
 * DESCRIPTION
 *  notify the notification
 * PARAMETERS
 *  notification handle  [IN]
 * RETURNS
 *  TRUE if notification notified
 *****************************************************************************/
extern BOOL vsrv_ncenter_notify_notification(vsrv_notification_handle nhandle);

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_send_intent
 * DESCRIPTION
 *  viewer send intent to the notification sender
 * PARAMETERS
 *  notification viewer type   [IN] 
 *  notification intent type   [IN]
 *  notification handle        [IN] NULL if viewer wants to send intent to all notification sender
 * RETURNS
 *  TRUE if intent sent
 *****************************************************************************/
extern BOOL vsrv_ncenter_send_intent(vsrv_nviewer_type viewer, vsrv_nintent_type type, vsrv_notification_handle nhandle);    


/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_set_notification_autoclose
 * DESCRIPTION
 *  set auto close in different cases, NCenter will close the notification automatically
 * PARAMETERS
 *  notification handle   [IN]
 *  auto close            [IN] TRUE to enable, FALSE to disable
 *  flag                  [IN] VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TAP, VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_CLEAR,
                               VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_LAUNCH,VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TERMINATE,       
                               VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_REQUEST_LEAVE
 * RETURNS
 *  TRUE if auto close set
 *****************************************************************************/
extern BOOL vsrv_ncenter_set_notification_autoclose(vsrv_notification_handle nhandle, BOOL auto_close, vsrv_notification_flag flag);    

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_notification_autoclose
 * DESCRIPTION
 *  get auto close property in different cases
 * PARAMETERS
 *  notification handle   [IN]
 *  flag                  [IN] VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TAP, VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_CLEAR,
                               VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_LAUNCH,VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TERMINATE,       
                               VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_REQUEST_LEAVE
 * RETURNS
 *  TRUE if auto close enabled
 *****************************************************************************/
extern BOOL vsrv_ncenter_get_notification_autoclose(vsrv_notification_handle nhandle, vsrv_notification_flag flag);    

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_set_notification_autolaunch
 * DESCRIPTION
 *  set auto launch when user tap the notification
 * PARAMETERS
 *  notification handle   [IN]
 *  auto launch           [IN] TRUE(NCenter will leave and APP get LAUNCH intent), FALSE(APP get TAP intent)
 * RETURNS
 *  TRUE if auto launch set
 *****************************************************************************/
extern BOOL vsrv_ncenter_set_notification_autolaunch(vsrv_notification_handle nhandle, BOOL auto_launch);  

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_notification_autolaunch
 * DESCRIPTION
 *  get auto launch property
 * PARAMETERS
 *  notification handle   [IN]
 * RETURNS
 *  TRUE if auto launch enabled
 *****************************************************************************/
extern BOOL vsrv_ncenter_get_notification_autolaunch(vsrv_notification_handle nhandle);    

/*****************************************************************************
 * FUNCTION
 *  vsrv_ncenter_get_notification_is_stable
 * DESCRIPTION
 *  check notificaion whether in a stable stage, stable stage means the notifcaion has been notified,
 *  if there is any property of the notificaion changed, e.g. timestamp, it will be unstable until notified.
 *  that is "vsrv_ncenter_notify_notification(nhandle)" used.
 * PARAMETERS
 *  notification handle   [IN]
 * RETURNS
 *  TRUE if auto launch enabled
 *****************************************************************************/
extern BOOL vsrv_ncenter_get_notification_is_stable(vsrv_notification_handle nhandle);    


#ifdef __cplusplus
}   /* extern "C" */
#endif 



#ifdef __MMI_NCENTER_SUPPORT__


#ifdef __cplusplus

#include "vfx_uc_include.h"
#include "vsrv_notification.h"
#include "vfx_container.h"
#include "vfx_signal.h"


/*
 * Macro to create a notification group without group ID
 *
 * NOTE:
 *      you can't query it back because of lack of ID information
 *
 * EXAMPLE:
 * <code>
 *      VsrvNGroup *group;      
 *      VSRV_NGROUP_CREATE(group, VsrvNGroup);
 * </code>
 */
#define VSRV_NGROUP_CREATE(_ptr, _className)           \
        do                                                                          \
        {                                                                           \
            VsrvNCenter *_nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);                  \
            if (_nm->checkMemory(sizeof(_className)))                               \
            {                                                                      \
                VFX_ALLOC_NEW(_ptr, _className, _nm);                    \
                _ptr->_init(_nm);                                       \
                _nm->_initNGroup(_ptr); \
            }                                                                     \
            else \
            { \
                _ptr = NULL; \
            } \
        } while (0)



/*
 * Macro to create a notification group with group ID
 *
 * NOTE:
 *      you can query it back by group ID
 *
 * EXAMPLE:
 * <code>
 *      VsrvNGroup *group;      
 *      VSRV_NGROUP_CREATE_EX(group, VsrvNGroup, (VAPP_MSG));
 * </code>
 */
#define VSRV_NGROUP_CREATE_EX(_ptr, _className, _param)           \
        do                                                                          \
        {                                                                           \
            VsrvNCenter *_nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);                  \
            VsrvNGroup* _ngroup = _nm->queryNGroup(_param); \
            if (_ngroup == NULL) \
            { \
                if (_nm->_checkMemory(sizeof(_className))) \
                { \
                    VFX_ALLOC_NEW_EX(_ptr, _className, _nm, _param);                    \
                    _ptr->_init(_nm);                                         \
                    _nm->_initNGroup(_ptr); \
                } \
                else \
                { \
                    _ptr = NULL; \
                } \
            } \
            else \
            { \
                _className _tmp; \
                VFX_ASSERT(_tmp.getType() == _ngroup->getType()); \
                _ptr = (_className *) _ngroup; \
            } \
        } while (0)


/*
 * Macro to close a notification group by its instance
 *
 * EXAMPLE:
 * <code> 
 *      VSRV_NGROUP_CLOSE(group);
 * </code>
 */
#define VSRV_NGROUP_CLOSE(_ptr) \
    do \
    { \
        if ((_ptr) != NULL) \
        { \
           VsrvNCenter *_nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);  \
           _nm->_deinitNGroup(_ptr); \
           _ptr = NULL; \
        } \
    } while (0)
    
                            
/*
 * Macro to close a notification group by its id
 *
 * EXAMPLE:
 * <code> 
 *      VSRV_NGROUP_CLOSE_EX(VAPP_MSG);
 * </code>
 */        
#define VSRV_NGROUP_CLOSE_EX(_id) \
    do \
    { \
        VsrvNCenter *_nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);  \
        VsrvNGroup *_ngroup = _nm->queryNGroup(_id); \
        _nm->_deinitNGroup(_ngroup); \
    } while (0)



/*
 * Macro to create a notification without indicating its notification group
 *
 * NOTE:
 *      the service will create a base notification group for it automatically
 *
 * EXAMPLE:
 * <code>
 *      VsrvNotification *noti;      
 *      VSRV_NGROUP_CREATE_EX(noti, VsrvNotification);
 * </code>
 */
#define VSRV_NOTIFICATION_CREATE(_ptr, _className)           \
        do                                                                          \
        {                                                                           \
            VsrvNCenter *_nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);                  \
            if (_nm->_checkMemory(sizeof(_className)))                               \
            {                                                                      \
                VFX_ALLOC_NEW(_ptr, _className, _nm);                    \
                (_ptr)->_init(_nm);                                                  \
                _nm->_initNotification(_ptr); \
            }                                                                     \
            else \
            { \
                _ptr = NULL; \
            } \
        } while (0)



/*
 * Macro to create a notification belong to the specified notification group
 *
 * NOTE:
 *      there are two way to decide the notification group
 *      1. ((VsrvNGroup*) group, Noti_ID)
 *      2. ((VsrvNGroupId) groupId, Noti_ID) // if there is no group with the groupId, the service will create a base notification group automatically
 *      the Noti_ID is uniquily defined within a group
 *
 * EXAMPLE:
 * <code>
 *      VsrvNotification *noti;      
 *      VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotification, ((VsrvNGroup*) group, Noti_ID));
 *      or
 *      VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotification, ((VsrvNGroupId) VAPP_MSG, Noti_ID));
 * </code>
 */
#define VSRV_NOTIFICATION_CREATE_EX(_ptr, _className, _param)           \
        do                                                                          \
        {                                                                           \
            VsrvNCenter *_nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);                  \
            VsrvNotification *_noti = _nm->queryNotification##_param;    \
            if (_noti == NULL) \
            { \
                if (_nm->_checkMemory(sizeof(_className))) \
                { \
                    VFX_ALLOC_NEW_EX(_ptr, _className, _nm, _param);                    \
                    (_ptr)->_init(_nm);                                                  \
                    _nm->_initNotification(_ptr); \
                } \
                else \
                { \
                    _ptr = NULL; \
                } \
            } \
            else \
            { \
                _className _tmp; \
                VFX_ASSERT(_tmp.getType() == _noti->getType()); \
                _ptr = (_className *) _noti; \
            } \
        } while (0)


/*
 * Macro to close a notification by its instance
 *
 * EXAMPLE:
 * <code> 
 *      VSRV_NOTIFICATION_CLOSE(noti);
 * </code>
 */ 
#define VSRV_NOTIFICATION_CLOSE(_ptr) \
    do \
    { \
        if ((_ptr) != NULL) \
        { \
           VsrvNCenter *_nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);  \
           _nm->_deinitNotification(_ptr); \
           _ptr = NULL; \
        } \
    } while (0)
    
                    
        
/*
 * Macro to close a notification by its group and notification id
 *
 * EXAMPLE:
 * <code> 
 *      VSRV_NOTIFICATION_CLOSE_EX(group, NOTI_ID);
 * </code>
 */         
#define VSRV_NOTIFICATION_CLOSE_EX(_groupHandle, _id) \
    do \
    { \
        VsrvNCenter *_nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);  \
        VsrvNotification *_noti = _nm->queryNotification(_groupHandle, _id); \
        _nm->_deinitNotification(_noti); \
    } while (0)



/***************************************************************************** 
 * Class VsrvNCenter 
 *****************************************************************************/
/*
 * VsrvNCenter is a singleton class which manages all notification
 *
 * EXAMPLE:
 * <code>
 *   VsrvNCenter *ncenterService = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
 * </code>
 */
class VsrvNCenter : public VfxObject
{
    VFX_DECLARE_CLASS(VsrvNCenter);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VsrvNCenter);

// Constructor / Destructor
public:

    // <group DOM_NCenter_VsrvNCenter_Constructor/Destructor>    
    // Constructor
    VsrvNCenter();   
    // <group DOM_NCenter_VsrvNCenter_Constructor/Destructor>    
    // Destructor
    virtual ~VsrvNCenter(){};   

private:

// Method
public:

/* DOM-NOT_FOR_SDK-BEGIN */

    //internal used      
    void _initNotification(VsrvNotification* noti); 
    void _deinitNotification(VsrvNotification* noti);
    void _initNGroup(VsrvNGroup* ngroup); 
    void _deinitNGroup(VsrvNGroup* ngroup);
	VfxBool _checkMemory(VfxS32 size);

    //debug
    void debugDump();

/* DOM-NOT_FOR_SDK-END */

    // <group DOM_NCenter_VsrvNCenter_Method>
    // Query back your notification using group and notification id
    // RETURNS: NULL if not existing
    VsrvNotification* queryNotification(VsrvNGroup *group, VsrvNotificationId id);    

    // <group DOM_NCenter_VsrvNCenter_Method>
    // Query back your notification using group id and notification id
    // RETURNS: NULL if not existing
	VsrvNotification* queryNotification(VsrvNGroupId gid, VsrvNotificationId nid);

    // <group DOM_NCenter_VsrvNCenter_Method>
    // Get the head of list of all notificaion groups
    // RETURNS: Iterator of notificaion groups
    const VfxList <VsrvNGroup*>::It getNGroups() { return m_groups.begin(); };
    

    // <group DOM_NCenter_VsrvNCenter_Method>
    // Check the notificaion is valid or not
    // RETURNS: VFX_TRUE if the notificaion is valid
  	VfxBool checkNotification(VsrvNotification *noti);


    // <group DOM_NCenter_VsrvNCenter_Method>
    // Query back your notification group using group id
    // RETURNS: NULL if not existing
    VsrvNGroup* queryNGroup(VsrvNGroupId id);           



    // <group DOM_NCenter_VsrvNCenter_Method>
    // send intent to all notifications or the specified notification
    void sendIntent(VsrvNViewerType observer, VsrvNIntentType type, VsrvNotification* noti = NULL, void* intentData = NULL);    


    // <group DOM_NCenter_VsrvNCenter_Method>
    // send intent to the kind of notifications specified by the notification type
    void sendIntent(VsrvNViewerType observer, VsrvNIntentType type, VsrvNotificationType ntype, void* intentData = NULL);    
    


/* DOM-NOT_FOR_SDK-BEGIN */

// Overridable
public:
    // IVfxAllocatable interfaces
    virtual vrt_allocator_handle getAllocator();


// Override
protected:
    virtual void onInit();

/* DOM-NOT_FOR_SDK-END */

// Signal
public:
    // <group DOM_NCenter_VsrvNCenter_Event>
    // notification activity signal. This signal is invoked when notofication created, closed, updated
    VfxSignal2 <VsrvNotification*, VsrvNStatusType> m_signalNStatus;

    
// Implementation
private:
    VfxBool broadcast(VsrvNotification* noti, VfxBool oldIsStable);

    

//variable
private:
    VfxContext *m_context;

  
//    VfxList <VsrvNotification*> m_pool;
    
    VfxList <VsrvNGroup*> m_groups;


    

    friend class VsrvNotification;
    friend class VsrvNGroup;    
};

#endif /* __cplusplus */


#endif /* __VSRV_NCENTER_H__ */
#endif /* __MMI_NCENTER_SUPPORT__ */

