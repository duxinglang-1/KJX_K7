#ifndef _VAPP_UC_PROT_H
#define _VAPP_UC_PROT_H

#include "MMI_features.h"
#include "vapp_msg_features.h"

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "..\Contact\ContactCore\vapp_contact_list.h"
#include "vapp_uc_contactlist.h"
#ifdef __MMI_EMAIL__
#include "customer_email_num.h"
#include "..\Email\vapp_email_composer.h"
#endif
#include "Vadp_asm.h"

extern "C"
{
    #include "Custom_uc_config.h"
//	#include "vappucappgprot.h"
    #include "SmsSrvGprot.h"
	#include "UcSrvGprot.h"
    #include "UcSrvIprot.h"
    #include "MmsSrvGprot.h"
    #include "vapp_uc_gprot.h"
//	#include "vappucappprot.h"
	#include "mmi_rp_vapp_unifiedcomposer_def.h"
    #include "mmi_rp_srv_mms_def.h"

typedef void (*vmsgc_resize_func_ptr) (mma_insert_type_enum, U8 *, U16 *);
typedef void (*vmsgc_confirm_func_ptr) (VfxBool, void *);
/* Max characters allowed in the text buffer to start UC in SMS only mode. */
#define UC_MAX_SMS_CONTENT 670
#define UC_MAX_RESIZE_ATTEMPTS 4
#define UC_ADM_MEM_SIZE ((WAP_CUSTOM_CFG_MAX_MMS_SLIDES * MMI_UC_CUSTOM_MAX_FILE_PATH_LEN * 2 * 2) + \
                                (WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT * MMI_UC_CUSTOM_MAX_FILE_PATH_LEN * 2) + \
                                (WAP_CUSTOM_CFG_MAX_MMS_ADDRESS * MMI_UC_CUSTOM_MAX_ADDR_LEN * 2) + \
                                (5 * 1024) + SRV_UC_UTF8_TEXT_BUFFER_SIZE)
#ifdef __MMI_EMAIL__
#define UC_EMAIL_MAX_TEXT_CHAR_COUNT (MMI_EMAIL_MAX_CONT_LEN_BY_K * 1024)
#endif
#define UC_MMS_MAX_TEXT_CHAR_COUNT (GUI_INPUT_BOX_MAX_LENGTH)

#ifdef __MMI_EMAIL__
#if WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT < MMI_EMAIL_MAX_ATTACH_NUMBER
#define UC_MAX_ATTACHMENT_POSSIBLE MMI_EMAIL_MAX_ATTACH_NUMBER
#else
#define UC_MAX_ATTACHMENT_POSSIBLE WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT
#endif
#else
#define UC_MAX_ATTACHMENT_POSSIBLE WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT
#endif

#define UC_MAX_SIZE_STRING 40

#if defined(__LOW_COST_SUPPORT_COMMON__)
    #define __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
#endif

#if !defined(__MMI_COSMOS_UC_VIDEO_SLIM_SUPPORT__)    
    #define __MMI_COSMOS_UC_VIDEO_PREVIEW_SUPPORT__
    #define __MMI_COSMOS_UC_GALLERY_VIDEO_PICKER_SUPPORT__
    #define __MMI_COSMOS_UC_MMS_PREVIEW_SUPPORT__
#endif

#ifndef __MMI_MESSAGE_SLIM__
    #define __MMI_COSMOS_UC_CC_BCC_SUPPORT__
#endif

#define __MMI_COSMOS_UC_INSERT_PHONE_NAME_ADD_SUPPORT__



#if defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)		
#define UC_EMOTICON_ICON_COUNT 20
static VcpIconTable textIconTable[UC_EMOTICON_ICON_COUNT] =
{
    {IMG_ID_VAPP_UC_EMOTIC_1_ID, (const VfxWChar *)L":-D"},
    {IMG_ID_VAPP_UC_EMOTIC_2_ID, (const VfxWChar *)L":-P"},
    {IMG_ID_VAPP_UC_EMOTIC_3_ID, (const VfxWChar *)L";-)"},
    {IMG_ID_VAPP_UC_EMOTIC_4_ID, (const VfxWChar *)L":-("},
    {IMG_ID_VAPP_UC_EMOTIC_5_ID, (const VfxWChar *)L":-x"},
    {IMG_ID_VAPP_UC_EMOTIC_6_ID, (const VfxWChar *)L":-O"},
    {IMG_ID_VAPP_UC_EMOTIC_7_ID, (const VfxWChar *)L"$_$"},
	{IMG_ID_VAPP_UC_EMOTIC_8_ID, (const VfxWChar *)L"o_o"},
    {IMG_ID_VAPP_UC_EMOTIC_9_ID, (const VfxWChar *)L">_<"},
    {IMG_ID_VAPP_UC_EMOTIC_10_ID, (const VfxWChar *)L"= =b"},
	{IMG_ID_VAPP_UC_EMOTIC_11_ID, (const VfxWChar *)L":-)"},
    {IMG_ID_VAPP_UC_EMOTIC_12_ID, (const VfxWChar *)L"-_-!"},
    {IMG_ID_VAPP_UC_EMOTIC_13_ID, (const VfxWChar *)L"-_-zZ"},
    {IMG_ID_VAPP_UC_EMOTIC_14_ID, (const VfxWChar *)L":-|"},
    {IMG_ID_VAPP_UC_EMOTIC_15_ID, (const VfxWChar *)L"?_?"},
    {IMG_ID_VAPP_UC_EMOTIC_16_ID, (const VfxWChar *)L">3<"},
    {IMG_ID_VAPP_UC_EMOTIC_17_ID, (const VfxWChar *)L"O_o"},
    {IMG_ID_VAPP_UC_EMOTIC_18_ID, (const VfxWChar *)L"T_T"},
    {IMG_ID_VAPP_UC_EMOTIC_19_ID, (const VfxWChar *)L"@_@"},
    {IMG_ID_VAPP_UC_EMOTIC_20_ID, (const VfxWChar *)L":-*"}
};
#endif  /* __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__ */
}

typedef enum
{
    UC_RESULT_FAIL,
    UC_RESULT_OK,
    UC_RESULT_WAIT,
    UC_RESULT_TOTAL
}VappUcResultEnum;

typedef enum
{
    UC_GET_CONTENT_REQ,
    UC_CREATE_REQ,
    UC_DELETE_REQ,
    UC_SEND_REQ,
    UC_SAVE_REQ
}VappUcReqEnum;

typedef enum
{
    UC_PB_CUI_STATE_NONE,
    UC_PB_CUI_STATE_INSERT_ADDRESS,
    UC_PB_CUI_STATE_INSERT_VCARD,
    UC_PB_CUI_STATE_INSERT_PHONE_NUM,
    UC_PB_CUI_STATE_INSERT_PHONE_NAME,
	UC_VCAL_CUI_STATE_INSERT_TASK,
	UC_VCAL_CUI_STATE_INSERT_EVENT,
	UC_PB_CUI_STATE_INSERT_PHONE_NAME_AND_NUM,
	UC_PB_CUI_STATE_TOTAL
}VappUcPbCuiState;




typedef enum
{
    UC_ABORT_NONE,
    UC_ABORT_BY_END_KEY,
    UC_ABORT_NORMAL,

    UC_ABORT_TOTAL_NUM
}VappUcAbortTypeEnum;


typedef enum
{
    UC_MEDIA_OPT_NONE,
    UC_MEDIA_OPT_INSERT,
    UC_MEDIA_OPT_REPLACE,
    UC_MEDIA_OPT_ATTACHMENT_LIST,
    UC_MEDIA_OPT_TOTAL_NUM
}VappUcSelectMediaOptionEnum;

typedef enum
{
    UC_CUI_NONE,
    UC_CUI_MUSIC_PLAYER,
    UC_CUI_VIDEO_PLAYER,
    UC_CUI_IMAGE_VIEWER,
    UC_CUI_SOUND_RECORDER,
    UC_CUI_CAMERA,
    UC_CUI_CAMCORDER,
    UC_CUI_SELECT_BOOKMARK,
    UC_CUI_CAL_LIST,
    UC_CUI_PHB_LIST,
    UC_CUI_GALLERY_IMG_PCKR,
    UC_CUI_GALLERY_VIDEO_PCKR,
    UC_CUI_FILE_SELECTOR,
    UC_CUI_PREVIEW_MMS,
    UC_CUI_PREVIEW_VCARD,
    UC_CUI_PREVIEW_VCALENDAR,
    UC_CUI_TOTAL_NUM
}VappUcCuiTypeEnum;

typedef enum
    {
		UC_RECIPIENT_TO = 1 << 0,
		UC_RECIPIENT_CC = 1 << 1,
		UC_RECIPIENT_BCC = 1 << 2,
		UC_SUBJECT = 1 << 3,
		UC_INLINE_SLIDE_BAR = 1 << 4,
		UC_INLINE_MEDIA_1 = 1 << 5,
		UC_INLINE_MEDIA_2 = 1 << 6,
		UC_BODY_TEXT = 1 << 7,
		UC_MULTI_ATTACHMENT = 1 << 8,
        UC_SINGLE_ATTACHMENT = UC_MULTI_ATTACHMENT,
		UC_INLINE_MSG_HINT = 1 << 9,
		UC_CONTACT_SELECTOR_LIST_MENU = 1 << 10,
		UC_REMOVABLE_NUM_BASE = -1
    }VappUcRemovableItemEnum;

typedef struct
{
U32 instance; 
mmi_id parent_gid;
MMI_BOOL multi_select;
const FMGR_FILTER* filter;
}VappOpenGalleryParam;

typedef struct
{    
U32 instance; 
mmi_id parent_gid;
const WCHAR* filename; 
const WCHAR* filepath;
}VappOpenVideoPlayerParam;

typedef struct
{
    U32 send_result;
    U32 save_result;
    U32 delete_result;
    U8 *fail_cause;
    U8 retry;
    VappUcAbortTypeEnum abort;
    U16 curr_folder;    /* srv_um_msg_box_enum */
//    srv_uc_sim_id highlight_sim_id;
    BOOL need_highlight_ind_to_um;
    BOOL change_in_recipient_list;
    mma_msg_storage_type_enum existed_msg_storage;
    mma_msg_storage_type_enum new_msg_storage;
    VappUcReqEnum request_id;
} VappUcSendInfoStruct;

typedef struct
{
    U32 instance;
    KAL_ADM_ID mem_pool_id;
    U8 uc_adm_mem[UC_ADM_MEM_SIZE];
    U8 busy_getting_data;
    S32 is_short;
    U8 is_warning;
	U8 launch_mode;
    U16 object_index;
    U16 max_text_limit;
    U32 image_resize_limit;
    vappUcMsgOperationEnum msg_operation;
    VappUcSelectMediaOptionEnum select_media_opt;
    srv_uc_object_type highlighted_object_type;
    vmsgc_func_ptr callback;
    void *callback_para;
    U8 file_path_to_delete[(MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH];
  #ifdef __MMI_MMS_2__
    srv_mms_create_rsp_struct *create_msg_rsp;
  #endif
    S32 resized_w;
    S32 resized_h;
    U32 resize_attempts;
    VfxTimer *m_timer;
    vmsgc_resize_func_ptr post_handler;
    vmsgc_confirm_func_ptr confirm_handler;
    mmi_id cui_gid;
    VappUcCuiTypeEnum cui_type;
    SMS_HANDLE send_handle;
    SMS_HANDLE save_handle;
    U32 m_itemForceOn;
	U32 skip_save_on_deinit;
#if (MMI_MAX_SIM_NUM >= 2)
	U32 sim_setting_primary_card;
#endif
    VfxBool active_app_flag;
} VappUcMainStruct;

typedef struct
{
    /* Use SRV_UC_MAX_EMAIL_LEN, because max(email, phonenumber) */
    U8 to[(SRV_UC_MAX_EMAIL_LEN + 1) *ENCODING_LENGTH];
    U8 cc[(SRV_UC_MAX_EMAIL_LEN + 1) *ENCODING_LENGTH];
    U8 bcc[(SRV_UC_MAX_EMAIL_LEN + 1) *ENCODING_LENGTH];
    /* U8 subject[(MMI_UC_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH]; */
    U16 current_addr_index;
    srv_uc_address_group_type_enum current_addr_type;
    srv_uc_msg_type_enum pre_msg_type;
//    mmi_uc_done_state_enum state;
} VappUcDoneStruct;


#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
extern "C" VfxBool VappUCneedTofreeService(U8 instance);
extern "C" void VappUCFreeEndKeyHandleData(U8 instance);
extern "C" U8 vappUcCheckInstanceByAppPtr(void *ptr);
#endif
/* UCE text info structure */
typedef struct
{
    U16 char_count;             /* Total Character Count */
    U16 utf8_msg_len;           /* Msg Len in UTF8 */
    U16 extension_char_count;   /* EXT CHAR Count */
    U16 UCS2_count;             /* UCS2 characters count that are not also extension characters */
} VappUcTextInfoStruct;




typedef struct 
{
    VappUcMainStruct main;
    VappUcSendInfoStruct send_info;
    VappUcDoneStruct done;
    srv_uc_cntxt_reference_struct m_service_cntxt;
} VappUcAppDataAfterSerializeBuffer;  // real memory should be from extra_base
#define VAPP_UC_SERIALIZE_ASM_SIZE ( sizeof(VappUcAppDataAfterSerializeBuffer) )

#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
typedef struct 
{
    srv_uc_msg_type_enum pre_msg_type;
    vappUcMsgOperationEnum operation_type;
    VappUcEntryStruct *otherAppTempUcInfo;
    U8 contact_insert_type;
    VfxU32 available_size;
    /*kuldeep_gplus*/
    VfxBool taken_pref_phb_sim ; 
    VfxBool is_mma_active ; 
    VfxBool wait_to_close ; 
    srv_uc_sim_id nvram_sim_id;
    /*kuldeep_async_phb*/
    srv_uc_addr_struct* CurrAsyncPhbAddr ; 
    BOOL WaitAsyncPhbRspToCloseUC ;
    void* g_settingLimitation;
    VappUcPbCuiState m_pbInsertState;
    VfxBool m_useSecondStage; 
    
    mmi_id appBaseId ;
    VappUcAppDataAfterSerializeBuffer *p_vapp_uc_asm; 
} VappUcAppArchivedata;

#define VappUcCuiResultSize ((SRV_FMGR_PATH_MAX_LEN + 1 ) * sizeof(WCHAR))

/*        
typedef enum
{
    UC_SMS_MSG_DEl,         vappUcHandleSmsMsgDelEvent
    UC_SD_CARD_PLUG_IN,     vappUcSdCardPlugInHdlr     
    UC_SD_CARD_PLUG_OUT,    vappUcSdCardPlugOutHdlr
    UC_FORCE_CLOSE,         vappUcForceClose
    Uc_USB_MS_PLUG_IN       vappUcUsbMsPlugInHdlr
    UC_EVENT_TOTAL
}VappUcStaticEvent;
*/
    
typedef struct 
{
    //mmi_id cui_id;
    
    VfxBool event_wait_to_proc;    
    mmi_event_struct event; 
    WCHAR path_buffer[VappUcCuiResultSize];
    S32 result;

    VfxBool isSuccess;
    VfxBool need_set_active_vk;
    VfxBool close_uc;
    VfxBool deinit_preview;
}VappUcCuiResult;

typedef struct 
{
    VappUcMainStruct *main;
    VappUcSendInfoStruct *send_info;
    VappUcDoneStruct *done;
    srv_uc_cntxt_reference_struct *m_service_cntxt;

    VappUcAppArchivedata archive_data;

    VfxBool is_serialized;
    VfxBool is_closing_cui;
    mmi_id group_id;
    VappUcCuiResult cui_result;
} VappUcAppDataAfterSerialize;


typedef struct 
{
    VappUcAppDataAfterSerialize *app;
    U32 instance;
}VappUcAppArchive;

#endif /* UC_VOLUNTEER_FREE */

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    typedef enum
    {
        SMS_SRV_SAVE_STOR_STATUS_NONE = 0,
        SMS_SRV_SAVE_STOR_STATUS_TCARD_FULL_SAVE_TO_PHONE,         
        SMS_SRV_SAVE_STOR_STATUS_TCARD_NOT_PRESENT_SAVE_TO_PHONE,          
        SMS_SRV_SAVE_STOR_STATUS_PHONE_FULL_SAVE_TO_TCARD,          
        SMS_SRV_SAVE_STOR_STATUS_TOTAL
    }vappUcSmsSrvSaveStorageStatusEnum;
#endif


class VappUcAppData : public VfxObject
{
public:
    /** extra_base **/
    VappUcMainStruct *main;
    VappUcSendInfoStruct *send_info;
    VappUcDoneStruct *done;
    srv_uc_cntxt_reference_struct *m_service_cntxt;
    /** extra_base **/
    
    /** archive **/
    srv_uc_msg_type_enum pre_msg_type;
    vappUcMsgOperationEnum operation_type;
    VappUcEntryStruct *otherAppTempUcInfo;
    U8 contact_insert_type;
    VfxU32 available_size;
    /*kuldeep_gplus*/
    VfxBool taken_pref_phb_sim ; 
    VfxBool is_mma_active ; 
    VfxBool wait_to_close ; 
    srv_uc_sim_id nvram_sim_id;
    /*kuldeep_async_phb*/
    srv_uc_addr_struct* CurrAsyncPhbAddr ; 
    BOOL WaitAsyncPhbRspToCloseUC ;
    void* g_settingLimitation;
    VappUcPbCuiState m_pbInsertState;
    VfxBool m_useSecondStage; 
    
    mmi_id appBaseId ;
    VappUcAppDataAfterSerializeBuffer *p_vapp_uc_asm; 
    /** archive **/
    
    // need to reset from restore 
    void* m_parent;


    /** methods  **/
    void resetApp(void);
    void createAdmPool(void);
    void isReady(void);
    VfxBool getServiceContext(void);
    void ucGenerateFilePath(mma_mms_object_struct * m_object, U8* virtual_file_name);
    void ucGetTextInfoForBuffer(VappUcTextInfoStruct *text_info, U8 *text_buffer);
    VfxBool ucTextChangeHandler(VappUcTextInfoStruct *text_info);
    VfxBool ucCharInputHandler(VappUcTextInfoStruct *new_text_info);
    U32 ucGetAttachmentItemsTotalSize(void);
    void ucGetComposerTitleString(U16* text_buffer);
	void ucGetComposerSendString(U16* text_buffer);
    void ucGetMmsSlideBarText(U16* text_buffer);
    void ucGetMmsHintBarText(U16* text_buffer);
    void ucSetRefMediaCount(void);
    void ucGetAttachmentItemList(U16 attachmentlist[][260], U16 attachmentSizeList[][UC_MAX_SIZE_STRING], VfxS32 *attachment_count);
    void ucGetAttachmentString(U16* text_buffer);
    S32 ucGetTotalNumberOfAttachment(void);
    VfxBool getMmsSetting(void);
    S32 ucHandleTextInCurrentSlide(void);
    void ucActionFsm(srv_uc_action_type_enum, VfxU32);
    void switchSlide(mma_mms_slide_struct *);
    void ucChangeMsgTypeToSms(void);
    void ucChangeMsgTypeToMms(void);
    void ucSaveMsgType(void);
    void ucEntryPreviousSlide(void);
    void ucEntryNextSlide(void);
    void getMmsContentReq(void);
    void preProcessSendTo(void);
    void ucEntryDeleteSlide(void);
    void ucEntryInsertSlide(void);
	void ucAppendTextFromApp(U8*);
    srv_um_msg_box_enum vappUcGetMsgBox(U32 msg_id);
    void sendMessage(void);
    void saveMessage(void);
#ifdef __MMI_COSMOS_UC_MMS_PREVIEW_SUPPORT__     
    void previewMessage(void);
#endif
    void ucSaveSmsReq(void);
    void ucSaveSmsAfterSend(U8 status, void *number);
    void ucPreSendSmsReq(void);
    void ucSendSmsReq(void);
#ifdef __MMI_EMAIL__
    BOOL ucSaveEmailReq(void);
    BOOL ucSendEmailReq(void);
#endif
    void ucCreateMmsHandler(U8);
    void ucCreateMmsReq(U8);
	/*kuldeep_async_phb*/
    //void ucSetPreferedSIMForMMSRecipients(void);
    srv_uc_msg_type_enum determineMsgTypeByContent(void);
    MMI_BOOL changeMsgTypeIfNeeded(void);
    MMI_BOOL isPendingContent(void);
//    virtual void sendAndSaveMessage(void);
  //  virtual void addRecipient(void);
    //virtual void removeRecipient(void);
    MMI_BOOL ucSmsMsgOperationTrigger(VappUcEntryStruct *data);
    void ucPreEntryForSms(void);
    VfxBool ucEntryWriteMsgWithContent(VappUcEntryStruct *data);
    void ucFreeCollectedObjectIndData(void);
    BOOL handleObjectInsertIfFilePathExist(void);
    S32 ucParseMmsXmlDescriptionFile(void);
    S32 ucMatchObjectId(void);
#ifdef __MMI_UC_SUB_PREFIX_MMS__
    VfxBool vappUcIsPrefixAlreadyExist(srv_uc_state_enum state, S8 *ucs2_string);
    void vappUcAddPrefixBeforeSubject(void);
#endif /* __MMI_UC_SUB_PREFIX_MMS__ */
    void ucSuccessCaseProcessAfterGetContentRsp(void);
    void ucClearMsgBearer(srv_uc_msg_type_enum msg_type);
    void ucDeleteMmsReq(U32 msg_id, U8 storage);
    void ucDeleteExistedMms(void);
    //void ucPreviewMms(void);
    void ucSelectFmgrObject(void);
    void ucSelectObjectFromFmToInsertWarningModeCheck(U16 *filePath, S32 is_short);
    void ucSelectObjectFromFmToReplaceWarningModeCheck(U16 *filePath, S32 is_short);
    void ucSelectObjectFromFmToInsert(U16 *filePath, S32 is_short);
#if defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__) || defined(__MMI_UC_MMS_IMG_RESOLUTION__)     
    U16 vappUcResizeBeforeVerification(U16 *file_path, S32 is_short);
#endif
    void vappUcImageObjectVerification(mma_insert_type_enum insert_mms_type, U8 *mmi_uc_image_path, U16* file_path);
    void ucPostHandlerSelectObjectFromFmToInsert(mma_insert_type_enum mms_type, U8 *uc_image_path, U16 *filePath);

#if defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__) || defined(__MMI_UC_MMS_IMG_RESOLUTION__) 
    VappUcResultEnum vappUcAutoResizeImgHandler(
            vmsgc_resize_func_ptr post_handler,
            U8 *filePath,
            U8 *dest_file,
            mma_insert_type_enum mms_type,
            S32 width,
            S32 height,
            S32 left_mms_size,
            BOOL first);
    S32 vappUcResizeImageAndCheck(
            U8 *src_file,
            U8 *dest_file,
            U32 resize_w,
            U32 resize_h,
            S32 left_mms_size,
            S32 *encoded_size);
    VfxBool vappUcAutoResizeImgTimeoutHandler(void);
#endif
    
    void vappUcUsbMsModePlugInHdlr(void);        
    void vappUcSdPlugInHdlr(void);
    void vappUcSdPlugOutHdlr(void);
    //void vappUcHandleObjOnSdPlugOut(VfxBool *attach_removed, VfxBool *close_cui );
    void ucEnterMultimediaApp(void);
    void vappUcSetAppData(void);
    void vappUcResetAppData(void);

#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
    void vappUcSetSerialize(U32 instance, mmi_id group_id );  
    VfxBool vappUcGetIsSerialize();
    //void vappUcResetSerialize(U32 instance);
#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    static mmi_ret onSmsSaveStorageStatusEvtCb(mmi_event_struct *param);
    vappUcSmsSrvSaveStorageStatusEnum vappUcSmsSrvSaveStorageStatus(mmi_event_struct *event_data, VfxBool isShowPopup);
    vappUcSmsSrvSaveStorageStatusEnum vappUcSmsSrvSaveStorageStatusData;
#endif    
    VfxBool vappUcSmsSrvSaveStorageStatusShowPopup();

    void vappUcTerminateWithPopup(WCHAR* str, mmi_nmgr_balloon_type_enum type);
    VfxSignal2 <WCHAR*, mmi_nmgr_balloon_type_enum> m_signalTerminate;
    VfxSignal0 m_signalConnectOnPage;
	VfxSignal0 m_signalTerminateWtPopUp;
    VfxSignal0 m_signalConnectOnFileSelection;
    VfxSignal2 <WCHAR*, mmi_nmgr_balloon_type_enum> m_signalPopup;
    VfxSignal0 m_signalConnectOnError;
    VfxSignal0 m_signalPreview;
    VfxSignal1 <VfxU16> m_signalShowConfirm;
    VfxSignal2 <VfxBool, VfxBool>m_signalRefreshPage;
    VfxSignal0 m_signalConnectOnTerminate;
    VfxSignal0 m_signalConnectToCloseProgress;
    void ucSetInsertMenu();
	void VappUCRemoveAttachment(VfxId index);
	void VappUCRemoveMedia(mma_mms_object_struct *obj);
	void setContactInsertType(U8);
	VfxU8 getContactInsertType(void);
    VfxBool ucRemoveRecipientByGroup(srv_uc_address_group_type_enum group);
    void vappUcProcessSelectObjectFromFmToInsert(VfxBool);
    void vappUcProcessNewMsgInMmsSetting(VfxBool input);
    U32 vappUcGetMaxAttachemntCount(void);
    U32 vappUcGetMaxSubjectLength(void);
    U32 vappUcGetMaxRecipientCount(void);
	U32 vappUcGetMaxTextCharCount(void);
#if defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__) || defined(__MMI_UC_MMS_IMG_RESOLUTION__)     
    void vappUcTimerExpiryCbk(VfxTimer *timer);
#endif
	U16 preCheckSendMessage();
	VfxBool handleUcUnSavedData(void);
    U32 getMaxMediaFileSizeAllowed(srv_uc_object_type obj_type);
	VfxBool recipientCheckMsgSize(VfxWChar* buff);
    void ucAddObjectFromAppSelection(U16 *filePath, S32 is_short);
	srv_uc_addr_struct* uc_convert_mms_addr_to_uc_addr(mma_mms_addr_list_struct *mms_address, U32 instance);
	void ucHandleDataAfterSend(void); /*kuldeep_async_phb*/

public:    
    VfxBool batchEdit;
    
public:

	VappUcAppData():m_pbInsertState(UC_PB_CUI_STATE_NONE),
                          m_useSecondStage(VFX_FALSE)
    {
        //memset(&main, 0, sizeof(VappUcMainStruct));
        //memset(&send_info, 0, sizeof(VappUcSendInfoStruct));
        //memset(&done, 0, sizeof(VappUcDoneStruct));
        //memset(&m_service_cntxt, 0, sizeof(srv_uc_cntxt_reference_struct));
        
        main = NULL;
        send_info = NULL;
        done = NULL;
        m_service_cntxt = NULL;
        
        m_parent = NULL;
		/*kuldeep_gplus*/
		taken_pref_phb_sim = VFX_FALSE ;
		CurrAsyncPhbAddr = NULL ;   /*kuldeep_async_phb*/
		WaitAsyncPhbRspToCloseUC = FALSE ;
		is_mma_active = VFX_FALSE ;
		wait_to_close  = VFX_FALSE;

        p_vapp_uc_asm = NULL;
        appBaseId = 0;

        operation_type = UC_OPERATION_WRITE_NEW_MSG;
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__    
        vappUcSmsSrvSaveStorageStatusData = SMS_SRV_SAVE_STOR_STATUS_NONE;
    #endif
        batchEdit = VFX_FALSE;
    }
};


/***************************************************************************** 
 * Class VappUCSlideBarItem
 *****************************************************************************/
class VappUCSlideBarItem : public VfxControl
{
    VFX_DECLARE_CLASS(VappUCSlideBarItem);

// Default Constructor
public:
    VappUCSlideBarItem() :
        m_title(NULL),
			m_parentPageSize(0, 0)
    {
    }

    VappUCSlideBarItem(VfxSize size) :
        m_title(NULL),
		m_parentPageSize(size)
    {
    }

// Override
protected:
    virtual void onInit();
    virtual void onUpdate();

// Method
public:
    virtual void setText(const VfxWString& string);
  //  void onSlideBarOptionClick(VfxObject* obj, VfxId id);
   // void onSlideBarLeftArrowClick(VfxObject* obj, VfxId id);
  //  void onSlideBarRightArrowClick(VfxObject* obj, VfxId id);
	void onSlideBarOptionMenuClick(VfxObject* obj, VfxId id);
	VcpButton* getOptionButton(void);
	VcpButton* getLeftArrowButton(void);
	VcpButton* getRightArrowButton(void);
// Implementation
private:
    enum
    {
        SCR_WIDTH   = 320,
        ITEM_WIDTH  = 305,
        ITEM_HEIGHT = 45,
        MARGIN_L    = 10,
        MARGIN_R    = 25,
        GAP         = 5,
        TXT_Y       = 18,
        TXT_Y_GAP   = 6
    };

   enum
    {
		ID_COMMAND_ADD_SLIDE,
		ID_COMMAND_REMOVE_SLIDE,

		IID_COMMAND_NUM_BASE
    };

    VfxTextFrame* m_title;

public:
    // create button image
	VcpButton* btn;
    VfxTextFrame *txt;
    VcpButton *btn2;
	VcpButton* btn1;
    VcpCommandPopup *m_commandPopup;
	VfxSize m_parentPageSize;
};


class VappUCMediaItem : public VfxControl
{
    VFX_DECLARE_CLASS(VappUCMediaItem);

// Override
protected:
    virtual void onInit();

// Implementation
private:
    enum
    {
        ITEM_WIDTH  = 320,
        ITEM_HEIGHT = 84,
        GAP         = 9,
        TXT_Y       = 18,
        TXT_Y_GAP   = 6
    };

    VfxImageFrame *img;
    VfxTextFrame *fileName;
    VfxTextFrame *sizeText;
    mma_mms_object_struct *m_object;
    srv_uc_object_type m_type ;
    VfxWString m_filePath;
	VfxSize m_parentPageSize;

public:
    VcpButton* m_MediaBase;
	FS_HANDLE m_fileHandle;

	VappUCMediaItem (mma_mms_object_struct *object, srv_uc_object_type object_type, U8* file_path, VfxSize size)
    {
        m_object = object;
        m_type = object_type;
        m_filePath.loadFromMem((VfxWChar*)file_path);
		m_parentPageSize = size;
        //vfx_sys_wcscpy(m_filePath, (VfxWChar*)file_path);
    }
    VappUCMediaItem(){};
	virtual ~VappUCMediaItem()
	{
		if (m_fileHandle> 0)
		{
			FS_Close(m_fileHandle);
			m_fileHandle = 0;
		}
	}
	void onClickCmdBtn(VfxObject *obj, VfxId btn_id);
	void VappUClaunchMediaApp();
    void onMediaBarClick(VfxObject* obj, VfxId id);

   	 enum
    {
        VAPP_UC_MEDIA_PREVIEW_OPTION_ID,
		VAPP_UC_MEDIA_REMOVE_OPTION_ID,
		VAPP_UC_MEDIA_CANCEL_OPTION_ID
    };

};

/***************************************************************************** 
 * Class VappUCAttachmentButtonItem
 *****************************************************************************/
class VappUCAttachmentButtonItem : public VfxControl
{
    VFX_DECLARE_CLASS(VappUCAttachmentButtonItem);

// Default Constructor
public:
    VappUCAttachmentButtonItem():
        m_hint(NULL),
		m_parentPageSize(0, 0)
    {
    }

	VappUCAttachmentButtonItem(VfxSize parentSize, VfxBool top_gap):
        m_hint(NULL),
		m_parentPageSize(parentSize),
		need_gap(top_gap)
	{
	}

// Override
protected:
    virtual void onInit();
    virtual void onUpdate();

// Method
public:
    virtual void setText(const VfxWString& string);
    virtual void setHint(const VfxWString& string);
    VcpArrowButton* btn;
	void onButtonClicked(VfxObject* obj, VfxId id);

// Implementation
private:
    enum
    {
        SCR_WIDTH   = 320,
        ITEM_WIDTH  = 305,
        ITEM_HEIGHT = 45,
        MARGIN_L    = 10,
        MARGIN_R    = 25
    };

    VfxTextFrame* m_hint;
	VfxSize m_parentPageSize;
	VfxBool need_gap;
};

/***************************************************************************** 
 * Class VappUCSingleAttachmentButtonItem
 *****************************************************************************/
class VappUCSingleAttachmentButtonItem : public VfxControl
{
    VFX_DECLARE_CLASS(VappUCSingleAttachmentButtonItem);

// Default Constructor
public:
    VappUCSingleAttachmentButtonItem() :
        m_title(NULL),
		m_parentPageSize(0, 0),
		need_gap(VFX_FALSE)
    {
    }

	  VappUCSingleAttachmentButtonItem(VfxSize Size, VfxBool topGap) :
        m_title(NULL),
		m_parentPageSize(Size),
		need_gap(topGap)
    {
    }

// Override
protected:
    virtual void onInit();
    virtual void onUpdate();

// Method
public:
    virtual void setText(const VfxWString& string);
	void ucPreviewRemoveSingleAttachment(VfxObject*sender, VfxId btnId);

// Implementation
private:
    enum
    {
        SCR_WIDTH   = 320,
        ITEM_WIDTH  = 305,
        ITEM_HEIGHT = 45,
        MARGIN_L    = 10,
        MARGIN_R    = 25
    };
	enum
	{
	   VAPP_UC_ATTACHMENT_PREVIEW_BTN_ID,
	   VAPP_UC_ATTACHMENT_REMOVE_BTN_ID
	};
	void onButtonClicked(VfxObject* obj, VfxId id);
    VcpButton* m_title;
	VfxSize m_parentPageSize;
	VfxBool need_gap;
};

class VappAttachmentInfoListMenuContentProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
	VfxWChar attachmentList[UC_MAX_ATTACHMENT_POSSIBLE][260];
    VfxWChar m_attachmentSizeList[UC_MAX_ATTACHMENT_POSSIBLE][UC_MAX_SIZE_STRING];
	VfxS32 attachmentCount;
	VfxBool appModeEmail;

public:
	virtual void setMenu(VcpListMenu *menu){list = menu;}
	VappAttachmentInfoListMenuContentProvider();
	virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );

	virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image         
        ) ;

	virtual VfxU32 getCount() const ;

public:
    VcpListMenu *list;
};

class VAppUcAttachmentlistPage : public VfxPage
{
    VFX_DECLARE_CLASS(VAppUcAttachmentlistPage);

// Override
private:
	VcpCommandPopup *m_attachmentOptions;
	VfxId selectedItem;

protected:
	virtual VfxBool onKeyInput(VfxKeyEvent& event);
    virtual void onInit();
	virtual void onEnter(VfxBool isbackward);
	virtual void onQueryRotateEx(VfxScreenRotateParam &param); /*For page Rotation*/

public:
	VcpListMenu *attahmentList;
	VappAttachmentInfoListMenuContentProvider *m_listMenuContentProviderForAttachment;
	//VfxBool onKeyInput(VfxKeyEvent& event);
    void onTap(VcpListMenu *listMenu, VfxU32 itemIndex);
    void onDeleteTab( VcpListMenu *lst, VfxU32 index);
    VAppUcAttachmentlistPage():attahmentList(NULL){}
    virtual void setBounds(const VfxRect &value);
    void onToolBarClick(VfxObject* obj, VfxId id);
        
	 enum
    {
        VAPP_UC_ATTACHMENT_PREVIEW_OPTION_ID,
		VAPP_UC_ATTACHMENT_REMOVE_OPTION_ID,
		VAPP_UC_ATTACHMENT_CANCEL_OPTION_ID
    };

};


class VappRecipientListContentProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
   VcpContactSelector *m_contactSelector;
	VfxS32 recipientCount;

public:
	virtual void setMenu(VcpListMenu *menu){list = menu;}
	VappRecipientListContentProvider();
	virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );

	virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image         
        ) ;

	virtual VfxU32 getCount() const ;

public:
    VcpListMenu *list;
};

class VAppUcRecipientlistPage : public VfxPage
{
    VFX_DECLARE_CLASS(VAppUcRecipientlistPage);

// Override
private:
   VcpContactSelector *m_contactSelector;
//	VcpCommandPopup *m_attachmentOptions;
	VcpListMenu *recipientListPage;
	VappRecipientListContentProvider *m_listContentProviderForRecipientList;
	VfxId selectedItem;

protected:
	virtual VfxBool onKeyInput(VfxKeyEvent& event);
    virtual void onInit();
	virtual void onEnter(VfxBool isbackward);
	virtual void onQueryRotateEx(VfxScreenRotateParam &param); /*For page Rotation*/

public:
	//VfxBool onKeyInput(VfxKeyEvent& event);
	//void onTap(VcpListMenu *listMenu, VfxU32 itemIndex);
   void onDeleteTab( VcpListMenu *lst, VfxU32 index);
   VcpContactSelector *getRecipientHead()
   {
    return m_contactSelector;
   }
   VAppUcRecipientlistPage(VcpContactSelector *obj): recipientListPage(NULL)
   {
       m_contactSelector = obj;   
   }
   VAppUcRecipientlistPage():recipientListPage(NULL){};
	virtual void setBounds(const VfxRect &value);
};


class VappComposerMainPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappComposerMainPage);

//W1203_UI_PERFORMANCE_BEGIN
public:
	void updateView(VfxBool isSetAutoActivated);
    void setAutoActivated();
    void setEditorActivated();
//W1203_UI_PERFORMANCE_END

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param); /*For page Rotation*/
    virtual void onEntered();    
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    virtual void setBounds(const VfxRect &value);
	virtual void onRotate(const VfxScreenRotateParam &param);

private:
    static mmi_ret onSimSrvEvtCb(mmi_event_struct * param);    
        
private:
    enum
    {
        ITEM_WIDTH  = 320,
        BUTTON_W    = 305,
        BUTTON_H    = 45,
        TEXT_W      = 320,
        TEXT_H      = 25,
		INPUT_H		= 38
    };

    /* Different component */
    VfxTextFrame* composer_title;
    VcpForm *composer_form;
    VcpTitleBar * composerTitleBar;
    VcpToolBar* composerToolbar;
    VcpContactSelector *m_contactSelectorTo;
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__      
    VcpContactSelector *m_contactSelectorCc;
    VcpContactSelector *m_contactSelectorBcc;
#endif    
    VcpTextEditor *textEditorSubject;
    VcpTextEditor *textEditorBody;
    // Slide bar
    VappUCSlideBarItem* slideBar;
    // create media bar
    VappUCMediaItem *composer_media1;
    VappUCMediaItem *composer_media2;
    VappUCAttachmentButtonItem *attachmentList;
    VappUCSingleAttachmentButtonItem *attachmentList1;
    VfxTextFrame *composerHintTxt;
    VcpCommandPopup *m_commandPopup;
    VAppUcRecipientlistPage *recipientListPage;
	VappUcContactList *m_contactlist;

    VcpFormItemCustomFrame *frame_part1;
    VcpFormItemCustomFrame *frame_part2;
    VcpFormItemCustomFrame *frame_part3;
    VcpFormItemCustomFrame *frame_part4;
    VcpFormItemCustomFrame *frame_part5;
    VcpFormItemCustomFrame *frame_part6;
    VcpFormItemCustomFrame *frame_part7;
    VcpFormItemCustomFrame *frame_part8;
    VcpFormItemCustomFrame *frame_part9;
    VcpFormItemCustomFrame *frame_part10;
    VcpFormItemCustomFrame *frame_part11;

	VcpFunctionBar* m_functionBarFrame;
	VcpFunctionBar* m_functionBarToFrame;
 #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__     
	VcpFunctionBar* m_functionBarCcFrame;
	VcpFunctionBar* m_functionBarBccFrame;
 #endif   
	VcpFunctionBar* m_functionBarSubjectFrame;

	U32 cursorIndexToHeighlight;
	VcpTextEditor * highlightedEditor;
    VfxBool m_isBlockDeactivateEditor;
        
    void setSubjectText(VfxWChar *string);
    VfxWChar* getSubjectText(void);
    void removableHandler(VcpFormItemRemovableTextEntry* obj, VfxId id, VfxBool isAdded);
    void onCharInput(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret);
    void onRecipientEditorActivated(VcpContactSelector* recipientHead, VcpTextEditor *editor, VfxBool activated);
    VfxBool onRecipientCharInput(VcpContactSelector* recipientHead, VfxWChar *text);
    void onToRCharInput(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret);
    void onToEditorActivated(VcpTextEditor *editor, VfxBool activated);
    void onRecipientMoreButtonClicked(VcpContactSelector* obj);
    void onBodyTextChanged(VcpTextEditor *editor);
    void onSubjectTextChanged(VcpTextEditor *editor);
    void onattachmentButtonClicked(VfxObject* obj, VfxId id);
    void onSlideBarOptionClick(VfxObject* obj, VfxId id);
    void onSlideBarLeftArrowClick(VfxObject* obj, VfxId id);
    void onSlideBarRightArrowClick(VfxObject* obj, VfxId id);
	void onTapItem(VcpListMenu *listMenu, VfxU32 itemIndex);
    VfxId VappUcGetPositionToInsert(VfxId id);
	void deactivateEditor(void);
	VfxObject * getNextHighlightPosition(VfxId itemID, VfxId moveSide);
	VfxObject* getItemToHilight(VfxObject* obj, VfxId id);
	void resetFunctionBar(VfxObject* obj);
	void resetAllFunctionBar(void);
	VcpTextEditor* getNextEditorFromFunctionBar(VcpFunctionBar* function_bar, VfxId id);

public:
    
    enum
    {
        ID_TOOLBAR_SEND,
        ID_TOOLBAR_SWITCH_SIM,
        ID_TOOLBAR_SAVE_AS,
        ID_TOOLBAR_INSERT,
        ID_TOOLBAR_ADD_SUBJECT,
        ID_TOOLBAR_REMOVE_SUBJECT,
        ID_TOOLBAR_CCBCC,
        ID_TOOLBAR_PREVIEW,
        ID_TOOLBAR_SAVE,
        ID_TOOLBAR_CANCEL,
        ID_TOOLBAR_ADD_VCARD,
        ID_TOOLBAR_ADD_VCALENDAR,
		ID_TOOLBAR_ADD_VTASK,
		ID_TOOLBAR_ADD_VEVENT,
        ID_TOOLBAR_ADD_FILE,
        ID_TOOLBAR_CLEAR_ALL,
        ID_TOOLBAR_ADD_ATTACHMENTS,
        ID_COMMAND_REMOVE_SLIDE,
        ID_COMMAND_ADD_SLIDE,
        ID_COMMAND_SELECT_PICTURE_FROM_GALLERY,
        ID_COMMAND_TAKE_PICTURE,
        ID_COMMAND_SELECT_VIDEO_FROM_GALLERY,
        ID_COMMAND_TAKE_VIDEO,
        ID_COMMAND_SELECT_AUDIO_FROM_GALLERY,
        ID_COMMAND_TAKE_AUDIO,
        ID_COMMAND_ADD_CC,
        ID_COMMAND_ADD_BCC,
        ID_COMMAND_REMOVE_CC,
        ID_COMMAND_REMOVE_BCC,
        ID_COMMAND_SAVE_AS_DRAFT,
        ID_COMMAND_SAVE_AS_TEMPLATE,
        ID_COMMAND_INSERT_TEMPLATE,
        ID_COMMAND_INSERT_EMOTICON,
		ID_TOOLBAR_PREV,
		ID_TOOLBAR_NEXT,
        ID_TOOLBAR_SWITCH_SIM1,
        ID_TOOLBAR_SWITCH_SIM2,
        ID_TOOLBAR_SWITCH_SIM3,
        ID_TOOLBAR_SWITCH_SIM4,
        ID_TOOLBAR_QUERY_SIM1,
        ID_TOOLBAR_QUERY_SIM2,
        ID_TOOLBAR_QUERY_SIM3,
        ID_TOOLBAR_QUERY_SIM4,

        ID_TOOLBAR_NUM_BASE
    };
   enum
    {
		ID_RECIPIENT_TO = 1 << 0,
		ID_RECIPIENT_CC = 1 << 1,
		ID_RECIPIENT_BCC = 1 << 2,
		ID_SUBJECT = 1 << 3,
		ID_INLINE_SLIDE_BAR = 1 << 4,
		ID_INLINE_MEDIA_1 = 1 << 5,
		ID_INLINE_MEDIA_2 = 1 << 6,
		ID_BODY_TEXT = 1 << 7,
		ID_MULTI_ATTACHMENT = 1 << 8,
        ID_SINGLE_ATTACHMENT = ID_MULTI_ATTACHMENT,
		ID_INLINE_MSG_HINT = 1 << 9,
		ID_CONTACT_SELECTOR_LIST_MENU = 1 << 10,
		ID_REMOVABLE_NUM_BASE = -1
    };
	enum
   {
		TOOLBAR_SEND = 1 << 0,
		TOOLBAR_SWITCH_SIM = 1 << 1,
		TOOLBAR_INSERT = 1 << 2,
		TOOLBAR_SAVE = 1 << 3,
		TOOLBAR_REMOVE_SUBJECT = 1 << 4,
		TOOLBAR_ADD_SUBJECT = 1 << 5,
		TOOLBAR_CCBCC = 1 << 6,
		TOOLBAR_PREVIEW = 1 << 7,
		TOOLBAR_CANCEL = 1<< 8,
		TOOLBAR_SAVE_AS = 1<< 9,
		TOOLBAR_NUM_BASE = -1
   };
    VAppUcAttachmentlistPage *attachmentPage;
    VcpIndicatorPopup *m_popup;
	VcpActivityIndicator *m_loading;
    VfxU32 m_itemsToDraw;
    VfxU32 m_itemsAlraedyDraw;
	VfxU32 m_BackUpitemsAlraedyDraw;
    VfxU32 m_itemForceOn;
    VfxU32 m_toolBarItemOn;

    void drawWithData(void);
    void onToolBarClick(VfxObject* obj, VfxId id);
    void removeObjectFromPage(VfxS32 pageItem);
    void removeButtonBar(void);
    VfxBool isSendButtonAvailable(void);
    void updateButtonBar(void);
    void insertSubjectItem(void);
    void removeSubjectItemFromPage(void);
    void insertMediaItem(void);
    void insertSlideBarItem(void);
    void insertTextBodyEditor(void);
    void insertAttachment(void);
    void updateBottomMsgHint(void);
    void insertContactSelector(void);
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
    void insertContactSelectorCc(void);
    void insertContactSelectorBcc(void);
#endif    
    void csToOnSearchButtonClicked(void);
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
    void csCCOnSearchButtonClicked(void);
    void csBCCOnSearchButtonClicked(void);
#endif    
	/*kuldeep_gplus*/
	void onEntertoggleString(void);
	void UpdateSendButtonOnSwithSim(void);
	void GetSwitchSimString(U16* text_buffer);
    void onContactListUpdate(VcpContactSelector *obj, VcpContactChangedEnum type);
    void csOnTextChanged(VcpContactSelector *cs, VfxWChar *text);
	void csOnBodyTextHeightChange(VfxFrame *f, const VfxRect &r);
    void csOnRcipientHeightChange(VfxFrame *f, const VfxRect &r);
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
    void csOnCcTextChanged(VcpContactSelector *cs, VfxWChar *text);
    void csOnCcRcipientHeightChange(VfxFrame *f, const VfxRect &r);
    void csOnBccTextChanged(VcpContactSelector *cs, VfxWChar *text);
    void csOnBccRcipientHeightChange(VfxFrame *f, const VfxRect &r);
    void onCcRCharInput(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret);
    void onBccRCharInput(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret);
    void onCcEditorActivated(VcpTextEditor *editor, VfxBool activated);
    void onBccEditorActivated(VcpTextEditor *editor, VfxBool activated);
#endif    
    void getRecipientFromBuffer(void);
	void getRecipientFromBufferByGroup(VcpContactSelector* recipientContacts);
	void hideUnhideControls(VfxU32 ids, VfxBool isHide);
	void restoreControls(void);
	void insertAddressItem(VfxU32 groupType, const VfxWChar *name, const VfxWChar *address, VfxU32 addressType);
	void insertTextStringOneGo(VfxWChar *string, VfxBool isReplace);
	void insertTextString(VfxWChar *string, VfxBool isReplace = VFX_FALSE);
	void onPhbSearchContactListUpdate(VfxU32 count);
	VfxBool addPendingRecipientEntry(void);
	void onSelectingSend(void);
	void validSimSend(void);
    void onToEnterKeyClicked(VcpTextEditor *editor, IMEVKEnterKeyStyleEnum enterKeyStyle);
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
    void onCcEnterKeyClicked(VcpTextEditor *editor, IMEVKEnterKeyStyleEnum enterKeyStyle);
    void onBccEnterKeyClicked(VcpTextEditor *editor, IMEVKEnterKeyStyleEnum enterKeyStyle);
#endif    
    void onRecipientEnterKeyClicked(VcpContactSelector* recipientHead);
	virtual void onBack(void);
	virtual VfxBool onKeyInput(VfxKeyEvent& event);
	void onTextBodyEditorActivated(VcpTextEditor *editor, VfxBool activated);
    void onSubjectActivated(VcpTextEditor *editor, VfxBool activated);
	void setTextBodyeditorActiveOnPage(void);
#if defined(__MMI_MESSAGES_TEMPLATE__)     
	void onSmsTemplateClicked(VfxObject * obj, VfxWString templateString, VfxU16 templateId);
#endif
	void setForceDataToRender(void);
	void onSubjectEnterKeyClicked(VcpTextEditor *editor, IMEVKEnterKeyStyleEnum enterKeyStyle);
	void onSubjectCharInput(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret);
#if defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)		
	void onEmoticonSelect(VfxObject *, VfxU32 index);
#endif
	void onFirstEnterSetDefaultActive();
	void SetTitleAfterSend(U16* text_buffer);
    VfxBool isNeedUpdate;

    //constructor
VappComposerMainPage():composer_form(NULL),
                                composerTitleBar(NULL),
                                composerToolbar(NULL),
                                m_contactSelectorTo(NULL),
                             #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__  	
                                m_contactSelectorCc(NULL),
                                m_contactSelectorBcc(NULL),
                             #endif
                                textEditorSubject(NULL),
                                textEditorBody(NULL),
                                slideBar(NULL),
                                composer_media1(NULL),
                                composer_media2(NULL),
                                attachmentList(NULL),
                                attachmentList1(NULL),
                                composerHintTxt(NULL),
                                m_contactlist(NULL),
                                m_functionBarFrame(NULL),
                                m_functionBarToFrame(NULL),
                             #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__  	
                                m_functionBarCcFrame(NULL),
                                m_functionBarBccFrame(NULL),
                             #endif
                                m_functionBarSubjectFrame(NULL),
                                cursorIndexToHeighlight(0),
                                highlightedEditor(NULL),
                                m_isBlockDeactivateEditor(VFX_FALSE),
                                m_popup(NULL),
                                m_loading(NULL),
                                m_itemsAlraedyDraw(0),
                                m_BackUpitemsAlraedyDraw(0),
                                m_itemForceOn(0),
                                m_toolBarItemOn(0),
                                isNeedUpdate(VFX_FALSE)
{
}

};


/*****************************************************************************
 * Class VappUCMainScr declaration
 *****************************************************************************/

class VappUCMainScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappUCMainScr);

//constructor
public:
    VappUCMainScr();
    

// Override
protected:
    virtual void on1stReady();
//W1203_UI_PERFORMANCE_BEGIN
	virtual void on2ndReady();
//W1203_UI_PERFORMANCE_END
	virtual void onQueryRotateEx(VfxScreenRotateParam &param); /*For Screen Rotation*/
public:
    VappUcAppData* getAppData(void);

public:
    VappUcAppData *m_app_data;  // need to reset after restore
    VappComposerMainPage *composer_page;  // need to reset after restore
    VfxBool m_isScreenEntered;   
    
private:
	VfxWChar m_inputStringTo[32];
    
    
	enum
    {
		VAPP_UC_PAGE_ID_NONE,
		VAPP_UC_PAGE_ID_COMPOSER_PAGE,
		VAPP_UC_PAGE_ID_INSERT_MENU_ITEM_PAGE,
		VAPP_UC_PAGE_ID_ATTACHMENT_LIST_PAGE,
		VAPP_UC_PAGE_ID_RECIPIENT_LIST_PAGE,
		VAPP_UC_PAGE_ID_DUMMY_PAGE,
		VAPP_UC_PAGE_ID_TOTAL
    };
public: 
void connectOnFileSelection(void)
{
    if(composer_page->m_popup)
    {
        if (composer_page->m_popup->isValid())
		{
            VFX_OBJ_CLOSE(composer_page->m_popup);
		}
        composer_page->m_popup = NULL;
    }
	connectOnPage();
}
void connectOnPage(void)
{
	m_app_data->main->busy_getting_data = 0;
    composer_page->drawWithData();
    m_app_data->m_signalConnectOnPage.disconnect(this, &VappUCMainScr::connectOnPage);
}
void connectToClose(void)
{
	if(composer_page)
	{
		if(composer_page->m_popup)
		{
		    if (composer_page->m_popup->isValid())
			{
		        VFX_OBJ_CLOSE(composer_page->m_popup);
			}
		    composer_page->m_popup = NULL;
		}
		if(composer_page->m_loading)
		{
		    if (composer_page->m_loading->isValid())
			{
				composer_page->m_loading->stop();
			}
		    composer_page->m_loading = NULL;
		}
		m_app_data->main->skip_save_on_deinit = VFX_TRUE;
		popPage();
		composer_page = NULL ;
	}
}
VappComposerMainPage* getComposerPage(void)
{
    return composer_page;
}
void connectToCloseProgress(void)
{
    if(composer_page->m_popup)
    {
		if (composer_page->m_popup->isValid())
		{
            VFX_OBJ_CLOSE(composer_page->m_popup);
		}
        composer_page->m_popup = NULL;
    }
    if(composer_page->m_loading)
    {
        if (composer_page->m_loading->isValid())
		{
			composer_page->m_loading->stop();
		}
        composer_page->m_loading = NULL;
    }
    m_app_data->m_signalConnectToCloseProgress.disconnect(this, &VappUCMainScr::connectToCloseProgress);
}
VfxBool vappUcCloseCui(void);
void refreshPageOnSdPlugOut(VfxBool deinit_preview, VfxBool attach_removed);
void displayPopup( WCHAR* title, mmi_nmgr_balloon_type_enum event_type);
void ucEnterMultimediaApp(void);
#ifdef __MMI_COSMOS_UC_MMS_PREVIEW_SUPPORT__ 
    void ucPreviewMms(void);
#endif
void terminateApp(void);
void ucOpenGallery(void);
#if defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__) && defined(BROWSER_SUPPORT)
void ucSelectBookMark(void);
#endif
void ucOpenImageViewer(const WCHAR*, const WCHAR*);

#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
#ifdef __MMI_COSMOS_UC_VIDEO_PREVIEW_SUPPORT__
    void ucPlayVideoFile(const WCHAR*, const WCHAR*);
#endif
#endif

void ucPlayAudioFile(const WCHAR* , const WCHAR*);
#if defined(__MMI_VCARD__)
void ucPreviewVcard(const WCHAR*, const WCHAR*);
#endif
#ifdef __MMI_VCALENDAR__
void ucPreviewVcalendar(const WCHAR* filename, const WCHAR* filepath);
#endif /* __MMI_VCALENDAR__ */
void VappUCPreviewAttachment(VfxId index);
void ucOpenPhoneBook(VfxBool isMultiSelect, VfxU32 mode);
#ifdef __MMI_VCALENDAR__
void ucOpenCalenderList(VfxU32 type);
#endif /* __MMI_VCALENDAR__ */
void vappUcShowConfirm(VfxU16 str_id);
void vappUcOnConfirm(VfxObject* obj, VfxId id);
void ucHandleAddressCallback(VfxU16 cnt);
void ucAddObjectFromAppSelectionProcess(U16 *filePath, S32 is_short);
virtual mmi_ret onProc(mmi_event_struct *evt);
void vappUcShowSendConfirm(VfxWChar* text_buffer);
void vappUcShowSimSwapConfirm(U16* text_buffer);
void vappUcGetSimSwapTitle(U16* text_buffer);
void vappUcOnSendConfirm(VfxObject* obj, VfxId id);
void vappOnSimSwapConfirm(VfxObject* obj, VfxId id);
void udateMessageSize(void);

};


/*****************************************************************************
 * Class VcuiUcMainCui declaration
 *****************************************************************************/

class VcuiUcMainCui : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiUcMainCui);

// Override
public:
    VappUcAppData *m_app_data;   // need to reset after restore
    VappUCMainScr *m_scr;  // need to reset after restore
    VfxBool temp_flag; // Temporarily required. Will be removed on 11.05
#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
    VfxBool m_isInRestore;
#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */

#ifdef __MMI_MMS_USE_ASM__ 
    VfxBool m_inCloseProcess;
    VfxBool m_isWaitToBeClose;
#endif

protected:
	using VfxApp::onProcessClose;

public:
    virtual void onRun(void* args, VfxU32 argSize);

#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__

    virtual void onGroupInactive();
	virtual void onSerialize(void *hint, VfxArchive &archive);
	virtual void onRestore(VfxArchive &archive);    
    VfxBool handleDataOnSerialize(void *hint, VfxArchive &archive);
    VfxBool handleDataOnRestore(VfxArchive &archive);
    VfxBool onProcBeforeRestore(VappUcCuiResult *cui_result);
    void onProcAfterRestore(VappUcCuiResult *cui_result);    
#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */

    VfxBool handleData(void* args, VfxU32 argsize);

#ifdef __MMI_MMS_USE_ASM__ 
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);
    VfxBool callContinueClose(void);
    void setWaitToBeClose(VfxBool isNeedWaitToBeClose);
    VfxBool isWaitToBeClose(void);
#endif        

    void vappUcSendEvtToCaller(cui_msgcomposer_evt_enum evt_id);
    void vappUcTerminate(void);
    void vappUcDeInitData(void);

#ifdef __MMI_MMS_USE_ASM__     
    static mmi_ret onMmsSrvEvtCb(mmi_event_struct *param);
#endif

    VcuiUcMainCui()
    {
        m_app_data = NULL;
 #ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__       
        m_isInRestore = VFX_FALSE;
 #endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */
 #ifdef __MMI_MMS_USE_ASM__ 
        m_inCloseProcess = VFX_FALSE;
        m_isWaitToBeClose = VFX_FALSE;
 #endif

#ifdef __MMI_MMS_USE_ASM__ 
        mmi_frm_cb_reg_event(EVT_ID_SRV_MMS_SERVICE_MEM_FREE_DONE, &VcuiUcMainCui::onMmsSrvEvtCb, getObjHandle());
#endif        
    }

    virtual ~VcuiUcMainCui()
    {
#ifdef __MMI_MMS_USE_ASM__ 
        mmi_frm_cb_dereg_event(EVT_ID_SRV_MMS_SERVICE_MEM_FREE_DONE, &VcuiUcMainCui::onMmsSrvEvtCb, getObjHandle());
#endif     
        if(m_app_data)
        {
         #ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__   
            if(m_app_data->vappUcGetIsSerialize())
            {
                m_app_data->m_signalRefreshPage.disconnect(this, &VappUCMainScr::refreshPageOnSdPlugOut);
                VFX_DELETE(m_app_data);
                m_app_data = NULL;
                return ;
            }
         #endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */       
         
            if (m_app_data->m_service_cntxt->send_info->new_msg_id)
			{
				m_app_data->ucClearMsgBearer(SRV_UC_MSG_TYPE_MMS_PREFER);
			}
        #ifdef __MMI_EMAIL__
            if (m_app_data->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
                vappUcSendEvtToCaller(EVT_ID_CUI_UC_EMAILCOMPOSER_CLOSE);
            }
            else
        #endif /* __MMI_EMAIL__ */
            if (m_app_data->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
            {
                vappUcSendEvtToCaller(EVT_ID_CUI_UC_LEMEICOMPOSER_CLOSE);
            }
			else
            {
               #ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
				// block the functionality as design limitation of folder removal.
			    if(!m_app_data->main->skip_save_on_deinit)
			    {
				    m_app_data->handleUcUnSavedData();
			    }
				else
				{
					VappUCFreeEndKeyHandleData(m_app_data->main->instance);
				}
                #endif
                cui_msgcomposer_evt_struct evt;
                MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_UC_MSGCOMPOSER_PRECLOSE, getGroupId());
                sendToCaller((mmi_group_event_struct*)&evt); 
        
                vappUcSendEvtToCaller(EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE);
            }
			/*if(m_app_data->m_service_cntxt->send_info->fs)
			{
				FS_Close(m_app_data->m_service_cntxt->send_info->fs);
				m_app_data->m_service_cntxt->send_info->fs = 0;
			}*/
			m_app_data->m_signalRefreshPage.disconnect(this, &VappUCMainScr::refreshPageOnSdPlugOut);
            m_app_data->resetApp();
			#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
				if(!VappUCneedTofreeService(m_app_data->main->instance))
            #endif
            srv_uc_delete(m_app_data->main->instance);
            m_app_data->vappUcResetAppData();

            vadpAsmFree(getGroupId(), m_app_data->p_vapp_uc_asm);
            m_app_data->p_vapp_uc_asm = NULL;
                
            VFX_DELETE(m_app_data);
            m_app_data = NULL;
        }
        //VFX_FREE_MEM(m_app_data->m_service_cntxt);
        //VFX_FREE_MEM(m_app_data);
    }
};

/* Attachment */


class VappTestInsertMenuListPage : public VfxPage,public IVcpGroupListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappTestInsertMenuListPage);
public:
    VfxS32 strMenu[20][2];
    VfxS32 strInsertGroups[5][2];
    VfxS32 numberInsertGroups[5];
    VfxS32 m_insert_group_count;
    VfxSignal0 m_signalConenctOnPage;

    virtual void onInit();
// slot
	void OnListFocused(VcpGroupListMenu *, // Sender
        VcpMenuPos        // Current focus list item index
		);
//	void onToolBarClick(VfxObject* sender, VfxId id);
//override
	virtual VfxBool onKeyInput(VfxKeyEvent& event);
    virtual VfxU32 getCount(VfxU32 group) const;
	virtual VfxU32 getGroupCount() const;
	virtual VfxBool hasGroupHeader(VfxS32 group) const;
	virtual VfxBool getItemText(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
    VappTestInsertMenuListPage();
	virtual void setBounds(const VfxRect &value);
protected:
	virtual void onQueryRotateEx(VfxScreenRotateParam &param); /*For page Rotation*/
private:
	VcpGroupListMenu *m_list;
};

#define MAX_UC_INSTANCES 5
typedef struct
{
    U32 valid_sim_id_info;
	/*kuldeep_gplus*/
	U32 blocked_sim_info ;
	U32 closed_sim_info ;
    VfxBool is_flight_mode_enable ;
	VfxBool temp_flag; /* Will be removed on 11.05 */
    VappUcAppData *app_data[MAX_UC_INSTANCES];
    VappUcAppData *curr_app;
    VappUcEntryStruct *initData;
    
#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
    mmi_id group_id[MAX_UC_INSTANCES];
    VfxBool is_serialize[MAX_UC_INSTANCES];
#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */
    
}VappUcContainerStruct;


#ifndef __MMI_MMS_STANDALONE_COMPOSER__
extern "C" VfxBool VappUCsmsReadyCheck(void);
#endif
#ifdef __MMI_MMS__
extern "C" VfxBool VappUCmmsReadyCheck(void);
#endif
extern "C" VfxBool VappUCisReady(void);
extern "C" void ucGetStringFromInt(S32 number, U16* text_buffer);
extern "C" void ucGetSizeStringFromByteCount(S32 number, U16* text_buffer);
extern "C" U32 vapp_get_icon_according_to_media_type(VfxWChar* file_name);

/* Dummy code : Remove later */
typedef struct
{
    kal_uint8 addr_num;                 /* Max addresses */
    srv_uc_addr_struct *addr;           /* Addresses linklist */
    srv_uc_msg_type_enum msg_type;      /* srv_uc_msg_type_enum */
    kal_uint8 *file_path;               /* File path */
    kal_uint8 *text_buffer;             /* File path */
    kal_uint16 text_num;                /* File path */
    kal_uint8 *subject;                 /* File path */
    srv_uc_info_type_enum info_type;    /* srv_uc_info_type_enum */
    void *info;                         /* Info. SMS use msg ID/Index to pass */
    vmsgc_func_ptr callback;               /* Callback function specified by caller of object forward, for calling after use of object */
    void *callback_para;                /* Input paramter to callback function above */
    srv_uc_sim_id sim_id;               /* srv_uc_sim_id */
    vmsgc_get_addr_func_ptr get_address_callback;        /* Callback function specified by caller to call if multiple addresses forwarded */
} vapp_uc_entry_write_struct;

#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
typedef struct
{
	VappUcAppData *EndKeyAppData ;
	VfxBool NeedToFreeService ;
	FS_HANDLE xml_fs ;
}VappUcEndKeyHandleStruct ;

extern VappUcEndKeyHandleStruct EndKeyHandle[MAX_UC_INSTANCES] ;
#endif
extern "C" srv_uc_sim_id vappUcConvertMmiSimIdToUc(U32 sim_id);
extern "C" mmi_sim_enum vappUcConvertUCSimIdToMmi(U32 sim_id);
extern "C" U32 vappUcConvertSwitchModeToUcSimId(U32 swith_mode);
extern "C" VfxBool vappUcGetSimNameString(srv_uc_sim_id sim, WCHAR* text_buffer);
extern "C" U32 vappUcGetValidSimInfo(void);
/*kuldeep_gplus*/
extern "C" U32 vappUcGetBlockedSimInfo(void);
extern "C" U32 vappUcGetClosedSimInfo(void);
extern "C" U32 vappUcGetInvalidSimInfo(void);
extern "C" U32 vappUcGetValidSimToSend(void);
extern "C" VfxBool vappUcFlightModecheck(void);
extern "C" srv_uc_sim_id vappUcGetCurrSimId(void);
extern "C" VfxS32 vappUcGetCurrValidSimCount(void);
extern "C" VfxS32 vappUcGetAllSimCount(void);
extern "C" MMI_BOOL vappUcDummy(mmi_scenario_id scen_id, void *arg);
extern "C" void processSelectObjectFromFmToInsert(VfxBool input, void* app_data);
extern "C" void processNewMsgInMmsSetting(VfxBool input, void* app_data);
extern "C" BOOL vappUcIsValidImage(U16 *file_path);
#ifdef __MMI_MMS_2__
#if defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__) || defined(__MMI_UC_MMS_IMG_RESOLUTION__) 
extern "C" U32 vappUcConvertUmmsResizeToUc(srv_umms_picture_size_enum size);
#endif
#endif
extern "C" void imageObjectVerification(mma_insert_type_enum insert_mms_type, U8 *uc_image_path, U16* file_path);
extern "C" MMI_BOOL vappUcCalImgResolution(S32 old_width, S32 old_height, S32 *new_width, S32 *new_height);
#ifdef __MMI_MMS_2__
extern "C" void vappUcDeleteMmsRsp(srv_mms_result_enum result, void *rsp_data, void* user_data);
#endif
extern "C" void vappUcDisplayPopup( WCHAR* title, mmi_nmgr_balloon_type_enum event_type);
extern "C" WCHAR* vappUcGetMmaResultPopupStr(mma_result_enum result, mmi_nmgr_balloon_type_enum *type);
#if defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__) || defined(__MMI_UC_MMS_IMG_RESOLUTION__) 
extern "C" WCHAR* vappUcGetResizeResultPopupStr(S32 result, mmi_nmgr_balloon_type_enum *type);
#endif
extern "C" WCHAR* vappUcGetSrvResultPopupStr(srv_uc_result result, mmi_nmgr_balloon_type_enum *type);
extern "C" srv_um_msg_box_enum vappUcConvertMmaBoxToUm(mma_folder_enum msg_box);
extern "C" srv_um_msg_box_enum vappUcConvertSmsBoxToUm(srv_sms_box_enum msg_box);
extern "C" VfxBool vappUcCheckAppSanity(void *ptr);
extern "C" void vappUcCopyInitData(VappUcEntryStruct *data);
extern "C" void vappUcResetInitData(void);

//extern "C" void vappUcDeInitData(void);
extern "C" srv_uc_addr_struct *vapp_uc_get_sms_address_callback(U16 index, void* user_data);
extern "C" void vappUcRefresh(VcuiUcMainCui *app);
extern "C" VfxBool vapp_uc_is_ascii_string(const S8 *ucs2_str);
extern "C" srv_sms_sim_enum vappUcConvertUCSimIdToSMS(U32 sim_id);
extern "C" srv_uc_sim_id vappUcConvertSMSSimIdToUc(U32 sim_id);

extern "C" srv_uc_msg_type_enum vappUcDetermineMsgTypeByContent(srv_uc_cntxt_reference_struct *m_service_cntxt,
                                                                VappUcMainStruct *main);
extern "C" MMI_BOOL vappUcChangeMsgTypeIfNeeded(srv_uc_cntxt_reference_struct *m_service_cntxt, 
                                                VappUcMainStruct *main);
extern "C" void vappUcCheckIfNeedCloseUcOnSdPlugOut(VfxBool *close_uc, 
                                                    VfxBool *deinit_preview, 
                                                    srv_uc_cntxt_reference_struct *service_cntxt, 
                                                    VappUcSendInfoStruct *send_info);
extern "C" void vappUcHandleObjOnSdPlugOut(srv_uc_cntxt_reference_struct *m_service_cntxt, 
                                           VappUcMainStruct *main, 
                                           VfxBool *attach_removed, 
                                           VfxBool *close_cui );

extern "C" void vappUcClearMsgBearer (srv_uc_cntxt_reference_struct *m_service_cntxt, 
                                      VappUcSendInfoStruct *send_info, 
                                      srv_uc_msg_type_enum msg_type);
extern "C" void vappUcDeleteMmsReq(U32 msg_id, 
                                   U8 storage, 
                                   VappUcSendInfoStruct *send_info,
                                   void *user_data);
extern "C" void vappUcResetApp(VappUcMainStruct *main,     
                    VappUcSendInfoStruct *send_info,
                    srv_uc_cntxt_reference_struct *m_service_cntxt);
extern "C"  void vappUcResetAppDataByInstance(U32 instance);


#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
extern "C" VfxBool vapp_uc_check_serialize_support_cui(VappUcCuiTypeEnum cui_type);
extern "C" void vapp_uc_close_serialize_support_cui(VappUcCuiTypeEnum cui_type, mmi_id cui_gid);
extern "C" mmi_ret vapp_uc_static_event_handler(mmi_event_struct *evt, VfxBool is_need_close_uc);
extern "C" mmi_ret vapp_uc_music_player_cui_handler(mmi_event_struct *evt);
extern "C" mmi_ret vapp_uc_gallery_cui_handler(mmi_event_struct *evt);
extern "C" mmi_ret vapp_uc_mms_preview_handler(mmi_event_struct *evt);
extern "C" mmi_ret vapp_uc_proxy_proc(mmi_event_struct *evt);
extern "C" void vapp_uc_open_audio_player_cui(void *arg, VfxU32 argSize);
extern "C" void vapp_uc_open_mms_preview_cui(void *arg, VfxU32 argSize);
extern "C" void vapp_uc_open_gallery_cui(void *arg, VfxU32 argSize);
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
extern "C" void vapp_uc_open_video_player_cui(void *arg, VfxU32 argSize);
#endif
extern "C" void vappUcResetSerialize(U32 instance);

#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */
#endif /* #if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */
#endif /* _VAPP_UC_PROT_H */

