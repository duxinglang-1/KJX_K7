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
 *  vtst_rt_cp_mem_test_main.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  CP memory test main header file
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
#ifndef __VTST_RT_CP_MEM_TEST_MAIN_H__
#define __VTST_RT_CP_MEM_TEST_MAIN_H__

#include "vfx_config.h"


#ifdef __AFX_RT_TEST__

#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vfx_timer.h"
#include "vfx_signal.h"


/***************************************************************************** 
 * Class VtstRtMemTestObj
 *****************************************************************************/

class VtstRtMemTestObj : public VfxFrame
{
// Constructor / Destructor
public:
    VtstRtMemTestObj() {}

// Method
public:
    void startTest()
    {
        VfxTimer *timer;
        VFX_OBJ_CREATE(timer, VfxTimer, this);
        timer->setStartDelay(0);
        timer->start();
        timer->m_signalTick.connect(this, &VtstRtMemTestObj::onTimeOut);

        m_origMemSize = getHeapSize();
        m_diffMemSize = 0;

        testFunc();
    }

    VfxU32 getUsedSize() {return m_diffMemSize;}

// Signal
public:
    VfxSignal0 m_signalEndTest;

// Override
protected:
    virtual void onInit()
    {
        VfxFrame::onInit();

        setSize(getParentFrame()->getSize());
    }

// Overridable
protected:
    virtual void testFunc() {}

// Implementation
private:
    VfxS32 m_diffMemSize;
    VfxS32 m_origMemSize;

    VfxS32 getHeapSize()
    {
        vfx_sys_mem_pool_status_struct memPoolStatistics;
        vrt_allocator_handle allocator = getAllocator();
        vfx_sys_mem_pool_allocator_get_status(allocator, &memPoolStatistics);
        return (VfxS32)memPoolStatistics.used_size;
    }

    void onTimeOut(VfxTimer *timer)
    {
        VfxS32 newSize = getHeapSize();
        m_diffMemSize = newSize - m_origMemSize;
        m_signalEndTest.emit();
    }
};


/***************************************************************************** 
 * Class VtstRtMemTestObj
 *****************************************************************************/

#define VTEST_RT_MEM_TEST_CREATE(_className)                            \
    public:                                                             \
        static inline void *createTestObj(void *parentObj)              \
        {                                                               \
            _className *obj;                                            \
            VFX_OBJ_CREATE(obj, _className, (VfxObject *)parentObj);    \
            return obj;                                              \
        }                                                               \


#endif /* __AFX_RT_TEST__ */

#endif /* __VTST_RT_CP_MEM_TEST_MAIN_H__ */
