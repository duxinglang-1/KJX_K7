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
 *  vapp_fmgr.h
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
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_FMGR_PROT_H__
#define __VAPP_FMGR_PROT_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_textView.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tabctrl_page.h"
#include "vcp_popup.h"
#include "vcp_form.h"
#include "vcp_menu_popup.h"

#include "vapp_fmgr_table.h"
#include "vapp_fmgr_cui_gprot.h"
#include "vapp_fmgr_cp.h"

#include "app_str.h"
#include "vfx_app.h"
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "FileMgrSrvGProt.h"
    #include "FileMgrSrvIProt.h"
    #include "MMI_include.h"
    #include "mmi_rp_file_type_def.h"
#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/
 
#define VAPP_FMGR_TRACE0(tr, f)              MMI_TRACE(TRACE_GROUP_1, tr)
#define VAPP_FMGR_TRACE1(tr, f, a1)          MMI_TRACE(TRACE_GROUP_1, tr, a1)
#define VAPP_FMGR_TRACE2(tr, f, a1, a2)      MMI_TRACE(TRACE_GROUP_1, tr, a1, a2)
#define VAPP_FMGR_TRACE3(tr, f, a1, a2, a3)  MMI_TRACE(TRACE_GROUP_1, tr, a1, a2, a3)
 
#if defined(__COSMOS_NO_USER_DRIVE__)
#define __VAPP_FMGR_NO_PUBLIC_DRIVE__
#endif
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/

/* Aidan test file manager begin */
/* VENUS_MMI_FMGR_INSTANCE_MAX_NUM should be one FMGR App and the value of VCUI_FMGR range(refer to vapp_package_res.h) */
#define VENUS_MMI_FMGR_INSTANCE_MAX_NUM 11
#define VENUS_FMGRI_INDEX_NOT_CHANGE     -1
#define VENUS_FMGRI_INDEX_TO_FIRST_POS   -2
#define VENUS_FMGRI_INDEX_ERROR_CODE   -3

#define VAPP_FMGR_PATH_ROOT               VFX_WSTR("root")
#define VAPP_FMGR_FILE_PATH_LEN (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH
/* include \0 */
#define VENUS_FMGR_FILENAME_BUF_LEN (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH
/* reserve for \0 */
#define VENUS_FMGR_FILENAME_BUF_LEN_RESERVED SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH

#define VENUS_FMGR_FILEEXT_BUF_LEN (SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1) *ENCODING_LENGTH
#define VENUS_FMGR_FILEEXT_BUF_LEN_RESERVED SRV_FMGR_PATH_MAX_FILE_EXT_LEN *ENCODING_LENGTH

typedef enum
{
    VAPP_FMGR_ERROR_OK = 0,  

    /* FS   error if < 0 */

    /* FMGR error if < FS_MINIMUM_ERROR_CODE */
    VAPP_FMGR_ERROR_START = FS_MINIMUM_ERROR_CODE,

    VAPP_FMGR_ERROR_LOADING,         /* Folder loading(Sort) still processing, can not display file list */
    VAPP_FMGR_ERROR_INDEX_INVALID,   /* Folder has been changed (file list is dirty), re-loading is required */
    VAPP_FMGR_ERROR_NO_SLOT,         /* No more slot to create file list */
    VAPP_FMGR_ERROR_INVALID_PARAM,   /* Invalid parameter */

    VAPP_FMGR_ERROR_MAX
    
} vapp_fmgr_error_enum;


typedef enum
{
    VENUS_FMGRI_DIRTY_CHANGE_INDEX            = 0x01,
    VENUS_FMGRI_DIRTY_RESET_TO_FIRST_INDEX    = 0x02,    /* reset index to zero or first non-hyperlink item */

    FMGRI_DIRTY_ALL = 0xFF
} vapp_fmgri_dirty_enum;

typedef enum
{  
    VAPP_FMGR_IFLAG_HIDE_LOADING_PATH            = 0x01000000,
        
#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__
    VAPP_FMGR_IFLAG_CUSTOM_ROOT                  = 0x02000000,
#endif

    VAPP_FMGR_IFLAG_WAIT_POPUP                   = 0x04000000,

    VAPP_FMGR_IFLAG_INTERNAL                     = 0x08000000,   /* without notify creation */

    VAPP_FMGR_IFLAG_DEAD                         = 0x10000000,
    
    VAPP_FMGR_IFLAG_ENUM = 0x7F000000
} vapp_fmgr_flag_internal_enum;

typedef enum
{
    /* FMGR internal error if < MMI_FMGR_ERROR_MAX */
    VAPP_FMGRI_ERROR_START = VAPP_FMGR_ERROR_MAX + 100,
    VAPP_FMGR_ERROR_EMPTY,
    VAPP_FMGR_ERROR_PATH_TOO_DEEP,
    VAPP_FMGR_ERROR_DEVICE_BUSY,
#ifdef __USB_IN_NORMAL_MODE__
    VAPP_FMGR_ERROR_USB_MODE,
#endif

    VAPP_FMGR_ERROR_BUFFER,

    VAPP_FMGR_ERROR_LOADING_CANCEL,

    VAPP_FMGR_ERROR_REQUIRE_ASYNC_LOADING,

    VAPP_FMGRI_ERROR_FILE_LIST_IS_DIRTY,
        
    VAPP_FMGRI_ERROR_PREPARE_SYSTEM_FOLDER_ERROR,
    VAPP_FMGRI_ERROR_PREPARE_SYSTEM_FOLDER_COMPLETE,
    VAPP_FMGRI_ERROR_STORAGE_REPORT_JOBID_ERROR,
    VAPP_FMGRI_ERROR_STORAGE_REPORT_GO_ON,
    VAPP_FMGRI_ERROR_STORAGE_REPORT_SWITCH,
    VAPP_FMGRI_ERROR_STORAGE_REPORT_COMPLELE,
    VAPP_FMGRI_ERROR_PARAM_ERROR,

    VAPP_FMGRI_ERROR_FOLDER_DETAIL_JOBID_ERROR,
    VAPP_FMGRI_ERROR_FOLDER_DETAIL_GO_ON,
    
    VAPP_FMGRI_ERROR_MAX
    
} vapp_fmgr_internal_error_enum;

typedef VfxCallback0 vapp_fmgr_callback;

typedef enum
{
    VAPP_FMGR_ACTION_NONE = 1,
        
    VAPP_FMGR_ACTION_COPY,       /* Copy */
    VAPP_FMGR_ACTION_MOVE,       /* Move */
    VAPP_FMGR_ACTION_SORT,
    VAPP_FMGR_ACTION_FORMAT,
    VAPP_FMGR_ACTION_MARK_COPY,
    VAPP_FMGR_ACTION_MARK_MOVE,
    VAPP_FMGR_ACTION_MARK_DELETE,    
    VAPP_FMGR_ACTION_MARK_SHARE,
    VAPP_FMGR_ACTION_RENAME_DRIVE,
    VAPP_FMGR_ACTION_CREATE_FOLDER,
    VAPP_FMGR_ACTION_RENAME_FILE,
    VAPP_FMGR_ACTION_RENAME_FOLDER,
    VAPP_FMGR_ACTION_DELETE_SINGLE,
    VAPP_FMGR_ACTION_DELETE_FOLDER,

    VAPP_FMGR_ACTION_SHARE_SINGLE,
    VAPP_FMGR_ACTION_FWD_MMS,
    VAPP_FMGR_ACTION_FWD_EMAIL,
    VAPP_FMGR_ACTION_FWD_BT,
    VAPP_FMGR_ACTION_OTHER,  /* for other app using FMT, ex:Ebook,DLAgent */
    VAPP_FMGR_ACTION_OTHER_DEL_FOLDER,

    VAPP_FMGR_ACTION_TOTAL

} vapp_fmgr_tree_action_enum;
/* Important structure */
/* This struct store all data related to a file or folder */
typedef struct
{
    VfxS8 file_name[VENUS_FMGR_FILENAME_BUF_LEN]; /* name */
    VfxS8 file_ext[VENUS_FMGR_FILEEXT_BUF_LEN]; /* extension */
    filetypes_file_type_enum file_type; /* type */
    VfxU32 file_size; /* size */
    MYTIME time; /* modified date */
    MYTIME created_time; /* create date */
    VfxU16 attribute; /* attribute, refer to FS_ATTR_XXX */
} VAPP_FMGR_FILE_INFO_STRUCT;

typedef struct _vapp_fmgr_drive_info_struct
{
    VfxU16 drv_path[SRV_FMGR_DRV_MAX_NAME_LEN + 1];
    VfxU16 string_id;
    VfxU16 icon_id;
    VfxS16 drv_type;
} vapp_fmgr_drive_info_struct;
/* Important structure */

typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VAPP_FMGR_INSTANCE_EVENT_BEGIN = EVT_ID_VCUI_FOLDER_SELECTOR_TOTAL,
    /* DOM-NOT_FOR_SDK-END */

    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VAPP_FMGR_INSTANCE_EVENT_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} vapp_fmgr_event_enum;
/* Temp test async create folder */

typedef struct {
    VfxS32 exist;
    VfxS32 index;
} vapp_fmgr_system_folder_properity_struct;


class VappFmgrApp : public VfxCui
{
    VFX_DECLARE_CLASS(VappFmgrApp);

public:
    void setInstance(VfxObject* instance);
    VfxObject* getInstance(void) const;
// Override
protected:
    virtual void onInit();
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onGroupInactive();
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);
protected:
    VfxObject *m_instance;
};

class VappFmgrGeneralOperation : public VfxControl
{
    VFX_DECLARE_CLASS(VappFmgrGeneralOperation);   

protected:
    VfxS32 actionDelete(void);
    VfxS32 actionCopy(void);
    VfxS32 actionMove(void);
    VfxS32 actionMultiSelectDelete(void);
    VfxS32 actionFormat(void);
#if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)
    VfxS32 actionSort(void);
#endif //#if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)
    VfxS32 actionShareSingle(void);
    VfxS32 actionCreateFolder(void);
    VfxS32 actionRename(void);
    #ifndef __MMI_SLIM_FILE_MANAGER__
    VfxS32 actionRenameDrive(void);
    #endif //__MMI_SLIM_FILE_MANAGER__
    void onClickButton(VfxObject* obj, VfxId id);
    void onClickInputButton(VfxObject* sender, VcpInputPopupButtonEnum button_id);
    void onClickProcessingCancel(VfxObject* obj, VfxFloat processing);
    void onPopupStateChange(VfxBasePopup* obj,  VfxBasePopupStateEnum state);
    void onClickConfirmButton(VfxObject * sender,VfxId id);
        
    void showConfirm(VfxWString &description);
    void showProcessing(void);
    void updateProgress(void);
    void closeProcessing(void);

    VfxS32 composeFilePath(VfxWString& path, VfxS8* file_name, VfxBool add_slash);
    VfxS32 composeFilePath(VfxS8* buffer, VfxS32 buffer_size, VfxWString& path, VfxS8* file_name, VfxBool add_end_slash);
    VfxS32 checkSrcDstPath(void);

    VfxS32 checkAvailableSpace(void);
public:
    virtual void onInit();
    virtual void onDeinit();  

    void setCallerInstanceId(VfxU8 instance_id);
    void setCallerGroupId(mmi_id group_id);

    VfxBool getOngoing(void) const;
    void resetOngoing(void);
    
    void setCanCancel(VfxBool can);
    VfxBool getCanCancel(void);

    void setAllowPopup(VfxBool allow);
    VfxBool getAllowPopup(void);

    void setAborting(VfxBool aborting);
    VfxBool getAborting(void);
    
    void setAction(VfxU32 action);
    VfxU32 getAction(void) const;

    void setJobId(VfxS32 job_id);
    VfxS32 getJobId(void);

    void setProgressed(VfxS32 progressed);
    VfxS32 getProgressed(void);
    
    void setMaxCount(VfxS32 max_count, VfxBool disp_only = VFX_TRUE);
    VfxS32 getMaxCount(void);
    VfxBool isRemainder(VfxS32 count);
        
    void setSrcPath(VfxWString &src);
    void setSrcPath(VfxS8 *src);
    VfxWString& getSrcPath(void);

    void setFilename(VfxS8 *filename);
    
    void setDstPath(VfxS8 *dst);
    void setDstPath(VfxWString &dst);
    VfxWString& getDstPath(void);

    void setSrcDrv(srv_fmgr_drv_type_enum src_drv);
        
    void setDstDrv(srv_fmgr_drv_type_enum src, VfxBool to_default = VFX_FALSE);
    VfxS32 getDstDrv(void);

    void setSelectedPath(VfxS8* path);
    VfxWString getSelectedPath(void);
    
    void setSrcFileInfo(srv_fmgr_fileinfo_struct* file_info);
    srv_fmgr_fileinfo_struct* getSrcFileInfo(void);

    void setDeleteFilterType(FMGR_FILTER* filter);
    FMGR_FILTER* getDeleteFilterType(void);

    void setFileListHdle(SRV_FMGR_FILELIST_HANDLE filelist_hdl);
    
    VfxS32 run(void);

    /* VfxS32 is error code. 
       error code < 0 : error case.
       error code == 0: no error.
    */
    VfxSignal3 <VfxObject*,VfxS32,VfxBool> m_signalActionRsp;
    
    void showActionResult(VfxS32 str_id, VfxBool succ, VfxS32 error_code, VfxBool pressed_cancel, VfxBool notify_caller = VFX_TRUE);

    VfxBool isShowProcessing(void);
    VfxBool isShowCommandPopup(void);
    void closeProcessing_ex(void);
    void updateProcessing_ex(void);
    
#ifdef __MMI_FMGR_FORMAT_WITH_PHONE_LOCK_CONFIRM__
    void doFormatEx(VfxBool success);
    void closeVerifyCui(void);
#endif
    VfxS32 getErrorCode(void);
    VfxBool getWaitConfirm(void);

    VfxS32 getErrorStrId(VfxS32 error_code);
private:
    void onClickToDelete(void);
    void onClickToFormat(void);
#if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)
    void onClickToSetSort(VfxId id);
#endif // #if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)
    void onClickToCreateFolder(const VfxWString &name);
    void onClickToRename(const VfxWString &name);
    #ifndef __MMI_SLIM_FILE_MANAGER__
    void onClickToRenameDrive(const VfxWString &name);
    #endif //__MMI_SLIM_FILE_MANAGER__
#ifdef __MMI_MMS_2__
    void onClickToShareAsMMS(void);
#endif
    void onClickToShareAsEmail(void);
    void onClickToShareAsBT(void);

private:
    VfxBool changeErrorStr(VfxS32 error_code);
private:
    VfxU8 m_caller_instance_id;
    mmi_id m_caller_group_id;
    mmi_id m_cui_id;
    VfxBool m_can_cancel;
    VfxBool m_allow_popup;  /* Allow to popup or not */
    VfxBool m_async_fs_aborting;
    VfxBool m_ongoing;  /* Check if the notification is caused from myself or not */
    VfxBool m_clicked;
    VfxBool m_waitconfirm;
    VfxS8 *m_filename;
    VfxS8 *m_ext;
    VfxU32 m_action;    
    VfxS32 m_job_id;
    VfxS32 m_progressed;
    VfxS32 m_max_count;     /* for multi-select */
    VfxS32 m_disp_count;    /* for display count on popup */
    VfxWString m_src_path;
    VfxWString m_selected_path;
    VfxWString m_dst_path;
    VcpIndicatorPopup *m_processing;
    VfxS32 m_src_drv;
    VfxS32 m_dst_drv;       /* for move/copy, if there is no dst path,
                               FMGR will move/copy file(s) to correct folder on the drive 
                               according to file type */
    srv_fmgr_fileinfo_struct *m_file_info;
    FMGR_FILTER *m_del_filter;

    SRV_FMGR_FILELIST_HANDLE m_filelist_hdl; /* for set sort type */

    VappFileNameEditorPopup *m_filename_input;
    
    VcpConfirmPopup *m_pop;
    VfxWeakPtr <VcpConfirmPopup> m_confirm;
    VcpCommandPopup *m_opt_menu;
    
    /* for delay signal */
    VfxS32 m_error_code;
    VfxBool m_pressed_cancel;
};

class VappFmgrMultiSelect : public VfxControl
{
    VFX_DECLARE_CLASS(VappFmgrMultiSelect);

    friend class VappFmgrMain;
    
#define VAPP_FMGR_MAX_MARK_ITEM_FOR_INDEX (FS_SORT_MAX_ENTRY)
#define VAPP_FMGR_MAX_MARK_ITEM_FOR_NAME 50

#ifdef __FS_SORT_SUPPORT__
#define VAPP_FMGR_MAX_MARK_ITEM  VAPP_FMGR_MAX_MARK_ITEM_FOR_INDEX
#else
#define VAPP_FMGR_MAX_MARK_ITEM  VAPP_FMGR_MAX_MARK_ITEM_FOR_NAME
#endif

#define VAPP_FMGRI_MSA_PROCESSED  0x01
#define VAPP_FMGRI_MSA_SENDABLE   0x02
#define VAPP_FMGRI_MSA_FOLDER     0x04

public:
    typedef enum
    {
        VAPP_FMGR_MSA_ERROR_NONE            = 0,
        VAPP_FMGR_MSA_ERROR_OVER_MAX        = -1,
        VAPP_FMGR_MSA_ERROR_FILE_NOT_FOUND  = -2,
        VAPP_FMGR_MSA_ERROR_NOT_CALLER      = -3,
        VAPP_FMGR_MSA_ERROR_NO_FSOBJ        = -4,
        VAPP_FMGR_MSA_ERROR_NO_NAMEBUFFER   = -5
    } vapp_fmgr_msa_error_code;
    
protected:
    virtual void onInit(void);
    virtual void onDeinit(void);
    
public:
    void createMSA(VfxS32 total_file_num);
    
    void setSrcPath(VfxWString &path);
    //VfxWString &getSrcPath(void) const;

    void setCount(VfxU16 count);
    VfxU16 getCount(void) const;

    VfxS32 add(VfxObject* obj, VfxWChar* name, VfxU32 size, MYTIME* time, VfxS8 flag);
    VfxS32 remove(VfxObject* obj, VfxWChar* name);
    VfxS32 remove_by_idx(VfxObject* obj, VfxU16 idx);
    
    VfxS16 isMarked(VfxObject* obj, VfxWChar* name);      

    VfxS32 add(VfxObject* obj, VfxS32 index, VfxU8 flag);
    VfxS32 remove(VfxObject* obj, VfxS32 index);
    VfxS32 remove_by_array_idx(VfxObject* obj, VfxS32 idx);
    VfxS16 isMarked(VfxObject* obj, VfxS32 index);

    VfxS32 pop(VfxObject* obj);
    VfxS32 top(VfxObject* obj, VfxS8 *name_buffer, VfxS32 buffer_size, VfxS8 *flag = NULL, VfxBool *isfolder = NULL);
    
    VfxS32 remove_all(VfxObject* obj);

    VfxBool isProtectedFile(VfxWChar* name);
    VfxBool isProtectedFile(VfxWString& file_path);

    void setSendableFlag(VfxS8 *flag, VfxBool remove = VFX_FALSE);
    void setFolderFlag(VfxS8 *flag, VfxBool remove = VFX_FALSE);
    void setProcessedFlag(VfxS8 *flag, VfxBool remove = VFX_FALSE);

    VfxBool isSetSendableFlag(VfxS8 flag);
    VfxBool isSetFolderFlag(VfxS8 flag);
    VfxBool isSetProcessedFlag(VfxS8 flag);
        
    void Selectall(VfxS32 count, VfxS32 start = 0);
    void Unselectall(void);
    void setSelectallFlag(VfxBool select_all = VFX_FALSE);
	VfxBool getSelectAllFlag() const;

    void setAllowToMarkCount(VfxU32 allow_to_mark_count);
    VfxU32 getAllowToMarkCount();
    
    VfxSignal1 <VfxObject*> m_signalCallerChanged;
    
private:
    VfxBool isCallerFmgrInstance();
    VfxU32 convertMYTIME(MYTIME* mytime);

    VfxS32 getFileInfo(VfxObject* obj, VfxS32 index, VAPP_FMGR_FILE_INFO_STRUCT *file_info);

private:
    VfxObject* m_current_caller;
    VfxS8  m_used;
    VfxU16 m_count;
    VfxU16 m_folder_count;
    VfxU16 m_sort_option;
    VfxU32 m_max_mark_item_count;
    VfxU32 m_allow_to_mark_count;
    VfxWString m_path;
    VfxWChar **m_nameArray_ptr;
    VfxWChar *m_nameArray;
    VfxU32 *m_sizeArray;
    VfxU32 *m_timeArray;    
    VfxS8 *m_flagArray;
    VfxS32 *m_indexArray;
    VfxBool m_can_selectall;
    VfxBool m_select_all;
};

class VappFmgrFSData;
class VappFmgrInstance : public VfxControl, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappFmgrInstance);

    friend class VappFmgrFSData;
    friend class VappFmgrGeneralOperation;
    
protected:
    VappFmgrInstance*        Next;
    VappFmgrInstance*        Prev;
    VfxU8                    m_id;      
    VappFmgrFSData*			 m_fsdata; /* for fsdata obj */
    VappFmgrInstance*        m_context;
    VfxU8 m_instance_type; /* Instance type, mmi_fmgri_type_enum */
    //U16 app_id; /* Application id */    
    VfxU16 title_icon_id;
    VfxU16 title_str_id;
    VfxS32 m_cur_index;
    VfxU32 drv_type; /* Display drive type, srv_fmgr_drivelist_type_enum */
    VfxU32 m_display_style;
    /* Instance`s type-specific data */
    VfxU32 cust_data;
    /* User data */
    VfxU32 user_data; /* This is data of user (those who create this instance) */
    VfxU32 m_flag;
    /* Data related */
    VfxWString m_file_path;
    FMGR_FILTER filter_type;
    mmi_id m_gid;
    VappFmgrGeneralOperation *m_action;     /* FMGR general operation */
    VappFmgrMultiSelect      *m_ms;         /* Multi-select */
    VfxWeakPtr <VcpListMenu> m_listmenu;
    VfxWeakPtr <VcpGroupListMenu> m_glist;
    VfxPage *m_page;
    VcpTabCtrlPage *m_tabctrlpage;

    vapp_fmgr_system_folder_properity_struct *m_system_folder_properity;
    VfxS32 m_system_folder_offset[g_def_folder_table_size];

    /* Prepare system folder index */
    VfxS8 m_sf_index;
    VfxS32 m_sf_job_id;
    VfxBool m_sf_cancel;

    /* Disable update list menu or not */
    VfxBool m_disable_update;
    
    /* delay event */
    mmi_group_event_struct* m_delay_event;

    /* For set view when back to fmgr */
    VcpMenuPos m_group_pos;

    VfxWeakPtr <VcpConfirmPopup> m_show_pop;

    VfxU16 m_ms_title_id;
public:
	VfxBool isDisabled(VfxU32 flag, VfxS32 index);
    VfxS32 setFilePath(VfxWChar *path);
    VfxWString getFilePath() const;
    void setTitleIconId(VfxU16 icon_id);
    void setTitleStrId(VfxU16 str_id);
    void setFilter(FMGR_FILTER filter);
    void setFlag(VfxU32 flag);
	void addFlag(VfxU32 flag);
	VfxU32 getFlag() const
	{
		return m_flag;
	};

    void setCustData(VfxU32 c_data);
    void setInstancyType(VfxU8 instance_type);
    void setPageObj(VfxPage *page);
    VfxPage* getPageObj() const
    {
        return m_page;
    };

    void setTabCtrlPageObj(VcpTabCtrlPage *tabctrlpage);    
    void addFmgrInstance(VappFmgrInstance* instance);
    void removeFmgrInstance(VappFmgrInstance* instance);
    VappFmgrInstance* getNextInstance(void);
    VappFmgrInstance* getPrevInstance(void);    
    void setInstanceId(VfxU8 instance_id)
    {
        m_id = instance_id;
    };
    VfxU8 getInstanceId(void) const
    {
        return m_id;
    };

    mmi_id getGroupId() const
    {
        return m_gid;
    };
    VfxBool isInstanceIdValid(VfxU8 instance_id) const;

    VfxS32 asyncLoadFileList(VfxBool checkDirty = VFX_TRUE);

    VfxBool isFilePathRoot(void) const;
    VfxBool isFilePathDrv(void) const;
    VfxS32 composeFilePath(VfxWString& path, VfxS8* file_name, VfxBool add_end_slash);
    VfxS32 composeFilePath(VfxS8* buffer, VfxS32 buffer_size, VfxWString& path, VfxS8* file_name, VfxBool add_end_slash);
    VfxBool isComposeFilePathOverLen(VfxWString& path, VfxS8* file_name, VfxBool add_end_slash);
    
    void createFSDataObj(VfxBool prepare_buffer = VFX_FALSE, VfxS32 app_id = 0);

    void releaseFSDataObj(void);
    VappFmgrFSData* getFSDataObj(void) const;   
    SRV_FMGR_FILELIST_HANDLE getFileListHdle(void);

    VappFmgrGeneralOperation* getOperationObj(void) const;

    void setPrepareSystemFolderIndex(VfxS8 index);
    VfxS8 getPrepareSystemFolderIndex(void) const;

    void setCreateSystemFolderJobCancel(VfxBool cancel)
    {
        m_sf_cancel = cancel;
    };

    VfxBool getCreateSystemFolderJobCancel()
    {
        return m_sf_cancel;
    };
        
    void setCurIndex(VfxS32 cur_index);
    VfxS32 getCurIndex(void) const;
    
    void refreshMenu(VfxS32 search_index = 0, VfxS32 fs_error = 0);
        
    virtual void onClickUpButton(VfxObject* obj, VfxId button_id);
    virtual void onClickCmdButton(VcpListMenu *listmenu, VfxU32 index);
    virtual void onClickGroupCmdButton(VcpGroupListMenu *listmenu, VcpMenuPos pos);
    virtual void onClickToolBarButton(VfxObject* obj, VfxId button_id);
    
    VfxSignal2 <VfxObject*, VfxS32> m_popup_error;

    //void transformSrvFileInfo(VAPP_FMGR_FILE_INFO_STRUCT *file_fino, srv_fmgr_fileinfo_struct *srv_file_info);

    virtual void getTitleStrAndIcn(VfxWString &main_str, VfxU32 title_element, VfxU16 &icn_id);
    void resetOptMenu(VfxU16 opt_menu_id);
    virtual void getOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num);    
    virtual VfxBool isMenuItemDisable(VfxU32 page_id, VfxU16 &opt_menu_id);
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
    virtual void onDrvTabSwitch(VfxObject *obj, VfxId tab_id);    
#endif
    virtual void onActionRsp(VfxObject* obj, VfxS32 error_code = FS_NO_ERROR, VfxBool no_on_confirm = VFX_FALSE);
    
    void setGid(mmi_id gid);
    void setDisplayStyle(VfxU32 display_style);
    VfxU32 GetDisplayStyle(void) const;

    VfxU8 getInstanceType(void)
    {
        return m_instance_type;
    };

    void setDrvType(VfxU32 type)
    {
        drv_type = type;
    };
    
    VfxU32 getDrvType()
    {
        return drv_type;
    };
    
    void getSizeString(VfxWString &text, VfxU64 total_size);
    void getDateTimeString(VfxWString &text, MYTIME* date_time);

    void enterFolder(VfxS8 *name);
    void exitFolder(void);
    void backRoot(void);

    VfxS32 prepareSystemFolders();
    void setCreateSystemFolderJobId(VfxS32 job_id);
    VfxS32 getCreateSystemFolderJobId(void) const;
    void resetSystemFolderProperity(void);
    void setSystemFolderProperityExist(VfxU8 i, VfxS32 exist = -1);
    void setSystemFolderProperityIndex(VfxU8 i, VfxS32 index = -1);    
    VfxS32 getSystemFolderProperityExist(VfxU8 i);
    VfxS32 getSystemFolderProperityIndex(VfxU8 i);
    VfxU16 isSystemFolder(VfxS8 *folder_name, VfxBool name_only = VFX_FALSE);
    void setSystemFolderOffset(VfxU8 i, VfxS32 index);
    VfxS32 getSystemFolderOffset(VfxU8 i) const;
    
    virtual mmi_ret callProc(mmi_event_struct *param);
    void callbackApp(mmi_group_event_struct *evt);
    VfxBool showPopupEx(VfxU16 str_id, VcpPopupTypeEnum popup_type, VcpConfirmPopupButtonSetEnum button_set = VCP_CONFIRM_BUTTON_SET_OK);
    VcpMenuPos getGroupPos(void);
    void resetDisableUpdate(void);
    static VappFmgrInstance*      NextNotify;
    void changeTabName(srv_fmgr_drv_type_enum drv_type);

	void setErrHandle(VfxBool shoudleHandle)	{ m_errHandle = shoudleHandle; }
	VfxBool getErrHandle() const { return m_errHandle;}

public:
    typedef enum
    {
        VAPP_FMGR_TYPE_NONE = 0,
        VAPP_FMGR_TYPE_APP,

        VAPP_FMGR2_TYPE_STORAGE_SELECTOR,
        VAPP_FMGR2_TYPE_FILE_SELECTOR,
        VAPP_FMGR2_TYPE_FOLDER_SELECTOR,
        VAPP_FMGR2_TYPE_FOLDER_BROWSER,
        // For media picker
        VAPP_FMGR2_TYPE_MEDIA_PICKER,
        VAPP_FMGR2_TYPE_FILE_OPTION,
        
#ifdef __DRM_V02__
        VAPP_FMGR_TYPE_VIEW_ARCHIVE,
#endif
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
        VAPP_FMGR_TYPE_SEL_FILE_MUlTI,
#endif

        VAPP_FMGR_TYPE_NUM

    } vapp_fmgri_type_enum;
    
protected:        
    virtual void onInit();
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *param);

    virtual void setMenu(VcpListMenu *);
    virtual void setMenu(VcpGroupListMenu *menu);
    
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    // Free the image resource for the image fields of list cell
    virtual void closeItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc Image               // [IN] the image resource
        );

    // Get the item count of the lis menu
    virtual VfxU32 getCount() const;

    virtual VfxBool getItemText(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    // <group DOM_ListMenu_IVcpGroupListMenuContentProvider_Overridable>
    // Get the text format for the text fields of list cell, if app doesn't provide
    // a special format, list menu will the text as simple string
    virtual VfxBool getItemTextFormat(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VcpRichTextFormat &format          // [OUT] the text resource
        ) {return VFX_FALSE;}

    // <group DOM_ListMenu_IVcpGroupListMenuContentProvider_Overridable>
    // Get the image resource for the image fields of list cell
    virtual VfxBool getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );
    
    // <group DOM_ListMenu_IVcpGroupListMenuContentProvider_Overridable>
    // Free the image resource for the image fields of list cell
    virtual void closeItemImage(
        VcpMenuPos pos,                 // [IN] the position of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc Image               // [IN] the image resource
        ) {}
    
    virtual VfxU32 getCount(VfxU32 group) const;
    
    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

    // Swap two items, user should update its internal data of the two items
    virtual VfxBool swapItem(
        VfxU32 index1, // [IN] index of the first item
        VfxU32 index2  // [IN] index of the second item
        );

    // Get the group count of the group list menu
    virtual VfxU32 getGroupCount() const;

    // <group DOM_ListMenu_IVcpGroupListMenuContentProviderr_Overridable>
    // Get if the specified group header is valid
    virtual VfxBool hasGroupHeader(VfxS32 group) const;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    virtual VfxBool getItemIsDisabled(
        VfxU32 index       // [IN] the index of item
        ) const;

    virtual VfxBool getItemIsDisabled(
        VcpMenuPos pos   // [IN] position of the item
        ) const;
        
    void releaseListMenu(void);

    VfxBool showPopup(VfxU16 str_id, VcpPopupTypeEnum popup_type, VcpConfirmPopupButtonSetEnum button_set = VCP_CONFIRM_BUTTON_SET_OK, VfxU16 button_str1_id = 0, VfxU16 button_str2_id = 0);
    virtual VfxBool error_handler(VfxS32 error_code, VfxS32 line = __LINE__);

    void onViewScrollStart(VcpBaseListMenu *menu);
    void onViewScrollEnd(VcpBaseListMenu *menu);


    #define VAPP_FMGRI_CHECK_PATH_OVER_LENGTH 0x01
    #define VAPP_FMGRI_CHECK_DRM_SEND_PERMISSION 0x02
    #define VAPP_FMGRI_CHECK_IS_FOLDER                       0x04
	
    void getTitleCellSubString(VfxWString &main_str);
    void getTitleCellMainString(VfxWString &main_str, VfxBool isPageRestore);

    void onHandleEventPlugIn(mmi_event_struct *param);
    /* callback */
protected:
    
    void onLoadRspCB(VfxObject *obj, VfxS32 result, VfxS32 search_index);    
    void onLoadProgressCB(VfxObject *obj, VfxS32 total_count, VfxS32 progress_count);
    virtual void onTapListMenuItem(VcpListMenu *sender, VfxU32 index);
    virtual void onTapGroupListMenuItem(VcpGroupListMenu *listmenu, VcpMenuPos pos);
    virtual void onPopupStateChange(VfxBasePopup* obj,  VfxBasePopupStateEnum state);
    virtual void onClickConfirmButton(VfxObject* obj, VfxId id);
    /* static member */
 
public:
    /* for private member */
    static VappFmgrInstance *cui_basic_check(mmi_id cui_id, vapp_fmgri_type_enum type)
    {
        VappFmgrApp *app = (VappFmgrApp*)VfxApp::getObject(cui_id);
        VappFmgrInstance *instance = NULL;
        if (app != NULL)
        {
            instance = (VappFmgrInstance*)app->getInstance();
            if (instance != NULL && instance->m_gid == cui_id && instance->m_instance_type == type)
            {
                return instance;
            }
        }        

        return NULL;
    };
    
    static void    resetVappFmgrInstanceStaticMember(void)
    {
        VappFmgrInstance *instance, *next_instance;

    	instance = Tail;
    	
    	while (instance != NULL)
    	{
    		next_instance = instance->Prev;
    		VFX_OBJ_CLOSE(instance);
    		instance = next_instance;
    	};

    	Head = NULL;
    	Tail = NULL;

    	instance_num = 0;
    };
    void    setSearchFilename(VfxU8 instance_id, VfxS8 *filename)
    {
        setSearchForNewFolder(instance_id, VFX_FALSE);
            
        if (filename != NULL)
        {
            VfxS32 len = app_ucs2_strlen(filename);
            if (filename[(len-1)*ENCODING_LENGTH] == '\\' &&
                filename[(len-1)*ENCODING_LENGTH+1] == 0)
            {
                len--;
            }
            app_ucs2_strncpy((kal_int8*)search_filename, (const kal_int8*)filename, len);
            setSearchInstancId(instance_id);
        }
        else
        {
            search_filename[0] = '\0';
            search_filename[1] = '\0';
        }
    };
    VfxS8*  getSearchFilename(VfxU8 instance_id)
    {
        if (instance_id == getSearchInstanceId())
        {
            return search_filename;
        }
        else
        {
            return NULL;
        }
    };
    void    setSearchInstancId(VfxU8 instance_id)
    {
        search_instance_id = instance_id;
    };
    VfxU8   getSearchInstanceId(void) const
    {
        return search_instance_id;
    };
    void    setSearchForNewFolder(VfxU8 instance_id, VfxBool isForNewFolder)
    {
        search_for_new_folder = isForNewFolder;
        setSearchInstancId(instance_id);
    };
    VfxBool   getSearchForNewFolder(VfxU8 instance_id) const
    {
        if (instance_id == getSearchInstanceId())
        {
            return search_for_new_folder;
        }
        else
        {
            return VFX_FALSE;
        }
    };
    static void    increaseInstanceNum(void)
    {
        instance_num++;
    };
    static void    decreaseInstanceNum(void)
    {
        instance_num--;
    };

    static VfxU8   getInstanceNum(void)
    {
        return instance_num;
    }
    
    static void    setHeadInstancePtr(VappFmgrInstance* instance)
    {
        Head = instance;
    };
    static VappFmgrInstance*    getHeadInstancePtr(void)
    {
        return Head;
    };
    static void    setTailInstancePtr(VappFmgrInstance* instance)
    {
        Tail = instance;
    };
    static VappFmgrInstance*    getTailInstancePtr(void)
    {
        return Tail;
    };
private:
	VfxBool _getItemTextForNormal(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString & text);
private:
    /* Search file index */    
    VfxS8                  search_filename[VENUS_FMGR_FILENAME_BUF_LEN];
    VfxU8                  search_instance_id;
    VfxBool                search_for_new_folder;
	VfxBool				   m_errHandle;

    /* instance list */
    static VfxU8                  instance_num;
    static VappFmgrInstance*      Head;
    static VappFmgrInstance*      Tail;
protected:	
	VfxBool m_isGroupListMenu;
};

//typedef VfxS32 (VfxObject::*vapp_fmgr_load_response_callback)(VfxU8 instance_id, VfxS32 result, VfxS32 search_index);
//typedef VfxS32 (VappFmgrInstance::*vapp_fmgr_load_progress_callback)(VfxU8 instance_id, VfxS32 total_count, VfxS32 progress_count);
typedef VfxCallback3<VfxObject*, VfxS32, VfxS32> vapp_fmgr_load_response_callback;
typedef VfxCallback3<VfxObject*, VfxS32, VfxS32> vapp_fmgr_load_progress_callback;

class VappFmgrFSData : public VfxObject
{
    VFX_DECLARE_CLASS(VappFmgrFSData); 
protected:
    virtual void onInit(void);
    virtual void onDeinit(void);
    
    mmi_ret onLoadFileListResult(mmi_event_struct *param);
    
    VfxS32 getHyperlinkCount(VappFmgrInstance* instance);
    /* VfxS32 getHyperlinkInfo(VappFmgrInstance* instance, mmi_fmgr_hyperlink_info_struct *link_info); */
public:
    VfxBool IsCurrCallerInstance(VappFmgrInstance *instance) const;
    
    void setLoadRspCB(vapp_fmgr_load_response_callback cb);
    vapp_fmgr_load_response_callback getLoadRspCB(void) const;
    void setLoadProgressCB(vapp_fmgr_load_progress_callback cb);
    vapp_fmgr_load_progress_callback getLoadProgressCB(void) const;

    void setCallerInstance(VappFmgrInstance *instance);
    VappFmgrInstance* getCallerInstance(void) const;

    VfxS32 asyncLoadFileList(VappFmgrInstance* instance,
                             vapp_fmgr_load_response_callback load_rsp_cb,
                             vapp_fmgr_load_progress_callback load_progress_cb,
                             VfxS8* highlight_filename,
                             VfxBool checkDirty = VFX_TRUE);
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
    VfxS32 refreshDrvList(VappFmgrInstance *instance);
#endif
    VfxS32 createFileListHdlr(void);
    void setFileListHdle(SRV_FMGR_FILELIST_HANDLE hdle);
    SRV_FMGR_FILELIST_HANDLE getFileListHdlr(void) const;
    VfxS32 createEmptyFileListHdlr(VappFmgrInstance* instance);
    void clearFileListData(VappFmgrInstance *instance);
    void releaseCurrCallerFSData(VappFmgrInstance *instance);
    void setFileListParent(mmi_id parent_id);
    
    //void setFileListLock(VfxBool lock);
    //VfxBool getFileListLock(void) const;

    void setLoadFileIndex(VfxS32);
    void resetLoadFileIndex(void);
    VfxS32 getLoadFileIndex(void) const;
    
    VfxS32 getFileInfo(VappFmgrInstance* instance, VfxS32 index, VAPP_FMGR_FILE_INFO_STRUCT *file_info);
    
    VfxS32 getDrvInfo(VappFmgrInstance* instance, VfxS32 index, vapp_fmgr_drive_info_struct *file_info);

    VfxS32 getDrvCount(VappFmgrInstance* instance);

    void   setCount(VfxS32 count);
    VfxS32 getCount(void) const;
    VfxS32 getCountWithoutSF(void) const;
    
    void   setSystemFolderCount(VfxS32 count);
    VfxS32 getSystemFolderCount(void) const;
    
    void   setFileCount(VfxS32 count);
    VfxS32 getFileCount(void) const;

    void   setFolderCount(VfxS32 count);
    VfxS32 getFolderCount(void) const;

    void prepareFileListBuffer(VfxS32 app_id);
private:
    vapp_fmgr_load_response_callback load_rsp_cb;
    vapp_fmgr_load_progress_callback load_progress_cb;

    VappFmgrInstance *caller_instance;    /* which instance is using instance_data */
    SRV_FMGR_FILELIST_HANDLE file_list_hdl;
    mmi_id m_file_list_parent;
    //VfxBool          file_list_lock;

    VfxS32 load_file_index;

    VfxS32 m_count;
    VfxS32 m_system_folder_count;
    VfxS32 m_file_count;
    VfxS32 m_folder_count;

    /* Caller of CUI have to prepare file list buffer */
    VfxBool m_prepare_buffer;
    U8 *m_filelist_buffer;
    VfxS32 m_filelist_buffer_size;
    VfxS32 m_app_id;
};


class VappFmgrMain : public VappFmgrInstance
{
    VFX_DECLARE_CLASS(VappFmgrMain);

    friend class VappFmgrFolderBrowserLaunch;
    
private:
    mmi_id m_fs_id;
    VfxWeakPtr <VcpMenuPopup> m_opt_menu;
    
    /* for file detail information */
    VfxU16 m_file_action;    
    VfxS32 m_selected_index;
    VcpMenuPos m_selected_pos;
    
    /* for mark several */
    //VfxBool m_my_action;
    VfxU16 m_opt_menu_id;
    VfxWString m_selected_path;
#if defined (__COSMOS_SLIM_FMGR_MT6260__)	
	VcpConfirmPopup* mStorageReportPop;
#endif
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *param);
    mmi_ret onMarkSeveralProc(mmi_event_struct *param);
    virtual void onTapListMenuItem(VcpListMenu *listmenu, VfxU32 index);
    void showLongTapOption(VfxS8* file_name, VfxBool isfolder);
    void onLongTapListMenuItem(VcpListMenu *listmenu, VfxU32 index);
    void onLongTapGroupListMenuItem(VcpGroupListMenu *listmenu, VcpMenuPos pos);
    void onTapMarkSeveralListMenuItem(VcpListMenu *listmenu, VfxU32 index);
    virtual void onTapGroupListMenuItem(VcpGroupListMenu *listmenu, VcpMenuPos pos);
    
    virtual void setMenu(VcpListMenu * listmenu);
    virtual void setMenu(VcpGroupListMenu *menu);
        
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    // Free the image resource for the image fields of list cell
    virtual void closeItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc Image               // [IN] the image resource
        );

    // Get the item count of the lis menu
    virtual VfxU32 getCount() const;

    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

    virtual VfxBool getItemIsDisabled(
        VfxU32 index       // [IN] the index of item
        ) const;
    
    virtual VfxBool error_handler(VfxS32 error_code, VfxS32 line = __LINE__);

    VfxS32 launchFileTypeHandler(VAPP_FMGR_FILE_INFO_STRUCT *file_info);

    VfxS32 selectFolderDone(VfxWChar* path = NULL);
    VfxS32 selectMarkSeveralFolderDone(VfxWChar* path = NULL);
#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
    VfxU32 closeFileDetailPage(void);
#endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
    void closeStorageReport(void);
    void closeMarkSeveral(void);
    void closeAction(void);
    void onClickMenuPopup(VcpMenuPopup* opt_menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item);

    virtual void onClickConfirmButton(VfxObject* obj, VfxId id);

    void doFileListDirtyErrorHandle(void);
public:    
    virtual void onActionRsp(VfxObject* obj, VfxS32 error_code = FS_NO_ERROR, VfxBool no_on_confirm = VFX_FALSE);
    void onActionMarkSeveralRsp(VfxObject* obj, VfxS32 error_code = FS_NO_ERROR, VfxBool no_on_confirm = VFX_FALSE);
    VfxBool hideSelectAll(void);
    virtual void getOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num);
    void getMarkSeveralOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num);
    virtual VfxBool isMenuItemDisable(VfxU32 page_id, VfxU16 &opt_menu_id);
    VfxBool isMarkSeveralMenuItemDisable(VfxU32 page_id, VfxU16 &opt_menu_id);

    virtual void onClickToolBarButton(VfxObject* obj, VfxId button_id);    
    void onClickMarkSeveralToolBarButton(VfxObject* obj, VfxId button_id);    
#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
    virtual void onClickCmdButton(VcpListMenu *listmenu, VfxU32 index);
    virtual void onClickGroupCmdButton(VcpGroupListMenu *listmenu, VcpMenuPos pos);
#endif //#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
    virtual mmi_ret callProc(mmi_event_struct *param);

    //void setIsMyAction(VfxBool is_my_action);
        
    void closeMarkSeveralEx(void);
    void closeActionEx(void);

private:
	VfxBool isCurDrvInflunced(mmi_event_struct *evt);
	void exitCurApp();
#if defined(__COSMOS_SLIM_FMGR_MT6260__)
	void storageReportPopup(VfxId drvId);
	void onStorageBtnClicked(VfxObject* obj, VfxId id);
#endif
#ifdef __MMI_OPP_SUPPORT__
    void multiShareAsBT();
#endif
#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
    VfxS32 handleClickCmdButton(VfxS32 index, VfxS32 group = -1);
#endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
};

class VappFmgrTitleCell : public VfxControl
{
    VFX_DECLARE_CLASS(VappFmgrTitleCell);

public:
    enum
    {
    #ifdef __MMI_MAINLCD_480X800__
        ITEM_WIDTH = 480,
        ITEM_HEIGHT = 105,
        TXT_Y_GAP   = 3,
        TEXT_LSIDE_ALIGN = 14,
        TEXT_TSIDE_ALIGN = 31,
        BACK_ICON_WIDTH  = 60,
        BACK_ICON_HEIGHT = 59,
        ICON_TSIDE_ALIGN = 25,
        ICON_LSIDE_ALIGN = 14,
        ICON_RSIDE_ALIGN = 14,

        MAIN_FONT_SIZE = 35,
        SUB_FONT_SIZE = 26,
    #elif __MMI_MAINLCD_320X480__
        ITEM_WIDTH = 320,
        ITEM_HEIGHT = 64,
        TXT_Y_GAP   = 1,
        TEXT_LSIDE_ALIGN = 8,
        TEXT_TSIDE_ALIGN = 21,
        BACK_ICON_WIDTH  = 40,
        BACK_ICON_HEIGHT = 40,
        ICON_TSIDE_ALIGN = 25,
        ICON_LSIDE_ALIGN = 8,
        ICON_RSIDE_ALIGN = 8,

        MAIN_FONT_SIZE = 22,
        SUB_FONT_SIZE = 14,
    #else
        ITEM_WIDTH = 240,
        ITEM_HEIGHT = 46,
        TXT_Y_GAP   = 0,
        TEXT_LSIDE_ALIGN = 5,
        TEXT_TSIDE_ALIGN = 21,
        BACK_ICON_WIDTH  = 32,
        BACK_ICON_HEIGHT = 30,
        ICON_TSIDE_ALIGN = 25,
        ICON_LSIDE_ALIGN = 5,
        ICON_RSIDE_ALIGN = 5,

        MAIN_FONT_SIZE = 16,
        SUB_FONT_SIZE = 12,
    #endif       
        TEXT_WIDTH = (ITEM_WIDTH-3*TEXT_LSIDE_ALIGN-BACK_ICON_WIDTH),
        MAIN_TEXT_HEIGHT = MAIN_FONT_SIZE+2,
        SUB_TEXT_HEIGHT = SUB_FONT_SIZE+2,
        MAIN_TEXT_COLOR_R = 250,
        MAIN_TEXT_COLOR_G = 250,
        MAIN_TEXT_COLOR_B = 250,
        SUB_TEXT_COLOR_R = 225,
        SUB_TEXT_COLOR_G = 225,
        SUB_TEXT_COLOR_B = 225,
    };
    
	void setMainText(VfxWString &text);
	void setSubText(VfxWString &text);
    void setImage(VfxU16 res_id);
    void reLayout(VfxS32 width, VfxS32 height);
	VcpImageButton *getUpButton();
// Override
protected:
    virtual void onInit();

// Implementation
private:
    
    VfxFrame *m_bg;
    VfxImageFrame *m_img;
	VfxTextFrame *m_txt;
	VfxTextFrame *m_txt_sub;
	VcpImageButton *m_btn;
};

class VappFmgrPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappFmgrPage);
#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
    friend class VappFmgrFileDetail;
    friend class VappFmgrStorageDetail;

#endif
#ifndef __MMI_SLIM_FILE_MANAGER__
    friend class VappFmgrFolderDetail;    
#endif
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
    friend class VappFmgrDrvTabPage;
#endif
public:
    /* enum */    
    typedef enum {
        /* Draw specific page style */
        VAPP_FMGR_DRAW_DRV_PHONE_PAGE = 0,
        VAPP_FMGR_DRAW_DRV_MEM_PAGE,
        VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE,
        VAPP_FMGR_DRAW_NORMAL_LIST_PAGE,
        VAPP_FMGR_DRAW_NORMAL_LIST_LAST_PAGE = 129, 
        VAPP_FMGR_DRAW_SINGLE_FILE_SELECT_PAGE,
        VAPP_FMGR_DRAW_SINGLE_FILE_SELECT_LAST_PAGE = 258,
        VAPP_FMGR_DRAW_MULTI_FILE_SELECT_PAGE,
        VAPP_FMGR_DRAW_MULTI_FILE_SELECT_LAST_PAGE = 386,
        VAPP_FMGR_DRAW_FOLDER_SELECT_PAGE,
        VAPP_FMGR_DRAW_FOLDER_SELECT_LAST_PAGE = 514,
        // For media picker
        VAPP_FMGR_DRAW_MEDIA_PICKER_PAGE,
        VAPP_FMGR_DRAW_MEDIA_PICKER_LAST_PAGE = 642,
        VAPP_FMGR_DRAW_FOLDER_BROWSER_LAUNCH_PAGE,
        
        VAPP_FMGR_DRAW_FILE_DETAIL_PAGE,         
        VAPP_FMGR_DRAW_STORAGE_DETAIL_PHONE_PAGE,
        VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE,
        VAPP_FMGR_DRAW_STORAGE_REPORT,

        VAPP_FMGR_DRAW_DRV_TABCTRL_PAGE
    } VAPP_FMGR_PAGE_ID;

    typedef enum {
        /* Get specific title element info */
        VAPP_FMGR_PAGE_TITLE_BAR_MAIN_STR = 0,
        VAPP_FMGR_PAGE_TITLE_BAR_SUB_STR,
        VAPP_FMGR_PAGE_TITLE_BAR_ICON,        

        VAPP_FMGR_PAGE_TITLE_CELL_MAIN_STR,
        VAPP_FMGR_PAGE_TITLE_CELL_SUB_STR,
        VAPP_FMGR_PAGE_TITLE_CELL_ICON,
        VAPP_FMGR_PAGE_TITLE_CELL_UP_BUTTON,
        
        VAPP_FMGR_PAGE_TITLE_END
    } VAPP_FMGR_TITLE_ELEMENT;
public:        
	VappFmgrPage(): m_instance(NULL), m_pageId(0){}
	VappFmgrPage(VfxU32 pageId, VappFmgrInstance *instance)
	: m_instance(instance), m_pageId(pageId)
	{
		if (m_instance)
		{
			m_instance->setPageObj(this);
		}
	}
	virtual ~VappFmgrPage(){}
public:        
    virtual void setBounds(const VfxRect &value);   

    void setTextFrame(VfxTextFrame* textframe);
    VfxTextFrame* getTextFrame(void);

    void setInstance(VappFmgrInstance *instance);

    void setPageId(VfxU32 pageId);
    VfxU32 getPageId(void) const;
    
    void updatePage(VfxObject *obj, VfxU32 page_id, VfxS32 cur_index = 0, VfxBool list_reset = VFX_FALSE, VfxBool draw_loading = VFX_FALSE);
    void updatePageTitle(VfxObject *obj, VfxId page_id);
    void updatePageBody(VfxObject *obj, VfxId page_id, VfxS32 cur_index = 0, VfxBool list_reset = VFX_FALSE, VfxBool draw_loading = VFX_FALSE);
    void updatePageOptionMenu(VfxObject *obj, VfxId page_id);
    
    void drawListPage(VfxObject *obj, VfxU32 style = 0,  VfxS32 cur_index = 0, VfxBool list_reset = VFX_FALSE);
    void drawGroupListPage(VfxObject *obj, VfxU32 style = 0,  VfxS32 cur_index = 0, VfxBool list_reset = VFX_FALSE);
    void drawAllPage(VfxObject *obj, VfxU32 style = 0, VfxS32 cur_index = 0, VfxBool list_reset = VFX_FALSE);
    void drawPageBody(VfxObject *obj, VfxU32 style = 0, VfxS32 cur_index = 0, VfxBool list_reset = VFX_FALSE);
    void drawLoadingPage(VfxBool list_reset, VfxS32 fs_error);
    void drawEmptyPage(VfxObject *obj);
    void drawToolBar(VfxObject *obj);
    void drawTitleBar(VfxObject *obj);
    void drawTitleCell(VfxObject *obj, VfxBool draw_loading = VFX_FALSE);
    void popupError(VfxObject *obj, VfxS32 error);       

    VcpToolBar* getToolBarObj(void);
    VappFmgrTitleCell *getFirstCell(void);
        
    VfxSignal3 <VfxWString&, VfxU32, VfxU16&> m_signalGetTitleStrAndIcn;
    VfxSignal3 <VfxU32, VfxU16&, VfxU16&> m_signalGetOptMenuItem;
    void onUpdatePage(VfxObject *obj, VfxU32 style = 0, VfxU32 cp = VAPP_FMGR_UPDATE_PAGE_BODY, VfxS32 cur_index = 0, VfxBool list_reset = VFX_FALSE);

    void closePage();
    void popPage();
    void pushPage(VfxId id, VfxPage * p);
    
    void closePage(VfxId page_id);

    void removeAllButtonsFromToolbar(VfxU16 &opt_menu_id);

    void startNewFolderHiiteAnim(VfxS32 index);

    void setMenuViewState(VcpBaseMenuViewState* history);
    void resetMenuViewState(void);

    void showLoadingIndicator(void);
    void closeLoadingIndicator(void);
    void setExit(void);
    VfxBool getExit(void);
    void setPageRestore(VfxBool restore);
    VfxBool checkPageRestore(void);
    VfxU32 convertPageIdToCPTabIndex(VfxU32 page_id);
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onBack();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );
    
    virtual VfxBool onSerialize(VfxArchive & ar);
    virtual void onRestore(VfxArchive & ar);

    virtual void drawFileDetail(){};
    virtual void drawStorageDetail(){};       

    void onListFocusChange(VcpListMenu *list, // Sender
        VfxU32 index,        // Current focus list item index
        VfxU32 pre_index);

    void onTimeUp(VfxTimer* timer);
    
    typedef enum {
        VAPP_FMGR_UPDATE_PAGE_BODY      = 0x000001,
        VAPP_FMGR_UPDATE_PAGE_TOOLBAR   = 0x000002,
        VAPP_FMGR_UPDATE_PAGE_TITLEBAR  = 0x000004,
        VAPP_FMGR_UPDATE_PAGE_FIRSTCELL = 0x000008,
        VAPP_FMGR_UPDATE_PAGE_ALL       = 0x000010,
        VAPP_FMGR_UPDATE_PAGE_DRVLIST   = 0x000020,
        
        VAPP_FMGR_UPDATE_PAGE_END       = 0x000080
    } vapp_fmgr_update_page_cp;
                                   
    typedef enum {
        VAPP_FMGR_LIST_NORMAL = 0,
        VAPP_FMGR_LIST_SINGLE_FILE_SELECT,
        VAPP_FMGR_LIST_SINGLE_FOLDER_SELECT,        
        VAPP_FMGR_LIST_MULTI_SELECT_FOR_MARK_SEVERAL,
        VAPP_FMGR_LIST_MULTI_SELECT,

        VAPP_FMGR_LIST_GROUP,
        
        VAPP_FMGR_LOADING,
        VAPP_FMGR_EMPTY,
        VAPP_FMGR_FILE_DETAIL,
        VAPP_FMGR_FILE_DETAIL_TAB_STYLE,
        VAPP_FMGR_BODY_END
    } VAPP_FMGR_BODY_STYLE;
           
private:
#ifdef __MMI_MAINLCD_480X800__
    #define TEXT_FONT_SIZE 30
#elif __MMI_MAINLCD_320X480__
    #define TEXT_FONT_SIZE 20
#else
    #define TEXT_FONT_SIZE 16
#endif
    #define TEXT_COLOR VfxColor(255, 144, 144, 144)
    VfxBool          m_exit;
    VfxBool          m_restore;


    VfxU8            *m_pFolder;
    VfxObject        *m_context;
    VcpListMenu      *m_listmenu;
    VcpGroupListMenu *m_glist;
    VfxTextFrame     *m_textframe;
    VcpToolBar       *m_toolbar;
    VcpTitleBar      *m_titlebar;
    VappFmgrTitleCell *m_first_cell;
    VcpForm          *m_form;
    VfxWeakPtr <VcpCommandPopup> m_popup;
    VappFmgrInstance *m_instance;
    VfxU32 m_pageId;
    VfxTimer *m_focus_timer;
    VcpBaseMenuViewState *m_menu_view_state;

    /* Loading frame */
    VcpActivityIndicator *m_loading;
};

#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
class VappFmgrFileDetail : public VappFmgrPage
{
    VFX_DECLARE_CLASS(VappFmgrFileDetail);

#ifndef __MMI_SLIM_FILE_MANAGER__
    friend class VappFmgrFolderDetail;
#endif
    enum {
        ITEM_GEN_NAME = 1,
        ITEM_GEN_TYPE,
        ITEM_GEN_SIZE,
        ITEM_GEN_CREATE_TIME,
        ITEM_GEN_MODIFIED_TIME,
        ITEM_GEN_COPY_RIGHT,

        ITEM_EXTRA_CAPTION,

        /* ERROR */
        ITEM_EXTRA_ERROR,
        
        /* IMAGE TYPE */
        ITEM_IMG_WIDTH,
        ITEM_IMG_HEIGHT,
        ITEM_IMG_PREVIEW,

        /* AUDIO TYPE */
        ITEM_AUD_DURATION,
        ITEM_AUD_BITRATE,
        ITEM_AUD_BIT,
        ITEM_AUD_SAMPLE_RATE,

        /* VIDEO TYPE */
        ITEM_VDO_WIDTH,
        ITEM_VDO_HEIGHT,
        ITEM_VDO_BPP,
        ITEM_VDO_DURATION,

        /* BOOKMARK */
        ITEM_BM_NAME,
        ITEM_BM_URL,

        /* JAVA */
        ITEM_JAVA_MIDLET_NAME,
        ITEM_JAVA_MIDLET_VENDOR,

        ITEM_DETAIL_TOTAL,
    };
public:    
	VappFmgrFileDetail():m_file_info(NULL){}
	VappFmgrFileDetail(VfxU32 pageId, VappFmgrInstance* instance, VAPP_FMGR_FILE_INFO_STRUCT* file_info)
		:VappFmgrPage(pageId, instance)
	{
		setFileInfo(file_info);
	}
	virtual ~VappFmgrFileDetail(){}
public:	
    void setHideEditButton(VfxBool hide_editbutton);
    void setFileInfo(VAPP_FMGR_FILE_INFO_STRUCT* file_info);
    VfxS32 setPath(VfxWString &path, VAPP_FMGR_FILE_INFO_STRUCT* file_info);
    VfxS8* getPath(void);
    void setFolderViewerPageId(VfxU32 page_id);
    VfxU32 getFolderViewerPageId();
    VAPP_FMGR_FILE_INFO_STRUCT* getFileInfo(void);
    void unhideFileNameEditBtn(void);
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEntered();
    
    virtual void drawFileDetail();
private:
	#if !defined(__MMI_SLIM_FILE_MANAGER__)
    void createImgDetail(void);
    void drawImgDetail(void);
    void drawAudDetail(void);
    void drawVdoDetail(void);
    void drawBookmarkDetail(void);
	#endif // #if !defined(__MMI_SLIM_FILE_MANAGER__)
    
private:
    VfxBool m_create_img_frame;
    VfxBool m_hide_editbutton;
    VfxS32 m_error_code;
    VfxU32 m_folder_viewer_pageid;
    VfxS8 *m_path;
    VAPP_FMGR_FILE_INFO_STRUCT *m_file_info;
};
#endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)

#ifndef __MMI_SLIM_FILE_MANAGER__
class VappFmgrFolderDetail : public VappFmgrFileDetail
{
    VFX_DECLARE_CLASS(VappFmgrFolderDetail);
    
public:            
	VappFmgrFolderDetail(){}
	VappFmgrFolderDetail(VfxU32 pageId, VappFmgrInstance* instance, VAPP_FMGR_FILE_INFO_STRUCT* file_info)
		:VappFmgrFileDetail(pageId, instance, file_info){}
	virtual ~VappFmgrFolderDetail(){}
public:
    VfxS32 queryFirst();
    VfxS32 queryUpdate(VfxS32 job_id, VfxU64 folder_size = 0);
    void setWorkStatus(VfxBool work);
    VfxBool getWorkStatus();
    VfxS32 getDisplayStyle();
    void disableEdit(VfxBool disable);
    
protected:
    virtual void onInit();
    virtual void onDeinit();    
            
private:
    #define DISPLAY_STYLE 8  /* Should be sync with table.h */
    
    VfxBool m_working;
    VfxS32 m_jobid;
    VfxBool m_cancel;
};
#endif

/*
class VappFmgrPagePanel : public VcpPagePanel
{
    VFX_DECLARE_CLASS(VappFmgrPagePanel);
    
public:
    virtual void onInit();
};
*/
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
class VappFmgrDrvTabPage : public VcpTabCtrlPage
{
    VFX_DECLARE_CLASS(VappFmgrDrvTabPage);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    

public:
    VappFmgrDrvTabPage();
    VappFmgrDrvTabPage(VappFmgrInstance* instance);

    void onUpdateDrvTab(VfxId tab_id);

    VfxSignal1 <VfxId> m_switch;
// Override
public:
    virtual void onInit();
    virtual void onDeinit();    
    //virtual void onAfterInit();
    //virtual void onEnter(VfxBool isBackward);
    //virtual void onEntered();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual void onTabSwitching(
        VfxId tabId                     // [IN] id of new tab.
    );  
    virtual VfxPage *onCreateTabPage(
        VfxId tabId                     // [IN] id of tab to be created.
    );    

    VappFmgrPage *getPage(VfxId tabId);
    void setInstance(VappFmgrInstance* instance);
    void closeChildPage(void);
private:
    enum {
        PHONE_STYLE_ID = 0,
        CARD_STYLE_ID = 1
    };
    
    VappFmgrInstance     *m_instance;
    VappFmgrPage      *m_phone_page;  
    VappFmgrPage      *m_mem_page;      
};
#endif

#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
class VappFmgrStorageCapacityItem : public VcpFormItemBase
{
    VFX_DECLARE_CLASS(VappFmgrStorageCapacityItem);

    friend class VappFmgrStorageDetail;
        
protected:
    virtual void onInit();

public:
    enum {
    #ifdef __MMI_MAINLCD_480X800__
        ITEM_WIDTH = 480,
        ITEM_HEIGHT = 85,

        IMG_WIDTH = 450,
        IMG_HEIGHT = 30,

        LGAP = 15
    #elif __MMI_MAINLCD_320X480__
        ITEM_WIDTH = 320,
        ITEM_HEIGHT = 50,

        IMG_WIDTH = 297,
        IMG_HEIGHT = 30,

        LGAP = 10
    #else
        ITEM_WIDTH = 240,
        ITEM_HEIGHT = 44,

        IMG_WIDTH = 230,
        IMG_HEIGHT = 30,
        
        LGAP = 5
    #endif        
    };
    void setUsedSize(VfxFloat percentage);
    
private:
#ifdef __MMI_MAINLCD_480X800__        
    #define ICON_WIDTH 18
    #define ICON_HEIGHT 44
#elif __MMI_MAINLCD_320X480__
    #define ICON_WIDTH 11
    #define ICON_HEIGHT 27
#else
    #define ICON_WIDTH 10
    #define ICON_HEIGHT 23
#endif
    #define NUM_OF_ICON IMG_WIDTH/ICON_WIDTH

    VfxFrame *m_panel;
    VfxFrame *m_storage_usage[NUM_OF_ICON];
};

class VappFmgrStorageDetailItem : public VcpFormItemBase
{
    VFX_DECLARE_CLASS(VappFmgrStorageDetailItem);

    friend class VappFmgrStorageDetail;
        
protected:
    virtual void onInit();

public:
    enum {
    #ifdef __MMI_MAINLCD_480X800__
        ITEM_WIDTH = 480,
        ITEM_HEIGHT = 85,

        LRGAP = 15,

        CATE_WIDTH = 30,
        CATE_HEIGHT = 2,
        CATE_TGAP = 8,
        SIZE_WIDTH = 30,
        SIZE_HEIGHT = 2,
        SIZE_TGAP = 2,
        PER_WIDTH = 10,
        PER_HEIGHT = 10,
        PER_LGAP = 5,

        MAIN_FONT_SIZE = 35,
        SUB_FONT_SIZE = 26,
    #elif __MMI_MAINLCD_320X480__
        ITEM_WIDTH = 320,
        ITEM_HEIGHT = 50,

        LRGAP         = 10,

        CATE_WIDTH = 30,
        CATE_HEIGHT = 2,
        CATE_TGAP = 5,
        SIZE_WIDTH = 30,
        SIZE_HEIGHT = 2,
        SIZE_TGAP = 2,
        PER_WIDTH = 10,
        PER_HEIGHT = 10,
        PER_LGAP = 5,

        MAIN_FONT_SIZE = 20,
        SUB_FONT_SIZE = 14,        
    #else
        ITEM_WIDTH = 240,
        ITEM_HEIGHT = 44,

        LRGAP         = 5,

        CATE_WIDTH = 30,
        CATE_HEIGHT = 2,
        CATE_TGAP = 5,
        SIZE_WIDTH = 30,
        SIZE_HEIGHT = 2,
        SIZE_TGAP = 2,
        PER_WIDTH = 10,
        PER_HEIGHT = 10,
        PER_LGAP = 5,

        MAIN_FONT_SIZE = 18,
        SUB_FONT_SIZE = 14,
    #endif        
    };
    void setCategory(VfxU16 str_id);
    void setSizeString(const VfxWChar *size);
    void setPercentage(VfxFloat percentage);
    void setPercentage(VfxWString &text);
    
private:    
    VfxTextFrame *m_category;
    VfxTextFrame *m_size;
    VfxTextFrame *m_percentage;
};

class VappFmgrStorageDetail : public VappFmgrPage
{
    VFX_DECLARE_CLASS(VappFmgrStorageDetail);

    friend class VappFmgrStorageReport;
public:        
    enum{
        ITEM_CAPACITY = 1,
        ITEM_TOTAL = 2,
        ITEM_FREE = 3,

        ITEM_SYS_BEGIN = ITEM_FREE + 1,
        ITEM_SYS_END = ITEM_SYS_BEGIN + 20,

        ITEM_DEF_BEGIN = ITEM_SYS_END + 1,
        ITEM_DEF_END = ITEM_DEF_BEGIN + 20
    };
public:
	VappFmgrStorageDetail(){}
	VappFmgrStorageDetail(VfxU32 pageId, VappFmgrInstance* instance)
		:VappFmgrPage(pageId, instance){}
	virtual ~VappFmgrStorageDetail(){}
#ifndef __MMI_SLIM_FILE_MANAGER__
    VfxS32 queryFirst();
    VfxS32 queryUpdate(VfxS32 job_id, VfxU64 folder_size = 0, VfxS32 result = 0);
    VfxS32 queryNext();

    void prepareNext();
#endif
    void drawInit(VfxId tab_id);

    VfxS32 getErrorCode();

    VfxBool getDone();
protected:
    virtual void onInit();
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
#endif
    virtual void onEntered();
        
    virtual void drawStorageDetail();

    void drawSysCategory();
#ifndef __MMI_SLIM_FILE_MANAGER__
    void drawDefCategory();
#endif
private:
    enum {
        PHONE_STYLE_ID = 10,
        CARD_STYLE_ID = 11
    };
    
    VfxBool m_done;
    VfxS32 m_error_code;
    VfxObject *m_sr;
    VfxU64 m_total_size;
    VfxU64 m_free_size;
    VappFmgrStorageCapacityItem *m_capacity;
    VappFmgrStorageDetailItem *m_total;
    VappFmgrStorageDetailItem *m_free;
    VfxS8 m_cur_index;
    VfxS8 m_sys_count;
    VappFmgrStorageDetailItem **m_sys_contents;
    VappFmgrStorageDetailItem *m_def_contents[g_def_folder_table_size];
};
#endif // __COSMOS_SLIM_FMGR_MT6260__

#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
class VappFmgrStorageReport : public VcpTabCtrlPage
{
    VFX_DECLARE_CLASS(VappFmgrStorageReport);

    friend class VappFmgrStorageDetail;
    
public:
    VappFmgrStorageReport();
	VappFmgrStorageReport(const VfxId default_tab, VappFmgrInstance* instance);
    
    void setInstance(VappFmgrInstance *instance);   
    VfxBool isEntered(void);
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual VfxPage *onCreateTabPage(
        VfxId tabId                     // [IN] id of tab to be created.
    );
    
private:
    VfxId m_default_tab;
    VfxBool m_entered;
    VfxBool m_close;
    VfxBool m_cancel;
    VfxS32 m_jobid;    
    VappFmgrInstance     *m_instance;
    VappFmgrStorageDetail      *m_phone_page;  
    VappFmgrStorageDetail      *m_mem_page;
};
#endif

typedef struct vapp_fmgr_launch_args
{   
    VfxU8  app_type;
    VfxWChar file_path[SRV_FMGR_PATH_MAX_LEN+1];
    VfxU16 title_icon_id;
    VfxU16 title_str_id;
    VfxU16 opt_menu_id;
    FMGR_FILTER filter_type;

    /* Mark several */
    SRV_FMGR_FILELIST_HANDLE filelist_hdle;
    mmi_id filelist_parent_id;
    
    /* CUI settings */
    VfxU32 style;
    VfxU32 flag;
    VfxU32 user_data;
    
}vapp_fmgr_launch_args;

class VappFmgrMainScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappFmgrMainScr);

public:
    void setCallerInstance(VappFmgrInstance* instance);
    VappFmgrInstance* getCallerInstance(void);
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
    VappFmgrDrvTabPage *getTabCtrlPageObj(void);
#endif
    void showPopup(mmi_id parent_id, VfxU16 str_id, VcpPopupTypeEnum popup_type);
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onObjectNotify(VfxId id, void* userData);
    
    void onUpdatePage(VfxId tab_id);
    void onAfterInit();
    void onPopupStateChange(VfxBasePopup* obj,  VfxBasePopupStateEnum state);

private:
    VappFmgrInstance *m_instance;
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
    VappFmgrDrvTabPage *m_tabctrlpage;
#endif
    VcpConfirmPopup *m_popup;
    mmi_id m_groupid;
};

/* External interface */
#ifdef __cplusplus
extern "C"
#endif
{
extern mmi_ret vapp_fmgr_fsdata_onload_result_proc(mmi_event_struct *param);
extern mmi_ret vapp_fmgr_notify_hdlr(mmi_event_struct *param);
extern mmi_ret vapp_fmgr_action_multiple_result_proc(mmi_event_struct *param);
extern mmi_ret vapp_fmgr_action_single_result_proc(mmi_event_struct *param);
extern mmi_ret vapp_fmgr_async_create_folder_result_proc(mmi_event_struct *param);
#ifndef __MMI_SLIM_FILE_MANAGER__
extern mmi_ret vapp_fmgr_async_get_folder_size_result_proc(mmi_event_struct *param);
extern mmi_ret vapp_fmgr_async_get_single_folder_size_result_proc(mmi_event_struct *param);
#endif
extern void vapp_file_type_unknown_launch(mmi_menu_id item_id, const WCHAR* filepath, 
                     const srv_fmgr_fileinfo_struct* fileinfo);
extern MMI_ID vapp_fmgr_launch(void);
extern mmi_ret vapp_fmgr_proc(mmi_event_struct *in);
#ifdef __cplusplus
}
#endif

/* Aidan test file manager end */
#endif /* __VAPP_FMGR_PROT_H__ */

