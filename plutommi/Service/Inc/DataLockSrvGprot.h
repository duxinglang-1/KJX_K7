/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  DataLockSrvGprot.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DATA_LOCK_SRV_GPROT_H__
#define __DATA_LOCK_SRV_GPROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_DATA_LOCK__
#include "MMIDataType.h"

typedef enum
{
    EVT_ID_SRV_DATA_LOCK_UPDATE = SRV_DATALOCK_BASE,

    EVT_ID_DATA_LOCK_TOTAL
} srv_data_lock_evt_id_enum;

/***************************************************************************** 
 * Functions
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_data_lock_get_setting
 * DESCRIPTION
 *  Get current setting of data lock 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern MMI_BOOL srv_data_lock_get_setting(void);

/*****************************************************************************
 * FUNCTION
 *  srv_data_lock_set_setting
 * DESCRIPTION
 *  Set data lock
 * PARAMETERS
 *  data    :   [IN]    MMI_TRUE: allow data service; MMI_FALSE: Disallow data service
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern void srv_data_lock_set_setting(MMI_BOOL data);

//#ifdef __COSMOS_MMI_PACKAGE__
/* Network roaming feature is only supported on COSMOS */
/*****************************************************************************
 * FUNCTION
 *  srv_data_lock_network_roaming_get_setting
 * DESCRIPTION
 *  Get current setting of network roaming
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern MMI_BOOL srv_data_lock_network_roaming_get_setting(void);

/*****************************************************************************
 * FUNCTION
 *  srv_data_lock_network_roaming_set_setting
 * DESCRIPTION
 *  Set network roaming state
 * PARAMETERS
 *  data    :   [IN]    MMI_TRUE: allow network roaming MMI_FALSE: disallow network roaming
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern void srv_data_lock_network_roaming_set_setting(MMI_BOOL data);
//#endif /* __COSMOS_MMI_PACKAGE__ */
#endif /* __MMI_DATA_LOCK__ */
#endif /* __DATA_LOCK_SRV_GPROT_H__ */
 
