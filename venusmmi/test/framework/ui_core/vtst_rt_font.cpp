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
 *  vtst_rt_font.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for Font
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vtst_rt_main.h"

#ifdef __AFX_RT_TEST__


/***************************************************************************** 
 * FontTest Implementation
 *****************************************************************************/

class VtstRtFont : public VtstRtScr
{
// Variable
public:
    VfxTextFrame   *m_text1;
    VfxTextFrame   *m_text2;
    VfxTextFrame   *m_text3;
    VfxTextFrame   *m_text4;
    VfxTextFrame   *m_text5;
    VfxTextFrame   *m_text6;

    VfxFontDesc     m_font1;
    VfxFontDesc     m_font2;
    VfxFontDesc     m_font3;
    VfxFontDesc     m_font4;
    VfxFontDesc     m_font5;
    VfxFontDesc     m_font6;
    VfxColor        m_textColor;
    VfxColor        m_borderColor;

// Constructor / Destructor
public:
    VtstRtFont() : 
        m_text1(NULL), 
        m_text2(NULL),
        m_text3(NULL),
        m_text4(NULL),
        m_text5(NULL),
        m_text6(NULL),
        m_font1(VFX_FONT_DESC_SIZE_MEDIUM),
        m_font2(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_ATTR_BOLD),
        m_font3(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_ATTR_OBLIQUE),
        m_font4(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_ATTR_ITALIC),
        m_font5(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_ATTR_UNDERLINE),
        m_font6(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_ATTR_STRIKETHROUGH),        
        m_textColor(VFX_COLOR_WHITE),
        m_borderColor(VFX_COLOR_BLACK)
    {
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Font Test"));

        VFX_OBJ_CREATE(m_text1, VfxTextFrame, this);
        m_text1->setPos(VfxPoint(10, 50));
        m_text1->setString(VFX_WSTR("Normal Font - ABCDE12345?!"));

        VFX_OBJ_CREATE(m_text2, VfxTextFrame, this);
        m_text2->setPos(VfxPoint(10, 80));
        m_text2->setString(VFX_WSTR("Bold Font - ABCDE12345?!"));

        VFX_OBJ_CREATE(m_text3, VfxTextFrame, this);
        m_text3->setPos(VfxPoint(10, 110));
        m_text3->setString(VFX_WSTR("Oblique Font - ABCDE12345?!"));

        VFX_OBJ_CREATE(m_text4, VfxTextFrame, this);
        m_text4->setPos(VfxPoint(10, 140));
        m_text4->setString(VFX_WSTR("Italic Font - ABCDE12345?!"));

        VFX_OBJ_CREATE(m_text5, VfxTextFrame, this);
        m_text5->setPos(VfxPoint(10, 170));
        m_text5->setString(VFX_WSTR("Underline Font - ABCDE12345?!"));

        VFX_OBJ_CREATE(m_text6, VfxTextFrame, this);
        m_text6->setPos(VfxPoint(10, 200));
        m_text6->setString(VFX_WSTR("Strike Font - ABCDE12345?!"));
    }

    virtual int start()
    {
        return 5; // no phase
    }

    void test0()
    {
        setTitle(VFX_WSTR("Normal"));
    }

    void test1()
    {
        setTitle(VFX_WSTR("Small"));
        m_font1.size = VFX_FONT_DESC_SIZE_SMALL;
        m_font2.size = VFX_FONT_DESC_SIZE_SMALL;
        m_font3.size = VFX_FONT_DESC_SIZE_SMALL;
        m_font4.size = VFX_FONT_DESC_SIZE_SMALL;
        m_font5.size = VFX_FONT_DESC_SIZE_SMALL;
        m_font6.size = VFX_FONT_DESC_SIZE_SMALL;
    }
    
    void test2()
    {
        setTitle(VFX_WSTR("Large"));
        m_font1.size = VFX_FONT_DESC_SIZE_LARGE;
        m_font2.size = VFX_FONT_DESC_SIZE_LARGE;
        m_font3.size = VFX_FONT_DESC_SIZE_LARGE;
        m_font4.size = VFX_FONT_DESC_SIZE_LARGE;
        m_font5.size = VFX_FONT_DESC_SIZE_LARGE;
        m_font6.size = VFX_FONT_DESC_SIZE_LARGE;
    }
    
    void test3()
    {
        setTitle(VFX_WSTR("Border"));
        m_font1.size = VFX_FONT_DESC_SIZE_MEDIUM;
        m_font2.size = VFX_FONT_DESC_SIZE_MEDIUM;
        m_font3.size = VFX_FONT_DESC_SIZE_MEDIUM;
        m_font4.size = VFX_FONT_DESC_SIZE_MEDIUM;
        m_font5.size = VFX_FONT_DESC_SIZE_MEDIUM;
        m_font6.size = VFX_FONT_DESC_SIZE_MEDIUM;
        m_font1.effect = VFX_FONT_DESC_EFFECT_BORDER;
        m_font2.effect = VFX_FONT_DESC_EFFECT_BORDER;
        m_font3.effect = VFX_FONT_DESC_EFFECT_BORDER;
        m_font4.effect = VFX_FONT_DESC_EFFECT_BORDER;
        m_font5.effect = VFX_FONT_DESC_EFFECT_BORDER;
        m_font6.effect = VFX_FONT_DESC_EFFECT_BORDER;
    }
    
    void test4()
    {
        setTitle(VFX_WSTR("Color"));
        m_textColor = VFX_COLOR_YELLOW;
        m_borderColor = VFX_COLOR_RED;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        switch (idx)
        {
            case 0:
                test0();
                break;

            case 1:
                test1();
                break;

            case 2:
                test2();
                break;

            case 3:
                test3();
                break;

            case 4:
                test4();
                break;
                
            default:
                VFX_ASSERT(0);
        }
        
        m_text1->setFont(m_font1);
        m_text2->setFont(m_font2);
        m_text3->setFont(m_font3);
        m_text4->setFont(m_font4);
        m_text5->setFont(m_font5);
        m_text6->setFont(m_font6);        
        
        m_text1->setColor(m_textColor);
        m_text2->setColor(m_textColor);
        m_text3->setColor(m_textColor);
        m_text4->setColor(m_textColor);
        m_text5->setColor(m_textColor);
        m_text6->setColor(m_textColor);

        m_text1->setBorderColor(m_borderColor);
        m_text2->setBorderColor(m_borderColor);
        m_text3->setBorderColor(m_borderColor);
        m_text4->setBorderColor(m_borderColor);
        m_text5->setBorderColor(m_borderColor);
        m_text6->setBorderColor(m_borderColor);
        
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_font(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFont);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Vector Font Test Implementation
 *****************************************************************************/

class VtstRtVectorFont : public VtstRtScr
{
// Variable
public:
    VfxTextFrame   *m_text[10];

// Constructor / Destructor
public:
    VtstRtVectorFont()
    {
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Font Test"));

        VfxS32 y = 50;
        VfxS32 i;
        for (i = 0; i < 10; i++)
        {
            VfxU8 size = 8 + i * 4;
            
            VFX_OBJ_CREATE(m_text[i], VfxTextFrame, this);
            m_text[i]->setPos(VfxPoint(10, y));
            m_text[i]->setString(VFX_WSTR("VF"));
            m_text[i]->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(size)));

            y += size;
        }
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it work?"));
        
        return -1;
    }
};


VtstTestResultEnum vtst_rt_vector_font(VfxU32 param)
{
    VTST_START_SCRN(VtstRtVectorFont);
    return VTST_TR_OK;
}


#endif // __AFX_RT_TEST__


