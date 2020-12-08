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
 *  vapp_calculator_logical.cpp
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
 *
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
	 
#ifdef __MMI_CALCULATOR__

#include "vfx_uc_include.h"
#include "vapp_calculator_logical.h"

#pragma arm section code = "DYNAMIC_CODE_CALC_ROCODE", rodata = "DYNAMIC_CODE_CALC_RODATA"
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
 
VappCalculatorLogical::VappCalculatorLogical(const VfxWChar *inputFormula) : formulaLen(0)
{
	formulaLen = vfx_sys_wcslen(inputFormula);
	
	p_inputFormula = (VfxWChar *)get_ctrl_buffer(sizeof(VfxWChar)*(formulaLen + 1));
	p_operandStack = (double *)get_ctrl_buffer(sizeof(double)*(formulaLen + 1));
    p_operatorStack = (VfxWChar *)get_ctrl_buffer(sizeof(VfxWChar)*(formulaLen + 1));
	
	if(formulaLen == 0)
	{
		p_inputFormula[0] = CALC_WCHAR_NULL;
	}
	else
	{	
		vfx_sys_wcscpy(p_inputFormula, inputFormula);
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
#endif

}

VappCalculatorLogical::~VappCalculatorLogical()
{
	free_ctrl_buffer(p_inputFormula);
	free_ctrl_buffer(p_operandStack);
	free_ctrl_buffer(p_operatorStack);
}

inline void VappCalculatorLogical::pushOperandStack(double value)
{
	operandStackCount++;
	p_operandStack[operandStackCount] = value;
}

inline double VappCalculatorLogical::popOperandStack()
{
	return p_operandStack[operandStackCount--];
}

inline void VappCalculatorLogical::pushOperatorStack(VfxWChar currChar)
{
	operatorStackCount++;
	p_operatorStack[operatorStackCount] = currChar;
}

inline VfxWChar VappCalculatorLogical::popOperatorStack()
{
	return p_operatorStack[operatorStackCount--];
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
#endif

VfxBool VappCalculatorLogical::isOutofBoundary()
{
	if(operand1 >= CALC_MAX_VALUE || operand1 <= CALC_MIN_VALUE)
	{
		return VFX_TRUE;
	}
	else
	{
		return VFX_FALSE;
	}
}


CALC_ERROR_TYPE_ENUM VappCalculatorLogical::popUpUnaryOperator()
{
	while((p_operatorStack[operatorStackCount] == CALC_WCHAR_SQUARE_ROOT) || (p_operatorStack[operatorStackCount] == (VfxWChar)'p')
		|| (p_operatorStack[operatorStackCount] == (VfxWChar)'n'))
	{
		VfxWChar unaryOperator;
		unaryOperator = popOperatorStack();
		operand1 = popOperandStack();
		switch(unaryOperator)
		{
			case CALC_WCHAR_SQUARE_ROOT:
				if(operand1 < 0)
				{
					return CALC_NEGATIVE_CAN_NOT_BE_SQUARE_ROOT;
				}
				operand1 = sqrt(operand1);	
				break;
			case (VfxWChar)'p':
				break;
			case (VfxWChar)'n':
				operand1 = -operand1;
				break;
		}
		pushOperandStack(operand1);
	}
	return CALC_FORMULA_NO_ERROR;
}

CALC_ERROR_TYPE_ENUM VappCalculatorLogical::popUpMultDivOperator()
{
	while(p_operatorStack[operatorStackCount] == CALC_WCHAR_MULT || p_operatorStack[operatorStackCount] == CALC_WCHAR_DIV)
	{
		/* popup one operator and two operands to compute */
		VfxWChar multDivOperator;
		multDivOperator = popOperatorStack();
		operand2 = popOperandStack();
		operand1 = popOperandStack();

		if(operandStackCount < 0)
		{
			return CALC_INVALID_EXPRESSION;
		}
		switch(multDivOperator)
		{
			case CALC_WCHAR_MULT:
				operand1 = operand1 * operand2;
				if(isOutofBoundary())
				{
					return CALC_RESULT_EXCEED_BORDER;
				}
				break;
			case CALC_WCHAR_DIV:
				if(operand2 == 0)
				{
					return CALC_DIVISOR_CAN_NOT_BE_ZERO;
				}
				else
				{
					operand1 = operand1 / operand2;
					if(isOutofBoundary())
					{
						return CALC_RESULT_EXCEED_BORDER;
					}
				}
				break;
		}
		pushOperandStack(operand1);
		}
	return CALC_FORMULA_NO_ERROR;
}

CALC_ERROR_TYPE_ENUM VappCalculatorLogical::popUpPlusMinusOperator()
{
	while(p_operatorStack[operatorStackCount] == CALC_WCHAR_PLUS || p_operatorStack[operatorStackCount] == CALC_WCHAR_MINUS)
	{
		/* popup one operator and two operands to compute */
		VfxWChar plusMinusOperator;
		plusMinusOperator = popOperatorStack();
		operand2 = popOperandStack();
		operand1 = popOperandStack();

		if(operandStackCount < 0)
		{
			return CALC_INVALID_EXPRESSION;
		}
		switch(plusMinusOperator)
		{
			case CALC_WCHAR_PLUS:
				operand1 = operand1 + operand2;
				if(isOutofBoundary())
				{
					return CALC_RESULT_EXCEED_BORDER;
				}
				break;
			case CALC_WCHAR_MINUS:
				operand1 = operand1 - operand2;
				if(isOutofBoundary())
				{
					return CALC_RESULT_EXCEED_BORDER;
				}
				break;
		}
		pushOperandStack(operand1);
	}
	return CALC_FORMULA_NO_ERROR;
}


CALC_ERROR_TYPE_ENUM VappCalculatorLogical::translateToAntiPolandAndCompute(double *result)
{
	currCharIndex = 0;
	currState = CALC_EQUAL;
	operandStackCount = 0;
	operatorStackCount = 0;
	p_operandStack[operandStackCount] = 0;
	p_operatorStack[operatorStackCount] = CALC_WCHAR_NULL;
	operand1 = 0;
	operand2 = 0;
	VfxS32 currOperandLen = 0;
    VfxS32 fractionLen = 0;
    VfxBool isHasPoint = VFX_FALSE;  
	
	while(currCharIndex <= formulaLen)
	{
		currChar = p_inputFormula[currCharIndex];
		switch(currChar)
		{
		/************ plus or positive sign **********************/
		case CALC_WCHAR_PLUS:
			if(currState == CALC_BINARY_OPERATOR || currState == CALC_SQUARE_ROOT || currState == CALC_SIGN )
			{
				return CALC_INVALID_EXPRESSION;
			}
			if(currState == CALC_EQUAL || currState == CALC_OPEN_PAREN)   /* positive sign */
			{
				currChar = (VfxWChar)'p';
				pushOperatorStack(currChar);	
				currState = CALC_SIGN;
				currCharIndex++;
			}
			else
			{
				if(currState == CALC_OPERAND)
				{
					pushOperandStack(operand1); 		
				}
				errorCode = popUpUnaryOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				errorCode = popUpMultDivOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				errorCode = popUpPlusMinusOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				pushOperatorStack(currChar);
				currState = CALC_BINARY_OPERATOR;
				currCharIndex++;
			}
			break;

		/************ minus or negative sign **********************/
		case CALC_WCHAR_MINUS:
			if(currState == CALC_BINARY_OPERATOR || currState == CALC_SQUARE_ROOT || currState == CALC_SIGN )
			{
				return CALC_INVALID_EXPRESSION;
			}
			if(currState == CALC_EQUAL || currState == CALC_OPEN_PAREN)   /* negative sign */
			{
				currChar = (VfxWChar)'n';
				pushOperatorStack(currChar);			
				currState = CALC_SIGN;
				currCharIndex++;
			}
			else
			{
				if(currState == CALC_OPERAND)
				{
					pushOperandStack(operand1);
				}
				errorCode = popUpUnaryOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				errorCode = popUpMultDivOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				errorCode = popUpPlusMinusOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				pushOperatorStack(currChar);
				currState = CALC_BINARY_OPERATOR;
				currCharIndex++;
			}
			break;

		/************ mult or div **********************/
		case CALC_WCHAR_MULT:
		case CALC_WCHAR_DIV:
			if(currState == CALC_OPERAND)
			{
				pushOperandStack(operand1); 			
			}
			if(currState == CALC_OPERAND || currState == CALC_SQUARE || currState == CALC_CLOSE_PAREN)
			{
				errorCode = popUpUnaryOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				errorCode = popUpMultDivOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				pushOperatorStack(currChar);
				currState = CALC_BINARY_OPERATOR;
				currCharIndex++;
			}	
			else
			{
				return CALC_INVALID_EXPRESSION;
			}		
			break;

		/************ square root **********************/
		case CALC_WCHAR_SQUARE_ROOT:
			if(currState == CALC_EQUAL || currState == CALC_BINARY_OPERATOR || currState == CALC_SIGN || currState == CALC_OPEN_PAREN)
			{
				pushOperatorStack(currChar);
				currState = CALC_SQUARE_ROOT;
				currCharIndex++;
			}
			else if(currState == CALC_CLOSE_PAREN)
			{
				errorCode = popUpUnaryOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				errorCode = popUpMultDivOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}	
				pushOperatorStack(CALC_WCHAR_MULT);
				pushOperatorStack(currChar);
				currState = CALC_SQUARE_ROOT;
				currCharIndex++;
			}
			else if(currState == CALC_OPERAND)
			{
				pushOperandStack(operand1); 
				errorCode = popUpUnaryOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				errorCode = popUpMultDivOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}	    
				pushOperatorStack(CALC_WCHAR_MULT);
				pushOperatorStack(currChar);
				currState = CALC_SQUARE_ROOT;
				currCharIndex++;
			}
			else
			{
				return CALC_INVALID_EXPRESSION;
			}
			break;

		/************ square **********************/
		case CALC_WCHAR_POWER:
			if(currState == CALC_CLOSE_PAREN)
			{
				operand1 = popOperandStack();
				operand1 = operand1 * operand1;
				if(isOutofBoundary())
				{
					return CALC_RESULT_EXCEED_BORDER;
				}
				pushOperandStack(operand1);
				currState = CALC_SQUARE;
				currCharIndex++;
			}
			else if(currState == CALC_OPERAND)
			{
				operand1 = operand1 * operand1;
				if(isOutofBoundary())
				{
					return CALC_RESULT_EXCEED_BORDER;
				}
				pushOperandStack(operand1);
				currState = CALC_SQUARE;
				currCharIndex++;
			}
			else
			{
				return CALC_INVALID_EXPRESSION;
			}	
			break;

		/************ left parenthesis ******************/
		case CALC_WCHAR_OPEN_PAREN:
			if(currState == CALC_SQUARE)
			{
				return CALC_INVALID_EXPRESSION;
			}
			else if(currState == CALC_CLOSE_PAREN)
			{
				pushOperatorStack(CALC_WCHAR_MULT);
				pushOperatorStack(currChar);
				currState = CALC_OPEN_PAREN;
				currCharIndex++;
			}
			else if(currState == CALC_OPERAND)
			{
				pushOperandStack(operand1);
				errorCode = popUpUnaryOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				errorCode = popUpMultDivOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				pushOperatorStack(CALC_WCHAR_MULT);
				pushOperatorStack(currChar);
				currState = CALC_OPEN_PAREN;
				currCharIndex++;
			}
			else
			{
				pushOperatorStack(currChar);
				currState = CALC_OPEN_PAREN;
				currCharIndex++;
			}		
			break;

		/************** right parenthesis *******************/
		case CALC_WCHAR_CLOSE_PAREN:
			if(currState == CALC_OPERAND)
			{
				pushOperandStack(operand1);
			}
			if(currState == CALC_OPERAND || currState == CALC_SQUARE || currState == CALC_CLOSE_PAREN)
			{
				errorCode = popUpUnaryOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				errorCode = popUpMultDivOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				errorCode = popUpPlusMinusOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				if(operatorStackCount <= 0)
				{
					return CALC_BRACKETS_DO_NOT_MATCH;
				}
				popOperatorStack();              /*pop up "(" */
				currState = CALC_CLOSE_PAREN;
				currCharIndex++;
			}
			else 
			{
				return CALC_INVALID_EXPRESSION;
			}	
			break;

		/*************** . 0 - 9 **********************/
		case CALC_WCHAR_ZERO:
		case CALC_WCHAR_ONE:
		case CALC_WCHAR_TWO:
		case CALC_WCHAR_THREE:
		case CALC_WCHAR_FOUR:
		case CALC_WCHAR_FIVE:
		case CALC_WCHAR_SIX:
		case CALC_WCHAR_SEVEN:
		case CALC_WCHAR_EIGHT:
		case CALC_WCHAR_NINE:
		case CALC_WCHAR_POINT:
			if(currState == CALC_SQUARE)
			{
				return CALC_INVALID_EXPRESSION;
			}
			else if(currState == CALC_OPERAND)
			{
				if(currChar == CALC_WCHAR_POINT)
				{
					if(isHasPoint == VFX_FALSE)
					{
						isHasPoint = VFX_TRUE;
						fractionLen = 0;
						currOperandLen++;
						if(currOperandLen > MAX_OPERAND_LEN)
						{
							return CALC_OPERAND_TOO_LONG;
						}				
					}
					else
					{
						return CALC_INVALID_OPERAND;
					}
				}
				else if(currChar >= CALC_WCHAR_ZERO && currChar <= CALC_WCHAR_NINE)
				{
					if(isHasPoint == VFX_FALSE)
					{
						operand1 = operand1 * 10 + currChar - CALC_WCHAR_ZERO;
						currOperandLen++;
						if(currOperandLen > MAX_OPERAND_LEN)
						{
							return CALC_OPERAND_TOO_LONG;
						}
					}
					else
					{	
						fractionLen++;
						VfxS32 tmp = fractionLen;
						double fraction = currChar - CALC_WCHAR_ZERO;
						while(tmp)
						{
							fraction = fraction / 10;
							tmp--;
						}
						operand1 = operand1 + fraction;
						currOperandLen++;
						if(currOperandLen > MAX_OPERAND_LEN)
						{
							return CALC_OPERAND_TOO_LONG;
						}
					}
				}
			}
			else if(currState == CALC_CLOSE_PAREN)	
			{
				errorCode = popUpUnaryOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				errorCode = popUpMultDivOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				pushOperatorStack(CALC_WCHAR_MULT);

				if(currChar == CALC_WCHAR_POINT)
				{
					isHasPoint = VFX_TRUE;
					currOperandLen = 1;
					fractionLen = 0;
					operand1 = 0;
					currState = CALC_OPERAND;
				}
				else
				{
					isHasPoint = VFX_FALSE;
					currOperandLen = 1;
					fractionLen = 0;
					operand1 = currChar - CALC_WCHAR_ZERO;
					currState = CALC_OPERAND;
				}
			}
			else
			{
				if(currChar == CALC_WCHAR_POINT)
				{
					isHasPoint = VFX_TRUE;
					currOperandLen = 1;
					fractionLen = 0;
					operand1 = 0;
					currState = CALC_OPERAND;
				}
				else
				{
					isHasPoint = VFX_FALSE;
					currOperandLen = 1;
					fractionLen = 0;
					operand1 = currChar - CALC_WCHAR_ZERO;
					currState = CALC_OPERAND;
				}
			}
			currCharIndex++;
			break;

		/*************** formula end **********************/
		case CALC_WCHAR_NULL:
			if(currState == CALC_OPERAND)
			{
				pushOperandStack(operand1);
			}
			if(currState == CALC_OPERAND || currState == CALC_SQUARE || currState == CALC_CLOSE_PAREN)
			{
				errorCode = popUpUnaryOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				errorCode = popUpMultDivOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;
				}
				errorCode = popUpPlusMinusOperator();
				if(errorCode != CALC_FORMULA_NO_ERROR)
				{
					return errorCode;		
				}
				if(operatorStackCount != 0 || operandStackCount != 1)
				{
					if(operatorStackCount != 0)
					{
						return CALC_BRACKETS_DO_NOT_MATCH;
					}
					else
					{
						return CALC_INVALID_EXPRESSION;
					}
				}		
				currState = CALC_END;
				*result = operand1;          /* return the compute result if no error happen */
				return CALC_FORMULA_NO_ERROR;
			}
			if(currState == CALC_EQUAL)
			{
				return CALC_FORMULA_EMPTY;
			}
			else 
			{
				return CALC_INVALID_EXPRESSION;
			}
			//break;
		/*************** other characters **********************/
		default:
			return CALC_INVALID_EXPRESSION;
		}
	} /* while(currCharIndex < formulaLen) */
	return CALC_FORMULA_NO_ERROR;
}

VfxS32 VappCalculatorLogical::getErrorIndex()
{
	return currCharIndex;
}

#pragma arm section code, rodata

#endif /* __MMI_CALCULATOR__ */

