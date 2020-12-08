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
 *  vapp_movie_theater_detail.h
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
 * -------
 *
 ****************************************************************************/

#ifndef __VAPP_MOVIE_THEATER_DETAIL_H__
#define __VAPP_MOVIE_THEATER_DETAIL_H__


/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_movie_theater.h"

extern "C"
{
#include "MotSrvGProt.h"
}


#ifdef __MMI_MAINLCD_480X800__
    #define VAPP_MOVIE_THEATER_STATUS_BAR_HEIGHT (36)
#else
    #define VAPP_MOVIE_THEATER_STATUS_BAR_HEIGHT (24)
#endif

class VappMovieTheaterTitleCell : public VfxControl
{
    //VFX_DECLARE_CLASS(VappMovieTheaterTitleCell);

public:
    enum
    {
    #ifdef __MMI_MAINLCD_480X800__
        ITEM_WIDTH = 480,
        ITEM_HEIGHT = 105,
        THUMB_ICON_WIDTH  = 85,
        THUMB_ICON_HEIGHT = 85,
        TXT_Y_GAP   = 3,
        TEXT_LSIDE_ALIGN = 14,
        TEXT_TSIDE_ALIGN = 31,
        ICON_TSIDE_ALIGN = 25,
        ICON_LSIDE_ALIGN = 14,
        ICON_RSIDE_ALIGN = 14,

        MAIN_FONT_SIZE = 35,
        SUB_FONT_SIZE = 26,
    #elif __MMI_MAINLCD_320X480__
        ITEM_WIDTH = 320,
        ITEM_HEIGHT = 64,
        THUMB_ICON_WIDTH  = 50,
        THUMB_ICON_HEIGHT = 50,
        TXT_Y_GAP   = 1,
        TEXT_LSIDE_ALIGN = 8,
        TEXT_TSIDE_ALIGN = 21,
        ICON_TSIDE_ALIGN = 25,
        ICON_LSIDE_ALIGN = 8,
        ICON_RSIDE_ALIGN = 8,

        MAIN_FONT_SIZE = 22,
        SUB_FONT_SIZE = 14,
    #else
        ITEM_WIDTH = 240,
        ITEM_HEIGHT = 50,
        THUMB_ICON_WIDTH  = 46,
        THUMB_ICON_HEIGHT = 46,
        TXT_Y_GAP   = 0,
        TEXT_LSIDE_ALIGN = 5,
        TEXT_TSIDE_ALIGN = 21,
        ICON_TSIDE_ALIGN = 25,
        ICON_LSIDE_ALIGN = 5,
        ICON_RSIDE_ALIGN = 5,

        MAIN_FONT_SIZE = 16,
        SUB_FONT_SIZE = 12,
    #endif
        TEXT_WIDTH = (ITEM_WIDTH-3*TEXT_LSIDE_ALIGN-THUMB_ICON_WIDTH),
        MAIN_TEXT_HEIGHT = MAIN_FONT_SIZE+2,
        SUB_TEXT_HEIGHT = SUB_FONT_SIZE+2,
        MAIN_TEXT_COLOR_R = 250,
        MAIN_TEXT_COLOR_G = 250,
        MAIN_TEXT_COLOR_B = 250,
        SUB_TEXT_COLOR_R = 225,
        SUB_TEXT_COLOR_G = 225,
        SUB_TEXT_COLOR_B = 225,
    };

    void setMainText(VfxWString &text);
    void setSubText(VfxWString &text);
    void setImage(const VfxU8 *buf);

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Implementation
private:

    VfxFrame *m_bg;
    VfxImageFrame *m_img;
    VfxTextFrame *m_txt;
    VfxTextFrame *m_txt_sub;
};

class VappMovieTheaterDetailCell : public VcpFormItemBase
{
    //VFX_DECLARE_CLASS(VappMovieTheaterDetailCell);
public:
    VappMovieTheaterDetailCell();
    VappMovieTheaterDetailCell(VfxBool firstCell);

    void setMainText(const VfxWString &text);
    void setSubText(const VfxWString &text);

// Override
protected:
    virtual void onInit();

// Implementation
private:
    enum
    {
    #ifdef __MMI_MAINLCD_480X800__
        ITEM_WIDTH  = 480,
        ITEM_HEIGHT = 63,
        GAP         = 14,
        CELL_GAP    = 18,
        EDITOR_GAP  = 14,
        EDITOR_SIZE = 59,
        TXT_Y       = 18,
        TXT_Y_GAP   = 0,

        TEXT_WIDTH = 200,
        TEXT_HEIGHT = 15,

        THUMB_Y_GAP = 18,
        THUMB_WIDTH = 350,
        THUMB_HEIGHT = 226,

        MAIN_FONT_SIZE = 30,
        SUB_FONT_SIZE = 26,
    #elif __MMI_MAINLCD_320X480__
        ITEM_WIDTH  = 320,
        ITEM_HEIGHT = 63,
        GAP         = 8,
        CELL_GAP    = 10,
        EDITOR_GAP  = 10,
        EDITOR_SIZE = 36,
        TXT_Y       = 18,
        TXT_Y_GAP   = 0,

        TEXT_WIDTH = 200,
        TEXT_HEIGHT = 15,

        THUMB_Y_GAP = 8,
        THUMB_WIDTH = 207,
        THUMB_HEIGHT = 155,

        MAIN_FONT_SIZE = 20,
        SUB_FONT_SIZE = 16,
    #else
        ITEM_WIDTH  = 240,
        ITEM_HEIGHT = 63,
        GAP         = 5,
        CELL_GAP    = 6,
        EDITOR_GAP  = 5,
        EDITOR_SIZE = 30,
        TXT_Y       = 3,
        TXT_Y_GAP   = 0,

        TEXT_WIDTH = 200,
        TEXT_HEIGHT = 15,

        THUMB_Y_GAP = 6,
        THUMB_WIDTH = 176,
        THUMB_HEIGHT = 132,

        MAIN_FONT_SIZE = 16,
        SUB_FONT_SIZE = 14,
    #endif
        MAIN_TEXT_HEIGHT = MAIN_FONT_SIZE+2,
        SUB_TEXT_HEIGHT = SUB_FONT_SIZE+2
    };

    #define MAIN_TEXT_COLOR VfxColor(255, 21, 21, 21)
    #define SUB_TEXT_COLOR VfxColor(255, 80, 80, 80)

    VfxBool m_firstCell;
    VfxTextFrame *m_txt;
    VfxTextFrame *m_txt_sub;
};


class VappMovieTheaterDetailPage : public VappMovieTheaterPage
{
    //VFX_DECLARE_CLASS(VappMovieTheaterDetailPage);

public:
    VappMovieTheaterDetailPage();

// Override VappMovieTheaterPage
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExited2();

public:
    void setSource(srv_mot_cat_enum catId, VfxU32 mediaId);

private:
    void onClickToolBarButton(VfxObject* obj, VfxId button_id);
    void drawFileDetail();

private:
    VcpTitleBar *m_titleBar;
    VappMovieTheaterTitleCell *m_titleCell;
    VfxU8 *m_titleCellImage;
    VcpForm *m_form;
    VcpToolBar  *m_toolBar;
};


#endif /* __VAPP_MOVIE_THEATER_DETAIL_H__ */

