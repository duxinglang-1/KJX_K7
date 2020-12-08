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
 *  vapp_wallpaper_file_factory.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the MRE factory of the screen lock.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_wallpaper_def.h"
#include "vapp_wallpaper_file_factory.h"
#include "vapp_wallpaper_frame_video.h"
#include "vapp_wallpaper_interactive_video.h"

extern "C"
{
#include "fs_gprot.h"
#include "FileMgrGprot.h"
#include "Unicodexdcl.h"
#include "MMI_trc_Int.h"
#include "MMI_common_app_trc.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MWP_WALLPAPER_FOLDER "@wallpaper_mwp"
/***************************************************************************** 
 * WallpaperFile Implementations
 *****************************************************************************/
VfxWString WallpaperFile::getRootFolder()
{
    VfxWString folder;
    folder.format("%c:\\%s\\", SRV_FMGR_CARD_DRV, MWP_WALLPAPER_FOLDER);
    return folder;
}

void WallpaperFile::fromWallpaperId(const VappWallpaperId &id, WallpaperFile &f)
{
    #ifdef WIN32
    mmi_asc_to_wcs(f.filePath, (CHAR*)id.getStringType());
    #else
    id.getIntPairType(f.hintCluster, f.hintIndex);
    #endif
}

FS_HANDLE WallpaperFile::openFileHandle() const
{
    FS_HANDLE hFile = NULL;
#if defined(__MTK_TARGET__)
    hFile = FS_OpenFileByHint((WCHAR)SRV_FMGR_CARD_DRV, hintCluster, hintIndex, FS_READ_ONLY);
#else
    // MoDIS does not support hint.
    hFile = FS_Open(filePath, FS_READ_ONLY);
#endif
    return hFile;
}

VfxWString WallpaperFile::getFilePath() const
{
    VfxWString wstr;
#ifndef __MTK_TARGET__
    wstr = VFX_WSTR_MEM(filePath);
#else
    do
    {
        int hnd = FS_OpenFileByHint((WCHAR)SRV_FMGR_CARD_DRV, hintCluster, hintIndex, FS_READ_ONLY);
        if(hnd)
        {  
            WCHAR *buf = (WCHAR*)wstr.lockBuf(FS_MAX_PATH);
            int fsRet = FS_MakeFileName(hnd, FS_LONGNAME_ATTR, buf, FS_MAX_PATH * sizeof(WCHAR));
            if(FS_NO_ERROR != fsRet)
            {
                MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_WALLPAPER_FILE_GET_FILE_PATH_FAIL_TO_GET_LFN);
                fsRet = FS_MakeFileName(hnd, 0, buf, FS_MAX_PATH * sizeof(WCHAR));
            }
            wstr.unlockBuf();
            FS_Close(hnd);
            hnd = NULL;
            if(FS_NO_ERROR == fsRet)
            {
                VfxWString fullPath = getRootFolder();
                fullPath += wstr;
                wstr = fullPath;
            }
            else
            {
                wstr.setEmpty();
            }
        }
    }while(0);
#endif
    return wstr;
}

/*****************************************************************************
 * File-based (mwp, lwp) wallpaper factory
 *****************************************************************************/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

VAPP_WALLPAPER_FACTORY_IMPLEMENT_CLASS(VappWallpaperFileFactory);

VappWallpaperFileFactory::VappWallpaperFileFactory():
    m_wallpaperArrayChecked(VFX_FALSE)
{
    // Do nothing.
}

void VappWallpaperFileFactory::onInit()
{
    VfxObject::onInit();
    m_wallpaperArrayChecked = VFX_FALSE;
    m_wallpaperArray.init(this);
}

void VappWallpaperFileFactory::onDeinit()
{
    m_wallpaperArray.deinit();
    m_wallpaperArrayChecked = VFX_FALSE;
#ifdef __USE_SEPARATE_MEM__
    VfxU8 *wallpaperPool = m_arrayContext->getBuf();
    VFX_OBJ_CLOSE(m_arrayContext);
    applib_asm_free_r(findRootAppGroupId(this), wallpaperPool);
#endif
    VfxObject::onDeinit();
}

VappWallpaperFactorySrcEnum VappWallpaperFileFactory::getSource() const
{
    return VAPP_WALLPAPER_FACTORY_FILE;
}

VfxBool VappWallpaperFileFactory::isSupportLWP() const
{
    return VFX_TRUE;
}

void VappWallpaperFileFactory::initWallpaperArrayIfNeeded()
{
    if(!m_wallpaperArrayChecked)
    {
        validateAndRemoveWallpaper();
        m_wallpaperArrayChecked = VFX_TRUE;
    }
}

void VappWallpaperFileFactory::validateAndRemoveWallpaper()
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_FILE_FACTORY_VALIDATE_AND_REMOVE_WALLPAPER);
    // cear the array
    m_wallpaperArray.clear();    
    m_wallpaperArray.reserve(MAX_FILE_WALLPAPER_COUNT / 10);

    // Collect Built-in Live Wallpaper
    VappWallpaperId wallpaperId;
    
    // Use List Open for long-file name path and hint
    FS_HANDLE list = NULL;
    fs_list_param_struct param = {0};
    const VfxWString dirPath = WallpaperFile::getRootFolder();
    VfxWString searchPath = WallpaperFile::getRootFolder();
    FS_Pattern_Struct patterns[3] = {0};
    const VfxS32 patternLen = sizeof(patterns[0].Pattern) / sizeof(patterns[0].Pattern[0]);

    // Config file search filter
    if(patternLen)
    {
        param.name_pattern_count = 0;    
        searchPath += VFX_WSTR("*.*");

        // Always support RAW IVLW
        mmi_wcsncpy(patterns[param.name_pattern_count].Pattern, (WCHAR*)L"*.rwp", patternLen);
        param.name_pattern_count++;

        #if !(defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__))
        // Cosmos slim does not support AB2 IVLW
        mmi_wcsncpy(patterns[param.name_pattern_count].Pattern, (WCHAR*)L"*.mwp", patternLen);
        param.name_pattern_count++;
        #endif
            
        if(isSupportLWP())
        {
            mmi_wcsncpy(patterns[param.name_pattern_count].Pattern, (WCHAR*)L"*.lwp", patternLen);
            param.name_pattern_count++;
        }
        
        param.name_pattern = patterns;
    }
    
    const VfxS32 batchSize = 5;
    param.path = (kal_wchar *)searchPath.getBuf();
    param.index = 0;
    param.buff_size = FS_LIST_SIZE(batchSize);
    VFX_ALLOC_MEM(param.buff, param.buff_size, this);
    FS_DOSDirEntry e = {0};
    WCHAR fileName[FS_MAX_FILE_NAME_LENGTH] = {0};
    const VfxU32 startingIndex = m_wallpaperArray.size();
    for(kal_int32 result = FS_ListOpen(&param, &list); 
        result >= 0 && list > 0 && (m_wallpaperArray.size() - startingIndex) < MAX_FILE_WALLPAPER_COUNT; 
        #ifdef __MTK_TARGET__
        FS_ListReload(&param, &list)
        #endif
        )
    {
        for(VfxS32 i = 0; i < batchSize; ++i)
        {
            result = FS_ListNext(list, &e, param.path, (WCHAR*)fileName, FS_MAX_FILE_NAME_LENGTH, i);
            if(result >= FS_NO_ERROR)
            {
                #ifdef WIN32
                WallpaperFile fileInfo;
                mmi_wcsncpy(fileInfo.filePath, (WCHAR*)dirPath.getBuf(), FS_MAX_PATH);
                mmi_wcsncat(fileInfo.filePath, fileName, FS_MAX_PATH);

                VfxChar *asciiPath = NULL;
                VFX_SYS_ALLOC_MEM(asciiPath, FS_MAX_PATH * sizeof(VfxChar));
                mmi_wcs_to_asc(asciiPath, fileInfo.filePath);
                wallpaperId.assignWith(VAPP_WALLPAPER_FACTORY_FILE, asciiPath);
                VFX_SYS_FREE_MEM(asciiPath);
                #else
                wallpaperId.assignWith(VAPP_WALLPAPER_FACTORY_FILE, e.Cluster, e.Index);
                #endif
                m_wallpaperArray.pushBack(wallpaperId);
            }
            if(m_wallpaperArray.size() - startingIndex >= MAX_FILE_WALLPAPER_COUNT)
            {
                break;
            }
        }
        if(result < 0)
        {
            break;
        }

        #ifndef __MTK_TARGET__
        // MoDIS can only search once.
        break;
        #endif
    }
    FS_ListClose(list);
    list = NULL;
    VFX_FREE_MEM(param.buff);
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_FILE_FACTORY_VALIDATE_AND_REMOVE_WALLPAPER_RETURN);
}

VfxS32 VappWallpaperFileFactory::getTotalNum()
{
    initWallpaperArrayIfNeeded();
    return m_wallpaperArray.size();
}

VfxBool VappWallpaperFileFactory::getId(
    VappWallpaperId &wallpaperId,   
    VfxS32 index)
{
    initWallpaperArrayIfNeeded();
    wallpaperId = m_wallpaperArray[index];
    return VFX_TRUE;
}

VfxS32 VappWallpaperFileFactory::getAllId(
    VappWallpaperId **idArray,
    VfxS32 size)
{
    // Make sure the caller's buffer is available and large enough.
    const VfxS32 totalNum = getTotalNum();
    VFX_ASSERT(idArray && size >= totalNum);

    // Copy ID to the buffer.
    for (VfxS32 i = 0; i < totalNum; ++i)
    {
        const VappWallpaperId &id = m_wallpaperArray[i];
        idArray[i]->assignWith(id);
    }
    return totalNum;
}

VappWallpaper *VappWallpaperFileFactory::createWallpaper(
    const VappWallpaperId &id,
    VfxObject *parentObj)
{
    
    WallpaperFile f;
    WallpaperFile::fromWallpaperId(id, f);
    const VfxWString path = f.getFilePath();
    if(!path.isEmpty())
    {
        VfxBool asyncSupport = VFX_FALSE;
#if defined(__FS_ASYNC_SUPPORT__) && !(defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__))
        asyncSupport = VFX_TRUE;
#endif
        if(!asyncSupport || !wallpaperDecGetTypeFromFileName((WCHAR*)path.getBuf()))
        {
            // no Async read support or
            // LWP case, use frame video
            VappWallpaperFrameVideo *wallpaper = NULL;
            VFX_OBJ_CREATE(wallpaper, VappWallpaperFrameVideo, parentObj);
            wallpaper->setSourceFile((WCHAR*)path.getBuf());
            return wallpaper;
        }
        else
        {
            // MWP/ABM case, use async (interactive) video
            VappWallpaperInteractiveVideo *wallpaper = NULL;
            VFX_OBJ_CREATE(wallpaper, VappWallpaperInteractiveVideo, parentObj);
            wallpaper->setSourceFile((WCHAR*)path.getBuf());
            return wallpaper;
        }
    }
    return NULL;
}

#endif /* defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__) */
