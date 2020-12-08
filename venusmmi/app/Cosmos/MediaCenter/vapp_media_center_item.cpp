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
 *  vapp_media_center_item.cpp
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

#include "MMI_features.h" 
#ifdef __MMI_3D_MEDIA_CENTER__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_config.h"
#include "vfx_object.h"
#include "vcp_include.h"
#include "vapp_media_center_item.h"
#include "vapp_media_center_util.h"

extern "C"
{
#include "mmi_rp_vapp_media_center_def.h"
#include "AppMgrSrvGprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMediaCenterAppItem", VappMediaCenterAppItem, VfxGroup);
VFX_IMPLEMENT_CLASS("VappMediaCenterAppItems", VappMediaCenterAppItems, VfxObject);

/***************************************************************************** 
 * Class Implementation : VappMediaCenterAppItem
 *****************************************************************************/
static VfxBool g_releaseFocusItemWhileUnfcus = VFX_FALSE;
void VappMediaCenterAppItem::onInit() 
{
    _ME_TRACE_1("[MediaCenter][Item] onInit(), id = %d", m_index);
    MEDIA_CENTER_MEASURE_TIME_START("MI0");
    
    VfxGroup::onInit();
    
    // setup scene 
    VfxAssetLoader::loadSceneBegin(this, m_resource.m_plateScene);
    m_plateMesh = (VfxMesh *)VfxAssetLoader::findObjByName(VFX_STR("plate-node_PIVOT"));
    m_plateRoot = (VfxGroup *)VfxAssetLoader::findObjByName(VFX_STR("plateRoot-node")); 
    VfxAssetLoader::loadSceneEnd();
    
    if(m_plateMesh)
        m_plateMesh->setPickable(VFX_TRUE);
    if(m_plateRoot)
        m_plateRoot->sendToBack();

    setupItemIcon();
    setupItemFocus();
    
    MEDIA_CENTER_MEASURE_TIME_STOP("MI0");
}

void VappMediaCenterAppItem::onDeinit()
{
    _ME_TRACE_1("[MediaCenter][Item] onDeinit(), id = %d", m_index);
    MEDIA_CENTER_MEASURE_TIME_START("MI9");

    removeFocusOpeningAnim();
    removeFocusAnim();

    m_plateAnim->setCustomTimingFunc(NULL, NULL, 0);
    m_plateAnim->setTimelineTime(NULL);
    m_opacityTL->setCustomTimingFunc(NULL, NULL, 0);
    m_opacityTL->setTimelineTime(NULL);
    VfxGroup::onDeinit();
    
    MEDIA_CENTER_MEASURE_TIME_STOP("MI9");
}
void VappMediaCenterAppItem::configItemAnim(VfxAnimation *plateAnim)
{
    VFX_OBJ_CLOSE(m_plateAnim);
    m_plateAnim = plateAnim;
}

void VappMediaCenterAppItem::configItemOpacTL(VfxFloatTimeline *tl)
{
    VFX_OBJ_CLOSE(m_opacityTL);
    m_opacityTL = tl;
}

void VappMediaCenterAppItem::setIndex(const VfxS32 index)
{
    m_index= index;
}

VfxS32 VappMediaCenterAppItem::getIndex() const
{
    return m_index;
}

VfxBool VappMediaCenterAppItem::isPicked(VfxNode *node) const
{    
    if(m_plateMesh && (m_plateMesh == node))
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

void VappMediaCenterAppItem::focus()
{
    _ME_TRACE_1("[MediaCenter][Item] focus(), id = %d", m_index);
    MEDIA_CENTER_MEASURE_TIME_START("MIF");

    bringToFront();
    if(m_flashMesh)
        m_flashMesh->bringToFront();
    
    showItemIcon(VFX_FALSE);
    showItemFocus(VFX_TRUE);

    setupItemFocusOpeningAnim();
    startItemFocusOpeningAnim();
    
    MEDIA_CENTER_MEASURE_TIME_STOP("MIF");    
}

void VappMediaCenterAppItem::unfocus()
{
    _ME_TRACE_1("[MediaCenter][Item] unfocus(), id = %d", m_index);
    MEDIA_CENTER_MEASURE_TIME_START("MIU");

    showItemIcon(VFX_TRUE);
    showItemFocus(VFX_FALSE);
    
    removeFocusOpeningAnim();
    removeFocusAnim();

    if(g_releaseFocusItemWhileUnfcus)
    {
        VFX_OBJ_CLOSE(m_focus);
        m_focus = NULL;
    }
    
    MEDIA_CENTER_MEASURE_TIME_STOP("MIU");    
}

void VappMediaCenterAppItem::removeFocusOpeningAnim()
{
    _ME_TRACE_1("[MediaCenter][Item] removeFocusOpeningAnim(), id = %d", m_index);

    stopItemFocusOpeningAnim();
    VFX_OBJ_CLOSE(m_openingAnimPly);
    m_openingAnimPly = NULL;
}
void VappMediaCenterAppItem::removeFocusAnim()
{
    _ME_TRACE_1("[MediaCenter][Item] removeFocusAnim(), id = %d", m_index);

    stopItemFocusAnim();
    VFX_OBJ_CLOSE(m_focusPlayer);
    m_focusPlayer = NULL;
}

void VappMediaCenterAppItem::setupItemIcon()
{
    if(m_icon){return;}
    
    VFX_OBJ_CREATE(m_icon, VfxGroup, m_plateRoot);
    VfxAssetLoader::loadScene(m_icon, m_resource.m_iconScene);
}

void VappMediaCenterAppItem::setupItemFocus()
{
    if(m_focus){return;}
     
    VFX_OBJ_CREATE(m_focus, VfxGroup, m_plateRoot);
    VfxAssetLoader::loadSceneBegin(m_focus, m_resource.m_focusScene);
    if(0 == m_resource.m_index)
    {
        m_flashMesh = (VfxMesh *)VfxAssetLoader::findObjByName(VFX_STR("flash-node"));
        _ME_TRACE_1("[MediaCenter][Item] setupItemFocus, m_flashMesh = %x", m_flashMesh);        
    }
    VfxAssetLoader::loadSceneEnd();
    
    m_focus->setTranslation(VfxVector3f(0, 0, 10.f));
    m_focus->bringToFront();
    m_focus->setOpacity(0.f);    
} 

void VappMediaCenterAppItem::setupItemFocusOpeningAnim()
{
    if((NULL == m_focus) || m_openingAnimPly)
    {
        return;
    }
    _ME_TRACE_1("[MediaCenter][Item] setupItemFocusOpeningAnim(), id = %d", m_index);
    
    VFX_OBJ_CREATE(m_openingAnimPly, VappMediaCenterAnimTimeline, m_focus);
    m_openingAnimPly->configAnim(m_resource.m_focusOpeningAnim, m_focus);    
}

void VappMediaCenterAppItem::setupItemFocusAnim()
{
    _ME_TRACE_1("[MediaCenter][Item] setupItemFocusAnim(), id = %d", m_index);

    setupItemFocusAnimPlayer();
    setupItemFocusAnimPlaylist();
}
void VappMediaCenterAppItem::setupItemFocusAnimPlayer()
{
    if((NULL == m_focus) || m_focusPlayer)
    {
        return;
    }

    _ME_TRACE_1("[MediaCenter][Item] setupItemFocusAnimPlayer(), id = %d", m_index);
    MEDIA_CENTER_MEASURE_TIME_START("MIP");

    VappMediaCenterAnimPlayerOption option;
    if(VFX_TRUE == m_resource.m_focusAnimRandomDecks)
    {
        option.configAsRadioDJ();
    }
    else
    {
        option.configAsGeneralCase();
    }
    
    VFX_OBJ_CREATE_EX(m_focusPlayer, VappMediaCenterAnimPlayer, m_focus, (option));
    m_focusPlayer->configTarget(m_focus);
    
    MEDIA_CENTER_MEASURE_TIME_STOP("MIP");
}

void VappMediaCenterAppItem::setupItemFocusAnimPlaylist()
{
    VfxS32 animCount = 0;
    m_provider->getAppItemFocusAnimCount(getIndex(), animCount);
    if((NULL == m_focus) || 
       (NULL == m_focusPlayer) ||
       (animCount <= m_focusPlayer->getTotalAnimCount()))
    {
        // already init playlist content
        return;
    }

    VappMediaCenter3DResPath path;
    for(int i = 0; i < animCount; i++)
    {
        m_provider->getAppItemFocusAnim(m_index, i, path);
            
        VfxAnimation *anim = NULL;
        VFX_OBJ_CREATE(anim, VfxAnimation, getFocusItemHandle());    
        VfxAssetLoader::loadAnimation(anim, getFocusItemHandle(), path); 
        addItemFocusAnim(anim);
    }
}

void VappMediaCenterAppItem::onFocusOpeningTimeout(VfxBaseTimeline *timeline, VfxBool isComplete)
{
    _ME_TRACE_2("[MediaCenter][Item] onFocusOpeningTimeout[%d], isComplete[%d]", m_index, isComplete);
    if(!isComplete){return;}
    stopItemFocusOpeningAnim();
    
    setupItemFocusAnim();
    playItemFocusAnim();
    
    m_sigOpeningAnimFinished.emit(m_index);
}

void VappMediaCenterAppItem::addItemFocusAnim(VfxAnimation *anim)
{
    if(m_focusPlayer)
    {
        m_focusPlayer->addToPlaylist(anim);
    }
}

VfxBool VappMediaCenterAppItem::isItemFocusHidden() const
{
    if(m_focus)
    {
        return ((m_focus->getOpacity() == 0.f)? VFX_TRUE : VFX_FALSE); 
    }
    return VFX_FALSE;
}

VfxBool VappMediaCenterAppItem::hasFlashMesh()const
{
    return ((m_flashMesh)? VFX_TRUE : VFX_FALSE);
}

void VappMediaCenterAppItem::resetFlahMeshInSceneThree()
{
    bringToFront();
    if(m_flashMesh)
        m_flashMesh->bringToFront();
}

void VappMediaCenterAppItem::startItemFocusOpeningAnim()
{
    if(NULL == m_openingAnimPly){return;}
    m_openingAnimPly->m_signalStopped.connect(this, &VappMediaCenterAppItem::onFocusOpeningTimeout);
    m_openingAnimPly->start();
}

void VappMediaCenterAppItem::stopItemFocusOpeningAnim()
{
    if(NULL == m_openingAnimPly){return;}
    m_openingAnimPly->m_signalStopped.disconnect(this, &VappMediaCenterAppItem::onFocusOpeningTimeout);
    m_openingAnimPly->stop();
}

void VappMediaCenterAppItem::playItemFocusAnim()
{
    if(NULL == m_focusPlayer){return;}
    m_focusPlayer->play();
}
void VappMediaCenterAppItem::stopItemFocusAnim()
{
    if(NULL == m_focusPlayer){return;}
    m_focusPlayer->stop();
}

void VappMediaCenterAppItem::showItemIcon(const VfxBool b)
{
    if(m_icon)
    {
        const VfxFloat opacity = (b)? 1.f: 0.f;
        m_icon->setOpacity(opacity);
    }

}

void VappMediaCenterAppItem::showItemFocus(const VfxBool b)
{
    if(m_focus)
    {
        const VfxFloat opacity = (b)? 1.f: 0.f;
        m_focus->setOpacity(opacity);
    }
}

/***************************************************************************** 
 * Class Implementation : VappMediaCenterAppItems
 *****************************************************************************/
const VappMediaCenterAppItemData VappMediaCenterAppItems::s_appItemData[] = {
        {"native.mtk.camcorder", 0},
        {"native.mtk.musicplayer", 0},
		{"native.mtk.soundrec", 0},
        {"native.mtk.fmradio", 0},
        {"native.mtk.gallery", 0},
};

VappMediaCenterAppItems::VappMediaCenterAppItems()
{
}

VfxS32 VappMediaCenterAppItems::getAppItemCount()
{
    return sizeof(s_appItemData) / sizeof(s_appItemData[0]);
}

VfxBool VappMediaCenterAppItems::launchAppItem(const VfxS32 index)
{
    MMI_ID appId = srv_appmgr_launch(getAppItemData(index).m_appId);
    if(GRP_ID_INVALID == appId)
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][AppItems] launchAppItem[%d], fail[%d]", index, appId);
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

void VappMediaCenterAppItems::getAppItemTitle(const VfxS32 index, VfxWString &title) 
{    
    WCHAR appName[MMI_APP_NAME_MAX_LEN];
    srv_appmgr_get_app_package_name(getAppItemData(index).m_appId, appName);
    title.loadFromMem(appName);
} 

VfxGroup* VappMediaCenterAppItems::createAppItem(const VfxS32 index, VfxGroup *parent)
{
    _ME_TRACE_1("[MediaCenter][AppItems] createAppItem(), index = %d", index);
    MEDIA_CENTER_MEASURE_TIME_START("MPI");
    
    VappMediaCenterAppItemResource res;
    res.m_index = index;
    res.m_contentId = index % getAppItemCount();
    res.m_focusAnimCount = getAppItemFocusAnimCount(index);
    res.m_focusAnimRandomDecks = getAppItemFocusAnimUseRandomDecks(index);
    getAppItemPlateScene(res.m_contentId, res.m_plateScene);
    getAppItemIconScene(res.m_contentId, res.m_iconScene);
    getAppItemFocusScene(res.m_contentId, res.m_focusScene);
    getAppItemFocusOpeningAnim(res.m_contentId, res.m_focusOpeningAnim);
    getAppItemFocusClosingAnim(res.m_contentId, res.m_focusClosingAnim);
    
    VappMediaCenterAppItem *item = NULL; 
    VFX_OBJ_CREATE_EX(item, VappMediaCenterAppItem, parent, (this, res));

    MEDIA_CENTER_MEASURE_TIME_STOP("MPI");
    return item;
}

VfxBool VappMediaCenterAppItems::isValidAppItemIndex(const VfxS32 index)
{
    if(index < 0 || index >= getAppItemCount())
    {
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

const VappMediaCenterAppItemData& VappMediaCenterAppItems::getAppItemData(const VfxS32 index)
{
    if(index < 0 || index >= getAppItemCount())
    {
        return s_appItemData[0];
    }
    return s_appItemData[index];
}

void VappMediaCenterAppItems::getAppItemFocusAnimCount(const VfxS32 index, VfxS32 &count) 
{
    if(!isValidAppItemIndex(index))
    { 
        count = 0;
        return;
    }
    
    const VfxResId arr[] = {2, 5, 3, 1, 1};
    count = arr[index]; 
}

VfxS32 VappMediaCenterAppItems::getAppItemFocusAnimCount(const VfxS32 index) 
{
    if(!isValidAppItemIndex(index))
    {
        return 0;
    }

    const VfxS32 arr[] = {2, 5, 3, 1, 1};
    return arr[index]; 
}
VfxBool VappMediaCenterAppItems:: getAppItemFocusAnimUseRandomDecks(const VfxS32 index) 
{
    if(!isValidAppItemIndex(index))
    {
        return VFX_FALSE;
    }

    VfxBool randomDecks = (3 == index)? VFX_TRUE : VFX_FALSE;
    return randomDecks;
}

VfxImageSrc VappMediaCenterAppItems::getAppItemTitleBoardIconScr(const VfxS32 index)
{
    if(!isValidAppItemIndex(index))
    {
        return VfxImageSrc();
    }

    const VfxResId arr[] = {IMG_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_CAMERA, 
                            IMG_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_MUSIC, 
                            IMG_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_SOUNDREC, 
                            IMG_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_RADIO, 
                            IMG_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_GALLERY};
     
    VfxImageSrc src = VfxImageSrc(arr[index]);
    return src;
}

void VappMediaCenterAppItems::getAppItemPlateScene(const VfxS32 index, VfxResId &id) const
{
	id = SCN_ID_VAPP_MEDIA_CENTER_PLATE;
}

void VappMediaCenterAppItems::getAppItemPlateAnim(const VfxS32 index, VfxResId &id) const
{
	id = ANI_ID_VAPP_MEDIA_CENTER_PLATE_ANIM;
}

void VappMediaCenterAppItems::getAppItemIconScene(const VfxS32 index, VfxResId &id) const
{
    const VfxResId arr[] = {
						SCN_ID_VAPP_MEDIA_CENTER_ITEM_CAMERA_ICON, 
                        SCN_ID_VAPP_MEDIA_CENTER_ITEM_MUSIC_PLY_ICON, 
                        SCN_ID_VAPP_MEDIA_CENTER_ITEM_SOUND_REC_ICON,
                        SCN_ID_VAPP_MEDIA_CENTER_ITEM_FM_ICON, 
                        SCN_ID_VAPP_MEDIA_CENTER_ITEM_GALLERY_ICON};
    id = arr [index];
}

void VappMediaCenterAppItems::getAppItemFocusScene(const VfxS32 index, VfxResId &id) const
{
    const VfxResId arr[] = {
						SCN_ID_VAPP_MEDIA_CENTER_ITEM_CAMERA_FOCUS, 
                        SCN_ID_VAPP_MEDIA_CENTER_ITEM_MUSIC_PLY_FOCUS, 
                        SCN_ID_VAPP_MEDIA_CENTER_ITEM_SOUND_REC_FOCUS,
                        SCN_ID_VAPP_MEDIA_CENTER_ITEM_FM_FOCUS, 
                        SCN_ID_VAPP_MEDIA_CENTER_ITEM_GALLERY_FOCUS};
    id = arr [index];
}

void VappMediaCenterAppItems::getAppItemFocusOpeningAnim(const VfxS32 index, VfxResId &id) const
{
    const VfxResId arr[] = {
						ANI_ID_VAPP_MEDIA_CENTER_ITEM_CAMERA_FOCUS_OPENING_ANIM, 
                        ANI_ID_VAPP_MEDIA_CENTER_ITEM_MUSIC_PLY_FOCUS_OPENING_ANIM, 
                        ANI_ID_VAPP_MEDIA_CENTER_ITEM_SOUND_REC_FOCUS_OPENING_ANIM,
                        ANI_ID_VAPP_MEDIA_CENTER_ITEM_FM_FOCUS_OPENING_ANIM, 
                        ANI_ID_VAPP_MEDIA_CENTER_ITEM_GALLERY_FOCUS_OPENING_ANIM};
    id = arr [index];
}

void VappMediaCenterAppItems::getAppItemFocusClosingAnim(const VfxS32 index, VfxResId &id) const
{
	getAppItemFocusOpeningAnim(index, id);
}

void VappMediaCenterAppItems::getAppItemFocusAnim(const VfxS32 index, const VfxS32 animId, VfxResId &id) const
{
    switch(index)
    {
    case 0:
        id = ANI_ID_VAPP_MEDIA_CENTER_ITEM_CAMERA_FOCUS_ANIM_1 + animId;
        break;
    case 1:
        id = ANI_ID_VAPP_MEDIA_CENTER_ITEM_MUSIC_PLY_FOCUS_ANIM_1 + animId;
        break;
    case 2:
        id = ANI_ID_VAPP_MEDIA_CENTER_ITEM_SOUND_REC_FOCUS_ANIM_1 + animId;
        break;
    case 3:
        id = ANI_ID_VAPP_MEDIA_CENTER_ITEM_FM_FOCUS_ANIM_1 + animId;
        break;
    case 4:
        id = ANI_ID_VAPP_MEDIA_CENTER_ITEM_GALLERY_FOCUS_ANIM_1 + animId;
		break;
    default:
        break;
    } 
}

void VappMediaCenterAppItems::getAppItemPlateScene(const VfxS32 index, VfxWString &path) const
{
    path = VFX_WSTR("D:\\MediaCenter\\plate\\plate.scn");
}

void VappMediaCenterAppItems::getAppItemPlateAnim(const VfxS32 index, VfxWString &path) const
{
    path = VFX_WSTR("D:\\MediaCenter\\plate\\plate.ani");
}

void VappMediaCenterAppItems::getAppItemIconScene(const VfxS32 index, VfxWString &path) const
{
    switch(index)
    {
    case 0:
        path = VFX_WSTR("D:\\MediaCenter\\cameraIcon\\cameraIcon.scn");
        break;
    case 1:
        path = VFX_WSTR("D:\\MediaCenter\\musicIcon\\musicIcon.scn");
        break;
    case 2:
        path = VFX_WSTR("D:\\MediaCenter\\soundrecIcon\\soundrecIcon.scn");
        break;
    case 3:
        path = VFX_WSTR("D:\\MediaCenter\\radioIcon\\radioIcon.scn");
        break;
    case 4:
	    path = VFX_WSTR("D:\\MediaCenter\\galleryIcon\\galleryIcon.scn");
		break;
    default:
        break;
    } 
}

void VappMediaCenterAppItems::getAppItemFocusScene(const VfxS32 index, VfxWString &path) const
{
    // note the *.dae used skinned mesh should convert to *.chr (charactor)
    switch(index)
    {
    case 0:
        path = VFX_WSTR("D:\\MediaCenter\\cameraFocus\\cameraFocus.scn");
        break; 
    case 1:
        path = VFX_WSTR("D:\\MediaCenter\\musicFocus\\musicFocus.chr");
        break;
    case 2:
        path = VFX_WSTR("D:\\MediaCenter\\soundrecFocus\\soundrecFocus.scn");
        break;
    case 3:
        path = VFX_WSTR("D:\\MediaCenter\\radioFocus\\radioFocus.scn");
        break;
    case 4:
        path = VFX_WSTR("D:\\MediaCenter\\galleryFocus\\galleryFocus.scn");
        break;
    default:
        break;
    } 
}

void VappMediaCenterAppItems::getAppItemFocusOpeningAnim(const VfxS32 index, VfxWString &path) const
{
    switch(index)
    {
    case 0:
        path = VFX_WSTR("D:\\MediaCenter\\cameraFocus\\cameraFocus_0_1000.ani");
        break;
    case 1:
        path = VFX_WSTR("D:\\MediaCenter\\musicFocus\\musicFocus_0_4500.ani");
        break;
    case 2:
        path = VFX_WSTR("D:\\MediaCenter\\soundrecFocus\\soundrecFocus_0_4000.ani");
        break;
    case 3:
        path = VFX_WSTR("D:\\MediaCenter\\radioFocus\\radioFocus_0_3000.ani");
        break;
    case 4:
        path = VFX_WSTR("D:\\MediaCenter\\galleryFocus\\galleryFocus_0_4000.ani");
        break;
    default:
        break;
    } 
}

void VappMediaCenterAppItems::getAppItemFocusClosingAnim(const VfxS32 index, VfxWString &path) const
{
	getAppItemFocusOpeningAnim(index, path);
}

void VappMediaCenterAppItems::getAppItemFocusAnim(const VfxS32 index, const VfxS32 animId, VfxWString &path) const
{
    switch(index)
    {
        case 0:
        {
            VfxWString arr[] = { 
                VFX_WSTR("D:\\MediaCenter\\cameraFocus\\cameraFocus_1266_5000.ani"),
                VFX_WSTR("D:\\MediaCenter\\cameraFocus\\cameraFocus_5166_10666.ani")};
            path = arr[animId];
            break;
        }
        case 1:
        {
            VfxWString arr[] = { 
                VFX_WSTR("D:\\MediaCenter\\musicFocus\\musicFocus_4666_7000.ani"),
                VFX_WSTR("D:\\MediaCenter\\musicFocus\\musicFocus_9133_9333.ani"), 
                VFX_WSTR("D:\\MediaCenter\\musicFocus\\musicFocus_13600_13666.ani"),
                VFX_WSTR("D:\\MediaCenter\\musicFocus\\musicFocus_13666_16866.ani"),
                VFX_WSTR("D:\\MediaCenter\\musicFocus\\musicFocus_17000_18533.ani")};
            path = arr[animId];
            break;
        }
        case 2:
        {
            VfxWString arr[] = { 
                VFX_WSTR("D:\\MediaCenter\\soundrecFocus\\soundrecFocus_4166_7866.ani"),
                VFX_WSTR("D:\\MediaCenter\\soundrecFocus\\soundrecFocus_8000_13166.ani"),
                VFX_WSTR("D:\\MediaCenter\\soundrecFocus\\soundrecFocus_13333_17500.ani")};
            path = arr[animId];
            break;
        }
        case 3:
        {
            path = VFX_WSTR("D:\\MediaCenter\\radioFocus\\radioFocus_3166_4333.ani");
            break;
        }
        case 4:
        {
            path = VFX_WSTR("D:\\MediaCenter\\galleryFocus\\galleryFocus_4033_8066.ani");
            break;
        }
    default:
        break;
    } 

}

#endif // __COSMOS_3D_MEDIA_CENTER__
