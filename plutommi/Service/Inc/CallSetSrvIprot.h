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
 *  CallSetSrvIprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Call setting service internal prototypes, for call setting application use only
 *
 * Author:
 * -------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef SRV_CALLSET_IPROT_H
#define SRV_CALLSET_IPROT_H

/****************************************************************************
* Define
*****************************************************************************/

/****************************************************************************
* Typedef                                                            
*****************************************************************************/

/****************************************************************************
* structure                                                            
*****************************************************************************/

/****************************************************************************
* Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_callset_is_available
 * DESCRIPTION
 *  to check if sim-related call setting service is available
 * PARAMETERS
 *  sim : [IN] target sim
 * RETURNS
 *  MMI_TRUE if the specific sim-related call setting service is available
 *****************************************************************************/
extern MMI_BOOL srv_callset_is_available(mmi_sim_enum sim);


#ifdef __MMI_CALLSET_CALLER_ID__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_is_caller_id_supported
 * DESCRIPTION
 *  to check if caller id service is supported by SIM
 * PARAMETERS
 *  sim : [IN] target sim
 * RETURNS
 *  MMI_TRUE if the specific sim-related call setting service is available
 *****************************************************************************/
extern MMI_BOOL srv_callset_is_caller_id_supported(mmi_sim_enum sim);
#endif /* __MMI_CALLSET_CALLER_ID__ */


#ifdef __MMI_CALLSET_CUG__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_is_cug_supported
 * DESCRIPTION
 *  to check if closed user group service is supported by SIM
 * PARAMETERS
 *  sim : [IN] target sim
 * RETURNS
 *  MMI_TRUE if the specific sim-related call setting service is available
 *****************************************************************************/
extern MMI_BOOL srv_callset_is_cug_supported(mmi_sim_enum sim);
#endif /* __MMI_CALLSET_CUG__ */


/*****************************************************************************
 * FUNCTION
 *  srv_callset_is_line_switch_supported
 * DESCRIPTION
 *  to check if line switch service is supported by SIM
 * PARAMETERS
 *  sim : [IN] target sim
 * RETURNS
 *  MMI_TRUE if the specific sim-related call setting service is available
 *****************************************************************************/
extern MMI_BOOL srv_callset_is_line_switch_supported(mmi_sim_enum sim);

#endif /* SRV_CALLSET_IPROT_H */ 
