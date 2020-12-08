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
 *  vtst_rt_basic_types.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for basic types
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
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_system.h"
#include "vfx_basic_type.h"
#include "vfx_image_src.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_app_cat_scr.h"

extern "C"
{
#include "GlobalResDef.h"    
}


/***************************************************************************** 
 * Basic Type Test Implementation
 *****************************************************************************/

class VtstRtBasicTypes : public VtstRtScr
{
// Variable
public:
    VfxWString m_strMember;
    
// Constructor / Destructor
public:
    VtstRtBasicTypes() : 
        m_strMember(VFX_WSTR("<Member>"))
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
    }

    virtual int start()
    {
        return 3;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        switch(m_phase)
        {
            case 0:
                phaseString();
                break;
                
            case 1:
                phaseColor();
                break;
                
            case 2:
                phaseImageSrc();
                break;
                
            case 3:
                phaseImageList();
                break;
                
            default:
                break;
        }
        return 0;
    }

    void phaseString()
    {
        setTitle(VFX_WSTR("VfxWString"));

        VfxWString strNull1(VFX_WSTR("ABC"));
        VfxWString strNull2;
        VfxWString strNull3 = strNull2;
        VfxWString strTemp1(m_strMember);
        VfxWString strTemp2(m_strMember);
        VfxWString strTemp3(VFX_WSTR("<Local>"));

        // Test null string
        strNull1.setNull();
        check(strNull1.isNull(),        VFX_WSTR("VfxWString NULL #1"));
        check(strNull3.isNull(),        VFX_WSTR("VfxWString NULL #2"));
        check(!m_strMember.isNull(),    VFX_WSTR("VfxWString NULL #3"));
        check(!strTemp3.isNull(),       VFX_WSTR("VfxWString NULL #4"));

        // Test string compare
        check(strNull1 == VFX_WSTR_NULL,        VFX_WSTR("VfxWString compare #1"));
        check(strNull1 == strNull1,             VFX_WSTR("VfxWString compare #2"));
        check(strNull2 == strNull1,             VFX_WSTR("VfxWString compare #3"));
        check(strNull1 != strTemp1,             VFX_WSTR("VfxWString compare #4"));
        check(strTemp2 == VFX_WSTR("<Member>"), VFX_WSTR("VfxWString compare #5"));        
        check(strTemp1 == strTemp2,             VFX_WSTR("VfxWString compare #6"));
        check(strTemp2 == strTemp1,             VFX_WSTR("VfxWString compare #7"));
        check(strTemp2 != strTemp3,             VFX_WSTR("VfxWString compare #8"));
        check(strTemp3 == VFX_WSTR("<Local>"),  VFX_WSTR("VfxWString compare #9"));

        // Test string assignment
        strTemp3 = strTemp1;        
        check(strTemp3 == VFX_WSTR("<Member>"), VFX_WSTR("VfxWString assign #1"));
        strTemp2 = strNull1;        
        check(strTemp2.isNull(),                VFX_WSTR("VfxWString assign #2"));
        strNull2 = strNull1;        
        check(strTemp2.isNull(),                VFX_WSTR("VfxWString assign #3"));
        strNull3 = VFX_WSTR("<Hello>");        
        check(strNull3 == VFX_WSTR("<Hello>"),  VFX_WSTR("VfxWString assign #4"));

        // Test String Length
        VfxWString strTemp4 = VFX_WSTR("ABCDEFG");
        check(strTemp4.getLength() == 7,        VFX_WSTR("VfxWString length #1"));
        check(strNull1.getLength() == 0,        VFX_WSTR("VfxWString length #2"));

        // Test lock buffer
        VfxWChar *p = strTemp4.lockBuf(256);
        vfx_sys_wcscpy(p, (const VfxWChar *)L"12345");
        strTemp4.unlockBuf();
        check(strTemp4 == VFX_WSTR("12345"),    VFX_WSTR("VfxWString lock #1"));
        check(strTemp4.getLength() == 5,        VFX_WSTR("VfxWString lock #2"));

        strTemp4.lockBuf(3);
        strTemp4.unlockBuf();
        check(strTemp4 == VFX_WSTR("12"),       VFX_WSTR("VfxWString lock #3"));

        check(strTemp4[0] == (VfxWChar)L'1',    VFX_WSTR("VfxWString at #1"));
        check(strTemp4[1] == (VfxWChar)L'2',    VFX_WSTR("VfxWString at #2"));
        check(strTemp4[2] == 0,                 VFX_WSTR("VfxWString at #3"));

        // Test format
        VfxWString strTemp6;
        strTemp6.format("(%d, %d)", 100, 200);
        VFX_ASSERT(strTemp6 == VFX_WSTR("(100, 200)"));
        
        VfxWString strTempFormat1 = VFX_WSTR("(%d, %d)");
        VfxWString strTemp7;
        strTemp7.format(strTempFormat1, 100, 200);
        VFX_ASSERT(strTemp7 == VFX_WSTR("(100, 200)"));
    }

    void phaseColor()
    {
        setTitle(VFX_WSTR("VfxColor"));

        VfxColor color0;
        check(color0.value == 0, VFX_WSTR("Zero VfxColor #1"));
        check(color0.getA() == 0, VFX_WSTR("Zero VfxColor #2"));
        check(color0.getR() == 0, VFX_WSTR("Zero VfxColor #3"));
        check(color0.getG() == 0, VFX_WSTR("Zero VfxColor #4"));
        check(color0.getB() == 0, VFX_WSTR("Zero VfxColor #5"));
        
        VfxColor color1(0x11, 0x22, 0x33, 0x44);
        check(color1.value == 0x11223344, VFX_WSTR("Construct VfxColor #1"));
        check(color1.getA() == 0x11, VFX_WSTR("Construct VfxColor #2"));
        check(color1.getR() == 0x22, VFX_WSTR("Construct VfxColor #3"));
        check(color1.getG() == 0x33, VFX_WSTR("Construct VfxColor #4"));
        check(color1.getB() == 0x44, VFX_WSTR("Construct VfxColor #5"));

        VfxColor color2(0xaabbccdd);
        check(color2.value == 0xaabbccdd, VFX_WSTR("Construct VfxColor #6"));

        VfxColor color3(color2);
        check(color3.value == 0xaabbccdd, VFX_WSTR("Construct VfxColor #7"));

        color3 = color1;
        check(color3.value == 0x11223344, VFX_WSTR("Assign VfxColor #1"));
        
        check(color3 == color1, VFX_WSTR("Compare VfxColor #1"));
        check(color3 != color2, VFX_WSTR("Compare VfxColor #2"));
        check(color3 == color3, VFX_WSTR("Compare VfxColor #3"));

        color1.setA(0x55);
        check(color1.value == 0x55223344, VFX_WSTR("Set VfxColor #1"));
        color1.setR(0x66);
        check(color1.value == 0x55663344, VFX_WSTR("Set VfxColor #2"));
        color1.setG(0x77);
        check(color1.value == 0x55667744, VFX_WSTR("Set VfxColor #3"));
        color1.setB(0x88);
        check(color1.value == 0x55667788, VFX_WSTR("Set VfxColor #4"));
    }

    void phaseImageSrc()
    {
        setTitle(VFX_WSTR("VfxImageSrc"));
        
        // Null image source
        VfxImageSrc img0;
        check(img0.isNull(), VFX_WSTR("Null VfxImageSrc #1"));
        check(img0.getType() == VFX_IMAGE_SRC_TYPE_NULL, VFX_WSTR("Null VfxImageSrc #2"));
        check(img0 == VFX_IMAGE_SRC_NULL, VFX_WSTR("Null VfxImageSrc #3"));
        check(img0.getResId()== VFX_RES_ID_NULL, VFX_WSTR("Null VfxImageSrc #4"));
        img0.setNull();
        check(img0.isNull(), VFX_WSTR("Null VfxImageSrc #5"));

        // Resource ID
        VfxImageSrc img1(IMG_GLOBAL_L1);
        check(!img1.isNull(), VFX_WSTR("Res ID VfxImageSrc #1"));
        check(img1.getType() == VFX_IMAGE_SRC_TYPE_RES_ID, VFX_WSTR("Res ID VfxImageSrc #2"));
        check(img1.getResId() == IMG_GLOBAL_L1, VFX_WSTR("Res ID VfxImageSrc #3"));

        VfxImageSrc img2;
        img2.setResId(IMG_GLOBAL_L1);
        check(!img2.isNull(), VFX_WSTR("Res ID VfxImageSrc #4"));
        check(img2.getType() == VFX_IMAGE_SRC_TYPE_RES_ID, VFX_WSTR("Res ID VfxImageSrc #5"));
        check(img2.getResId() == IMG_GLOBAL_L1, VFX_WSTR("Res ID VfxImageSrc #6"));

        check(img1 == img2, VFX_WSTR("Res ID VfxImageSrc #7"));
        check(img1 == VfxImageSrc(IMG_GLOBAL_L1), VFX_WSTR("Res ID VfxImageSrc #8"));
        check(img1 != VfxImageSrc(IMG_GLOBAL_L2), VFX_WSTR("Res ID VfxImageSrc #9"));

        // Image Buffer
        VfxImageBuffer imgBuf1;
        imgBuf1.ptr         = (VfxU8 *)0x12345678;
        imgBuf1.pitchBytes  = 100;
        imgBuf1.width       = 200;
        imgBuf1.width       = 300;
        imgBuf1.colorFormat = VRT_COLOR_TYPE_RGB565;
        
        VfxImageSrc img3(imgBuf1);
        check(!img3.isNull(), VFX_WSTR("ImgBuf VfxImageSrc #1"));
        check(img3.getType() == VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER, VFX_WSTR("ImgBuf VfxImageSrc #2"));
        check(img3.getImageBuffer() == imgBuf1, VFX_WSTR("ImgBuf VfxImageSrc #3"));

        VfxImageSrc img4;
        img4.setImageBuffer(imgBuf1);
        check(!img4.isNull(), VFX_WSTR("ImgBuf VfxImageSrc #4"));
        check(img4.getType() == VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER, VFX_WSTR("ImgBuf VfxImageSrc #5"));
        check(img4 == VfxImageSrc(imgBuf1), VFX_WSTR("ImgBuf VfxImageSrc #6"));

        check(img3 == img4, VFX_WSTR("ImgBuf VfxImageSrc #7"));
        imgBuf1.ptr = (VfxU8 *)0x87654321;
        check(img3 != VfxImageSrc(imgBuf1), VFX_WSTR("ImgBuf VfxImageSrc #8"));

        // Path
        VfxImageSrc img5(VFX_WSTR("HELLO"));
        check(!img5.isNull(), VFX_WSTR("Path VfxImageSrc #1"));
        check(img5.getType() == VFX_IMAGE_SRC_TYPE_PATH, VFX_WSTR("Path VfxImageSrc #2"));
        check(img5.getPath() == VFX_WSTR("HELLO"), VFX_WSTR("Path VfxImageSrc #3"));

        VfxImageSrc img6;
        img6.setPath(VFX_WSTR("HELLO"));
        check(!img6.isNull(), VFX_WSTR("Path VfxImageSrc #4"));
        check(img6.getType() == VFX_IMAGE_SRC_TYPE_PATH, VFX_WSTR("Path VfxImageSrc #5"));
        check(img6.getPath() == VFX_WSTR("HELLO"), VFX_WSTR("Path VfxImageSrc #6"));

        check(img5 == img6, VFX_WSTR("Path VfxImageSrc #7"));
        check(img5 == VfxImageSrc(VFX_WSTR("HELLO")), VFX_WSTR("Path VfxImageSrc #8"));
        check(img5 != VfxImageSrc(VFX_WSTR("WORLD")), VFX_WSTR("Path VfxImageSrc #9"));

        // Remix
        check(img0 != img1, VFX_WSTR("Remix VfxImageSrc #1"));
        check(img1 != img3, VFX_WSTR("Remix VfxImageSrc #1"));
        check(img3 != img5, VFX_WSTR("Remix VfxImageSrc #2"));

        img0 = img1;
        check(img0.getResId() == IMG_GLOBAL_L1, VFX_WSTR("Remix VfxImageSrc #3"));
        
        img3 = img5;
        check(img3.getPath() == VFX_WSTR("HELLO"), VFX_WSTR("Remix VfxImageSrc #4"));
    }

    void phaseImageList()
    {
        setTitle(VFX_WSTR("VfxImageList"));

        // test add item
        VfxImageList imgListTmp1;
        imgListTmp1.setItemWithResId('IT06', IMG_GLOBAL_L1);
        imgListTmp1.setItemWithResId('IT07', IMG_GLOBAL_L2);
        imgListTmp1.setItemWithResId('IT08', IMG_GLOBAL_L3);
        imgListTmp1.setItemWithResId('IT09', IMG_GLOBAL_L4);
        imgListTmp1.setItemWithResId('IT10', IMG_GLOBAL_L5);
        
        imgListTmp1.setItemWithResId('IT06', IMG_GLOBAL_L6);
        imgListTmp1.setItemWithResId('IT07', IMG_GLOBAL_L7);
        imgListTmp1.setItemWithResId('IT08', IMG_GLOBAL_L8);
        imgListTmp1.setItemWithResId('IT09', IMG_GLOBAL_L9);
        imgListTmp1.setItemWithResId('IT10', IMG_GLOBAL_L10);

        // Test copy constructor
        VfxImageList imgListTemp2(imgListTmp1);

        // Test assign operator
        VfxImageList imgList;
        VfxS32 i;
        for (i = 1; i <= 100; i++)
        {
            imgList.setItemWithResId(i, IMG_GLOBAL_L11);
        }
        imgList = imgListTemp2;

        // Check the result
        check(imgList['IT06'].getResId() == IMG_GLOBAL_L6, VFX_WSTR("VfxImageList #1"));
        check(imgList['IT07'].getResId() == IMG_GLOBAL_L7, VFX_WSTR("VfxImageList #2"));
        check(imgList['IT08'].getResId() == IMG_GLOBAL_L8, VFX_WSTR("VfxImageList #3"));
        check(imgList['IT09'].getResId() == IMG_GLOBAL_L9, VFX_WSTR("VfxImageList #4"));
        check(imgList['IT10'].getResId() == IMG_GLOBAL_L10, VFX_WSTR("VfxImageList #5"));
        check(imgList['NONE'].isNull(), VFX_WSTR("VfxImageList #6"));

        // Check empty list
        VfxImageList emptyList;
        check(emptyList.isEmpty(), VFX_WSTR("Empty VfxImageList #1"));
        check(!imgListTmp1.isEmpty(), VFX_WSTR("Empty VfxImageList #2"));
        
        imgListTmp1 = emptyList;
        check(imgListTmp1.isEmpty(), VFX_WSTR("Empty VfxImageList #3"));

        imgListTemp2.removeItem('IT10');
        imgListTemp2.removeItem('IT09');
        imgListTemp2.removeItem('IT06');
        imgListTemp2.removeItem('IT07');
        imgListTemp2.removeItem('IT06');
        imgListTemp2.removeItem('IT07');
        imgListTemp2.removeItem('IT08');
        imgListTemp2.removeItem('IT09');
        imgListTemp2.removeItem('IT08');
        imgListTemp2.removeItem('IT09');
        check(imgListTemp2.isEmpty(), VFX_WSTR("Empty VfxImageList #4"));

        // Check remove
        imgList.setItem('NONE', VFX_IMAGE_SRC_NULL);
        check(imgList['NONE'].isNull(), VFX_WSTR("Remove VfxImageList #1"));
        imgList.setItem('IT08', VFX_IMAGE_SRC_NULL);
        check(imgList['IT08'].isNull(), VFX_WSTR("Remove VfxImageList #2"));
        imgList.removeItem('IT10');
        check(imgList['IT10'].isNull(), VFX_WSTR("Remove VfxImageList #3"));
        imgList.removeItem('IT10');
        check(imgList['IT10'].isNull(), VFX_WSTR("Remove VfxImageList #4"));
        check(!imgList.isEmpty(), VFX_WSTR("Remove VfxImageList #5"));
        check(imgList['IT06'].getResId() == IMG_GLOBAL_L6, VFX_WSTR("Remove VfxImageList #6"));
        check(imgList['IT07'].getResId() == IMG_GLOBAL_L7, VFX_WSTR("Remove VfxImageList #7"));
        check(imgList['IT09'].getResId() == IMG_GLOBAL_L9, VFX_WSTR("Remove VfxImageList #8"));


        // Check operator assign
        VfxImageList imgList2;
        imgList2.setItemWithResId('AA01', IMG_GLOBAL_L1);
        imgList2.setItemWithResId('AA02', IMG_GLOBAL_L2);

        VfxImageList imgList3;
        imgList3.setItemWithResId('BB01', IMG_GLOBAL_L1);
        imgList3.setItemWithResId('BB02', IMG_GLOBAL_L2);
        imgList3.setItemWithResId('BB03', IMG_GLOBAL_L2);

        VfxImageList imgList2b(imgList2);
        VfxImageList imgList3b(imgList3);
        
        imgList2 = imgList3;
        check(imgList2['AA02'] == VFX_IMAGE_SRC_NULL, VFX_WSTR("Assgin VfxImageList #1"));
        check(imgList2['BB02'] == VfxImageSrc(IMG_GLOBAL_L2), VFX_WSTR("Assgin VfxImageList #2"));
        
        imgList3b = imgList2b;
        check(imgList3b['BB02'] == VFX_IMAGE_SRC_NULL, VFX_WSTR("Assgin VfxImageList #3"));
        check(imgList3b['AA02'] == VfxImageSrc(IMG_GLOBAL_L2), VFX_WSTR("Assgin VfxImageList #4"));
    }
};


VtstTestResultEnum vtst_rt_basic_types(VfxU32 param)
{
    VTST_START_SCRN(VtstRtBasicTypes);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

