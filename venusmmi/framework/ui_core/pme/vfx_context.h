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
 *  vfx_context.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Framework VfxContext Class
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_CONTEXT_H__
#define __VFX_CONTEXT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxObject
#include "vfx_object.h"

#include "vfx_class_info.h"
#include "vfx_datatype.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

// The VfxContext registered name
#define VFX_CONTEXT_CLASS_NAME          "Context"

#define VFX_CONTEXT_SIZE_NO_CHANGE       0x00    

// The Venus system global memory context 
#define VFX_SYS_GLOBAL_CONTEXT          VFX_OBJ_GET_INSTANCE(VfxSysGlobalContext)


/***************************************************************************** 
 * Class VfxContext
 *****************************************************************************/

/*
 * Class VfxContext represents a memory pool for application.
 */
class VfxContext : public VfxObject
{
    VFX_DECLARE_CLASS(VfxContext);

// Constructor / Destructor
public:
    // Default Constructor
    VfxContext();    
    // Destructor
    virtual ~VfxContext();

// Method
public:
    
    // Assign a memory buffer to the context
    void assignPool(
        mmi_id app_id,  // [IN] app id / group id
        VfxU8 *buf,     // [IN] Pointer to memory buffer
        VfxU32 bufSize, // [IN] The size of memory buffer, in bytes
        VfxBool logFlag = VFX_FALSE // [IN] The context pool loggging flag
    );
    // Assign a memory buffer to the context
    void assignPool(
        VfxU8 *buf,     // [IN] Pointer to memory buffer
        VfxU32 bufSize, // [IN] The size of memory buffer, in bytes
        VfxBool logFlag = VFX_FALSE // [IN] The context pool loggging flag
    );

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Assign an allocator to the context
    void assignPoolWithAllocator(
        vrt_allocator_handle allocator, // [IN]
        VfxBool logFlag = VFX_FALSE // [IN] The context pool loggging flag
    );
#endif

    // Assign a slmm memory buffer in asm to the context
    void assignPoolWithSlmm(
        mmi_id app_id,              // [IN] app id / group id
        U32 mem_size,               // [IN] memory size
        VfxBool logFlag = VFX_FALSE // [IN] The context pool loggging flag
    );
    // Get app_id's shrink size
    VfxU32 getShrinkSize(mmi_id app_id)
    {
        return onGetShrinkSize(app_id);
    }
    // virtual function to get shrink size
    virtual VfxU32 onGetShrinkSize(mmi_id app_id)
    {
        #if !defined __MMI_USE_MMV2__
        VFX_ASSERT(0);
    #endif
        return VFX_CONTEXT_SIZE_NO_CHANGE;
    }
    // 
    VfxBool checkEnlargeHeapPrepare()
    {
        return onEnlargeHeapPrepare();
    }
	virtual VfxBool onEnlargeHeapPrepare()
    {
	#if !defined __MMI_USE_MMV2__
        VFX_ASSERT(0);
    #endif
        return VFX_TRUE;
    }
    // Enlarge heap size in backward active case. return 1 : success ; 0: async enlarge
    VfxU32 backwardEnlargeHeapSize(
        mmi_id app_id    // [IN] app id / group id
    );
    // Enlarge heap size.  return 1 : success ; 0: async enlarge
    VfxU32 enlargeHeapSize(
        mmi_id app_id,       // [IN] app id / group id
        mmi_proc_func func,  // [IN] callback
        void *user_data,     // [IN] user_data
        VfxU32 flag          // [IN] flag
    );
    // shrink heap size. return 1 : success ; 0: fail
    VfxU32 shrinkHeapSize(
        mmi_id app_id    // [IN] app id / group id
    );    
    // Return the pointer to memory buffer
    //
    // RETURNS: The pointer to memory buffer
    VfxU8 *getBuf() const
    {
        return m_buf;
    }

    // Return the size of memory buffer
    //
    // RETURNS: The size of memory buffer
    VfxU32 getBufSize() const
    {
        return m_bufSize;
    }

    // Statistics the memory pool state of the context
    void statistics(
        vfx_sys_mem_pool_status_struct &output  // [OUT] The statistics ourput 
    );

// Override
public:
    // IVfxAllocatable interfaces    
    virtual vrt_allocator_handle getAllocator();

// Override
protected:
    void onAfterDeinit();    
    virtual void onObjectNotify(VfxId eventId, void *userData);
    
protected:
    vrt_allocator_handle m_allocatorHandle;         // handle of memory pool
    
    VfxU8 *m_buf;                                   // start buffer pointer of memory pool
    VfxU32 m_bufSize;                               // size of memory pool
    

    // Create memory pool with a memory buffer
    void createPool(
        mmi_id app_id,      // [IN] app id / group id
        VfxU8 *buf,         // [IN] memory buffer pointer
        VfxU32 bufSize,     // [IN] size of memory buffer
        VfxBool logFlag = VFX_FALSE // [IN] The context pool loggging flag
    );
    void createPoolWithSlmm(
        mmi_id app_id,              // [IN] app id / group id
        U32 mem_size,               // [IN] memory size
        VfxBool logFlag = VFX_FALSE // [IN] The context pool loggging flag
    );
    // Delete memory pool
    void deletePool();
};

/***************************************************************************** 
 * Class VfxSysGlobalContext
 *****************************************************************************/

/*
 * Class VfxSysGlobalContext is an allocatable instance used for AP creating VfxContext.
 */

class VfxSysGlobalContext : public VfxContext
{
    VFX_DECLARE_CLASS(VfxSysGlobalContext);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VfxSysGlobalContext);

public:
    // Override
    // IVfxAllocatable interfaces
    virtual vrt_allocator_handle getAllocator();
};


/***************************************************************************** 
 * Class VfxSubContext
 *****************************************************************************/

class VfxSubContext : public VfxContext
{
    VFX_DECLARE_CLASS(VfxSubContext);

public:
    VfxSubContext();

    void setContext(VfxContext *parent);

    virtual vrt_allocator_handle getAllocator();

protected:
    virtual void onDeinit();

private:
    vrt_allocator_handle m_allocator;
};


/***************************************************************************** 
 * Class VfxTmpContext
 *****************************************************************************/

#define VFX_CREATE_TMP_CONTEXT(_ptr) \
    VfxTmpContext __tmpVfxTmpContext; \
    (_ptr) = &__tmpVfxTmpContext

class VfxTmpContext : public VfxBase, public IVfxAllocatable
{
public:
    VfxTmpContext();
    ~VfxTmpContext();

public:
    virtual vrt_allocator_handle getAllocator();

private:
    vrt_allocator_handle m_allocator;
};

#endif /* __VFX_CONTEXT_H__ */

