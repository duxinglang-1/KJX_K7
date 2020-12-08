/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *  vapp_calculator.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 extern "C"
{
#include "mmi_features.h"
}

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_page_panel.h"

#ifdef __MMI_CALCULATOR__
#include "filemgrsrvgprot.h"
#include "GlobalResDef.h"
#include "vapp_calculator.h"
#include "mmi_rp_vapp_calculator_def.h"
#include "vfx_adp_device.h"

extern "C"
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__) 
#include "dcmgr.h" // DCM
#endif
}

/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/

#pragma arm section code = "DYNAMIC_CODE_CALC_ROCODE", rodata = "DYNAMIC_CODE_CALC_RODATA"
/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
const VfxS32 CALC_EDITOR_BUFFER_LENGTH = 72;
VfxWChar CALC_BUFFER_POOL[CALC_EDITOR_BUFFER_LENGTH + 1]= {0};

#if defined (__MMI_MAINLCD_240X320__)
const VfxS32 CALC_STATUS_BAR_HIGHT = 24;
const VfxS32 CALC_BUTTON_ORIGIN_Y = 82;
const VfxS32 CALC_SIDE_BORDER = 8;
const VfxS32 CALC_BUTTON_HORIZONTAL_GAP = 6;
const VfxS32 CALC_BUTTON_VERTICAL_GAP = 2;
const VfxS32 CALC_BUTTON_WIDTH = 40;
const VfxS32 CALC_BUTTON_HIGHT = 40;
const VfxS32 CALC_WIDE_BUTTON_WIDTH = 86;
const VfxS32 CALC_BUTTON_FONT_SIZE = 23;
const VfxS32 CALC_BUTTON_HIGH_LIGHT_BORDER = 10;
const VfxS32 CALC_EDITOR_FONT_SIZE = 36;
const VfxS32 CALC_LCD_SIZE_X = 222;
const VfxS32 CALC_LCD_SIZE_Y = 59;
const VfxS32 CALC_LCD_POSITION_X = 9;
const VfxS32 CALC_LCD_POSITION_Y = 9;

#elif defined (__MMI_MAINLCD_240X400__)
const VfxS32 CALC_STATUS_BAR_HIGHT = 24;
const VfxS32 CALC_BUTTON_ORIGIN_Y = 143;
const VfxS32 CALC_SIDE_BORDER = 8;
const VfxS32 CALC_BUTTON_HORIZONTAL_GAP = 6;
const VfxS32 CALC_BUTTON_VERTICAL_GAP = 6;
const VfxS32 CALC_BUTTON_WIDTH = 40;
const VfxS32 CALC_BUTTON_HIGHT = 40;
const VfxS32 CALC_WIDE_BUTTON_WIDTH = 86;
const VfxS32 CALC_BUTTON_FONT_SIZE = 23;
const VfxS32 CALC_BUTTON_HIGH_LIGHT_BORDER = 10;
const VfxS32 CALC_EDITOR_FONT_SIZE = 36;
const VfxS32 CALC_LCD_SIZE_X = 222;
const VfxS32 CALC_LCD_SIZE_Y = 113;
const VfxS32 CALC_LCD_POSITION_X = 9;
const VfxS32 CALC_LCD_POSITION_Y = 10;

#elif defined (__MMI_MAINLCD_320X480__)
const VfxS32 CALC_STATUS_BAR_HIGHT = 24;
const VfxS32 CALC_BUTTON_ORIGIN_Y = 169;
const VfxS32 CALC_SIDE_BORDER = 13;
const VfxS32 CALC_BUTTON_HORIZONTAL_GAP = 9;
const VfxS32 CALC_BUTTON_VERTICAL_GAP = 4;
const VfxS32 CALC_BUTTON_WIDTH = 52;
const VfxS32 CALC_BUTTON_HIGHT = 52;
const VfxS32 CALC_WIDE_BUTTON_WIDTH = 113;
const VfxS32 CALC_BUTTON_FONT_SIZE = 30;
const VfxS32 CALC_BUTTON_HIGH_LIGHT_BORDER = 20;
const VfxS32 CALC_EDITOR_FONT_SIZE = 50;
const VfxS32 CALC_LCD_SIZE_X = 294;
const VfxS32 CALC_LCD_SIZE_Y = 134;
const VfxS32 CALC_LCD_POSITION_X = 13;
const VfxS32 CALC_LCD_POSITION_Y = 16;

#elif defined (__MMI_MAINLCD_480X800__)
const VfxS32 CALC_STATUS_BAR_HIGHT = 38;
const VfxS32 CALC_BUTTON_ORIGIN_Y = 288;
const VfxS32 CALC_SIDE_BORDER = 20;
const VfxS32 CALC_BUTTON_HORIZONTAL_GAP = 14;
const VfxS32 CALC_BUTTON_VERTICAL_GAP = 15;
const VfxS32 CALC_BUTTON_WIDTH = 77;
const VfxS32 CALC_BUTTON_HIGHT = 78;
const VfxS32 CALC_WIDE_BUTTON_WIDTH = 168;
const VfxS32 CALC_BUTTON_FONT_SIZE = 45;
const VfxS32 CALC_BUTTON_HIGH_LIGHT_BORDER = 24;
const VfxS32 CALC_EDITOR_FONT_SIZE = 72;
const VfxS32 CALC_LCD_SIZE_X = 441;
const VfxS32 CALC_LCD_SIZE_Y = 223;
const VfxS32 CALC_LCD_POSITION_X =20;
const VfxS32 CALC_LCD_POSITION_Y = 22;
#endif

/***************************************************************************** 
 * Class VappCalculatorButton
 *****************************************************************************/

//VFX_IMPLEMENT_CLASS("VappCalculatorButton", VappCalculatorButton, VcpButton);

VfxWChar VappCalculatorButton :: getOutputWChar()
{
	return outputWChar;
}

void VappCalculatorButton :: setOutputWChar(VfxWChar btnOutputWChar)
{
	outputWChar = btnOutputWChar;
}

VfxBool VappCalculatorButton :: onPenInput(VfxPenEvent &event)
{
	if (event.type == VFX_PEN_EVENT_TYPE_LONG_TAP)
    {
        m_longPressed.postEmit(this, getId());
    }
	
	return VcpButton::onPenInput(event);
}
#pragma arm section code, rodata

/***************************************************************************** 
 * vapp_calculator_launch()
 *****************************************************************************/
 
extern "C" void vapp_calculator_launch(void)
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
    DCM_Load(DYNAMIC_CODE_COMPRESS_CALC, 0, 0);
#endif
    VfxAppLauncher::launch( 
        VAPP_CALCULATOR,
        VFX_OBJ_CLASS_INFO(VappCalculatorApp),
        GRP_ID_ROOT);
}

#pragma arm section code = "DYNAMIC_CODE_CALC_ROCODE", rodata = "DYNAMIC_CODE_CALC_RODATA"
/***************************************************************************** 
 * Class VappCalculatorApp
 *****************************************************************************/
 
VFX_IMPLEMENT_CLASS("VappCalculatorApp", VappCalculatorApp, VfxApp);

void VappCalculatorApp::onRun(void * args, VfxU32 argSize)
{
	VFX_TRACE(("\n[VappCalculatorApp::onRun()]\n"));

    VfxApp::onRun(args, argSize);

    // create and display main screen
    VFX_OBJ_CREATE_EX(m_mainScr, VfxMainScrEx, this, (this));
    m_mainScr->show();
}

void VappCalculatorApp::onDeinit()
{
	VFX_TRACE(("\n[VappCalculatorApp::onDeinit()]\n"));

    VfxApp::onDeinit();

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
    DCM_Unload(DYNAMIC_CODE_COMPRESS_CALC);
#endif
}

void VappCalculatorApp::onScr1stReady(VfxMainScrEx * scr)
{
	VFX_TRACE(("\n[VappCalculatorScreen::on1stReady()]\n"));

    //VfxMainScr::on1stReady();

    // create and display first page
    VFX_OBJ_CREATE(m_page, VappCalculatorPage, scr);
    scr->pushPage(0, m_page);

}

void VappCalculatorApp::onScr2ndReady(VfxMainScrEx * scr)
{
	if(m_page)
	{
		m_page->on2ndinit();
	}

}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/***************************************************************************** 
 * Class VappCalculatorPage
 *****************************************************************************/
 
//VFX_IMPLEMENT_CLASS("VappCalculatorPage", VappCalculatorPage, VfxPage);

VappCalculatorPage::VappCalculatorPage()
{
	/* initialization */
	inputLength = 0;
	openParenNum = 0;
	isFormulaStart = VFX_TRUE;
}


void VappCalculatorPage::onInit()
{
	/* call base class */
    VfxPage::onInit(); 
    this->setTranslucent(VFX_TRUE);
    m_btnHighLight = NULL;
    placeCalcComponent();	
	recoverFormula();
	setCalcButtonClickedAction();
	VFX_TRACE(("\n[VappCalculatorPage::onInit() Done!]\n"));
	setIsZSortChild(VFX_TRUE);

}


void VappCalculatorPage::on2ndinit()
{
	m_calcEditBox->activate();
	m_calculatorBg->setCacheMode(VFX_CACHE_MODE_FORCE);
	setCacheMode(VFX_CACHE_MODE_PREVENT);
	for (VfxS32 i = VCP_CALC_BUTTON_0; i < VCP_CALC_BUTTON_TOTAL; i++)
		{
			m_calcBtn[i]->setCacheMode(VFX_CACHE_MODE_FORCE);
		}


}


void VappCalculatorPage::onDeinit()
{
	VfxPage::onDeinit();
	storeFormula();
	VFX_TRACE(("\n[VappCalculatorPage::onDeinit() Done!]\n"));
}


void VappCalculatorPage::storeFormula()
{
    wcscpy((wchar_t*)CALC_BUFFER_POOL, (wchar_t*)m_calcEditBox->getText());
}
	

void VappCalculatorPage::recoverFormula()
{
	VfxU32 len = vfx_sys_wcslen(CALC_BUFFER_POOL);

	// init openParenNum
	if(len != 0)
	{
	    m_calcEditBox->insertText((VfxWChar*)CALC_BUFFER_POOL);
	    isFormulaStart = VFX_FALSE;
		for(VfxU32 index = 0; index < len; index++)
		{
		    if(CALC_BUFFER_POOL[index] == CALC_WCHAR_OPEN_PAREN)
		    {
		        openParenNum++;
		    }
			else if(CALC_BUFFER_POOL[index] == CALC_WCHAR_CLOSE_PAREN)
			{
			    openParenNum--;
			}
	    }
	}
}

void VappCalculatorPage::placeCalcComponent()
{
	/* Calculator Back Image */
	VFX_OBJ_CREATE(m_calculatorBg, VfxImageFrame, this);
	m_calculatorBg->setImgContent(VfxImageSrc(IMG_ID_VAPP_CALCULATOR_BG));
	m_calculatorBg->setPos(0, 0 + CALC_STATUS_BAR_HIGHT);
	m_calculatorBg->setAnchor(0.0f, 0.0f);
	m_calculatorBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_calculatorBg->setSize(this->getSize().width, this->getSize().height - CALC_STATUS_BAR_HIGHT);
	m_calculatorBg->setPosZ(2);

	

	/* Calculator Editor Back Image */
	VFX_OBJ_CREATE(m_editorBg, VfxImageFrame, this);
	m_editorBg->setImgContent(VfxImageSrc(IMG_ID_VAPP_CALCULATOR_LCD));
	m_editorBg->setPos(CALC_LCD_POSITION_X, CALC_LCD_POSITION_Y + CALC_STATUS_BAR_HIGHT);
	m_editorBg->setAnchor(0.0f, 0.0f);
	m_editorBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_editorBg->setSize(CALC_LCD_SIZE_X, CALC_LCD_SIZE_Y);
	m_editorBg->setPosZ(1);

	/* Calculator Editor Font */
	VfxColor m_calcColor(255, 28, 28, 28);
	VfxFontDesc m_calcFont;
	m_calcFont.size = VFX_FONT_DESC_VF_SIZE(CALC_EDITOR_FONT_SIZE);
//	m_calcFont.attr |= VFX_FONT_DESC_ATTR_MONOSPACE;   
	m_calcFont.effect |= VFX_FE1_9;

	/* Calculator Editor */
	VFX_OBJ_CREATE(m_calcEditBox, VcpTextEditor, this); 
	m_calcEditBox->setText(VFX_WSTR_EMPTY, CALC_EDITOR_BUFFER_LENGTH);
	m_calcEditBox->setPos(CALC_LCD_POSITION_X + 10, CALC_LCD_POSITION_X + 10 + CALC_STATUS_BAR_HIGHT);
	m_calcEditBox->setBounds(VfxRect(0, 0, CALC_LCD_SIZE_X - 20, CALC_LCD_SIZE_Y - 20));
	m_calcEditBox->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
	m_calcEditBox->setAlignMode(VCP_TEXT_ALIGN_MODE_RIGHT);
	m_calcEditBox->setVerticalAlignMode(VCP_TEXT_VERT_ALIGN_MODE_BOTTOM);
	m_calcEditBox->setIME(IME_SETTING_FLAG_NONE);
	//m_calcEditBox->activate();
    m_calcEditBox->setDisableClipboard(VFX_TRUE);
	m_calcEditBox->disableBackground(VFX_TRUE);
	m_calcEditBox->hideCounter(VFX_TRUE);
	m_calcEditBox->setAutoFontSize(VFX_TRUE);
	m_calcEditBox->setHint(VFX_WSTR(""));
	m_calcEditBox->setFont(m_calcFont);
	m_calcEditBox->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, m_calcColor);
    m_calcEditBox->setTextWrapStyle(VCP_TEXT_WRAP_OPERATOR_WRAP);


    /* set the font attr of number button */
    VfxFontDesc m_numBtnFont;
	m_numBtnFont.size = VFX_FONT_DESC_VF_SIZE(CALC_BUTTON_FONT_SIZE);
	m_numBtnFont.effect |= VFX_FE1_2;
	VfxColor m_numBtnFontColor(255, 50, 50, 50);

	/* Calculator Number Buttons */
	for (VfxS32 i = VCP_CALC_BUTTON_0; i < VCP_CALC_NUM_BUTTON_TOTAL; i++)
	{
	    //VFX_OBJ_CREATE(m_calcBtn[i], VappCalculatorButton, this);
	    VFX_OBJ_CREATE(m_calcBtn[i], VappCalculatorButton, this);
		m_calcBtn[i]->getButtonTextFrame()->setFullLineHeightMode(VFX_FALSE);
		m_calcBtn[i]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
	    m_calcBtn[i]->setTextFont(m_numBtnFont);
	    m_calcBtn[i]->setTextColor(m_numBtnFontColor);
		m_calcBtn[i]->setBgImageList(IMG_ID_VAPP_CALCULATOR_BUTTON_NUM_BG);
		m_calcBtn[i]->setId(i);
		m_calcBtn[i]->setIsHapticTouchEnabled(VFX_TRUE);
                m_calcBtn[i]->setMargin(0,0,0,0);
		if (i == VCP_CALC_BUTTON_0 || i == VCP_CALC_BUTTON_POINT)
			{
				continue; 
			}
		m_calcBtn[i]->setRect(VfxRect(CALC_SIDE_BORDER +  (i-1)%3*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP),
			                                      CALC_BUTTON_ORIGIN_Y + (1+(9-i)/3)*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
			                                      CALC_BUTTON_WIDTH, 
			                                      CALC_BUTTON_HIGHT));
	}	
	m_calcBtn[VCP_CALC_BUTTON_0]->setRect(VfxRect(CALC_SIDE_BORDER + 0*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP),
			                                      CALC_BUTTON_ORIGIN_Y + 4*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
			                                      CALC_WIDE_BUTTON_WIDTH, 
			                                      CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_0]->setText(VFX_WSTR("0"));
	
	m_calcBtn[VCP_CALC_BUTTON_0]->setOutputWChar(CALC_WCHAR_ZERO);
	//m_calcBtn[VCP_CALC_BUTTON_1]->setRect(VfxRect(CALC_SIDE_BORDER + 0*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                      CALC_BUTTON_ORIGIN_Y + 3*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                      CALC_BUTTON_WIDTH, 
	//		                                      CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_1]->setText(VFX_WSTR("1"));
	m_calcBtn[VCP_CALC_BUTTON_1]->setOutputWChar(CALC_WCHAR_ONE);
	//m_calcBtn[VCP_CALC_BUTTON_2]->setRect(VfxRect(CALC_SIDE_BORDER + 1*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                      CALC_BUTTON_ORIGIN_Y + 3*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                      CALC_BUTTON_WIDTH, 
	//		                                      CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_2]->setText(VFX_WSTR("2"));
	m_calcBtn[VCP_CALC_BUTTON_2]->setOutputWChar(CALC_WCHAR_TWO);
	//m_calcBtn[VCP_CALC_BUTTON_3]->setRect(VfxRect(CALC_SIDE_BORDER + 2*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                      CALC_BUTTON_ORIGIN_Y + 3*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                      CALC_BUTTON_WIDTH, 
	//		                                      CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_3]->setText(VFX_WSTR("3"));
	m_calcBtn[VCP_CALC_BUTTON_3]->setOutputWChar(CALC_WCHAR_THREE);
	//m_calcBtn[VCP_CALC_BUTTON_4]->setRect(VfxRect(CALC_SIDE_BORDER + 0*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                      CALC_BUTTON_ORIGIN_Y + 2*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                      CALC_BUTTON_WIDTH, 
	//		                                      CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_4]->setText(VFX_WSTR("4"));
	m_calcBtn[VCP_CALC_BUTTON_4]->setOutputWChar(CALC_WCHAR_FOUR);
	//m_calcBtn[VCP_CALC_BUTTON_5]->setRect(VfxRect(CALC_SIDE_BORDER + 1*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                      CALC_BUTTON_ORIGIN_Y + 2*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                      CALC_BUTTON_WIDTH, 
	//		                                      CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_5]->setText(VFX_WSTR("5"));
	m_calcBtn[VCP_CALC_BUTTON_5]->setOutputWChar(CALC_WCHAR_FIVE);
	//m_calcBtn[VCP_CALC_BUTTON_6]->setRect(VfxRect(CALC_SIDE_BORDER + 2*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                      CALC_BUTTON_ORIGIN_Y + 2*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                      CALC_BUTTON_WIDTH, 
	//		                                      CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_6]->setText(VFX_WSTR("6"));
	m_calcBtn[VCP_CALC_BUTTON_6]->setOutputWChar(CALC_WCHAR_SIX);
	//m_calcBtn[VCP_CALC_BUTTON_7]->setRect(VfxRect(CALC_SIDE_BORDER + 0*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                      CALC_BUTTON_ORIGIN_Y + 1*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                      CALC_BUTTON_WIDTH, 
	//		                                      CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_7]->setText(VFX_WSTR("7"));
	m_calcBtn[VCP_CALC_BUTTON_7]->setOutputWChar(CALC_WCHAR_SEVEN);
	//m_calcBtn[VCP_CALC_BUTTON_8]->setRect(VfxRect(CALC_SIDE_BORDER + 1*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                      CALC_BUTTON_ORIGIN_Y + 1*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                      CALC_BUTTON_WIDTH, 
	//		                                      CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_8]->setText(VFX_WSTR("8"));
	m_calcBtn[VCP_CALC_BUTTON_8]->setOutputWChar(CALC_WCHAR_EIGHT);
	//m_calcBtn[VCP_CALC_BUTTON_9]->setRect(VfxRect(CALC_SIDE_BORDER + 2*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                      CALC_BUTTON_ORIGIN_Y + 1*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                      CALC_BUTTON_WIDTH, 
	//		                                      CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_9]->setText(VFX_WSTR("9"));
	m_calcBtn[VCP_CALC_BUTTON_9]->setOutputWChar(CALC_WCHAR_NINE);
	m_calcBtn[VCP_CALC_BUTTON_POINT]->setRect(VfxRect(CALC_SIDE_BORDER + 2*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
			                                          CALC_BUTTON_ORIGIN_Y + 4*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
			                                          CALC_BUTTON_WIDTH, 
			                                          CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_POINT]->setText(VFX_WSTR("."));
	m_calcBtn[VCP_CALC_BUTTON_POINT]->setOutputWChar(CALC_WCHAR_POINT);
	m_calcBtn[VCP_CALC_BUTTON_POINT]->getButtonTextFrame()->setFullLineHeightMode(VFX_TRUE);


	/* Calculator System Buttons */
	for (VfxS32 i = VCP_CALC_BUTTON_AC; i < VCP_CALC_BUTTON_TOTAL; i++)
	{
	    VFX_OBJ_CREATE(m_calcBtn[i], VappCalculatorButton, this);
		m_calcBtn[i]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
		m_calcBtn[i]->setBgImageList(IMG_ID_VAPP_CALCULATOR_BUTTON_PUNC_BG);
		m_calcBtn[i]->setId(i);
		m_calcBtn[i]->setIsHapticTouchEnabled(VFX_TRUE);
                m_calcBtn[i]->setMargin(0,0,0,0);
		if (i == VCP_CALC_BUTTON_EQUAL)
		{
			continue;
	}	
		m_calcBtn[i]->setRect(VfxRect(CALC_SIDE_BORDER + (((((i-10)/4)>>((i-10)/8))^0x01)*((i-10)%4-1)+((((i-10)/4)>>((i-10)/8))^0x00)*((i-10)/4+2))*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
							  CALC_BUTTON_ORIGIN_Y + CALC_STATUS_BAR_HIGHT + (((((i-10)/4)>>((i-10)/8))^0x00)*((i-10)%4))*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP), 
		                                           CALC_BUTTON_WIDTH, 
		                                           CALC_BUTTON_HIGHT));

	}	
	
//	m_calcBtn[VCP_CALC_BUTTON_AC]->setRect(VfxRect(CALC_SIDE_BORDER, 
//		                                           CALC_BUTTON_ORIGIN_Y + CALC_STATUS_BAR_HIGHT, 
//		                                           CALC_BUTTON_WIDTH, 
//		                                           CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_AC]->setImage(IMG_ID_VAPP_CALCULATOR_BUTTON_AC);
	m_calcBtn[VCP_CALC_BUTTON_AC]->setBgImageList(IMG_ID_VAPP_CALCULATOR_BUTTON_AC_BG);
//	m_calcBtn[VCP_CALC_BUTTON_BACKSAPCE]->setRect(VfxRect(CALC_SIDE_BORDER + 4*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
//			                                              CALC_BUTTON_ORIGIN_Y + CALC_STATUS_BAR_HIGHT, 
//			                                              CALC_BUTTON_WIDTH, 
//			                                              CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_BACKSAPCE]->setImage(IMG_ID_VAPP_CALCULATOR_BUTTON_BACKSPACE);
	m_calcBtn[VCP_CALC_BUTTON_EQUAL]->setRect(VfxRect(CALC_SIDE_BORDER + 3*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
			                                          CALC_BUTTON_ORIGIN_Y + 4*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
			                                          CALC_WIDE_BUTTON_WIDTH, 
			                                          CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_EQUAL]->setImage(IMG_ID_VAPP_CALCULATOR_BUTTON_EQUAL);
	m_calcBtn[VCP_CALC_BUTTON_EQUAL]->setBgImageList(IMG_ID_VAPP_CALCULATOR_BUTTON_EQUAL_BG);
	//m_calcBtn[VCP_CALC_BUTTON_POWER_TWO]->setRect(VfxRect(CALC_SIDE_BORDER + 2*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                              CALC_BUTTON_ORIGIN_Y + CALC_STATUS_BAR_HIGHT, 
	//		                                              CALC_BUTTON_WIDTH, 
	//		                                              CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_POWER_TWO]->setImage(IMG_ID_VAPP_CALCULATOR_BUTTON_SQUARE);
	//m_calcBtn[VCP_CALC_BUTTON_RECIPROCAL]->setRect(VfxRect(CALC_SIDE_BORDER + 3*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                               CALC_BUTTON_ORIGIN_Y + CALC_STATUS_BAR_HIGHT, 
	//		                                               CALC_BUTTON_WIDTH, 
	//		                                               CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_RECIPROCAL]->setImage(IMG_ID_VAPP_CALCULATOR_BUTTON_RECIPROCAL);	
	//m_calcBtn[VCP_CALC_BUTTON_SQUARE_ROOT]->setRect(VfxRect(CALC_SIDE_BORDER + 1*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                                CALC_BUTTON_ORIGIN_Y + CALC_STATUS_BAR_HIGHT, 
	//		                                                CALC_BUTTON_WIDTH, 
	//		                                                CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_SQUARE_ROOT]->setOutputWChar(CALC_WCHAR_SQUARE_ROOT);
	m_calcBtn[VCP_CALC_BUTTON_SQUARE_ROOT]->setImage(IMG_ID_VAPP_CALCULATOR_BUTTON_SQUARE_ROOT);

	//m_calcBtn[VCP_CALC_BUTTON_OPEN_PAREN]->setRect(VfxRect(CALC_SIDE_BORDER + 3*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                               CALC_BUTTON_ORIGIN_Y + 1*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                               CALC_BUTTON_WIDTH, 
	//		                                               CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_OPEN_PAREN]->setOutputWChar(CALC_WCHAR_OPEN_PAREN);
	m_calcBtn[VCP_CALC_BUTTON_OPEN_PAREN]->setImage(IMG_ID_VAPP_CALCULATOR_BUTTON_OPEN_PAREN);
	//m_calcBtn[VCP_CALC_BUTTON_CLOSE_PAREN]->setRect(VfxRect(CALC_SIDE_BORDER + 4*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                                CALC_BUTTON_ORIGIN_Y + 1*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                                CALC_BUTTON_WIDTH, 
	//		                                                CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_CLOSE_PAREN]->setOutputWChar(CALC_WCHAR_CLOSE_PAREN);
	m_calcBtn[VCP_CALC_BUTTON_CLOSE_PAREN]->setImage(IMG_ID_VAPP_CALCULATOR_BUTTON_CLOSE_PAREN);
	//m_calcBtn[VCP_CALC_BUTTON_PLUS]->setRect(VfxRect(CALC_SIDE_BORDER + 3*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                         CALC_BUTTON_ORIGIN_Y + 2*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                         CALC_BUTTON_WIDTH, 
	//		                                         CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_PLUS]->setOutputWChar(CALC_WCHAR_PLUS);
	m_calcBtn[VCP_CALC_BUTTON_PLUS]->setImage(IMG_ID_VAPP_CALCULATOR_BUTTON_PLUS);
	//m_calcBtn[VCP_CALC_BUTTON_MINUS]->setRect(VfxRect(CALC_SIDE_BORDER + 4*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                          CALC_BUTTON_ORIGIN_Y + 2*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                          CALC_BUTTON_WIDTH, 
	//		                                          CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_MINUS]->setOutputWChar(CALC_WCHAR_MINUS);
	m_calcBtn[VCP_CALC_BUTTON_MINUS]->setImage(IMG_ID_VAPP_CALCULATOR_BUTTON_MINUS);
	//m_calcBtn[VCP_CALC_BUTTON_MULT]->setRect(VfxRect(CALC_SIDE_BORDER + 3*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                         CALC_BUTTON_ORIGIN_Y + 3*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                         CALC_BUTTON_WIDTH, 
	//		                                         CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_MULT]->setOutputWChar(CALC_WCHAR_MULT);
	m_calcBtn[VCP_CALC_BUTTON_MULT]->setImage(IMG_ID_VAPP_CALCULATOR_BUTTON_MULT);
	//m_calcBtn[VCP_CALC_BUTTON_DIV]->setRect(VfxRect(CALC_SIDE_BORDER + 4*(CALC_BUTTON_WIDTH+CALC_BUTTON_HORIZONTAL_GAP), 
	//		                                        CALC_BUTTON_ORIGIN_Y + 3*(CALC_BUTTON_HIGHT+CALC_BUTTON_VERTICAL_GAP) + CALC_STATUS_BAR_HIGHT, 
	//		                                        CALC_BUTTON_WIDTH, 
	//		                                        CALC_BUTTON_HIGHT));
	m_calcBtn[VCP_CALC_BUTTON_DIV]->setOutputWChar(CALC_WCHAR_DIV);
	m_calcBtn[VCP_CALC_BUTTON_DIV]->setImage(IMG_ID_VAPP_CALCULATOR_BUTTON_DIV);

}


VfxBool VappCalculatorPage::isInsertState()
{
	if(m_calcEditBox->getCharAfterCursor(0) == NULL)
	{
		return VFX_FALSE;
	}
	else
	{
		return VFX_TRUE;
	}
}


VfxBool VappCalculatorPage::isCharBeforeCursorSign()
{
	if(m_calcEditBox->getCharBeforeCursor() == CALC_WCHAR_PLUS || m_calcEditBox->getCharBeforeCursor() == CALC_WCHAR_MINUS)
	{
		if(m_calcEditBox->getCharBeforeCursor(2) == CALC_WCHAR_OPEN_PAREN || m_calcEditBox->getLength() == 1)
		{
			return VFX_TRUE;
		}
		else 
		{
			return VFX_FALSE;
		}
	}
	else 
	{
		return VFX_FALSE;
	}
}


VfxBool VappCalculatorPage::isCharBeforeCursorPlusMinus()
{
	if(m_calcEditBox->getCharBeforeCursor() == CALC_WCHAR_PLUS || m_calcEditBox->getCharBeforeCursor() == CALC_WCHAR_MINUS)
	{
		if((m_calcEditBox->getCharBeforeCursor(2) == CALC_WCHAR_OPEN_PAREN) || (m_calcEditBox->getLength() == 1))
		{
			return VFX_FALSE;
		}
		else 
		{
			return VFX_TRUE;
		}
	}
	else
	{
		return VFX_FALSE;
	}
}

/*
 * change double to UCS2String
 * point : point to the "."
 * intLen : length of integer part
 */
void VappCalculatorPage::double2WString(VfxWChar *WString, VfxDoube result)
{
	if(result >= CALC_MAX_VALUE || result <= CALC_MIN_VALUE)
	{
		onErrorPopup(CALC_RESULT_EXCEED_BORDER);
		return;
	}
	VfxBool sign = VFX_FALSE;
	VfxChar resultStr[2 * MAX_OPERAND_LEN + 2]= {0};  /* sign + 12 + . + 11 + \0 */
	sprintf(resultStr, "%.11f",result);
//	printf("%s\n",resultStr);
	VfxS32 len = strlen(resultStr);
	VfxChar *point = strstr(resultStr,".");
	VfxS32 intLen = strcspn(resultStr,".");
	
	if(resultStr[0] == '-')    /* negative number */
	{
		sign = VFX_TRUE;
		intLen--;
	}
	if(intLen == MAX_OPERAND_LEN)
	{
		if(point[1] < '5')
		{
			point[0] = '\0';
		}
		if(point[1] >= '5')
		{
			point[0] = '\0';
			int i = -1;
			while(point[i] == '9')
			{
				point[i] = '0';
				i--;
			}
			point[i]++;
		}
	}
	else if(intLen < MAX_OPERAND_LEN)
	{
		if(point[MAX_OPERAND_LEN - intLen] < '5')
		{
			int i = 1;
			while(point[MAX_OPERAND_LEN - intLen -i]== '0')
			{
				i++;
			}
			if(point[MAX_OPERAND_LEN - intLen -i]== '.')
			{
				point[MAX_OPERAND_LEN - intLen - i] = '\0';
			}
			else
			{
				point[MAX_OPERAND_LEN - intLen - i + 1] = '\0';
			}
		}
		else if(point[MAX_OPERAND_LEN - intLen] >= '5')
		{
			int i = 1;
			while((point[MAX_OPERAND_LEN - intLen - i] == '9')&& (MAX_OPERAND_LEN - intLen - i > 0))
			{
				i++;
			}
			if(i < MAX_OPERAND_LEN - intLen)
			{
				point[MAX_OPERAND_LEN - intLen - i]++;
				point[MAX_OPERAND_LEN - intLen - i + 1] = '\0';
			}
			else
			{
				point[0] = '\0';
				int i = -1;
				while(point[i] == '9' && (-i) <= intLen)
				{
					point[i] = '0';
					i--;
				}
				if(-i <= intLen)
				{
					point[i]++;
				}
				/* 
					 99.99999999999 -> 100;
				   -999.99999999999 -> -1000
				*/
				else
				{
					if(sign == VFX_TRUE)
					{
						resultStr[0] = '-';
						resultStr[1] = '1';
						for(i=0; i<intLen; i++)
						{
							resultStr[i+2] = '0';
						}
						resultStr[intLen+2] = '\0';
					}
					else
					{
						resultStr[0] = '1';
						for(i=0; i<intLen; i++)
						{
							resultStr[i+1] = '0';
						}
						resultStr[intLen+1] = '\0';
					}	
				}
			}
		}
	}
	if((resultStr[0] == '-') && (resultStr[1] == '0') && (resultStr[2] == '\0'))
	{
	    resultStr[0] = '0';
		resultStr[1] = '\0';
	}
	mmi_asc_to_ucs2((char*)WString, resultStr);
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


VfxBool VappCalculatorPage::onKeyInput(VfxKeyEvent &event)
{
	if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
	{
		switch(event.keyCode)
		{
			case VFX_KEY_CODE_0:
			case VFX_KEY_CODE_1:
			case VFX_KEY_CODE_2:
			case VFX_KEY_CODE_3:
			case VFX_KEY_CODE_4:
			case VFX_KEY_CODE_5:
			case VFX_KEY_CODE_6:
			case VFX_KEY_CODE_7:
			case VFX_KEY_CODE_8:
			case VFX_KEY_CODE_9:
				onBtnClick(NULL, event.keyCode);
				break;
	        case VFX_KEY_CODE_POUND:
		    case VFX_KEY_CODE_L:
				onBtnClick(NULL, VCP_CALC_BUTTON_POINT);
				break;
	        case VFX_KEY_CODE_CSK:
			case VFX_KEY_CODE_QWERTY_ENTER:
			case VFX_KEY_CODE_A:
				onBtnClick(NULL, VCP_CALC_BUTTON_EQUAL);
				break;
			case VFX_KEY_CODE_CLEAR:
			case VFX_KEY_CODE_BACKSPACE:
				onBtnClick(NULL, VCP_CALC_BUTTON_BACKSAPCE);
				break;
			case VFX_KEY_CODE_ARROW_UP:
			case VFX_KEY_CODE_ARROW_DOWN:
			case VFX_KEY_CODE_ARROW_LEFT:
			case VFX_KEY_CODE_ARROW_RIGHT:
				m_calcEditBox->activate();
				break;
			case VFX_KEY_CODE_Y:
				onBtnClick(NULL, VCP_CALC_BUTTON_OPEN_PAREN);
				break;
			case VFX_KEY_CODE_U:
				onBtnClick(NULL, VCP_CALC_BUTTON_CLOSE_PAREN);
				break;
			case VFX_KEY_CODE_W:
				onBtnClick(NULL, VCP_CALC_BUTTON_PLUS);
				break;
			case VFX_KEY_CODE_S:
				onBtnClick(NULL, VCP_CALC_BUTTON_MINUS);
				break;
		#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
			case VFX_KEY_CODE_STAR:
				onBtnClick(NULL, VCP_CALC_BUTTON_MULT);
				break;
        #endif
			case VFX_KEY_CODE_Q:
				onBtnClick(NULL, VCP_CALC_BUTTON_DIV);
				break;
			case VFX_KEY_CODE_BACK:
		        back();
				break;
	    }
    }
	
	if (event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS)
	{
		if (event.keyCode == VFX_KEY_CODE_CLEAR || event.keyCode == VFX_KEY_CODE_BACKSPACE)
		{
		    onBtnClick(NULL, VCP_CALC_BUTTON_AC);
	    }
    }	
	return VfxPage::onKeyInput(event);
}


void VappCalculatorPage::setCalcButtonClickedAction()
{
	for (VfxS32 i = VCP_CALC_BUTTON_0; i < VCP_CALC_BUTTON_TOTAL; i++)
	{
		m_calcBtn[i]->m_signalClicked.connect(this, &VappCalculatorPage::onBtnClick);
		m_calcBtn[i]->m_signalStateChanged.connect(this,&VappCalculatorPage::onBtnStateChanged);
	}
	
	m_calcBtn[VCP_CALC_BUTTON_BACKSAPCE]->m_longPressed.connect(this,&VappCalculatorPage::onDelBtnLongPress);
}


VfxBool VappCalculatorPage::checkOperandBeforeCursor()
{
	VfxS32 len = 1;
	VfxBool hasPoint = VFX_FALSE;

	while(len <= m_calcEditBox->getLength() && 
		m_calcEditBox->getCharBeforeCursor(len) >= CALC_WCHAR_ZERO
		&& m_calcEditBox->getCharBeforeCursor(len) <= CALC_WCHAR_NINE
	    || m_calcEditBox->getCharBeforeCursor(len) == CALC_WCHAR_POINT)
	{
		if(m_calcEditBox->getCharBeforeCursor(len) == CALC_WCHAR_POINT)
		{
			if(hasPoint == VFX_FALSE)
			{
				hasPoint = VFX_TRUE;
			}
			else
			{
				return VFX_FALSE;
			}
		}
		len++;
	}
	currOperandLen = len - 1;
	isHasPoint = hasPoint;
	if(currOperandLen > MAX_OPERAND_LEN)
	{
		return VFX_FALSE;
	}
	return VFX_TRUE;
}

void VappCalculatorPage::onErrorPopup(CALC_ERROR_TYPE_ENUM errorCode)
{	
	
	
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_DEFAULT,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_FAILURE,
			VFX_WSTR_RES(STR_ID_VAPP_CALCULATOR_TITLE - errorCode)); 
	
	

	/*switch(errorCode)
	{
		case CALC_FORMULA_TOO_LONG:
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_DEFAULT,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				VFX_WSTR_RES(STR_ID_VAPP_CALCULATOR_ERROR_EXPRESSION_TOO_LONG)); 
			break;
		case CALC_DIVISOR_CAN_NOT_BE_ZERO:
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_DEFAULT,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				VFX_WSTR_RES(STR_ID_VAPP_CALCULATOR_ERROR_UNABLE_TO_DIVIDE_BY_ZERO)); 
			break;
		case CALC_NEGATIVE_CAN_NOT_BE_SQUARE_ROOT:
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_DEFAULT,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				VFX_WSTR_RES(STR_ID_VAPP_CALCULATOR_ERROR_UNABLE_TO_EXTRACT_A_ROOT_OF_NEGATIVE)); 
			break;
		case CALC_OPERAND_TOO_LONG:
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_DEFAULT,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				VFX_WSTR_RES(STR_ID_VAPP_CALCULATOR_ERROR_MAXIMUM_NUMBER_OF_CHARACTERS_EXCEEDED)); 
			break;
		case CALC_RESULT_EXCEED_BORDER:
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_DEFAULT,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				VFX_WSTR_RES(STR_ID_VAPP_CALCULATOR_ERROR_RESULT_TOO_LARGE_TO_DISPLAY)); 
			break;
		case CALC_BRACKETS_DO_NOT_MATCH:
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_DEFAULT,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				VFX_WSTR_RES(STR_ID_VAPP_CALCULATOR_ERROR_BRACKETS_DO_NOT_MATCH)); 
			break;
		case CALC_INVALID_OPERAND:
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_DEFAULT,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				VFX_WSTR_RES(STR_ID_VAPP_CALCULATOR_ERROR_INVALID_OPERAND)); 
			break;
		default:		
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_DEFAULT,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				VFX_WSTR_RES(STR_ID_VAPP_CALCULATOR_ERROR_INVALID_EXPRESSION)); 
			break;	
	}*/
}


void VappCalculatorPage::onDelBtnLongPress(VfxObject *obj, VfxId id)
{
	isFormulaStart = VFX_TRUE;
	openParenNum = 0;
	m_calcEditBox->deleteAll();
	vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
}


void VappCalculatorPage::onBtnClick(VfxObject *obj, VfxId id)
{   
	if(id != VCP_CALC_BUTTON_EQUAL)
	{
	    m_calcEditBox->activate();
	}
	if(id != VCP_CALC_BUTTON_AC && id != VCP_CALC_BUTTON_BACKSAPCE 
		&& id != VCP_CALC_BUTTON_EQUAL)
	{
		inputLength = m_calcEditBox->getLength();
		
		/*  button "1/X" need input 4 characters: "(1/)" */
		if(id == VCP_CALC_BUTTON_RECIPROCAL)
		{
		    if(inputLength >= CALC_EDITOR_BUFFER_LENGTH - 3)
		    {
		    	onErrorPopup(CALC_FORMULA_TOO_LONG);
			    return;
		    }
		}
		if(inputLength >= CALC_EDITOR_BUFFER_LENGTH)
		{
			onErrorPopup(CALC_FORMULA_TOO_LONG);
			return;
		}	
	}
	VFX_TRACE(("\n[VappCalculatorPage::onBtnClick() ButtonId: %d InsertText: %s ]\n",id, m_calcEditBox->getText()));
	m_charBeforeCursor = m_calcEditBox->getCharBeforeCursor(1);
	switch (id)
	{
		case VCP_CALC_BUTTON_AC:
			m_calcEditBox->deleteAll();
			isFormulaStart = VFX_TRUE;
			openParenNum = 0;
			break;
			
		case VCP_CALC_BUTTON_BACKSAPCE:
			if(m_calcEditBox->getLength() == 0)
			{
			    break;
			}
			
				isFormulaStart = VFX_FALSE;


			if(m_charBeforeCursor == CALC_WCHAR_OPEN_PAREN)
			{	
				openParenNum--;
			}
			else if(m_charBeforeCursor == CALC_WCHAR_CLOSE_PAREN)
			{
				openParenNum++;
			}	
				m_calcEditBox->deleteChars();
			break;
				
		case VCP_CALC_BUTTON_0:
		case VCP_CALC_BUTTON_1:
		case VCP_CALC_BUTTON_2:
		case VCP_CALC_BUTTON_3:
		case VCP_CALC_BUTTON_4:
		case VCP_CALC_BUTTON_5:
		case VCP_CALC_BUTTON_6:
		case VCP_CALC_BUTTON_7:
		case VCP_CALC_BUTTON_8:
		case VCP_CALC_BUTTON_9:
			if(isInsertState() == VFX_TRUE)    /*insert state*/
			{
					isFormulaStart = VFX_FALSE;
				m_calcEditBox->insertText(m_calcBtn[id]->getOutputWChar());
				break;
			}
			if(isFormulaStart == VFX_TRUE)   /* begin a new formula */
			{
				isFormulaStart = VFX_FALSE;
				m_calcEditBox->deleteAll();
				m_calcEditBox->insertText(m_calcBtn[id]->getOutputWChar());
				break;
			}	
			/* append mode */
			if(m_charBeforeCursor == CALC_WCHAR_POWER || m_charBeforeCursor == CALC_WCHAR_CLOSE_PAREN)  // "^2" ")"
			{
			    if(inputLength >= CALC_EDITOR_BUFFER_LENGTH - 1)
			    {
			    	onErrorPopup(CALC_FORMULA_TOO_LONG);
				    return;
			    }
				m_calcEditBox->insertText(CALC_WCHAR_MULT);
				m_calcEditBox->insertText(m_calcBtn[id]->getOutputWChar());
				break;
			}
			else if((m_charBeforeCursor >= CALC_WCHAR_ZERO && m_charBeforeCursor <= CALC_WCHAR_NINE)  //"0-9"
				|| m_charBeforeCursor == CALC_WCHAR_POINT)          // ".", 
			{
				bool ret = checkOperandBeforeCursor();
				if(ret == VFX_FALSE)
				{
					onErrorPopup(CALC_OPERAND_TOO_LONG);
				}
				if(m_charBeforeCursor == CALC_WCHAR_ZERO && currOperandLen == 1)  // "0"
				{
					m_calcEditBox->deleteChars();
					m_calcEditBox->insertText(m_calcBtn[id]->getOutputWChar());
				}
				else if(currOperandLen < MAX_OPERAND_LEN)
				{
					m_calcEditBox->insertText(m_calcBtn[id]->getOutputWChar());
				}
				else
				{
					onErrorPopup(CALC_OPERAND_TOO_LONG);
				}
				break;
			}
			else
			{
				m_calcEditBox->insertText(m_calcBtn[id]->getOutputWChar());
			}
			break;
			
		case VCP_CALC_BUTTON_POINT:	
			if(isInsertState() == VFX_TRUE)  /*insert state*/
			{
					isFormulaStart = VFX_FALSE;
				m_calcEditBox->insertText(CALC_WCHAR_POINT);
				break;
			}
			if(isFormulaStart == VFX_TRUE)  /* begin a new formula */
			{
				m_calcEditBox->deleteAll();
				isFormulaStart = VFX_FALSE;
				m_calcEditBox->insertText(CALC_WCHAR_ZERO);
				m_calcEditBox->insertText(CALC_WCHAR_POINT);
				break;
			}
			/* append mode */
			if((m_charBeforeCursor == CALC_WCHAR_POWER ) 
				|| m_charBeforeCursor == CALC_WCHAR_CLOSE_PAREN)  // ")"
			{
				if(inputLength >= CALC_EDITOR_BUFFER_LENGTH - 2)
			    {
			    	onErrorPopup(CALC_FORMULA_TOO_LONG);
				    return;
			    }
				m_calcEditBox->insertText(CALC_WCHAR_MULT);
				m_calcEditBox->insertText(CALC_WCHAR_ZERO);
				m_calcEditBox->insertText(m_calcBtn[id]->getOutputWChar());
			}
			else if(m_charBeforeCursor >= CALC_WCHAR_ZERO && m_charBeforeCursor <= CALC_WCHAR_NINE) //"0-9"
			{
				bool ret = checkOperandBeforeCursor();				
				if(isHasPoint == VFX_TRUE)      // already has a "." 
		    	{
		    		onErrorPopup(CALC_INVALID_OPERAND);
		    	}
				else if(currOperandLen >= MAX_OPERAND_LEN)
				{
		    		onErrorPopup(CALC_OPERAND_TOO_LONG);
				}			    
				
				if(isHasPoint == VFX_FALSE && currOperandLen < MAX_OPERAND_LEN)
				{
					m_calcEditBox->insertText(CALC_WCHAR_POINT);
				}
			}
			else if(m_charBeforeCursor == CALC_WCHAR_POINT)    // "."
			{
				onErrorPopup(CALC_INVALID_OPERAND);
			}
			else
			{
				m_calcEditBox->insertText(CALC_WCHAR_ZERO);
				m_calcEditBox->insertText(CALC_WCHAR_POINT);
			}
			break;
			
		case VCP_CALC_BUTTON_PLUS:
		case VCP_CALC_BUTTON_MINUS:
			if(isInsertState() == VFX_TRUE)  /*insert state*/
			{
					isFormulaStart = VFX_FALSE;
				m_calcEditBox->insertText(m_calcBtn[id]->getOutputWChar());
				break;
			}
				isFormulaStart = VFX_FALSE;		

			if(isCharBeforeCursorPlusMinus() || m_charBeforeCursor == CALC_WCHAR_MULT  //+ - x /
				|| m_charBeforeCursor == CALC_WCHAR_DIV || isCharBeforeCursorSign())
			{
				m_calcEditBox->deleteChars();
				m_calcEditBox->insertText(m_calcBtn[id]->getOutputWChar());
			}
			else if(m_charBeforeCursor != CALC_WCHAR_SQUARE_ROOT) // sign, square_root
			{
				m_calcEditBox->insertText(m_calcBtn[id]->getOutputWChar());
			}
			break;
			
		case VCP_CALC_BUTTON_MULT:
		case VCP_CALC_BUTTON_DIV:
			if(isInsertState() == VFX_TRUE)  /*insert state*/
			{
					isFormulaStart = VFX_FALSE;
				m_calcEditBox->insertText(m_calcBtn[id]->getOutputWChar());
				break;
			}
				isFormulaStart = VFX_FALSE;
			/* append mode */
			if(m_calcEditBox->getLength() != 0 && !isCharBeforeCursorSign() && 
				m_charBeforeCursor != CALC_WCHAR_OPEN_PAREN && m_charBeforeCursor != CALC_WCHAR_SQUARE_ROOT)
			{
				if(isCharBeforeCursorPlusMinus() || m_charBeforeCursor == CALC_WCHAR_MULT   
				 || m_charBeforeCursor == CALC_WCHAR_DIV)      // + - x /

			{
				m_calcEditBox->deleteChars();
			}
				m_calcEditBox->insertText(m_calcBtn[id]->getOutputWChar());

			}
			break;
			
		case VCP_CALC_BUTTON_OPEN_PAREN:
			if(isInsertState() == VFX_TRUE)  /*insert state*/
			{
					isFormulaStart = VFX_FALSE;
				m_calcEditBox->insertText(CALC_WCHAR_OPEN_PAREN);
				openParenNum++;
				break;
			}
			/* append mode */

				isFormulaStart = VFX_FALSE;
			if((m_charBeforeCursor == CALC_WCHAR_POWER)  
				|| m_charBeforeCursor == CALC_WCHAR_CLOSE_PAREN
				||(m_charBeforeCursor >= CALC_WCHAR_ZERO && m_charBeforeCursor <= CALC_WCHAR_NINE)
				|| m_charBeforeCursor == CALC_WCHAR_POINT)
			{
				if(inputLength >= CALC_EDITOR_BUFFER_LENGTH - 1)
			    {
			    	onErrorPopup(CALC_FORMULA_TOO_LONG);
				    return;
			    }
				m_calcEditBox->insertText(CALC_WCHAR_MULT);
			}
		
			openParenNum++;
			m_calcEditBox->insertText(CALC_WCHAR_OPEN_PAREN);
			break;
			
		case VCP_CALC_BUTTON_CLOSE_PAREN:
			if(isInsertState() == VFX_TRUE)  /*insert state*/
			{
					isFormulaStart = VFX_FALSE;
				m_calcEditBox->insertText(CALC_WCHAR_CLOSE_PAREN);
				openParenNum--;
				break;
			}
			/*append mode*/
			if(	openParenNum <= 0 || m_calcEditBox->getLength() == 0)
			{
			    onErrorPopup(CALC_BRACKETS_DO_NOT_MATCH);
				break;
			}

			if(m_charBeforeCursor != CALC_WCHAR_OPEN_PAREN && !isCharBeforeCursorSign()
						&& m_charBeforeCursor != CALC_WCHAR_SQUARE_ROOT)
			{
			
				if(isCharBeforeCursorPlusMinus() || m_charBeforeCursor == CALC_WCHAR_MULT   
				 || m_charBeforeCursor == CALC_WCHAR_DIV)
			{
				m_calcEditBox->deleteChars();
			}
				m_calcEditBox->insertText(CALC_WCHAR_CLOSE_PAREN);
				openParenNum--;
			}
			break;
			
		case VCP_CALC_BUTTON_SQUARE_ROOT:
			if(isInsertState() == VFX_TRUE)  /*insert state*/
			{
					isFormulaStart = VFX_FALSE;
				m_calcEditBox->insertText(CALC_WCHAR_SQUARE_ROOT);
				break;
			}
				isFormulaStart = VFX_FALSE;
			if(m_charBeforeCursor != CALC_WCHAR_SQUARE_ROOT)
			{
				if((m_charBeforeCursor == CALC_WCHAR_POWER) 
					|| m_charBeforeCursor == CALC_WCHAR_CLOSE_PAREN
					||(m_charBeforeCursor >= CALC_WCHAR_ZERO && m_charBeforeCursor <= CALC_WCHAR_NINE)
				|| m_charBeforeCursor == CALC_WCHAR_POINT)
			{
				if(inputLength >= CALC_EDITOR_BUFFER_LENGTH - 1)
			    {
			    	onErrorPopup(CALC_FORMULA_TOO_LONG);
				    return;
			    }
				m_calcEditBox->insertText(CALC_WCHAR_MULT);
			}
				m_calcEditBox->insertText(CALC_WCHAR_SQUARE_ROOT);
			}
			break;
			
		case VCP_CALC_BUTTON_POWER_TWO:
			if(isInsertState() == VFX_TRUE)  /*insert state*/
			{
					isFormulaStart = VFX_FALSE;
				m_calcEditBox->insertText(CALC_WCHAR_POWER);
				break;
			}
				isFormulaStart = VFX_FALSE;
			if(m_charBeforeCursor != CALC_WCHAR_POWER)
			{
		
			if((m_charBeforeCursor < CALC_WCHAR_ZERO || m_charBeforeCursor > CALC_WCHAR_NINE)
				&& m_charBeforeCursor != CALC_WCHAR_POINT && m_charBeforeCursor != CALC_WCHAR_CLOSE_PAREN)
			{
				m_calcEditBox->insertText(CALC_WCHAR_ZERO);
			}
				m_calcEditBox->insertText(CALC_WCHAR_POWER);
			}
			break;
			
		case VCP_CALC_BUTTON_RECIPROCAL:
			
					isFormulaStart = VFX_FALSE;
			if(isInsertState() != VFX_TRUE)  /*insert state*/
			{
			if((m_charBeforeCursor == CALC_WCHAR_POWER) 
					|| m_charBeforeCursor == CALC_WCHAR_CLOSE_PAREN
					||(m_charBeforeCursor >= CALC_WCHAR_ZERO && m_charBeforeCursor <= CALC_WCHAR_NINE)
					|| m_charBeforeCursor == CALC_WCHAR_POINT)
			{
				if(inputLength >= CALC_EDITOR_BUFFER_LENGTH - 4)
			    {
			    	onErrorPopup(CALC_FORMULA_TOO_LONG);
				    return;
			    }
				m_calcEditBox->insertText(CALC_WCHAR_MULT);
			}
			}
			m_calcEditBox->insertText(CALC_WCHAR_OPEN_PAREN);
			m_calcEditBox->insertText(CALC_WCHAR_ONE);
			m_calcEditBox->insertText(CALC_WCHAR_DIV);
			m_calcEditBox->insertText(CALC_WCHAR_CLOSE_PAREN);
			m_calcEditBox->previous();
			break;
			
		case VCP_CALC_BUTTON_EQUAL:	
			VappCalculatorLogical calc(m_calcEditBox->getText());
			VfxDoube result = 0;
			errorCode = calc.translateToAntiPolandAndCompute(&result);
			VFX_TRACE(("\n[VappCalculatorPage::onBtnClick() Result: %f ]\n", result));

			if(errorCode == CALC_FORMULA_NO_ERROR)
			{
				isFormulaStart = VFX_TRUE;
				openParenNum = 0;
				m_calcEditBox->deleteAll();
				double2WString(m_resultString, result);
				m_calcEditBox->insertText(m_resultString);
				m_calcEditBox->deactivate();
				break;
			}
			else if(errorCode == CALC_FORMULA_EMPTY)
			{
				isFormulaStart = VFX_TRUE;
				openParenNum = 0;
				m_calcEditBox->deleteAll();
				m_calcEditBox->insertText(CALC_WCHAR_ZERO);
				m_calcEditBox->deactivate();
				break;
			}
			else
			{
				onErrorPopup(errorCode);
				m_calcEditBox->setCursorIndex(calc.getErrorIndex());
				break;
			}
	}
}


void VappCalculatorPage::onBtnStateChanged(VfxObject *obj, VfxId id, VcpButtonStateEnum state)
{
	/* draw a high light back ground imageframe when a button was pressed down */	
	if(state == VCP_BUTTON_STATE_PRESSED)
	{	
        if(m_btnHighLight == NULL)
        {
		    VFX_OBJ_CREATE(m_btnHighLight, VfxImageFrame, this);
#ifndef __LOW_COST_SUPPORT_COMMON__			
			m_btnHighLight->setImgContent(VfxImageSrc(IMG_ID_VAPP_CALCULATOR_BUTTON_HIGHT_LIGHT));
#else
			m_btnHighLight->setImgContent(VfxImageSrc(VCP_IMG_BUTTON_GLOW_EFFECT));
#endif


		    m_btnHighLight->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
			m_btnHighLight->setPosZ(1);
        }
		else
		{
		    //m_btnHighLight->setHidden(VFX_FALSE);
            m_btnHighLight->setOpacity(1);
		}
		//m_calcBtn[id]->bringToFront();
		//this->insertChildFrameBefore(m_calcBtn[id],m_btnHighLight);
		if(id == VCP_CALC_BUTTON_0 || id == VCP_CALC_BUTTON_EQUAL)
		{
			m_btnHighLight->setRect(m_calcBtn[id]->getRect().getX() - CALC_BUTTON_HIGH_LIGHT_BORDER, m_calcBtn[id]->getRect().getY() - CALC_BUTTON_HIGH_LIGHT_BORDER, 
				CALC_BUTTON_HIGH_LIGHT_BORDER * 2 + CALC_WIDE_BUTTON_WIDTH, CALC_BUTTON_HIGH_LIGHT_BORDER * 2 + CALC_BUTTON_HIGHT);
		}
		else
		{
			m_btnHighLight->setRect(m_calcBtn[id]->getRect().getX() - CALC_BUTTON_HIGH_LIGHT_BORDER, m_calcBtn[id]->getRect().getY() - CALC_BUTTON_HIGH_LIGHT_BORDER,
				CALC_BUTTON_HIGH_LIGHT_BORDER * 2 + CALC_BUTTON_WIDTH, CALC_BUTTON_HIGH_LIGHT_BORDER * 2 + CALC_BUTTON_HIGHT);
		}
	}

    /* hidden the highLight imageframe*/
	if(state == VCP_BUTTON_STATE_NORMAL)
	{
		//m_btnHighLight->setHidden(VFX_TRUE);
        m_btnHighLight->setOpacity(0);
	}  
}

#pragma arm section code, rodata

#endif



