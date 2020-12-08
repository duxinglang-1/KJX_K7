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
 *  vfx_app_launcher.h
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
#ifndef __VFX_APP_LAUNCHER_H__
#define __VFX_APP_LAUNCHER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
// by RHR //#include "ui_core\base\vfx_base.h"
// by RHR //#include "ui_core\pme\vfx_pme.h"
// by RHR //#include "vadp_mmi_frm.h"
//#include "vfx_app.h"

extern "C"
{
#include "MMIDataType.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"    
}

#include "vfx_config.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_context.h"
#include "vfx_app.h"

/* DOM-NOT_FOR_SDK-BEGIN */
////////////////////////////////////////////////////////////////
// only for test, should be app's own resource base.

#define APP1_BASE   FW_TEST1
#define APP2_BASE   FW_TEST2
#define APP3_BASE   FW_TEST3
#define CUI1_BASE   FW_TEST4

#ifdef __AFX_RT_TEST__
//#include "mmi_rp_app_data.h"

#define APP1_HEAP_SIZE      mmi_res_get_app_base_mem_size(FW_TEST1)
#define APP2_HEAP_SIZE      mmi_res_get_app_base_mem_size(FW_TEST2)
#define APP3_HEAP_SIZE      mmi_res_get_app_base_mem_size(FW_TEST3)
#define CUI1_HEAP_SIZE      mmi_res_get_app_base_mem_size(FW_TEST4)

#define APP1_POOL_SIZE      (mmi_res_get_app_base_mem_size(FW_TEST1) + mmi_res_get_app_fg_mem_size(FW_TEST1))
#define APP2_POOL_SIZE      (mmi_res_get_app_base_mem_size(FW_TEST2) + mmi_res_get_app_fg_mem_size(FW_TEST2))
#define APP3_POOL_SIZE      (mmi_res_get_app_base_mem_size(FW_TEST3) + mmi_res_get_app_fg_mem_size(FW_TEST2))
#endif /* __AFX_RT_TEST__ */

// resource related above
////////////////////////////////////////////////////////////////
/* DOM-NOT_FOR_SDK-END */

class VfxApp;

/***************************************************************************** 
 * Define
 *****************************************************************************/

// Used by VfxAppLauncher::findApp, find only normal App
#define VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG   0x01
// Used by VfxAppLauncher::findApp, find only background App
#define VFX_APP_LAUNACHER_FIND_APP_BG_FLAG       0x02

// Flag used to indicate the find range of VfxAppLauncher::findApp
// It is a bitmask of VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 
// VFX_APP_LAUNACHER_FIND_APP_BG_FLAG, etc...
typedef VfxU32 VfxAppLauncherFindAppFlag;

/* DOM-NOT_FOR_SDK-BEGIN */
#define VFX_APP_LAUNCHER_RES_ID_MAX  (100)

typedef void (*VfxAppContextCbType)(void *memPtr, void *userData);
/* DOM-NOT_FOR_SDK-END */

typedef enum {
    VFX_APP_LAUNCHER_RESULT_OK,
    VFX_APP_LAUNCHER_RESULT_CANCEL
} VfxAppLauncherResultEnum;

typedef void (*VfxAppLauncherResult)(VfxAppLauncherResultEnum result, void *userData);

// Flag used to indicate the placement of new app.
typedef enum {
    VFX_APP_LAUNCHER_PLACE_DEFAULT,
    
    VFX_APP_LAUNCHER_PLACE_TOP = VFX_APP_LAUNCHER_PLACE_DEFAULT,
    VFX_APP_LAUNCHER_PLACE_BOTTOM,
    VFX_APP_LAUNCHER_PLACE_BEFORE,
    VFX_APP_LAUNCHER_PLACE_AFTER,

    VFX_APP_LAUNCHER_PLACE_END_OF_ENUM,

} VfxAppLauncherPlacementEnum;


typedef enum {
    VFX_APP_LAUNCHER_DYNAMIC_HEAP_DISABLE = (1<<0),
    VFX_APP_LAUNCHER_DYNAMIC_HEAP_AT_INACTIVE = (1<<1),
    VFX_APP_LAUNCHER_DYNAMIC_HEAP_AT_HIDDEN = (1<<2),
    VFX_APP_LAUNCHER_DYNAMIC_HEAP_END_OF_ENUM
} VfxAppLauncherDynHeapEnum;

/***************************************************************************** 
 * Class VfxAppLauncherParam
 *****************************************************************************/

class VfxAppLauncher;

/*
 *  VfxAppLauncherParam. Helper class to wrapper launch parameters
 */
class VfxAppLauncherParam : public VfxBase
{
    friend class VfxAppLauncher;
public:
    // Constructor
    VfxAppLauncherParam(
        mmi_id appBaseId,               // [IN] app id
        const VfxClassInfo *classInfo,  // [IN] class info
        mmi_id callerId = GRP_ID_ROOT   // [IN] caller group id
    );

    // set memory source from a outside context    
    void setMemSource(
        VfxContext *context,            // [IN] context
        VfxBool doPrepare = VFX_FALSE   // [IN] need to prepare or not
    );

    // set memory source from a outside buffer
    void setMemSource(
        void *buffer,                   // [IN] buffer
        VfxU32 bufferSize,              // [IN] size of buffer
        VfxAppContextCbType callback,   // [IN] callback when the app is terminated 
        void *userData                  // [IN] userdata of callback
    );

    // set size of memory, it will be prepared from ASM pool
    void setMemSource(
        VfxU32 heapSize                 // [IN] size of heap
    );

    // set placement of apps.
    void setPlacement(
        VfxAppLauncherPlacementEnum placement,  // [IN] app placement
        mmi_id hint = GRP_ID_INVALID            // [IN] place hint
    );

    // set launch arguments
    void setArgument(
        void *arg,      // [IN] pointer of argument
        VfxU32 argSize  // [IN] size of argument      
    );
    
    // set Heap offset
    void setHeapOffset(
        VfxU32 HeapOffset // [IN] size of Heap Offset argument
    );
    
    // set Memory Priority
    void setMemPriority(
        VfxU32 MemPriority // [IN] Priority of Memory allocation
    );

    // enable/disable force prepare, It only works when memory source is from ASM
    void setForcePrepare(
        VfxBool value   // [IN] on/off
    );

    /* enable/disable Context Logging mechanism, It only works when the context is created by VfxAppLauncher.
       if the context pool is created by (app) user, user should set the logFlag of 
       VfxContext::assignPool/createPool() by itself*/ 
    void setContextLogging(
        VfxBool value   // [IN] on/off
    );
    
    /* set the trigger-time of Dynamic Heap mechanism*/ 
    void setDynHeap(VfxAppLauncherDynHeapEnum flag);

    // set launcher result callback
    void setLauncherResultCb(
        VfxAppLauncherResult cb, // [IN] callback when the launch of app is successful or cancelled
        void* userData           // [IN] userdata of callback
    );
/* DOM-NOT_FOR_SDK-BEGIN */
private:
    mmi_id              m_appBaseId;   // app base
    mmi_id              m_callerId;    // caller group id
    const VfxClassInfo  *m_classInfo;  // app class
    
    void                *m_heap;
    VfxU32              m_heapSize;
    VfxAppContextCbType m_callback;
    void                *m_callbackData; 
    VfxAppLauncherResult m_launcherResultCb;
    void                *m_launcherResultUserData;

    VfxContext          *m_context;
    
    void                *m_arg;        // argument
    VfxU32              m_argSize;
    VfxU32              m_HeapOffset;

    VfxU32              m_MemPriority;

    VfxAppLauncherPlacementEnum m_placement;
    mmi_id              m_placehint;

    VfxU16              m_flags;
/* DOM-NOT_FOR_SDK-END */

};

/***************************************************************************** 
 * Class VfxAppLauncher
 *****************************************************************************/

/*
 *  VfxAppLauncher. Helper class to create an Venus app (VfxApp)
 */
class VfxAppLauncher : public VfxObject
{
    VFX_DECLARE_CLASS(VfxAppLauncher);

    friend class VfxApp;

public:
// Constructor / Destructor
    VfxAppLauncher();
    virtual ~VfxAppLauncher();

// Overridable
public:
    virtual void onContextAllocationFail(mmi_frm_appmem_event_type_enum reason);

// static Method
public:
    // launch an application with default setting. The most common used version.
    // RETURNS: group id of app
    static mmi_id launch(
        mmi_id appBaseId,           // [IN] app id
        VfxClassInfo *classInfo,    // [IN] class info
        mmi_id callerId,            // [IN] caller id
        void *arg = NULL,           // [IN] argument
        VfxU32 argSize = 0,         // [IN] size of argument
        VfxBool contextLogFlag = VFX_FALSE// [IN] Context Logging Flag, default disable
    );

    // launch an application with given heap size
    // RETURNS: group id of app
    static mmi_id launchWithAsmSize(
        mmi_id appBaseId,           // [IN] app id
        VfxClassInfo *classInfo,    // [IN] class info
        mmi_id callerId,            // [IN] caller id
        VfxU32 heapSize,            // [IN] given heap size
        void *arg = NULL,           // [IN] argument
        VfxU32 argSize = 0,         // [IN] size of argument
        VfxBool contextLogFlag = VFX_FALSE// [IN] Context Logging Flag, default disable
    );

    // launch an application with a given outside heap buffer
    // RETURNS: group id of app
    static mmi_id launchWithMem(
        mmi_id appBaseId,           // [IN] app id
        VfxClassInfo *classInfo,    // [IN] class info
        mmi_id callerId,            // [IN] caller id
        void *heap,                 // [IN] heap buffer
        VfxU32 heapSize,            // [IN] size of buffer
        VfxAppContextCbType callback, // [IN] callback when app terminate, you
                                    // can free the buffer if necessary
        void *userData = NULL,      // [IN] userdata of callback
        void *arg = NULL,           // [IN] argument
        VfxU32 argSize = 0,         // [IN] size of argument
        VfxBool contextLogFlag = VFX_FALSE// [IN] Context Logging Flag, default disable
    );

    // launch an application with given context
    // RETURNS: group id of app
    static mmi_id launchWithCtx(
        mmi_id appBaseId,           // [IN] app id
        VfxClassInfo *classInfo,    // [IN] class info
        mmi_id callerId,            // [IN] caller id
        VfxContext *ctx,            // [IN] context
        void *arg = NULL,           // [IN] argument
        VfxU32 argSize = 0          // [IN] size of argument
    );

    // launch an application with param struct
    // RETURNS: group id of app
    static mmi_id launchEx(
        const VfxAppLauncherParam& param    // [IN] parameters
    );

    // create a CUI
    // RETURNS: group id of cui
    static mmi_id createCui(
        mmi_id appBaseId,           // [IN] app id
        VfxClassInfo *classInfo,    // [IN] class info
        mmi_id parentId,            // [IN] parent id
        void *arg = NULL,           // [IN] argument
        VfxU32 argSize = 0,          // [IN] size of argument
        VfxBool contextLogFlag = VFX_FALSE// [IN] Context Logging Flag, default disable
    );
    
    // create a CUI with param struct
    // RETURNS: group id of cui
    static mmi_id createCuiEx(
        const VfxAppLauncherParam& param    // [IN] parameters
    );

    // start to run a CUI after it's created
    static void runCui(
        mmi_id groupId  // [IN] cui id, returned by createCui
    );

    // close an application
    static void terminate(
        mmi_id gid  // [IN] group id of app/cui to be terminated
    );

    // get object pointer by group id
    // RETURNS: pointer, NULL if not found.
    static VfxObject *getObject(mmi_id gid);

    // query if an app exist
    // Note that this function returns VfxApp instance only. If the app is still a VfxAppLauncher
    // object, NULL will be returned.
    // RETURNS: app pointer, NULL if not found
    static VfxApp *findApp(
        mmi_id appBaseId,               // [IN] app id
        const VfxClassInfo *classInfo,  // [IN] class info
        VfxAppLauncherFindAppFlag flag, // [IN] find range, only normal apps, 
                                        //      or also background apps
        VfxS32 skipN = 0                // [IN] skip first N match and return N+1 matched
    );

    // kill all the apps (if existence) with the given classInfo/
    // Note that this function could kill both VfxAppLauncher and VfxApp instances. It's useful
    // to use this function to guarantee the singleton of an application.
    static void killApp(
        mmi_id appBaseId,               // [IN] app id
        const VfxClassInfo *classInfo,  // [IN] class info
        VfxAppLauncherFindAppFlag flag  // [IN] kill range, only normal apps, 
                                        //      or also background apps
    );

// Method
public:
    // get application associated screen group id
    mmi_id getGroupId(void);

/* DOM-NOT_FOR_SDK-BEGIN */
// Implementation
private:
    mmi_id          m_groupId;
    mmi_id          m_dummyGroupId;
    const VfxClassInfo *m_classInfo;

    void            *m_arg;
    VfxU32          m_argSize;

    void            *m_heap;
    VfxU32          m_heapSize;    /* required app-ASM size */
    VfxU32          m_HeapOffset;

    VfxU32					m_MemPriority;

    VfxContext      *m_context;

    VfxAppContextCbType m_freeContextMemCb;
    void            *m_freeContextMemUserData;

    VfxAppLauncherResult m_launcherResultCb;
    void            *m_launcherResultUserData;

    VfxAppLauncherPlacementEnum m_placement;
    mmi_id          m_placeHint;

    VfxU16          m_flags;

private:
    VfxBool createContext(VfxBool isCui = VFX_FALSE);
    void    launchCtxSizePrepare(VfxContext *context, U32 flag);
    void    onContextReady(VfxContext *context, VfxBool isCui = VFX_FALSE, VfxBool needToFreeCtx = VFX_TRUE);
    void    saveLaunchParam(const VfxClassInfo *classInfo, void *arg, VfxU32 argSize);

// Static function
private:
    static VfxU32   getHeapSize(mmi_id appId);
    static VfxU32   getFgSize(mmi_id appId);
    static VfxU32   getBaseSize(mmi_id appId);

    static mmi_ret  static_proc(mmi_event_struct *evt);
    static mmi_id   static_launchByMem(const VfxAppLauncherParam &param);
    static mmi_id   static_launchByContext(const VfxAppLauncherParam &param);
    static mmi_ret  static_launchByContext_proc(mmi_event_struct *evt);

    static mmi_id   static_create(const VfxAppLauncherParam& param);
    static void     static_run(mmi_id groupId, VfxBool isCui);
    
    static mmi_id   static_genId(mmi_id appBaseId); // gen group/screen id based on given appBaseId
    static void     static_freeId(mmi_id id);
    static void     static_freeContextMemCb(void *memPtr, void *userData);

    static mmi_ret  static_postLaunch(mmi_event_struct *evt);
    static mmi_ret  static_postLaunchCtx(mmi_event_struct *evt);

// Static varitables
private:
    static mmi_id   s_allocatedId[VFX_APP_LAUNCHER_RES_ID_MAX];
    static VfxU32   s_firstEmptyIdxBeyondUsed;
/* DOM-NOT_FOR_SDK-END */
    
};

/* DOM-NOT_FOR_SDK-BEGIN */
// Weak Pointer Type Define
typedef VfxWeakPtr <VfxAppLauncher> VfxAppLauncherWeakPtr;
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
*  Class VfxAppContext
*****************************************************************************/


/* DOM-NOT_FOR_SDK-BEGIN */
class VfxAppContext : public VfxContext
{
    VFX_DECLARE_CLASS(VfxAppContext);

public:
    VfxAppContext() : m_freeMemCallback(NULL), m_userData(NULL) {};
    virtual ~VfxAppContext() {};

public:
    void setFreeContextMemCallback(VfxAppContextCbType cb, void *userData);

protected:
    void onAfterDeinit();
    virtual void onObjectNotify(VfxId eventId, void *userData);

#if defined(__MMI_USE_MMV2__)
    virtual VfxU32 onGetShrinkSize(mmi_id app_id);
#endif

private:
    VfxAppContextCbType m_freeMemCallback;
    void *m_userData;
};
/* DOM-NOT_FOR_SDK-END */

#endif /* __VFX_APP_LAUNCHER_H__ */

