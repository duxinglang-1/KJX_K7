/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   hdi_networkAccount.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Integration of network account APIs
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef Q03C_IND_MOD_ARCH_SUPPORT
#include "kal_public_api.h"

/* Header files for ABM utility functions */
#include "kal_public_defs.h"
#include "stack_ltlcom.h"
#include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "l4c2abm_struct.h"
#include "abm_soc_enums.h"

#include "msf_def.h"
#include "msf_int.h"
#include "cbm_api.h"
#include "Custom_data_account.h"

/**********************************************************************
 * HDI Network Account
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_networkAccountGetBearer
 * DESCRIPTION
 *  This function returns the bearer type according to the network account ID.
 * PARAMETERS
 *  networkAccountId        [IN]        
 * RETURNS
 *  Bearer type of the network account ID
 *****************************************************************************/
int gmms_HDIa_networkAccountGetBearer(MSF_INT32 networkAccountId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_bearer_enum bearer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CBM_OK == cbm_get_bearer_type((kal_uint32) networkAccountId, &bearer))
    {
        switch (bearer)
        {
            case CBM_BEARER_GSM_CSD:
                return HDI_SOCKET_BEARER_GSM_CSD;
            case CBM_BEARER_GSM_GPRS:
                return HDI_SOCKET_BEARER_GSM_GPRS;
            case CBM_BEARER_WIFI:
                return HDI_SOCKET_BEARER_WIFI;
            default:
                return HDI_SOCKET_BEARER_IP_ANY;
        }
    }
    return HDI_SOCKET_BEARER_IP_ANY;
}



#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "kal_public_api.h"        /* Basic data type */
#include "kal_public_defs.h"
#include "stack_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"
#include "l4c2abm_struct.h"
#include "abm_soc_enums.h"

#include "msf_int.h"
#include "nvram_user_defs.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"


#include "msf_chrs.h"
#include "mcd_l4_common.h"
#include "l4c2phb_enums.h"
#include <stdio.h>

#include "widget_extension.h"

#include "cbm_api.h"
#include "Custom_data_account.h"
kal_uint8 abm2hdi_enum_table[] = {HDI_SOCKET_BEARER_IP_ANY, HDI_SOCKET_BEARER_GSM_CSD, HDI_SOCKET_BEARER_GSM_GPRS, HDI_SOCKET_BEARER_WIFI};


/*****************************************************************************
 * FUNCTION
 *  HDIa_networkAccountGetBearer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  networkAccountID        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_networkAccountGetBearer(MSF_INT32 networkAccountID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_bearer_enum bearer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CBM_OK == cbm_get_bearer_type((kal_uint32) networkAccountID, &bearer))
    {
        switch (bearer)
    {
            case CBM_BEARER_GSM_CSD:
                return HDI_SOCKET_BEARER_GSM_CSD;
            case CBM_BEARER_GSM_GPRS:
                return HDI_SOCKET_BEARER_GSM_GPRS;
            case CBM_BEARER_WIFI:
                return HDI_SOCKET_BEARER_WIFI;
            default:
                return HDI_SOCKET_BEARER_IP_ANY;
    }
    }
    return HDI_SOCKET_BEARER_IP_ANY;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_networkAccountGetName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  networkAccountID        [IN]        
 *  buf                     [?]         
 *  buflen                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_networkAccountGetName(MSF_INT32 networkAccountID, char *buf, int buflen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_networkAccountGetId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bearer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MSF_INT32 HDIa_networkAccountGetId(int bearer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 nw_acc_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern kal_int8 cbm_get_valid_account_id( cbm_bearer_enum bearer_type, kal_uint32* account_id);

    if (HDI_SOCKET_BEARER_GSM_CSD == bearer)
    {
        if (CBM_OK != cbm_get_valid_account_id(CBM_BEARER_GSM_CSD, &nw_acc_id))
        {
            return -1;
        }
    }
    else if (HDI_SOCKET_BEARER_GSM_GPRS == bearer)
    {
        if (CBM_OK !=  cbm_get_valid_account_id(CBM_BEARER_GSM_GPRS, &nw_acc_id))
        {
            return -1;
        }
    }
    else if(HDI_SOCKET_BEARER_WIFI == bearer)
    {
        if(CBM_OK != cbm_get_valid_account_id(CBM_BEARER_WIFI,  &nw_acc_id))
        {
             return -1;
        }
    }
    else
    {
        return -1;
    }

    return (MSF_INT32)nw_acc_id;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_networkAccountGetFirst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MSF_INT32 HDIa_networkAccountGetFirst()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ABM_MIN_NWACC_ID;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_networkAccountGetNext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  networkAccountID        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MSF_INT32 HDIa_networkAccountGetNext(MSF_INT32 networkAccountID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* get the total bearer number */
    extern kal_uint8 custom_get_total_bearer_num(void);

    /* custom_get_total_bearer_num()-1 is for one invisible GPRS profile ID (SAT use only) */
    if (ABM_MIN_NWACC_ID <= networkAccountID)// && custom_get_total_bearer_num() - 1 > networkAccountID + 1)
    {
        return networkAccountID + 1;
    }
    else
    {
        return -1;
    }
}
#endif/*Q03C_IND_MOD_ARCH_SUPPORT*/

