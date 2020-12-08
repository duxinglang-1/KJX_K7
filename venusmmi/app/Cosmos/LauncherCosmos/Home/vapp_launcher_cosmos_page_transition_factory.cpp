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
 *  vapp_widget_factory.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the base class of the widget factory.
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

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_launcher_cosmos_page_transition.h"
#include "vapp_launcher_cosmos_page_transition_factory.h"


/*****************************************************************************
 * Page Transition Class Configuration
 *****************************************************************************/

/*
 * Macro to add a page transition class.
 */
#define VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_CFG_ADD(_id, _class)                            \
    VappLauncherCosmosPageTransitionFactory::createTableEntry(      \
        _id,                                                        \
        _class::createPageTransition)

#define VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_CFG_END()                                       \
    VappLauncherCosmosPageTransitionFactory::createTableEntry(      \
        VAPP_PAGE_TRANSITION_INVALID,                                   \
        NULL)


/*
 * Registration:
 */
const VappLauncherCosmosPageTransitionFactory::createTableEntry
VappLauncherCosmosPageTransitionFactory::s_createTbl[] =
{

    VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_CFG_ADD(
        VAPP_PAGE_TRANSITION_TYPE_NORMAL,
        VappLauncherCosmosPageTransitionNormal),

    VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_CFG_ADD(
        VAPP_PAGE_TRANSITION_TYPE_PHOTO_WALL,
        VappLauncherCosmosPageTransitionPhotoWall),

    VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_CFG_ADD(
        VAPP_PAGE_TRANSITION_TYPE_CUBE,
        VappLauncherCosmosPageTransitionCube),
    
    VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_CFG_ADD(
        VAPP_PAGE_TRANSITION_TYPE_ROBOT,
        VappLauncherCosmosPageTransitionRobot),

    VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_CFG_END()
};

const VfxS32 VappLauncherCosmosPageTransitionFactory::s_sizeOfCreateTbl =
    sizeof(VappLauncherCosmosPageTransitionFactory::s_createTbl) /
    sizeof(VappLauncherCosmosPageTransitionFactory::createTableEntry) - 1;


/*****************************************************************************
 * Page Transition Factory Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosPageTransitionFactory", VappLauncherCosmosPageTransitionFactory, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappLauncherCosmosPageTransitionFactory);


VappLauncherCosmosPageTransitionFactory::VappLauncherCosmosPageTransitionFactory()
{
    // Do nothing.
}


VappLauncherCosmosPageTransitionFactory::~VappLauncherCosmosPageTransitionFactory()
{
    // Do nothing.
}


VappLauncherCosmosPageTransition *VappLauncherCosmosPageTransitionFactory::createPageTransition(
    const VappPageTransitionTypeEnum &id,
    VfxObject *parentObj)
{
    VfxS32 i;

    // Find the entry corresponding to this widget.
    for (i = 0; i < s_sizeOfCreateTbl; i++)
    {
        if (s_createTbl[i].m_type == id)
        {
            break;
        }
    }

    if (i == s_sizeOfCreateTbl)
    {
        return NULL;    // Not found.
    }

    // Make sure the create function is present.
    VFX_ASSERT(s_createTbl[i].m_create);

    return (VappLauncherCosmosPageTransition *)s_createTbl[i].m_create(parentObj);
}

