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
 *  vapp_app_widget_native_factory.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the native widget factory.
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

#ifndef VAPP_APP_WIDGET_NATIVE_FACTORY_H
#define VAPP_APP_WIDGET_NATIVE_FACTORY_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_app_widget_def.h"
#include "vapp_app_widget_factory.h"


/*****************************************************************************
 * Native Widget Factory
 *****************************************************************************/

class VappAppWidgetNativeFactory : public VappAppWidgetFactory
{
    VAPP_APP_WIDGET_FACTORY_DECLARE_CLASS(VappAppWidgetNativeFactory);

public:
    // This block defines the class used to register the native widget.

    class createTableEntry : public VfxBase
    {
    public:
        typedef VappAppWidget *(*createFunc)(VfxObject *parentObj);

    // Constructor / Destructor
    public:
        // Default constructor
        createTableEntry() :
            m_type(VAPP_APP_WIDGET_TYPE_INVALID),
            m_create(NULL)
        {
            // Do nothing.
        }

        // Construct a entry with the type and create function.
        createTableEntry(VappAppWidgetTypeEnum type, createFunc create) :
            m_type(type),
            m_create(create)
        {
            // Do nothing.
        }

    // Variable
    public:
        // Type of the widget
        VappAppWidgetTypeEnum m_type;

        // Create function for such widget
        createFunc m_create;
    };

// Constructor / Destructor
public:
    VappAppWidgetNativeFactory();

// Override
public:
    virtual VappAppWidgetSrcEnum getSource() const
    {
        return VAPP_APP_WIDGET_SRC_NATIVE;
    }

    virtual VfxS32 getTotalNum() const
    {
        return VAPP_APP_WIDGET_TYPE_TOTAL;
    }

    virtual VfxS32 getAllId(
        VappAppWidgetId **id,
        VfxS32 size
    ) const;

    virtual VappAppWidget *createWidget(
        const VappAppWidgetId &id,
        VfxObject *parentObj
    );

// Variable
private:
    // Table for the native widget registration.
    static const createTableEntry s_createTbl[];

    // Size of the table.
    static const VfxS32 s_sizeOfTbl;
};

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_APP_WIDGET_NATIVE_FACTORY_H */

