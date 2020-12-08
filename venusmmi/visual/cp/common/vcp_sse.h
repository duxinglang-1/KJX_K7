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
 *  vcp_sse.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
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
 * removed!
 *
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
#ifndef __VCP_SSE_TOP_LEVEL_H__
#define __VCP_SSE_TOP_LEVEL_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxControl
#include "vfx_control.h"

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
//#include "vfx_screen.h"
#include "vfx_cpp_base.h"
//#include "vfx_input_event.h"
#include "vfx_context.h"
#include "vfx_weak_ptr.h"

//#include "vfx_top_level.h"

#include "vcp_page_panel.h"

extern "C"
{
#include "gui_effect_oem.h"
#include "AppMgrSrvGprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VCP_SSE_MANAGER_CLASS_NAME        "VcpSseManager"

/***************************************************************************** 
 * Predeclaration
 *****************************************************************************/


/***************************************************************************** 
 * Class VcpSseScreenBuilder
 *****************************************************************************/
class VcpSseScreenBuilder : public VfxObject
{
// Constructor / Destructor
public:
    // Default constructor
    VcpSseScreenBuilder(){};

public:
    virtual void onSnapshot(VfxU8 *buffer) = 0;
    virtual void onBuildScreen(VfxFrame *frame, VfxU8 *buffer) = 0;
};


/***************************************************************************** 
 * Class VcpSseSnapShotScreenBuilder
 *****************************************************************************/
class VcpSseSnapShotScreenBuilder : public VcpSseScreenBuilder
{
// Constructor / Destructor
public:
    // Default constructor
    VcpSseSnapShotScreenBuilder(){};

public:
    virtual void onSnapshot(VfxU8 *buffer);
    virtual void onBuildScreen(VfxFrame *frame, VfxU8 *buffer);
};


/***************************************************************************** 
 * Class VcpSseFlattenSnapShotScreenBuilder
 *****************************************************************************/
class VcpSseFlattenSnapShotScreenBuilder : public VcpSseScreenBuilder
{
// Constructor / Destructor
public:
    // Default constructor
    VcpSseFlattenSnapShotScreenBuilder(){};

public:
    virtual void onSnapshot(VfxU8 *buffer);
    virtual void onBuildScreen(VfxFrame *frame, VfxU8 *buffer);
};
 

/***************************************************************************** 
 * Class VcpSseManager
 *****************************************************************************/

class VcpSseManager : public VfxFrame
{
    VFX_DECLARE_CLASS(VcpSseManager);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VcpSseManager);

// Constructor / Destructor
public:
    // Default constructor
    VcpSseManager();

// Framework method, internal used
public:
    // Setup frame size to fit with screen size and bind it to renderer as root frame.
    void setupScenario(gui_sse_scenario_enum scenario);
    void runSse();
    void buildOldScreen();
    void buildNewScreen();
    void setup();
    void setIsPluto(VfxBool value)
    {
        m_isPluto = value;
    }
    void closeSse();

#ifdef __MMI_REDUCED_UI_BUFFER__
    void force_cancel(VfxU8 *mem_ptr);

private:
	  static void asm_free_cb(void *mem_ptr);
    void force_cancel(void);	
#endif /* __MMI_REDUCED_UI_BUFFER__ */	
// Overridable
public:
    // IVfxAllocatable interfaces
    virtual vrt_allocator_handle getAllocator();
    
// Override
protected:
    virtual void onInit();
// Variable
private:
    VfxContext *m_context;
    VfxU8 *m_mem;
    VfxFrame *m_oldScreen;
    VfxFrame *m_newScreen;
    VfxImageSrc m_oldScreenImageSrc;
    VfxImageSrc m_newScreenImageSrc;
    VcpPagePanel *m_pagePanel;

    VcpSseScreenBuilder *m_oldScreenBuilder;
    VcpSseScreenBuilder *m_newScreenBuilder;

    VcpPageEffectType  m_effectType;
    VfxMsec m_duration;
    VcpPageEffectTypeDirection m_direction;
    void *m_data;
    VfxS32 m_dataSize;

    VfxBool m_isPluto;
    VfxBool m_useImageSrc;
#ifdef __MMI_REDUCED_UI_BUFFER__
	VfxU8 *m_oldScreenBuf;
    VfxU8 *m_newScreenBuf;
#endif /* __MMI_REDUCED_UI_BUFFER__ */
};


/***************************************************************************** 
 * Extern Function 
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif
void vcpSseRunSsePluto(void);
void vcpSseRunSse(void);
void vcpSseBuildOldScreen(void);
void vcpSseBuildNewScreen(void);
void vcpSseSetupScenario(gui_sse_scenario_enum scenario);
void vcpSseReset(void);

void vcpSseSetupScenarioByApp(mmi_app_package_name_struct appName);
void vcpSseSetOpen();

#ifdef __MMI_REDUCED_UI_BUFFER__
extern void vcpSseUseSingleBufferModeInVRT(vrt_bool state);
extern vrt_bool vcpSseIsVRTinSingleBufferMode(void);
MMI_BOOL vcpSseIsForcedCancel(void);
#endif /* __MMI_REDUCED_UI_BUFFER__ */

#ifdef __cplusplus
} /* extern "C"*/
#endif 

#endif /* __VCP_SSE_TOP_LEVEL_H__ */

