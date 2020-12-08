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
 *  vapp_media_center_item.h
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
#ifndef __VAPP_MEDIA_CENTER_MENU_ITEM_H__
#define __VAPP_MEDIA_CENTER_MENU_ITEM_H__

#include "MMI_features.h"
#ifdef __MMI_3D_MEDIA_CENTER__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_asset_loader.h"
#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_mesh.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_shader_uniforms.h"
#include "vfx_shader.h"
#include "vfx_texture.h"
#include "vfx_light.h"
#include "vfx_bounding_volume.h"
#include "vfx_render_buffer.h"

#include "vapp_media_center_anim.h"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VappMediaCenterAppItem;
class VappMediaCenterAppItems;
class VappMediaCenterAppItemResource;

// use 3D resource with file mode while  __MEDIA_CENTER_FILE_MODE__ is defined (quick prototyping usage)
//#define __MEDIA_CENTER_FILE_MODE__
#ifdef __MEDIA_CENTER_FILE_MODE__
    typedef VfxWString VappMediaCenter3DResPath;
#else 
    typedef VfxResId VappMediaCenter3DResPath;
#endif

/***************************************************************************** 
 * Class : Resource
 *****************************************************************************/
class VappMediaCenterAppItemResource : public VfxBase
{
public:
	VappMediaCenterAppItemResource(){};
    
public:
    VfxS32 m_index;  
    VfxS32 m_contentId;
    VfxS32 m_focusAnimCount;
    VfxBool m_focusAnimRandomDecks;

    VappMediaCenter3DResPath m_plateScene;
    VappMediaCenter3DResPath m_iconScene;
    VappMediaCenter3DResPath m_focusScene;
    VappMediaCenter3DResPath m_focusOpeningAnim;
    VappMediaCenter3DResPath m_focusClosingAnim;
};

/***************************************************************************** 
 * Class : AppItems
 *****************************************************************************/
struct VappMediaCenterAppItemData
{
    VfxChar *m_appId;
    VfxId m_appRes;
};


// TODO: Remove VappMediaCenterAppItemResource
// TODO:  Add contentId for duplicated content usage

class VappMediaCenterAppItem : public VfxGroup
{
    VFX_DECLARE_CLASS(VappMediaCenterAppItem);
    VfxSignal1<VfxS32> m_sigOpeningAnimFinished;
public:
    VappMediaCenterAppItem()
        :m_icon(NULL),
        m_focus(NULL),
        m_plateMesh(NULL),
        m_plateRoot(NULL),
        m_plateAnim(NULL),
        m_opacityTL(NULL),
        m_openingAnimPly(NULL),
        m_flashMesh(NULL),        
        m_focusPlayer(NULL),
        m_index(-1)
        {};
    
    VappMediaCenterAppItem(VappMediaCenterAppItems *provider, 
                                   const VappMediaCenterAppItemResource &res) 
        :m_icon(NULL),
        m_focus(NULL),
        m_plateMesh(NULL),
        m_plateRoot(NULL),
        m_plateAnim(NULL),
        m_opacityTL(NULL),
        m_openingAnimPly(NULL),
        m_focusPlayer(NULL),
        m_flashMesh(NULL),
        m_index(-1),
        m_resource(res)
    {
        VFX_DEV_ASSERT(provider);
        
        m_provider = provider;
        setIndex(m_resource.m_index % 5);
    };

    VappMediaCenterAppItem(VappMediaCenterAppItems *provider, 
                                   const VfxS32 index) 
        :m_icon(NULL),
        m_focus(NULL),
        m_plateMesh(NULL),
        m_plateRoot(NULL),
        m_plateAnim(NULL),
        m_opacityTL(NULL),
        m_openingAnimPly(NULL),  
        m_flashMesh(NULL),                
        m_focusPlayer(NULL),
        m_index(-1)
    {
        VFX_DEV_ASSERT(provider);

        m_provider = provider;
        setIndex(index);
    };    

protected:
    virtual void onInit();
    virtual void onDeinit();

public:    
    // general setting
    void configItemAnim(VfxAnimation *plateAnim);
    void configItemOpacTL(VfxFloatTimeline *tl);
    
    void setIndex(const VfxS32 index);
    VfxS32 getIndex() const;
    VfxBool isPicked(VfxNode *node) const;    

    void focus();
    void unfocus();
    void addItemFocusAnim(VfxAnimation *anim);
    VfxGroup* getFocusItemHandle(){ return m_focus;};

    VfxBool isItemFocusHidden() const;
    VfxBool hasFlashMesh()const;
    void resetFlahMeshInSceneThree();

private:
    void setupItemIcon();
    void setupItemFocus();
    void setupItemFocusOpeningAnim();
    void setupItemFocusAnim();
    void removeFocusOpeningAnim();
    void removeFocusAnim();

    
    void setupItemFocusAnimPlayer();
    void setupItemFocusAnimPlaylist();
    
    void onFocusOpeningTimeout(VfxBaseTimeline *timeline, VfxBool isComplete);
    
    void startItemFocusOpeningAnim();
    void stopItemFocusOpeningAnim();
    void playItemFocusAnim();
    void stopItemFocusAnim();
    
    void showItemIcon(const VfxBool b);
    void showItemFocus(const VfxBool b);
    
private:    
    VfxS32 m_index;
    VfxWeakPtr<VappMediaCenterAppItems> m_provider;
    VappMediaCenterAppItemResource m_resource;

    // plate general resource    
    VfxMesh *m_plateMesh;
    VfxGroup *m_plateRoot;
    VfxAnimation *m_plateAnim;
    VfxFloatTimeline *m_opacityTL;
    //     
    VfxGroup *m_icon;
    VfxGroup *m_focus;
    VappMediaCenterAnimPlayer *m_focusPlayer; 
    
    VfxMesh* m_flashMesh;
    
public:
    VappMediaCenterAnimTimeline *m_openingAnimPly;    
};


// TODO: define pure virtual funtion for constent provider usuage
// VappMediaCenterAppItems is the helper class that creates VappMediaCenterAppItem and manage VappMediaCenterAppItemData
class VappMediaCenterAppItems : public VfxObject
{
    VFX_DECLARE_CLASS(VappMediaCenterAppItems);
public:
    VappMediaCenterAppItems();


    VfxS32 getAppItemCount();
    VfxBool launchAppItem(VfxS32 index);
    void getAppItemTitle(const VfxS32 index, VfxWString &title);
    VfxGroup* createAppItem(const VfxS32 index, VfxGroup *parent);
    VfxBool isValidAppItemIndex(const VfxS32 index);
    
public:
    const VappMediaCenterAppItemData& getAppItemData(VfxS32 index);

    void getAppItemFocusAnimCount(const VfxS32 index, VfxS32 &count);

    VfxS32 getAppItemFocusAnimCount(const VfxS32 index) ;
    VfxBool getAppItemFocusAnimUseRandomDecks(const VfxS32 index);
    VfxImageSrc getAppItemTitleBoardIconScr(const VfxS32 index);

    // resource mode  
    void getAppItemPlateScene(const VfxS32 index, VfxResId &id) const;
    void getAppItemPlateAnim(const VfxS32 index, VfxResId &id) const;
    void getAppItemIconScene(const VfxS32 index, VfxResId &id) const;    
    void getAppItemFocusScene(const VfxS32 index, VfxResId &id) const;
    void getAppItemFocusOpeningAnim(const VfxS32 index, VfxResId &id) const;
    void getAppItemFocusClosingAnim(const VfxS32 index, VfxResId &id) const;
    void getAppItemFocusAnim(const VfxS32 index, const VfxS32 animId, VfxResId &id) const;

    // file mode
    void getAppItemPlateScene(const VfxS32 index, VfxWString &path) const;
    void getAppItemPlateAnim(const VfxS32 index, VfxWString &path) const;
    void getAppItemIconScene(const VfxS32 index, VfxWString &path) const;
    void getAppItemFocusScene(const VfxS32 index, VfxWString &path) const;    
    void getAppItemFocusOpeningAnim(const VfxS32 index, VfxWString &path) const;   
    void getAppItemFocusClosingAnim(const VfxS32 index, VfxWString &path) const;
    void getAppItemFocusAnim(const VfxS32 index, const VfxS32 animId, VfxWString &path) const;

private:
    const static VappMediaCenterAppItemData s_appItemData[];
};

#endif // __COSMOS_3D_MEDIA_CENTER__
#endif // __VAPP_MEDIA_CENTER_MENU_ITEM_H__ 

