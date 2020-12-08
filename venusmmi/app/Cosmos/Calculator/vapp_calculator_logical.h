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
 *  vapp_calculator_logical.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *  "p"  positive
 *  "n"  negative
 *  "s"  square root
 *  "^"  square
 *  "+"  plus
 *  "-"  minus
 *  "*"  mult
 *  "/"  div
 *  "("  left parenthesis
 *  ")"  right parenthesis
 *
 *  Most 128 WChar characters can be input.
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
 *
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CALCULATOR_LOGICAL_H__
#define __VAPP_CALCULATOR_LOGICAL_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/
const VfxS32 CALC_BUFFER_MAX_LEN = 128 + 1;
const VfxS32 MAX_OPERAND_LEN = 12;
const double CALC_MAX_VALUE  = 999999999999.5;
const double CALC_MIN_VALUE  = -999999999999.5;

const VfxWChar CALC_WCHAR_EQUAL     =      (VfxWChar)'=';
const VfxWChar CALC_WCHAR_PLUS      =      (VfxWChar)'+';
const VfxWChar CALC_WCHAR_MINUS     =      (VfxWChar)'-';
const VfxWChar CALC_WCHAR_MULT      =      (VfxWChar)0X00D7;
const VfxWChar CALC_WCHAR_DIV       =      (VfxWChar)'/';
const VfxWChar CALC_WCHAR_POINT     =      (VfxWChar)'.';
const VfxWChar CALC_WCHAR_ZERO      =      (VfxWChar)'0';
const VfxWChar CALC_WCHAR_ONE       =      (VfxWChar)'1';
const VfxWChar CALC_WCHAR_TWO       =      (VfxWChar)'2';
const VfxWChar CALC_WCHAR_THREE     =      (VfxWChar)'3';
const VfxWChar CALC_WCHAR_FOUR      =      (VfxWChar)'4';
const VfxWChar CALC_WCHAR_FIVE      =      (VfxWChar)'5';
const VfxWChar CALC_WCHAR_SIX       =      (VfxWChar)'6';
const VfxWChar CALC_WCHAR_SEVEN     =      (VfxWChar)'7';
const VfxWChar CALC_WCHAR_EIGHT     =      (VfxWChar)'8';
const VfxWChar CALC_WCHAR_NINE      =      (VfxWChar)'9';
const VfxWChar CALC_WCHAR_POWER     =      (VfxWChar)0X00B2;
const VfxWChar CALC_WCHAR_SQUARE_ROOT =    (VfxWChar)0X221A;
const VfxWChar CALC_WCHAR_OPEN_PAREN  =    (VfxWChar)'(';
const VfxWChar CALC_WCHAR_CLOSE_PAREN =    (VfxWChar)')';
const VfxWChar CALC_WCHAR_NULL        =    (VfxWChar)'\0';

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum CALC_ERROR_TYPE_ENUM
{
    CALC_FORMULA_NO_ERROR = 0,
	CALC_INVALID_EXPRESSION = -1,
    CALC_FORMULA_TOO_LONG = -2,
    CALC_DIVISOR_CAN_NOT_BE_ZERO = -3,
    CALC_NEGATIVE_CAN_NOT_BE_SQUARE_ROOT = -4,
    CALC_OPERAND_TOO_LONG = -5,
    CALC_INVALID_OPERAND = -6,
    CALC_RESULT_EXCEED_BORDER = -7,  
    CALC_BRACKETS_DO_NOT_MATCH = -8,
    CALC_FORMULA_EMPTY = -9,  
}error_type_name;

/***************************************************************************** 
 * Class VappCalculatorLogical
 *****************************************************************************/      
class VappCalculatorLogical
{

// Constructor / Destructor
public:
    VappCalculatorLogical(const VfxWChar *inputFormula);
    ~VappCalculatorLogical();

// Member function
public:
    VfxS32 getErrorIndex();
    CALC_ERROR_TYPE_ENUM translateToAntiPolandAndCompute(double *result);
    
private:
    void pushOperandStack(double value);
    double popOperandStack();
    void pushOperatorStack(VfxWChar currChar);
    VfxWChar popOperatorStack();
    
    VfxBool isOutofBoundary();
    CALC_ERROR_TYPE_ENUM popUpUnaryOperator();
    CALC_ERROR_TYPE_ENUM popUpMultDivOperator();
    CALC_ERROR_TYPE_ENUM popUpPlusMinusOperator();

// Date member
private: 
    typedef enum CALC_LOGICAL_STATE
    {
        CALC_EQUAL,
        CALC_OPERAND,
        CALC_BINARY_OPERATOR,
        CALC_SQUARE,
        CALC_SQUARE_ROOT,
        CALC_SIGN,
        CALC_OPEN_PAREN,
        CALC_CLOSE_PAREN,
        CALC_END
    }calc_logical_stated;

    VfxS32  formulaLen; 
    VfxWChar *p_inputFormula;
    double *p_operandStack;
    VfxWChar *p_operatorStack; 

#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    VfxS32  operandStackCount;
    VfxS32  operatorStackCount;
    
    VfxWChar currChar;
    VfxS32  currCharIndex;
    VfxS32 currState;
    double operand1;
    double operand2;
    VfxS32 currOperandLen;
    VfxS32 fractionLen;
    VfxBool isHasPoint;   
    CALC_ERROR_TYPE_ENUM errorCode;

};

#endif /* __VAPP_CALCULATOR_LOGICAL_H__ */

