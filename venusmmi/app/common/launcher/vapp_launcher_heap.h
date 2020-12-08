/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vapp_launcher_heap.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the launcher's heap.
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

#ifndef VAPP_LAUNCHER_HEAP_H
#define VAPP_LAUNCHER_HEAP_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_launcher_def.h"


/*****************************************************************************
 * Launcher Heap
 *****************************************************************************/

class VappLauncherHeap : public VfxObject
{
    VFX_DECLARE_CLASS(VappLauncherHeap);

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappLauncherHeap);

// Constructor / Destructor
public:
    // Default Constructor
    VappLauncherHeap();

// Signal
public:
    // This signal is emitted when we need you to volunteerly free the context.
    // Note that after all the objects are closed, you need to call
    // 'releaseContext'.
    VfxSignal0 m_signalVolunteerFree;

// Method
public:
    // Create the heap context.
    // RETURNS: heap context.
    VfxContext *createContext();

    // Release the heap context.
    void releaseContext();

    // Get the created context. If it's created, return NULL.
    // RETURNS: If existed, return the context; otherwise, return NULL.
    VfxContext *get();

#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
// Variable
private:
    // ASM memory group ID.
    MMI_ID m_asmGid;

    // If we are waiting for the application to release the ASM memory.
    VfxBool m_isWaitForRelease;

    // Heap memory pointer.
    VfxU8 *m_memPtr;

    // ASM context.
    VfxContext *m_asmContext;

// Implementation
private:
    // Create the ASM context.
    // RETURNS: ASM context.
    VfxContext *createAsmContext();

    // Release the ASM context.
    void releaseAsmContext();

// Implementation
private:
    // Allocate memory from ASM pool.
    void *asmMalloc(
        VfxU32 size     // [IN] Size
    );

    // Free the memory.
    void asmFree(
        void *mem       // [IN] Memory pointer
    );

    // Init the ASM memory pool.
    void initAsmMemory();

    // Deinit the ASM memory pool.
    void deinitAsmMemory();

    // This function handles the ASM free request.
    void handleAsmFreeReq();

    // This function handles the ASM events from the framework.
    static mmi_ret onAsmGroupEvent(
        mmi_event_struct *evt   // [IN] Event structure
    );
#endif /* defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__) */
};

#endif /* defined(__MMI_VUI_LAUNCHER_FACTORY__) */
#endif /* VAPP_LAUNCHER_HEAP_H */

