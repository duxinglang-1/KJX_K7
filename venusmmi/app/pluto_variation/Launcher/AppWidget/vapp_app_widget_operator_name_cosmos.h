/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_app_widget_operator_name_cosmos.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the cosmos style operator name widget.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_APP_WIDGET_OPERATOR_NAME_COSMOS_H
#define VAPP_APP_WIDGET_OPERATOR_NAME_COSMOS_H

#include "MMI_features.h"

#include "vapp_app_widget_def.h"

#if defined(__MMI_VUI_LAUNCHER__) && defined(VAPP_APP_WIDGET_OPERATOR_NAME)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMIDataType.h"
#include "vfx_datatype.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vfx_uc_include.h"

#include "vapp_app_widget.h"


#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
/***************************************************************************** 
 * Class VappAppWidgetSIMNameElementCosmos
 *****************************************************************************/

class VappAppWidgetSIMNameElementCosmos : public VfxFrame
{
// Enum
private:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        SIM_NAME_FONT_SIZE = 14
    #else
        SIM_NAME_FONT_SIZE = 12
    #endif
    };

    // Constructor / Destructor
public:
    // Default constructor
    VappAppWidgetSIMNameElementCosmos(VfxS32 simId);   

// Override
protected:
    virtual void onInit();

// Method
public:
    void layout();

// Variable
private:
    VfxS32 m_simId;
    VfxTextFrame    *m_leftParenthesis;
    VfxTextFrame    *m_textSIMName;
    VfxTextFrame    *m_rightParenthesis;
    VfxSize         m_size;
};
#endif


/***************************************************************************** 
 * Class VappAppWidgetOperatorElementCosmos
 *****************************************************************************/

class VappAppWidgetOperatorElementCosmos : public VfxFrame
{
// Enum
private:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        OPERATOR_NAME_FONT_SIZE = 14,
        SERVICE_NAME_FONT_SIZE = 12,
        ELEMENT_HEIGHT = 38,
        SIM_ICON_OFFSET_X = 18,
        SIM_ICON_OFFSET_Y = 8,
        OPN_OFFSET_X = 14,
        OPN_OFFSET_Y = 7,
        SPN_OFFSET_X = 14,
        SPN_OFFSET_Y = 6,
        WHITE_GAP_OFFSET_X = 18,
    #else
        OPERATOR_NAME_FONT_SIZE = 12,
        SERVICE_NAME_FONT_SIZE = 10,
        ELEMENT_HEIGHT = 33,
        SIM_ICON_OFFSET_X = 15,
        SIM_ICON_OFFSET_Y = 8,
        OPN_OFFSET_X = 9,
        OPN_OFFSET_Y = 6,
        SPN_OFFSET_X = 9,
        SPN_OFFSET_Y = 5,
        WHITE_GAP_OFFSET_X = 15,
    #endif
        SEPERATE_LINE_OFFSET = 4
    };

// Constructor / Destructor
public:
    // Default constructor
    VappAppWidgetOperatorElementCosmos(VfxS32 simId);   

// Override
protected:
    virtual void onInit();

// Method
public:
    void updateOperatorName();

// Variable
private:
    VfxS32 m_simId;
    VfxImageFrame   *m_imgSim;
    VfxTextFrame    *m_textOPN;
    VfxTextFrame    *m_textSPN;
    VfxImageFrame   *m_seperateLineImg;
#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    VappAppWidgetSIMNameElementCosmos *m_textSIMName;
#endif
};


/*****************************************************************************
 * Cosmos Style Operator Name Widget
 *****************************************************************************/

class VappAppWidgetOperatorNameCosmos : public VappAppWidget
{
    VAPP_APP_WIDGET_DECLARE_CLASS(VappAppWidgetOperatorNameCosmos);

// Enum
private:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        WIDTH = 209,
        CELL_HEIGHT = 38,
#else
        WIDTH = 178,
        CELL_HEIGHT = 33,
#endif
        TITLE_BAR_HEIGHT = 26,
        SEPERATE_LINE_HEIGHT = 2,
        TITLE_UP_GAP = 2,
        TITLE_WIDTH = 166,
        TITLE_FONT_SIZE = 14,
        EDIT_BUTTON_OFFSET_X = 21,
        EDIT_BUTTON_OFFSET_Y = 13,
    };

// Constructor / Destructor
public:
    // Default constructor.
    VappAppWidgetOperatorNameCosmos();


// Override
public:
    // Please refer to VfxAppWidget.
    virtual VappAppWidgetId getId() const;

    // Please refer to VfxAppWidget.
    virtual VfxS32 getName(
        VfxWChar *string,
        VfxS32 size
    ) const;

    // Please refer to VfxAppWidget.
    virtual VfxSize getMaxSize() const;

    // Please refer to VfxAppWidget.
    virtual VfxFrame *createIcon(
        VfxObject *parentObj
    );

protected:
    // Please refer to VfxAppWidget.
    virtual void onCreateView();

    // Please refer to VfxAppWidget.
    virtual void onReleaseView();

    // Please refer to VfxAppWidget.
    virtual VfxPoint onGetEditButtonOffset();

// Method
private:
    void createOperatorNameElement();
    void releaseOperatorNameElement();
    void update();
    static mmi_ret eventHandler(mmi_event_struct *event);

// Variable
private:
    VfxImageFrame   *m_bgImg;
    VfxImageFrame   *m_bgTitleImg;
    VfxTextFrame    *m_title;
    VappAppWidgetOperatorElementCosmos *m_operElement[MMI_SIM_TOTAL]; 
};

#endif /* defined(__MMI_VUI_LAUNCHER__) && defined(VAPP_APP_WIDGET_OPERATOR_NAME) */
#endif /* VAPP_APP_WIDGET_OPERATOR_NAME_COSMOS_H */

