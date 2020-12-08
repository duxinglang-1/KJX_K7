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
 *  Vapp_op01_mm.c
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Mainmenu launch functions
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "browser_api.h"
#include "Conversions.h"
#include "JavaAppFactorySrvGprot.h"
#include "Vapp_op_mm_util.h"

#ifdef BROWSER_SUPPORT
#define MMI_OP01_ONLINE_SALES   L"http://10086.cn/m"


/*****************************************************************************
 * FUNCTION
 *  vapp_mobile_portal_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_mobile_portal_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8)MMI_OP01_ONLINE_SALES);
    return MMI_RET_OK;
}
#endif /* BROWSER_SUPPORT */

#ifdef __MMI_OP01_MIDLET_FETION__
/*****************************************************************************
 * FUNCTION
 *  vapp_fetion_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_fetion_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR app_name[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)app_name, sizeof(app_name), (kal_uint8 *)vapp_op_midlet_info[VAPP_OP01_MIDLET_FETION].midlet_name);
    srv_java_appfactory_launch(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, NULL, 0);

    return MMI_RET_OK;
}
#endif

#ifdef __MMI_OP01_MIDLET_MUSIC_WALKMAN__
/*****************************************************************************
 * FUNCTION
 *  vapp_music_walkman_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_music_walkman_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR app_name[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)app_name, sizeof(app_name), (kal_uint8 *)vapp_op_midlet_info[VAPP_OP01_MIDLET_MUSIC_WALKMAN].midlet_name);
    srv_java_appfactory_launch(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, NULL, 0);

    return MMI_RET_OK;
}
#endif

#ifdef __MMI_OP01_MIDLET_MOBILE_STOCK__
/*****************************************************************************
 * FUNCTION
 *  vapp_mobile_stock_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_mobile_stock_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR app_name[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)app_name, sizeof(app_name), (kal_uint8 *)vapp_op_midlet_info[VAPP_OP01_MIDLET_MOBILE_STOCK].midlet_name);
    srv_java_appfactory_launch(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, NULL, 0);

    return MMI_RET_OK;
}
#endif

#ifdef __MMI_OP01_MIDLET_MOBILE_MAP__
/*****************************************************************************
 * FUNCTION
 *  vapp_mobile_map_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_mobile_map_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR app_name[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)app_name, sizeof(app_name), (kal_uint8 *)vapp_op_midlet_info[VAPP_OP01_MIDLET_MOBILE_MAP].midlet_name);
    srv_java_appfactory_launch(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, NULL, 0);

    return MMI_RET_OK;
}
#endif

#ifdef __MMI_OP01_MIDLET_MOBILE_MARKET__
/*****************************************************************************
 * FUNCTION
 *  vapp_mobile_market_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_mobile_market_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR app_name[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)app_name, sizeof(app_name), (kal_uint8 *)vapp_op_midlet_info[VAPP_OP01_MIDLET_MOBILE_MARKET].midlet_name);
    srv_java_appfactory_launch(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, NULL, 0);

    return MMI_RET_OK;
}
#endif


#ifdef __MMI_OP01_MIDLET_MOBILE_READ__
/*****************************************************************************
 * FUNCTION
 *  vapp_mobile_read_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_mobile_read_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR app_name[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)app_name, sizeof(app_name), (kal_uint8 *)vapp_op_midlet_info[VAPP_OP01_MIDLET_MOBILE_READ].midlet_name);
    srv_java_appfactory_launch(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, NULL, 0);

    return MMI_RET_OK;
}
#endif


