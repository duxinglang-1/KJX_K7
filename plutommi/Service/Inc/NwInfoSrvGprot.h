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
 *  NwInfoSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface of network info.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SRV_NW_INFO_GPROT_H__
#define __SRV_NW_INFO_GPROT_H__


/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"
#include "SimCtrlSrvGprot.h"


/****************************************************************************
 * Compile options & constants
 ****************************************************************************/

#ifdef __MMI_NETWORK_CIPHER_SUPPORT__
/*
 * DESCRIPTION
 *  Compile option: cipher network information support.
 *  Cipher information is valid only if this compile option is turned on.
 *  This macro is defined if and only if system compile option
 *  __MMI_NETWORK_CIPHER_SUPPORT__ is defined.
 */
#define __SRV_NW_INFO_CIPHER_SUPPORT__
#endif /* __MMI_NETWORK_CIPHER_SUPPORT__ */

/*
 * DESCRIPTION
 *  Maximum string length of homezone tag.
 */
#define SRV_NW_INFO_MAX_HOMEZONE_TAG_LEN 12

/****************************************************************************
 * Typedef
 ****************************************************************************/

/*
 * DESCRIPTION
 *  Network band.
 */
typedef enum
{
    SRV_NW_BAND_NONE        = 0x00,     /* No network */
    SRV_NW_BAND_GSM900      = 0x02,     /* GSM900 */
    SRV_NW_BAND_DCS1800     = 0x08,     /* DCS1800 */
    SRV_NW_BAND_PCS1900     = 0x10,     /* PCS1900 */
    SRV_NW_BAND_GSM450      = 0x20,     /* GSM450 */
    SRV_NW_BAND_GSM480      = 0x40,     /* GSM480 */
    SRV_NW_BAND_GSM850      = 0x80,     /* GSM850 */
    SRV_NW_BAND_OTHERS      = 0xf0,     /* Other band not defined above. */

    SRV_NW_BAND_END_OF_ENUM
} srv_nw_band_enum;


/*
 * DESCRIPTION
 *  Network service availability.
 *  Including SEARCHING, NO_SERVICE, LIMITED_SERVICE, FULL_SERVICE. Note that
 *  the service availability is a temporary state, and will change very quickly.
 */
typedef enum
{
    SRV_NW_INFO_SA_SEARCHING,       /* Searching network */
    SRV_NW_INFO_SA_NO_SERVICE,      /* No service */
    SRV_NW_INFO_SA_LIMITED_SERVICE, /* Limited service, emergency call only */
    SRV_NW_INFO_SA_FULL_SERVICE,    /* Full service */

    SRV_NW_INFO_SA_END_OF_ENUM
} srv_nw_info_service_availability_enum;


/*
 * DESCRIPTION
 *  Bit set of mmi_network_capability_enum. It may combine none,
 *  one or more bits of mmi_network_capability_enum.
 * SEE ALSO
 *  mmi_network_capability_enum
 */
typedef U32 srv_nw_info_capability_bit_set;


/*
 * DESCRIPTION
 *  [INTERNAL]
 *  Data network status.
 *  This enum contains a set of bit masks to test the status of data network.
 * SEE ALSO
 *  srv_nw_info_get_sim_dn_status
 */
typedef enum
{
    SRV_NW_INFO_SIM_DN_STATUS_NONE             = 0x00,   /* No coverage */
    SRV_NW_INFO_SIM_DN_STATUS_COVERAGE         = 0x01,   /* In coverage */
    SRV_NW_INFO_SIM_DN_STATUS_ATTACHED         = 0x02,   /* Attached */
    SRV_NW_INFO_SIM_DN_STATUS_PDP_ACTIVATED    = 0x04,   /* PDP activated */
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    SRV_NW_INFO_SIM_DN_STATUS_UPLINK           = 0x08,   /* DN uplink */
    SRV_NW_INFO_SIM_DN_STATUS_DOWNLINK         = 0x10,   /* DN downlink */
#endif // __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    SRV_NW_INFO_SIM_DN_STATUS_END_OF_ENUM
} srv_nw_info_sim_dn_status_enum;

/*
 * DESCRIPTION
 *  Bit set of srv_nw_info_sim_dn_status_enum. It may combine none,
 *  one or more bits of srv_nw_info_sim_dn_status_enum.
 * SEE ALSO
 *  srv_nw_info_sim_dn_status_enum
 */
typedef U32 srv_nw_info_sim_dn_status_bit_set;


/*
 * DESCRIPTION
 *  Location information.
 */
typedef struct
{
    CHAR plmn[SRV_MAX_PLMN_LEN + 1];    /* Network PLMN */
    U16 lac;                            /* LAC */
    U16 cell_id;                        /* Cell ID. */
} srv_nw_info_location_info_struct;


#ifdef __SRV_NW_INFO_CIPHER_SUPPORT__
/*
 * Cipher status.
 */
typedef enum
{
    SRV_NW_INFO_CIPHER_STATUS_OFF,      /* Off */
    SRV_NW_INFO_CIPHER_STATUS_ON,       /* On */
    SRV_NW_INFO_CIPHER_STATUS_INVALID,  /* Unknown or invalid status */

    SRV_NW_INFO_CIPHER_STATUS_END_OF_ENUM
} srv_nw_info_cipher_status_enum;


/*
 * DESCRIPTION
 *  Cipher information of the network. This information is available only if
 *  __SRV_NW_INFO_CIPHER_SUPPORT__ is enabled.
 */
typedef struct
{
    /* Cipher is supported by network */
    MMI_BOOL is_supported_by_network;

    /* CS domain connection exists */
    MMI_BOOL cs_connection_exists;

    /* CS domain ciphered */
    srv_nw_info_cipher_status_enum cs_status;

    /* PS domain ciphered */
    srv_nw_info_cipher_status_enum ps_status;
} srv_nw_info_cipher_info_struct;
#endif /* __SRV_NW_INFO_CIPHER_SUPPORT__ */


#ifdef __HOMEZONE_SUPPORT__
/*
 * DESCRIPTION
 *  Homezone information
 * SEE ALSO
 *  srv_nw_info_get_homezone_info
 */
typedef struct
{
    /* Phone is in homezone */
    MMI_BOOL is_in_homezone;

    /* Homezone tag string */
    WCHAR tag[SRV_NW_INFO_MAX_HOMEZONE_TAG_LEN + 1];
} srv_nw_info_homezone_info_struct;
#endif /* __HOMEZONE_SUPPORT__ */

/****************************************************************************
 * Global functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_get_service_availability
 * DESCRIPTION
 *  Get the service availability status.
 *  If the network is disabled, the return value is invalid. Please check the
 *  setting before querying.
 * PARAMETERS
 *  sim     : [IN] Which protocol layer of SIM
 * RETURNS
 *  Service availability
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED
 *****************************************************************************/
extern srv_nw_info_service_availability_enum srv_nw_info_get_service_availability(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_get_camp_on_band
 * DESCRIPTION
 *  Get current camp-on band information.
 * PARAMETERS
 *  sim     : [IN] Which protocol layer of SIM
 * RETURNS
 *  Camp-on band information.
 *****************************************************************************/
extern srv_nw_band_enum srv_nw_info_get_camp_on_band(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_sim_is_rejected
 * DESCRIPTION
 *  To query whether the network rejected the SIM(called invalid SIM formally).
 * PARAMETERS
 *  sim     : [IN] Which protocol layer of SIM
 * RETURNS
 *  MMI_TRUE if the SIM has been rejected by network. (Invalid SIM)
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_REGISTER_FAILED
 *****************************************************************************/
extern MMI_BOOL srv_nw_info_sim_is_rejected(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_is_roaming
 * DESCRIPTION
 *  Query if phone is in roaming.
 * PARAMETERS
 *  sim     : [IN] Which protocol layer of SIM
 * RETURNS
 *  MMI_TRUE is it is in roaming.
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED
 *****************************************************************************/
extern MMI_BOOL srv_nw_info_is_roaming(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_get_signal_strength_in_percentage
 * DESCRIPTION
 *  Get the presentage of signal strength.
 *  NOTE that even if limited service, there is still signal strength for
 *  emergency call.
 * PARAMETERS
 *  sim     : [IN] Which protocol layer of SIM
 * RETURNS
 *  Strength value ranges from 0 to 100.
 *****************************************************************************/
extern U8 srv_nw_info_get_signal_strength_in_percentage(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_get_location_info
 * DESCRIPTION
 *  Get location information. Client can use function to get current PLMN,
 *  lac or cell ID.
 *  If the network is disabled by mode setting, the out_info returned is invalid.
 *  Please check the setting before calling this function.
 * PARAMETERS
 *  sim         : [IN] Which protocol layer of SIM
 *  out_info    : [OUT] Output location info.
 * RETURN VALUES
 *  MMI_TRUE    : If out_info is valid.
 *  MMI_FALSE   : If location is not available. For example, on the condition
 *                of SEARCHING, or NO_SERVICE.
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_LOCATION_CHANGED
 *****************************************************************************/
extern MMI_BOOL srv_nw_info_get_location_info(
                    mmi_sim_enum sim,
                    srv_nw_info_location_info_struct *out_info);

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_get_nw_plmn
 * DESCRIPTION
 *  Get network PLMN.
 * PARAMETERS
 *  sim                 : [IN] Which protocol layer of SIM
 *  out_plmn_buffer     : [OUT] PLMN buffer to be filled in. The size shall be
 *                             (SRV_MAX_PLMN_LEN + 1) at minimum.
 *  buffer_size         : [IN] The size of out_plmn_buffer[]. It shall be >=
 *                             (SRV_MAX_PLMN_LEN + 1).
 * RETURN VALUES
 *  MMI_TRUE    : If returned PLMN is valid.
 *  MMI_FALSE   : If PLMN is not available; for example, NO_SERVICE state.
 * SEE ALSO
 *  srv_nw_info_get_location_info, EVT_ID_SRV_NW_INFO_LOCATION_CHANGED
 *****************************************************************************/
extern MMI_BOOL srv_nw_info_get_nw_plmn(mmi_sim_enum sim, CHAR *out_plmn_buffer, U32 buffer_size);

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_cell_supports
 * DESCRIPTION
 *  Query if current cell supports the capability.
 *  Do not assume we can obtain the resource even if the cell supports the
 *  capability you desire. That is, it is possible that a cell declares it
 *  supports EDGE but we can only transfer data by GPRS.
 * PARAMETERS
 *  sim         : [IN] Which protocol layer of SIM
 *  type        : [IN] Protocol capability.
 * RETURNS
 *  MMI_TRUE if supports.
 * SEE ALSO
 *  srv_nw_info_get_protocol, EVT_ID_SRV_NW_INFO_PROTOCOL_CAPABILITY_CHANGED
 *****************************************************************************/
extern MMI_BOOL srv_nw_info_cell_supports(mmi_sim_enum sim, mmi_network_capability_enum type);

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_channel_supports
 * DESCRIPTION
 *  Query if current channel supports the capability. This API is valid only
 *  if PS attached.
 * PARAMETERS
 *  sim         : [IN] Which protocol layer of SIM
 *  type        : [IN] Protocol capability.
 * RETURNS
 *  MMI_TRUE if supports.
 * SEE ALSO
 *  srv_nw_info_get_protocol, EVT_ID_SRV_NW_INFO_PROTOCOL_CAPABILITY_CHANGED
 *****************************************************************************/
extern MMI_BOOL srv_nw_info_channel_supports(mmi_sim_enum sim, mmi_network_capability_enum type);

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_get_protocol
 * DESCRIPTION
 *  Get the protocol of current network.
 * PARAMETERS
 *  sim         : [IN] Which protocol layer of SIM
 * RETURNS
 *  MMI_TRUE if supports.
 * SEE ALSO
 *  srv_nw_info_cell_supports, EVT_ID_SRV_NW_INFO_PROTOCOL_CAPABILITY_CHANGED
 *****************************************************************************/
extern mmi_network_enum srv_nw_info_get_protocol(mmi_sim_enum sim);

#ifdef __SRV_NW_INFO_CIPHER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_get_cipher_info
 * DESCRIPTION
 *  Query the cipher status of current network.
 *  This function is available only if __SRV_NW_INFO_CIPHER_SUPPORT__ is enabled.
 * PARAMETERS
 *  sim         : [IN] Which protocol layer of SIM
 *  out_info    : [OUT] Cipher info
 * RETURNS
 *  MMI_TRUE if out_status is valud.
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_CIPHER_STATUS_CHANGED
 *****************************************************************************/
extern MMI_BOOL srv_nw_info_get_cipher_info(mmi_sim_enum sim, srv_nw_info_cipher_info_struct *out_info);
#endif


#ifdef __HOMEZONE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_get_homezone_info
 * DESCRIPTION
 *  Query if phone is in homezone and get related information.
 *  This function is available only if __HOMEZONE_SUPPORT__ is defined.
 * PARAMETERS
 *  sim         : [IN] Which protocol layer of SIM
 *  out_info    : [OUT] Homezone info
 * RETURNS
 *  MMI_TRUE if it is in homezone.
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_HOMEZONE_STATUS_CHANGED
 *****************************************************************************/
extern MMI_BOOL srv_nw_info_get_homezone_info(mmi_sim_enum sim, srv_nw_info_homezone_info_struct *out_info);
#endif


/****************************************************************************
 * Events
 ****************************************************************************/

/*
 * DESCRIPTION
 *  Event ID of network information events.
 */
typedef enum
{
    /*
     * network status changed.
     * Notify if any change on service availability, location or data network status.
     * This event only notifies basic properties changes. For derived properties,
     * for example, to know roaming status, please call the query function when
     * aware of location changed.
     *
     * Structure:
     *  srv_nw_info_status_changed_evt_struct
     */
    EVT_ID_SRV_NW_INFO_STATUS_CHANGED = SRV_NW_INFO_BASE,

    /*
     * Service availability changed.
     *
     * Structure:
     *  srv_nw_info_service_availability_changed_evt_struct
     * See also:
     *  srv_nw_info_get_service_availability
     */
    EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED,

    /*
     * Protocol capability changed.
     *
     * Structure:
     *  srv_nw_info_protocol_capability_changed_evt_struct
     * See also:
     *  srv_nw_info_get_protocol, srv_nw_info_cell_supports
     */
    EVT_ID_SRV_NW_INFO_PROTOCOL_CAPABILITY_CHANGED,

    /*
     * Location changed.
     *
     * Structure:
     *  srv_nw_info_location_changed_evt_struct
     * See also:
     *  srv_nw_info_get_location_info
     */
    EVT_ID_SRV_NW_INFO_LOCATION_CHANGED,

    /*
     * Register failed. Also known as, invalid SIM.
     * The network does not accept the SIM.
     *
     * Structure:
     *  srv_nw_info_service_register_failed_evt_struct
     * See also:
     *  srv_nw_info_is_successfully_registered
     */
    EVT_ID_SRV_NW_INFO_REGISTER_FAILED,

    /*
     * Roaming status changed.
     * This event will be emitted if location changed cause roaming status changed.
     *
     * Structure:
     *  srv_nw_info_roaming_status_changed_evt_struct
     * See also:
     *  srv_nw_info_is_roaming
     */
    EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED,

    /*
     * [INTERNAL]
     * Data network status changed.
     *
     * Structure:
     *  srv_nw_info_sim_dn_status_changed_evt_struct
     * See also:
     *  srv_nw_info_get_sim_dn_status
     */
    EVT_ID_SRV_NW_INFO_SIM_DN_STATUS_CHANGED,

    /*
     * Singal strength changed.
     * Note that there is also singal strength for limited service. We can still
     * make emergency call in the state.
     *
     * Structure:
     *  srv_nw_info_singal_strength_changed_evt_struct
     */
    EVT_ID_SRV_NW_INFO_SIGNAL_STRENGTH_CHANGED,

    /*
     * Cipher status changed.
     * This event is available only if __SRV_NW_INFO_CIPHER_SUPPORT__ is enabled.
     *
     * Structure:
     *  srv_nw_info_cipher_status_changed_evt_struct
     * See also:
     *  srv_nw_info_get_signal_strength_in_percentage
     */
    EVT_ID_SRV_NW_INFO_CIPHER_STATUS_CHANGED,

    /*
     * Homezone status chaged.
     * This event is available only if __SRV_NW_INFO_HOMEZONE_SUPPORT__ if defined.
     *
     * Structure:
     *  srv_nw_info_homezone_status_changed_evt_struct
     */
    EVT_ID_SRV_NW_INFO_HOMEZONE_STATUS_CHANGED,

    EVT_ID_SRV_NW_INFO_END_OF_ENUM
} srv_nw_info_event_enum;

/*
 * DESCRIPTION
 *  The event structure of network status changed event.
 *  Clients can use this structure to know which type of status changed.
 *  This event is only used for general notifications;, to know the detail,
 *  please query the query functions, or subscribe specified event.
 *  The change of the properties not listed in the structure will not produce
 *  this event.
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Which protocol layer of SIM */
    mmi_sim_enum sim;

    /*
     * Service availability changed.
     *
     * See also:
     *  srv_nw_info_get_service_availability, EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED
     */
    MMI_BOOL service_availability_changed;

    /*
     * Location changed.
     *
     * See also:
     *  srv_nw_info_get_location_info, EVT_ID_SRV_NW_INFO_LOCATION_CHANGED
     */
    MMI_BOOL location_changed;
    
    /*
     * Data network status changed.
     *
     * See also:
     *  srv_nw_info_get_sim_dn_status, EVT_ID_SRV_NW_INFO_SIM_DN_STATUS_CHANGED
     */
    MMI_BOOL dn_status_changed;

    /*
     * Protocol changed.
     *
     * See also:
     *  srv_nw_info_get_protocol, EVT_ID_SRV_NW_INFO_PROTOCOL_CAPABILITY_CHANGED
     */
    MMI_BOOL protocol_changed;

    /*
     * Capability changed.
     *
     * See also:
     *  srv_nw_info_cell_supports, EVT_ID_SRV_NW_INFO_PROTOCOL_CAPABILITY_CHANGED
     */
    MMI_BOOL capability_changed;
} srv_nw_info_status_changed_evt_struct;


/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED.
 *  To describe old availability status and new availability status of data network.
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;       /* Which protocol layer of SIM */
    srv_nw_info_service_availability_enum old_status; /* Old status */
    srv_nw_info_service_availability_enum new_status; /* New status */
} srv_nw_info_service_availability_changed_evt_struct;


/*
 * DESCRIPTION
 *  The event for the protocol of the capability of current network.
 *  This event will not be emitted for the state change from some network to
 *  no service; as the no service may be a temporary state. I.e., the
 *  new_protocol will never be SRV_NW_INFO_PROTOCOL_NONE.
 *  changed.
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_PROTOCOL_CAPABILITY_CHANGED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;       /* Which protocol layer of SIM */
    mmi_network_enum old_protocol;                  /* Old protocol */
    srv_nw_info_capability_bit_set old_cell_cap;    /* Old cell capability bit set */
    srv_nw_info_capability_bit_set old_channel_cap; /* Old channel capability bit set */
    mmi_network_enum new_protocol;                  /* New protocol */
    srv_nw_info_capability_bit_set new_cell_cap;    /* New cell capability bit set */
    srv_nw_info_capability_bit_set new_channel_cap; /* New channel capability bit set */
} srv_nw_info_protocol_capability_changed_evt_struct;


/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_NW_INFO_REGISTER_FAILED.
 *  SIM registration failed; that is, invalid SIM. Once the SIM is determined
 *  invalid, it can not be covered back.
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_REGISTER_FAILED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;       /* Which protocol layer of SIM */
    CHAR nw_plmn[SRV_MAX_PLMN_LEN + 1]; /* Current network PLMN */
} srv_nw_info_register_failed_evt_struct;


/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_NW_INFO_LOCATION_CHANGED.
 *  This struction describes old location and new location.
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_LOCATION_CHANGED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;       /* Which protocol layer of SIM */
    srv_nw_info_location_info_struct old_location;  /* Old location information */
    srv_nw_info_location_info_struct new_location;  /* New location information */
} srv_nw_info_location_changed_evt_struct;


/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED.
 *  Once enter roaming or leave roaming, this event will be emitted.
 *  This structure contains the current status of roaming.
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;           /* Which protocol layer of SIM */
    MMI_BOOL is_roaming_now;    /* MMI_TRUE if it is in roaming */
} srv_nw_info_roaming_status_changed_evt_struct;


/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_NW_INFO_SIGNAL_STRENGTH_CHANGED.
 *  This is used to update the signal strength of network. Note that even
 *  if limited service, there is still strength change event. The signal
 *  can be used for emergency call.
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_SIGNAL_STRENGTH_CHANGED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;   /* Which protocol layer of SIM */
    U8 old_percentage;  /* Old strength value in percentage. */
    U8 new_percentage;  /* New strength value in percentage. */
} srv_nw_info_signal_strength_changed_evt_struct;


#ifdef __SRV_NW_INFO_CIPHER_SUPPORT__
/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_NW_INFO_CIPHER_STATUS_CHANGED.
 *  This event is available only if __SRV_NW_INFO_CIPHER_SUPPORT__ is enabled.
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_CIPHER_STATUS_CHANGED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;   /* Which protocol layer of SIM */
    srv_nw_info_cipher_info_struct status; /* Cipher information of network */
} srv_nw_info_cipher_status_changed_evt_struct;
#endif /* __SRV_NW_INFO_CIPHER_SUPPORT__ */


#ifdef __HOMEZONE_SUPPORT__
/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_NW_INFO_CIPHER_STATUS_CHANGED.
 *  This event is available only if __HOMEZONE_SUPPORT__ if defined.
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_CIPHER_STATUS_CHANGED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;       /* Which protocol layer of SIM */
    srv_nw_info_homezone_info_struct info;
    MMI_BOOL notify_user;           /* Display string or show icon to user */
} srv_nw_info_homezone_status_changed_evt_struct;
#endif /* __HOMEZONE_SUPPORT__ */



/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_get_sim_dn_status
 * DESCRIPTION
 *  [INTERNAL]
 *  Get current data network status.
 * PARAMETERS
 *  sim         : [IN] Which protocol layer of SIM
 * RETURNS
 *  A bit set of srv_nw_info_sim_dn_status_enum.
 * SEE ALSO
 *  srv_nw_info_sim_dn_status_enum
 *****************************************************************************/
extern srv_nw_info_sim_dn_status_bit_set srv_nw_info_get_sim_dn_status(mmi_sim_enum sim);

extern MMI_BOOL srv_nw_info_is_enabled(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_enable_ivsr
 * DESCRIPTION
 *  [INTERNAL]
 *  Enable invalid SIM recovery for better UE. Currently only for EM used.
 * PARAMETERS
 *  enable_flag  : [IN] enable or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_nw_info_enable_ivsr(MMI_BOOL enable_flag);

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_is_need_display_fake_nw_status
 * DESCRIPTION
 *  [INTERNAL]
 *  Check is to display fake nw status.
 * PARAMETERS
 *  sim         : [IN] Which protocol layer of SIM
 * RETURNS
 *  MMI_TRUE: app should display fake nw status
 *  MMI_FALSE: app should display real nw status
 *****************************************************************************/
 #ifdef __OP01_3G__
extern MMI_BOOL srv_nw_info_is_need_display_fake_nw_status(mmi_sim_enum sim);
#endif
/*
 * DESCRIPTION
 *  [INTERNAL]
 *  The event structure of EVT_ID_SRV_NW_INFO_DN_STATUS_CHANGED.
 *  This structure describes the status changes. You can compare old_status
 *  and new_status by AND or XOR operator to know what remains and what
 *  changed, respectively. For example:
 *  <code>
 *  changes = (dn_event->old_status) ^ (dn_event->new_status);
 *  if (changes & SRV_NW_INFO_SIM_DN_STATUS_PDP_ACTIVATED)
 *  {
 *      mmi_display_popup(get_string(STR_ID_MYAPP_PDP_ACTIVATED), MMI_EVENT_INFO);
 *  }
 *  </code>
 * SEE ALSO
 *  EVT_ID_SRV_NW_INFO_DN_STATUS_CHANGED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;       /* Which protocol layer of SIM */
    srv_nw_info_sim_dn_status_bit_set old_status;     /* Old status */
    srv_nw_info_sim_dn_status_bit_set new_status;     /* New status */
} srv_nw_info_sim_dn_status_changed_evt_struct;

/* DOM-NOT_FOR_SDK-END */

#endif /* __SRV_NW_INFO_GPROT_H__ */

