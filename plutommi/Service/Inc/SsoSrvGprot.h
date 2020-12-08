#ifndef __SSO_SRV_GPROT_H__
#define __SSO_SRV_GPROT_H__

#include "MMIDataType.h"

#define PROVIDER_YAHOO                               0x00701100

#define SRV_SSO_PROVIDER_MAX                         1
#define SRV_SSO_ACCOUNTS_PER_PROVIDER                1
#define SRV_SSO_INVALID_ACC_ID                       0xFF

#define SRV_SSO_NAME_SIZE                            64
#define SRV_SSO_URL_SIZE                             256
#define SRV_SSO_ACCESS_TOKEN                         256
#define SRV_SSO_REFRESH_TOKEN                        256
#define SRV_SSO_SCOPE                                128
#define SRV_SSO_EXTENSION                            256

#define SRV_SSO_EXT_YAHOO_COOKIE                     300
#define SRV_SSO_EXT_YAHOO_CRUMB                      256

typedef enum
{
    SRV_SSO_OK,
    SRV_SSO_UNKNOWN_ERROR      = -999,
    SRV_SSO_CARD_PLUG_OUT,
    SRV_SSO_USB_MS_MODE,
    SRV_SSO_PROVIDER_NOT_FOUND,
    SRV_SSO_ACCOUNT_NOT_FOUND,
    SRV_SSO_BUSY,
    SRV_SSO_CONNECTION_FAIL,
    SRV_SSO_INCORRECT_ID_PW,
    SRV_SSO_NOT_FULL_EMAIL,
    SRV_SSO_CANCELLED,
    SRV_SSO_UPGRADING,
    SRV_SSO_FAIL_TO_LOAD_PLUGIN,
} srv_sso_result;

typedef enum
{
    SRV_SSO_LOGIN_DONT_CARE,
    SRV_SSO_LOGIN_TRUE,
    SRV_SSO_LOGIN_FALSE,
} srv_sso_login_state;

typedef enum
{
    SRV_SSO_ICON_LARGE,
    SRV_SSO_ICON_SMALL,
    SRV_SSO_ICON_TOTAL,
} srv_sso_icon_enum;

typedef struct srv_sso_provider
{
    U32 provider;
    U8 accounts_total;    /**< number of total accounts               */
    U8 accounts_loggedin; /**< number of accounts which are logged-in */
} srv_sso_provider_struct;

typedef struct srv_sso_account
{
    U32 provider;
    U8 account;
    MMI_BOOL is_login;
} srv_sso_account_struct;

typedef enum
{
   SRV_SSO_CREDENTIAL_OAUTH,
   SRV_SSO_CREDENTIAL_USERPASS,
   SRV_SSO_CREDENTIAL_YAHOO,
} srv_sso_credential_enum;

typedef struct srv_sso_credential
{
    srv_sso_credential_enum type;
    union 
    {
       struct 
       {
          CHAR access_token[SRV_SSO_ACCESS_TOKEN];
          CHAR refresh_token[SRV_SSO_REFRESH_TOKEN];
          CHAR scope[SRV_SSO_SCOPE];
          CHAR extension[SRV_SSO_EXTENSION];
       } oauth;
       struct 
       {
          CHAR username[SRV_SSO_NAME_SIZE];
          CHAR password[SRV_SSO_NAME_SIZE];
       } userpass;       
       struct 
       {
          CHAR security_token[SRV_SSO_ACCESS_TOKEN];
          CHAR ycookie[SRV_SSO_EXT_YAHOO_COOKIE];
          CHAR tcookie[SRV_SSO_EXT_YAHOO_COOKIE];
          CHAR crumb[SRV_SSO_EXT_YAHOO_CRUMB];
       } yahoo;
    } value;
} srv_sso_credential_struct;

/**
 * event structure for EVT_ID_SRV_SSO_READY
 */
typedef struct {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
   MMI_BOOL is_ready;
   S32 reason;
} srv_sso_evt_ready_struct;

/**
 * event structure for EVT_ID_SRV_SSO_LOGIN | EVT_ID_SRV_SSO_LOGOUT | EVT_ID_SRV_SSO_REFRESH 
 */
typedef struct {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
   U32 provider;
   U8 account;
} srv_sso_evt_account_state_struct;

/** 
 * event structure for EVT_ID_SRV_SSO_PLUGINS_UPGRADED 
 */
typedef struct {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
   MMI_BOOL is_successful;
} srv_sso_evt_plugins_upgraded_struct;

typedef void (*srv_sso_account_callback)(S32 req_id, srv_sso_result result, U32 provider, U8 account, void *userdata);

typedef void (*srv_sso_result_callback)(S32 req_id, srv_sso_result result, void *userdata);


/**
 * check if SSO Service is ready
 * @returns TRUE if ready
 */
MMI_BOOL srv_sso_is_ready(void);

/**
 * get ready state of SSO Service
 * @returns SSO return codes
 */
S32 srv_sso_get_ready(void);

/**
 * get the number of providers
 * @returns the number of providers
 */
U8 srv_sso_get_provider_count(void);

/**
 * get info for all providers
 * @param [out] buffer memory allocated by caller to hold the provider structure
 * @param [in] buffer_items  number of items the buffer can hold
 * @returns the number of providers filled
 */
U8 srv_sso_get_providers(srv_sso_provider_struct *buffer, U8 buffer_items);

/**
 * check if a provider exists
 * @param [in] provider the provider id as in srv_sso_provider_struct.provider
 * @param [in] buffer copy provider info if not NULL
 * @returns whether the provider exists
 */
MMI_BOOL srv_sso_get_provider(U32 provider, srv_sso_provider_struct *buffer);

/**
 * get the name of a provider by its id
 * @param [in] provider the provider id as in srv_sso_provider_struct.provider
 * @param [in] type the size of icon to get
 * @returns the file path of the icon
 */
WCHAR *srv_sso_get_provider_icon(U32 provider, srv_sso_icon_enum type);

/**
 * get the name of a provider by its id
 * @param [in] provider  the provider id as in srv_sso_provider_struct.provider
 * @param [out] buffer memory allocated by caller to hold the name of the provider, must be at least SRV_SSO_NAME_SIZE bytes
 */
MMI_BOOL srv_sso_get_provider_name(U32 provider, WCHAR *buffer);

/**
 * get the signup url of a provider by its id
 * @param [in] provider  the provider id as in srv_sso_provider_struct.provider
 * @param [out] buffer memory allocated by caller to hold the signup url  of the provider, must be at least SRV_SSO_URL_SIZE bytes
 */
MMI_BOOL srv_sso_get_provider_signup_url(U32 provider, WCHAR *buffer);

/**
 * get the number of accounts for a provider according the login state
 * @param [in] provider the provider id as in srv_sso_provider_struct.provider
 * @param [in] login_state login state to filter accounts
 * @returns the number of accounts
 */
U8 srv_sso_get_account_count(U32 provider, srv_sso_login_state login_state);

/**
 * get the info of accounts for a provider according the login state
 * @param [in] provider  the provider id as in srv_sso_provider_struct.provider
 * @param [in] login_state  login state to filter accounts
 * @param [out] buffer memory allocated by caller to hold the account structure
 * @param [in] buffer_items  number of items the buffer can hold
 * @returns the number of accounts
 */
U8 srv_sso_get_accounts(U32 provider, srv_sso_login_state login_state, srv_sso_account_struct *buffer, U8 buffer_items);

/**
 * check if an account exists
 * @param [in] provider  the provider id as in srv_sso_account_struct.provider
 * @param [in] account  the account id as in srv_sso_account_struct.account
 * @param [out] buffer copy account info if not NULL
 * @returns whether the account exists
 */
MMI_BOOL srv_sso_get_account(U32 provider, U8 account, srv_sso_account_struct *buffer);

/**
 * get the username of an account by its provider and account id
 * @param [in] provider  the provider id as in srv_sso_account_struct.provider
 * @param [in] account  the account id as in srv_sso_account_struct.account
 * @param [out] buffer memory allocated by caller to hold the username of the account, must be at least SRV_SSO_NAME_SIZE bytes
 */
MMI_BOOL srv_sso_get_account_name(U32 provider, U8 account, WCHAR *buffer);

/**
 * get the credentials of an account by its provider and account id
 * @param [in] provider  the provider id as in srv_sso_account_struct.provider
 * @param [in] account  the account id as in srv_sso_account_struct.account
 * @param [out] buffer memory allocated by caller to hold the credentials of the account, must be at least sizeof(srv_sso_credential_struct) bytes
 */
MMI_BOOL srv_sso_get_credentials(U32 provider, U8 account, srv_sso_credential_struct *buffer);

/**
 * launch plugin to prompt user for username/password in exchange for credentials
 * @param [in] provider the provider id as in srv_sso_provider_struct.provider
 * @param [in] username username of account
 * @param [in] password password of account
 * @param [in] callback will be called when the operation is done, no matter success or failure
 * @param [in] userdata user data to be pass along by the callback function
 */
S32 srv_sso_add_account(U32 provider, WCHAR *username, WCHAR *password, srv_sso_account_callback callback, void *userdata);

/**
 * log in to an existing account which has been logged out
 * @param [in] provider the provider id as in srv_sso_account_struct.provider
 * @param [in] account the account id as in srv_sso_account_struct.account
 * @param [in] password password of account, user needs to enter again
 * @param [in] callback will be called when the operation is done, no matter success or failure
 * @param [in] userdata user data to be pass along by the callback function
 */
S32 srv_sso_login_account(U32 provider, U8 account, WCHAR *password, srv_sso_account_callback callback, void *userdata);

/**
 * logout account but still keep it for log-in later
 * @param [in] provider the provider id as in srv_sso_provider_struct.provider
 * @param [in] account the account id as in srv_sso_account_struct.account
 * @param [in] callback will be called when the operation is done, no matter success or failure
 * @param [in] userdata user data to be pass along by the callback function
 */
S32 srv_sso_logout_account(U32 provider, U8 account, srv_sso_result_callback callback, void *userdata);

/**
 * delete account and do the necessary clean-ups
 * @param [in] provider the provider id as in srv_sso_account_struct.provider
 * @param [in] account the account id as in srv_sso_account_struct.account
 * @param [in] callback will be called when the operation is done, no matter success or failure
 * @param [in] userdata user data to be pass along by the callback function
 */
S32 srv_sso_del_account(U32 provider, U8 account, srv_sso_result_callback callback, void *userdata);

/**
 * ask plugin to refresh access token by using refresh token or extension
 * @param [in] provider the provider id as in srv_sso_account_struct.provider
 * @param [in] account the account id as in srv_sso_account_struct.account
 * @param [in] callback will be called when the operation is done, no matter success or failure
 * @param [in] userdata user data to be pass along by the callback function
 */
S32 srv_sso_refresh_credentials(U32 provider, U8 account, srv_sso_result_callback callback, void *userdata);

/**
 * cancel an running operation
 * @param [in] req_id request id
 */
void srv_sso_cancel(S32 req_id);

/**
 * get error string for error code
 * @param [in] error_code error code
 */
MMI_STR_ID srv_sso_get_error_string(S32 error_code);


#endif
