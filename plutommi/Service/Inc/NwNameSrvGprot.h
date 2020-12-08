/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  NwNameSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This header defines the external API for the network name service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef NW_NAME_SRV_GPROT_H
#define NW_NAME_SRV_GPROT_H


/****************************************************************************
 * Include
 ****************************************************************************/

#include "mmi_rp_srv_nw_name_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"


/****************************************************************************
 * Define
 ****************************************************************************/

#define SRV_NW_NAME_MAX_STR_LEN         (28)

#define SRV_NW_NAME_MAX_BUF_SIZE        (SRV_NW_NAME_MAX_STR_LEN + 1)


/****************************************************************************
 * Structure
 ****************************************************************************/

typedef struct
{
    /* Line 1 of the service indication string. */
    WCHAR   line1[SRV_NW_NAME_MAX_BUF_SIZE];

    /* Line 2 of the service indication string. */
    WCHAR   line2[SRV_NW_NAME_MAX_BUF_SIZE];
} srv_nw_name_service_indication_struct;


/****************************************************************************
 * Enum
 ****************************************************************************/

/* This enum defines the type of the network name. */
typedef enum
{
    /* Network name from Enhanced Operator Name String (EONS). EONS is defined
       in the EF_PNN and EF_OPL. */
    SRV_NW_NAME_TYPE_EONS,

    /* Network name from NITZ. */
    SRV_NW_NAME_TYPE_NITZ,

    /* Network name from CPHS. */
    SRV_NW_NAME_TYPE_CPHS,

    /* Network name from the handset's ROM. */
    SRV_NW_NAME_TYPE_ROM,

    /* End of enum. */
    SRV_NW_NAME_TYPE_TOTAL
} srv_nw_name_type_enum;


/****************************************************************************
 * Event Structure
 ****************************************************************************/

/* This is the structure for the EVT_ID_SRV_NW_NAME_CHANGED. This event is
   emitted when the network name is changed. */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* SIM associated with this event. */
    mmi_sim_enum sim;
} srv_nw_name_changed_evt_struct;

/* This is the structure for the EVT_ID_SRV_NW_NAME_SIM_CHANGED_BY_SAT. */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* SIM associated with this event. */
    mmi_sim_enum sim;
} srv_nw_name_sat_changed_evt_struct;


/****************************************************************************
 * Function
 ****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_main_evt_hdlr
 * DESCRIPTION
 *  This function is the main event handler of the network name service.
 * PARAMETERS
 *  event           : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern mmi_ret srv_nw_name_main_evt_hdlr(mmi_event_struct *event);

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_is_ready
 * DESCRIPTION
 *  This function checks if the service is ready. Network name service could be
 *  unready when the phone does not camp-on any network or its sub-module,
 *  e.g., EONS, has not been initialized successfully.
 * PARAMETERS
 *  sim             : [IN]      SIM ID
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_nw_name_is_ready(mmi_sim_enum sim);


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_is_rplmn_required
 * DESCRIPTION
 *  This function checks if the Registered PLMN (RPLMN) is required. Please
 *  refer to the 'Display Condition' field in the EF_SPN.
 * PARAMETERS
 *  sim             : [IN]      SIM ID
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_nw_name_is_rplmn_required(mmi_sim_enum sim);


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_is_spn_required
 * DESCRIPTION
 *  This function checks if the Service Provider Name (SPN) is required. Please
 *  refer to the 'Display Condition' field in the EF_SPN.
 * PARAMETERS
 *  sim             : [IN]      SIM ID
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_nw_name_is_spn_required(mmi_sim_enum sim);


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_name
 * DESCRIPTION
 *  This function gets the operator name.
 * PARAMETERS
 *  sim             : [IN]      SIM ID
 *  type            : [IN]      Network name type
 *  name            : [OUT]     Name string
 *  size            : [IN]      Size of the 'name' buffer in WCHAR.
 * RETURNS
 *  String length.
 *****************************************************************************/
extern S32 srv_nw_name_get_name_ex(
    mmi_sim_enum sim,
    srv_nw_name_type_enum type,
    WCHAR *name,
    S32 size);


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_name
 * DESCRIPTION
 *  This function gets the network name. It consider the "Display Condition"
 *  byte in the EF_SPN.
 * PARAMETERS
 *  sim             : [IN]      SIM ID
 *  name            : [OUT]     Name string
 *  size            : [IN]      Size of the 'name' buffer in WCHAR.
 * RETURNS
 *  String length.
 *****************************************************************************/
extern S32 srv_nw_name_get_name(mmi_sim_enum sim, WCHAR *name, S32 size);


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_name
 * DESCRIPTION
 *  This function gets the network name if anyone is present.
 * PARAMETERS
 *  sim             : [IN]      SIM ID
 *  name            : [OUT]     Name string
 *  size            : [IN]      Size of the 'name' buffer in WCHAR.
 * RETURNS
 *  String length.
 *****************************************************************************/
extern S32 srv_nw_name_get_name_if_any(mmi_sim_enum sim, WCHAR *name, S32 size);


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_spn
 * DESCRIPTION
 *  This function gets the Service Provider Name (SPN).
 * PARAMETERS
 *  sim             : [IN]      SIM ID
 *  name            : [OUT]     Name string
 *  size            : [IN]      Size of the 'name' buffer in WCHAR.
 * RETURNS
 *  String length.
 *****************************************************************************/
extern S32 srv_nw_name_get_spn(mmi_sim_enum sim, WCHAR *name, S32 size);


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_service_indication_string
 * DESCRIPTION
 *  This function gets the service indication string of the specified SIM, which
 *  is generally be displayed on the idle screen.
 * PARAMETERS
 *  sim                 : [IN]          SIM ID
 *  service_indication  : [OUT]         srv_nw_name_service_indication_struct
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_nw_name_get_service_indication_string(
    mmi_sim_enum sim,
    srv_nw_name_service_indication_struct *service_indication);


#endif /* NW_NAME_SRV_GPROT_H */

