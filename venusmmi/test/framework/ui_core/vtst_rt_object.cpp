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
 *  vtst_rt_object.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for object
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
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_string.h"
#include "vfx_app_cat_scr.h"
#include "vfx_text_frame.h"
#include "vfx_weak_ptr.h"
#include "vfx_basic_type.h"


/***************************************************************************** 
 * Object Test Implementation
 *****************************************************************************/

class VtstRtObjParentTest : public VfxObject
{
    VFX_DECLARE_CLASS(VtstRtObjParentTest);

// Constructor / Destructor
public:
    VtstRtObjParentTest() : m_magicNumber0(0xaaaaaaaa)
    {
    }

    virtual void onInit()
    {
        VfxObject::onInit();
        
        m_magicNumber0 = 0xcccccccc;
    }

    VfxU32 m_magicNumber0;
};

VFX_IMPLEMENT_CLASS("VtstRtObjParentTest", VtstRtObjParentTest, VfxObject);


class VtstRtObjTest : public VtstRtObjParentTest
{
    VFX_DECLARE_CLASS(VtstRtObjTest);

// Constructor / Destructor
public:
    VtstRtObjTest() : m_magicNumber1(0xbbbbbbbb)
    {
    }

    virtual void onInit()
    {
        VtstRtObjParentTest::onInit();
        
        m_magicNumber1 = 0xdddddddd;
    }

    VfxU32 m_magicNumber1;
};

VFX_IMPLEMENT_CLASS("VtstRtObjTest", VtstRtObjTest, VtstRtObjParentTest);


class VtstRtObjTestClose : public VfxObject
{
private:
    VtstRtObjParentTest *m_child1;
    VtstRtObjParentTest *m_child2;
    VtstRtObjParentTest *m_child3;
    VtstRtObjParentTest *m_child4;
    
// Constructor / Destructor
public:
    VtstRtObjTestClose() : 
        m_child1(NULL),
        m_child2(NULL),
        m_child3(NULL),
        m_child4(NULL)
    {
    }

    virtual void onInit()
    {
        VFX_OBJ_CREATE(m_child1, VtstRtObjParentTest, this);
        VFX_OBJ_CREATE(m_child2, VtstRtObjParentTest, this);
        VFX_OBJ_CREATE(m_child3, VtstRtObjParentTest, this);
        VFX_OBJ_CREATE(m_child4, VtstRtObjParentTest, this);
    }

    virtual void onDeinit()
    {
        // Close in special order
        VFX_OBJ_CLOSE(m_child4);
        VFX_OBJ_CLOSE(m_child1);
        VFX_OBJ_CLOSE(m_child2);
    }
};


class VtstRtObject : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtObject()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Object Test"));
    }

    virtual int start()
    {
        //
        // Object create and class info checking
        //
        VtstRtObjTest *obj0;
        VFX_OBJ_CREATE(obj0, VtstRtObjTest, this);
        check((obj0->m_magicNumber1 == 0xdddddddd), VFX_WSTR("Create and init an object"));
        check(obj0->isKindOf(VFX_OBJ_CLASS_INFO(VtstRtObjTest)), VFX_WSTR("Check is kind of slef class"));
        check(obj0->isKindOf(VFX_OBJ_CLASS_INFO(VtstRtObjParentTest)), VFX_WSTR("Check is kind of parent class"));
        check(obj0->isKindOf(VFX_OBJ_CLASS_INFO(VfxObject)), VFX_WSTR("Check is kind of parent class"));
        check(!obj0->isKindOf(NULL), VFX_WSTR("Check is kind of NULL class"));

        VfxObject *obj0pp = obj0;
        VtstRtObjParentTest *obj0p = obj0;
        check((VFX_OBJ_DYNAMIC_CAST(obj0p, VtstRtObjTest) == obj0), VFX_WSTR("Dynamic cast to child class"));
        check((VFX_OBJ_DYNAMIC_CAST(obj0p, VtstRtObjParentTest) == obj0p), VFX_WSTR("Dynamic cast to self class"));
        check((VFX_OBJ_DYNAMIC_CAST(obj0p, VfxObject) == obj0pp), VFX_WSTR("Dynamic cast to parent class"));

        VtstRtObjParentTest *obj1;
        VFX_OBJ_CREATE(obj1, VtstRtObjParentTest, this);
        check(!obj1->isKindOf(VFX_OBJ_CLASS_INFO(VtstRtObjTest)), VFX_WSTR("Check is kind of wrong class"));
        check((VFX_OBJ_DYNAMIC_CAST(obj1, VtstRtObjTest) == NULL), VFX_WSTR("Dynamic cast to a wrong class"));

        VfxClassInfo *classInfo0 = VFX_OBJ_CLASS_INFO(VtstRtObjTest);
        check(classInfo0->isKindOf(VFX_OBJ_CLASS_INFO(VtstRtObjTest)), VFX_WSTR("Class info is kind of self class"));
        VtstRtObjTest *obj0b = (VtstRtObjTest *)classInfo0->createObject(this);
        check((obj0b->m_magicNumber1 == 0xdddddddd), VFX_WSTR("Create an object by a class info"));

        check(classInfo0->isKindOf(VFX_OBJ_CLASS_INFO(VtstRtObjParentTest)), VFX_WSTR("Class info is kind of parent class"));
        VtstRtObjParentTest *obj1b = (VtstRtObjParentTest *)classInfo0->createObject(this);
        check((obj1b->m_magicNumber0 == 0xcccccccc), VFX_WSTR("Create an object by a child class info"));


        //
        // Object parent-child checking
        //
        check(obj0->isValid(), VFX_WSTR("Object magic number"));
        VFX_OBJ_CLOSE(obj0);
        VFX_OBJ_CLOSE(obj1);
        check(obj0 == NULL, VFX_WSTR("Object close reset pointer"));
        check(!obj0p->isValid(), VFX_WSTR("Object magic number reset"));

        VFX_OBJ_CREATE(obj0, VtstRtObjTest, this);
        check(obj0->getChildCount() == 0, VFX_WSTR("Object has no child object"));

        VFX_OBJ_CREATE(obj1, VtstRtObjTest, obj0);
        check(obj0->getChildCount() == 1, VFX_WSTR("Object has one child object"));

        VtstRtObjParentTest *obj2;
        VFX_OBJ_CREATE(obj2, VtstRtObjParentTest, obj0);
        check(obj0->getChildCount() == 2, VFX_WSTR("Object has two child objects"));
        
        VtstRtObjParentTest *obj3;
        VFX_OBJ_CREATE(obj3, VtstRtObjParentTest, obj2);
        
        VFX_OBJ_CLOSE(obj0);
        check(!obj1->isValid() && !obj2->isValid() && !obj3->isValid(), VFX_WSTR("Object is closed by parent"));

        //
        // Object Close
        //

        VtstRtObjTestClose *objClose;
        VFX_OBJ_CREATE(objClose, VtstRtObjTestClose, this);
        VFX_OBJ_CLOSE(objClose);
        
        return 0; // no phase
    }
};


VtstTestResultEnum vtst_rt_object(VfxU32 param)
{
    VTST_START_SCRN(VtstRtObject);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * WeakRef Test Implementation
 *****************************************************************************/

class VtstRtWeakRef : public VtstRtScr
{
// Variable
public:
    VfxTextFrame    *m_test;
    VfxWeakPtr <VfxTextFrame> m_weakptr_test;

// Constructor / Destructor
public:
    VtstRtWeakRef() : m_test(NULL) 
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("WeakRef Test"));
    }

    virtual int start()
    {
        VfxTextFrame    *test;

        VFX_OBJ_CREATE(test, VfxTextFrame, this);
        test->setPos(VfxPoint(10, 100));
        test->setString(VFX_WSTR("Test"));

        VfxWeakPtr <VfxTextFrame> weakptr_test = test;

        VFX_OBJ_CLOSE(test);

        check(!weakptr_test.isValid(), VFX_WSTR("Create then Close immediately"));


        VFX_OBJ_CREATE(m_test, VfxTextFrame, this);
        m_test->setPos(VfxPoint(10, 100));
        m_test->setString(VFX_WSTR("Test"));

        m_weakptr_test = m_test;
       
        return 0; // no phase
    }


    virtual void end()
    {
        VFX_OBJ_CLOSE(m_test);
        check(!m_weakptr_test.isValid(), VFX_WSTR("Create then Close"));
    }
};


VtstTestResultEnum vtst_rt_weakref(VfxU32 param)
{
    VTST_START_SCRN(VtstRtWeakRef);
    return VTST_TR_OK;
}

/***************************************************************************** 
 * ObjToHandle Test Implementation
 *****************************************************************************/

class VtstRtObjHandle : public VtstRtScr
{
// Variable
public:

// Constructor / Destructor
public:
    VtstRtObjHandle()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("ObjToHandle"));
    }

    virtual int start()
    {
        VfxTextFrame    *test[10];
        VfxS32          i;

        for(i=0;i<10;i++)
        {
            VFX_OBJ_CREATE(test[i], VfxTextFrame, this);
            test[i]->setPos(VfxPoint(10, 10*(i+1)));
            test[i]->setString(VFX_WSTR("Test"));
        }

        VfxObjHandle hdl0 = test[0]->getObjHandle();
        VfxObjHandle hdl4 = test[4]->getObjHandle();
        VfxObjHandle hdl1 = test[1]->getObjHandle();
        VfxObjHandle hdl3 = test[3]->getObjHandle();
        VfxObjHandle hdl2 = test[2]->getObjHandle();

        VfxObject *obj0 = VfxObject::handleToObject(hdl0);
        check(obj0 == test[0], VFX_WSTR("test1"));

        check(hdl4 == test[4]->getObjHandle(), VFX_WSTR("test2"));
        
        VFX_OBJ_CLOSE(test[1]);
        check(!VfxObject::handleToObject(hdl1), VFX_WSTR("test3"));

        check(hdl3 == test[3]->getObjHandle(), VFX_WSTR("test4"));

        for(i=0;i<10;i++)
        {
            if(test[i])
                check(test[i] == VfxObject::handleToObject(test[i]->getObjHandle()), VFX_WSTR("test5"));
        }

        for(i=0;i<10;i++)
        {
            if(test[i])
                check(test[i] == VfxObject::handleToObject(test[i]->getObjHandle()), VFX_WSTR("test7"));
            VFX_OBJ_CLOSE(test[i]);
        }

        check(!VfxObject::handleToObject(hdl0), VFX_WSTR("test6_0"));
        check(!VfxObject::handleToObject(hdl1), VFX_WSTR("test6_1"));
        check(!VfxObject::handleToObject(hdl2), VFX_WSTR("test6_2"));
        check(!VfxObject::handleToObject(hdl3), VFX_WSTR("test6_3"));
        check(!VfxObject::handleToObject(hdl4), VFX_WSTR("test6_4"));
        return 0; // no phase
    }

    virtual void end()
    {
    }
};


VtstTestResultEnum vtst_rt_objtohandle(VfxU32 param)
{
    VTST_START_SCRN(VtstRtObjHandle);
    return VTST_TR_OK;
}

/***************************************************************************** 
 * AttachProp Test Implementation
 *****************************************************************************/

class VtstRtObjAttachProp : public VtstRtScr
{
// Variable
public:

// Constructor / Destructor
public:
    VtstRtObjAttachProp()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("AttachProp"));
    }

    virtual int start()
    {
        return -1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        if(idx == 0)
        {
            VFX_OBJ_CREATE(f, VfxFrame, this);
            return 0;
        }
        else if(idx == 1)
        {
            VfxU8   a1 = 0x78;
            VfxU16  a2 = 0xABCD;
            VfxU32  a4 = 0x98765432;
            VfxPoint pt(320,480);
            VfxTransform tr;
            tr.data.affine.sx = 0.8f;
            tr.data.affine.sy = 0.6f;

            // add prop
            f->setAttachProperty(2,  &a1, sizeof(a1));
            f->setAttachProperty(17,  &a2, sizeof(a2));
            f->setAttachProperty(8,  &a4, sizeof(a4));
            f->setAttachProperty(16,  &pt, sizeof(pt));
            f->setAttachProperty(12,  &tr, sizeof(tr));
            f->setAttachProperty(1,   &pt, sizeof(pt));

            // update with wrong size, should fail
            check(!f->setAttachProperty(16,  &a4, sizeof(a4)), VFX_WSTR("test1-1"));
            check(!f->setAttachProperty(1,  &a4, sizeof(a4)), VFX_WSTR("test1-2"));

            // update with correct size, should success
            a4 = 0x23456789;
            check(f->setAttachProperty(8,  &a4, sizeof(a4)), VFX_WSTR("test2-1"));
            pt.x = 10;
            check(f->setAttachProperty(16,  &pt, sizeof(pt)), VFX_WSTR("test2-2"));
            a1 = 0x87;
            check(f->setAttachProperty(2,  &a1, sizeof(a1)), VFX_WSTR("test2-3"));
            a2 = 0xDCBA;
            check(f->setAttachProperty(17,  &a2, sizeof(a2)), VFX_WSTR("test2-4"));

            // retrieve value and check
            check(!kal_mem_cmp(f->getAttachProperty(2, sizeof(a1)), &a1, sizeof(a1)), VFX_WSTR("test3-1"));
            check(!kal_mem_cmp(f->getAttachProperty(17, sizeof(a2)), &a2, sizeof(a2)), VFX_WSTR("test3-2"));
            check(!kal_mem_cmp(f->getAttachProperty(8, sizeof(a4)), &a4, sizeof(a4)), VFX_WSTR("test3-3"));
            check(!kal_mem_cmp(f->getAttachProperty(16, sizeof(pt)), &pt, sizeof(pt)), VFX_WSTR("test3-4"));
            check(!kal_mem_cmp(f->getAttachProperty(12, sizeof(tr)), &tr, sizeof(tr)), VFX_WSTR("test3-5"));

            // wrong id, should fail
            check(!f->getAttachProperty(99, sizeof(a4)), VFX_WSTR("test4-1"));
            check(!f->getAttachProperty(1, sizeof(a4)), VFX_WSTR("test4-2"));

            f->setAttachProperty(12,  NULL, sizeof(a1));
            f->setAttachProperty(1,  NULL, sizeof(a2));
            f->setAttachProperty(17,  NULL, sizeof(a4));

            f->setAttachProperty(18,  &a2, sizeof(a2));
            f->setAttachProperty(12,  &a2, sizeof(a2));
            f->setAttachProperty(1,  &a2, sizeof(a2));

            check(!kal_mem_cmp(f->getAttachProperty(12, sizeof(a2)), &a2, sizeof(a2)), VFX_WSTR("test5-1"));
            check(!f->getAttachProperty(0, sizeof(a2)), VFX_WSTR("test5-2"));
            check(!f->getAttachProperty(17, sizeof(a4)), VFX_WSTR("test5-3"));

            f->setAttachProperty(1,  NULL, 0);
            f->setAttachProperty(2,  NULL, 0);
            f->setAttachProperty(12,  NULL, 0);
            f->setAttachProperty(16,  NULL, 0);
            f->setAttachProperty(8,  NULL, 0);
            f->setAttachProperty(18,  NULL, 0);

            // here there should no attach property left.

            f->setAttachProperty(2,  &a1, sizeof(a1));
            f->setAttachProperty(8,  &a4, sizeof(a4));
            f->setAttachProperty(16,  &pt, sizeof(pt));
            f->setAttachProperty(17,  &a2, sizeof(a2));
            f->setAttachProperty(12,  &tr, sizeof(tr));
            f->setAttachProperty(1,   &pt, sizeof(pt));
            return 0;
        }
        else if(idx == 2)
        {
            VFX_OBJ_CLOSE(f);
            return 0;
        }
        return VTST_RT_END_TESTCASE;
    }

    VfxFrame *f;
};


VtstTestResultEnum vtst_rt_objattachprop(VfxU32 param)
{
    VTST_START_SCRN(VtstRtObjAttachProp);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

