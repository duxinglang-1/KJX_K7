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
 *  vcui_wallpaper_setting.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCUI_WALLPAPER_SETTING_H__
#define __VCUI_WALLPAPER_SETTING_H__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcui_wallpaper_setting_gprot.h"
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
#include "vapp_setting_wallpaper_type_def_gprot.h"
#include "vapp_video_player_cp.h"
#include "mdi_video.h"
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappWallpaperSettingCui
 *****************************************************************************/
class VappWallpaperSettingCui : public VfxCui
{
    VFX_DECLARE_CLASS(VappWallpaperSettingCui);
    // Override
    protected:
    virtual void onRun(void* args, VfxU32 argSize);

#if defined(__MMI_COSMOS_IMAGECLIPPER__) && !defined(__LOW_COST_SUPPORT_COMMON__)
    virtual mmi_ret onProc(mmi_event_struct *evt);
#endif // defined(__MMI_COSMOS_IMAGECLIPPER__) && !defined(__LOW_COST_SUPPORT_COMMON__)

    virtual void onDeinit();
        
    public:
    void setImage(const WCHAR *filename) {m_filename = VFX_WSTR_MEM(filename);};

    // Internal use
    public:
    VappWallpaperSettingCui() : m_imgClipperId(0), m_userData(NULL), m_isSetProcessing(VFX_FALSE) {m_filename = VFX_WSTR_EMPTY; };

    void clearTempFile();
    protected:

    void initFolder();
    void directlySet(VfxWString filename); // Set the file to wallpaper directly
    void showErrorConfirmPopup(VfxResId stringId);
    void postEvent(cui_wallpaper_setting_event_enum event, cui_wallpaper_setting_error_enum error);
    void onSettingFinished(VfxU8 error);

#if !defined(__MMI_COSMOS_IMAGECLIPPER__) && defined(__LOW_COST_SUPPORT_COMMON__)
    private:
    static void onConfirmPopup(VfxId id, void *userData);
#endif
    protected:
    cui_wallpaper_setting_screen_type_enum m_screenType;
    VfxWString m_filename;
    VfxWString m_tempFilename;
    mmi_id     m_imgClipperId;
    void      *m_userData;
    cui_wallpaper_setting_error_enum m_errorCode;
    VfxBool    m_isSetProcessing;
};

/***************************************************************************** 
 * Class VappVideoWallpaperSettingCui
 *****************************************************************************/
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
class VappGalleryVideoPreviewPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappGalleryVideoPreviewPage);
    //typedef enum
    //{
    //    BOOTUP_VIDEO_MAX_DURATION = 20000,      // The max duration of boouup video is 20s
    //    SHUTDOWN_VIDEO_MAX_DURATION = 20000    // The max duration of shutdown video is 20s
    //}enumPwrOnOffVideoDuration;

public:
    VappGalleryVideoPreviewPage();
    VappGalleryVideoPreviewPage(cui_wallpaper_setting_create_struct* rcvData);

protected:
    // override toolbar options & handlers
    virtual void onInit();
	virtual void onDeinit();
	virtual void onEnter(VfxBool isBackward);
	virtual void onEntered();
	virtual void onExit(VfxBool isBackward);
    virtual void onExited2();


    void createWallpaperFrameFromInfo();
	void onVideoOpened(VappVideoPlayerComponent *sender, MDI_RESULT result);
    void onVideoFinished(VappVideoPlayerComponent *sender, MDI_RESULT result);	
    void onToolbarClicked(VfxObject* sender, VfxId btnId);
	//void onPwrHintClick(VfxObject* sender, VfxId id);
    void onSettingFinished(void);	
	static mmi_ret devPlugOutHdlr(mmi_event_struct *evt);
	static mmi_ret onEvent(mmi_event_struct *param);
	
private:
	void createToolbar();
	void setOKayStatus(VfxBool status);
	void setToolBarUnHittable(VfxBool hittable);
	void playVideo(VappVideoPlayerComponent *player, MDI_RESULT openStatus);
    void postEvent(cui_wallpaper_setting_event_enum event, cui_wallpaper_setting_error_enum error);
    void setVideoFileName(VfxWString filename);
    
    cui_wallpaper_setting_create_struct* m_rcvData;
    VappWallpaperType m_wallpaperType;
    VfxWString m_fileName;
    VappVideoPlayerComponent *m_activeLiveWallpaper;        // may be live wallpaper or video frame
    VfxBool	m_isSeted;
	VfxBool m_isEntered;
	VfxBool m_isVideoOpened;
	MDI_RESULT m_openStatus;
};


class VappGalleryVideoPreviewScr : public VfxMainScr
{
public:
	VappGalleryVideoPreviewScr():m_rcvData(NULL)
		{}
    VappGalleryVideoPreviewScr(cui_wallpaper_setting_create_struct* rcvData)
        : m_rcvData(rcvData)
        {}

// Override
protected:
    virtual void on1stReady()
    {
        VfxMainScr::on1stReady();
        //setBgColor(VFX_COLOR_BLACK);
        VappGalleryVideoPreviewPage* prewPage;
        VFX_OBJ_CREATE_EX(prewPage, VappGalleryVideoPreviewPage, this, (m_rcvData));
        pushPage(0, prewPage);    
    }
    private:
    cui_wallpaper_setting_create_struct* m_rcvData;
};

class VappVideoWallpaperSettingCui : public VfxCui
{
    VFX_DECLARE_CLASS(VappVideoWallpaperSettingCui);
    // Override
    protected:
    // virtual void onInit();
    virtual void onRun(void* args, VfxU32 argSize);
    // Internal use
    public:
    VappVideoWallpaperSettingCui() : m_rcvData(NULL), m_prewScr(NULL)
    {}

    protected:
    cui_wallpaper_setting_create_struct* m_rcvData;
    VappGalleryVideoPreviewScr* m_prewScr;
};


#endif //__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
#endif /* __VCUI_WALLPAPER_SETTING_H__ */
