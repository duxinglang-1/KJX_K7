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
 * NetSetSrvMsgQueue.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is message queue of network setup
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"


/***************************************************************************** 
* Include
*****************************************************************************/
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stdarg.h"
/* auto add by kw_check end */

/***************************************************************************** 
* External Variable
*****************************************************************************/
#ifndef __MTK_TARGET__
static U8 g_netset_modis_trace_on = 0;
#endif /* __MTK_TARGET__ */

/***************************************************************************** 
* Global Variable
*****************************************************************************/


/***************************************************************************** 
* Local Function
*****************************************************************************/


/***************************************************************************** 
* External Function
*****************************************************************************/


/* Network Setup Event Handler Management */
/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_event_handler
 * DESCRIPTION
 *  This function is to set protocol event handler
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_set_event_handler(mmi_sim_enum sim_type, U16 event, PsExtFuncPtr func)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_type)
    {
        case MMI_SIM1:
        //#ifdef __MMI_DUAL_SIM_MASTER__
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2: 
    #if (MMI_MAX_SIM_NUM >= 3)        
        case MMI_SIM3: //added
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4: //added
    #endif
    #endif
    #endif
            SetProtocolEventHandler(func, event);
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_clear_event_handler
 * DESCRIPTION
 *  This function is to clear protocol event handler
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_clear_event_handler(mmi_sim_enum sim_type, U16 event)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_type)
    {
        case MMI_SIM1:
    //#ifdef __MMI_DUAL_SIM_MASTER__
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2: 
    #if (MMI_MAX_SIM_NUM >= 3)        
        case MMI_SIM3: //added
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4: //added
    #endif
    #endif
    #endif
            ClearProtocolEventHandler(event);
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

}

/* Network Setup Message Queue Management */

#ifndef __MTK_TARGET__
void mmi_netset_enable_modis_trace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_netset_modis_trace_on = 1;
}

void mmi_netset_modis_trace(char* format, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list argptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!g_netset_modis_trace_on)
        return;

    va_start(argptr, format);
    vprintf(format, argptr);
    va_end(argptr);
}
#endif /* __MTK_TARGET__ */
