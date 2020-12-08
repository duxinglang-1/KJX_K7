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
 *  vtst_rt_signal.cpp
 *
 * Project:
 * --------
 *  Venus Regression Test for signal
 *
 * Description:
 * ------------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vfx_object.h"
#include "vfx_signal.h"
#include "vfx_sys_memory.h"
#include "vfx_basic_type.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_app_cat_scr.h"


/***************************************************************************** 
 * Signal Test Implementation
 *****************************************************************************/

class VtstRtSignal : public VtstRtScr
{

    class MyObj : public VfxObject
    {
    public:
        VfxSignal0  m_signal;

        virtual void onInit()
        {
            m_signal.connect(this, &MyObj::onSignal);
            m_signal.connect(this, &MyObj::onSignal2);
        }

        void onSignal()
        {
            
        }

        void onSignal2()
        {
            MyObj* obj = this;
            VFX_OBJ_CLOSE(obj);
            
        }
    };

    class MyObj2 : public VfxObject
    {
    public:
        VfxSignal0  m_signal;

        virtual void onInit()
        {
            m_signal.connect(this, &MyObj2::onSignal);
            m_signal.connect(this, &MyObj2::onSignal2);
        }

        void onSignal()
        {
            MyObj2* obj = this;
            VFX_OBJ_CLOSE(obj);
            
        }

        void onSignal2()
        {
            // following code will crash system, it should not be called
            m_signal.emit();
            
        }
    };

    class MyObj3 : public VfxObject
    {
    public:
        VfxSignal0  m_signal;

        virtual void onInit()
        {
            m_signal.connect(this, &MyObj3::onSignal);
        }

        void onSignal()
        {
            MyObj3* obj = this;
            VFX_OBJ_CLOSE(obj);
            
        }

        void onSignal2()
        {
            // can this be invoke?
        }

        void test()
        {
            m_signal.postEmit(this, &MyObj3::onSignal2);
        }
    };

// Variable
public:
    VfxSignal0  m_signal0;
    VfxSignal0  m_signal1;

    // various signal argument test
    VfxSignal1<VfxColor>                             m_signalArg1;
    VfxSignal2<VfxSize, VfxColor>                    m_signalArg2;
    VfxSignal3<VfxRect, VfxSize, VfxColor>           m_signalArg3;
    VfxSignal4<VfxPoint, VfxRect, VfxSize, VfxColor>  m_signalArg4;

    VfxSignal1<VfxWString>                           m_signalStr;

    // hit count for verifying
    VfxS32      m_hitCount0;
    VfxS32      m_hitCount1;
    VfxS32      m_hitCountPost;
    VfxS32      m_hitCountPostDone;
    VfxS32      m_cbCount;

    // For life-cycle testing
    MyObj       *m_pObj;
    MyObj2      *m_pObj2;
    MyObj3      *m_pObj3;

    // For callback test
    VfxCallback2<VfxS32, VfxColor> m_callback2;


// Constructor / Destructor
public:
    VtstRtSignal() : m_hitCount0(0), m_hitCount1(0), m_hitCountPost(0), m_hitCountPostDone(0), m_cbCount(0) {}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Signal Test"));
        
        m_signal0.connect(this, &VtstRtSignal::onSignal0);
        m_signal0.connect(this, &VtstRtSignal::onSignal0_1);

        m_signal1.connect(this, &VtstRtSignal::onSignal1);
        m_signal1.connect(this, &VtstRtSignal::onSignal1_1);

        VfxCallback1<VfxColor> cb(this, &VtstRtSignal::onSignalT2);
        m_signalArg1.connect(cb);
        m_signalArg1.emit(VfxColor(1, 2, 3, 4));
        m_signalArg1.disconnect(cb);
        m_signalArg1.emit(VfxColor(1, 2, 3, 4));

        m_signalArg1.connect(this, &VtstRtSignal::onSignalT1);
        m_signalArg4.connect(this, &VtstRtSignal::onSignalT4);

        // It should compile error, for typeing checking
        // m_signalArg4.connect(this, &VtstRtSignal::onSignalT1);

        VFX_OBJ_CREATE(m_pObj, MyObj, this);
        VFX_OBJ_CREATE(m_pObj2, MyObj2, this);
        VFX_OBJ_CREATE(m_pObj3, MyObj3, this);

        m_callback2 = VfxCallback2<VfxS32, VfxColor>(this, &VtstRtSignal::onCallback2);
    }

    static VfxFloat fooTimingFunc(VfxFloat t, void *data, VfxU32 dataSize)
    {
        VtstRtSignal* _this = *(VtstRtSignal **)data;
        vfxPostInvoke4(_this, &VtstRtSignal::onPostInOtherTask,
            VfxPoint(50, 50), 
            VfxRect(0, 0, 200, 200), 
            VfxSize(100, 100), 
            VfxColor(255, 0, 255, 255));
        
        return t;
    }
    
    virtual int start()
    {
        m_signal0.emit();
        m_signal1.emit();

        VfxColor color(1, 2, 3, 4);

        m_signalArg1.emit(color);
        m_signalArg1.postEmit(color);
        m_signalArg1.postEmit(color, this, &VtstRtSignal::onSignalTPostDone1);

        // overwrite old memory for testing safty
        color = VfxColor(255, 255, 255, 255); 

        m_signalArg3.postEmit(
            VfxRect(0, 0, 200, 200), 
            VfxSize(100, 100), 
            VfxColor(255, 0, 255, 255));
        
        m_signalArg4.postEmit(
            VfxPoint(50, 50), 
            VfxRect(0, 0, 200, 200), 
            VfxSize(100, 100), 
            VfxColor(255, 0, 255, 255), 
            this, &VtstRtSignal::onSignalTPostDone4);

        m_pObj->m_signal.emit();
        m_pObj2->m_signal.emit();
        m_pObj3->test();


        // test copy constructor
        VfxCallback2<VfxS32, VfxColor> tmp(m_callback2);
        // operator=
        VfxCallback2<VfxS32, VfxColor> tmp2;
        tmp2 = m_callback2;

        m_callback2.invoke(100, VfxColor(1, 2, 3, 4));

        VfxCallback0 tmp0(this, &VtstRtSignal::onCallback0);

        tmp0.invoke();

        VfxCallback1<VfxS32> tmp1(this, &VtstRtSignal::onCallback1);
        tmp1.invoke(100);

        VfxCallback3<VfxS32, VfxColor, VfxFloat> tmp3(this, &VtstRtSignal::onCallback3);
        tmp3.invoke(100, VfxColor(1, 2, 3, 4), 0.1f);

        VfxCallback4<VfxS32, VfxColor, VfxFloat, VfxBool> tmp4(this, &VtstRtSignal::onCallback4);
        tmp4.invoke(100, VfxColor(1, 2, 3, 4), 0.1f, VFX_FALSE);

        // This should compile error

        // You will get following error message:
        // error C2440: 'static_cast' : cannot convert from 'void (__thiscall VtstRtSignal::*)(int,class VfxColor,float)' to 'void (__thiscall VfxObject::*)(int,class VfxColor,float,bool)'
        // VfxCallback4<VfxS32, VfxColor, VfxFloat, VfxBool> tmp5(this, &VtstRtSignal::onCallback3);

        VfxCallback4<VfxS32, VfxColor, VfxFloat, VfxBool> tmp6;
        // Invoke a no one registered function
        tmp6.invoke(100, VfxColor(1, 2, 3, 4), 0.1f, VFX_FALSE);

        VfxCallback4<VfxS32, VfxColor, VfxFloat, VfxBool> tmp7(VFX_CALLBACK_NULL);
        VfxCallback4<VfxS32, VfxColor, VfxFloat, VfxBool> tmp8;
        
        tmp8 = tmp7;
        tmp7 = VFX_CALLBACK_NULL;

        return 2;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        if (idx == 0)
        {
            vfxPostInvoke0(this, &VtstRtSignal::onP0);
            vfxPostInvoke1(this, &VtstRtSignal::onP1,
                VfxColor(255, 0, 255, 255)
            );
            vfxPostInvoke2(this, &VtstRtSignal::onP2,
                VfxColor(255, 0, 255, 255),
                (VfxObject*)this
            );
            vfxPostInvoke3(this, &VtstRtSignal::onP3,
                1,
                (VfxObject*)this,
                VfxSize(1, 1)
            );
            vfxPostInvoke4(this, &VtstRtSignal::onP4,
                VfxPoint(50, 50), 
                VfxRect(0, 0, 200, 200), 
                VfxSize(100, 100), 
                VfxColor(255, 0, 255, 255)
            );

            // make it very short
            // Post Emit should be process before timer
            return 1; 
        }
        else if (idx == 1)
        {
            //vrt_invoke_mmi_rpc(&VtstRtSignal::taskProc, this);

            setAutoAnimate(VFX_TRUE);

            // Trigger a timing function callback on VRT
            VfxAutoAnimate::begin();

            void *data = this;
            VfxAutoAnimate::setCustomTimingFunc(fooTimingFunc, &data, sizeof(data));
            setBgColor(VFX_COLOR_SILVER);
            
            VfxAutoAnimate::commit();
            
            return -1;
        }
        return 0;
    }

    virtual void end()
    {
        check(m_hitCount0 == 2 && m_hitCount1 == 1 && m_hitCountPost == 9, VFX_WSTR("Signal Count"));
        check(m_hitCountPostDone == 2, VFX_WSTR("Post Done"));
        check(m_cbCount == 5, VFX_WSTR("Callback count"));
    }

// Slot
protected:
    void onSignal0()
    {
        check(m_hitCount0 == 0, VFX_WSTR("Signal Order"));
        m_hitCount0++;
    }

    void onSignal0_1()
    {
        check(m_hitCount0 == 1, VFX_WSTR("Signal Order2"));
        m_hitCount0++;
    }

    void onSignal1()
    {
        check(m_hitCount1 == 0, VFX_WSTR("Signal Order3"));
        m_hitCount1++;
        vfxStopEmit();
    }

    void onSignal1_1()
    {
        check(m_hitCount1 == 1, VFX_WSTR("Signal Order4"));
        m_hitCount1++;
        vfxStopEmit();
    }

    void onSignalT1(VfxColor a1)
    {
        m_hitCountPost++;
        check(a1 == VfxColor(1, 2, 3, 4), VFX_WSTR("Argument value check"));
    }

    void onSignalT2(VfxColor a1)
    {
        check(a1 == VfxColor(1, 2, 3, 4), VFX_WSTR("Argument value check"));
    }

    void onSignalTPostDone1(VfxColor a1)
    {
        m_hitCountPostDone ++;
    }

    void onSignalT4(VfxPoint, VfxRect, VfxSize, VfxColor)
    {
        m_hitCountPost++;
    }

    void onSignalTPostDone4(VfxPoint, VfxRect, VfxSize, VfxColor)
    {
        m_hitCountPostDone ++;
    }

    void onP0()
    {
        m_hitCountPost++;
    }

    void onP1(VfxColor a1)
    {
        m_hitCountPost++;
    }

    void onP2(VfxColor a1, VfxObject *obj)
    {
        m_hitCountPost++;
    }

    void onP3(VfxS32 i, VfxObject *obj, VfxSize sz)
    {
        m_hitCountPost++;
    }

    void onP4(VfxPoint p, VfxRect r, VfxSize sz, VfxColor c)
    {
        m_hitCountPost++;
    }

    void onPostInOtherTask(VfxPoint p, VfxRect r, VfxSize sz, VfxColor c)
    {
        endPhase();
    }

    void onCallback0()
    {
        m_cbCount++;
    }

    void onCallback1(VfxS32 a1)
    {
        m_cbCount++;
    }

    void onCallback2(VfxS32 a1, VfxColor a2)
    {
        m_cbCount++;
        check(a1 == 100, VFX_WSTR("Argument value check"));
        check(a2 == VfxColor(1, 2, 3, 4), VFX_WSTR("Argument value check"));
    }

    void onCallback3(VfxS32 a1, VfxColor a2, VfxFloat a3)
    {
        m_cbCount++;
    }

    void onCallback4(VfxS32 a1, VfxColor a2, VfxFloat a3, VfxBool a4)
    {
        m_cbCount++;
    }
};


VtstTestResultEnum vtst_rt_signal(VfxU32 param)
{
    VTST_START_SCRN(VtstRtSignal);
    return VTST_TR_OK;
}


#endif // __AFX_RT_TEST__

