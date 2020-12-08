/*****************************************************************************
*
* Filename:
* ---------
* CbmSrvGprot.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file contains the CBM APIs
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef _CBM_SRV_GPROT_H_
#define _CBM_SRV_GPROT_H_

#include "MMI_include.h"

#ifndef _CBM_CONSTS_H
#include "cbm_consts.h"
#endif

#include "MMIDataType.h"
#include "mmi_res_range_def.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "ps_public_enum.h"
 
/*************************************************************************
* Constant values
*************************************************************************/


/*************************************************************************
* Enum values
*************************************************************************/

/* CBM service event id definition */
typedef enum
{
    EVT_ID_SRV_CBM_BEARER_UNAVAILABLE = SRV_CBM_BASE + 1, /* bearer unavailable event */
    EVT_ID_SRV_CBM_BEARER_AVAILABLE, /* bearer available event */
    EVT_ID_SRV_CBM_EVT_ID_TOTAL
} srv_cbm_evt_id_enum;

/* This structure defines MMI CBM service error cause */
typedef enum
{
    SRV_CBM_OK                  = MMI_RET_OK,  /* success */
    SRV_CBM_ERROR               = CBM_ERROR, /* error */
    SRV_CBM_LIMIT_RESOURCE      = CBM_LIMIT_RESOURCE, /* limited resource */
    SRV_CBM_INVALID_ACCT_ID     = CBM_INVALID_ACCT_ID, /* invalid account id*/
    SRV_CBM_INVALID_AP_ID       = CBM_INVALID_AP_ID, /* invalid application id*/
    SRV_CBM_INVALID_SIM_ID      = CBM_INVALID_SIM_ID, /* invalid SIM id */
    SRV_CBM_BEARER_FAIL         = CBM_BEARER_FAIL, /* bearer fail */
    SRV_CBM_DHCP_ERROR          = CBM_DHCP_ERROR, /* DHCP get IP error */
    SRV_CBM_CANCEL_ACT_BEARER   = CBM_CANCEL_ACT_BEARER, /* cancel the account query screen, such as always ask or bearer fallback screen */
    SRV_CBM_DISC_BY_CM          = CBM_DISC_BY_CM /* bearer is deactivated by the connection management */
} srv_cbm_result_error_enum;
    
/* This enum is used to define bearer status */
typedef enum
{
    SRV_CBM_DEACTIVATED             = CBM_DEACTIVATED, /* bearer deactivated */
    SRV_CBM_ACTIVATING              = CBM_ACTIVATING, /* bearer activating */
    SRV_CBM_ACTIVATED               = CBM_ACTIVATED, /* bearer activated */
    SRV_CBM_DEACTIVATING            = CBM_DEACTIVATING, /* bearer deactivating */
    SRV_CBM_CSD_AUTO_DISC_TIMEOUT   = CBM_CSD_AUTO_DISC_TIMEOUT, /* csd auto disconnection timeout */
    SRV_CBM_GPRS_AUTO_DISC_TIMEOUT  = CBM_GPRS_AUTO_DISC_TIMEOUT, /* gprs auto disconnection timeout */
    SRV_CBM_NWK_NEG_QOS_MODIFY      = CBM_NWK_NEG_QOS_MODIFY, /* negotiated network qos modify notification */
    SRV_CBM_BEARER_STATE_TOTAL
} srv_cbm_bearer_state_enum;
    
/* This enum is used to define bearer type */
typedef enum
{
    SRV_CBM_BEARER_INVALID = CBM_BEARER_NONE, /* invalid bearer type*/
    SRV_CBM_BEARER_CSD = CBM_CSD, /* csd bearer type */
    
    SRV_CBM_BEARER_GPRS = CBM_GPRS, /* gprs bearer type */
    SRV_CBM_BEARER_EDGE = CBM_EDGE, /* edge bearer type */
    SRV_CBM_BEARER_UMTS = CBM_UMTS, /* umts (3G) bearer type */

    SRV_CBM_BEARER_PS = CBM_PS, /* packet service type */
    
    SRV_CBM_BEARER_WIFI = CBM_WIFI, /* wireless lan bearer type */
    
    SRV_CBM_BEARER_DIALUP = CBM_BEARER_TOTAL+1, /* dialup bearer type, it is the interface used by non-phone application */
    SRV_CBM_BEARER_LOCAL = SRV_CBM_BEARER_DIALUP << 1, /* local bearer type, it is the interface used by phone application */
    SRV_CBM_BEARER_TOTAL
} srv_cbm_bearer_type_enum;

/* CBM service event type id definition */
typedef enum
{
    SRV_CBM_BEARER_ALWAYS_ASK = 0x01,
    SRV_CBM_BEARER_FB_L1 = 0x02, /* fallback level one */
    SRV_CBM_BEARER_FB_L1_WITH_NEW_CONN = 0x04, /* fallback level one with new connection */
    SRV_CBM_BEARER_FB_L2_WITH_NEW_CONN = 0x08, /* fallback level two with new connection */
    SRV_CBM_BEARER_WIFI_PREFER = 0x10,
    SRV_CBM_BEARER_FB_WIFI_TO_PS = 0x20,
    SRV_CBM_BEARER_EVENT_SWITCH = 0x40, /* Bearer switch */
    SRV_CBM_BEARER_EVENT_DISCONNECT = 0x80, /* Bearer is disconnected */
    SRV_CBM_BEARER_QUERY_TOTAL
} srv_cbm_bearer_event_type_enum;


/*************************************************************************
* Structures
*************************************************************************/


/* This structure is used to define the structure obtained in callback
 * function "srv_cbm_bearer_info_func"
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    U32 account_id; /* network account id */
    srv_cbm_bearer_state_enum state; /* bearer state */
    srv_cbm_bearer_type_enum  type; /* bearer type */
    srv_cbm_result_error_enum error; /* error */
    S32 error_cause; /* network error cause */
} srv_cbm_bearer_info_struct;

/* CBM bearer switch type definition */
typedef enum
{
    SRV_CBM_BEARER_SWITCH_NONE,
    SRV_CBM_BEARER_SWITCH_WIFI_TO_PS,
    SRV_CBM_BEARER_SWITCH_WIFI_TO_WIFI,
    SRV_CBM_BEARER_SWITCH_PS_TO_WIFI,
    SRV_CBM_BEARER_SWITCH_TOTAL
} srv_cbm_bearer_switch_type_enum;

/* This structure is used to define the structure obtained in callback
 * function "srv_cbm_bearer_event_func"
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_cbm_bearer_event_type_enum type; /* bearer query type */
    U32 account_id; /* account id include app id, sim id, etc. */
    srv_cbm_bearer_type_enum ori_bearer_type; /* original bearer type */
    srv_cbm_bearer_switch_type_enum switch_type; /* bearer switch type */
    MMI_BOOL user_result; /* user selected result */
} srv_cbm_bearer_event_struct;


/*************************************************************************
* External APIs
*************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_cbm_register_bearer_info
 * DESCRIPTION
 *  register application's bearer info, such as bearer status, bearer type, etc.
 * PARAMETERS
 *  app_id    : [IN]   application identification
 *  state     : [IN]   bearer state
 *  type      : [IN]   bearer type
 *  callback  : [IN]   callback function
 *  user_data : [IN]   user data
 * RETURN VALUES
 *  SRV_CBM_OK : success
 *  SRV_CBM_ERROR : wrong parameters
 *  SRV_CBM_LIMIT_RESOURCE : limited resources
 *  SRV_CBM_INVALID_AP_ID : invalid application id
 * SEE ALSO
 *  srv_cbm_deregister_bearer_info
 * EXAMPLE
 *  <code>
 *   ret = srv_cbm_register_bearer_info(
 *          app_id,
 *          SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED,
 *          SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
 *          srv_app_bearer_info_ind_hdlr, NULL);
 *   if (ret != SRV_CBM_OK)
 *   {
 *       goto error;
 *   }
 *  </code>
 *****************************************************************************/
srv_cbm_result_error_enum srv_cbm_register_bearer_info(U8 app_id,
                                                       U32 state,
                                                       U32 type,
                                                       mmi_proc_func callback,
                                                       void *user_data);
    
/*****************************************************************************
 * FUNCTION
 *  srv_cbm_deregister_bearer_info
 * DESCRIPTION
 *  deregister application's bearer info
 * PARAMETERS
 *  app_id    : [IN]   application identification
 * RETURN VALUES
 *  SRV_CBM_OK : success
 *  SRV_CBM_ERROR : wrong parameters
 *  SRV_CBM_INVALID_AP_ID : invalid application id
 * SEE ALSO
 *  srv_cbm_register_bearer_info
 * EXAMPLE
 *  <code>
 *       srv_cbm_deregister_bearer_info(app_id);
 *  </code>
 *****************************************************************************/
srv_cbm_result_error_enum srv_cbm_deregister_bearer_info(U8 app_id);
    
/*****************************************************************************
 * FUNCTION
 *  srv_cbm_register_bearer_event
 * DESCRIPTION
 *  register bearer event, such as fallback, always ask, etc.
 * PARAMETERS
 *  type     : [IN]    bearer query type (srv_cbm_bearer_event_type_enum)
 *  app_id   : [IN]    application identification
 *  callback : [IN]  callback function
 * RETURN VALUES
 *  SRV_CBM_OK : success
 *  SRV_CBM_ERROR : wrong parameters
 *  SRV_CBM_LIMIT_RESOURCE : limited resources
 *  SRV_CBM_INVALID_AP_ID : invalid application id
 * SEE ALSO
 *  srv_cbm_deregister_bearer_query
 * EXAMPLE
 *  <code>
 *   ret = srv_cbm_register_bearer_event(
 *          SRV_CBM_BEARER_BEARER_SWITCH,
 *          app_id,
 *          srv_app_bearer_event_ind_hdlr,
 *          NULL);
 *   if (ret != SRV_CBM_OK)
 *   {
 *       goto error;
 *   }
 *  </code>
 *****************************************************************************/
srv_cbm_result_error_enum srv_cbm_register_bearer_event(
                            U32 type,
                            U8 app_id,
                            mmi_proc_func callback,
                            void *user_data);
    
/*****************************************************************************
 * FUNCTION
 *  srv_cbm_deregister_bearer_event
 * DESCRIPTION
 *  deregister application's bearer event
 * PARAMETERS
 *  app_id   : [IN]    application identification
 * RETURN VALUES
 *  SRV_CBM_OK : success
 *  SRV_CBM_ERROR : wrong parameters
 *  SRV_CBM_INVALID_AP_ID : invalid application id
 * SEE ALSO
 *  srv_cbm_register_bearer_event
 * EXAMPLE
 *  <code>
 *       srv_cbm_deregister_bearer_event(app_id);
 *  </code>
 *****************************************************************************/
srv_cbm_result_error_enum srv_cbm_deregister_bearer_event(U8 app_id);

/*****************************************************************************
 * FUNCTION
 *  srv_cbm_abort_app_bearer_event
 * DESCRIPTION
 *  Abort bearer event, such as always ask or bearer fallback event.
 * PARAMETERS
 *  app_id    : [IN]   application identification
 * RETURN VALUES
 *  SRV_CBM_OK : success
 *  SRV_CBM_ERROR : error occurs
 *  SRV_CBM_INVALID_AP_ID : invalid application id
 * EXAMPLE
 *  <code>
 *       srv_cbm_abort_app_bearer_event(app_id);
 *  </code>
 *****************************************************************************/
srv_cbm_result_error_enum srv_cbm_abort_app_bearer_event(U8 app_id);

/*****************************************************************************
 * FUNCTION
 *  srv_cbm_disallow_nwk_srv
 * DESCRIPTION
 *  disallow whole phone network service. user can specified which bearer type s/he
 *  wants to disallow.
 * PARAMETERS
 *  type      : [IN]   network service type (srv_cbm_bearer_type_enum)
 *  app_id    : [IN]   application identification used to check who do this 
 *                     dangerous action
 * RETURN VALUES
 *  SRV_CBM_OK : success
 *  SRV_CBM_ERROR : error occurs
 * SEE ALSO
 *  srv_cbm_allow_bearer_activation
 * EXAMPLE
 *  <code>
 *      result = srv_cbm_disallow_nwk_srv(SRV_CBM_BEARER_GPRS, app_id);
 *      if (result != SRV_CBM_OK)
 *      {
 *            MMI_STR_ID string_id;
 *            mmi_event_notify_enum popup_type;
 *	
 *            srv_cbm_get_nwk_srv_error_info(ret,&string_id, &event_type);                        
 *             ...
 *            mmi_popup_display((WCHAR *) GetString(string_id), MMI_EVENT_FAILURE, &arg);
 *      }
 *  </code>
 *****************************************************************************/
srv_cbm_result_error_enum srv_cbm_disallow_nwk_srv(U32 type, U8 app_id);
    
/*****************************************************************************
 * FUNCTION
 *  srv_cbm_allow_nwk_srv
 * DESCRIPTION
 *  allow whole phone network service. user can speicified whcih bearer type s/he
 *  wants to allow.
 * PARAMETERS
 *  type      : [IN]   bearer type (srv_cbm_bearer_type_enum)
 *  app_id    : [IN]   application identification used to check who do this 
 *                     dangerous action
 * RETURN VALUES
 *  SRV_CBM_OK : success
 *  SRV_CBM_ERROR : error occurs
 * SEE ALSO
 *  srv_cbm_disallow_bearer_activation
 * EXAMPLE
 *  <code>
 *      // allow PS(GPRS, 3G, etc) and CSD network
 *       srv_cbm_allow_nwk_srv(SRV_CBM_BEARER_PS|SRV_CBM_BEARER_CSD, app_id);
 * </code>
 *****************************************************************************/
srv_cbm_result_error_enum srv_cbm_allow_nwk_srv(U32 type, U8 app_id);

/*****************************************************************************
 * FUNCTION
 *  srv_cbm_set_allowed_app_nwk_srv
 * DESCRIPTION
 *  Application can call this API to allow application network service when bearer is disallowed.
 *  
 * PARAMETERS
 *  type     : [IN]    which bearer type it wants to allow the network service. 
 *                     (srv_cbm_bearer_type_enum)
 *  app_id   : [IN]    application identification
 *  
 * RETURN VALUES
 *  SRV_CBM_OK : OK
 *  SRV_CBM_ERROR: error occurs
 * EXAMPLE
 *  <code>
 *  kal_int8 ret;
 *  ...
 *  app_id = cbm_register_app_id(STR_ID, ICON_ID);
 *  ...
 *  ret = srv_cbm_set_allowed_app_nwk_srv(SRV_CBM_CSD|SRV_CBM_PS|SRV_CBM_WIFI, app_id);
 *  if (ret != SRV_CBM_OK)
 *  {
 *       return error;
 *  }
 *  ...
 *  </code>
 *****************************************************************************/
srv_cbm_result_error_enum srv_cbm_set_allowed_app_nwk_srv(U32 type, kal_uint8 app_id);
    
/*****************************************************************************
 * FUNCTION
 *  srv_cbm_get_nwk_srv_error_info
 * DESCRIPTION
 *  get network service error string and pop up type
 * PARAMETERS
 *  error      : [IN]   input error reason
 *  str_id     : [OUT]  error string id
 *  popup_type : [OUT]  error pop up type
 * RETURN VALUES
 *  SRV_CBM_OK : success
 *  SRV_CBM_ERROR : wrong input error cause
 * EXAMPLE
 *  <code>
 *      MMI_STR_ID string_id = 0;
 *      mmi_event_notify_enum event_type = 0;   
 *      srv_cbm_get_nwk_srv_error_info(ret,&string_id, &event_type);              
 *       ...
 *      mmi_popup_display((WCHAR *) GetString(string_id), MMI_EVENT_FAILURE, &arg);
 *  </code>
 *****************************************************************************/
srv_cbm_result_error_enum srv_cbm_get_nwk_srv_error_info(srv_cbm_result_error_enum error,
                                                         MMI_STR_ID *str_id,
                                                         mmi_event_notify_enum *popup_type);
    
/*****************************************************************************
 * FUNCTION
 *  srv_cbm_is_nwk_srv_disallowed
 * DESCRIPTION
 *  check whether the network service is disallowed or not currently.
 * PARAMETERS
 *  type      : [IN]   bearer type  (srv_cbm_bearer_type_enum)
 * RETURN VALUES
 *  MMI_TRUE : network is disallowed
 *  MMI_FALSE : network is not disallowed
 * EXAMPLE
 *  <code>
 *  if (srv_cbm_is_nwk_srv_disallowed(SRV_CBM_BEARER_PS|SRV_CBM_BEARER_CSD) == MMI_TRUE)
 *  {
 *       // network PS(GPRS and 3G, etc) or CSD is disallowed now
 *  } 
 *  </code>
 *****************************************************************************/
MMI_BOOL srv_cbm_is_nwk_srv_disallowed(U32 type);


/*****************************************************************************
 * FUNCTION
 *  srv_cbm_disallow_nwk_srv_by_sim
 * DESCRIPTION
 *  disallow whole phone network service. user can specified which bearer type s/he
 *  wants to disallow.
 * PARAMETERS
 *  type      : [IN]   network service type (srv_cbm_bearer_type_enum)
 *  app_id    : [IN]   application identification used to check who do this 
 *                     dangerous action
 * RETURN VALUES
 *  SRV_CBM_OK : success
 *  SRV_CBM_ERROR : error occurs
 * SEE ALSO
 *  srv_cbm_allow_bearer_activation
 * EXAMPLE
 *  <code>
 *      result = srv_cbm_disallow_nwk_srv_by_sim(CBM_SIM_ID_SIM1, SRV_CBM_BEARER_GPRS, app_id);
 *      if (result != SRV_CBM_OK)
 *      {
 *            MMI_STR_ID string_id;
 *            mmi_event_notify_enum popup_type;
 *	
 *            srv_cbm_get_nwk_srv_error_info(ret,&string_id, &event_type);                        
 *             ...
 *            mmi_popup_display((WCHAR*)GetString(string_id), MMI_EVENT_FAILURE, &arg);
 *      }
 *  </code>
 *****************************************************************************/
srv_cbm_result_error_enum srv_cbm_disallow_nwk_srv_by_sim(cbm_sim_id_enum sim_id, U32 type, U8 app_id);
    
/*****************************************************************************
 * FUNCTION
 *  srv_cbm_allow_nwk_srv
 * DESCRIPTION
 *  allow whole phone network service. user can speicified whcih bearer type s/he
 *  wants to allow.
 * PARAMETERS
 *  type      : [IN]   bearer type (srv_cbm_bearer_type_enum)
 *  app_id    : [IN]   application identification used to check who do this 
 *                     dangerous action
 * RETURN VALUES
 *  SRV_CBM_OK : success
 *  SRV_CBM_ERROR : error occurs
 * SEE ALSO
 *  srv_cbm_disallow_bearer_activation
 * EXAMPLE
 *  <code>
 *      // allow PS(GPRS, 3G, etc) and CSD network
 *       srv_cbm_allow_nwk_srv_by_sim(CBM_SIM_ID_SIM1, SRV_CBM_BEARER_PS|SRV_CBM_BEARER_CSD, app_id);
 *  </code>
 *****************************************************************************/
srv_cbm_result_error_enum srv_cbm_allow_nwk_srv_by_sim(cbm_sim_id_enum sim_id, U32 type, U8 app_id);

/*****************************************************************************
 * FUNCTION
 *  srv_cbm_is_nwk_srv_disallowed
 * DESCRIPTION
 *  check whether the network service is disallowed or not currently.
 * PARAMETERS
 *  type      : [IN]   bearer type  (srv_cbm_bearer_type_enum)
 * RETURN VALUES
 *  MMI_TRUE : network is disallowed
 *  MMI_FALSE : network is not disallowed
 * EXAMPLE
 *  <code>
 *  if (srv_cbm_is_sim_nwk_srv_disallowed(CBM_SIM_ID_SIM1, SRV_CBM_BEARER_PS|SRV_CBM_BEARER_CSD) == MMI_TRUE)
 *  {
 *       // network PS(GPRS and 3G, etc) or CSD of SIM1 is disallowed now
 *  } 
 *  </code>
 *****************************************************************************/
MMI_BOOL srv_cbm_is_sim_nwk_srv_disallowed(cbm_sim_id_enum sim_id, U32 type);

#endif /* _CBM_SRV_GPROT_H_ */

