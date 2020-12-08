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
 * VappMmsAppDataManager.h
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
 * 
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef VAPP_MMS_DATA_MGR_H
#define VAPP_MMS_DATA_MGR_H
#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__

#define         MMI_UMMS_MAX_URL_LENGTH           WAP_MAX_URL_LENGTH

extern "C"
{
	#include "MmsSrvGprot.h"
}

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mma_struct.h"
#include "MmsXMLDefSrv.h"
#include "custom_mmi_default_value.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_timer.h"
#include "app_usedetails.h"



typedef struct
{
    U8 result;
    U8 media_type;
    kal_uint8 from_address_type;
    kal_uint8 msg_class;
    kal_uint8 priority;
    /* kal_uint8 msg_status; */
    kal_uint32 msg_size;
    kal_uint32 date;
    kal_uint32 receive_date;
    kal_uint32 expiry_time;
    kal_bool isRead;
    kal_bool need_read_report;
#ifdef  __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
    kal_bool need_delivery_report;
#endif
    kal_bool isForwardLock;
    kal_bool isDRM;
    kal_bool isFollowPhoneMMSContentClass;
    kal_bool hasAttachment;
    kal_uint8 msg_type;
    kal_uint8 msg_sim_info;
    kal_wchar from_address[MMA_MAX_ADDR_LEN];
    kal_wchar subject[MMA_MAX_SUBJECT_LEN];
    kal_uint8 lock_mode;
    kal_uint8 notification_error_type;
    kal_uint8 from_folder;
    kal_uint8 storage_location; /*  0 for phone 1 for card */
    kal_wchar app_id[SRV_MMS_MAX_COMM_STRING_LENGTH];
    kal_wchar reply_app_id[SRV_MMS_MAX_COMM_STRING_LENGTH];
#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    kal_uint32 user_element_size;
#endif 
} mmi_umms_app_dtmgr_msg_info_data_struct;

typedef struct
{
    srv_mms_addr_struct *to_head;
    srv_mms_addr_struct *cc_head;
    srv_mms_addr_struct *bcc_head;
    srv_mms_addr_struct *from;
    srv_mms_viewer_slide_struct *slide_head;
    srv_mms_viewer_slide_struct *current_slide;
    srv_mms_viewer_object_struct **object_head;
    srv_mms_viewer_attachment_info_struct *attachment_head;
    U32 background_color;
    U32 foreground_color;
    U32 date;
    U32 msgsize;
    U32 download_size;
    U32 reported_msg_id;
    U32 delivery_time;  /* mma_delivery_time_enum + java uses it for time in secs */
    U8 java_app_id[100 *ENCODING_LENGTH];
    U8 java_reply_app_id[100 *ENCODING_LENGTH];

    U16 subject[SRV_MMS_XML_MAX_SUBJECT_LEN+ 1];
    U16 reported_subject[SRV_MMS_XML_MAX_SUBJECT_LEN + 1];
    U16 slide_timing;
    U16 email_num;
    U16 ph_num;
    U8 mms_version[SRV_MMS_VERSION_LEN];
    U8 to_num;
    U8 cc_num;
    U8 bcc_num;
    U8 priority;    /* mma_priority_enum */
    U8 expiry_time; /* mma_expiry_time_enum */
    U8 msgStatus;   /* mma_msg_status_enum */
    U8 msgclass;    /* mma_msg_class_enum */
    U8 total_slide_num;
    U8 current_slide_num;
    U8 total_object_num;
    U8 total_attachment_num;
    U8 total_addresses;
    U8 status;
    BOOL sender_visibility;
    BOOL read_report;
    BOOL delivery_report;
    /* mma_slide_layout_enum */ U8 layout;
} mmi_umms_app_dtmgr_xml_header_info_struct;

typedef struct
{
    srv_mms_viewer_xml_msg_struct *msg_cntx;
    PU8 slide_txt_buffer;   /* final buffer with UCS2 encoding */
    PU8 src_buffer;         /* buffer with source encoding */
    PU8 inputbox_buffer;
    U32 ptxtbuffersize;

} mmi_umms_app_dtmgr_viewer_cateory_info_data;

typedef struct
{
    U16 *xml_file_path;
    U16 shown_slide_num;
    mmi_umms_app_dtmgr_viewer_cateory_info_data *cat_info;
    srv_mms_viewer_use_details_list *list_head;
} mmi_umms_app_dtmgr_viewer_info_data;

typedef enum
{
	MMS_SEND_RR_FALSE,
	MMS_SEND_RR_TRUE,
	MMS_SEND_RR_ERROR,
}MmsRRResultTypeEnum;

class VappMmsViewerData :public VfxObject
{
	VFX_DECLARE_CLASS(VappMmsViewerData);

//declaration
public:
	enum modeView
	{
		MODE_NONE,
		MODE_LIGHT,
		MODE_FULL,
		MODE_TOTAL,
	};
//signals
public:
	VfxSignal2 <srv_mms_viewer_result_enum, VfxS32> m_signalMmsViewerServiceDone;
	VfxSignal1 <srv_mms_viewer_result_enum> m_signalMmsViewerUseDetailsDone;

//method
public:
	mmi_umms_app_dtmgr_msg_info_data_struct *getMsgInfo(void);
	mmi_umms_app_dtmgr_xml_header_info_struct *getHeaderInfo(void);
	mmi_umms_app_dtmgr_viewer_info_data *getViewerInfo(void);
	srv_mms_viewer_use_details_list *getUseDetailsListHead(void);
	VfxBool checkDataReady(void);
	VfxBool getDataReady(void);
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
	
	VfxBool checkUseDetailsDataReady(void);
	VfxBool getUseDetailsDataReady(void);
#endif	
	VfxBool getviewerHeaderMsgInfo(void);
	VfxBool checkMsgInfoDataReady(void);
	VfxBool checkViewerDataReady(void);
	VfxBool getViewerContentReady(void);
	VfxU32 getMyIndex(void);
	VfxU32 getMsgId(void);
	void setBasicProp(VfxU32 msg_id, VfxBool is_preview = VFX_FALSE, VfxU32 srv_index = 0);
	MmsRRResultTypeEnum decideReadReport(void);
	MmsRRResultTypeEnum MmsHandleReadReport(VfxBool send);
	void MmsSendReadReport(void);
	void MmsAbortSendReadReport(U32);
	VfxBool getIsPreview(void);
	void resendOnExit(VfxBool resend_on_exit );
	static void *allocMem(U32 size,void *user_data);
	static void freeMem(void *mem);

//contructor

public:
		VappMmsViewerData(VfxU32 msg_id_x, VfxBool is_preview_x, VfxU32 index = 0):m_state(MMI_UMMS_APP_DTMGR_GET_DATA_NONE)
		{
			msg_id = msg_id_x;
			is_preview = is_preview_x;
			m_srv_index = index;
			m_list_head = NULL;
			memset(&m_viewer_info, 0, sizeof(mmi_umms_app_dtmgr_viewer_info_data));
			memset(&m_header_info, 0, sizeof(mmi_umms_app_dtmgr_xml_header_info_struct));
			memset(&m_msg_info, 0, sizeof(mmi_umms_app_dtmgr_msg_info_data_struct));
			m_dataTimer = NULL;
			m_need_rr_viewer = VFX_FALSE;
			m_use_detail_state = MMI_UMMS_APP_DTMGR_GET_DATA_NONE;
			m_mode = MODE_NONE;
			m_resend_on_exit = VFX_FALSE;
			m_shown_slide_num = 0;
		}
		VappMmsViewerData(VfxU32 msg_id_x, VappMmsViewerData::modeView mode):m_state(MMI_UMMS_APP_DTMGR_GET_DATA_NONE)
		{
			msg_id = msg_id_x;
			m_list_head = NULL;
			is_preview = VFX_FALSE;
			m_srv_index = 0;
			memset(&m_viewer_info, 0, sizeof(mmi_umms_app_dtmgr_viewer_info_data));
			memset(&m_header_info, 0, sizeof(mmi_umms_app_dtmgr_xml_header_info_struct));
			memset(&m_msg_info, 0, sizeof(mmi_umms_app_dtmgr_msg_info_data_struct));
			m_dataTimer = NULL;
			m_need_rr_viewer = VFX_FALSE;
			m_use_detail_state = MMI_UMMS_APP_DTMGR_GET_DATA_NONE;
			m_mode = mode;
			m_resend_on_exit = VFX_FALSE;
			m_shown_slide_num = 0;
		}
		VappMmsViewerData():m_state(MMI_UMMS_APP_DTMGR_GET_DATA_NONE),m_use_detail_state(MMI_UMMS_APP_DTMGR_GET_DATA_NONE), m_srv_index(0),m_list_head(NULL), m_mode(MODE_NONE), m_resend_on_exit(VFX_FALSE)
		{
		}

//override

//method
protected:
	virtual void onDeinit(void);
//implementation

//method
private:
	void viewerDataReadyCb(srv_mms_result_enum result, void *msgrsp);
	void viewerUseDetailsReadyCb(srv_mms_result_enum result, void *msgrsp);
	void onMmsTimerExpiry(VfxTimer *timer);
	void onMmsUseDetailsTimerExpiry(VfxTimer *timer);
	void MmsSetReadmark(VfxBool read);
	void getAsmPoolInit(void);
	void resendMMS(void );
	static void viewerDataReadyCbRspHldr(srv_mms_result_enum result, void *msgrsp, void *user_data);
	
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
	static void viewerUseDetailsReadyCbRspHldr(srv_mms_result_enum result, void *msgrsp, void *user_data);
#endif
	static void viewerAsmStopCb(void *user_data);
	static void appAsmStopCb(void *user_data);
	
//variables
	private:
	typedef enum
	{
		MMI_UMMS_APP_DTMGR_GET_DATA_NONE,
		MMI_UMMS_APP_DTMGR_GET_CONTENT_INFO_WAIT,
		MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT,
		MMI_UMMS_APP_DTMGR_MSG_PARSE_DATA_WAIT,
		MMI_UMMS_APP_DTMGR_MSG_PARSE_DRM_WAIT,
		MMI_UMMS_APP_DTMGR_MSG_DATA_READY,
		MMI_UMMS_APP_DTMGR_USE_DETAIL_START,
		MMI_UMMS_APP_DTMGR_USE_DETAIL_NUMBER,
		MMI_UMMS_APP_DTMGR_USE_DETAIL_EMAIL,
		MMI_UMMS_APP_DTMGR_USE_DETAIL_URL,
		MMI_UMMS_APP_DTMGR_USE_DETAIL_SORT,
		MMI_UMMS_APP_DTMGR_TOTAL
	} mmi_umms_app_dtmgr_state_enum;
	mmi_umms_app_dtmgr_state_enum m_state;
	mmi_umms_app_dtmgr_state_enum m_use_detail_state;
	VfxU32 msg_id;
	VfxU32 m_srv_index;
	VfxU32 m_shown_slide_num;
	VfxU32 m_req_slide_num;
	VfxBool is_preview;
	mmi_umms_app_dtmgr_msg_info_data_struct m_msg_info;
	mmi_umms_app_dtmgr_xml_header_info_struct m_header_info;
	mmi_umms_app_dtmgr_viewer_info_data m_viewer_info;	
	srv_mms_viewer_use_details_list *m_list_head;
	VfxTimer *m_dataTimer;
	VfxBool m_need_rr_viewer;
	modeView m_mode;
	VfxBool m_resend_on_exit;

};
typedef struct
{
    U8 applib_addr_type;
    S8 *hilited_data;
    S32 hilite_index;
    srv_mms_get_use_details_rsp_struct get_use_details_rsp;
    srv_mms_get_use_details_enum mms_umms_app_slide;
} mmi_umms_app_dtmgr_use_details_struct;

#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__

class VappMmsUseDetails :public VfxObject
{
	VFX_DECLARE_CLASS(VappMmsUseDetails);

//declaration
public:
	VfxBool getUseDetailsFromSrv(void);
	VfxU32 getUseDetailsCount(void);
	applib_address_node_struct *getUseDetailsNode(VfxU32 index);

//constructor
public:
	VappMmsUseDetails(VfxU32 index = 0)
	{
		m_srv_index = index;
	}

//implementation

//variables
private:
	mmi_umms_app_dtmgr_use_details_struct m_data;
	VfxU32 m_srv_index;
	
};
#endif	

#ifdef __DRM_SUPPORT__

namespace VappMmsDrmHandler
{
	VfxBool checkRightsById(srv_mms_viewer_object_info_struct *obj, VfxU32 index);
	VfxBool startConsumeRights(srv_mms_viewer_object_info_struct *obj, VfxU16 *file_path, srv_mms_rights_expiry_notify_cb expiry_func, void *user_data, VfxU32 index);
	void stopConsumeRights(srv_mms_viewer_object_info_struct *obj, VfxU32 index);
	void updateRightsById(srv_mms_viewer_object_info_struct *obj, VfxBool rightsExpired, VfxU32 index);	
};

#endif
#endif /* __MMI_MMS_2__ */ 
#endif /* VAPP_MMS_DATA_MGR_H */ 

