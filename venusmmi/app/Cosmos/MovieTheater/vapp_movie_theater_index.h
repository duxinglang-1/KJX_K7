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
 *  vapp_movie_theater_index.h
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

#ifndef __VAPP_MOVIE_THEATER_INDEX_H__
#define __VAPP_MOVIE_THEATER_INDEX_H__


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

/*****************************************************************************
 * Enum and constants
 *****************************************************************************/


class VappMovieTheaterIndexPage : public VappMovieTheaterPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappMovieTheaterIndexPage);

public:
    static const VfxS32 INDEX_MENU_ITEM_COUNT = (SRV_MOT_CAT_SYSTEM_DEFINE_NUM + 2);  // last play, all, and system defined categories.

// Override
public:
    VappMovieTheaterIndexPage();
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onExited2();

    void onDelayEntered(VfxTimer *timer);

// Implement IVcpListMenuContentProvider
public:
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType,
                            VfxWString &text, VcpListMenuTextColorEnum &color);

    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

// methods
public:
    virtual void refreshStorage(VfxBool directRefresh);

// methods for provider callback.
public:
    void updateListItems(srv_mot_ret_enum result);

public:
    VcpIndicatorPopup *m_popupWaiting;

protected:
    void onIndexItemTapped(VcpListMenu *sender, VfxU32 index);
    void onGotoPage(VfxU32 index);
    void onSelectStorage(VfxObject *sender, VfxId btnId);

    VfxBool handleStorageChangeLite(VappMovieTheaterStorageSetting &storageSetting);
    void handleStorageChange(VappMovieTheaterStorageSetting &storageSetting);

    void createStorageSelectionTab(
                    VfxBool updateStorage    // VFX_TRUE means automatically update storage. Otherwise keep current focus.
                    );

    // create Page instances from index menu index
    static mmi_ret onDevicePlugInOut(mmi_event_struct *param);
    mmi_ret handleDevicePlugInOut(mmi_event_struct *param);

private:
    void handleWaitingBegin(srv_fmgr_drv_type_enum defaultStorage);
    void handleWaitingEnd();
    void onClickToolBarButton(VfxObject* obj, VfxId button_id);
    void onRefreshed(VfxTimer *timer);
    void popupWaiting(VfxWString str, VfxBool withCancelBtn);
    void onWaitingCanceled(VfxObject* obj, VfxFloat curr_progress);
    void popupWaitingClose();

private:
    VfxSignal0 m_signalUpdated;

    VcpListMenu *m_indexMenu;                           // the menu component
    VfxBool m_1stEntry;
    VfxBool m_isDBReady;

    VfxTimer *m_delayEnteredTimer;
    VfxTimer *m_delayRefreshedTimer;
    VfxMsec m_refreshStart;

    VfxS32* m_indexNumber;

    VcpToolBar *m_toolBar;

    VcpBaseMenuViewState m_viewState; // restore folder view state after re-enter the page

};

#endif /* __VAPP_MOVIE_THEATER_INDEX_H__ */

