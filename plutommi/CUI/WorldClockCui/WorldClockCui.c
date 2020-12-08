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
 *   WorldClockCui.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Worldclock Common UI header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "MMI_include.h"


/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_WORLD_CLOCK__) || defined(__MMI_VRE_WORLD_CLOCK__)

#include "WorldClockCui.h"
#include "WorldClock.h"
#include "WorldClockCuiGprot.h"
#include "commonscreens.h"


/*******************************************************************************
 * Structure Define
 *******************************************************************************/

/*******************************************************************************
 * Macro Define
 *******************************************************************************/

/*******************************************************************************
 *  Local function
 *******************************************************************************/
static mmi_ret cui_worldclock_proc(mmi_event_struct *evt);

/*******************************************************************************
 * Global Function
 *******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *   cui_worldclock_launch
 * DESCRIPTION
 *   world clock launch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_worldclock_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    EntryWcBrowseCity();
}


/*****************************************************************************
 * FUNCTION
 *   cui_worldclock_create
 * DESCRIPTION
 *   world clock cui group create
 * PARAMETERS
 *  parent_gid  : [IN] parent group ID
 * RETURNS
 *  world clock cui group ID
 * RETURN VALUES
 *  world clock cui group ID
 *****************************************************************************/
mmi_id cui_worldclock_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id grp_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_id = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, cui_worldclock_proc, NULL);    

    return grp_id;
}


/*****************************************************************************
 * FUNCTION
 *   cui_worldclock_set_current_city
 * DESCRIPTION
 *   world clock cui group create
 * PARAMETERS
 *  city_index  : [IN] parent group ID
 * RETURNS
 *  void
*****************************************************************************/
void cui_worldclock_set_current_city(U16 city_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WcSetCityIndex(city_index);
}


/*****************************************************************************
 * FUNCTION
 *   cui_worldclock_set_timezone
 * DESCRIPTION
 *   camera cui group create
 * PARAMETERS
 *  city_index  : [IN] parent group ID
 * RETURNS
 *  camera cui group ID
 * RETURN VALUES
 *  camera cui group ID
*****************************************************************************/
void cui_worldclock_set_timezone(U16 city_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************              
 * FUNCTION
 *   cui_worldclock_run
 * DESCRIPTION
 *   world clock cui run
 * PARAMETERS
 *  cui_gid : [IN] world clock cui group ID
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_worldclock_run(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cui_gid != GRP_ID_INVALID);
    
    mmi_frm_group_enter(cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_wc_cntx.grp_id = cui_gid;
    g_wc_cntx.sel_scrn = MMI_TRUE;
    
    mmi_wc_entry_city_scrn();
}


/*****************************************************************************              
 * FUNCTION
 *   cui_worldclock_close
 * DESCRIPTION
 *   world clock cui close
 * PARAMETERS
 *  cui_gid : [IN] world clock cui group ID
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_worldclock_close(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(cui_gid);
}


/*****************************************************************************              
 * FUNCTION
 *  cui_worldclock_proc
 * DESCRIPTION
 *  create cui menu
 * PARAMETERS
 *  evt            : [IN]     Receives event from framework 
 * RETURNS
 *  mmi_ret
 * RETURN VALUES
 *  error code
********************************************************************************/
static mmi_ret cui_worldclock_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    cui_worldclock_event_struct evt_for_parent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
            break;
            
        case EVT_ID_GROUP_ACTIVE:
            break;
            
        case EVT_ID_GROUP_INACTIVE:
        {
         /*   evt_for_parent.evt_id = CUI_WC_SELECT_EVENT_CLOSE_REQ;                
            evt_for_parent.size = sizeof(cui_worldclock_event_struct);
            evt_for_parent.user_data = NULL;
            evt_for_parent.sender_id = g_wc_cntx.grp_id;
            evt_for_parent.city_index = g_wc_cntx.CurrCityIndex;
            mmi_frm_group_send_to_parent(g_wc_cntx.grp_id, (mmi_group_event_struct *)&evt_for_parent);
            */
            break;
        }
        
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:     
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:  
        case EVT_ID_GROUP_DEINIT:
        {
            g_wc_cntx.grp_id = GRP_ID_INVALID;
            g_wc_cntx.sel_scrn = MMI_FALSE;
	    cui_worldclock_set_current_city(0XFF);
            break; 
        }
        
    }
    return MMI_RET_OK;

}


/*****************************************************************************              
 * FUNCTION
 *  mmi_wc_cui_select_result
 * DESCRIPTION
 *  create cui menu
 * PARAMETERS
 *  evt            : [IN]     Receives event from framework 
 * RETURNS
 *  mmi_ret
 * RETURN VALUES
 *  error code
********************************************************************************/
void mmi_wc_cui_select_result(MMI_BOOL result, U8 city_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_worldclock_event_struct evt_for_parent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        evt_for_parent.evt_id = CUI_WC_SELECT_EVENT_OK;
    }
    else
    {
        evt_for_parent.evt_id = CUI_WC_SELECT_EVENT_CANCEL;
    }

    evt_for_parent.size = sizeof(cui_worldclock_event_struct);
    evt_for_parent.user_data = NULL;
    evt_for_parent.sender_id = g_wc_cntx.grp_id;
    evt_for_parent.city_index = city_index;
    mmi_frm_group_send_to_parent(g_wc_cntx.grp_id, (mmi_group_event_struct *)&evt_for_parent);

}

#endif /* __MMI_WORLD_CLOCK__ */


