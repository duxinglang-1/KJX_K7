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
 * Vapp_cbs_iprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines constant, enum value, structure, and function prototype for world clock.
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
**********************************************************************************/

#ifndef __VAPP_CBS_IPROT_H__
#define __VAPP_CBS_IPROT_H__
#include "mmi_features.h"

#ifndef __cplusplus
#error "this header file can be used in C++ only."
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_cbs_def.h"

#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "vadp_app_trc.h"
#include "vadp_app_trc_gen.h"

extern "C"
{
#include "GlobalResDef.h"
#include "cbssrvgprot.h"
}


#define VAPP_CBS_TRC_GROUP VFX_INFO2

typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_sms_sim_enum sim_id;
    U16 msg_id;
} VappCbsMSgViewedStruct;

enum VappCbsConfEnum
{
	CBS_FAILURE_CONF,
	CBS_WARNING_CONF,
	CBS_INFO_CONF,
	CBS_CNF_TOTAL
};
enum VappCbsDelStrEnum
{
	CBS_CHANNEL_STR,
	CBS_MSG_STR,
	CBS_STR_TOTAL
};


/***************************************************************************** 
 * Define
 *****************************************************************************/
enum VappCbsSimEnum
{
    CB_SIM_1 = 0,
#if (MMI_MAX_SIM_NUM >= 2)
    CB_SIM_2,
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    CB_SIM_3,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
	CB_SIM_4,
#endif

    CB_SIM_ALL,
    CB_SIM_INVALID = 0xFF
};

enum
{
    CBS_DATATIME_BUFF_LEN = 40
};


#define VAPP_CB_INVALID_CHANNEL_ID 0xFFFF
#define VAPP_CB_INVALID_MSG_ID  SRV_CBS_INVALID_MSG_ID
#define VAPP_CB_INVALID_LANG_ID SRV_CBS_LANG_INVALID

#define VAPP_CBS_CHNL_NUMBER_DISP_LEN        5       /* 0 - 0xFFFF (0 - 65535) */
#define VAPP_CB_CHNL_PAGE 'CHNL'


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef srv_sms_callback_struct cbsCallbackStruct;
typedef MMI_BOOL SRV_BOOL ;
#define SRV_TRUE MMI_TRUE 
#define SRV_FALSE MMI_FALSE 
typedef srv_sms_sim_enum SRV_SIM_ENUM;

/*****************************************************************************
 * Class Xyz
 ****************************************************************************/

/*****************************************************************************
 * Template Abc
 ****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
//extern VappCbsSimEnum vappCbsTransfer2UISIM(srv_sms_sim_enum sim);
//extern srv_sms_sim_enum vappCbsTransfer2SrvSIM(VappCbsSimEnum sim);
extern VcpConfirmPopup *vapp_cbs_show_error_confirm(VfxObject *parent, VfxWString string, VappCbsConfEnum type);
extern void vapp_cbs_delete_confirm_str(VfxWString& ask, VfxU32 del_cnt, VappCbsDelStrEnum type);

#endif /* __VAPP_CBS_IPROT_H__ */
