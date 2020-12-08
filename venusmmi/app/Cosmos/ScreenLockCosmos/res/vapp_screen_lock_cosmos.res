#include "mmi_features.h"
#include "vapp_screen_lock_app_def.h"
#include "custresdef.h"

#if defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_SCREEN_LOCK_COSMOS" name="STR_ID_VAPP_SCREEN_LOCK_COSMOS" type="venus">
    <MEMORY base="0" />

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   
    #define ROOT_PATH RES_IMG_ROOT"\\\\ScreenLock\\\\ScreenLockCosmos\\\\"
    #define COMMON_IMG_PATH RES_THEME_ROOT"\\\\Default\\\\Common\\\\"
    #define ROOT_PATH_3D RES_IMG_ROOT"\\\\3D\\\\ScrLock\\\\Texture\\\\"

// 2D resource
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_COSMOS_SETTING_NAME"/> 

    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_COSMOS_SETTING_SNAPSHOT">ROOT_PATH"screenshot.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_COSMOS_SETTING_ICON">ROOT_PATH"icon.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_UNCLICKED_CARD1">ROOT_PATH"Card_L_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_UNCLICKED_CARD2">ROOT_PATH"Card_C_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_UNCLICKED_CARD3">ROOT_PATH"Card_R_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_CLICKED_CARD">ROOT_PATH"Card_onPress.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_ARROW">ROOT_PATH"whiteArrow.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_TIME_BG">ROOT_PATH"time_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_CARD_ICON_ENVELOP">ROOT_PATH"icon_envelop.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_CARD_ICON_UNLOCK">ROOT_PATH"icon_lock.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_CARD_ICON_PHONE">ROOT_PATH"icon_phone.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_CARD_ICON_CAMCODER">ROOT_PATH"icon_camera.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_CARD_ICON_DOT">COMMON_IMG_PATH"Point_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_CARD_ICON_ARROW">ROOT_PATH"arrow_mini.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_STATUS_ICON_BAR">ROOT_PATH"StatusBar_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_NOTIFICATION_BG">ROOT_PATH"Notification_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_NOTIFICATION_LINE">ROOT_PATH"Notification_Lines.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_TIME_BG_NO_SHADOW">ROOT_PATH"time_bg2.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_DEFAULT_EVENT_ICON">ROOT_PATH"event_icon_info.png"</IMAGE>    

    <!-----------------------------------------------------Other Resource Area------------------------------------------------------>   
    /*
     * This event is emitted before launch screen lock
     *
     * Screen lock will not be launched if register callback return MMI_RET_ERR
     * else return MMI_RET_OK
     *
     * Structure: vapp_screen_lock_pre_lock_evt_struct
     */

    <RECEIVER id="EVT_ID_VAPP_SCREEN_LOCK_SYS_INIT" proc="VappScreenLockLiberatePublisher"/>
</APP>
#endif /*__MMI_VUI_SCREEN_LOCK_COSMOS__ */