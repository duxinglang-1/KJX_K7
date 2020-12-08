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
 *  TetheringSrvApi.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Wi-Fi hotspot service API
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"
#include "mmi_features.h"
#include "TetheringSrvGprot.h"
#include "TetheringSrvIprot.h"

#include "BootupSrvGprot.h"
#include "mmi_conn_app_trc.h"
#include "CbmSrvGprot.h" // CBM_INVALID_NWK_ACCT_ID

/****************************************************************************
* Define
*****************************************************************************/

/****************************************************************************
* Typedef
*****************************************************************************/

/****************************************************************************
* Global Variable
*****************************************************************************/

/****************************************************************************
* Static Variable
*****************************************************************************/
static srv_tethering_cb_info cb_info;

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/

/****************************************************************************
* Function Body
*****************************************************************************/

MMI_BOOL srv_tethering_is_on(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TETHERING__
    switch (tethering_type)
    {
        case SRV_TETHERING_TYPE_WIFI_HS:
        case SRV_TETHERING_TYPE_USB:
        {
            if (srv_tethering_get_status(tethering_type) == SRV_TETHERING_STATUS_SRV_ON)
            {
                ret = MMI_TRUE;
            }
            break;
        }

        default:
            break;
    }
#endif /* __MMI_TETHERING__ */
    return ret;
}


MMI_BOOL srv_tethering_is_off(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TETHERING__
    switch (tethering_type)
    {
        case SRV_TETHERING_TYPE_WIFI_HS:
        case SRV_TETHERING_TYPE_USB:
        {
            if (srv_tethering_get_status(tethering_type) == SRV_TETHERING_STATUS_SRV_OFF)
            {
                ret = MMI_TRUE;
            }
            else
            {
                ret = MMI_FALSE;
           	}
            break;
        }

        default:
            break;
    }
#endif /* __MMI_TETHERING__ */
    return ret;
}


MMI_BOOL srv_tethering_is_switching(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TETHERING__    
    switch (tethering_type)
    {
        case SRV_TETHERING_TYPE_WIFI_HS:
        case SRV_TETHERING_TYPE_USB:
        {
            if (srv_tethering_get_status(tethering_type) == SRV_TETHERING_STATUS_ON_SWITCHING_OFF ||
                srv_tethering_get_status(tethering_type) == SRV_TETHERING_STATUS_ON_SWITCHING_ON)
            {
                ret = MMI_TRUE;
            }
            break;
        }

        default:
            break;
    }
#endif /* __MMI_TETHERING__ */
    return ret;
}


MMI_BOOL srv_tethering_any_type_is_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TETHERING__
    S32 i = 0;
		
    for (i = 0; i < SRV_TETHERING_TYPE_ALL; i++)
    {
        if (srv_tethering_get_status((srv_tethering_type_enum)i) == SRV_TETHERING_STATUS_SRV_ON)
        {
            return MMI_TRUE;
        }
    }
#endif /* __MMI_TETHERING__ */
    return MMI_FALSE;
}


void srv_tethering_stop(
    srv_tethering_type_enum tethering_type,
    srv_tethering_cb_func_ptr cb_func_ptr,
    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_STOP, tethering_type);

    cb_info.cb_func_ptr = cb_func_ptr;
    cb_info.user_data = user_data;

#ifdef __MMI_TETHERING__
    if (srv_tethering_get_status(tethering_type) == SRV_TETHERING_STATUS_SRV_ON)
    {
        srv_tethering_set_ext_status(
            tethering_type,
            SRV_TETHERING_EXT_STATUS_FORCE_STOP);
        srv_tethering_abm_send_deactivate_req(tethering_type);
    }
    else if (srv_tethering_get_status(tethering_type) == SRV_TETHERING_STATUS_SRV_OFF)
    {
        if (srv_tethering_get_ext_status(tethering_type) == SRV_TETHERING_EXT_STATUS_REACTIVATE)
        {
            srv_tethering_set_ext_status(
                tethering_type,
                SRV_TETHERING_EXT_STATUS_FORCE_STOP);
        }
        srv_tethering_run_cb_func(tethering_type, MMI_TRUE);
    }
    else
    {
        srv_tethering_set_ext_status(
            tethering_type,
            SRV_TETHERING_EXT_STATUS_FORCE_STOP);
    }
#else /* __MMI_TETHERING__ */
    srv_tethering_run_cb_func(tethering_type, MMI_TRUE);
#endif /* __MMI_TETHERING__ */
}


MMI_BOOL srv_tethering_stop_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
#ifdef __MMI_TETHERING__
    srv_tethering_type_enum tethering_type = SRV_TETHERING_TYPE_WIFI_HS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_STOP_ALL);

    for (; tethering_type < SRV_TETHERING_TYPE_ALL; tethering_type++)
    {
        srv_tethering_stop(tethering_type, NULL, NULL);
    }
#endif /* __MMI_TETHERING__ */
    return ret;
}


void srv_tethering_run_cb_func(srv_tethering_type_enum tethering_type, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_RUN_CB, tethering_type, result);

    if (cb_info.cb_func_ptr != NULL)
    {
        cb_info.cb_func_ptr(tethering_type, result, cb_info.user_data);
    }
    cb_info.cb_func_ptr = NULL;
    cb_info.user_data = NULL;
}


void srv_tethering_usb_cable_disconnect_notify_hdlr(void)
{
#ifdef __USB_TETHERING__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_USB_CABLE_DISCONN);
    //srv_tethering_stop(SRV_TETHERING_TYPE_USB, NULL, NULL);
    //srv_tethering_set_reactivate_flag(SRV_TETHERING_TYPE_USB, MMI_FALSE);
    //srv_tethering_usb_cable_disconnect_notify_app();
#endif /* __USB_TETHERING__ */
}


U32 srv_tethering_usb_qurey_acct_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret = CBM_INVALID_NWK_ACCT_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_TETHERING__
    if (srv_tethering_get_status(SRV_TETHERING_TYPE_USB) != SRV_TETHERING_STATUS_SRV_OFF)
    {
        ret = srv_tethering_get_curr_dtcnt(SRV_TETHERING_TYPE_USB);
        //ret = cbm_get_original_account(ret);
    }
#endif /* __USB_TETHERING__ */
    return ret;
}

