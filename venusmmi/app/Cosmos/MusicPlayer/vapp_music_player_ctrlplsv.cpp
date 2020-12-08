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
 *  vapp_music_player_ctrlplsv.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player PLSV control and ListMenuContentProvider
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
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
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#include "vapp_music_player_ctrlplsv.h"
#include "vapp_music_player.h"
#include "vapp_music_player_util.h"
#include "Vfx_config.h"
#include "mmi_rp_vapp_music_player_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "drm_errcode.h"
#include "mmi_frm_mem_gprot.h"

extern "C"
{
#include "gdi_include.h"
}

/***************************************************************************** 
 * VappMusicPlayerContentProvider Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerListMenuProvider", VappMusicPlayerListMenuProvider, VfxObject);

void VappMusicPlayerListMenuProvider::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_LIST_MENU_PROVIDER_ON_INIT);

    VfxObject::onInit();

    m_mplayerSrv = getMusicPlayerSrv();
}

void VappMusicPlayerListMenuProvider::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_LIST_MENU_PROVIDER_ON_DEINIT);

    VfxObject::onDeinit();
}

VfxU32 VappMusicPlayerListMenuProvider::getCount() const
{
#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
    if (!m_mplayerSrv->getMemoryCardReady())
    {
        // Do not return any data if no memory card
        return 0;
    }
#endif

    // If page is in onEnter() to onEntered() state, return 0
    // or if app is chekcing duplicated playlist, return 0
    if(m_isEntering || m_isCheckingDuplicatedPlaylist)
    {
        return 0;
    }

    if(m_dataProvider)
    {
        // If data provider in the same view of list, return count. Or use old count to return.
        if(m_dataProvider->getViewType() == m_viewType)
        {
            m_count = m_dataProvider->getCount();
        }
        return m_count;
    }
    return 0;
}

VfxU32 VappMusicPlayerListMenuProvider::getID(VfxU32 index)
{
    if(m_dataProvider && (m_dataProvider->getViewType() == m_viewType))
    {
        return m_dataProvider->getID(index);
    }

    return 0;
}

VcpListMenuCellClientBaseFrame* VappMusicPlayerListMenuProvider::getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame)
{
    if(m_dataProvider)
    {
        return m_dataProvider->getItemCustomContentFrame(index, parentFrame);
    }
    return NULL;
}

void VappMusicPlayerListMenuProvider::closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame *pCell)
{
    if(m_dataProvider)
    {
        return m_dataProvider->closeItemCustomContentFrame(index, pCell);
    }
}

VfxBool VappMusicPlayerListMenuProvider::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    // Check if data provider view same as list content provider view
    if(m_dataProvider && (m_dataProvider->getViewType() == m_viewType))
    {
        VfxBool isLoad = VFX_TRUE;
        if(m_listMenu)
        {
            isLoad = m_listMenu->isCellSubTextLoad(index);
        }	

        return m_dataProvider->getItemTextEx(index, fieldType, text, color, m_isScrolling, isLoad);
    }
    return VFX_FALSE;
}

VfxBool VappMusicPlayerListMenuProvider::getItemTextFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VcpRichText &format)
{
    if(m_dataProvider && (m_dataProvider->getViewType() == m_viewType))
    {
        return m_dataProvider->getItemTextFormat(index, fieldType, format, m_isScrolling);
    }
    return VFX_FALSE;
}

VfxBool VappMusicPlayerListMenuProvider::getItemTextFrameFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxTextFrame *frame)
{
    if(m_dataProvider && (m_dataProvider->getViewType() == m_viewType))
    {
        return m_dataProvider->getItemTextFrameFormat(index, fieldType, frame);
    }
    return VFX_FALSE;
}

VfxBool VappMusicPlayerListMenuProvider::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image)
{
    if(m_dataProvider && (m_dataProvider->getViewType() == m_viewType))
    {
        return m_dataProvider->getItemImage(index, fieldType, image);
    }

    image.setResId(m_dataProvider->getDefaultAlbumCover(m_viewType));
    
    return VFX_FALSE;
}

void VappMusicPlayerListMenuProvider::closeItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc Image)
{
    if(m_dataProvider)
    {
        if (fieldType == VCP_LIST_MENU_FIELD_ICON)
        {
            if (m_viewType == VIEW_TYPE_ALBUM
             || m_viewType == VIEW_TYPE_ARTIST_ALBUM
             || m_viewType == VIEW_TYPE_PLAYLIST_ADD_ALBUM)
            {
                // free image buffer
                VfxU32 itemIndex = index;
                if (m_viewType == VIEW_TYPE_ARTIST_ALBUM)
                {
                    // consider the first item in artist's album view is "All songs of artist"
                    if (index == 0)
                    {
                        return;
                    }
                    else
                    {
                        itemIndex--;
                    }
                }

                m_dataProvider->closeItemImage(itemIndex, fieldType, Image);
            }
        }
    }
}

VcpListMenuItemStateEnum VappMusicPlayerListMenuProvider::getItemState(VfxU32 index) const
{ 
    if(m_dataProvider)
    {
        return m_dataProvider->getItemState(index);
    }
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}

VfxBool VappMusicPlayerListMenuProvider::getItemIsDisabled(VfxU32 index) const
{
    if(m_dataProvider)
    {
        return m_dataProvider->getItemIsDisabled(index);
    }
    return VFX_FALSE;
}

VfxBool VappMusicPlayerListMenuProvider::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color) 
{
#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
    if (!m_mplayerSrv->getMemoryCardReady())
    {
        text.loadFromRes(STR_GLOBAL_INSERT_MEMORY_CARD);
        return VFX_TRUE;
    }
#endif

    // If page is in onEnter() to onEntered() state, show nothing
    VappMusicPlayerApp *app = getMusicPlayerApp();
    ActionEnum action = app ? app->getActionMode() : ACTION_NONE;

    if (m_isEntering || action <= ACTION_RESET)
    {
        text.format("");
        return VFX_TRUE;
    }

    if(m_dataProvider)
    {
        return m_dataProvider->getMenuEmptyText(text, color);
    }
    return VFX_FALSE;
}

VfxBool VappMusicPlayerListMenuProvider::swapItem(VfxU32 to, VfxU32 from)
{
    if(m_dataProvider)
    {
        return m_dataProvider->swapItem(to, from);
    }
    return VFX_FALSE;
}

void VappMusicPlayerListMenuProvider::setViewType(ViewTypeEnum viewType)
{
    m_viewType = viewType;
}

ViewTypeEnum VappMusicPlayerListMenuProvider::getViewType() const
{
    return m_viewType;
}

void VappMusicPlayerListMenuProvider::setListMenu(VappMusicPlayerListMenu *listmenu)
{
    m_listMenu = listmenu;
}

void VappMusicPlayerListMenuProvider::setDataProvider(VappMusicPlayerContentProvider *provider)
{
    m_dataProvider = provider;
}

void VappMusicPlayerListMenuProvider::pauseMediaCache(void)
{
    if(m_dataProvider)
    {
        if(m_dataProvider->getViewType() == m_viewType)
        {
            m_dataProvider->pauseMediaCache();
        }
    }
}

void VappMusicPlayerListMenuProvider::resumeMediaCache(void)
{
    if(m_dataProvider)
    {
        if(m_dataProvider->getViewType() == m_viewType)
        {
            m_dataProvider->resumeMediaCache();
        }
    }
}

void VappMusicPlayerListMenuProvider::setMenuScrolling(VfxBool isScrolling)
{
    m_isScrolling = isScrolling;
}

void VappMusicPlayerListMenuProvider::setEntering(VfxBool isEntering)
{
    m_isEntering = isEntering;
}

void VappMusicPlayerListMenuProvider::setCheckingDuplicatedPlaylist(VfxBool isChecking)
{
    m_isCheckingDuplicatedPlaylist = isChecking;
}

/***************************************************************************** 
 * VappMusicPlayerContentProvider Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerContentProvider", VappMusicPlayerContentProvider, VfxObject);

void VappMusicPlayerContentProvider::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTNT_PROVIDER_INIT);

    VfxObject::onInit();
    
    VFX_OBJ_CREATE(m_ctrlPLSV, VappMusicPlayerCtrlPLSV, this);

    VFX_OBJ_CREATE(m_ctrlMediaCache, VappMusicPlayerCtrlMediaCahce, this);
    m_ctrlMediaCache->setDecodeCallback(&VappMusicPlayerContentProvider::onMediaCacheDecodeResultHandler, this);

    m_listItemCache.ID = 0;
    m_listItemCache.index = 0;
    m_listItemCache.hasInfo = VFX_FALSE;
    m_listItemCache.titleOnly = VFX_FALSE;

    m_mplayerSrv = getMusicPlayerSrv();
    VfxWString activeFilePath = m_mplayerSrv->getActiveFilePath();

    m_hlInfo.viewType = VIEW_TYPE_NONE;
    m_hlInfo.plstID = -1;
    m_hlInfo.hlIdx = -1;
    m_hlInfo.preHlIdx = -1;
        
    if (!activeFilePath.isEmpty())
    {
        // restore high light info
        SongInfoStruct info;
        m_mplayerSrv->getCurrInfo(info);
        updateHighLightInfo(info, m_mplayerSrv->getActiveViewType());
        m_hlInfo.plstID = m_mplayerSrv->getActivePlayListID();

        m_showPlayIcon = VFX_TRUE;
    }
}

void VappMusicPlayerContentProvider::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTNT_PROVIDER_DEINIT);

    m_mplayerSrv->setActivePlayListID(m_hlInfo.plstID);

    freeImageBuffer();

    if(m_selectingState != NULL)
    {
        VFX_FREE_MEM(m_selectingState);
        m_selectingState = NULL;
    }

    VfxObject::onDeinit();
}

void VappMusicPlayerContentProvider::initRepeatShuffle()
{
    m_ctrlPLSV->initRepeatShuffle();
}

void VappMusicPlayerContentProvider::saveRepeatShuffle()
{
    m_ctrlPLSV->saveRepeatShuffle();
}

void VappMusicPlayerContentProvider::setCBReceiver(VfxObject *obj)
{
    m_ctrlPLSV->setCBReceiver(obj);
}

void VappMusicPlayerContentProvider::setIsReady(VfxBool isReady)
{
    m_ctrlPLSV->setIsReady(isReady);
}

VfxBool VappMusicPlayerContentProvider::getIsReady(void)
{
    return m_ctrlPLSV->getIsReady();
}

void VappMusicPlayerContentProvider::setListMenu(VappMusicPlayerListMenu *listmenu)
{
    m_listMenu = listmenu;
}

VfxBool VappMusicPlayerContentProvider::isUsingMediaCache()
{
    VfxBool isUsingMC =  m_currentView == VIEW_TYPE_ALBUM
                      || m_currentView == VIEW_TYPE_ARTIST_ALBUM
                      || m_currentView == VIEW_TYPE_PLAYLIST_ADD_ALBUM
                      || m_currentView == VIEW_TYPE_COVER_FLOW;

    return isUsingMC;
}

void VappMusicPlayerContentProvider::onMediaCacheDecodeResultHandler(VfxU32 index, DecodeResult result, VfxImageBuffer imgBuf, void *user_data)
{
    VappMusicPlayerContentProvider *pThis = reinterpret_cast<VappMusicPlayerContentProvider*>(user_data);
    if (pThis)
    {
        vfxPostInvoke4(pThis, &VappMusicPlayerContentProvider::doMediaCacheDecodeResultHandler, index, result, imgBuf, user_data);
    }
}

void VappMusicPlayerContentProvider::doMediaCacheDecodeResultHandler(VfxU32 index, DecodeResult result, VfxImageBuffer imgBuf, void *user_data)
{
    const VfxBool isCorrectView = isUsingMediaCache();
    if (!isCorrectView)
    {
        return;
    }

    VfxU32 itemIndex = getViewType() == VIEW_TYPE_ARTIST_ALBUM ? index + 1 : index;

    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerApp);

    if (result == GDI_OK)
    {
#ifdef __COSMOS_MUSICPLY_COVER_FLOW__
        // update decoded cell
        if (m_currentView == VIEW_TYPE_COVER_FLOW)
        {
            if (app->getCoverFlow())
            {
#ifdef __COSMOS_3D_V10__
                app->getCoverFlow()->updateCellImage(index, imgBuf);
#else
				app->getCoverFlow()->updateCellImage(index, imgBuf);
#endif
            }
        }
        else 
#endif // __COSMOS_MUSICPLY_COVER_FLOW__
        if(isUsingMediaCache())
        {
            app->updateContent(itemIndex, VFX_FALSE, VFX_FALSE);
        }
    }
#ifdef __COSMOS_MUSICPLY_COVER_FLOW__
    else
    {
        // have no album cover
        if (m_currentView == VIEW_TYPE_COVER_FLOW)
        {
            if (app->getCoverFlow())
            {
                app->getCoverFlow()->updateCellInfo(index);
            }
        }
    }
#endif // __COSMOS_MUSICPLY_COVER_FLOW__

    vfxPostInvoke0(this, &VappMusicPlayerContentProvider::getNextItemImage);
}

void VappMusicPlayerContentProvider::getNextItemImage()
{
    // find next non_proc cell to do lock buffer
    VcpMenuRegion region = getCellRange();

    const VfxS32 count = VfxS32(getCount());
    if ((count > 0) && (region.begin.pos >= 0) && (region.end.pos >= 0))
    {
        VfxU32 startIndex = region.begin.pos;
        VfxU32 lastIndex = region.end.pos;

        // find next task to decode
        VfxU32 nextIdx = 0;
        VfxBool foundNextTask = m_ctrlMediaCache->findNextNoneProcTask(startIndex, lastIndex, nextIdx);
        //kal_prompt_trace(MOD_MMI_MEDIA_APP, "[MUSICPLY] VappMusicPlayerContentProvider::getNextItemImage(), found=[%d] index=[%d] start=[%d] end=[%d]", foundNextTask, nextIdx, startIndex, lastIndex);

        if (foundNextTask)
        {
            VfxImageBuffer imageBuffer;
            DecodeResult decResult = m_ctrlMediaCache->getImageBuffer(nextIdx, imageBuffer, VFX_TRUE);

            VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerApp);

            if (decResult == DECODING)
            {
                // waiting for decoding
                return;
            }
            else if (decResult == MC_OK)
            {
                // get image buffer on lock buffer, update item and process the next one
               
#ifdef __COSMOS_MUSICPLY_COVER_FLOW__
                if (m_currentView == VIEW_TYPE_COVER_FLOW)
                {
                    if (app->getCoverFlow())
                    {
#ifdef __COSMOS_3D_V10__
                        app->getCoverFlow()->updateCellImage(nextIdx, imageBuffer);
#else
						app->getCoverFlow()->updateCellImage(nextIdx, imageBuffer);
#endif
                    }
                }
                else 
#endif // __COSMOS_MUSICPLY_COVER_FLOW__
                if(isUsingMediaCache())
                {
                    VfxU32 itemIndex = m_currentView == VIEW_TYPE_ARTIST_ALBUM ? nextIdx + 1 : nextIdx;
                    app->updateContent(itemIndex, VFX_FALSE, VFX_FALSE);
                }
            }
#ifdef __COSMOS_MUSICPLY_COVER_FLOW__
            else
            {
#ifndef __COSMOS_3D_V10__
                // have no album cover
                if (m_currentView == VIEW_TYPE_COVER_FLOW)
                {
                    if (app->getCoverFlow())
                    {
                        app->getCoverFlow()->updateCellInfo(nextIdx);
                    }
                }
#endif
            }
#endif // __COSMOS_MUSICPLY_COVER_FLOW__
            vfxPostInvoke0(this, &VappMusicPlayerContentProvider::getNextItemImage);
        }
    }
}

void VappMusicPlayerContentProvider::lockFirstVisibleCell()
{
    VfxImageBuffer imageBuffer;

    VcpMenuRegion region = getCellRange();
    
    VfxU32 index = (region.begin.isValid() && region.begin.pos >= 0) ? region.begin.pos : 0;
    
    m_ctrlMediaCache->getImageBuffer(index, imageBuffer);
}

VcpMenuRegion VappMusicPlayerContentProvider::getCellRange()
{
    VcpMenuRegion region;
    if (m_currentView == VIEW_TYPE_COVER_FLOW)
    {
        VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerApp);
        if (app->getCoverFlow())
        {
#ifdef __COSMOS_3D_V10__
            region = app->getCoverFlow()->m_menu->getRealContentRegion();
#else
            region = app->getCoverFlow()->m_menu->getRealContentRegion();
#endif
        }
    }
    else if (m_currentView == VIEW_TYPE_ALBUM
          || m_currentView == VIEW_TYPE_ARTIST_ALBUM
          || m_currentView == VIEW_TYPE_PLAYLIST_ADD_ALBUM)
    {
        if (m_listMenu)
        {
            region = m_listMenu->getRealContentRegion();
        }
    }

    if (m_currentView == VIEW_TYPE_ARTIST_ALBUM)
    {
        // Remapping list index to media cache index if in artist album view
        if(region.begin.pos != 0) region.begin.pos--;
        if(region.end.pos != 0)   region.end.pos--;
    }

    return region;
}

VfxBool VappMusicPlayerContentProvider::checkMediaCacheDecodeCellRange(VfxU32 index)
{
    VcpMenuRegion region = getCellRange();

    VfxS32 startIndex = region.begin.pos;
    VfxS32 lastIndex = region.end.pos;

    //kal_prompt_trace(MOD_MMI_MEDIA_APP, "[MUSICPLY] VappMusicPlayerContentProvider::checkMediaCacheDecodeCellRange(), index=[%d] start=[%d] end=[%d]", index, startIndex, lastIndex);

    if (index < startIndex || index > lastIndex)
    {
        return MMI_FALSE;    
    }

    return VFX_TRUE;
}

VfxU32 VappMusicPlayerContentProvider::getCount() const
{
    VfxU32 count = 0;
    switch (m_currentView)
    {
        case VIEW_TYPE_VIEW_SELECT:
            count = 3;
            break;

        case VIEW_TYPE_PLAYLIST_SELECT:
            // add one more item "New playlist" at the top
            count = m_ctrlPLSV->getCount() + 1;
            break;

        case VIEW_TYPE_ARTIST_ALBUM:
            // add one more item "All songs" at the top
            count = m_ctrlPLSV->getCount() + 1;
            break;

        default:    
            count = m_ctrlPLSV->getCount();
            break;
    };

    return count;
}

VfxU32 VappMusicPlayerContentProvider::getFixedCount(const ViewTypeEnum viewType, const VfxU32 index) const
{
    return m_ctrlPLSV->getFixedCount(viewType, index);
}

VcpListMenuCellClientBaseFrame* VappMusicPlayerContentProvider::getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame)
{
    VappMusicPlayerListMenu *listMenu = VFX_OBJ_DYNAMIC_CAST(parentFrame->getParent(), VappMusicPlayerListMenu);
    if (listMenu)
    {
        const ViewTypeEnum listMenuViewType = listMenu->m_viewType;
        const VfxBool isCustomStyle = listMenu->getIsCustomStyle();

        if (isCustomStyle)
        {
            if (listMenuViewType == VIEW_TYPE_ALBUM
             || listMenuViewType == VIEW_TYPE_ARTIST_ALBUM
             || listMenuViewType == VIEW_TYPE_PLAYLIST_ADD_ALBUM)
            {
                VappMusicPlayerAlbumListCell *cell = NULL;
                VFX_OBJ_CREATE(cell, VappMusicPlayerAlbumListCell, parentFrame);

                return cell;
            }
            else if (listMenuViewType == VIEW_TYPE_ALBUM_SONG
                  || listMenuViewType == VIEW_TYPE_ARTIST_ALBUM_SONG)   ///// add cover flow album song list also
            {
                VappMusicPlayerAlbumSongCell *cell = NULL;
                VFX_OBJ_CREATE(cell, VappMusicPlayerAlbumSongCell, parentFrame);
                cell->setSerial(index + 1);

                return cell;
            }
            else if (listMenuViewType == VIEW_TYPE_ARTIST)
            {
                VappMusicPlayerArtistListCell *cell = NULL;
                VFX_OBJ_CREATE(cell, VappMusicPlayerArtistListCell, parentFrame);

                return cell;
            }
            else
            {
                VappMusicPlayerSongListCell *cell = NULL;
                VFX_OBJ_CREATE(cell, VappMusicPlayerSongListCell, parentFrame);

                return cell;
            }
        }
    }

    return NULL;
}

VappMusicPlayerAlbumListCell* VappMusicPlayerContentProvider::getAlbumListCell(VfxU32 index)
{
    // The index here will be list menu index
    VcpListMenuCell *menuItem = m_listMenu->getCell(index);
    if (menuItem)
    {
        VappMusicPlayerAlbumListCell *cell = VFX_OBJ_DYNAMIC_CAST(menuItem->m_clientFrame, VappMusicPlayerAlbumListCell);
        return cell;
    }
    return NULL;
}

void VappMusicPlayerContentProvider::setAlbumListCellBorder(const VfxU32 index, const VfxBool hasBorder)
{
    if(m_currentView != VIEW_TYPE_COVER_FLOW)
    {
        VappMusicPlayerAlbumListCell *cell = getAlbumListCell(index);
        if (!hasBorder || (hasBorder && cell))
        {
            doSetAlbumListCellBorder(index, hasBorder);
        }
        else
        {
            // Use post invoke because sometime the custom frame not create yet
            vfxPostInvoke2(this, &VappMusicPlayerContentProvider::doSetAlbumListCellBorder, index, VFX_TRUE);
        }
    }
}

void VappMusicPlayerContentProvider::doSetAlbumListCellBorder(const VfxU32 index, const VfxBool hasBorder)
{
    // The index here will be list menu index
    VappMusicPlayerAlbumListCell *cell = getAlbumListCell(index);
    if (cell)
    {
        cell->enableImageBorder(hasBorder);
    }
}

VappMusicPlayerAlbumSongCell* VappMusicPlayerContentProvider::getAlbumSongCell(VfxU32 index)
{
    VcpListMenuCell *menuItem = m_listMenu->getCell(index);
    if (menuItem)
    {
        VappMusicPlayerAlbumSongCell *cell = VFX_OBJ_DYNAMIC_CAST(menuItem->m_clientFrame, VappMusicPlayerAlbumSongCell);
        return cell;
    }
    return NULL;
}

void VappMusicPlayerContentProvider::setAlbumSongCellColor(VfxU32 index, VfxBool isHighLight)
{
    VappMusicPlayerAlbumSongCell *cell = getAlbumSongCell(index);
    if (cell)
    {
        cell->setIsPlaying(isHighLight);
    }
}

void VappMusicPlayerContentProvider::closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame *pCell)
{
    VFX_OBJ_CLOSE(pCell);
}

VfxBool VappMusicPlayerContentProvider::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    return getItemTextEx(index, fieldType, text, color, VFX_FALSE, VFX_TRUE);
}

VfxBool VappMusicPlayerContentProvider::getItemTextEx(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color, VfxBool isScrolling, VfxBool isCellLoad)
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        
        switch (m_currentView)
        {
            case VIEW_TYPE_ALL_SONGS:
            case VIEW_TYPE_ARTIST_SONG:
            case VIEW_TYPE_ARTIST_ALBUM_SONG:
            case VIEW_TYPE_ALBUM_SONG:
            case VIEW_TYPE_PLAYLIST_SONG:
            case VIEW_TYPE_PLAYLIST_ADD_ALL_SONG:
            case VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG:
            case VIEW_TYPE_PLAYLIST_ADD_ALBUM_SONG:
            case VIEW_TYPE_NOW_PLAYING_LIST:
            case VIEW_TYPE_COVER_FLOW_SONG:
                {
                    VfxId ID = getID(index);

                    if (ID != m_listItemCache.ID || index != m_listItemCache.index)
                    {
                        if(m_currentView == VIEW_TYPE_ALL_SONGS && isScrolling && !isCellLoad)
                        {
                            m_listItemCache.hasInfo = getDetailInfoTitleOnly(index, &m_listItemCache.info);
                            m_listItemCache.titleOnly = VFX_TRUE;
                        }
                        else
                        {
                            m_listItemCache.hasInfo = getDetailInfo(index, &m_listItemCache.info);
                            m_listItemCache.titleOnly = VFX_FALSE;
                        }
                        m_listItemCache.ID = ID;
                        m_listItemCache.index = index;
                    }

                    if(m_listItemCache.hasInfo)
                    {
                        text.loadFromMem(m_listItemCache.info.title);
                    }
                    else
                    {
                        text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_SONG);
                    }

                    if (m_showPlayIcon && m_activeID == ID)
                    {
                        if (checkHighLight(index))
                        {
                            color = VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT;
                        }
                        else
                        {
                            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                        }
                    }

                    if (m_currentView == VIEW_TYPE_ARTIST_ALBUM_SONG || m_currentView == VIEW_TYPE_ALBUM_SONG)
                    {
                        if (m_showPlayIcon && m_activeID == ID)
                        {
                            vfxPostInvoke2(this, &VappMusicPlayerContentProvider::setAlbumSongCellColor, index, VFX_TRUE);
                        }
                        else
                        {
                            vfxPostInvoke2(this, &VappMusicPlayerContentProvider::setAlbumSongCellColor, index, VFX_FALSE);
                        }                       
                    }
                }   
                break;

            case VIEW_TYPE_PLAYLIST:
                if (isSelectStart())
                {
                    if (index == 0)
                    {
                        text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TITLE_FAVORITE);
                    }
                    else
                    {
                        getTitle(index, text);
                    }
                }
                else
                {
                    getTitle(index, text);
                }
                break;

            case VIEW_TYPE_ARTIST:
            case VIEW_TYPE_ALBUM:
            case VIEW_TYPE_PLAYLIST_ADD_ARTIST:
            case VIEW_TYPE_PLAYLIST_ADD_ALBUM:
            case VIEW_TYPE_COVER_FLOW:
                getTitle(index, text);
                break;

            case VIEW_TYPE_ARTIST_ALBUM:
                if (index == 0)
                {
                    text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_ALL_SONGS);
                }
                else
                {
                    getTitle(index-1, text);
                }
                break;

            case VIEW_TYPE_PLAYLIST_SELECT:
                if (index == 0)
                {
                    text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_NEW_PLAYLIST);
                }
                else
                {
                    getTitle(index-1, text);
                }
                break;

            case VIEW_TYPE_VIEW_SELECT:
                if (index == 0)
                {
                    text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TAB_SONG);
                }
                else if (index == 1)
                {
                    text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TAB_ARTIST);
                }
                else if (index == 2)
                {
                    text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TAB_ALBUM);
                }
                else
                {
                    // no such case
                    text.format("Unknown");
                    //VFX_ASSERT(!"[VappMusicPlayerPage::getItemText()] VIEW_TYPE_VIEW_SELECT");
                }
                break;
            
            case VIEW_TYPE_NOW_PLAYING:
            case VIEW_TYPE_SETTING:
            case VIEW_TYPE_SETTING_SOUND_EFFECT:
                text.format("");
                break;

            default:
                VFX_ASSERT(!"[VappMusicPlayerPage::getItemText()] Undefine view type");
                break;
        }

    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        
        switch (m_currentView)
        {
            case VIEW_TYPE_ALL_SONGS:
            case VIEW_TYPE_ARTIST_SONG:
            case VIEW_TYPE_ARTIST_ALBUM_SONG:
            case VIEW_TYPE_ALBUM_SONG:
            case VIEW_TYPE_PLAYLIST_SONG:
            case VIEW_TYPE_PLAYLIST_ADD_ALL_SONG:
            case VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG:
            case VIEW_TYPE_PLAYLIST_ADD_ALBUM_SONG:
            case VIEW_TYPE_NOW_PLAYING_LIST:
                {
                    if(m_currentView == VIEW_TYPE_ALL_SONGS && isScrolling && !isCellLoad)
                    {
                        text.format("");
                    }
                    else
                    {
                        VfxId ID = getID(index);
                        
                        if (ID != m_listItemCache.ID || index != m_listItemCache.index || m_listItemCache.titleOnly)
                        {
                            m_listItemCache.hasInfo = getDetailInfo(index, &m_listItemCache.info);
                            m_listItemCache.ID = ID;
                            m_listItemCache.index = index;
                            m_listItemCache.titleOnly = VFX_FALSE;
                        }

                        if(m_listItemCache.hasInfo)
                        {
                            if (m_currentView == VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG)
                            {
                                text.loadFromMem(m_listItemCache.info.album);
                            }
                            else
                            {
                                text.loadFromMem(m_listItemCache.info.artist);
                            }
                        }
                        else
                        {
                            if (m_currentView == VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG)
                            {
                                text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_ALBUM);
                            }
                            else
                            {
                                text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_ARTIST);
                            }
                        }

                        if (m_showPlayIcon && m_activeID == ID)
                        {
                            if (checkHighLight(index))
                            {
                                color = VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT;
                            }
                            else
                            {
                                color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
                            }
                        }
                    }
                }                   
                break;
            
            case VIEW_TYPE_ARTIST:
            case VIEW_TYPE_PLAYLIST_ADD_ARTIST:
                {
                    if(isScrolling && !isCellLoad)
                    {
                       text.format("");
                    }
                    else
                    {
                        VfxU32 albumCount = m_ctrlPLSV->getHintCount(index, SRV_PLST_VIEW_ALBUM);
                        text.format("%d ", albumCount);
                        if (albumCount > 1)
                        {
                            text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_ALBUMS);
                        }
                        else
                        {
                            text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_ALBUM);
                        }
                        VfxU32 songCount = m_ctrlPLSV->getHintCount(index, SRV_PLST_VIEW_MEDIA);
                        VfxWString textSong;
                        textSong.format(" %d ", songCount);
                        if (songCount > 1)
                        {
                            textSong += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONGS);
                        }
                        else
                        {
                            textSong += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONG);
                        }
                        text += textSong;
                    }
                }
                break;

            case VIEW_TYPE_ALBUM:
            case VIEW_TYPE_PLAYLIST_ADD_ALBUM:
            {
                    if(isScrolling && !isCellLoad)
                    {
                       text.format("");
                    }
                    else
                    {
                        VfxId ID = getID(index);

                        m_ctrlPLSV->getAlbumArtistName(ID, text);

                        VfxU32 count = m_ctrlPLSV->getHintCount(index, SRV_PLST_VIEW_MEDIA);
                        VfxWString textSong;
                        textSong.format("   %d ", count);
                        if (count > 1)
                        {
                            textSong += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONGS);
                        }
                        else
                        {
                            textSong += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONG);
                        }
                        text += textSong;
                    }
                }
                break;

            case VIEW_TYPE_COVER_FLOW:
                {
                    VfxId ID = getID(index);
                    
                    m_ctrlPLSV->getAlbumArtistName(ID, text);

#ifndef __COSMOS_3D_V10__
                    VfxU32 count = m_ctrlPLSV->getHintCount(index, SRV_PLST_VIEW_MEDIA);
                    VfxWString textSong;
                    textSong.format("   %d ", count);
                    if (count > 1)
                    {
                        textSong += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONGS);
                    }
                    else
                    {
                        textSong += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONG);
                    }
                    text += textSong;
#endif
                }
                break;

            case VIEW_TYPE_COVER_FLOW_SONG:
                {
                    VfxId ID = getID(index);
                    
                    if (ID != m_listItemCache.ID || index != m_listItemCache.index || m_listItemCache.titleOnly)
                    {
                        m_listItemCache.hasInfo = getDetailInfo(index, &m_listItemCache.info);
                        m_listItemCache.ID = ID;
                        m_listItemCache.index = index;
                        m_listItemCache.titleOnly = VFX_FALSE;
                    }

                    if(m_listItemCache.hasInfo && m_listItemCache.info.duration > 0)
                    {
                        text.format("%d:%02d", m_listItemCache.info.duration/(60), m_listItemCache.info.duration%(60));
                    }
                    else
                    {
                        text.format("0:00");
                    }
                    
                    if (m_showPlayIcon && m_activeID == ID)
                    {
                        color = VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT;
                    }
                    else
                    {
                        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
                    }
                    break;
                }

            case VIEW_TYPE_PLAYLIST:
                {
                    if (isSelectStart())
                    {
                        if (index == 0)
                        {
                            text = m_myFavHint; 
                        }
                        else
                        {
                            VfxU32 count = m_ctrlPLSV->getHintCount(index, SRV_PLST_VIEW_MEDIA);
                            text.format("%d ", count);
                            if (count > 1)
                            {
                                text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONGS);
                            }
                            else
                            {
                                text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONG);
                            }
                        }
                    }
                    else
                    {
                        VfxU32 count = m_ctrlPLSV->getHintCount(index, SRV_PLST_VIEW_MEDIA);
                        text.format("%d ", count);
                        if (count > 1)
                        {
                            text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONGS);
                        }
                        else
                        {
                            text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONG);
                        }

                        if (index == 0)
                        {
                            m_myFavHint = text;
                        }
                    }
                }
                break;

            case VIEW_TYPE_PLAYLIST_SELECT:
                {
                    if (index == 0)
                    {
                        // "New playlist" item, no need to show sub info
                        text.format("");
                    }
                    else
                    {
                        VfxU32 count = m_ctrlPLSV->getHintCount(index-1, SRV_PLST_VIEW_MEDIA);
                        text.format("%d ", count);
                        if (count > 1)
                        {
                            text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONGS);
                        }
                        else
                        {
                            text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONG);
                        }
                    }
                }
                break;

            case VIEW_TYPE_ARTIST_ALBUM:
                {
                    VfxU32 count = 0;
                    if (index == 0)
                    {
                        // "All songs" item
                        count = static_cast<VappMusicPlayerApp*>(getParent())->getSelectItemCount();
                    }
                    else
                    {
                        count = m_ctrlPLSV->getHintCount(index-1, SRV_PLST_VIEW_MEDIA); 
                    }

                    text.format("%d ", count);
                    if (count > 1)
                    {
                        text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONGS);
                    }
                    else
                    {
                        text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONG);
                    }
                }
                break;

            case VIEW_TYPE_VIEW_SELECT:
                if (index == 0)
                {
                    VfxU32 count = m_ctrlPLSV->getHintCount(index, SRV_PLST_VIEW_AUDIO);
                    text.format("%d ", count);
                    if (count > 1)
                    {
                        text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONGS);
                    }
                    else
                    {
                        text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONG);
                    }
                }
                else if (index == 1)
                {
                    VfxU32 count = m_ctrlPLSV->getHintCount(index, SRV_PLST_VIEW_ARTIST);
                    text.format("%d ", count);
                    if (count > 1)
                    {
                        text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_ARTISTS);
                    }
                    else
                    {
                        text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_ARTIST);
                    }
                }
                else if (index == 2)
                {
                    VfxU32 count = m_ctrlPLSV->getHintCount(index, SRV_PLST_VIEW_ALBUM);
                    text.format("%d ", count);
                    if (count > 1)
                    {
                        text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_ALBUMS);
                    }
                    else
                    {
                        text += VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_ALBUM);
                    }
                }
                else
                {
                    // no such case
                    text.format("");
                    //VFX_ASSERT(!"[VappMusicPlayerPage::getItemText()] VIEW_TYPE_VIEW_SELECT");
                }
                break;

            default:
                text.format("");
                break;
        }

    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT2)
    {
        switch (m_currentView)
        {
            case VIEW_TYPE_ALL_SONGS:
            case VIEW_TYPE_ARTIST_SONG:
            case VIEW_TYPE_ARTIST_ALBUM_SONG:
            case VIEW_TYPE_ALBUM_SONG:
            case VIEW_TYPE_PLAYLIST_SONG:
            case VIEW_TYPE_PLAYLIST_ADD_ALL_SONG:
            case VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG:
            case VIEW_TYPE_PLAYLIST_ADD_ALBUM_SONG:
            case VIEW_TYPE_NOW_PLAYING_LIST:
            {   
                if(m_currentView == VIEW_TYPE_ALL_SONGS && isScrolling && !isCellLoad)
                {
                    text.format("");
                }
                else
                {
                    VfxId ID = getID(index);

                    if (ID != m_listItemCache.ID || index != m_listItemCache.index || m_listItemCache.titleOnly)
                    {
                        m_listItemCache.hasInfo = getDetailInfo(index, &m_listItemCache.info);
                        m_listItemCache.ID = ID;
                        m_listItemCache.index = index;
                        m_listItemCache.titleOnly = VFX_FALSE;
                    }

                    if(m_listItemCache.hasInfo && m_listItemCache.info.duration > 0)
                    {
                        text.format("%d:%02d", m_listItemCache.info.duration/(60), m_listItemCache.info.duration%(60));
                    }
                    else
                    {
                        text.format("0:00");
                    }

                    if (checkHighLight(index))
                    {
                        color = VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT;
                    }
                    else
                    {
                        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
                    }
                }
                break;
            }
            default:
                text.format("");
                break;
        }       
    }
    
    return VFX_TRUE;
}

VfxBool VappMusicPlayerContentProvider::getItemTextFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VcpRichText &format, VfxBool isScroll)
{
    if (isSearching() && ((m_currentView == VIEW_TYPE_ALL_SONGS) || (m_currentView == VIEW_TYPE_ARTIST) || (m_currentView == VIEW_TYPE_ALBUM)))
    {
        if (isScroll)
        {
            return VFX_FALSE;
        }
        
        if(fieldType == VCP_LIST_MENU_FIELD_TEXT && m_searchText.getLength() > 0)
        {
            VfxWString title;
            VcpListMenuTextColorEnum color;
            getItemText(index, VCP_LIST_MENU_FIELD_TEXT, title, color);

            // the string of "title" is load from Res
            VfxWString title2;
            title2.loadFromMem(title.getBuf());
            
            VfxWChar *pSearchText = mmi_wcsupr(const_cast<VfxWChar*>(m_searchText.getBuf()));
            VfxWChar *pTargetText = mmi_wcsupr(const_cast<VfxWChar*>(title2.getBuf()));
            VfxWChar *pStr = mmi_wcsstr(pTargetText, pSearchText);
            VfxBool flag = VFX_FALSE;
            if (pStr != NULL)
            {
                const VfxU32 titleLength = title2.getLength();
                VfxU32 pStrLength = mmi_ucs2strlen((const CHAR *)pStr);

                // if the substring is not start from the first
                if (pStrLength != titleLength)
                {
                    // if previous character is not " ", for example: search "o" in "Copy of a book", use " o" to search again
                    if (checkIsASCIIChar(pStr-1) && checkIsASCIIChar(pStr) && vfx_sys_wcsncmp(const_cast<const VfxWChar*>(pStr-1), (VfxWChar*)" ", 1))
                    {
                        VfxWString newSearchText;
                        newSearchText.format(" ");
                        newSearchText += m_searchText;
                        pSearchText = mmi_wcsupr(const_cast<VfxWChar*>(newSearchText.getBuf()));
                        pStr = mmi_wcsstr(pTargetText, pSearchText);
                        flag = VFX_TRUE;
                    }
                }

                if (pStr != NULL)
                {
                    pStrLength = mmi_ucs2strlen((const CHAR *)pStr);
                    VfxS32 hlIndex = titleLength - pStrLength + (flag ? 1 : 0);
                    format.setRange(hlIndex, hlIndex + m_searchText.getLength());
                    format.setTextBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_SEARCH));
                    format.setTextColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
                    //format.setTextColor(VfxColor(VFX_COLOR_RED));
                    format.setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_MEDIUM));
                    return VFX_TRUE;
                }
            }
        }
    }
    return VFX_FALSE;
}

VfxBool VappMusicPlayerContentProvider::getItemTextFrameFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxTextFrame *frame)
{
    VcpListMenuCell *cell = m_listMenu->getCell(index);
    if (m_listMenu && cell)
    {
        VfxId ID = 0;
        
        if (isSongView())
        {
            ID = getID(index);
        }

        if (m_showPlayIcon && m_activeID == ID && checkHighLight(index))
        {
            frame->setColor(cell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT));

            return VFX_TRUE;
        }
        else
        {
            if(fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1 || fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT2)
            {
                frame->setColor(cell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT));
            }
            else
            {
                frame->setColor(cell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_NORMAL));
            }

            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}

VfxBool VappMusicPlayerContentProvider::getTitle(VfxU32 index, VfxWString &title)
{
    if (!m_ctrlPLSV->getIsReady())
    {
        title.format("Unknown");
        return VFX_FALSE;
    }

    U32* buffer = NULL;
    VFX_ALLOC_MEM(buffer, sizeof(U32)*SRV_PLST_META_INFO_MAX_LEN, this);

    srv_plst_list_get_display_struct displayStruct;
    displayStruct.index = index;
    displayStruct.buff_size = SRV_PLST_META_INFO_MAX_LEN - 1;
    displayStruct.string_ptr = (U32)buffer;

    VfxBool result = m_ctrlPLSV->getTitle(index, displayStruct);

    if ((m_currentView == VIEW_TYPE_PLAYLIST || m_currentView == VIEW_TYPE_PLAYLIST_SELECT)
     && !mmi_wcscmp((WCHAR*)displayStruct.string_ptr, (WCHAR*)L""))
    {
        VfxU32 playlistType = m_ctrlPLSV->getDefaultPlaylistType(index);
        switch (playlistType)
        {
            case SRV_PLST_DEF_MY_FAVOURITE:
                title.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TITLE_FAVORITE);
                break;

            default:
                title.format("Unknown Playlist");
                break;
        };
    }
    else
    {
        title.loadFromMem(reinterpret_cast<VfxWChar*>(displayStruct.string_ptr));
    }

    VFX_FREE_MEM(buffer);
    buffer = NULL;

    return result;
}

VfxBool VappMusicPlayerContentProvider::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image)
{
    switch (fieldType)
    {
        case VCP_LIST_MENU_FIELD_DISCLOSURE_IMG:
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
            break;

        case VCP_LIST_MENU_FIELD_HIGHLIGHT_DISCLOSURE_IMG:
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_HIGHLIGHT_DISCLOSURE);
            return VFX_FALSE;

        case VCP_LIST_MENU_FIELD_ICON:
            if (m_currentView == VIEW_TYPE_VIEW_SELECT)
            {
                switch (index)
                {
                    case 0:
                        image.setResId(IMG_ID_VAPP_MUSICPLY_LIST_SONG);
                        break;
                    case 1:
                        image.setResId(IMG_ID_VAPP_MUSICPLY_LIST_ARTIST);
                        break;
                    case 2:
                        image.setResId(IMG_ID_VAPP_MUSICPLY_LIST_ALBUM);
                        break;
                    default:
                        break;
                };
            }
            else if (m_currentView == VIEW_TYPE_ALBUM
                  || m_currentView == VIEW_TYPE_ARTIST_ALBUM
                  || m_currentView == VIEW_TYPE_PLAYLIST_ADD_ALBUM
                  || m_currentView == VIEW_TYPE_COVER_FLOW)
            {
                VfxU32 itemIndex = index;

                // First check, return default image if media cache view type is NONE or doesn't match
                // 1st condition: currentView != curMediaCacheView, except currentView == ALBUM && curMediaCacheView == PLAYLIST_ADD_ALBUM (or reverse)
                // 2nd condition: currentView == curMediaCacheView == ARTIST_ALBUM, but not the same artist
                if ((m_currentView != m_curMediaCacheView && !((m_currentView == VIEW_TYPE_ALBUM && m_curMediaCacheView == VIEW_TYPE_PLAYLIST_ADD_ALBUM) || (m_currentView == VIEW_TYPE_PLAYLIST_ADD_ALBUM && m_curMediaCacheView == VIEW_TYPE_ALBUM)))
                 || (m_currentView == VIEW_TYPE_ARTIST_ALBUM && m_curMediaCacheView == VIEW_TYPE_ARTIST_ALBUM && m_curMediaCacheArtistIdx != m_curArtistIdx))
                {
                    if (m_currentView == VIEW_TYPE_ARTIST_ALBUM && index == 0)
                    {
                        // the item "All songs" has no field icon
                        return VFX_TRUE;
                    }

                    image.setResId(getDefaultAlbumCover(m_currentView));

                    setAlbumListCellBorder(index, VFX_FALSE);

                    return VFX_TRUE;
                }

                if (m_currentView == VIEW_TYPE_ARTIST_ALBUM)
                {
                    // consider the first item in artist's album view is "All songs of artist"
                    if (index == 0)
                    {
                        return VFX_TRUE;
                    }
                    else
                    {
                        itemIndex--;
                    }
                }

                MediaCacheTask task = m_ctrlMediaCache->getTask(itemIndex);
                if (task.m_state == MediaCacheTask::NO_THUMB || task.m_state == MediaCacheTask::PROCESSING)
                {
                    // has no album cover
                    image.setResId(getDefaultAlbumCover(m_currentView));
                    setAlbumListCellBorder(index, VFX_FALSE);
                }
                else if (task.m_state == MediaCacheTask::HAS_THUMB)
                {
                    VfxImageBuffer imageBuffer;
                    DecodeResult result = m_ctrlMediaCache->getImageBuffer(itemIndex, imageBuffer);

                    if (result == MC_OK)
                    {
                        image.setImageBuffer(imageBuffer);
                        // Use "index" here because it is list menu index
                        setAlbumListCellBorder(index, VFX_TRUE);
                    }
                    else
                    {
                        image.setResId(getDefaultAlbumCover(m_currentView, VFX_TRUE));
                        setAlbumListCellBorder(index, VFX_FALSE);                        
                    }
                }
                else if (task.m_state == MediaCacheTask::DRM_THUMB)
                {
                    image.setResId(getDefaultAlbumCover(m_currentView, VFX_TRUE));
                    setAlbumListCellBorder(index, VFX_FALSE);                    
                }
                else // NONE_PROC || BUSY
                {
                    // not processed before
                    // get image from ctrlMediaCache
                    VfxImageBuffer imageBuffer;
                    // Use "itemIndex" here because it is media cache index
                    DecodeResult result = m_ctrlMediaCache->getImageBuffer(itemIndex, imageBuffer);
                    if (result == MC_OK)
                    {
                        image.setImageBuffer(imageBuffer);
                        setAlbumListCellBorder(index, VFX_TRUE);
                    }
                    else if (result == DRM_LOCKED)
                    {
                        image.setResId(getDefaultAlbumCover(m_currentView, VFX_TRUE));
                        task.m_state = MediaCacheTask::DRM_THUMB;
                        setAlbumListCellBorder(index, VFX_FALSE);                        
                    }
                    else if (result == FORMAT_UNSUPPORTED || result == UNEXPECTED)
                    {
                        image.setResId(getDefaultAlbumCover(m_currentView));
                        task.m_state = MediaCacheTask::NO_THUMB;
                        setAlbumListCellBorder(index, VFX_FALSE);                        
                    }
                    else if (result == DECODING)
                    {
                        image.setResId(getDefaultAlbumCover(m_currentView));
                        task.m_state = MediaCacheTask::PROCESSING;
                        setAlbumListCellBorder(index, VFX_FALSE);                        
                    }
                    else // result == BUSY || result == MC_NOT_READY
                    {
                        image.setResId(getDefaultAlbumCover(m_currentView));
                        setAlbumListCellBorder(index, VFX_FALSE);                        
                    }
                }
            }
            else if (m_currentView == VIEW_TYPE_COVER_FLOW_SONG)
            {
                MediaCacheTask task = m_ctrlMediaCache->getTask(index);
                if (task.m_state == MediaCacheTask::HAS_THUMB)
                {
                    image.setImageBuffer(task.m_imageBuffer);
                }
                else
                {
                    image.setResId(getDefaultAlbumCover(m_currentView));
                }
            }
            break;

        case VCP_LIST_MENU_FIELD_ICON_EXTRA2:
            {
                switch (m_currentView)
                {
                    case VIEW_TYPE_ALL_SONGS:
                    case VIEW_TYPE_ARTIST_SONG:
                    case VIEW_TYPE_ARTIST_ALBUM_SONG:
                    case VIEW_TYPE_ALBUM_SONG:
                    case VIEW_TYPE_PLAYLIST_SONG:
                    case VIEW_TYPE_PLAYLIST_ADD_ALL_SONG:
                    case VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG:
                    case VIEW_TYPE_PLAYLIST_ADD_ALBUM_SONG:
                    case VIEW_TYPE_NOW_PLAYING_LIST:
                    case VIEW_TYPE_COVER_FLOW_SONG:
            
                        if (checkHighLight(index))
                        {
                            image.setResId(IMG_ID_VAPP_MUSICPLY_LIST_PLAYING);
                        }
                        break;

                    default:
                        return VFX_FALSE;
                }
            }
            break;
    };
    
    return VFX_TRUE;
}

VfxResId VappMusicPlayerContentProvider::getDefaultAlbumCover(ViewTypeEnum viewType, VfxBool isDRM)
{
    if (m_currentView == VIEW_TYPE_COVER_FLOW || m_currentView == VIEW_TYPE_COVER_FLOW_SONG)
    {
#ifdef __LOW_COST_SUPPORT_COMMON__
    return IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER_BG;
#else
        ///// use DRM icon
#ifdef __COSMOS_3D_V10__
        return isDRM ? IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER_NO_TEXT : IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER_NO_TEXT;
#else
        return isDRM ? IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER : IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER;
#endif
#endif
    }
    else
    {
        ///// use DRM icon
        return isDRM ? IMG_ID_VAPP_MUSICPLY_LIST_ALBUM : IMG_ID_VAPP_MUSICPLY_LIST_ALBUM;
    }
}

void VappMusicPlayerContentProvider::closeItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc Image)
{
    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        MediaCacheTask task = m_ctrlMediaCache->getTask(index);
        m_ctrlMediaCache->freeImageBuffer(task.m_imageBuffer.ptr, index);
    }
}

VcpListMenuItemStateEnum VappMusicPlayerContentProvider::getItemState(VfxU32 index) const
{ 
    if (index == 0 && (m_currentView == VIEW_TYPE_PLAYLIST || m_currentView == VIEW_TYPE_ARTIST_ALBUM))
    {
        // "Favorites" and "All songs" should not be selected for deletion
        return VCP_LIST_MENU_ITEM_STATE_NONE;
    }
    else if (m_isSelectStart && (m_currentView == VIEW_TYPE_ARTIST_ALBUM))
    {
        if (index == 0)
        {
            return VCP_LIST_MENU_ITEM_STATE_NONE;   
        }
        else
        {
            if (m_selectingState && m_selectingState[index - 1])
            {
                return VCP_LIST_MENU_ITEM_STATE_SELECTED;
            }
            else
            {
                return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
            }   
        }
    }
    else if (m_currentView == VIEW_TYPE_PLAYLIST_SELECT)
    {
        VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerApp);
        if (0 < index && index == app->getSelectItemIdx() + 1)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }
    else
    {
        if (m_selectingState && m_selectingState[index])
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }
}

VfxBool VappMusicPlayerContentProvider::getItemIsDisabled(VfxU32 index) const
{
    if (m_isSelectStart && index == 0 && (m_currentView == VIEW_TYPE_PLAYLIST || m_currentView == VIEW_TYPE_ARTIST_ALBUM))
    {
        // Favorite should be disabled during selecting for deletion
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

VfxBool VappMusicPlayerContentProvider::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color) 
{
    switch (m_currentView)
    {
        case VIEW_TYPE_ALL_SONGS:
        case VIEW_TYPE_ARTIST:
        case VIEW_TYPE_ALBUM:
            if(m_ctrlPLSV->isWaitSearchResult())
            {
                text.loadFromRes(STR_GLOBAL_SEARCHING);
            }
            else if (isSearching())
            {
                text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_SEARCH_NO_RESULT);
            }
            else
            {
                VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerApp);
                if (app && app->getActionMode() == ACTION_LAUNCHING)
                {
                    return VFX_TRUE;
                }               
                text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_NO_SONG);
            }
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
            break;

        case VIEW_TYPE_PLAYLIST_SONG:
        case VIEW_TYPE_PLAYLIST_ADD_ALL_SONG:
        case VIEW_TYPE_PLAYLIST_ADD_ARTIST:
        case VIEW_TYPE_PLAYLIST_ADD_ALBUM:
            text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_PLAYLIST_NO_SONG);
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
            break;

        case VIEW_TYPE_NOW_PLAYING:
        case VIEW_TYPE_NOW_PLAYING_LIST:
            text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_NO_SONG_PLAYING);
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
            break;
    }
    
    return VFX_TRUE;
}

VfxBool VappMusicPlayerContentProvider::checkHighLight(VfxU32 index)
{
    if (!isSongView())
    {
        return VFX_FALSE;
    }

    VfxBool showIcon = VFX_FALSE;

    if (m_showPlayIcon)
    {
        VfxId ID = getID(index);
        if (m_activeID == ID)
        {
            if (m_currentView == VIEW_TYPE_PLAYLIST_SONG)
            {
                VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerApp);
                if (m_hlInfo.viewType == VIEW_TYPE_PLAYLIST_SONG && app->getSelectItemId() == m_hlInfo.plstID)
                {
                    // in the playlist that start the playback, high light song with correct index
                    if (index == getActiveIndex())
                    {
                        if (index != m_hlInfo.hlIdx)
                        {
                            m_hlInfo.preHlIdx = m_hlInfo.hlIdx;
                            m_hlInfo.hlIdx = index;
                        }
                        showIcon = VFX_TRUE;
                    }
                }
                else
                {
                    // do not show high light if playback is started from different playlist

                    /*
                    // not the playlist that start the playback, high light the first found song
                    if (m_hlInfo.hlIdx == -1)
                    {
                        m_hlInfo.hlIdx = index;
                        showIcon = VFX_TRUE;
                    }
                    else if (m_hlInfo.hlIdx == index)
                    {
                        showIcon = VFX_TRUE;
                    }
                    */
                }
            }
            else if (m_currentView == VIEW_TYPE_NOW_PLAYING_LIST)
            {
                if (getActiveListType() == SRV_PLST_ACTIVE_LIST_AUDIO)
                {
                    if (index != m_hlInfo.hlIdx)
                    {
                        m_hlInfo.preHlIdx = m_hlInfo.hlIdx;
                        m_hlInfo.hlIdx = index;
                    }
                    showIcon = VFX_TRUE;
                }
                else
                {
                    if (index == getActiveIndex())
                    {
                        if (index != m_hlInfo.hlIdx)
                        {
                            m_hlInfo.preHlIdx = m_hlInfo.hlIdx;
                            m_hlInfo.hlIdx = index;
                        }
                        showIcon = VFX_TRUE;
                    }
                }
            }
            else
            {
                if (index != m_hlInfo.hlIdx)
                {
                    m_hlInfo.preHlIdx = m_hlInfo.hlIdx;
                    m_hlInfo.hlIdx = index;
                }
                showIcon = VFX_TRUE;
            }
        }
    }

    return showIcon;
}

VfxBool VappMusicPlayerContentProvider::isSongView()
{
    if (m_currentView == VIEW_TYPE_ALL_SONGS 
     || m_currentView == VIEW_TYPE_ARTIST_SONG 
     || m_currentView == VIEW_TYPE_ARTIST_ALBUM_SONG 
     || m_currentView == VIEW_TYPE_ALBUM_SONG 
     || m_currentView == VIEW_TYPE_PLAYLIST_SONG 
     || m_currentView == VIEW_TYPE_PLAYLIST_ADD_ALL_SONG 
     || m_currentView == VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG 
     || m_currentView == VIEW_TYPE_PLAYLIST_ADD_ALBUM_SONG 
     || m_currentView == VIEW_TYPE_NOW_PLAYING_LIST 
     || m_currentView == VIEW_TYPE_COVER_FLOW_SONG)
    {
        return VFX_TRUE;   
    }

    return VFX_FALSE;
}

VfxBool VappMusicPlayerContentProvider::isActiveView(ViewTypeEnum view)
{
    if (view == VIEW_TYPE_NOW_PLAYING_LIST)
    {
        return VFX_TRUE;
    }
    else if (view == VIEW_TYPE_PLAYLIST_SONG && m_hlInfo.viewType == VIEW_TYPE_PLAYLIST_SONG)
    {
        VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerApp);
        const VfxU32 plstID = app->getSelectItemId();
        return plstID == m_hlInfo.plstID;
    }
    else if (m_hlInfo.viewType == VIEW_TYPE_ALL_SONGS && view == VIEW_TYPE_PLAYLIST_ADD_ALL_SONG)
    {
        return VFX_TRUE;
    }
    else
    {
        return m_hlInfo.viewType == view;
    }
}

VfxU32 VappMusicPlayerContentProvider::getHighLightIndex()
{
    return m_hlInfo.hlIdx;
}

VfxU32 VappMusicPlayerContentProvider::getPreHighLightIndex()
{
    return m_hlInfo.preHlIdx;
}

VfxU32 VappMusicPlayerContentProvider::getHighLightPlayListId()
{
    return m_hlInfo.plstID;
}

void VappMusicPlayerContentProvider::resetHighLighIndex()
{
    m_hlInfo.hlIdx = -1;
    m_hlInfo.preHlIdx = -1;
}

void VappMusicPlayerContentProvider::setHighLighIndex(VfxS32 index)
{
    if (isActiveView(getViewType()))
    {
        m_hlInfo.hlIdx = index;
    }
    else
    {
        m_hlInfo.hlIdx = -1;
    }
}

void VappMusicPlayerContentProvider::setHighLightInfo(VfxU32 index)
{
    if (m_currentView == VIEW_TYPE_ALL_SONGS
     || m_currentView == VIEW_TYPE_ALBUM_SONG
     || m_currentView == VIEW_TYPE_ARTIST_SONG
     || m_currentView == VIEW_TYPE_ARTIST_ALBUM_SONG
     || m_currentView == VIEW_TYPE_PLAYLIST_SONG
     || m_currentView == VIEW_TYPE_NOW_PLAYING_LIST
     || m_currentView == VIEW_TYPE_COVER_FLOW_SONG)
    {
        m_activeID = getID(index);

        m_hlInfo.preHlIdx = -1;
        m_hlInfo.hlIdx = index;
    }
    else
    {
        SongInfoStruct info;
        m_mplayerSrv->getCurrInfo(info);
        m_activeID = info.id;
    }

    // store playlist index for high light comparing
    // no need to consider VIEW_TYPE_NOW_PLAYING_LIST, since it must be the same as the view started the playback
    if (m_currentView == VIEW_TYPE_PLAYLIST)
    {
        m_hlInfo.plstID = getID(index);
    }
    else if (m_currentView == VIEW_TYPE_PLAYLIST_SONG)
    {
        VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerApp);
        if (app)
        {
            m_hlInfo.plstID = app->getSelectItemId();
        }
    }
    
    switch (m_currentView)
    {
        case VIEW_TYPE_ALL_SONGS:
            m_hlInfo.viewType = VIEW_TYPE_ALL_SONGS;
            break;

        case VIEW_TYPE_ARTIST:
        case VIEW_TYPE_ARTIST_SONG:
            m_hlInfo.viewType = VIEW_TYPE_ARTIST_SONG;
            break;

        case VIEW_TYPE_ARTIST_ALBUM:
        case VIEW_TYPE_ARTIST_ALBUM_SONG:
            m_hlInfo.viewType = VIEW_TYPE_ARTIST_ALBUM_SONG;
            break;

        case VIEW_TYPE_ALBUM:
        case VIEW_TYPE_ALBUM_SONG:
            m_hlInfo.viewType = VIEW_TYPE_ALBUM_SONG;
            break;

        case VIEW_TYPE_PLAYLIST:
        case VIEW_TYPE_PLAYLIST_SONG:
            m_hlInfo.viewType = VIEW_TYPE_PLAYLIST_SONG;
            break;

        case VIEW_TYPE_NOW_PLAYING_LIST:
            // do not change the view type since active playlist is equal to the active view type
            break;

        case VIEW_TYPE_COVER_FLOW_SONG:
            m_hlInfo.viewType = VIEW_TYPE_COVER_FLOW_SONG;
            break;

        default:
            // should not happen
            m_hlInfo.viewType = VIEW_TYPE_NONE;
    }
}

void VappMusicPlayerContentProvider::updateHighLightInfo(SongInfoStruct &info, ViewTypeEnum activeView)
{
    m_activeID = info.id;

    m_hlInfo.preHlIdx = m_hlInfo.hlIdx;
    
    m_hlInfo.hlIdx = info.index;

    if (activeView != VIEW_TYPE_NONE)
    {
        m_hlInfo.viewType = activeView;
    }
}

HighLightInfoStruct VappMusicPlayerContentProvider::getHighLightInfo()
{
    return m_hlInfo;
}

VfxBool VappMusicPlayerContentProvider::swapItem(VfxU32 to, VfxU32 from)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTNT_PROVIDER_SWAP, from, to);

    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerApp);
    if (app)
    {
        const VfxU32 startIdx = app->getReorderStartIndex();
        if(startIdx != 0xFFFFFFFF)
        {
            // Do not swap item in every swap callback, only swap when it move over some range or change move direction
            if ((vfxAbs(VfxS32(to) - VfxS32(startIdx)) >= SRV_PLST_MAX_REORDER_STEP) ||
                (startIdx < from && to < from) ||
                (startIdx > from && to > from))
            {
                rearrangeSwapPos(startIdx, to);
                app->setReorderStartIndex(to);
            }
        }
    }

    return VFX_TRUE;
}

void VappMusicPlayerContentProvider::updateCount()
{
    m_ctrlPLSV->updateCount();
}

void VappMusicPlayerContentProvider::resetPLSV()
{
    m_currentView = VIEW_TYPE_NONE;
    m_ctrlPLSV->resetPLSV();
}

void VappMusicPlayerContentProvider::refreshDB()
{
    m_ctrlPLSV->refreshDB();
}

void VappMusicPlayerContentProvider::refreshDBCancel()
{
    m_ctrlPLSV->refreshDBCancel();
    onRefreshComplete();
}

void VappMusicPlayerContentProvider::resetDB()
{
    m_ctrlPLSV->resetDB();

    // Clear highlight
    m_hlInfo.viewType = VIEW_TYPE_NONE;
    m_hlInfo.plstID = -1;
    m_hlInfo.hlIdx = -1;
}

VfxResId VappMusicPlayerContentProvider::getErrorStrId(VfxS32 errorCode)
{
    return m_ctrlPLSV->getErrorStrId(errorCode);
}

void VappMusicPlayerContentProvider::onRefreshComplete()
{
    m_ctrlPLSV->clearTempBuffer();
}

void VappMusicPlayerContentProvider::selectStart()
{
    m_isSelectStart = VFX_TRUE;
    m_selectingCount = 0;

    // Allocate memory to store select state
    if(m_selectingState == NULL)
    {
        VfxU32 count = getCount();
        if (m_isSelectStart && m_currentView == VIEW_TYPE_ARTIST_ALBUM)
        {
            count--;
        }

        if (count > 0)
        {
            if(m_selectingState != NULL)
            {
                VFX_FREE_MEM(m_selectingState);
                m_selectingState = NULL;
            }

            VFX_ALLOC_MEM(m_selectingState, sizeof(VfxBool)*count, this);
            kal_mem_set(m_selectingState, 0, sizeof(VfxBool)*count);
        }
    }

    VfxTimer *t;
    VFX_OBJ_CREATE(t, VfxTimer, this);
    t->m_signalTick.connect(this, &VappMusicPlayerContentProvider::postProcSelectStart);
    t->setStartDelay(0);
    t->start();
}

void VappMusicPlayerContentProvider::postProcSelectStart(VfxTimer *t)
{
    m_ctrlPLSV->selectStart();
    VFX_OBJ_CLOSE(t);
}

void VappMusicPlayerContentProvider::selectEnd()
{
    m_isSelectStart = VFX_FALSE;
    m_selectingCount = 0;
    if(m_selectingState != NULL)
    {
        VFX_FREE_MEM(m_selectingState);
        m_selectingState = NULL;
    }

    m_ctrlPLSV->selectEnd();
}

void VappMusicPlayerContentProvider::selectAll()
{
    setAllSelectingState(VFX_TRUE);

    VfxTimer *t;
    VFX_OBJ_CREATE(t, VfxTimer, this);
    t->m_signalTick.connect(this, &VappMusicPlayerContentProvider::postProcSelectAll);
    t->setStartDelay(0);
    t->start();
}

void VappMusicPlayerContentProvider::deselectAll()
{
    setAllSelectingState(VFX_FALSE);

    VfxTimer *t;
    VFX_OBJ_CREATE(t, VfxTimer, this);
    t->m_signalTick.connect(this, &VappMusicPlayerContentProvider::postProcDeselectAll);
    t->setStartDelay(0);
    t->start();
}

void VappMusicPlayerContentProvider::postProcSelectAll(VfxTimer *t)
{
    m_ctrlPLSV->selectAll();
    VFX_OBJ_CLOSE(t);
}

void VappMusicPlayerContentProvider::postProcDeselectAll(VfxTimer *t)
{
    m_ctrlPLSV->deselectAll();
    VFX_OBJ_CLOSE(t);
}

VfxBool VappMusicPlayerContentProvider::isSelectStart()
{
    return m_isSelectStart;
}

VfxBool VappMusicPlayerContentProvider::isSelectAll()
{
    VfxU32 count = getCount();
    if (m_isSelectStart && (m_currentView == VIEW_TYPE_PLAYLIST || m_currentView == VIEW_TYPE_ARTIST_ALBUM))
    {
        count--;
    }

    return m_selectingCount == count;
}

VfxBool VappMusicPlayerContentProvider::isSelectNone()
{
    return m_selectingCount == 0;
}

VfxU32 VappMusicPlayerContentProvider::getSelectingCount()
{
    return m_selectingCount;
}

void VappMusicPlayerContentProvider::setSelectingState(VfxU32 idx, VfxBool isSelect)
{
    // Internal use only
    if (m_selectingState)
    {
        if (isSelect)
        {
            if (!m_selectingState[idx])
            {
                m_selectingCount++;
            }
        }
        else
        {
            if (m_selectingState[idx])
            {
                m_selectingCount--;
            }
        }
        m_selectingState[idx] = isSelect;
    }
}

void VappMusicPlayerContentProvider::setAllSelectingState(VfxBool isSelect)
{
    // Internal use only
    if (m_selectingState)
    {
        VfxU32 count = getCount();

        if (m_isSelectStart && m_currentView == VIEW_TYPE_ARTIST_ALBUM)
        {
            count--;
        }

        for (VfxU32 i = 0; i < count; i++)
        {
            m_selectingState[i] = isSelect;
        }
        
		if(m_currentView == VIEW_TYPE_PLAYLIST)
		{
		    m_selectingState[0] = VFX_FALSE;
			count--;
		}

        m_selectingCount = isSelect ? count : 0;
    }
}

VfxBool VappMusicPlayerContentProvider::getSelectingState(VfxU32 idx)
{
    if (m_selectingState && idx < getCount())
    {
        return m_selectingState[idx];
    }
    return VFX_FALSE;
}

void VappMusicPlayerContentProvider::select(VfxU32 index)
{
    if (!getSelectingState(index))
    {
        setSelectingState(index, VFX_TRUE);
        m_ctrlPLSV->select(index);
    }
}

void VappMusicPlayerContentProvider::deselect(VfxU32 index)
{
    if (getSelectingState(index))
    {
        setSelectingState(index, VFX_FALSE);
        m_ctrlPLSV->deselect(index);
    }
}

VfxBool VappMusicPlayerContentProvider::isSelected(VfxU32 index)
{
    return m_ctrlPLSV->isSelected(index);
}

void VappMusicPlayerContentProvider::del(VfxU32 index)
{
    m_ctrlPLSV->del(index);
}

void VappMusicPlayerContentProvider::delSelected()
{
    m_ctrlPLSV->delSelected();
}

VfxU32 VappMusicPlayerContentProvider::delCancel()
{
    return m_ctrlPLSV->delCancel();
}

void VappMusicPlayerContentProvider::createPlaylist(VfxWString name)
{
    m_ctrlPLSV->createPlaylist(name);
}

VfxBool VappMusicPlayerContentProvider::isPlaylistExist(VfxWString name)
{
    return m_ctrlPLSV->isPlaylistExist(name);
}

void VappMusicPlayerContentProvider::addToPlaylist(VfxU32 index, VfxU32 playlistIdx)
{
    m_ctrlPLSV->addToPlaylist(index, playlistIdx);
}

void VappMusicPlayerContentProvider::addSelectedToPlaylist(VfxU32 playlistIdx)
{
    m_ctrlPLSV->addSelectedToPlaylist(playlistIdx);
}

void VappMusicPlayerContentProvider::addToPlaylistCancel()
{
    m_ctrlPLSV->addToPlaylistCancel();
}

void VappMusicPlayerContentProvider::renamePlaylist(VfxWString name, VfxU32 playlistIdx)
{
    m_ctrlPLSV->renamePlaylist(name, playlistIdx);
}

VfxBool VappMusicPlayerContentProvider::getPlaylistIndexByName(VfxWString &name, VfxU32 *playlistIdx)
{
    return m_ctrlPLSV->getPlaylistIndexByName(name, playlistIdx);
}

VfxBool VappMusicPlayerContentProvider::isActiveSongInFavorite()
{
    return m_ctrlPLSV->isActiveSongInFavorite();
}

void VappMusicPlayerContentProvider::addActiveSongToFavorite()
{
    m_ctrlPLSV->addActiveSongToFavorite();
}

void VappMusicPlayerContentProvider::removeActiveSongFromFavorite()
{
    m_ctrlPLSV->removeActiveSongFromFavorite();
}

void VappMusicPlayerContentProvider::rearrangeStart()
{
    m_ctrlPLSV->rearrangeStart();
}

void VappMusicPlayerContentProvider::rearrangeEnd()
{
    m_ctrlPLSV->rearrangeEnd();
}

void VappMusicPlayerContentProvider::rearrangeSwapPos(const VfxU32 from, const VfxU32 to)
{
    m_ctrlPLSV->rearrangeSwapPos(from, to);
}

void VappMusicPlayerContentProvider::rearrangeSave(VfxBool save)
{
    m_ctrlPLSV->rearrangeSave(save);
}

void VappMusicPlayerContentProvider::setActiveToDBUseCurrent()
{
    m_ctrlPLSV->setActiveToDBUseCurrent();
}

srv_plst_active_list_enum VappMusicPlayerContentProvider::getActiveListType()
{
    return m_ctrlPLSV->getActiveListType();
}

VfxBool VappMusicPlayerContentProvider::isPlayingFavorite()
{
    return m_ctrlPLSV->isPlayingFavorite();
}

VfxU32 VappMusicPlayerContentProvider::getID(VfxU32 index)
{
    VfxU32 ID = 0;
    m_ctrlPLSV->getID(index, ID);
    return ID;
}

VfxU32 VappMusicPlayerContentProvider::getHintCount(VfxU32 index, srv_plst_view_type_enum getCountType)
{
    return m_ctrlPLSV->getHintCount(index, getCountType);
}

VfxBool VappMusicPlayerContentProvider::getDetailInfo(VfxU32 index, srv_plst_media_details_struct *info)
{
    return m_ctrlPLSV->getDetailInfo(index, info);
}

VfxBool VappMusicPlayerContentProvider::getDetailInfoTitleOnly(VfxU32 index, srv_plst_media_details_struct *info)
{
    return m_ctrlPLSV->getDetailInfo(index, info, VFX_TRUE);
}

VfxBool VappMusicPlayerContentProvider::getDetailInfoByID(VfxU32 ID, srv_plst_media_details_struct *info)
{
    return m_ctrlPLSV->getDetailInfoByID(ID, info);
}

VfxBool VappMusicPlayerContentProvider::getCurrDetailInfo(srv_plst_media_details_struct *info)
{
    return m_ctrlPLSV->getCurrDetailInfo(info);
}

void VappMusicPlayerContentProvider::getFilePath(VfxU32 index, VfxWString &filePath)
{
    m_ctrlPLSV->getFilePath(index, filePath);
}

void VappMusicPlayerContentProvider::getAlbumCoverPathBySongID(VfxU32 ID, VfxWString &filePath)
{
    m_ctrlPLSV->getAlbumCoverPathBySongID(ID, filePath);
}

void VappMusicPlayerContentProvider::setDuration(VfxU32 ID, VfxU32 duration)
{
    m_ctrlPLSV->setDuration(ID, duration);
}

void VappMusicPlayerContentProvider::freeImageBuffer()
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void VappMusicPlayerContentProvider::freeMediaCache()
{
    if (m_ctrlMediaCache)
    {
        m_ctrlMediaCache->closeMediaCache();
        m_curMediaCacheView = VIEW_TYPE_NONE;
    }
}

ViewTypeEnum VappMusicPlayerContentProvider::getMediaCacheView()
{
    return m_curMediaCacheView;
}

VfxS32 VappMusicPlayerContentProvider::getAlbumCoverAsync(srv_plst_list_get_display_struct *displayStruct)
{
    return m_ctrlPLSV->getAlbumCoverAsync(displayStruct);
}

void VappMusicPlayerContentProvider::getAlbumCoverAsyncCancel()
{
    m_ctrlPLSV->getAlbumCoverAsyncCancel();
}

VfxU32 VappMusicPlayerContentProvider::getActiveCount()
{
    return m_ctrlPLSV->getActiveCount();
}

void VappMusicPlayerContentProvider::updateActiveCount()
{
    return m_ctrlPLSV->updateActiveCount();
}

VfxU32 VappMusicPlayerContentProvider::getActiveIndex()
{
    return m_ctrlPLSV->getActiveIndex();
}

void VappMusicPlayerContentProvider::updateActiveIndex()
{
    return m_ctrlPLSV->updateActiveIndex();
}

void VappMusicPlayerContentProvider::updateActiveID()
{
    m_activeID = m_ctrlPLSV->updateActiveID();
}

VfxS32 VappMusicPlayerContentProvider::getActiveAlbumIndex()
{
    return m_ctrlPLSV->getActiveAlbumIndex();
}

VfxBool VappMusicPlayerContentProvider::setViewType(ViewTypeEnum viewType, const ChangeViewMode mode, const VfxU32 index)
{
    // Clear get item text cache if view type change
    m_listItemCache.ID = 0;
    m_listItemCache.index = 0;
    m_listItemCache.hasInfo = VFX_FALSE;
    m_listItemCache.titleOnly = VFX_FALSE;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTNT_PROVIDER_SET_VIEW, m_currentView, viewType, mode, index);

    if (m_currentView == viewType)
    {
        return VFX_TRUE;
    }
    else if (mode == CHANGE_VIEW_MODE_ENTER && (viewType == VIEW_TYPE_SETTING || viewType == VIEW_TYPE_SETTING_SOUND_EFFECT))
    {
        // enter sound setting
        m_currentView = viewType;
        return VFX_FALSE;
    }
    else if (mode == CHANGE_VIEW_MODE_BACK && (m_currentView == VIEW_TYPE_SETTING || m_currentView == VIEW_TYPE_SETTING_SOUND_EFFECT))
    {
        // exit sound setting
        m_currentView = viewType;
        return VFX_FALSE;
    }

    m_currentView = viewType;
    m_changeViewMode = mode;

    // Clear highlight
    m_hlInfo.hlIdx = -1;
    m_hlInfo.preHlIdx = -1;

    if (isUsingMediaCache() && getCount() > 0 && mode == CHANGE_VIEW_MODE_SWITCH)
    {
        // sometimes APP can't find a NONE_PROC task to lock after switching view
        // reset all media cache tasks to unlock all cells
        m_ctrlMediaCache->resetTask();
    }
    
    const VfxBool ret = m_ctrlPLSV->setViewType(viewType, mode, index);

    if (viewType == VIEW_TYPE_ARTIST_ALBUM && mode == CHANGE_VIEW_MODE_ENTER)
    {
        m_curArtistIdx = index;
    }

    return ret;
}

void VappMusicPlayerContentProvider::setMediaCache()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SET_MEDIA_CACHE, m_currentView, m_changeViewMode, m_curMediaCacheView);

    if (isUsingMediaCache() && getCount() > 0)
    {
        VfxBool initMC = VFX_FALSE;
        VfxU32 thumbWidth = 0;
        VfxU32 thumbHeight = 0;
        VfxU32 count = getCount();

        if (m_currentView == VIEW_TYPE_COVER_FLOW)
        {
            if (m_changeViewMode == CHANGE_VIEW_MODE_ENTER)
            {
                if (m_currentView == m_curMediaCacheView)
                {
                    // already running by last entry
                    resumeMediaCache();
                    return;
                }

                initMC = VFX_TRUE;
            }
            else if (m_changeViewMode == CHANGE_VIEW_MODE_BACK)
            {
                if (m_curMediaCacheView == VIEW_TYPE_NONE)
                {
                    // this case media cache is closed due to releasing FG memory in the COVER_FLOW_SONG view
                    initMC = VFX_TRUE;
                }
            }
            
            thumbWidth = VAPP_MUSICPLY_CF_CELL_WIDTH;
            thumbHeight = VAPP_MUSICPLY_CF_CELL_HEIGHT;
            m_curMediaCacheView = VIEW_TYPE_COVER_FLOW;
        }
        else if (m_currentView == VIEW_TYPE_ARTIST_ALBUM)
        {
            if (m_currentView != m_curMediaCacheView 
            || (m_changeViewMode == CHANGE_VIEW_MODE_ENTER && m_currentView == m_curMediaCacheView && m_curArtistIdx != m_curMediaCacheArtistIdx))
            {
                count--;
                initMC = VFX_TRUE;
                m_curMediaCacheView = VIEW_TYPE_ARTIST_ALBUM;
                m_curMediaCacheArtistIdx = m_curArtistIdx;
                thumbWidth = VAPP_MUSICPLY_LISTMENU_THUMB_WIDTH;
                thumbHeight = VAPP_MUSICPLY_LISTMENU_THUMB_HEIGHT;
            }
        }
        else if (m_currentView == VIEW_TYPE_ALBUM || m_currentView == VIEW_TYPE_PLAYLIST_ADD_ALBUM)
        {
            if (m_curMediaCacheView != VIEW_TYPE_ALBUM && m_curMediaCacheView != VIEW_TYPE_PLAYLIST_ADD_ALBUM)
            {
                initMC = VFX_TRUE;
                m_curMediaCacheView = m_currentView;
                thumbWidth = VAPP_MUSICPLY_LISTMENU_THUMB_WIDTH;
                thumbHeight = VAPP_MUSICPLY_LISTMENU_THUMB_HEIGHT;
            }
        }

        if (count > 0)
        {
            if (initMC)
            {
                m_ctrlMediaCache->initMediaCache(count, thumbWidth, thumbHeight);

                if (m_currentView == VIEW_TYPE_COVER_FLOW)
                {
                    // lock a buffer to start media cache scheduling
                    lockFirstVisibleCell();
                }
            }
            else
            {
                if (m_ctrlMediaCache->getState() == PAUSE)
                {
                    resumeMediaCache();
                }
                else if (m_ctrlMediaCache->getState() == IDLE)
                {
                    resetMediaCache();
                }
            }
        }
    }
    else if (m_currentView == VIEW_TYPE_COVER_FLOW_SONG && m_changeViewMode == CHANGE_VIEW_MODE_ENTER)
    {
        // pause mediacache on entering COVER_FLOW_SONG or leaving COVER_FLOW
        m_ctrlMediaCache->pauseMediaCache();
    }
    else
    {
        // Beside cover flow, always pause media cache and close in onExit2() on change view
        m_ctrlMediaCache->pauseMediaCache();

        m_curMediaCacheView = VIEW_TYPE_NONE;
    }
}

void VappMusicPlayerContentProvider::pauseMediaCache()
{
    if (m_ctrlMediaCache)
    {
        m_ctrlMediaCache->pauseMediaCache();    
    }
}

void VappMusicPlayerContentProvider::resumeMediaCache()
{
    if (m_ctrlMediaCache)
    {
        m_ctrlMediaCache->resumeMediaCache();
    }
}

void VappMusicPlayerContentProvider::resetMediaCache()
{
    if (isUsingMediaCache() && getCount() > 0)
    {
        VfxU32 thumbWidth = 0;
        VfxU32 thumbHeight = 0;
        VfxU32 count = getCount();

        if (m_currentView == VIEW_TYPE_COVER_FLOW)
        {
            thumbWidth = VAPP_MUSICPLY_CF_CELL_WIDTH;
            thumbHeight = VAPP_MUSICPLY_CF_CELL_HEIGHT;

            m_curMediaCacheView = m_currentView;
        }
        else if (m_currentView == VIEW_TYPE_ARTIST_ALBUM)
        {
            count--;
            thumbWidth = VAPP_MUSICPLY_LISTMENU_THUMB_WIDTH;
            thumbHeight = VAPP_MUSICPLY_LISTMENU_THUMB_HEIGHT;

            m_curMediaCacheView = m_currentView;
        }
        else if (m_currentView == VIEW_TYPE_ALBUM || m_currentView == VIEW_TYPE_PLAYLIST_ADD_ALBUM)
        {
            thumbWidth = VAPP_MUSICPLY_LISTMENU_THUMB_WIDTH;
            thumbHeight = VAPP_MUSICPLY_LISTMENU_THUMB_HEIGHT;

            m_curMediaCacheView = m_currentView;
        }
        
        m_ctrlMediaCache->initMediaCache(count, thumbWidth, thumbHeight);
    }
}

ViewTypeEnum VappMusicPlayerContentProvider::getViewType() const
{
    return m_currentView;
}

ChangeViewMode VappMusicPlayerContentProvider::getChangeViewMode() const
{
    return m_changeViewMode;
}

void VappMusicPlayerContentProvider::resetChangeViewMode()
{
    m_changeViewMode = CHANGE_VIEW_MODE_NONE;
}

VappMusicPlayerCtrlMediaCahce* VappMusicPlayerContentProvider::getCtrlMediaCache() const
{
    return m_ctrlMediaCache;
}

ViewTypeEnum VappMusicPlayerContentProvider::getCurrMediaCacheViewType() const
{
    return m_curMediaCacheView;
}

MCStateEnum VappMusicPlayerContentProvider::getMediaCacheState() const
{
    return m_ctrlMediaCache->getState();
}

ListItemDataStruct VappMusicPlayerContentProvider::getListItemCache() const
{
    return m_listItemCache;
}

void VappMusicPlayerContentProvider::setRepeat(srv_plst_repeat_enum repeatState)
{
    m_ctrlPLSV->setRepeat(repeatState);
}

void VappMusicPlayerContentProvider::setShuffle(srv_plst_shuffle_enum shuffleState)
{
    m_ctrlPLSV->setShuffle(shuffleState);
}

srv_plst_repeat_enum VappMusicPlayerContentProvider::getRepeat()
{
    return m_ctrlPLSV->getRepeat();
}

srv_plst_shuffle_enum VappMusicPlayerContentProvider::getShuffle()
{
    return m_ctrlPLSV->getShuffle();
}

srv_plst_repeat_enum VappMusicPlayerContentProvider::nextRepeatState()
{
    return m_ctrlPLSV->nextRepeatState();
}

srv_plst_shuffle_enum VappMusicPlayerContentProvider::nextShuffleState()
{
    return m_ctrlPLSV->nextShuffleState();
}

void VappMusicPlayerContentProvider::searchStart()
{
    if (!isSearching())
    {
        m_isSearching = VFX_TRUE;
        m_ctrlPLSV->searchStart();
    }
}

void VappMusicPlayerContentProvider::searchEnd()
{
    if (isSearching())
    {
        m_isSearching = VFX_FALSE;
        m_ctrlPLSV->searchEnd();
        m_searchText.setEmpty();
    }
}

void VappMusicPlayerContentProvider::search(VfxWString &searchText)
{
    m_ctrlPLSV->search(searchText);
    m_searchText = searchText;
}

VfxBool VappMusicPlayerContentProvider::isSearching()
{
    return m_isSearching;
}

void VappMusicPlayerContentProvider::setShowPlayIcon(VfxBool show)
{
    m_showPlayIcon = show;
}

void VappMusicPlayerContentProvider::clearCurrCache(void)
{
    m_ctrlPLSV->clearCurrCache();
}

/***************************************************************************** 
 * VappMusicPlayerCtrlPLSV Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerCtrlPLSV", VappMusicPlayerCtrlPLSV, VfxObject);

void VappMusicPlayerCtrlPLSV::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_INIT);

    VfxObject::onInit();

    m_parent = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerContentProvider);
    VFX_ASSERT(m_parent);

    // Initial cache info index
    kal_mem_set(&m_activeInfo, 0, sizeof(srv_plst_media_details_struct));

    m_mplayerSrv = getMusicPlayerSrv();
    m_mplayerSrv->m_signalPLSVCallback.connect(this, &VappMusicPlayerCtrlPLSV::PLSVCallback);
    m_mplayerSrv->m_signalPLSVHandleChanged.connect(this, &VappMusicPlayerCtrlPLSV::PLSVHandleChanged);

    m_srvHandle = m_mplayerSrv->getPLSVHandle();
}

void VappMusicPlayerCtrlPLSV::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_DEINIT);

    m_srvHandle = 0;

    setIsReady(VFX_FALSE);

    clearTempBuffer();

    saveRepeatShuffle();

    VfxObject::onDeinit();
}

void VappMusicPlayerCtrlPLSV::initRepeatShuffle()
{
    // read repeat/shuffle state from NVRAM
    VfxU32 repeatState = 0;
    VfxU32 shuffleState = 0;
    VfxS16 sError = 0;
    ReadValue(NVRAM_VAPP_MUSICPLY_REPEAT_STATE, &repeatState, DS_BYTE, &sError);
    ReadValue(NVRAM_VAPP_MUSICPLY_SHUFFLE_STATE, &shuffleState, DS_BYTE, &sError);
    m_repeatState = (srv_plst_repeat_enum)repeatState;
    m_shuffleState = (srv_plst_shuffle_enum)shuffleState;
    setRepeat(m_repeatState);
    setShuffle(m_shuffleState);
}

void VappMusicPlayerCtrlPLSV::saveRepeatShuffle()
{
    // write repeat/shuffle state back to NVRAM
    VfxS16 sError;
    WriteValue(NVRAM_VAPP_MUSICPLY_REPEAT_STATE, (void*)&m_repeatState, DS_BYTE, &sError);
    WriteValue(NVRAM_VAPP_MUSICPLY_SHUFFLE_STATE, (void*)&m_shuffleState, DS_BYTE, &sError);
}

void VappMusicPlayerCtrlPLSV::setCBReceiver(VfxObject *obj)
{
    m_cbReceiver = obj;
}

void VappMusicPlayerCtrlPLSV::setIsReady(VfxBool isReady)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SET_IS_READY, isReady);

    m_isReady = isReady;
}

VfxBool VappMusicPlayerCtrlPLSV::getIsReady()
{
    return m_isReady;
}

VfxU32 VappMusicPlayerCtrlPLSV::getCount() const
{
    if (m_isReady && m_srvHandle && !m_waitSearchResult)
    {
        return m_itemCount;
    }
    return 0;
}

VfxU32 VappMusicPlayerCtrlPLSV::getCountFromPLSV() const
{
    VfxU32 totalCount = 0;

    if (m_isReady && m_srvHandle && !m_waitSearchResult)
    {
        VfxS32 ret = srv_plst_list_get_item_count(m_srvHandle, &totalCount);

        if (ret < SRV_PLST_OK)
        {
            // TODO: add error logs
            // fail
            m_parent->m_signalPLSVReturn.emit(ret);
            return 0;
        }
    }
    return totalCount;
}

VfxU32 VappMusicPlayerCtrlPLSV::getFixedCount(const ViewTypeEnum viewType, const VfxU32 index) const
{
    switch(viewType)
    {
        case VIEW_TYPE_ARTIST:
        {
            // Get totol songs in an artist
            srv_plst_fixed_count_struct view;
            VfxU32 count;
            
            kal_mem_set(&view, 0, sizeof(srv_plst_fixed_count_struct));
            view.view_stack[0].view_type = SRV_PLST_VIEW_ARTIST;
            view.view_stack[0].id = index;
            view.view_stack[0].is_id_used = MMI_TRUE;
            
            VfxS32 ret = srv_plst_list_get_fixed_count(m_srvHandle, &view, &count);

            if(ret == SRV_PLST_OK)
            {
                return count;
            }
            break;
        }
        default:
            break;
    }

    return 0;
}

void VappMusicPlayerCtrlPLSV::updateCount()
{
    m_itemCount = getCountFromPLSV();
}

void VappMusicPlayerCtrlPLSV::updateCount(VfxU32 count)
{
    m_itemCount = count;
}

void VappMusicPlayerCtrlPLSV::getID(VfxU32 index, VfxU32 &ID)
{
    if (m_isReady && m_srvHandle)
    {
        switch (m_viewType)
        {
            case VIEW_TYPE_ALL_SONGS:
            case VIEW_TYPE_ARTIST_SONG:
            case VIEW_TYPE_ARTIST_ALBUM_SONG:
            case VIEW_TYPE_ALBUM_SONG:
            case VIEW_TYPE_PLAYLIST_SONG:
            case VIEW_TYPE_PLAYLIST_ADD_ALL_SONG:
            case VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG:
            case VIEW_TYPE_PLAYLIST_ADD_ALBUM_SONG:
            case VIEW_TYPE_NOW_PLAYING:
            case VIEW_TYPE_NOW_PLAYING_LIST:
            case VIEW_TYPE_COVER_FLOW:
            case VIEW_TYPE_COVER_FLOW_SONG:
                srv_plst_media_get_id(m_srvHandle, index, &ID);
                break;

            default:
                srv_plst_list_get_item_id(m_srvHandle, index, &ID);
                break;
        };
    }
    else
    {
        ID = 0;
    }
}

VfxBool VappMusicPlayerCtrlPLSV::getTitle(const VfxU32 index, srv_plst_list_get_display_struct &displayStruct) const
{
    if (m_isReady && m_srvHandle)
    {
        VfxS32 ret = srv_plst_list_get_item_display(m_srvHandle, &displayStruct);

        if (ret < SRV_PLST_OK)
        {
            vfx_sys_wcscpy((WCHAR *)displayStruct.string_ptr, (WCHAR*)L"Unknown");
            return VFX_FALSE;
        }
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxBool VappMusicPlayerCtrlPLSV::getDetailInfo(VfxU32 index, srv_plst_media_details_struct *infoStruct, VfxBool getTitleOnly)
{
    if (m_isReady && m_srvHandle)
    {
        VfxU32 ID;
        getID(index, ID);
        const VfxBool ret = getDetailInfoByID(ID, infoStruct, getTitleOnly);

        return ret;
    }
    else
    {
        return VFX_FALSE;
    }    
}

VfxBool VappMusicPlayerCtrlPLSV::getDetailInfoByID(VfxU32 ID, srv_plst_media_details_struct *infoStruct, VfxBool getTitleOnly)
{
    if (m_isReady && m_srvHandle)
    {
        VfxS32 ret;
        if(getTitleOnly)
        {
            // currently only get title
            ret = srv_plst_media_get_details_by_filter(m_srvHandle, (U32)ID, infoStruct, 0);
        }
        else
        {
            ret = srv_plst_media_get_details(m_srvHandle, (U32)ID, infoStruct);
        }
        return ret == SRV_PLST_OK;
    }
    else
    {
        return VFX_FALSE;
    }    
}

VfxBool VappMusicPlayerCtrlPLSV::getCurrDetailInfo(srv_plst_media_details_struct *infoStruct)
{
    if (m_isReady && m_srvHandle)
    {
        SongInfoStruct info;
        m_mplayerSrv->getCurrInfo(info);

        // Compare cache id with active ID
        if ((m_activeInfo.media_id == info.id) && (m_activeInfo.media_id == m_activeID) && (m_activeInfo.media_id != 0))
        {
            memcpy(infoStruct, &m_activeInfo, sizeof(srv_plst_media_details_struct));
            return VFX_TRUE;
        }
        else
        {
            if(info.id != 0)
            {
                VfxS32 ret = srv_plst_media_get_details(m_srvHandle, info.id, infoStruct);

                if (ret == SRV_PLST_OK)
                {
                    memcpy(&m_activeInfo, infoStruct, sizeof(srv_plst_media_details_struct));
                    m_activeID = info.id;
                    return VFX_TRUE;
                }
            }
            return VFX_FALSE;
        }
    }
    else
    {
        return VFX_FALSE;
    }    
}

void VappMusicPlayerCtrlPLSV::getFilePath(VfxU32 index, VfxWString &filePath)
{
    UI_string_type buffer = NULL;
    VFX_ALLOC_MEM(buffer, sizeof(UI_character_type)*SRV_PLST_MAX_PATH_LEN, this);

    srv_plst_list_get_display_struct info;
    info.index = index;
    info.buff_size = SRV_PLST_MAX_PATH_LEN;
    info.string_ptr = (U32)buffer;

    VfxS32 ret = srv_plst_media_get_path(m_srvHandle, &info);

    if (ret == SRV_PLST_OK)
    {
        filePath.loadFromMem(buffer);
    }
    else
    {
        filePath.setEmpty();
    }

    VFX_FREE_MEM(buffer);
}

void VappMusicPlayerCtrlPLSV::getAlbumCoverPathBySongID(VfxU32 ID, VfxWString &filePath)
{
    UI_string_type buffer = NULL;
    VFX_ALLOC_MEM(buffer, sizeof(UI_character_type)*SRV_PLST_MAX_PATH_LEN, this);

    srv_plst_list_get_display_struct info;
    info.index = ID;
    info.buff_size = SRV_PLST_MAX_PATH_LEN;
    info.string_ptr = (U32)buffer;

    VfxS32 ret = srv_plst_list_get_artwork_parser_path_by_media_id(m_srvHandle, &info);

    if (ret == SRV_PLST_OK)
    {
        filePath.loadFromMem(buffer);
    }
    else
    {
        filePath.setEmpty();
    }

    VFX_FREE_MEM(buffer);
}

void VappMusicPlayerCtrlPLSV::setDuration(VfxU32 ID, VfxU32 duration)
{
    m_mplayerSrv->setDuration(ID, duration);
}

void VappMusicPlayerCtrlPLSV::resetPLSV()
{
    VfxS32 ret = 0;

    if (m_isReady && m_srvHandle)
    {
        m_viewType = VIEW_TYPE_NONE;
        ret = srv_plst_list_reset_all_list(m_srvHandle);
        m_parent->m_signalPLSVReturn.emit(ret);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_RESET, ret, m_isReady);
}

void VappMusicPlayerCtrlPLSV::refreshDB()
{   
    if (m_isReady && m_srvHandle)
    {
        setTempBuffer();
        VfxS32 ret = srv_plst_library_update(m_srvHandle);
        m_parent->m_signalPLSVReturn.emit(ret);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_REFRESH_DB_RESULT_D, ret);
    }
}

void VappMusicPlayerCtrlPLSV::refreshDBCancel()
{
    if (m_srvHandle)
    {
        VfxS32 ret = srv_plst_library_stop_udpate(m_srvHandle); 

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_REFRESH_DBCANCEL_RESULT_D, ret);
    }

    clearTempBuffer();   
}

void VappMusicPlayerCtrlPLSV::resetDB()
{
    m_itemCount = 0;

    VfxS32 ret = srv_plst_library_close(m_srvHandle);
    m_parent->m_signalPLSVReturn.emit(ret);

    if (ret == SRV_PLST_OK)
    {
        UI_character_type path[SRV_FMGR_PATH_MAX_LEN + 1];
        kal_wsprintf(path, "%w", L"media_lib");
        ret = srv_plst_library_open(m_srvHandle, path, SRV_PLST_OPEN_NEW);
        m_parent->m_signalPLSVReturn.emit(ret);

        if (ret == SRV_PLST_OK)
        {
            m_mplayerSrv->setDBState(DB_NORMAL);    // set to normal since reset can be executed when app exists
            setIsReady(VFX_TRUE);
        }
        else if (ret > SRV_PLST_OK)
        {
            // async
            m_mplayerSrv->setDBState(DB_OPENING);
            setIsReady(VFX_FALSE);
        }
        else
        {
            // fail
            m_mplayerSrv->setDBState(DB_CLOSE);
            setIsReady(VFX_FALSE);
        }

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_RESET_DB_RESULT_D, ret);
    }
}

VfxResId VappMusicPlayerCtrlPLSV::getErrorStrId(VfxS32 errorCode)
{
    mmi_event_notify_enum eventType;
    
    VfxU32 strID = srv_plst_get_error_string(errorCode, &eventType);

    return strID;
}

void VappMusicPlayerCtrlPLSV::setTempBuffer()
{
    if (m_cbReceiver)
    {
        VfxApp *app = VFX_OBJ_DYNAMIC_CAST(m_cbReceiver, VfxApp);
        if (app)
        {
            if (m_tempBuffer)
            {
                applib_asm_free_r(app->getGroupId(), m_tempBuffer);
                m_tempBuffer = NULL;
            }

            // The memory for read cover from source and resize destination
            VfxU32 bufferSize = VAPP_MUSICPLY_META_FILE_IMAGE_SIZE + (SRV_PLST_ARTWORK_RESIZED_WIDTH*SRV_PLST_ARTWORK_RESIZED_HEIGHT*2);
            m_tempBuffer = (U8*)applib_asm_alloc_nc_r(app->getGroupId(), bufferSize);

            if (m_isReady && m_srvHandle)
            {
                VfxS32 ret = srv_plst_set_temp_memory(m_srvHandle, (void**)&m_tempBuffer, bufferSize);

                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SET_TEMP_BUFFER_RESULT_D, ret);
            }
        }
    }
}

void VappMusicPlayerCtrlPLSV::clearTempBuffer()
{
    if (m_cbReceiver && m_tempBuffer)
    {
        VfxApp *app = VFX_OBJ_DYNAMIC_CAST(m_cbReceiver, VfxApp);
        if (app)
        {
            VfxS32 ret = 0;

            if (m_isReady && m_srvHandle)
            {
                ret = srv_plst_clear_temp_memory(m_srvHandle);
            }

            applib_asm_free_r(app->getGroupId(), m_tempBuffer);
            m_tempBuffer = NULL;

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_CLEAR_TEMP_BUFFER_RESULT_D, ret);
        }
    }
}

void VappMusicPlayerCtrlPLSV::selectStart()
{
    VfxS32 ret = srv_plst_list_multi_select_mark_begin(m_srvHandle);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SELECT_START_RESULT_D, ret);
}

void VappMusicPlayerCtrlPLSV::selectEnd()
{
    VfxS32 ret = srv_plst_list_multi_select_mark_end(m_srvHandle);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SELECT_END_RESULT_D, ret);
}

void VappMusicPlayerCtrlPLSV::selectAll()
{
    VfxS32 ret = srv_plst_list_multi_select_mark_all(m_srvHandle, KAL_TRUE);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SELECT_ALL_RESULT_D, ret);
}

void VappMusicPlayerCtrlPLSV::deselectAll()
{
    VfxS32 ret = srv_plst_list_multi_select_mark_all(m_srvHandle, KAL_FALSE);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_DESELECT_ALL_RESULT_D, ret);
}

void VappMusicPlayerCtrlPLSV::select(VfxU32 index)
{
    VfxS32 ret = srv_plst_list_multi_select_set_mark(m_srvHandle, index, KAL_TRUE);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SELECT_RESULT_D, ret);
}

void VappMusicPlayerCtrlPLSV::deselect(VfxU32 index)
{
    VfxS32 ret = srv_plst_list_multi_select_set_mark(m_srvHandle, index, KAL_FALSE);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_DESELECT_RESULT_D, ret);
}

VfxBool VappMusicPlayerCtrlPLSV::isSelected(VfxU32 index)
{
    kal_bool select = KAL_FALSE;
    VfxS32 ret = srv_plst_list_multi_select_get_mark(m_srvHandle, index, &select);
    return VfxBool(select);
}

void VappMusicPlayerCtrlPLSV::del(VfxU32 index)
{
    VfxS32 ret = 0;

    if (m_viewType == VIEW_TYPE_PLAYLIST)
    {
        ret = srv_plst_plst_delete(m_srvHandle, index);
    }
    else if(m_viewType == VIEW_TYPE_PLAYLIST_SONG 
         || m_viewType == VIEW_TYPE_NOW_PLAYING)
    {
        ret = srv_plst_plst_item_remove(m_srvHandle, index);
    }
    else if(m_viewType == VIEW_TYPE_NOW_PLAYING_LIST)
    {
        if (getActiveListType() == SRV_PLST_ACTIVE_LIST_AUDIO)
        {
            ret = srv_plst_list_item_delete(m_srvHandle, index);
        }
        else if (getActiveListType() == SRV_PLST_ACTIVE_LIST_PLST)
        {
            ret = srv_plst_plst_item_remove(m_srvHandle, index);
        }
        else
        {
            return;
        }
    }
    else
    {
        ret = srv_plst_list_item_delete(m_srvHandle, index);
    }

    m_parent->m_signalPLSVReturn.emit(ret);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_DEL_RESULT_D, ret);
}

void VappMusicPlayerCtrlPLSV::delSelected()
{
    VfxS32 ret = 0;

    if (m_viewType == VIEW_TYPE_PLAYLIST)
    {
        ret = srv_plst_plst_delete(m_srvHandle, 0);
    }
    else if(m_viewType == VIEW_TYPE_PLAYLIST_SONG )
    {
        ret = srv_plst_plst_item_remove(m_srvHandle, 0);
    }
    else if(m_viewType == VIEW_TYPE_NOW_PLAYING_LIST || m_viewType == VIEW_TYPE_NOW_PLAYING)
    {
        if (getActiveListType() == SRV_PLST_ACTIVE_LIST_AUDIO)
        {
            ret = srv_plst_list_item_delete(m_srvHandle, 0);
        }
        else if (getActiveListType() == SRV_PLST_ACTIVE_LIST_PLST)
        {
            ret = srv_plst_plst_item_remove(m_srvHandle, 0);
        }
        else
        {
            return;
        }
    }
    else
    {
        ret = srv_plst_list_item_delete(m_srvHandle, 0);
    }

    m_parent->m_signalPLSVReturn.emit(ret);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_DEL_SELECTED_RESULT_D, ret);
}

VfxU32 VappMusicPlayerCtrlPLSV::delCancel()
{
    VfxU32 count;
    VfxS32 ret;

    if (m_viewType == VIEW_TYPE_PLAYLIST)
    {
        ret = srv_plst_plst_stop_delete(m_srvHandle, &count);
    }
    else if(m_viewType == VIEW_TYPE_PLAYLIST_SONG 
         || m_viewType == VIEW_TYPE_NOW_PLAYING)
    {
        ret = srv_plst_plst_item_stop_remove(m_srvHandle, &count);
    }
    else if (m_viewType == VIEW_TYPE_NOW_PLAYING_LIST)
    {
        srv_plst_active_list_enum activeType = getActiveListType();
        if (activeType == SRV_PLST_ACTIVE_LIST_PLST
         || activeType == SRV_PLST_ACTIVE_LIST_TEMP_PLST)
        {
            ret = srv_plst_plst_item_stop_remove(m_srvHandle, &count);
        }
        else
        {
            ret = srv_plst_list_item_stop_delete(m_srvHandle, &count);
        }
    }
    else
    {
        ret = srv_plst_list_item_stop_delete(m_srvHandle, &count);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_DEL_CANCEL_RESULT_D, ret);
    return count;
}

void VappMusicPlayerCtrlPLSV::configDefaultPlaylist()
{
    m_mplayerSrv->configDefaultPlaylist();
}

void VappMusicPlayerCtrlPLSV::createPlaylist(VfxWString name)
{
    U32 plstID;
    VfxS32 ret = srv_plst_plst_create(m_srvHandle, (WCHAR*)name.getBuf(), &plstID);
    m_parent->m_signalPLSVReturn.emit(ret);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_CREATE_PLAYLIST_RESULT_D, ret);
}

VfxBool VappMusicPlayerCtrlPLSV::isPlaylistExist(VfxWString name)
{
    return srv_plst_check_playlist_is_exist(m_srvHandle, (WCHAR*)name.getBuf());
}

VfxU32 VappMusicPlayerCtrlPLSV::getDefaultPlaylistType(VfxU32 index)
{
    U32 playlistType;
    VfxS32 ret = srv_plst_default_playlist_get_type(m_srvHandle, index, &playlistType);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_GET_DEFAULT_PLAYLIST_TYPE_RESULT_D, ret);

    return playlistType;
}

void VappMusicPlayerCtrlPLSV::addToPlaylist(VfxU32 index, VfxU32 playlistIdx)
{
    VfxS32 ret = srv_plst_media_add_to_playlist(m_srvHandle, index, playlistIdx);
    m_parent->m_signalPLSVReturn.emit(ret);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_ADD_TO_PLAYLIST_RESULT_D, ret);
}

void VappMusicPlayerCtrlPLSV::addSelectedToPlaylist(VfxU32 playlistIdx)
{
    VfxS32 ret = srv_plst_media_add_to_playlist(m_srvHandle, -1, playlistIdx);
    m_parent->m_signalPLSVReturn.emit(ret);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_ADD_SELECTED_TO_PLAYLIST_RESULT_D, ret);
}

void VappMusicPlayerCtrlPLSV::addToPlaylistCancel()
{
    VfxS32 ret = srv_plst_media_stop_add_to_playlist(m_srvHandle);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_ADD_TO_PLAYLIST_CANCEL_RESULT_D, ret);
}

void VappMusicPlayerCtrlPLSV::renamePlaylist(VfxWString name, VfxU32 playlistIdx)
{
    VfxS32 ret = srv_plst_plst_rename(m_srvHandle, (WCHAR*)name.getBuf(), playlistIdx);
    m_parent->m_signalPLSVReturn.emit(ret);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_RENAME_PLAYLIST_RESULT_D, ret);
}

VfxBool VappMusicPlayerCtrlPLSV::getPlaylistIndexByName(VfxWString &name, VfxU32 *playlistIdx)
{
    VfxS32 ret = srv_plst_get_plst_index_by_name(m_srvHandle, (WCHAR*)name.getBuf(), playlistIdx);
    return (ret == SRV_PLST_OK);
}

VfxBool VappMusicPlayerCtrlPLSV::isActiveSongInFavorite()
{
    return srv_plst_check_active_media_is_in_playlist(m_srvHandle, SRV_PLST_DEF_MY_FAVOURITE);
}

void VappMusicPlayerCtrlPLSV::addActiveSongToFavorite()
{
    VfxS32 ret = srv_plst_active_media_add_to_playlist(m_srvHandle, SRV_PLST_DEF_MY_FAVOURITE);
    m_parent->m_signalPLSVReturn.emit(ret);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_ADD_ACTIVE_SONG_TO_FAVORITE_RESULT_D, ret);
}

void VappMusicPlayerCtrlPLSV::removeActiveSongFromFavorite()
{
    VfxS32 ret = srv_plst_active_media_remove_from_playlist(m_srvHandle, SRV_PLST_DEF_MY_FAVOURITE);
    m_parent->m_signalPLSVReturn.emit(ret);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_REMOVE_ACTIVE_SONG_FROM_FAVORITE_RESULT_D, ret);
}

void VappMusicPlayerCtrlPLSV::rearrangeStart()
{
    VfxS32 ret = srv_plst_plst_item_reorder_begin(m_srvHandle);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_REARRANGE_START_RESULT_D, ret);
}

void VappMusicPlayerCtrlPLSV::rearrangeEnd()
{
    VfxS32 ret = srv_plst_plst_item_reorder_end(m_srvHandle);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_REARRANGE_END_RESULT_D, ret);
}

void VappMusicPlayerCtrlPLSV::rearrangeSwapPos(const VfxU32 from, const VfxU32 to)
{
    VfxS32 ret = srv_plst_plst_item_reorder_action(m_srvHandle, from, to);
    m_parent->m_signalPLSVReturn.emit(ret);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_REARRANGE_SWAP_POS_RESULT_D_FROM_D_TO_D, ret, from, to);
}

void VappMusicPlayerCtrlPLSV::rearrangeSave(VfxBool save)
{
    VfxS32 ret = srv_plst_plst_item_reorder_action_set_result(m_srvHandle, (kal_bool)save);
    m_parent->m_signalPLSVReturn.emit(ret);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_REARRANGE_SAVE_RESULT_D, ret);
}

void VappMusicPlayerCtrlPLSV::setActiveNoUpdateDB(VfxU32 index)
{
    VfxS32 ret = m_mplayerSrv->setActive(index, VFX_FALSE);

    if (ret == SRV_PLST_OK)
    {
        updateActiveIndex();
        updateActiveCount();
    }

}

void VappMusicPlayerCtrlPLSV::setActiveToDBUseCurrent(void)
{
    VfxS32 ret = srv_plst_list_update_current_active_to_db(m_srvHandle);
}

srv_plst_active_list_enum VappMusicPlayerCtrlPLSV::getActiveListType()
{
    srv_plst_active_list_enum type = srv_plst_get_active_list_type(m_srvHandle);
    return type;
}

VfxBool VappMusicPlayerCtrlPLSV::isPlayingFavorite()
{

    if (getActiveListType() == SRV_PLST_ACTIVE_LIST_PLST)
    {
        VfxU32 ID;
        VfxS32 ret = srv_plst_plst_get_active_plst_id(m_srvHandle, &ID);

        if (ret == SRV_PLST_OK)
        {
            srv_plst_default_playlist_enum defPlaylistType;
            ret = srv_plst_default_playlist_get_type_info_by_id(m_srvHandle, ID, &defPlaylistType);

            if (ret == SRV_PLST_OK && defPlaylistType == SRV_PLST_DEF_MY_FAVOURITE)
            {
                return VFX_TRUE;
            }
        }
    }
    return VFX_FALSE;
}

VfxU32 VappMusicPlayerCtrlPLSV::getHintCount(VfxU32 index, srv_plst_view_type_enum getCountType)
{
    VfxU32 count = 0;

    if (m_isReady && m_srvHandle)
    {
        VfxS32 ret = srv_plst_list_get_hint_count_ex(m_srvHandle, index, getCountType, &count);
    }

    return count;
}

void VappMusicPlayerCtrlPLSV::getAlbumArtistName(VfxU32 ID, VfxWString &name)
{
    srv_plst_get_cntx_param_struct inParam;
    inParam.id = ID;
    inParam.id_enum = SRV_PLST_TYPE_ID_ALBUM;
    inParam.get_type = SRV_PLST_CNTX_TYPE_ARTISTNAME;

    getContext(inParam, name);
}

void VappMusicPlayerCtrlPLSV::getContext(srv_plst_get_cntx_param_struct inParam, VfxWString &context)
{
    if (m_isReady && m_srvHandle)
    {
        srv_plst_get_context_struct outParam;
        VfxS32 ret = srv_plst_list_get_context_by_id(m_srvHandle, &inParam, &outParam);
        if (ret == SRV_PLST_OK)
        {
            context.loadFromMem(outParam.name);
        }
        else
        {
            context.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_ARTIST);
        }
    }
    else
    {
        context.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_ARTIST);
    }    
}

VfxS32 VappMusicPlayerCtrlPLSV::getAlbumCoverAsync(srv_plst_list_get_display_struct *displayStruct)
{
    if (m_isReady && m_srvHandle)
    {
        VfxS32 ret = srv_plst_list_get_item_artwork_async(m_srvHandle, displayStruct);
        
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_GET_ALBUM_COVER_ASYNC_RESULT_D, ret);

        m_parent->m_signalPLSVReturn.emit(ret);

        return ret;
    }
    else
    {
        return -1;
    }    
}

void VappMusicPlayerCtrlPLSV::getAlbumCoverAsyncCancel()
{
    if (m_srvHandle)
    {
        VfxS32 ret = srv_plst_list_get_item_artwork_async_stop(m_srvHandle);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_GET_ALBUM_COVER_ASYNC_CANCEL_RESULT_D, ret);
    }
}

VfxU32 VappMusicPlayerCtrlPLSV::getActiveCount() const
{
    return m_mplayerSrv->getActiveCount();
}

void VappMusicPlayerCtrlPLSV::updateActiveCount()
{
    m_mplayerSrv->updateActiveCount();
}

VfxU32 VappMusicPlayerCtrlPLSV::getActiveIndex() const
{
    return m_mplayerSrv->getActiveIndex();
}

VfxU32 VappMusicPlayerCtrlPLSV::getActiveIndexFromPLSV() const
{
    VfxU32 index = 0;
    
    if (m_isReady && m_srvHandle)
    {
        VfxS32 ret = srv_plst_plst_get_active_plst_item_index(m_srvHandle, &index);
        m_parent->m_signalPLSVReturn.emit(ret);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_GET_ACTIVE_INDEX_FROM_PLSV_RESULT_D, ret);
    }

    return index;
}

void VappMusicPlayerCtrlPLSV::updateActiveIndex() const
{
    m_mplayerSrv->updateActiveIndex();
}

VfxU32 VappMusicPlayerCtrlPLSV::updateActiveID() const
{
    m_mplayerSrv->updateActiveID();

    return m_mplayerSrv->getActiveID();
}

VfxS32 VappMusicPlayerCtrlPLSV::getActiveAlbumIndex() const
{
    VfxS32 index = -1;

    if (m_isReady && m_srvHandle)
    {
        VfxU32 idx = 0;
        VfxS32 ret = srv_plst_plst_get_active_index(m_srvHandle, SRV_PLST_ACTIVE_ALBUM, &idx);

		if (ret == SRV_PLST_OK)
		{
			// PLSV API return index starts from 1, may be a bug
			index = idx - 1;
		}

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_GET_ACTIVE_ALBUM_INDEX_RESULT_D, ret);
    }

    return index;
}

void VappMusicPlayerCtrlPLSV::setRepeat(srv_plst_repeat_enum repeatState)
{
    m_mplayerSrv->setRepeat(repeatState);
}

void VappMusicPlayerCtrlPLSV::setShuffle(srv_plst_shuffle_enum shuffleState)
{
    m_mplayerSrv->setShuffle(shuffleState);
}

srv_plst_repeat_enum VappMusicPlayerCtrlPLSV::getRepeat()
{
    return m_mplayerSrv->getRepeat();
}

srv_plst_shuffle_enum VappMusicPlayerCtrlPLSV::getShuffle()
{
    return m_mplayerSrv->getShuffle();
}

srv_plst_repeat_enum VappMusicPlayerCtrlPLSV::nextRepeatState()
{
    VfxU32 repeatState = (VfxU32)m_repeatState;
    m_repeatState = (srv_plst_repeat_enum)((repeatState + 1)%3);
    setRepeat(m_repeatState);
    return m_repeatState;
}

srv_plst_shuffle_enum VappMusicPlayerCtrlPLSV::nextShuffleState()
{
    VfxU32 shuffleState = (VfxU32)m_shuffleState;
    m_shuffleState = (srv_plst_shuffle_enum)((shuffleState + 1)%2);
    setShuffle(m_shuffleState);
    return m_shuffleState;
}

void VappMusicPlayerCtrlPLSV::searchStart()
{
    if (m_isReady && m_srvHandle)
    {
        VfxS32 ret = srv_plst_list_prefix_search_begin(m_srvHandle);
        m_parent->m_signalPLSVReturn.emit(ret);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SEARCH_START_RESULT_D, ret);
    }
    m_waitSearchResult = VFX_FALSE;
}

void VappMusicPlayerCtrlPLSV::searchEnd()
{
    if (m_isReady && m_srvHandle)
    {
        VfxS32 ret = srv_plst_list_prefix_search_end(m_srvHandle);
        m_parent->m_signalPLSVReturn.emit(ret);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SEARCH_END_RESULT_D, ret);
    }
    m_waitSearchResult = VFX_FALSE;
    
    updateCount();
}

void VappMusicPlayerCtrlPLSV::search(VfxWString &searchText)
{
    if (m_isReady && m_srvHandle)
    {
        VfxS32 ret = srv_plst_list_search_async(m_srvHandle, (U32)searchText.getBuf());
        m_parent->m_signalPLSVReturn.emit(ret);
        m_waitSearchResult = VFX_TRUE;
    }
}

VfxBool VappMusicPlayerCtrlPLSV::isWaitSearchResult(void)
{
    return m_waitSearchResult;
}

void VappMusicPlayerCtrlPLSV::clearCurrCache(void)
{
    if (m_isReady && m_srvHandle)
    {
        VfxS32 ret = srv_plst_plst_clear_curr_view_cache(m_srvHandle, MMI_FALSE);
        m_parent->m_signalPLSVReturn.emit(ret);
    }
}

VfxBool VappMusicPlayerCtrlPLSV::setViewType(const ViewTypeEnum viewType, const ChangeViewMode mode, const VfxU32 index)
{
    if (!m_isReady || !m_srvHandle)
    {
        return VFX_FALSE;
    }

    if (viewType == m_viewType)
    {
        return VFX_TRUE;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SET_VIEW_TYPE, viewType, mode, index);

    VfxS32 ret = 0;
    srv_plst_list_view_struct viewStruct;
    viewStruct.is_id_used = (kal_bool)VFX_FALSE;
    // These following view type should use ID for entry next level: VIEW_TYPE_ARTIST_ALUBM, VIEW_TYPE_ARTIST_SONG, VIEW_TYPE_ALBUM_SONG
    // Using index under search result will entry incorrect item
        
    if (mode == CHANGE_VIEW_MODE_SWITCH)
    {
        ret = srv_plst_list_exit(m_srvHandle);
        m_parent->m_signalPLSVReturn.emit(ret);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SRV_PLST_LIST_EXIT_RET_D, ret);
    }
    else if (mode == CHANGE_VIEW_MODE_BACK)
    {
        if (viewType == VIEW_TYPE_ARTIST_ALBUM && m_viewType == VIEW_TYPE_ARTIST_SONG)
        {
            // This case is back from artist all songs, should do one extra exit than entry current artist again
            ret = srv_plst_list_exit(m_srvHandle);
            m_parent->m_signalPLSVReturn.emit(ret);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SRV_PLST_LIST_EXIT_RET_D, ret);

            viewStruct.view_type = SRV_PLST_VIEW_ALBUM;
            viewStruct.id = index;
            viewStruct.is_id_used = (kal_bool)VFX_TRUE;
            ret = srv_plst_list_entry(m_srvHandle, &viewStruct);
            m_parent->m_signalPLSVReturn.emit(ret);

            m_viewType = viewType;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SRV_PLST_LIST_ENTRY_RET_D, ret);
        }
        else
        {
            if (viewType == VIEW_TYPE_NOW_PLAYING && m_viewType == VIEW_TYPE_NOW_PLAYING_LIST)
            {
                // back from active list to now playing
                m_viewType = viewType;
                return VFX_TRUE;
            }

            ret = srv_plst_list_exit(m_srvHandle);
            m_parent->m_signalPLSVReturn.emit(ret);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SRV_PLST_LIST_EXIT_RET_D, ret);

            if (viewType == VIEW_TYPE_VIEW_SELECT)
            {
                m_viewType = VIEW_TYPE_PLAYLIST_SONG;
            }
            else if (viewType == VIEW_TYPE_SETTING)
            {
                // skip the setting view to now playing, cause' now playing is the only way to enter setting
                m_viewType = VIEW_TYPE_NOW_PLAYING;
            }
            else
            {
                m_viewType = viewType;
            }
        }
        updateCount();
        return VFX_TRUE;
    }
    else if (mode == CHANGE_VIEW_MODE_ENTER)
    {
        switch (viewType)
        {
            case VIEW_TYPE_ARTIST_SONG:
                ret = srv_plst_list_exit(m_srvHandle);
                m_parent->m_signalPLSVReturn.emit(ret);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SRV_PLST_LIST_EXIT_RET_D, ret);
            
            case VIEW_TYPE_ARTIST_ALBUM:
            case VIEW_TYPE_ALBUM_SONG:
                viewStruct.id = index;
                viewStruct.is_id_used = (kal_bool)VFX_TRUE;
                break;
        };
    }
    else if (mode == CHANGE_VIEW_MODE_NONE)
    {
        if (viewType != VIEW_TYPE_ALL_SONGS)
        {
            ret = srv_plst_list_exit(m_srvHandle);
            m_parent->m_signalPLSVReturn.emit(ret);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SRV_PLST_LIST_EXIT_RET_D, ret);
            updateCount();
            m_viewType = viewType;
            return VFX_TRUE;
        }
    }
    
    switch (viewType)
    {
        case VIEW_TYPE_ALL_SONGS:
            viewStruct.view_type = SRV_PLST_VIEW_AUDIO;
            viewStruct.index = SRV_PLST_VIEW_ROOT;
            break;
        case VIEW_TYPE_ARTIST:
            viewStruct.view_type = SRV_PLST_VIEW_ARTIST;
            viewStruct.index = SRV_PLST_VIEW_ROOT;
            break;
        case VIEW_TYPE_ALBUM:
            viewStruct.view_type = SRV_PLST_VIEW_ALBUM;
            viewStruct.index = SRV_PLST_VIEW_ROOT;
            break;
        case VIEW_TYPE_PLAYLIST:
            viewStruct.view_type = SRV_PLST_VIEW_PLST;
            viewStruct.index = SRV_PLST_VIEW_ROOT;
            break;

        case VIEW_TYPE_ARTIST_SONG:
            viewStruct.view_type = SRV_PLST_VIEW_MEDIA;
            viewStruct.index = index;
            break;

        case VIEW_TYPE_ARTIST_ALBUM:
            viewStruct.view_type = SRV_PLST_VIEW_ALBUM;
            viewStruct.index = index;
            break;

        case VIEW_TYPE_ARTIST_ALBUM_SONG:
            viewStruct.view_type = SRV_PLST_VIEW_MEDIA;
            viewStruct.index = index;
            break;

        case VIEW_TYPE_ALBUM_SONG:
            viewStruct.view_type = SRV_PLST_VIEW_MEDIA;
            viewStruct.index = index;
            break;

        case VIEW_TYPE_PLAYLIST_SONG:
            viewStruct.view_type = SRV_PLST_VIEW_MEDIA;
            viewStruct.index = index;
            break;

        case VIEW_TYPE_PLAYLIST_SELECT:
            viewStruct.view_type = SRV_PLST_VIEW_PLST_ADDTO;
            viewStruct.index = SRV_PLST_VIEW_ROOT;
            break;

        case VIEW_TYPE_VIEW_SELECT:
            return VFX_TRUE;

        case VIEW_TYPE_PLAYLIST_ADD_ALL_SONG:
            viewStruct.view_type = SRV_PLST_VIEW_AUDIO;
            viewStruct.index = SRV_PLST_VIEW_ROOT;
            break;

        case VIEW_TYPE_PLAYLIST_ADD_ARTIST:
            viewStruct.view_type = SRV_PLST_VIEW_ARTIST;
            viewStruct.index = SRV_PLST_VIEW_ROOT;
            break;

        case VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG:
            viewStruct.view_type = SRV_PLST_VIEW_MEDIA;
            viewStruct.index = index;
            break;

        case VIEW_TYPE_PLAYLIST_ADD_ALBUM:
            viewStruct.view_type = SRV_PLST_VIEW_ALBUM;
            viewStruct.index = SRV_PLST_VIEW_ROOT;
            break;

        case VIEW_TYPE_PLAYLIST_ADD_ALBUM_SONG:
            viewStruct.view_type = SRV_PLST_VIEW_MEDIA;
            viewStruct.index = index;
            break;

        case VIEW_TYPE_NOW_PLAYING:
            viewStruct.view_type = SRV_PLST_VIEW_PLST_ACTIVE;
            viewStruct.index = SRV_PLST_VIEW_ROOT;
            break;

        case VIEW_TYPE_SETTING:
            return VFX_TRUE;

        case VIEW_TYPE_NOW_PLAYING_LIST:
            // back from active list to now playing
            // re-enter the active list view again to reset Data from the beginning
            ret = srv_plst_list_exit(m_srvHandle);
            
            viewStruct.view_type = SRV_PLST_VIEW_PLST_ACTIVE;
            viewStruct.index = SRV_PLST_VIEW_ROOT;
            break;

        case VIEW_TYPE_COVER_FLOW:
            viewStruct.view_type = SRV_PLST_VIEW_IMAGE_FLOW;
            viewStruct.index = SRV_PLST_VIEW_ROOT;
            break;

        case VIEW_TYPE_COVER_FLOW_SONG:
            viewStruct.view_type = SRV_PLST_VIEW_MEDIA;
            viewStruct.index = index;
            break;

        default:
            VFX_ASSERT(!"[VappMusicPlayerCtrlPLSV::setViewType()] Undefine view type");
            break;
    }

    ret = srv_plst_list_entry(m_srvHandle, &viewStruct);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_SRV_PLST_LIST_ENTRY_RET_D, ret);

    m_parent->m_signalPLSVReturn.emit(ret);

    if (ret < SRV_PLST_OK)
    {
        // fail
        return VFX_FALSE;
    }

    // To enhance tap to play performance, Do not get count from SQL command. Use get fixed count to get count from active play list
    if(viewType == VIEW_TYPE_NOW_PLAYING)
    {
        // Get total songs in an artist
        srv_plst_fixed_count_struct view;
        VfxU32 count;
        
        kal_mem_set(&view, 0, sizeof(srv_plst_fixed_count_struct));
        view.view_stack[0].view_type = SRV_PLST_VIEW_PLST_ACTIVE;
        
        VfxS32 ret = srv_plst_list_get_fixed_count(m_srvHandle, &view, &count);

        // TODO: remove (only for debug to check if list count is correct
        //updateCount();
        //ASSERT(m_itemCount == count);

        m_itemCount = count;
    }
    else
    {
        updateCount();
    }
    
    m_viewType = viewType;

    return VFX_TRUE;
}

void VappMusicPlayerCtrlPLSV::PLSVCallback(srv_plst_cb_evt_enum cb_event, S32 result, VfxU32 ca_para_2)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRL_PLSV_PLSVCALLBACK, cb_event, result, ca_para_2);

    // handle callback event before emit signal
    switch (cb_event)
    {
        case SRV_PLST_CB_EVT_OPEN:
            setIsReady(result == SRV_PLST_OK);
            break;

        case SRV_PLST_CB_EVT_SEARCH:
            // async search complete, should update count first then post invoke to APP for updating content
            m_waitSearchResult = VFX_FALSE;
            updateCount((VfxU32)ca_para_2);
            break;

        case SRV_PLST_CB_EVT_MSDC_PLUG_OUT: // SD card out
#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
            setIsReady(VFX_FALSE);
#endif
            break;

        case SRV_PLST_CB_EVT_MSDC_PLUG_IN:  // SD card in
            break;
    }

    VappMusicPlayerContentProvider *pParent = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerContentProvider);
    pParent->m_signalPLSVCallback.emit(cb_event, result, ca_para_2);
    
    // handle callback event after emit signal
    switch (cb_event)
    {
        case SRV_PLST_CB_EVT_OPEN:
        #ifdef __COSMOS_MUSICPLY_CARD_ONLY__
            if (!m_mplayerSrv->getMemoryCardReady())
            {
                break;
            }
        #endif
            updateCount();
            updateActiveCount();
            break;

        case SRV_PLST_CB_EVT_UPDATE:
            updateCount();
            updateActiveCount();
            break;

        case SRV_PLST_CB_EVT_SEARCH:
            break;

        case SRV_PLST_CB_EVT_DELETE_LIST:
            updateActiveIndex();
            updateActiveCount();
            break;

        case SRV_PLST_CB_EVT_DELETE_PROGRESS:
            break;

        case SRV_PLST_CB_EVT_DELETE_ACTIVE_MEDIA:   
            break;

        case SRV_PLST_CB_EVT_DELETE_FROM_FMGR:
            break;

        case SRV_PLST_CB_EVT_ADD_TO_PLST:
            updateActiveIndex();
            updateActiveCount();
            break;

        case SRV_PLST_CB_EVT_GET_IMAGE:
            break;

        case SRV_PLST_CB_EVT_USB_PLUG_IN:
            break;

        case SRV_PLST_CB_EVT_USB_PLUG_OUT:
            break;

        case SRV_PLST_CB_EVT_MSDC_PLUG_OUT: // SD card out
            break;

        case SRV_PLST_CB_EVT_MSDC_PLUG_IN:  // SD card in
            break;

        case SRV_PLST_CB_EVT_UPDATE_ARTWORK:
            break;
        
        case SRV_PLST_CB_EVT_PRE_FORMAT:
        case SRV_PLST_CB_EVT_NOTIFY_DEFAULT_STORAGE_CHANGE:
        case SRV_PLST_CB_EVT_MSDC_ENTRY_UNMOUNT:
        case SRV_PLST_CB_EVT_MSDC_EXIT_UNMOUNT:
        case SRV_PLST_CB_EVT_ACTIVE_LIST_INVALID:
        case SRV_PLST_CB_EVT_TOTAL:

        default:
            break;
    };
}

void VappMusicPlayerCtrlPLSV::PLSVHandleChanged(VfxS32 handle)
{
    m_srvHandle = handle;
}

#endif //__COSMOS_MUSICPLY__
