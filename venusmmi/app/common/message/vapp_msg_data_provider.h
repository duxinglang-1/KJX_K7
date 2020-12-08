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
 * Vapp_msg_data_provider.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __VAPP_MSG_DATA_PROVIDER_H__
#define __VAPP_MSG_DATA_PROVIDER_H__

/*****************************************************************************
 * Include
 *****************************************************************************/


/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "MMI_features.h"
#include "UmSrvGprot.h"
#include "smssrvgprot.h"
#include "MmsSrvGprot.h"
#include "WAPPushSrvGprots.h"

#ifdef __cplusplus
}
#endif

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vfx_string.h"

/*****************************************************************************
 * Class VappMsgDataProvider
 *****************************************************************************/
#ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
#define VAPP_MSG_CONTENT_LENGTH  70
#define VAPP_MSG_WIDGET_EXT_INFO_NUM  8
#define VAPP_MSG_WIDGET_EXT_INFO_FS_MAX_LENTH (FS_GenVFN_SIZE + 12 + 1)
enum VappMsgReadStatus
{
    VAPP_MSG_READ_STATUS_READ,
    VAPP_MSG_READ_STATUS_UNREAD,

    VAPP_MSG_READ_STATUS_MAX
};

enum VappMsgWidgetExtInfoProcessingStatus
{
    VAPP_MSG_WIDGET_EXT_STATUS_OK,
    VAPP_MSG_WIDGET_EXT_STATUS_FAILED,
    VAPP_MSG_WIDGET_EXT_STATUS_PROCESSING,
    VAPP_MSG_WIDGET_EXT_STATUS_CANCELLING,
    VAPP_MSG_WIDGET_EXT_STATUS_UNUSED,
    
    VAPP_MSG_WIDGET_EXT_STATUS_MAX
};

enum VappMsgWidgetExtInfoThumbnailResult
{
    VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_OK = SRV_MMS_LITE_VIEWER_RESULT_OK,
    VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_VIDEO = SRV_MMS_LITE_VIEWER_VIDEO_TYPE,
    VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_DRM = SRV_MMS_LITE_VIEWER_DRM_TYPE,
    VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_FAIL = SRV_MMS_LITE_VIEWER_OPERATION_FAILED_ERROR,

    VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_NO_THUMBNAIL = VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_FAIL + 1,
    VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_PROCESSING = 0xff,
    VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_MAX
};

#ifdef __MMI_MMS_IN_UM__
typedef struct
{
    srv_mms_get_lite_viewer_text_req_struct txt_req_data;
    VfxU16 contentBuffer[VAPP_MSG_CONTENT_LENGTH + 1];
} vapp_msg_mms_content_cntx;

typedef struct
{
    srv_mms_get_lite_viewer_image_req_struct thumbnail_req_data;
    srv_mms_get_lite_view_data_struct *image_data; /*Lite viewer image related data*/
    S8 mem[VAPP_MSG_WIDGET_EXT_INFO_FS_MAX_LENTH] ;                                   /*memory buffer for virtual file name size = FS_GenVFN_SIZE+12 */    
} vapp_msg_mms_thumbnail_cntx;

class VappMsgWidgetExtInfo;
static void* vapp_msg_alloc_mem(U32 size, void *user_data);
static void vapp_msg_free_mem(void *mem);
static vapp_msg_mms_content_cntx *vapp_msg_construct_mms_lite_viewer_data(void* requester);
static void vapp_msg_destory_mms_lite_viewer_data(vapp_msg_mms_content_cntx *to_be_destroy);

static vapp_msg_mms_thumbnail_cntx *vapp_msg_construct_mms_lite_viewer_data_for_thumbnail(void* requester);
static void vapp_msg_destory_mms_lite_viewer_data_for_thumbnail(vapp_msg_mms_thumbnail_cntx *to_be_destroy);
#endif /* __MMI_MMS_IN_UM__ */

/* internal use only, please do not use it out of this file */
class VappMsgWidgetExtInfo : public VfxObject
{
    VFX_DECLARE_CLASS(VappMsgWidgetExtInfo);
    
    typedef VappMsgWidgetExtInfo    Self;
    typedef VfxObject        Super;
    
    public:
        VappMsgWidgetExtInfo();
        VappMsgWidgetExtInfo(VfxU32 msg_id, srv_um_msg_enum msg_type);
        const VfxWChar *getMsgContent();
        const VappMsgReadStatus *getMsgReadStatus();
        const VappMsgWidgetExtInfoThumbnailResult getMsgThumbnail(void**thumbnailPointer);
        VfxU32 getMsgID();
        srv_um_msg_enum getMsgType();
        VfxBool isDestroyable();
        /* will be emitted when the request is finished, 
           only will be emitted for async get method, 
           Please remember to check VappMsgWidgetExtInfo::mStatus 
           after calling getMsgWidgetExtInfo */
        VfxSignal1 <VappMsgWidgetExtInfo *> m_signalGetExtInfoFinished;
        /* will be emitted when the VappMsgWidgetExtInfo is become invalid*/
        VfxSignal1 <VappMsgWidgetExtInfo *> m_signalGetExtDestroyed;
        /* delete refreshed one */
        static mmi_ret msgRefreshProc(mmi_event_struct* evt);
        static void getSMSContentCallback(srv_sms_callback_struct* callback_data);
#ifdef __MMI_PUSH_IN_UM__
        static void getWapContetnCallback(pmg_detailed_msg_struct *msg_content ,kal_int8* url, void* user_data);
#endif /* __MMI_PUSH_IN_UM__ */
#ifdef __MMI_MMS_IN_UM__
        static void getMMSDataCallback(srv_mms_result_enum result, void *rsp_data, void *user_data);
#endif /* __MMI_MMS_IN_UM__ */
        static VfxBool isPendingProcessConflict(srv_um_msg_enum msgType);
        
    protected:
        virtual void onInit();
        virtual void onDeinit();
        void getExtInfoFromMesssage();
        VappMsgWidgetExtInfoProcessingStatus getProcessStatus();
        VfxBool isUsable();
        void deleteMessageUnit();
        void getExtInfoFromMesssageCallBack(void *msgData, VfxBool result);
        void resetMessageUnit();
        static VfxS32 mWappushProcessCounter;
        
    private:
        typedef void* VappMsgThumbNail;
        VfxU32 mMsgID;
        srv_um_msg_enum mMsgType;
        VappMsgWidgetExtInfoProcessingStatus mProcessStatus;
        VappMsgReadStatus mReadStatus;
        VfxWChar mContentBuffer[VAPP_MSG_CONTENT_LENGTH + 1];
        
        VfxChar mThumbnail[VAPP_MSG_WIDGET_EXT_INFO_FS_MAX_LENTH] ;
        VappMsgWidgetExtInfoThumbnailResult mThumbnailResult;
        
#ifdef __MMI_MMS_IN_UM__
        srv_mms_lite_viewer_handle_data mFileTable ;
        srv_mms_get_lite_viewer_data_rsp_struct *rsp_data;
        srv_mms_lite_viewer_deinit_callback thumbnailDestroyCallback; /* called to close the file handle */
#endif /* __MMI_MMS_IN_UM__ */

};
#endif /*  __MMI_VUI_WIDGET_KEY_MESSAGE__ */

class VappMsgDataProvider : public VfxObject
{
    VFX_DECLARE_CLASS(VappMsgDataProvider);

    typedef VappMsgDataProvider    Self;
    typedef VfxObject        Super;

public:
    VappMsgDataProvider();

    VfxS32 getMsgNum(
        srv_um_msg_enum msg_type,
        srv_um_get_msg_num_result &result
        );

    VfxS32 getMsgList(
        srv_um_box_identity_struct &msg_box,
        srv_um_list_filter_struct &filter,
        srv_um_notify_list_handler cb_func,
        VfxS32 user_data,
        srv_um_list_cntx_struct *&list_cntx
        );

    VfxS32 getThreadList(
        srv_um_box_identity_struct &msg_box,
        srv_um_list_filter_struct &filter,
        srv_um_notify_list_handler cb_func,
        VfxS32 user_data,
        srv_um_list_cntx_struct *&list_cntx
        );

    VfxS32 getMsgInfo(
        srv_um_msg_node_struct msg_list[],
        VfxU16 list_info_size,
        VfxU16 start_entry,
        VfxU16 msg_number,
        srv_um_msg_info_struct *msg_info[]
        );

    VfxS32 getThreadInfo(
        srv_um_thread_id_struct thread_list[],
        VfxU16 list_info_size,
        VfxU16 start_entry,
        VfxU16 thread_number,
        srv_um_thread_info_struct *thread_info[],
        srv_um_msg_info_struct *msg_info[]);
    
#ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
    /* return NULL for unfinished request */
    const VfxWChar* getMsgContent(srv_um_msg_node_struct *msgNode);
    /* return NULL for unfinished request */
    const VappMsgWidgetExtInfoThumbnailResult getMsgThumbnail(srv_um_msg_node_struct *msgNode, void**thumbnailPointer);
    /* return NULL for unfinished request */
    const VappMsgReadStatus* getMsgReadStatus(srv_um_msg_node_struct *msgNode);
    
    void onGetMsgExtInfoFinished(VappMsgWidgetExtInfo *finishedUnit);
    void onMsgExtInfoDestroyed(VappMsgWidgetExtInfo *destroyedUnit);
#endif /*  __MMI_VUI_WIDGET_KEY_MESSAGE__ */

    VfxS32 markSeveralOp(
        srv_um_box_identity_struct msg_box,
        srv_um_msg_node_struct msg_list[],
        U16 msg_list_size,
        U32 mark_status[],
        srv_um_mark_several_op_action_enum action_type);

    VfxS32 markSeveralThreadOp(
        srv_um_box_identity_struct msg_box,
        srv_um_thread_id_struct thread_list[],
        U16 thread_list_size,
        U32 mark_status[],
        srv_um_mark_several_op_action_enum action_type);
    
    VfxS32 cancelProcess(void);

    VfxBool isProcessing() const { return m_PID>0?VFX_TRUE:VFX_FALSE; }

    void setAutoGetData(VfxBool isAuto);

    VfxS32 getProcessProgress(VfxS32 &finishNum, VfxS32 &totalNum);

public :
    VfxSignal1 <srv_um_get_msg_num_result>     m_signalGetMsgNumFinished;
    VfxSignal1 <srv_um_get_msg_list_result>    m_signalGetMsgListFinished;
    VfxSignal1 <srv_um_get_msg_info_result>    m_signalGetMsgInfoFinished;
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    VfxSignal1 <srv_um_get_thread_list_result> m_signalGetThreadListFinished;
    VfxSignal1 <srv_um_get_thread_info_result> m_signalGetThreadInfoFinished;
#endif
    VfxSignal1 <srv_um_mark_several_op_result> m_signalMarkSeveralOpFinished;
    VfxSignal1 <srv_um_mark_several_thread_op_result> m_signalMarkSeveralThreadOpFinished;

#ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
    /* will be emitted when the content status is changed, 
       e.g., async request finished, become invalid and so on,
       listeners just need to re-get the content it needed */
    VfxSignal0 m_signalExtInfoUpdated;
#endif 


protected:
    virtual void onDeinit();

private:
    VfxS32 m_PID;
    VfxBool m_isAuto;
    
#ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
    S32 mMsgWidgetCounter;
    VappMsgWidgetExtInfo* mMsgWidgetExtInfoQueue[VAPP_MSG_WIDGET_EXT_INFO_NUM];
    VfxBool m_isInDeinit;
#endif /*  __MMI_VUI_WIDGET_KEY_MESSAGE__ */

private:
#ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
/* helper functions */
/* query one msg */
VappMsgWidgetExtInfo *getMsgExtInfoNode(srv_um_msg_node_struct *msgNode);

/* query cached */
VappMsgWidgetExtInfo *getMsgExtInfoNodeCache(srv_um_msg_node_struct *msgNode);

/* cache pool full */
VfxBool isMsgExtPoolFull();


#endif /* __MMI_VUI_WIDGET_KEY_MESSAGE__ */
    static VfxS32 getMsgNumCb     (VfxS32 pid, srv_um_get_msg_num_result* rsp, VfxS32 userData);
    static VfxS32 getMsgListCb    (VfxS32 pid, srv_um_get_msg_list_result* rsp, VfxS32 userData);
    static VfxS32 getMsgInfoCb    (VfxS32 pid, srv_um_get_msg_info_result* rsp, VfxS32 userData);
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    static VfxS32 getThreadListCb (VfxS32 pid, srv_um_get_thread_list_result* rsp, VfxS32 userData);
    static VfxS32 getThreadInfoCb (VfxS32 pid, srv_um_get_thread_info_result* rsp, VfxS32 userData);
#endif
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    static VfxS32 markSeveralOpCb (VfxS32 pid, srv_um_mark_several_op_result* rsp, VfxS32 userData);
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    static VfxS32 markSeveralThreadOpCb (VfxS32 pid, srv_um_mark_several_thread_op_result* rsp, VfxS32 userData);
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
};


/*****************************************************************************
 * Class VappBaseList
 *****************************************************************************/
class VappBaseList : public VfxObject
{
    VFX_DECLARE_CLASS(VappBaseList);

    typedef VappBaseList    Self;
    typedef VfxObject      Super;

public:
    VappBaseList();

    // Derived class may override this function.
    virtual void update() = 0;

    // Derived class may override this function.
    virtual void release(VfxBool fullRelease);

    void setMsgBoxInfo(
        srv_um_msg_enum msg_type,
        srv_um_msg_box_enum msg_box_type
    );

    srv_um_box_identity_struct getMsgBoxInfo() const;

    void setSortBy(
        srv_um_list_idx_enum idx_type,              // the index data type
        srv_um_sort_order_enum order                // the order of sorting
    );

    srv_um_list_filter_struct getFilter() const;

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    void setThreadID(
        srv_um_thread_id_struct thread_id
    );

    void setThreadIDbyAddress(
        srv_um_addr_enum type,
        VfxWString &addressMap
    );

    srv_um_thread_id_struct getThreadID() const;
#endif

    VfxS32 getListSize() const;

    VfxBool isOutOfDate() const;

    void *getList() const;

    VfxBool isUpdating() const;

public:
    VfxSignal0 m_signalListUpdating;
    VfxSignal0 m_signalListUpdated;
    VfxSignal0 m_signalListReleased;

protected:
    VappMsgDataProvider *m_msgDataProvider;
    srv_um_box_identity_struct m_msgBox;
    srv_um_list_filter_struct m_filter;
    srv_um_list_cntx_struct *m_listCntx;
    VfxBool m_isModified;
    VfxS32 m_listCntxID;
    VfxBool m_isUpdating;

protected:
    static void listMgrNotifyCB(
        VfxS32 event,
        VfxS32 list_cid,
        VfxS32 user_data
    );

    // Derived class may override this function.
    virtual void onListMgrNotify(VfxS32 event, VfxS32 list_cid);

    virtual void onInit();

    virtual void onDeinit();
};

/*****************************************************************************
 * Class VappMsgList
 *****************************************************************************/
class VappMsgList : public VappBaseList
{
    VFX_DECLARE_CLASS(VappMsgList);

    typedef VappMsgList    Self;
    typedef VappBaseList   Super;

    public:
        virtual void update();
        srv_um_msg_node_struct *getMsgList() const;

    protected:
        virtual void onInit();

    private:
        virtual void forceUpdate();
        void onGetMsgListFinished(srv_um_get_msg_list_result );
};

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
#endif
/*****************************************************************************
 * Global Function
 *****************************************************************************/

#endif
