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

/*******************************************************************************
 * Filename:
 * ---------
 * NetSetSrvProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines internal interface of network setup service.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __NETSET_SRV_PROT_H__
#define __NETSET_SRV_PROT_H__

#include "MMIDataType.h"
#include "NetSetSrvGprot.h"
/* auto add by kw_check begin */
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
/* auto add by kw_check end */

typedef enum
{
    SRV_NETSET_OP_GET_PLMN,
	SRV_NETSET_OP_ABORT_PLMN,

    SRV_NETSET_OP_SET_PLMN_AUTO,
    SRV_NETSET_OP_SET_PLMN_MANUAL,
    
    SRV_NETSET_OP_SET_SELECT_MODE,
    
    SRV_NETSET_OP_GET_GPRS_STATUS,
    SRV_NETSET_OP_SET_GPRS_STATUS,
       
    SRV_NETSET_OP_GET_PREF_LIST,
    SRV_NETSET_OP_SET_PREF_LIST,
    
    SRV_NETSET_OP_GET_RAT,
    SRV_NETSET_OP_SET_RAT,

	SRV_NETSET_OP_GET_PCH,
	SRV_NETSET_OP_SET_PCH,
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
    SRV_NETSET_OP_GET_PEER_PCH,
#endif
    SRV_NETSET_OP_GET_HSPA,
    SRV_NETSET_OP_SET_HSPA,
#ifdef __MMI_3G_SWITCH__
    SRV_NETSET_OP_SET_3G_SIM_CAPABILITY,
    SRV_NETSET_OP_GET_3G_SIM_CAPABILITY,
#endif
    SRV_NETSET_OP_NUM    
} srv_netset_op_type_enum;

#define SRV_NETSET_MIN_PLMN_LEN (5)
#define SRV_NETSET_MAX_OPNAME_LENGTH (20)
typedef struct
{
    U32 mccmnc_bcd;
    U16 group_id;
} srv_netset_plmn_group_struct;

extern const U32 plmn_mccmnc_bcd[];
extern const U16 plmn_index[];
extern const srv_netset_plmn_group_struct plmn_group_index[];


/* Protocol Event Handler Functions */
/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_event_handler
 * DESCRIPTION
 *  Set message handler to L4C or L4C_2 module
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  event       :   [IN]    message id of event handler
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_set_event_handler(mmi_sim_enum sim_type, U16 event, PsExtFuncPtr rsp_func);


/*****************************************************************************
 * FUNCTION
 *  srv_netset_clear_event_handler
 * DESCRIPTION
 *  Clear message handler to L4C or L4C_2 module
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  event       :   [IN]    clear message id
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_clear_event_handler(mmi_sim_enum sim_type, U16 event);


extern void srv_netset_init_pref_mode(void);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_3g_capacity_sim
 * DESCRIPTION
 *  Callback function for PLMN selection mode indication
 * PARAMETERS
 *  info        [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_set_3g_capacity_sim(mmi_sim_enum sim_id);

#ifdef __MMI_3G_SWITCH__
/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_3g_sim_capability_req
 * DESCRIPTION
 *  This function is for 3g sim capability request 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_set_3g_sim_capability_req(mmi_sim_enum sim_type, srv_netset_rat_mode_enum rat, mmi_proc_func ptr_func, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_3g_sim_capability_req
 * DESCRIPTION
 *  This function is to get 3g sim capability req 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
extern void srv_netset_get_3g_sim_capability_req(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data);
#endif


#ifndef __MTK_TARGET__
extern void mmi_netset_modis_trace(char* format, ...);

#define NETSET_TRACE0(tr, f)              mmi_netset_modis_trace(f)
#define NETSET_TRACE1(tr, f, a1)          mmi_netset_modis_trace(f, a1)
#define NETSET_TRACE2(tr, f, a1, a2)      mmi_netset_modis_trace(f, a1, a2)
#define NETSET_TRACE3(tr, f, a1, a2, a3)  mmi_netset_modis_trace(f, a1, a2, a3)
#else /* __MTK_TARGET__ */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define NETSET_TRACE0(tr, f)              MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, f)
#define NETSET_TRACE1(tr, f, a1)          MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, f, a1)
#define NETSET_TRACE2(tr, f, a1, a2)      MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, f, a1, a2)
#define NETSET_TRACE3(tr, f, a1, a2, a3)  MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, f, a1, a2, a3)
#endif

#endif /* __MTK_TARGET__ */

#define NETSET_FLAG_IS_SET(b, a)       ((b & (0x1 << a)) >> a)
#define NETSET_SET_FLAG(b, a)          (b |= (0x1 << a))
#define NETSET_UNSET_FLAG(b, a)        (b &= ~(0x1 << a))
#define NETSET_TOGGLE_FLAG(b, a)       (b ^= (0x1 << a))

#endif /* __NETSET_SRV_PROT_H__ */
