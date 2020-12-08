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
 *  vtst_rt_cp_mem_test_main.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  CP memory test main source file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vtst_rt_cp_mem_test_main.h"
#include "vcp_list_menu.h"


/***************************************************************************** 
 * Enum table
 *****************************************************************************/
/*
    enum VTST_RT_MEM_TEST_CP_ENUM
    {
        VTST_RT_MEM_TEST_CP_ENUM_VtstRtMemTestListMenu,
        VTST_RT_MEM_TEST_CP_ENUM_COUNT
    };
*/

#define VTST_RT_CP_MEM_TEST_TABLE           enum VTST_RT_MEM_TEST_CP_ENUM
#define VTST_RT_CP_MEM_TEST_NEW(_class)     VTST_RT_MEM_TEST_CP_ENUM_##_class
#define VTST_RT_CP_MEM_TEST_NEW_LAST_ITEM   VTST_RT_MEM_TEST_CP_ENUM_COUNT

#include "vtst_rt_cp_mem_test_cfg.h"


/***************************************************************************** 
 * String array
 *****************************************************************************/
/*
    static const VfxU8* g_vtst_rt_mem_test_cp_name[] =
    {
        (VfxU8*)L"VtstRtMemTestListMenu"
    }
*/

#undef VTST_RT_CP_MEM_TEST_TABLE
#undef VTST_RT_CP_MEM_TEST_NEW
#undef VTST_RT_CP_MEM_TEST_NEW_LAST_ITEM
#define VTST_RT_CP_MEM_TEST_TABLE           static const VfxU8* g_vtst_rt_mem_test_cp_name[] =
#define VTST_RT_CP_MEM_TEST_NEW(_class)     (VfxU8*)L###_class
#define VTST_RT_CP_MEM_TEST_NEW_LAST_ITEM

#include "vtst_rt_cp_mem_test_cfg.h"


/***************************************************************************** 
 * Create function array
 *****************************************************************************/
/*
    static const vtst_rt_cp_mem_test_create_obj_func g_vtst_rt_cp_mem_test_create_obj_func[] =
    {
        VtstRtMemTestListMenu::createTestObj,
    }
*/
typedef void *(*vtst_rt_cp_mem_test_create_obj_func)(void *parentObj);

#undef VTST_RT_CP_MEM_TEST_TABLE
#undef VTST_RT_CP_MEM_TEST_NEW
#undef VTST_RT_CP_MEM_TEST_NEW_LAST_ITEM
#define VTST_RT_CP_MEM_TEST_TABLE           static const vtst_rt_cp_mem_test_create_obj_func g_vtst_rt_cp_mem_test_create_obj_func[] =
#define VTST_RT_CP_MEM_TEST_NEW(_class)     _class##::createTestObj
#define VTST_RT_CP_MEM_TEST_NEW_LAST_ITEM

#include "vtst_rt_cp_mem_test_cfg.h"


/***************************************************************************** 
 * Class VtstRtMemTest
 *****************************************************************************/

class VtstRtMemTest : public VtstRtScr, public IVcpListMenuContentProvider
{
// Constructor / Destructor
public:
    VtstRtMemTest() {}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setBgColor(VFX_COLOR_WHITE);

        VFX_OBJ_CREATE(m_list, VcpListMenu, this);
        m_list->setSize(getSize().width, getSize().height * 4 / 5);
        m_list->setContentProvider(this);
        m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
        m_list->m_signalItemTapped.connect(this, &VtstRtMemTest::onItemSelected);
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        //setTitle(VFX_WSTR("Memory Test"));
        confirm(VFX_WSTR("Result is correct?"));
        
        return -1;
    }

    virtual VfxS32 start() {return 1;}

// Implementation
private:
    enum
    {
        TEST_COUNT = 20,
		IGNORE_COUNT = 10
    };

    VcpListMenu *m_list;
    VtstRtMemTestObj *m_testObj;
    VfxS32 m_minSize, m_maxSize, m_totalSize;
    VfxS32 m_count;
    vtst_rt_cp_mem_test_create_obj_func m_createObj;

    void onItemSelected(VcpListMenu *sender, VfxU32 index)
    {
        m_minSize = 0x7FFFFFFF;
        m_maxSize = m_totalSize = 0;
        m_count = TEST_COUNT + IGNORE_COUNT;
        m_createObj = g_vtst_rt_cp_mem_test_create_obj_func[index];
        startOneTest();
		VFX_OBJ_CLOSE(sender);
    }

    void startOneTest()
    {
        m_testObj = (VtstRtMemTestObj*)m_createObj(this);
        m_testObj->m_signalEndTest.connect(this, &VtstRtMemTest::endOneTest);
        m_testObj->startTest();
    }

    void endOneTest()
    {
		VfxS32 size = m_testObj->getUsedSize();
		printf("===%d===\n", size);

		if (m_count <= TEST_COUNT)
		{
			m_totalSize += size;
			m_maxSize = (size > m_maxSize) ? (size) : (m_maxSize);
			m_minSize = (size < m_minSize) ? (size) : (m_minSize);
		}

        VFX_OBJ_CLOSE(m_testObj);

        m_count --;

        if (m_count > 0)
        {
            startOneTest();
        }
        else
        {
            finish();
        }
    }

    void finish()
    {
        VfxS32 gap = 2;

        VfxWString text1;
        VfxTextFrame *textFrame1;
        VFX_OBJ_CREATE(textFrame1, VfxTextFrame, this);
        textFrame1->setPos(10, 10);
		textFrame1->setColor(VFX_COLOR_BLACK);
        textFrame1->setString(text1.format("Average: %d bytes", (VfxU32)(m_totalSize / TEST_COUNT)));

        VfxWString text2;
        VfxTextFrame *textFrame2;
        VFX_OBJ_CREATE(textFrame2, VfxTextFrame, this);
		textFrame2->setColor(VFX_COLOR_BLACK);
        textFrame2->setString(text2.format("Max: %d bytes", m_maxSize));
        textFrame2->setPos(textFrame1->getPos().x, textFrame1->getPos().y + textFrame1->getSize().height + gap);

        VfxWString text3;
        VfxTextFrame *textFrame3;
        VFX_OBJ_CREATE(textFrame3, VfxTextFrame, this);
		textFrame3->setColor(VFX_COLOR_BLACK);
        textFrame3->setString(text3.format("Min: %d bytes", m_minSize));
        textFrame3->setPos(textFrame2->getPos().x, textFrame2->getPos().y + textFrame2->getSize().height + gap);
    }

// List menu
public:
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
    {
        text.loadFromMem((VfxWChar *)g_vtst_rt_mem_test_cp_name[index]);
        return VFX_TRUE;
    }

    virtual VfxU32 getCount() const {return VTST_RT_MEM_TEST_CP_ENUM_COUNT; }
};


VtstTestResultEnum vtst_rt_mem_test(VfxU32 param)
{
    VTST_START_SCRN(VtstRtMemTest);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

