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
 *  vapp_gpio_setting.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_GPIO_SETTING_H__
#define __VAPP_GPIO_SETTING_H__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_form.h"
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#include "MMIDataType.h"
#include "mmi_features.h"
#include "MMI_common_app_trc.h"
 
}
#endif


 /***************************************************************************** 
 * Define
 *****************************************************************************/
#define VGPIO_TRC_INFO                 MMI_COMMON_TRC_G8_DEV

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" void vapp_gpio_setting_launch(VfxMainScr * scr);


/***************************************************************************** 
* Class 
*****************************************************************************/
class VappGPIOSettingPopup : public VfxObject
{


public:
    
    VappGPIOSettingPopup(){};

public:
    
    virtual void onInit();

private:
    
    void onSliderChange(VcpSlider * obj, VfxFloat newlevel);

    void onKeyPenInput(VfxObject* sender, VfxId id);
};


class VappGPIOSettingPage : public VfxPage
{

public:
    
    VappGPIOSettingPage(){};

public:
    
    virtual void onInit();
    
    void onSliderChange(VcpSlider * obj, VfxFloat newlevel);

    enum
    {
        CELL_WIDTH = LCD_WIDTH,
        CELL_HEIGHT = VCPFRM_STD_CELL_HEIGHT,

        MIN_IMG_LEFT_TAP = 10,
        MAX_IMG_RIGHT_TAP = 10,
        IMG_WIDTH = 24,
        IMG_SLIDER_GAP = 18,

        SLIDER_LEN = CELL_WIDTH - MIN_IMG_LEFT_TAP - 2*IMG_WIDTH - 2*IMG_SLIDER_GAP - MAX_IMG_RIGHT_TAP,
    };

private:

    VcpForm *m_form;
    VcpSlider *m_slider;
};


/***************************************************************************** 
 * VappBrightnessCell 
 *****************************************************************************/
class VappBrightnessCell : public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappBrightnessCell);

// Constructor
public:
    VappBrightnessCell();

// Override
protected:
    virtual void onInit();

// Methods
private:
    void onTap(VcpFormItemCell* sender, VfxId senderId);
};

#ifdef __MMI_CABC__

/***************************************************************************** 
 * VappGpioCABCCell
 *****************************************************************************/
class VappGpioCABCCell : public VcpFormItemSwitchCell
{
    VFX_DECLARE_CLASS(VappGpioCABCCell);
    // Overrides
public:
    virtual void onInit();
    
    // Methods
public:
    void onSwitch(VcpFormItemSwitchCell* sender, VfxId senderid, VfxBool status);
};

#endif /* __MMI_CABC__ */

/*****************************************************************************
 * Class VcpSliderPopup
 *****************************************************************************/
//////////////////////////////// VcpSliderPopup
#if defined(__MMI_MAINLCD_480X800__)
    #define VCP_SLIDER_POPUP_WIDTH                   (446)    
    #define VCP_SLIDER_POPUP_LEFT_MARGIN             (21)
    #define VCP_SLIDER_POPUP_RIGHT_MARGIN            (21) 
    
    #define VCP_SLIDER_POPUP_TITLE_X                  0
    #define VCP_SLIDER_POPUP_TITLE_Y                  0
    #define VCP_SLIDER_POPUP_TITLE_HEIGHT             45
    #define VCP_SLIDER_POPUP_TITLE_FONT_SIZE          24

    #define VCP_SLIDER_POPUP_IMG_WIDTH               52    
    #define VCP_SLIDER_POPUP_IMG_Y                   72
    #define VCP_SLIDER_POPUP_IMG_SLIDER_GAP          14

    #define VCP_SLIDER_POPUP_BUTTON_HEIGHT           (70)
    #define VCP_SLIDER_POPUP_BUTTON_BOTTOM_GAP       (24)
    #define VCP_SLIDER_POPUP_BTN_FONT_SIZE           (30)
#elif defined(__MMI_MAINLCD_320X480__)
    #define VCP_SLIDER_POPUP_WIDTH                   (290)
    #define VCP_SLIDER_POPUP_LEFT_MARGIN             (11)
    #define VCP_SLIDER_POPUP_RIGHT_MARGIN            (11)
   
    #define VCP_SLIDER_POPUP_TITLE_X                  0
    #define VCP_SLIDER_POPUP_TITLE_Y                  0
    #define VCP_SLIDER_POPUP_TITLE_HEIGHT             25
    #define VCP_SLIDER_POPUP_TITLE_FONT_SIZE          15

    #define VCP_SLIDER_POPUP_IMG_WIDTH               34
    #define VCP_SLIDER_POPUP_IMG_Y                   47
    #define VCP_SLIDER_POPUP_IMG_SLIDER_GAP          8

    #define VCP_SLIDER_POPUP_BUTTON_HEIGHT           (45)
    #define VCP_SLIDER_POPUP_BUTTON_BOTTOM_GAP       (16)
    #define VCP_SLIDER_POPUP_BTN_FONT_SIZE           (18)
#else  // defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    #define VCP_SLIDER_POPUP_WIDTH                   (222)
    #define VCP_SLIDER_POPUP_LEFT_MARGIN             (8)
    #define VCP_SLIDER_POPUP_RIGHT_MARGIN            (8)
    
    #define VCP_SLIDER_POPUP_TITLE_X                  0
    #define VCP_SLIDER_POPUP_TITLE_Y                  0
    #define VCP_SLIDER_POPUP_TITLE_HEIGHT             20
    #define VCP_SLIDER_POPUP_TITLE_FONT_SIZE          13

    #define VCP_SLIDER_POPUP_IMG_WIDTH               26
    #define VCP_SLIDER_POPUP_IMG_Y                   34
    #define VCP_SLIDER_POPUP_IMG_SLIDER_GAP          5

    #define VCP_SLIDER_POPUP_BUTTON_HEIGHT           (40)
    #define VCP_SLIDER_POPUP_BUTTON_BOTTOM_GAP       (8)
    #define VCP_SLIDER_POPUP_BTN_FONT_SIZE           (16)
#endif 

#define VCP_SLIDER_POPUP_SLIER_LEN               (VCP_SLIDER_POPUP_WIDTH -          \
                                                  VCP_SLIDER_POPUP_LEFT_MARGIN -    \
                                                  VCP_SLIDER_POPUP_RIGHT_MARGIN -   \
                                                  VCP_SLIDER_POPUP_IMG_WIDTH -      \
                                                  VCP_SLIDER_POPUP_IMG_SLIDER_GAP)
                                                  
#define VCP_SLIDER_POPUP_BUTTON_WIDTH            (VCP_SLIDER_POPUP_WIDTH -          \
                                                  VCP_SLIDER_POPUP_LEFT_MARGIN -    \
                                                  VCP_SLIDER_POPUP_RIGHT_MARGIN)

#define VCP_SLIDER_POPUP_CNTX_Y                  (VCP_SLIDER_POPUP_IMG_Y +  VCP_SLIDER_POPUP_IMG_WIDTH / 2)// include Brightness icon and slider
#define VCP_SLIDER_POPUP_BUTTON_Y                (2 * VCP_SLIDER_POPUP_CNTX_Y - VCP_SLIDER_POPUP_TITLE_HEIGHT)
#define VCP_SLIDER_POPUP_HEIGHT                  (VCP_SLIDER_POPUP_BUTTON_Y + \
                                                  VCP_SLIDER_POPUP_BUTTON_HEIGHT + \
                                                  VCP_SLIDER_POPUP_BUTTON_BOTTOM_GAP) 


enum VcpSliderPopupButtonEnum
{
     VCP_SLIDER_POPUP_BTN_OK,
     VCP_SLIDER_POPUP_BTN_CANCEL,
     VCP_SLIDER_POPUP_BTN_TOTAL
};


class VcpSliderPopup : public VfxBasePopup
{
// Constructor / Destructor
public:

    VcpSliderPopup(); 

// Method
public:

    // Show the popup
    void show(
        VfxBool isAnim      // [IN] show animation or not
    );
    
    // set hint text
    void setTitle(
        const VfxWString &title                  // [IN] title text
        );

// Signal
public:
    // This singal is used to notify the popup is closed by Back key
    VfxSignal1 <
        VcpSliderPopup*          // popup
    > m_signalPopupClosed;

// override
protected:
    virtual void onInit();
    virtual void onLeaveStack();

    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );

    virtual void onUpdate();

    virtual VfxBool onKeyInput(VfxKeyEvent & event);

// implenmention
private:
    void onButtonClick(VfxObject* sender, VfxId id);


// Signal
public:
    // This singal is invoked when Ok/Cancel button on VK is clicked
    // void YourClass::onButtonClicked(VfxObject* sender, VfxId id)
    VfxSignal2 <
        VfxObject*,     // sender 
        VfxId           // id
    > m_signalButtonClicked;
// Variable
protected:
    VfxFrame                        *m_background;
    VfxFrame                        *m_titleBg;
    VfxWString                      m_title;
    VfxTextFrame                    *m_titleFrame;
    VcpButton                       *m_okButton;
public:    
    VcpSlider              *m_slider;
};

#endif /* __VAPP_GPIO_SETTING_H__ */
