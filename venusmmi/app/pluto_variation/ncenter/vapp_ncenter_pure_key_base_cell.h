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
 *  vapp_ncenter_base_cell.h
 *
 * Project:
 * --------
 *  COSMOS Notification Center
 *
 * Description:
 * ------------
 * 
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"

#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_KEY_ONLY_NCENTER__)


#ifndef __VAPP_NCENTER_BASE_CELL_H__
#define __VAPP_NCENTER_BASE_CELL_H__

#include "vfx_uc_include.h"

#include "vcp_button.h"
#include "vcp_image_button.h"
#include "vcp_var_height_menu.h"
extern "C" 
{
    #include "mmi_rp_app_ncenter_def.h"

    #if defined(__MMI_VUI_COSMOS_CP__)
    #include "mmi_rp_app_cosmos_global_def.h"
    #endif
}



/***************************************************************************** 
 * Define
 *****************************************************************************/

// layout
#if defined(__MMI_MAINLCD_320X480__)
    //FOLD button
    #define VAPP_NCENTER_FOLD_BUTTON_GAP_X            (10)
    #define VAPP_NCENTER_FOLD_BUTTON_WIDTH            (24)
    #define VAPP_NCENTER_FOLD_BUTTON_HEIGHT           (24)
    // Event default cell
    #define VAPP_NCENTER_EVENT_CELL_WIDTH             (320)
    #define VAPP_NCENTER_EVENT_CELL_HEIGHT            (51)
    #define VAPP_NCENTER_EVENT_CELL_ICON_X            (10)
    #define VAPP_NCENTER_EVENT_CELL_ICON_Y            (5)
    #define VAPP_NCENTER_EVENT_CELL_ICON_WIDTH        (30)
    #define VAPP_NCENTER_EVENT_CELL_ICON_HEIGHT       (30)

    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_X       (50)
    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_Y       (4)
    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH   (260)
    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_SIZE    (20)
    
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_X       (50)
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_Y       (4)
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_WIDTH   (183)
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_SIZE    (14)

    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_X       (10)
    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_Y       (4)
    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_WIDTH   (77)
    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_SIZE    (14)

    // OnGoing default cell
    #define VAPP_NCENTER_ONGOING_CELL_WIDTH             (320)
    #define VAPP_NCENTER_ONGOING_CELL_HEIGHT            (51)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_X            (10)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_Y            (5)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_WIDTH        (30)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_HEIGHT       (30)

    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_X       (50)
    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_Y       (4)
    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_WIDTH   (226)
    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_SIZE    (20)
    
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_X       (50)
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_Y       (4)
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_WIDTH   (226)
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_SIZE    (14)

    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_X       (10)
    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_Y       (5)
    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_WIDTH   (24)
    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_HEIGHT  (24)


    #define VAPP_NCENTER_CLEAR_CELL_HEIGHT          (51)
    #define VAPP_NCENTER_CLEAR_CELL_BUTTON_X        (10)
    #define VAPP_NCENTER_CLEAR_CELL_BUTTON_WIDTH    (300)
    #define VAPP_NCENTER_CLEAR_CELL_BUTTON_HEIGHT   (47)

    #define VAPP_NCENTER_BOTTOM_HEIGHT              (37)
    #define VAPP_NCENTER_NO_EVENT_TEXT_SIZE         (20)

#if defined(__MMI_VUI_COSMOS_CP__)
    #define VAPP_NCENTER_CAPTION_FONT_SIZE          VFX_FONT_DESC_VF_SIZE(14)
#else /* defined(__MMI_VUI_COSMOS_CP__) */
    #define VAPP_NCENTER_CAPTION_FONT_SIZE          VFX_FONT_DESC_SIZE_SMALL
#endif    
    #define VAPP_NCENTER_CAPTION_HEIGHT             (26)
    

#elif defined(__MMI_MAINLCD_480X800__)
    //FOLD button
    #define VAPP_NCENTER_FOLD_BUTTON_GAP_X            (14)
    #define VAPP_NCENTER_FOLD_BUTTON_WIDTH            (45)
    #define VAPP_NCENTER_FOLD_BUTTON_HEIGHT           (45)
    // Event default cell
    #define VAPP_NCENTER_EVENT_CELL_WIDTH             (480)
    #define VAPP_NCENTER_EVENT_CELL_HEIGHT            (86)
    #define VAPP_NCENTER_EVENT_CELL_ICON_X            (14)
    #define VAPP_NCENTER_EVENT_CELL_ICON_Y            (10)
    #define VAPP_NCENTER_EVENT_CELL_ICON_WIDTH        (35)
    #define VAPP_NCENTER_EVENT_CELL_ICON_HEIGHT       (35)

    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_X       (67)
    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_Y       (10)
    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH   (399)
    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_SIZE    (35)
    
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_X       (67)
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_Y       (10)
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_WIDTH   (231)
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_SIZE    (26)

    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_X       (14)
    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_Y       (10)
    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_WIDTH   (135)
    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_SIZE    (26)

    // OnGoing default cell
    #define VAPP_NCENTER_ONGOING_CELL_WIDTH             (480)
    #define VAPP_NCENTER_ONGOING_CELL_HEIGHT            (86)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_X            (14)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_Y            (10)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_WIDTH        (35)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_HEIGHT       (35)

    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_X       (67)
    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_Y       (10)
    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_WIDTH   (347)
    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_SIZE    (35)
    
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_X       (67)
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_Y       (10)
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_WIDTH   (347)
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_SIZE    (26)

    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_X       (14)
    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_Y       (10)
    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_WIDTH   (45)
    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_HEIGHT  (45)

    #define VAPP_NCENTER_CLEAR_CELL_HEIGHT          (86)
    #define VAPP_NCENTER_CLEAR_CELL_BUTTON_X        (14)
    #define VAPP_NCENTER_CLEAR_CELL_BUTTON_WIDTH    (452)
    #define VAPP_NCENTER_CLEAR_CELL_BUTTON_HEIGHT   (84)

    #define VAPP_NCENTER_BOTTOM_HEIGHT              (47)
    #define VAPP_NCENTER_NO_EVENT_TEXT_SIZE         (35)

    #define VAPP_NCENTER_CAPTION_FONT_SIZE           VFX_FONT_DESC_VF_SIZE(21)
    #define VAPP_NCENTER_CAPTION_HEIGHT             (37)    
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__)
    //FOLD button
    #define VAPP_NCENTER_FOLD_BUTTON_GAP_X            (5)
    #define VAPP_NCENTER_FOLD_BUTTON_WIDTH            (24)
    #define VAPP_NCENTER_FOLD_BUTTON_HEIGHT           (24)
    // Event default cell
    #define VAPP_NCENTER_EVENT_CELL_WIDTH             (240)
    #define VAPP_NCENTER_EVENT_CELL_HEIGHT            (45)
    #define VAPP_NCENTER_EVENT_CELL_ICON_X            (5)
    #define VAPP_NCENTER_EVENT_CELL_ICON_Y            (10)
    #define VAPP_NCENTER_EVENT_CELL_ICON_WIDTH        (24)
    #define VAPP_NCENTER_EVENT_CELL_ICON_HEIGHT       (24)

    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_X       (34)
    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_Y       (7)
    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH   (201)
    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_SIZE    (16)
    
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_X       (34)
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_Y       (4)
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_WIDTH   (137)
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_SIZE    (12)

    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_X       (5)
    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_Y       (4)
    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_WIDTH   (67)
    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_SIZE    (12)

    // OnGoing default cell
    #define VAPP_NCENTER_ONGOING_CELL_WIDTH             (240)
    #define VAPP_NCENTER_ONGOING_CELL_HEIGHT            (45)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_X            (5)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_Y            (10)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_WIDTH        (24)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_HEIGHT       (24)

    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_X       (34)
    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_Y       (7)
    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_WIDTH   (172)
    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_SIZE    (16)
    
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_X       (34)
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_Y       (4)
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_WIDTH   (160)
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_SIZE    (12)

    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_X       (5)
    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_Y       (10)
    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_WIDTH   (24)
    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_HEIGHT  (24)

    #define VAPP_NCENTER_CLEAR_CELL_HEIGHT          (45)
    #define VAPP_NCENTER_CLEAR_CELL_BUTTON_X        (14)
    #define VAPP_NCENTER_CLEAR_CELL_BUTTON_WIDTH    (220)
    #define VAPP_NCENTER_CLEAR_CELL_BUTTON_HEIGHT   (45)

    #define VAPP_NCENTER_BOTTOM_HEIGHT              (25)
    #define VAPP_NCENTER_NO_EVENT_TEXT_SIZE         (20)   

    #define VAPP_NCENTER_CAPTION_FONT_SIZE          VFX_FONT_DESC_VF_SIZE(12)
    #define VAPP_NCENTER_CAPTION_HEIGHT             (22)
#else
    //FOLD button
    #define VAPP_NCENTER_FOLD_BUTTON_GAP_X            (10)
    #define VAPP_NCENTER_FOLD_BUTTON_WIDTH            (24)
    #define VAPP_NCENTER_FOLD_BUTTON_HEIGHT           (24)
    // Event default cell
    #define VAPP_NCENTER_EVENT_CELL_WIDTH             (320)
    #define VAPP_NCENTER_EVENT_CELL_HEIGHT            (51)
    #define VAPP_NCENTER_EVENT_CELL_ICON_X            (10)
    #define VAPP_NCENTER_EVENT_CELL_ICON_Y            (5)
    #define VAPP_NCENTER_EVENT_CELL_ICON_WIDTH        (30)
    #define VAPP_NCENTER_EVENT_CELL_ICON_HEIGHT       (30)

    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_X       (50)
    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_Y       (4)
    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH   (260)
    #define VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_SIZE    (20)
    
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_X       (50)
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_Y       (4)
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_WIDTH   (183)
    #define VAPP_NCENTER_EVENT_CELL_SUB_TEXT_SIZE    (14)
    
    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_X       (10)
    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_Y       (4)
    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_WIDTH   (73)
    #define VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_SIZE    (14)
    
    // OnGoing default cell
    #define VAPP_NCENTER_ONGOING_CELL_WIDTH             (320)
    #define VAPP_NCENTER_ONGOING_CELL_HEIGHT            (51)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_X            (10)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_Y            (5)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_WIDTH        (30)
    #define VAPP_NCENTER_ONGOING_CELL_ICON_HEIGHT       (30)

    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_X       (50)
    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_Y       (4)
    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_WIDTH   (226)
    #define VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_SIZE    (20)
    
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_X       (50)
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_Y       (4)
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_WIDTH   (226)
    #define VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_SIZE    (14)

    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_X       (10)
    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_Y       (5)
    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_WIDTH   (24)
    #define VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_HEIGHT  (24)

    #define VAPP_NCENTER_CLEAR_CELL_HEIGHT          (45)
    #define VAPP_NCENTER_CLEAR_CELL_BUTTON_X        (14)
    #define VAPP_NCENTER_CLEAR_CELL_BUTTON_WIDTH    (220)
    #define VAPP_NCENTER_CLEAR_CELL_BUTTON_HEIGHT   (45)

    #define VAPP_NCENTER_BOTTOM_HEIGHT              (24)
    #define VAPP_NCENTER_NO_EVENT_TEXT_SIZE         (20)   

    #define VAPP_NCENTER_CAPTION_FONT_SIZE          VFX_FONT_DESC_VF_SIZE(12)
    #define VAPP_NCENTER_CAPTION_HEIGHT             (22)    
#endif



#if defined(__MMI_VUI_COSMOS_CP__)
    #define VAPP_NCENTER_CLR_BACKGROUND VFX_COLOR_RES(CLR_COSMOS_BG_MAIN)
    #define VAPP_NCENTER_CLR_TEXT_MAIN VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN) 
    #define VAPP_NCENTER_CLR_TEXT_SUB VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB) 
    #define VAPP_NCENTER_CLR_TEXT_MAIN_HIGHLIGHT VFX_COLOR_RES(VCP_COL_LIST_MENU_FOCUS_HIGHLIGHT_TEXT)
    #define VAPP_NCENTER_CLR_TEXT_SUB_HIGHLIGHT VFX_COLOR_RES(VCP_COL_LIST_MENU_FOCUS_HIGHLIGHT_TEXT)
#else

    #define VAPP_NCENTER_CLR_BACKGROUND VFX_COLOR_WHITE
    #define VAPP_NCENTER_CLR_TEXT_MAIN VRT_COLOR_MAKE(255,15, 15, 15) 
    #define VAPP_NCENTER_CLR_TEXT_SUB VRT_COLOR_MAKE(255, 50, 50, 50)
    #define VAPP_NCENTER_CLR_TEXT_MAIN_HIGHLIGHT VFX_COLOR_WHITE
    #define VAPP_NCENTER_CLR_TEXT_SUB_HIGHLIGHT VFX_COLOR_WHITE    
#endif   

    #define VAPP_NCENTER_CLR_SEPERATOR VRT_COLOR_MAKE(80, 128, 128, 128)



class VsrvNotification;
class VsrvNGroup;
class VappNCenterList;


/***************************************************************************** 
 * Class VappNCenterBaseCell
 *****************************************************************************/
    
class VappNCenterBaseCell : public VfxControl
{
    // Constructor / Destructor
public:
    // Default constructor
    VappNCenterBaseCell();   


// Override
protected:
    virtual void onInit();
    virtual void onDeinit();    
    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

// Method
public:
    void setNotification(VsrvNotification* noti);
    VsrvNotification* getNotification();    
    virtual void setHighlight(VfxBool isHighlight);
    virtual void updateElements(){};    
    virtual void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos preFocusItem);

protected:
    VsrvNotification* m_noti;
    VfxS32 m_maxMoveOffset;
    VappNCenterList* m_menu;

};

/***************************************************************************** 
 * Class VappNCenterEventCell
 *****************************************************************************/


class VappNCenterEventCell : public VappNCenterBaseCell
{
    // Constructor / Destructor
public:
    // Default constructor
    VappNCenterEventCell();   


// Override
protected:
    virtual void onInit();
   
// Method
public:
    virtual void updateElements();    
    virtual void setHighlight(VfxBool isHighlight);

    void setIcon(
        const VfxImageSrc &imgScr         // [IN] image
        )
    {
        if (m_icon && !imgScr.isNull())
        {
            m_icon->setImgContent(imgScr);
        }
    }
    
    void setMainText(
        const VfxWString &text          // [IN] text
        )
    {
        if (m_mainText)
        {
            m_mainText->setString(text);
        }
    }
    
    VfxWString getMainText() const
    {
        if (m_mainText)
        {
            return m_mainText->getString();
        }
        else
        {
            return VFX_WSTR_NULL;
        }
    }

    void setSubText(
        const VfxWString &text          // [IN] text
        )
    {
        if (m_subText)
        {
            m_subText->setString(text);
        }
    }
    
    VfxWString getSubText() const
    {
        if (m_subText)
        {
            return m_subText->getString();
        }
        else
        {
            return VFX_WSTR_NULL;
        }
    }

    void setRightText(
        const VfxWString &text          // [IN] text
        )
    {
        if (m_rightText)
        {
            m_rightText->setString(text);
        }
    }
    
    VfxWString getRightText() const
    {
        if (m_subText)
        {
            return m_subText->getString();
        }
        else
        {
            return VFX_WSTR_NULL;
        }
    }    



// Variable 
protected:
    VfxFrame *m_icon;
    VfxTextFrame *m_mainText;
    VfxTextFrame *m_subText;
    VfxTextFrame *m_rightText;


};



/***************************************************************************** 
 * Class VappNCenterOngoingDefaultCell 
 *****************************************************************************/
 
class VappNCenterOngoingCell : public VappNCenterBaseCell
{
    // Constructor / Destructor
public:
    // Default constructor
    VappNCenterOngoingCell();   


// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Method
public:
    virtual void updateElements();        
    virtual void setHighlight(VfxBool isHighlight);

    void setIcon(
        const VfxImageSrc &imgScr         // [IN] image
        )
    {
        if (m_icon && !imgScr.isNull())
        {
            m_icon->setImgContent(imgScr);
        }
    }
    
    void setMainText(
        const VfxWString &text          // [IN] text
        )
    {
        if (m_mainText)
        {
            m_mainText->setString(text);
        }
    }
    
    VfxWString getMainText() const
    {
        if (m_mainText)
        {
            return m_mainText->getString();
        }
        else
        {
            return VFX_WSTR_NULL;
        }
    }

    void setSubText(
        const VfxWString &text          // [IN] text
        )
    {
        if (m_subText)
        {
            m_subText->setString(text);
        }
    }
    
    VfxWString getSubText() const
    {
        if (m_subText)
        {
            return m_subText->getString();
        }
        else
        {
            return VFX_WSTR_NULL;
        }
    }

    void setQuestionText(
        const VfxWString &text          // [IN] text
        )
    {
        m_questionText = text;
    }
    
    VfxWString getQuestionText() const
    {
        return m_questionText;
    }


// Variable 
protected:
    VfxFrame *m_icon;
    VfxTextFrame *m_mainText;
    VfxTextFrame *m_subText;
    VcpImageButton  *m_closeButton;
    VfxWString m_questionText;
    VfxS32 m_popupHandle;
    
    
};



/***************************************************************************** 
 * Class VappNCenterOngoingDefaultCell 
 *****************************************************************************/

enum VappNCenterListCellType
{
	VAPP_NCENTER_LIST_CELL_TYPE_HEADER,
    VAPP_NCENTER_LIST_CELL_TYPE_EVENT,
	VAPP_NCENTER_LIST_CELL_TYPE_ONGOING,        
	VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_EVENT,        		
    VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_ONGOING,        		
	VAPP_NCENTER_LIST_CELL_TYPE_END      				
};

struct VappNCenterListCellStruct
{
    VappNCenterListCellType type;
    VfxDateTime timeStamp;        
};


struct VappNCenterGroupStruct
{
    VsrvNGroup *group;
    VfxDateTime groupTimeStamp;    
};




class VappNCenterListCell : public VcpVarHeightMenuCell
{

    
    // Constructor / Destructor
public:
    // Default constructor
    VappNCenterListCell(VcpMenuPos pos, VappNCenterListCellType type) : VcpVarHeightMenuCell(pos), m_type(type) {};

// Override
protected:
    virtual void onInit();
    virtual void onUpdate();

// method
public:
    void setContent(VfxFrame *);
    
    
// Variable 
protected:
    VappNCenterListCellType m_type;    
    VfxWeakPtr <VfxFrame> m_content;
};


/***************************************************************************** 
 * Class VVappNCenterListLayout
 *****************************************************************************/

class VappNCenterListLayout : public VcpVarHeightMenuLayout
{
    
// Constructor / Destructor
public:
    VappNCenterListLayout(VappNCenterList *menu);

    
// Overridable
public:
    virtual VfxBool navDir(NavDirEnum dir);   

    VfxS32 getNextFocusItem(VfxS32 index, NavDirEnum dir);

};




/***************************************************************************** 
 * Class VappNCenterList 
 *****************************************************************************/


class VappNCenterList : public VcpVarHeightMenu 
{
    VFX_DECLARE_CLASS(VappNCenterList);

// Constructor / Destructor
public:
    VappNCenterList() : VcpVarHeightMenu(LAYOUT_NORMAL) {};


// Override
protected:
    // create VcpVarHeightMenuLayout
    virtual VcpBaseMenuLayout* createLayout();

    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    virtual void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos preFocusItem);
    virtual void onTouchCell(VcpMenuPos cellPos, VcpBaseMenu::CellTouchTypeEnum touchType, VfxPoint pt, VfxFrame *cell);

    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos);
   
    virtual void onCloseCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index
        VfxFrame* cellFrame     // [IN] The cell will be closed
    );

    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);

public:
    VappNCenterListLayout* getLayoutNCenter()
    {
        return (VappNCenterListLayout*)VcpBaseMenu::getLayout();
    }
// Signal
public:
    VfxSignal2 <VcpMenuPos, VcpMenuPos>  m_signalFocusIndexChange;


};


/***************************************************************************** 
 * Class VappNCenterClearCell 
 *****************************************************************************/

class VappNCenterClearCell : public VfxControl
{
    // Constructor / Destructor
public:
    // Default constructor
    VappNCenterClearCell();   

// Override
protected:
    virtual void onInit();

// Variable
public:
    VcpButton *m_clearButton;
};






#endif /* __VAPP_NCENTER_BASE_CELL_H__ */

#endif /* defined(__MMI_NCENTER_SUPPORT__) */

