#ifndef _CMCC_WLAN_AUTH_GPROT_H_
#define _CMCC_WLAN_AUTH_GPROT_H_

#ifdef __MMI_OP01_WIFI__

#include "MMIDataType.h"

typedef enum
{
    CMCC_WLAN_AUTH_OK = 0, /* Login successfully */

    CMCC_WLAN_AUTH_NO_NEED_LOGIN, /* Server response OK directly, could take it as CMCC_WLAN_AUTH_OK */

    CMCC_WLAN_AUTH_WBLOCK, /* Would block, callback will be called later */

    CMCC_WLAN_AUTH_PARA_ERROR, /* Parameter error */

    CMCC_WLAN_AUTH_ABORTED,/* Action aborted by user */

    CMCC_WLAN_AUTH_NO_ACCOUNT, /* User press NO in the setting screen */

    CMCC_WLAN_AUTH_BUSY, /* Previous login / logout activity not finished */

    CMCC_WLAN_AUTH_WPS_ERROR, /* HTTP layer error  */

    CMCC_WLAN_AUTH_BEARER_ERROR, /* WiFi AP is unreachable */

    CMCC_WLAN_AUTH_LOGIN_FAIL /* CMCC server response fail, maybe wrong user name or password */

}cmcc_wlan_auth_ret_enum;

/* callback for login / logout result */
typedef void(*cmcc_wlan_auth_callback)(cmcc_wlan_auth_ret_enum ret);

/* Show setting screen */
extern mmi_id cmcc_wlan_auth_setting_show(mmi_id parent_id);

/* login */
// Have UI
extern 
cmcc_wlan_auth_ret_enum
cmcc_wlan_auth_login(cmcc_wlan_auth_callback cb);

/* logout */
// No UI
extern 
cmcc_wlan_auth_ret_enum
cmcc_wlan_auth_logout(cmcc_wlan_auth_callback cb); 

/* abort current pending LOGIN / LOGOUT action. 
 Do nothing if there is no pending operation */
extern void cmcc_wlan_auth_abort(void); 

#endif /* _CMCC_WLAN_AUTH_GPROT_H_ */

#endif /* __MMI_OP01_WIFI__ */

