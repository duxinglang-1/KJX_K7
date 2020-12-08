/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vtst_rt_dirty_region.cpp
 *
 * Project:
 * --------
 *  Venus Rendering Task
 *
 * Description:
 * ------------
 *  Venus Regression Test for VRT dirty region
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

/***************************************************************************** 
* Include
*****************************************************************************/
#include "vtst_rt_dirty_region.h"
#include "vrt_canvas.h"
#include "vfx_object.h"
#include "vfx_system.h"
#include "vtst_rt_main.h"
#include "vfx_mmi.h"

extern "C" void vrt_render_get_last_dirty_info(vrt_u32 *dirty_rect_num, vrt_rect_struct **dirty_rect_list);

/***************************************************************************** 
 * Dirty region Test Implementation
 *****************************************************************************/
VfxMemFunc g_test_case_func[][2] = {
    {(VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::case1, VfxMemFunc), 
     (VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::runCase1, VfxMemFunc)},
    {(VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::case2, VfxMemFunc), 
     (VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::runCase2, VfxMemFunc)},
    {(VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::case3, VfxMemFunc), 
     (VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::runCase3, VfxMemFunc)},
    {(VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::case4, VfxMemFunc), 
     (VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::runCase4, VfxMemFunc)},
    {(VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::case5, VfxMemFunc), 
     (VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::runCase5, VfxMemFunc)},
    {(VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::case6, VfxMemFunc), 
     (VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::runCase6, VfxMemFunc)},
    {(VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::case7, VfxMemFunc), 
     (VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::runCase7, VfxMemFunc)},
    {(VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::case8, VfxMemFunc), 
     (VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::runCase8, VfxMemFunc)},
    {(VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::case9, VfxMemFunc), 
     (VfxMemFunc) VFX_STATIC_CAST(&VtstDirtyScanPage::runCase9, VfxMemFunc)}
};


static VfxBool vfx_rect_is_empty(const VfxRect &rect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (VfxBool)(rect.size.width == 0 || rect.size.height == 0);
}


static VfxRect vfx_rect_intersect(const VfxRect &lhs, const VfxRect &rhs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 lhs_right, lhs_bottom;
    VfxS32 rhs_right, rhs_bottom;
    VfxRect ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lhs_right    = lhs.origin.x + lhs.size.width;
    lhs_bottom   = lhs.origin.y + lhs.size.height;
    rhs_right    = rhs.origin.x + rhs.size.width;
    rhs_bottom   = rhs.origin.y + rhs.size.height;
    
    ret.origin.x = VFX_MAX(lhs.origin.x, rhs.origin.x);
    ret.origin.y = VFX_MAX(lhs.origin.y, rhs.origin.y);
    ret.size.width = VFX_MIN(lhs_right, rhs_right) - ret.origin.x;
    ret.size.height = VFX_MIN(lhs_bottom, rhs_bottom) - ret.origin.y;
    
    if (ret.size.width <= 0 || ret.size.height <= 0)
    {
        return VfxRect(0, 0, 0, 0);
    }
    
    return ret;
}


static VfxRect vfx_rect_union(const VfxRect &lhs, const VfxRect &rhs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 lhs_right, lhs_bottom;
    VfxS32 rhs_right, rhs_bottom;
    VfxRect ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lhs_right    = lhs.origin.x + lhs.size.width;
    lhs_bottom   = lhs.origin.y + lhs.size.height;
    rhs_right    = rhs.origin.x + rhs.size.width;
    rhs_bottom   = rhs.origin.y + rhs.size.height;
    
    ret.origin.x = VFX_MIN(lhs.origin.x, rhs.origin.x);
    ret.origin.y = VFX_MIN(lhs.origin.y, rhs.origin.y);
    ret.size.width = VFX_MAX(lhs_right, rhs_right) - ret.origin.x;
    ret.size.height = VFX_MAX(lhs_bottom, rhs_bottom) - ret.origin.y;
    
    return ret;
}


/***************************************************************************** 
 * Class VtstDirtyScanPage
 *****************************************************************************/
class VtstRtDirtyRegion : public VtstRtScr
{
// Variable
public:
    VtstDirtyScanPage *m_rtpage;

// Constructor / Destructor
public:
    VtstRtDirtyRegion(){}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        VFX_OBJ_CREATE(m_rtpage, VtstDirtyScanPage, this);

        m_rtpage->setSize(UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT);
        m_rtpage->setPos(0, 0);
        m_rtpage->setHidden(VFX_FALSE);
    }

    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        return -1;
    }
};


VtstTestResultEnum vtst_rt_dirty_region(VfxU32 param)
{
    VTST_START_SCRN(VtstRtDirtyRegion);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Class VtstDirtyScanPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstDirtyScanPage", VtstDirtyScanPage, VfxPage);

VtstDirtyScanPage::VtstDirtyScanPage():
    m_testcasecnt(0),
    m_testcase(0),
    m_testcasestage(TESTCASE_INIT),
    m_description(NULL),
    m_indexframe(NULL),
    m_frame1(NULL),
    m_frame2(NULL),
    m_frame3(NULL),
    m_frame4(NULL),
    m_frame5(NULL)
{

}


void VtstDirtyScanPage::onInit()
{
    VfxPage::onInit();
    setStatusBar(VFX_FALSE);
    setBgColor(VfxColor(255, 206, 235, 206));
    VFX_OBJ_CREATE(m_description, VcpTextView, this);
    m_description->setPos(0, 0);
    m_description->setSize(UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT/4);
    m_description->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    m_description->setAutoResized(VFX_FALSE);
    m_description->setBgColor(VfxColor(255, 36, 94, 220));
    m_description->setFont(VfxFontDesc(VFX_FONT_DESC_SMALL));
    
    VFX_OBJ_CREATE(m_indexframe, VcpTextView, this);
    m_indexframe->setPos(UI_DEVICE_WIDTH/3, UI_DEVICE_HEIGHT - 30);
    m_indexframe->setSize(UI_DEVICE_WIDTH/3, 30);
    m_indexframe->setAlignMode(VCP_TEXT_ALIGN_MODE_CENTER);
    m_indexframe->setAutoResized(VFX_FALSE);

    m_testcasecnt = sizeof(g_test_case_func)/sizeof(g_test_case_func[0]);

    initTestCase();
}


void VtstDirtyScanPage::onDeinit()
{
    VfxPage::onDeinit();
    vrt_canvas_resume();
}


void VtstDirtyScanPage::initTestCase()
{
    dirty_rect_num = 0;
    setBgColor(VfxColor(255, 206, 235, 206));
    setIsZSortChild(VFX_TRUE);

    VfxFrame *frame = getFirstChildFrame();
    while (frame)
    {
        VfxFrame *next = frame->getNextFrame();
        if (frame != m_description && frame != m_indexframe)
        {
            VFX_OBJ_CLOSE(frame);
        }
        frame = next;
    }
        
    VFX_OBJ_CREATE(m_frame1, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_frame2, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_frame3, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_frame4, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_frame5, VfxTextFrame, this);

    m_frame1->setSize(120, 100);
    m_frame1->setString(VFX_WSTR("Frame 1"));
    m_frame1->setAutoResized(VFX_FALSE);
    m_frame1->setBgColor(VFX_COLOR_BLUE);

    m_frame2->setSize(120, 100);
    m_frame2->setString(VFX_WSTR("Frame 2"));
    m_frame2->setAutoResized(VFX_FALSE);
    m_frame2->setBgColor(VFX_COLOR_BLACK);
    
    m_frame3->setSize(120, 100);
    m_frame3->setString(VFX_WSTR("Frame 3"));
    m_frame3->setAutoResized(VFX_FALSE);
    m_frame3->setBgColor(VFX_COLOR_GREY);
    
    m_frame4->setSize(120, 100);
    m_frame4->setString(VFX_WSTR("Frame 4"));
    m_frame4->setAutoResized(VFX_FALSE);
    m_frame4->setBgColor(VFX_COLOR_YELLOW);

    m_frame5->setSize(120, 100);
    m_frame5->setString(VFX_WSTR("Frame 5"));
    m_frame5->setAutoResized(VFX_FALSE);
    m_frame5->setBgColor(VFX_COLOR_TEAL);
    m_frame5->setHidden(VFX_TRUE);

    (this->*(g_test_case_func[m_testcase][0]))();

    VfxWString ws;
    ws.format("%d Test Case", m_testcase);
    m_indexframe->setText(ws);
    
    m_testcasestage = TESTCASE_INIT;
    vrt_canvas_resume();
}


void VtstDirtyScanPage::runTestCase()
{
    (this->*(g_test_case_func[m_testcase][1]))();
    
    VFX_OBJ_GET_INSTANCE(VfxRenderer)->mustShowNextFrame();
    vrt_canvas_suspend();
    vfx_mmi_update_scene();

    if (!verifyDiryRect())
    {
        setBgColor(VFX_COLOR_RED);
    }
    
    vrt_canvas_resume();
    m_testcase++;
    if (m_testcase >= m_testcasecnt)
    {
        m_testcase = 0;
    }
    m_testcasestage = TESTCASE_FINISH;
}


void VtstDirtyScanPage::case1()
{
    VfxChar description[] =  "\
/*\n\
 *  normal dirty case\n\
 *\n\
 *  Flow:\n\
 *      frame1 setPos\n\
 *      frame2 setOpacity\n\
 *      frame3 setAnchor\n\
 *\n\
 *  Result:\n\
 *      Dirty region should be\n\
 *      3 frames's old region and lastest region\n\
 */";

    VfxWChar *ws;
    VfxU32 len = vfx_sys_strlen(description);
    VFX_ALLOC_MEM(ws, sizeof(VfxWChar)*(len+1), this);
    vfx_sys_mbstowcs(ws, description, len);
    ws[len] = '\0';

    m_description->setText(ws);
    VFX_FREE_MEM(ws);

    m_frame1->setPos(30, START_Y + 20);
    m_frame2->setPos(80, START_Y + 50);
    m_frame3->setPos(200, START_Y + 100);
    VFX_OBJ_CLOSE(m_frame4);
}


void VtstDirtyScanPage::runCase1()
{
    addDirtyRect(m_frame1->getRect());
    m_frame1->setPos(50, START_Y + 70);
    addDirtyRect(m_frame1->getRect());

    m_frame2->setOpacity(0.2f);
    addDirtyRect(m_frame2->getRect());

    m_frame3->setAnchor(VfxFPoint(0.7f, 0.3f));
    addDirtyRect(m_frame3->getRect());
}


void VtstDirtyScanPage::case2()
{
    VfxChar description[] =  "\
    /*\n\
     *  Normal dirty case\n\
     *\n\
     *  Flow:\n\
     *      Frame2 setPosZ\n\
     *\n\
     *  Result:\n\
     *      Dirty region should be\n\
     *      frame2's region\n\
     */";
    VfxWChar *ws;
    VfxU32 len = vfx_sys_strlen(description);
    VFX_ALLOC_MEM(ws, sizeof(VfxWChar)*(len+1), this);
    vfx_sys_mbstowcs(ws, description, len);
    ws[len] = '\0';

    m_description->setText(ws);
    VFX_FREE_MEM(ws);

    m_frame1->setPos(50, START_Y + 50);
    m_frame1->setPosZ(100);
    m_frame2->setPos(110, START_Y + 100);
    m_frame2->setPosZ(90);
    m_frame3->setPos(280, START_Y + 80);
    m_frame3->setPosZ(80);
    m_frame4->setPos(350, START_Y + 200);
    m_frame4->setPosZ(70);
}


void VtstDirtyScanPage::runCase2()
{
    m_frame2->setPosZ(120);
    addDirtyRect(m_frame2->getRect());
}


void VtstDirtyScanPage::case3()
{
    VfxChar description[] =  "\
    /*\n\
     *  Content dirty case\n\
     *\n\
     *  Flow:\n\
     *      frame1 setSize\n\
     *      frame2 setBgColor\n\
     *      frame3 setSize & setPos\n\
     *\n\
     *  Result:\n\
     *      Dirty region should be\n\
     *      frame1,3's last region and current region\n\
     *      frame2's region\n\
     */";
    VfxWChar *ws;
    VfxU32 len = vfx_sys_strlen(description);
    VFX_ALLOC_MEM(ws, sizeof(VfxWChar)*(len+1), this);
    vfx_sys_mbstowcs(ws, description, len);
    ws[len] = '\0';

    m_description->setText(ws);
    VFX_FREE_MEM(ws);

    m_frame1->setPos(50, START_Y + 50);
    m_frame2->setPos(110, START_Y + 100);
    m_frame3->setPos(280, START_Y + 80);
    VFX_OBJ_CLOSE(m_frame4);
}


void VtstDirtyScanPage::runCase3()
{
    addDirtyRect(m_frame1->getRect());
    m_frame1->setPos(0, START_Y);
    m_frame1->setSize(100, 80);
    addDirtyRect(m_frame1->getRect());

    m_frame2->setBgColor(VFX_COLOR_PURPLE);
    addDirtyRect(m_frame2->getRect());

    addDirtyRect(m_frame3->getRect());
    m_frame3->setSize(100, 100);
    m_frame3->setPos(320, START_Y + 130);
    addDirtyRect(m_frame3->getRect());
}


void VtstDirtyScanPage::case4()
{
    VfxChar description[] =  "\
    /*\n\
     *  Remove frame dirty case\n\
     *  \n\
     *  Flow:\n\
     *      frame1 has child frame2\n\
     *      remove frame2 from frame1\n\
     *\n\
     *  Result:\n\
     *      Dirty region should be\n\
     *      frame1's region \n\
     */";
    VfxWChar *ws;
    VfxU32 len = vfx_sys_strlen(description);
    VFX_ALLOC_MEM(ws, sizeof(VfxWChar)*(len+1), this);
    vfx_sys_mbstowcs(ws, description, len);
    ws[len] = '\0';

    m_description->setText(ws);
    VFX_FREE_MEM(ws);
    
    m_frame1->setSize(200, 200);
    m_frame1->setPos(20, START_Y + 20);
    m_frame1->addChildFrame(m_frame2);
    
    m_frame2->setSize(100, 100);
    m_frame2->setPos(20, 20);

    m_frame3->setHidden(VFX_TRUE);
    m_frame4->setHidden(VFX_TRUE);
    m_frame5->setHidden(VFX_TRUE);
}


void VtstDirtyScanPage::runCase4()
{
    // remove frame2 from frame1
    addDirtyRect(m_frame2->getParentFrame()->getRect());
    m_frame2->removeFromParentFrame();
}


void VtstDirtyScanPage::case5()
{
    VfxChar description[] =  "\
    /*\n\
     *  Remove frame dirty case\n\
     *  \n\
     *  Flow:\n\
     *      frame1 has child frame2 and frame1 is prevent cache\n\
     *      remove frame2 from frame1\n\
     *\n\
     *  Result:\n\
     *      Dirty region should be\n\
     *      frame1's parent last region \n\
     */";
    VfxWChar *ws;
    VfxU32 len = vfx_sys_strlen(description);
    VFX_ALLOC_MEM(ws, sizeof(VfxWChar)*(len+1), this);
    vfx_sys_mbstowcs(ws, description, len);
    ws[len] = '\0';

    m_description->setText(ws);
    VFX_FREE_MEM(ws);
    
    m_frame1->setSize(200, 200);
    m_frame1->setPos(20, START_Y + 20);
    m_frame1->addChildFrame(m_frame2);
    m_frame1->setCacheMode(VFX_CACHE_MODE_PREVENT);
    
    m_frame2->setSize(100, 100);
    m_frame2->setPos(20, 20);

    m_frame3->setHidden(VFX_TRUE);
    m_frame4->setHidden(VFX_TRUE);
    m_frame5->setHidden(VFX_TRUE);
}


void VtstDirtyScanPage::runCase5()
{
    // remove frame2 from frame1
    addDirtyRect(m_frame1->getParentFrame()->getRect());
    m_frame2->removeFromParentFrame();
}


void VtstDirtyScanPage::case6()
{
    VfxChar description[] =  "\
    /*\n\
     *  Add frame dirty case\n\
     *  \n\
     *  Flow:\n\
     *      add frame2 to frame1\n\
     *\n\
     *  Result:\n\
     *      Dirty region should be\n\
     *      frame2's parent region \n\
     */";
    VfxWChar *ws;
    VfxU32 len = vfx_sys_strlen(description);
    VFX_ALLOC_MEM(ws, sizeof(VfxWChar)*(len+1), this);
    vfx_sys_mbstowcs(ws, description, len);
    ws[len] = '\0';

    m_description->setText(ws);
    VFX_FREE_MEM(ws);
    
    m_frame1->setSize(200, 200);
    m_frame1->setPos(20, START_Y + 20);

    VFX_OBJ_CLOSE(m_frame2);
    VFX_OBJ_CLOSE(m_frame3);
    VFX_OBJ_CLOSE(m_frame4);
    VFX_OBJ_CLOSE(m_frame5);
}


void VtstDirtyScanPage::runCase6()
{
    VFX_OBJ_CREATE(m_frame2, VfxTextFrame, m_frame1);
    m_frame2->setSize(120, 100);
    m_frame2->setPos(20, 20);
    m_frame2->setAutoResized(VFX_FALSE);
    m_frame2->setString(VFX_WSTR("Frame 2"));
    m_frame2->setBgColor(VFX_COLOR_FUCHSIA);
    addDirtyRect(m_frame2->getParentFrame()->getRect());
}


void VtstDirtyScanPage::case7()
{
    VfxChar description[] =  "\
    /*\n\
     *  Change frame parent dirty case\n\
     *  \n\
     *  Flow:\n\
     *      frame2 is frame1's child\n\
     *      change frame2 parent to frame3\n\
     *\n\
     *  Result:\n\
     *      Dirty region should be\n\
     *      frame2's two parent frame's last region and current region \n\
     */";
    VfxWChar *ws;
    VfxU32 len = vfx_sys_strlen(description);
    VFX_ALLOC_MEM(ws, sizeof(VfxWChar)*(len+1), this);
    vfx_sys_mbstowcs(ws, description, len);
    ws[len] = '\0';

    m_description->setText(ws);
    VFX_FREE_MEM(ws);
    
    m_frame1->setSize(200, 200);
    m_frame1->setPos(20, START_Y + 20);

    m_frame1->addChildFrame(m_frame2);
    m_frame2->setSize(120, 100);
    m_frame2->setPos(40,  40);

    m_frame3->setSize(200, 200);
    m_frame3->setPos(230, START_Y + 20);
    VFX_OBJ_CLOSE(m_frame4);
    VFX_OBJ_CLOSE(m_frame5);
}


void VtstDirtyScanPage::runCase7()
{
    // dirty region should be frame2's parent last dirty region
    addDirtyRect(m_frame2->getParentFrame()->getRect());
    m_frame3->addChildFrame(m_frame2);
    addDirtyRect(m_frame2->getParentFrame()->getRect());    
}


void VtstDirtyScanPage::case8()
{
    VfxChar description[] =  "\
    /*\n\
     *  Hide frame content dirty case\n\
     *  This case is the same as remove frame case\n\
     *  \n\
     *  Flow:\n\
     *      Hide frame2, frame2 is frame1's child\n\
     *\n\
     *  Result:\n\
     *      Dirty region should be\n\
     *      frame1's region \n\
     */";
    VfxWChar *ws;
    VfxU32 len = vfx_sys_strlen(description);
    VFX_ALLOC_MEM(ws, sizeof(VfxWChar)*(len+1), this);
    vfx_sys_mbstowcs(ws, description, len);
    ws[len] = '\0';

    m_description->setText(ws);
    VFX_FREE_MEM(ws);
    
    m_frame1->setSize(200, 200);
    m_frame1->setPos(20, START_Y + 20);

    m_frame1->addChildFrame(m_frame2);
    m_frame2->setSize(120, 100);
    m_frame2->setPos(100,  120);
    
    VFX_OBJ_CLOSE(m_frame3);
    VFX_OBJ_CLOSE(m_frame4);
    VFX_OBJ_CLOSE(m_frame5);
}


void VtstDirtyScanPage::runCase8()
{
    // dirty region should be frame2's parent last dirty region
    m_frame2->setHidden(VFX_TRUE);
    addDirtyRect(m_frame2->getParentFrame()->getRect());
}


void VtstDirtyScanPage::case9()
{
    VfxChar description[] =  "\
    /*\n\
     *  Lots of small frames dirty in the same time\n\
     *  \n\
     *  Flow:\n\
     *      There are 12 frames dirty in the same time\n\
     *\n\
     *  Result:\n\
     *      Judge the VRT dirty rect list\n\
     */";
    VfxWChar *ws;
    VfxU32 len = vfx_sys_strlen(description);
    VFX_ALLOC_MEM(ws, sizeof(VfxWChar)*(len+1), this);
    vfx_sys_mbstowcs(ws, description, len);
    ws[len] = '\0';

    m_description->setText(ws);
    VFX_FREE_MEM(ws);

    VFX_OBJ_CLOSE(m_frame1);
    VFX_OBJ_CLOSE(m_frame2);
    VFX_OBJ_CLOSE(m_frame3);
    VFX_OBJ_CLOSE(m_frame4);
    VFX_OBJ_CLOSE(m_frame5);

    VfxS32 frameX       = 20;
    VfxS32 frameY       = START_Y + 40;
    VfxS32 frameWidth   = 40;
    VfxS32 frameHeight  = 40;
    VfxS32 frameGap     = 20;
    VfxFrame *tempFrame = NULL;
    for(VfxS32 i = 0; i < 12; i++)
    {
        VFX_OBJ_CREATE(tempFrame, VfxFrame, this);
        tempFrame->setSize(frameWidth, frameHeight);
        if (frameX + frameWidth > UI_DEVICE_WIDTH)
        {
            frameX = 20;
            frameY += frameGap + frameHeight;
        }
        tempFrame->setPos(frameX, frameY);
        tempFrame->setBgColor(VfxColor(100, frameX%255, frameY%255, (frameX*frameY)%255));

        frameX += frameGap + frameWidth;
    }
}


void VtstDirtyScanPage::runCase9()
{
    // change frame3's parent from frame2 to frame1
    VfxFrame *frame = getFirstChildFrame();
    while (frame)
    {
        if (frame != m_description && frame != m_indexframe)
        {
            VfxS32 x = frame->getPos().x;
            VfxS32 y = frame->getPos().y;
            
            frame->setBgColor(VfxColor(200, y%255, (x*y)%255, x%255));
            addDirtyRect(frame->getRect());
        }
        frame = frame->getNextFrame();
    }
}


void VtstDirtyScanPage::addDirtyRect(const VfxRect & dirty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU32 i;
    VfxRect rect;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vfx_rect_is_empty(dirty))
    {
        return;
    }

    for (i = 0; i < dirty_rect_num; i++)
    {
        rect = vfx_rect_intersect(dirty_rect[i], dirty);

        if (!vfx_rect_is_empty(rect))
        {
            dirty_rect[i] = vfx_rect_union(dirty_rect[i], dirty);
            
            return;
        }        
    }

    /* the dirty list is not enough, just union dirty_rect with the first element */
    if (dirty_rect_num == 6)
    {
        VfxRect union_rect;
        VfxS32 min_union_rect_area, area, min_dirty_rect_idx;

        min_union_rect_area = VRT_S32_MAX;
        min_dirty_rect_idx = 0;
        
        for (i = 0; i < dirty_rect_num; i++)
        {
            union_rect = vfx_rect_union(dirty_rect[i], dirty);
            area = union_rect.size.width * union_rect.size.height;
            if (area < min_union_rect_area)
            {
                min_union_rect_area = area;
                min_dirty_rect_idx = i;
            }
        }

        dirty_rect[min_dirty_rect_idx] = vfx_rect_union(dirty_rect[min_dirty_rect_idx], dirty);
    }
    else
    {   /* append dirty_rect to the end of the list */
        dirty_rect[dirty_rect_num++] = dirty;
    }        
}


VfxBool VtstDirtyScanPage::verifyDiryRect()
{
    VfxU32 real_dirty_rect_num;
    vrt_rect_struct *real_dirty_rect = NULL;

    vrt_render_get_last_dirty_info(&real_dirty_rect_num, &real_dirty_rect);

    for (VfxU32 i = 0; i < real_dirty_rect_num; i++)
    {
        for (VfxU32 j = 0; j < dirty_rect_num; j++)
        {
            if (real_dirty_rect[i].origin.x >= dirty_rect[j].origin.x &&
                real_dirty_rect[i].origin.y >= dirty_rect[j].origin.y &&
                real_dirty_rect[i].size.width <= dirty_rect[j].size.width &&
                real_dirty_rect[i].size.width <= dirty_rect[j].size.width)
            {
                break;
            }
            else
            {
                if (j == dirty_rect_num - 1)
                {
                    return VFX_FALSE;
                }
                continue;
            }
        }
    }

    return VFX_TRUE;
}


VfxBool VtstDirtyScanPage::onPenInput(VfxPenEvent & event)
{
    if (event.type != VFX_PEN_EVENT_TYPE_UP)
    {
        return VFX_TRUE;
    }

    if (m_testcasestage == TESTCASE_INIT &&
        event.pos.x > UI_DEVICE_WIDTH/2)
    {
        runTestCase();
    }
    else
    {
        if (event.pos.x <= UI_DEVICE_WIDTH/2)
        {
            if (m_testcase == 0)
            {
                m_testcase = m_testcasecnt - 1;
            }
            else
            {
                m_testcase--;
            }
            
        }
        initTestCase();
    }

    return VFX_TRUE;
}

