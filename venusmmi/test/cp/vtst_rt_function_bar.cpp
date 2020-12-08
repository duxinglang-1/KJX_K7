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
 *  vtst_rt_function_bar.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for VcpFunctionBar
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vtst_rt_main.h"

#if defined(__AFX_RT_TEST__)  && defined(__MMI_VUI_COSMOS_CP__)

#include "vcp_include.h"
#include "vcp_function_bar.h"
#include "GlobalResDef.h"

/***************************************************************************** 
 * Control Test Implementation
 *****************************************************************************/
#ifdef __MMI_MAINLCD_480X800__
    #define FBAR_SCR_WIDTH           480
    #define FBAR_SCR_HEIGHT          800
    #define FBAR_SCR_BUTTON_HEIGHT   30  
    #define FBAR_SCR_START_Y         50
    #define FBAR_FONT_SIZE           18
    #define FBAR_LABEL_HEIGHT        30
#elif defined(__MMI_MAINLCD_320X480__)
    #define FBAR_SCR_WIDTH           320
    #define FBAR_SCR_HEIGHT          480
    #define FBAR_SCR_BUTTON_HEIGHT   25  
    #define FBAR_SCR_START_Y         50
    #define FBAR_FONT_SIZE           18
    #define FBAR_LABEL_HEIGHT        30
#elif defined(__MMI_MAINLCD_240X400__)
    #define FBAR_SCR_WIDTH           240
    #define FBAR_SCR_HEIGHT          400
    #define FBAR_SCR_BUTTON_HEIGHT   20  
    #define FBAR_SCR_START_Y         20
    #define FBAR_FONT_SIZE           12
    #define FBAR_LABEL_HEIGHT        15
#elif defined(__MMI_MAINLCD_240X320__)
    #define FBAR_SCR_WIDTH           240
    #define FBAR_SCR_HEIGHT          320
    #define FBAR_SCR_BUTTON_HEIGHT   20  
    #define FBAR_SCR_START_Y         20
    #define FBAR_FONT_SIZE           12
    #define FBAR_LABEL_HEIGHT        15
#else 
    #define FBAR_SCR_WIDTH           240
    #define FBAR_SCR_HEIGHT          320
    #define FBAR_SCR_BUTTON_HEIGHT   20  
    #define FBAR_SCR_START_Y         20
    #define FBAR_FONT_SIZE           12
    #define FBAR_LABEL_HEIGHT        15
#endif


class VtstRtFunctionBar : public VtstRtScr
{
// Variable
public:
    VcpFunctionBar *m_bar;
    VfxTextFrame *m_curValue;
    VfxBool m_disable;
    VfxBool m_iconOrString;
    VfxS32 m_but_count;
// Constructor / Destructor
public:
    VtstRtFunctionBar()
    {
        m_but_count = 0;
    }

// Override
public:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        VfxS32 x, y, w, h;
        x = 10;
        y = FBAR_SCR_START_Y + FBAR_LABEL_HEIGHT;
        w = (FBAR_SCR_WIDTH - 20)/2;
        h = FBAR_SCR_BUTTON_HEIGHT;
        
        VcpButton *addButton1;
        VFX_OBJ_CREATE(addButton1,VcpButton, this);
        addButton1->setPos(x, y);
        addButton1->setSize(w, h);
        addButton1->setText(VFX_WSTR("Add a button"));
        addButton1->setTextFont(VFX_FONT_DESC_SMALL);
        addButton1->m_signalClicked.connect(this, &VtstRtFunctionBar::onAddButton);

        x += w;

        VcpSegmentButton *toggleIconString;
        VFX_OBJ_CREATE(toggleIconString,VcpSegmentButton, this);
        toggleIconString->setPos(x, y);
        toggleIconString->setSize(w, h);
        toggleIconString->addButton('IMAG', VcpStateImage(IMG_GLOBAL_L1), VFX_WSTR("Icon"));
        toggleIconString->addButton('STRI', VcpStateImage(IMG_GLOBAL_L2), VFX_WSTR("String"));
        toggleIconString->setType(VCP_SEGMENT_BUTTON_TYPE_RADIO);
        toggleIconString->setStyle(VCP_SEGMENT_BUTTON_STYLE_TEXT_ONLY);
        toggleIconString->m_signalButtonClicked.connect(this, &VtstRtFunctionBar::onToggleIconString);
        toggleIconString->setButtonIsHighlighted('IMAG', VFX_TRUE);
        m_iconOrString = VFX_TRUE; // ICons

        x = 10;
        y += FBAR_SCR_BUTTON_HEIGHT;
        w = FBAR_SCR_WIDTH - 20;
        
        VcpButton *removeButton1;
        VFX_OBJ_CREATE(removeButton1,VcpButton, this);
        removeButton1->setPos(x, y);
        removeButton1->setSize(w, h);
        removeButton1->setText(VFX_WSTR("Remove a button"));
        removeButton1->setTextFont(VFX_FONT_DESC_SMALL);
        removeButton1->m_signalClicked.connect(this, &VtstRtFunctionBar::onRemoveButton);

        y += FBAR_SCR_BUTTON_HEIGHT;
            
        VcpButton *setSpecialButton;
        VFX_OBJ_CREATE(setSpecialButton,VcpButton, this);
        setSpecialButton->setPos(x, y);
        setSpecialButton->setSize(w, h);
        setSpecialButton->setText(VFX_WSTR("Set Button 2 as Special"));
        setSpecialButton->setTextFont(VFX_FONT_DESC_SMALL);
        setSpecialButton->m_signalClicked.connect(this, &VtstRtFunctionBar::onSpecialSet);

        y += FBAR_SCR_BUTTON_HEIGHT;

        VcpButton *setDisableButton;
        VFX_OBJ_CREATE(setDisableButton,VcpButton, this);
        setDisableButton->setPos(x, y);
        setDisableButton->setSize(w, h);
        setDisableButton->setText(VFX_WSTR("Disable/Enable Button 1"));
        setDisableButton->setTextFont(VFX_FONT_DESC_SMALL);
        setDisableButton->m_signalClicked.connect(this, &VtstRtFunctionBar::onToggleDisable);

        y += FBAR_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_bar, VcpFunctionBar, this);
        m_bar->setPos(0, y + 5);
        m_bar->m_signalButtonTap.connect(this, &VtstRtFunctionBar::onClick);

        VfxFrame *f;
        VFX_OBJ_CREATE(f,VfxFrame,this);
        f->setPos(0, m_bar->getPos().y + m_bar->getSize().height + 1);
        f->setBounds(0, 0, FBAR_SCR_WIDTH, FBAR_SCR_HEIGHT - m_bar->getSize().height);
        f->setBgColor(VFX_COLOR_YELLOW);        

        VfxTextFrame *t;
        VFX_OBJ_CREATE(t,VfxTextFrame,f);
        t->setPos(f->getSize().width/2, 20);
        t->setString(VFX_WSTR("VK"));
        t->setBgColor(VFX_COLOR_YELLOW);
        t->setColor(VFX_COLOR_BLUE);
        t->setBorderColor(VFX_COLOR_GREEN);
        // return 0;
    }

    void onSpecialSet(VfxObject* sender, VfxId id)
    {    
        m_bar->setItemSpecial('ADD1');
    }

    void onToggleDisable(VfxObject* sender, VfxId id)
    {    
            m_disable = m_disable ? VFX_FALSE : VFX_TRUE;
            m_bar->setDisableItem('ADD0', m_disable);
    }


    void onToggleIconString(VfxObject* sender, VfxId id)
    {    
            switch(id)
            {
                case 'IMAG':
                        m_iconOrString = VFX_TRUE;
                        break;
                case 'STRI':
                        m_iconOrString = VFX_FALSE;
                        break;
                default :
                        {}
            }
    }

    void onAddButton(VfxObject* sender, VfxId id)
    {
        if(m_but_count < 4)
        {
            VfxWString str(VFX_WSTR("But"));
            switch(m_but_count)
            {
                case 0:
                        str+=VFX_WSTR(" 1");
                        m_disable = VFX_FALSE;
                        break;
                case 1:
                        str+=VFX_WSTR(" 2");
                        break;
                case 2:
                        str+=VFX_WSTR(" 3");
                        break;
                case 3:
                        str+=VFX_WSTR(" 4");
                        break;
                default :
                        {}
            }
            if(m_iconOrString)
            {
                m_bar->addItem('ADD0' + m_but_count, IMG_GLOBAL_L1 + m_but_count);
            }
            else
            {
                m_bar->addItem('ADD0' + m_but_count, str);
            }
            m_but_count++;
        }
    }

    void onRemoveButton(VfxObject* sender, VfxId id)
    {
        if(m_but_count > 0)
        {
            m_but_count--;
            m_bar->removeItem('ADD0' + m_but_count);
        }
    }
    
    void onClick(VfxObject *sender, // Slider pointer
                    VfxId id // Button ID
                    )
    {
        VfxFrame *f;
        VFX_OBJ_CREATE(f,VfxFrame,this);
        f->setPos(0, FBAR_SCR_START_Y);
        f->setBounds(0, 0, FBAR_SCR_WIDTH, FBAR_LABEL_HEIGHT - 5);
        f->setBgColor(VFX_COLOR_YELLOW);

        VfxWString str(VFX_WSTR("Click event : "));
        switch(id)
        {
        case 'ADD0':
                str+=VFX_WSTR("But 1");
                break;
        case 'ADD1':
                str+=VFX_WSTR("But 2");
                break;
        case 'ADD2':
                str+=VFX_WSTR("But 3");
                break;
        case 'ADD3':
                str+=VFX_WSTR("But 4");
                break;
        default :
                {}
        }
        VfxTextFrame *t;
        VFX_OBJ_CREATE(t,VfxTextFrame,this);
        t->setPos(50, FBAR_SCR_START_Y);
        t->setString(str);
        t->setBgColor(VFX_COLOR_YELLOW);
        t->setColor(VFX_COLOR_BLUE);
        t->setBorderColor(VFX_COLOR_GREEN);
        VfxFontDesc font;
        font.size = VFX_FONT_DESC_VF_SIZE(FBAR_FONT_SIZE);
        t->setFont(font);
    }

    virtual void onQueryRotateEx(const VfxScreenRotateParam &param)
    {  
    }

	void onRotate(const VfxScreenRotateParam &param)
	{
	    vrt_size_struct main_screen_size;
	    vrt_color_type_enum main_screen_color_format;
	    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        switch(param.rotateTo)
        {  
            case VFX_SCR_ROTATE_TYPE_NORMAL:                
            case VFX_SCR_ROTATE_TYPE_90:                
            case VFX_SCR_ROTATE_TYPE_180:                
            case VFX_SCR_ROTATE_TYPE_LANDSCAPE:
                m_bar->setLayout(param.rotateTo);
                break;
            default:
                break;
        }

	    VtstRtScr::onRotate(param);
	}

   virtual VfxS32 phase(VfxS32 idx)
    {
        setTitle(VFX_WSTR("Fuction Bar Test"));
        confirm(VFX_WSTR("Result is correct?"));
        
        return -1;
    }

    virtual VfxS32 start() {return 1;}
};


VtstTestResultEnum vtst_rt_function_bar(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFunctionBar);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

