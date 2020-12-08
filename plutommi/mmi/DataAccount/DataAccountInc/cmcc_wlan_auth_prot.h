#ifndef __CMCC_WLAN_AUTH_PROT_H__
#define __CMCC_WLAN_AUTH_PROT_H__

#ifdef __MMI_OP01_WIFI__

#include "MMIDataType.h"
#include "cmcc_wlan_auth_gprot.h"

/* get saved username, will return empty string if not saved yet */
extern const CHAR *cmcc_wlan_auth_setting_get_user(void); 

/* get saved password, will return empty string if not saved yet*/
extern const CHAR *cmcc_wlan_auth_setting_get_pass(void); 

extern U8 cmcc_wlan_http_get_abm_id(void);

extern U32 cmcc_wlan_http_get_dtcnt_id(void);

extern
cmcc_wlan_auth_ret_enum
cmcc_wlan_http_login(cmcc_wlan_auth_callback cb);

/* logout */
extern 
cmcc_wlan_auth_ret_enum
cmcc_wlan_http_logout(cmcc_wlan_auth_callback cb); 

/* abort current pending LOGIN / LOGOUT action. 
 Do nothing if there is no pending operation */
extern void cmcc_wlan_http_abort(void); 

#endif /* __CMCC_WLAN_AUTH_PROT_H__ */

#endif /* __MMI_OP01_WIFI__ */

