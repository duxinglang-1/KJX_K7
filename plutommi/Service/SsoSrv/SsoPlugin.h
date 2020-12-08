#ifndef __SSO_PLUGIN_H__
#define __SSO_PLUGIN_H__

#include "vmsys.h"

#define SSO_PLUGIN_NAME_SIZE                            64
#define SSO_PLUGIN_URL_SIZE                             256
#define SSO_PLUGIN_ACCESS_TOKEN                         256
#define SSO_PLUGIN_REFRESH_TOKEN                        256
#define SSO_PLUGIN_SCOPE                                128
#define SSO_PLUGIN_EXTENSION                            256

#define SSO_PLUGIN_EXT_YAHOO_COOKIE                     300
#define SSO_PLUGIN_EXT_YAHOO_CRUMB                      256

typedef enum
{
    SSO_PLUGIN_OK,
    SSO_PLUGIN_UNKNOWN_ERROR   = -9999,
    SSO_PLUGIN_CONNECTION_FAIL,
    SSO_PLUGIN_INCORRECT_ID_PW,
    SSO_PLUGIN_NOT_FULL_EMAIL,
} sso_plugin_result;

typedef enum {
    SSO_PLUGIN_ICON_45,
    SSO_PLUGIN_ICON_32,
    SSO_PLUGIN_ICON_24,
    SSO_PLUGIN_ICON_20,
    SSO_PLUGIN_ICON_TOTAL,
} sso_plugin_icon_enum;


typedef struct sso_plugin_provider
{
    VMUINT32 id;
    void *icon_data[SSO_PLUGIN_ICON_TOTAL];
    VMUINT32 icon_size[SSO_PLUGIN_ICON_TOTAL];
    VMWCHAR name[SSO_PLUGIN_NAME_SIZE];
    VMWCHAR signup_url[SSO_PLUGIN_URL_SIZE];
} sso_plugin_provider_struct;

typedef enum
{
   SSO_PLUGIN_CREDENTIAL_OAUTH,
   SSO_PLUGIN_CREDENTIAL_USERPASS,
   SSO_PLUGIN_CREDENTIAL_YAHOO,
} sso_plugin_credential_enum;

typedef struct sso_plugin_credential
{
    sso_plugin_credential_enum type;
    union 
    {
       struct 
       {
          VMCHAR access_token[SSO_PLUGIN_ACCESS_TOKEN];
          VMCHAR refresh_token[SSO_PLUGIN_REFRESH_TOKEN];
          VMCHAR scope[SSO_PLUGIN_SCOPE];
          VMCHAR extension[SSO_PLUGIN_EXTENSION];
       } oauth;
       struct 
       {
          VMCHAR username[SSO_PLUGIN_NAME_SIZE];
          VMCHAR password[SSO_PLUGIN_NAME_SIZE];
       } userpass;
       struct 
       {
          VMCHAR security_token[SSO_PLUGIN_ACCESS_TOKEN];
          VMCHAR ycookie[SSO_PLUGIN_EXT_YAHOO_COOKIE];
          VMCHAR tcookie[SSO_PLUGIN_EXT_YAHOO_COOKIE];
          VMCHAR crumb[SSO_PLUGIN_EXT_YAHOO_CRUMB];
       } yahoo;
    } value;
} sso_plugin_credential_struct;

typedef struct sso_plugin_account
{
    VMWCHAR *username;
    sso_plugin_credential_struct *credential;
} sso_plugin_account_struct;

typedef void (*sso_plugin_account_cb)(VMUINT32 req_id, sso_plugin_result result, sso_plugin_account_struct *account);
typedef void (*sso_plugin_result_cb)(VMUINT32 req_id, sso_plugin_result result);

/**
 * @see sso_plugin_manifest
 */
typedef void (*sso_plugin_manifest_func)(sso_plugin_provider_struct *);

/**
 * called during bootup for sso plugin discovery
 * @param [out] buffer plugin has to fill this buffer with correct data to identify itself
 */
void sso_plugin_manifest(sso_plugin_provider_struct *buffer);

/**
 * @see sso_plugin_login
 */
typedef void (*sso_plugin_login_func)(VMUINT32, VMWSTR, VMWSTR, sso_plugin_account_cb);

/**
 * show a screen for user to login
 * @param [in] req_id identifer provided by caller and must be kept by plugin so that caller can cancel the login process
 * @param [in] username username of the account
 * @param [in] password password of the account
 * @param [in] callback will be called when log-in is done, no matter success or failure
 */
void sso_plugin_login(VMUINT32 req_id, VMWSTR username, VMWSTR password, sso_plugin_account_cb callback);
    
/**
 * @see sso_plugin_logout
 */
typedef void (*sso_plugin_logout_func)(VMUINT32, VMWSTR, sso_plugin_credential_struct *, sso_plugin_result_cb);

/**
 * depending on the service provider, might need to do server-side logout
 * @param [in] req_id identifer provided by caller and must be kept by plugin so that caller can cancel the login process
 * @param [in] username username of the account
 * @param [in] credential credential of the account
 * @param [in] callback will be called when log-out is done, no matter success or failure
 */
void sso_plugin_logout(VMUINT32 req_id, VMWSTR username, sso_plugin_credential_struct *credential, sso_plugin_result_cb callback);
    
/**
 * @see sso_plugin_refresh
 */
typedef void (*sso_plugin_refresh_func)(VMUINT32, VMWSTR, sso_plugin_credential_struct *, sso_plugin_result_cb);

/**
 * refresh access token by using refresh token or extension
 * if fails to refresh, prompt user to enter password again to get a new access token
 * @param [in] req_id identifer provided by caller and must be kept by plugin so that caller can cancel the login process
 * @param [in] username in case of refresh failure, show this read-only username and ask user to enter password again
 * @param [in,out] credential tokens maybe updated to new ones or just re-validate on server side
 * @param [in] callback will be called when log-out is done, no matter success or failure
 */
void sso_plugin_refresh(VMUINT32 req_id, VMWSTR username, sso_plugin_credential_struct *credential, sso_plugin_result_cb callback);
    
/**
 * @see sso_plugin_cancel
 */
typedef void (*sso_plugin_cancel_func)(VMUINT32);

/**
 * cancel the running process identified by req_id
 * @param [in] req_id identifer passed along async requests
 */
void sso_plugin_cancel(VMUINT32 req_id);

static S32 sso_check_ready(void);


#endif
