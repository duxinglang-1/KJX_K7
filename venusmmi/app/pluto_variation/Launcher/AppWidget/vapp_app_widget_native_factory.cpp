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
 *  vapp_app_widget_native_factory.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the native widget factory.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_app_widget_def.h"
#include "vapp_app_widget_native_factory.h"

/*
 * Widget's Header:
 */
#include "vapp_app_widget_clock.h"
#include "vapp_app_widget_operator_name_cosmos.h"


/*****************************************************************************
 * Define
 *****************************************************************************/

/*
 * Macro to add a native widget.
 */
#define VAPP_APP_WIDGET_CFG_ADD(_id, _class)            \
    VappAppWidgetNativeFactory::createTableEntry(      \
        _id,                                        \
        _class::createWidget)

#define VAPP_APP_WIDGET_CFG_END()                       \
    VappAppWidgetNativeFactory::createTableEntry(      \
        VAPP_APP_WIDGET_TYPE_INVALID,                   \
        NULL)


/*****************************************************************************
 * Configuration
 *****************************************************************************/

const VappAppWidgetNativeFactory::createTableEntry
VappAppWidgetNativeFactory::s_createTbl[] =
{
    VAPP_APP_WIDGET_CFG_ADD(
        VAPP_APP_WIDGET_TYPE_ANALOG_CLOCK,
        VappAppWidgetAnalogClock),

    VAPP_APP_WIDGET_CFG_ADD(
        VAPP_APP_WIDGET_TYPE_DIGITAL_CLOCK,
        VappAppWidgetDigitalClock),

#if defined(VAPP_APP_WIDGET_OPERATOR_NAME)
    VAPP_APP_WIDGET_CFG_ADD(
        VAPP_APP_WIDGET_TYPE_OPERATOR_NAME_COSMOS,
        VappAppWidgetOperatorNameCosmos),
#endif

    VAPP_APP_WIDGET_CFG_END()
};


const VfxS32 VappAppWidgetNativeFactory::s_sizeOfTbl =
    sizeof(VappAppWidgetNativeFactory::s_createTbl) /
    sizeof(VappAppWidgetNativeFactory::createTableEntry) - 1;


/*****************************************************************************
 * Native Widget Factory
 *****************************************************************************/

VAPP_APP_WIDGET_FACTORY_IMPLEMENT_CLASS(VappAppWidgetNativeFactory);


VappAppWidgetNativeFactory::VappAppWidgetNativeFactory()
{
    // Assert if the configuration of the widgets is not correct.
    VFX_ASSERT(s_sizeOfTbl == VAPP_APP_WIDGET_TYPE_TOTAL);
}


VfxS32 VappAppWidgetNativeFactory::getAllId(VappAppWidgetId **id, VfxS32 size) const
{
    // Make sure the caller's buffer is available and large enough.
    VFX_ASSERT(id && size >= s_sizeOfTbl);

    // Copy ID to the buffer.
    for (VfxS32 i = 0; i < s_sizeOfTbl; i++)
    {
        id[i]->assignWith(VAPP_APP_WIDGET_SRC_NATIVE, s_createTbl[i].m_type);
    }

    return s_sizeOfTbl;
}


VappAppWidget *VappAppWidgetNativeFactory::createWidget(
    const VappAppWidgetId &id,
    VfxObject *parentObj)
{
    VfxS32 i;

    if (id.getSource() != getSource())
    {
        return NULL;
    }

    // Find the entry corresponding to this widget.
    for (i = 0; i < s_sizeOfTbl; i++)
    {
        if (s_createTbl[i].m_type == id.getIntType())
        {
            break;
        }
    }

    if (i == s_sizeOfTbl)
    {
        return NULL;    // Not found.
    }

    // Make sure the create function is present.
    VFX_ASSERT(s_createTbl[i].m_create);

    return (VappAppWidget *)s_createTbl[i].m_create(parentObj);
}

#endif /* defined(__MMI_VUI_LAUNCHER__) */
