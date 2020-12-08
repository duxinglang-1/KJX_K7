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
 *  vapp_movie_theater_category.h
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

#ifndef __VAPP_MOVIE_THEATER_CATEGORY_H__
#define __VAPP_MOVIE_THEATER_CATEGORY_H__


/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_movie_theater.h"
#include "vapp_gallery_gprot.h"

extern "C"
{
#include "MotSrvGProt.h"
}

class VappMovieTheaterCategoryPage : public VappMovieTheaterPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappMovieTheaterCategoryPage);

public:
    VappMovieTheaterCategoryPage(srv_mot_cat_enum cat = SRV_MOT_CAT_ACTION_ADVENTURE);

// Override VappMovieTheaterPage
public:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onUpdate();
    virtual void onExit(VfxBool isBackward);
    virtual void onExited2();

// method and event handler
public:
    void setupVideoMenu();

    void onItemTapped(VcpListMenu *sender, VfxU32 index);
    
    void onClickCmdButton(VcpListMenu *listmenu, VfxU32 index);

// data members
private:
    VcpListMenu *m_videoMenu;
    VcpBaseMenuViewState m_viewState; // restore folder view state after re-enter the page

// UI implementation
private:

    // handles media list prepare result
    void onMediaListReady();

// supporting list menu
public:
    // Provide custom cells for layout
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        );

    // Check if there are thumbnails waiting to be decoded
    //void onThumbRefresh(VfxTimer *source);

    // Notify the view is end of scrolling.
    //void handleViewScrollStart(VcpBaseListMenu *menu);
    //void handleViewScrollEnd(VcpBaseListMenu *menu);

    // Provide custom cells for layout
    virtual void closeItemCustomContentFrame(VfxU32 index,
                                             VcpListMenuCellClientBaseFrame *cell);

    virtual VfxU32 getCount() const;

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );

    virtual void closeItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc imgSrc               // [IN] the image resource
        );

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index
        ) const;

// implementation of ListMenu & multi-selection
private:
    VfxBool                 m_isExit;       // use dummy content when page onExit() is called
    //VfxTimer                *m_thumbRefreshTimer;
    VfxU32 m_currCatNum;   // current video number of selected category
};

class VappMovieTheaterCategoryMenuItemFrame : public VcpListMenuCellIconTripleTextFrameEx
{
public:
    enum VappMovieTheaterCategoryThumbLayout
    {
    #if defined(__MMI_MAINLCD_480X800__)
        VIDEO_THUMB_W = 85, //110,
        VIDEO_THUMB_H = 85, //85,

    #elif defined(__MMI_MAINLCD_320X480__)
        VIDEO_THUMB_W = 50, //64,
        VIDEO_THUMB_H = 50, //50,

    #else
        VIDEO_THUMB_W = 46, //64,
        VIDEO_THUMB_H = 46, //50,

    #endif
    };

public:
    VappMovieTheaterCategoryMenuItemFrame();

    // override layout method to customize thumbnail postion
    virtual void onLayoutElements();

    //VfxBool isContentReady();

private:
};


#endif /* __VAPP_MOVIE_THEATER_CATEGORY_H__ */

