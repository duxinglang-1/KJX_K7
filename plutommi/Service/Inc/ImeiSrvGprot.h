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
 *  ImeiSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface of IMEI service
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMI_IMEI_SRV_GPROT_H__
#define __MMI_IMEI_SRV_GPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "kal_general_types.h"
#include "MMIDataType.h"


/****************************************************************************
 * Constant
 ****************************************************************************/

/*
 * DESCRIPTION
 *  Length of IMEI
 */
#define SRV_IMEI_MAX_LEN 15


/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_imei_get_imei
 * DESCRIPTION
 *  Get IMEI. The ascii-encoded IMSI string will be filled in out_buffer.
 * PARAMETERS
 *  sim         : [IN]  Which protocol layer of SIM
 *  out_buffer  : [OUT] IMEI string to be filled in. The space should be 
 *                      (SRV_IMEI_MAX_LEN + 1) chars at least.
 *  buffer_size : [IN]  Size of out_buffer, should be >= (SRV_IMEI_MAX_LEN + 1).
 * RETURNS
 *  MMI_TRUE if IMEI is valid; otherwise IMEI is invalid.
 *****************************************************************************/
extern MMI_BOOL srv_imei_get_imei(mmi_sim_enum sim, CHAR *out_buffer, U32 buffer_size);


/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  srv_imei_is_valid
 * DESCRIPTION
 *  Check whether the IMEI is valid.
 * PARAMETERS
 *  sim         : [IN] Which protocol layer of SIM
 * RETURNS
 *  MMI_TRUE if IMEI is valid; otherwise IMEI is invalid.
 *****************************************************************************/
extern MMI_BOOL srv_imei_is_valid(mmi_sim_enum sim);


/*****************************************************************************
 * FUNCTION
 *  srv_imei_same_config_on_any_pair
 * DESCRIPTION
 *  Check whether there are any 2 IMEIs the same.
 * PARAMETERS
 *  sim         : [IN] Which protocol layer of SIM
 * RETURNS
 *  Same-IMEI pair exists.
 *****************************************************************************/
extern MMI_BOOL srv_imei_same_config_on_any_pair(mmi_sim_enum sim);

/* DOM-NOT_FOR_SDK-END */

#endif /* __MMI_IMEI_SRV_GPROT_H__ */

