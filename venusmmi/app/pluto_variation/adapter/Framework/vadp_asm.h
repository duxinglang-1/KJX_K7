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
 *  vadp_asm.h
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
 *  adapter to pluto ASM
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VADP_ASM_H__
#define __VADP_ASM_H__

#include "string.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vfx_datatype.h"
#include "vfx_sys_memory.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_mem_gprot.h"

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/

// allocate ASM with given ID and size (for cacheable memory)
#define vadpAsmAlloc(_id, _size)   VadpAsm::alloc_int(_id, _size, VFX_FALSE, __FILE__,  __LINE__)

// allocate ASM with given ID and size (for non-cacheable memory)
#define vadpAsmAllocNc(_id, _size)   VadpAsm::alloc_int(_id, _size, VFX_TRUE, __FILE__,  __LINE__)    

// free ASM for given ID and memory pointer
#define vadpAsmFree(_id, _ptr)  VadpAsm::free_int(_id, _ptr, __FILE__, __LINE__)


/***************************************************************************** 
 * Class VadpAsmProperty
 *****************************************************************************/

class VadpAsmProperty : public mmi_frm_asm_property_struct
{
public:
    VadpAsmProperty()
    {
        init();
    }
    virtual ~VadpAsmProperty() {};

    /* initialize to default value */
    void init()
    {
        mmi_frm_asm_property_init(this);
    }

    /* clear to all 0 */
    void clear()
    {
        memset(this, 0, sizeof(mmi_frm_asm_property_struct));
    }
};


/***************************************************************************** 
 * Class VadpAsm
 *****************************************************************************/

#define VADP_ASM_FORCE_PREPARE  MMI_FRM_ASM_F_FORCE_PREPARE

class VadpAsm : public VfxBase
{
public:
    typedef VfxCallback1<
                mmi_frm_asm_evt_struct *
                > PrepareCb;

    typedef PrepareCb* PrepareHandle;
   
public:
    /*
     * prepare ASM for given id with desired size. 
     * notify prepare callback, cb, when memory is enough or operation is cancelled.
     *
     * PARAMETERS
     *  flag: 
     *  VADP_ASM_FORCE_PREPARE   if memory is not enough, there's no OOM prompt but will still ask APP to quit to release ASM.
     * 
     * RETURNS
     *  prepare handle that can be used to cancel prepare if necessary
     */
    static PrepareHandle prepare(VfxU16 id, VfxU32 size, PrepareCb cb, VfxU32 flag)
    {
        PrepareHandle cbPtr;
        VFX_SYS_NEW_EX(cbPtr, PrepareCb, (cb));
        mmi_frm_asm_prepare(id, size, (mmi_proc_func)&VadpAsm::static_prepareCallback, cbPtr, (mmi_frm_asm_prepare_flag_type)flag);
        return cbPtr;;
    }

    // cancel prepare with given id and prepare handle
    static void cancelPrepare(VfxU16 id, PrepareHandle h)
    {
        mmi_frm_asm_cancel_prepare(id, (mmi_proc_func)&VadpAsm::static_prepareCallback, h);
    }

    /* DOM-NOT_FOR_SDK-BEGIN */
    static void *alloc_int(VfxU16 id, VfxU32 size, VfxBool isFrameBuffer, VfxChar* file,  VfxU32 line)
    {
        if (isFrameBuffer == MMI_TRUE)
            return mmi_frm_asm_alloc_nc_r(id, size);
        else
            return mmi_frm_asm_alloc_r(id, size);
    }
    /* DOM-NOT_FOR_SDK-END */

    /* DOM-NOT_FOR_SDK-BEGIN */
    static void free_int(VfxU16 id, void *ptr, VfxChar *file, VfxU32 line)
    {
        mmi_frm_asm_free_int(id, ptr, file, line);
    }
    /* DOM-NOT_FOR_SDK-END */

    /* 
     * set ASM related property for given APP instance
     * 
     * EXAMPLE:
     * <code>
     * VadpAsmProperty p;
     * p.f_hide_in_oom          = 1;    // do not show this APP in OOM list
     * p.f_skip_size_checking   = 1;    // skip size checking for this APP, i.e. APP can allocate memory larger than configured in its res file.
     * VadpAsm::setProperty(getGroupId(), p);
     * </code>
     */
    static VfxBool setProperty(VfxU16 id, VadpAsmProperty &p)
    {
        return (mmi_frm_asm_set_property((mmi_id)id, (mmi_frm_asm_property_struct *)&p) == MMI_TRUE);
    }

    /* 
     * get ASM related property for given APP instance
     * 
     * EXAMPLE:
     * <code>
     * VadpAsmProperty p;
     * VadpAsm::getProperty(getGroupId(), p);
     * p.f_hide_in_oom          = 1;    // do not show this APP in OOM list
     * VadpAsm::setProperty(getGroupId(), p);
     * </code>
     */
    static VfxBool getProperty(VfxU16 id, VadpAsmProperty &p)
    {
        return (mmi_frm_asm_get_property((mmi_id)id, (mmi_frm_asm_property_struct *)&p) == MMI_TRUE);
    }

    // check if desired size is available to allocate in ASM pool or not
    static VfxBool checkEnough(VfxU16 id, VfxU32 size)
    {
        return (mmi_frm_asm_check_enough(id, size) != 0);
    }

    // get max. size available to allocate in ASM pool
    static VfxU32 getMaxAllocSize(VfxU16 id)
    {
        return mmi_frm_asm_get_max_alloc_size_r(id);
    }

    // get ASM pool size
    static VfxU32 getPoolSize()
    {
        return mmi_frm_asm_get_pool_size_r();
    }

    // check if given pointer is a valid memory block from ASM pool
    static VfxBool isValidBlock(void *ptr)
    {
        return (mmi_frm_asm_is_valid_block_r(ptr) != 0);
    }

    /* check if all ASM memory blocks are valid. 
       This function takes a lot of computing time and it should NOT be used in normal case.
       It can be inserted to application code when debugging to locate hard-to-find memory corruption issue. */
    static void checkIntegrity()
    {
        mmi_frm_asm_check_integrity_r();
    }

private:
    static mmi_ret static_prepareCallback(mmi_event_struct *evt)
    {
        PrepareCb *cbPtr = (PrepareCb *)evt->user_data;
        if (cbPtr)
        {
            cbPtr->invoke((mmi_frm_asm_evt_struct *)evt);
            VFX_DELETE(cbPtr);
        }
        return MMI_RET_OK;
    }
};

#endif // __VADP_ASM_H__

