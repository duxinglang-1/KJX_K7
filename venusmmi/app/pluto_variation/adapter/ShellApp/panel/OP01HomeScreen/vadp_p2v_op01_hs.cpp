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
 *  vadp_p2v_op01_hs.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 /****************************************************************************
  * Include
  ****************************************************************************/
     
#include "MMI_features.h"
     
#ifdef __MMI_VUI_SHELL_OP01_HOMESCREEN__
     
/* Venus headers: */
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vdat_include.h"
#include "OP01HomeScreen\vadp_p2v_op01_hs.h"
#include "OP01HomeScreen\vadp_v2p_op01_hs.h"
#include "vapp_op01_hs_scr.h"

extern VappOp01HsScr *gVappOp01HsScrObj;
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
 *  vadp_p2v_hs_update_wlan_button
 * DESCRIPTION
 *  This function sets wlan button state.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_update_wlan_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gVappOp01HsScrObj != NULL)
    {
        gVappOp01HsScrObj->updateWlanButton();
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_update_wlan_button
 * DESCRIPTION
 *  This function sets wlan button state.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_update_hint_button(VfxS32 id, VfxS32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // num = 100;
    // id = BUTTON_TYPE_SMS;
    if (gVappOp01HsScrObj != NULL)
    {
        gVappOp01HsScrObj->updateHintBox(id, num);
    }
}

#ifdef __MMI_OP01_DCD_V30__
/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_update_dcd_news_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_update_dcd_news_img(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gVappOp01HsScrObj != NULL)
    {
        gVappOp01HsScrObj->updateDCDNewsImgArea();
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_update_dcd_news_cnt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_update_dcd_news_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gVappOp01HsScrObj != NULL)
    {
        gVappOp01HsScrObj->updateDCDNewsContentArea();
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_update_dcd_whether_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_update_dcd_whether_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gVappOp01HsScrObj != NULL)
    {
        gVappOp01HsScrObj->updateDCDWhetherArea();
    }
}
#endif /* __MMI_OP01_DCD_V30__ */

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_suspend_wallpaper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_suspend_wallpaper(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gVappOp01HsScrObj != NULL)
    {
        gVappOp01HsScrObj->suspendLiveWallpaper();
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_hs_resume_wallpaper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_hs_resume_wallpaper(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gVappOp01HsScrObj != NULL)
    {
        gVappOp01HsScrObj->resumeLiveWallpaper();
    }
}
#endif
