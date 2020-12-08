#ifndef __CLOUD_PLUG_IN_H__
#define __CLOUD_PLUG_IN_H__

#include "vmsys.h"

#define SRV_CLOUD_NAME_LEN              (64)
#define SRV_CLOUD_URL_LEN               (256)
#define CLOUD_PLUGIN_FEATURE_TOTAL      (8)
#define CLOUD_PLUGIN_NAME_SIZE          (64)

/* feature */
#define CLOUD_PLUGIN_FEATURE_TYPE_CONTACT_BACKUP_RESTORE           0x0001 //
#define CLOUD_PLUGIN_FEATURE_TYPE_SMS_BACKUP_RESTORE               0x0002 //
#define CLOUD_PLUGIN_FEATURE_TYPE_EMAIL_REFRESH                    0x0004 //

/* protocol */
#define CLOUD_PLUGIN_PROTOCOL_TYPE_HTTP                   0x00010000
#define CLOUD_PLUGIN_PROTOCOL_TYPE_HTTPS                  0x00020000
#define CLOUD_PLUGIN_PROTOCOL_IMAP                        0x00040000
#define CLOUD_PLUGIN_PROTOCOL_CARDDAV                     0x00080000
#define CLOUD_PLUGIN_PROTOCOL_SMTP                        0x00100000 //

#define CLOUD_PLUGIN_PATH "%c:\\mre_cloud\\"
#define CLOUD_PLUGIN_TARGET_EXT L"*.vpp"
#define CLOUD_PLUGIN_MODIS_EXT  L"*.dll"

typedef enum
{
    CLOUD_PLUGIN_SEC_NONE = 0,
    CLOUD_PLUGIN_SEC_SSL_TLS,
    CLOUD_PLUGIN_SEC_STARTTLS,
    CLOUD_PLUGIN_SEC_TOTAL
} cloud_plugin_sec_mode_enum;

typedef struct
{
    VMUINT32 features;                            //format: FEATURE | PROTOCOL
    VMUINT8 d_name_space[SRV_CLOUD_NAME_LEN];    // the normal namespace of the server.
    VMUINT8 c_name_space[SRV_CLOUD_NAME_LEN];    // the collect namespace of the server.
    VMUINT8 user_agent[SRV_CLOUD_NAME_LEN];      // the user agent.
    VMUINT8 server[SRV_CLOUD_URL_LEN];           // the server address.
    VMUINT8 url[SRV_CLOUD_URL_LEN];              // the contact url on the server.
    VMUINT16 port_num;                           // the port number
    cloud_plugin_sec_mode_enum sec_mode;         // the security mode
}cloud_plugin_server_info_struct;

typedef struct
{
    VMUINT32 id;
    cloud_plugin_server_info_struct server[CLOUD_PLUGIN_FEATURE_TOTAL]; //format: FEATURE | PROTOCOL
}cloud_plugin_provider_struct;



/******************************************************************************
 * FUNCTION
 *    cloud_plugin_get_data_account
 * DESCRIPTION
 *    get data account.
 * PARAMETERS
 *    provider:         [IN]  the provider id of service vendor, 
 *    account_id:     [OUT]  data account used to access network
 * RETURNS
 *    return 0 if success, otherwise < 0.
 ******************************************************************************/
typedef VMINT ( * cloud_plugin_get_data_account_func)(VMUINT32 provider, VMUINT32 * account_id ); 
VMINT cloud_plugin_get_data_account(VMUINT32 provider, VMUINT32 * account_id );


/********************************************************************************
* FUNCTION
*    cloud_plugin_get_provider_features
* DESCRIPTION
*    get service type which provider can support. 
* PARAMETERS
*    info:             [OUT] information of provider
* RETURNS
*  
*********************************************************************************/

typedef void (*cloud_plugin_manifest_func)(cloud_plugin_provider_struct * );

void cloud_plugin_manifest(
    cloud_plugin_provider_struct *info
);


#endif  //__CLOUD_PLUG_IN_H__
