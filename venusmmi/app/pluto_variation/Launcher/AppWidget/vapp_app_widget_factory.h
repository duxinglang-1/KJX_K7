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
 *  vapp_app_widget_factory.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the base class of the App widget factory.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_APP_WIDGET_FACTORY_H
#define VAPP_APP_WIDGET_FACTORY_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_app_widget_def.h"
#include "vapp_app_widget.h"


/*****************************************************************************
 * Widget Factory Base Class
 *****************************************************************************/

/*
 * Macro to declare a widget factory.
 */
#define VAPP_APP_WIDGET_FACTORY_DECLARE_CLASS(_className)                       \
    VFX_DECLARE_CLASS(_className);                                          \
    VFX_OBJ_DECLARE_SINGLETON_CLASS(_className);                            \
    public:                                                                 \
        static inline VappAppWidgetFactory *createFactory()                    \
        {                                                                   \
            VappAppWidgetFactory *factory;                                     \
            factory = VFX_OBJ_GET_INSTANCE(_className);                     \
            return factory;                                                 \
        }

/*
 * Macro to implement a widget factory.
 */
#define VAPP_APP_WIDGET_FACTORY_IMPLEMENT_CLASS(_className)                     \
    VFX_IMPLEMENT_CLASS(#_className, _className, VappAppWidgetFactory);        \
    VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(_className)


/*
 * Widget Factory Base Class
 */
class VappAppWidgetFactory : public VfxObject
{
    VFX_DECLARE_CLASS(VappAppWidgetFactory);

// Constructor / Destructor
public:
    // Default constructor.
    VappAppWidgetFactory();

    // Default destructor.
    virtual ~VappAppWidgetFactory();

// Method
public:
    // This function checks if the ID is valid.
    // RETURNS: On valid, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isValid(
        const VappAppWidgetId &id          // [IN] Widget ID
    );

    // This function gets the name of the widget.
    // RETURNS: Length of the widget name
    VfxS32 getName(
        const VappAppWidgetId &id,         // [IN]  Widget ID
        VfxWChar *string,               // [OUT] String Buffer
        VfxS32 size                     // [IN]  Buffer size in wchar
    );

    // This function creates the widget icon.
    // RETURNS: widget icon.
    VfxFrame *createIcon(
        const VappAppWidgetId &id,               // [IN] Widget ID
        VfxObject *parentObj            // [IN] Parent of the widget icon
    );

// Method
public:
    // This function returns the type of the widget factory.
    // RETURNS: type of the creator.
    virtual VappAppWidgetSrcEnum getSource() const = 0;

    // This function gets the total number of the widget associated with this
    // type.
    // RETURNS: total number of the widgets.
    virtual VfxS32 getTotalNum() const = 0;

    // This function gets the id of all the widgets associated with this type.
    // RETURNS: total number of widgets.
    virtual VfxS32 getAllId(
        VappAppWidgetId **id,              // [OUT] Id of all the widget
        VfxS32 size                     // [IN]  Size of the 'id' array
    ) const = 0;

    // This function creates a widget.
    // RETURNS: the created widget.
    virtual VappAppWidget *createWidget(
        const VappAppWidgetId &id,         // [IN] Id of the widget
        VfxObject *parentObj            // [IN] Parent of the widget
    ) = 0;

    // This function gets the total number of the pre-installed widgets.
    // RETURNS: total number of the pre-installed widgets.
    virtual VfxS32 getPreInstalledNum() const;

    // This function gets all the pre-installed widgets.
    // RETURNS: total number of the pre-installed widgets.
    virtual VfxS32 getPreInstalledWidget(
        VappAppWidgetPreInstalled **preInstalled,  // [Out] pre-installed widget
        VfxS32 size                             // [IN]  size of the array
    ) const;
};

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_APP_WIDGET_FACTORY_H */

