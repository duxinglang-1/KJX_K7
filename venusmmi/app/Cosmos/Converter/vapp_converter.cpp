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
 *  vapp_converter.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file is used to implement converter.
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
 *
 * removed!
 * removed!
 * removed!
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
#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif
extern "C"
{
#include "mmi_features.h"

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif
}
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vtst_rt_main.h"


#ifdef __MMI_CONVERTER__
#include "vapp_converter.h"
#include "mmi_rp_vapp_converter_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "GlobalResDef.h"



/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
//this table used to store value which will be used when entry converter the fisrt time. 
const vapp_conv_currency_rate_struct vappConverterCurrencyRates[VAPP_CONVERTER_CURRENCY_RATE_TOTAL] = 
{  
    {STR_ID_VAPP_CONVERTER_CHY, 1},
    {STR_ID_VAPP_CONVERTER_USD, 1},
    {STR_ID_VAPP_CONVERTER_EUR, 1},
    {STR_ID_VAPP_CONVERTER_GBP, 1},
    {STR_ID_VAPP_CONVERTER_HKD, 1},
    {STR_ID_VAPP_CONVERTER_JPY, 1},
    {STR_ID_VAPP_CONVERTER_KRW, 1},
    {STR_ID_VAPP_CONVERTER_SEK, 1},
    {STR_ID_VAPP_CONVERTER_AUD, 1},
    {STR_ID_VAPP_CONVERTER_CHF, 1}
};

const double vappConverterWeightRates[VAPP_CONVERTER_WEIGHT_TOTAL] = {0.4535924, 1, 16};
const double vappConverterLengthRates[VAPP_CONVERTER_LENGTH_TOTAL] = {100, 1, 0.001, 1.0936133 * 36, 1.0936133, 1.0936133 * 3, 1.0936133 / 1760};

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/***************************************************************************** 
 * Global Function
 *****************************************************************************/


/***************************************************************************** 
 * Class VappConverterContext
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappConverterContext", VappConverterContext, VfxObject);

void VappConverterContext::onInit()
{
    VfxObject::onInit();

    //initial value
    S16 error;
    U8 firstLaunch; // set default value / read from NVRAM
    
    ReadValue(NVRAM_CONVERTER_FIRST_LAUNCH, &firstLaunch, DS_BYTE, &error);

    if (firstLaunch) /* after restore factory or first time launch Converter */
    {
        //VfxId index;
        //for (index = 0; index < NVRAM_EF_CONV_CURRENCY_RATE_TOTAL; index++)
        //{
        //    WriteRecord(
        //        NVRAM_EF_CONV_CURRENCY_RATE_LID,
        //        (index + 1),
        //        (void*)&vappConverterCurrencyRates[index],
        //        NVRAM_EF_CONV_CURRENCY_RATE_SIZE,
        //        &error);
        //}
        //firstLaunch = 0;
        setCurrencyRates(vappConverterCurrencyRates);
        //WriteValue(NVRAM_CONVERTER_FIRST_LAUNCH, &firstLaunch, DS_BYTE, &error);
    }
    else
    {
        ReadMultiRecord(
            NVRAM_EF_CONV_CURRENCY_RATE_LID,
            1,
            m_currencyRates,
            NVRAM_EF_CONV_CURRENCY_RATE_SIZE * NVRAM_EF_CONV_CURRENCY_RATE_TOTAL,
            NVRAM_EF_CONV_CURRENCY_RATE_TOTAL,
            &error);
    }
    
    ReadValue(NVRAM_CONVERTER_LAST_USE_TYPE, &m_type, DS_BYTE, &error);

    vapp_conv_type_pair_struct pair;
    ReadRecord(
        NVRAM_EF_CONV_TYPE_PAIR_LID,
        (U16)(m_type + 1),
         &pair,
        NVRAM_EF_CONV_TYPE_PAIR_SIZE,
        &error);
    setUpperUnit((VfxU8)pair.upper_id);
    setLowerUnit((VfxU8)pair.lower_id);

    setUpperValue(0);
    setLowerValue(0);
}


void VappConverterContext::onDeinit()
{
    VfxObject::onDeinit();
}


double VappConverterContext::wStringToDouble(VfxWChar *s)
{
    CHAR *ansii_str;
    S32 len;
    len = mmi_wcslen((WCHAR*)s);
    VFX_ALLOC_MEM(ansii_str, len + 1, this);
    mmi_wcs_to_asc((CHAR*)ansii_str, (WCHAR*)s);
    double ret;
    ret = atof(ansii_str);
    VFX_FREE_MEM(ansii_str);
    return ret;
}


void VappConverterContext::doubleToWString(VfxWChar *s, double number, VfxS16 max_digits)
{
    CHAR *tmp, fmt[8];    
    VFX_ALLOC_MEM(tmp, (max_digits + 1) * 2, this);
    kal_sprintf(fmt, "%%.%df", (max_digits - 2));
    kal_sprintf(tmp, fmt, number);

    CHAR *p;
    p = strchr((char*)tmp, '.');
    if (p)
    {
        *p = 0;
    }

    S32 len;
    len = strlen((char*)tmp);
    if ((max_digits - len - 1) > 0)
    {
        kal_sprintf(fmt, "%%%d.%df", len, (max_digits - len - 1));
        kal_sprintf(tmp, fmt, number);
    }
    else
    {
        kal_sprintf(fmt, "%%%d.%df", len, 0);
        kal_sprintf(tmp, fmt, number);
    }
    memset(s, 0x0, sizeof(VfxWChar) * (max_digits + 1));
    mmi_asc_n_to_wcs((WCHAR*)s, (CHAR*)tmp, max_digits);
    removeZeroInTail(s);
    VFX_FREE_MEM(tmp);
}


void VappConverterContext::removeZeroInTail(VfxWChar *buffer)
{
    S32 length;    
    length = mmi_ucs2strlen((CHAR*)buffer);

    S32 dotIndex;    
    for (dotIndex = 0; dotIndex < length; dotIndex++)
    {
        if (buffer[dotIndex] == '.')
            break;
    }
    if (dotIndex == length) /* integer */
        return;
    
    S32 index;
    index = length - 1;
    while(index != dotIndex)
    {
        if (buffer[index] != '0')
        {
            buffer[++index] = 0;
            return;
        }
        index--;
    }
    buffer[index] = 0;
}


void VappConverterContext::setCurrencyRates(const vapp_conv_currency_rate_struct *rates)
{
    memcpy(m_currencyRates, rates, NVRAM_EF_CONV_CURRENCY_RATE_TOTAL * sizeof(vapp_conv_currency_rate_struct));
}

void VappConverterContext::getCurrencyRates(vapp_conv_currency_rate_struct *rates)
{
    memcpy(rates, m_currencyRates, NVRAM_EF_CONV_CURRENCY_RATE_TOTAL * sizeof(vapp_conv_currency_rate_struct));
}


void VappConverterContext::getCurrencyRate(VfxId index, vapp_conv_currency_rate_struct *r)
{
    r->rate = m_currencyRates[index].rate;
    r->str_id = m_currencyRates[index].str_id;
}


/***************************************************************************** 
 * Class VappConverterCurrencyPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappConverterCurrencyPage", VappConverterCurrencyPage, VfxPage);
void VappConverterCurrencyPage::onInit()
{
    VfxPage::onInit();
    
    VFX_OBJ_CREATE(m_currencyPageForm, VcpForm, this);

    VcpTitleBar *titleBar;
    VfxWString str;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    str.loadFromRes(STR_ID_VAPP_CONVERTER_SET_CURRECNY_RATES);
    titleBar->setTitle(str);
    setTopBar(titleBar);
    
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    str.loadFromRes(STR_GLOBAL_SAVE);
    m_toolBar->addItem(ID_CURRENCY_TOOLBAR_SAVE, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);       // add tool bar
    str.loadFromRes(STR_GLOBAL_CANCEL);
    m_toolBar->addItem(ID_CURRENCY_TOOLBAR_CANCEL, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);       // add tool bar
    m_toolBar->m_signalButtonTap.connect(this, &VappConverterCurrencyPage::onCurrencyToolBarTap);
    setBottomBar(m_toolBar); 
    
    VFX_OBJ_CREATE(m_currencyPageForm, VcpForm, this);
    m_currencyPageForm->setSize(getSize());
    m_currencyPageForm->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpFormItemTextInput *textInput;
    VcpFunctionBar *functionBar;
    VFX_OBJ_CREATE(functionBar, VcpFunctionBar, this);
    str.loadFromRes(STR_GLOBAL_SAVE);
    functionBar->addItem(ID_CURRENCY_FUNCTIONBAR_SAVE, str);
    functionBar->setItemSpecial(ID_CURRENCY_FUNCTIONBAR_SAVE);
    functionBar->m_signalButtonTap.connect(this, &VappConverterCurrencyPage::onCurrencyFunctionBarTap);
    VfxId i;
    vapp_conv_currency_rate_struct r;

    for (i = 0; i < NVRAM_EF_CONV_CURRENCY_RATE_TOTAL; i++)
    {
        // get rate string id and value
        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getCurrencyRate(i, &r);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_currencyPageForm);
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        str.loadFromRes(r.str_id);
        textInput->setLabelText(str);

        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_DECIMAL_NUMERIC);
        VfxWChar *string;
        // add one char number for dot ".0001"
        VFX_ALLOC_MEM(string, sizeof(VfxWChar) * (VAPP_CONVERTER_MAX_RATE_BUF_LEN + 1 + 1), this);
        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->doubleToWString(string, r.rate, VAPP_CONVERTER_MAX_RATE_BUF_LEN + 1);
        if (mmi_wcslen((WCHAR*)string) == (VAPP_CONVERTER_MAX_RATE_BUF_LEN + 1))
        {
            VfxWChar tmp[VAPP_CONVERTER_MAX_RATE_BUF_LEN + 1 + 1];
            mmi_wcscpy((WCHAR*)tmp, (WCHAR*)string);
            tmp[0] = 0;
            textInput->getTextBox()->setText(&tmp[1], VAPP_CONVERTER_MAX_RATE_BUF_LEN);
        }
        else
        {
            textInput->getTextBox()->setText(string, VAPP_CONVERTER_MAX_RATE_BUF_LEN);
        }
        VFX_FREE_MEM(string);
        textInput->getTextBox()->setId(i);
        textInput->getTextBox()->setDisableClipboard(VFX_TRUE);
        textInput->getTextBox()->m_signalTextChanged.connect(this, &VappConverterCurrencyPage::onTextChanged);
        textInput->getTextBox()->m_signalActivated.connect(this, &VappConverterCurrencyPage::onTextActivated);
        textInput->getTextBox()->m_signalBeforeChange.connect(this, &VappConverterCurrencyPage::onTextInsert);
        textInput->getTextBox()->setAlignMode(VCP_TEXT_ALIGN_MODE_RIGHT);        
        textInput->getTextBox()->setFunctionBar((VfxFrame*)functionBar);
        m_currencyPageForm->addItem(textInput, i);
    }
}


void VappConverterCurrencyPage::onTextChanged(VcpTextEditor *sender)
{
    return;
}


void VappConverterCurrencyPage::onTextActivated(VcpTextEditor *sender, VfxBool activated)
{
    VfxWChar *str;
    str = sender->getText();
    VfxU32 len;
    len = mmi_wcslen((WCHAR*)str);
    if (activated)
    {
        sender->setHighlight(0, len);
        m_currActiveIndex = sender->getId();
    }
    else
    {
        sender->setHighlight(0, 0);
    }
}

void VappConverterCurrencyPage::onTextInsert(
        VfxWChar *str,  // [IN] current text string buf
        VfxS32 pos,     // [IN] will be inserted char
        VcpTextChangeEnum type,
        VfxBool *changed // [OUT] flad indicate to insert or not
    ) 
{
    *changed = VFX_TRUE;
    switch (type)
    {
        case VCP_TEXT_CHANGE_INSERT_CHAR:
            VFX_ASSERT(str != NULL);
            VcpTextEditor *sender;
            VcpFormItemTextInput* textInput;
            textInput = (VcpFormItemTextInput*)(m_currencyPageForm->getItem(m_currActiveIndex));
            sender = textInput->getTextBox();
            VfxWChar *textBuf;
            textBuf = sender->getText();

            if (mmi_wcslen((WCHAR*)textBuf) == 0)
            {
                *changed = VFX_TRUE;
                return;
            }

            // dot won't make number bigger
            if (mmi_wcscmp((WCHAR*)str, (WCHAR*)L".") == 0) // .
            {
                if (mmi_wcsrchr(textBuf, L'.'))
                {
                    *changed = VFX_FALSE; // don't allow two point
                    return;
                }
                *changed = VFX_TRUE;
                return;
            }
            else if (mmi_wcscmp((WCHAR*)str, (WCHAR*)L"0") == 0) // 0
            {
                // the followting cases won't impact value, editor will skip it.
                if ((pos == 0 && mmi_wcsncmp((WCHAR*)textBuf, (WCHAR*)L".", 1) != 0) || 
                    (pos == 1 && mmi_wcsncmp((WCHAR*)textBuf, (WCHAR*)L"0", 1) == 0))
                {
                    *changed = VFX_FALSE;
                    return;
                }
            }
            else // 1~9
            {
                if (pos == 1 && mmi_wcsncmp((WCHAR*)textBuf, (WCHAR*)L"0", 1) == 0)
                {
                    // first calculate, then delete
                    sender->deleteChars();
                    *changed = VFX_TRUE;
                    return;
                }
            }
            break;
        case VCP_TEXT_CHANGE_DELETE_CHAR:
        case VCP_TEXT_CHANGE_DELETE_ALL:
        case VCP_TEXT_CHANGE_INSERT_STR:
            break;
    }
}


void VappConverterCurrencyPage::onDeinit()
{
    VfxPage::onDeinit();
}


void VappConverterCurrencyPage::onBarSaveCommond()
{
    VfxBool errorFlag = VFX_FALSE;
    VfxU32 i;
    VcpFormItemTextInput* textInput;
    VfxWString string;
    VfxWChar *str;
    VfxBool emptyErrorStr[NVRAM_EF_CONV_CURRENCY_RATE_TOTAL];
    for (i = 0; i < NVRAM_EF_CONV_CURRENCY_RATE_TOTAL; i++)
    {
        emptyErrorStr[i] = VFX_FALSE;
        textInput = (VcpFormItemTextInput*)(m_currencyPageForm->getItem(i));
        str = textInput->getTextBox()->getText();
        double val;
        val = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->wStringToDouble(str);
        if (mmi_wcslen((WCHAR *)str) == 0)
        {
            errorFlag = VFX_TRUE;
            string.loadFromRes(STR_ID_VAPP_CONVERTER_EMPTY_CURRECNY_RATE);
            textInput->setWarningText(string);
        }
        else if (val == 0)
        {
            errorFlag = VFX_TRUE;
            string.loadFromRes(STR_ID_VAPP_CONVERTER_INVALID_CURRECNY_RATE);
            textInput->setWarningText(string);
        }
        else
        {
            emptyErrorStr[i] = VFX_TRUE;
            //textInput->setWarningText(VFX_WSTR_EMPTY);
        }
    }
    if (errorFlag)
    {
        VfxBool focus = VFX_FALSE;
        for (i = 0; i < NVRAM_EF_CONV_CURRENCY_RATE_TOTAL; i++)
        {
            if (emptyErrorStr[i])
            {
                textInput = (VcpFormItemTextInput*)(m_currencyPageForm->getItem(i));
                textInput->setWarningText(VFX_WSTR_EMPTY);
            }
            else if (!focus)
            {
                focus = VFX_TRUE;
                m_currencyPageForm->scrollItemToView(i, VCPFORM_SCROLL_TOP);
            }
        }
        return;
    }
    
    // save currency rate                
    VfxId index;
    vapp_conv_currency_rate_struct *rates;
    VFX_ALLOC_MEM(rates, NVRAM_EF_CONV_CURRENCY_RATE_TOTAL * sizeof(vapp_conv_currency_rate_struct), this);
    ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getCurrencyRates(rates);
    double val;
    VfxS16 error;

    for (index = 0; index < NVRAM_EF_CONV_CURRENCY_RATE_TOTAL; index++)
    {                    
        textInput = (VcpFormItemTextInput*)(m_currencyPageForm->getItem(index));
        str = textInput->getTextBox()->getText();
        val = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->wStringToDouble(str);
        rates[index].rate = val;
        WriteRecord(
            NVRAM_EF_CONV_CURRENCY_RATE_LID,
            (index + 1),
            (void*)&rates[index],
            NVRAM_EF_CONV_CURRENCY_RATE_SIZE,
            &error);
    }
    {
        U8 firstLaunch = 0; // set default value / read from NVRAM
        WriteValue(NVRAM_CONVERTER_FIRST_LAUNCH, &firstLaunch, DS_BYTE, &error);
    }
    ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setCurrencyRates(rates);
    VFX_FREE_MEM(rates);

    // here will update actionPage
    VcpForm *form;
    form = ((VappConverterScreen*)getMainScr())->m_page->getActionPageForm();
    ((VappConverterScreen*)getMainScr())->m_page->setTextChangedFlag(VFX_FALSE);
    textInput = (VcpFormItemTextInput*)(form->getItem(VappConverterActionPage::ID_CONVERTER_FORM_ITEM_UNIT1_TEXT));
    textInput->getTextBox()->setText((VfxWChar*)"0", VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
    ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setUpperValue(0);
    textInput = (VcpFormItemTextInput*)(form->getItem(VappConverterActionPage::ID_CONVERTER_FORM_ITEM_UNIT2_TEXT));
    textInput->getTextBox()->setText((VfxWChar*)"0", VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
    ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setLowerValue(0);
    ((VappConverterScreen*)getMainScr())->m_page->setTextChangedFlag(VFX_TRUE);
    getMainScr()->popPage();
}

void VappConverterCurrencyPage::onCurrencyFunctionBarTap(VfxObject *sender, VfxId id)
{
    switch (id)
    {
        case ID_CURRENCY_FUNCTIONBAR_SAVE:
            VcpFormItemTextInput* textInput;
            textInput = (VcpFormItemTextInput*)(m_currencyPageForm->getItem(m_currActiveIndex));
            textInput->getTextBox()->deactivate();
            onBarSaveCommond();
            break;
        default:
            break;
    }
}

void VappConverterCurrencyPage::onCurrencyToolBarTap(VfxObject * sender,VfxId id)
{
    switch(id)
    {
        case ID_CURRENCY_TOOLBAR_SAVE:
            onBarSaveCommond();
            break;
        case ID_CURRENCY_TOOLBAR_CANCEL:
            getMainScr()->popPage();
            break;
        default:
            break;
    }
}


/***************************************************************************** 
 * Class VappConverterActionPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappConverterActionPage", VappConverterActionPage, VfxPage);
void VappConverterActionPage::onInit()
{
    VfxPage::onInit();
    
    VFX_OBJ_CREATE(m_actionPageForm, VcpForm, this);

    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);    
    VfxWString str;
    str.loadFromRes(STR_ID_VAPP_CONVERTER);
    titleBar->setTitle(str);
    setTopBar(titleBar); 

    // create tool bar

    VfxU8 currType;
    currType = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getType();

    if (currType == VAPP_CONVERTER_TYPE_CURRENCY)
    {
        VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
        str.loadFromRes(STR_ID_VAPP_CONVERTER_SET_CURRECNY_RATES);
        m_toolBar->addItem(ID_CONVERTER_TOOLBAR_SET_CURRENCY, str, IMG_ID_VAPP_CONVERTER_SET_CURRENCY);       // add tool bar
        m_toolBar->m_signalButtonTap.connect(this, &VappConverterActionPage::onConverterToolBarTap);          // connect tool bar signal
        setBottomBar(m_toolBar); 
    }
    
    VFX_OBJ_CREATE(m_actionPageForm, VcpForm, this);
    m_actionPageForm->setSize(getSize());
    m_actionPageForm->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // type
    VcpFormItemBigButton *btn;
    VFX_OBJ_CREATE(btn, VcpFormItemBigButton, m_actionPageForm);
    str.loadFromRes(STR_ID_VAPP_CONVERTER_TYPE);
    btn->setButtonText(str);

    VfxResId resId = 0;
    VfxResId upperId = 0; //  for upper unit string
    VfxResId lowerId = 0; //  for lower unit string
    switch (currType)
    {        
        case VAPP_CONVERTER_TYPE_WEIGHT: 
            resId = STR_ID_VAPP_CONVERTER_WEIGHT;
            upperId = STR_ID_VAPP_CONVERTER_UNIT1;
            lowerId = STR_ID_VAPP_CONVERTER_UNIT2;
            break;
            
        case VAPP_CONVERTER_TYPE_LENGTH:
            resId = STR_ID_VAPP_CONVERTER_LENGTH;
            upperId = STR_ID_VAPP_CONVERTER_UNIT1;
            lowerId = STR_ID_VAPP_CONVERTER_UNIT2;
            break;
            
        case VAPP_CONVERTER_TYPE_CURRENCY:
            resId = STR_ID_VAPP_CONVERTER_CURRENCY;
            upperId = STR_ID_VAPP_CONVERTER_CURRENCY1;
            lowerId = STR_ID_VAPP_CONVERTER_CURRENCY2;
            break;
            
        default:
            break;
    }
    str.loadFromRes(resId);
    btn->setHintText(str);
    btn->getButton()->setId(ID_CONVERTER_FORM_ITEM_TYPE_BTN);
    btn->getButton()->m_signalClicked.connect(this, &VappConverterActionPage::onBtnClicked);
    m_actionPageForm->addItem(btn, ID_CONVERTER_FORM_ITEM_TYPE_BTN);

    // unit1 btn
    VFX_OBJ_CREATE(btn, VcpFormItemBigButton, m_actionPageForm);
    str.loadFromRes(upperId);
    btn->setButtonText(str);    
    // here use string id enum value.
    VfxU8 unit1;
    unit1 = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getUpperUnit();
    // get resId
    switch (currType)
    {
        case VAPP_CONVERTER_TYPE_WEIGHT:
            resId = STR_ID_VAPP_CONVERTER_KILOGRAM + unit1;
            break;
            
        case VAPP_CONVERTER_TYPE_LENGTH:
            resId = STR_ID_VAPP_CONVERTER_CENTERMETER + unit1;
            break;
            
        case VAPP_CONVERTER_TYPE_CURRENCY:
            vapp_conv_currency_rate_struct r;
            ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getCurrencyRate(unit1, &r);
            resId = r.str_id;
            break;
            
        default:
            break;
    }
    str.loadFromRes(resId);
    btn->setHintText(str);
    btn->getButton()->setId(ID_CONVERTER_FORM_ITEM_UNIT1_BTN);
    btn->getButton()->m_signalClicked.connect(this, &VappConverterActionPage::onBtnClicked);
    m_actionPageForm->addItem(btn, ID_CONVERTER_FORM_ITEM_UNIT1_BTN);

    // text1
    VcpFormItemTextInput *textInput;
    VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_actionPageForm);
    textInput->setLabelPosition(VCPFORM_NO_LABEL);
    textInput->getTextBox()->setIME(IMM_INPUT_TYPE_DECIMAL_NUMERIC);
    textInput->getTextBox()->setAlignMode(VCP_TEXT_ALIGN_MODE_RIGHT);
    textInput->getTextBox()->setDisableClipboard(VFX_TRUE);
    setTextChangedFlag(VFX_FALSE);
    textInput->getTextBox()->setText((VfxWChar*)"0", VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
    setTextChangedFlag(VFX_TRUE);
    textInput->getTextBox()->m_signalTextChanged.connect(this, &VappConverterActionPage::onTextChanged);
    textInput->getTextBox()->m_signalActivated.connect(this, &VappConverterActionPage::onTextActivated);
    textInput->getTextBox()->m_signalBeforeChange.connect(this, &VappConverterActionPage::onUpperTextInsert);
    textInput->getTextBox()->setId(ID_CONVERTER_FORM_ITEM_UNIT1_TEXT);
    //textInput->getTextBox()->setAutoDeactivated(VFX_TRUE);
    m_actionPageForm->addItem(textInput, ID_CONVERTER_FORM_ITEM_UNIT1_TEXT);

    // unit2 btn
    VFX_OBJ_CREATE(btn, VcpFormItemBigButton, m_actionPageForm);
    str.loadFromRes(lowerId);
    btn->setButtonText(str);    
    // here use string id enum value.
    VfxU8 unit2;
    unit2 = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getLowerUnit();
    // get resId
    switch (currType)
    {
        case VAPP_CONVERTER_TYPE_WEIGHT:
            resId = STR_ID_VAPP_CONVERTER_KILOGRAM + unit2;
            break;
            
        case VAPP_CONVERTER_TYPE_LENGTH:
            resId = STR_ID_VAPP_CONVERTER_CENTERMETER + unit2;
            break;
            
        case VAPP_CONVERTER_TYPE_CURRENCY:
            vapp_conv_currency_rate_struct r;
            ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getCurrencyRate(unit2, &r);
            resId = r.str_id;
            break;
            
        default:
            break;
    }
    str.loadFromRes(resId);
    btn->setHintText(str);
    btn->getButton()->setId(ID_CONVERTER_FORM_ITEM_UNIT2_BTN);
    btn->getButton()->m_signalClicked.connect(this, &VappConverterActionPage::onBtnClicked);
    m_actionPageForm->addItem(btn, ID_CONVERTER_FORM_ITEM_UNIT2_BTN);

    // text2
    VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_actionPageForm);
    textInput->setLabelPosition(VCPFORM_NO_LABEL);
    textInput->getTextBox()->setIME(IMM_INPUT_TYPE_DECIMAL_NUMERIC);
    textInput->getTextBox()->setAlignMode(VCP_TEXT_ALIGN_MODE_RIGHT);
    textInput->getTextBox()->setDisableClipboard(VFX_TRUE);
    setTextChangedFlag(VFX_FALSE);
    textInput->getTextBox()->setText((VfxWChar*)"0", VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
    setTextChangedFlag(VFX_TRUE);
    textInput->getTextBox()->m_signalTextChanged.connect(this, &VappConverterActionPage::onTextChanged);
    textInput->getTextBox()->m_signalActivated.connect(this, &VappConverterActionPage::onTextActivated);
    textInput->getTextBox()->m_signalBeforeChange.connect(this, &VappConverterActionPage::onLowerTextInsert);
    textInput->getTextBox()->setId(ID_CONVERTER_FORM_ITEM_UNIT2_TEXT);
    //textInput->getTextBox()->setAutoDeactivated(VFX_TRUE);
    m_actionPageForm->addItem(textInput, ID_CONVERTER_FORM_ITEM_UNIT2_TEXT);

	setUnitChangedFlag(VFX_FALSE);
}


void VappConverterActionPage::onBtnClicked(VfxObject *sender, VfxId id)
{
    // de-active editor
    VcpFormItemTextInput* textInput;
    VcpTextEditor *editor;
    textInput = (VcpFormItemTextInput*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT1_TEXT));
    editor = textInput->getTextBox();
    editor->deactivate();
    textInput = (VcpFormItemTextInput*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT2_TEXT));
    editor = textInput->getTextBox();
    editor->deactivate();
    // get type
    VfxU8 currType;
    currType = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getType();
    VfxWString str;
    VfxResId res_id = 0;
    VcpSelectPopup *selectPopup;
    if (ID_CONVERTER_FORM_ITEM_TYPE_BTN == id)
    {
        VfxId i;
        VFX_OBJ_CREATE(selectPopup, VcpSelectPopup, this);
        selectPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
        str.loadFromRes(STR_ID_VAPP_CONVERTER_SELECT_A_CONVERTER_TYPE);
        selectPopup->setText(str);
        selectPopup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

        for (i = 0; i < VAPP_CONVERTER_TYPE_TOTAL; i++)
        {
            switch (i)
            {                
                case VAPP_CONVERTER_TYPE_WEIGHT: 
                    res_id = STR_ID_VAPP_CONVERTER_WEIGHT;
                    break;
                    
                case VAPP_CONVERTER_TYPE_LENGTH:
                    res_id = STR_ID_VAPP_CONVERTER_LENGTH;
                    break;
                    
                case VAPP_CONVERTER_TYPE_CURRENCY:
                    res_id = STR_ID_VAPP_CONVERTER_CURRENCY;
                    break;
                    
                default:
                    break;
            }
            str.loadFromRes(res_id);
            if (i == currType)
            {
                selectPopup->addItem(i, str, VFX_TRUE);
            }
            else
            {
                selectPopup->addItem(i, str, VFX_FALSE);
            }
        }
        selectPopup->m_signalPopupState.connect(this, &VappConverterActionPage::onTypeListTap);
        selectPopup->show(VFX_FALSE);
    }
    else if ((id == ID_CONVERTER_FORM_ITEM_UNIT1_BTN) || (id == ID_CONVERTER_FORM_ITEM_UNIT2_BTN))
    {
        VfxId i;
        VFX_OBJ_CREATE(selectPopup, VcpSelectPopup, this);
        selectPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
        if (currType == VAPP_CONVERTER_TYPE_CURRENCY)
        {
            str.loadFromRes(STR_ID_VAPP_CONVERTER_SELECT_A_CURRENCY);
        }
        else
        {
            str.loadFromRes(STR_ID_VAPP_CONVERTER_SELECT_A_UNIT);
        }
        selectPopup->setText(str);
        selectPopup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

        // get optionmenu list highlight id
        VfxU8 unit1;
        VfxU8 unit2;
        unit1 = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getUpperUnit();
        unit2 = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getLowerUnit();
        VfxU8 currUnit;
        if (ID_CONVERTER_FORM_ITEM_UNIT1_BTN == id)
        {
            currUnit = unit1;
        }
        else
        {
            currUnit = unit2;
        }
        
        switch (currType)
        {
            case VAPP_CONVERTER_TYPE_WEIGHT:
                for (i = 0; i < VAPP_CONVERTER_WEIGHT_TOTAL; i++)
                {
                    str.loadFromRes(STR_ID_VAPP_CONVERTER_KILOGRAM + i);
                    if (i == currUnit)
                    {
                        selectPopup->addItem(i, str, VFX_TRUE);
                    }
                    else
                    {
                        selectPopup->addItem(i, str, VFX_FALSE);
                    }
                }
                break;
            case VAPP_CONVERTER_TYPE_LENGTH:
                for (i = 0; i < VAPP_CONVERTER_LENGTH_TOTAL; i++)
                {
                    str.loadFromRes(STR_ID_VAPP_CONVERTER_CENTERMETER + i);
                    if (i == currUnit)
                    {
                        selectPopup->addItem(i, str, VFX_TRUE);
                    }
                    else
                    {
                        selectPopup->addItem(i, str, VFX_FALSE);
                    }
                }
                break;
            case VAPP_CONVERTER_TYPE_CURRENCY:
                vapp_conv_currency_rate_struct rate;
                for (i = 0; i < NVRAM_EF_CONV_CURRENCY_RATE_TOTAL; i++)
                {
                    ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getCurrencyRate(i, &rate);
                    str.loadFromRes(rate.str_id);
                    if (i == currUnit)
                    {
                        selectPopup->addItem(i, str, VFX_TRUE);
                    }
                    else
                    {
                        selectPopup->addItem(i, str, VFX_FALSE);
                    }
                }
                break;
            default:
                break;
        }

        selectPopup->show(VFX_FALSE);
        if (ID_CONVERTER_FORM_ITEM_UNIT1_BTN == id)
        {
            selectPopup->m_signalPopupState.connect(this, &VappConverterActionPage::onUnit1ListTap);
        }
        else
        {
            selectPopup->m_signalPopupState.connect(this, &VappConverterActionPage::onUnit2ListTap);
        }
    }
}


void VappConverterActionPage::onTypeListTap(
    VfxBasePopup *sender,        // popup
    VfxBasePopupStateEnum state  // state
)
{
    if(state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {        
        VcpSelectPopup *senderPopup;
        senderPopup = (VcpSelectPopup*)sender;
        VfxId i;
        i = senderPopup->getFirstSeletedId();

        // last type
        VfxU8 type;
        type = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getType();

        // if not change type, skip
        if (i == type)
        {
            return;
        }
        VfxWString str;
        // if change type, set default btn and text editor
        if (i == VAPP_CONVERTER_TYPE_CURRENCY)
        {
            if (!m_toolBar)
            {
                VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
                str.loadFromRes(STR_ID_VAPP_CONVERTER_SET_CURRECNY_RATES);
                m_toolBar->addItem(ID_CONVERTER_TOOLBAR_SET_CURRENCY, str, IMG_ID_VAPP_CONVERTER_SET_CURRENCY);       // add tool bar
                m_toolBar->m_signalButtonTap.connect(this, &VappConverterActionPage::onConverterToolBarTap);          // connect tool bar signal
                setBottomBar(m_toolBar); 
            }
            else
            {
                toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_TRUE);
            }

        }
        else
        {
            toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_FALSE);
        }

        // update converter screen
        S16 error;
        
        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setType((VfxU8)i);
        WriteValue(NVRAM_CONVERTER_LAST_USE_TYPE, &i, DS_BYTE, &error);

        vapp_conv_type_pair_struct pair;
        ReadRecord(
            NVRAM_EF_CONV_TYPE_PAIR_LID,
            (U16)(i + 1),
             &pair,
            NVRAM_EF_CONV_TYPE_PAIR_SIZE,
            &error);

        VfxResId res = 0, res1 = 0, res2 = 0;
        VfxResId upperId = 0, lowerId = 0; // btn text
        switch (i)
        {                           
            case VAPP_CONVERTER_TYPE_WEIGHT:
                res = STR_ID_VAPP_CONVERTER_WEIGHT;
                res1 = STR_ID_VAPP_CONVERTER_KILOGRAM + pair.upper_id;
                res2 = STR_ID_VAPP_CONVERTER_KILOGRAM + pair.lower_id;
                upperId = STR_ID_VAPP_CONVERTER_UNIT1;
                lowerId = STR_ID_VAPP_CONVERTER_UNIT2;
                break;
            case VAPP_CONVERTER_TYPE_LENGTH:
                res = STR_ID_VAPP_CONVERTER_LENGTH;
                res1 = STR_ID_VAPP_CONVERTER_CENTERMETER + pair.upper_id;
                res2 = STR_ID_VAPP_CONVERTER_CENTERMETER + pair.lower_id;
                upperId = STR_ID_VAPP_CONVERTER_UNIT1;
                lowerId = STR_ID_VAPP_CONVERTER_UNIT2;
                break;
            case VAPP_CONVERTER_TYPE_CURRENCY:
                res = STR_ID_VAPP_CONVERTER_CURRENCY;
                // get rate string id and value
                vapp_conv_currency_rate_struct r;
                ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getCurrencyRate(pair.upper_id, &r);
                res1 = r.str_id;
                ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getCurrencyRate(pair.lower_id, &r);
                res2 = r.str_id;
                upperId = STR_ID_VAPP_CONVERTER_CURRENCY1;
                lowerId = STR_ID_VAPP_CONVERTER_CURRENCY2;
                break;
            default:
                break;
        }
        // type
        VcpFormItemBigButton* btn;
        btn = (VcpFormItemBigButton*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_TYPE_BTN));
        str.loadFromRes(res);
        btn->setHintText(str);
        // unit1
        btn = (VcpFormItemBigButton*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT1_BTN));
        str.loadFromRes(upperId);
        btn->setButtonText(str);
        str.loadFromRes(res1);
        btn->setHintText(str);
        // unit2
        btn = (VcpFormItemBigButton*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT2_BTN));
        str.loadFromRes(lowerId);
        btn->setButtonText(str);
        str.loadFromRes(res2);
        btn->setHintText(str);
            
        setTextChangedFlag(VFX_FALSE);
        VcpFormItemTextInput* textInput;
        textInput = (VcpFormItemTextInput*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT1_TEXT));
        textInput->getTextBox()->setText((VfxWChar*)"0", VAPP_CONVERTER_MAX_INPUT_BUF_LEN);

        textInput = (VcpFormItemTextInput*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT2_TEXT));
        textInput->getTextBox()->setText((VfxWChar*)"0", VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
        setTextChangedFlag(VFX_TRUE);
        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setUpperUnit((VfxU8)pair.upper_id);
        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setLowerUnit((VfxU8)pair.lower_id);

        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setUpperValue(0);
        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setLowerValue(0);
        
    }
}


void VappConverterActionPage::onUnit1ListTap(
    VfxBasePopup *sender,        // popup
    VfxBasePopupStateEnum state  // state
)
{
    // convert using currenct value
    if(state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {        
        VcpSelectPopup *senderPopup;
        senderPopup = (VcpSelectPopup*)sender;
        VfxId i;
        i = senderPopup->getFirstSeletedId();

        // last unit1
        VfxU8 unit1, unit2;
        unit1 = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getUpperUnit();
        unit2 = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getLowerUnit();

        VfxU8 currType;
        currType = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getType();

        if (unit1 == i)
        {
            return;
        }
        // check whether overflow
        double newVal;
        if (i != unit2) // the different units
        {
            double oldVal;
            oldVal = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getUpperValue();
            // get rate
            double rate = computeRate(currType, i, unit1);
            newVal = oldVal * rate;           
        }
        else // the same units
        {
            newVal = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getLowerValue();
        }
        
        if ((newVal + 0.5) >= VAPP_CONVERTER_MAX_VALUE)
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_GENERAL,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_INFO,
                (WCHAR*)GetString(STR_ID_VAPP_CONVERTER_ERROR_MAXIMUM_VALUE_EXCEEDED));
            return;
        }
        
        // update unit pair
        vapp_conv_type_pair_struct pair;
        S16 error;
        pair.upper_id = i;
        pair.lower_id = unit2;

        WriteRecord(
            NVRAM_EF_CONV_TYPE_PAIR_LID,
            (U16)(currType + 1),
             &pair,
            NVRAM_EF_CONV_TYPE_PAIR_SIZE,
            &error);
        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setUpperUnit((VfxU8)i);
        
        // update upper string and value
        // get res_id
        VfxResId res_id = 0;
        switch (currType)
        {
            case VAPP_CONVERTER_TYPE_WEIGHT:
                res_id = STR_ID_VAPP_CONVERTER_KILOGRAM + i;
                break;
                
            case VAPP_CONVERTER_TYPE_LENGTH:
                res_id = STR_ID_VAPP_CONVERTER_CENTERMETER + i;
                break;
                
            case VAPP_CONVERTER_TYPE_CURRENCY:
                vapp_conv_currency_rate_struct r;
                ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getCurrencyRate(i, &r);
                res_id = r.str_id;
                break;
                
            default:
                break;
        }
        VfxWString str;
        str.loadFromRes(res_id);
        VcpFormItemBigButton* btn;
        btn = (VcpFormItemBigButton*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT1_BTN));
        btn->setHintText(str);

        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setUpperValue(newVal);
        VfxWChar *string;
        VFX_ALLOC_MEM(string, sizeof(VfxWChar) * (VAPP_CONVERTER_MAX_INPUT_BUF_LEN + 1), this);
        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->doubleToWString(string, newVal, VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
        setTextChangedFlag(VFX_FALSE);        
        VcpFormItemTextInput* textInput;
        textInput = (VcpFormItemTextInput*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT1_TEXT));
        textInput->getTextBox()->setText(string, VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
        setTextChangedFlag(VFX_TRUE);
		    setUnitChangedFlag(VFX_TRUE);
        VFX_FREE_MEM(string);
    }
}


void VappConverterActionPage::onUnit2ListTap(
    VfxBasePopup *sender,        // popup
    VfxBasePopupStateEnum state  // state
)
{
    // convert using currenct value 
    if(state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {        
        VcpSelectPopup *senderPopup;
        senderPopup = (VcpSelectPopup*)sender;
        VfxId i;
        i = senderPopup->getFirstSeletedId();

        // last unit1
        VfxU8 unit1, unit2;
        unit1 = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getUpperUnit();
        unit2 = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getLowerUnit();

        VfxU8 currType;
        currType = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getType();

        if (unit2 == i)
        {
            return;
        }

        // check whether overflow
        double newVal;
        if (i != unit1) // the different units
        {
            double oldVal;
            oldVal = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getLowerValue();
            // get rate
            double rate = computeRate(currType, i, unit2);
            newVal = oldVal * rate;           
        }
        else // the same units
        {
            newVal = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getUpperValue();
        }
        if ((newVal + 0.5) >= VAPP_CONVERTER_MAX_VALUE)
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_GENERAL,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_INFO,
                (WCHAR*)GetString(STR_ID_VAPP_CONVERTER_ERROR_MAXIMUM_VALUE_EXCEEDED));
            return;
        }
        
        // update unit pair
        vapp_conv_type_pair_struct pair;
        S16 error;
        pair.upper_id = unit1;
        pair.lower_id = i;

        WriteRecord(
            NVRAM_EF_CONV_TYPE_PAIR_LID,
            (U16)(currType + 1),
             &pair,
            NVRAM_EF_CONV_TYPE_PAIR_SIZE,
            &error);
        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setLowerUnit((VfxU8)i);
        
        // update upper string and value
        // get res_id
        VfxResId res_id = 0;
        switch (currType)
        {
            case VAPP_CONVERTER_TYPE_WEIGHT:
                res_id = STR_ID_VAPP_CONVERTER_KILOGRAM + i;
                break;
                
            case VAPP_CONVERTER_TYPE_LENGTH:
                res_id = STR_ID_VAPP_CONVERTER_CENTERMETER + i;
                break;
                
            case VAPP_CONVERTER_TYPE_CURRENCY:
                vapp_conv_currency_rate_struct r;
                ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getCurrencyRate(i, &r);
                res_id = r.str_id;
                break;
                
            default:
                break;
        }
        VfxWString str;
        str.loadFromRes(res_id);
        VcpFormItemBigButton* btn;
        btn = (VcpFormItemBigButton*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT2_BTN));
        btn->setHintText(str);

        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setLowerValue(newVal);
        VfxWChar *string;
        VFX_ALLOC_MEM(string, sizeof(VfxWChar) * (VAPP_CONVERTER_MAX_INPUT_BUF_LEN + 1), this);
        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->doubleToWString(string, newVal, VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
        setTextChangedFlag(VFX_FALSE);
        VcpFormItemTextInput* textInput;
        textInput = (VcpFormItemTextInput*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT2_TEXT));
        textInput->getTextBox()->setText(string, VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
        setTextChangedFlag(VFX_TRUE);
		    setUnitChangedFlag(VFX_TRUE);
        VFX_FREE_MEM(string);
    }
}


void VappConverterActionPage::onConverterToolBarTap(VfxObject *sender, VfxId id)
{
    switch (id)
    {
        case ID_CONVERTER_TOOLBAR_SET_CURRENCY:
            VappConverterCurrencyPage *currencyPage;
            VFX_OBJ_CREATE(currencyPage, VappConverterCurrencyPage, getMainScr());
            getMainScr()->pushPage(0, currencyPage);
            break;
        default:
            break;
    }
}


double VappConverterActionPage::computeRate(VfxU8 currType, VfxU8 unit1, VfxU8 unit2)
{
    switch (currType)
    {
        case VAPP_CONVERTER_TYPE_WEIGHT:
            return (vappConverterWeightRates[unit1] / vappConverterWeightRates[unit2]);
            break;
            
        case VAPP_CONVERTER_TYPE_LENGTH:
            return (vappConverterLengthRates[unit1] / vappConverterLengthRates[unit2]);
            break;
            
        case VAPP_CONVERTER_TYPE_CURRENCY:
            vapp_conv_currency_rate_struct r1, r2;
            ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getCurrencyRate(unit1, &r1);
            ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getCurrencyRate(unit2, &r2);
            return (r1.rate / r2.rate);
            break;
            
        default:
            break;
    }
    return 1;
}


void VappConverterActionPage::onTextChanged(VcpTextEditor *sender)
{
    if (!getTextChangedFlag() || getUnitChangedFlag())
    {
        setUnitChangedFlag(VFX_FALSE);
        return;
    }
    VfxS32 i = sender->getId();    
    VfxWChar *str = sender->getText();
    double val;
    val = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->wStringToDouble(str);

    VfxU8 unit1, unit2;
    unit1 = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getUpperUnit();
    unit2 = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getLowerUnit();
    if (unit1 != unit2) // the same unit
    {
        VfxU8 currType;
        currType = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->getType();
        if (i == ID_CONVERTER_FORM_ITEM_UNIT1_TEXT)
        {
            // get_rate
            double rate = computeRate(currType, unit2, unit1);

            double lowerVal;
            lowerVal = val * rate;

            ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setUpperValue(val);
            ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setLowerValue(lowerVal);

            VfxWChar *str2;
            VFX_ALLOC_MEM(str2, sizeof(VfxWChar) * (VAPP_CONVERTER_MAX_INPUT_BUF_LEN + 1), this); // here 10 mean max buffer
            ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->doubleToWString(str2, lowerVal, VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
            setTextChangedFlag(VFX_FALSE);
            VcpFormItemTextInput* textInput;
            textInput = (VcpFormItemTextInput*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT2_TEXT));
            textInput->getTextBox()->changeText(str2, VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
            setTextChangedFlag(VFX_TRUE);
            VFX_FREE_MEM(str2);

        }
        else
        {
            // get_rate
            double rate = computeRate(currType, unit1, unit2);

            double upperVal;
            upperVal = val * rate;

            ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setUpperValue(upperVal);
            ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setLowerValue(val);

            VfxWChar *str2;
            VFX_ALLOC_MEM(str2, sizeof(VfxWChar) * (VAPP_CONVERTER_MAX_INPUT_BUF_LEN + 1), this); // here 10 mean max buffer
            ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->doubleToWString(str2, upperVal, VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
            setTextChangedFlag(VFX_FALSE);
            VcpFormItemTextInput* textInput;
            textInput = (VcpFormItemTextInput*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT1_TEXT));
            textInput->getTextBox()->changeText(str2, VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
            setTextChangedFlag(VFX_TRUE);
            VFX_FREE_MEM(str2);
        }
    }
    else
    {
        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setUpperValue(val);
        ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx->setLowerValue(val);
        setTextChangedFlag(VFX_FALSE);
        if (i == ID_CONVERTER_FORM_ITEM_UNIT1_TEXT)
        {
            VcpFormItemTextInput* textInput;
            textInput = (VcpFormItemTextInput*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT2_TEXT));
            textInput->getTextBox()->changeText(str, VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
        }
        else
        {
            VcpFormItemTextInput* textInput;
            textInput = (VcpFormItemTextInput*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT1_TEXT));
            textInput->getTextBox()->changeText(str, VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
        }
        setTextChangedFlag(VFX_TRUE);
    }
    
}


void VappConverterActionPage::onTextActivated(VcpTextEditor *sender, VfxBool activated)
{
    VfxWChar *str;
    str = sender->getText();
    VfxU32 len;
    len = mmi_wcslen((WCHAR*)str);
    if (activated)
    {
        sender->setHighlight(0, len);
    }
    else
    {
        sender->setHighlight(0, 0);
    }
    
    if (!activated && (len == 0))
    {
        setTextChangedFlag(VFX_FALSE);
        sender->setText((VfxWChar*)"0", VAPP_CONVERTER_MAX_INPUT_BUF_LEN);
        setTextChangedFlag(VFX_TRUE);
    }
}


void VappConverterActionPage::onUpperTextInsert(VfxWChar *str, VfxS32 pos, VcpTextChangeEnum type, VfxBool *changed)
{
    *changed = VFX_TRUE;
    switch (type)
    {
        case VCP_TEXT_CHANGE_INSERT_CHAR:
        {
            VFX_ASSERT(str != NULL);
            VcpTextEditor *sender;
            VcpFormItemTextInput* textInput;
            textInput = (VcpFormItemTextInput*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT1_TEXT));
            sender = textInput->getTextBox();
            VfxWChar *textBuf;
            textBuf = sender->getText();

            if (mmi_wcslen((WCHAR*)textBuf) == 0)
            {
                *changed = VFX_TRUE;
                return;
            }
            // dot won't make number bigger
            if (mmi_wcscmp((WCHAR*)str, (WCHAR*)L".") == 0) // .
            {
                if (mmi_wcsrchr(textBuf, L'.'))
                {
                    *changed = VFX_FALSE; // don't allow two point
                    return;
                }
                *changed = VFX_TRUE;
                return;
            }
            else if (mmi_wcscmp((WCHAR*)str, (WCHAR*)L"0") == 0) // 0
            {
                // the followting cases won't impact value, editor will skip it.
                if ((pos == 0 && mmi_wcsncmp((WCHAR*)textBuf, (WCHAR*)L".", 1) != 0) || 
                    (pos == 1 && mmi_wcsncmp((WCHAR*)textBuf, (WCHAR*)L"0", 1) == 0))
                {
                    *changed = VFX_FALSE;
                    return;
                }
            }
            
            // calc other text whether overflow   
            VfxS32 len;
            len = mmi_wcslen(textBuf);

            // max buffer reached, editor will skip it.
            if (len == VAPP_CONVERTER_MAX_INPUT_BUF_LEN)
            {
                *changed = VFX_TRUE;
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_GENERAL,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_INFO,
                    (WCHAR*)GetString(STR_ID_VAPP_CONVERTER_ERROR_MAXIMUM_VALUE_EXCEEDED));
                return;
            }

            VfxWChar *newBuf;
            VFX_ALLOC_MEM(newBuf, sizeof(VfxWChar) * (len + 1 + 1), this); // insert char + null end symbol
            newBuf = mmi_wcsncpy(newBuf, textBuf, pos);
            newBuf = mmi_wcscat(newBuf, str);
            newBuf = mmi_wcscat(newBuf, textBuf + pos);
            VappConverterContext *cntx;
            cntx = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx;
            double val, rate, lowerval;
            val = cntx->wStringToDouble(newBuf);
            VfxU8 unit1, unit2, currType;
            unit1 = cntx->getUpperUnit();
            unit2 = cntx->getLowerUnit();
            currType = cntx->getType();
            rate = computeRate(currType, unit2, unit1);
            lowerval = val * rate;
            VFX_FREE_MEM(newBuf);
            if ((lowerval + 0.5) >= VAPP_CONVERTER_MAX_VALUE)
            {
                *changed = VFX_FALSE;
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_GENERAL,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_INFO,
                    (WCHAR*)GetString(STR_ID_VAPP_CONVERTER_ERROR_MAXIMUM_VALUE_EXCEEDED));
                return;
            }
            if (mmi_wcscmp((WCHAR*)str, (WCHAR*)L".") != 0 ||
                mmi_wcscmp((WCHAR*)str, (WCHAR*)L"0") != 0)
            {
                if (pos == 1 && mmi_wcsncmp((WCHAR*)textBuf, (WCHAR*)L"0", 1) == 0)
                {
                    // first calculate, then delete
                    setTextChangedFlag(VFX_FALSE);
                    sender->deleteChars();
                    setTextChangedFlag(VFX_TRUE);
                    *changed = VFX_TRUE;
                    return;
                }
            }
            break;
        }
        case VCP_TEXT_CHANGE_DELETE_CHAR:
        {
            VcpTextEditor *sender;
            VcpFormItemTextInput* textInput;
            textInput = (VcpFormItemTextInput*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT1_TEXT));
            sender = textInput->getTextBox();
            VfxS32 start = 0, end = 0;
            sender->getHighlight(&start, &end);
            if (end > start) // editor is highlighted
            {
                *changed = VFX_TRUE;
                return;
            }

            VfxWChar *textBuf;
            textBuf = sender->getText();

            // just deal with one char '.' delete
            if ((pos >= 1) && mmi_wcsncmp((WCHAR*)&textBuf[pos - 1], (WCHAR*)L".", 1) == 0)
            {                
                
                VfxWChar tmpBuf[VAPP_CONVERTER_MAX_INPUT_BUF_LEN + 1];
                memset(tmpBuf, 0x00, sizeof(VfxWChar) * (VAPP_CONVERTER_MAX_INPUT_BUF_LEN + 1));
                mmi_wcsncpy((WCHAR*)tmpBuf, (WCHAR*)textBuf, (pos - 1));
                mmi_wcscat((WCHAR*)tmpBuf, (WCHAR*)&textBuf[pos]);

                VappConverterContext *cntx;
                cntx = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx;
                double val, rate, lowerval;
                val = cntx->wStringToDouble(tmpBuf);
                VfxU8 unit1, unit2, currType;
                unit1 = cntx->getUpperUnit();
                unit2 = cntx->getLowerUnit();
                currType = cntx->getType();
                rate = computeRate(currType, unit2, unit1);
                lowerval = val * rate;
                if ((lowerval + 0.5) >= VAPP_CONVERTER_MAX_VALUE)
                {
                    *changed = VFX_FALSE;
                    mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_GENERAL,
                        MMI_EVENT_INFO_BALLOON,
                        MMI_NMGR_BALLOON_TYPE_INFO,
                        (WCHAR*)GetString(STR_ID_VAPP_CONVERTER_ERROR_MAXIMUM_VALUE_EXCEEDED));
                    return;
                } 
            }

            break;
        }
        case VCP_TEXT_CHANGE_DELETE_ALL:
        case VCP_TEXT_CHANGE_INSERT_STR:
            break;
    }
}


void VappConverterActionPage::onLowerTextInsert(VfxWChar *str, VfxS32 pos, VcpTextChangeEnum type, VfxBool *changed)
{
    *changed = VFX_TRUE;
    switch (type)
    {
        case VCP_TEXT_CHANGE_INSERT_CHAR:
        {
            VFX_ASSERT(str != NULL);
            VcpTextEditor *sender;
            VcpFormItemTextInput* textInput;
            textInput = (VcpFormItemTextInput*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT2_TEXT));
            sender = textInput->getTextBox();
            VfxWChar *textBuf;
            textBuf = sender->getText();
            
            if (mmi_wcslen((WCHAR*)textBuf) == 0)
            {
                *changed = VFX_TRUE;
                return;
            }
            // dot won't make number bigger
            if (mmi_wcscmp((WCHAR*)str, (WCHAR*)L".") == 0) // .
            {
                if (mmi_wcsrchr(textBuf, L'.'))
                {
                    *changed = VFX_FALSE; // don't allow two point
                    return;
                }
                *changed = VFX_TRUE;
                return;
            }
            else if (mmi_wcscmp((WCHAR*)str, (WCHAR*)L"0") == 0) // 0
            {
                // the followting cases won't impact value, editor will skip it.
                if ((pos == 0 && mmi_wcsncmp((WCHAR*)textBuf, (WCHAR*)L".", 1) != 0) || 
                    (pos == 1 && mmi_wcsncmp((WCHAR*)textBuf, (WCHAR*)L"0", 1) == 0))
                {
                    *changed = VFX_FALSE;
                    return;
                }
            }

            // calc other text whether overflow   
            VfxS32 len;
            len = mmi_wcslen(textBuf);

            // max buffer reached, editor will skip it.
            if (len == VAPP_CONVERTER_MAX_INPUT_BUF_LEN)
            {
                *changed = VFX_TRUE;
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_GENERAL,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_INFO,
                    (WCHAR*)GetString(STR_ID_VAPP_CONVERTER_ERROR_MAXIMUM_VALUE_EXCEEDED));
                return;
            }

            VfxWChar *newBuf;
            VFX_ALLOC_MEM(newBuf, sizeof(VfxWChar) * (len + 1 + 1), this); // insert char + null end symbol
            newBuf = mmi_wcsncpy(newBuf, textBuf, pos);
            newBuf = mmi_wcscat(newBuf, str);
            newBuf = mmi_wcscat(newBuf, textBuf + pos);
            VappConverterContext *cntx;
            cntx = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx;
            double val, rate, upperval;
            val = cntx->wStringToDouble(newBuf);
            VfxU8 unit1, unit2, currType;
            unit1 = cntx->getUpperUnit();
            unit2 = cntx->getLowerUnit();
            currType = cntx->getType();
            rate = computeRate(currType, unit1, unit2);
            upperval = val * rate;
            VFX_FREE_MEM(newBuf);
            if ((upperval + 0.5) >= VAPP_CONVERTER_MAX_VALUE)
            {
                *changed = VFX_FALSE;
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_GENERAL,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_INFO,
                    (WCHAR*)GetString(STR_ID_VAPP_CONVERTER_ERROR_MAXIMUM_VALUE_EXCEEDED));
                return;
            }
            if (mmi_wcscmp((WCHAR*)str, (WCHAR*)L".") != 0 ||
                mmi_wcscmp((WCHAR*)str, (WCHAR*)L"0") != 0)
            {
                if (pos == 1 && mmi_wcsncmp((WCHAR*)textBuf, (WCHAR*)L"0", 1) == 0)
                {
                    // first calculate, then delete
                    setTextChangedFlag(VFX_FALSE);
                    sender->deleteChars();
                    setTextChangedFlag(VFX_TRUE);
                    *changed = VFX_TRUE;
                    return;
                }
            }
            break;
        }
        case VCP_TEXT_CHANGE_DELETE_CHAR:
        {
            VcpTextEditor *sender;
            VcpFormItemTextInput* textInput;
            textInput = (VcpFormItemTextInput*)(m_actionPageForm->getItem(ID_CONVERTER_FORM_ITEM_UNIT2_TEXT));
            sender = textInput->getTextBox();
            VfxS32 start = 0, end = 0;
            sender->getHighlight(&start, &end);
            if (end > start) // editor is highlighted
            {
                *changed = VFX_TRUE;
                return;
            }

            VfxWChar *textBuf;
            textBuf = sender->getText();

            // just deal with one char '.' delete
            if ((pos >= 1) && mmi_wcsncmp((WCHAR*)&textBuf[pos - 1], (WCHAR*)L".", 1) == 0)
            {                
                
                VfxWChar tmpBuf[VAPP_CONVERTER_MAX_INPUT_BUF_LEN + 1];
                memset(tmpBuf, 0x00, sizeof(VfxWChar) * (VAPP_CONVERTER_MAX_INPUT_BUF_LEN + 1));
                mmi_wcsncpy((WCHAR*)tmpBuf, (WCHAR*)textBuf, (pos - 1));
                mmi_wcscat((WCHAR*)tmpBuf, (WCHAR*)&textBuf[pos]);

                VappConverterContext *cntx;
                cntx = ((VappConverterApp*)(getMainScr()->getApp()))->m_cntx;
                double val, rate, upperval;
                val = cntx->wStringToDouble(tmpBuf);
                VfxU8 unit1, unit2, currType;
                unit1 = cntx->getUpperUnit();
                unit2 = cntx->getLowerUnit();
                currType = cntx->getType();
                rate = computeRate(currType, unit1, unit2);
                upperval = val * rate;

                if ((upperval + 0.5) >= VAPP_CONVERTER_MAX_VALUE)
                {
                    *changed = VFX_FALSE;
                    mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_GENERAL,
                        MMI_EVENT_INFO_BALLOON,
                        MMI_NMGR_BALLOON_TYPE_INFO,
                        (WCHAR*)GetString(STR_ID_VAPP_CONVERTER_ERROR_MAXIMUM_VALUE_EXCEEDED));
                    return;
                } 
            }

            break;
        }
        case VCP_TEXT_CHANGE_DELETE_ALL:
        case VCP_TEXT_CHANGE_INSERT_STR:
            break;
    }
}


void VappConverterActionPage::onDeinit()
{    
    VfxPage::onDeinit();
}


/***************************************************************************** 
 * Class VappConverterScreen
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappConverterScreen", VappConverterScreen, VfxMainScr);
void VappConverterScreen::onInit()
{
    VfxMainScr::onInit();
}


void VappConverterScreen::onDeinit()
{
    VfxMainScr::onDeinit();
}


void VappConverterScreen::on1stReady()
{
    VfxMainScr::on1stReady();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("C03", SA_start);
#endif
    VFX_OBJ_CREATE(m_page, VappConverterActionPage, this);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("C03", SA_stop);
#endif
    pushPage(0, m_page);
}


/***************************************************************************** 
 * Class VappConverterApp
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappConverterApp", VappConverterApp, VfxApp);

void VappConverterApp::onInit()
{
    VFX_TRACE(("VappConverterApp::onInit"));
    
    VfxApp::onInit();
}


void VappConverterApp::onDeinit()
{
    VFX_TRACE(("VappConverterApp::onDeinit"));
    
    VfxApp::onDeinit();
}


void VappConverterApp::onRun(void* args, VfxU32 argSize)
{
    VFX_TRACE(("VappConverterApp::onRun"));
    VfxApp::onRun(args, argSize);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("C01", SA_start);
#endif
    VFX_OBJ_CREATE(m_cntx, VappConverterContext, this);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("C01", SA_stop);
#endif
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("C02", SA_start);
#endif
    VFX_OBJ_CREATE(m_mainScr, VappConverterScreen, this);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("C02", SA_stop);
#endif
    m_mainScr->show();
}

extern "C"
{
MMI_ID vappConverterLaunch(void* param, U32 param_size)
{
    return VfxAppLauncher::launch(
                VAPP_CONVERTER, 
                VFX_OBJ_CLASS_INFO(VappConverterApp), 
                GRP_ID_ROOT, 
                NULL, 
                0);
}
}

#endif /* __MMI_CONVERTER__ */
extern "C"
{
#include "AppMgrSrvGprot.h"
}

VtstTestResultEnum vapp_conv_launch(VfxU32 param)
{
#ifdef __MMI_CONVERTER__
    srv_appmgr_launch("native.mtk.app_converter");
    MMI_ASSERT(MMI_TRUE == srv_appmgr_is_app_package_running("native.mtk.app_converter"));
#endif
    return VTST_TR_OK;
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
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __CCA_SUPPORT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

