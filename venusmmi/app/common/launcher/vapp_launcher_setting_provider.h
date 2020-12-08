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
 *  vapp_launcher_setting_provider.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the setting provider of the launcher.
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

#ifndef VAPP_LAUNCHER_SETTING_PROVIDER_H
#define VAPP_LAUNCHER_SETTING_PROVIDER_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "custom_launcher_config.h"

#include "vfx_uc_include.h"
#include "vapp_archive_nvram.h"
#include "vapp_launcher_primitive.h"


/*****************************************************************************
 * System Setting Element
 *****************************************************************************/

typedef struct
{
    // If this slot is used?
    VfxBool isUsed;

    // If this launcher is the default launcher?
    VfxBool isDefault;

    // The launcher ID which this slot is associated with
    VappLauncherId id;
} VappLauncherSettingElem;


/*****************************************************************************
 * Setting Provider
 *****************************************************************************/

class VappLauncherSettingProvider : public VfxObject
{
    VFX_DECLARE_CLASS(VappLauncherSettingProvider);

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappLauncherSettingProvider);

// Enum
public:
    // This enum defines the setting ID.
    //
    // SEE ALSO: createArchiveReader, createArchiveWriter
    enum SettingIdEnum
    {
        // Wallpaper setting ID
        SETTING_ID_WALLPAPER,

    #if defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__)
        // APP icon setting ID
        SETTING_ID_APP_ICON,
    #endif /* defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) */

        // End of setting ID enum
        SETTING_ID_END_OF_ENUM
    };

// Constructor / Destructor
public:
    // Default constructor
    VappLauncherSettingProvider();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Signal
public:
    // This signal is emitted when the default launcher is changed.
    VfxSignal0 m_signalDefaultLauncherChanged;

    // This signal is emitted when the default launcher is changed and we want
    // launcher application updates its display.
    VfxSignal0 m_signalLauncherUpdated;

// Method
public:
    // This function gets the default launcher.
    // RETURNS: Launcher ID.
    VappLauncherId getDefaultLauncher();

    // This functions sets the default launcher.
    void setDefaultLauncher(
        const VappLauncherId &id        // [IN] Launcher ID
    );

    // This function sets the default launcher and requests the mobile to update
    // launcher application.
    void updateDefaultLauncher(
        const VappLauncherId &id        // [IN] Launcher ID
    );

    // This function gets the launcher if anyone is available. Specifically, it
    // gets the first launcher from the native launcher factory.
    // RETURNS: launcher ID.
    VappLauncherId getLauncherIfAny() const;

    // This function creates an archive reader for the specified setting ID. The
    // archive is for the current default launcher.
    //
    // IMPORTANT. PLEASE READ ME.
    //
    // 1) You can't create archive reader and writer at the same time. Assert
    //    will fail if this rule is violated.
    // 2) Before you create the next archive reader, you must close any existing
    //    archive reader. Assert will fail if this rule is violated.
    //
    // Generally, please close the archive reader as soon as you have read the
    // setting from it.
    //
    // SEE ALSO: createArchiveWriter
    VfxArchive *createArchiveReader(
        SettingIdEnum settingId,        // [IN] Setting ID
        VfxObject *parentObj            // [IN] Parent object
    );

    // This function creates an archive writer for the specified setting ID. The
    // archive is for the current default launcher.
    //
    // IMPORTANT. PLEASE READ ME.
    //
    // 1) You can't create archive reader and writer at the same time. Assert
    //    will fail if this rule is violated.
    // 2) Before you create the next archive reader, you must close any existing
    //    archive reader. Assert will fail if this rule is violated.
    //
    // Generally, please close the archive reader as soon as you have read the
    // setting from it.
    //
    // SEE ALSO: createArchiveWriter
    VfxArchive *createArchiveWriter(
        SettingIdEnum settingId,        // [IN] Setting ID
        VfxObject *parentObj            // [IN] Parent object
    );

// Enum
private:
    enum
    {
        GUARD_PATTERN = 0xBABEC0DE,
        LAUNCHER_NUM = CUSTOM_LAUNCHER_MAX_NUM
    };

// Variable
private:
    // Array of settings for all launchers.
    VappLauncherSettingElem m_elem[LAUNCHER_NUM];

#if defined(__MMI_VUI_LAUNCHER_MRE__)
// Implementation
private:
    // This function is the main event hanndler.
    static mmi_ret eventProc(
        mmi_event_struct *evt   // [IN] Event structure
    );

    // Handles the "uninstall" event from the MRE.
    void handleUninstall(
        const VfxChar *appName  // [IN] MRE app name
    );
#endif /* defined(__MMI_VUI_LAUNCHER_MRE__) */

// Implementation
private:
    // Get default launcher. If it isn't existed, return an invalid launcher ID.
    // RETURNS: On success, return the default launcher ID. Otherwise, return an
    //          invalid launcher ID.
    VappLauncherId getDefaultLauncherInt() const;

    // Check if the default launcher ID is existed.
    // RETURNS: On existed, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isDefaultLauncherExisted() const;

    // This function creates an archive.
    // RETURN: archive.
    VfxArchive *createArchive(
        nvram_lid_enum lid,                         // [IN] NVRAM LID
        VfxS32 lidIndex,                            // [IN] LID index
        VfxS32 lidSize,                             // [IN] LID size
        VappArchiveNvramSource::SourceModeEnum mode,// [IN] Read or write?
        VfxObject *parentObj                        // [IN] Parent object
    ) const;

    // Create the system archive.
    // RETURNS archive.
    VfxArchive *createSysArchive(
        VappArchiveNvramSource::SourceModeEnum mode,// [IN] Read or write?
        VfxObject *parentObj                        // [IN] Parent object
    ) const;

    // Get NVRAM LID for the specified setting ID.
    // RETURNS: NVRAM LID.
    nvram_lid_enum getLid(
        SettingIdEnum settingId     // [IN] Setting ID
    ) const;

    // Get LID size for the specified setting ID.
    // RETURNS: LID size
    VfxS32 getLidSize(
        SettingIdEnum settingId     // [IN] Setting ID
    ) const;

    // Remove all invalid items.
    void removeInvalidItems();

    // Find the index of the slot storing the launcher ID.
    // RETURNS: index
    VfxS32 find(
        const VappLauncherId &id
    );

    // Initialize the system information of this setting provider.
    void initSys();

    // Synchronize the system information of this setting provider to the
    // permanent storage.
    void syncSys();
};

#endif /* defined(__MMI_VUI_LAUNCHER_FACTORY__) */
#endif /* VAPP_LAUNCHER_SETTING_PROVIDER_H */

