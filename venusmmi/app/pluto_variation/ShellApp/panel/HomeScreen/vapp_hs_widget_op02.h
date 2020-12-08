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
 *  vapp_hs_widget_mre.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: MRE link
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_HS_WIDGET_OP02_H__
#define __VAPP_HS_WIDGET_OP02_H__

#include "MMI_features.h"

#if defined(__MMI_VUI_HOMESCREEN_MOBILE_INTERNET__) || defined(__MMI_VUI_HOMESCREEN_WO_STORE__)
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_hs_widget_base.h"
#include "vapp_hs_widget_shortcut.h"

#include "vfx_cpp_base.h"
#include "vapp_hs_widget_cfg.h"
#include "vapp_hs_def.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_datatype.h"
#include "mmi_rp_app_venus_homescreen_wg_mobile_internet_def.h"
#include "mmi_rp_app_venus_homescreen_wg_wo_store_def.h"
#endif /* defined(__MMI_VUI_HOMESCREEN_MOBILE_INTERNET__) || defined(__MMI_VUI_HOMESCREEN_WO_STORE__) */

#ifdef __MMI_VUI_HOMESCREEN_WO_STORE__
extern "C" void mmi_op02_midlet_wo_store_launch(void);

/***************************************************************************** 
 * Home screen widget: Wo store
 *****************************************************************************/
class VappHsWidgetWoStore : public VappHsWidgetShortcut
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetWoStore);

// Constructor / Destructor
public:
    // Default constructor
    VappHsWidgetWoStore() {}

// Method
public:
    // get the image ID of
    virtual VfxU16 getIcon() { return VAPP_HS_IMG_WG_ICON_WO_STORE; }

    // get the string ID of
    virtual VfxU16 getName() { return VAPP_HS_STR_WG_WO_STORE; }
    
    // Get widget body image ID, only used if getImage returns NULL
    // RETURNS: image resource ID
    virtual VfxS32 getImageId() {return VAPP_HS_IMG_WG_WO_STORE;}

// Override
protected:
#ifdef __MMI_OP02_MIDLET_WO_STORE__
    // Launch setting
    virtual void onDirectLaunch() {mmi_op02_midlet_wo_store_launch();}
#endif
};
#endif /* __MMI_VUI_HOMESCREEN_WO_STORE__ */


#ifdef __MMI_VUI_HOMESCREEN_MOBILE_INTERNET__
extern "C" void goto_op02_web_portal(void);

/***************************************************************************** 
 * Home screen widget: Mobile Internet
 *****************************************************************************/
class VappHsWidgetMobileInternet : public VappHsWidgetShortcut
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetMobileInternet);

// Constructor / Destructor
public:
    // Default constructor
    VappHsWidgetMobileInternet() {}

// Method
public:
    // get the image ID of
    virtual VfxU16 getIcon() { return VAPP_HS_IMG_WG_ICON_MOBILE_INTERNET; }

    // get the string ID of
    virtual VfxU16 getName() { return VAPP_HS_STR_WG_MOBILE_INTERNET; };
    
    // Get widget body image ID, only used if getImage returns NULL
    // RETURNS: image resource ID
    virtual VfxS32 getImageId() { return VAPP_HS_IMG_WG_MOBILE_INTERNET; }

// Override
protected:
    // Launch setting
    virtual void onDirectLaunch() {goto_op02_web_portal();}
};
#endif /* __MMI_VUI_HOMESCREEN_MOBILE_INTERNET__ */
#endif /* __VAPP_HS_WIDGET_OP02_H__ */

