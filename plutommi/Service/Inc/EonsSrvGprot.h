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
 *  EonsSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This header defines the external API for the Enhanced Operator Name String
 *  (EONS) service.
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

#ifndef EONS_SRV_GPROT_H
#define EONS_SRV_GPROT_H

#include "MMI_features.h"

#if defined(__MMI_EONS_SRV__)

/****************************************************************************
 * Define
 ****************************************************************************/

#define SRV_EONS_MAX_STR_LEN            (28)

#define SRV_EONS_MAX_BUF_SIZE           (SRV_EONS_MAX_STR_LEN + 1)

#define SRV_EONS_MAX_PLMN_INFO_BUF_SIZE (255)


/****************************************************************************
 * Include
 ****************************************************************************/
#include "mmi_rp_srv_eons_def.h"

// auto add by kw_check begin
#include "MMIDataType.h"
#include "kal_general_types.h"
// auto add by kw_check end 

/****************************************************************************
 * Event Structure
 ****************************************************************************/

/* This is the structure for the EVT_ID_SRV_EONS_UPDATED. */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* SIM associated with this event. */
    mmi_sim_enum sim;
} srv_eons_updated_evt_struct;


/****************************************************************************
 * Structure
 ****************************************************************************/

/* This defines the operator name returned by the EONS service. */
typedef struct
{
    /* SIM associated with the name. */
    mmi_sim_enum sim;
    
    /* The full name of the operator. */
    WCHAR full_name[SRV_EONS_MAX_BUF_SIZE];

    /* The short name of the operator. */
    WCHAR short_name[SRV_EONS_MAX_BUF_SIZE];

    /* The PLMN additional information. */
    WCHAR plmn_info[SRV_EONS_MAX_PLMN_INFO_BUF_SIZE];	
} srv_eons_name_struct;


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_eons_get_name_cb
 * DESCRIPTION
 *  This callback is called when the name is obtained. Please copy the operator
 *  name to your string buffer.
 * PARAMETERS
 *  sim             : [IN]      SIM ID
 *  name            : [IN]      Operator name
 *  user_data       : [IN]      User data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_eons_get_name_cb)(
                const srv_eons_name_struct *name, 
                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_eons_is_ready
 * DESCRIPTION
 *  This function checks if the EONS service is ready.
 * PARAMETERS
 *  sim             : [IN]      SIM ID
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_eons_is_ready(mmi_sim_enum sim);


/*****************************************************************************
 * FUNCTION
 *  srv_eons_is_present
 * DESCRIPTION
 *  This function checks if the (PLMN, LAC) is present in the EF_OPL.
 * PARAMETERS
 *  sim             : [IN]      SIM ID
 *  plmn            : [IN]      PLMN. Should be NULL terminated.
 *  lac             : [IN]      LAC
 * RETURNS
 *  If not found, return 0. Otherwise, return the EF_PNN record index.
 *****************************************************************************/
extern U8 srv_eons_is_present(mmi_sim_enum sim, const CHAR *plmn, U16 lac);


/*****************************************************************************
 * FUNCTION
 *  srv_eons_get_name
 * DESCRIPTION
 *  This function gets the name assoicated with this (PLMN, LAC) couple.
 * PARAMETERS
 *  sim             : [IN]      SIM ID
 *  plmn            : [IN]      PLMN. Should be NULL terminated.
 *  lac             : [IN]      LAC
 *  callback        : [IN]      Callback function
 *  user_data       : [IN]      User data
 * RETURNS
 *  If the name is present, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_eons_get_name(
                    mmi_sim_enum sim,
                    const CHAR *plmn, 
                    U16 lac, 
                    srv_eons_get_name_cb callback, 
                    void *user_data);


/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  srv_eons_default_network_name_is_needed
 * DESCRIPTION
 *  This function checks whether default network name is needed
 * PARAMETERS
 *  sim             : [IN]      SIM ID
 * RETURNS
 *  If default network name is needed, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_eons_default_network_name_is_needed(mmi_sim_enum sim);


/*****************************************************************************
 * FUNCTION
 *  srv_eons_get_default_network_name
 * DESCRIPTION
 *  This function gets the network name from the first record of EF PNN
 * PARAMETERS
 *  sim             : [IN]      SIM ID
 *  callback        : [IN]      Callback function
 *  user_data       : [IN]      User data
 * RETURNS
 *  If the default name is present, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_eons_get_default_network_name(
     mmi_sim_enum sim,
     srv_eons_get_name_cb callback,
     void *user_data);

/* DOM-NOT_FOR_SDK-END */

#endif /* defined(__MMI_EONS_SRV__) */
#endif /* EONS_SRV_GPROT_H */
