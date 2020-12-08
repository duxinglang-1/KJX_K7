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
 * Vapp_msg_data_provider.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "MMI_features.h"

/*****************************************************************************
 * Include
 *****************************************************************************/
/**********  KAL Layer Header **************/
#ifdef __cplusplus
extern "C"
{
#endif

#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "GlobalDefs.h"
#ifdef __cplusplus
}
#endif

/**********  MMI Layer Header **************/
#include "MMI_features.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_system.h"
#include "vfx_signal.h"
#include "vfx_string.h"
#include "vrt_datatype.h"
#include "vadp_app_trc.h"
#include "vapp_msg_data_provider.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "MMIDataType.h"
#include "UmSrvDefs.h"
#include "UmSrvGprot.h"
#include "ProvBoxSrvGprot.h"

#ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
#include "mmi_rp_app_sms_def.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#endif

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 *
 * Class VappMsgDataProvider
 *
 *****************************************************************************/
#ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
static void* vapp_msg_alloc_mem(U32 size, void *user_data)
{
    void *temp = NULL;
    VFX_ALLOC_MEM(temp, size, (IVfxAllocatable *)user_data);
    return temp;
};

static void vapp_msg_free_mem(void *mem)
{
    VFX_FREE_MEM(mem);
}

#ifdef __MMI_MMS_IN_UM__
static vapp_msg_mms_content_cntx *vapp_msg_construct_mms_lite_viewer_data(void* requester)
{
    vapp_msg_mms_content_cntx *cntx = NULL;
    srv_mms_get_lite_viewer_text_req_struct *req_data = NULL;
    VFX_ALLOC_MEM(cntx, sizeof(vapp_msg_mms_content_cntx),(IVfxAllocatable *)requester);
    req_data = &cntx->txt_req_data;
    req_data->alloc_fn = vapp_msg_alloc_mem;
    req_data->free_fn = vapp_msg_free_mem;
    req_data->mem = &(cntx->contentBuffer[0]);
    cntx->contentBuffer[0] = 0;
    req_data->msg_id = ((VappMsgWidgetExtInfo*)requester)->getMsgID();
    req_data->user_data = requester;
    req_data->txt_size = VAPP_MSG_CONTENT_LENGTH;
    return cntx;
}

static void vapp_msg_destory_mms_lite_viewer_data(vapp_msg_mms_content_cntx *to_be_destroy)
{
    VFX_FREE_MEM(to_be_destroy);
};

static vapp_msg_mms_thumbnail_cntx *vapp_msg_construct_mms_lite_viewer_data_for_thumbnail(void* requester)
{
    vapp_msg_mms_thumbnail_cntx *cntx = NULL;
    srv_mms_get_lite_viewer_image_req_struct *req_data = NULL;
    VFX_ALLOC_MEM(cntx, sizeof(vapp_msg_mms_thumbnail_cntx), (IVfxAllocatable *)requester);
    req_data = &cntx->thumbnail_req_data;
    req_data->mem = &(cntx->mem[0]);
    req_data->msg_id = ((VappMsgWidgetExtInfo*)requester)->getMsgID();
    return cntx;

}
static void vapp_msg_destory_mms_lite_viewer_data_for_thumbnail(vapp_msg_mms_thumbnail_cntx *to_be_destroy)
{
    VFX_FREE_MEM(to_be_destroy);
}

#endif /* __MMI_MMS_IN_UM__ */


VfxS32 VappMsgWidgetExtInfo::mWappushProcessCounter = 0;
VFX_IMPLEMENT_CLASS("VappMsgWidgetExtInfo", VappMsgWidgetExtInfo, VfxObject);
VappMsgWidgetExtInfo::VappMsgWidgetExtInfo()
{};

VappMsgWidgetExtInfo::VappMsgWidgetExtInfo(VfxU32 msg_id, srv_um_msg_enum msg_type) :
    mMsgID(msg_id), 
    mMsgType(msg_type), 
    mProcessStatus(VAPP_MSG_WIDGET_EXT_STATUS_UNUSED), 
    mReadStatus(VAPP_MSG_READ_STATUS_MAX), 
    mThumbnailResult(VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_OK),
	rsp_data(NULL),
	thumbnailDestroyCallback(NULL)
{
        mContentBuffer[0] = 0;
        mFileTable.file_handle = 0;
        mFileTable.msg_id = SRV_SMS_INVALID_MSG_ID;
};
void VappMsgWidgetExtInfo::onInit()
{
    Super::onInit();
    getExtInfoFromMesssage();
    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH, msgRefreshProc, this);
};


void VappMsgWidgetExtInfo::onDeinit()
{
    //VFX_ASSERT(mProcessStatus != VAPP_MSG_WIDGET_EXT_STATUS_PROCESSING);
    //VFX_ASSERT(mProcessStatus != VAPP_MSG_WIDGET_EXT_STATUS_CANCELLING);
    /* Destroy mms virtual file */
    m_signalGetExtDestroyed.emit(this);
    if (mFileTable.file_handle && rsp_data && thumbnailDestroyCallback)
    {
        thumbnailDestroyCallback(&mFileTable);
    }
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH, msgRefreshProc, this);
    Super::onDeinit();

};


VappMsgWidgetExtInfoProcessingStatus VappMsgWidgetExtInfo::getProcessStatus()
{
    return mProcessStatus;
};


VfxBool VappMsgWidgetExtInfo::isUsable()
{
    return ((VAPP_MSG_WIDGET_EXT_STATUS_OK == mProcessStatus) ||
            (VAPP_MSG_WIDGET_EXT_STATUS_FAILED== mProcessStatus));
};


void VappMsgWidgetExtInfo::deleteMessageUnit()
{
    VappMsgWidgetExtInfo *self = this;
    if (isDestroyable())
    {
        VFX_OBJ_CLOSE(self);
    }
    else
    {
        mProcessStatus = VAPP_MSG_WIDGET_EXT_STATUS_CANCELLING;
    }
    
};

const VfxWChar *VappMsgWidgetExtInfo::getMsgContent()
{
    if (isUsable())
    {
        return mContentBuffer;
    }
    else
    {
        return NULL;
    }
};


const VappMsgReadStatus *VappMsgWidgetExtInfo::getMsgReadStatus()
{
    if (isUsable())
    {
        return &mReadStatus;
    }
    else
    {
        return NULL;
    }
};


const VappMsgWidgetExtInfoThumbnailResult VappMsgWidgetExtInfo::getMsgThumbnail(void** thumbnailPointer)
{
    *thumbnailPointer = NULL;
    if (mMsgType == SRV_UM_MSG_MMS)
    {
       if (!isUsable())
       {
           return VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_PROCESSING;
       }
       else
       {
           if (VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_OK == mThumbnailResult)
           {
               *thumbnailPointer = mThumbnail;
           }
       }
    }
    return mThumbnailResult;
};


VfxU32 VappMsgWidgetExtInfo::getMsgID()
{
    return mMsgID;
};


srv_um_msg_enum VappMsgWidgetExtInfo::getMsgType()
{
    return mMsgType;
};


VfxBool VappMsgWidgetExtInfo::isDestroyable()
{
    return ((mProcessStatus != VAPP_MSG_WIDGET_EXT_STATUS_PROCESSING) &&
            (mProcessStatus != VAPP_MSG_WIDGET_EXT_STATUS_CANCELLING));
};


#ifdef __MMI_MMS_IN_UM__
void VappMsgWidgetExtInfo::getMMSDataCallback(srv_mms_result_enum result, void *rsp_data, void *user_data)
{
    VappMsgWidgetExtInfo *my_provider =  (VappMsgWidgetExtInfo *)  VfxObject::handleToObject((VfxObjHandle*)user_data);
    if (NULL != my_provider)
    {
        if (SRV_MMS_RESULT_OK == result)
        {
           /* get content from rsp data*/
            vapp_msg_mms_content_cntx *cntx = 
                vapp_msg_construct_mms_lite_viewer_data(my_provider);
            srv_mms_get_lite_viewer_text_req_struct *content_req = &cntx->txt_req_data;
            my_provider->rsp_data = (srv_mms_get_lite_viewer_data_rsp_struct *)rsp_data;
            my_provider->thumbnailDestroyCallback = my_provider->rsp_data->cb_deinit_function;
            content_req->txt_data = &my_provider->rsp_data->thumbnail_info_txt;
            content_req->msg_type = ((srv_mms_get_lite_viewer_data_rsp_struct *)rsp_data)->msg_type;
            content_req->storage_type= ((srv_mms_get_lite_viewer_data_rsp_struct *)rsp_data)->storage_type;
            content_req->txt_size = VAPP_MSG_CONTENT_LENGTH;
            if (content_req->txt_size > my_provider->rsp_data->thumbnail_info_txt.body_size)
            {
                content_req->txt_size = my_provider->rsp_data->thumbnail_info_txt.body_size;
            }
            if (((srv_mms_get_lite_viewer_data_rsp_struct *)rsp_data)->cb_text_function)
            {
                if (SRV_MMS_RESULT_OK == ((srv_mms_get_lite_viewer_data_rsp_struct *)rsp_data)->cb_text_function(content_req))
                {
                    mmi_ucs2ncpy((CHAR*)my_provider->mContentBuffer, (CHAR*)content_req->mem, VAPP_MSG_CONTENT_LENGTH);
                }
                else
                {
                    VfxWString text;
                    text.loadFromRes(STR_GLOBAL_UNSUPPORTED_FORMAT);
                    mmi_ucs2cpy((CHAR*)my_provider->mContentBuffer, (CHAR*)text.getBuf());
                }
            }
            else
            {
                my_provider->mContentBuffer[0] = 0;
            }
            vapp_msg_destory_mms_lite_viewer_data(cntx);
            
            /* get thumbnail from callback */
            vapp_msg_mms_thumbnail_cntx *thumbnail_cntx = vapp_msg_construct_mms_lite_viewer_data_for_thumbnail(my_provider);
            thumbnail_cntx->thumbnail_req_data.image_data = &((srv_mms_get_lite_viewer_data_rsp_struct *)rsp_data)->thumbnail_info;
            thumbnail_cntx->thumbnail_req_data.msg_type = ((srv_mms_get_lite_viewer_data_rsp_struct *)rsp_data)->msg_type;
            thumbnail_cntx->thumbnail_req_data.storage_type= ((srv_mms_get_lite_viewer_data_rsp_struct *)rsp_data)->storage_type;
            thumbnail_cntx->thumbnail_req_data.file_table = &my_provider->mFileTable;
            if (((srv_mms_get_lite_viewer_data_rsp_struct *)rsp_data)->cb_image_function)
            {
                my_provider->mThumbnailResult = 
                              ( VappMsgWidgetExtInfoThumbnailResult) ((srv_mms_get_lite_viewer_data_rsp_struct *)rsp_data)->cb_image_function(&thumbnail_cntx->thumbnail_req_data);

                if (VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_OK == my_provider->mThumbnailResult)
                {
                    memcpy(my_provider->mThumbnail, thumbnail_cntx->thumbnail_req_data.mem, VAPP_MSG_WIDGET_EXT_INFO_FS_MAX_LENTH);
                }
            }
            else
            {
                my_provider->mThumbnail[0] = 0;
                my_provider->mThumbnailResult = VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_NO_THUMBNAIL;
            }
            vapp_msg_destory_mms_lite_viewer_data_for_thumbnail(thumbnail_cntx);
            
        }
        else
        {
            VfxWString text;
            text.loadFromRes(STR_GLOBAL_FAILED);
            mmi_ucs2cpy((CHAR*)my_provider->mContentBuffer, (CHAR*)text.getBuf());
        }
        
        my_provider->getExtInfoFromMesssageCallBack(NULL, (SRV_MMS_RESULT_OK == result));
    }
}
#endif /* __MMI_MMS_IN_UM__ */


void VappMsgWidgetExtInfo::getExtInfoFromMesssage()
{
    // invoke different process
    mProcessStatus = VAPP_MSG_WIDGET_EXT_STATUS_PROCESSING;
    // start process
    switch(mMsgType)
    {
        case SRV_UM_MSG_SMS:
        {
            srv_sms_status_enum status = srv_sms_get_msg_status(mMsgID);
            if (SRV_SMS_STATUS_UNREAD & status)
            {
                mReadStatus = VAPP_MSG_READ_STATUS_UNREAD;
            }
            else
            {
                mReadStatus = VAPP_MSG_READ_STATUS_READ;
            }
            
            srv_sms_msg_data_struct *msg_data = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));
            msg_data->para_flag = SRV_SMS_PARA_CONTENT_BUFF;
            VFX_SYS_ALLOC_MEM(msg_data->content_buff, (VAPP_MSG_CONTENT_LENGTH + 1)* ENCODING_LENGTH);
            msg_data->content_buff_size = VAPP_MSG_CONTENT_LENGTH * ENCODING_LENGTH;
            srv_sms_read_msg(
                mMsgID,
                MMI_FALSE,
                msg_data,
                &VappMsgWidgetExtInfo::getSMSContentCallback,
                getObjHandle());
        }
            break;
#ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:  
        {
            if (MMI_TRUE == srv_mms_mma_get_mms_read_status(mMsgID))
            {
                mReadStatus = VAPP_MSG_READ_STATUS_READ;
            }
            else
            {
                mReadStatus = VAPP_MSG_READ_STATUS_UNREAD;
            }
            
           // srv_mms_get_lite_view_data_struct data;
            //srv_mms_get_lite_view_data(mMsgID, &data);
            // update data to  mThumbnail
            const VfxU8 MMS_APP_ID = 0;
            srv_mms_get_lite_viewer_data_req_struct req;
            req.app_id = MMS_APP_ID;
            req.call_back = &VappMsgWidgetExtInfo::getMMSDataCallback;
            req.msg_id = mMsgID;
            req.user_data = getObjHandle();
            srv_mms_get_lite_viewer_data(&req);
        }
        break;
#endif /* __MMI_MMS_IN_UM__ */
#ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            VappMsgWidgetExtInfo::mWappushProcessCounter++;
            srv_wap_push_get_msg_content(mMsgID, &VappMsgWidgetExtInfo::getWapContetnCallback, getObjHandle());
        }
            break;
#endif /* __MMI_PUSH_IN_UM__ */
#ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            if (SRV_PROVBOX_MSG_READ_STATUS_READ == srv_provbox_get_msg_status(mMsgID))
            {
                mReadStatus = VAPP_MSG_READ_STATUS_READ;
            }
            else
            {
                mReadStatus = VAPP_MSG_READ_STATUS_UNREAD;
            }
            mProcessStatus = VAPP_MSG_WIDGET_EXT_STATUS_OK;
        }
            break;
#endif /* __MMI_PUSH_IN_UM__ */
        default:
        {
            mReadStatus = VAPP_MSG_READ_STATUS_READ;
            mProcessStatus = VAPP_MSG_WIDGET_EXT_STATUS_OK;
            VFX_ASSERT(!"Invalid Messag Type");
        }
    }
    // if sync one, refresh status
    if (isUsable())
    {
        getExtInfoFromMesssageCallBack(NULL, VFX_TRUE);
    }
    else
    {
        // if async one, wait callback
    }
}


void VappMsgWidgetExtInfo::getExtInfoFromMesssageCallBack(void *msgData, VfxBool result)
{
    if (VAPP_MSG_WIDGET_EXT_STATUS_CANCELLING != mProcessStatus)
    {
        if (result)
        {
            mProcessStatus = VAPP_MSG_WIDGET_EXT_STATUS_OK;
        }
        else
        {
            mProcessStatus = VAPP_MSG_WIDGET_EXT_STATUS_FAILED;
        }
        // fill data fields
    }
    else
    {
        mProcessStatus = VAPP_MSG_WIDGET_EXT_STATUS_UNUSED;
    }
    m_signalGetExtInfoFinished.emit(this);
}


mmi_ret VappMsgWidgetExtInfo::msgRefreshProc(mmi_event_struct* evt)
{
    //judge if current message is in refreshed type, 
    //if yes, destroy it
    srv_um_notify_refresh_evt_struct *refresh_srv_evt = (srv_um_notify_refresh_evt_struct*)evt;
    if (((VappMsgWidgetExtInfo*)evt->user_data)->mMsgType & refresh_srv_evt->msg_type)
    {
        ((VappMsgWidgetExtInfo*)evt->user_data) ->deleteMessageUnit();
    }
    return MMI_OK;
};


void VappMsgWidgetExtInfo::resetMessageUnit()
{
    mMsgID = SRV_SMS_INVALID_MSG_ID;
    mMsgType = SRV_UM_MSG_NONE;
    mReadStatus = VAPP_MSG_READ_STATUS_MAX;
    mContentBuffer[0] = 0;
    mThumbnail[0] = 0;
}

void VappMsgWidgetExtInfo::getSMSContentCallback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_msg_cb_struct *read_msg_cb_data;
    srv_sms_msg_data_struct *msg_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_msg_cb_data = (srv_sms_read_msg_cb_struct*)callback_data->action_data;
    msg_data = read_msg_cb_data->msg_data;
    
    VappMsgWidgetExtInfo *my_provider =  (VappMsgWidgetExtInfo *)  VfxObject::handleToObject((VfxObjHandle*)(srv_sms_read_msg_cb_struct*)callback_data->user_data);

    if (my_provider && my_provider->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgWidgetExtInfo)))
    {
        mmi_ucs2ncpy((CHAR*)my_provider->mContentBuffer, (CHAR*)msg_data->content_buff, VAPP_MSG_CONTENT_LENGTH);
        srv_sms_status_enum status = srv_sms_get_msg_status(my_provider->getMsgID());
        VfxU16 string_id = 0;
        
        if (srv_sms_is_msg_complete(my_provider->getMsgID()) == MMI_FALSE)
        {
            string_id = STR_UM_INCOMPLETE_ID;
        }
        else if (srv_sms_get_msg_mti(my_provider->getMsgID()) == SRV_SMS_MTI_STATUS_REPORT)
        {
            string_id = STR_SR_DELIVERD_ID; //STR_SR_DELIVERD_ID;
        }
        else if (status & SRV_SMS_STATUS_UNSUPPORTED)
        {
            string_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
        }
        
        if (string_id != 0)
        {
            VfxWString text;
            text.loadFromRes(string_id);
            mmi_ucs2cpy((CHAR*)my_provider->mContentBuffer, (CHAR*)text.getBuf());
        }
        my_provider->getExtInfoFromMesssageCallBack(NULL, (MMI_TRUE == callback_data->result));
    }
    VFX_SYS_FREE_MEM(msg_data->content_buff);
    OslMfree(msg_data);
}


#ifdef __MMI_PUSH_IN_UM__
void VappMsgWidgetExtInfo::getWapContetnCallback(pmg_detailed_msg_struct *msg_content ,kal_int8* url, void* user_data)
{
    VappMsgWidgetExtInfo *my_provider =  (VappMsgWidgetExtInfo *)  VfxObject::handleToObject((VfxObjHandle*)user_data);
    if (my_provider && my_provider->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgWidgetExtInfo)))
    {
        if (WAP_PMG_STRTYPE_ASCII == msg_content->text_type)
        {
            mmi_asc_to_ucs2((CHAR *)my_provider->mContentBuffer, (CHAR *)msg_content->text);
        }
        else
        {
            mmi_ucs2ncpy((CHAR *)my_provider->mContentBuffer, (CHAR *)msg_content->text, VAPP_MSG_CONTENT_LENGTH);
        }
        if (msg_content->read)
        {
            my_provider->mReadStatus = VAPP_MSG_READ_STATUS_READ;
        }
        else
        {
            my_provider->mReadStatus = VAPP_MSG_READ_STATUS_UNREAD;
        }
        my_provider->getExtInfoFromMesssageCallBack(NULL, VFX_TRUE);
    }
    VappMsgWidgetExtInfo::mWappushProcessCounter--;
};
#endif /* __MMI_PUSH_IN_UM__ */


VfxBool VappMsgWidgetExtInfo::isPendingProcessConflict(srv_um_msg_enum msgType)
{
#ifdef __MMI_PUSH_IN_UM__
    if ((SRV_UM_MSG_WAP_PUSH == msgType) &&
        (mWappushProcessCounter > 0))
    {
        return VFX_TRUE;
    }
#endif /* __MMI_PUSH_IN_UM__ */

#ifdef __MMI_MMS_IN_UM__
    if ((SRV_UM_MSG_MMS == msgType) && 
         (MMI_TRUE == srv_mms_is_lite_view_content_req_reached_max()))
    {
        return VFX_TRUE;
    }
#endif /* __MMI_MMS_IN_UM__ */
    return VFX_FALSE;
};
#endif /* __MMI_VUI_WIDGET_KEY_MESSAGE__ */


VFX_IMPLEMENT_CLASS("VappMsgDataProvider", VappMsgDataProvider, VfxObject);
VappMsgDataProvider::VappMsgDataProvider()
{
    VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_ONINIT, (VfxS32) this);

    m_PID = 0;
    m_isAuto = VFX_TRUE;
#ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
	mMsgWidgetCounter = 0;
	memset(mMsgWidgetExtInfoQueue, 0, sizeof(mMsgWidgetExtInfoQueue));
    m_isInDeinit = VFX_FALSE;
#endif /* __MMI_VUI_WIDGET_KEY_MESSAGE__ */
}

void VappMsgDataProvider::onDeinit()
{
    VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_ONDEINIT, (VfxS32) this);
#ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
    m_isInDeinit = VFX_TRUE;
#endif
    cancelProcess();
    Super::onDeinit();
}

// -------------------------------------------------------------
// Property Set/Get
// -------------------------------------------------------------

void VappMsgDataProvider::setAutoGetData(VfxBool isAuto)
{
    if (m_PID == 0)
    {
        m_isAuto = isAuto;
    }
}


// -------------------------------------------------------------
// Method
// -------------------------------------------------------------


VfxS32 VappMsgDataProvider::getMsgNum(
     srv_um_msg_enum msg_type,
     srv_um_get_msg_num_result &result)
{

    VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETMSGNUM, (VfxS32) this, m_PID, m_isAuto);

    if (m_PID > 0)
    {
        return SRV_UM_RESULT_TOO_MANY_THREAD;
    }

    if (!m_isAuto)
    {
        return SRV_UM_RESULT_DATA_NOT_FOUND;
    }

    m_PID = srv_um_get_msg_num(msg_type, SRV_UM_SIM_ALL, Self::getMsgNumCb, (S32)getObjHandle());

    VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_PID, m_PID);

    return SRV_UM_RESULT_PROCESS_BUSY;
}

VfxS32 VappMsgDataProvider::getMsgList(
    srv_um_box_identity_struct &msg_box,
    srv_um_list_filter_struct &filter,
    srv_um_notify_list_handler cb_func,
    VfxS32 user_data,
    srv_um_list_cntx_struct *&list_cntx)
{

    VfxS32 result;

    result = srv_um_check_msg_list(msg_box, &filter, cb_func, user_data, &list_cntx);

//    printf("VappMsgDataProvider::getMsgList %d %d\n", user_data, result);

    VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETMSGLIST, (VfxS32) this, result);

    if (result > SRV_UM_RESULT_OK)
    {
        return result;
    }
    else if (!m_isAuto)
    {
        return result;
    }

    if (m_PID > 0)
    {
        return SRV_UM_RESULT_TOO_MANY_THREAD;
    }

    m_PID = srv_um_get_msg_list(msg_box, &filter, Self::getMsgListCb, (S32)getObjHandle());

    VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_PID, m_PID);

    return SRV_UM_RESULT_PROCESS_BUSY;

}


VfxS32 VappMsgDataProvider::getMsgInfo(
    srv_um_msg_node_struct msg_list[],
    VfxU16 list_info_size,
    VfxU16 start_entry,
    VfxU16 msg_number,
    srv_um_msg_info_struct *msg_info[])
{
    VfxS32 result;
 
    srv_um_box_identity_struct msg_box = {SRV_UM_MSG_ALL, SRV_UM_MSG_BOX_ALL, SRV_UM_SIM_ALL};

    result = srv_um_check_msg_info_by_ref(msg_box, msg_list, list_info_size, start_entry, msg_number, msg_info);

    VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETMSGINFO, (VfxS32) this, result);

    if (result == SRV_UM_RESULT_OK)
    {
        return SRV_UM_RESULT_OK;
    }
    else if (!m_isAuto)
    {
        return result;
    }

    if (m_PID > 0)
    {
        return SRV_UM_RESULT_TOO_MANY_THREAD;
    }

    // get lot of message together to enhance performance
    if (list_info_size - start_entry < 8)
    {
        msg_number = list_info_size - start_entry;
    }
    else if (msg_number < 8)
    {
        msg_number = 8;
    }

    m_PID = srv_um_get_msg_info(msg_box, msg_list + start_entry, msg_number, Self::getMsgInfoCb, (S32)getObjHandle());

    VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_PID, m_PID);

    return SRV_UM_RESULT_PROCESS_BUSY;

}

VfxS32 VappMsgDataProvider::getThreadList(
    srv_um_box_identity_struct &msg_box,
    srv_um_list_filter_struct &filter,
    srv_um_notify_list_handler cb_func,
    VfxS32 user_data,
    srv_um_list_cntx_struct *&list_cntx)
{
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    VfxS32 result;

    result = srv_um_check_thread_list(msg_box, &filter, cb_func, user_data, &list_cntx);

    VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETTHREADLIST, (VfxS32) this, result);

    if (result > SRV_UM_RESULT_OK)
    {
        return result;
    }
    else if (!m_isAuto)
    {
        return result;
    }

    if (m_PID > 0)
    {
        return SRV_UM_RESULT_TOO_MANY_THREAD;
    }

    m_PID = srv_um_get_thread_list(msg_box, &filter, Self::getThreadListCb, (S32)getObjHandle());

    VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_PID, m_PID);

    return SRV_UM_RESULT_PROCESS_BUSY;
#else
    return SRV_UM_RESULT_NOT_SUPPORT;
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
}

VfxS32 VappMsgDataProvider::getThreadInfo(
    srv_um_thread_id_struct thread_list[],
    VfxU16 list_info_size,
    VfxU16 start_entry,
    VfxU16 thread_number,
    srv_um_thread_info_struct *thread_info[],
    srv_um_msg_info_struct *msg_info[])
{
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    VfxS32 result;

    srv_um_box_identity_struct msg_box = {SRV_UM_MSG_ALL, SRV_UM_MSG_BOX_ALL, SRV_UM_SIM_ALL};

    result = srv_um_check_thread_info(msg_box, thread_list, list_info_size, start_entry, thread_number, thread_info, msg_info);

    VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETTHREADINFO, (VfxS32) this, result);

    if (result == SRV_UM_RESULT_OK)
    {
        return SRV_UM_RESULT_OK;
    }
    else if (!m_isAuto)
    {
        return result;
    }

    if (m_PID > 0)
    {
        return SRV_UM_RESULT_TOO_MANY_THREAD;
    }

    // get lot of message together to enhance performance
    if (list_info_size - start_entry < 8)
    {
        thread_number = list_info_size - start_entry;
    }
    else if (thread_number < 8)
    {
        thread_number = 8;
    }

    m_PID = srv_um_get_thread_info(msg_box, thread_list + start_entry, thread_number, Self::getThreadInfoCb, (S32)getObjHandle());

    VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_PID, m_PID);

    return SRV_UM_RESULT_PROCESS_BUSY;
#else
    return SRV_UM_RESULT_NOT_SUPPORT;
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
}


#ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
/* return NULL for unfinished request*/
const VfxWChar* VappMsgDataProvider::getMsgContent(srv_um_msg_node_struct *msgNode)
{
    VappMsgWidgetExtInfo *msgExtInfoUnit = getMsgExtInfoNode(msgNode);
    if (NULL != msgExtInfoUnit)
    {
        return msgExtInfoUnit->getMsgContent();
    }
    else
    {
        return NULL;
    }
};
/* return NULL for unfinished request*/
const VappMsgWidgetExtInfoThumbnailResult VappMsgDataProvider::getMsgThumbnail(srv_um_msg_node_struct *msgNode, void**thunmbnailPointer)
{
    VappMsgWidgetExtInfo *msgExtInfoUnit = getMsgExtInfoNode(msgNode);
    if (NULL != msgExtInfoUnit)
    {
        return msgExtInfoUnit->getMsgThumbnail(thunmbnailPointer);
    }
    else
    {
        return VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_PROCESSING;
    }
};

/* return NULL for unfinished request*/
const VappMsgReadStatus* VappMsgDataProvider::getMsgReadStatus(srv_um_msg_node_struct *msgNode)
{
    VappMsgWidgetExtInfo *msgExtInfoUnit = getMsgExtInfoNode(msgNode);
    if (NULL != msgExtInfoUnit)
    {
        return msgExtInfoUnit->getMsgReadStatus();
    }
    else
    {
        return NULL;
    }
};

void VappMsgDataProvider::onGetMsgExtInfoFinished(VappMsgWidgetExtInfo *finishedUnit)
{
    m_signalExtInfoUpdated.postEmit();
}

void VappMsgDataProvider::onMsgExtInfoDestroyed(VappMsgWidgetExtInfo *destroyedUnit)
{
    /* move cached one to end */
    VfxS32 i = 0;
    
    destroyedUnit->m_signalGetExtInfoFinished.disconnect(this, &VappMsgDataProvider::onGetMsgExtInfoFinished);
    destroyedUnit->m_signalGetExtDestroyed.disconnect(this, &VappMsgDataProvider::onMsgExtInfoDestroyed);
    /* find its position */
    for (; i< mMsgWidgetCounter; ++i)
    {
        if ((mMsgWidgetExtInfoQueue[i] == destroyedUnit))
        {
            break;
        }
    }
    /* move following ones to front */
    for (; i < mMsgWidgetCounter - 1; ++i) 
    {
        mMsgWidgetExtInfoQueue[i] = mMsgWidgetExtInfoQueue[i + 1];
    }
    /* reset as last */
    mMsgWidgetExtInfoQueue[i] = NULL;
	--mMsgWidgetCounter;
    if (!m_isInDeinit)
    {
        m_signalExtInfoUpdated.postEmit();
    }
}

VappMsgWidgetExtInfo *VappMsgDataProvider::getMsgExtInfoNode(srv_um_msg_node_struct *msg_node)
{
    VappMsgWidgetExtInfo * msgNode;
	
    // pending filter //for wap push
    if (VappMsgWidgetExtInfo::isPendingProcessConflict(msg_node->msg_type))
    {   
        return NULL;
    }

    /* query cached */
    msgNode = getMsgExtInfoNodeCache(msg_node);
    /* create a new one */
    if (NULL == msgNode)
    {
        if (isMsgExtPoolFull())
        {
            /*if it is full, try to remove oldest one */
            if (mMsgWidgetExtInfoQueue[0]->isDestroyable())
            {
                VappMsgWidgetExtInfo * msgNodeTemp = mMsgWidgetExtInfoQueue[0];
                /* will invoke signal, and cause the unit removed from Q */
                VFX_OBJ_CLOSE(msgNodeTemp);
            }
        }
		            
        /* create a new one if there is room for it */
        if (!isMsgExtPoolFull())
        {
            VFX_OBJ_CREATE_EX(mMsgWidgetExtInfoQueue[mMsgWidgetCounter], \
                VappMsgWidgetExtInfo, \
                this, \
                (msg_node->msg_id, msg_node->msg_type));
            msgNode =  mMsgWidgetExtInfoQueue[mMsgWidgetCounter];
            msgNode->m_signalGetExtInfoFinished.connect(this, &VappMsgDataProvider::onGetMsgExtInfoFinished);
            msgNode->m_signalGetExtDestroyed.connect(this, &VappMsgDataProvider::onMsgExtInfoDestroyed);
            ++mMsgWidgetCounter;
        }
    }
    else
    {
        /* move cached one to end */
        VfxS32 i = 0;
        VappMsgWidgetExtInfo * cachedOne = msgNode;
        /* find its position */
        for (; i< mMsgWidgetCounter; ++i)
        {
            if ((mMsgWidgetExtInfoQueue[i] == cachedOne))
            {
                break;
            }
        }
        /* move following ones to front */
        for (; i < mMsgWidgetCounter - 1; ++i) 
        {
            mMsgWidgetExtInfoQueue[i] = mMsgWidgetExtInfoQueue[i + 1];
        }
        /* add as last */
        mMsgWidgetExtInfoQueue[i] = cachedOne;
    }
    
    return msgNode;
};

/* query cached */
VappMsgWidgetExtInfo *VappMsgDataProvider::getMsgExtInfoNodeCache(srv_um_msg_node_struct *msgNode)
{
    VfxS32 i = 0;
    VappMsgWidgetExtInfo * cachedOne = NULL;
    srv_um_msg_enum msg_type = msgNode->msg_type;                   /* message type */
    U32 msg_id = msgNode->msg_id;                                 /* message id */
    for (; i< mMsgWidgetCounter; ++i)
    {
        if ((mMsgWidgetExtInfoQueue[i]->getMsgID() == msg_id) &&
            (mMsgWidgetExtInfoQueue[i]->getMsgType() == msg_type))
        {
            cachedOne =  mMsgWidgetExtInfoQueue[i];
            break;
        }
    }
    return cachedOne;
}

/* cache pool full */
VfxBool VappMsgDataProvider::isMsgExtPoolFull()
{
    return !(mMsgWidgetCounter < VAPP_MSG_WIDGET_EXT_INFO_NUM);
}

#endif /*  __MMI_VUI_WIDGET_KEY_MESSAGE__ */

VfxS32 VappMsgDataProvider::markSeveralOp(
    srv_um_box_identity_struct msg_box, 
    srv_um_msg_node_struct msg_list [ ], 
    U16 msg_list_size, 
    U32 mark_status [ ], 
    srv_um_mark_several_op_action_enum action_type)
{
    if (m_PID > 0)
    {
        return SRV_UM_RESULT_TOO_MANY_THREAD;
    }

    if (!m_isAuto)
    {
        return SRV_UM_RESULT_DATA_NOT_FOUND;
    }

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    m_PID = srv_um_mark_several_op(
                    msg_box, 
                    msg_list, 
                    msg_list_size, 
                    mark_status, 
                    action_type, 
                    Self::markSeveralOpCb, 
                    (S32)getObjHandle());

    return SRV_UM_RESULT_PROCESS_BUSY;
#else /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
    return SRV_UM_RESULT_NOT_SUPPORT;
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
}

VfxS32 VappMsgDataProvider::markSeveralThreadOp(
    srv_um_box_identity_struct msg_box, 
    srv_um_thread_id_struct thread_list [ ], 
    U16 thread_list_size, 
    U32 mark_status [ ], 
    srv_um_mark_several_op_action_enum action_type)
{
    if (m_PID > 0)
    {
        return SRV_UM_RESULT_TOO_MANY_THREAD;
    }

    if (!m_isAuto)
    {
        return SRV_UM_RESULT_DATA_NOT_FOUND;
    }

#if defined(__UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__) && defined(__SRV_UM_THREAD_MESSAGE_SUPPORT__)
    m_PID = srv_um_mark_several_thread_op(
                    msg_box, 
                    thread_list, 
                    thread_list_size, 
                    mark_status, 
                    action_type, 
                    Self::markSeveralThreadOpCb, 
                    (S32)getObjHandle());

    return SRV_UM_RESULT_PROCESS_BUSY;
#else /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ && __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
    return SRV_UM_RESULT_NOT_SUPPORT;
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ && __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
}

VfxS32 VappMsgDataProvider::cancelProcess(void)
{
    if (m_PID > 0)
    {
        VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_CANCELPROCESS, (VfxS32) this, m_PID);

        srv_um_cancel_request(m_PID);
    }

    return SRV_UM_RESULT_OK;
}

VfxS32 VappMsgDataProvider::getProcessProgress(VfxS32 & finishNum, VfxS32 & totalNum)
{
    if (m_PID > 0)
    {
        return srv_um_get_request_progress(
                    m_PID, 
                    &finishNum, 
                    &totalNum);
    }

    return SRV_UM_RESULT_INVALID_PID;
}

// -------------------------------------------------------------
// Callback Function for Um Service
// -------------------------------------------------------------

VfxS32 VappMsgDataProvider::getMsgNumCb(VfxS32 pid, srv_um_get_msg_num_result* rsp, VfxS32 userData)
{
    VappMsgDataProvider *my_provider =  (VappMsgDataProvider *)  VfxObject::handleToObject((VfxObjHandle*)userData);

    if (my_provider && my_provider->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgDataProvider)) && pid == my_provider->m_PID)
    {
        VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETMSGNUMCB, 1, userData, pid);

        my_provider->m_signalGetMsgNumFinished.postEmit(*rsp);
        my_provider->m_PID = 0;
    }
    else
    {
        VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETMSGNUMCB, 0, userData, pid);
    }

    return 0;
}

VfxS32 VappMsgDataProvider::getMsgListCb(VfxS32 pid, srv_um_get_msg_list_result* rsp, VfxS32 userData)
{
    VappMsgDataProvider *my_provider =  (VappMsgDataProvider *) VfxObject::handleToObject((VfxObjHandle*)userData);

    if (my_provider && my_provider->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgDataProvider)) && pid == my_provider->m_PID)
    {
        VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETMSGLISTCB, 1, userData, pid);

        my_provider->m_signalGetMsgListFinished.postEmit(*rsp);
        my_provider->m_PID = 0;
    }
    else
    {
        VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETMSGLISTCB, 0, userData, pid);
    }

    return 0;
}



VfxS32 VappMsgDataProvider::getMsgInfoCb(VfxS32 pid, srv_um_get_msg_info_result* rsp, VfxS32 userData)
{
    VappMsgDataProvider *my_provider =  (VappMsgDataProvider *) VfxObject::handleToObject((VfxObjHandle*)userData);

    if (my_provider && my_provider->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgDataProvider)) && pid == my_provider->m_PID)
    {
        VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETMSGINFOCB, 1, userData, pid);

        my_provider->m_signalGetMsgInfoFinished.postEmit(*rsp);
        my_provider->m_PID = 0;
    }
    else
    {
        VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETMSGINFOCB, 0, userData, pid);
    }

    return 0;
}

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
VfxS32 VappMsgDataProvider::getThreadListCb(VfxS32 pid, srv_um_get_thread_list_result* rsp, VfxS32 userData)
{
    VappMsgDataProvider *my_provider =  (VappMsgDataProvider *) VfxObject::handleToObject((VfxObjHandle*)userData);

    if (my_provider && my_provider->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgDataProvider)) && pid == my_provider->m_PID)
    {
        VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETTHREADLISTCB, 1, userData, pid);

        my_provider->m_signalGetThreadListFinished.postEmit(*rsp);
        my_provider->m_PID = 0;
    }
    else
    {
        VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETTHREADLISTCB, 0, userData, pid);
    }
    return 0;
}

VfxS32 VappMsgDataProvider::getThreadInfoCb(VfxS32 pid, srv_um_get_thread_info_result* rsp, VfxS32 userData)
{
    VappMsgDataProvider *my_provider =  (VappMsgDataProvider *) VfxObject::handleToObject((VfxObjHandle*)userData);

    if (my_provider && my_provider->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgDataProvider)) && pid == my_provider->m_PID)
    {
        VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETTHREADINFOCB, 1, userData, pid);

        my_provider->m_signalGetThreadInfoFinished.postEmit(*rsp);
        my_provider->m_PID = 0;
    }
    else
    {
        VFX_LOG(VFX_FUNC, VAPP_MSGDATAPROVIDER_GETTHREADINFOCB, 0, userData, pid);
    }
    return 0;
}
#endif

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
VfxS32 VappMsgDataProvider::markSeveralOpCb(VfxS32 pid, srv_um_mark_several_op_result* rsp, VfxS32 userData)
{
    VappMsgDataProvider *my_provider =  (VappMsgDataProvider *) VfxObject::handleToObject((VfxObjHandle*)userData);

    if (my_provider && my_provider->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgDataProvider)) && pid == my_provider->m_PID)
    {
        my_provider->m_signalMarkSeveralOpFinished.postEmit(*rsp);
        my_provider->m_PID = 0;
    }
    else
    {
    }
    return 0;
}

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
VfxS32 VappMsgDataProvider::markSeveralThreadOpCb(VfxS32 pid, srv_um_mark_several_thread_op_result* rsp, VfxS32 userData)
{
    VappMsgDataProvider *my_provider =  (VappMsgDataProvider *) VfxObject::handleToObject((VfxObjHandle*)userData);

    if (my_provider && my_provider->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgDataProvider)) && pid == my_provider->m_PID)
    {
        my_provider->m_signalMarkSeveralThreadOpFinished.postEmit(*rsp);
        my_provider->m_PID = 0;
    }
    else
    {
    }
    return 0;
}
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */

/*****************************************************************************
 * Class VappBaseList
 *****************************************************************************/

//VFX_IMPLEMENT_CLASS("VappBaseList", VappBaseList, VfxObject);
VFX_IMPLEMENT_VIRTUAL_CLASS("VappBaseList", VappBaseList, VfxObject);

VappBaseList::VappBaseList()
{
    m_msgDataProvider = NULL;

    m_msgBox.msg_box_type = SRV_UM_MSG_BOX_INBOX;
    m_msgBox.msg_type = SRV_UM_MSG_SMS;
    m_msgBox.sim_id = SRV_UM_SIM_ALL;

    memset(&m_filter, 0, sizeof(m_filter));

    m_listCntx = NULL;

    m_listCntxID = 0;

    m_isModified = VFX_TRUE;

    m_isUpdating = VFX_FALSE;

}

void VappBaseList::onInit()
{

    VFX_LOG(VFX_FUNC, VAPP_BASELIST_ONINIT, (VfxS32)this);

    Super::onInit();

    VFX_OBJ_CREATE(m_msgDataProvider, VappMsgDataProvider, this);
}

void VappBaseList::onDeinit()
{
    VFX_LOG(VFX_FUNC, VAPP_BASELIST_ONDEINIT, (VfxS32)this);

    release(VFX_TRUE);

    VFX_OBJ_CLOSE(m_msgDataProvider);

    Super::onDeinit();
}

// -------------------------------------------------------------
// Property set/get
// -------------------------------------------------------------

void VappBaseList::setMsgBoxInfo(srv_um_msg_enum msg_type,srv_um_msg_box_enum msg_box_type)
{
    if (m_msgBox.msg_type != msg_type ||
        m_msgBox.msg_box_type != msg_box_type)
    {
        m_msgBox.msg_type = msg_type;
        m_msgBox.msg_box_type = msg_box_type;
        m_isModified = VFX_TRUE;
    }
}

srv_um_box_identity_struct VappBaseList::getMsgBoxInfo() const
{
    return m_msgBox;
}

void VappBaseList::setSortBy(srv_um_list_idx_enum idx_type, srv_um_sort_order_enum order)
{
    if (m_filter.idx_type != idx_type ||
        m_filter.order != order)
    {
        m_filter.idx_type = idx_type;
        m_filter.order = order;
        m_isModified = VFX_TRUE;
    }
}

srv_um_list_filter_struct VappBaseList::getFilter() const
{
    return m_filter;
}

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
void VappBaseList::setThreadID(srv_um_thread_id_struct thread_id)
{
    if (m_filter.thread_id.type != thread_id.type ||
        m_filter.thread_id.value != thread_id.value)
    {
        m_filter.thread_id = thread_id;
        m_isModified = VFX_TRUE;
    }
}

void VappBaseList::setThreadIDbyAddress(srv_um_addr_enum type, VfxWString &addressMap)
{
    srv_um_thread_id_struct tmp;
    srv_um_tsfr_address_to_thread_id(type, (U16*)addressMap.getBuf(), SRV_UM_SIM_UNCLASSIFIED, &tmp);

    if (m_filter.thread_id.type != tmp.type ||
        m_filter.thread_id.value != tmp.value)
    {
        m_filter.thread_id.type = tmp.type;
        m_filter.thread_id.value = tmp.value;
        m_isModified = VFX_TRUE;
    }
}

srv_um_thread_id_struct VappBaseList::getThreadID() const
{
    return m_filter.thread_id;
}
#endif

VfxS32 VappBaseList::getListSize() const
{
    return m_listCntx? m_listCntx->msg_number:0;
}


VfxBool VappBaseList::isOutOfDate() const
{
    return m_isModified;
}

void *VappBaseList::getList() const
{
    return m_listCntx? m_listCntx->list:NULL;
}

VfxBool VappBaseList::isUpdating() const
{
    return m_isUpdating;
}


// -------------------------------------------------------------
// Method
// -------------------------------------------------------------

// Derived class may override this function.
void VappBaseList::release(VfxBool fullRelease)
{
    if (m_listCntx)
    {
        VFX_LOG(VFX_FUNC, VAPP_BASELIST_RELEASE, (VfxS32)this, m_listCntxID, fullRelease);

        srv_um_release_list(m_listCntxID, (MMI_BOOL)fullRelease);
        m_listCntxID = 0;
        m_listCntx = NULL;
        m_isModified = VFX_TRUE;

        // the list is released , notify every user that the message is released
        m_signalListReleased.emit();
    }
    else if (m_isUpdating)
    {
        m_msgDataProvider->cancelProcess();
    }
}

// -------------------------------------------------------------
// Event HAndler
// -------------------------------------------------------------


void VappBaseList::listMgrNotifyCB(VfxS32 event, VfxS32 list_cid, VfxS32 user_data)
{
    VappBaseList *myList = (VappBaseList *)VfxObject::handleToObject((VfxObjHandle*)user_data);

    if (myList && myList->isKindOf(VFX_OBJ_CLASS_INFO(VappBaseList)))
    {
        VFX_LOG(VFX_FUNC, VAPP_BASELIST_LISTMGRNOTIFYCB, 1, event, list_cid, user_data);

        myList->onListMgrNotify(event, list_cid);
    }
    else
    {
        VFX_LOG(VFX_FUNC, VAPP_BASELIST_LISTMGRNOTIFYCB, 0, event, list_cid, user_data);

        VFX_ASSERT(0);
    }
}

// Derived class may override this function.
void VappBaseList::onListMgrNotify(VfxS32 event, VfxS32 list_cid)
{
    if (list_cid != m_listCntxID)
    {
        VFX_ASSERT(0);
    }

    VFX_LOG(VFX_FUNC, VAPP_BASELIST_ONLISTMGRNOTIFY, (VfxS32)this, event, list_cid);

    if (event == SRV_UM_NOTIFY_LIST_RELEASED_IND)
    {
        VFX_ASSERT(m_isUpdating == VFX_FALSE);

        m_listCntx = NULL;
        m_listCntxID = 0;
        m_isModified = VFX_TRUE;
        m_isUpdating = VFX_FALSE;
        m_signalListReleased.emit();
    }
    else
    {
        VFX_ASSERT(0);
    }
}

/*****************************************************************************
 * Class VappMsgList
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMsgList", VappMsgList, VappBaseList);

void VappMsgList::onInit()
{
    Super::onInit();
}

// -------------------------------------------------------------
// Property set/get
// -------------------------------------------------------------

srv_um_msg_node_struct *VappMsgList::getMsgList() const
{
    return m_listCntx? (srv_um_msg_node_struct *)(m_listCntx->list):NULL;
}

// -------------------------------------------------------------
// Method
// -------------------------------------------------------------

void VappMsgList::forceUpdate()
{
    VFX_LOG(VFX_FUNC, VAPP_MSGLIST_FORCEUPDATE, (VfxS32)this, m_isUpdating, m_isModified);

    if (m_listCntx)
    {
        release(VFX_TRUE);
    }

    if (!srv_um_check_ready_type(m_msgBox.msg_type))
    {
        m_isUpdating = VFX_FALSE;
        m_signalListUpdated.emit();
        return;
    }

    m_isModified = VFX_FALSE;

    m_msgDataProvider->m_signalGetMsgListFinished.connect(this, &Self::onGetMsgListFinished);

    VfxS32 result = m_msgDataProvider->getMsgList(m_msgBox, m_filter, &Self::listMgrNotifyCB, (VfxS32)getObjHandle(), m_listCntx);

    if (result > SRV_UM_RESULT_OK)
    {
        // we get the data synchonize
        m_isUpdating = VFX_FALSE;
        m_signalListUpdated.emit();
        m_listCntxID = result;
    }
    else if (result == SRV_UM_RESULT_PROCESS_BUSY)
    {
        m_signalListUpdating.emit();
    }
    else
    {
        VFX_ASSERT(0);
        // some error
        m_isUpdating = VFX_FALSE;
    }
}

void VappMsgList::update()
{
    // create a clear environment to do upate
    // sometimes AP update the list in the emit function
    // In this case, the data provider may thread full
    // and message list will auto update in onGetMsgListFinished too

    VFX_LOG(VFX_FUNC, VAPP_MSGLIST_UPDATE, (VfxS32) this);

    if (!m_isUpdating)
    {
        m_isUpdating = VFX_TRUE;

        vfxPostInvoke0(this, &VappMsgList::forceUpdate);
    }
    // the criteria is modified during processing, cancel the cureent process first and wait for the callback
    else if(m_isModified)
    {
        m_msgDataProvider->cancelProcess();
    }
}

// -------------------------------------------------------------
// Event Handler
// -------------------------------------------------------------

void VappMsgList::onGetMsgListFinished(srv_um_get_msg_list_result result)
{
    VFX_ASSERT(m_isUpdating == VFX_TRUE);

    m_isUpdating = VFX_FALSE;

    VFX_LOG(VFX_FUNC, VAPP_MSGLIST_ONGETMSGLISTFINISHED, (VfxS32) this, m_isModified, result.error);

    // if the data is modified during this time, get the data again
    if (m_isModified)
    {
        update();
        return;
    }

    if (result.error == SRV_UM_RESULT_OK)
    {
        update();
    }
    else
    {
        // let the message list out of date
        m_isModified = VFX_TRUE;
        // some error, we cannot get the list now.
        m_signalListUpdated.emit();
    }

}

