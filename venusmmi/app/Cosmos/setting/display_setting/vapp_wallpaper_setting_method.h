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
 *  vapp_setting_wallpaper_setting.h
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
 *
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SETTING_WALLPAPER_SETTING_H__
#define __VAPP_SETTING_WALLPAPER_SETTING_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_wallpaper_setting_method_gprot.h"
extern "C"
{
#include "FileMgrSrvGprot.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_USER_DEFINED_FILE_SIZE (1024 * 1024 / VAPP_WALLPAPER_TYPE_END)
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappWpSettingStrategyBase : public VfxObject
{
    // Overrides
    public:
    VappWpSettingStrategyBase() : m_next(NULL) {};
    
    // get the live wallpaper setting if it is not live wallpaper return 0
    virtual void getWallpaperId(VappWpResType type, VfxU16 *id) 
    {
        // perform operation
        if (m_next)
    	{
    	    m_next->getWallpaperId(type, id);
    	}
    };

    // Set wallpaper ID according to type and resource type
    virtual void setWallpaperId(VappWpResType type, VfxU16 wallpaperId, VappWpSetErrorCode *error) 
    {
        // perform operation
        if (m_next)
    	{
    	    m_next->setWallpaperId(type, wallpaperId, error);
    	}
    };

    // Get resource type of input type wallpaper setting
    virtual void getWallpaperResType(VappWpResType *type) 
    {
        // perform operation
        if (m_next)
    	{
    	    m_next->getWallpaperResType(type);
    	}
    };

    // Get resource type of input type wallpaper setting
    virtual void setWallpaperResType(VappWpResType type, const VfxWString& filename = VFX_WSTR_EMPTY)
    {
        // perform operation
        if (m_next)
    	{
    	    m_next->setWallpaperResType(type, filename);
    	}
    };

    // Get wallpaper file path and file name
    virtual void getWallpaperFile(VappWpResType type, VfxWString *file) 
    {
        // perform operation
        if (m_next)
    	{
    	    m_next->getWallpaperFile(type, file);
    	}
    };
    
    // Set wallpaper file according to type, it will cache the file to system drive
    virtual void setWallpaperFile(VappWpResType type, const VfxWString &fileName, VappWpSetErrorCode *error) 
    {
        // perform operation
        if (m_next)
    	{
    	    m_next->setWallpaperFile(type, fileName, error);
    	}
    };
    
  
    
    // Check wallpaper availability, if it is not available to use, restore the wallpaper
    virtual void checkWallpaper(VappWpResType type, VappWpSetErrorCode *error) 
    {
        // perform operation
        if (m_next)
    	{
    	    m_next->checkWallpaper(type, error);
    	}
    };
    
    // Restore wallpaper to the default one
    virtual void restoreWallpaper() 
    {
        // perform operation
        if (m_next)
    	{
    	    m_next->restoreWallpaper();
    	}
    };

    

    virtual void addNext(VappWpSettingStrategyBase *obj) 
	{
		m_next = obj;
		if (obj)
		{
			obj->m_next = NULL;
		}
	};

    virtual void setNvramData(VfxU16 cacheId) {m_nvramCacheId = cacheId;};

    virtual void initSetting() {};
    // variables
    public:
    VfxSignal2 <VappWpSetErrorCode, const VfxWString&> m_signalSettingFinished;
    VappWpSettingStrategyBase *m_next;
    protected:
    VfxU16 m_nvramCacheId;
};

/***************************************************************************** 
 * VappWpSettingWallpaperTypeSetting
 *****************************************************************************/
class VappWpSettingWallpaperTypeSetting : public VappWpSettingStrategyBase
{
    // Overrides
    public:
    
    // Get resource type of input type wallpaper setting
    virtual void getWallpaperResType(VappWpResType *type);

    // Set resource type of input type wallpaper setting
    virtual void setWallpaperResType(VappWpResType type, const VfxWString& filename = VFX_WSTR_EMPTY);

    virtual void initSetting();

    virtual void restoreWallpaper();
    // Variables
    protected:
    VfxU8 m_wallpaperResType;
};



//--------1108--------------------------------------------------------------
/***************************************************************************** 
 * VappWpSettingVideoWallpaperSetting
 *****************************************************************************/
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
class VappWpSettingVideoWallpaperSetting : public VappWpSettingStrategyBase
{
    // Overrides
    public:
    // get static wallpaper setting
    
    virtual void getWallpaperId(VappWpResType type, VfxU16 *id);
    
    // Set wallpaper ID according to type and resource type
    virtual void setWallpaperId(VappWpResType resType, VfxU16 wallpaperId, VappWpSetErrorCode *error);

    virtual void initSetting();
    void restoreWallpaper();

    // Varialbes
    protected:
    VfxU8 m_videoWallpaperId;
};
#endif

/***************************************************************************** 
 * VappWpSettingFileDirectSetting
 *****************************************************************************/
class VappWpSettingFileDirectSetting : public VappWpSettingStrategyBase
{
protected:
    // Typedef
    typedef struct
    {
        WCHAR userFile[SRV_FMGR_PATH_MAX_LEN + 1];
        CHAR cacheFile[WALLPAPER_CACHE_FILENAME_MAX_LENGTH];
    } VappWpSettingUserFileStruct;
    
    // Overrides
    public:

    // Set wallpaper ID according to type and resource type
    virtual void setWallpaperId(VappWpResType resType, VfxU16 wallpaperId, VappWpSetErrorCode *error);

    // Get wallpaper file path and file name
    virtual void getWallpaperFile(VappWpResType type, VfxWString *file);

    // Set wallpaper file according to type, it will cache the file to system drive
    virtual void setWallpaperFile(VappWpResType type, const VfxWString &fileName, VappWpSetErrorCode *error);
    
    // Check wallpaper availability, if it is not available to use, restore the wallpaper
    virtual void checkWallpaper(VappWpResType type, VappWpSetErrorCode *error);

    virtual void initSetting();

    virtual void setNvramData(VfxU16 recordId, VfxU16 fileId);

public:
    // Constructor & destructor
    VappWpSettingFileDirectSetting();
    virtual ~VappWpSettingFileDirectSetting();
    
    // Used for user file setting
    virtual void setSettingChain(VappWpSettingStrategyBase *header) {m_settingChain = header;}
    virtual void setSettingType (VappWallpaperType type) {m_wpType = type;}

    #ifdef __MMI_USB_SUPPORT__
        static mmi_ret usbMassStorageModeHdlr(mmi_event_struct *evt);
        void enterMassStorageMode();
        void exitMassStorageMode();
    #endif /* __MMI_USB_SUPPORT__ */
    
    #ifdef __DRM_SUPPORT__    
        static VfxBool isDRMVaild(const VfxWChar *fileName);
    #endif  
protected:
    VfxBool checkFileFormat(VfxWString fileName, VfxS32 *formatArray);

    VfxBool isFileExist(const VfxWString &fileName);

    VappWpSetErrorCode checkWallpaperInt();

    virtual const VfxWString& getFileName() const
    {   return m_userFileName;  }

protected:
    VfxU16 m_nvramRecordId;
    VfxU16 m_nvramFileId;
    VfxWString m_userFileName;    
    VfxBool m_resetByUsb;
    VappWpSettingStrategyBase *m_settingChain;
    VappWallpaperType m_wpType;
    VappWpSettingUserFileStruct m_fileData;

};


#if !defined(__LOW_COST_SUPPORT_COMMON__)
/***************************************************************************** 
 * VappWpSettingUserWallpaperSetting
 *****************************************************************************/
class VappWpSettingUserWallpaperSetting : public VappWpSettingFileDirectSetting
{
// Overrides
public:
    void setWallpaperCacheFile(VappWallpaperType type, const VfxWString &fileName, VappWpSetErrorCode *error);

    // Get wallpaper file path and file name
    virtual void getWallpaperFile(VappWpResType type, VfxWString *file);
         
    // Restore wallpaper to the default one
    virtual void restoreWallpaper();

    virtual void initSetting();

    void setDefaultFilename(VfxWString filename) {m_defaultFileName = filename;};
    
    static VappWpSetErrorCode initFolder();
    
    VappWpSetErrorCode cacheFile(const VfxWString fileName);


    // Method
    // Internal used
    public:
    VappWpSettingUserWallpaperSetting();
    ~VappWpSettingUserWallpaperSetting();
  
    
    protected: 

    // Check if driver space is available for caching 
    VappWpSetErrorCode checkFolder(VfxWString fileName);
  
    VfxBool deleteOldFile();

    VfxWString getDefaultFile(VfxU8 index, VfxWString postfix);

     mmi_ret onCacheFinish(mmi_event_struct *evt);

    //VfxBool deleteFile(const VfxWString &fileName);

    static mmi_ret cacheFinishedProc(mmi_event_struct *evt);

    virtual const VfxWString& getFileName() const
    {   return m_cacheFileName;  }


    // Variable
    protected:
    VfxWString m_cacheFileName; // File which is cached to system drive\Settings
    VfxWString m_defaultFileName;

    private:
    VappWallpaperType m_cacheType;
        
};
#endif // defined(__LOW_COST_SUPPORT_COMMON__)
#endif /* __VAPP_SETTING_WALLPAPER_SETTING_H__ */
 
