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
 * NotificationSettingSrvGprot.h
 *
 * Project:
 * --------
 * MAUI   
 *
 * Description:
 * ------------
 * NSS (Notification setting service) for storing and managing app's push or pool 
 * notification setting
 * Currently the setting includes sound, lock scrn, badge, ncenter, alert(popup, status bar)
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMIDataType.h"
#include "MMI_features.h" 

#ifndef __NOTIFICATION_SETTING_GPROT_SRV_H__
#define __NOTIFICATION_SETTING_GPROT_SRV_H__


/*Setting service used key-value pair to retrieve setting's configuration*/

/* KEYs */

//
// The order of setting value must be the same as mask value
//
typedef enum
{ 
    NSS_SETTING_BADGE_ICON = 0,
    NSS_SETTING_SOUND,
    NSS_SETTING_LOCK_SCRN,
    NSS_SETTING_NCENTER,    
    NSS_SETTING_ALERT, /*Can be None, Popup, Status bar*/
    NSS_SETTING_MAX 
} nss_setting_key_enum;

/*MASKs*/
#define NSS_MASK_BADGE_ICON 0x1
#define NSS_MASK_SOUND 0x2 
#define NSS_MASK_LOCK_SCRN 0x4
#define NSS_MASK_NCENTER 0x8
#define NSS_MASK_ALERT 0x10 

/*VALUEs*/
#define SETTING_ON (1)
#define SETTING_OFF (0)

#define ALERT_TYPE_NONE (0)
#define ALERT_TYPE_POPUP (1)
#define ALERT_TYPE_STATUS_BAR (2)

#define SETTING_BADGE_DEFAULT SETTING_ON
#define SETTING_SOUND_DEFAULT SETTING_ON
#define SETTING_LOCK_SCRN_DEFAULT SETTING_ON
#define SETTING_NCENTER_DEFAULT SETTING_ON

/*APP TYPE*/
#define DOWNLOAD_APP_TYPE (1)
#define NATIVE_APP_TYPE (0)

#ifdef __MMI_NSS_SUPPORT__
/*EVENTs NSS event type*/
typedef enum
{
    EVT_ID_SRV_NSS_BEGIN = SRV_NSS_BASE,   
    EVT_ID_SRV_NSS_SETTING_MODIFIED,
    EVT_ID_SRV_NSS_END_OF_ENUM
} srv_nss_event_enum;

/*MACROs*/
#ifdef __PLUTO_MMI_PACKAGE__              
    #ifdef __MMI_FTE_SUPPORT__
        #ifdef __MMI_VUI_LAUNCHER_KEY__
            #ifdef __MMI_NCENTER_SUPPORT__
                #define ALERT_TYPE_DEFAULT ALERT_TYPE_STATUS_BAR
                #define NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND (NSS_MASK_BADGE_ICON|\
                    NSS_MASK_LOCK_SCRN|\
                    NSS_MASK_NCENTER)
                #define NSS_MASK_DEFAULT (NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND|\
                    NSS_MASK_SOUND|\
                    NSS_MASK_ALERT)
            #else            
                #define ALERT_TYPE_DEFAULT ALERT_TYPE_STATUS_BAR
                #define NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND (NSS_MASK_BADGE_ICON)
                #define NSS_MASK_DEFAULT (NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND|\
                    NSS_MASK_SOUND|\
                    NSS_MASK_ALERT)
            #endif/*__MMI_NCENTER_SUPPORT__*/
        #else
            #ifdef __MMI_NCENTER_SUPPORT__
                #define ALERT_TYPE_DEFAULT ALERT_TYPE_STATUS_BAR
                #define NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND (NSS_MASK_BADGE_ICON|\
                    NSS_MASK_NCENTER)
                #define NSS_MASK_DEFAULT (NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND|\
                    NSS_MASK_SOUND|\
                    NSS_MASK_ALERT)
            #else                
                #define ALERT_TYPE_DEFAULT ALERT_TYPE_STATUS_BAR
                #define NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND (NSS_MASK_BADGE_ICON)                   
                #define NSS_MASK_DEFAULT (NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND|\
                    NSS_MASK_SOUND|\
                    NSS_MASK_ALERT)
            #endif/*__MMI_NCENTER_SUPPORT__*/
        #endif/*__MMI_VUI_LAUNCHER_KEY__*/
    #else
        #ifdef __MMI_APP_MANAGER_SUPPORT__
            #define ALERT_TYPE_DEFAULT ALERT_TYPE_POPUP

            #define NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND (NSS_MASK_BADGE_ICON)
            #define NSS_MASK_DEFAULT (NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND|\
                NSS_MASK_SOUND|\
                NSS_MASK_ALERT)
        #else
            #define ALERT_TYPE_DEFAULT ALERT_TYPE_POPUP

            #define NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND (0)
            #define NSS_MASK_DEFAULT (NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND|\
                NSS_MASK_SOUND|\
                NSS_MASK_ALERT)
        #endif/*__MMI_APP_MANAGER_SUPPORT__*/
    #endif /*__MMI_FTE_SUPPORT__*/
#else 
#define ALERT_TYPE_DEFAULT ALERT_TYPE_STATUS_BAR
#define NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND (NSS_MASK_BADGE_ICON|\
                NSS_MASK_LOCK_SCRN|\
                NSS_MASK_NCENTER)
#define NSS_MASK_DEFAULT (NSS_MASK_BADGE_ICON|\
                NSS_MASK_SOUND|\
                NSS_MASK_LOCK_SCRN|\
                NSS_MASK_NCENTER|\
                NSS_MASK_ALERT)               
#endif /*__PLUTO_MMI_PACKAGE__*/

#define NSS_FILL_SETTING_VALUE(BADGE_SETTING, SOUND_SETTING, LOCK_SCRN_SETTING, NCENTER_SETTING, ALERT_SETTING) (\
             (BADGE_SETTING<< NSS_SETTING_BADGE_ICON) |\
             ((SOUND_SETTING)<<NSS_SETTING_SOUND)|\
             ((LOCK_SCRN_SETTING)<<NSS_SETTING_LOCK_SCRN)|\
             ((NCENTER_SETTING)<<NSS_SETTING_NCENTER)|\
             ((ALERT_SETTING)<<NSS_SETTING_ALERT)) 
#define NSS_SETTING_DEFAULT (NSS_FILL_SETTING_VALUE( SETTING_BADGE_DEFAULT,\
              SETTING_SOUND_DEFAULT, \
              SETTING_NCENTER_DEFAULT, \
              SETTING_LOCK_SCRN_DEFAULT, \
              ALERT_TYPE_DEFAULT))   

//Help to transfer KEY to MASK
#define KEY_TO_MASK(_key) (1<<_key)

//Return zero if the setting is not configurable, return non-zero if setting is configurable
#define NSS_IS_SETTING_CONFIGURABLE(notification_mask, check_mask) (notification_mask & check_mask)

// 
// Retrieve setting value by interpreting macro
// Return SETTING_ON or SETTING_OFF when the key is sound, lock scrn, badge, ncenter
// Return ALERT_TYPE_NONE or ALERT_TYPE_POPUP or ALERT_TYPE_STATUS_BAR when the key is alert
//
#define NSS_EXTRACT_SETTING_VALUE(_notification_setting, _key, _value) do{\
    _value = SETTING_OFF;\
    if(_notification_setting & KEY_TO_MASK(_key))\
    {\
            _value = SETTING_ON;\
    }\
    if(_key == NSS_SETTING_ALERT)\
    {\
        if(_notification_setting & (NSS_MASK_ALERT<<1))\
        {\
            _value = ALERT_TYPE_STATUS_BAR;\
        }\
    }\
}while(0)

//
// Modify setting value by interpreting macro
// Set SETTING_ON or SETTING_OFF when the key is sound, lock scrn, badge, ncenter
// Set ALERT_TYPE_NONE or ALERT_TYPE_POPUP or ALERT_TYPE_STATUS_BAR when the key is alert
// Support boundary in this macro
//
#define NSS_MODIFY_SETTING_VALUE(_notification_setting, _key, _value) do{\
   if(_key <= NSS_SETTING_ALERT)\
   {\
       if(_value == SETTING_OFF)\
        {\
            _notification_setting  &=~(KEY_TO_MASK(_key));\
            if(_key == NSS_SETTING_ALERT)\
            {\
                _notification_setting &=~(NSS_MASK_ALERT<<1);\
            }\
        }\
       else\
       {\
           if(_value == SETTING_ON)\
            {\
                _notification_setting  |= KEY_TO_MASK(_key);\
            }\
           if(_key == NSS_SETTING_ALERT)\
           {\
               if(_value == ALERT_TYPE_STATUS_BAR)\
               {\
                   _notification_setting &=~NSS_MASK_ALERT;\
                   _notification_setting |=(NSS_MASK_ALERT<<1);\
               }\
               if(_value == ALERT_TYPE_POPUP)\
               {\
                   _notification_setting &=~(NSS_MASK_ALERT<<1);\
               }\
           }\
       }\
   }\
}while(0)

//
// event structure for nss callback function usage
//
typedef struct {
           MMI_EVT_PARAM_HEADER
           MMI_ID app_id;
           U32 notification_setting;
           U32 notification_mask;
} mmi_srv_nss_event_struct;

typedef struct {
    U16 app_str_id;
    U16 app_image_id;
} native_res_struct;

typedef struct {
    mmi_app_package_char *app_mre_package_name;   
} mre_res_struct;

typedef union
{
    native_res_struct native_res;
    mre_res_struct mre_res;
} mmi_srv_nss_app_res_union;

typedef struct 
{
    /*application identity*/
    MMI_ID app_id; 
    /*identifying the registered app type (native(1) or mre(0))*/   
    U16 app_type;     
    /*record app's notification setting*/
    U32 notification_setting;
    /*record app's notification mask, the value is set 
     *if this setting is configurable*/
    U32 notification_mask;
    /*used for retrieve the app's ALERT name and image icon*/ 
    mmi_srv_nss_app_res_union app_info;
    /*An array of alias app id, this array must be ended by 0xffff and 0x0.
     * when user try to query NSS setting by the alias id, we will give them 
     * the same app's setting*/
    MMI_ID *alias_app_id;
} mmi_srv_nss_node;

typedef void (*mmi_listener_proc_func) (MMI_ID app_id, U32 changed_setting, MMI_ID *alias_id);

typedef struct 
{
    U32 interest_notification_mask;
    mmi_listener_proc_func cb_proc;
} mmi_srv_nss_listener_list;


/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_register
 * DESCRIPTION
 *  if the installed app can receive push or poll notification, it should be registered to notification 
 *  setting service for user to modify its setting. And currently NSS only helps to save notification 
 *  setting of native app, if you are MRE or JAVA (anyway, not native app) then you need to register
 *  the callback function for receiving the notification change and save the content by yourself
 *
 * PARAMETERS
 *  nss_node     : [IN] register information
 * RETURN VALUES
 *  handle
 *  if register success, the function will return handle (the value is same as app_id)
 *  if register fail, the function will return NULL
 *****************************************************************************/
MMI_ID mmi_srv_nss_register(mmi_srv_nss_node *nss_node);

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_unregister
 * DESCRIPTION
 *  Unregister nss function should be called when app (within notification ability) is uninstalled
 *  Noted. In the current version, native app cannot be uninstalled
 *
 * PARAMETERS
 *  app_id     : [IN] application identity
 * RETURN VALUES
 *  MMI_RET_OK : unregister successfully 
 *  MMI_RET_FAIL : unregister fail
 *****************************************************************************/
mmi_ret mmi_srv_nss_unregister(MMI_ID app_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_get_setting
 * DESCRIPTION
 *  get the specific setting(KEY) of the specific app
 * PARAMETERS
 *  app_id     : [IN] application identity
 *  key     : [IN] the specific setting (Ex. sound, lock scrn..,etc)
 *  value     : [OUT] the value of the specific setting
 * RETURN VALUES
 *  MMI_RET_OK : get setting successfully 
 *  MMI_RET_FAIL : get setting fail
 * NOTED
 *  For general service (Ex. NMGR, Ncenter platform service, App mgr service), don't care RETURN VALUE
 *  just need to use the "value" to check the key's configuration
 *  For notification app, use the the RETURN VALUE to check if the setting can be configurable or not
 *****************************************************************************/
mmi_ret mmi_srv_nss_get_setting (MMI_ID app_id, nss_setting_key_enum key, U16 *value);

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_set_setting
 * DESCRIPTION
 *  set the specific setting(KEY) of the specific app
 * PARAMETERS
 *  app_id     : [IN] application identity
 *  key     : [IN] the specific setting (Ex. sound, lock scrn..,etc)
 *  value     : [IN] the value of the specific setting
 * RETURN VALUES
 *  MMI_RET_OK : set setting successfully 
 *  MMI_RET_FAIL : set setting fail
 *****************************************************************************/
mmi_ret mmi_srv_nss_set_setting(MMI_ID app_id, nss_setting_key_enum key, U16 value);

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_get_app_setting
 * DESCRIPTION
 *  get all settings of the specific app
 * PARAMETERS
 *  app_id     : [IN] application identity
 *  notification_setting : [OUT] notification setting of specific app
 *  notification_mask   : [OUT] notification mask of specific app
 * RETURN VALUES
 *  MMI_RET_OK : get setting successfully 
 *  MMI_RET_FAIL : get setting fail
 * NOTED
 *  NSS provide macro to help app to retrieve the specific setting's value
 *****************************************************************************/
mmi_ret mmi_srv_nss_get_app_setting(MMI_ID app_id, U32 *notification_setting, U32 *notification_mask);

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_set_app_setting
 * DESCRIPTION
 *  set all settings of the specific app
 * PARAMETERS
 *  app_id     : [IN] application identity
 *  notification_setting : [IN] notification setting of specific app
 * RETURN VALUES
 *  MMI_RET_OK : get setting successfully 
 *  MMI_RET_FAIL : get setting fail
 * NOTED
 *  NSS provide macro to help app to modify the specific setting's value
 *****************************************************************************/
mmi_ret mmi_srv_nss_set_app_setting(MMI_ID app_id, U32 notification_setting);

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_get_first_node
 * DESCRIPTION
 *  get the first node of nss node list (for showing app list to user)
 * PARAMETERS
 *  nss_node     : [OUT] you can use the structure to retrieve 1. app_id, 2. ALERT name, 3. image icon
 * RETURN VALUES
 *  void. if there is no node, the app_id would be zero
 *****************************************************************************/
void mmi_srv_nss_get_first_node(mmi_srv_nss_node *nss_node) ;

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_get_next_node
 * DESCRIPTION
 *  get the next node of nss node list (for showing app list to user)
 * PARAMETERS
 *  nss_node     : [OUT] you can use the structure to retrieve 1. app_id, 2. ALERT name, 3. image icon
 * RETURN VALUES
 *  void. if there is no node, the app_id would be zero
 *****************************************************************************/
void mmi_srv_nss_get_next_node(mmi_srv_nss_node *nss_node);

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_get_node_by_index
 * DESCRIPTION
 *  get the node by its index (for showing app list to user, and the index is start from zero)
 * PARAMETERS
 *  index     : [IN] the node you want to get
 *  nss_node     : [OUT] you can use the structure to retrieve 1. app_id, 2. ALERT name, 3. image icon
 * RETURN VALUES
 *  void. if there is no such index, the app_id of the nss_node would be zero
 *****************************************************************************/
void mmi_srv_nss_get_node_by_index (U32 index , mmi_srv_nss_node *nss_node); 

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_get_node_num
 * DESCRIPTION
 *  get the total number of nodes
 * PARAMETERS
 * RETURN VALUES
 *  the total number of nodes
 *****************************************************************************/
U32 mmi_srv_nss_get_node_num(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_register_listener
 * DESCRIPTION
 *  app or other service can register this function to listen the setting change
 *  you can unregister by insert the NULL mask value
 * PARAMETERS
 * RETURN VALUES
 *  true when register or unregister success
 *****************************************************************************/
MMI_BOOL mmi_srv_nss_register_listener(U32 interest_notification_mask, mmi_listener_proc_func cb_proc);



#endif /* __NOTIFICATION_SETTING_GPROT_SRV_H__ */ 
#endif /*__MMI_NSS_SUPPORT__*/
