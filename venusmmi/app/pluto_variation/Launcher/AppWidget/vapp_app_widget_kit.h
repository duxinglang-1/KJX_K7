/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_app_widget_kit.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the widget kit.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_APP_WIDGET_KIT_H
#define VAPP_APP_WIDGET_KIT_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_app_widget_primitive.h"
#include "vapp_app_widget.h"
#include "vapp_app_widget_factory.h"

#define VAPP_APP_WIDGET_KIT_MAX_NUM_FACTORY 5


/*****************************************************************************
 * Widget Kit Control Class
 *****************************************************************************/

class VappAppWidgetKitControl : public VfxBase
{
public:
    VappAppWidgetKitControl();

    VappAppWidgetKitControl(
        VfxBool initial
    );

    ~VappAppWidgetKitControl();

public:
    void permit(
        VappAppWidgetSrcEnum source
    );

    void forbit(
        VappAppWidgetSrcEnum source
    );

    VfxBool isPermitted(
        VappAppWidgetSrcEnum source
    ) const;

private:
    enum
    {
        TOTAL_SOURCE_NUM = VAPP_APP_WIDGET_SRC_TOTAL
    };

private:
    VfxBool m_permitted[TOTAL_SOURCE_NUM];
};


/*****************************************************************************
 * Widget Kit Class
 *****************************************************************************/

class VappAppWidgetKit : public VfxObject
{
    VFX_DECLARE_CLASS(VappAppWidgetKit);

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappAppWidgetKit);

public:
    typedef VappAppWidgetFactory *(*createFunc)();

public:
    VappAppWidgetKit();

public:
    // This function gets the total number of supported widgets.
    // RETURNS: total number of widgets.
    VfxS32 getTotalNum(
        const VappAppWidgetKitControl *control = NULL  // [IN] Kit control
    );

    // This function gets the ID of all the supported widgets.
    // RETURNS: total number of widgets.
    VfxS32 getAllId(
        VappAppWidgetId **id,                          // [OUT] Widget ID array
        VfxS32 size,                                // [IN]  Size of the array
        const VappAppWidgetKitControl *control = NULL  // [IN]  Kit control
    );

    // This function checks if the ID is valid to create a widget.
    // RETURNS: valid or not.
    VfxBool isIdValid(
        const VappAppWidgetId &id,                     // [IN] Widget ID
        const VappAppWidgetKitControl *control = NULL  // [IN] Kit control
    );

    // This function gets the name of the widgets.
    // RETURNS: length of the widget name
    VfxS32 getName(
        const VappAppWidgetId &id,     // [IN]  Widget ID
        VfxWChar *string,           // [OUT] String buffer
        VfxS32 size                 // [IN]  Buffer size in wchar
    );

    // This function creates the widgets.
    // RETURNS: the created widget.
    VappAppWidget *createWidget(
        const VappAppWidgetId &id,     // [IN] Widget ID
        VfxObject *parentObj        // [IN] Parent object of the widget
    );

    // This function creates the widget icon.
    // RETURNS: the widget icon.
    VfxFrame *createIcon(
        const VappAppWidgetId &id,     // [IN] Widget ID
        VfxObject *parentObj        // [IN] Parent object of the widget
    );

    // This function gets the total number of the pre-installed widgets.
    // RETURNS: total number of the pre-installed widgets.
    VfxS32 getPreInstalledNum() const;

    // This function gets all the pre-installed widgets.
    // RETURNS: total number of the pre-installed widgets.
    VfxS32 getPreInstalledWidget(
        VappAppWidgetPreInstalled **preInstalled,  // [Out] pre-installed widget
        VfxS32 size                             // [IN]  size of the array
    ) const;

// Override
protected:
    virtual void onInit();

    virtual void onDeinit();

// Variable
private:
    // This table definese the create function of all widget kits.
    static const createFunc m_factoryCreateTbl[];

    // The pointer to the widget factory.
    VappAppWidgetFactory *m_factory[VAPP_APP_WIDGET_KIT_MAX_NUM_FACTORY];

    // The number of widget kits.
    VfxS32 m_numOfFactory;
};

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_APP_WIDGET_KIT_H */

