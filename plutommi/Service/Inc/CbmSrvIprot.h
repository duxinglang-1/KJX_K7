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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef _CBM_SRV_IPROT_H_
#define _CBM_SRV_IPROT_H_

#include "MMI_include.h"

#ifndef _CBM_CONSTS_H
#include "cbm_consts.h"
#endif

#include "MMIDataType.h"
#include "mmi_res_range_def.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"

#include "CbmSrvGprot.h"
#include "DtcntSrvGprot.h"

/*************************************************************************
* Constant values
*************************************************************************/

/* CBM service event id definition */
typedef enum
{
    EVT_ID_SRV_CBM_BEARER_INFO = EVT_ID_SRV_CBM_EVT_ID_TOTAL + 1, /* bearer info event */
    EVT_ID_SRV_CBM_BEARER_EVENT, /* bearer event, such as always ask or fallback */
    EVT_ID_SRV_CBM_WLAN_QUERY, /* WLAN query event */
    EVT_ID_SRV_CBM_WLAN_UNUSED, /* WLAN unused event */
    EVT_ID_SRV_CBM_EVENT_TOTAL
} srv_cbm_event_enum;


/*************************************************************************
* Structures
*************************************************************************/

typedef enum
{
    SRV_CBM_WLAN_QUERY_TYPE_NONE,
    SRV_CBM_WLAN_QUERY_TYPE_STARTUP,
    SRV_CBM_WLAN_QUERY_TYPE_RECONNECT,
    SRV_CBM_WLAN_QUERY_TYPE_DISCONNECTED,
    SRV_CBM_WLAN_QUERY_TYPE_RESWITCH,
    SRV_CBM_WLAN_QUERY_TYPE_FOUND,
    SRV_CBM_WLAN_QUERY_TYPE_REQUERY,
    SRV_CBM_WLAN_QUERY_TYPE_AUTO_CONN,
    SRV_CBM_WLAN_QUERY_TYPE_CANCEL,
    SRV_CBM_WLAN_QUERY_TYPE_TOTAL
} srv_cbm_wlan_query_type_enum;

typedef void (*srv_cbm_wlan_query_cb_func_ptr)(U32 bearer_type);

/* Event structure for EVT_ID_SRV_CBM_WLAN_QUERY */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;             /* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;        /* Piggyback user data */
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    srv_cbm_wlan_query_type_enum query_type;
    srv_cbm_wlan_query_cb_func_ptr rsp_callback; /* After getting AP list, APP need to call this cb to notify SRV. */
} srv_cbm_wlan_query_evt_struct;


extern srv_cbm_result_error_enum srv_cbm_get_real_account(U32 nw_acct_id, U32 *rel_acct_id);
extern void srv_cbm_get_wlan_prefer_setting(
                srv_cbm_wlan_query_type_enum query_type,
                MMI_BOOL *auto_conn,
                MMI_BOOL *need_notify);
extern U8 srv_cbm_get_valid_wlan_ap_num(MMI_BOOL check_store_prof, srv_dtcnt_wlan_scan_result_struct *scan_info_p);
extern MMI_BOOL srv_cbm_get_ask_cellular_setting(void);
extern void srv_cbm_set_ask_cellular_setting(MMI_BOOL ask_cellular);
extern MMI_BOOL srv_cbm_is_wlan_query_needed(void);

extern MMI_BOOL srv_cbm_is_wlan_used_by_app(void);

#endif /* _CBM_SRV_IPROT_H_ */

