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
 *  vapp_calculator.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CALCULATOR_H__
#define __VAPP_CALCULATOR_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_calculator_logical.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Calculator Button
 *****************************************************************************/
 
class VappCalculatorButton : public VcpButton
{
    //VFX_DECLARE_CLASS(VappCalculatorButton);

public:
    VfxWChar getOutputWChar();
    void setOutputWChar(VfxWChar btnOutputWChar);
    VfxSignal2 <VfxObject*, VfxId> m_longPressed;

protected:
    virtual VfxBool onPenInput(VfxPenEvent &event);
    
private:
    // WChar insert into VcpTextEditor when tap button
    VfxWChar outputWChar;
};


/***************************************************************************** 
 * Calculator MainPage
 *****************************************************************************/
 
class VappCalculatorPage : public VfxPage
{
    //VFX_DECLARE_CLASS(VappCalculatorPage);
    
public:
// Default constructor
    VappCalculatorPage();

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    
public:
	    // TextEditor, used to store and dispaly input strings
	VcpTextEditor *m_calcEditBox;
	void on2ndinit();
    
private:
    // store the string in the editor into calculator.txt
    void storeFormula();
    
    // read the string in calculator.txt and insert them into editor when enter Calculator
    void recoverFormula();

    // place the components when enter Calculator
    void placeCalcComponent();

    // connect signal function when button's state changed between "Normal" and "Pressed"
    void onBtnStateChanged(VfxObject *obj,VfxId Id, VcpButtonStateEnum state);

    // check the cursor if in insert state
    VfxBool isInsertState();

    // check the char before cursor if a plus or minus sign 
    VfxBool isCharBeforeCursorSign();

    // check the char before cursor if a add or subtract sign 
    VfxBool isCharBeforeCursorPlusMinus();

    // convert double to wide string
    void double2WString(VfxWChar *WString, VfxDoube result);

    // set connect function when button was clicked
    void setCalcButtonClickedAction();

    // check the operand before cursor if allow append number any more 
    VfxBool checkOperandBeforeCursor();

    // popup error message when error happen 
    void onErrorPopup(CALC_ERROR_TYPE_ENUM errorCode);

    // clear TextEditor when long press "Backspace" button
    void onDelBtnLongPress(VfxObject *obj, VfxId id);

    // connect signal function when button was clicked
    void onBtnClick(VfxObject *obj, VfxId id);

	// cosmos 1.1 key support
    virtual VfxBool onKeyInput(VfxKeyEvent &event);



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
#endif    

private:
    // Calculator Number button: "0~9", "."
    enum CalcNumBtnEnum
    {
		VCP_CALC_BUTTON_0,
		VCP_CALC_BUTTON_1,
        VCP_CALC_BUTTON_2,
        VCP_CALC_BUTTON_3,
		VCP_CALC_BUTTON_4,
        VCP_CALC_BUTTON_5,
        VCP_CALC_BUTTON_6,
		VCP_CALC_BUTTON_7,
        VCP_CALC_BUTTON_8,
        VCP_CALC_BUTTON_9,
        VCP_CALC_BUTTON_POINT,
        VCP_CALC_NUM_BUTTON_TOTAL,
    };

    // Calculator System button: the first item must = VCP_CALC_NUM_BUTTON_TOTAL
    /*enum CalcSysBtnEnum{
        VCP_CALC_BUTTON_PLUS = VCP_CALC_NUM_BUTTON_TOTAL,
        VCP_CALC_BUTTON_MINUS,        
        VCP_CALC_BUTTON_MULT,
        VCP_CALC_BUTTON_DIV,
        VCP_CALC_BUTTON_SQUARE_ROOT,
        VCP_CALC_BUTTON_POWER_TWO,
        VCP_CALC_BUTTON_RECIPROCAL,
		VCP_CALC_BUTTON_OPEN_PAREN,
        VCP_CALC_BUTTON_CLOSE_PAREN,
        VCP_CALC_BUTTON_BACKSAPCE,
		VCP_CALC_BUTTON_AC,
        VCP_CALC_BUTTON_EQUAL,
        VCP_CALC_BUTTON_TOTAL,
    };*/
	
    enum CalcSysBtnEnum{
		VCP_CALC_BUTTON_AC = VCP_CALC_NUM_BUTTON_TOTAL,
		VCP_CALC_BUTTON_SQUARE_ROOT,
		VCP_CALC_BUTTON_POWER_TWO,
		VCP_CALC_BUTTON_RECIPROCAL,
		VCP_CALC_BUTTON_OPEN_PAREN,		
		VCP_CALC_BUTTON_PLUS,
		VCP_CALC_BUTTON_MULT,
		VCP_CALC_BUTTON_BACKSAPCE,
		VCP_CALC_BUTTON_CLOSE_PAREN,
        VCP_CALC_BUTTON_MINUS,     
        VCP_CALC_BUTTON_DIV,
        VCP_CALC_BUTTON_EQUAL,
        VCP_CALC_BUTTON_TOTAL,
    };

    // error code when formula invalid 
    CALC_ERROR_TYPE_ENUM errorCode; 

    // if start a new compute process
    VfxBool isFormulaStart; 

  // cursor index in TextEditor
  // VfxS32 CursorIndex;

    // string length in TextEditor
	VfxS32 inputLength;

    // the length of operand which before cursor, used when cursor at the end of string 
	VfxS32 currOperandLen;

    // check the operand if has "."
	VfxBool isHasPoint;

    // the bumber of "(" subtract the number of ")"
    VfxS32 openParenNum;

    // char before TextEditor cursor
	VfxWChar m_charBeforeCursor;

    // buffer strore compute result 
	VfxWChar m_resultString[2 * MAX_OPERAND_LEN + 2];
    
    // calculator background image 
    VfxImageFrame *m_calculatorBg;

    // TextEditor background image
    VfxImageFrame *m_editorBg;

    // highlight image when button was tapped
    VfxImageFrame *m_btnHighLight;



    // calculator buttons, which input numbers and operators into TextEditor
    //VappCalculatorButton *m_calcBtn[VCP_CALC_BUTTON_TOTAL];
    VappCalculatorButton *m_calcBtn[VCP_CALC_BUTTON_TOTAL];

};

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
#endif

/***************************************************************************** 
 * Calculator App
 *****************************************************************************/
 
class VappCalculatorApp : public VfxApp, public IVfxMainScrHandler
{
    VFX_DECLARE_CLASS(VappCalculatorApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();
	virtual void onScr1stReady(VfxMainScrEx * scr);
	virtual void onScr2ndReady(VfxMainScrEx * scr);

private:
    //main screen instance
    //VappCalculatorScreen *m_mainScr;
	VfxMainScrEx *m_mainScr;
	VappCalculatorPage *m_page;
};

#endif /* __VAPP_CALCULATOR_H__ */

