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
 *  NwUsabSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Service to wrap network usability information.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SRV_NW_USAB_GPROT_H__
#define __SRV_NW_USAB_GPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMIDataType.h"
/* auto add by kw_check begin */
#include "mmi_res_range_def.h"
/* auto add by kw_check end */

/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_nw_usab_is_usable
 * DESCRIPTION
 *  Query whether the SIM is usable for network.
 *  That is, the SIM is available and mode switching enabled the network
 *  of the SIM.
 *  Note that a SIM is available does not implies the network is in full
 *  service. This function only determines phone status but does not
 *  check external status.
 * PARAMETERS
 *  sim     [IN] SIM ID
 * RETURNS
 *  The usability of the network corresponding to the SIM.
 * SEE ALSO
 *  srv_nw_info_get_service_availability
 *****************************************************************************/
extern MMI_BOOL srv_nw_usab_is_usable(mmi_sim_enum sim);


/*****************************************************************************
 * FUNCTION
 *  srv_nw_usab_get_one_usable_sim
 * DESCRIPTION
 *  Get one SIM which is usable for network.
 * PARAMETERS
 *  void
 * RETURNS
 *  One network-usable SIM ID.
 *  If none, returns MMI_SIM_NONE.
 * SEE ALSO
 *  srv_nw_usab_is_usable
 *****************************************************************************/
extern mmi_sim_enum srv_nw_usab_get_one_usable_sim(void);


/*****************************************************************************
 * FUNCTION
 *  srv_nw_usab_any_sim_is_usable
 * DESCRIPTION
 *  Query whether there is any SIM is usable for network.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if some SIM is usable for network.
 *****************************************************************************/
#define srv_nw_usab_any_sim_is_usable() \
    (srv_nw_usab_get_one_usable_sim() != MMI_SIM_NONE)


/*****************************************************************************
 * FUNCTION
 *  srv_nw_usab_is_any_network_available
 * DESCRIPTION
 *  Query whether there is any network is available
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if any network (no matter GSM or WLAN) is available
 *****************************************************************************/
extern MMI_BOOL srv_nw_usab_is_any_network_available(void);


/*
 * DESCRIPTION
 *  Event ID of network usability events.
 */
typedef enum
{
    /*
     * Network usability changed.
     *
     * Structure:
     *  srv_nw_info_status_changed_evt_struct
     */
    EVT_ID_SRV_NW_USAB_CHANGED = SRV_NW_USAB_BASE,

    EVT_ID_SRV_NW_USAB_END_OF_ENUM
} srv_nw_usab_event_enum;


/*
 * DESCRIPTION
 *  Structure of EVT_ID_SRV_NW_USAB_CHANGED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;       /* Which network-usability changed */
    MMI_BOOL is_usable;     /* New usability status */
} srv_nw_usab_changed_evt_struct;


#endif /* __SRV_NW_USAB_GPROT_H__ */
