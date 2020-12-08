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
 *    mmi_ap_dcm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  mmi ap DCM load/unload
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================

*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "GlobalResDef.h"
#include "MMI_ap_dcm_config.h"
#include "kal_general_types.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_events_gprot.h"


typedef struct
{
    MMI_EVT_PARAM_HEADER    
    S32 region_id; /* ap's DCM region ID in dcmgr.h */
} mmi_ap_dcm_evt_struct;


/*****************************************************************************
 * FUNCTION
 *  mmi_ap_send_dcm_load_evt
 * DESCRIPTION
 *  send DCM load ap DCM region evt
 * PARAMETERS
 *  region_id: ap DCM region ID 
 * RETURNS
 * void
 *****************************************************************************/
void mmi_ap_send_dcm_load_evt(S32 region_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ap_dcm_evt_struct dcm_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_init_event((mmi_event_struct *)&dcm_evt, EVT_ID_MMI_AP_DCM_LOAD, sizeof(*(&dcm_evt)));
    dcm_evt.region_id = region_id;

    mmi_frm_cb_emit_event((mmi_event_struct *)(&dcm_evt));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ap_send_dcm_unload_evt
 * DESCRIPTION
 *  send DCM unload ap DCM region evt
 * PARAMETERS
 *  region_id: ap DCM region ID 
 * RETURNS
 * void
 *****************************************************************************/

void mmi_ap_send_dcm_unload_evt(S32 region_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ap_dcm_evt_struct dcm_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_init_event((mmi_event_struct *)&dcm_evt, EVT_ID_MMI_AP_DCM_UNLOAD, sizeof(*(&dcm_evt)));
    dcm_evt.region_id = region_id;

    mmi_frm_cb_emit_event((mmi_event_struct *)(&dcm_evt));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ap_post_dcm_unload_evt
 * DESCRIPTION
 *  post DCM unload ap DCM region evt
 * PARAMETERS
 *  region_id: ap DCM region ID 
 * RETURNS
 * void
 *****************************************************************************/

void mmi_ap_post_dcm_unload_evt(S32 region_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ap_dcm_evt_struct dcm_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_init_event((mmi_event_struct *)&dcm_evt, EVT_ID_MMI_AP_DCM_UNLOAD, sizeof(*(&dcm_evt)));
    dcm_evt.region_id = region_id;

    mmi_frm_cb_emit_post_event((mmi_event_struct *)(&dcm_evt));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ap_dcm_evt_hdlr
 * DESCRIPTION
 *  This function is ap DCM load/unload event handler
 *  
 * PARAMETERS
 *  mmi_event_struct    [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/ 

#if defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
mmi_ret mmi_ap_dcm_evt_hdlr(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ap_dcm_evt_struct *dcm_evt = (mmi_ap_dcm_evt_struct *)evt;
    S32 region_id = dcm_evt->region_id;
    U16 evt_id = dcm_evt->evt_id; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (evt_id == EVT_ID_MMI_AP_DCM_LOAD)
    {
        if(DCM_Isloaded(region_id)== KAL_FALSE)
        {
        #ifdef __MMI_AP_DCM_DEBUG__ 
            kal_prompt_trace(MOD_MMI_FW, "[DCM]MMI Load ap region ID = %d", region_id);
        #endif            
            DCM_Load(region_id, 0,0);
        }
    }
    else if (evt_id == EVT_ID_MMI_AP_DCM_UNLOAD)
    {
        if(DCM_Isloaded(region_id)== KAL_TRUE)
        {
        #ifdef __MMI_AP_DCM_DEBUG__
            kal_prompt_trace(MOD_MMI_FW, "[DCM]MMI Unload ap region ID = %d", region_id);
        #endif            
            DCM_Unload(region_id);
        }
    }    
    return MMI_RET_OK;
}

#else
mmi_ret mmi_ap_dcm_evt_hdlr(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ap_dcm_evt_struct *dcm_evt = (mmi_ap_dcm_evt_struct *)evt;
    S32 region_id = dcm_evt->region_id;
    U16 evt_id = dcm_evt->evt_id; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (evt_id == EVT_ID_MMI_AP_DCM_LOAD)
    {
       
    }
    else if (evt_id == EVT_ID_MMI_AP_DCM_UNLOAD)
    {
        
    }    
    return MMI_RET_OK;
}
#endif

