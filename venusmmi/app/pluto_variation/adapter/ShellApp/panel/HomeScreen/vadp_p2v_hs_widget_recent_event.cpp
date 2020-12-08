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
 *  vadp_v2p_hs_widget_recent_event.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions of recent event widget from 
 *  Venus MMI to PlutoMMI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**********************************************************************
 * Include
 **********************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/* Venus headers: */
#include "vdat_recent_event.h"
#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_string.h"
#include "vadp_p2v_hs_widget_recent_event.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "IdleRecentEventGprot.h"

#ifdef __cplusplus
}
#endif


/*****************************************************************************
 * FUNCTION
 *  convert_event
 * DESCRIPTION
 *  This function converts the recent event type from Pluto to Venus.
 * PARAMETERS
 *  type        : [IN]      The event type in Pluto
 * RETURNS
 *  The event type in Venus.
 *****************************************************************************/
static VdatRecentEvent::EventTypeEnum convert_event(mmi_hs_recent_event_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VdatRecentEvent::EventTypeEnum ret = VdatRecentEvent::EVENT_TOTAL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_HS_RECENT_EVENT_MISSED_CALL:
            ret = VdatRecentEvent::EVENT_CALL;
            break;
            
    #ifdef __MMI_DUAL_SIM_MASTER__
        case MMI_HS_RECENT_EVENT_MISSED_CALL2:
            ret = VdatRecentEvent::EVENT_CALL2;
            break;
    #endif

        case MMI_HS_RECENT_EVENT_SMS:
            ret = VdatRecentEvent::EVENT_SMS;
            break;
            
    #ifdef __MMI_MMS_2__
        case MMI_HS_RECENT_EVENT_MMS:
            ret = VdatRecentEvent::EVENT_MMS;
            break;
    #endif /* __MMI_MMS_2__ */

        default:
            //VFX_ASSERT(0);
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_widget_recent_event_updated
 * DESCRIPTION
 *  This function updates the recent events of the specified type.
 * PARAMETERS
 *  type        : [IN]      The event type in Pluto
 *  is_read     : [IN]      The message is read or not
 *  subject     : [IN]      Subject of the event
 *  time        : [IN]      Received time of the event
 *  user_data   : [IN]      User data associated with the event
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_widget_recent_event_changed(
        mmi_hs_recent_event_enum type,
        mmi_hs_key_cbf_t cbf,
        S32 num,
        MMI_BOOL *is_read,
        PS8 *subject,
        MYTIME **time,
        void **user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VdatRecentEvent *recentEventSrv;
    VdatRecentEvent::EventStruct event[MMI_HS_MAX_RECENT_EVENT_NUM];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recentEventSrv = VFX_OBJ_GET_INSTANCE(VdatRecentEvent);

    recentEventSrv->processEventCleared(convert_event(type));
    recentEventSrv->processEventChanged(convert_event(type), cbf);

    for (VfxS32 i = 0; i < num; i++)
    {
        event[i].type = convert_event(type);
        event[i].is_read = is_read[i]? VFX_TRUE: VFX_FALSE;
        event[i].subject = VFX_WSTR_MEM((VfxWChar *)subject[i]);
        event[i].time.setDate(time[i]->nYear, time[i]->nMonth, time[i]->nDay);
        event[i].time.setTime(time[i]->nHour, time[i]->nMin, time[i]->nSec);
        event[i].user_data = user_data[i];
    }

    recentEventSrv->processEventChanged(num, event);
}

#endif /* __MMI_VUI_HOMESCREEN__ */

