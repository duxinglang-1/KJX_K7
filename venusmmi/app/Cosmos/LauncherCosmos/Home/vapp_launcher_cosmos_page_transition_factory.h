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
 *  vapp_launcher_cosmos_page_transition_factory.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the base class of the widget factory.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_FACTORY_H
#define VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_FACTORY_H

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_launcher_cosmos_page_transition.h"


/*****************************************************************************
 * Page Transition Enum
 *****************************************************************************/

typedef enum
{
    VAPP_PAGE_TRANSITION_TYPE_NORMAL,

    VAPP_PAGE_TRANSITION_TYPE_PHOTO_WALL,

    VAPP_PAGE_TRANSITION_TYPE_CUBE,

    VAPP_PAGE_TRANSITION_TYPE_ROBOT,
    
    VAPP_PAGE_TRANSITION_TOTAL,

    VAPP_PAGE_TRANSITION_INVALID
} VappPageTransitionTypeEnum;


/*****************************************************************************
 * Widget Factory Base Class
 *****************************************************************************/

/*
 * Widget Factory Base Class
 */
class VappLauncherCosmosPageTransitionFactory : public VfxObject
{
    VFX_DECLARE_CLASS(VappLauncherCosmosPageTransitionFactory);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappLauncherCosmosPageTransitionFactory);

// Constructor / Destructor
public:
    // Default constructor.
    VappLauncherCosmosPageTransitionFactory();

    // Default destructor.
    virtual ~VappLauncherCosmosPageTransitionFactory();

//
// This block defines the class used to register the page transition class.
//
public:
    class createTableEntry : public VfxBase
    {
    public:
        typedef VappLauncherCosmosPageTransition *(*createFunc)(VfxObject *parentObj);

    // Constructor / Destructor
    public:
        // Default constructor
        createTableEntry() :
            m_type(VAPP_PAGE_TRANSITION_INVALID),
            m_create(NULL)
        {
            // Do nothing.
        }

        // Construct an entry with the type and create function.
        createTableEntry(VappPageTransitionTypeEnum type, createFunc create) :
            m_type(type),
            m_create(create)
        {
            // Do nothing.
        }

    // Variable
    public:
        // Type of the page transition effect
        VappPageTransitionTypeEnum m_type;

        // Create function for such page transition effect
        createFunc m_create;
    };

// Method
public:

    virtual VfxS32 getTotalNum() const
    {
        return VAPP_PAGE_TRANSITION_TOTAL;
    }

    // Please refer to VappWidgetFactory.
    virtual VappLauncherCosmosPageTransition *createPageTransition(
        const VappPageTransitionTypeEnum &id,
        VfxObject *parentObj
    );


// Variable
private:
    // Table for the native widget registration.
    static const createTableEntry s_createTbl[];

    // Size of the create table.
    static const VfxS32 s_sizeOfCreateTbl;
};

#endif /* VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_FACTORY_H */

