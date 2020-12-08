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
 *  vapp_music_player_util.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player utility functions
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#ifndef __VAPP_MUSIC_PLAYER_UTIL_H__
#define __VAPP_MUSIC_PLAYER_UTIL_H__

#include "mmi_rp_vapp_music_player_def.h"
#include "vapp_music_player.h"
#include "vapp_music_player_service.h"

/***************************************************************************** 
 * utility function
 *****************************************************************************/

inline VfxObject* findObject(VfxObject *obj, VfxClassInfo *classInfo)
{
    VfxObject *pObj = obj;
    do {
        pObj = pObj->getParent();

        VFX_ASSERT(pObj);

        if(pObj->isKindOf(classInfo))
           return pObj;

    } while(pObj);

    return NULL;
}

inline VfxApp* findRootApp(VfxObject *obj)
{
    VfxApp *pApp = NULL;
    for(VfxObject *pObj = obj; pObj != NULL; pObj = pObj->getParent())
    {
        pApp = VFX_OBJ_DYNAMIC_CAST(pObj, VfxApp);
        if(pApp != NULL)
        {
            return pApp;
        }
    }

    // root should be VfxApp
    VFX_ASSERT(0);
    return NULL;
}

inline VappMusicPlayerApp* getMusicPlayerApp()
{
    VfxApp *app = VfxAppLauncher::findApp(
                    VAPP_MUSIC_PLAYER, 
                    VFX_OBJ_CLASS_INFO(VappMusicPlayerApp), 
                    VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);

    return VFX_OBJ_DYNAMIC_CAST(app, VappMusicPlayerApp);
}

inline VappMusicPlayerService* getMusicPlayerSrv()
{
    VappMusicPlayerService *srv = VFX_OBJ_GET_INSTANCE(VappMusicPlayerService);
    return srv;
}

inline void setDefaultCover(VfxFrame *f, VfxBool useDefSize, VfxU32 width, VfxU32 height, VfxBool noText)
{
#if defined(__MMI_MAINLCD_240X320__)
    VfxSize defCoverSize(140, 140);
    VfxSize iconSize(66, 63);
    VfxU32 iconXPos = 64;
    VfxU32 iconYPosWithText = 43;
#elif defined(__MMI_MAINLCD_240X400__)
    VfxSize defCoverSize(162, 162);
    VfxSize iconSize(75, 72);
    VfxU32 iconXPos = 76;
    VfxU32 iconYPosWithText = 47;
#elif defined(__MMI_MAINLCD_320X480__)
    VfxSize defCoverSize(180, 180);
    VfxSize iconSize(84, 80);
    VfxU32 iconXPos = 85;
    VfxU32 iconYPosWithText = 53;
#else //(__MMI_MAINLCD_480X800__)
    VfxSize defCoverSize(234, 234);
    // cosmos slim does not support WVGA yet
    VfxSize iconSize(1, 1);
    VfxU32 iconXPos = 1;
    VfxU32 iconYPosWithText = 1;
#endif

    VfxSize size;
    if (useDefSize)
    {
        size = defCoverSize;
    }
    else
    {
        size.width = width;
        size.height = height;
    }

#ifdef __LOW_COST_SUPPORT_COMMON__

    VfxFloat scale = VfxFloat(size.width) / defCoverSize.width;

    VfxImageSrc imgSrc;
    imgSrc.setResId(IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER_BG);
    f->setImgContent(imgSrc);
    f->setSize(size);
    f->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VfxImageSrc imgSrc2;
    imgSrc2.setResId(IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER_ICON);
    VfxFrame *icon;
    VFX_OBJ_CREATE(icon, VfxFrame, f);
    icon->setAnchor(0.5, 0.5);
    icon->setPos(iconXPos * scale, noText ? size.height / 2 : (iconYPosWithText * scale));
    icon->setSize(iconSize.width * scale, iconSize.height * scale);
    icon->setImgContent(imgSrc2);
    icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    
#else

    VfxImageSrc imgSrc;
    imgSrc.setResId(noText? IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER_NO_TEXT : IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER);
    f->setImgContent(imgSrc);
    f->setSize(size);
    f->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);

#endif
}

inline VfxFrame* dropShadow(VfxObject *parent, VfxRect &rect, VfxBool isAnim)
{
#if defined(__MMI_MAINLCD_480X800__)
    const VfxU32 shadowSize = 12;
    const VfxU32 shadowDistance = 1;
#else //(__MMI_MAINLCD_240X320__, __MMI_MAINLCD_240X400__, __MMI_MAINLCD_320X480__)
    const VfxU32 shadowSize = 7;
    const VfxU32 shadowDistance = 1;
#endif

    VfxFrame *f;
    VFX_OBJ_CREATE(f, VfxFrame, parent);
    f->setSize(rect.getWidth() + shadowSize, rect.getHeight() + shadowSize);
    f->setPos(rect.getX(), rect.getY());

    VfxFrame *r;
    VFX_OBJ_CREATE(r, VfxFrame, f);
    r->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_DROP_SHADOW_R));
    r->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    r->setSize(shadowSize, rect.getHeight() - shadowDistance);
    r->setPos(rect.getWidth(), shadowDistance);

    VfxFrame *d;
    VFX_OBJ_CREATE(d, VfxFrame, f);
    d->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_DROP_SHADOW_D));
    d->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    d->setSize(rect.getWidth() + shadowSize - shadowDistance, shadowSize);
    d->setPos(shadowDistance, rect.getHeight());

    if (isAnim)
    {
        r->setOpacity(0.0f);
        r->setAutoAnimate(VFX_TRUE);
        d->setOpacity(0.0f);
        d->setAutoAnimate(VFX_TRUE);
        
        VfxAutoAnimate::initAnimateBegin();
        VfxAutoAnimate::begin();
        {
            VfxAutoAnimate::setDisable(VFX_FALSE);
            VfxAutoAnimate::setDuration(300);
            VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE);
            
            r->setOpacity(1.0f);
            d->setOpacity(1.0f);
        }
        VfxAutoAnimate::commit();
        VfxAutoAnimate::initAnimateEnd();
    }   

    return f;
}

inline VfxBool isFileExist(const VfxWChar *filePath)
{
    FS_HANDLE handle;
    handle = FS_Open(filePath, FS_READ_ONLY);
    if (handle != NULL)
    {
        FS_Close(handle);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

inline VfxBool checkIsASCIIChar(VfxWChar *code)
{
    if ((0x0020 <= *code) && (*code <= 0x0080))
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

#endif /*   __VAPP_MUSIC_PLAYER_UTIL_H__    */

#endif //__COSMOS_MUSICPLY__
