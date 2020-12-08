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
 *  vapp_launcher_cosmos_preinstaller.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the pre-installer to configure the pre-installed widgets.
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

#ifndef VAPP_LAUNCHER_COSMOS_PREINSTALLER_H
#define VAPP_LAUNCHER_COSMOS_PREINSTALLER_H

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMIDataType.h"
#include "vfx_uc_include.h"


/*****************************************************************************
 * Widget Pre-Installer
 *****************************************************************************/

class VappLauncherCosmosPreinstaller : public VfxObject
{
    VFX_DECLARE_CLASS(VappLauncherCosmosPreinstaller);

// Constructor / Destructor
public:
    // Default constructor
    VappLauncherCosmosPreinstaller();

//
// This block defines the class used to register the preinstalled widget.
//
public:
    class preInstallTableEntry : public VfxBase
    {
    // Constructor / Destructor
    public:
        // Default constructor
        preInstallTableEntry();

        // Construct an entry with the specified attributes.
        preInstallTableEntry(
            VappWidgetSrcEnum source,   // [IN] Widget source
            VfxS32 type,                // [IN] Kind o the type
            VfxS32 pageIdx,             // [IN] Page index
            VfxS32 x,                   // [IN] Cell index in x-axis
            VfxS32 y                    // [IN] Cell index in y-axis
        );

        // Construct an entry with the specified attributes.
        preInstallTableEntry(
            VappWidgetSrcEnum source,   // [IN] Widget source
            VfxChar *type,              // [IN] Kind o the type
            VfxS32 pageIdx,             // [IN] Page index
            VfxS32 x,                   // [IN] Cell index in x-axis
            VfxS32 y                    // [IN] Cell index in y-axis
        );

    public:
        // The source of the widget.
        VappWidgetSrcEnum m_source;

        // Kind of the type.
        VappWidgetId::TypeKindEnum m_typeKind;

        // The type of the widget. Use union for different type kinds.
        union
        {
            // Integer type kind.
            VfxS32 ival;

            // String type kind.
            VfxChar sval[MMI_APP_NAME_MAX_LEN];
        } m_type;

        // Page to put this pre-installed widget
        VfxS32 m_pageIdx;

        // Position, in pixels on the specified page, to put this widget.
        VfxPoint m_pos;
    };

// Method
public:
    // This function gets the total number of the pre-installed widgets.
    // RETURNS: total number of the pre-installed widgets.
    VfxS32 getPreInstalledNum() const;

    // This function gets all the pre-installed widgets.
    // RETURNS: total number of the pre-installed widgets.
    VfxS32 getPreInstalledWidget(
        VappWidgetPreInstalled **preInstalled,  // [Out] pre-installed widget
        VfxS32 size                             // [IN]  size of the array
    ) const;

// Variable
private:
    // Table for the pre-installed widget registration.
    static const preInstallTableEntry s_preInstallTbl[];

    // Size of the pre-install table.
    static const VfxS32 s_sizeOfPreInstallTbl;
};

#endif /* VAPP_LAUNCHER_COSMOS_PREINSTALLER_H */

