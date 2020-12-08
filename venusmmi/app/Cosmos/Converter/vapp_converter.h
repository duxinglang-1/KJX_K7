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
 *  vapp_converter.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file define the class of converter
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CONVERTER_H__
#define __VAPP_CONVERTER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

extern "C"
{
#include "mmi_features.h"
}

#ifdef __MMI_CONVERTER__
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_tabctrl_page.h"
#include "vcp_form.h"
#include "vcp_textview.h"

extern "C"
{
#include "common_nvram_editor_data_item.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_CONVERTER_MAX_VALUE            (1000000000000000)
#define VAPP_CONVERTER_MAX_INPUT_BUF_LEN       (15)
#define VAPP_CONVERTER_MAX_RATE_BUF_LEN         (5)
#define VAPP_CONVERTER_CURRENCY_RATE_TOTAL  (NVRAM_EF_CONV_CURRENCY_RATE_TOTAL)
#define VAPP_CONVERTER_CURRENCY_RATE_SIZE   (NVRAM_EF_CONV_CURRENCY_RATE_SIZE)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// converter type, such as weight, length, currency
enum VappConverterTypeEnum
{
    VAPP_CONVERTER_TYPE_WEIGHT,
    VAPP_CONVERTER_TYPE_LENGTH,
    VAPP_CONVERTER_TYPE_CURRENCY,
    VAPP_CONVERTER_TYPE_TOTAL
};

// weight units
enum VappConverterWeightEnum
{
    VAPP_CONVERTER_WEIGHT_KG,
    VAPP_CONVERTER_WEIGHT_POUND,
    VAPP_CONVERTER_WEIGHT_OUNCE,
    VAPP_CONVERTER_WEIGHT_TOTAL
};

// length units
enum VappConverterLengthEnum
{
    VAPP_CONVERTER_LENGTH_CM,
    VAPP_CONVERTER_LENGTH_METER,
    VAPP_CONVERTER_LENGTH_KM,
    VAPP_CONVERTER_LENGTH_INCH,
    VAPP_CONVERTER_LENGTH_YARD,
    VAPP_CONVERTER_LENGTH_FOOT,
    VAPP_CONVERTER_LENGTH_MILE,
    VAPP_CONVERTER_LENGTH_TOTAL
};


/***************************************************************************** 
 * Class VappConverterContext
 *****************************************************************************/

/*
 * DESCRIPTION
 *  converter data and basic method.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappConverterContext : public VfxObject
{
    VFX_DECLARE_CLASS(VappConverterContext);

// Construtor / Destructor
public:
    VappConverterContext() {};
    ~VappConverterContext() {};
//
protected:

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
//method
public:
    // converter wide string to double
    // RETURNS : return double value not check validation.
    double wStringToDouble(
        VfxWChar *s // [IN] wide string
    );

    // converter double to wide string 
    // RETURNS : return wide string not check validation.
    void doubleToWString(
        VfxWChar *s,        // [OUT] wide string 
        double number,      // [IN]double value
        VfxS16 max_digits   // [IN] buffer length for wide string
    );

    //remove zero from tail of string 
    void removeZeroInTail(
        VfxWChar *buffer // [IN] wide string
    );
    
    //set and get method for private member
    void setType(VfxU8 t) {m_type = t;}
    void setUpperUnit(VfxU8 upperUnit) {m_upperUnit = upperUnit;}
    void setLowerUnit(VfxU8 lowerUnit) {m_lowerUnit = lowerUnit;}
    void setUpperValue(double upperVal) {m_upperVal = upperVal;}
    void setLowerValue(double lowerVal) {m_lowerVal = lowerVal;}
    
    VfxU8 getType() {return m_type;}            
    VfxU8 getUpperUnit() {return m_upperUnit;}        
    VfxU8 getLowerUnit() {return m_lowerUnit;}            
    double getUpperValue() {return m_upperVal;}            
    double getLowerValue() {return m_lowerVal;}

    void setCurrencyRates(const vapp_conv_currency_rate_struct *rates); // data from nvram or temp load.
    void getCurrencyRates(vapp_conv_currency_rate_struct *rates); //
    void getCurrencyRate(VfxId index, vapp_conv_currency_rate_struct *r); // get index related string id and rate.

//    void setUpperValidFlag(VfxBool flag) {m_upperValidFlag = flag;}
    
//    VfxBool getUpperValidFlag() { return m_upperValidFlag;}
    
//    void setLowerValidFlag(VfxBool flag) {m_lowerValidFlag = flag;}
    
//    VfxBool getLowerValidFlag() {return m_lowerValidFlag;}
//
private:
    VfxU8 m_type;   // current converter type //converter type,define a enum and need nvram
    VfxU8 m_upperUnit;  // unit for some type in upper field //need a nvram struct
    VfxU8 m_lowerUnit;  // unit for some type in lower field
    double m_upperVal;  // upper field value
    double m_lowerVal;  // lower field value
    vapp_conv_currency_rate_struct m_currencyRates[NVRAM_EF_CONV_CURRENCY_RATE_TOTAL];
//    VfxBool m_upperValidFlag; // Error indication for upper value
//    VfxBool m_lowerValidFlag; // Error indication for lower value
};


/***************************************************************************** 
 * Class VappConverterCurrencyPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  This page is used to input rate for currency converter.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappConverterCurrencyPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappConverterCurrencyPage);
    enum
    {
        ID_CURRENCY_TOOLBAR_SAVE = 1,
        ID_CURRENCY_TOOLBAR_CANCEL,
        ID_CURRENCY_TOOLBAR_TOTAL
    };

    enum
    {
        ID_CURRENCY_FUNCTIONBAR_SAVE = 1
    } ;
//constructor / Destructor
public:
    VappConverterCurrencyPage() : 
        m_toolBar(NULL), 
        m_currencyPageForm(NULL), 
        m_emptyFlag(0), 
        m_zeroFlag(0),
        m_currActiveIndex(0) 
    {
    };
    ~VappConverterCurrencyPage() {};
//override
public:
    virtual void onInit();
    virtual void onDeinit();

//method:
public:
    // get / set method
    void setEmptyFlag(U32 value) {m_emptyFlag = value;}
    U32 getEmptyFlag() {return m_emptyFlag;}
    
    void setZeroFlag(U32 value) {m_zeroFlag = value;}
    U32 getZeroFlag() {return m_zeroFlag;}
    void onBarSaveCommond();
    
protected:
    // connect signal function when tap toolbar in currency page
    void onCurrencyToolBarTap(
        VfxObject *sender,  // [IN] sender object
        VfxId id            // [IN] Toolbar id
    );

    void onCurrencyFunctionBarTap(
        VfxObject *sender,  // [IN] sender object
        VfxId id            // [IN] Toolbar id
    );

    // connect signal function when text changed
    void onTextChanged(
        VcpTextEditor *sender   // [IN] send object
    );

    void onTextActivated(
        VcpTextEditor *sender, 
        VfxBool activated
    );

    void onTextInsert(
        VfxWChar *str,  // [IN] current text string buf
        VfxS32 pos,     // [IN] will be inserted char
        VcpTextChangeEnum type,
        VfxBool *changed // [OUT] flad indicate to insert or not
    ) ;
private:
    // toolBar
    VcpToolBar *m_toolBar;
    // form to display currency rate
    VcpForm *m_currencyPageForm; 
    
    // flag for text editor empty status, 0 indicate all aren't empty
    VfxU32  m_emptyFlag;

    // flag for text editor value(0) status, 0 indicate all aren't zero.
    VfxU32  m_zeroFlag;

    VfxU32 m_currActiveIndex;
};


/***************************************************************************** 
 * Class VappConverterActionPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  Main screen Page used to convert.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappConverterActionPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappConverterActionPage);
public:
    enum
    {
        ID_CONVERTER_FORM_ITEM_TYPE_BTN = 0,
        ID_CONVERTER_FORM_ITEM_UNIT1_BTN,
        ID_CONVERTER_FORM_ITEM_UNIT1_TEXT,
        ID_CONVERTER_FORM_ITEM_UNIT2_BTN,
        ID_CONVERTER_FORM_ITEM_UNIT2_TEXT,
        ID_CONVERTER_FORM_ITEM_ITEM_TOTAL
    };

    enum
    {
        ID_CONVERTER_TOOLBAR_SET_CURRENCY = 0,
        ID_CONVERTER_TOOLBAR_TOTAL
    };
//constructor / Destructor
public:
    VappConverterActionPage() : m_actionPageForm(NULL), m_toolBar(NULL), m_textChangedFlag(VFX_TRUE) {};
    ~VappConverterActionPage() {};

//override
public:
    virtual void onInit();
    virtual void onDeinit();

// method
public:
    // this function is used to compute rate between two units
    //RETURNS: return rate
    double computeRate(
        VfxU8 currType, // [IN] type
        VfxU8 unit1,    // [IN] unit1
        VfxU8 unit2     // [IN] unit2
    );
    
    VcpForm* getActionPageForm() {return m_actionPageForm;}

    VfxBool getTextChangedFlag() {return m_textChangedFlag;}

    void setTextChangedFlag(VfxBool flag) {m_textChangedFlag = flag;}
    
    void setUnitChangedFlag(VfxBool flag) {m_unitFlag = flag;}
    
    VfxBool getUnitChangedFlag() {return m_unitFlag;}
    
// connect signal function
protected:
    // connect signal function when click btn in converter page
    void onBtnClicked(
        VfxObject *sender,  // [IN] sender object
        VfxId id            // [IN] btn id
    );

    // connect signal function when tap toolbar in converter page
    void onConverterToolBarTap(
        VfxObject *sender,  // [IN] sender object
        VfxId id            // [IN] Toolbar id
    );

    // connect signal function when tap type option list 
    void onTypeListTap(
        VfxBasePopup *sender,        // popup
        VfxBasePopupStateEnum state  // state
    ) ;

    // connect signal function when tap type option list 
    void onUnit1ListTap(
        VfxBasePopup *sender,        // popup
        VfxBasePopupStateEnum state  // state
    ) ;

    // connect signal function when tap type option list 
    void onUnit2ListTap(
        VfxBasePopup *sender,        // popup
        VfxBasePopupStateEnum state  // state
    ) ;

    // connect signal function when text changed, using to convert
    void onTextChanged(
        VcpTextEditor *sender   // [IN] send object
    );

    // connect signal function when text actived, using to process error output "E"
    void onTextActivated(
        VcpTextEditor *sender,  // [IN] send object
        VfxBool  activated      // [IN] activate flag
    );

    // connect signal function to control upper input
    void onUpperTextInsert(
        VfxWChar *str,  // [IN] current text string buf
        VfxS32 pos,     // [IN] will be inserted char
        VcpTextChangeEnum type,
        VfxBool *changed // [OUT] flad indicate to insert or not
    );

    // connect signal function to control lower input
    void onLowerTextInsert(
        VfxWChar *str,  // [IN] current text string buf
        VfxS32 pos,     // [IN] will be inserted char
        VcpTextChangeEnum type,
        VfxBool *changed // [OUT] flad indicate to insert or not
    );

private:
    VcpForm         *m_actionPageForm;
    VcpToolBar      *m_toolBar;
    VfxBool         m_textChangedFlag; //use this flag to prevent process textchange singal
    VfxBool         m_unitFlag;
};


/***************************************************************************** 
 * Class VappConverterScreen
 *****************************************************************************/

/*
 * DESCRIPTION
 *  Main screen Class.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappConverterScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappConverterScreen);

// Construtor / Destructor
public:
    VappConverterScreen() : m_page(NULL) {};
    ~VappConverterScreen() {};
//
protected:

// Override
public:
    virtual void on1stReady();
    virtual void onInit();
    virtual void onDeinit();

public:
    // first page of main screen
    VappConverterActionPage *m_page;
};


/***************************************************************************** 
 * Class VappConverterApp
 *****************************************************************************/

/*
 * DESCRIPTION
 *  App Class.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappConverterApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappConverterApp);
// Construtor / Destructor
public:
    VappConverterApp() : m_mainScr(NULL), m_cntx(NULL) {};
    ~VappConverterApp() {};

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onInit();
    virtual void onDeinit();

//variable
public:
    //main screen instance
    VappConverterScreen     *m_mainScr;     

    // g_cntx for converter when launch converter app.
    VappConverterContext *m_cntx; // This cntx can get by getApp()
};

#endif /* __MMI_CONVERTER__ */
#endif
