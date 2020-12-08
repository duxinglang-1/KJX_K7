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
 *  NITZSrvGprot.h
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
#ifndef __NITZ_SRV_GPROT_H__
#define __NITZ_SRV_GPROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_NITZ__
#include "MMIDataType.h"
#include "Custom_mmi_Default_value.h"
#include "Ps_public_enum.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    EVT_ID_SRV_NITZ_UPDATE = SRV_NITZ_BASE,

    /* Only for internal used */
    EVT_ID_SRV_NITZ_UPDATE_REQ,
        
    EVT_ID_SRV_NITZ_END,
    
    EVT_ID_NITZ_NW_NAME_UPDATE_NOTIFY,
    
} srv_nitz_evt_id_enum;

typedef enum
{
    SRV_NITZ_UPDATE_DONE,
//    SRV_NITZ_UPDATE_WAIT_FOR_CONFIRM,
    SRV_NITZ_UPDATE_REJECT,

    SRV_NITZ_UPDATE_STATUS_ENUM
} srv_nitz_update_status_enum;

/* data structure for event EVT_ID_SRV_NITZ_UPDATE */
typedef struct
{
    MMI_EVT_PARAM_HEADER
	MYTIME time;
	mmi_sim_enum sim_id;
	U8 time_zone_p;
	FLOAT time_zone;
	U8 dst_p;
}srv_nitz_update_event_struct;

typedef struct
{
    S16 nitz_timezone;	/* current time zone and save this value in NVRAM */
    MYTIME nitz_time;	/* date and time information in NITZ message */
	U32 recv_tick_count;	/* tick count of receive NITZ message */
    U8 operator_full_name[MAX_NW_LEN * ENCODING_LENGTH];		/* operator full name in NITZ message */
    U8 operator_short_name[MAX_NW_LEN * ENCODING_LENGTH];	/* operator short name in NITZ message */
    U8 add_ci;			/* receive from NITZ message */
    U8 update_time;
#ifdef __MMI_NITZ_TZ_SUPPORT__
    U8 update_local_time_zone;		/* update time zone information to mobile or not */
    U8 update_day_light_saving;			/* update NITZ day light saving information to mobile or not */
    U8 day_light_saving;
#endif
    U8 nitz_plmn[MAX_PLMN_LEN + 1];
	mmi_sim_enum sim_id;
} srv_nitz_context_struct;

/* data structure for event EVT_ID_SRV_NITZ_UPDATE_REQ */
typedef struct
{
    MMI_EVT_PARAM_HEADER
	srv_nitz_context_struct nitz_data;
}srv_nitz_update_req_event_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
	mmi_sim_enum sim_id;
}srv_nitz_nw_name_update_event_struct;

/*****************************************************************************
 * FUNCTION
 *  srv_nitz_update_callback
 * DESCRIPTION
 *  Call this callback when NITZ update is finished 
 * PARAMETERS
 *  update_status   [IN]    status
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_nitz_update_callback(srv_nitz_update_status_enum update_status);

/*****************************************************************************
 * FUNCTION
 *  srv_nitz_enable_update
 * DESCRIPTION
 *  Set the NITZ update enable status, should be called when NITZ setting is 
 *  updated  and after boot up 
 * PARAMETERS
 *  is_enable   [IN]    MMI_TRUE enable update, MMI_FALSE disable update
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_nitz_enable_update(MMI_BOOL is_enable);

/*****************************************************************************
 * FUNCTION
 *  srv_nitz_get_current_nw_name
 * DESCRIPTION
 *  Get the current network name 
 * PARAMETERS
 *  sim             [IN]    which SIM the network name need to get
 *  plmn_buf        [OUT]   PLMN output buffer
 *  nw_name_buf     [OUT]   network name output buffer
 *  nw_name_buf_len [IN]    network name output buffer length
 *  add_ci          [OUT]   ADD CI
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_nitz_get_current_nw_name(mmi_sim_enum sim, CHAR* plmn_buf, WCHAR* nw_name_buf, U8 nw_name_buf_len, MMI_BOOL* add_ci);

/*****************************************************************************
 * FUNCTION
 *  srv_nitz_set_current_nw_name
 * DESCRIPTION
 *  Update current network name, should only be called by NITZ APP 
 * PARAMETERS
 *  sim     [IN]    which SIM to be updated
 *  data    [IN]    update data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_nitz_set_current_nw_name(mmi_sim_enum sim, const nitz_nw_name_struct *data);
#endif /* __MMI_NITZ__ */
#endif /* __NITZ_SRV_GPROT_H__ */
 
