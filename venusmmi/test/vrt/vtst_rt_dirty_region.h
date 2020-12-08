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
 *  vtst_rt_dirty_region.h
 *
 * Project:
 * --------
 *  Venus Rendering Task
 *
 * Description:
 * ------------
 *  head file of Venus Regression Test for VRT dirty region
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

/***************************************************************************** 
* Include
*****************************************************************************/
#include "vfx_page.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"
#include "vfx_datatype.h"
#include "vfx_text_frame.h"
#include "vcp_text_view.h"
#include "lcd_sw_inc.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define START_Y (UI_DEVICE_HEIGHT/4)
#define FWIDTH  (UI_DEVICE_WIDTH/6)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef void (VfxObject::*VfxMemFunc)();

/***************************************************************************** 
 * Class VtstDirtyScanPage
 *****************************************************************************/
class VtstDirtyScanPage : public VfxPage
{
    VFX_DECLARE_CLASS(VtstDirtyScanPage);

public:
    VtstDirtyScanPage();
    void onInit();
    void onDeinit();

    VfxBool onPenInput(VfxPenEvent & event);

private:
    void initTestCase();
    void runTestCase();
    void addDirtyRect(const VfxRect &dirty_rect);
    VfxBool verifyDiryRect();

public:    
    void case1();
    void runCase1();
    void case2();
    void runCase2();
    void case3();
    void runCase3();
    void case4();
    void runCase4();
    void case5();
    void runCase5();
    void case6();
    void runCase6();
    void case7();
    void runCase7();
    void case8();
    void runCase8();
    void case9();
    void runCase9();

private:
    enum TestCaseStageEnum
    {
        TESTCASE_INIT,
        TESTCASE_FINISH
    };
    
    VfxU32 m_testcasecnt;
    VfxU32 m_testcase;
    TestCaseStageEnum m_testcasestage;    

    VcpTextView  *m_description;
    VcpTextView  *m_indexframe;

    VfxTextFrame *m_frame1;
    VfxTextFrame *m_frame2;
    VfxTextFrame *m_frame3;
    VfxTextFrame *m_frame4;
    VfxTextFrame *m_frame5;

    VfxU32 dirty_rect_num;
    VfxRect dirty_rect[6];
};

