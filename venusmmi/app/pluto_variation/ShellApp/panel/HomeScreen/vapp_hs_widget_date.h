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
 *  vapp_hs_widget_date.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: date
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_HS_WIDGET_DATE_H__
#define __VAPP_HS_WIDGET_DATE_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_DATE__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_hs_widget_base.h"

#include "vfx_cpp_base.h"
#include "vapp_hs_widget_cfg.h"
#include "vapp_hs_def.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_datatype.h"
#include "mmi_rp_app_venus_homescreen_wg_date_def.h"
#include "vfx_primitive_frame.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Home screen widget: date
 *****************************************************************************/
class VappHsWidgetDate : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetDate);

// Declaration
private:
    enum
    {
        GAP = 2         // GAP
    };

// Constructor / Destructor
public:
    // Default constructor
    VappHsWidgetDate();

// Override
public:
    // get the image ID of widget bar icon
    virtual VfxU16 getIcon() { return VAPP_HS_IMG_WG_ICON_DATE; }

    // get the name of the widget
    virtual VfxU16 getName() { return VAPP_HS_STR_WG_DATE; }

    // create widget bar icon frame, m_controlIcon
    virtual VfxBool onCreateIconView();

    // release widget bar icon frame
    virtual void onReleaseIconView();

    // create the whole widget content
    virtual void onCreateView();

    // release the whole widget content
    virtual void onReleaseView();

// Method
private:
    // time update for widget
    // RETURNS: void
    void timeUpdate(VfxU32 flag);

    // time update for widget icon
    // RETURNS: void
    void timeUpdateIcon(VfxU32 flag);

// Variables
private:

    // month image
    VfxImageFrame   *m_imageMonth;

    // week image
    VfxImageFrame   *m_imageWeek;

    // day image
    VfxImageFrame   *m_imageDay[2];

    // widget icon digits
    VfxImageFrame   *m_imageIconDigits[2];

    // image background
    VfxImageFrame   *m_imageBg;
};

#endif /* __MMI_VUI_HOMESCREEN_DATE__ */
#endif /* __VAPP_HS_WIDGET_DATE_H__ */

