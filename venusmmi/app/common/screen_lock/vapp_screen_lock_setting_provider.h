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
 *  vapp_screen_lock_setting_provider.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the setting provider of the screen lock.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_SCREEN_LOCK_SETTING_PROVIDER_H
#define VAPP_SCREEN_LOCK_SETTING_PROVIDER_H

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "custom_screen_lock_config.h"

#include "vfx_uc_include.h"
#include "vapp_archive_nvram.h"
#include "vapp_screen_lock_primitive.h"


/*****************************************************************************
 * System Setting Element
 *****************************************************************************/

typedef struct
{
    VfxBool isUsed;
    VfxBool isDefault;
    VappScreenLockId id;
} VappScreenLockSettingElem;


/*****************************************************************************
 * Setting Provider
 *****************************************************************************/

class VappScreenLockSettingProvider : public VfxObject
{
    VFX_DECLARE_CLASS(VappScreenLockSettingProvider);

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappScreenLockSettingProvider);

// Enum
public:
    // This enum defines the setting ID.
    //
    // SEE ALSO: createArchiveReader, createArchiveWriter
    enum SettingIdEnum
    {
        // Wallpaper setting ID
        SETTING_ID_WALLPAPER,

        // End of setting ID enum
        SETTING_ID_END_OF_ENUM
    };

// Constructor / Destructor
public:
    // Default constructor
    VappScreenLockSettingProvider();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Signal
public:
    // This signal is emitted when the default screen lock is changed.
    VfxSignal0 m_signalDefaultScreenLockChanged;

// Method
public:
    // This function gets the default screen lock.
    // RETURNS: Screen lock ID.
    VappScreenLockId getDefaultScreenLock();

    // This functions sets the default screen lock.
    void setDefaultScreenLock(
        const VappScreenLockId &id      // [IN] Screen lock ID
    );

    // This function gets the screen lock if anyone is available. Specifically,
    // it gets the first screen lock from the native screen lock factory.
    // RETURNS: screen lock ID.
    VappScreenLockId getScreenLockIfAny() const;

    // This function creates an archive reader for the specified setting ID.
    // The archive is for the current default screen lock.
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

    // This function creates an archive writer for the specified setting ID.
    // The archive is for the current default screen lock.
    //
    // IMPORTANT. PLEASE READ ME.
    //
    // 1) You can't create archive reader and writer at the same time. Assert
    //    will fail if this rule is violated.
    // 2) Before you create the next archive writer, you must close any existing
    //    archive writer. Assert will fail if this rule is violated.
    //
    // SEE ALSO: createArchiveReader
    VfxArchive *createArchiveWriter(
        SettingIdEnum settingId,        // [IN] Setting ID
        VfxObject *parentObj            // [IN] Parent object
    );

// Enum
private:
    enum
    {
        GUARD_PATTERN = 0xBABEC0DE,
        SCREEN_LOCK_NUM = CUSTOM_SCREEN_LOCK_MAX_NUM
    };

// Variable
private:
    VappScreenLockSettingElem m_elem[SCREEN_LOCK_NUM];

#if defined(__MMI_VUI_SCREEN_LOCK_MRE__)
// Implementation
private:
    // This function is the main event hanndler.
    static mmi_ret eventProc(
        mmi_event_struct *evt   // [IN] Event structure
    );

    void handleUninstall(
        const VfxChar *appName
    );
#endif /* defined(__MMI_VUI_SCREEN_LOCK_MRE__) */

// Implementation
private:
    // This function creates an archive using the system archive file.
    // RETURN: archive.
    VfxArchive *createArchive(
        nvram_lid_enum lid,
        VfxS32 lidIndex,
        VfxS32 lidSize,
        VappArchiveNvramSource::SourceModeEnum mode,    // [IN] Source mode
        VfxObject *parentObj                            // [IN] Parent object
    ) const;

    VfxArchive *createSysArchive(
        VappArchiveNvramSource::SourceModeEnum mode,
        VfxObject *parentObj
    ) const;

    nvram_lid_enum getLid(
        SettingIdEnum settingId
    ) const;

    VfxS32 getLidSize(
        SettingIdEnum settingId
    ) const;

    VfxS32 find(
        const VappScreenLockId &id
    );

    void initSys();

    void syncSys();
};

#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) */
#endif /* VAPP_SCREEN_LOCK_SETTING_PROVIDER_H */

