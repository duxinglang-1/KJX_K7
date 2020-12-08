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
 *  vadp_p2v_hs.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Pluto MMI to the Venus
 *  MMI.
 *
 *      Pluto APP ---> p2v adaptor ---> Venus APP
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

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/* Pluto headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "kal_general_types.h"

#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"

#ifdef __cplusplus
}   /* extern "C" */
#endif

/* Venus headers: */
#include "vapp_hs_widget_mgr.h"
#include "vadp_p2v_hs.h"
#include "vdat_network_info.h"
#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vapp_hs_widget_cfg.h"
#include "vfx_cpp_base.h"


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vapp_hs_set_network_name
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_set_network_name(const U8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VdatNetworkInfo *networkSrv;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    networkSrv = VFX_OBJ_GET_INSTANCE(VdatNetworkInfo);
    networkSrv->processNameChanged((const VfxWChar *)name);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_hs_set_network_status
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_set_network_status_2(const U8 *status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VdatNetworkInfo *networkSrv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    networkSrv = VFX_OBJ_GET_INSTANCE(VdatNetworkInfo);
    networkSrv->processStatusChanged2((const VfxWChar *)status);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_hs_set_network_name
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_set_network_name_2(const U8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VdatNetworkInfo *networkSrv;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    networkSrv = VFX_OBJ_GET_INSTANCE(VdatNetworkInfo);
    networkSrv->processNameChanged2((const VfxWChar *)name);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_hs_set_network_status
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_set_network_status(const U8 *status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VdatNetworkInfo *networkSrv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    networkSrv = VFX_OBJ_GET_INSTANCE(VdatNetworkInfo);
    networkSrv->processStatusChanged((const VfxWChar *)status);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_set_idle_mode_text
 * DESCRIPTION
 *  This function sets the idle mode text.
 * PARAMETERS
 *  text        : [IN]      Idle mode text
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_set_idle_mode_text(const U8 *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VdatNetworkInfo *networkSrv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    networkSrv = VFX_OBJ_GET_INSTANCE(VdatNetworkInfo);
    networkSrv->processIdleModeTextChanged((const VfxWChar *)text);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_set_idle_mode_icon
 * DESCRIPTION
 *  This function sets the idle mode icon.
 * PARAMETERS
 *  icon        : [IN]      Idle mode icon
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_set_idle_mode_icon(const U8 *icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VdatNetworkInfo *networkSrv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    networkSrv = VFX_OBJ_GET_INSTANCE(VdatNetworkInfo);
    networkSrv->processIdleModeIconChanged((const VfxU8 *)icon);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_widget_get_all_id
 * DESCRIPTION
 *  This function gets the ID of all device widget.
 * PARAMETERS
 *  id              : [OUT]             ID
 *  size            : [IN]              Size of 'id' array
 * RETURNS
 *  On success, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL vadp_p2v_hs_widget_get_all_id(S32 *id, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const vapp_hs_widget_cfg_struct *tbl = vapp_hs_get_widget_cfg_table();
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size < VAPP_HS_WIDGET_TOTAL)
    {
        return MMI_FALSE; /* id array is not large enough */
    }

    for (i = 0; i < VAPP_HS_WIDGET_TOTAL; i++)
    {
        id[i] = tbl[i].id;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_widget_get_icon
 * DESCRIPTION
 *  This function gets the widget icon.
 * PARAMETERS
 *  id              : [IN]          ID of the device widget
 * RETURNS
 *  Icon image ID.
 *****************************************************************************/
U16 vadp_p2v_hs_widget_get_icon(S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const vapp_hs_widget_cfg_struct *tbl = vapp_hs_get_widget_cfg_table();
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < VAPP_HS_WIDGET_TOTAL; i++)
    {
        if (id == tbl[i].id)
        {
            return tbl[i].icon;
        }
    }

    return 0; /* invalid id */
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_widget_get_name
 * DESCRIPTION
 *  This function gets the widget name.
 * PARAMETERS
 *  id              : [IN]          ID of the device widget
 * RETURNS
 *  String ID of the widget name.
 *****************************************************************************/
U16 vadp_p2v_hs_widget_get_name(S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const vapp_hs_widget_cfg_struct *tbl = vapp_hs_get_widget_cfg_table();
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < VAPP_HS_WIDGET_TOTAL; i++)
    {
        if (id == tbl[i].id)
        {
            return tbl[i].name;
        }
    }

    return 0; /* invalid id */
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_widget_need_network
 * DESCRIPTION
 *  This function check if the widget needs to access the network.
 * PARAMETERS
 *  id              : [IN]          ID of the device widget
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL vadp_p2v_hs_widget_need_network(S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const vapp_hs_widget_cfg_struct *tbl = vapp_hs_get_widget_cfg_table();
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < VAPP_HS_WIDGET_TOTAL; i++)
    {
        if (id == tbl[i].id)
        {
            if ((tbl[i].attr & VAPP_HS_WIDGET_ATTR_NEED_NETWORK))
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
    }

    return MMI_FALSE; /* invalid id */
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_widget_reset
 * DESCRIPTION
 *  This function resets all the widgets of the specified type.
 * PARAMETERS
 *  type                : [IN]          Widget type
 *  err_str_id          : [IN]          Error string ID
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_widget_reset(S32 type, U16 err_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VappHsWidgetMgr::dismissWidget(type, VFX_FALSE, 0);

    if (err_str_id != 0)
    {
        mmi_popup_display_simple(
            (WCHAR *)get_string(err_str_id),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_widget_reset_by_id
 * DESCRIPTION
 *  This function resets the specified widget.
 * PARAMETERS
 *  type                : [IN]          Widget type
 *  id                  : [IN]          Widget ID
 *  err_str_id          : [IN]          Error string ID
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_widget_reset_by_id(S32 type, S32 id, U16 err_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VappHsWidgetMgr::dismissWidget(type, VFX_TRUE, id);

    if (err_str_id != 0)
    {
        mmi_popup_display_simple(
            (WCHAR *)get_string(err_str_id),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
    }
}

#endif /* __MMI_VUI_HOMESCREEN__ */

