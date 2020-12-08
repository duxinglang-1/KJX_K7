/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_kit.h
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

#ifndef VAPP_WIDGET_KIT_H
#define VAPP_WIDGET_KIT_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_widget_primitive.h"
#include "vapp_widget.h"
#include "vapp_widget_factory.h"


/*****************************************************************************
 * Macro
 *****************************************************************************/

/*
 * Macro to populate a widget factory.
 */
#define VAPP_WIDGET_SYS_PUBLISH_FACTORY(_className, _publisher)             \
                                                                            \
    extern "C" mmi_ret _publisher(mmi_event_struct *event)                  \
    {                                                                       \
        _className *factory = VFX_OBJ_GET_INSTANCE(_className);             \
        VappWidgetKit *kit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);           \
        kit->add(factory);                                                  \
        return MMI_RET_OK;                                                  \
    }


/*****************************************************************************
 * Widget Kit Control Class
 *****************************************************************************/

class VappWidgetKitControl : public VfxBase
{
public:
    VappWidgetKitControl();

    VappWidgetKitControl(
        VfxBool initial
    );

    ~VappWidgetKitControl();

public:
    void permit(
        VappWidgetSrcEnum source
    );

    void forbit(
        VappWidgetSrcEnum source
    );

    VfxBool isPermitted(
        VappWidgetSrcEnum source
    ) const;

private:
    enum
    {
        TOTAL_SOURCE_NUM = VAPP_WIDGET_SRC_TOTAL
    };

private:
    VfxBool m_permitted[TOTAL_SOURCE_NUM];
};


/*****************************************************************************
 * Widget Kit Class
 *****************************************************************************/

class VappWidgetKit : public VfxObject
{
    VFX_DECLARE_CLASS(VappWidgetKit);

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappWidgetKit);

// Constructor / Destructor
public:
    // Default Constructor
    VappWidgetKit();

// Method
public:
    // This function gets the total number of supported widgets.
    // RETURNS: total number of widgets.
    VfxS32 getTotalNum(
        const VappWidgetKitControl *control = NULL  // [IN] Kit control
    );

    // This function gets the ID of all the supported widgets.
    // RETURNS: total number of widgets.
    VfxS32 getAllId(
        VappWidgetId **id,                          // [OUT] Widget ID array
        VfxS32 size,                                // [IN]  Size of the array
        const VappWidgetKitControl *control = NULL  // [IN]  Kit control
    );

    // This function checks if the ID is valid to create a widget.
    // RETURNS: valid or not.
    VfxBool isIdValid(
        const VappWidgetId &id,                     // [IN] Widget ID
        const VappWidgetKitControl *control = NULL  // [IN] Kit control
    );

    // This function gets the name of the widgets.
    // RETURNS: length of the widget name
    VfxS32 getName(
        const VappWidgetId &id,     // [IN]  Widget ID
        VfxWChar *string,           // [OUT] String buffer
        VfxS32 size                 // [IN]  Buffer size in wchar
    );

    // This function creates the widgets.
    // RETURNS: the created widget.
    VappWidget *createWidget(
        const VappWidgetId &id,     // [IN] Widget ID
        VfxObject *parentObj        // [IN] Parent object of the widget
    );

    // This function creates the widget icon.
    // RETURNS: the widget icon.
    VfxFrame *createIcon(
        const VappWidgetId &id,     // [IN] Widget ID
        VfxObject *parentObj        // [IN] Parent object of the widget
    );

    // This function gets the total number of the pre-installed widgets.
    // RETURNS: total number of the pre-installed widgets.
    VfxS32 getPreInstalledNum() const;

    // This function gets all the pre-installed widgets.
    // RETURNS: total number of the pre-installed widgets.
    VfxS32 getPreInstalledWidget(
        VappWidgetPreInstalled **preInstalled,  // [Out] pre-installed widget
        VfxS32 size                             // [IN]  size of the array
    ) const;

// Method
public:
    // This function adds a widget factory to the kit.
    void add(
        VappWidgetFactory *factory      // [IN] Widget factory
    );

    // This function removes a widget factory from the kit.
    void remove(
        VappWidgetFactory *factory      // [IN] Widget factory
    );

// Variable
private:
    // Factory list.
    VfxObjList m_factoryList;
};

#endif /* defined(__MMI_VUI_WIDGET_FACTORY__) */
#endif /* VAPP_WIDGET_KIT_H */

