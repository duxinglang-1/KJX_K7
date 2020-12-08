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
 *  vapp_gallery_file_operation.cpp
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

#ifdef __MMI_GALLERY_SLIM__

#include "vapp_gallery_slim.h"
#include "vapp_gallery_slim_file_operation.h"
#include "vapp_gallery_slim_util.h"
#include "GlobalResDef.h"
#include "vapp_phb_gprot.h"

extern "C"
{
#include "MMI_media_app_trc.h"
#include "mmi_rp_vapp_gallery_def.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrType.h"

#include "vcui_phb_gprot.h"
#include "vapp_uc_gprot.h"

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#include "RightsMgrGProt.h"
#include "Drm_errcode.h"
#endif

#ifdef __MMI_EMAIL__
#include "emailappgprot.h"
#endif

#include "vcui_sns_gprot.h"
}

#ifdef __MMI_OPP_SUPPORT__
#include "vapp_bt_send_gprot.h"
#endif

#define MAX_FILE_PROGRESS (1.0f)

///////////////////// Use these after W11.05
#define __USE_UC_CUI__
#define __USE_WALLPAPER_SET_CUI__
/////////////////////

#ifdef __USE_WALLPAPER_SET_CUI__
#include "vcui_wallpaper_setting_gprot.h"
#endif

/*****************************************************************************
 * VappGalleryFileUtil implementation
 *****************************************************************************/
VfxBool VappGalleryFileUtil::isFileExist(const VfxWChar *filePath)
{
    FS_HANDLE handle;
    handle = FS_Open(filePath, FS_READ_ONLY);
    if(handle > 0)
    {
        FS_Close(handle);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

/*****************************************************************************
 * VappGalleryFileJobContext implementation
 *****************************************************************************/
void VappGalleryFileJobContext::reset()
{
    m_jobId = 0;
    m_abortJob = VFX_FALSE;
    m_unitPerFile = MAX_FILE_PROGRESS;
}

VfxBool VappGalleryFileJobContext::isValidJob()const
{
    return (m_jobId > 0);
}

VfxBool VappGalleryFileJobContext::isAborting()const
{
    return m_abortJob;
}

/*****************************************************************************
 * VappGalleryFileOperationBase implementation
 *****************************************************************************/
VappGalleryFileOperationBase::VappGalleryFileOperationBase():
    m_parentPage(NULL)
{
}

void VappGalleryFileOperationBase::configParentPage(VfxPage *page)
{
    m_parentPage = page;
}

VfxS32 VappGalleryFileOperationBase::getMaxBlueToothShareLimit()
{
#ifdef __MMI_OPP_SUPPORT__
    return VAPP_BTSENDING_MAX_OBJ;
#else
    return 0;
#endif
}

VappGalleryFileOperationBase::WordingHint VappGalleryFileOperationBase::getWordingFromFile(const VfxWString &filePath)
{
    filetypes_group_type_enum fsGroup = srv_fmgr_types_find_group_by_filename_str((const WCHAR*)filePath);
    switch(fsGroup)
    {
    case FMGR_GROUP_IMAGE:
        return WORDING_PICTURE;
    case FMGR_GROUP_VIDEO:
        return WORDING_VIDEO;
    default:
        return WORDING_FILE;
    }
}

void VappGalleryFileOperationBase::showDRMErrorPopup(VfxBool isSingle)
{
    VfxResId errStr = STR_ID_VAPP_GALLERY_SHARE_DRM_ERROR_SINGLE;
    if(!isSingle)
    {
        errStr = STR_ID_VAPP_GALLERY_SHARE_DRM_ERROR_MULTI;
    }
    mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_FAILURE,
        (WCHAR *)VFX_WSTR_RES(errStr).getBuf());
}

/*****************************************************************************
 * VappGalleryMultiFileOperationUI implementation
 *****************************************************************************/
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
VappGalleryMultiFileOperationUI::VappGalleryMultiFileOperationUI():
    m_usePhotoWording(VFX_FALSE)
	,m_fileSequence(NULL)
	,m_mediaList(NULL)
	,m_progress(NULL)
    ,m_confirmDelete(NULL)
    ,m_confirmShareOverLimit(NULL)
{
    m_jobContext.reset();
}

void VappGalleryMultiFileOperationUI::onDeinit()
{
    if(m_jobContext.isValidJob())
    {
        // force cancel and do not send any more message.
        srv_fmgr_async_abort(m_jobContext.m_jobId, MMI_TRUE);
        m_jobContext.reset();
    }

    VFX_OBJ_CLOSE(m_progress);
    VFX_OBJ_CLOSE(m_confirmDelete);
    VFX_OBJ_CLOSE(m_confirmShareOverLimit);

    VappGalleryFileOperationBase::onDeinit();
}

void VappGalleryMultiFileOperationUI::configFileSequence(IVappGalleryFileOperationSequence *sequence)
{
    m_fileSequence = sequence;
}

// VFX_TRUE if want wording to use "photo" instead of "picture"
void VappGalleryMultiFileOperationUI::configPhotoWording(VfxBool usePhoto)
{
    m_usePhotoWording = usePhoto;
}

void VappGalleryMultiFileOperationUI::configMediaList(IVappGalleryMediaList *mediaList)
{
    m_mediaList = mediaList;
}

static void appendCountText(VfxWString &s, VfxU32 count)
{
    VfxWString countTxt;
    countTxt.format("%d", count);
    s += VFX_WSTR_RES(STR_ID_VAPP_GALLERY_PARENTHESIS_LEFT);
    s += countTxt;
    s += VFX_WSTR_RES(STR_ID_VAPP_GALLERY_PARENTHESIS_RIGHT);
}

void VappGalleryMultiFileOperationUI::showDeleteUI()
{
    // we need both parent VfxPage and file sequence to work.
    if(NULL == m_parentPage || NULL == m_fileSequence)
    {
        return;
    }

    // check if the file seq is empty.
    m_fileSequence->start();
    if(!m_fileSequence->hasNextPath())
    {
        return;
    }

    VFX_OBJ_CREATE(m_confirmDelete, VcpConfirmPopup, m_parentPage);
    m_confirmDelete->setInfoType(VCP_POPUP_TYPE_WARNING);
    VfxWString questionTxt = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_DELETE_PREFIX);

    VfxU32 imageCount = 0;
    VfxU32 videoCount = 0;
    m_fileSequence->getCountByType(imageCount, videoCount);
    VfxWString countTxt;

    #ifdef __VAPP_GALLERY_ENABLE_ALWAYS_SHOW_DELETE_COUNT__
    const VfxS32 checkCount = 0;
    #else
    const VfxS32 checkCount = 1;
    #endif

    if(imageCount && videoCount)
    {
        questionTxt += VFX_WSTR_RES(STR_ID_VAPP_GALLERY_DELETE_FILE_SUFFIX);
        appendCountText(questionTxt, imageCount + videoCount);
    }
    else if(imageCount)
    {
        if(m_usePhotoWording)
        {
            questionTxt += VFX_WSTR_RES(imageCount <= checkCount ?
                                    STR_ID_VAPP_GALLERY_IDX_PHOTO_COUNT_SUFFIX_SINGLE :
                                    STR_ID_VAPP_GALLERY_IDX_PHOTO_COUNT_SUFFIX);
        }
        else
        {
            questionTxt += VFX_WSTR_RES(imageCount <= checkCount ?
                                    STR_ID_VAPP_GALLERY_IDX_IMAGE_COUNT_SUFFIX_SINGLE :
                                    STR_ID_VAPP_GALLERY_IDX_IMAGE_COUNT_SUFFIX);
        }

        if(imageCount > checkCount)
        {
            appendCountText(questionTxt, imageCount);
        }
    }
    else if(videoCount)
    {
        questionTxt += VFX_WSTR_RES(videoCount <= checkCount ?
                                    STR_ID_VAPP_GALLERY_IDX_VIDEO_COUNT_SUFFIX_SINGLE :
                                    STR_ID_VAPP_GALLERY_IDX_VIDEO_COUNT_SUFFIX);
        if(videoCount > checkCount)
        {
            appendCountText(questionTxt, videoCount);
        }
    }
    questionTxt += VFX_WSTR_RES(STR_ID_VAPP_GALLERY_QUESTION_MARK);

    m_confirmDelete->setText(questionTxt);

    m_confirmDelete->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_confirmDelete->setCustomButton(
                        VFX_WSTR_RES(STR_GLOBAL_DELETE),
                        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
                        VCP_POPUP_BUTTON_TYPE_WARNING,
                        VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_confirmDelete->m_signalButtonClicked.connect(this, &VappGalleryMultiFileOperationUI::onDeleteConfirm);
    m_confirmDelete->setAutoDestory(VFX_FALSE);
    m_confirmDelete->show(VFX_TRUE);
}

void VappGalleryMultiFileOperationUI::showShareUI(WordingHint wording)
{
    // we need both parent VfxPage and file sequence to work.
    if(NULL == m_parentPage || NULL == m_fileSequence)
    {
        return;
    }

    // check if the file seq is empty.
    m_fileSequence->start();
    if(!m_fileSequence->hasNextPath())
    {
        return;
    }

    // MAUI_02738290: enter BT share directly, since there is only 1 option in W11.12MP
    startBlueToothShareOperation(VFX_TRUE);
}

void VappGalleryMultiFileOperationUI::onDeleteConfirm(VfxObject *sender, VfxId id)
{
    if(m_confirmDelete.get() == sender)
    {
        VFX_OBJ_CLOSE(m_confirmDelete);
    }
    if(VCP_CONFIRM_POPUP_BUTTON_USER_2 == id ||
       VCP_CONFIRM_POPUP_BUTTON_CANCEL == id)
    {
        // cancel, note: popup is auto-close
        finishDeleteOperation(VGFOR_CANCELLED);
    }
    else if(VCP_CONFIRM_POPUP_BUTTON_USER_1 == id)
    {
        m_jobContext.reset();

        // ok, start file operation with progress indicator
        VfxU32 fileCount = m_fileSequence->getTotalCount();
        m_jobContext.m_unitPerFile = MAX_FILE_PROGRESS / fileCount;

        // setup indicator
        VFX_OBJ_CLOSE(m_progress);
        VFX_OBJ_CREATE(m_progress, VcpIndicatorPopup, m_parentPage);
        m_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
        m_progress->setText(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_DELETING));
        m_progress->m_signalCanceled.connect(this, &VappGalleryMultiFileOperationUI::onCancelFileOperation);
        m_progress->setMaxProgress(MAX_FILE_PROGRESS);
        m_progress->setProgress(0.0f);
        m_progress->setAutoDestory(VFX_FALSE);

        // launch delete operation, starting from first file.
        m_fileSequence->getNextPath(m_deletingPath);
        startDeleteOperation(m_deletingPath);

    }
    else
    {
        VFX_DEV_ASSERT(VFX_FALSE);  // should not reach here
    }
}

void VappGalleryMultiFileOperationUI::onOverLimitShareConfirm(VfxObject* sender, VfxId id)
{
    VFX_OBJ_CLOSE(m_confirmShareOverLimit);

    if(VCP_CONFIRM_POPUP_BUTTON_USER_2 == id ||
       VCP_CONFIRM_POPUP_BUTTON_CANCEL == id)
    {
        m_signalOperationDone.emit(this, VGFOR_CANCELLED);
        return;
    }
    else if(VCP_CONFIRM_POPUP_BUTTON_USER_1 == id)
    {
        startBlueToothShareOperation(VFX_FALSE);
    }
}

void VappGalleryMultiFileOperationUI::startBlueToothShareOperation(VfxBool showLimitCheck)
{
#ifdef __MMI_OPP_SUPPORT__
    if(NULL == m_fileSequence)
    {
        return;
    }

    m_fileSequence->start();
    // construct path name array to BT service
    if(showLimitCheck &&
       (VfxS32)m_fileSequence->getTotalCount() > (VfxS32)getMaxBlueToothShareLimit())
    {
        // exceed limit, ask for user confirm.
        VFX_OBJ_CREATE(m_confirmShareOverLimit, VcpConfirmPopup, m_parentPage);
        m_confirmShareOverLimit->setInfoType(VCP_POPUP_TYPE_WARNING);
        m_confirmShareOverLimit->setText(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_MORE_THAN_BT_LIMIT_CONTINUE));
        m_confirmShareOverLimit->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        m_confirmShareOverLimit->setCustomButton(
                            VFX_WSTR_RES(STR_GLOBAL_SHARE),
                            VFX_WSTR_RES(STR_GLOBAL_CANCEL),
                            VCP_POPUP_BUTTON_TYPE_NORMAL,
                            VCP_POPUP_BUTTON_TYPE_CANCEL);
        m_confirmShareOverLimit->m_signalButtonClicked.connect(this, &VappGalleryMultiFileOperationUI::onOverLimitShareConfirm);
        m_confirmShareOverLimit->setAutoDestory(VFX_FALSE);
        m_confirmShareOverLimit->show(VFX_TRUE);
        return;
    }

    const VfxU32 pathCount = vfxMin((VfxU32)getMaxBlueToothShareLimit(), (VfxU32)m_fileSequence->getTotalCount());
    const VfxU32 pathArrayBufSize = pathCount * SRV_FMGR_PATH_BUFFER_SIZE;
    WCHAR *pathArrayBuf = NULL;
    WCHAR **pathPtrArray = NULL;

    // buffer for path arrays
    VFX_ALLOC_MEM(pathArrayBuf, pathArrayBufSize, this);
    VFX_ASSERT(pathArrayBuf);
    memset(pathArrayBuf, 0, pathArrayBufSize);

    // pointer array to path arrays.
    // They simply points into each path in pathArrayBuf.
    // this is for BT service protocol
    const VfxU32 pathPtrArraySize = pathCount * sizeof(WCHAR*);
    VFX_ALLOC_MEM(pathPtrArray, pathPtrArraySize, this);
    VFX_ASSERT(pathPtrArray);
    // setup the pointers
    memset(pathPtrArray, 0, pathPtrArraySize);
    for(VfxU32 i = 0; i < pathCount; ++i)
    {
        pathPtrArray[i] = (WCHAR*)(((U8*)pathArrayBuf) + SRV_FMGR_PATH_BUFFER_SIZE * i);
    }


    // copy and fill the pathArrayBuf
    VfxU32 filledPathCount = 0;
    for(VfxU32 i = 0; i < pathCount; ++i)
    {
        VfxWString nextPath;
        m_fileSequence->getNextPath(nextPath);

#ifdef __DRM_SUPPORT__
        // Check DRM permission
        VfxS32 fs_ret = mmi_rmgr_check_forward((WCHAR*)(const WCHAR*)nextPath);
        if (fs_ret >= 0 && (!(fs_ret & MMI_RMGR_USAGE_SEND)))
        {
            continue;
        }
#endif

        // Put into array
        mmi_wcsncpy(pathPtrArray[filledPathCount], (const WCHAR*)nextPath, SRV_FMGR_PATH_MAX_LEN);
        ++filledPathCount;
    }

    if(filledPathCount < pathCount)
    {
        showDRMErrorPopup(VFX_FALSE);
    }

    VfxWeakPtr<VappGalleryMultiFileOperationUI> self(this);

    if(filledPathCount > 0)
    {
        // call BT CUI
        vapp_bt_send_app_info app_info;
        memset(&app_info, 0, sizeof(app_info));
        app_info.group_id = m_parentPage->getApp()->getGroupId();
        vapp_bt_send_obj(
                &app_info,
                VAPP_BT_SEND_NONE,
                filledPathCount,
                pathPtrArray);
    }

    // release allocated buffers
    VFX_FREE_MEM(pathPtrArray);
    pathPtrArray = NULL;
    VFX_FREE_MEM(pathArrayBuf);
    pathArrayBuf = NULL;

    // note: vapp_bt_send_obj causes screen exit.
    // it's possible that parent release this object.
    if(self.isValid())
    {
        m_signalOperationDone.emit(self.get(), VGFOR_DONE);
    }
#endif
}

void VappGalleryMultiFileOperationUI::startDeleteOperation(const VfxWString &filePath)
{
    // start file manager service async delete file
    S32 job_id = srv_fmgr_async_delete(
                                (const WCHAR*)filePath,
                                SRV_FMGR_ASYNC_FLAG_PRIORITY_FG | SRV_FMGR_ASYNC_FLAG_NO_PROGRESS,
                                &fileOperationFinishProc,
                                this);


    if(job_id > 0)
    {
        // job succesfully created, show inicator
        m_jobContext.m_jobId = job_id;
        m_progress->show(VFX_TRUE);
    }
    else
    {
        // job cannot start, finish with error.
        finishDeleteOperation(VGFOR_ERROR);
    }
}

void VappGalleryMultiFileOperationUI::finishDeleteOperation(VappGalleryFileOpResult res)
{
    VFX_OBJ_CLOSE(m_progress);
    m_signalOperationDone.emit(this, res);
}

void VappGalleryMultiFileOperationUI::onCancelFileOperation(VfxObject* sender, VfxFloat curr_progress)
{
    if(!m_jobContext.isValidJob())
    {
        // no job running, directly close and emit result
        finishDeleteOperation(VGFOR_ABORTED);
    }
    else
    {
        // job running, raise cancel flag and wait for proc to finish.
        m_jobContext.m_abortJob = VFX_TRUE;
        srv_fmgr_async_abort(m_jobContext.m_jobId, MMI_FALSE);
    }
    return;
}

mmi_ret VappGalleryMultiFileOperationUI::onProc(mmi_event_struct *param)
{
    VfxWString deletedPath = m_deletingPath;
    m_deletingPath = VFX_WSTR_EMPTY;
    VfxBool isFileDeleteFail = VFX_FALSE;
    switch(param->evt_id)
    {
    case EVT_ID_SRV_FMGR_ASYNC_PROGRESSING:
        // we ignore processing events
        return MMI_RET_OK;
    case EVT_ID_SRV_FMGR_ASYNC_ABORTING:
        // flag aborting job
        m_jobContext.m_abortJob = VFX_TRUE;
        if(m_progress.isValid())
        {
            m_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            m_progress->setText(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_CANCELLING));
            m_progress->setAutoDestory(VFX_FALSE);
        }
        return MMI_RET_OK;
    case EVT_ID_SRV_FMGR_ASYNC_DONE:
        if(sizeof(srv_fmgr_async_abort_event_struct) == param->size)
        {
            srv_fmgr_async_done_event_struct *doneEvent = (srv_fmgr_async_done_event_struct*)param;
            if(0 != doneEvent->result)
            {
                isFileDeleteFail = VFX_TRUE;
            }
        }
        break;
    default:
        return MMI_RET_DONT_CARE;
    }


    if(isFileDeleteFail)
    {
        // if any file fails, terminate the delete operation
        // and report error
        finishDeleteOperation(VGFOR_ERROR);
    }
    else if(m_jobContext.isAborting())
    {
        // user cancel or FS cancel (interrupted)
        finishDeleteOperation(VGFOR_ABORTED);
    }
    else if(!m_fileSequence->hasNextPath())
    {
        // update progress to full
        if(m_progress.isValid())
        {
            m_progress->setProgress(MAX_FILE_PROGRESS);
        }
        // emit finish signal
        finishDeleteOperation(VGFOR_DONE);
    }
    else
    {
        // update progress
        VfxFloat p = m_progress->getProgress();
        p += m_jobContext.m_unitPerFile;
        m_progress->setProgress(p);

        // trigger next file
        m_fileSequence->getNextPath(m_deletingPath);
        startDeleteOperation(m_deletingPath);
    }
    return MMI_RET_OK;
}

mmi_ret VappGalleryMultiFileOperationUI::fileOperationFinishProc(mmi_event_struct *param)
{
    VappGalleryMultiFileOperationUI* self = reinterpret_cast<VappGalleryMultiFileOperationUI*>(param->user_data);
    if(!self->isValid())
    {
        return MMI_RET_OK;
    }
    return self->onProc(param);
}
#endif
/*****************************************************************************
 * VappGallerySingleFileOperationUI implementation
 *****************************************************************************/
VappGallerySingleFileOperationUI::VappGallerySingleFileOperationUI():
    m_usePhotoWording(VFX_FALSE)
	,m_mediaList(NULL)
	,m_waitPopup(NULL)
    ,m_confirmDelete(NULL)
    ,m_shareOptions(NULL)
    ,m_setAsOptions(NULL)
    ,m_jobId(NULL)
    ,m_appId(NULL)
    ,m_cuiId(NULL)
    ,m_cuiCloseFunc(NULL)
{

}

void VappGallerySingleFileOperationUI::onInit()
{
    VappGalleryFileOperationBase::onInit();
    m_appId = findRootAppId(this);
    m_usePhotoWording = VFX_FALSE;
    return;
}

void VappGallerySingleFileOperationUI::delay_close_cui_func(void *pfnCloseFunc, void *cuiIdValue, void *dontCare)
{
    PFN_CUI_CLOSE closeFunc = reinterpret_cast<PFN_CUI_CLOSE>(pfnCloseFunc);
    if(closeFunc)
    {
        const U16 cuiId = (U16)(U32)cuiIdValue;
        closeFunc((mmi_id)cuiId);
    }
}

void VappGallerySingleFileOperationUI::onDeinit()
{
    if(m_jobId > 0)
    {
        // don't send cancel event since we're destroyed anyway
        srv_fmgr_async_abort(m_jobId, MMI_TRUE);
        m_jobId = 0;
    }

    VFX_OBJ_CLOSE(m_waitPopup);
    VFX_OBJ_CLOSE(m_confirmDelete);
    VFX_OBJ_CLOSE(m_shareOptions);
    VFX_OBJ_CLOSE(m_setAsOptions);

    // close CUIs
    if(m_cuiId && m_cuiCloseFunc)
    {
        mmi_frm_group_set_caller_proc(m_cuiId, NULL, NULL);

        // since we're destroying this object,
        // we cannot use this object to post-invoke.
        // use APP instead.
        VfxApp::postInvoke(&delay_close_cui_func,
                           *((void**)((void*)(&m_cuiCloseFunc))),
                           reinterpret_cast<void*>(m_cuiId),
                           NULL);
    }
    m_cuiCloseFunc = NULL;
    m_cuiId = NULL;

    VappGalleryFileOperationBase::onDeinit();
}

void VappGallerySingleFileOperationUI::configFilePath(const VfxWString &filePath)
{
    m_filePath = filePath;
}

void VappGallerySingleFileOperationUI::configPhotoWording(VfxBool usePhoto)
{
    m_usePhotoWording = usePhoto;
}

void VappGallerySingleFileOperationUI::configMediaList(IVappGalleryMediaList *mediaList)
{
    m_mediaList = mediaList;
}

void VappGallerySingleFileOperationUI::showDeleteUI()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_SHOW_DELETE_UI);

    VFX_OBJ_CREATE(m_confirmDelete, VcpConfirmPopup, m_parentPage);
    m_confirmDelete->setInfoType(VCP_POPUP_TYPE_WARNING);

    VfxId questionStrId = STR_ID_VAPP_GALLERY_DELETE_SINGLE_PIC;
    WordingHint wording = getWordingFromFile(m_filePath);
    switch(wording)
    {
    case WORDING_PICTURE:
        questionStrId = m_usePhotoWording ? STR_ID_VAPP_GALLERY_DELETE_SINGLE_PHT : STR_ID_VAPP_GALLERY_DELETE_SINGLE_PIC;
        break;
    case WORDING_VIDEO:
        questionStrId = STR_ID_VAPP_GALLERY_DELETE_SINGLE_VID;
        break;
    case WORDING_FILE:
    default:
        questionStrId = STR_ID_VAPP_GALLERY_DELETE_SINGLE_FILE;
        break;
    }

    VfxWString questionText = VFX_WSTR_RES(questionStrId);

    m_confirmDelete->setText(questionText);
    m_confirmDelete->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_confirmDelete->setCustomButton(
                        VFX_WSTR_RES(STR_GLOBAL_DELETE),
                        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
                        VCP_POPUP_BUTTON_TYPE_WARNING,
                        VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_confirmDelete->m_signalButtonClicked.connect(this, &VappGallerySingleFileOperationUI::onDeleteConfirm);
    m_confirmDelete->setAutoDestory(VFX_FALSE);
    m_confirmDelete->show(VFX_TRUE);
}

void VappGallerySingleFileOperationUI::onDeleteConfirm(VfxObject* sender, VfxId id)
{
    if(m_confirmDelete.get() == sender)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_ON_DELETE_CONFIRM, 1);
        VFX_OBJ_CLOSE(m_confirmDelete);
    }

    if(VCP_CONFIRM_POPUP_BUTTON_USER_2 == id ||
       VCP_CONFIRM_POPUP_BUTTON_CANCEL == id)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_ON_DELETE_CONFIRM, 2);
        // cancel, note: popup is auto-close
        m_signalOperationDone.emit(this, VGFOR_CANCELLED);
    }
    else if(VCP_CONFIRM_POPUP_BUTTON_USER_1 == id)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_ON_DELETE_CONFIRM, 3);
        // ok, start file operation with progress indicator
        if(NULL == m_waitPopup.get())
        {
            VFX_OBJ_CREATE(m_waitPopup, VcpIndicatorPopup, m_parentPage);
            const VfxSize pageSize = m_parentPage->getSize();
            m_waitPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            m_waitPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_DELETING));
            m_waitPopup->setAutoDestory(VFX_FALSE);
        }
        // launch delete operation, starting from first file.
        startDeleteOperation(m_filePath);
    }
}

void VappGallerySingleFileOperationUI::startDeleteOperation(const VfxWString &filePath)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_START_DELETE_OPERATION, 1, VAPP_GALLERY_INTERNAL_UNUSED_PARAM);
    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();

    // start file manager service async delete file
    S32 job_id = srv_fmgr_async_delete(
                                (const WCHAR*)filePath,
                                SRV_FMGR_ASYNC_FLAG_PRIORITY_FG | SRV_FMGR_ASYNC_FLAG_NO_PROGRESS,
                                &fileOperationFinishProc,
                                this);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_START_DELETE_OPERATION, 2, job_id);
    if(job_id > 0)
    {
        // job succesfully created, show inicator
        m_jobId = job_id;
        m_waitPopup->show(VFX_TRUE);
    }
    else
    {
        // job cannot start, finish with error.
        m_signalOperationDone.emit(this, VGFOR_ERROR);
    }
}

mmi_ret VappGallerySingleFileOperationUI::onFileOperationFinished(mmi_event_struct *param)
{
    if(m_waitPopup.isValid())
    {
        m_waitPopup->hide(VFX_TRUE);
        VFX_OBJ_CLOSE(m_waitPopup);
        m_waitPopup = NULL;
    }

    m_jobId = 0;
	mmi_ret ret = 0;
    switch(param->evt_id)
    {
    // we ignore processing events
    case EVT_ID_SRV_FMGR_ASYNC_PROGRESSING:        
    case EVT_ID_SRV_FMGR_ASYNC_ABORTING:
        break;
    case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {
            // successfully deleted, notify client
            srv_fmgr_async_done_event_struct *doneEvent = (srv_fmgr_async_done_event_struct*)param;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_FILE_OPERATION_FINISHED, param->evt_id,  doneEvent->result);
            m_signalOperationDone.emit(this, doneEvent->result == 0 ? VGFOR_DONE : VGFOR_ERROR);
			ret = doneEvent->result;
        }
    }
	return ret;
}


mmi_ret VappGallerySingleFileOperationUI::fileOperationFinishProc(mmi_event_struct *param)
{
    VappGallerySingleFileOperationUI* pThis = reinterpret_cast<VappGallerySingleFileOperationUI*>(param->user_data);
    if(!pThis->isValid())
    {
        return MMI_RET_OK;
    }
    return pThis->onFileOperationFinished(param);
}

void VappGallerySingleFileOperationUI::showShareUI()
{
    VFX_OBJ_CREATE(m_shareOptions, VcpCommandPopup, m_parentPage);
    VfxWString caption;
    WordingHint wording = getWordingFromFile(m_filePath);

    switch(wording)
    {
    case WORDING_PICTURE:
        caption = VFX_WSTR_RES(
                        m_usePhotoWording ?
                        STR_ID_VAPP_GALLERY_SHARE_PHT_SINGLE :
                        STR_ID_VAPP_GALLERY_SHARE_PIC_SINGLE);
        break;
    case WORDING_VIDEO:
        caption = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SHARE_VID_SINGLE);
        break;
    case WORDING_FILE:
    default:
        caption = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SHARE_FILE_SINGLE);
        break;
    }

    m_shareOptions->setText(caption);
    m_shareOptions->setInfoType(VCP_POPUP_TYPE_QUESTION);
#ifdef __MMI_SNS_PHOTO_UPLOAD__
    if(wording != WORDING_VIDEO)
    {
        // note Gallery dose not support upload videos to SNS in W1212
        m_shareOptions->addItem('SNS', VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SHARE_VIA_SNS));
    }
#endif
#ifdef __MMI_MMS_2__
	VfxBool isShareByMMS = VFX_TRUE;
#if defined(__MMI_MESSAGE_SLIM__)
    if (srv_fmgr_types_find_group_by_filename_str(m_filePath.getBuf()) == FMGR_GROUP_VIDEO)
    {
		isShareByMMS = VFX_FALSE;
	}
#endif // defined(__MMI_MESSAGE_SLIM__)
	if (isShareByMMS)
	{
		m_shareOptions->addItem('WMMS', VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SHARE_VIA_MMS));
    }
#endif
#ifdef __MMI_EMAIL__
    m_shareOptions->addItem('EMAL', VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SHARE_VIA_EMAIL));
#endif
    m_shareOptions->addItem('WBTH', VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SHARE_VIA_BT));
    m_shareOptions->addItem('CANC', VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_shareOptions->m_signalButtonClicked.connect(this, &VappGallerySingleFileOperationUI::onShareConfirm);
    m_shareOptions->setAutoDestory(VFX_FALSE);
    m_shareOptions->show(VFX_TRUE);   // default auto-destroy
}

void VappGallerySingleFileOperationUI::onShareConfirm(VfxObject* sender, VfxId id)
{
    if(sender == m_shareOptions.get())
    {
        VFX_OBJ_CLOSE(m_shareOptions);
    }
    // check if file can be shared
#ifdef __DRM_SUPPORT__
    // Check DRM permission
    S32 ret = mmi_rmgr_check_forward((WCHAR*)(const WCHAR*)m_filePath);
    if (ret >= 0 && (!(ret & MMI_RMGR_USAGE_SEND)))
    {
        showDRMErrorPopup(VFX_TRUE);
        m_signalOperationDone.postEmit(this, VGFOR_ERROR);
        return;
    }
#endif

    switch(id)
    {
    case 'SNS':
        launchSNSUploader(m_filePath);
        return;
    case 'WMMS':
        launchUnifiedComposer(m_filePath);
        return;
    case 'EMAL':
        launchEmail(m_filePath);
        return;
    case 'WBTH':
        doBackgroundBlueToothShare(m_filePath);
        return;
    case 'CANC':
        m_signalOperationDone.emit(this, VGFOR_CANCELLED);
        return;
    default:
        m_signalOperationDone.emit(this, VGFOR_CANCELLED);
        return;
    }
}

void VappGallerySingleFileOperationUI::launchSNSUploader(const VfxWString &filePath)
{
#ifdef __MMI_SNS_PHOTO_UPLOAD__
    // lauch the lite sns uploader, which is not include photo capture utitly
    m_cuiId = vcui_sns_upload_pic_create(m_appId, filePath.getBuf(), VCUI_SNS_SLIM);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_LAUNCH_SNS_UPLOADER, m_cuiId);
    if(GRP_ID_INVALID != m_cuiId)
    {
        mmi_frm_group_set_caller_proc(m_cuiId, &VappGallerySingleFileOperationUI::callerProc, getObjHandle());
        m_cuiCloseFunc = vcui_sns_upload_pic_close;
        vcui_sns_upload_pic_run(m_cuiId);
    }
    else
    {
        m_signalOperationDone.emit(this, VGFOR_ERROR);
    }
#endif
}

void VappGallerySingleFileOperationUI::launchUnifiedComposer(const VfxWString &filePath)
{
#ifdef __MMI_MMS_2__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_LAUNCH_UNIFIED_COMPOSER);

    VappUcEntryStruct data;
    memset(&data, 0, sizeof(VappUcEntryStruct));
    data.app_id = (U8)m_appId;
    data.media_num = 1;
    data.file_path = (VfxU8*)filePath.getBuf();
    data.info_type = SRV_UC_INFO_TYPE_MMS;

#ifdef  __LOW_COST_SUPPORT_COMMON__
    // query if UC app is available to launch (ex: UC app is not available in mass storage scenario)
    // if not, we should not shrink Gallery memory to heap size
    BOOL preCheck = vappUcAppLauncherPreCheck(&data, TRUE);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_LAUNCH_UC_PRE_CHECK, preCheck);
    if(!preCheck)
    {
        m_signalOperationDone.emit(this, VGFOR_DONE);
        return;
    }

    // notify page to release resource
    // note App has to release FG before call mmi_frm_asm_base_shrink_size
    m_signalReleaseResource.emit();
    // shrink bease to heap size
    const mmi_id appId = findRootAppId(this);
    const U32 shrinkSize = mmi_res_get_app_heap_size(appId);
    mmi_frm_asm_base_shrink_size(appId, shrinkSize);
    // launch UC app in SLIM project
    VfxBool result = vappUcAppLauncher(&data) ? VFX_TRUE : VFX_FALSE;
    m_signalOperationDone.emit(this, VGFOR_DONE);
#else
    #ifdef __USE_UC_CUI__
    m_cuiId = vcui_unifiedcomposer_create(m_appId, &data);
    if(m_cuiId != GRP_ID_INVALID)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_CUI_ID_D, m_cuiId);
        mmi_frm_group_set_caller_proc(m_cuiId, &VappGallerySingleFileOperationUI::callerProc, getObjHandle());
        m_cuiCloseFunc = vcui_unifiedcomposer_close;
        vcui_unifiedcomposer_run(m_cuiId);
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_VGFOR_ERROR);
        m_signalOperationDone.emit(this, VGFOR_ERROR);
    }
    #else
    VfxBool result = vappUcAppLauncher(&data) ? VFX_TRUE : VFX_FALSE;
    m_signalOperationDone.emit(this, VGFOR_DONE);
    #endif
#endif /* __LOW_COST_SUPPORT_COMMON__*/
#endif /*__MMI_MMS_2__*/
}

void VappGallerySingleFileOperationUI::launchEmail(const VfxWString &filePath)
{
#ifdef __MMI_EMAIL__
    mmi_email_app_send_attch((const CHAR*)filePath.getBuf());
#endif
    m_signalOperationDone.emit(this, VGFOR_DONE);
}

void VappGallerySingleFileOperationUI::doBackgroundBlueToothShare(const VfxWString &filePath)
{
    VfxWeakPtr<VappGallerySingleFileOperationUI> self(this);
#ifdef __MMI_OPP_SUPPORT__
    vapp_bt_send_app_info app_info;
    memset(&app_info, 0, sizeof(vapp_bt_send_app_info));

    app_info.group_id = m_appId;

    VfxWChar* wArray[1] = {0};
    wArray[0] = (VfxWChar*)filePath.getBuf();

    // this cause screen exit, and may cause "this" destroyed
    vapp_bt_send_obj(
                &app_info,
                VAPP_BT_SEND_NONE,
                1,
                (WCHAR**)wArray);
#endif
    if(self.isValid())
    {
        m_signalOperationDone.postEmit(self.get(), VGFOR_DONE);
    }
}

void VappGallerySingleFileOperationUI::showSetAsUI()
{
    VFX_OBJ_CREATE(m_setAsOptions, VcpCommandPopup, m_parentPage);
    m_setAsOptions->setText(
                    VFX_WSTR_RES(
                            m_usePhotoWording ?
                                STR_ID_VAPP_GALLERY_IMG_SET_PHOTO_AS :
                                STR_ID_VAPP_GALLERY_IMG_SET_PICTURE_AS));
    m_setAsOptions->setInfoType(VCP_POPUP_TYPE_QUESTION);
    // 3 types of wallpapers
    m_setAsOptions->addItem('HOME', VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IMG_AS_HOME_WALLPAPER));
#ifdef __WALLPAPER_SET_USE_MAIN_MENU_WALLPAPER__
    m_setAsOptions->addItem('MAIN', VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IMG_AS_MENU_WALLPAPER));
#endif
    m_setAsOptions->addItem('LOCK', VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IMG_AS_LOCK_WALLPAPER));

    // as contact
    m_setAsOptions->addItem('CONT', VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IMG_AS_CONTACT));
    m_setAsOptions->addItem('CANC', VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_setAsOptions->m_signalButtonClicked.connect(this, &VappGallerySingleFileOperationUI::onSetAsConfirm);
    m_setAsOptions->setAutoDestory(VFX_FALSE);

    // check if file type is supported by "set as CUIs",
    // note "filetypes_file_type_enum = mmi_fmgr_filetype_enum"
    const filetypes_file_type_enum fileType = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_filepath((WCHAR*)m_filePath.getBuf());
    if(MMI_FALSE == vapp_phb_query_head_portrait_type(fileType))
        m_setAsOptions->disableItem('CONT');

    m_setAsOptions->show(VFX_TRUE);   // default auto-destroy
}

void VappGallerySingleFileOperationUI::onSetAsConfirm(VfxObject* sender, VfxId id)
{
    if(sender == m_setAsOptions.get())
    {
        VFX_OBJ_CLOSE(m_setAsOptions);
    }
    switch(id)
    {
    case 'HOME':
    case 'MAIN':
    case 'LOCK':
        setAsWallpaper(id, m_filePath);
        return;
    case 'CONT':
        setAsContactImage(m_filePath);
        return;
    default:
        m_signalOperationDone.emit(this, VGFOR_CANCELLED);
        return;
    }
}

void VappGallerySingleFileOperationUI::setAsWallpaper(VfxId wallpaperType, const VfxWString &filePath)
{
#ifdef __USE_WALLPAPER_SET_CUI__
    cui_wallpaper_setting_create_struct setting;
    memset(&setting, 0, sizeof(setting));
    setting.screen_type = CUI_WALLPAPER_SETTING_HOME_SCREEN;
    setting.filename = const_cast<WCHAR*>(filePath.getBuf());
    setting.user_data = this;
    // get wallpaper type
    switch(wallpaperType)
    {
    case 'HOME':
        setting.screen_type = CUI_WALLPAPER_SETTING_HOME_SCREEN;
        break;
    case 'MAIN':
#ifdef __WALLPAPER_SET_USE_MAIN_MENU_WALLPAPER__
        // setting.screen_type = CUI_WALLPAPER_SETTING_MAIN_MENU;
#endif
        break;
    case 'LOCK':
        setting.screen_type = CUI_WALLPAPER_SETTING_LOCK_SCREEN;
        break;
    }

    m_cuiId = vcui_wallpaper_setting_create(m_appId, &setting);

    if(GRP_ID_INVALID == m_cuiId)
    {
        m_signalOperationDone.emit(this, VGFOR_ERROR);
        return;
    }

    // set CUI caller proc
    mmi_frm_group_set_caller_proc(
                                m_cuiId,
                                &VappGallerySingleFileOperationUI::callerProc, // redirect CUI event to this
                                getObjHandle());
    m_cuiCloseFunc = vcui_wallpaper_setting_close;
    vcui_wallpaper_setting_run(m_cuiId);
#endif
}

void VappGallerySingleFileOperationUI::setAsContactImage(const VfxWString &filePath)
{
    m_cuiId = vcui_phb_contact_saver_create(m_appId);
    if(GRP_ID_INVALID == m_cuiId)
    {
        m_signalOperationDone.emit(this, VGFOR_ERROR);
        return;
    }
    mmi_frm_group_set_caller_proc(
                                m_cuiId,
                                &VappGallerySingleFileOperationUI::callerProc, // redirect CUI event to this
                                getObjHandle());
    vcui_phb_contact_saver_set_type(m_cuiId, VAPP_PHB_SAVE_CONTACT_DEFAULT);
    vcui_phb_contact_saver_set_image(
                                m_cuiId,
                                (WCHAR*)(const WCHAR*)filePath,
                                filePath.getLength(),
                                0                       // we don't use image resource, pass 0.
                                );
    m_cuiCloseFunc = vcui_phb_contact_saver_close;
    vcui_phb_contact_saver_run(m_cuiId);
    return;
}

mmi_ret VappGallerySingleFileOperationUI::onCuiEvent(mmi_event_struct *evt)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_ON_CUI_EVENT);
    switch(evt->evt_id)
    {
    case EVT_ID_CUI_PHB_SAVE_RESULT:
#ifdef __USE_UC_CUI__
#ifdef __MMI_MMS_2__
    case EVT_ID_CUI_UC_SMS_SENT:
    case EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE:
    case EVT_ID_CUI_UC_EMAILCOMPOSER_CLOSE:
#endif
#endif
#ifdef __USE_WALLPAPER_SET_CUI__
    case EVT_ID_CUI_WALLPAPER_SETTING_DONE:
    case EVT_ID_CUI_WALLPAPER_SETTING_ERROR:
    case EVT_ID_CUI_WALLPAPER_SETTING_CANCEL:
#endif
#ifdef __MMI_SNS_PHOTO_UPLOAD__
    case EVT_ID_VCUI_SNS_RESULT:
#endif
        // result of share is not important to us, so we simply close CUI
        VFX_ASSERT(m_cuiId);
        VFX_ASSERT(m_cuiCloseFunc);
        m_cuiCloseFunc(m_cuiId);
        m_cuiId = NULL;
        m_cuiCloseFunc = NULL;
        // always DONE since we don't care saver result
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_ON_CUI_EVENT_VGFOR_DONE);
        m_signalOperationDone.emit(this, VGFOR_DONE);
        return MMI_RET_OK;
    default:
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FILE_OP_ON_CUI_EVENT_UNKNOWN_EVENT);
        return MMI_RET_OK;
    }
}

mmi_ret VappGallerySingleFileOperationUI::callerProc(mmi_event_struct *evt)
{
    VappGallerySingleFileOperationUI *pThis = (VappGallerySingleFileOperationUI*)handleToObject((VfxObjHandle)(evt->user_data));
    if(NULL == pThis)
    {
        return MMI_RET_OK;
    }
    return pThis->onCuiEvent(evt);
}

#endif
