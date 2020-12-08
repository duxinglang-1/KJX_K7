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
 *  vapp_movie_theater.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Movie Theater APP
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

#ifndef __VAPP_MOVIE_THEATER_H__
#define __VAPP_MOVIE_THEATER_H__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_movie_theater_gprot.h"
#include "vapp_gallery_gprot.h"

extern "C"
{
#include "FileMgrSrvGProt.h"
#include "MotSrvGProt.h"
}

extern "C"
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_B__) 
#include "dcmgr.h" // DCM
#endif
}

/*****************************************************************************
 * Global Variable & Define
 *****************************************************************************/
//#define VAPP_GALLERY_URL_MAX_BUF_LENGTH 521      // This comes from MEDPLY_URL_MAX_LENGTH

/*****************************************************************************
 * Class forward declaration
 *****************************************************************************/
class SimpleBitSet;
class VappMovieTheaterContentProvider;

/*****************************************************************************
 * Class
 *****************************************************************************/
class VappMovieTheater : public VfxApp
{
    VFX_DECLARE_CLASS(VappMovieTheater);

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);

    virtual mmi_ret handleDevicePlugOut(srv_fmgr_notification_dev_plug_event_struct* evt);

public:
    static mmi_ret onUSBEnterMS(mmi_event_struct *param);
    static mmi_ret onDevicePlugIn(mmi_event_struct *param);
    static mmi_ret onDevicePlugOut(mmi_event_struct *param);

public:
    static VfxBool isMatchingStorage(const srv_fmgr_notification_dev_plug_event_struct &evt, U8 drv);

protected:
    U8 queryActiveDrive();

private:
    mmi_ret onProcPreLockRouting();

private:
    VappMovieTheaterContentProvider *m_provider;
};

class VappMovieTheaterScreen : public VfxMainScr
{
    //VFX_DECLARE_CLASS(VappMovieTheaterScreen);

public:
    VappMovieTheaterScreen();

// Override
protected:
    // override to display proper page
    virtual void on1stReady();

    // override to enter/exit screen
    //virtual void onEnter(VfxBool isBackward);
    //virtual void onExit(VfxBool isBackward);

    // override to check last-page exit
    virtual VfxBool onPageBack(VfxPage* page);

// Method
public:
    // set SSE disabled option
    // It sould be set before entry Gallery screen
    //void setIsSSEDisabled(const VfxBool disabled);

    void setProvider(VappMovieTheaterContentProvider *provider);

    // this signal is emitted when the last page is being popped.
    // this allows Vapp/Vcui to know that it maybe going to terminate.
    VfxSignal0 m_signalLastPagePopped;
private:
    VfxPage *m_firstPage;
    //VfxBool m_isSSEDisabled;

    VappMovieTheaterContentProvider *m_provider;
};

// Base class of Gallery CUI pages.
// These pages may assign custom title bar caption,
// and may show an default string when content is empty.
class VappMovieTheaterPage : public VfxPage
{
    //VFX_DECLARE_CLASS(VappMovieTheaterPage);
public:
    VappMovieTheaterPage();
    virtual void onInit();
// Method
public:
    // change the custom message in page center
    void setPageMessage(const VfxWString &message);

    // if isShow is VFX_TRUE, show message in page center.
    void showPageMessage(VfxBool isShow, VfxBool whiteText = VFX_FALSE);

    // show waiting icon
    void showPageWaitIcon(VfxBool isShow);

    void setProvider(VappMovieTheaterContentProvider *provider);

    static void onVideoPlayerExitProc(vapp_gallery_last_play_struct* param, void* userData);
    void launchVideoPlayer(VfxWString &path, VfxU64 time);

// overridable
public:
    // if VFX_FALSE is returned, means no "current storage" defined for this page.
    virtual VfxBool getPageCurrentStorage(U8 &drvLetter);

public:
    srv_mot_cat_enum m_currCatId;   // current selected category id
    VfxU32 m_currMediaId;   // current selected media id

// Common operations for pages
protected:


protected:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        PAGE_MESSAGE_FONT_SIZE = 20,
#elif defined(__MMI_MAINLCD_480X800__)
        PAGE_MESSAGE_FONT_SIZE = 30,
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        PAGE_MESSAGE_FONT_SIZE = 16,
#else
        PAGE_MESSAGE_FONT_SIZE = 16,
#endif
    };
protected:
    VfxWString m_pageMessage;
    VfxTextFrame *m_messageFrame;    // lazy-initialized text, used to display note like "No Photos" in page center.
    VcpActivityIndicator *m_waitIcon;  // lazy-init wait icon
    VappMovieTheaterContentProvider *m_provider;
    static srv_mot_ret_enum m_plUpdateRet;
    MMI_ID m_appId;
};


class VappMovieTheaterStorageSetting
{
public:
    VappMovieTheaterStorageSetting();

    ~VappMovieTheaterStorageSetting();

    // get default storage, if correntInvalidStorage is VFX_TRUE(default),
    // then Phone storage is returned when current default storage is not available.
    srv_fmgr_drv_type_enum getDefaultStorage(VfxBool correntInvalidStorage = VFX_TRUE);
    // set default storage
    void setDefaultStorage(srv_fmgr_drv_type_enum drvType);

protected:
    void readFromNVRAM();
    void flushToNVRAM();

private:
    VfxBool m_dirty;
    srv_fmgr_drv_type_enum m_defaultDriveType;
};

typedef struct VappMovieTheaterThumbCacheStruct
{
    VfxBool isUsed;
    VfxU32 mediaId;
    VfxU32 thumbnail_size;                             /* thumbnail size */
    VfxU8 *thumbnail_buf;       /* PNG bitstream */
} VappMovieTheaterThumbCacheStruct;

class VappMovieTheaterContentProvider : public VfxObject
{
    VFX_DECLARE_CLASS(VappMovieTheaterContentProvider);

public:
    VappMovieTheaterContentProvider();
    virtual void onInit();
    virtual void onDeinit();

public:
    srv_mot_ret_enum open(srv_fmgr_drv_type_enum type);
    void close();
    srv_mot_ret_enum update();
    void stopUpdating();
    void refreshCategoryList(srv_mot_cat_enum category);
    void getCategoryString(srv_mot_cat_enum category, VfxWString &text);
    void getCategoryString(VfxU32 mediaId, VfxWString &text);
    void getCategoryCount(srv_mot_cat_enum category, VfxU32 *number);
    void getMediaName(VfxU32 mediaId, VfxWString &str);
    void getMediaPath(VfxU32 mediaId, VfxWString &str);
    void getMediaDuration(VfxU32 mediaId, U64 &duration);
    void getMediaDuration(VfxU32 mediaId, VfxWString &str);
    void getMediaDurationStr(VfxU32 mediaId, VfxWString &str);
    void getMediaLastPlayTime(VfxU32 mediaId, U64 &time);
    void getMediaLastPlayTimeStr(VfxU32 mediaId, VfxWString &str);
    void getMediaThumb(VfxU32 mediaId, U8 *buf, U32 &bufSize);
    void getMediaThumb(VfxU32 mediaId, U8 **buf, U32 &bufSize);
    void freeMediaThumb(VfxU32 mediaId);
    void getMediaTitle(VfxU32 mediaId, VfxWString &str);
    void getMediaYear(VfxU32 mediaId, VfxWString &str);
    void getMediaStarring(VfxU32 mediaId, VfxWString &str);
    void getMediaPlot(VfxU32 mediaId, VfxWString &str);
    void getMediaId(const VfxU32 index, U32 &mediaId);
    srv_mot_ret_enum addLastPlayMedia(VfxU32 mediaId, U64 playTime);
    void getErrorString(srv_mot_ret_enum error, VfxWString &text);
    VfxBool isDBReady();
    srv_mot_ret_enum memorySpaceCheck();
    void createMediaCache();
    void destroyMediaCache();
    void setCBReceiver(VfxObject* receiver);

public:
    VfxSignal3 <srv_mot_cb_evt_enum, srv_mot_ret_enum, VfxU32> m_signalMOTCallback;

private:
    static VfxS32 MOTCallback(void* user_data, srv_mot_cb_evt_enum cb_event, srv_mot_ret_enum result, U32 param);

    // format miliseconds into "HH:MM:SS" format.
    // if hideHourIfZero is VFX_TRUE, then "MM:SS" is used when the time is less than 1 hour.
    void formatTimeText(VfxWString &timeText, U64 timeMsec, VfxBool hideHourIfZero = VFX_TRUE);

    VfxBool isInCache(VfxU32 mediaId, VfxU32 &cacheIdx);
    void getFromCache(VfxU32 cacheIdx, U8 **buf, U32 &bufSize);
    void setCacheUnused(VfxU32 mediaId);
    VappMovieTheaterThumbCacheStruct* getEmptyCache();
    void clearCache();


private:
    enum PROVIDER_STATE
    {
        PROVIDER_STATE_INITED,
        PROVIDER_STATE_OPENED,
        PROVIDER_STATE_UPDATING,
    };

    MMI_ID m_appId;
    srv_mot_h m_srvMot;
    VfxObject *m_cbReceiver;
    PROVIDER_STATE m_state;
    VfxU32* m_mediaId;
    VfxU32 m_currMediaId;
    srv_mot_content_info_struct* m_mediaInfo;
    VappMovieTheaterThumbCacheStruct m_tCache[VAPP_MOVIE_THEATER_CACHE_SIZE];
    VfxU32 m_lastCacheIdx;

};

#endif /* __VAPP_MOVIE_THEATER_H__ */

