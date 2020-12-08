/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vfx_app_scr.h
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
#ifndef __VFX_APP_SCR_H__
#define __VFX_APP_SCR_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

extern "C"
{
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_utility_gprot.h"
}

#include "vfx_datatype.h"
#include "vfx_screen.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_archive.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_SCR_HISTORY_NODE_DELETE_FORBIDDEN_FLAG  0x0001
#define VFX_SCR_HISTORY_NODE_SKIP_DEL_CHECK_FLAG    0x0002
#define VFX_SCR_HISTORY_NODE_CLOSING_FLAG           0x0004
#define VFX_SCR_HISTORY_NODE_SERIALIZE_FLAG         0x0008

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Predefined class
class VfxApp;
class VfxAppScrInitData;

/***************************************************************************** 
 * Class VfxAppScr
 *****************************************************************************/

/*
 * VfxAppScr. This class is a Venus wrapper of an Pluto screen. 
 * Like VfxApp represent an Pluto group, VfxAppScr represent an Pluto screen.
 * Therefore, it will have an Pluto screen id.
 */
class VfxAppScr : public VfxScreen
{
    friend class VfxApp;

    VFX_DECLARE_CLASS(VfxAppScr);

/* DOM-NOT_FOR_SDK-BEGIN */
// Declaration
private:
    // This node is keep in history by screen user-data.
    class HistoryNode : public VfxBase
    {
    public:
        HistoryNode();
        ~HistoryNode();

        mmi_id          screenId;
        VfxU16          flag;
        VfxApp          *app;
        VfxWeakPtr<VfxAppScr> screen;
        VfxClassInfo    *classInfo;
        // TODO: serialize data
        VfxU8           *serializeData;
        VfxS32          serializeDataSize;
    };
/* DOM-NOT_FOR_SDK-END */

// Constructor / Destructor
public:
    // Constructor
    VfxAppScr();
    
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    void onBeforeDeinit();
    virtual void onObjectNotify(VfxId eventId, void *userData);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

// Method
public:
    // Return the app which associated with the screen
    VfxApp* getApp() const;

    // Show the screen as active screen.
    // RETURNS: the screen id of this screen
    mmi_id show();

    // Close the screen itself. Please use this API to close screen. Dont use
    // VFX_OBJ_CLOSE() to close screen directly.
    void exit();

    // Close the screen itself via emulating User presses back key.
    void back();

    // Check if the screen is at top most. 
    // RETURNS: VFX_TRUE if the screen is active.
    VfxBool isActive();

    // Check if the screen is active or in history.
    // Usually, this API is used to check whether this screen has shown before.
    // RETURNS: VFX_TRUE if the screen has been displayed.
    VfxBool isShown();
    
    // Get the group id of this screen
    // RETURNS: group id of this screen
    mmi_id getGroupId() const;

    // Get the screen ID, the same as show() returned.
    // RETURNS: screen id of this screen
    mmi_id getScreenId() const;

    // Check if allowing to delete screen? The default implementation return true.
    // RETURNS: VFX_TRUE (default) if screen can be deleted.
    virtual VfxBool getAllowDelete() const;

    // Set whether allow to delete screen.
    void setAllowDelete(VfxBool allowDelete);

    void setCABCMode(mmi_frm_cabc_mode_enum mode);
    void resetCABCMode();
    mmi_frm_cabc_mode_enum getCABCMode() const;

// Overridable    
protected:
    // Call when the screen is serialized and will be restored to active again.
    // Read data from archive and set them back again.
    // See also onSerialize()
    virtual void onRestore(
        VfxArchive &ar  // [IN] the archive object that store previous saved data
    );

    // Call when the screen will be put to history. If returning VFX_TRUE (serialized),
    // The screen will be closed and the archive object will be saved separatedly.
    // The archive object will be used again for restoring.
    // See also onRestore()
    // RETURNS: VFX_TRUE if the screen would like to serialize itself.
    //          VFX_FALSE if the screen want to keep alive even in history.
    virtual VfxBool onSerialize(
        VfxArchive &ar  // [OUT] archive that stores data, you can write data into it.
    );

    // Notify for back key process, the default implementation is exit() self.
    // Note. If you dont want screen to close, override it and dont call base class' 
    // implementation 
    virtual void onBack();

    // General Screen Proc. You can handle all events from this API.
    // RETURNS: MMI_RET_OK if the event is handled.
    virtual mmi_ret onProc(
        mmi_event_struct *evt   // [IN] event to be handled
    );

    // Obsolete, please use onProc to replace proc
    virtual mmi_ret proc(mmi_event_struct *evt);

/* DOM-NOT_FOR_SDK-BEGIN */
// Variable
protected:
    mmi_id                      m_screenId;

    VfxU8                       m_CABCMode;

    HistoryNode                 *m_pHistoryNode;
    VfxAppScrInitData           *m_pInitData;

    static VfxU16               m_nextScrIdToCheck;

// Implementation
protected:
    
    static mmi_ret static_proc(mmi_event_struct *evt);
    static void static_exit(mmi_scrn_essential_struct* scrn_info);
    static void static_entry(mmi_scrn_essential_struct* scrn_info);
    
// Override
public:
    virtual mmi_ret processProc(mmi_event_struct *evt);
protected:
    virtual VfxBool processSerialize(VfxArchive &ar);
    virtual void processRestore(VfxArchive &ar);
    virtual void processEnter(VfxBool isBackward);
    virtual void processExit(VfxBool isBackward);

private:
    VfxBool serialize(VfxBool isAutoClose);
    void    restore();

    void    updateCABCMode();

    static HistoryNode  *createHistoryNode(VfxApp *app, VfxClassInfo *classInfo);
    static mmi_id       getUnusedScreenId(VfxApp *app);

    static mmi_ret static_callerProc(mmi_event_struct *evt);

    friend mmi_ret vfxSetCuiCallerScr(mmi_id cuiId, VfxAppScr* scr);

/* DOM-NOT_FOR_SDK-END */

};

// Helper function. You can use this API to make an CUI notify result to an 
// VfxAppScr, instead of an VfxApp.
mmi_ret vfxSetCuiCallerScr(
    mmi_id cuiId,   // [IN] the ID of CUI
    VfxAppScr* scr  // [IN] the screen that receive CUI events.
);

#endif /* __VFX_APP_BASE_H__ */

